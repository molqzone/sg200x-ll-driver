#pragma once

/**
 * @file sg200x_ll_mmio.h
 * @brief 设备寄存器的访问器：把"这段内存不是普通内存"写进函数名。
 *        The register accessor: put "this is not ordinary memory" in the name.
 *
 * 为什么存在：LL 层以前对寄存器就是 `PLIC_C906L->ENABLE[...] |= bit` 这样的普通读写
 * （普通 `volatile` 指针）。可这段地址在 C906L 的 SYSMAP 里是**可缓存**的，于是
 * "store 到了"和"PLIC 看到了"是两件事——S-mode 分支的实测就是 tick 永远不进来，因为
 * PLIC 的使能位还脏在本核 D-cache 里（`docs/smode-status.md` 第三条根因）。当时的修法
 * 是在 `Core/` 里新造一对 `MmodeStoreMmio/MmodeLoadMmio`。
 *
 * Why this exists: the LL layer used to touch registers with plain `volatile` reads and
 * writes (`PLIC_C906L->ENABLE[...] |= bit`).  That range is **cacheable** in the C906L's
 * SYSMAP, so "the store happened" and "the PLIC saw it" are two different events -- the
 * S-mode branch measured a tick that never arrived because the enable bit sat dirty in
 * this core's D-cache (`docs/smode-status.md`, third root cause), and the fix at the time
 * was a fresh `MmodeStoreMmio/MmodeLoadMmio` pair in `Core/`.
 *
 * 现在的固件把 D-cache 整个关掉（`Core/sg200x_system_init.cpp`），所以这里的屏障只需要
 * 编译器级别的顺序；但**这个前提是断言，不是希望**：有人打开 D-cache 时，
 * `SG200X_LL_DCACHE_ON` 会让构建停下，而不是让 PLIC 少看一次写。
 *
 * Today's firmware turns the data cache off entirely (`Core/sg200x_system_init.cpp`), so
 * the barriers here only need to order the compiler's accesses -- but that premise is an
 * assertion, not a hope: whoever enables the data cache must define
 * `SG200X_LL_DCACHE_ON`, and the build stops instead of the PLIC missing a write.
 */

#include <stdint.h>

#if defined(SG200X_LL_DCACHE_ON)
#error "sg200x_ll_mmio assumes an uncached data path. Add clean/invalidate (see Core/sg200x_system_init.cpp) before enabling the D-cache."
#endif

#if defined(__riscv)
/** 顺序：芯内访存完成前不要让后续访问通过；C906 的 CMO 用 `sync.s`，这里只需要 fence。*/
#define SG200X_LL_MMIO_BARRIER() __asm__ __volatile__("fence iorw, iorw" ::: "memory")
#else
#define SG200X_LL_MMIO_BARRIER() __atomic_thread_fence(__ATOMIC_SEQ_CST)
#endif

/**
 * @brief 写一个 32 位设备寄存器 / Store one 32-bit device register.
 *
 * 前后都有屏障：写之前保证此前的数据写已经可见（例如 DMA 描述符），写之后保证这次写
 * 不会被编译器挪到后面去（紧接着的门铃依赖它）。
 * Barriers on both sides: the one before makes earlier data stores visible (a DMA
 * descriptor, say), the one after keeps the compiler from sinking this store past the
 * doorbell that depends on it.
 */
static inline void sg200x_ll_mmio_store32(volatile uint32_t *reg, uint32_t value)
{
    SG200X_LL_MMIO_BARRIER();
    *reg = value;
    SG200X_LL_MMIO_BARRIER();
}

/// @brief 读一个 32 位设备寄存器 / Load one 32-bit device register.
static inline uint32_t sg200x_ll_mmio_load32(const volatile uint32_t *reg)
{
    SG200X_LL_MMIO_BARRIER();
    const uint32_t value = *reg;
    SG200X_LL_MMIO_BARRIER();
    return value;
}

/**
 * @brief 置位（读改写）/ Set bits (read-modify-write).
 *
 * 寄存器没有原子位操作时，这是"读改写"而不是"原子置位"：同一时刻只能有一个写者，
 * 描述见调用点。
 * Without atomic bit ops this is a read-modify-write, not an atomic set: one writer at
 * a time, documented at the call site.
 */
static inline uint32_t sg200x_ll_mmio_set_bits(volatile uint32_t *reg, uint32_t mask)
{
    SG200X_LL_MMIO_BARRIER();
    const uint32_t value = (uint32_t)(*reg | mask);
    *reg = value;
    SG200X_LL_MMIO_BARRIER();
    return value;
}

/// @brief 清位（读改写）/ Clear bits (read-modify-write).
static inline uint32_t sg200x_ll_mmio_clear_bits(volatile uint32_t *reg, uint32_t mask)
{
    SG200X_LL_MMIO_BARRIER();
    const uint32_t value = (uint32_t)(*reg & ~mask);
    *reg = value;
    SG200X_LL_MMIO_BARRIER();
    return value;
}
