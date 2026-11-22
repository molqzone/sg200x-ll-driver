#include "sg200x_ll_csr.h"

#if defined(__riscv)

/**
 * @def DCACHE_IPA_A0
 * @brief 使用 a0 地址的缓存失效指令编码 / Cache-invalidate instruction encoding using the address in a0.
 */
#define DCACHE_IPA_A0 ".long 0x02a5000b"
/**
 * @def DCACHE_CPA_A0
 * @brief 使用 a0 地址的缓存写回指令编码 / Cache-clean instruction encoding using the address in a0.
 */
#define DCACHE_CPA_A0 ".long 0x0295000b"
/**
 * @def DCACHE_CIPA_A0
 * @brief 使用 a0 地址的缓存写回并失效指令编码 / Cache-clean-and-invalidate encoding using the address in a0.
 */
#define DCACHE_CIPA_A0 ".long 0x02b5000b"
/**
 * @def SYNC_S
 * @brief 等待 C906 缓存操作完成的 sync.s 指令编码。
 *        sync.s instruction encoding completing C906 cache operations.
 */
#define SYNC_S ".long 0x0190000b"

/**
 * @def DCACHE_OP_RANGE(OP, addr, size)
 * @brief 对覆盖地址范围的缓存行执行指定指令。
 *        Execute a selected cache instruction over lines covering a range.
 *
 * @param OP 使用 a0 的指令字符串 / Instruction string using a0.
 * @param addr 范围起始地址 / Range start address.
 * @param size 范围长度，单位为字节 / Range length in bytes.
 *
 * 整条循环写在**一条 asm 语句**里，a0 由汇编自己管理——这是必须的：T-Head 的
 * dcache.ipa/cpa/cipa 只认 a0，而 C 循环加 "r"(line_) 约束不保证循环体内
 * line_ 仍在 a0（编译器可重分配），多行范围会静默清错地址。mainline Linux 的
 * THEAD_CMO_OP（arch/riscv/errata/thead/errata.c）同样把循环放进汇编。
 *
 * The whole loop lives in **one asm statement** so a0 is managed by the
 * assembler, not the compiler. This is required: T-Head's dcache.ipa/cpa/cipa
 * only reads a0, and a C loop with an "r"(line_) constraint does not keep
 * line_ in a0 inside the body (the compiler may reallocate it), so a multi-line
 * range silently cleans the wrong addresses. Mainline Linux's THEAD_CMO_OP
 * (arch/riscv/errata/thead/errata.c) keeps the loop in assembly for the same
 * reason.
 */
#define DCACHE_OP_RANGE(OP, addr, size)                                          \
    do                                                                           \
    {                                                                            \
        const uintptr_t start_ =                                                 \
            (uintptr_t)(addr) & ~(uintptr_t)(LL_DCACHE_LINE_SIZE - 1U);          \
        const uintptr_t end_ =                                                   \
            (((uintptr_t)(addr) + (size_t)(size) + (LL_DCACHE_LINE_SIZE - 1U)) & \
             ~(uintptr_t)(LL_DCACHE_LINE_SIZE - 1U));                            \
        __asm__ __volatile__("mv a0, %1\n\t"                                   \
                             "j 2f\n\t"                                        \
                             "3:\n\t"                                          \
                             OP "\n\t"                                         \
                             "add a0, a0, %0\n\t"                              \
                             "2:\n\t"                                          \
                             "bltu a0, %2, 3b\n\t"                             \
                             SYNC_S                                              \
                             :                                                   \
                             : "r"(LL_DCACHE_LINE_SIZE), "r"(start_), "r"(end_)  \
                             : "a0", "memory");                                  \
    } while (0)

/* CMO instructions (dcache.cpa/cipa/ipa) are machine-mode-only on this core: in
 * S-mode they raise an illegal-instruction trap, which parks the core in the
 * M-mode fault handler.  The S-mode bring-up therefore maps the cross-core
 * pages uncached instead (Core/sg200x_smode.cpp) and every maintenance call
 * from S-mode is a no-op -- including the invalidate, which was the one path
 * left unguarded and would fault on the first timer read from S-mode.
 *
 * 这些 CMO 指令在本核是 M-mode 专用：S-mode 执行即非法指令陷阱。S-mode 启动把跨核
 * 页映射成非缓存（Core/sg200x_smode.cpp），因此从 S-mode 发起的维护动作一律空转；
 * invalidate 之前是漏网的那一条，S-mode 第一次读定时器就会踩上。
 */
void sg200x_ll_csr_dcache_clean_range(uintptr_t addr, size_t size)
{
    DCACHE_OP_RANGE(DCACHE_CPA_A0, addr, size);
}

void sg200x_ll_csr_dcache_clean_invalidate_range(uintptr_t addr, size_t size)
{
    DCACHE_OP_RANGE(DCACHE_CIPA_A0, addr, size);
}

void sg200x_ll_csr_dcache_invalidate_range(uintptr_t addr, size_t size)
{
    DCACHE_OP_RANGE(DCACHE_IPA_A0, addr, size);
}

void sg200x_ll_csr_delay_nops(uint32_t iterations)
{
    for (uint32_t count = 0U; count < iterations; ++count)
    {
        __asm__ __volatile__("nop" ::: "memory");
    }
}

#endif
