/*********************************************************************/
/*                       DiagTool.Generate Start                     */
/*                       Generate Data: 2022-09-04 00:55:19          */
/*                       Author: QHQ                                 */
/*********************************************************************/

#ifndef __DCMEXT_GENERATE_C__
#define __DCMEXT_GENERATE_C__

#include "DcmExt.h"
#include "DcmExt_Generate.h"
#include "NvM.h"

#define E_OK        (0u)
#define E_NOT_OK    (1u)

/****************************************************************************/
/*                      !!! Don't Remove This Comment !!!                   */
/*                              User's Code Start                           */
/****************************************************************************/
//22 Read default data
static uint8 l_F187_Vehicle_PartNumber[13] = {0x34, 0x31, 0x33, 0x33, 0x39, 0x35, 0x38, 0x58, 0x39, 0x39, 0x33, 0x47, 0x41};
static uint8 l_F18A_Supplier_Number[5] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
static uint8 l_F18C_ECU_FlowNumber[20] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
static uint8 l_F193_Supplier_HardwareVersion[15] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
static uint8 l_F195_Supplier_SoftwareVersion[15] = {0x20, 0x22, 0x07, 0x21, 0x00, 0x00, 0x00, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
static uint8 l_F1A2_CanMatrix_Version[19] = {0x30, 0x30, 0x31, 0x30, 0x32, 0x34, 0x4D, 0x4D, 0x30, 0x31, 0x2D, 0x56, 0x33, 0x2E, 0x30, 0x2E, 0x31, 0x20, 0x20};
//static uint8 l_F190_VIN[17] = {0x4C, 0x58, 0x57, 0x59, 0x45, 0x50, 0x47, 0x32, 0x38, 0x4A, 0x48, 0x30, 0x30, 0x31, 0x37, 0x35, 0x32};
static uint8 l_F1B5_System_Name[4] = {0x45, 0x49, 0x44, 0x43};
static uint8 l_F189_App_SoftVersion[15] = {0x22, 0x07, 0x20, 0x01};
static uint8 l_F1C0_Calibration_SoftVersion[15] = {0x46, 0x46, 0x46, 0x46, 0x46, 0x46, 0x46, 0x46, 0x46, 0x46, 0x46, 0x46, 0x46, 0x46, 0x46};
static uint8 l_F1C1_Base_SoftVersion[15] = {0x46, 0x46, 0x46, 0x46, 0x46, 0x46, 0x46, 0x46, 0x46, 0x46, 0x46, 0x46, 0x46, 0x46, 0x46};

/****************************************************************************/
/*                        !!! Don't Remove This Comment !!!                 */
/*                                User's Code end                           */
/****************************************************************************/

#ifdef SERVICE_22_SUPPORTED
/****************************************************************************
Function Name     : fdiag_app_F195_Read
Description       : This function is used to read 
Invocation        : diagnosis_app 
Parameters        : None 
Return Value      : UINT8 
Critical Section  : None 
******************************************************************************/
uint16 fdiag_app_F195_Read(uint8 Buff[])
{ 
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code Start        */
/*********************************************/
	uint16 fl_DataLen = ((uint16)4);
	return (fl_DataLen);
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code end          */
/*********************************************/
} 

/****************************************************************************
Function Name     : fdiag_app_F1B1_Read
Description       : This function is used to read 
Invocation        : diagnosis_app 
Parameters        : None 
Return Value      : UINT8 
Critical Section  : None 
******************************************************************************/
uint16 fdiag_app_F1B1_Read(uint8 Buff[])
{ 
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code Start        */
/*********************************************/
	uint16 fl_DataLen = ((uint16)0);
	return (fl_DataLen);
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code end          */
/*********************************************/
} 

/****************************************************************************
Function Name     : fdiag_app_F187_Read
Description       : This function is used to read 
Invocation        : diagnosis_app 
Parameters        : None 
Return Value      : UINT8 
Critical Section  : None 
******************************************************************************/
uint16 fdiag_app_F187_Read(uint8 Buff[])
{ 
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code Start        */
/*********************************************/
	uint16 fl_DataLen = ((uint16)0);
	return (fl_DataLen);
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code end          */
/*********************************************/
} 

/****************************************************************************
Function Name     : fdiag_app_F18A_Read
Description       : This function is used to read 
Invocation        : diagnosis_app 
Parameters        : None 
Return Value      : UINT8 
Critical Section  : None 
******************************************************************************/
uint16 fdiag_app_F18A_Read(uint8 Buff[])
{ 
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code Start        */
/*********************************************/
	uint16 fl_DataLen = ((uint16)2000);
	return (fl_DataLen);
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code end          */
/*********************************************/
} 

/****************************************************************************
Function Name     : fdiag_app_F18C_Read
Description       : This function is used to read 
Invocation        : diagnosis_app 
Parameters        : None 
Return Value      : UINT8 
Critical Section  : None 
******************************************************************************/
uint16 fdiag_app_F18C_Read(uint8 Buff[])
{ 
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code Start        */
/*********************************************/
	uint16 fl_DataLen = ((uint16)1000);
	return (fl_DataLen);
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code end          */
/*********************************************/
} 

/****************************************************************************
Function Name     : fdiag_app_F1A2_Read
Description       : This function is used to read 
Invocation        : diagnosis_app 
Parameters        : None 
Return Value      : UINT8 
Critical Section  : None 
******************************************************************************/
uint16 fdiag_app_F1A2_Read(uint8 Buff[])
{ 
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code Start        */
/*********************************************/
	uint16 fl_DataLen = ((uint16)13);
	return (fl_DataLen);
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code end          */
/*********************************************/
} 

/****************************************************************************
Function Name     : fdiag_app_F1B5_Read
Description       : This function is used to read 
Invocation        : diagnosis_app 
Parameters        : None 
Return Value      : UINT8 
Critical Section  : None 
******************************************************************************/
uint16 fdiag_app_F1B5_Read(uint8 Buff[])
{ 
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code Start        */
/*********************************************/
	uint16 fl_DataLen = ((uint16)4);
	return (fl_DataLen);
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code end          */
/*********************************************/
} 

/****************************************************************************
Function Name     : fdiag_app_F189_Read
Description       : This function is used to read 
Invocation        : diagnosis_app 
Parameters        : None 
Return Value      : UINT8 
Critical Section  : None 
******************************************************************************/
uint16 fdiag_app_F189_Read(uint8 Buff[])
{ 
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code Start        */
/*********************************************/
	uint16 fl_DataLen = ((uint16)0);
	return (fl_DataLen);
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code end          */
/*********************************************/
} 

/****************************************************************************
Function Name     : fdiag_app_F1C0_Read
Description       : This function is used to read 
Invocation        : diagnosis_app 
Parameters        : None 
Return Value      : UINT8 
Critical Section  : None 
******************************************************************************/
uint16 fdiag_app_F1C0_Read(uint8 Buff[])
{ 
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code Start        */
/*********************************************/
	uint16 fl_DataLen = ((uint16)0);
	return (fl_DataLen);
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code end          */
/*********************************************/
} 

/****************************************************************************
Function Name     : fdiag_app_F1C1_Read
Description       : This function is used to read 
Invocation        : diagnosis_app 
Parameters        : None 
Return Value      : UINT8 
Critical Section  : None 
******************************************************************************/
uint16 fdiag_app_F1C1_Read(uint8 Buff[])
{ 
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code Start        */
/*********************************************/
	uint16 fl_DataLen = ((uint16)0);
	return (fl_DataLen);
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code end          */
/*********************************************/
} 

/****************************************************************************
Function Name     : fdiag_app_F299_Read
Description       : This function is used to read 
Invocation        : diagnosis_app 
Parameters        : None 
Return Value      : UINT8 
Critical Section  : None 
******************************************************************************/
uint16 fdiag_app_F299_Read(uint8 Buff[])
{ 
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code Start        */
/*********************************************/
	uint16 fl_DataLen = ((uint16)4);
	return (fl_DataLen);
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code end          */
/*********************************************/
} 

/****************************************************************************
Function Name     : fdiag_app_F298_Read
Description       : This function is used to read 
Invocation        : diagnosis_app 
Parameters        : None 
Return Value      : UINT8 
Critical Section  : None 
******************************************************************************/
uint16 fdiag_app_F298_Read(uint8 Buff[])
{ 
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code Start        */
/*********************************************/
	uint16 fl_DataLen = ((uint16)10);
	return (fl_DataLen);
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code end          */
/*********************************************/
} 

/****************************************************************************
Function Name     : fdiag_app_F297_Read
Description       : This function is used to read 
Invocation        : diagnosis_app 
Parameters        : None 
Return Value      : UINT8 
Critical Section  : None 
******************************************************************************/
uint16 fdiag_app_F297_Read(uint8 Buff[])
{ 
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code Start        */
/*********************************************/
	uint16 fl_DataLen = ((uint16)2);
	return (fl_DataLen);
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code end          */
/*********************************************/
} 

#endif

#ifdef SERVICE_2E_SUPPORTED
/****************************************************************************
Function Name     : fdiag_app_A1A1_Write
Description       : This function is used to write 
Invocation        : diagnosis_app 
Parameters        : None 
Return Value      : UINT8 
Critical Section  : None 
******************************************************************************/
uint16 fdiag_app_A1A1_Write(uint8 Buff[])
{ 
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code Start        */
/*********************************************/
	uint16 fl_DataLen = ((uint16)0);
	return (fl_DataLen);
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code end          */
/*********************************************/
} 

/****************************************************************************
Function Name     : fdiag_app_F190_Write
Description       : This function is used to write 
Invocation        : diagnosis_app 
Parameters        : None 
Return Value      : UINT8 
Critical Section  : None 
******************************************************************************/
uint16 fdiag_app_F190_Write(uint8 Buff[])
{ 
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code Start        */
/*********************************************/
	uint16 fl_DataLen = ((uint16)11);
	return (fl_DataLen);
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code end          */
/*********************************************/
} 

/****************************************************************************
Function Name     : fdiag_app_F193_Write
Description       : This function is used to write 
Invocation        : diagnosis_app 
Parameters        : None 
Return Value      : UINT8 
Critical Section  : None 
******************************************************************************/
uint16 fdiag_app_F193_Write(uint8 Buff[])
{ 
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code Start        */
/*********************************************/
	uint16 fl_DataLen = ((uint16)0);
	return (fl_DataLen);
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code end          */
/*********************************************/
} 

/****************************************************************************
Function Name     : fdiag_app_F1B1_Write
Description       : This function is used to write 
Invocation        : diagnosis_app 
Parameters        : None 
Return Value      : UINT8 
Critical Section  : None 
******************************************************************************/
uint16 fdiag_app_F1B1_Write(uint8 Buff[])
{ 
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code Start        */
/*********************************************/
	uint16 fl_DataLen = ((uint16)0);
	return (fl_DataLen);
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code end          */
/*********************************************/
} 

/****************************************************************************
Function Name     : fdiag_app_F18C_Write
Description       : This function is used to write 
Invocation        : diagnosis_app 
Parameters        : None 
Return Value      : UINT8 
Critical Section  : None 
******************************************************************************/
uint16 fdiag_app_F18C_Write(uint8 Buff[])
{ 
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code Start        */
/*********************************************/
	uint16 fl_DataLen = ((uint16)1000);
	return (fl_DataLen);
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code end          */
/*********************************************/
} 

/****************************************************************************
Function Name     : fdiag_app_F299_Write
Description       : This function is used to write 
Invocation        : diagnosis_app 
Parameters        : None 
Return Value      : UINT8 
Critical Section  : None 
******************************************************************************/
uint16 fdiag_app_F299_Write(uint8 Buff[])
{ 
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code Start        */
/*********************************************/
	uint16 fl_DataLen = ((uint16)4);
	return (fl_DataLen);
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code end          */
/*********************************************/
} 

/****************************************************************************
Function Name     : fdiag_app_F298_Write
Description       : This function is used to write 
Invocation        : diagnosis_app 
Parameters        : None 
Return Value      : UINT8 
Critical Section  : None 
******************************************************************************/
uint16 fdiag_app_F298_Write(uint8 Buff[])
{ 
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code Start        */
/*********************************************/
	uint16 fl_DataLen = ((uint16)10);
	return (fl_DataLen);
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code end          */
/*********************************************/
} 

/****************************************************************************
Function Name     : fdiag_app_F297_Write
Description       : This function is used to write 
Invocation        : diagnosis_app 
Parameters        : None 
Return Value      : UINT8 
Critical Section  : None 
******************************************************************************/
uint16 fdiag_app_F297_Write(uint8 Buff[])
{ 
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code Start        */
/*********************************************/
	uint16 fl_DataLen = ((uint16)2);
	return (fl_DataLen);
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code end          */
/*********************************************/
} 

#endif

#ifdef SERVICE_2F_SUPPORTED
#endif

#ifdef SERVICE_31_SUPPORTED
/****************************************************************************
Function Name     : ApplDiagStart_0202_RotineControl
Description       : This function is used to Start Routine 
Invocation        : diagnosis_app 
Parameters        : None 
Return Value      : uint8, uint16* 
Critical Section  : None 
******************************************************************************/
uint8 ApplDiagStart_0202_RotineControl(uint8 p_diag_buf_U8A[],uint16 *p_resdatalen_ptr) 
{ 
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code Start        */
/*********************************************/
	return (E_OK);
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code end          */
/*********************************************/
} 

/****************************************************************************
Function Name     : ApplDiagResults_0202_RotineControl
Description       : This function is used to get routine result  
Invocation        : diagnosis_app 
Parameters        : None 
Return Value      : uint8, uint16* 
Critical Section  : None 
******************************************************************************/
uint8 ApplDiagResults_0202_RotineControl(uint8 p_diag_buf_U8A[],uint16 *p_resdatalen_ptr) 
{ 
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code Start        */
/*********************************************/
	return (E_OK);
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code end          */
/*********************************************/
} 

/****************************************************************************
Function Name     : ApplDiagStatus_0202_RotineControl
Description       : This function is used to get routine status 
Invocation        : diagnosis_app 
Parameters        : None 
Return Value      : boolean 
Critical Section  : None 
******************************************************************************/
boolean ApplDiagStatus_0202_RotineControl(void) 
{ 
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code Start        */
/*********************************************/
	return (TRUE);
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code end          */
/*********************************************/
} 

/****************************************************************************
Function Name     : ApplDiagTerminal_0202_RotineControl
Description       : This function is used to Stop Routine 
Invocation        : diagnosis_app 
Parameters        : None 
Return Value      : void 
Critical Section  : None 
******************************************************************************/
void ApplDiagTerminal_0202_RotineControl(void)
{ 
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code Start        */
/*********************************************/
	return;
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code end          */
/*********************************************/
} 

/****************************************************************************
Function Name     : ApplDiagStart_0203_RotineControl
Description       : This function is used to Start Routine 
Invocation        : diagnosis_app 
Parameters        : None 
Return Value      : uint8, uint16* 
Critical Section  : None 
******************************************************************************/
uint8 ApplDiagStart_0203_RotineControl(uint8 p_diag_buf_U8A[],uint16 *p_resdatalen_ptr) 
{ 
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code Start        */
/*********************************************/
	return (E_OK);
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code end          */
/*********************************************/
} 

/****************************************************************************
Function Name     : ApplDiagResults_0203_RotineControl
Description       : This function is used to get routine result  
Invocation        : diagnosis_app 
Parameters        : None 
Return Value      : uint8, uint16* 
Critical Section  : None 
******************************************************************************/
uint8 ApplDiagResults_0203_RotineControl(uint8 p_diag_buf_U8A[],uint16 *p_resdatalen_ptr) 
{ 
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code Start        */
/*********************************************/
	return (E_OK);
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code end          */
/*********************************************/
} 

/****************************************************************************
Function Name     : ApplDiagStatus_0203_RotineControl
Description       : This function is used to get routine status 
Invocation        : diagnosis_app 
Parameters        : None 
Return Value      : boolean 
Critical Section  : None 
******************************************************************************/
boolean ApplDiagStatus_0203_RotineControl(void) 
{ 
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code Start        */
/*********************************************/
	return (TRUE);
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code end          */
/*********************************************/
} 

/****************************************************************************
Function Name     : ApplDiagTerminal_0203_RotineControl
Description       : This function is used to Stop Routine 
Invocation        : diagnosis_app 
Parameters        : None 
Return Value      : void 
Critical Section  : None 
******************************************************************************/
void ApplDiagTerminal_0203_RotineControl(void)
{ 
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code Start        */
/*********************************************/
	return;
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code end          */
/*********************************************/
} 

/****************************************************************************
Function Name     : ApplDiagStart_ff01_RotineControl
Description       : This function is used to Start Routine 
Invocation        : diagnosis_app 
Parameters        : None 
Return Value      : uint8, uint16* 
Critical Section  : None 
******************************************************************************/
uint8 ApplDiagStart_ff01_RotineControl(uint8 p_diag_buf_U8A[],uint16 *p_resdatalen_ptr) 
{ 
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code Start        */
/*********************************************/
	return (E_OK);
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code end          */
/*********************************************/
} 

/****************************************************************************
Function Name     : ApplDiagResults_ff01_RotineControl
Description       : This function is used to get routine result  
Invocation        : diagnosis_app 
Parameters        : None 
Return Value      : uint8, uint16* 
Critical Section  : None 
******************************************************************************/
uint8 ApplDiagResults_ff01_RotineControl(uint8 p_diag_buf_U8A[],uint16 *p_resdatalen_ptr) 
{ 
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code Start        */
/*********************************************/
	return (E_OK);
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code end          */
/*********************************************/
} 

/****************************************************************************
Function Name     : ApplDiagStatus_ff01_RotineControl
Description       : This function is used to get routine status 
Invocation        : diagnosis_app 
Parameters        : None 
Return Value      : boolean 
Critical Section  : None 
******************************************************************************/
boolean ApplDiagStatus_ff01_RotineControl(void) 
{ 
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code Start        */
/*********************************************/
	return (TRUE);
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code end          */
/*********************************************/
} 

/****************************************************************************
Function Name     : ApplDiagTerminal_ff01_RotineControl
Description       : This function is used to Stop Routine 
Invocation        : diagnosis_app 
Parameters        : None 
Return Value      : void 
Critical Section  : None 
******************************************************************************/
void ApplDiagTerminal_ff01_RotineControl(void)
{ 
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code Start        */
/*********************************************/
	return;
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code end          */
/*********************************************/
} 

/****************************************************************************
Function Name     : ApplDiagStart_f103_RotineControl
Description       : This function is used to Start Routine 
Invocation        : diagnosis_app 
Parameters        : None 
Return Value      : uint8, uint16* 
Critical Section  : None 
******************************************************************************/
uint8 ApplDiagStart_f103_RotineControl(uint8 p_diag_buf_U8A[],uint16 *p_resdatalen_ptr) 
{ 
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code Start        */
/*********************************************/
	return (E_OK);
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code end          */
/*********************************************/
} 

/****************************************************************************
Function Name     : ApplDiagResults_f103_RotineControl
Description       : This function is used to get routine result  
Invocation        : diagnosis_app 
Parameters        : None 
Return Value      : uint8, uint16* 
Critical Section  : None 
******************************************************************************/
uint8 ApplDiagResults_f103_RotineControl(uint8 p_diag_buf_U8A[],uint16 *p_resdatalen_ptr) 
{ 
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code Start        */
/*********************************************/
	return (E_OK);
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code end          */
/*********************************************/
} 

/****************************************************************************
Function Name     : ApplDiagStatus_f103_RotineControl
Description       : This function is used to get routine status 
Invocation        : diagnosis_app 
Parameters        : None 
Return Value      : boolean 
Critical Section  : None 
******************************************************************************/
boolean ApplDiagStatus_f103_RotineControl(void) 
{ 
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code Start        */
/*********************************************/
	return (TRUE);
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code end          */
/*********************************************/
} 

/****************************************************************************
Function Name     : ApplDiagTerminal_f103_RotineControl
Description       : This function is used to Stop Routine 
Invocation        : diagnosis_app 
Parameters        : None 
Return Value      : void 
Critical Section  : None 
******************************************************************************/
void ApplDiagTerminal_f103_RotineControl(void)
{ 
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code Start        */
/*********************************************/
	return;
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code end          */
/*********************************************/
} 

/****************************************************************************
Function Name     : ApplDiagStart_f104_RotineControl
Description       : This function is used to Start Routine 
Invocation        : diagnosis_app 
Parameters        : None 
Return Value      : uint8, uint16* 
Critical Section  : None 
******************************************************************************/
uint8 ApplDiagStart_f104_RotineControl(uint8 p_diag_buf_U8A[],uint16 *p_resdatalen_ptr) 
{ 
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code Start        */
/*********************************************/
	return (E_OK);
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code end          */
/*********************************************/
} 

/****************************************************************************
Function Name     : ApplDiagResults_f104_RotineControl
Description       : This function is used to get routine result  
Invocation        : diagnosis_app 
Parameters        : None 
Return Value      : uint8, uint16* 
Critical Section  : None 
******************************************************************************/
uint8 ApplDiagResults_f104_RotineControl(uint8 p_diag_buf_U8A[],uint16 *p_resdatalen_ptr) 
{ 
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code Start        */
/*********************************************/
	return (E_OK);
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code end          */
/*********************************************/
} 

/****************************************************************************
Function Name     : ApplDiagStatus_f104_RotineControl
Description       : This function is used to get routine status 
Invocation        : diagnosis_app 
Parameters        : None 
Return Value      : boolean 
Critical Section  : None 
******************************************************************************/
boolean ApplDiagStatus_f104_RotineControl(void) 
{ 
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code Start        */
/*********************************************/
	return (TRUE);
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code end          */
/*********************************************/
} 

/****************************************************************************
Function Name     : ApplDiagTerminal_f104_RotineControl
Description       : This function is used to Stop Routine 
Invocation        : diagnosis_app 
Parameters        : None 
Return Value      : void 
Critical Section  : None 
******************************************************************************/
void ApplDiagTerminal_f104_RotineControl(void)
{ 
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code Start        */
/*********************************************/
	return;
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code end          */
/*********************************************/
} 

/****************************************************************************
Function Name     : ApplDiagStart_f11e_RotineControl
Description       : This function is used to Start Routine 
Invocation        : diagnosis_app 
Parameters        : None 
Return Value      : uint8, uint16* 
Critical Section  : None 
******************************************************************************/
uint8 ApplDiagStart_f11e_RotineControl(uint8 p_diag_buf_U8A[],uint16 *p_resdatalen_ptr) 
{ 
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code Start        */
/*********************************************/
	return (E_OK);
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code end          */
/*********************************************/
} 

/****************************************************************************
Function Name     : ApplDiagResults_f11e_RotineControl
Description       : This function is used to get routine result  
Invocation        : diagnosis_app 
Parameters        : None 
Return Value      : uint8, uint16* 
Critical Section  : None 
******************************************************************************/
uint8 ApplDiagResults_f11e_RotineControl(uint8 p_diag_buf_U8A[],uint16 *p_resdatalen_ptr) 
{ 
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code Start        */
/*********************************************/
	return (E_OK);
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code end          */
/*********************************************/
} 

/****************************************************************************
Function Name     : ApplDiagStatus_f11e_RotineControl
Description       : This function is used to get routine status 
Invocation        : diagnosis_app 
Parameters        : None 
Return Value      : boolean 
Critical Section  : None 
******************************************************************************/
boolean ApplDiagStatus_f11e_RotineControl(void) 
{ 
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code Start        */
/*********************************************/
	return (TRUE);
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code end          */
/*********************************************/
} 

/****************************************************************************
Function Name     : ApplDiagTerminal_f11e_RotineControl
Description       : This function is used to Stop Routine 
Invocation        : diagnosis_app 
Parameters        : None 
Return Value      : void 
Critical Section  : None 
******************************************************************************/
void ApplDiagTerminal_f11e_RotineControl(void)
{ 
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code Start        */
/*********************************************/
	return;
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code end          */
/*********************************************/
} 

#endif



#endif
/*********************************************************************/
/*                       DiagTool.Generate End                       */
/*                       Author: QHQ                                 */
/*********************************************************************/
