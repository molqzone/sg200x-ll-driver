#include "sg200x_ll_rcc.h"

/**
 * @def RESET_LOCATION(name, reg_index, bit)
 * @brief 由器件映射生成一个复位坐标表项 / Generate one reset-coordinate table entry from the device map.
 *
 * @param name 复位目标名称后缀 / Reset-target name suffix.
 * @param reg_index SOFT_RSTN 寄存器编号 / SOFT_RSTN register index.
 * @param bit 复位位编号 / Reset-bit index.
 */
#define RESET_LOCATION(name, reg_index, bit) [RESET_##name] = {reg_index, bit},
/**
 * @brief 由 SG2002_RESET_MAP 生成并只编译一次的复位坐标表。
 *        Reset-coordinate table generated from SG2002_RESET_MAP and compiled once.
 */
static const rstgen_reset_location_t rstgen_reset_locations[RESET_TARGET_COUNT] = {
    SG2002_RESET_MAP(RESET_LOCATION)
};
#undef RESET_LOCATION

rstgen_reset_location_t sg200x_ll_rcc_reset_loc_get(rstgen_reset_target_t target)
{
    if ((unsigned)target < (unsigned)RESET_TARGET_COUNT)
    {
        return rstgen_reset_locations[target];
    }
    return rstgen_reset_locations[RESET_NONE];
}

/**
 * @def CLKGEN_REGISTER_CASE(member)
 * @brief 生成具名 CLKGEN 寄存器的偏移选择分支。
 *        Generate an offset-selection case for a named CLKGEN register.
 *
 * @param member CLKGEN_Type 中的成员选择表达式 / Member designator in CLKGEN_Type.
 */
volatile uint32_t *sg200x_ll_rcc_clkgen_reg(uint32_t offset)
{
    switch (offset)
    {
#define CLKGEN_REGISTER_CASE(member)    \
    case offsetof(CLKGEN_Type, member): \
        return &CLKGEN->member;
        SG2002_CLKGEN_REGISTERS(CLKGEN_REGISTER_CASE)
#undef CLKGEN_REGISTER_CASE
    default:
        return (volatile uint32_t *)0;
    }
}

void sg200x_ll_rcc_rtc_saradc_enable(void)
{
    RTC_CTRL_REGS->CLOCK_MUX &= ~RTC_CTRL_SARADC_OSC_DIV_BIT;
    sg200x_ll_csr_fence_io();
    RTC_CTRL_REGS->RESET |= RTC_CTRL_SARADC_RESETN_BIT;
    sg200x_ll_csr_fence_io();
}
