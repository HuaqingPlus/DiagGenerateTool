#ifndef __DCMEXT_GENERATE_H__
#define __DCMEXT_GENERATE_H__

#include "Std_Types.h"
/*********************************************************************/
/*                       DiagTool.Generate Start                     */
/*********************************************************************/
#define DID_0x2FDID_SIZE                          	(1u)
#define DID_0x2FDID_SIZE_2                          (2u)
#define DID_0x2FDID_SIZE_3                          (3u)
#define DID_0x2FDID_SIZE_4                          (4u)

/* PID Define */
#define Pid_A1A1		((uint16)0xA1A1)
#define Pid_F1B1		((uint16)0xF1B1)             

//Service Define
#define MODE_22_SUPPORTED
#define MODE_2E_SUPPORTED
#define MODE_2F_SUPPORTED

//Service22_Functions
#ifndef DCM_TABLE_READ
#define DCM_TABLE_READ \
/*0xA1A1*/	{Pid_A1A1		  			   ,fdiag_app_A1A1_Read		  	},\

#endif

//Service2E_Functions
#ifndef DCM_TABLE_WRITE
#define DCM_TABLE_WRITE \
/*0xA1A1*/	{Pid_A1A1		               ,fdiag_app_A1A1_Write	    },\

#endif

//Service2F_Functions
#ifndef DCM_TABLE_IOCTRL
#define DCM_TABLE_IOCTRL \
{	/*0xF1B1*/	\
	Pid_F1B1,\
	RETURN_CONTROL_ECU|FREEZE_CURRENT_STATE|RESET_TO_DEFAULT|SHORT_TERM_ADJUST,\
	DID_0x2FDID_SIZE_2,\
	NULL_PTR,\
	fdiag_app_F1B1_IOC,\
	NULL_PTR,\
},	\

#endif


#ifdef MODE_22_SUPPORTED
uint8 fdiag_app_A1A1_Read(uint8 Buff[]);

static const PID_RECORD diag_pid_table_rom[] =
{
    DCM_TABLE_READ
    {0,NULL_PTR}
};

#endif

#ifdef MODE_2E_SUPPORTED
uint8 fdiag_app_A1A1_Write(uint8 Buff[]);

static const PID_RECORD diag_write_pid_table_rom[] =
{
    DCM_TABLE_WRITE
    {0,NULL_PTR}
};

#endif

#ifdef MODE_2F_SUPPORTED
uint8 fdiag_app_F1B1_IOC(uint8 fl_ctrl_parameter, uint8 *fl_get_ctrl_value);

static const IOCTL_RECORD ioctl_diag_table_rom[] =
{
    DCM_TABLE_IOCTRL
    {0, 0, 0, NULL_PTR, NULL_PTR, NULL_PTR}
};
#endif

/*********************************************************************/
/*                       DiagTool.Generate Stop                      */
/*********************************************************************/

#endif
