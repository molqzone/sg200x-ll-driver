#pragma once

#include <stddef.h>
#include <stdint.h>

/// @brief Main crystal frequency in Hz.
static constexpr auto XTAL_FREQ_HZ = 25'000'000UL;
/// @brief RTC crystal frequency in Hz.
static constexpr auto RTC_XTAL_FREQ_HZ = 32'768UL;

/// @brief Number of main-domain GPIO controllers.
static constexpr auto GPIO_COUNT = 4U;

/// @brief Pins per GPIO port.
static constexpr auto GPIO_PIN_COUNT = 32U;

/// @brief Number of RTC-domain GPIO controllers.
static constexpr auto RTC_GPIO_COUNT = 1U;
/// @brief Number of main-domain UART controllers.
static constexpr auto UART_COUNT = 5U;
/// @brief Number of RTC-domain UART controllers.
static constexpr auto RTC_UART_COUNT = 1U;
/// @brief Number of main-domain I2C controllers.
static constexpr auto I2C_COUNT = 5U;
/// @brief Number of RTC-domain I2C controllers.
static constexpr auto RTC_I2C_COUNT = 1U;
/// @brief Number of SSI controllers.
static constexpr auto SPI_COUNT = 4U;
/// @brief Number of PWM controllers.
static constexpr auto PWM_CONTROLLER_COUNT = 4U;

/// @brief Channels per PWM controller.
static constexpr auto PWM_CHANNELS_PER_CONTROLLER = 4U;

/// @brief Total channels across all PWM controllers.
static constexpr auto PWM_CHANNEL_COUNT = 16U;
/// @brief Number of system timers.
static constexpr auto TIMER_COUNT = 8U;
/// @brief Number of main-domain watchdogs.
static constexpr auto WDT_COUNT = 3U;
/// @brief Number of RTC-domain watchdogs.
static constexpr auto RTC_WDT_COUNT = 1U;
/// @brief Total SARADC instances across main and RTC domains.
static constexpr auto SARADC_COUNT = 2U;
/// @brief Input channels per SARADC instance.
static constexpr auto SARADC_CHANNEL_COUNT = 3U;
/// @brief Total AXI DMA channels.
static constexpr auto DMA_CHANNEL_COUNT = 8U;

/// @brief Machine-mode global interrupt-enable bit.
static constexpr auto LL_MSTATUS_MIE_BIT = (1UL << 3);

/// @brief Supervisor software interrupt-enable bit.
static constexpr auto LL_MIE_SSIE_BIT = (1UL << 1);
/// @brief Machine software interrupt-enable bit.
static constexpr auto LL_MIE_MSIE_BIT = (1UL << 3);
/// @brief Supervisor timer interrupt-enable bit.
static constexpr auto LL_MIE_STIE_BIT = (1UL << 5);
/// @brief Machine timer interrupt-enable bit.
static constexpr auto LL_MIE_MTIE_BIT = (1UL << 7);
/// @brief Supervisor external interrupt-enable bit.
static constexpr auto LL_MIE_SEIE_BIT = (1UL << 9);
/// @brief Machine external interrupt-enable bit used by the PLIC.
static constexpr auto LL_MIE_MEIE_BIT = (1UL << 11);

/// @brief C906L data-cache line size in bytes.
static constexpr auto LL_DCACHE_LINE_SIZE = 64U;

/// @brief Base address of APB_MAILBOX registers.
static constexpr auto APB_MAILBOX_BASE = 0x0190'0000UL;
/// @brief Base address of the mailbox register buffer, 1 KB above the mailbox.
static constexpr auto MAILBOX_BUFF_BASE = 0x0190'0400UL;
/// @brief Base address of the hardware spinlock registers.
static constexpr auto SPINLOCK_BASE = 0x0190'00C0UL;
/// @brief Base address of the security subsystem.
static constexpr auto SEC_BASE = 0x0200'0000UL;
/// @brief Base address of the on-chip SRAM.
static constexpr auto SRAM_BASE = 0x0E00'0000UL;
/// @brief Base address of AP_SYSTEM_CTRL registers.
static constexpr auto AP_SYSTEM_CTRL_BASE = 0x0190'1000UL;
/// @brief Base address of CRYPTO_DMA registers.
static constexpr auto CRYPTO_DMA_BASE = 0x0206'0000UL;
/// @brief Base address of TRNG registers.
static constexpr auto TRNG_BASE = 0x0207'0000UL;

/// @brief Base address of TOP_MISC registers.
static constexpr auto TOP_MISC_BASE = 0x0300'0000UL;
/// @brief Base address of PINMUX registers.
static constexpr auto PINMUX_BASE = 0x0300'1000UL;
/// @brief Base address of the IOBLK pad-control registers, a sub-block of the
static constexpr auto IOBLK_BASE = 0x0300'1800UL;
/// @brief Base address of CLKGEN registers.
static constexpr auto CLKGEN_BASE = 0x0300'2000UL;

/// @brief Size of the CLKGEN register-address window.
static constexpr auto CLKGEN_REGISTER_BYTES = 0x1'000U;

/// @brief Base address of PLL_G2 registers.
static constexpr auto PLL_G2_BASE = 0x0300'2800UL;
/// @brief Base address of PLL_G6 registers.
static constexpr auto PLL_G6_BASE = 0x0300'2900UL;
/// @brief Base address of RSTGEN registers.
static constexpr auto RSTGEN_BASE = 0x0300'3000UL;

/// @brief Base address of WDT0 registers.
static constexpr auto WDT0_BASE = 0x0301'0000UL;
/// @brief Base address of WDT1 registers.
static constexpr auto WDT1_BASE = 0x0301'1000UL;
/// @brief Base address of WDT2 registers.
static constexpr auto WDT2_BASE = 0x0301'2000UL;
/// @brief Base address of GPIO0 registers.
static constexpr auto GPIO0_BASE = 0x0302'0000UL;
/// @brief Base address of GPIO1 registers.
static constexpr auto GPIO1_BASE = 0x0302'1000UL;
/// @brief Base address of GPIO2 registers.
static constexpr auto GPIO2_BASE = 0x0302'2000UL;
/// @brief Base address of GPIO3 registers.
static constexpr auto GPIO3_BASE = 0x0302'3000UL;
/// @brief Base address of WGN0 registers.
static constexpr auto WGN0_BASE = 0x0303'0000UL;
/// @brief Base address of WGN1 registers.
static constexpr auto WGN1_BASE = 0x0303'1000UL;
/// @brief Base address of WGN2 registers.
static constexpr auto WGN2_BASE = 0x0303'2000UL;
/// @brief Base address of KEYSCAN registers.
static constexpr auto KEYSCAN_BASE = 0x0304'0000UL;
/// @brief Base address of EFUSE registers.
static constexpr auto EFUSE_BASE = 0x0305'0000UL;
/// @brief Base address of PWM0 registers.
static constexpr auto PWM0_BASE = 0x0306'0000UL;
/// @brief Base address of PWM1 registers.
static constexpr auto PWM1_BASE = 0x0306'1000UL;
/// @brief Base address of PWM2 registers.
static constexpr auto PWM2_BASE = 0x0306'2000UL;
/// @brief Base address of PWM3 registers.
static constexpr auto PWM3_BASE = 0x0306'3000UL;
/// @brief Base address of TIMER registers.
static constexpr auto TIMER_BASE = 0x030A'0000UL;
/// @brief Base address of TEMPSEN registers.
static constexpr auto TEMPSEN_BASE = 0x030E'0000UL;
/// @brief Base address of SARADC registers.
static constexpr auto SARADC_BASE = 0x030F'0000UL;

/// @brief Base address of I2C0 registers.
static constexpr auto I2C0_BASE = 0x0400'0000UL;
/// @brief Base address of I2C1 registers.
static constexpr auto I2C1_BASE = 0x0401'0000UL;
/// @brief Base address of I2C2 registers.
static constexpr auto I2C2_BASE = 0x0402'0000UL;
/// @brief Base address of I2C3 registers.
static constexpr auto I2C3_BASE = 0x0403'0000UL;
/// @brief Base address of I2C4 registers.
static constexpr auto I2C4_BASE = 0x0404'0000UL;
/// @brief Base address of SPI_NAND registers.
static constexpr auto SPI_NAND_BASE = 0x0406'0000UL;
/// @brief Base address of the memory-mapped SPI NOR flash window (256 MB). The
static constexpr auto SPI_NOR_FLASH_BASE = 0x1000'0000UL;
/// @brief Base address of ETH0 registers.
static constexpr auto ETH0_BASE = 0x0407'0000UL;
/// @brief Base address of I2S0 registers.
static constexpr auto I2S0_BASE = 0x0410'0000UL;
/// @brief Base address of I2S_GLOBAL registers.
static constexpr auto I2S_GLOBAL_BASE = 0x0410'8000UL;
/// @brief Base address of I2S1 registers.
static constexpr auto I2S1_BASE = 0x0411'0000UL;
/// @brief Base address of I2S2 registers.
static constexpr auto I2S2_BASE = 0x0412'0000UL;
/// @brief Base address of I2S3 registers.
static constexpr auto I2S3_BASE = 0x0413'0000UL;
/// @brief Base address of UART0 registers.
static constexpr auto UART0_BASE = 0x0414'0000UL;
/// @brief Base address of UART1 registers.
static constexpr auto UART1_BASE = 0x0415'0000UL;
/// @brief Base address of UART2 registers.
static constexpr auto UART2_BASE = 0x0416'0000UL;
/// @brief Base address of UART3 registers.
static constexpr auto UART3_BASE = 0x0417'0000UL;
/// @brief Base address of SPI0 registers.
static constexpr auto SPI0_BASE = 0x0418'0000UL;
/// @brief Base address of SPI1 registers.
static constexpr auto SPI1_BASE = 0x0419'0000UL;
/// @brief Base address of SPI2 registers.
static constexpr auto SPI2_BASE = 0x041A'0000UL;
/// @brief Base address of SPI3 registers.
static constexpr auto SPI3_BASE = 0x041B'0000UL;
/// @brief Base address of UART4 registers.
static constexpr auto UART4_BASE = 0x041C'0000UL;
/// @brief Base address of AUDSRC registers.
static constexpr auto AUDSRC_BASE = 0x041D'0000UL;
/// @brief Base address of EMMC registers.
static constexpr auto EMMC_BASE = 0x0430'0000UL;
/// @brief Base address of SD0 registers.
static constexpr auto SD0_BASE = 0x0431'0000UL;
/// @brief Base address of SD1 registers.
static constexpr auto SD1_BASE = 0x0432'0000UL;
/// @brief Base address of DMA registers.
static constexpr auto DMA_BASE = 0x0433'0000UL;
/// @brief Base address of USB registers.
static constexpr auto USB_BASE = 0x0434'0000UL;

/// @brief Base address of RTC_TIMER registers.
static constexpr auto RTC_TIMER_BASE = 0x0502'0000UL;
/// @brief Base address of RTC_GPIO registers.
static constexpr auto RTC_GPIO_BASE = 0x0502'1000UL;
/// @brief Base address of RTC_UART registers.
static constexpr auto RTC_UART_BASE = 0x0502'2000UL;
/// @brief Base address of RTC_INTR registers.
static constexpr auto RTC_INTR_BASE = 0x0502'3000UL;
/// @brief Base address of RTC_MBOX registers.
static constexpr auto RTC_MBOX_BASE = 0x0502'4000UL;
/// @brief Base address of RTC_CTRL registers.
static constexpr auto RTC_CTRL_BASE = 0x0502'5000UL;
/// @brief Base address of RTC_CORE registers.
static constexpr auto RTC_CORE_BASE = 0x0502'6000UL;
/// @brief Base address of RTC_MACRO registers.
static constexpr auto RTC_MACRO_BASE = 0x0502'6400UL;
/// @brief Base address of RTC_IO registers.
static constexpr auto RTC_IO_BASE = 0x0502'7000UL;
/// @brief Base address of RTC_OSC registers.
static constexpr auto RTC_OSC_BASE = 0x0502'8000UL;
/// @brief Base address of RTC_32KLESS registers.
static constexpr auto RTC_32KLESS_BASE = 0x0502'A000UL;
/// @brief Base address of RTC_I2C registers.
static constexpr auto RTC_I2C_BASE = 0x0502'B000UL;
/// @brief Base address of RTC_SARADC registers.
static constexpr auto RTC_SARADC_BASE = 0x0502'C000UL;
/// @brief Base address of RTC_WDT registers.
static constexpr auto RTC_WDT_BASE = 0x0502'D000UL;

/// @brief Base address of the RTC-domain IRRX registers.
static constexpr auto IRRX_BASE = 0x0502'E000UL;

/// @brief Base address of PLIC registers.
static constexpr auto PLIC_BASE_ADDRESS = 0x7000'0000UL;

/// @brief Maximum permitted PLIC priority value.
static constexpr auto PLIC_PRIORITY_MAX = 7UL;
/// @brief Size of the C906L PLIC source-ID space, including reserved ID zero.
static constexpr auto NUM_IRQ = 62UL;
/// @brief Byte offset of PLIC priority register array.
static constexpr auto PLIC_PRIORITY_OFFSET = 0x0000UL;
/// @brief Byte offset of PLIC pending-interrupt bit array.
static constexpr auto PLIC_PENDING_OFFSET = 0x1000UL;
/// @brief Byte offset of PLIC context source-enable bit array.
static constexpr auto PLIC_ENABLE_OFFSET = 0x2000UL;
/// @brief Byte offset of PLIC context priority threshold.
static constexpr auto PLIC_THRESHOLD_OFFSET = 0x20'0000UL;
/// @brief Byte offset of PLIC claim-and-completion register.
static constexpr auto PLIC_CLAIM_OFFSET = 0x20'0004UL;

/// @brief Interrupt sources represented by one PLIC bitmap word.
static constexpr auto PLIC_IRQS_PER_WORD = 32U;
/// @brief Bitmap words needed to cover the C906L source-ID space.
static constexpr auto PLIC_IRQ_WORD_COUNT = ((NUM_IRQ + PLIC_IRQS_PER_WORD - 1U) / PLIC_IRQS_PER_WORD);

/**
 * @brief PLIC register block for C906L context zero.
 *
 * @note The SDK also defines PLIC_Type/PLIC; this view names the C906L context explicitly.
 * @see Sophgo, SDK, arch/riscv64/include/irq.h, register-definition source）。
 */
typedef struct
{
    volatile uint32_t PRIORITY[NUM_IRQ]; /*!< interrupt-source priority
                                                      array, Address offset: 0x000 */
    uint32_t RESERVED_PRIORITY
        [(PLIC_PENDING_OFFSET - NUM_IRQ * sizeof(uint32_t)) /
         sizeof(uint32_t)]; /*!< padding for an unexposed area, Address offset: 0x0F8 */
    volatile const uint32_t PENDING[PLIC_IRQ_WORD_COUNT]; /*!< pending-interrupt
                                                               bit array, Address offset: 0x1000 */
    uint32_t RESERVED_PENDING
        [(PLIC_ENABLE_OFFSET - PLIC_PENDING_OFFSET) / sizeof(uint32_t) -
         PLIC_IRQ_WORD_COUNT]; /*!< padding for an unexposed area, Address offset: 0x1008 */
    volatile uint32_t ENABLE[PLIC_IRQ_WORD_COUNT]; /*!< context-zero source-enable
                                                        bit array, Address offset: 0x2000 */
    uint32_t RESERVED_ENABLE
        [(PLIC_THRESHOLD_OFFSET - PLIC_ENABLE_OFFSET) / sizeof(uint32_t) -
         PLIC_IRQ_WORD_COUNT];        /*!< padding for an unexposed area, Address offset: 0x2008 */
    volatile uint32_t THRESHOLD;      /*!< context priority threshold, Address offset: 0x200000 */
    volatile uint32_t CLAIM_COMPLETE; /*!< read-to-claim,
                                                      write-to-complete register, Address offset: 0x200004 */
} PLIC_C906L_Type;

static_assert(offsetof(PLIC_C906L_Type, PENDING) == PLIC_PENDING_OFFSET);
static_assert(offsetof(PLIC_C906L_Type, ENABLE) == PLIC_ENABLE_OFFSET);
static_assert(offsetof(PLIC_C906L_Type, THRESHOLD) == PLIC_THRESHOLD_OFFSET);
static_assert(offsetof(PLIC_C906L_Type, CLAIM_COMPLETE) == PLIC_CLAIM_OFFSET);

/**
 * @brief PLIC_C906L register-instance pointer.
 */
#define PLIC_C906L ((PLIC_C906L_Type *)(uintptr_t)PLIC_BASE_ADDRESS)

/**
 * @brief Number of contiguous 32-bit pin-function selectors.
 *
 * @note Selectors run contiguously from CAM_MCLK0 at offset 0x000 to GPIO_ZQ at 0x1D0.
 * @see Sophgo, SDK, cv181x_reg_fmux_gpio.h, register-definition source）。
 */
static constexpr auto PINMUX_FUNCTION_COUNT = 117U;

/**
 * @brief Contiguous pin-function selector registers.
 *
 * @see Sophgo, SDK, cv181x_reg_fmux_gpio.h, register-definition source）。
 */
typedef struct
{
    volatile uint32_t FUNCTION[PINMUX_FUNCTION_COUNT]; /*!< pin-function selector
                                                            register array, Address offset: 0x000 */
} PINMUX_Type;

static_assert(sizeof(PINMUX_Type) == 0x1D4U);

/**
 * @brief PINMUX register-instance pointer.
 */
#define PINMUX ((PINMUX_Type *)(uintptr_t)PINMUX_BASE)

/// @brief Bit mask for pin-function selector field.
static constexpr auto PINMUX_FUNCTION_MASK = 0x07UL;

/// @brief Function-selector offset of CAM_MCLK0.
static constexpr auto PINMUX_CAM_MCLK0_OFFSET = 0x000UL;
/// @brief Function-selector offset of CAM_PD0.
static constexpr auto PINMUX_CAM_PD0_OFFSET = 0x004UL;
/// @brief Function-selector offset of CAM_RST0.
static constexpr auto PINMUX_CAM_RST0_OFFSET = 0x008UL;
/// @brief Function-selector offset of CAM_MCLK1.
static constexpr auto PINMUX_CAM_MCLK1_OFFSET = 0x00CUL;
/// @brief Function-selector offset of CAM_PD1.
static constexpr auto PINMUX_CAM_PD1_OFFSET = 0x010UL;
/// @brief Function-selector offset of IIC3_SCL.
static constexpr auto PINMUX_IIC3_SCL_OFFSET = 0x014UL;
/// @brief Function-selector offset of IIC3_SDA.
static constexpr auto PINMUX_IIC3_SDA_OFFSET = 0x018UL;
/// @brief Function-selector offset of SD0_CLK.
static constexpr auto PINMUX_SD0_CLK_OFFSET = 0x01CUL;
/// @brief Function-selector offset of SD0_CMD.
static constexpr auto PINMUX_SD0_CMD_OFFSET = 0x020UL;
/// @brief Function-selector offset of SD0_D0.
static constexpr auto PINMUX_SD0_D0_OFFSET = 0x024UL;
/// @brief Function-selector offset of SD0_D1.
static constexpr auto PINMUX_SD0_D1_OFFSET = 0x028UL;
/// @brief Function-selector offset of SD0_D2.
static constexpr auto PINMUX_SD0_D2_OFFSET = 0x02CUL;
/// @brief Function-selector offset of SD0_D3.
static constexpr auto PINMUX_SD0_D3_OFFSET = 0x030UL;
/// @brief Function-selector offset of SD0_CD.
static constexpr auto PINMUX_SD0_CD_OFFSET = 0x034UL;
/// @brief Function-selector offset of SD0_PWR_EN.
static constexpr auto PINMUX_SD0_PWR_EN_OFFSET = 0x038UL;
/// @brief Function-selector offset of SPK_EN.
static constexpr auto PINMUX_SPK_EN_OFFSET = 0x03CUL;
/// @brief Function-selector offset of UART0_TX.
static constexpr auto PINMUX_UART0_TX_OFFSET = 0x040UL;
/// @brief Function-selector offset of UART0_RX.
static constexpr auto PINMUX_UART0_RX_OFFSET = 0x044UL;
/// @brief Function-selector offset of EMMC_RSTN.
static constexpr auto PINMUX_EMMC_RSTN_OFFSET = 0x048UL;
/// @brief Function-selector offset of EMMC_DAT2.
static constexpr auto PINMUX_EMMC_DAT2_OFFSET = 0x04CUL;
/// @brief Function-selector offset of EMMC_CLK.
static constexpr auto PINMUX_EMMC_CLK_OFFSET = 0x050UL;
/// @brief Function-selector offset of EMMC_DAT0.
static constexpr auto PINMUX_EMMC_DAT0_OFFSET = 0x054UL;
/// @brief Function-selector offset of EMMC_DAT3.
static constexpr auto PINMUX_EMMC_DAT3_OFFSET = 0x058UL;
/// @brief Function-selector offset of EMMC_CMD.
static constexpr auto PINMUX_EMMC_CMD_OFFSET = 0x05CUL;
/// @brief Function-selector offset of EMMC_DAT1.
static constexpr auto PINMUX_EMMC_DAT1_OFFSET = 0x060UL;
/// @brief Function-selector offset of JTAG_CPU_TMS.
static constexpr auto PINMUX_JTAG_CPU_TMS_OFFSET = 0x064UL;
/// @brief Function-selector offset of JTAG_CPU_TCK.
static constexpr auto PINMUX_JTAG_CPU_TCK_OFFSET = 0x068UL;
/// @brief Function-selector offset of JTAG_CPU_TRST.
static constexpr auto PINMUX_JTAG_CPU_TRST_OFFSET = 0x06CUL;
/// @brief Function-selector offset of IIC0_SCL.
static constexpr auto PINMUX_IIC0_SCL_OFFSET = 0x070UL;
/// @brief Function-selector offset of IIC0_SDA.
static constexpr auto PINMUX_IIC0_SDA_OFFSET = 0x074UL;
/// @brief Function-selector offset of AUX0.
static constexpr auto PINMUX_AUX0_OFFSET = 0x078UL;
/// @brief Function-selector offset of PWR_VBAT_DET.
static constexpr auto PINMUX_PWR_VBAT_DET_OFFSET = 0x07CUL;
/// @brief Function-selector offset of PWR_RSTN.
static constexpr auto PINMUX_PWR_RSTN_OFFSET = 0x080UL;
/// @brief Function-selector offset of PWR_SEQ1.
static constexpr auto PINMUX_PWR_SEQ1_OFFSET = 0x084UL;
/// @brief Function-selector offset of PWR_SEQ2.
static constexpr auto PINMUX_PWR_SEQ2_OFFSET = 0x088UL;
/// @brief Function-selector offset of PWR_SEQ3.
static constexpr auto PINMUX_PWR_SEQ3_OFFSET = 0x08CUL;
/// @brief Function-selector offset of PWR_WAKEUP0.
static constexpr auto PINMUX_PWR_WAKEUP0_OFFSET = 0x090UL;
/// @brief Function-selector offset of PWR_WAKEUP1.
static constexpr auto PINMUX_PWR_WAKEUP1_OFFSET = 0x094UL;
/// @brief Function-selector offset of PWR_BUTTON1.
static constexpr auto PINMUX_PWR_BUTTON1_OFFSET = 0x098UL;
/// @brief Function-selector offset of PWR_ON.
static constexpr auto PINMUX_PWR_ON_OFFSET = 0x09CUL;
/// @brief Function-selector offset of XTAL_XIN.
static constexpr auto PINMUX_XTAL_XIN_OFFSET = 0x0A0UL;
/// @brief Function-selector offset of PWR_GPIO0.
static constexpr auto PINMUX_PWR_GPIO0_OFFSET = 0x0A4UL;
/// @brief Function-selector offset of PWR_GPIO1.
static constexpr auto PINMUX_PWR_GPIO1_OFFSET = 0x0A8UL;
/// @brief Function-selector offset of PWR_GPIO2.
static constexpr auto PINMUX_PWR_GPIO2_OFFSET = 0x0ACUL;
/// @brief Function-selector offset of CLK32K.
static constexpr auto PINMUX_CLK32K_OFFSET = 0x0B0UL;
/// @brief Function-selector offset of CLK25M.
static constexpr auto PINMUX_CLK25M_OFFSET = 0x0B4UL;
/// @brief Function-selector offset of IIC2_SCL.
static constexpr auto PINMUX_IIC2_SCL_OFFSET = 0x0B8UL;
/// @brief Function-selector offset of IIC2_SDA.
static constexpr auto PINMUX_IIC2_SDA_OFFSET = 0x0BCUL;
/// @brief Function-selector offset of UART2_TX.
static constexpr auto PINMUX_UART2_TX_OFFSET = 0x0C0UL;
/// @brief Function-selector offset of UART2_RTS.
static constexpr auto PINMUX_UART2_RTS_OFFSET = 0x0C4UL;
/// @brief Function-selector offset of UART2_RX.
static constexpr auto PINMUX_UART2_RX_OFFSET = 0x0C8UL;
/// @brief Function-selector offset of UART2_CTS.
static constexpr auto PINMUX_UART2_CTS_OFFSET = 0x0CCUL;
/// @brief Function-selector offset of SD1_D3.
static constexpr auto PINMUX_SD1_D3_OFFSET = 0x0D0UL;
/// @brief Function-selector offset of SD1_D2.
static constexpr auto PINMUX_SD1_D2_OFFSET = 0x0D4UL;
/// @brief Function-selector offset of SD1_D1.
static constexpr auto PINMUX_SD1_D1_OFFSET = 0x0D8UL;
/// @brief Function-selector offset of SD1_D0.
static constexpr auto PINMUX_SD1_D0_OFFSET = 0x0DCUL;
/// @brief Function-selector offset of SD1_CMD.
static constexpr auto PINMUX_SD1_CMD_OFFSET = 0x0E0UL;
/// @brief Function-selector offset of SD1_CLK.
static constexpr auto PINMUX_SD1_CLK_OFFSET = 0x0E4UL;
/// @brief Function-selector offset of RSTN.
static constexpr auto PINMUX_RSTN_OFFSET = 0x0E8UL;
/// @brief Function-selector offset of PWM0_BUCK.
static constexpr auto PINMUX_PWM0_BUCK_OFFSET = 0x0ECUL;
/// @brief Function-selector offset of ADC3.
static constexpr auto PINMUX_ADC3_OFFSET = 0x0F0UL;
/// @brief Function-selector offset of ADC2.
static constexpr auto PINMUX_ADC2_OFFSET = 0x0F4UL;
/// @brief Function-selector offset of ADC1.
static constexpr auto PINMUX_ADC1_OFFSET = 0x0F8UL;
/// @brief Function-selector offset of USB_ID.
static constexpr auto PINMUX_USB_ID_OFFSET = 0x0FCUL;
/// @brief Function-selector offset of USB_VBUS_EN.
static constexpr auto PINMUX_USB_VBUS_EN_OFFSET = 0x100UL;
/// @brief Function-selector offset of PKG_TYPE0.
static constexpr auto PINMUX_PKG_TYPE0_OFFSET = 0x104UL;
/// @brief Function-selector offset of USB_VBUS_DET.
static constexpr auto PINMUX_USB_VBUS_DET_OFFSET = 0x108UL;
/// @brief Function-selector offset of PKG_TYPE1.
static constexpr auto PINMUX_PKG_TYPE1_OFFSET = 0x10CUL;
/// @brief Function-selector offset of PKG_TYPE2.
static constexpr auto PINMUX_PKG_TYPE2_OFFSET = 0x110UL;
/// @brief Function-selector offset of MUX_SPI1_MISO.
static constexpr auto PINMUX_MUX_SPI1_MISO_OFFSET = 0x114UL;
/// @brief Function-selector offset of MUX_SPI1_MOSI.
static constexpr auto PINMUX_MUX_SPI1_MOSI_OFFSET = 0x118UL;
/// @brief Function-selector offset of MUX_SPI1_CS.
static constexpr auto PINMUX_MUX_SPI1_CS_OFFSET = 0x11CUL;
/// @brief Function-selector offset of MUX_SPI1_SCK.
static constexpr auto PINMUX_MUX_SPI1_SCK_OFFSET = 0x120UL;
/// @brief Function-selector offset of PAD_ETH_TXM.
static constexpr auto PINMUX_PAD_ETH_TXM_OFFSET = 0x124UL;
/// @brief Function-selector offset of PAD_ETH_TXP.
static constexpr auto PINMUX_PAD_ETH_TXP_OFFSET = 0x128UL;
/// @brief Function-selector offset of PAD_ETH_RXM.
static constexpr auto PINMUX_PAD_ETH_RXM_OFFSET = 0x12CUL;
/// @brief Function-selector offset of PAD_ETH_RXP.
static constexpr auto PINMUX_PAD_ETH_RXP_OFFSET = 0x130UL;
/// @brief Function-selector offset of VIVO_D10.
static constexpr auto PINMUX_VIVO_D10_OFFSET = 0x134UL;
/// @brief Function-selector offset of VIVO_D9.
static constexpr auto PINMUX_VIVO_D9_OFFSET = 0x138UL;
/// @brief Function-selector offset of VIVO_D8.
static constexpr auto PINMUX_VIVO_D8_OFFSET = 0x13CUL;
/// @brief Function-selector offset of VIVO_D7.
static constexpr auto PINMUX_VIVO_D7_OFFSET = 0x140UL;
/// @brief Function-selector offset of VIVO_D6.
static constexpr auto PINMUX_VIVO_D6_OFFSET = 0x144UL;
/// @brief Function-selector offset of VIVO_D5.
static constexpr auto PINMUX_VIVO_D5_OFFSET = 0x148UL;
/// @brief Function-selector offset of VIVO_D4.
static constexpr auto PINMUX_VIVO_D4_OFFSET = 0x14CUL;
/// @brief Function-selector offset of VIVO_D3.
static constexpr auto PINMUX_VIVO_D3_OFFSET = 0x150UL;
/// @brief Function-selector offset of VIVO_D2.
static constexpr auto PINMUX_VIVO_D2_OFFSET = 0x154UL;
/// @brief Function-selector offset of VIVO_D1.
static constexpr auto PINMUX_VIVO_D1_OFFSET = 0x158UL;
/// @brief Function-selector offset of VIVO_D0.
static constexpr auto PINMUX_VIVO_D0_OFFSET = 0x15CUL;
/// @brief Function-selector offset of VIVO_CLK.
static constexpr auto PINMUX_VIVO_CLK_OFFSET = 0x160UL;
/// @brief Function-selector offset of PAD_MIPIRX5N.
static constexpr auto PINMUX_PAD_MIPIRX5N_OFFSET = 0x164UL;
/// @brief Function-selector offset of PAD_MIPIRX5P.
static constexpr auto PINMUX_PAD_MIPIRX5P_OFFSET = 0x168UL;
/// @brief Function-selector offset of PAD_MIPIRX4N.
static constexpr auto PINMUX_PAD_MIPIRX4N_OFFSET = 0x16CUL;
/// @brief Function-selector offset of PAD_MIPIRX4P.
static constexpr auto PINMUX_PAD_MIPIRX4P_OFFSET = 0x170UL;
/// @brief Function-selector offset of PAD_MIPIRX3N.
static constexpr auto PINMUX_PAD_MIPIRX3N_OFFSET = 0x174UL;
/// @brief Function-selector offset of PAD_MIPIRX3P.
static constexpr auto PINMUX_PAD_MIPIRX3P_OFFSET = 0x178UL;
/// @brief Function-selector offset of PAD_MIPIRX2N.
static constexpr auto PINMUX_PAD_MIPIRX2N_OFFSET = 0x17CUL;
/// @brief Function-selector offset of PAD_MIPIRX2P.
static constexpr auto PINMUX_PAD_MIPIRX2P_OFFSET = 0x180UL;
/// @brief Function-selector offset of PAD_MIPIRX1N.
static constexpr auto PINMUX_PAD_MIPIRX1N_OFFSET = 0x184UL;
/// @brief Function-selector offset of PAD_MIPIRX1P.
static constexpr auto PINMUX_PAD_MIPIRX1P_OFFSET = 0x188UL;
/// @brief Function-selector offset of PAD_MIPIRX0N.
static constexpr auto PINMUX_PAD_MIPIRX0N_OFFSET = 0x18CUL;
/// @brief Function-selector offset of PAD_MIPIRX0P.
static constexpr auto PINMUX_PAD_MIPIRX0P_OFFSET = 0x190UL;
/// @brief Function-selector offset of PAD_MIPI_TXM4.
static constexpr auto PINMUX_PAD_MIPI_TXM4_OFFSET = 0x194UL;
/// @brief Function-selector offset of PAD_MIPI_TXP4.
static constexpr auto PINMUX_PAD_MIPI_TXP4_OFFSET = 0x198UL;
/// @brief Function-selector offset of PAD_MIPI_TXM3.
static constexpr auto PINMUX_PAD_MIPI_TXM3_OFFSET = 0x19CUL;
/// @brief Function-selector offset of PAD_MIPI_TXP3.
static constexpr auto PINMUX_PAD_MIPI_TXP3_OFFSET = 0x1A0UL;
/// @brief Function-selector offset of PAD_MIPI_TXM2.
static constexpr auto PINMUX_PAD_MIPI_TXM2_OFFSET = 0x1A4UL;
/// @brief Function-selector offset of PAD_MIPI_TXP2.
static constexpr auto PINMUX_PAD_MIPI_TXP2_OFFSET = 0x1A8UL;
/// @brief Function-selector offset of PAD_MIPI_TXM1.
static constexpr auto PINMUX_PAD_MIPI_TXM1_OFFSET = 0x1ACUL;
/// @brief Function-selector offset of PAD_MIPI_TXP1.
static constexpr auto PINMUX_PAD_MIPI_TXP1_OFFSET = 0x1B0UL;
/// @brief Function-selector offset of PAD_MIPI_TXM0.
static constexpr auto PINMUX_PAD_MIPI_TXM0_OFFSET = 0x1B4UL;
/// @brief Function-selector offset of PAD_MIPI_TXP0.
static constexpr auto PINMUX_PAD_MIPI_TXP0_OFFSET = 0x1B8UL;
/// @brief Function-selector offset of PAD_AUD_AINL_MIC.
static constexpr auto PINMUX_PAD_AUD_AINL_MIC_OFFSET = 0x1BCUL;
/// @brief Function-selector offset of PAD_AUD_AINR_MIC.
static constexpr auto PINMUX_PAD_AUD_AINR_MIC_OFFSET = 0x1C0UL;
/// @brief Function-selector offset of PAD_AUD_AOUTL.
static constexpr auto PINMUX_PAD_AUD_AOUTL_OFFSET = 0x1C4UL;
/// @brief Function-selector offset of PAD_AUD_AOUTR.
static constexpr auto PINMUX_PAD_AUD_AOUTR_OFFSET = 0x1C8UL;
/// @brief Function-selector offset of GPIO_RTX.
static constexpr auto PINMUX_GPIO_RTX_OFFSET = 0x1CCUL;
/// @brief Function-selector offset of GPIO_ZQ.
static constexpr auto PINMUX_GPIO_ZQ_OFFSET = 0x1D0UL;
/// @brief GPIOA14 function encoding on SD0_PWR_EN.
static constexpr auto PINMUX_SD0_PWR_EN_GPIOA14_FUNCTION = 3U;
/// @brief GPIOA22 function encoding on EMMC_CLK.
static constexpr auto PINMUX_EMMC_CLK_GPIOA22_FUNCTION = 3U;
/// @brief GPIOA23 function encoding on EMMC_CMD.
static constexpr auto PINMUX_EMMC_CMD_GPIOA23_FUNCTION = 3U;
/// @brief GPIOA24 function encoding on EMMC_DAT1.
static constexpr auto PINMUX_EMMC_DAT1_GPIOA24_FUNCTION = 3U;
/// @brief GPIOA25 function encoding on EMMC_DAT0.
static constexpr auto PINMUX_EMMC_DAT0_GPIOA25_FUNCTION = 3U;
/// @brief RTC GPIO18 mask corresponding to SD1_D3.
static constexpr auto PINMUX_SD1_D3_GPIO_MASK = (1UL << 18);

/// @brief Mux encoding selecting GPIOA26 on EMMC_DAT2.
static constexpr auto PINMUX_EMMC_DAT2_GPIOA26_FUNCTION = 3U;
/// @brief GPIOA26 mask corresponding to EMMC_DAT2.
static constexpr auto PINMUX_EMMC_DAT2_GPIOA26_MASK = (1UL << 26);
/// @brief Mux encoding selecting SPI2_CS on SD1_D3.
static constexpr auto PINMUX_SD1_D3_SPI2_CS_FUNCTION = 1U;
/// @brief Mux encoding selecting GPIO18 on SD1_D3.
static constexpr auto PINMUX_SD1_D3_GPIO18_FUNCTION = 3U;
/// @brief Mux encoding selecting GPIO21 on SD1_D0.
static constexpr auto PINMUX_SD1_D0_GPIO21_FUNCTION = 3U;
/// @brief Mux encoding selecting GPIO22 on SD1_CMD.
static constexpr auto PINMUX_SD1_CMD_GPIO22_FUNCTION = 3U;
/// @brief Mux encoding selecting GPIO23 on SD1_CLK.
static constexpr auto PINMUX_SD1_CLK_GPIO23_FUNCTION = 3U;
/// @brief GPIO pin mask corresponding to SD1_D0.
static constexpr auto PINMUX_SD1_D0_GPIO_MASK = (1UL << 21);
/// @brief GPIO pin mask corresponding to SD1_CMD.
static constexpr auto PINMUX_SD1_CMD_GPIO_MASK = (1UL << 22);
/// @brief GPIO pin mask corresponding to SD1_CLK.
static constexpr auto PINMUX_SD1_CLK_GPIO_MASK = (1UL << 23);
/// @brief Bit mask for SD1 GPIO pad group.
static constexpr auto PINMUX_SD1_GPIO_PAD_MASK =
    (PINMUX_SD1_D0_GPIO_MASK | PINMUX_SD1_CMD_GPIO_MASK | PINMUX_SD1_CLK_GPIO_MASK);
/// @brief Byte offset of TOP SD1 pad-bank selector register.
static constexpr auto TOP_SD1_SELECT_OFFSET = 0x294UL;
/// @brief Bit for TOP SD1 alternate-MIPI-path selection.
static constexpr auto TOP_SD1_MIPI_SELECT_BIT = (1UL << 10);

/// @brief Function encodings for ADC1.
static constexpr auto PINMUX_ADC1_ADC1_FUNCTION = 0U;     /*!< Function 0 of ADC1 selects (ADC1). */
static constexpr auto PINMUX_ADC1_XGPIOB3_FUNCTION = 3U;  /*!< Function 3 of ADC1 selects XGPIOB[3]. */
static constexpr auto PINMUX_ADC1_KEY_COL2_FUNCTION = 4U; /*!< Function 4 of ADC1 selects KEY_COL2. */

/// @brief Function encodings for AUX0.
static constexpr auto PINMUX_AUX0_AUX0_FUNCTION = 0U;      /*!< Function 0 of AUX0 selects AUX0. */
static constexpr auto PINMUX_AUX0_XGPIOA30_FUNCTION = 3U;  /*!< Function 3 of AUX0 selects XGPIOA[30]. */
static constexpr auto PINMUX_AUX0_IIS1_MCLK_FUNCTION = 4U; /*!< Function 4 of AUX0 selects IIS1_MCLK. */
static constexpr auto PINMUX_AUX0_VO_D31_FUNCTION = 5U;    /*!< Function 5 of AUX0 selects VO_D[31]. */
static constexpr auto PINMUX_AUX0_WG1_D1_FUNCTION = 6U;    /*!< Function 6 of AUX0 selects WG1_D1. */
static constexpr auto PINMUX_AUX0_DBG12_FUNCTION = 7U;     /*!< Function 7 of AUX0 selects DBG[12]. */

/// @brief Function encodings for EMMC_CLK.
static constexpr auto PINMUX_EMMC_CLK_EMMC_CLK_FUNCTION = 0U; /*!< Function 0 of EMMC_CLK selects EMMC_CLK. */
static constexpr auto PINMUX_EMMC_CLK_SPINOR_SCK_FUNCTION =
    1U; /*!< Function 1 of EMMC_CLK selects SPINOR_SCK. */
static constexpr auto PINMUX_EMMC_CLK_SPINAND_CLK_FUNCTION =
    2U; /*!< Function 2 of EMMC_CLK selects SPINAND_CLK. */
static constexpr auto PINMUX_EMMC_CLK_XGPIOA22_FUNCTION =
    3U; /*!< Function 3 of EMMC_CLK selects XGPIOA[22]. */

/// @brief Function encodings for EMMC_CMD.
static constexpr auto PINMUX_EMMC_CMD_EMMC_CMD_FUNCTION = 0U; /*!< Function 0 of EMMC_CMD selects EMMC_CMD. */
static constexpr auto PINMUX_EMMC_CMD_SPINOR_MISO_FUNCTION =
    1U; /*!< Function 1 of EMMC_CMD selects SPINOR_MISO. */
static constexpr auto PINMUX_EMMC_CMD_SPINAND_MISO_FUNCTION =
    2U; /*!< Function 2 of EMMC_CMD selects SPINAND_MISO. */
static constexpr auto PINMUX_EMMC_CMD_XGPIOA23_FUNCTION =
    3U; /*!< Function 3 of EMMC_CMD selects XGPIOA[23]. */

/// @brief Function encodings for EMMC_DAT0.
static constexpr auto PINMUX_EMMC_DAT0_EMMC_DAT0_FUNCTION =
    0U; /*!< Function 0 of EMMC_DAT0 selects EMMC_DAT[0]. */
static constexpr auto PINMUX_EMMC_DAT0_SPINOR_MOSI_FUNCTION =
    1U; /*!< Function 1 of EMMC_DAT0 selects SPINOR_MOSI. */
static constexpr auto PINMUX_EMMC_DAT0_SPINAND_MOSI_FUNCTION =
    2U; /*!< Function 2 of EMMC_DAT0 selects SPINAND_MOSI. */
static constexpr auto PINMUX_EMMC_DAT0_XGPIOA25_FUNCTION =
    3U; /*!< Function 3 of EMMC_DAT0 selects XGPIOA[25]. */

/// @brief Function encodings for EMMC_DAT1.
static constexpr auto PINMUX_EMMC_DAT1_EMMC_DAT1_FUNCTION =
    0U; /*!< Function 0 of EMMC_DAT1 selects EMMC_DAT[1]. */
static constexpr auto PINMUX_EMMC_DAT1_SPINOR_CS_X_FUNCTION =
    1U; /*!< Function 1 of EMMC_DAT1 selects SPINOR_CS_X. */
static constexpr auto PINMUX_EMMC_DAT1_SPINAND_CS_FUNCTION =
    2U; /*!< Function 2 of EMMC_DAT1 selects SPINAND_CS. */
static constexpr auto PINMUX_EMMC_DAT1_XGPIOA24_FUNCTION =
    3U; /*!< Function 3 of EMMC_DAT1 selects XGPIOA[24]. */

/// @brief Function encodings for EMMC_DAT2.
static constexpr auto PINMUX_EMMC_DAT2_EMMC_DAT2_FUNCTION =
    0U; /*!< Function 0 of EMMC_DAT2 selects EMMC_DAT[2]. */
static constexpr auto PINMUX_EMMC_DAT2_SPINOR_HOLD_X_FUNCTION =
    1U; /*!< Function 1 of EMMC_DAT2 selects SPINOR_HOLD_X. */
static constexpr auto PINMUX_EMMC_DAT2_SPINAND_HOLD_FUNCTION =
    2U; /*!< Function 2 of EMMC_DAT2 selects SPINAND_HOLD. */
static constexpr auto PINMUX_EMMC_DAT2_XGPIOA26_FUNCTION =
    3U; /*!< Function 3 of EMMC_DAT2 selects XGPIOA[26]. */

/// @brief Function encodings for EMMC_DAT3.
static constexpr auto PINMUX_EMMC_DAT3_EMMC_DAT3_FUNCTION =
    0U; /*!< Function 0 of EMMC_DAT3 selects EMMC_DAT[3]. */
static constexpr auto PINMUX_EMMC_DAT3_SPINOR_WP_X_FUNCTION =
    1U; /*!< Function 1 of EMMC_DAT3 selects SPINOR_WP_X. */
static constexpr auto PINMUX_EMMC_DAT3_SPINAND_WP_FUNCTION =
    2U; /*!< Function 2 of EMMC_DAT3 selects SPINAND_WP. */
static constexpr auto PINMUX_EMMC_DAT3_XGPIOA27_FUNCTION =
    3U; /*!< Function 3 of EMMC_DAT3 selects XGPIOA[27]. */

/// @brief Function encodings for GPIO_RTX___EPHY_RTX.
static constexpr auto PINMUX_GPIO_RTX___EPHY_RTX_XGPIOB23_FUNCTION =
    3U; /*!< Function 3 of GPIO_RTX___EPHY_RTX selects XGPIOB[23]. */
static constexpr auto PINMUX_GPIO_RTX___EPHY_RTX_PWM1_FUNCTION =
    4U; /*!< Function 4 of GPIO_RTX___EPHY_RTX selects PWM[1]. */
static constexpr auto PINMUX_GPIO_RTX___EPHY_RTX_CAM_MCLK0_FUNCTION =
    5U; /*!< Function 5 of GPIO_RTX___EPHY_RTX selects CAM_MCLK0. */

/// @brief Function encodings for GPIO_ZQ___PAD_ZQ.
static constexpr auto PINMUX_GPIO_ZQ___PAD_ZQ_PWR_GPIO24_FUNCTION =
    3U; /*!< Function 3 of GPIO_ZQ___PAD_ZQ selects PWR_GPIO[24]. */
static constexpr auto PINMUX_GPIO_ZQ___PAD_ZQ_PWM2_FUNCTION =
    4U; /*!< Function 4 of GPIO_ZQ___PAD_ZQ selects PWM[2]. */

/// @brief Function encodings for IIC0_SCL.
static constexpr auto PINMUX_IIC0_SCL_CR_4WTDI_FUNCTION = 0U; /*!< Function 0 of IIC0_SCL selects CR_4WTDI. */
static constexpr auto PINMUX_IIC0_SCL_UART1_TX_FUNCTION = 1U; /*!< Function 1 of IIC0_SCL selects UART1_TX. */
static constexpr auto PINMUX_IIC0_SCL_UART2_TX_FUNCTION = 2U; /*!< Function 2 of IIC0_SCL selects UART2_TX. */
static constexpr auto PINMUX_IIC0_SCL_XGPIOA28_FUNCTION =
    3U;                                                     /*!< Function 3 of IIC0_SCL selects XGPIOA[28]. */
static constexpr auto PINMUX_IIC0_SCL_WG0_D0_FUNCTION = 5U; /*!< Function 5 of IIC0_SCL selects WG0_D0. */
static constexpr auto PINMUX_IIC0_SCL_DBG10_FUNCTION = 7U;  /*!< Function 7 of IIC0_SCL selects DBG[10]. */

/// @brief Function encodings for IIC0_SDA.
static constexpr auto PINMUX_IIC0_SDA_CR_4WTDO_FUNCTION = 0U; /*!< Function 0 of IIC0_SDA selects CR_4WTDO. */
static constexpr auto PINMUX_IIC0_SDA_UART1_RX_FUNCTION = 1U; /*!< Function 1 of IIC0_SDA selects UART1_RX. */
static constexpr auto PINMUX_IIC0_SDA_UART2_RX_FUNCTION = 2U; /*!< Function 2 of IIC0_SDA selects UART2_RX. */
static constexpr auto PINMUX_IIC0_SDA_XGPIOA29_FUNCTION =
    3U;                                                     /*!< Function 3 of IIC0_SDA selects XGPIOA[29]. */
static constexpr auto PINMUX_IIC0_SDA_WG0_D1_FUNCTION = 5U; /*!< Function 5 of IIC0_SDA selects WG0_D1. */
static constexpr auto PINMUX_IIC0_SDA_WG1_D0_FUNCTION = 6U; /*!< Function 6 of IIC0_SDA selects WG1_D0. */
static constexpr auto PINMUX_IIC0_SDA_DBG11_FUNCTION = 7U;  /*!< Function 7 of IIC0_SDA selects DBG[11]. */

/// @brief Function encodings for JTAG_CPU_TCK.
static constexpr auto PINMUX_JTAG_CPU_TCK_CR_4WTCK_FUNCTION =
    0U; /*!< Function 0 of JTAG_CPU_TCK selects CR_4WTCK. */
static constexpr auto PINMUX_JTAG_CPU_TCK_CAM_MCLK1_FUNCTION =
    1U; /*!< Function 1 of JTAG_CPU_TCK selects CAM_MCLK1. */
static constexpr auto PINMUX_JTAG_CPU_TCK_PWM6_FUNCTION =
    2U; /*!< Function 2 of JTAG_CPU_TCK selects PWM[6]. */
static constexpr auto PINMUX_JTAG_CPU_TCK_XGPIOA18_FUNCTION =
    3U; /*!< Function 3 of JTAG_CPU_TCK selects XGPIOA[18]. */
static constexpr auto PINMUX_JTAG_CPU_TCK_UART1_CTS_FUNCTION =
    4U; /*!< Function 4 of JTAG_CPU_TCK selects UART1_CTS. */
static constexpr auto PINMUX_JTAG_CPU_TCK_AUX1_FUNCTION = 5U; /*!< Function 5 of JTAG_CPU_TCK selects AUX1. */
static constexpr auto PINMUX_JTAG_CPU_TCK_UART1_RX_FUNCTION =
    6U; /*!< Function 6 of JTAG_CPU_TCK selects UART1_RX. */
static constexpr auto PINMUX_JTAG_CPU_TCK_VO_D29_FUNCTION =
    7U; /*!< Function 7 of JTAG_CPU_TCK selects VO_D[29]. */

/// @brief Function encodings for JTAG_CPU_TMS.
static constexpr auto PINMUX_JTAG_CPU_TMS_CR_4WTMS_FUNCTION =
    0U; /*!< Function 0 of JTAG_CPU_TMS selects CR_4WTMS. */
static constexpr auto PINMUX_JTAG_CPU_TMS_CAM_MCLK0_FUNCTION =
    1U; /*!< Function 1 of JTAG_CPU_TMS selects CAM_MCLK0. */
static constexpr auto PINMUX_JTAG_CPU_TMS_PWM7_FUNCTION =
    2U; /*!< Function 2 of JTAG_CPU_TMS selects PWM[7]. */
static constexpr auto PINMUX_JTAG_CPU_TMS_XGPIOA19_FUNCTION =
    3U; /*!< Function 3 of JTAG_CPU_TMS selects XGPIOA[19]. */
static constexpr auto PINMUX_JTAG_CPU_TMS_UART1_RTS_FUNCTION =
    4U; /*!< Function 4 of JTAG_CPU_TMS selects UART1_RTS. */
static constexpr auto PINMUX_JTAG_CPU_TMS_AUX0_FUNCTION = 5U; /*!< Function 5 of JTAG_CPU_TMS selects AUX0. */
static constexpr auto PINMUX_JTAG_CPU_TMS_UART1_TX_FUNCTION =
    6U; /*!< Function 6 of JTAG_CPU_TMS selects UART1_TX. */
static constexpr auto PINMUX_JTAG_CPU_TMS_VO_D28_FUNCTION =
    7U; /*!< Function 7 of JTAG_CPU_TMS selects VO_D[28]. */

/// @brief Function encodings for MUX_SPI1_CS.
static constexpr auto PINMUX_MUX_SPI1_CS_UART3_CTS_FUNCTION =
    1U; /*!< Function 1 of MUX_SPI1_CS selects UART3_CTS. */
static constexpr auto PINMUX_MUX_SPI1_CS_CAM_MCLK0_FUNCTION =
    2U; /*!< Function 2 of MUX_SPI1_CS selects CAM_MCLK0. */
static constexpr auto PINMUX_MUX_SPI1_CS_XGPIOB10_FUNCTION =
    3U; /*!< Function 3 of MUX_SPI1_CS selects XGPIOB[10]. */
static constexpr auto PINMUX_MUX_SPI1_CS_PWM11_FUNCTION =
    4U; /*!< Function 4 of MUX_SPI1_CS selects PWM[11]. */
static constexpr auto PINMUX_MUX_SPI1_CS_KEY_ROW3_FUNCTION =
    5U; /*!< Function 5 of MUX_SPI1_CS selects KEY_ROW3. */
static constexpr auto PINMUX_MUX_SPI1_CS_SPI1_CS_X_FUNCTION =
    6U; /*!< Function 6 of MUX_SPI1_CS selects SPI1_CS_X. */
static constexpr auto PINMUX_MUX_SPI1_CS_DBG16_FUNCTION =
    7U; /*!< Function 7 of MUX_SPI1_CS selects DBG[16]. */

/// @brief Function encodings for MUX_SPI1_MISO.
static constexpr auto PINMUX_MUX_SPI1_MISO_UART3_RTS_FUNCTION =
    1U; /*!< Function 1 of MUX_SPI1_MISO selects UART3_RTS. */
static constexpr auto PINMUX_MUX_SPI1_MISO_IIC1_SDA_FUNCTION =
    2U; /*!< Function 2 of MUX_SPI1_MISO selects IIC1_SDA. */
static constexpr auto PINMUX_MUX_SPI1_MISO_XGPIOB8_FUNCTION =
    3U; /*!< Function 3 of MUX_SPI1_MISO selects XGPIOB[8]. */
static constexpr auto PINMUX_MUX_SPI1_MISO_PWM9_FUNCTION =
    4U; /*!< Function 4 of MUX_SPI1_MISO selects PWM[9]. */
static constexpr auto PINMUX_MUX_SPI1_MISO_KEY_COL1_FUNCTION =
    5U; /*!< Function 5 of MUX_SPI1_MISO selects KEY_COL1. */
static constexpr auto PINMUX_MUX_SPI1_MISO_SPI1_SDI_FUNCTION =
    6U; /*!< Function 6 of MUX_SPI1_MISO selects SPI1_SDI. */
static constexpr auto PINMUX_MUX_SPI1_MISO_DBG14_FUNCTION =
    7U; /*!< Function 7 of MUX_SPI1_MISO selects DBG[14]. */

/// @brief Function encodings for MUX_SPI1_MOSI.
static constexpr auto PINMUX_MUX_SPI1_MOSI_UART3_RX_FUNCTION =
    1U; /*!< Function 1 of MUX_SPI1_MOSI selects UART3_RX. */
static constexpr auto PINMUX_MUX_SPI1_MOSI_IIC1_SCL_FUNCTION =
    2U; /*!< Function 2 of MUX_SPI1_MOSI selects IIC1_SCL. */
static constexpr auto PINMUX_MUX_SPI1_MOSI_XGPIOB7_FUNCTION =
    3U; /*!< Function 3 of MUX_SPI1_MOSI selects XGPIOB[7]. */
static constexpr auto PINMUX_MUX_SPI1_MOSI_PWM8_FUNCTION =
    4U; /*!< Function 4 of MUX_SPI1_MOSI selects PWM[8]. */
static constexpr auto PINMUX_MUX_SPI1_MOSI_KEY_COL0_FUNCTION =
    5U; /*!< Function 5 of MUX_SPI1_MOSI selects KEY_COL0. */
static constexpr auto PINMUX_MUX_SPI1_MOSI_SPI1_SDO_FUNCTION =
    6U; /*!< Function 6 of MUX_SPI1_MOSI selects SPI1_SDO. */
static constexpr auto PINMUX_MUX_SPI1_MOSI_DBG13_FUNCTION =
    7U; /*!< Function 7 of MUX_SPI1_MOSI selects DBG[13]. */

/// @brief Function encodings for MUX_SPI1_SCK.
static constexpr auto PINMUX_MUX_SPI1_SCK_UART3_TX_FUNCTION =
    1U; /*!< Function 1 of MUX_SPI1_SCK selects UART3_TX. */
static constexpr auto PINMUX_MUX_SPI1_SCK_CAM_MCLK1_FUNCTION =
    2U; /*!< Function 2 of MUX_SPI1_SCK selects CAM_MCLK1. */
static constexpr auto PINMUX_MUX_SPI1_SCK_XGPIOB9_FUNCTION =
    3U; /*!< Function 3 of MUX_SPI1_SCK selects XGPIOB[9]. */
static constexpr auto PINMUX_MUX_SPI1_SCK_PWM10_FUNCTION =
    4U; /*!< Function 4 of MUX_SPI1_SCK selects PWM[10]. */
static constexpr auto PINMUX_MUX_SPI1_SCK_KEY_ROW2_FUNCTION =
    5U; /*!< Function 5 of MUX_SPI1_SCK selects KEY_ROW2. */
static constexpr auto PINMUX_MUX_SPI1_SCK_SPI1_SCK_FUNCTION =
    6U; /*!< Function 6 of MUX_SPI1_SCK selects SPI1_SCK. */
static constexpr auto PINMUX_MUX_SPI1_SCK_DBG15_FUNCTION =
    7U; /*!< Function 7 of MUX_SPI1_SCK selects DBG[15]. */

/// @brief Function encodings for PAD_AUD_AINL_MIC.
static constexpr auto PINMUX_PAD_AUD_AINL_MIC_PAD_AUD_AINL_MIC_FUNCTION =
    0U; /*!< Function 0 of PAD_AUD_AINL_MIC selects */
        ///< (PAD_AUD_AINL_MIC).
static constexpr auto PINMUX_PAD_AUD_AINL_MIC_XGPIOC23_FUNCTION =
    3U; /*!< Function 3 of PAD_AUD_AINL_MIC selects XGPIOC[23]. */
static constexpr auto PINMUX_PAD_AUD_AINL_MIC_IIS1_BCLK_FUNCTION =
    4U; /*!< Function 4 of PAD_AUD_AINL_MIC selects IIS1_BCLK. */
static constexpr auto PINMUX_PAD_AUD_AINL_MIC_IIS2_BCLK_FUNCTION =
    5U; /*!< Function 5 of PAD_AUD_AINL_MIC selects IIS2_BCLK. */

/// @brief Function encodings for PAD_AUD_AOUTR.
static constexpr auto PINMUX_PAD_AUD_AOUTR_PAD_AUD_AOUTR_FUNCTION =
    0U; /*!< Function 0 of PAD_AUD_AOUTR selects (PAD_AUD_AOUTR). */
static constexpr auto PINMUX_PAD_AUD_AOUTR_XGPIOC24_FUNCTION =
    3U; /*!< Function 3 of PAD_AUD_AOUTR selects XGPIOC[24]. */
static constexpr auto PINMUX_PAD_AUD_AOUTR_IIS1_DI_FUNCTION =
    4U; /*!< Function 4 of PAD_AUD_AOUTR selects IIS1_DI. */
static constexpr auto PINMUX_PAD_AUD_AOUTR_IIS2_DO_FUNCTION =
    5U; /*!< Function 5 of PAD_AUD_AOUTR selects IIS2_DO. */
static constexpr auto PINMUX_PAD_AUD_AOUTR_IIS1_DO_FUNCTION =
    6U; /*!< Function 6 of PAD_AUD_AOUTR selects IIS1_DO. */

/// @brief Function encodings for PAD_ETH_RXM___EPHY_TXP.
static constexpr auto PINMUX_PAD_ETH_RXM___EPHY_TXP_PAD_ETH_RXM_FUNCTION =
    0U; /*!< Function 0 of PAD_ETH_RXM___EPHY_TXP selects */
        ///< (PAD_ETH_RXM).
static constexpr auto PINMUX_PAD_ETH_RXM___EPHY_TXP_UART3_CTS_FUNCTION =
    1U; /*!< UART3_CTS, Function 1 of PAD_ETH_RXM___EPHY_TXP selects */
        ///< UART3_CTS.
static constexpr auto PINMUX_PAD_ETH_RXM___EPHY_TXP_CAM_MCLK0_FUNCTION =
    2U; /*!< CAM_MCLK0, Function 2 of PAD_ETH_RXM___EPHY_TXP selects */
        ///< CAM_MCLK0.
static constexpr auto PINMUX_PAD_ETH_RXM___EPHY_TXP_XGPIOB26_FUNCTION =
    3U; /*!< XGPIOB, Function 3 of PAD_ETH_RXM___EPHY_TXP selects */
        ///< XGPIOB[26].
static constexpr auto PINMUX_PAD_ETH_RXM___EPHY_TXP_PWM14_FUNCTION =
    4U; /*!< Function 4 of PAD_ETH_RXM___EPHY_TXP selects PWM[14]. */
static constexpr auto PINMUX_PAD_ETH_RXM___EPHY_TXP_CAM_VS0_FUNCTION =
    5U; /*!< Function 5 of PAD_ETH_RXM___EPHY_TXP selects CAM_VS0. */
static constexpr auto PINMUX_PAD_ETH_RXM___EPHY_TXP_SPI1_CS_X_FUNCTION =
    6U; /*!< SPI1_CS_X, Function 6 of PAD_ETH_RXM___EPHY_TXP selects */
        ///< SPI1_CS_X.
static constexpr auto PINMUX_PAD_ETH_RXM___EPHY_TXP_IIS2_DI_FUNCTION =
    7U; /*!< Function 7 of PAD_ETH_RXM___EPHY_TXP selects IIS2_DI. */

/// @brief Function encodings for PAD_ETH_RXP___EPHY_TXN.
static constexpr auto PINMUX_PAD_ETH_RXP___EPHY_TXN_PAD_ETH_RXP_FUNCTION =
    0U; /*!< Function 0 of PAD_ETH_RXP___EPHY_TXN selects */
        ///< (PAD_ETH_RXP).
static constexpr auto PINMUX_PAD_ETH_RXP___EPHY_TXN_UART3_TX_FUNCTION =
    1U; /*!< Function 1 of PAD_ETH_RXP___EPHY_TXN selects UART3_TX. */
static constexpr auto PINMUX_PAD_ETH_RXP___EPHY_TXN_CAM_MCLK1_FUNCTION =
    2U; /*!< CAM_MCLK1, Function 2 of PAD_ETH_RXP___EPHY_TXN selects */
        ///< CAM_MCLK1.
static constexpr auto PINMUX_PAD_ETH_RXP___EPHY_TXN_XGPIOB27_FUNCTION =
    3U; /*!< XGPIOB, Function 3 of PAD_ETH_RXP___EPHY_TXN selects */
        ///< XGPIOB[27].
static constexpr auto PINMUX_PAD_ETH_RXP___EPHY_TXN_PWM15_FUNCTION =
    4U; /*!< Function 4 of PAD_ETH_RXP___EPHY_TXN selects PWM[15]. */
static constexpr auto PINMUX_PAD_ETH_RXP___EPHY_TXN_CAM_HS0_FUNCTION =
    5U; /*!< Function 5 of PAD_ETH_RXP___EPHY_TXN selects CAM_HS0. */
static constexpr auto PINMUX_PAD_ETH_RXP___EPHY_TXN_SPI1_SCK_FUNCTION =
    6U; /*!< Function 6 of PAD_ETH_RXP___EPHY_TXN selects SPI1_SCK. */
static constexpr auto PINMUX_PAD_ETH_RXP___EPHY_TXN_IIS2_DO_FUNCTION =
    7U; /*!< Function 7 of PAD_ETH_RXP___EPHY_TXN selects IIS2_DO. */

/// @brief Function encodings for PAD_ETH_TXM___EPHY_RXP.
static constexpr auto PINMUX_PAD_ETH_TXM___EPHY_RXP_PAD_ETH_TXM_FUNCTION =
    0U; /*!< Function 0 of PAD_ETH_TXM___EPHY_RXP selects */
        ///< (PAD_ETH_TXM).
static constexpr auto PINMUX_PAD_ETH_TXM___EPHY_RXP_UART3_RTS_FUNCTION =
    1U; /*!< UART3_RTS, Function 1 of PAD_ETH_TXM___EPHY_RXP selects */
        ///< UART3_RTS.
static constexpr auto PINMUX_PAD_ETH_TXM___EPHY_RXP_IIC1_SDA_FUNCTION =
    2U; /*!< Function 2 of PAD_ETH_TXM___EPHY_RXP selects IIC1_SDA. */
static constexpr auto PINMUX_PAD_ETH_TXM___EPHY_RXP_XGPIOB24_FUNCTION =
    3U; /*!< XGPIOB, Function 3 of PAD_ETH_TXM___EPHY_RXP selects */
        ///< XGPIOB[24].
static constexpr auto PINMUX_PAD_ETH_TXM___EPHY_RXP_PWM12_FUNCTION =
    4U; /*!< Function 4 of PAD_ETH_TXM___EPHY_RXP selects PWM[12]. */
static constexpr auto PINMUX_PAD_ETH_TXM___EPHY_RXP_CAM_MCLK1_FUNCTION =
    5U; /*!< CAM_MCLK1, Function 5 of PAD_ETH_TXM___EPHY_RXP selects */
        ///< CAM_MCLK1.
static constexpr auto PINMUX_PAD_ETH_TXM___EPHY_RXP_SPI1_SDI_FUNCTION =
    6U; /*!< Function 6 of PAD_ETH_TXM___EPHY_RXP selects SPI1_SDI. */
static constexpr auto PINMUX_PAD_ETH_TXM___EPHY_RXP_IIS2_BCLK_FUNCTION =
    7U; /*!< IIS2_BCLK, Function 7 of PAD_ETH_TXM___EPHY_RXP selects */
        ///< IIS2_BCLK.

/// @brief Function encodings for PAD_ETH_TXP___EPHY_RXN.
static constexpr auto PINMUX_PAD_ETH_TXP___EPHY_RXN_PAD_ETH_TXP_FUNCTION =
    0U; /*!< Function 0 of PAD_ETH_TXP___EPHY_RXN selects */
        ///< (PAD_ETH_TXP).
static constexpr auto PINMUX_PAD_ETH_TXP___EPHY_RXN_UART3_RX_FUNCTION =
    1U; /*!< Function 1 of PAD_ETH_TXP___EPHY_RXN selects UART3_RX. */
static constexpr auto PINMUX_PAD_ETH_TXP___EPHY_RXN_IIC1_SCL_FUNCTION =
    2U; /*!< Function 2 of PAD_ETH_TXP___EPHY_RXN selects IIC1_SCL. */
static constexpr auto PINMUX_PAD_ETH_TXP___EPHY_RXN_XGPIOB25_FUNCTION =
    3U; /*!< XGPIOB, Function 3 of PAD_ETH_TXP___EPHY_RXN selects */
        ///< XGPIOB[25].
static constexpr auto PINMUX_PAD_ETH_TXP___EPHY_RXN_PWM13_FUNCTION =
    4U; /*!< Function 4 of PAD_ETH_TXP___EPHY_RXN selects PWM[13]. */
static constexpr auto PINMUX_PAD_ETH_TXP___EPHY_RXN_CAM_MCLK0_FUNCTION =
    5U; /*!< CAM_MCLK0, Function 5 of PAD_ETH_TXP___EPHY_RXN selects */
        ///< CAM_MCLK0.
static constexpr auto PINMUX_PAD_ETH_TXP___EPHY_RXN_SPI1_SDO_FUNCTION =
    6U; /*!< Function 6 of PAD_ETH_TXP___EPHY_RXN selects SPI1_SDO. */
static constexpr auto PINMUX_PAD_ETH_TXP___EPHY_RXN_IIS2_LRCK_FUNCTION =
    7U; /*!< IIS2_LRCK, Function 7 of PAD_ETH_TXP___EPHY_RXN selects */
        ///< IIS2_LRCK.

/// @brief Function encodings for PAD_MIPIRX0N.
static constexpr auto PINMUX_PAD_MIPIRX0N_PAD_MIPIRX0N_FUNCTION =
    0U; /*!< Function 0 of PAD_MIPIRX0N selects (PAD_MIPIRX0N). */
static constexpr auto PINMUX_PAD_MIPIRX0N_VI0_D7_FUNCTION =
    1U; /*!< Function 1 of PAD_MIPIRX0N selects VI0_D[7]. */
static constexpr auto PINMUX_PAD_MIPIRX0N_VO_D6_FUNCTION =
    2U; /*!< Function 2 of PAD_MIPIRX0N selects VO_D[6]. */
static constexpr auto PINMUX_PAD_MIPIRX0N_XGPIOC10_FUNCTION =
    3U; /*!< Function 3 of PAD_MIPIRX0N selects XGPIOC[10]. */
static constexpr auto PINMUX_PAD_MIPIRX0N_IIC1_SCL_FUNCTION =
    4U; /*!< Function 4 of PAD_MIPIRX0N selects IIC1_SCL. */
static constexpr auto PINMUX_PAD_MIPIRX0N_CAM_MCLK1_FUNCTION =
    5U; /*!< Function 5 of PAD_MIPIRX0N selects CAM_MCLK1. */
static constexpr auto PINMUX_PAD_MIPIRX0N_DBG10_FUNCTION =
    7U; /*!< Function 7 of PAD_MIPIRX0N selects DBG[10]. */

/// @brief Function encodings for PAD_MIPIRX0P.
static constexpr auto PINMUX_PAD_MIPIRX0P_PAD_MIPIRX0P_FUNCTION =
    0U; /*!< Function 0 of PAD_MIPIRX0P selects (PAD_MIPIRX0P). */
static constexpr auto PINMUX_PAD_MIPIRX0P_VI0_D8_FUNCTION =
    1U; /*!< Function 1 of PAD_MIPIRX0P selects VI0_D[8]. */
static constexpr auto PINMUX_PAD_MIPIRX0P_VO_D5_FUNCTION =
    2U; /*!< Function 2 of PAD_MIPIRX0P selects VO_D[5]. */
static constexpr auto PINMUX_PAD_MIPIRX0P_XGPIOC11_FUNCTION =
    3U; /*!< Function 3 of PAD_MIPIRX0P selects XGPIOC[11]. */
static constexpr auto PINMUX_PAD_MIPIRX0P_CAM_MCLK0_FUNCTION =
    4U; /*!< Function 4 of PAD_MIPIRX0P selects CAM_MCLK0. */
static constexpr auto PINMUX_PAD_MIPIRX0P_DBG11_FUNCTION =
    7U; /*!< Function 7 of PAD_MIPIRX0P selects DBG[11]. */

/// @brief Function encodings for PAD_MIPIRX1N.
static constexpr auto PINMUX_PAD_MIPIRX1N_PAD_MIPIRX1N_FUNCTION =
    0U; /*!< Function 0 of PAD_MIPIRX1N selects (PAD_MIPIRX1N). */
static constexpr auto PINMUX_PAD_MIPIRX1N_VI0_D5_FUNCTION =
    1U; /*!< Function 1 of PAD_MIPIRX1N selects VI0_D[5]. */
static constexpr auto PINMUX_PAD_MIPIRX1N_VO_D8_FUNCTION =
    2U; /*!< Function 2 of PAD_MIPIRX1N selects VO_D[8]. */
static constexpr auto PINMUX_PAD_MIPIRX1N_XGPIOC8_FUNCTION =
    3U; /*!< Function 3 of PAD_MIPIRX1N selects XGPIOC[8]. */
static constexpr auto PINMUX_PAD_MIPIRX1N_KEY_ROW3_FUNCTION =
    6U; /*!< Function 6 of PAD_MIPIRX1N selects KEY_ROW3. */
static constexpr auto PINMUX_PAD_MIPIRX1N_DBG8_FUNCTION =
    7U; /*!< Function 7 of PAD_MIPIRX1N selects DBG[8]. */

/// @brief Function encodings for PAD_MIPIRX1P.
static constexpr auto PINMUX_PAD_MIPIRX1P_PAD_MIPIRX1P_FUNCTION =
    0U; /*!< Function 0 of PAD_MIPIRX1P selects (PAD_MIPIRX1P). */
static constexpr auto PINMUX_PAD_MIPIRX1P_VI0_D6_FUNCTION =
    1U; /*!< Function 1 of PAD_MIPIRX1P selects VI0_D[6]. */
static constexpr auto PINMUX_PAD_MIPIRX1P_VO_D7_FUNCTION =
    2U; /*!< Function 2 of PAD_MIPIRX1P selects VO_D[7]. */
static constexpr auto PINMUX_PAD_MIPIRX1P_XGPIOC9_FUNCTION =
    3U; /*!< Function 3 of PAD_MIPIRX1P selects XGPIOC[9]. */
static constexpr auto PINMUX_PAD_MIPIRX1P_IIC1_SDA_FUNCTION =
    4U; /*!< Function 4 of PAD_MIPIRX1P selects IIC1_SDA. */
static constexpr auto PINMUX_PAD_MIPIRX1P_KEY_ROW2_FUNCTION =
    6U; /*!< Function 6 of PAD_MIPIRX1P selects KEY_ROW2. */
static constexpr auto PINMUX_PAD_MIPIRX1P_DBG9_FUNCTION =
    7U; /*!< Function 7 of PAD_MIPIRX1P selects DBG[9]. */

/// @brief Function encodings for PAD_MIPIRX2N.
static constexpr auto PINMUX_PAD_MIPIRX2N_PAD_MIPIRX2N_FUNCTION =
    0U; /*!< Function 0 of PAD_MIPIRX2N selects (PAD_MIPIRX2N). */
static constexpr auto PINMUX_PAD_MIPIRX2N_VI0_D3_FUNCTION =
    1U; /*!< Function 1 of PAD_MIPIRX2N selects VI0_D[3]. */
static constexpr auto PINMUX_PAD_MIPIRX2N_VO_D10_FUNCTION =
    2U; /*!< Function 2 of PAD_MIPIRX2N selects VO_D[10]. */
static constexpr auto PINMUX_PAD_MIPIRX2N_XGPIOC6_FUNCTION =
    3U; /*!< Function 3 of PAD_MIPIRX2N selects XGPIOC[6]. */
static constexpr auto PINMUX_PAD_MIPIRX2N_VI1_D17_FUNCTION =
    4U; /*!< Function 4 of PAD_MIPIRX2N selects VI1_D[17]. */
static constexpr auto PINMUX_PAD_MIPIRX2N_IIC4_SCL_FUNCTION =
    5U; /*!< Function 5 of PAD_MIPIRX2N selects IIC4_SCL. */
static constexpr auto PINMUX_PAD_MIPIRX2N_DBG6_FUNCTION =
    7U; /*!< Function 7 of PAD_MIPIRX2N selects DBG[6]. */

/// @brief Function encodings for PAD_MIPIRX2P.
static constexpr auto PINMUX_PAD_MIPIRX2P_PAD_MIPIRX2P_FUNCTION =
    0U; /*!< Function 0 of PAD_MIPIRX2P selects (PAD_MIPIRX2P). */
static constexpr auto PINMUX_PAD_MIPIRX2P_VI0_D4_FUNCTION =
    1U; /*!< Function 1 of PAD_MIPIRX2P selects VI0_D[4]. */
static constexpr auto PINMUX_PAD_MIPIRX2P_VO_D9_FUNCTION =
    2U; /*!< Function 2 of PAD_MIPIRX2P selects VO_D[9]. */
static constexpr auto PINMUX_PAD_MIPIRX2P_XGPIOC7_FUNCTION =
    3U; /*!< Function 3 of PAD_MIPIRX2P selects XGPIOC[7]. */
static constexpr auto PINMUX_PAD_MIPIRX2P_VI1_D18_FUNCTION =
    4U; /*!< Function 4 of PAD_MIPIRX2P selects VI1_D[18]. */
static constexpr auto PINMUX_PAD_MIPIRX2P_IIC4_SDA_FUNCTION =
    5U; /*!< Function 5 of PAD_MIPIRX2P selects IIC4_SDA. */
static constexpr auto PINMUX_PAD_MIPIRX2P_DBG7_FUNCTION =
    7U; /*!< Function 7 of PAD_MIPIRX2P selects DBG[7]. */

/// @brief Function encodings for PAD_MIPIRX3N.
static constexpr auto PINMUX_PAD_MIPIRX3N_CR_2WTMS_FUNCTION =
    0U; /*!< Function 0 of PAD_MIPIRX3N selects CR_2WTMS. */
static constexpr auto PINMUX_PAD_MIPIRX3N_VI0_D1_FUNCTION =
    1U; /*!< Function 1 of PAD_MIPIRX3N selects VI0_D[1]. */
static constexpr auto PINMUX_PAD_MIPIRX3N_VI1_D15_FUNCTION =
    2U; /*!< Function 2 of PAD_MIPIRX3N selects VI1_D[15]. */
static constexpr auto PINMUX_PAD_MIPIRX3N_XGPIOC4_FUNCTION =
    3U; /*!< Function 3 of PAD_MIPIRX3N selects XGPIOC[4]. */
static constexpr auto PINMUX_PAD_MIPIRX3N_CAM_MCLK0_FUNCTION =
    4U; /*!< Function 4 of PAD_MIPIRX3N selects CAM_MCLK0. */
static constexpr auto PINMUX_PAD_MIPIRX3N_MUX_SPI1_MISO_FUNCTION =
    7U; /*!< Function 7 of PAD_MIPIRX3N selects MUX_SPI1_MISO. */

/// @brief Function encodings for PAD_MIPIRX3P.
static constexpr auto PINMUX_PAD_MIPIRX3P_CR_2WTCK_FUNCTION =
    0U; /*!< Function 0 of PAD_MIPIRX3P selects CR_2WTCK. */
static constexpr auto PINMUX_PAD_MIPIRX3P_VI0_D2_FUNCTION =
    1U; /*!< Function 1 of PAD_MIPIRX3P selects VI0_D[2]. */
static constexpr auto PINMUX_PAD_MIPIRX3P_VI1_D16_FUNCTION =
    2U; /*!< Function 2 of PAD_MIPIRX3P selects VI1_D[16]. */
static constexpr auto PINMUX_PAD_MIPIRX3P_XGPIOC5_FUNCTION =
    3U; /*!< Function 3 of PAD_MIPIRX3P selects XGPIOC[5]. */
static constexpr auto PINMUX_PAD_MIPIRX3P_MUX_SPI1_MOSI_FUNCTION =
    7U; /*!< Function 7 of PAD_MIPIRX3P selects MUX_SPI1_MOSI. */

/// @brief Function encodings for PAD_MIPIRX4N.
static constexpr auto PINMUX_PAD_MIPIRX4N_CR_SCL0_FUNCTION =
    0U; /*!< Function 0 of PAD_MIPIRX4N selects CR_SCL0. */
static constexpr auto PINMUX_PAD_MIPIRX4N_VI0_CLK_FUNCTION =
    1U; /*!< Function 1 of PAD_MIPIRX4N selects VI0_CLK. */
static constexpr auto PINMUX_PAD_MIPIRX4N_VI1_D13_FUNCTION =
    2U; /*!< Function 2 of PAD_MIPIRX4N selects VI1_D[13]. */
static constexpr auto PINMUX_PAD_MIPIRX4N_XGPIOC2_FUNCTION =
    3U; /*!< Function 3 of PAD_MIPIRX4N selects XGPIOC[2]. */
static constexpr auto PINMUX_PAD_MIPIRX4N_IIC1_SDA_FUNCTION =
    4U; /*!< Function 4 of PAD_MIPIRX4N selects IIC1_SDA. */
static constexpr auto PINMUX_PAD_MIPIRX4N_CAM_MCLK0_FUNCTION =
    5U; /*!< Function 5 of PAD_MIPIRX4N selects CAM_MCLK0. */
static constexpr auto PINMUX_PAD_MIPIRX4N_KEY_ROW0_FUNCTION =
    6U; /*!< Function 6 of PAD_MIPIRX4N selects KEY_ROW0. */
static constexpr auto PINMUX_PAD_MIPIRX4N_MUX_SPI1_SCK_FUNCTION =
    7U; /*!< Function 7 of PAD_MIPIRX4N selects MUX_SPI1_SCK. */

/// @brief Function encodings for PAD_MIPIRX4P.
static constexpr auto PINMUX_PAD_MIPIRX4P_CR_SDA0_FUNCTION =
    0U; /*!< Function 0 of PAD_MIPIRX4P selects CR_SDA0. */
static constexpr auto PINMUX_PAD_MIPIRX4P_VI0_D0_FUNCTION =
    1U; /*!< Function 1 of PAD_MIPIRX4P selects VI0_D[0]. */
static constexpr auto PINMUX_PAD_MIPIRX4P_VI1_D14_FUNCTION =
    2U; /*!< Function 2 of PAD_MIPIRX4P selects VI1_D[14]. */
static constexpr auto PINMUX_PAD_MIPIRX4P_XGPIOC3_FUNCTION =
    3U; /*!< Function 3 of PAD_MIPIRX4P selects XGPIOC[3]. */
static constexpr auto PINMUX_PAD_MIPIRX4P_IIC1_SCL_FUNCTION =
    4U; /*!< Function 4 of PAD_MIPIRX4P selects IIC1_SCL. */
static constexpr auto PINMUX_PAD_MIPIRX4P_CAM_MCLK1_FUNCTION =
    5U; /*!< Function 5 of PAD_MIPIRX4P selects CAM_MCLK1. */
static constexpr auto PINMUX_PAD_MIPIRX4P_KEY_ROW1_FUNCTION =
    6U; /*!< Function 6 of PAD_MIPIRX4P selects KEY_ROW1. */
static constexpr auto PINMUX_PAD_MIPIRX4P_MUX_SPI1_CS_FUNCTION =
    7U; /*!< Function 7 of PAD_MIPIRX4P selects MUX_SPI1_CS. */

/// @brief Function encodings for PAD_MIPI_TXM0.
static constexpr auto PINMUX_PAD_MIPI_TXM0_PAD_MIPI_TXM0_FUNCTION =
    0U; /*!< Function 0 of PAD_MIPI_TXM0 selects (PAD_MIPI_TXM0). */
static constexpr auto PINMUX_PAD_MIPI_TXM0_VI0_D9_FUNCTION =
    1U; /*!< Function 1 of PAD_MIPI_TXM0 selects VI0_D[9]. */
static constexpr auto PINMUX_PAD_MIPI_TXM0_VO_D4_FUNCTION =
    2U; /*!< Function 2 of PAD_MIPI_TXM0 selects VO_D[4]. */
static constexpr auto PINMUX_PAD_MIPI_TXM0_XGPIOC12_FUNCTION =
    3U; /*!< Function 3 of PAD_MIPI_TXM0 selects XGPIOC[12]. */
static constexpr auto PINMUX_PAD_MIPI_TXM0_CAM_MCLK1_FUNCTION =
    4U; /*!< Function 4 of PAD_MIPI_TXM0 selects CAM_MCLK1. */
static constexpr auto PINMUX_PAD_MIPI_TXM0_PWM14_FUNCTION =
    5U; /*!< Function 5 of PAD_MIPI_TXM0 selects PWM[14]. */
static constexpr auto PINMUX_PAD_MIPI_TXM0_CAM_VS0_FUNCTION =
    6U; /*!< Function 6 of PAD_MIPI_TXM0 selects CAM_VS0. */
static constexpr auto PINMUX_PAD_MIPI_TXM0_DBG12_FUNCTION =
    7U; /*!< Function 7 of PAD_MIPI_TXM0 selects DBG[12]. */

/// @brief Function encodings for PAD_MIPI_TXM1.
static constexpr auto PINMUX_PAD_MIPI_TXM1_CR_2WTMS_FUNCTION =
    0U; /*!< Function 0 of PAD_MIPI_TXM1 selects CR_2WTMS. */
static constexpr auto PINMUX_PAD_MIPI_TXM1_VI0_D11_FUNCTION =
    1U; /*!< Function 1 of PAD_MIPI_TXM1 selects VI0_D[11]. */
static constexpr auto PINMUX_PAD_MIPI_TXM1_VO_D2_FUNCTION =
    2U; /*!< Function 2 of PAD_MIPI_TXM1 selects VO_D[2]. */
static constexpr auto PINMUX_PAD_MIPI_TXM1_XGPIOC14_FUNCTION =
    3U; /*!< Function 3 of PAD_MIPI_TXM1 selects XGPIOC[14]. */
static constexpr auto PINMUX_PAD_MIPI_TXM1_IIC2_SDA_FUNCTION =
    4U; /*!< Function 4 of PAD_MIPI_TXM1 selects IIC2_SDA. */
static constexpr auto PINMUX_PAD_MIPI_TXM1_PWM10_FUNCTION =
    5U; /*!< Function 5 of PAD_MIPI_TXM1 selects PWM[10]. */
static constexpr auto PINMUX_PAD_MIPI_TXM1_SPI0_SDO_FUNCTION =
    6U; /*!< Function 6 of PAD_MIPI_TXM1 selects SPI0_SDO. */
static constexpr auto PINMUX_PAD_MIPI_TXM1_DBG14_FUNCTION =
    7U; /*!< Function 7 of PAD_MIPI_TXM1 selects DBG[14]. */

/// @brief Function encodings for PAD_MIPI_TXM2.
static constexpr auto PINMUX_PAD_MIPI_TXM2_CR_SDA0_FUNCTION =
    0U; /*!< Function 0 of PAD_MIPI_TXM2 selects CR_SDA0. */
static constexpr auto PINMUX_PAD_MIPI_TXM2_VI0_D13_FUNCTION =
    1U; /*!< Function 1 of PAD_MIPI_TXM2 selects VI0_D[13]. */
static constexpr auto PINMUX_PAD_MIPI_TXM2_VO_D0_FUNCTION =
    2U; /*!< Function 2 of PAD_MIPI_TXM2 selects VO_D[0]. */
static constexpr auto PINMUX_PAD_MIPI_TXM2_XGPIOC16_FUNCTION =
    3U; /*!< Function 3 of PAD_MIPI_TXM2 selects XGPIOC[16]. */
static constexpr auto PINMUX_PAD_MIPI_TXM2_IIC1_SDA_FUNCTION =
    4U; /*!< Function 4 of PAD_MIPI_TXM2 selects IIC1_SDA. */
static constexpr auto PINMUX_PAD_MIPI_TXM2_PWM8_FUNCTION =
    5U; /*!< Function 5 of PAD_MIPI_TXM2 selects PWM[8]. */
static constexpr auto PINMUX_PAD_MIPI_TXM2_SPI0_SCK_FUNCTION =
    6U; /*!< Function 6 of PAD_MIPI_TXM2 selects SPI0_SCK. */

/// @brief Function encodings for PAD_MIPI_TXP0.
static constexpr auto PINMUX_PAD_MIPI_TXP0_PAD_MIPI_TXP0_FUNCTION =
    0U; /*!< Function 0 of PAD_MIPI_TXP0 selects (PAD_MIPI_TXP0). */
static constexpr auto PINMUX_PAD_MIPI_TXP0_VI0_D10_FUNCTION =
    1U; /*!< Function 1 of PAD_MIPI_TXP0 selects VI0_D[10]. */
static constexpr auto PINMUX_PAD_MIPI_TXP0_VO_D3_FUNCTION =
    2U; /*!< Function 2 of PAD_MIPI_TXP0 selects VO_D[3]. */
static constexpr auto PINMUX_PAD_MIPI_TXP0_XGPIOC13_FUNCTION =
    3U; /*!< Function 3 of PAD_MIPI_TXP0 selects XGPIOC[13]. */
static constexpr auto PINMUX_PAD_MIPI_TXP0_CAM_MCLK0_FUNCTION =
    4U; /*!< Function 4 of PAD_MIPI_TXP0 selects CAM_MCLK0. */
static constexpr auto PINMUX_PAD_MIPI_TXP0_PWM15_FUNCTION =
    5U; /*!< Function 5 of PAD_MIPI_TXP0 selects PWM[15]. */
static constexpr auto PINMUX_PAD_MIPI_TXP0_CAM_HS0_FUNCTION =
    6U; /*!< Function 6 of PAD_MIPI_TXP0 selects CAM_HS0. */
static constexpr auto PINMUX_PAD_MIPI_TXP0_DBG13_FUNCTION =
    7U; /*!< Function 7 of PAD_MIPI_TXP0 selects DBG[13]. */

/// @brief Function encodings for PAD_MIPI_TXP1.
static constexpr auto PINMUX_PAD_MIPI_TXP1_CR_2WTCK_FUNCTION =
    0U; /*!< Function 0 of PAD_MIPI_TXP1 selects CR_2WTCK. */
static constexpr auto PINMUX_PAD_MIPI_TXP1_VI0_D12_FUNCTION =
    1U; /*!< Function 1 of PAD_MIPI_TXP1 selects VI0_D[12]. */
static constexpr auto PINMUX_PAD_MIPI_TXP1_VO_D1_FUNCTION =
    2U; /*!< Function 2 of PAD_MIPI_TXP1 selects VO_D[1]. */
static constexpr auto PINMUX_PAD_MIPI_TXP1_XGPIOC15_FUNCTION =
    3U; /*!< Function 3 of PAD_MIPI_TXP1 selects XGPIOC[15]. */
static constexpr auto PINMUX_PAD_MIPI_TXP1_IIC2_SCL_FUNCTION =
    4U; /*!< Function 4 of PAD_MIPI_TXP1 selects IIC2_SCL. */
static constexpr auto PINMUX_PAD_MIPI_TXP1_PWM11_FUNCTION =
    5U; /*!< Function 5 of PAD_MIPI_TXP1 selects PWM[11]. */
static constexpr auto PINMUX_PAD_MIPI_TXP1_SPI0_SDI_FUNCTION =
    6U; /*!< Function 6 of PAD_MIPI_TXP1 selects SPI0_SDI. */
static constexpr auto PINMUX_PAD_MIPI_TXP1_DBG15_FUNCTION =
    7U; /*!< Function 7 of PAD_MIPI_TXP1 selects DBG[15]. */

/// @brief Function encodings for PAD_MIPI_TXP2.
static constexpr auto PINMUX_PAD_MIPI_TXP2_CR_SCL0_FUNCTION =
    0U; /*!< Function 0 of PAD_MIPI_TXP2 selects CR_SCL0. */
static constexpr auto PINMUX_PAD_MIPI_TXP2_VI0_D14_FUNCTION =
    1U; /*!< Function 1 of PAD_MIPI_TXP2 selects VI0_D[14]. */
static constexpr auto PINMUX_PAD_MIPI_TXP2_VO_CLK0_FUNCTION =
    2U; /*!< Function 2 of PAD_MIPI_TXP2 selects VO_CLK0. */
static constexpr auto PINMUX_PAD_MIPI_TXP2_XGPIOC17_FUNCTION =
    3U; /*!< Function 3 of PAD_MIPI_TXP2 selects XGPIOC[17]. */
static constexpr auto PINMUX_PAD_MIPI_TXP2_IIC1_SCL_FUNCTION =
    4U; /*!< Function 4 of PAD_MIPI_TXP2 selects IIC1_SCL. */
static constexpr auto PINMUX_PAD_MIPI_TXP2_PWM9_FUNCTION =
    5U; /*!< Function 5 of PAD_MIPI_TXP2 selects PWM[9]. */
static constexpr auto PINMUX_PAD_MIPI_TXP2_SPI0_CS_X_FUNCTION =
    6U; /*!< Function 6 of PAD_MIPI_TXP2 selects SPI0_CS_X. */

/// @brief Function encodings for PKG_TYPE0.
static constexpr auto PINMUX_PKG_TYPE0_PKG_TYPE0_FUNCTION =
    0U; /*!< Function 0 of PKG_TYPE0 selects PKG_TYPE0. */

/// @brief Function encodings for PKG_TYPE1.
static constexpr auto PINMUX_PKG_TYPE1_PKG_TYPE1_FUNCTION =
    0U; /*!< Function 0 of PKG_TYPE1 selects PKG_TYPE1. */

/// @brief Function encodings for PKG_TYPE2.
static constexpr auto PINMUX_PKG_TYPE2_PKG_TYPE2_FUNCTION =
    0U; /*!< Function 0 of PKG_TYPE2 selects PKG_TYPE2. */

/// @brief Function encodings for PWM0_BUCK.
static constexpr auto PINMUX_PWM0_BUCK_PWM0_FUNCTION = 0U; /*!< Function 0 of PWM0_BUCK selects PWM[0]. */
static constexpr auto PINMUX_PWM0_BUCK_XGPIOB0_FUNCTION =
    3U; /*!< Function 3 of PWM0_BUCK selects XGPIOB[0]. */

/// @brief Function encodings for PWR_BUTTON1.
static constexpr auto PINMUX_PWR_BUTTON1_PWR_BUTTON1_FUNCTION =
    0U; /*!< Function 0 of PWR_BUTTON1 selects PWR_BUTTON1. */
static constexpr auto PINMUX_PWR_BUTTON1_PWR_GPIO8_FUNCTION =
    3U; /*!< Function 3 of PWR_BUTTON1 selects PWR_GPIO[8]. */
static constexpr auto PINMUX_PWR_BUTTON1_UART1_RX_FUNCTION =
    4U; /*!< Function 4 of PWR_BUTTON1 selects UART1_RX. */
static constexpr auto PINMUX_PWR_BUTTON1_IIC4_SDA_FUNCTION =
    5U; /*!< Function 5 of PWR_BUTTON1 selects IIC4_SDA. */
static constexpr auto PINMUX_PWR_BUTTON1_EPHY_SPD_LED_FUNCTION =
    6U; /*!< Function 6 of PWR_BUTTON1 selects EPHY_SPD_LED. */
static constexpr auto PINMUX_PWR_BUTTON1_WG2_D1_FUNCTION =
    7U; /*!< Function 7 of PWR_BUTTON1 selects WG2_D1. */

/// @brief Function encodings for PWR_GPIO0.
static constexpr auto PINMUX_PWR_GPIO0_PWR_GPIO0_FUNCTION =
    0U; /*!< Function 0 of PWR_GPIO0 selects PWR_GPIO[0]. */
static constexpr auto PINMUX_PWR_GPIO0_UART2_TX_FUNCTION =
    1U; /*!< Function 1 of PWR_GPIO0 selects UART2_TX. */
static constexpr auto PINMUX_PWR_GPIO0_PWR_UART0_RX_FUNCTION =
    2U; /*!< Function 2 of PWR_GPIO0 selects PWR_UART0_RX. */
static constexpr auto PINMUX_PWR_GPIO0_PWM8_FUNCTION = 4U; /*!< Function 4 of PWR_GPIO0 selects PWM[8]. */

/// @brief Function encodings for PWR_GPIO1.
static constexpr auto PINMUX_PWR_GPIO1_PWR_GPIO1PWRSAR1_VIN2_FUNCTION =
    0U; /*!< PWRSAR1.VIN2, Function 0 of PWR_GPIO1 selects */
        ///< PWR_GPIO[1](PWRSAR1.VIN2).
static constexpr auto PINMUX_PWR_GPIO1_UART2_RX_FUNCTION =
    1U; /*!< Function 1 of PWR_GPIO1 selects UART2_RX. */
static constexpr auto PINMUX_PWR_GPIO1_EPHY_LNK_LED_FUNCTION =
    3U; /*!< Function 3 of PWR_GPIO1 selects EPHY_LNK_LED. */
static constexpr auto PINMUX_PWR_GPIO1_PWM9_FUNCTION = 4U; /*!< Function 4 of PWR_GPIO1 selects PWM[9]. */
static constexpr auto PINMUX_PWR_GPIO1_PWR_IIC_SCL_FUNCTION =
    5U; /*!< Function 5 of PWR_GPIO1 selects PWR_IIC_SCL. */
static constexpr auto PINMUX_PWR_GPIO1_IIC2_SCL_FUNCTION =
    6U; /*!< Function 6 of PWR_GPIO1 selects IIC2_SCL. */
static constexpr auto PINMUX_PWR_GPIO1_CR_SDA0_FUNCTION = 7U; /*!< Function 7 of PWR_GPIO1 selects CR_SDA0. */

/// @brief Function encodings for PWR_GPIO2.
static constexpr auto PINMUX_PWR_GPIO2_PWR_GPIO2PWRSAR_VIN1_FUNCTION =
    0U; /*!< PWRSAR.VIN1, Function 0 of PWR_GPIO2 selects */
        ///< PWR_GPIO[2](PWRSAR.VIN1).
static constexpr auto PINMUX_PWR_GPIO2_EPHY_SPD_LED_FUNCTION =
    3U; /*!< Function 3 of PWR_GPIO2 selects EPHY_SPD_LED. */
static constexpr auto PINMUX_PWR_GPIO2_PWM10_FUNCTION = 4U; /*!< Function 4 of PWR_GPIO2 selects PWM[10]. */
static constexpr auto PINMUX_PWR_GPIO2_PWR_IIC_SDA_FUNCTION =
    5U; /*!< Function 5 of PWR_GPIO2 selects PWR_IIC_SDA. */
static constexpr auto PINMUX_PWR_GPIO2_IIC2_SDA_FUNCTION =
    6U; /*!< Function 6 of PWR_GPIO2 selects IIC2_SDA. */
static constexpr auto PINMUX_PWR_GPIO2_CR_2WTCK_FUNCTION =
    7U; /*!< Function 7 of PWR_GPIO2 selects CR_2WTCK. */

/// @brief Function encodings for PWR_RSTN.
static constexpr auto PINMUX_PWR_RSTN_PWR_RSTN_FUNCTION = 0U; /*!< Function 0 of PWR_RSTN selects PWR_RSTN. */

/// @brief Function encodings for PWR_SEQ1.
static constexpr auto PINMUX_PWR_SEQ1_PWR_SEQ1_FUNCTION = 0U; /*!< Function 0 of PWR_SEQ1 selects PWR_SEQ1. */
static constexpr auto PINMUX_PWR_SEQ1_PWR_GPIO3_FUNCTION =
    3U; /*!< Function 3 of PWR_SEQ1 selects PWR_GPIO[3]. */

/// @brief Function encodings for PWR_SEQ2.
static constexpr auto PINMUX_PWR_SEQ2_PWR_SEQ2_FUNCTION = 0U; /*!< Function 0 of PWR_SEQ2 selects PWR_SEQ2. */
static constexpr auto PINMUX_PWR_SEQ2_PWR_GPIO4_FUNCTION =
    3U; /*!< Function 3 of PWR_SEQ2 selects PWR_GPIO[4]. */

/// @brief Function encodings for PWR_VBAT_DET.
static constexpr auto PINMUX_PWR_VBAT_DET_PWR_VBAT_DETPWRSAR_VIN3_FUNCTION =
    0U; /*!< PWRSAR.VIN3, Function 0 of PWR_VBAT_DET selects */
        ///< PWR_VBAT_DET(PWRSAR.VIN3).

/// @brief Function encodings for PWR_WAKEUP0.
static constexpr auto PINMUX_PWR_WAKEUP0_PWR_WAKEUP0_FUNCTION =
    0U; /*!< Function 0 of PWR_WAKEUP0 selects PWR_WAKEUP0. */
static constexpr auto PINMUX_PWR_WAKEUP0_PWR_IR0_FUNCTION =
    1U; /*!< Function 1 of PWR_WAKEUP0 selects PWR_IR0. */
static constexpr auto PINMUX_PWR_WAKEUP0_PWR_UART0_TX_FUNCTION =
    2U; /*!< Function 2 of PWR_WAKEUP0 selects PWR_UART0_TX. */
static constexpr auto PINMUX_PWR_WAKEUP0_PWR_GPIO6_FUNCTION =
    3U; /*!< Function 3 of PWR_WAKEUP0 selects PWR_GPIO[6](. */
static constexpr auto PINMUX_PWR_WAKEUP0_UART1_TX_FUNCTION =
    4U; /*!< Function 4 of PWR_WAKEUP0 selects UART1_TX. */
static constexpr auto PINMUX_PWR_WAKEUP0_IIC4_SCL_FUNCTION =
    5U; /*!< Function 5 of PWR_WAKEUP0 selects IIC4_SCL. */
static constexpr auto PINMUX_PWR_WAKEUP0_EPHY_LNK_LED_FUNCTION =
    6U; /*!< Function 6 of PWR_WAKEUP0 selects EPHY_LNK_LED. */
static constexpr auto PINMUX_PWR_WAKEUP0_WG2_D0_FUNCTION =
    7U; /*!< Function 7 of PWR_WAKEUP0 selects WG2_D0. */

/// @brief Function encodings for SD0_CD.
static constexpr auto PINMUX_SD0_CD_SDIO0_CD_FUNCTION = 0U; /*!< Function 0 of SD0_CD selects SDIO0_CD. */
static constexpr auto PINMUX_SD0_CD_XGPIOA13_FUNCTION = 3U; /*!< Function 3 of SD0_CD selects XGPIOA[13]. */

/// @brief Function encodings for SD0_CLK.
static constexpr auto PINMUX_SD0_CLK_SDIO0_CLK_FUNCTION = 0U; /*!< Function 0 of SD0_CLK selects SDIO0_CLK. */
static constexpr auto PINMUX_SD0_CLK_IIC1_SDA_FUNCTION = 1U;  /*!< Function 1 of SD0_CLK selects IIC1_SDA. */
static constexpr auto PINMUX_SD0_CLK_SPI0_SCK_FUNCTION = 2U;  /*!< Function 2 of SD0_CLK selects SPI0_SCK. */
static constexpr auto PINMUX_SD0_CLK_XGPIOA7_FUNCTION = 3U;   /*!< Function 3 of SD0_CLK selects XGPIOA[7]. */
static constexpr auto PINMUX_SD0_CLK_PWM15_FUNCTION = 5U;     /*!< Function 5 of SD0_CLK selects PWM[15]. */
static constexpr auto PINMUX_SD0_CLK_EPHY_LNK_LED_FUNCTION =
    6U;                                                  /*!< Function 6 of SD0_CLK selects EPHY_LNK_LED. */
static constexpr auto PINMUX_SD0_CLK_DBG0_FUNCTION = 7U; /*!< Function 7 of SD0_CLK selects DBG[0]. */

/// @brief Function encodings for SD0_CMD.
static constexpr auto PINMUX_SD0_CMD_SDIO0_CMD_FUNCTION = 0U; /*!< Function 0 of SD0_CMD selects SDIO0_CMD. */
static constexpr auto PINMUX_SD0_CMD_IIC1_SCL_FUNCTION = 1U;  /*!< Function 1 of SD0_CMD selects IIC1_SCL. */
static constexpr auto PINMUX_SD0_CMD_SPI0_SDO_FUNCTION = 2U;  /*!< Function 2 of SD0_CMD selects SPI0_SDO. */
static constexpr auto PINMUX_SD0_CMD_XGPIOA8_FUNCTION = 3U;   /*!< Function 3 of SD0_CMD selects XGPIOA[8]. */
static constexpr auto PINMUX_SD0_CMD_PWM14_FUNCTION = 5U;     /*!< Function 5 of SD0_CMD selects PWM[14]. */
static constexpr auto PINMUX_SD0_CMD_EPHY_SPD_LED_FUNCTION =
    6U;                                                  /*!< Function 6 of SD0_CMD selects EPHY_SPD_LED. */
static constexpr auto PINMUX_SD0_CMD_DBG1_FUNCTION = 7U; /*!< Function 7 of SD0_CMD selects DBG[1]. */

/// @brief Function encodings for SD0_D0.
static constexpr auto PINMUX_SD0_D0_SDIO0_D0_FUNCTION = 0U;  /*!< Function 0 of SD0_D0 selects SDIO0_D[0]. */
static constexpr auto PINMUX_SD0_D0_CAM_MCLK1_FUNCTION = 1U; /*!< Function 1 of SD0_D0 selects CAM_MCLK1. */
static constexpr auto PINMUX_SD0_D0_SPI0_SDI_FUNCTION = 2U;  /*!< Function 2 of SD0_D0 selects SPI0_SDI. */
static constexpr auto PINMUX_SD0_D0_XGPIOA9_FUNCTION = 3U;   /*!< Function 3 of SD0_D0 selects XGPIOA[9]. */
static constexpr auto PINMUX_SD0_D0_UART3_TX_FUNCTION = 4U;  /*!< Function 4 of SD0_D0 selects UART3_TX. */
static constexpr auto PINMUX_SD0_D0_PWM13_FUNCTION = 5U;     /*!< Function 5 of SD0_D0 selects PWM[13]. */
static constexpr auto PINMUX_SD0_D0_WG0_D0_FUNCTION = 6U;    /*!< Function 6 of SD0_D0 selects WG0_D0. */
static constexpr auto PINMUX_SD0_D0_DBG2_FUNCTION = 7U;      /*!< Function 7 of SD0_D0 selects DBG[2]. */

/// @brief Function encodings for SD0_D1.
static constexpr auto PINMUX_SD0_D1_SDIO0_D1_FUNCTION = 0U; /*!< Function 0 of SD0_D1 selects SDIO0_D[1]. */
static constexpr auto PINMUX_SD0_D1_IIC1_SDA_FUNCTION = 1U; /*!< Function 1 of SD0_D1 selects IIC1_SDA. */
static constexpr auto PINMUX_SD0_D1_AUX0_FUNCTION = 2U;     /*!< Function 2 of SD0_D1 selects AUX0. */
static constexpr auto PINMUX_SD0_D1_XGPIOA10_FUNCTION = 3U; /*!< Function 3 of SD0_D1 selects XGPIOA[10]. */
static constexpr auto PINMUX_SD0_D1_UART1_TX_FUNCTION = 4U; /*!< Function 4 of SD0_D1 selects UART1_TX. */
static constexpr auto PINMUX_SD0_D1_PWM12_FUNCTION = 5U;    /*!< Function 5 of SD0_D1 selects PWM[12]. */
static constexpr auto PINMUX_SD0_D1_WG0_D1_FUNCTION = 6U;   /*!< Function 6 of SD0_D1 selects WG0_D1. */
static constexpr auto PINMUX_SD0_D1_DBG3_FUNCTION = 7U;     /*!< Function 7 of SD0_D1 selects DBG[3]. */

/// @brief Function encodings for SD0_D2.
static constexpr auto PINMUX_SD0_D2_SDIO0_D2_FUNCTION = 0U; /*!< Function 0 of SD0_D2 selects SDIO0_D[2]. */
static constexpr auto PINMUX_SD0_D2_IIC1_SCL_FUNCTION = 1U; /*!< Function 1 of SD0_D2 selects IIC1_SCL. */
static constexpr auto PINMUX_SD0_D2_AUX1_FUNCTION = 2U;     /*!< Function 2 of SD0_D2 selects AUX1. */
static constexpr auto PINMUX_SD0_D2_XGPIOA11_FUNCTION = 3U; /*!< Function 3 of SD0_D2 selects XGPIOA[11]. */
static constexpr auto PINMUX_SD0_D2_UART1_RX_FUNCTION = 4U; /*!< Function 4 of SD0_D2 selects UART1_RX. */
static constexpr auto PINMUX_SD0_D2_PWM11_FUNCTION = 5U;    /*!< Function 5 of SD0_D2 selects PWM[11]. */
static constexpr auto PINMUX_SD0_D2_WG1_D0_FUNCTION = 6U;   /*!< Function 6 of SD0_D2 selects WG1_D0. */
static constexpr auto PINMUX_SD0_D2_DBG4_FUNCTION = 7U;     /*!< Function 7 of SD0_D2 selects DBG[4]. */

/// @brief Function encodings for SD0_D3.
static constexpr auto PINMUX_SD0_D3_SDIO0_D3_FUNCTION = 0U;  /*!< Function 0 of SD0_D3 selects SDIO0_D[3]. */
static constexpr auto PINMUX_SD0_D3_CAM_MCLK0_FUNCTION = 1U; /*!< Function 1 of SD0_D3 selects CAM_MCLK0. */
static constexpr auto PINMUX_SD0_D3_SPI0_CS_X_FUNCTION = 2U; /*!< Function 2 of SD0_D3 selects SPI0_CS_X. */
static constexpr auto PINMUX_SD0_D3_XGPIOA12_FUNCTION = 3U;  /*!< Function 3 of SD0_D3 selects XGPIOA[12]. */
static constexpr auto PINMUX_SD0_D3_UART3_RX_FUNCTION = 4U;  /*!< Function 4 of SD0_D3 selects UART3_RX. */
static constexpr auto PINMUX_SD0_D3_PWM10_FUNCTION = 5U;     /*!< Function 5 of SD0_D3 selects PWM[10]. */
static constexpr auto PINMUX_SD0_D3_WG1_D1_FUNCTION = 6U;    /*!< Function 6 of SD0_D3 selects WG1_D1. */
static constexpr auto PINMUX_SD0_D3_DBG5_FUNCTION = 7U;      /*!< Function 7 of SD0_D3 selects DBG[5]. */

/// @brief Function encodings for SD0_PWR_EN.
static constexpr auto PINMUX_SD0_PWR_EN_SDIO0_PWR_EN_FUNCTION =
    0U; /*!< Function 0 of SD0_PWR_EN selects SDIO0_PWR_EN. */
static constexpr auto PINMUX_SD0_PWR_EN_XGPIOA14_FUNCTION =
    3U; /*!< Function 3 of SD0_PWR_EN selects XGPIOA[14]. */

/// @brief Function encodings for SD1_CLK.
static constexpr auto PINMUX_SD1_CLK_PWR_SD1_CLK_FUNCTION =
    0U; /*!< Function 0 of SD1_CLK selects PWR_SD1_CLK. */
static constexpr auto PINMUX_SD1_CLK_SPI2_SCK_FUNCTION = 1U; /*!< Function 1 of SD1_CLK selects SPI2_SCK. */
static constexpr auto PINMUX_SD1_CLK_IIC3_SDA_FUNCTION = 2U; /*!< Function 2 of SD1_CLK selects IIC3_SDA. */
static constexpr auto PINMUX_SD1_CLK_PWR_GPIO23_FUNCTION =
    3U; /*!< Function 3 of SD1_CLK selects PWR_GPIO[23]. */
static constexpr auto PINMUX_SD1_CLK_CAM_HS0_FUNCTION = 4U; /*!< Function 4 of SD1_CLK selects CAM_HS0. */
static constexpr auto PINMUX_SD1_CLK_EPHY_SPD_LED_FUNCTION =
    5U; /*!< Function 5 of SD1_CLK selects EPHY_SPD_LED. */
static constexpr auto PINMUX_SD1_CLK_PWR_SPINOR1_SCK_FUNCTION =
    6U; /*!< Function 6 of SD1_CLK selects PWR_SPINOR1_SCK. */
static constexpr auto PINMUX_SD1_CLK_PWM9_FUNCTION = 7U; /*!< Function 7 of SD1_CLK selects PWM[9]. */

/// @brief Function encodings for SD1_CMD.
static constexpr auto PINMUX_SD1_CMD_PWR_SD1_CMD_FUNCTION =
    0U; /*!< Function 0 of SD1_CMD selects PWR_SD1_CMD. */
static constexpr auto PINMUX_SD1_CMD_SPI2_SDO_FUNCTION = 1U; /*!< Function 1 of SD1_CMD selects SPI2_SDO. */
static constexpr auto PINMUX_SD1_CMD_IIC3_SCL_FUNCTION = 2U; /*!< Function 2 of SD1_CMD selects IIC3_SCL. */
static constexpr auto PINMUX_SD1_CMD_PWR_GPIO22_FUNCTION =
    3U; /*!< Function 3 of SD1_CMD selects PWR_GPIO[22]. */
static constexpr auto PINMUX_SD1_CMD_CAM_VS0_FUNCTION = 4U; /*!< Function 4 of SD1_CMD selects CAM_VS0. */
static constexpr auto PINMUX_SD1_CMD_EPHY_LNK_LED_FUNCTION =
    5U; /*!< Function 5 of SD1_CMD selects EPHY_LNK_LED. */
static constexpr auto PINMUX_SD1_CMD_PWR_SPINOR1_MOSI_FUNCTION =
    6U; /*!< Function 6 of SD1_CMD selects PWR_SPINOR1_MOSI. */
static constexpr auto PINMUX_SD1_CMD_PWM8_FUNCTION = 7U; /*!< Function 7 of SD1_CMD selects PWM[8]. */

/// @brief Function encodings for SD1_D0.
static constexpr auto PINMUX_SD1_D0_PWR_SD1_D0_FUNCTION = 0U; /*!< Function 0 of SD1_D0 selects PWR_SD1_D0. */
static constexpr auto PINMUX_SD1_D0_SPI2_SDI_FUNCTION = 1U;   /*!< Function 1 of SD1_D0 selects SPI2_SDI. */
static constexpr auto PINMUX_SD1_D0_IIC1_SDA_FUNCTION = 2U;   /*!< Function 2 of SD1_D0 selects IIC1_SDA. */
static constexpr auto PINMUX_SD1_D0_PWR_GPIO21_FUNCTION =
    3U; /*!< Function 3 of SD1_D0 selects PWR_GPIO[21]. */
static constexpr auto PINMUX_SD1_D0_CAM_MCLK1_FUNCTION = 4U; /*!< Function 4 of SD1_D0 selects CAM_MCLK1. */
static constexpr auto PINMUX_SD1_D0_UART3_RTS_FUNCTION = 5U; /*!< Function 5 of SD1_D0 selects UART3_RTS. */
static constexpr auto PINMUX_SD1_D0_PWR_SPINOR1_MISO_FUNCTION =
    6U;                                                 /*!< Function 6 of SD1_D0 selects PWR_SPINOR1_MISO. */
static constexpr auto PINMUX_SD1_D0_PWM7_FUNCTION = 7U; /*!< Function 7 of SD1_D0 selects PWM[7]. */

/// @brief Function encodings for SD1_D1.
static constexpr auto PINMUX_SD1_D1_PWR_SD1_D1_FUNCTION = 0U; /*!< Function 0 of SD1_D1 selects PWR_SD1_D1. */
static constexpr auto PINMUX_SD1_D1_IIC1_SDA_FUNCTION = 1U;   /*!< Function 1 of SD1_D1 selects IIC1_SDA. */
static constexpr auto PINMUX_SD1_D1_UART2_RX_FUNCTION = 2U;   /*!< Function 2 of SD1_D1 selects UART2_RX. */
static constexpr auto PINMUX_SD1_D1_PWR_GPIO20_FUNCTION =
    3U; /*!< Function 3 of SD1_D1 selects PWR_GPIO[20]. */
static constexpr auto PINMUX_SD1_D1_CAM_MCLK1_FUNCTION = 4U; /*!< Function 4 of SD1_D1 selects CAM_MCLK1. */
static constexpr auto PINMUX_SD1_D1_UART3_RX_FUNCTION = 5U;  /*!< Function 5 of SD1_D1 selects UART3_RX. */
static constexpr auto PINMUX_SD1_D1_PWR_SPINOR1_WP_X_FUNCTION =
    6U;                                                 /*!< Function 6 of SD1_D1 selects PWR_SPINOR1_WP_X. */
static constexpr auto PINMUX_SD1_D1_PWM6_FUNCTION = 7U; /*!< Function 7 of SD1_D1 selects PWM[6]. */

/// @brief Function encodings for SD1_D2.
static constexpr auto PINMUX_SD1_D2_PWR_SD1_D2_FUNCTION = 0U; /*!< Function 0 of SD1_D2 selects PWR_SD1_D2. */
static constexpr auto PINMUX_SD1_D2_IIC1_SCL_FUNCTION = 1U;   /*!< Function 1 of SD1_D2 selects IIC1_SCL. */
static constexpr auto PINMUX_SD1_D2_UART2_TX_FUNCTION = 2U;   /*!< Function 2 of SD1_D2 selects UART2_TX. */
static constexpr auto PINMUX_SD1_D2_PWR_GPIO19_FUNCTION =
    3U; /*!< Function 3 of SD1_D2 selects PWR_GPIO[19]. */
static constexpr auto PINMUX_SD1_D2_CAM_MCLK0_FUNCTION = 4U; /*!< Function 4 of SD1_D2 selects CAM_MCLK0. */
static constexpr auto PINMUX_SD1_D2_UART3_TX_FUNCTION = 5U;  /*!< Function 5 of SD1_D2 selects UART3_TX. */
static constexpr auto PINMUX_SD1_D2_PWR_SPINOR1_HOLD_X_FUNCTION =
    6U; /*!< Function 6 of SD1_D2 selects PWR_SPINOR1_HOLD_X. */
static constexpr auto PINMUX_SD1_D2_PWM5_FUNCTION = 7U; /*!< Function 7 of SD1_D2 selects PWM[5]. */

/// @brief Function encodings for SD1_D3.
static constexpr auto PINMUX_SD1_D3_PWR_SD1_D3_FUNCTION = 0U; /*!< Function 0 of SD1_D3 selects PWR_SD1_D3. */
static constexpr auto PINMUX_SD1_D3_SPI2_CS_X_FUNCTION = 1U;  /*!< Function 1 of SD1_D3 selects SPI2_CS_X. */
static constexpr auto PINMUX_SD1_D3_IIC1_SCL_FUNCTION = 2U;   /*!< Function 2 of SD1_D3 selects IIC1_SCL. */
static constexpr auto PINMUX_SD1_D3_PWR_GPIO18_FUNCTION =
    3U; /*!< Function 3 of SD1_D3 selects PWR_GPIO[18]. */
static constexpr auto PINMUX_SD1_D3_CAM_MCLK0_FUNCTION = 4U; /*!< Function 4 of SD1_D3 selects CAM_MCLK0. */
static constexpr auto PINMUX_SD1_D3_UART3_CTS_FUNCTION = 5U; /*!< Function 5 of SD1_D3 selects UART3_CTS. */
static constexpr auto PINMUX_SD1_D3_PWR_SPINOR1_CS_X_FUNCTION =
    6U;                                                 /*!< Function 6 of SD1_D3 selects PWR_SPINOR1_CS_X. */
static constexpr auto PINMUX_SD1_D3_PWM4_FUNCTION = 7U; /*!< Function 7 of SD1_D3 selects PWM[4]. */

/// @brief Function encodings for SPK_EN.
static constexpr auto PINMUX_SPK_EN_XGPIOA15_FUNCTION = 3U; /*!< Function 3 of SPK_EN selects XGPIOA[15]. */

/// @brief Function encodings for UART0_RX.
static constexpr auto PINMUX_UART0_RX_UART0_RX_FUNCTION = 0U; /*!< Function 0 of UART0_RX selects UART0_RX. */
static constexpr auto PINMUX_UART0_RX_CAM_MCLK0_FUNCTION =
    1U;                                                   /*!< Function 1 of UART0_RX selects CAM_MCLK0. */
static constexpr auto PINMUX_UART0_RX_PWM5_FUNCTION = 2U; /*!< Function 2 of UART0_RX selects PWM[5]. */
static constexpr auto PINMUX_UART0_RX_XGPIOA17_FUNCTION =
    3U; /*!< Function 3 of UART0_RX selects XGPIOA[17]. */
static constexpr auto PINMUX_UART0_RX_UART1_RX_FUNCTION = 4U; /*!< Function 4 of UART0_RX selects UART1_RX. */
static constexpr auto PINMUX_UART0_RX_AUX0_FUNCTION = 5U;     /*!< Function 5 of UART0_RX selects AUX0. */
static constexpr auto PINMUX_UART0_RX_DBG7_FUNCTION = 7U;     /*!< Function 7 of UART0_RX selects DBG[7]. */

/// @brief Function encodings for UART0_TX.
static constexpr auto PINMUX_UART0_TX_UART0_TX_FUNCTION = 0U; /*!< Function 0 of UART0_TX selects UART0_TX. */
static constexpr auto PINMUX_UART0_TX_CAM_MCLK1_FUNCTION =
    1U;                                                   /*!< Function 1 of UART0_TX selects CAM_MCLK1. */
static constexpr auto PINMUX_UART0_TX_PWM4_FUNCTION = 2U; /*!< Function 2 of UART0_TX selects PWM[4]. */
static constexpr auto PINMUX_UART0_TX_XGPIOA16_FUNCTION =
    3U; /*!< Function 3 of UART0_TX selects XGPIOA[16]. */
static constexpr auto PINMUX_UART0_TX_UART1_TX_FUNCTION = 4U; /*!< Function 4 of UART0_TX selects UART1_TX. */
static constexpr auto PINMUX_UART0_TX_AUX1_FUNCTION = 5U;     /*!< Function 5 of UART0_TX selects AUX1. */
static constexpr auto PINMUX_UART0_TX_DBG6_FUNCTION = 7U;     /*!< Function 7 of UART0_TX selects DBG[6]. */

/// @brief Function encodings for USB_VBUS_DET.
static constexpr auto PINMUX_USB_VBUS_DET_USB_VBUS_DET_FUNCTION =
    0U; /*!< Function 0 of USB_VBUS_DET selects USB_VBUS_DET. */
static constexpr auto PINMUX_USB_VBUS_DET_XGPIOB6_FUNCTION =
    3U; /*!< Function 3 of USB_VBUS_DET selects XGPIOB[6]. */
static constexpr auto PINMUX_USB_VBUS_DET_CAM_MCLK0_FUNCTION =
    4U; /*!< Function 4 of USB_VBUS_DET selects CAM_MCLK0. */
static constexpr auto PINMUX_USB_VBUS_DET_CAM_MCLK1_FUNCTION =
    5U; /*!< Function 5 of USB_VBUS_DET selects CAM_MCLK1. */

/**
 * @brief GPIO Port A data, direction, and interrupt registers.
 */
typedef struct
{
    volatile uint32_t SWPORTA_DR;          /*!< Port A output-data register, Address offset: 0x000 */
    volatile uint32_t SWPORTA_DDR;         /*!< Port A output-direction enable
                                               register, Address offset: 0x004 */
    uint32_t RESERVED_008[10];             /*!< Reserved, Address offset: 0x008 */
    volatile uint32_t INTEN;               /*!< interrupt-enable register, Address offset: 0x030 */
    volatile uint32_t INTMASK;             /*!< interrupt-mask register, Address offset: 0x034 */
    volatile uint32_t INTTYPE_LEVEL;       /*!< edge/level trigger selector, Address offset: 0x038 */
    volatile uint32_t INT_POLARITY;        /*!< interrupt-polarity selector, Address offset: 0x03C */
    volatile const uint32_t INTSTATUS;     /*!< Port A interrupt status, Address offset: 0x040 */
    volatile const uint32_t RAW_INTSTATUS; /*!< unmasked Port A interrupt status, Address offset: 0x044 */
    volatile uint32_t DEBOUNCE;            /*!< input-debounce enable register, Address offset: 0x048 */
    volatile uint32_t PORTA_EOI;           /*!< Port A interrupt-clear register, Address offset: 0x04C */
    volatile const uint32_t EXT_PORTA;     /*!< Port A input pin levels, Address offset: 0x050 */
    uint32_t RESERVED_054[3];              /*!< Reserved, Address offset: 0x054 */
    volatile uint32_t LS_SYNC;             /*!< level-sensitive input synchronization
                                               enable register, Address offset: 0x060 */
} GPIO_Type;

static_assert(offsetof(GPIO_Type, SWPORTA_DR) == 0x000U);
static_assert(offsetof(GPIO_Type, SWPORTA_DDR) == 0x004U);
static_assert(offsetof(GPIO_Type, INTEN) == 0x030U);
static_assert(offsetof(GPIO_Type, PORTA_EOI) == 0x04CU);
static_assert(offsetof(GPIO_Type, EXT_PORTA) == 0x050U);
static_assert(offsetof(GPIO_Type, LS_SYNC) == 0x060U);

/**
 * @brief GPIO0 register-instance pointer.
 */
#define GPIO0_REGS ((GPIO_Type *)(uintptr_t)GPIO0_BASE)
/**
 * @brief GPIO1 register-instance pointer.
 */
#define GPIO1_REGS ((GPIO_Type *)(uintptr_t)GPIO1_BASE)
/**
 * @brief GPIO2 register-instance pointer.
 */
#define GPIO2_REGS ((GPIO_Type *)(uintptr_t)GPIO2_BASE)
/**
 * @brief GPIO3 register-instance pointer.
 */
#define GPIO3_REGS ((GPIO_Type *)(uintptr_t)GPIO3_BASE)
/**
 * @brief RTC_GPIO register-instance pointer.
 */
#define RTC_GPIO_REGS ((GPIO_Type *)(uintptr_t)RTC_GPIO_BASE)

/// @brief Byte offset of TOP DMA request-remap register zero.
static constexpr auto TOP_DMA_REMAP0_OFFSET = 0x154U;
/// @brief Byte offset of TOP DMA request-remap register one.
static constexpr auto TOP_DMA_REMAP1_OFFSET = 0x158U;
/// @brief Byte offset of TOP DMA interrupt-multiplexer register.
static constexpr auto TOP_DMA_INTERRUPT_MUX_OFFSET = 0x298U;
/// @brief Least-significant bit position of the CPU0 DMA routing field.
static constexpr auto TOP_DMA_INTERRUPT_CPU0_SHIFT = 0U;
/// @brief Least-significant bit position of the CPU1 DMA routing field.
static constexpr auto TOP_DMA_INTERRUPT_CPU1_SHIFT = 10U;
/// @brief Least-significant bit position of the CPU2 DMA routing field.
static constexpr auto TOP_DMA_INTERRUPT_CPU2_SHIFT = 20U;
/// @brief Bit mask for TOP per-CPU DMA interrupt-routing field.
/// @brief Mask of one CPU's field: 10 bits, of which the low eight are channels.
///
/// 上游 `drivers/dma/cv1800b-dmamux.c`（Sophgo CV1800/SG2000 的 DMAMUX 驱动）给出真实位域：
///   DMAMUX_INT_BIT_PER_CPU = 10
///   DMAMUX_INT_BIT(chid, cpuid) = BIT(cpuid * 10 + chid)      // 低 8 位：每通道一位
///   DMAMUX_INTEN_BIT(cpuid)     = DMAMUX_INT_BIT(8, cpuid)    // 第 8 位：该 CPU 的中断使能
/// 也就是**通道位只是"选谁"，第 8 位才是"往这个 CPU 发中断"的总开关**。
/// Upstream `drivers/dma/cv1800b-dmamux.c` documents the real field: 10 bits per CPU, the low
/// eight being one bit per channel and bit 8 the per-CPU interrupt enable.  The channel bits only
/// select the destination; bit 8 is what actually lets the interrupt reach that CPU.
static constexpr auto TOP_DMA_INTERRUPT_FIELD_MASK = 0x3FFU;
/// @brief Per-CPU interrupt-enable bit inside that field (bit 8).
static constexpr auto TOP_DMA_INTERRUPT_ENABLE_BIT = 1U << 8U;

/**
 * @brief TOP register block.
 */
typedef struct
{
    uint32_t RESERVED_000[1];            /*!< Reserved, Address offset: 0x000 */
    volatile uint32_t CONF_INFO;         /*!< conf_info, Address offset: 0x004 */
    volatile uint32_t SYS_CTRL;          /*!< sys_ctrl_reg, Address offset: 0x008 */
    uint32_t RESERVED_00C[15];           /*!< Reserved, Address offset: 0x00C */
    volatile uint32_t USB_PHY_CTRL_REG;  /*!< usb_phy_ctrl_reg, Address offset: 0x048 */
    uint32_t RESERVED_04C[6];            /*!< Reserved, Address offset: 0x04C */
    volatile uint32_t DDR_ADDR_MODE;     /*!< DDR address-mode and remap register.
                                             The SDK uses it but TRM Table 9.2 does
                                             not list it, Address offset: 0x064 */
    uint32_t RESERVED_068[59];           /*!< Reserved, Address offset: 0x068 */
    volatile uint32_t DMA_REMAP0;        /*!< sdma_dma_ch_remap0, Address offset: 0x154 */
    volatile uint32_t DMA_REMAP1;        /*!< sdma_dma_ch_remap1, Address offset: 0x158 */
    uint32_t RESERVED_15C[17];           /*!< Reserved, Address offset: 0x15C */
    volatile uint32_t TOP_TIMER_CLK_SEL; /*!< top_timer_clk_sel, Address offset: 0x1A0 */
    uint32_t RESERVED_1A4[1];            /*!< Reserved, Address offset: 0x1A4 */
    volatile uint32_t WDT_CTRL;          /*!< Watchdog reset-routing control, Address offset: 0x1A8 */
    uint32_t RESERVED_1AC[3];            /*!< Reserved, Address offset: 0x1AC */
    volatile uint32_t DDR_AXI_URGENT_OW; /*!< ddr_axi_urgent_ow, Address offset: 0x1B8 */
    volatile uint32_t DDR_AXI_URGENT;    /*!< ddr_axi_urgent, Address offset: 0x1BC */
    uint32_t RESERVED_1C0[6];            /*!< Reserved, Address offset: 0x1C0 */
    volatile uint32_t DDR_AXI_QOS_0;     /*!< ddr_axi_qos_0, Address offset: 0x1D8 */
    volatile uint32_t DDR_AXI_QOS_1;     /*!< ddr_axi_qos_1, Address offset: 0x1DC */
    uint32_t RESERVED_1E0[5];            /*!< Reserved, Address offset: 0x1E0 */
    volatile uint32_t SD_PWRSW_CTRL;     /*!< sd_pwrsw_ctrl, Address offset: 0x1F4 */
    volatile uint32_t SD_PWRSW_TIME;     /*!< sd_pwrsw_time, Address offset: 0x1F8 */
    uint32_t RESERVED_1FC[16];           /*!< Reserved, Address offset: 0x1FC */
    volatile uint32_t DDR_AXI_QOS_OW;    /*!< ddr_axi_qos_ow, Address offset: 0x23C */
    uint32_t RESERVED_240[21];           /*!< Reserved, Address offset: 0x240 */
    volatile uint32_t SD1_SELECT;        /*!< additional control register for sd, Address offset: 0x294 */
    volatile uint32_t DMA_INTERRUPT_MUX; /*!< Mux sdma channel interrupt to
                                              different processors, Address offset: 0x298 */
} TOP_Type;

static_assert(offsetof(TOP_Type, CONF_INFO) == 0x004U);
static_assert(offsetof(TOP_Type, SYS_CTRL) == 0x008U);
static_assert(offsetof(TOP_Type, USB_PHY_CTRL_REG) == 0x048U);
static_assert(offsetof(TOP_Type, DMA_REMAP0) == 0x154U);
static_assert(offsetof(TOP_Type, DMA_REMAP1) == 0x158U);
static_assert(offsetof(TOP_Type, TOP_TIMER_CLK_SEL) == 0x1A0U);
static_assert(offsetof(TOP_Type, WDT_CTRL) == 0x1A8U);
static_assert(offsetof(TOP_Type, DDR_AXI_URGENT_OW) == 0x1B8U);
static_assert(offsetof(TOP_Type, DDR_AXI_URGENT) == 0x1BCU);
static_assert(offsetof(TOP_Type, DDR_AXI_QOS_0) == 0x1D8U);
static_assert(offsetof(TOP_Type, DDR_AXI_QOS_1) == 0x1DCU);
static_assert(offsetof(TOP_Type, SD_PWRSW_CTRL) == 0x1F4U);
static_assert(offsetof(TOP_Type, SD_PWRSW_TIME) == 0x1F8U);
static_assert(offsetof(TOP_Type, DDR_AXI_QOS_OW) == 0x23CU);
static_assert(offsetof(TOP_Type, SD1_SELECT) == 0x294U);
static_assert(offsetof(TOP_Type, DMA_INTERRUPT_MUX) == 0x298U);

/**
 * @brief TOP register-instance pointer.
 */
#define TOP ((TOP_Type *)(uintptr_t)TOP_MISC_BASE)

/// @brief TOP system-control register offset.
static constexpr auto TOP_SYS_CTRL_OFFSET = 0x008UL;
/// @brief First bit of the watchdog system-reset route field.
static constexpr auto TOP_WDT_SYSTEM_ROUTE_SHIFT = 0U;
/// @brief First bit of the watchdog CPU-reset route field.
static constexpr auto TOP_WDT_CPU_ROUTE_SHIFT = 4U;
/// @brief Shared clock-selection field for main-domain watchdogs.
static constexpr auto TOP_WDT_CLOCK_SELECT_MASK = (7UL << 8);
/// @brief 32 kHz encoding of the shared main-domain watchdog clock selector.
static constexpr auto TOP_WDT_CLOCK_32K = (1UL << 8);

/**
 * @brief System-control compatibility enable used by the Sophgo watchdog driver.
 * @note Retains cvitek_wdt CV_TOP_WDT_VAL=0x100; TRM Table 9.4 lists this bit as reserved.
 */
static constexpr auto TOP_SYS_CTRL_WDT_COMPAT_ENABLE_BIT = (1UL << 8);

static_assert(offsetof(TOP_Type, WDT_CTRL) == 0x1A8U);
static_assert(offsetof(TOP_Type, SD1_SELECT) == TOP_SD1_SELECT_OFFSET);
static_assert(offsetof(TOP_Type, DMA_REMAP0) == 0x154U);
static_assert(offsetof(TOP_Type, DMA_REMAP1) == TOP_DMA_REMAP1_OFFSET);
static_assert(offsetof(TOP_Type, DMA_INTERRUPT_MUX) == TOP_DMA_INTERRUPT_MUX_OFFSET);
static_assert(offsetof(TOP_Type, DDR_ADDR_MODE) == 0x064U);

/// @brief VBUS-valid bit in the TOP USB PHY control/status register.
static constexpr auto TOP_USB_PHY_VBUS_VALID_BIT = 0U;
/// @brief First bit of the USB remap address [39:32] field in DDR address mode.
static constexpr auto TOP_DDR_ADDR_MODE_USB_REMAP_SHIFT = 16U;
/// @brief Mask of the USB remap address [39:32] field in DDR address mode.
static constexpr auto TOP_DDR_ADDR_MODE_USB_REMAP_MASK = 0xFFUL;
/// @brief First bit of the video remap address [39:32] field in DDR address mode.
static constexpr auto TOP_DDR_ADDR_MODE_VD_REMAP_SHIFT = 24U;
/// @brief Mask of the video remap address [39:32] field in DDR address mode.
static constexpr auto TOP_DDR_ADDR_MODE_VD_REMAP_MASK = 0xFFUL;
/// @brief Byte offset of the TOP software-reset register.
static constexpr auto TOP_SW_RESET_OFFSET = 0x3000UL;
/// @brief JPEG reset bit in the TOP software-reset register.
static constexpr auto TOP_SW_RESET_JPEG_BIT = 4U;

/// @brief Byte offset of CLK_EN0 clock-control register.
static constexpr auto CLKGEN_CLK_EN0_OFFSET = 0x000UL;
/// @brief Byte offset of CLK_EN1 clock-control register.
static constexpr auto CLKGEN_CLK_EN1_OFFSET = 0x004UL;
/// @brief Byte offset of CLK_EN2 clock-control register.
static constexpr auto CLKGEN_CLK_EN2_OFFSET = 0x008UL;
/// @brief Byte offset of CLK_EN3 clock-control register.
static constexpr auto CLKGEN_CLK_EN3_OFFSET = 0x00CUL;
/// @brief Byte offset of CLK_EN4 clock-control register.
static constexpr auto CLKGEN_CLK_EN4_OFFSET = 0x010UL;
/// @brief Byte offset of CLK_SEL0 clock-control register.
static constexpr auto CLKGEN_CLK_SEL0_OFFSET = 0x020UL;
/// @brief Byte offset of CLK_BYP0 clock-control register.
static constexpr auto CLKGEN_CLK_BYP0_OFFSET = 0x030UL;
/// @brief Byte offset of CLK_BYP1 clock-control register.
static constexpr auto CLKGEN_CLK_BYP1_OFFSET = 0x034UL;

/// @brief Byte offset of the CPU_AXI0 divider register from CLKGEN.
static constexpr auto CLKGEN_DIV_OFF_CPU_AXI0 = 0x048UL;
/// @brief Byte offset of the GPIO_DB divider register from CLKGEN.
static constexpr auto CLKGEN_DIV_OFF_GPIO_DB = 0x094UL;
/// @brief Byte offset of the SDMA_AUD0 divider register from CLKGEN.
static constexpr auto CLKGEN_DIV_OFF_SDMA_AUD0 = 0x098UL;
/// @brief Byte offset of the SDMA_AUD1 divider register from CLKGEN.
static constexpr auto CLKGEN_DIV_OFF_SDMA_AUD1 = 0x09CUL;
/// @brief Byte offset of the SDMA_AUD2 divider register from CLKGEN.
static constexpr auto CLKGEN_DIV_OFF_SDMA_AUD2 = 0x0A0UL;
/// @brief Byte offset of the SDMA_AUD3 divider register from CLKGEN.
static constexpr auto CLKGEN_DIV_OFF_SDMA_AUD3 = 0x0A4UL;
/// @brief Byte offset of the AXI4 divider register from CLKGEN.
static constexpr auto CLKGEN_DIV_OFF_AXI4 = 0x0B8UL;
/// @brief Byte offset of the AXI6 divider register from CLKGEN.
static constexpr auto CLKGEN_DIV_OFF_AXI6 = 0x0BCUL;
/// @brief Byte offset of the 1M divider register from CLKGEN.
static constexpr auto CLKGEN_DIV_OFF_1M = 0x0FCUL;
/// @brief Byte offset of the SPI divider register from CLKGEN.
static constexpr auto CLKGEN_DIV_OFF_SPI = 0x100UL;
/// @brief Byte offset of the I2C divider register from CLKGEN.
static constexpr auto CLKGEN_DIV_OFF_I2C = 0x104UL;
/// @brief Byte offset of the SD0 divider register from CLKGEN.
static constexpr auto CLKGEN_DIV_OFF_SD0 = 0x070UL;
/// @brief Byte offset of the 100K_SD0 divider register from CLKGEN.
static constexpr auto CLKGEN_DIV_OFF_100K_SD0 = 0x078UL;
/// @brief Byte offset of the SD1 divider register from CLKGEN.
static constexpr auto CLKGEN_DIV_OFF_SD1 = 0x07CUL;
/// @brief Byte offset of the 100K_SD1 divider register from CLKGEN.
static constexpr auto CLKGEN_DIV_OFF_100K_SD1 = 0x084UL;
/// @brief Byte offset of the PWM_SRC divider register from CLKGEN.
static constexpr auto CLKGEN_DIV_OFF_PWM_SRC = 0x120UL;
/// @brief Byte offset of the C906_0_0 divider register from CLKGEN.
static constexpr auto CLKGEN_DIV_OFF_C906_0_0 = 0x130UL;
/// @brief Byte offset of the C906_0_1 divider register from CLKGEN.
static constexpr auto CLKGEN_DIV_OFF_C906_0_1 = 0x134UL;
/// @brief Byte offset of the C906_1_0 divider register from CLKGEN.
static constexpr auto CLKGEN_DIV_OFF_C906_1_0 = 0x138UL;
/// @brief Byte offset of the C906_1_1 divider register from CLKGEN.
static constexpr auto CLKGEN_DIV_OFF_C906_1_1 = 0x13CUL;

/// @brief Bit for divider reset release.
static constexpr auto CLKGEN_DIV_RESET_BIT = (1UL << 0);
/// @brief Bit for divider register-factor selection.
static constexpr auto CLKGEN_DIV_USE_REG_FACTOR_BIT = (1UL << 3);
/// @brief Least-significant bit position of divider parent-clock selector.
static constexpr auto CLKGEN_DIV_SRC_SHIFT = 8U;
/// @brief Bit width of divider parent-clock selector.
static constexpr auto CLKGEN_DIV_SRC_WIDTH = 2U;
/// @brief Least-significant bit position of divider-factor field.
static constexpr auto CLKGEN_DIV_FACTOR_SHIFT = 16U;

/// @brief Parent-clock selector encoding for FPLL.
static constexpr auto CLKGEN_SRC_FPLL = 0UL;
/// @brief Parent-clock selector encoding for DISPPLL.
static constexpr auto CLKGEN_SRC_DISPPLL = 1UL;

/// @brief Bit width of the AXI4 divider-factor field.
static constexpr auto CLKGEN_DIV_AXI4_FACTOR_WIDTH = 4U;
/// @brief Maximum divider factor of the AXI4 branch.
static constexpr auto CLKGEN_AXI4_MAX_FACTOR = 15U;
/// @brief Hardware initial divider factor of the AXI4 branch.
static constexpr auto CLKGEN_AXI4_INITIAL_FACTOR = 5U;
/// @brief Bit width of the CPU_AXI0 divider-factor field.
static constexpr auto CLKGEN_DIV_CPU_AXI0_FACTOR_WIDTH = 4U;
/// @brief Hardware initial divider factor of the CPU_AXI0 branch.
static constexpr auto CLKGEN_CPU_AXI0_INITIAL_FACTOR = 3U;
/// @brief Bit width of the AXI6 divider-factor field.
static constexpr auto CLKGEN_DIV_AXI6_FACTOR_WIDTH = 4U;
/// @brief Maximum divider factor of the AXI6 branch.
static constexpr auto CLKGEN_AXI6_MAX_FACTOR = 15U;
/// @brief Hardware initial divider factor of the AXI6 branch.
static constexpr auto CLKGEN_AXI6_INITIAL_FACTOR = 15U;
/// @brief Bit width of the SD divider-factor field.
static constexpr auto CLKGEN_DIV_SD_FACTOR_WIDTH = 5U;
/// @brief Hardware initial divider factor of the SD branch.
static constexpr auto CLKGEN_SD_INITIAL_FACTOR = 15U;
/// @brief Bit width of the SD_100K divider-factor field.
static constexpr auto CLKGEN_DIV_SD_100K_FACTOR_WIDTH = 8U;
/// @brief Hardware initial divider factor of the SD_100K branch.
static constexpr auto CLKGEN_SD_100K_INITIAL_FACTOR = 10U;
/// @brief Bit width of the 1M divider-factor field.
static constexpr auto CLKGEN_DIV_1M_FACTOR_WIDTH = 6U;
/// @brief Hardware initial divider factor of the 1M branch.
static constexpr auto CLKGEN_1M_INITIAL_FACTOR = 25U;
/// @brief Bit width of the SPI divider-factor field.
static constexpr auto CLKGEN_DIV_SPI_FACTOR_WIDTH = 6U;
/// @brief Hardware initial divider factor of the SPI branch.
static constexpr auto CLKGEN_SPI_INITIAL_FACTOR = 8U;
/// @brief Bit width of the I2C divider-factor field.
static constexpr auto CLKGEN_DIV_I2C_FACTOR_WIDTH = 4U;
/// @brief Hardware initial divider factor of the I2C branch.
static constexpr auto CLKGEN_I2C_INITIAL_FACTOR = 1U;
/// @brief Bit width of the PWM_SRC divider-factor field.
static constexpr auto CLKGEN_DIV_PWM_SRC_FACTOR_WIDTH = 6U;
/// @brief Hardware initial divider factor of the PWM_SRC branch.
static constexpr auto CLKGEN_PWM_SRC_INITIAL_FACTOR = 10U;
/// @brief Bit width of the C906 divider-factor field.
static constexpr auto CLKGEN_DIV_C906_FACTOR_WIDTH = 4U;
/// @brief Hardware initial divider factor of the C906_0_0 branch.
static constexpr auto CLKGEN_C906_0_0_INITIAL_FACTOR = 1U;
/// @brief Hardware initial divider factor of the C906_0_1 branch.
static constexpr auto CLKGEN_C906_0_1_INITIAL_FACTOR = 2U;
/// @brief Hardware initial divider factor of the C906_1_0 branch.
static constexpr auto CLKGEN_C906_1_0_INITIAL_FACTOR = 2U;
/// @brief Hardware initial divider factor of the C906_1_1 branch.
static constexpr auto CLKGEN_C906_1_1_INITIAL_FACTOR = 2U;

/**
 * @brief RTC_25M clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_RTC_25M CLKGEN_CLK_EN0_OFFSET, 8U
/**
 * @brief TEMPSEN clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_TEMPSEN CLKGEN_CLK_EN0_OFFSET, 9U
/**
 * @brief SARADC clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_SARADC CLKGEN_CLK_EN0_OFFSET, 10U
/**
 * @brief EFUSE clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_EFUSE CLKGEN_CLK_EN0_OFFSET, 11U
/**
 * @brief APB_EFUSE clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_APB_EFUSE CLKGEN_CLK_EN0_OFFSET, 12U
/**
 * @brief XTAL_MISC clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_XTAL_MISC CLKGEN_CLK_EN0_OFFSET, 14U
/**
 * @brief APB_GPIO clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_APB_GPIO CLKGEN_CLK_EN0_OFFSET, 29U
/**
 * @brief APB_GPIO_INTR clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_APB_GPIO_INTR CLKGEN_CLK_EN0_OFFSET, 30U
/**
 * @brief GPIO_DB clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_GPIO_DB CLKGEN_CLK_EN0_OFFSET, 31U
/**
 * @brief SDMA_AXI clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_SDMA_AXI CLKGEN_CLK_EN1_OFFSET, 1U
/**
 * @brief SDMA_AUD0 clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_SDMA_AUD0 CLKGEN_CLK_EN1_OFFSET, 2U
/**
 * @brief SDMA_AUD1 clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_SDMA_AUD1 CLKGEN_CLK_EN1_OFFSET, 3U
/**
 * @brief SDMA_AUD2 clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_SDMA_AUD2 CLKGEN_CLK_EN1_OFFSET, 4U
/**
 * @brief SDMA_AUD3 clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_SDMA_AUD3 CLKGEN_CLK_EN1_OFFSET, 5U
/**
 * @brief APB_I2C clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_APB_I2C CLKGEN_CLK_EN1_OFFSET, 6U
/**
 * @brief APB_WDT clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_APB_WDT CLKGEN_CLK_EN1_OFFSET, 7U
/**
 * @brief APB_PWM clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_APB_PWM CLKGEN_CLK_EN1_OFFSET, 8U
/**
 * @brief APB_SPI0 clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_APB_SPI0 CLKGEN_CLK_EN1_OFFSET, 9U
/**
 * @brief APB_SPI1 clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_APB_SPI1 CLKGEN_CLK_EN1_OFFSET, 10U
/**
 * @brief APB_SPI2 clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_APB_SPI2 CLKGEN_CLK_EN1_OFFSET, 11U
/**
 * @brief APB_SPI3 clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_APB_SPI3 CLKGEN_CLK_EN1_OFFSET, 12U
/**
 * @brief UART0 clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_UART0 CLKGEN_CLK_EN1_OFFSET, 14U
/**
 * @brief APB_UART0 clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_APB_UART0 CLKGEN_CLK_EN1_OFFSET, 15U
/**
 * @brief UART1 clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_UART1 CLKGEN_CLK_EN1_OFFSET, 16U
/**
 * @brief APB_UART1 clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_APB_UART1 CLKGEN_CLK_EN1_OFFSET, 17U
/**
 * @brief UART2 clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_UART2 CLKGEN_CLK_EN1_OFFSET, 18U
/**
 * @brief APB_UART2 clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_APB_UART2 CLKGEN_CLK_EN1_OFFSET, 19U
/**
 * @brief UART3 clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_UART3 CLKGEN_CLK_EN1_OFFSET, 20U
/**
 * @brief APB_UART3 clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_APB_UART3 CLKGEN_CLK_EN1_OFFSET, 21U
/**
 * @brief UART4 clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_UART4 CLKGEN_CLK_EN1_OFFSET, 22U
/**
 * @brief APB_UART4 clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_APB_UART4 CLKGEN_CLK_EN1_OFFSET, 23U
/**
 * @brief APB_I2S0 clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_APB_I2S0 CLKGEN_CLK_EN1_OFFSET, 24U
/**
 * @brief APB_I2S1 clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_APB_I2S1 CLKGEN_CLK_EN1_OFFSET, 25U
/**
 * @brief APB_I2S2 clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_APB_I2S2 CLKGEN_CLK_EN1_OFFSET, 26U
/**
 * @brief APB_I2S3 clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_APB_I2S3 CLKGEN_CLK_EN1_OFFSET, 27U
/**
 * @brief AXI4_USB clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_AXI4_USB CLKGEN_CLK_EN1_OFFSET, 28U
/**
 * @brief APB_USB clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_APB_USB CLKGEN_CLK_EN1_OFFSET, 29U
/**
 * @brief AXI4 clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_AXI4 CLKGEN_CLK_EN2_OFFSET, 1U
/**
 * @brief AXI6 clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_AXI6 CLKGEN_CLK_EN2_OFFSET, 2U
/**
 * @brief 1M clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_1M CLKGEN_CLK_EN3_OFFSET, 5U
/**
 * @brief SPI clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_SPI CLKGEN_CLK_EN3_OFFSET, 6U
/**
 * @brief I2C clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_I2C CLKGEN_CLK_EN3_OFFSET, 7U
/**
 * @brief PM clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_PM CLKGEN_CLK_EN3_OFFSET, 8U
/**
 * @brief TIMER0 clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_TIMER0 CLKGEN_CLK_EN3_OFFSET, 9U
/**
 * @brief TIMER1 clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_TIMER1 CLKGEN_CLK_EN3_OFFSET, 10U
/**
 * @brief TIMER2 clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_TIMER2 CLKGEN_CLK_EN3_OFFSET, 11U
/**
 * @brief TIMER3 clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_TIMER3 CLKGEN_CLK_EN3_OFFSET, 12U
/**
 * @brief TIMER4 clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_TIMER4 CLKGEN_CLK_EN3_OFFSET, 13U
/**
 * @brief TIMER5 clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_TIMER5 CLKGEN_CLK_EN3_OFFSET, 14U
/**
 * @brief TIMER6 clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_TIMER6 CLKGEN_CLK_EN3_OFFSET, 15U
/**
 * @brief TIMER7 clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_TIMER7 CLKGEN_CLK_EN3_OFFSET, 16U
/**
 * @brief APB_I2C0 clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_APB_I2C0 CLKGEN_CLK_EN3_OFFSET, 17U
/**
 * @brief APB_I2C1 clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_APB_I2C1 CLKGEN_CLK_EN3_OFFSET, 18U
/**
 * @brief APB_I2C2 clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_APB_I2C2 CLKGEN_CLK_EN3_OFFSET, 19U
/**
 * @brief APB_I2C3 clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_APB_I2C3 CLKGEN_CLK_EN3_OFFSET, 20U
/**
 * @brief APB_I2C4 clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_APB_I2C4 CLKGEN_CLK_EN3_OFFSET, 21U
/**
 * @brief WGN clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_WGN CLKGEN_CLK_EN3_OFFSET, 22U
/**
 * @brief WGN0 clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_WGN0 CLKGEN_CLK_EN3_OFFSET, 23U
/**
 * @brief WGN1 clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_WGN1 CLKGEN_CLK_EN3_OFFSET, 24U
/**
 * @brief WGN2 clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_WGN2 CLKGEN_CLK_EN3_OFFSET, 25U
/**
 * @brief KEYSCAN clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_KEYSCAN CLKGEN_CLK_EN3_OFFSET, 26U
/**
 * @brief AHB_SF1 clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_AHB_SF1 CLKGEN_CLK_EN3_OFFSET, 27U
/**
 * @brief AUDSRC clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_AUDSRC CLKGEN_CLK_EN4_OFFSET, 1U
/**
 * @brief APB_AUDSRC clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_APB_AUDSRC CLKGEN_CLK_EN4_OFFSET, 2U
/**
 * @brief PWM_SRC clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_PWM_SRC CLKGEN_CLK_EN4_OFFSET, 4U
/**
 * @brief RTCSYS_SRC0 clock-gate coordinates (register offset, bit index).
 */
#define CLKGEN_GATE_RTCSYS_SRC0 CLKGEN_CLK_EN4_OFFSET, 6U

/**
 * @brief PWM_SRC crystal-bypass coordinates (register offset, bit index).
 */
#define CLKGEN_BYPASS_PWM_SRC CLKGEN_CLK_BYP0_OFFSET, 15U
/**
 * @brief AXI4 crystal-bypass coordinates (register offset, bit index).
 */
#define CLKGEN_BYPASS_AXI4 CLKGEN_CLK_BYP0_OFFSET, 19U
/**
 * @brief AXI6 crystal-bypass coordinates (register offset, bit index).
 */
#define CLKGEN_BYPASS_AXI6 CLKGEN_CLK_BYP0_OFFSET, 20U
/**
 * @brief SPI crystal-bypass coordinates (register offset, bit index).
 */
#define CLKGEN_BYPASS_SPI CLKGEN_CLK_BYP0_OFFSET, 30U
/**
 * @brief I2C crystal-bypass coordinates (register offset, bit index).
 */
#define CLKGEN_BYPASS_I2C CLKGEN_CLK_BYP0_OFFSET, 31U
/// @brief A53 core-clock selector bit mask.
static constexpr auto CLKGEN_SEL0_A53_BIT = (1UL << 0);
/// @brief C906_0 core-clock selector bit mask.
static constexpr auto CLKGEN_SEL0_C906_0_BIT = (1UL << 23);
/// @brief C906_1 core-clock selector bit mask.
static constexpr auto CLKGEN_SEL0_C906_1_BIT = (1UL << 24);
/// @brief A53 core-clock selector bit position.
static constexpr auto CLKGEN_SEL0_A53_SHIFT = 0U;
/// @brief C906_0 core-clock selector bit position.
static constexpr auto CLKGEN_SEL0_C906_0_SHIFT = 23U;
/// @brief C906_1 core-clock selector bit position.
static constexpr auto CLKGEN_SEL0_C906_1_SHIFT = 24U;

/**
 * @brief Clock-generator register block.
 *
 * @note Padding areas are not exposed as accessible registers.
 * @see SG2002 TRM v1.02, Table 8.51
 */
typedef struct
{
    volatile uint32_t CLK_EN[5];           /*!< clock-gate register array, Address offset: 0x000 */
    uint32_t RESERVED_014[3];              /*!< Reserved, Address offset: 0x014 */
    volatile uint32_t CLK_SEL0;            /*!< core clock-source selector, Address offset: 0x020 */
    uint32_t RESERVED_024[3];              /*!< Reserved, Address offset: 0x024 */
    volatile uint32_t CLK_BYP0;            /*!< clock-bypass register zero, Address offset: 0x030 */
    volatile uint32_t CLK_BYP1;            /*!< clock-bypass register one, Address offset: 0x034 */
    uint32_t RESERVED_038[2];              /*!< Reserved, Address offset: 0x038 */
    volatile uint32_t DIV_A53_0;           /*!< clock-divider register for A53_0, Address offset: 0x040 */
    volatile uint32_t DIV_A53_1;           /*!< clock-divider register for A53_1, Address offset: 0x044 */
    volatile uint32_t DIV_CPU_AXI0;        /*!< clock-divider register for CPU_AXI0, Address offset: 0x048 */
    uint32_t RESERVED_04C;                 /*!< Reserved, Address offset: 0x04C */
    volatile uint32_t DIV_CPU_GIC;         /*!< clock-divider register for CPU_GIC, Address offset: 0x050 */
    volatile uint32_t DIV_TPU;             /*!< clock-divider register for TPU, Address offset: 0x054 */
    uint32_t RESERVED_058[3];              /*!< Reserved, Address offset: 0x058 */
    volatile uint32_t DIV_EMMC;            /*!< clock-divider register for EMMC, Address offset: 0x064 */
    uint32_t RESERVED_068;                 /*!< Reserved, Address offset: 0x068 */
    volatile uint32_t DIV_100K_EMMC;       /*!< clock-divider register for 100K_EMMC, Address offset: 0x06C */
    volatile uint32_t DIV_SD0;             /*!< clock-divider register for SD0, Address offset: 0x070 */
    uint32_t RESERVED_074;                 /*!< Reserved, Address offset: 0x074 */
    volatile uint32_t DIV_100K_SD0;        /*!< clock-divider register for 100K_SD0, Address offset: 0x078 */
    volatile uint32_t DIV_SD1;             /*!< clock-divider register for SD1, Address offset: 0x07C */
    uint32_t RESERVED_080;                 /*!< Reserved, Address offset: 0x080 */
    volatile uint32_t DIV_100K_SD1;        /*!< clock-divider register for 100K_SD1, Address offset: 0x084 */
    volatile uint32_t DIV_SPI_NAND;        /*!< clock-divider register for SPI_NAND, Address offset: 0x088 */
    volatile uint32_t DIV_500M_ETH0;       /*!< clock-divider register for 500M_ETH0, Address offset: 0x08C */
    uint32_t RESERVED_090;                 /*!< Reserved, Address offset: 0x090 */
    volatile uint32_t DIV_GPIO_DB;         /*!< clock-divider register for GPIO_DB, Address offset: 0x094 */
    volatile uint32_t DIV_SDMA_AUD[4];     /*!< clock-divider register for SDMA_AUD, Address offset: 0x098 */
    volatile uint32_t DIV_CAM0_200;        /*!< clock-divider register for CAM0_200, Address offset: 0x0A8 */
    uint32_t RESERVED_0AC[3];              /*!< Reserved, Address offset: 0x0AC */
    volatile uint32_t DIV_AXI4;            /*!< clock-divider register for AXI4, Address offset: 0x0B8 */
    volatile uint32_t DIV_AXI6;            /*!< clock-divider register for AXI6, Address offset: 0x0BC */
    uint32_t RESERVED_0C0;                 /*!< Reserved, Address offset: 0x0C0 */
    volatile uint32_t DIV_DSI_ESC;         /*!< clock-divider register for DSI_ESC, Address offset: 0x0C4 */
    volatile uint32_t DIV_AXI_VIP;         /*!< clock-divider register for AXI_VIP, Address offset: 0x0C8 */
    uint32_t RESERVED_0CC;                 /*!< Reserved, Address offset: 0x0CC */
    volatile uint32_t DIV_SRC_VIP_SYS_0;   /*!< clock-divider register for
                                               SRC_VIP_SYS_0, Address offset: 0x0D0 */
    uint32_t RESERVED_0D4;                 /*!< Reserved, Address offset: 0x0D4 */
    volatile uint32_t DIV_SRC_VIP_SYS_1;   /*!< clock-divider register for
                                               SRC_VIP_SYS_1, Address offset: 0x0D8 */
    uint32_t RESERVED_0DC;                 /*!< Reserved, Address offset: 0x0DC */
    volatile uint32_t DIV_DISP_SRC_VIP;    /*!< clock-divider register for
                                               DISP_SRC_VIP, Address offset: 0x0E0 */
    volatile uint32_t DIV_AXI_VIDEO_CODEC; /*!< clock-divider register for
                                                AXI_VIDEO_CODEC, Address offset: 0x0E4 */
    uint32_t RESERVED_0E8;                 /*!< Reserved, Address offset: 0x0E8 */
    volatile uint32_t DIV_VC_SRC0;         /*!< clock-divider register for VC_SRC0, Address offset: 0x0EC */
    uint32_t RESERVED_0F0[3];              /*!< Reserved, Address offset: 0x0F0 */
    volatile uint32_t DIV_1M;              /*!< clock-divider register for 1M, Address offset: 0x0FC */
    volatile uint32_t DIV_SPI;             /*!< clock-divider register for SPI, Address offset: 0x100 */
    volatile uint32_t DIV_I2C;             /*!< clock-divider register for I2C, Address offset: 0x104 */
    uint32_t RESERVED_108[2];              /*!< Reserved, Address offset: 0x108 */
    volatile uint32_t DIV_SRC_VIP_SYS_2;   /*!< clock-divider register for
                                               SRC_VIP_SYS_2, Address offset: 0x110 */
    uint32_t RESERVED_114;                 /*!< Reserved, Address offset: 0x114 */
    volatile uint32_t DIV_AUDSRC;          /*!< clock-divider register for AUDSRC, Address offset: 0x118 */
    uint32_t RESERVED_11C;                 /*!< Reserved, Address offset: 0x11C */
    volatile uint32_t DIV_PWM_SRC;         /*!< clock-divider register for PWM_SRC, Address offset: 0x120 */
    uint32_t RESERVED_124;                 /*!< Reserved, Address offset: 0x124 */
    volatile uint32_t DIV_AP_DEBUG;        /*!< clock-divider register for AP_DEBUG, Address offset: 0x128 */
    volatile uint32_t DIV_RTCSYS_SRC_0;    /*!< clock-divider register for
                                               RTCSYS_SRC_0, Address offset: 0x12C */
    volatile uint32_t DIV_C906[4];         /*!< clock-divider register for C906, Address offset: 0x130 */
    volatile uint32_t DIV_SRC_VIP_SYS_3;   /*!< clock-divider register for
                                               SRC_VIP_SYS_3, Address offset: 0x140 */
    volatile uint32_t DIV_SRC_VIP_SYS_4;   /*!< clock-divider register for
                                               SRC_VIP_SYS_4, Address offset: 0x144 */
} CLKGEN_Type;

/**
 * @brief CLKGEN register-instance pointer.
 */
#define CLKGEN ((CLKGEN_Type *)(uintptr_t)CLKGEN_BASE)
static_assert(offsetof(CLKGEN_Type, CLK_EN[0]) == 0x000U);
static_assert(offsetof(CLKGEN_Type, CLK_EN[1]) == 0x004U);
static_assert(offsetof(CLKGEN_Type, CLK_EN[2]) == 0x008U);
static_assert(offsetof(CLKGEN_Type, CLK_EN[3]) == 0x00CU);
static_assert(offsetof(CLKGEN_Type, CLK_EN[4]) == 0x010U);
static_assert(offsetof(CLKGEN_Type, CLK_SEL0) == 0x020U);
static_assert(offsetof(CLKGEN_Type, CLK_BYP0) == 0x030U);
static_assert(offsetof(CLKGEN_Type, CLK_BYP1) == 0x034U);
static_assert(offsetof(CLKGEN_Type, DIV_A53_0) == 0x040U);
static_assert(offsetof(CLKGEN_Type, DIV_A53_1) == 0x044U);
static_assert(offsetof(CLKGEN_Type, DIV_CPU_AXI0) == 0x048U);
static_assert(offsetof(CLKGEN_Type, DIV_CPU_GIC) == 0x050U);
static_assert(offsetof(CLKGEN_Type, DIV_TPU) == 0x054U);
static_assert(offsetof(CLKGEN_Type, DIV_EMMC) == 0x064U);
static_assert(offsetof(CLKGEN_Type, DIV_100K_EMMC) == 0x06CU);
static_assert(offsetof(CLKGEN_Type, DIV_SD0) == 0x070U);
static_assert(offsetof(CLKGEN_Type, DIV_100K_SD0) == 0x078U);
static_assert(offsetof(CLKGEN_Type, DIV_SD1) == 0x07CU);
static_assert(offsetof(CLKGEN_Type, DIV_100K_SD1) == 0x084U);
static_assert(offsetof(CLKGEN_Type, DIV_SPI_NAND) == 0x088U);
static_assert(offsetof(CLKGEN_Type, DIV_500M_ETH0) == 0x08CU);
static_assert(offsetof(CLKGEN_Type, DIV_GPIO_DB) == 0x094U);
static_assert(offsetof(CLKGEN_Type, DIV_SDMA_AUD[0]) == 0x098U);
static_assert(offsetof(CLKGEN_Type, DIV_SDMA_AUD[1]) == 0x09CU);
static_assert(offsetof(CLKGEN_Type, DIV_SDMA_AUD[2]) == 0x0A0U);
static_assert(offsetof(CLKGEN_Type, DIV_SDMA_AUD[3]) == 0x0A4U);
static_assert(offsetof(CLKGEN_Type, DIV_CAM0_200) == 0x0A8U);
static_assert(offsetof(CLKGEN_Type, DIV_AXI4) == 0x0B8U);
static_assert(offsetof(CLKGEN_Type, DIV_AXI6) == 0x0BCU);
static_assert(offsetof(CLKGEN_Type, DIV_DSI_ESC) == 0x0C4U);
static_assert(offsetof(CLKGEN_Type, DIV_AXI_VIP) == 0x0C8U);
static_assert(offsetof(CLKGEN_Type, DIV_SRC_VIP_SYS_0) == 0x0D0U);
static_assert(offsetof(CLKGEN_Type, DIV_SRC_VIP_SYS_1) == 0x0D8U);
static_assert(offsetof(CLKGEN_Type, DIV_DISP_SRC_VIP) == 0x0E0U);
static_assert(offsetof(CLKGEN_Type, DIV_AXI_VIDEO_CODEC) == 0x0E4U);
static_assert(offsetof(CLKGEN_Type, DIV_VC_SRC0) == 0x0ECU);
static_assert(offsetof(CLKGEN_Type, DIV_1M) == 0x0FCU);
static_assert(offsetof(CLKGEN_Type, DIV_SPI) == 0x100U);
static_assert(offsetof(CLKGEN_Type, DIV_I2C) == 0x104U);
static_assert(offsetof(CLKGEN_Type, DIV_SRC_VIP_SYS_2) == 0x110U);
static_assert(offsetof(CLKGEN_Type, DIV_AUDSRC) == 0x118U);
static_assert(offsetof(CLKGEN_Type, DIV_PWM_SRC) == 0x120U);
static_assert(offsetof(CLKGEN_Type, DIV_AP_DEBUG) == 0x128U);
static_assert(offsetof(CLKGEN_Type, DIV_RTCSYS_SRC_0) == 0x12CU);
static_assert(offsetof(CLKGEN_Type, DIV_C906[0]) == 0x130U);
static_assert(offsetof(CLKGEN_Type, DIV_C906[1]) == 0x134U);
static_assert(offsetof(CLKGEN_Type, DIV_C906[2]) == 0x138U);
static_assert(offsetof(CLKGEN_Type, DIV_C906[3]) == 0x13CU);
static_assert(offsetof(CLKGEN_Type, DIV_SRC_VIP_SYS_3) == 0x140U);
static_assert(offsetof(CLKGEN_Type, DIV_SRC_VIP_SYS_4) == 0x144U);
static_assert(offsetof(CLKGEN_Type, DIV_AXI4) == 0x0B8U);
static_assert(offsetof(CLKGEN_Type, DIV_C906) == 0x130U);

/**
 * @brief Expand named CLKGEN registers for static validation and runtime selection.
 *
 * @param Expansion macro accepting one CLKGEN_Type member designator.
 */
#define SG2002_CLKGEN_REGISTERS(X) \
    X(CLK_EN[0])                   \
    X(CLK_EN[1])                   \
    X(CLK_EN[2])                   \
    X(CLK_EN[3])                   \
    X(CLK_EN[4])                   \
    X(CLK_SEL0)                    \
    X(CLK_BYP0)                    \
    X(CLK_BYP1)                    \
    X(DIV_A53_0)                   \
    X(DIV_A53_1)                   \
    X(DIV_CPU_AXI0)                \
    X(DIV_CPU_GIC)                 \
    X(DIV_TPU)                     \
    X(DIV_EMMC)                    \
    X(DIV_100K_EMMC)               \
    X(DIV_SD0)                     \
    X(DIV_100K_SD0)                \
    X(DIV_SD1)                     \
    X(DIV_100K_SD1)                \
    X(DIV_SPI_NAND)                \
    X(DIV_500M_ETH0)               \
    X(DIV_GPIO_DB)                 \
    X(DIV_SDMA_AUD[0])             \
    X(DIV_SDMA_AUD[1])             \
    X(DIV_SDMA_AUD[2])             \
    X(DIV_SDMA_AUD[3])             \
    X(DIV_CAM0_200)                \
    X(DIV_AXI4)                    \
    X(DIV_AXI6)                    \
    X(DIV_DSI_ESC)                 \
    X(DIV_AXI_VIP)                 \
    X(DIV_SRC_VIP_SYS_0)           \
    X(DIV_SRC_VIP_SYS_1)           \
    X(DIV_DISP_SRC_VIP)            \
    X(DIV_AXI_VIDEO_CODEC)         \
    X(DIV_VC_SRC0)                 \
    X(DIV_1M)                      \
    X(DIV_SPI)                     \
    X(DIV_I2C)                     \
    X(DIV_SRC_VIP_SYS_2)           \
    X(DIV_AUDSRC)                  \
    X(DIV_PWM_SRC)                 \
    X(DIV_AP_DEBUG)                \
    X(DIV_RTCSYS_SRC_0)            \
    X(DIV_C906[0])                 \
    X(DIV_C906[1])                 \
    X(DIV_C906[2])                 \
    X(DIV_C906[3])                 \
    X(DIV_SRC_VIP_SYS_3)           \
    X(DIV_SRC_VIP_SYS_4)

/// @brief Least-significant bit position of G6 PLL predivider field.
static constexpr auto PLL_G6_PREDIV_SHIFT = 0U;
/// @brief Least-significant bit position of G6 PLL postdivider field.
static constexpr auto PLL_G6_POSTDIV_SHIFT = 8U;
/// @brief Least-significant bit position of G6 PLL multiplier field.
static constexpr auto PLL_G6_MULTIPLIER_SHIFT = 17U;
/// @brief Bit width of G6 PLL divider field.
static constexpr auto PLL_G6_DIVIDER_WIDTH = 7U;

/// @brief Byte offset of G6 MPLL control register.
static constexpr auto PLL_G6_MPLL_OFFSET = 0x008UL;
/// @brief Byte offset of G6 TPLL control register.
static constexpr auto PLL_G6_TPLL_OFFSET = 0x00CUL;
/// @brief Byte offset of G6 FPLL control register.
static constexpr auto PLL_G6_FPLL_OFFSET = 0x010UL;

/**
 * @brief G6 MPLL, TPLL, and FPLL control registers.
 */
typedef struct
{
    volatile uint32_t CTRL;         /*!< Group6 PLL control register, Address offset: 0x000 */
    volatile const uint32_t STATUS; /*!< Group6 PLL status register, Address offset: 0x004 */
    volatile uint32_t MPLL;         /*!< MPLL control register, Address offset: 0x008 */
    volatile uint32_t TPLL;         /*!< TPLL control register, Address offset: 0x00C */
    volatile uint32_t FPLL;         /*!< FPLL control register, Address offset: 0x010 */
    uint32_t RESERVED_014[11];      /*!< Reserved, Address offset: 0x014 */
    volatile uint32_t SSC_SYN_CTRL; /*!< Group6 PLL synthesizer control register, Address offset: 0x040 */
    uint32_t RESERVED_044[3];       /*!< Reserved, Address offset: 0x044 */
    volatile uint32_t DPLL_SSC_SYN_CTRL; /*!< DPLL synthesizer control register, Address offset: 0x050 */
    volatile uint32_t DPLL_SSC_SYN_SET;  /*!< DPLL synthesizer set register, Address offset: 0x054 */
    volatile uint32_t DPLL_SSC_SYN_SPAN; /*!< DPLL synthesizer span register, Address offset: 0x058 */
    volatile uint32_t DPLL_SSC_SYN_STEP; /*!< DPLL synthesizer step register, Address offset: 0x05C */
    volatile uint32_t MPLL_SSC_SYN_CTRL; /*!< MPLL synthesizer control register, Address offset: 0x060 */
    volatile uint32_t MPLL_SSC_SYN_SET;  /*!< MPLL synthesizer set register, Address offset: 0x064 */
    volatile uint32_t MPLL_SSC_SYN_SPAN; /*!< MPLL synthesizer span register, Address offset: 0x068 */
    volatile uint32_t MPLL_SSC_SYN_STEP; /*!< MPLL synthesizer step register, Address offset: 0x06C */
    volatile uint32_t TPLL_SSC_SYN_CTRL; /*!< TPLL synthesizer control register, Address offset: 0x070 */
    volatile uint32_t TPLL_SSC_SYN_SET;  /*!< TPLL synthesizer set register, Address offset: 0x074 */
    volatile uint32_t TPLL_SSC_SYN_SPAN; /*!< TPLL synthesizer span register, Address offset: 0x078 */
    volatile uint32_t TPLL_SSC_SYN_STEP; /*!< TPLL synthesizer step register, Address offset: 0x07C */
} PLL_G6_Type;

/**
 * @brief PLL_G6 register-instance pointer.
 */
#define PLL_G6 ((PLL_G6_Type *)(uintptr_t)PLL_G6_BASE)
static_assert(offsetof(PLL_G6_Type, MPLL) == PLL_G6_MPLL_OFFSET);
static_assert(offsetof(PLL_G6_Type, TPLL) == PLL_G6_TPLL_OFFSET);
static_assert(offsetof(PLL_G6_Type, FPLL) == PLL_G6_FPLL_OFFSET);

/// @brief Element count of the SOFT_RSTN register view.
static constexpr auto RSTGEN_SOFT_RSTN_COUNT = 8U;
/// @brief Byte offset of SOFT_RSTN0 soft-reset register.
static constexpr auto RSTGEN_SOFT_RSTN0_OFFSET = 0x000UL;
/// @brief Byte stride of SOFT_RSTN soft-reset register.
static constexpr auto RSTGEN_SOFT_RSTN_STRIDE = 0x004UL;
/// @brief Indicates active-low soft-reset semantics.
static constexpr auto RSTGEN_SOFT_RSTN_ACTIVE_LOW = 1U;
/// @brief Sentinel for an invalid reset-register or bit coordinate.
static constexpr auto RSTGEN_RESET_LOCATION_INVALID = 0xFFU;

/**
 * @brief Reset-controller register block.
 */
typedef struct
{
    volatile uint32_t SOFT_RSTN[RSTGEN_SOFT_RSTN_COUNT]; /*!< active-low soft-reset
                                                              register array, Address offset: 0x000 */
    volatile uint32_t SOFT_CPUAC_RSTN; /*!< CPUAC soft-reset register, Address offset: 0x020 */
    volatile uint32_t SOFT_CPU_RSTN;   /*!< CPU soft-reset register, Address offset: 0x024 */
} RSTGEN_Type;

/**
 * @brief RSTGEN register-instance pointer.
 */
#define RSTGEN ((RSTGEN_Type *)(uintptr_t)RSTGEN_BASE)
static_assert(offsetof(RSTGEN_Type, SOFT_RSTN) == RSTGEN_SOFT_RSTN0_OFFSET);
static_assert(
    offsetof(RSTGEN_Type, SOFT_CPUAC_RSTN) ==
    RSTGEN_SOFT_RSTN0_OFFSET + RSTGEN_SOFT_RSTN_COUNT * RSTGEN_SOFT_RSTN_STRIDE
);

/**
 * @brief Expand reset-target names and their register/bit coordinates.
 *
 * @param Expansion macro accepting name, reg_index, and bit.
 * @note The RCC implementation builds its internal reset-location table from this map.
 * @see SG2002, TRM, Tables 7.2-7.5, reset coordinates.
 */
#define SG2002_RESET_MAP(X)                                               \
    X(NONE, RSTGEN_RESET_LOCATION_INVALID, RSTGEN_RESET_LOCATION_INVALID) \
    X(SDMA, 0U, 18U)                                                      \
    X(I2S0, 0U, 19U)                                                      \
    X(I2S1, 0U, 20U)                                                      \
    X(I2S2, 0U, 21U)                                                      \
    X(I2S3, 0U, 22U)                                                      \
    X(UART0, 0U, 23U)                                                     \
    X(UART1, 0U, 24U)                                                     \
    X(UART2, 0U, 25U)                                                     \
    X(UART3, 0U, 26U)                                                     \
    X(I2C0, 0U, 27U)                                                      \
    X(I2C1, 0U, 28U)                                                      \
    X(I2C2, 0U, 29U)                                                      \
    X(I2C3, 0U, 30U)                                                      \
    X(I2C4, 0U, 31U)                                                      \
    X(PWM0, 1U, 0U)                                                       \
    X(PWM1, 1U, 1U)                                                       \
    X(PWM2, 1U, 2U)                                                       \
    X(PWM3, 1U, 3U)                                                       \
    X(SPI0, 1U, 8U)                                                       \
    X(SPI1, 1U, 9U)                                                       \
    X(SPI2, 1U, 10U)                                                      \
    X(SPI3, 1U, 11U)                                                      \
    X(GPIO0, 1U, 12U)                                                     \
    X(GPIO1, 1U, 13U)                                                     \
    X(GPIO2, 1U, 14U)                                                     \
    X(EFUSE, 1U, 15U)                                                     \
    X(WDT0, 1U, 16U)                                                      \
    X(TEMPSEN, 1U, 19U)                                                   \
    X(SARADC, 1U, 20U)                                                    \
    X(UART4, 2U, 10U)                                                     \
    X(GPIO3, 2U, 11U)                                                     \
    X(TIMER, 2U, 13U)                                                     \
    X(TIMER0, 2U, 14U)                                                    \
    X(TIMER1, 2U, 15U)                                                    \
    X(TIMER2, 2U, 16U)                                                    \
    X(TIMER3, 2U, 17U)                                                    \
    X(TIMER4, 2U, 18U)                                                    \
    X(TIMER5, 2U, 19U)                                                    \
    X(TIMER6, 2U, 20U)                                                    \
    X(TIMER7, 2U, 21U)                                                    \
    X(WGN0, 2U, 22U)                                                      \
    X(WGN1, 2U, 23U)                                                      \
    X(WGN2, 2U, 24U)                                                      \
    X(KEYSCAN, 2U, 25U)                                                   \
    X(WDT1, 3U, 4U)                                                       \
    X(WDT2, 3U, 5U)                                                       \
    X(SD0, 0U, 16U)                                                       \
    X(SD1, 0U, 17U)

/**
 * @brief Reset-target identifiers generated from the device map.
 */
typedef enum
{
/**
 * @brief Generate an enumerator from the reset map.
 *
 * @param Reset-target name suffix.
 * @param Register index in the map; unused by this expansion.
 * @param Bit index in the map; unused by this expansion.
 */
#define SG2002_RESET_ENUM(name, reg_index, bit) RESET_##name,
    SG2002_RESET_MAP(SG2002_RESET_ENUM)
#undef SG2002_RESET_ENUM
        RESET_TARGET_COUNT /*!< Size of the reset-target ID space. */
} rstgen_reset_target_t;

/**
 * @var rstgen_reset_target_t::RESET_NONE
 * @brief No reset target.
 */
/**
 * @var rstgen_reset_target_t::RESET_SD0
 * @brief SD0 reset target.
 */
/**
 * @var rstgen_reset_target_t::RESET_SD1
 * @brief SD1 reset target.
 * @note Coordinates retain RST_SD1=17 from cv181x-resets.h; TRM Table 7.2 lists this bit as reserved.
 */
/**
 * @var rstgen_reset_target_t::RESET_SDMA
 * @brief SDMA reset target.
 */
/**
 * @var rstgen_reset_target_t::RESET_I2S0
 * @brief I2S0 reset target.
 */
/**
 * @var rstgen_reset_target_t::RESET_I2S1
 * @brief I2S1 reset target.
 */
/**
 * @var rstgen_reset_target_t::RESET_I2S2
 * @brief I2S2 reset target.
 */
/**
 * @var rstgen_reset_target_t::RESET_I2S3
 * @brief I2S3 reset target.
 */
/**
 * @var rstgen_reset_target_t::RESET_UART0
 * @brief UART0 reset target.
 */
/**
 * @var rstgen_reset_target_t::RESET_UART1
 * @brief UART1 reset target.
 */
/**
 * @var rstgen_reset_target_t::RESET_UART2
 * @brief UART2 reset target.
 */
/**
 * @var rstgen_reset_target_t::RESET_UART3
 * @brief UART3 reset target.
 */
/**
 * @var rstgen_reset_target_t::RESET_I2C0
 * @brief I2C0 reset target.
 */
/**
 * @var rstgen_reset_target_t::RESET_I2C1
 * @brief I2C1 reset target.
 */
/**
 * @var rstgen_reset_target_t::RESET_I2C2
 * @brief I2C2 reset target.
 */
/**
 * @var rstgen_reset_target_t::RESET_I2C3
 * @brief I2C3 reset target.
 */
/**
 * @var rstgen_reset_target_t::RESET_I2C4
 * @brief I2C4 reset target.
 */
/**
 * @var rstgen_reset_target_t::RESET_PWM0
 * @brief PWM0 reset target.
 */
/**
 * @var rstgen_reset_target_t::RESET_PWM1
 * @brief PWM1 reset target.
 */
/**
 * @var rstgen_reset_target_t::RESET_PWM2
 * @brief PWM2 reset target.
 */
/**
 * @var rstgen_reset_target_t::RESET_PWM3
 * @brief PWM3 reset target.
 */
/**
 * @var rstgen_reset_target_t::RESET_SPI0
 * @brief SPI0 reset target.
 */
/**
 * @var rstgen_reset_target_t::RESET_SPI1
 * @brief SPI1 reset target.
 */
/**
 * @var rstgen_reset_target_t::RESET_SPI2
 * @brief SPI2 reset target.
 */
/**
 * @var rstgen_reset_target_t::RESET_SPI3
 * @brief SPI3 reset target.
 */
/**
 * @var rstgen_reset_target_t::RESET_GPIO0
 * @brief GPIO0 reset target.
 */
/**
 * @var rstgen_reset_target_t::RESET_GPIO1
 * @brief GPIO1 reset target.
 */
/**
 * @var rstgen_reset_target_t::RESET_GPIO2
 * @brief GPIO2 reset target.
 */
/**
 * @var rstgen_reset_target_t::RESET_EFUSE
 * @brief EFUSE reset target.
 */
/**
 * @var rstgen_reset_target_t::RESET_WDT0
 * @brief WDT0 reset target.
 */
/**
 * @var rstgen_reset_target_t::RESET_TEMPSEN
 * @brief TEMPSEN reset target.
 */
/**
 * @var rstgen_reset_target_t::RESET_SARADC
 * @brief SARADC reset target.
 */
/**
 * @var rstgen_reset_target_t::RESET_UART4
 * @brief UART4 reset target.
 */
/**
 * @var rstgen_reset_target_t::RESET_GPIO3
 * @brief GPIO3 reset target.
 */
/**
 * @var rstgen_reset_target_t::RESET_TIMER
 * @brief TIMER reset target.
 */
/**
 * @var rstgen_reset_target_t::RESET_TIMER0
 * @brief TIMER0 reset target.
 */
/**
 * @var rstgen_reset_target_t::RESET_TIMER1
 * @brief TIMER1 reset target.
 */
/**
 * @var rstgen_reset_target_t::RESET_TIMER2
 * @brief TIMER2 reset target.
 */
/**
 * @var rstgen_reset_target_t::RESET_TIMER3
 * @brief TIMER3 reset target.
 */
/**
 * @var rstgen_reset_target_t::RESET_TIMER4
 * @brief TIMER4 reset target.
 */
/**
 * @var rstgen_reset_target_t::RESET_TIMER5
 * @brief TIMER5 reset target.
 */
/**
 * @var rstgen_reset_target_t::RESET_TIMER6
 * @brief TIMER6 reset target.
 */
/**
 * @var rstgen_reset_target_t::RESET_TIMER7
 * @brief TIMER7 reset target.
 */
/**
 * @var rstgen_reset_target_t::RESET_WGN0
 * @brief WGN0 reset target.
 */
/**
 * @var rstgen_reset_target_t::RESET_WGN1
 * @brief WGN1 reset target.
 */
/**
 * @var rstgen_reset_target_t::RESET_WGN2
 * @brief WGN2 reset target.
 */
/**
 * @var rstgen_reset_target_t::RESET_KEYSCAN
 * @brief KEYSCAN reset target.
 */
/**
 * @var rstgen_reset_target_t::RESET_WDT1
 * @brief WDT1 reset target.
 */
/**
 * @var rstgen_reset_target_t::RESET_WDT2
 * @brief WDT2 reset target.
 */

/**
 * @brief Register index and bit coordinate of an active-low reset.
 */
typedef struct
{
    uint8_t reg_index; /*!< SOFT_RSTN index, or RSTGEN_RESET_LOCATION_INVALID, Address offset: 0x000 */
    uint8_t bit;       /*!< register bit index, or RSTGEN_RESET_LOCATION_INVALID, Address offset: 0x001 */
} rstgen_reset_location_t;

/// @brief Required byte alignment of DMA linked-list items.
static constexpr auto DMA_LLI_ALIGNMENT = 64U;
/// @brief Maximum number of data items in one DMA block.
static constexpr auto DMA_BLOCK_TRANSFER_MAX = 0x40'0000U;
/// @brief No-peripheral-request encoding used for memory copies.
static constexpr auto DMA_REQUEST_NONE = 0U;
/// @brief DMA receive request ID for UART0.
static constexpr auto DMA_REQUEST_UART0_RX = 8U;
/// @brief DMA transmit request ID for UART0.
static constexpr auto DMA_REQUEST_UART0_TX = 9U;
/// @brief DMA receive request ID for UART1.
static constexpr auto DMA_REQUEST_UART1_RX = 10U;
/// @brief DMA transmit request ID for UART1.
static constexpr auto DMA_REQUEST_UART1_TX = 11U;
/// @brief DMA receive request ID for UART2.
static constexpr auto DMA_REQUEST_UART2_RX = 12U;
/// @brief DMA transmit request ID for UART2.
static constexpr auto DMA_REQUEST_UART2_TX = 13U;
/// @brief DMA receive request ID for UART3.
static constexpr auto DMA_REQUEST_UART3_RX = 14U;
/// @brief DMA transmit request ID for UART3.
static constexpr auto DMA_REQUEST_UART3_TX = 15U;
/// @brief DMA receive request ID for SPI0.
static constexpr auto DMA_REQUEST_SPI0_RX = 16U;
/// @brief DMA transmit request ID for SPI0.
static constexpr auto DMA_REQUEST_SPI0_TX = 17U;
/// @brief DMA receive request ID for SPI1.
static constexpr auto DMA_REQUEST_SPI1_RX = 18U;
/// @brief DMA transmit request ID for SPI1.
static constexpr auto DMA_REQUEST_SPI1_TX = 19U;
/// @brief DMA receive request ID for SPI2.
static constexpr auto DMA_REQUEST_SPI2_RX = 20U;
/// @brief DMA transmit request ID for SPI2.
static constexpr auto DMA_REQUEST_SPI2_TX = 21U;
/// @brief DMA receive request ID for SPI3.
static constexpr auto DMA_REQUEST_SPI3_RX = 22U;
/// @brief DMA transmit request ID for SPI3.
static constexpr auto DMA_REQUEST_SPI3_TX = 23U;
/// @brief DMA receive request ID for I2C0.
static constexpr auto DMA_REQUEST_I2C0_RX = 24U;
/// @brief DMA transmit request ID for I2C0.
static constexpr auto DMA_REQUEST_I2C0_TX = 25U;
/// @brief DMA receive request ID for I2C1.
static constexpr auto DMA_REQUEST_I2C1_RX = 26U;
/// @brief DMA transmit request ID for I2C1.
static constexpr auto DMA_REQUEST_I2C1_TX = 27U;
/// @brief DMA receive request ID for I2C2.
static constexpr auto DMA_REQUEST_I2C2_RX = 28U;
/// @brief DMA transmit request ID for I2C2.
static constexpr auto DMA_REQUEST_I2C2_TX = 29U;
/// @brief DMA receive request ID for I2C3.
static constexpr auto DMA_REQUEST_I2C3_RX = 30U;
/// @brief DMA transmit request ID for I2C3.
static constexpr auto DMA_REQUEST_I2C3_TX = 31U;
/// @brief DMA receive request ID for I2C4.
static constexpr auto DMA_REQUEST_I2C4_RX = 32U;
/// @brief DMA transmit request ID for I2C4.
static constexpr auto DMA_REQUEST_I2C4_TX = 33U;
/// @brief DMA receive request ID for UART4.
static constexpr auto DMA_REQUEST_UART4_RX = 40U;
/// @brief DMA transmit request ID for UART4.
static constexpr auto DMA_REQUEST_UART4_TX = 41U;
/// @brief Bit stride between adjacent DMA request-remap fields.
static constexpr auto DMA_REMAP_REQUEST_SHIFT = 8U;
/// @brief Channel fields held in each remap register.
static constexpr auto DMA_REMAP_CHANNELS_PER_REGISTER = 4U;
/// @brief Bit mask for DMA request-remap field.
static constexpr auto DMA_REMAP_REQUEST_MASK = 0x3FU;
/// @brief Bit for DMA request-remap enable.
static constexpr auto DMA_REMAP_ENABLE_BIT = (1UL << 31);
/// @brief Shift from a channel-request bit to its write-enable bit.
static constexpr auto DMA_CHANNEL_WRITE_ENABLE_SHIFT = 8U;

/// @brief Byte offset of DMA global configuration register.
static constexpr auto DMA_CFG_OFFSET = 0x010U;
/// @brief Byte offset of DMA channel-enable register low word.
static constexpr auto DMA_CHEN_OFFSET = 0x018U;

/**
 * @brief Byte offset of DMA channel-enable register high word.
 *
 * @note DMAC_CHENREG[39:32] holds abort requests and [47:40] their write enables; this is the high word of
 * the same register.
 * @see SG2002, TRM, Table 11.5, channel-enable register.
 */
// CHABORT 在 0x028，不是 0x01C。0x01C 是 **CHEN 的高半字**（8 通道映射下 suspend 位域在
// CHEN[16:23]、写使能在 CHEN[24:31]）。参考实现：Linux `dw-axi-dmac` 的
// `DMAC_CHEN_H 0x01C` 与 `DMAC_CHABORTREG 0x028`。此前把 abort 写到 0x01C，内容又是
// `ch | ch<<8`（这正好是"使能通道"的位模式），所以**每一次 abort 实际都是在重新使能通道**，
// 从来没有中止过任何通道。
// CHABORT lives at 0x028, not 0x01C.  0x01C is the **high half of CHEN** (on the 8-channel
// register map, suspend sits in CHEN[16:23] with write-enables in CHEN[24:31]).  Reference:
// Linux `dw-axi-dmac` defines `DMAC_CHEN_H 0x01C` and `DMAC_CHABORTREG 0x028`.  Writing abort
// requests to 0x01C with the payload `ch | ch<<8` -- which is exactly the enable bit pattern --
// means every "abort" actually re-enabled the channel and nothing was ever aborted.
static constexpr auto DMA_CHABORT_OFFSET = 0x028U;
/// @brief Byte offset of DMA channel register block.
static constexpr auto DMA_CHANNEL_OFFSET = 0x100U;
/// @brief Byte stride of DMA channel register block.
static constexpr auto DMA_CHANNEL_STRIDE = 0x100U;
/// @brief Byte offset of DMA channel configuration register.
static constexpr auto DMA_CH_CFG_OFFSET = 0x020U;
/// @brief Byte offset of DMA channel linked-list-pointer register.
static constexpr auto DMA_CH_LLP_OFFSET = 0x028U;
/// @brief Byte offset of DMA channel interrupt-status-enable register.
static constexpr auto DMA_CH_INTSTATUS_EN_OFFSET = 0x080U;
/// @brief Byte offset of DMA channel interrupt-status register.
static constexpr auto DMA_CH_INTSTATUS_OFFSET = 0x088U;
/// @brief Byte offset of DMA channel interrupt-signal-enable register.
static constexpr auto DMA_CH_INTSIGNAL_EN_OFFSET = 0x090U;
/// @brief Byte offset of DMA channel interrupt-clear register.
static constexpr auto DMA_CH_INTCLEAR_OFFSET = 0x098U;

/// @brief Bit for DMA controller enable.
static constexpr auto DMA_CFG_DMAC_ENABLE_BIT = (1UL << 0);
/// @brief Bit for DMA global interrupt enable.
static constexpr auto DMA_CFG_INTERRUPT_ENABLE_BIT = (1UL << 1);
/// @brief Bit for DMA source-master selection.
static constexpr auto DMA_CTL_SMS_BIT = (1ULL << 0);
/// @brief Bit for DMA destination-master selection.
static constexpr auto DMA_CTL_DMS_BIT = (1ULL << 2);
/// @brief Bit for DMA source-address increment control.
static constexpr auto DMA_CTL_SINC_BIT = (1ULL << 4);
/// @brief Bit for DMA destination-address increment control.
static constexpr auto DMA_CTL_DINC_BIT = (1ULL << 6);
/// @brief Least-significant bit position of DMA source-data-width field.
static constexpr auto DMA_CTL_SRC_WIDTH_SHIFT = 8U;
/// @brief Least-significant bit position of DMA destination-data-width field.
static constexpr auto DMA_CTL_DST_WIDTH_SHIFT = 11U;
/// @brief Bit for DMA block-completion interrupt enable.
static constexpr auto DMA_CTL_IOC_BLOCK_BIT = (1ULL << 58);
/// @brief Bit for DMA last-linked-list-item flag.
static constexpr auto DMA_CTL_LLI_LAST_BIT = (1ULL << 62);
/// @brief Bit for DMA linked-list-item valid flag.
static constexpr auto DMA_CTL_LLI_VALID_BIT = (1ULL << 63);
/// @brief Least-significant bit position of DMA transfer-type and flow-control field.
static constexpr auto DMA_CFG_TTFC_SHIFT = 32U;
/// @brief Least-significant bit position of DMA source-handshake selector.
static constexpr auto DMA_CFG_SRC_PER_SHIFT = 39U;
/// @brief Least-significant bit position of DMA destination-handshake selector.
static constexpr auto DMA_CFG_DST_PER_SHIFT = 44U;
/// @brief Least-significant bit position of DMA priority field.
static constexpr auto DMA_CFG_PRIORITY_SHIFT = 49U;
/// @brief Highest DMA channel-priority encoding.
static constexpr auto DMA_CFG_PRIORITY_MAX = 7U;
/// @brief Bit mask for DMA priority field.
static constexpr auto DMA_CFG_PRIORITY_MASK = (7ULL << DMA_CFG_PRIORITY_SHIFT);
/// @brief Field encoding for the maximum outstanding-request limit.
static constexpr auto DMA_CFG_OSR_MAX = 15U;
/// @brief Least-significant bit position of DMA source outstanding-request limit field.
static constexpr auto DMA_CFG_SRC_OSR_SHIFT = 55U;
/// @brief Least-significant bit position of DMA destination outstanding-request limit field.
static constexpr auto DMA_CFG_DST_OSR_SHIFT = 59U;
/// @brief Source linked-list multi-block transfer encoding.
static constexpr auto DMA_CFG_SRC_MULTIBLK_LLI = (3ULL << 0);
/// @brief Destination linked-list multi-block transfer encoding.
static constexpr auto DMA_CFG_DST_MULTIBLK_LLI = (3ULL << 2);
/// @brief Bit for DMA block-completion interrupt.
static constexpr auto DMA_INT_BLOCK_DONE_BIT = (1UL << 0);
/// @brief Bit for DMA transfer-completion interrupt.
static constexpr auto DMA_INT_TRANSFER_DONE_BIT = (1UL << 1);
/// @brief Bit mask for DMA error-interrupt fields.
static constexpr auto DMA_INT_ERROR_MASK = 0xF8FF'7FE0UL;
/// @brief Least-significant bit position of the source burst-length (MSIZE) field.
static constexpr auto DMA_CTL_SRC_MSIZE_SHIFT = 14U;
/// @brief Least-significant bit position of the destination burst-length (MSIZE) field.
static constexpr auto DMA_CTL_DST_MSIZE_SHIFT = 18U;
/// @brief Burst length encoding for 4 beats (field value, not beat count).
static constexpr auto DMA_CTL_MSIZE_4_BEATS = 1U;
/// @brief Bit mask for DMA defined interrupt fields.
static constexpr auto DMA_INT_ALL_MASK =
    (DMA_INT_BLOCK_DONE_BIT | DMA_INT_TRANSFER_DONE_BIT | DMA_INT_ERROR_MASK);

/**
 * @brief AXI DMA global control registers.
 */
typedef struct
{
    volatile uint32_t RESERVED_000[4]; /*!< Reserved, Address offset: 0x000 */
    volatile uint32_t CFG;             /*!< DMA global
                                                      configuration-register low
                                                      word, Address offset: 0x010 */
    volatile uint32_t RESERVED_014;    /*!< Reserved, Address offset: 0x014 */
    volatile uint32_t CHEN;            /*!< DMA channel-enable register
                                                      low word, Address offset: 0x018 */
    volatile uint32_t CHEN_H;          /*!< channel-enable high word (channels 32-63);
                                                      on the 8-channel map it carries the
                                                      suspend field and its write enables,
                                                      Address offset: 0x01C */
    volatile uint32_t CHSUSP;          /*!< channel-suspend register,
                                                      Address offset: 0x020 */
    volatile uint32_t RESERVED_024;    /*!< Reserved, Address offset: 0x024 */
    volatile uint32_t CHABORT;         /*!< channel-abort register, Address offset: 0x028 */
    volatile uint32_t RESERVED_02C[(DMA_CHANNEL_OFFSET - 0x02CU) / 4U]; /*!< padding for an
                                                               unexposed area, Address offset: 0x02C */
} DMA_GLOBAL_Type;

static_assert(offsetof(DMA_GLOBAL_Type, CFG) == DMA_CFG_OFFSET);
static_assert(offsetof(DMA_GLOBAL_Type, CHEN) == DMA_CHEN_OFFSET);
static_assert(offsetof(DMA_GLOBAL_Type, CHABORT) == DMA_CHABORT_OFFSET);
static_assert(sizeof(DMA_GLOBAL_Type) == DMA_CHANNEL_OFFSET);

/**
 * @brief Register block for one AXI DMA channel.
 */
typedef struct
{
    volatile uint32_t SAR_LOW;          /*!< low 32 bits of the source address, Address offset: 0x000 */
    volatile uint32_t SAR_HIGH;         /*!< high 32 bits of the source address, Address offset: 0x004 */
    volatile uint32_t DAR_LOW;          /*!< low 32 bits of the destination address, Address offset: 0x008 */
    volatile uint32_t DAR_HIGH;         /*!< high 32 bits of the destination address, Address offset: 0x00C */
    volatile uint32_t BLOCK_TS_LOW;     /*!< low word of the block item-count field, Address offset: 0x010 */
    volatile uint32_t BLOCK_TS_HIGH;    /*!< high word of the block item-count field, Address offset: 0x014 */
    volatile uint32_t CTL_LOW;          /*!< transfer-control low word, Address offset: 0x018 */
    volatile uint32_t CTL_HIGH;         /*!< transfer-control high word, Address offset: 0x01C */
    volatile uint32_t CFG_LOW;          /*!< channel-configuration low word, Address offset: 0x020 */
    volatile uint32_t CFG_HIGH;         /*!< channel-configuration high word, Address offset: 0x024 */
    volatile uint32_t LLP_LOW;          /*!< linked-list-pointer low word, Address offset: 0x028 */
    volatile uint32_t LLP_HIGH;         /*!< linked-list-pointer high word, Address offset: 0x02C */
    volatile uint32_t RESERVED_030[20]; /*!< Reserved, Address offset: 0x030 */
    volatile uint32_t INTSTATUS_EN;     /*!< interrupt-status latch enable, Address offset: 0x080 */
    volatile uint32_t RESERVED_084;     /*!< Reserved, Address offset: 0x084 */
    volatile uint32_t INTSTATUS;        /*!< interrupt-status register, Address offset: 0x088 */
    volatile uint32_t RESERVED_08C;     /*!< Reserved, Address offset: 0x08C */
    volatile uint32_t INTSIGNAL_EN;     /*!< interrupt-signal output enable, Address offset: 0x090 */
    volatile uint32_t RESERVED_094;     /*!< Reserved, Address offset: 0x094 */
    volatile uint32_t INTCLEAR; /*!< write-one-to-clear interrupt status bits, Address offset: 0x098 */
    volatile uint32_t RESERVED_09C[25]; /*!< Reserved, Address offset: 0x09C */
} DMA_Channel_Type;

static_assert(sizeof(DMA_Channel_Type) == DMA_CHANNEL_STRIDE);
static_assert(offsetof(DMA_Channel_Type, INTSTATUS_EN) == DMA_CH_INTSTATUS_EN_OFFSET);
static_assert(offsetof(DMA_Channel_Type, INTSTATUS) == DMA_CH_INTSTATUS_OFFSET);
static_assert(offsetof(DMA_Channel_Type, INTSIGNAL_EN) == DMA_CH_INTSIGNAL_EN_OFFSET);
static_assert(offsetof(DMA_Channel_Type, INTCLEAR) == DMA_CH_INTCLEAR_OFFSET);

/**
 * @brief DMA controller view containing global and channel registers.
 */
typedef struct
{
    DMA_GLOBAL_Type GLOBAL;                      /*!< DMA global control-register
                                                     view, Address offset: 0x000 */
    DMA_Channel_Type CHANNEL[DMA_CHANNEL_COUNT]; /*!< DMA channel-register array, Address offset: 0x100 */
} DMA_Type;

/**
 * @brief DMA register-instance pointer.
 */
#define DMA ((DMA_Type *)(uintptr_t)DMA_BASE)

/**
 * @brief AXI DMA linked-list item.
 *
 * @note LLP[5:1] are reserved; each item must begin on a 64-byte boundary.
 * @see SG2002 TRM v1.02, Table 11.26
 */
typedef struct
{
    alignas(DMA_LLI_ALIGNMENT) uint64_t source; /*!< source data address, Address offset: 0x000 */
    uint64_t destination;                       /*!< destination data address, Address offset: 0x008 */
    uint64_t block_ts;                          /*!< data-item count minus one, Address offset: 0x010 */
    uint64_t next;                              /*!< next-descriptor address and
                                                     link fields, Address offset: 0x018 */
    uint32_t control_low;                       /*!< transfer-control low word, Address offset: 0x020 */
    uint32_t control_high;                      /*!< transfer-control high word, Address offset: 0x024 */
    uint32_t source_status;                     /*!< source-status word, Address offset: 0x028 */
    uint32_t destination_status;                /*!< destination-status word, Address offset: 0x02C */
    uint32_t status_low;                        /*!< descriptor-status low word, Address offset: 0x030 */
    uint32_t status_high;                       /*!< descriptor-status high word, Address offset: 0x034 */
    uint32_t reserved_low;                      /*!< reserved low word, Address offset: 0x038 */
    uint32_t reserved_high;                     /*!< reserved high word, Address offset: 0x03C */
} DMA_LLI_Type;

static_assert(sizeof(DMA_LLI_Type) == 64U);
static_assert(alignof(DMA_LLI_Type) == DMA_LLI_ALIGNMENT);

/// @brief Byte stride between adjacent SSI instance bases.
static constexpr auto SPI_INSTANCE_STRIDE = 0x1'0000UL;
/// @brief Entry depth of the SSI receive/transmit FIFOs.
static constexpr auto SPI_FIFO_DEPTH = 8U;
/// @brief Address aliases for the same SPI FIFO data port.
static constexpr auto SPI_DR_COUNT = 36U;
/// @brief Defined external slave selects per SSI instance.
static constexpr auto SPI_CHIP_SELECT_COUNT = 1U;
/// @brief Byte offset of SPI control register zero.
static constexpr auto SPI_CTRLR0_OFFSET = 0x000U;
/// @brief Byte offset of SPI control register one.
static constexpr auto SPI_CTRLR1_OFFSET = 0x004U;
/// @brief Byte offset of SSI enable register.
static constexpr auto SPI_SPIENR_OFFSET = 0x008U;
/// @brief Byte offset of Microwire control register.
static constexpr auto SPI_MWCR_OFFSET = 0x00CU;
/// @brief Byte offset of SPI slave-select register.
static constexpr auto SPI_SER_OFFSET = 0x010U;
/// @brief Byte offset of SPI baud-divisor register.
static constexpr auto SPI_BAUDR_OFFSET = 0x014U;
/// @brief Byte offset of SPI transmit FIFO threshold register.
static constexpr auto SPI_TXFTLR_OFFSET = 0x018U;
/// @brief Byte offset of SPI receive FIFO threshold register.
static constexpr auto SPI_RXFTLR_OFFSET = 0x01CU;
/// @brief Byte offset of SPI transmit FIFO level register.
static constexpr auto SPI_TXFLR_OFFSET = 0x020U;
/// @brief Byte offset of SPI receive FIFO level register.
static constexpr auto SPI_RXFLR_OFFSET = 0x024U;
/// @brief Byte offset of SPI status register.
static constexpr auto SPI_SR_OFFSET = 0x028U;
/// @brief Byte offset of SPI interrupt-enable mask register.
static constexpr auto SPI_IMR_OFFSET = 0x02CU;
/// @brief Byte offset of SPI masked interrupt-status register.
static constexpr auto SPI_ISR_OFFSET = 0x030U;
/// @brief Byte offset of SPI raw interrupt-status register.
static constexpr auto SPI_RISR_OFFSET = 0x034U;
/// @brief Byte offset of SPI transmit-overflow clear register.
static constexpr auto SPI_TXOICR_OFFSET = 0x038U;
/// @brief Byte offset of SPI receive-overflow clear register.
static constexpr auto SPI_RXOICR_OFFSET = 0x03CU;
/// @brief Byte offset of SPI receive-underflow clear register.
static constexpr auto SPI_RXUICR_OFFSET = 0x040U;
/// @brief Byte offset of SPI multi-master contention clear register.
static constexpr auto SPI_MSTICR_OFFSET = 0x044U;
/// @brief Byte offset of SPI interrupt-clear register.
static constexpr auto SPI_ICR_OFFSET = 0x048U;
/// @brief Byte offset of SPI DMA request-control register.
static constexpr auto SPI_DMACR_OFFSET = 0x04CU;
/// @brief Byte offset of SPI transmit DMA request threshold.
static constexpr auto SPI_DMATDLR_OFFSET = 0x050U;
/// @brief Byte offset of SPI receive DMA request threshold.
static constexpr auto SPI_DMARDLR_OFFSET = 0x054U;
/// @brief Byte offset of SPI FIFO data port.
static constexpr auto SPI_DR_OFFSET = 0x060U;
/// @brief Byte offset of SPI receive-sample delay.
static constexpr auto SPI_RX_SAMPLE_DLY_OFFSET = 0x0F0U;

/**
 * @brief DesignWare SSI register block.
 *
 * @see SG2002 TRM v1.02, Tables 21.73-21.98
 */
typedef struct
{
    volatile uint32_t CTRLR0;           /*!< SPI control register zero, Address offset: 0x000 */
    volatile uint32_t CTRLR1;           /*!< SPI control register one, Address offset: 0x004 */
    volatile uint32_t SPIENR;           /*!< SSI enable register, Address offset: 0x008 */
    volatile uint32_t MWCR;             /*!< Microwire control register, Address offset: 0x00C */
    volatile uint32_t SER;              /*!< SPI slave-select register, Address offset: 0x010 */
    volatile uint32_t BAUDR;            /*!< SPI baud-divisor register, Address offset: 0x014 */
    volatile uint32_t TXFTLR;           /*!< SPI transmit FIFO threshold register, Address offset: 0x018 */
    volatile uint32_t RXFTLR;           /*!< SPI receive FIFO threshold register, Address offset: 0x01C */
    volatile uint32_t TXFLR;            /*!< SPI transmit FIFO level register, Address offset: 0x020 */
    volatile uint32_t RXFLR;            /*!< SPI receive FIFO level register, Address offset: 0x024 */
    volatile uint32_t SR;               /*!< SPI status register, Address offset: 0x028 */
    volatile uint32_t IMR;              /*!< SPI interrupt-enable mask register, Address offset: 0x02C */
    volatile uint32_t ISR;              /*!< SPI masked interrupt-status register, Address offset: 0x030 */
    volatile uint32_t RISR;             /*!< SPI raw interrupt-status register, Address offset: 0x034 */
    volatile uint32_t TXOICR;           /*!< SPI transmit-overflow clear register, Address offset: 0x038 */
    volatile uint32_t RXOICR;           /*!< SPI receive-overflow clear register, Address offset: 0x03C */
    volatile uint32_t RXUICR;           /*!< SPI receive-underflow clear register, Address offset: 0x040 */
    volatile uint32_t MSTICR;           /*!< SPI multi-master contention clear
                                            register, Address offset: 0x044 */
    volatile uint32_t ICR;              /*!< SPI interrupt-clear register, Address offset: 0x048 */
    volatile uint32_t DMACR;            /*!< SPI DMA request-control register, Address offset: 0x04C */
    volatile uint32_t DMATDLR;          /*!< SPI transmit DMA request threshold, Address offset: 0x050 */
    volatile uint32_t DMARDLR;          /*!< SPI receive DMA request threshold, Address offset: 0x054 */
    uint32_t RESERVED_058[2];           /*!< Reserved, Address offset: 0x058 */
    volatile uint32_t DR[SPI_DR_COUNT]; /*!< 36 address aliases of the same FIFO
                                             data port, Address offset: 0x060 */
    volatile uint32_t RX_SAMPLE_DLY;    /*!< SPI receive-sample delay, Address offset: 0x0F0 */
} SPI_Type;

static_assert(offsetof(SPI_Type, DR) == SPI_DR_OFFSET);
static_assert(offsetof(SPI_Type, RX_SAMPLE_DLY) == SPI_RX_SAMPLE_DLY_OFFSET);

/**
 * @brief Indicate that the device header provides the SPI register type.
 */
#define DEVICE_HAS_SPI_TYPE 1

/**
 * @brief Alias of the SPI register-block type.
 */
typedef SPI_Type spi_t;

/**
 * @brief SPI0 register-instance pointer.
 */
#define SPI0_REGS ((SPI_Type *)(uintptr_t)SPI0_BASE)

/**
 * @brief SPI1 register-instance pointer.
 */
#define SPI1_REGS ((SPI_Type *)(uintptr_t)SPI1_BASE)

/**
 * @brief SPI2 register-instance pointer.
 */
#define SPI2_REGS ((SPI_Type *)(uintptr_t)SPI2_BASE)

/**
 * @brief SPI3 register-instance pointer.
 */
#define SPI3_REGS ((SPI_Type *)(uintptr_t)SPI3_BASE)

/// @brief Least-significant bit position of SPI control-frame-length field.
static constexpr auto SPI_CTRLR0_CFS_SHIFT = 12U;
/// @brief Bit width of SPI control-frame-length field.
static constexpr auto SPI_CTRLR0_CFS_WIDTH = 4U;
/// @brief Bit mask for SPI control-frame-length field.
static constexpr auto SPI_CTRLR0_CFS_MASK = (0x0FUL << SPI_CTRLR0_CFS_SHIFT);
/// @brief Bit for SPI shift-register loopback.
static constexpr auto SPI_CTRLR0_SRL_BIT = (1UL << 11);
/// @brief Least-significant bit position of SPI transfer-mode field.
static constexpr auto SPI_CTRLR0_TMOD_SHIFT = 8U;
/// @brief Bit width of SPI transfer-mode field.
static constexpr auto SPI_CTRLR0_TMOD_WIDTH = 2U;
/// @brief Bit mask for SPI transfer-mode field.
static constexpr auto SPI_CTRLR0_TMOD_MASK = (0x03UL << SPI_CTRLR0_TMOD_SHIFT);
/// @brief Bit for SPI clock polarity.
static constexpr auto SPI_CTRLR0_SCPOL_BIT = (1UL << 7);
/// @brief Bit for SPI clock phase.
static constexpr auto SPI_CTRLR0_SCPH_BIT = (1UL << 6);
/// @brief Least-significant bit position of SPI serial frame-format field.
static constexpr auto SPI_CTRLR0_FRF_SHIFT = 4U;
/// @brief Bit width of SPI serial frame-format field.
static constexpr auto SPI_CTRLR0_FRF_WIDTH = 2U;
/// @brief Bit mask for SPI serial frame-format field.
static constexpr auto SPI_CTRLR0_FRF_MASK = (0x03UL << SPI_CTRLR0_FRF_SHIFT);
/// @brief Least-significant bit position of SPI data-frame-length field.
static constexpr auto SPI_CTRLR0_DFS_SHIFT = 0U;
/// @brief Bit width of SPI data-frame-length field.
static constexpr auto SPI_CTRLR0_DFS_WIDTH = 4U;
/// @brief Bit mask for SPI data-frame-length field.
static constexpr auto SPI_CTRLR0_DFS_MASK = 0x0FUL;

/// @brief Bit for SSI controller enable.
static constexpr auto SPI_SPIENR_ENABLE_BIT = (1UL << 0);
/// @brief Bit for SPI slave-select-zero enable.
static constexpr auto SPI_SER_CS0_BIT = (1UL << 0);
/// @brief Bit mask for SPI slave-select register.
static constexpr auto SPI_SER_MASK = SPI_SER_CS0_BIT;
/// @brief Bit mask for SPI receive-frame-count-minus-one field.
static constexpr auto SPI_CTRLR1_NDF_MASK = 0xFFFFUL;

/// @brief Minimum BAUDR divisor usable for transfers.
static constexpr auto SPI_BAUDR_MIN = 2U;
/// @brief Maximum even BAUDR divisor usable for transfers.
static constexpr auto SPI_BAUDR_MAX = 65'534U;
/// @brief BAUDR encoding that disables the serial output clock.
static constexpr auto SPI_BAUDR_CLOCK_DISABLED = 0U;
/// @brief Bit mask for SPI baud-divisor register.
static constexpr auto SPI_BAUDR_MASK = 0xFFFFUL;
/// @brief Bit mask for SPI FIFO entry count.
static constexpr auto SPI_FIFO_LEVEL_MASK = 0x0FUL;
/// @brief Bit mask for SPI FIFO threshold.
static constexpr auto SPI_FIFO_THRESHOLD_MASK = 0x07UL;
/// @brief Maximum FIFO threshold-field encoding.
static constexpr auto SPI_FIFO_THRESHOLD_MAX = SPI_FIFO_THRESHOLD_MASK;
/// @brief Bit mask for SPI DMA request threshold.
static constexpr auto SPI_DMA_LEVEL_MASK = 0x07UL;

/// @brief Bit for SSI busy status.
static constexpr auto SPI_SR_BUSY_BIT = (1UL << 0);
/// @brief Bit for SPI transmit FIFO not-full status.
static constexpr auto SPI_SR_TFNF_BIT = (1UL << 1);
/// @brief Bit for SPI transmit FIFO empty status.
static constexpr auto SPI_SR_TFE_BIT = (1UL << 2);
/// @brief Bit for SPI receive FIFO not-empty status.
static constexpr auto SPI_SR_RFNE_BIT = (1UL << 3);
/// @brief Bit for SPI receive FIFO full status.
static constexpr auto SPI_SR_RFF_BIT = (1UL << 4);
/// @brief Bit for SPI transmit-error status.
static constexpr auto SPI_SR_TX_ERROR_BIT = (1UL << 5);
/// @brief Bit for SPI collision-error status.
static constexpr auto SPI_SR_COLLISION_ERROR_BIT = (1UL << 6);
/// @brief Bit mask for SPI status-register error fields.
static constexpr auto SPI_SR_ERROR_MASK = (SPI_SR_TX_ERROR_BIT | SPI_SR_COLLISION_ERROR_BIT);

/// @brief Bit for SPI transmit FIFO empty interrupt.
static constexpr auto SPI_INTERRUPT_TX_EMPTY_BIT = (1UL << 0);
/// @brief Bit for SPI transmit FIFO overflow interrupt.
static constexpr auto SPI_INTERRUPT_TX_OVERFLOW_BIT = (1UL << 1);
/// @brief Bit for SPI receive FIFO underflow interrupt.
static constexpr auto SPI_INTERRUPT_RX_UNDERFLOW_BIT = (1UL << 2);
/// @brief Bit for SPI receive FIFO overflow interrupt.
static constexpr auto SPI_INTERRUPT_RX_OVERFLOW_BIT = (1UL << 3);
/// @brief Bit for SPI receive FIFO full interrupt.
static constexpr auto SPI_INTERRUPT_RX_FULL_BIT = (1UL << 4);
/// @brief Bit for SPI multi-master contention interrupt.
static constexpr auto SPI_INTERRUPT_MULTI_MASTER_BIT = (1UL << 5);
/// @brief Bit mask for SPI defined interrupt fields.
static constexpr auto SPI_INTERRUPT_MASK = 0x3FUL;
/// @brief Bit mask for SPI raw error-interrupt fields.
static constexpr auto SPI_RISR_ERROR_MASK =
    (SPI_INTERRUPT_TX_OVERFLOW_BIT | SPI_INTERRUPT_RX_UNDERFLOW_BIT | SPI_INTERRUPT_RX_OVERFLOW_BIT |
     SPI_INTERRUPT_MULTI_MASTER_BIT);

/// @brief Bit for SPI receive DMA request enable.
static constexpr auto SPI_DMACR_RX_ENABLE_BIT = (1UL << 0);
/// @brief Bit for SPI transmit DMA request enable.
static constexpr auto SPI_DMACR_TX_ENABLE_BIT = (1UL << 1);
/// @brief Bit mask for SPI DMA request-control register.
static constexpr auto SPI_DMACR_MASK = 0x03UL;
/// @brief Bit mask for SPI transmit DMA request threshold.
static constexpr auto SPI_DMATDLR_MASK = SPI_DMA_LEVEL_MASK;
/// @brief Bit mask for SPI receive DMA request threshold.
static constexpr auto SPI_DMARDLR_MASK = SPI_DMA_LEVEL_MASK;
/// @brief Bit mask for SPI FIFO data port.
static constexpr auto SPI_DR_MASK = 0xFFFFUL;
/// @brief Bit mask for SPI receive-sample delay.
static constexpr auto SPI_RX_SAMPLE_DLY_MASK = 0xFFUL;
/// @brief Maximum receive-sample-delay encoding supported internally.
static constexpr auto SPI_RX_SAMPLE_DLY_MAX = 7U;

/// @brief Bit for Microwire transfer mode.
static constexpr auto SPI_MWCR_TRANSFER_MODE_BIT = (1UL << 0);
/// @brief Bit for Microwire control direction.
static constexpr auto SPI_MWCR_CONTROL_BIT = (1UL << 1);
/// @brief Bit for Microwire handshake enable.
static constexpr auto SPI_MWCR_HANDSHAKE_BIT = (1UL << 2);
/// @brief Bit mask for Microwire control register.
static constexpr auto SPI_MWCR_MASK = 0x07UL;

/**
 * @brief DesignWare APB I2C register block.
 *
 * @see sg2002-licheerv-nano-b.svd, SVD register descriptions）。
 */
typedef struct
{
    volatile uint32_t CON;            /*!< I2C control register, Address offset: 0x000 */
    volatile uint32_t TAR;            /*!< master target-address register, Address offset: 0x004 */
    volatile uint32_t SAR;            /*!< slave own-address register, Address offset: 0x008 */
    volatile uint32_t RESERVED_00C;   /*!< Reserved, Address offset: 0x00C */
    volatile uint32_t DATA_CMD;       /*!< FIFO data and transfer-command port, Address offset: 0x010 */
    volatile uint32_t SS_SCL_HCNT;    /*!< standard-mode SCL high count, Address offset: 0x014 */
    volatile uint32_t SS_SCL_LCNT;    /*!< standard-mode SCL low count, Address offset: 0x018 */
    volatile uint32_t FS_SCL_HCNT;    /*!< fast-mode SCL high count, Address offset: 0x01C */
    volatile uint32_t FS_SCL_LCNT;    /*!< fast-mode SCL low count, Address offset: 0x020 */
    volatile uint32_t HS_SCL_HCNT;    /*!< high-speed-mode SCL high count, Address offset: 0x024 */
    volatile uint32_t HS_SCL_LCNT;    /*!< high-speed-mode SCL low count, Address offset: 0x028 */
    volatile uint32_t INTR_STAT;      /*!< masked interrupt status, Address offset: 0x02C */
    volatile uint32_t INTR_MASK;      /*!< interrupt-enable mask, Address offset: 0x030 */
    volatile uint32_t RAW_INTR_STAT;  /*!< unmasked interrupt status, Address offset: 0x034 */
    volatile uint32_t RX_TL;          /*!< receive FIFO threshold, Address offset: 0x038 */
    volatile uint32_t TX_TL;          /*!< transmit FIFO threshold, Address offset: 0x03C */
    volatile uint32_t CLR_INTR;       /*!< read to clear all interrupts status, Address offset: 0x040 */
    volatile uint32_t CLR_RX_UNDER;   /*!< read to clear receive underflow status, Address offset: 0x044 */
    volatile uint32_t CLR_RX_OVER;    /*!< read to clear receive overflow status, Address offset: 0x048 */
    volatile uint32_t CLR_TX_OVER;    /*!< read to clear transmit overflow status, Address offset: 0x04C */
    volatile uint32_t CLR_RD_REQ;     /*!< read to clear read request status, Address offset: 0x050 */
    volatile uint32_t CLR_TX_ABRT;    /*!< read to clear transmit abort status, Address offset: 0x054 */
    volatile uint32_t CLR_RX_DONE;    /*!< read to clear receive completion
                                              status, Address offset: 0x058 */
    volatile uint32_t CLR_ACTIVITY;   /*!< read to clear activity status status, Address offset: 0x05C */
    volatile uint32_t CLR_STOP_DET;   /*!< read to clear STOP detection status, Address offset: 0x060 */
    volatile uint32_t CLR_START_DET;  /*!< read to clear START detection status, Address offset: 0x064 */
    volatile uint32_t CLR_GEN_CALL;   /*!< read to clear general call status, Address offset: 0x068 */
    volatile uint32_t ENABLE;         /*!< controller enable and abort control, Address offset: 0x06C */
    volatile uint32_t STATUS;         /*!< controller status, Address offset: 0x070 */
    volatile uint32_t TXFLR;          /*!< transmit FIFO entry count, Address offset: 0x074 */
    volatile uint32_t RXFLR;          /*!< receive FIFO entry count, Address offset: 0x078 */
    volatile uint32_t SDA_HOLD;       /*!< SDA hold time, Address offset: 0x07C */
    volatile uint32_t TX_ABRT_SOURCE; /*!< transmit-abort source, Address offset: 0x080 */
    volatile uint32_t SLV_DATA_NACK_ONLY; /*!< generate SLV_DATA_NACK register, Address offset: 0x084 */
    volatile uint32_t DMA_CR;             /*!< DMA request enables, Address offset: 0x088 */
    volatile uint32_t DMA_TDLR;           /*!< transmit DMA request threshold, Address offset: 0x08C */
    volatile uint32_t DMA_RDLR;           /*!< receive DMA request threshold, Address offset: 0x090 */
    volatile uint32_t SDA_SETUP;          /*!< SDA setup time, Address offset: 0x094 */
    volatile uint32_t ACK_GENERAL_CALL;   /*!< I2C ACK general call register, Address offset: 0x098 */
    volatile uint32_t ENABLE_STATUS;      /*!< actual enable status, Address offset: 0x09C */
    volatile uint32_t SPKLEN;             /*!< spike-suppression length, Address offset: 0x0A0 */
    volatile uint32_t HS_SPKLEN;          /*!< HS spike suppression limit, Address offset: 0x0A4 */
    volatile uint32_t CLR_RESTART_DET; /*!< read to clear RESTART detection status, Address offset: 0x0A8 */
    uint32_t RESERVED_0AC[18];         /*!< Reserved, Address offset: 0x0AC */
    volatile uint32_t COMP_PARAM_1;    /*!< component-parameter register, Address offset: 0x0F4 */
    volatile uint32_t COMP_VERSION;    /*!< component-version register, Address offset: 0x0F8 */
    volatile uint32_t COMP_TYPE;       /*!< component-type register, Address offset: 0x0FC */
} I2C_Type;

static_assert(offsetof(I2C_Type, DATA_CMD) == 0x010U);
static_assert(offsetof(I2C_Type, DMA_CR) == 0x088U);
static_assert(offsetof(I2C_Type, ENABLE_STATUS) == 0x09CU);
static_assert(offsetof(I2C_Type, CLR_RESTART_DET) == 0x0A8U);
static_assert(offsetof(I2C_Type, COMP_PARAM_1) == 0x0F4U);

/**
 * @brief I2C0 register-instance pointer.
 */
#define I2C0_REGS ((I2C_Type *)(uintptr_t)I2C0_BASE)

/**
 * @brief I2C1 register-instance pointer.
 */
#define I2C1_REGS ((I2C_Type *)(uintptr_t)I2C1_BASE)

/**
 * @brief I2C2 register-instance pointer.
 */
#define I2C2_REGS ((I2C_Type *)(uintptr_t)I2C2_BASE)

/**
 * @brief I2C3 register-instance pointer.
 */
#define I2C3_REGS ((I2C_Type *)(uintptr_t)I2C3_BASE)

/**
 * @brief I2C4 register-instance pointer.
 */
#define I2C4_REGS ((I2C_Type *)(uintptr_t)I2C4_BASE)

/// @brief I2C standard-speed mode encoding.
static constexpr auto I2C_SPEED_STANDARD = 1U;
/// @brief I2C fast-mode encoding.
static constexpr auto I2C_SPEED_FAST = 2U;
/// @brief I2C high-speed mode encoding.
static constexpr auto I2C_SPEED_HIGH = 3U;

/// @brief Input clock frequency in hz for the 25 MHz profile.
static constexpr auto I2C_TIMING_25M_CLOCK_HZ = 25'000'000UL;
/// @brief Standard-mode scl high count for the 25 MHz profile.
static constexpr auto I2C_TIMING_25M_SS_HCNT = 115U;
/// @brief Standard-mode scl low count for the 25 MHz profile.
static constexpr auto I2C_TIMING_25M_SS_LCNT = 135U;
/// @brief Fast-mode scl high count for the 25 MHz profile.
static constexpr auto I2C_TIMING_25M_FS_HCNT = 21U;
/// @brief Fast-mode scl low count for the 25 MHz profile.
static constexpr auto I2C_TIMING_25M_FS_LCNT = 42U;
/// @brief Sda setup-time count for the 25 MHz profile.
static constexpr auto I2C_TIMING_25M_SDA_SETUP = 6U;
/// @brief Spike-suppression cycle count for the 25 MHz profile.
static constexpr auto I2C_TIMING_25M_SPKLEN = 2U;
/// @brief Input clock frequency in hz for the 100 MHz profile.
static constexpr auto I2C_TIMING_100M_CLOCK_HZ = 100'000'000UL;
/// @brief Standard-mode scl high count for the 100 MHz profile.
static constexpr auto I2C_TIMING_100M_SS_HCNT = 460U;
/// @brief Standard-mode scl low count for the 100 MHz profile.
static constexpr auto I2C_TIMING_100M_SS_LCNT = 540U;
/// @brief Fast-mode scl high count for the 100 MHz profile.
static constexpr auto I2C_TIMING_100M_FS_HCNT = 90U;
/// @brief Fast-mode scl low count for the 100 MHz profile.
static constexpr auto I2C_TIMING_100M_FS_LCNT = 160U;
/// @brief Sda setup-time count for the 100 MHz profile.
static constexpr auto I2C_TIMING_100M_SDA_SETUP = 25U;
/// @brief Spike-suppression cycle count for the 100 MHz profile.
static constexpr auto I2C_TIMING_100M_SPKLEN = 5U;
/// @brief SDA hold-time setting in IP-clock cycles.
static constexpr auto I2C_TIMING_SDA_HOLD = 1U;

/// @brief Entry depth of the I2C receive/transmit FIFOs.
static constexpr auto I2C_FIFO_DEPTH = 64U;

/// @brief Maximum I2C SCL high/low count.
static constexpr auto I2C_SCL_COUNT_MAX = 0xFFFFU;
/// @brief Maximum I2C SDA transmit-hold count.
static constexpr auto I2C_SDA_HOLD_TX_MAX = 0xFFFFU;
/// @brief Minimum I2C SDA setup count.
static constexpr auto I2C_SDA_SETUP_MIN = 2U;
/// @brief Maximum I2C SDA setup count.
static constexpr auto I2C_SDA_SETUP_MAX = 0xFFU;
/// @brief Maximum I2C spike-suppression count.
static constexpr auto I2C_SPKLEN_MAX = 0xFFU;
/// @brief Minimum standard-mode I2C SCL high time in ns.
static constexpr auto I2C_STANDARD_HIGH_NS = 4'000U;
/// @brief Minimum standard-mode I2C SCL low time in ns.
static constexpr auto I2C_STANDARD_LOW_NS = 4'700U;
/// @brief Minimum fast-mode I2C SCL high time in ns.
static constexpr auto I2C_FAST_HIGH_NS = 600U;
/// @brief Minimum fast-mode I2C SCL low time in ns.
static constexpr auto I2C_FAST_LOW_NS = 1'300U;
/// @brief Default I2C SCL fall-time budget in ns.
static constexpr auto I2C_SCL_FALL_NS = 300U;
/// @brief Default I2C SDA hold time in ns.
static constexpr auto I2C_SDA_HOLD_NS = 300U;
/// @brief Default I2C SDA setup time in ns.
static constexpr auto I2C_SDA_SETUP_NS = 1'000U;
/// @brief Default I2C spike-suppression time in ns.
static constexpr auto I2C_SPIKE_SUPPRESSION_NS = 50U;
/// @brief DesignWare internal SCL high latency in IP cycles.
static constexpr auto I2C_SCL_HIGH_LATENCY = 3U;
/// @brief DesignWare internal SCL low latency in IP cycles.
static constexpr auto I2C_SCL_LOW_LATENCY = 1U;

/// @brief Bit mask for I2C seven-bit target-address field.
static constexpr auto I2C_TAR_7BIT_ADDRESS_MASK = 0x7FU;
/// @brief Reset target address of I2C TAR.
static constexpr auto I2C_TAR_RESET_ADDRESS = 0x55U;
/// @brief Bit for I2C master-mode enable.
static constexpr auto I2C_CON_MASTER_BIT = (1UL << 0);
/// @brief Least-significant bit position of I2C speed-mode field.
static constexpr auto I2C_CON_SPEED_SHIFT = 1U;
/// @brief Bit mask for I2C speed-mode field.
static constexpr auto I2C_CON_SPEED_MASK = (3UL << I2C_CON_SPEED_SHIFT);
/// @brief Bit for I2C slave ten-bit addressing.
static constexpr auto I2C_CON_SLAVE_10BIT_BIT = (1UL << 3);
/// @brief Bit for I2C master ten-bit addressing.
static constexpr auto I2C_CON_MASTER_10BIT_BIT = (1UL << 4);
/// @brief Bit for I2C repeated-start enable.
static constexpr auto I2C_CON_RESTART_ENABLE_BIT = (1UL << 5);
/// @brief Bit for I2C slave disable.
static constexpr auto I2C_CON_SLAVE_DISABLE_BIT = (1UL << 6);
/// @brief Bit for I2C addressed-only STOP detection selection.
static constexpr auto I2C_CON_STOP_DET_IF_ADDRESSED_BIT = (1UL << 7);
/// @brief Bit for I2C transmit-empty interrupt control.
static constexpr auto I2C_CON_TX_EMPTY_CTRL_BIT = (1UL << 8);
/// @brief Bit for I2C receive-FIFO-full hold control.
static constexpr auto I2C_CON_RX_FIFO_FULL_HOLD_BIT = (1UL << 9);
/// @brief Bit for I2C bus-clear control.
static constexpr auto I2C_CON_BUS_CLEAR_CTRL_BIT = (1UL << 11);
/// @brief Bit mask for I2C target-address field.
static constexpr auto I2C_TAR_ADDRESS_MASK = 0x3FFUL;
/// @brief Bit for I2C TAR ten-bit addressing selection.
static constexpr auto I2C_TAR_10BIT_BIT = (1UL << 12);
/// @brief Bit mask for I2C command-data field.
static constexpr auto I2C_DATA_CMD_DATA_MASK = 0xFFUL;
/// @brief Bit for I2C read-request command.
static constexpr auto I2C_DATA_CMD_READ_BIT = (1UL << 8);
/// @brief Bit for I2C STOP command.
static constexpr auto I2C_DATA_CMD_STOP_BIT = (1UL << 9);
/// @brief Bit for I2C RESTART command.
static constexpr auto I2C_DATA_CMD_RESTART_BIT = (1UL << 10);
/// @brief Bit for I2C first-byte flag.
static constexpr auto I2C_DATA_CMD_FIRST_BYTE_BIT = (1UL << 11);
/// @brief Bit for I2C transmit-abort interrupt.
static constexpr auto I2C_INTR_TX_ABRT_BIT = (1UL << 6);
/// @brief Bit for I2C STOP-detection interrupt.
static constexpr auto I2C_INTR_STOP_DET_BIT = (1UL << 9);
/// @brief Bit for I2C controller enable.
static constexpr auto I2C_ENABLE_BIT = (1UL << 0);
/// @brief Bit for I2C abort request.
static constexpr auto I2C_ENABLE_ABORT_BIT = (1UL << 1);
/// @brief Bit for I2C controller actual enable status.
static constexpr auto I2C_ENABLE_STATUS_BIT = (1UL << 0);
/// @brief Bit for I2C receive DMA request enable.
static constexpr auto I2C_DMA_RX_ENABLE_BIT = (1UL << 0);
/// @brief Bit for I2C transmit DMA request enable.
static constexpr auto I2C_DMA_TX_ENABLE_BIT = (1UL << 1);

/**
 * @brief DesignWare APB UART register block.
 *
 * @see sg2002-licheerv-nano-b.svd, DW_apb_uart, views, SVD register descriptions）。
 */
typedef struct
{
    volatile uint32_t RBR_THR_DLL; /*!< receive buffer, transmit holding, or divisor
                                        low byte, selected by access direction and
                                        DLAB, Address offset: 0x000 */
    volatile uint32_t IER_DLH;     /*!< interrupt enable or divisor high byte,
                                       selected by DLAB, Address offset: 0x004 */
    volatile uint32_t IIR_FCR;     /*!< read interrupt identification, write FIFO
                                       control, Address offset: 0x008 */
    volatile uint32_t LCR;         /*!< line-format and DLAB control, Address offset: 0x00C */
    volatile uint32_t MCR;         /*!< modem control, Address offset: 0x010 */
    volatile uint32_t LSR;         /*!< line status, Address offset: 0x014 */
    volatile uint32_t MSR;         /*!< modem status, Address offset: 0x018 */
    volatile uint32_t SCR;         /*!< scratch register, Address offset: 0x01C */
    volatile uint32_t LPDLL;       /*!< low-power divisor-latch low byte, Address offset: 0x020 */
    volatile uint32_t LPDLH;       /*!< low-power divisor-latch high byte, Address offset: 0x024 */
    uint32_t RESERVED_028[2];      /*!< Reserved, Address offset: 0x028 */
    volatile uint32_t SHADOW[16];  /*!< shadow FIFO data-port array, Address offset: 0x030 */
    volatile uint32_t FAR;         /*!< FIFO access control, Address offset: 0x070 */
    volatile uint32_t TFR;         /*!< transmit FIFO read port, Address offset: 0x074 */
    volatile uint32_t RFW;         /*!< receive FIFO write port, Address offset: 0x078 */
    volatile uint32_t USR;         /*!< UART status register, Address offset: 0x07C */
    volatile uint32_t TFL;         /*!< transmit FIFO entry count, Address offset: 0x080 */
    volatile uint32_t RFL;         /*!< receive FIFO entry count, Address offset: 0x084 */
    volatile uint32_t SRR;         /*!< software-reset register, Address offset: 0x088 */
    volatile uint32_t SRTS;        /*!< shadow RTS register, Address offset: 0x08C */
    volatile uint32_t SBCR;        /*!< shadow break-control register, Address offset: 0x090 */
    volatile uint32_t SDMAM;       /*!< shadow DMA-mode register, Address offset: 0x094 */
    volatile uint32_t SFE;         /*!< shadow FIFO-enable register, Address offset: 0x098 */
    volatile uint32_t SRT;         /*!< shadow receive-trigger register, Address offset: 0x09C */
    volatile uint32_t STET;        /*!< shadow transmit-empty trigger register, Address offset: 0x0A0 */
    volatile uint32_t HTX;         /*!< halt-transmit control, Address offset: 0x0A4 */
    volatile uint32_t DMSA;        /*!< DMA software acknowledgement, Address offset: 0x0A8 */
    uint32_t RESERVED_0AC[18];     /*!< Reserved, Address offset: 0x0AC */
    volatile uint32_t CPR;         /*!< component-parameter register, Address offset: 0x0F4 */
    volatile uint32_t UCV_CTR;     /*!< UCV/CTR register view, Address offset: 0x0F8 */
} UART_Type;

static_assert(offsetof(UART_Type, SHADOW) == 0x030U);
static_assert(offsetof(UART_Type, USR) == 0x07CU);
static_assert(offsetof(UART_Type, DMSA) == 0x0A8U);
static_assert(offsetof(UART_Type, CPR) == 0x0F4U);

/**
 * @brief UART0 register-instance pointer.
 */
#define UART0_REGS ((UART_Type *)(uintptr_t)UART0_BASE)

/**
 * @brief UART1 register-instance pointer.
 */
#define UART1_REGS ((UART_Type *)(uintptr_t)UART1_BASE)

/**
 * @brief UART2 register-instance pointer.
 */
#define UART2_REGS ((UART_Type *)(uintptr_t)UART2_BASE)

/**
 * @brief UART3 register-instance pointer.
 */
#define UART3_REGS ((UART_Type *)(uintptr_t)UART3_BASE)

/**
 * @brief UART4 register-instance pointer.
 */
#define UART4_REGS ((UART_Type *)(uintptr_t)UART4_BASE)

/// @brief Bit for UART received-data interrupt enable.
static constexpr auto UART_IER_ERBFI_BIT = (1UL << 0);
/// @brief Bit for UART transmit-holding-empty interrupt enable.
static constexpr auto UART_IER_ETBEI_BIT = (1UL << 1);
/// @brief Bit for UART receive-line-status interrupt enable.
static constexpr auto UART_IER_ELSI_BIT = (1UL << 2);
/// @brief Bit for UART modem-status interrupt enable.
static constexpr auto UART_IER_EDSSI_BIT = (1UL << 3);
/// @brief Bit for UART programmable THRE interrupt mode.
static constexpr auto UART_IER_PTIME_BIT = (1UL << 7);
/**
 * @brief Bit mask for UART interrupt-identification field.
 *
 * @note The interrupt ID occupies IIR[3:0]; see TRM Table 21.48.
 */
static constexpr auto UART_IIR_IID_MASK = 0x0FUL;
/// @brief Bit mask for UART FIFO-status field.
static constexpr auto UART_IIR_FIFO_STATUS_MASK = (3UL << 6);
/// @brief Bit for UART FIFO enable.
static constexpr auto UART_FCR_FIFO_ENABLE_BIT = (1UL << 0);
/// @brief Bit for UART receive FIFO reset.
static constexpr auto UART_FCR_RX_FIFO_RESET_BIT = (1UL << 1);
/// @brief Bit for UART transmit FIFO reset.
static constexpr auto UART_FCR_TX_FIFO_RESET_BIT = (1UL << 2);
/// @brief Bit for UART DMA-mode selection.
static constexpr auto UART_FCR_DMA_MODE_BIT = (1UL << 3);
/// @brief Least-significant bit position of UART transmit FIFO trigger field.
static constexpr auto UART_FCR_TX_TRIGGER_SHIFT = 4U;
/// @brief Least-significant bit position of UART receive FIFO trigger field.
static constexpr auto UART_FCR_RX_TRIGGER_SHIFT = 6U;
/// @brief Maximum UART FIFO trigger-field encoding.
static constexpr auto UART_FCR_TRIGGER_MAX = 3U;
/// @brief UART baud-generator oversampling factor.
static constexpr auto UART_BAUD_OVERSAMPLING = 16U;
/// @brief Maximum UART baud-divisor latch value.
static constexpr auto UART_BAUD_DIVISOR_MAX = 65'535U;
/// @brief Bit mask for UART data-length field.
static constexpr auto UART_LCR_DATA_LENGTH_MASK = 3UL;
/// @brief Bit for UART stop-bit selection.
static constexpr auto UART_LCR_STOP_BIT = (1UL << 2);
/// @brief Bit for UART parity enable.
static constexpr auto UART_LCR_PARITY_ENABLE_BIT = (1UL << 3);
/// @brief Bit for UART even-parity selection.
static constexpr auto UART_LCR_EVEN_PARITY_BIT = (1UL << 4);
/// @brief Bit for UART stick-parity selection.
static constexpr auto UART_LCR_STICK_PARITY_BIT = (1UL << 5);
/// @brief Bit for UART break control.
static constexpr auto UART_LCR_BREAK_BIT = (1UL << 6);
/// @brief Bit for UART divisor-latch access selection.
static constexpr auto UART_LCR_DLAB_BIT = (1UL << 7);
/// @brief Bit for UART request-to-send output.
static constexpr auto UART_MCR_RTS_BIT = (1UL << 1);
/// @brief Bit for UART automatic flow-control enable.
static constexpr auto UART_MCR_AUTO_FLOW_CONTROL_BIT = (1UL << 5);
/// @brief Bit for UART received-data-ready status.
static constexpr auto UART_LSR_DATA_READY_BIT = (1UL << 0);
/// @brief Bit for UART transmit-holding-register empty status.
static constexpr auto UART_LSR_THR_EMPTY_BIT = (1UL << 5);
/// @brief Bit for UART transmitter empty status.
static constexpr auto UART_LSR_TEMT_BIT = (1UL << 6);
/// @brief Bit for UART busy status.
static constexpr auto UART_USR_BUSY_BIT = (1UL << 0);
/// @brief Bit for UART transmit FIFO not-full status.
static constexpr auto UART_USR_TFNF_BIT = (1UL << 1);
/// @brief Bit for UART transmit FIFO empty status.
static constexpr auto UART_USR_TFE_BIT = (1UL << 2);
/// @brief Bit for UART receive FIFO not-empty status.
static constexpr auto UART_USR_RFNE_BIT = (1UL << 3);
/// @brief Bit for UART receive FIFO full status.
static constexpr auto UART_USR_RFF_BIT = (1UL << 4);

/**
 * @brief Period registers for one PWM channel.
 */
typedef struct
{
    volatile uint32_t HLPERIOD; /*!< high/low period register in clock ticks, Address offset: 0x000 */
    volatile uint32_t PERIOD;   /*!< complete PWM period in clock ticks, Address offset: 0x004 */
} PWM_Channel_Type;

/**
 * @brief PWM period, polarity, start, update, and output-enable registers.
 */
typedef struct
{
    PWM_Channel_Type CHANNEL[PWM_CHANNELS_PER_CONTROLLER]; /*!< PWM channel-period
                                                                register array with
                                                                an eight-byte stride, Address offset: 0x000 */
    uint32_t RESERVED_020[8];                              /*!< Reserved, Address offset: 0x020 */
    volatile uint32_t POLARITY;  /*!< output-polarity selection, Address offset: 0x040 */
    volatile uint32_t PWMSTART;  /*!< channel start control, Address offset: 0x044 */
    volatile uint32_t PWMDONE;   /*!< PWM ending state, Address offset: 0x048 */
    volatile uint32_t PWMUPDATE; /*!< channel dynamic-update control, Address offset: 0x04C */
    volatile uint32_t PCOUNT[PWM_CHANNELS_PER_CONTROLLER];     /*!< per-channel pulse
                                                                count, Address offset: 0x050 */
    volatile uint32_t PULSECOUNT[PWM_CHANNELS_PER_CONTROLLER]; /*!< per-channel
                                                                    output pulse
                                                                    meter status, Address offset: 0x060 */
    uint32_t RESERVED_070[4];                                  /*!< Reserved, Address offset: 0x070 */
    volatile uint32_t SHIFTCOUNT[PWM_CHANNELS_PER_CONTROLLER]; /*!< synchronous-mode
                                                                    per-channel
                                                                    initial
                                                                    difference, Address offset: 0x080 */
    volatile uint32_t SHIFTSTART; /*!< synchronization mode enable, Address offset: 0x090 */
    uint32_t RESERVED_094[15];    /*!< Reserved, Address offset: 0x094 */
    volatile uint32_t PWM_OE;     /*!< channel output enables, Address offset: 0x0D0 */
} PWM_Type;

static_assert(sizeof(PWM_Channel_Type) == 0x008U);
static_assert(offsetof(PWM_Channel_Type, HLPERIOD) == 0x000U);
static_assert(offsetof(PWM_Channel_Type, PERIOD) == 0x004U);
static_assert(offsetof(PWM_Type, POLARITY) == 0x040U);
static_assert(offsetof(PWM_Type, PWMSTART) == 0x044U);
static_assert(offsetof(PWM_Type, PWMUPDATE) == 0x04CU);
static_assert(offsetof(PWM_Type, PWM_OE) == 0x0D0U);

/** @brief PWM0 register instance. */
#define PWM0_REGS ((PWM_Type *)(uintptr_t)PWM0_BASE)
/** @brief PWM1 register instance. */
#define PWM1_REGS ((PWM_Type *)(uintptr_t)PWM1_BASE)
/** @brief PWM2 register instance. */
#define PWM2_REGS ((PWM_Type *)(uintptr_t)PWM2_BASE)
/** @brief PWM3 register instance. */
#define PWM3_REGS ((PWM_Type *)(uintptr_t)PWM3_BASE)

/// @brief Maximum clock count in a PWM period field.
static constexpr auto PWM_PERIOD_MAX = 0x3FFF'FFFFUL;
/// @brief Valid channel mask for one PWM controller.
static constexpr auto PWM_CHANNEL_MASK = (1UL << PWM_CHANNELS_PER_CONTROLLER) - 1UL;

/**
 * @brief SARADC conversion-control, result, and timing registers.
 */
typedef struct
{
    uint32_t RESERVED_000;          /*!< Reserved, Address offset: 0x000 */
    volatile uint32_t CTRL;         /*!< conversion-trigger and
                                                      channel-select control, Address offset: 0x004 */
    volatile const uint32_t STATUS; /*!< conversion-busy status, Address offset: 0x008 */
    volatile uint32_t CYC_SET;      /*!< conversion-cycle configuration, Address offset: 0x00C */
    uint32_t RESERVED_010;          /*!< Reserved, Address offset: 0x010 */
    volatile const uint32_t RESULT[SARADC_CHANNEL_COUNT]; /*!< sample-result array
                                                               for input channels
                                                               one through three, Address offset: 0x014 */
    volatile uint32_t INTR_EN;                            /*!< interrupt enable, Address offset: 0x020 */
    volatile uint32_t INTR_CLR;                           /*!< interrupt clear, Address offset: 0x024 */
    volatile const uint32_t INTR_STA; /*!< interrupt status register, Address offset: 0x028 */
    volatile const uint32_t INTR_RAW; /*!< interrupt raw status register, Address offset: 0x02C */
    volatile uint32_t TEST;           /*!< test and reference-voltage
                                                      selection, Address offset: 0x030 */
    volatile uint32_t TRIM;           /*!< trim register, Address offset: 0x034 */
} SARADC_Type;

static_assert(offsetof(SARADC_Type, CTRL) == 0x004U);
static_assert(offsetof(SARADC_Type, STATUS) == 0x008U);
static_assert(offsetof(SARADC_Type, CYC_SET) == 0x00CU);
static_assert(offsetof(SARADC_Type, RESULT) == 0x014U);
static_assert(offsetof(SARADC_Type, INTR_EN) == 0x020U);
static_assert(offsetof(SARADC_Type, INTR_CLR) == 0x024U);
static_assert(offsetof(SARADC_Type, TEST) == 0x030U);

/// @brief SARADC single-conversion trigger bit.
static constexpr auto SARADC_CTRL_TRIGGER_BIT = (1UL << 0);
/// @brief Start of the SARADC one-hot channel field; channel one uses bit five.
static constexpr auto SARADC_CTRL_CHANNEL_SHIFT = 4U;
/// @brief Mask of the SARADC one-hot channel-selection field.
static constexpr auto SARADC_CTRL_CHANNEL_MASK = (0xFUL << SARADC_CTRL_CHANNEL_SHIFT);
/// @brief SARADC conversion-busy flag.
static constexpr auto SARADC_STATUS_BUSY_BIT = (1UL << 0);
/// @brief SARADC result-valid flag.
static constexpr auto SARADC_RESULT_VALID_BIT = (1UL << 15);
/// @brief Mask of the twelve-bit SARADC sample value.
static constexpr auto SARADC_RESULT_DATA_MASK = 0xFFFUL;
/// @brief SARADC conversion interrupt enable and clear bit.
static constexpr auto SARADC_INTERRUPT_BIT = (1UL << 0);
/// @brief SARADC external VDD18A reference-selection bit.
static constexpr auto SARADC_TEST_EXTERNAL_REFERENCE_BIT = (1UL << 2);
/// @brief SARADC settling-cycle field mask.
static constexpr auto SARADC_CYCLE_SETTLE_MASK = 0x1FUL;
/// @brief SARADC sampling-cycle field shift.
static constexpr auto SARADC_CYCLE_SAMPLE_SHIFT = 8U;
/// @brief SARADC sampling-cycle field mask.
static constexpr auto SARADC_CYCLE_SAMPLE_MASK = (0xFUL << SARADC_CYCLE_SAMPLE_SHIFT);
/// @brief SARADC clock-divider field shift.
static constexpr auto SARADC_CYCLE_DIVIDER_SHIFT = 12U;
/// @brief SARADC clock-divider field mask.
static constexpr auto SARADC_CYCLE_DIVIDER_MASK = (0xFUL << SARADC_CYCLE_DIVIDER_SHIFT);
/// @brief Maximum SARADC divider encoding; the divisor is the encoding plus one.
static constexpr auto SARADC_CYCLE_DIVIDER_MAX = 15U;
/// @brief SARADC comparison-cycle field shift.
static constexpr auto SARADC_CYCLE_COMPARE_SHIFT = 16U;
/// @brief SARADC comparison-cycle field mask.
static constexpr auto SARADC_CYCLE_COMPARE_MASK = (0xFUL << SARADC_CYCLE_COMPARE_SHIFT);
/// @brief Default SARADC settling-cycle encoding.
static constexpr auto SARADC_CYCLE_SETTLE_DEFAULT = 15U;
/// @brief Default SARADC sampling-cycle encoding.
static constexpr auto SARADC_CYCLE_SAMPLE_DEFAULT = 3U;
/// @brief Default SARADC comparison-cycle encoding.
static constexpr auto SARADC_CYCLE_COMPARE_DEFAULT = 11U;

/** @brief Main-domain SARADC register instance. */
#define SARADC_REGS ((SARADC_Type *)(uintptr_t)SARADC_BASE)

/** @brief RTC-domain SARADC register instance. */
#define RTC_SARADC_REGS ((SARADC_Type *)(uintptr_t)RTC_SARADC_BASE)

/**
 * @brief RTC_CTRL register block.
 */
typedef struct
{
    volatile uint32_t RTC_CTRL_VERSION;     /*!< rtc_ctrl_version, Address offset: 0x000 */
    volatile uint32_t RTC_CTRL_UNLOCKKEY;   /*!< rtc_ctrl_unlockkey, Address offset: 0x004 */
    volatile uint32_t RTC_CTRL0;            /*!< rtc_ctrl0, Address offset: 0x008 */
    volatile uint32_t RTC_CTRL_STATUS0;     /*!< rtc_ctrl_status0, Address offset: 0x00C */
    volatile uint32_t RTC_CTRL_STATUS1;     /*!< rtc_ctrl_status1, Address offset: 0x010 */
    volatile uint32_t RTC_CTRL_STATUS2GPIO; /*!< rtc_ctrl_status2gpio, Address offset: 0x014 */
    volatile uint32_t RESET;                /*!< rtcsys_rst_ctrl, Address offset: 0x018 */
    volatile uint32_t CLOCK_MUX;            /*!< rtcsys_clkmux, Address offset: 0x01C */
    volatile uint32_t RTCSYS_MCU51_CTRL0;   /*!< rtcsys_mcu51_ctrl0, Address offset: 0x020 */
    volatile uint32_t RTCSYS_MCU51_CTRL1;   /*!< rtcsys_mcu51_ctrl1, Address offset: 0x024 */
    volatile uint32_t RTCSYS_PMU;           /*!< rtcsys_pmu, Address offset: 0x028 */
    volatile uint32_t RTCSYS_STATUS;        /*!< rtcsys_status, Address offset: 0x02C */
    volatile uint32_t RTCSYS_CLKBYP;        /*!< rtcsys_clkbyp, Address offset: 0x030 */
    volatile uint32_t RTCSYS_CLK_EN;        /*!< rtcsys_clk_en, Address offset: 0x034 */
    volatile uint32_t RTCSYS_WKUP_CTRL;     /*!< rtcsys_wkup_ctrl, Address offset: 0x038 */
    volatile uint32_t RTCSYS_CLKDIV;        /*!< rtcsys_clkdiv, Address offset: 0x03C */
    volatile uint32_t FC_COARSE_EN;         /*!< fc_coarse_en, Address offset: 0x040 */
    volatile uint32_t FC_COARSE_CAL;        /*!< fc_coarse_cal, Address offset: 0x044 */
    volatile uint32_t FC_FINE_EN;           /*!< fc_fine_en, Address offset: 0x048 */
    volatile uint32_t FC_FINE_PERIOD;       /*!< fc_fine_period, Address offset: 0x04C */
    volatile uint32_t FC_FINE_CAL;          /*!< fc_fine_cal, Address offset: 0x050 */
    volatile uint32_t RTCSYS_PMU2;          /*!< rtcsys_pmu2, Address offset: 0x054 */
    volatile uint32_t RTCSYS_CLKDIV1;       /*!< rtcsys_clkdiv1, Address offset: 0x058 */
    volatile uint32_t RTCSYS_MCU51_DBG;     /*!< rtcsys_mcu51_dbg, Address offset: 0x05C */
    volatile uint32_t SW_REG0;              /*!< sw_reg0, Address offset: 0x060 */
    volatile uint32_t SW_REG1_POR;          /*!< sw_reg1_por, Address offset: 0x064 */
    volatile uint32_t FAB_LP_CTRL;          /*!< fab_lp_ctrl, Address offset: 0x068 */
    volatile uint32_t FAB_OPTION;           /*!< fab_option, Address offset: 0x06C */
    uint32_t RESERVED_070[3];               /*!< Reserved, Address offset: 0x070 */
    volatile uint32_t RTCSYS_MCU51_ICTRL1;  /*!< rtcsys_mcu51_ictrl1, Address offset: 0x07C */
    volatile uint32_t RTC_IP_PWR_REQ;       /*!< rtc_ip_pwr_req, Address offset: 0x080 */
    volatile uint32_t RTC_IP_ISO_CTRL;      /*!< rtc_ip_iso_ctrl, Address offset: 0x084 */
    volatile uint32_t RTCSYS_SPARE_REG0;    /*!< rtcsys_spare_reg0, Address offset: 0x088 */
    volatile uint32_t RTCSYS_SPARE_REG1;    /*!< rtcsys_spare_reg1, Address offset: 0x08C */
    volatile uint32_t RTCSYS_SPARE_RO;      /*!< rtcsys_spare_ro, Address offset: 0x090 */
    volatile uint32_t RTCSYS_WKUP_CTRL1;    /*!< rtcsys_wkup_ctrl1, Address offset: 0x094 */
    volatile uint32_t RTCSYS_SRAM_CTRL;     /*!< rtcsys_sram_ctrl, Address offset: 0x098 */
    volatile uint32_t RTCSYS_IO_CTRL;       /*!< rtcsys_io_ctrl, Address offset: 0x09C */
    volatile uint32_t RTCSYS_WDT_CTRL;      /*!< rtcsys_wdt_ctrl, Address offset: 0x0A0 */
    volatile uint32_t RTCSYS_IRRX_CLK_CTRL; /*!< rtcsys_irrx_clk_ctrl, Address offset: 0x0A4 */
    volatile uint32_t RTCSYS_RTC_WKUP_CTRL; /*!< rtcsys_rtc_wkup_ctrl, Address offset: 0x0A8 */
    volatile uint32_t RTCSYS_POR_RST_CTRL;  /*!< rtcsys_por_rst_ctrl, Address offset: 0x0AC */
} RTC_CTRL_Type;

static_assert(offsetof(RTC_CTRL_Type, RTC_CTRL_VERSION) == 0x000U);
static_assert(offsetof(RTC_CTRL_Type, RTC_CTRL_UNLOCKKEY) == 0x004U);
static_assert(offsetof(RTC_CTRL_Type, RTC_CTRL0) == 0x008U);
static_assert(offsetof(RTC_CTRL_Type, RTC_CTRL_STATUS0) == 0x00CU);
static_assert(offsetof(RTC_CTRL_Type, RTC_CTRL_STATUS1) == 0x010U);
static_assert(offsetof(RTC_CTRL_Type, RTC_CTRL_STATUS2GPIO) == 0x014U);
static_assert(offsetof(RTC_CTRL_Type, RESET) == 0x018U);
static_assert(offsetof(RTC_CTRL_Type, CLOCK_MUX) == 0x01CU);
static_assert(offsetof(RTC_CTRL_Type, RTCSYS_MCU51_CTRL0) == 0x020U);
static_assert(offsetof(RTC_CTRL_Type, RTCSYS_MCU51_CTRL1) == 0x024U);
static_assert(offsetof(RTC_CTRL_Type, RTCSYS_PMU) == 0x028U);
static_assert(offsetof(RTC_CTRL_Type, RTCSYS_STATUS) == 0x02CU);
static_assert(offsetof(RTC_CTRL_Type, RTCSYS_CLKBYP) == 0x030U);
static_assert(offsetof(RTC_CTRL_Type, RTCSYS_CLK_EN) == 0x034U);
static_assert(offsetof(RTC_CTRL_Type, RTCSYS_WKUP_CTRL) == 0x038U);
static_assert(offsetof(RTC_CTRL_Type, RTCSYS_CLKDIV) == 0x03CU);
static_assert(offsetof(RTC_CTRL_Type, FC_COARSE_EN) == 0x040U);
static_assert(offsetof(RTC_CTRL_Type, FC_COARSE_CAL) == 0x044U);
static_assert(offsetof(RTC_CTRL_Type, FC_FINE_EN) == 0x048U);
static_assert(offsetof(RTC_CTRL_Type, FC_FINE_PERIOD) == 0x04CU);
static_assert(offsetof(RTC_CTRL_Type, FC_FINE_CAL) == 0x050U);
static_assert(offsetof(RTC_CTRL_Type, RTCSYS_PMU2) == 0x054U);
static_assert(offsetof(RTC_CTRL_Type, RTCSYS_CLKDIV1) == 0x058U);
static_assert(offsetof(RTC_CTRL_Type, RTCSYS_MCU51_DBG) == 0x05CU);
static_assert(offsetof(RTC_CTRL_Type, SW_REG0) == 0x060U);
static_assert(offsetof(RTC_CTRL_Type, SW_REG1_POR) == 0x064U);
static_assert(offsetof(RTC_CTRL_Type, FAB_LP_CTRL) == 0x068U);
static_assert(offsetof(RTC_CTRL_Type, FAB_OPTION) == 0x06CU);
static_assert(offsetof(RTC_CTRL_Type, RTCSYS_MCU51_ICTRL1) == 0x07CU);
static_assert(offsetof(RTC_CTRL_Type, RTC_IP_PWR_REQ) == 0x080U);
static_assert(offsetof(RTC_CTRL_Type, RTC_IP_ISO_CTRL) == 0x084U);
static_assert(offsetof(RTC_CTRL_Type, RTCSYS_SPARE_REG0) == 0x088U);
static_assert(offsetof(RTC_CTRL_Type, RTCSYS_SPARE_REG1) == 0x08CU);
static_assert(offsetof(RTC_CTRL_Type, RTCSYS_SPARE_RO) == 0x090U);
static_assert(offsetof(RTC_CTRL_Type, RTCSYS_WKUP_CTRL1) == 0x094U);
static_assert(offsetof(RTC_CTRL_Type, RTCSYS_SRAM_CTRL) == 0x098U);
static_assert(offsetof(RTC_CTRL_Type, RTCSYS_IO_CTRL) == 0x09CU);
static_assert(offsetof(RTC_CTRL_Type, RTCSYS_WDT_CTRL) == 0x0A0U);
static_assert(offsetof(RTC_CTRL_Type, RTCSYS_IRRX_CLK_CTRL) == 0x0A4U);
static_assert(offsetof(RTC_CTRL_Type, RTCSYS_RTC_WKUP_CTRL) == 0x0A8U);
static_assert(offsetof(RTC_CTRL_Type, RTCSYS_POR_RST_CTRL) == 0x0ACU);

/**
 * @brief RTC_CTRL register-instance pointer.
 */
#define RTC_CTRL_REGS ((RTC_CTRL_Type *)(uintptr_t)RTC_CTRL_BASE)

/// @brief RTC SARADC active-low reset-release bit.
static constexpr auto RTC_CTRL_SARADC_RESETN_BIT = (1UL << 17);
/// @brief RTC SARADC divided-oscillator selector; clear to select XTAL.
static constexpr auto RTC_CTRL_SARADC_OSC_DIV_BIT = (1UL << 20);

/**
 * @brief DesignWare watchdog control and counter registers.
 */
typedef struct
{
    volatile uint32_t CR;         /*!< watchdog control register, Address offset: 0x000 */
    volatile uint32_t TORR;       /*!< timeout-range configuration, Address offset: 0x004 */
    volatile const uint32_t CCVR; /*!< current counter value, Address offset: 0x008 */
    volatile uint32_t CRR;        /*!< counter-restart register, Address offset: 0x00C */
    volatile const uint32_t STAT; /*!< interrupt status, Address offset: 0x010 */
    volatile const uint32_t EOI;  /*!< read-to-clear interrupt register, Address offset: 0x014 */
    uint32_t RESERVED_018;        /*!< Reserved, Address offset: 0x018 */
    volatile uint32_t TOC;        /*!< timeout-count configuration, Address offset: 0x01C */
} WDT_Type;

static_assert(offsetof(WDT_Type, CR) == 0x000U);
static_assert(offsetof(WDT_Type, TORR) == 0x004U);
static_assert(offsetof(WDT_Type, CRR) == 0x00CU);
static_assert(offsetof(WDT_Type, TOC) == 0x01CU);

/** @brief WDT0 register instance. */
#define WDT0_REGS ((WDT_Type *)(uintptr_t)WDT0_BASE)
/** @brief WDT1 register instance. */
#define WDT1_REGS ((WDT_Type *)(uintptr_t)WDT1_BASE)
/** @brief WDT2 register instance. */
#define WDT2_REGS ((WDT_Type *)(uintptr_t)WDT2_BASE)

/// @brief Watchdog enable bit; only a system reset can clear it once set.
static constexpr auto WDT_CR_ENABLE_BIT = (1UL << 0);
/// @brief Watchdog interrupt-then-reset response selector.
static constexpr auto WDT_CR_INTERRUPT_RESPONSE_BIT = (1UL << 1);
/// @brief Maximum watchdog timeout-range encoding.
static constexpr auto WDT_TOP_MAX = 15U;
/// @brief Watchdog initial timeout-range field shift.
static constexpr auto WDT_TOP_INITIAL_SHIFT = 4U;
/// @brief Base timeout exponent in exponential counter mode.
static constexpr auto WDT_TIMEOUT_EXPONENT_MIN = 16U;
/// @brief Write key that reloads the watchdog and clears its interrupt.
static constexpr auto WDT_RESTART_KEY = 0x76U;

/**
 * @brief One Timer channel register block.
 */
typedef struct
{
    volatile uint32_t LOAD_COUNT;    /*!< Value to be loaded into Timer1, Address offset: 0x000 */
    volatile uint32_t CURRENT_VALUE; /*!< Current Value of Timer1, Address offset: 0x004 */
    volatile uint32_t CONTROL;       /*!< Control Register for Timer1, Address offset: 0x008 */
    volatile uint32_t EOI;           /*!< Clears the interrupt from Timer1, Address offset: 0x00C */
    volatile uint32_t INT_STATUS;    /*!< Contains the interrupt status for Timer1, Address offset: 0x010 */
} TIMER_Channel_Type;

static_assert(offsetof(TIMER_Channel_Type, LOAD_COUNT) == 0x000U);
static_assert(offsetof(TIMER_Channel_Type, CURRENT_VALUE) == 0x004U);
static_assert(offsetof(TIMER_Channel_Type, CONTROL) == 0x008U);
static_assert(offsetof(TIMER_Channel_Type, EOI) == 0x00CU);
static_assert(offsetof(TIMER_Channel_Type, INT_STATUS) == 0x010U);

/**
 * @brief Timer register block.
 */
typedef struct
{
    TIMER_Channel_Type CHANNEL[8];           /*!< channel register array with a
                                                 0x14-byte stride, Address offset: 0x000 */
    volatile uint32_t TIMERS_INT_STATUS;     /*!< Contains the interrupt status of
                                                 all timers in the component, Address offset: 0x0A0 */
    volatile uint32_t TIMERS_EOI;            /*!< Returns all zeroes (0) and clears
                                                 all active interrupts, Address offset: 0x0A4 */
    volatile uint32_t TIMERS_RAW_INT_STATUS; /*!< Contains the unmasked interrupt
                                                  status of all timers in the
                                                  component, Address offset: 0x0A8 */
} TIMER_Type;

static_assert(offsetof(TIMER_Type, TIMERS_INT_STATUS) == 0x0A0U);
static_assert(offsetof(TIMER_Type, TIMERS_EOI) == 0x0A4U);
static_assert(offsetof(TIMER_Type, TIMERS_RAW_INT_STATUS) == 0x0A8U);

/**
 * @brief TIMER register-instance pointer.
 */
#define TIMER_REGS ((TIMER_Type *)(uintptr_t)TIMER_BASE)

/**
 * @brief TRNG register block.
 */
typedef struct
{
    volatile uint32_t CTRL;   /*!< Used to cause TRNG to execute one of a number of
                                  actions, Address offset: 0x000 */
    uint32_t RESERVED_004[2]; /*!< Reserved, Address offset: 0x004 */
    volatile uint32_t STAT;   /*!< Allows the user to monitor the internal status of
                                  the TRNG, Address offset: 0x00C */
    uint32_t RESERVED_010[1]; /*!< Reserved, Address offset: 0x010 */
    volatile uint32_t ISTAT;  /*!< Allows the user to monitor the interrupt status of
                                  the TRNG, Address offset: 0x014 */
    uint32_t RESERVED_018[3]; /*!< Reserved, Address offset: 0x018 */
    volatile uint32_t RAND0;  /*!< Used by the host to read bits [31:0] of the newly
                                  generated 128-bit random, Address offset: 0x024 */
    volatile uint32_t RAND1;  /*!< Used by the host to read bits [63:32] of the newly
                                  generated 128-bit random, Address offset: 0x028 */
    volatile uint32_t RAND2;  /*!< Used by the host to read bits [95:64] of the newly
                                  generated 128-bit random, Address offset: 0x02C */
    volatile uint32_t RAND3;  /*!< Used by the host to read bits [127:96] of the
                                  newly generated 128-bit random, Address offset: 0x030 */
} TRNG_Type;

static_assert(offsetof(TRNG_Type, CTRL) == 0x000U);
static_assert(offsetof(TRNG_Type, STAT) == 0x00CU);
static_assert(offsetof(TRNG_Type, ISTAT) == 0x014U);
static_assert(offsetof(TRNG_Type, RAND0) == 0x024U);
static_assert(offsetof(TRNG_Type, RAND1) == 0x028U);
static_assert(offsetof(TRNG_Type, RAND2) == 0x02CU);
static_assert(offsetof(TRNG_Type, RAND3) == 0x030U);

/**
 * @brief TRNG_REGS register-instance pointer.
 */
#define TRNG_REGS ((TRNG_Type *)(uintptr_t)TRNG_BASE)

/**
 * @brief KeyScan register block.
 */
typedef struct
{
    volatile uint32_t KEYSCAN_CONFIG0;        /*!< Address offset: 0x000 */
    volatile uint32_t KEYSCAN_CONFIG1;        /*!< Address offset: 0x004 */
    volatile uint32_t KEYSCAN_CONFIG2;        /*!< Address offset: 0x008 */
    volatile uint32_t KEYSCAN_CONFIG3;        /*!< Address offset: 0x00C */
    uint32_t RESERVED_010[1];                 /*!< Reserved, Address offset: 0x010 */
    volatile uint32_t KEYSCAN_SNAPSHOT_ARRAY; /*!< Address offset: 0x014 */
    uint32_t RESERVED_018[1];                 /*!< Reserved, Address offset: 0x018 */
    volatile uint32_t KEYSCAN_SNAPSHOT_TRIG;  /*!< Address offset: 0x01C */
    volatile uint32_t KEYSCAN_FIFO_STATUS;    /*!< Address offset: 0x020 */
    volatile uint32_t KEYSCAN_FIFO;           /*!< Address offset: 0x024 */
    volatile uint32_t KEYSCAN_IRQ_ENABLE;     /*!< Address offset: 0x028 */
    volatile uint32_t KEYSCAN_IRQ_FLAG;       /*!< Address offset: 0x02C */
    volatile uint32_t KEYSCAN_IRQ_CLEAR;      /*!< Address offset: 0x030 */
} KEYSCAN_Type;

static_assert(offsetof(KEYSCAN_Type, KEYSCAN_CONFIG0) == 0x000U);
static_assert(offsetof(KEYSCAN_Type, KEYSCAN_CONFIG1) == 0x004U);
static_assert(offsetof(KEYSCAN_Type, KEYSCAN_CONFIG2) == 0x008U);
static_assert(offsetof(KEYSCAN_Type, KEYSCAN_CONFIG3) == 0x00CU);
static_assert(offsetof(KEYSCAN_Type, KEYSCAN_SNAPSHOT_ARRAY) == 0x014U);
static_assert(offsetof(KEYSCAN_Type, KEYSCAN_SNAPSHOT_TRIG) == 0x01CU);
static_assert(offsetof(KEYSCAN_Type, KEYSCAN_FIFO_STATUS) == 0x020U);
static_assert(offsetof(KEYSCAN_Type, KEYSCAN_FIFO) == 0x024U);
static_assert(offsetof(KEYSCAN_Type, KEYSCAN_IRQ_ENABLE) == 0x028U);
static_assert(offsetof(KEYSCAN_Type, KEYSCAN_IRQ_FLAG) == 0x02CU);
static_assert(offsetof(KEYSCAN_Type, KEYSCAN_IRQ_CLEAR) == 0x030U);

/**
 * @brief KEYSCAN_REGS register-instance pointer.
 */
#define KEYSCAN_REGS ((KEYSCAN_Type *)(uintptr_t)KEYSCAN_BASE)

/**
 * @brief Wiegand register block.
 */
typedef struct
{
    volatile uint32_t TX_CONFIG0;      /*!< Address offset: 0x000 */
    volatile uint32_t TX_CONFIG1;      /*!< Address offset: 0x004 */
    volatile uint32_t TX_CONFIG2;      /*!< Address offset: 0x008 */
    volatile uint32_t TX_BUFFER;       /*!< Address offset: 0x00C */
    uint32_t RESERVED_010[1];          /*!< Reserved, Address offset: 0x010 */
    volatile uint32_t TX_TRIG;         /*!< Address offset: 0x014 */
    volatile uint32_t TX_BUSY;         /*!< Address offset: 0x018 */
    volatile uint32_t TX_DEBUG;        /*!< Address offset: 0x01C */
    volatile uint32_t RX_CONFIG0;      /*!< Address offset: 0x020 */
    volatile uint32_t RX_CONFIG1;      /*!< Address offset: 0x024 */
    volatile uint32_t RX_CONFIG2;      /*!< Address offset: 0x028 */
    volatile uint32_t RX_BUFFER;       /*!< Address offset: 0x02C */
    uint32_t RESERVED_030[2];          /*!< Reserved, Address offset: 0x030 */
    volatile uint32_t RX_BUFFER_VALID; /*!< Address offset: 0x038 */
    volatile uint32_t RX_BUFFER_CLEAR; /*!< Address offset: 0x03C */
    volatile uint32_t RX_DEBUG;        /*!< Address offset: 0x040 */
    volatile uint32_t IRQ_ENABLE;      /*!< Address offset: 0x044 */
    volatile uint32_t IRQ_FLAG;        /*!< Address offset: 0x048 */
    volatile uint32_t IRQ_CLEAR;       /*!< Address offset: 0x04C */
} WGN_Type;

static_assert(offsetof(WGN_Type, TX_CONFIG0) == 0x000U);
static_assert(offsetof(WGN_Type, TX_CONFIG1) == 0x004U);
static_assert(offsetof(WGN_Type, TX_CONFIG2) == 0x008U);
static_assert(offsetof(WGN_Type, TX_BUFFER) == 0x00CU);
static_assert(offsetof(WGN_Type, TX_TRIG) == 0x014U);
static_assert(offsetof(WGN_Type, TX_BUSY) == 0x018U);
static_assert(offsetof(WGN_Type, TX_DEBUG) == 0x01CU);
static_assert(offsetof(WGN_Type, RX_CONFIG0) == 0x020U);
static_assert(offsetof(WGN_Type, RX_CONFIG1) == 0x024U);
static_assert(offsetof(WGN_Type, RX_CONFIG2) == 0x028U);
static_assert(offsetof(WGN_Type, RX_BUFFER) == 0x02CU);
static_assert(offsetof(WGN_Type, RX_BUFFER_VALID) == 0x038U);
static_assert(offsetof(WGN_Type, RX_BUFFER_CLEAR) == 0x03CU);
static_assert(offsetof(WGN_Type, RX_DEBUG) == 0x040U);
static_assert(offsetof(WGN_Type, IRQ_ENABLE) == 0x044U);
static_assert(offsetof(WGN_Type, IRQ_FLAG) == 0x048U);
static_assert(offsetof(WGN_Type, IRQ_CLEAR) == 0x04CU);

/**
 * @brief WGN0_REGS register-instance pointer.
 */
#define WGN0_REGS ((WGN_Type *)(uintptr_t)WGN0_BASE)

/**
 * @brief WGN1_REGS register-instance pointer.
 */
#define WGN1_REGS ((WGN_Type *)(uintptr_t)WGN1_BASE)

/**
 * @brief WGN2_REGS register-instance pointer.
 */
#define WGN2_REGS ((WGN_Type *)(uintptr_t)WGN2_BASE)

/**
 * @brief IRRX register block.
 */
typedef struct
{
    volatile uint32_t IR_EN;            /*!< Address offset: 0x000 */
    volatile uint32_t IR_MODE;          /*!< Address offset: 0x004 */
    volatile uint32_t IR_CFG;           /*!< Address offset: 0x008 */
    volatile uint32_t IR_FRAME;         /*!< Address offset: 0x00C */
    volatile uint32_t INT_EN;           /*!< Address offset: 0x010 */
    volatile uint32_t INT_CLR;          /*!< Address offset: 0x014 */
    volatile uint32_t INT_MSK;          /*!< Address offset: 0x018 */
    volatile uint32_t INT;              /*!< Address offset: 0x01C */
    volatile uint32_t INT_RAW;          /*!< Address offset: 0x020 */
    uint32_t RESERVED_024[3];           /*!< Reserved, Address offset: 0x024 */
    volatile uint32_t IR_SYMBOL_CFG0;   /*!< Address offset: 0x030 */
    volatile uint32_t IR_SYMBOL_CFG1;   /*!< Address offset: 0x034 */
    volatile uint32_t IR_SYMBOL_CFG2;   /*!< Address offset: 0x038 */
    volatile uint32_t IR_SYMBOL_CFG3;   /*!< Address offset: 0x03C */
    volatile uint32_t IR_SYMBOL_CFG4;   /*!< Address offset: 0x040 */
    volatile uint32_t IR_SYMBOL_CFG5;   /*!< Address offset: 0x044 */
    volatile uint32_t IR_SYMBOL_CFG6;   /*!< Address offset: 0x048 */
    volatile uint32_t IR_SYMBOL_CFG7;   /*!< Address offset: 0x04C */
    volatile uint32_t IR_CLOCK_CTRL;    /*!< Address offset: 0x050 */
    uint32_t RESERVED_054[11];          /*!< Reserved, Address offset: 0x054 */
    volatile uint32_t IR_DATA0;         /*!< Address offset: 0x080 */
    volatile uint32_t IR_DATA1;         /*!< Address offset: 0x084 */
    volatile uint32_t IR_DATA2;         /*!< Address offset: 0x088 */
    volatile uint32_t IR_DATA3;         /*!< Address offset: 0x08C */
    volatile uint32_t IR_DATA4;         /*!< Address offset: 0x090 */
    uint32_t RESERVED_094[5];           /*!< Reserved, Address offset: 0x094 */
    volatile uint32_t IR_NEC_DATA0;     /*!< Address offset: 0x0A8 */
    volatile uint32_t IR_SONY_DATA0;    /*!< Address offset: 0x0AC */
    volatile uint32_t IR_SONY_DATA1;    /*!< Address offset: 0x0B0 */
    volatile uint32_t IR_PHILIPS_DATA0; /*!< Address offset: 0x0B4 */
    volatile uint32_t IR_PHILIPS_DATA1; /*!< Address offset: 0x0B8 */
    uint32_t RESERVED_0BC[9];           /*!< Reserved, Address offset: 0x0BC */
    volatile uint32_t IR_PRD_REC0;      /*!< Address offset: 0x0E0 */
    volatile uint32_t IR_PRD_REC1;      /*!< Address offset: 0x0E4 */
    volatile uint32_t IR_PRD_REC2;      /*!< Address offset: 0x0E8 */
    volatile uint32_t IR_PRD_REC3;      /*!< Address offset: 0x0EC */
    volatile uint32_t IR_PRD_REC4;      /*!< Address offset: 0x0F0 */
    volatile uint32_t IR_PRD_REC5;      /*!< Address offset: 0x0F4 */
    uint32_t RESERVED_0F8[958];         /*!< Reserved, Address offset: 0x0F8 */
    volatile uint32_t SPARE_0;          /*!< Address offset: 0xFF0 */
    volatile uint32_t SPARE_1;          /*!< Address offset: 0xFF4 */
    volatile uint32_t SPARE_RO;         /*!< Address offset: 0xFF8 */
    volatile uint32_t DATA_CODE;        /*!< Address offset: 0xFFC */
} IRRX_Type;

static_assert(offsetof(IRRX_Type, IR_EN) == 0x000U);
static_assert(offsetof(IRRX_Type, IR_MODE) == 0x004U);
static_assert(offsetof(IRRX_Type, IR_CFG) == 0x008U);
static_assert(offsetof(IRRX_Type, IR_FRAME) == 0x00CU);
static_assert(offsetof(IRRX_Type, INT_EN) == 0x010U);
static_assert(offsetof(IRRX_Type, INT_CLR) == 0x014U);
static_assert(offsetof(IRRX_Type, INT_MSK) == 0x018U);
static_assert(offsetof(IRRX_Type, INT) == 0x01CU);
static_assert(offsetof(IRRX_Type, INT_RAW) == 0x020U);
static_assert(offsetof(IRRX_Type, IR_SYMBOL_CFG0) == 0x030U);
static_assert(offsetof(IRRX_Type, IR_SYMBOL_CFG1) == 0x034U);
static_assert(offsetof(IRRX_Type, IR_SYMBOL_CFG2) == 0x038U);
static_assert(offsetof(IRRX_Type, IR_SYMBOL_CFG3) == 0x03CU);
static_assert(offsetof(IRRX_Type, IR_SYMBOL_CFG4) == 0x040U);
static_assert(offsetof(IRRX_Type, IR_SYMBOL_CFG5) == 0x044U);
static_assert(offsetof(IRRX_Type, IR_SYMBOL_CFG6) == 0x048U);
static_assert(offsetof(IRRX_Type, IR_SYMBOL_CFG7) == 0x04CU);
static_assert(offsetof(IRRX_Type, IR_CLOCK_CTRL) == 0x050U);
static_assert(offsetof(IRRX_Type, IR_DATA0) == 0x080U);
static_assert(offsetof(IRRX_Type, IR_DATA1) == 0x084U);
static_assert(offsetof(IRRX_Type, IR_DATA2) == 0x088U);
static_assert(offsetof(IRRX_Type, IR_DATA3) == 0x08CU);
static_assert(offsetof(IRRX_Type, IR_DATA4) == 0x090U);
static_assert(offsetof(IRRX_Type, IR_NEC_DATA0) == 0x0A8U);
static_assert(offsetof(IRRX_Type, IR_SONY_DATA0) == 0x0ACU);
static_assert(offsetof(IRRX_Type, IR_SONY_DATA1) == 0x0B0U);
static_assert(offsetof(IRRX_Type, IR_PHILIPS_DATA0) == 0x0B4U);
static_assert(offsetof(IRRX_Type, IR_PHILIPS_DATA1) == 0x0B8U);
static_assert(offsetof(IRRX_Type, IR_PRD_REC0) == 0x0E0U);
static_assert(offsetof(IRRX_Type, IR_PRD_REC1) == 0x0E4U);
static_assert(offsetof(IRRX_Type, IR_PRD_REC2) == 0x0E8U);
static_assert(offsetof(IRRX_Type, IR_PRD_REC3) == 0x0ECU);
static_assert(offsetof(IRRX_Type, IR_PRD_REC4) == 0x0F0U);
static_assert(offsetof(IRRX_Type, IR_PRD_REC5) == 0x0F4U);
static_assert(offsetof(IRRX_Type, SPARE_0) == 0xFF0U);
static_assert(offsetof(IRRX_Type, SPARE_1) == 0xFF4U);
static_assert(offsetof(IRRX_Type, SPARE_RO) == 0xFF8U);
static_assert(offsetof(IRRX_Type, DATA_CODE) == 0xFFCU);

/**
 * @brief IRRX_REGS register-instance pointer.
 */
#define IRRX_REGS ((IRRX_Type *)(uintptr_t)IRRX_BASE)

/**
 * @brief SPI NOR register block.
 */
typedef struct
{
    volatile uint32_t SPI_CTRL;  /*!< SPI_NOR Operation control, Address offset: 0x000 */
    volatile uint32_t CE_CTRL;   /*!< CE Operation control, Address offset: 0x004 */
    volatile uint32_t DLY_CTRL;  /*!< Delay control, Address offset: 0x008 */
    volatile uint32_t DMMR_CTRL; /*!< DMMR Mode control, Address offset: 0x00C */
    volatile uint32_t TRAN_CSR;  /*!< transport control, Address offset: 0x010 */
    volatile uint32_t TRAN_NUM;  /*!< Number of frames transmitted, Address offset: 0x014 */
    volatile uint32_t FF_PORT;   /*!< FIFO write read port, Address offset: 0x018 */
    uint32_t RESERVED_01C[1];    /*!< Reserved, Address offset: 0x01C */
    volatile uint32_t FF_PT;     /*!< FIFO indicator status, Address offset: 0x020 */
    uint32_t RESERVED_024[1];    /*!< Reserved, Address offset: 0x024 */
    volatile uint32_t INT_STS;   /*!< interrupt status, Address offset: 0x028 */
    volatile uint32_t INT_EN;    /*!< Interrupt enable, Address offset: 0x02C */
} SPI_NOR_Type;

static_assert(offsetof(SPI_NOR_Type, SPI_CTRL) == 0x000U);
static_assert(offsetof(SPI_NOR_Type, CE_CTRL) == 0x004U);
static_assert(offsetof(SPI_NOR_Type, DLY_CTRL) == 0x008U);
static_assert(offsetof(SPI_NOR_Type, DMMR_CTRL) == 0x00CU);
static_assert(offsetof(SPI_NOR_Type, TRAN_CSR) == 0x010U);
static_assert(offsetof(SPI_NOR_Type, TRAN_NUM) == 0x014U);
static_assert(offsetof(SPI_NOR_Type, FF_PORT) == 0x018U);
static_assert(offsetof(SPI_NOR_Type, FF_PT) == 0x020U);
static_assert(offsetof(SPI_NOR_Type, INT_STS) == 0x028U);
static_assert(offsetof(SPI_NOR_Type, INT_EN) == 0x02CU);

/**
 * @brief SPI NAND register block.
 */
typedef struct
{
    volatile uint32_t REG_CTRL;        /*!< transmission control, Address offset: 0x000 */
    volatile uint32_t REG_TIMING_CTRL; /*!< timing control, Address offset: 0x004 */
    volatile uint32_t REG_TRX_SIZE;    /*!< number of content size, Address offset: 0x008 */
    uint32_t RESERVED_00C[1];          /*!< Reserved, Address offset: 0x00C */
    volatile uint32_t REG_INT_EN;      /*!< interrupt enable, Address offset: 0x010 */
    volatile uint32_t REG_INT_CLR;     /*!< interrupt clear, Address offset: 0x014 */
    uint32_t RESERVED_018[1];          /*!< Reserved, Address offset: 0x018 */
    volatile uint32_t REG_INT_STS;     /*!< interrupt status, Address offset: 0x01C */
    uint32_t RESERVED_020[4];          /*!< Reserved, Address offset: 0x020 */
    volatile uint32_t REG_CONT0;       /*!< content 0, Address offset: 0x030 */
    volatile uint32_t REG_CONT1;       /*!< content 1, Address offset: 0x034 */
    uint32_t RESERVED_038[8];          /*!< Reserved, Address offset: 0x038 */
    volatile uint32_t REG_CMPLT_CNT;   /*!< number of transferred bytes, Address offset: 0x058 */
    uint32_t RESERVED_05C[1];          /*!< Reserved, Address offset: 0x05C */
    volatile uint32_t REG_TX_DATA;     /*!< tx data, Address offset: 0x060 */
    volatile uint32_t REG_RX_DATA;     /*!< rx data, Address offset: 0x064 */
} SPI_NAND_Type;

static_assert(offsetof(SPI_NAND_Type, REG_CTRL) == 0x000U);
static_assert(offsetof(SPI_NAND_Type, REG_TIMING_CTRL) == 0x004U);
static_assert(offsetof(SPI_NAND_Type, REG_TRX_SIZE) == 0x008U);
static_assert(offsetof(SPI_NAND_Type, REG_INT_EN) == 0x010U);
static_assert(offsetof(SPI_NAND_Type, REG_INT_CLR) == 0x014U);
static_assert(offsetof(SPI_NAND_Type, REG_INT_STS) == 0x01CU);
static_assert(offsetof(SPI_NAND_Type, REG_CONT0) == 0x030U);
static_assert(offsetof(SPI_NAND_Type, REG_CONT1) == 0x034U);
static_assert(offsetof(SPI_NAND_Type, REG_CMPLT_CNT) == 0x058U);
static_assert(offsetof(SPI_NAND_Type, REG_TX_DATA) == 0x060U);
static_assert(offsetof(SPI_NAND_Type, REG_RX_DATA) == 0x064U);

/**
 * @brief SPI_NAND_REGS register-instance pointer.
 */
#define SPI_NAND_REGS ((SPI_NAND_Type *)(uintptr_t)SPI_NAND_BASE)

/**
 * @brief ETH0/GMAC register block.
 */
typedef struct
{
    volatile uint32_t REG_MAC_CONFIG;                /*!< Local MAC Operation
                                                      Configuration Register, Address offset: 0x000 */
    uint32_t RESERVED_004[3];                        /*!< Reserved, Address offset: 0x004 */
    volatile uint32_t REG_MDIO_ADDR;                 /*!< MDIO Operation Register, Address offset: 0x010 */
    volatile uint32_t REG_MDIO_DATA;                 /*!< MDIO Data Read and Write
                                                      Register, Address offset: 0x014 */
    uint32_t RESERVED_018[10];                       /*!< Reserved, Address offset: 0x018 */
    volatile uint32_t REG_MAC_ADDR0_HIGH;            /*!< Local MAC Address Register#0
                                                      High 16bit, Address offset: 0x040 */
    volatile uint32_t REG_MAC_ADDR0_LOW;             /*!< Local MAC Address Register#0
                                                      Low 32bit, Address offset: 0x044 */
    volatile uint32_t REG_MAC_ADDR1_HIGH;            /*!< Local MAC Address Register#1
                                                      High 16bit, Address offset: 0x048 */
    volatile uint32_t REG_MAC_ADDR1_LOW;             /*!< Local MAC Address Register#1
                                                      Low 32bit, Address offset: 0x04C */
    uint32_t RESERVED_050[50];                       /*!< Reserved, Address offset: 0x050 */
    volatile uint32_t REG_TX_PACKET_NUM_GOOD_BAD;    /*!< Tranmit Good and Bad Packet
                                                       Num Count Register, Address offset: 0x118 */
    volatile uint32_t REG_TX_BCAST_PACKETS_GOOD;     /*!< Tranmit Good Bad Packet
                                                      Broadcast Count Register, Address offset: 0x11C */
    volatile uint32_t REG_TX_MCAST_PACKETS_GOOD;     /*!< Tranmit Good Bad Packet
                                                      Multicast Count Register, Address offset: 0x120 */
    uint32_t RESERVED_124[6];                        /*!< Reserved, Address offset: 0x124 */
    volatile uint32_t REG_TX_UCAST_PACKETS_GOOD_BAD; /*!< Tranmit Good and Bad
                                                          Packet Unicast Count
                                                          Register, Address offset: 0x13C */
    volatile uint32_t REG_TX_MCAST_PACKETS_GOOD_BAD; /*!< Tranmit Good and Bad
                                                          Packet Multicast Count
                                                          Register, Address offset: 0x140 */
    volatile uint32_t REG_TX_BCAST_PACKETS_GOOD_BAD; /*!< Tranmit Good and Bad
                                                          Packet Broadcast Count
                                                          Register, Address offset: 0x144 */
    uint32_t RESERVED_148[14];                       /*!< Reserved, Address offset: 0x148 */
    volatile uint32_t REG_RX_PACKETS_NUM_GOOD_BAD;   /*!< Receive Good and Bad Packet
                                                        Count Register, Address offset: 0x180 */
    uint32_t RESERVED_184[2];                        /*!< Reserved, Address offset: 0x184 */
    volatile uint32_t REG_RX_BCAST_PACKETS_GOOD;     /*!< Receive Good Packet Broadcast
                                                      Count Register, Address offset: 0x18C */
    volatile uint32_t REG_RX_MCAST_PACKETS_GOOD;     /*!< Receive Good Packet Multicast
                                                      Count Register, Address offset: 0x190 */
    volatile uint32_t REG_RX_CRC_ERROR_PACKETS;      /*!< Receive CRC Error Packet Count
                                                      Register, Address offset: 0x194 */
    uint32_t RESERVED_198[11];                       /*!< Reserved, Address offset: 0x198 */
    volatile uint32_t REG_RX_UCAST_PACKETS_GOOD;     /*!< Receive Good Packet Unicast
                                                      Count Register, Address offset: 0x1C4 */
    uint32_t RESERVED_1C8[915];                      /*!< Reserved, Address offset: 0x1C8 */
    volatile uint32_t REG_INT_STATUS;                /*!< Interrupt Status Register, Address offset: 0x1014 */
    uint32_t RESERVED_1018[1];                       /*!< Reserved, Address offset: 0x1018 */
    volatile uint32_t REG_INT_ENABLE;                /*!< Interrupt Enable Register, Address offset: 0x101C */
} GMAC_Type;

static_assert(offsetof(GMAC_Type, REG_MAC_CONFIG) == 0x000U);
static_assert(offsetof(GMAC_Type, REG_MDIO_ADDR) == 0x010U);
static_assert(offsetof(GMAC_Type, REG_MDIO_DATA) == 0x014U);
static_assert(offsetof(GMAC_Type, REG_MAC_ADDR0_HIGH) == 0x040U);
static_assert(offsetof(GMAC_Type, REG_MAC_ADDR0_LOW) == 0x044U);
static_assert(offsetof(GMAC_Type, REG_MAC_ADDR1_HIGH) == 0x048U);
static_assert(offsetof(GMAC_Type, REG_MAC_ADDR1_LOW) == 0x04CU);
static_assert(offsetof(GMAC_Type, REG_TX_PACKET_NUM_GOOD_BAD) == 0x118U);
static_assert(offsetof(GMAC_Type, REG_TX_BCAST_PACKETS_GOOD) == 0x11CU);
static_assert(offsetof(GMAC_Type, REG_TX_MCAST_PACKETS_GOOD) == 0x120U);
static_assert(offsetof(GMAC_Type, REG_TX_UCAST_PACKETS_GOOD_BAD) == 0x13CU);
static_assert(offsetof(GMAC_Type, REG_TX_MCAST_PACKETS_GOOD_BAD) == 0x140U);
static_assert(offsetof(GMAC_Type, REG_TX_BCAST_PACKETS_GOOD_BAD) == 0x144U);
static_assert(offsetof(GMAC_Type, REG_RX_PACKETS_NUM_GOOD_BAD) == 0x180U);
static_assert(offsetof(GMAC_Type, REG_RX_BCAST_PACKETS_GOOD) == 0x18CU);
static_assert(offsetof(GMAC_Type, REG_RX_MCAST_PACKETS_GOOD) == 0x190U);
static_assert(offsetof(GMAC_Type, REG_RX_CRC_ERROR_PACKETS) == 0x194U);
static_assert(offsetof(GMAC_Type, REG_RX_UCAST_PACKETS_GOOD) == 0x1C4U);
static_assert(offsetof(GMAC_Type, REG_INT_STATUS) == 0x1014U);
static_assert(offsetof(GMAC_Type, REG_INT_ENABLE) == 0x101CU);

/**
 * @brief ETH0_REGS register-instance pointer.
 */
#define ETH0_REGS ((GMAC_Type *)(uintptr_t)ETH0_BASE)

/**
 * @brief TEMPSEN register block.
 */
typedef struct
{
    volatile uint32_t TEMPSEN_VERSION;            /*!< ip version number, Address offset: 0x000 */
    volatile uint32_t TEMPSEN_CTRL;               /*!< control register, Address offset: 0x004 */
    volatile uint32_t TEMPSEN_STATUS;             /*!< staus register, Address offset: 0x008 */
    volatile uint32_t TEMPSEN_SET;                /*!< temperature sensor macro
                                                      setting, Address offset: 0x00C */
    volatile uint32_t TEMPSEN_INTR_EN;            /*!< interrupt enable, Address offset: 0x010 */
    volatile uint32_t TEMPSEN_INTR_CLR;           /*!< interrupt clear, Address offset: 0x014 */
    volatile uint32_t TEMPSEN_INTR_STA;           /*!< interupt status, Address offset: 0x018 */
    volatile uint32_t TEMPSEN_INTR_RAW;           /*!< interrupt raw status, Address offset: 0x01C */
    volatile uint32_t TEMPSEN_CH0_RESULT;         /*!< temperature sensor channel 0
                                                      result, Address offset: 0x020 */
    volatile uint32_t TEMPSEN_CH1_RESULT;         /*!< temperature sensor channel 1
                                                      result, Address offset: 0x024 */
    uint32_t RESERVED_028[6];                     /*!< Reserved, Address offset: 0x028 */
    volatile uint32_t TEMPSEN_CH0_TEMP_TH;        /*!< temperature sensor channel 0
                                                      threshold, Address offset: 0x040 */
    volatile uint32_t TEMPSEN_CH1_TEMP_TH;        /*!< temperature sensor channel 1
                                                      threshold, Address offset: 0x044 */
    uint32_t RESERVED_048[6];                     /*!< Reserved, Address offset: 0x048 */
    volatile uint32_t OVERHEAT_TH;                /*!< overheat threshold register, Address offset: 0x060 */
    volatile uint32_t TEMPSEN_AUTO_PERIOD;        /*!< auto sample setting register, Address offset: 0x064 */
    volatile uint32_t TEMPSEN_OVERHEAT_CTRL;      /*!< overheat control register, Address offset: 0x068 */
    volatile uint32_t TEMPSEN_OVERHEAT_COUNTDOWN; /*!< overheat status register, Address offset: 0x06C */
    volatile uint32_t TEMPSEN_CH0_TEMP_TH_CNT;    /*!< counter of channel 0
                                                      over/under threshold event, Address offset: 0x070 */
    volatile uint32_t TEMPSEN_CH1_TEMP_TH_CNT;    /*!< counter of channel 1
                                                      over/under threshold event, Address offset: 0x074 */
} TEMPSEN_Type;

static_assert(offsetof(TEMPSEN_Type, TEMPSEN_VERSION) == 0x000U);
static_assert(offsetof(TEMPSEN_Type, TEMPSEN_CTRL) == 0x004U);
static_assert(offsetof(TEMPSEN_Type, TEMPSEN_STATUS) == 0x008U);
static_assert(offsetof(TEMPSEN_Type, TEMPSEN_SET) == 0x00CU);
static_assert(offsetof(TEMPSEN_Type, TEMPSEN_INTR_EN) == 0x010U);
static_assert(offsetof(TEMPSEN_Type, TEMPSEN_INTR_CLR) == 0x014U);
static_assert(offsetof(TEMPSEN_Type, TEMPSEN_INTR_STA) == 0x018U);
static_assert(offsetof(TEMPSEN_Type, TEMPSEN_INTR_RAW) == 0x01CU);
static_assert(offsetof(TEMPSEN_Type, TEMPSEN_CH0_RESULT) == 0x020U);
static_assert(offsetof(TEMPSEN_Type, TEMPSEN_CH1_RESULT) == 0x024U);
static_assert(offsetof(TEMPSEN_Type, TEMPSEN_CH0_TEMP_TH) == 0x040U);
static_assert(offsetof(TEMPSEN_Type, TEMPSEN_CH1_TEMP_TH) == 0x044U);
static_assert(offsetof(TEMPSEN_Type, OVERHEAT_TH) == 0x060U);
static_assert(offsetof(TEMPSEN_Type, TEMPSEN_AUTO_PERIOD) == 0x064U);
static_assert(offsetof(TEMPSEN_Type, TEMPSEN_OVERHEAT_CTRL) == 0x068U);
static_assert(offsetof(TEMPSEN_Type, TEMPSEN_OVERHEAT_COUNTDOWN) == 0x06CU);
static_assert(offsetof(TEMPSEN_Type, TEMPSEN_CH0_TEMP_TH_CNT) == 0x070U);
static_assert(offsetof(TEMPSEN_Type, TEMPSEN_CH1_TEMP_TH_CNT) == 0x074U);

/**
 * @brief TEMPSEN_REGS register-instance pointer.
 */
#define TEMPSEN_REGS ((TEMPSEN_Type *)(uintptr_t)TEMPSEN_BASE)

/**
 * @brief SDMMC register block.
 */
typedef struct
{
    volatile uint32_t SDMA_SADDR;                 /*!< SDMA System Memory Address/
                                                      Argument2, Address offset: 0x000 */
    volatile uint32_t BLK_SIZE_AND_CNT;           /*!< Block Size and Block Count
                                                      Register, Address offset: 0x004 */
    volatile uint32_t ARGUMENT;                   /*!< Argument 1 Register, Address offset: 0x008 */
    volatile uint32_t XFER_MODE_AND_CMD;          /*!< Transfer Mode and Command
                                                      Register, Address offset: 0x00C */
    volatile uint32_t RESP31_0;                   /*!< Response Bit 31-0 Regsiter, Address offset: 0x010 */
    volatile uint32_t RESP63_32;                  /*!< Response Bit 63-32 Regsiter, Address offset: 0x014 */
    volatile uint32_t RESP95_64;                  /*!< Response Bit 95-64 Regsiter, Address offset: 0x018 */
    volatile uint32_t RESP127_96;                 /*!< Response Bit 127-96 Regsiter, Address offset: 0x01C */
    volatile uint32_t BUF_DATA;                   /*!< Buffer Data Port Register, Address offset: 0x020 */
    volatile uint32_t PRESENT_STS;                /*!< Present State Register, Address offset: 0x024 */
    volatile uint32_t HOST_CTL1_PWR_BG_WUP;       /*!< Host Control 1 , Power, Block
                                                      Gap and Wakeup Register, Address offset: 0x028 */
    volatile uint32_t CLK_CTL_SWRST;              /*!< Clock and Reset Control
                                                      Register, Address offset: 0x02C */
    volatile uint32_t NORM_AND_ERR_INT_STS;       /*!< Normal and Error Interrupt
                                                      Status Register, Address offset: 0x030 */
    volatile uint32_t NORM_AND_ERR_INT_STS_EN;    /*!< Normal and Error Interrupt
                                                      Status Enable Register, Address offset: 0x034 */
    volatile uint32_t NORM_AND_ERR_INT_SIG_EN;    /*!< Normal and Error Interrupt
                                                      Signal Enable Register, Address offset: 0x038 */
    volatile uint32_t AUTO_CMD_ERR_AND_HOST_CTL2; /*!< Auto CMD Error Status
                                                       Register and Host Control 2
                                                       register, Address offset: 0x03C */
    volatile uint32_t CAPABILITIES1;              /*!< Capabilities 1 Register, Address offset: 0x040 */
    volatile uint32_t CAPABILITIES2;              /*!< Capabilities 2 Register, Address offset: 0x044 */
    uint32_t RESERVED_048[2];                     /*!< Reserved, Address offset: 0x048 */
    volatile uint32_t FORCE_EVENT_ERR;            /*!< Force Event Register for Auto
                                                      CMD Error Status, Address offset: 0x050 */
    volatile uint32_t ADMA_ERR_STS;               /*!< ADMA Error Status Register, Address offset: 0x054 */
    volatile uint32_t ADMA_SADDR_L;               /*!< ADMA System Address Register
                                                      for low 32-bit, Address offset: 0x058 */
    volatile uint32_t ADMA_SADDR_H;               /*!< ADMA System Address Register
                                                      for high 32-bit, Address offset: 0x05C */
    volatile uint32_t PRESENT_VUL_INIT_DS;        /*!< Present Value Register for
                                                      Initialization and Default
                                                      Speed, Address offset: 0x060 */
    volatile uint32_t PRESENT_VUL_HS_SDR12;       /*!< Present Value Register for
                                                      High-speed and SDR12, Address offset: 0x064 */
    volatile uint32_t PRESENT_VUL_SDR25_SDR50;    /*!< Present Value Register for
                                                      SDR25 and SDR50, Address offset: 0x068 */
    volatile uint32_t PRESENT_VUL_SDR104_DDR50;   /*!< Present Value Register for
                                                      SDR104 and DDR50, Address offset: 0x06C */
    uint32_t RESERVED_070[35];                    /*!< Reserved, Address offset: 0x070 */
    volatile uint32_t SLOT_INT_AND_HOST_VER;      /*!< Slot Interrupt Status and Host
                                                      Controller Version Register, Address offset: 0x0FC */
    uint32_t RESERVED_100[64];                    /*!< Reserved, Address offset: 0x100 */
    volatile uint32_t EMMC_CTRL;                  /*!< MSHC Control register, Address offset: 0x200 */
    volatile uint32_t EMMC_BOOT_CTL;              /*!< eMMC Boot Control Register, Address offset: 0x204 */
    volatile uint32_t CDET_TOUT_CTL;              /*!< Card Detect Control Register, Address offset: 0x208 */
    volatile uint32_t MBIU_CTRL;                  /*!< MBIU Control register, Address offset: 0x20C */
    uint32_t RESERVED_210[12];                    /*!< Reserved, Address offset: 0x210 */
    volatile uint32_t PHY_TX_RX_DLY;              /*!< PHY tx and rx delay line
                                                      register, Address offset: 0x240 */
    volatile uint32_t PHY_DS_DLY;                 /*!< PHY DS delay line register, Address offset: 0x244 */
    volatile uint32_t PHY_DLY_STS; /*!< PHY delay line status register, Address offset: 0x248 */
    volatile uint32_t PHY_CONFIG;  /*!< PHY Configuration register, Address offset: 0x24C */
} SDMMC_Type;

static_assert(offsetof(SDMMC_Type, SDMA_SADDR) == 0x000U);
static_assert(offsetof(SDMMC_Type, BLK_SIZE_AND_CNT) == 0x004U);
static_assert(offsetof(SDMMC_Type, ARGUMENT) == 0x008U);
static_assert(offsetof(SDMMC_Type, XFER_MODE_AND_CMD) == 0x00CU);
static_assert(offsetof(SDMMC_Type, RESP31_0) == 0x010U);
static_assert(offsetof(SDMMC_Type, RESP63_32) == 0x014U);
static_assert(offsetof(SDMMC_Type, RESP95_64) == 0x018U);
static_assert(offsetof(SDMMC_Type, RESP127_96) == 0x01CU);
static_assert(offsetof(SDMMC_Type, BUF_DATA) == 0x020U);
static_assert(offsetof(SDMMC_Type, PRESENT_STS) == 0x024U);
static_assert(offsetof(SDMMC_Type, HOST_CTL1_PWR_BG_WUP) == 0x028U);
static_assert(offsetof(SDMMC_Type, CLK_CTL_SWRST) == 0x02CU);
static_assert(offsetof(SDMMC_Type, NORM_AND_ERR_INT_STS) == 0x030U);
static_assert(offsetof(SDMMC_Type, NORM_AND_ERR_INT_STS_EN) == 0x034U);
static_assert(offsetof(SDMMC_Type, NORM_AND_ERR_INT_SIG_EN) == 0x038U);
static_assert(offsetof(SDMMC_Type, AUTO_CMD_ERR_AND_HOST_CTL2) == 0x03CU);
static_assert(offsetof(SDMMC_Type, CAPABILITIES1) == 0x040U);
static_assert(offsetof(SDMMC_Type, CAPABILITIES2) == 0x044U);
static_assert(offsetof(SDMMC_Type, FORCE_EVENT_ERR) == 0x050U);
static_assert(offsetof(SDMMC_Type, ADMA_ERR_STS) == 0x054U);
static_assert(offsetof(SDMMC_Type, ADMA_SADDR_L) == 0x058U);
static_assert(offsetof(SDMMC_Type, ADMA_SADDR_H) == 0x05CU);
static_assert(offsetof(SDMMC_Type, PRESENT_VUL_INIT_DS) == 0x060U);
static_assert(offsetof(SDMMC_Type, PRESENT_VUL_HS_SDR12) == 0x064U);
static_assert(offsetof(SDMMC_Type, PRESENT_VUL_SDR25_SDR50) == 0x068U);
static_assert(offsetof(SDMMC_Type, PRESENT_VUL_SDR104_DDR50) == 0x06CU);
static_assert(offsetof(SDMMC_Type, SLOT_INT_AND_HOST_VER) == 0x0FCU);
static_assert(offsetof(SDMMC_Type, EMMC_CTRL) == 0x200U);
static_assert(offsetof(SDMMC_Type, EMMC_BOOT_CTL) == 0x204U);
static_assert(offsetof(SDMMC_Type, CDET_TOUT_CTL) == 0x208U);
static_assert(offsetof(SDMMC_Type, MBIU_CTRL) == 0x20CU);
static_assert(offsetof(SDMMC_Type, PHY_TX_RX_DLY) == 0x240U);
static_assert(offsetof(SDMMC_Type, PHY_DS_DLY) == 0x244U);
static_assert(offsetof(SDMMC_Type, PHY_DLY_STS) == 0x248U);
static_assert(offsetof(SDMMC_Type, PHY_CONFIG) == 0x24CU);

/**
 * @brief EMMC_REGS register-instance pointer.
 */
#define EMMC_REGS ((SDMMC_Type *)(uintptr_t)EMMC_BASE)

/**
 * @brief SD0_REGS register-instance pointer.
 */
#define SD0_REGS ((SDMMC_Type *)(uintptr_t)SD0_BASE)

/**
 * @brief SD1_REGS register-instance pointer.
 */
#define SD1_REGS ((SDMMC_Type *)(uintptr_t)SD1_BASE)

/**
 * @brief USB core register block.
 */
typedef struct
{
    volatile uint32_t GOTGCTL; /*!< Control and Status Register, Address offset: 0x000 */
    volatile uint32_t GOTGINT; /*!< Interrupt Register, Address offset: 0x004 */
    volatile uint32_t GAHBCFG; /*!< AHB Configuration Register, Address offset: 0x008 */
    volatile uint32_t GUSBCFG; /*!< USB Configuration Register, Address offset: 0x00C */
    volatile uint32_t GRSTCTL; /*!< Reset Register, Address offset: 0x010 */
    volatile uint32_t GINTSTS; /*!< Interrupt Status Register, Address offset: 0x014 */
    volatile uint32_t GINTMSK; /*!< Interrupt Mask Register, Address offset: 0x018 */
    uint32_t RESERVED_01C[8];  /*!< Reserved, Address offset: 0x01C */
    volatile uint32_t GUID;    /*!< User ID Register, Address offset: 0x03C */
    uint32_t RESERVED_040[5];  /*!< Reserved, Address offset: 0x040 */
    volatile uint32_t GLPMCFG; /*!< Core LPM Configuration Register, Address offset: 0x054 */
    volatile uint32_t GPWRDN;  /*!< Power Down Register, Address offset: 0x058 */
} USB_Type;

static_assert(offsetof(USB_Type, GOTGCTL) == 0x000U);
static_assert(offsetof(USB_Type, GOTGINT) == 0x004U);
static_assert(offsetof(USB_Type, GAHBCFG) == 0x008U);
static_assert(offsetof(USB_Type, GUSBCFG) == 0x00CU);
static_assert(offsetof(USB_Type, GRSTCTL) == 0x010U);
static_assert(offsetof(USB_Type, GINTSTS) == 0x014U);
static_assert(offsetof(USB_Type, GINTMSK) == 0x018U);
static_assert(offsetof(USB_Type, GUID) == 0x03CU);
static_assert(offsetof(USB_Type, GLPMCFG) == 0x054U);
static_assert(offsetof(USB_Type, GPWRDN) == 0x058U);

/**
 * @brief USB_REGS register-instance pointer.
 */
#define USB_REGS ((USB_Type *)(uintptr_t)USB_BASE)

/**
 * @brief USB host register block.
 */
typedef struct
{
    uint32_t RESERVED_000[256]; /*!< Reserved, Address offset: 0x000 */
    volatile uint32_t HCFG;     /*!< Host Configuration Register, Address offset: 0x400 */
    volatile uint32_t HFIR;     /*!< Host Frame Interval Register, Address offset: 0x404 */
    volatile uint32_t HFNUM;    /*!< Host Frame Number/Frame Time Remaining Register, Address offset: 0x408 */
    uint32_t RESERVED_40C[1];   /*!< Reserved, Address offset: 0x40C */
    volatile uint32_t HPTXSTS;  /*!< Host Periodic Transmit FIFO/Queue Status
                                     Register, Address offset: 0x410 */
    volatile uint32_t HAINT;    /*!< Host All Channels Interrupt Register, Address offset: 0x414 */
    volatile uint32_t HAINTMSK; /*!< Host All Channels Interrupt Mask Register, Address offset: 0x418 */
    volatile uint32_t HFLB_ADDR; /*!< Host Frame List Base Address Register, Address offset: 0x41C */
    uint32_t RESERVED_420[56];   /*!< Reserved, Address offset: 0x420 */
    volatile uint32_t HCCHA_RN;  /*!< Host Channel-n Characteristics Register, Address offset: 0x500 */
    uint32_t RESERVED_504[4];    /*!< Reserved, Address offset: 0x504 */
    volatile uint32_t HCDM_AN;   /*!< Host Channel-n DMA Address Register, Address offset: 0x514 */
    uint32_t RESERVED_518[1];    /*!< Reserved, Address offset: 0x518 */
    volatile uint32_t HCDMA_BN;  /*!< Host Channel-n DMA Buffer Address Register, Address offset: 0x51C */
} USB_HOST_Type;

static_assert(offsetof(USB_HOST_Type, HCFG) == 0x400U);
static_assert(offsetof(USB_HOST_Type, HFIR) == 0x404U);
static_assert(offsetof(USB_HOST_Type, HFNUM) == 0x408U);
static_assert(offsetof(USB_HOST_Type, HPTXSTS) == 0x410U);
static_assert(offsetof(USB_HOST_Type, HAINT) == 0x414U);
static_assert(offsetof(USB_HOST_Type, HAINTMSK) == 0x418U);
static_assert(offsetof(USB_HOST_Type, HFLB_ADDR) == 0x41CU);
static_assert(offsetof(USB_HOST_Type, HCCHA_RN) == 0x500U);
static_assert(offsetof(USB_HOST_Type, HCDM_AN) == 0x514U);
static_assert(offsetof(USB_HOST_Type, HCDMA_BN) == 0x51CU);

/**
 * @brief USB_HOST_REGS register-instance pointer.
 */
#define USB_HOST_REGS ((USB_HOST_Type *)(uintptr_t)(USB_BASE + 0x400UL))

/**
 * @brief USB device register block.
 */
typedef struct
{
    uint32_t RESERVED_000[512];    /*!< Reserved, Address offset: 0x000 */
    volatile uint32_t DCFG;        /*!< Device Configuration Register, Address offset: 0x800 */
    volatile uint32_t DCTL;        /*!< Device Control Register, Address offset: 0x804 */
    volatile uint32_t DSTS;        /*!< Device Status Register, Address offset: 0x808 */
    uint32_t RESERVED_80C[1];      /*!< Reserved, Address offset: 0x80C */
    volatile uint32_t DIEPMSK;     /*!< Device IN Endpoint Common Interrupt Mask
                                       Register, Address offset: 0x810 */
    volatile uint32_t DOEPMSK;     /*!< Device OUT Endpoint Common Interrupt Mask
                                       Register, Address offset: 0x814 */
    volatile uint32_t DAINT;       /*!< Device All Endpoints Interrupt Register, Address offset: 0x818 */
    volatile uint32_t DAINTMSK;    /*!< Device Endpoints Interrupt Mask Register, Address offset: 0x81C */
    uint32_t RESERVED_820[5];      /*!< Reserved, Address offset: 0x820 */
    volatile uint32_t DIEPEMPMSK;  /*!< Device IN Endpoint FIFO Empty Interrupt Mask
                                       Register, Address offset: 0x834 */
    volatile uint32_t DEACHINT;    /*!< Device Each Endpoint Interrupt Register, Address offset: 0x838 */
    volatile uint32_t DEACHINTMSK; /*!< Device Each Endpoint Interrupt Register Mask, Address offset: 0x83C */
} USB_DEVICE_Type;

static_assert(offsetof(USB_DEVICE_Type, DCFG) == 0x800U);
static_assert(offsetof(USB_DEVICE_Type, DCTL) == 0x804U);
static_assert(offsetof(USB_DEVICE_Type, DSTS) == 0x808U);
static_assert(offsetof(USB_DEVICE_Type, DIEPMSK) == 0x810U);
static_assert(offsetof(USB_DEVICE_Type, DOEPMSK) == 0x814U);
static_assert(offsetof(USB_DEVICE_Type, DAINT) == 0x818U);
static_assert(offsetof(USB_DEVICE_Type, DAINTMSK) == 0x81CU);
static_assert(offsetof(USB_DEVICE_Type, DIEPEMPMSK) == 0x834U);
static_assert(offsetof(USB_DEVICE_Type, DEACHINT) == 0x838U);
static_assert(offsetof(USB_DEVICE_Type, DEACHINTMSK) == 0x83CU);

/**
 * @brief USB_DEVICE_REGS register-instance pointer.
 */
#define USB_DEVICE_REGS ((USB_DEVICE_Type *)(uintptr_t)(USB_BASE + 0x800UL))

/**
 * @brief CryptoDMA register block.
 */
typedef struct
{
    volatile uint32_t DMA_CTRL;         /*!< DMA controll register, Address offset: 0x000 */
    volatile uint32_t INT_MASK;         /*!< interrupt mask, Address offset: 0x004 */
    volatile uint32_t DES_BASE_0;       /*!< descriptor base low address, Address offset: 0x008 */
    volatile uint32_t DES_BASE_1;       /*!< descriptor base high address, Address offset: 0x00C */
    volatile uint32_t SPACC_INT_RAW;    /*!< interrupt, Address offset: 0x010 */
    volatile uint32_t SECURE_KEY_VALID; /*!< key valid, Address offset: 0x014 */
    volatile uint32_t DES_ADDR_0;       /*!< current descirptor low address, Address offset: 0x018 */
    volatile uint32_t DES_ADDR_1;       /*!< current descirptor high address, Address offset: 0x01C */
    uint32_t RESERVED_020[24];          /*!< Reserved, Address offset: 0x020 */
    volatile uint32_t PIO_CMD_DATA_0;   /*!< PIO command0, Address offset: 0x080 */
    volatile uint32_t PIO_CMD_DATA_1;   /*!< PIO command1, Address offset: 0x084 */
    volatile uint32_t PIO_CMD_DATA_2;   /*!< PIO command2, Address offset: 0x088 */
    volatile uint32_t PIO_CMD_DATA_3;   /*!< PIO command3, Address offset: 0x08C */
    volatile uint32_t PIO_CMD_DATA_4;   /*!< PIO command4, Address offset: 0x090 */
    volatile uint32_t PIO_CMD_DATA_5;   /*!< PIO command5, Address offset: 0x094 */
    volatile uint32_t PIO_CMD_DATA_6;   /*!< PIO command6, Address offset: 0x098 */
    volatile uint32_t PIO_CMD_DATA_7;   /*!< PIO command7, Address offset: 0x09C */
    volatile uint32_t PIO_CMD_DATA_8;   /*!< PIO command8, Address offset: 0x0A0 */
    volatile uint32_t PIO_CMD_DATA_9;   /*!< PIO command9, Address offset: 0x0A4 */
    volatile uint32_t PIO_CMD_DATA_10;  /*!< PIO command10, Address offset: 0x0A8 */
    volatile uint32_t PIO_CMD_DATA_11;  /*!< PIO command11, Address offset: 0x0AC */
    volatile uint32_t PIO_CMD_DATA_12;  /*!< PIO command12, Address offset: 0x0B0 */
    volatile uint32_t PIO_CMD_DATA_13;  /*!< PIO command13, Address offset: 0x0B4 */
    volatile uint32_t PIO_CMD_DATA_14;  /*!< PIO command14, Address offset: 0x0B8 */
    volatile uint32_t PIO_CMD_DATA_15;  /*!< PIO command15, Address offset: 0x0BC */
    volatile uint32_t PIO_CMD_DATA_16;  /*!< PIO command16, Address offset: 0x0C0 */
    volatile uint32_t PIO_CMD_DATA_17;  /*!< PIO command17, Address offset: 0x0C4 */
    volatile uint32_t PIO_CMD_DATA_18;  /*!< PIO command18, Address offset: 0x0C8 */
    volatile uint32_t PIO_CMD_DATA_19;  /*!< PIO command19, Address offset: 0x0CC */
    volatile uint32_t PIO_CMD_DATA_20;  /*!< PIO command20, Address offset: 0x0D0 */
    volatile uint32_t PIO_CMD_DATA_21;  /*!< PIO command21, Address offset: 0x0D4 */
    uint32_t RESERVED_0D8[10];          /*!< Reserved, Address offset: 0x0D8 */
    volatile uint32_t KEY_DATA_0;       /*!< cipher key data 0, Address offset: 0x100 */
    volatile uint32_t KEY_DATA_1;       /*!< cipher key data 1, Address offset: 0x104 */
    volatile uint32_t KEY_DATA_2;       /*!< cipher key data 2, Address offset: 0x108 */
    volatile uint32_t KEY_DATA_3;       /*!< cipher key data 3, Address offset: 0x10C */
    volatile uint32_t KEY_DATA_4;       /*!< cipher key data 4, Address offset: 0x110 */
    volatile uint32_t KEY_DATA_5;       /*!< cipher key data 5, Address offset: 0x114 */
    volatile uint32_t KEY_DATA_6;       /*!< cipher key data 6, Address offset: 0x118 */
    volatile uint32_t KEY_DATA_7;       /*!< cipher key data 7, Address offset: 0x11C */
    volatile uint32_t KEY_DATA_8;       /*!< cipher key data 8, Address offset: 0x120 */
    volatile uint32_t KEY_DATA_9;       /*!< cipher key data 9, Address offset: 0x124 */
    volatile uint32_t KEY_DATA_10;      /*!< cipher key data 10, Address offset: 0x128 */
    volatile uint32_t KEY_DATA_11;      /*!< cipher key data 11, Address offset: 0x12C */
    volatile uint32_t KEY_DATA_12;      /*!< cipher key data 12, Address offset: 0x130 */
    volatile uint32_t KEY_DATA_13;      /*!< cipher key data 13, Address offset: 0x134 */
    volatile uint32_t KEY_DATA_14;      /*!< cipher key data 14, Address offset: 0x138 */
    volatile uint32_t KEY_DATA_15;      /*!< cipher key data 15, Address offset: 0x13C */
    volatile uint32_t KEY_DATA_16;      /*!< cipher key data 16, Address offset: 0x140 */
    volatile uint32_t KEY_DATA_17;      /*!< cipher key data 17, Address offset: 0x144 */
    volatile uint32_t KEY_DATA_18;      /*!< cipher key data 18, Address offset: 0x148 */
    volatile uint32_t KEY_DATA_19;      /*!< cipher key data 19, Address offset: 0x14C */
    volatile uint32_t KEY_DATA_20;      /*!< cipher key data 20, Address offset: 0x150 */
    volatile uint32_t KEY_DATA_21;      /*!< cipher key data 21, Address offset: 0x154 */
    volatile uint32_t KEY_DATA_22;      /*!< cipher key data 22, Address offset: 0x158 */
    volatile uint32_t KEY_DATA_23;      /*!< cipher key data 23, Address offset: 0x15C */
    uint32_t RESERVED_160[8];           /*!< Reserved, Address offset: 0x160 */
    volatile uint32_t INI_DATA_0;       /*!< initial vector data 0, Address offset: 0x180 */
    volatile uint32_t INI_DATA_1;       /*!< initial vector data 1, Address offset: 0x184 */
    volatile uint32_t INI_DATA_2;       /*!< initial vector data 2, Address offset: 0x188 */
    volatile uint32_t INI_DATA_3;       /*!< initial vector data 3, Address offset: 0x18C */
    volatile uint32_t INI_DATA_4;       /*!< initial vector data 4, Address offset: 0x190 */
    volatile uint32_t INI_DATA_5;       /*!< initial vector data 5, Address offset: 0x194 */
    volatile uint32_t INI_DATA_6;       /*!< initial vector data 6, Address offset: 0x198 */
    volatile uint32_t INI_DATA_7;       /*!< initial vector data 7, Address offset: 0x19C */
    volatile uint32_t INI_DATA_8;       /*!< initial vector data 8, Address offset: 0x1A0 */
    volatile uint32_t INI_DATA_9;       /*!< initial vector data 9, Address offset: 0x1A4 */
    volatile uint32_t INI_DATA_10;      /*!< initial vector data 10, Address offset: 0x1A8 */
    volatile uint32_t INI_DATA_11;      /*!< initial vector data 11, Address offset: 0x1AC */
    uint32_t RESERVED_1B0[4];           /*!< Reserved, Address offset: 0x1B0 */
    volatile uint32_t SHA_DATA_0;       /*!< SHA paramenter0, Address offset: 0x1C0 */
    volatile uint32_t SHA_DATA_1;       /*!< SHA paramenter1, Address offset: 0x1C4 */
    volatile uint32_t SHA_DATA_2;       /*!< SHA paramenter2, Address offset: 0x1C8 */
    volatile uint32_t SHA_DATA_3;       /*!< SHA paramenter3, Address offset: 0x1CC */
    volatile uint32_t SHA_DATA_4;       /*!< SHA paramenter4, Address offset: 0x1D0 */
    volatile uint32_t SHA_DATA_5;       /*!< SHA paramenter5, Address offset: 0x1D4 */
    volatile uint32_t SHA_DATA_6;       /*!< SHA paramenter6, Address offset: 0x1D8 */
    volatile uint32_t SHA_DATA_7;       /*!< SHA paramenter7, Address offset: 0x1DC */
} CRYPTO_DMA_Type;

static_assert(offsetof(CRYPTO_DMA_Type, DMA_CTRL) == 0x000U);
static_assert(offsetof(CRYPTO_DMA_Type, INT_MASK) == 0x004U);
static_assert(offsetof(CRYPTO_DMA_Type, DES_BASE_0) == 0x008U);
static_assert(offsetof(CRYPTO_DMA_Type, DES_BASE_1) == 0x00CU);
static_assert(offsetof(CRYPTO_DMA_Type, SPACC_INT_RAW) == 0x010U);
static_assert(offsetof(CRYPTO_DMA_Type, SECURE_KEY_VALID) == 0x014U);
static_assert(offsetof(CRYPTO_DMA_Type, DES_ADDR_0) == 0x018U);
static_assert(offsetof(CRYPTO_DMA_Type, DES_ADDR_1) == 0x01CU);
static_assert(offsetof(CRYPTO_DMA_Type, PIO_CMD_DATA_0) == 0x080U);
static_assert(offsetof(CRYPTO_DMA_Type, PIO_CMD_DATA_1) == 0x084U);
static_assert(offsetof(CRYPTO_DMA_Type, PIO_CMD_DATA_2) == 0x088U);
static_assert(offsetof(CRYPTO_DMA_Type, PIO_CMD_DATA_3) == 0x08CU);
static_assert(offsetof(CRYPTO_DMA_Type, PIO_CMD_DATA_4) == 0x090U);
static_assert(offsetof(CRYPTO_DMA_Type, PIO_CMD_DATA_5) == 0x094U);
static_assert(offsetof(CRYPTO_DMA_Type, PIO_CMD_DATA_6) == 0x098U);
static_assert(offsetof(CRYPTO_DMA_Type, PIO_CMD_DATA_7) == 0x09CU);
static_assert(offsetof(CRYPTO_DMA_Type, PIO_CMD_DATA_8) == 0x0A0U);
static_assert(offsetof(CRYPTO_DMA_Type, PIO_CMD_DATA_9) == 0x0A4U);
static_assert(offsetof(CRYPTO_DMA_Type, PIO_CMD_DATA_10) == 0x0A8U);
static_assert(offsetof(CRYPTO_DMA_Type, PIO_CMD_DATA_11) == 0x0ACU);
static_assert(offsetof(CRYPTO_DMA_Type, PIO_CMD_DATA_12) == 0x0B0U);
static_assert(offsetof(CRYPTO_DMA_Type, PIO_CMD_DATA_13) == 0x0B4U);
static_assert(offsetof(CRYPTO_DMA_Type, PIO_CMD_DATA_14) == 0x0B8U);
static_assert(offsetof(CRYPTO_DMA_Type, PIO_CMD_DATA_15) == 0x0BCU);
static_assert(offsetof(CRYPTO_DMA_Type, PIO_CMD_DATA_16) == 0x0C0U);
static_assert(offsetof(CRYPTO_DMA_Type, PIO_CMD_DATA_17) == 0x0C4U);
static_assert(offsetof(CRYPTO_DMA_Type, PIO_CMD_DATA_18) == 0x0C8U);
static_assert(offsetof(CRYPTO_DMA_Type, PIO_CMD_DATA_19) == 0x0CCU);
static_assert(offsetof(CRYPTO_DMA_Type, PIO_CMD_DATA_20) == 0x0D0U);
static_assert(offsetof(CRYPTO_DMA_Type, PIO_CMD_DATA_21) == 0x0D4U);
static_assert(offsetof(CRYPTO_DMA_Type, KEY_DATA_0) == 0x100U);
static_assert(offsetof(CRYPTO_DMA_Type, KEY_DATA_1) == 0x104U);
static_assert(offsetof(CRYPTO_DMA_Type, KEY_DATA_2) == 0x108U);
static_assert(offsetof(CRYPTO_DMA_Type, KEY_DATA_3) == 0x10CU);
static_assert(offsetof(CRYPTO_DMA_Type, KEY_DATA_4) == 0x110U);
static_assert(offsetof(CRYPTO_DMA_Type, KEY_DATA_5) == 0x114U);
static_assert(offsetof(CRYPTO_DMA_Type, KEY_DATA_6) == 0x118U);
static_assert(offsetof(CRYPTO_DMA_Type, KEY_DATA_7) == 0x11CU);
static_assert(offsetof(CRYPTO_DMA_Type, KEY_DATA_8) == 0x120U);
static_assert(offsetof(CRYPTO_DMA_Type, KEY_DATA_9) == 0x124U);
static_assert(offsetof(CRYPTO_DMA_Type, KEY_DATA_10) == 0x128U);
static_assert(offsetof(CRYPTO_DMA_Type, KEY_DATA_11) == 0x12CU);
static_assert(offsetof(CRYPTO_DMA_Type, KEY_DATA_12) == 0x130U);
static_assert(offsetof(CRYPTO_DMA_Type, KEY_DATA_13) == 0x134U);
static_assert(offsetof(CRYPTO_DMA_Type, KEY_DATA_14) == 0x138U);
static_assert(offsetof(CRYPTO_DMA_Type, KEY_DATA_15) == 0x13CU);
static_assert(offsetof(CRYPTO_DMA_Type, KEY_DATA_16) == 0x140U);
static_assert(offsetof(CRYPTO_DMA_Type, KEY_DATA_17) == 0x144U);
static_assert(offsetof(CRYPTO_DMA_Type, KEY_DATA_18) == 0x148U);
static_assert(offsetof(CRYPTO_DMA_Type, KEY_DATA_19) == 0x14CU);
static_assert(offsetof(CRYPTO_DMA_Type, KEY_DATA_20) == 0x150U);
static_assert(offsetof(CRYPTO_DMA_Type, KEY_DATA_21) == 0x154U);
static_assert(offsetof(CRYPTO_DMA_Type, KEY_DATA_22) == 0x158U);
static_assert(offsetof(CRYPTO_DMA_Type, KEY_DATA_23) == 0x15CU);
static_assert(offsetof(CRYPTO_DMA_Type, INI_DATA_0) == 0x180U);
static_assert(offsetof(CRYPTO_DMA_Type, INI_DATA_1) == 0x184U);
static_assert(offsetof(CRYPTO_DMA_Type, INI_DATA_2) == 0x188U);
static_assert(offsetof(CRYPTO_DMA_Type, INI_DATA_3) == 0x18CU);
static_assert(offsetof(CRYPTO_DMA_Type, INI_DATA_4) == 0x190U);
static_assert(offsetof(CRYPTO_DMA_Type, INI_DATA_5) == 0x194U);
static_assert(offsetof(CRYPTO_DMA_Type, INI_DATA_6) == 0x198U);
static_assert(offsetof(CRYPTO_DMA_Type, INI_DATA_7) == 0x19CU);
static_assert(offsetof(CRYPTO_DMA_Type, INI_DATA_8) == 0x1A0U);
static_assert(offsetof(CRYPTO_DMA_Type, INI_DATA_9) == 0x1A4U);
static_assert(offsetof(CRYPTO_DMA_Type, INI_DATA_10) == 0x1A8U);
static_assert(offsetof(CRYPTO_DMA_Type, INI_DATA_11) == 0x1ACU);
static_assert(offsetof(CRYPTO_DMA_Type, SHA_DATA_0) == 0x1C0U);
static_assert(offsetof(CRYPTO_DMA_Type, SHA_DATA_1) == 0x1C4U);
static_assert(offsetof(CRYPTO_DMA_Type, SHA_DATA_2) == 0x1C8U);
static_assert(offsetof(CRYPTO_DMA_Type, SHA_DATA_3) == 0x1CCU);
static_assert(offsetof(CRYPTO_DMA_Type, SHA_DATA_4) == 0x1D0U);
static_assert(offsetof(CRYPTO_DMA_Type, SHA_DATA_5) == 0x1D4U);
static_assert(offsetof(CRYPTO_DMA_Type, SHA_DATA_6) == 0x1D8U);
static_assert(offsetof(CRYPTO_DMA_Type, SHA_DATA_7) == 0x1DCU);

/**
 * @brief CRYPTO_DMA_REGS register-instance pointer.
 */
#define CRYPTO_DMA_REGS ((CRYPTO_DMA_Type *)(uintptr_t)CRYPTO_DMA_BASE)

/**
 * @brief I2S global (AIAO) register block.
 */
typedef struct
{
    volatile uint32_t I2S_TDM_SCLK_IN_SEL; /*!< Select the Source of the Mode TX/RX
                                                Module SCLK Source, Address offset: 0x000 */
    volatile uint32_t I2S_TDM_FS_IN_SEL;   /*!< Select the Synchronous signal Source
                                               of the Mode TX/RX Module, Address offset: 0x004 */
    volatile uint32_t I2S_TDM_SDI_IN_SEL;  /*!< Select the RX module SDI signal
                                               source, Address offset: 0x008 */
    volatile uint32_t I2S_TDM_SDO_OUT_SEL; /*!< Select the subsystem SDO output
                                                source, Address offset: 0x00C */
    uint32_t RESERVED_010[8];              /*!< Reserved, Address offset: 0x010 */
    volatile uint32_t I2S_BCLK_OEN_SEL;    /*!< BCLK IO output control, Address offset: 0x030 */
    uint32_t RESERVED_034[3];              /*!< Reserved, Address offset: 0x034 */
    volatile uint32_t AUDIO_PDM_CTRL;      /*!< Enable PDM mode, Address offset: 0x040 */
    uint32_t RESERVED_044[7];              /*!< Reserved, Address offset: 0x044 */
    volatile uint32_t I2S_SYS_INT_EN;      /*!< Enable the I2S subsystem interrupt
                                               signal, Address offset: 0x060 */
    volatile uint32_t I2S_SYS_INTS;        /*!< I2S subsystem interrupt signal status
                                               The I2S_TDM_0 ~ I2S_TDM_3 module
                                               register overview is shown in the
                                               table I2S_TDM_0/1/2/3 Registers
                                               Overview (Base Address: 0x0410_0000 +
                                               n*0x10000), Address offset: 0x064 */
} I2S_GLOBAL_Type;

static_assert(offsetof(I2S_GLOBAL_Type, I2S_TDM_SCLK_IN_SEL) == 0x000U);
static_assert(offsetof(I2S_GLOBAL_Type, I2S_TDM_FS_IN_SEL) == 0x004U);
static_assert(offsetof(I2S_GLOBAL_Type, I2S_TDM_SDI_IN_SEL) == 0x008U);
static_assert(offsetof(I2S_GLOBAL_Type, I2S_TDM_SDO_OUT_SEL) == 0x00CU);
static_assert(offsetof(I2S_GLOBAL_Type, I2S_BCLK_OEN_SEL) == 0x030U);
static_assert(offsetof(I2S_GLOBAL_Type, AUDIO_PDM_CTRL) == 0x040U);
static_assert(offsetof(I2S_GLOBAL_Type, I2S_SYS_INT_EN) == 0x060U);
static_assert(offsetof(I2S_GLOBAL_Type, I2S_SYS_INTS) == 0x064U);

/**
 * @brief I2S_GLOBAL_REGS register-instance pointer.
 */
#define I2S_GLOBAL_REGS ((I2S_GLOBAL_Type *)(uintptr_t)I2S_GLOBAL_BASE)

/**
 * @brief I2S/TDM register block.
 */
typedef struct
{
    volatile uint32_t BLK_MODE_SETTING; /*!< TX/RX module operation control, Address offset: 0x000 */
    volatile uint32_t FRAME_SETTING;    /*!< Audio frame timing control, Address offset: 0x004 */
    volatile uint32_t SLOT_SETTING1;    /*!< Classic and Data Control, Address offset: 0x008 */
    volatile uint32_t SLOT_SETTING2;    /*!< Enable channels, Address offset: 0x00C */
    volatile uint32_t DATA_FORMAT;      /*!< Set the storage data format, Address offset: 0x010 */
    volatile uint32_t BLK_CFG;          /*!< TX/RX module function configuration, Address offset: 0x014 */
    volatile uint32_t I2_S_ENABLE;      /*!< Enable TX/RX module, Address offset: 0x018 */
    volatile uint32_t I2_S_RESET;       /*!< TX/RX module reset, Address offset: 0x01C */
    volatile uint32_t I2_S_INT_EN;      /*!< Enable interruption, Address offset: 0x020 */
    volatile uint32_t I2_S_INT;         /*!< Interrupt status, Address offset: 0x024 */
    volatile uint32_t FIFO_THRESHOLD;   /*!< FIFO threshold, Address offset: 0x028 */
    volatile uint32_t I2_S_LRCK_MASTER; /*!< Make the main mode of LRCK continuous
                                             output mode, Address offset: 0x02C */
    volatile uint32_t FIFO_RESET;       /*!< FIFO reset, Address offset: 0x030 */
    uint32_t RESERVED_034[3];           /*!< Reserved, Address offset: 0x034 */
    volatile uint32_t RX_STATUS;        /*!< RX module internal state register, Address offset: 0x040 */
    uint32_t RESERVED_044[1];           /*!< Reserved, Address offset: 0x044 */
    volatile uint32_t TX_STATUS;        /*!< TX module internal state register, Address offset: 0x048 */
    uint32_t RESERVED_04C[5];           /*!< Reserved, Address offset: 0x04C */
    volatile uint32_t I2_S_CLK_CTRL0;   /*!< Clock Control, Address offset: 0x060 */
    volatile uint32_t I2_S_CLK_CTRL1;   /*!< The main mode of the clock frequency, Address offset: 0x064 */
    volatile uint32_t I2_S_PCM_SYNTH;   /*!< PCM frame synchronization signal
                                            synthesis mode control, Address offset: 0x068 */
    uint32_t RESERVED_06C[5];           /*!< Reserved, Address offset: 0x06C */
    volatile uint32_t RX_RD_PORT;       /*!< RX FIFO read port, Address offset: 0x080 */
    uint32_t RESERVED_084[15];          /*!< Reserved, Address offset: 0x084 */
    volatile uint32_t TX_WR_PORT;       /*!< TX FIFO write port, Address offset: 0x0C0 */
} I2S_Type;

static_assert(offsetof(I2S_Type, BLK_MODE_SETTING) == 0x000U);
static_assert(offsetof(I2S_Type, FRAME_SETTING) == 0x004U);
static_assert(offsetof(I2S_Type, SLOT_SETTING1) == 0x008U);
static_assert(offsetof(I2S_Type, SLOT_SETTING2) == 0x00CU);
static_assert(offsetof(I2S_Type, DATA_FORMAT) == 0x010U);
static_assert(offsetof(I2S_Type, BLK_CFG) == 0x014U);
static_assert(offsetof(I2S_Type, I2_S_ENABLE) == 0x018U);
static_assert(offsetof(I2S_Type, I2_S_RESET) == 0x01CU);
static_assert(offsetof(I2S_Type, I2_S_INT_EN) == 0x020U);
static_assert(offsetof(I2S_Type, I2_S_INT) == 0x024U);
static_assert(offsetof(I2S_Type, FIFO_THRESHOLD) == 0x028U);
static_assert(offsetof(I2S_Type, I2_S_LRCK_MASTER) == 0x02CU);
static_assert(offsetof(I2S_Type, FIFO_RESET) == 0x030U);
static_assert(offsetof(I2S_Type, RX_STATUS) == 0x040U);
static_assert(offsetof(I2S_Type, TX_STATUS) == 0x048U);
static_assert(offsetof(I2S_Type, I2_S_CLK_CTRL0) == 0x060U);
static_assert(offsetof(I2S_Type, I2_S_CLK_CTRL1) == 0x064U);
static_assert(offsetof(I2S_Type, I2_S_PCM_SYNTH) == 0x068U);
static_assert(offsetof(I2S_Type, RX_RD_PORT) == 0x080U);
static_assert(offsetof(I2S_Type, TX_WR_PORT) == 0x0C0U);

/**
 * @brief I2S0_REGS register-instance pointer.
 */
#define I2S0_REGS ((I2S_Type *)(uintptr_t)I2S0_BASE)

/**
 * @brief I2S1_REGS register-instance pointer.
 */
#define I2S1_REGS ((I2S_Type *)(uintptr_t)I2S1_BASE)

/**
 * @brief I2S2_REGS register-instance pointer.
 */
#define I2S2_REGS ((I2S_Type *)(uintptr_t)I2S2_BASE)

/**
 * @brief I2S3_REGS register-instance pointer.
 */
#define I2S3_REGS ((I2S_Type *)(uintptr_t)I2S3_BASE)

/**
 * @brief Audio codec register block.
 */
typedef struct
{
    volatile uint32_t TXDAC_CTRL0;  /*!< Address offset: 0x000 */
    volatile uint32_t TXDAC_CTRL1;  /*!< Address offset: 0x004 */
    volatile uint32_t TXDAC_STATUS; /*!< Address offset: 0x008 */
    volatile uint32_t TXDAC_AFE0;   /*!< Address offset: 0x00C */
    volatile uint32_t TXDAC_AFE1;   /*!< Address offset: 0x010 */
    uint32_t RESERVED_014[3];       /*!< Reserved, Address offset: 0x014 */
    volatile uint32_t TXDAC_ANA0;   /*!< Address offset: 0x020 */
    volatile uint32_t TXDAC_ANA1;   /*!< Address offset: 0x024 */
    uint32_t RESERVED_028[54];      /*!< Reserved, Address offset: 0x028 */
    volatile uint32_t RXADC_CTRL0;  /*!< Address offset: 0x100 */
    volatile uint32_t RXADCC_CTRL1; /*!< Address offset: 0x104 */
    volatile uint32_t RXADC_STATUS; /*!< Address offset: 0x108 */
    uint32_t RESERVED_10C[1];       /*!< Reserved, Address offset: 0x10C */
    volatile uint32_t RXADC_ANA0;   /*!< Address offset: 0x110 */
    volatile uint32_t RXADC_ANA1;   /*!< Address offset: 0x114 */
    volatile uint32_t RXADC_ANA2;   /*!< Address offset: 0x118 */
    volatile uint32_t RXADC_ANA3;   /*!< Address offset: 0x11C */
    volatile uint32_t RXADC_ANA4;   /*!< Address offset: 0x120 */
} AUDIO_CODEC_Type;

static_assert(offsetof(AUDIO_CODEC_Type, TXDAC_CTRL0) == 0x000U);
static_assert(offsetof(AUDIO_CODEC_Type, TXDAC_CTRL1) == 0x004U);
static_assert(offsetof(AUDIO_CODEC_Type, TXDAC_STATUS) == 0x008U);
static_assert(offsetof(AUDIO_CODEC_Type, TXDAC_AFE0) == 0x00CU);
static_assert(offsetof(AUDIO_CODEC_Type, TXDAC_AFE1) == 0x010U);
static_assert(offsetof(AUDIO_CODEC_Type, TXDAC_ANA0) == 0x020U);
static_assert(offsetof(AUDIO_CODEC_Type, TXDAC_ANA1) == 0x024U);
static_assert(offsetof(AUDIO_CODEC_Type, RXADC_CTRL0) == 0x100U);
static_assert(offsetof(AUDIO_CODEC_Type, RXADCC_CTRL1) == 0x104U);
static_assert(offsetof(AUDIO_CODEC_Type, RXADC_STATUS) == 0x108U);
static_assert(offsetof(AUDIO_CODEC_Type, RXADC_ANA0) == 0x110U);
static_assert(offsetof(AUDIO_CODEC_Type, RXADC_ANA1) == 0x114U);
static_assert(offsetof(AUDIO_CODEC_Type, RXADC_ANA2) == 0x118U);
static_assert(offsetof(AUDIO_CODEC_Type, RXADC_ANA3) == 0x11CU);
static_assert(offsetof(AUDIO_CODEC_Type, RXADC_ANA4) == 0x120U);

/**
 * @brief RTC_CORE register block.
 */
typedef struct
{
    volatile uint32_t RTC_ANA_CALIB;            /*!< 32K oscillator control, Address offset: 0x000 */
    volatile uint32_t RTC_SEC_PULSE_GEN;        /*!< Second pulse generator integer
                                                    and decimal digits, Address offset: 0x004 */
    volatile uint32_t RTC_ALARM_TIME;           /*!< scheduled alarm time, Address offset: 0x008 */
    volatile uint32_t RTC_ALARM_ENABLE;         /*!< Enable alarm, Address offset: 0x00C */
    volatile uint32_t RTC_SET_SEC_CNTR_VALUE;   /*!< Set seconds counter value, Address offset: 0x010 */
    volatile uint32_t RTC_SET_SEC_CNTR_TRIG;    /*!< Loading seconds counter value, Address offset: 0x014 */
    volatile uint32_t RTC_SEC_CNTR_VALUE;       /*!< Read current second counter
                                                    value, Address offset: 0x018 */
    volatile uint32_t RTC_INFO0;                /*!< Information register 0, Address offset: 0x01C */
    volatile uint32_t RTC_INFO1;                /*!< Information register 1, Address offset: 0x020 */
    volatile uint32_t RTC_INFO2;                /*!< Information register 2, Address offset: 0x024 */
    volatile uint32_t RTC_INFO3;                /*!< Information register 3, Address offset: 0x028 */
    volatile uint32_t RTC_NOPOR_INFO0;          /*!< No reset information register 0, Address offset: 0x02C */
    volatile uint32_t RTC_NOPOR_INFO1;          /*!< No reset information register 1, Address offset: 0x030 */
    volatile uint32_t RTC_NOPOR_INFO2;          /*!< No reset information register 2, Address offset: 0x034 */
    volatile uint32_t RTC_NOPOR_INFO3;          /*!< No reset information register 3, Address offset: 0x038 */
    uint32_t RESERVED_03C[1];                   /*!< Reserved, Address offset: 0x03C */
    volatile uint32_t RTC_DB_PWR_VBAT_DET;      /*!< PWR_VBAT_DET debounce time, Address offset: 0x040 */
    uint32_t RESERVED_044[1];                   /*!< Reserved, Address offset: 0x044 */
    volatile uint32_t RTC_DB_BUTTON1;           /*!< PWR_BUTTON1debounce time, Address offset: 0x048 */
    volatile uint32_t RTC_DB_PWR_ON;            /*!< PWR_ONdebounce time, Address offset: 0x04C */
    volatile uint32_t RTC_7_SEC_RESET;          /*!< Set the number of seconds to
                                                    press and hold PWR_BUTTON to
                                                    force reset, Address offset: 0x050 */
    uint32_t RESERVED_054[4];                   /*!< Reserved, Address offset: 0x054 */
    volatile uint32_t RTC_THM_SHDN_AUTO_REBOOT; /*!< Select REQ_THM_SHDN action, Address offset: 0x064 */
    volatile uint32_t RTC_POR_DB_MAGIC_KEY;     /*!< Enable POR long-term debounce, Address offset: 0x068 */
    volatile uint32_t RTC_DB_SEL_PWR;           /*!< Select PWR_BUTTON debounce mode, Address offset: 0x06C */
    volatile uint32_t RTC_UP_SEQ0;              /*!< Power-on PWR_SEQ0 output timing, Address offset: 0x070 */
    volatile uint32_t RTC_UP_SEQ1;              /*!< Power-on PWR_SEQ1 output timing, Address offset: 0x074 */
    volatile uint32_t RTC_UP_SEQ2;              /*!< Power-on PWR_SEQ2 output timing, Address offset: 0x078 */
    volatile uint32_t RTC_UP_SEQ3;              /*!< Power-on PWR_SEQ3 output timing, Address offset: 0x07C */
    volatile uint32_t RTC_UP_IF_EN;             /*!< Power-on ISO release timing, Address offset: 0x080 */
    volatile uint32_t RTC_UP_RSTN;              /*!< Power-on system reset release
                                                    sequence, Address offset: 0x084 */
    volatile uint32_t RTC_UP_MAX;               /*!< Power-on process completion
                                                    timing, Address offset: 0x088 */
    uint32_t RESERVED_08C[1];                   /*!< Reserved, Address offset: 0x08C */
    volatile uint32_t RTC_DN_SEQ0;             /*!< Power off PWR_SEQ0 output timing, Address offset: 0x090 */
    volatile uint32_t RTC_DN_SEQ1;             /*!< Power off PWR_SEQ1 output timing, Address offset: 0x094 */
    volatile uint32_t RTC_DN_SEQ2;             /*!< Power off PWR_SEQ2 output timing, Address offset: 0x098 */
    volatile uint32_t RTC_DN_SEQ3;             /*!< Power off PWR_SEQ3 output timing, Address offset: 0x09C */
    volatile uint32_t RTC_DN_IF_EN;            /*!< Power off ISO open timing, Address offset: 0x0A0 */
    volatile uint32_t RTC_DN_RSTN;             /*!< Power-off system reset sequence, Address offset: 0x0A4 */
    volatile uint32_t RTC_DN_MAX;              /*!< Power-off process completion
                                                    timing, Address offset: 0x0A8 */
    uint32_t RESERVED_0AC[1];                  /*!< Reserved, Address offset: 0x0AC */
    volatile uint32_t RTC_PWR_CYC_MAX;         /*!< Power-cycle completion timing, Address offset: 0x0B0 */
    volatile uint32_t RTC_WARM_RST_MAX;        /*!< Warm-reset completion timi, Address offset: 0x0B4 */
    volatile uint32_t RTC_EN_7_SEC_RST;        /*!< Set PWR_BUTTON1 7SEC reset mode, Address offset: 0x0B8 */
    volatile uint32_t RTC_EN_PWR_WAKEUP;       /*!< Set sleep wake-up source, Address offset: 0x0BC */
    volatile uint32_t RTC_EN_SHDN_REQ;         /*!< Enable REQ_SHDN, Address offset: 0x0C0 */
    volatile uint32_t RTC_EN_THM_SHDN;         /*!< Enable REQ_THM_SHDN, Address offset: 0x0C4 */
    volatile uint32_t RTC_EN_PWR_CYC_REQ;      /*!< Enable REQ_PWR_CYC, Address offset: 0x0C8 */
    volatile uint32_t RTC_EN_WARM_RST_REQ;     /*!< Enable REQ_WARM_RST, Address offset: 0x0CC */
    volatile uint32_t RTC_EN_PWR_VBAT_DET;     /*!< Enable state machine reference
                                                    PWR_VBAT_DET, Address offset: 0x0D0 */
    volatile uint32_t FSM_STATE;               /*!< RTC state machine value, Address offset: 0x0D4 */
    uint32_t RESERVED_0D8[2];                  /*!< Reserved, Address offset: 0x0D8 */
    volatile uint32_t RTC_EN_WDG_RST_REQ;      /*!< Enable REQ_WDG_RST, Address offset: 0x0E0 */
    volatile uint32_t RTC_EN_SUSPEND_REQ;      /*!< Enable REQ_SUSPEND, Address offset: 0x0E4 */
    volatile uint32_t RTC_DB_REQ_WDG_RST;      /*!< REQ_WDG_RST debounce time, Address offset: 0x0E8 */
    volatile uint32_t RTC_DB_REQ_SUSPEND;      /*!< REQ_SUSPEND debounce time, Address offset: 0x0EC */
    volatile uint32_t RTC_PG_REG;              /*!< Power Good Register, Address offset: 0x0F0 */
    uint32_t RESERVED_0F4[1];                  /*!< Reserved, Address offset: 0x0F4 */
    volatile uint32_t RTC_ST_ON_REASON;        /*!< Power-on status register, Address offset: 0x0F8 */
    volatile uint32_t RTC_ST_OFF_REASON;       /*!< Power-down status register, Address offset: 0x0FC */
    uint32_t RESERVED_100[8];                  /*!< Reserved, Address offset: 0x100 */
    volatile uint32_t RTC_EN_WAKEUP_REQ;       /*!< Enable REQ_WAKEUP, Address offset: 0x120 */
    uint32_t RESERVED_124[1];                  /*!< Reserved, Address offset: 0x124 */
    volatile uint32_t RTC_PWR_WAKEUP_POLARITY; /*!< Select PWR_WAKEUP low level, Address offset: 0x128 */
    uint32_t RESERVED_12C[1];                  /*!< Reserved, Address offset: 0x12C */
    volatile uint32_t RTC_DB_SEL_REQ;          /*!< Select debounce mode, Address offset: 0x130 */
    uint32_t RESERVED_134[3];                  /*!< Reserved, Address offset: 0x134 */
    volatile uint32_t RTC_PWR_DET_SEL;         /*!< Select low voltage detection
                                                    signal source The overview of
                                                    RTC_MACRO_REG register is shown
                                                    in RTC_MACRO_REG Overview (Base
                                                    0x05026400), Address offset: 0x140 */
} RTC_CORE_Type;

static_assert(offsetof(RTC_CORE_Type, RTC_ANA_CALIB) == 0x000U);
static_assert(offsetof(RTC_CORE_Type, RTC_SEC_PULSE_GEN) == 0x004U);
static_assert(offsetof(RTC_CORE_Type, RTC_ALARM_TIME) == 0x008U);
static_assert(offsetof(RTC_CORE_Type, RTC_ALARM_ENABLE) == 0x00CU);
static_assert(offsetof(RTC_CORE_Type, RTC_SET_SEC_CNTR_VALUE) == 0x010U);
static_assert(offsetof(RTC_CORE_Type, RTC_SET_SEC_CNTR_TRIG) == 0x014U);
static_assert(offsetof(RTC_CORE_Type, RTC_SEC_CNTR_VALUE) == 0x018U);
static_assert(offsetof(RTC_CORE_Type, RTC_INFO0) == 0x01CU);
static_assert(offsetof(RTC_CORE_Type, RTC_INFO1) == 0x020U);
static_assert(offsetof(RTC_CORE_Type, RTC_INFO2) == 0x024U);
static_assert(offsetof(RTC_CORE_Type, RTC_INFO3) == 0x028U);
static_assert(offsetof(RTC_CORE_Type, RTC_NOPOR_INFO0) == 0x02CU);
static_assert(offsetof(RTC_CORE_Type, RTC_NOPOR_INFO1) == 0x030U);
static_assert(offsetof(RTC_CORE_Type, RTC_NOPOR_INFO2) == 0x034U);
static_assert(offsetof(RTC_CORE_Type, RTC_NOPOR_INFO3) == 0x038U);
static_assert(offsetof(RTC_CORE_Type, RTC_DB_PWR_VBAT_DET) == 0x040U);
static_assert(offsetof(RTC_CORE_Type, RTC_DB_BUTTON1) == 0x048U);
static_assert(offsetof(RTC_CORE_Type, RTC_DB_PWR_ON) == 0x04CU);
static_assert(offsetof(RTC_CORE_Type, RTC_7_SEC_RESET) == 0x050U);
static_assert(offsetof(RTC_CORE_Type, RTC_THM_SHDN_AUTO_REBOOT) == 0x064U);
static_assert(offsetof(RTC_CORE_Type, RTC_POR_DB_MAGIC_KEY) == 0x068U);
static_assert(offsetof(RTC_CORE_Type, RTC_DB_SEL_PWR) == 0x06CU);
static_assert(offsetof(RTC_CORE_Type, RTC_UP_SEQ0) == 0x070U);
static_assert(offsetof(RTC_CORE_Type, RTC_UP_SEQ1) == 0x074U);
static_assert(offsetof(RTC_CORE_Type, RTC_UP_SEQ2) == 0x078U);
static_assert(offsetof(RTC_CORE_Type, RTC_UP_SEQ3) == 0x07CU);
static_assert(offsetof(RTC_CORE_Type, RTC_UP_IF_EN) == 0x080U);
static_assert(offsetof(RTC_CORE_Type, RTC_UP_RSTN) == 0x084U);
static_assert(offsetof(RTC_CORE_Type, RTC_UP_MAX) == 0x088U);
static_assert(offsetof(RTC_CORE_Type, RTC_DN_SEQ0) == 0x090U);
static_assert(offsetof(RTC_CORE_Type, RTC_DN_SEQ1) == 0x094U);
static_assert(offsetof(RTC_CORE_Type, RTC_DN_SEQ2) == 0x098U);
static_assert(offsetof(RTC_CORE_Type, RTC_DN_SEQ3) == 0x09CU);
static_assert(offsetof(RTC_CORE_Type, RTC_DN_IF_EN) == 0x0A0U);
static_assert(offsetof(RTC_CORE_Type, RTC_DN_RSTN) == 0x0A4U);
static_assert(offsetof(RTC_CORE_Type, RTC_DN_MAX) == 0x0A8U);
static_assert(offsetof(RTC_CORE_Type, RTC_PWR_CYC_MAX) == 0x0B0U);
static_assert(offsetof(RTC_CORE_Type, RTC_WARM_RST_MAX) == 0x0B4U);
static_assert(offsetof(RTC_CORE_Type, RTC_EN_7_SEC_RST) == 0x0B8U);
static_assert(offsetof(RTC_CORE_Type, RTC_EN_PWR_WAKEUP) == 0x0BCU);
static_assert(offsetof(RTC_CORE_Type, RTC_EN_SHDN_REQ) == 0x0C0U);
static_assert(offsetof(RTC_CORE_Type, RTC_EN_THM_SHDN) == 0x0C4U);
static_assert(offsetof(RTC_CORE_Type, RTC_EN_PWR_CYC_REQ) == 0x0C8U);
static_assert(offsetof(RTC_CORE_Type, RTC_EN_WARM_RST_REQ) == 0x0CCU);
static_assert(offsetof(RTC_CORE_Type, RTC_EN_PWR_VBAT_DET) == 0x0D0U);
static_assert(offsetof(RTC_CORE_Type, FSM_STATE) == 0x0D4U);
static_assert(offsetof(RTC_CORE_Type, RTC_EN_WDG_RST_REQ) == 0x0E0U);
static_assert(offsetof(RTC_CORE_Type, RTC_EN_SUSPEND_REQ) == 0x0E4U);
static_assert(offsetof(RTC_CORE_Type, RTC_DB_REQ_WDG_RST) == 0x0E8U);
static_assert(offsetof(RTC_CORE_Type, RTC_DB_REQ_SUSPEND) == 0x0ECU);
static_assert(offsetof(RTC_CORE_Type, RTC_PG_REG) == 0x0F0U);
static_assert(offsetof(RTC_CORE_Type, RTC_ST_ON_REASON) == 0x0F8U);
static_assert(offsetof(RTC_CORE_Type, RTC_ST_OFF_REASON) == 0x0FCU);
static_assert(offsetof(RTC_CORE_Type, RTC_EN_WAKEUP_REQ) == 0x120U);
static_assert(offsetof(RTC_CORE_Type, RTC_PWR_WAKEUP_POLARITY) == 0x128U);
static_assert(offsetof(RTC_CORE_Type, RTC_DB_SEL_REQ) == 0x130U);
static_assert(offsetof(RTC_CORE_Type, RTC_PWR_DET_SEL) == 0x140U);

/**
 * @brief RTC_CORE_REGS register-instance pointer.
 */
#define RTC_CORE_REGS ((RTC_CORE_Type *)(uintptr_t)RTC_CORE_BASE)

/**
 * @brief RTC_MACRO register block.
 */
typedef struct
{
    uint32_t RESERVED_000[17];                 /*!< Reserved, Address offset: 0x000 */
    volatile uint32_t RTC_PWR_DET_COMP;        /*!< Low voltage detection control, Address offset: 0x044 */
    uint32_t RESERVED_048[14];                 /*!< Reserved, Address offset: 0x048 */
    volatile uint32_t RTC_MACRO_DA_CLEAR_ALL;  /*!< DA_CLEAR_ALL, Address offset: 0x080 */
    volatile uint32_t RTC_MACRO_DA_SET_ALL;    /*!< DA_SEL_ALL, Address offset: 0x084 */
    volatile uint32_t RTC_MACRO_DA_LATCH_PASS; /*!< DA_LATCH_PASS, Address offset: 0x088 */
    volatile uint32_t RTC_MACRO_DA_SOC_READY;  /*!< DA_SOC_READY, Address offset: 0x08C */
    volatile uint32_t RTC_MACRO_PD_SLDO;       /*!< PD_SLDO, Address offset: 0x090 */
    volatile uint32_t RTC_MACRO_RG_DEFD;       /*!< RG_DEFD, Address offset: 0x094 */
    volatile uint32_t RTC_MACRO_RG_SET_T;      /*!< RG_SET_T, Address offset: 0x098 */
    uint32_t RESERVED_09C[1];                  /*!< Reserved, Address offset: 0x09C */
    volatile uint32_t RTC_MACRO_RO_CLK_STOP;   /*!< RO_CLK_STOP, Address offset: 0x0A0 */
    volatile uint32_t RTC_MACRO_RO_DEFQ;       /*!< RO_DEFQ, Address offset: 0x0A4 */
    volatile uint32_t RTC_MACRO_RO_T;          /*!< RO_T The overview of RTC_CTRL_REG
                                                   register is shown in RTC_CTRL_REG
                                                   Overview (Base: 0x05025000), Address offset: 0x0A8 */
} RTC_MACRO_Type;

static_assert(offsetof(RTC_MACRO_Type, RTC_PWR_DET_COMP) == 0x044U);
static_assert(offsetof(RTC_MACRO_Type, RTC_MACRO_DA_CLEAR_ALL) == 0x080U);
static_assert(offsetof(RTC_MACRO_Type, RTC_MACRO_DA_SET_ALL) == 0x084U);
static_assert(offsetof(RTC_MACRO_Type, RTC_MACRO_DA_LATCH_PASS) == 0x088U);
static_assert(offsetof(RTC_MACRO_Type, RTC_MACRO_DA_SOC_READY) == 0x08CU);
static_assert(offsetof(RTC_MACRO_Type, RTC_MACRO_PD_SLDO) == 0x090U);
static_assert(offsetof(RTC_MACRO_Type, RTC_MACRO_RG_DEFD) == 0x094U);
static_assert(offsetof(RTC_MACRO_Type, RTC_MACRO_RG_SET_T) == 0x098U);
static_assert(offsetof(RTC_MACRO_Type, RTC_MACRO_RO_CLK_STOP) == 0x0A0U);
static_assert(offsetof(RTC_MACRO_Type, RTC_MACRO_RO_DEFQ) == 0x0A4U);
static_assert(offsetof(RTC_MACRO_Type, RTC_MACRO_RO_T) == 0x0A8U);

/**
 * @brief RTC_MACRO_REGS register-instance pointer.
 */
#define RTC_MACRO_REGS ((RTC_MACRO_Type *)(uintptr_t)RTC_MACRO_BASE)

/**
 * @brief PLL_G2 register block.
 */
typedef struct
{
    volatile uint32_t PLL_G2_CTRL;         /*!< Group2 PLL Ctrl register, Address offset: 0x000 */
    volatile uint32_t PLL_G2_STATUS;       /*!< Group2 PLL Status register, Address offset: 0x004 */
    volatile uint32_t MIPIMPLL_CSR;        /*!< MIPIMPLL Ctrl register, Address offset: 0x008 */
    volatile uint32_t APLL0_CSR;           /*!< APLL0 Ctrl register, Address offset: 0x00C */
    volatile uint32_t DISPPLL_CSR;         /*!< DISPPLL Ctrl register, Address offset: 0x010 */
    volatile uint32_t CAM0PLL_CSR;         /*!< CAM0PLL Ctrl register, Address offset: 0x014 */
    volatile uint32_t CAM1PLL_CSR;         /*!< CAM1PLL Ctrl register, Address offset: 0x018 */
    uint32_t RESERVED_01C[9];              /*!< Reserved, Address offset: 0x01C */
    volatile uint32_t PLL_G2_SSC_SYN_CTRL; /*!< Group2 PLL Synthesizer ctrl register, Address offset: 0x040 */
    uint32_t RESERVED_044[3];              /*!< Reserved, Address offset: 0x044 */
    volatile uint32_t APLL_SSC_SYN_CTRL;   /*!< APLL synthesizer ctrl register, Address offset: 0x050 */
    volatile uint32_t APLL_SSC_SYN_SET;    /*!< APLL synthesizer set register, Address offset: 0x054 */
    uint32_t RESERVED_058[2];              /*!< Reserved, Address offset: 0x058 */
    volatile uint32_t DISPPLL_SSC_SYN_CTRL; /*!< DISPPLL synthesizer ctrl register, Address offset: 0x060 */
    volatile uint32_t DISPPLL_SSC_SYN_SET;  /*!< DISPPLL synthesizer set register, Address offset: 0x064 */
    uint32_t RESERVED_068[2];               /*!< Reserved, Address offset: 0x068 */
    volatile uint32_t CAM0PLL_SSC_SYN_CTRL; /*!< CAM0PLL synthesizer ctrl register, Address offset: 0x070 */
    volatile uint32_t CAM0PLL_SSC_SYN_SET;  /*!< CAM0PLL synthesizer set register, Address offset: 0x074 */
    uint32_t RESERVED_078[2];               /*!< Reserved, Address offset: 0x078 */
    volatile uint32_t CAM1PLL_SSC_SYN_CTRL; /*!< CAM1PLL synthesizer ctrl register, Address offset: 0x080 */
    volatile uint32_t CAM1PLL_SSC_SYN_SET;  /*!< CAM1PLL synthesizer set register, Address offset: 0x084 */
    uint32_t RESERVED_088[2];               /*!< Reserved, Address offset: 0x088 */
    volatile uint32_t APLL_FRAC_DIV_CTRL;   /*!< APLL frac divider ctrl register, Address offset: 0x090 */
    volatile uint32_t APLL_FRAC_DIV_M;      /*!< APLL frac divider M parameter, Address offset: 0x094 */
    volatile uint32_t APLL_FRAC_DIV_N;      /*!< APLL frac divider N parameter, Address offset: 0x098 */
    uint32_t RESERVED_09C[1];               /*!< Reserved, Address offset: 0x09C */
    volatile uint32_t MIPIMPLL_CLK_CSR;     /*!< MIPIMPLL clock Ctrl register, Address offset: 0x0A0 */
    volatile uint32_t A0PLL_CLK_CSR;        /*!< a0pll clock Ctrl register, Address offset: 0x0A4 */
    volatile uint32_t DISPPLL_CLK_CSR;      /*!< disppll clock Ctrl register, Address offset: 0x0A8 */
    volatile uint32_t CAM0PLL_CLK_CSR;      /*!< cam0pll clock Ctrl register, Address offset: 0x0AC */
    volatile uint32_t CAM1PLL_CLK_CSR;      /*!< cam1pll clock Ctrl register, Address offset: 0x0B0 */
    uint32_t RESERVED_0B4[3];               /*!< Reserved, Address offset: 0x0B4 */
    volatile uint32_t CLK_CAM0_SRC_DIV;     /*!< clk_cam0_src_div, Address offset: 0x0C0 */
    volatile uint32_t CLK_CAM1_SRC_DIV;     /*!< clk_cam1_src_div, Address offset: 0x0C4 */
} PLL_G2_Type;

static_assert(offsetof(PLL_G2_Type, PLL_G2_CTRL) == 0x000U);
static_assert(offsetof(PLL_G2_Type, PLL_G2_STATUS) == 0x004U);
static_assert(offsetof(PLL_G2_Type, MIPIMPLL_CSR) == 0x008U);
static_assert(offsetof(PLL_G2_Type, APLL0_CSR) == 0x00CU);
static_assert(offsetof(PLL_G2_Type, DISPPLL_CSR) == 0x010U);
static_assert(offsetof(PLL_G2_Type, CAM0PLL_CSR) == 0x014U);
static_assert(offsetof(PLL_G2_Type, CAM1PLL_CSR) == 0x018U);
static_assert(offsetof(PLL_G2_Type, PLL_G2_SSC_SYN_CTRL) == 0x040U);
static_assert(offsetof(PLL_G2_Type, APLL_SSC_SYN_CTRL) == 0x050U);
static_assert(offsetof(PLL_G2_Type, APLL_SSC_SYN_SET) == 0x054U);
static_assert(offsetof(PLL_G2_Type, DISPPLL_SSC_SYN_CTRL) == 0x060U);
static_assert(offsetof(PLL_G2_Type, DISPPLL_SSC_SYN_SET) == 0x064U);
static_assert(offsetof(PLL_G2_Type, CAM0PLL_SSC_SYN_CTRL) == 0x070U);
static_assert(offsetof(PLL_G2_Type, CAM0PLL_SSC_SYN_SET) == 0x074U);
static_assert(offsetof(PLL_G2_Type, CAM1PLL_SSC_SYN_CTRL) == 0x080U);
static_assert(offsetof(PLL_G2_Type, CAM1PLL_SSC_SYN_SET) == 0x084U);
static_assert(offsetof(PLL_G2_Type, APLL_FRAC_DIV_CTRL) == 0x090U);
static_assert(offsetof(PLL_G2_Type, APLL_FRAC_DIV_M) == 0x094U);
static_assert(offsetof(PLL_G2_Type, APLL_FRAC_DIV_N) == 0x098U);
static_assert(offsetof(PLL_G2_Type, MIPIMPLL_CLK_CSR) == 0x0A0U);
static_assert(offsetof(PLL_G2_Type, A0PLL_CLK_CSR) == 0x0A4U);
static_assert(offsetof(PLL_G2_Type, DISPPLL_CLK_CSR) == 0x0A8U);
static_assert(offsetof(PLL_G2_Type, CAM0PLL_CLK_CSR) == 0x0ACU);
static_assert(offsetof(PLL_G2_Type, CAM1PLL_CLK_CSR) == 0x0B0U);
static_assert(offsetof(PLL_G2_Type, CLK_CAM0_SRC_DIV) == 0x0C0U);
static_assert(offsetof(PLL_G2_Type, CLK_CAM1_SRC_DIV) == 0x0C4U);

/**
 * @brief PLL_G2_REGS register-instance pointer.
 */
#define PLL_G2_REGS ((PLL_G2_Type *)(uintptr_t)PLL_G2_BASE)

/**
 * @brief Per-pad pull, drive-strength and Schmitt-trigger configuration.
 */
typedef struct
{
    uint32_t RESERVED_000[1];                    /*!< Reserved, Address offset: 0x000 */
    volatile uint32_t PWM0_BUCK;                 /*!< 58 pad control, field layout A, Address offset: 0x004 */
    uint32_t RESERVED_008[2];                    /*!< Reserved, Address offset: 0x008 */
    volatile uint32_t ADC1;                      /*!< 59 pad control, field layout A, Address offset: 0x010 */
    uint32_t RESERVED_014[2];                    /*!< Reserved, Address offset: 0x014 */
    volatile uint32_t PKG_TYPE0;                 /*!< PKG_TYPE0 pad control, field
                                                      layout A, Address offset: 0x01C */
    volatile uint32_t USB_VBUS_DET;              /*!< 60 pad control, field layout A, Address offset: 0x020 */
    volatile uint32_t PKG_TYPE1;                 /*!< PKG_TYPE1 pad control, field
                                                      layout A, Address offset: 0x024 */
    volatile uint32_t PKG_TYPE2;                 /*!< PKG_TYPE2 pad control, field
                                                      layout A, Address offset: 0x028 */
    uint32_t RESERVED_02C[53];                   /*!< Reserved, Address offset: 0x02C */
    volatile uint32_t IOBLK_G7_REG_SD0_CD;       /*!< 14 pad control, field layout B, Address offset: 0x100 */
    volatile uint32_t IOBLK_G7_REG_SD0_PWR_EN;   /*!< 15 pad control, field layout B, Address offset: 0x104 */
    volatile uint32_t IOBLK_G7_REG_SPK_EN;       /*!< 17 pad control, field layout B, Address offset: 0x108 */
    volatile uint32_t IOBLK_G7_REG_UART0_TX;     /*!< 18 pad control, field layout B, Address offset: 0x10C */
    volatile uint32_t IOBLK_G7_REG_UART0_RX;     /*!< 19 pad control, field layout B, Address offset: 0x110 */
    uint32_t RESERVED_114[1];                    /*!< Reserved, Address offset: 0x114 */
    volatile uint32_t IOBLK_G7_REG_EMMC_DAT2;    /*!< 20 pad control, field layout B, Address offset: 0x118 */
    volatile uint32_t IOBLK_G7_REG_EMMC_CLK;     /*!< 21 pad control, field layout B, Address offset: 0x11C */
    volatile uint32_t IOBLK_G7_REG_EMMC_DAT0;    /*!< 22 pad control, field layout B, Address offset: 0x120 */
    volatile uint32_t IOBLK_G7_REG_EMMC_DAT3;    /*!< 23 pad control, field layout B, Address offset: 0x124 */
    volatile uint32_t IOBLK_G7_REG_EMMC_CMD;     /*!< 24 pad control, field layout B, Address offset: 0x128 */
    volatile uint32_t IOBLK_G7_REG_EMMC_DAT1;    /*!< 25 pad control, field layout B, Address offset: 0x12C */
    volatile uint32_t IOBLK_G7_REG_JTAG_CPU_TMS; /*!< 26 pad control, field layout B, Address offset: 0x130 */
    volatile uint32_t IOBLK_G7_REG_JTAG_CPU_TCK; /*!< 27 pad control, field layout B, Address offset: 0x134 */
    uint32_t RESERVED_138[1];                    /*!< Reserved, Address offset: 0x138 */
    volatile uint32_t IOBLK_G7_REG_IIC0_SCL;     /*!< 28 pad control, field layout B, Address offset: 0x13C */
    volatile uint32_t IOBLK_G7_REG_IIC0_SDA;     /*!< 29 pad control, field layout B, Address offset: 0x140 */
    volatile uint32_t IOBLK_G7_REG_AUX0;         /*!< 30 pad control, field layout B, Address offset: 0x144 */
    uint32_t RESERVED_148[46];                   /*!< Reserved, Address offset: 0x148 */
    volatile uint32_t IOBLK_G10_REG_SD0_CLK;     /*!< 6 pad control, field layout B, Address offset: 0x200 */
    volatile uint32_t IOBLK_G10_REG_SD0_CMD;     /*!< 7 pad control, field layout B, Address offset: 0x204 */
    volatile uint32_t IOBLK_G10_REG_SD0_D0;      /*!< 8 pad control, field layout B, Address offset: 0x208 */
    volatile uint32_t IOBLK_G10_REG_SD0_D1;      /*!< 10 pad control, field layout B, Address offset: 0x20C */
    volatile uint32_t IOBLK_G10_REG_SD0_D2;      /*!< 11 pad control, field layout B, Address offset: 0x210 */
    volatile uint32_t IOBLK_G10_REG_SD0_D3;      /*!< 12 pad control, field layout B, Address offset: 0x214 */
    uint32_t RESERVED_218[136];                  /*!< Reserved, Address offset: 0x218 */
    volatile uint32_t IOBLK_G12_REG_PAD_MIPIRX4N;  /*!< 72 pad control, field layout
                                                       A, Address offset: 0x438 */
    volatile uint32_t IOBLK_G12_REG_PAD_MIPIRX4P;  /*!< 73 pad control, field layout
                                                       A, Address offset: 0x43C */
    volatile uint32_t IOBLK_G12_REG_PAD_MIPIRX3N;  /*!< 74 pad control, field layout
                                                       A, Address offset: 0x440 */
    volatile uint32_t IOBLK_G12_REG_PAD_MIPIRX3P;  /*!< 75 pad control, field layout
                                                       A, Address offset: 0x444 */
    volatile uint32_t IOBLK_G12_REG_PAD_MIPIRX2N;  /*!< 76 pad control, field layout
                                                       A, Address offset: 0x448 */
    volatile uint32_t IOBLK_G12_REG_PAD_MIPIRX2P;  /*!< 77 pad control, field layout
                                                       A, Address offset: 0x44C */
    volatile uint32_t IOBLK_G12_REG_PAD_MIPIRX1N;  /*!< 78 pad control, field layout
                                                       A, Address offset: 0x450 */
    volatile uint32_t IOBLK_G12_REG_PAD_MIPIRX1P;  /*!< 79 pad control, field layout
                                                       A, Address offset: 0x454 */
    volatile uint32_t IOBLK_G12_REG_PAD_MIPIRX0N;  /*!< 80 pad control, field layout
                                                       A, Address offset: 0x458 */
    volatile uint32_t IOBLK_G12_REG_PAD_MIPIRX0P;  /*!< 81 pad control, field layout
                                                       A, Address offset: 0x45C */
    uint32_t RESERVED_460[4];                      /*!< Reserved, Address offset: 0x460 */
    volatile uint32_t IOBLK_G12_REG_PAD_MIPI_TXM2; /*!< 83 pad control, field layout
                                                        A, Address offset: 0x470 */
    volatile uint32_t IOBLK_G12_REG_PAD_MIPI_TXP2; /*!< 84 pad control, field layout
                                                        A, Address offset: 0x474 */
    volatile uint32_t IOBLK_G12_REG_PAD_MIPI_TXM1; /*!< 85 pad control, field layout
                                                        A, Address offset: 0x478 */
    volatile uint32_t IOBLK_G12_REG_PAD_MIPI_TXP1; /*!< 86 pad control, field layout
                                                        A, Address offset: 0x47C */
    volatile uint32_t IOBLK_G12_REG_PAD_MIPI_TXM0; /*!< 87 pad control, field layout
                                                        A, Address offset: 0x480 */
    volatile uint32_t IOBLK_G12_REG_PAD_MIPI_TXP0; /*!< 88 pad control, field layout
                                                        A, Address offset: 0x484 */
    uint32_t RESERVED_488[1];                      /*!< Reserved, Address offset: 0x488 */
    volatile uint32_t IOBLK_G12_REG_GPIO_RTX; /*!< 67 pad control, field layout A, Address offset: 0x48C */
} IOBLK_Type;

static_assert(offsetof(IOBLK_Type, PWM0_BUCK) == 0x004U);
static_assert(offsetof(IOBLK_Type, ADC1) == 0x010U);
static_assert(offsetof(IOBLK_Type, PKG_TYPE0) == 0x01CU);
static_assert(offsetof(IOBLK_Type, USB_VBUS_DET) == 0x020U);
static_assert(offsetof(IOBLK_Type, PKG_TYPE1) == 0x024U);
static_assert(offsetof(IOBLK_Type, PKG_TYPE2) == 0x028U);
static_assert(offsetof(IOBLK_Type, IOBLK_G7_REG_SD0_CD) == 0x100U);
static_assert(offsetof(IOBLK_Type, IOBLK_G7_REG_SD0_PWR_EN) == 0x104U);
static_assert(offsetof(IOBLK_Type, IOBLK_G7_REG_SPK_EN) == 0x108U);
static_assert(offsetof(IOBLK_Type, IOBLK_G7_REG_UART0_TX) == 0x10CU);
static_assert(offsetof(IOBLK_Type, IOBLK_G7_REG_UART0_RX) == 0x110U);
static_assert(offsetof(IOBLK_Type, IOBLK_G7_REG_EMMC_DAT2) == 0x118U);
static_assert(offsetof(IOBLK_Type, IOBLK_G7_REG_EMMC_CLK) == 0x11CU);
static_assert(offsetof(IOBLK_Type, IOBLK_G7_REG_EMMC_DAT0) == 0x120U);
static_assert(offsetof(IOBLK_Type, IOBLK_G7_REG_EMMC_DAT3) == 0x124U);
static_assert(offsetof(IOBLK_Type, IOBLK_G7_REG_EMMC_CMD) == 0x128U);
static_assert(offsetof(IOBLK_Type, IOBLK_G7_REG_EMMC_DAT1) == 0x12CU);
static_assert(offsetof(IOBLK_Type, IOBLK_G7_REG_JTAG_CPU_TMS) == 0x130U);
static_assert(offsetof(IOBLK_Type, IOBLK_G7_REG_JTAG_CPU_TCK) == 0x134U);
static_assert(offsetof(IOBLK_Type, IOBLK_G7_REG_IIC0_SCL) == 0x13CU);
static_assert(offsetof(IOBLK_Type, IOBLK_G7_REG_IIC0_SDA) == 0x140U);
static_assert(offsetof(IOBLK_Type, IOBLK_G7_REG_AUX0) == 0x144U);
static_assert(offsetof(IOBLK_Type, IOBLK_G10_REG_SD0_CLK) == 0x200U);
static_assert(offsetof(IOBLK_Type, IOBLK_G10_REG_SD0_CMD) == 0x204U);
static_assert(offsetof(IOBLK_Type, IOBLK_G10_REG_SD0_D0) == 0x208U);
static_assert(offsetof(IOBLK_Type, IOBLK_G10_REG_SD0_D1) == 0x20CU);
static_assert(offsetof(IOBLK_Type, IOBLK_G10_REG_SD0_D2) == 0x210U);
static_assert(offsetof(IOBLK_Type, IOBLK_G10_REG_SD0_D3) == 0x214U);
static_assert(offsetof(IOBLK_Type, IOBLK_G12_REG_PAD_MIPIRX4N) == 0x438U);
static_assert(offsetof(IOBLK_Type, IOBLK_G12_REG_PAD_MIPIRX4P) == 0x43CU);
static_assert(offsetof(IOBLK_Type, IOBLK_G12_REG_PAD_MIPIRX3N) == 0x440U);
static_assert(offsetof(IOBLK_Type, IOBLK_G12_REG_PAD_MIPIRX3P) == 0x444U);
static_assert(offsetof(IOBLK_Type, IOBLK_G12_REG_PAD_MIPIRX2N) == 0x448U);
static_assert(offsetof(IOBLK_Type, IOBLK_G12_REG_PAD_MIPIRX2P) == 0x44CU);
static_assert(offsetof(IOBLK_Type, IOBLK_G12_REG_PAD_MIPIRX1N) == 0x450U);
static_assert(offsetof(IOBLK_Type, IOBLK_G12_REG_PAD_MIPIRX1P) == 0x454U);
static_assert(offsetof(IOBLK_Type, IOBLK_G12_REG_PAD_MIPIRX0N) == 0x458U);
static_assert(offsetof(IOBLK_Type, IOBLK_G12_REG_PAD_MIPIRX0P) == 0x45CU);
static_assert(offsetof(IOBLK_Type, IOBLK_G12_REG_PAD_MIPI_TXM2) == 0x470U);
static_assert(offsetof(IOBLK_Type, IOBLK_G12_REG_PAD_MIPI_TXP2) == 0x474U);
static_assert(offsetof(IOBLK_Type, IOBLK_G12_REG_PAD_MIPI_TXM1) == 0x478U);
static_assert(offsetof(IOBLK_Type, IOBLK_G12_REG_PAD_MIPI_TXP1) == 0x47CU);
static_assert(offsetof(IOBLK_Type, IOBLK_G12_REG_PAD_MIPI_TXM0) == 0x480U);
static_assert(offsetof(IOBLK_Type, IOBLK_G12_REG_PAD_MIPI_TXP0) == 0x484U);
static_assert(offsetof(IOBLK_Type, IOBLK_G12_REG_GPIO_RTX) == 0x48CU);

/**
 * @brief IOBLK_REGS register-instance pointer.
 */
#define IOBLK_REGS ((IOBLK_Type *)(uintptr_t)IOBLK_BASE)

/**
 * @brief Per-pad pull, drive-strength and Schmitt-trigger configuration.
 */
typedef struct
{
    volatile uint32_t PWR_VBAT_DET; /*!< 38 pad control, field layout A, Address offset: 0x000 */
    volatile uint32_t PWR_RSTN;     /*!< 39 pad control, field layout A, Address offset: 0x004 */
    volatile uint32_t PWR_SEQ1;     /*!< 40 pad control, field layout A, Address offset: 0x008 */
    volatile uint32_t PWR_SEQ2;     /*!< 41 pad control, field layout A, Address offset: 0x00C */
    uint32_t RESERVED_010[1];       /*!< Reserved, Address offset: 0x010 */
    volatile uint32_t PTEST;        /*!< 42 pad control, field layout A, Address offset: 0x014 */
    volatile uint32_t PWR_WAKEUP0;  /*!< 43 pad control, field layout A, Address offset: 0x018 */
    uint32_t RESERVED_01C[1];       /*!< Reserved, Address offset: 0x01C */
    volatile uint32_t PWR_BUTTON1;  /*!< 44 pad control, field layout A, Address offset: 0x020 */
    uint32_t RESERVED_024[1];       /*!< Reserved, Address offset: 0x024 */
    volatile uint32_t XTAL_XIN;     /*!< 45 pad control, field layout C, Address offset: 0x028 */
    volatile uint32_t PWR_GPIO0;    /*!< 47 pad control, field layout A, Address offset: 0x02C */
    volatile uint32_t PWR_GPIO1;    /*!< 48 pad control, field layout A, Address offset: 0x030 */
    volatile uint32_t PWR_GPIO2;    /*!< 49 pad control, field layout A, Address offset: 0x034 */
    uint32_t RESERVED_038[8];       /*!< Reserved, Address offset: 0x038 */
    volatile uint32_t SD1_D3;       /*!< 51 pad control, field layout B, Address offset: 0x058 */
    volatile uint32_t SD1_D2;       /*!< 52 pad control, field layout B, Address offset: 0x05C */
    volatile uint32_t SD1_D1;       /*!< 53 pad control, field layout B, Address offset: 0x060 */
    volatile uint32_t SD1_D0;       /*!< 54 pad control, field layout B, Address offset: 0x064 */
    volatile uint32_t SD1_CMD;      /*!< 55 pad control, field layout B, Address offset: 0x068 */
    volatile uint32_t SD1_CLK;      /*!< 56 pad control, field layout B, Address offset: 0x06C */
    uint32_t RESERVED_070[28];      /*!< Reserved, Address offset: 0x070 */
    volatile uint32_t GPIO_ZQ;      /*!< 35 pad control, field layout A, Address offset: 0x0E0 */
} RTC_IO_Type;

static_assert(offsetof(RTC_IO_Type, PWR_VBAT_DET) == 0x000U);
static_assert(offsetof(RTC_IO_Type, PWR_RSTN) == 0x004U);
static_assert(offsetof(RTC_IO_Type, PWR_SEQ1) == 0x008U);
static_assert(offsetof(RTC_IO_Type, PWR_SEQ2) == 0x00CU);
static_assert(offsetof(RTC_IO_Type, PTEST) == 0x014U);
static_assert(offsetof(RTC_IO_Type, PWR_WAKEUP0) == 0x018U);
static_assert(offsetof(RTC_IO_Type, PWR_BUTTON1) == 0x020U);
static_assert(offsetof(RTC_IO_Type, XTAL_XIN) == 0x028U);
static_assert(offsetof(RTC_IO_Type, PWR_GPIO0) == 0x02CU);
static_assert(offsetof(RTC_IO_Type, PWR_GPIO1) == 0x030U);
static_assert(offsetof(RTC_IO_Type, PWR_GPIO2) == 0x034U);
static_assert(offsetof(RTC_IO_Type, SD1_D3) == 0x058U);
static_assert(offsetof(RTC_IO_Type, SD1_D2) == 0x05CU);
static_assert(offsetof(RTC_IO_Type, SD1_D1) == 0x060U);
static_assert(offsetof(RTC_IO_Type, SD1_D0) == 0x064U);
static_assert(offsetof(RTC_IO_Type, SD1_CMD) == 0x068U);
static_assert(offsetof(RTC_IO_Type, SD1_CLK) == 0x06CU);
static_assert(offsetof(RTC_IO_Type, GPIO_ZQ) == 0x0E0U);

/**
 * @brief RTC_IO_REGS register-instance pointer.
 */
#define RTC_IO_REGS ((RTC_IO_Type *)(uintptr_t)RTC_IO_BASE)

/// @brief Pull-up enable. bit 2
static constexpr auto IOBLK_PU_BIT = 2U;
/// @brief Pull-down enable. bit 3
static constexpr auto IOBLK_PD_BIT = 3U;
/// @brief Drive strength bit 0. bit 5
static constexpr auto IOBLK_DS0_BIT = 5U;
/// @brief Drive strength bit 1. bit 6
static constexpr auto IOBLK_DS1_BIT = 6U;
/// @brief Schmitt trigger level bit 0. bit 8
static constexpr auto IOBLK_ST0_BIT = 8U;
/// @brief Output slew-rate limit. bit 11
static constexpr auto IOBLK_SL_BIT = 11U;

/// @brief Schmitt trigger level bit 1. bit 9
static constexpr auto IOBLK_ST1_BIT = 9U;
/// @brief Bus-holder enable. bit 10
static constexpr auto IOBLK_HE_BIT = 10U;

/// @brief Drive strength bit 2. bit 7
static constexpr auto IOBLK_DS2_BIT = 7U;

/// @brief Extended drive strength bit 0. bit 14
static constexpr auto IOBLK_XDS0_BIT = 14U;
/// @brief Extended drive strength bit 1. bit 15
static constexpr auto IOBLK_XDS1_BIT = 15U;
/// @brief Extended drive strength bit 2. bit 16
static constexpr auto IOBLK_XDS2_BIT = 16U;

/// @brief C906L PLIC interrupt-source ID for SDMA.
// **警告：下面这组编号与本板的中断控制器的实际编号并不一致。**
// 上游 `arch/riscv/boot/dts/sophgo/cv180x.dtsi` 用 `SOC_PERIPHERAL_IRQ(n) = n + 16`，
// 给出的是权威值：DMAC = 29（`SOC_PERIPHERAL_IRQ(13)`）、GPIO0 端口 A..GPIO4 = 60..70
// （44..54+16）、SPI0..SPI3 = 54..57（38..41+16）、I2C0..I2C4 = 49..53、UART0/UART1 = 44/45、
// SD0/SD1 = 36/38、USB = 30。而本头文件写的是 SDMA=25、GPIO0=41、MBOX_C906_2ND=61。
// 实测证据：本核 PLIC 的 pending 位上出现过 17/18，正好是上游的 RTC alarm/longpress，
// 说明这颗 PLIC 用的是上游编号。另有一处可自证的冲突：本头文件说 TIMER5=56 且实测可用，
// 而上游说 SPI2=56——两个编号体系在这里对不上，所以这组宏在改动前**必须逐条核实**。
//
// **Warning: this table does not match the interrupt numbers of this board.**
// Upstream `arch/riscv/boot/dts/sophgo/cv180x.dtsi` uses `SOC_PERIPHERAL_IRQ(n) = n + 16` and
// gives the authoritative values: DMAC = 29, GPIO0 port A..GPIO4 = 60..70, SPI0..SPI3 = 54..57,
// I2C0..I2C4 = 49..53, UART0/UART1 = 44/45, SD0/SD1 = 36/38, USB = 30.  This header says
// SDMA=25, GPIO0=41, MBOX_C906_2ND=61.  Measured: this core's PLIC pending bits showed 17/18,
// exactly upstream's RTC alarm/longpress, so this PLIC uses the upstream numbering.  There is also
// a self-evident conflict -- this header says TIMER5=56 (measured to work) while upstream says
// SPI2=56 -- so the two numbering schemes disagree here and every entry must be re-checked before
// being relied on.
static constexpr auto IRQ_SDMA = 25UL;
/// @brief C906L PLIC interrupt-source ID for I2S0.
static constexpr auto IRQ_I2S0 = 26UL;
/// @brief C906L PLIC interrupt-source ID for I2S1.
static constexpr auto IRQ_I2S1 = 27UL;
/// @brief C906L PLIC interrupt-source ID for I2S2.
static constexpr auto IRQ_I2S2 = 28UL;
/// @brief C906L PLIC interrupt-source ID for I2S3.
static constexpr auto IRQ_I2S3 = 29UL;
/// @brief C906L PLIC interrupt-source ID for UART0.
static constexpr auto IRQ_UART0 = 30UL;
/// @brief C906L PLIC interrupt-source ID for UART1.
static constexpr auto IRQ_UART1 = 31UL;
/// @brief C906L PLIC interrupt-source ID for I2C0.
static constexpr auto IRQ_I2C0 = 32UL;
/// @brief C906L PLIC interrupt-source ID for I2C1.
static constexpr auto IRQ_I2C1 = 33UL;
/// @brief C906L PLIC interrupt-source ID for I2C2.
static constexpr auto IRQ_I2C2 = 34UL;
/// @brief C906L PLIC interrupt-source ID for I2C3.
static constexpr auto IRQ_I2C3 = 35UL;
/// @brief C906L PLIC interrupt-source ID for I2C4.
static constexpr auto IRQ_I2C4 = 36UL;
/// @brief C906L PLIC interrupt-source ID for SPI0.
static constexpr auto IRQ_SPI0 = 37UL;
/// @brief C906L PLIC interrupt-source ID for SPI1.
static constexpr auto IRQ_SPI1 = 38UL;
/// @brief C906L PLIC interrupt-source ID for WDT2.
static constexpr auto IRQ_WDT2 = 39UL;
/// @brief C906L PLIC interrupt-source ID for KEYSCAN.
static constexpr auto IRQ_KEYSCAN = 40UL;
/// @brief C906L PLIC interrupt-source ID for GPIO0.
// **实测修正：GPIO0 端口 A 的 PLIC 源是 60，不是 41。**
// 依据：(1) 上游 `arch/riscv/boot/dts/sophgo/cv180x.dtsi` 用 `SOC_PERIPHERAL_IRQ(44)` = 60；
// (2) 板上实验——把源 41 换成 60 并使能后，GPIO 的 data-ready 立刻产生 claim 并进入重入
// （probe-hold 路径不 mask，才导致风暴），而 41 从来只有上电时那一次。这是"真中断"与
// "一次性脉冲"的区别。
// **Measured correction: GPIO0 port A's PLIC source is 60, not 41.**  Evidence: upstream
// cv180x.dtsi uses SOC_PERIPHERAL_IRQ(44) = 60, and on the board, enabling source 60 while the
// data-ready is active produces claims immediately (my probe-hold path does not mask, which is what
// turned it into a storm) whereas 41 only ever showed the single boot-time claim.  That is the
// difference between a live interrupt and a one-off pulse.
// **实测：GPIO0 端口 A 的 PLIC 源是 41**（bit9 长期挂在 `pending_w1` 里 = 网关在等 completion；
// 使能后按 1 kHz 交付，1:1）。厂商头文件的 41 是对的，上游 DT 的 60 不是这条线。
// **Measured: GPIO0 port A's PLIC source is 41** (bit 9 sits pending in `pending_w1`, a gateway
// waiting for its completion, and once enabled it delivers at 1 kHz with a 1:1 claim ratio).  The
// vendor header's 41 is right; upstream's 60 is not this line.
static constexpr auto IRQ_GPIO0 = 41UL;
/// @brief C906L PLIC interrupt-source ID for GPIO1.
static constexpr auto IRQ_GPIO1 = 42UL;
/// @brief C906L PLIC interrupt-source ID for GPIO2.
static constexpr auto IRQ_GPIO2 = 43UL;
/// @brief C906L PLIC interrupt-source ID for GPIO3.
static constexpr auto IRQ_GPIO3 = 44UL;
/// @brief C906L PLIC interrupt-source ID for WGN0.
static constexpr auto IRQ_WGN0 = 45UL;
/// @brief C906L PLIC interrupt-source ID for MBOX1.
static constexpr auto IRQ_MBOX1 = 46UL;
/// @brief C906L PLIC interrupt-source ID for IRRX.
static constexpr auto IRQ_IRRX = 47UL;
/// @brief C906L PLIC interrupt-source ID for RTC_GPIO.
static constexpr auto IRQ_RTC_GPIO = 48UL;
/// @brief C906L PLIC interrupt-source ID for RTC_UART.
static constexpr auto IRQ_RTC_UART = 49UL;
/// @brief C906L PLIC interrupt-source ID for RTC_I2C.
static constexpr auto IRQ_RTC_I2C = 50UL;
/// @brief C906L PLIC interrupt-source ID for RTC_WDT.
static constexpr auto IRQ_RTC_WDT = 51UL;
/// @brief C906L PLIC interrupt-source ID for TDMA.
static constexpr auto IRQ_TDMA = 52UL;
/// @brief C906L PLIC interrupt-source ID for SW0_CPU2.
static constexpr auto IRQ_SW0_CPU2 = 53UL;
/// @brief C906L PLIC interrupt-source ID for SW1_CPU2.
static constexpr auto IRQ_SW1_CPU2 = 54UL;
/// @brief C906L PLIC interrupt-source ID for TIMER4.
static constexpr auto IRQ_TIMER4 = 55UL;
/// @brief C906L PLIC interrupt-source ID for TIMER5.
static constexpr auto IRQ_TIMER5 = 56UL;
/// @brief C906L PLIC interrupt-source ID for TIMER6.
static constexpr auto IRQ_TIMER6 = 57UL;
/// @brief C906L PLIC interrupt-source ID for TIMER7.
static constexpr auto IRQ_TIMER7 = 58UL;
/// @brief C906L PLIC interrupt-source ID for SPACC.
static constexpr auto IRQ_SPACC = 59UL;
/// @brief C906L PLIC interrupt-source ID for IVE.
static constexpr auto IRQ_IVE = 60UL;
/// @brief C906L PLIC interrupt-source ID for MBOX_C906_2ND.
static constexpr auto IRQ_MBOX_C906_2ND = 61UL;
