#include "Dem_Cfg_Generate.h"

//Dem_Cfg_NvmBlock_DefaultValue
const Dem_Cfg_PrimaryMemEntryType Dem_MemoryEntryInit = {0xFFFFFFFF,0,0,0,0,0,0,0,0,0,0,0,0,0};

Dem_Cfg_OpCycleType Dem_Cfg_OpCycle_Default;
Dem_Cfg_AdminDataType Dem_Cfg_AdminData_Default;
Dem_Cfg_UdsStatusDataType Dem_Cfg_StatusData_Default;


//Dem Primary Table
Dem_Cfg_OpCycleType Dem_Cfg_OpCycle;
Dem_Cfg_AdminDataType Dem_Cfg_AdminData;
Dem_Cfg_UdsStatusDataType Dem_Cfg_StatusData;

Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_000 = {0xFFFFFFFF,0,0,0,0,0,0,0,0,0,0,0,0,0};
Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_001 = {0xFFFFFFFF,0,0,0,0,0,0,0,0,0,0,0,0,0};
Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_002 = {0xFFFFFFFF,0,0,0,0,0,0,0,0,0,0,0,0,0};
Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_003 = {0xFFFFFFFF,0,0,0,0,0,0,0,0,0,0,0,0,0};
Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_004 = {0xFFFFFFFF,0,0,0,0,0,0,0,0,0,0,0,0,0};
Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_005 = {0xFFFFFFFF,0,0,0,0,0,0,0,0,0,0,0,0,0};
Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_006 = {0xFFFFFFFF,0,0,0,0,0,0,0,0,0,0,0,0,0};

//Dem NvmBlock RamData Table
const uint8* Dem_Cfg_MemPtr[Dem_Cfg_Mem_Total_Entry] = 
{
	(uint8*) &Dem_Cfg_OpCycle,   
	(uint8*) &Dem_Cfg_AdminData, 
	(uint8*) &Dem_Cfg_StatusData,
	(uint8*) &Dem_PrimaryEntry_000,
	(uint8*) &Dem_PrimaryEntry_001,
	(uint8*) &Dem_PrimaryEntry_002,
	(uint8*) &Dem_PrimaryEntry_003,
	(uint8*) &Dem_PrimaryEntry_004,
	(uint8*) &Dem_PrimaryEntry_005,
	(uint8*) &Dem_PrimaryEntry_006,
};

//Dem NvmBlock_Id Table
const Dem_Cfg_NvRamBlockIdType Dem_Cfg_Memory_BlockId[Dem_Cfg_Mem_Total_Entry] = 
{
	DemCfg_NvMBlockDescriptor_OpCycle,
	DemCfg_NvMBlockDescriptor_DemAdmin,
	DemCfg_NvMBlockDescriptor_DemStatus,
	DemCfg_NvMBlockDescriptor_DemPrimary_000,
	DemCfg_NvMBlockDescriptor_DemPrimary_001,
	DemCfg_NvMBlockDescriptor_DemPrimary_002,
	DemCfg_NvMBlockDescriptor_DemPrimary_003,
	DemCfg_NvMBlockDescriptor_DemPrimary_004,
	DemCfg_NvMBlockDescriptor_DemPrimary_005,
	DemCfg_NvMBlockDescriptor_DemPrimary_006,
};