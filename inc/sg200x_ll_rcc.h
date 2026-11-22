#pragma once

#include <stdbool.h>
#include <stdint.h>

#include "sg2002.h"
#include "sg200x_ll_csr.h"
#include "sg200x_ll_utils.h"

#ifdef __cplusplus
extern "C"
{
#endif
    /**
     * @brief 将 CLKGEN 偏移解析为具名寄存器地址 / Resolve a CLKGEN offset to a named register address.
     *
     * @param offset 相对于相应寄存器块基址的字节偏移 / Byte offset from the relevant register-block base.
     * @return 具名寄存器地址；未知或保留偏移返回空指针。
     *         Named register address, or null for an unknown or reserved offset.
     */
    volatile uint32_t *sg200x_ll_rcc_clkgen_reg(uint32_t offset);
#ifdef __cplusplus
}
#endif

/**
 * @brief 解析 CLK_EN0 至 CLK_EN4 的寄存器偏移 / Resolve a CLK_EN0 through CLK_EN4 register offset.
 *
 * @param offset 相对于相应寄存器块基址的字节偏移 / Byte offset from the relevant register-block base.
 * @return 有效门控寄存器地址；偏移无效时返回空指针。
 *         Valid gate-register address, or null for an invalid offset.
 */
static inline volatile uint32_t *sg200x_ll_rcc_clk_en_reg(uint32_t offset)
{
    return offset <= CLKGEN_CLK_EN4_OFFSET && (offset % sizeof(uint32_t)) == 0U
               ? &CLKGEN->CLK_EN[offset / sizeof(uint32_t)]
               : (volatile uint32_t *)0;
}

/**
 * @brief 通过 CLKGEN 选择器解析分频器寄存器地址。
 *        Resolve a divider register address through the CLKGEN selector.
 *
 * @param offset 相对于相应寄存器块基址的字节偏移 / Byte offset from the relevant register-block base.
 * @return 具名寄存器地址；未知偏移返回空指针 / Named register address, or null for an unknown offset.
 * @pre 调用者必须传入分频器偏移；选择器自身也能解析其他 CLKGEN 寄存器。
 *      The caller must pass a divider offset; the selector itself also resolves other CLKGEN registers.
 */
static inline volatile uint32_t *sg200x_ll_rcc_div_reg(uint32_t offset)
{
    return sg200x_ll_rcc_clkgen_reg(offset);
}

/**
 * @brief 读取具名 CLKGEN 寄存器 / Read a named CLKGEN register.
 *
 * @param offset 相对于相应寄存器块基址的字节偏移 / Byte offset from the relevant register-block base.
 * @return 寄存器值；偏移未知时返回 0 / Register value, or zero for an unknown offset.
 */
static inline uint32_t sg200x_ll_rcc_clkgen_read(uint32_t offset)
{
    const volatile uint32_t *reg = sg200x_ll_rcc_clkgen_reg(offset);
    return reg != (const volatile uint32_t *)0 ? *reg : 0U;
}

/**
 * @brief 写入具名 CLKGEN 寄存器 / Write a named CLKGEN register.
 *
 * @param offset 相对于相应寄存器块基址的字节偏移 / Byte offset from the relevant register-block base.
 * @param value 要写入或编码的数值 / Value to write or encode.
 */
static inline void sg200x_ll_rcc_clkgen_write(uint32_t offset, uint32_t value)
{
    volatile uint32_t *reg = sg200x_ll_rcc_clkgen_reg(offset);
    if (reg != (volatile uint32_t *)0)
    {
        *reg = value;
    }
}

/**
 * @brief 读取 CLKGEN 寄存器中的位字段 / Read a bit field from a CLKGEN register.
 *
 * @param offset 相对于相应寄存器块基址的字节偏移 / Byte offset from the relevant register-block base.
 * @param shift 字段最低有效位的零起始位置 / Zero-based position of the field's least-significant bit.
 * @param width 字段位数，且 shift + width 不超过 32 / Field bit count; shift plus width must not exceed 32.
 * @return 右对齐字段值；偏移未知时为 0 / Right-aligned field value, or zero for an unknown offset.
 * @note shift 和 width 必须构成有效的 32 位字段；底层位运算不检查范围。
 *       shift and width must describe a valid 32-bit field; the underlying bit operations do not check
 *       bounds.
 */
static inline uint32_t sg200x_ll_rcc_field_read(uint32_t offset, uint32_t shift, uint32_t width)
{
    return sg200x_ll_field_get(sg200x_ll_rcc_clkgen_read(offset), shift, width);
}

/**
 * @brief 读改写 CLKGEN 位字段，在 I/O 屏障后检查读回值。
 *        Modify a CLKGEN bit field and check readback after an I/O fence.
 *
 * @param offset 相对于相应寄存器块基址的字节偏移 / Byte offset from the relevant register-block base.
 * @param shift 字段最低有效位的零起始位置 / Zero-based position of the field's least-significant bit.
 * @param width 字段位数，且 shift + width 不超过 32 / Field bit count; shift plus width must not exceed 32.
 * @param value 要写入或编码的数值 / Value to write or encode.
 * @return 读回匹配时为 true；未知偏移或读回不匹配时为 false。
 *         True for matching readback; false for an unknown offset or mismatched readback.
 * @note shift 和 width 必须构成有效的 32 位字段；底层位运算不检查范围。
 *       shift and width must describe a valid 32-bit field; the underlying bit operations do not check
 *       bounds.
 * @note false 可能来自写入后的读回不匹配；此接口不执行回滚。
 *       false may indicate mismatched readback after a write; this interface does not roll back changes.
 * @note value 超出字段宽度时会先截断写入，再因读回不等而返回 false。
 *       An oversized value is truncated on write and then causes false because readback differs.
 */
static inline bool sg200x_ll_rcc_field_write(uint32_t offset, uint32_t shift, uint32_t width, uint32_t value)
{
    volatile uint32_t *reg = sg200x_ll_rcc_clkgen_reg(offset);
    if (reg == (volatile uint32_t *)0)
    {
        return false;
    }
    uint32_t current = *reg;
    current = sg200x_ll_field_prepare(current, shift, width, value);
    *reg = current;
    sg200x_ll_csr_fence_io();
    return sg200x_ll_field_get(*reg, shift, width) == value;
}

/**
 * @brief 读改写 CLKGEN 单个位并检查读回值 / Modify one CLKGEN bit and check readback.
 *
 * @param offset 相对于相应寄存器块基址的字节偏移 / Byte offset from the relevant register-block base.
 * @param bit 寄存器位号，范围为 0 到 31 / Register bit index from 0 through 31.
 * @param enabled 目标位的使能状态 / Requested enable state of the bit.
 * @return 读回状态匹配时为 true；否则为 false / True when the readback state matches; false otherwise.
 * @note false 可能来自写入后的读回不匹配；此接口不执行回滚。
 *       false may indicate mismatched readback after a write; this interface does not roll back changes.
 */
static inline bool sg200x_ll_rcc_bit_write(uint32_t offset, uint32_t bit, bool enabled)
{
    volatile uint32_t *reg = sg200x_ll_rcc_clkgen_reg(offset);
    if (reg == (volatile uint32_t *)0)
    {
        return false;
    }
    uint32_t current = *reg;
    current = enabled ? current | LL_BIT(bit) : current & ~(uint32_t)LL_BIT(bit);
    *reg = current;
    return ((*reg & LL_BIT(bit)) != 0U) == enabled;
}

/**
 * @brief 读取一个已定义的 G6 PLL 控制寄存器 / Read one defined G6 PLL control register.
 *
 * @param offset 相对于相应寄存器块基址的字节偏移 / Byte offset from the relevant register-block base.
 * @return MPLL、TPLL 或 FPLL 的值；偏移未知时为 0 / MPLL, TPLL, or FPLL value, or zero for an unknown offset.
 */
static inline uint32_t sg200x_ll_rcc_g6_pll_read(uint32_t offset)
{
    switch (offset)
    {
    case PLL_G6_MPLL_OFFSET:
        return PLL_G6->MPLL;
    case PLL_G6_TPLL_OFFSET:
        return PLL_G6->TPLL;
    case PLL_G6_FPLL_OFFSET:
        return PLL_G6->FPLL;
    default:
        return 0U;
    }
}

/**
 * @brief 获取指定 SOFT_RSTN 寄存器 / Get a selected SOFT_RSTN register.
 *
 * @param index SOFT_RSTN 数组编号，小于 RSTGEN_SOFT_RSTN_COUNT。
 *        SOFT_RSTN array index below RSTGEN_SOFT_RSTN_COUNT.
 * @return 寄存器地址；编号无效时返回空指针 / Register address, or null for an invalid index.
 */
static inline volatile uint32_t *sg200x_ll_rcc_reset_reg(uint32_t index)
{
    return index < RSTGEN_SOFT_RSTN_COUNT ? &RSTGEN->SOFT_RSTN[index] : (volatile uint32_t *)0;
}

/**
 * @brief 使能指定外设时钟门控位 / Enable a selected peripheral clock gate.
 *
 * @param gate_reg CLK_EN 门控寄存器的字节偏移 / Byte offset of the CLK_EN gate register.
 * @param gate_bit 门控位号，范围为 0 到 31 / Gate bit index from 0 through 31.
 */
static inline void sg200x_ll_rcc_gate_enable(unsigned gate_reg, unsigned gate_bit)
{
    volatile uint32_t *reg = sg200x_ll_rcc_clk_en_reg(gate_reg);
    if (reg != (volatile uint32_t *)0)
    {
        *reg |= LL_BIT(gate_bit);
    }
}

/**
 * @brief 禁止指定外设时钟门控位 / Disable a selected peripheral clock gate.
 *
 * @param gate_reg CLK_EN 门控寄存器的字节偏移 / Byte offset of the CLK_EN gate register.
 * @param gate_bit 门控位号，范围为 0 到 31 / Gate bit index from 0 through 31.
 */
static inline void sg200x_ll_rcc_gate_disable(unsigned gate_reg, unsigned gate_bit)
{
    volatile uint32_t *reg = sg200x_ll_rcc_clk_en_reg(gate_reg);
    if (reg != (volatile uint32_t *)0)
    {
        *reg &= ~(uint32_t)LL_BIT(gate_bit);
    }
}

/**
 * @brief 读取指定时钟门控位 / Read a selected clock-gate bit.
 *
 * @param gate_reg CLK_EN 门控寄存器的字节偏移 / Byte offset of the CLK_EN gate register.
 * @param gate_bit 门控位号，范围为 0 到 31 / Gate bit index from 0 through 31.
 * @return 门控已使能时为 true；偏移无效时为 false / True when enabled; false for an invalid offset.
 */
static inline bool sg200x_ll_rcc_gate_is_enabled(unsigned gate_reg, unsigned gate_bit)
{
    volatile uint32_t *reg = sg200x_ll_rcc_clk_en_reg(gate_reg);
    return reg != (volatile uint32_t *)0 && ((*reg & LL_BIT(gate_bit)) != 0U);
}

/**
 * @brief 使指定时钟分支旁路到晶振 / Bypass a selected clock branch to the crystal source.
 *
 * @param bypass_reg CLK_BYP0 或 CLK_BYP1 的字节偏移 / Byte offset of CLK_BYP0 or CLK_BYP1.
 * @param bypass_bit 旁路位号，范围为 0 到 31 / Bypass bit index from 0 through 31.
 */
static inline void sg200x_ll_rcc_bypass_enable(unsigned bypass_reg, unsigned bypass_bit)
{
    volatile uint32_t *reg = sg200x_ll_rcc_clkgen_reg(bypass_reg);
    if (bypass_reg == CLKGEN_CLK_BYP0_OFFSET)
    {
        *reg |= LL_BIT(bypass_bit);
    }
    else if (bypass_reg == CLKGEN_CLK_BYP1_OFFSET)
    {
        *reg |= LL_BIT(bypass_bit);
    }
}

/**
 * @brief 恢复指定时钟分支的正常父时钟路径 / Restore the normal parent path of a selected clock branch.
 *
 * @param bypass_reg CLK_BYP0 或 CLK_BYP1 的字节偏移 / Byte offset of CLK_BYP0 or CLK_BYP1.
 * @param bypass_bit 旁路位号，范围为 0 到 31 / Bypass bit index from 0 through 31.
 */
static inline void sg200x_ll_rcc_bypass_disable(unsigned bypass_reg, unsigned bypass_bit)
{
    volatile uint32_t *reg = sg200x_ll_rcc_clkgen_reg(bypass_reg);
    if (bypass_reg == CLKGEN_CLK_BYP0_OFFSET)
    {
        *reg &= ~(uint32_t)LL_BIT(bypass_bit);
    }
    else if (bypass_reg == CLKGEN_CLK_BYP1_OFFSET)
    {
        *reg &= ~(uint32_t)LL_BIT(bypass_bit);
    }
}

/**
 * @brief 检查时钟分支是否旁路到晶振 / Check whether a clock branch bypasses to the crystal.
 *
 * @param bypass_reg CLK_BYP0 或 CLK_BYP1 的字节偏移 / Byte offset of CLK_BYP0 or CLK_BYP1.
 * @param bypass_bit 旁路位号，范围为 0 到 31 / Bypass bit index from 0 through 31.
 * @return 旁路位置位时为 true；偏移无效时为 false。
 *         True when the bypass bit is set; false for an invalid offset.
 */
static inline bool sg200x_ll_rcc_bypass_is_enabled(unsigned bypass_reg, unsigned bypass_bit)
{
    if (bypass_reg != CLKGEN_CLK_BYP0_OFFSET && bypass_reg != CLKGEN_CLK_BYP1_OFFSET)
    {
        return false;
    }
    return (sg200x_ll_rcc_clkgen_read(bypass_reg) & LL_BIT(bypass_bit)) != 0U;
}

/**
 * @brief 读取 C906_0 的路径 0 选择位 / Read the C906_0 path-zero selection bit.
 *
 * @return 路径 0 选择位置位时返回 true / True when the path-zero selection bit is set.
 */
static inline bool sg200x_ll_rcc_c906_0_uses_path0(void)
{
    return (CLKGEN->CLK_SEL0 & CLKGEN_SEL0_C906_0_BIT) != 0U;
}

/**
 * @brief 读取 C906_1 的路径 0 选择位 / Read the C906_1 path-zero selection bit.
 *
 * @return 路径 0 选择位置位时返回 true / True when the path-zero selection bit is set.
 */
static inline bool sg200x_ll_rcc_c906_1_uses_path0(void)
{
    return (CLKGEN->CLK_SEL0 & CLKGEN_SEL0_C906_1_BIT) != 0U;
}

/**
 * @brief 读取分频因子的原始寄存器字段 / Read the raw register field of a divider factor.
 *
 * @param div_offset 器件头定义的分频器寄存器字节偏移。
 *        Divider register byte offset defined by the device header.
 * @param factor_width 该时钟分支的因子字段位宽 / Factor-field width of this clock branch.
 * @return 原始因子字段，不一定是当前有效分频值。
 *         Raw factor field, which may differ from the effective divider.
 * @note 因子选择位为 0 时，硬件使用初始因子而非此字段；位宽见器件定义。
 *       With register-factor selection clear, hardware uses the initial factor instead; see device
 *       definitions for field width.
 */
static inline uint32_t sg200x_ll_rcc_div_factor_raw_get(uint32_t div_offset, uint32_t factor_width)
{
    return sg200x_ll_rcc_field_read(div_offset, CLKGEN_DIV_FACTOR_SHIFT, factor_width);
}

/**
 * @brief 检查分频器是否选择寄存器中的因子 / Check whether a divider selects its register-programmed factor.
 *
 * @param div_offset 器件头定义的分频器寄存器字节偏移。
 *        Divider register byte offset defined by the device header.
 * @return 因子选择位置位时返回 true / True when the register-factor selector is set.
 */
static inline bool sg200x_ll_rcc_div_uses_register_factor(uint32_t div_offset)
{
    return (sg200x_ll_rcc_clkgen_read(div_offset) & CLKGEN_DIV_USE_REG_FACTOR_BIT) != 0U;
}

/**
 * @brief 检查分频器复位是否已释放 / Check whether divider reset is deasserted.
 *
 * @param div_offset 器件头定义的分频器寄存器字节偏移。
 *        Divider register byte offset defined by the device header.
 * @return 复位释放位置位时为 true；未知偏移时为 false。
 *         True when reset is released; false for an unknown offset.
 */
static inline bool sg200x_ll_rcc_div_reset_is_deasserted(uint32_t div_offset)
{
    return (sg200x_ll_rcc_clkgen_read(div_offset) & CLKGEN_DIV_RESET_BIT) != 0U;
}

/**
 * @brief 写入分频因子、选择寄存器因子并释放复位。
 *        Write the divider factor, select it, and release divider reset.
 *
 * @param div_offset 器件头定义的分频器寄存器字节偏移。
 *        Divider register byte offset defined by the device header.
 * @param factor_width 该时钟分支的因子字段位宽 / Factor-field width of this clock branch.
 * @param factor 硬件允许的分频因子 / Divider factor permitted by the hardware.
 */
static inline void sg200x_ll_rcc_div_factor_set(uint32_t div_offset, uint32_t factor_width, uint32_t factor)
{
    volatile uint32_t *reg = sg200x_ll_rcc_div_reg(div_offset);
    if (reg == (volatile uint32_t *)0)
    {
        return;
    }
    uint32_t value = *reg;
    value = sg200x_ll_field_prepare(value, CLKGEN_DIV_FACTOR_SHIFT, factor_width, factor);
    value |= CLKGEN_DIV_USE_REG_FACTOR_BIT;
    value |= CLKGEN_DIV_RESET_BIT;
    *reg = value;
}

/**
 * @brief 拉低分频器复位位 / Assert divider reset by clearing its reset bit.
 *
 * @param div_offset 器件头定义的分频器寄存器字节偏移。
 *        Divider register byte offset defined by the device header.
 */
static inline void sg200x_ll_rcc_div_reset_assert(uint32_t div_offset)
{
    volatile uint32_t *reg = sg200x_ll_rcc_div_reg(div_offset);
    if (reg != (volatile uint32_t *)0)
    {
        *reg &= ~(uint32_t)CLKGEN_DIV_RESET_BIT;
    }
}

/**
 * @brief 置位分频器复位释放位 / Deassert divider reset by setting its reset bit.
 *
 * @param div_offset 器件头定义的分频器寄存器字节偏移。
 *        Divider register byte offset defined by the device header.
 */
static inline void sg200x_ll_rcc_div_reset_release(uint32_t div_offset)
{
    volatile uint32_t *reg = sg200x_ll_rcc_div_reg(div_offset);
    if (reg != (volatile uint32_t *)0)
    {
        *reg |= CLKGEN_DIV_RESET_BIT;
    }
}

/**
 * @brief 读取分频叶节点的父时钟选择字段 / Read a divider leaf's parent-clock selector.
 *
 * @param div_offset 器件头定义的分频器寄存器字节偏移。
 *        Divider register byte offset defined by the device header.
 * @return 原始时钟源编码；未知偏移时为 0 / Raw source encoding, or zero for an unknown offset.
 */
static inline uint32_t sg200x_ll_rcc_div_source_get(uint32_t div_offset)
{
    return sg200x_ll_rcc_field_read(div_offset, CLKGEN_DIV_SRC_SHIFT, CLKGEN_DIV_SRC_WIDTH);
}

/**
 * @brief 写入分频叶节点的父时钟选择字段 / Write a divider leaf's parent-clock selector.
 *
 * @param div_offset 器件头定义的分频器寄存器字节偏移。
 *        Divider register byte offset defined by the device header.
 * @param source 父时钟选择编码；仅字段内的低位被写入。
 *        Parent-clock selector encoding; only bits within the field are written.
 */
static inline void sg200x_ll_rcc_div_source_set(uint32_t div_offset, uint32_t source)
{
    volatile uint32_t *reg = sg200x_ll_rcc_div_reg(div_offset);
    if (reg != (volatile uint32_t *)0)
    {
        *reg = sg200x_ll_field_prepare(*reg, CLKGEN_DIV_SRC_SHIFT, CLKGEN_DIV_SRC_WIDTH, source);
    }
}

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @brief 查询复位目标的寄存器及位坐标 / Look up a reset target's register and bit coordinates.
     *
     * @param target 器件复位目标枚举 / Device reset-target enumeration.
     * @return 目标坐标；无效目标返回 RESET_NONE 对应的无效坐标。
     *         Target coordinates, or RESET_NONE's invalid coordinates for an invalid target.
     */
    rstgen_reset_location_t sg200x_ll_rcc_reset_loc_get(rstgen_reset_target_t target);

#ifdef __cplusplus
}
#endif

/**
 * @brief 检查复位目标是否具有有效坐标 / Check whether a reset target has valid coordinates.
 *
 * @param target 器件复位目标枚举 / Device reset-target enumeration.
 * @return 目标存在时返回 true / True when the target exists.
 */
static inline bool sg200x_ll_rcc_reset_target_exists(rstgen_reset_target_t target)
{
    rstgen_reset_location_t loc = sg200x_ll_rcc_reset_loc_get(target);
    return loc.reg_index != RSTGEN_RESET_LOCATION_INVALID;
}

/**
 * @brief 拉低目标模块的软复位位 / Assert a target module's active-low soft reset.
 *
 * @param target 器件复位目标枚举 / Device reset-target enumeration.
 * @pre 目标模块的总线及 DMA 活动必须已停止，参见 TRM 7.3。
 *      The target module's bus and DMA activity must be idle; see TRM 7.3.
 * @note 复位位低有效且不自动清除；调用者负责 I/O 屏障和模块活动状态。无效目标不执行写入。
 *       Reset bits are active-low and not self-clearing; the caller manages I/O barriers and module activity.
 *       Invalid targets cause no write.
 */
static inline void sg200x_ll_rcc_reset_assert(rstgen_reset_target_t target)
{
    rstgen_reset_location_t loc = sg200x_ll_rcc_reset_loc_get(target);
    volatile uint32_t *reg = sg200x_ll_rcc_reset_reg(loc.reg_index);
    if (reg != (volatile uint32_t *)0)
    {
        *reg &= ~(uint32_t)LL_BIT(loc.bit);
    }
}

/**
 * @brief 置位目标模块的软复位释放位 / Deassert a target module's active-low soft reset.
 *
 * @param target 器件复位目标枚举 / Device reset-target enumeration.
 * @note 复位位低有效且不自动清除；调用者负责 I/O 屏障和模块活动状态。无效目标不执行写入。
 *       Reset bits are active-low and not self-clearing; the caller manages I/O barriers and module activity.
 *       Invalid targets cause no write.
 */
static inline void sg200x_ll_rcc_reset_release(rstgen_reset_target_t target)
{
    rstgen_reset_location_t loc = sg200x_ll_rcc_reset_loc_get(target);
    volatile uint32_t *reg = sg200x_ll_rcc_reset_reg(loc.reg_index);
    if (reg != (volatile uint32_t *)0)
    {
        *reg |= LL_BIT(loc.bit);
    }
}

/**
 * @brief 检查目标模块的软复位是否释放 / Check whether a target module's soft reset is released.
 *
 * @param target 器件复位目标枚举 / Device reset-target enumeration.
 * @return 有效目标的复位已释放时为 true；无效目标为 false。
 *         True for a valid target with reset released; false for an invalid target.
 */
static inline bool sg200x_ll_rcc_reset_is_released(rstgen_reset_target_t target)
{
    rstgen_reset_location_t loc = sg200x_ll_rcc_reset_loc_get(target);
    volatile uint32_t *reg = sg200x_ll_rcc_reset_reg(loc.reg_index);
    return reg != (volatile uint32_t *)0 && ((*reg & LL_BIT(loc.bit)) != 0U);
}

static_assert(RSTGEN_BASE == 0x03003000UL, "RSTGEN base moved");
static_assert(CLKGEN_BASE == 0x03002000UL, "CLKGEN base moved");

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @brief 为 RTC SARADC 选择晶振并释放域内复位。
     *        Select the crystal and release domain reset for RTC SARADC.
     * @note 保留其他 RTC 时钟和复位字段；主域 SARADC 资源由调用者独立管理。
     *        Preserves other RTC clock/reset fields; the caller manages main-domain SARADC resources
     *        separately.
     */
    void sg200x_ll_rcc_rtc_saradc_enable(void);

#ifdef __cplusplus
}
#endif

/**
 * @brief 选择主域看门狗的共享计数时钟 / Select the shared counter clock of main-domain watchdogs.
 * @param use_32k 为 true 选择 RTC 32 kHz，否则选择主晶振。
 *        True selects RTC 32 kHz; false selects the main crystal.
 * @note 整体替换 TOP WDT_CTRL[10:8]，影响所有主域看门狗；调用者协调所有权和时钟切换。
 *        Replaces all of TOP WDT_CTRL[10:8], affecting every main-domain watchdog; the caller coordinates
 *        ownership and clock switching.
 */
static inline void sg200x_ll_rcc_watchdog_clock_select(bool use_32k)
{
    TOP->WDT_CTRL = (TOP->WDT_CTRL & ~TOP_WDT_CLOCK_SELECT_MASK) | (use_32k ? TOP_WDT_CLOCK_32K : 0U);
    sg200x_ll_csr_fence_io();
}
