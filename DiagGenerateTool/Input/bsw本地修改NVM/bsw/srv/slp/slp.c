/*---------------------------------------------------------------------------
** Project Name:
** #Archive: #
** #Author: #
** #Date: #
** (c) Copyright 2010, Lear Corporation
**----------------------------------------------------------------------------
** #Revision: #
**----------------------------------------------------------------------------
** Target system:  S32K
** Compiler:       S32DS
**----------------------------------------------------------------------------
**               A U T H O R   I D E N T I T Y
**----------------------------------------------------------------------------
** Initials     Name                     Company
** --------     ---------------------    -------------------------------------
** PF           Pep Fernandez            LEAR CORPORATION
** ROLF         Roberto Lanuza           LEAR CORPORATION
**----------------------------------------------------------------------------
**               R E V I S I O N   H I S T O R Y
**----------------------------------------------------------------------------
** #Log: #
**--------------------------------------------------------------------------*/
/*lint -wlib(0)*/

/*----------------------------------------------------------------------------
** Types declaration
*/
    /* Standard LEAREW types. */
    #include <stddef.h>

/*----------------------------------------------------------------------------
** Imports
*/
    /* Prototypes */
    #include "slp_api.h"

    /* Get the Microcontroller registers */
	#include "device_registers.h"
    #include "mcal_api.h"
    #include "mcal_init.h"
	#include "mcu.h"
	#include "IoHwAb.h"
	#include "interrupt_manager.h"
	#include "pins_driver.h"
	#include "bsw_init.h"
    /* Get the Sleep Interface */
	#include "slp_cfg.h"
	#include "CanNm_Cfg.h"
	#include "NmStack_Types.h"
	#include "tja1045a.h"
	#include "ComVnimMdl.h"
	#include "Appl_Cbk.h"
	/* Import: PORT */
	#include "pin_mux.h"

	/* Import: MCU */
	#include "clockMan1.h"
	#include "scg_hw_access.h"


    /* Import: spi */
	#include "lpspi_master_driver.h"
	#include "lpspiCom1.h"

	/* Import: spi */
	#include "adConv1.h"

	#include "cdd_init.h"
	#include "ComM.h"
	#include "Com.h"
	#include "ComM_EcuMBswM.h"
    #include "CanIf_Cfg.h"

/*----------------------------------------------------------------------------
** Define constants

*/
#define IGN_OFF 0x00u
#define VALID 0x01u
#define INVALID 0x00u
	
/*----------------------------------------------------------------------------
** Private functions declaration
*/

/*----------------------------------------------------------------------------
** Local data
*/
static uint8_t wakeupflag = 0;
static uint16_t counter=0;
/*----------------------------------------------------------------------------
** Functions implementation
*/
	static void CAN_NetworkOperation(void)
	{
		uint8_t SysPowerModVld;
		uint8_t SysPowerMod;

		/* get data from can  */
		Rte_Read_ComVnimMdl_Sig_PEPS2_SysPowerModVld_Value(&SysPowerModVld);
		if(SysPowerModVld == VALID)
		{

			Rte_Read_ComVnimMdl_Sig_PEPS2_SysPowerMod_Value(&SysPowerMod);
		}
		else
		{

		}

		if(SysPowerMod == IGN_OFF)
		{
			CanNm_NetworkRelease(0);
		}
		else
		{
			CanNm_NetworkRequest(0);
		}
	}
	
	


    /*----------------------------------------------------------------------------
    ** Description :
    **--------------------------------------------------------------------------*/
    void SLP_SleepMode_Prepare(void){

	}

    /*----------------------------------------------------------------------------
    ** Description :
    **--------------------------------------------------------------------------*/
    void SLP_SleepMode_Finish(void){

    }

    /*----------------------------------------------------------------------------
    ** Description :
    **--------------------------------------------------------------------------*/
    void SLP_SleepMode_MainTask(void){
		counter++;

		if(counter > 200)
		{
			//CAN_NetworkOperation();
			
			if(NM_STATE_BUS_SLEEP == CanNm_GetNmState(0))
			{
				PINS_DRV_ClearPortIntFlagCmd(PORTD);
	    		INT_SYS_EnableIRQ(PORTD_IRQn);
				Tja1445_sleep();
				LPSPI_DRV_MasterDeinit(0);
				IoHwAb_DioWritePin(IoHwAb_PMU_PWRON_PIN,IoHwAb_DIO_HIGH);
				IoHwAb_DioWritePin(IoHwAb_PMU_WAKEUP_PIN,IoHwAb_DIO_LOW);
				IoHwAb_DioWritePin(IoHwAb_5V_EN_MCU_PIN,IoHwAb_DIO_LOW);
				IoHwAb_DioWritePin(IoHwAb_MCU_STAT_PIN,IoHwAb_DIO_LOW);
				Mcu_SetMode(MCU_SLEEP_MODE);
			}
			else
			{
				
			}
			counter = 0;
		}
		if(wakeupflag == 1)
		{
			INT_SYS_DisableIRQ(PORTD_IRQn);
			/* Set MCU mode */
	    	Mcu_SetMode(MCU_NORMAL_MODE);
			PINS_DRV_Init(NUM_OF_CONFIGURED_PINS, g_pin_mux_InitConfigArr);
			LPSPI_DRV_MasterInit(LPSPICOM1,&lpspiCom1State,&lpspiCom1_MasterConfig0);

			LPSPI_DRV_MasterSetDelay(LPSPICOM1,1,1,1);
			ADC_DRV_ConfigConverter(INST_ADCONV1, &adConv1_ConvConfig0);
			ADC_DRV_AutoCalibration(INST_ADCONV1);
			IoHwAb_Init();
			Tja1445_init();
			//Bsw_Init();
			//Cdd_Init();
			wakeupflag = 0;
		}
		else
		{

		}
		
    }

	void PORTE_IRQHandler(void)
	{
		PINS_DRV_ClearPortIntFlagCmd(PORTE);
		wakeupflag = 1;
	}
	
	void CDD_ValidateWakeupEvent(uint32 WakeupSource)
	{
		static ComM_ModeType mode = COMM_NO_COMMUNICATION;
		ComM_GetCurrentComMode(ComMConf_ComMChannel_CN_C03_for_EL_CAN_V2_1_776d6b8e, &mode);

		if(mode == COMM_NO_COMMUNICATION)
		{
			ComM_EcuM_WakeUpIndication(0);
			ComM_CommunicationAllowed(ComMConf_ComMChannel_CN_C03_for_EL_CAN_V2_1_776d6b8e, TRUE);
			Com_IpduGroupStart(ComConf_ComIPduGroup_EIDC_oC03_for_EL_CAN_V2_1_Rx_0f13cc3b,FALSE);
			Com_IpduGroupStart(ComConf_ComIPduGroup_EIDC_oC03_for_EL_CAN_V2_1_Tx_59496bbd,FALSE);
			//CanIf_CtrlStates.raw[0].WakeUpValidationStateOfCtrlStates = 1;
		}
	}
