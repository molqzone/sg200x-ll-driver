#include "sg200x_ll_mbox.h"

#include <stddef.h>

#include "sg2002.h"

/**
 * @file sg200x_ll_mbox.c
 * @brief 邮箱外设寄存器布局的唯一描述 / The single description of the mailbox register
 *        layout.
 *
 * 四个 bank 各是一个“使能字 + 四个 set 块”的组合；set 块里 `clr` 写 1 清状态、
 * `intr` 是已屏蔽状态、`raw` 是原始状态。`0x60` 是敲门铃寄存器，`0x64` 是全局状态；
 * 上下文槽在基址之上 1 KiB，每个 8 字节。
 *
 * Each bank is an enable word plus four set blocks; inside a block `clr` clears by
 * writing ones, `intr` is the masked state and `raw` the raw one.  `0x60` is the
 * doorbell and `0x64` the global status; the context slots sit 1 KiB above the base,
 * eight bytes each.
 */

typedef struct
{
    volatile uint32_t clr;
    volatile uint32_t mask;
    volatile uint32_t intr;
    volatile uint32_t raw;
} sg200x_ll_mbox_set_t;

typedef struct
{
    volatile uint32_t enable[SG200X_LL_MBOX_BANKS];
    sg200x_ll_mbox_set_t set[SG200X_LL_MBOX_BANKS];
    volatile uint32_t reserved[4];
    volatile uint32_t mbox_set;
    volatile uint32_t mbox_status;
    volatile uint32_t reserved2[2];
    volatile uint32_t status[SG200X_LL_MBOX_BANKS];
} sg200x_ll_mbox_regs_t;

static_assert(offsetof(sg200x_ll_mbox_regs_t, set) == 0x10U,
              "the set blocks follow the enable words");
static_assert(offsetof(sg200x_ll_mbox_regs_t, mbox_set) == 0x60U,
              "the doorbell register sits at 0x60");
static_assert(offsetof(sg200x_ll_mbox_regs_t, mbox_status) == 0x64U,
              "the global status register follows the doorbell");

static volatile sg200x_ll_mbox_regs_t *mbox_regs(void)
{
    return (volatile sg200x_ll_mbox_regs_t *)APB_MAILBOX_BASE;
}

static volatile uint32_t *mbox_ctx(uint32_t index)
{
    return (volatile uint32_t *)(MAILBOX_BUFF_BASE + index * SG200X_LL_MBOX_CTX_BYTES);
}

uint32_t sg200x_ll_mbox_int_status(uint32_t bank)
{
    return mbox_regs()->set[bank].intr;
}

uint32_t sg200x_ll_mbox_int_raw(uint32_t bank)
{
    return mbox_regs()->set[bank].raw;
}

void sg200x_ll_mbox_int_clear(uint32_t bank, uint32_t mask)
{
    mbox_regs()->set[bank].clr = mask;
}

uint32_t sg200x_ll_mbox_enable_get(uint32_t bank)
{
    return mbox_regs()->enable[bank];
}

void sg200x_ll_mbox_enable_set(uint32_t bank, uint32_t mask)
{
    mbox_regs()->enable[bank] |= mask;
}

void sg200x_ll_mbox_enable_clear(uint32_t bank, uint32_t mask)
{
    mbox_regs()->enable[bank] &= ~mask;
}

void sg200x_ll_mbox_doorbell(uint32_t mask)
{
    mbox_regs()->mbox_set = mask;
}

uint32_t sg200x_ll_mbox_status(void)
{
    return mbox_regs()->mbox_status;
}

uintptr_t sg200x_ll_mbox_ctx_addr(uint32_t index)
{
    return (uintptr_t)mbox_ctx(index);
}

void sg200x_ll_mbox_ctx_load(uint32_t index, uint64_t *value)
{
    if (value != NULL)
    {
        *value = *(volatile uint64_t *)mbox_ctx(index);
    }
}

void sg200x_ll_mbox_ctx_store_word(uint32_t index, uint32_t word, uint32_t value)
{
    mbox_ctx(index)[word & 1U] = value;
}

void sg200x_ll_mbox_ctx_clear(uint32_t index)
{
    *(volatile uint64_t *)mbox_ctx(index) = 0U;
}
