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
*  File Name         :  NvM_Cfg.h                                            *
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
#ifndef NVM_CFG_H
#define NVM_CFG_H
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "NvM_Types.h"
#include "Crc.h"
#include "NvM_Cfg_Generate.h"

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

#ifndef NVM_CFG_C
#define EXTERN extern
#else
#define EXTERN
#endif




#ifdef __ghs__
#pragma alignvar (8)
#endif
extern uint8 Data_Interpolations[36];

#ifdef __ghs__
#pragma alignvar (8)
#endif
extern const uint8 DefData_Interpolations[36];


#ifdef __ghs__
#pragma alignvar (8)
#endif
extern uint8 Data_Runtime[4];

#ifdef __ghs__
#pragma alignvar (8)
#endif
extern const uint8 DefData_Runtime[4];


#ifdef __ghs__
#pragma alignvar (8)
#endif
extern uint8 Data_ClusterSettings[12];

#ifdef __ghs__
#pragma alignvar (8)
#endif
extern const uint8 DefData_ClusterSettings[12];


#ifdef __ghs__
#pragma alignvar (8)
#endif
extern uint8 NvMConfigBlock_RamBlock_au8[8];


/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

#define NVM_CRC_BYTES           1
#define NVM_CRC_CALC_MAX_LEN    32
#define NVM_CRC_CALCULATE       Crc_CalculateCRC8

#define IMMEDIATE_JOB_QUEUE_SIZE 20
#define STANDARD_JOB_QUEUE_SIZE  20


#define BswMMultiBlockJobStatusInformation
#define CrcNumOfBytes
#define NVM_DATASET_SELECTION_BITS        0
#define NVM_WRITE_VERIFICATION_DATASIZE   200
#define DrvModeSwitch
#define JobPrioritization
#define MultiBlockCallback
#define PollingMode
#define SetRamBlockStatusApi
#define SizeImmediateJobQueue
#define SizeStandardJobQueue
#define VersionInfoApi
#define WriteVerification


/*****************************************************************************
*                                Globally  accessed Variable Declarations    *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/
EXTERN const NvM_BlockDescriptorType NvM_BlockConfig[NVM_NUM_OF_BLOCKS];
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

EXTERN void NvM_EnterCriticalSection(void);

EXTERN void NvM_ExitCriticalSection(void);

EXTERN FUNC( void, NVM_CODE) NvM_MultiBlockJobEndNotification(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult);

#undef EXTERN

#endif /* NVM_H */
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
