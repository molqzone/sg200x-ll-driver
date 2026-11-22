#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "sg2002.h"
#include "sg200x_ll_utils.h"

/**
 * @brief 按编号获取 SPI0 至 SPI3 / Get SPI0 through SPI3 by index.
 *
 * @param index 实例编号，范围为 0 到 3 / Instance index from 0 through 3.
 * @return 实例指针；编号无效时返回空指针 / Instance pointer, or null for an invalid index.
 */
static inline spi_t *sg200x_ll_spi_get(uint32_t index)
{
    switch (index)
    {
    case 0U:
        return SPI0_REGS;
    case 1U:
        return SPI1_REGS;
    case 2U:
        return SPI2_REGS;
    case 3U:
        return SPI3_REGS;
    default:
        return (spi_t *)0;
    }
}

/**
 * @brief 获取 SPI FIFO 数据端口的地址 / Get the address of the SPI FIFO data port.
 *
 * @param spi SPI 寄存器实例 / SPI register instance.
 * @return DR[0] 的地址，可用于 DMA 外设地址 / Address of DR[0], suitable as a DMA peripheral address.
 */
static inline uintptr_t sg200x_ll_spi_data_address(const spi_t *spi) { return (uintptr_t)&spi->DR[0]; }

/**
 * @brief SPI 控制帧位数减 1 的 CFS 编码 / SPI CFS encoding equal to control-frame bit count minus one.
 */
typedef enum
{

    LL_SPI_CONTROL_FRAME_SIZE_1_BIT = 0U, ///< 1 位控制帧。 1-bit control frame.
    LL_SPI_CONTROL_FRAME_SIZE_2_BIT,      ///< 2 位控制帧。 2-bit control frame.
    LL_SPI_CONTROL_FRAME_SIZE_3_BIT,      ///< 3 位控制帧。 3-bit control frame.
    LL_SPI_CONTROL_FRAME_SIZE_4_BIT,      ///< 4 位控制帧。 4-bit control frame.
    LL_SPI_CONTROL_FRAME_SIZE_5_BIT,      ///< 5 位控制帧。 5-bit control frame.
    LL_SPI_CONTROL_FRAME_SIZE_6_BIT,      ///< 6 位控制帧。 6-bit control frame.
    LL_SPI_CONTROL_FRAME_SIZE_7_BIT,      ///< 7 位控制帧。 7-bit control frame.
    LL_SPI_CONTROL_FRAME_SIZE_8_BIT,      ///< 8 位控制帧。 8-bit control frame.
    LL_SPI_CONTROL_FRAME_SIZE_9_BIT,      ///< 9 位控制帧。 9-bit control frame.
    LL_SPI_CONTROL_FRAME_SIZE_10_BIT,     ///< 10 位控制帧。 10-bit control frame.
    LL_SPI_CONTROL_FRAME_SIZE_11_BIT,     ///< 11 位控制帧。 11-bit control frame.
    LL_SPI_CONTROL_FRAME_SIZE_12_BIT,     ///< 12 位控制帧。 12-bit control frame.
    LL_SPI_CONTROL_FRAME_SIZE_13_BIT,     ///< 13 位控制帧。 13-bit control frame.
    LL_SPI_CONTROL_FRAME_SIZE_14_BIT,     ///< 14 位控制帧。 14-bit control frame.
    LL_SPI_CONTROL_FRAME_SIZE_15_BIT,     ///< 15 位控制帧。 15-bit control frame.
    LL_SPI_CONTROL_FRAME_SIZE_16_BIT,     ///< 16 位控制帧。 16-bit control frame.
} sg200x_ll_spi_control_frame_size_t;

/**
 * @brief SPI TMOD 传输模式编码 / SPI TMOD transfer-mode encoding.
 */
typedef enum
{
    LL_SPI_TRANSFER_MODE_TX_RX = 0U,       ///< 全双工收发。 Full-duplex transmit and receive.
    LL_SPI_TRANSFER_MODE_TX_ONLY = 1U,     ///< 仅发送。 Transmit only.
    LL_SPI_TRANSFER_MODE_RX_ONLY = 2U,     ///< 仅接收。 Receive only.
    LL_SPI_TRANSFER_MODE_EEPROM_READ = 3U, ///< EEPROM 读取模式。 EEPROM-read mode.
} sg200x_ll_spi_transfer_mode_t;

/**
 * @brief SPI 空闲时钟极性 / SPI idle-clock polarity.
 */
typedef enum
{
    LL_SPI_CLOCK_POLARITY_LOW = 0U,  ///< 时钟空闲为低电平。 Clock idles low.
    LL_SPI_CLOCK_POLARITY_HIGH = 1U, ///< 时钟空闲为高电平。 Clock idles high.
} sg200x_ll_spi_clock_polarity_t;

/**
 * @brief SPI 数据采样边沿选择 / SPI data-sampling edge selection.
 */
typedef enum
{

    LL_SPI_CLOCK_PHASE_FIRST_EDGE = 0U,  ///< 第一边沿采样，SCPH=0。 Sample on the first edge, SCPH=0.
    LL_SPI_CLOCK_PHASE_SECOND_EDGE = 1U, ///< 第二边沿采样，SCPH=1。 Sample on the second edge, SCPH=1.
} sg200x_ll_spi_clock_phase_t;

/**
 * @brief SPI 串行帧格式选择 / SPI serial frame-format selection.
 */
typedef enum
{
    LL_SPI_FRAME_FORMAT_MOTOROLA = 0U,     ///< Motorola SPI 格式。 Motorola SPI format.
    LL_SPI_FRAME_FORMAT_TI_SSP = 1U,       ///< TI 同步串行格式。 TI synchronous serial format.
    LL_SPI_FRAME_FORMAT_NS_MICROWIRE = 2U, ///< NS Microwire 格式。 NS Microwire format.
} sg200x_ll_spi_frame_format_t;

/**
 * @brief SPI 数据帧位数减 1 的 DFS 编码 / SPI DFS encoding equal to data-frame bit count minus one.
 */
typedef enum
{

    LL_SPI_DATA_FRAME_SIZE_4_BIT = 3U, ///< 4 位数据帧。 4-bit data frame.
    LL_SPI_DATA_FRAME_SIZE_5_BIT,      ///< 5 位数据帧。 5-bit data frame.
    LL_SPI_DATA_FRAME_SIZE_6_BIT,      ///< 6 位数据帧。 6-bit data frame.
    LL_SPI_DATA_FRAME_SIZE_7_BIT,      ///< 7 位数据帧。 7-bit data frame.
    LL_SPI_DATA_FRAME_SIZE_8_BIT,      ///< 8 位数据帧。 8-bit data frame.
    LL_SPI_DATA_FRAME_SIZE_9_BIT,      ///< 9 位数据帧。 9-bit data frame.
    LL_SPI_DATA_FRAME_SIZE_10_BIT,     ///< 10 位数据帧。 10-bit data frame.
    LL_SPI_DATA_FRAME_SIZE_11_BIT,     ///< 11 位数据帧。 11-bit data frame.
    LL_SPI_DATA_FRAME_SIZE_12_BIT,     ///< 12 位数据帧。 12-bit data frame.
    LL_SPI_DATA_FRAME_SIZE_13_BIT,     ///< 13 位数据帧。 13-bit data frame.
    LL_SPI_DATA_FRAME_SIZE_14_BIT,     ///< 14 位数据帧。 14-bit data frame.
    LL_SPI_DATA_FRAME_SIZE_15_BIT,     ///< 15 位数据帧。 15-bit data frame.
    LL_SPI_DATA_FRAME_SIZE_16_BIT,     ///< 16 位数据帧。 16-bit data frame.
} sg200x_ll_spi_data_frame_size_t;

/**
 * @brief 由 CPOL 与 SCPH 组成的标准 SPI 模式 / Standard SPI mode formed by CPOL and SCPH.
 */
typedef enum
{
    LL_SPI_MODE_0 = 0U, ///< 模式 0：CPOL=0、SCPH=0。 Mode 0: CPOL=0, SCPH=0.
    LL_SPI_MODE_1 = 1U, ///< 模式 1：CPOL=0、SCPH=1；8 位全双工 CTRLR0=0x47。 Mode 1: CPOL=0, SCPH=1.
    LL_SPI_MODE_2 = 2U, ///< 模式 2：CPOL=1、SCPH=0。 Mode 2: CPOL=1, SCPH=0.
    LL_SPI_MODE_3 = 3U, ///< 模式 3：CPOL=1、SCPH=1。 Mode 3: CPOL=1, SCPH=1.
} sg200x_ll_spi_mode_t;

/**
 * @brief 已禁止 SSI 主机的无状态初始化参数 / Stateless initialization parameters for a disabled SSI master.
 */
typedef struct
{
    sg200x_ll_spi_mode_t mode; ///< 标准 SPI 模式 0 到 3。 Standard SPI mode zero through three.
    sg200x_ll_spi_transfer_mode_t
        transfer_mode; ///< 收发方向或 EEPROM 读取模式。 Transmit/receive direction or EEPROM-read mode.
    sg200x_ll_spi_frame_format_t
        frame_format; ///< Motorola、TI SSP 或 NS Microwire 格式。 Motorola, TI SSP, or NS Microwire format.
    sg200x_ll_spi_data_frame_size_t
        data_frame_size; ///< 4 到 16 位数据帧的 DFS 编码。 DFS encoding for four- to sixteen-bit data frames.
    sg200x_ll_spi_control_frame_size_t
        control_frame_size; ///< 1 到 16 位控制帧的 CFS 编码。 CFS encoding for one-
                            ///< to sixteen-bit control frames.
    bool loopback;          ///< 使能移位寄存器回环。 Enable shift-register loopback.
    uint32_t baud_divider; ///< 2 到 65534 的偶数分频值，Init 不接受 0。 Even divisor from 2 through 65534;
                           ///< Init rejects zero.
    uint32_t
        receive_frame_count; ///< 接收帧数量，范围为 1 到 65536。 Receive-frame count from 1 through 65536.
    uint32_t tx_fifo_threshold; ///< 发送 FIFO 原始阈值，范围为 0 到 7。 Raw transmit FIFO threshold from 0
                                ///< through 7.
    uint32_t rx_fifo_threshold; ///< 接收 FIFO 原始阈值，范围为 0 到 7。 Raw receive FIFO threshold from 0
                                ///< through 7.
    uint32_t
        dma_tx_level; ///< 发送 DMA 请求阈值，范围为 0 到 7。 Transmit DMA request threshold from 0 through 7.
    uint32_t dma_rx_level; ///< 接收 DMA 请求原始阈值，范围为 0 到 7。 Raw receive DMA request threshold from
                           ///< 0 through 7.
    uint32_t rx_sample_delay; ///< 接收采样延迟，范围为 0 到 7。 Receive-sample delay from 0 through 7.
    uint32_t microwire_control; ///< MWCR 中定义的低 3 位。 Defined low three bits of MWCR.
} sg200x_ll_spi_init_t;

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @brief 填充 SPI 主机默认初始化参数 / Fill default SPI master initialization parameters.
     *
     * @param[out] config 接收默认配置的结构体指针，可为空。
     *        Destination for default configuration; may be null.
     * @note 默认 8 位 Motorola 模式 0、全双工、分频 2、阈值为 0；空指针不执行操作。
     *       Defaults are eight-bit Motorola mode zero, full duplex, divisor two, and zero thresholds; a null
     *       pointer is ignored.
     */
    void sg200x_ll_spi_struct_init(sg200x_ll_spi_init_t *config);

    /**
     * @brief 初始化调用者拥有的已禁止 SPI 实例 / Initialize a disabled SPI instance owned by the caller.
     *
     * @param spi SPI 寄存器实例 / SPI register instance.
     * @param[in] config 调用者提供的初始化配置 / Caller-provided initialization configuration.
     * @return 成功返回 true；参数或使能状态不合法时不写寄存器并返回 false。
     *         True on success; false without register writes for invalid arguments or enable state.
     * @note 仅支持 SPI0-3；时钟开启、复位释放且 SPIENR 为 0。成功后 SSI、片选、中断和 DMA 请求保持关闭。
     *       Only SPI0-3 are supported; clocks must be enabled, reset released, and SPIENR zero. SSI, selects,
     *       interrupts, and DMA requests remain disabled on success.
     */
    bool sg200x_ll_spi_init(spi_t *spi, const sg200x_ll_spi_init_t *config);

    /**
     * @brief 复位一个已禁止的 SPI 实例 / Reset one disabled SPI instance.
     *
     * @param spi SPI 寄存器实例 / SPI register instance.
     * @return 成功返回 true；实例无效或仍使能时返回 false。
     *         True on success; false for an invalid or enabled instance.
     * @note 调用者先禁止 SSI 并停止相关 DMA；只脉冲当前实例的复位位。
     *       Disable SSI and stop associated DMA first; only this instance's reset bit is pulsed.
     */
    bool sg200x_ll_spi_deinit(spi_t *spi);
#ifdef __cplusplus
}
#endif

/**
 * @brief 按语义参数编码 SPI CTRLR0 / Encode SPI CTRLR0 from semantic parameters.
 *
 * @param control_frame_size 控制帧位数减 1 的 CFS 编码 / CFS encoding equal to control-frame bits minus one.
 * @param shift_register_loop 是否使能移位寄存器回环 / Whether to enable shift-register loopback.
 * @param transfer_mode 收发方向及 EEPROM 读取模式编码。
 *        Transmit/receive direction or EEPROM-read mode encoding.
 * @param clock_polarity 串行时钟空闲电平 / Idle level of the serial clock.
 * @param clock_phase 在第一或第二个时钟边沿采样 / Sample on the first or second clock edge.
 * @param frame_format Motorola、TI SSP 或 NS Microwire 帧格式。
 *        Motorola, TI SSP, or NS Microwire frame format.
 * @param data_frame_size 数据帧位数减 1 的 DFS 编码 / DFS encoding equal to data-frame bits minus one.
 * @return CTRLR0 编码，不访问寄存器 / CTRLR0 encoding without register access.
 */
static inline uint32_t sg200x_ll_spi_ctrlr0_build(
    sg200x_ll_spi_control_frame_size_t control_frame_size, bool shift_register_loop,
    sg200x_ll_spi_transfer_mode_t transfer_mode, sg200x_ll_spi_clock_polarity_t clock_polarity,
    sg200x_ll_spi_clock_phase_t clock_phase, sg200x_ll_spi_frame_format_t frame_format,
    sg200x_ll_spi_data_frame_size_t data_frame_size
)
{
    uint32_t value = ((uint32_t)control_frame_size << SPI_CTRLR0_CFS_SHIFT) & SPI_CTRLR0_CFS_MASK;
    value |= ((uint32_t)transfer_mode << SPI_CTRLR0_TMOD_SHIFT) & SPI_CTRLR0_TMOD_MASK;
    value |= ((uint32_t)frame_format << SPI_CTRLR0_FRF_SHIFT) & SPI_CTRLR0_FRF_MASK;
    value |= (uint32_t)data_frame_size & SPI_CTRLR0_DFS_MASK;
    if (shift_register_loop)
    {
        value |= SPI_CTRLR0_SRL_BIT;
    }
    if (clock_polarity == LL_SPI_CLOCK_POLARITY_HIGH)
    {
        value |= SPI_CTRLR0_SCPOL_BIT;
    }
    if (clock_phase == LL_SPI_CLOCK_PHASE_SECOND_EDGE)
    {
        value |= SPI_CTRLR0_SCPH_BIT;
    }
    return value;
}

/**
 * @brief 构造 8 位 Motorola 全双工模式的 CTRLR0 / Build CTRLR0 for eight-bit Motorola full-duplex operation.
 *
 * @param mode 标准 SPI 模式 0 到 3 / Standard SPI mode zero through three.
 * @param shift_register_loop 是否使能移位寄存器回环 / Whether to enable shift-register loopback.
 * @return 包含极性、相位和回环选择的 CTRLR0 编码。
 *         CTRLR0 encoding with polarity, phase, and loopback selection.
 */
static inline uint32_t
sg200x_ll_spi_ctrlr0_build_motorola_8bit(sg200x_ll_spi_mode_t mode, bool shift_register_loop)
{
    const sg200x_ll_spi_clock_polarity_t polarity =
        (mode & 2U) != 0U ? LL_SPI_CLOCK_POLARITY_HIGH : LL_SPI_CLOCK_POLARITY_LOW;
    const sg200x_ll_spi_clock_phase_t phase =
        (mode & 1U) != 0U ? LL_SPI_CLOCK_PHASE_SECOND_EDGE : LL_SPI_CLOCK_PHASE_FIRST_EDGE;
    return sg200x_ll_spi_ctrlr0_build(
        LL_SPI_CONTROL_FRAME_SIZE_1_BIT, shift_register_loop, LL_SPI_TRANSFER_MODE_TX_RX, polarity, phase,
        LL_SPI_FRAME_FORMAT_MOTOROLA, LL_SPI_DATA_FRAME_SIZE_8_BIT
    );
}

/**
 * @brief 从 CTRLR0 数值解析标准 SPI 模式 / Decode the standard SPI mode from a CTRLR0 value.
 *
 * @param ctrlr0 待解析的 CTRLR0 数值 / CTRLR0 value to decode.
 * @return 由 CPOL 和 SCPH 决定的模式 0 到 3 / Mode zero through three selected by CPOL and SCPH.
 */
static inline sg200x_ll_spi_mode_t sg200x_ll_spi_mode_get(uint32_t ctrlr0)
{
    return (sg200x_ll_spi_mode_t)(((ctrlr0 & SPI_CTRLR0_SCPOL_BIT) != 0U ? 2U : 0U) |
                                  ((ctrlr0 & SPI_CTRLR0_SCPH_BIT) != 0U ? 1U : 0U));
}

/**
 * @brief 写入 CTRLR0 的低 16 位配置 / Write the low sixteen configuration bits of CTRLR0.
 *
 * @param spi SPI 寄存器实例 / SPI register instance.
 * @param value 要写入或编码的数值 / Value to write or encode.
 * @pre SSI 必须处于禁止状态 / SSI must be disabled.
 */
static inline void sg200x_ll_spi_ctrlr0_set(spi_t *spi, uint32_t value) { spi->CTRLR0 = value & 0xFFFFUL; }

/**
 * @brief 读取 CTRLR0 的低 16 位配置 / Read the low sixteen configuration bits of CTRLR0.
 *
 * @param spi SPI 寄存器实例 / SPI register instance.
 * @return 屏蔽高位后的 CTRLR0 值 / CTRLR0 with upper bits masked off.
 */
static inline uint32_t sg200x_ll_spi_ctrlr0_get(const spi_t *spi) { return spi->CTRLR0 & 0xFFFFUL; }

/**
 * @brief 使能 SSI 控制器 / Enable the SSI controller.
 *
 * @param spi SPI 寄存器实例 / SPI register instance.
 */
static inline void sg200x_ll_spi_enable(spi_t *spi) { spi->SPIENR = SPI_SPIENR_ENABLE_BIT; }

/**
 * @brief 禁止 SSI 控制器 / Disable the SSI controller.
 *
 * @param spi SPI 寄存器实例 / SPI register instance.
 */
static inline void sg200x_ll_spi_disable(spi_t *spi) { spi->SPIENR = 0U; }

/**
 * @brief 检查 SSI 控制器是否使能 / Check whether the SSI controller is enabled.
 *
 * @param spi SPI 寄存器实例 / SPI register instance.
 * @return SPIENR 使能位置位时返回 true / True when the SPIENR enable bit is set.
 */
static inline bool sg200x_ll_spi_is_enabled(const spi_t *spi)
{
    return (spi->SPIENR & SPI_SPIENR_ENABLE_BIT) != 0U;
}

/**
 * @brief 写入已定义的 SPI 片选使能位 / Write the defined SPI slave-select enable bits.
 *
 * @param spi SPI 寄存器实例 / SPI register instance.
 * @param mask 片选位掩码；本芯片只写入已定义的 SER 位 0。
 *        Slave-select mask; only the defined SER bit zero is written on this chip.
 */
static inline void sg200x_ll_spi_slave_select_set(spi_t *spi, uint32_t mask)
{
    spi->SER = mask & SPI_SER_MASK;
}

/**
 * @brief 使能 SPI 的片选 0 / Enable SPI slave select zero.
 *
 * @param spi SPI 寄存器实例 / SPI register instance.
 */
static inline void sg200x_ll_spi_slave_select_enable(spi_t *spi)
{
    sg200x_ll_spi_slave_select_set(spi, SPI_SER_CS0_BIT);
}

/**
 * @brief 关闭全部 SPI 片选使能位 / Clear all SPI slave-select enable bits.
 *
 * @param spi SPI 寄存器实例 / SPI register instance.
 */
static inline void sg200x_ll_spi_slave_select_disable(spi_t *spi) { spi->SER = 0U; }

/**
 * @brief 检查片选 0 的使能状态 / Check the enable state of slave select zero.
 *
 * @param spi SPI 寄存器实例 / SPI register instance.
 * @return SER 的片选 0 位置位时返回 true / True when slave-select bit zero in SER is set.
 */
static inline bool sg200x_ll_spi_slave_is_selected(const spi_t *spi)
{
    return (spi->SER & SPI_SER_CS0_BIT) != 0U;
}

/**
 * @brief 设置接收模式的帧数量 / Set the receive-mode frame count.
 *
 * @param spi SPI 寄存器实例 / SPI register instance.
 * @param count 接收数据帧数量，范围为 1 到 65536 / Receive data-frame count from 1 through 65536.
 * @return 数量在 1 到 65536 之间时写入并返回 true；否则返回 false。
 *         True after writing a count from 1 through 65536; false otherwise.
 * @note CTRLR1.NDF 存储 count - 1，用于只接收等接收计数模式。
 *       CTRLR1.NDF stores count minus one for receive-count modes such as receive-only.
 */
static inline bool sg200x_ll_spi_data_frame_count_set(spi_t *spi, uint32_t count)
{

    if (count == 0U || count > 65536UL)
    {
        return false;
    }
    spi->CTRLR1 = (count - 1U) & SPI_CTRLR1_NDF_MASK;
    return true;
}

/**
 * @brief 读取接收模式的帧数量 / Read the receive-mode frame count.
 *
 * @param spi SPI 寄存器实例 / SPI register instance.
 * @return CTRLR1.NDF 加 1 后的帧数量 / Frame count obtained by adding one to CTRLR1.NDF.
 */
static inline uint32_t sg200x_ll_spi_data_frame_count_get(const spi_t *spi)
{
    return (spi->CTRLR1 & SPI_CTRLR1_NDF_MASK) + 1U;
}

/**
 * @brief 检查 BAUDR 分频值是否合法 / Check whether a BAUDR divisor is valid.
 *
 * @param divider BAUDR 原始分频值 / Raw BAUDR divisor.
 * @return 值为 0 或 2 到 65534 之间的偶数时返回 true / True for zero or an even divisor from 2 through 65534.
 * @note 0 是关闭串行时钟的合法编码，不能作为有效传输分频；Init 不接受 0。
 *       Zero legally disables the serial clock but is not a transfer divisor; Init rejects zero.
 */
static inline bool sg200x_ll_spi_baud_divider_is_valid(uint32_t divider)
{
    return divider == SPI_BAUDR_CLOCK_DISABLED ||
           (divider >= SPI_BAUDR_MIN && divider <= SPI_BAUDR_MAX && (divider & 1U) == 0U);
}

/**
 * @brief 写入合法的 BAUDR 分频值 / Write a valid BAUDR divisor.
 *
 * @param spi SPI 寄存器实例 / SPI register instance.
 * @param divider BAUDR 原始分频值 / Raw BAUDR divisor.
 * @return 成功返回 true；分频值无效时不写寄存器并返回 false。
 *         True on success; false without a register write for an invalid divisor.
 * @note 0 是关闭串行时钟的合法编码，不能作为有效传输分频；Init 不接受 0。
 *       Zero legally disables the serial clock but is not a transfer divisor; Init rejects zero.
 */
static inline bool sg200x_ll_spi_baud_divider_set(spi_t *spi, uint32_t divider)
{
    if (!sg200x_ll_spi_baud_divider_is_valid(divider))
    {
        return false;
    }
    spi->BAUDR = divider & SPI_BAUDR_MASK;
    return true;
}

/**
 * @brief 读取 BAUDR 的分频值 / Read the BAUDR divisor.
 *
 * @param spi SPI 寄存器实例 / SPI register instance.
 * @return 原始分频值；0 表示串行时钟关闭 / Raw divisor; zero means the serial clock is disabled.
 */
static inline uint32_t sg200x_ll_spi_baud_divider_get(const spi_t *spi)
{
    return spi->BAUDR & SPI_BAUDR_MASK;
}

/**
 * @brief 设置发送 FIFO 的原始中断阈值 / Set the raw transmit FIFO interrupt threshold.
 *
 * @param spi SPI 寄存器实例 / SPI register instance.
 * @param level FIFO 阈值的原始寄存器编码 / Raw register encoding of the FIFO threshold.
 * @return 阈值在 0 到 7 之间时写入并返回 true / True after writing a threshold from 0 through 7.
 */
static inline bool sg200x_ll_spi_tx_fifo_threshold_set(spi_t *spi, uint32_t level)
{
    if (level > SPI_FIFO_THRESHOLD_MAX)
    {
        return false;
    }
    spi->TXFTLR = level & SPI_FIFO_THRESHOLD_MASK;
    return true;
}

/**
 * @brief 设置接收 FIFO 的原始中断阈值 / Set the raw receive FIFO interrupt threshold.
 *
 * @param spi SPI 寄存器实例 / SPI register instance.
 * @param level FIFO 阈值的原始寄存器编码 / Raw register encoding of the FIFO threshold.
 * @return 阈值在 0 到 7 之间时写入并返回 true / True after writing a threshold from 0 through 7.
 * @note RXFTLR 只有 3 位；接收条目数达到 level + 1 时触发。
 *       RXFTLR is only three bits wide; it triggers when the receive count reaches level plus one.
 */
static inline bool sg200x_ll_spi_rx_fifo_threshold_set(spi_t *spi, uint32_t level)
{

    if (level > SPI_FIFO_THRESHOLD_MAX)
    {
        return false;
    }
    spi->RXFTLR = level & SPI_FIFO_THRESHOLD_MASK;
    return true;
}

/**
 * @brief 按条目数设置接收 FIFO 中断触发点 / Set the receive FIFO interrupt trigger by entry count.
 *
 * @param spi SPI 寄存器实例 / SPI register instance.
 * @param entries 触发接收中断的 FIFO 条目数，范围为 1 到 8。
 *        FIFO entry count triggering receive interrupt, from 1 through 8.
 * @return 条目数在 1 到 8 之间时返回 true；否则不写寄存器。
 *         True for one through eight entries; otherwise no register is written.
 * @note 实际写入 RXFTLR 的值为 entries - 1 / The value written to RXFTLR is entries minus one.
 */
static inline bool sg200x_ll_spi_rx_fifo_trigger_level_set(spi_t *spi, uint32_t entries)
{

    if (entries == 0U || entries > SPI_FIFO_DEPTH)
    {
        return false;
    }
    return sg200x_ll_spi_rx_fifo_threshold_set(spi, entries - 1U);
}

/**
 * @brief 读取发送 FIFO 中的条目数 / Read the transmit FIFO entry count.
 *
 * @param spi SPI 寄存器实例 / SPI register instance.
 * @return 发送 FIFO 的当前条目数 / Current transmit FIFO entry count.
 */
static inline uint32_t sg200x_ll_spi_tx_fifo_level_get(const spi_t *spi)
{
    return spi->TXFLR & SPI_FIFO_LEVEL_MASK;
}

/**
 * @brief 读取接收 FIFO 中的条目数 / Read the receive FIFO entry count.
 *
 * @param spi SPI 寄存器实例 / SPI register instance.
 * @return 接收 FIFO 的当前条目数 / Current receive FIFO entry count.
 */
static inline uint32_t sg200x_ll_spi_rx_fifo_level_get(const spi_t *spi)
{
    return spi->RXFLR & SPI_FIFO_LEVEL_MASK;
}

/**
 * @brief 读取 SSI 状态寄存器 / Read the SSI status register.
 *
 * @param spi SPI 寄存器实例 / SPI register instance.
 * @return SR 的原始值 / Raw SR value.
 * @note 读取 SR 会清除位 5、6 的错误状态，参见 TRM 表 21.85。
 *       Reading SR clears error status bits five and six; see TRM Table 21.85.
 */
static inline uint32_t sg200x_ll_spi_status_get(const spi_t *spi) { return spi->SR; }

/**
 * @brief 检查 SSI 是否忙 / Check whether SSI is busy.
 *
 * @param spi SPI 寄存器实例 / SPI register instance.
 * @return SR.BUSY 置位时返回 true / True when SR.BUSY is set.
 * @note 读取 SR 会清除位 5、6 的错误状态，参见 TRM 表 21.85。
 *       Reading SR clears error status bits five and six; see TRM Table 21.85.
 */
static inline bool sg200x_ll_spi_is_busy(const spi_t *spi)
{
    return (sg200x_ll_spi_status_get(spi) & SPI_SR_BUSY_BIT) != 0U;
}

/**
 * @brief 检查发送 FIFO 是否仍有空间 / Check whether the transmit FIFO has space.
 *
 * @param spi SPI 寄存器实例 / SPI register instance.
 * @return SR.TFNF 置位时返回 true / True when SR.TFNF is set.
 * @note 读取 SR 会清除位 5、6 的错误状态，参见 TRM 表 21.85。
 *       Reading SR clears error status bits five and six; see TRM Table 21.85.
 */
static inline bool sg200x_ll_spi_tx_fifo_not_full(const spi_t *spi)
{
    return (sg200x_ll_spi_status_get(spi) & SPI_SR_TFNF_BIT) != 0U;
}

/**
 * @brief 检查接收 FIFO 是否有数据 / Check whether the receive FIFO contains data.
 *
 * @param spi SPI 寄存器实例 / SPI register instance.
 * @return SR.RFNE 置位时返回 true / True when SR.RFNE is set.
 * @note 读取 SR 会清除位 5、6 的错误状态，参见 TRM 表 21.85。
 *       Reading SR clears error status bits five and six; see TRM Table 21.85.
 */
static inline bool sg200x_ll_spi_rx_fifo_not_empty(const spi_t *spi)
{
    return (sg200x_ll_spi_status_get(spi) & SPI_SR_RFNE_BIT) != 0U;
}

/**
 * @brief 读取 SPI 中断使能掩码 / Read the SPI interrupt-enable mask.
 *
 * @param spi SPI 寄存器实例 / SPI register instance.
 * @return IMR 中定义的低 6 位 / Defined low six bits of IMR.
 */
static inline uint32_t sg200x_ll_spi_interrupt_mask_get(const spi_t *spi)
{
    return spi->IMR & SPI_INTERRUPT_MASK;
}

/**
 * @brief 设置 SPI 中断使能掩码 / Set the SPI interrupt-enable mask.
 *
 * @param spi SPI 寄存器实例 / SPI register instance.
 * @param mask IMR 使能位掩码，只写入低 6 位 / IMR enable mask; only the low six bits are written.
 */
static inline void sg200x_ll_spi_interrupt_mask_set(spi_t *spi, uint32_t mask)
{
    spi->IMR = mask & SPI_INTERRUPT_MASK;
}

/**
 * @brief 读取屏蔽后的 SPI 中断状态 / Read masked SPI interrupt status.
 *
 * @param spi SPI 寄存器实例 / SPI register instance.
 * @return ISR 中定义的中断状态位 / Defined interrupt-status bits in ISR.
 */
static inline uint32_t sg200x_ll_spi_interrupt_status_get(const spi_t *spi)
{
    return spi->ISR & SPI_INTERRUPT_MASK;
}

/**
 * @brief 读取屏蔽前的 SPI 中断状态 / Read unmasked SPI interrupt status.
 *
 * @param spi SPI 寄存器实例 / SPI register instance.
 * @return RISR 中定义的中断状态位 / Defined interrupt-status bits in RISR.
 */
static inline uint32_t sg200x_ll_spi_raw_interrupt_status_get(const spi_t *spi)
{
    return spi->RISR & SPI_INTERRUPT_MASK;
}

/**
 * @brief 通过读 ICR 清除 SPI 中断 / Clear SPI interrupts by reading ICR.
 *
 * @param spi SPI 寄存器实例 / SPI register instance.
 * @return 清除寄存器读回值 / Value read from the clear register.
 * @note 该读取具有清除状态的副作用 / This read has the side effect of clearing status.
 */
static inline uint32_t sg200x_ll_spi_interrupt_clear(spi_t *spi) { return spi->ICR; }

/**
 * @brief 通过读 TXOICR 清除发送溢出中断 / Clear transmit-overflow interrupt by reading TXOICR.
 *
 * @param spi SPI 寄存器实例 / SPI register instance.
 * @return 清除寄存器读回值 / Value read from the clear register.
 * @note 该读取具有清除状态的副作用 / This read has the side effect of clearing status.
 */
static inline uint32_t sg200x_ll_spi_tx_overflow_clear(spi_t *spi) { return spi->TXOICR; }

/**
 * @brief 通过读 RXOICR 清除接收溢出中断 / Clear receive-overflow interrupt by reading RXOICR.
 *
 * @param spi SPI 寄存器实例 / SPI register instance.
 * @return 清除寄存器读回值 / Value read from the clear register.
 * @note 该读取具有清除状态的副作用 / This read has the side effect of clearing status.
 */
static inline uint32_t sg200x_ll_spi_rx_overflow_clear(spi_t *spi) { return spi->RXOICR; }

/**
 * @brief 通过读 RXUICR 清除接收下溢中断 / Clear receive-underflow interrupt by reading RXUICR.
 *
 * @param spi SPI 寄存器实例 / SPI register instance.
 * @return 清除寄存器读回值 / Value read from the clear register.
 * @note 该读取具有清除状态的副作用 / This read has the side effect of clearing status.
 */
static inline uint32_t sg200x_ll_spi_rx_underflow_clear(spi_t *spi) { return spi->RXUICR; }

/**
 * @brief 通过读 MSTICR 清除多主机竞争中断 / Clear multi-master contention interrupt by reading MSTICR.
 *
 * @param spi SPI 寄存器实例 / SPI register instance.
 * @return 清除寄存器读回值 / Value read from the clear register.
 * @note 该读取具有清除状态的副作用 / This read has the side effect of clearing status.
 */
static inline uint32_t sg200x_ll_spi_multi_master_clear(spi_t *spi) { return spi->MSTICR; }

/**
 * @brief 设置 SPI 收发 DMA 请求使能位 / Set SPI receive/transmit DMA request enables.
 *
 * @param spi SPI 寄存器实例 / SPI register instance.
 * @param mask DMACR 收发使能掩码，只写入低 2 位。
 *        DMACR receive/transmit enable mask; only the low two bits are written.
 * @note 只配置 SSI 请求位，DMA 通道及描述符由调用者管理。
 *       Only SSI request bits are configured; the caller manages DMA channels and descriptors.
 */
static inline void sg200x_ll_spi_dma_control_set(spi_t *spi, uint32_t mask)
{
    spi->DMACR = mask & SPI_DMACR_MASK;
}

/**
 * @brief 关闭 SPI 的全部 DMA 请求 / Disable all SPI DMA requests.
 *
 * @param spi SPI 寄存器实例 / SPI register instance.
 * @note 只配置 SSI 请求位，DMA 通道及描述符由调用者管理。
 *       Only SSI request bits are configured; the caller manages DMA channels and descriptors.
 */
static inline void sg200x_ll_spi_dma_disable(spi_t *spi) { sg200x_ll_spi_dma_control_set(spi, 0U); }

/**
 * @brief 分别配置 SPI 接收和发送 DMA 请求 / Configure SPI receive and transmit DMA requests separately.
 *
 * @param spi SPI 寄存器实例 / SPI register instance.
 * @param receive 接收 DMA 请求使能状态 / Receive DMA request-enable state.
 * @param transmit 发送 DMA 请求使能状态 / Transmit DMA request-enable state.
 * @note 只配置 SSI 请求位，DMA 通道及描述符由调用者管理。
 *       Only SSI request bits are configured; the caller manages DMA channels and descriptors.
 */
static inline void sg200x_ll_spi_dma_enable(spi_t *spi, bool receive, bool transmit)
{
    uint32_t mask = 0U;
    if (receive)
    {
        mask |= SPI_DMACR_RX_ENABLE_BIT;
    }
    if (transmit)
    {
        mask |= SPI_DMACR_TX_ENABLE_BIT;
    }
    sg200x_ll_spi_dma_control_set(spi, mask);
}

/**
 * @brief 设置发送 DMA 请求的 FIFO 阈值 / Set the transmit DMA request FIFO threshold.
 *
 * @param spi SPI 寄存器实例 / SPI register instance.
 * @param level FIFO 阈值的原始寄存器编码 / Raw register encoding of the FIFO threshold.
 * @return 阈值在 0 到 7 之间时写入并返回 true / True after writing a threshold from 0 through 7.
 * @note 发送 FIFO 条目数不大于 level 时提出 DMA 请求。
 *       A DMA request is raised when the transmit FIFO count is no greater than level.
 */
static inline bool sg200x_ll_spi_dma_tx_level_set(spi_t *spi, uint32_t level)
{
    if (level >= SPI_FIFO_DEPTH)
    {
        return false;
    }
    spi->DMATDLR = level & SPI_DMATDLR_MASK;
    return true;
}

/**
 * @brief 设置接收 DMA 请求的原始 FIFO 阈值 / Set the raw receive DMA request FIFO threshold.
 *
 * @param spi SPI 寄存器实例 / SPI register instance.
 * @param level FIFO 阈值的原始寄存器编码 / Raw register encoding of the FIFO threshold.
 * @return 阈值在 0 到 7 之间时写入并返回 true / True after writing a threshold from 0 through 7.
 * @note 接收 FIFO 条目数达到 level + 1 时提出 DMA 请求。
 *       A DMA request is raised when the receive FIFO count reaches level plus one.
 */
static inline bool sg200x_ll_spi_dma_rx_level_set(spi_t *spi, uint32_t level)
{
    if (level >= SPI_FIFO_DEPTH)
    {
        return false;
    }
    spi->DMARDLR = level & SPI_DMARDLR_MASK;
    return true;
}

/**
 * @brief 向 SPI 发送 FIFO 写入一个数据字 / Write one data word to the SPI transmit FIFO.
 *
 * @param spi SPI 寄存器实例 / SPI register instance.
 * @param value 要写入或编码的数值 / Value to write or encode.
 * @pre 发送 FIFO 必须有空间 / The transmit FIFO must have space.
 * @note DR 有 36 个地址别名供总线突发访问同一 FIFO；本接口使用 DR[0]。
 *       DR has 36 aliases for burst access to the same FIFO; this interface uses DR[0].
 */
static inline void sg200x_ll_spi_data_write(spi_t *spi, uint16_t value)
{

    spi->DR[0] = (uint32_t)value & SPI_DR_MASK;
}

/**
 * @brief 从 SPI 接收 FIFO 取出一个数据字 / Pop one data word from the SPI receive FIFO.
 *
 * @param spi SPI 寄存器实例 / SPI register instance.
 * @return 接收数据端口的低 16 位 / Low sixteen bits read from the receive data port.
 * @pre 接收 FIFO 必须非空 / The receive FIFO must be nonempty.
 */
static inline uint16_t sg200x_ll_spi_data_read(spi_t *spi) { return (uint16_t)(spi->DR[0] & SPI_DR_MASK); }

/**
 * @brief 设置 SPI 接收采样延迟 / Set the SPI receive-sample delay.
 *
 * @param spi SPI 寄存器实例 / SPI register instance.
 * @param delay 采样延迟周期数，范围为 0 到 7 / Sample-delay cycles from 0 through 7.
 * @return 延迟在 0 到 7 之间时写入并返回 true；否则不写入。
 *         True after writing a delay from 0 through 7; otherwise no write occurs.
 * @note 超出内部延迟深度的硬件编码会选择零延迟，本接口拒绝这些值。
 *       Hardware encodings beyond the internal delay depth select zero delay; this interface rejects them.
 */
static inline bool sg200x_ll_spi_rx_sample_delay_set(spi_t *spi, uint32_t delay)
{
    if (delay > SPI_RX_SAMPLE_DLY_MAX)
    {

        return false;
    }
    spi->RX_SAMPLE_DLY = delay & SPI_RX_SAMPLE_DLY_MASK;
    return true;
}

/**
 * @brief 读取 SPI 接收采样延迟字段 / Read the SPI receive-sample delay field.
 *
 * @param spi SPI 寄存器实例 / SPI register instance.
 * @return RX_SAMPLE_DLY 的低 8 位 / Low eight bits of RX_SAMPLE_DLY.
 */
static inline uint32_t sg200x_ll_spi_rx_sample_delay_get(const spi_t *spi)
{
    return spi->RX_SAMPLE_DLY & SPI_RX_SAMPLE_DLY_MASK;
}

/**
 * @brief 设置 NS Microwire 控制字段 / Set the NS Microwire control fields.
 *
 * @param spi SPI 寄存器实例 / SPI register instance.
 * @param value 要写入或编码的数值 / Value to write or encode.
 */
static inline void sg200x_ll_spi_microwire_control_set(spi_t *spi, uint32_t value)
{
    spi->MWCR = value & SPI_MWCR_MASK;
}

/**
 * @brief 读取 NS Microwire 控制字段 / Read the NS Microwire control fields.
 *
 * @param spi SPI 寄存器实例 / SPI register instance.
 * @return MWCR 中定义的低 3 位 / Defined low three bits of MWCR.
 */
static inline uint32_t sg200x_ll_spi_microwire_control_get(const spi_t *spi)
{
    return spi->MWCR & SPI_MWCR_MASK;
}

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @brief 有界轮询等待 SPI 移位器空闲 / Poll for an idle SPI serializer with a bounded attempt count.
     * @param spi SPI 寄存器实例 / SPI register instance.
     * @param attempts 最大状态读取次数，零表示不轮询 / Maximum status reads; zero performs no polling.
     * @return 观察到空闲时为 true；空实例或超时为 false。
     *        True when idle is observed; false for a null instance or timeout.
     */
    bool sg200x_ll_spi_wait_idle(const SPI_Type *spi, uint32_t attempts);

#ifdef __cplusplus
}
#endif
