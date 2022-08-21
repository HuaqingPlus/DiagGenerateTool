/*****************************************************************
| System Includes
|----------------------------------------------------------------*/
#include <stddef.h>

/*****************************************************************
| Project Includes
|----------------------------------------------------------------*/
#include "dio.h"
#include "port.h"
#include "IoHwAb.h"
#include "IoHwAb_cfg.h"




/*****************************************************************
| Local Function
|----------------------------------------------------------------*/
static uint16_t IoHwAb_GetPinIndex(IoHwAb_LabelType Label);

void   IoHwAb_EnterPowerState(IoHwAb_PowerType Mode)
{
	switch(Mode)
	{
		case IoHwAb_PWR_COLDSTART:
			Port_Init(PORT_COLD_CFG);
			break;

		case IoHwAb_PWR_WARMSTART:
			Port_Init(PORT_WARM_CFG);
			break;

		case IoHwAb_PWR_STANDBY:
			Port_Init(PORT_STANDBY_CFG);
			break;

		case IoHwAb_PWR_SLEEP:
			Port_Init(PORT_SLEEP_CFG);
			break;

		default:
			/* Solve static check warning */
			break;
	}
}

IoHwAb_StdType IoHwAb_DioReadPin(IoHwAb_LabelType Label)
{
	uint16_t i;
	uint8_t port, pin;
	IoHwAb_StdType ret=IoHwAb_ERROR;
	Dio_LevelType dio_lv;

	i = IoHwAb_GetPinIndex(Label);
	if(i < PORT_TOTAL_PINS)
	{
		/* Check valid port & pin */
		port = (uint8_t)(Dio_ChannelConfig[i].pin >> 8);
		pin  = (uint8_t)Dio_ChannelConfig[i].pin;
		if((port < PORT_TOTAL_PORT) && (pin < PORT_MAX_PIN_PER_PORT))
		{
			dio_lv = Dio_ReadChannel(Dio_ChannelConfig[i].pin);
			if (dio_lv == DIO_HIGH)
			{
				ret = IoHwAb_DIO_HIGH;
			}
			else
			{
				ret = IoHwAb_DIO_LOW;
			}
		}
	}
	return ret;
}

void IoHwAb_DioWritePin(IoHwAb_LabelType Label, IoHwAb_StdType Level)
{
	uint16_t i;
	uint8_t port, pin;
	Dio_LevelType dio_lv;
	IoHwAb_LabelType pinlabel=Label;

	i = IoHwAb_GetPinIndex(pinlabel);
	if(i < PORT_TOTAL_PINS)
	{
		/* Check valid port & pin */
		port = (uint8_t)(Dio_ChannelConfig[i].pin >> 8);
		pin  = (uint8_t)Dio_ChannelConfig[i].pin;
		if((port < PORT_TOTAL_PORT) && (pin < PORT_MAX_PIN_PER_PORT))
		{
			if(Level == IoHwAb_DIO_HIGH)
			{
				dio_lv = DIO_HIGH;
			}
			else
			{
				dio_lv = DIO_LOW;
			}
			Dio_WriteChannel(Dio_ChannelConfig[i].pin, dio_lv);
		}
	}
}

IoHwAb_StdType IoHwAb_DioTogglePin(IoHwAb_LabelType Label)
{
	uint16_t i;
	uint8_t port, pin;
	IoHwAb_StdType ret=IoHwAb_ERROR;
	Dio_LevelType dio_lv;

	i = IoHwAb_GetPinIndex(Label);
	if(i < PORT_TOTAL_PINS)
	{
		/* Check valid port & pin */
		port = (uint8_t)(Dio_ChannelConfig[i].pin >> 8);
		pin  = (uint8_t)Dio_ChannelConfig[i].pin;
		if((port < PORT_TOTAL_PORT) && (pin < PORT_MAX_PIN_PER_PORT))
		{
			dio_lv = Dio_FlipChannel(Dio_ChannelConfig[i].pin);
			if (dio_lv == DIO_HIGH)
			{
				ret = IoHwAb_DIO_HIGH;
			}
			else
			{
				ret = IoHwAb_DIO_LOW;
			}

		}
	}
	return ret;
}

void IoHwAb_PortSetPinMode(IoHwAb_LabelType Label, IoHwAb_PinMuxType Mode)
{
	uint16_t i;
	uint8_t port, pin, skip=0;
	Dio_LevelType dio_lv;
	Port_PinModeType port_mode;

	i = IoHwAb_GetPinIndex(Label);
	if(i < PORT_TOTAL_PINS)
	{
		port = (uint8_t)(Dio_ChannelConfig[i].pin >> 8);
		pin  = (uint8_t)Dio_ChannelConfig[i].pin;
		if((port < PORT_TOTAL_PORT) && (pin < PORT_MAX_PIN_PER_PORT))
		{
			switch(Mode)
			{
				case IoHwAb_MUX_INT_RISE_EDGE:
					port_mode = PORT_MUX_INT_RISE_EDGE;
					break;

				case IoHwAb_MUX_INT_FAIL_EDGE:
					port_mode = PORT_MUX_INT_FAIL_EDGE;
					break;

				case IoHwAb_MUX_INT_BOTH_EDGE:
					port_mode = PORT_MUX_INT_BOTH_EDGE;
					break;

				case IoHwAb_MUX_INT_HIGH_LEVEL:
					port_mode = PORT_MUX_INT_HIGH_LEVEL;
					break;

				case IoHwAb_MUX_INT_LOW_LEVEL:
					port_mode = PORT_MUX_INT_LOW_LEVEL;
					break;

				default:
					skip = 1;
					break;
			}
			if(skip == 0)
			{
				Port_SetPinMode(Dio_ChannelConfig[i].portpin, port_mode);
			}
		}
	}
}


static uint16_t IoHwAb_GetPinIndex(IoHwAb_LabelType Label)
{
	uint16_t i;
	IoHwAb_LabelType pinlabel=Label;

	for(i=0; i<PORT_TOTAL_PINS; i++)
	{
		if(Dio_ChannelConfig[i].label == pinlabel)
		{
			break;
		}
	}

	return i;
}

void   IoHwAb_Init(void)
{
	IoHwAb_DioWritePin(IoHwAb_5V_EN_MCU_PIN,DIO_HIGH);
	IoHwAb_DioWritePin(IoHwAb_PMU_PWRON_PIN,DIO_LOW);
	IoHwAb_DioWritePin(IoHwAb_PMU_WAKEUP_PIN,DIO_LOW);
	IoHwAb_DioWritePin(IoHwAb_MCU_STAT_PIN,DIO_HIGH);
}

