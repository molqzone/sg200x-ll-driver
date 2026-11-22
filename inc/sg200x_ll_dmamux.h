#pragma once

#include <stdbool.h>
#include <stdint.h>

#include "sg2002.h"
#include "sg200x_ll_utils.h"

/**
 * @brief 读取指定 CPU 的 TOP DMA 中断路由字段 / Read one CPU's TOP DMA interrupt-route field.
 *
 * @param cpu CPU 路由编号，范围为 0 到 2 / CPU route index from 0 through 2.
 * @return 该 CPU 的 9 位路由字段 / The CPU's nine-bit routing field.
 * @pre cpu 必须为 0、1 或 2；该原语不报告无效 CPU 编号。
 *      cpu must be 0, 1, or 2; this primitive does not report invalid CPU indices.
 */
static inline uint32_t sg200x_ll_dmamux_interrupt_route_get(uint32_t cpu)
{
    const uint32_t shift = cpu == 0U   ? TOP_DMA_INTERRUPT_CPU0_SHIFT
                           : cpu == 1U ? TOP_DMA_INTERRUPT_CPU1_SHIFT
                                       : TOP_DMA_INTERRUPT_CPU2_SHIFT;
    return (TOP->DMA_INTERRUPT_MUX >> shift) & TOP_DMA_INTERRUPT_FIELD_MASK;
}

/**
 * @brief 替换指定 CPU 的 TOP DMA 中断路由字段 / Replace one CPU's TOP DMA interrupt-route field.
 *
 * @param cpu CPU 路由编号，范围为 0 到 2 / CPU route index from 0 through 2.
 * @param channels 当前 CPU 的路由位掩码，仅低 9 位写入。
 *        Routing mask for this CPU; only the low nine bits are written.
 * @pre cpu 必须为 0、1 或 2；该原语不报告无效 CPU 编号。
 *      cpu must be 0, 1, or 2; this primitive does not report invalid CPU indices.
 * @note 保留其他 CPU 的字段；当前 CPU 字段整体替换，调用者须保留其中不归自己管理的通道。
 *       Other CPUs' fields are preserved; the selected field is replaced in full, so retain channels owned by
 *       other users.
 */
static inline void sg200x_ll_dmamux_interrupt_route_set(uint32_t cpu, uint32_t channels)
{
    const uint32_t shift = cpu == 0U   ? TOP_DMA_INTERRUPT_CPU0_SHIFT
                           : cpu == 1U ? TOP_DMA_INTERRUPT_CPU1_SHIFT
                                       : TOP_DMA_INTERRUPT_CPU2_SHIFT;
    uint32_t value = TOP->DMA_INTERRUPT_MUX;
    value = (value & ~(TOP_DMA_INTERRUPT_FIELD_MASK << shift)) |
            ((channels & TOP_DMA_INTERRUPT_FIELD_MASK) << shift);
    TOP->DMA_INTERRUPT_MUX = value;
}

/**
 * @brief 查询 SPI 实例对应的 DMA 请求编号 / Look up the DMA request number for a SPI instance.
 * @param index 主域外设实例编号 / Main-domain peripheral instance index.
 * @param transmit 为 true 选择发送请求，否则选择接收请求 / True selects transmit; false selects receive.
 * @return 请求编号；无效实例返回 DMA_REQUEST_NONE / Request number; DMA_REQUEST_NONE for an invalid instance.
 */
static inline uint32_t sg200x_ll_dmamux_spi_request_get(uint32_t index, bool transmit)
{
    switch (index)
    {
    case 0U:
        return transmit ? DMA_REQUEST_SPI0_TX : DMA_REQUEST_SPI0_RX;
    case 1U:
        return transmit ? DMA_REQUEST_SPI1_TX : DMA_REQUEST_SPI1_RX;
    case 2U:
        return transmit ? DMA_REQUEST_SPI2_TX : DMA_REQUEST_SPI2_RX;
    case 3U:
        return transmit ? DMA_REQUEST_SPI3_TX : DMA_REQUEST_SPI3_RX;
    default:
        return DMA_REQUEST_NONE;
    }
}

/**
 * @brief 查询 I2C 实例对应的 DMA 请求编号 / Look up the DMA request number for a I2C instance.
 * @param index 主域外设实例编号 / Main-domain peripheral instance index.
 * @param transmit 为 true 选择发送请求，否则选择接收请求 / True selects transmit; false selects receive.
 * @return 请求编号；无效实例返回 DMA_REQUEST_NONE / Request number; DMA_REQUEST_NONE for an invalid instance.
 */
static inline uint32_t sg200x_ll_dmamux_i2c_request_get(uint32_t index, bool transmit)
{
    switch (index)
    {
    case 0U:
        return transmit ? DMA_REQUEST_I2C0_TX : DMA_REQUEST_I2C0_RX;
    case 1U:
        return transmit ? DMA_REQUEST_I2C1_TX : DMA_REQUEST_I2C1_RX;
    case 2U:
        return transmit ? DMA_REQUEST_I2C2_TX : DMA_REQUEST_I2C2_RX;
    case 3U:
        return transmit ? DMA_REQUEST_I2C3_TX : DMA_REQUEST_I2C3_RX;
    case 4U:
        return transmit ? DMA_REQUEST_I2C4_TX : DMA_REQUEST_I2C4_RX;
    default:
        return DMA_REQUEST_NONE;
    }
}
