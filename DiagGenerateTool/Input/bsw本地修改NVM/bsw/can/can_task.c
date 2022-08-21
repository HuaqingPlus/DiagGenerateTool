/* ###################################################################
**     Filename    : can_init.c
**     Processor   : S32K1xx
**     Abstract    :
**         can initilization module.
** 
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/

/* Including necessary module. Cpu.h contains other modules needed for compiling.*/
#include <stddef.h>
#include "Cpu.h"
#include "CanNm.h"
#include "Det.h" 
#include "Nm.h" 
#include "CanTp.h" 
#include "CanIf.h" 
#include "Can.h" 
#include "CanSM_EcuM.h" 
#include "PduR.h" 
#include "ComM.h"  
#include "Com.h"
#include "SchM_Com.h"
#include "SchM_CanNm.h"
#include "SchM_CanSm.h"
#include "SchM_CanTp.h"
#include "ComM_EcuMBswM.h"
#include "Dcm.h"
#include "Dem.h"
#include "NvM.h"
#include "NvM_Server.h"
#include "Fee.h"
#include "Fls.h"
#include "Can_Flexcan.h"
#include "Can_IPW.h"
#include "tja1045a.h"

ISR(Can_IsrFCA_RxFifoEventsMbMix);
ISR(Can_IsrFCA_BO);
extern void NvM_ReadAll_Write_Status(uint8 status);
void CAN_RequsetCommodeInit(void)
{
	Tja1445_init();
	CanSM_StartWakeupSources(0);
}
void CanMianFunction(void)
{

	ComM_MainFunction_0(); /* PRQA S 2987 */ /* MD_Rte_2987 */
	Com_MainFunctionTx();
	Com_MainFunctionRx();
	CanNm_MainFunction();
	CanSM_MainFunction();
	CanTp_MainFunction();
	Can_MainFunction_Mode();
	Dcm_MainFunction();
	Dem_MainFunction();
	NvM_MainFunction();
	NvmServer_MainFunction();
	Fee_MainFunction();
	Fls_MainFunction();

}

void task_CanInitilization(void)
{
	INT_SYS_InstallHandler(CAN0_ORed_IRQn, Can_IsrFCA_BO, (isr_t *)0);
	INT_SYS_InstallHandler(CAN0_ORed_0_15_MB_IRQn, Can_IsrFCA_RxFifoEventsMbMix, (isr_t *)0);
	INT_SYS_EnableIRQ(CAN0_ORed_IRQn);
	INT_SYS_EnableIRQ(CAN0_ORed_0_15_MB_IRQn);

	CanNm_InitMemory(); 
    Det_InitMemory();
    Nm_InitMemory();
    CanTp_InitMemory();
    CanIf_InitMemory();
    CanSM_InitMemory();
    PduR_InitMemory();
    Det_Init( NULL_PTR );
    ComM_InitMemory();
    Com_InitMemory();
    Dcm_InitMemory();

	PduR_PreInit(PduR_Config_Ptr);
	Dem_PreInit();
	Can_Init(&CanConfigSet);
    CanIf_Init(CanIf_Config_Ptr);
    Com_Init(Com_Config_Ptr);
    PduR_Init(PduR_Config_Ptr);
    CanSM_Init(CanSM_Config_Ptr);
    CanNm_Init(CanNm_Config_Ptr);
    Nm_Init();
    CanTp_Init(CanTp_Config_Ptr);
    ComM_Init();
    Dcm_Init(NULL_PTR);
	NvM_Init();
	NvmServer_Init();
	Fee_Init();
	Fls_Init(&Fls_Config);

	NvM_ReadAll();
}

//NvM_ReadAll CallBack Function
FUNC( void, NVM_CODE) NvM_MultiBlockJobEndNotification(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{

	if (ServiceId == NVM_READ_ALL)
	{
		if (JobResult != NVM_REQ_PENDING)
		{
			NvM_ReadAll_Write_Status(TRUE);
            Dem_Init(NULL_PTR);
		}
	}
	else if(ServiceId == NVM_WRITE_ALL)
	{
        // NvM_WriteAllJobResult = JobResult;
        // NvM_WriteAllFinished = TRUE;
	}
}

