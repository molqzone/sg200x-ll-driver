#pragma once

#include <stdint.h>

/**
 * @file sg200x_ll_mbox.h
 * @brief SG200x mailbox 外设的寄存器原语 / Register primitives of the SG200x mailbox
 *        peripheral.
 *
 * 这颗外设有 4 个 bank（每个核一个接收 bank），每个 bank 有 8 个 set 位；位 n 对应
 * 上下文槽 n —— 槽是 8 字节的共享寄存器窗口。中断语义是“bank 里哪个位被置起”，所以
 * 状态是成对的：`int_status` 读已屏蔽的状态，`int_raw` 读原始状态，`int_clear` 写回
 * 一个 set 位子集来清掉它们。
 *
 * The peripheral has four banks (one receive bank per core) with eight set bits each;
 * bit n owns context slot n, an eight-byte window of shared registers.  Interrupt state
 * is per bit, so the accessors come in pairs: `int_status` reads the masked state,
 * `int_raw` the raw one, and `int_clear` writes a set-bit mask back to clear it.
 *
 * 这里只管寄存器：**哪个 bank 是本核的、位怎么分配、什么时候响铃**都是驱动层的策略。
 * 本层不持状态，也不做缓存维护——上下文槽的地址由 `ctx_addr` 给出，调用方拿它去做
 * clean/invalidate，因为缓存策略属于调用方的一致性域。
 *
 * Registers only: which bank belongs to this core, how the bits are allocated and when
 * to ring are driver policy.  This layer keeps no state and performs no cache
 * maintenance -- `ctx_addr` hands out the slot address so the caller can
 * clean/invalidate it in its own coherency domain.
 */

#ifdef __cplusplus
extern "C"
{
#endif

/** @brief bank 数量 / Number of set banks. */
#define SG200X_LL_MBOX_BANKS 4U
/** @brief 每个 bank 的 set 位数 / Set bits per bank, one per context slot. */
#define SG200X_LL_MBOX_SLOTS 8U
/** @brief 上下文槽的字节数（两个 32 位字）/ Context slot size in bytes. */
#define SG200X_LL_MBOX_CTX_BYTES 8U

    /**
     * @brief 读某个 bank 的已屏蔽中断状态 / Read one bank's masked interrupt status.
     * @param bank bank 编号（0..3）/ Bank index (0..3).
     * @return 置起位的掩码，bit n = 槽 n / Mask of the pending bits, bit n = slot n.
     */
    uint32_t sg200x_ll_mbox_int_status(uint32_t bank);

    /**
     * @brief 读某个 bank 的原始中断状态（不受 mask 影响）/ Read the raw status.
     * @param bank bank 编号（0..3）/ Bank index (0..3).
     * @return 原始置位掩码 / Raw pending mask.
     */
    uint32_t sg200x_ll_mbox_int_raw(uint32_t bank);

    /**
     * @brief 清掉某些 set 位的状态 / Clear the state of some set bits.
     * @param bank bank 编号（0..3）/ Bank index (0..3).
     * @param mask 要清的位 / Bits to clear.
     */
    void sg200x_ll_mbox_int_clear(uint32_t bank, uint32_t mask);

    /**
     * @brief 读某个 bank 的使能位 / Read one bank's enable bits.
     * @param bank bank 编号（0..3）/ Bank index (0..3).
     * @return 使能掩码 / Enable mask.
     */
    uint32_t sg200x_ll_mbox_enable_get(uint32_t bank);

    /**
     * @brief 置起某些使能位（读改写）/ Set some enable bits (read-modify-write).
     * @param bank bank 编号（0..3）/ Bank index (0..3).
     * @param mask 要置的位 / Bits to set.
     */
    void sg200x_ll_mbox_enable_set(uint32_t bank, uint32_t mask);

    /**
     * @brief 清掉某些使能位（读改写）/ Clear some enable bits (read-modify-write).
     * @param bank bank 编号（0..3）/ Bank index (0..3).
     * @param mask 要清的位 / Bits to clear.
     */
    void sg200x_ll_mbox_enable_clear(uint32_t bank, uint32_t mask);

    /**
     * @brief 敲一次门铃：把给定的 set 位置起 / Ring the doorbell for the given bits.
     * @param mask 要置起的位 / Bits to raise.
     */
    void sg200x_ll_mbox_doorbell(uint32_t mask);

    /**
     * @brief 读全局状态寄存器 / Read the global status register.
     * @return 状态字 / Status word.
     */
    uint32_t sg200x_ll_mbox_status(void);

    /**
     * @brief 取一个上下文槽的地址，供缓存维护使用 / Address of one context slot.
     * @param index 槽号（0..7）/ Slot index (0..7).
     * @return 该槽的本地地址（8 字节，两字对齐）/ Local address of the slot.
     * @note 本层不做缓存维护；需要 clean/invalidate 的调用方拿这个地址去做。
     *       No cache maintenance here: a caller that needs it uses this address.
     */
    uintptr_t sg200x_ll_mbox_ctx_addr(uint32_t index);

    /**
     * @brief 原子读一个上下文槽的两个字 / Atomically read a slot's two words.
     * @param index 槽号（0..7）/ Slot index (0..7).
     * @param[out] value 收到的 8 字节（低字在前）/ Received eight bytes, low word first.
     * @note RV64 上 8 字节对齐访问是单次原子读，这是“要么整条命令、要么没有”的前提。
     *       On RV64 an aligned eight-byte access is a single atomic read, which is what
     *       makes "a whole command or nothing" hold.
     */
    void sg200x_ll_mbox_ctx_load(uint32_t index, uint64_t *value);

    /**
     * @brief 写上下文槽的一个 32 位字 / Write one 32-bit word of a slot.
     * @param index 槽号（0..7）/ Slot index (0..7).
     * @param word 字编号（0 = 头，1 = 载荷）/ Word index (0 = header, 1 = payload).
     * @param value 要写入的值 / Value to write.
     * @note 顺序由调用方决定：这条 ABI 要求先写载荷字、再写头字，两次写之间由调用方
     *       放屏障。本层只保证单次写是整字写，其余字节归零。
     *       Ordering is the caller's: this ABI requires the payload word first and the
     *       header word second, with the caller's barrier between.  Each store is one
     *       whole word; the other byte lanes read back as zero.
     */
    void sg200x_ll_mbox_ctx_store_word(uint32_t index, uint32_t word, uint32_t value);

    /**
     * @brief 清零一个上下文槽 / Zero one context slot.
     * @param index 槽号（0..7）/ Slot index (0..7).
     */
    void sg200x_ll_mbox_ctx_clear(uint32_t index);

#ifdef __cplusplus
}
#endif
