/*********************************************************************/
/*                       DiagTool.Generate Start                     */
/*                       Generate Data: 2022-09-07 11:34:58          */
/*                       Author: QHQ                                 */
/*********************************************************************/

#ifndef __NVM_CFG_GENERATE_C__
#define __NVM_CFG_GENERATE_C__

#include "Std_Types.h"
#include "Dem_Cfg.h"
#include "NvM.h"

/****************************************************************************/
/*                      !!! Don't Remove This Comment !!!                   */
/*                              User's Code Start                           */
/****************************************************************************/
/****************************************************************************/
/*                        !!! Don't Remove This Comment !!!                 */
/*                                User's Code end                           */
/****************************************************************************/

//Ram Block
uint8 NvMConfigBlock_RamBlock_au8[32] = {0};
uint8 NvmRamData_VIN[17] = {0};
uint8 NvmRamData_EcuConfig[200] = {0};
uint8 NvmRamData_EIDCConfig[8] = {0};

//Rom Block
const uint8 NvmRomData_VIN[17] = {0x4C, 0x58, 0x57, 0x59, 0x45, 0x50, 0x47, 0x32, 0x38, 0x4A, 0x48, 0x30, 0x30, 0x31, 0x37, 0x35, 0x32};
const uint8 NvmRomData_EcuConfig[200] = {\
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,\
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,\
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,\
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,\
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,\
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,\
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,\
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,\
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,\
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,\
};
const uint8 NvmRomData_EIDCConfig[8] = {0,1,0,2,0,0,0,0};

//JobFinished Function
uint8 Rte_Call_VIN_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
	uint8 fl_Ret_u8 = E_NOT_OK;
	if((ServiceId == NVM_READ_BLOCK) && (JobResult == NVM_REQ_OK))
	{
		fl_Ret_u8 = E_OK;
	}
	return fl_Ret_u8;
}

uint8 Rte_Call_EcuConfig_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
	uint8 fl_Ret_u8 = E_NOT_OK;
	if((ServiceId == NVM_READ_BLOCK) && (JobResult == NVM_REQ_OK))
	{
		fl_Ret_u8 = E_OK;
	}
	return fl_Ret_u8;
}

uint8 Rte_Call_EIDCConfig_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
	uint8 fl_Ret_u8 = E_NOT_OK;
	if((ServiceId == NVM_READ_BLOCK) && (JobResult == NVM_REQ_OK))
	{
		fl_Ret_u8 = E_OK;
	}
	return fl_Ret_u8;
}


//Dirty Flag
S_NvM_DirtyFlag_Type Rte_DirtyFlags[NVM_NUM_OF_BLOCKS] = \
{
	{NvMConf___MultiBlockRequest,                       0,  NULL                          },\
	{NvMConf_NvMBlockDescriptor_NvMConfigBlock,         0,  (uint8*)(&NvMConfigBlock_RamBlock_au8)},\
	{NvMConf_NvMBlockDescriptor_VIN,                    0,  (uint8*)(&NvmRamData_VIN)     },\
	{NvMConf_NvMBlockDescriptor_EcuConfig,              0,  (uint8*)(&NvmRamData_EcuConfig)},\
	{NvMConf_NvMBlockDescriptor_EIDCConfig,             0,  (uint8*)(&NvmRamData_EIDCConfig)},\
	{DemCfg_NvMBlockDescriptor_OpCycle,                 0,  (uint8*)(&Dem_Cfg_OpCycle)    },\
	{DemCfg_NvMBlockDescriptor_DemAdmin,                0,  (uint8*)(&Dem_Cfg_AdminData)  },\
	{DemCfg_NvMBlockDescriptor_DemStatus,               0,  (uint8*)(&Dem_Cfg_StatusData) },\
	{DemCfg_NvMBlockDescriptor_DemPrimary_000,          0,  (uint8*)(&Dem_PrimaryEntry_000)},\
	{DemCfg_NvMBlockDescriptor_DemPrimary_001,          0,  (uint8*)(&Dem_PrimaryEntry_001)},\
	{DemCfg_NvMBlockDescriptor_DemPrimary_002,          0,  (uint8*)(&Dem_PrimaryEntry_002)},\
	{DemCfg_NvMBlockDescriptor_DemPrimary_003,          0,  (uint8*)(&Dem_PrimaryEntry_003)},\
	{DemCfg_NvMBlockDescriptor_DemPrimary_004,          0,  (uint8*)(&Dem_PrimaryEntry_004)},\
	{DemCfg_NvMBlockDescriptor_DemPrimary_005,          0,  (uint8*)(&Dem_PrimaryEntry_005)},\
	{DemCfg_NvMBlockDescriptor_DemPrimary_006,          0,  (uint8*)(&Dem_PrimaryEntry_006)},\
	{DemCfg_NvMBlockDescriptor_DemPrimary_007,          0,  (uint8*)(&Dem_PrimaryEntry_007)},\
	{DemCfg_NvMBlockDescriptor_DemPrimary_008,          0,  (uint8*)(&Dem_PrimaryEntry_008)},\
};



#endif
/*********************************************************************/
/*                       DiagTool.Generate End                       */
/*                       Author: QHQ                                 */
/*********************************************************************/
