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
 *  File Name         :  Dem_Cfg.h                                                *
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
#ifndef DEM_CFG_H
#define DEM_CFG_H

/*****************************************************************************
 *                            Include files                                   *
 ******************************************************************************/
#include "Std_Types.h"
#include "RTE_Dem_Type.h"
#include "Dem_Cfg_Generate.h"

/* Qiuhuaqing Modify to avoid Compiler Error */
/* -----------------------------------------------------------------------------
    Version information
 ----------------------------------------------------------------------------- */
/* AUTOSAR Version (from xsi:schemaLocation) */
#define DEM_CFG_AR_RELEASE_MAJOR_VERSION                              4u
#define DEM_CFG_AR_RELEASE_MINOR_VERSION                              1u
#define DEM_CFG_AR_RELEASE_REVISION_VERSION                           2u

/* AUTOSAR Software Specification Version Information of BSW-IMPLEMENTATION */
#define DEM_CFG_AR_MAJOR_VERSION                                      4u
#define DEM_CFG_AR_MINOR_VERSION                                      1u
#define DEM_CFG_AR_PATCH_VERSION                                      2u

/* SW version number of BSW-IMPLEMENTATION */
#define DEM_CFG_SW_MAJOR_VERSION                                      19u
#define DEM_CFG_SW_MINOR_VERSION                                      0u
#define DEM_CFG_SW_PATCH_VERSION                                      0u

/* Generator Version Information */
#define DEM_CFG_GEN_MAJOR_VERSION                                     19
#define DEM_CFG_GEN_MINOR_VERSION                                     0
#define DEM_CFG_GEN_PATCH_VERSION                                     0
#define DEM_CFG_GEN_COMPATIBILITY_VERSION                             118535uL


/*****************************************************************************
 *                                 Macro Definitions                          *
 *----------------------------------------------------------------------------*
 * Definition of macro shall be followed by a comment that explains the       *
 * purpose of the macro.                                                      *
 ******************************************************************************/
/* Frame Work compilation purpose */
#define DemConf_DemOperationCycle_DemOperationCycle_IgnitionOnOff   0U
#define DemConf_DemOperationCycle_DemOperationCycle_WakeupSleep   1U

/* For compile */
#define DemConf_DemEventParameter_IOHWAB_E_UNDERVOLTAGE   0
#define DemConf_DemEventParameter_IOHWAB_E_OVERVOLTAGE    0

/* Qiuhuaqing Add, DTC Code */
#define DEM_DTC_VALUE_FFFFFF  ((uint32)0xFFFFFFFF)

#define Dem_Cfg_Num_Of_EnCon    1U

#define Dem_Cfg_Num_Of_StrCon    1U

/***  DEM NVM   ***/

#define Dem_Cfg_Mem_Entry_Start        0U
#define Dem_Cfg_Mem_Admin_Index        0U
#define Dem_Cfg_Mem_Status_Index       1U
#define Dem_Cfg_Mem_Primary_Entry_Start   3U /*include DTC 0xFFFFFFFF index2*/
#define Dem_Cfg_Mem_Total_Primary_Entry (Dem_Cfg_Num_Of_DTC)
#define Dem_Cfg_Mem_Primary_Entry_Stop  (Dem_Cfg_Mem_Total_Primary_Entry + 2)
#define Dem_Cfg_Mem_Total_Entry      (Dem_Cfg_Mem_Total_Primary_Entry + 2)

/*************  Dem_General Configuration ************************************/

/***  DemClearDTCBehavior ***/
#define DEM_CLRRESP_NONVOLATILE_FINISH    FALSE
#define DEM_CLRRESP_NONVOLATILE_TRIGGER    FALSE
#define DEM_CLRRESP_VOLATILE        TRUE

/***  DemClearDTCLimitation  ***/

#define DEM_ALL_SUPPORTED_DTCS        TRUE
#define DEM_ONLY_CLEAR_ALL_DTCS        FALSE

/***  ***/

#define DemDebounceCounterBasedSupport    TRUE
#define DemDebounceTimeBasedSupport      TRUE

#define DemDevErrorDetect          TRUE

#define DemDtcStatusAvailabilityMask    0x09 //(For BAIC)

/***  DemEventMemoryEntryStorageTrigger  ***/
#define DEM_TRIGGER_ON_CONFIRMED      FALSE
#define DEM_TRIGGER_ON_FDC_THRESHOLD    FALSE
#define DEM_TRIGGER_ON_PENDING        FALSE
#define DEM_TRIGGER_ON_TEST_FAILED      TRUE

/***  DemOccurrenceCounterProcessing  ***/
#define DEM_PROCESS_OCCCTR_CDTC        FALSE
#define DEM_PROCESS_OCCCTR_TF        TRUE

#define DEM_OCCURRENCE_COUNTER_THERSHOLD  255U

/***  ***/
#define DemTriggerMonitorInitBeforeClearOk  TRUE

#define DEM_DEBOUNCE_RESET              1U


/*
 *  FLS Error List
*/
#define DemConf_DemEventParameter_FLS_E_COMPARE_FAILED                10U
#define DemConf_DemEventParameter_FLS_E_ERASE_FAILED                  28U
#define DemConf_DemEventParameter_FLS_E_READ_FAILED                   29U
#define DemConf_DemEventParameter_FLS_E_READ_FAILED_DED               30U
#define DemConf_DemEventParameter_FLS_E_WRITE_FAILED                  31U


/*
 *  GPT Error List
*/
#define DemConf_DemEventParameter_GPT_E_TIMEOUT_FAILURE               27U


/*
 *  SPI Error List
*/
#define DemConf_DemEventParameter_SPI_E_HARDWARE_ERROR                13U
#define DemConf_DemEventParameter_SPI_E_DATA_TX_TIMEOUT_FAILURE       12U

/*
 *  PORT Error List
*/
#define DemConf_DemEventParameter_PORT_E_WRITE_TIMEOUT_FAILURE        26U


//ssukuma1: macros requried by RH850 MCALs hardcoded below for compilation
//Dem macros - these are required by rh850 mcal gen
#define DemConf_DemEventParameter_DemEventParameter_001 1
#define DemConf_DemEventParameter_DemEventParameter0    2
#define DemConf_DemEventParameter_DemEventParameter1    3
#define DemConf_DemEventParameter_DemEventParameter2    4
#define DemConf_DemEventParameter_DemEventParameter3    5
#define DemConf_DemEventParameter_DemEventParameter4    6
#define DemConf_DemEventParameter_DemEventParameter5    7

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

typedef struct
{
  uint32 TimeStamb;
  uint16 EventId;
  uint16 AgingCounter;
  uint8 ignst;
  uint8 batt_volt;
  uint32 odo_value;
  uint16 speed_value;
  uint8  time_year;
  uint8  time_month;
  uint8  time_day;
  uint8  time_hour;
  uint8  time_minute;
  uint8  time_second;
  uint16 tach_speed;
  //uint16 OccurrenceCounter;
} Dem_Cfg_PrimaryMemEntryType;

typedef struct
{
  uint16 FirstFailedEvent;
  uint16 FirstConfirmedEvent;
  uint16 RecentFailedEvent;
  uint16 RecentConfirmedEvent;
  uint8 EventStatus[Dem_Cfg_Mem_Total_Entry];
} Dem_Cfg_UdsStatusDataType;

typedef struct 
{
  uint16 ImplementationVersion;
  uint16 ConfigurationId;
  uint16 CycleCounter[2];
  uint8  MemoryOverflow; /* (DEM_CFG_DATA_OVFLIND == STD_ON) || (DEM_CFG_SUPPORT_OVFLIND_API == STD_ON) */
}Dem_Cfg_AdminDataType;

typedef struct
{
  uint16 Counter[Dem_Cfg_Num_Of_OpCycle];
  uint8 MagicFlag;
} Dem_Cfg_OpCycleType;

typedef struct
{
  uint8 Id;
  uint8 Type;
  boolean AutoStart;
  boolean AutoStop;
} Dem_Cfg_OpCycleStateType;

typedef struct
{
  uint8 Id;
  boolean Status;
} Dem_Cfg_EnableConditionType;

typedef struct
{
  uint8 Id;
  boolean Status;
} Dem_Cfg_StorageConditionType;

/*typedef struct
 {
 uint16 Number;
 } Dem_Cfg_NvRamBlockIdType;*/

typedef uint16 Dem_Cfg_NvRamBlockIdType;

typedef struct
{
  uint32 Value;
  uint8 AttrbsRef;
} Dem_Cfg_DTCType;

typedef struct
{
  uint8 AgingThershold;
  uint8 AgingOpCycleRef;
  boolean ImmediateNvStorageAllowed;
  boolean AgingAllowed;
} Dem_Cfg_DTCAttributesType;

typedef struct
{
  Std_ReturnType (*DemCallbackInitMForE)(Dem_InitMonitorReasonType Reason);
  Dem_EventIdType Id;
  uint8 EventKind;
  uint8 FailureCycleCounterThershold;
  uint8 DebounceTableRef;
  uint8 OpCycleRef;
  uint8 DTCTableRef;
  uint8 EnableConditionRef;
  uint8 StorageConditionRef;
  boolean AvailableStatus;
} Dem_Cfg_EventParameterType;

typedef struct
{
  sint16 FailedThershold;
  sint16 PassedThershold;
  sint16 FailedTimeThershold;
  sint16 PassedTimeThershold;
  sint8 DecStepSize;
  sint8 IncStepSize;
  sint8 JumpUpValue;
  sint8 JumpDownValue;
  uint8 AlgoClass;
  boolean JumpUp;
  boolean JumpDown;
  boolean behavior;
} Dem_Cfg_DebounceTableType;

extern const Dem_Cfg_PrimaryMemEntryType Dem_MemoryEntryInit;

/*
 extern Dem_Cfg_PrimaryMemEntryType Dem_SecondaryEntry_0;
 extern Dem_Cfg_PrimaryMemEntryType Dem_SecondaryEntry_1;
 extern Dem_Cfg_PrimaryMemEntryType Dem_SecondaryEntry_2;
 extern Dem_Cfg_PrimaryMemEntryType Dem_SecondaryEntry_3;
 extern Dem_Cfg_PrimaryMemEntryType Dem_SecondaryEntry_4;
 extern Dem_Cfg_PrimaryMemEntryType Dem_SecondaryEntry_5;
 extern Dem_Cfg_PrimaryMemEntryType Dem_SecondaryEntry_6;
 extern Dem_Cfg_PrimaryMemEntryType Dem_SecondaryEntry_7;
 extern Dem_Cfg_PrimaryMemEntryType Dem_SecondaryEntry_8;
 extern Dem_Cfg_PrimaryMemEntryType Dem_SecondaryEntry_9;
 extern Dem_Cfg_PrimaryMemEntryType Dem_SecondaryEntry_10;
 extern Dem_Cfg_PrimaryMemEntryType Dem_SecondaryEntry_11;
 extern Dem_Cfg_PrimaryMemEntryType Dem_SecondaryEntry_12;
 extern Dem_Cfg_PrimaryMemEntryType Dem_SecondaryEntry_13;
 extern Dem_Cfg_PrimaryMemEntryType Dem_SecondaryEntry_14;
 extern Dem_Cfg_PrimaryMemEntryType Dem_SecondaryEntry_15;
 extern Dem_Cfg_PrimaryMemEntryType Dem_SecondaryEntry_16;
 extern Dem_Cfg_PrimaryMemEntryType Dem_SecondaryEntry_17;
 extern Dem_Cfg_PrimaryMemEntryType Dem_SecondaryEntry_18;
 extern Dem_Cfg_PrimaryMemEntryType Dem_SecondaryEntry_19;
 extern Dem_Cfg_PrimaryMemEntryType Dem_SecondaryEntry_20;
 extern Dem_Cfg_PrimaryMemEntryType Dem_SecondaryEntry_21;
 extern Dem_Cfg_PrimaryMemEntryType Dem_SecondaryEntry_22;
 extern Dem_Cfg_PrimaryMemEntryType Dem_SecondaryEntry_23;
 extern Dem_Cfg_PrimaryMemEntryType Dem_SecondaryEntry_24;
 extern Dem_Cfg_PrimaryMemEntryType Dem_SecondaryEntry_25;
 extern Dem_Cfg_PrimaryMemEntryType Dem_SecondaryEntry_26;
 extern Dem_Cfg_PrimaryMemEntryType Dem_SecondaryEntry_27;
 */

extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_0;
extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_1;
extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_2;
extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_3;
extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_4;
extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_5;
extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_6;
extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_7;
extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_8;
extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_9;
extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_10;
extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_11;
extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_12;
extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_13;
extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_14;
extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_15;
extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_16;
extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_17;
extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_18;
extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_19;
extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_20;

extern const uint8* Dem_Cfg_MemPtr[Dem_Cfg_Mem_Total_Entry];
extern const Dem_Cfg_NvRamBlockIdType Dem_Cfg_Memory_BlockId[Dem_Cfg_Mem_Total_Entry];

extern Dem_Cfg_UdsStatusDataType Dem_Cfg_StatusData;
extern Dem_Cfg_AdminDataType Dem_Cfg_AdminData;
extern Dem_Cfg_OpCycleType Dem_Cfg_OpCycle;

extern const Dem_Cfg_OpCycleStateType Dem_Cfg_OpCycleState[Dem_Cfg_Num_Of_OpCycle];

extern const Dem_Cfg_EnableConditionType Dem_Cfg_EnableCondition[Dem_Cfg_Num_Of_EnCon];
extern const Dem_Cfg_StorageConditionType Dem_Cfg_StorageCondition[Dem_Cfg_Num_Of_StrCon];

/***  DTC  ***/
extern const Dem_Cfg_DTCType Dem_Cfg_DTC[Dem_Cfg_Num_Of_DTC];
extern const Dem_Cfg_DTCAttributesType Dem_Cfg_DTCAttributes[Dem_Cfg_Num_Of_DTC];

/*** Event  ***/
extern const Dem_Cfg_EventParameterType Dem_Cfg_EventParameter[Dem_Cfg_Num_Of_Event];
extern const Dem_Cfg_DebounceTableType Dem_Cfg_DebounceTable[Dem_Cfg_Num_Of_DebounceTable];

/*****************************************************************************
 *                                 Locally used Variable Declarations         *
 *----------------------------------------------------------------------------*
 * Declaration shall be followed by a comment that gives the following info.  *
 * about the variable.                                                        *
 * purpose, critical section, unit, and resolution                            *
 ******************************************************************************/

/*****************************************************************************
 *                   Functions                                                *
 ******************************************************************************/

extern void Dem_EnterCriticalSection(void);
extern void Dem_ExitCriticalSection(void);

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

