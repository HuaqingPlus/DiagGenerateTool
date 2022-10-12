/*********************************************************************/
/*                       DiagTool.Generate Start                     */
/*                       Generate Data: 2022-10-12 18:08:40          */
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
uint8 NvMConfigBlock_RamBlock_au8[0] = {0};
uint8 NvmRamData_Odo[4] = {0};

//Rom Block
const uint8 NvmRomData_Odo[4] = {0};

//JobFinished Function
uint8 Rte_Call_Odo_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code Start        */
/*********************************************/
	uint8 fl_Ret_u8 = E_NOT_OK;
	if((ServiceId == NVM_READ_BLOCK) && (JobResult == NVM_REQ_OK))
	{
		fl_Ret_u8 = E_OK;
	}
	return fl_Ret_u8;
/*********************************************/
/*     !!! Don't Remove This Comment !!!     */
/*         User's Function Code end          */
/*********************************************/
}


//Dirty Flag
S_NvM_DirtyFlag_Type Rte_DirtyFlags[NVM_NUM_OF_BLOCKS] = \
{
	{NvMConf___MultiBlockRequest ,                      0,  NULL                          },\
	{NvMConf_NvMBlockDescriptor_NvMConfigBlock,         0,  (uint8*)(&NvMConfigBlock_RamBlock_au8)},\
	{DemCfg_NvMBlockDescriptor_OpCycle,                 0,  (uint8*)(&Dem_Cfg_OpCycle)    },\
	{DemCfg_NvMBlockDescriptor_DemAdmin,                0,  (uint8*)(&Dem_Cfg_AdminData)  },\
	{DemCfg_NvMBlockDescriptor_DemStatus,               0,  (uint8*)(&Dem_Cfg_StatusData) },\
	{DemCfg_NvMBlockDescriptor_DemPrimary_000,          0,  (uint8*)(&Dem_PrimaryEntry_000)},\
	{NvMConf_NvMBlockDescriptor_Odo,                    0,  (uint8*)(&NvmRamData_Odo)     },\
	{DemCfg_NvMBlockDescriptor_DemPrimary_001,          0,  (uint8*)(&Dem_PrimaryEntry_001)},\
};



#endif
/*********************************************************************/
/*                       DiagTool.Generate End                       */
/*                       Author: QHQ                                 */
/*********************************************************************/
