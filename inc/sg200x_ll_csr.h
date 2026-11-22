#pragma once

#include <stddef.h>
#include <stdint.h>

#include "sg2002.h"

#if defined(__riscv) && defined(LL_CORE_BACKEND_SDK)
#include "core_rv64.h"
#endif

/**
 * @brief 执行设备 I/O 与编译器内存屏障 / Issue a device I/O and compiler memory barrier.
 *
 * @note RISC-V 使用 fence iorw, iorw；宿主构建使用顺序一致的线程屏障。
 *       RISC-V uses fence iorw, iorw; host builds use a sequentially consistent thread fence.
 */
static inline void sg200x_ll_csr_fence_io(void)
{
#if defined(__riscv)
    __asm__ __volatile__("fence iorw, iorw" ::: "memory");
#else
    __atomic_thread_fence(__ATOMIC_SEQ_CST);
#endif
}

#if defined(__riscv)

/**
 * @brief 读取机器状态寄存器 / Read the machine-status register.
 *
 * @return 当前 mstatus 值 / Current mstatus value.
 */
static inline unsigned long sg200x_ll_csr_mstatus_read(void)
{
#if defined(LL_CORE_BACKEND_SDK)
    return (unsigned long)__get_MSTATUS();
#else
    unsigned long value;
    __asm__ __volatile__("csrr %0, mstatus" : "=r"(value));
    return value;
#endif
}

/**
 * @brief 写入完整的机器状态寄存器 / Write the complete machine-status register.
 *
 * @param value 要写入的 mstatus 值 / mstatus value to write.
 */
static inline void sg200x_ll_csr_mstatus_write(unsigned long value)
{
#if defined(LL_CORE_BACKEND_SDK)
    __set_MSTATUS((uint64_t)value);
#else
    __asm__ __volatile__("csrw mstatus, %0" ::"r"(value) : "memory");
#endif
}

/**
 * @brief 读取机器中断使能寄存器 / Read the machine interrupt-enable register.
 *
 * @return 当前 mie 值 / Current mie value.
 */
static inline unsigned long sg200x_ll_csr_mie_read(void)
{
#if defined(LL_CORE_BACKEND_SDK)
    return (unsigned long)__get_MIE();
#else
    unsigned long value;
    __asm__ __volatile__("csrr %0, mie" : "=r"(value));
    return value;
#endif
}

/**
 * @brief 写入完整的机器中断使能寄存器 / Write the complete machine interrupt-enable register.
 *
 * @param value 要写入的 mie 值 / mie value to write.
 */
static inline void sg200x_ll_csr_mie_write(unsigned long value)
{
#if defined(LL_CORE_BACKEND_SDK)
    __set_MIE((uint64_t)value);
#else
    __asm__ __volatile__("csrw mie, %0" ::"r"(value) : "memory");
#endif
}

/**
 * @brief 置位指定的 mie 中断使能位 / Set the selected mie interrupt-enable bits.
 *
 * @param mask 要操作的位掩码 / Bit mask to operate on.
 * @note 此读改写操作不原子；调用者应禁止中断或自行串行化。
 *       This read-modify-write operation is not atomic; disable interrupts or serialize it externally.
 */
static inline void sg200x_ll_csr_mie_set(unsigned long mask)
{
#if defined(LL_CORE_BACKEND_SDK)
    __set_MIE(__get_MIE() | (uint64_t)mask);
#else
    unsigned long value;
    __asm__ __volatile__("csrr %0, mie" : "=r"(value));
    value |= mask;
    __asm__ __volatile__("csrw mie, %0" ::"r"(value) : "memory");
#endif
}

/**
 * @brief 清除指定的 mie 中断使能位 / Clear the selected mie interrupt-enable bits.
 *
 * @param mask 要操作的位掩码 / Bit mask to operate on.
 * @note 此读改写操作不原子；调用者应禁止中断或自行串行化。
 *       This read-modify-write operation is not atomic; disable interrupts or serialize it externally.
 */
static inline void sg200x_ll_csr_mie_clear(unsigned long mask)
{
#if defined(LL_CORE_BACKEND_SDK)
    __set_MIE(__get_MIE() & ~(uint64_t)mask);
#else
    unsigned long value;
    __asm__ __volatile__("csrr %0, mie" : "=r"(value));
    value &= ~mask;
    __asm__ __volatile__("csrw mie, %0" ::"r"(value) : "memory");
#endif
}

/**
 * @brief 使能机器级全局中断 / Enable machine-mode global interrupts.
 *
 * @note 置位 mstatus.MIE（位 3），即 csrs mstatus, 8；两个后端一致。
 *       Sets mstatus.MIE (bit three), that is csrs mstatus, 8; both backends agree.
 * @note 各中断源的 mie 位和 PLIC 门控仍需单独配置。
 *       Per-source mie bits and PLIC enables must still be configured separately.
 */
static inline void sg200x_ll_csr_global_irq_enable(void)
{
#if defined(LL_CORE_BACKEND_SDK)
    __enable_irq();
#else
    __asm__ __volatile__("csrs mstatus, 8" ::: "memory");
#endif
}

/**
 * @brief 禁止机器级全局中断 / Disable machine-mode global interrupts.
 *
 * @note 清除 mstatus.MIE（位 3），即 csrc mstatus, 8；两个后端一致。
 *       Clears mstatus.MIE (bit three), that is csrc mstatus, 8; both backends agree.
 */
static inline void sg200x_ll_csr_global_irq_disable(void)
{
#if defined(LL_CORE_BACKEND_SDK)
    __disable_irq();
#else
    __asm__ __volatile__("csrc mstatus, 8" ::: "memory");
#endif
}

/**
 * @brief 保存 mstatus 并禁止机器级全局中断 / Save mstatus and disable machine-mode global interrupts.
 *
 * @return 供 critical_exit 恢复的完整 mstatus 快照 / Complete mstatus snapshot to restore with critical_exit.
 */
static inline unsigned long sg200x_ll_csr_critical_enter(void)
{
    unsigned long prior = sg200x_ll_csr_mstatus_read();
    sg200x_ll_csr_global_irq_disable();
    return prior;
}

/**
 * @brief 恢复进入临界区前的 mstatus / Restore the mstatus saved before entering a critical section.
 *
 * @param prior critical_enter 返回的 mstatus 快照 / The mstatus snapshot returned by critical_enter.
 */
static inline void sg200x_ll_csr_critical_exit(unsigned long prior) { sg200x_ll_csr_mstatus_write(prior); }

/**
 * @brief 使能核心的机器外部中断输入 / Enable the core's machine external-interrupt input.
 *
 * @note 此读改写操作不原子；调用者应禁止中断或自行串行化。
 *       This read-modify-write operation is not atomic; disable interrupts or serialize it externally.
 * @note 仅设置 mie.MEIE；mstatus.MIE 和 PLIC 源使能由调用者或 RTOS 管理。
 *       Only mie.MEIE is set; the caller or RTOS manages mstatus.MIE and PLIC source enables.
 */
static inline void sg200x_ll_csr_external_irq_enable(void) { sg200x_ll_csr_mie_set(LL_MIE_MEIE_BIT); }

/**
 * @brief 禁止核心的机器外部中断输入 / Disable the core's machine external-interrupt input.
 *
 * @note 此读改写操作不原子；调用者应禁止中断或自行串行化。
 *       This read-modify-write operation is not atomic; disable interrupts or serialize it externally.
 * @note 仅清除 mie.MEIE，不修改 PLIC 中的各源使能位。
 *       Only mie.MEIE is cleared; per-source PLIC enables are unchanged.
 */
static inline void sg200x_ll_csr_external_irq_disable(void) { sg200x_ll_csr_mie_clear(LL_MIE_MEIE_BIT); }

#if __riscv_xlen == 64
/**
 * @brief 读取 64 位 time CSR 计数值 / Read the 64-bit time CSR counter.
 *
 * @return 未经时间单位换算的计数值 / Raw counter ticks without time-unit conversion.
 * @note 本板 time 时基为 25 MHz；使用 CSR，不访问非 QEMU SDK 未提供的 CLINT mtime 地址。
 *       The board time base is 25 MHz; use the CSR rather than a CLINT mtime address absent from the
 *       non-QEMU SDK.
 * @note 使用 rdtime；SDK 的时间访问器在固件中不可用，两个后端因此共用同一实现。
 *       Uses rdtime; the SDK time accessors are unusable in this firmware, so both backends share this
 *       implementation.
 */
static inline uint64_t sg200x_ll_csr_time_read(void)
{
    uint64_t value;
    __asm__ __volatile__("rdtime %0" : "=r"(value));
    return value;
}
#elif __riscv_xlen == 32
/**
 * @brief 读取 64 位 time CSR 计数值 / Read the 64-bit time CSR counter.
 *
 * @return 未经时间单位换算的计数值 / Raw counter ticks without time-unit conversion.
 * @note 本板 time 时基为 25 MHz；使用 CSR，不访问非 QEMU SDK 未提供的 CLINT mtime 地址。
 *       The board time base is 25 MHz; use the CSR rather than a CLINT mtime address absent from the
 *       non-QEMU SDK.
 * @note 通过高低字重读避免进位撕裂；C906L 使用 RV64 路径，此分支供 RV32 复用。
 *       The high word is reread to avoid rollover tearing; C906L uses the RV64 path and this branch keeps
 *       RV32 reuse possible.
 */
static inline uint64_t sg200x_ll_csr_time_read(void)
{
    uint32_t low;
    uint32_t high0;
    uint32_t high1;
    do
    {
        __asm__ __volatile__("rdtimeh %0" : "=r"(high0));
        __asm__ __volatile__("rdtime %0" : "=r"(low));
        __asm__ __volatile__("rdtimeh %0" : "=r"(high1));
    } while (high0 != high1);
    return ((uint64_t)high1 << 32) | low;
}
#else
#error "Unsupported __riscv_xlen"
#endif

/**
 * @brief 同步本核心后续的指令取指 / Synchronize subsequent instruction fetches on this core.
 *
 * @note 使用真正的 fence.i；SDK 的 __ISB 仅提供数据屏障。
 *       Use a real fence.i; the SDK __ISB only provides a data barrier.
 */
static inline void sg200x_ll_csr_fence_i(void)
{
    __asm__ __volatile__(".option push\n\t"
                         ".option arch, +zifencei\n\t"
                         "fence.i\n\t"
                         ".option pop" ::
                             : "memory");
}

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @brief 使指定范围的数据缓存失效 / Invalidate data-cache lines covering a range.
     *
     * @param addr 范围起始地址 / Start address of the range.
     * @param size 范围长度，单位为字节 / Range length in bytes.
     * @pre 地址加长度再加 63 不得溢出 uintptr_t；调用者拥有覆盖的完整缓存行。
     *      Address plus length plus 63 must not overflow uintptr_t; the caller owns every covered cache line.
     * @note 起始地址向下、末地址向上对齐至 64 字节边界，末尾执行 sync.s 等待完成。
     *       The start is rounded down and the end up to 64-byte boundaries; sync.s completes the operation.
     * @note 失效不写回脏数据；仅用于可丢弃本地缓存内容的范围。
     *       Invalidation does not write back dirty data; use it only where local cached contents may be
     *       discarded.
     */
    void sg200x_ll_csr_dcache_invalidate_range(uintptr_t addr, size_t size);
    /**
     * @brief 写回指定范围的脏数据缓存行 / Clean dirty data-cache lines covering a range.
     *
     * @param addr 范围起始地址 / Start address of the range.
     * @param size 范围长度，单位为字节 / Range length in bytes.
     * @pre 地址加长度再加 63 不得溢出 uintptr_t；调用者拥有覆盖的完整缓存行。
     *      Address plus length plus 63 must not overflow uintptr_t; the caller owns every covered cache line.
     * @note 起始地址向下、末地址向上对齐至 64 字节边界，末尾执行 sync.s 等待完成。
     *       The start is rounded down and the end up to 64-byte boundaries; sync.s completes the operation.
     */
    void sg200x_ll_csr_dcache_clean_range(uintptr_t addr, size_t size);
    /**
     * @brief 写回并使指定范围的数据缓存失效 / Clean and invalidate data-cache lines covering a range.
     *
     * @param addr 范围起始地址 / Start address of the range.
     * @param size 范围长度，单位为字节 / Range length in bytes.
     * @pre 地址加长度再加 63 不得溢出 uintptr_t；调用者拥有覆盖的完整缓存行。
     *      Address plus length plus 63 must not overflow uintptr_t; the caller owns every covered cache line.
     * @note 起始地址向下、末地址向上对齐至 64 字节边界，末尾执行 sync.s 等待完成。
     *       The start is rounded down and the end up to 64-byte boundaries; sync.s completes the operation.
     */
    void sg200x_ll_csr_dcache_clean_invalidate_range(uintptr_t addr, size_t size);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @brief 执行指定数量的 NOP 延迟迭代 / Execute a specified number of NOP delay iterations.
     * @param iterations NOP 迭代次数 / Number of NOP iterations.
     * @note 仅 RISC-V；每次包含循环开销，不能作为精确时钟周期或时间单位。
     *        RISC-V only; each iteration includes loop overhead and is not an exact cycle or time unit.
     */
    void sg200x_ll_csr_delay_nops(uint32_t iterations);

#ifdef __cplusplus
}
#endif

#endif
