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
 *  File Name         :  Dem_Cfg.c                                            *
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
#ifndef DEM_CFG_C
#define DEM_CFG_C

/*****************************************************************************
 *                            Include files                                   *
 ******************************************************************************/
#include "Std_Types.h"
#include "Dem.h"
#include "Dem_Cfg_Generate.h"

/*#include "Rte_Dem.h"*/
#include "NvM.h"  /* Qiuhuaqing Modify,  To be Release after NVM Finished */
//#include "SchM_Dem.h"

/*****************************************************************************
 *                                 Macro Definitions                          *
 *----------------------------------------------------------------------------*
 * Definition of macro shall be followed by a comment that explains the       *
 * purpose of the macro.                                                      *
 ******************************************************************************/

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

const Dem_Cfg_PrimaryMemEntryType Dem_MemoryEntryInit =
{0xFFFFFFFF,0,0,0,0,0,0,0,0,0,0,0,0,0};



Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_0 = {0xFFFFFFFF,0,0,0,0,0,0,0,0,0,0,0,0,0};
Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_1 = {0xFFFFFFFF,0,0,0,0,0,0,0,0,0,0,0,0,0};
Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_2 = {0xFFFFFFFF,0,0,0,0,0,0,0,0,0,0,0,0,0};

Dem_Cfg_UdsStatusDataType Dem_Cfg_StatusData;
Dem_Cfg_OpCycleType Dem_Cfg_OpCycle;
Dem_Cfg_AdminDataType Dem_Cfg_AdminData;
Dem_Cfg_AdminDataType Dem_Cfg_AdminData1;

const uint8* Dem_Cfg_MemPtr[Dem_Cfg_Mem_Total_Entry] =
{   
  (uint8*) &Dem_Cfg_OpCycle,   
  (uint8*) &Dem_Cfg_AdminData,  
  (uint8*) &Dem_Cfg_StatusData, 
  (uint8*) &Dem_PrimaryEntry_0,
  (uint8*) &Dem_PrimaryEntry_1, 
};

const Dem_Cfg_NvRamBlockIdType Dem_Cfg_Memory_BlockId[Dem_Cfg_Mem_Total_Entry] = \
{
    NvMConf_NvMBlockDescriptor_OpCycle, 
    NvMConf_NvMBlockDescriptor_DemAdmin, 
    NvMConf_NvMBlockDescriptor_DemStatus,
    NvMConf_NvMBlockDescriptor_DemPrimary_000, 
    NvMConf_NvMBlockDescriptor_DemPrimary_001,
};



const Dem_Cfg_EnableConditionType Dem_Cfg_EnableCondition[Dem_Cfg_Num_Of_EnCon] =
{
	/*id, Status */
	{ 0, 1 } 
};

const Dem_Cfg_StorageConditionType Dem_Cfg_StorageCondition[Dem_Cfg_Num_Of_StrCon] =
{
	/*id, Status */
	{ 0, 1 } 
};


//OpCYcle Table
const Dem_Cfg_OpCycleStateType Dem_Cfg_OpCycleState[Dem_Cfg_Num_Of_OpCycle] =
{
  	DEM_TABLE_OPCYCLE
};

//Debounce Table
const Dem_Cfg_DebounceTableType Dem_Cfg_DebounceTable[Dem_Cfg_Num_Of_DebounceTable] =
{
  	DEM_TABLE_DEBOUNCE
};

//DTC Value
const Dem_Cfg_DTCType Dem_Cfg_DTC[Dem_Cfg_Num_Of_DTC] =
{
    DEM_TABLE_DTC
};

//DTC Attributes Table
const Dem_Cfg_DTCAttributesType Dem_Cfg_DTCAttributes[Dem_Cfg_Num_Of_DTC] =
{
    DEM_TABLE_DTC_ATTRIBUTES
};

//Event Table
const Dem_Cfg_EventParameterType Dem_Cfg_EventParameter[Dem_Cfg_Num_Of_Event] =
{
  	DEM_TABLE_EVENT_PARAMETERS
};


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

void Dem_EnterCriticalSection(void)
{
    
  /* Qiuhuaqing Modify,  To be Release after SchM Finished */
  //SchM_Enter_Dem_DEM_EXCLUSIVE_AREA_0();
}
void Dem_ExitCriticalSection(void)
{
    /* Qiuhuaqing Modify,  To be Release after SchM Finished */
    //SchM_Exit_Dem_DEM_EXCLUSIVE_AREA_0();
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
/*Date              : 15-Mar-2017                                            */
/*Version           :                                                       */
/*By                : msavariy                                              */
/*Traceability      :                                                       */
/*Change Description: Data design And Framework , Initial Version */
/*--------------------------------------------------------------------------*/

