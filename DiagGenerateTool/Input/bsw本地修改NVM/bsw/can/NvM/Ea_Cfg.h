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
*  File Name         :  Ea_Cfg.h                                             *
*  Module Short Name :  Ea                                                   *
*  Description       : Generated Configuration file for Ea                   *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS Multi                                              *
* Target Hardware  :                                                         *
*                                                                            *
******************************************************************************/
#ifndef EA_CFG_H
#define EA_CFG_H
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/

#include "Ea_Types.h"
//#include "Eep24xx.h"
#include "NvM_Types.h"
#include "NVM_Cbk.h"
#include "Os.h"

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
#ifndef EA_CFG_C
#define EXTERN extern
#else
#define EXTERN
#endif

#define EaDevErrorDetect

#define EaNvmJobEndNotification
#define EaNvmJobErrorNotification
#define EaPollingMode
#define EaVersionInfoApi
#define EaVirtualPageSize

#define EA_HEADER2_SIZE         1
#define EA_HEADER1_SIZE         1
#define EA_BLOCK_OVERHEAD      (EA_HEADER1_SIZE + EA_HEADER2_SIZE)

#define EA_NUM_BLOCKS          75

#define Ea_Eep_Write        Eep24xx_Write
#define Ea_Eep_Read         Eep24xx_Read
#define Ea_Eep_Compare      Eep24xx_Compare
#define Ea_Eep_Erase        Eep24xx_Erase
#define Ea_Eep_GetJobResult Eep24xx_GetJobResult

/*---------------  Call Backs  to NVM------------------------*/

#define Ea_CbkJobEndNotification()    NvM_JobEndNotification()
#define Ea_CbkJobErrorNotification()  NvM_JobErrorNotification()

/*---------------  EA Critical Sections Macro  ------------------------*/
#define EA_ENTER_CRITICAL_SECTION()   SuspendAllInterrupts()
#define EA_EXIT_CRITICAL_SECTION()    ResumeAllInterrupts()



/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/
typedef struct
{
uint16  BlockBaseAddress;
uint16  BlockSize;
uint8   NoOfInstances;
uint8   BlockFlags;
}Ea_ConfigType;

/*****************************************************************************
*                                Globally  accessed Variable Declarations    *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/
EXTERN const uint8 Ea_DatasetSelectionBits;

EXTERN const Ea_ConfigType Ea_Config[EA_NUM_BLOCKS];
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
#undef EXTERN

#endif /* EA_CFG_H */
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
/*Date              : 13-01-2016                                            */
/*Version           :                                                       */
/*By                : kshaik1                                               */
/*Traceability      :                                                       */
/*Change Description: Datadesign And Framework implemented, Initial Version */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 25-02-2016                                            */
/*Version           :                                                       */
/*By                : kshaik1                                               */
/*Traceability      : 513221                                                */
/*Change Description: Updated for code review comments                      */
/*--------------------------------------------------------------------------*/
