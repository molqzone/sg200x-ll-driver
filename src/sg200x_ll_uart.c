#include "sg200x_ll_uart.h"
#include "sg200x_ll_csr.h"
#include "sg200x_ll_rcc.h"

/**
 * @brief 查找 UART 实例对应的复位目标 / Find the reset target corresponding to a UART instance.
 *
 * @param uart UART 寄存器实例地址 / UART register-instance address.
 * @return 匹配的目标；未知地址返回 RESET_NONE / Matching target, or RESET_NONE for an unknown address.
 */
static rstgen_reset_target_t uart_reset_target(const UART_Type *uart)
{
    static const rstgen_reset_target_t resets[UART_COUNT] =
        {RESET_UART0, RESET_UART1, RESET_UART2, RESET_UART3, RESET_UART4};
    for (uint32_t index = 0U; index < UART_COUNT; ++index)
    {
        if (uart == sg200x_ll_uart_get(index))
        {
            return resets[index];
        }
    }
    return RESET_NONE;
}

void sg200x_ll_uart_struct_init(sg200x_ll_uart_init_t *config)
{
    if (config == NULL)
    {
        return;
    }
    config->baud_rate = 115200U;
    config->data_bits = LL_UART_DATA_BITS_8;
    config->stop_bits = LL_UART_STOP_BITS_1;
    config->parity = LL_UART_PARITY_NONE;
    config->fifo_enable = true;
    config->auto_flow_control = false;
    config->tx_fifo_trigger = 0U;
    config->rx_fifo_trigger = 0U;
}

bool sg200x_ll_uart_init(UART_Type *uart, const sg200x_ll_uart_init_t *config, uint32_t peripheral_clock_hz)
{
    if (config == NULL || uart_reset_target(uart) == RESET_NONE || config->baud_rate == 0U ||
        peripheral_clock_hz == 0U || (uint32_t)config->data_bits > LL_UART_DATA_BITS_8 ||
        (uint32_t)config->stop_bits > LL_UART_STOP_BITS_2 ||
        (uint32_t)config->parity > LL_UART_PARITY_SPACE ||
        (config->stop_bits == LL_UART_STOP_BITS_1_5 && config->data_bits != LL_UART_DATA_BITS_5) ||
        (config->stop_bits == LL_UART_STOP_BITS_2 && config->data_bits == LL_UART_DATA_BITS_5) ||
        config->tx_fifo_trigger > UART_FCR_TRIGGER_MAX || config->rx_fifo_trigger > UART_FCR_TRIGGER_MAX)
    {
        return false;
    }
    const uint64_t denominator = (uint64_t)config->baud_rate * UART_BAUD_OVERSAMPLING;
    const uint64_t divisor = ((uint64_t)peripheral_clock_hz + denominator / 2U) / denominator;
    if (denominator > peripheral_clock_hz || divisor == 0U || divisor > UART_BAUD_DIVISOR_MAX ||
        sg200x_ll_uart_is_busy(uart))
    {
        return false;
    }

    uint32_t line = (uint32_t)config->data_bits;
    if (config->stop_bits != LL_UART_STOP_BITS_1)
    {
        line |= UART_LCR_STOP_BIT;
    }
    if (config->parity != LL_UART_PARITY_NONE)
    {
        line |= UART_LCR_PARITY_ENABLE_BIT;
    }
    if (config->parity == LL_UART_PARITY_EVEN || config->parity == LL_UART_PARITY_SPACE)
    {
        line |= UART_LCR_EVEN_PARITY_BIT;
    }
    if (config->parity == LL_UART_PARITY_MARK || config->parity == LL_UART_PARITY_SPACE)
    {
        line |= UART_LCR_STICK_PARITY_BIT;
    }

    uart->LCR = line;
    sg200x_ll_csr_fence_io();
    uart->IER_DLH = 0U;
    sg200x_ll_csr_fence_io();
    uart->LCR = line | UART_LCR_DLAB_BIT;
    sg200x_ll_csr_fence_io();
    sg200x_ll_uart_baud_divisor_set(uart, (uint16_t)divisor);
    sg200x_ll_csr_fence_io();
    uart->LCR = line;
    sg200x_ll_csr_fence_io();
    uart->MCR = config->auto_flow_control ? UART_MCR_RTS_BIT | UART_MCR_AUTO_FLOW_CONTROL_BIT : 0U;
    uart->IIR_FCR = config->fifo_enable
                        ? UART_FCR_FIFO_ENABLE_BIT | UART_FCR_RX_FIFO_RESET_BIT | UART_FCR_TX_FIFO_RESET_BIT |
                              (config->tx_fifo_trigger << UART_FCR_TX_TRIGGER_SHIFT) |
                              (config->rx_fifo_trigger << UART_FCR_RX_TRIGGER_SHIFT)
                        : 0U;
    sg200x_ll_csr_fence_io();
    return true;
}

bool sg200x_ll_uart_deinit(UART_Type *uart)
{
    const rstgen_reset_target_t reset = uart_reset_target(uart);
    if (reset == RESET_NONE || sg200x_ll_uart_is_busy(uart))
    {
        return false;
    }
    sg200x_ll_uart_divisor_latch_enable(uart, false);
    sg200x_ll_csr_fence_io();
    uart->IER_DLH = 0U;
    uart->IIR_FCR = 0U;
    uart->MCR = 0U;
    sg200x_ll_csr_fence_io();
    sg200x_ll_rcc_reset_assert(reset);
    sg200x_ll_csr_fence_io();
    sg200x_ll_rcc_reset_release(reset);
    sg200x_ll_csr_fence_io();
    return true;
}
