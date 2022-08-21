/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2013. Visteon Corporation owns all rights to           *
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
*  File Name         :  Dcm_Dsp.h                                            *
*  Module Short Name :  DiagMgr                                              *
*  VOBName           :                                                       *
*  Author            : msavariy                                              *
*  Description       : This file contains the Diagnostics request and        *
*                       response Service processing functionalities          *
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

#ifndef DCM_DSP_H
#define DCM_DSP_H

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "Dcm_Types.h"
#include "Dcm_cfg.h"
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
#ifndef DCM_DSP_C
#define EXTERN extern
#else
#define EXTERN
#endif

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/
/* Qiuhuaqing, Add Timer_27Service, don't depend on GPt  */
typedef struct
{
	uint16 ResetCounter;
    uint16 FailCounter;
    uint8 IsStarted;
	uint8 TimeOut;
}Dcm_27Service_TimerType;


#define TIMER_RESET                 ((uint8)1)
#define TIMER_FAILCOUNTER           ((uint8)2)

#define TIMER_VALUE_RESET           ((uint16)1000)  /* 10s = 1000 * 10ms */
#define TIMER_VALUE_FAILCOUNTER     ((uint16)1000)  /* 10s = 1000 * 10ms */

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
EXTERN void DcmExt_Main(void);
EXTERN void DcmExt_Init(void);
/**************************************************************************
Function name       : void Dsp_Init(void)
Description         : Initializes the Diag Service Processing
Parameters (in)     : None. 
Parameters (out)    : None
Return value        : None 
Design Information  : 
**************************************************************************/
EXTERN void Dsp_Init(void);

/**************************************************************************
Function name       : void Dsp_Init(void)
Description         : Diag Service Processing Main function
Parameters (in)     : None. 
Parameters (out)    : None
Return value        : None 
Design Information  : 
**************************************************************************/
EXTERN void Dsp_Main(void);

/**************************************************************************
Function name       : Std_ReturnType Dcm_10ServiceProcess(Dcm_MsgContextType *pMsgContext)
Description         : DiagnosticSessionControl 0x10 service
Parameters (in)     : Dcm_MsgContextType *pMsgContext 
Parameters (out)    : none
Return value        : Std_ReturnType 
Design Information  : 
**************************************************************************/
EXTERN Std_ReturnType Dcm_10ServiceProcess(Dcm_MsgContextType *pMsgContext);

/**************************************************************************
Function name       : Std_ReturnType Dcm_01DefaultProcess(void)
Description         :
Parameters (in)     :
Parameters (out)    : none
Return value        : Std_ReturnType
Design Information  :
**************************************************************************/
EXTERN Std_ReturnType Dcm_01DefaultProcess(void);

/**************************************************************************
Function name       : Std_ReturnType Dcm_02PgmProcess(void)
Description         :
Parameters (in)     :
Parameters (out)    : none
Return value        : Std_ReturnType
Design Information  :
**************************************************************************/
EXTERN Std_ReturnType Dcm_02PgmProcess(void);

/**************************************************************************
Function name       : Std_ReturnType Dcm_03ExtnDiagProcess(void)
Description         :
Parameters (in)     :
Parameters (out)    : none
Return value        : Std_ReturnType
Design Information  :
**************************************************************************/
EXTERN Std_ReturnType Dcm_03ExtnDiagProcess(void);

/**************************************************************************
Function name       : Std_ReturnType Dcm_04EOLDiagProcess(void)
Description         :
Parameters (in)     :
Parameters (out)    : none
Return value        : Std_ReturnType
Design Information  :
**************************************************************************/
EXTERN Std_ReturnType Dcm_04EOLDiagProcess(void);

/**************************************************************************
Function name       : Std_ReturnType Dcm_11ServiceProcess(Dcm_MsgContextType *pMsgContext)
Description         : ECUReset 
Parameters (in)     : Dcm_MsgContextType *pMsgContext 
Parameters (out)    : none
Return value        : Std_ReturnType 
Design Information  : 
**************************************************************************/
EXTERN Std_ReturnType Dcm_11ServiceProcess(Dcm_MsgContextType *pMsgContext);

/**************************************************************************
Function name       : Std_ReturnType Dcm_22ServiceProcess(Dcm_MsgContextType *pMsgContext)
Description         : ReadDataByIdentifier Service 
Parameters (in)     : Dcm_MsgContextType *pMsgContext 
Parameters (out)    : none
Return value        : Std_ReturnType 
Design Information  : 
**************************************************************************/
EXTERN Std_ReturnType Dcm_22ServiceProcess(Dcm_MsgContextType *pMsgContext);

/**************************************************************************
Function name       : Std_ReturnType Dcm_2EServiceProcess(Dcm_MsgContextType *pMsgContext)
Description         : WriteDataByIdentifier Service 
Parameters (in)     : Dcm_MsgContextType *pMsgContext 
Parameters (out)    : none
Return value        : Std_ReturnType 
Design Information  : 
**************************************************************************/
EXTERN Std_ReturnType Dcm_23ServiceProcess(Dcm_MsgContextType *pMsgContext);

/**************************************************************************
Function name       : Std_ReturnType Dcm_23ServiceProcess(Dcm_MsgContextType *pMsgContext)
Description         : ReadMemoryByAddress Service 
Parameters (in)     : Dcm_MsgContextType *pMsgContext 
Parameters (out)    : none
Return value        : Std_ReturnType 
Design Information  : 
**************************************************************************/
EXTERN Std_ReturnType Dcm_2EServiceProcess(Dcm_MsgContextType *pMsgContext);

/**************************************************************************
Function name       : Std_ReturnType Dcm_2FServiceProcess(Dcm_MsgContextType *pMsgContext)
Description         : ReadDataByIdentifier Service 
Parameters (in)     : Dcm_MsgContextType *pMsgContext 
Parameters (out)    : none
Return value        : Std_ReturnType 
Design Information  : 
**************************************************************************/
EXTERN Std_ReturnType Dcm_2FServiceProcess(Dcm_MsgContextType *pMsgContext);

/**************************************************************************
Function name       : Std_ReturnType Dcm_31ServiceProcess(Dcm_MsgContextType *pMsgContext)
Description         : InputOutputControlByIdentifier
Parameters (in)     : Dcm_MsgContextType *pMsgContext 
Parameters (out)    : none
Return value        : Std_ReturnType 
Design Information  : 
**************************************************************************/
EXTERN Std_ReturnType Dcm_31ServiceProcess(Dcm_MsgContextType *pMsgContext);

/**************************************************************************
Function name       : Std_ReturnType Dcm_3DServiceProcess(Dcm_MsgContextType *pMsgContext)
Description         : RoutineControl Service 
Parameters (in)     : Dcm_MsgContextType *pMsgContext 
Parameters (out)    : none
Return value        : Std_ReturnType 
Design Information  : 
**************************************************************************/
EXTERN Std_ReturnType Dcm_3DServiceProcess(Dcm_MsgContextType *pMsgContext);

/**************************************************************************
Function name       : Std_ReturnType Dcm_3EServiceProcess(Dcm_MsgContextType *pMsgContext)
Description         : Tester Present Service 
Parameters (in)     : Dcm_MsgContextType *pMsgContext 
Parameters (out)    : none
Return value        : Std_ReturnType 
Design Information  : 
**************************************************************************/
EXTERN Std_ReturnType Dcm_3EServiceProcess(Dcm_MsgContextType *pMsgContext);
/**************************************************************************
Function name       : Std_ReturnType Dcm_27ServiceProcess(Dcm_MsgContextType *pMsgContext)
Description         : SecurityAccess Service 
Parameters (in)     : Dcm_MsgContextType *pMsgContext 
Parameters (out)    : none
Return value        : Std_ReturnType 
Design Information  : 
**************************************************************************/
EXTERN Std_ReturnType Dcm_27ServiceProcess(Dcm_MsgContextType *pMsgContext);
/**************************************************************************
Function name       : Std_ReturnType Dcm_28ServiceProcess(Dcm_MsgContextType *pMsgContext)
Description         : Communication Control Service 
Parameters (in)     : Dcm_MsgContextType *pMsgContext 
Parameters (out)    : none
Return value        : Std_ReturnType 
Design Information  : 
**************************************************************************/
EXTERN Std_ReturnType Dcm_28ServiceProcess(Dcm_MsgContextType *pMsgContext);
/**************************************************************************
Function name       : Std_ReturnType Dcm_19ServiceProcess(Dcm_MsgContextType *pMsgContext)
Description         : ReadDTCInformation Service 
Parameters (in)     : Dcm_MsgContextType *pMsgContext 
Parameters (out)    : none
Return value        : Std_ReturnType 
Design Information  : 
**************************************************************************/
EXTERN Std_ReturnType Dcm_19ServiceProcess(Dcm_MsgContextType *pMsgContext);
/**************************************************************************
Function name       : Std_ReturnType Dcm_14ServiceProcess(Dcm_MsgContextType *pMsgContext)
Description         : Clear DiagnosticInformation Service 
Parameters (in)     : Dcm_MsgContextType *pMsgContext 
Parameters (out)    : none
Return value        : Std_ReturnType 
Design Information  : 
**************************************************************************/
EXTERN Std_ReturnType Dcm_14ServiceProcess(Dcm_MsgContextType *pMsgContext);
/**************************************************************************
Function name       : Std_ReturnType Dcm_85ServiceProcess(Dcm_MsgContextType *pMsgContext)
Description         : ControlDTCSetting service 
Parameters (in)     : Dcm_MsgContextType *pMsgContext 
Parameters (out)    : none
Return value        : Std_ReturnType 
Design Information  : 
**************************************************************************/
EXTERN Std_ReturnType Dcm_85ServiceProcess(Dcm_MsgContextType *pMsgContext);
/**************************************************************************
Function name   : void Dsp_DslConfirmation
Arguments       : PduIdType DcmRxPduId, Std_ReturnType result
Return type     : void
Description     : Dcm Confirmation. 
**************************************************************************/ 
EXTERN void Dsp_DslConfirmation(PduIdType DcmRxPduId, Std_ReturnType result);
/**************************************************************************
Function name       : void Dcm_SessionChangeAction(uint8 SubFunction)
Description         : Action required on session change.
Parameters (in)     : uint8 SubFunction
Parameters (out)    : none
Return value        : none 
Design Information  : 
**************************************************************************/
EXTERN void Dcm_SessionChangeAction(uint8 SubFunction);
/**************************************************************************
Function name       : Std_ReturnType Dcm_DspService19_01Processor(Dcm_MsgContextType *pMsgContext)
Description         : Service 19 subfunction 1.
Parameters (in)     : Dcm_MsgContextType *pMsgContext 
Parameters (out)    : none
Return value        : Std_ReturnType 
Design Information  : 
**************************************************************************/
EXTERN Std_ReturnType Dcm_DspService19_01Processor(Dcm_MsgContextType *pMsgContext);
/**************************************************************************
Function name       : Std_ReturnType Dcm_DspService19_02Processor(Dcm_MsgContextType *pMsgContext)
Description         : Service 19 subfunction 2.
Parameters (in)     : Dcm_MsgContextType *pMsgContext 
Parameters (out)    : none
Return value        : Std_ReturnType 
Design Information  : 
**************************************************************************/
EXTERN Std_ReturnType Dcm_DspService19_02Processor(Dcm_MsgContextType *pMsgContext);
/**************************************************************************
Function name       : Std_ReturnType Dcm_DspService19_04Processor(Dcm_MsgContextType *pMsgContext)
Description         : Service 19 subfunction 4.
Parameters (in)     : Dcm_MsgContextType *pMsgContext 
Parameters (out)    : none
Return value        : Std_ReturnType 
Design Information  : 
**************************************************************************/
EXTERN Std_ReturnType Dcm_DspService19_04Processor(Dcm_MsgContextType *pMsgContext);
/**************************************************************************
Function name       : Std_ReturnType Dcm_DspService19_0AProcessor(Dcm_MsgContextType *pMsgContext)
Description         : Service 19 subfunction A.
Parameters (in)     : Dcm_MsgContextType *pMsgContext 
Parameters (out)    : none
Return value        : Std_ReturnType 
Design Information  : 
**************************************************************************/

EXTERN Std_ReturnType Dcm_DspService19_06Processor(Dcm_MsgContextType *pMsgContext);
/**************************************************************************
Function name       : Std_ReturnType Dcm_DspService19_0AProcessor(Dcm_MsgContextType *pMsgContext)
Description         : Service 19 subfunction A.
Parameters (in)     : Dcm_MsgContextType *pMsgContext 
Parameters (out)    : none
Return value        : Std_ReturnType 
Design Information  : 
**************************************************************************/
EXTERN Std_ReturnType Dcm_DspService19_0AProcessor(Dcm_MsgContextType *pMsgContext);

#if(DCM_DEM_LOG_DTC_EXT != FALSE)
/**************************************************************************
Function name       : Std_ReturnType Dcm_30ServiceProcess(Dcm_MsgContextType *pMsgContext)
Description         : log DTC from ext 
Parameters (in)     : Dcm_MsgContextType *pMsgContext 
Parameters (out)    : none
Return value        : Std_ReturnType 
Design Information  : 
**************************************************************************/
EXTERN Std_ReturnType Dcm_30ServiceProcess(Dcm_MsgContextType *pMsgContext);
#endif
EXTERN void Dcm_DspClear14Pending(void);

EXTERN boolean Dcm_0801_Write_ConditionProcess(void);
EXTERN boolean Dcm_FFFF_Read_NOConditionProcess(void);



/*****************************************************************************
*                              Limited Scope Prototypes                      *
******************************************************************************/

/*****************************************************************************
*                   Functions                                                *
******************************************************************************/
#undef EXTERN

#endif /* DCM_DSP_H */
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
/*By                : msavariy                                               */
/*Traceability      :                                                       */
/*Change Description: Datadesign And Framework implemented, Initial Version */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 21-Sep-2016                                           */
/*Version           :                                                       */
/*By                : akalarim                                              */
/*Traceability      :                                                       */
/*Change Description: service 10,11,22 implementation						*/
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 17-Oct-2016                                           */
/*Version           :                                                       */
/*By                : akalarim                                              */
/*Traceability      :                                                       */
/*Change Description: service 2E,2F,31 implementation						*/
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 21-Oct-2016                                           */
/*Version           :                                                       */
/*By                : akalarim                                              */
/*Traceability      :                                                       */
/*Change Description: service 3E,27 implementation						    */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 22-Nov-2016                                           */
/*Version           :                                                       */
/*By                : akalarim                                              */
/*Traceability      : RTC 746031                                            */
/*Change Description: service 28 implementation						        */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 20-Jan-2017                                           */
/*Version           :                                                       */
/*By                : akalarim                                              */
/*Traceability      : RTC 765864,765855,765852.                             */
/*Change Description: Service 0x14,0x85 and sercice 19 with subfunction 0x01*/
/*                    0x02 and 0x0A Implementation.                         */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 3-April-2017                                          */
/*Version           :                                                       */
/*By                : akalarim                                              */
/*Traceability      : RTC 838240                                            */
/*Change Description: Fixed the compiler warnings.                          */
/*--------------------------------------------------------------------------*/
