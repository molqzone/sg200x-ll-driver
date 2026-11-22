#include "sg200x_ll_dma.h"
#include "sg200x_ll_csr.h"

/**
 * @brief 检查 DMA 初始化配置的地址、计数、模式和请求方向。
 *        Check DMA initialization addresses, count, modes, and request direction.
 *
 * @param[in] config 待验证的配置 / Configuration to validate.
 * @return 全部配置检查通过时返回 true / True when all configuration checks pass.
 * @note TRM 表 9.1 中，UART/SPI/I2C 接收请求编号为偶数，发送请求编号为奇数。
 *       In TRM Table 9.1, UART/SPI/I2C receive requests use even IDs and transmit requests odd IDs.
 */
static bool dma_init_config_valid(const sg200x_ll_dma_init_t *config)
{
    if (config == NULL || config->source == 0U || config->destination == 0U || config->count == 0U ||
        config->count > DMA_BLOCK_TRANSFER_MAX || (uint32_t)config->direction > LL_DMA_PERIPHERAL_TO_MEMORY ||
        (uint32_t)config->width > LL_DMA_WIDTH_HALF_WORD || (uint32_t)config->mode > LL_DMA_MODE_CIRCULAR ||
        config->priority > DMA_CFG_PRIORITY_MAX ||
        (config->next != 0U && !sg200x_ll_dma_lli_address_is_valid(config->next)) ||
        (config->mode == LL_DMA_MODE_NORMAL && config->next != 0U))
    {
        return false;
    }
    const uintptr_t alignment_mask = ((uintptr_t)1U << (uint32_t)config->width) - 1U;
    if (((config->source | config->destination) & alignment_mask) != 0U)
    {
        return false;
    }
    if (config->direction == LL_DMA_MEMORY_TO_MEMORY)
    {
        return config->request == LL_DMA_REQUEST_NONE;
    }
    const uint32_t request = (uint32_t)config->request;
    const bool supported_request = (request >= DMA_REQUEST_UART0_RX && request <= DMA_REQUEST_I2C4_TX) ||
                                   request == DMA_REQUEST_UART4_RX || request == DMA_REQUEST_UART4_TX;

    return supported_request &&
           (request & 1U) == (config->direction == LL_DMA_MEMORY_TO_PERIPHERAL ? 1U : 0U);
}

void sg200x_ll_dma_struct_init(sg200x_ll_dma_init_t *config)
{
    if (config == NULL)
    {
        return;
    }
    config->source = 0U;
    config->destination = 0U;
    config->count = 0U;
    config->direction = LL_DMA_MEMORY_TO_MEMORY;
    config->width = LL_DMA_WIDTH_BYTE;
    config->mode = LL_DMA_MODE_NORMAL;
    config->request = LL_DMA_REQUEST_NONE;
    config->priority = 0U;
    config->next = 0U;
}

bool sg200x_ll_dma_init(uint32_t channel, DMA_LLI_Type *lli, const sg200x_ll_dma_init_t *config)
{
    if (!sg200x_ll_dma_channel_is_valid(channel) || !sg200x_ll_dma_lli_address_is_valid((uintptr_t)lli) ||
        !dma_init_config_valid(config))
    {
        return false;
    }
    if ((sg200x_ll_dma_enabled_channels_get() & LL_BIT(channel)) != 0U)
    {
        return false;
    }
    const uintptr_t next =
        config->mode == LL_DMA_MODE_CIRCULAR ? (config->next != 0U ? config->next : (uintptr_t)lli) : 0U;
    if (!sg200x_ll_dma_lli_build(
            lli, config->source, config->destination, config->count, config->direction, config->width,
            config->mode, next
        ))
    {
        return false;
    }
    uint64_t channel_config = sg200x_ll_dma_config_build(config->direction, channel);
    channel_config =
        (channel_config & ~DMA_CFG_PRIORITY_MASK) | ((uint64_t)config->priority << DMA_CFG_PRIORITY_SHIFT);
    sg200x_ll_dma_channel_interrupt_configure(channel, 0U);
    sg200x_ll_dma_channel_interrupt_clear(channel, DMA_INT_ALL_MASK);
    if (config->direction != LL_DMA_MEMORY_TO_MEMORY)
    {
        sg200x_ll_dma_request_route_set(channel, (uint32_t)config->request);
    }
    (void)sg200x_ll_dma_channel_configure(channel, channel_config, (uintptr_t)lli);
    sg200x_ll_csr_fence_io();
    return true;
}

bool sg200x_ll_dma_deinit(uint32_t channel)
{
    if (!sg200x_ll_dma_channel_is_valid(channel) ||
        (sg200x_ll_dma_enabled_channels_get() & LL_BIT(channel)) != 0U)
    {
        return false;
    }
    DMA_Channel_Type *const ch = sg200x_ll_dma_channel_get(channel);
    sg200x_ll_dma_channel_interrupt_configure(channel, 0U);
    sg200x_ll_dma_channel_interrupt_clear(channel, DMA_INT_ALL_MASK);
    ch->CFG_LOW = 0U;
    ch->CFG_HIGH = 0U;
    ch->LLP_LOW = 0U;
    ch->LLP_HIGH = 0U;
    ch->SAR_LOW = 0U;
    ch->SAR_HIGH = 0U;
    ch->DAR_LOW = 0U;
    ch->DAR_HIGH = 0U;
    ch->BLOCK_TS_LOW = 0U;
    ch->BLOCK_TS_HIGH = 0U;
    ch->CTL_LOW = 0U;
    ch->CTL_HIGH = 0U;
    sg200x_ll_csr_fence_io();
    return true;
}

bool sg200x_ll_dma_lli_build(
    DMA_LLI_Type *lli, uintptr_t source, uintptr_t destination, uint32_t count,
    sg200x_ll_dma_direction_t direction, sg200x_ll_dma_width_t width, sg200x_ll_dma_mode_t mode,
    uintptr_t next
)
{
    if (!sg200x_ll_dma_lli_address_is_valid((uintptr_t)lli) || source == 0U || destination == 0U ||
        count == 0U || count > DMA_BLOCK_TRANSFER_MAX ||
        (next != 0U && !sg200x_ll_dma_lli_address_is_valid(next)) ||
        (mode == LL_DMA_MODE_CIRCULAR && next == 0U))
    {
        return false;
    }
    const uint64_t control = sg200x_ll_dma_control_build(direction, width, mode, (uintptr_t)lli);
    lli->source = source;
    lli->destination = destination;
    lli->block_ts = (uint64_t)count - 1U;
    lli->next = mode == LL_DMA_MODE_CIRCULAR ? next : 0U;
    lli->control_low = (uint32_t)control;
    lli->control_high = (uint32_t)(control >> 32U);
    lli->source_status = 0U;
    lli->destination_status = 0U;
    lli->status_low = 0U;
    lli->status_high = 0U;
    lli->reserved_low = 0U;
    lli->reserved_high = 0U;
    return true;
}

bool sg200x_ll_dma_channel_configure(uint32_t channel, uint64_t config, uintptr_t lli_address)
{
    DMA_Channel_Type *const ch = sg200x_ll_dma_channel_get(channel);
    if (ch == (DMA_Channel_Type *)0 || !sg200x_ll_dma_lli_address_is_valid(lli_address))
    {
        return false;
    }
    ch->CFG_LOW = (uint32_t)config;
    ch->CFG_HIGH = (uint32_t)(config >> 32U);
    ch->LLP_LOW = (uint32_t)lli_address;
    ch->LLP_HIGH = (uint32_t)((uint64_t)lli_address >> 32U);
    return true;
}

bool sg200x_ll_dma_channel_wait_disabled(uint32_t channel, uint32_t attempts)
{
    if (!sg200x_ll_dma_channel_is_valid(channel))
    {
        return false;
    }
    const uint32_t bit = LL_BIT(channel);
    for (uint32_t attempt = 0U; attempt < attempts; ++attempt)
    {
        if ((sg200x_ll_dma_enabled_channels_get() & bit) == 0U)
        {
            return true;
        }
    }
    return false;
}

bool sg200x_ll_dma_channels_wait_disabled(uint32_t channels, uint32_t attempts)
{
    if (channels == 0U || (channels & ~((1U << DMA_CHANNEL_COUNT) - 1U)) != 0U)
        return false;
    for (uint32_t attempt = 0U; attempt < attempts; ++attempt)
    {
        if ((sg200x_ll_dma_enabled_channels_get() & channels) == 0U)
            return true;
    }
    return false;
}
