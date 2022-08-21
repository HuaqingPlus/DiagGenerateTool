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
*  File Name         :  Fee_Cfg.h                                            *
*  Module Short Name :  Fee                                                  *
*  VOBName           :                                                       *
*  Author            : vbalakr3                                              *
*  Description       : Generated Configuration file for Fee                  *
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
#ifndef FEE_CFG_H
#define FEE_CFG_H
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/

#include "Fee_Types.h"
#include "Fee_Cfg_Generate.h"
#include "Fls.h"

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
#ifndef FEE_CFG_C
#define EXTERN extern
#else
#define EXTERN
#endif




#define NVM_JOB_END_NOTIFICATION()      NvM_JobEndNotification()
#define NVM_JOB_ERROR_NOTIFICATION()    NvM_JobErrorNotification()


#define FLS_WRITE(x,y,z)      Fls_Write(x,y,z)
#define FLS_READ(x,y,z)     Fls_Read(x,y,z)
#define FLS_GET_JOB_RESULT()  Fls_GetJobResult()
#define FLS_ERASE(x,y)        Fls_Erase(x,y)


/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/
typedef struct  
{
  uint16 BlockNumber;
  uint16 BlockSize;
  uint8  PartitionNo;
  boolean ImmediateData;
}Fee_BlockConfigType;


typedef struct  
{
  uint32 StartVirtualAddress;
  uint8  NumberOfSectors;
}Fee_PartitionConfigType;



/*****************************************************************************
*                                Globally  accessed Variable Declarations    *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/
EXTERN const Fee_BlockConfigType Fee_BlockConfig[FEE_NUM_BLOCKS];

EXTERN const Fee_PartitionConfigType Fee_PartitionConfig[FEE_NUM_PARTITIONS];


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

#endif /* NVM_CBK_H */
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
