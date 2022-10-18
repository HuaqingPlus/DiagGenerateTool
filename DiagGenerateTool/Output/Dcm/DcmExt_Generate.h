/*********************************************************************/
/*                       DiagTool.Generate Start                     */
/*                       Generate Data: 2022-10-18 14:21:26          */
/*                       Author: QHQ                                 */
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
#define PID_F190		((uint16)0xF190)
#define PID_F193		((uint16)0xF193)
#define PID_F195		((uint16)0xF195)
#define PID_F1B1		((uint16)0xF1B1)
#define PID_F187		((uint16)0xF187)
#define PID_F18A		((uint16)0xF18A)
#define PID_F18C		((uint16)0xF18C)
#define PID_F1A2		((uint16)0xF1A2)
#define PID_F1B5		((uint16)0xF1B5)
#define PID_F189		((uint16)0xF189)
#define PID_F1C0		((uint16)0xF1C0)
#define PID_F1C1		((uint16)0xF1C1)
#define PID_F299		((uint16)0xF299)
#define PID_F298		((uint16)0xF298)
#define PID_F297		((uint16)0xF297)

#ifndef DCM_TABLE_READ
#define DCM_TABLE_READ \
{PID_F195,		fdiag_app_F195_Read},\
{PID_F1B1,		fdiag_app_F1B1_Read},\
{PID_F187,		fdiag_app_F187_Read},\
{PID_F18A,		fdiag_app_F18A_Read},\
{PID_F18C,		fdiag_app_F18C_Read},\
{PID_F1A2,		fdiag_app_F1A2_Read},\
{PID_F1B5,		fdiag_app_F1B5_Read},\
{PID_F189,		fdiag_app_F189_Read},\
{PID_F1C0,		fdiag_app_F1C0_Read},\
{PID_F1C1,		fdiag_app_F1C1_Read},\
{PID_F299,		fdiag_app_F299_Read},\
{PID_F298,		fdiag_app_F298_Read},\
{PID_F297,		fdiag_app_F297_Read},\

#endif

#ifndef DCM_TABLE_WRITE
#define DCM_TABLE_WRITE \
{PID_A1A1,		fdiag_app_A1A1_Write},\
{PID_F190,		fdiag_app_F190_Write},\
{PID_F193,		fdiag_app_F193_Write},\
{PID_F1B1,		fdiag_app_F1B1_Write},\
{PID_F18C,		fdiag_app_F18C_Write},\
{PID_F299,		fdiag_app_F299_Write},\
{PID_F298,		fdiag_app_F298_Write},\
{PID_F297,		fdiag_app_F297_Write},\

#endif

#ifndef DCM_TABLE_IOCTRL
#define DCM_TABLE_IOCTRL \

#endif

#ifdef SERVICE_22_SUPPORTED
uint16 fdiag_app_F195_Read(uint8 Buff[]);
uint16 fdiag_app_F1B1_Read(uint8 Buff[]);
uint16 fdiag_app_F187_Read(uint8 Buff[]);
uint16 fdiag_app_F18A_Read(uint8 Buff[]);
uint16 fdiag_app_F18C_Read(uint8 Buff[]);
uint16 fdiag_app_F1A2_Read(uint8 Buff[]);
uint16 fdiag_app_F1B5_Read(uint8 Buff[]);
uint16 fdiag_app_F189_Read(uint8 Buff[]);
uint16 fdiag_app_F1C0_Read(uint8 Buff[]);
uint16 fdiag_app_F1C1_Read(uint8 Buff[]);
uint16 fdiag_app_F299_Read(uint8 Buff[]);
uint16 fdiag_app_F298_Read(uint8 Buff[]);
uint16 fdiag_app_F297_Read(uint8 Buff[]);

static const PID_RECORD diag_pid_table_rom[] = 
{
	DCM_TABLE_READ
	{0,NULL_PTR}
}; 
#endif

#ifdef SERVICE_2E_SUPPORTED
uint16 fdiag_app_A1A1_Write(uint8 Buff[]);
uint16 fdiag_app_F190_Write(uint8 Buff[]);
uint16 fdiag_app_F193_Write(uint8 Buff[]);
uint16 fdiag_app_F1B1_Write(uint8 Buff[]);
uint16 fdiag_app_F18C_Write(uint8 Buff[]);
uint16 fdiag_app_F299_Write(uint8 Buff[]);
uint16 fdiag_app_F298_Write(uint8 Buff[]);
uint16 fdiag_app_F297_Write(uint8 Buff[]);

static const PID_RECORD diag_write_pid_table_rom[] = 
{
	DCM_TABLE_WRITE
	{0,NULL_PTR}
}; 
#endif

#ifdef SERVICE_2F_SUPPORTED

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
/*                       DiagTool.Generate End                       */
/*                       Author: QHQ                                 */
/*********************************************************************/
