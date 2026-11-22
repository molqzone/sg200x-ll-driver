#pragma once

#include <stdbool.h>
#include <stdint.h>

#include "sg2002.h"
#include "sg200x_ll_utils.h"

/**
 * @brief 已停止 I2C 主机的初始化参数 / Initialization parameters for a stopped I2C master.
 */
typedef struct
{
    uint32_t speed;          ///< STANDARD 或 FAST 主机速率模式。 STANDARD or FAST master speed mode.
    uint32_t target_address; ///< 符合所选 7/10 位模式的目标地址。 Target address fitting the selected
                             ///< seven-/ten-bit mode.
    bool ten_bit_addressing; ///< 使能 10 位地址模式。 Enable ten-bit addressing.
    bool restart_enable;     ///< 使能重复起始条件。 Enable repeated-start conditions.
    uint32_t tx_fifo_threshold; ///< 发送 FIFO 原始阈值，范围为 0 到 63。 Raw transmit FIFO threshold from 0
                                ///< through 63.
    uint32_t rx_fifo_threshold; ///< 接收 FIFO 原始阈值，范围为 0 到 63。 Raw receive FIFO threshold from 0
                                ///< through 63.
    uint32_t dma_tx_level; ///< 发送 DMA 请求阈值，范围为 0 到 63。 Transmit DMA request threshold from 0
                           ///< through 63.
    uint32_t dma_rx_level; ///< 接收 DMA 请求阈值，范围为 0 到 63。 Receive DMA request threshold from 0
                           ///< through 63.
} sg200x_ll_i2c_init_t;

/**
 * @brief I2C 寄存器时序计数 / I2C register timing counts.
 */
typedef struct
{
    uint32_t standard_high; ///< 标准模式 SCL 高电平计数。 Standard-mode SCL high count.
    uint32_t standard_low;  ///< 标准模式 SCL 低电平计数。 Standard-mode SCL low count.
    uint32_t fast_high;     ///< 快速模式 SCL 高电平计数。 Fast-mode SCL high count.
    uint32_t fast_low;      ///< 快速模式 SCL 低电平计数。 Fast-mode SCL low count.
    uint32_t sda_hold;      ///< SDA 发送保持计数。 SDA transmit-hold count.
    uint32_t sda_setup;     ///< SDA 建立计数。 SDA setup count.
    uint32_t spike_length;  ///< SCL 毛刺抑制计数。 SCL spike-suppression count.
} sg200x_ll_i2c_timing_t;

#ifdef __cplusplus
extern "C"
{
#endif
    /**
     * @brief 填充 I2C 主机默认初始化参数 / Fill default I2C master initialization parameters.
     *
     * @param[out] config 接收默认配置的结构体指针，可为空。
     *        Destination for default configuration; may be null.
     * @note 空指针不执行操作。默认标准模式、7 位地址及重复起始，FIFO/DMA 阈值为 0。
     *       A null pointer is ignored. Defaults select standard mode, seven-bit addressing and restart, with
     *       zero FIFO/DMA thresholds.
     */
    void sg200x_ll_i2c_struct_init(sg200x_ll_i2c_init_t *config);

    /**
     * @brief 按 TRM 时序配置一个已停止的 I2C 主机 / Configure a stopped I2C master using TRM timing profiles.
     *
     * @param i2c I2C 寄存器实例 / I2C register instance.
     * @param[in] config 调用者提供的初始化配置 / Caller-provided initialization configuration.
     * @param peripheral_clock_hz 实际外设输入时钟频率，单位为 Hz。
     *        Actual peripheral input clock frequency in Hz.
     * @return 成功返回 true；参数或状态不满足要求时不写寄存器并返回 false。
     *         True on success; false without register writes when arguments or state are unsuitable.
     * @note 仅接受 I2C0-4 和 25/100 MHz 输入时钟；ENABLE 与 ENABLE_STATUS 都必须为 0。
     *       Only I2C0-4 and 25/100 MHz input clocks are accepted; both ENABLE and ENABLE_STATUS must be zero.
     * @note 调用者管理时钟、引脚和 DMA。成功后控制器、中断及 DMA 请求保持关闭。
     *       The caller manages clocks, pins, and DMA. The controller, interrupts, and DMA requests remain
     *       disabled on success.
     */
    bool sg200x_ll_i2c_init(I2C_Type *i2c, const sg200x_ll_i2c_init_t *config, uint32_t peripheral_clock_hz);

    /**
     * @brief 复位一个已停止的 I2C 实例 / Reset one stopped I2C instance.
     *
     * @param i2c I2C 寄存器实例 / I2C register instance.
     * @return 成功返回 true；实例无效或尚未停止时返回 false。
     *         True on success; false for an invalid instance or incomplete disable.
     * @note 先停止相关 DMA 并确认禁用完成；仅脉冲此实例的复位位。
     *       Stop associated DMA and confirm disable completion first; only this instance's reset is pulsed.
     */
    bool sg200x_ll_i2c_deinit(I2C_Type *i2c);
#ifdef __cplusplus
}
#endif

/**
 * @brief 按编号获取 I2C0 至 I2C4 / Get I2C0 through I2C4 by index.
 *
 * @param index 实例编号，范围为 0 到 4 / Instance index from 0 through 4.
 * @return 实例指针；编号无效时返回空指针 / Instance pointer, or null for an invalid index.
 */
static inline I2C_Type *sg200x_ll_i2c_get(uint32_t index)
{
    switch (index)
    {
    case 0U:
        return I2C0_REGS;
    case 1U:
        return I2C1_REGS;
    case 2U:
        return I2C2_REGS;
    case 3U:
        return I2C3_REGS;
    case 4U:
        return I2C4_REGS;
    default:
        return (I2C_Type *)0;
    }
}

/**
 * @brief 编码 I2C CON 配置字段 / Encode I2C CON configuration fields.
 *
 * @param master 是否使能主机模式 / Whether to enable master mode.
 * @param speed I2C 速率模式编码 / I2C speed-mode encoding.
 * @param master_10bit 是否使用主机 10 位地址模式 / Whether to use master ten-bit addressing.
 * @param restart 是否设置重复起始功能或命令位 / Whether to set restart enable or the restart command bit.
 * @param slave_disable 是否禁止从机功能 / Whether to disable slave functionality.
 * @return 可写入 CON 的配置值 / Configuration value to write to CON.
 */
static inline uint32_t
sg200x_ll_i2c_con_build(bool master, uint32_t speed, bool master_10bit, bool restart, bool slave_disable)
{
    uint32_t value = (speed << I2C_CON_SPEED_SHIFT) & I2C_CON_SPEED_MASK;
    if (master)
        value |= I2C_CON_MASTER_BIT;
    if (master_10bit)
        value |= I2C_CON_MASTER_10BIT_BIT;
    if (restart)
        value |= I2C_CON_RESTART_ENABLE_BIT;
    if (slave_disable)
        value |= I2C_CON_SLAVE_DISABLE_BIT;
    return value;
}

/**
 * @brief 写入 I2C CON 配置寄存器 / Write the I2C CON configuration register.
 *
 * @param i2c I2C 寄存器实例 / I2C register instance.
 * @param value 要写入或编码的数值 / Value to write or encode.
 * @pre 修改 CON 前必须禁止控制器 / Disable the controller before modifying CON.
 */
static inline void sg200x_ll_i2c_con_set(I2C_Type *i2c, uint32_t value) { i2c->CON = value; }

/**
 * @brief 设置 I2C 目标地址及 10 位地址选择位 / Set the I2C target address and ten-bit address selector.
 *
 * @param i2c I2C 寄存器实例 / I2C register instance.
 * @param address 目标从机地址，低 10 位写入 TAR / Target slave address; the low ten bits are written to TAR.
 * @param ten_bit 是否设置 TAR 的 10 位地址选择位 / Whether to set the TAR ten-bit address selector.
 * @pre 控制器处于允许修改 TAR 的空闲状态；地址应符合所选的 7/10 位模式。
 *      The controller must be idle in a state that permits TAR changes; the address must fit the selected
 *      seven-/ten-bit mode.
 * @note 本函数只写 TAR；CON 的主机 10 位模式需要单独配置。
 *       This function writes TAR only; configure the CON master ten-bit mode separately.
 */
static inline void sg200x_ll_i2c_target_set(I2C_Type *i2c, uint16_t address, bool ten_bit)
{
    i2c->TAR = ((uint32_t)address & I2C_TAR_ADDRESS_MASK) | (ten_bit ? I2C_TAR_10BIT_BIT : 0U);
}

/**
 * @brief 构造一个 I2C DATA_CMD 命令字 / Build an I2C DATA_CMD command word.
 *
 * @param data 命令中的低 8 位数据；读命令时数据字段不用于发送。
 *        Low eight data bits; the data field is not transmitted for a read command.
 * @param read 为 true 时构造读请求 / True to build a read request.
 * @param stop 是否在该命令结束后生成 STOP / Whether to generate STOP after this command.
 * @param restart 是否设置重复起始功能或命令位 / Whether to set restart enable or the restart command bit.
 * @return 包含数据、读请求、STOP 和 RESTART 位的命令。
 *         Command containing data, read-request, STOP, and RESTART bits.
 */
static inline uint32_t sg200x_ll_i2c_data_command_build(uint8_t data, bool read, bool stop, bool restart)
{
    return ((uint32_t)data & I2C_DATA_CMD_DATA_MASK) | (read ? I2C_DATA_CMD_READ_BIT : 0U) |
           (stop ? I2C_DATA_CMD_STOP_BIT : 0U) | (restart ? I2C_DATA_CMD_RESTART_BIT : 0U);
}

/**
 * @brief 向 I2C 发送 FIFO 提交 DATA_CMD 命令 / Submit a DATA_CMD command to the I2C transmit FIFO.
 *
 * @param i2c I2C 寄存器实例 / I2C register instance.
 * @param command 由 DATA_CMD 构造器生成的命令字 / Command word produced by the DATA_CMD builder.
 * @pre 调用者确认发送 FIFO 有空间 / The caller must ensure that the transmit FIFO has space.
 */
static inline void sg200x_ll_i2c_data_command_write(I2C_Type *i2c, uint32_t command)
{
    i2c->DATA_CMD = command;
}

/**
 * @brief 读取屏蔽前的 I2C 中断状态 / Read unmasked I2C interrupt status.
 *
 * @param i2c I2C 寄存器实例 / I2C register instance.
 * @return RAW_INTR_STAT 的当前值 / Current RAW_INTR_STAT value.
 */
static inline uint32_t sg200x_ll_i2c_raw_interrupt_status_get(const I2C_Type *i2c)
{
    return i2c->RAW_INTR_STAT;
}

/**
 * @brief 读取屏蔽后的 I2C 中断状态 / Read masked I2C interrupt status.
 *
 * @param i2c I2C 寄存器实例 / I2C register instance.
 * @return INTR_STAT 的当前值 / Current INTR_STAT value.
 */
static inline uint32_t sg200x_ll_i2c_interrupt_status_get(const I2C_Type *i2c) { return i2c->INTR_STAT; }

/**
 * @brief 通过读 CLR_INTR 清除 I2C 中断 / Clear I2C interrupts by reading CLR_INTR.
 *
 * @param i2c I2C 寄存器实例 / I2C register instance.
 * @return 清除寄存器读回值 / Value read from the clear register.
 */
static inline uint32_t sg200x_ll_i2c_interrupt_clear(I2C_Type *i2c) { return i2c->CLR_INTR; }

/**
 * @brief 写入 I2C 中断使能掩码 / Write the I2C interrupt-enable mask.
 *
 * @param i2c I2C 寄存器实例 / I2C register instance.
 * @param mask 写入 INTR_MASK 的中断使能位掩码 / Interrupt-enable mask written to INTR_MASK.
 */
static inline void sg200x_ll_i2c_interrupt_mask_set(I2C_Type *i2c, uint32_t mask) { i2c->INTR_MASK = mask; }

/**
 * @brief 请求使能或禁止 I2C 控制器 / Request enable or disable of the I2C controller.
 *
 * @param i2c I2C 寄存器实例 / I2C register instance.
 * @param enable 为 true 时使能，为 false 时禁止 / True to enable; false to disable.
 * @note 禁止请求可能延迟完成；继续配置或复位前读取 ENABLE_STATUS 确认。
 *       Disable completion may be delayed; check ENABLE_STATUS before further configuration or reset.
 */
static inline void sg200x_ll_i2c_enable(I2C_Type *i2c, bool enable)
{
    i2c->ENABLE = enable ? I2C_ENABLE_BIT : 0U;
}

/**
 * @brief 读取 I2C 控制器的实际使能状态 / Read the I2C controller's actual enable state.
 *
 * @param i2c I2C 寄存器实例 / I2C register instance.
 * @return ENABLE_STATUS 的使能位为 1 时返回 true / True when the enable bit in ENABLE_STATUS is set.
 */
static inline bool sg200x_ll_i2c_is_enabled(const I2C_Type *i2c)
{
    return (i2c->ENABLE_STATUS & I2C_ENABLE_STATUS_BIT) != 0U;
}

/**
 * @brief 读取 I2C 发送 FIFO 的条目数 / Read the number of entries in the I2C transmit FIFO.
 *
 * @param i2c I2C 寄存器实例 / I2C register instance.
 * @return TXFLR 中的条目数 / Entry count reported by TXFLR.
 */
static inline uint32_t sg200x_ll_i2c_tx_fifo_level_get(const I2C_Type *i2c) { return i2c->TXFLR; }

/**
 * @brief 读取 I2C 接收 FIFO 的条目数 / Read the number of entries in the I2C receive FIFO.
 *
 * @param i2c I2C 寄存器实例 / I2C register instance.
 * @return RXFLR 中的条目数 / Entry count reported by RXFLR.
 */
static inline uint32_t sg200x_ll_i2c_rx_fifo_level_get(const I2C_Type *i2c) { return i2c->RXFLR; }

/**
 * @brief 配置 I2C 的接收和发送 DMA 请求 / Configure I2C receive and transmit DMA requests.
 *
 * @param i2c I2C 寄存器实例 / I2C register instance.
 * @param receive 接收 DMA 请求使能状态 / Receive DMA request-enable state.
 * @param transmit 发送 DMA 请求使能状态 / Transmit DMA request-enable state.
 * @note 仅修改外设请求位，不申请、配置或启动 DMA 通道。
 *       Only peripheral request bits change; DMA channels are not acquired, configured, or started.
 */
static inline void sg200x_ll_i2c_dma_enable(I2C_Type *i2c, bool receive, bool transmit)
{
    i2c->DMA_CR = (receive ? I2C_DMA_RX_ENABLE_BIT : 0U) | (transmit ? I2C_DMA_TX_ENABLE_BIT : 0U);
}

/**
 * @brief 关闭 I2C 的接收和发送 DMA 请求 / Disable I2C receive and transmit DMA requests.
 *
 * @param i2c I2C 寄存器实例 / I2C register instance.
 * @note 仅修改外设请求位，不申请、配置或启动 DMA 通道。
 *       Only peripheral request bits change; DMA channels are not acquired, configured, or started.
 */
static inline void sg200x_ll_i2c_dma_disable(I2C_Type *i2c) { i2c->DMA_CR = 0U; }

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @brief 由输入时钟计算标准及快速模式时序。
     *        Calculate standard- and fast-mode timing from the input clock.
     * @param peripheral_clock_hz 实际 I2C 输入时钟，单位 Hz / Actual I2C input clock in Hz.
     * @param [out] timing 接收时序计算结果 / Receives calculated timing.
     * @return 全部计数可表示时返回 true；失败时保留输出。
     *        True when every count is representable; preserves output on failure.
     * @note 按器件默认纳秒预算向上取整，并补偿 DesignWare 高低电平内部延迟；不访问硬件。
     *        Rounds the device default nanosecond budgets upward and compensates DesignWare high/low latency;
     *        no hardware access.
     */
    bool sg200x_ll_i2c_timing_calculate(uint32_t peripheral_clock_hz, sg200x_ll_i2c_timing_t *timing);

    /**
     * @brief 使用显式时序配置一个已停止的 I2C 主机 / Configure a stopped I2C master with explicit timing.
     * @param i2c I2C0 至 I2C4 寄存器实例 / I2C0 through I2C4 register instance.
     * @param config 主机、地址和 FIFO 参数 / Master, address, and FIFO parameters.
     * @param timing 计数参数，可来自运行时计算或 TRM 表。
     *        Timing counts from runtime calculation or a TRM table.
     * @return 成功返回 true；参数无效或未停止时不写寄存器。
     *        True on success; no register writes for invalid parameters or a controller that is not stopped.
     * @note 保持控制器、中断和 DMA 请求关闭，并清除先前的中断；调用者准备时钟和引脚。
     *        Leaves the controller, interrupts, and DMA requests disabled and clears prior interrupts; the
     *        caller prepares clocks and pins.
     */
    bool sg200x_ll_i2c_init_with_timing(
        I2C_Type *i2c, const sg200x_ll_i2c_init_t *config, const sg200x_ll_i2c_timing_t *timing
    );

    /**
     * @brief 请求 I2C 使能状态并有界等待确认 / Request an I2C enable state and wait for bounded confirmation.
     * @param i2c I2C0 至 I2C4 寄存器实例 / I2C0 through I2C4 register instance.
     * @param enable 期望的使能状态 / Requested enable state.
     * @param attempts 最大状态读取次数，零表示不轮询 / Maximum status reads; zero performs no polling.
     * @return 状态已达到目标时返回 true；无效实例或超时返回 false。
     *        True when the requested state is observed; false for invalid instances or timeout.
     * @note 有效实例即使 attempts 为零也会写入使能请求；超时不撤销请求。
     *        A valid instance receives the enable request even with zero attempts; timeout does not cancel
     *        the request.
     */
    bool sg200x_ll_i2c_enable_wait(I2C_Type *i2c, bool enable, uint32_t attempts);

#ifdef __cplusplus
}
#endif

/**
 * @brief 同时配置 CON 和 TAR 的目标寻址模式 / Configure target addressing in both CON and TAR.
 * @param i2c I2C0 至 I2C4 寄存器实例 / I2C0 through I2C4 register instance.
 * @param address 符合所选模式的目标地址 / Target address fitting the selected mode.
 * @param ten_bit 是否使用十位地址 / Whether to use ten-bit addressing.
 * @pre 控制器已停止，地址符合七位或十位范围。
 *        The controller is stopped and the address fits seven or ten bits.
 */
static inline void sg200x_ll_i2c_master_address_set(I2C_Type *i2c, uint16_t address, bool ten_bit)
{
    const uint32_t con = i2c->CON;
    i2c->CON = ten_bit ? con | I2C_CON_MASTER_10BIT_BIT : con & ~I2C_CON_MASTER_10BIT_BIT;
    sg200x_ll_i2c_target_set(i2c, address, ten_bit);
}

/**
 * @brief 配置 I2C 收发 DMA 请求阈值 / Configure I2C receive/transmit DMA request thresholds.
 * @param i2c I2C0 至 I2C4 寄存器实例 / I2C0 through I2C4 register instance.
 * @param transmit 发送阈值，小于 I2C_FIFO_DEPTH / Transmit threshold, below I2C_FIFO_DEPTH.
 * @param receive 接收阈值，小于 I2C_FIFO_DEPTH / Receive threshold, below I2C_FIFO_DEPTH.
 * @pre 控制器已停止且阈值有效 / The controller is stopped and thresholds are valid.
 */
static inline void sg200x_ll_i2c_dma_threshold_set(I2C_Type *i2c, uint32_t transmit, uint32_t receive)
{
    i2c->DMA_TDLR = transmit;
    i2c->DMA_RDLR = receive;
}

/**
 * @brief 清除 I2C 发送中止状态 / Clear I2C transmit-abort status.
 * @param i2c I2C0 至 I2C4 寄存器实例 / I2C0 through I2C4 register instance.
 * @return 清除寄存器读回值 / Clear-register readback value.
 * @note 读取即清除该状态 / Reading clears the corresponding status.
 */
static inline uint32_t sg200x_ll_i2c_abort_clear(I2C_Type *i2c) { return i2c->CLR_TX_ABRT; }

/**
 * @brief 清除 I2C STOP 检测状态 / Clear I2C STOP-detection status.
 * @param i2c I2C0 至 I2C4 寄存器实例 / I2C0 through I2C4 register instance.
 * @return 清除寄存器读回值 / Clear-register readback value.
 * @note 读取即清除该状态 / Reading clears the corresponding status.
 */
static inline uint32_t sg200x_ll_i2c_stop_clear(I2C_Type *i2c) { return i2c->CLR_STOP_DET; }

/**
 * @brief 获取供 DMA 使用的 DATA_CMD 地址 / Get the DATA_CMD address for DMA.
 * @param i2c I2C0 至 I2C4 寄存器实例 / I2C0 through I2C4 register instance.
 * @return DATA_CMD 寄存器地址，不执行读取 / DATA_CMD register address; no read is performed.
 */
static inline uintptr_t sg200x_ll_i2c_data_address(I2C_Type *i2c) { return (uintptr_t)&i2c->DATA_CMD; }
