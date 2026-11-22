#pragma once

#include "sg2002.h"
#include <stdbool.h>
#include <stdint.h>

/**
 * @brief SARADC 时钟及参考电压配置 / SARADC clock and reference-voltage configuration.
 */
typedef struct
{
    uint32_t clock_divider; ///< 分频编码 0 至 15，实际分频为编码加一。 Divider encoding zero through fifteen;
                            ///< divisor is encoding plus one.
    bool external_reference; ///< 使用外部 VDD18A 参考电压。 Use external VDD18A reference voltage.
} sg200x_ll_adc_init_t;

/**
 * @brief 按电源域获取 SARADC 实例 / Get a SARADC instance by power domain.
 * @param index 零为主域，一为 RTC 域 / Zero for the main domain; one for the RTC domain.
 * @return 实例指针；无效编号返回空指针 / Instance pointer; null for an invalid index.
 */
static inline SARADC_Type *sg200x_ll_adc_get(uint32_t index)
{
    return index == 0U ? SARADC_REGS : index == 1U ? RTC_SARADC_REGS : NULL;
}

/**
 * @brief 读取 SARADC 转换忙状态 / Read SARADC conversion-busy status.
 * @param adc 主域或 RTC 域 SARADC 实例 / Main-domain or RTC-domain SARADC instance.
 * @return 转换活动时返回 true / True while a conversion is active.
 */
static inline bool sg200x_ll_adc_is_busy(const SARADC_Type *adc)
{
    return (adc->STATUS & SARADC_STATUS_BUSY_BIT) != 0U;
}

/**
 * @brief 读取一个有效的 SARADC 结果 / Read one valid SARADC result.
 * @param adc 主域或 RTC 域 SARADC 实例 / Main-domain or RTC-domain SARADC instance.
 * @param channel 域内物理输入通道，范围 1 至 3。
 *        Physical input channel within the domain, from one through three.
 * @param [out] value 有效时写入 12 位采样值 / Receives the twelve-bit sample when valid.
 * @return 结果有效返回 true；参数或结果无效返回 false，保留输出。
 *        True for a valid result; false with output preserved for invalid parameters or an invalid result.
 * @pre 已等待转换结束；本函数不等待硬件。
 *        Conversion completion has been awaited; this function does not wait for hardware.
 */
static inline bool sg200x_ll_adc_result_read(const SARADC_Type *adc, uint32_t channel, uint16_t *value)
{
    if (adc == NULL || value == NULL || channel == 0U || channel > SARADC_CHANNEL_COUNT)
        return false;
    const uint32_t sample = adc->RESULT[channel - 1U];
    if ((sample & SARADC_RESULT_VALID_BIT) == 0U)
        return false;
    *value = (uint16_t)(sample & SARADC_RESULT_DATA_MASK);
    return true;
}

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @brief 填充 SARADC 默认配置 / Fill SARADC defaults.
     * @param config 接收默认配置，可为空 / Destination for defaults; may be null.
     * @note 默认采用十六分频及内部参考电压 / Defaults select divide-by-sixteen and the internal reference.
     */
    void sg200x_ll_adc_struct_init(sg200x_ll_adc_init_t *config);

    /**
     * @brief 初始化一个空闲 SARADC 实例 / Initialize one idle SARADC instance.
     * @param adc 主域或 RTC 域 SARADC 实例 / Main-domain or RTC-domain SARADC instance.
     * @param config 初始化参数；不保留指针 / Initialization parameters; the pointer is not retained.
     * @return 成功返回 true；配置无效或转换活动时不写寄存器。
     *        True on success; no register writes for invalid configuration or active conversion.
     * @note 保留时序寄存器的保留位；禁止并清除中断，不触发转换。
     *        Preserves reserved timing bits; disables and clears interrupts without starting a conversion.
     */
    bool sg200x_ll_adc_init(SARADC_Type *adc, const sg200x_ll_adc_init_t *config);

    /**
     * @brief 选择物理通道并触发一次转换 / Select a physical channel and trigger one conversion.
     * @param adc 主域或 RTC 域 SARADC 实例 / Main-domain or RTC-domain SARADC instance.
     * @param channel 域内物理输入通道，范围 1 至 3。
     *        Physical input channel within the domain, from one through three.
     * @return 启动成功返回 true；参数无效或忙时不写寄存器。
     *        True when started; no register writes for invalid arguments or a busy ADC.
     * @note 顺序为通道选择、清中断、触发；会清除该通道旧结果的有效位。
     *        Orders channel selection, interrupt clear, and trigger; hardware clears the old result-valid
     *        bit.
     */
    bool sg200x_ll_adc_start(SARADC_Type *adc, uint32_t channel);

    /**
     * @brief 有界等待 SARADC 空闲 / Wait for SARADC idle with a bounded attempt count.
     * @param adc 主域或 RTC 域 SARADC 实例 / Main-domain or RTC-domain SARADC instance.
     * @param attempts 最多轮询次数，零表示不轮询 / Maximum polling attempts; zero performs no polling.
     * @return 观察到空闲返回 true；实例无效或超时返回 false。
     *        True when idle is observed; false for an invalid instance or timeout.
     */
    bool sg200x_ll_adc_wait_idle(const SARADC_Type *adc, uint32_t attempts);

#ifdef __cplusplus
}
#endif
