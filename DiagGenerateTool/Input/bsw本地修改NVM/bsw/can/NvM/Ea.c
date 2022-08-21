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
*  File Name         :  Ea.c                                                 *
*  Module Short Name :  Ea                                                   *
*  Description       : Request handling of Ea data module                    *
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
#ifndef EA_C
#define EA_C
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "Ea.h"
#include "Ea_Cbk.h"
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
#define EA_INVALIDATION_BIT         (uint8)4

#define EA_DATASET_SELECTION_MASK   ((1 << Ea_DatasetSelectionBits) -1)

#define EA_ERASED_EEPROM_VALUE      (uint8)255

#define EA_INVALID_INSTANCE_COUNT   (uint8)255

#define EA_IMMEDIATE_DATA           (uint8)1

#define EA_VERIFICATION_ENABLED     (uint8)2

/* Job JobActiveId */
#define EA_JOB_IDLE                      (uint8)0
#define EA_JOB_READ                      (uint8)1
#define EA_JOB_WRITE                     (uint8)2
#define EA_JOB_ERASE                     (uint8)3
#define EA_JOB_INVALIDATE                (uint8)4

/* Ea Internal States */
#define EA_STATE_IDLE                    (uint8)0

#define EA_STATE_READ_START              (uint8)1
#define EA_STATE_READ_FIND_INSTANCE      (uint8)2
#define EA_STATE_READ_HEADER             (uint8)3
#define EA_STATE_READ_HEADER_VALIDATE    (uint8)4
#define EA_STATE_READ_PAYLOAD            (uint8)5
#define EA_STATE_READ_PAYLOAD_CBK_WAIT   (uint8)6
#define EA_STATE_READ_END_NOTIFY         (uint8)7
#define EA_STATE_READ_ERROR_NOTIFY       (uint8)8

#define EA_STATE_WRITE_HEADER1           (uint8)9
#define EA_STATE_WRITE_HEADER1_CBK_WAIT  (uint8)10
#define EA_STATE_VERIFY_HEADER1          (uint8)11
#define EA_STATE_VERIFY_HEADER1_CBK_WAIT (uint8)12
#define EA_STATE_WRITE_PAYLOAD           (uint8)13
#define EA_STATE_WRITE_PAYLOAD_CBK_WAIT  (uint8)14
#define EA_STATE_VERIFY_PAYLOAD          (uint8)15
#define EA_STATE_VERIFY_PAYLOAD_CBK_WAIT (uint8)16
#define EA_STATE_WRITE_HEADER2           (uint8)17
#define EA_STATE_WRITE_HEADER2_CBK_WAIT  (uint8)18
#define EA_STATE_VERIFY_HEADER2          (uint8)19
#define EA_STATE_VERIFY_HEADER2_CBK_WAIT (uint8)20
#define EA_STATE_WRITE_END_NOTIFY        (uint8)21
#define EA_STATE_WRITE_ERROR_NOTIFY      (uint8)22
 
#define EA_STATE_ERASE                   (uint8)24
#define EA_STATE_ERASE_CBK_WAIT          (uint8)25


/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/
typedef struct{
  uint8*                ClientAddress;
  uint16                BlockNumber;
  uint16                Offset;
  uint16                Length;
  uint16                BlockIndex;
  uint8                 JobActiveId;
  uint8                 JobState;
  MemIf_JobResultType   JobResult;
  MemIf_JobResultType   Eep_JobResult;
  uint8                 ManagementData[2];
  boolean               BlockInvalid;
  boolean               CbkServiced;
  boolean               ProcessState;
}Ea_Descriptor_Type;

typedef struct{
  uint8 Counter;
  uint8 PreviousHeaderValue;
  uint8 CurrentHeaderValue[2];
  uint8 ValidInstance;
  uint8 FailureCount;
}Ea_InstanceSearch_Type;

typedef struct{
  uint8 CurrentInstance;
  uint8 CurrentInstanceHeader;
}Ea_BlockInformation_Type;


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

static Ea_Descriptor_Type       Ea_Descriptor;
static Ea_InstanceSearch_Type   Ea_InstanceSearch;
static Ea_BlockInformation_Type Ea_BlockInformation[EA_NUM_BLOCKS];

/*****************************************************************************
*                              Limited Scope Prototypes                      *
******************************************************************************/
static void Ea_ProcessJob(void);
static void Ea_ProcessJob_Read(void);
static void Ea_ProcessJob_Write(void);
static void Ea_ProcessJob_Erase(void);

static uint16 Ea_GetBlockIndex(uint16 BlockNumber_u16);
static uint8 Ea_ValidateManagementData(uint8* p_Value_u8);

static void Ea_ReadStart(void);
static void Ea_ReadFindInstance(void);
static void Ea_ReadHeader(void);
static void Ea_ReadHeaderValidate(void);
static void Ea_ReadPayLoad(void);
static void Ea_ReadPayLoadCbkWait(void);
static void Ea_ReadEndNotify(void);
static void Ea_ReadErrorNotify(void);

static void Ea_WriteHeader1(void);
static void Ea_WriteHeader1CbkWait(void);
static void Ea_WritePayload(void);
static void Ea_WritePayloadCbkWait(void);
static void Ea_WriteHeader2(void);
static void Ea_WriteHeader2CbkWait(void);
static void Ea_WriteEndNotify(void);
static void Ea_WriteErrorNotify(void);

static void Ea_VerifyHeader1(void);
static void Ea_VerifyHeader1CbkWait(void);
static void Ea_VerifyPayload(void);
static void Ea_VerifyPayloadCbkWait(void);
static void Ea_VerifyHeader2(void);
static void Ea_VerifyHeader2CbkWait(void);

/*****************************************************************************
*                   Functions                                                *
******************************************************************************/

/**************************************************************************
Function name       : void Ea_Init(void)
Description         : Initializes the EEPROM abstraction module
Parameters (in)     : None. 
Parameters (out)    : None
Return value        : None 
Design Information  : 
**************************************************************************/
void Ea_Init(void)
{
    uint8 Count;
    
    MemLib_MemSet(&Ea_Descriptor, 0, sizeof(Ea_Descriptor_Type));
    
    Ea_InstanceSearch.PreviousHeaderValue   = EA_ERASED_EEPROM_VALUE;
    Ea_InstanceSearch.CurrentHeaderValue[0] = EA_ERASED_EEPROM_VALUE;
    Ea_InstanceSearch.CurrentHeaderValue[1] = EA_ERASED_EEPROM_VALUE;
    Ea_InstanceSearch.Counter  = 0;
    Ea_InstanceSearch.FailureCount = 0;
    Ea_InstanceSearch.ValidInstance = 255;
    for (Count=0; Count < EA_NUM_BLOCKS;  Count++)
    {
        Ea_BlockInformation[Count].CurrentInstance = EA_INVALID_INSTANCE_COUNT;
        Ea_BlockInformation[Count].CurrentInstanceHeader = EA_ERASED_EEPROM_VALUE;
    }

}

/**************************************************************************
Function name       : void Ea_SetMode(MemIf_ModeType Mode)
Description         : Service to call the Eep_SetMode function of the 
                      underlying EEEPROM driver 
Parameters (in)     : Mode - Desired mode for the underlying EEPROM driver slow/fast 
Parameters (out)    : None
Return value        : None 
Design Information  :
**************************************************************************/
void Ea_SetMode(MemIf_ModeType Mode)
{
}

/**************************************************************************
Function name       : Std_ReturnType Ea_Read(uint16 BlockNumber, uint16 BlockOffset, 
                                                uint8* DataBufferPtr, uint16 Length);
Description         : Service to initiate a read job. 
Parameters (in)     : BlockNumber   - Number of logical block, also denoting start address 
                                      of that block in EEPROM.
                      BlockOffset   - Read address offset inside the block
                      Length        - Number of bytes to read
Parameters (out)    : DataBufferPtr - Pointer to data buffer
Return value        : E_OK: The requested job has been accepted by the module. 
                      E_NOT_OK: The requested job has not been accepted by the EA module. 
Design Information  :
**************************************************************************/
Std_ReturnType Ea_Read(uint16 BlockNumber, uint16 BlockOffset, uint8* DataBufferPtr, uint16 Length)
{
    Std_ReturnType retVal;
    retVal = E_NOT_OK ;
    if (Ea_Descriptor.JobActiveId == EA_JOB_IDLE)
    {
        MemLib_MemSet(&Ea_Descriptor, 0, sizeof(Ea_Descriptor_Type));
        Ea_Descriptor.BlockNumber   = BlockNumber;
        Ea_Descriptor.Offset        = BlockOffset;
        Ea_Descriptor.Length        = Length;
        Ea_Descriptor.ClientAddress = DataBufferPtr;
        Ea_Descriptor.JobActiveId   = EA_JOB_READ;
        Ea_Descriptor.JobResult     = MEMIF_JOB_PENDING;
        Ea_Descriptor.JobState      = EA_STATE_READ_START;
        retVal = E_OK;
    }
    
    return retVal;
}

/**************************************************************************
Function name       : Std_ReturnType Ea_Write(uint16 BlockNumber, 
                                             const uint8* DataBufferPtr);
Description         : Service to initiate a write job.
Parameters (in)     : BlockNumber   - Number of logical block, also denoting 
                                      start address of that block in EEPROM.
                      DataBufferPtr - Pointer to data buffer
Parameters (out)    : DataBufferPtr - Pointer to data buffer
Return value        : E_OK: The requested job has been accepted by the module. 
                      E_NOT_OK: The requested job has not been accepted by the EA module. 
Design Information  :
**************************************************************************/
Std_ReturnType Ea_Write(uint16 BlockNumber, uint8* DataBufferPtr)
{
    Std_ReturnType retVal;
    retVal = E_NOT_OK ;
    if (Ea_Descriptor.JobActiveId == EA_JOB_IDLE)
    {
        MemLib_MemSet(&Ea_Descriptor, 0, sizeof(Ea_Descriptor_Type));
        Ea_Descriptor.BlockNumber   = BlockNumber;
        Ea_Descriptor.ClientAddress = DataBufferPtr;
        Ea_Descriptor.JobActiveId   = EA_JOB_WRITE;
        Ea_Descriptor.JobResult     = MEMIF_JOB_PENDING;
        Ea_Descriptor.JobState      = EA_STATE_WRITE_HEADER1;
        retVal = E_OK;
    }
    
    return retVal;
}
/**************************************************************************
Function name       : void Ea_Cancel(void)
Description         : service to Cancels the ongoing asynchronous operation.
Parameters (in)     : None
Parameters (out)    : None
Return value        : None 
Design Information  :
**************************************************************************/
void Ea_Cancel(void)
{
}
/**************************************************************************
Function name       : MemIf_StatusType Ea_GetStatus(void)
Description         : Service to return the Status.
Parameters (in)     : None
Parameters (out)    : None
Return value        : MemIf_StatusType   
                      MEMIF_UNINIT: The EA module has not been initialized (yet). 
                      MEMIF_IDLE: The EA module is currently idle. 
                      MEMIF_BUSY: The EA module is currently busy. 
                      MEMIF_BUSY_INTERNAL: The EA module is currently busy with 
                                           internal management operations.
Design Information  :                                                              
**************************************************************************/
MemIf_StatusType Ea_GetStatus(void)
{
    MemIf_StatusType retVal;
    retVal = MEMIF_BUSY;
    if (Ea_Descriptor.JobActiveId == EA_JOB_IDLE)
    {
        /* Ea Module is idle */
        retVal = MEMIF_IDLE;
    }
    return retVal;
}

/**************************************************************************
Function name       : MemIf_JobResultType Ea_GetJobResult(void)
Description         : Service to return the JobResult.
Parameters (in)     : None
Parameters (out)    : None
Return value        : MemIf_JobResultType - 
                      MEMIF_JOB_OK: The last job has been finished successfully. 
                      MEMIF_JOB_PENDING: The last job is waiting for execution or 
                                         currently being executed. 
                      MEMIF_JOB_CANCELED: The last job has been cancelled. 
                      MEMIF_JOB_FAILED: The last job was not finished successfully (it failed). 
                      MEMIF_BLOCK_INCONSISTENT: The requested block is inconsistent, 
                                                it may contain corrupted data. 
                      MEMIF_BLOCK_INVALID: The requested block has been invalidated, 
                                            the requested operation can not be performed
Design Information  : 
**************************************************************************/
MemIf_JobResultType Ea_GetJobResult(void)
{
  return (Ea_Descriptor.JobResult);
}

/**************************************************************************
Function name       : Std_ReturnType Ea_InvalidateBlock( uint16 BlockNumber)
Description         : Invalidates the block BlockNumber.
Parameters (in)     : BlockNumber - Number of logical block, also denoting 
                                    start address of that block in EEPROM.
Parameters (out)    : None
Return value        : E_OK - The requested job has been accepted by the module. 
                      E_NOT_OK - only if DET is enabled: The requested job 
                                 has not been accepted by the EA module.
Design Information  : 
**************************************************************************/
Std_ReturnType Ea_InvalidateBlock( uint16 BlockNumber)
{
    Std_ReturnType retVal;
    retVal = E_NOT_OK ;
    if (Ea_Descriptor.JobActiveId == EA_JOB_IDLE)
    {
        MemLib_MemSet(&Ea_Descriptor, 0, sizeof(Ea_Descriptor_Type));
        Ea_Descriptor.BlockNumber   = BlockNumber;
        Ea_Descriptor.BlockInvalid  = TRUE;
        Ea_Descriptor.JobActiveId   = EA_JOB_WRITE;
        Ea_Descriptor.JobResult     = MEMIF_JOB_PENDING;
        Ea_Descriptor.JobState      = EA_STATE_WRITE_HEADER1;
        
        retVal = E_OK;
    }
    
    return retVal;
}

/**************************************************************************
Function name       : void Ea_GetVersionInfo(Std_VersionInfoType* VersionInfoPtr)
Description         : Service to return the version information of the Ea module.
Parameters (in)     : None
Parameters (out)    : VersionInfoPtr - Pointer to standard version information structure.
Return value        : None
Design Information  : 
**************************************************************************/
void Ea_GetVersionInfo(Std_VersionInfoType* VersionInfoPtr)
{
}

/**************************************************************************
Function name       : Std_ReturnType Ea_EraseImmediateBlock(uint16 BlockNumber)
Description         : Service to Erases the block BlockNumber..
Parameters (in)     : BlockNumber - 
                      Number of logical block, also denoting start address of that block in EEPROM.
Parameters (out)    : None
Return value        : E_OK: The requested job has been accepted by the module. 
                      E_NOT_OK - only if DET is enabled: The requested job 
                                 has not been accepted by the EA module.
Design Information  : 
**************************************************************************/
Std_ReturnType Ea_EraseImmediateBlock(uint16 BlockNumber)
{
  return E_NOT_OK;
}

/**************************************************************************
Function name       : void Ea_JobEndNotification(void)
Description         : Service to report to this module the successful end of 
                      an asynchronous operation
Parameters (in)     : None
Parameters (out)    : None
Return value        : None
Design Information  : 
**************************************************************************/
void Ea_JobEndNotification(void)
{
    Ea_Descriptor.CbkServiced = TRUE;
    Ea_Descriptor.Eep_JobResult = MEMIF_JOB_OK;
}

/**************************************************************************
Function name       : void void Ea_JobErrorNotification(void)
Description         : Service to report to this module the failure of an 
                      asynchronous operation.
Parameters (in)     : None
Parameters (out)    : None
Return value        : None
Design Information  : 
**************************************************************************/
void Ea_JobErrorNotification(void)
{
    Ea_Descriptor.CbkServiced = TRUE;
    Ea_Descriptor.Eep_JobResult = Ea_Eep_GetJobResult();
}

/**************************************************************************
Function name       : void Ea_MainFunction(void)
Description         : Service to handle the requested jobs and the internal 
                      management operations
Parameters (in)     : None
Parameters (out)    : None
Return value        : None
Design Information  : 
**************************************************************************/
void Ea_MainFunction(void)
{
    if (Ea_Descriptor.JobActiveId != EA_JOB_IDLE)
    {
        do
        {
        Ea_ProcessJob();
        }while(FALSE != Ea_Descriptor.ProcessState);
    }
}


/**************************************************************************
Function name       : void Ea_ProcessJob(void)
Description         : Service to handle the requested jobs and the internal 
                      management operations
Parameters (in)     : None
Parameters (out)    : None
Return value        : None
Design Information  : 
**************************************************************************/
static void Ea_ProcessJob(void)
{
    switch(Ea_Descriptor.JobActiveId)
    {
        case EA_JOB_READ:
            Ea_ProcessJob_Read();
            break;
        case EA_JOB_WRITE:
            Ea_ProcessJob_Write();
            break;
        case EA_JOB_ERASE:
            Ea_ProcessJob_Erase();
            break;
        default:
            break;
    }
}

/**************************************************************************
Function name       : void Ea_ProcessJob_Read(void)
Description         : Service to handle the read request job 
Parameters (in)     : None
Parameters (out)    : None
Return value        : None
Design Information  : 
**************************************************************************/
static void Ea_ProcessJob_Read()
{
    switch(Ea_Descriptor.JobState)
    {
        case EA_STATE_READ_START:
            Ea_ReadStart();
            break;
        case EA_STATE_READ_FIND_INSTANCE:
            Ea_ReadFindInstance();
            break;
        case EA_STATE_READ_HEADER:
            Ea_ReadHeader();
            break;
        case EA_STATE_READ_HEADER_VALIDATE:
            Ea_ReadHeaderValidate();
            break;
        case EA_STATE_READ_PAYLOAD:
            Ea_ReadPayLoad();
            break;
        case EA_STATE_READ_PAYLOAD_CBK_WAIT:
            Ea_ReadPayLoadCbkWait();
            break;
        case EA_STATE_READ_END_NOTIFY:
            Ea_ReadEndNotify();
            break;
        case EA_STATE_READ_ERROR_NOTIFY:
            Ea_ReadErrorNotify();
            break;
        default:
            break;
    }

}

/**************************************************************************
Function name       : void Ea_ProcessJob_Write(void)
Description         : Service to handle the write request job 
Parameters (in)     : None
Parameters (out)    : None
Return value        : None
Design Information  : 
**************************************************************************/
static void Ea_ProcessJob_Write()
{
    switch(Ea_Descriptor.JobState)
    {
        case EA_STATE_WRITE_HEADER1:
            Ea_WriteHeader1();
            break;
        case EA_STATE_WRITE_HEADER1_CBK_WAIT:
            Ea_WriteHeader1CbkWait();
            break;
        case EA_STATE_VERIFY_HEADER1:
            Ea_VerifyHeader1();
            break;
        case EA_STATE_VERIFY_HEADER1_CBK_WAIT:
            Ea_VerifyHeader1CbkWait();
            break;
        case EA_STATE_WRITE_PAYLOAD:
            Ea_WritePayload();
            break;
        case EA_STATE_WRITE_PAYLOAD_CBK_WAIT:
            Ea_WritePayloadCbkWait();
            break;
        case EA_STATE_VERIFY_PAYLOAD:
            Ea_VerifyPayload();
            break;
        case EA_STATE_VERIFY_PAYLOAD_CBK_WAIT:
            Ea_VerifyPayloadCbkWait();
            break;
        case EA_STATE_WRITE_HEADER2:
            Ea_WriteHeader2();
            break;
        case EA_STATE_WRITE_HEADER2_CBK_WAIT:
            Ea_WriteHeader2CbkWait();
            break;
        case EA_STATE_VERIFY_HEADER2:
            Ea_VerifyHeader2();
            break;
        case EA_STATE_VERIFY_HEADER2_CBK_WAIT:
            Ea_VerifyHeader2CbkWait();
            break;
        case EA_STATE_WRITE_END_NOTIFY:
            Ea_WriteEndNotify();
            break;
        case EA_STATE_WRITE_ERROR_NOTIFY:
            Ea_WriteErrorNotify();
            break;
        default:
            break;
    }
}
/**************************************************************************
Function name       : void Ea_ProcessJob_Erase(void)
Description         : Service to handle the Erase request job 
Parameters (in)     : None
Parameters (out)    : None
Return value        : None
Design Information  : 
**************************************************************************/
static void Ea_ProcessJob_Erase()
{
    switch(Ea_Descriptor.JobState)
    {
        case EA_STATE_ERASE:
            break;
        case EA_STATE_ERASE_CBK_WAIT:
            break;
        default:
            break;
        
    }
}
/**************************************************************************
Function name       : uint16 Ea_GetBlockIndex(uint16 BlockNumber_u16)
Description         : Service to get the Real Block Number 
Parameters (in)     : BlockNumber_u16
Parameters (out)    : None
Return value        : RealBlockNumber_u16
Design Information  : 
**************************************************************************/
static uint16 Ea_GetBlockIndex(uint16 BlockNumber_u16)
{
     return ((BlockNumber_u16 >> (uint16)EA_DATASET_SELECTION_MASK ) - (uint16)1);
}

/**************************************************************************
Function name       : void Ea_ReadStart(void);
Description         : service start the internal read start state 
Parameters (in)     : None
Parameters (out)    : None
Return value        : None
Design Information  : 
**************************************************************************/
static void Ea_ReadStart()
{
    uint16 PhyEepAddr;
    
    Ea_Descriptor.BlockIndex = Ea_GetBlockIndex(Ea_Descriptor.BlockNumber);
    
    if(Ea_Config[Ea_Descriptor.BlockIndex].NoOfInstances > 1)
    {
        if(Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstance != EA_INVALID_INSTANCE_COUNT)
        {
            Ea_Descriptor.JobState = EA_STATE_READ_HEADER;
            Ea_Descriptor.ProcessState = TRUE;
        }
        else
        {
            PhyEepAddr = Ea_Config[Ea_Descriptor.BlockIndex].BlockBaseAddress;
            if ( E_OK == Ea_Eep_Read(PhyEepAddr, &Ea_InstanceSearch.CurrentHeaderValue[0], EA_BLOCK_OVERHEAD))
            {
               Ea_InstanceSearch.Counter = 0;
               Ea_InstanceSearch.FailureCount = 0;
               Ea_Descriptor.JobState  = EA_STATE_READ_FIND_INSTANCE;
               Ea_Descriptor.ProcessState = FALSE;
            }
            else
            {
                Ea_Descriptor.JobResult = MEMIF_JOB_FAILED;
                Ea_Descriptor.JobState  = EA_STATE_READ_ERROR_NOTIFY;
                Ea_Descriptor.ProcessState = TRUE;
            }
        }
    }
    else
    {
        Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstance = 0;
        Ea_Descriptor.JobState  = EA_STATE_READ_HEADER;
        Ea_Descriptor.ProcessState = TRUE;
    }
}
/**************************************************************************
Function name       : void Ea_ReadFindInstance(void);
Description         : Service to find the Instance Position
Parameters (in)     : None
Parameters (out)    : None
Return value        : None
Design Information  : 
**************************************************************************/
static void Ea_ReadFindInstance()
{
    uint16 PhyEepAddr;
    uint8 InvalidStatus;
    boolean CbkStatus;

    EA_ENTER_CRITICAL_SECTION();
    CbkStatus = Ea_Descriptor.CbkServiced;  
    EA_EXIT_CRITICAL_SECTION();    

    if(FALSE != CbkStatus)
    {
        CbkStatus = FALSE;
        EA_ENTER_CRITICAL_SECTION();
        Ea_Descriptor.CbkServiced = FALSE;  
        EA_EXIT_CRITICAL_SECTION();    

        
        if(Ea_Descriptor.Eep_JobResult == MEMIF_JOB_OK)
        { 
            if(EA_ERASED_EEPROM_VALUE != Ea_InstanceSearch.CurrentHeaderValue[0])
            {
                /* verify Header 1*/
                if(FALSE != Ea_ValidateManagementData(&Ea_InstanceSearch.CurrentHeaderValue[0]))
                {

                    if(Ea_InstanceSearch.Counter == 0)
                    {
                        /*skip the comparison for first instance and store the header value*/
                        Ea_InstanceSearch.ValidInstance = Ea_InstanceSearch.Counter;
                        Ea_InstanceSearch.PreviousHeaderValue = Ea_InstanceSearch.CurrentHeaderValue[0];
                    }
                    else if((Ea_InstanceSearch.Counter == 1) && (Ea_InstanceSearch.FailureCount == 1))
                    {
                        /*skip the comparison for second instance and store the header value if failure count = 1*/
                        Ea_InstanceSearch.ValidInstance = Ea_InstanceSearch.Counter;
                        Ea_InstanceSearch.PreviousHeaderValue = Ea_InstanceSearch.CurrentHeaderValue[0];
                        
                    }
                    else
                    {
                        /*Previous and current instance are not matching then previous instance having latest data and stop search*/
                        if((Ea_InstanceSearch.PreviousHeaderValue & 0x03) != (Ea_InstanceSearch.CurrentHeaderValue[0] & 0x03))
                        {
                            Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstance =  Ea_InstanceSearch.ValidInstance;
                            Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstanceHeader =  Ea_InstanceSearch.PreviousHeaderValue;
                            Ea_Descriptor.JobState = EA_STATE_READ_PAYLOAD;
                            Ea_Descriptor.ProcessState = TRUE;
                        }
                        else 
                        {
                            /*Previous and current instance are  matching then current instance having latest data continue search*/
                            Ea_InstanceSearch.ValidInstance = Ea_InstanceSearch.Counter;
                            Ea_InstanceSearch.PreviousHeaderValue = Ea_InstanceSearch.CurrentHeaderValue[0];
                            /*No. of instances reached to Max. configured Instances then last instance having latest data and stop search*/
                            if(Ea_InstanceSearch.Counter >= (Ea_Config[Ea_Descriptor.BlockIndex].NoOfInstances - 1))
                            {
                              Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstance =  Ea_InstanceSearch.ValidInstance;
                              Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstanceHeader =  Ea_InstanceSearch.CurrentHeaderValue[0];
                              Ea_Descriptor.JobState = EA_STATE_READ_PAYLOAD; 
                              Ea_Descriptor.ProcessState = TRUE;
                            }
                        }
                        
                    }
                }
                else 
                {
                    Ea_InstanceSearch.FailureCount ++;
                    /*Two instance got corrupted then stop search and notify error to upper layer*/
                    if(Ea_InstanceSearch.FailureCount > 1)
                    {
                        Ea_InstanceSearch.FailureCount = 0x00;
                        Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstance = 0xFF;
                        Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstanceHeader =  0xFF;
                        Ea_Descriptor.JobResult = MEMIF_JOB_FAILED;
                        Ea_Descriptor.JobState  = EA_STATE_READ_ERROR_NOTIFY;
                        Ea_Descriptor.ProcessState = TRUE;
                    }
                    else
                    {
                        /*Last instance got corrupted then previous instance is latest and stop the search */
                        if(Ea_InstanceSearch.Counter >= (Ea_Config[Ea_Descriptor.BlockIndex].NoOfInstances - 1))
                        {
                            Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstance =  Ea_InstanceSearch.ValidInstance;
                            Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstanceHeader =  Ea_InstanceSearch.PreviousHeaderValue;
                            Ea_Descriptor.JobState = EA_STATE_READ_PAYLOAD; 
                            Ea_Descriptor.ProcessState = TRUE;
                        }
                        else
                        {
                            if(Ea_InstanceSearch.Counter != 0 )
                            {
                                /*Store the Valid Instance */
                                Ea_InstanceSearch.ValidInstance = (Ea_InstanceSearch.Counter - 1) ;
                            }
                        }
                    }
                }
            }
            else
            {
                /*if instance with erased value and search counter is zero then notify error message to upper layer saying BLOCK INVALID*/
                if( Ea_InstanceSearch.Counter == 0)
                {
                    Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstance = 0xFF;
                    Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstanceHeader = 0xFF;
                    Ea_Descriptor.JobResult = MEMIF_BLOCK_INVALID;
                    Ea_Descriptor.JobState  = EA_STATE_READ_ERROR_NOTIFY;
                    Ea_Descriptor.ProcessState = TRUE;
                }
                else
                {   /*if instance with erased value and search counter not zero then  stop search*/
                    Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstance = Ea_InstanceSearch.ValidInstance;
                    Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstanceHeader = Ea_InstanceSearch.PreviousHeaderValue;
                    Ea_Descriptor.JobState = EA_STATE_READ_PAYLOAD;
                    Ea_Descriptor.ProcessState = TRUE; 
                }
            }
            if(Ea_Descriptor.JobState == EA_STATE_READ_FIND_INSTANCE)
            {
                /*read next instance */
                Ea_InstanceSearch.Counter ++;
                /* Header Physical Address = Block Base Addr +  ((block size + Overhead) * instance Number) */
                PhyEepAddr  = ( Ea_Config[Ea_Descriptor.BlockIndex].BlockBaseAddress + \
                                       ((Ea_Config[Ea_Descriptor.BlockIndex].BlockSize + EA_BLOCK_OVERHEAD)* Ea_InstanceSearch.Counter)) ;
                if ( E_OK != Ea_Eep_Read(PhyEepAddr, &Ea_InstanceSearch.CurrentHeaderValue[0], EA_BLOCK_OVERHEAD))
                {
                       Ea_Descriptor.JobResult = MEMIF_JOB_FAILED;
                       Ea_Descriptor.JobState  = EA_STATE_READ_ERROR_NOTIFY;
                       Ea_Descriptor.ProcessState = TRUE;
                       Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstance = 0xFF;
                       Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstanceHeader = 0xFF;
                }
            }
            else
            {
                InvalidStatus = (Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstanceHeader & EA_INVALIDATION_BIT);
                
                if((Ea_Descriptor.JobState == EA_STATE_READ_PAYLOAD) && (FALSE != InvalidStatus))
                {
                    Ea_Descriptor.JobResult = MEMIF_BLOCK_INVALID;
                    Ea_Descriptor.JobState  = EA_STATE_READ_ERROR_NOTIFY;
                    Ea_Descriptor.ProcessState = TRUE;
                }
            }
        }
        else
        {
            Ea_Descriptor.JobResult = MEMIF_JOB_FAILED;
            Ea_Descriptor.JobState  = EA_STATE_READ_ERROR_NOTIFY;
            Ea_Descriptor.ProcessState = TRUE;
            Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstance = 0xFF;
            Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstanceHeader = 0xFF;
        }    
    }
    else
    {
        /* do nothing */
    }
}
/**************************************************************************
Function name       : void Ea_ReadHeader(void)
Description         : Service to read Header
Parameters (in)     : None
Parameters (out)    : None
Return value        : None
Design Information  : 
**************************************************************************/
static void Ea_ReadHeader()
{
    uint16 PhyEepAddr;
    /* Header Physical Address = Block Base Addr +  ((block size + Overhead) * instance Number) */
    PhyEepAddr = ( Ea_Config[Ea_Descriptor.BlockIndex].BlockBaseAddress + \
                         (( Ea_Config[Ea_Descriptor.BlockIndex].BlockSize + EA_BLOCK_OVERHEAD)* \
                                Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstance)) ;

    if ( E_OK == Ea_Eep_Read(PhyEepAddr, &Ea_Descriptor.ManagementData[0], EA_BLOCK_OVERHEAD))
    {
       Ea_Descriptor.JobState  = EA_STATE_READ_HEADER_VALIDATE;
       Ea_Descriptor.ProcessState = FALSE;
    }
    else
    {
        Ea_Descriptor.JobResult = MEMIF_JOB_FAILED;
        Ea_Descriptor.JobState  = EA_STATE_READ_ERROR_NOTIFY;
        Ea_Descriptor.ProcessState = TRUE;
    }

}

/**************************************************************************
Function name       : void Ea_ReadHeaderValidate(void)
Description         : Service to read wait for call back and validate Header
Parameters (in)     : None
Parameters (out)    : None
Return value        : None
Design Information  : 
**************************************************************************/
static void Ea_ReadHeaderValidate()
{
    boolean CbkStatus;
    EA_ENTER_CRITICAL_SECTION();
    CbkStatus = Ea_Descriptor.CbkServiced;  
    EA_EXIT_CRITICAL_SECTION();    

    if(FALSE != CbkStatus)
    {
        CbkStatus = FALSE;
        EA_ENTER_CRITICAL_SECTION();
        Ea_Descriptor.CbkServiced = FALSE;  
        EA_EXIT_CRITICAL_SECTION();    
        
        if(Ea_Descriptor.Eep_JobResult == MEMIF_JOB_OK)
        {
            /* Validate the Header Data */
            if(FALSE != Ea_ValidateManagementData(&Ea_Descriptor.ManagementData[0]))
            {
                /*Check for the Invalid Block */
                if(FALSE == (Ea_Descriptor.ManagementData[0] & EA_INVALIDATION_BIT ) )
                {
                    /* Valid Block */
                    Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstanceHeader = Ea_Descriptor.ManagementData[0];
                    Ea_Descriptor.JobState  = EA_STATE_READ_PAYLOAD;
                    Ea_Descriptor.ProcessState = TRUE;
                }
                else
                {
                    /* Invalid Block */
                    Ea_Descriptor.JobResult = MEMIF_BLOCK_INVALID;
                    Ea_Descriptor.JobState  = EA_STATE_READ_ERROR_NOTIFY;
                    Ea_Descriptor.ProcessState = TRUE;
                }
            }
            else
            {
                Ea_Descriptor.JobResult = MEMIF_BLOCK_INCONSISTENT;
                Ea_Descriptor.JobState  = EA_STATE_READ_ERROR_NOTIFY;
                Ea_Descriptor.ProcessState = TRUE;
            } 
        }
        else
        {
            Ea_Descriptor.JobResult = Ea_Descriptor.Eep_JobResult;
            Ea_Descriptor.JobState  = EA_STATE_READ_ERROR_NOTIFY;
            Ea_Descriptor.ProcessState = TRUE;
        }
    }
}

/**************************************************************************
Function name       : void Ea_ReadPayLoad(void)
Description         : Service to read data
Parameters (in)     : None
Parameters (out)    : None
Return value        : None
Design Information  : 
**************************************************************************/
static void Ea_ReadPayLoad()
{
    uint16 PhyEepAddr;
    /* Pay Load Physical Address = Block Base Addr +  ((block size + Overhead) * instance Number) + OverHead + Offset*/
    PhyEepAddr = ( Ea_Config[Ea_Descriptor.BlockIndex].BlockBaseAddress + \
                         (( Ea_Config[Ea_Descriptor.BlockIndex].BlockSize + EA_BLOCK_OVERHEAD)* \
                            Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstance) + \
                            EA_BLOCK_OVERHEAD + \
                            Ea_Descriptor.Offset);
    
    if ( E_OK == Ea_Eep_Read(PhyEepAddr, Ea_Descriptor.ClientAddress, Ea_Descriptor.Length))
    {
       Ea_Descriptor.JobState  = EA_STATE_READ_PAYLOAD_CBK_WAIT;
       Ea_Descriptor.ProcessState = FALSE;
       
    }
    else
    {
        Ea_Descriptor.JobResult = MEMIF_JOB_FAILED;
        Ea_Descriptor.JobState  = EA_STATE_READ_ERROR_NOTIFY;
        Ea_Descriptor.ProcessState = TRUE;
    }
    
}


/**************************************************************************
Function name       : void Ea_ReadPayLoadCbkWait(void)
Description         : Service to wait for read data call back
Parameters (in)     : None
Parameters (out)    : None
Return value        : None
Design Information  : 
**************************************************************************/
static void Ea_ReadPayLoadCbkWait()
{
    boolean CbkStatus;
    EA_ENTER_CRITICAL_SECTION();
    CbkStatus = Ea_Descriptor.CbkServiced;  
    EA_EXIT_CRITICAL_SECTION();    
    
    if(FALSE != CbkStatus)
    {
        CbkStatus = FALSE;
        EA_ENTER_CRITICAL_SECTION();
        Ea_Descriptor.CbkServiced = FALSE;  
        EA_EXIT_CRITICAL_SECTION();    

        Ea_Descriptor.JobResult = Ea_Descriptor.Eep_JobResult;
        Ea_Descriptor.JobState  = EA_STATE_READ_ERROR_NOTIFY;
        Ea_Descriptor.ProcessState = TRUE;
        if(Ea_Descriptor.Eep_JobResult == MEMIF_JOB_OK)
        {
            Ea_Descriptor.JobState  = EA_STATE_READ_END_NOTIFY;
            Ea_Descriptor.ProcessState = TRUE;
        }
    }

}

/**************************************************************************
Function name       : void Ea_ReadEndNotify(void)
Description         : Service to send read end notification to Upper Layer
Parameters (in)     : None
Parameters (out)    : None
Return value        : None
Design Information  : 
**************************************************************************/
static void Ea_ReadEndNotify()
{
    Ea_Descriptor.JobActiveId = EA_JOB_IDLE;
    Ea_Descriptor.JobState = EA_STATE_IDLE;
    Ea_Descriptor.ProcessState = FALSE;
    Ea_Descriptor.JobResult = MEMIF_JOB_OK;
    Ea_CbkJobEndNotification();
}


/**************************************************************************
Function name       : void Ea_ReadErrorNotify(void)
Description         : Service to send read error notification to Upper Layer
Parameters (in)     : None
Parameters (out)    : None
Return value        : None
Design Information  : 
**************************************************************************/
static void Ea_ReadErrorNotify()
{
    Ea_Descriptor.JobActiveId = EA_JOB_IDLE;
    Ea_Descriptor.JobState = EA_STATE_IDLE;
    Ea_Descriptor.ProcessState = FALSE;
    Ea_CbkJobErrorNotification();
}
/**************************************************************************
Function name       : uint8 Ea_ValidateManagementData(uint8* )
Description         : Service to validate Header  bytes
Parameters (in)     : HeaderValue
Parameters (out)    : None
Return value        : TRUE/FALSE
Design Information  : 
**************************************************************************/
static uint8 Ea_ValidateManagementData(uint8* p_HeaderValue_u8)
{
    uint8 retVal;
    uint8 LowerNibble;
    uint8 UpperBibble;
    
    retVal = FALSE;
    LowerNibble = (p_HeaderValue_u8[0] & 0x0F);

    UpperBibble = (~(p_HeaderValue_u8[0] >> 4))  & 0x0F; 

    if((LowerNibble == UpperBibble) && (p_HeaderValue_u8[0] == p_HeaderValue_u8[1]))
    {
        retVal = TRUE;
    }
    return  retVal;
}
/**************************************************************************
Function name       : static void Ea_WriteHeader1(void)
Description         : Service to write Header
Parameters (in)     : None
Parameters (out)    : None
Return value        : None
Design Information  : 
**************************************************************************/
static void Ea_WriteHeader1()
{
    uint16 PhyEepAddr;
    uint8 LowerNibble;
    uint8 UpperNibble;
    
    Ea_Descriptor.BlockIndex = Ea_GetBlockIndex(Ea_Descriptor.BlockNumber);
    if(Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstanceHeader == EA_ERASED_EEPROM_VALUE)
    {
       Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstanceHeader = 0xF0;
    }
    else 
    {
        Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstance++;
        if(Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstance >= Ea_Config[Ea_Descriptor.BlockIndex].NoOfInstances)
        {
            LowerNibble = (Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstanceHeader & 0x03);
            LowerNibble = ((LowerNibble + 1) % 4);
            UpperNibble = ((~LowerNibble) << 4) & 0xF0;
            Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstanceHeader = (UpperNibble | LowerNibble);
            Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstance = 0;
        }
    }
    
    if(FALSE != Ea_Descriptor.BlockInvalid)
    {
        /* Set the Invalid flag */
        Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstanceHeader |= EA_INVALIDATION_BIT;
        Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstanceHeader &= (~(EA_INVALIDATION_BIT << 4));
    }
    else
    {
        /* Clear the Invalid flag */
        Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstanceHeader &= (~EA_INVALIDATION_BIT);
        Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstanceHeader |= (EA_INVALIDATION_BIT << 4);
    }
        
    PhyEepAddr  = ( Ea_Config[Ea_Descriptor.BlockIndex].BlockBaseAddress + \
                           ((Ea_Config[Ea_Descriptor.BlockIndex].BlockSize + EA_BLOCK_OVERHEAD)* \
                             Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstance)) ;
    

    if (E_OK == Ea_Eep_Write(PhyEepAddr, &Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstanceHeader, EA_HEADER1_SIZE))
    {
       Ea_Descriptor.JobState  = EA_STATE_WRITE_HEADER1_CBK_WAIT;
       Ea_Descriptor.ProcessState = FALSE;
    }
    else
    {
        Ea_Descriptor.JobResult = MEMIF_JOB_FAILED;
        Ea_Descriptor.JobState  = EA_STATE_WRITE_ERROR_NOTIFY;
        Ea_Descriptor.ProcessState = TRUE;
    }
}
/**************************************************************************
Function name       : static void Ea_WriteHeader1CbkWait(void)
Description         : Service to write Header call back wait
Parameters (in)     : None
Parameters (out)    : None
Return value        : None
Design Information  : 
**************************************************************************/
static void Ea_WriteHeader1CbkWait()
{
    boolean CbkStatus;
    EA_ENTER_CRITICAL_SECTION();
    CbkStatus = Ea_Descriptor.CbkServiced;  
    EA_EXIT_CRITICAL_SECTION();    
    
    if(FALSE != CbkStatus)
    {
        CbkStatus = FALSE;
        EA_ENTER_CRITICAL_SECTION();
        Ea_Descriptor.CbkServiced = FALSE;  
        EA_EXIT_CRITICAL_SECTION();    
        
        if(Ea_Descriptor.Eep_JobResult == MEMIF_JOB_OK)
        {
             if((Ea_Config[Ea_Descriptor.BlockIndex].BlockFlags & EA_VERIFICATION_ENABLED) == EA_VERIFICATION_ENABLED)
             {
                 Ea_Descriptor.JobState  = EA_STATE_VERIFY_HEADER1;
                 Ea_Descriptor.ProcessState = TRUE;
             }
             else
             {
                 Ea_Descriptor.JobState  = EA_STATE_WRITE_PAYLOAD;
                 Ea_Descriptor.ProcessState = TRUE;
             }
        }
        else
        {
            Ea_Descriptor.JobResult = Ea_Descriptor.Eep_JobResult;
            Ea_Descriptor.JobState  = EA_STATE_WRITE_ERROR_NOTIFY;
            Ea_Descriptor.ProcessState = TRUE;
        }
    }

}

/**************************************************************************
Function name       : static void Ea_VerifyHeader1(void)
Description         : Service to verify header
Parameters (in)     : None
Parameters (out)    : None
Return value        : None
Design Information  : 
**************************************************************************/
static void Ea_VerifyHeader1()
{
    uint16 PhyEepAddr;
    
    
    PhyEepAddr  = ( Ea_Config[Ea_Descriptor.BlockIndex].BlockBaseAddress + \
                            ((Ea_Config[Ea_Descriptor.BlockIndex].BlockSize + EA_BLOCK_OVERHEAD)* \
                               Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstance)) ;

    if(E_OK == Ea_Eep_Compare(PhyEepAddr, &Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstanceHeader, EA_HEADER1_SIZE))
    {
       Ea_Descriptor.JobState  = EA_STATE_VERIFY_HEADER1_CBK_WAIT;
       Ea_Descriptor.ProcessState = FALSE;
    }
    else
    {
        Ea_Descriptor.JobResult = MEMIF_JOB_FAILED;
        Ea_Descriptor.JobState  = EA_STATE_WRITE_ERROR_NOTIFY;
        Ea_Descriptor.ProcessState = TRUE;
    }
    
}

/**************************************************************************
Function name       : static void Ea_VerifyHeader1CbkWait(void)
Description         : Service to wait for verify header call back
Parameters (in)     : None
Parameters (out)    : None
Return value        : None
Design Information  : 
**************************************************************************/
static void Ea_VerifyHeader1CbkWait()
{
    boolean CbkStatus;
    EA_ENTER_CRITICAL_SECTION();
    CbkStatus = Ea_Descriptor.CbkServiced;  
    EA_EXIT_CRITICAL_SECTION();    
    
    if(FALSE != CbkStatus)
    {
        CbkStatus = FALSE;
        EA_ENTER_CRITICAL_SECTION();
        Ea_Descriptor.CbkServiced = FALSE;  
        EA_EXIT_CRITICAL_SECTION();    
        
        if(Ea_Descriptor.Eep_JobResult == MEMIF_JOB_OK)
        {
             Ea_Descriptor.JobState  = EA_STATE_WRITE_PAYLOAD;
             Ea_Descriptor.ProcessState = TRUE;
        }
        else
        {
            Ea_Descriptor.JobResult = Ea_Descriptor.Eep_JobResult;
            Ea_Descriptor.JobState  = EA_STATE_WRITE_ERROR_NOTIFY;
            Ea_Descriptor.ProcessState = TRUE;
        }
    }

}

/**************************************************************************
Function name       : static void Ea_WritePayload(void)
Description         : Service to write data in EEPROM
Parameters (in)     : None
Parameters (out)    : None
Return value        : None
Design Information  : 
**************************************************************************/
static void Ea_WritePayload()
{
    uint16 PhyEepAddr;
    
    /* Pay Load Physical Address = Block Base Addr +  ((block size + Overhead) * instance Number) + OverHead */
    PhyEepAddr = ( Ea_Config[Ea_Descriptor.BlockIndex].BlockBaseAddress + \
                          ((Ea_Config[Ea_Descriptor.BlockIndex].BlockSize + EA_BLOCK_OVERHEAD)* Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstance) + \
                          EA_BLOCK_OVERHEAD) ;
    if(FALSE == Ea_Descriptor.BlockInvalid)
    {
        if ( E_OK == Ea_Eep_Write(PhyEepAddr, Ea_Descriptor.ClientAddress, Ea_Config[Ea_Descriptor.BlockIndex].BlockSize))
        {
           Ea_Descriptor.JobState  = EA_STATE_WRITE_PAYLOAD_CBK_WAIT;
           Ea_Descriptor.ProcessState = FALSE;
        }
        else
        {
            Ea_Descriptor.JobResult = MEMIF_JOB_FAILED;
            Ea_Descriptor.JobState  = EA_STATE_WRITE_ERROR_NOTIFY;
            Ea_Descriptor.ProcessState = TRUE;
        }
    }
    else
    {
        if ( E_OK == Ea_Eep_Erase(PhyEepAddr, Ea_Config[Ea_Descriptor.BlockIndex].BlockSize))
        {
           Ea_Descriptor.JobState  = EA_STATE_WRITE_PAYLOAD_CBK_WAIT;
           Ea_Descriptor.ProcessState = FALSE;
        }
        else
        {
            Ea_Descriptor.JobResult = MEMIF_JOB_FAILED;
            Ea_Descriptor.JobState  = EA_STATE_WRITE_ERROR_NOTIFY;
            Ea_Descriptor.ProcessState = TRUE;
        }
        
    }
    
}
/**************************************************************************
Function name       : static void Ea_WritePayloadCbkWait(void)
Description         : Service to write data call back wait
Parameters (in)     : None
Parameters (out)    : None
Return value        : None
Design Information  : 
**************************************************************************/
static void Ea_WritePayloadCbkWait()
{
    boolean CbkStatus;
    EA_ENTER_CRITICAL_SECTION();
    CbkStatus = Ea_Descriptor.CbkServiced;  
    EA_EXIT_CRITICAL_SECTION();    
    
    if(FALSE != CbkStatus)
    {
        CbkStatus = FALSE;
        EA_ENTER_CRITICAL_SECTION();
        Ea_Descriptor.CbkServiced = FALSE;  
        EA_EXIT_CRITICAL_SECTION();    
        
        if(Ea_Descriptor.Eep_JobResult == MEMIF_JOB_OK)
        {
             if((Ea_Config[Ea_Descriptor.BlockIndex].BlockFlags & EA_VERIFICATION_ENABLED) == EA_VERIFICATION_ENABLED)
             {
                 Ea_Descriptor.JobState  = EA_STATE_VERIFY_PAYLOAD;
                 Ea_Descriptor.ProcessState = TRUE;
             }
             else
             {
                 Ea_Descriptor.JobState  = EA_STATE_WRITE_HEADER2;
                 Ea_Descriptor.ProcessState = TRUE;
             }
             
        }
        else
        {
            Ea_Descriptor.JobResult = Ea_Descriptor.Eep_JobResult;
            Ea_Descriptor.JobState  = EA_STATE_WRITE_ERROR_NOTIFY;
            Ea_Descriptor.ProcessState = TRUE;
        }
    }
    
}

/**************************************************************************
Function name       : static void Ea_VerifyPayload(void)
Description         : Service to verify payload
Parameters (in)     : None
Parameters (out)    : None
Return value        : None
Design Information  : 
**************************************************************************/
static void Ea_VerifyPayload()
{
    uint16 PhyEepAddr;
    
    /* Pay Load Physical Address = Block Base Addr +  ((block size + Overhead) * instance Number) + OverHead */
    
    PhyEepAddr      = ( Ea_Config[Ea_Descriptor.BlockIndex].BlockBaseAddress + \
                               ((Ea_Config[Ea_Descriptor.BlockIndex].BlockSize + EA_BLOCK_OVERHEAD)* \
                                  Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstance) + \
                               EA_BLOCK_OVERHEAD) ;

    if ( E_OK == Ea_Eep_Compare(PhyEepAddr, Ea_Descriptor.ClientAddress, Ea_Config[Ea_Descriptor.BlockIndex].BlockSize))
    {
       Ea_Descriptor.JobState  = EA_STATE_VERIFY_PAYLOAD_CBK_WAIT;
       Ea_Descriptor.ProcessState = FALSE;
    }
    else
    {
        Ea_Descriptor.JobResult = MEMIF_JOB_FAILED;
        Ea_Descriptor.JobState  = EA_STATE_WRITE_ERROR_NOTIFY;
        Ea_Descriptor.ProcessState = TRUE;
    }
    
}

/**************************************************************************
Function name       : static void Ea_VerifyPayloadCbkWait(void)
Description         : Service to verify header
Parameters (in)     : None
Parameters (out)    : None
Return value        : None
Design Information  : 
**************************************************************************/
static void Ea_VerifyPayloadCbkWait()
{
    boolean CbkStatus;
    EA_ENTER_CRITICAL_SECTION();
    CbkStatus = Ea_Descriptor.CbkServiced;  
    EA_EXIT_CRITICAL_SECTION();    
    
    if(FALSE != CbkStatus)
    {
        CbkStatus = FALSE;
        EA_ENTER_CRITICAL_SECTION();
        Ea_Descriptor.CbkServiced = FALSE;
        EA_EXIT_CRITICAL_SECTION();    
        
        
        if(Ea_Descriptor.Eep_JobResult == MEMIF_JOB_OK)
        {
             Ea_Descriptor.JobState  = EA_STATE_WRITE_HEADER2;
             Ea_Descriptor.ProcessState = TRUE;
        }
        else
        {
            Ea_Descriptor.JobResult = Ea_Descriptor.Eep_JobResult;
            Ea_Descriptor.JobState  = EA_STATE_WRITE_ERROR_NOTIFY;
            Ea_Descriptor.ProcessState = TRUE;
        }
    }

}


/**************************************************************************
Function name       : static void Ea_WriteHeader2(void)
Description         : Service to write footer
Parameters (in)     : None
Parameters (out)    : None
Return value        : None
Design Information  : 
**************************************************************************/
static void Ea_WriteHeader2()
{
    uint16 PhyEepAddr;
     
    /* Header 2 Physical Address = Block Base Addr +  ((block size + Overhead) * instance Number) + Header1 Size */
    
    PhyEepAddr = ( Ea_Config[Ea_Descriptor.BlockIndex].BlockBaseAddress + \
                          ((Ea_Config[Ea_Descriptor.BlockIndex].BlockSize + EA_BLOCK_OVERHEAD)* \
                            Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstance) + \
                           EA_HEADER1_SIZE );
    
    if ( E_OK == Ea_Eep_Write(PhyEepAddr, &Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstanceHeader, EA_HEADER2_SIZE))
    {
       Ea_Descriptor.JobState  = EA_STATE_WRITE_HEADER2_CBK_WAIT;
       Ea_Descriptor.ProcessState = FALSE;
    }
    else
    {
        Ea_Descriptor.JobResult = MEMIF_JOB_FAILED;
        Ea_Descriptor.JobState  = EA_STATE_WRITE_ERROR_NOTIFY;
        Ea_Descriptor.ProcessState = TRUE;
    }
}

/**************************************************************************
Function name       : static void Ea_WriteHeader2CbkWait(void)
Description         : Service to write footer
Parameters (in)     : None
Parameters (out)    : None
Return value        : None
Design Information  : 
**************************************************************************/
static void Ea_WriteHeader2CbkWait()
{
    boolean CbkStatus;
    EA_ENTER_CRITICAL_SECTION();
    CbkStatus = Ea_Descriptor.CbkServiced;  
    EA_EXIT_CRITICAL_SECTION();    
    
    if(FALSE != CbkStatus)
    {
        CbkStatus = FALSE;
        EA_ENTER_CRITICAL_SECTION();
        Ea_Descriptor.CbkServiced = FALSE;
        EA_EXIT_CRITICAL_SECTION();    
        
        if(Ea_Descriptor.Eep_JobResult == MEMIF_JOB_OK)
        {
             if((Ea_Config[Ea_Descriptor.BlockIndex].BlockFlags & EA_VERIFICATION_ENABLED) == EA_VERIFICATION_ENABLED)
             {
                 Ea_Descriptor.JobState  = EA_STATE_VERIFY_HEADER2;
                 Ea_Descriptor.ProcessState = TRUE;
             }
             else
             {
                 Ea_Descriptor.JobState  = EA_STATE_WRITE_END_NOTIFY;
                 Ea_Descriptor.ProcessState = TRUE;
             }
        }
        else
        {
            Ea_Descriptor.JobResult = Ea_Descriptor.Eep_JobResult;
            Ea_Descriptor.JobState  = EA_STATE_WRITE_ERROR_NOTIFY;
            Ea_Descriptor.ProcessState = TRUE;
        }
    }
}

/**************************************************************************
Function name       : static void Ea_VerifyHeader2(void)
Description         : Service to verify footer with EEPROM Data
Parameters (in)     : None
Parameters (out)    : None
Return value        : None
Design Information  : 
**************************************************************************/
static void Ea_VerifyHeader2(void)
{
    uint16 PhyEepAddr;
     
    
    /* Header 2 Physical Address = Block Base Addr +  ((block size + Overhead) * instance Number) + Header1 Size */
    
    PhyEepAddr = ( Ea_Config[Ea_Descriptor.BlockIndex].BlockBaseAddress + \
                          ((Ea_Config[Ea_Descriptor.BlockIndex].BlockSize + EA_BLOCK_OVERHEAD)* \
                            Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstance) + \
                            EA_HEADER1_SIZE) ;
                                
    if ( E_OK == Ea_Eep_Compare(PhyEepAddr, &Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstanceHeader, EA_HEADER2_SIZE))
    {
       Ea_Descriptor.JobState  = EA_STATE_VERIFY_HEADER2_CBK_WAIT;
       Ea_Descriptor.ProcessState = FALSE;
    }
    else
    {
        Ea_Descriptor.JobResult = MEMIF_JOB_FAILED;
        Ea_Descriptor.JobState  = EA_STATE_WRITE_ERROR_NOTIFY;
        Ea_Descriptor.ProcessState = TRUE;
    }
    
}

/**************************************************************************
Function name       : static void Ea_VerifyHeader2CbkWait(void)
Description         : Service to wait for verify footer call back wait
Parameters (in)     : None
Parameters (out)    : None
Return value        : None
Design Information  : 
**************************************************************************/
static void Ea_VerifyHeader2CbkWait(void)
{
    boolean CbkStatus;
    EA_ENTER_CRITICAL_SECTION();
    CbkStatus = Ea_Descriptor.CbkServiced;  
    EA_EXIT_CRITICAL_SECTION();    
    
    if(FALSE != CbkStatus)
    {
        CbkStatus = FALSE;
        EA_ENTER_CRITICAL_SECTION();
        Ea_Descriptor.CbkServiced = FALSE;
        EA_EXIT_CRITICAL_SECTION();    
        
        if(Ea_Descriptor.Eep_JobResult == MEMIF_JOB_OK)
        {
             Ea_Descriptor.JobState  = EA_STATE_WRITE_END_NOTIFY;
             Ea_Descriptor.ProcessState = TRUE;
        }
        else
        {
            Ea_Descriptor.JobResult = Ea_Descriptor.Eep_JobResult;
            Ea_Descriptor.JobState  = EA_STATE_WRITE_ERROR_NOTIFY;
            Ea_Descriptor.ProcessState = TRUE;
        }
    }
}

/**************************************************************************
Function name       : static void Ea_WriteEndNotify(void)
Description         : Service to provide end notification to upper layer
Parameters (in)     : None
Parameters (out)    : None
Return value        : None
Design Information  : 
**************************************************************************/
static void Ea_WriteEndNotify(void)
{

    Ea_Descriptor.JobResult = MEMIF_JOB_OK;
    Ea_Descriptor.JobState  = EA_STATE_IDLE;
    Ea_Descriptor.ProcessState = FALSE;
    Ea_Descriptor.JobActiveId = EA_JOB_IDLE;
    Ea_CbkJobEndNotification();
}

/**************************************************************************
Function name       : static void Ea_WriteErrorNotify(void)
Description         : Service to provide error notification to upper layer
Parameters (in)     : None
Parameters (out)    : None
Return value        : None
Design Information  : 
**************************************************************************/
static void Ea_WriteErrorNotify(void)
{
    uint8 LowerNibble;
    uint8 UpperNibble;
    Ea_Descriptor.JobActiveId = EA_JOB_IDLE;
    Ea_Descriptor.JobState  = EA_STATE_IDLE;
    Ea_Descriptor.ProcessState = FALSE;
    if(Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstance == 0)
    {
        LowerNibble = (Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstanceHeader & 0x03);
        LowerNibble = ((LowerNibble - 1) % 4);
        UpperNibble = ((~LowerNibble) << 4) & 0xF0;
        Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstanceHeader = (UpperNibble | LowerNibble);
   }
   Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstance--;
   Ea_CbkJobErrorNotification();
}



#endif /* EA_C */
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
/*Change Description: Data design And Framework implemented, Initial Version*/
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 22-01-2016                                            */
/*Version           :                                                       */
/*By                : kshaik1                                               */
/*Traceability      : 506324,506325                                         */
/*Change Description: Read, Write Implementation                            */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 04-02-2016                                            */
/*Version           :                                                       */
/*By                : kshaik1                                               */
/*Traceability      : 515730                                                */
/*Change Description: Ea and Eep Integration                               */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 10-02-2016                                            */
/*Version           :                                                       */
/*By                : kshaik1                                               */
/*Traceability      : 516513                                                */
/*Change Description: Updated Search Algorithm                              */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 22-02-2016                                            */
/*Version           :                                                       */
/*By                : kshaik1                                               */
/*Traceability      : 528464                                                */
/*Change Description: Fixing Coverity Warnings                              */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 25-02-2016                                            */
/*Version           :                                                       */
/*By                : kshaik1                                               */
/*Traceability      : 513221                                                */
/*Change Description: Updated for code review comments                      */
/*--------------------------------------------------------------------------*/


