/**
 * @file sg200x_ll_clint.h
 * @brief CLINT：这个核**只能写**，读会挂。CLINT: this core may only write; reading it hangs.
 *
 * 2026-11-08 实测（板子上，不是推测）：C906L 对 `0x74004000`（mtimecmp）做一次普通 load，
 * 固件就停在 `CreateDefaultTask` 之前——`main()` 的面包屑已写、`uxCurrentNumberOfTasks`
 * 恒 0，大核一切正常，也就是掉进了 port 的 `is_exception` 死循环。把那次读删掉、其余一字
 * 不改，同一份固件立刻活（tick 1,035 Hz、7 个任务、观测器在发布）。
 *
 * 原因和补丁 0005 的注释同源：C906 的 SYSMAP 把 `0x74000000` 这段标成**可缓存**，一次
 * 可缓存的 load 要填 64 字节的行，而 CLINT 每个比较槽只有 8 字节——填充越过实现范围就
 * 回一个总线错误。store 不触发行填充，所以**写一直是好的**（FreeRTOS 的 tick 就靠写）。
 *
 * 因此这一层**只提供两个动作**：读时间（走 `rdtime`，CSR，不经缓存）和写比较槽。
 * 读比较槽的接口故意不存在，并且留了一个会报名字的编译期陷阱，免得下一个人"顺手读回来"。
 *
 * Measured on the board, 2026-11-08, not inferred: one plain load from `0x74004000`
 * (mtimecmp) on the C906L stops the firmware before `CreateDefaultTask` -- `main()`'s
 * breadcrumb is written, `uxCurrentNumberOfTasks` stays 0, the big core is fine, i.e.
 * the port's `is_exception` loop.  Delete that load and change nothing else and the same
 * firmware is alive immediately (tick 1,035 Hz, 7 tasks, the observer publishing).
 *
 * The reason is the same one patch 0005's comment gives: the C906's SYSMAP marks
 * `0x74000000` cacheable, a cacheable load fills a 64-byte line, and each CLINT compare
 * slot is only 8 bytes -- a fill past the implemented range comes back as a bus error.
 * Stores do not fill lines, so **writes have always been fine** (the FreeRTOS tick is
 * built on them).
 *
 * This layer therefore offers exactly two actions: read the time (`rdtime`, a CSR, never
 * cached) and arm a compare slot.  A compare-slot read API deliberately does not exist,
 * and a named compile-time trap stands in its place so nobody "just reads it back".
 */

#pragma once

#include <stdint.h>

/** @brief CLINT 的物理基址与寄存器偏移。CLINT base and register offsets.
 *
 *  TRM 3.x 的内存图里只有这一份：`0x74000000..0x7400FFFF`，前 0x4000 是软件中断
 *  （msip），0x4000 起是 mtimecmp，0xBFF8 是 mtime。两个核看到的是同一组地址，
 *  而 `clint,has-no-64bit-mmio` 意味着 64 位比较值要拆成两次 32 位写。
 *  The TRM's map has exactly one: `0x74000000..0x7400FFFF`; the first 0x4000 is the
 *  software-interrupt array, 0x4000 onward is mtimecmp and 0xBFF8 is mtime.  Both cores
 *  see the same addresses, and `clint,has-no-64bit-mmio` means a 64-bit compare value is
 *  split into two 32-bit stores.
 */
#define SG200X_LL_CLINT_PHYS 0x74000000u
#define SG200X_LL_CLINT_MTIMECMP_OFF 0x4000u
#define SG200X_LL_CLINT_MTIME_OFF 0xbFF8u
#define SG200X_LL_CLINT_COMPARATOR_STRIDE 8u
/** 本核的 tick 默认落在槽 0（= mhartid）；槽 1 是给"挪开大核"准备的对照槽。
 *  The tick lands in slot 0 by default (= mhartid); slot 1 is the control slot used to
 *  move it away from the big core. */
#define SG200X_LL_CLINT_SLOTS 2u

#if defined(__riscv)

/** @brief 读 mtime（`rdtime`）。Read mtime through `rdtime`.
 *
 *  CSR 读，不经 D-cache，所以这是这颗核上**唯一**可靠的 CLINT 读数方式。
 *  A CSR read, never cached, so it is the only reliable way to read the CLINT here.
 */
static inline uint64_t sg200x_ll_clint_now(void)
{
    uint64_t value;
    __asm__ __volatile__("rdtime %0" : "=r"(value));
    return value;
}

/** @brief 武装一个比较槽（只写）。Arm one compare slot, write-only.
 *
 *  两次 32 位 store，先低后高（`clint,has-no-64bit-mmio`）；这是 FreeRTOS 的 tick
 *  ISR 用的同一顺序，也是这颗核上验证过不挂的那条路径。
 *  Two 32-bit stores, low then high (`clint,has-no-64bit-mmio`): the same order the
 *  FreeRTOS tick ISR uses and the only path verified not to hang on this core.
 */
static inline void sg200x_ll_clint_arm(uint32_t slot, uint64_t when)
{
    volatile uint32_t *reg = (volatile uint32_t *)(uintptr_t)(
        SG200X_LL_CLINT_PHYS + SG200X_LL_CLINT_MTIMECMP_OFF +
        slot * SG200X_LL_CLINT_COMPARATOR_STRIDE);
    reg[0] = (uint32_t)(when & 0xFFFFFFFFu);
    reg[1] = (uint32_t)(when >> 32);
}

#else

/** 宿主构建没有 CLINT：时间返回 0，写是空操作。Host builds have no CLINT. */
static inline uint64_t sg200x_ll_clint_now(void) { return 0u; }
static inline void sg200x_ll_clint_arm(uint32_t slot, uint64_t when)
{
    (void)slot;
    (void)when;
}

#endif

/** @brief 读比较槽的编译期陷阱。The compile-time trap for reading a compare slot.
 *
 *  这个名字本身就是错误信息：谁写 `sg200x_ll_clint_compare_read(0)`，构建会在
 *  "叫做这个名字的函数不存在"上停下，并顺手读到本文件顶部的原因。
 *  The name is the error message: whoever writes `sg200x_ll_clint_compare_read(0)`
 *  stops on "no such function" and lands on the explanation at the top of this file.
 */
#define sg200x_ll_clint_compare_read(slot) \
    do_not_read_the_CLINT_the_C906L_faults_on_a_cacheable_load_see_sg200x_ll_clint_h(slot)
