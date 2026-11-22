#include "sg200x_ll_spi.h"
#include "sg200x_ll_csr.h"
#include "sg200x_ll_rcc.h"

/**
 * @brief 查找 SPI 实例对应的复位目标 / Find the reset target corresponding to a SPI instance.
 *
 * @param spi SPI 寄存器实例地址 / SPI register-instance address.
 * @return 匹配的目标；未知地址返回 RESET_NONE / Matching target, or RESET_NONE for an unknown address.
 */
static rstgen_reset_target_t spi_reset_target(const spi_t *spi)
{
    static const rstgen_reset_target_t resets[SPI_COUNT] = {RESET_SPI0, RESET_SPI1, RESET_SPI2, RESET_SPI3};
    for (uint32_t index = 0U; index < SPI_COUNT; ++index)
    {
        if (spi == sg200x_ll_spi_get(index))
        {
            return resets[index];
        }
    }
    return RESET_NONE;
}

void sg200x_ll_spi_struct_init(sg200x_ll_spi_init_t *config)
{
    if (config == NULL)
    {
        return;
    }
    config->mode = LL_SPI_MODE_0;
    config->transfer_mode = LL_SPI_TRANSFER_MODE_TX_RX;
    config->frame_format = LL_SPI_FRAME_FORMAT_MOTOROLA;
    config->data_frame_size = LL_SPI_DATA_FRAME_SIZE_8_BIT;
    config->control_frame_size = LL_SPI_CONTROL_FRAME_SIZE_1_BIT;
    config->loopback = false;
    config->baud_divider = SPI_BAUDR_MIN;
    config->receive_frame_count = 1U;
    config->tx_fifo_threshold = 0U;
    config->rx_fifo_threshold = 0U;
    config->dma_tx_level = 0U;
    config->dma_rx_level = 0U;
    config->rx_sample_delay = 0U;
    config->microwire_control = 0U;
}

bool sg200x_ll_spi_init(spi_t *spi, const sg200x_ll_spi_init_t *config)
{
    if (config == NULL || spi_reset_target(spi) == RESET_NONE || (uint32_t)config->mode > LL_SPI_MODE_3 ||
        (uint32_t)config->transfer_mode > LL_SPI_TRANSFER_MODE_EEPROM_READ ||
        (uint32_t)config->frame_format > LL_SPI_FRAME_FORMAT_NS_MICROWIRE ||
        (uint32_t)config->data_frame_size < LL_SPI_DATA_FRAME_SIZE_4_BIT ||
        (uint32_t)config->data_frame_size > LL_SPI_DATA_FRAME_SIZE_16_BIT ||
        (uint32_t)config->control_frame_size > LL_SPI_CONTROL_FRAME_SIZE_16_BIT ||
        config->baud_divider < SPI_BAUDR_MIN || !sg200x_ll_spi_baud_divider_is_valid(config->baud_divider) ||
        config->receive_frame_count == 0U || config->receive_frame_count > SPI_CTRLR1_NDF_MASK + 1U ||
        config->tx_fifo_threshold > SPI_FIFO_THRESHOLD_MAX ||
        config->rx_fifo_threshold > SPI_FIFO_THRESHOLD_MAX || config->dma_tx_level >= SPI_FIFO_DEPTH ||
        config->dma_rx_level >= SPI_FIFO_DEPTH || config->rx_sample_delay > SPI_RX_SAMPLE_DLY_MAX ||
        (config->microwire_control & ~(uint32_t)SPI_MWCR_MASK) != 0U)
    {
        return false;
    }
    if (sg200x_ll_spi_is_enabled(spi))
    {
        return false;
    }

    const sg200x_ll_spi_clock_polarity_t polarity =
        (config->mode & 2U) != 0U ? LL_SPI_CLOCK_POLARITY_HIGH : LL_SPI_CLOCK_POLARITY_LOW;
    const sg200x_ll_spi_clock_phase_t phase =
        (config->mode & 1U) != 0U ? LL_SPI_CLOCK_PHASE_SECOND_EDGE : LL_SPI_CLOCK_PHASE_FIRST_EDGE;
    sg200x_ll_spi_disable(spi);
    spi->IMR = 0U;
    spi->DMACR = 0U;
    spi->SER = 0U;
    spi->CTRLR0 = sg200x_ll_spi_ctrlr0_build(
        config->control_frame_size, config->loopback, config->transfer_mode, polarity, phase,
        config->frame_format, config->data_frame_size
    );
    spi->CTRLR1 = config->receive_frame_count - 1U;
    spi->BAUDR = config->baud_divider;
    spi->MWCR = config->microwire_control;
    spi->TXFTLR = config->tx_fifo_threshold;
    spi->RXFTLR = config->rx_fifo_threshold;
    spi->DMATDLR = config->dma_tx_level;
    spi->DMARDLR = config->dma_rx_level;
    spi->RX_SAMPLE_DLY = config->rx_sample_delay;
    (void)sg200x_ll_spi_interrupt_clear(spi);
    sg200x_ll_csr_fence_io();
    return true;
}

bool sg200x_ll_spi_deinit(spi_t *spi)
{
    const rstgen_reset_target_t reset = spi_reset_target(spi);
    if (reset == RESET_NONE || sg200x_ll_spi_is_enabled(spi))
    {
        return false;
    }
    spi->IMR = 0U;
    spi->DMACR = 0U;
    spi->SER = 0U;
    sg200x_ll_csr_fence_io();
    sg200x_ll_rcc_reset_assert(reset);
    sg200x_ll_csr_fence_io();
    sg200x_ll_rcc_reset_release(reset);
    sg200x_ll_csr_fence_io();
    return true;
}

bool sg200x_ll_spi_wait_idle(const SPI_Type *spi, uint32_t attempts)
{
    if (spi == NULL)
        return false;
    for (uint32_t attempt = 0U; attempt < attempts; ++attempt)
    {
        if (!sg200x_ll_spi_is_busy(spi))
            return true;
    }
    return false;
}
