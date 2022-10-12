/*********************************************************************/
/*                       DiagTool.Generate Start                     */
/*                       Generate Data: 2022-10-12 18:08:40          */
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

Code1
code2
code3

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
uint16 fdiag_app_A1A1_Read(uint8 Buff[])
{ 
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code Start        */
/*********************************************/
	uint16 fl_DataLen = ((uint16)4);
	return (fl_DataLen);
	Code111
	code222
	code333
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
	uint16 fl_DataLen = ((uint16)4);
	return (fl_DataLen);
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code end          */
/*********************************************/
} 

#endif

#ifdef SERVICE_2F_SUPPORTED
/****************************************************************************
Function Name     : fdiag_app_B1B1_IOC
Description       : This function is used to control IO 
Invocation        : diagnosis_app 
Parameters        : None 
Return Value      : UINT8 
Critical Section  : None 
******************************************************************************/
uint8 fdiag_app_B1B1_IOC(uint8 fl_ctrl_parameter, uint8 *fl_get_ctrl_value)
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
Function Name     : ApplDiagStart_f101_RotineControl
Description       : This function is used to Start Routine 
Invocation        : diagnosis_app 
Parameters        : None 
Return Value      : uint8, uint16* 
Critical Section  : None 
******************************************************************************/
uint8 ApplDiagStart_f101_RotineControl(uint8 p_diag_buf_U8A[],uint16 *p_resdatalen_ptr) 
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
Function Name     : ApplDiagResults_f101_RotineControl
Description       : This function is used to get routine result  
Invocation        : diagnosis_app 
Parameters        : None 
Return Value      : uint8, uint16* 
Critical Section  : None 
******************************************************************************/
uint8 ApplDiagResults_f101_RotineControl(uint8 p_diag_buf_U8A[],uint16 *p_resdatalen_ptr) 
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
Function Name     : ApplDiagStatus_f101_RotineControl
Description       : This function is used to get routine status 
Invocation        : diagnosis_app 
Parameters        : None 
Return Value      : boolean 
Critical Section  : None 
******************************************************************************/
boolean ApplDiagStatus_f101_RotineControl(void) 
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
Function Name     : ApplDiagTerminal_f101_RotineControl
Description       : This function is used to Stop Routine 
Invocation        : diagnosis_app 
Parameters        : None 
Return Value      : void 
Critical Section  : None 
******************************************************************************/
void ApplDiagTerminal_f101_RotineControl(void)
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
