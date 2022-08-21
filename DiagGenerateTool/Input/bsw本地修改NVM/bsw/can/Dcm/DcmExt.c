//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2015] Visteon Corporation
// All Rights Reserved.
//
// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
// under all copyright laws to protect this work as a published work, when appropriate.
// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
// without the written authorization of Visteon Corporation.
//
//---------------------------------------------------------------------------------------------------------------------
                                                                                                                                                      /* PRQA S 0857, 0828 EOF */ /* MD_MSR_1.1_857, MD_MSR_1.1_828 */
#include "Dcm.h"
#include "Dcm_Types.h"
//#include "Gpt.h"
//#include "WdgM.h"
//#include "Dcm_Int.h"
//#include "Rte_DcmExt.h"
//#include "SchM_Dcm.h"
//#if (DCM_DEV_ERROR_DETECT == STD_ON)
//# include "Det.h"
//#endif /* (DCM_DEV_ERROR_DETECT == STD_ON) */
//#include "Mcu.h"
//#include <MemLib.h>
//#include <DmaDrv.h>
//#include <Adc.h>
//#include <Dio.h>
//#include "NvM.h"
//#include "NvM_Cfg.h"
//#include "CanCcl.h"
#include "Rte_DcmExt.h"
//#include "canEOL.h"
//#include "TmExt_Cfg.h"
//#include "TmExt_Timer.h"
#include "Dcm_Dsp.h"
#include "string.h"
#include "DcmExt.h"
#include "DcmExt_Generate.h"
#include "ComVnimMdl.h"

//=====================================================================================================================
//  MACRO
//=====================================================================================================================
#define DCM_DSP_DID_READ          	0x01
#define DCM_DSP_DID_WRITE         	0x02
#define DCM_DSP_DID_MANUFACTURE     0x03
#define DCM_DSP_DID_IO            	0x04  // lxiong2.used for 0x2F service

#define DCM_DSP_RID_START          	0x01
#define DCM_DSP_RID_STOP           	0x02
#define DCM_DSP_RID_RESULTS        	0x03


#define DCM_IO_RETCTRL2ECU        	0x00
#define DCM_IO_RST2DEF            	0x01
#define DCM_IO_FRZCURSTATE        	0x02
#define DCM_IO_SHRTTRMADJ         	0x03
#define SEED_AND_KEY_COCF1				(uint8)(0x1Eu)
#define SEED_AND_KEY_COCF2				(uint8)(0x60u)
#define SEC_KEY_LEN						4

/* NVM Related State Machine*/

#define DCM_NVM_IDLE				0
#define DCM_NVM_INIT 				1
#define DCM_NVM_PROCESS 			2
#define DCM_NVM_WAIT 				3
#define DCM_NVM_COMPLETE 			4


/***************************************************************************
** Routine Control Types
***************************************************************************/

#define ROUTINE_TYPE_1				(0x01u)
#define ROUTINE_TYPE_2				(0x02u)
#define RC_STOP_SERVICE				(0x04u)
#define RC_SELFTEST					(0x10u)
/***************************************************************************
** Bit definitions for the 'l_diag_status_U8' data store.
***************************************************************************/

#define SELFTEST_UDS                (BIT0)
#define ROUTINEBUSY                 (BIT1)
#define SELF_TEST_DR_RECVD_AGAIN    (BIT2)

/***************************************************************************
** Bit map definitions to be allocated in 'l_rtn_ctrl_flags_U8'
***************************************************************************/
#define RTN_CTRL_ABORT_ECU          (0x01u)
#define RTN_CTRL_START_RECEIVED     (0x04u)
#define RTN_CTRL_ABORT_TESTER       (0x02u)
#define RTN_CTRL_COMPLETED          (0x08u)
#define RTN_CTRL_ABORT_SESSION      (0x10u)

#define DATA_LEN_1_BYTE             ((DG_MGR_UINT8)0x01u)
#define DATA_LEN_2_BYTE             ((DG_MGR_UINT8)0x02u)
#define DATA_LEN_3_BYTE             ((DG_MGR_UINT8)0x03u)
#define DATA_LEN_4_BYTE             ((DG_MGR_UINT8)0x04u)
#define DATA_LEN_5_BYTE             ((DG_MGR_UINT8)0x05u)
#define DATA_LEN_6_BYTE             ((DG_MGR_UINT8)0x06u)
#define DATA_LEN_7_BYTE             ((DG_MGR_UINT8)0x07u)
#define DATA_LEN_8_BYTE             ((DG_MGR_UINT8)0x08u)
#define DATA_LEN_9_BYTE             ((DG_MGR_UINT8)0x09u)
#define DATA_LEN_10_BYTE             ((DG_MGR_UINT8)0x0Au)
#define DATA_LEN_11_BYTE             ((DG_MGR_UINT8)0x0Bu)
#define DATA_LEN_12_BYTE             ((DG_MGR_UINT8)0x0Cu)
#define DATA_LEN_13_BYTE             ((DG_MGR_UINT8)0x0Du)
#define DATA_LEN_14_BYTE             ((DG_MGR_UINT8)0x0Eu)
#define DATA_LEN_15_BYTE             ((DG_MGR_UINT8)0x0Fu)
#define DATA_LEN_16_BYTE             ((DG_MGR_UINT8)0x10u)
#define DATA_LEN_17_BYTE             ((DG_MGR_UINT8)0x11u)
#define DATA_LEN_18_BYTE             ((DG_MGR_UINT8)0x12u)
#define DATA_LEN_19_BYTE             ((DG_MGR_UINT8)0x13u)
#define DATA_LEN_20_BYTE             ((DG_MGR_UINT8)0x14u)
#define DATA_LEN_32_BYTE			((DG_MGR_UINT8)0x20u)

#define TESTBIT( operand, bit_mask )        (((operand) &  (bit_mask)) != ((bit_mask) - (bit_mask)))
#define SETBIT( operand, bit_mask )         ((operand) |= (bit_mask))
#define CLEARBIT( operand, bit_mask )       ((operand) &= ((uint32)~(bit_mask)))
/***************************************************************************
** Negative Response Code **
***************************************************************************/
#define kwp2k_diag_NrcGeneralReject                                     0x10
#define kwp2k_diag_NrcServiceNotSupported                               0x11
#define kwp2k_diag_NrcSubfunctionNotSupported                           0x12
#define kwp2k_diag_NrcInvalidFormat                                     0x13
#define kwp2k_diag_NrcBusyRepeatRequest                                 0x21
#define kwp2k_diag_NrcConditionsNotCorrect                              0x22
#define kwp2k_diag_NrcRoutineNotCompleted                               0x23
#define kwp2k_diag_NrcRequestSequenceError                              0x24
#define kwp2k_diag_NrcRequestOutOfRange                                 0x31
#define kwp2k_diag_NrcSecaccess_denied                   				0x33
#define kwp2k_diag_NrcGeneralProgrammingFailure                         0x72
#define kwp2k_diag_NrcResponsePending                                   0x78
#define kwp2k_diag_NrcSubfunctionNotSupportedInActiveSession            0x7E
#define kwp2k_diag_NrcServiceNotSupportedInActiveSession                0x7F
#define NO_ERROR                    									0x00

#define ST_ROUTINE_NEVER_EXCECUTE 										0x00
#define ST_ROUTINE_DURING_EXCECUTION 									0x00
#define ON_DEMAND_SELF_TEST 											0x00

/***************************************************************************
** Service id support **
***************************************************************************/
#define SID_31_SUPPORTED
#define MODE_22_SUPPORTED
#define MODE_2E_SUPPORTED
#define MODE_2F_SUPPORTED

#define NO_SPACE_AVAILABLE              								(0xFF)
#define LHVSD_CHECK_NEEDED              								(0xFF)
#define LHVSD_CHECK_NOT_NEEDED          								(0x00)

#ifdef SID_31_SUPPORTED
#define DR_TIME_NOT_REQ                     							((uint32)0)

#define PROD_SPEC_DENY_ROUTINE_EXECUTE_LIST         \

#define APP_MARKER_PATTERN_SIZE         4u
#define APP_MARKER_PATTERN_BEGIN        {0xAAu, 0x55u, 0xAAu, 0x55u}
#define APP_MARKER_PATTERN_END          {0x55u, 0xAAu, 0x55u, 0xAAu}

uint8 FblApp_IsValidApp(void);

#endif

//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================

//=====================================================================================================================
//  FORWARD DECLARATIONS
//=====================================================================================================================

//=====================================================================================================================
//  PRIVATE
//=====================================================================================================================
static uint32 SecurityLevel1_SeedSend;
static uint32 SecurityLevel2_SeedSend;
static uint32 SecurityLevelEOL_SeedSend;

static uint8 Dcm_NvMDefaultWriteState;
static uint8 Dcm_nvm_BlockWrite_State;

//static uint8 *bufPtr;
static uint8 NVM_Write_Success_flag;

static uint16 NvM_BlockNumber;
static boolean Dcm_NvMError;

static DG_MGR_UINT8  l_diag_status_U8;
static DG_MGR_UINT16 l_routine_number;
static DG_MGR_UINT8  l_rtn_ctrl_flags_U8;
static DG_MGR_UINT32 l_routine_tmr_cnt_U32;

static const uint32 timeout_5s = 5000;

static const HTimer CrankTimerID = eCrankTimer_5s;

static uint8 VECONFIG_ENGINE_RUNNING_STATUS;
static boolean dem_out_crank_flag;
extern boolean DCM_ENABLE_RX_TX_NORM_NM_flag;

static boolean service_2E_write_DID_flag;

/******************************************************************************************
** The 'diag_routine_ctrl_table_rom' list contain supported Routine ID's and corresponding
** function to be invoked to execute the routine task
*******************************************************************************************/

static DG_MGR_BOOLEAN (*const deny_routine_entry_list_rom[])(void) =
{
  	PROD_SPEC_DENY_ROUTINE_EXECUTE_LIST
  	NULL_PTR
};


/*
static const  Eol_Nvm_Block_RECORD nvm_block_table_rom[] =
{
	{0xF195,NvMConf_NvMBlockDescriptor_Cluster_SoftwareVersion			,2	,(Std_ReturnType (*)(uint8 *))Rte_Write_NV_Cluster_SoftwareVersion_SoftwareVersion 					 ,(Std_ReturnType (*)(uint8 *))//Rte_Read_NV_Cluster_SoftwareVersion_SoftwareVersion				   },		 	 		 ,(Std_ReturnType (*)(uint8 *))//Rte_Read_NV_ECUCfgFlag_Element							 },
	{0,0,0,NULL_PTR}
};
*/


#define CrankTimerStart() TmExt_Timer_Start(CrankTimerID)
#define CrankTimerStop() TmExt_Timer_Stop(CrankTimerID)

//=====================================================================================================================
//  PUBLIC
//=====================================================================================================================
uint8 flTimer;
//extern boolean dem_out_crank_5s;
boolean dem_out_crank_5s;

//=====================================================================================================================
//  PRIVATE FUNCTION
//=====================================================================================================================
static void Dcm_NvMCalibrationStateProcess(void);
static void Dcm_NvMDefaultWriteStateProcess(void);
static Std_ReturnType DI_Did_Diag_Read(Dcm_DspDidIdentifierTableType  Did,Dcm_MsgType Buff,Dcm_MsgLenType* Length);
static Std_ReturnType DI_Did_Diag_Write(Dcm_DspDidIdentifierTableType  Did,Dcm_MsgType Buff,Dcm_MsgLenType* Length);
static Std_ReturnType DI_Did_Diag_IO(Dcm_DspDidIdentifierTableType  Did,Dcm_MsgType Buff,Dcm_MsgLenType* Length);
static Std_ReturnType Sec_VerifyKey(const uint32 seed, const uint8 *pKeyBuffer, uint32 *len);
static void Sec_GenerateKey (uint32 seed, uint32 *Seed_Key);

/**********************************************************************************************************************
 *
 * Function Name  : uds_check_valid_routine_id
 * Description    : This function checks Routine Id supplied is supported by ECU
 * Invocation     : Local
 * Parameters     : None
 * Returns        : NULL_PTR - If RoutineId is not supported
 *                : Address  - If RoutineId is supported by ecu
 *
************************************************************************************************************************/
static RTN_CTRL_RECORD  *uds_check_valid_routine_id(DG_MGR_UINT16 RoutineId);
/**********************************************************************************************************************
 *
 * Function Name  : uds_start_routine_control
 * Description    : This function start requested routine control
 *                  Supports Both Routine Type 2 and Routine Type 1.
 * Invocation     : Local
 * Parameters[in] : RoutineId   - Routine control ID
 *                  p_reclen_U8 - length of option record
 * Returns        : None
 *
************************************************************************************************************************/
static DG_MGR_UINT8 uds_start_routine_control(DG_MGR_UINT8 p_msgdat_U8A[],				\
													Dcm_DspRidIdentifierTableType Rid,		\
													RTN_CTRL_RECORD *p_routine_ptr,			\
													DG_MGR_UINT16 *p_res_data_len_ptr);		\
/**********************************************************************************************************************
 *
 * Function Name  : uds_stop_routine_control
 * Description    : This function stops requested ongoing routine control
 * Invocation     : Local
 * Parameters[in] : RoutineId - Routine control ID
 * Returns        : None
 *
************************************************************************************************************************/
static DG_MGR_UINT8 uds_stop_routine_control(DG_MGR_UINT8 p_msgdat_U8A[],				\
												   Dcm_DspRidIdentifierTableType Rid,		\
												   RTN_CTRL_RECORD *p_routine_ptr);			\
/**********************************************************************************************************************
 *
 * Function Name  : uds_request_routine_result
 * Description    : This function returns result of routine control
 * Invocation     : Local
 * Parameters[in] : RoutineId - Routine control ID
 * Returns        : None
 *
************************************************************************************************************************/
static DG_MGR_UINT8 uds_request_routine_result(DG_MGR_UINT8 p_msgdat_U8A[],			\
													 RTN_CTRL_RECORD *p_routine_ptr,		\
													 DG_MGR_UINT16 *p_res_data_len_ptr);	\

/**********************************************************************************************************************
 *
 * Function Name  : DiagTravBoolVoidLst
 * Description    : This function traverses and calls a list of NULL_PTR terminated
 *                  boolean/void functions (functions which take no parameters and
 *                  return a boolean value).
 * Invocation     : Local
 * Parameters     : list_ptr - pointer to the beginning of the function list.
 * Returns        : FALSE    - if all function listed returns false
 *                  TRUE     - if any one function listed returns true
 *
************************************************************************************************************************/
static DG_MGR_BOOLEAN DiagTravBoolVoidLst(DG_MGR_BOOLEAN (*const (*list_ptr))(void));
/**********************************************************************************************************************
 *
 * Function Name  : uds_diagnostic_rtnctrl_periodic_task
 * Description    : This function is called periodically to check abort condition
 *                  of Routine. If no abort, checks for completion of Routine
 * Invocation     : Local
 * Parameters     : None
 * Returns        : None
 *
************************************************************************************************************************/
static void uds_diagnostic_rtnctrl_periodic_task(void);
/**********************************************************************************************************************
 *
 * Function Name  :
 * Description    :
 *
 * Invocation     :
 * Parameters[in] :
 *
 * Returns        :
 *
************************************************************************************************************************/
void DcmExt_Init(void)
{
	flTimer = 0x00;
	Dcm_NvMDefaultWriteState = DCM_NVM_IDLE;
	Dcm_nvm_BlockWrite_State = DCM_NVM_IDLE;
	NVM_Write_Success_flag = FALSE;
	Dcm_NvMError = FALSE;
  	dem_out_crank_5s = FALSE;
  	dem_out_crank_flag = FALSE;
  	service_2E_write_DID_flag = FALSE;

}

/**********************************************************************************************************************
 *
 * Function Name  :
 * Description    :
 *
 * Invocation     :
 * Parameters[in] :
 *
 * Returns        :
 *
************************************************************************************************************************/
static void Dcm_NvMCalibrationStateProcess(void)
{
    // uint8 WriteStatus;
	// WriteStatus = NVM_REQ_NOT_OK;

    // if((Dcm_nvm_BlockWrite_State == DCM_NVM_IDLE) && (service_2E_write_DID_flag == TRUE))
    // {
    // 	service_2E_write_DID_flag = FALSE;
    // 	//Dcm_2E_Service_ExternalProcessingDone(); //lxiong2 add this function
    // }
    // if(Dcm_nvm_BlockWrite_State == DCM_NVM_INIT)
    // {
    //     Dcm_nvm_BlockWrite_State = DCM_NVM_PROCESS;
    // }
    // if( Dcm_nvm_BlockWrite_State == DCM_NVM_WAIT)
    // {
    //     (void)NvM_GetErrorStatus(NvM_BlockNumber, &WriteStatus);
    //     if(NVM_REQ_PENDING != WriteStatus)
    //     {
    //         if(WriteStatus != NVM_REQ_OK)
    //         {
    //          //   Dcm_NvMError = TRUE;       //lxiong2 changge this for BAIC defect
    //         }
    //         Dcm_nvm_BlockWrite_State = DCM_NVM_COMPLETE;
    //     }
    // }
    // if(Dcm_nvm_BlockWrite_State == DCM_NVM_PROCESS)
    // {
    //     (void)NvM_GetErrorStatus(NvM_BlockNumber, &WriteStatus);
    //     if(NVM_REQ_PENDING != WriteStatus)
    //     {
    //     	if(NVM_Write_Success_flag == TRUE)
    //         {
    //         	//NVM_Write_Success_flag = FALSE;
    //         	Dcm_nvm_BlockWrite_State = DCM_NVM_WAIT;
	// 			service_2E_write_DID_flag = TRUE;
    //         }
    //         else
    //         {
    //         //    Dcm_NvMError = TRUE;	//lxiong2 changge this for BAIC defect
    //             Dcm_nvm_BlockWrite_State = DCM_NVM_COMPLETE;
    //         }
    //     }
    // }
    // if(Dcm_nvm_BlockWrite_State == DCM_NVM_COMPLETE)
    // {
    //     Dcm_nvm_BlockWrite_State = DCM_NVM_IDLE;
    //     if(FALSE != Dcm_NvMError)
    //     {
    //         Dcm_NvMError = FALSE;
    //         Dcm_ExternalSetNegResponse(0x72);
    //         Dcm_ExternalProcessingDone();
    //     }
    //     else
    //     {
    //         Dcm_ExternalProcessingDone();
    //     }
    // }
}
/**********************************************************************************************************************
 *
 * Function Name  :
 * Description    :
 *
 * Invocation     :
 * Parameters[in] :
 *
 * Returns        :
 *
************************************************************************************************************************/
static void Dcm_NvMDefaultWriteStateProcess(void)
{
	/* do nothing */
}
/**********************************************************************************************************************
 *
 * Function Name  :
 * Description    :
 *
 * Invocation     :
 * Parameters[in] :
 *
 * Returns        :
 *
************************************************************************************************************************/
void DcmExt_Main(void)
{
    Dcm_NvMDefaultWriteStateProcess();
    Dcm_NvMCalibrationStateProcess();
    if(FALSE != TESTBIT(l_diag_status_U8, ROUTINEBUSY))
    {
        uds_diagnostic_rtnctrl_periodic_task();
    }
}

void CDcmExt_GetCurrentSessionType(SessionId *session)
{
	uint8 fl_session;
	Dcm_GetSesCtrlType(&fl_session);
	*session = (SessionId)fl_session;
}

/**********************************************************************************************************************
 *
 * Function Name  :
 * Description    :
 *
 * Invocation     :
 * Parameters[in] :
 *
 * Returns        :
 *
************************************************************************************************************************/
Std_ReturnType DI_Did_Diag_Action(uint8 Did_action
											  ,Dcm_DspDidIdentifierTableType  Did
											  ,Dcm_MsgType Buff
											  ,Dcm_MsgLenType* Length
											  )
{
	Std_ReturnType RetVal;
	RetVal = DCM_E_OK;

	if (DCM_DSP_DID_READ == Did_action)
	{
		RetVal = DI_Did_Diag_Read(Did, Buff, Length);
	}
	else if(DCM_DSP_DID_WRITE == Did_action)
	{
		RetVal = DI_Did_Diag_Write(Did, Buff, Length);
	}
	else if(DCM_DSP_DID_IO == Did_action) // lxiong2.used for 0x2F service
	{
		RetVal = DI_Did_Diag_IO(Did, Buff, Length);
	}
	else
	{
		/*do nothing*/
	}
	return RetVal;

}
/**********************************************************************************************************************
 *
 * Function Name  :
 * Description    :
 *
 * Invocation     :
 * Parameters[in] :
 *
 * Returns        :
 *
************************************************************************************************************************/
void Dcm_WdgM_PerformReset(void)
{
	//(void)WdgM_PerformReset();

	/* Qiuhuaqing Modify,  To be Release after EcuM Finished */
	//Mcu_PerformReset();
	//while(1);
}

void Dcm_WdgM_PerformHardReset(void)
{
	//(void)WdgM_PerformReset();
	//Mcu_PerformReset();
	while(1);
}
/**********************************************************************************************************************
 *
 * Function Name  :
 * Description    :
 *
 * Invocation     :
 * Parameters[in] :
 *
 * Returns        :
 *
************************************************************************************************************************/
#ifdef SID_31_SUPPORTED
extern Std_ReturnType DI_Rid_Diag_Action(uint8 Rid_action ,Dcm_DspRidIdentifierTableType Rid,Dcm_MsgType Buff ,Dcm_MsgLenType*Length)
{
	DG_MGR_UINT8 fl_errval_U8 = NO_ERROR;
	RTN_CTRL_RECORD  *fl_routine_ptr;

	fl_routine_ptr     = uds_check_valid_routine_id(Rid);
	switch(Rid_action)
	{
		case DCM_DSP_RID_START:
		{
			fl_errval_U8 = uds_start_routine_control(&Buff[0],Rid,fl_routine_ptr,(DG_MGR_UINT16 *)Length);
			if(fl_errval_U8 == NO_ERROR)
			{
				Dcm_ExternalProcessingDone();
			}
			else
			{
				Dcm_ExternalSetNegResponse(fl_errval_U8);
				Dcm_ExternalProcessingDone();
			}
		}break;
		case DCM_DSP_RID_STOP:
		{
			fl_errval_U8 = uds_stop_routine_control(&Buff[0],Rid,fl_routine_ptr);
			if(fl_errval_U8 == NO_ERROR)
			{
				Dcm_ExternalProcessingDone();
			}
			else
			{
				Dcm_ExternalSetNegResponse(fl_errval_U8);
				Dcm_ExternalProcessingDone();
			}
		}break;
		case DCM_DSP_RID_RESULTS:
		{
			fl_errval_U8 = uds_request_routine_result(&Buff[0],fl_routine_ptr, (DG_MGR_UINT16 *)Length);
			if(fl_errval_U8 == NO_ERROR)
			{
				Dcm_ExternalProcessingDone();
			}
			else if(fl_errval_U8 == kwp2k_diag_NrcBusyRepeatRequest)
			{
				Dcm_ExternalSetNegResponse(kwp2k_diag_NrcBusyRepeatRequest);
				Dcm_ExternalProcessingDone();
			}
		}break;
		default:
		{
			/*do nothing */
		}break;
	}
	return DCM_E_OK;

}
/**********************************************************************************************************************
 *
 * Function Name  : uds_start_routine_control
 * Description    : This function start requested routine control
 *                  Supports Both Routine Type 2 and Routine Type 1.
 * Invocation     : Local
 * Parameters[in] : RoutineId   - Routine control ID
 *                  p_reclen_U8 - length of option record
 * Returns        : None
 *
************************************************************************************************************************/
static DG_MGR_UINT8 uds_start_routine_control(DG_MGR_UINT8 p_msgdat_U8A[],			\
											  Dcm_DspRidIdentifierTableType Rid,	\
											  RTN_CTRL_RECORD *p_routine_ptr,		\
											  DG_MGR_UINT16 *p_res_data_len_ptr)	\
{
    uint16 RoutineId;
    DG_MGR_UINT8  fl_errval_U8;
    /*UINT8  fl_record_status_U8;*/
    DG_MGR_UINT8  fl_rtn_status_U8;
    DG_MGR_UINT8  fl_diag_status_U8;

    RoutineId 			= Rid;
    fl_diag_status_U8   = 0;

    l_routine_number      = 0;
    l_rtn_ctrl_flags_U8   = 0;
    l_routine_tmr_cnt_U32 = 0;

    /*
    ** Check what type of routine service to be used. If Routine Type 2 service to be used
    ** check is it a selftest request
    */
    if(FALSE != TESTBIT(p_routine_ptr->routine_type, ROUTINE_TYPE_2))
    {
        SETBIT(fl_diag_status_U8, ROUTINEBUSY);
        fl_rtn_status_U8     = RTN_CTRL_START_RECEIVED;

        if(FALSE != TESTBIT(p_routine_ptr->routine_type, RC_SELFTEST))
        {
            SETBIT(fl_diag_status_U8, SELFTEST_UDS);

            #ifdef PROD_SPEC_SD_NEW_DIAG_CMD_EXIT_REQ
                if(FALSE != TESTBIT(l_diag_status_U8, (SELFTEST_UDS | ROUTINEBUSY)))
                {
                    udscore_set_new_diag_cmd_recvd();
                }
            #endif

        }
    }
    else
    {
        fl_rtn_status_U8     = RTN_CTRL_START_RECEIVED | RTN_CTRL_COMPLETED;
    }

    /*
    ** Control option record is passed to application to use it. application has to validate
    ** the record and return its status
    */
    if(NULL_PTR != p_routine_ptr->start_routine_func)
    {
         fl_errval_U8 = p_routine_ptr->start_routine_func(&p_msgdat_U8A[0],p_res_data_len_ptr);
    }
	else
    {
    }

    //*p_res_data_len_ptr += (DG_MGR_UINT16)DATA_LEN_1_BYTE;
    if(fl_errval_U8 == NO_ERROR)
    {

        if(FALSE != TESTBIT(l_diag_status_U8, (SELFTEST_UDS | ROUTINEBUSY)))
        {
            SETBIT(fl_diag_status_U8, SELF_TEST_DR_RECVD_AGAIN);
        }

        l_diag_status_U8    |= fl_diag_status_U8;
        l_routine_number     = RoutineId;
        l_rtn_ctrl_flags_U8  = fl_rtn_status_U8;

    }
	return(fl_errval_U8);

}
/**********************************************************************************************************************
 *
 * Function Name  : uds_stop_routine_control
 * Description    : This function stops requested ongoing routine control
 * Invocation     : Local
 * Parameters[in] : RoutineId - Routine control ID
 * Returns        : None
 *
************************************************************************************************************************/
static DG_MGR_UINT8 uds_stop_routine_control(DG_MGR_UINT8 p_msgdat_U8A[],			\
												    Dcm_DspRidIdentifierTableType Rid,	\
												    RTN_CTRL_RECORD *p_routine_ptr)		\
{

	//DG_MGR_UINT16 RoutineId;
	DG_MGR_UINT8  fl_errval_U8 = NO_ERROR;

    //RoutineId      = Rid;

    /*
    ** Check whether Routine Stop service is supported
    */
    if(FALSE == TESTBIT(p_routine_ptr->routine_type, RC_STOP_SERVICE ))
    {
        fl_errval_U8 = kwp2k_diag_NrcSubfunctionNotSupported;
    }
	/*
    else if((FALSE == TESTBIT(l_rtn_ctrl_flags_U8, RTN_CTRL_START_RECEIVED))
    ||      (FALSE != TESTBIT(l_rtn_ctrl_flags_U8, RTN_CTRL_COMPLETED     )))
    {
        fl_errval_U8 = kwp2k_diag_NrcRequestSequenceError;
    }
    else if(RoutineId != l_routine_number)
    {
        fl_errval_U8 = kwp2k_diag_NrcRequestOutOfRange;
    }
	*/
    else
    {

        /*
		if(NULL_PTR != p_routine_ptr->terminate_routine_func)
	    {
	         fl_errval_U8 = p_routine_ptr->terminate_routine_func(&p_msgdat_U8A[0],p_res_data_len_ptr);
	    }
		else
	    {
	    }
        */

		if(NULL_PTR != p_routine_ptr->terminate_routine_func)
        {
            p_routine_ptr->terminate_routine_func();
        }

        if(FALSE != TESTBIT(p_routine_ptr->routine_type, RC_SELFTEST))
        {
            p_msgdat_U8A[0] = ST_ROUTINE_NEVER_EXCECUTE;
            p_msgdat_U8A[1] = 0x00;
        }


        SETBIT(l_rtn_ctrl_flags_U8, RTN_CTRL_ABORT_TESTER);
    }

	return(fl_errval_U8);

}
/**********************************************************************************************************************
 *
 * Function Name  : uds_request_routine_result
 * Description    : This function returns result of routine control
 * Invocation     : Local
 * Parameters[in] : RoutineId - Routine control ID
 * Returns        : None
 *
************************************************************************************************************************/
static DG_MGR_UINT8 uds_request_routine_result(DG_MGR_UINT8 p_msgdat_U8A[],		\
											         RTN_CTRL_RECORD *p_routine_ptr,	\
											         DG_MGR_UINT16 *p_res_data_len_ptr) \
{

	DG_MGR_UINT8  fl_errval_U8 = NO_ERROR;

    if( (FALSE == TESTBIT(p_routine_ptr->routine_type, RC_SELFTEST)) && \
        (FALSE == TESTBIT(l_rtn_ctrl_flags_U8, (RTN_CTRL_START_RECEIVED |
                             RTN_CTRL_ABORT_ECU | RTN_CTRL_ABORT_TESTER))) )
    {
        fl_errval_U8 = kwp2k_diag_NrcRequestSequenceError;
    }
    else if( (FALSE == TESTBIT(p_routine_ptr->routine_type, RC_SELFTEST)) && \
             (FALSE != TESTBIT(l_diag_status_U8, ROUTINEBUSY)) )
    {
        /*
        ** If New Routine Result request is received, while routine is still in progress
        ** Return Busy response.
        */
        fl_errval_U8 = kwp2k_diag_NrcBusyRepeatRequest;
    }
    else if(FALSE != TESTBIT(p_routine_ptr->routine_type, RC_SELFTEST))
    {
        if(FALSE != TESTBIT(l_diag_status_U8, ROUTINEBUSY))
        {
            p_msgdat_U8A[0] = ST_ROUTINE_DURING_EXCECUTION;
        }
        else
        {
            p_msgdat_U8A[0] = ST_ROUTINE_NEVER_EXCECUTE;
        }
        p_msgdat_U8A[1] = 0x00;
        *p_res_data_len_ptr = DATA_LEN_5_BYTE;
    }
    else
    {
        if(NULL_PTR != p_routine_ptr->results_routine_func)
        {
            fl_errval_U8 = p_routine_ptr->results_routine_func(&p_msgdat_U8A[0], p_res_data_len_ptr);
        }
        //*p_res_data_len_ptr = DATA_LEN_2_BYTE;
    }

	return(fl_errval_U8);

}
/**********************************************************************************************************************
 *
 * Function Name  : uds_check_valid_routine_id
 * Description    : This function checks Routine Id supplied is supported by ECU
 * Invocation     : Local
 * Parameters     : None
 * Returns        : NULL_PTR - If RoutineId is not supported
 *                : Address  - If RoutineId is supported by ecu
 *
************************************************************************************************************************/
static RTN_CTRL_RECORD  *uds_check_valid_routine_id(DG_MGR_UINT16 RoutineId)
{
	RTN_CTRL_RECORD  *fl_rec_ptr;
	RTN_CTRL_RECORD  *fl_ret_ptr;

	fl_rec_ptr = diag_routine_ctrl_table_rom;
	fl_ret_ptr = NULL_PTR;

	while (fl_rec_ptr->routine_id != 0)
	{
		if(fl_rec_ptr->routine_id == RoutineId)
		{
			fl_ret_ptr = fl_rec_ptr;
			break;
		}
		fl_rec_ptr++;
	}

	return(fl_ret_ptr);
}

/********************************************************************************
 *
 * Function Name  : uds_diagnostic_rtnctrl_periodic_task
 * Description    : This function is called periodically to check abort condition
 *                  of Routine. If no abort, checks for completion of Routine
 * Invocation     : Local
 * Parameters     : None
 * Returns        : None
 *
********************************************************************************/
static void uds_diagnostic_rtnctrl_periodic_task(void)
{
	RTN_CTRL_RECORD  *fl_routine_ptr;

#ifdef PROD_SPEC_SD_NEW_DIAG_CMD_EXIT_REQ

	boolean  		  fl_sess_abort_BOOL;

#endif

	boolean  		  fl_abort_stat_BOOL;

	fl_routine_ptr     = uds_check_valid_routine_id(l_routine_number);

	if(NULL_PTR != fl_routine_ptr)
	{
		/*
		** Abort Routine, if satisfies abort condition or session change happens
		*/
		fl_abort_stat_BOOL = DiagTravBoolVoidLst(deny_routine_entry_list_rom);

        #ifdef PROD_SPEC_SD_NEW_DIAG_CMD_EXIT_REQ

			fl_sess_abort_BOOL = TESTBIT(l_rtn_ctrl_flags_U8, RTN_CTRL_ABORT_SESSION);

        #endif

		if( ((FALSE != fl_abort_stat_BOOL ) \

            #ifdef PROD_SPEC_SD_NEW_DIAG_CMD_EXIT_REQ

				|| (FALSE != fl_sess_abort_BOOL) \

            #endif

			) && (NULL != fl_routine_ptr->terminate_routine_func) )
		{
			fl_routine_ptr->terminate_routine_func();
			CLEARBIT(l_diag_status_U8 , SELFTEST_UDS|ROUTINEBUSY);
			SETBIT(l_rtn_ctrl_flags_U8, (RTN_CTRL_ABORT_ECU | RTN_CTRL_COMPLETED) );
		}
		else
		{
			if( ((DG_MGR_UINT32)0 != fl_routine_ptr->routine_time) && \
				(l_routine_tmr_cnt_U32 >= fl_routine_ptr->routine_time) )
			{
				fl_routine_ptr->terminate_routine_func();
			}

			/*
			** Check Routine is Active. If no routine function is active, store status and
			** recover to normal.
			*/
			if(NULL != fl_routine_ptr->status_routine_func)
			{
				if(FALSE != fl_routine_ptr->status_routine_func())
				{
				    l_routine_number = 0x0000;
				    CLEARBIT(l_diag_status_U8 , (SELFTEST_UDS|ROUTINEBUSY));
					SETBIT(l_rtn_ctrl_flags_U8, RTN_CTRL_COMPLETED);

					if(FALSE != TESTBIT(l_diag_status_U8, SELF_TEST_DR_RECVD_AGAIN))
					{
					    l_routine_number = ON_DEMAND_SELF_TEST;
					    CLEARBIT(l_diag_status_U8, SELF_TEST_DR_RECVD_AGAIN);
					    CLEARBIT(l_rtn_ctrl_flags_U8, RTN_CTRL_COMPLETED);
					    SETBIT(l_diag_status_U8 , (SELFTEST_UDS|ROUTINEBUSY));
					    /*ApplDiag_ReStart_OnDemand_Self_Test();*/
					}
				}
			}
		}
	}
}
/********************************************************************************
 *
 * Function Name  : DiagTravBoolVoidLst
 * Description    : This function traverses and calls a list of NULL_PTR terminated
 *                  boolean/void functions (functions which take no parameters and
 *                  return a boolean value).
 * Invocation     : Local
 * Parameters     : list_ptr - pointer to the beginning of the function list.
 * Returns        : FALSE    - if all function listed returns false
 *                  TRUE     - if any one function listed returns true
 *
********************************************************************************/
static DG_MGR_BOOLEAN DiagTravBoolVoidLst(DG_MGR_BOOLEAN (*const (*list_ptr))(void))
{
	DG_MGR_UINT8 fl_ret_U8 = 0;

    /*
    ** Check for RAM error.
    */
    if(NULL_PTR == list_ptr)
    {
        //KernelReportError(RAM_ERROR);
    }
    else
    {
        while((NULL_PTR != *list_ptr) && (0 == fl_ret_U8))
        {
            if(FALSE != ((**list_ptr)()))
            {
                fl_ret_U8 = 1;
                break;
            }
            ++list_ptr;
        }
    }
    return (fl_ret_U8);
}
#endif
/**********************************************************************************************************************
 *
 * Function Name  :
 * Description    :
 *
 * Invocation     :
 * Parameters[in] :
 *
 * Returns        :
 *
************************************************************************************************************************/
Std_ReturnType SecLevel1GetSeed(Dcm_MsgType Buff
	,Dcm_MsgLenType* Length)
{
	/* Qiuhuaqing Modify,  To be Release after Timer Finished */
	//SecurityLevel1_SeedSend = (uint32)Gpt_GetTimeElapsed(GptConf_GptChannelConfiguration_GptChCfg_60MHzFRT);
	SecurityLevel1_SeedSend = 0x11223344;
	Buff[0] = (uint8)(SecurityLevel1_SeedSend >> 24);
	Buff[1] = (uint8)(SecurityLevel1_SeedSend >> 16);
	Buff[2] = (uint8)(SecurityLevel1_SeedSend >> 8);
	Buff[3] = (uint8)(SecurityLevel1_SeedSend);
	*Length = 4;
	return DCM_E_OK;
}
/**********************************************************************************************************************
 *
 * Function Name  :
 * Description    :
 *
 * Invocation     :
 * Parameters[in] :
 *
 * Returns        :
 *
************************************************************************************************************************/
Std_ReturnType SecLevel2GetSeed(Dcm_MsgType Buff
	,Dcm_MsgLenType* Length)
{
	/* Qiuhuaqing Modify,  To be Release after Timer Finished */
	//SecurityLevel2_SeedSend = (uint32)Gpt_GetTimeElapsed(GptConf_GptChannelConfiguration_GptChCfg_60MHzFRT);
	SecurityLevel1_SeedSend = 0x11223344;
	Buff[0] = (uint8)(SecurityLevel2_SeedSend >> 24);
	Buff[1] = (uint8)(SecurityLevel2_SeedSend >> 16);
	Buff[2] = (uint8)(SecurityLevel2_SeedSend >> 8);
	Buff[3] = (uint8)(SecurityLevel2_SeedSend);
	*Length = 4;
	return DCM_E_OK;
}
/**********************************************************************************************************************
 *
 * Function Name  :
 * Description    :
 *
 * Invocation     :
 * Parameters[in] :
 *
 * Returns        :
 *
************************************************************************************************************************/
Std_ReturnType SecLevelEOLGetSeed(Dcm_MsgType Buff,Dcm_MsgLenType* Length)
{
	/* Qiuhuaqing Modify,  To be Release after Timer Finished */
	//SecurityLevelEOL_SeedSend = (uint32)Gpt_GetTimeElapsed(GptConf_GptChannelConfiguration_GptChCfg_60MHzFRT);
	SecurityLevel1_SeedSend = 0x11223344;
	Buff[0] = (uint8)(SecurityLevelEOL_SeedSend >> 24);
	Buff[1] = (uint8)(SecurityLevelEOL_SeedSend >> 16);
	Buff[2] = (uint8)(SecurityLevelEOL_SeedSend >> 8);
	Buff[3] = (uint8)(SecurityLevelEOL_SeedSend);
	*Length = 4;
	return DCM_E_OK;
}
/**********************************************************************************************************************
 *
 * Function Name  :
 * Description    :
 *
 * Invocation     :
 * Parameters[in] :
 *
 * Returns        :
 *
************************************************************************************************************************/
Std_ReturnType SecLevel1CmpKey(Dcm_MsgType Buff
	,Dcm_MsgLenType* Length)
{
	Std_ReturnType ret_val;
	ret_val =  Sec_VerifyKey(SecurityLevel1_SeedSend, Buff, Length);
	SecurityLevel1_SeedSend = 0;
	return ret_val;
}
/**********************************************************************************************************************
 *
 * Function Name  :
 * Description    :
 *
 * Invocation     :
 * Parameters[in] :
 *
 * Returns        :
 *
************************************************************************************************************************/
Std_ReturnType SecLevel2CmpKey(Dcm_MsgType Buff
	,Dcm_MsgLenType* Length)
{
	Std_ReturnType ret_val;
	ret_val =  Sec_VerifyKey(SecurityLevel2_SeedSend, Buff, Length);
	SecurityLevel2_SeedSend = 0;
	return ret_val;
}

/*============================================================================
 ** Function Name:	  Sec_VerifyKey
 **
 ** Visibility: 	  Public
 **
 ** Description:	  This function used to verify the security key sent by
 ** 				  the tester
 **
 ** Invocation: 	  Invoked by FBL
 **
 ** Inputs			  UINT8 *pKeyBuffer - Buffer that contains the key
 ** 				  UINT32 len - Length of the buffer
 **
 **
 ** Return: 		  Std_ReturnType
 ** 				  DCM_E_OK				- Success
 ** 				  DCM_E_NOT_OK			- Failed
 **
 ** Critical Section: None.
 **==========================================================================*/
static Std_ReturnType Sec_VerifyKey(const uint32 seed, const uint8 *pKeyBuffer, uint32 *Length)
{
	Std_ReturnType  status = DCM_E_NOT_OK;
	Dcm_SesCtrlType fl_Session;
	uint32 fl_key_Receive_u32 = 0;
	uint32 fl_Key_Generate_u32 = 0;

	fl_key_Receive_u32 = (pKeyBuffer[0] << 24) | (pKeyBuffer[1] << 16) | (pKeyBuffer[2] << 8) | pKeyBuffer[3];

	uint32 Eol_Seed_H = ((seed >> 16) & 0x0000FFFF);
	uint32 Eol_Seed_L = (seed & 0x0000FFFF);
	uint32 Eol_Recv_Key = ((uint32)pKeyBuffer[0] << 24u) | ((uint32)pKeyBuffer[1] << 16u) | ((uint32)pKeyBuffer[2] << 8u) | ((uint32)pKeyBuffer[3]);
	uint32 Eol_Calc_Key = ((Eol_Seed_H * 1103515245) + 12345)^((Eol_Seed_L * 1103515245)+12345)^(0x87654321);

	(void)Dcm_GetSesCtrlType(&fl_Session);
	if(EOL_SESSION == fl_Session)
	{
		if(Eol_Recv_Key == Eol_Calc_Key)
		{
			status = DCM_E_OK;
			*Length = 0;
		}
		else
		{
			status = DCM_E_NOT_OK;
		}
	}
	else
	{
		/* Calculate Key */
		Sec_GenerateKey(seed, &fl_Key_Generate_u32);
		if(fl_key_Receive_u32 == fl_Key_Generate_u32)
		{

		}
		/* Verify Key */
		// if (( R_Key_Tool == R_Seed_Key) && ( L_Key_Tool == L_Seed_Key))
		// {
		// 	status = DCM_E_OK;
		// 	*Length = 0;
		// }
		// else
		// {
		// 	status = DCM_E_NOT_OK;
		// }

	}

	return status;
}


/*============================================================================
 ** Function Name:	  Sec_GenerateKey
 **
 ** Visibility: 	  Private
 **
 ** Description:	  This function used to Generate the security key after getting SEED
 **
 **
 ** Invocation: 	  Invoked by Sec_VerifyKey
 **
 ** Inputs			  UINT16 *Seed_Key - address of key variable from the  calling function
 **
 ** Return: 		  None
 **
 ** Critical Section: None.
 **==========================================================================*/
static void Sec_GenerateKey (uint32 seed, uint32 *Seed_Key)
{
	uint32 key = 0;
	uint8 i = 0;
	uint64 CONST_VALUE = 0x80000000;
	uint64 MASK = 0x8EC9AA7E;

	if(seed != 0)
	{
		for(i = 0; i < 35; i++)
		{
			if(seed & CONST_VALUE)
			{
				seed = seed << 1;
				seed = seed ^ MASK;
			}
			else
			{
				seed = seed << 1;
			}
		}
		key = seed;
	}

	*Seed_Key = key;
}

/**********************************************************************************************************************
 *
 * Function Name  :
 * Description    :
 *
 * Invocation     :
 * Parameters[in] :
 *
 * Returns        :
 *
************************************************************************************************************************/
Std_ReturnType SecLevelEOLCmpKey(Dcm_MsgType Buff,Dcm_MsgLenType* Length)
{
	uint32 key;
	Std_ReturnType ret_val;
	/*key = 0x684307A7 */
	key = ~SecurityLevelEOL_SeedSend;
	key = key + 0x56;
	if((Buff[0] == (uint8)(key >> 24)) &&
		(Buff[1] == (uint8)(key >> 16)) &&
		(Buff[2] == (uint8)(key >> 8))  &&
		(Buff[3] == (uint8)(key >> 0)))
	{
		ret_val = DCM_E_OK;
		*Length = 0;
	}
	else
	{
		ret_val = DCM_E_NOT_OK;
	}
	SecurityLevel2_SeedSend = 0;
	return ret_val;
}

/**********************************************************************************************************************
 *
 * Function Name  :
 * Description    :
 *
 * Invocation     :
 * Parameters[in] :
 *
 * Returns        :
 *
************************************************************************************************************************/
Std_ReturnType Communication_action(uint8 Com_action)
{
	/* The below code is added for testing the Implementation.
	Once the Inteface functon is avilable which can be called here.

	Ex: Std_ReturnType App_Comm_control(Com_action)
	ret_val = DCM_E_OK;
	*Length = 0;
	*/

	Std_ReturnType ret_val;

	/* Qiuhuaqing Modify,  To be Release after BswM Finished */
	//BswM_Dcm_CommunicationMode_CurrentState(0, Com_action);

	Dcm_ExternalProcessingDone();
	ret_val = DCM_E_OK;

	switch(Com_action)
	{
		case DCM_ENABLE_RX_TX_NORM:
		{
			// AppCtrlExt_CAN_Rx_EnableNoInit();
			// AppCtrlExt_CAN_TX_EnableNoInit();
			Dcm_ExternalProcessingDone();
			ret_val = DCM_E_OK;
		}
		break;
		case DCM_ENABLE_RX_TX_NM:
		{
			// AppCtrlExt_CAN_NM_Enable();
			// Dcm_ExternalProcessingDone();
			ret_val = DCM_E_OK;
		}
		break;
		case DCM_ENABLE_RX_TX_NORM_NM:
		{
			// AppCtrlExt_CAN_Rx_EnableNoInit();
			// AppCtrlExt_CAN_TX_EnableNoInit();
			//AppCtrlExt_CAN_NM_Enable();
			/*lxiong2 add this for exit 03 session, DCM should enable RX and TX NORM NM*/
			if(DCM_ENABLE_RX_TX_NORM_NM_flag == TRUE)
			{
				DCM_ENABLE_RX_TX_NORM_NM_flag = FALSE;
				Dcm_ExternalProcessingDone();
			}
			ret_val = DCM_E_OK;
		}
		break;
		case DCM_ENABLE_RX_DISABLE_TX_NORM:
		{
			//AppCtrlExt_CAN_Rx_EnableNoInit();
			//AppCtrlExt_CAN_TX_Disable();

			Dcm_ExternalProcessingDone();
			ret_val = DCM_E_OK;
		}
		break;
		case DCM_ENABLE_RX_DISABLE_TX_NM:
		{
			//AppCtrlExt_CAN_NM_Disable();

			Dcm_ExternalProcessingDone();
			ret_val = DCM_E_OK;
		}
		break;
		case DCM_ENABLE_RX_DISABLE_TX_NORM_NM:
		{
			// AppCtrlExt_CAN_Rx_EnableNoInit();
			// AppCtrlExt_CAN_TX_Disable();
			// AppCtrlExt_CAN_NM_Disable();

			Dcm_ExternalProcessingDone();
			ret_val = DCM_E_OK;
		}
		break;
		case DCM_DISABLE_RX_ENABLE_TX_NORM:
		{
			// AppCtrlExt_CAN_Rx_Disable();
			// AppCtrlExt_CAN_TX_EnableNoInit();

			Dcm_ExternalProcessingDone();
			ret_val = DCM_E_OK;
		}
		break;
		case DCM_DISABLE_RX_ENABLE_TX_NM:
		{
			//AppCtrlExt_CAN_NM_Disable();

			Dcm_ExternalProcessingDone();
			ret_val = DCM_E_OK;
		}
		break;
		case DCM_DISABLE_RX_ENABLE_TX_NORM_NM:
		{
			// AppCtrlExt_CAN_Rx_Disable();
			// AppCtrlExt_CAN_TX_EnableNoInit();
			// AppCtrlExt_CAN_NM_Disable();

			Dcm_ExternalProcessingDone();
			ret_val = DCM_E_OK;
		}
		break;
		case DCM_DISABLE_RX_TX_NORMAL:
		{
			// AppCtrlExt_CAN_Rx_Disable();
			// AppCtrlExt_CAN_TX_Disable();

			Dcm_ExternalProcessingDone();
			ret_val = DCM_E_OK;
		}
		break;
		case DCM_DISABLE_RX_TX_NM:
		{
			//AppCtrlExt_CAN_NM_Disable();

			Dcm_ExternalProcessingDone();
			ret_val = DCM_E_OK;
		}
		break;
		case DCM_DISABLE_RX_TX_NORM_NM:
		{
			// AppCtrlExt_CAN_Rx_Disable();
			// AppCtrlExt_CAN_TX_Disable();
			// AppCtrlExt_CAN_NM_Disable();

			Dcm_ExternalProcessingDone();
			ret_val = DCM_E_OK;
		}
		break;
		default:
		{
			//Dcm_ExternalSetNegResponse(DCM_E_REQUESTOUTOFRANGE);
			Dcm_ExternalProcessingDone();
			ret_val = DCM_E_NOT_OK;
		}
		break;
	}
	return ret_val;
}
/**********************************************************************************************************************
 *
 * Function Name  :
 * Description    :
 *
 * Invocation     :
 * Parameters[in] :
 *
 * Returns        :
 *
************************************************************************************************************************/
void BroadCastSessionStatus(uint8 SubFunction)
{

}

/**********************************************************************************************************************
 *
 * Function Name  : DSP_APP_Diag_Entry_Condition
 * Description    : the key is ON and the speed is 0
 *
 * Invocation     :
 * Parameters[in] :
 *
 * Returns        :
 *
************************************************************************************************************************/
boolean DSP_APP_Diag_Entry_Condition(void)
{
	boolean fl_rte_bool = FALSE;
	eIgnState fl_ign_state_e = eIGN_OFF;
	uint16 fl_speed_u16 = 0;
	uint8 fl_session = 0;

	//Qiuhuaqing Modify,
	fl_ign_state_e = eIGN_RUN;
	Rte_Read_ComVnimMdl_Sig_ABS3_VehSpd_Value(&fl_speed_u16);

	fl_speed_u16 = fl_speed_u16 * 45 / 8;

	if((eIGN_RUN == fl_ign_state_e) && \
	  (125 >= fl_speed_u16))
	{
		fl_rte_bool = TRUE;
	}
	else
	{
		fl_rte_bool = FALSE;
	}

	return fl_rte_bool;
}

/**********************************************************************************************************************
 *
 * Function Name  : DSP_APP_Prog_Entry_Condition
 * Description    : the key is ON, the speed is 0, and the battery voltage is greater than 11V.
 *
 * Invocation     :
 * Parameters[in] :
 *
 * Returns        :
 *
************************************************************************************************************************/
boolean DSP_APP_Prog_Entry_Condition(void)
{
	boolean fl_rte_bool = FALSE;
	eIgnState fl_ign_state_e = eIGN_OFF;
	UInt32 fl_speed_U32 = 0;
	UInt32 fl_tach_U32 = 0;
	sint32 fl_batt_voltage_S32 = 0;
	uint8 fl_session = 0;

	fl_session = EXTENDED_SESSION;
	fl_ign_state_e = eIGN_RUN;
	fl_speed_U32 = 0;
	fl_tach_U32 = 0;

	//QHQ,ToBeDefine
	// Rte_Read_TIModMdlIgnState_IGNState(&fl_ign_state_e);
	// Rte_Read_tiSR_TISpdMdl_value(&fl_speed_U32);
	// Rte_Read_tiSR_TITachMdl_value(&fl_tach_U32);
	// Rte_Call_tiCS_TIIoHwAb_AIn_Impl_GetVoltage(eIOVoltageInId_MAI_BAT,&fl_batt_voltage_S32);
	// Dcm_GetSesCtrlType(&fl_session);

	if((EXTENDED_SESSION == fl_session) && \
		(eIGN_RUN == fl_ign_state_e) && \
		(0 == fl_speed_U32) && \
		(0 == fl_tach_U32) && \
		(fl_batt_voltage_S32 > 1100))/*the battery voltage is greater than 11V*/
	{
		fl_rte_bool = TRUE;
	}
	else
	{
		fl_rte_bool = FALSE;
	}

	return fl_rte_bool;
}

/**********************************************************************************************************************
 *
 * Function Name  :
 * Description    :
 *
 * Invocation     :
 * Parameters[in] :
 *
 * Returns        :
 *
************************************************************************************************************************/
Std_ReturnType DI_Did_Diag_Read(Dcm_DspDidIdentifierTableType  Did,Dcm_MsgType Buff,Dcm_MsgLenType* Length)
{
	Std_ReturnType		RetVal = DCM_E_OK;
	PID_RECORD  		*table_ptr;
	DG_MGR_UINT8		i;
	DG_MGR_UINT8		loop_size;

    table_ptr = (PID_RECORD *) diag_pid_table_rom;
	loop_size = sizeof(diag_pid_table_rom) / sizeof(PID_RECORD);

	for(i = 0x01;i < loop_size; i++)
	{
		if( table_ptr->pid_number == Did)
		{
			*Length = (*table_ptr->pid_function_ptr)(Buff);
			if(*Length != 0)
			{
				Dcm_ExternalProcessingDone();
			}
			else
			{
				Dcm_ExternalSetNegResponse(DCM_E_SUBFUNCTIONNOTSUPPORTED);
				Dcm_ExternalProcessingDone();
			}
		}
		else
		{
			/*Do Nothing!*/
		}
		++table_ptr;
	}
	return RetVal;
}
/**********************************************************************************************************************
 *
 * Function Name  :
 * Description    :
 *
 * Invocation     :
 * Parameters[in] :
 *
 * Returns        :
 *
************************************************************************************************************************/
static Std_ReturnType DI_Did_Diag_Write(Dcm_DspDidIdentifierTableType  Did,Dcm_MsgType Buff,Dcm_MsgLenType* Length)
{
	Std_ReturnType		RetVal = DCM_E_OK;
	PID_RECORD  		*table_ptr;
	DG_MGR_UINT8		i;
	DG_MGR_UINT8		loop_size;

    table_ptr = (PID_RECORD *) diag_write_pid_table_rom;
	loop_size = sizeof(diag_write_pid_table_rom) / sizeof(PID_RECORD);

	for(i = 0x01;i < loop_size; i++)
	{
		if( table_ptr->pid_number == Did)
		{
			*Length = (*table_ptr->pid_function_ptr)(Buff);
			if(*Length == 0)
			{
				Dcm_ExternalSetNegResponse(49);
				Dcm_ExternalProcessingDone();
			}
			else
			{
				*Length = 0;
				Dcm_ExternalProcessingDone();
			}
		}
		else
		{
			/*Do Nothing!*/
		}
		++table_ptr;
	}

	return RetVal;
}
/**********************************************************************************************************************
 *
 * Function Name  :
 * Description    :
 *
 * Invocation     :
 * Parameters[in] :
 *
 * Returns        :
 *
************************************************************************************************************************/
static Std_ReturnType DI_Did_Diag_IO(Dcm_DspDidIdentifierTableType  Did,Dcm_MsgType Buff,Dcm_MsgLenType* Length)
{
	Std_ReturnType		RetVal = DCM_E_OK;
	IOCTL_RECORD const 	*ioctl_record_ptr;
	DG_MGR_UINT8  		fl_resp_code_U8;

	ioctl_record_ptr = &ioctl_diag_table_rom[0];

	while (ioctl_record_ptr->pid != 0x00)
	{
		if (ioctl_record_ptr->pid == Did)
    	{
    		fl_resp_code_U8 = ioctl_record_ptr->function_handler(Buff[0],(DG_MGR_UINT8 *)&Buff[1]);
			*Length = ioctl_record_ptr->data_length;
			if(fl_resp_code_U8 == 0)
			{
				Dcm_ExternalProcessingDone();
			}
			else
			{
				Dcm_ExternalSetNegResponse(fl_resp_code_U8);
				Dcm_ExternalProcessingDone();
			}
		}
		ioctl_record_ptr++;
	}

	return RetVal;
}


uint8 FblApp_IsValidApp(void)
{
    uint8 valid = (uint8)TRUE;
    uint8 i;
    uint8 validBegin[APP_MARKER_PATTERN_SIZE] = APP_MARKER_PATTERN_BEGIN;
    uint8 validEnd[APP_MARKER_PATTERN_SIZE] = APP_MARKER_PATTERN_END;



	return valid;
}



