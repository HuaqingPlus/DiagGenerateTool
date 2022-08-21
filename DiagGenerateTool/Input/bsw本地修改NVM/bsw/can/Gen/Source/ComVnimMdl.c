# include "ComVnimMdl.h"
#include "Com.h"

typedef unsigned int Rte_BitType;

typedef struct
{
	Rte_BitType Rte_RxTimeout_BCM17_AnimationReq_Rx : 1;
	Rte_BitType Rte_RxTimeout_BCM17_ApproachLightAnimationType_Rx : 1;
	Rte_BitType Rte_RxTimeout_BMS17_BMS_DCChrgConnect_Rx : 1;
	Rte_BitType Rte_RxTimeout_BCM17_GoodbyeAnimationType_Rx : 1;
	Rte_BitType Rte_RxTimeout_BCM17_WelcomeAnimationType_Rx : 1;
	Rte_BitType Rte_RxTimeout_BCM17_MecDancAnimationType_Rx : 1;
	Rte_BitType Rte_RxTimeout_BMS1_BMS_SOC_Rx : 1;
	Rte_BitType Rte_RxTimeout_BCM23_CEMDetminCdnSts_Rx : 1;
	Rte_BitType Rte_RxTimeout_ABS3_CheckSum_ABS3_Rx : 1;
	Rte_BitType Rte_RxTimeout_ABS3_RollingCounter_ABS3_Rx : 1;
	Rte_BitType Rte_RxTimeout_ABS3_VehSpdVld_Rx : 1;
	Rte_BitType Rte_RxTimeout_ABS3_VehSpd_Rx : 1;
	Rte_BitType Rte_RxTimeout_PEPS2_CheckSum_PEPS2_Rx : 1;
	Rte_BitType Rte_RxTimeout_PEPS2_RollingCounter_PEPS2_Rx : 1;
	Rte_BitType Rte_RxTimeout_PEPS2_SysPowerModVld_Rx : 1;
	Rte_BitType Rte_RxTimeout_PEPS2_SysPowerMod_Rx : 1;
	Rte_BitType Rte_RxTimeout_BCM10_Checksum_BCM10_Rx : 1;
	Rte_BitType Rte_RxTimeout_BCM10_LTurnLampWorkCmd_Rx : 1;
	Rte_BitType Rte_RxTimeout_BCM10_RTurnLmpWorkCmd_Rx : 1;
	Rte_BitType Rte_RxTimeout_BCM10_Rollingcounter_BCM10_Rx : 1;
	Rte_BitType Rte_RxTimeout_HUT54_ChrgDispPatTypSet_Rx : 1;
	Rte_BitType Rte_RxTimeout_HUT54_ChrgPatDispSwt_Rx : 1;
	Rte_BitType Rte_RxTimeout_HUT54_EIDCSwt_Rx : 1;
	Rte_BitType Rte_RxTimeout_HUT54_EmojiTypSet_Rx : 1;
	Rte_BitType Rte_RxTimeout_HUT54_RemindTypSet_Rx : 1;
	Rte_BitType Rte_RxTimeout_HUT54_TopicTypSet_Rx : 1;
	Rte_BitType Rte_RxTimeout_HUT54_TurnRemdSwt_Rx : 1;
	Rte_BitType Rte_RxTimeout_HUT54_WelcomeSwt_Rx : 1;
	Rte_BitType Rte_RxTimeout_HUT54_WordTypSet_Rx : 1;
	Rte_BitType Rte_RxTimeout_HUT54_WelcomePatTypSet_Rx : 1;
	Rte_BitType Rte_RxTimeout_EEM1_DeepSlpCmd_Rx : 1;
	Rte_BitType Rte_RxTimeout_EEM1_Stat_PwrSv_Lvl_Rx : 1;
	Rte_BitType Rte_RxTimeout_EEM1_TranPMode_Sts_Rx : 1;
	Rte_BitType Rte_RxTimeout_IP2_IP_VehTotDistanceValid_Rx : 1;
	Rte_BitType Rte_RxTimeout_IP2_IP_VehTotDistance_Rx : 1;
	Rte_BitType Rte_RxTimeout_CSA1_RTurnLmpSwtSts_Rx : 1;
	Rte_BitType Rte_RxTimeout_CSA1_LTurnLmpSwtSts_Rx : 1;
	Rte_BitType Rte_RxTimeout_RMCU4_RMCU_ActRotSpd_Rx : 1;
	Rte_BitType Rte_RxTimeout_MCU_5_MCU_ActRotSpd_Rx : 1;
	Rte_BitType Rte_RxTimeout_OBC3_OBC_CCLineConnectSts_Rx : 1;
	Rte_BitType Rte_RxTimeout_R_PBOX1_PosnLmpOutpSts_R_PBox_Rx : 1;
	Rte_BitType Rte_RxTimeout_GW1_ScenarioID_Rx : 1;
	Rte_BitType Rte_RxTimeout_GW1_ScenarioReq_Rx : 1;
	Rte_BitType Rte_RxTimeout_HUT34_TimeIndcn_Rx : 1;
	Rte_BitType Rte_RxTimeout_HUT34_TimeMod_Rx : 1;
	Rte_BitType Rte_RxTimeout_HUT34_Time_Day_Rx : 1;
	Rte_BitType Rte_RxTimeout_HUT34_Time_Hour_Rx : 1;
	Rte_BitType Rte_RxTimeout_HUT34_Time_Minutes_Rx : 1;
	Rte_BitType Rte_RxTimeout_HUT34_Time_Month_Rx : 1;
	Rte_BitType Rte_RxTimeout_HUT34_Time_Second_Rx : 1;
	Rte_BitType Rte_RxTimeout_HUT34_Time_Year_Left_Rx : 1;
	Rte_BitType Rte_RxTimeout_HUT34_Time_Year_Right_Rx : 1;
	Rte_BitType Rte_RxTimeout_VCU6_VCU_BrkPedlSts_Rx : 1;
	Rte_BitType Rte_RxTimeout_VCU3_VCU_ChrgnSts_Rx : 1;
	Rte_BitType Rte_RxTimeout_VCU2_VCU_GearSts_Rx : 1;
} Rte_RxTimeoutFlagsType;

typedef struct
{
	Rte_BitType Rte_RxNeverReceived_BCM17_AnimationReq_Rx : 1;
	Rte_BitType Rte_RxNeverReceived_BCM17_ApproachLightAnimationType_Rx : 1;
	Rte_BitType Rte_RxNeverReceived_BMS17_BMS_DCChrgConnect_Rx : 1;
	Rte_BitType Rte_RxNeverReceived_BCM17_GoodbyeAnimationType_Rx : 1;
	Rte_BitType Rte_RxNeverReceived_BCM17_WelcomeAnimationType_Rx : 1;
	Rte_BitType Rte_RxNeverReceived_BCM17_MecDancAnimationType_Rx : 1;
	Rte_BitType Rte_RxNeverReceived_BMS1_BMS_SOC_Rx : 1;
	Rte_BitType Rte_RxNeverReceived_BCM23_CEMDetminCdnSts_Rx : 1;
	Rte_BitType Rte_RxNeverReceived_ABS3_CheckSum_ABS3_Rx : 1;
	Rte_BitType Rte_RxNeverReceived_ABS3_RollingCounter_ABS3_Rx : 1;
	Rte_BitType Rte_RxNeverReceived_ABS3_VehSpdVld_Rx : 1;
	Rte_BitType Rte_RxNeverReceived_ABS3_VehSpd_Rx : 1;
	Rte_BitType Rte_RxNeverReceived_PEPS2_CheckSum_PEPS2_Rx : 1;
	Rte_BitType Rte_RxNeverReceived_PEPS2_RollingCounter_PEPS2_Rx : 1;
	Rte_BitType Rte_RxNeverReceived_PEPS2_SysPowerModVld_Rx : 1;
	Rte_BitType Rte_RxNeverReceived_PEPS2_SysPowerMod_Rx : 1;
	Rte_BitType Rte_RxNeverReceived_BCM10_Checksum_BCM10_Rx : 1;
	Rte_BitType Rte_RxNeverReceived_BCM10_LTurnLampWorkCmd_Rx : 1;
	Rte_BitType Rte_RxNeverReceived_BCM10_RTurnLmpWorkCmd_Rx : 1;
	Rte_BitType Rte_RxNeverReceived_BCM10_Rollingcounter_BCM10_Rx : 1;
	Rte_BitType Rte_RxNeverReceived_HUT54_ChrgDispPatTypSet_Rx : 1;
	Rte_BitType Rte_RxNeverReceived_HUT54_ChrgPatDispSwt_Rx : 1;
	Rte_BitType Rte_RxNeverReceived_HUT54_EIDCSwt_Rx : 1;
	Rte_BitType Rte_RxNeverReceived_HUT54_EmojiTypSet_Rx : 1;
	Rte_BitType Rte_RxNeverReceived_HUT54_RemindTypSet_Rx : 1;
	Rte_BitType Rte_RxNeverReceived_HUT54_TopicTypSet_Rx : 1;
	Rte_BitType Rte_RxNeverReceived_HUT54_TurnRemdSwt_Rx : 1;
	Rte_BitType Rte_RxNeverReceived_HUT54_WelcomeSwt_Rx : 1;
	Rte_BitType Rte_RxNeverReceived_HUT54_WordTypSet_Rx : 1;
	Rte_BitType Rte_RxNeverReceived_HUT54_WelcomePatTypSet_Rx : 1;
	Rte_BitType Rte_RxNeverReceived_EEM1_DeepSlpCmd_Rx : 1;
	Rte_BitType Rte_RxNeverReceived_EEM1_Stat_PwrSv_Lvl_Rx : 1;
	Rte_BitType Rte_RxNeverReceived_EEM1_TranPMode_Sts_Rx : 1;
	Rte_BitType Rte_RxNeverReceived_IP2_IP_VehTotDistanceValid_Rx : 1;
	Rte_BitType Rte_RxNeverReceived_IP2_IP_VehTotDistance_Rx : 1;
	Rte_BitType Rte_RxNeverReceived_CSA1_RTurnLmpSwtSts_Rx : 1;
	Rte_BitType Rte_RxNeverReceived_CSA1_LTurnLmpSwtSts_Rx : 1;
	Rte_BitType Rte_RxNeverReceived_RMCU4_RMCU_ActRotSpd_Rx : 1;
	Rte_BitType Rte_RxNeverReceived_MCU_5_MCU_ActRotSpd_Rx : 1;
	Rte_BitType Rte_RxNeverReceived_OBC3_OBC_CCLineConnectSts_Rx : 1;
	Rte_BitType Rte_RxNeverReceived_R_PBOX1_PosnLmpOutpSts_R_PBox_Rx : 1;
	Rte_BitType Rte_RxNeverReceived_GW1_ScenarioID_Rx : 1;
	Rte_BitType Rte_RxNeverReceived_GW1_ScenarioReq_Rx : 1;
	Rte_BitType Rte_RxNeverReceived_HUT34_TimeIndcn_Rx : 1;
	Rte_BitType Rte_RxNeverReceived_HUT34_TimeMod_Rx : 1;
	Rte_BitType Rte_RxNeverReceived_HUT34_Time_Day_Rx : 1;
	Rte_BitType Rte_RxNeverReceived_HUT34_Time_Hour_Rx : 1;
	Rte_BitType Rte_RxNeverReceived_HUT34_Time_Minutes_Rx : 1;
	Rte_BitType Rte_RxNeverReceived_HUT34_Time_Month_Rx : 1;
	Rte_BitType Rte_RxNeverReceived_HUT34_Time_Second_Rx : 1;
	Rte_BitType Rte_RxNeverReceived_HUT34_Time_Year_Left_Rx : 1;
	Rte_BitType Rte_RxNeverReceived_HUT34_Time_Year_Right_Rx : 1;
	Rte_BitType Rte_RxNeverReceived_VCU6_VCU_BrkPedlSts_Rx : 1;
	Rte_BitType Rte_RxNeverReceived_VCU3_VCU_ChrgnSts_Rx : 1;
	Rte_BitType Rte_RxNeverReceived_VCU2_VCU_GearSts_Rx : 1;
} Rte_RxNeverReceivedFlagsType;

Rte_RxNeverReceivedFlagsType Rte_RxNeverReceivedFlags = {
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0
};

Rte_RxTimeoutFlagsType Rte_RxTimeoutFlags = {
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0
};

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComVnimMdl_Sig_BCM17_AnimationReq_Value(uint8 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = E_OK;

  ret = Com_ReceiveSignal(ComConf_ComSignal_AnimationReq_oBCM17_oC03_for_EL_CAN_V2_1_1db28c46_Rx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */
  if (ret != COM_SERVICE_NOT_AVAILABLE)
  {
    if (Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_BCM17_AnimationReq_Rx == 0)
    {
      ret = RTE_E_NEVER_RECEIVED;
    }
  }
  if (Rte_RxTimeoutFlags.Rte_RxTimeout_BCM17_AnimationReq_Rx != 0)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED;
  }

  return ret;
} 

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComVnimMdl_Sig_BCM17_ApproachLightAnimationType_Value(uint8 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_OK;

	ret = Com_ReceiveSignal(ComConf_ComSignal_ApproachLightAnimationType_oBCM17_oC03_for_EL_CAN_V2_1_5b20a81e_Rx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */
	if (ret != COM_SERVICE_NOT_AVAILABLE)
	{
		if (Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_BCM17_ApproachLightAnimationType_Rx == 0)
		{
			ret = RTE_E_NEVER_RECEIVED;
		}
	}
	if (Rte_RxTimeoutFlags.Rte_RxTimeout_BCM17_ApproachLightAnimationType_Rx != 0)
	{
		ret |= RTE_E_MAX_AGE_EXCEEDED;
	}

	return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComVnimMdl_Sig_BMS17_BMS_DCChrgConnect_Value(uint8 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_OK;

	ret = Com_ReceiveSignal(ComConf_ComSignal_BMS_DCChrgConnect_oBMS17_oC03_for_EL_CAN_V2_1_91db617c_Rx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */
	if (ret != COM_SERVICE_NOT_AVAILABLE)
	{
		if (Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_BMS17_BMS_DCChrgConnect_Rx == 0)
		{
			ret = RTE_E_NEVER_RECEIVED;
		}
	}
	if (Rte_RxTimeoutFlags.Rte_RxTimeout_BMS17_BMS_DCChrgConnect_Rx != 0)
	{
		ret |= RTE_E_MAX_AGE_EXCEEDED;
	}

	return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComVnimMdl_Sig_BCM17_GoodbyeAnimationType_Value(uint8 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_OK;

	ret = Com_ReceiveSignal(ComConf_ComSignal_GoodbyeAnimationType_oBCM17_oC03_for_EL_CAN_V2_1_bc8c4dab_Rx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */
	if (ret != COM_SERVICE_NOT_AVAILABLE)
	{
		if (Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_BCM17_GoodbyeAnimationType_Rx == 0)
		{
			ret = RTE_E_NEVER_RECEIVED;
		}
	}
	if (Rte_RxTimeoutFlags.Rte_RxTimeout_BCM17_GoodbyeAnimationType_Rx != 0)
	{
		ret |= RTE_E_MAX_AGE_EXCEEDED;
	}

	return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComVnimMdl_Sig_BCM17_WelcomeAnimationType_Value(uint8 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_OK;

	ret = Com_ReceiveSignal(ComConf_ComSignal_WelcomeAnimationType_oBCM17_oC03_for_EL_CAN_V2_1_c76d0f7a_Rx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */
	if (ret != COM_SERVICE_NOT_AVAILABLE)
	{
		if (Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_BCM17_WelcomeAnimationType_Rx == 0)
		{
			ret = RTE_E_NEVER_RECEIVED;
		}
	}
	if (Rte_RxTimeoutFlags.Rte_RxTimeout_BCM17_WelcomeAnimationType_Rx != 0)
	{
		ret |= RTE_E_MAX_AGE_EXCEEDED;
	}

	return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComVnimMdl_Sig_BCM17_MecDancAnimationType_Value(uint8 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_OK;

	ret = Com_ReceiveSignal(ComConf_ComSignal_MecDancAnimationType_oBCM17_oC03_for_EL_CAN_V2_1_6bb5a98f_Rx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */
	if (ret != COM_SERVICE_NOT_AVAILABLE)
	{
		if (Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_BCM17_MecDancAnimationType_Rx == 0)
		{
			ret = RTE_E_NEVER_RECEIVED;
		}
	}
	if (Rte_RxTimeoutFlags.Rte_RxTimeout_BCM17_MecDancAnimationType_Rx != 0)
	{
		ret |= RTE_E_MAX_AGE_EXCEEDED;
	}

	return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComVnimMdl_Sig_BMS1_BMS_SOC_Value(uint16 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_OK;

	ret = Com_ReceiveSignal(ComConf_ComSignal_BMS_SOC_oBMS1_oC03_for_EL_CAN_V2_1_a261d1ce_Rx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */
	if (ret != COM_SERVICE_NOT_AVAILABLE)
	{
		if (Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_BMS1_BMS_SOC_Rx == 0)
		{
			ret = RTE_E_NEVER_RECEIVED;
		}
	}
	if (Rte_RxTimeoutFlags.Rte_RxTimeout_BMS1_BMS_SOC_Rx != 0)
	{
		ret |= RTE_E_MAX_AGE_EXCEEDED;
	}

	return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComVnimMdl_Sig_BCM23_CEMDetminCdnSts_Value(uint8 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_OK;

	ret = Com_ReceiveSignal(ComConf_ComSignal_CEMDetminCdnSts_oBCM23_oC03_for_EL_CAN_V2_1_df6348d5_Rx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */
	if (ret != COM_SERVICE_NOT_AVAILABLE)
	{
		if (Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_BCM23_CEMDetminCdnSts_Rx == 0)
		{
			ret = RTE_E_NEVER_RECEIVED;
		}
	}
	if (Rte_RxTimeoutFlags.Rte_RxTimeout_BCM23_CEMDetminCdnSts_Rx != 0)
	{
		ret |= RTE_E_MAX_AGE_EXCEEDED;
	}

	return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComVnimMdl_Sig_ABS3_CheckSum_ABS3_Value(uint8 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_OK;

	ret = Com_ReceiveSignal(ComConf_ComSignal_CheckSum_ABS3_oABS3_oC03_for_EL_CAN_V2_1_5745e086_Rx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */
	if (ret != COM_SERVICE_NOT_AVAILABLE)
	{
		if (Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_ABS3_CheckSum_ABS3_Rx == 0)
		{
			ret = RTE_E_NEVER_RECEIVED;
		}
	}
	if (Rte_RxTimeoutFlags.Rte_RxTimeout_ABS3_CheckSum_ABS3_Rx != 0)
	{
		ret |= RTE_E_MAX_AGE_EXCEEDED;
	}

	return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComVnimMdl_Sig_ABS3_RollingCounter_ABS3_Value(uint8 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_OK;

	ret = Com_ReceiveSignal(ComConf_ComSignal_RollingCounter_ABS3_oABS3_oC03_for_EL_CAN_V2_1_b6ac7000_Rx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */
	if (ret != COM_SERVICE_NOT_AVAILABLE)
	{
		if (Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_ABS3_RollingCounter_ABS3_Rx == 0)
		{
			ret = RTE_E_NEVER_RECEIVED;
		}
	}
	if (Rte_RxTimeoutFlags.Rte_RxTimeout_ABS3_RollingCounter_ABS3_Rx != 0)
	{
		ret |= RTE_E_MAX_AGE_EXCEEDED;
	}

	return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComVnimMdl_Sig_ABS3_VehSpdVld_Value(uint8 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_OK;

	ret = Com_ReceiveSignal(ComConf_ComSignal_VehSpdVld_oABS3_oC03_for_EL_CAN_V2_1_32497dd3_Rx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */
	if (ret != COM_SERVICE_NOT_AVAILABLE)
	{
		if (Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_ABS3_VehSpdVld_Rx == 0)
		{
			ret = RTE_E_NEVER_RECEIVED;
		}
	}
	if (Rte_RxTimeoutFlags.Rte_RxTimeout_ABS3_VehSpdVld_Rx != 0)
	{
		ret |= RTE_E_MAX_AGE_EXCEEDED;
	}

	return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComVnimMdl_Sig_ABS3_VehSpd_Value(uint16 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_OK;

	ret = Com_ReceiveSignal(ComConf_ComSignal_VehSpd_oABS3_oC03_for_EL_CAN_V2_1_23260d94_Rx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */
	if (ret != COM_SERVICE_NOT_AVAILABLE)
	{
		if (Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_ABS3_VehSpd_Rx == 0)
		{
			ret = RTE_E_NEVER_RECEIVED;
		}
	}
	if (Rte_RxTimeoutFlags.Rte_RxTimeout_ABS3_VehSpd_Rx != 0)
	{
		ret |= RTE_E_MAX_AGE_EXCEEDED;
	}

	return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComVnimMdl_Sig_PEPS2_CheckSum_PEPS2_Value(uint8 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_OK;

	ret = Com_ReceiveSignal(ComConf_ComSignal_CheckSum_PEPS2_oPEPS2_oC03_for_EL_CAN_V2_1_06064851_Rx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */
	if (ret != COM_SERVICE_NOT_AVAILABLE)
	{
		if (Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_PEPS2_CheckSum_PEPS2_Rx == 0)
		{
			ret = RTE_E_NEVER_RECEIVED;
		}
	}
	if (Rte_RxTimeoutFlags.Rte_RxTimeout_PEPS2_CheckSum_PEPS2_Rx != 0)
	{
		ret |= RTE_E_MAX_AGE_EXCEEDED;
	}

	return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComVnimMdl_Sig_PEPS2_RollingCounter_PEPS2_Value(uint16 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_OK;

	ret = Com_ReceiveSignal(ComConf_ComSignal_RollingCounter_PEPS2_oPEPS2_oC03_for_EL_CAN_V2_1_9bd00531_Rx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */
	if (ret != COM_SERVICE_NOT_AVAILABLE)
	{
		if (Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_PEPS2_RollingCounter_PEPS2_Rx == 0)
		{
			ret = RTE_E_NEVER_RECEIVED;
		}
	}
	if (Rte_RxTimeoutFlags.Rte_RxTimeout_PEPS2_RollingCounter_PEPS2_Rx != 0)
	{
		ret |= RTE_E_MAX_AGE_EXCEEDED;
	}

	return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComVnimMdl_Sig_PEPS2_SysPowerModVld_Value(uint8 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_OK;

	ret = Com_ReceiveSignal(ComConf_ComSignal_SysPowerModVld_oPEPS2_oC03_for_EL_CAN_V2_1_b6c20e3c_Rx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */
	if (ret != COM_SERVICE_NOT_AVAILABLE)
	{
		if (Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_PEPS2_SysPowerModVld_Rx == 0)
		{
			ret = RTE_E_NEVER_RECEIVED;
		}
	}
	if (Rte_RxTimeoutFlags.Rte_RxTimeout_PEPS2_SysPowerModVld_Rx != 0)
	{
		ret |= RTE_E_MAX_AGE_EXCEEDED;
	}

	return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComVnimMdl_Sig_PEPS2_SysPowerMod_Value(uint8 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_OK;

	ret = Com_ReceiveSignal(ComConf_ComSignal_SysPowerMod_oPEPS2_oC03_for_EL_CAN_V2_1_37fb939a_Rx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */
	if (ret != COM_SERVICE_NOT_AVAILABLE)
	{
		if (Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_PEPS2_SysPowerMod_Rx == 0)
		{
			ret = RTE_E_NEVER_RECEIVED;
		}
	}
	if (Rte_RxTimeoutFlags.Rte_RxTimeout_PEPS2_SysPowerMod_Rx != 0)
	{
		ret |= RTE_E_MAX_AGE_EXCEEDED;
	}

	return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComVnimMdl_Sig_BCM10_Checksum_BCM10_Value(uint8 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_OK;

	ret = Com_ReceiveSignal(ComConf_ComSignal_Checksum_BCM10_oBCM10_oC03_for_EL_CAN_V2_1_819e75d3_Rx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */
	if (ret != COM_SERVICE_NOT_AVAILABLE)
	{
		if (Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_BCM10_Checksum_BCM10_Rx == 0)
		{
			ret = RTE_E_NEVER_RECEIVED;
		}
	}
	if (Rte_RxTimeoutFlags.Rte_RxTimeout_BCM10_Checksum_BCM10_Rx != 0)
	{
		ret |= RTE_E_MAX_AGE_EXCEEDED;
	}

	return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComVnimMdl_Sig_BCM10_LTurnLampWorkCmd_Value(uint8 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_OK;

	ret = Com_ReceiveSignal(ComConf_ComSignal_LTurnLampWorkCmd_oBCM10_oC03_for_EL_CAN_V2_1_7a1a08f4_Rx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */
	if (ret != COM_SERVICE_NOT_AVAILABLE)
	{
		if (Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_BCM10_LTurnLampWorkCmd_Rx == 0)
		{
			ret = RTE_E_NEVER_RECEIVED;
		}
	}
	if (Rte_RxTimeoutFlags.Rte_RxTimeout_BCM10_LTurnLampWorkCmd_Rx != 0)
	{
		ret |= RTE_E_MAX_AGE_EXCEEDED;
	}

	return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComVnimMdl_Sig_BCM10_RTurnLmpWorkCmd_Value(uint8 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_OK;

	ret = Com_ReceiveSignal(ComConf_ComSignal_RTurnLmpWorkCmd_oBCM10_oC03_for_EL_CAN_V2_1_10ea9ba1_Rx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */
	if (ret != COM_SERVICE_NOT_AVAILABLE)
	{
		if (Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_BCM10_RTurnLmpWorkCmd_Rx == 0)
		{
			ret = RTE_E_NEVER_RECEIVED;
		}
	}
	if (Rte_RxTimeoutFlags.Rte_RxTimeout_BCM10_RTurnLmpWorkCmd_Rx != 0)
	{
		ret |= RTE_E_MAX_AGE_EXCEEDED;
	}

	return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComVnimMdl_Sig_BCM10_Rollingcounter_BCM10_Value(uint8 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_OK;

	ret = Com_ReceiveSignal(ComConf_ComSignal_Rollingcounter_BCM10_oBCM10_oC03_for_EL_CAN_V2_1_6dd2f1f9_Rx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */
	if (ret != COM_SERVICE_NOT_AVAILABLE)
	{
		if (Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_BCM10_Rollingcounter_BCM10_Rx == 0)
		{
			ret = RTE_E_NEVER_RECEIVED;
		}
	}
	if (Rte_RxTimeoutFlags.Rte_RxTimeout_BCM10_Rollingcounter_BCM10_Rx != 0)
	{
		ret |= RTE_E_MAX_AGE_EXCEEDED;
	}

	return ret;
}


FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComVnimMdl_Sig_HUT54_ChrgDispPatTypSet_Value(uint8 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_OK;

	ret = Com_ReceiveSignal(ComConf_ComSignal_ChrgDispPatTypSet_oHUT54_oC03_for_EL_CAN_V2_1_f6de33f3_Rx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */
	if (ret != COM_SERVICE_NOT_AVAILABLE)
	{
		if (Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_HUT54_ChrgDispPatTypSet_Rx == 0)
		{
			ret = RTE_E_NEVER_RECEIVED;
		}
	}
	if (Rte_RxTimeoutFlags.Rte_RxTimeout_HUT54_ChrgDispPatTypSet_Rx != 0)
	{
		ret |= RTE_E_MAX_AGE_EXCEEDED;
	}

	return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComVnimMdl_Sig_HUT54_ChrgPatDispSwt_Value(uint8 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_OK;

	ret = Com_ReceiveSignal(ComConf_ComSignal_ChrgPatDispSwt_oHUT54_oC03_for_EL_CAN_V2_1_f66d5f08_Rx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */
	if (ret != COM_SERVICE_NOT_AVAILABLE)
	{
		if (Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_HUT54_ChrgPatDispSwt_Rx == 0)
		{
			ret = RTE_E_NEVER_RECEIVED;
		}
	}
	if (Rte_RxTimeoutFlags.Rte_RxTimeout_HUT54_ChrgPatDispSwt_Rx != 0)
	{
		ret |= RTE_E_MAX_AGE_EXCEEDED;
	}

	return ret;
}


FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComVnimMdl_Sig_HUT54_EIDCSwt_Value(uint8 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_OK;

	ret = Com_ReceiveSignal(ComConf_ComSignal_EIDCSwt_oHUT54_oC03_for_EL_CAN_V2_1_ac2debcb_Rx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */
	if (ret != COM_SERVICE_NOT_AVAILABLE)
	{
		if (Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_HUT54_EIDCSwt_Rx == 0)
		{
			ret = RTE_E_NEVER_RECEIVED;
		}
	}
	if (Rte_RxTimeoutFlags.Rte_RxTimeout_HUT54_EIDCSwt_Rx != 0)
	{
		ret |= RTE_E_MAX_AGE_EXCEEDED;
	}

	return ret;
}


FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComVnimMdl_Sig_HUT54_EmojiTypSet_Value(uint8 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_OK;

	ret = Com_ReceiveSignal(ComConf_ComSignal_EmojiTypSet_oHUT54_oC03_for_EL_CAN_V2_1_ac4f7c91_Rx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */
	if (ret != COM_SERVICE_NOT_AVAILABLE)
	{
		if (Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_HUT54_EmojiTypSet_Rx == 0)
		{
			ret = RTE_E_NEVER_RECEIVED;
		}
	}
	if (Rte_RxTimeoutFlags.Rte_RxTimeout_HUT54_EmojiTypSet_Rx != 0)
	{
		ret |= RTE_E_MAX_AGE_EXCEEDED;
	}

	return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComVnimMdl_Sig_HUT54_RemindTypSet_Value(uint8 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_OK;

	ret = Com_ReceiveSignal(ComConf_ComSignal_RemindTypSet_oHUT54_oC03_for_EL_CAN_V2_1_fc32c110_Rx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */
	if (ret != COM_SERVICE_NOT_AVAILABLE)
	{
		if (Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_HUT54_RemindTypSet_Rx == 0)
		{
			ret = RTE_E_NEVER_RECEIVED;
		}
	}
	if (Rte_RxTimeoutFlags.Rte_RxTimeout_HUT54_RemindTypSet_Rx != 0)
	{
		ret |= RTE_E_MAX_AGE_EXCEEDED;
	}

	return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComVnimMdl_Sig_HUT54_TopicTypSet_Value(uint8 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_OK;

	ret = Com_ReceiveSignal(ComConf_ComSignal_TopicTypSet_oHUT54_oC03_for_EL_CAN_V2_1_71504e9d_Rx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */
	if (ret != COM_SERVICE_NOT_AVAILABLE)
	{
		if (Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_HUT54_TopicTypSet_Rx == 0)
		{
			ret = RTE_E_NEVER_RECEIVED;
		}
	}
	if (Rte_RxTimeoutFlags.Rte_RxTimeout_HUT54_TopicTypSet_Rx != 0)
	{
		ret |= RTE_E_MAX_AGE_EXCEEDED;
	}

	return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComVnimMdl_Sig_HUT54_TurnRemdSwt_Value(uint8 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_OK;

	ret = Com_ReceiveSignal(ComConf_ComSignal_TurnRemdSwt_oHUT54_oC03_for_EL_CAN_V2_1_06f5df9c_Rx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */
	if (ret != COM_SERVICE_NOT_AVAILABLE)
	{
		if (Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_HUT54_TurnRemdSwt_Rx == 0)
		{
			ret = RTE_E_NEVER_RECEIVED;
		}
	}
	if (Rte_RxTimeoutFlags.Rte_RxTimeout_HUT54_TurnRemdSwt_Rx != 0)
	{
		ret |= RTE_E_MAX_AGE_EXCEEDED;
	}

	return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComVnimMdl_Sig_HUT54_WelcomeSwt_Value(uint8 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_OK;

	ret = Com_ReceiveSignal(ComConf_ComSignal_WelcomeSwt_oHUT54_oC03_for_EL_CAN_V2_1_351ff7b4_Rx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */
	if (ret != COM_SERVICE_NOT_AVAILABLE)
	{
		if (Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_HUT54_WelcomeSwt_Rx == 0)
		{
			ret = RTE_E_NEVER_RECEIVED;
		}
	}
	if (Rte_RxTimeoutFlags.Rte_RxTimeout_HUT54_WelcomeSwt_Rx != 0)
	{
		ret |= RTE_E_MAX_AGE_EXCEEDED;
	}

	return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComVnimMdl_Sig_HUT54_WordTypSet_Value(uint8 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_OK;

	ret = Com_ReceiveSignal(ComConf_ComSignal_WordTypSet_oHUT54_oC03_for_EL_CAN_V2_1_035aa6cb_Rx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */
	if (ret != COM_SERVICE_NOT_AVAILABLE)
	{
		if (Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_HUT54_WordTypSet_Rx == 0)
		{
			ret = RTE_E_NEVER_RECEIVED;
		}
	}
	if (Rte_RxTimeoutFlags.Rte_RxTimeout_HUT54_WordTypSet_Rx != 0)
	{
		ret |= RTE_E_MAX_AGE_EXCEEDED;
	}

	return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComVnimMdl_Sig_HUT54_WelcomePatTypSet_Value(uint8 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_OK;

	ret = Com_ReceiveSignal(ComConf_ComSignal_WelcomePatTypSet_oHUT54_oC03_for_EL_CAN_V2_1_ac7026e0_Rx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */
	if (ret != COM_SERVICE_NOT_AVAILABLE)
	{
		if (Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_HUT54_WelcomePatTypSet_Rx == 0)
		{
			ret = RTE_E_NEVER_RECEIVED;
		}
	}
	if (Rte_RxTimeoutFlags.Rte_RxTimeout_HUT54_WelcomePatTypSet_Rx != 0)
	{
		ret |= RTE_E_MAX_AGE_EXCEEDED;
	}

	return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComVnimMdl_Sig_EEM1_DeepSlpCmd_Value(uint8 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_OK;

	ret = Com_ReceiveSignal(ComConf_ComSignal_DeepSlpCmd_oEEM1_oC03_for_EL_CAN_V2_1_41fb7d93_Rx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */
	if (ret != COM_SERVICE_NOT_AVAILABLE)
	{
		if (Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_EEM1_DeepSlpCmd_Rx == 0)
		{
			ret = RTE_E_NEVER_RECEIVED;
		}
	}
	if (Rte_RxTimeoutFlags.Rte_RxTimeout_EEM1_DeepSlpCmd_Rx != 0)
	{
		ret |= RTE_E_MAX_AGE_EXCEEDED;
	}

	return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComVnimMdl_Sig_EEM1_Stat_PwrSv_Lvl_Value(uint8 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_OK;

	ret = Com_ReceiveSignal(ComConf_ComSignal_Stat_PwrSv_Lvl_oEEM1_oC03_for_EL_CAN_V2_1_a4eaa63e_Rx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */
	if (ret != COM_SERVICE_NOT_AVAILABLE)
	{
		if (Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_EEM1_Stat_PwrSv_Lvl_Rx == 0)
		{
			ret = RTE_E_NEVER_RECEIVED;
		}
	}
	if (Rte_RxTimeoutFlags.Rte_RxTimeout_EEM1_Stat_PwrSv_Lvl_Rx != 0)
	{
		ret |= RTE_E_MAX_AGE_EXCEEDED;
	}

	return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComVnimMdl_Sig_EEM1_TranPMode_Sts_Value(uint8 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_OK;

	ret = Com_ReceiveSignal(ComConf_ComSignal_TranPMode_Sts_oEEM1_oC03_for_EL_CAN_V2_1_a5a3838d_Rx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */
	if (ret != COM_SERVICE_NOT_AVAILABLE)
	{
		if (Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_EEM1_TranPMode_Sts_Rx == 0)
		{
			ret = RTE_E_NEVER_RECEIVED;
		}
	}
	if (Rte_RxTimeoutFlags.Rte_RxTimeout_EEM1_TranPMode_Sts_Rx != 0)
	{
		ret |= RTE_E_MAX_AGE_EXCEEDED;
	}

	return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComVnimMdl_Sig_IP2_IP_VehTotDistanceValid_Value(uint8 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_OK;

	ret = Com_ReceiveSignal(ComConf_ComSignal_IP_VehTotDistanceValid_oIP2_oC03_for_EL_CAN_V2_1_234ac38e_Rx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */
	if (ret != COM_SERVICE_NOT_AVAILABLE)
	{
		if (Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_IP2_IP_VehTotDistanceValid_Rx == 0)
		{
			ret = RTE_E_NEVER_RECEIVED;
		}
	}
	if (Rte_RxTimeoutFlags.Rte_RxTimeout_IP2_IP_VehTotDistanceValid_Rx != 0)
	{
		ret |= RTE_E_MAX_AGE_EXCEEDED;
	}

	return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComVnimMdl_Sig_IP2_IP_VehTotDistance_Value(uint32 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_OK;

	ret = Com_ReceiveSignal(ComConf_ComSignal_IP_VehTotDistance_oIP2_oC03_for_EL_CAN_V2_1_a238a7cc_Rx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */
	if (ret != COM_SERVICE_NOT_AVAILABLE)
	{
		if (Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_IP2_IP_VehTotDistance_Rx == 0)
		{
			ret = RTE_E_NEVER_RECEIVED;
		}
	}
	if (Rte_RxTimeoutFlags.Rte_RxTimeout_IP2_IP_VehTotDistance_Rx != 0)
	{
		ret |= RTE_E_MAX_AGE_EXCEEDED;
	}

	return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComVnimMdl_Sig_CSA1_RTurnLmpSwtSts_Value(uint8 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_OK;

	ret = Com_ReceiveSignal(ComConf_ComSignal_RTurnLmpSwtSts_oCSA1_oC03_for_EL_CAN_V2_1_2fe59187_Rx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */
	if (ret != COM_SERVICE_NOT_AVAILABLE)
	{
		if (Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_CSA1_RTurnLmpSwtSts_Rx == 0)
		{
			ret = RTE_E_NEVER_RECEIVED;
		}
	}
	if (Rte_RxTimeoutFlags.Rte_RxTimeout_CSA1_RTurnLmpSwtSts_Rx != 0)
	{
		ret |= RTE_E_MAX_AGE_EXCEEDED;
	}

	return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComVnimMdl_Sig_CSA1_LTurnLmpSwtSts_Value(uint8 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_OK;

	ret = Com_ReceiveSignal(ComConf_ComSignal_LTurnLmpSwtSts_oCSA1_oC03_for_EL_CAN_V2_1_458e5c96_Rx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */
	if (ret != COM_SERVICE_NOT_AVAILABLE)
	{
		if (Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_CSA1_LTurnLmpSwtSts_Rx == 0)
		{
			ret = RTE_E_NEVER_RECEIVED;
		}
	}
	if (Rte_RxTimeoutFlags.Rte_RxTimeout_CSA1_LTurnLmpSwtSts_Rx != 0)
	{
		ret |= RTE_E_MAX_AGE_EXCEEDED;
	}

	return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComVnimMdl_Sig_RMCU4_RMCU_ActRotSpd_Value(uint16 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_OK;

	ret = Com_ReceiveSignal(ComConf_ComSignal_RMCU_ActRotSpd_oRMCU4_oC03_for_EL_CAN_V2_1_a08a2435_Rx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */
	if (ret != COM_SERVICE_NOT_AVAILABLE)
	{
		if (Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_RMCU4_RMCU_ActRotSpd_Rx == 0)
		{
			ret = RTE_E_NEVER_RECEIVED;
		}
	}
	if (Rte_RxTimeoutFlags.Rte_RxTimeout_RMCU4_RMCU_ActRotSpd_Rx != 0)
	{
		ret |= RTE_E_MAX_AGE_EXCEEDED;
	}

	return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComVnimMdl_Sig_MCU_5_MCU_ActRotSpd_Value(uint16 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_OK;

	ret = Com_ReceiveSignal(ComConf_ComSignal_MCU_ActRotSpd_oMCU_5_oC03_for_EL_CAN_V2_1_c2eb67f0_Rx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */
	if (ret != COM_SERVICE_NOT_AVAILABLE)
	{
		if (Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_MCU_5_MCU_ActRotSpd_Rx == 0)
		{
			ret = RTE_E_NEVER_RECEIVED;
		}
	}
	if (Rte_RxTimeoutFlags.Rte_RxTimeout_MCU_5_MCU_ActRotSpd_Rx != 0)
	{
		ret |= RTE_E_MAX_AGE_EXCEEDED;
	}

	return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComVnimMdl_Sig_OBC3_OBC_CCLineConnectSts_Value(uint8 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_OK;

	ret = Com_ReceiveSignal(ComConf_ComSignal_OBC_CCLineConnectSts_oOBC3_oC03_for_EL_CAN_V2_1_a7854723_Rx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */
	if (ret != COM_SERVICE_NOT_AVAILABLE)
	{
		if (Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_OBC3_OBC_CCLineConnectSts_Rx == 0)
		{
			ret = RTE_E_NEVER_RECEIVED;
		}
	}
	if (Rte_RxTimeoutFlags.Rte_RxTimeout_OBC3_OBC_CCLineConnectSts_Rx != 0)
	{
		ret |= RTE_E_MAX_AGE_EXCEEDED;
	}

	return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComVnimMdl_Sig_R_PBOX1_PosnLmpOutpSts_R_PBox_Value(uint8 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_OK;

	ret = Com_ReceiveSignal(ComConf_ComSignal_PosnLmpOutpSts_R_PBox_oR_PBOX1_oC03_for_EL_CAN_V2_1_c63ace4d_Rx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */
	if (ret != COM_SERVICE_NOT_AVAILABLE)
	{
		if (Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_R_PBOX1_PosnLmpOutpSts_R_PBox_Rx == 0)
		{
			ret = RTE_E_NEVER_RECEIVED;
		}
	}
	if (Rte_RxTimeoutFlags.Rte_RxTimeout_R_PBOX1_PosnLmpOutpSts_R_PBox_Rx != 0)
	{
		ret |= RTE_E_MAX_AGE_EXCEEDED;
	}

	return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComVnimMdl_Sig_GW1_ScenarioID_Value(uint8 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_OK;

	ret = Com_ReceiveSignal(ComConf_ComSignal_ScenarioID_oGW1_oC03_for_EL_CAN_V2_1_b0249678_Rx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */
	if (ret != COM_SERVICE_NOT_AVAILABLE)
	{
		if (Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_GW1_ScenarioID_Rx == 0)
		{
			ret = RTE_E_NEVER_RECEIVED;
		}
	}
	if (Rte_RxTimeoutFlags.Rte_RxTimeout_GW1_ScenarioID_Rx != 0)
	{
		ret |= RTE_E_MAX_AGE_EXCEEDED;
	}

	return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComVnimMdl_Sig_GW1_ScenarioReq_Value(uint8 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_OK;

	ret = Com_ReceiveSignal(ComConf_ComSignal_ScenarioReq_oGW1_oC03_for_EL_CAN_V2_1_d81adfac_Rx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */
	if (ret != COM_SERVICE_NOT_AVAILABLE)
	{
		if (Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_GW1_ScenarioReq_Rx == 0)
		{
			ret = RTE_E_NEVER_RECEIVED;
		}
	}
	if (Rte_RxTimeoutFlags.Rte_RxTimeout_GW1_ScenarioReq_Rx != 0)
	{
		ret |= RTE_E_MAX_AGE_EXCEEDED;
	}

	return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComVnimMdl_Sig_HUT34_TimeIndcn_Value(uint8 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_OK;

	ret = Com_ReceiveSignal(ComConf_ComSignal_TimeIndcn_oHUT34_oC03_for_EL_CAN_V2_1_d29435a0_Rx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */
	if (ret != COM_SERVICE_NOT_AVAILABLE)
	{
		if (Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_HUT34_TimeIndcn_Rx == 0)
		{
			ret = RTE_E_NEVER_RECEIVED;
		}
	}
	if (Rte_RxTimeoutFlags.Rte_RxTimeout_HUT34_TimeIndcn_Rx != 0)
	{
		ret |= RTE_E_MAX_AGE_EXCEEDED;
	}

	return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComVnimMdl_Sig_HUT34_TimeMod_Value(uint8 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_OK;

	ret = Com_ReceiveSignal(ComConf_ComSignal_TimeMod_oHUT34_oC03_for_EL_CAN_V2_1_baa135ee_Rx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */
	if (ret != COM_SERVICE_NOT_AVAILABLE)
	{
		if (Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_HUT34_TimeMod_Rx == 0)
		{
			ret = RTE_E_NEVER_RECEIVED;
		}
	}
	if (Rte_RxTimeoutFlags.Rte_RxTimeout_HUT34_TimeMod_Rx != 0)
	{
		ret |= RTE_E_MAX_AGE_EXCEEDED;
	}

	return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComVnimMdl_Sig_HUT34_Time_Day_Value(uint8 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_OK;

	ret = Com_ReceiveSignal(ComConf_ComSignal_Time_Day_oHUT34_oC03_for_EL_CAN_V2_1_5996a937_Rx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */
	if (ret != COM_SERVICE_NOT_AVAILABLE)
	{
		if (Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_HUT34_Time_Day_Rx == 0)
		{
			ret = RTE_E_NEVER_RECEIVED;
		}
	}
	if (Rte_RxTimeoutFlags.Rte_RxTimeout_HUT34_Time_Day_Rx != 0)
	{
		ret |= RTE_E_MAX_AGE_EXCEEDED;
	}

	return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComVnimMdl_Sig_HUT34_Time_Hour_Value(uint8 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_OK;

	ret = Com_ReceiveSignal(ComConf_ComSignal_Time_Hour_oHUT34_oC03_for_EL_CAN_V2_1_2c4ebd6a_Rx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */
	if (ret != COM_SERVICE_NOT_AVAILABLE)
	{
		if (Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_HUT34_Time_Hour_Rx == 0)
		{
			ret = RTE_E_NEVER_RECEIVED;
		}
	}
	if (Rte_RxTimeoutFlags.Rte_RxTimeout_HUT34_Time_Hour_Rx != 0)
	{
		ret |= RTE_E_MAX_AGE_EXCEEDED;
	}

	return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComVnimMdl_Sig_HUT34_Time_Minutes_Value(uint8 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_OK;

	ret = Com_ReceiveSignal(ComConf_ComSignal_Time_Minutes_oHUT34_oC03_for_EL_CAN_V2_1_da3ecd44_Rx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */
	if (ret != COM_SERVICE_NOT_AVAILABLE)
	{
		if (Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_HUT34_Time_Minutes_Rx == 0)
		{
			ret = RTE_E_NEVER_RECEIVED;
		}
	}
	if (Rte_RxTimeoutFlags.Rte_RxTimeout_HUT34_Time_Minutes_Rx != 0)
	{
		ret |= RTE_E_MAX_AGE_EXCEEDED;
	}

	return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComVnimMdl_Sig_HUT34_Time_Month_Value(uint8 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_OK;

	ret = Com_ReceiveSignal(ComConf_ComSignal_Time_Month_oHUT34_oC03_for_EL_CAN_V2_1_33ed510d_Rx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */
	if (ret != COM_SERVICE_NOT_AVAILABLE)
	{
		if (Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_HUT34_Time_Month_Rx == 0)
		{
			ret = RTE_E_NEVER_RECEIVED;
		}
	}
	if (Rte_RxTimeoutFlags.Rte_RxTimeout_HUT34_Time_Month_Rx != 0)
	{
		ret |= RTE_E_MAX_AGE_EXCEEDED;
	}

	return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComVnimMdl_Sig_HUT34_Time_Second_Value(uint8 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_OK;

	ret = Com_ReceiveSignal(ComConf_ComSignal_Time_Second_oHUT34_oC03_for_EL_CAN_V2_1_9732895b_Rx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */
	if (ret != COM_SERVICE_NOT_AVAILABLE)
	{
		if (Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_HUT34_Time_Second_Rx == 0)
		{
			ret = RTE_E_NEVER_RECEIVED;
		}
	}
	if (Rte_RxTimeoutFlags.Rte_RxTimeout_HUT34_Time_Second_Rx != 0)
	{
		ret |= RTE_E_MAX_AGE_EXCEEDED;
	}

	return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComVnimMdl_Sig_HUT34_Time_Year_Left_Value(uint8 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_OK;

	ret = Com_ReceiveSignal(ComConf_ComSignal_Time_Year_Left_oHUT34_oC03_for_EL_CAN_V2_1_f1a91267_Rx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */
	if (ret != COM_SERVICE_NOT_AVAILABLE)
	{
		if (Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_HUT34_Time_Year_Left_Rx == 0)
		{
			ret = RTE_E_NEVER_RECEIVED;
		}
	}
	if (Rte_RxTimeoutFlags.Rte_RxTimeout_HUT34_Time_Year_Left_Rx != 0)
	{
		ret |= RTE_E_MAX_AGE_EXCEEDED;
	}

	return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComVnimMdl_Sig_HUT34_Time_Year_Right_Value(uint8 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_OK;

	ret = Com_ReceiveSignal(ComConf_ComSignal_Time_Year_Right_oHUT34_oC03_for_EL_CAN_V2_1_fa890340_Rx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */
	if (ret != COM_SERVICE_NOT_AVAILABLE)
	{
		if (Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_HUT34_Time_Year_Right_Rx == 0)
		{
			ret = RTE_E_NEVER_RECEIVED;
		}
	}
	if (Rte_RxTimeoutFlags.Rte_RxTimeout_HUT34_Time_Year_Right_Rx != 0)
	{
		ret |= RTE_E_MAX_AGE_EXCEEDED;
	}

	return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComVnimMdl_Sig_VCU6_VCU_BrkPedlSts_Value(uint8 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_OK;

	ret = Com_ReceiveSignal(ComConf_ComSignal_VCU_BrkPedlSts_oVCU6_oC03_for_EL_CAN_V2_1_66fed013_Rx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */
	if (ret != COM_SERVICE_NOT_AVAILABLE)
	{
		if (Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_VCU6_VCU_BrkPedlSts_Rx == 0)
		{
			ret = RTE_E_NEVER_RECEIVED;
		}
	}
	if (Rte_RxTimeoutFlags.Rte_RxTimeout_VCU6_VCU_BrkPedlSts_Rx != 0)
	{
		ret |= RTE_E_MAX_AGE_EXCEEDED;
	}

	return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComVnimMdl_Sig_VCU3_VCU_ChrgnSts_Value(uint8 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_OK;

	ret = Com_ReceiveSignal(ComConf_ComSignal_VCU_ChrgnSts_oVCU3_oC03_for_EL_CAN_V2_1_87b3fa1f_Rx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */
	if (ret != COM_SERVICE_NOT_AVAILABLE)
	{
		if (Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_VCU3_VCU_ChrgnSts_Rx == 0)
		{
			ret = RTE_E_NEVER_RECEIVED;
		}
	}
	if (Rte_RxTimeoutFlags.Rte_RxTimeout_VCU3_VCU_ChrgnSts_Rx != 0)
	{
		ret |= RTE_E_MAX_AGE_EXCEEDED;
	}

	return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ComVnimMdl_Sig_VCU2_VCU_GearSts_Value(uint8 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_OK;

	ret = Com_ReceiveSignal(ComConf_ComSignal_VCU_GearSts_oVCU2_oC03_for_EL_CAN_V2_1_71c2293d_Rx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */
	if (ret != COM_SERVICE_NOT_AVAILABLE)
	{
		if (Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_VCU2_VCU_GearSts_Rx == 0)
		{
			ret = RTE_E_NEVER_RECEIVED;
		}
	}
	if (Rte_RxTimeoutFlags.Rte_RxTimeout_VCU2_VCU_GearSts_Rx != 0)
	{
		ret |= RTE_E_MAX_AGE_EXCEEDED;
	}

	return ret;
}


FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComVnimMdl_Sig_EIDC1_ChrgDispPatFailSts_Value(uint8 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_NOT_OK;

	ret = Com_SendSignal(ComConf_ComSignal_ChrgDispPatFailSts_oEIDC1_oC03_for_EL_CAN_V2_1_ad1e97ef_Tx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */

	return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComVnimMdl_Sig_EIDC1_CurrChrgDispSts_Value(uint8 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_NOT_OK;

	ret = Com_SendSignal(ComConf_ComSignal_CurrChrgDispSts_oEIDC1_oC03_for_EL_CAN_V2_1_b91c73c4_Tx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */

	return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComVnimMdl_Sig_EIDC1_CurrEmojiSts_Value(uint8 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_NOT_OK;

	ret = Com_SendSignal(ComConf_ComSignal_CurrEmojiSts_oEIDC1_oC03_for_EL_CAN_V2_1_6bd59cd2_Tx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */

	return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComVnimMdl_Sig_EIDC1_CurrRemdSts_Value(uint8 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_NOT_OK;

	ret = Com_SendSignal(ComConf_ComSignal_CurrRemdSts_oEIDC1_oC03_for_EL_CAN_V2_1_d08f6960_Tx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */

	return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComVnimMdl_Sig_EIDC1_CurrTopicSts_Value(uint8 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_NOT_OK;

	ret = Com_SendSignal(ComConf_ComSignal_CurrTopicSts_oEIDC1_oC03_for_EL_CAN_V2_1_fe35aa4e_Tx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */

	return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComVnimMdl_Sig_EIDC1_CurrWelcomeSts_Value(uint8 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_NOT_OK;

	ret = Com_SendSignal(ComConf_ComSignal_CurrWelcomeSts_oEIDC1_oC03_for_EL_CAN_V2_1_adc4e5a0_Tx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */

	return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComVnimMdl_Sig_EIDC1_CurrWordSts_Value(uint8 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_NOT_OK;

	ret = Com_SendSignal(ComConf_ComSignal_CurrWordSts_oEIDC1_oC03_for_EL_CAN_V2_1_141f7025_Tx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */

	return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComVnimMdl_Sig_EIDC1_EIDCOpenFBSts_Value(uint8 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_NOT_OK;

	ret = Com_SendSignal(ComConf_ComSignal_EIDCOpenFBSts_oEIDC1_oC03_for_EL_CAN_V2_1_c910b9b6_Tx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */

	return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComVnimMdl_Sig_EIDC1_TurnRemdFailSts_Value(uint8 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_NOT_OK;

	ret = Com_SendSignal(ComConf_ComSignal_TurnRemdFailSts_oEIDC1_oC03_for_EL_CAN_V2_1_5d16f6d4_Tx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */

	return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ComVnimMdl_Sig_EIDC1_WelcomePatFailSts_Value(uint8 * data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
	Std_ReturnType ret = E_NOT_OK;

	ret = Com_SendSignal(ComConf_ComSignal_WelcomePatFailSts_oEIDC1_oC03_for_EL_CAN_V2_1_29fa7824_Tx, (data)); /* PRQA S 3453 */ /* MD_MSR_19.7 */

	return ret;
}

FUNC(void, RTE_CODE) ComEx_COMCbkNr_AnimationReq_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_BCM17_AnimationReq_Rx = 1;
  Rte_RxTimeoutFlags.Rte_RxTimeout_BCM17_AnimationReq_Rx = 0;
} 

FUNC(void, RTE_CODE) ComEx_COMCbkRxTOut_AnimationReq_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  Rte_RxTimeoutFlags.Rte_RxTimeout_BCM17_AnimationReq_Rx = 1;
}


FUNC(void, RTE_CODE) ComEx_COMCbkNr_ApproachLightAnimationType_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_BCM17_ApproachLightAnimationType_Rx = 1;
  Rte_RxTimeoutFlags.Rte_RxTimeout_BCM17_ApproachLightAnimationType_Rx= 0;
} 

FUNC(void, RTE_CODE) ComEx_COMCbkRxTOut_ApproachLightAnimationType_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  Rte_RxTimeoutFlags.Rte_RxTimeout_BCM17_ApproachLightAnimationType_Rx= 1;
}


FUNC(void, RTE_CODE) ComEx_COMCbkNr_BMS_DCChrgConnect_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_BMS17_BMS_DCChrgConnect_Rx = 1;
  Rte_RxTimeoutFlags.Rte_RxTimeout_BMS17_BMS_DCChrgConnect_Rx = 0;
} 

FUNC(void, RTE_CODE) ComEx_COMCbkRxTOut_BMS_DCChrgConnect_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  Rte_RxTimeoutFlags.Rte_RxTimeout_BMS17_BMS_DCChrgConnect_Rx = 1;
}


FUNC(void, RTE_CODE) ComEx_COMCbkNr_GoodbyeAnimationType_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_BCM17_GoodbyeAnimationType_Rx = 1;
	Rte_RxTimeoutFlags.Rte_RxTimeout_BCM17_GoodbyeAnimationType_Rx = 0;
}

FUNC(void, RTE_CODE) ComEx_COMCbkRxTOut_GoodbyeAnimationType_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxTimeoutFlags.Rte_RxTimeout_BCM17_GoodbyeAnimationType_Rx = 1;
}


FUNC(void, RTE_CODE) ComEx_COMCbkNr_WelcomeAnimationType_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_BCM17_WelcomeAnimationType_Rx = 1;
	Rte_RxTimeoutFlags.Rte_RxTimeout_BCM17_WelcomeAnimationType_Rx = 0;
}

FUNC(void, RTE_CODE) ComEx_COMCbkRxTOut_WelcomeAnimationType_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxTimeoutFlags.Rte_RxTimeout_BCM17_WelcomeAnimationType_Rx = 1;
}

FUNC(void, RTE_CODE) ComEx_COMCbkNr_MecDancAnimationType_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_BCM17_MecDancAnimationType_Rx = 1;
	Rte_RxTimeoutFlags.Rte_RxTimeout_BCM17_MecDancAnimationType_Rx = 0;
}

FUNC(void, RTE_CODE) ComEx_COMCbkRxTOut_MecDancAnimationType_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxTimeoutFlags.Rte_RxTimeout_BCM17_MecDancAnimationType_Rx = 1;
}

FUNC(void, RTE_CODE) ComEx_COMCbkNr_BMS_SOC_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_BMS1_BMS_SOC_Rx = 1;
	Rte_RxTimeoutFlags.Rte_RxTimeout_BMS1_BMS_SOC_Rx = 0;
}

FUNC(void, RTE_CODE) ComEx_COMCbkRxTOut_BMS_SOC_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxTimeoutFlags.Rte_RxTimeout_BMS1_BMS_SOC_Rx = 1;
}


FUNC(void, RTE_CODE) ComEx_COMCbkNr_CEMDetminCdnSts_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_BCM23_CEMDetminCdnSts_Rx = 1;
	Rte_RxTimeoutFlags.Rte_RxTimeout_BCM23_CEMDetminCdnSts_Rx = 0;
}

FUNC(void, RTE_CODE) ComEx_COMCbkRxTOut_CEMDetminCdnSts_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxTimeoutFlags.Rte_RxTimeout_BCM23_CEMDetminCdnSts_Rx = 1;
}

FUNC(void, RTE_CODE) ComEx_COMCbkNr_CheckSum_ABS3_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_ABS3_CheckSum_ABS3_Rx = 1;
	Rte_RxTimeoutFlags.Rte_RxTimeout_ABS3_CheckSum_ABS3_Rx = 0;
}

FUNC(void, RTE_CODE) ComEx_COMCbkRxTOut_CheckSum_ABS3_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxTimeoutFlags.Rte_RxTimeout_ABS3_CheckSum_ABS3_Rx = 1;
}


FUNC(void, RTE_CODE) ComEx_COMCbkNr_RollingCounter_ABS3_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_ABS3_RollingCounter_ABS3_Rx = 1;
	Rte_RxTimeoutFlags.Rte_RxTimeout_ABS3_RollingCounter_ABS3_Rx = 0;
}

FUNC(void, RTE_CODE) ComEx_COMCbkRxTOut_RollingCounter_ABS3_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxTimeoutFlags.Rte_RxTimeout_ABS3_RollingCounter_ABS3_Rx = 1;
}

FUNC(void, RTE_CODE) ComEx_COMCbkNr_VehSpdVld_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_ABS3_VehSpdVld_Rx = 1;
	Rte_RxTimeoutFlags.Rte_RxTimeout_ABS3_VehSpdVld_Rx = 0;
}

FUNC(void, RTE_CODE) ComEx_COMCbkRxTOut_VehSpdVld_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxTimeoutFlags.Rte_RxTimeout_ABS3_VehSpdVld_Rx = 1;
}

FUNC(void, RTE_CODE) ComEx_COMCbkNr_VehSpd_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_ABS3_VehSpd_Rx = 1;
	Rte_RxTimeoutFlags.Rte_RxTimeout_ABS3_VehSpd_Rx = 0;
}

FUNC(void, RTE_CODE) ComEx_COMCbkRxTOut_VehSpd_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxTimeoutFlags.Rte_RxTimeout_ABS3_VehSpd_Rx = 1;
}

FUNC(void, RTE_CODE) ComEx_COMCbkNr_CheckSum_PEPS2_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_PEPS2_CheckSum_PEPS2_Rx = 1;
	Rte_RxTimeoutFlags.Rte_RxTimeout_PEPS2_CheckSum_PEPS2_Rx = 0;
}

FUNC(void, RTE_CODE) ComEx_COMCbkRxTOut_CheckSum_PEPS2_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxTimeoutFlags.Rte_RxTimeout_PEPS2_CheckSum_PEPS2_Rx = 1;
}


FUNC(void, RTE_CODE) ComEx_COMCbkNr_RollingCounter_PEPS2_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_PEPS2_RollingCounter_PEPS2_Rx = 1;
	Rte_RxTimeoutFlags.Rte_RxTimeout_PEPS2_RollingCounter_PEPS2_Rx = 0;
}

FUNC(void, RTE_CODE) ComEx_COMCbkRxTOut_RollingCounter_PEPS2_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxTimeoutFlags.Rte_RxTimeout_PEPS2_RollingCounter_PEPS2_Rx = 1;
}

FUNC(void, RTE_CODE) ComEx_COMCbkNr_SysPowerModVld_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_PEPS2_SysPowerModVld_Rx = 1;
	Rte_RxTimeoutFlags.Rte_RxTimeout_PEPS2_SysPowerModVld_Rx = 0;
}

FUNC(void, RTE_CODE) ComEx_COMCbkRxTOut_SysPowerModVld_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxTimeoutFlags.Rte_RxTimeout_PEPS2_SysPowerModVld_Rx = 1;
}

FUNC(void, RTE_CODE) ComEx_COMCbkNr_SysPowerMod_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_PEPS2_SysPowerMod_Rx = 1;
	Rte_RxTimeoutFlags.Rte_RxTimeout_PEPS2_SysPowerMod_Rx = 0;
}

FUNC(void, RTE_CODE) ComEx_COMCbkRxTOut_SysPowerMod_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxTimeoutFlags.Rte_RxTimeout_PEPS2_SysPowerMod_Rx = 1;
}

FUNC(void, RTE_CODE) ComEx_COMCbkNr_Checksum_BCM10_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_BCM10_Checksum_BCM10_Rx = 1;
	Rte_RxTimeoutFlags.Rte_RxTimeout_BCM10_Checksum_BCM10_Rx = 0;
}

FUNC(void, RTE_CODE) ComEx_COMCbkRxTOut_Checksum_BCM10_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxTimeoutFlags.Rte_RxTimeout_BCM10_Checksum_BCM10_Rx = 1;
}

FUNC(void, RTE_CODE) ComEx_COMCbkNr_LTurnLampWorkCmd_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_BCM10_LTurnLampWorkCmd_Rx = 1;
	Rte_RxTimeoutFlags.Rte_RxTimeout_BCM10_LTurnLampWorkCmd_Rx = 0;
}

FUNC(void, RTE_CODE) ComEx_COMCbkRxTOut_LTurnLampWorkCmd_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxTimeoutFlags.Rte_RxTimeout_BCM10_LTurnLampWorkCmd_Rx = 1;
}

FUNC(void, RTE_CODE) ComEx_COMCbkNr_RTurnLmpWorkCmd_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_BCM10_RTurnLmpWorkCmd_Rx = 1;
	Rte_RxTimeoutFlags.Rte_RxTimeout_BCM10_RTurnLmpWorkCmd_Rx = 0;
}

FUNC(void, RTE_CODE) ComEx_COMCbkRxTOut_RTurnLmpWorkCmd_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxTimeoutFlags.Rte_RxTimeout_BCM10_RTurnLmpWorkCmd_Rx = 1;
}

FUNC(void, RTE_CODE) ComEx_COMCbkNr_Rollingcounter_BCM10_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_BCM10_Rollingcounter_BCM10_Rx = 1;
	Rte_RxTimeoutFlags.Rte_RxTimeout_BCM10_Rollingcounter_BCM10_Rx = 0;
}

FUNC(void, RTE_CODE) ComEx_COMCbkRxTOut_Rollingcounter_BCM10_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxTimeoutFlags.Rte_RxTimeout_BCM10_Rollingcounter_BCM10_Rx = 1;
}


FUNC(void, RTE_CODE) ComEx_COMCbkNr_ChrgDispPatTypSet_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_HUT54_ChrgDispPatTypSet_Rx = 1;
	Rte_RxTimeoutFlags.Rte_RxTimeout_HUT54_ChrgDispPatTypSet_Rx = 0;
}


FUNC(void, RTE_CODE) ComEx_COMCbkNr_ChrgPatDispSwt_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_HUT54_ChrgPatDispSwt_Rx = 1;
	Rte_RxTimeoutFlags.Rte_RxTimeout_HUT54_ChrgPatDispSwt_Rx = 0;
}


FUNC(void, RTE_CODE) ComEx_COMCbkNr_EIDCSwt_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_HUT54_EIDCSwt_Rx = 1;
	Rte_RxTimeoutFlags.Rte_RxTimeout_HUT54_EIDCSwt_Rx = 0;
}


FUNC(void, RTE_CODE) ComEx_COMCbkNr_EmojiTypSet_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_HUT54_EmojiTypSet_Rx = 1;
	Rte_RxTimeoutFlags.Rte_RxTimeout_HUT54_EmojiTypSet_Rx = 0;
}


FUNC(void, RTE_CODE) ComEx_COMCbkNr_RemindTypSet_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_HUT54_RemindTypSet_Rx = 1;
	Rte_RxTimeoutFlags.Rte_RxTimeout_HUT54_RemindTypSet_Rx = 0;
}


FUNC(void, RTE_CODE) ComEx_COMCbkNr_TopicTypSet_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_HUT54_TopicTypSet_Rx = 1;
	Rte_RxTimeoutFlags.Rte_RxTimeout_HUT54_TopicTypSet_Rx = 0;
}


FUNC(void, RTE_CODE) ComEx_COMCbkNr_TurnRemdSwt_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_HUT54_TurnRemdSwt_Rx = 1;
	Rte_RxTimeoutFlags.Rte_RxTimeout_HUT54_TurnRemdSwt_Rx = 0;
}


FUNC(void, RTE_CODE) ComEx_COMCbkNr_WelcomeSwt_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_HUT54_WelcomeSwt_Rx = 1;
	Rte_RxTimeoutFlags.Rte_RxTimeout_HUT54_WelcomeSwt_Rx = 0;
}


FUNC(void, RTE_CODE) ComEx_COMCbkNr_WordTypSet_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_HUT54_WordTypSet_Rx = 1;
	Rte_RxTimeoutFlags.Rte_RxTimeout_HUT54_WordTypSet_Rx = 0;
}


FUNC(void, RTE_CODE) ComEx_COMCbkNr_WelcomePatTypSet_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_HUT54_WelcomePatTypSet_Rx = 1;
	Rte_RxTimeoutFlags.Rte_RxTimeout_HUT54_WelcomePatTypSet_Rx = 0;
}


FUNC(void, RTE_CODE) ComEx_COMCbkNr_DeepSlpCmd_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_EEM1_DeepSlpCmd_Rx = 1;
	Rte_RxTimeoutFlags.Rte_RxTimeout_EEM1_DeepSlpCmd_Rx = 0;
}

FUNC(void, RTE_CODE) ComEx_COMCbkRxTOut_DeepSlpCmd_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxTimeoutFlags.Rte_RxTimeout_EEM1_DeepSlpCmd_Rx = 1;
}

FUNC(void, RTE_CODE) ComEx_COMCbkNr_Stat_PwrSv_Lvl_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_EEM1_Stat_PwrSv_Lvl_Rx = 1;
	Rte_RxTimeoutFlags.Rte_RxTimeout_EEM1_Stat_PwrSv_Lvl_Rx = 0;
}

FUNC(void, RTE_CODE) ComEx_COMCbkRxTOut_Stat_PwrSv_Lvl_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxTimeoutFlags.Rte_RxTimeout_EEM1_Stat_PwrSv_Lvl_Rx = 1;
}

FUNC(void, RTE_CODE) ComEx_COMCbkNr_TranPMode_Sts_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_EEM1_TranPMode_Sts_Rx = 1;
	Rte_RxTimeoutFlags.Rte_RxTimeout_EEM1_TranPMode_Sts_Rx = 0;
}

FUNC(void, RTE_CODE) ComEx_COMCbkRxTOut_TranPMode_Sts_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxTimeoutFlags.Rte_RxTimeout_EEM1_TranPMode_Sts_Rx = 1;
}

FUNC(void, RTE_CODE) ComEx_COMCbkNr_IP_VehTotDistanceValid_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_IP2_IP_VehTotDistanceValid_Rx = 1;
	Rte_RxTimeoutFlags.Rte_RxTimeout_IP2_IP_VehTotDistanceValid_Rx = 0;
}

FUNC(void, RTE_CODE) ComEx_COMCbkRxTOut_IP_VehTotDistanceValid_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxTimeoutFlags.Rte_RxTimeout_IP2_IP_VehTotDistanceValid_Rx = 1;
}

FUNC(void, RTE_CODE) ComEx_COMCbkNr_IP_VehTotDistance_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_IP2_IP_VehTotDistance_Rx = 1;
	Rte_RxTimeoutFlags.Rte_RxTimeout_IP2_IP_VehTotDistance_Rx = 0;
}

FUNC(void, RTE_CODE) ComEx_COMCbkRxTOut_IP_VehTotDistance_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxTimeoutFlags.Rte_RxTimeout_IP2_IP_VehTotDistance_Rx = 1;
}


FUNC(void, RTE_CODE) ComEx_COMCbkNr_RTurnLmpSwtSts_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_CSA1_RTurnLmpSwtSts_Rx = 1;
	Rte_RxTimeoutFlags.Rte_RxTimeout_CSA1_RTurnLmpSwtSts_Rx = 0;
}

FUNC(void, RTE_CODE) ComEx_COMCbkRxTOut_RTurnLmpSwtSts_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxTimeoutFlags.Rte_RxTimeout_CSA1_RTurnLmpSwtSts_Rx = 1;
}

FUNC(void, RTE_CODE) ComEx_COMCbkNr_LTurnLmpSwtSts_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_CSA1_LTurnLmpSwtSts_Rx = 1;
	Rte_RxTimeoutFlags.Rte_RxTimeout_CSA1_LTurnLmpSwtSts_Rx = 0;
}

FUNC(void, RTE_CODE) ComEx_COMCbkRxTOut_LTurnLmpSwtSts_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxTimeoutFlags.Rte_RxTimeout_CSA1_LTurnLmpSwtSts_Rx = 1;
}

FUNC(void, RTE_CODE) ComEx_COMCbkNr_RMCU_ActRotSpd_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_RMCU4_RMCU_ActRotSpd_Rx = 1;
	Rte_RxTimeoutFlags.Rte_RxTimeout_RMCU4_RMCU_ActRotSpd_Rx = 0;
}

FUNC(void, RTE_CODE) ComEx_COMCbkRxTOut_RMCU_ActRotSpd_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxTimeoutFlags.Rte_RxTimeout_RMCU4_RMCU_ActRotSpd_Rx = 1;
}

FUNC(void, RTE_CODE) ComEx_COMCbkNr_MCU_ActRotSpd_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_MCU_5_MCU_ActRotSpd_Rx = 1;
	Rte_RxTimeoutFlags.Rte_RxTimeout_MCU_5_MCU_ActRotSpd_Rx = 0;
}

FUNC(void, RTE_CODE) ComEx_COMCbkRxTOut_MCU_ActRotSpd_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxTimeoutFlags.Rte_RxTimeout_MCU_5_MCU_ActRotSpd_Rx = 1;
}

FUNC(void, RTE_CODE) ComEx_COMCbkNr_OBC_CCLineConnectSts_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_OBC3_OBC_CCLineConnectSts_Rx = 1;
	Rte_RxTimeoutFlags.Rte_RxTimeout_OBC3_OBC_CCLineConnectSts_Rx = 0;
}

FUNC(void, RTE_CODE) ComEx_COMCbkRxTOut_OBC_CCLineConnectSts_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxTimeoutFlags.Rte_RxTimeout_OBC3_OBC_CCLineConnectSts_Rx = 1;
}

FUNC(void, RTE_CODE) ComEx_COMCbkNr_PosnLmpOutpSts_R_PBox_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_R_PBOX1_PosnLmpOutpSts_R_PBox_Rx = 1;
	Rte_RxTimeoutFlags.Rte_RxTimeout_R_PBOX1_PosnLmpOutpSts_R_PBox_Rx = 0;
}

FUNC(void, RTE_CODE) ComEx_COMCbkRxTOut_PosnLmpOutpSts_R_PBox_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxTimeoutFlags.Rte_RxTimeout_R_PBOX1_PosnLmpOutpSts_R_PBox_Rx = 1;
}

FUNC(void, RTE_CODE) ComEx_COMCbkNr_ScenarioID_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_GW1_ScenarioID_Rx = 1;
	Rte_RxTimeoutFlags.Rte_RxTimeout_GW1_ScenarioID_Rx = 0;
}

FUNC(void, RTE_CODE) ComEx_COMCbkRxTOut_ScenarioID_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxTimeoutFlags.Rte_RxTimeout_GW1_ScenarioID_Rx = 1;
}

FUNC(void, RTE_CODE) ComEx_COMCbkNr_ScenarioReq_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_GW1_ScenarioReq_Rx = 1;
	Rte_RxTimeoutFlags.Rte_RxTimeout_GW1_ScenarioReq_Rx = 0;
}

FUNC(void, RTE_CODE) ComEx_COMCbkRxTOut_ScenarioReq_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxTimeoutFlags.Rte_RxTimeout_GW1_ScenarioReq_Rx = 1;
}

FUNC(void, RTE_CODE) ComEx_COMCbkNr_TimeIndcn_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_HUT34_TimeIndcn_Rx = 1;
	Rte_RxTimeoutFlags.Rte_RxTimeout_HUT34_TimeIndcn_Rx = 0;
}

FUNC(void, RTE_CODE) ComEx_COMCbkRxTOut_TimeIndcn_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxTimeoutFlags.Rte_RxTimeout_HUT34_TimeIndcn_Rx = 1;
}

FUNC(void, RTE_CODE) ComEx_COMCbkNr_TimeMod_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_HUT34_TimeMod_Rx = 1;
	Rte_RxTimeoutFlags.Rte_RxTimeout_HUT34_TimeMod_Rx = 0;
}

FUNC(void, RTE_CODE) ComEx_COMCbkRxTOut_TimeMod_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxTimeoutFlags.Rte_RxTimeout_HUT34_TimeMod_Rx = 1;
}

FUNC(void, RTE_CODE) ComEx_COMCbkNr_Time_Day_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_HUT34_Time_Day_Rx = 1;
	Rte_RxTimeoutFlags.Rte_RxTimeout_HUT34_Time_Day_Rx = 0;
}

FUNC(void, RTE_CODE) ComEx_COMCbkRxTOut_Time_Day_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxTimeoutFlags.Rte_RxTimeout_HUT34_Time_Day_Rx = 1;
}

FUNC(void, RTE_CODE) ComEx_COMCbkNr_Time_Hour_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_HUT34_Time_Hour_Rx = 1;
	Rte_RxTimeoutFlags.Rte_RxTimeout_HUT34_Time_Hour_Rx = 0;
}

FUNC(void, RTE_CODE) ComEx_COMCbkRxTOut_Time_Hour_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxTimeoutFlags.Rte_RxTimeout_HUT34_Time_Hour_Rx = 1;
}

FUNC(void, RTE_CODE) ComEx_COMCbkNr_Time_Minutes_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_HUT34_Time_Minutes_Rx = 1;
	Rte_RxTimeoutFlags.Rte_RxTimeout_HUT34_Time_Minutes_Rx = 0;
}

FUNC(void, RTE_CODE) ComEx_COMCbkRxTOut_Time_Minutes_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxTimeoutFlags.Rte_RxTimeout_HUT34_Time_Minutes_Rx = 1;
}

FUNC(void, RTE_CODE) ComEx_COMCbkNr_Time_Month_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_HUT34_Time_Month_Rx = 1;
	Rte_RxTimeoutFlags.Rte_RxTimeout_HUT34_Time_Month_Rx = 0;
}

FUNC(void, RTE_CODE) ComEx_COMCbkRxTOut_Time_Month_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxTimeoutFlags.Rte_RxTimeout_HUT34_Time_Month_Rx = 1;
}

FUNC(void, RTE_CODE) ComEx_COMCbkNr_Time_Second_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_HUT34_Time_Second_Rx = 1;
	Rte_RxTimeoutFlags.Rte_RxTimeout_HUT34_Time_Second_Rx = 0;
}

FUNC(void, RTE_CODE) ComEx_COMCbkRxTOut_Time_Second_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxTimeoutFlags.Rte_RxTimeout_HUT34_Time_Second_Rx = 1;
}

FUNC(void, RTE_CODE) ComEx_COMCbkNr_Time_Year_Left_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_HUT34_Time_Year_Left_Rx = 1;
	Rte_RxTimeoutFlags.Rte_RxTimeout_HUT34_Time_Year_Left_Rx = 0;
}

FUNC(void, RTE_CODE) ComEx_COMCbkRxTOut_Time_Year_Left_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxTimeoutFlags.Rte_RxTimeout_HUT34_Time_Year_Left_Rx = 1;
}

FUNC(void, RTE_CODE) ComEx_COMCbkNr_Time_Year_Right_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_HUT34_Time_Year_Right_Rx = 1;
	Rte_RxTimeoutFlags.Rte_RxTimeout_HUT34_Time_Year_Right_Rx = 0;
}

FUNC(void, RTE_CODE) ComEx_COMCbkRxTOut_Time_Year_Right_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxTimeoutFlags.Rte_RxTimeout_HUT34_Time_Year_Right_Rx = 1;
}

FUNC(void, RTE_CODE) ComEx_COMCbkNr_VCU_BrkPedlSts_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_VCU6_VCU_BrkPedlSts_Rx = 1;
	Rte_RxTimeoutFlags.Rte_RxTimeout_VCU6_VCU_BrkPedlSts_Rx = 0;
}

FUNC(void, RTE_CODE) ComEx_COMCbkRxTOut_VCU_BrkPedlSts_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxTimeoutFlags.Rte_RxTimeout_VCU6_VCU_BrkPedlSts_Rx = 1;
}

FUNC(void, RTE_CODE) ComEx_COMCbkNr_VCU_ChrgnSts_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_VCU3_VCU_ChrgnSts_Rx = 1;
	Rte_RxTimeoutFlags.Rte_RxTimeout_VCU3_VCU_ChrgnSts_Rx = 0;
}

FUNC(void, RTE_CODE) ComEx_COMCbkRxTOut_VCU_ChrgnSts_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxTimeoutFlags.Rte_RxTimeout_VCU3_VCU_ChrgnSts_Rx = 1;
}

FUNC(void, RTE_CODE) ComEx_COMCbkNr_VCU_GearSts_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxNeverReceivedFlags.Rte_RxNeverReceived_VCU2_VCU_GearSts_Rx = 1;
	Rte_RxTimeoutFlags.Rte_RxTimeout_VCU2_VCU_GearSts_Rx = 0;
}

FUNC(void, RTE_CODE) ComEx_COMCbkRxTOut_VCU_GearSts_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	Rte_RxTimeoutFlags.Rte_RxTimeout_VCU2_VCU_GearSts_Rx = 1;
}