#pragma once

#include <stdint.h>

/**
 * @brief 构造本机 unsigned long 类型的单比特掩码 / Build a single-bit mask of native unsigned long type.
 *
 * @param n 零起始位号，必须小于 unsigned long 的位宽 / Zero-based bit index below the width of unsigned long.
 * @return 仅位 n 置位的掩码 / Mask with only bit n set.
 */
#define LL_BIT(n) (1UL << (n))
/**
 * @brief 构造 32 位连续字段掩码 / Build a contiguous 32-bit field mask.
 *
 * @param shift 字段最低有效位位置，小于 32 / Least-significant field-bit position, below 32.
 * @param width 字段位数，不大于 32 - shift / Field bit count, no greater than 32 - shift.
 * @return 指定字段的掩码 / Mask of the selected field.
 */
#define LL_MASK(shift, width) ((uint32_t)((((uint64_t)1U << (width)) - 1U) << (shift)))

/**
 * @brief 从 32 位数值中提取位字段 / Extract a bit field from a 32-bit value.
 *
 * @param value 待提取字段的原始 32 位数值 / Original 32-bit value containing the field.
 * @param shift 字段最低有效位的零起始位置 / Zero-based position of the field's least-significant bit.
 * @param width 字段位数，且 shift + width 不超过 32 / Field bit count; shift plus width must not exceed 32.
 * @return 右对齐的字段值 / Right-aligned field value.
 * @pre shift 小于 32，width 不大于 32 - shift；调用者负责范围有效性。
 *      shift must be below 32 and width no greater than 32 - shift; the caller validates ranges.
 * @note 仅进行数值运算，不读取或写入寄存器 / Perform value operations only; no registers are read or written.
 */
static inline uint32_t sg200x_ll_field_get(uint32_t value, uint32_t shift, uint32_t width)
{
    return (value >> shift) & (uint32_t)(((uint64_t)1U << width) - 1U);
}

/**
 * @brief 替换 32 位数值中的指定位字段 / Replace a selected bit field in a 32-bit value.
 *
 * @param reg_value 待替换字段的原始 32 位数值 / Original 32-bit value whose field is replaced.
 * @param shift 字段最低有效位的零起始位置 / Zero-based position of the field's least-significant bit.
 * @param width 字段位数，且 shift + width 不超过 32 / Field bit count; shift plus width must not exceed 32.
 * @param field_value 右对齐的新字段值 / New right-aligned field value.
 * @return 替换后的数值，字段外的位保持不变 / Updated value with bits outside the field preserved.
 * @pre shift 小于 32，width 不大于 32 - shift；调用者负责范围有效性。
 *      shift must be below 32 and width no greater than 32 - shift; the caller validates ranges.
 * @note 仅进行数值运算，不读取或写入寄存器 / Perform value operations only; no registers are read or written.
 * @note field_value 超出字段宽度的高位会被截断。
 *       High bits of field_value outside the field width are discarded.
 */
static inline uint32_t
sg200x_ll_field_prepare(uint32_t reg_value, uint32_t shift, uint32_t width, uint32_t field_value)
{
    const uint32_t mask = LL_MASK(shift, width);
    return (reg_value & ~mask) | ((field_value << shift) & mask);
}
