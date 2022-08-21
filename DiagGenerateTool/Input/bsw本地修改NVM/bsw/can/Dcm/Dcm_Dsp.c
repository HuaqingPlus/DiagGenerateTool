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
*  File Name         :  Dcm_Dsp.c                                            *
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

#ifndef DCM_DSP_C
#define DCM_DSP_C

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "Dcm_Dsp.h"
#include "Dcm.h"
//#include "Dcm_Internal.h"
#include "Dem.h"
#include "Dem_Dcm.h"
#include "Rte_DcmExt.h"
//#include "canEOL.h"
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
/*
#define DCM_DIDMGR_OP_READ          0x01
#define DCM_DIDMGR_OP_WRITE         0x02
#define DCM_DIDMGR_OP_IO            0x04
*/
#define DCM_DIDMGR_OPTYPE_READ                     0x01
#define DCM_DIDMGR_OPTYPE_WRITE                    0x02
//#define DCM_DIDMGR_OPTYPE_READCHKCOND              0x03
#define DCM_DIDMGR_OPTYPE_IO       				   0x04

#define DCM_DIDMGR_OPTYPE_IO_RETCTRL2ECU        0x01
#define DCM_DIDMGR_OPTYPE_IO_RST2DEF            0x02
#define DCM_DIDMGR_OPTYPE_IO_FRZCURSTATE        0x04
#define DCM_DIDMGR_OPTYPE_IO_SHRTTRMADJ         0x08



#define DCM_DIDMGR_OPCLS_READ_SYNC                   0x01
#define DCM_DIDMGR_OPCLS_READ_ASYNC                  0x02

#define DCM_DIDMGR_OPCLS_WRITE_SYNC          0x01
#define DCM_DIDMGR_OPCLS_WRITE_ASYNC         0x02

#define DCM_DIDMGR_RETCTRL2ECU_SYNC         0x00
#define DCM_DIDMGR_RST2DEF_SYNC             0x01
#define DCM_DIDMGR_FRZCURSTATE_SYNC         0x02
#define DCM_DIDMGR_SHRTTRMADJ_SYNC          0x03
#define DCM_DIDMGR_RETCTRL2ECU_ASYNC        0x04
#define DCM_DIDMGR_RST2DEF_ASYNC            0x05
#define DCM_DIDMGR_FRZCURSTATE_ASYNC        0x06
#define DCM_DIDMGR_SHRTTRMADJ_ASYNC         0x07


/*
*  Routine Control
*/

# define DCM_RIDMGR_OP_START                        0x01
# define DCM_RIDMGR_OP_STOP                         0x02
# define DCM_RIDMGR_OP_REQRSLTS                     0x04

/*# define DCM_RIDMGR_OPTYPE_NONE
# define DCM_RIDMGR_OPTYPE_REQ
# define DCM_RIDMGR_OPTYPE_REQ_RES
# define DCM_RIDMGR_OPTYPE_RES
# define DCM_RIDMGR_OPTYPE_REQ_DYNLEN
# define DCM_RIDMGR_OPTYPE_REQ_DYNLEN_RES
# define DCM_RIDMGR_OPTYPE_RES_DYNLEN
# define DCM_RIDMGR_OPTYPE_REQ_DYNLEN_RES_DYNLEN
# define DCM_RIDMGR_OPTYPE_REQ_RES_DYNLEN           */

#if 0
/*Session Types */
#define DEFAULT_SESSION     0x01
#define PROGRAMMING_SESSION 0x02
#define EXTENDED_SESSION    0x03
#define EOL_SESSION.........0x04
#endif

/* Reset Types */
#define HARD        0x00
#define KEYONOFF    0x01
#define SOFT        0x02

#define S10_MAX_SUPPORTED_SUB_FUNCTION 0x03

#define S11_MAX_SUPPORTED_SUB_FUNCTION 0x03
#define S11_SUB_FUNCTION_HardReset     0x01
#define S11_SUB_FUNCTION_SoftReset     0x03

#define S22_MAX_SUPPORTED_DID_READ     0x01
#define S31_MAX_SUPPORTED_SUB_FUNCTION 0x03

#define DCM_DSP_DID_READ          0x01
#define DCM_DSP_DID_WRITE         0x02
#define DCM_DSP_DID_IO            0x04

#define DCM_DSP_RETCTRL2ECU        0x00
#define DCM_DSP_RST2DEF            0x01
#define DCM_DSP_FRZCURSTATE        0x02
#define DCM_DSP_SHRTTRMADJ         0x03


#define DCM_DSP_RID_START          0x01
#define DCM_DSP_RID_STOP           0x02
#define DCM_DSP_RID_RESULTS        0x03

/* Extract a concrete byte of a WORD */
#define Dsp_UtiGetHiByte(data16)                                    ((uint8)(((uint16)(data16))>>8))                                                /* PRQA S 3453 */ /* MD_MSR_19.7 */
#define Dsp_UtiGetLoByte(data16)                                    ((uint8)(((uint16)(data16)) & 0xFFu))                                           /* PRQA S 3453 */ /* MD_MSR_19.7 */

#define DSP_PerformHardReset		0x01
#define DSP_PerformSoftReset		0x02

#define DSP_Fbl_EntryReset			0x02
#define DSP_Diag_Entered			0x04
#define DSP_EOL_Entered				0x08


typedef uint8 Dcm_DspDiagCheckLvlType;
#define DSP_DIAG_CHK_LVL_SERVICE_ID   ((Dcm_DspDiagCheckLvlType)0u)
#define DSP_DIAG_CHK_LVL_PARAMETER    ((Dcm_DspDiagCheckLvlType)1u)
#define DSP_DIAG_CHK_LVL_SUBFUNC      ((Dcm_DspDiagCheckLvlType)2u)
#define DSP_NUM_DIAG_CHK_LVLS         (DSP_DIAG_CHK_LVL_SUBFUNC + 1u)


static const Dcm_NegativeResponseCodeType  Dcm_StateSessionNrcs[DSP_NUM_DIAG_CHK_LVLS]=
{
  DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION      /* on SID level */
 ,DCM_E_REQUESTOUTOFRANGE                       /* on Parameter (DID, RID, etc.) level */
 ,DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION  /* on SubFunction level */
};

#if 0
# pragma ghs section data = ".fbl_magic_flag"
uint32 APPLN_REQUEST = 0;
# pragma ghs section data=default
#endif

# pragma ghs section data = ".fbl_magic_flag"
uint8 fblAppMagicFlag[4] = {0xFFu,0xFFu,0xFFu,0xFFu};
# pragma ghs section data=default

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/
typedef uint8 Dcm_Svc19DemSetFilterClassType;
typedef uint8 Dcm_Svc19DemSetFilterMaskUsageType;


# define DEM_SETFILTER_CLASS_01                           ((Dcm_Svc19DemSetFilterClassType)0u) /* SF 0x01, 0x02, 0x0A */
# define DEM_SETFILTER_CLASS_02                           ((Dcm_Svc19DemSetFilterClassType)1u) /* SF 0x07 */
# define DEM_SETFILTER_CLASS_03                           ((Dcm_Svc19DemSetFilterClassType)2u) /* SF 0x11, 0x0F  */
# define DEM_SETFILTER_CLASS_04                           ((Dcm_Svc19DemSetFilterClassType)3u) /* SF 0x12, 0x13 */
# define DEM_SETFILTER_CLASS_05                           ((Dcm_Svc19DemSetFilterClassType)4u) /* SF 0x15 */
# define DEM_SETFILTER_CLASS_06                           ((Dcm_Svc19DemSetFilterClassType)5u) /* SF 0x17 */
# define DEM_SETFILTER_NUM_CLASSES                        (DEM_SETFILTER_CLASS_06+1u)

# define DCM_SVC_19_USE_MASK_REQ                                     ((Dcm_Svc19DemSetFilterMaskUsageType)0u)
# define DCM_SVC_19_USE_MASK_ALL                                     ((Dcm_Svc19DemSetFilterMaskUsageType)1u)

struct DCM_SVC19DEMDTCFILTERINFOTYPE_TAG
{
	Dem_DTCKindType             Kind;
	Dem_DTCOriginType           Origin;
	Dem_FilterWithSeverityType  ConsiderSeverity;
};
typedef struct DCM_SVC19DEMDTCFILTERINFOTYPE_TAG Dcm_Svc19DemDtcFilterInfoType;

static const Dcm_Svc19DemDtcFilterInfoType Dcm_Svc19DemDtcFilterInfo[DEM_SETFILTER_NUM_CLASSES] =                              /* PRQA S 3218 */ /* MD_Dcm_CodingRule_3218 */
{
	{
		DEM_DTC_KIND_ALL_DTCS,           DEM_DTC_ORIGIN_PRIMARY_MEMORY,   DEM_FILTER_WITH_SEVERITY_NO
	}  /* SF 0x01, 0x02, 0x0A */
	,{
		DEM_DTC_KIND_ALL_DTCS,           DEM_DTC_ORIGIN_PRIMARY_MEMORY,   DEM_FILTER_WITH_SEVERITY_YES
	} /* SF 0x07 */
	,{
		DEM_DTC_KIND_ALL_DTCS,           DEM_DTC_ORIGIN_MIRROR_MEMORY,    DEM_FILTER_WITH_SEVERITY_NO
	}  /* SF 0x11, 0x0F  */
	,{
		DEM_DTC_KIND_EMISSION_REL_DTCS,  DEM_DTC_ORIGIN_PRIMARY_MEMORY,   DEM_FILTER_WITH_SEVERITY_NO
	}  /* SF 0x12, 0x13 */
	,{
		DEM_DTC_KIND_ALL_DTCS,           DEM_DTC_ORIGIN_PERMANENT_MEMORY, DEM_FILTER_WITH_SEVERITY_NO
	}  /* SF 0x15 */
	,{
		DEM_DTC_KIND_ALL_DTCS,           DEM_DTC_ORIGIN_SECONDARY_MEMORY, DEM_FILTER_WITH_SEVERITY_NO
	}  /* SF 0x17 */
};


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

static Dcm_NegativeResponseCodeType Dcm_DspCheckSessionSecurity(uint8 StateRef,Dcm_DspDiagCheckLvlType LevelRef);
static uint8 Dcm_DspGetStateRefIndex(uint8 Index, uint8 Operations, uint8 ConditionRef);
static uint8 Dcm_S31_Opindex_check(uint8 operation ,uint8 subfunction);
static Boolean Request_seed_rcvd = FALSE;
static uint8 Old_Session;
static uint8 Communication_Status;
static uint8 Dsp_PostProcessingFlag;
static Boolean Dsp_14SvcRpHandleFlag;
static uint32  Group_DTC;
static uint8 S27_SeedBuffer[4] = {0,0,0,0};
static uint8 l_smrs_status_u8 = FALSE;

#ifdef S27_DELAY_SUPPORTED
static uint8 S27_fail_counter = 0;
static Boolean S27_reset_delay = FALSE;
#endif

static uint16 No_Of_Matching_DTC;
boolean DCM_ENABLE_RX_TX_NORM_NM_flag;


#if(DCM_DEM_LOG_DTC_EXT != FALSE)
uint8 data_byte = 0;
uint8 dem_event_byte_one = 0;
uint8 dem_event_byte_two = 0;
uint8 dem_event_byte_three = 0;
uint8 dem_event_byte_four = 0;
uint8 dem_event_byte_five = 0;
uint8 dem_event_send_flag = 0;
uint8 dem_event_counter = 0;
uint16 dem_opcycle_counter = 0;
uint8 bit_position;
uint8 byte_position;
uint8 bit_status;
uint8 l_cycle_state;
boolean DemOPCycleStop;
#endif

static Std_ReturnType Dcm_DspSvc19UtiReportNumDtcByStatusMaskData(uint8 dsfClass,uint8 dtcStatusMask,uint8 dtcSeverity,Dcm_MsgContextType *pMsgContext);
static Std_ReturnType Dcm_DspSvc19UtiDemGetNumFltrdDtc(Dcm_MsgContextType *pMsgContext);
static Std_ReturnType Dcm_DspSvc19UtiReportDtcByStatusMaskData(uint8 dsfClass,Dcm_Svc19DemSetFilterMaskUsageType maskUsage,Dcm_MsgContextType *pMsgContext);
static Std_ReturnType Dcm_DspSvc19UtiDemGetNxtFltrdDtc(Dcm_MsgContextType *pMsgContext);
static Std_ReturnType Dcm_DspSvc19UtiCpyLinearData(Dcm_MsgContextType *pMsgContext);
static Std_ReturnType Dcm_DspSvc19UtiCpyDemGetNxtFltrdDtc(Dcm_MsgType pData,Dcm_MsgLenType* pAvailLen);
static Dcm_NegativeResponseCodeType Dcm_27Service_seed_Process(Dcm_MsgContextType *pMsgContext,uint8 Counter);
static Dcm_NegativeResponseCodeType Dcm_27Service_key_Process(Dcm_MsgContextType *pMsgContext,uint8 Counter);

/* Qiuhuaqing Modify, add timer */

Dcm_27Service_TimerType S27Timer;
static void Dcm_27Timer_Init(void);
static void Dcm_27Timer_Start(uint8 TimerId);
static void Dcm_27Timer_Stop(uint8 TimerId);
static void Dcm_27Timer_Process(void);
static void Dcm_27Timer_IsTimeout(uint8 TimerId, boolean* Timeout);

/*****************************************************************************
*                              Limited Scope Prototypes                      *
******************************************************************************/
static Std_ReturnType Dcm_DspSvc19UtiReportDtcSnapshotData(uint32 dtcid,Dcm_MsgContextType *pMsgContext);


/*****************************************************************************
*                   Functions                                                *
******************************************************************************/

/**************************************************************************
Function name       : void Dsp_Init(void)
Description         : Initializes the Diag Service Processing
Parameters (in)     : None.
Parameters (out)    : None
Return value        : None
Design Information  :
**************************************************************************/

void Dsp_Init(void)
{
	DcmExt_Init();
	Old_Session = DCM_DEFAULT_SESSION;
	Communication_Status = DCM_ENABLE_RX_TX_NORM;
	Dsp_PostProcessingFlag = 0;
	Dsp_14SvcRpHandleFlag = 0;
#if(DCM_DEM_LOG_DTC_EXT != FALSE)
	l_cycle_state = 0;
	dem_event_counter = 0;
	dem_opcycle_counter = 0;
	DemOPCycleStop = 0;
#endif
#ifdef S27_DELAY_SUPPORTED
	S27_reset_delay = TRUE;
	S27_fail_counter = 0;
	Dcm_27Timer_Init();
	Dcm_27Timer_Start(TIMER_RESET);
#endif
	DCM_ENABLE_RX_TX_NORM_NM_flag = FALSE;

}

/**************************************************************************
Function name       : void Dsp_Init(void)
Description         : Diag Service Processing Main function
Parameters (in)     : None.
Parameters (out)    : None
Return value        : None
Design Information  :
**************************************************************************/

void Dsp_Main(void)
{
#if(DCM_DEM_LOG_DTC_EXT != FALSE)
	uint8 fl_retVal[NoOfDTCevents];
	uint8 dem_bit_counter = 0;
#endif
	Std_ReturnType RetVal;
	DcmExt_Main();

	/* Qiuhuaqing Modify, add Timer process */
	Dcm_27Timer_Process();

	if(Dsp_14SvcRpHandleFlag != FALSE)
	{
		RetVal = Dem_DcmClearDTC(Group_DTC,DEM_DTC_FORMAT_UDS,DEM_DTC_ORIGIN_PRIMARY_MEMORY);
		if(RetVal == DCM_DEM_RET_CLEAR_OK)
		{
			Dsp_14SvcRpHandleFlag = FALSE;
			Dcm_ExternalProcessingDone();
		}
	}
#if(DCM_DEM_LOG_DTC_EXT != FALSE)

	dem_opcycle_counter = dem_opcycle_counter + 1;

    if(dem_opcycle_counter == 20)
    {
        (void)Dem_SetOperationCycleState(DemConf_DemOperationCycle_DemOperationCycle_Ignition, DEM_CYCLE_STATE_START);
    }
    if(dem_opcycle_counter == 100)
    {
        (void)Dem_SetOperationCycleState(DemConf_DemOperationCycle_DemOperationCycle_Profile4, DEM_CYCLE_STATE_START);
        (void)Dem_SetOperationCycleState(DemConf_DemOperationCycle_DemOperationCycle_Profile3, DEM_CYCLE_STATE_START);
    }

	if((dem_opcycle_counter >= 100) && ((dem_opcycle_counter <= 3000)))
	{
	    dem_opcycle_counter = 1000;
		dem_event_counter = dem_event_counter + 1;
		if(dem_event_counter == 10)
		{
			dem_event_counter = 0;
			if(dem_event_send_flag  == 1)
			{
				for(dem_bit_counter = 0;dem_bit_counter < NoOfDTCevents;dem_bit_counter++)
				{
					bit_position = dem_bit_counter % 8;
					byte_position = dem_bit_counter / 8;
					if(byte_position == 0)
					{
						data_byte = dem_event_byte_one;
					}
					else if(byte_position == 1)
					{
						data_byte = dem_event_byte_two;
					}
					else if(byte_position == 2)
					{
						data_byte = dem_event_byte_three;
					}
					else if(byte_position == 3)
					{
						data_byte = dem_event_byte_four;
					}
					else if(byte_position == 4)
					{
						data_byte = dem_event_byte_five;
					}

					else
					{

					}

					bit_status = (data_byte >> (7 - bit_position));
					if((dem_bit_counter != 25) && (dem_bit_counter != 0))
					{
                        if(FALSE != (bit_status & 0x01))
                        {
                            fl_retVal[dem_bit_counter] = Dem_SetEventStatus(dem_bit_counter + 1,2);
                        }
                        else
                        {
                            fl_retVal[dem_bit_counter] = Dem_SetEventStatus(dem_bit_counter + 1,3);
                        }
					}
					else
					{
                        if(FALSE != (bit_status & 0x01))
                        {
                            (void)Dem_ReportErrorStatus(dem_bit_counter + 1,2);
                        }
                        else
                        {
                            (void)Dem_ReportErrorStatus(dem_bit_counter + 1,3);
                        }
					}
					/*RetVal_temp = Dem_SetEventStatus(2,3);*/

				}
			/*	Dem_SetEventStatus(2,3);*/
				/*Dem_SetEventStatus(3,3);*/
			}
		}
	}

	if(DemOPCycleStop != FALSE)
	{
	    dem_opcycle_counter = 0;
	    DemOPCycleStop = 0;
		(void)Dem_SetOperationCycleState(DemConf_DemOperationCycle_DemOperationCycle_Profile4, DEM_CYCLE_STATE_END);
		(void)Dem_SetOperationCycleState(DemConf_DemOperationCycle_DemOperationCycle_Profile3, DEM_CYCLE_STATE_END);
        (void)Dem_SetOperationCycleState(DemConf_DemOperationCycle_DemOperationCycle_Ignition, DEM_CYCLE_STATE_END);
	}


   /*	else if(dem_event_counter == 3)
	{
		(void)Dem_SetOperationCycleState(DemConf_DemOperationCycle_DemOperationCycle_Profile4, DEM_CYCLE_STATE_START);
	}
	else if(dem_event_counter == 4)
	{
		(void)Dem_SetOperationCycleState(DemConf_DemOperationCycle_DemOperationCycle_Profile3, DEM_CYCLE_STATE_START);
	}
	else if(dem_event_counter == 1)
	{
		(void)Dem_SetOperationCycleState(DemConf_DemOperationCycle_DemOperationCycle_Profile4, DEM_CYCLE_STATE_END);
	}
	else if(dem_event_counter == 2)
	{
		(void)Dem_SetOperationCycleState(DemConf_DemOperationCycle_DemOperationCycle_Profile3, DEM_CYCLE_STATE_END);
	}
	else
	{
	}*/


#endif
}

/**************************************************************************
Function name       : Std_ReturnType Dcm_10ServiceProcess(Dcm_MsgContextType *pMsgContext)
Description         : DiagnosticSessionControl 0x10 service
Parameters (in)     : Dcm_MsgContextType *pMsgContext
Parameters (out)    : none
Return value        : Std_ReturnType
Design Information  :
**************************************************************************/

Std_ReturnType Dcm_10ServiceProcess(Dcm_MsgContextType *pMsgContext)
{
	uint8   SubFunction;
	Std_ReturnType RetVal;
	uint8 index;
	uint8 StateRef;
	Dcm_NegativeResponseCodeType  NegRes;

	RetVal = DCM_E_NOT_OK;

	SubFunction = pMsgContext->reqData[0];
	NegRes = DCM_E_SUBFUNCTIONNOTSUPPORTED;
	for(index=0; index < NO_OF_SUPPORTTED_SESSIONS; index++)
	{
		if(SubFunction == Dcm_DsdSubService10[index].SubServiceId)
		{
			NegRes = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
			if(pMsgContext->reqDataLen == 1u)
			{
				NegRes = DCM_E_CONDITIONSNOTCORRECT;
				StateRef = Dcm_DsdSubService10[index].State_Ref;
				RetVal = Dcm_DspCheckSessionSecurity(StateRef,DSP_DIAG_CHK_LVL_PARAMETER);

				if(DCM_E_OK == RetVal)
				{
					RetVal = Dcm_DsdSubService10[index].SubServiceFnc();

					if(DCM_E_OK == RetVal)
					{
						NegRes = DCM_E_OK;
						DslInternal_SetSecurityLevel(DCM_SEC_LEV_LOCKED);
						if(SubFunction != Old_Session)
						{
							DslInternal_SetSesCtrlType(SubFunction);
							Old_Session = SubFunction;
						}
						pMsgContext->resData =  &pMsgContext->resData[2];

						pMsgContext->resData[0] = Dsp_UtiGetHiByte(Dcm_DsdSessionInfo[index].P2);
						pMsgContext->resData[1] = Dsp_UtiGetLoByte(Dcm_DsdSessionInfo[index].P2);
						pMsgContext->resData[2] = Dsp_UtiGetHiByte(Dcm_DsdSessionInfo[index].P2Star);
						pMsgContext->resData[3] = Dsp_UtiGetLoByte(Dcm_DsdSessionInfo[index].P2Star);
						pMsgContext->resDataLen = 4u;
					}
				}
			}
			break;
		}
	}

	if(NegRes != DCM_E_OK)
	{
		Dcm_ExternalSetNegResponse(NegRes);
		Dcm_ExternalProcessingDone();
	}
	return(RetVal);
}


/**************************************************************************
Function name       : Std_ReturnType Dcm_01DefaultProcess(void)
Description         :
Parameters (in)     :
Parameters (out)    : none
Return value        : Std_ReturnType
Design Information  :
**************************************************************************/
Std_ReturnType Dcm_01DefaultProcess(void)
{
	Dcm_ExternalProcessingDone();
	return(DCM_E_OK);
}

/**************************************************************************
Function name       : Std_ReturnType Dcm_0801_Write_ConditionProcess(void)
Description         :
Parameters (in)     :
Parameters (out)    : none
Return value        : Std_ReturnType
Design Information  :
**************************************************************************/
Boolean Dcm_0801_Write_ConditionProcess(void)
{
	return (0);
}

/**************************************************************************
Function name       : Std_ReturnType Dcm_FFFF_Read_NOConditionProcess(void)
Description         :
Parameters (in)     :
Parameters (out)    : none
Return value        : Std_ReturnType
Design Information  :
**************************************************************************/
Boolean Dcm_FFFF_Read_NOConditionProcess(void)
{

	return (TRUE);
}


/**************************************************************************
Function name       : Std_ReturnType Dcm_02PgmProcess(void)
Description         :
Parameters (in)     :
Parameters (out)    : none
Return value        : Std_ReturnType
Design Information  :
**************************************************************************/
Std_ReturnType Dcm_02PgmProcess(void)
{
	Std_ReturnType RetVal;
	RetVal = DCM_E_NOT_OK;

	if(FALSE != DSP_APP_PROG_ENTRY_CONDITION)
	{

		fblAppMagicFlag[0] = 0x11;
		fblAppMagicFlag[1] = 0x22;
		fblAppMagicFlag[2] = 0x33;
		fblAppMagicFlag[3] = 0x44;

		RetVal = DCM_E_FORCE_RCRRP;
		/* Write the Magic Flag for Program Entry */
		Dsp_PostProcessingFlag |= DSP_Fbl_EntryReset;
		/* Don't invoke processing done for 78 Response */
	}
	else
	{
		RetVal = DCM_E_NOT_OK;
		//Dcm_ExternalProcessingDone();
	}
	return (RetVal);
}

/**************************************************************************
Function name       : Std_ReturnType Dcm_03ExtnDiagProcess(void)
Description         :
Parameters (in)     :
Parameters (out)    : none
Return value        : Std_ReturnType
Design Information  :
**************************************************************************/
Std_ReturnType Dcm_03ExtnDiagProcess(void)
{
	Std_ReturnType RetVal;
	RetVal = DCM_E_NOT_OK;

	if(FALSE != DSP_APP_DIAG_ENTRY_CONDITION)
	{
		RetVal = DCM_E_OK;
		Dsp_PostProcessingFlag |= DSP_Diag_Entered;
		Dcm_ExternalProcessingDone();
	}
	else
	{
		RetVal = DCM_E_NOT_OK;
	}
	return (RetVal);
}

/**************************************************************************
Function name       : Std_ReturnType Dcm_60EOLDiagProcess(void)
Description         :
Parameters (in)     :
Parameters (out)    : none
Return value        : Std_ReturnType
Design Information  :
**************************************************************************/
Std_ReturnType Dcm_04EOLDiagProcess(void)
{
	Std_ReturnType RetVal;
	RetVal = DCM_E_NOT_OK;

	if(FALSE != DSP_APP_EOL_ENTRY_CONDITION)
	{
		RetVal = DCM_E_OK;
		Dsp_PostProcessingFlag = 0;
		Dsp_PostProcessingFlag |= DSP_EOL_Entered;

		if(DCM_E_OK == Communication_action(DCM_DISABLE_RX_TX_NORM_NM))
		{
			Communication_Status = DCM_DISABLE_RX_TX_NORM_NM;

			/* Qiuhuaqing Modify,  To be Release after EOL Finished */
			//CANEOL_Entry_Function();
		}
		else
		{
			/*do nothing*/
			RetVal = DCM_E_NOT_OK;
		}
	}
	return(RetVal);
}

/**************************************************************************
Function name       : Std_ReturnType Dcm_11ServiceProcess(Dcm_MsgContextType *pMsgContext)
Description         : ECUReset
Parameters (in)     : Dcm_MsgContextType *pMsgContext
Parameters (out)    : none
Return value        : Std_ReturnType
Design Information  :
**************************************************************************/
Std_ReturnType Dcm_11ServiceProcess(Dcm_MsgContextType *pMsgContext)
{
	uint8   SubFunction;
	Dcm_NegativeResponseCodeType  NegRes;
	Dcm_SesCtrlType fl_Session;
	NegRes = DCM_E_SUBFUNCTIONNOTSUPPORTED;

	SubFunction = pMsgContext->reqData[0];
	(void)Dcm_GetSesCtrlType(&fl_Session);

	if((S11_SUB_FUNCTION_SoftReset == SubFunction) || \
	  ((S11_SUB_FUNCTION_HardReset == SubFunction) && EOL_SESSION == fl_Session))
	{
		NegRes = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
		if(pMsgContext->reqDataLen == 1u)
		{
			if(FALSE != DCM_DSP_S11_TRIGGER_CONDITION)
			{
                if(SubFunction == S11_SUB_FUNCTION_HardReset)
                {
					Dsp_PostProcessingFlag |= DSP_PerformHardReset;
				}
                else if(SubFunction == S11_SUB_FUNCTION_SoftReset)
				{
					Dsp_PostProcessingFlag |= DSP_PerformSoftReset;
				}
				pMsgContext->resData = &pMsgContext->resData[2];
				pMsgContext->resDataLen = 0u;
				NegRes = DCM_E_OK;
			}
			else
			{
				NegRes = DCM_E_CONDITIONSNOTCORRECT;
			}
		}
	}
	if(NegRes == DCM_E_OK)
	{
		Dcm_ExternalProcessingDone();
	}
	else
	{
		Dcm_ExternalSetNegResponse(NegRes);
		Dcm_ExternalProcessingDone();
	}
	return(DCM_E_OK);
}
/**************************************************************************
Function name       : Std_ReturnType Dcm_22ServiceProcess(Dcm_MsgContextType *pMsgContext)
Description         : ReadDataByIdentifier Service
Parameters (in)     : Dcm_MsgContextType *pMsgContext
Parameters (out)    : none
Return value        : Std_ReturnType
Design Information  :
**************************************************************************/
Std_ReturnType Dcm_22ServiceProcess(Dcm_MsgContextType *pMsgContext)
{
	Dcm_NegativeResponseCodeType  NegRes;
	Std_ReturnType RetVal;
	uint16  Did;
	uint8   Counter;
	uint8   Length;
	uint8   Index;
	uint8   StateRef;

	RetVal = DCM_E_OK;

	NegRes = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
	/* Get the 16 bit DID from the pMsgContext*/
	Did = ((uint16)((((uint16)pMsgContext->reqData[0] << 8)) | (uint16)(pMsgContext->reqData[1])));
	if( ((pMsgContext->reqDataLen & 0x01u) == 0) /* length is an odd (wrong) or even (right) number */
		&&(pMsgContext->reqDataLen <= (Dcm_MsgLenType)(S22_MAX_SUPPORTED_DID_READ * 2)) )    /* Also the capacity of the ECU shall not be exceeded */
	{
		Length  = (uint8)Dcm_DspDidIdentifierTable[0];
		for(Counter = 0; Counter < Length ; Counter++)
		{
			NegRes = DCM_E_REQUESTOUTOFRANGE;
			if(Dcm_DspDidIdentifierTable[Counter + 1] == Did)
			{
				if((Dcm_DspDidInfo[Counter].Operations & DCM_DIDMGR_OPTYPE_READ) == DCM_DIDMGR_OPTYPE_READ)
				{
					Index = Dcm_DspDidInfo[Counter].OpInfoRef;
					StateRef = Dcm_DspDidOpInfo[Index].State_Ref;
					NegRes = Dcm_DspCheckSessionSecurity(StateRef,DSP_DIAG_CHK_LVL_PARAMETER);
					if(DCM_E_OK == NegRes)
					{
						NegRes = DCM_E_CONDITIONSNOTCORRECT;
						if(FALSE != (Dcm_DspDidOpInfo[Index].CallTypes & DCM_DIDMGR_OPCLS_READ_SYNC))
						{
							Index = Dcm_DspDidOpInfo[Index].SignalInfo_Ref;
							NegRes = DCM_E_SERVICENOTSUPPORTED;
							if(FALSE != (Dcm_DspDidSignalInfo[Index].FunClass & DCM_DIDMGR_OPCLS_READ_SYNC))
							{
								NegRes = DCM_E_OK;
								pMsgContext->resData = &pMsgContext->resData[3];
								RetVal = DidOpFunc[Dcm_DspDidSignalInfo[Index].DidOpFunc_Ref](DCM_DSP_DID_READ,Did,pMsgContext->resData,&pMsgContext->resDataLen);
							}
						}
					}
				}
				break;
			}
		}
	}
	else
	{
		NegRes = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
	}

	if(NegRes != DCM_E_OK)
	{
		Dcm_ExternalSetNegResponse(NegRes);
		Dcm_ExternalProcessingDone();
	}
	return(RetVal);
}

/**************************************************************************
Function name       : Std_ReturnType Dcm_2EServiceProcess(Dcm_MsgContextType *pMsgContext)
Description         : WriteDataByIdentifier Service
Parameters (in)     : Dcm_MsgContextType *pMsgContext
Parameters (out)    : none
Return value        : Std_ReturnType
Design Information  :
**************************************************************************/
Std_ReturnType Dcm_2EServiceProcess(Dcm_MsgContextType *pMsgContext)
{
	Dcm_NegativeResponseCodeType  NegRes;
	Std_ReturnType RetVal;
	uint16  Did;
	uint8   Counter;
	uint8   Length;
	uint8   Index;
	uint8   StateRef;

	RetVal = DCM_E_OK;

	NegRes = DCM_E_SERVICENOTSUPPORTED;
	Did = ((uint16)((((uint16)pMsgContext->reqData[0] << 8)) | (uint16)(pMsgContext->reqData[1])));

	Length  = (uint8)Dcm_DspDidIdentifierTable[0];
	for(Counter=0; Counter < Length ; Counter++)
	{
		NegRes = DCM_E_REQUESTOUTOFRANGE;
		if(Dcm_DspDidIdentifierTable[Counter+1] == Did)
		{
			NegRes = DCM_E_REQUESTOUTOFRANGE;
			if((Dcm_DspDidInfo[Counter].Operations & DCM_DIDMGR_OPTYPE_WRITE) == DCM_DIDMGR_OPTYPE_WRITE)
			{
				NegRes = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;

				if((Dcm_DspDidInfo[Counter].Length + 2) == pMsgContext->reqDataLen)
				{
					Index = Dcm_DspDidInfo[Counter].OpInfoRef;
					Index = Dcm_DspGetStateRefIndex(Index, Dcm_DspDidInfo[Counter].Operations, DCM_DIDMGR_OPTYPE_WRITE);
					StateRef = Dcm_DspDidOpInfo[Index].State_Ref;
					NegRes = Dcm_DspCheckSessionSecurity(StateRef,DSP_DIAG_CHK_LVL_PARAMETER);
					if(DCM_E_OK == NegRes)
					{
						NegRes = DCM_E_CONDITIONSNOTCORRECT;
						if(FALSE != (Dcm_DspDidOpInfo[Index].CallTypes & DCM_DIDMGR_OPCLS_WRITE_SYNC))
						{
							Index = Dcm_DspDidOpInfo[Index].SignalInfo_Ref;
							NegRes = DCM_E_CONDITIONSNOTCORRECT;
							//if(FALSE != Dcm_DspDidConditionProcess[Counter]())
							if(DSP_APP_DIAG_ENTRY_CONDITION) //Qiuhuaqing Modify, set Diag Entry Conditon
							{
								if(FALSE != (Dcm_DspDidSignalInfo[Index].FunClass & DCM_DIDMGR_OPCLS_WRITE_SYNC))
								{
									NegRes = DCM_E_OK;
									pMsgContext->resData = &pMsgContext->resData[3];
									RetVal = DidOpFunc[Dcm_DspDidSignalInfo[Index].DidOpFunc_Ref](DCM_DSP_DID_WRITE,Did,pMsgContext->resData,&pMsgContext->resDataLen);
								}
							}
						}
					}
				}
			}
			break;
		}
	}
	if(NegRes != DCM_E_OK)
	{
		Dcm_ExternalSetNegResponse(NegRes);
		Dcm_ExternalProcessingDone();

	}
	return(RetVal);
}

/**************************************************************************
Function name       : Std_ReturnType Dcm_23ServiceProcess(Dcm_MsgContextType *pMsgContext)
Description         : ReadMemoryByAddress Service
Parameters (in)     : Dcm_MsgContextType *pMsgContext
Parameters (out)    : none
Return value        : Std_ReturnType
Design Information  :
**************************************************************************/
Std_ReturnType Dcm_23ServiceProcess(Dcm_MsgContextType *pMsgContext)
{
	Std_ReturnType lStdRet;
	lStdRet = DCM_E_OK;
	/*QAC fix*/
	pMsgContext->reqData[0] = 0;
	return  lStdRet;
}

/**************************************************************************
Function name       : Std_ReturnType Dcm_3DServiceProcess(Dcm_MsgContextType *pMsgContext)
Description         : WriteMemoryByAddress Service
Parameters (in)     : Dcm_MsgContextType *pMsgContext
Parameters (out)    : none
Return value        : Std_ReturnType
Design Information  :
**************************************************************************/

Std_ReturnType Dcm_3DServiceProcess(Dcm_MsgContextType *pMsgContext)
{
	Std_ReturnType lStdRet;
	lStdRet = DCM_E_OK;
	/*QAC fix*/
	pMsgContext->reqData[0] = 0;
	return  lStdRet;
}

/**************************************************************************
Function name       : Std_ReturnType Dcm_2FServiceProcess(Dcm_MsgContextType *pMsgContext)
Description         : InputOutputControlByIdentifier
Parameters (in)     : Dcm_MsgContextType *pMsgContext
Parameters (out)    : none
Return value        : Std_ReturnType
Design Information  :
**************************************************************************/
Std_ReturnType Dcm_2FServiceProcess(Dcm_MsgContextType *pMsgContext)
{
	Dcm_NegativeResponseCodeType  NegRes = 0;
	Std_ReturnType RetVal;
	uint16  Did;
	uint8   Counter;
	uint8   Length;
	uint8   Index;
	uint8   StateRef;

	RetVal = DCM_E_OK;

	Did = ((uint16)((((uint16)pMsgContext->reqData[0] << 8)) | (uint16)(pMsgContext->reqData[1])));
	Length  = (uint8)Dcm_DspDidIdentifierTable[0];
	for(Counter=0; Counter < Length ; Counter++)
	{
		NegRes = DCM_E_REQUESTOUTOFRANGE;
		if(Dcm_DspDidIdentifierTable[Counter+1] == Did)
		{
			Length = 0x0;
			if(DCM_DSP_SHRTTRMADJ == pMsgContext->resData[3])
			{
				Length = Dcm_DspDidInfo[Counter].Length;
			}
			NegRes = DCM_E_REQUESTOUTOFRANGE;
			if((Dcm_DspDidInfo[Counter].Operations & DCM_DIDMGR_OPTYPE_IO) == DCM_DIDMGR_OPTYPE_IO)
			{
				NegRes = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
				if((Length + 3) == pMsgContext->reqDataLen)
				{
					NegRes = DCM_E_REQUESTOUTOFRANGE;
					Index = Dcm_DspDidInfo[Counter].OpInfoRef;
					Index = Dcm_DspGetStateRefIndex(Index, Dcm_DspDidInfo[Counter].Operations, DCM_DIDMGR_OPTYPE_IO);
					if(FALSE != (Dcm_DspDidOpInfo[Index].CallTypes & (1 << pMsgContext->resData[3])))
					{
						StateRef = Dcm_DspDidOpInfo[Index].State_Ref;
						NegRes = Dcm_DspCheckSessionSecurity(StateRef,DSP_DIAG_CHK_LVL_PARAMETER);
						if(DCM_E_OK == NegRes)
						{
							Index = Dcm_DspDidOpInfo[Index].SignalInfo_Ref;
							NegRes = DCM_E_CONDITIONSNOTCORRECT;
							if(FALSE != (Dcm_DspDidSignalInfo[Index].FunClass & DCM_DIDMGR_OPCLS_WRITE_SYNC))
							{
								NegRes = DCM_E_OK;
								pMsgContext->resData = &pMsgContext->resData[3];
								RetVal = DidOpFunc[Dcm_DspDidSignalInfo[Index].DidOpFunc_Ref](DCM_DSP_DID_IO,Did,pMsgContext->resData,&pMsgContext->resDataLen);
							}
						}
					}
				}
			}
			break;
		}
	}
	if(NegRes != DCM_E_OK)
	{
		Dcm_ExternalSetNegResponse(NegRes);
		Dcm_ExternalProcessingDone();

	}
	return(RetVal);
}

/**************************************************************************
Function name       : Std_ReturnType Dcm_31ServiceProcess(Dcm_MsgContextType *pMsgContext)
Description         : RoutineControl Service
Parameters (in)     : Dcm_MsgContextType *pMsgContext
Parameters (out)    : none
Return value        : Std_ReturnType
Design Information  :
**************************************************************************/

Std_ReturnType Dcm_31ServiceProcess(Dcm_MsgContextType *pMsgContext)
{
	Dcm_NegativeResponseCodeType  NegRes;
	Std_ReturnType RetVal;
	uint16  Rid;
	uint8   Counter;
	uint8   Length;
	uint8   Index;
	uint8   StateRef;
	uint8   SubFunction;

	RetVal = DCM_E_OK;


	NegRes = DCM_E_SERVICENOTSUPPORTED;
	SubFunction = pMsgContext->reqData[0];
	Rid = ((uint16)((((uint16)pMsgContext->reqData[1] << 8)) | (uint16)(pMsgContext->reqData[2])));
	Length  = (uint8)Dcm_DspRidIdentifierTable[0];

	for(Counter=0; Counter < Length ; Counter++)
	{
		NegRes = DCM_E_REQUESTOUTOFRANGE;
		if(Dcm_DspRidIdentifierTable[Counter+1] == Rid)
		{
			NegRes = DCM_E_SUBFUNCTIONNOTSUPPORTED;
			if((SubFunction > 0) && (SubFunction <= S31_MAX_SUPPORTED_SUB_FUNCTION))
			{
				if(0 != (Dcm_DspRidInfo[Counter].Operation & (1 << (SubFunction-1))))
				{
					NegRes = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
					Index = Dcm_S31_Opindex_check(Dcm_DspRidInfo[Counter].Operation,SubFunction);
					Index = Dcm_DspRidInfo[Counter].SignalInfo_Ref + Index;

					if((Dcm_DspRidSignalInfo[Index].Req_Length + 3) == pMsgContext->reqDataLen)
					{
						StateRef = Dcm_DspRidInfo[Counter].State_Ref;
						NegRes = Dcm_DspCheckSessionSecurity(StateRef,DSP_DIAG_CHK_LVL_PARAMETER);
						if(DCM_E_OK == NegRes)
						{
							NegRes = DCM_E_OK;
							pMsgContext->resData = &pMsgContext->resData[4];
							Index = Dcm_DspRidSignalInfo[Index].RidOpFunc_Ref;
							RetVal = RidOpFunc[Index](SubFunction,Rid,pMsgContext->resData,&pMsgContext->resDataLen);
						}
					}
				}
			}
			break;
		}
	}

	if(NegRes != DCM_E_OK)
	{
		Dcm_ExternalSetNegResponse(NegRes);
		Dcm_ExternalProcessingDone();

	}
	return(RetVal);
}

/**************************************************************************
Function name       : Std_ReturnType Dcm_3EServiceProcess(Dcm_MsgContextType *pMsgContext)
Description         : Tester Present Service
Parameters (in)     : Dcm_MsgContextType *pMsgContext
Parameters (out)    : none
Return value        : Std_ReturnType
Design Information  :
**************************************************************************/
Std_ReturnType Dcm_3EServiceProcess(Dcm_MsgContextType *pMsgContext)
{
	Dcm_NegativeResponseCodeType  NegRes;

	NegRes = DCM_E_SUBFUNCTIONNOTSUPPORTED;
	if(pMsgContext->reqData[0] == 0)
	{
		NegRes = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
		if(pMsgContext->reqDataLen == 1)
		{
			NegRes = DCM_E_OK;
			pMsgContext->resData =  &pMsgContext->resData[2];
			pMsgContext->resDataLen = 0;
		}
	}

	if(NegRes != DCM_E_OK)
	{
		Dcm_ExternalSetNegResponse(NegRes);
		Dcm_ExternalProcessingDone();
	}
	else
	{
		Dcm_ExternalProcessingDone();
	}
	return DCM_E_OK;
}
/**************************************************************************
Function name       : Std_ReturnType Dcm_27ServiceProcess(Dcm_MsgContextType *pMsgContext)
Description         : SecurityAccess Service
Parameters (in)     : Dcm_MsgContextType *pMsgContext
Parameters (out)    : none
Return value        : Std_ReturnType
Design Information  :
**************************************************************************/
Std_ReturnType Dcm_27ServiceProcess(Dcm_MsgContextType *pMsgContext)
{
	Dcm_NegativeResponseCodeType  NegRes;
	uint8   SubFunction;
	uint8   Counter;
	uint8   StateRef;
	Std_ReturnType RetVal;


	NegRes = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
	RetVal = DCM_E_OK;

	SubFunction = pMsgContext->reqData[0];

	//No_of_security_level
	for(Counter = 0;Counter < No_of_security_level; Counter++)
	{
		NegRes = DCM_E_SUBFUNCTIONNOTSUPPORTED;
		if(Dcm_DsdSubService27[Counter].SubServiceId == SubFunction)
		{
			NegRes = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
			if(Dcm_DsdSubService27[Counter].Req_Length == pMsgContext->reqDataLen)
			{

				StateRef = Dcm_DsdSubService27[Counter].State_Ref;
				NegRes = Dcm_DspCheckSessionSecurity(StateRef,DSP_DIAG_CHK_LVL_SUBFUNC);
				if(DCM_E_OK == NegRes)
				{
					switch(SubFunction%2)
					{
					/* send key*/
					case 0:
						NegRes = Dcm_27Service_key_Process(pMsgContext,Counter);
						RetVal = DCM_E_OK;
						break;
					/* request seed*/
					case 1:
						NegRes = Dcm_27Service_seed_Process(pMsgContext,Counter);
						break;
					default:
						/* This is not reachable */
						break;
					}
				}
			}
			break;
		}
	}


	if(NegRes == DCM_E_OK)
	{
		Dcm_ExternalProcessingDone();
	}
	else
	{
		Dcm_ExternalSetNegResponse(NegRes);
		Dcm_ExternalProcessingDone();
	}

	return RetVal;
}
/**************************************************************************
Function name       : Std_ReturnType Dcm_28ServiceProcess(Dcm_MsgContextType *pMsgContext)
Description         : Communication Control Service
Parameters (in)     : Dcm_MsgContextType *pMsgContext
Parameters (out)    : none
Return value        : Std_ReturnType
Design Information  :
**************************************************************************/
Std_ReturnType Dcm_28ServiceProcess(Dcm_MsgContextType *pMsgContext)
{
	Dcm_NegativeResponseCodeType  NegRes;
	uint8   Comm_Action;
	Std_ReturnType RetVal;
	uint8 Sub_Function;
	uint8 MessageType;

	NegRes = DCM_E_SUBFUNCTIONNOTSUPPORTED;
	RetVal = DCM_E_OK;
	Sub_Function = pMsgContext->reqData[0] & 0x03;
	MessageType = pMsgContext->reqData[1] & 0x03;

	if((Sub_Function == 0) || (Sub_Function == 3))
	{
		NegRes = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
		if(pMsgContext->reqDataLen == 2)
		{
			NegRes = DCM_E_OK;
			pMsgContext->resData =  &pMsgContext->resData[2];

			//Add Actions
			//Comm_Action = (((pMsgContext->reqData[1] & 0x03) << 2) | ((pMsgContext->reqData[0] & 0x03))) - 4;
			Comm_Action = (Sub_Function << 4) & MessageType;
			pMsgContext->resDataLen = 0;

			/*lxiong2 add this for exit 03 session, DCM should enable RX and TX NORM NM*/
			if(((Sub_Function << 2 |  MessageType) - 4) == 0x08)
			{
				DCM_ENABLE_RX_TX_NORM_NM_flag = TRUE;
			}


			RetVal = Communication_action(Comm_Action);
			if(RetVal == DCM_E_OK)
			{
				Communication_Status = Comm_Action;
			}
		}
	}

	if(NegRes != DCM_E_OK)
	{
		Dcm_ExternalSetNegResponse(NegRes);
		Dcm_ExternalProcessingDone();
	}
	return(RetVal);
}
/**************************************************************************
Function name       : Std_ReturnType Dcm_19ServiceProcess(Dcm_MsgContextType *pMsgContext)
Description         : ReadDTCInformation Service
Parameters (in)     : Dcm_MsgContextType *pMsgContext
Parameters (out)    : none
Return value        : Std_ReturnType
Design Information  :
**************************************************************************/
Std_ReturnType Dcm_19ServiceProcess(Dcm_MsgContextType *pMsgContext)
{
	Std_ReturnType RetVal;
	Dcm_NegativeResponseCodeType  NegRes;
	uint8 Counter;
	uint8   StateRef;

	RetVal = DCM_E_OK;
	NegRes = DCM_E_SUBFUNCTIONNOTSUPPORTED;

	for(Counter = 0; Counter < Svc19NumOfsubFunc; Counter++)
	{
		if(pMsgContext->reqData[0] == Dcm_DsdSubService19[Counter].SubServiceId)
		{
			if(pMsgContext->reqDataLen == Dcm_DsdSubService19[Counter].Length)
			{
				NegRes = DCM_E_REQUESTOUTOFRANGE;
				StateRef = Dcm_DsdSubService19[Counter].State_Ref;
				NegRes = Dcm_DspCheckSessionSecurity(StateRef,DSP_DIAG_CHK_LVL_SUBFUNC);
				if(DCM_E_OK == NegRes)
				{
					pMsgContext->resData = &pMsgContext->resData[2];
					RetVal = Dcm_DsdSubService19[Counter].SubServiceFnc(pMsgContext);
					NegRes = DCM_E_OK;
				}
			}
			else
			{
				NegRes = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
			}
			break;
		}
	}

	if(NegRes != DCM_E_OK)
	{
		Dcm_ExternalSetNegResponse(NegRes);
		Dcm_ExternalProcessingDone();
	}


	return(RetVal);
}
/**************************************************************************
Function name       : Std_ReturnType Dcm_14ServiceProcess(Dcm_MsgContextType *pMsgContext)
Description         : Clear DiagnosticInformation Service
Parameters (in)     : Dcm_MsgContextType *pMsgContext
Parameters (out)    : none
Return value        : Std_ReturnType
Design Information  :
**************************************************************************/
Std_ReturnType Dcm_14ServiceProcess(Dcm_MsgContextType *pMsgContext)
{
	Std_ReturnType RetVal;
	Dcm_NegativeResponseCodeType  NegRes;
	RetVal = DCM_E_OK;
	NegRes = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;

	if(pMsgContext->reqDataLen == 3)
	{
		Group_DTC =	((uint32)((((uint32)pMsgContext->reqData[0] << 16)) | ((uint32)pMsgContext->reqData[1] << 8) | (uint32)(pMsgContext->reqData[2])));

		RetVal = Dem_DcmClearDTC(Group_DTC,DEM_DTC_FORMAT_UDS,DEM_DTC_ORIGIN_PRIMARY_MEMORY);
		switch(RetVal)
		{
		case DCM_DEM_RET_CLEAR_OK:
			pMsgContext->resData =  &pMsgContext->resData[1];
			pMsgContext->resDataLen = 0;
			NegRes = DCM_E_OK;
			RetVal = DCM_E_OK;
			Dcm_ExternalProcessingDone();
			break;
		case DCM_DEM_RET_CLEAR_PENDING:
			pMsgContext->resData =  &pMsgContext->resData[1];
			pMsgContext->resDataLen = 0;
			Dsp_14SvcRpHandleFlag = TRUE;
			NegRes = DCM_E_OK;
			RetVal = DCM_E_RESPONSE_PENDING; /* try again later */
			break;
		case DCM_DEM_RET_CLEAR_W_DTC:
			NegRes = DCM_E_REQUESTOUTOFRANGE;
			RetVal = DCM_E_NOT_OK;
			break;
		case DCM_DEM_RET_CLEAR_FAILED:
			NegRes = DCM_E_CONDITIONSNOTCORRECT;
			RetVal = DCM_E_NOT_OK;
			break;
#if defined(DCM_DEM_RET_CLEAR_BUSY)
		case DCM_DEM_RET_CLEAR_BUSY:
			NegRes = DCM_E_CONDITIONSNOTCORRECT;
			RetVal = DCM_E_NOT_OK;
			break;
#endif
#if defined (DCM_DEM_RET_CLEAR_MEMORY_ERROR)
		case DCM_DEM_RET_CLEAR_MEMORY_ERROR:
			NegRes = DCM_E_GENERALPROGRAMMINGFAILURE;
			RetVal = DCM_E_NOT_OK;
			break;
#endif
		default:
			NegRes = DCM_E_REQUESTOUTOFRANGE;
			RetVal = DCM_E_NOT_OK;
			break;
		}
	}
	if(NegRes != DCM_E_OK)
	{
		Dcm_ExternalSetNegResponse(NegRes);
		Dcm_ExternalProcessingDone();
	}
	return(RetVal);
}
/**************************************************************************
Function name       : Std_ReturnType Dcm_85ServiceProcess(Dcm_MsgContextType *pMsgContext)
Description         : ControlDTCSetting service
Parameters (in)     : Dcm_MsgContextType *pMsgContext
Parameters (out)    : none
Return value        : Std_ReturnType
Design Information  :
**************************************************************************/
Std_ReturnType Dcm_85ServiceProcess(Dcm_MsgContextType *pMsgContext)
{
	Std_ReturnType RetVal;
	Dcm_NegativeResponseCodeType  NegRes;
	uint32 DTC_group = 0;
	uint8 DTC_kind = 0;
	uint8 Counter;
	uint8   StateRef;

	RetVal = DCM_E_OK;
	NegRes = DCM_E_SUBFUNCTIONNOTSUPPORTED;

	for(Counter = 0; Counter < Svc85NumOfsubFunc; Counter++)
	{
		if(pMsgContext->reqData[0] == Dcm_DsdSubService85[Counter].SubServiceId)
		{
			#if (DCM_SVC_85_DTC_GRP_ENABLED != FALSE)
			if(pMsgContext->reqDataLen == 4)
			#else
				if(pMsgContext->reqDataLen == 1)
			#endif
				{
					NegRes = DCM_E_REQUESTOUTOFRANGE;
					StateRef = Dcm_DsdSubService85[Counter].State_Ref;
					NegRes = Dcm_DspCheckSessionSecurity(StateRef,DSP_DIAG_CHK_LVL_SUBFUNC);
					if(DCM_E_OK == NegRes)
					{
						#if (DCM_SVC_85_DTC_GRP_ENABLED != FALSE)
						DTC_group = ((uint32)(((uint32)(pMsgContext->reqData[1] << 16)) | (uint32)(pMsgContext->reqData[2] << 8) | (uint32)(pMsgContext->reqData[3])));
						#else
						DTC_group = DEM_DTC_GROUP_ALL_DTCS;
						#endif
						DTC_kind = DEM_DTC_KIND_ALL_DTCS;
						RetVal = Dcm_DsdSubService85[Counter].SubServiceFnc(DTC_group,DTC_kind);
						switch(RetVal)
						{
						case DEM_CONTROL_DTC_SETTING_OK:
							/* success */
							pMsgContext->resData = &pMsgContext->resData[2];
							pMsgContext->reqDataLen = 0;
							NegRes = DCM_E_OK;
							RetVal = DCM_E_OK;
							Dcm_ExternalProcessingDone();
							break;
						case DEM_CONTROL_DTC_SETTING_N_OK:
							NegRes = DCM_E_CONDITIONSNOTCORRECT;
							RetVal = DCM_E_NOT_OK;
							break;
# if (DCM_SVC_85_DTC_GRP_ENABLED != FALSE)
						case DEM_CONTROL_DTC_WRONG_DTCGROUP:
							NegRes = DCM_E_REQUESTOUTOFRANGE;
							RetVal = DCM_E_NOT_OK;
							break;
# endif
						default:
							NegRes = DCM_E_PANIC_NRC;
							RetVal = DCM_E_NOT_OK;
							break;
						}
					}
				}
				else
				{
					NegRes = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
				}
			break;
		}
	}

	if(NegRes != DCM_E_OK)
	{
		Dcm_ExternalSetNegResponse(NegRes);
		Dcm_ExternalProcessingDone();
	}

	return(RetVal);
}

/**************************************************************************
Function name   : void Dsp_DslConfirmation
Arguments       : PduIdType DcmRxPduId, Std_ReturnType result
Return type     : void
Description     : Dcm Confirmation.
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

void Dsp_DslConfirmation(PduIdType DcmRxPduId, Std_ReturnType result)
{
	/*QAC fix*/
	DCM_IGNORE_UNREF_PARAM(DcmRxPduId);
	DCM_IGNORE_UNREF_PARAM(result);

	if (FALSE != (Dsp_PostProcessingFlag & DSP_PerformHardReset))
	{
		Dsp_PostProcessingFlag &= ~DSP_PerformHardReset;
		Dcm_WdgM_PerformHardReset();
	}

	if (FALSE != (Dsp_PostProcessingFlag & DSP_PerformSoftReset))
	{
		Dsp_PostProcessingFlag &= ~DSP_PerformSoftReset;
		Dcm_WdgM_PerformReset();
	}

	if (FALSE != (Dsp_PostProcessingFlag & DSP_Fbl_EntryReset))
	{
		Dsp_PostProcessingFlag &= ~DSP_Fbl_EntryReset;
		Dcm_WdgM_PerformReset();
	}
}

static Dcm_NegativeResponseCodeType Dcm_DspCheckSessionSecurity(uint8 StateRef,Dcm_DspDiagCheckLvlType LevelRef)
{
	Dcm_NegativeResponseCodeType  NegRes;
	Dcm_SesCtrlType fl_Session;
	Dcm_SecLevelType fl_Security;

	NegRes = DCM_E_REQUESTOUTOFRANGE;
	(void)Dcm_GetSesCtrlType(&fl_Session);
	if(((Dcm_DsdStateRef[StateRef].Session) & (0x01 << (fl_Session-1))) != FALSE)
	{
		NegRes = DCM_E_SECURITYACCESSDENIED;
		(void)Dcm_GetSecurityLevel(&fl_Security);
		if(((Dcm_DsdStateRef[StateRef].Security) & (0x01 << (fl_Security))) != FALSE)
		{
			NegRes = DCM_E_OK;
		}
	}
	else
	{
		NegRes = Dcm_StateSessionNrcs[LevelRef];
	}
	return NegRes;
}

static uint8 Dcm_DspGetStateRefIndex(uint8 Index, uint8 Operations, uint8 ConditionRef)
{
	while(0 != ConditionRef)
	{
		if(FALSE != (Operations & 0x01))
		{
			Index = Index + 1;
		}
		Operations = Operations >> 1;
		ConditionRef = ConditionRef >> 1;
	}
	/* Qiuhuaqing Modify, */
	if(Index > 0)
	{
		Index = Index - 1;
	}
	return Index;
}

static uint8 Dcm_S31_Opindex_check(uint8 operation ,uint8 subfunction)
{
	uint8 fl_return;

	fl_return = 0;
	switch(operation)
	{
	case 1:
	case 3:
	case 7:
		fl_return = subfunction - 1;
		break;
	case 2:
	case 4:
		fl_return = 0;
		break;
	case 6:
		fl_return = subfunction - 2;
		break;
	case 5:
		if(subfunction ==1)
		{
			fl_return = 0;
		}
		else if(subfunction ==3)
		{
			fl_return = 1;
		}
		else
		{
			/*wrong place to come*/
		}
		break;
	default:
		break;
	}
	return fl_return;
}


void Dcm_SessionChangeAction(uint8 SubFunction)
{
	uint8 counter;
	DCM_DSP_BROADCAST_SESSION_STATUS(SubFunction);
	Old_Session = SubFunction;
	for(counter = 0;counter < NO_OF_SUPPORTTED_SESSIONS; counter++)
	{
		if(Dcm_SessionCommEnable[counter].Subfunction == SubFunction)
		{
			if(Dcm_SessionCommEnable[counter].Comm_support != FALSE)
			{
			}
			else if(Communication_Status != DCM_ENABLE_RX_TX_NORM)
			{
				(void)Communication_action(DCM_ENABLE_RX_TX_NORM_NM);
				Communication_Status = DCM_ENABLE_RX_TX_NORM;
			}
			else
			{
			/*Do nothing*/
			}
		}
		if(SubFunction == 0x04)
		{
			l_smrs_status_u8 = TRUE;
		}

		if(l_smrs_status_u8 == TRUE)
		{
			//do nothing
		}
		else
		{
			if(SubFunction == 0x01)
			{
				(void)Dem_DcmEnableDTCSetting(DEM_DTC_GROUP_ALL_DTCS,DEM_DTC_KIND_ALL_DTCS);
			}
		}
	}
}
/**************************************************************************
Function name       : Std_ReturnType Dcm_DspService19_01Processor(Dcm_MsgContextType *pMsgContext)
Description         : Service 19 subfunction 1.
Parameters (in)     : Dcm_MsgContextType *pMsgContext
Parameters (out)    : none
Return value        : Std_ReturnType
Design Information  :
**************************************************************************/
Std_ReturnType Dcm_DspService19_01Processor(Dcm_MsgContextType *pMsgContext)
{
	Std_ReturnType ret_val;
	ret_val = DCM_E_OK;

	ret_val = Dcm_DspSvc19UtiReportNumDtcByStatusMaskData(DEM_SETFILTER_CLASS_01,pMsgContext->reqData[1],0,pMsgContext);

	return ret_val;
}
/**************************************************************************
Function name       : Std_ReturnType Dcm_DspService19_02Processor(Dcm_MsgContextType *pMsgContext)
Description         : Service 19 subfunction 2.
Parameters (in)     : Dcm_MsgContextType *pMsgContext
Parameters (out)    : none
Return value        : Std_ReturnType
Design Information  :
**************************************************************************/
Std_ReturnType Dcm_DspService19_02Processor(Dcm_MsgContextType *pMsgContext)
{
	Std_ReturnType ret_val;
	ret_val = DCM_E_OK;

	ret_val = Dcm_DspSvc19UtiReportDtcByStatusMaskData(DEM_SETFILTER_CLASS_01,DCM_SVC_19_USE_MASK_REQ,pMsgContext);

	return ret_val;
}
/**************************************************************************
Function name       : Std_ReturnType Dcm_DspService19_06Processor(Dcm_MsgContextType *pMsgContext)
Description         : Service 19 subfunction 6.
Parameters (in)     : Dcm_MsgContextType *pMsgContext
Parameters (out)    : none
Return value        : Std_ReturnType
Design Information  :
**************************************************************************/
Std_ReturnType Dcm_DspService19_04Processor(Dcm_MsgContextType *pMsgContext)
{
	Std_ReturnType ret_val;
	ret_val = DCM_E_OK;
	uint32 fl_dtc_id_u32 = 0;
	uint8 fl_dtc_snap_record_u8 = 0;
	Dcm_NegativeResponseCodeType  NegRes = DCM_E_OK;

	fl_dtc_id_u32 = ((uint32)(pMsgContext->reqData[1] << 16) | (pMsgContext->reqData[2] << 8) | (pMsgContext->reqData[3]));
	fl_dtc_snap_record_u8 = pMsgContext->reqData[4];

	if(fl_dtc_snap_record_u8 == 0x01 || fl_dtc_snap_record_u8 == 0xff)
	{
		ret_val = Dcm_DspSvc19UtiReportDtcSnapshotData(fl_dtc_id_u32,pMsgContext);
	}
	else
	{
		NegRes = DCM_E_SUBFUNCTIONNOTSUPPORTED;
		ret_val = DCM_E_NOT_OK;
	}

	if(NegRes != DCM_E_OK)
	{
		Dcm_ExternalSetNegResponse(NegRes);
		Dcm_ExternalProcessingDone();
	}


	return ret_val;
}

/**************************************************************************
Function name       : Std_ReturnType Dcm_DspService19_06Processor(Dcm_MsgContextType *pMsgContext)
Description         : Service 19 subfunction 6.
Parameters (in)     : Dcm_MsgContextType *pMsgContext
Parameters (out)    : none
Return value        : Std_ReturnType
Design Information  :
**************************************************************************/
Std_ReturnType Dcm_DspService19_06Processor(Dcm_MsgContextType *pMsgContext)
{
	Std_ReturnType ret_val;
	ret_val = DCM_E_OK;
	/*QAC fix*/
	pMsgContext->reqData[0] = 0;
	return ret_val;
}
/**************************************************************************
Function name       : Std_ReturnType Dcm_DspService19_0AProcessor(Dcm_MsgContextType *pMsgContext)
Description         : Service 19 subfunction 0x0A.
Parameters (in)     : Dcm_MsgContextType *pMsgContext
Parameters (out)    : none
Return value        : Std_ReturnType
Design Information  :
**************************************************************************/
Std_ReturnType Dcm_DspService19_0AProcessor(Dcm_MsgContextType *pMsgContext)
{
	Std_ReturnType ret_val;
	ret_val = DCM_E_OK;

	ret_val = Dcm_DspSvc19UtiReportDtcByStatusMaskData(DEM_SETFILTER_CLASS_01,DCM_SVC_19_USE_MASK_ALL,pMsgContext);


	return ret_val;
}
/**************************************************************************
Function name       : Std_ReturnType Dcm_DspSvc19UtiReportNumDtcByStatusMaskData(uint8 dsfClass,uint8 dtcStatusMask,uint8 dtcSeverity,Dcm_MsgContextType *pMsgContext)
Description         : Report number of DTC by status mask.
Parameters (in)     : uint8 dsfClass,uint8 dtcStatusMask,uint8 dtcSeverity,Dcm_MsgContextType *pMsgContext.
Parameters (out)    : none
Return value        : Std_ReturnType
Design Information  :
**************************************************************************/
static Std_ReturnType Dcm_DspSvc19UtiReportNumDtcByStatusMaskData(uint8 dsfClass,uint8 dtcStatusMask,uint8 dtcSeverity,Dcm_MsgContextType *pMsgContext)
{
	Std_ReturnType ret_val;
	Dem_ReturnSetFilterType  demResultSetFilter;
	Dcm_NegativeResponseCodeType  NegRes;

	ret_val = Dem_DcmGetDTCStatusAvailabilityMask(pMsgContext->resData);  /* Copy the status availability mask (in any case) */
	if(ret_val == E_OK)
	{
		dtcStatusMask &= pMsgContext->resData[0];
		if(dtcStatusMask != 0)
		{
			demResultSetFilter = Dem_DcmSetDTCFilter(dtcStatusMask
				,Dcm_Svc19DemDtcFilterInfo[dsfClass].Kind
				,DEM_DTC_FORMAT_UDS
				,Dcm_Svc19DemDtcFilterInfo[dsfClass].Origin
				,Dcm_Svc19DemDtcFilterInfo[dsfClass].ConsiderSeverity
				,dtcSeverity
				,DEM_FILTER_FOR_FDC_NO);
			if(demResultSetFilter == DEM_FILTER_ACCEPTED)
			{
				ret_val = Dcm_DspSvc19UtiDemGetNumFltrdDtc(pMsgContext);
				if(ret_val == DCM_E_OK)
				{
					pMsgContext->resData[1] = Dem_DcmGetTranslationType();
					pMsgContext->resData[2] = (uint8)(No_Of_Matching_DTC >> 8);
					pMsgContext->resData[3] = (uint8)(No_Of_Matching_DTC);
					pMsgContext->resDataLen = 4u;

					Dcm_ExternalProcessingDone();
				}
				NegRes = DCM_E_OK;
			}
			else
			{
				NegRes = DCM_E_REQUESTOUTOFRANGE;
				ret_val = DCM_E_NOT_OK;
			}
		}
		else
		{
			pMsgContext->resData[1] = Dem_DcmGetTranslationType();
		    pMsgContext->resData[2] = 0u;
			pMsgContext->resData[3] = 0u;
			pMsgContext->resDataLen = 4u;

			Dcm_ExternalProcessingDone();
			NegRes = DCM_E_OK;
			ret_val = DCM_E_OK;
		}
	}
	else
	{
		NegRes = DCM_E_REQUESTOUTOFRANGE;
		ret_val = DCM_E_NOT_OK;
	}

	if(NegRes != DCM_E_OK)
	{
		Dcm_ExternalSetNegResponse(NegRes);
		Dcm_ExternalProcessingDone();
	}

	return ret_val;
}
/**************************************************************************
Function name       : Std_ReturnType Dcm_DspSvc19UtiReportDtcSnapshotData(uint8 dsfClass,uint8 dtcStatusMask,uint8 dtcSeverity,Dcm_MsgContextType *pMsgContext)
Description         : Report number of DTC by status mask.
Parameters (in)     : uint32 dtcid,Dcm_MsgContextType *pMsgContext
Parameters (out)    : none
Return value        : Std_ReturnType
Design Information  :
**************************************************************************/
static Std_ReturnType Dcm_DspSvc19UtiReportDtcSnapshotData(uint32 dtcid,Dcm_MsgContextType *pMsgContext)
{
	Std_ReturnType ret_val = DCM_E_OK;
	Dcm_NegativeResponseCodeType  NegRes = DCM_E_OK;
	uint8 fl_dtc_number_u8 = 0;
	uint8 fl_dtc_snopshat_def_u8 = 0;

	fl_dtc_snopshat_def_u8 = (uint8)pMsgContext->reqData[4];

	ret_val = Dem_DcmGetNumberOfDtcID(dtcid,&fl_dtc_number_u8);

	if(ret_val == DCM_E_OK)
	{
		pMsgContext->resData = &pMsgContext->resData[0];
		pMsgContext->resDataLen = 33u;

		Dem_DcmGetSnapshotDataOfDtcID(fl_dtc_number_u8,fl_dtc_snopshat_def_u8,pMsgContext->resData);
		Dcm_ExternalProcessingDone();
	}
	else
	{
		NegRes = DCM_E_REQUESTOUTOFRANGE;
		ret_val = DCM_E_NOT_OK;
	}

	if(NegRes != DCM_E_OK)
	{
		Dcm_ExternalSetNegResponse(NegRes);
		Dcm_ExternalProcessingDone();
	}


	return ret_val;
}

/**************************************************************************
Function name       : Std_ReturnType Dcm_DspSvc19UtiDemGetNumFltrdDtc(Dcm_MsgContextType *pMsgContext)
Description         : Get the number of filtered DTC.
Parameters (in)     : Dcm_MsgContextType *pMsgContext.
Parameters (out)    : none
Return value        : Std_ReturnType
Design Information  :
**************************************************************************/
/******************************MISRA Warning Begin***********************************
** CID : 3112
** MISRA Title : Redundancy
** MISRA: There shall be no dead code (MISRA C-2012 Rule 2.2)
** MISRA Message :
** This statement has no side-effect - it can be removed.
** DCM_IGNORE_UNREF_PARAM(pMsgContext);
** Rational:
** This warning is reviewed and team decided to approve since this implementation
** is design intended and it will not impact the functionalities.
** Approved Status: Yes
** Approved Date : 05-05-2017
** Approved By : DI COC Team
******************************MISRA Warning End************************************/
static Std_ReturnType Dcm_DspSvc19UtiDemGetNumFltrdDtc(Dcm_MsgContextType *pMsgContext)                                            /* PRQA S 3673 */ /* MD_Dcm_Design_3673 */
{
	Std_ReturnType ret_val;
	uint8 demResult;

	DCM_IGNORE_UNREF_PARAM(pMsgContext);

	demResult = Dem_DcmGetNumberOfFilteredDTC(&No_Of_Matching_DTC);
	switch(demResult)
	{
	case DEM_NUMBER_OK:
		ret_val = DCM_E_OK;
		break;
	case DEM_NUMBER_PENDING:
		ret_val = DCM_E_RESPONSE_PENDING;
		break;
	default:
		Dcm_ExternalSetNegResponse(DCM_E_REQUESTOUTOFRANGE);
		Dcm_ExternalProcessingDone();
		ret_val = DCM_E_NOT_OK;
		break;
	}
	return ret_val;
}
/**************************************************************************
Function name       : static Std_ReturnType Dcm_DspSvc19UtiReportDtcByStatusMaskData(uint8 dsfClass,Dcm_Svc19DemSetFilterMaskUsageType maskUsage,Dcm_MsgContextType *pMsgContext)
Description         : Report number of DTC by status mask.
Parameters (in)     : uint8 dsfClass,Dcm_Svc19DemSetFilterMaskUsageType maskUsage,Dcm_MsgContextType *pMsgContext.
Parameters (out)    : none
Return value        : Std_ReturnType
Design Information  :
**************************************************************************/
static Std_ReturnType Dcm_DspSvc19UtiReportDtcByStatusMaskData(uint8 dsfClass,Dcm_Svc19DemSetFilterMaskUsageType maskUsage,Dcm_MsgContextType *pMsgContext)
{
	Std_ReturnType ret_val;
	uint8 dtcStatusMask;
	Dcm_NegativeResponseCodeType  NegRes;
	Dem_ReturnSetFilterType  demResultSetFilter;

	ret_val = DCM_E_OK;

	dtcStatusMask = pMsgContext->resData[0];/* save the requested mask */
	ret_val = Dem_DcmGetDTCStatusAvailabilityMask(pMsgContext->resData);  /* Copy the status availability mask (in any case) */
	if(ret_val == E_OK)
	{
		dtcStatusMask &= pMsgContext->resData[0];      /* Form the relevant status bits */
		if((maskUsage == DCM_SVC_19_USE_MASK_REQ) && (dtcStatusMask == 0u))
		{
			NegRes = DCM_E_OK;
			ret_val = DCM_E_OK;/* no DTCs to report */
			pMsgContext->resDataLen = 1u;
			Dcm_ExternalProcessingDone();
		}
		else
		{
			if(maskUsage != DCM_SVC_19_USE_MASK_REQ)
			{
				dtcStatusMask = 0u; /* all DTCs to be filtered */
			}

			demResultSetFilter = Dem_DcmSetDTCFilter(dtcStatusMask
													   ,Dcm_Svc19DemDtcFilterInfo[dsfClass].Kind
													   ,DEM_DTC_FORMAT_UDS
													   ,Dcm_Svc19DemDtcFilterInfo[dsfClass].Origin
													   ,DEM_FILTER_WITH_SEVERITY_NO
													   ,0 /* parameter not used */
 													   ,DEM_FILTER_FOR_FDC_NO);
			if(demResultSetFilter == DEM_FILTER_ACCEPTED)
			{
				pMsgContext->resData = &pMsgContext->resData[1];
				ret_val = Dcm_DspSvc19UtiDemGetNumFltrdDtc(pMsgContext);
				if(ret_val == DCM_E_OK)
				{
					ret_val = Dcm_DspSvc19UtiDemGetNxtFltrdDtc(pMsgContext);
				}
				NegRes = DCM_E_OK;
				Dcm_ExternalProcessingDone();
			}/* else - error case - send NRC */
			else
			{
				NegRes = DCM_E_REQUESTOUTOFRANGE;
				ret_val = DCM_E_NOT_OK;
			}
		}
	}
	else
	{
		NegRes = DCM_E_REQUESTOUTOFRANGE;
		ret_val = DCM_E_NOT_OK;
	}
	if(NegRes != DCM_E_OK)
	{
		Dcm_ExternalSetNegResponse(NegRes);
		Dcm_ExternalProcessingDone();
	}

	return ret_val;
}

/**************************************************************************
Function name       : static Std_ReturnType Dcm_DspSvc19UtiDemGetNxtFltrdDtc(Dcm_MsgContextType *pMsgContext)
Description         : Copy the filtered data.
Parameters (in)     : Dcm_MsgContextType *pMsgContext.
Parameters (out)    : none
Return value        : Std_ReturnType
Design Information  :
**************************************************************************/
static Std_ReturnType Dcm_DspSvc19UtiDemGetNxtFltrdDtc(Dcm_MsgContextType *pMsgContext)
{
	Std_ReturnType ret_val;

	ret_val = DCM_E_OK;

    ret_val = Dcm_DspSvc19UtiCpyLinearData(pMsgContext);
	return ret_val;
}
/**************************************************************************
Function name       : static Std_ReturnType Dcm_DspSvc19UtiCpyLinearData(Dcm_MsgContextType *pMsgContext)
Description         : Copy the linear data.
Parameters (in)     : Dcm_MsgContextType *pMsgContext.
Parameters (out)    : none
Return value        : Std_ReturnType
Design Information  :
**************************************************************************/
static Std_ReturnType Dcm_DspSvc19UtiCpyLinearData(Dcm_MsgContextType *pMsgContext)
{
  Std_ReturnType lStdResult;
  Dcm_MsgLenType remainingData = (Dcm_MsgLenType)pMsgContext->resMaxDataLen;

  lStdResult = Dcm_DspSvc19UtiCpyDemGetNxtFltrdDtc(pMsgContext->resData,&remainingData);

  /* commit copied data */
  remainingData = (Dcm_MsgLenType)(pMsgContext->resMaxDataLen - remainingData);

  pMsgContext->resDataLen = remainingData;                                                                              /* PRQA S 3109 */ /* MD_MSR_14.3 */
  lStdResult = DCM_E_OK;
/*  if(lStdResult != DCM_E_PENDING)
  {
    if(lStdResult == DCM_E_BUFFERTOOLOW)
    {
      Dcm_SetNegResponse(DCM_E_RESPONSETOOLONG);
    }
    lStdResult = DCM_E_PROCESSINGDONE;
  }*/
  return lStdResult;
}
/**************************************************************************
Function name       : static Std_ReturnType Dcm_DspSvc19UtiCpyDemGetNxtFltrdDtc(Dcm_MsgType pData,Dcm_MsgLenType* pAvailLen)
Description         : get next filtered data.
Parameters (in)     : Dcm_MsgType pData,Dcm_MsgLenType* pAvailLen.
Parameters (out)    : none
Return value        : Std_ReturnType
Design Information  :
**************************************************************************/
static Std_ReturnType Dcm_DspSvc19UtiCpyDemGetNxtFltrdDtc(Dcm_MsgType pData,Dcm_MsgLenType* pAvailLen)
{
  uint32                                lDtc;
  uint16           lAvailLen;
  uint8                                 dtcStatus;
  uint16  demResult;
  Std_ReturnType                        lStdResult;

  lAvailLen = *pAvailLen;
  lStdResult = DCM_E_BUFFERTOOLOW;

  while (lAvailLen >= 4u)
  {

    demResult =  Dem_DcmGetNextFilteredDTC(&lDtc, &dtcStatus);
    if(demResult == DCM_DEM_RET_FILTERED_OK)
    {
      pData[0] = (uint8)(lDtc >> 16);
      pData[1] = (uint8)(lDtc >> 8);
      pData[2] = (uint8)(lDtc);
      pData[3] = dtcStatus;
      /* commit data */
	  pData = &(pData)[4];
      lAvailLen -= 4u;
    }
    else
    {
//      lStdResult = Dcm_DemApiConvDemRsltGetNextFilteredItem(demResult);
      break;
    }
  }

  *pAvailLen = (uint16)lAvailLen; /* commit all copied data */
  return lStdResult; /*lint !e438 pData is always post incremented */
}                                                                                                                                                    /* PRQA S 6080 */ /* MD_MSR_STMIF */
#if(DCM_DEM_LOG_DTC_EXT != FALSE)
Std_ReturnType Dcm_30ServiceProcess(Dcm_MsgContextType *pMsgContext)
{
	Dcm_NegativeResponseCodeType  NegRes;
	Std_ReturnType RetVal;

	RetVal = DCM_E_OK;

	NegRes = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
	if(pMsgContext->reqDataLen == 6)
	{
		dem_event_byte_one = pMsgContext->resData[1];
		dem_event_byte_two = pMsgContext->resData[2];
		dem_event_byte_three = pMsgContext->resData[3];
		dem_event_byte_four = pMsgContext->resData[4];
		dem_event_byte_five = pMsgContext->resData[5];

		dem_event_send_flag = pMsgContext->resData[6];

		NegRes = DCM_E_OK;
		pMsgContext->resData =  &pMsgContext->resData[7];
		pMsgContext->resDataLen = 0;
		Dcm_ExternalProcessingDone();
	}

	if(NegRes != DCM_E_OK)
	{
		Dcm_ExternalSetNegResponse(NegRes);
		Dcm_ExternalProcessingDone();
	}
	return(RetVal);
}
#endif
void Dcm_DspClear14Pending(void)
{
	Dsp_14SvcRpHandleFlag = FALSE;
}
static Dcm_NegativeResponseCodeType Dcm_27Service_key_Process(Dcm_MsgContextType *pMsgContext,uint8 Counter)
{
	Dcm_NegativeResponseCodeType  NegRes;
	Std_ReturnType RetVal;

	if(Request_seed_rcvd == FALSE)
	{
		NegRes = DCM_E_REQUESTSEQUENCEERROR;
	}
	else
	{
		pMsgContext->resData = &pMsgContext->resData[2];
		RetVal = Dcm_DsdSubService27[Counter].SubServiceFnc(pMsgContext->resData,&pMsgContext->resDataLen);
		if(RetVal == DCM_E_OK)
		{
			NegRes = DCM_E_OK;
			DslInternal_SetSecurityLevel((Counter+1)/2);

			#ifdef S27_DELAY_SUPPORTED
			/* Qiuhuaqing Modify,  no longer depence on Timer MOdule */
			Dcm_27Timer_Stop(TIMER_RESET | TIMER_FAILCOUNTER);
			#endif
		}
		else
		{
			NegRes = DCM_E_INVALIDKEY;
			#ifdef S27_DELAY_SUPPORTED
			S27_fail_counter += 1;
			if(S27_fail_counter >= S27_FAIL_COUNT)
			{
				NegRes = DCM_E_EXCEEDNUMBEROFATTEMPTS;

				/* Qiuhuaqing Modify,  no longer depence on Timer MOdule */
				Dcm_27Timer_Start(TIMER_FAILCOUNTER);
				/* start counter for exceededNumberOfAttempts */
			}
			else
			{
			}
			#endif
		}
	}
	Request_seed_rcvd = FALSE;
	return(NegRes);
}
static Dcm_NegativeResponseCodeType Dcm_27Service_seed_Process(Dcm_MsgContextType *pMsgContext,uint8 Counter)
{
	Dcm_NegativeResponseCodeType  NegRes;
	Dcm_SecLevelType fl_Security;
	Boolean Dcm_Timer_Elapsed_Status = FALSE;
	uint8 indexBuffer;

	(void)Dcm_GetSecurityLevel(&fl_Security);

	if(fl_Security == ((Counter/2)+1))
	{
		NegRes = DCM_E_OK;
		pMsgContext->resData = &pMsgContext->resData[2];
		pMsgContext->resData[0] = 0;
		pMsgContext->resData[1] = 0;
		pMsgContext->resData[2] = 0;
		pMsgContext->resData[3] = 0;
		pMsgContext->resDataLen = 4u;
	}
	else
	{
		NegRes =  DCM_E_OK;

	#ifdef S27_DELAY_SUPPORTED
		if(((FALSE != S27_reset_delay)) || ((S27_fail_counter >= S27_FAIL_COUNT)))
		{
			if(FALSE != S27_reset_delay)
			{
				/* Qiuhuaqing Modify,  no longer depence on Timer MOdule */
				Dcm_27Timer_IsTimeout(TIMER_RESET,&Dcm_Timer_Elapsed_Status);
			}
			else if(S27_fail_counter >= S27_FAIL_COUNT)
			{
				/* Qiuhuaqing Modify,  no longer depence on Timer MOdule */
				Dcm_27Timer_IsTimeout(TIMER_FAILCOUNTER, &Dcm_Timer_Elapsed_Status);
			}
			else
			{
				/*Do nothing*/
			}

			if(Dcm_Timer_Elapsed_Status == FALSE)
			{
				NegRes = DCM_E_REQUIREDTIMEDELAYNOTEXPIRED;
			}
			else
			{
				if(FALSE != S27_reset_delay)
				{
					S27_reset_delay = FALSE;
				}
				else if (S27_fail_counter >= S27_FAIL_COUNT)
				{
					S27_fail_counter -= 1;
				}
				else
				{
					/*Do Nothing*/
				}

				/* Qiuhuaqing Modify,  no longer depence on Timer MOdule */
				Dcm_27Timer_Stop(TIMER_RESET | TIMER_FAILCOUNTER);
			}
		}
		if(NegRes == DCM_E_OK)
	#endif
		{
			if(Request_seed_rcvd == FALSE)
			{
				Request_seed_rcvd = TRUE;
				pMsgContext->resData = &pMsgContext->resData[2];
				(void)Dcm_DsdSubService27[Counter].SubServiceFnc(pMsgContext->resData,&pMsgContext->resDataLen);
				for(indexBuffer = 0; indexBuffer < 4; indexBuffer++)
				{
					S27_SeedBuffer[indexBuffer] = pMsgContext->resData[indexBuffer];
				}
			}
			else
			{
				pMsgContext->resData = &pMsgContext->resData[2];
				pMsgContext->resDataLen = 4;

				S27_fail_counter += 1;
				if(S27_fail_counter >= S27_FAIL_COUNT)
				{
					NegRes = DCM_E_EXCEEDNUMBEROFATTEMPTS;
					pMsgContext->resDataLen = 0;
					Request_seed_rcvd = FALSE;

					/* Qiuhuaqing Modify,  no longer depence on Timer MOdule */
					Dcm_27Timer_Start(TIMER_FAILCOUNTER);
					/* start counter for exceededNumberOfAttempts */
				}
				else
				{
				}
				for(indexBuffer = 0; indexBuffer < 4; indexBuffer++)
				{
					pMsgContext->resData[indexBuffer] = S27_SeedBuffer[indexBuffer];
				}
			}
		}
	}
	return(NegRes);
}

/**************************************************************************
Function name   : void Dcm_27Timer_Start
Arguments       : void
Return type     : void
Description     : This function is used to handle the Diag.27sevice timer
**************************************************************************/
static void Dcm_27Timer_Init(void)
{
	S27Timer.ResetCounter = TIMER_VALUE_RESET;
	S27Timer.FailCounter = TIMER_VALUE_FAILCOUNTER;
	S27Timer.IsStarted  = 0;
	S27Timer.TimeOut = 0;
}

/**************************************************************************
Function name   : void Dcm_27Timer_Start
Arguments       : void
Return type     : void
Description     : This function is used to handle the Diag.27sevice timer
**************************************************************************/
static void Dcm_27Timer_Start(uint8 TimerId)
{
	if(FALSE != (TimerId & TIMER_RESET))
	{
		S27Timer.ResetCounter = TIMER_VALUE_RESET;
		S27Timer.IsStarted |= TIMER_RESET;
		S27Timer.TimeOut &= (~TIMER_RESET);
	}
	if(FALSE != (TimerId & TIMER_FAILCOUNTER))
	{
		S27Timer.FailCounter = TIMER_VALUE_FAILCOUNTER;
		S27Timer.IsStarted |= TIMER_FAILCOUNTER;
		S27Timer.TimeOut &= (~TIMER_FAILCOUNTER);
	}
}

/**************************************************************************
Function name   : void Dcm_27Timer_Stop
Arguments       : void
Return type     : void
Description     : This function is used to handle the Diag.27sevice timer
**************************************************************************/
static void Dcm_27Timer_Stop(uint8 TimerId)
{
	if(TIMER_RESET == TimerId)
	{
		S27Timer.IsStarted &= (~TIMER_RESET);
	}
	if(TIMER_FAILCOUNTER == TimerId)
	{
		S27Timer.IsStarted &= (~TIMER_FAILCOUNTER);
	}
}

/**************************************************************************
Function name   : void Dcm_27Timer_Process
Arguments       : void
Return type     : void
Description     : This function is used to handle the Diag.27sevice timer
**************************************************************************/
static void Dcm_27Timer_Process(void)
{
	if(0 != (S27Timer.IsStarted & TIMER_RESET))
	{
		if(0 == (S27Timer.TimeOut & TIMER_RESET))
		{
			if(0 != S27Timer.ResetCounter)
			{
				--S27Timer.ResetCounter;
			}
			else
			{
				S27Timer.TimeOut |= TIMER_RESET;
			}
		}
	}
	else
	{
		/* do nothing */
	}

	if(0 != (S27Timer.IsStarted & TIMER_FAILCOUNTER))
	{
		if(0 == (S27Timer.TimeOut & TIMER_FAILCOUNTER))
		{
			if(0 != S27Timer.FailCounter)
			{
				--S27Timer.FailCounter;
			}
			else
			{
				S27Timer.TimeOut |= TIMER_FAILCOUNTER;
			}
		}
	}
}

static void Dcm_27Timer_IsTimeout(uint8 TimerId, boolean* Timeout)
{
	boolean result = FALSE;

	if(TimerId <= TIMER_FAILCOUNTER)
	{
		if(0 != (S27Timer.TimeOut & TimerId))
		{
			result = TRUE;
		}
		else
		{
			/* do nothing */
		}
	}
	else
	{
		/* do nothing */
	}
	*Timeout = result;
}

#endif /* DCM_DSP_C*/
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
/*Date              : 17-Jun-2016                                           */
/*Version           :                                                       */
/*By                : msavariy                                              */
/*Traceability      :                                                       */
/*Change Description: Data design And Framework implemented, Initial Version*/
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
/*Traceability      : RTC 746031,RTC 746018                                 */
/*Change Description: service 28 and 27 timing implementation			    */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 16-Dec-2016                                           */
/*Version           :                                                       */
/*By                : msavariy                                              */
/*Traceability      :                                                       */
/*Change Description: Session & Security state checking logic changes for   */
/*			  DID which supporting multiple operations. (Read | Write | IO) */
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
/*Date              : 13-March-2017                                         */
/*Version           :                                                       */
/*By                : akalarim                                              */
/*Traceability      : Rtc# 822374                                           */
/*Change Description: Coverity issue fixes                                  */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 21-March-2017                                         */
/*Version           :                                                       */
/*By                : akalarim                                              */
/*Traceability      : Rtc# 830120                                           */
/*Change Description: Control DTC setting is enabled on transition to       */
/*					  default session.   	                                */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 22-March-2017                                         */
/*Version           :                                                       */
/*By                : akalarim                                              */
/*Traceability      : Rtc# 828126                                           */
/*Change Description: Service 27 request positive response at reset is 	    */
/*						changed from 10 second to 8 second                  */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 3-April-2017                                          */
/*Version           :                                                       */
/*By                : akalarim                                              */
/*Traceability      : RTC 838240                                            */
/*Change Description: Fixed the compiler warnings.                          */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 5-April-2017                                          */
/*Version           :                                                       */
/*By                : akalarim                                              */
/*Traceability      : RTC 833391                                            */
/*Change Description: NRC priority issue on multiple NRC is fixed           */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 7-April-2017                                          */
/*Version           :                                                       */
/*By                : akalarim                                              */
/*Traceability      : RTC 842239                                            */
/*Change Description: Pr review comment fixed                               */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 18-April-2017                                         */
/*Version           :                                                       */
/*By                : akalarim                                              */
/*Traceability      : RTC 841275                                            */
/*Change Description: NRC updated for session not supportted in subfunction */
/*                    and DID or RID level.                                 */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 20-April-2017                                         */
/*Version           :                                                       */
/*By                : akalarim                                              */
/*Traceability      : RTC 847171                                            */
/*Change Description: Test code update for DTC addition                     */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 13-May-2017                                           */
/*Version           :                                                       */
/*By                : akalarim                                              */
/*Traceability      : Rtc#                                                  */
/*Change Description: QAC warning fixes                                     */
/*--------------------------------------------------------------------------*/
