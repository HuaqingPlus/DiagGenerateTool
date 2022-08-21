/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: Com
 *           Program: MSR_Vector_SLP4
 *          Customer: Nobo Automotive Systems Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F7016513ABG
 *    License Scope : The usage is restricted to CBD2000298_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Appl_Cbk.h
 *   Generation Time: 2022-07-15 15:35:34
 *           Project: C03 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.24
 *
 *
 *********************************************************************************************************************/


#if !defined (APPL_CBK_H)
# define APPL_CBK_H

/**********************************************************************************************************************
  MISRA / PClint JUSTIFICATIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#include "Com_Types.h"

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTION MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
#define COM_START_SEC_APPL_CODE
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "MemMap.h"

/* Configurable notification interface prototypes */
FUNC(void, COM_APPL_CODE) ComEx_COMCbkNr_AnimationReq_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkNr_ApproachLightAnimationType_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkNr_BMS_DCChrgConnect_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkNr_BMS_SOC_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkNr_CEMDetminCdnSts_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkNr_CheckSum_ABS3_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkNr_CheckSum_PEPS2_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkNr_Checksum_BCM10_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkNr_ChrgDispPatTypSet_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkNr_ChrgPatDispSwt_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkNr_DeepSlpCmd_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkNr_EIDCSwt_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkNr_EmojiTypSet_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkNr_GoodbyeAnimationType_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkNr_IP_VehTotDistanceValid_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkNr_IP_VehTotDistance_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkNr_LTurnLampWorkCmd_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkNr_MCU_ActRotSpd_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkNr_MecDancAnimationType_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkNr_OBC_CCLineConnectSts_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkNr_PosnLmpOutpSts_R_PBox_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkNr_RMCU_ActRotSpd_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkNr_RTurnLmpSwtSts_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkNr_RTurnLmpWorkCmd_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkNr_RemindTypSet_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkNr_RollingCounter_ABS3_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkNr_RollingCounter_PEPS2_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkNr_Rollingcounter_BCM10_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkNr_ScenarioID_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkNr_ScenarioReq_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkNr_Stat_PwrSv_Lvl_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkNr_SysPowerModVld_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkNr_SysPowerMod_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkNr_TimeIndcn_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkNr_TimeMod_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkNr_Time_Day_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkNr_Time_Hour_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkNr_Time_Minutes_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkNr_Time_Month_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkNr_Time_Second_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkNr_Time_Year_Left_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkNr_Time_Year_Right_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkNr_TopicTypSet_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkNr_TranPMode_Sts_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkNr_TurnRemdSwt_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkNr_VCU_BrkPedlSts_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkNr_VCU_ChrgnSts_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkNr_VCU_GearSts_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkNr_VehSpdVld_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkNr_VehSpd_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkNr_WelcomeAnimationType_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkNr_WelcomePatTypSet_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkNr_WelcomeSwt_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkNr_WordTypSet_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkRxTOut_AnimationReq_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkRxTOut_ApproachLightAnimationType_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkRxTOut_BMS_DCChrgConnect_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkRxTOut_BMS_SOC_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkRxTOut_CEMDetminCdnSts_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkRxTOut_CheckSum_ABS3_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkRxTOut_CheckSum_PEPS2_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkRxTOut_Checksum_BCM10_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkRxTOut_DeepSlpCmd_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkRxTOut_GoodbyeAnimationType_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkRxTOut_IP_VehTotDistanceValid_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkRxTOut_IP_VehTotDistance_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkRxTOut_LTurnLampWorkCmd_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkRxTOut_LTurnLmpSwtSts_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkRxTOut_MCU_ActRotSpd_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkRxTOut_MecDancAnimationType_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkRxTOut_OBC_CCLineConnectSts_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkRxTOut_PosnLmpOutpSts_R_PBox_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkRxTOut_RMCU_ActRotSpd_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkRxTOut_RTurnLmpSwtSts_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkRxTOut_RTurnLmpWorkCmd_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkRxTOut_RollingCounter_ABS3_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkRxTOut_RollingCounter_PEPS2_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkRxTOut_Rollingcounter_BCM10_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkRxTOut_ScenarioID_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkRxTOut_ScenarioReq_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkRxTOut_Stat_PwrSv_Lvl_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkRxTOut_SysPowerModVld_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkRxTOut_SysPowerMod_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkRxTOut_TimeIndcn_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkRxTOut_TimeMod_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkRxTOut_Time_Day_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkRxTOut_Time_Hour_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkRxTOut_Time_Minutes_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkRxTOut_Time_Month_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkRxTOut_Time_Second_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkRxTOut_Time_Year_Left_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkRxTOut_Time_Year_Right_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkRxTOut_TranPMode_Sts_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkRxTOut_VCU_BrkPedlSts_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkRxTOut_VCU_ChrgnSts_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkRxTOut_VCU_GearSts_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkRxTOut_VehSpdVld_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkRxTOut_VehSpd_Rx(void);
FUNC(void, COM_APPL_CODE) ComEx_COMCbkRxTOut_WelcomeAnimationType_Rx(void);


#define COM_STOP_SEC_APPL_CODE
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "MemMap.h"

#endif  /* APPL_CBK_H */
/**********************************************************************************************************************
  END OF FILE: Appl_Cbk.h
**********************************************************************************************************************/

