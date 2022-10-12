/*********************************************************************/
/*                       DiagTool.Generate Start                     */
/*                       Generate Data: 2022-10-12 18:08:40          */
/*                       Author: QHQ                                 */
/*********************************************************************/

#ifndef __NVM_CFG_GENERATE_H__
#define __NVM_CFG_GENERATE_H__

#include "Std_Types.h"
#include "NvM_Types.h"
#include "NvM_Server.h"

#define NVM_NUM_OF_BLOCKS                                           ((uint8)8)
//BlockId
#define NvMConf___MultiBlockRequest                                 (0)
#define NvMConf_NvMBlockDescriptor_NvMConfigBlock                   (1)
#define DemCfg_NvMBlockDescriptor_OpCycle                           (2)
#define DemCfg_NvMBlockDescriptor_DemAdmin                          (3)
#define DemCfg_NvMBlockDescriptor_DemStatus                         (4)
#define DemCfg_NvMBlockDescriptor_DemPrimary_000                    (5)
#define NvMConf_NvMBlockDescriptor_Odo                              (6)
#define DemCfg_NvMBlockDescriptor_DemPrimary_001                    (7)

//Ram Block
extern uint8 NvMConfigBlock_RamBlock_au8[0];
extern uint8 NvmRamData_Odo[4];

//Rom Block
extern const uint8 NvmRomData_Odo[4];

//JobFinished Function
uint8 Rte_Call_Odo_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult);

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
		0,                            /*   NvM_CrcEnumeration BlockCrcType;      */ \
		0,                            /*   NvM_BlockType BlockManagementType;    */ \
		0,                            /*   boolean   BlockUseCrc;                */ \
		0,                            /*   boolean   BlockUseSetRamBlockStatus;  */ \
		0,                            /*   boolean BlockWriteProt;               */ \
		0,                            /*   boolean   BswMBlockStatusInformation; */ \
		0,                            /*   boolean   CalcRamBlockCrc;            */ \
		1,                            /*   boolean   SelectBlockForReadAll;      */ \
		0,                            /*   boolean   SelectBlockForWriteAll;     */ \
		0,                            /*   boolean   WriteBlockOnce;             */ \
	},\
	{\
		NULL,                         /*   void (*InitCallback) (void);          */ \
		NULL,                         /*   void(*SingleBlockCallback)(void);     */ \
 		(uint8*)&NvMConfigBlock_RamBlock_au8,/*   uint8*    RamBlockDataAddress;        */ \
 		NULL,                         /*   uint8*    RomBlockDataAddress;        */ \
 		1,                            /*   uint16    NvBlockBaseNumber;          */ \
 		0,                            /*   uint16    NvBlockLength;              */ \
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
 		2,                            /*   uint16    NvBlockBaseNumber;          */ \
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
 		3,                            /*   uint16    NvBlockBaseNumber;          */ \
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
 		4,                            /*   uint16    NvBlockBaseNumber;          */ \
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
 		5,                            /*   uint16    NvBlockBaseNumber;          */ \
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
		Rte_Call_Odo_JobFinished,     /*   void(*SingleBlockCallback)(void);     */ \
 		(uint8*)&NvmRamData_Odo,      /*   uint8*    RamBlockDataAddress;        */ \
 		(uint8*)&NvmRomData_Odo,      /*   uint8*    RomBlockDataAddress;        */ \
 		6,                            /*   uint16    NvBlockBaseNumber;          */ \
 		4,                            /*   uint16    NvBlockLength;              */ \
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
 		(uint8*)&Dem_PrimaryEntry_001,/*   uint8*    RamBlockDataAddress;        */ \
 		(uint8*)&Dem_MemoryEntryInit, /*   uint8*    RomBlockDataAddress;        */ \
 		7,                            /*   uint16    NvBlockBaseNumber;          */ \
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

#endif


#endif
/*********************************************************************/
/*                       DiagTool.Generate End                       */
/*                       Author: QHQ                                 */
/*********************************************************************/
