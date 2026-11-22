#pragma once

#include "sg2002.h"
#include <stdbool.h>
#include <stdint.h>

/**
 * @brief 看门狗指数计数配置 / Watchdog exponential-counter configuration.
 */
typedef struct
{
    uint32_t
        top; ///< 初始及重装超时编码 0 至 15。 Initial and reload timeout encoding from zero through fifteen.
    bool interrupt_first; ///< 第一次超时中断，第二次超时复位。 Interrupt on first timeout, reset on second
                          ///< timeout.
} sg200x_ll_wdt_init_t;

/**
 * @brief 按编号获取主域看门狗 / Get a main-domain watchdog by index.
 * @param index 看门狗编号，0 至 2 / Watchdog index from zero through two.
 * @return 实例指针；无效编号返回空指针 / Instance pointer; null for an invalid index.
 */
static inline WDT_Type *sg200x_ll_wdt_get(uint32_t index)
{
    switch (index)
    {
    case 0U:
        return WDT0_REGS;
    case 1U:
        return WDT1_REGS;
    case 2U:
        return WDT2_REGS;
    default:
        return NULL;
    }
}

/**
 * @brief 检查看门狗是否已使能 / Check whether the watchdog is enabled.
 * @param wdt 主域 WDT0 至 WDT2 寄存器实例 / Main-domain WDT0 through WDT2 register instance.
 * @return 已使能时为 true / True when enabled.
 */
static inline bool sg200x_ll_wdt_is_enabled(const WDT_Type *wdt)
{
    return (wdt->CR & WDT_CR_ENABLE_BIT) != 0U;
}

/**
 * @brief 计算指数模式的超时周期数 / Calculate timeout cycles in exponential mode.
 * @param top 指数超时范围编码，0 至 WDT_TOP_MAX。
 *        Exponential timeout-range encoding, zero through WDT_TOP_MAX.
 * @return 输入时钟周期数 / Input clock cycles.
 * @pre top 不超过 WDT_TOP_MAX / top does not exceed WDT_TOP_MAX.
 */
static inline uint64_t sg200x_ll_wdt_timeout_cycles(uint32_t top)
{
    return 1ULL << (WDT_TIMEOUT_EXPONENT_MIN + top);
}

/**
 * @brief 设置相同的初始和重装超时范围 / Set equal initial and reload timeout ranges.
 * @param wdt 主域 WDT0 至 WDT2 寄存器实例 / Main-domain WDT0 through WDT2 register instance.
 * @param top 指数超时范围编码，0 至 WDT_TOP_MAX。
 *        Exponential timeout-range encoding, zero through WDT_TOP_MAX.
 * @pre top 不超过 WDT_TOP_MAX / top does not exceed WDT_TOP_MAX.
 * @note 正在运行时的新周期在下次喂狗后生效 / A new running timeout takes effect after the next feed.
 */
static inline void sg200x_ll_wdt_timeout_set(WDT_Type *wdt, uint32_t top)
{
    wdt->TORR = top | (top << WDT_TOP_INITIAL_SHIFT);
}

/**
 * @brief 重载看门狗计数器并清除中断 / Reload the watchdog counter and clear its interrupt.
 * @param wdt 主域 WDT0 至 WDT2 寄存器实例 / Main-domain WDT0 through WDT2 register instance.
 * @note 写入硬件规定的重启密钥 / Writes the hardware restart key.
 */
static inline void sg200x_ll_wdt_feed(WDT_Type *wdt) { wdt->CRR = WDT_RESTART_KEY; }

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @brief 填充看门狗默认配置 / Fill watchdog defaults.
     * @param config 接收默认配置，可为空 / Destination for defaults; may be null.
     * @note 默认最短超时编码和直接复位响应。
     *        Defaults select the shortest timeout encoding and immediate-reset response.
     */
    void sg200x_ll_wdt_struct_init(sg200x_ll_wdt_init_t *config);

    /**
     * @brief 配置一个尚未使能的看门狗 / Configure a watchdog that has not been enabled.
     * @param wdt 主域 WDT0 至 WDT2 寄存器实例 / Main-domain WDT0 through WDT2 register instance.
     * @param config 初始化参数；不保留指针 / Initialization parameters; the pointer is not retained.
     * @return 成功返回 true；参数无效或已使能时不写寄存器。
     *        True on success; no register writes for invalid arguments or an enabled watchdog.
     * @note 写入指数计数模式及响应模式，完成后保持未使能。
     *        Programs exponential counting and response mode, leaving the watchdog disabled.
     */
    bool sg200x_ll_wdt_init(WDT_Type *wdt, const sg200x_ll_wdt_init_t *config);

    /**
     * @brief 重载并启动一个尚未使能的看门狗 / Reload and start a watchdog that has not been enabled.
     * @param wdt 主域 WDT0 至 WDT2 寄存器实例 / Main-domain WDT0 through WDT2 register instance.
     * @param top 指数超时范围编码，0 至 WDT_TOP_MAX。
     *        Exponential timeout-range encoding, zero through WDT_TOP_MAX.
     * @param interrupt_first 是否先中断、第二次超时复位。
     *        Whether to interrupt first and reset on the second timeout.
     * @return 启动成功返回 true；无效参数或已使能时不写寄存器。
     *        True when started; no register writes for invalid arguments or an enabled watchdog.
     * @pre 已准备输入时钟和复位路由 / The input clock and reset routing are prepared.
     * @note 依次设置超时、喂狗、使能；一旦启动不能通过清 CR 停止。
     *        Orders timeout selection, feed, and enable; clearing CR cannot stop it after starting.
     */
    bool sg200x_ll_wdt_start(WDT_Type *wdt, uint32_t top, bool interrupt_first);

    /**
     * @brief 为一个看门狗选择 CPU 或系统复位路由 / Select CPU or system reset routing for one watchdog.
     * @param index 主域看门狗编号，0 至 2 / Main-domain watchdog index from zero through two.
     * @param reset_cpu 为 true 选择 CPU 复位，否则选择系统复位。
     *        True selects CPU reset; false selects system reset.
     * @return 成功返回 true；参数无效时不写寄存器并返回 false。
     *        True on success; false without register writes for invalid parameters.
     * @note 保留其他实例路由和共享时钟字段，并沿用 Sophgo 系统控制兼容使能位。
     *        Preserves other instance routes and the shared clock field, retaining the Sophgo system-control
     *        compatibility enable.
     */
    bool sg200x_ll_wdt_reset_route_set(uint32_t index, bool reset_cpu);

#ifdef __cplusplus
}
#endif
