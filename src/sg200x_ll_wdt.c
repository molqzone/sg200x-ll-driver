#include "sg200x_ll_wdt.h"
#include "sg200x_ll_csr.h"

/**
 * @brief 检查主域看门狗实例 / Validate a main-domain watchdog instance.
 * @param wdt 主域 WDT0 至 WDT2 寄存器实例 / Main-domain WDT0 through WDT2 register instance.
 * @return WDT0 至 WDT2 返回 true / True for WDT0 through WDT2.
 */
static bool wdt_instance_valid(const WDT_Type *wdt)
{
    return wdt == WDT0_REGS || wdt == WDT1_REGS || wdt == WDT2_REGS;
}

void sg200x_ll_wdt_struct_init(sg200x_ll_wdt_init_t *config)
{
    if (config != NULL)
    {
        config->top = 0U;
        config->interrupt_first = false;
    }
}

bool sg200x_ll_wdt_init(WDT_Type *wdt, const sg200x_ll_wdt_init_t *config)
{
    if (!wdt_instance_valid(wdt) || config == NULL || config->top > WDT_TOP_MAX ||
        sg200x_ll_wdt_is_enabled(wdt))
        return false;
    sg200x_ll_wdt_timeout_set(wdt, config->top);
    wdt->TOC = 0U;
    wdt->CR = config->interrupt_first ? WDT_CR_INTERRUPT_RESPONSE_BIT : 0U;
    sg200x_ll_csr_fence_io();
    return true;
}

bool sg200x_ll_wdt_start(WDT_Type *wdt, uint32_t top, bool interrupt_first)
{
    if (!wdt_instance_valid(wdt) || top > WDT_TOP_MAX || sg200x_ll_wdt_is_enabled(wdt))
        return false;
    sg200x_ll_wdt_timeout_set(wdt, top);
    sg200x_ll_wdt_feed(wdt);
    sg200x_ll_csr_fence_io();
    wdt->CR = WDT_CR_ENABLE_BIT | (interrupt_first ? WDT_CR_INTERRUPT_RESPONSE_BIT : 0U);
    sg200x_ll_csr_fence_io();
    return true;
}

bool sg200x_ll_wdt_reset_route_set(uint32_t index, bool reset_cpu)
{
    if (index >= WDT_COUNT)
        return false;
    TOP->SYS_CTRL |= TOP_SYS_CTRL_WDT_COMPAT_ENABLE_BIT;
    const uint32_t system_bit = 1U << (TOP_WDT_SYSTEM_ROUTE_SHIFT + index);
    const uint32_t cpu_bit = 1U << (TOP_WDT_CPU_ROUTE_SHIFT + index);
    TOP->WDT_CTRL = (TOP->WDT_CTRL & ~(system_bit | cpu_bit)) | (reset_cpu ? cpu_bit : system_bit);
    sg200x_ll_csr_fence_io();
    return true;
}
