#ifndef IOHWAB_H
#define IOHWAB_H



/***********************************************************************************************************************************/
/** IoHwAb Typedef 																												   */
/***********************************************************************************************************************************/
typedef enum {IoHwAb_PWR_COLDSTART=0, IoHwAb_PWR_WARMSTART, IoHwAb_PWR_STANDBY, IoHwAb_PWR_SLEEP}IoHwAb_PowerType;
typedef enum {IoHwAb_DIO_LOW=0, IoHwAb_DIO_HIGH, IoHwAb_OK=0x80, IoHwAb_ERROR}IoHwAb_StdType;

typedef enum {
	/* Reserve Pins */
	IoHwAb_NC_PIN=0,
	/* JTAG Pins */
	IoHwAb_JTAG_TMS_PIN, IoHwAb_JTAG_RST_PIN, IoHwAb_JTAG_TDO_PIN, IoHwAb_JTAG_TCLK_PIN, IoHwAb_JTAG_TDI_PIN,
	IoHwAb_VBATT_AN_EN_PIN,IoHwAb_GPIO1_PIN,IoHwAb_WDI_PIN,IoHwAb_GPIO2_PIN,IoHwAb_PMU_PWRON_PIN,
	IoHwAb_PMU_WAKEUP_PIN,IoHwAb_DCDC1_AD_PIN,IoHwAb_SPI1_MOSI_PIN,IoHwAb_SPI1_MISO_PIN,IoHwAb_UART0_RX_PIN,
	IoHwAb_UART0_TX_PIN,IoHwAb_UART1_RX_PIN,IoHwAb_UART1_TX_PIN,IoHwAb_SPI1_CS0_PIN,IoHwAb_SPI1_CLK_PIN,
	IoHwAb_SK32_USB_ID_PIN,IoHwAb_VIN_AD_PIN,IoHwAb_VCC5V_AD_PIN,IoHwAb_PWR_EN_PIN,IoHwAb_5V_EN_MCU_PIN,
	IoHwAb_MCU_STAT_PIN,IoHwAb_SPI0_CLK_PIN,IoHwAb_SPI0_MOSI_PIN,IoHwAb_SPI0_MISO_PIN,IoHwAb_CAN0_RX,
	IoHwAb_CAN0_TX,IoHwAb_SPI0_CS0_PIN,IoHwAb_CAN_WAKE_PIN,IoHwAb_FEL_PIN,IoHwAb_SOC_RESET_PIN,
}IoHwAb_LabelType;

typedef enum {
	IoHwAb_MUX_DISABLE=0, IoHwAb_MUX_GPIO, IoHwAb_MUX_ADC, IoHwAb_MUX_PWMO, IoHwAb_MUX_PWMI,
	IoHwAb_MUX_I2C_SCL, IoHwAb_MUX_I2C_SDA,
	IoHwAb_MUX_INT_RISE_EDGE, IoHwAb_MUX_INT_FAIL_EDGE, IoHwAb_MUX_INT_BOTH_EDGE, IoHwAb_MUX_INT_HIGH_LEVEL, IoHwAb_MUX_INT_LOW_LEVEL,
	IoHwAb_MUX_UART_TX, IoHwAb_MUX_UART_RX, IoHwAb_MUX_UART_RTS, IoHwAb_MUX_UART_CTS,
	IoHwAb_MUX_SPI_CLK, IoHwAb_MUX_SPI_MISO, IoHwAb_MUX_SPI_MOSI, IoHwAb_MUX_SPI_CS,
	IoHwAb_MUX_CAN_RX, IoHwAb_MUX_CAN_TX,
}IoHwAb_PinMuxType;


extern void IoHwAb_Init(void);
extern void IoHwAb_EnterPowerState(IoHwAb_PowerType Mode);
/* DIO Abstraction API */
extern void IoHwAb_DioWritePin(IoHwAb_LabelType Label, IoHwAb_StdType Level);
extern IoHwAb_StdType  IoHwAb_DioReadPin(IoHwAb_LabelType Label);
extern IoHwAb_StdType  IoHwAb_DioTogglePin(IoHwAb_LabelType Label);
/* Port Abstraction API */
extern void IoHwAb_PortSetPinMode(IoHwAb_LabelType Label, IoHwAb_PinMuxType Mode);

#endif
