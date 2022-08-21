/*********************************************************************/
/*                       DiagTool.Generate Start                     */
/*********************************************************************/

#ifndef __DCMEXT_GENERATE_C__
#define __DCMEXT_GENERATE_C__

#include "DcmExt.h"
#include "DcmExt_Generate.h"

#define E_OK		(0u)

/****************************************************************************/
/*                      !!! Don't Remove This Comment !!!                   */
/*                              User's Code Start                           */
/****************************************************************************/
//22 Read data
static uint8 l_F193_HardWare_Version[4] = {0x00, 0x00, 0x00, 0xA1};
static uint8 l_F195_SoftWare_Version[4] = {0x22, 0x06, 0x24, 0x02};

/****************************************************************************/
/*                        !!! Don't Remove This Comment !!!                 */
/*                                User's Code end                           */
/****************************************************************************/

#ifdef SERVICE_22_SUPPORTED
/****************************************************************************
Function Name     : fdiag_app_A1A1_Read
Description       : This function is used to read 
Invocation        : diagnosis_app 
Parameters        : None 
Return Value      : UINT8 
Critical Section  : None 
******************************************************************************/
uint8 fdiag_app_A1A1_Read(uint8 Buff[])
{ 
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code Start        */
/*********************************************/
	uint8 fl_DataLen = ((uint8)10);
	return (fl_DataLen);
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code end          */
/*********************************************/
} 

/****************************************************************************
Function Name     : fdiag_app_F193_Read
Description       : This function is used to read 
Invocation        : diagnosis_app 
Parameters        : None 
Return Value      : UINT8 
Critical Section  : None 
******************************************************************************/
uint8 fdiag_app_F193_Read(uint8 Buff[])
{ 
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code Start        */
/*********************************************/
	uint8 fl_DataLen = ((uint8)4);
	for(uint8 i = 0; i < 4; i++)
	{
		Buff[i] = l_F193_HardWare_Version[i];
	}
	return (fl_DataLen);
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code end          */
/*********************************************/
} 

/****************************************************************************
Function Name     : fdiag_app_F195_Read
Description       : This function is used to read 
Invocation        : diagnosis_app 
Parameters        : None 
Return Value      : UINT8 
Critical Section  : None 
******************************************************************************/
uint8 fdiag_app_F195_Read(uint8 Buff[])
{ 
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code Start        */
/*********************************************/
	uint8 fl_DataLen = ((uint8)4);
	for(uint8 i = 0; i < 4; i++)
	{
		Buff[i] = l_F195_SoftWare_Version[i];
	}
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
uint8 fdiag_app_A1A1_Write(uint8 Buff[])
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

#endif

#ifdef SERVICE_2F_SUPPORTED
/****************************************************************************
Function Name     : fdiag_app_F1B1_IOC
Description       : This function is used to control IO 
Invocation        : diagnosis_app 
Parameters        : None 
Return Value      : UINT8 
Critical Section  : None 
******************************************************************************/
uint8 fdiag_app_F1B1_IOC(uint8 fl_ctrl_parameter, uint8 *fl_get_ctrl_value)
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
/*                       DiagTool.Generate Stop                      */
/*********************************************************************/

