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
*  File Name         :  NvM.c                                                *
*  Module Short Name :  NvMMgr                                               *
*  VOBName           :                                                       *
*  Author            : vbalakr3                                              *
*  Description       : This file contains the NvM Manager Request handling   *
*                       functionalities and invokes Fee/Ea                    *
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
#ifndef NVM_C
#define NVM_C
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "NvM.h"
#include "NvM_Cbk.h"
#include "MemIf.h"
#include "NvM_Adapt.h"

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
#define NV_ERASE_BLOCK       0
#define NV_WRITE_BLOCK       1
#define NV_READ_BLOCK        2
#define NV_INVALIDATE_BLOCK  3

/*
#define NVM_JOB_STATE_IDLE          0x00
#define NVM_WRITE_REQUESTED     0x01
#define NVM_READ_REQUESTED      0x02
#define NVM_READ_ALL_IN_PROCESS 0x03
#define NVM_ERASE_REQUESTED     0x04
*/




/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

typedef enum
{
  NVM_STATE_UNINIT=0,
  NVM_STATE_IDLE,
  NVM_STATE_WRITE_BLOCK,
  NVM_STATE_READ_BLOCK,
  NVM_STATE_WRITE_ALL,
  NVM_STATE_READ_ALL,
  NVM_STATE_INVALIDATE
}NvM_StatusType;

typedef enum
{
  NVM_JOB_STATE_IDLE=0,
  NVM_JOB_STATE_WRITE,
  NVM_JOB_STATE_READ,
  NVM_JOB_STATE_INVALIDATE
}NvM_JobStateType;


typedef enum
{
  NVM_JOB_SUBSTATE_IDLE = 0,
  NVM_JOB_SUBSTATE_WRITE_CRC_CALC,
  NVM_JOB_SUBSTATE_WRITE,
  NVM_JOB_SUBSTATE_WRITE_WAIT,
  NVM_JOB_SUBSTATE_VERIFY_READ,
  NVM_JOB_SUBSTATE_VERIFY_READ_WAIT,
  NVM_JOB_SUBSTATE_READ,
  NVM_JOB_SUBSTATE_READ_WAIT,
  NVM_JOB_SUBSTATE_READ_CRC_CALC,
  NVM_JOB_SUBSTATE_READ_CRC_VALIDATE,
  NVM_JOB_SUBSTATE_INVALIDATE,
  NVM_JOB_SUBSTATE_INVALIDATE_CBK_WAIT
}NvM_JobSubStateType;


/* NvM Queue management data structure */
typedef struct
{
  uint8* DataPointer;
  uint16 ReadLength;
  uint16 BlockId;
  uint16 BlockOffset;
  uint8  RequestType;
}NvM_QueueType;

/* NvM Immediate Queue Parameters */
typedef struct
{
   uint8 CurrentQueueIndex;
   uint8 CurrentQueueSize;
}NvM_ImmediateQueueType;


/* NvM Standard Queue Parameters */
typedef struct
{
   uint8 CurrentQueueIndex;
   uint8 CurrentQueueSize;
   uint8 RequestQueueIndex;
}NvM_StandardQueueType;


/* Ongoing Job variables */
typedef struct
{
  uint8* RamBuffer;
  uint16 BlockId;
  uint16 BlockOffset;
  uint16 NvDescriptor;
  uint16 ReadLength;
  uint8  RequestType;
  uint8  WriteRetryCount;
  uint8  ReadRetryCount;
  NvM_RequestResultType JobStatus;
  NvM_JobStateType JobState;
  NvM_JobSubStateType JobSubState;
  boolean ProcessState;
}NvM_CurrJobType;


/* Blcok Status Variable */
typedef struct
{
  uint8   BlockProcessStatus;
  uint8   DataSetIndex;
  boolean BlockModifiedStatus;
  boolean BlockValidStatus;
  boolean BlockWriteProt;
  boolean BlockLockedStatus;
}NvM_AdminBlockType;


/* NvM Handling Variables */
typedef struct
{
  uint16 ApiFlags;
  NvM_StatusType NvMState;
  boolean ReadAllRequest;
  boolean WriteAllRequest;
  uint8 WriteVerificationBuffer[NVM_WRITE_VERIFICATION_DATASIZE];
}NvM_DataStructType;

typedef struct
{
  uint8*  DataPtr;
  uint32  Length;
  uint32  CrcValue;
  boolean IsFirstCall;
}NvM_CrcStructType;

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

static NvM_AdminBlockType NvM_AdminBlock[NVM_NUM_OF_BLOCKS+1];

static NvM_CurrJobType NvM_CurrentJob;

static NvM_DataStructType NvM_DataStruct;

static NvM_QueueType NvM_ImmediateJobQueue[IMMEDIATE_JOB_QUEUE_SIZE];

static NvM_QueueType NvM_StandardJobQueue[STANDARD_JOB_QUEUE_SIZE];

static NvM_CrcStructType NvM_CrcStruct;


static NvM_ImmediateQueueType NvM_ImmediateQueueParameter;

static NvM_StandardQueueType  NvM_StandardQueueParameter;

static uint8 NvM_WriteVerificationBuffer[NVM_WRITE_VERIFICATION_DATASIZE];

/*****************************************************************************
*                              Limited Scope Prototypes                      *
******************************************************************************/
static NvM_RequestResultType NvM_GetJobResult(void);

static Std_ReturnType NvM_WriteVerifyReadData(void);

static void NvM_ProcessJobSubState(void);

static void NvM_InitRead(void);
static void NvM_ReadCbkWait(void);
static void NvM_ReadCrcCalculate(void);
static void NvM_ReadCrcValidate(void);
static void NvM_ProcessReadAll(void);

static void NvM_CheckNewRequest(void);

static void NvM_WriteCrcCalculate(void);
static void NvM_InitWrite(void);
static void NvM_WriteCbkWait(void);
static void NvM_WriteVerify(void);
static void NvM_WriteVerifyCbkWait(void);
static void NvM_ProcessWriteAll(void);

static void NvM_InitInvalidateBlock(void);
static void NvM_InitInvalidateBlockCbkWait(void);

/*****************************************************************************
*                   Functions                                                *
******************************************************************************/

/**************************************************************************
Function name   : void NvM_Init(void)
Arguments       : void
Return type     : void
Description     : This function is called by App/Scheduler when there is an
                  init required.
**************************************************************************/
void NvM_Init(void)
{
  uint8 fl_iteration;
  NvM_DataStruct.NvMState = NVM_STATE_UNINIT;
  /* NvM Admin block initialisation */
  for(fl_iteration=0; fl_iteration< (NVM_NUM_OF_BLOCKS+1); fl_iteration++)
  {
    NvM_AdminBlock[fl_iteration].BlockModifiedStatus = 0;
    NvM_AdminBlock[fl_iteration].BlockProcessStatus = 0;
    NvM_AdminBlock[fl_iteration].BlockValidStatus = 0;
    if(NvM_BlockConfig[fl_iteration].WriteBlockOnce == TRUE)
    {
      NvM_AdminBlock[fl_iteration].BlockWriteProt = FALSE;
    }
    else
    {
      NvM_AdminBlock[fl_iteration].BlockWriteProt = NvM_BlockConfig[fl_iteration].BlockWriteProt;
    }
    NvM_AdminBlock[fl_iteration].DataSetIndex = 0;
  }
  /* Current Job structure initialise */
  NvM_CurrentJob.BlockId = 0;
  NvM_CurrentJob.BlockOffset = 0;
  NvM_CurrentJob.NvDescriptor = 0;
  NvM_CurrentJob.RamBuffer = 0;
  NvM_CurrentJob.ReadLength = 0;
  NvM_CurrentJob.RequestType = 0;

  /* NvM handling data structure initialise */
  NvM_DataStruct.ApiFlags = 0;
//  NvM_DataStruct.JobState = NVM_JOB_STATE_IDLE;

  /* Immediate queue initialisation */
  for(fl_iteration=0; fl_iteration< IMMEDIATE_JOB_QUEUE_SIZE; fl_iteration++)
  {
    NvM_ImmediateJobQueue[fl_iteration].BlockId = 0;
    NvM_ImmediateJobQueue[fl_iteration].BlockOffset = 0;
    NvM_ImmediateJobQueue[fl_iteration].DataPointer = 0;
    NvM_ImmediateJobQueue[fl_iteration].ReadLength = 0;
    NvM_ImmediateJobQueue[fl_iteration].RequestType = 0;
  }

  /* Standard queue initialisation */

  for(fl_iteration=0; fl_iteration< STANDARD_JOB_QUEUE_SIZE; fl_iteration++)
  {
    NvM_StandardJobQueue[fl_iteration].BlockId = 0;
    NvM_StandardJobQueue[fl_iteration].BlockOffset = 0;
    NvM_StandardJobQueue[fl_iteration].DataPointer = 0;
    NvM_StandardJobQueue[fl_iteration].ReadLength = 0;
    NvM_StandardJobQueue[fl_iteration].RequestType = 0;
  }

  /* Immediate queue parameter init */
  NvM_ImmediateQueueParameter.CurrentQueueIndex = 0;
  NvM_ImmediateQueueParameter.CurrentQueueSize = 0;

  /* Standard queue Parameter init */
  NvM_StandardQueueParameter.CurrentQueueIndex = 0;
  NvM_StandardQueueParameter.CurrentQueueSize = 0;
  NvM_StandardQueueParameter.RequestQueueIndex = 0;

  NvM_CrcStruct.DataPtr = NULL;
  NvM_CrcStruct.Length = 0;
  NvM_CrcStruct.CrcValue = 0xFFFF;
  NvM_CrcStruct.IsFirstCall = TRUE;



  Fee_Init();

  NvM_DataStruct.NvMState = NVM_STATE_IDLE;

}

/**************************************************************************
Function name   : Std_ReturnType NvM_SetDataIndex(NvM_BlockIdType BlockId, uint8 DataIndex)
Arguments       : void
Return type     : void
Description     : This function is used to set the Data set index of the DatasetBlock
**************************************************************************/
Std_ReturnType NvM_SetDataIndex(NvM_BlockIdType BlockId, uint8 DataIndex)
{
  #ifndef COMPILER_WARNING_TEMP_FIX
  if(NvM_ImmediateJobQueue[0].BlockId == 0xFFFF)
  {
    NvM_ImmediateJobQueue[0].RequestType = NvM_AdminBlock[0].DataSetIndex;
    NvM_AdminBlock[0].DataSetIndex = NvM_ImmediateQueueParameter.CurrentQueueSize;
  }
  #endif
  return E_OK;
}


/**************************************************************************
Function name   : Std_ReturnType NvM_GetDataIndex( NvM_BlockIdType BlockId, uint8* DataIndexPtr)
Arguments       : NvM_BlockIdType BlockId, uint8* DataIndexPtr
Return type     : Std_ReturnType
                  E_OK: The index position has been retrieved successfully.
                  E_NOT_OK: An error occurred
Description     : Service for getting the currently set DataIndex of a dataset NVRAM block
**************************************************************************/
Std_ReturnType NvM_GetDataIndex( NvM_BlockIdType BlockId, uint8* DataIndexPtr)
{
  return E_OK;
}

/**************************************************************************
Function name   : Std_ReturnType NvM_SetBlockProtection(NvM_BlockIdType BlockId, boolean ProtectionEnabled)
Arguments       : NvM_BlockIdType BlockId, boolean ProtectionEnabled
Return type     : Std_ReturnType
                  E_OK: The block was enabled/disabled as requested
                  E_NOT_OK: An error occured
Description     : Service for setting/resetting the write protection for a NV block
**************************************************************************/
Std_ReturnType NvM_SetBlockProtection(NvM_BlockIdType BlockId, boolean ProtectionEnabled)
{
  Std_ReturnType fl_RetVal;
  fl_RetVal = E_OK;
  if(NvM_BlockConfig[BlockId].WriteBlockOnce == TRUE)
  {
    fl_RetVal = E_NOT_OK;
  }
  if(NvM_DataStruct.NvMState == NVM_STATE_UNINIT)
  {
    fl_RetVal = E_NOT_OK;
  }
  if(fl_RetVal == E_OK)
  {
    NvM_AdminBlock[BlockId].BlockWriteProt = ProtectionEnabled;
  }
  return fl_RetVal;
}

/**************************************************************************
Function name   : Std_ReturnType NvM_GetErrorStatus( NvM_BlockIdType BlockId, NvM_RequestResultType* RequestResultPtr)
Arguments       : NvM_BlockIdType BlockId, NvM_RequestResultType* RequestResultPtr
Return type     : Std_ReturnType
                  E_OK: The block dependent error/status information was read successfully.
                  E_NOT_OK: An error occured.
Description     : Service to read the block dependent error/status information
**************************************************************************/
Std_ReturnType NvM_GetErrorStatus( NvM_BlockIdType BlockId, NvM_RequestResultType* RequestResultPtr)
{
  Std_ReturnType fl_RetVal;
  fl_RetVal = E_OK;
  if(NvM_DataStruct.NvMState == NVM_STATE_UNINIT)
  {
    fl_RetVal = E_NOT_OK;
  }
  if(fl_RetVal == E_OK)
  {
    *RequestResultPtr = NvM_AdminBlock[BlockId].BlockProcessStatus;
  }
  return fl_RetVal;
  }

/**************************************************************************
Function name   : void NvM_GetVersionInfo( Std_VersionInfoType* versioninfo)
Arguments       : Std_VersionInfoType* versioninfo
Return type     : void
Description     : Service to get the version information of the NvM module.
**************************************************************************/
void NvM_GetVersionInfo( Std_VersionInfoType* versioninfo)
{
}

/**************************************************************************
Function name   : Std_ReturnType NvM_SetRamBlockStatus( NvM_BlockIdType BlockId, boolean BlockChanged)
Arguments       : NvM_BlockIdType BlockId, boolean BlockChanged
Return type     : Std_ReturnType
                  E_OK: The status of the RAM-Block was changed as requested.
                  E_NOT_OK: An error occurred.
Description     : Service for setting the RAM block status of an NVRAM block.
**************************************************************************/
Std_ReturnType NvM_SetRamBlockStatus( NvM_BlockIdType BlockId, boolean BlockChanged)
{
  Std_ReturnType fl_RetVal;
  fl_RetVal = E_OK;
  if(NvM_DataStruct.NvMState == NVM_STATE_UNINIT)
  {
    fl_RetVal = E_NOT_OK;
  }
  if(fl_RetVal == E_OK)
  {
    if(FALSE != BlockChanged)
    {
        NvM_AdminBlock[BlockId].BlockModifiedStatus = BlockChanged;

    }
    else
    {
    }
    NvM_AdminBlock[BlockId].BlockModifiedStatus = BlockChanged;
  }
  return fl_RetVal;
}

/**************************************************************************
Function name   : void NvM_SetBlockLockStatus( NvM_BlockIdType BlockId, boolean BlockLocked)
Arguments       : NvM_BlockIdType BlockId, boolean BlockLocked
Return type     : void
Description     : Service for setting the lock status of a permanent RAM block or of the explicit
                  synchronization of a NVRAM block.
**************************************************************************/
void NvM_SetBlockLockStatus( NvM_BlockIdType BlockId, boolean BlockLocked)
{
    NvM_AdminBlock[BlockId].BlockLockedStatus = BlockLocked;
}

/**************************************************************************
Function name   : Std_ReturnType NvM_CancelJobs( NvM_BlockIdType BlockId)
Arguments       : NvM_BlockIdType BlockId
Return type     : Std_ReturnType
                  E_OK: The job was successfully removed from queue.
                  E_NOT_OK: The job could not be found in the queue.
Description     : Service to cancel all jobs pending for a NV block.
***********************************************************************/
Std_ReturnType NvM_CancelJobs( NvM_BlockIdType BlockId)
{
  return E_OK;
}


/**************************************************************************
Function name   : Std_ReturnType NvM_ReadBlock( NvM_BlockIdType BlockId,void* NvM_DstPtr)
Arguments       : NvM_BlockIdType BlockId,void* NvM_DstPtr
Return type     : Std_ReturnType
                   E_OK: request has been accepted
                   E_NOT_OK: request has not been accepted
Description     : Service to copy the data of the NV block to its corresponding RAM block
***********************************************************************/
Std_ReturnType NvM_ReadBlock( NvM_BlockIdType BlockId,void* NvM_DstPtr)
{
  Std_ReturnType NvM_RetVal;
  NvM_EnterCriticalSection();
  if(NvM_StandardQueueParameter.CurrentQueueSize >= STANDARD_JOB_QUEUE_SIZE)
  {
    NvM_AdminBlock[BlockId].BlockProcessStatus = NVM_REQ_NOT_OK;
    NvM_RetVal = E_NOT_OK;
  }
  else
  {
    NvM_StandardQueueParameter.CurrentQueueSize+=1;
    NvM_StandardJobQueue[NvM_StandardQueueParameter.RequestQueueIndex].BlockId = BlockId;
    NvM_StandardJobQueue[NvM_StandardQueueParameter.RequestQueueIndex].RequestType = NV_READ_BLOCK;
    NvM_StandardJobQueue[NvM_StandardQueueParameter.RequestQueueIndex].ReadLength = NvM_BlockConfig[BlockId].NvBlockLength;
    if(NvM_DstPtr == NULL)
    {
      NvM_StandardJobQueue[NvM_StandardQueueParameter.RequestQueueIndex].DataPointer = NvM_BlockConfig[BlockId].RamBlockDataAddress;
    }
    else
    {
      NvM_StandardJobQueue[NvM_StandardQueueParameter.RequestQueueIndex].DataPointer = (uint8*)NvM_DstPtr;
    }

    NvM_StandardQueueParameter.RequestQueueIndex+=1;
    if(NvM_StandardQueueParameter.RequestQueueIndex >= STANDARD_JOB_QUEUE_SIZE)
    {
      NvM_StandardQueueParameter.RequestQueueIndex = 0;
    }
    NvM_AdminBlock[BlockId].BlockProcessStatus = NVM_REQ_PENDING;
    NvM_RetVal = E_OK;
  }
  NvM_ExitCriticalSection();
  return NvM_RetVal;
}

/**************************************************************************
Function name   : Std_ReturnType NvM_WriteBlock(NvM_BlockIdType BlockId, const void* NvM_SrcPtr)
Arguments       : NvM_BlockIdType BlockId, const void* NvM_SrcPtr
Return type     : Std_ReturnType
                   E_OK: request has been accepted
                   E_NOT_OK: request has not been accepted
Description     : Service to copy the data of the RAM block to its corresponding NV block.
***********************************************************************/
Std_ReturnType NvM_WriteBlock(NvM_BlockIdType BlockId, const void* NvM_SrcPtr)
{
  Std_ReturnType NvM_RetVal;
  NvM_EnterCriticalSection();
  if(FALSE != NvM_AdminBlock[BlockId].BlockWriteProt)
  {
    NvM_AdminBlock[BlockId].BlockProcessStatus = NVM_REQ_NOT_OK;
    NvM_RetVal = E_NOT_OK;
  }
  else if(FALSE != NvM_AdminBlock[BlockId].BlockLockedStatus)
  {
    NvM_AdminBlock[BlockId].BlockProcessStatus = NVM_REQ_NOT_OK;
    NvM_RetVal = E_NOT_OK;
  }
  else if(NvM_StandardQueueParameter.CurrentQueueSize >= STANDARD_JOB_QUEUE_SIZE)
  {
    NvM_AdminBlock[BlockId].BlockProcessStatus = NVM_REQ_NOT_OK;
    NvM_RetVal = E_NOT_OK;
  }
  else
  {
    NvM_StandardQueueParameter.CurrentQueueSize+=1;
    NvM_StandardJobQueue[NvM_StandardQueueParameter.RequestQueueIndex].BlockId = BlockId;
    NvM_StandardJobQueue[NvM_StandardQueueParameter.RequestQueueIndex].RequestType = NV_WRITE_BLOCK;
    NvM_StandardJobQueue[NvM_StandardQueueParameter.RequestQueueIndex].ReadLength = NvM_BlockConfig[BlockId].NvBlockLength;
    if(NvM_SrcPtr == NULL)
    {
      NvM_StandardJobQueue[NvM_StandardQueueParameter.RequestQueueIndex].DataPointer = NvM_BlockConfig[BlockId].RamBlockDataAddress;
    }
    else
    {
      NvM_StandardJobQueue[NvM_StandardQueueParameter.RequestQueueIndex].DataPointer = (uint8*)NvM_SrcPtr;
    }

    NvM_StandardQueueParameter.RequestQueueIndex+=1;
    if(NvM_StandardQueueParameter.RequestQueueIndex >= STANDARD_JOB_QUEUE_SIZE)
    {
      NvM_StandardQueueParameter.RequestQueueIndex= 0;
    }
    NvM_AdminBlock[BlockId].BlockProcessStatus = NVM_REQ_PENDING;
    NvM_RetVal = E_OK;
  }
  NvM_ExitCriticalSection();
  return NvM_RetVal;
}

/**************************************************************************
Function name   : Std_ReturnType NvM_RestoreBlockDefaults( NvM_BlockIdType BlockId, void* NvM_DestPtr)
Arguments       : NvM_BlockIdType BlockId, void* NvM_DestPtr
Return type     : Std_ReturnType
                   E_OK: request has been accepted
                   E_NOT_OK: request has not been accepted
Description     : Service to restore the default data to its corresponding RAM block
***********************************************************************/
Std_ReturnType NvM_RestoreBlockDefaults( NvM_BlockIdType BlockId, void* NvM_DestPtr)
{
	return E_NOT_OK;
}

/**************************************************************************
Function name   : Std_ReturnType NvM_EraseNvBlock(NvM_BlockIdType BlockId)
Arguments       : NvM_BlockIdType BlockId
Return type     : Std_ReturnType
                   E_OK: request has been accepted
                   E_NOT_OK: request has not been accepted
Description     : Service to erase a NV block.
***********************************************************************/
Std_ReturnType NvM_EraseNvBlock(NvM_BlockIdType BlockId)
{
  return E_OK;
}

/**************************************************************************
Function name   : void NvM_CancelWriteAll(void)
Arguments       : void
Return type     : void
Description     : Service to cancel a running NvM_WriteAll request.
***********************************************************************/
void NvM_CancelWriteAll(void)
{
  NvM_DataStruct.WriteAllRequest =  FALSE;
}

/**************************************************************************
Function name   : Std_ReturnType NvM_InvalidateNvBlock(NvM_BlockIdType BlockId)
Arguments       : NvM_BlockIdType BlockId
Return type     : Std_ReturnType
                   E_OK: request has been accepted
                   E_NOT_OK: request has not been accepted
Description     : Service to invalidate a NV block.
***********************************************************************/
Std_ReturnType NvM_InvalidateNvBlock(NvM_BlockIdType BlockId)
{
  Std_ReturnType NvM_RetVal;
  NvM_EnterCriticalSection();
  if(FALSE != NvM_AdminBlock[BlockId].BlockWriteProt)
  {
    NvM_AdminBlock[BlockId].BlockProcessStatus = NVM_REQ_NOT_OK;
    NvM_RetVal = E_NOT_OK;
  }
  else if(FALSE != NvM_AdminBlock[BlockId].BlockLockedStatus)
  {
    NvM_AdminBlock[BlockId].BlockProcessStatus = NVM_REQ_NOT_OK;
    NvM_RetVal = E_NOT_OK;
  }

  else if(NvM_StandardQueueParameter.CurrentQueueSize >= STANDARD_JOB_QUEUE_SIZE)
  {
    NvM_AdminBlock[BlockId].BlockProcessStatus = NVM_REQ_NOT_OK;
    NvM_RetVal = E_NOT_OK;
  }
  else
  {
    NvM_StandardQueueParameter.CurrentQueueSize+=1;
    NvM_StandardQueueParameter.RequestQueueIndex+=1;
    if(NvM_StandardQueueParameter.RequestQueueIndex >= STANDARD_JOB_QUEUE_SIZE)
    {
      NvM_StandardQueueParameter.RequestQueueIndex= 0;
    }
    NvM_StandardJobQueue[NvM_StandardQueueParameter.RequestQueueIndex].BlockId = BlockId;
    NvM_StandardJobQueue[NvM_StandardQueueParameter.RequestQueueIndex].RequestType = NV_INVALIDATE_BLOCK;
    NvM_StandardJobQueue[NvM_StandardQueueParameter.RequestQueueIndex].DataPointer = NvM_BlockConfig[BlockId].RamBlockDataAddress;

    NvM_AdminBlock[BlockId].BlockProcessStatus = NVM_REQ_PENDING;
    NvM_RetVal = E_OK;
  }
  NvM_ExitCriticalSection();
  return NvM_RetVal;

}

/**************************************************************************
Function name   : Std_ReturnType NvM_ReadPRAMBlock(NvM_BlockIdType BlockId)
Arguments       : NvM_BlockIdType BlockId
Return type     : Std_ReturnType
                   E_OK: request has been accepted
                   E_NOT_OK: request has not been accepted
Description     : Service to copy the data of the NV block to its corresponding
                  permanent RAM block.
***********************************************************************/
Std_ReturnType NvM_ReadPRAMBlock(NvM_BlockIdType BlockId)
{
  Std_ReturnType NvM_RetVal;
  NvM_EnterCriticalSection();
  if(NvM_BlockConfig[BlockId].RamBlockDataAddress == NULL)
  {
    NvM_AdminBlock[BlockId].BlockProcessStatus = NVM_REQ_NOT_OK;
    NvM_RetVal = E_NOT_OK;
  }
  else
  {
    if(NvM_StandardQueueParameter.CurrentQueueSize >= STANDARD_JOB_QUEUE_SIZE)
    {
      NvM_AdminBlock[BlockId].BlockProcessStatus = NVM_REQ_NOT_OK;
      NvM_RetVal = E_NOT_OK;
    }
    else
    {
      NvM_StandardQueueParameter.CurrentQueueSize+=1;
      NvM_StandardJobQueue[NvM_StandardQueueParameter.RequestQueueIndex].BlockId = BlockId;
      NvM_StandardJobQueue[NvM_StandardQueueParameter.RequestQueueIndex].RequestType = NV_READ_BLOCK;
      NvM_StandardJobQueue[NvM_StandardQueueParameter.RequestQueueIndex].DataPointer = NvM_BlockConfig[BlockId].RamBlockDataAddress;
      NvM_StandardJobQueue[NvM_StandardQueueParameter.RequestQueueIndex].ReadLength = NvM_BlockConfig[BlockId].NvBlockLength;
      NvM_RetVal = E_OK;
      NvM_StandardQueueParameter.RequestQueueIndex+=1;
      if(NvM_StandardQueueParameter.RequestQueueIndex >= STANDARD_JOB_QUEUE_SIZE)
      {
        NvM_StandardQueueParameter.RequestQueueIndex = 0;
      }
      NvM_AdminBlock[BlockId].BlockProcessStatus = NVM_REQ_PENDING;
    }
  }
  NvM_ExitCriticalSection();
  return NvM_RetVal;
}

/**************************************************************************
Function name   : Std_ReturnType NvM_WritePRAMBlock(NvM_BlockIdType BlockId)
Arguments       : NvM_BlockIdType BlockId
Return type     : Std_ReturnType
                   E_OK: request has been accepted
                   E_NOT_OK: request has not been accepted
Description     : Service to copy the data of the RAM block to its corresponding
                  permanent RAM Block
***********************************************************************/
Std_ReturnType NvM_WritePRAMBlock(NvM_BlockIdType BlockId)
{
  Std_ReturnType NvM_RetVal;
  NvM_EnterCriticalSection();
  if(NvM_BlockConfig[BlockId].RamBlockDataAddress == NULL)
  {
    NvM_AdminBlock[BlockId].BlockProcessStatus = NVM_REQ_NOT_OK;
    NvM_RetVal = E_NOT_OK;
  }
  else
  {
    if(NvM_StandardQueueParameter.CurrentQueueSize >= STANDARD_JOB_QUEUE_SIZE)
    {
      NvM_AdminBlock[BlockId].BlockProcessStatus = NVM_REQ_NOT_OK;
      NvM_RetVal = E_NOT_OK;
    }
    else
    {
	  NvM_StandardQueueParameter.CurrentQueueSize+=1;
      NvM_StandardJobQueue[NvM_StandardQueueParameter.RequestQueueIndex].BlockId = BlockId;
      NvM_StandardJobQueue[NvM_StandardQueueParameter.RequestQueueIndex].RequestType = NV_WRITE_BLOCK;
      NvM_StandardJobQueue[NvM_StandardQueueParameter.RequestQueueIndex].DataPointer = NvM_BlockConfig[BlockId].RamBlockDataAddress;
      NvM_StandardJobQueue[NvM_StandardQueueParameter.RequestQueueIndex].ReadLength = NvM_BlockConfig[BlockId].NvBlockLength;
      NvM_RetVal = E_OK;
      NvM_StandardQueueParameter.RequestQueueIndex+=1;
      if(NvM_StandardQueueParameter.RequestQueueIndex >= STANDARD_JOB_QUEUE_SIZE)
	  {
	    NvM_StandardQueueParameter.RequestQueueIndex = 0;
	  }
      NvM_AdminBlock[BlockId].BlockProcessStatus = NVM_REQ_PENDING;
    }
  }
  NvM_ExitCriticalSection();
  return NvM_RetVal;
}

/**************************************************************************
Function name   : Std_ReturnType NvM_RestorePRAMBlockDefaults(NvM_BlockIdType BlockId)
Arguments       : NvM_BlockIdType BlockId
Return type     : Std_ReturnType
                   E_OK: request has been accepted
                   E_NOT_OK: request has not been accepted
Description     : Service to restore the default data to its corresponding permanent RAM block.
***********************************************************************/
Std_ReturnType NvM_RestorePRAMBlockDefaults(NvM_BlockIdType BlockId)
{
  uint8 *SrcPtr = NvM_BlockConfig[BlockId].RomBlockDataAddress;
  uint8 *DestPtr = NvM_BlockConfig[BlockId].RamBlockDataAddress;
  uint16 length = NvM_BlockConfig[BlockId].NvBlockLength;
  uint16 fl_temp;

  if((SrcPtr != NULL) && (DestPtr != NULL))
  {
	  for(fl_temp = 0; fl_temp< length; fl_temp++)
	  {
	    *DestPtr = *SrcPtr;
	    DestPtr++;
	    SrcPtr++;
	  }
  }
  return E_OK;
}

/**************************************************************************
Function name   : void NvM_ReadAll(void)
Arguments       : void
Return type     : void
Description     : Initiates a multi block read request.
***********************************************************************/
void NvM_ReadAll(void)
{
  NvM_DataStruct.ReadAllRequest = TRUE;
}

/**************************************************************************
Function name   : void NvM_WriteAll(void)
Arguments       : void
Return type     : void
Description     : Initiates a multi block write request.
***********************************************************************/
void NvM_WriteAll(void)
{
  NvM_DataStruct.WriteAllRequest = TRUE;
}

/**************************************************************************
Function name   : void NvM_ValidateAll(void)
Arguments       : void
Return type     : void
Description     : Initiates a multi block validation request
***********************************************************************/
void NvM_ValidateAll(void)
{
}

/**************************************************************************
Function name   : void NvM_JobEndNotification(void)
Arguments       : void
Return type     : void
Description     : Function to be used by the underlying memory abstraction
                  to signal end of job without error
***********************************************************************/
void NvM_JobEndNotification(void)
{
  NvM_RequestResultType fl_RequestResult;
  fl_RequestResult = NvM_GetJobResult();
  NvM_CurrentJob.JobStatus = fl_RequestResult;
  NvM_AdminBlock[NvM_CurrentJob.BlockId].BlockProcessStatus = fl_RequestResult;
}

/**************************************************************************
Function name   : void NvM_JobErrorNotification(void)
Arguments       : void
Return type     : void
Description     : Function to be used by the underlying memory abstraction
                  to signal end of job with error
***********************************************************************/
void NvM_JobErrorNotification(void)
{
  NvM_RequestResultType fl_RequestResult;
  fl_RequestResult = NvM_GetJobResult();
  NvM_CurrentJob.JobStatus = fl_RequestResult;
  NvM_AdminBlock[NvM_CurrentJob.BlockId].BlockProcessStatus = fl_RequestResult;
}

/**************************************************************************
Function name   : void NvM_JobErrorNotification(void)
Arguments       : void
Return type     : NvM_RequestResultType
Description     : Function to get the job result
***********************************************************************/
static NvM_RequestResultType NvM_GetJobResult(void)
{
  MemIf_JobResultType fl_JobResult;
  NvM_RequestResultType fl_RetVal;
  if(NvM_BlockConfig[NvM_CurrentJob.BlockId].NvRamDeviceId == MEMIF_FEE)
  {
    fl_JobResult = MEMIF_FEE_GET_JOB_RESULT();
  }
  else
  {
    fl_JobResult = MEMIF_EA_GET_JOB_RESULT();
  }

  switch(fl_JobResult)
  {
    case MEMIF_JOB_PENDING:
    fl_RetVal = NVM_REQ_PENDING;
    break;

    case MEMIF_JOB_OK:
    fl_RetVal = NVM_REQ_OK;
    break;

    case MEMIF_JOB_FAILED:
    fl_RetVal = NVM_REQ_NOT_OK;
    break;

    case MEMIF_BLOCK_INVALID:
    fl_RetVal = NVM_REQ_NV_INVALIDATED;
    break;

    case MEMIF_BLOCK_INCONSISTENT:
    fl_RetVal = NVM_REQ_INTEGRITY_FAILED;
    break;

    default:
    fl_RetVal = NVM_REQ_NOT_OK;
    break;
  }
  return fl_RetVal;
}


/**************************************************************************
Function name   : void NvM_MainFunction(void)
Arguments       : void
Return type     : void
Description     : Service for performing the processing of the NvM jobs.
***********************************************************************/
void NvM_MainFunction(void)
{
  NvM_CheckNewRequest();
  do
  {
      NvM_ProcessJobSubState();
  }while(FALSE != NvM_CurrentJob.ProcessState);
}

/**************************************************************************
Function name   : void NvM_CheckNewRequest(void)
Arguments       : void
Return type     : void
Description     : Check the New Request
**************************************************************************/
static void NvM_CheckNewRequest(void)
{
  if((MEMIF_IDLE == MEMIF_FEE_GET_STATUS()) && (MEMIF_IDLE == MEMIF_EA_GET_STATUS()))
  {
    if(NvM_DataStruct.NvMState == NVM_STATE_IDLE)
    {
      if(NvM_StandardQueueParameter.CurrentQueueSize > 0)
      {
        NvM_CurrentJob.BlockId = NvM_StandardJobQueue[NvM_StandardQueueParameter.CurrentQueueIndex].BlockId;
        NvM_CurrentJob.BlockOffset = NvM_StandardJobQueue[NvM_StandardQueueParameter.CurrentQueueIndex].BlockOffset;
        NvM_CurrentJob.RamBuffer = NvM_StandardJobQueue[NvM_StandardQueueParameter.CurrentQueueIndex].DataPointer;
        NvM_CurrentJob.ReadLength = NvM_StandardJobQueue[NvM_StandardQueueParameter.CurrentQueueIndex].ReadLength;
        NvM_CurrentJob.RequestType = NvM_StandardJobQueue[NvM_StandardQueueParameter.CurrentQueueIndex].RequestType;
        NvM_CurrentJob.WriteRetryCount = NvM_BlockConfig[NvM_CurrentJob.BlockId].MaxNumWriteRetries+1;
        NvM_CurrentJob.ReadRetryCount = NvM_BlockConfig[NvM_CurrentJob.BlockId].MaxNumReadRetries+1;

        NvM_EnterCriticalSection();
        NvM_StandardQueueParameter.CurrentQueueSize =NvM_StandardQueueParameter.CurrentQueueSize - 1;
        NvM_ExitCriticalSection();

        NvM_StandardQueueParameter.CurrentQueueIndex+=1;

        if(NvM_StandardQueueParameter.CurrentQueueIndex >= STANDARD_JOB_QUEUE_SIZE)
        {
            NvM_StandardQueueParameter.CurrentQueueIndex = 0;
        }
        switch(NvM_CurrentJob.RequestType)
        {
          case NV_WRITE_BLOCK:
          NvM_DataStruct.NvMState = NVM_STATE_WRITE_BLOCK;
          NvM_CurrentJob.JobState = NVM_JOB_STATE_WRITE;
          NvM_CrcStruct.IsFirstCall = TRUE;
          NvM_CrcStruct.DataPtr =  NvM_CurrentJob.RamBuffer;
          NvM_CrcStruct.Length =  NvM_BlockConfig[NvM_CurrentJob.BlockId].NvBlockLength - NVM_CRC_BYTES;
          NvM_CrcStruct.CrcValue = 0xFFFF;
          //NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_WRITE_CRC_CALC;
		      NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_WRITE;
          NvM_CurrentJob.ProcessState = TRUE;
          break;

          case NV_READ_BLOCK:
          NvM_DataStruct.NvMState = NVM_STATE_READ_BLOCK;
          NvM_CurrentJob.JobState = NVM_JOB_STATE_READ;
          NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_READ;
          NvM_CurrentJob.ProcessState = TRUE;
          break;

          case NV_INVALIDATE_BLOCK:
          NvM_DataStruct.NvMState = NVM_STATE_INVALIDATE;
          NvM_CurrentJob.JobState = NVM_JOB_STATE_INVALIDATE;
          NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_INVALIDATE;
          NvM_CurrentJob.ProcessState = TRUE;
          break;


          default:
          break;
        }
      }
      else
      {
        if(NvM_DataStruct.WriteAllRequest == TRUE)
        {
          NvM_CurrentJob.BlockId = 2;
          NvM_CurrentJob.BlockOffset = 0;
          NvM_CurrentJob.RamBuffer = NvM_BlockConfig[NvM_CurrentJob.BlockId].RamBlockDataAddress;
          NvM_CurrentJob.ReadLength = NvM_BlockConfig[NvM_CurrentJob.BlockId].NvBlockLength;
          NvM_CurrentJob.RequestType = NVM_WRITE_ALL;
          NvM_CurrentJob.WriteRetryCount = NvM_BlockConfig[NvM_CurrentJob.BlockId].MaxNumWriteRetries+1;
          NvM_CurrentJob.ReadRetryCount = NvM_BlockConfig[NvM_CurrentJob.BlockId].MaxNumReadRetries+1;
          NvM_DataStruct.NvMState = NVM_STATE_WRITE_ALL;
          NvM_CurrentJob.JobState = NVM_JOB_STATE_WRITE;
          NvM_CrcStruct.IsFirstCall = TRUE;
          NvM_CrcStruct.DataPtr =  NvM_CurrentJob.RamBuffer;
          NvM_CrcStruct.Length =  NvM_CurrentJob.ReadLength - NVM_CRC_BYTES;
          NvM_CrcStruct.CrcValue = 0xFFFF;
          //NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_WRITE_CRC_CALC;
		      NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_WRITE;
          NvM_CurrentJob.ProcessState = TRUE;
        }
        else
        {
          if(NvM_DataStruct.ReadAllRequest == TRUE)
          {
            NvM_CurrentJob.BlockId = 2;
            NvM_CurrentJob.BlockOffset = 0;
            NvM_CurrentJob.RamBuffer = NvM_BlockConfig[NvM_CurrentJob.BlockId].RamBlockDataAddress;
            NvM_CurrentJob.ReadLength = NvM_BlockConfig[NvM_CurrentJob.BlockId].NvBlockLength;
            NvM_CurrentJob.RequestType = NVM_READ_ALL;
            NvM_CurrentJob.WriteRetryCount = NvM_BlockConfig[NvM_CurrentJob.BlockId].MaxNumWriteRetries+1;
            NvM_CurrentJob.ReadRetryCount = NvM_BlockConfig[NvM_CurrentJob.BlockId].MaxNumReadRetries+1;
            NvM_DataStruct.NvMState = NVM_STATE_READ_ALL;
            NvM_CurrentJob.JobState = NVM_JOB_STATE_READ;
            NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_READ;
            NvM_CurrentJob.ProcessState = TRUE;
          }
        }
      }
    }
  }
}


/**************************************************************************
Function name   : void NvM_ProcessJobSubState(void)
Arguments       : void
Return type     : void
Description     : Job Process State Machine
**************************************************************************/
static void NvM_ProcessJobSubState(void)
{
  switch(NvM_CurrentJob.JobSubState)
  {
    case NVM_JOB_SUBSTATE_IDLE:
    break;

    case NVM_JOB_SUBSTATE_WRITE_CRC_CALC:
      NvM_WriteCrcCalculate();
    break;

    case NVM_JOB_SUBSTATE_WRITE:
      NvM_InitWrite();
    break;

    case NVM_JOB_SUBSTATE_WRITE_WAIT:
      NvM_WriteCbkWait();
    break;

    case NVM_JOB_SUBSTATE_VERIFY_READ:
      NvM_WriteVerify();
    break;

    case NVM_JOB_SUBSTATE_VERIFY_READ_WAIT:
      NvM_WriteVerifyCbkWait();
    break;

    case NVM_JOB_SUBSTATE_READ:
      NvM_InitRead();
    break;

    case NVM_JOB_SUBSTATE_READ_WAIT:
      NvM_ReadCbkWait();
    break;

    case NVM_JOB_SUBSTATE_READ_CRC_CALC:
      NvM_ReadCrcCalculate();
    break;

    case NVM_JOB_SUBSTATE_READ_CRC_VALIDATE:
      NvM_ReadCrcValidate();
    break;

    case NVM_JOB_SUBSTATE_INVALIDATE:
      NvM_InitInvalidateBlock();
    break;

    case NVM_JOB_SUBSTATE_INVALIDATE_CBK_WAIT:
      NvM_InitInvalidateBlockCbkWait();
    break;


    default:
    break;

  }
}

/**************************************************************************
Function name   : void NvM_WriteCrcCalculate(void)
Arguments       : void
Return type     : void
Description     : Calculate CRC
**************************************************************************/
static void NvM_WriteCrcCalculate()
{
    uint32 CrcLength;
    uint8  Length;

    if( NvM_CrcStruct.Length  > NVM_CRC_CALC_MAX_LEN)
    {
        NvM_CrcStruct.Length -= NVM_CRC_CALC_MAX_LEN;
        CrcLength = NVM_CRC_CALC_MAX_LEN;
    }
    else
    {
        CrcLength  =  NvM_CrcStruct.Length ;
        NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_WRITE;
        NvM_CurrentJob.ProcessState = TRUE;
    }

    if(FALSE != NvM_CrcStruct.IsFirstCall)
    {
        NvM_CrcStruct.CrcValue = NVM_CRC_CALCULATE(NvM_CrcStruct.DataPtr,CrcLength,NvM_CrcStruct.CrcValue,NvM_CrcStruct.IsFirstCall);
        NvM_CrcStruct.IsFirstCall = FALSE;
    }
    else
    {
        NvM_CrcStruct.DataPtr += NVM_CRC_CALC_MAX_LEN;
        NvM_CrcStruct.CrcValue = NVM_CRC_CALCULATE(NvM_CrcStruct.DataPtr,CrcLength,NvM_CrcStruct.CrcValue,NvM_CrcStruct.IsFirstCall);
    }
    if(NvM_CrcStruct.Length <= NVM_CRC_CALC_MAX_LEN)
    {
        Length = NvM_CurrentJob.ReadLength - NVM_CRC_BYTES;
        if( NvM_BlockConfig[NvM_CurrentJob.BlockId].BlockCrcType == CRC_32)
        {
            *(NvM_CurrentJob.RamBuffer+Length)   = (uint8) (NvM_CrcStruct.CrcValue & 0x000000FF);
            *(NvM_CurrentJob.RamBuffer+Length+1) = (uint8)((NvM_CrcStruct.CrcValue & 0x0000FF00) >> 8);
            *(NvM_CurrentJob.RamBuffer+Length+2) = (uint8)((NvM_CrcStruct.CrcValue & 0x00FF0000) >> 16);
            *(NvM_CurrentJob.RamBuffer+Length+3) = (uint8)((NvM_CrcStruct.CrcValue & 0xFF000000) >> 24);
        }
        else if( NvM_BlockConfig[NvM_CurrentJob.BlockId].BlockCrcType == CRC_16)
        {
            *(NvM_CurrentJob.RamBuffer+Length)   = (uint8) (NvM_CrcStruct.CrcValue & 0x000000FF);
            *(NvM_CurrentJob.RamBuffer+Length+1) = (uint8)((NvM_CrcStruct.CrcValue & 0x0000FF00) >> 8);
            *(NvM_CurrentJob.RamBuffer+Length+2) = 0x00;
            *(NvM_CurrentJob.RamBuffer+Length+3) = 0x00;
        }
        else
        {
            *(NvM_CurrentJob.RamBuffer+Length)   = (uint8) (NvM_CrcStruct.CrcValue & 0x000000FF);
            *(NvM_CurrentJob.RamBuffer+Length+1) = 0x00;
            *(NvM_CurrentJob.RamBuffer+Length+2) = 0x00;
            *(NvM_CurrentJob.RamBuffer+Length+3) = 0x00;


        }
    }
}
/**************************************************************************
Function name   : void NvM_InitWrite(void)
Arguments       : void
Return type     : void
Description     : Initiate the Write Request
**************************************************************************/
static void NvM_InitWrite(void)
{
  uint16 fl_Nvdescriptor;
  Std_ReturnType fl_RequestStatus;
  boolean fl_RequestWriteBlock;

  fl_Nvdescriptor = NvM_BlockConfig[NvM_CurrentJob.BlockId].NvBlockBaseNumber;
  fl_RequestWriteBlock = TRUE;
  if(NvM_DataStruct.NvMState == NVM_STATE_WRITE_ALL)
  {
      if(FALSE == NvM_BlockConfig[NvM_CurrentJob.BlockId].SelectBlockForWriteAll)
      {
            fl_RequestWriteBlock = FALSE;
            NvM_ProcessWriteAll();
      }
  }
  if(FALSE != fl_RequestWriteBlock)
  {
      if(NvM_CurrentJob.WriteRetryCount > 0)
      {
        NvM_CurrentJob.JobStatus = NVM_REQ_PENDING;
        if(NvM_BlockConfig[NvM_CurrentJob.BlockId].NvRamDeviceId == MEMIF_FEE)
        {
          fl_RequestStatus = MEMIF_FEE_WRITE_BLOCK(fl_Nvdescriptor,NvM_CurrentJob.RamBuffer);
        }
        else
        {
          fl_RequestStatus = MEMIF_EA_WRITE_BLOCK(fl_Nvdescriptor,NvM_CurrentJob.RamBuffer);
        }
        if(fl_RequestStatus == E_OK)
        {
          NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_WRITE_WAIT;
          NvM_CurrentJob.ProcessState = FALSE;
        }
        else
        {
          NvM_CurrentJob.WriteRetryCount--;
          NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_WRITE;
          NvM_CurrentJob.ProcessState = FALSE;
        }
      }
      else
      {
        NvM_BlockConfig[NvM_CurrentJob.BlockId].SingleBlockCallback(NVM_READ_BLOCK,NVM_REQ_NOT_OK);
        if(NvM_DataStruct.NvMState == NVM_STATE_WRITE_ALL)
        {
            NvM_ProcessWriteAll();
        }
        else
        {
            NvM_DataStruct.NvMState = NVM_STATE_IDLE;
            NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_IDLE;
            NvM_CurrentJob.ProcessState = FALSE;
            NvM_CurrentJob.JobState = NVM_JOB_STATE_IDLE;
            NvM_AdminBlock[NvM_CurrentJob.BlockId].BlockProcessStatus = NVM_REQ_NOT_OK;
        }
      }
  }
}
/**************************************************************************
Function name   : static void NvM_ProcessWriteAll(void)
Arguments       : void
Return type     : void
Description     : process write all
**************************************************************************/

static void NvM_ProcessWriteAll()
{
  if(NvM_DataStruct.WriteAllRequest == TRUE)
  {
    if(NvM_CurrentJob.BlockId < NVM_NUM_OF_BLOCKS)
    {
      NvM_CurrentJob.BlockId = NvM_CurrentJob.BlockId+1;
      if((FALSE != NvM_AdminBlock[NvM_CurrentJob.BlockId].BlockLockedStatus) || \
        (FALSE != NvM_AdminBlock[NvM_CurrentJob.BlockId].BlockWriteProt))
      {
        NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_WRITE;
        NvM_CurrentJob.ProcessState = TRUE;
        NvM_CurrentJob.WriteRetryCount = 0; /*Skip the write Block*/
      }
      else
      {
          NvM_CurrentJob.JobStatus = NVM_REQ_PENDING;
          NvM_CurrentJob.BlockOffset = 0;
          NvM_CurrentJob.RamBuffer = NvM_BlockConfig[NvM_CurrentJob.BlockId].RamBlockDataAddress;
          NvM_CurrentJob.ReadLength = NvM_BlockConfig[NvM_CurrentJob.BlockId].NvBlockLength;
          NvM_CurrentJob.RequestType = NVM_WRITE_ALL;
          NvM_CurrentJob.WriteRetryCount = NvM_BlockConfig[NvM_CurrentJob.BlockId].MaxNumWriteRetries+1;
          NvM_CurrentJob.ReadRetryCount = NvM_BlockConfig[NvM_CurrentJob.BlockId].MaxNumReadRetries+1;
          NvM_CurrentJob.JobState = NVM_JOB_STATE_WRITE;
          NvM_CrcStruct.IsFirstCall = TRUE;
          NvM_CrcStruct.DataPtr =  NvM_CurrentJob.RamBuffer;
          NvM_CrcStruct.Length =  NvM_CurrentJob.ReadLength - NVM_CRC_BYTES;
          NvM_CrcStruct.CrcValue = 0xFFFF;
          //NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_WRITE_CRC_CALC;
		      NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_WRITE;
          NvM_CurrentJob.ProcessState = TRUE;
      }
    }
    else
    {
      NvM_DataStruct.WriteAllRequest = FALSE;
      NvM_DataStruct.NvMState = NVM_STATE_IDLE;
      NvM_CurrentJob.JobState = NVM_JOB_STATE_IDLE;
      NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_IDLE;
      NvM_CurrentJob.ProcessState = FALSE;
      NvM_MultiBlockCallbackFunction(NVM_WRITE_ALL,NVM_REQ_OK);
    }
  }
  else
  {
    NvM_DataStruct.NvMState = NVM_STATE_IDLE;
    NvM_CurrentJob.JobState = NVM_JOB_STATE_IDLE;
    NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_IDLE;
    NvM_CurrentJob.ProcessState = FALSE;
    NvM_MultiBlockCallbackFunction(NVM_WRITE_ALL,NVM_REQ_CANCELED);
  }
}


/**************************************************************************
Function name   : void NvM_WriteCbkWait(void)
Arguments       : void
Return type     : void
Description     : wait for callback
**************************************************************************/
static void NvM_WriteCbkWait()
{
    if(NvM_CurrentJob.JobStatus != NVM_REQ_PENDING)
    {
        if(NvM_CurrentJob.JobStatus != NVM_REQ_OK)
        {
            /* NvM Write request is not successful, needs to retry based on the  */
            /* write retry count                                                 */
            NvM_CurrentJob.WriteRetryCount--;
            NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_WRITE;
            NvM_CurrentJob.ProcessState = FALSE;
        }
        else
        {
            NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_VERIFY_READ;
            NvM_CurrentJob.ProcessState = TRUE;
        }
    }
    else
    {
        NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_WRITE_WAIT;
        NvM_CurrentJob.ProcessState = FALSE;
    }
}
/**************************************************************************
Function name   : void NvM_WriteVerify(void)
Arguments       : void
Return type     : void
Description     : read the data
**************************************************************************/
static void NvM_WriteVerify()
{
  uint16 fl_Nvdescriptor;
  Std_ReturnType fl_RequestStatus;

  fl_Nvdescriptor = NvM_BlockConfig[NvM_CurrentJob.BlockId].NvBlockBaseNumber;
  NvM_CurrentJob.BlockOffset = 0;
  NvM_CurrentJob.JobStatus = NVM_REQ_PENDING;

  if(NvM_BlockConfig[NvM_CurrentJob.BlockId].NvRamDeviceId == MEMIF_FEE)
  {
  fl_RequestStatus = MEMIF_FEE_READ_BLOCK(fl_Nvdescriptor,NvM_CurrentJob.BlockOffset,\
                                      (uint8 *)&NvM_WriteVerificationBuffer,NvM_CurrentJob.ReadLength);
  }
  else
  {
  fl_RequestStatus = MEMIF_EA_READ_BLOCK(fl_Nvdescriptor,NvM_CurrentJob.BlockOffset,\
                                      (uint8 *)&NvM_WriteVerificationBuffer,NvM_CurrentJob.ReadLength);
  }
  if(fl_RequestStatus == E_OK)
  {
    NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_VERIFY_READ_WAIT;
    NvM_CurrentJob.ProcessState = FALSE;
  }
  else
  {
    NvM_BlockConfig[NvM_CurrentJob.BlockId].SingleBlockCallback(NVM_READ_BLOCK,NVM_REQ_NOT_OK);
    if(NvM_DataStruct.NvMState == NVM_STATE_WRITE_ALL)
    {
        NvM_ProcessWriteAll();
    }
    else
    {
        NvM_DataStruct.NvMState = NVM_STATE_IDLE;
        NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_IDLE;
        NvM_CurrentJob.JobState = NVM_JOB_STATE_IDLE;
        NvM_CurrentJob.ProcessState = FALSE;
        NvM_AdminBlock[NvM_CurrentJob.BlockId].BlockProcessStatus = NVM_REQ_NOT_OK;/*Verification Failed*/
    }

  }
}

/**************************************************************************
Function name   : void NvM_WriteVerifyCbkWait(void)
Arguments       : void
Return type     : void
Description     : wait for write verify call back wait
**************************************************************************/
static void NvM_WriteVerifyCbkWait()
{
    uint8 Result;
    if(NvM_CurrentJob.JobStatus != NVM_REQ_PENDING)
    {
        if(NvM_CurrentJob.JobStatus != NVM_REQ_OK)
        {
            NvM_BlockConfig[NvM_CurrentJob.BlockId].SingleBlockCallback(NVM_READ_BLOCK,NVM_REQ_NOT_OK);
            if(NvM_DataStruct.NvMState == NVM_STATE_WRITE_ALL)
            {
                NvM_ProcessWriteAll();
            }
            else
            {
                NvM_DataStruct.NvMState = NVM_STATE_IDLE;
                NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_IDLE;
                NvM_CurrentJob.ProcessState = FALSE;
                NvM_CurrentJob.JobState = NVM_JOB_STATE_IDLE;
                NvM_AdminBlock[NvM_CurrentJob.BlockId].BlockProcessStatus = NVM_REQ_NOT_OK; /*Verification Failed*/
            }
        }
        else
        {
             Result = NvM_WriteVerifyReadData();

            if(FALSE != Result)
            {
                /* Regular Read Request; Callback needs to be called */
                NvM_BlockConfig[NvM_CurrentJob.BlockId].SingleBlockCallback(NVM_READ_BLOCK,NVM_REQ_OK);
                if(NvM_DataStruct.NvMState != NVM_STATE_WRITE_ALL)
                {
                  NvM_DataStruct.NvMState = NVM_STATE_IDLE;
                  NvM_CurrentJob.JobState = NVM_JOB_STATE_IDLE;
                  NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_IDLE;
                  NvM_CurrentJob.ProcessState = FALSE;
                }
                else
                {
                    NvM_ProcessWriteAll();
                }

            }
            else
            {
               NvM_CurrentJob.WriteRetryCount--;
               NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_WRITE; /* Verfication Failed */
               NvM_CurrentJob.ProcessState = TRUE;
            }
        }
    }
}

/**************************************************************************
Function name   : Std_ReturnType NvM_WriteVerifyReadData(void)
Arguments       : void
Return type     : boolean
Description     : Verify the write data
**************************************************************************/
static boolean NvM_WriteVerifyReadData(void)
{
  uint8* WriteBuff = NvM_CurrentJob.RamBuffer;
  uint8* ReadBuff = (uint8 *)&NvM_WriteVerificationBuffer;

  uint16 CompareLength;
  uint16 Iter;
  boolean RetVal = TRUE;

  CompareLength = NvM_CurrentJob.ReadLength;

  for(Iter=0; Iter < CompareLength; Iter++)
  {
    if((*WriteBuff) != (*ReadBuff))
    {
      RetVal = FALSE;
      break;
    }
    WriteBuff++;
    ReadBuff++;
  }

  return(RetVal);
}

/**************************************************************************
Function name   : void NvM_InitRead(void)
Arguments       : void
Return type     : void
Description     : Initiate the Read Request
**************************************************************************/
static void NvM_InitRead(void)
{
  uint16 fl_Nvdescriptor;
  Std_ReturnType fl_RequestStatus;
  boolean fl_RequestReadBlock;

  fl_Nvdescriptor = NvM_BlockConfig[NvM_CurrentJob.BlockId].NvBlockBaseNumber;
  fl_RequestReadBlock = TRUE;
  if(NvM_DataStruct.NvMState == NVM_STATE_READ_ALL)
  {
      if(FALSE == NvM_BlockConfig[NvM_CurrentJob.BlockId].SelectBlockForReadAll)
      {
            fl_RequestReadBlock = FALSE;
            NvM_ProcessReadAll();
      }
  }
  if(FALSE != fl_RequestReadBlock)
  {
      if(NvM_CurrentJob.ReadRetryCount > 0)
      {
        NvM_CurrentJob.JobStatus = NVM_REQ_PENDING;
        if(NvM_BlockConfig[NvM_CurrentJob.BlockId].NvRamDeviceId == MEMIF_FEE)
        {
        fl_RequestStatus = MEMIF_FEE_READ_BLOCK(fl_Nvdescriptor,NvM_CurrentJob.BlockOffset,\
                                            NvM_CurrentJob.RamBuffer,NvM_CurrentJob.ReadLength);
        }
        else
        {
        fl_RequestStatus = MEMIF_EA_READ_BLOCK(fl_Nvdescriptor,NvM_CurrentJob.BlockOffset,\
                                            NvM_CurrentJob.RamBuffer,NvM_CurrentJob.ReadLength);
        }
        if(fl_RequestStatus == E_OK)
        {
          NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_READ_WAIT;
          NvM_CurrentJob.ProcessState = FALSE;
        }
        else
        {
          NvM_CurrentJob.ReadRetryCount--;
          NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_READ;
          NvM_CurrentJob.ProcessState = FALSE;
        }
      }
      else
      {
        NvM_AdminBlock[NvM_CurrentJob.BlockId].BlockProcessStatus = NVM_REQ_NOT_OK;
        NvM_BlockConfig[NvM_CurrentJob.BlockId].SingleBlockCallback(NVM_READ_BLOCK,NVM_REQ_NOT_OK);
        (void)NvM_RestorePRAMBlockDefaults(NvM_CurrentJob.BlockId);
        if(NvM_DataStruct.NvMState == NVM_STATE_READ_ALL)
        {
            NvM_ProcessReadAll();
        }
        else
        {
          NvM_DataStruct.NvMState = NVM_STATE_IDLE;
          NvM_CurrentJob.JobState = NVM_JOB_STATE_IDLE;
          NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_IDLE;
          NvM_CurrentJob.ProcessState = FALSE;
        }
      }
  }
}
/**************************************************************************
Function name   : void NvM_ProcessReadAll()
Arguments       : void
Return type     : void
Description     : Initiate the Read Request
**************************************************************************/
static void NvM_ProcessReadAll()
{
  if(NvM_DataStruct.ReadAllRequest == TRUE)
  {
    if(NvM_CurrentJob.BlockId < NVM_NUM_OF_BLOCKS)
    {
      NvM_CurrentJob.JobStatus = NVM_REQ_PENDING;
      NvM_CurrentJob.BlockId = NvM_CurrentJob.BlockId+1;
      NvM_CurrentJob.BlockOffset = 0;
      NvM_CurrentJob.RamBuffer = NvM_BlockConfig[NvM_CurrentJob.BlockId].RamBlockDataAddress;
      NvM_CurrentJob.ReadLength = NvM_BlockConfig[NvM_CurrentJob.BlockId].NvBlockLength;
      NvM_CurrentJob.RequestType = NVM_READ_ALL;
      NvM_CurrentJob.WriteRetryCount = NvM_BlockConfig[NvM_CurrentJob.BlockId].MaxNumWriteRetries+1;
      NvM_CurrentJob.ReadRetryCount = NvM_BlockConfig[NvM_CurrentJob.BlockId].MaxNumReadRetries+1;
      NvM_CurrentJob.JobState = NVM_JOB_STATE_READ;
      NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_READ;
      NvM_CurrentJob.ProcessState = TRUE;
    }
    else
    {
      NvM_DataStruct.ReadAllRequest = FALSE;
      NvM_DataStruct.NvMState = NVM_STATE_IDLE;
      NvM_CurrentJob.JobState = NVM_JOB_STATE_IDLE;
      NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_IDLE;
      NvM_CurrentJob.ProcessState = FALSE;
      NvM_MultiBlockCallbackFunction(NVM_READ_ALL,NVM_REQ_OK);
    }
  }
}
/**************************************************************************
Function name   : void NvM_ReadCbkWait(void)
Arguments       : void
Return type     : void
Description     : wait for callback
**************************************************************************/
static void NvM_ReadCbkWait()
{
    if(NvM_CurrentJob.JobStatus != NVM_REQ_PENDING)
    {
        switch(NvM_CurrentJob.JobStatus)
        {
          case NVM_REQ_NOT_OK:
            /* NvM Read request is not successful, needs to retry based on the  */
            /* read retry count                                                 */
            NvM_CurrentJob.ReadRetryCount--;
            NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_READ;
            NvM_CurrentJob.ProcessState = TRUE;
          break;

          case NVM_REQ_OK:
            NvM_CrcStruct.IsFirstCall = TRUE;
            NvM_CrcStruct.DataPtr =  NvM_CurrentJob.RamBuffer;
            NvM_CrcStruct.Length =  NvM_CurrentJob.ReadLength - NVM_CRC_BYTES;
            NvM_CrcStruct.CrcValue = 0xFFFF;
            //NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_READ_CRC_CALC;
        /* Regular Read Request; Callback needs to be called */
	        NvM_AdminBlock[NvM_CurrentJob.BlockId].BlockProcessStatus = NVM_REQ_OK;
	        NvM_BlockConfig[NvM_CurrentJob.BlockId].SingleBlockCallback(NVM_READ_BLOCK,NVM_REQ_OK);
	        if(NvM_DataStruct.NvMState != NVM_STATE_READ_ALL)
	        {
	          NvM_DataStruct.NvMState = NVM_STATE_IDLE;
	          NvM_CurrentJob.JobState = NVM_JOB_STATE_IDLE;
	          NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_IDLE;
              NvM_CurrentJob.ProcessState = FALSE;
	        }
	        else
	        {
	          /* Check whether Read all is in progress if so load next block */
	           NvM_ProcessReadAll();
	        }

          break;

          case NVM_REQ_NV_INVALIDATED:
          case NVM_REQ_INTEGRITY_FAILED:
            if(NvM_CurrentJob.JobStatus == NVM_REQ_NV_INVALIDATED)
            {
              NvM_AdminBlock[NvM_CurrentJob.BlockId].BlockValidStatus = FALSE;
            }
            else
            {
                (void)NvM_RestorePRAMBlockDefaults(NvM_CurrentJob.BlockId);
            }

            NvM_AdminBlock[NvM_CurrentJob.BlockId].BlockProcessStatus = NVM_REQ_NOT_OK;
            NvM_BlockConfig[NvM_CurrentJob.BlockId].SingleBlockCallback(NVM_READ_BLOCK,NVM_REQ_NOT_OK);
            if(NvM_DataStruct.NvMState == NVM_STATE_READ_ALL)
            {
              NvM_ProcessReadAll();
            }
            else
            {
               NvM_DataStruct.NvMState = NVM_STATE_IDLE;
               NvM_CurrentJob.JobState = NVM_JOB_STATE_IDLE;
               NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_IDLE;
               NvM_CurrentJob.ProcessState = FALSE;
            }
            break;

          default:
          break;
        }
    }
}

/**************************************************************************
Function name   : void NvM_ReadCrcCalculate(void)
Arguments       : void
Return type     : void
Description     : Calculate CRC
**************************************************************************/
static void NvM_ReadCrcCalculate()
{
    uint32 CrcLength;

    CrcLength  =  NvM_CrcStruct.Length ;
    if( CrcLength  > NVM_CRC_CALC_MAX_LEN)
    {
        NvM_CrcStruct.Length -= NVM_CRC_CALC_MAX_LEN;
        CrcLength = NVM_CRC_CALC_MAX_LEN;
    }
    else
    {
       NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_READ_CRC_VALIDATE;
       NvM_CurrentJob.ProcessState = TRUE;
    }

    if(FALSE != NvM_CrcStruct.IsFirstCall)
    {
        NvM_CrcStruct.CrcValue = NVM_CRC_CALCULATE(NvM_CrcStruct.DataPtr,CrcLength,NvM_CrcStruct.CrcValue,NvM_CrcStruct.IsFirstCall);
        NvM_CrcStruct.IsFirstCall = FALSE;
    }
    else
    {
        NvM_CrcStruct.DataPtr += NVM_CRC_CALC_MAX_LEN;
        NvM_CrcStruct.CrcValue = NVM_CRC_CALCULATE(NvM_CrcStruct.DataPtr,CrcLength,NvM_CrcStruct.CrcValue,NvM_CrcStruct.IsFirstCall);

    }
}

/**************************************************************************
Function name   : void NvM_ReadCrcValidate(void)
Arguments       : void
Return type     : void
Description     : Validate CRC
**************************************************************************/
static void NvM_ReadCrcValidate()
{
    uint32 ReadCrcValue;
    uint8* Buff;
    uint8  Length;

    Length = NvM_CurrentJob.ReadLength - NVM_CRC_BYTES;
    Buff = (NvM_CurrentJob.RamBuffer+Length);
    ReadCrcValue = 0;

    if( NvM_BlockConfig[NvM_CurrentJob.BlockId].BlockCrcType == CRC_32)
    {
         ReadCrcValue |= (uint32)(*Buff);
         Buff++;
         ReadCrcValue |= (uint32)(*Buff << 8);
         Buff++;
         ReadCrcValue |= (uint32)(*Buff << 16);
         Buff++;
         ReadCrcValue |= (uint32)(*Buff << 24);
    }
    else if(NvM_BlockConfig[NvM_CurrentJob.BlockId].BlockCrcType == CRC_16)
    {
         ReadCrcValue |= (uint32)(*Buff);
         Buff++;
         ReadCrcValue |= (uint32)(*Buff << 8);
    }
    else
    {
         ReadCrcValue |= (uint32)(*Buff);
    }
    if(NvM_CrcStruct.CrcValue == ReadCrcValue)
    {
        /* Regular Read Request; Callback needs to be called */
        NvM_AdminBlock[NvM_CurrentJob.BlockId].BlockProcessStatus = NVM_REQ_OK;
        NvM_BlockConfig[NvM_CurrentJob.BlockId].SingleBlockCallback(NVM_READ_BLOCK,NVM_REQ_OK);
        if(NvM_DataStruct.NvMState != NVM_STATE_READ_ALL)
        {
          NvM_DataStruct.NvMState = NVM_STATE_IDLE;
          NvM_CurrentJob.JobState = NVM_JOB_STATE_IDLE;
          NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_IDLE;
          NvM_CurrentJob.ProcessState = FALSE;
        }
        else
        {
          /* Check whether Read all is in progress if so load next block */
           NvM_ProcessReadAll();
        }
    }
    else
    {
      if(FALSE != NvM_CurrentJob.ReadRetryCount)
      {
        NvM_CurrentJob.ReadRetryCount--;
      }
      NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_READ;
      NvM_CurrentJob.ProcessState = TRUE;
    }

}
/**************************************************************************
Function name   : void NvM_InitInvalidateBlock(void)
Arguments       : void
Return type     : void
Description     : Invalidate block
**************************************************************************/
static void NvM_InitInvalidateBlock()
{
  uint16 fl_Nvdescriptor;
  Std_ReturnType fl_RequestStatus;

    fl_Nvdescriptor = NvM_BlockConfig[NvM_CurrentJob.BlockId].NvBlockBaseNumber;

    NvM_CurrentJob.JobStatus = NVM_REQ_PENDING;

    if(NvM_BlockConfig[NvM_CurrentJob.BlockId].NvRamDeviceId == MEMIF_FEE)
    {
      fl_RequestStatus = MEMIF_FEE_INVALIDATE_BLOCK(fl_Nvdescriptor);
    }
    else
    {
      fl_RequestStatus = MEMIF_EA_INVALIDATE_BLOCK(fl_Nvdescriptor);
    }
    if(fl_RequestStatus == E_OK)
    {
      NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_INVALIDATE_CBK_WAIT;
      NvM_CurrentJob.ProcessState = FALSE;
    }
    else
    {
        NvM_BlockConfig[NvM_CurrentJob.BlockId].SingleBlockCallback(NVM_INVALIDATE_NV_BLOCK,NVM_REQ_NOT_OK);
        NvM_DataStruct.NvMState = NVM_STATE_IDLE;
        NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_IDLE;
        NvM_CurrentJob.JobState = NVM_JOB_STATE_IDLE;
        NvM_CurrentJob.ProcessState = FALSE;
        NvM_AdminBlock[NvM_CurrentJob.BlockId].BlockProcessStatus = NVM_REQ_NOT_OK;

    }
}

/**************************************************************************
Function name   : void NvM_InitInvalidateBlockCbkWait(void)
Arguments       : void
Return type     : void
Description     : Invalidate block cbk wait
**************************************************************************/
static void NvM_InitInvalidateBlockCbkWait()
{
    if(NvM_CurrentJob.JobStatus != NVM_REQ_PENDING)
    {
        if(NvM_CurrentJob.JobStatus != NVM_REQ_OK)
        {
            NvM_BlockConfig[NvM_CurrentJob.BlockId].SingleBlockCallback(NVM_INVALIDATE_NV_BLOCK,NVM_REQ_NOT_OK);
            NvM_AdminBlock[NvM_CurrentJob.BlockId].BlockProcessStatus = NVM_REQ_NOT_OK;
        }
        else
        {
            NvM_AdminBlock[NvM_CurrentJob.BlockId].BlockValidStatus = FALSE;
            NvM_AdminBlock[NvM_CurrentJob.BlockId].BlockProcessStatus = NVM_REQ_OK;
            NvM_BlockConfig[NvM_CurrentJob.BlockId].SingleBlockCallback(NVM_INVALIDATE_NV_BLOCK,NVM_REQ_OK);
        }
        NvM_DataStruct.NvMState = NVM_STATE_IDLE;
        NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_IDLE;
        NvM_CurrentJob.JobState = NVM_JOB_STATE_IDLE;
        NvM_CurrentJob.ProcessState = FALSE;
    }
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
/**-------------------------------------------------------------------------*/
/*Date              : 23-02-2016                                            */
/*Version           :                                                       */
/*By                : vbalakr3                                              */
/*Traceability      :                                                       */
/*Change Description:Queue and Write Verification implemented               */
/*--------------------------------------------------------------------------*/
