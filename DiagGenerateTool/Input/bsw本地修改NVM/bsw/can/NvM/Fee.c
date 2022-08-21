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
*  File Name         :  Fee.c                                                *
*  Module Short Name :  Fee                                                  *
*  VOBName           :                                                       *
*  Author            : vbalakr3                                              *
*  Description       : Request handling of Fee data module                   *
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
#ifndef FEE_C
#define FEE_C
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "Fee.h"
//#include "SchM_NvM.h"/* Qiuhuaqing Modify,  To be Release after NVM Finished */
#include "String.h"
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

typedef enum
{
  FEE_PARTITION_UNINIT = 0,
  FEE_PARTITION_READY,
  FEE_PARTITION_ERROR,
  FEE_PARTITION_INIT_PROGRESS
}Fee_PartitionStatusType;

typedef enum
{
  FEE_JOB_IDLE = 0,
  FEE_JOB_WRITE,
  FEE_JOB_READ,
  FEE_JOB_UNINIT
}Fee_JobActiveIdType;

typedef enum
{
  FEE_JOB_STATE_IDLE = 0,
  FEE_JOB_STATE_WRITE_HEADER1,
  FEE_JOB_STATE_WRITE_HEADER1_WAIT,
  FEE_JOB_STATE_WRITE_PAYLOAD,
  FEE_JOB_STATE_WRITE_PAYLOAD_WAIT,
  FEE_JOB_STATE_WRITE_HEADER2,
  FEE_JOB_STATE_WRITE_HEADER2_WAIT,
  FEE_JOB_STATE_READ_HEADER,
  FEE_JOB_STATE_READ_HEADER_WAIT,
  FEE_JOB_STATE_READ_PAYLOAD,
  FEE_JOB_STATE_READ_PAYLOAD_WAIT
}Fee_JobStateType;


typedef enum
{
  FEE_SECTOR_SWITCH_STATE_IDLE = 0,
  FEE_SECTOR_SWITCH_STATE_HEADER_WRITE,
  FEE_SECTOR_SWITCH_STATE_HEADER_WRITE_WAIT,
  FEE_SECTOR_SWITCH_STATE_SEARCH_NEXT_BLOCK,
  FEE_SECTOR_SWITCH_STATE_BLOCK_READ,
  FEE_SECTOR_SWITCH_STATE_BLOCK_READ_WAIT,
  FEE_SECTOR_SWITCH_STATE_BLOCK_WRITE,
  FEE_SECTOR_SWITCH_STATE_BLOCK_WRITE_WAIT,
  FEE_SECTOR_SWITCH_STATE_SECTOR_FOOTER_WRITE,
  FEE_SECTOR_SWITCH_STATE_SECTOR_FOOTER_WRITE_WAIT
}Fee_SectorSwitchStateType;


typedef enum
{
  FEE_PARTITION_STATE_IDLE = 0,
  FEE_PARTITION_STATE_SECTOR_HEADER_READ,
  FEE_PARTITION_STATE_SECTOR_HEADER_READ_WAIT,
  FEE_PARTITION_STATE_SECTOR_FOOTER_READ,
  FEE_PARTITION_STATE_WAIT_SECTOR_FOOTER_READ,
  FEE_PARTITION_STATE_VALIDATE_SECTOR,
  FEE_PARTITION_STATE_SECTOR_HEADER_WRITE,
  FEE_PARTITION_STATE_SECTOR_HEADER_WRITE_WAIT,
  FEE_PARTITION_STATE_SECTOR_FOOTER_WRITE,
  FEE_PARTITION_STATE_SECTOR_FOOTER_WRITE_WAIT,
  FEE_PARTITION_STATE_BLOCK_READ_HEADER,
  FEE_PARTITION_STATE_BLOCK_READ_HEADER_WAIT,
  FEE_PARTITION_STATE_BLOCK_READ_HEADER_VALIDATE,
}Fee_PartitionStateType;


typedef enum
{
  FEE_SECTOR_ERASE_STATE_IDLE = 0,
  FEE_SECTOR_ERASE_STATE_ERASE,
  FEE_SECTOR_ERASE_STATE_ERASE_WAIT
}Fee_SectorEraseType;


typedef struct  
{
  uint32 NextFreeAddress;
  Fee_PartitionStatusType Status;
  uint8 OldSectorId;
  uint8 CurrentSectorId;
  uint8 EraseSectorId;
  uint8 count;
}Fee_PartitionType;

typedef struct  
{
  uint8* RamAddress;
  uint16 BlockId;
  uint16 Offset;
  uint16 Length;
  uint16 SearchBlockId;
  uint8 DataIndex;
  Fee_JobActiveIdType JobActiveId;
  Fee_JobStateType JobState;
  Fee_SectorSwitchStateType SectorSwitchState;
  Fee_PartitionStateType PartitionState;
  Fee_SectorEraseType SectorEraseState;
  MemIf_JobResultType JobResult;
  boolean RepeatStateMachine;
}Fee_JobType;

typedef struct  
{
  uint16 BlockId;
  uint16 PayloadLength;
  uint16 Reserved1; /* Qiuhuaqing Modify, Page size 8Byte */
  uint16 Reserved2;
}Fee_BlockHeaderType;


typedef struct  
{
  uint8 SectorId;
  uint8 count;
  uint16 Reserved1;
  uint16 Reserved2;
  uint16 Reserved3;
}Fee_SectorHeaderType;


typedef struct 
{
  uint8 SectorId;
  uint8 count;
  uint16 Reserved1;
  uint16 Reserved2;
  uint16 Reserved3;
}Fee_SectorFooterType;


typedef struct
{
  uint8 ValidSectorId;
  uint8 count;
  uint8 CurrentSectorId;
}Fee_SectorSearchType;


typedef struct 
{
  uint32 LatestAddress;
}Fee_BlockInformationType;

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
static Fee_JobType Fee_Job;
static Fee_BlockInformationType Fee_BlockInformation[FEE_NUM_BLOCKS];
static Fee_PartitionType Fee_Partition[FEE_NUM_PARTITIONS];
static Fee_SectorSearchType Fee_SectorSearch;
static uint8 Fee_BlockReadBuffer[FEE_MAX_LENGTH];

#ifdef __ghs__
#pragma alignvar (8)
#endif
static Fee_SectorHeaderType Fee_SectorHeader;
#ifdef __ghs__
#pragma alignvar (8)
#endif
static Fee_SectorFooterType Fee_SectorFooter;
#ifdef __ghs__
#pragma alignvar (8)
#endif
static Fee_BlockHeaderType Fee_BlockHeader[2];

/*****************************************************************************
*                              Limited Scope Prototypes                      *
******************************************************************************/
static void Fee_JobWriteHeader1(void);
static void Fee_JobWriteHeader1Wait(void);
static void Fee_JobWritePayload(void);
static void Fee_JobWritePayloadWait(void);
static void Fee_JobWriteHeader2(void);
static void Fee_JobWriteHeader2Wait(void);
static void Fee_JobReadHeader(void);
static void Fee_JobReadHeaderWait(void);
static Std_ReturnType Fee_HeaderValidate(void);
static void Fee_JobReadPayload(void);
static void Fee_JobReadPayloadWait(void);
static void Fee_JobStateProcess(void);
static void Fee_PartitionSectorHeaderRead(void);
static void Fee_PartitionSectorHeaderReadWait(void);
static void Fee_PartitionSectorFooterRead(void);
static void Fee_PartitionSectorFooterReadWait(void);
static void Fee_ValidateSector(void);
static void Fee_PartitionSectorHeaderWrite(void);
static void Fee_PartitionSectorHeaderWriteWait(void);
static void Fee_PartitionSectorFooterWrite(void);
static void Fee_PartitionSectorFooterWriteWait(void);
static void Fee_PartitionBlockReadHeader(void);
static void Fee_PartitionBlockReadHeaderWait(void);
static void Fee_PartitionBlockValidate(void);
static void Fee_PartitionStateProcess(void);
static void Fee_SectorErase(void);
static void Fee_SectorEraseWait(void);
static void Fee_SectorEraseStateProcess(void);
static void Fee_SectorSwitchHeaderWrite(void);
static void Fee_SectorSwitchHeaderWriteWait(void);
static void Fee_SectorSwitchSearchNextBlock(void);
static void Fee_SectorSwitchBlockRead(void);
static void Fee_SectorSwitchBlockReadWait(void);
static void Fee_SectorSwitchBlockWrite(void);
static void Fee_SectorSwitchBlockWriteWait(void);
static void Fee_SectorSwitchSectorFooterWrite(void);
static void Fee_SectorSwitchSectorFooterWriteWait(void);
static void Fee_SectorSwitchStateProcess(void);
static Std_ReturnType Fee_SectorSwitchRequired(uint8 fl_PartionNo);

/*****************************************************************************
*                   Functions                                                *
******************************************************************************/

/**************************************************************************
Function name   : void Fee_Init(void)
Arguments       : void
Return type     : void
Description     : Service to initialize the FEE module. 
**************************************************************************/
void Fee_Init(void)
{
  uint16 fl_BlockId;
  uint8 fl_PartionNo;
  Fee_Job.JobActiveId = FEE_JOB_UNINIT;
  Fee_Job.BlockId = 0;
  Fee_Job.DataIndex = 0;
  Fee_Job.JobResult = MEMIF_JOB_OK;
  Fee_Job.JobState = FEE_JOB_STATE_IDLE;
  Fee_Job.Length = 0;
  Fee_Job.Offset = 0;
  Fee_Job.PartitionState = FEE_PARTITION_STATE_IDLE;
  Fee_Job.RamAddress = NULL;
  Fee_Job.RepeatStateMachine = FALSE;
  Fee_Job.SearchBlockId = 0;
  Fee_Job.SectorEraseState = FEE_SECTOR_ERASE_STATE_IDLE;
  Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_IDLE;
  
  for(fl_PartionNo = 0; fl_PartionNo < FEE_NUM_PARTITIONS; fl_PartionNo++)
  {
    Fee_Partition[fl_PartionNo].Status = FEE_PARTITION_UNINIT;
    Fee_Partition[fl_PartionNo].NextFreeAddress = 0;
    Fee_Partition[fl_PartionNo].count = 0;
    Fee_Partition[fl_PartionNo].CurrentSectorId = 0;
    Fee_Partition[fl_PartionNo].OldSectorId = 0;
    Fee_Partition[fl_PartionNo].EraseSectorId = 0;
  }

  for(fl_BlockId = 0; fl_BlockId < FEE_NUM_BLOCKS; fl_BlockId++)
  {
    Fee_BlockInformation[fl_BlockId].LatestAddress = 0;
  }
  Fee_SectorSearch.CurrentSectorId = 0;
  Fee_SectorSearch.count =0;
  Fee_SectorSearch.ValidSectorId = 0xFF;

  Fee_Job.JobActiveId = FEE_JOB_IDLE;
}

/**************************************************************************
Function name   : void Fee_SetMode(MemIf_ModeType Mode)
Arguments       : MemIf_ModeType Mode
Return type     : void
Description     : Service to call the Fls_SetMode function of the underlying flash driver. 
**************************************************************************/
void Fee_SetMode(MemIf_ModeType Mode)
{
}

/**************************************************************************
Function name   : Std_ReturnType Fee_Read(uint16 BlockNumber, uint16 BlockOffset, uint8* DataBufferPtr, uint16 Length);
Arguments       : uint16 BlockNumber, uint16 BlockOffset, uint8* DataBufferPtr, uint16 Length
Return type     : Std_ReturnType
                    E_OK: The requested job has been accepted by the module.
                    E_NOT_OK: The requested job has not been accepted by the module.
Description     : Service to initiate a read job.
**************************************************************************/
Std_ReturnType Fee_Read(uint16 BlockNumber, uint16 BlockOffset, uint8* DataBufferPtr, uint16 Length)
{
  Std_ReturnType fl_RetVal;
  if(Fee_Job.JobActiveId == FEE_JOB_IDLE)
  {
    Fee_Job.JobActiveId = FEE_JOB_READ;
    Fee_Job.BlockId = BlockNumber;
    Fee_Job.JobResult = MEMIF_JOB_PENDING;
    Fee_Job.JobState = FEE_JOB_STATE_READ_HEADER;
    Fee_Job.Length = Fee_BlockConfig[BlockNumber].BlockSize;
    Fee_Job.RamAddress = (uint8 *)DataBufferPtr;
    Fee_Job.Offset = BlockOffset;
    fl_RetVal = E_OK;
  }
  else
  {
    fl_RetVal = E_NOT_OK;
  }
  return fl_RetVal;
}

/**************************************************************************
Function name   : Std_ReturnType Fee_Write(uint16 BlockNumber, const uint8* DataBufferPtr);
Arguments       : uint16 BlockNumber, const uint8* DataBufferPtr
Return type     : Std_ReturnType
                    E_OK: The requested job has been accepted by the module.
                    E_NOT_OK: The requested job has not been accepted by the module.
Description     : Service to initiate a write job.
**************************************************************************/
Std_ReturnType Fee_Write(uint16 BlockNumber, const uint8* DataBufferPtr)
{
  Std_ReturnType fl_RetVal;
  if(Fee_Job.JobActiveId == FEE_JOB_IDLE)
  {
    Fee_Job.JobActiveId = FEE_JOB_WRITE;
    Fee_Job.BlockId = BlockNumber;
    Fee_Job.JobResult = MEMIF_JOB_PENDING;
    Fee_Job.JobState = FEE_JOB_STATE_WRITE_HEADER1;
    Fee_Job.Length = Fee_BlockConfig[BlockNumber].BlockSize;
    Fee_Job.RamAddress = (uint8 *)DataBufferPtr;
    Fee_Job.Offset = 0;
    fl_RetVal = E_OK;
  }
  else
  {
    fl_RetVal = E_NOT_OK;
  }
  return fl_RetVal;
}


/**************************************************************************
Function name   : Std_ReturnType Fee_Write(uint16 BlockNumber, const uint8* DataBufferPtr);
Arguments       : void
Return type     : void
Description     : Service to Cancel.
**************************************************************************/
void Fee_Cancel(void)
{
}

/**************************************************************************
Function name   : MemIf_StatusType Fee_GetStatus(void)
Arguments       : void
Return type     : Memif_StatusType
                  MEMIF_UNINIT: The FEE module has not been initialized.
                  MEMIF_IDLE: The FEE module is currently idle.
                  MEMIF_BUSY: The FEE module is currently busy.
                  MEMIF_BUSY_INTERNAL: The FEE module is busy with internal management operations.
Description     : Service to return the status.
**************************************************************************/
MemIf_StatusType Fee_GetStatus(void)
{
  MemIf_StatusType fl_RetVal;
  if(Fee_Job.JobActiveId == FEE_JOB_UNINIT)
  {
    fl_RetVal = MEMIF_UNINIT;
  }
  else if(Fee_Job.JobActiveId == FEE_JOB_IDLE)
  {
    fl_RetVal = MEMIF_IDLE;
  }
  else
  {
    fl_RetVal = MEMIF_BUSY;
  }
  return fl_RetVal;
}

/**************************************************************************
Function name   : MemIf_JobResultType Fee_GetJobResult(void)
Arguments       : void
Return type     : MemIf_JobResultType
                  MEMIF_JOB_OK: The last job has been finished successfully.
                  MEMIF_JOB_PENDING: The last job is waiting for execution or currently being executed.
                  MEMIF_JOB_CANCELED: The last job has been canceled (which means it failed).
                  MEMIF_JOB_FAILED: The last job has not been finished successfully (it failed).
                  MEMIF_BLOCK_INCONSISTENT: The requested block is inconsistent, it may contain corrupted data.
                  MEMIF_BLOCK_INVALID: The requested block has been invalidated, the requested read operation can not be performed.
Description     : Service to query the result of the last accepted job issued by the upper layer software.
**************************************************************************/
MemIf_JobResultType Fee_GetJobResult(void)
{
  return Fee_Job.JobResult;
}

/**************************************************************************
Function name   : Std_ReturnType Fee_InvalidateBlock( uint16 BlockNumber)
Arguments       : uint16 BlockNumber
Return type     : Std_ReturnType
                  E_OK: The requested job has been accepted by the module.
                  E_NOT_OK - only if DET is enabled: The requested job has not been accepted by the module.
Description     : Service to invalidate a logical block
**************************************************************************/
Std_ReturnType Fee_InvalidateBlock( uint16 BlockNumber)
{
  return E_NOT_OK;
}

/**************************************************************************
Function name   : void Fee_GetVersionInfo(Std_VersionInfoType* VersionInfoPtr)
Arguments       : Std_VersionInfoType* VersionInfoPtr
Return type     : void
Description     : Service to return the version information of the FEE module.
**************************************************************************/
void Fee_GetVersionInfo(Std_VersionInfoType* VersionInfoPtr)
{
}

/**************************************************************************
Function name   : Std_ReturnType Fee_EraseImmediateBlock(uint16 BlockNumber)
Arguments       : uint16 BlockNumber
Return type     : Std_ReturnType
                  E_OK: The requested job has been accepted by the module.
                  E_NOT_OK - only if DET is enabled: The requested job has not been accepted by the module.
Description     : This function is called by App/Scheduler when there is an
                  init required. 
**************************************************************************/
Std_ReturnType Fee_EraseImmediateBlock(uint16 BlockNumber)
{
  return E_NOT_OK;
}

/**************************************************************************
Function name   : void Fee_JobEndNotification(void)
Arguments       : void
Return type     : void
Description     : Service to report to this module the successful end of an asynchronous operation.
**************************************************************************/
void Fee_JobEndNotification(void)
{
}

/**************************************************************************
Function name   : void void Fee_JobErrorNotification(void)
Arguments       : void
Return type     : void
Description     : Service to report to this module the failure of an asynchronous operation.
**************************************************************************/
void Fee_JobErrorNotification(void)
{
}


/**************************************************************************
Function name   : void Fee_JobWriteHeader1(void)
Arguments       : void
Return type     : void
Description     : Service to initialize the Header Write
**************************************************************************/
static void Fee_JobWriteHeader1(void)
{
  uint8 fl_PartionNo;
  Std_ReturnType fl_SectorSwitchRequired;
  Std_ReturnType fl_RequestStatus;
  fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
  fl_SectorSwitchRequired = Fee_SectorSwitchRequired(fl_PartionNo);
  if(Fee_Partition[fl_PartionNo].Status == FEE_PARTITION_UNINIT)
  {
    Fee_Partition[fl_PartionNo].Status = FEE_PARTITION_INIT_PROGRESS;
    Fee_SectorSearch.ValidSectorId = 0xFF;
    Fee_SectorSearch.CurrentSectorId = Fee_PartitionConfig[fl_PartionNo].StartVirtualAddress/FEE_SECTOR_SIZE;
    Fee_Job.PartitionState = FEE_PARTITION_STATE_SECTOR_HEADER_READ;
    Fee_Job.RepeatStateMachine = TRUE;
  }
  else if (Fee_Partition[fl_PartionNo].Status == FEE_PARTITION_ERROR)
  {
    Fee_Job.JobResult = MEMIF_BLOCK_INVALID;
    NVM_JOB_ERROR_NOTIFICATION();
    Fee_Job.JobActiveId = FEE_JOB_IDLE;
    Fee_Job.JobState = FEE_JOB_STATE_IDLE;
    Fee_Job.RepeatStateMachine = FALSE;
  }
  else if (fl_SectorSwitchRequired == E_OK)
  {
    Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_HEADER_WRITE;
    Fee_Job.RepeatStateMachine = TRUE;
  }
  else
  {
    Fee_BlockHeader[0].BlockId = Fee_Job.BlockId;
    Fee_BlockHeader[0].PayloadLength = Fee_Job.Length;
    Fee_BlockHeader[0].Reserved1 = 0xFFFF;    /* Qiuhuaqing Modify, Page size only 4Byte */
    Fee_BlockHeader[0].Reserved2 = 0xFFFF;
    fl_RequestStatus = FLS_WRITE(Fee_Partition[fl_PartionNo].NextFreeAddress,(uint8 *)&Fee_BlockHeader[0].BlockId,FEE_HEADER_SIZE);
    if(fl_RequestStatus == E_OK)
    {
      Fee_Partition[fl_PartionNo].NextFreeAddress = Fee_Partition[fl_PartionNo].NextFreeAddress + (FEE_HEADER_SIZE << 1);
      Fee_Job.JobState = FEE_JOB_STATE_WRITE_HEADER1_WAIT;
      Fee_Job.RepeatStateMachine = FALSE;
    }
    else
    {
      Fee_Job.JobResult = MEMIF_JOB_FAILED;
      NVM_JOB_ERROR_NOTIFICATION();
      Fee_Job.JobActiveId = FEE_JOB_IDLE;
      Fee_Job.JobState = FEE_JOB_STATE_IDLE;
      Fee_Job.RepeatStateMachine = FALSE;
    }
  }
}

/**************************************************************************
Function name   : Std_ReturnType Fee_SectorSwitchRequired(uint8 fl_PartionNo)
Arguments       : void
Return type     : Std_ReturnType
Description     : Service to Check the Sector Sith required. 
                  E_OK - Sector Switch Required
                  E_NOT_OK - Sector Switch Not Required.
**************************************************************************/
static Std_ReturnType Fee_SectorSwitchRequired(uint8 fl_PartionNo)
{
  uint16 fl_RemainingDataBytes;
  Std_ReturnType fl_RetVal;
  fl_RemainingDataBytes = (Fee_Partition[fl_PartionNo].CurrentSectorId *FEE_SECTOR_SIZE) + \
                            FEE_SECTOR_SIZE - Fee_Partition[fl_PartionNo].NextFreeAddress - FEE_SECTOR_FOOTER_SIZE;
  if(fl_RemainingDataBytes < FEE_MAX_LENGTH)
  {
    fl_RetVal = E_OK;
  }
  else
  {
    fl_RetVal = E_NOT_OK;
  }
  return fl_RetVal;
} 

/**************************************************************************
Function name   : void Fee_JobWriteHeader1Wait(void)
Arguments       : void
Return type     : void
Description     : Service to Check the Flash Driver Job Result 
**************************************************************************/
static void Fee_JobWriteHeader1Wait(void)
{
  uint8 fl_PartionNo;
  MemIf_JobResultType fl_FlsJobStatus;
  fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
  fl_FlsJobStatus = FLS_GET_JOB_RESULT();
  if(fl_FlsJobStatus != MEMIF_JOB_PENDING)
  {
    if(fl_FlsJobStatus == MEMIF_JOB_OK)
    {
      Fee_Job.JobState = FEE_JOB_STATE_WRITE_PAYLOAD;
      Fee_Job.RepeatStateMachine = TRUE;
    }
    else
    {
      Fee_Partition[fl_PartionNo].NextFreeAddress = Fee_Partition[fl_PartionNo].NextFreeAddress + Fee_Job.Length;
      Fee_Job.JobResult = MEMIF_JOB_FAILED;
      NVM_JOB_ERROR_NOTIFICATION();
      Fee_Job.JobActiveId = FEE_JOB_IDLE;
      Fee_Job.JobState = FEE_JOB_STATE_IDLE;
      Fee_Job.RepeatStateMachine = FALSE;
    }
  }
  else
  {
    /* Wait for Next State Machine */
    Fee_Job.RepeatStateMachine = FALSE;
  }
}

/**************************************************************************
Function name   : void Fee_JobWritePayload(void)
Arguments       : void
Return type     : void
Description     : Write Payload request
**************************************************************************/
static void Fee_JobWritePayload(void)
{
  uint8 fl_PartionNo;
  Std_ReturnType fl_RequestType;
  fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
  fl_RequestType = FLS_WRITE(Fee_Partition[fl_PartionNo].NextFreeAddress,(uint8 *)Fee_Job.RamAddress,Fee_Job.Length);
  if(fl_RequestType == E_OK)
  {
    Fee_Partition[fl_PartionNo].NextFreeAddress = Fee_Partition[fl_PartionNo].NextFreeAddress - FEE_HEADER_SIZE;
    Fee_Job.JobState = FEE_JOB_STATE_WRITE_PAYLOAD_WAIT;
    Fee_Job.RepeatStateMachine = FALSE;
  }
  else
  {
    Fee_Partition[fl_PartionNo].NextFreeAddress = Fee_Partition[fl_PartionNo].NextFreeAddress + Fee_Job.Length;
    Fee_Job.JobResult = MEMIF_JOB_FAILED;
    NVM_JOB_ERROR_NOTIFICATION();
    Fee_Job.JobActiveId = FEE_JOB_IDLE;
    Fee_Job.JobState = FEE_JOB_STATE_IDLE;
    Fee_Job.RepeatStateMachine = FALSE;
  }
}

/**************************************************************************
Function name   : void Fee_JobWritePayloadWait(void)
Arguments       : void
Return type     : void
Description     : Service to Check the Flash Driver Job Result
**************************************************************************/
static void Fee_JobWritePayloadWait(void)
{
  uint8 fl_PartionNo;
  MemIf_JobResultType fl_FlsJobStatus;
  fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
  fl_FlsJobStatus = FLS_GET_JOB_RESULT();
  if(fl_FlsJobStatus != MEMIF_JOB_PENDING)
  {
    if(fl_FlsJobStatus == MEMIF_JOB_OK)
    {
      Fee_Job.JobState = FEE_JOB_STATE_WRITE_HEADER2;
      Fee_Job.RepeatStateMachine = TRUE;
    }
    else
    {
      Fee_Partition[fl_PartionNo].NextFreeAddress = Fee_Partition[fl_PartionNo].NextFreeAddress + Fee_Job.Length;
      Fee_Job.JobResult = MEMIF_JOB_FAILED;
      NVM_JOB_ERROR_NOTIFICATION();
      Fee_Job.JobActiveId = FEE_JOB_IDLE;
      Fee_Job.JobState = FEE_JOB_STATE_IDLE;
      Fee_Job.RepeatStateMachine = FALSE;
    }
  }
  else
  {
    /* Wait for Next State Machine */
    Fee_Job.RepeatStateMachine = FALSE;
  }
}

/**************************************************************************
Function name   : void Fee_JobWriteHeader2(void)
Arguments       : void
Return type     : void
Description     : Request write Header2
**************************************************************************/
static void Fee_JobWriteHeader2(void)
{
  uint8 fl_PartionNo;
  Std_ReturnType fl_RequestType;
  fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
  Fee_BlockHeader[1].BlockId = (uint16)~Fee_Job.BlockId;
  Fee_BlockHeader[1].PayloadLength = (uint16)~Fee_Job.Length;
  Fee_BlockHeader[1].Reserved1 = 0x0000;      /* Qiuhuaqing Modify, Page size only 4Byte */
  Fee_BlockHeader[1].Reserved2 = 0x0000;
  fl_RequestType = FLS_WRITE(Fee_Partition[fl_PartionNo].NextFreeAddress,(uint8 *)&Fee_BlockHeader[1].BlockId,FEE_HEADER_SIZE);
  if(fl_RequestType == E_OK)
  {
    Fee_Partition[fl_PartionNo].NextFreeAddress = Fee_Partition[fl_PartionNo].NextFreeAddress + FEE_HEADER_SIZE + Fee_Job.Length;
    Fee_Job.JobState = FEE_JOB_STATE_WRITE_HEADER2_WAIT;
    Fee_Job.RepeatStateMachine = FALSE;
  }
  else
  {
    Fee_Partition[fl_PartionNo].NextFreeAddress = Fee_Partition[fl_PartionNo].NextFreeAddress + FEE_HEADER_SIZE + Fee_Job.Length;
    Fee_Job.JobResult = MEMIF_JOB_FAILED;
    NVM_JOB_ERROR_NOTIFICATION();
    Fee_Job.JobActiveId = FEE_JOB_IDLE;
    Fee_Job.JobState = FEE_JOB_STATE_IDLE;
    Fee_Job.RepeatStateMachine = FALSE;
  }
}

/**************************************************************************
Function name   : void Fee_JobWriteHeader2Wait(void)
Arguments       : void
Return type     : void
Description     : Service to Check the Flash Driver Job Result 
**************************************************************************/
static void Fee_JobWriteHeader2Wait(void)
{
  uint8 fl_PartionNo;
  MemIf_JobResultType fl_FlsJobStatus;
  Std_ReturnType fl_SectorSwitchRequired;
  fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
  fl_FlsJobStatus = FLS_GET_JOB_RESULT();
  if(fl_FlsJobStatus != MEMIF_JOB_PENDING)
  {
    if(fl_FlsJobStatus == MEMIF_JOB_OK)
    {
      Fee_Job.JobResult = MEMIF_JOB_OK;
      Fee_BlockInformation[Fee_Job.BlockId].LatestAddress = Fee_Partition[fl_PartionNo].NextFreeAddress - (FEE_HEADER_SIZE << 1) - Fee_Job.Length;
      NVM_JOB_END_NOTIFICATION();
      Fee_Job.JobActiveId = FEE_JOB_IDLE;
      Fee_Job.JobState = FEE_JOB_STATE_IDLE;
      Fee_Job.RepeatStateMachine = FALSE;
    }
    else
    {
      Fee_Job.JobResult = MEMIF_JOB_FAILED;
      NVM_JOB_ERROR_NOTIFICATION();
      Fee_Job.JobActiveId = FEE_JOB_IDLE;
      Fee_Job.JobState = FEE_JOB_STATE_IDLE;
      Fee_Job.RepeatStateMachine = FALSE;
    }
    fl_SectorSwitchRequired = Fee_SectorSwitchRequired(fl_PartionNo);
    if (fl_SectorSwitchRequired == E_OK)
    {
      Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_HEADER_WRITE;
      Fee_Job.RepeatStateMachine = TRUE;
    }
  }
  else
  {
    /* Wait for Next State Machine */
    Fee_Job.RepeatStateMachine = FALSE;
  }
}

/**************************************************************************
Function name   : void Fee_JobReadHeader(void)
Arguments       : void
Return type     : void
Description     : Request Read Header
**************************************************************************/
static void Fee_JobReadHeader(void)
{
  uint8 fl_PartionNo;
  Std_ReturnType fl_RequestStatus;
  fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
  if(Fee_Partition[fl_PartionNo].Status == FEE_PARTITION_UNINIT)
  {
    Fee_Partition[fl_PartionNo].Status = FEE_PARTITION_INIT_PROGRESS;
    Fee_SectorSearch.ValidSectorId = 0xFF;
    Fee_SectorSearch.CurrentSectorId = Fee_PartitionConfig[fl_PartionNo].StartVirtualAddress/FEE_SECTOR_SIZE;
    Fee_Job.PartitionState = FEE_PARTITION_STATE_SECTOR_HEADER_READ;
    Fee_Job.RepeatStateMachine = TRUE;
  }
  else if (Fee_Partition[fl_PartionNo].Status == FEE_PARTITION_ERROR)
  {
    Fee_Job.JobResult = MEMIF_BLOCK_INVALID;
    NVM_JOB_ERROR_NOTIFICATION();
    Fee_Job.JobActiveId = FEE_JOB_IDLE;
    Fee_Job.JobState = FEE_JOB_STATE_IDLE;
    Fee_Job.RepeatStateMachine = FALSE;
  }
  else if (Fee_BlockInformation[Fee_Job.BlockId].LatestAddress == 0)
  {
    Fee_Job.JobResult = MEMIF_BLOCK_INVALID;
    NVM_JOB_ERROR_NOTIFICATION();
    Fee_Job.JobActiveId = FEE_JOB_IDLE;
    Fee_Job.JobState = FEE_JOB_STATE_IDLE;
    Fee_Job.RepeatStateMachine = FALSE;
  }
  else
  {
    fl_RequestStatus = FLS_READ(Fee_BlockInformation[Fee_Job.BlockId].LatestAddress, (uint8 *)&Fee_BlockHeader[0].BlockId, (FEE_HEADER_SIZE<<1));
    if(fl_RequestStatus == E_OK)
    {
      Fee_Job.JobState = FEE_JOB_STATE_READ_HEADER_WAIT;
      Fee_Job.RepeatStateMachine = FALSE;
    }
    else
    {
      Fee_Job.JobResult = MEMIF_JOB_FAILED;
      NVM_JOB_ERROR_NOTIFICATION();
      Fee_Job.JobActiveId = FEE_JOB_IDLE;
      Fee_Job.JobState = FEE_JOB_STATE_IDLE;
      Fee_Job.RepeatStateMachine = FALSE;
    }
  }
}

/**************************************************************************
Function name   : void Fee_JobReadHeaderWait(void)
Arguments       : void
Return type     : void
Description     :Service to Check the Flash Driver Job Result
**************************************************************************/
static void Fee_JobReadHeaderWait(void)
{
  MemIf_JobResultType fl_FlsJobStatus;
  Std_ReturnType fl_HeaderValidity;
  fl_FlsJobStatus = FLS_GET_JOB_RESULT();
  if(fl_FlsJobStatus != MEMIF_JOB_PENDING)
  {
    if(fl_FlsJobStatus == MEMIF_JOB_OK)
    {
      fl_HeaderValidity = Fee_HeaderValidate();
      if(fl_HeaderValidity == E_OK)
      {
        Fee_Job.JobState = FEE_JOB_STATE_READ_PAYLOAD;
        Fee_Job.RepeatStateMachine = TRUE;
      }
      else
      {
        Fee_Job.JobResult = MEMIF_BLOCK_INCONSISTENT;
        NVM_JOB_ERROR_NOTIFICATION();
        Fee_Job.JobActiveId = FEE_JOB_IDLE;
        Fee_Job.JobState = FEE_JOB_STATE_IDLE;
        Fee_Job.RepeatStateMachine = FALSE;
      }
    }
    else
    {
      Fee_Job.JobResult = MEMIF_JOB_FAILED;
      NVM_JOB_ERROR_NOTIFICATION();
      Fee_Job.JobActiveId = FEE_JOB_IDLE;
      Fee_Job.JobState = FEE_JOB_STATE_IDLE;
      Fee_Job.RepeatStateMachine = FALSE;
    }
  }
  else
  {
    /* Wait for Next State Machine */
    Fee_Job.RepeatStateMachine = FALSE;
  }
}

/**************************************************************************
Function name   : void Fee_HeaderValidate(void)
Arguments       : void
Return type     : void
Description     : Validate the Block
**************************************************************************/
static Std_ReturnType Fee_HeaderValidate(void)
{
  Std_ReturnType fl_RetVal;
  fl_RetVal = E_NOT_OK;
  
  if(Fee_BlockHeader[0].BlockId == (uint16)~Fee_BlockHeader[1].BlockId )
  {
    if(Fee_BlockHeader[0].PayloadLength == (uint16)~Fee_BlockHeader[1].PayloadLength)
    {
      fl_RetVal = E_OK;
    }
  }
  return fl_RetVal;
  return E_OK;
}

/**************************************************************************
Function name   : void Fee_JobReadPayload(void)
Arguments       : void
Return type     : void
Description     : Request Read Payload
**************************************************************************/
static void Fee_JobReadPayload(void)
{
  uint32 fl_PayLoadAddress;
  Std_ReturnType fl_RequestStatus;
  fl_PayLoadAddress = Fee_BlockInformation[Fee_Job.BlockId].LatestAddress + (FEE_HEADER_SIZE << 1) + Fee_Job.Offset;
  fl_RequestStatus = FLS_READ(fl_PayLoadAddress, (uint8 *)Fee_Job.RamAddress, Fee_Job.Length);
  if(fl_RequestStatus == E_OK)
  {
    Fee_Job.JobState = FEE_JOB_STATE_READ_PAYLOAD_WAIT;
    Fee_Job.RepeatStateMachine = FALSE;
  }
  else
  {
    Fee_Job.JobResult = MEMIF_JOB_FAILED;
    NVM_JOB_ERROR_NOTIFICATION();
    Fee_Job.JobActiveId = FEE_JOB_IDLE;
    Fee_Job.JobState = FEE_JOB_STATE_IDLE;
    Fee_Job.RepeatStateMachine = FALSE;
  }
}

/**************************************************************************
Function name   : void Fee_JobReadPayloadWait(void)
Arguments       : void
Return type     : void
Description     : Service to Check the Flash Driver Job Result 
**************************************************************************/
static void Fee_JobReadPayloadWait(void)
{
  MemIf_JobResultType fl_FlsJobStatus;
  fl_FlsJobStatus = FLS_GET_JOB_RESULT();
  if(fl_FlsJobStatus != MEMIF_JOB_PENDING)
  {
    if(fl_FlsJobStatus == MEMIF_JOB_OK)
    {
      Fee_Job.JobResult = MEMIF_JOB_OK;
      NVM_JOB_END_NOTIFICATION();
      Fee_Job.JobActiveId = FEE_JOB_IDLE;
      Fee_Job.JobState = FEE_JOB_STATE_IDLE;
      Fee_Job.RepeatStateMachine = FALSE;
    }
    else
    {
      Fee_Job.JobResult = MEMIF_JOB_FAILED;
      NVM_JOB_ERROR_NOTIFICATION();
      Fee_Job.JobActiveId = FEE_JOB_IDLE;
      Fee_Job.JobState = FEE_JOB_STATE_IDLE;
      Fee_Job.RepeatStateMachine = FALSE;
    }
  }
  else
  {
    /* Wait for Next State Machine */
    Fee_Job.RepeatStateMachine = FALSE;
  }
}


/**************************************************************************
Function name   : void Fee_JobStateProcess(void)
Arguments       : void
Return type     : void
Description     : Job State machine Process
**************************************************************************/
static void Fee_JobStateProcess(void)
{
  if((Fee_Job.PartitionState == FEE_PARTITION_STATE_IDLE) && (Fee_Job.SectorSwitchState == FEE_SECTOR_SWITCH_STATE_IDLE) && \
      (Fee_Job.SectorEraseState == FEE_SECTOR_ERASE_STATE_IDLE))
  {
    switch(Fee_Job.JobState)
    {

      case FEE_JOB_STATE_IDLE:
      break;
    
      case FEE_JOB_STATE_WRITE_HEADER1:
        Fee_JobWriteHeader1();
      break;
      
      case FEE_JOB_STATE_WRITE_HEADER1_WAIT:
        Fee_JobWriteHeader1Wait();
      break;
    
      case FEE_JOB_STATE_WRITE_PAYLOAD:
        Fee_JobWritePayload();
      break;
    
      case FEE_JOB_STATE_WRITE_PAYLOAD_WAIT:
        Fee_JobWritePayloadWait();
      break;
    
      case FEE_JOB_STATE_WRITE_HEADER2:
        Fee_JobWriteHeader2();
      break;
      
      case FEE_JOB_STATE_WRITE_HEADER2_WAIT:
        Fee_JobWriteHeader2Wait();
      break;
    
      case FEE_JOB_STATE_READ_HEADER:
        Fee_JobReadHeader();
      break;
    
      case FEE_JOB_STATE_READ_HEADER_WAIT:
        Fee_JobReadHeaderWait();
      break;
    
      case FEE_JOB_STATE_READ_PAYLOAD:
        Fee_JobReadPayload();
      break;
      
      case FEE_JOB_STATE_READ_PAYLOAD_WAIT:
        Fee_JobReadPayloadWait();
      break;
    }
  }
  else
  {
    /* Wait until Sector Switch or Partition Init is completed */
  }
}

/**************************************************************************
Function name   : void Fee_PartitionSectorHeaderRead(void)
Arguments       : void
Return type     : void
Description     : Sector Header Read init
**************************************************************************/
static void Fee_PartitionSectorHeaderRead(void)
{
  uint32 fl_SectorHeaderAddress;
  uint8 fl_PartionNo;
  Std_ReturnType fl_RequestStatus;
  fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
  fl_SectorHeaderAddress = ((uint32)Fee_SectorSearch.CurrentSectorId) * FEE_SECTOR_SIZE;
  fl_RequestStatus = FLS_READ(fl_SectorHeaderAddress,(uint8 *)&Fee_SectorHeader.SectorId,FEE_SECTOR_HEADER_SIZE);
  if(fl_RequestStatus == E_OK)
  {
    Fee_Job.PartitionState = FEE_PARTITION_STATE_SECTOR_HEADER_READ_WAIT;
    Fee_Job.RepeatStateMachine = FALSE;
  }
  else
  {
    Fee_Partition[fl_PartionNo].Status = FEE_PARTITION_ERROR;
    Fee_Job.PartitionState = FEE_PARTITION_STATE_IDLE;
    Fee_Job.RepeatStateMachine = TRUE;
  }
}

/**************************************************************************
Function name   : void Fee_PartitionSectorHeaderReadWait(void)
Arguments       : void
Return type     : void
Description     : Service to Check the Flash Driver Job Result 
**************************************************************************/
static void Fee_PartitionSectorHeaderReadWait(void)
{
  uint8 fl_PartionNo;
  MemIf_JobResultType fl_FlsJobStatus;
  fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
  fl_FlsJobStatus = FLS_GET_JOB_RESULT();
  if(fl_FlsJobStatus != MEMIF_JOB_PENDING)
  {
    if(fl_FlsJobStatus == MEMIF_JOB_OK)
    {
      Fee_Job.PartitionState = FEE_PARTITION_STATE_SECTOR_FOOTER_READ;
      Fee_Job.RepeatStateMachine = TRUE;
    }
    else
    {
      Fee_Partition[fl_PartionNo].Status = FEE_PARTITION_ERROR;
      Fee_Job.PartitionState = FEE_PARTITION_STATE_IDLE;
      Fee_Job.RepeatStateMachine = TRUE;
    }
  }
  else
  {
    /* Wait for Next State Machine */
    Fee_Job.RepeatStateMachine = FALSE;
  }
}

/**************************************************************************
Function name   : void Fee_PartitionSectorFooterRead(void)
Arguments       : void
Return type     : void
Description     : Request Footer Read
**************************************************************************/
static void Fee_PartitionSectorFooterRead(void)
{
  uint32 fl_SectorFooterAddress;
  uint8 fl_PartionNo;
  Std_ReturnType fl_RequestStatus;
  fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
  fl_SectorFooterAddress = (((uint32)Fee_SectorSearch.CurrentSectorId) * FEE_SECTOR_SIZE) + FEE_SECTOR_SIZE - FEE_SECTOR_FOOTER_SIZE ;
  fl_RequestStatus = FLS_READ(fl_SectorFooterAddress,(uint8 *)&Fee_SectorFooter.SectorId,FEE_SECTOR_FOOTER_SIZE);
  if(fl_RequestStatus == E_OK)
  {
    Fee_Job.PartitionState = FEE_PARTITION_STATE_WAIT_SECTOR_FOOTER_READ;
    Fee_Job.RepeatStateMachine = FALSE;
  }
  else
  {
    Fee_Partition[fl_PartionNo].Status = FEE_PARTITION_ERROR;
    Fee_Job.PartitionState = FEE_PARTITION_STATE_IDLE;
    Fee_Job.RepeatStateMachine = TRUE;
  }
}

/**************************************************************************
Function name   : void Fee_PartitionSectorFooterReadWait(void)
Arguments       : void
Return type     : void
Description     : Service to Check the Flash Driver Job Result 
**************************************************************************/
static void Fee_PartitionSectorFooterReadWait(void)
{
  uint8 fl_PartionNo;
  MemIf_JobResultType fl_FlsJobStatus;
  fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
  fl_FlsJobStatus = FLS_GET_JOB_RESULT();
  if(fl_FlsJobStatus != MEMIF_JOB_PENDING)
  {
    if(fl_FlsJobStatus == MEMIF_JOB_OK)
    {
      Fee_Job.PartitionState = FEE_PARTITION_STATE_VALIDATE_SECTOR;
      Fee_Job.RepeatStateMachine = TRUE;
    }
    else
    {
      Fee_Partition[fl_PartionNo].Status = FEE_PARTITION_ERROR;
      Fee_Job.PartitionState = FEE_PARTITION_STATE_IDLE;
      Fee_Job.RepeatStateMachine = TRUE;
    }
  }
  else
  {
    /* Wait for Next State Machine */
    Fee_Job.RepeatStateMachine = FALSE;
  }
}

/**************************************************************************
Function name   : void Fee_ValidateSector(void)
Arguments       : void
Return type     : void
Description     : Validate the latest sector
**************************************************************************/
static void Fee_ValidateSector(void)
{
  uint8 fl_PartionNo;
  uint8 fl_StartSectorId;
  uint8 fl_CurrentSectorId;
  uint8 fl_SectorCount;
  boolean fl_SectorValid;
  boolean fl_SectorEmpty;

  fl_SectorValid = FALSE;
  fl_SectorEmpty = FALSE;
  fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
  if((Fee_SectorHeader.SectorId == 0xFF) && (Fee_SectorHeader.count == 0xFF))
  {
    if((Fee_SectorFooter.SectorId == 0xFF) && (Fee_SectorFooter.count == 0xFF))
    {
      fl_SectorEmpty = TRUE;
    }
  }
  if(Fee_SectorHeader.SectorId == (uint8)~Fee_SectorFooter.SectorId)
  {
    if(Fee_SectorHeader.count == (uint8)~Fee_SectorFooter.count)
    {
      fl_SectorValid = TRUE;
    }
  }
  if(FALSE == fl_SectorEmpty)
  {
    if(FALSE != fl_SectorValid)
    {
      if(Fee_SectorSearch.ValidSectorId != 0xFF)
      {
        if(Fee_SectorSearch.count > Fee_SectorHeader.count)
        {
          if((Fee_SectorSearch.count - Fee_SectorHeader.count) > 1)
          {
            Fee_Partition[fl_PartionNo].EraseSectorId = Fee_SectorSearch.ValidSectorId;
            Fee_SectorSearch.ValidSectorId = Fee_SectorHeader.SectorId;
            Fee_SectorSearch.count = Fee_SectorHeader.SectorId;
            Fee_Job.SectorEraseState = FEE_SECTOR_ERASE_STATE_ERASE;
            Fee_Job.RepeatStateMachine = TRUE;
          }
          else
          {
            Fee_Partition[fl_PartionNo].EraseSectorId = Fee_SectorHeader.SectorId;
            Fee_Job.SectorEraseState = FEE_SECTOR_ERASE_STATE_ERASE;
            Fee_Job.RepeatStateMachine = TRUE;
          }
        }
        else
        {
          if((Fee_SectorHeader.count - Fee_SectorSearch.count) > 1)
          {
            Fee_Partition[fl_PartionNo].EraseSectorId = Fee_SectorHeader.SectorId;
            Fee_Job.SectorEraseState = FEE_SECTOR_ERASE_STATE_ERASE;
            Fee_Job.RepeatStateMachine = TRUE;
          }
          else
          {
            Fee_Partition[fl_PartionNo].EraseSectorId = Fee_SectorSearch.ValidSectorId;
            Fee_SectorSearch.ValidSectorId = Fee_SectorHeader.SectorId;
            Fee_SectorSearch.count = Fee_SectorHeader.SectorId;
            Fee_Job.SectorEraseState = FEE_SECTOR_ERASE_STATE_ERASE;
            Fee_Job.RepeatStateMachine = TRUE;
          }
        }
      }
      else
      {
        Fee_SectorSearch.ValidSectorId = Fee_SectorHeader.SectorId;
        Fee_SectorSearch.count = Fee_SectorHeader.SectorId;
      }
    }
    else
    {
      Fee_Partition[fl_PartionNo].EraseSectorId = Fee_SectorHeader.SectorId;
      Fee_Job.SectorEraseState = FEE_SECTOR_ERASE_STATE_ERASE;
    }
  }

  fl_StartSectorId = Fee_PartitionConfig[fl_PartionNo].StartVirtualAddress / FEE_SECTOR_SIZE;
  fl_CurrentSectorId = Fee_SectorSearch.CurrentSectorId;
  fl_SectorCount = fl_CurrentSectorId - fl_StartSectorId + 1; 

  if(Fee_PartitionConfig[fl_PartionNo].NumberOfSectors  > fl_SectorCount )
  {
    Fee_SectorSearch.CurrentSectorId = fl_CurrentSectorId + 1;
    Fee_Job.PartitionState = FEE_PARTITION_STATE_SECTOR_HEADER_READ;
    Fee_Job.RepeatStateMachine = TRUE;
  }
  else
  {
    if(Fee_SectorSearch.ValidSectorId == 0xFF)
    {
      Fee_Partition[fl_PartionNo].CurrentSectorId = fl_StartSectorId;
      Fee_Partition[fl_PartionNo].count = 0;
      Fee_Job.PartitionState = FEE_PARTITION_STATE_SECTOR_HEADER_WRITE;
      Fee_Job.RepeatStateMachine = TRUE;
    }
    else
    {
      Fee_Partition[fl_PartionNo].CurrentSectorId = Fee_SectorSearch.ValidSectorId;
      Fee_Partition[fl_PartionNo].count = Fee_SectorSearch.count;
      Fee_Partition[fl_PartionNo].NextFreeAddress = (Fee_Partition[fl_PartionNo].CurrentSectorId * FEE_SECTOR_SIZE) + FEE_SECTOR_HEADER_SIZE;
      Fee_Job.PartitionState = FEE_PARTITION_STATE_BLOCK_READ_HEADER;
      Fee_Job.RepeatStateMachine = TRUE;
    }
  }
}

/**************************************************************************
Function name   : void Fee_PartitionSectorHeaderWrite(void)
Arguments       : void
Return type     : void
Description     : Request Header Write
**************************************************************************/
static void Fee_PartitionSectorHeaderWrite(void)
{
  uint32 fl_SectorStartAddress;
  uint8 fl_PartionNo;
  Std_ReturnType fl_RequestStatus;
  fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
  Fee_SectorHeader.SectorId = Fee_Partition[fl_PartionNo].CurrentSectorId;
  Fee_SectorHeader.count = Fee_Partition[fl_PartionNo].count;
  Fee_SectorHeader.Reserved1 = 0xFFFF;
  Fee_SectorHeader.Reserved2 = 0xFFFF;
  Fee_SectorHeader.Reserved3 = 0xFFFF;
  fl_SectorStartAddress = (Fee_SectorHeader.SectorId)* FEE_SECTOR_SIZE;
  fl_RequestStatus = FLS_WRITE(fl_SectorStartAddress,(uint8 *)&Fee_SectorHeader.SectorId,FEE_SECTOR_HEADER_SIZE);
  if(fl_RequestStatus == E_OK)
  {
    Fee_Partition[fl_PartionNo].NextFreeAddress = Fee_Partition[fl_PartionNo].NextFreeAddress + FEE_SECTOR_HEADER_SIZE;
    Fee_Job.PartitionState = FEE_PARTITION_STATE_SECTOR_HEADER_WRITE_WAIT;
    Fee_Job.RepeatStateMachine = FALSE;
  }
  else
  {
    Fee_Partition[fl_PartionNo].Status = FEE_PARTITION_ERROR;
    Fee_Job.PartitionState = FEE_PARTITION_STATE_IDLE;
    Fee_Job.RepeatStateMachine = TRUE;
  }
}

/**************************************************************************
Function name   : void Fee_PartitionSectorHeaderWriteWait(void)
Arguments       : void
Return type     : void
Description     : Service to Check the Flash Driver Job Result 
**************************************************************************/
static void Fee_PartitionSectorHeaderWriteWait(void)
{
  uint8 fl_PartionNo;
  MemIf_JobResultType fl_FlsJobStatus;
  fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
  fl_FlsJobStatus = FLS_GET_JOB_RESULT();
  if(fl_FlsJobStatus != MEMIF_JOB_PENDING)
  {
    if(fl_FlsJobStatus == MEMIF_JOB_OK)
    {
      Fee_Job.PartitionState = FEE_PARTITION_STATE_SECTOR_FOOTER_WRITE;
      Fee_Job.RepeatStateMachine = TRUE;
    }
    else
    {
      Fee_Partition[fl_PartionNo].Status = FEE_PARTITION_ERROR;
      Fee_Job.PartitionState = FEE_PARTITION_STATE_IDLE;
      Fee_Job.RepeatStateMachine = TRUE;
    }
  }
  else
  {
    /* Wait for Next State Machine */
    Fee_Job.RepeatStateMachine = FALSE;
  }
}

/**************************************************************************
Function name   : void Fee_PartitionSectorFooterWrite(void)
Arguments       : void
Return type     : void
Description     : Request Footer Write
**************************************************************************/
static void Fee_PartitionSectorFooterWrite(void)
{
  uint32 fl_FooterStartAddress;
  uint8 fl_PartionNo;
  Std_ReturnType fl_RequestStatus;
  fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
  Fee_SectorFooter.SectorId = (uint8)~Fee_Partition[fl_PartionNo].CurrentSectorId;
  Fee_SectorFooter.count = (uint8)~Fee_Partition[fl_PartionNo].count;
  Fee_SectorFooter.Reserved1 = 0;
  Fee_SectorFooter.Reserved2 = 0;
  Fee_SectorFooter.Reserved3 = 0;
  fl_FooterStartAddress = ((uint32)Fee_Partition[fl_PartionNo].CurrentSectorId * FEE_SECTOR_SIZE) + FEE_SECTOR_SIZE - FEE_SECTOR_FOOTER_SIZE ;
  fl_RequestStatus = FLS_WRITE(fl_FooterStartAddress,(uint8 *)&Fee_SectorFooter.SectorId,FEE_SECTOR_FOOTER_SIZE);
  if(fl_RequestStatus == E_OK)
  {
    Fee_Job.PartitionState = FEE_PARTITION_STATE_SECTOR_FOOTER_WRITE_WAIT;
    Fee_Job.RepeatStateMachine = FALSE;
  }
  else
  {
    Fee_Partition[fl_PartionNo].Status = FEE_PARTITION_ERROR;
    Fee_Job.PartitionState = FEE_PARTITION_STATE_IDLE;
    Fee_Job.RepeatStateMachine = TRUE;
  }
}

/**************************************************************************
Function name   : void Fee_PartitionSectorFooterWriteWait(void)
Arguments       : void
Return type     : void
Description     : Service to Check the Flash Driver Job Result. 
**************************************************************************/
static void Fee_PartitionSectorFooterWriteWait(void)
{
  uint8 fl_PartionNo;
  MemIf_JobResultType fl_FlsJobStatus;
  fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
  fl_FlsJobStatus = FLS_GET_JOB_RESULT();
  if(fl_FlsJobStatus != MEMIF_JOB_PENDING)
  {
    if(fl_FlsJobStatus == MEMIF_JOB_OK)
    {
      Fee_Partition[fl_PartionNo].Status = FEE_PARTITION_READY;
      Fee_Job.PartitionState = FEE_PARTITION_STATE_IDLE;
      Fee_Job.RepeatStateMachine = TRUE;
    }
    else
    {
      Fee_Partition[fl_PartionNo].Status = FEE_PARTITION_ERROR;
      Fee_Job.PartitionState = FEE_PARTITION_STATE_IDLE;
      Fee_Job.RepeatStateMachine = TRUE;
    }
  }
  else
  {
    /* Wait for Next State Machine */
    Fee_Job.RepeatStateMachine = FALSE;
  }
}

/**************************************************************************
Function name   : void Fee_PartitionBlockReadHeader(void)
Arguments       : void
Return type     : void
Description     : Request Block Read
**************************************************************************/
static void Fee_PartitionBlockReadHeader(void)
{
  uint8 fl_PartionNo;
  Std_ReturnType fl_RequestStatus;
  fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
  fl_RequestStatus = FLS_READ(Fee_Partition[fl_PartionNo].NextFreeAddress, (uint8 *)&Fee_BlockHeader[0].BlockId, (FEE_HEADER_SIZE << 1));
  if(fl_RequestStatus == E_OK)
  {
    Fee_Job.PartitionState = FEE_PARTITION_STATE_BLOCK_READ_HEADER_WAIT;
    Fee_Job.RepeatStateMachine = FALSE;
  }
  else
  {
    Fee_Partition[fl_PartionNo].Status = FEE_PARTITION_ERROR;
    Fee_Job.PartitionState = FEE_PARTITION_STATE_IDLE;
    Fee_Job.RepeatStateMachine = TRUE;
  }
}

/**************************************************************************
Function name   : void Fee_PartitionBlockReadHeaderWait(void)
Arguments       : void
Return type     : void
Description     : Service to Check the Flash Driver Job Result 
**************************************************************************/
static void Fee_PartitionBlockReadHeaderWait(void)
{
  uint8 fl_PartionNo;
  MemIf_JobResultType fl_FlsJobStatus;
  fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
  fl_FlsJobStatus = FLS_GET_JOB_RESULT();
  if(fl_FlsJobStatus != MEMIF_JOB_PENDING)
  {
    if(fl_FlsJobStatus == MEMIF_JOB_OK)
    {
      Fee_Job.PartitionState = FEE_PARTITION_STATE_BLOCK_READ_HEADER_VALIDATE;
      Fee_Job.RepeatStateMachine = TRUE;
    }
    else
    {
      Fee_Partition[fl_PartionNo].Status = FEE_PARTITION_ERROR;
      Fee_Job.PartitionState = FEE_PARTITION_STATE_IDLE;
      Fee_Job.RepeatStateMachine = TRUE;
    }
  }
  else
  {
    /* Wait for Next State Machine */
    Fee_Job.RepeatStateMachine = FALSE;
  }
}

/**************************************************************************
Function name   : void Fee_PartitionBlockValidate(void)
Arguments       : void
Return type     : void
Description     : Validate Block
**************************************************************************/
static void Fee_PartitionBlockValidate(void)
{
  uint16 fl_BlockId;
  uint8 fl_PartionNo;
  Std_ReturnType fl_BlockValid;
  fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
  fl_BlockId = Fee_BlockHeader[0].BlockId;
  if(fl_BlockId != 0xFFFF)
  {
    fl_BlockValid = Fee_HeaderValidate();
    if(fl_BlockValid == E_OK)
    {
      Fee_BlockInformation[fl_BlockId].LatestAddress = Fee_Partition[fl_PartionNo].NextFreeAddress;
    }
    Fee_Partition[fl_PartionNo].NextFreeAddress =  Fee_Partition[fl_PartionNo].NextFreeAddress + Fee_BlockConfig[fl_BlockId].BlockSize + (FEE_HEADER_SIZE << 1);
    Fee_Job.PartitionState = FEE_PARTITION_STATE_BLOCK_READ_HEADER;
    Fee_Job.RepeatStateMachine = TRUE;
  }
  else
  {
    Fee_Job.PartitionState = FEE_PARTITION_STATE_IDLE;
    Fee_Job.RepeatStateMachine = TRUE;
  }
}

/**************************************************************************
Function name   : void Fee_PartitionStateProcess(void)
Arguments       : void
Return type     : void
Description     : Partition initialisation State machine
**************************************************************************/
static void Fee_PartitionStateProcess(void)
{
  if(Fee_Job.SectorEraseState == FEE_SECTOR_ERASE_STATE_IDLE)
  {
    switch(Fee_Job.PartitionState)
    {
      case FEE_PARTITION_STATE_IDLE:
      break;
    
      case FEE_PARTITION_STATE_SECTOR_HEADER_READ:
        Fee_PartitionSectorHeaderRead();
      break;
  
      case FEE_PARTITION_STATE_SECTOR_HEADER_READ_WAIT:
        Fee_PartitionSectorHeaderReadWait();
      break;
  
      case FEE_PARTITION_STATE_SECTOR_FOOTER_READ:
        Fee_PartitionSectorFooterRead();
      break;
  
      case FEE_PARTITION_STATE_WAIT_SECTOR_FOOTER_READ:
        Fee_PartitionSectorFooterReadWait();
      break;
  
      case FEE_PARTITION_STATE_VALIDATE_SECTOR:
        Fee_ValidateSector();
      break;
    
      case FEE_PARTITION_STATE_SECTOR_HEADER_WRITE:
        Fee_PartitionSectorHeaderWrite();
      break;
    
      case FEE_PARTITION_STATE_SECTOR_HEADER_WRITE_WAIT:
        Fee_PartitionSectorHeaderWriteWait();
      break;
    
      case FEE_PARTITION_STATE_SECTOR_FOOTER_WRITE:
        Fee_PartitionSectorFooterWrite();
      break;

      case FEE_PARTITION_STATE_SECTOR_FOOTER_WRITE_WAIT:
        Fee_PartitionSectorFooterWriteWait();
      break;
    
      case FEE_PARTITION_STATE_BLOCK_READ_HEADER:
        Fee_PartitionBlockReadHeader();
      break;
    
      case FEE_PARTITION_STATE_BLOCK_READ_HEADER_WAIT:
        Fee_PartitionBlockReadHeaderWait();
      break;
    
      case FEE_PARTITION_STATE_BLOCK_READ_HEADER_VALIDATE:
        Fee_PartitionBlockValidate();
      break;
    }
  }
}

/**************************************************************************
Function name   : void Fee_SectorErase(void)
Arguments       : void
Return type     : void
Description     : Request Sector Erase
**************************************************************************/
static void Fee_SectorErase(void)
{
  uint32 fl_EraseAddress;
  uint8 fl_PartionNo;
  Std_ReturnType fl_RequestStatus;
  fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
  fl_EraseAddress = Fee_Partition[fl_PartionNo].EraseSectorId * FEE_SECTOR_SIZE;
  fl_RequestStatus = FLS_ERASE(fl_EraseAddress,FEE_SECTOR_SIZE);
  if(fl_RequestStatus == E_OK)
  {
    Fee_Job.SectorEraseState = FEE_SECTOR_ERASE_STATE_ERASE_WAIT;
    Fee_Job.RepeatStateMachine = TRUE;
  }
  else
  {
    /* TO_DISCUSS */
  }
}

/**************************************************************************
Function name   : void Fee_SectorEraseWait(void)
Arguments       : void
Return type     : void
Description     : Service to Check the Flash Driver Job Result 
**************************************************************************/
static void Fee_SectorEraseWait(void)
{
  MemIf_JobResultType fl_FlsJobStatus;
  fl_FlsJobStatus = FLS_GET_JOB_RESULT();
  if(fl_FlsJobStatus != MEMIF_JOB_PENDING)
  {
    if(fl_FlsJobStatus == MEMIF_JOB_OK)
    {
      Fee_Job.SectorEraseState = FEE_SECTOR_ERASE_STATE_IDLE;
      Fee_Job.RepeatStateMachine = TRUE;
    }
    else
    {
      /* TO_DISCUSS */
    }
  }
  else
  {
    /* Wait for Next State Machine */
    Fee_Job.RepeatStateMachine = FALSE;
  }
}

/**************************************************************************
Function name   : void Fee_SectorEraseStateProcess(void)
Arguments       : void
Return type     : void
Description     : Sector Erase State machine 
**************************************************************************/
static void Fee_SectorEraseStateProcess(void)
{
  switch(Fee_Job.SectorEraseState)
  {
    case FEE_SECTOR_ERASE_STATE_IDLE:
    break;
    
    case FEE_SECTOR_ERASE_STATE_ERASE:
      Fee_SectorErase();
    break;
  
    case FEE_SECTOR_ERASE_STATE_ERASE_WAIT:
      Fee_SectorEraseWait();
    break;
  }
}

/**************************************************************************
Function name   : void Fee_SectorSwitchHeaderWrite(void)
Arguments       : void
Return type     : void
Description     : Request Se4ctor Header Write
**************************************************************************/
static void Fee_SectorSwitchHeaderWrite(void)
{
  uint32 fl_SectorWriteAddress;
  uint8 fl_PartionNo;
  uint8 fl_StartSectorId;
  uint8 fl_CurrentSectorId;
  Std_ReturnType fl_RequestStatus;
  fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
  Fee_Partition[fl_PartionNo].OldSectorId = Fee_Partition[fl_PartionNo].CurrentSectorId;
  Fee_Partition[fl_PartionNo].count = Fee_Partition[fl_PartionNo].count + 1;
  Fee_Partition[fl_PartionNo].CurrentSectorId = Fee_Partition[fl_PartionNo].CurrentSectorId +1;
  fl_StartSectorId = Fee_PartitionConfig[fl_PartionNo].StartVirtualAddress / FEE_SECTOR_SIZE;
  fl_CurrentSectorId = Fee_Partition[fl_PartionNo].CurrentSectorId - fl_StartSectorId;
  if(Fee_PartitionConfig[fl_PartionNo].NumberOfSectors <= fl_CurrentSectorId)
  {
    Fee_Partition[fl_PartionNo].CurrentSectorId = fl_StartSectorId;
  }
  Fee_SectorHeader.SectorId = Fee_Partition[fl_PartionNo].CurrentSectorId;
  Fee_SectorHeader.count = Fee_Partition[fl_PartionNo].count;
  Fee_SectorHeader.Reserved1 = 0xFFFF;
  Fee_SectorHeader.Reserved2 = 0xFFFF;
  Fee_SectorHeader.Reserved3 = 0xFFFF;
  fl_SectorWriteAddress = Fee_SectorHeader.SectorId * FEE_SECTOR_SIZE;
  fl_RequestStatus = FLS_WRITE(fl_SectorWriteAddress,(uint8 *)&Fee_SectorHeader.SectorId,FEE_SECTOR_HEADER_SIZE);
  if(fl_RequestStatus == E_OK)
  {
    Fee_Partition[fl_PartionNo].NextFreeAddress = fl_SectorWriteAddress + FEE_SECTOR_HEADER_SIZE;
    Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_HEADER_WRITE_WAIT;
    Fee_Job.RepeatStateMachine = FALSE;
  }
  else
  {
    /* TO_DISCUSS */
  }
}

/**************************************************************************
Function name   : void Fee_SectorSwitchHeaderWriteWait(void)
Arguments       : void
Return type     : void
Description     : Service to Check the Flash Driver Job Result 
**************************************************************************/
static void Fee_SectorSwitchHeaderWriteWait(void)
{
  uint8 fl_PartionNo;
  MemIf_JobResultType fl_FlsJobStatus;
  fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
  fl_FlsJobStatus = FLS_GET_JOB_RESULT();
  if(fl_FlsJobStatus != MEMIF_JOB_PENDING)
  {
    if(fl_FlsJobStatus == MEMIF_JOB_OK)
    {
      Fee_Job.SearchBlockId = 1;
      if(Fee_BlockConfig[Fee_Job.SearchBlockId].PartitionNo == fl_PartionNo)
      {
        Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_BLOCK_READ;
        Fee_Job.RepeatStateMachine = TRUE;
      }
      else
      {
        Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_SEARCH_NEXT_BLOCK;
        Fee_Job.RepeatStateMachine = TRUE;
      }
    }
    else
    {
      /* TO_DISCUSS */
    }
  }
  else
  {
    /* Wait for Next State Machine */
    Fee_Job.RepeatStateMachine = FALSE;
  }
}

/**************************************************************************
Function name   : void Fee_SectorSwitchSearchNextBlock(void)
Arguments       : void
Return type     : void
Description     : Search Next Block
**************************************************************************/
static void Fee_SectorSwitchSearchNextBlock(void)
{
  uint8 fl_PartionNo;
  fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
  Fee_Job.SearchBlockId = Fee_Job.SearchBlockId + 1;
  if(Fee_Job.SearchBlockId >= FEE_NUM_BLOCKS)
  {
    Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_SECTOR_FOOTER_WRITE;
    Fee_Job.RepeatStateMachine = TRUE;
  }
  else
  {
    if(Fee_BlockConfig[Fee_Job.SearchBlockId].PartitionNo == fl_PartionNo)
    {
      Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_BLOCK_READ;
      Fee_Job.RepeatStateMachine = TRUE;
    }
    else
    {
      Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_SEARCH_NEXT_BLOCK;
      Fee_Job.RepeatStateMachine = TRUE;
    }
  }
}

/**************************************************************************
Function name   : void Fee_SectorSwitchBlockRead(void)
Arguments       : void
Return type     : void
Description     : Request Block Read
**************************************************************************/
static void Fee_SectorSwitchBlockRead(void)
{
  Std_ReturnType fl_RequestStatus;
  if(Fee_BlockInformation[Fee_Job.SearchBlockId].LatestAddress != 0)
  {
    fl_RequestStatus = FLS_READ(Fee_BlockInformation[Fee_Job.SearchBlockId].LatestAddress, (uint8 *)&Fee_BlockReadBuffer[0], (Fee_BlockConfig[Fee_Job.BlockId].BlockSize + (FEE_HEADER_SIZE << 1)));
    if(fl_RequestStatus == E_OK)
    {
      Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_BLOCK_READ_WAIT;
      Fee_Job.RepeatStateMachine = FALSE;
    }
    else
    {
      /* TO_DISCUSS */
    }
  }
  else
  {
      Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_SEARCH_NEXT_BLOCK;
      Fee_Job.RepeatStateMachine = TRUE;
  }
}

/**************************************************************************
Function name   : void Fee_SectorSwitchBlockReadWait(void)
Arguments       : void
Return type     : void
Description     : Service to Check the Flash Driver Job Result
**************************************************************************/
static void Fee_SectorSwitchBlockReadWait(void)
{
  MemIf_JobResultType fl_FlsJobStatus;
  fl_FlsJobStatus = FLS_GET_JOB_RESULT();
  if(fl_FlsJobStatus != MEMIF_JOB_PENDING)
  {
    if(fl_FlsJobStatus == MEMIF_JOB_OK)
    {
      Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_BLOCK_WRITE;
      Fee_Job.RepeatStateMachine = TRUE;
    }
    else
    {
      /* TO_DISCUSS */
    }
  }
  else
  {
    /* Wait for Next State Machine */
    Fee_Job.RepeatStateMachine = FALSE;
  }
}

/**************************************************************************
Function name   : void Fee_SectorSwitchBlockWrite(void)
Arguments       : void
Return type     : void
Description     : Request Block Write
**************************************************************************/
static void Fee_SectorSwitchBlockWrite(void)
{
  uint8 fl_PartionNo;
  Std_ReturnType fl_RequestStatus;
  fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
  fl_RequestStatus = FLS_WRITE(Fee_Partition[fl_PartionNo].NextFreeAddress, (uint8 *)&Fee_BlockReadBuffer[0], (Fee_BlockConfig[Fee_Job.BlockId].BlockSize + (FEE_HEADER_SIZE << 1)));
  if(fl_RequestStatus == E_OK)
  {
    Fee_Partition[fl_PartionNo].NextFreeAddress = Fee_Partition[fl_PartionNo].NextFreeAddress + Fee_BlockConfig[Fee_Job.BlockId].BlockSize + (FEE_HEADER_SIZE << 1);
    Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_BLOCK_WRITE_WAIT;
    Fee_Job.RepeatStateMachine = FALSE;
  }
  else
  {
    /* TO_DISCUSS */
  }
}

/**************************************************************************
Function name   : void Fee_SectorSwitchBlockWriteWait(void)
Arguments       : void
Return type     : void
Description     : Service to Check the Flash Driver Job Result
**************************************************************************/
static void Fee_SectorSwitchBlockWriteWait(void)
{
  uint8 fl_PartionNo;
  MemIf_JobResultType fl_FlsJobStatus;
  fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
  fl_FlsJobStatus = FLS_GET_JOB_RESULT();
  if(fl_FlsJobStatus != MEMIF_JOB_PENDING)
  {
    if(fl_FlsJobStatus == MEMIF_JOB_OK)
    {
      Fee_BlockInformation[Fee_Job.SearchBlockId].LatestAddress = Fee_Partition[fl_PartionNo].NextFreeAddress - Fee_BlockConfig[Fee_Job.BlockId].BlockSize - (FEE_HEADER_SIZE << 1);
      Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_SEARCH_NEXT_BLOCK;
      Fee_Job.RepeatStateMachine = TRUE;
    }
    else
    {
      /* TO_DISCUSS */
    }
  }
  else
  {
    /* Wait for Next State Machine */
    Fee_Job.RepeatStateMachine = FALSE;
  }
}

/**************************************************************************
Function name   : void Fee_SectorSwitchSectorFooterWrite(void)
Arguments       : void
Return type     : void
Description     : Request Sector Footer Write
**************************************************************************/
static void Fee_SectorSwitchSectorFooterWrite(void)
{
  uint32 fl_SectorWriteAddress;
  uint8 fl_PartionNo;
  Std_ReturnType fl_RequestStatus;
  fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
  Fee_SectorFooter.SectorId = (uint8)~Fee_Partition[fl_PartionNo].CurrentSectorId;
  Fee_SectorFooter.count = (uint8)~Fee_Partition[fl_PartionNo].count;
  Fee_SectorFooter.Reserved1 = 0;
  Fee_SectorFooter.Reserved2 = 0;
  Fee_SectorFooter.Reserved3 = 0;
  fl_SectorWriteAddress =  (Fee_Partition[fl_PartionNo].CurrentSectorId * FEE_SECTOR_SIZE) + FEE_SECTOR_SIZE - FEE_SECTOR_FOOTER_SIZE ;
  fl_RequestStatus = FLS_WRITE(fl_SectorWriteAddress, (uint8 *)&Fee_SectorFooter.SectorId, FEE_SECTOR_FOOTER_SIZE);
  if(fl_RequestStatus == E_OK)
  {
    Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_SECTOR_FOOTER_WRITE_WAIT;
    Fee_Job.RepeatStateMachine = FALSE;
  }
  else
  {
    /* TO_DISCUSS */
  }
}

/**************************************************************************
Function name   : void Fee_SectorSwitchSectorFooterWriteWait(void)
Arguments       : void
Return type     : void
Description     : Service to Check the Flash Driver Job Result
**************************************************************************/
static void Fee_SectorSwitchSectorFooterWriteWait(void)
{
  uint8 fl_PartionNo;
  MemIf_JobResultType fl_FlsJobStatus;
  fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
  fl_FlsJobStatus = FLS_GET_JOB_RESULT();
  if(fl_FlsJobStatus != MEMIF_JOB_PENDING)
  {
    if(fl_FlsJobStatus == MEMIF_JOB_OK)
    {
      Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_IDLE;
      Fee_Partition[fl_PartionNo].EraseSectorId = Fee_Partition[fl_PartionNo].OldSectorId;
      Fee_Job.SectorEraseState = FEE_SECTOR_ERASE_STATE_ERASE;
      Fee_Job.RepeatStateMachine = TRUE;
    }
    else
    {
      /* TO_DISCUSS */
    }
  }
  else
  {
    /* Wait for Next State Machine */
    Fee_Job.RepeatStateMachine = FALSE;
  }
}

/**************************************************************************
Function name   : void Fee_SectorSwitchStateProcess(void)
Arguments       : void
Return type     : void
Description     : Sector Switch State machine
**************************************************************************/
static void Fee_SectorSwitchStateProcess(void)
{
  if(Fee_Job.SectorEraseState == FEE_SECTOR_ERASE_STATE_IDLE)
  {
    switch(Fee_Job.SectorSwitchState)
    {
      case FEE_SECTOR_SWITCH_STATE_IDLE:
      break;
    
      case FEE_SECTOR_SWITCH_STATE_HEADER_WRITE:
        Fee_SectorSwitchHeaderWrite();
      break;
    
      case FEE_SECTOR_SWITCH_STATE_HEADER_WRITE_WAIT:
        Fee_SectorSwitchHeaderWriteWait();
      break;
    
      case FEE_SECTOR_SWITCH_STATE_SEARCH_NEXT_BLOCK:
        Fee_SectorSwitchSearchNextBlock();
      break;
    
      case FEE_SECTOR_SWITCH_STATE_BLOCK_READ:
        Fee_SectorSwitchBlockRead();
      break;
    
      case FEE_SECTOR_SWITCH_STATE_BLOCK_READ_WAIT:
        Fee_SectorSwitchBlockReadWait();
      break;
    
      case FEE_SECTOR_SWITCH_STATE_BLOCK_WRITE:
        Fee_SectorSwitchBlockWrite();
      break;
    
      case FEE_SECTOR_SWITCH_STATE_BLOCK_WRITE_WAIT:
        Fee_SectorSwitchBlockWriteWait();
      break;
    
      case FEE_SECTOR_SWITCH_STATE_SECTOR_FOOTER_WRITE:
        Fee_SectorSwitchSectorFooterWrite();
      break;
    
      case FEE_SECTOR_SWITCH_STATE_SECTOR_FOOTER_WRITE_WAIT:
        Fee_SectorSwitchSectorFooterWriteWait();
      break;
    }
  }
}

/**************************************************************************
Function name   : void Fee_MainFunction(void)
Arguments       : void
Return type     : void
Description     : Service to handle the requested read / write / erase jobs and the 
                  internal management operations
**************************************************************************/
void Fee_MainFunction(void)
{
  do
  {
    Fee_JobStateProcess();
    Fee_PartitionStateProcess();
    Fee_SectorEraseStateProcess();
    Fee_SectorSwitchStateProcess();
  }while(FALSE != Fee_Job.RepeatStateMachine);
}


#endif /* FEE_C */
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
/*Date              : 05-02-2016                                            */
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
/*Change Description:Write, Read, Sector Switch, Partition init implemented */
/*--------------------------------------------------------------------------*/
