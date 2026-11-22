/**
 * @file sg200x_ll_tim.h
 * @brief DW APB timer：小核 tick 的时钟源。DW APB timer: the little core's tick source.
 *
 * 为什么需要它：实测（2026-11-10）小核 `csrr mhartid` 返回 **0**，与大核（Linux，
 * `/proc/cpuinfo` 的 `hart : 0`）相同，而两颗核物理上共享同一个 CLINT。于是小核
 * FreeRTOS 的 tick 每 1 ms 就往 `mtimecmp[0]` 写——那是**大核的比较槽**。又因为
 * `0x74000000` 在 C906L 的 SYSMAP 里标为可缓存，小核的 store 脏在自己的 D-cache 里，
 * 驱逐时才写回，把大核 SBI 刚武装的值盖成旧值，大核定时器被打坏、tick 停住、
 * ssh 失去响应——这就是"放核即冻死"，且因驱逐时机不定而呈间歇性。
 *
 * 为什么不换槽：RISC-V 里 hart N 的时钟中断只在 `mtime >= mtimecmp[N]` 时来，小核是
 * hart 0 就只认槽 0。实测把槽强制成 1，小核 tick 立刻停（遥测 head 冻结）而大核随之
 * 不再死——双向都证实了因果，也证实槽挪不了。所以 tick 必须整个移出 CLINT。
 *
 * 本文件就是那个新时钟源。实测底数（探针固件，2026-11-10）：输入时钟 25 MHz
 * （= XTAL），通道 4 对应 PLIC IRQ 55，`configTICK_RATE_HZ == 1000` 时
 * `LOAD_COUNT = 25000`。
 *
 * Why this exists: measured 2026-11-10, the little core's `csrr mhartid` returns
 * **0**, the same id Linux uses, and the two cores physically share one CLINT.  The
 * little core's FreeRTOS tick therefore arms `mtimecmp[0]` every 1 ms -- the **big
 * core's** compare slot.  Because `0x74000000` is SYSMAP-cacheable on the C906L, that
 * store sits dirty in the little core's D-cache and is written back on eviction,
 * overwriting whatever the big core's SBI just armed.  The big core's timer is
 * corrupted, its tick stops and ssh dies -- the "release freezes the board" symptom,
 * intermittent because eviction timing varies.
 *
 * Why not another slot: a core only takes its timer interrupt from its own slot
 * (`mtime >= mtimecmp[N]`), and the little core is hart 0.  Measured: forcing the slot
 * to 1 stops the little core's tick outright (telemetry head freezes) while the big
 * core then stops dying -- both directions confirm the cause and rule out the slot
 * move.  So the tick has to leave the CLINT entirely.
 *
 * This file is that new clock source.  Measured with a probe firmware on 2026-11-10:
 * a 25 MHz input clock (the XTAL), channel 4 on PLIC IRQ 55, and `LOAD_COUNT = 25000`
 * for `configTICK_RATE_HZ == 1000`.
 */

#pragma once

#include <stdint.h>

#include "sg2002.h"
#include "sg200x_ll_csr.h"

/** @brief 写一个 timer 寄存器，并让这次 store 真正出核。
 *         Write one timer register and make the store reach the hardware.
 *
 *  `0x030A0000` 落在 SYSMAP 标为可缓存的 `[0, 0x8FFFF000)` 区间里，所以一条普通 store
 *  会分配进行、脏在 D-cache 里不立即出核——中断就清不掉（实测症状：IRQ 55 以 ~1.2 MHz
 *  反复重入，`do_irq` 的 claim/handler/eoi 循环空转，固件被饿死，而 timer 的
 *  `INT_STATUS` 却读到 0）。写完立刻 clean 掉所在行，store 才落地。
 *  The timer window is cacheable in the M-mode SYSMAP, so a plain store sits
 *  dirty in the D-cache; clean the line after the store.  S-mode does not call
 *  this helper (its start path below writes the uncached mapping directly). */
static inline void sg200x_ll_tim_write32(uintptr_t addr, uint32_t value)
{
    *(volatile uint32_t*)addr = value;
    __asm__ __volatile__("fence iorw, iorw" ::: "memory");
    sg200x_ll_csr_dcache_clean_range(addr, sizeof(uint32_t));
    sg200x_ll_csr_fence_io();
}

/** @brief 读一个 timer 寄存器，先丢掉可能的旧行。
 *         Read one timer register, dropping any stale line first.
 *
 *  The timer window is cacheable in M-mode; drop the stale line before reading.
 */
static inline uint32_t sg200x_ll_tim_read32(uintptr_t addr)
{
    sg200x_ll_csr_fence_io();
    sg200x_ll_csr_dcache_invalidate_range(addr, sizeof(uint32_t));
    sg200x_ll_csr_fence_io();
    return *(volatile uint32_t*)addr;
}

/** @brief 小核 tick 使用的通道。Channel the little core's tick uses.
 *
 *  通道 5 / PLIC IRQ 56。硬件上小核只能收 DW timer5 的中断——通道 4 虽然探针能测到
 *  25 MHz 且 IRQ 55 会挂起，但那条中断送不到小核，表现为 tick 只跳一次就停。
 *  Channel 5 / PLIC IRQ 56.  In hardware the little core can only take DW timer5's
 *  interrupt -- channel 4 measures a clean 25 MHz and pends IRQ 55, but that interrupt
 *  never reaches the little core, which shows up as the tick firing once and stopping. */
#define SG200X_LL_TIM_TICK_CHANNEL 5U

/** @brief 小核 tick 的 PLIC 中断号。PLIC IRQ of the little core's tick. */
#define SG200X_LL_TIM_TICK_IRQ IRQ_TIMER5

/** @brief timer5 的计数值：16 kHz（25 MHz / 16000 = 1562）。
 *         Count for timer5: 16 kHz (25 MHz / 16000 = 1562).
 *
 *  为什么不是 1 kHz：M-mode 靠这条中断做**中断投递**（DMA 完成 + 陀螺 data-ready），
 *  1 kHz 的观察周期意味着每个 DMA 块要等 ~1 ms，一次采样四个块就吃掉 4 ms。16 kHz 把
 *  观察周期压到 62.5 µs；FreeRTOS 的 tick 在 shim 里按 16 分频推进，仍是 1 kHz。
 *  硬件上小核只收得到 timer5 这一条定时器中断，所以只能在这里提速、在外面分频。
 *  Why not 1 kHz: M-mode uses this interrupt for **interrupt delivery** (DMA completions and
 *  the gyro data-ready); a 1 kHz observation period means every DMA block waits ~1 ms, and four
 *  blocks per sample eat 4 ms.  16 kHz brings the period down to 62.5 us, while the FreeRTOS tick
 *  is that divided by 16 in the shim and stays at 1 kHz.  This core only ever receives timer5's
 *  interrupt, so speeding it up here and dividing outside is the only option. */
#define SG200X_LL_TIM_TICK_COUNT 1562U

static inline uintptr_t sg200x_ll_tim_base(uint32_t channel)
{
    return TIMER_BASE + channel * 0x14UL;
}

/** @brief 以 **user-defined** 周期中断方式启动一个通道（ISR 每拍重装）。
 *         Start one channel in **user-defined** periodic mode (the ISR reloads it).
 *
 *  为什么不是 free-running：DW APB timer 的 free-running 是"计到 0 后回绕到
 *  0xFFFFFFFF 继续减"，**不会重装 LOAD_COUNT**。所以它的中断周期是 2^32 / F 而不是
 *  LOAD_COUNT / F——25 MHz 下第一次 1 ms、第二次要等约 172 秒。实测"只跳一次、
 *  CURRENT_VALUE 读到 0xffffffff"就是这条语义，不是缓存没生效。
 *  Why not free-running: DW APB timer's free-running mode wraps to 0xFFFFFFFF after
 *  reaching zero and **does not reload LOAD_COUNT**.  Its interrupt period is therefore
 *  2^32 / F, not LOAD_COUNT / F -- at 25 MHz the first tick comes after 1 ms and the
 *  second after ~172 s.  The measured "fires once, CURRENT_VALUE reads 0xffffffff" is
 *  exactly this, not a cache artifact.
 *
 *  user-defined 模式按 TRM 12.3 是**自动重装**："when the count value decreases to 0,
 *  the initial value is loaded again from the TimerNLoadCount register and continues
 *  counting"——所以 ISR 不需要续弓，只需清中断。
 *  `CONTROL`: bit0=enable, bit1=mode(1=user-defined), bit2=int_mask(0=不屏蔽).
 *  According to TRM 12.3, user-defined mode **reloads automatically**: "when the count
 *  value decreases to 0, the initial value is loaded again from the TimerNLoadCount
 *  register and continues counting" -- so the ISR only clears the interrupt.
 *  User-defined mode: counts to zero, stops, raises the interrupt; writing LOAD_COUNT
 *  reloads it and restarts the count.  `CONTROL`: bit0 enable, bit1 mode (1 =
 *  user-defined), bit2 int_mask (0 = unmasked). */
static inline void sg200x_ll_tim_start_periodic(uint32_t channel, uint32_t load_count)
{
    /* S-mode runs with the low 1 GiB mapped uncached, so these stores reach the
     * timer directly; no CMO is allowed here.  M-mode uses the generic helpers
     * above, which clean the cacheable SYSMAP line. */
    const uintptr_t base = sg200x_ll_tim_base(channel);
    __asm__ __volatile__("fence iorw, iorw" ::: "memory");
    *(volatile uint32_t*)(base + 0x08UL) = 0U;         /* CONTROL: stop first */
    *(volatile uint32_t*)(base + 0x00UL) = load_count; /* LOAD_COUNT */
    *(volatile uint32_t*)(base + 0x08UL) = 0x3U;       /* enable + user-defined */
    __asm__ __volatile__("fence iorw, iorw" ::: "memory");
    sg200x_ll_csr_fence_io();
}

/** @brief 清一个通道的中断：按 TRM 12.4.2 **读** TimerNEOI。
 *         Clear one channel's interrupt: **read** TimerNEOI, per TRM 12.4.2.
 *
 *  TRM 写得很明确："Read the TimerNEOI (N=1~8) register to clear the TimerN
 *  interrupt." 之前这里写 EOI（写 0），那不会清任何东西——中断一直挂着，于是
 *  `do_irq` 反复重入（实测 1.2 MHz 风暴），或者反过来只来一次。读一次就清掉了。
 *  The TRM is explicit: "Read the TimerNEOI (N=1~8) register to clear the TimerN
 *  interrupt."  This used to *write* EOI (0), which clears nothing -- the interrupt
 *  stayed asserted, so `do_irq` re-entered in a storm (measured 1.2 MHz) or the tick
 *  came only once.  One read clears it.
 *
 *  user-defined 模式会自动重装计数（TRM 12.3），所以这里不写 LOAD_COUNT。
 *  User-defined mode reloads the count by itself (TRM 12.3), so LOAD_COUNT is not
 *  rewritten here. */
static inline void sg200x_ll_tim_clear(uint32_t channel)
{
    (void)sg200x_ll_tim_read32(sg200x_ll_tim_base(channel) + 0x0CUL);
}

/** @brief 兼容旧名字：清中断（user-defined 自动重装，这里不再续弓）。
 *         Old name kept: clear the interrupt (user-defined reloads itself). */
static inline void sg200x_ll_tim_rearm(uint32_t channel, uint32_t load_count)
{
    (void)load_count;
    sg200x_ll_tim_clear(channel);
}

/** @brief 停一个通道。Stop one channel. */
static inline void sg200x_ll_tim_stop(uint32_t channel)
{
    sg200x_ll_tim_write32(sg200x_ll_tim_base(channel) + 0x08UL, 0U);
}

/** @brief 读一个通道的当前计数值。Read one channel's current count. */
static inline uint32_t sg200x_ll_tim_current_value(uint32_t channel)
{
    return sg200x_ll_tim_read32(sg200x_ll_tim_base(channel) + 0x04UL);
}

/** @brief 读一个通道的控制寄存器。Read one channel's control register. */
static inline uint32_t sg200x_ll_tim_control(uint32_t channel)
{
    return sg200x_ll_tim_read32(sg200x_ll_tim_base(channel) + 0x08UL);
}

/** @brief 读一个通道的中断状态（原始）。Read one channel's raw interrupt status. */
static inline uint32_t sg200x_ll_tim_int_status(uint32_t channel)
{
    return sg200x_ll_tim_read32(sg200x_ll_tim_base(channel) + 0x10UL);
}

/** @brief 读整个 timer 块的中断状态汇总。Read the block's interrupt-status summary. */
static inline uint32_t sg200x_ll_tim_int_status_all(void)
{
    return sg200x_ll_tim_read32(TIMER_BASE + 0x0A0UL);
}
