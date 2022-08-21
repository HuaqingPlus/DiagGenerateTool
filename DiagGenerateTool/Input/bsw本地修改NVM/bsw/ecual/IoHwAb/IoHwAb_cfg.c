/*****************************************************************
| System Includes
|----------------------------------------------------------------*/
#include <stddef.h>
#include <stdint.h>


/*****************************************************************
| Project Includes
|----------------------------------------------------------------*/
#include "IoHwAb.h"
#include "port.h"
#include "dio.h"
#include "IoHwAb_cfg.h"



const Dio_ConfigType Dio_ChannelConfig[PORT_TOTAL_PINS] = {
		/* PORT A Pins*/
		{PORT_P0_0,	 DIO_P0_0,	IoHwAb_NC_PIN, 					},
		{PORT_P0_1,  DIO_P0_1, 	IoHwAb_WDI_PIN, 				},
		{PORT_P0_2,  DIO_P0_2, 	IoHwAb_VBATT_AN_EN_PIN,			},
		{PORT_P0_3,  DIO_P0_3, 	IoHwAb_NC_PIN,					},
		{PORT_P0_4,  DIO_P0_4, 	IoHwAb_JTAG_TMS_PIN,			},
		{PORT_P0_5,  DIO_P0_5, 	IoHwAb_JTAG_RST_PIN,			},
		{PORT_P0_6,  DIO_P0_6, 	IoHwAb_NC_PIN,					},
		{PORT_P0_7,  DIO_P0_7, 	IoHwAb_NC_PIN,					},
		{PORT_P0_8,  DIO_P0_8, 	IoHwAb_NC_PIN,					},
		{PORT_P0_9,  DIO_P0_9, 	IoHwAb_NC_PIN,					},
		{PORT_P0_10, DIO_P0_10, IoHwAb_JTAG_TDO_PIN,			},
		{PORT_P0_11, DIO_P0_11, IoHwAb_NC_PIN,					},
		{PORT_P0_12, DIO_P0_12, IoHwAb_NC_PIN,					},
		{PORT_P0_13, DIO_P0_13, IoHwAb_NC_PIN,					},
		{PORT_P0_14, DIO_P0_14, IoHwAb_NC_PIN,					},
		{PORT_P0_15, DIO_P0_15, IoHwAb_NC_PIN,					},
		{PORT_P0_16, DIO_P0_16, IoHwAb_NC_PIN,					},
		{PORT_P0_17, DIO_P0_17, IoHwAb_NC_PIN,					},
		/* PORT B Pins */
		{PORT_P1_0,	 DIO_P1_0, 	IoHwAb_GPIO1_PIN,				},
		{PORT_P1_1,  DIO_P1_1, 	IoHwAb_GPIO2_PIN,				},
		{PORT_P1_2,  DIO_P1_2, 	IoHwAb_PMU_PWRON_PIN,			},
		{PORT_P1_3,  DIO_P1_3, 	IoHwAb_PMU_WAKEUP_PIN,			},
		{PORT_P1_4,  DIO_P1_4, 	IoHwAb_NC_PIN,					},
		{PORT_P1_5,  DIO_P1_5, 	IoHwAb_NC_PIN,					},
		{PORT_P1_6,  DIO_P1_6, 	IoHwAb_NC_PIN,					},
		{PORT_P1_7,  DIO_P1_7, 	IoHwAb_NC_PIN,					},
		{PORT_P1_8,  DIO_P1_8, 	IoHwAb_NC_PIN,					},
		{PORT_P1_9,  DIO_P1_9, 	IoHwAb_NC_PIN,					},
		{PORT_P1_10, DIO_P1_10, IoHwAb_NC_PIN,					},
		{PORT_P1_11, DIO_P1_11, IoHwAb_NC_PIN,					},
		{PORT_P1_12, DIO_P1_12, IoHwAb_DCDC1_AD_PIN,			},
		{PORT_P1_13, DIO_P1_13, IoHwAb_NC_PIN,					},
		{PORT_P1_14, DIO_P1_14, IoHwAb_NC_PIN,					},
		{PORT_P1_15, DIO_P1_15, IoHwAb_NC_PIN,					},
		{PORT_P1_16, DIO_P1_16, IoHwAb_NC_PIN,					},
		{PORT_P1_17, DIO_P1_17, IoHwAb_NC_PIN,					},
		/* PORT C Pins */
		{PORT_P2_0,	 DIO_P2_0, 	IoHwAb_SPI1_MOSI_PIN,			},
		{PORT_P2_1,  DIO_P2_1, 	IoHwAb_SPI1_MISO_PIN,			},
		{PORT_P2_2,  DIO_P2_2, 	IoHwAb_UART0_RX_PIN,			},
		{PORT_P2_3,  DIO_P2_3, 	IoHwAb_UART0_TX_PIN,			},
		{PORT_P2_4,  DIO_P2_4, 	IoHwAb_JTAG_TCLK_PIN,			},
		{PORT_P2_5,  DIO_P2_5, 	IoHwAb_JTAG_TDI_PIN,			},
		{PORT_P2_6,  DIO_P2_6, 	IoHwAb_NC_PIN,					},
		{PORT_P2_7,  DIO_P2_7, 	IoHwAb_NC_PIN,					},
		{PORT_P2_8,  DIO_P2_8, 	IoHwAb_UART1_RX_PIN,			},
		{PORT_P2_9,  DIO_P2_9, 	IoHwAb_UART1_TX_PIN,			},
		{PORT_P2_10, DIO_P2_10, IoHwAb_NC_PIN,					},
		{PORT_P2_11, DIO_P2_11, IoHwAb_NC_PIN,					},
		{PORT_P2_12, DIO_P2_12, IoHwAb_NC_PIN,					},
		{PORT_P2_13, DIO_P2_13, IoHwAb_NC_PIN,					},
		{PORT_P2_14, DIO_P2_14, IoHwAb_SPI1_CS0_PIN,			},
		{PORT_P2_15, DIO_P2_15, IoHwAb_SPI1_CLK_PIN,			},
		{PORT_P2_16, DIO_P2_16, IoHwAb_NC_PIN,					},
		{PORT_P2_17, DIO_P2_17, IoHwAb_SK32_USB_ID_PIN,			},
		/* PORT D Pins */
		{PORT_P3_0,	 DIO_P3_0, 	IoHwAb_NC_PIN,					},
		{PORT_P3_1,  DIO_P3_1, 	IoHwAb_NC_PIN,					},
		{PORT_P3_2,  DIO_P3_2, 	IoHwAb_VIN_AD_PIN,				},
		{PORT_P3_3,  DIO_P3_3, 	IoHwAb_NC_PIN,					},
		{PORT_P3_4,  DIO_P3_4, 	IoHwAb_VCC5V_AD_PIN,			},
		{PORT_P3_5,  DIO_P3_5, 	IoHwAb_NC_PIN,					},
		{PORT_P3_6,  DIO_P3_6, 	IoHwAb_NC_PIN,					},
		{PORT_P3_7,  DIO_P3_7, 	IoHwAb_PWR_EN_PIN,			},
		{PORT_P3_8,  DIO_P3_8, 	IoHwAb_NC_PIN,					},
		{PORT_P3_9,  DIO_P3_9, 	IoHwAb_NC_PIN,					},
		{PORT_P3_10, DIO_P3_10, IoHwAb_NC_PIN,					},
		{PORT_P3_11, DIO_P3_11, IoHwAb_NC_PIN,					},
		{PORT_P3_12, DIO_P3_12, IoHwAb_NC_PIN,					},
		{PORT_P3_13, DIO_P3_13, IoHwAb_NC_PIN,					},
		{PORT_P3_14, DIO_P3_14, IoHwAb_NC_PIN,					},
		{PORT_P3_15, DIO_P3_15, IoHwAb_5V_EN_MCU_PIN,			},
		{PORT_P3_16, DIO_P3_16, IoHwAb_MCU_STAT_PIN,			},
		{PORT_P3_17, DIO_P3_17, IoHwAb_NC_PIN,					},
		/* PORT E Pins */
		{PORT_P4_0,	 DIO_P4_0, 	IoHwAb_SPI0_CLK_PIN,			},
		{PORT_P4_1,  DIO_P4_1, 	IoHwAb_SPI0_MOSI_PIN,			},
		{PORT_P4_2,  DIO_P4_2, 	IoHwAb_SPI0_MISO_PIN,			},
		{PORT_P4_3,  DIO_P4_3, 	IoHwAb_NC_PIN,					},
		{PORT_P4_4,  DIO_P4_4, 	IoHwAb_CAN0_RX,					},
		{PORT_P4_5,  DIO_P4_5, 	IoHwAb_CAN0_TX,					},
		{PORT_P4_6,  DIO_P4_6, 	IoHwAb_SPI0_CS0_PIN,			},
		{PORT_P4_7,  DIO_P4_7, 	IoHwAb_NC_PIN,					},
		{PORT_P4_8,  DIO_P4_8, 	IoHwAb_NC_PIN,					},
		{PORT_P4_9,  DIO_P4_9, 	IoHwAb_CAN_WAKE_PIN,			},
		{PORT_P4_10, DIO_P4_10, IoHwAb_FEL_PIN,					},
		{PORT_P4_11, DIO_P4_11, IoHwAb_SOC_RESET_PIN,			},
		{PORT_P4_12, DIO_P4_12, IoHwAb_NC_PIN,					},
		{PORT_P4_13, DIO_P4_13, IoHwAb_NC_PIN,					},
		{PORT_P4_14, DIO_P4_14, IoHwAb_NC_PIN,					},
		{PORT_P4_15, DIO_P4_15, IoHwAb_NC_PIN,					},
		{PORT_P4_16, DIO_P4_16, IoHwAb_NC_PIN,					},
};
