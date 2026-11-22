#include "sg200x_ll_adc.h"
#include "sg200x_ll_csr.h"

/**
 * @brief 检查 SARADC 电源域实例 / Validate a SARADC power-domain instance.
 * @param adc 主域或 RTC 域 SARADC 实例 / Main-domain or RTC-domain SARADC instance.
 * @return 主域或 RTC 域实例返回 true / True for the main-domain or RTC-domain instance.
 */
static bool adc_instance_valid(const SARADC_Type *adc)
{
    return adc == SARADC_REGS || adc == RTC_SARADC_REGS;
}

void sg200x_ll_adc_struct_init(sg200x_ll_adc_init_t *config)
{
    if (config != NULL)
    {
        config->clock_divider = SARADC_CYCLE_DIVIDER_MAX;
        config->external_reference = false;
    }
}

bool sg200x_ll_adc_init(SARADC_Type *adc, const sg200x_ll_adc_init_t *config)
{
    if (!adc_instance_valid(adc) || config == NULL || config->clock_divider > SARADC_CYCLE_DIVIDER_MAX ||
        sg200x_ll_adc_is_busy(adc))
        return false;
    uint32_t cycles = adc->CYC_SET;
    cycles &=
        ~(SARADC_CYCLE_SETTLE_MASK | SARADC_CYCLE_SAMPLE_MASK | SARADC_CYCLE_DIVIDER_MASK |
          SARADC_CYCLE_COMPARE_MASK);
    cycles |= SARADC_CYCLE_SETTLE_DEFAULT | (SARADC_CYCLE_SAMPLE_DEFAULT << SARADC_CYCLE_SAMPLE_SHIFT) |
              (config->clock_divider << SARADC_CYCLE_DIVIDER_SHIFT) |
              (SARADC_CYCLE_COMPARE_DEFAULT << SARADC_CYCLE_COMPARE_SHIFT);
    adc->CYC_SET = cycles;
    adc->INTR_EN = 0U;
    adc->INTR_CLR = SARADC_INTERRUPT_BIT;
    adc->TEST = (adc->TEST & ~SARADC_TEST_EXTERNAL_REFERENCE_BIT) |
                (config->external_reference ? SARADC_TEST_EXTERNAL_REFERENCE_BIT : 0U);
    sg200x_ll_csr_fence_io();
    return true;
}

bool sg200x_ll_adc_start(SARADC_Type *adc, uint32_t channel)
{
    if (!adc_instance_valid(adc) || channel == 0U || channel > SARADC_CHANNEL_COUNT ||
        sg200x_ll_adc_is_busy(adc))
        return false;
    const uint32_t control = (adc->CTRL & ~(SARADC_CTRL_CHANNEL_MASK | SARADC_CTRL_TRIGGER_BIT)) |
                             (1U << (SARADC_CTRL_CHANNEL_SHIFT + channel));
    adc->CTRL = control;
    adc->INTR_CLR = SARADC_INTERRUPT_BIT;
    sg200x_ll_csr_fence_io();
    adc->CTRL = control | SARADC_CTRL_TRIGGER_BIT;
    sg200x_ll_csr_fence_io();
    return true;
}

bool sg200x_ll_adc_wait_idle(const SARADC_Type *adc, uint32_t attempts)
{
    if (!adc_instance_valid(adc))
        return false;
    for (uint32_t attempt = 0U; attempt < attempts; ++attempt)
    {
        if (!sg200x_ll_adc_is_busy(adc))
            return true;
    }
    return false;
}
