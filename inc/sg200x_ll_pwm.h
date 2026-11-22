#pragma once

#include "sg2002.h"
#include <stdbool.h>
#include <stdint.h>

/**
 * @brief PWM 单通道配置 / PWM single-channel configuration.
 */
typedef struct
{
    uint32_t period_ticks; ///< 总周期计数，范围 2 至 PWM_PERIOD_MAX。 Total period, from two through
                           ///< PWM_PERIOD_MAX.
    uint32_t inactive_ticks; ///< 非有效电平计数，范围 1 至 period_ticks-1。 Inactive-level count from one
                             ///< through period_ticks-1.
    bool active_high; ///< 有效高电平极性。 Active-high polarity.
} sg200x_ll_pwm_init_t;

/**
 * @brief 获取 PWM 控制器 / Get a PWM controller.
 * @param index 控制器编号，范围 0 至 3 / Controller index from zero through three.
 * @return 实例指针；无效编号返回空指针 / Instance pointer; null for an invalid index.
 */
static inline PWM_Type *sg200x_ll_pwm_get(uint32_t index)
{
    switch (index)
    {
    case 0U:
        return PWM0_REGS;
    case 1U:
        return PWM1_REGS;
    case 2U:
        return PWM2_REGS;
    case 3U:
        return PWM3_REGS;
    default:
        return NULL;
    }
}

/**
 * @brief 设置选定通道的输出极性 / Set output polarity for selected channels.
 * @param pwm PWM 寄存器实例 / PWM register instance.
 * @param channels 控制器内通道掩码，仅低四位有效。
 *        Channel mask within the controller; only the low four bits are valid.
 * @param active_high 是否使用有效高电平 / Whether to use active-high polarity.
 * @pre 通道已停止且 channels 为有效掩码 / Channels are stopped and channels is a valid mask.
 */
static inline void sg200x_ll_pwm_polarity_set(PWM_Type *pwm, uint32_t channels, bool active_high)
{
    const uint32_t value = pwm->POLARITY;
    pwm->POLARITY = active_high ? value & ~channels : value | channels;
}

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @brief 填充 PWM 默认配置 / Fill PWM defaults.
     * @param config 接收默认配置，可为空 / Destination for defaults; may be null.
     * @note 默认周期 2、非有效电平 1、有效高电平。
     *        Defaults are period two, inactive count one, and active-high polarity.
     */
    void sg200x_ll_pwm_struct_init(sg200x_ll_pwm_init_t *config);

    /**
     * @brief 初始化一个已停止的 PWM 通道 / Initialize one stopped PWM channel.
     * @param pwm PWM 寄存器实例 / PWM register instance.
     * @param channel 控制器内通道编号，范围 0 至 3。
     *        Channel index within the controller, from zero through three.
     * @param config 初始化参数；不保留指针 / Initialization parameters; the pointer is not retained.
     * @return 成功返回 true；无效配置或通道仍输出时不写寄存器。
     *        True on success; no register writes for invalid configuration or a channel still producing
     *        output.
     * @note 保持其他通道和共享模式位；成功后仍未使能输出。
     *        Preserves other channels and shared mode bits; output remains disabled on success.
     */
    bool sg200x_ll_pwm_init(PWM_Type *pwm, uint32_t channel, const sg200x_ll_pwm_init_t *config);

    /**
     * @brief 写入单通道周期和非有效电平计数 / Write a channel period and inactive-level count.
     * @param pwm PWM 寄存器实例 / PWM register instance.
     * @param channel 控制器内通道编号，范围 0 至 3。
     *        Channel index within the controller, from zero through three.
     * @param period_ticks 完整周期计数，范围 2 至 PWM_PERIOD_MAX。
     *        Full period count from two through PWM_PERIOD_MAX.
     * @param inactive_ticks 非有效电平计数，大于零且小于完整周期。
     *        Inactive-level count greater than zero and below the full period.
     * @return 成功返回 true；参数无效时不写寄存器并返回 false。
     *        True on success; false without register writes for invalid parameters.
     * @note 先写 HLPERIOD 再写 PERIOD；运行中需随后调用 update。
     *        Writes HLPERIOD before PERIOD; call update afterward when running.
     */
    bool
    sg200x_ll_pwm_period_set(PWM_Type *pwm, uint32_t channel, uint32_t period_ticks, uint32_t inactive_ticks);

    /**
     * @brief 用置位再清零脉冲提交动态周期更新 / Commit a dynamic period update with a set-then-clear pulse.
     * @param pwm PWM 寄存器实例 / PWM register instance.
     * @param channels 控制器内通道掩码，仅低四位有效。
     *        Channel mask within the controller; only the low four bits are valid.
     * @return 成功返回 true；参数无效时不写寄存器并返回 false。
     *        True on success; false without register writes for invalid parameters.
     * @note I/O 屏障确保周期写入和更新脉冲有序 / I/O fences order period writes and the update pulse.
     */
    bool sg200x_ll_pwm_update(PWM_Type *pwm, uint32_t channels);

    /**
     * @brief 配置极性并启动 PWM 输出 / Configure polarity and start PWM output.
     * @param pwm PWM 寄存器实例 / PWM register instance.
     * @param channels 控制器内通道掩码，仅低四位有效。
     *        Channel mask within the controller; only the low four bits are valid.
     * @param active_high 有效高电平极性 / Active-high polarity.
     * @return 成功返回 true；参数无效时不写寄存器并返回 false。
     *        True on success; false without register writes for invalid parameters.
     * @pre 已配置有效周期；调用者管理 PWM 模式及引脚。
     *        A valid period is configured; the caller manages PWM mode and pins.
     * @note 按极性、START 清零、OE 置位、START 置位的顺序执行。
     *        Orders polarity, START clear, OE set, and START set.
     */
    bool sg200x_ll_pwm_start(PWM_Type *pwm, uint32_t channels, bool active_high);

    /**
     * @brief 先禁止输出，再停止 PWM 计数 / Disable output before stopping PWM counting.
     * @param pwm PWM 寄存器实例 / PWM register instance.
     * @param channels 控制器内通道掩码，仅低四位有效。
     *        Channel mask within the controller; only the low four bits are valid.
     * @return 成功返回 true；参数无效时不写寄存器并返回 false。
     *        True on success; false without register writes for invalid parameters.
     */
    bool sg200x_ll_pwm_stop(PWM_Type *pwm, uint32_t channels);

#ifdef __cplusplus
}
#endif
