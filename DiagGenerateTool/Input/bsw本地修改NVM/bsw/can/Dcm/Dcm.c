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
*  File Name         :  Dcm.C                                                *
*  Module Short Name :  DiagMgr                                               *
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
#ifndef DCM_C
#define DCM_C

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/

#include "Dcm.h"
//#include "Dcm_Internal.h"
#include "Dcm_Dsd.h"
#include "Dcm_Dsp.h"
#include "Dcm_Cbk.h"
#include "PduR_Dcm.h"
#include "ComM_Dcm.h"
#include "NvM_Server.h" //Qiuhuaqing Modify

//NVM Test, Qiuhuaqing Modify
//#define DCM_NVM_Test
#ifdef DCM_NVM_Test
static uint8 l_ReadOdo[8] = {0,0,0,0};
static uint8 l_ReadVIN[17] = {0,0,0,0};
static uint8 counter = 1;
#endif

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
#define DCM_STATE_ONRX         0x01u
#define DCM_STATE_RX_END       0x02u
#define DCM_STATE_PREPTX_NRC   0x04u
#define DCM_STATE_ONTX         0x08u
#define DCM_STATE_ONTX_WAIT    0x10u
#define DCM_STATE_READY        0x20u
#define DCM_SID_PROCESS        0x40u


/* ComM */
#define Dcm_ComM_Active        0x01u
#define Dcm_ComM_InActive      0x00u

#define DCM_COMM_STATE_RX_DIS	0x0
#define DCM_COMM_STATE_TX_DIS	0x0
#define DCM_COMM_STATE_TX_EN	0x1
#define DCM_COMM_STATE_RX_EN	0x2



/* Timing Flags */
#define DCM_TMR_ID_P2           0x01
#define DCM_TMR_ID_P2STAR       0x02
#define DCM_TMR_ID_S3SERVER     0x04

#define DCM_ON_TIMEOUT_P2       0x01
#define DCM_ON_TIMEOUT_P2STAR   0x02
#define DCM_ON_TIMEOUT_S3Server 0x04



/* Avoid warnings of unused API parameters */


/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/
typedef uint8 DcmDsl_BufferType;


typedef struct
{
  Dcm_MsgContextType pMsgContext;
  DcmDsl_BufferType* RxData;
  Dcm_MsgItemType* AddBuf;
  uint8 Buff_Pos;
  uint8 State;
}Dcm_DslRequestResponseType;

typedef struct
{
  Dcm_SesCtrlType Session_Level;
  Dcm_SecLevelType Security_Level;
  Dcm_OpStatusType OpStatus;
  Dcm_CommunicationModeType ComMMode;
  Dcm_ConfirmationStatusType ConfirmationStatus;
  boolean ComMState;
  boolean ConcurrentTesterPresent;
}Dcm_InternalStatusType;

typedef struct
{
  uint16 P2;
  uint16 P2Star;
  uint16 S3Server;
  uint8 TimeOut;
}Dcm_TimerType;

typedef enum {
    DCM_NO_COM = 0,
    DCM_SILENT_COM,
    DCM_FULL_COM
}Dcm_ComModeType;


/*****************************************************************************
*                                Globally  accessed Variable Declarations    *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/

const Dcm_ConfigType *Dcm_ConfigPtr;

/*****************************************************************************
*                                 Locally used Variable Declarations         *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/


static DcmDsl_BufferType DcmDsl_Buffer[DcmDslBufferSize];
static Dcm_MsgItemType AddBuffer[DcmDslAddBufferSize];
static Dcm_DslRequestResponseType Dcm_DslRequestResponse;
static Dcm_InternalStatusType Dcm_InternalStatus;
static Dcm_TimerType Dcm_Timer;



/*****************************************************************************
*                              Limited Scope Prototypes                      *
******************************************************************************/

/* DiagMgr Timing Functions */
static void Dcm_StarTimer(uint8 TmrId);
static void Dcm_StopTimer(uint8 TmrId);
static void Dcm_TimerProcess(void);
static void Dcm_Transmit_Function(void);
static void Dcm_OnTimeout(uint8 TmrId);

/*****************************************************************************
*                   Functions                                                *
******************************************************************************/


/* Callback Notifications */
/**************************************************************************
Function name   : BufReq_ReturnType Dcm_CopyRxData
Arguments       : PduIdType DcmRxPduId, const PduInfoType* info, PduLengthType* bufferSizePtr
Return type     : BufReq_ReturnType
Description     : This function is called to provide the received data of an I-PDU segment (N-PDU)
                  to the upper layer.
**************************************************************************/
/******************************MISRA Warning Begin***********************************
** CID : 3112
** MISRA Title : Redundancy
** MISRA: There shall be no dead code (MISRA C-2012 Rule 2.2)
** MISRA Message :
** This statement has no side-effect - it can be removed.
** DCM_IGNORE_UNREF_PARAM(DcmRxPduId);
** Rational:
** This warning is reviewed and team decided to approve since this implementation
** is design intended and it will not impact the functionalities.
** Approved Status: Yes
** Approved Date : 05-05-2017
** Approved By : DI COC Team
******************************MISRA Warning End************************************/
BufReq_ReturnType Dcm_CopyRxData(PduIdType DcmRxPduId,  PduInfoType* info, PduLengthType* bufferSizePtr)
{
  BufReq_ReturnType fl_RetVal;
  uint8 MemIter;
  fl_RetVal = BUFREQ_E_NOT_OK;
  /*QAC fix*/
  DCM_IGNORE_UNREF_PARAM(DcmRxPduId);

  if(Dcm_DslRequestResponse.State == DCM_STATE_ONRX)
  {
      if(info->SduLength != 0)
      {
         if(Dcm_DslRequestResponse.Buff_Pos < Dcm_DslRequestResponse.pMsgContext.reqDataLen)
         {
             for(MemIter = 0; MemIter < info->SduLength; MemIter++)
             {
                 Dcm_DslRequestResponse.pMsgContext.reqData[Dcm_DslRequestResponse.Buff_Pos + MemIter] = info->SduDataPtr[MemIter];
             }
             Dcm_DslRequestResponse.Buff_Pos += MemIter;
             *bufferSizePtr = (PduLengthType)(Dcm_DslRequestResponse.pMsgContext.reqDataLen - Dcm_DslRequestResponse.Buff_Pos);
             fl_RetVal = BUFREQ_OK;
         }
      }
      else
      {     /* Just inform available buffer size*/
          *bufferSizePtr = (PduLengthType)Dcm_DslRequestResponse.pMsgContext.reqDataLen - Dcm_DslRequestResponse.Buff_Pos;
          fl_RetVal = BUFREQ_OK;
      }
  }
  /* To handle Concurrent tester present request */
  else if (info->SduLength == 0x02)
  {
	if((info->SduDataPtr[0] == 0x3E) && ((info->SduDataPtr[1] == 0x80)))
	{
		*bufferSizePtr = 0;
		Dcm_InternalStatus.ConcurrentTesterPresent = TRUE;
		fl_RetVal = BUFREQ_OK;
	}
  }
  else
  {
  /*Do nothing*/
  }
  return fl_RetVal;
}

/**************************************************************************
Function name   : BufReq_ReturnType Dcm_StartOfReception
Arguments       : PduIdType DcmRxPduId, const PduInfoType* info, PduLengthType TpSduLength, PduLengthType* bufferSizePtr
Return type     : BufReq_ReturnType
Description     : This function is called to indicate the start of new diag request.
**************************************************************************/
/******************************MISRA Warning Begin***********************************
** CID : 3112
** MISRA Title : Redundancy
** MISRA: There shall be no dead code (MISRA C-2012 Rule 2.2)
** MISRA Message :
** This statement has no side-effect - it can be removed.
** DCM_IGNORE_UNREF_PARAM(info);
** Rational:
** This warning is reviewed and team decided to approve since this implementation
** is design intended and it will not impact the functionalities.
** Approved Status: Yes
** Approved Date : 05-05-2017
** Approved By : DI COC Team
******************************MISRA Warning End************************************/
BufReq_ReturnType Dcm_StartOfReception(PduIdType DcmRxPduId, PduInfoType* info, PduLengthType TpSduLength, PduLengthType* bufferSizePtr)
{
	BufReq_ReturnType fl_RetVal;
	fl_RetVal = BUFREQ_E_NOT_OK;

	DCM_IGNORE_UNREF_PARAM(info);
	if(FALSE != (Dcm_InternalStatus.ComMMode & DCM_COMM_STATE_RX_EN))
	{
		Dcm_DslRequestResponse.pMsgContext.msgAddInfo.reqType = 0;
		if(DcmTesterSourceFuncAddr == DcmRxPduId)
		{
			Dcm_DslRequestResponse.pMsgContext.msgAddInfo.reqType = 1;
		}

		if(Dcm_DslRequestResponse.State == DCM_STATE_READY)
		{
			if(TpSduLength <= DcmDslBufferSize)
			{
				Dcm_DslRequestResponse.Buff_Pos = 0x0u;
				Dcm_InternalStatus.OpStatus = DCM_INITIAL;
				Dcm_InternalStatus.ConcurrentTesterPresent = FALSE;
				Dcm_DslRequestResponse.pMsgContext.rxPduId = DcmRxPduId;
				Dcm_DslRequestResponse.pMsgContext.msgAddInfo.suppressPosResponse = 0;
				Dcm_DslRequestResponse.State = DCM_STATE_ONRX;
				Dcm_DslRequestResponse.pMsgContext.reqData = (Dcm_MsgType)&DcmDsl_Buffer[0];
				Dcm_DslRequestResponse.pMsgContext.resData = (Dcm_MsgType)&DcmDsl_Buffer[0];
				Dcm_DslRequestResponse.pMsgContext.resDataLen = 0u;
				Dcm_DslRequestResponse.pMsgContext.reqDataLen = (Dcm_MsgLenType)TpSduLength;
				*bufferSizePtr = (PduLengthType)DcmDslBufferSize;
				fl_RetVal = BUFREQ_OK;
			}
			else
			{
				fl_RetVal = BUFREQ_E_OVFL;
			}
		}
		else if(TpSduLength == 0x02)
		{
		  *bufferSizePtr = 0x03;
		  fl_RetVal = BUFREQ_OK;
		}
		else
		{
		/*Do nothing*/
		}
	}

	return fl_RetVal;
}

/**************************************************************************
Function name   : void Dcm_TpRxIndication
Arguments       : PduIdType DcmRxPduId, Std_ReturnType result
Return type     : void
Description     : This function is called to indicate whether the transmission was successful or not.
**************************************************************************/
/******************************MISRA Warning Begin***********************************
** CID : 3112
** MISRA Title : Redundancy
** MISRA: There shall be no dead code (MISRA C-2012 Rule 2.2)
** MISRA Message :
** This statement has no side-effect - it can be removed.
** DCM_IGNORE_UNREF_PARAM(DcmRxPduId);
** Rational:
** This warning is reviewed and team decided to approve since this implementation
** is design intended and it will not impact the functionalities.
** Approved Status: Yes
** Approved Date : 05-05-2017
** Approved By : DI COC Team
******************************MISRA Warning End************************************/
void Dcm_TpRxIndication(PduIdType DcmRxPduId, Std_ReturnType result)
{
	/*QAC fix*/
   	DCM_IGNORE_UNREF_PARAM(DcmRxPduId);
    if(Dcm_DslRequestResponse.State == DCM_STATE_ONRX)
    {
      if(result == E_OK)
      {
    	/* Check for the tester present request*/
    	if(Dcm_DslRequestResponse.pMsgContext.reqData[0] == 0x3Eu)
    	{
    		/* Check for the suppression of Pos Response */
    		if((Dcm_DslRequestResponse.pMsgContext.reqData[1] == 0x80u) && \
			   (Dcm_DslRequestResponse.pMsgContext.reqDataLen == 2u))
    		{
    			/* Restart the session timeout timer for "tester present"*/
    			Dcm_StarTimer(DCM_TMR_ID_S3SERVER);
    			/* No further processing needed for Suppress Positive Response bit set*/
    			Dcm_DslRequestResponse.State = DCM_STATE_READY;
    		}
    		else
    		{
    			/**/
    			Dcm_StarTimer(DCM_TMR_ID_P2 | DCM_TMR_ID_P2STAR);
    			Dcm_DslRequestResponse.State = DCM_STATE_RX_END;
    		}
    	}
    	else
    	{
            Dcm_StarTimer(DCM_TMR_ID_P2 | DCM_TMR_ID_P2STAR);
            Dcm_DslRequestResponse.State = DCM_STATE_RX_END;
    	}
      }
      else
      {
    	  Dcm_DslRequestResponse.State = DCM_STATE_READY;
      }

      if(Dcm_DslRequestResponse.State == DCM_STATE_RX_END)
      {
    	/* Pre copy the SID for NRC 0x78 Response */
    	Dcm_DslRequestResponse.AddBuf[1] = Dcm_DslRequestResponse.pMsgContext.reqData[0];

      	Dcm_EnterCriticalSection();
      	if((Dcm_InternalStatus.ComMState != FALSE) && \
		   (Dcm_InternalStatus.Session_Level == DCM_DEFAULT_SESSION))
		{
			/* Need to look at network id - currently keep it as 0*/
			ComM_DCM_ActiveDiagnostic(0u);
		}
      	Dcm_ExitCriticalSection();
      }
    }
    else if(FALSE != Dcm_InternalStatus.ConcurrentTesterPresent)
    {
		/* Restart the session timeout timer for "tester present"*/
		Dcm_StarTimer(DCM_TMR_ID_S3SERVER);
		Dcm_InternalStatus.ConcurrentTesterPresent = FALSE;
    }
    else
    {

    }
}

/**************************************************************************
Function name   : BufReq_ReturnType Dcm_CopyTxData
Arguments       : PduIdType DcmRxPduId, const PduInfoType* info, RetryInfoType* retry, PduLengthType* availableDataPtr
Return type     : BufReq_ReturnType
Description     : This function is called to acquire the transmit data of an I-PDU segment.
**************************************************************************/
/******************************MISRA Warning Begin***********************************
** CID : 3112
** MISRA Title : Redundancy
** MISRA: There shall be no dead code (MISRA C-2012 Rule 2.2)
** MISRA Message :
** This statement has no side-effect - it can be removed.
** DCM_IGNORE_UNREF_PARAM(DcmRxPduId);
** DCM_IGNORE_UNREF_PARAM(retry);
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
** The object addressed by the pointer parameter 'retry' is not modified and so the
** pointer could be of type 'pointer to const'..
** Rational:
** This warning is reviewed and team decided to approve since this implementation
** is design intended and it will not impact the functionalities.
** Approved Status: Yes
** Approved Date : 05-05-2017
** Approved By : DI COC Team
******************************MISRA Warning End************************************/
BufReq_ReturnType Dcm_CopyTxData(PduIdType DcmRxPduId, PduInfoType* info, RetryInfoType* retry, PduLengthType* availableDataPtr)
{
  BufReq_ReturnType fl_RetVal;
  uint8 memIter;
  fl_RetVal = BUFREQ_E_NOT_OK;


  DCM_IGNORE_UNREF_PARAM(DcmRxPduId);
  DCM_IGNORE_UNREF_PARAM(retry);

	if(Dcm_DslRequestResponse.State == DCM_STATE_ONTX_WAIT)
	{
		fl_RetVal = BUFREQ_E_BUSY;

		if(info->SduLength == 0)
		{
			*availableDataPtr = (Dcm_DslRequestResponse.pMsgContext.resDataLen - Dcm_DslRequestResponse.Buff_Pos);
		}

		if(Dcm_InternalStatus.OpStatus == DCM_E_PROCESSING_DONE)
		{
			if(Dcm_DslRequestResponse.Buff_Pos < Dcm_DslRequestResponse.pMsgContext.resDataLen)
			{
				if(info->SduLength <= (Dcm_DslRequestResponse.pMsgContext.resDataLen - Dcm_DslRequestResponse.Buff_Pos))
				{
					for(memIter = 0; memIter < info->SduLength; memIter++)
					{
						info->SduDataPtr[memIter] = \
								Dcm_DslRequestResponse.pMsgContext.resData[Dcm_DslRequestResponse.Buff_Pos + memIter];
					}
					Dcm_DslRequestResponse.Buff_Pos += memIter;
					*availableDataPtr = Dcm_DslRequestResponse.pMsgContext.resDataLen - Dcm_DslRequestResponse.Buff_Pos;
					fl_RetVal = BUFREQ_OK;
				}

			}
		}
		else
		{
			if(info->SduLength <= 3)
			{
				for(memIter = 0; memIter < info->SduLength; memIter++)
				{
					info->SduDataPtr[memIter] = \
							Dcm_DslRequestResponse.AddBuf[memIter];
				}
				*availableDataPtr = (PduLengthType)info->SduLength - memIter;
				fl_RetVal = BUFREQ_OK;
			}

		}
	}
	return fl_RetVal;
}
/**************************************************************************
Function name   : void Dcm_TpTxConfirmation
Arguments       : PduIdType DcmRxPduId, Std_ReturnType result
Return type     : void
Description     : The result indicates whether the diag response
                  transmission was successful or not.
**************************************************************************/

void  Dcm_TpTxConfirmation(PduIdType DcmRxPduId, Std_ReturnType result)
{

	Dsd_DslConfirmation(DcmRxPduId, result);
	Dsp_DslConfirmation(DcmRxPduId, result);
	/* For an error confirmation re-transmission of response not require...
	 * Hence Result parameter not checked */
	if((Dcm_InternalStatus.OpStatus == DCM_E_PROCESSING_DONE) || \
	   (Dcm_InternalStatus.OpStatus == DCM_E_CANCEL))
	{
		/* Indicate inactive diagnostics to ComM*/
		if((Dcm_InternalStatus.ComMState != FALSE) && \
		   (Dcm_InternalStatus.Session_Level == DCM_DEFAULT_SESSION))
		{
			/* Inform ComM inactive only for the final response
			 * and session level in the default session*/
			ComM_DCM_InactiveDiagnostic(0);
		}
		/* QHQ, should be set Ready */
		 Dcm_DslRequestResponse.State = DCM_STATE_READY;
	}
	else
	{
		Dcm_DslRequestResponse.State = DCM_SID_PROCESS;
	}

	/* Start S3Timer */
	if(Dcm_InternalStatus.Session_Level != DCM_DEFAULT_SESSION)
	{
		Dcm_StarTimer(DCM_TMR_ID_S3SERVER);
	}
}

/**************************************************************************
Function name   : void Dcm_TxConfirmation
Arguments       : PduIdType DcmRxPduId, Std_ReturnType result
Return type     : void
Description     : the result indicates whether the diag response
                  transmission was successful or not.
**************************************************************************/
/******************************MISRA Warning Begin***********************************
** CID : 3112
** MISRA Title : Redundancy
** MISRA: There shall be no dead code (MISRA C-2012 Rule 2.2)
** MISRA Message :
** This statement has no side-effect - it can be removed.
** DCM_IGNORE_UNREF_PARAM(TxPduId);
** Rational:
** This warning is reviewed and team decided to approve since this implementation
** is design intended and it will not impact the functionalities.
** Approved Status: Yes
** Approved Date : 05-05-2017
** Approved By : DI COC Team
******************************MISRA Warning End************************************/
void Dcm_TxConfirmation(PduIdType TxPduId)
{
	/*QAC fix*/
    DCM_IGNORE_UNREF_PARAM(TxPduId);

	if((Dcm_InternalStatus.OpStatus == DCM_E_PROCESSING_DONE) || \
			(Dcm_InternalStatus.OpStatus == DCM_E_CANCEL))
	{
		/* Indicate inactive diagnostics to ComM*/
		if((Dcm_InternalStatus.ComMState != FALSE) && \
		   (Dcm_InternalStatus.Session_Level == DCM_DEFAULT_SESSION))
		{
			/* Inform ComM inactive only for the final response
			 * and session level in the default session*/
			ComM_DCM_InactiveDiagnostic(0);
		}
		Dcm_DslRequestResponse.State = DCM_STATE_READY;
	}
	else
	{
		Dcm_DslRequestResponse.State = DCM_SID_PROCESS;
	}
}


/**************************************************************************
Function name   : void Dcm_ComM_NoComModeEntered
Arguments       : uint8 NetworkId
Return type     : void
Description     : This call informs the Dcm module about a ComM mode change to
                  COMM_NO_COMMUNICATION.
**************************************************************************/
/******************************MISRA Warning Begin***********************************
** CID : 3112
** MISRA Title : Redundancy
** MISRA: There shall be no dead code (MISRA C-2012 Rule 2.2)
** MISRA Message :
** This statement has no side-effect - it can be removed.
** DCM_IGNORE_UNREF_PARAM(NetworkId);
** Rational:
** This warning is reviewed and team decided to approve since this implementation
** is design intended and it will not impact the functionalities.
** Approved Status: Yes
** Approved Date : 05-05-2017
** Approved By : DI COC Team
******************************MISRA Warning End************************************/
void Dcm_ComM_NoComModeEntered(uint8 NetworkId)
{
   /*QAC fix*/
    DCM_IGNORE_UNREF_PARAM(NetworkId);

    Dcm_EnterCriticalSection();
    Dcm_InternalStatus.ComMMode = (DCM_COMM_STATE_RX_DIS | DCM_COMM_STATE_TX_DIS);
    Dcm_ExitCriticalSection();
}

/**************************************************************************
Function name   : void Dcm_ComM_SilentComModeEntered
Arguments       : uint8 NetworkId
Return type     : void
Description     : This call informs the Dcm module about a ComM mode change to
                  COMM_SILENT_COMMUNICATION..
**************************************************************************/
/******************************MISRA Warning Begin***********************************
** CID : 3112
** MISRA Title : Redundancy
** MISRA: There shall be no dead code (MISRA C-2012 Rule 2.2)
** MISRA Message :
** This statement has no side-effect - it can be removed.
** DCM_IGNORE_UNREF_PARAM(NetworkId);
** Rational:
** This warning is reviewed and team decided to approve since this implementation
** is design intended and it will not impact the functionalities.
** Approved Status: Yes
** Approved Date : 05-05-2017
** Approved By : DI COC Team
******************************MISRA Warning End************************************/
void Dcm_ComM_SilentComModeEntered( uint8 NetworkId)
{
     /*QAC fix*/
    DCM_IGNORE_UNREF_PARAM(NetworkId);

    Dcm_EnterCriticalSection();
    Dcm_InternalStatus.ComMMode = (DCM_COMM_STATE_RX_EN | DCM_COMM_STATE_TX_DIS);
    Dcm_ExitCriticalSection();
}

/**************************************************************************
Function name   : void Dcm_ComM_FullComModeEntered
Arguments       : uint8 NetworkId
Return type     : void
Description     : This call informs the Dcm module about a ComM mode change to
                  COMM_FULL_COMMUNICATION.
**************************************************************************/
/******************************MISRA Warning Begin***********************************
** CID : 3112
** MISRA Title : Redundancy
** MISRA: There shall be no dead code (MISRA C-2012 Rule 2.2)
** MISRA Message :
** This statement has no side-effect - it can be removed.
** DCM_IGNORE_UNREF_PARAM(NetworkId);
** Rational:
** This warning is reviewed and team decided to approve since this implementation
** is design intended and it will not impact the functionalities.
** Approved Status: Yes
** Approved Date : 05-05-2017
** Approved By : DI COC Team
******************************MISRA Warning End************************************/
void Dcm_ComM_FullComModeEntered( uint8 NetworkId)
{
    /*QAC fix*/
    DCM_IGNORE_UNREF_PARAM(NetworkId);

    Dcm_EnterCriticalSection();
    Dcm_InternalStatus.ComMMode = (DCM_COMM_STATE_RX_EN | DCM_COMM_STATE_TX_EN);
    Dcm_ExitCriticalSection();
}

/*  Functions provided for other BSW components */
/**************************************************************************
Function name   : void Dcm_Init
Arguments       : const Dcm_ConfigType *ConfigPtr
Return type     : void
Description     : Service for basic initialization of DCM module.
**************************************************************************/

void Dcm_Init(const Dcm_ConfigType* ConfigPtr)
{
	Dcm_ConfigPtr = ConfigPtr;
    Dcm_DslRequestResponse.State = DCM_STATE_READY;
    Dcm_DslRequestResponse.Buff_Pos = (uint8)0u;
    Dcm_DslRequestResponse.RxData = (DcmDsl_BufferType*)&DcmDsl_Buffer[0];
    AddBuffer[0] = 0x7F; /* Always used to send NRC */
    AddBuffer[2] = 0x78; /* Always used to send NRC - 0x78 */
    Dcm_DslRequestResponse.AddBuf = (Dcm_MsgItemType*)&AddBuffer[0];
    Dcm_DslRequestResponse.pMsgContext.idContext = (Dcm_IdContextType)0u;
    Dcm_DslRequestResponse.pMsgContext.msgAddInfo.reqType = (boolean)0;
    Dcm_DslRequestResponse.pMsgContext.msgAddInfo.suppressPosResponse = (boolean)0;
    Dcm_DslRequestResponse.pMsgContext.reqData = (Dcm_MsgType)&DcmDsl_Buffer[0];
    Dcm_DslRequestResponse.pMsgContext.reqDataLen = (Dcm_MsgLenType)0u;
    Dcm_DslRequestResponse.pMsgContext.resData = (Dcm_MsgType)&DcmDsl_Buffer[0];
    Dcm_DslRequestResponse.pMsgContext.resDataLen = (Dcm_MsgLenType)0u;
    Dcm_DslRequestResponse.pMsgContext.resMaxDataLen = (Dcm_MsgLenType)DcmDslBufferSize;
    Dcm_DslRequestResponse.pMsgContext.rxPduId = (PduIdType)0x0;

    Dcm_InternalStatus.ComMMode = DCM_NO_COM;
    Dcm_InternalStatus.ConcurrentTesterPresent = FALSE;
    Dcm_InternalStatus.ComMState = Dcm_ComM_Active;
    Dcm_InternalStatus.ConfirmationStatus = DCM_RES_NEG_OK;
    Dcm_InternalStatus.OpStatus = DCM_INITIAL;
	/*This should be edited for 27 service*/
    /*Dcm_InternalStatus.Security_Level = 1;*/
    Dcm_InternalStatus.Security_Level = DCM_SEC_LEV_LOCKED;
    Dcm_InternalStatus.Session_Level = DCM_DEFAULT_SESSION;

    Dcm_Timer.P2 = 0u;
    Dcm_Timer.P2Star = 0u;
    Dcm_Timer.S3Server = 0u;
    Dcm_Timer.TimeOut = 0u;

    Dsd_Init();
    Dsp_Init();
}
/**************************************************************************
Function name   : void Dcm_InitMemory
Arguments       : Std_VersionInfoType* versionInfo
Return type     : void
Description     : Returns the version information of this module.
**************************************************************************/

void Dcm_InitMemory(Std_VersionInfoType* versionInfo)
{
	void;
}

/**************************************************************************
Function name   : void Dcm_GetVersionInfo
Arguments       : Std_VersionInfoType* versionInfo
Return type     : void
Description     : Returns the version information of this module.
**************************************************************************/

void Dcm_GetVersionInfo(Std_VersionInfoType* versionInfo)
{
/*QAC fix*/
versionInfo->vendorID = 0;
}

/**************************************************************************
Function name   : Std_ReturnType Dcm_DemTriggerOnDTCStatus
Arguments       : Std_VersionInfoType* versionInfo
Return type     : Std_ReturnType
Description     : Triggers on changes of the UDS DTC status byte. Allows to trigger on ROE Event
                  for subservice OnDTCStatusChanged.
**************************************************************************/
/******************************MISRA Warning Begin***********************************
** CID : 3112
** MISRA Title : Redundancy
** MISRA: There shall be no dead code (MISRA C-2012 Rule 2.2)
** MISRA Message :
** This statement has no side-effect - it can be removed.
** DCM_IGNORE_UNREF_PARAM(DTC);
** DCM_IGNORE_UNREF_PARAM(DTCStatusOld);
** DCM_IGNORE_UNREF_PARAM(DTCStatusNew);
** Rational:
** This warning is reviewed and team decided to approve since this implementation
** is design intended and it will not impact the functionalities.
** Approved Status: Yes
** Approved Date : 05-05-2017
** Approved By : DI COC Team
******************************MISRA Warning End************************************/
Std_ReturnType Dcm_DemTriggerOnDTCStatus(uint32 DTC,Dem_UdsStatusByteType DTCStatusOld,Dem_UdsStatusByteType DTCStatusNew)
{
	Std_ReturnType fl_RetVal;
	fl_RetVal = DCM_E_OK;

	/*QAC fix*/
	DCM_IGNORE_UNREF_PARAM(DTC);
	DCM_IGNORE_UNREF_PARAM(DTCStatusOld);
	DCM_IGNORE_UNREF_PARAM(DTCStatusNew);

	return fl_RetVal;
}
/**************************************************************************
Function name   : Std_ReturnType Dcm_GetVin
Arguments       : uint8* Data
Return type     : Std_ReturnType
Description     : Callbackfunction to get the VIN
**************************************************************************/
Std_ReturnType Dcm_GetVin(uint8* Data)
{
  Std_ReturnType fl_RetVal;
  fl_RetVal = DCM_E_OK;
  /*QAC fix*/
  *Data = 0;

  return fl_RetVal;
}


/*    Scheduled Functions */
/**************************************************************************
Function name   : void Dcm_MainFunction
Arguments       : void
Return type     : void
Description     : This service is used for processing the tasks of the main loop.
**************************************************************************/
void Dcm_MainFunction(void)
{
	Std_ReturnType stdReturn = DCM_E_NOT_OK;

    switch(Dcm_DslRequestResponse.State)
    {
      case DCM_STATE_ONRX:
      break;

      case DCM_STATE_RX_END:
            Dcm_DslRequestResponse.State = DCM_SID_PROCESS;
            stdReturn = Dsd_DslDataIndication(&Dcm_DslRequestResponse.pMsgContext);
			switch (stdReturn)
			{
				case DCM_E_OK:
				case DCM_E_NOT_OK:
					Dcm_InternalStatus.OpStatus = DCM_E_PROCESSING_DONE;
				break;
				case DCM_E_RESPONSE_PENDING:
					Dcm_InternalStatus.OpStatus = DCM_E_RESPONSE_PENDING;
				break;
				case DCM_E_FORCE_RCRRP:
					/* Transmit immediate RCRRP */
					Dcm_DslRequestResponse.AddBuf[2] = 0x78;
					Dcm_DslRequestResponse.State = DCM_STATE_ONTX;
					Dcm_InternalStatus.OpStatus = DCM_E_RESPONSE_PENDING;
				break;
				default:
				break;
			}
      break;

      case DCM_STATE_ONTX:
            Dcm_Transmit_Function();
      break;

      case DCM_STATE_ONTX_WAIT:
      case DCM_STATE_READY:
      case DCM_STATE_PREPTX_NRC:
      case DCM_SID_PROCESS:
      default:
      break;
    }
    Dcm_TimerProcess();
    Dsd_Main();
    Dsp_Main();




	#ifdef DCM_NVM_Test
	static uint16 fl_Counter = 0;
	uint8 i = 0;
	uint8 fl_TestOdo[8] = {10,20,30,40, 50, 60, 70, 80 };
	uint8 fl_TestVIN[17] = {0};

	fl_Counter++;
	if(fl_Counter == 1000)
	{
		fl_Counter = 0;
		counter++;

		for(i = 0; i < 8; i++)
		{
			l_ReadOdo[i] = 0;
			fl_TestOdo[i] += counter;
		}

		for(i = 0; i < 17; i++)
		{
			l_ReadVIN[i] = 0;
			fl_TestVIN[i] += counter;
		}

	// static uint8 fl_ReadAll = 0;
	// if(fl_ReadAll == 0)
	// {
	// 	fl_ReadAll = 1;
	// 	NvM_ReadAll();
	// }

		NvmServer_ReadBlock_ById(NvmBlockNumber_TestOdo, l_ReadOdo, 8);
		//NvmServer_WriteBlock_ById(NvmBlockNumber_TestOdo, fl_TestOdo, 8);

		NvmServer_ReadBlock_ById(NvMConf_NvMBlockDescriptor_VIN, l_ReadVIN, 17);
		NvmServer_WriteBlock_ById(NvMConf_NvMBlockDescriptor_VIN, fl_TestVIN, 17);
	}
	#endif
}


/**************************************************************************
Function name   : void Dcm_Transmit_Function
Arguments       : void
Return type     : void
Description     : This function is used to handle transmit functionalities.
**************************************************************************/

static void Dcm_Transmit_Function(void)
{
	Std_ReturnType stdReturn = DCM_E_NOT_OK;
	PduIdType id;
	PduInfoType info;
	Dcm_DslRequestResponse.Buff_Pos = 0x0;
	id = DcmTesterResponseAddr; /* Temporary implementation */

	if(FALSE != (Dcm_InternalStatus.ComMMode & DCM_COMM_STATE_TX_EN))
	{
		if(Dcm_InternalStatus.OpStatus != DCM_E_PROCESSING_DONE)
		{ 	/* Send Nrc: 0x78 - Response Pending */
			/* No need to touch resdata length on on response pending as it may upodated by SWC's*/
	   		/*		Dcm_DslRequestResponse.pMsgContext.resDataLen = 3;*/
			info.SduDataPtr = Dcm_DslRequestResponse.AddBuf;
			info.SduLength = 3;
		}
		else
		{
			Dcm_DslRequestResponse.pMsgContext.resDataLen += \
					(Dcm_DslRequestResponse.pMsgContext.resData - Dcm_DslRequestResponse.pMsgContext.reqData);
			/* Revert back to starting address */
			Dcm_DslRequestResponse.pMsgContext.resData = Dcm_DslRequestResponse.pMsgContext.reqData;

			/* Check if the response length is higher than the available buffer size...
			 * To report Nrc - 0x14  */
			if(Dcm_DslRequestResponse.pMsgContext.resDataLen >= Dcm_DslRequestResponse.pMsgContext.resMaxDataLen)
			{
				/* Add 0x40 with SID for positive response */
				Dcm_DslRequestResponse.pMsgContext.resData[0] = 0x7F;
				Dcm_DslRequestResponse.pMsgContext.resData[2] = DCM_E_RESPONSETOOLONG;
				info.SduDataPtr = Dcm_DslRequestResponse.pMsgContext.resData;
				info.SduLength = 3;
			}
			else
			{
				info.SduDataPtr = Dcm_DslRequestResponse.pMsgContext.resData;
				info.SduLength = Dcm_DslRequestResponse.pMsgContext.resDataLen;
			}
		}

		Dcm_DslRequestResponse.State = DCM_STATE_ONTX_WAIT;
		stdReturn = PduR_DcmTransmit(id, &info); //To be updated after CAN integration

		if(stdReturn != E_OK)
		{
			Dcm_TpTxConfirmation(id, stdReturn);
		}
	}
}


/**************************************************************************
Function name   : void Dcm_TimeTask
Arguments       : void
Return type     : void
Description     : This function is used to handle the DiagMgr timeout's
**************************************************************************/

static void Dcm_TimerProcess(void)
{
    if(0 == (Dcm_Timer.TimeOut & DCM_TMR_ID_P2))
    {
        if(0 != Dcm_Timer.P2)
        {
            --Dcm_Timer.P2;
        }
        else
        {
            Dcm_Timer.TimeOut |= DCM_TMR_ID_P2;
            Dcm_OnTimeout(DCM_TMR_ID_P2);
            /* Handle response pending */
        }
    }

    if(0 == (Dcm_Timer.TimeOut & DCM_TMR_ID_P2STAR))
    {

        if(0 != Dcm_Timer.P2Star)
        {
           --Dcm_Timer.P2Star;
        }
        else
        {
            Dcm_Timer.TimeOut |= DCM_TMR_ID_P2STAR;
            Dcm_OnTimeout(DCM_TMR_ID_P2STAR);
            /* Cancel the current request */
        }
    }

    if(0 == (Dcm_Timer.TimeOut & DCM_TMR_ID_S3SERVER))
    {
        if(0 != Dcm_Timer.S3Server)
        {
           --Dcm_Timer.S3Server;
        }
        else
        {
            Dcm_Timer.TimeOut |= DCM_TMR_ID_S3SERVER;
            Dcm_OnTimeout(DCM_TMR_ID_S3SERVER);
        }
    }
}


/**************************************************************************
Function name   : void Dcm_TimeTask
Arguments       : void
Return type     : void
Description     : This function is used to handle the DiagMgr timeout's
**************************************************************************/
static void Dcm_OnTimeout(uint8 TmrId)
{
    if(FALSE != (DCM_TMR_ID_P2 & TmrId))
    {
        if(Dcm_DslRequestResponse.State == DCM_SID_PROCESS)
        {
        	Dcm_StarTimer(DCM_TMR_ID_P2);
						/* Nrc */
			Dcm_DslRequestResponse.AddBuf[2] = 0x78;
        	Dcm_InternalStatus.OpStatus = DCM_E_RESPONSE_PENDING;
        	Dcm_DslRequestResponse.State = DCM_STATE_ONTX;
        }
        else if(Dcm_DslRequestResponse.State == DCM_STATE_ONTX)
        {
        	Dcm_StarTimer(DCM_TMR_ID_P2);
        }
        else
        {

        }
    }
    if(FALSE != (DCM_TMR_ID_P2STAR & TmrId))
    {
        if(Dcm_DslRequestResponse.State == DCM_SID_PROCESS)
        {
        	Dcm_StopTimer(DCM_TMR_ID_P2);
			/* Nrc */
			Dcm_DslRequestResponse.AddBuf[2] = 0x10;
        	Dcm_InternalStatus.OpStatus = DCM_E_CANCEL;
        	Dcm_DslRequestResponse.State = DCM_STATE_READY;
			Dcm_DspClear14Pending();
        	/* Transmit Negative resposne if ComM Tx Available */
        	if (FALSE != (Dcm_InternalStatus.ComMMode & DCM_COMM_STATE_TX_EN))
        	{
        		Dcm_DslRequestResponse.State = DCM_STATE_ONTX;
        	}

        }
        else if(Dcm_DslRequestResponse.State == DCM_STATE_ONTX)
        {
        	Dcm_StopTimer(DCM_TMR_ID_P2);
        	/* should Trigger DTC*/
        	Dcm_InternalStatus.OpStatus = DCM_INITIAL;
        	Dcm_DslRequestResponse.State = DCM_STATE_READY;
        }
        else
        {

        }
    }

    if(FALSE != (DCM_TMR_ID_S3SERVER & TmrId))
    {
    	(void)Dcm_ResetToDefaultSession();
    }
}



/**************************************************************************
Function name   : void Dcm_StarTimer
Arguments       : uint8
Return type     : void
Description     : This function is used to Start the timer's
**************************************************************************/

static void Dcm_StarTimer(uint8 TmrId)
{
	uint8 SessionIter;

	for (SessionIter =0; SessionIter < NO_OF_SUPPORTTED_SESSIONS; SessionIter++)
	{
		if(Dcm_DsdSessionInfo[SessionIter].Session_Value == Dcm_InternalStatus.Session_Level)
		{
			if(FALSE != (DCM_TMR_ID_P2 & TmrId))
			{
				Dcm_Timer.P2 = Dcm_DsdSessionInfo[SessionIter].P2 * 2;
				Dcm_Timer.TimeOut &= ~DCM_TMR_ID_P2;
			}

			if(FALSE != (DCM_TMR_ID_P2STAR & TmrId))
			{
				Dcm_Timer.P2Star = Dcm_DsdSessionInfo[SessionIter].P2Star * 2;
				Dcm_Timer.TimeOut &= ~DCM_TMR_ID_P2STAR;
			}

			if(FALSE != (DCM_TMR_ID_S3SERVER & TmrId))
			{
				Dcm_Timer.S3Server = DCM_S3_SERVER_TIME;
				Dcm_Timer.TimeOut &= ~DCM_TMR_ID_S3SERVER;
			}

			break;
		}
	}
}

/**************************************************************************
Function name   : void Dcm_StopTimer
Arguments       : uint8
Return type     : void
Description     : This function is used to Start the timer's
**************************************************************************/

static void Dcm_StopTimer(uint8 TmrId)
{
    if(FALSE != (DCM_TMR_ID_P2 & TmrId))
    {
      Dcm_Timer.TimeOut |= DCM_TMR_ID_P2;
    }
    if(FALSE != (DCM_TMR_ID_P2STAR & TmrId))
    {
        Dcm_Timer.TimeOut |= DCM_TMR_ID_P2STAR;
    }
    if(FALSE != (DCM_TMR_ID_S3SERVER & TmrId))
    {
        Dcm_Timer.TimeOut |= DCM_TMR_ID_S3SERVER;
    }
}


/**************************************************************************
Function name   : DslInternal_SetSesCtrlType
Arguments       : Dcm_SesCtrlType SesCtrlType
Return type     : void
Description     : This function sets a new session control type value in the DCM module.
**************************************************************************/
void DslInternal_SetSesCtrlType(Dcm_SesCtrlType SesCtrlType)
{
   Dcm_InternalStatus.Session_Level = SesCtrlType;
	Dcm_SessionChangeAction(SesCtrlType);
}

/**************************************************************************
Function name   : DslInternal_SetSecurityLevel
Arguments       : Dcm_SecLevelType SecurityLevel)
Return type     : void
Description     : This function sets a new security level value in the DCM module.
**************************************************************************/
void DslInternal_SetSecurityLevel(Dcm_SecLevelType SecurityLevel)
{
    Dcm_InternalStatus.Security_Level = SecurityLevel;
}

/* Functions provided to BSW modules and to SW-Cs */

/**************************************************************************
Function name   : Std_ReturnType Dcm_GetSecurityLevel
Arguments       : Dcm_SecLevelType *secLevel
Return type     : Std_ReturnType
Description     : This function provides the active security level value.
**************************************************************************/

Std_ReturnType Dcm_GetSecurityLevel(Dcm_SecLevelType *secLevel)
{
  Std_ReturnType fl_RetVal;
  fl_RetVal = DCM_E_OK;
  *secLevel = Dcm_InternalStatus.Security_Level;
  return fl_RetVal;
}

/**************************************************************************
Function name   : Std_ReturnType Dcm_GetSesCtrlType
Arguments       : Dcm_SesCtrlType *sesCtrlType
Return type     : Std_ReturnType
Description     : This function provides the active session control type value.
**************************************************************************/
Std_ReturnType Dcm_GetSesCtrlType(Dcm_SesCtrlType *sesCtrlType)
{
  Std_ReturnType fl_RetVal;
  fl_RetVal = DCM_E_OK;
  *sesCtrlType = Dcm_InternalStatus.Session_Level;
  return fl_RetVal;
}


 /**************************************************************************
Function name   : Std_ReturnType Dcm_GetActiveProtocol
Arguments       : Dcm_ProtocolType *activeProtocol
Return type     : Std_ReturnType
Description     : This function returns the active protocol name
**************************************************************************/
Std_ReturnType Dcm_GetActiveProtocol(Dcm_ProtocolType *activeProtocol)
{
  Std_ReturnType fl_RetVal;
  fl_RetVal = DCM_E_OK;
  /*QAC fix*/
  *activeProtocol = 0;

  return fl_RetVal;
}


/**************************************************************************
Function name   : Dcm_ResetToDefaultSession
Arguments       : void
Return type     : Std_ReturnType
Description     : The call to this function allows the application to reset the current session to
                  Default session.
**************************************************************************/
Std_ReturnType Dcm_ResetToDefaultSession(void)
{
	Std_ReturnType fl_RetVal;
	fl_RetVal = DCM_E_OK;
	/*This should be edited for 27 service*/
	/*Dcm_InternalStatus.Security_Level = 1;*/
	Dcm_InternalStatus.Security_Level = DCM_SEC_LEV_LOCKED;
	Dcm_InternalStatus.Session_Level = DCM_DEFAULT_SESSION;
	Dcm_SessionChangeAction(DCM_DEFAULT_SESSION);
	if(Dcm_InternalStatus.ComMState != FALSE)
	{
		ComM_DCM_InactiveDiagnostic(0);
	}
	return fl_RetVal;
}


/**************************************************************************
Function name   : Std_ReturnType Dcm_TriggerOnEvent
Arguments       : uint8 RoeEventId
Return type     : Std_ReturnType
Description     : The call to this function allows to trigger an event linked to a ResponseOnEvent
                  request.
**************************************************************************/
/******************************MISRA Warning Begin***********************************
** CID : 3112
** MISRA Title : Redundancy
** MISRA: There shall be no dead code (MISRA C-2012 Rule 2.2)
** MISRA Message :
** This statement has no side-effect - it can be removed.
** DCM_IGNORE_UNREF_PARAM(RoeEventId);
** Rational:
** This warning is reviewed and team decided to approve since this implementation
** is design intended and it will not impact the functionalities.
** Approved Status: Yes
** Approved Date : 05-05-2017
** Approved By : DI COC Team
******************************MISRA Warning End************************************/
Std_ReturnType Dcm_TriggerOnEvent(uint8 RoeEventId)
{
  Std_ReturnType fl_RetVal;
  fl_RetVal = DCM_E_OK;
  /*QAC fix*/
  DCM_IGNORE_UNREF_PARAM(RoeEventId);
  return fl_RetVal;
}


/**************************************************************************
Function name   : Std_ReturnType Dcm_SetActiveDiagnostic
Arguments       : boolean avtive
Return type     : Std_ReturnType
Description     : Allows to activate and deactivate the call of ComM_DCM_ActiveDiagnostic()
                  function. Critical section needed as this API is reentrant.
**************************************************************************/
Std_ReturnType Dcm_SetActiveDiagnostic(boolean active)
{
  Std_ReturnType fl_RetVal;
  fl_RetVal = DCM_E_OK;
  Dcm_EnterCriticalSection();
  	  Dcm_InternalStatus.ComMState = active;
  Dcm_ExitCriticalSection();
  return fl_RetVal;
}

/* External diagnostic service processing */
/**************************************************************************
Function name   : void Dcm_ExternalSetNegResponse
Arguments       : Dcm_NegativeResponseCodeType ErrorCode
Return type     : void
Description     : Used by service interpreter outside of DCM to indicate that a the final response
                  shall be a negative one.
**************************************************************************/
void Dcm_ExternalSetNegResponse(Dcm_NegativeResponseCodeType ErrorCode)
{
	Dcm_DslRequestResponse.pMsgContext.reqData = (Dcm_MsgType)&DcmDsl_Buffer[0];
	/* Anyway response is pointing to same as request address */
	Dcm_DslRequestResponse.pMsgContext.resData = Dcm_DslRequestResponse.pMsgContext.reqData;
	Dcm_DslRequestResponse.pMsgContext.resData[1] = Dcm_DslRequestResponse.pMsgContext.reqData[0];
	Dcm_DslRequestResponse.pMsgContext.resData[0] = 0x7F;
	Dcm_DslRequestResponse.pMsgContext.resData[2] = ErrorCode;
	/* The below assignment for getting length information in transmit function */
	Dcm_DslRequestResponse.pMsgContext.resData = \
				&Dcm_DslRequestResponse.pMsgContext.resData[3];
	Dcm_DslRequestResponse.pMsgContext.resDataLen = 0x00u;
	Dcm_DslRequestResponse.State = DCM_STATE_PREPTX_NRC;

	/* Suppression of Response should not proceed for Physical Address */
	Dcm_DslRequestResponse.pMsgContext.msgAddInfo.suppressPosResponse = FALSE;

#if (DCM_FUNC_ADDR_SUPPRESS_NRC != FALSE)
	if(FALSE != Dcm_DslRequestResponse.pMsgContext.msgAddInfo.reqType)
	{
		switch(ErrorCode)
		{
		/* Suppress the below NRC's only for active Functional Addressing */
			case DCM_E_SERVICENOTSUPPORTED:
			case DCM_E_SUBFUNCTIONNOTSUPPORTED:
			case DCM_E_REQUESTOUTOFRANGE:
			case DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION:
			case DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION:
				Dcm_DslRequestResponse.pMsgContext.msgAddInfo.suppressPosResponse = TRUE;
			break;

			default:
				Dcm_DslRequestResponse.pMsgContext.msgAddInfo.suppressPosResponse = FALSE;
			break;
		}
	}
	else
	{

	}
#endif
}

/**************************************************************************
Function name   : void Dcm_ExternalProcessingDone
Arguments       : void
Return type     : void
Description     : Used by service interpreter outside of DCM to indicate that a final response can be
                   sent.
**************************************************************************/
void Dcm_ExternalProcessingDone(void)
{
	if (Dcm_DslRequestResponse.State != DCM_STATE_PREPTX_NRC)
	{
		Dcm_DslRequestResponse.pMsgContext.reqData = (Dcm_MsgType)&DcmDsl_Buffer[0];
		/* Add 0x40 with SID for positive response */
		Dcm_DslRequestResponse.pMsgContext.reqData[0] += 0x40;
	}

	Dcm_InternalStatus.OpStatus = DCM_E_PROCESSING_DONE;
	Dcm_DslRequestResponse.State = DCM_STATE_ONTX;

	if(FALSE != Dcm_DslRequestResponse.pMsgContext.msgAddInfo.suppressPosResponse)
	{
		Dcm_DslRequestResponse.pMsgContext.msgAddInfo.suppressPosResponse = 0u;
		if(Dcm_InternalStatus.Session_Level != DCM_DEFAULT_SESSION)
		{
			Dcm_StarTimer(DCM_TMR_ID_S3SERVER);
		}
		/* if response is suppressed in Default session, Dcm will call
		 * ComM Dcm inactive diagnostics */
		else if(Dcm_InternalStatus.ComMState != FALSE)
		{
		  ComM_DCM_InactiveDiagnostic(0);
		}
		else
		{
		}
		Dsp_DslConfirmation(Dcm_DslRequestResponse.pMsgContext.rxPduId, DCM_E_OK);
		Dcm_DslRequestResponse.State = DCM_STATE_READY;
	}
}

void Dcm_ResetP2StartServer(void)
{
	Dcm_StarTimer (DCM_TMR_ID_P2STAR);
}
#if 0

/* Callout Definitions */

/*!!!!!!!!!!!!!!!!!!!!!*/
/*  The content of most callouts is hand-written code, for some callouts the
DCM configuration tool shall generate a default implementation that is manually
edited by the integrator.

  These fucntions will be kept in Dcm_Callout.c file in future
When real implementation begins*/

/**************************************************************************
Function name   : Dcm_ReturnReadMemoryType Dcm_ReadMemory
Arguments       : Dcm_OpStatusType OpStatus, uint8 MemoryIdentifier, uint32 MemoryAddress, uint32 MemorySize, uint8* MemoryData
Return type     : Dcm_ReturnReadMemoryType
Description     : The Dcm_ReadMemory callout is used to request memory data identified by the
                  parameter memoryAddress and memorySize from the UDS request message.
**************************************************************************/

Dcm_ReturnReadMemoryType Dcm_ReadMemory(Dcm_OpStatusType OpStatus, uint8 MemoryIdentifier, uint32 MemoryAddress, uint32 MemorySize, uint8* MemoryData)
{
  Dcm_ReturnReadMemoryType fl_RetVal;
  fl_RetVal = DCM_READ_OK;
  return fl_RetVal;
}

/**************************************************************************
Function name   : Dcm_ReturnWriteMemoryType Dcm_WriteMemory
Arguments       : Dcm_OpStatusType OpStatus, uint8 MemoryIdentifier, uint32 MemoryAddress, uint32 MemorySize, uint8* MemoryData
Return type     : Dcm_ReturnWriteMemoryType
Description     : The Dcm_WriteMemory callout is used to write memory data identified by the
                  parameter memoryAddress and memorySize.
**************************************************************************/

Dcm_ReturnWriteMemoryType Dcm_WriteMemory(Dcm_OpStatusType OpStatus, uint8 MemoryIdentifier, uint32 MemoryAddress, uint32 MemorySize, uint8* MemoryData)
{
  Dcm_ReturnWriteMemoryType fl_RetVal;
  fl_RetVal = DCM_WRITE_OK;
  return fl_RetVal;
}

/**************************************************************************
Function name   : void Dcm_Confirmation
Arguments       : Dcm_IdContextType idContext, PduIdType dcmRxPduId, Dcm_ConfirmationStatusType status
Return type     : void
Description     : This function confirms the successful transmission or a transmission error of a
                  diagnostic service.
**************************************************************************/
void Dcm_Confirmation(Dcm_IdContextType idContext, PduIdType dcmRxPduId, Dcm_ConfirmationStatusType status)
{

}

/**************************************************************************
Function name   : Std_ReturnType Dcm_SetProgConditions
Arguments       : Dcm_ProgConditionsType * ProgConditions
Return type     : Std_ReturnType
Description     : The Dcm_SetProgConditions callout allows the integrator to store relevant
                  information prior to jumping to bootloader.
**************************************************************************/

Std_ReturnType Dcm_SetProgConditions(Dcm_ProgConditionsType * ProgConditions)
{
  Std_ReturnType fl_RetVal;
  fl_RetVal = DCM_E_OK;
  return fl_RetVal;
}

/**************************************************************************
Function name   : Dcm_EcuStartModeType Dcm_GetProgConditions
Arguments       : Dcm_ProgConditionsType * ProgConditions
Return type     : Dcm_EcuStartModeType
Description     : The Dcm_GetProgConditions callout is called upon DCM initialization and allows to
                  determine if a response ($50 or $51) has to be sent depending on request within
                  the bootloader.
**************************************************************************/
Dcm_EcuStartModeType Dcm_GetProgConditions(Dcm_ProgConditionsType * ProgConditions)
{
  Dcm_EcuStartModeType fl_RetVal;
  fl_RetVal = DCM_COLD_START;
  return fl_RetVal;
}

/**************************************************************************
Function name   : Std_ReturnType Dcm_ProcessRequestTransferExit
Arguments       : Dcm_OpStatusType OpStatus, uint8* ParameterRecord, uint32 ParameterRecordSize, Dcm_NegativeResponseCodeType* ErrorCode
Return type     : Std_ReturnType
Description     : DCM shall call this callout function to terminate a download or upload process.
**************************************************************************/
Std_ReturnType Dcm_ProcessRequestTransferExit(Dcm_OpStatusType OpStatus, uint8* ParameterRecord, uint32 ParameterRecordSize, \
                                                                                        Dcm_NegativeResponseCodeType* ErrorCode)
{
  Std_ReturnType fl_RetVal;
  fl_RetVal = DCM_E_OK;
  return fl_RetVal;
}

/**************************************************************************
Function name   : Std_ReturnType Dcm_ProcessRequestUpload
Arguments       : Dcm_OpStatusType OpStatus, uint8 DataFormatIdentifier, uint32 MemoryAddress, uint32 MemorySize,
                    uint32* BlockLength, Dcm_NegativeResponseCodeType* ErrorCode
Return type     : Std_ReturnType
Description     : DCM shall call this callout function to start an upload process. This service
                  is needed for the implementation of UDS service RequestUpload.
**************************************************************************/

Std_ReturnType Dcm_ProcessRequestUpload(Dcm_OpStatusType OpStatus, uint8 DataFormatIdentifier, uint32 MemoryAddress, uint32 MemorySize, \
                                                                            uint32* BlockLength, Dcm_NegativeResponseCodeType* ErrorCode)
{
  Std_ReturnType fl_RetVal;
  fl_RetVal = DCM_E_OK;
  return fl_RetVal;
}

/**************************************************************************
Function name   : Std_ReturnType Dcm_ProcessRequestDownload
Arguments       : Dcm_OpStatusType OpStatus, uint8 DataFormatIdentifier, uint32 MemoryAddress, uint32 MemorySize, uint32* BlockLength,
                  Dcm_NegativeResponseCodeType* ErrorCode
Return type     : Std_ReturnType
Description     : DCM shall call this callout function to start an upload process. This service
                  is needed for the implementation of UDS service RequestUpload.
**************************************************************************/

Std_ReturnType Dcm_ProcessRequestDownload(Dcm_OpStatusType OpStatus, uint8 DataFormatIdentifier, uint32 MemoryAddress, uint32 MemorySize, \
                                                                              uint32* BlockLength, Dcm_NegativeResponseCodeType* ErrorCode)
{
  Std_ReturnType fl_RetVal;
  fl_RetVal = DCM_E_OK;
  return fl_RetVal;
}


/**************************************************************************
Function name   : Std_ReturnType Dcm_ProcessRequestFileTransfer
Arguments       : Dcm_OpStatusType OpStatus, uint8 modeofOperation, uint16 fileSizeParameterLength,
                  uint8* filePathAndName, uint8 dataFormatIdentifier, uint8* fileSizeUncompressedOrDirInfoLength,
                  uint8* fileSizeCompressed, uint32* BlockLength, Dcm_NegativeResponseCodeType* ErrorCode
Return type     : Std_ReturnType
Description     : DCM shall call this callout function to start a RequestFileTransferprocess. This
                  service is needed for the implementation of UDS service RequestFileTransfer.
**************************************************************************/

Std_ReturnType Dcm_ProcessRequestFileTransfer(Dcm_OpStatusType OpStatus, uint8 modeofOperation, uint16 fileSizeParameterLength, \
                                uint8* filePathAndName, uint8 dataFormatIdentifier, uint8* fileSizeUncompressedOrDirInfoLength, \
                                        uint8* fileSizeCompressed, uint32* BlockLength, Dcm_NegativeResponseCodeType* ErrorCode)
{
  Std_ReturnType fl_RetVal;
  fl_RetVal = DCM_E_OK;
  return fl_RetVal;
}


/**************************************************************************
Function name   : Std_ReturnType Dcm_GetResetConditions
Arguments       : Dcm_ResetConditionsType* ResetConditions
Return type     : Std_ReturnType
Description     : The Dcm_GetResetConditions callout is called upon DCM initialization and allows
                  to determine if a response ($51) has to be sent or not.
**************************************************************************/
Std_ReturnType Dcm_GetResetConditions(Dcm_ResetConditionsType* ResetConditions)
{
  Std_ReturnType fl_RetVal;
  fl_RetVal = DCM_E_OK;
  return fl_RetVal;
}


/**************************************************************************
Function name   : Std_ReturnType Dcm_SetResetConditions
Arguments       : Dcm_ResetConditionsType* ResetConditions
Return type     : Std_ReturnType
Description     : The Dcm_GetResetConditions callout is called upon DCM initialization and allows
                  to determine if a response ($51) has to be sent or not.
**************************************************************************/
Std_ReturnType Dcm_SetResetConditions(Dcm_ResetConditionsType* ResetConditions)
{
  Std_ReturnType fl_RetVal;
  fl_RetVal = DCM_E_OK;
  return fl_RetVal;
}
#endif

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
/*Date              : 20-Jun-2016                                           */
/*Version           :                                                       */
/*By                : msavariy                                              */
/*Traceability      : RTC# 567968                                           */
/*Change Description: Datadesign And Framework implemented, Initial Version */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 16-Dec-2016                                           */
/*Version           :                                                       */
/*By                : msavariy                                              */
/*Traceability      : Rtc# 731986                                           */
/*Change Description: Concurrent tester present, functional request,        */
/*			   Response pending transmission related issue's fix.           */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 13-March-2017                                         */
/*Version           :                                                       */
/*By                : akalarim                                              */
/*Traceability      : Rtc# 822374                                           */
/*Change Description: Coverity issue fixes                                  */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 13-May-2017                                           */
/*Version           :                                                       */
/*By                : akalarim                                              */
/*Traceability      : Rtc#                                                  */
/*Change Description: QAC warning fixes                                     */
/*--------------------------------------------------------------------------*/

