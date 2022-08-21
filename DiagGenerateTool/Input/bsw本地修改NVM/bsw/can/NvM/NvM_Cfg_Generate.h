#ifndef __NVM_CFG_GENERATE_H__
#define __NVM_CFG_GENERATE_H__

#include "Std_Types.h"
#include "NvM_Types.h"
#include "NvM_Server.h"

#define NVM_NUM_OF_BLOCKS        ((uint8)11)

uint8 NvMConfigBlock_RamBlock_au8[8];

static const uint8 EStatus[32] = { 0 };


//Qiuhuaqing Modify
//BlockId
#define NvmBlockNumber_TestOdo                					    (2UL)
#define NvMConf___MultiBlockRequest                                 (0)
#define NvMConf_NvMBlockDescriptor_NvMConfigBlock                   (0)
#define DemCfg_NvMBlockDescriptor_OpCycle                           (2)
#define DemCfg_NvMBlockDescriptor_DemAdmin                          (3)
#define DemCfg_NvMBlockDescriptor_DemStatus                         (4)
#define NvMConf_NvMBlockDescriptor_VIN                              (5)
#define NvMConf_NvMBlockDescriptor_EcuConfig                        (6)
#define NvMConf_NvMBlockDescriptor_EIDCConfig                       (7)
#define DemCfg_NvMBlockDescriptor_DemPrimary_000                    (8)
#define DemCfg_NvMBlockDescriptor_DemPrimary_001                    (9)
#define DemCfg_NvMBlockDescriptor_DemPrimary_002                    (10)
#define DemCfg_NvMBlockDescriptor_DemPrimary_003                    (11)
#define DemCfg_NvMBlockDescriptor_DemPrimary_004                    (12)
#define DemCfg_NvMBlockDescriptor_DemPrimary_005                    (13)
#define DemCfg_NvMBlockDescriptor_DemPrimary_006                    (14)

//Ram Block
extern uint8 NvmRamData_TestOdo[8];
extern uint8 NvmRamData_VIN_17Byte[17];
extern uint8 NvmRamData_EcuConfig_200Byte[200];
extern uint8 NvmRamData_EIDCConfig_Byte[8];

//Rom Block
extern const uint8 NvmRomData_TestOdo[8];
extern const uint8 NvmRomData_VIN_17Byte[17];
extern const uint8 NvmRomData_EcuConfig_200Byte[200];
extern const uint8 NvmRomData_EIDCConfig_Byte[8];

//CallBack
extern uint8 Rte_Call_EIDCConfig_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult);

extern uint8 Rte_Call_TestOdo_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult);

extern uint8 Rte_Call_VIN_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult);

extern uint8 Rte_Call_EcuConfig_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult);

//DirtyFlags
/* index 0 and 1 not used */
extern S_NvM_DirtyFlag_Type Rte_DirtyFlags[NVM_NUM_OF_BLOCKS];

#ifndef NvmCfg_BlockConfig_Table
#define NvmCfg_BlockConfig_Table \
  {\
     NULL,        /*   void (*InitCallback) (void);          */ \
     NULL,        /*   void(*SingleBlockCallback)(void);     */ \
     NULL,        /*   uint8*    RamBlockDataAddress;        */ \
     NULL,        /*   uint8*    RomBlockDataAddress;        */ \
     0,           /*   uint16    NvBlockBaseNumber;          */ \
     0,           /*   uint16    NvBlockLength;              */ \
     0,           /*   uint16    NvRamBlockIdentifier;       */ \
     1,           /*   uint8     BlockJobPriority;           */ \
     0,           /*   uint8     MaxNumReadRetries;          */ \
     0,           /*   uint8     MaxNumWriteRetries;         */ \
     0,           /*   uint8     NvBlockNum;                 */ \
     0,           /*   uint8     NvRamDeviceId;              */ \
     0,           /*   uint8     RomBlockNum;                */ \
     CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */ \
     NVM_NATIVE_BLOCK, /*   NvM_BlockType BlockManagementType;    */ \
     0,           /*   boolean   BlockUseCrc;                */ \
     0,           /*   boolean   BlockUseSetRamBlockStatus;  */ \
     0,           /*   boolean BlockWriteProt;               */ \
     0,           /*   boolean   BswMBlockStatusInformation; */ \
     0,           /*   boolean   CalcRamBlockCrc;            */ \
     0,           /*   boolean   SelectBlockForReadAll;      */ \
     0,           /*   boolean   SelectBlockForWriteAll;     */ \
     0            /*  boolean   WriteBlockOnce;              */ \
  },\
  {\
     NULL,        /*   void (*InitCallback) (void);          */ \
     NULL,        /*   void(*SingleBlockCallback)(void);     */ \
     (uint8*)&NvMConfigBlock_RamBlock_au8,        /*   uint8*    RamBlockDataAddress;        */ \
     NULL,        /*   uint8*    RomBlockDataAddress;        */ \
     0,           /*   uint16    NvBlockBaseNumber;          */ \
     32,          /*   uint16    NvBlockLength;              */ \
     0,           /*   uint16    NvRamBlockIdentifier;       */ \
     1,           /*   uint8     BlockJobPriority;           */ \
     0,           /*   uint8     MaxNumReadRetries;          */ \
     0,           /*   uint8     MaxNumWriteRetries;         */ \
     0,           /*   uint8     NvBlockNum;                 */ \
     0,           /*   uint8     NvRamDeviceId;              */ \
     0,           /*   uint8     RomBlockNum;                */ \
     CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */ \
     NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */ \
     0,           /*   boolean   BlockUseCrc;                */ \
     0,           /*   boolean   BlockUseSetRamBlockStatus;  */ \
     0,           /*   boolean BlockWriteProt;               */ \
     0,           /*   boolean   BswMBlockStatusInformation; */ \
     0,           /*   boolean   CalcRamBlockCrc;            */ \
     0,           /*   boolean   SelectBlockForReadAll;      */ \
     0,           /*   boolean   SelectBlockForWriteAll;     */ \
     0            /*  boolean   WriteBlockOnce;              */ \
  },\
  {\
     NULL,        /*   void (*InitCallback) (void);          */ \
     Rte_Call_TestOdo_JobFinished,        /*   void(*SingleBlockCallback)(void);     */ \
     (uint8*)&NvmRamData_TestOdo,        /*   uint8*    RamBlockDataAddress;        */  \
     (uint8*)&NvmRomData_TestOdo,        /*   uint8*    RomBlockDataAddress;        */  \
     NvmBlockNumber_TestOdo,           /*   uint16    NvBlockBaseNumber;          */    \
     8,          /*   uint16    NvBlockLength;               */ \
     0,           /*   uint16    NvRamBlockIdentifier;       */ \
     1,           /*   uint8     BlockJobPriority;           */ \
     0,           /*   uint8     MaxNumReadRetries;          */ \
     0,           /*   uint8     MaxNumWriteRetries;         */ \
     0,           /*   uint8     NvBlockNum;                 */ \
     MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */ \
     0,           /*   uint8     RomBlockNum;                */ \
     CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */ \
     NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */ \
     0,           /*   boolean   BlockUseCrc;                */ \
     0,           /*   boolean   BlockUseSetRamBlockStatus;  */ \
     0,           /*   boolean BlockWriteProt;               */ \
     0,           /*   boolean   BswMBlockStatusInformation; */ \
     0,           /*   boolean   CalcRamBlockCrc;            */ \
     1,           /*   boolean   SelectBlockForReadAll;      */ \
     1,           /*   boolean   SelectBlockForWriteAll;     */ \
     0            /*  boolean   WriteBlockOnce;              */ \
  },\
  {\
     NULL,        /*   void (*InitCallback) (void);          */ \
     Dem_NvM_JobFinished,        /*   void(*SingleBlockCallback)(void);     */\
     (uint8*)&Dem_Cfg_OpCycle,        /*   uint8*    RamBlockDataAddress;        */\
     (uint8*)&EStatus,        /* Note: Since the ROM Block is not available, Temporarily it has been put as RAM block Needs to Explore*/\
     NvMConf_NvMBlockDescriptor_OpCycle, /*  uint16  NvBlockBaseNumber;  */\
     sizeof(Dem_Cfg_OpCycleType),          /*   uint16    NvBlockLength;              */\
     0,           /*   uint16    NvRamBlockIdentifier;       */ \
     0,           /*   uint8     BlockJobPriority;           */ \
     0,           /*   uint8     MaxNumReadRetries;          */ \
     0,           /*   uint8     MaxNumWriteRetries;         */ \
     0,           /*   uint8     NvBlockNum;                 */ \
     MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */ \
     0,           /*   uint8     RomBlockNum;                */ \
     CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */ \
     NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */ \
     0,           /*   boolean   BlockUseCrc;                */ \
     0,           /*   boolean   BlockUseSetRamBlockStatus;  */ \
     0,           /*   boolean BlockWriteProt;               */ \
     0,           /*   boolean   BswMBlockStatusInformation; */ \
     0,           /*   boolean   CalcRamBlockCrc;            */ \
     1,           /*   boolean   SelectBlockForReadAll;      */ \
     1,           /*   boolean   SelectBlockForWriteAll;     */ \
     0            /*  boolean   WriteBlockOnce;              */ \
  },\
  {\
     NULL,        /*   void (*InitCallback) (void);          */ \
     Dem_NvM_JobFinished,        /*   void(*SingleBlockCallback)(void);     */ \
     (uint8*)&Dem_Cfg_AdminData,        /*   uint8*    RamBlockDataAddress;        */ \
     (uint8*)&EStatus,        /* Note: Since the ROM Block is not available, Temporarily it has been put as RAM block Needs to Explore*/ \
     NvMConf_NvMBlockDescriptor_DemAdmin, /*  uint16  NvBlockBaseNumber;  */ \
     sizeof(Dem_Cfg_AdminDataType),          /*   uint16    NvBlockLength;              */ \
     0,           /*   uint16    NvRamBlockIdentifier;       */ \
     0,           /*   uint8     BlockJobPriority;           */ \
     0,           /*   uint8     MaxNumReadRetries;          */ \
     0,           /*   uint8     MaxNumWriteRetries;         */ \
     0,           /*   uint8     NvBlockNum;                 */ \
     MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */ \
     0,           /*   uint8     RomBlockNum;                */ \
     CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */ \
     NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */ \
     0,           /*   boolean   BlockUseCrc;                */ \
     0,           /*   boolean   BlockUseSetRamBlockStatus;  */ \
     0,           /*   boolean BlockWriteProt;               */ \
     0,           /*   boolean   BswMBlockStatusInformation; */ \
     0,           /*   boolean   CalcRamBlockCrc;            */ \
     1,           /*   boolean   SelectBlockForReadAll;      */ \
     1,           /*   boolean   SelectBlockForWriteAll;     */ \
     0            /*  boolean   WriteBlockOnce;              */ \
  },\
  {\
     NULL,        /*   void (*InitCallback) (void);          */ \
     Dem_NvM_JobFinished,        /*   void(*SingleBlockCallback)(void);     */ \
     (uint8*)&Dem_Cfg_StatusData,        /*   uint8*    RamBlockDataAddress;        */ \
     (uint8*)&EStatus,        /* Note: Since the ROM Block is not available, Temporarily it has been put as RAM block Needs to Explore*/ \
     NvMConf_NvMBlockDescriptor_DemStatus, /*  uint16  NvBlockBaseNumber;  */ \
     sizeof(Dem_Cfg_UdsStatusDataType),          /*   uint16    NvBlockLength;              */ \
     0,           /*   uint16    NvRamBlockIdentifier;       */ \
     0,           /*   uint8     BlockJobPriority;           */ \
     0,           /*   uint8     MaxNumReadRetries;          */ \
     0,           /*   uint8     MaxNumWriteRetries;         */ \
     0,           /*   uint8     NvBlockNum;                 */ \
     MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */ \
     0,           /*   uint8     RomBlockNum;                */ \
     CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */ \
     NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */ \
     0,           /*   boolean   BlockUseCrc;                */ \
     0,           /*   boolean   BlockUseSetRamBlockStatus;  */ \
     0,           /*   boolean BlockWriteProt;               */ \
     0,           /*   boolean   BswMBlockStatusInformation; */ \
     0,           /*   boolean   CalcRamBlockCrc;            */ \
     1,           /*   boolean   SelectBlockForReadAll;      */ \
     1,           /*   boolean   SelectBlockForWriteAll;     */ \
     0            /*  boolean   WriteBlockOnce;              */ \
  },\
  {\
     NULL,        /*   void (*InitCallback) (void);          */ \
     Dem_NvM_JobFinished,        /*   void(*SingleBlockCallback)(void);     */ \
     (uint8*) &Dem_PrimaryEntry_0, /*  uint8*  RamBlockDataAddress;  */ \
     (uint8*)&Dem_MemoryEntryInit,        /*   uint8*    RomBlockDataAddress;        */ \
     NvMConf_NvMBlockDescriptor_DemPrimary_000,           /*   uint16    NvBlockBaseNumber;          */ \
     sizeof(Dem_Cfg_PrimaryMemEntryType),          /*   uint16    NvBlockLength;              */ \
     0,           /*   uint16    NvRamBlockIdentifier;       */ \
     0,           /*   uint8     BlockJobPriority;           */ \
     0,           /*   uint8     MaxNumReadRetries;          */ \
     0,           /*   uint8     MaxNumWriteRetries;         */ \
     0,           /*   uint8     NvBlockNum;                 */ \
     MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */ \
     0,           /*   uint8     RomBlockNum;                */ \
     CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */ \
     NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */ \
     0,           /*   boolean   BlockUseCrc;                */ \
     0,           /*   boolean   BlockUseSetRamBlockStatus;  */ \
     0,           /*   boolean BlockWriteProt;               */ \
     0,           /*   boolean   BswMBlockStatusInformation; */ \
     0,           /*   boolean   CalcRamBlockCrc;            */ \
     1,           /*   boolean   SelectBlockForReadAll;      */ \
     1,           /*   boolean   SelectBlockForWriteAll;     */ \
     0            /*  boolean   WriteBlockOnce;              */ \
  },\
  {\
     NULL,        /*   void (*InitCallback) (void);          */ \
     Dem_NvM_JobFinished,        /*   void(*SingleBlockCallback)(void);     */ \
     (uint8*) &Dem_PrimaryEntry_1, /*  uint8*  RamBlockDataAddress;  */ \
     (uint8*)&Dem_MemoryEntryInit,        /*   uint8*    RomBlockDataAddress;        */ \
     NvMConf_NvMBlockDescriptor_DemPrimary_001,           /*   uint16    NvBlockBaseNumber;          */ \
     sizeof(Dem_Cfg_PrimaryMemEntryType),          /*   uint16    NvBlockLength;              */ \
     0,           /*   uint16    NvRamBlockIdentifier;       */ \
     0,           /*   uint8     BlockJobPriority;           */ \
     0,           /*   uint8     MaxNumReadRetries;          */ \
     0,           /*   uint8     MaxNumWriteRetries;         */ \
     0,           /*   uint8     NvBlockNum;                 */ \
     MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */ \
     0,           /*   uint8     RomBlockNum;                */ \
     CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */ \
     NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */ \
     0,           /*   boolean   BlockUseCrc;                */ \
     0,           /*   boolean   BlockUseSetRamBlockStatus;  */ \
     0,           /*   boolean BlockWriteProt;               */ \
     0,           /*   boolean   BswMBlockStatusInformation; */ \
     0,           /*   boolean   CalcRamBlockCrc;            */ \
     1,           /*   boolean   SelectBlockForReadAll;      */ \
     1,           /*   boolean   SelectBlockForWriteAll;     */ \
     0            /*   boolean   WriteBlockOnce;             */ \
  },\
  {\
     NULL,        /*   void (*InitCallback) (void);          */ \
     Rte_Call_VIN_JobFinished,        /*   void(*SingleBlockCallback)(void);     */ \
     (uint8*)&NvmRamData_VIN_17Byte, /*  uint8*  RamBlockDataAddress;  */ \
     (uint8*)&NvmRomData_VIN_17Byte,        /*   uint8*    RomBlockDataAddress;        */ \
     NvMConf_NvMBlockDescriptor_VIN,           /*   uint16    NvBlockBaseNumber;          */ \
     17,          /*   uint16    NvBlockLength;              */ \
     0,           /*   uint16    NvRamBlockIdentifier;       */ \
     0,           /*   uint8     BlockJobPriority;           */ \
     0,           /*   uint8     MaxNumReadRetries;          */ \
     0,           /*   uint8     MaxNumWriteRetries;         */ \
     0,           /*   uint8     NvBlockNum;                 */ \
     MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */ \
     0,           /*   uint8     RomBlockNum;                */ \
     CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */ \
     NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */ \
     0,           /*   boolean   BlockUseCrc;                */ \
     0,           /*   boolean   BlockUseSetRamBlockStatus;  */ \
     0,           /*   boolean BlockWriteProt;               */ \
     0,           /*   boolean   BswMBlockStatusInformation; */ \
     0,           /*   boolean   CalcRamBlockCrc;            */ \
     1,           /*   boolean   SelectBlockForReadAll;      */ \
     1,           /*   boolean   SelectBlockForWriteAll;     */ \
     0            /*  boolean   WriteBlockOnce;              */ \
  },\
  {\
     NULL,        /*   void (*InitCallback) (void);          */ \
     Rte_Call_EcuConfig_JobFinished,        /*   void(*SingleBlockCallback)(void);     */ \
     (uint8*)&NvmRamData_EcuConfig_200Byte, /*  uint8*  RamBlockDataAddress;  */ \
     (uint8*)&NvmRomData_EcuConfig_200Byte,        /*   uint8*    RomBlockDataAddress;        */ \
     NvMConf_NvMBlockDescriptor_EcuConfig,           /*   uint16    NvBlockBaseNumber;          */ \
     200,          /*   uint16    NvBlockLength;             */ \
     0,           /*   uint16    NvRamBlockIdentifier;       */ \
     0,           /*   uint8     BlockJobPriority;           */ \
     0,           /*   uint8     MaxNumReadRetries;          */ \
     0,           /*   uint8     MaxNumWriteRetries;         */ \
     0,           /*   uint8     NvBlockNum;                 */ \
     MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */ \
     0,           /*   uint8     RomBlockNum;                */ \
     CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */ \
     NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */ \
     0,           /*   boolean   BlockUseCrc;                */ \
     0,           /*   boolean   BlockUseSetRamBlockStatus;  */ \
     0,           /*   boolean BlockWriteProt;               */ \
     0,           /*   boolean   BswMBlockStatusInformation; */ \
     0,           /*   boolean   CalcRamBlockCrc;            */ \
     1,           /*   boolean   SelectBlockForReadAll;      */ \
     1,           /*   boolean   SelectBlockForWriteAll;     */ \
     0            /*   boolean   WriteBlockOnce;             */ \
  },\
  {\
     NULL,        /*   void (*InitCallback) (void);          */ \
     Rte_Call_EIDCConfig_JobFinished,        /*   void(*SingleBlockCallback)(void);     */ \
     (uint8*)&NvmRamData_EIDCConfig_Byte, /*  uint8*  RamBlockDataAddress;  */ \
     (uint8*)&NvmRomData_EIDCConfig_Byte,        /*   uint8*    RomBlockDataAddress;        */ \
     NvMConf_NvMBlockDescriptor_EIDC,           /*   uint16    NvBlockBaseNumber;           */ \
     8,          /*   uint16    NvBlockLength;               */ \
     0,           /*   uint16    NvRamBlockIdentifier;       */ \
     0,           /*   uint8     BlockJobPriority;           */ \
     0,           /*   uint8     MaxNumReadRetries;          */ \
     0,           /*   uint8     MaxNumWriteRetries;         */ \
     0,           /*   uint8     NvBlockNum;                 */ \
     MEMIF_FEE,   /*   uint8     NvRamDeviceId;              */ \
     0,           /*   uint8     RomBlockNum;                */ \
     CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */ \
     NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */ \
     0,           /*   boolean   BlockUseCrc;                */ \
     0,           /*   boolean   BlockUseSetRamBlockStatus;  */ \
     0,           /*   boolean BlockWriteProt;               */ \
     0,           /*   boolean   BswMBlockStatusInformation; */ \
     0,           /*   boolean   CalcRamBlockCrc;            */ \
     1,           /*   boolean   SelectBlockForReadAll;      */ \
     1,           /*   boolean   SelectBlockForWriteAll;     */ \
     0            /*  boolean   WriteBlockOnce;              */ \
  },
#endif


#endif

