#include "sg200x_ll_i2c.h"
#include "sg200x_ll_csr.h"
#include "sg200x_ll_rcc.h"

/**
 * @brief 查找 I2C 实例对应的复位目标 / Find the reset target corresponding to an I2C instance.
 *
 * @param i2c I2C 寄存器实例地址 / I2C register-instance address.
 * @return 匹配的目标；未知地址返回 RESET_NONE / Matching target, or RESET_NONE for an unknown address.
 */
static rstgen_reset_target_t i2c_reset_target(const I2C_Type *i2c)
{
    static const rstgen_reset_target_t resets[I2C_COUNT] =
        {RESET_I2C0, RESET_I2C1, RESET_I2C2, RESET_I2C3, RESET_I2C4};
    for (uint32_t index = 0U; index < I2C_COUNT; ++index)
    {
        if (i2c == sg200x_ll_i2c_get(index))
        {
            return resets[index];
        }
    }
    return RESET_NONE;
}

/**
 * @brief 确认 I2C 的使能和中止位均清零且禁用已完成。
 *        Confirm that I2C enable and abort bits are clear and disable has completed.
 *
 * @param i2c I2C 寄存器实例 / I2C register instance.
 * @return 控制寄存器与实际使能状态均表示已停止时为 true。
 *         True when control and actual enable status both indicate a stopped controller.
 */
static bool i2c_is_disabled(const I2C_Type *i2c)
{
    return (i2c->ENABLE & (I2C_ENABLE_BIT | I2C_ENABLE_ABORT_BIT)) == 0U && !sg200x_ll_i2c_is_enabled(i2c);
}

void sg200x_ll_i2c_struct_init(sg200x_ll_i2c_init_t *config)
{
    if (config == NULL)
    {
        return;
    }
    config->speed = I2C_SPEED_STANDARD;
    config->target_address = I2C_TAR_RESET_ADDRESS;
    config->ten_bit_addressing = false;
    config->restart_enable = true;
    config->tx_fifo_threshold = 0U;
    config->rx_fifo_threshold = 0U;
    config->dma_tx_level = 0U;
    config->dma_rx_level = 0U;
}

/**
 * @brief 检查 I2C 时序字段范围 / Validate I2C timing field ranges.
 * @param timing 待检查的时序 / Timing to validate.
 * @return 所有字段均可表示时返回 true / True when all fields are representable.
 */
static bool i2c_timing_valid(const sg200x_ll_i2c_timing_t *timing)
{
    return timing != NULL && timing->standard_high != 0U && timing->standard_high <= I2C_SCL_COUNT_MAX &&
           timing->standard_low != 0U && timing->standard_low <= I2C_SCL_COUNT_MAX &&
           timing->fast_high != 0U && timing->fast_high <= I2C_SCL_COUNT_MAX && timing->fast_low != 0U &&
           timing->fast_low <= I2C_SCL_COUNT_MAX && timing->sda_hold != 0U &&
           timing->sda_hold <= I2C_SDA_HOLD_TX_MAX && timing->sda_setup >= I2C_SDA_SETUP_MIN &&
           timing->sda_setup <= I2C_SDA_SETUP_MAX && timing->spike_length != 0U &&
           timing->spike_length <= I2C_SPKLEN_MAX;
}

/**
 * @brief 将纳秒预算向上换算为时钟计数 / Round a nanosecond budget upward to clock cycles.
 * @param clock_hz 输入时钟频率 / Input clock frequency.
 * @param nanoseconds 时间预算 / Time budget.
 * @return 向上取整的周期数 / Rounded-up cycle count.
 */
static uint32_t i2c_cycles(uint32_t clock_hz, uint32_t nanoseconds)
{
    return (uint32_t)(((uint64_t)clock_hz * nanoseconds + 999999999ULL) / 1000000000ULL);
}

bool sg200x_ll_i2c_timing_calculate(uint32_t peripheral_clock_hz, sg200x_ll_i2c_timing_t *timing)
{
    if (timing == NULL || peripheral_clock_hz == 0U)
        return false;
    sg200x_ll_i2c_timing_t counts = {
        .standard_high = i2c_cycles(peripheral_clock_hz, I2C_STANDARD_HIGH_NS + I2C_SCL_FALL_NS),
        .standard_low = i2c_cycles(peripheral_clock_hz, I2C_STANDARD_LOW_NS + I2C_SCL_FALL_NS),
        .fast_high = i2c_cycles(peripheral_clock_hz, I2C_FAST_HIGH_NS + I2C_SCL_FALL_NS),
        .fast_low = i2c_cycles(peripheral_clock_hz, I2C_FAST_LOW_NS + I2C_SCL_FALL_NS),
        .sda_hold = i2c_cycles(peripheral_clock_hz, I2C_SDA_HOLD_NS),
        .sda_setup = i2c_cycles(peripheral_clock_hz, I2C_SDA_SETUP_NS),
        .spike_length = i2c_cycles(peripheral_clock_hz, I2C_SPIKE_SUPPRESSION_NS),
    };
    if (counts.standard_high <= I2C_SCL_HIGH_LATENCY || counts.fast_high <= I2C_SCL_HIGH_LATENCY ||
        counts.standard_low <= I2C_SCL_LOW_LATENCY || counts.fast_low <= I2C_SCL_LOW_LATENCY)
        return false;
    counts.standard_high -= I2C_SCL_HIGH_LATENCY;
    counts.fast_high -= I2C_SCL_HIGH_LATENCY;
    counts.standard_low -= I2C_SCL_LOW_LATENCY;
    counts.fast_low -= I2C_SCL_LOW_LATENCY;
    if (!i2c_timing_valid(&counts))
        return false;
    *timing = counts;
    return true;
}

bool sg200x_ll_i2c_init_with_timing(
    I2C_Type *i2c, const sg200x_ll_i2c_init_t *config, const sg200x_ll_i2c_timing_t *timing
)
{
    if (config == NULL || i2c_reset_target(i2c) == RESET_NONE || !i2c_timing_valid(timing) ||
        (config->speed != I2C_SPEED_STANDARD && config->speed != I2C_SPEED_FAST) ||
        config->target_address >
            (config->ten_bit_addressing ? I2C_TAR_ADDRESS_MASK : I2C_TAR_7BIT_ADDRESS_MASK) ||
        config->tx_fifo_threshold >= I2C_FIFO_DEPTH || config->rx_fifo_threshold >= I2C_FIFO_DEPTH ||
        config->dma_tx_level >= I2C_FIFO_DEPTH || config->dma_rx_level >= I2C_FIFO_DEPTH ||
        !i2c_is_disabled(i2c))
    {
        return false;
    }
    i2c->ENABLE = 0U;
    i2c->INTR_MASK = 0U;
    i2c->DMA_CR = 0U;
    sg200x_ll_i2c_con_set(
        i2c,
        sg200x_ll_i2c_con_build(true, config->speed, config->ten_bit_addressing, config->restart_enable, true)
    );
    sg200x_ll_i2c_target_set(i2c, (uint16_t)config->target_address, config->ten_bit_addressing);
    i2c->SS_SCL_HCNT = timing->standard_high;
    i2c->SS_SCL_LCNT = timing->standard_low;
    i2c->FS_SCL_HCNT = timing->fast_high;
    i2c->FS_SCL_LCNT = timing->fast_low;
    i2c->SDA_HOLD = timing->sda_hold;
    i2c->SDA_SETUP = timing->sda_setup;
    i2c->SPKLEN = timing->spike_length;
    i2c->TX_TL = config->tx_fifo_threshold;
    i2c->RX_TL = config->rx_fifo_threshold;
    sg200x_ll_i2c_dma_threshold_set(i2c, config->dma_tx_level, config->dma_rx_level);
    (void)sg200x_ll_i2c_interrupt_clear(i2c);
    sg200x_ll_csr_fence_io();
    return true;
}

bool sg200x_ll_i2c_init(I2C_Type *i2c, const sg200x_ll_i2c_init_t *config, uint32_t peripheral_clock_hz)
{
    if (peripheral_clock_hz != I2C_TIMING_25M_CLOCK_HZ && peripheral_clock_hz != I2C_TIMING_100M_CLOCK_HZ)
        return false;
    const bool clock_25m = peripheral_clock_hz == I2C_TIMING_25M_CLOCK_HZ;
    const sg200x_ll_i2c_timing_t timing = {
        .standard_high = clock_25m ? I2C_TIMING_25M_SS_HCNT : I2C_TIMING_100M_SS_HCNT,
        .standard_low = clock_25m ? I2C_TIMING_25M_SS_LCNT : I2C_TIMING_100M_SS_LCNT,
        .fast_high = clock_25m ? I2C_TIMING_25M_FS_HCNT : I2C_TIMING_100M_FS_HCNT,
        .fast_low = clock_25m ? I2C_TIMING_25M_FS_LCNT : I2C_TIMING_100M_FS_LCNT,
        .sda_hold = I2C_TIMING_SDA_HOLD,
        .sda_setup = clock_25m ? I2C_TIMING_25M_SDA_SETUP : I2C_TIMING_100M_SDA_SETUP,
        .spike_length = clock_25m ? I2C_TIMING_25M_SPKLEN : I2C_TIMING_100M_SPKLEN,
    };
    return sg200x_ll_i2c_init_with_timing(i2c, config, &timing);
}

bool sg200x_ll_i2c_enable_wait(I2C_Type *i2c, bool enable, uint32_t attempts)
{
    if (i2c_reset_target(i2c) == RESET_NONE)
        return false;
    sg200x_ll_i2c_enable(i2c, enable);
    sg200x_ll_csr_fence_io();
    for (uint32_t attempt = 0U; attempt < attempts; ++attempt)
    {
        if (sg200x_ll_i2c_is_enabled(i2c) == enable)
            return true;
    }
    return false;
}

bool sg200x_ll_i2c_deinit(I2C_Type *i2c)
{
    const rstgen_reset_target_t reset = i2c_reset_target(i2c);
    if (reset == RESET_NONE || !i2c_is_disabled(i2c))
    {
        return false;
    }
    i2c->INTR_MASK = 0U;
    i2c->DMA_CR = 0U;
    sg200x_ll_csr_fence_io();
    sg200x_ll_rcc_reset_assert(reset);
    sg200x_ll_csr_fence_io();
    sg200x_ll_rcc_reset_release(reset);
    sg200x_ll_csr_fence_io();
    return true;
}
