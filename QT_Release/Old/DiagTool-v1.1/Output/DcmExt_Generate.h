/*********************************************************************/
/*                       DiagTool.Generate Start                     */
/*********************************************************************/

#ifndef __DCMEXT_GENERATE_H__
#define __DCMEXT_GENERATE_H__

#include "Std_Types.h"

#define DID_0x2FDID_SIZE_2		 ((uint8)2)
#define DR_TIME_NOT_REQ		 ((uint32)0)
#define ROUTINE_TYPE_1		(0x01u)
#define ROUTINE_TYPE_2		(0x02u)
#define RC_STOP_SERVICE		(0x04u)
#define RC_SELFTEST		(0x10u)
#define NO_SPACE_AVAILABLE		(0xFF)
#define LHVSD_CHECK_NEEDED		(0xFF)
#define LHVSD_CHECK_NOT_NEEDED		(0x00)

#define SERVICE_22_SUPPORTED
#define SERVICE_2E_SUPPORTED
#define SERVICE_2F_SUPPORTED
#define SERVICE_31_SUPPORTED

//PID Define
#define PID_A1A1		((uint16)0xA1A1)
#define PID_F1B1		((uint16)0xF1B1)
#define PID_F193		((uint16)0xF193)
#define PID_F195		((uint16)0xF195)

#ifndef DCM_TABLE_READ
#define DCM_TABLE_READ \
{PID_A1A1,		fdiag_app_A1A1_Read},\
{PID_F193,		fdiag_app_F193_Read},\
{PID_F195,		fdiag_app_F195_Read},\

#endif

#ifndef DCM_TABLE_WRITE
#define DCM_TABLE_WRITE \
{PID_A1A1,		fdiag_app_A1A1_Write},\

#endif

#ifndef DCM_TABLE_IOCTRL
#define DCM_TABLE_IOCTRL \
{\
	PID_F1B1,\
	RETURN_CONTROL_ECU|FREEZE_CURRENT_STATE|RESET_TO_DEFAULT|SHORT_TERM_ADJUST,\
	DID_0x2FDID_SIZE_2,\
	NULL_PTR, \
	fdiag_app_F1B1_IOC, \
	NULL_PTR, \
},\

#endif

#ifdef SERVICE_22_SUPPORTED
uint8 fdiag_app_A1A1_Read(uint8 Buff[]);
uint8 fdiag_app_F193_Read(uint8 Buff[]);
uint8 fdiag_app_F195_Read(uint8 Buff[]);
static const PID_RECORD diag_pid_table_rom[] = 
{
	DCM_TABLE_READ
	{0,NULL_PTR}
}; 
#endif

#ifdef SERVICE_2E_SUPPORTED
uint8 fdiag_app_A1A1_Write(uint8 Buff[]);
static const PID_RECORD diag_write_pid_table_rom[] = 
{
	DCM_TABLE_WRITE
	{0,NULL_PTR}
}; 
#endif

#ifdef SERVICE_2F_SUPPORTED
uint8 fdiag_app_F1B1_IOC(uint8 fl_ctrl_parameter, uint8 *fl_get_ctrl_value);
static const IOCTL_RECORD ioctl_diag_table_rom[] = 
{
	DCM_TABLE_IOCTRL
	{0, 0, 0, NULL_PTR, NULL_PTR, NULL_PTR}
}; 
#endif

//RID Define
#define RID_0202		((uint16)0x0202)
#define RID_0203		((uint16)0x0203)
#define RID_FF01		((uint16)0xFF01)
#define RID_F103		((uint16)0xF103)
#define RID_F104		((uint16)0xF104)
#define RID_F11E		((uint16)0xF11E)

#ifndef DCM_TABLE_ROUTINE_CONTROL
#define DCM_TABLE_ROUTINE_CONTROL		\
{\
	DR_TIME_NOT_REQ,\
 	RID_0202,\
 	ROUTINE_TYPE_2 | RC_STOP_SERVICE,\
 	4,\
 	4,\
 	0,\
 	LHVSD_CHECK_NOT_NEEDED,\
 	ApplDiagStart_0202_RotineControl,\
 	ApplDiagResults_0202_RotineControl,\
 	ApplDiagStatus_0202_RotineControl,\
 	ApplDiagTerminal_0202_RotineControl\
}, \
{\
	DR_TIME_NOT_REQ,\
 	RID_0203,\
 	ROUTINE_TYPE_2 | RC_STOP_SERVICE,\
 	4,\
 	4,\
 	0,\
 	LHVSD_CHECK_NOT_NEEDED,\
 	ApplDiagStart_0203_RotineControl,\
 	ApplDiagResults_0203_RotineControl,\
 	ApplDiagStatus_0203_RotineControl,\
 	ApplDiagTerminal_0203_RotineControl\
}, \
{\
	DR_TIME_NOT_REQ,\
 	RID_FF01,\
 	ROUTINE_TYPE_2 | RC_STOP_SERVICE,\
 	4,\
 	4,\
 	0,\
 	LHVSD_CHECK_NOT_NEEDED,\
 	ApplDiagStart_ff01_RotineControl,\
 	ApplDiagResults_ff01_RotineControl,\
 	ApplDiagStatus_ff01_RotineControl,\
 	ApplDiagTerminal_ff01_RotineControl\
}, \
{\
	DR_TIME_NOT_REQ,\
 	RID_F103,\
 	ROUTINE_TYPE_2 | RC_STOP_SERVICE,\
 	4,\
 	4,\
 	0,\
 	LHVSD_CHECK_NOT_NEEDED,\
 	ApplDiagStart_f103_RotineControl,\
 	ApplDiagResults_f103_RotineControl,\
 	ApplDiagStatus_f103_RotineControl,\
 	ApplDiagTerminal_f103_RotineControl\
}, \
{\
	DR_TIME_NOT_REQ,\
 	RID_F104,\
 	ROUTINE_TYPE_2 | RC_STOP_SERVICE,\
 	4,\
 	4,\
 	0,\
 	LHVSD_CHECK_NOT_NEEDED,\
 	ApplDiagStart_f104_RotineControl,\
 	ApplDiagResults_f104_RotineControl,\
 	ApplDiagStatus_f104_RotineControl,\
 	ApplDiagTerminal_f104_RotineControl\
}, \
{\
	DR_TIME_NOT_REQ,\
 	RID_F11E,\
 	ROUTINE_TYPE_2 | RC_STOP_SERVICE,\
 	4,\
 	4,\
 	0,\
 	LHVSD_CHECK_NOT_NEEDED,\
 	ApplDiagStart_f11e_RotineControl,\
 	ApplDiagResults_f11e_RotineControl,\
 	ApplDiagStatus_f11e_RotineControl,\
 	ApplDiagTerminal_f11e_RotineControl\
}, \

#endif

#ifdef SERVICE_31_SUPPORTED
uint8 ApplDiagStart_0202_RotineControl(uint8 p_diag_buf_U8A[],uint16 *p_resdatalen_ptr); 
uint8 ApplDiagResults_0202_RotineControl(uint8 p_diag_buf_U8A[],uint16 *p_resdatalen_ptr); 
boolean ApplDiagStatus_0202_RotineControl(void); 
void ApplDiagTerminal_0202_RotineControl(void); 

uint8 ApplDiagStart_0203_RotineControl(uint8 p_diag_buf_U8A[],uint16 *p_resdatalen_ptr); 
uint8 ApplDiagResults_0203_RotineControl(uint8 p_diag_buf_U8A[],uint16 *p_resdatalen_ptr); 
boolean ApplDiagStatus_0203_RotineControl(void); 
void ApplDiagTerminal_0203_RotineControl(void); 

uint8 ApplDiagStart_ff01_RotineControl(uint8 p_diag_buf_U8A[],uint16 *p_resdatalen_ptr); 
uint8 ApplDiagResults_ff01_RotineControl(uint8 p_diag_buf_U8A[],uint16 *p_resdatalen_ptr); 
boolean ApplDiagStatus_ff01_RotineControl(void); 
void ApplDiagTerminal_ff01_RotineControl(void); 

uint8 ApplDiagStart_f103_RotineControl(uint8 p_diag_buf_U8A[],uint16 *p_resdatalen_ptr); 
uint8 ApplDiagResults_f103_RotineControl(uint8 p_diag_buf_U8A[],uint16 *p_resdatalen_ptr); 
boolean ApplDiagStatus_f103_RotineControl(void); 
void ApplDiagTerminal_f103_RotineControl(void); 

uint8 ApplDiagStart_f104_RotineControl(uint8 p_diag_buf_U8A[],uint16 *p_resdatalen_ptr); 
uint8 ApplDiagResults_f104_RotineControl(uint8 p_diag_buf_U8A[],uint16 *p_resdatalen_ptr); 
boolean ApplDiagStatus_f104_RotineControl(void); 
void ApplDiagTerminal_f104_RotineControl(void); 

uint8 ApplDiagStart_f11e_RotineControl(uint8 p_diag_buf_U8A[],uint16 *p_resdatalen_ptr); 
uint8 ApplDiagResults_f11e_RotineControl(uint8 p_diag_buf_U8A[],uint16 *p_resdatalen_ptr); 
boolean ApplDiagStatus_f11e_RotineControl(void); 
void ApplDiagTerminal_f11e_RotineControl(void); 

static RTN_CTRL_RECORD diag_routine_ctrl_table_rom[] = 
{
	DCM_TABLE_ROUTINE_CONTROL
	{0, 0, 0, 0, 0, 0, 0, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR}
}; 
#endif


#endif
/*********************************************************************/
/*                       DiagTool.Generate Stop                      */
/*********************************************************************/
