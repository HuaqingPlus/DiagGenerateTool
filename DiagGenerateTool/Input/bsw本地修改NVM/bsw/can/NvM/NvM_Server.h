/*****************************************************************************
*
*  FILE        :NvM_Server.h
*  DESCRIPTION :NvM_Server.c
*  DATE        :2022-07-05
*  AUTHOR      :Qhq
*  NOTE:
*
******************************************************************************/
/*****************************************************************************
 *     Start of File
 *
 *****************************************************************************/
#ifndef __NVM_SERVER_H__
#define __NVM_SERVER_H__

#ifndef __NVM_SERVER_C__
#define EXTERN extern
#else
#define EXTERN
#endif

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "Std_Types.h"

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/
typedef struct NvM_DirtyConfig
{
   uint8 BlockId;
   uint8 DirtyFlag;
   uint8* RamAddress;
}S_NvM_DirtyFlag_Type;


/*****************************************************************************
*                  CallBack Functions                                        *
*****************************************************************************/
EXTERN void NvmServer_MainFunction(void);
EXTERN void NvmServer_Init(void);
EXTERN void NvmServer_InitFlags(void);
EXTERN uint8 NvmServer_WriteBlock_ById(uint8 BlockId, uint8* Data, uint8 len);
EXTERN uint8 NvmServer_ReadBlock_ById(uint8 BlockId, uint8* Data, uint8 len);

#undef EXTERN
#endif

/*****************************************************************************
 *     End of File
 *
 *****************************************************************************/

