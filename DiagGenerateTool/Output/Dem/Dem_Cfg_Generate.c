/*********************************************************************/
/*                       DiagTool.Generate Start                     */
/*                       Generate Data: 2022-10-12 18:08:40          */
/*                       Author: QHQ                                 */
/*********************************************************************/

#ifndef __DEM_CFG_GENERATE_C__
#define __DEM_CFG_GENERATE_C__


#include "Dem_Cfg_Generate.h"

const Dem_Cfg_PrimaryMemEntryType Dem_MemoryEntryInit = {0xFFFFFFFF,0,0,0,0,0,0,0,0,0,0,0,0,0};

const Dem_Cfg_OpCycleType DemCfg_OpCycle_Default = {0};
const Dem_Cfg_AdminDataType DemCfg_AdminData_Default = {0};
const Dem_Cfg_UdsStatusDataType DemCfg_StatusData_Default = {0};


//Dem Primary Table
Dem_Cfg_OpCycleType Dem_Cfg_OpCycle;
Dem_Cfg_AdminDataType Dem_Cfg_AdminData;
Dem_Cfg_UdsStatusDataType Dem_Cfg_StatusData;
Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_000 = {0xFFFFFFFF,0,0,0,0,0,0,0,0,0,0,0,0,0};
Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_001 = {0xFFFFFFFF,0,0,0,0,0,0,0,0,0,0,0,0,0};

//Dem NvmBlock RamData Table
const uint8* Dem_Cfg_MemPtr[Dem_Cfg_Mem_Total_Entry] = 
{
	(uint8*) &Dem_Cfg_OpCycle,   
	(uint8*) &Dem_Cfg_AdminData, 
	(uint8*) &Dem_Cfg_StatusData,
	(uint8*) &Dem_PrimaryEntry_000,
	(uint8*) &Dem_PrimaryEntry_001,
};

//Dem NvmBlock_Id Table
const Dem_Cfg_NvRamBlockIdType Dem_Cfg_Memory_BlockId[Dem_Cfg_Mem_Total_Entry] = 
{
	DemCfg_NvMBlockDescriptor_OpCycle,
	DemCfg_NvMBlockDescriptor_DemAdmin,
	DemCfg_NvMBlockDescriptor_DemStatus,
	DemCfg_NvMBlockDescriptor_DemPrimary_000,
	DemCfg_NvMBlockDescriptor_DemPrimary_001,
};



#endif
/*********************************************************************/
/*                       DiagTool.Generate End                       */
/*                       Author: QHQ                                 */
/*********************************************************************/
