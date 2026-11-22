#pragma once

#include "sg2002.h"
#include <stdbool.h>
#include <stdint.h>

/**
 * @brief 按编号获取主域 GPIO0 至 GPIO3 / Get main-domain GPIO0 through GPIO3 by index.
 * @param index 主域控制器编号 / Main-domain controller index.
 * @return 实例指针；编号无效返回空指针 / Instance pointer, or null for an invalid index.
 */
static inline GPIO_Type *sg200x_ll_gpio_get(uint32_t index)
{
    switch (index)
    {
    case 0U:
        return GPIO0_REGS;
    case 1U:
        return GPIO1_REGS;
    case 2U:
        return GPIO2_REGS;
    case 3U:
        return GPIO3_REGS;
    default:
        return NULL;
    }
}

/**
 * @brief 查询主域 GPIO 实例编号 / Look up a main-domain GPIO instance index.
 * @param gpio GPIO 寄存器实例，支持主域和 RTC 域 / GPIO register instance in the main or RTC domain.
 * @return 主域编号；RTC 或未知实例返回 GPIO_COUNT。
 *        Main-domain index; GPIO_COUNT for RTC or unknown instances.
 */
static inline uint32_t sg200x_ll_gpio_index_get(const GPIO_Type *gpio)
{
    if (gpio == GPIO0_REGS)
        return 0U;
    if (gpio == GPIO1_REGS)
        return 1U;
    if (gpio == GPIO2_REGS)
        return 2U;
    if (gpio == GPIO3_REGS)
        return 3U;
    return GPIO_COUNT;
}

/**
 * @brief 读取 GPIO 引脚输入电平 / Read GPIO pin input levels.
 * @param gpio GPIO 寄存器实例，支持主域和 RTC 域 / GPIO register instance in the main or RTC domain.
 * @return 端口位掩码 / Port bit mask.
 */
static inline uint32_t sg200x_ll_gpio_input_get(const GPIO_Type *gpio) { return gpio->EXT_PORTA; }

/**
 * @brief 读取 GPIO 输出锁存值 / Read the GPIO output latch.
 * @param gpio GPIO 寄存器实例，支持主域和 RTC 域 / GPIO register instance in the main or RTC domain.
 * @return 端口位掩码 / Port bit mask.
 */
static inline uint32_t sg200x_ll_gpio_output_get(const GPIO_Type *gpio) { return gpio->SWPORTA_DR; }

/**
 * @brief 读取屏蔽后的 GPIO 中断状态 / Read masked GPIO interrupt status.
 * @param gpio GPIO 寄存器实例，支持主域和 RTC 域 / GPIO register instance in the main or RTC domain.
 * @return 端口位掩码 / Port bit mask.
 */
static inline uint32_t sg200x_ll_gpio_interrupt_status_get(const GPIO_Type *gpio) { return gpio->INTSTATUS; }

/**
 * @brief 设置选定引脚的输出锁存电平 / Set the output latch level of selected pins.
 * @param gpio GPIO 寄存器实例，支持主域和 RTC 域 / GPIO register instance in the main or RTC domain.
 * @param pins 端口内的引脚位掩码 / Pin mask within the port.
 * @param high 写入高电平或低电平 / Write a high or low level.
 * @pre 调用者独占选定引脚，并串行化同一端口的读改写。
 *        The caller owns the selected pins and serializes read-modify-write on the port.
 */
static inline void sg200x_ll_gpio_output_write(GPIO_Type *gpio, uint32_t pins, bool high)
{
    const uint32_t current = gpio->SWPORTA_DR;
    gpio->SWPORTA_DR = high ? current | pins : current & ~pins;
}

/**
 * @brief 设置选定引脚的输入或输出方向 / Set selected pins to output or input.
 * @param gpio GPIO 寄存器实例，支持主域和 RTC 域 / GPIO register instance in the main or RTC domain.
 * @param pins 端口内的引脚位掩码 / Pin mask within the port.
 * @param enable 是否使能指定功能 / Whether to enable the selected function.
 * @pre 调用者独占选定引脚，并串行化同一端口的读改写。
 *        The caller owns the selected pins and serializes read-modify-write on the port.
 */
static inline void sg200x_ll_gpio_output_enable(GPIO_Type *gpio, uint32_t pins, bool enable)
{
    const uint32_t current = gpio->SWPORTA_DDR;
    gpio->SWPORTA_DDR = enable ? current | pins : current & ~pins;
}

/**
 * @brief 使能或禁止选定引脚的中断源 / Enable or disable selected pin interrupt sources.
 * @param gpio GPIO 寄存器实例，支持主域和 RTC 域 / GPIO register instance in the main or RTC domain.
 * @param pins 端口内的引脚位掩码 / Pin mask within the port.
 * @param enable 是否使能指定功能 / Whether to enable the selected function.
 * @pre 调用者独占选定引脚，并串行化同一端口的读改写。
 *        The caller owns the selected pins and serializes read-modify-write on the port.
 */
static inline void sg200x_ll_gpio_interrupt_enable(GPIO_Type *gpio, uint32_t pins, bool enable)
{
    const uint32_t current = gpio->INTEN;
    gpio->INTEN = enable ? current | pins : current & ~pins;
}

/**
 * @brief 屏蔽或取消屏蔽选定引脚中断 / Mask or unmask selected pin interrupts.
 * @param gpio GPIO 寄存器实例，支持主域和 RTC 域 / GPIO register instance in the main or RTC domain.
 * @param pins 端口内的引脚位掩码 / Pin mask within the port.
 * @param masked 为 true 时屏蔽 / True to mask.
 * @pre 调用者独占选定引脚，并串行化同一端口的读改写。
 *        The caller owns the selected pins and serializes read-modify-write on the port.
 */
static inline void sg200x_ll_gpio_interrupt_mask(GPIO_Type *gpio, uint32_t pins, bool masked)
{
    const uint32_t current = gpio->INTMASK;
    gpio->INTMASK = masked ? current | pins : current & ~pins;
}

/**
 * @brief 设置边沿或电平触发 / Select edge or level triggering.
 * @param gpio GPIO 寄存器实例，支持主域和 RTC 域 / GPIO register instance in the main or RTC domain.
 * @param pins 端口内的引脚位掩码 / Pin mask within the port.
 * @param edge 为 true 时边沿触发，为 false 时电平触发 / True for edge triggering; false for level triggering.
 * @pre 调用者独占选定引脚，并串行化同一端口的读改写。
 *        The caller owns the selected pins and serializes read-modify-write on the port.
 */
static inline void sg200x_ll_gpio_interrupt_edge_set(GPIO_Type *gpio, uint32_t pins, bool edge)
{
    const uint32_t current = gpio->INTTYPE_LEVEL;
    gpio->INTTYPE_LEVEL = edge ? current | pins : current & ~pins;
}

/**
 * @brief 选择高电平或上升沿触发极性 / Select high-level or rising-edge interrupt polarity.
 * @param gpio GPIO 寄存器实例，支持主域和 RTC 域 / GPIO register instance in the main or RTC domain.
 * @param pins 端口内的引脚位掩码 / Pin mask within the port.
 * @param active_high 为 false 时选择低电平或下降沿 / False selects low-level or falling-edge triggering.
 * @pre 调用者独占选定引脚，并串行化同一端口的读改写。
 *        The caller owns the selected pins and serializes read-modify-write on the port.
 */
static inline void sg200x_ll_gpio_interrupt_polarity_set(GPIO_Type *gpio, uint32_t pins, bool active_high)
{
    const uint32_t current = gpio->INT_POLARITY;
    gpio->INT_POLARITY = active_high ? current | pins : current & ~pins;
}

/**
 * @brief 清除选定 GPIO 引脚的中断 / Clear interrupts on selected GPIO pins.
 * @param gpio GPIO 寄存器实例，支持主域和 RTC 域 / GPIO register instance in the main or RTC domain.
 * @param pins 端口内的引脚位掩码 / Pin mask within the port.
 * @note 直接写 PORTA_EOI，不对清除寄存器做读改写。
 *        Writes PORTA_EOI directly without read-modify-write on the clear register.
 */
static inline void sg200x_ll_gpio_interrupt_clear(GPIO_Type *gpio, uint32_t pins) { gpio->PORTA_EOI = pins; }
