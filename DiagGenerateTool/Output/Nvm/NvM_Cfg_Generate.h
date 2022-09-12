/*********************************************************************/
/*                       DiagTool.Generate Start                     */
/*                       Generate Data: 2022-09-12 22:10:51          */
/*                       Author: QHQ                                 */
/*********************************************************************/

#ifndef __NVM_CFG_GENERATE_H__
#define __NVM_CFG_GENERATE_H__

#include "Std_Types.h"
#include "NvM_Types.h"
#include "NvM_Server.h"

#define NVM_NUM_OF_BLOCKS                                           ((uint8)17)
//BlockId
#define NvMConf___MultiBlockRequest                                 (0)
#define NvMConf_NvMBlockDescriptor_NvMConfigBlock                   (1)
#define NvMConf_NvMBlockDescriptor_VIN                              (2)
#define NvMConf_NvMBlockDescriptor_EcuConfig                        (3)
#define NvMConf_NvMBlockDescriptor_EIDCConfig                       (4)
#define DemCfg_NvMBlockDescriptor_OpCycle                           (5)
#define DemCfg_NvMBlockDescriptor_DemAdmin                          (6)
#define DemCfg_NvMBlockDescriptor_DemStatus                         (7)
#define DemCfg_NvMBlockDescriptor_DemPrimary_000                    (8)
#define DemCfg_NvMBlockDescriptor_DemPrimary_001                    (9)
#define DemCfg_NvMBlockDescriptor_DemPrimary_002                    (10)
#define DemCfg_NvMBlockDescriptor_DemPrimary_003                    (11)
#define DemCfg_NvMBlockDescriptor_DemPrimary_004                    (12)
#define DemCfg_NvMBlockDescriptor_DemPrimary_005                    (13)
#define DemCfg_NvMBlockDescriptor_DemPrimary_006                    (14)
#define DemCfg_NvMBlockDescriptor_DemPrimary_007                    (15)
#define DemCfg_NvMBlockDescriptor_DemPrimary_008                    (16)

//Ram Block
extern uint8 NvMConfigBlock_RamBlock_au8[32];
extern uint8 NvmRamData_VIN[17];
extern uint8 NvmRamData_EcuConfig[200];
extern uint8 NvmRamData_EIDCConfig[8];

//Rom Block
extern const uint8 NvmRomData_VIN[17];
extern const uint8 NvmRomData_EcuConfig[200];
extern const uint8 NvmRomData_EIDCConfig[8];

//JobFinished Function
uint8 Rte_Call_VIN_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult);
uint8 Rte_Call_EcuConfig_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult);
uint8 Rte_Call_EIDCConfig_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult);

//Dirty Flag
extern S_NvM_DirtyFlag_Type Rte_DirtyFlags[NVM_NUM_OF_BLOCKS];

//NVM Block Config
#ifndef NvmCfg_BlockConfig_Table
#define NvmCfg_BlockConfig_Table \
	{\
		NULL,                         /*   void (*InitCallback) (void);          */ \
		NULL,                         /*   void(*SingleBlockCallback)(void);     */ \
 		NULL,                         /*   uint8*    RamBlockDataAddress;        */ \
 		NULL,                         /*   uint8*    RomBlockDataAddress;        */ \
 		0,                            /*   uint16    NvBlockBaseNumber;          */ \
 		0,                            /*   uint16    NvBlockLength;              */ \
 		0,                            /*   uint16    NvRamBlockIdentifier;       */ \
 		1,                            /*   uint8     BlockJobPriority;           */ \
 		0,                            /*   uint8     MaxNumReadRetries;          */ \
 		0,                            /*   uint8     MaxNumWriteRetries;         */ \
		0,                            /*   uint8     NvBlockNum;                 */ \
		0,                            /*   uint8     NvRamDeviceId;              */ \
		0,                            /*   uint8     RomBlockNum;                */ \
		2,                            /*   NvM_CrcEnumeration BlockCrcType;      */ \
		1,                            /*   NvM_BlockType BlockManagementType;    */ \
		0,                            /*   boolean   BlockUseCrc;                */ \
		0,                            /*   boolean   BlockUseSetRamBlockStatus;  */ \
		0,                            /*   boolean BlockWriteProt;               */ \
		0,                            /*   boolean   BswMBlockStatusInformation; */ \
		0,                            /*   boolean   CalcRamBlockCrc;            */ \
		1,                            /*   boolean   SelectBlockForReadAll;      */ \
		1,                            /*   boolean   SelectBlockForWriteAll;     */ \
		0,                            /*   boolean   WriteBlockOnce;             */ \
	},\
	{\
		NULL,                         /*   void (*InitCallback) (void);          */ \
		NULL,                         /*   void(*SingleBlockCallback)(void);     */ \
 		(uint8*)&NvMConfigBlock_RamBlock_au8,/*   uint8*    RamBlockDataAddress;        */ \
 		NULL,                         /*   uint8*    RomBlockDataAddress;        */ \
 		1,                            /*   uint16    NvBlockBaseNumber;          */ \
 		32,                           /*   uint16    NvBlockLength;              */ \
 		0,                            /*   uint16    NvRamBlockIdentifier;       */ \
 		1,                            /*   uint8     BlockJobPriority;           */ \
 		0,                            /*   uint8     MaxNumReadRetries;          */ \
 		0,                            /*   uint8     MaxNumWriteRetries;         */ \
		0,                            /*   uint8     NvBlockNum;                 */ \
		0,                            /*   uint8     NvRamDeviceId;              */ \
		0,                            /*   uint8     RomBlockNum;                */ \
		2,                            /*   NvM_CrcEnumeration BlockCrcType;      */ \
		2,                            /*   NvM_BlockType BlockManagementType;    */ \
		0,                            /*   boolean   BlockUseCrc;                */ \
		0,                            /*   boolean   BlockUseSetRamBlockStatus;  */ \
		0,                            /*   boolean BlockWriteProt;               */ \
		0,                            /*   boolean   BswMBlockStatusInformation; */ \
		0,                            /*   boolean   CalcRamBlockCrc;            */ \
		1,                            /*   boolean   SelectBlockForReadAll;      */ \
		1,                            /*   boolean   SelectBlockForWriteAll;     */ \
		0,                            /*   boolean   WriteBlockOnce;             */ \
	},\
	{\
		NULL,                         /*   void (*InitCallback) (void);          */ \
		Rte_Call_VIN_JobFinished,     /*   void(*SingleBlockCallback)(void);     */ \
 		(uint8*)&NvmRamData_VIN,      /*   uint8*    RamBlockDataAddress;        */ \
 		(uint8*)&NvmRomData_VIN,      /*   uint8*    RomBlockDataAddress;        */ \
 		2,                            /*   uint16    NvBlockBaseNumber;          */ \
 		17,                           /*   uint16    NvBlockLength;              */ \
 		0,                            /*   uint16    NvRamBlockIdentifier;       */ \
 		1,                            /*   uint8     BlockJobPriority;           */ \
 		0,                            /*   uint8     MaxNumReadRetries;          */ \
 		0,                            /*   uint8     MaxNumWriteRetries;         */ \
		0,                            /*   uint8     NvBlockNum;                 */ \
		0,                            /*   uint8     NvRamDeviceId;              */ \
		0,                            /*   uint8     RomBlockNum;                */ \
		2,                            /*   NvM_CrcEnumeration BlockCrcType;      */ \
		0,                            /*   NvM_BlockType BlockManagementType;    */ \
		0,                            /*   boolean   BlockUseCrc;                */ \
		0,                            /*   boolean   BlockUseSetRamBlockStatus;  */ \
		0,                            /*   boolean BlockWriteProt;               */ \
		0,                            /*   boolean   BswMBlockStatusInformation; */ \
		0,                            /*   boolean   CalcRamBlockCrc;            */ \
		1,                            /*   boolean   SelectBlockForReadAll;      */ \
		1,                            /*   boolean   SelectBlockForWriteAll;     */ \
		0,                            /*   boolean   WriteBlockOnce;             */ \
	},\
	{\
		NULL,                         /*   void (*InitCallback) (void);          */ \
		Rte_Call_EcuConfig_JobFinished,/*   void(*SingleBlockCallback)(void);     */ \
 		(uint8*)&NvmRamData_EcuConfig,/*   uint8*    RamBlockDataAddress;        */ \
 		(uint8*)&NvmRomData_EcuConfig,/*   uint8*    RomBlockDataAddress;        */ \
 		3,                            /*   uint16    NvBlockBaseNumber;          */ \
 		200,                          /*   uint16    NvBlockLength;              */ \
 		0,                            /*   uint16    NvRamBlockIdentifier;       */ \
 		1,                            /*   uint8     BlockJobPriority;           */ \
 		0,                            /*   uint8     MaxNumReadRetries;          */ \
 		0,                            /*   uint8     MaxNumWriteRetries;         */ \
		0,                            /*   uint8     NvBlockNum;                 */ \
		0,                            /*   uint8     NvRamDeviceId;              */ \
		0,                            /*   uint8     RomBlockNum;                */ \
		2,                            /*   NvM_CrcEnumeration BlockCrcType;      */ \
		0,                            /*   NvM_BlockType BlockManagementType;    */ \
		0,                            /*   boolean   BlockUseCrc;                */ \
		0,                            /*   boolean   BlockUseSetRamBlockStatus;  */ \
		0,                            /*   boolean BlockWriteProt;               */ \
		0,                            /*   boolean   BswMBlockStatusInformation; */ \
		0,                            /*   boolean   CalcRamBlockCrc;            */ \
		1,                            /*   boolean   SelectBlockForReadAll;      */ \
		1,                            /*   boolean   SelectBlockForWriteAll;     */ \
		0,                            /*   boolean   WriteBlockOnce;             */ \
	},\
	{\
		NULL,                         /*   void (*InitCallback) (void);          */ \
		Rte_Call_EIDCConfig_JobFinished,/*   void(*SingleBlockCallback)(void);     */ \
 		(uint8*)&NvmRamData_EIDCConfig,/*   uint8*    RamBlockDataAddress;        */ \
 		(uint8*)&NvmRomData_EIDCConfig,/*   uint8*    RomBlockDataAddress;        */ \
 		4,                            /*   uint16    NvBlockBaseNumber;          */ \
 		8,                            /*   uint16    NvBlockLength;              */ \
 		0,                            /*   uint16    NvRamBlockIdentifier;       */ \
 		1,                            /*   uint8     BlockJobPriority;           */ \
 		0,                            /*   uint8     MaxNumReadRetries;          */ \
 		0,                            /*   uint8     MaxNumWriteRetries;         */ \
		0,                            /*   uint8     NvBlockNum;                 */ \
		0,                            /*   uint8     NvRamDeviceId;              */ \
		0,                            /*   uint8     RomBlockNum;                */ \
		2,                            /*   NvM_CrcEnumeration BlockCrcType;      */ \
		0,                            /*   NvM_BlockType BlockManagementType;    */ \
		0,                            /*   boolean   BlockUseCrc;                */ \
		0,                            /*   boolean   BlockUseSetRamBlockStatus;  */ \
		0,                            /*   boolean BlockWriteProt;               */ \
		0,                            /*   boolean   BswMBlockStatusInformation; */ \
		0,                            /*   boolean   CalcRamBlockCrc;            */ \
		1,                            /*   boolean   SelectBlockForReadAll;      */ \
		1,                            /*   boolean   SelectBlockForWriteAll;     */ \
		0,                            /*   boolean   WriteBlockOnce;             */ \
	},\
	{\
		NULL,                         /*   void (*InitCallback) (void);          */ \
		Dem_NvM_JobFinished,          /*   void(*SingleBlockCallback)(void);     */ \
 		(uint8*)&Dem_Cfg_OpCycle,     /*   uint8*    RamBlockDataAddress;        */ \
 		(uint8*)&DemCfg_OpCycle_Default,/*   uint8*    RomBlockDataAddress;        */ \
 		5,                            /*   uint16    NvBlockBaseNumber;          */ \
 		sizeof(Dem_Cfg_OpCycleType),  /*   uint16    NvBlockLength;              */ \
 		0,                            /*   uint16    NvRamBlockIdentifier;       */ \
 		1,                            /*   uint8     BlockJobPriority;           */ \
 		0,                            /*   uint8     MaxNumReadRetries;          */ \
 		0,                            /*   uint8     MaxNumWriteRetries;         */ \
		0,                            /*   uint8     NvBlockNum;                 */ \
		0,                            /*   uint8     NvRamDeviceId;              */ \
		0,                            /*   uint8     RomBlockNum;                */ \
		2,                            /*   NvM_CrcEnumeration BlockCrcType;      */ \
		0,                            /*   NvM_BlockType BlockManagementType;    */ \
		0,                            /*   boolean   BlockUseCrc;                */ \
		0,                            /*   boolean   BlockUseSetRamBlockStatus;  */ \
		0,                            /*   boolean BlockWriteProt;               */ \
		0,                            /*   boolean   BswMBlockStatusInformation; */ \
		0,                            /*   boolean   CalcRamBlockCrc;            */ \
		1,                            /*   boolean   SelectBlockForReadAll;      */ \
		1,                            /*   boolean   SelectBlockForWriteAll;     */ \
		0,                            /*   boolean   WriteBlockOnce;             */ \
	},\
	{\
		NULL,                         /*   void (*InitCallback) (void);          */ \
		Dem_NvM_JobFinished,          /*   void(*SingleBlockCallback)(void);     */ \
 		(uint8*)&Dem_Cfg_AdminData,   /*   uint8*    RamBlockDataAddress;        */ \
 		(uint8*)&DemCfg_AdminData_Default,/*   uint8*    RomBlockDataAddress;        */ \
 		6,                            /*   uint16    NvBlockBaseNumber;          */ \
 		sizeof(Dem_Cfg_AdminDataType),/*   uint16    NvBlockLength;              */ \
 		0,                            /*   uint16    NvRamBlockIdentifier;       */ \
 		1,                            /*   uint8     BlockJobPriority;           */ \
 		0,                            /*   uint8     MaxNumReadRetries;          */ \
 		0,                            /*   uint8     MaxNumWriteRetries;         */ \
		0,                            /*   uint8     NvBlockNum;                 */ \
		0,                            /*   uint8     NvRamDeviceId;              */ \
		0,                            /*   uint8     RomBlockNum;                */ \
		2,                            /*   NvM_CrcEnumeration BlockCrcType;      */ \
		0,                            /*   NvM_BlockType BlockManagementType;    */ \
		0,                            /*   boolean   BlockUseCrc;                */ \
		0,                            /*   boolean   BlockUseSetRamBlockStatus;  */ \
		0,                            /*   boolean BlockWriteProt;               */ \
		0,                            /*   boolean   BswMBlockStatusInformation; */ \
		0,                            /*   boolean   CalcRamBlockCrc;            */ \
		1,                            /*   boolean   SelectBlockForReadAll;      */ \
		1,                            /*   boolean   SelectBlockForWriteAll;     */ \
		0,                            /*   boolean   WriteBlockOnce;             */ \
	},\
	{\
		NULL,                         /*   void (*InitCallback) (void);          */ \
		Dem_NvM_JobFinished,          /*   void(*SingleBlockCallback)(void);     */ \
 		(uint8*)&Dem_Cfg_StatusData,  /*   uint8*    RamBlockDataAddress;        */ \
 		(uint8*)&DemCfg_StatusData_Default,/*   uint8*    RomBlockDataAddress;        */ \
 		7,                            /*   uint16    NvBlockBaseNumber;          */ \
 		sizeof(Dem_Cfg_UdsStatusDataType),/*   uint16    NvBlockLength;              */ \
 		0,                            /*   uint16    NvRamBlockIdentifier;       */ \
 		1,                            /*   uint8     BlockJobPriority;           */ \
 		0,                            /*   uint8     MaxNumReadRetries;          */ \
 		0,                            /*   uint8     MaxNumWriteRetries;         */ \
		0,                            /*   uint8     NvBlockNum;                 */ \
		0,                            /*   uint8     NvRamDeviceId;              */ \
		0,                            /*   uint8     RomBlockNum;                */ \
		2,                            /*   NvM_CrcEnumeration BlockCrcType;      */ \
		0,                            /*   NvM_BlockType BlockManagementType;    */ \
		0,                            /*   boolean   BlockUseCrc;                */ \
		0,                            /*   boolean   BlockUseSetRamBlockStatus;  */ \
		0,                            /*   boolean BlockWriteProt;               */ \
		0,                            /*   boolean   BswMBlockStatusInformation; */ \
		0,                            /*   boolean   CalcRamBlockCrc;            */ \
		1,                            /*   boolean   SelectBlockForReadAll;      */ \
		1,                            /*   boolean   SelectBlockForWriteAll;     */ \
		0,                            /*   boolean   WriteBlockOnce;             */ \
	},\
	{\
		NULL,                         /*   void (*InitCallback) (void);          */ \
		Dem_NvM_JobFinished,          /*   void(*SingleBlockCallback)(void);     */ \
 		(uint8*)&Dem_PrimaryEntry_000,/*   uint8*    RamBlockDataAddress;        */ \
 		(uint8*)&Dem_MemoryEntryInit, /*   uint8*    RomBlockDataAddress;        */ \
 		8,                            /*   uint16    NvBlockBaseNumber;          */ \
 		sizeof(Dem_Cfg_PrimaryMemEntryType),/*   uint16    NvBlockLength;              */ \
 		0,                            /*   uint16    NvRamBlockIdentifier;       */ \
 		1,                            /*   uint8     BlockJobPriority;           */ \
 		0,                            /*   uint8     MaxNumReadRetries;          */ \
 		0,                            /*   uint8     MaxNumWriteRetries;         */ \
		0,                            /*   uint8     NvBlockNum;                 */ \
		1,                            /*   uint8     NvRamDeviceId;              */ \
		0,                            /*   uint8     RomBlockNum;                */ \
		2,                            /*   NvM_CrcEnumeration BlockCrcType;      */ \
		0,                            /*   NvM_BlockType BlockManagementType;    */ \
		0,                            /*   boolean   BlockUseCrc;                */ \
		0,                            /*   boolean   BlockUseSetRamBlockStatus;  */ \
		0,                            /*   boolean BlockWriteProt;               */ \
		0,                            /*   boolean   BswMBlockStatusInformation; */ \
		0,                            /*   boolean   CalcRamBlockCrc;            */ \
		1,                            /*   boolean   SelectBlockForReadAll;      */ \
		1,                            /*   boolean   SelectBlockForWriteAll;     */ \
		0,                            /*   boolean   WriteBlockOnce;             */ \
	},\
	{\
		NULL,                         /*   void (*InitCallback) (void);          */ \
		Dem_NvM_JobFinished,          /*   void(*SingleBlockCallback)(void);     */ \
 		(uint8*)&Dem_PrimaryEntry_001,/*   uint8*    RamBlockDataAddress;        */ \
 		(uint8*)&Dem_MemoryEntryInit, /*   uint8*    RomBlockDataAddress;        */ \
 		9,                            /*   uint16    NvBlockBaseNumber;          */ \
 		sizeof(Dem_Cfg_PrimaryMemEntryType),/*   uint16    NvBlockLength;              */ \
 		0,                            /*   uint16    NvRamBlockIdentifier;       */ \
 		1,                            /*   uint8     BlockJobPriority;           */ \
 		0,                            /*   uint8     MaxNumReadRetries;          */ \
 		0,                            /*   uint8     MaxNumWriteRetries;         */ \
		0,                            /*   uint8     NvBlockNum;                 */ \
		1,                            /*   uint8     NvRamDeviceId;              */ \
		0,                            /*   uint8     RomBlockNum;                */ \
		2,                            /*   NvM_CrcEnumeration BlockCrcType;      */ \
		0,                            /*   NvM_BlockType BlockManagementType;    */ \
		0,                            /*   boolean   BlockUseCrc;                */ \
		0,                            /*   boolean   BlockUseSetRamBlockStatus;  */ \
		0,                            /*   boolean BlockWriteProt;               */ \
		0,                            /*   boolean   BswMBlockStatusInformation; */ \
		0,                            /*   boolean   CalcRamBlockCrc;            */ \
		1,                            /*   boolean   SelectBlockForReadAll;      */ \
		1,                            /*   boolean   SelectBlockForWriteAll;     */ \
		0,                            /*   boolean   WriteBlockOnce;             */ \
	},\
	{\
		NULL,                         /*   void (*InitCallback) (void);          */ \
		Dem_NvM_JobFinished,          /*   void(*SingleBlockCallback)(void);     */ \
 		(uint8*)&Dem_PrimaryEntry_002,/*   uint8*    RamBlockDataAddress;        */ \
 		(uint8*)&Dem_MemoryEntryInit, /*   uint8*    RomBlockDataAddress;        */ \
 		10,                           /*   uint16    NvBlockBaseNumber;          */ \
 		sizeof(Dem_Cfg_PrimaryMemEntryType),/*   uint16    NvBlockLength;              */ \
 		0,                            /*   uint16    NvRamBlockIdentifier;       */ \
 		1,                            /*   uint8     BlockJobPriority;           */ \
 		0,                            /*   uint8     MaxNumReadRetries;          */ \
 		0,                            /*   uint8     MaxNumWriteRetries;         */ \
		0,                            /*   uint8     NvBlockNum;                 */ \
		0,                            /*   uint8     NvRamDeviceId;              */ \
		0,                            /*   uint8     RomBlockNum;                */ \
		2,                            /*   NvM_CrcEnumeration BlockCrcType;      */ \
		0,                            /*   NvM_BlockType BlockManagementType;    */ \
		0,                            /*   boolean   BlockUseCrc;                */ \
		0,                            /*   boolean   BlockUseSetRamBlockStatus;  */ \
		0,                            /*   boolean BlockWriteProt;               */ \
		0,                            /*   boolean   BswMBlockStatusInformation; */ \
		0,                            /*   boolean   CalcRamBlockCrc;            */ \
		1,                            /*   boolean   SelectBlockForReadAll;      */ \
		1,                            /*   boolean   SelectBlockForWriteAll;     */ \
		0,                            /*   boolean   WriteBlockOnce;             */ \
	},\
	{\
		NULL,                         /*   void (*InitCallback) (void);          */ \
		Dem_NvM_JobFinished,          /*   void(*SingleBlockCallback)(void);     */ \
 		(uint8*)&Dem_PrimaryEntry_003,/*   uint8*    RamBlockDataAddress;        */ \
 		(uint8*)&Dem_MemoryEntryInit, /*   uint8*    RomBlockDataAddress;        */ \
 		11,                           /*   uint16    NvBlockBaseNumber;          */ \
 		sizeof(Dem_Cfg_PrimaryMemEntryType),/*   uint16    NvBlockLength;              */ \
 		0,                            /*   uint16    NvRamBlockIdentifier;       */ \
 		1,                            /*   uint8     BlockJobPriority;           */ \
 		0,                            /*   uint8     MaxNumReadRetries;          */ \
 		0,                            /*   uint8     MaxNumWriteRetries;         */ \
		0,                            /*   uint8     NvBlockNum;                 */ \
		0,                            /*   uint8     NvRamDeviceId;              */ \
		0,                            /*   uint8     RomBlockNum;                */ \
		2,                            /*   NvM_CrcEnumeration BlockCrcType;      */ \
		0,                            /*   NvM_BlockType BlockManagementType;    */ \
		0,                            /*   boolean   BlockUseCrc;                */ \
		0,                            /*   boolean   BlockUseSetRamBlockStatus;  */ \
		0,                            /*   boolean BlockWriteProt;               */ \
		0,                            /*   boolean   BswMBlockStatusInformation; */ \
		0,                            /*   boolean   CalcRamBlockCrc;            */ \
		1,                            /*   boolean   SelectBlockForReadAll;      */ \
		1,                            /*   boolean   SelectBlockForWriteAll;     */ \
		0,                            /*   boolean   WriteBlockOnce;             */ \
	},\
	{\
		NULL,                         /*   void (*InitCallback) (void);          */ \
		Dem_NvM_JobFinished,          /*   void(*SingleBlockCallback)(void);     */ \
 		(uint8*)&Dem_PrimaryEntry_004,/*   uint8*    RamBlockDataAddress;        */ \
 		(uint8*)&Dem_MemoryEntryInit, /*   uint8*    RomBlockDataAddress;        */ \
 		12,                           /*   uint16    NvBlockBaseNumber;          */ \
 		sizeof(Dem_Cfg_PrimaryMemEntryType),/*   uint16    NvBlockLength;              */ \
 		0,                            /*   uint16    NvRamBlockIdentifier;       */ \
 		1,                            /*   uint8     BlockJobPriority;           */ \
 		0,                            /*   uint8     MaxNumReadRetries;          */ \
 		0,                            /*   uint8     MaxNumWriteRetries;         */ \
		0,                            /*   uint8     NvBlockNum;                 */ \
		0,                            /*   uint8     NvRamDeviceId;              */ \
		0,                            /*   uint8     RomBlockNum;                */ \
		2,                            /*   NvM_CrcEnumeration BlockCrcType;      */ \
		0,                            /*   NvM_BlockType BlockManagementType;    */ \
		0,                            /*   boolean   BlockUseCrc;                */ \
		0,                            /*   boolean   BlockUseSetRamBlockStatus;  */ \
		0,                            /*   boolean BlockWriteProt;               */ \
		0,                            /*   boolean   BswMBlockStatusInformation; */ \
		0,                            /*   boolean   CalcRamBlockCrc;            */ \
		1,                            /*   boolean   SelectBlockForReadAll;      */ \
		1,                            /*   boolean   SelectBlockForWriteAll;     */ \
		0,                            /*   boolean   WriteBlockOnce;             */ \
	},\
	{\
		NULL,                         /*   void (*InitCallback) (void);          */ \
		Dem_NvM_JobFinished,          /*   void(*SingleBlockCallback)(void);     */ \
 		(uint8*)&Dem_PrimaryEntry_005,/*   uint8*    RamBlockDataAddress;        */ \
 		(uint8*)&Dem_MemoryEntryInit, /*   uint8*    RomBlockDataAddress;        */ \
 		13,                           /*   uint16    NvBlockBaseNumber;          */ \
 		sizeof(Dem_Cfg_PrimaryMemEntryType),/*   uint16    NvBlockLength;              */ \
 		0,                            /*   uint16    NvRamBlockIdentifier;       */ \
 		1,                            /*   uint8     BlockJobPriority;           */ \
 		0,                            /*   uint8     MaxNumReadRetries;          */ \
 		0,                            /*   uint8     MaxNumWriteRetries;         */ \
		0,                            /*   uint8     NvBlockNum;                 */ \
		0,                            /*   uint8     NvRamDeviceId;              */ \
		0,                            /*   uint8     RomBlockNum;                */ \
		2,                            /*   NvM_CrcEnumeration BlockCrcType;      */ \
		0,                            /*   NvM_BlockType BlockManagementType;    */ \
		0,                            /*   boolean   BlockUseCrc;                */ \
		0,                            /*   boolean   BlockUseSetRamBlockStatus;  */ \
		0,                            /*   boolean BlockWriteProt;               */ \
		0,                            /*   boolean   BswMBlockStatusInformation; */ \
		0,                            /*   boolean   CalcRamBlockCrc;            */ \
		1,                            /*   boolean   SelectBlockForReadAll;      */ \
		1,                            /*   boolean   SelectBlockForWriteAll;     */ \
		0,                            /*   boolean   WriteBlockOnce;             */ \
	},\
	{\
		NULL,                         /*   void (*InitCallback) (void);          */ \
		Dem_NvM_JobFinished,          /*   void(*SingleBlockCallback)(void);     */ \
 		(uint8*)&Dem_PrimaryEntry_006,/*   uint8*    RamBlockDataAddress;        */ \
 		(uint8*)&Dem_MemoryEntryInit, /*   uint8*    RomBlockDataAddress;        */ \
 		14,                           /*   uint16    NvBlockBaseNumber;          */ \
 		sizeof(Dem_Cfg_PrimaryMemEntryType),/*   uint16    NvBlockLength;              */ \
 		0,                            /*   uint16    NvRamBlockIdentifier;       */ \
 		1,                            /*   uint8     BlockJobPriority;           */ \
 		0,                            /*   uint8     MaxNumReadRetries;          */ \
 		0,                            /*   uint8     MaxNumWriteRetries;         */ \
		0,                            /*   uint8     NvBlockNum;                 */ \
		0,                            /*   uint8     NvRamDeviceId;              */ \
		0,                            /*   uint8     RomBlockNum;                */ \
		2,                            /*   NvM_CrcEnumeration BlockCrcType;      */ \
		0,                            /*   NvM_BlockType BlockManagementType;    */ \
		0,                            /*   boolean   BlockUseCrc;                */ \
		0,                            /*   boolean   BlockUseSetRamBlockStatus;  */ \
		0,                            /*   boolean BlockWriteProt;               */ \
		0,                            /*   boolean   BswMBlockStatusInformation; */ \
		0,                            /*   boolean   CalcRamBlockCrc;            */ \
		1,                            /*   boolean   SelectBlockForReadAll;      */ \
		1,                            /*   boolean   SelectBlockForWriteAll;     */ \
		0,                            /*   boolean   WriteBlockOnce;             */ \
	},\
	{\
		NULL,                         /*   void (*InitCallback) (void);          */ \
		Dem_NvM_JobFinished,          /*   void(*SingleBlockCallback)(void);     */ \
 		(uint8*)&Dem_PrimaryEntry_007,/*   uint8*    RamBlockDataAddress;        */ \
 		(uint8*)&Dem_MemoryEntryInit, /*   uint8*    RomBlockDataAddress;        */ \
 		15,                           /*   uint16    NvBlockBaseNumber;          */ \
 		sizeof(Dem_Cfg_PrimaryMemEntryType),/*   uint16    NvBlockLength;              */ \
 		0,                            /*   uint16    NvRamBlockIdentifier;       */ \
 		1,                            /*   uint8     BlockJobPriority;           */ \
 		0,                            /*   uint8     MaxNumReadRetries;          */ \
 		0,                            /*   uint8     MaxNumWriteRetries;         */ \
		0,                            /*   uint8     NvBlockNum;                 */ \
		0,                            /*   uint8     NvRamDeviceId;              */ \
		0,                            /*   uint8     RomBlockNum;                */ \
		2,                            /*   NvM_CrcEnumeration BlockCrcType;      */ \
		2,                            /*   NvM_BlockType BlockManagementType;    */ \
		0,                            /*   boolean   BlockUseCrc;                */ \
		0,                            /*   boolean   BlockUseSetRamBlockStatus;  */ \
		0,                            /*   boolean BlockWriteProt;               */ \
		0,                            /*   boolean   BswMBlockStatusInformation; */ \
		0,                            /*   boolean   CalcRamBlockCrc;            */ \
		1,                            /*   boolean   SelectBlockForReadAll;      */ \
		1,                            /*   boolean   SelectBlockForWriteAll;     */ \
		0,                            /*   boolean   WriteBlockOnce;             */ \
	},\
	{\
		NULL,                         /*   void (*InitCallback) (void);          */ \
		Dem_NvM_JobFinished,          /*   void(*SingleBlockCallback)(void);     */ \
 		(uint8*)&Dem_PrimaryEntry_008,/*   uint8*    RamBlockDataAddress;        */ \
 		(uint8*)&Dem_MemoryEntryInit, /*   uint8*    RomBlockDataAddress;        */ \
 		16,                           /*   uint16    NvBlockBaseNumber;          */ \
 		sizeof(Dem_Cfg_PrimaryMemEntryType),/*   uint16    NvBlockLength;              */ \
 		0,                            /*   uint16    NvRamBlockIdentifier;       */ \
 		1,                            /*   uint8     BlockJobPriority;           */ \
 		0,                            /*   uint8     MaxNumReadRetries;          */ \
 		0,                            /*   uint8     MaxNumWriteRetries;         */ \
		0,                            /*   uint8     NvBlockNum;                 */ \
		0,                            /*   uint8     NvRamDeviceId;              */ \
		0,                            /*   uint8     RomBlockNum;                */ \
		2,                            /*   NvM_CrcEnumeration BlockCrcType;      */ \
		1,                            /*   NvM_BlockType BlockManagementType;    */ \
		0,                            /*   boolean   BlockUseCrc;                */ \
		0,                            /*   boolean   BlockUseSetRamBlockStatus;  */ \
		0,                            /*   boolean BlockWriteProt;               */ \
		0,                            /*   boolean   BswMBlockStatusInformation; */ \
		0,                            /*   boolean   CalcRamBlockCrc;            */ \
		1,                            /*   boolean   SelectBlockForReadAll;      */ \
		1,                            /*   boolean   SelectBlockForWriteAll;     */ \
		0,                            /*   boolean   WriteBlockOnce;             */ \
	},\

#endif


#endif
/*********************************************************************/
/*                       DiagTool.Generate End                       */
/*                       Author: QHQ                                 */
/*********************************************************************/
