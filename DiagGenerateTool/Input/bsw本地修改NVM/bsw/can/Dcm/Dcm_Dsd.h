/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2016. Visteon Corporation owns all rights to           *
* this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right,           *
* under the copyright laws of the United States or those of any              *
* other country that may have jurisdiction, to protect this work             *
* as an unpublished work, in the event of an inadvertent or                  *
* deliberate unauthorized publication. Visteon Corporation also              *
* reserves its rights under all copyright laws to protect this               *
* work as a published work, when appropriate. Those having access            *
* to this work may not copy it, use it, modify it or disclose the            *
* information contained in it without the written authorization              *
* of Visteon Corporation.                                                    *
*                                                                            *
******************************************************************************/
/*****************************************************************************
*  File Name         :  Dcm_Dsd.c                                            *
*  Module Short Name :  DiagMgr                                              *
*  VOBName           :                                                       *
*  Author            : msavariy                                              *
*  Description       : This file contains the Diagnostics request and        *
*                       response handling functionlities.                    *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS                                                    *
* Target Hardware  :                                                         *
*                                                                            *
******************************************************************************/
#ifndef DCM_DSD_H
#define DCM_DSD_H
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "Dcm_Types.h"
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/
#ifndef DCM_DSD_C
#define EXTERN extern
#else
#define EXTERN
#endif

/*****************************************************************************
*                                Globally  accessed Variable Declarations    *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/

/*****************************************************************************
*                                 Locally used Variable Declarations         *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/

/*****************************************************************************
*                              Limited Scope Prototypes                      *
******************************************************************************/


/*****************************************************************************
*                   Functions                                                *
******************************************************************************/


/**************************************************************************
Function name   : void Dsd_Init
Arguments       : void
Return type     : void
Description     : This function is called to provide the received data of an I-PDU segment (N-PDU)
                  to the upper layer. 
**************************************************************************/
EXTERN void Dsd_Init(void);

/**************************************************************************
Function name   : void Dsd_Main
Arguments       : void
Return type     : void
Description     : DSD Main Function. 
**************************************************************************/
EXTERN void Dsd_Main(void);

/**************************************************************************
Function name   : void Dsd_DslDataIndication
Arguments       : Dcm_MsgContextType* pMsgContext
Return type     : void
Description     : Indication from the DSL module as request received correctly. 
**************************************************************************/ 
EXTERN Std_ReturnType Dsd_DslDataIndication(Dcm_MsgContextType* pMsgContext);

/**************************************************************************
Function name   : void Dsd_Main
Arguments       : void
Return type     : void
Description     : DSD Main Function. 
**************************************************************************/ 
EXTERN void Dsd_DspProcessingDone(Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType responseCode);


/**************************************************************************
Function name   : void Dsd_DslConfirmation
Arguments       : PduIdType DcmRxPduId, Std_ReturnType result
Return type     : void
Description     : DCM Confirmation. 
**************************************************************************/ 
EXTERN void Dsd_DslConfirmation(PduIdType DcmRxPduId, Std_ReturnType result);

#undef EXTERN

#endif
/*****************************************************************************
*     End of File
*
*******************************************************************************/
/****************************************************************************
*   for each change to this file, be sure to record:                        *
*      1.  who made the change and when the change was made                 *
*      2.  why the change was made and the intended result                  *
*   Following block needs to be repeated for each change                    *
*****************************************************************************/
/**-------------------------------------------------------------------------*/
/*Date              : 17-Jun-2016                                            */
/*Version           :                                                       */
/*By                : msavariy                                              */
/*Traceability      :                                                       */
/*Change Description: Datadesign And Framework implemented, Initial Version */
/*--------------------------------------------------------------------------*/
