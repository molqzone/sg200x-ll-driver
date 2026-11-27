#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "sg2002.h"
#include "sg200x_ll_utils.h"

/**
 * @brief DMA 元素宽度编码 / DMA item-width encoding.
 */
typedef enum
{
    LL_DMA_WIDTH_BYTE = 0U,      ///< 8 位数据元素。 Eight-bit data items.
    LL_DMA_WIDTH_HALF_WORD = 1U, ///< 16 位数据元素。 Sixteen-bit data items.
} sg200x_ll_dma_width_t;

/**
 * @brief DMA 数据传输方向 / DMA data-transfer direction.
 */
typedef enum
{
    LL_DMA_MEMORY_TO_MEMORY = 0U,     ///< 内存到内存传输。 Memory-to-memory transfer.
    LL_DMA_MEMORY_TO_PERIPHERAL = 1U, ///< 内存到外设传输。 Memory-to-peripheral transfer.
    LL_DMA_PERIPHERAL_TO_MEMORY = 2U, ///< 外设到内存传输。 Peripheral-to-memory transfer.
} sg200x_ll_dma_direction_t;

/**
 * @brief DMA 普通或循环工作模式 / DMA normal or circular operating mode.
 */
typedef enum
{
    LL_DMA_MODE_NORMAL = 0U,   ///< 单次描述符传输。 One-shot descriptor transfer.
    LL_DMA_MODE_CIRCULAR = 1U, ///< 循环链表传输。 Circular linked-list transfer.
} sg200x_ll_dma_mode_t;

/**
 * @brief DMA 外设请求映射编号 / DMA peripheral-request mapping IDs.
 */
typedef enum
{
    LL_DMA_REQUEST_NONE = DMA_REQUEST_NONE, ///< 不使用外设请求。 No peripheral request.
    LL_DMA_REQUEST_UART0_RX =
        DMA_REQUEST_UART0_RX, ///< UART0 的 DMA 接收请求。 DMA receive request for UART0.
    LL_DMA_REQUEST_UART0_TX =
        DMA_REQUEST_UART0_TX, ///< UART0 的 DMA 发送请求。 DMA transmit request for UART0.
    LL_DMA_REQUEST_UART1_RX =
        DMA_REQUEST_UART1_RX, ///< UART1 的 DMA 接收请求。 DMA receive request for UART1.
    LL_DMA_REQUEST_UART1_TX =
        DMA_REQUEST_UART1_TX, ///< UART1 的 DMA 发送请求。 DMA transmit request for UART1.
    LL_DMA_REQUEST_UART2_RX =
        DMA_REQUEST_UART2_RX, ///< UART2 的 DMA 接收请求。 DMA receive request for UART2.
    LL_DMA_REQUEST_UART2_TX =
        DMA_REQUEST_UART2_TX, ///< UART2 的 DMA 发送请求。 DMA transmit request for UART2.
    LL_DMA_REQUEST_UART3_RX =
        DMA_REQUEST_UART3_RX, ///< UART3 的 DMA 接收请求。 DMA receive request for UART3.
    LL_DMA_REQUEST_UART3_TX =
        DMA_REQUEST_UART3_TX, ///< UART3 的 DMA 发送请求。 DMA transmit request for UART3.
    LL_DMA_REQUEST_UART4_RX =
        DMA_REQUEST_UART4_RX, ///< UART4 的 DMA 接收请求。 DMA receive request for UART4.
    LL_DMA_REQUEST_UART4_TX =
        DMA_REQUEST_UART4_TX, ///< UART4 的 DMA 发送请求。 DMA transmit request for UART4.
    LL_DMA_REQUEST_SPI0_RX = DMA_REQUEST_SPI0_RX, ///< SPI0 的 DMA 接收请求。 DMA receive request for SPI0.
    LL_DMA_REQUEST_SPI0_TX = DMA_REQUEST_SPI0_TX, ///< SPI0 的 DMA 发送请求。 DMA transmit request for SPI0.
    LL_DMA_REQUEST_SPI1_RX = DMA_REQUEST_SPI1_RX, ///< SPI1 的 DMA 接收请求。 DMA receive request for SPI1.
    LL_DMA_REQUEST_SPI1_TX = DMA_REQUEST_SPI1_TX, ///< SPI1 的 DMA 发送请求。 DMA transmit request for SPI1.
    LL_DMA_REQUEST_SPI2_RX = DMA_REQUEST_SPI2_RX, ///< SPI2 的 DMA 接收请求。 DMA receive request for SPI2.
    LL_DMA_REQUEST_SPI2_TX = DMA_REQUEST_SPI2_TX, ///< SPI2 的 DMA 发送请求。 DMA transmit request for SPI2.
    LL_DMA_REQUEST_SPI3_RX = DMA_REQUEST_SPI3_RX, ///< SPI3 的 DMA 接收请求。 DMA receive request for SPI3.
    LL_DMA_REQUEST_SPI3_TX = DMA_REQUEST_SPI3_TX, ///< SPI3 的 DMA 发送请求。 DMA transmit request for SPI3.
    LL_DMA_REQUEST_I2C0_RX = DMA_REQUEST_I2C0_RX, ///< I2C0 的 DMA 接收请求。 DMA receive request for I2C0.
    LL_DMA_REQUEST_I2C0_TX = DMA_REQUEST_I2C0_TX, ///< I2C0 的 DMA 发送请求。 DMA transmit request for I2C0.
    LL_DMA_REQUEST_I2C1_RX = DMA_REQUEST_I2C1_RX, ///< I2C1 的 DMA 接收请求。 DMA receive request for I2C1.
    LL_DMA_REQUEST_I2C1_TX = DMA_REQUEST_I2C1_TX, ///< I2C1 的 DMA 发送请求。 DMA transmit request for I2C1.
    LL_DMA_REQUEST_I2C2_RX = DMA_REQUEST_I2C2_RX, ///< I2C2 的 DMA 接收请求。 DMA receive request for I2C2.
    LL_DMA_REQUEST_I2C2_TX = DMA_REQUEST_I2C2_TX, ///< I2C2 的 DMA 发送请求。 DMA transmit request for I2C2.
    LL_DMA_REQUEST_I2C3_RX = DMA_REQUEST_I2C3_RX, ///< I2C3 的 DMA 接收请求。 DMA receive request for I2C3.
    LL_DMA_REQUEST_I2C3_TX = DMA_REQUEST_I2C3_TX, ///< I2C3 的 DMA 发送请求。 DMA transmit request for I2C3.
    LL_DMA_REQUEST_I2C4_RX = DMA_REQUEST_I2C4_RX, ///< I2C4 的 DMA 接收请求。 DMA receive request for I2C4.
    LL_DMA_REQUEST_I2C4_TX = DMA_REQUEST_I2C4_TX, ///< I2C4 的 DMA 发送请求。 DMA transmit request for I2C4.
} sg200x_ll_dma_request_t;

/**
 * @brief 调用者持有的 DMA 初始化参数 / Caller-owned DMA initialization parameters.
 */
typedef struct
{
    uintptr_t source;      ///< 数据源地址。 Source data address.
    uintptr_t destination; ///< 数据目的地址。 Destination data address.
    uint32_t
        count; ///< 所选元素宽度的数据项数量，不是字节数。 Item count of the selected width, not a byte count.
    sg200x_ll_dma_direction_t direction; ///< 数据传输方向。 Data-transfer direction.
    sg200x_ll_dma_width_t width;         ///< 字节或半字元素宽度。 Byte or half-word item width.
    sg200x_ll_dma_mode_t mode;           ///< 普通或循环模式。 Normal or circular mode.
    sg200x_ll_dma_request_t
        request; ///< 外设请求编号，内存复制使用 NONE。 Peripheral request ID; memory copy uses NONE.
    uint32_t priority; ///< 通道优先级，范围为 0 到 7。 Channel priority from 0 through 7.
    uintptr_t next; ///< 循环模式下 0 表示自链接，否则是 64 字节对齐的下一项地址。 In circular mode, zero
        ///< self-links; otherwise use a 64-byte-aligned next-item address.
} sg200x_ll_dma_init_t;

/**
 * @brief 获取 DMA 通道的寄存器块 / Get a DMA channel's register block.
 *
 * @param channel DMA 通道编号，范围为 0 到 7 / DMA channel index from 0 through 7.
 * @return 有效通道指针；编号无效时返回空指针 / Channel pointer, or null for an invalid index.
 */
static inline DMA_Channel_Type *sg200x_ll_dma_channel_get(uint32_t channel)
{
    return channel < DMA_CHANNEL_COUNT ? &DMA->CHANNEL[channel] : (DMA_Channel_Type *)0;
}

/**
 * @brief 获取 DMA 通道寄存器块的地址 / Get the address of a DMA channel's register block.
 *
 * @param channel DMA 通道编号，范围为 0 到 7 / DMA channel index from 0 through 7.
 * @return 寄存器块地址；编号无效时返回 0 / Register-block address, or zero for an invalid index.
 */
static inline uintptr_t sg200x_ll_dma_channel_address(uint32_t channel)
{
    return (uintptr_t)sg200x_ll_dma_channel_get(channel);
}

/**
 * @brief 检查 DMA 通道编号 / Check a DMA channel index.
 *
 * @param channel DMA 通道编号，范围为 0 到 7 / DMA channel index from 0 through 7.
 * @return 编号在 0 到 7 之间时为 true / True for channel indices from 0 through 7.
 */
static inline bool sg200x_ll_dma_channel_is_valid(uint32_t channel) { return channel < DMA_CHANNEL_COUNT; }

/**
 * @brief 设置 DMA 控制器及全局中断使能 / Set DMA controller and global interrupt enables.
 *
 * @param enable 为 true 时使能，为 false 时禁止 / True to enable; false to disable.
 * @param enable_interrupts DMA 全局中断使能状态 / DMA global interrupt-enable state.
 */
/** @brief 读取全局配置寄存器 / Read the controller's global configuration. */
static inline uint32_t sg200x_ll_dma_cfg_get(void) { return DMA->GLOBAL.CFG; }

/** @brief 写全局配置寄存器（只在确实需要时用）/ Write the global configuration. */
static inline void sg200x_ll_dma_cfg_set(uint32_t value) { DMA->GLOBAL.CFG = value; }

/**
 * @brief 只在控制器**未使能**时才打开它，绝不改全局中断使能位。
 *        Enable the controller only if it is off, and never touch the global interrupt bit.
 *
 * SD 卡（内核 MMC）用的是同一颗 DMAC 的 0–3 通道。放核期间若**无条件重写** `GLOBAL.CFG`，
 * 会在内核正等 SD 传输时动到全局中断使能位，那次传输就永远收不到完成，表现为"放核即挂死
 * 大核"（实测：首次开机正常，重启后应用在写录制时放核必挂）。
 *
 * 但也不能干脆不设：若控制器原本没使能中断，我们的 DMA 完成中断永远不来，SPI 读会一直
 * 阻塞（实测：模块图卡在 BMI088 构造函数里，控制台停在 `[guided-dart] up`）。
 * 所以是读-改-写，**只补齐缺的位**：内核已经设好时一个字节都不写，缺的时候才补。
 * The SD card (kernel MMC) uses channels 0-3 of the same DMAC.  **Unconditionally**
 * rewriting `GLOBAL.CFG` during a release flips the controller's global interrupt enable,
 * so the SD transfer the kernel is waiting on never completes -- "releasing the core
 * freezes the big core" (measured: first boot fine, a reboot with the recorder writing to
 * SD always hung).
 *
 * Not setting it at all is the other failure: with the controller's interrupts off, our DMA
 * completion never arrives and the SPI read blocks forever (measured: the graph stops in
 * the BMI088 constructor, console ending at `[guided-dart] up`).  So this is a
 * read-modify-write that fills in **only the missing bits**: nothing is written when the
 * kernel already enabled both, and the bits are added when they are missing.
 */
static inline void sg200x_ll_dma_enable_if_off(void)
{
    /* 空实现：**不要**碰全局配置寄存器。/ Empty on purpose: **do not** touch GLOBAL.CFG.
     *
     * 读它不行：这个核对外设寄存器的可缓存读会做 64 字节行填充，落在实现范围外就回总线
     * 错误（和 CLINT 那次同源，实测固件在第一行打印之前就停住）。
     * 写它也不行：放核期间无条件写会改到全局中断使能位，内核正等的 SD 传输永远完不成
     * （实测：录制写盘时重启必挂）。
     * 控制器由引导/内核使能，本核只做按通道的配置与中断路由，所以这里什么都不用做。
     *
     * Reading it is out: a cacheable load on this core fills a 64-byte line, and a fill past
     * the implemented range returns a bus error (the same trap as the CLINT; measured: the
     * firmware stopped before printing its first line).
     * Writing it is out too: an unconditional write during a release flips the global
     * interrupt enable and the SD transfer the kernel is waiting on never completes
     * (measured: a reboot with the recorder writing to SD always hung).
     * The controller is enabled by the boot chain/kernel, and this core only configures its
     * own channels and their interrupt routing, so nothing is needed here. */
}

static inline void sg200x_ll_dma_enable(bool enable, bool enable_interrupts)
{
    DMA->GLOBAL.CFG =
        (enable ? DMA_CFG_DMAC_ENABLE_BIT : 0U) | (enable_interrupts ? DMA_CFG_INTERRUPT_ENABLE_BIT : 0U);
}

/**
 * @brief 读取 DMA 通道使能寄存器 / Read the DMA channel-enable register.
 *
 * @return CHEN 原始值，低 8 位表示通道使能状态 / Raw CHEN value; the low eight bits report channel enables.
 */
static inline uint32_t sg200x_ll_dma_enabled_channels_get(void) { return DMA->GLOBAL.CHEN; }

/**
 * @brief 请求停止一个 DMA 通道 / Request that one DMA channel be disabled.
 *
 * @param channel DMA 通道编号，范围为 0 到 7 / DMA channel index from 0 through 7.
 * @note 此函数只发出请求；复用资源前须等待通道停止。
 *       This function only issues a request; wait for disable completion before reusing resources.
 */
static inline void sg200x_ll_dma_channel_disable_request(uint32_t channel)
{
    if (sg200x_ll_dma_channel_is_valid(channel))
    {
        DMA->GLOBAL.CHEN = LL_BIT(channel) << DMA_CHANNEL_WRITE_ENABLE_SHIFT;
    }
}

/**
 * @brief 请求停止掩码指定的 DMA 通道 / Request that the selected DMA channels be disabled.
 *
 * @param channels DMA 通道位掩码，使用低 8 位 / DMA channel mask using the low eight bits.
 * @note 此函数只发出请求；复用资源前须等待通道停止。
 *       This function only issues a request; wait for disable completion before reusing resources.
 * @note 掩码仅可包含低 8 位，调用者负责共享通道所有权。
 *       The mask may contain only the low eight bits; the caller manages shared-channel ownership.
 */
static inline void sg200x_ll_dma_channels_disable_request(uint32_t channels)
{
    DMA->GLOBAL.CHEN = channels << DMA_CHANNEL_WRITE_ENABLE_SHIFT;
}

/**
 * @brief 使能一个已配置的 DMA 通道 / Enable one configured DMA channel.
 *
 * @param channel DMA 通道编号，范围为 0 到 7 / DMA channel index from 0 through 7.
 */
static inline void sg200x_ll_dma_channel_enable(uint32_t channel)
{
    if (sg200x_ll_dma_channel_is_valid(channel))
    {
        DMA->GLOBAL.CHEN = LL_BIT(channel) | (LL_BIT(channel) << DMA_CHANNEL_WRITE_ENABLE_SHIFT);
    }
}

/**
 * @brief 请求中止一个 DMA 通道 / Request that one DMA channel be aborted.
 *
 * @param channel DMA 通道编号，范围为 0 到 7 / DMA channel index from 0 through 7.
 * @note 此函数只发出请求；复用资源前须等待通道停止。
 *       This function only issues a request; wait for disable completion before reusing resources.
 */
static inline void sg200x_ll_dma_channel_abort(uint32_t channel)
{
    if (sg200x_ll_dma_channel_is_valid(channel))
    {
        DMA->GLOBAL.CHABORT = LL_BIT(channel) | (LL_BIT(channel) << DMA_CHANNEL_WRITE_ENABLE_SHIFT);
    }
}

/**
 * @brief 请求中止掩码指定的 DMA 通道 / Request that the selected DMA channels be aborted.
 *
 * @param channels DMA 通道位掩码，使用低 8 位 / DMA channel mask using the low eight bits.
 * @note 此函数只发出请求；复用资源前须等待通道停止。
 *       This function only issues a request; wait for disable completion before reusing resources.
 * @note 掩码仅可包含低 8 位，调用者负责共享通道所有权。
 *       The mask may contain only the low eight bits; the caller manages shared-channel ownership.
 */
static inline void sg200x_ll_dma_channels_abort(uint32_t channels)
{
    DMA->GLOBAL.CHABORT = channels | (channels << DMA_CHANNEL_WRITE_ENABLE_SHIFT);
}

/**
 * @brief 获取通道所使用的请求重映射寄存器 / Get the request-remap register containing a channel's field.
 *
 * @param channel DMA 通道编号，范围为 0 到 7 / DMA channel index from 0 through 7.
 * @return TOP DMA_REMAP0 或 DMA_REMAP1 的地址 / Address of TOP DMA_REMAP0 or DMA_REMAP1.
 * @pre channel 必须在 0 到 7 之间；此辅助函数不检查范围。
 *      channel must be from 0 through 7; this helper does not check bounds.
 */
static inline volatile uint32_t *sg200x_ll_dma_remap_reg(uint32_t channel)
{
    return channel < DMA_REMAP_CHANNELS_PER_REGISTER ? &TOP->DMA_REMAP0 : &TOP->DMA_REMAP1;
}

/**
 * @brief 设置通道的外设请求映射并置位映射使能。
 *        Set a channel's peripheral-request mapping and enable remapping.
 *
 * @param channel DMA 通道编号，范围为 0 到 7 / DMA channel index from 0 through 7.
 * @param request 外设 DMA 请求编号 / Peripheral DMA request number.
 * @note 通道无效或 request 超出 6 位字段时不写寄存器；有效输入会执行读改写。
 *       Invalid channels or requests exceeding the six-bit field cause no write; valid inputs use
 *       read-modify-write.
 */
static inline void sg200x_ll_dma_request_route_set(uint32_t channel, uint32_t request)
{
    if (channel >= DMA_CHANNEL_COUNT || request > DMA_REMAP_REQUEST_MASK)
    {
        return;
    }
    volatile uint32_t *reg = sg200x_ll_dma_remap_reg(channel);
    const uint32_t shift = (channel % DMA_REMAP_CHANNELS_PER_REGISTER) * DMA_REMAP_REQUEST_SHIFT;
    uint32_t value = *reg;
    value = (value & ~(DMA_REMAP_REQUEST_MASK << shift)) | (request << shift) | DMA_REMAP_ENABLE_BIT;
    *reg = value;
}

/**
 * @brief 读取通道的外设请求映射 / Read a channel's peripheral-request mapping.
 *
 * @param channel DMA 通道编号，范围为 0 到 7 / DMA channel index from 0 through 7.
 * @return 请求编号；通道无效时返回 0 / Request number, or zero for an invalid channel.
 */
static inline uint32_t sg200x_ll_dma_request_route_get(uint32_t channel)
{
    if (channel >= DMA_CHANNEL_COUNT)
    {
        return 0U;
    }
    const volatile uint32_t *reg = sg200x_ll_dma_remap_reg(channel);
    return (*reg >> ((channel % DMA_REMAP_CHANNELS_PER_REGISTER) * DMA_REMAP_REQUEST_SHIFT)) &
           DMA_REMAP_REQUEST_MASK;
}

/**
 * @brief 清除指定的 DMA 通道中断状态 / Clear selected DMA channel interrupt status bits.
 *
 * @param channel DMA 通道编号，范围为 0 到 7 / DMA channel index from 0 through 7.
 * @param status 写入 INTCLEAR 的清除位掩码，置 1 清除对应状态。
 *        Mask written to INTCLEAR; each set bit clears its status.
 */
static inline void sg200x_ll_dma_channel_interrupt_clear(uint32_t channel, uint32_t status)
{
    DMA_Channel_Type *const ch = sg200x_ll_dma_channel_get(channel);
    if (ch != (DMA_Channel_Type *)0)
    {
        ch->INTCLEAR = status;
    }
}

/**
 * @brief 读取 DMA 通道中断状态 / Read DMA channel interrupt status.
 *
 * @param channel DMA 通道编号，范围为 0 到 7 / DMA channel index from 0 through 7.
 * @return INTSTATUS 值；通道无效时返回 0 / INTSTATUS value, or zero for an invalid channel.
 */
static inline uint32_t sg200x_ll_dma_channel_interrupt_status_get(uint32_t channel)
{
    DMA_Channel_Type *const ch = sg200x_ll_dma_channel_get(channel);
    return ch == (DMA_Channel_Type *)0 ? 0U : ch->INTSTATUS;
}

/**
 * @brief 同时配置中断状态锁存和中断信号使能。
 *        Configure interrupt-status latching and interrupt-signal enables together.
 *
 * @param channel DMA 通道编号，范围为 0 到 7 / DMA channel index from 0 through 7.
 * @param mask 同时写入 INTSTATUS_EN 和 INTSIGNAL_EN 的使能掩码。
 *        Enable mask written to both INTSTATUS_EN and INTSIGNAL_EN.
 */
static inline void sg200x_ll_dma_channel_interrupt_configure(uint32_t channel, uint32_t mask)
{
    DMA_Channel_Type *const ch = sg200x_ll_dma_channel_get(channel);
    if (ch != (DMA_Channel_Type *)0)
    {
        ch->INTSTATUS_EN = mask;
        ch->INTSIGNAL_EN = mask;
    }
}

/**
 * @brief 编码 DMA 描述符的 64 位 CTL 字段 / Encode the 64-bit CTL field of a DMA descriptor.
 *
 * @param direction DMA 传输方向 / DMA transfer direction.
 * @param width DMA 元素宽度，字节或半字 / DMA item width: byte or half-word.
 * @param mode 普通或循环传输模式 / Normal or circular transfer mode.
 * @param lli_address 保留的描述符地址参数，当前不参与 CTL 编码。
 *        Reserved descriptor-address argument; it does not currently affect CTL encoding.
 * @return CTL 编码，不访问硬件 / CTL encoding without hardware access.
 * @note 普通模式设置 LAST 和 VALID；循环模式只设置 VALID。
 *       Normal mode sets LAST and VALID; circular mode sets VALID only.
 * @note 此编码辅助函数假定枚举和通道参数有效；不负责资源分配或缓存同步。
 *       This encoding helper assumes valid enums and channel arguments; it does not allocate resources or
 *       synchronize caches.
 */
static inline uint64_t sg200x_ll_dma_control_build(
    sg200x_ll_dma_direction_t direction, sg200x_ll_dma_width_t width, sg200x_ll_dma_mode_t mode,
    uintptr_t lli_address
)
{
    uint64_t control = DMA_CTL_IOC_BLOCK_BIT | DMA_CTL_SMS_BIT | DMA_CTL_DMS_BIT;
    control |= (uint64_t)width << DMA_CTL_SRC_WIDTH_SHIFT;
    control |= (uint64_t)width << DMA_CTL_DST_WIDTH_SHIFT;
    if (direction == LL_DMA_MEMORY_TO_PERIPHERAL)
    {
        control |= DMA_CTL_DINC_BIT;
    }
    else if (direction == LL_DMA_PERIPHERAL_TO_MEMORY)
    {
        control |= DMA_CTL_SINC_BIT;
    }
    if (mode == LL_DMA_MODE_CIRCULAR)
    {
        (void)lli_address;
        control |= DMA_CTL_LLI_VALID_BIT;
    }
    else
    {
        control |= DMA_CTL_LLI_LAST_BIT | DMA_CTL_LLI_VALID_BIT;
    }
    return control;
}

/**
 * @brief 编码 DMA 通道的 64 位 CFG 字段 / Encode a DMA channel's 64-bit CFG field.
 *
 * @param direction DMA 传输方向 / DMA transfer direction.
 * @param channel DMA 通道编号，范围为 0 到 7 / DMA channel index from 0 through 7.
 * @return CFG 编码，不访问硬件 / CFG encoding without hardware access.
 * @note 默认最高优先级和最大未完成请求数；外设握手选择使用通道编号。
 *       Use maximum priority and outstanding-request settings; peripheral handshakes select the channel
 *       index.
 * @note 此编码辅助函数假定枚举和通道参数有效；不负责资源分配或缓存同步。
 *       This encoding helper assumes valid enums and channel arguments; it does not allocate resources or
 *       synchronize caches.
 */
static inline uint64_t sg200x_ll_dma_config_build(sg200x_ll_dma_direction_t direction, uint32_t channel)
{
    uint64_t config = DMA_CFG_SRC_MULTIBLK_LLI | DMA_CFG_DST_MULTIBLK_LLI;
    config |= (uint64_t)DMA_CFG_PRIORITY_MAX << DMA_CFG_PRIORITY_SHIFT;
    config |= (uint64_t)DMA_CFG_OSR_MAX << DMA_CFG_SRC_OSR_SHIFT;
    config |= (uint64_t)DMA_CFG_OSR_MAX << DMA_CFG_DST_OSR_SHIFT;
    if (direction == LL_DMA_MEMORY_TO_PERIPHERAL)
    {
        config |= 1ULL << DMA_CFG_TTFC_SHIFT;
    }
    else if (direction == LL_DMA_PERIPHERAL_TO_MEMORY)
    {
        config |= 2ULL << DMA_CFG_TTFC_SHIFT;
    }
    if (direction != LL_DMA_MEMORY_TO_MEMORY)
    {
        config |= (uint64_t)channel << DMA_CFG_SRC_PER_SHIFT;
        config |= (uint64_t)channel << DMA_CFG_DST_PER_SHIFT;
    }
    return config;
}

/**
 * @brief 检查描述符地址是否非零且按 64 字节对齐。
 *        Check that a descriptor address is nonzero and 64-byte aligned.
 *
 * @param address 待检查或配置的地址 / Address to check or configure.
 * @return 地址满足描述符对齐约束时为 true / True when the address meets descriptor-alignment requirements.
 */
static inline bool sg200x_ll_dma_lli_address_is_valid(uintptr_t address)
{
    return address != 0U && (address & (DMA_LLI_ALIGNMENT - 1U)) == 0U;
}

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @brief 填充 DMA 默认初始化参数 / Fill default DMA initialization parameters.
     *
     * @param[out] config 接收默认配置的结构体指针，可为空。
     *        Destination for default configuration; may be null.
     * @note 默认按字节执行普通内存复制，优先级为 0；调用者仍需填写地址和数量。空指针不执行操作。
     *       Defaults are byte-wide normal memory copy at priority zero; supply addresses and a count. A null
     *       pointer is ignored.
     */
    void sg200x_ll_dma_struct_init(sg200x_ll_dma_init_t *config);

    /**
     * @brief 初始化调用者拥有的已停止通道及其描述符。
     *        Initialize a caller-owned stopped channel and its descriptor.
     *
     * @param channel DMA 通道编号，范围为 0 到 7 / DMA channel index from 0 through 7.
     * @param[out] lli 调用者提供且按 64 字节对齐的描述符存储。
     *        Caller-provided, 64-byte-aligned descriptor storage.
     * @param[in] config 调用者提供的初始化配置 / Caller-provided initialization configuration.
     * @return 成功返回 true；参数无效或通道活动时返回 false。
     *         True on success; false for invalid arguments or an active channel.
     * @note 失败不修改寄存器或描述符。成功不启动通道、不打开全局控制器，也不改变 TOP 中断路由。
     *       Failure changes neither registers nor the descriptor. Success does not start the channel, enable
     *       the global controller, or change TOP interrupt routing.
     * @note 启用通道前由调用者按方向维护载荷缓存并写回描述符；循环模式 next 为 0 时自链接。
     *       Before enabling the channel, maintain payload caches by direction and clean the descriptor;
     *       circular mode self-links when next is zero.
     */
    bool sg200x_ll_dma_init(uint32_t channel, DMA_LLI_Type *lli, const sg200x_ll_dma_init_t *config);

    /**
     * @brief 清理一个已停止的 DMA 通道 / Clear one stopped DMA channel.
     *
     * @param channel DMA 通道编号，范围为 0 到 7 / DMA channel index from 0 through 7.
     * @return 成功返回 true；通道无效或仍活动时返回 false。
     *         True on success; false for an invalid or active channel.
     * @note 调用者先请求停止并等待完成；其他通道、全局控制器和请求映射保持不变。
     *       Request disable and wait for completion first; other channels, the global controller, and request
     *       mappings are preserved.
     */
    bool sg200x_ll_dma_deinit(uint32_t channel);

    /**
     * @brief 构造一个调用者提供存储的 DMA 链表描述符。
     *        Build one DMA linked-list item in caller-provided storage.
     *
     * @param[out] lli 调用者提供且按 64 字节对齐的描述符存储。
     *        Caller-provided, 64-byte-aligned descriptor storage.
     * @param source 数据源地址 / Source data address.
     * @param destination 数据目的地址 / Destination data address.
     * @param count 数据元素数量，范围为 1 到 DMA_BLOCK_TRANSFER_MAX。
     *        Item count from 1 through DMA_BLOCK_TRANSFER_MAX.
     * @param direction DMA 传输方向 / DMA transfer direction.
     * @param width DMA 元素宽度，字节或半字 / DMA item width: byte or half-word.
     * @param mode 普通或循环传输模式 / Normal or circular transfer mode.
     * @param next 下一描述符地址；非零值必须按 64 字节对齐。
     *        Next descriptor address; nonzero values must be 64-byte aligned.
     * @return 地址、计数和链接检查通过时返回 true；否则不修改描述符并返回 false。
     *         True when address, count, and link checks pass; otherwise false without modifying the
     *         descriptor.
     * @pre direction、width、mode 必须有效，数据地址按元素宽度对齐；此底层构造器不验证这些条件。
     *      direction, width, and mode must be valid and data addresses aligned to the item width; this
     *      low-level builder does not validate these conditions.
     * @note 所有非零链接按 64 字节对齐；循环模式必须提供非零 next。提交前写回描述符缓存。
     *       All nonzero links are 64-byte aligned; circular mode requires a nonzero next. Clean the
     *       descriptor cache before submission.
     */
    bool sg200x_ll_dma_lli_build(
        DMA_LLI_Type *lli, uintptr_t source, uintptr_t destination, uint32_t count,
        sg200x_ll_dma_direction_t direction, sg200x_ll_dma_width_t width, sg200x_ll_dma_mode_t mode,
        uintptr_t next
    );

    /**
     * @brief 写入已停止通道的 CFG 和链表起始地址。
     *        Write CFG and the linked-list address of a stopped channel.
     *
     * @param channel DMA 通道编号，范围为 0 到 7 / DMA channel index from 0 through 7.
     * @param config 由 sg200x_ll_dma_config_build 构造的通道 CFG 编码。
     *        Channel CFG encoding produced by sg200x_ll_dma_config_build.
     * @param lli_address 非零且按 64 字节对齐的链表描述符地址。
     *        Nonzero, 64-byte-aligned linked-list descriptor address.
     * @return 通道和描述符地址有效时返回 true；否则不写寄存器。
     *         True for a valid channel and descriptor address; otherwise no registers are written.
     * @pre 调用者必须先停止通道；本函数只检查编号和描述符地址。
     *      The caller must first stop the channel; this function only checks the index and descriptor
     *      address.
     */
    bool sg200x_ll_dma_channel_configure(uint32_t channel, uint64_t config, uintptr_t lli_address);

    /**
     * @brief 有界轮询等待 DMA 通道停止。
     *        Poll a DMA channel for disable completion with a bounded attempt count.
     *
     * @param channel DMA 通道编号，范围为 0 到 7 / DMA channel index from 0 through 7.
     * @param attempts 最多读取使能寄存器的次数；0 表示不轮询。
     *        Maximum enable-register reads; zero performs no polling.
     * @return 观察到通道停止时为 true；通道无效或次数耗尽时为 false。
     *         True when disabled is observed; false for an invalid channel or exhausted attempts.
     */
    bool sg200x_ll_dma_channel_wait_disabled(uint32_t channel, uint32_t attempts);

#ifdef __cplusplus
}
#endif

/**
 * @brief 获取普通或循环传输使用的 DMA 中断掩码 / Get the DMA interrupt mask for normal or circular transfers.
 *
 * @param mode 普通或循环传输模式 / Normal or circular transfer mode.
 * @return 块完成及错误位；普通模式还包含传输完成位。
 *         Block-completion and error bits, plus transfer-completion in normal mode.
 */
static inline uint32_t sg200x_ll_dma_interrupt_mask(sg200x_ll_dma_mode_t mode)
{
    return DMA_INT_BLOCK_DONE_BIT | DMA_INT_ERROR_MASK |
           (mode == LL_DMA_MODE_NORMAL ? DMA_INT_TRANSFER_DONE_BIT : 0U);
}

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @brief 有界等待指定 DMA 通道集合全部停止。
     *        Wait for all selected DMA channels to stop with a bounded attempt count.
     * @param channels 待停止的通道位掩码 / Mask of channels to await.
     * @param attempts 最大状态读取次数，零表示不轮询 / Maximum status reads; zero performs no polling.
     * @return 全部停止时为 true；掩码无效或超时为 false。
     *        True when all have stopped; false for an invalid mask or timeout.
     */
    bool sg200x_ll_dma_channels_wait_disabled(uint32_t channels, uint32_t attempts);

#ifdef __cplusplus
}
#endif
