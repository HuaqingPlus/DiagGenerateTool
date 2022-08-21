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
#ifndef DCM_DSD_C_
#define DCM_DSD_C_

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/

#include "Dcm_Dsd.h"
#include "Dcm.h"
//#include "Dcm_Internal.h"

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

#define DCM_DSD_SID_HAS_SUBFN  				 0x01u
#define DCM_DSD_SID_FUNCTIONAL_ADDR_SUPPORT  0x02u
/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/


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

void Dsd_Init(void)
{
}

/**************************************************************************
Function name   : void Dsd_Main
Arguments       : void
Return type     : void
Description     : DSD Main Function.
**************************************************************************/
void Dsd_Main(void)
{
}

/**************************************************************************
Function name   : void Dsd_Main
Arguments       : void
Return type     : void
Description     : DSD Main Function.
**************************************************************************/
Std_ReturnType Dsd_DslDataIndication(Dcm_MsgContextType *pMsgContext)
{
	  uint8 flIter;
	  uint8 flLength;
	  uint8 flStateRef;
	  Std_ReturnType retVal;
	  Dcm_NegativeResponseCodeType Nrc;
	  Dcm_SesCtrlType flSession;

	  retVal = DCM_E_NOT_OK;

	  flLength = Dcm_DsdSidTabServiceId[0];
	  Nrc = DCM_E_SERVICENOTSUPPORTED;
	  for(flIter = 0; flIter < flLength; flIter++)
	  {
		  if(pMsgContext->reqData[0] == Dcm_DsdSidTabServiceId[flIter + 1])
		  {
			 if((FALSE !=(Dcm_DsdSidTabServiceInfo[flIter].Props & DCM_DSD_SID_FUNCTIONAL_ADDR_SUPPORT)) || (FALSE == pMsgContext->msgAddInfo.reqType))
			 {
			  flStateRef = Dcm_DsdSidTabServiceInfo[flIter].State_Ref;
			  (void)Dcm_GetSesCtrlType(&flSession);
			  Nrc = DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION;
			  if(FALSE != ((Dcm_DsdStateRef[flStateRef].Session) & (0x01 << (flSession-1))))
			  {
				  Nrc = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
				  if(pMsgContext->reqDataLen >= Dcm_DsdSidTabServiceInfo[flIter].Length)
				  {
					  if(FALSE != (Dcm_DsdSidTabServiceInfo[flIter].Props & DCM_DSD_SID_HAS_SUBFN))
					  {
						if(FALSE != (pMsgContext->reqData[1] & 0x80))
						{
							pMsgContext->reqData[1] &= 0x7Fu;
							pMsgContext->msgAddInfo.suppressPosResponse = 1;
						}
					  }
					  Nrc = FALSE;
					  pMsgContext->reqData = (Dcm_MsgType)&pMsgContext->reqData[1];
					  pMsgContext->reqDataLen = pMsgContext->reqDataLen - 1;
					  retVal = Dcm_DsdSidTabServiceInfo[flIter].DcmDsdSidTabFnc(pMsgContext);
				  }
			  }
			  }
			  break;
		  }
	  }
	  if(Nrc != FALSE)
	  {
		  Dcm_ExternalSetNegResponse(Nrc);
		  Dcm_ExternalProcessingDone();
	  }

	  return retVal;

}

/**************************************************************************
Function name   : void Dsd_Main
Arguments       : void
Return type     : void
Description     : DSD Main Function.
**************************************************************************/
/******************************MISRA Warning Begin***********************************
** CID : 3112
** MISRA Title : Redundancy
** MISRA: There shall be no dead code (MISRA C-2012 Rule 2.2)
** MISRA Message :
** This statement has no side-effect - it can be removed.
** DCM_IGNORE_UNREF_PARAM(pMsgContext);
** DCM_IGNORE_UNREF_PARAM(responseCode);
** Rational:
** This warning is reviewed and team decided to approve since this implementation
** is design intended and it will not impact the functionalities.
** Approved Status: Yes
** Approved Date : 05-05-2017
** Approved By : DI COC Team
******************************MISRA Warning End************************************/
/******************************MISRA Warning Begin***********************************
** CID : 3673
** MISRA Title : pointer
** MISRA Type:A pointer should point to a const-qualified type whenever possible - MISRA C:2012  Rule-8.13: (Advisory)
** MISRA Message :
** The object addressed by the pointer parameter 'pMsgContext' is not modified and so the
** pointer could be of type 'pointer to const'..
** Rational:
** This warning is reviewed and team decided to approve since this implementation
** is design intended and it will not impact the functionalities.
** Approved Status: Yes
** Approved Date : 05-05-2017
** Approved By : DI COC Team
******************************MISRA Warning End************************************/
void Dsd_DspProcessingDone(Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType responseCode)
{
/*QAC fix*/
DCM_IGNORE_UNREF_PARAM(pMsgContext);
DCM_IGNORE_UNREF_PARAM(responseCode);
/*QAC fix*/
}

/**************************************************************************
Function name   : void Dsd_DslConfirmation
Arguments       : PduIdType DcmRxPduId, Std_ReturnType result
Return type     : void
Description     : DCM Confirmation.
**************************************************************************/
/******************************MISRA Warning Begin***********************************
** CID : 3112
** MISRA Title : Redundancy
** MISRA: There shall be no dead code (MISRA C-2012 Rule 2.2)
** MISRA Message :
** This statement has no side-effect - it can be removed.
** DCM_IGNORE_UNREF_PARAM(DcmRxPduId);
** DCM_IGNORE_UNREF_PARAM(result);
** Rational:
** This warning is reviewed and team decided to approve since this implementation
** is design intended and it will not impact the functionalities.
** Approved Status: Yes
** Approved Date : 05-05-2017
** Approved By : DI COC Team
******************************MISRA Warning End************************************/
void Dsd_DslConfirmation(PduIdType DcmRxPduId, Std_ReturnType result)
{
/*QAC fix*/
DCM_IGNORE_UNREF_PARAM(DcmRxPduId);
DCM_IGNORE_UNREF_PARAM(result);
/*QAC fix*/
}



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
/*Change Description: Data design And Framework implemented, Initial Version */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 13-May-2017                                           */
/*Version           :                                                       */
/*By                : akalarim                                              */
/*Traceability      : Rtc#                                                  */
/*Change Description: QAC warning fixes                                     */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 13-May-2017                                           */
/*Version           :                                                       */
/*By                : akalarim                                              */
/*Traceability      : Rtc# 859867                                           */
/*Change Description: Issue fix for service ID not supportted in Functional */
/*						Addressing                                          */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 19-May-2017                                           */
/*Version           :                                                       */
/*By                : akalarim                                              */
/*Traceability      : Rtc#  866349                                          */
/*Change Description: PR defect fixes for 866349							*/
/*--------------------------------------------------------------------------*/
