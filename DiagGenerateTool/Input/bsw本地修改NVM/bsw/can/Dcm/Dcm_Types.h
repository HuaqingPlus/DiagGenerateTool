
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
*  File Name         :  Dcm_Types.h                                          *
*  Module Short Name :  DiagMgr                                              *
*  VOBName           :                                                       *
*  Author            : msavariy                                              *
*  Description       :  This file contains declations of the Autosar ECU     *
*                       State Manager types and macros                       *
*                                                                            *                                                                           *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS                                                    *
* Target Hardware  :                                                         *
*                                                                            *
******************************************************************************/

#ifndef DCM_TYPES_H
#define DCM_TYPES_H

#include "Std_Types.h"
#include "ComStack_Types.h"
#include "Rte_Dcm_Type.h"
#include "Dcm_Cfg.h" /* Qiuhuaqing modify */
#include "Dcm_Cfg_Generate.h"

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

# define DCM_IGNORE_UNREF_PARAM(param)                  ((void)(param))

/* Added this macro for compilation purose, as it is referenced on PduR_Lcfg.c*/
# define DcmConf_DcmDslProtocolTx_PT_TxDiag_PP_TxDiag_Tx_346f2748_ad5ca5d7      0u

/*
* Dcm_StatusType
*/

#define DCM_E_OK  			(Std_ReturnType)E_OK
#define DCM_E_NOT_OK		(Std_ReturnType)E_NOT_OK
#define DCM_E_BUFFERTOOLOW  ((Std_ReturnType)42)

#define DCM_E_CANCEL		0x13
#define DCM_E_RESPONSE_PENDING	0x10
#define DCM_E_FORCE_RCRRP		0x12

#define DCM_E_PROCESSING_DONE	0x40

#define DCM_E_ROE_NOT_ACCEPTED  0x06
#define DCM_E_PERIODICID_NOT_ACCEPTED  0x07

#define DCM_E_PANIC_NRC   DCM_E_GENERALREJECT


#define DCM_DEM_RET_CLEAR_OK               0
#define DCM_DEM_RET_CLEAR_W_DTC            1
#define DCM_DEM_RET_CLEAR_W_ORIGIN         2
#define DCM_DEM_RET_CLEAR_FAILED           3
#define DCM_DEM_RET_CLEAR_PENDING          4
#define DCM_DEM_RET_CLEAR_BUSY			   5
#define DCM_DEM_RET_CLEAR_MEMORY_ERROR     6

#   define DCM_DEM_RET_FILTERED_OK                                   DEM_FILTERED_OK
#   define DCM_DEM_RET_FILTERED_NO_ITEMS                             DEM_FILTERED_NO_MATCHING_DTC
#   define DCM_DEM_RET_FILTERED_PENDING                              DEM_FILTERED_PENDING


/*
*  Dcm_CommunicationModeType
*/
#  ifndef DCM_ENABLE_RX_TX_NORM
#   define DCM_ENABLE_RX_TX_NORM (0U)
#  endif

#  ifndef DCM_ENABLE_RX_DISABLE_TX_NORM
#   define DCM_ENABLE_RX_DISABLE_TX_NORM (1U)
#  endif

#  ifndef DCM_DISABLE_RX_ENABLE_TX_NORM
#   define DCM_DISABLE_RX_ENABLE_TX_NORM (2U)
#  endif

#  ifndef DCM_DISABLE_RX_TX_NORMAL
#   define DCM_DISABLE_RX_TX_NORMAL (3U)
#  endif

#  ifndef DCM_ENABLE_RX_TX_NM
#   define DCM_ENABLE_RX_TX_NM (4U)
#  endif

#  ifndef DCM_ENABLE_RX_DISABLE_TX_NM
#   define DCM_ENABLE_RX_DISABLE_TX_NM (5U)
#  endif

#  ifndef DCM_DISABLE_RX_ENABLE_TX_NM
#   define DCM_DISABLE_RX_ENABLE_TX_NM (6U)
#  endif

#  ifndef DCM_DISABLE_RX_TX_NM
#   define DCM_DISABLE_RX_TX_NM (7U)
#  endif

#  ifndef DCM_ENABLE_RX_TX_NORM_NM
#   define DCM_ENABLE_RX_TX_NORM_NM (8U)
#  endif

#  ifndef DCM_ENABLE_RX_DISABLE_TX_NORM_NM
#   define DCM_ENABLE_RX_DISABLE_TX_NORM_NM (9U)
#  endif

#  ifndef DCM_DISABLE_RX_ENABLE_TX_NORM_NM
#   define DCM_DISABLE_RX_ENABLE_TX_NORM_NM (10U)
#  endif

#  ifndef DCM_DISABLE_RX_TX_NORM_NM
#   define DCM_DISABLE_RX_TX_NORM_NM (11U)
#  endif


/*
* Dcm_ReturnReadMemoryType
*/

#define DCM_READ_OK   0x00
#define DCM_READ_PENDING   0x01
#define DCM_READ_FAILED   0x02
#define DCM_READ_FORCE_RCRRP   0x03

/*
* Dcm_ReturnWriteMemoryType
*/

#define DCM_WRITE_OK   0x00
#define DCM_WRITE_PENDING   0x01
#define DCM_WRITE_FAILED   0x02
#define DCM_WRITE_FORCE_RCRRP   0x03

/*
* Dcm_EcuStartModeType
*/

#define DCM_COLD_START 0x0
#define DCM_WARM_START 0x1

/*
* Dcm_DidSupportedType
*/

#define DCM_DID_SUPPORTED 0x00
#define DCM_DID_NOT_SUPPORTED 0x01


/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

typedef uint8 Dcm_StatusType;
/* Already Declared in Rte_Type.h - moses */
/*typedef uint8 Dcm_CommunicationModeType;*/
typedef uint8 Dcm_ReturnReadMemoryType;
typedef uint8 Dcm_ReturnWriteMemoryType;
typedef uint8 Dcm_EcuStartModeType;
typedef uint32  Dcm_MsgLenType;
typedef uint8 Dcm_MsgItemType;
typedef Dcm_MsgItemType* Dcm_MsgType;
typedef uint8 Dcm_IdContextType;
typedef uint8 Dcm_DidSupportedType;

typedef uint8  Dcm_BitType;

typedef struct
{
  Dcm_BitType reqType  :1; /* 0: physical 1: functional */
  Dcm_BitType suppressPosResponse  :1; /* 0: do not suppress positive response, 1: do suppress positive response  */
}Dcm_MsgAddInfoType;



typedef struct
{
  Dcm_MsgLenType     reqDataLen;
  Dcm_MsgLenType     resDataLen;
  Dcm_MsgLenType     resMaxDataLen;
  Dcm_MsgType        reqData;
  Dcm_MsgType        resData;
  Dcm_MsgAddInfoType msgAddInfo;
  Dcm_IdContextType  idContext;
  PduIdType          rxPduId;
}Dcm_MsgContextType;


/*! Programming condition information */
struct DCM_PROGCONDITIONSTYPE_TAG
{
  uint16  TesterSourceAddr;     /*!< The client ID (source address). Note: AR 4.0.3 specifics the client ID to be a U8 for this API, but the connection configuration has a 16 Bit value! */
  uint8   ProtocolId;           /*!< The protocol ID */
  uint8   Sid;                  /*!< The request SID to be responded to */
  uint8   SubFuncId;            /*!< The sub-function ID to be responded to */
  boolean ReprogrammingRequest; /*!< Specifies whether an ECU preprogramming is needed (TRUE - ECU reprogramming, FALSE - no ECU reprogramming) */
  boolean ApplUpdated;          /*!< Specifies whether the application has been updated (TRUE - application updated, FALSE - no application updated) */
  boolean ResponseRequired;     /*!< Specifies whether a response to the SID and sub-function has to be sent (TRUE) or just the requested diagnostic session shall be entered (FALSE) */
};
typedef struct DCM_PROGCONDITIONSTYPE_TAG Dcm_ProgConditionsType;
typedef P2VAR(Dcm_ProgConditionsType, TYPEDEF, DCM_VAR_NOINIT) Dcm_ProgConditionsPtrType;


typedef struct
{
  boolean ResponseRequired;
  uint8 SubFncId;
}Dcm_ResetConditionsType;

/* test */
typedef uint8 Dcm_ConfigType;
/* Qiuhuaqing Modify to adapt D53.Diagnosis */
typedef P2CONST(Dcm_ConfigType, TYPEDEF, DCM_CONST_PBCFG) Dcm_ConfigPtrType;

typedef boolean (*DcmDidConditionProcessFnc) (void);

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
/********************************************************************************/
/*  This macro is used to log the DTC from the CAN  */
#define DCM_DEM_LOG_DTC_EXT  FALSE

/********************************************************************************/
#define DCM_DSP_SVC10_HARD_RESET         DCM_EXT_HARD_RESET
#define DCM_DSP_DIAG_ENTRY_CONDITION     DSP_APP_DIAG_ENTRY_CONDITION
#define DCM_DSP_PROG_ENTRY_CONDITION     DSP_APP_PROG_ENTRY_CONDITION

#define DCM_DSP_S11_TRIGGER_CONDITION    DSP_APP_S11_TRIGGER_CONDITION
#define DCM_DSP_BROADCAST_SESSION_STATUS  BroadCastSessionStatus

#define DI_DID_DIAG_ACTION      DI_Did_Diag_Action

#define DCM_EXT_HARD_RESET

/* Application has to populate the entry condition check
 *  For Diag and Programming entry check  */
#define DSP_APP_EOL_ENTRY_CONDITION		TRUE
#define DSP_APP_DIAG_ENTRY_CONDITION 	DSP_APP_Diag_Entry_Condition()
#define DSP_APP_PROG_ENTRY_CONDITION 	DSP_APP_Prog_Entry_Condition()
#define DSP_APP_S11_TRIGGER_CONDITION	TRUE

#define DcmDslAddBufferSize    (uint8)3
#if(DCM_DEM_LOG_DTC_EXT != FALSE)
#define DcmNumOfSIDSupported   (uint8)13
#define NoOfDTCevents          (uint8)33
#else
#define DcmNumOfSIDSupported   (uint8)12
#endif

#define DI_RID_DIAG_ACTION		DI_Rid_Diag_Action

#define DCM_S3_SERVER_TIME		1000u	/* 1000 * 5msTask = 5s */

#define No_of_security_level        2
#define NO_OF_SUPPORTTED_SESSIONS 	4

/*Define the macro S27_DELAY_SUPPORTED if delay need to be added for security failure */
#define S27_DELAY_SUPPORTED   TRUE

#ifdef  S27_DELAY_SUPPORTED
/*Value of 30000 makes 30 Seconds on Turing B*/
#define S27_PGMDELAY_TIME_MS    10000
#define S27_RSTDELAY_TIME_MS    8000
#define S27_FAIL_COUNT  3
#define Dcm_Timer_Start        TmExt_Timer_Start
#define Dcm_Timer_Stop	       TmExt_Timer_Stop
#define Dcm_Timer_IsElapsed    TmExt_Timer_IsElapsed
#endif

#define DcmDsdNumOfStateRef			17
#define DcmDspNumOfDidSignalInfo	1
#define DidNumOfOpFunc				1
#define RidNumOfOpFunc				1
#define Svc85NumOfsubFunc			 2
//#define DCM_SVC_85_DTC_GRP_ENABLED FALSE

#define Svc19NumOfsubFunc			 4
#if !defined(DCM_FUNC_ADDR_SUPPRESS_NRC)
#define DCM_FUNC_ADDR_SUPPRESS_NRC		FALSE
#endif


/*Session Types */
#define DEFAULT_SESSION     0x01
#define PROGRAMMING_SESSION 0xFF  /* don't use */
#define EXTENDED_SESSION    0x03
#define EOL_SESSION			    0x60

#define DCM_SECURITY_LOCKED		(0U)
#define DCM_SECURITY_LEVEL1		(1U)
#define DCM_SECURITY_LEVEL2		(2U)

typedef struct
{
  Std_ReturnType (*DcmDsdSidTabFnc) (Dcm_MsgContextType *pMsgContext);
  uint8 Props;        /*bit0 : has subfunction; bit1 : support function addr*/
  uint8 Length;
  uint8 State_Ref;
}Dcm_DsdSidTabServiceInfoType;


typedef struct
{
  uint8 Session;
  uint8 Security;
}Dcm_DsdStateRefType;


typedef struct
{
  Std_ReturnType (*SubServiceFnc) (Dcm_MsgContextType *Buff);
  uint8 SubServiceId;
  uint8 Length;
  uint8 State_Ref;
}Dcm_DsdSubService19Type;

typedef struct
{
  Std_ReturnType (*SubServiceFnc) (void);
  uint8 State_Ref;
  uint8 SubServiceId;
}Dcm_DsdSubService10Type;


typedef struct
{
  Std_ReturnType (*SubServiceFnc) (Dcm_MsgType Buff,Dcm_MsgLenType* Length);
  uint8 SubServiceId;
  uint8 Req_Length;
  uint8 Resp_Length;
  uint8 State_Ref;
}Dcm_DsdSubService27Type;


typedef struct
{
  Std_ReturnType (*SubServiceFnc) (uint32 DTC_group,uint8 DTC_kind);
  uint8 SubServiceId;
  uint8 State_Ref;
}Dcm_DsdSubService85Type;

typedef struct
{
  uint16 P2;
  uint16 P2Star;
  uint8 Session_Value;
}Dcm_DsdSessionInfoType;


typedef struct
{
  uint8 Length;
  uint8 OpInfoRef;
  uint8 Operations;
}Dcm_DspDidInfoType;


typedef struct
{
  uint8 State_Ref;
  uint8 SignalInfo_Ref;
  uint8 CallTypes;
}Dcm_DspDidOpInfoType;


typedef struct
{
  uint8 DidOpFunc_Ref;
  uint8 FunClass;
}Dcm_DspDidSignalInfoType;

typedef struct
{
  uint8 SignalInfo_Ref;
  uint8 State_Ref;
  uint8 Operation;
}Dcm_DspRidInfoType;


typedef struct
{
  uint8 RidOpFunc_Ref;
  uint8 Req_Length;
  uint8 Resp_Length;
  uint8 OpType;
}Dcm_DspRidSignalInfoType;

typedef struct
{
  uint8 RxPduID;
  uint8 TxPduID;
}Dcm_UDSProtocolType;

typedef struct
{
  uint8       ReqLength; /* for seed: SF + ADR_size, for key: SF + key_size*/
  uint8       ResLength; /* for seed: SF + seed_size, for key: SF */
}Dcm_DspSecurityInfoType;
typedef struct
{
  uint8       Subfunction; /* for seed: SF + ADR_size, for key: SF + key_size*/
  uint8       Comm_support; /* for seed: SF + seed_size, for key: SF */
}Dcm_SessionCommEnableInfo;

//typedef Boolean (*DcmDidConditionProcessFnc) (void);


/*****************************************************************************
*                                Globally  accessed Variable Declarations    *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/

typedef uint8 Dcm_DsdSidTabServiceIdType;
typedef uint16 Dcm_DspDidIdentifierTableType;
typedef uint16 Dcm_DspRidIdentifierTableType;
typedef uint8 Dcm_DspSvc27SubFuncTableType;
typedef Std_ReturnType (*DidOpFuncType)(uint8 Did_action
	,Dcm_DspDidIdentifierTableType  Did
	,Dcm_MsgType Buff
	,Dcm_MsgLenType* Length);
typedef Std_ReturnType (*RidOpFuncType)(uint8 Rid_action
	,Dcm_DspRidIdentifierTableType  Did
	,Dcm_MsgType Buff
	,Dcm_MsgLenType* Length);
extern const Dcm_DsdSidTabServiceIdType Dcm_DsdSidTabServiceId[DcmNumOfSIDSupported+1];
extern const Dcm_DsdSidTabServiceInfoType Dcm_DsdSidTabServiceInfo[DcmNumOfSIDSupported];
extern const Dcm_DsdStateRefType   Dcm_DsdStateRef[DcmDsdNumOfStateRef];

extern const Dcm_DsdSubService10Type Dcm_DsdSubService10[NO_OF_SUPPORTTED_SESSIONS];

extern const Dcm_DsdSubService19Type Dcm_DsdSubService19[Svc19NumOfsubFunc];
extern const Dcm_DsdSubService27Type Dcm_DsdSubService27[No_of_security_level*2];
extern const Dcm_DsdSubService85Type Dcm_DsdSubService85[Svc85NumOfsubFunc];

extern const Dcm_DsdSessionInfoType Dcm_DsdSessionInfo[NO_OF_SUPPORTTED_SESSIONS];

extern const Dcm_DspDidIdentifierTableType Dcm_DspDidIdentifierTable[DcmNumOfDIDSupported + 1];
extern const Dcm_DspDidInfoType Dcm_DspDidInfo[DcmNumOfDIDSupported];
extern const Dcm_DspDidOpInfoType Dcm_DspDidOpInfo[DcmDspNumOfDidOpInfo];

extern const Dcm_DspDidSignalInfoType Dcm_DspDidSignalInfo[DcmDspNumOfDidSignalInfo];
extern const DidOpFuncType DidOpFunc[DidNumOfOpFunc];

extern const Dcm_DspRidIdentifierTableType Dcm_DspRidIdentifierTable[DcmNumOfRIDSupported+1];
extern const Dcm_DspRidInfoType Dcm_DspRidInfo[DcmNumOfRIDSupported];
extern const Dcm_DspRidSignalInfoType Dcm_DspRidSignalInfo[DcmDspNumOfRidSignalInfo];
extern const RidOpFuncType RidOpFunc[RidNumOfOpFunc];
extern const Dcm_SessionCommEnableInfo Dcm_SessionCommEnable[NO_OF_SUPPORTTED_SESSIONS];

//extern const DcmDidConditionProcessFnc Dcm_DspDidConditionProcess[DcmNumOfDIDSupported];


/* PduR_Lcfg.c uses the below macro for tx pdu id*/
/*  ----- Symbolic name values for Tx PduIds -----  */
# define DcmConf_DcmDslProtocolTx_PT_TxDiag_PP_TxDiag_Tx_346f2748_ad5ca5d7      0u


/*****************************************************************************
*                               Functions                                    *
******************************************************************************/
extern void Dcm_EnterCriticalSection(void);
extern void Dcm_ExitCriticalSection(void);
extern void Dcm_(void);

extern Std_ReturnType DI_Did_Diag_Action(uint8 Did_action
	,Dcm_DspDidIdentifierTableType  Did
	,Dcm_MsgType Buff
	,Dcm_MsgLenType* Length
	);

extern Std_ReturnType DI_Rid_Diag_Action(uint8 Rid_action
	,Dcm_DspRidIdentifierTableType  Rid
	,Dcm_MsgType Buff
	,Dcm_MsgLenType* Length);

extern void Dcm_WdgM_PerformReset(void);
extern void Dcm_WdgM_PerformHardReset(void);

Std_ReturnType Communication_action(uint8 Com_action);
extern void BroadCastSessionStatus(uint8 SubFunction);

extern boolean DSP_APP_Diag_Entry_Condition(void);
extern boolean DSP_APP_Prog_Entry_Condition(void);


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
/*Date              : 16-Jun-2016                                           */
/*Version           :                                                       */
/*By                : msavariy                                              */
/*Traceability      :                                                       */
/*Change Description: Datadesign And Framework implemented, Initial Version */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 3-April-2017                                          */
/*Version           :                                                       */
/*By                : akalarim                                              */
/*Traceability      : RTC 838240                                            */
/*Change Description: Fixed the compiler warnings.                          */
/*--------------------------------------------------------------------------*/

