#pragma once

#include <stdbool.h>
#include <stdint.h>

#include "sg2002.h"

/**
 * @brief UART 数据位长度编码 / UART data-bit length encoding.
 */
typedef enum
{
    LL_UART_DATA_BITS_5 = 0U, ///< 5 个数据位。 5 data bits.
    LL_UART_DATA_BITS_6,      ///< 6 个数据位。 6 data bits.
    LL_UART_DATA_BITS_7,      ///< 7 个数据位。 7 data bits.
    LL_UART_DATA_BITS_8,      ///< 8 个数据位。 8 data bits.
} sg200x_ll_uart_data_bits_t;

/**
 * @brief UART 停止位选择 / UART stop-bit selection.
 */
typedef enum
{
    LL_UART_STOP_BITS_1 = 0U, ///< 1 个停止位。 One stop bit.
    LL_UART_STOP_BITS_1_5, ///< 1.5 个停止位，仅用于 5 数据位。 One and a half stop bits, for five data bits
                           ///< only.
    LL_UART_STOP_BITS_2, ///< 2 个停止位，用于 6 到 8 数据位。 Two stop bits, for six to eight data bits.
} sg200x_ll_uart_stop_bits_t;

/**
 * @brief UART 奇偶校验选择 / UART parity selection.
 */
typedef enum
{
    LL_UART_PARITY_NONE = 0U, ///< 无奇偶校验。 No parity.
    LL_UART_PARITY_ODD,       ///< 奇校验。 Odd parity.
    LL_UART_PARITY_EVEN,      ///< 偶校验。 Even parity.
    LL_UART_PARITY_MARK,      ///< 校验位固定为 1。 Parity bit held at one.
    LL_UART_PARITY_SPACE,     ///< 校验位固定为 0。 Parity bit held at zero.
} sg200x_ll_uart_parity_t;

/**
 * @brief UART 波特率、帧格式和 FIFO 初始化参数。
 *        UART baud-rate, frame-format, and FIFO initialization parameters.
 */
typedef struct
{
    uint32_t baud_rate; ///< 目标波特率，分频取最近整数。 Target baud rate; the divisor is rounded to nearest.
    sg200x_ll_uart_data_bits_t data_bits; ///< 数据位长度选择。 Data-bit length selection.
    sg200x_ll_uart_stop_bits_t
        stop_bits; ///< 停止位选择，须与数据位长度兼容。 Stop-bit selection, compatible with the data length.
    sg200x_ll_uart_parity_t parity; ///< 奇偶校验模式。 Parity mode.
    bool fifo_enable;               ///< 使能收发 FIFO。 Enable receive and transmit FIFOs.
    bool auto_flow_control;         ///< 使能自动 RTS/CTS 流控。 Enable automatic RTS/CTS flow control.
    uint32_t tx_fifo_trigger; ///< 发送 FIFO 触发编码，范围为 0 到 3。 Transmit FIFO trigger encoding from 0
                              ///< through 3.
    uint32_t rx_fifo_trigger; ///< 接收 FIFO 触发编码，范围为 0 到 3。 Receive FIFO trigger encoding from 0
                              ///< through 3.
} sg200x_ll_uart_init_t;

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @brief 填充 UART 默认初始化参数 / Fill default UART initialization parameters.
     *
     * @param[out] config 接收默认配置的结构体指针，可为空。
     *        Destination for default configuration; may be null.
     * @note 默认 115200 波特、8N1、FIFO 开启且无硬件流控；空指针不执行操作。
     *       Defaults are 115200 baud, 8N1, FIFOs enabled, and no hardware flow control; a null pointer is
     *       ignored.
     */
    void sg200x_ll_uart_struct_init(sg200x_ll_uart_init_t *config);

    /**
     * @brief 用实际外设时钟配置一个空闲 UART / Configure an idle UART using the actual peripheral clock.
     *
     * @param uart UART 寄存器实例 / UART register instance.
     * @param[in] config 调用者提供的初始化配置 / Caller-provided initialization configuration.
     * @param peripheral_clock_hz 实际外设输入时钟频率，单位为 Hz。
     *        Actual peripheral input clock frequency in Hz.
     * @return 成功返回 true；参数无效或 UART 忙时不写寄存器并返回 false。
     *         True on success; false without register writes for invalid arguments or a busy UART.
     * @note 仅支持 UART0-4；分频值四舍五入。调用者先使对端和 DMA 静止。
     *       Only UART0-4 are supported; the divisor is rounded to nearest. Quiesce the peer and DMA first.
     * @note 成功后 DLAB 清零、中断关闭、FIFO 复位；1.5 停止位仅适用 5 数据位，2 停止位适用 6-8 数据位。
     *       Success clears DLAB, disables interrupts, and resets FIFOs; 1.5 stop bits require five data bits
     *       and two stop bits require six to eight.
     */
    bool
    sg200x_ll_uart_init(UART_Type *uart, const sg200x_ll_uart_init_t *config, uint32_t peripheral_clock_hz);

    /**
     * @brief 复位一个空闲 UART 实例 / Reset one idle UART instance.
     *
     * @param uart UART 寄存器实例 / UART register instance.
     * @return 成功返回 true；实例无效或 UART 忙时返回 false。
     *         True on success; false for an invalid or busy UART.
     * @note 调用者先使对端和 DMA 静止；仅脉冲此 UART 的复位位。
     *       Quiesce the peer and DMA first; only this UART's reset is pulsed.
     */
    bool sg200x_ll_uart_deinit(UART_Type *uart);
#ifdef __cplusplus
}
#endif

/**
 * @brief 按编号获取 UART0 至 UART4 / Get UART0 through UART4 by index.
 *
 * @param index 实例编号，范围为 0 到 4 / Instance index from 0 through 4.
 * @return 实例指针；编号无效时返回空指针 / Instance pointer, or null for an invalid index.
 */
static inline UART_Type *sg200x_ll_uart_get(uint32_t index)
{
    switch (index)
    {
    case 0U:
        return UART0_REGS;
    case 1U:
        return UART1_REGS;
    case 2U:
        return UART2_REGS;
    case 3U:
        return UART3_REGS;
    case 4U:
        return UART4_REGS;
    default:
        return (UART_Type *)0;
    }
}

/**
 * @brief 设置 UART 分频锁存器访问选择位 / Set the UART divisor-latch access selector.
 *
 * @param uart UART 寄存器实例 / UART register instance.
 * @param enable 为 true 时使能，为 false 时禁止 / True to enable; false to disable.
 */
static inline void sg200x_ll_uart_divisor_latch_enable(UART_Type *uart, bool enable)
{
    uint32_t value = uart->LCR;
    uart->LCR = enable ? value | UART_LCR_DLAB_BIT : value & ~(uint32_t)UART_LCR_DLAB_BIT;
}

/**
 * @brief 写入 UART 的低、高字节波特率分频值 / Write the low and high bytes of the UART baud divisor.
 *
 * @param uart UART 寄存器实例 / UART register instance.
 * @param divisor 写入 DLL/DLH 的 16 位波特率分频值 / Sixteen-bit baud divisor written to DLL/DLH.
 * @pre 调用者先设置 LCR.DLAB，并在写入后按需清除；本函数不切换寄存器银行。
 *      Set LCR.DLAB first and clear it afterward as needed; this function does not switch register banks.
 */
static inline void sg200x_ll_uart_baud_divisor_set(UART_Type *uart, uint16_t divisor)
{
    uart->RBR_THR_DLL = divisor & 0xFFU;
    uart->IER_DLH = (divisor >> 8U) & 0xFFU;
}

/**
 * @brief 设置 FIFO 使能并清除其他 FCR 配置位 / Set FIFO enable and clear the other FCR configuration bits.
 *
 * @param uart UART 寄存器实例 / UART register instance.
 * @param enable 为 true 时使能，为 false 时禁止 / True to enable; false to disable.
 */
static inline void sg200x_ll_uart_fifo_enable(UART_Type *uart, bool enable)
{
    uart->IIR_FCR = enable ? UART_FCR_FIFO_ENABLE_BIT : 0U;
}

/**
 * @brief 使能 FIFO 并复位收发 FIFO / Enable and reset both receive and transmit FIFOs.
 *
 * @param uart UART 寄存器实例 / UART register instance.
 * @note 此操作丢弃 FIFO 中的数据，并将其他 FCR 配置位清零。
 *       This discards FIFO contents and clears the other FCR configuration bits.
 */
static inline void sg200x_ll_uart_fifo_reset(UART_Type *uart)
{
    uart->IIR_FCR = UART_FCR_FIFO_ENABLE_BIT | UART_FCR_RX_FIFO_RESET_BIT | UART_FCR_TX_FIFO_RESET_BIT;
}

/**
 * @brief 写入 UART 帧格式控制寄存器的低 8 位 / Write the low eight bits of the UART line-control register.
 *
 * @param uart UART 寄存器实例 / UART register instance.
 * @param value 要写入或编码的数值 / Value to write or encode.
 */
static inline void sg200x_ll_uart_line_control_set(UART_Type *uart, uint32_t value)
{
    uart->LCR = value & 0xFFU;
}

/**
 * @brief 读取 UART 线路状态寄存器 / Read the UART line-status register.
 *
 * @param uart UART 寄存器实例 / UART register instance.
 * @return LSR 当前值 / Current LSR value.
 */
static inline uint32_t sg200x_ll_uart_line_status_get(const UART_Type *uart) { return uart->LSR; }

/**
 * @brief 检查 UART 是否有接收数据 / Check whether UART receive data is available.
 *
 * @param uart UART 寄存器实例 / UART register instance.
 * @return LSR 数据就绪位置位时返回 true / True when the LSR data-ready bit is set.
 */
static inline bool sg200x_ll_uart_rx_ready(const UART_Type *uart)
{
    return (uart->LSR & UART_LSR_DATA_READY_BIT) != 0U;
}

/**
 * @brief 检查 UART 发送保持寄存器是否为空 / Check whether the UART transmit holding register is empty.
 *
 * @param uart UART 寄存器实例 / UART register instance.
 * @return LSR THR 空位置位时返回 true / True when the LSR THR-empty bit is set.
 */
static inline bool sg200x_ll_uart_tx_ready(const UART_Type *uart)
{
    return (uart->LSR & UART_LSR_THR_EMPTY_BIT) != 0U;
}

/**
 * @brief 向 UART 发送保持寄存器写入一个字节 / Write one byte to the UART transmit holding register.
 *
 * @param uart UART 寄存器实例 / UART register instance.
 * @param value 要写入或编码的数值 / Value to write or encode.
 * @pre LCR.DLAB 必须为 0；调用者负责检查相应 FIFO/保持寄存器状态。
 *      LCR.DLAB must be zero; the caller checks the relevant FIFO/holding-register state.
 */
static inline void sg200x_ll_uart_data_write(UART_Type *uart, uint8_t value) { uart->RBR_THR_DLL = value; }

/**
 * @brief 从 UART 接收缓冲寄存器读取一个字节 / Read one byte from the UART receive buffer register.
 *
 * @param uart UART 寄存器实例 / UART register instance.
 * @return 接收的低 8 位数据 / Received low eight bits.
 * @pre LCR.DLAB 必须为 0；调用者负责检查相应 FIFO/保持寄存器状态。
 *      LCR.DLAB must be zero; the caller checks the relevant FIFO/holding-register state.
 */
static inline uint8_t sg200x_ll_uart_data_read(UART_Type *uart) { return (uint8_t)uart->RBR_THR_DLL; }

/**
 * @brief 读取 DesignWare UART 状态寄存器 / Read the DesignWare UART status register.
 *
 * @param uart UART 寄存器实例 / UART register instance.
 * @return USR 当前值 / Current USR value.
 */
static inline uint32_t sg200x_ll_uart_status_get(const UART_Type *uart) { return uart->USR; }

/**
 * @brief 检查 UART 的 BUSY 状态位 / Check the UART BUSY status bit.
 *
 * @param uart UART 寄存器实例 / UART register instance.
 * @return UART 忙时返回 true / True while the UART is busy.
 */
static inline bool sg200x_ll_uart_is_busy(const UART_Type *uart)
{
    return (uart->USR & UART_USR_BUSY_BIT) != 0U;
}
