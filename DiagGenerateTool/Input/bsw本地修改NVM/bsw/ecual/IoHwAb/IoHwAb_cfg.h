#ifndef IOHWAB_CFG_H
#define IOHWAB_CFG_H


typedef struct {
	Port_PinType portpin;
	Dio_ChannelType pin;
	IoHwAb_LabelType label;
}Dio_ConfigType;

extern const Dio_ConfigType Dio_ChannelConfig[PORT_TOTAL_PINS];


#endif
