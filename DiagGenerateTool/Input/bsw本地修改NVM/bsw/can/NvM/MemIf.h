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
*  File Name         :  Memif.h                                              *
*  Module Short Name :  NvMMgr                                               *
*  VOBName           :                                                       *
*  Author            : vbalakr3                                              *
*  Description       : Abstraction for EA/Fee                                *
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
#ifndef MEMIF_H
#define MEMIF_H
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "Fee.h"
#include "Ea.h"
#include "MemIf_Types.h"

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
#define MEMIF_FEE_ERASE_BLOCK(x)       Fee_EraseImmediateBlock(x)
#define MEMIF_FEE_WRITE_BLOCK(x,y)     Fee_Write(x,y)
#define MEMIF_FEE_READ_BLOCK(w,x,y,z)  Fee_Read(w,x,y,z)
#define MEMIF_FEE_INVALIDATE_BLOCK(x)  Fee_InvalidateBlock(x)
#define MEMIF_FEE_GET_JOB_RESULT()     Fee_GetJobResult()
#define MEMIF_FEE_GET_STATUS()         Fee_GetStatus()


#define MEMIF_EA_ERASE_BLOCK(x)       Ea_EraseImmediateBlock(x)
#define MEMIF_EA_WRITE_BLOCK(x,y)     Ea_Write(x,y)
#define MEMIF_EA_READ_BLOCK(w,x,y,z)  Ea_Read(w,x,y,z)
#define MEMIF_EA_INVALIDATE_BLOCK(x)       Ea_InvalidateBlock(x)
#define MEMIF_EA_GET_JOB_RESULT()     Ea_GetJobResult()
#define MEMIF_EA_GET_STATUS()         Ea_GetStatus()

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

#endif /* MEMIF_H */
/*****************************************************************************
*     End of File
*
*******************************************************************************/
