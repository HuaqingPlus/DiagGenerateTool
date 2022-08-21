/*********************************************************************/
/*                       DiagTool.Generate Start                     */
/*********************************************************************/

#ifndef __DCMEXT_GENERATE_C__
#define __DCMEXT_GENERATE_C__

#include "DcmExt.h"
#include "DcmExt_Generate.h"


#ifdef MODE_22_SUPPORTED
/****************************************************************************
Function Name     : fdiag_app_A1A1_Read
Description       : This function is used to read DID A1A1
Invocation        : dg_app
Parameters        : None
Return Value      : UINT8
Critical Section  : None

******************************************************************************/
uint8 fdiag_app_A1A1_Read(uint8 Buff[])
{
	uint8 fl_ret = 0;
	return fl_ret;
}

#endif
#ifdef MODE_2E_SUPPORTED
/****************************************************************************
Function Name     : fdiag_app_A1A1_Read

Description       : This function is used to read DID A1A1

Invocation        : dg_app

Parameters        : None

Return Value      : UINT8

Critical Section  : None

******************************************************************************/
uint8 fdiag_app_A1A1_Write(uint8 Buff[])
{
	uint8 fl_ret = 0;
	return fl_ret;
}

#endif
#ifdef MODE_2F_SUPPORTED
/****************************************************************************
Function Name     : fdiag_app_F1B1_IOC
Description       : control
Invocation        :
Parameters        : None
Return Value      : UINT8
Critical Section  : None
******************************************************************************/
uint8 fdiag_app_F1B1_IOC(uint8 fl_ctrl_parameter, uint8 *fl_get_ctrl_value)
{
    return(0);
}

#endif


#endif
/*********************************************************************/
/*                       DiagTool.Generate Stop                      */
/*********************************************************************/

