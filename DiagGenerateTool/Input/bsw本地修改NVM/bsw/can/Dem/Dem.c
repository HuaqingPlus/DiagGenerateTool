/*****************************************************************************
 *                                                                            *
 *              CONFIDENTIAL VISTEON CORPORATION                              *
 *                                                                            *
 * This is an unpublished work of authorship, which contains trade            *
 * secrets, created in 2017. Visteon Corporation owns all rights to           *
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
 *  File Name         :  Dem.c                                                *
 *  Module Short Name :  ErrMgr                                               *
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
#ifndef DEM_C
#define DEM_C

/*****************************************************************************
 *                            Include files                                   *
 ******************************************************************************/
#include "Dem.h"
#include "Dem_Cbk.h"

/*
 #include "Rte_Dem.h"
 #include "Dem_Dcm.h"
 */
#include "NvM.h"  /* qiuhuqign modify */

/* Schedule Manager, for critical sections */
/* Qiuhuaqing MOdify to adapt D53.Diagnosis */
//#include "SchM_Dem.h"

/* Development error tracer, for Det_ReportError */
/* Qiuhuaqing MOdify to adapt D53.Diagnosis */
//# include "Det.h"

#include "Rte_DcmExt.h"
#include "string.h"
#include "Dem_Cfg.h"

//NVM Test, Qiuhuaqing Modify 
//#define DEM_NVM_Test
#ifdef DEM_NVM_Test
static Dem_Cfg_UdsStatusDataType l_Read_UdsStatus;
#endif

/* Qiuhuaqing modify */
/*==================================================================================================
*                                        LOCAL MACROS
==================================================================================================*/
#define DEM_VENDOR_ID_C         43
#define DEM_AR_RELEASE_MAJOR_VERSION  4
#define DEM_AR_RELEASE_MINOR_VERSION  2
#define DEM_AR_RELEASE_REVISION_VERSION  2
#define DEM_SW_MAJOR_VERSION  1
#define DEM_SW_MINOR_VERSION  0
#define DEM_SW_PATCH_VERSION  0

/*****************************************************************************
 *                                 Macro Definitions                          *
 *----------------------------------------------------------------------------*
 * Definition of macro shall be followed by a comment that explains the       *
 * purpose of the macro.                                                      *
 ******************************************************************************/

/*** utilities ***/
#define DEM_SET_CFG_FAILING(Status)            (Status |= BIT0) /*BIT0 dem current failing*/
#define DEM_SET_CFG_TRIGGER_STORE(Status)      (Status |= BIT1) /*BIT1 dem current failing trigger storage*/
#define DEM_SET_CFG_CURRENT_STORAGED(Status)   (Status |= BIT2) /*BIT2 dem current ign storaged*/
#define DEM_SET_CFG_LAST_BAT_STORAGED(Status)  (Status |= BIT3) /*BIT3 dem last battoff storaged*/
#define DEM_SET_CFG_DTC_STORAGED(Status)       (Status |= BIT5) /*BIT5 dem clear storaged*/

#define DEM_GET_CFG_FAILING(Status)            ((Status & BIT0) != FALSE)  /*BIT0 dem current failing*/
#define DEM_GET_CFG_TRIGGER_STORE(Status)      ((Status & BIT1) != FALSE) /*BIT1 dem current failing trigger storage*/
#define DEM_GET_CFG_CURRENT_STORAGED(Status)   ((Status & BIT2) != FALSE)  /*BIT2 dem current ign storaged*/
#define DEM_GET_CFG_LAST_BAT_STORAGED(Status)  ((Status & BIT3) != FALSE)  /*BIT3 dem last battoff storaged*/
#define DEM_GET_CFG_DTC_STORAGED(Status)       ((Status & BIT5) != FALSE)  /*BIT5 dem clear storaged*/


#define DEM_CLR_CFG_FAILING(Status)            (Status &= ~BIT0)  /*BIT0 dem current failing*/
#define DEM_CLR_CFG_TRIGGER_STORE(Status)      (Status &= ~BIT1)  /*BIT1 dem current failing trigger storage*/
#define DEM_CLR_CFG_CURRENT_STORAGED(Status)   (Status &= ~BIT2)  /*BIT2 dem current ign storaged*/
#define DEM_CLR_CFG_LAST_BAT_STORAGED(Status)  (Status &= ~BIT3)  /*BIT3 dem last battoff storaged*/
#define DEM_CLR_CFG_DTC_STORAGED(Status)       (Status &= ~BIT5)  /*BIT5 dem clear storaged*/

#define DEM_CLR_CFG_LOW4BIT(Status)            (Status &= ~(BIT0+BIT1+BIT2+BIT3))  /*BIT5 dem clear storaged*/

#define DEM_TIMESTAMB_INVALID 0xFFFFFFFF

#define DEM_CALCULATE_SIZE(Value)    ((Value + 7) /8)
#define DEM_CALCULATE_INDEX(Value)    (Value / 8)
#define DEM_CALCULATE_MASK_BIT(Value)  (uint8)(0x01 << ((uint8)(Value % 8)))

#define DEM_GET_BIT_STATE(Value, Mask)    ((uint8)(Value & Mask) != FALSE)
#define DEM_SET_BIT_STATE(Value, Mask)    (uint8)(Value |= Mask)
#define DEM_RESET_BIT_STATE(Value, Mask)  (uint8)(Value &= ~(Mask))

#if (DemDevErrorDetect == TRUE)

#define Dem_Det_Error_register(AppID, Error)

#endif

/****  Dem Initialization States  ***/

#define DEM_UNINITIALIZED    0U
#define DEM_PREINITIALIZED    1U
#define DEM_INITIALIZED      2U
#define DEM_SHUTDOWN      3U

/*** DTC  ***/
#define DEM_DTC_STORAGE_SETTING_ENABLED   1U
#define DEM_DTC_STORAGE_SETTING_DISABLED  0U

/*** Enable and Storage Condition ***/

#define DEM_EVENT_ENABLE_CONDITION_FAILED          0U
#define DEM_EVENT_ENABLE_CONDITION_FULFILLED       1U

#define DEM_EVENT_STORAGE_CONDITION_FAILED          0U
#define DEM_EVENT_STORAGE_CONDITION_FULFILLED       1U

#define DEM_EVENT_ENABLE_CONDITION_REQUESTED        0x01U
#define DEM_EVENT_STORAGE_CONDITION_REQUESTED       0x02U

/*** Invalid Status ***/

#define DEM_DTC_INVALID             0x00FFFFFFU
#define DEM_DTC_AGING_INVALID       0xFFFF
#define DEM_EVENT_INVALID           0x00U
#define DEM_EVENT_TMSTMP_INVALID    0xFFFFFFFFU
#define DEM_EVENT_OCCNTR_INVALID    0xFFU
#define DEM_EVENT_STATUS_INVALID    0x04U
#define DEM_DEBOUNCE_STATUS_INVALID 0x02U
#define DEM_CYCLE_STATE_INVALID     0x02U
#define DEM_DTC_FORMAT_INVALID      0x03U
#define DEM_DTC_ORIGIN_INVALID      0x05U
#define DEM_DTC_KIND_INVALID        0x03U
#define DEM_DTC_VALID_START         0x03U

/*** DEM Clear DTC ***/
#define DEM_DCM_CLEAR_DTC_IDLE          0x00U
#define DEM_DCM_CLEAR_DTC_REQUESTED     0x01U
#define DEM_DCM_CLEAR_DTC_REQUEST_COMPLETED     0x02U

#define DEM_DCM_CLEAR_DTC_QUEUE_PENDING     0x01U
#define DEM_DCM_CLEAR_DTC_QUEUE_FAILED      0x02U
#define DEM_DCM_CLEAR_DTC_QUEUE_DONE        0x03U
#define DEM_DCM_CLEAR_DTC_QUEUE_CANCEL      0x04U

/*** Event Internal Status  ***/

#define DEM_EVENT_VALID_ID_START   0x03U

#define DEM_EVENT_STATUS_BIT_POS    0x00
#define DEM_EVENT_STATUS_BIT_SIZE   0x02
#define DEM_EVENT_STATUS_BIT_MASK   0x03

#define DEM_EVENT_STATUS_NONE       0x0U
#define DEM_EVENT_STATUS_TRIGGERED  0x01U
#define DEM_EVENT_STATUS_STORED     0x02U
#define DEM_EVENT_STATUS_AGING      0x03U

#define DEM_EVENT_DEBOUNCE_STATUS_BIT_POS    0x02
#define DEM_EVENT_DEBOUNCE_STATUS_BIT_SIZE   0x03
#define DEM_EVENT_DEBOUNCE_STATUS_BIT_MASK   0x07

#define DEM_EVENT_DEBOUNCE_STATUS_FREEZE        0x00U
#define DEM_EVENT_DEBOUNCE_STATUS_RESET         0x00U

#define DEM_EVENT_DEBOUNCE_STATUS_NONE          0x00U
#define DEM_EVENT_DEBOUNCE_STATUS_PASSED        0x01U
#define DEM_EVENT_DEBOUNCE_STATUS_FAILED        0x02U
#define DEM_EVENT_DEBOUNCE_STATUS_HEALING       0x03U
#define DEM_EVENT_DEBOUNCE_STATUS_FAILING       0x04U
#define DEM_EVENT_DEBOUNCE_STATUS_RESET_HEAL    0x05U
#define DEM_EVENT_DEBOUNCE_STATUS_RESET_FAIL    0x06U
#define DEM_EVENT_DEBOUNCE_STATUS_FREEZE_HEAL   0x07U
#define DEM_EVENT_DEBOUNCE_STATUS_FREEZE_FAIL   0x08U

/*** Operation cycle status ***/
#define DEM_OPCYCLE_STATE_INVALID       0x02U

#define DEM_OPERATION_QUEUE_CYCLE_STOPED       0x01U
#define DEM_OPERATION_QUEUE_CYCLE_STARTED      0x02U
#define DEM_OPERATION_QUEUE_CYCLE_RESTARTED    0x03U

#define DEM_GET_OPERTATION_CYCLE_STATUS(Status, CycleId) ((Status & (1 << CycleId)) != FALSE)
#define DEM_SET_OPERTATION_CYCLE_STATUS(Status, CycleId) (Status |= (1 << CycleId))
#define DEM_RESET_OPERTATION_CYCLE_STATUS(Status, CycleId) (Status &= ~(1 << CycleId))

/***    UDS Status bit update   ***/

/***  TF  ***/

#define DEM_UDS_STATUS_MASK_TF            0x01U
#define DEM_UDS_STATUS_MASK_TFTMC         0x02U
#define DEM_UDS_STATUS_MASK_PDTC          0x04U
#define DEM_UDS_STATUS_MASK_CDTC          0x08U
#define DEM_UDS_STATUS_MASK_TNCSLC        0x10U
#define DEM_UDS_STATUS_MASK_TFSLC         0x20U
#define DEM_UDS_STATUS_MASK_TNCTMC        0x40U
#define DEM_UDS_STATUS_MASK_WIR           0x80U

#define DEM_UDS_STATUS_DEFAULT            0x50U

#define DEM_SET_UDS_STATUS_BYTE_TF(status)      (status |= DEM_UDS_STATUS_MASK_TF)
#define DEM_SET_UDS_STATUS_BYTE_TFTMC(status)   (status |= DEM_UDS_STATUS_MASK_TFTMC)
#define DEM_SET_UDS_STATUS_BYTE_PDTC(status)    (status |= DEM_UDS_STATUS_MASK_PDTC)
#define DEM_SET_UDS_STATUS_BYTE_CDTC(status)    (status |= DEM_UDS_STATUS_MASK_CDTC)
#define DEM_SET_UDS_STATUS_BYTE_TNCSLC(status)  (status |= DEM_UDS_STATUS_MASK_TNCSLC)
#define DEM_SET_UDS_STATUS_BYTE_TFSLC(status)   (status |= DEM_UDS_STATUS_MASK_TFSLC)
#define DEM_SET_UDS_STATUS_BYTE_TNCTMC(status)  (status |= DEM_UDS_STATUS_MASK_TNCTMC)
#define DEM_SET_UDS_STATUS_BYTE_WIR(status)     (status |= DEM_UDS_STATUS_MASK_WIR)

#define DEM_RESET_UDS_STATUS_BYTE_TF(status)      (status &= ~(DEM_UDS_STATUS_MASK_TF))
#define DEM_RESET_UDS_STATUS_BYTE_TFTMC(status)   (status &= ~(DEM_UDS_STATUS_MASK_TFTMC))
#define DEM_RESET_UDS_STATUS_BYTE_PDTC(status)    (status &= ~(DEM_UDS_STATUS_MASK_PDTC))
#define DEM_RESET_UDS_STATUS_BYTE_CDTC(status)    (status &= ~(DEM_UDS_STATUS_MASK_CDTC))
#define DEM_RESET_UDS_STATUS_BYTE_TNCSLC(status)  (status &= ~(DEM_UDS_STATUS_MASK_TNCSLC))
#define DEM_RESET_UDS_STATUS_BYTE_TFSLC(status)   (status &= ~(DEM_UDS_STATUS_MASK_TFSLC))
#define DEM_RESET_UDS_STATUS_BYTE_TNCTMC(status)  (status &= ~(DEM_UDS_STATUS_MASK_TNCTMC))
#define DEM_RESET_UDS_STATUS_BYTE_WIR(status)     (status &= ~(DEM_UDS_STATUS_MASK_WIR))

#define DEM_GET_UDS_STATUS_BYTE_TF(status)      ((status & DEM_UDS_STATUS_MASK_TF) != FALSE)
#define DEM_GET_UDS_STATUS_BYTE_TFTMC(status)   ((status & DEM_UDS_STATUS_MASK_TFTMC) != FALSE)
#define DEM_GET_UDS_STATUS_BYTE_PDTC(status)    ((status & DEM_UDS_STATUS_MASK_PDTC) != FALSE)
#define DEM_GET_UDS_STATUS_BYTE_CDTC(status)    ((status & DEM_UDS_STATUS_MASK_CDTC) != FALSE)
#define DEM_GET_UDS_STATUS_BYTE_TNCSLC(status)  ((status & DEM_UDS_STATUS_MASK_TNCSL)) != FALSE)
#define DEM_GET_UDS_STATUS_BYTE_TFSLC(status)   ((status & DEM_UDS_STATUS_MASK_TFSLC) != FALSE)
#define DEM_GET_UDS_STATUS_BYTE_TNCTMC(status)  ((status & DEM_UDS_STATUS_MASK_TNCTMC) != FALSE)
#define DEM_GET_UDS_STATUS_BYTE_WIR(status)     ((status & DEM_UDS_STATUS_MASK_WIR) != FALSE)

/***  DEM Event Queue Status  ***/
#define DEM_EVENT_QUEUE_PENDING         0x80U
#define DEM_EVENT_QUEUE_PASSED          0x01U
#define DEM_EVENT_QUEUE_FAILED          0x02U

#define DEM_EVENT_GET_QUEUE_STATUS_PENDING(Status)  ((Status & DEM_EVENT_QUEUE_PENDING) != FALSE)
#define DEM_EVENT_SET_QUEUE_STATUS_PENDING(Status)  (Status |= DEM_EVENT_QUEUE_PENDING)
#define DEM_EVENT_RESET_QUEUE_STATUS_PENDING(Status)  (Status &= ~(DEM_EVENT_QUEUE_PENDING))

#define DEM_EVENT_GET_QUEUE_STATUS_FAILED(Status)  ((Status & DEM_EVENT_QUEUE_FAILED) != FALSE)
#define DEM_EVENT_SET_QUEUE_STATUS_FAILED(Status)  (Status |= DEM_EVENT_QUEUE_FAILED)
#define DEM_EVENT_RESET_QUEUE_STATUS_FAILED(Status)  (Status &= ~(DEM_EVENT_QUEUE_FAILED))

#define DEM_EVENT_GET_QUEUE_STATUS_PASSED(Status)  ((Status & DEM_EVENT_QUEUE_PASSED) != FALSE)
#define DEM_EVENT_SET_QUEUE_STATUS_PASSED(Status)  (Status |= DEM_EVENT_QUEUE_PASSED)
#define DEM_EVENT_RESET_QUEUE_STATUS_PASSED(Status)  (Status &= ~(DEM_EVENT_QUEUE_PASSED))

/*** NVM Status ***/

#define DEM_NVM_IDLE            0x00U
#define DEM_NVM_WRITING         0x01U
#define DEM_NVM_FINISHED        0x02U
#define DEM_NVM_FAILED          0x03U

/* Mem Status */
#define DEM_MEM_IDLE            0x00U
#define DEM_MEM_DIRTY           0x01U

/***  Dem Internal Mem Status  ***/
#define DEM_MEM_STATUS_NONE                      0x00U
#define DEM_MEM_STATUS_TRIGGER_STORAGE           0x01U
#define DEM_MEM_STATUS_TRIGGER_CLEAR             0x02U
#define DEM_MEM_STATUS_STORE_RETRY               0x03U
#define DEM_MEM_STATUS_CLEAR_RETRY               0x04U

/*** Dem Dcm interface ***/
#define DEM_DCM_FILTER_USESTATUSMASK            0x01U
#define DEM_DCM_FILTER_USESEVERITY              0x02U
#define DEM_DCM_FILTER_USESFDC                  0x04U

#define DEM_DCM_GET_USESTATUSMASK_FLAG(filter)  ((filter & DEM_DCM_FILTER_USESTATUSMASK) != FALSE)
#define DEM_DCM_SET_USESTATUSMASK_FLAG(filter)  (filter |= DEM_DCM_FILTER_USESTATUSMASK)
#define DEM_DCM_RESET_USESTATUSMASK_FLAG(filter)  (filter &= ~(DEM_DCM_FILTER_USESTATUSMASK))

#define DEM_DCM_GET_USESEVERITY_FLAG(filter)  ((filter & DEM_DCM_FILTER_USESEVERITY) != FALSE)
#define DEM_DCM_SET_USESEVERITY_FLAG(filter)  (filter |= DEM_DCM_FILTER_USESEVERITY)
#define DEM_DCM_RESET_USESEVERITY_FLAG(filter)  (filter &= ~(DEM_DCM_FILTER_USESEVERITY))

#define DEM_DCM_GET_USESFDC_FLAG(filter)  ((filter & DEM_DCM_FILTER_USESFDC) != FALSE)
#define DEM_DCM_SET_USESFDC_FLAG(filter)  (filter |= DEM_DCM_FILTER_USESFDC)
#define DEM_DCM_RESET_USESFDC_FLAG(filter)  (filter &= ~(DEM_DCM_FILTER_USESFDC))


#define Rte_Read_Speed(Status, Value) (*Status = RTE_E_NEVER_RECEIVED, *Value = 0)
#define Rte_Read_EngSpd(Status, Value) (*Status = RTE_E_NEVER_RECEIVED, *Value = 0)
#define Rte_Read_Voltage(Value) (*Value = 0)
#define Rte_Read_ODO(Value) (*Value = 0)

/*****************************************************************************
 *                                 Type Declarations                          *
 ******************************************************************************/
typedef struct
{
  uint32 TimeStampCounter;
  uint8 InitState;
  boolean DtcSettingEnCondition;
  boolean DtcSettingEnConditionQueue;
  boolean DtcSettingConditionRequestedFlag;
} Dem_InternalType;

typedef struct
{
  sint16 DebounceValue[Dem_Cfg_Num_Of_Event];
  uint8 InternalStatus[Dem_Cfg_Num_Of_Event];
  uint8 InternalMemStatus[Dem_Cfg_Mem_Total_Entry];
  uint8 QueueStatus[Dem_Cfg_Num_Of_Event];
  uint8 AvailableStatus[DEM_CALCULATE_SIZE(Dem_Cfg_Num_Of_Event)];
  uint8 EnableCondition[Dem_Cfg_Num_Of_EnCon];
  uint8 StorageCondition[Dem_Cfg_Num_Of_StrCon];
  uint8 EnableConditionQueue[Dem_Cfg_Num_Of_EnCon];
  uint8 StorageConditionQueue[Dem_Cfg_Num_Of_StrCon];
  uint8 EnStrConditionFlag;
  uint8 QueueCount;
} Dem_EventType;

typedef struct
{
  uint32 DTC;
  uint16 EventId;
  Dem_DTCFormatType Format;
  Dem_DTCOriginType Orgin;
  uint8 QueueState;
  uint8 Req_Status;
} Dem_ClearDtcType;

typedef struct
{
  uint8 MemIndex;
  uint8 PendingCount;
  uint8 MemStatus;
  uint8 WriteStatus;
  boolean ReTryFlag;
} Dem_NvmWriteDataType;

typedef struct
{
  uint16 EventIndex;
  uint8 Dtc_StatusMask;
  uint8 Req_Status;
} Dem_FilterInfoType;

typedef struct
{
  uint16 State;
  uint16 QueueState;
  uint16 Flag;
} Dem_InternalOpCycleType;

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
Dem_InternalType Dem_Internal;
Dem_EventType Dem_Event;
Dem_ClearDtcType Dem_ClearDtc;
Dem_NvmWriteDataType Dem_NvmWriteData;

Dem_FilterInfoType Dem_FilterInfo;
Dem_InternalOpCycleType Dem_InternalOpCycle;

static Dem_Cfg_PrimaryMemEntryType l_Prev_Valid_Entry_S;

static void Dem_EventAvailabeStatusInit(void);
static void Dem_EventEnableConditionInit(void);
static void Dem_EventStorageConditionInit(void);
static void Dem_OperationCycleAutoStartInit(void);
static void Dem_InternalStatusRestoreFromNvm(void);
static Dem_EventIdType Dem_InternalGetEventIdByDTCValue(uint32 DTC);
static void Dem_SetInternalEventStatus(Dem_EventIdType EventId, uint8 Value);
static uint8 Dem_GetInternalEventStatus(Dem_EventIdType EventId);
static void Dem_SetInternalDebounceStatus(Dem_EventIdType EventId, uint8 Value);
static uint8 Dem_GetInternalDebounceStatus(Dem_EventIdType EventId);
/*static void Dem_CfgUdsStatusDataInit(void);
static void Dem_CfgOperationCycleCounterInit(void);
static void Dem_CfgPrimaryMemEntryInit(void);*/
static void Dem_ProcessEventAging(Dem_EventIdType flEventId, uint8 CycleId);
static void Dem_ProcessOperationCycleStateChange(uint8 CycleId, uint8 CycleStatus);
static void Dem_ProcessOperationCycleQueue(void);
static void Dem_MainFunctionProcessQueue(void);
static void Dem_MainFunctionProcessTimer(void);
static void Dem_MainFunctionProcessNvm(void);
static Std_ReturnType Dem_SetEventUpdateQueued(Dem_EventIdType EventId, Dem_EventStatusType EventStatus);
static Std_ReturnType Dem_SetEventUpdateImmediate(Dem_EventIdType EventId, Dem_EventStatusType EventStatus);
static Std_ReturnType Dem_SetEventQueueImmediate(Dem_EventIdType EventId, Dem_EventStatusType EventStatus);
static void Dem_ProcessQueuedEvent(void);
/*static void Dem_ProcessTimerEvents(Dem_EventIdType EventId,
    Dem_Cfg_DebounceTableType DebounceTable);
*/
static void Dem_ProcessQueueSetEventStatus(void);
static void Dem_FreezeOrResetInternalDebounceStatus(Dem_EventIdType flEventId);
static void Dem_ProcessDtcEnableCondition(void);
/*static void Dem_ProcessInitMForEventAll(Dem_InitMonitorReasonType flInitMReason);*/
static void Dem_NvmProcessPendingWrite(void);
static void Dem_NvmProcessRetryPendingWrite(void);
static Std_ReturnType Dem_ProcessCreatePrimaryMemEntry(Dem_EventIdType EventId,
    uint8 *flMemIndex);
static Std_ReturnType Dem_ProcessUpdatePrimaryMemEntry(Dem_EventIdType EventId,
    uint8 *flMemIndex);
static void Dem_ProcessDeletePrimaryMemEntry(uint8 flMemIndex);
static Dem_ReturnClearDTCType Dem_ClearDTCInternal(uint32 DTC,
    Dem_DTCFormatType DTCFormat, Dem_DTCOriginType DTCOrigin);
static void Dem_ProcessClearDtcQueue(void);

//MZHAO6 use for DTC snapshot
#define DTC_Snapshot
#ifdef DTC_Snapshot

static uint8 l_dem_snapshot_write_count_100ms_u8 = 0;
static uint8 l_ign_status_pre_u8 = 0;
static uint8 l_aging_count_u8[Dem_Cfg_Mem_Total_Entry];
static uint8 l_nvm_store_flag[Dem_Cfg_Mem_Total_Entry];

static void Dem_MainFunctionProcessSnapShot(void);
static void Dem_Snapshot_Write_Nvm_Process(void);
static void Dem_ProcessIGNEvent(void);
static void Dem_Get_SnapShot(Dem_Cfg_PrimaryMemEntryType* Entry);

#define DEM_DTC_SNAPSHOT_NONE         0
#define AGING_COUNT                   40
#define AGING_COUNT_NONE              0
#define SPEED_INVALID_VALUE           65535
#define DTC_SNAPSHOT_ID_VALUE         14

static uint16 l_speed_value_pre_u16 = 0;
static uint8  l_time_year_pre_u8 = 0;
static uint8  l_time_month_pre_u8 = 0;
static uint8  l_time_day_pre_u8 = 0;
static uint8  l_time_hour_pre_u8 = 0;
static uint8  l_time_second_pre_u8 = 0;
static uint8  l_time_minute_pre_u8 = 0;
static uint16 l_tach_value_pre_u16 = 0;

#endif

/*****************************************************************************
 *                   Functions                                                *
 ******************************************************************************/

/**************************************************************************
 Function name   : Dem_GetVersionInfo
 Arguments       : Std_VersionInfoType* versioninfo
 Return type     : void
 Sync/Async      : Synchronous
 Reentrancy      : Reentrant
 Description     : Returns the version information of this module..
 **************************************************************************/
void Dem_GetVersionInfo(Std_VersionInfoType* versioninfo)
{

}

/**************************************************************************
 Function name   :  Dem_SetInternalEventStatus
 Arguments       :  Dem_EventIdType EventId, uint8 Value
 Return type     :  void
 Sync/Async      :  Synchronous
 Reentrancy      :
 Description     :  Set the status of the internal event status.
 **************************************************************************/

static void Dem_SetInternalEventStatus(Dem_EventIdType EventId, uint8 Value)
{
  Value &= (DEM_EVENT_STATUS_BIT_MASK);
  Dem_Event.InternalStatus[EventId] &= ~(DEM_EVENT_STATUS_BIT_MASK << DEM_EVENT_STATUS_BIT_POS);
  Dem_Event.InternalStatus[EventId] |= (Value << DEM_EVENT_STATUS_BIT_POS);
}

/**************************************************************************
 Function name   :  Dem_GetInternalEventStatus
 Arguments       :  Dem_EventIdType EventId
 Return type     :  uint8
 Sync/Async      :  Synchronous
 Reentrancy      :
 Description     :  Get the status of the internal event status.
 **************************************************************************/
static uint8 Dem_GetInternalEventStatus(Dem_EventIdType EventId)
{
  uint8 fl_RetVal;
  fl_RetVal = (Dem_Event.InternalStatus[EventId] & (DEM_EVENT_STATUS_BIT_MASK << DEM_EVENT_STATUS_BIT_POS));
  return (fl_RetVal >> DEM_EVENT_STATUS_BIT_POS);
}

/**************************************************************************
 Function name   :  Dem_SetInternalDebounceStatus
 Arguments       :  Dem_EventIdType EventId, uint8 Value
 Return type     :  void
 Sync/Async      :  Synchronous
 Reentrancy      :
 Description     :  Set the status of the internal debounce status.
 **************************************************************************/

static void Dem_SetInternalDebounceStatus(Dem_EventIdType EventId, uint8 Value)
{
  Value &= (DEM_EVENT_DEBOUNCE_STATUS_BIT_MASK);
  Dem_Event.InternalStatus[EventId] &= ~(DEM_EVENT_DEBOUNCE_STATUS_BIT_MASK << DEM_EVENT_DEBOUNCE_STATUS_BIT_POS);
  Dem_Event.InternalStatus[EventId] |= (Value << DEM_EVENT_DEBOUNCE_STATUS_BIT_POS);
}

/**************************************************************************
 Function name   :  Dem_GetInternalDebounceStatus
 Arguments       :  Dem_EventIdType EventId, uint8 Value
 Return type     :  void
 Sync/Async      :  Synchronous
 Reentrancy      :
 Description     :  Get the status of the internal debounce status.
 **************************************************************************/
static uint8 Dem_GetInternalDebounceStatus(Dem_EventIdType EventId)
{
  uint8 fl_RetVal;
  fl_RetVal = (Dem_Event.InternalStatus[EventId] & 
              (DEM_EVENT_DEBOUNCE_STATUS_BIT_MASK << DEM_EVENT_DEBOUNCE_STATUS_BIT_POS));
  return (fl_RetVal >> DEM_EVENT_DEBOUNCE_STATUS_BIT_POS);
}

#if 0
/**************************************************************************
 Function name   :  Dem_CfgUdsStatusDataInit
 Arguments       :  void
 Return type     :  void
 Sync/Async      :  Synchronous
 Reentrancy      :
 Description     :  Used to initialize the UDS event status and related data
 to default values upon init.
 **************************************************************************/
static void Dem_CfgUdsStatusDataInit(void)
{
  uint8 flIter;
  Dem_Cfg_StatusData.FirstConfirmedEvent = DEM_EVENT_INVALID;
  Dem_Cfg_StatusData.FirstFailedEvent = DEM_EVENT_INVALID;
  Dem_Cfg_StatusData.RecentConfirmedEvent = DEM_EVENT_INVALID;
  Dem_Cfg_StatusData.RecentFailedEvent = DEM_EVENT_INVALID;
  for (flIter = 0; flIter < Dem_Cfg_Num_Of_Event; flIter++)
  {
    Dem_Cfg_StatusData.EventStatus[flIter] = DEM_UDS_STATUS_DEFAULT;
  }
  Dem_Event.InternalMemStatus[Dem_Cfg_Mem_Status_Index] = DEM_MEM_STATUS_TRIGGER_CLEAR;
  Dem_NvmWriteData.PendingCount = Dem_NvmWriteData.PendingCount + 1;
}

/**************************************************************************
 Function name   :  Dem_CfgOperationCycleCounterInit
 Arguments       :  void
 Return type     :  void
 Sync/Async      :  Synchronous
 Reentrancy      :
 Description     :  Used to initialize the Operation cycle counter and magic flag
 to default values upon init.
 **************************************************************************/
static void Dem_CfgOperationCycleCounterInit(void)
{
  uint8 flIter;
  Dem_Cfg_OpCycle.MagicFlag = DEM_NVM_MAGIC_VALUE;
  for (flIter = 0; flIter < Dem_Cfg_Num_Of_OpCycle; flIter++)
  {
    Dem_Cfg_OpCycle.Counter[flIter] = 0x0U;
  }
  Dem_Event.InternalMemStatus[Dem_Cfg_Mem_Admin_Index] = DEM_MEM_STATUS_TRIGGER_CLEAR;
  Dem_NvmWriteData.PendingCount = Dem_NvmWriteData.PendingCount + 1;
}

/**************************************************************************
 Function name   :  Dem_CfgOperationCycleCounterInit
 Arguments       :  void
 Return type     :  void
 Sync/Async      :  Synchronous
 Reentrancy      :
 Description     :  Used to initialize the primary memory entry init structures
 to default values upon init.
 **************************************************************************/
static void Dem_CfgPrimaryMemEntryInit(void)
{
  uint8 flIter;
  Dem_Cfg_PrimaryMemEntryType *flEntry;

  for (flIter = Dem_Cfg_Mem_Primary_Entry_Start; flIter < Dem_Cfg_Mem_Primary_Entry_Stop;
      flIter++)
  {
    flEntry = (Dem_Cfg_PrimaryMemEntryType*) Dem_Cfg_MemPtr[flIter];
    Dem_SetInternalEventStatus(flEntry->EventId, DEM_EVENT_STATUS_NONE);
    flEntry->AgingCounter = DEM_DTC_AGING_INVALID;
    flEntry->EventId = DEM_EVENT_INVALID;
    //flEntry->OccurrenceCounter = DEM_EVENT_OCCNTR_INVALID;
    flEntry->TimeStamb = DEM_EVENT_TMSTMP_INVALID;
    Dem_Event.InternalMemStatus[flIter] = DEM_MEM_STATUS_TRIGGER_CLEAR;
    Dem_NvmWriteData.PendingCount = Dem_NvmWriteData.PendingCount + 1;
  }
}
#endif

/* ECU State Manager <=> Dem */

/**************************************************************************
 Function name   : Dem_PreInit
 Arguments       : void
 Return type     : void
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant
 Description     : Initializes the internal states necessary to process
 events reported by BSW-modules.
 **************************************************************************/
void Dem_PreInit(void)
{

  uint8 flIter;

#if (DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if (Dem_Internal.InitState != DEM_UNINITIALIZED)
  {
    flError = DEM_DET_WRONG_CONDITION;
  }
  else
#endif
  {

    Dem_Internal.DtcSettingEnCondition = DEM_DTC_STORAGE_SETTING_ENABLED;
    Dem_Internal.DtcSettingEnConditionQueue = DEM_DTC_STORAGE_SETTING_ENABLED;
    Dem_Internal.DtcSettingConditionRequestedFlag = FALSE;

    Dem_Internal.TimeStampCounter = 0U;

    Dem_ClearDtc.DTC = 0U;
    Dem_ClearDtc.EventId = 0U;
    Dem_ClearDtc.Format = 0U;
    Dem_ClearDtc.Orgin = 0U;
    Dem_ClearDtc.Req_Status = 0U;
    Dem_ClearDtc.QueueState = 0;

    Dem_NvmWriteData.MemIndex = 0U;
    Dem_NvmWriteData.PendingCount = 0U;
    Dem_NvmWriteData.MemStatus = 0U;
    Dem_NvmWriteData.WriteStatus = 0U;
    Dem_NvmWriteData.ReTryFlag = 0U;

    Dem_FilterInfo.Dtc_StatusMask = 0U;
    Dem_FilterInfo.EventIndex = 0U;
    Dem_FilterInfo.Req_Status = 0U;

    Dem_InternalOpCycle.Flag = 0U;
    Dem_InternalOpCycle.QueueState = 0U;
    Dem_InternalOpCycle.State = 0U;

    Dem_Event.QueueCount = 0U;

    for (flIter = 0; flIter < Dem_Cfg_Num_Of_Event; flIter++)
    {
      Dem_Event.DebounceValue[flIter] = 0U;
      Dem_Event.InternalStatus[flIter] = 0U;
      Dem_Event.QueueStatus[flIter] = 0U;
    }

    for (flIter = 0; flIter < Dem_Cfg_Mem_Total_Entry; flIter++)
    {
      Dem_Event.InternalMemStatus[flIter] = 0U;
    }

    Dem_EventAvailabeStatusInit();
    Dem_EventEnableConditionInit();
    Dem_EventStorageConditionInit();
    Dem_OperationCycleAutoStartInit();/*Dem_InternalOpCycle.state*/

    Dem_Internal.InitState = DEM_PREINITIALIZED;
  }

#if (DemDevErrorDetect == TRUE)

  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
#endif

}

/**************************************************************************
 Function name   : Dem_OperationCycleAutoStartInit
 Arguments       : void
 Return type     : void
 Sync/Async      : Synchronous
 Reentrancy      :
 Description     : Used to initialize the operation cycle auto-start functionality
 upon pre-init.
 **************************************************************************/
static void Dem_OperationCycleAutoStartInit(void)
{
  uint8 flIter;
  for (flIter = 0; flIter < Dem_Cfg_Num_Of_OpCycle; flIter++)
  {
    if (FALSE != (Dem_Cfg_OpCycleState[flIter].AutoStart))
    {
      DEM_SET_OPERTATION_CYCLE_STATUS(Dem_InternalOpCycle.State, flIter);
    }
    else
    {
      DEM_RESET_OPERTATION_CYCLE_STATUS(Dem_InternalOpCycle.State, flIter);
    }
  }
}

/**************************************************************************
 Function name   : Dem_EventAvailabeStatusInit
 Arguments       : void
 Return type     : void
 Sync/Async      : Synchronous
 Reentrancy      :
 Description     : Used to initialize the event available status upon pre-init.
 **************************************************************************/
static void Dem_EventAvailabeStatusInit(void)
{
  uint8 flIter;
  uint8 flIndex;
  uint8 flMask;

  for (flIter = 0; flIter < Dem_Cfg_Num_Of_Event; flIter++)
  {
    flIndex = DEM_CALCULATE_INDEX(flIter);
    flMask = DEM_CALCULATE_MASK_BIT(flIter);
    /* Setting the Default bit wise status from configuration */
    if (FALSE != (Dem_Cfg_EventParameter[flIter].AvailableStatus))
    {
      DEM_SET_BIT_STATE(Dem_Event.AvailableStatus[flIndex], flMask);
    }
    else
    {
      DEM_RESET_BIT_STATE(Dem_Event.AvailableStatus[flIndex], flMask);
    }
  }
}

/**************************************************************************
 Function name   : Dem_EventEnableConditionInit
 Arguments       : void
 Return type     : void
 Sync/Async      : Synchronous
 Reentrancy      :
 Description     : Used to initialize the event enable condition upon pre-init.
 **************************************************************************/
static void Dem_EventEnableConditionInit(void)
{
  uint8 flIter;

  for (flIter = 0; flIter < Dem_Cfg_Num_Of_EnCon; flIter++)
  {
    Dem_Event.EnableCondition[flIter] = Dem_Cfg_EnableCondition[flIter].Status;
    Dem_Event.EnableConditionQueue[flIter] = Dem_Cfg_EnableCondition[flIter].Status;
  }
  DEM_RESET_BIT_STATE(Dem_Event.EnStrConditionFlag, DEM_EVENT_ENABLE_CONDITION_REQUESTED);

}

/**************************************************************************
 Function name   : Dem_EventStorageConditionInit
 Arguments       : void
 Return type     : void
 Sync/Async      : Synchronous
 Reentrancy      :
 Description     : Used to initialize the event storage condition upon pre-init.
 **************************************************************************/
static void Dem_EventStorageConditionInit(void)
{
  uint8 flIter;

  for (flIter = 0; flIter < Dem_Cfg_Num_Of_StrCon; flIter++)
  {
    Dem_Event.StorageCondition[flIter] = Dem_Cfg_StorageCondition[flIter].Status;
    Dem_Event.StorageConditionQueue[flIter] = Dem_Cfg_StorageCondition[flIter].Status;
  }
  DEM_RESET_BIT_STATE(Dem_Event.EnStrConditionFlag,
      DEM_EVENT_STORAGE_CONDITION_REQUESTED);
}

/**************************************************************************
 Function name   : Dem_InternalStatusRestoreFromNvm
 Arguments       : void
 Return type     : void
 Sync/Async      : Synchronous
 Reentrancy      :
 Description     : Used to restore the UDS event status from retained event volatile
 Entry if exists. Else restore the default values to all PRAM.
 **************************************************************************/
static void Dem_InternalStatusRestoreFromNvm(void)
{
  uint8 flMemIndex;
  Dem_Cfg_PrimaryMemEntryType *flEntry;

	for (flMemIndex = DEM_EVENT_VALID_ID_START; flMemIndex < Dem_Cfg_Mem_Total_Entry;flMemIndex++)
	{
		flEntry = (Dem_Cfg_PrimaryMemEntryType*) Dem_Cfg_MemPtr[flMemIndex];
		if ((flEntry->EventId == flMemIndex) && (flEntry->TimeStamb > 0))
		{
			DEM_SET_CFG_LAST_BAT_STORAGED(Dem_Cfg_StatusData.EventStatus[flMemIndex]);/*Read from Nvm memory to set cfg global*/
			if (flEntry->TimeStamb == DEM_TIMESTAMB_INVALID) 
			{
				flEntry->TimeStamb = 1;
			}
		}
	}
}

/**************************************************************************
 Function name   :  Dem_Init
 Arguments       :  const Dem_ConfigType* ConfigPtr
 Return type     :  void
 Sync/Async      :  Synchronous
 Reentrancy      :  Non Reentrant
 Description     :  Initializes or reinitializes this module.
 **************************************************************************/
void Dem_Init(const Dem_ConfigType* ConfigPtr)
{
#if (DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if ((Dem_Internal.InitState != DEM_PREINITIALIZED)
      && (Dem_Internal.InitState != DEM_SHUTDOWN))
  {
    flError = DEM_DET_WRONG_CONDITION;
  }
  else
#endif
  {
    /*** NVM Init ***/

    Dem_NvmWriteData.MemIndex = 0U;
    Dem_NvmWriteData.ReTryFlag = 0U;
    Dem_NvmWriteData.PendingCount = 0U;
    Dem_NvmWriteData.WriteStatus = DEM_NVM_IDLE;
    Dem_NvmWriteData.MemStatus = DEM_MEM_IDLE;

    Dem_ClearDtc.DTC = DEM_DTC_INVALID;
    Dem_ClearDtc.EventId = DEM_EVENT_INVALID;
    Dem_ClearDtc.Format = DEM_DTC_FORMAT_INVALID;
    Dem_ClearDtc.Orgin = DEM_DTC_ORIGIN_INVALID;
    Dem_ClearDtc.Req_Status = 0x0U;

    Dem_InternalStatusRestoreFromNvm();

    Dem_Internal.InitState = DEM_INITIALIZED;
  }
#if (DemDevErrorDetect == TRUE)

  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
#endif
}

/**************************************************************************
 Function name   : Dem_Shutdown
 Arguments       : void
 Return type     : void
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant
 Description     : Shuts down this module.
 **************************************************************************/
void Dem_Shutdown(void)
{
//   uint8 flIndex;

// #if (DemDevErrorDetect == TRUE)
//   uint8 flError;
//   flError = DEM_DET_NO_ERROR;
//   if (Dem_Internal.InitState != DEM_INITIALIZED)
//   {
//     flError = DEM_DET_UNINITIALIZED;
//   }
//   else
// #endif
//   {
//     Dem_Internal.InitState = DEM_SHUTDOWN;

//     for (flIndex = 0; flIndex < Dem_Cfg_Num_Of_OpCycle; flIndex++)
//     {
//       DEM_RESET_OPERTATION_CYCLE_STATUS(Dem_InternalOpCycle.QueueState, flIndex);
//       DEM_RESET_OPERTATION_CYCLE_STATUS(Dem_InternalOpCycle.Flag, flIndex);
//     }

//     for (flIndex = Dem_Cfg_Mem_Entry_Start; flIndex < Dem_Cfg_Mem_Primary_Entry_Stop;
//         flIndex++)
//     {
//       if (Dem_Event.InternalMemStatus[flIndex] != DEM_MEM_STATUS_NONE)
//       {
//         (void) NvM_SetRamBlockStatus((NvM_BlockIdType) Dem_Cfg_Memory_BlockId[flIndex],
//             TRUE);
//       }
//     }
//   }
// #if (DemDevErrorDetect == TRUE)
//   if (flError != DEM_DET_NO_ERROR)
//   {
//     Dem_Det_Error_register(0,flError);
//   }
// #endif
}

#if 0
/**************************************************************************
 Function name   : Dem_ProcessTimerEvents
 Arguments       : void
 Return type     : void
 Sync/Async      : Synchronous
 Reentrancy      :
 Description     : Does process of qualifying reported events which are configured for
 time debouncing algorithm.
 **************************************************************************/
static void Dem_ProcessTimerEvents(Dem_EventIdType EventId,
    Dem_Cfg_DebounceTableType DebounceTable)
{
  Dem_EventStatusType flEventStatus;
  Std_ReturnType flReturnVal;
  sint16 flOldDebounceValue;
  sint16 flNewDebounceValue;
  uint8 flInternalDebounceStatus;
  uint8 flOldUdsEventStatus;
  uint8 flNewUdsEventStatus;

  for (;;)
  {
    flOldDebounceValue = Dem_Event.DebounceValue[EventId];
    flOldUdsEventStatus = Dem_Cfg_StatusData.EventStatus[EventId];
    flNewDebounceValue = flOldDebounceValue;
    flNewUdsEventStatus = flOldUdsEventStatus;
    flEventStatus = DEM_EVENT_STATUS_INVALID;

    flInternalDebounceStatus = Dem_GetInternalDebounceStatus(EventId);
    switch (flInternalDebounceStatus)
    {
    case DEM_EVENT_DEBOUNCE_STATUS_NONE:
    case DEM_EVENT_DEBOUNCE_STATUS_FREEZE_FAIL:
    case DEM_EVENT_DEBOUNCE_STATUS_FREEZE_HEAL:
      break;

    case DEM_EVENT_DEBOUNCE_STATUS_PASSED:
      flNewDebounceValue = 0x0U;
      flEventStatus = DEM_EVENT_STATUS_PASSED;
      break;

    case DEM_EVENT_DEBOUNCE_STATUS_FAILED:
      flNewDebounceValue = 0x0U;
      flEventStatus = DEM_EVENT_STATUS_FAILED;
      break;

    case DEM_EVENT_DEBOUNCE_STATUS_HEALING:
      if (flNewDebounceValue > 0x1U)
      {
        flNewDebounceValue = flNewDebounceValue - 0x01U;
        flEventStatus = DEM_EVENT_STATUS_PREPASSED;
      }
      else
      {
        flNewDebounceValue = 0x0U;
        Dem_SetInternalDebounceStatus(EventId, DEM_EVENT_DEBOUNCE_STATUS_PASSED);
        flEventStatus = DEM_EVENT_STATUS_PASSED;
      }
      break;

    case DEM_EVENT_DEBOUNCE_STATUS_FAILING:
      if (flNewDebounceValue > 0x1U)
      {
        flNewDebounceValue = flNewDebounceValue - 0x01;
        flEventStatus = DEM_EVENT_STATUS_PREFAILED;
      }
      else
      {
        flNewDebounceValue = 0x0U;
        Dem_SetInternalDebounceStatus(EventId, DEM_EVENT_DEBOUNCE_STATUS_FAILED);
        flEventStatus = DEM_EVENT_STATUS_FAILED;
      }
      break;

    case DEM_EVENT_DEBOUNCE_STATUS_RESET_HEAL:
      flNewDebounceValue = DebounceTable.PassedTimeThershold;
      flEventStatus = DEM_EVENT_STATUS_PREPASSED;
      Dem_SetInternalDebounceStatus(EventId, DEM_EVENT_DEBOUNCE_STATUS_HEALING);
      break;

    case DEM_EVENT_DEBOUNCE_STATUS_RESET_FAIL:
      flNewDebounceValue = DebounceTable.FailedTimeThershold;
      flEventStatus = DEM_EVENT_STATUS_PREFAILED;
      Dem_SetInternalDebounceStatus(EventId, DEM_EVENT_DEBOUNCE_STATUS_FAILING);
      break;

    default:
      break;
    }

    if (flNewDebounceValue != flOldDebounceValue)
    {
      if (flEventStatus == DEM_EVENT_STATUS_PASSED)
      {
        DEM_RESET_UDS_STATUS_BYTE_TF(flNewUdsEventStatus);
        DEM_RESET_UDS_STATUS_BYTE_TNCSLC(flNewUdsEventStatus);
        DEM_RESET_UDS_STATUS_BYTE_TNCTMC(flNewUdsEventStatus);
      }
      else if (flEventStatus == DEM_EVENT_STATUS_FAILED)
      {
        DEM_SET_UDS_STATUS_BYTE_TFTMC(flNewUdsEventStatus);
        DEM_SET_UDS_STATUS_BYTE_TF(flNewUdsEventStatus);
        DEM_SET_UDS_STATUS_BYTE_TFSLC(flNewUdsEventStatus);
        DEM_SET_UDS_STATUS_BYTE_PDTC(flNewUdsEventStatus);
        DEM_SET_UDS_STATUS_BYTE_CDTC(flNewUdsEventStatus);
        DEM_RESET_UDS_STATUS_BYTE_TNCSLC(flNewUdsEventStatus);
        DEM_RESET_UDS_STATUS_BYTE_TNCTMC(flNewUdsEventStatus);
      }
      else
      {
        /* Do nothing */
      }

      Dem_EnterCriticalSection();
      if ((flOldUdsEventStatus != Dem_Cfg_StatusData.EventStatus[EventId])
          || (flOldDebounceValue != Dem_Event.DebounceValue[EventId]))
      {
        Dem_ExitCriticalSection();
        continue;
      }
      if (DEM_DTC_STORAGE_SETTING_ENABLED == Dem_Internal.DtcSettingEnCondition)
      {

        /***  Queue Event Status ***/
        flReturnVal = Dem_SetEventQueueImmediate(EventId, flEventStatus);

        /*** Update New event status  ***/
        if (flReturnVal == E_OK)
        {
          Dem_Cfg_StatusData.EventStatus[EventId] = flNewUdsEventStatus;
          Dem_Event.DebounceValue[EventId] = flNewDebounceValue;
        }
      }
      Dem_ExitCriticalSection();
    }
    break;
  }

}
#endif

/**************************************************************************
 Function name   : Dem_ProcessCreatePrimaryMemEntry
 Arguments       : Dem_EventIdType EventId,     uint8 *flMemIndex
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      :
 Description     : Used to find the free PRAM entry and create new entry into that.
 **************************************************************************/
static Std_ReturnType Dem_ProcessCreatePrimaryMemEntry(Dem_EventIdType EventId,
    uint8 *flMemIndex)
{
  uint8 flIndex;
  Std_ReturnType flReturnVal;
  Dem_Cfg_PrimaryMemEntryType *flEntry;

  flReturnVal = E_NOT_OK;

  /* Find New Free index */
  for (flIndex = Dem_Cfg_Mem_Primary_Entry_Start; flIndex < Dem_Cfg_Mem_Total_Entry; flIndex++)
  {
    flEntry = (Dem_Cfg_PrimaryMemEntryType*) Dem_Cfg_MemPtr[flIndex];
    if ((flEntry->EventId == DEM_EVENT_INVALID) && (flEntry->TimeStamb == DEM_EVENT_TMSTMP_INVALID))
    {
        Dem_Get_SnapShot(flEntry);
        flEntry->EventId = EventId;
        flEntry->AgingCounter = DEM_DTC_AGING_INVALID;
        //flEntry->OccurrenceCounter = 0x01U;
        flEntry->TimeStamb = Dem_Internal.TimeStampCounter;
        Dem_Internal.TimeStampCounter += 0x01U;
        *flMemIndex = flIndex;
        flReturnVal = E_OK;
        break;
    }
  }
  return flReturnVal;
}

/**************************************************************************
 Function name   : Dem_ProcessUpdatePrimaryMemEntry
 Arguments       : Dem_EventIdType EventId,     uint8 *flMemIndex
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      :
 Description     : Used to find the existing entry from reported EventId and
 update that entry with latest time stamp value.
 **************************************************************************/
static Std_ReturnType Dem_ProcessUpdatePrimaryMemEntry(Dem_EventIdType EventId,
    uint8 *flMemIndex)
{
  uint8 flIndex;
  Std_ReturnType flReturnVal;
  Dem_Cfg_PrimaryMemEntryType *flEntry;

  flReturnVal = E_NOT_OK;

  /* Find New Free index */
  for (flIndex = Dem_Cfg_Mem_Primary_Entry_Start; flIndex < Dem_Cfg_Mem_Total_Entry; flIndex++)
  {
    flEntry = (Dem_Cfg_PrimaryMemEntryType*) Dem_Cfg_MemPtr[flIndex];
    if (flEntry->EventId == EventId)
    {
        Dem_Get_SnapShot(flEntry);
        flEntry->AgingCounter = DEM_DTC_AGING_INVALID;
        /* If occurrence counter reached thershold, No need to put NVM entry */
        //if 1(flEntry->OccurrenceCounter < DEM_OCCURRENCE_COUNTER_THERSHOLD)
        {
            //flEntry->OccurrenceCounter = flEntry->OccurrenceCounter + 0x01U;
            flEntry->TimeStamb = Dem_Internal.TimeStampCounter;
            Dem_Internal.TimeStampCounter = Dem_Internal.TimeStampCounter + 0x01U;
            *flMemIndex = flIndex;
            flReturnVal = E_OK;
        }
        break;
    }
  }
  return flReturnVal;
}

/**************************************************************************
 Function name   : Dem_ProcessUpdatePrimaryMemEntry
 Arguments       : uint8 *flMemIndex
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      :
 Description     : Used to delete the reported entry from PRAM and trigger the NV storage.
 **************************************************************************/
static void Dem_ProcessDeletePrimaryMemEntry(uint8 flMemIndex)
{
  Dem_Cfg_PrimaryMemEntryType *flEntry;

  Dem_EnterCriticalSection();
  flEntry = (Dem_Cfg_PrimaryMemEntryType*) Dem_Cfg_MemPtr[flMemIndex];

  Dem_Event.DebounceValue[flEntry->EventId] = 0x00U;
  Dem_Cfg_StatusData.EventStatus[flEntry->EventId] = DEM_UDS_STATUS_DEFAULT;

  Dem_SetInternalEventStatus(flEntry->EventId, DEM_EVENT_STATUS_NONE);
  Dem_SetInternalDebounceStatus(flEntry->EventId, DEM_EVENT_DEBOUNCE_STATUS_NONE);

  if (FALSE != DEM_EVENT_GET_QUEUE_STATUS_PENDING(Dem_Event.QueueStatus[flEntry->EventId]))
  {
    DEM_EVENT_RESET_QUEUE_STATUS_PENDING(Dem_Event.QueueStatus[flEntry->EventId]);
    Dem_Event.QueueCount = Dem_Event.QueueCount - 0x01U;
  }

  flEntry->EventId = DEM_EVENT_INVALID;
  flEntry->AgingCounter = DEM_DTC_AGING_INVALID;
  //flEntry->OccurrenceCounter = DEM_EVENT_OCCNTR_INVALID;
  flEntry->TimeStamb = DEM_EVENT_TMSTMP_INVALID;
  flEntry->ignst = DEM_DTC_SNAPSHOT_NONE;
  flEntry->batt_volt = DEM_DTC_SNAPSHOT_NONE;
  flEntry->odo_value = DEM_DTC_SNAPSHOT_NONE;
  flEntry->speed_value = DEM_DTC_SNAPSHOT_NONE;
  flEntry->time_year = DEM_DTC_SNAPSHOT_NONE;
  flEntry->time_month = DEM_DTC_SNAPSHOT_NONE;
  flEntry->time_day = DEM_DTC_SNAPSHOT_NONE;
  flEntry->time_hour = DEM_DTC_SNAPSHOT_NONE;
  flEntry->time_minute = DEM_DTC_SNAPSHOT_NONE;
  flEntry->time_second = DEM_DTC_SNAPSHOT_NONE;
  flEntry->tach_speed = DEM_DTC_SNAPSHOT_NONE;
  l_nvm_store_flag[flMemIndex] = 0;
  l_aging_count_u8[flMemIndex] = AGING_COUNT_NONE;

  if (Dem_Event.InternalMemStatus[flMemIndex] == DEM_MEM_STATUS_NONE)
  {
    Dem_Event.InternalMemStatus[flMemIndex] = DEM_MEM_STATUS_TRIGGER_CLEAR;
    Dem_NvmWriteData.PendingCount += 0x01;
    Dem_NvmWriteData.MemStatus = DEM_MEM_DIRTY;
  }
  Dem_ExitCriticalSection();

}

/**************************************************************************
 Function name   : Dem_ProcessUpdatePrimaryMemEntry
 Arguments       : void
 Return type     : void
 Sync/Async      : Synchronous
 Reentrancy      :
 Description     : Does the processing of Operation Cycle state change requested queue.
 **************************************************************************/
static void Dem_ProcessOperationCycleQueue(void)
{
  uint8 flIter;
  uint8 flOldStatus;
  uint8 flNewStatus;

  for (flIter = 0; flIter < Dem_Cfg_Num_Of_OpCycle; flIter++)
  {
    if (FALSE != DEM_GET_OPERTATION_CYCLE_STATUS(Dem_InternalOpCycle.Flag, flIter))
    {
      DEM_RESET_OPERTATION_CYCLE_STATUS(Dem_InternalOpCycle.Flag, flIter);
      flOldStatus = DEM_GET_OPERTATION_CYCLE_STATUS(Dem_InternalOpCycle.State, flIter);
      flNewStatus = DEM_GET_OPERTATION_CYCLE_STATUS(Dem_InternalOpCycle.QueueState,flIter);

      if (FALSE != flNewStatus)
      {
        if (flOldStatus == flNewStatus)
        {
          /* Trigger the operations for Operation cycle Re-Starting */
          Dem_ProcessOperationCycleStateChange(flIter, DEM_OPERATION_QUEUE_CYCLE_RESTARTED);
        }
        else
        {
          /* Trigger the operations for Operation cycle Starting */
          Dem_ProcessOperationCycleStateChange(flIter, DEM_OPERATION_QUEUE_CYCLE_STARTED);
        }
      }
      else
      {
        /* Trigger the operations for Operation cycle Stops */
        Dem_ProcessOperationCycleStateChange(flIter, DEM_OPERATION_QUEUE_CYCLE_STOPED);
      }
    }
  }
}

/**************************************************************************
 Function name   : Dem_ProcessOperationCycleStateChange
 Arguments       : void
 Return type     : void
 Sync/Async      : Synchronous
 Reentrancy      :
 Description     : Does the action item for operation cycle state changes.
 **************************************************************************/
static void Dem_ProcessOperationCycleStateChange(uint8 CycleId, uint8 CycleStatus)
{
  Dem_EventIdType flEventId;
  Dem_UdsStatusByteType flNewUdsEventStatus;
  Dem_UdsStatusByteType flOldUdsEventStatus;
  uint8 flIsTestFailedLastOpCycle;

  /* Stop the Operation cycle state to not take any further report status */
  DEM_RESET_OPERTATION_CYCLE_STATUS(Dem_InternalOpCycle.State, CycleId);
  if (CycleStatus == DEM_OPERATION_QUEUE_CYCLE_STARTED)
  {
    Dem_Cfg_OpCycle.Counter[CycleId] = Dem_Cfg_OpCycle.Counter[CycleId] + 0x01U;
  }

  for (flEventId = DEM_EVENT_VALID_ID_START; flEventId < Dem_Cfg_Num_Of_Event; flEventId++)
  {
    flOldUdsEventStatus = Dem_Cfg_StatusData.EventStatus[flEventId];
    flNewUdsEventStatus = flOldUdsEventStatus;

    flIsTestFailedLastOpCycle = TRUE;
    if ((FALSE == DEM_GET_UDS_STATUS_BYTE_TFTMC(flOldUdsEventStatus)) && 
        (FALSE == DEM_GET_UDS_STATUS_BYTE_TNCTMC(flOldUdsEventStatus)))
    {
      flIsTestFailedLastOpCycle = FALSE;
    }

    if (CycleId == Dem_Cfg_EventParameter[flEventId].OpCycleRef)
    {
      if (DEM_OPERATION_QUEUE_CYCLE_STARTED == CycleStatus)
      {
        /*
         DEM_EVENT_RESET_QUEUE_STATUS_PENDING(Dem_Event.QueueStatus[flEventId]);
         DEM_EVENT_RESET_QUEUE_STATUS_FAILED(Dem_Event.QueueStatus[flEventId]);
         DEM_EVENT_RESET_QUEUE_STATUS_PASSED(Dem_Event.QueueStatus[flEventId]);
         Dem_Event.QueueCount = 0x00U;
         */
        /* New operation cycle started, Restore the UDS status for new OpCycle*/
        DEM_RESET_UDS_STATUS_BYTE_TF(flNewUdsEventStatus);
        DEM_RESET_UDS_STATUS_BYTE_TFTMC(flNewUdsEventStatus);
        DEM_SET_UDS_STATUS_BYTE_TNCTMC(flNewUdsEventStatus);
      }
      else
      {
        if (FALSE == flIsTestFailedLastOpCycle)
        {
          DEM_RESET_UDS_STATUS_BYTE_PDTC(flNewUdsEventStatus);
        }
      }

      if (DEM_OPERATION_QUEUE_CYCLE_RESTARTED != CycleStatus)
      {
        if (NULL != Dem_Cfg_EventParameter[flEventId].DemCallbackInitMForE)
        {
          Dem_Cfg_EventParameter[flEventId].DemCallbackInitMForE(DEM_INIT_MONITOR_RESTART);
        }
      }

      Dem_EnterCriticalSection();
      Dem_Cfg_StatusData.EventStatus[flEventId] = flNewUdsEventStatus;
      Dem_Event.DebounceValue[flEventId] = 0x0U;
      Dem_SetInternalDebounceStatus(flEventId, DEM_EVENT_DEBOUNCE_STATUS_NONE);
      Dem_ExitCriticalSection();
    }

    if (DEM_OPERATION_QUEUE_CYCLE_STARTED == CycleStatus)
    {
      if (DEM_EVENT_STATUS_NONE != Dem_GetInternalEventStatus(flEventId))
      {
        if (FALSE == flIsTestFailedLastOpCycle)
        {
          Dem_ProcessEventAging(flEventId, CycleId);
        }
      }
    }
  }

  if (CycleStatus != DEM_OPERATION_QUEUE_CYCLE_STOPED)
  {
    DEM_SET_OPERTATION_CYCLE_STATUS(Dem_InternalOpCycle.State, CycleId);
  }

}

/**************************************************************************
 Function name   : Dem_ProcessEventAging
 Arguments       : Dem_EventIdType flEventId, uint8 CycleId
 Return type     : void
 Sync/Async      : Synchronous
 Reentrancy      :
 Description     : Does qualifying process on stored event entry for event aging.
 **************************************************************************/
static void Dem_ProcessEventAging(Dem_EventIdType flEventId, uint8 CycleId)
{
  uint8 flMemIndex;
  Dem_Cfg_PrimaryMemEntryType *flEntry;
  uint8 flDtcAttributeTableRef;

  flDtcAttributeTableRef = Dem_Cfg_DTC[Dem_Cfg_EventParameter[flEventId].DTCTableRef].AttrbsRef;

  if ((FALSE != Dem_Cfg_DTCAttributes[flDtcAttributeTableRef].AgingAllowed) && 
      (CycleId == Dem_Cfg_DTCAttributes[flDtcAttributeTableRef].AgingOpCycleRef))
  {
    for (flMemIndex = Dem_Cfg_Mem_Primary_Entry_Start;
        flMemIndex < Dem_Cfg_Mem_Total_Entry; flMemIndex++)
    {
      flEntry = (Dem_Cfg_PrimaryMemEntryType*) Dem_Cfg_MemPtr[flMemIndex];
      if (flEntry->EventId == flEventId)
      {
        if (DEM_EVENT_STATUS_STORED == Dem_GetInternalEventStatus(flEventId))
        {
          flEntry->AgingCounter = (Dem_Cfg_OpCycle.Counter[CycleId] + Dem_Cfg_DTCAttributes[flDtcAttributeTableRef].AgingThershold);
          if (Dem_Event.InternalMemStatus[flMemIndex] == DEM_MEM_STATUS_NONE)
          {
            Dem_NvmWriteData.PendingCount += 0x01;
          }
          Dem_Event.InternalMemStatus[flMemIndex] = DEM_MEM_STATUS_TRIGGER_STORAGE;
          Dem_SetInternalEventStatus(flEventId, DEM_EVENT_STATUS_AGING);
        }

        if (DEM_EVENT_STATUS_AGING == Dem_GetInternalEventStatus(flEventId))
        {
          if (flEntry->AgingCounter <= Dem_Cfg_OpCycle.Counter[CycleId])
          {
            Dem_ProcessDeletePrimaryMemEntry(flMemIndex);
          }
        }
        break;
      }
    }
  }
}

#if 0
/**************************************************************************
 Function name   : Dem_ProcessInitMForEventAll
 Arguments       : Dem_InitMonitorReasonType flInitMReason
 Return type     : void
 Sync/Async      : Synchronous
 Reentrancy      :
 Description     : Does Callback the all configured monitor components for event enable or
 re-enable condition.
 **************************************************************************/
static void Dem_ProcessInitMForEventAll(Dem_InitMonitorReasonType flInitMReason)
{
  Dem_EventIdType flEventId;
  /*Std_ReturnType flRetVal;*/

  for (flEventId = DEM_EVENT_VALID_ID_START; flEventId < Dem_Cfg_Num_Of_Event;
      flEventId++)
  {
    if (NULL != Dem_Cfg_EventParameter[flEventId].DemCallbackInitMForE)
    {
      (void) Dem_Cfg_EventParameter[flEventId].DemCallbackInitMForE(flInitMReason);
    }
  }
}
#endif

/**************************************************************************
 Function name   : Dem_FreezeOrResetInternalDebounceStatus
 Arguments       : Dem_EventIdType flEventId
 Return type     : void
 Sync/Async      : Synchronous
 Reentrancy      :
 Description     : Reset or Freeze the internal event debounce status.
 **************************************************************************/
static void Dem_FreezeOrResetInternalDebounceStatus(Dem_EventIdType flEventId)
{
  uint8 flDebounceTableRef;

  flDebounceTableRef = Dem_Cfg_EventParameter[flEventId].DebounceTableRef;

  Dem_EnterCriticalSection();
  if (DEM_CFG_DEBOUNCETYPE_TIMER == Dem_Cfg_DebounceTable[flDebounceTableRef].AlgoClass)
  {
    if (Dem_Cfg_DebounceTable[flDebounceTableRef].behavior == DEM_DEBOUNCE_RESET)
    {
      Dem_Event.DebounceValue[flEventId] = 0U;
      Dem_SetInternalDebounceStatus(flEventId, DEM_EVENT_DEBOUNCE_STATUS_NONE);
    }
    else
    {
      switch (Dem_GetInternalDebounceStatus(flEventId))
      {
        case DEM_EVENT_DEBOUNCE_STATUS_PASSED:
        case DEM_EVENT_DEBOUNCE_STATUS_RESET_HEAL:
        case DEM_EVENT_DEBOUNCE_STATUS_HEALING:
          Dem_SetInternalDebounceStatus(flEventId, DEM_EVENT_DEBOUNCE_STATUS_FREEZE_HEAL);
          break;
        case DEM_EVENT_DEBOUNCE_STATUS_FAILED:
        case DEM_EVENT_DEBOUNCE_STATUS_FAILING:
        case DEM_EVENT_DEBOUNCE_STATUS_RESET_FAIL:
          Dem_SetInternalDebounceStatus(flEventId, DEM_EVENT_DEBOUNCE_STATUS_FREEZE_FAIL);
          break;
      }
    }
  }
  else
  { /* No Freeze for counter based algo */
    Dem_Event.DebounceValue[flEventId] = 0U;
  }
  Dem_ExitCriticalSection();

}

/**************************************************************************
 Function name   : Dem_ProcessDtcEnableCondition
 Arguments       : void
 Return type     : void
 Sync/Async      : Synchronous
 Reentrancy      :
 Description     : Does processing of action item has to taken for DTC storage setting
 enabled / disabled condition.
 **************************************************************************/
static void Dem_ProcessDtcEnableCondition(void)
{
  #if 0
  Dem_EventIdType flEventId;
  uint8 flMemInex;
  #endif /*Lhbb warning*/
  
  if ((Dem_Internal.DtcSettingEnCondition == DEM_DTC_STORAGE_SETTING_ENABLED) || 
      (Dem_Internal.DtcSettingEnConditionQueue == DEM_DTC_STORAGE_SETTING_ENABLED))
  {
    if (Dem_Internal.DtcSettingEnConditionQueue == DEM_DTC_STORAGE_SETTING_DISABLED)
    {
      /* Reset De-bounce and internal status */
      #if 0
        for (flEventId = DEM_EVENT_VALID_ID_START; flEventId < Dem_Cfg_Num_Of_Event;
            flEventId++)
        {
          Dem_FreezeOrResetInternalDebounceStatus(flEventId);
          DEM_EVENT_RESET_QUEUE_STATUS_PENDING(Dem_Event.QueueStatus[flEventId]);
          DEM_EVENT_RESET_QUEUE_STATUS_FAILED(Dem_Event.QueueStatus[flEventId]);
          DEM_EVENT_RESET_QUEUE_STATUS_PASSED(Dem_Event.QueueStatus[flEventId]);
        }
        Dem_Event.QueueCount = 0x00U;

        for (flMemInex = Dem_Cfg_Mem_Entry_Start;
            flMemInex < Dem_Cfg_Mem_Primary_Entry_Stop; flMemInex++)
        {
          if (Dem_Event.InternalMemStatus[flMemInex] != DEM_MEM_STATUS_NONE)
          {
            Dem_Event.InternalMemStatus[flMemInex] = DEM_MEM_STATUS_NONE;
            Dem_NvmWriteData.PendingCount = Dem_NvmWriteData.PendingCount - 1;
          }
        }
      #endif
    }
    else if (Dem_Internal.DtcSettingEnCondition == DEM_DTC_STORAGE_SETTING_ENABLED)
    {
      #if 0
      Dem_ProcessInitMForEventAll (DEM_INIT_MONITOR_STORAGE_REENABLED);
	    #endif
    }
    else
    {

    }
    Dem_EnterCriticalSection();
    Dem_Internal.DtcSettingEnCondition = Dem_Internal.DtcSettingEnConditionQueue;
    Dem_ExitCriticalSection();
  }
}

/**************************************************************************
 Function name   : Dem_ProcessQueueSetEventStatus
 Arguments       : void
 Return type     : void
 Sync/Async      : Synchronous
 Reentrancy      :
 Description     : Does processing of checking queued qualified result and takes necessary action
                   Dem_Event.Queuestatus  ->  Dem_Event.InterStatus = DEM_EVENT_STATUS_TRIGGERED
 **************************************************************************/
static void Dem_ProcessQueueSetEventStatus(void)
{
  Dem_EventIdType EventId;
  uint8 flReturnVal;
  uint8 flMemIndex;
  uint8 lQueueStatus;
  uint8 lQueueCount;

  flReturnVal = E_NOT_OK;
  lQueueCount = Dem_Event.QueueCount;
  for (EventId = DEM_EVENT_VALID_ID_START; EventId < Dem_Cfg_Num_Of_Event; EventId++)
  {
    lQueueStatus = Dem_Event.QueueStatus[EventId];
    if (FALSE != DEM_EVENT_GET_QUEUE_STATUS_PENDING(lQueueStatus))
    {
      if (FALSE != DEM_EVENT_GET_QUEUE_STATUS_FAILED(lQueueStatus))
      {
        if (DEM_EVENT_STATUS_NONE == Dem_GetInternalEventStatus(EventId))
        {
          flReturnVal = Dem_ProcessCreatePrimaryMemEntry(EventId, &flMemIndex);
        }
        else
        {
          flReturnVal = Dem_ProcessUpdatePrimaryMemEntry(EventId, &flMemIndex);
        }

        if (flReturnVal == E_OK)
        {
          if (Dem_Event.InternalMemStatus[flMemIndex] == DEM_MEM_STATUS_NONE)
          {
            Dem_NvmWriteData.PendingCount += 0x01;
            Dem_NvmWriteData.MemStatus = DEM_MEM_DIRTY;
          }
          Dem_Event.InternalMemStatus[flMemIndex] = DEM_MEM_STATUS_TRIGGER_STORAGE;
          Dem_SetInternalEventStatus(EventId, DEM_EVENT_STATUS_TRIGGERED);
        }
        DEM_EVENT_RESET_QUEUE_STATUS_FAILED(lQueueStatus);/*0x80*/
      }
      else if (FALSE != DEM_EVENT_GET_QUEUE_STATUS_PASSED(lQueueStatus))
      {
        if (DEM_EVENT_STATUS_NONE != Dem_GetInternalEventStatus(EventId))
        {
          /* Aging related activities ? */
          DEM_EVENT_RESET_QUEUE_STATUS_PASSED(lQueueStatus);
        }
      }
      else
      {

      }
      DEM_EVENT_RESET_QUEUE_STATUS_PENDING(lQueueStatus);
      Dem_Event.QueueStatus[EventId] = lQueueStatus;
      if (lQueueCount > 0)
      {
        lQueueCount--;
      }
    }
  }
  Dem_Event.QueueCount = lQueueCount;
}

/**************************************************************************
 Function name   : Dem_ProcessQueuedEvent
 Arguments       : void
 Return type     : void
 Sync/Async      : Synchronous
 Reentrancy      :
 Description     : Checks condition prior to process the queues event status
 **************************************************************************/
static void Dem_ProcessQueuedEvent(void)
{
  if ((DEM_DTC_STORAGE_SETTING_ENABLED == Dem_Internal.DtcSettingEnCondition) && 
      (Dem_ClearDtc.Req_Status == DEM_DCM_CLEAR_DTC_IDLE))
  {
    Dem_ProcessQueueSetEventStatus();
  }
}

/**************************************************************************
 Function name   : Dem_ProcessClearDtcQueue
 Arguments       : void
 Return type     : void
 Sync/Async      : Synchronous
 Reentrancy      :
 Description     : Does the processing of clearing event/s entry from PRAM and triggers
 the clearing of entry from NVM upon requested
 **************************************************************************/
static void Dem_ProcessClearDtcQueue(void)
{
  Dem_Cfg_PrimaryMemEntryType *flEntry;
  uint8 flMemIndex;

  if (Dem_ClearDtc.EventId != DEM_EVENT_INVALID)
  {/*ClearOneDTC*/
    if ((DEM_GET_CFG_LAST_BAT_STORAGED(Dem_Cfg_StatusData.EventStatus[Dem_ClearDtc.EventId]) ||
        (DEM_GET_CFG_FAILING(Dem_Cfg_StatusData.EventStatus[Dem_ClearDtc.EventId]))))
    {
      for (flMemIndex = Dem_Cfg_Mem_Primary_Entry_Start; flMemIndex < Dem_Cfg_Mem_Primary_Entry_Stop; flMemIndex++)
      {
        flEntry = (Dem_Cfg_PrimaryMemEntryType*) Dem_Cfg_MemPtr[flMemIndex];
        if (flEntry->EventId == Dem_ClearDtc.EventId)
        {
          Dem_ProcessDeletePrimaryMemEntry(flMemIndex);/*Clear one DTC Memory*/
          break;
        }
      }
    }
  }
  else
  {/*ClearAllDTC*/
    for (flMemIndex = Dem_Cfg_Mem_Primary_Entry_Start; flMemIndex < Dem_Cfg_Mem_Primary_Entry_Stop; flMemIndex++)
    {
      flEntry = (Dem_Cfg_PrimaryMemEntryType*) Dem_Cfg_MemPtr[flMemIndex];
      if (flEntry->EventId != DEM_EVENT_INVALID)
      {
        Dem_ProcessDeletePrimaryMemEntry(flMemIndex);
      }
    }
    Dem_Internal.TimeStampCounter = 0x00U;
  }
  Dem_ClearDtc.Req_Status = DEM_DCM_CLEAR_DTC_REQUEST_COMPLETED;

#if ((TRUE == DEM_CLRRESP_VOLATILE) || (TRUE == DEM_CLRRESP_NONVOLATILE_TRIGGER))
  Dem_ClearDtc.QueueState = DEM_DCM_CLEAR_DTC_QUEUE_DONE;
#endif
}

/**************************************************************************
 Function name   : Dem_ProcessEnableCondition
 Arguments       : void
 Return type     : void
 Sync/Async      : Synchronous
 Reentrancy      :
 Description     : Does the processing on queued enable condition and store conditon status.
 **************************************************************************/
static void Dem_ProcessEnableCondition(void)
{
  Dem_EventIdType flEventId;
  uint8 flConditionId;
  uint8 flOldEnableCondition;
  uint8 flNewEnableCondition;

  if (Dem_Event.EnStrConditionFlag & DEM_EVENT_ENABLE_CONDITION_REQUESTED)
  {
    for (flConditionId = 0; flConditionId < Dem_Cfg_Num_Of_EnCon; flConditionId++)
    {
      flOldEnableCondition = Dem_Event.EnableCondition[flConditionId];
      flNewEnableCondition = Dem_Event.EnableConditionQueue[flConditionId];
      if ((flOldEnableCondition == DEM_EVENT_ENABLE_CONDITION_FULFILLED) || (flNewEnableCondition == DEM_EVENT_ENABLE_CONDITION_FULFILLED))
      {
        /* Reset De-bounce and internal status */
        for (flEventId = DEM_EVENT_VALID_ID_START; flEventId < Dem_Cfg_Num_Of_Event; flEventId++)
        {
          if (Dem_Cfg_EventParameter[flEventId].EnableConditionRef == flConditionId)
          {
            if (flNewEnableCondition == DEM_EVENT_ENABLE_CONDITION_FAILED)
            {
              Dem_FreezeOrResetInternalDebounceStatus(flEventId);
            }
            else if (NULL != Dem_Cfg_EventParameter[flEventId].DemCallbackInitMForE)
            {
              (void) Dem_Cfg_EventParameter[flEventId].DemCallbackInitMForE(DEM_INIT_MONITOR_REENABLED);
            }
          }
        }
        Dem_Event.EnableCondition[flConditionId] = flNewEnableCondition;
      }
    }
    DEM_RESET_BIT_STATE(Dem_Event.EnStrConditionFlag,DEM_EVENT_ENABLE_CONDITION_REQUESTED);
  }

  if (Dem_Event.EnStrConditionFlag & DEM_EVENT_STORAGE_CONDITION_REQUESTED)
  {
    for (flConditionId = 0; flConditionId < Dem_Cfg_Num_Of_StrCon; flConditionId++)
    {
      flOldEnableCondition = Dem_Event.StorageCondition[flConditionId];
      flNewEnableCondition = Dem_Event.StorageConditionQueue[flConditionId];
      if ((flOldEnableCondition == DEM_EVENT_STORAGE_CONDITION_FULFILLED) || 
          (flNewEnableCondition == DEM_EVENT_STORAGE_CONDITION_FULFILLED))
      {
        /* Reset De-bounce and internal status */
        for (flEventId = DEM_EVENT_VALID_ID_START; flEventId < Dem_Cfg_Num_Of_Event; flEventId++)
        {
          if (Dem_Cfg_EventParameter[flEventId].EnableConditionRef == flConditionId)
          {
            if (flNewEnableCondition == DEM_EVENT_ENABLE_CONDITION_FAILED)
            {
              Dem_FreezeOrResetInternalDebounceStatus(flEventId);
            }
            else if (NULL != Dem_Cfg_EventParameter[flEventId].DemCallbackInitMForE)
            {
              (void) Dem_Cfg_EventParameter[flEventId].DemCallbackInitMForE(DEM_INIT_MONITOR_STORAGE_REENABLED);
            }
          }
        }
        Dem_Event.StorageCondition[flConditionId] = flNewEnableCondition;
      }
    }
    DEM_RESET_BIT_STATE(Dem_Event.EnStrConditionFlag, DEM_EVENT_STORAGE_CONDITION_REQUESTED);
  }
}

/**************************************************************************
 Function name   : Dem_ProcessEnableCondition
 Arguments       : void
 Return type     : void
 Sync/Async      : Synchronous
 Reentrancy      :
 Description     : Does the processing of main function queues.
 **************************************************************************/
static void Dem_MainFunctionProcessQueue(void)
{

  if (Dem_Event.QueueCount != 0)
  {
    Dem_ProcessQueuedEvent();
  }

  if (Dem_Internal.DtcSettingConditionRequestedFlag != FALSE)
  { /*Lhbb 0x85 DTCSetting*/
    Dem_ProcessDtcEnableCondition();
    Dem_Internal.DtcSettingConditionRequestedFlag = FALSE;
  }

  if (Dem_ClearDtc.Req_Status == DEM_DCM_CLEAR_DTC_REQUESTED)
  { /*Lhbb DEM_DCM_CLEAR_DTC_REQUESTED from Dem_ClearDTCInternal 0x14*/
    Dem_ProcessClearDtcQueue();
  }

  if (Dem_Event.EnStrConditionFlag != 0)
  {
    Dem_ProcessEnableCondition();
  }

  /* OpCycle state change should be called last ? */

  if (Dem_InternalOpCycle.Flag != 0U)
  {
    Dem_ProcessOperationCycleQueue();
  }

}

/**************************************************************************
 Function name   : Dem_NvmProcessRetryPendingWrite
 Arguments       : void
 Return type     : void
 Sync/Async      : Synchronous
 Reentrancy      :
 Description     : Does the processing NVM re-try pending job
 **************************************************************************/
static void Dem_NvmProcessRetryPendingWrite(void)
{
  Std_ReturnType flReturnVal;
  uint8 flMemIndex;
  Dem_Cfg_PrimaryMemEntryType *flEntry;
  uint16 flBlockId;
  flReturnVal = E_NOT_OK;

  for (flMemIndex = Dem_Cfg_Mem_Primary_Entry_Start; flMemIndex < Dem_Cfg_Mem_Total_Entry;
      flMemIndex++)
  {
    if (DEM_MEM_STATUS_STORE_RETRY == Dem_Event.InternalMemStatus[flMemIndex])
    {
      flEntry = (Dem_Cfg_PrimaryMemEntryType*) Dem_Cfg_MemPtr[flMemIndex];
      flBlockId = Dem_Cfg_Memory_BlockId[flMemIndex];
      
      flReturnVal = NvmServer_WriteBlock_ById(flBlockId, NULL, sizeof(Dem_Cfg_PrimaryMemEntryType));
      if (E_OK == flReturnVal)
      {
        Dem_NvmWriteData.MemIndex = flMemIndex;
        Dem_NvmWriteData.WriteStatus = DEM_NVM_WRITING;
      }
      break;
    }
    else if (DEM_MEM_STATUS_CLEAR_RETRY == Dem_Event.InternalMemStatus[flMemIndex])
    {
      flEntry = (Dem_Cfg_PrimaryMemEntryType*) Dem_Cfg_MemPtr[flMemIndex];
      flBlockId = Dem_Cfg_Memory_BlockId[flMemIndex];
      flReturnVal = NvmServer_WriteBlock_ById(flBlockId, flEntry, sizeof(Dem_Cfg_PrimaryMemEntryType));
      if (E_OK == flReturnVal)
      { 
        Dem_NvmWriteData.MemIndex = flMemIndex;
        Dem_NvmWriteData.WriteStatus = DEM_NVM_WRITING;
      }
      break;
    }
    else
    {

    }
  }
}

static void Dem_NvmProcessPendingWrite(void)
{
  uint16 flBlockId;
  Std_ReturnType flReturnVal;
  uint8 flMemIndex;
  Dem_Cfg_PrimaryMemEntryType *flEntry;
  flReturnVal = E_NOT_OK;

  Dem_NvmWriteData.ReTryFlag = TRUE;

  for (flMemIndex = DEM_EVENT_VALID_ID_START; flMemIndex < Dem_Cfg_Mem_Total_Entry;flMemIndex++)
  {
    if (DEM_GET_CFG_TRIGGER_STORE(Dem_Cfg_StatusData.EventStatus[flMemIndex]))
    {
      flEntry = (Dem_Cfg_PrimaryMemEntryType*) Dem_Cfg_MemPtr[flMemIndex];
	  
      flEntry->EventId = flMemIndex;
      if (flEntry->TimeStamb == DEM_TIMESTAMB_INVALID) 
      {
        flEntry->TimeStamb = 1;
      }
      else
      {
        flEntry->TimeStamb += 1;
      }
      flBlockId = Dem_Cfg_Memory_BlockId[flMemIndex];/*3-> block 1*/
      
      flReturnVal = NvmServer_WriteBlock_ById(flBlockId, flEntry, sizeof(Dem_Cfg_PrimaryMemEntryType));
      if (E_OK == flReturnVal)
      {
        DEM_CLR_CFG_TRIGGER_STORE(Dem_Cfg_StatusData.EventStatus[flMemIndex]);
        DEM_SET_CFG_CURRENT_STORAGED(Dem_Cfg_StatusData.EventStatus[flMemIndex]);
        DEM_SET_CFG_LAST_BAT_STORAGED(Dem_Cfg_StatusData.EventStatus[flMemIndex]);
      }
      Dem_NvmWriteData.ReTryFlag = FALSE;
      break;
    }
    /*else if (DEM_GET_CFG_CLR_STORAGED(Dem_Cfg_StatusData.EventStatus[flMemIndex]))*/
	  else if (DEM_MEM_STATUS_TRIGGER_CLEAR == Dem_Event.InternalMemStatus[flMemIndex])
    {
      flEntry = (Dem_Cfg_PrimaryMemEntryType*) Dem_Cfg_MemPtr[flMemIndex];
      flBlockId = Dem_Cfg_Memory_BlockId[flMemIndex];
      flReturnVal = NvmServer_WriteBlock_ById(flBlockId, NULL, sizeof(Dem_Cfg_PrimaryMemEntryType));
      if (E_OK == flReturnVal)
      {
		    DEM_CLR_CFG_LOW4BIT(Dem_Cfg_StatusData.EventStatus[flMemIndex]);/*Lhbb clear low 4 bit dtc status*/
		    Dem_Event.InternalMemStatus[flMemIndex] = DEM_MEM_STATUS_NONE;
        Dem_NvmWriteData.MemIndex = flMemIndex;
        Dem_NvmWriteData.WriteStatus = DEM_NVM_WRITING;
      }
      Dem_NvmWriteData.ReTryFlag = FALSE;
      break;
    }
    else
    {

    }
    /* No more fresh write available...Try for Retry flags*/
  }
  if ((FALSE != Dem_NvmWriteData.ReTryFlag) && (Dem_NvmWriteData.PendingCount != 0x0U))
  {
    Dem_NvmProcessRetryPendingWrite();
  }
}

static void Dem_MainFunctionProcessNvm(void)
{
  Dem_NvmProcessPendingWrite();
}

/* handle status Switch( Failing -> Trigger_Store) */
static void Dem_MainFunctionProcessTimer(void)
{
  	Dem_EventIdType EventId;

	if ((DEM_DTC_STORAGE_SETTING_ENABLED == Dem_Internal.DtcSettingEnCondition) && 
	    (Dem_ClearDtc.Req_Status == DEM_DCM_CLEAR_DTC_IDLE))
	{
		for (EventId = DEM_EVENT_VALID_ID_START; EventId < Dem_Cfg_Num_Of_Event; EventId++)
		{
			if (DEM_GET_CFG_FAILING(Dem_Cfg_StatusData.EventStatus[EventId]))
			{	/*if current failing*/
				if(DEM_GET_CFG_CURRENT_STORAGED(Dem_Cfg_StatusData.EventStatus[EventId]))
				{
					DEM_CLR_CFG_TRIGGER_STORE(Dem_Cfg_StatusData.EventStatus[EventId]);
				}
				else
				{   	  
					DEM_SET_CFG_TRIGGER_STORE(Dem_Cfg_StatusData.EventStatus[EventId]);
				}
			}	 	
		}
	}
}

/**************************************************************************
 Function name   : Dem_MainFunction
 Arguments       : void
 Return type     : void
 Sync/Async      :
 Reentrancy      :
 Description     : Processes all not event based Dem internal functions..
 **************************************************************************/
void Dem_MainFunction(void)
{
	if (Dem_Internal.InitState == DEM_INITIALIZED)
	{
		Dem_MainFunctionProcessTimer();
		Dem_MainFunctionProcessQueue();
		Dem_MainFunctionProcessNvm();
		Dem_MainFunctionProcessSnapShot();
	}
  
#ifdef DEM_NVM_Test
  static uint16 count = 0;

  count++;
  if(count == 1000)
  {
     count = 0;
     NvmServer_ReadBlock_ById(5, (uint8*)(&l_Read_UdsStatus), sizeof(Dem_Cfg_UdsStatusDataType));

    /* 0,1 don't use */
    //Dem_SetEventStatus(2, DEM_CFG_FAIL_VALUE);
    Dem_ReportErrorStatus(3, DEM_EVENT_STATUS_FAILED);
  }
#endif 
}

/*** Interface BSW modules / SW-Components <=> Dem  ***/

/**************************************************************************
 Function name   : Dem_ReportErrorStatus
 Arguments       : Dem_EventIdType EventId, Dem_EventStatusType EventStatus
 Return type     : void
 Sync/Async      : Asynchronous
 Reentrancy      : Reentrant for different EventIds. Non reentrant for the same
 EventId.
 Description     : Queues the reported events from the BSW modules (API is
 only used by BSW modules). The interface has an asynchronous
 behavior, because the processing of the event is
 done within the Dem main function.
 OBD Events Suppression shall be ignored for this computation.
 **************************************************************************/
void Dem_ReportErrorStatus(Dem_EventIdType EventId, Dem_EventStatusType EventStatus)
{
  uint8 flOpCycleId;
  uint8 flIndex;
  uint8 flMask;
  uint8 flAvailableCondition;
  uint8 flEnableCondition;

#if (DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if (Dem_Internal.InitState != DEM_INITIALIZED)
  {
    flError = DEM_DET_UNINITIALIZED;
  }
  else if (EventId >= Dem_Cfg_Num_Of_Event)
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else if (EventId == DEM_EVENT_INVALID)
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else if (Dem_Cfg_EventParameter[EventId].EventKind != DEM_EVENT_KIND_BSW)
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else if (EventStatus >= DEM_EVENT_STATUS_INVALID)
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else
#endif
  {
    flOpCycleId = Dem_Cfg_EventParameter[EventId].OpCycleRef;
    if (FALSE != DEM_GET_OPERTATION_CYCLE_STATUS(Dem_InternalOpCycle.State, flOpCycleId))
    {
      flIndex = DEM_CALCULATE_INDEX(EventId);
      flMask = DEM_CALCULATE_MASK_BIT(EventId);
      flAvailableCondition = DEM_GET_BIT_STATE(Dem_Event.AvailableStatus[flIndex],flMask);
      flEnableCondition = Dem_Cfg_EventParameter[EventId].EnableConditionRef;
      flEnableCondition = Dem_Event.EnableCondition[flEnableCondition];
      if ((FALSE != flAvailableCondition) && (FALSE != flEnableCondition))
      {
        if (DEM_CFG_DEBOUNCETYPE_TIMER == \
            Dem_Cfg_DebounceTable[Dem_Cfg_EventParameter[EventId].DebounceTableRef].AlgoClass)
        {
          (void) Dem_SetEventUpdateQueued(EventId, EventStatus);
        }
        else
        {
          (void) Dem_SetEventUpdateImmediate(EventId, EventStatus);
        }
      }
    }
  }

#if (DemDevErrorDetect == TRUE)
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
#endif

}

/**************************************************************************
 Function name   : Dem_SetEventAvailable
 Arguments       : Dem_EventIdType EventId, boolean AvailableStatus
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant.
 Description     : Set the available status of a specific Event.
 **************************************************************************/
Std_ReturnType Dem_SetEventAvailable(Dem_EventIdType EventId, boolean AvailableStatus)
{
  Std_ReturnType fl_RetVal;
  uint8 flIndex;
  uint8 flMask;
  fl_RetVal = E_OK;

#if (DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if (Dem_Internal.InitState != DEM_INITIALIZED)
  {
    flError = DEM_DET_UNINITIALIZED;
  }
  else if (EventId >= Dem_Cfg_Num_Of_Event)
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else if (EventId == DEM_EVENT_INVALID)
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else
#endif
  {
    flIndex = DEM_CALCULATE_INDEX(EventId);
    flMask = DEM_CALCULATE_MASK_BIT(EventId);
    Dem_EnterCriticalSection();
    if (AvailableStatus != FALSE)
    {
      DEM_SET_BIT_STATE(Dem_Event.AvailableStatus[flIndex], flMask);
    }
    else
    {
      DEM_RESET_BIT_STATE(Dem_Event.AvailableStatus[flIndex], flMask);
    }
    Dem_ExitCriticalSection();
  }

#if (DemDevErrorDetect == TRUE)
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
#endif
  return fl_RetVal;
}

static Std_ReturnType Dem_SetEventUpdateQueued(Dem_EventIdType EventId,
    Dem_EventStatusType EventStatus)
{
  Std_ReturnType flReturnVal;
  uint8 flOldInternalStatus;
  uint8 flNewInternalStatus;

  flReturnVal = E_OK;

  for (;;)
  {
    flOldInternalStatus = Dem_GetInternalDebounceStatus(EventId);/*4*/
    flNewInternalStatus = flOldInternalStatus;
    if (DEM_DTC_STORAGE_SETTING_ENABLED == Dem_Internal.DtcSettingEnCondition) /*ENABLED*/
    {
      switch (EventStatus)
      {
        case DEM_EVENT_STATUS_PREPASSED:
        if ((flOldInternalStatus == DEM_EVENT_DEBOUNCE_STATUS_NONE) /*00*/
            || (flOldInternalStatus == DEM_EVENT_DEBOUNCE_STATUS_FAILING) /*04*/
            || (flOldInternalStatus == DEM_EVENT_DEBOUNCE_STATUS_FAILED))/*02*/
        {
          flNewInternalStatus = DEM_EVENT_DEBOUNCE_STATUS_RESET_HEAL;/*05*/
        }
        else if (flOldInternalStatus == DEM_EVENT_DEBOUNCE_STATUS_FREEZE_HEAL)/*07*/
        {
          flNewInternalStatus = DEM_EVENT_DEBOUNCE_STATUS_HEALING;
        }
        break;

        case DEM_EVENT_STATUS_PREFAILED:
          if ((flOldInternalStatus == DEM_EVENT_DEBOUNCE_STATUS_NONE)
              || (flOldInternalStatus == DEM_EVENT_DEBOUNCE_STATUS_HEALING)
              || (flOldInternalStatus == DEM_EVENT_DEBOUNCE_STATUS_PASSED))
          {
            flNewInternalStatus = DEM_EVENT_DEBOUNCE_STATUS_RESET_FAIL;/*HEAL Reset From Fail*/
          }
          else if (flOldInternalStatus == DEM_EVENT_DEBOUNCE_STATUS_FREEZE_FAIL)
          {
            flNewInternalStatus = DEM_EVENT_DEBOUNCE_STATUS_FAILING;
          }
          break;

        case DEM_EVENT_STATUS_PASSED:
        flNewInternalStatus = DEM_EVENT_DEBOUNCE_STATUS_PASSED;
        break;

        case DEM_EVENT_STATUS_FAILED:
        flNewInternalStatus = DEM_EVENT_DEBOUNCE_STATUS_FAILED;
        break;
       default:
        break;
      }
    }
    else
    {
      flReturnVal = E_NOT_OK;
      break;
    }

    if (flOldInternalStatus != flNewInternalStatus)
    {
      Dem_EnterCriticalSection();
      if (flOldInternalStatus != Dem_GetInternalDebounceStatus(EventId))
      {
        Dem_ExitCriticalSection();
        continue;
      }
      Dem_SetInternalDebounceStatus(EventId, flNewInternalStatus);/*InternalStatus == 0x18*/
      Dem_ExitCriticalSection();
    }
    break;
  }
  return flReturnVal;
}

static Std_ReturnType Dem_SetEventQueueImmediate(Dem_EventIdType EventId, Dem_EventStatusType EventStatus)
{
  Std_ReturnType flReturnVal;
  uint8 lQueueStatus;
  uint8 lQueueCount;
  flReturnVal = E_OK;

  lQueueStatus = Dem_Event.QueueStatus[EventId];
  lQueueCount = Dem_Event.QueueCount;

  if (EventStatus == DEM_EVENT_STATUS_PASSED)
  {
    if (FALSE == DEM_EVENT_GET_QUEUE_STATUS_PENDING(lQueueStatus))
    {
      DEM_EVENT_SET_QUEUE_STATUS_PENDING(lQueueStatus);
      lQueueCount++;
    }

    if (FALSE == DEM_EVENT_GET_QUEUE_STATUS_PASSED(lQueueStatus))
    {
      DEM_EVENT_SET_QUEUE_STATUS_PASSED(lQueueStatus);
    }
  }
  else if (EventStatus == DEM_EVENT_STATUS_FAILED)
  {
    if (FALSE == DEM_EVENT_GET_QUEUE_STATUS_PENDING(lQueueStatus))
    {
      DEM_EVENT_SET_QUEUE_STATUS_PENDING(lQueueStatus);
      lQueueCount++;
    }

    if (FALSE == DEM_EVENT_GET_QUEUE_STATUS_FAILED(lQueueStatus))
    {
      DEM_EVENT_SET_QUEUE_STATUS_FAILED(lQueueStatus);
    }

    if (Dem_Cfg_StatusData.FirstFailedEvent != DEM_EVENT_INVALID)
    {
      Dem_Cfg_StatusData.RecentFailedEvent = EventId;
      Dem_Cfg_StatusData.RecentConfirmedEvent = EventId;
    }
    else
    {
      Dem_Cfg_StatusData.FirstConfirmedEvent = EventId;
      Dem_Cfg_StatusData.FirstFailedEvent = EventId;
    }
  }
  else
  {
  }

  if (lQueueStatus != Dem_Event.QueueStatus[EventId])
  {
    Dem_Event.QueueStatus[EventId] = lQueueStatus;
  }
  if (lQueueCount != Dem_Event.QueueCount)
  {
    Dem_Event.QueueCount = lQueueCount;
  }
  return flReturnVal;
}

static Std_ReturnType Dem_SetEventUpdateImmediate(Dem_EventIdType EventId, Dem_EventStatusType EventStatus)
{
  Std_ReturnType flReturnVal;
  sint16 flOldDebounceValue;
  sint16 flNewDebounceValue;
  sint16 flJumpToValue;
  uint8 flOldUdsEventStatus;
  uint8 flNewUdsEventStatus;
  uint8 flCfgDebounceTableRef;

  flReturnVal = E_OK;

  for (;;)
  {
    flOldUdsEventStatus = Dem_Cfg_StatusData.EventStatus[EventId];
    flNewUdsEventStatus = flOldUdsEventStatus;
    flOldDebounceValue = Dem_Event.DebounceValue[EventId];
    flNewDebounceValue = flOldDebounceValue;

    if (DEM_DTC_STORAGE_SETTING_ENABLED == Dem_Internal.DtcSettingEnCondition)
    {
      flCfgDebounceTableRef = Dem_Cfg_EventParameter[EventId].DebounceTableRef;
      switch (EventStatus)
      {
      case DEM_EVENT_STATUS_PREPASSED:
        if (FALSE != (Dem_Cfg_DebounceTable[flCfgDebounceTableRef].JumpDown))
        {
          flJumpToValue = Dem_Cfg_DebounceTable[flCfgDebounceTableRef].JumpDownValue;
          if (flOldDebounceValue > flJumpToValue)
          {
            flNewDebounceValue = flJumpToValue;
          }
          else
          {
            flNewDebounceValue = flOldDebounceValue;
          }
        }

        if (Dem_Cfg_DebounceTable[flCfgDebounceTableRef].PassedThershold
            >= (flNewDebounceValue
                + Dem_Cfg_DebounceTable[flCfgDebounceTableRef].DecStepSize))
        {
          flNewDebounceValue = Dem_Cfg_DebounceTable[flCfgDebounceTableRef]
              .PassedThershold;
          EventStatus = DEM_EVENT_STATUS_PASSED;
        }
        else
        {
          flNewDebounceValue += Dem_Cfg_DebounceTable[flCfgDebounceTableRef].DecStepSize;
        }
        break;

      case DEM_EVENT_STATUS_PREFAILED:
        if (FALSE != (Dem_Cfg_DebounceTable[flCfgDebounceTableRef].JumpUp))
        {
          flJumpToValue = Dem_Cfg_DebounceTable[flCfgDebounceTableRef].JumpUpValue;
          if (flOldDebounceValue < flJumpToValue)
          {
            flNewDebounceValue = flJumpToValue;
          }
          else
          {
            flNewDebounceValue = flOldDebounceValue;
          }
        }

        if (Dem_Cfg_DebounceTable[flCfgDebounceTableRef].FailedThershold
            <= (flNewDebounceValue
                + Dem_Cfg_DebounceTable[flCfgDebounceTableRef].IncStepSize))
        {
          flNewDebounceValue = Dem_Cfg_DebounceTable[flCfgDebounceTableRef]
              .FailedThershold;
          EventStatus = DEM_EVENT_STATUS_FAILED;
        }
        else
        {
          flNewDebounceValue += Dem_Cfg_DebounceTable[flCfgDebounceTableRef].IncStepSize;
        }
        break;

      case DEM_EVENT_STATUS_PASSED:
        flNewDebounceValue = Dem_Cfg_DebounceTable[flCfgDebounceTableRef].PassedThershold;
        EventStatus = DEM_EVENT_STATUS_PASSED;
        break;

      case DEM_EVENT_STATUS_FAILED:
        flNewDebounceValue = Dem_Cfg_DebounceTable[flCfgDebounceTableRef].FailedThershold;
        EventStatus = DEM_EVENT_STATUS_FAILED;
        break;
      default:
        break;
      }
    }
    else
    {
      flReturnVal = E_NOT_OK;
      break;
    }

    if (flNewDebounceValue != flOldDebounceValue)
    {
      if (EventStatus == DEM_EVENT_STATUS_PASSED)
      {
        DEM_RESET_UDS_STATUS_BYTE_TF(flNewUdsEventStatus);
        DEM_RESET_UDS_STATUS_BYTE_TNCSLC(flNewUdsEventStatus);
        DEM_RESET_UDS_STATUS_BYTE_TNCTMC(flNewUdsEventStatus);
      }
      else if (EventStatus == DEM_EVENT_STATUS_FAILED)
      {
        DEM_SET_UDS_STATUS_BYTE_TFTMC(flNewUdsEventStatus);
        DEM_SET_UDS_STATUS_BYTE_TF(flNewUdsEventStatus);
        DEM_SET_UDS_STATUS_BYTE_TFSLC(flNewUdsEventStatus);
        DEM_SET_UDS_STATUS_BYTE_PDTC(flNewUdsEventStatus);
        DEM_SET_UDS_STATUS_BYTE_CDTC(flNewUdsEventStatus);
        DEM_RESET_UDS_STATUS_BYTE_TNCSLC(flNewUdsEventStatus);
        DEM_RESET_UDS_STATUS_BYTE_TNCTMC(flNewUdsEventStatus);
      }
      else
      {
        /* Do nothing */
      }

      Dem_EnterCriticalSection();
      if ((flOldUdsEventStatus != Dem_Cfg_StatusData.EventStatus[EventId])
          || (flOldDebounceValue != Dem_Event.DebounceValue[EventId]))
      {
        Dem_ExitCriticalSection();
        continue;
      }

      /***  Queue Event Status ***/
      flReturnVal = Dem_SetEventQueueImmediate(EventId, EventStatus);

      /*** Update New event status  ***/
      if (flReturnVal == E_OK)
      {
        Dem_Cfg_StatusData.EventStatus[EventId] = flNewUdsEventStatus;
        Dem_Event.DebounceValue[EventId] = flNewDebounceValue;
      }
      Dem_ExitCriticalSection();
    }
    break;
  }

  return flReturnVal;
}

/**************************************************************************
 Function name   : Dem_SetEventStatus
 Arguments       : Dem_EventIdType EventId, Dem_EventStatusType EventStatus
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous/Asynchronous
 Reentrancy      : Reentrant for different EventIds. Non reentrant for the same
 EventId.
 Description     : Processes the events reported by SW-Cs via RTE. This API
 can only be used through the RTE, and therefore no declaration
 is exported via Dem.h. Some bits of the UDS DTC
 status byte changes synchronously or asynchronously (refer
 to Dem036 and Dem379).
 OBD Events Suppression shall be ignored for this computation.
 **************************************************************************/
Std_ReturnType Dem_SetEventStatus(Dem_EventIdType EventId, Dem_EventStatusType EventStatus)
{
  Std_ReturnType fl_RetVal;

  fl_RetVal = E_NOT_OK;
#if (DemDevErrorDetect == TRUE)
  //uint8 flError;
  //flError = DEM_DET_NO_ERROR;
  if (Dem_Internal.InitState != DEM_INITIALIZED)
  {
    fl_RetVal = DEM_DET_UNINITIALIZED;
  }
  else if (EventId >= Dem_Cfg_Num_Of_Event) /*34*/
  {
    fl_RetVal = DEM_DET_INVALID_PARAMETER;
  }
  else if (EventId == DEM_EVENT_INVALID)
  {
    fl_RetVal = DEM_DET_INVALID_PARAMETER;
  }
  else if (Dem_Cfg_EventParameter[EventId].EventKind != DEM_EVENT_KIND_SWC)
  {
    fl_RetVal = DEM_DET_INVALID_PARAMETER;
  }
  else if (EventStatus >= DEM_EVENT_STATUS_INVALID) /*>=04*/
  {
    fl_RetVal = DEM_DET_INVALID_PARAMETER;
  }
  else if (DEM_DTC_STORAGE_SETTING_DISABLED == Dem_Internal.DtcSettingEnCondition)
  {
    return DEM_DET_NO_ERROR;/*Lhbb DiagnosticInformation== 0 not set new event */
  }
  else
#endif
  {
    switch (EventStatus)
    {
		  case DEM_CFG_FAIL_VALUE:/*Lhbb dem current failed*/
        if (DEM_GET_CFG_FAILING(Dem_Cfg_StatusData.EventStatus[EventId]))
        {
          /*Lhbb is failing from this IGN ON,no operation*/
        }
        else
        {
          DEM_SET_CFG_FAILING(Dem_Cfg_StatusData.EventStatus[EventId]);
        }
        break;
		  case DEM_CFG_PASS_VALUE:/*Lhbb dem current passed*/
        if (DEM_GET_CFG_FAILING(Dem_Cfg_StatusData.EventStatus[EventId]))
        {
          DEM_CLR_CFG_FAILING(Dem_Cfg_StatusData.EventStatus[EventId]);
        }
        else
        {  
          /*Lhbb is passed from this IGN ON,no operation*/
        }			
        break;
		  default:
        break;
    }
	  fl_RetVal = DEM_DET_NO_ERROR;
  }
  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_ResetEventDebounceStatus
 Arguments       : Dem_EventIdType EventId,
 Dem_DebounceResetStatusType DebounceResetStatus)
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Reentrant for different EventIds. Non reentrant for the same
 EventId.
 Description     : Control the internal debounce counter/timer by BSW modules
 and SW-Cs. The event qualification will not be affected
 by these debounce state changes. This API is available for
 BSW modules as soon as Dem_PreInit has been completed
 **************************************************************************/
Std_ReturnType Dem_ResetEventDebounceStatus(Dem_EventIdType EventId,
    Dem_DebounceResetStatusType DebounceResetStatus)
{
  Std_ReturnType fl_RetVal;
  fl_RetVal = E_NOT_OK;

#if (DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if (Dem_Internal.InitState != DEM_INITIALIZED)
  {
    flError = DEM_DET_UNINITIALIZED;
  }
  else if (EventId >= Dem_Cfg_Num_Of_Event)
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else if (EventId == DEM_EVENT_INVALID)
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else if (DebounceResetStatus > DEM_DEBOUNCE_STATUS_RESET)
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else
#endif
  {
    Dem_EnterCriticalSection();
    if (DebounceResetStatus == DEM_DEBOUNCE_STATUS_RESET)
    {
      Dem_Event.DebounceValue[EventId] = 0U;
      Dem_SetInternalDebounceStatus(EventId, DEM_EVENT_DEBOUNCE_STATUS_RESET);
    }
    else
    {
      switch (Dem_GetInternalDebounceStatus(EventId))
      {
      case DEM_EVENT_DEBOUNCE_STATUS_PASSED:
      case DEM_EVENT_DEBOUNCE_STATUS_RESET_HEAL:
      case DEM_EVENT_DEBOUNCE_STATUS_HEALING:
        Dem_SetInternalDebounceStatus(EventId, DEM_EVENT_DEBOUNCE_STATUS_FREEZE_HEAL);
        break;
      case DEM_EVENT_DEBOUNCE_STATUS_FAILED:
      case DEM_EVENT_DEBOUNCE_STATUS_FAILING:
      case DEM_EVENT_DEBOUNCE_STATUS_RESET_FAIL:
        Dem_SetInternalDebounceStatus(EventId, DEM_EVENT_DEBOUNCE_STATUS_FREEZE_FAIL);
        break;
      }
    }
    fl_RetVal = E_OK;
    Dem_ExitCriticalSection();
  }

#if (DemDevErrorDetect == TRUE)
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0, flError);
  }
#endif
  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_ResetEventStatus
 Arguments       : Dem_EventIdType EventId
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Reentrant for different EventIds. Non reentrant for the same
 EventId.
 Description     : Resets the event failed status. This API can only be used
 through the RTE and therefore no declaration is exported via
 Dem.h.
 **************************************************************************/
Std_ReturnType Dem_ResetEventStatus(Dem_EventIdType EventId)
{
  Std_ReturnType fl_RetVal;
  fl_RetVal = E_NOT_OK;

#if (DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if (Dem_Internal.InitState != DEM_INITIALIZED)
  {
    flError = DEM_DET_UNINITIALIZED;
  }
  else if (EventId >= Dem_Cfg_Num_Of_Event)
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else if (EventId == DEM_EVENT_INVALID)
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else
#endif
  {
    Dem_EnterCriticalSection();
    if (FALSE != DEM_GET_UDS_STATUS_BYTE_TNCTMC(Dem_Cfg_StatusData.EventStatus[EventId]))
    {
      DEM_RESET_UDS_STATUS_BYTE_TF(Dem_Cfg_StatusData.EventStatus[EventId]);
      Dem_FreezeOrResetInternalDebounceStatus(EventId);
      Dem_ExitCriticalSection();
      fl_RetVal = E_OK;
    }
  }

#if (DemDevErrorDetect == TRUE)
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0, flError);
  }
#endif
  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_PrestoreFreezeFrame
 Arguments       : Dem_EventIdType EventId
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Reentrant for different EventIds. Non reentrant for the same
 EventId.
 Description     : Captures the freeze frame data for a specific event. This
 API can only be used through the RTE and therefore no
 declaration is exported via Dem.h.
 **************************************************************************/
Std_ReturnType Dem_PrestoreFreezeFrame(Dem_EventIdType EventId)
{
  Std_ReturnType fl_RetVal;
  fl_RetVal = E_OK;
  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_ClearPrestoredFreezeFrame
 Arguments       : Dem_EventIdType EventId
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Reentrant for different EventIds. Non reentrant for the same
 EventId.
 Description     : Clears a prestored freeze frame of a specific event. This
 API can only be used through the RTE and therefore no
 declaration is exported via Dem.h.
 **************************************************************************/
Std_ReturnType Dem_ClearPrestoredFreezeFrame(Dem_EventIdType EventId)
{
  Std_ReturnType fl_RetVal;
  fl_RetVal = E_OK;
  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_SetOperationCycleState
 Arguments       : uint8 OperationCycleId,
 Dem_OperationCycleStateType CycleState
 Return type     : Std_ReturnType
 Sync/Async      : Asynchronous
 Reentrancy      : Reentrant.
 Description     : Sets an operation cycle state. This API can only be used
 through the RTE and therefore no declaration is exported via
 Dem.h.
 **************************************************************************/
Std_ReturnType Dem_SetOperationCycleState(uint8 OperationCycleId,
    Dem_OperationCycleStateType CycleState)
{
  Std_ReturnType fl_RetVal;
  uint8 flOpCycleStatus;
  fl_RetVal = E_OK;

#if (DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if (Dem_Internal.InitState != DEM_INITIALIZED)
  {
    flError = DEM_DET_UNINITIALIZED;
    fl_RetVal = E_NOT_OK;
  }
  else if (OperationCycleId >= Dem_Cfg_Num_Of_OpCycle)
  {
    flError = DEM_DET_INVALID_PARAMETER;
    fl_RetVal = E_NOT_OK;
  }
  else if (CycleState >= DEM_OPCYCLE_STATE_INVALID)
  {
    flError = DEM_DET_INVALID_PARAMETER;
    fl_RetVal = E_NOT_OK;
  }
  else
#endif
  {

    /* !!! check for critical section code - later */

    flOpCycleStatus = DEM_OPERATION_QUEUE_CYCLE_STOPED;
    if (FALSE
        != DEM_GET_OPERTATION_CYCLE_STATUS(Dem_InternalOpCycle.State, OperationCycleId))
    {
      flOpCycleStatus = DEM_OPERATION_QUEUE_CYCLE_STARTED;
    }

    /* Check Current operation cycle state and requested state are for STOP. If yes,
     *  no need to proceed further */

    if ((flOpCycleStatus != DEM_OPERATION_QUEUE_CYCLE_STOPED)
        || (CycleState != DEM_CYCLE_STATE_END))
    {
      /* Check if already queued cycle request is there ? */
      if (FALSE
          != DEM_GET_OPERTATION_CYCLE_STATUS(Dem_InternalOpCycle.Flag, OperationCycleId))

      {
        /* Check Pending state is for STOP */
        if (FALSE
            == DEM_GET_OPERTATION_CYCLE_STATUS(Dem_InternalOpCycle.QueueState,
                OperationCycleId))
        {
          /* If pending state is for STOP, take new start request alone */
          if (CycleState == DEM_CYCLE_STATE_START)
          {
            DEM_SET_OPERTATION_CYCLE_STATUS(Dem_InternalOpCycle.QueueState,
                OperationCycleId);
          }
        }

      }
      else
      {
        DEM_SET_OPERTATION_CYCLE_STATUS(Dem_InternalOpCycle.Flag, OperationCycleId);
        if (CycleState == DEM_CYCLE_STATE_START)
        {
          DEM_SET_OPERTATION_CYCLE_STATUS(Dem_InternalOpCycle.QueueState,
              OperationCycleId);
        }
        else
        {
          DEM_RESET_OPERTATION_CYCLE_STATUS(Dem_InternalOpCycle.QueueState,
              OperationCycleId);
        }
      }

    }
  }

#if (DemDevErrorDetect == TRUE)
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
#endif
  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_GetOperationCycleState
 Arguments       : uint8 OperationCycleId,
 Dem_OperationCycleStateType* CycleState
 Return type     : Std_ReturnType
 Sync/Async      : Asynchronous
 Reentrancy      : Reentrant.
 Description     : Gets information about the status of a specific operation cycle.
 This API can only be used through the RTE and therefore
 no declaration is exported via Dem.h.
 **************************************************************************/
Std_ReturnType Dem_GetOperationCycleState(uint8 OperationCycleId,
    Dem_OperationCycleStateType* CycleState)
{
  Std_ReturnType fl_RetVal;
  fl_RetVal = E_OK;
  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_SetAgingCycleState
 Arguments       : uint8 OperationCycleId
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Reentrant.
 Description     : Triggers the next aging cycle state. This API can only be
 used through the RTE, and therefore no declaration is exported
 via Dem.h.
 **************************************************************************/
Std_ReturnType Dem_SetAgingCycleState(uint8 OperationCycleId)
{
  Std_ReturnType fl_RetVal;
  fl_RetVal = E_OK;
  return fl_RetVal;
}

#if (DEM_PROCESS_AGING_CTR_EXTERN == FALSE)
/**************************************************************************
 Function name   : Dem_SetAgingCycleCounterValue
 Arguments       : uint8 CounterValue
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant.
 Description     : Provides the value of the external aging counter. This API
 can only be used through the RTE, and therefore no declaration
 is exported via Dem.h.
 **************************************************************************/
Std_ReturnType Dem_SetAgingCycleCounterValue(uint8 CounterValue)
{
  Std_ReturnType fl_RetVal;
  fl_RetVal = E_OK;
  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_SetWIRStatus
 Arguments       : Dem_EventIdType EventId, boolean WIRStatus
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Reentrant for different EventIds. Non reentrant for the same
 EventId.Non Reentrant.
 Description     : Sets the WIR status bit via failsafe SW-Cs.
 This API can only be used through the RTE and therefore no
 declaration is exported via Dem.h.
 **************************************************************************/
Std_ReturnType Dem_SetWIRStatus(Dem_EventIdType EventId, boolean WIRStatus)
{
  Std_ReturnType fl_RetVal;
  fl_RetVal = E_OK;
  return fl_RetVal;
}

#endif

/**************************************************************************
 Function name   : Dem_GetComponentFailed
 Arguments       : Dem_ComponentIdType ComponentId, boolean* ComponentFailed
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Reentrant.
 Description     : Gets the failed status of a DemComponent.
 **************************************************************************/
Std_ReturnType Dem_GetComponentFailed(Dem_ComponentIdType ComponentId,
    boolean* ComponentFailed)
{
  Std_ReturnType fl_RetVal;
  fl_RetVal = E_OK;
  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_GetEventStatus
 Arguments       : Dem_EventIdType EventId,
 Dem_UdsStatusByteType* EventStatusByte
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Reentrant
 Description     : Gets the current extended event status of an event.
 **************************************************************************/
Std_ReturnType Dem_GetEventStatus(Dem_EventIdType EventId,
    Dem_UdsStatusByteType* EventStatusByte)
{
  Std_ReturnType fl_RetVal;
  fl_RetVal = E_NOT_OK;

#if (DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if (Dem_Internal.InitState != DEM_INITIALIZED)
  {
    flError = DEM_DET_UNINITIALIZED;
  }
  else if (EventId >= Dem_Cfg_Num_Of_Event)
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else if (EventId == DEM_EVENT_INVALID)
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else if (EventStatusByte == NULL_PTR)
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else
#endif
  {
    *EventStatusByte = Dem_Cfg_StatusData.EventStatus[EventId];
    fl_RetVal = E_OK;
  }

#if (DemDevErrorDetect == TRUE)
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0, flError);
  }
#endif
  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_GetEventFailed
 Arguments       : Dem_EventIdType EventId, boolean* EventFailed
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Reentrant
 Description     : Gets the event failed status of an event.
 **************************************************************************/
Std_ReturnType Dem_GetEventFailed(Dem_EventIdType EventId, boolean* EventFailed)
{
  Std_ReturnType fl_RetVal;
  fl_RetVal = E_NOT_OK;

#if (DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if (Dem_Internal.InitState != DEM_INITIALIZED)
  {
    flError = DEM_DET_UNINITIALIZED;
  }
  else if (EventId >= Dem_Cfg_Num_Of_Event)
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else if (EventId == DEM_EVENT_INVALID)
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else if (EventFailed == NULL_PTR)
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else
#endif
  {
    *EventFailed = DEM_GET_UDS_STATUS_BYTE_TF(Dem_Cfg_StatusData.EventStatus[EventId]);
    fl_RetVal = E_OK;
  }

#if (DemDevErrorDetect == TRUE)
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0, flError);
  }
#endif

  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_GetEventTested
 Arguments       : Dem_EventIdType EventId, boolean* EventTested
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Reentrant
 Description     : Gets the event tested status of an event.
 **************************************************************************/
Std_ReturnType Dem_GetEventTested(Dem_EventIdType EventId, boolean* EventTested)
{
  Std_ReturnType fl_RetVal;
  fl_RetVal = E_NOT_OK;

#if (DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if (Dem_Internal.InitState != DEM_INITIALIZED)
  {
    flError = DEM_DET_UNINITIALIZED;
  }
  else if (EventId >= Dem_Cfg_Num_Of_Event)
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else if (EventId == DEM_EVENT_INVALID)
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else if (EventTested == NULL_PTR)
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else
#endif
  {
    *EventTested = DEM_GET_UDS_STATUS_BYTE_TNCTMC(
        Dem_Cfg_StatusData.EventStatus[EventId]);
    fl_RetVal = E_OK;
  }

#if (DemDevErrorDetect == TRUE)
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0, flError);
  }
#endif
  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_GetDebouncingOfEvent
 Arguments       : Dem_EventIdType EventId,
 Dem_DebouncingStateType* DebouncingState
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Reentrant
 Description     : Gets the event tested status of an event.
 **************************************************************************/
Std_ReturnType Dem_GetDebouncingOfEvent(Dem_EventIdType EventId,
    Dem_DebouncingStateType* DebouncingState)
{
  Std_ReturnType fl_RetVal;
  fl_RetVal = E_OK;
  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_GetDTCOfEvent
 Arguments       : Dem_EventIdType EventId,
 Dem_DTCFormatType DTCFormat, uint32* DTCOfEvent
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Reentrant
 Description     : Gets the DTC of an event.
 **************************************************************************/
Std_ReturnType Dem_GetDTCOfEvent(Dem_EventIdType EventId, Dem_DTCFormatType DTCFormat,
    uint32* DTCOfEvent)
{
  Std_ReturnType fl_RetVal;
  fl_RetVal = E_NOT_OK;

#if (DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if (Dem_Internal.InitState != DEM_INITIALIZED)
  {
    flError = DEM_DET_UNINITIALIZED;
  }
  else if (EventId >= Dem_Cfg_Num_Of_Event)
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else if (EventId == DEM_EVENT_INVALID)
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else if (DTCFormat >= DEM_DTC_FORMAT_INVALID)
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else if (DTCOfEvent == NULL_PTR)
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else
#endif
  {
    if (DTCFormat == DEM_DTC_FORMAT_UDS)
    {
      *DTCOfEvent = Dem_Cfg_DTC[EventId].Value;
      fl_RetVal = E_OK;
    }
  }

#if (DemDevErrorDetect == TRUE)
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
#endif
  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_SetEnableCondition
 Arguments       : uint8 EnableConditionID, boolean ConditionFulfilled
 Return type     : Std_ReturnType
 Sync/Async      : Asynchronous
 Reentrancy      : Reentrant
 Description     : Std_ReturnType
 **************************************************************************/
Std_ReturnType Dem_SetEnableCondition(uint8 EnableConditionID, boolean ConditionFulfilled)
{
  Std_ReturnType fl_RetVal;
  fl_RetVal = E_NOT_OK;

#if (DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if (Dem_Internal.InitState != DEM_INITIALIZED)
  {
    flError = DEM_DET_UNINITIALIZED;
  }
  else if (EnableConditionID >= Dem_Cfg_Num_Of_EnCon)
  {
    flError = DEM_DET_INVALID_PARAMETER;

  }
  else
#endif
  {
    Dem_Event.EnableConditionQueue[EnableConditionID] = ConditionFulfilled;
    DEM_SET_BIT_STATE(Dem_Event.EnStrConditionFlag, DEM_EVENT_ENABLE_CONDITION_REQUESTED);
    fl_RetVal = E_OK;
  }

#if (DemDevErrorDetect == TRUE)
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
#endif
  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_SetStorageCondition
 Arguments       : uint8 StorageConditionID, boolean ConditionFulfilled
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Reentrant
 Description     : Sets a storage condition.
 **************************************************************************/
Std_ReturnType Dem_SetStorageCondition(uint8 StorageConditionID,
    boolean ConditionFulfilled)
{
  Std_ReturnType fl_RetVal;
  fl_RetVal = E_NOT_OK;

#if (DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if (Dem_Internal.InitState != DEM_INITIALIZED)
  {
    flError = DEM_DET_UNINITIALIZED;
  }
  else if (StorageConditionID >= Dem_Cfg_Num_Of_StrCon)
  {
    flError = DEM_DET_INVALID_PARAMETER;

  }
  else
#endif
  {
    Dem_Event.StorageConditionQueue[StorageConditionID] = ConditionFulfilled;
    DEM_SET_BIT_STATE(Dem_Event.EnStrConditionFlag,
        DEM_EVENT_STORAGE_CONDITION_REQUESTED);
    fl_RetVal = E_OK;
  }

#if (DemDevErrorDetect == TRUE)
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
#endif
  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_GetFaultDetectionCounter
 Arguments       : Dem_EventIdType EventId, sint8* FaultDetectionCounter
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant
 Description     : Gets the fault detection counter of an event. This API can
 only be used through the RTE, and therefore no declaration
 is exported via Dem.h.
 **************************************************************************/
Std_ReturnType Dem_GetFaultDetectionCounter(Dem_EventIdType EventId,
    sint8* FaultDetectionCounter)
{
  Std_ReturnType fl_RetVal;
  fl_RetVal = E_OK;
  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_GetIndicatorStatus
 Arguments       : uint8 IndicatorId, Dem_IndicatorStatusType* IndicatorStatus
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant
 Description     : Gets the indicator status derived from the event status.
 **************************************************************************/
Std_ReturnType Dem_GetIndicatorStatus(uint8 IndicatorId,
    Dem_IndicatorStatusType* IndicatorStatus)
{
  Std_ReturnType fl_RetVal;
  fl_RetVal = E_OK;
  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_SetIndicatorStatus
 Arguments       : uint8 IndicatorId, Dem_IndicatorStatusType* IndicatorStatus
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant
 Description     : Sets the indicator status included in the event status.
 API will only exist in a Master ECU a software component if
 the MIL Master functionality is solved within the Dem of the
 Master ECU.
 **************************************************************************/
Std_ReturnType Dem_SetIndicatorStatus(uint8 IndicatorId,
    Dem_IndicatorStatusType* IndicatorStatus)
{
  Std_ReturnType fl_RetVal;
  fl_RetVal = E_OK;
  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_GetEventFreezeFrameData
 Arguments       : Dem_EventIdType EventId, uint8 RecordNumber,
 boolean ReportTotalRecord, uint16 DataId,uint8* DestBuffer
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Reentrant
 Description     : Gets the data of a freeze frame by event.
 **************************************************************************/
Std_ReturnType Dem_GetEventFreezeFrameData(Dem_EventIdType EventId, uint8 RecordNumber,
    boolean ReportTotalRecord, uint16 DataId, uint8* DestBuffer)
{
  Std_ReturnType fl_RetVal;
  fl_RetVal = E_OK;
  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_GetEventExtendedDataRecord
 Arguments       : Dem_EventIdType EventId, uint8 RecordNumber, uint8* DestBuffer
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Reentrant
 Description     : Gets the data of an extended data record by event.
 **************************************************************************/
Std_ReturnType Dem_GetEventExtendedDataRecord(Dem_EventIdType EventId, uint8 RecordNumber,
    uint8* DestBuffer)
{
  Std_ReturnType fl_RetVal;
  fl_RetVal = E_OK;
  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_GetEventMemoryOverflow
 Arguments       : Dem_DTCOriginType DTCOrigin, boolean* OverflowIndication
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Reentrant
 Description     : Gets the event memory overflow indication status.
 **************************************************************************/
Std_ReturnType Dem_GetEventMemoryOverflow(Dem_DTCOriginType DTCOrigin,
    boolean* OverflowIndication)
{
  Std_ReturnType fl_RetVal;
  fl_RetVal = E_OK;
  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_GetNumberOfEventMemoryEntries
 Arguments       : Dem_DTCOriginType DTCOrigin, uint8* NumberOfEventMemoryEntries
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Reentrant
 Description     : Returns the number of entries currently stored in the
 requested event memory.
 **************************************************************************/
Std_ReturnType Dem_GetNumberOfEventMemoryEntries(Dem_DTCOriginType DTCOrigin,
    uint8* NumberOfEventMemoryEntries)
{
  Std_ReturnType fl_RetVal;
  fl_RetVal = E_OK;
  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_SetComponentAvailable
 Arguments       : Dem_ComponentIdType ComponentId, boolean AvailableStatus
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant
 Description     : Set the availability of a specific DemComponent.
 **************************************************************************/
Std_ReturnType Dem_SetComponentAvailable(Dem_ComponentIdType ComponentId,
    boolean AvailableStatus)
{
  Std_ReturnType fl_RetVal;
  fl_RetVal = E_OK;
  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_SetDTCSuppression
 Arguments       : uint32 DTC, Dem_DTCFormatType DTCFormat,
 boolean SuppressionStatus
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant
 Description     : Set the suppression status of a specific DTC.
 **************************************************************************/
Std_ReturnType Dem_SetDTCSuppression(uint32 DTC, Dem_DTCFormatType DTCFormat,
    boolean SuppressionStatus)
{
  Std_ReturnType fl_RetVal;
  fl_RetVal = E_OK;
  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_ClearDTC
 Arguments       : uint32 DTC, Dem_DTCFormatType DTCFormat,
 Dem_DTCOriginType DTCOrigin
 Return type     : Dem_ReturnClearDTCType
 Sync/Async      : Asynchronous
 Reentrancy      : Reentrant
 Description     : Clears single DTCs, as well as groups of DTCs. This
 API is intended for complex device driver. It can only be
 used through the RTE (due to work-around described below
 SWS_Dem_00659), and therefore no declaration is exported
 via Dem.h.
 **************************************************************************/
Dem_ReturnClearDTCType Dem_ClearDTC(uint32 DTC, Dem_DTCFormatType DTCFormat, Dem_DTCOriginType DTCOrigin)
{
  Dem_ReturnClearDTCType fl_RetVal;
  fl_RetVal = DEM_CLEAR_FAILED;

#if (DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if (Dem_Internal.InitState != DEM_INITIALIZED)
  {
    flError = DEM_DET_UNINITIALIZED;
    fl_RetVal = DEM_CLEAR_FAILED;
  }
  else if (DTCFormat >= DEM_DTC_FORMAT_INVALID)
  {
    flError = DEM_DET_INVALID_PARAMETER;
    fl_RetVal = DEM_CLEAR_WRONG_DTC;
  }
  else if (DEM_DTC_ORIGIN_PRIMARY_MEMORY != DTCOrigin)
  {
    flError = DEM_DET_INVALID_PARAMETER;
    fl_RetVal = DEM_CLEAR_WRONG_DTCORIGIN;
  }
  else
#endif
  {
    if (DTCFormat == DEM_DTC_FORMAT_UDS)
    {
      fl_RetVal = Dem_ClearDTCInternal(DTC, DTCFormat, DTCOrigin);
    }
  }

#if (DemDevErrorDetect == TRUE)
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0, flError);
  }
#endif
  return fl_RetVal;
}

/*** Interface Dcm <=> Dem ***/

/**************************************************************************
 Function name   : Dem_DcmGetTranslationType
 Arguments       : void
 Return type     : Dem_DTCTranslationFormatType
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant
 Description     : Gets the supported DTC formats of the ECU.
 The supported formats are configured via DemTypeOfDTCSupported.
 **************************************************************************/
Dem_DTCTranslationFormatType Dem_DcmGetTranslationType(void)
{
  Dem_DTCTranslationFormatType fl_RetVal;
  fl_RetVal = DEM_DTC_TRANSLATION_ISO14229_1;
  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_DcmGetDTCStatusAvailabilityMask
 Arguments       : Dem_UdsStatusByteType* DTCStatusMask
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant
 Description     : Gets the DTC Status availability mask.
 **************************************************************************/
Std_ReturnType Dem_DcmGetDTCStatusAvailabilityMask(Dem_UdsStatusByteType * DTCStatusMask)
{
  Std_ReturnType fl_RetVal;
  fl_RetVal = E_NOT_OK;

#if (DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if (Dem_Internal.InitState != DEM_INITIALIZED)
  {
    flError = DEM_DET_UNINITIALIZED;
  }
  else if (DTCStatusMask == NULL_PTR)
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else
#endif
  {
    *DTCStatusMask = DemDtcStatusAvailabilityMask;
    fl_RetVal = E_OK;
  }

#if (DemDevErrorDetect == TRUE)
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
#endif

  return fl_RetVal;
}

static Dem_EventIdType Dem_InternalGetEventIdByDTCValue(uint32 DTC)
{
  Dem_EventIdType flRetVal;
  Dem_EventIdType flEventId;
  uint8 flDtcRef;

  flRetVal = DEM_EVENT_INVALID;
  if (DTC != DEM_DTC_INVALID)
  {
    for (flDtcRef = DEM_DTC_VALID_START; flDtcRef < Dem_Cfg_Num_Of_DTC; flDtcRef++)
    {
      if (Dem_Cfg_DTC[flDtcRef].Value == DTC)
      {
        for (flEventId = DEM_EVENT_VALID_ID_START; flEventId < Dem_Cfg_Num_Of_Event;
            flEventId++)
        {
          if (flDtcRef == Dem_Cfg_EventParameter[flEventId].DTCTableRef)
          {
            flRetVal = flEventId;
            break;
          }
        }
        break;
      }
    }
  }
  return flRetVal;
}

/**************************************************************************
 Function name   : Dem_DcmGetStatusOfDTC
 Arguments       : uint32 DTC, Dem_DTCOriginType DTCOrigin, uint8* DTCStatus
 Return type     : Dem_ReturnGetStatusOfDTCType
 Sync/Async      : Synchronous or Asynchronous
 Reentrancy      : Non Reentrant
 Description     : Gets the status of a DTC.
 For large configurations and DTC-calibration, the interface
 behavior can be asynchronous
 **************************************************************************/
Dem_ReturnGetStatusOfDTCType Dem_DcmGetStatusOfDTC(uint32 DTC,
    Dem_DTCOriginType DTCOrigin, uint8* DTCStatus)
{
  Dem_ReturnGetStatusOfDTCType fl_RetVal;
  Dem_EventIdType flEventId;

#if (DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if (Dem_Internal.InitState != DEM_INITIALIZED)
  {
    flError = DEM_DET_UNINITIALIZED;
    fl_RetVal = DEM_STATUS_FAILED;
  }
  else if ((0x00U == DTCOrigin) || (DEM_DTC_ORIGIN_INVALID <= DTCOrigin))
  {
    flError = DEM_DET_INVALID_PARAMETER;
    fl_RetVal = DEM_STATUS_WRONG_DTCORIGIN;
  }
  else if (DTCStatus == NULL_PTR)
  {
    flError = DEM_DET_INVALID_PARAMETER;
    fl_RetVal = DEM_STATUS_FAILED;
  }
  else
#endif
  {
    fl_RetVal = DEM_STATUS_WRONG_DTCORIGIN;
    if (DTCOrigin == DEM_DTC_ORIGIN_PRIMARY_MEMORY)
    {
      flEventId = Dem_InternalGetEventIdByDTCValue(DTC);

      fl_RetVal = DEM_STATUS_WRONG_DTC;
      if (flEventId != DEM_EVENT_INVALID)
      {
        *DTCStatus = (Dem_Cfg_StatusData.EventStatus[flEventId]
            & DemDtcStatusAvailabilityMask);
      }
    }
  }

#if (DemDevErrorDetect == TRUE)
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
#endif
  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_DcmGetSeverityOfDTC
 Arguments       : uint32 DTC, Dem_DTCSeverityType* DTCSeverity
 Return type     : Dem_ReturnGetSeverityOfDTCType
 Sync/Async      : Synchronous or Asynchronous
 Reentrancy      : Non Reentrant
 Description     : Gets the severity of the requested DTC.
 For large configurations and DTC-calibration, the interface
 behavior can be asynchronous.
 **************************************************************************/
Dem_ReturnGetSeverityOfDTCType Dem_DcmGetSeverityOfDTC(uint32 DTC,
    Dem_DTCSeverityType* DTCSeverity)
{
  Dem_ReturnGetSeverityOfDTCType fl_RetVal;
  fl_RetVal = DEM_GET_SEVERITYOFDTC_OK;
  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_DcmGetFunctionalUnitOfDTC
 Arguments       : uint32 DTC, uint8* DTCFunctionalUnit
 Return type     : Dem_ReturnGetFunctionalUnitOfDTCType
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant
 Description     : Gets the functional unit of the requested DTC.
 **************************************************************************/
Dem_ReturnGetFunctionalUnitOfDTCType Dem_DcmGetFunctionalUnitOfDTC(uint32 DTC,
    uint8* DTCFunctionalUnit)
{
  Dem_ReturnGetFunctionalUnitOfDTCType fl_RetVal;
  fl_RetVal = DEM_GET_FUNCTIONALUNITOFDTC_OK;
  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_DcmSetDTCFilter
 Arguments       : Dem_UdsStatusByteType DTCStatusMask, Dem_DTCKindType DTCKind,
 Dem_DTCFormatType DTCFormat, Dem_DTCOriginType DTCOrigin,
 boolean FilterWithSeverity,
 Dem_DTCSeverityType DTCSeverityMask,
 boolean FilterForFaultDetectionCounter
 Return type     : Dem_ReturnSetFilterType
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant
 Description     : Sets the DTC Filter.
 The server shall perform a bit-wise logical AND-ing operation
 between the parameter DTCStatusMask and the current DTC status in the
 server. In addition to the DTCStatusAvailabilityMask, the server
 shall return all DTCs for which the result of the AND-ing
 operation is non-zero [i.e. (statusOfDTC & DTCStatusMask)
 != 0]. The server shall process only the DTC Status bits that
 it is supporting.
 OBD Events Suppression shall be ignored for this computation.
 If no DTCs within the server match the masking criteria
 specified in the client?s request, no DTC or status
 information shall be provided following the DTCStatusAvailabilityMask
 byte in the positive response message
 (((statusOfDTC & DTCStatusMask) != 0) && ((severity
 & DTCSeverityMask) != 0)) == TRUE
 **************************************************************************/
Dem_ReturnSetFilterType Dem_DcmSetDTCFilter(Dem_UdsStatusByteType DTCStatusMask,
    Dem_DTCKindType DTCKind, Dem_DTCFormatType DTCFormat, Dem_DTCOriginType DTCOrigin,
    boolean FilterWithSeverity, Dem_DTCSeverityType DTCSeverityMask,
    boolean FilterForFaultDetectionCounter)
{
  Dem_ReturnSetFilterType fl_RetVal;
  fl_RetVal = DEM_WRONG_FILTER;

#if (DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if (Dem_Internal.InitState != DEM_INITIALIZED)
  {
    flError = DEM_DET_UNINITIALIZED;
  }
  else if (DEM_DTC_KIND_INVALID <= DTCKind)
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else if (DTCFormat >= DEM_DTC_FORMAT_INVALID)
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else if ((0x00U == DTCOrigin) || (DEM_DTC_ORIGIN_INVALID <= DTCOrigin))
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else
#endif
  {
    (void) (FilterWithSeverity);
    (void) (DTCSeverityMask);
    (void) (FilterForFaultDetectionCounter);

    if((DTCKind == DEM_DTC_KIND_ALL_DTCS) && (DTCFormat == DEM_DTC_FORMAT_UDS) && 
       (DTCOrigin == DEM_DTC_ORIGIN_PRIMARY_MEMORY))
    {
      if (DTCStatusMask == 0x00U)
      {
        Dem_FilterInfo.Dtc_StatusMask = DemDtcStatusAvailabilityMask; // ALL filter for mzhao6
        DEM_DCM_SET_USESTATUSMASK_FLAG(Dem_FilterInfo.Req_Status);
        Dem_FilterInfo.EventIndex = DEM_EVENT_VALID_ID_START;
      }
      else
      {
        Dem_FilterInfo.Dtc_StatusMask = (DTCStatusMask & DemDtcStatusAvailabilityMask);
        DEM_DCM_SET_USESTATUSMASK_FLAG(Dem_FilterInfo.Req_Status);
        Dem_FilterInfo.EventIndex = DEM_EVENT_VALID_ID_START;
      }
      fl_RetVal = DEM_FILTER_ACCEPTED;
    }
  }

#if (DemDevErrorDetect == TRUE)
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0, flError);
  }
#endif
  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_DcmGetNumberOfFilteredDTC
 Arguments       : uint16* NumberOfFilteredDTC
 Return type     : Dem_ReturnGetNumberOfFilteredDTCType
 Sync/Async      : Asynchronous
 Reentrancy      : Non Reentrant
 Description     : Gets the number of a filtered DTC.
 **************************************************************************/
Dem_ReturnGetNumberOfFilteredDTCType Dem_DcmGetNumberOfFilteredDTC(uint16 * NumberOfFilteredDTC)
{
  Dem_ReturnGetNumberOfFilteredDTCType fl_RetVal;
  uint16 flNumberofFilteredDtc;
  Dem_EventIdType flEventId;

  fl_RetVal = DEM_NUMBER_FAILED;
  flNumberofFilteredDtc = 0x00U;

#if (DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if (Dem_Internal.InitState != DEM_INITIALIZED)
  {
    flError = DEM_DET_UNINITIALIZED;
  }
  else if (NumberOfFilteredDTC == NULL_PTR)
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else
#endif
  {
    for (flEventId = DEM_EVENT_VALID_ID_START; flEventId < Dem_Cfg_Num_Of_Event; flEventId++)
    {
      if (Dem_Cfg_StatusData.EventStatus[flEventId] & Dem_FilterInfo.Dtc_StatusMask)
      {
        flNumberofFilteredDtc++;
      }
    }
    *NumberOfFilteredDTC = flNumberofFilteredDtc;
    fl_RetVal = DEM_NUMBER_OK;
  }

#if (DemDevErrorDetect == TRUE)
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
#endif

  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_DcmGetNextFilteredDTC
 Arguments       : uint32* DTC, Dem_UdsStatusByteType* DTCStatus
 Return type     : Dem_ReturnGetNextFilteredElementType
 Sync/Async      : Synchronous or Asynchronous
 Reentrancy      : Non Reentrant
 Description     : Gets the next filtered DTC matching the filter criteria. For
 UDS services, the interface has an asynchronous behavior,
 because a large number of DTCs has to be processed.
 **************************************************************************/
Dem_ReturnGetNextFilteredElementType Dem_DcmGetNextFilteredDTC(uint32 * DTC,
    Dem_UdsStatusByteType * DTCStatus)
{
  Dem_ReturnGetNextFilteredElementType fl_RetVal;
  uint8 flDtcTableRef;
  fl_RetVal = DEM_FILTERED_NO_MATCHING_ELEMENT;

#if (DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if (Dem_Internal.InitState != DEM_INITIALIZED)
  {
    flError = DEM_DET_UNINITIALIZED;
  }
  else if (DTC == NULL_PTR)
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else if (DTCStatus == NULL_PTR)
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else
#endif
  {
    while (Dem_FilterInfo.EventIndex < Dem_Cfg_Num_Of_Event)
    {
      if (DEM_DCM_GET_USESTATUSMASK_FLAG(Dem_FilterInfo.Req_Status))
      {
        /* DTC uses filter */
        if (FALSE != (Dem_Cfg_StatusData.EventStatus[Dem_FilterInfo.EventIndex] & Dem_FilterInfo.Dtc_StatusMask))
        {
          flDtcTableRef = Dem_Cfg_EventParameter[Dem_FilterInfo.EventIndex].DTCTableRef;
          *DTC = Dem_Cfg_DTC[flDtcTableRef].Value;
          *DTCStatus = (Dem_Cfg_StatusData.EventStatus[Dem_FilterInfo.EventIndex] & DemDtcStatusAvailabilityMask);
          fl_RetVal = DEM_FILTERED_OK;
        }
      }
      else
      {
        flDtcTableRef = Dem_Cfg_EventParameter[Dem_FilterInfo.EventIndex].DTCTableRef;
        *DTC = Dem_Cfg_DTC[flDtcTableRef].Value;
        *DTCStatus = (Dem_Cfg_StatusData.EventStatus[Dem_FilterInfo.EventIndex] & DemDtcStatusAvailabilityMask);
        fl_RetVal = DEM_FILTERED_OK;
      }

      Dem_FilterInfo.EventIndex++;

      if (fl_RetVal == DEM_FILTERED_OK)
      {
        break;
      }
    }
  }

#if (DemDevErrorDetect == TRUE)
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
#endif
  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_DcmGetNextFilteredDTCAndFDC
 Arguments       : uint32* DTC, sint8* DTCFaultDetectionCounter
 Return type     : Dem_ReturnGetNextFilteredElementType
 Sync/Async      : Asynchronous
 Reentrancy      : Non Reentrant
 Description     : Gets the next filtered DTC and its associated Fault Detection
 Counter (FDC) matching the filter criteria. The interface
 has an asynchronous behavior, because a large number of
 DTCs has to be processed and the FDC might be received
 asynchronously from a SW-C, too.
 **************************************************************************/
Dem_ReturnGetNextFilteredElementType Dem_DcmGetNextFilteredDTCAndFDC(uint32 * DTC,
    sint8 * DTCFaultDetectionCounter)
{
  Dem_ReturnGetNextFilteredElementType fl_RetVal;
  fl_RetVal = DEM_FILTERED_OK;
  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_DcmGetNextFilteredDTCAndSeverity
 Arguments       : uint32* DTC, Dem_UdsStatusByteType* DTCStatus,
 Dem_DTCSeverityType* DTCSeverity, uint8* DTCFunctionalUnit
 Return type     : Dem_ReturnGetNextFilteredElementType
 Sync/Async      : Asynchronous
 Reentrancy      : Non Reentrant
 Description     : Gets the next filtered DTC and its associated Severity
 matching the filter criteria. The interface has an asynchronous
 behavior, because a large number of DTCs has to be processed.
 **************************************************************************/
Dem_ReturnGetNextFilteredElementType Dem_DcmGetNextFilteredDTCAndSeverity(uint32 * DTC,
    Dem_UdsStatusByteType * DTCStatus, Dem_DTCSeverityType * DTCSeverity,
    uint8 * DTCFunctionalUnit)
{
  Dem_ReturnGetNextFilteredElementType fl_RetVal;
  fl_RetVal = DEM_FILTERED_OK;
  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_DcmSetFreezeFrameRecordFilter
 Arguments       : Dem_DTCFormatType DTCFormat, uint16* NumberOfFilteredRecords
 Return type     : Dem_ReturnSetFilterType
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant
 Description     : Sets a freeze frame record filter.
 **************************************************************************/
Dem_ReturnSetFilterType Dem_DcmSetFreezeFrameRecordFilter(Dem_DTCFormatType DTCFormat,
    uint16* NumberOfFilteredRecords)
{
  Dem_ReturnSetFilterType fl_RetVal;
  fl_RetVal = DEM_FILTER_ACCEPTED;
  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_DcmGetNextFilteredRecord
 Arguments       : uint32* DTC, uint8* RecordNumber
 Return type     : Dem_ReturnGetNextFilteredElementType
 Sync/Async      : Asynchronous
 Reentrancy      : Non Reentrant
 Description     : Gets the next freeze frame record number and its associated
 DTC stored in the event memory. The interface has an
 asynchronous behavior, because NvRAM access might be
 required.
 **************************************************************************/
Dem_ReturnGetNextFilteredElementType Dem_DcmGetNextFilteredRecord(uint32 * DTC,
    uint8 * RecordNumber)
{
  Dem_ReturnGetNextFilteredElementType fl_RetVal;
  fl_RetVal = DEM_FILTERED_OK;
  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_DcmGetDTCByOccurrenceTime
 Arguments       : Dem_DTCRequestType DTCRequest, uint32* DTC
 Return type     : Dem_ReturnGetDTCByOccurrenceTimeType
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant
 Description     : Gets the DTC by occurrence time. There is no explicit
 parameter for the DTC-origin as the origin always is
 DEM_DTC_ORIGIN_PRIMARY_MEMORY.
 **************************************************************************/
Dem_ReturnGetDTCByOccurrenceTimeType Dem_DcmGetDTCByOccurrenceTime(
    Dem_DTCRequestType DTCRequest, uint32* DTC)
{
  Dem_ReturnGetDTCByOccurrenceTimeType fl_RetVal;
  Dem_EventIdType flEventId;
  fl_RetVal = DEM_OCCURR_NOT_AVAILABLE;

#if (DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if (Dem_Internal.InitState != DEM_INITIALIZED)
  {
    flError = DEM_DET_UNINITIALIZED;
  }
  else if (DTCRequest > DEM_MOST_REC_DET_CONFIRMED_DTC)
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else if (NULL_PTR == DTC)
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else
#endif
  {
    flEventId = DEM_EVENT_INVALID;

    switch (DTCRequest)
    {
    case DEM_FIRST_FAILED_DTC:
      flEventId = Dem_Cfg_StatusData.FirstFailedEvent;
      break;
    case DEM_MOST_RECENT_FAILED_DTC:
      flEventId = Dem_Cfg_StatusData.RecentFailedEvent;
      break;
    case DEM_FIRST_DET_CONFIRMED_DTC:
      flEventId = Dem_Cfg_StatusData.FirstConfirmedEvent;
      break;
    case DEM_MOST_REC_DET_CONFIRMED_DTC:
      flEventId = Dem_Cfg_StatusData.RecentConfirmedEvent;
      break;
    default:
      break;
    }

    if (flEventId != DEM_EVENT_INVALID)
    {
      *DTC = Dem_Cfg_DTC[Dem_Cfg_EventParameter[flEventId].DTCTableRef].Value;
      fl_RetVal = DEM_OCCURR_OK;
    }

  }

#if (DemDevErrorDetect == TRUE)
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
#endif
  return fl_RetVal;
}
	
#ifdef DTC_Snapshot

/**************************************************************************
 Function name   : Dem_DcmControlDTCStatusChangedNotification
 Arguments       : boolean TriggerNotification
 Return type     : void
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant
 Description     : Controls the triggering of Dcm_DemTriggerOnDTCStatus.
 **************************************************************************/
Std_ReturnType Dem_DcmGetNumberOfDtcID(uint32 dtcid,uint8* dtcnumber)
{
	uint8 fl_loop_count_u8 = 0;
	uint8 fl_RetVal = DEM_OCCURR_NOT_AVAILABLE;

	for(fl_loop_count_u8 = DEM_EVENT_VALID_ID_START; fl_loop_count_u8 < DTC_SNAPSHOT_ID_VALUE; fl_loop_count_u8 ++)
	{
		if(dtcid == Dem_Cfg_DTC[fl_loop_count_u8].Value)
		{
			if(Dem_Cfg_StatusData.EventStatus[fl_loop_count_u8] & DemDtcStatusAvailabilityMask)
			{
				fl_RetVal = DEM_OCCURR_OK;
				*dtcnumber = Dem_Cfg_DTC[fl_loop_count_u8].AttrbsRef;
				break;
			}
		}
	}

	return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_DcmControlDTCStatusChangedNotification
 Arguments       : boolean TriggerNotification
 Return type     : void
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant
 Description     : Controls the triggering of Dcm_DemTriggerOnDTCStatus.
 **************************************************************************/
Std_ReturnType Dem_DcmGetSnapshotDataOfDtcID(uint8 dtcnumber,uint8 snapshotdef,uint8* dtcdata)
{
	uint8 fl_RetVal = DEM_OCCURR_NOT_AVAILABLE;
	uint32 fl_dtc_id = Dem_Cfg_DTC[dtcnumber].Value;
	Dem_Cfg_PrimaryMemEntryType *flEntry;
	flEntry = (Dem_Cfg_PrimaryMemEntryType*)Dem_Cfg_MemPtr[dtcnumber];
	
	/* Qiuhuaqing Modify,  To be Release after NVM Finished */
	fl_RetVal = NvM_ReadBlock(Dem_Cfg_Memory_BlockId[dtcnumber],flEntry);

	if(fl_RetVal == E_OK)
	{
		dtcdata[0] = (uint8)(fl_dtc_id >> 16);
		dtcdata[1] = (uint8)(fl_dtc_id >> 8);
		dtcdata[2] = (uint8)(fl_dtc_id);
		dtcdata[3] = (uint8)(Dem_Cfg_StatusData.EventStatus[dtcnumber] & DemDtcStatusAvailabilityMask);
		dtcdata[4] = (uint8)(snapshotdef);
		dtcdata[5] = 0x06;
		dtcdata[6] = 0x0b;
		dtcdata[7] = 0x00;
		dtcdata[8] = flEntry->ignst;
		dtcdata[9] = 0x0b;
		dtcdata[10] = 0x01;
		dtcdata[11] = flEntry->batt_volt;
		dtcdata[12] = 0x0b;
		dtcdata[13] = 0x02;
		dtcdata[14] = flEntry->odo_value >> 16;
		dtcdata[15] = flEntry->odo_value >> 8;
		dtcdata[16] = flEntry->odo_value;
		dtcdata[17] = 0x0b;
		dtcdata[18] = 0x03;
		dtcdata[19] = flEntry->speed_value >> 8;
		dtcdata[20] = flEntry->speed_value;
		dtcdata[21] = 0x0b;
		dtcdata[22] = 0x04;
		dtcdata[23] = flEntry->time_year;
		dtcdata[24] = flEntry->time_month;
		dtcdata[25] = flEntry->time_day;
		dtcdata[26] = flEntry->time_hour;
		dtcdata[27] = flEntry->time_minute;
		dtcdata[28] = flEntry->time_second;
		dtcdata[29] = 0x0b;
		dtcdata[30] = 0x05;
		dtcdata[31] = flEntry->tach_speed >> 8;
		dtcdata[32] = flEntry->tach_speed;
		
	}

	
	return fl_RetVal;
}

static void Dem_MainFunctionProcessSnapShot(void)
{
	if(l_dem_snapshot_write_count_100ms_u8 >= 10)
	{
		//Dem_Snapshot_Write_Nvm_Process();
		Dem_ProcessIGNEvent();
		l_dem_snapshot_write_count_100ms_u8 = 0;
	}
	else 
	{
		l_dem_snapshot_write_count_100ms_u8 ++;
	}
}



static void Dem_Get_SnapShot(Dem_Cfg_PrimaryMemEntryType* Entry)
{
    uint8 flMemIndex = DEM_EVENT_VALID_ID_START;
	uint16 flBlockId = DEM_EVENT_VALID_ID_START;
    uint8 fl_Speed_Status = RTE_E_NEVER_RECEIVED;
    uint8 fl_EngSpd_Status = RTE_E_NEVER_RECEIVED;
    uint16 fl_Speed_Value_u16 = 0;
    uint16 fl_EngSpd_Value_u16 = 0;
    uint8 fl_Voltage_u8 = 0;
    uint32 fl_Odo_u32 = 0;

	Dem_Cfg_PrimaryMemEntryType flEntry;

    // get signal status
    Rte_Read_Speed(&fl_Speed_Status, &fl_Speed_Value_u16);
    Rte_Read_EngSpd(&fl_EngSpd_Status, &fl_EngSpd_Value_u16);
    Rte_Read_Voltage(&fl_Voltage_u8);
    Rte_Read_ODO(&fl_Odo_u32);

    if(RTE_E_NEVER_RECEIVED == fl_Speed_Status || RTE_E_TIMEOUT == fl_Speed_Status)
	{
		flEntry.speed_value = fl_Speed_Value_u16;
	}
    else
    {
        flEntry.speed_value = l_Prev_Valid_Entry_S.speed_value;
    }

    if(RTE_E_NEVER_RECEIVED == fl_EngSpd_Status || RTE_E_TIMEOUT == fl_EngSpd_Status)
	{
		fl_EngSpd_Status = fl_EngSpd_Value_u16;
	}
    else
    {
        flEntry.tach_speed = l_Prev_Valid_Entry_S.tach_speed;
    }

    flEntry.batt_volt   = fl_Voltage_u8;
    flEntry.odo_value   = fl_Odo_u32;
    flEntry.time_year   = l_time_year_pre_u8;
    flEntry.time_month  = l_time_month_pre_u8;
    flEntry.time_day    = l_time_day_pre_u8;
    flEntry.time_hour   = l_time_hour_pre_u8;
    flEntry.time_minute = l_time_second_pre_u8;
    flEntry.time_second = l_time_minute_pre_u8;

    *Entry = flEntry;
}

static void Dem_Snapshot_Write_Nvm_Process(void)
{
	uint8 flMemIndex = DEM_EVENT_VALID_ID_START;
	uint16 flBlockId = DEM_EVENT_VALID_ID_START;
	Dem_Cfg_PrimaryMemEntryType *flEntry;
	flEntry = (Dem_Cfg_PrimaryMemEntryType*) Dem_Cfg_MemPtr[flMemIndex];
	uint8 fl_ignst_u8 = 0;
	uint8 fl_battstate_u8 = 0;
	uint32 fl_odo_value_u32 = 0;
	uint16 fl_speed_value_u16 = 0;
	uint8  fl_time_year_u8 = 0;
	uint8  fl_time_year_cal_u8 = 0;
	uint8  fl_time_month_u8 = 0;
	uint8  fl_time_day_u8 = 0;
	uint8  fl_time_hour_u8 = 0;
	uint8  fl_time_second_u8 = 0;
	uint8  fl_time_minute_u8 = 0;
	uint16 fl_tach_value_u16 = 0;
	Std_ReturnType flReturnVal = E_NOT_OK;
	uint8 fl_esc2_msg_nr_u8 = 0;
	uint8 fl_esc2_msg_tout_u8 = 0;
	uint8 fl_ems3_msg_nr_u8 = 0;
	uint8 fl_ems3_msg_tout_u8 = 0;
	uint8 fl_mp5time_msg_nr_u8 = 0;
	uint8 fl_mp5time_msg_tout_u8 = 0;


  /* Qiuhuaqing Modify,  To be Release after Com Finished */
	// Rte_Read_TIModMdlIgnState_IGNState(&fl_ignst_u8);
	// Rte_Call_tiCS_TIIoHwAb_AIn_Impl_GetVoltage(eIOVoltageInId_MAI_BAT ,&fl_battstate_u8);
	// Rte_Read_rpSR_OdoOutKiloMeters_KiloMeters(&fl_odo_value_u32);
	// Rte_Read_rpSR_CANMSG_GW_ESC2_ESC_VehSpd(&fl_speed_value_u16);
	// Rte_Read_rpSR_CANMSG_MP5_Time_MP5_TBOX_Time_Year(&fl_time_year_u8);
	// Rte_Read_rpSR_CANMSG_MP5_Time_MP5_TBOX_Time_Month(&fl_time_month_u8);
	// Rte_Read_rpSR_CANMSG_MP5_Time_MP5_TBOX_Time_Date(&fl_time_day_u8);
	// Rte_Read_rpSR_CANMSG_MP5_Time_MP5_TBOX_Time_Hour(&fl_time_hour_u8);
	// Rte_Read_rpSR_CANMSG_MP5_Time_MP5_TBOX_Time_Second(&fl_time_second_u8);
	// Rte_Read_rpSR_CANMSG_MP5_Time_MP5_TBOX_Time_Minute(&fl_time_minute_u8);
	// Rte_Read_rpSR_CANMSG_GW_EMS3_EMS_EngFilterSpd(&fl_tach_value_u16);
	// Rte_Read_rpSR_CANMSG_GW_ESC2_NR(&fl_esc2_msg_nr_u8);
	// Rte_Read_rpSR_CANMSG_GW_ESC2_Tout(&fl_esc2_msg_tout_u8);
	// Rte_Read_rpSR_CANMSG_GW_EMS3_NR(&fl_ems3_msg_nr_u8);
	// Rte_Read_rpSR_CANMSG_GW_EMS3_Tout(&fl_ems3_msg_tout_u8);
	// Rte_Read_rpSR_CANMSG_MP5_Time_NR(&fl_mp5time_msg_nr_u8);
	// Rte_Read_rpSR_CANMSG_MP5_Time_Tout(&fl_mp5time_msg_tout_u8);

	if(RTE_E_NEVER_RECEIVED == fl_esc2_msg_nr_u8 || RTE_E_TIMEOUT == fl_esc2_msg_tout_u8)
	{
		fl_speed_value_u16 = l_speed_value_pre_u16;
	}

    if(RTE_E_NEVER_RECEIVED == fl_ems3_msg_nr_u8 || RTE_E_TIMEOUT == fl_ems3_msg_tout_u8)
	{
		fl_tach_value_u16 = l_tach_value_pre_u16;
	}

	if(RTE_E_NEVER_RECEIVED == fl_mp5time_msg_nr_u8 || RTE_E_TIMEOUT == fl_mp5time_msg_tout_u8)
	{
		fl_time_year_u8   = l_time_year_pre_u8;
		fl_time_month_u8  = l_time_month_pre_u8;
		fl_time_day_u8    = l_time_day_pre_u8;
		fl_time_hour_u8   = l_time_hour_pre_u8;
		fl_time_second_u8 = l_time_second_pre_u8;
		fl_time_minute_u8 = l_time_minute_pre_u8;	
	}
	
	if(fl_ignst_u8 == eIGN_OFF)
	{
		fl_ignst_u8 = 0;
	}
	fl_battstate_u8 = fl_battstate_u8 / 10;
	fl_odo_value_u32 = fl_odo_value_u32 / 100;
	fl_time_year_cal_u8 = fl_time_year_u8 + 18;
		
	if (DEM_DTC_STORAGE_SETTING_DISABLED == Dem_Internal.DtcSettingEnCondition)
	{
	    /*Lhbb DiagnosticInformation== 0 not set new event */
	}
	else 
	{
		for (flMemIndex = DEM_EVENT_VALID_ID_START; flMemIndex < Dem_Cfg_Mem_Total_Entry;flMemIndex++)
		{
			if(DEM_GET_CFG_FAILING(Dem_Cfg_StatusData.EventStatus[flMemIndex]))
			{
				if(l_nvm_store_flag[flMemIndex] == 0)
				{
					l_nvm_store_flag[flMemIndex]++;
				}
			}
			else 
			{
				l_nvm_store_flag[flMemIndex] = 0;
			}
		}

		for (flMemIndex = DEM_EVENT_VALID_ID_START; flMemIndex < Dem_Cfg_Mem_Total_Entry;flMemIndex++)
		{
			if(l_nvm_store_flag[flMemIndex] == 1)
			{
				flEntry = (Dem_Cfg_PrimaryMemEntryType*) Dem_Cfg_MemPtr[flMemIndex];
				flBlockId = Dem_Cfg_Memory_BlockId[flMemIndex];

				flEntry->ignst = fl_ignst_u8;
				flEntry->batt_volt = fl_battstate_u8;
				flEntry->odo_value = fl_odo_value_u32;
				flEntry->speed_value = fl_speed_value_u16;
				flEntry->time_year = fl_time_year_cal_u8;
				flEntry->time_month = fl_time_month_u8;
				flEntry->time_day = fl_time_day_u8;
				flEntry->time_hour = fl_time_hour_u8;
				flEntry->time_minute = fl_time_minute_u8;
				flEntry->time_second = fl_time_second_u8;
				flEntry->tach_speed = fl_tach_value_u16;

        flReturnVal = NvmServer_WriteBlock_ById(flBlockId, flEntry, sizeof(Dem_Cfg_PrimaryMemEntryType));
				if (E_OK == flReturnVal)
        {
          l_nvm_store_flag[flMemIndex] = 2;
        }
				break;
			}
		}
	}
	
	l_speed_value_pre_u16 = fl_speed_value_u16;
	l_time_year_pre_u8 = fl_time_year_u8;
	l_time_month_pre_u8 = fl_time_month_u8;
	l_time_day_pre_u8 = fl_time_day_u8;
	l_time_hour_pre_u8 = fl_time_hour_u8;
	l_time_second_pre_u8 = fl_time_second_u8;
	l_time_minute_pre_u8 = fl_time_minute_u8;
	l_tach_value_pre_u16 = fl_tach_value_u16;
}

/**************************************************************************
 Function name   : Dem_ProcessEventAging
 Arguments       : Dem_EventIdType flEventId, uint8 CycleId
 Return type     : void
 Sync/Async      : Synchronous
 Reentrancy      :
 Description     : Does qualifying process on stored event entry for event aging.
 **************************************************************************/
static void Dem_ProcessIGNEvent(void)
{
 uint8 flMemIndex;
	uint8 fl_ignst_u8 = 0;

	NV_DTC_AgeTimes_SetType fl_snapshot_count = {0};
	
  /* Qiuhuaqing Modify,  To be Release after Com Finished */
	//Rte_Read_TIModMdlIgnState_IGNState(&fl_ignst_u8);
	
	for (flMemIndex = DEM_DTC_VALID_START; flMemIndex < Dem_Cfg_Mem_Total_Entry; flMemIndex++)
  {
    if(DEM_GET_CFG_LAST_BAT_STORAGED(Dem_Cfg_StatusData.EventStatus[flMemIndex]))
    {
			if(DEM_GET_CFG_FAILING(Dem_Cfg_StatusData.EventStatus[flMemIndex]))
			{
				l_aging_count_u8[flMemIndex] = AGING_COUNT_NONE;
			}
			else 
			{
				if(fl_ignst_u8 == eIGN_OFF && l_ign_status_pre_u8 == eIGN_RUN)
				{
					if(l_aging_count_u8[flMemIndex] < AGING_COUNT)
					{
						l_aging_count_u8[flMemIndex] ++;
					}
				}
			}
    }
	}
	
	for (flMemIndex = DEM_DTC_VALID_START; flMemIndex < Dem_Cfg_Mem_Total_Entry; flMemIndex++)
  {
    if(DEM_GET_CFG_LAST_BAT_STORAGED(Dem_Cfg_StatusData.EventStatus[flMemIndex]))
    {
			if(fl_ignst_u8 == eIGN_RUN && l_ign_status_pre_u8 == eIGN_OFF)
			{
	      /* Qiuhuaqing Modify,  To be Release after NVM Finished */
				//Rte_Read_NV_DTC_AgeTimes_Element(fl_snapshot_count);
				memcpy(l_aging_count_u8,fl_snapshot_count,sizeof(l_aging_count_u8));
				break;
			}
			else if(fl_ignst_u8 == eIGN_OFF && l_ign_status_pre_u8 == eIGN_RUN)
			{
				memcpy(fl_snapshot_count,l_aging_count_u8,sizeof(fl_snapshot_count));

	      /* Qiuhuaqing Modify,  To be Release after NVM Finished */
				//Rte_Write_NV_DTC_AgeTimes_Element(fl_snapshot_count);
				break;
			}
			else if (l_aging_count_u8[flMemIndex] == AGING_COUNT)
      {
        Dem_ProcessDeletePrimaryMemEntry(flMemIndex);
      }
    }
	}
	
	l_ign_status_pre_u8 = fl_ignst_u8;
}

#endif
/**************************************************************************
 Function name   : Dem_DcmControlDTCStatusChangedNotification
 Arguments       : boolean TriggerNotification
 Return type     : void
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant
 Description     : Controls the triggering of Dcm_DemTriggerOnDTCStatus.
 **************************************************************************/
void Dem_DcmControlDTCStatusChangedNotification(boolean TriggerNotification)
{

}

/**************************************************************************
 Function name   : Dem_DcmDisableDTCRecordUpdate
 Arguments       : uint32 DTC,
 Dem_DTCOriginType DTCOrigin
 Return type     : Dem_ReturnDisableDTCRecordUpdateType
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant
 Description     : Disables the event memory update of a specific DTC.
 **************************************************************************/
Dem_ReturnDisableDTCRecordUpdateType Dem_DcmDisableDTCRecordUpdate(uint32 DTC,
    Dem_DTCOriginType DTCOrigin)
{
  Dem_ReturnDisableDTCRecordUpdateType fl_RetVal;
  fl_RetVal = DEM_DISABLE_DTCRECUP_OK;
  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_DcmEnableDTCRecordUpdate
 Arguments       : void
 Return type     : Dem_ReturnDisableDTCRecordUpdateType
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant
 Description     : Enables the event memory update of the DTC disabled by
 Dem_DcmDisableDTCRecordUpdate() before.
 **************************************************************************/
Dem_ReturnDisableDTCRecordUpdateType Dem_DcmEnableDTCRecordUpdate(void)
{
  Dem_ReturnDisableDTCRecordUpdateType fl_RetVal;
  fl_RetVal = DEM_DISABLE_DTCRECUP_OK;
  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_DcmGetFreezeFrameDataByDTC
 Arguments       : uint32 DTC, Dem_DTCOriginType DTCOrigin, uint8 RecordNumber,
 uint8* DestBuffer, uint16* BufSize
 Return type     : Dem_ReturnGetFreezeFrameDataByDTCType
 Sync/Async      : Asynchronous
 Reentrancy      : Non Reentrant
 Description     : Gets freeze frame data by DTC. The function stores the data
 in the provided DestBuffer.
 **************************************************************************/
Dem_ReturnGetFreezeFrameDataByDTCType Dem_DcmGetFreezeFrameDataByDTC(uint32 DTC,
    Dem_DTCOriginType DTCOrigin, uint8 RecordNumber, uint8* DestBuffer, uint16* BufSize)
{
  Dem_ReturnGetFreezeFrameDataByDTCType fl_RetVal;
  fl_RetVal = DEM_GET_FFDATABYDTC_OK;
  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_DcmGetSizeOfFreezeFrameByDTC
 Arguments       : uint32 DTC, Dem_DTCOriginType DTCOrigin,
 uint8 RecordNumber, uint16* SizeOfFreezeFrame
 Return type     : Dem_ReturnGetSizeOfDataByDTCType
 Sync/Async      : Asynchronous
 Reentrancy      : Non Reentrant
 Description     : Gets the size of freeze frame data by DTC.
 **************************************************************************/
Dem_ReturnGetSizeOfDataByDTCType Dem_DcmGetSizeOfFreezeFrameByDTC(uint32 DTC,
    Dem_DTCOriginType DTCOrigin, uint8 RecordNumber, uint16* SizeOfFreezeFrame)
{
  Dem_ReturnGetSizeOfDataByDTCType fl_RetVal;
  fl_RetVal = DEM_GETSIZEBYDTC_OK;
  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_DcmGetExtendedDataRecordByDTC
 Arguments       : uint32 DTC, Dem_DTCOriginType DTCOrigin,
 uint8 ExtendedDataNumber, uint8* DestBuffer, uint16* BufSize
 Return type     : Dem_ReturnGetExtendedDataRecordByDTCType
 Sync/Async      : Asynchronous
 Reentrancy      : Non Reentrant
 Description     :  Gets extended data by DTC. The function stores the data in
 the provided DestBuffer.
 **************************************************************************/
Dem_ReturnGetExtendedDataRecordByDTCType Dem_DcmGetExtendedDataRecordByDTC(uint32 DTC,
    Dem_DTCOriginType DTCOrigin, uint8 ExtendedDataNumber, uint8* DestBuffer,
    uint16* BufSize)
{
  Dem_ReturnGetExtendedDataRecordByDTCType fl_RetVal;
  fl_RetVal = DEM_RECORD_OK;
  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_DcmGetSizeOfExtendedDataRecordByDTC
 Arguments       : uint32 DTC, Dem_DTCOriginType DTCOrigin,
 uint8 ExtendedDataNumber, uint16* SizeOfExtendedDataRecord
 Return type     : Dem_ReturnGetSizeOfDataByDTCType
 Sync/Async      : Asynchronous
 Reentrancy      : Non Reentrant
 Description     : Gets the size of extended data by DTC.
 **************************************************************************/
Dem_ReturnGetSizeOfDataByDTCType Dem_DcmGetSizeOfExtendedDataRecordByDTC(uint32 DTC,
    Dem_DTCOriginType DTCOrigin, uint8 ExtendedDataNumber,
    uint16* SizeOfExtendedDataRecord)
{
  Dem_ReturnGetSizeOfDataByDTCType fl_RetVal;
  fl_RetVal = DEM_GETSIZEBYDTC_OK;
  return fl_RetVal;
}

static Dem_ReturnClearDTCType Dem_ClearDTCInternal(uint32 DTC, Dem_DTCFormatType DTCFormat, Dem_DTCOriginType DTCOrigin)
{
  Dem_ReturnClearDTCType fl_RetVal;
  uint16 flEventId;

  fl_RetVal = DEM_CLEAR_FAILED;
  Dem_EnterCriticalSection();
  if (Dem_ClearDtc.Req_Status == DEM_DCM_CLEAR_DTC_IDLE)
  {
    fl_RetVal = DEM_CLEAR_WRONG_DTC;
    flEventId = Dem_InternalGetEventIdByDTCValue(DTC);
    if (DEM_DTC_GROUP_ALL_DTCS == DTC)
    {
      Dem_ClearDtc.Req_Status = DEM_DCM_CLEAR_DTC_REQUESTED;/*judge in Dem_MainFunctionProcessQueue*/
      Dem_ClearDtc.DTC = DTC;
      Dem_ClearDtc.Format = DTCFormat;
      Dem_ClearDtc.Orgin = DTCOrigin;
      Dem_ClearDtc.EventId = flEventId;
      Dem_ClearDtc.QueueState = DEM_DCM_CLEAR_DTC_QUEUE_PENDING;
      fl_RetVal = DEM_CLEAR_PENDING;
    }
  }
  else
  {
    /* is it a same request again ? */
    if ((Dem_ClearDtc.DTC == DTC) && (Dem_ClearDtc.Format == DTCFormat) && (Dem_ClearDtc.Orgin == DTCOrigin))
    {
      switch (Dem_ClearDtc.QueueState)
      {
      case DEM_DCM_CLEAR_DTC_QUEUE_PENDING:
        fl_RetVal = DEM_CLEAR_PENDING;
        break;
      case DEM_DCM_CLEAR_DTC_QUEUE_DONE:
        Dem_ClearDtc.Req_Status = DEM_DCM_CLEAR_DTC_IDLE;
        fl_RetVal = DEM_CLEAR_OK;
        break;
      case DEM_DCM_CLEAR_DTC_QUEUE_FAILED:
        Dem_ClearDtc.Req_Status = DEM_DCM_CLEAR_DTC_IDLE;
        fl_RetVal = DEM_CLEAR_FAILED;
        break;
      case DEM_DCM_CLEAR_DTC_QUEUE_CANCEL:
        Dem_ClearDtc.Req_Status = DEM_DCM_CLEAR_DTC_IDLE;
        fl_RetVal = DEM_CLEAR_FAILED;
        break;
      default:
        break;
      }
    }
    else
    {
      fl_RetVal = DEM_CLEAR_BUSY;
    }
  }
  Dem_ExitCriticalSection();
  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_ClearDTC
 Arguments       : uint32 DTC, Dem_DTCFormatType DTCFormat,
 Dem_DTCOriginType DTCOrigin
 Return type     : Dem_ReturnClearDTCType
 Sync/Async      : Asynchronous
 Reentrancy      : Reentrant
 Description     : Clears single DTCs, as well as groups of DTCs. This
 API is intended for complex device driver. It can only be
 used through the RTE (due to work-around described below
 SWS_Dem_00659), and therefore no declaration is exported
 via Dem.h.
 **************************************************************************/
Dem_ReturnClearDTCType Dem_DcmClearDTC(uint32 DTC, Dem_DTCFormatType DTCFormat, Dem_DTCOriginType DTCOrigin)
{
  Dem_ReturnClearDTCType fl_RetVal;
  fl_RetVal = DEM_CLEAR_FAILED;

#if (DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if (Dem_Internal.InitState != DEM_INITIALIZED)
  {
    flError = DEM_DET_UNINITIALIZED;
    fl_RetVal = DEM_CLEAR_FAILED;
  }
  else if (DTCFormat >= DEM_DTC_FORMAT_INVALID)
  {
    flError = DEM_DET_INVALID_PARAMETER;
    fl_RetVal = DEM_CLEAR_WRONG_DTC;
  }
  else if (DEM_DTC_ORIGIN_PRIMARY_MEMORY != DTCOrigin)
  {
    flError = DEM_DET_INVALID_PARAMETER;
    fl_RetVal = DEM_CLEAR_WRONG_DTCORIGIN;
  }
  else
#endif
  {
    if (DTCFormat == DEM_DTC_FORMAT_UDS)
    {
      fl_RetVal = Dem_ClearDTCInternal(DTC, DTCFormat, DTCOrigin);
    }
  }

#if (DemDevErrorDetect == TRUE)
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0, flError);
  }
#endif
  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_DcmDisableDTCSetting
 Arguments       : uint32 DTCGroup, Dem_DTCKindType DTCKind

 Return type     : Dem_ReturnControlDTCSettingType
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant
 Description     : Disables the DTC setting for a DTC group.
 **************************************************************************/
Dem_ReturnControlDTCSettingType Dem_DcmDisableDTCSetting(uint32 DTCGroup,
    Dem_DTCKindType DTCKind)
{
  Dem_ReturnControlDTCSettingType fl_RetVal;
  fl_RetVal = DEM_CONTROL_DTC_SETTING_N_OK;

#if (DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if (Dem_Internal.InitState != DEM_INITIALIZED)
  {
    flError = DEM_DET_UNINITIALIZED;
  }
  else if (DEM_DTC_KIND_INVALID <= DTCKind)
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else
#endif
  {

    if ((DTCGroup == DEM_DTC_GROUP_ALL_DTCS) && (DTCKind == DEM_DTC_KIND_ALL_DTCS))
    {
      Dem_Internal.DtcSettingConditionRequestedFlag = TRUE;
      Dem_Internal.DtcSettingEnConditionQueue = DEM_DTC_STORAGE_SETTING_DISABLED;
      fl_RetVal = DEM_CONTROL_DTC_SETTING_OK;
    }
  }

#if (DemDevErrorDetect == TRUE)
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
#endif
  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_DcmEnableDTCSetting
 Arguments       : uint32 DTCGroup, Dem_DTCKindType DTCKind

 Return type     : Dem_ReturnControlDTCSettingType
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant
 Description     : Enables the DTC setting for a DTC group.
 This API is intended for the Dcm. It can only be used
 through the RTE (due to work-around described below
 SWS_Dem_00035), and therefore no declaration is exported
 via Dem_Dcm.h.
 **************************************************************************/
Dem_ReturnControlDTCSettingType Dem_DcmEnableDTCSetting(uint32 DTCGroup,
    Dem_DTCKindType DTCKind)
{
  Dem_ReturnControlDTCSettingType fl_RetVal;
  fl_RetVal = DEM_CONTROL_DTC_SETTING_N_OK;

#if (DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if (Dem_Internal.InitState != DEM_INITIALIZED)
  {
    flError = DEM_DET_UNINITIALIZED;
  }
  else if (DEM_DTC_KIND_INVALID <= DTCKind)
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else
#endif
  {

    if ((DTCGroup == DEM_DTC_GROUP_ALL_DTCS) && (DTCKind == DEM_DTC_KIND_ALL_DTCS))
    {
      Dem_Internal.DtcSettingConditionRequestedFlag = TRUE;
      Dem_Internal.DtcSettingEnConditionQueue = DEM_DTC_STORAGE_SETTING_ENABLED;
      fl_RetVal = DEM_CONTROL_DTC_SETTING_OK;
    }
  }

#if (DemDevErrorDetect == TRUE)
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
#endif
  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_NvM_JobFinished
 Arguments       : (uint8 ServiceId, NvM_RequestResultType JobResult

 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant
 Description     : NVM CallBack .
 **************************************************************************/
Std_ReturnType Dem_NvM_JobFinished(uint8 ServiceId, NvM_RequestResultType Result)
{
  Std_ReturnType fl_RetVal;
  fl_RetVal = E_OK;

  if (Dem_NvmWriteData.WriteStatus == DEM_NVM_WRITING)
  {
    if (Result != NVM_REQ_OK)
    { /* Write request aborted or otherwise failed. */
      Dem_NvmWriteData.WriteStatus = DEM_NVM_FAILED;
    }
    else
    {
      /* Continue with next block */
      Dem_NvmWriteData.WriteStatus = DEM_NVM_FINISHED;
    }
  }

  return fl_RetVal;
}

/*** OBD-specific Dcm <=> Dem Interfaces *** Not Supported ***/
/*** Interface J1939Dcm <=> Dem *** Not Supported ***/
/*** OBD-specific Interfaces *** Not Supported ***/
/*** Interface Dlt <=> Dem *** Not Supported ***/

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
/*Date              : 07-Mar-2017                                            */
/*Version           :                                                       */
/*By                : msavariy                                              */
/*Traceability      :                                                       */
/*Change Description: Data design And Framework , Initial Version */
/*--------------------------------------------------------------------------*/

