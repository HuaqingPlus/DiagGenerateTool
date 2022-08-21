/*****************************************************************************
*
*  FILE        :NvM_Server.c
*  DESCRIPTION :NvM_Server.c
*  DATE        :2022-07-05
*  AUTHOR      :Qhq
*  NOTE:
*
******************************************************************************/
/*****************************************************************************
 *     Start of File
 *
 *****************************************************************************/
#ifndef __NVM_SERVER_C__
#define __NVM_SERVER_C__

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "NvM_Server.h"
#include "NvM.h"

/*****************************************************************************
*                  CallBack Functions                                        *
*****************************************************************************/
/*****************************************************************************
*Function   : NvmServer_ReadBlock_ById                                       *
*Description: TBD 	                                                         *
*Parameter	: NONE													     	 *
*Return 	: void                                                           *
*Author 	: QHQ                                                            *
*Date		: 2022-07-05                                                     *
*****************************************************************************/
void NvmServer_Init(void)
{
    NvmServer_InitFlags();
}


/*****************************************************************************
*Function   : NvmServer_Runnable                                             *
*Description: Handle Nvm Request	                                         *
*Parameter	: NONE													     	 *
*Return 	: void                                                           *
*Author 	: QHQ                                                            *
*Date		: 2022-07-05                                                     *
*****************************************************************************/
void NvmServer_MainFunction(void)
{
    uint8 index = 0;
    for(index = 0; index < NVM_NUM_OF_BLOCKS; index++)
    {
        if(Rte_DirtyFlags[index].DirtyFlag == 1)
        {
            (void)NvM_WriteBlock(Rte_DirtyFlags[index].BlockId, NULL_PTR);
            //Rte_DisableOSInterrupts();    /* Qiuhuaqing Modify,  To be Release after OsInterrupt Finished */
            Rte_DirtyFlags[index].DirtyFlag = 0;
            //Rte_EnableOSInterrupts();     /* Qiuhuaqing Modify,  To be Release after OsInterrupt Finished */
        }
    }
}

/*****************************************************************************
*Function   : NvmServer_InitFlags                                            *
*Description: Init DirtyFlag 	                                             *
*Parameter	: NONE													     	 *
*Return 	: void                                                           *
*Author 	: QHQ                                                            *
*Date		: 2022-07-05                                                     *
*****************************************************************************/
void NvmServer_InitFlags(void)
{
    uint8 index = 0;
    for(index = 0; index < NVM_NUM_OF_BLOCKS; index++)
    {
        Rte_DirtyFlags[index].DirtyFlag = 0;
    }
}

/*****************************************************************************
*Function   : NvmServer_WriteBlock_ById                                      *
*Description: API to Write Block 	                                         *
*Parameter	: NONE													     	 *
*Return 	: void                                                           *
*Author 	: QHQ                                                            *
*Date		: 2022-07-05                                                     *
*****************************************************************************/
uint8 NvmServer_WriteBlock_ById(uint8 BlockId, uint8* Data, uint8 len)
{
    uint8 ret = E_NOT_OK;
    uint8 index = 0;
    for(index = 0; index < NVM_NUM_OF_BLOCKS; index++)
    {
        if(BlockId == Rte_DirtyFlags[index].BlockId)
        {
            //Rte_DisableOSInterrupts(); /* Qiuhuaqing Modify,  To be Release after OsInterrupt Finished */
            Rte_DirtyFlags[index].DirtyFlag = 1;
            memcpy(Rte_DirtyFlags[index].RamAddress, Data, len);
            //Rte_EnableOSInterrupts(); /* Qiuhuaqing Modify,  To be Release after OsInterrupt Finished */
            ret = E_OK;
            break;
        }
    }
    return ret;
}

/*****************************************************************************
*Function   : NvmServer_ReadBlock_ById                                       *
*Description: API to Read Block 	                                         *
*Parameter	: NONE													     	 *
*Return 	: void                                                           *
*Author 	: QHQ                                                            *
*Date		: 2022-07-05                                                     *
*****************************************************************************/
uint8 NvmServer_ReadBlock_ById(uint8 BlockId, uint8* Data, uint8 len)
{
    uint8 ret = E_NOT_OK;
    uint8 index = 0;
     for(index = 0; index < NVM_NUM_OF_BLOCKS; index++)
    {
        if(BlockId == Rte_DirtyFlags[index].BlockId)
        {
            //Rte_DisableOSInterrupts(); /* Qiuhuaqing Modify,  To be Release after OsInterrupt Finished */
            memcpy(Data, Rte_DirtyFlags[index].RamAddress, len);
            //Rte_EnableOSInterrupts(); /* Qiuhuaqing Modify,  To be Release after OsInterrupt Finished */
            ret = E_OK;
            break;
        }
    }
}

#endif

/*****************************************************************************
 *     End of File
 *
 *****************************************************************************/

