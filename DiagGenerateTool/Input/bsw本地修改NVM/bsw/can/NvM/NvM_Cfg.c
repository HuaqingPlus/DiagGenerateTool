/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2012. Visteon Corporation owns all rights to           *
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
*  File Name         :  NvM_Cfg.c                                            *
*  Module Short Name :  NvMMgr                                               *
*  VOBName           :                                                       *
*  Author            : vbalakr3                                              *
*  Description       : Generated Configuration file for NvM                  *
*                                                                            *
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
#ifndef NVM_CFG_C
#define NVM_CFG_C
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#define RTE_MICROSAR_PIM_EXPORT

#include "Rte_NvM.h"
#include "NvM_Cfg.h"

//#include "EcuMExt.h"
#include "Dem.h"
#include "Dem_Cbk.h" // Murali added this

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/
#ifdef __ghs__
#pragma alignvar (8)
#endif


/*****************************************************************************
*                                Globally  accessed Variable Declarations    *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/
const NvM_BlockDescriptorType NvM_BlockConfig[NVM_NUM_OF_BLOCKS] =
{
   NvmCfg_BlockConfig_Table
};

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

void NvM_MultiBlockCallbackFunction(uint8 ServiceId, NvM_RequestResultType JobResult)
{
    //NvMExt_MultiBlockJobEndNotification(ServiceId,JobResult);
    NvM_MultiBlockJobEndNotification(ServiceId, JobResult);
}

void NvM_EnterCriticalSection(void)
{
   /* Qiuhuaqing Modify,  To be Release after OS Finished */
  //SchM_Enter_NvM_NVM_EXCLUSIVE_AREA_0();
}

void NvM_ExitCriticalSection(void)
{
   /* Qiuhuaqing Modify,  To be Release after OS Finished */
  //SchM_Exit_NvM_NVM_EXCLUSIVE_AREA_0();
}

#endif /* NVM_C */
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
/*Date              : 21-08-2015                                            */
/*Version           :                                                       */
/*By                : vbalakr3                                              */
/*Traceability      :                                                       */
/*Change Description: Datadesign And Framework implemented, Initial Version */
/*--------------------------------------------------------------------------*/
