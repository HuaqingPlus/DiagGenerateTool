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
*  File Name         :  NvM_Types.h                                          *
*  Module Short Name :  NvMMgr                                               *
*  VOBName           :                                                       *
*  Author            : vbalakr3                                              *
*  Description       : This file contains the typedefs for nvM               *
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
#ifndef NVM_TYPES_H
#define NVM_TYPES_H
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "Std_Types.h"
#include "Rte_Type.h"
#include "Nvm_Adapt.h"

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/


/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

/* Qiuhuaqing Modify, to resolve Compile Error */

typedef uint16 NvM_BlockIdType;

typedef uint8 NvM_RequestResultType;

#ifndef NVM_REQ_OK
#define NVM_REQ_OK                    0x00
#endif

#ifndef NVM_REQ_NOT_OK
#define NVM_REQ_NOT_OK                0x01
#endif

#ifndef NVM_REQ_PENDING
#define NVM_REQ_PENDING               0x02
#endif

#ifndef NVM_REQ_INTEGRITY_FAILED
#define NVM_REQ_INTEGRITY_FAILED      0x03
#endif

#ifndef NVM_REQ_BLOCK_SKIPPED
#define NVM_REQ_BLOCK_SKIPPED         0x04
#endif

#ifndef NVM_REQ_NV_INVALIDATED
#define NVM_REQ_NV_INVALIDATED        0x05
#endif

#ifndef NVM_REQ_CANCELED
#define NVM_REQ_CANCELED              0x06
#endif

#ifndef NVM_REQ_REDUNDANCY_FAILED
#define NVM_REQ_REDUNDANCY_FAILED     0x07
#endif

#ifndef NVM_REQ_RESTORED_FROM_ROM
#define NVM_REQ_RESTORED_FROM_ROM     0x08
#endif


/* These Sevice IDs are important to an SW-C, as they can be passed to it in the
"single block job end notification" callback.
Therefore they are also defined by the RTE */
#ifndef NVM_READ_BLOCK
#    define NVM_READ_BLOCK             (6u) /* Service ID NvM_ReadBlock() */
#endif
#ifndef NVM_WRITE_BLOCK
#    define NVM_WRITE_BLOCK            (7u) /* Service ID NvM_WriteBlock() */
#endif
#ifndef NVM_RESTORE_BLOCK_DEFAULTS
#    define NVM_RESTORE_BLOCK_DEFAULTS (8u) /* Service ID NvM_RestoreBlockDefaults() */
#endif
#ifndef NVM_ERASE_BLOCK
#    define NVM_ERASE_BLOCK            (9u) /* Service ID NvM_EraseNvBlock() */
#endif
#ifndef NVM_INVALIDATE_NV_BLOCK
#    define NVM_INVALIDATE_NV_BLOCK   (11u) /* Service ID NvM_InvalidateNvBlock() */
#endif
#ifndef NVM_READ_ALL
#    define NVM_READ_ALL              (12u) /* Service ID NvM_ReadAll() */
#endif

/* Service Ids of the different service routines of the NVM
 * These sevice IDs should never be defined by the RTE. However, it doesn't hurt to protect them ... */

#ifndef NVM_INIT
#    define NVM_INIT                   (0u) /* Service ID NvM_Init() */
#endif
#ifndef NVM_SET_DATA_INDEX
#    define NVM_SET_DATA_INDEX         (1u) /* Service ID NvM_SetDataIndex() */
#endif
#ifndef NVM_GET_DATA_INDEX
#    define NVM_GET_DATA_INDEX         (2u) /* Service ID NvM_GetDataIndex() */
#endif
#ifndef NVM_SET_BLOCK_PROTECTION
#    define NVM_SET_BLOCK_PROTECTION   (3u) /* Service ID NvM_SetBlockProtection() */
#endif
#ifndef NVM_GET_ERROR_STATUS
#    define NVM_GET_ERROR_STATUS       (4u) /* Service ID NvM_GetErrorStatus() */
#endif
#ifndef NVM_SET_RAM_BLOCK_STATUS
#    define NVM_SET_RAM_BLOCK_STATUS   (5u) /* Service ID NvM_SetRamBlockStatus() */
#endif

#ifndef NVM_CANCEL_WRITE_ALL
#    define NVM_CANCEL_WRITE_ALL      (10u) /* Service ID NvM_CancelRequest() */
#endif

#ifndef NVM_WRITE_ALL
#    define NVM_WRITE_ALL             (13u) /* Service ID NvM_WriteAll() */
#endif
#ifndef NVM_MAINFUNCTION
#    define NVM_MAINFUNCTION          (14u) /* Service ID NvM_MainFunction() */
#endif
#ifndef NVM_GET_VERSION_INFO
#    define NVM_GET_VERSION_INFO      (15u) /* Service ID NvM_GetVersionInfo() */
#endif

#ifndef NVM_CANCEL_JOBS
#    define NVM_CANCEL_JOBS           (16u) /* Service ID NvM_CancelJobs() */
#endif
#ifndef NVM_SET_BLOCK_LOCK_STATUS
#   define NVM_SET_BLOCK_LOCK_STATUS (19u) /* Service ID NvM_SetBlockProtection() */
#endif
#ifndef NVM_KILL_WRITE_ALL
#   define NVM_KILL_WRITE_ALL        (20u) /* Service ID NvM_KillWriteAll() */
#endif

typedef enum
{
CRC_32 = 0,
CRC_16,
CRC_8,
}NvM_CrcEnumeration;

typedef enum
{
NVM_NATIVE_BLOCK = 0,
NVM_REDUNDANT_BLOCK,
NVM_DATASET_BLOCK
}NvM_BlockType;

#define MEMIF_FEE   0
#define MEMIF_EA    1


/* NvM Block specific Configuration */
typedef struct
{
  void (*InitCallback) (void);
  Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);
  uint8*    RamBlockDataAddress;
  uint8*    RomBlockDataAddress;
  uint16    NvBlockBaseNumber;
  uint16    NvBlockLength;
  uint16    NvRamBlockIdentifier;
  uint8     BlockJobPriority;
  uint8     MaxNumReadRetries;
  uint8     MaxNumWriteRetries;
  uint8     NvBlockNum;
  uint8     NvRamDeviceId;
  uint8     RomBlockNum;
  NvM_CrcEnumeration BlockCrcType;
  NvM_BlockType BlockManagementType;
  boolean   BlockUseCrc;
  boolean   BlockUseSetRamBlockStatus;
  boolean BlockWriteProt;
  boolean   BswMBlockStatusInformation;
  boolean   CalcRamBlockCrc;
  boolean   SelectBlockForReadAll;
  boolean   SelectBlockForWriteAll;
  boolean   WriteBlockOnce;
}NvM_BlockDescriptorType;


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


#endif /* NVM_TYPES_H */

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
