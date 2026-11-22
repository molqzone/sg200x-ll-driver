#pragma once

#include <stdbool.h>
#include <stdint.h>

#include "sg2002.h"
#include "sg200x_ll_utils.h"

/**
 * @brief 检查引脚复用功能值是否适合 3 位字段 / Check whether a pin function fits the three-bit selector.
 *
 * @param function 引脚复用功能编码，范围为 0 到 7 / Pin-function encoding from 0 through 7.
 * @return 功能值在 0 到 7 之间时为 true / True for function values from 0 through 7.
 */
static inline bool sg200x_ll_pinmux_function_is_valid(uint32_t function)
{
    return function <= PINMUX_FUNCTION_MASK;
}

/**
 * @brief 检查引脚选择寄存器偏移的范围和对齐 / Check a pin-selector register offset for range and alignment.
 *
 * @param offset 相对于相应寄存器块基址的字节偏移 / Byte offset from the relevant register-block base.
 * @return 偏移按 4 字节对齐且位于选择器数组内时为 true。
 *         True for a four-byte-aligned offset within the selector array.
 */
static inline bool sg200x_ll_pinmux_offset_is_valid(uint32_t offset)
{
    return offset % sizeof(uint32_t) == 0U && offset < sizeof(PINMUX->FUNCTION);
}

/**
 * @brief 设置一个引脚的复用功能并保留其他位 / Set one pin's function while preserving the other bits.
 *
 * @param offset 相对于相应寄存器块基址的字节偏移 / Byte offset from the relevant register-block base.
 * @param function 引脚复用功能编码，范围为 0 到 7 / Pin-function encoding from 0 through 7.
 * @return 成功返回 true；偏移或功能值无效时不写寄存器并返回 false。
 *         True on success; false without a register write for an invalid offset or function.
 */
static inline bool sg200x_ll_pinmux_function_set(uint32_t offset, uint32_t function)
{
    if (!sg200x_ll_pinmux_offset_is_valid(offset) || !sg200x_ll_pinmux_function_is_valid(function))
    {
        return false;
    }
    const uint32_t index = offset / sizeof(uint32_t);
    PINMUX->FUNCTION[index] = (PINMUX->FUNCTION[index] & ~PINMUX_FUNCTION_MASK) | function;
    return true;
}

/**
 * @brief 读取一个引脚的复用功能 / Read one pin's selected function.
 *
 * @param offset 相对于相应寄存器块基址的字节偏移 / Byte offset from the relevant register-block base.
 * @return 3 位功能值；偏移无效时返回 0 / Three-bit function value, or zero for an invalid offset.
 */
static inline uint32_t sg200x_ll_pinmux_function_get(uint32_t offset)
{
    return sg200x_ll_pinmux_offset_is_valid(offset)
               ? PINMUX->FUNCTION[offset / sizeof(uint32_t)] & PINMUX_FUNCTION_MASK
               : 0U;
}

/**
 * @brief 选择 SD1 专用引脚组 / Select the dedicated SD1 pad bank.
 *
 * @note 清除 TOP SD1_SELECT 的选择位；置位时选择替代 MIPI 通路。
 *       Clear the selector in TOP SD1_SELECT; a set bit selects the alternate MIPI path.
 */
static inline void sg200x_ll_pinmux_select_sd1_pad_bank(void)
{

    TOP->SD1_SELECT &= ~(uint32_t)TOP_SD1_MIPI_SELECT_BIT;
}
