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
 *              File: Com_Lcfg.c
 *   Generation Time: 2022-07-21 09:20:10
 *           Project: C03 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.24
 *
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
  MISRA / PClint JUSTIFICATIONS
**********************************************************************************************************************/
/* PRQA  S 1881 EOF */ /* MD_MSR_AutosarBoolean */
/* PRQA  S 1882 EOF */ /* MD_MSR_AutosarBoolean */

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#define V_IL_ASRCOMCFG5_LCFG_SOURCE

#include "Com.h"

#include "Com_Lcfg.h"

#include "Appl_Cbk.h"

#include "SchM_Com.h"

/**********************************************************************************************************************
  LOCAL CONSTANT MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL FUNCTION MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  LOCAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  Com_CbkRxTOutFuncPtr
**********************************************************************************************************************/
/** 
  \var    Com_CbkRxTOutFuncPtr
  \brief  Function pointer table containing configured Rx timeout notifications for signals and signal groups.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(ComCbkRxTOutType, COM_CONST) Com_CbkRxTOutFuncPtr[45] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     CbkRxTOutFuncPtr                                      Referable Keys */
  /*     0 */ ComEx_COMCbkRxTOut_CheckSum_ABS3_Rx              ,  /* [/ActiveEcuC/Com/ComConfig/ABS3_oC03_for_EL_CAN_V2_1_5328da88_Rx] */
  /*     1 */ ComEx_COMCbkRxTOut_RollingCounter_ABS3_Rx        ,  /* [/ActiveEcuC/Com/ComConfig/ABS3_oC03_for_EL_CAN_V2_1_5328da88_Rx] */
  /*     2 */ ComEx_COMCbkRxTOut_VehSpdVld_Rx                  ,  /* [/ActiveEcuC/Com/ComConfig/ABS3_oC03_for_EL_CAN_V2_1_5328da88_Rx] */
  /*     3 */ ComEx_COMCbkRxTOut_VehSpd_Rx                     ,  /* [/ActiveEcuC/Com/ComConfig/ABS3_oC03_for_EL_CAN_V2_1_5328da88_Rx] */
  /*     4 */ ComEx_COMCbkRxTOut_Checksum_BCM10_Rx             ,  /* [/ActiveEcuC/Com/ComConfig/BCM10_oC03_for_EL_CAN_V2_1_8175742c_Rx] */
  /*     5 */ ComEx_COMCbkRxTOut_LTurnLampWorkCmd_Rx           ,  /* [/ActiveEcuC/Com/ComConfig/BCM10_oC03_for_EL_CAN_V2_1_8175742c_Rx] */
  /*     6 */ ComEx_COMCbkRxTOut_RTurnLmpWorkCmd_Rx            ,  /* [/ActiveEcuC/Com/ComConfig/BCM10_oC03_for_EL_CAN_V2_1_8175742c_Rx] */
  /*     7 */ ComEx_COMCbkRxTOut_Rollingcounter_BCM10_Rx       ,  /* [/ActiveEcuC/Com/ComConfig/BCM10_oC03_for_EL_CAN_V2_1_8175742c_Rx] */
  /*     8 */ ComEx_COMCbkRxTOut_AnimationReq_Rx               ,  /* [/ActiveEcuC/Com/ComConfig/BCM17_oC03_for_EL_CAN_V2_1_e4ac4a6c_Rx] */
  /*     9 */ ComEx_COMCbkRxTOut_ApproachLightAnimationType_Rx ,  /* [/ActiveEcuC/Com/ComConfig/BCM17_oC03_for_EL_CAN_V2_1_e4ac4a6c_Rx] */
  /*    10 */ ComEx_COMCbkRxTOut_GoodbyeAnimationType_Rx       ,  /* [/ActiveEcuC/Com/ComConfig/BCM17_oC03_for_EL_CAN_V2_1_e4ac4a6c_Rx] */
  /*    11 */ ComEx_COMCbkRxTOut_MecDancAnimationType_Rx       ,  /* [/ActiveEcuC/Com/ComConfig/BCM17_oC03_for_EL_CAN_V2_1_e4ac4a6c_Rx] */
  /*    12 */ ComEx_COMCbkRxTOut_WelcomeAnimationType_Rx       ,  /* [/ActiveEcuC/Com/ComConfig/BCM17_oC03_for_EL_CAN_V2_1_e4ac4a6c_Rx] */
  /*    13 */ ComEx_COMCbkRxTOut_CEMDetminCdnSts_Rx            ,  /* [/ActiveEcuC/Com/ComConfig/BCM23_oC03_for_EL_CAN_V2_1_cee8e051_Rx] */
  /*    14 */ ComEx_COMCbkRxTOut_BMS_SOC_Rx                    ,  /* [/ActiveEcuC/Com/ComConfig/BMS1_oC03_for_EL_CAN_V2_1_ab80ae92_Rx] */
  /*    15 */ ComEx_COMCbkRxTOut_BMS_DCChrgConnect_Rx          ,  /* [/ActiveEcuC/Com/ComConfig/BMS17_oC03_for_EL_CAN_V2_1_be27a4ae_Rx] */
  /*    16 */ ComEx_COMCbkRxTOut_LTurnLmpSwtSts_Rx             ,  /* [/ActiveEcuC/Com/ComConfig/CSA1_oC03_for_EL_CAN_V2_1_ffb47aea_Rx] */
  /*    17 */ ComEx_COMCbkRxTOut_RTurnLmpSwtSts_Rx             ,  /* [/ActiveEcuC/Com/ComConfig/CSA1_oC03_for_EL_CAN_V2_1_ffb47aea_Rx] */
  /*    18 */ ComEx_COMCbkRxTOut_DeepSlpCmd_Rx                 ,  /* [/ActiveEcuC/Com/ComConfig/EEM1_oC03_for_EL_CAN_V2_1_5bdcd994_Rx] */
  /*    19 */ ComEx_COMCbkRxTOut_Stat_PwrSv_Lvl_Rx             ,  /* [/ActiveEcuC/Com/ComConfig/EEM1_oC03_for_EL_CAN_V2_1_5bdcd994_Rx] */
  /*    20 */ ComEx_COMCbkRxTOut_TranPMode_Sts_Rx              ,  /* [/ActiveEcuC/Com/ComConfig/EEM1_oC03_for_EL_CAN_V2_1_5bdcd994_Rx] */
  /*    21 */ ComEx_COMCbkRxTOut_ScenarioID_Rx                 ,  /* [/ActiveEcuC/Com/ComConfig/GW1_oC03_for_EL_CAN_V2_1_48654b76_Rx] */
  /*    22 */ ComEx_COMCbkRxTOut_ScenarioReq_Rx                ,  /* [/ActiveEcuC/Com/ComConfig/GW1_oC03_for_EL_CAN_V2_1_48654b76_Rx] */
  /*    23 */ ComEx_COMCbkRxTOut_TimeIndcn_Rx                  ,  /* [/ActiveEcuC/Com/ComConfig/HUT34_oC03_for_EL_CAN_V2_1_6fae3f7a_Rx] */
  /*    24 */ ComEx_COMCbkRxTOut_TimeMod_Rx                    ,  /* [/ActiveEcuC/Com/ComConfig/HUT34_oC03_for_EL_CAN_V2_1_6fae3f7a_Rx] */
  /*    25 */ ComEx_COMCbkRxTOut_Time_Day_Rx                   ,  /* [/ActiveEcuC/Com/ComConfig/HUT34_oC03_for_EL_CAN_V2_1_6fae3f7a_Rx] */
  /*    26 */ ComEx_COMCbkRxTOut_Time_Hour_Rx                  ,  /* [/ActiveEcuC/Com/ComConfig/HUT34_oC03_for_EL_CAN_V2_1_6fae3f7a_Rx] */
  /*    27 */ ComEx_COMCbkRxTOut_Time_Minutes_Rx               ,  /* [/ActiveEcuC/Com/ComConfig/HUT34_oC03_for_EL_CAN_V2_1_6fae3f7a_Rx] */
  /*    28 */ ComEx_COMCbkRxTOut_Time_Month_Rx                 ,  /* [/ActiveEcuC/Com/ComConfig/HUT34_oC03_for_EL_CAN_V2_1_6fae3f7a_Rx] */
  /*    29 */ ComEx_COMCbkRxTOut_Time_Second_Rx                ,  /* [/ActiveEcuC/Com/ComConfig/HUT34_oC03_for_EL_CAN_V2_1_6fae3f7a_Rx] */
  /*    30 */ ComEx_COMCbkRxTOut_Time_Year_Left_Rx             ,  /* [/ActiveEcuC/Com/ComConfig/HUT34_oC03_for_EL_CAN_V2_1_6fae3f7a_Rx] */
  /*    31 */ ComEx_COMCbkRxTOut_Time_Year_Right_Rx            ,  /* [/ActiveEcuC/Com/ComConfig/HUT34_oC03_for_EL_CAN_V2_1_6fae3f7a_Rx] */
  /*    32 */ ComEx_COMCbkRxTOut_IP_VehTotDistanceValid_Rx     ,  /* [/ActiveEcuC/Com/ComConfig/IP2_oC03_for_EL_CAN_V2_1_65941076_Rx] */
  /*    33 */ ComEx_COMCbkRxTOut_IP_VehTotDistance_Rx          ,  /* [/ActiveEcuC/Com/ComConfig/IP2_oC03_for_EL_CAN_V2_1_65941076_Rx] */
  /*    34 */ ComEx_COMCbkRxTOut_MCU_ActRotSpd_Rx              ,  /* [/ActiveEcuC/Com/ComConfig/MCU_5_oC03_for_EL_CAN_V2_1_002cb201_Rx] */
  /*    35 */ ComEx_COMCbkRxTOut_OBC_CCLineConnectSts_Rx       ,  /* [/ActiveEcuC/Com/ComConfig/OBC3_oC03_for_EL_CAN_V2_1_158aa3d5_Rx] */
  /*    36 */ ComEx_COMCbkRxTOut_CheckSum_PEPS2_Rx             ,  /* [/ActiveEcuC/Com/ComConfig/PEPS2_oC03_for_EL_CAN_V2_1_d41abfa7_Rx] */
  /*    37 */ ComEx_COMCbkRxTOut_RollingCounter_PEPS2_Rx       ,  /* [/ActiveEcuC/Com/ComConfig/PEPS2_oC03_for_EL_CAN_V2_1_d41abfa7_Rx] */
  /*    38 */ ComEx_COMCbkRxTOut_SysPowerModVld_Rx             ,  /* [/ActiveEcuC/Com/ComConfig/PEPS2_oC03_for_EL_CAN_V2_1_d41abfa7_Rx] */
  /*    39 */ ComEx_COMCbkRxTOut_SysPowerMod_Rx                ,  /* [/ActiveEcuC/Com/ComConfig/PEPS2_oC03_for_EL_CAN_V2_1_d41abfa7_Rx] */
  /*    40 */ ComEx_COMCbkRxTOut_RMCU_ActRotSpd_Rx             ,  /* [/ActiveEcuC/Com/ComConfig/RMCU4_oC03_for_EL_CAN_V2_1_55159990_Rx] */
  /*    41 */ ComEx_COMCbkRxTOut_PosnLmpOutpSts_R_PBox_Rx      ,  /* [/ActiveEcuC/Com/ComConfig/R_PBOX1_oC03_for_EL_CAN_V2_1_7854cc6e_Rx] */
  /*    42 */ ComEx_COMCbkRxTOut_VCU_GearSts_Rx                ,  /* [/ActiveEcuC/Com/ComConfig/VCU2_oC03_for_EL_CAN_V2_1_bea872d3_Rx] */
  /*    43 */ ComEx_COMCbkRxTOut_VCU_ChrgnSts_Rx               ,  /* [/ActiveEcuC/Com/ComConfig/VCU3_oC03_for_EL_CAN_V2_1_a9801613_Rx] */
  /*    44 */ ComEx_COMCbkRxTOut_VCU_BrkPedlSts_Rx                /* [/ActiveEcuC/Com/ComConfig/VCU6_oC03_for_EL_CAN_V2_1_e209e1d3_Rx] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_ConstValueUInt16
**********************************************************************************************************************/
/** 
  \var    Com_ConstValueUInt16
  \brief  Optimized array of commonly used values like initial or invalid values. (UINT16)
*/ 
#define COM_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_ConstValueUInt16Type, COM_CONST) Com_ConstValueUInt16[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     ConstValueUInt16      Referable Keys */
  /*     0 */           0x0000u   /* [/ActiveEcuC/Com/ComConfig/BMS_SOC_oBMS1_oC03_for_EL_CAN_V2_1_a261d1ce_RxInitValue, /ActiveEcuC/Com/ComConfig/MCU_ActRotSpd_oMCU_5_oC03_for_EL_CAN_V2_1_c2eb67f0_RxInitValue, /ActiveEcuC/Com/ComConfig/RMCU_ActRotSpd_oRMCU4_oC03_for_EL_CAN_V2_1_a08a2435_RxInitValue, /ActiveEcuC/Com/ComConfig/VehSpd_oABS3_oC03_for_EL_CAN_V2_1_23260d94_RxInitValue] */
};
#define COM_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_ConstValueUInt32
**********************************************************************************************************************/
/** 
  \var    Com_ConstValueUInt32
  \brief  Optimized array of commonly used values like initial or invalid values. (UINT32)
*/ 
#define COM_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_ConstValueUInt32Type, COM_CONST) Com_ConstValueUInt32[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     ConstValueUInt32      Referable Keys */
  /*     0 */       0x00000000u   /* [/ActiveEcuC/Com/ComConfig/IP_VehTotDistance_oIP2_oC03_for_EL_CAN_V2_1_a238a7cc_RxInitValue] */
};
#define COM_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_ConstValueUInt8
**********************************************************************************************************************/
/** 
  \var    Com_ConstValueUInt8
  \brief  Optimized array of commonly used values like initial or invalid values. (BOOLEAN, UINT8)
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_ConstValueUInt8Type, COM_CONST) Com_ConstValueUInt8[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     ConstValueUInt8      Referable Keys */
  /*     0 */            0x00u   /* [/ActiveEcuC/Com/ComConfig/AnimationReq_oBCM17_oC03_for_EL_CAN_V2_1_1db28c46_RxInitValue, /ActiveEcuC/Com/ComConfig/ApproachLightAnimationType_oBCM17_oC03_for_EL_CAN_V2_1_5b20a81e_RxInitValue, /ActiveEcuC/Com/ComConfig/BMS_DCChrgConnect_oBMS17_oC03_for_EL_CAN_V2_1_91db617c_RxInitValue, /ActiveEcuC/Com/ComConfig/CEMDetminCdnSts_oBCM23_oC03_for_EL_CAN_V2_1_df6348d5_RxInitValue, /ActiveEcuC/Com/ComConfig/CheckSum_ABS3_oABS3_oC03_for_EL_CAN_V2_1_5745e086_RxInitValue, /ActiveEcuC/Com/ComConfig/CheckSum_PEPS2_oPEPS2_oC03_for_EL_CAN_V2_1_06064851_RxInitValue, /ActiveEcuC/Com/ComConfig/Checksum_BCM10_oBCM10_oC03_for_EL_CAN_V2_1_819e75d3_RxInitValue, /ActiveEcuC/Com/ComConfig/ChrgDispPatTypSet_oHUT54_oC03_for_EL_CAN_V2_1_f6de33f3_RxInitValue, /ActiveEcuC/Com/ComConfig/ChrgPatDispSwt_oHUT54_oC03_for_EL_CAN_V2_1_f66d5f08_RxInitValue, /ActiveEcuC/Com/ComConfig/DeepSlpCmd_oEEM1_oC03_for_EL_CAN_V2_1_41fb7d93_RxInitValue, /ActiveEcuC/Com/ComConfig/EIDCSwt_oHUT54_oC03_for_EL_CAN_V2_1_ac2debcb_RxInitValue, /ActiveEcuC/Com/ComConfig/EmojiTypSet_oHUT54_oC03_for_EL_CAN_V2_1_ac4f7c91_RxInitValue, /ActiveEcuC/Com/ComConfig/GoodbyeAnimationType_oBCM17_oC03_for_EL_CAN_V2_1_bc8c4dab_RxInitValue, /ActiveEcuC/Com/ComConfig/IP_VehTotDistanceValid_oIP2_oC03_for_EL_CAN_V2_1_234ac38e_RxInitValue, /ActiveEcuC/Com/ComConfig/LTurnLampWorkCmd_oBCM10_oC03_for_EL_CAN_V2_1_7a1a08f4_RxInitValue, /ActiveEcuC/Com/ComConfig/LTurnLmpSwtSts_oCSA1_oC03_for_EL_CAN_V2_1_458e5c96_RxInitValue, /ActiveEcuC/Com/ComConfig/MecDancAnimationType_oBCM17_oC03_for_EL_CAN_V2_1_6bb5a98f_RxInitValue, /ActiveEcuC/Com/ComConfig/OBC_CCLineConnectSts_oOBC3_oC03_for_EL_CAN_V2_1_a7854723_RxInitValue, /ActiveEcuC/Com/ComConfig/PosnLmpOutpSts_R_PBox_oR_PBOX1_oC03_for_EL_CAN_V2_1_c63ace4d_RxInitValue, /ActiveEcuC/Com/ComConfig/RTurnLmpSwtSts_oCSA1_oC03_for_EL_CAN_V2_1_2fe59187_RxInitValue, /ActiveEcuC/Com/ComConfig/RTurnLmpWorkCmd_oBCM10_oC03_for_EL_CAN_V2_1_10ea9ba1_RxInitValue, /ActiveEcuC/Com/ComConfig/RemindTypSet_oHUT54_oC03_for_EL_CAN_V2_1_fc32c110_RxInitValue, /ActiveEcuC/Com/ComConfig/RollingCounter_ABS3_oABS3_oC03_for_EL_CAN_V2_1_b6ac7000_RxInitValue, /ActiveEcuC/Com/ComConfig/RollingCounter_PEPS2_oPEPS2_oC03_for_EL_CAN_V2_1_9bd00531_RxInitValue, /ActiveEcuC/Com/ComConfig/Rollingcounter_BCM10_oBCM10_oC03_for_EL_CAN_V2_1_6dd2f1f9_RxInitValue, /ActiveEcuC/Com/ComConfig/ScenarioID_oGW1_oC03_for_EL_CAN_V2_1_b0249678_RxInitValue, /ActiveEcuC/Com/ComConfig/ScenarioReq_oGW1_oC03_for_EL_CAN_V2_1_d81adfac_RxInitValue, /ActiveEcuC/Com/ComConfig/Stat_PwrSv_Lvl_oEEM1_oC03_for_EL_CAN_V2_1_a4eaa63e_RxInitValue, /ActiveEcuC/Com/ComConfig/SysPowerModVld_oPEPS2_oC03_for_EL_CAN_V2_1_b6c20e3c_RxInitValue, /ActiveEcuC/Com/ComConfig/SysPowerMod_oPEPS2_oC03_for_EL_CAN_V2_1_37fb939a_RxInitValue, /ActiveEcuC/Com/ComConfig/TimeIndcn_oHUT34_oC03_for_EL_CAN_V2_1_d29435a0_RxInitValue, /ActiveEcuC/Com/ComConfig/TimeMod_oHUT34_oC03_for_EL_CAN_V2_1_baa135ee_RxInitValue, /ActiveEcuC/Com/ComConfig/Time_Day_oHUT34_oC03_for_EL_CAN_V2_1_5996a937_RxInitValue, /ActiveEcuC/Com/ComConfig/Time_Hour_oHUT34_oC03_for_EL_CAN_V2_1_2c4ebd6a_RxInitValue, /ActiveEcuC/Com/ComConfig/Time_Minutes_oHUT34_oC03_for_EL_CAN_V2_1_da3ecd44_RxInitValue, /ActiveEcuC/Com/ComConfig/Time_Month_oHUT34_oC03_for_EL_CAN_V2_1_33ed510d_RxInitValue, /ActiveEcuC/Com/ComConfig/Time_Second_oHUT34_oC03_for_EL_CAN_V2_1_9732895b_RxInitValue, /ActiveEcuC/Com/ComConfig/Time_Year_Left_oHUT34_oC03_for_EL_CAN_V2_1_f1a91267_RxInitValue, /ActiveEcuC/Com/ComConfig/Time_Year_Right_oHUT34_oC03_for_EL_CAN_V2_1_fa890340_RxInitValue, /ActiveEcuC/Com/ComConfig/TopicTypSet_oHUT54_oC03_for_EL_CAN_V2_1_71504e9d_RxInitValue, /ActiveEcuC/Com/ComConfig/TranPMode_Sts_oEEM1_oC03_for_EL_CAN_V2_1_a5a3838d_RxInitValue, /ActiveEcuC/Com/ComConfig/TurnRemdSwt_oHUT54_oC03_for_EL_CAN_V2_1_06f5df9c_RxInitValue, /ActiveEcuC/Com/ComConfig/VCU_BrkPedlSts_oVCU6_oC03_for_EL_CAN_V2_1_66fed013_RxInitValue, /ActiveEcuC/Com/ComConfig/VCU_ChrgnSts_oVCU3_oC03_for_EL_CAN_V2_1_87b3fa1f_RxInitValue, /ActiveEcuC/Com/ComConfig/VCU_GearSts_oVCU2_oC03_for_EL_CAN_V2_1_71c2293d_RxInitValue, /ActiveEcuC/Com/ComConfig/VehSpdVld_oABS3_oC03_for_EL_CAN_V2_1_32497dd3_RxInitValue, /ActiveEcuC/Com/ComConfig/WelcomeAnimationType_oBCM17_oC03_for_EL_CAN_V2_1_c76d0f7a_RxInitValue, /ActiveEcuC/Com/ComConfig/WelcomePatTypSet_oHUT54_oC03_for_EL_CAN_V2_1_ac7026e0_RxInitValue, /ActiveEcuC/Com/ComConfig/WelcomeSwt_oHUT54_oC03_for_EL_CAN_V2_1_351ff7b4_RxInitValue, /ActiveEcuC/Com/ComConfig/WordTypSet_oHUT54_oC03_for_EL_CAN_V2_1_035aa6cb_RxInitValue] */
};
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_IPduGroupInfo
**********************************************************************************************************************/
/** 
  \var    Com_IPduGroupInfo
  \brief  Contains all I-Pdu Group relevant information
  \details
  Element                 Description
  TxPduInfoIndUsed        TRUE, if the 0:n relation has 1 relation pointing to Com_TxPduInfoInd
  RxPduInfoIndEndIdx      the end index of the 0:n relation pointing to Com_RxPduInfoInd
  RxPduInfoIndStartIdx    the start index of the 0:n relation pointing to Com_RxPduInfoInd
  TxPduInfoIndEndIdx      the end index of the 0:n relation pointing to Com_TxPduInfoInd
  TxPduInfoIndStartIdx    the start index of the 0:n relation pointing to Com_TxPduInfoInd
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_IPduGroupInfoType, COM_CONST) Com_IPduGroupInfo[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    TxPduInfoIndUsed  RxPduInfoIndEndIdx                        RxPduInfoIndStartIdx                        TxPduInfoIndEndIdx                        TxPduInfoIndStartIdx                              Referable Keys */
  { /*     0 */            FALSE,                                      20u,                                         0u, COM_NO_TXPDUINFOINDENDIDXOFIPDUGROUPINFO, COM_NO_TXPDUINFOINDSTARTIDXOFIPDUGROUPINFO },  /* [/ActiveEcuC/Com/ComConfig/EIDC_oC03_for_EL_CAN_V2_1_Rx_0f13cc3b, /ActiveEcuC/Com/ComConfig/RMCU4_oC03_for_EL_CAN_V2_1_55159990_Rx, /ActiveEcuC/Com/ComConfig/BCM17_oC03_for_EL_CAN_V2_1_e4ac4a6c_Rx, /ActiveEcuC/Com/ComConfig/PEPS2_oC03_for_EL_CAN_V2_1_d41abfa7_Rx, /ActiveEcuC/Com/ComConfig/BCM10_oC03_for_EL_CAN_V2_1_8175742c_Rx, /ActiveEcuC/Com/ComConfig/CSA1_oC03_for_EL_CAN_V2_1_ffb47aea_Rx, /ActiveEcuC/Com/ComConfig/VCU2_oC03_for_EL_CAN_V2_1_bea872d3_Rx, /ActiveEcuC/Com/ComConfig/OBC3_oC03_for_EL_CAN_V2_1_158aa3d5_Rx, /ActiveEcuC/Com/ComConfig/HUT34_oC03_for_EL_CAN_V2_1_6fae3f7a_Rx, /ActiveEcuC/Com/ComConfig/HUT54_oC03_for_EL_CAN_V2_1_82644d00_Rx, /ActiveEcuC/Com/ComConfig/MCU_5_oC03_for_EL_CAN_V2_1_002cb201_Rx, /ActiveEcuC/Com/ComConfig/BMS17_oC03_for_EL_CAN_V2_1_be27a4ae_Rx, /ActiveEcuC/Com/ComConfig/GW1_oC03_for_EL_CAN_V2_1_48654b76_Rx, /ActiveEcuC/Com/ComConfig/VCU3_oC03_for_EL_CAN_V2_1_a9801613_Rx, /ActiveEcuC/Com/ComConfig/ABS3_oC03_for_EL_CAN_V2_1_5328da88_Rx, /ActiveEcuC/Com/ComConfig/R_PBOX1_oC03_for_EL_CAN_V2_1_7854cc6e_Rx, /ActiveEcuC/Com/ComConfig/EEM1_oC03_for_EL_CAN_V2_1_5bdcd994_Rx, /ActiveEcuC/Com/ComConfig/IP2_oC03_for_EL_CAN_V2_1_65941076_Rx, /ActiveEcuC/Com/ComConfig/BCM23_oC03_for_EL_CAN_V2_1_cee8e051_Rx, /ActiveEcuC/Com/ComConfig/BMS1_oC03_for_EL_CAN_V2_1_ab80ae92_Rx, /ActiveEcuC/Com/ComConfig/VCU6_oC03_for_EL_CAN_V2_1_e209e1d3_Rx] */
  { /*     1 */             TRUE, COM_NO_RXPDUINFOINDENDIDXOFIPDUGROUPINFO, COM_NO_RXPDUINFOINDSTARTIDXOFIPDUGROUPINFO,                                       1u,                                         0u }   /* [/ActiveEcuC/Com/ComConfig/EIDC_oC03_for_EL_CAN_V2_1_Tx_59496bbd, /ActiveEcuC/Com/ComConfig/EIDC1_oC03_for_EL_CAN_V2_1_4a10c7b4_Tx] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_IPduGroupInfoOfRxPduInfoInd
**********************************************************************************************************************/
/** 
  \var    Com_IPduGroupInfoOfRxPduInfoInd
  \brief  the indexes of the 1:1 sorted relation pointing to Com_IPduGroupInfo
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_IPduGroupInfoOfRxPduInfoIndType, COM_CONST) Com_IPduGroupInfoOfRxPduInfoInd[20] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     IPduGroupInfoOfRxPduInfoInd      Referable Keys */
  /*     0 */                           0u,  /* [/ActiveEcuC/Com/ComConfig/ABS3_oC03_for_EL_CAN_V2_1_5328da88_Rx] */
  /*     1 */                           0u,  /* [/ActiveEcuC/Com/ComConfig/BCM10_oC03_for_EL_CAN_V2_1_8175742c_Rx] */
  /*     2 */                           0u,  /* [/ActiveEcuC/Com/ComConfig/BCM17_oC03_for_EL_CAN_V2_1_e4ac4a6c_Rx] */
  /*     3 */                           0u,  /* [/ActiveEcuC/Com/ComConfig/BCM23_oC03_for_EL_CAN_V2_1_cee8e051_Rx] */
  /*     4 */                           0u,  /* [/ActiveEcuC/Com/ComConfig/BMS1_oC03_for_EL_CAN_V2_1_ab80ae92_Rx] */
  /*     5 */                           0u,  /* [/ActiveEcuC/Com/ComConfig/BMS17_oC03_for_EL_CAN_V2_1_be27a4ae_Rx] */
  /*     6 */                           0u,  /* [/ActiveEcuC/Com/ComConfig/CSA1_oC03_for_EL_CAN_V2_1_ffb47aea_Rx] */
  /*     7 */                           0u,  /* [/ActiveEcuC/Com/ComConfig/EEM1_oC03_for_EL_CAN_V2_1_5bdcd994_Rx] */
  /*     8 */                           0u,  /* [/ActiveEcuC/Com/ComConfig/GW1_oC03_for_EL_CAN_V2_1_48654b76_Rx] */
  /*     9 */                           0u,  /* [/ActiveEcuC/Com/ComConfig/HUT34_oC03_for_EL_CAN_V2_1_6fae3f7a_Rx] */
  /*    10 */                           0u,  /* [/ActiveEcuC/Com/ComConfig/HUT54_oC03_for_EL_CAN_V2_1_82644d00_Rx] */
  /*    11 */                           0u,  /* [/ActiveEcuC/Com/ComConfig/IP2_oC03_for_EL_CAN_V2_1_65941076_Rx] */
  /*    12 */                           0u,  /* [/ActiveEcuC/Com/ComConfig/MCU_5_oC03_for_EL_CAN_V2_1_002cb201_Rx] */
  /*    13 */                           0u,  /* [/ActiveEcuC/Com/ComConfig/OBC3_oC03_for_EL_CAN_V2_1_158aa3d5_Rx] */
  /*    14 */                           0u,  /* [/ActiveEcuC/Com/ComConfig/PEPS2_oC03_for_EL_CAN_V2_1_d41abfa7_Rx] */
  /*    15 */                           0u,  /* [/ActiveEcuC/Com/ComConfig/RMCU4_oC03_for_EL_CAN_V2_1_55159990_Rx] */
  /*    16 */                           0u,  /* [/ActiveEcuC/Com/ComConfig/R_PBOX1_oC03_for_EL_CAN_V2_1_7854cc6e_Rx] */
  /*    17 */                           0u,  /* [/ActiveEcuC/Com/ComConfig/VCU2_oC03_for_EL_CAN_V2_1_bea872d3_Rx] */
  /*    18 */                           0u,  /* [/ActiveEcuC/Com/ComConfig/VCU3_oC03_for_EL_CAN_V2_1_a9801613_Rx] */
  /*    19 */                           0u   /* [/ActiveEcuC/Com/ComConfig/VCU6_oC03_for_EL_CAN_V2_1_e209e1d3_Rx] */
};
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxAccessInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxAccessInfo
  \brief  Contains all signal layout information necessary for signal access within an I-PDU.
  \details
  Element                   Description
  InitValueUsed             TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_ConstValueUInt8,Com_ConstValueUInt16,Com_ConstValueUInt32,Com_ConstValueUInt64,Com_ConstValueSInt8,Com_ConstValueSInt16,Com_ConstValueSInt32,Com_ConstValueSInt64,Com_ConstValueFloat32,Com_ConstValueFloat64
  ApplType                  Application data type.
  BitLength                 Bit length of the signal or group signal.
  BitPosition               Little endian bit position of the signal or group signal within the I-PDU.
  BufferIdx                 the index of the 0:1 relation pointing to Com_RxSigBufferUInt8,Com_RxSigBufferUInt16,Com_RxSigBufferUInt32,Com_RxSigBufferUInt64,Com_RxSigBufferZeroBit,Com_RxSigBufferSInt8,Com_RxSigBufferSInt16,Com_RxSigBufferSInt32,Com_RxSigBufferSInt64,Com_RxSigBufferFloat32,Com_RxSigBufferFloat64
  BusAcc                    BUS access algorithm for signal or group signal packing / un-packing.
  ByteLength                Byte length of the signal or group signal.
  BytePosition              Little endian byte position of the signal or group signal within the I-PDU.
  InitValueIdx              the index of the 0:1 relation pointing to Com_ConstValueUInt8,Com_ConstValueUInt16,Com_ConstValueUInt32,Com_ConstValueUInt64,Com_ConstValueSInt8,Com_ConstValueSInt16,Com_ConstValueSInt32,Com_ConstValueSInt64,Com_ConstValueFloat32,Com_ConstValueFloat64
  RxPduInfoIdx              the index of the 1:1 relation pointing to Com_RxPduInfo
  RxTOutInfoIdx             the index of the 0:1 relation pointing to Com_RxTOutInfo
  StartByteInPduPosition    Start Byte position of the signal or group signal within the I-PDU.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_RxAccessInfoType, COM_CONST) Com_RxAccessInfo[55] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    InitValueUsed  ApplType                           BitLength  BitPosition  BufferIdx  BusAcc                                 ByteLength  BytePosition  InitValueIdx  RxPduInfoIdx  RxTOutInfoIdx                       StartByteInPduPosition        Referable Keys */
  { /*     0 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        2u,         10u,        0u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           1u,           0u,           2u,                                 2u,                     1u },  /* [/ActiveEcuC/Com/ComConfig/AnimationReq_oBCM17_oC03_for_EL_CAN_V2_1_1db28c46_Rx, /ActiveEcuC/Com/ComConfig/BCM17_oC03_for_EL_CAN_V2_1_e4ac4a6c_Rx] */
  { /*     1 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        4u,         16u,        1u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           2u,           0u,           2u,                                 2u,                     2u },  /* [/ActiveEcuC/Com/ComConfig/ApproachLightAnimationType_oBCM17_oC03_for_EL_CAN_V2_1_5b20a81e_Rx, /ActiveEcuC/Com/ComConfig/BCM17_oC03_for_EL_CAN_V2_1_e4ac4a6c_Rx] */
  { /*     2 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        1u,         55u,        2u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           6u,           0u,           5u,                                 5u,                     6u },  /* [/ActiveEcuC/Com/ComConfig/BMS_DCChrgConnect_oBMS17_oC03_for_EL_CAN_V2_1_91db617c_Rx, /ActiveEcuC/Com/ComConfig/BMS17_oC03_for_EL_CAN_V2_1_be27a4ae_Rx] */
  { /*     3 */          TRUE, COM_UINT16_APPLTYPEOFRXACCESSINFO,       10u,         62u,        0u, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1u,           7u,           0u,           4u,                                 4u,                     6u },  /* [/ActiveEcuC/Com/ComConfig/BMS_SOC_oBMS1_oC03_for_EL_CAN_V2_1_a261d1ce_Rx, /ActiveEcuC/Com/ComConfig/BMS1_oC03_for_EL_CAN_V2_1_ab80ae92_Rx] */
  { /*     4 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        1u,         37u,        3u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           4u,           0u,           3u,                                 3u,                     4u },  /* [/ActiveEcuC/Com/ComConfig/CEMDetminCdnSts_oBCM23_oC03_for_EL_CAN_V2_1_df6348d5_Rx, /ActiveEcuC/Com/ComConfig/BCM23_oC03_for_EL_CAN_V2_1_cee8e051_Rx] */
  { /*     5 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,          0u,        4u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,           0u,           0u,           0u,                                 0u,                     0u },  /* [/ActiveEcuC/Com/ComConfig/CheckSum_ABS3_oABS3_oC03_for_EL_CAN_V2_1_5745e086_Rx, /ActiveEcuC/Com/ComConfig/ABS3_oC03_for_EL_CAN_V2_1_5328da88_Rx] */
  { /*     6 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,          0u,        5u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,           0u,           0u,          14u,                                13u,                     0u },  /* [/ActiveEcuC/Com/ComConfig/CheckSum_PEPS2_oPEPS2_oC03_for_EL_CAN_V2_1_06064851_Rx, /ActiveEcuC/Com/ComConfig/PEPS2_oC03_for_EL_CAN_V2_1_d41abfa7_Rx] */
  { /*     7 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,          0u,        6u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,           0u,           0u,           1u,                                 1u,                     0u },  /* [/ActiveEcuC/Com/ComConfig/Checksum_BCM10_oBCM10_oC03_for_EL_CAN_V2_1_819e75d3_Rx, /ActiveEcuC/Com/ComConfig/BCM10_oC03_for_EL_CAN_V2_1_8175742c_Rx] */
  { /*     8 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        2u,         21u,        7u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           2u,           0u,          10u, COM_NO_RXTOUTINFOIDXOFRXACCESSINFO,                     2u },  /* [/ActiveEcuC/Com/ComConfig/ChrgDispPatTypSet_oHUT54_oC03_for_EL_CAN_V2_1_f6de33f3_Rx, /ActiveEcuC/Com/ComConfig/HUT54_oC03_for_EL_CAN_V2_1_82644d00_Rx] */
  { /*     9 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        2u,         23u,        8u, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         0u,           2u,           0u,          10u, COM_NO_RXTOUTINFOIDXOFRXACCESSINFO,                     1u },  /* [/ActiveEcuC/Com/ComConfig/ChrgPatDispSwt_oHUT54_oC03_for_EL_CAN_V2_1_f66d5f08_Rx, /ActiveEcuC/Com/ComConfig/HUT54_oC03_for_EL_CAN_V2_1_82644d00_Rx] */
  { /*    10 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        2u,          2u,        9u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           0u,           0u,           7u,                                 7u,                     0u },  /* [/ActiveEcuC/Com/ComConfig/DeepSlpCmd_oEEM1_oC03_for_EL_CAN_V2_1_41fb7d93_Rx, /ActiveEcuC/Com/ComConfig/EEM1_oC03_for_EL_CAN_V2_1_5bdcd994_Rx] */
  { /*    11 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        2u,          6u,       10u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           0u,           0u,          10u, COM_NO_RXTOUTINFOIDXOFRXACCESSINFO,                     0u },  /* [/ActiveEcuC/Com/ComConfig/EIDCSwt_oHUT54_oC03_for_EL_CAN_V2_1_ac2debcb_Rx, /ActiveEcuC/Com/ComConfig/HUT54_oC03_for_EL_CAN_V2_1_82644d00_Rx] */
  { /*    12 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        3u,          1u,       11u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           0u,           0u,          10u, COM_NO_RXTOUTINFOIDXOFRXACCESSINFO,                     0u },  /* [/ActiveEcuC/Com/ComConfig/EmojiTypSet_oHUT54_oC03_for_EL_CAN_V2_1_ac4f7c91_Rx, /ActiveEcuC/Com/ComConfig/HUT54_oC03_for_EL_CAN_V2_1_82644d00_Rx] */
  { /*    13 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        4u,         28u,       12u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           3u,           0u,           2u,                                 2u,                     3u },  /* [/ActiveEcuC/Com/ComConfig/GoodbyeAnimationType_oBCM17_oC03_for_EL_CAN_V2_1_bc8c4dab_Rx, /ActiveEcuC/Com/ComConfig/BCM17_oC03_for_EL_CAN_V2_1_e4ac4a6c_Rx] */
  { /*    14 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        1u,         46u,       13u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           5u,           0u,          11u,                                10u,                     5u },  /* [/ActiveEcuC/Com/ComConfig/IP_VehTotDistanceValid_oIP2_oC03_for_EL_CAN_V2_1_234ac38e_Rx, /ActiveEcuC/Com/ComConfig/IP2_oC03_for_EL_CAN_V2_1_65941076_Rx] */
  { /*    15 */          TRUE, COM_UINT32_APPLTYPEOFRXACCESSINFO,       24u,         24u,        0u,     COM_NBYTE_SW_BUSACCOFRXACCESSINFO,         3u,           3u,           0u,          11u,                                10u,                     1u },  /* [/ActiveEcuC/Com/ComConfig/IP_VehTotDistance_oIP2_oC03_for_EL_CAN_V2_1_a238a7cc_Rx, /ActiveEcuC/Com/ComConfig/IP2_oC03_for_EL_CAN_V2_1_65941076_Rx] */
  { /*    16 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        1u,          8u,       14u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           1u,           0u,           1u,                                 1u,                     1u },  /* [/ActiveEcuC/Com/ComConfig/LTurnLampWorkCmd_oBCM10_oC03_for_EL_CAN_V2_1_7a1a08f4_Rx, /ActiveEcuC/Com/ComConfig/BCM10_oC03_for_EL_CAN_V2_1_8175742c_Rx] */
  { /*    17 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        1u,         19u,       15u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           2u,           0u,           6u,                                 6u,                     2u },  /* [/ActiveEcuC/Com/ComConfig/LTurnLmpSwtSts_oCSA1_oC03_for_EL_CAN_V2_1_458e5c96_Rx, /ActiveEcuC/Com/ComConfig/CSA1_oC03_for_EL_CAN_V2_1_ffb47aea_Rx] */
  { /*    18 */          TRUE, COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         40u,        1u,     COM_NBYTE_SW_BUSACCOFRXACCESSINFO,         2u,           5u,           0u,          12u,                                11u,                     4u },  /* [/ActiveEcuC/Com/ComConfig/MCU_ActRotSpd_oMCU_5_oC03_for_EL_CAN_V2_1_c2eb67f0_Rx, /ActiveEcuC/Com/ComConfig/MCU_5_oC03_for_EL_CAN_V2_1_002cb201_Rx] */
  { /*    19 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        4u,         60u,       16u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           7u,           0u,           2u,                                 2u,                     7u },  /* [/ActiveEcuC/Com/ComConfig/MecDancAnimationType_oBCM17_oC03_for_EL_CAN_V2_1_6bb5a98f_Rx, /ActiveEcuC/Com/ComConfig/BCM17_oC03_for_EL_CAN_V2_1_e4ac4a6c_Rx] */
  { /*    20 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        2u,         63u,       17u, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         0u,           7u,           0u,          13u,                                12u,                     6u },  /* [/ActiveEcuC/Com/ComConfig/OBC_CCLineConnectSts_oOBC3_oC03_for_EL_CAN_V2_1_a7854723_Rx, /ActiveEcuC/Com/ComConfig/OBC3_oC03_for_EL_CAN_V2_1_158aa3d5_Rx] */
  { /*    21 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        1u,         11u,       18u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           1u,           0u,          16u,                                15u,                     1u },  /* [/ActiveEcuC/Com/ComConfig/PosnLmpOutpSts_R_PBox_oR_PBOX1_oC03_for_EL_CAN_V2_1_c63ace4d_Rx, /ActiveEcuC/Com/ComConfig/R_PBOX1_oC03_for_EL_CAN_V2_1_7854cc6e_Rx] */
  { /*    22 */          TRUE, COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         32u,        2u,     COM_NBYTE_SW_BUSACCOFRXACCESSINFO,         2u,           4u,           0u,          15u,                                14u,                     3u },  /* [/ActiveEcuC/Com/ComConfig/RMCU_ActRotSpd_oRMCU4_oC03_for_EL_CAN_V2_1_a08a2435_Rx, /ActiveEcuC/Com/ComConfig/RMCU4_oC03_for_EL_CAN_V2_1_55159990_Rx] */
  { /*    23 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        1u,         20u,       19u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           2u,           0u,           6u,                                 6u,                     2u },  /* [/ActiveEcuC/Com/ComConfig/RTurnLmpSwtSts_oCSA1_oC03_for_EL_CAN_V2_1_2fe59187_Rx, /ActiveEcuC/Com/ComConfig/CSA1_oC03_for_EL_CAN_V2_1_ffb47aea_Rx] */
  { /*    24 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        1u,          9u,       20u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           1u,           0u,           1u,                                 1u,                     1u },  /* [/ActiveEcuC/Com/ComConfig/RTurnLmpWorkCmd_oBCM10_oC03_for_EL_CAN_V2_1_10ea9ba1_Rx, /ActiveEcuC/Com/ComConfig/BCM10_oC03_for_EL_CAN_V2_1_8175742c_Rx] */
  { /*    25 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        3u,         14u,       21u, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         0u,           1u,           0u,          10u, COM_NO_RXTOUTINFOIDXOFRXACCESSINFO,                     0u },  /* [/ActiveEcuC/Com/ComConfig/RemindTypSet_oHUT54_oC03_for_EL_CAN_V2_1_fc32c110_Rx, /ActiveEcuC/Com/ComConfig/HUT54_oC03_for_EL_CAN_V2_1_82644d00_Rx] */
  { /*    26 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        4u,         56u,       22u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           7u,           0u,           0u,                                 0u,                     7u },  /* [/ActiveEcuC/Com/ComConfig/RollingCounter_ABS3_oABS3_oC03_for_EL_CAN_V2_1_b6ac7000_Rx, /ActiveEcuC/Com/ComConfig/ABS3_oC03_for_EL_CAN_V2_1_5328da88_Rx] */
  { /*    27 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        4u,         56u,       23u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           7u,           0u,          14u,                                13u,                     7u },  /* [/ActiveEcuC/Com/ComConfig/RollingCounter_PEPS2_oPEPS2_oC03_for_EL_CAN_V2_1_9bd00531_Rx, /ActiveEcuC/Com/ComConfig/PEPS2_oC03_for_EL_CAN_V2_1_d41abfa7_Rx] */
  { /*    28 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        4u,         56u,       24u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           7u,           0u,           1u,                                 1u,                     7u },  /* [/ActiveEcuC/Com/ComConfig/Rollingcounter_BCM10_oBCM10_oC03_for_EL_CAN_V2_1_6dd2f1f9_Rx, /ActiveEcuC/Com/ComConfig/BCM10_oC03_for_EL_CAN_V2_1_8175742c_Rx] */
  { /*    29 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,          0u,       25u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,           0u,           0u,           8u,                                 8u,                     0u },  /* [/ActiveEcuC/Com/ComConfig/ScenarioID_oGW1_oC03_for_EL_CAN_V2_1_b0249678_Rx, /ActiveEcuC/Com/ComConfig/GW1_oC03_for_EL_CAN_V2_1_48654b76_Rx] */
  { /*    30 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        3u,         13u,       26u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           1u,           0u,           8u,                                 8u,                     1u },  /* [/ActiveEcuC/Com/ComConfig/ScenarioReq_oGW1_oC03_for_EL_CAN_V2_1_d81adfac_Rx, /ActiveEcuC/Com/ComConfig/GW1_oC03_for_EL_CAN_V2_1_48654b76_Rx] */
  { /*    31 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        3u,          4u,       27u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           0u,           0u,           7u,                                 7u,                     0u },  /* [/ActiveEcuC/Com/ComConfig/Stat_PwrSv_Lvl_oEEM1_oC03_for_EL_CAN_V2_1_a4eaa63e_Rx, /ActiveEcuC/Com/ComConfig/EEM1_oC03_for_EL_CAN_V2_1_5bdcd994_Rx] */
  { /*    32 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        1u,         13u,       28u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           1u,           0u,          14u,                                13u,                     1u },  /* [/ActiveEcuC/Com/ComConfig/SysPowerModVld_oPEPS2_oC03_for_EL_CAN_V2_1_b6c20e3c_Rx, /ActiveEcuC/Com/ComConfig/PEPS2_oC03_for_EL_CAN_V2_1_d41abfa7_Rx] */
  { /*    33 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        2u,         14u,       29u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           1u,           0u,          14u,                                13u,                     1u },  /* [/ActiveEcuC/Com/ComConfig/SysPowerMod_oPEPS2_oC03_for_EL_CAN_V2_1_37fb939a_Rx, /ActiveEcuC/Com/ComConfig/PEPS2_oC03_for_EL_CAN_V2_1_d41abfa7_Rx] */
  { /*    34 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        1u,         17u,       30u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           2u,           0u,           9u,                                 9u,                     2u },  /* [/ActiveEcuC/Com/ComConfig/TimeIndcn_oHUT34_oC03_for_EL_CAN_V2_1_d29435a0_Rx, /ActiveEcuC/Com/ComConfig/HUT34_oC03_for_EL_CAN_V2_1_6fae3f7a_Rx] */
  { /*    35 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        1u,         16u,       31u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           2u,           0u,           9u,                                 9u,                     2u },  /* [/ActiveEcuC/Com/ComConfig/TimeMod_oHUT34_oC03_for_EL_CAN_V2_1_baa135ee_Rx, /ActiveEcuC/Com/ComConfig/HUT34_oC03_for_EL_CAN_V2_1_6fae3f7a_Rx] */
  { /*    36 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        5u,         51u,       32u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           6u,           0u,           9u,                                 9u,                     6u },  /* [/ActiveEcuC/Com/ComConfig/Time_Day_oHUT34_oC03_for_EL_CAN_V2_1_5996a937_Rx, /ActiveEcuC/Com/ComConfig/HUT34_oC03_for_EL_CAN_V2_1_6fae3f7a_Rx] */
  { /*    37 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        5u,         11u,       33u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           1u,           0u,           9u,                                 9u,                     1u },  /* [/ActiveEcuC/Com/ComConfig/Time_Hour_oHUT34_oC03_for_EL_CAN_V2_1_2c4ebd6a_Rx, /ActiveEcuC/Com/ComConfig/HUT34_oC03_for_EL_CAN_V2_1_6fae3f7a_Rx] */
  { /*    38 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        6u,         18u,       34u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           2u,           0u,           9u,                                 9u,                     2u },  /* [/ActiveEcuC/Com/ComConfig/Time_Minutes_oHUT34_oC03_for_EL_CAN_V2_1_da3ecd44_Rx, /ActiveEcuC/Com/ComConfig/HUT34_oC03_for_EL_CAN_V2_1_6fae3f7a_Rx] */
  { /*    39 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        4u,         44u,       35u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           5u,           0u,           9u,                                 9u,                     5u },  /* [/ActiveEcuC/Com/ComConfig/Time_Month_oHUT34_oC03_for_EL_CAN_V2_1_33ed510d_Rx, /ActiveEcuC/Com/ComConfig/HUT34_oC03_for_EL_CAN_V2_1_6fae3f7a_Rx] */
  { /*    40 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        6u,         26u,       36u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           3u,           0u,           9u,                                 9u,                     3u },  /* [/ActiveEcuC/Com/ComConfig/Time_Second_oHUT34_oC03_for_EL_CAN_V2_1_9732895b_Rx, /ActiveEcuC/Com/ComConfig/HUT34_oC03_for_EL_CAN_V2_1_6fae3f7a_Rx] */
  { /*    41 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        4u,         36u,       37u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           4u,           0u,           9u,                                 9u,                     4u },  /* [/ActiveEcuC/Com/ComConfig/Time_Year_Left_oHUT34_oC03_for_EL_CAN_V2_1_f1a91267_Rx, /ActiveEcuC/Com/ComConfig/HUT34_oC03_for_EL_CAN_V2_1_6fae3f7a_Rx] */
  { /*    42 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        4u,         32u,       38u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           4u,           0u,           9u,                                 9u,                     4u },  /* [/ActiveEcuC/Com/ComConfig/Time_Year_Right_oHUT34_oC03_for_EL_CAN_V2_1_fa890340_Rx, /ActiveEcuC/Com/ComConfig/HUT34_oC03_for_EL_CAN_V2_1_6fae3f7a_Rx] */
  { /*    43 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        2u,          4u,       39u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           0u,           0u,          10u, COM_NO_RXTOUTINFOIDXOFRXACCESSINFO,                     0u },  /* [/ActiveEcuC/Com/ComConfig/TopicTypSet_oHUT54_oC03_for_EL_CAN_V2_1_71504e9d_Rx, /ActiveEcuC/Com/ComConfig/HUT54_oC03_for_EL_CAN_V2_1_82644d00_Rx] */
  { /*    44 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        1u,          7u,       40u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           0u,           0u,           7u,                                 7u,                     0u },  /* [/ActiveEcuC/Com/ComConfig/TranPMode_Sts_oEEM1_oC03_for_EL_CAN_V2_1_a5a3838d_Rx, /ActiveEcuC/Com/ComConfig/EEM1_oC03_for_EL_CAN_V2_1_5bdcd994_Rx] */
  { /*    45 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        2u,         19u,       41u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           2u,           0u,          10u, COM_NO_RXTOUTINFOIDXOFRXACCESSINFO,                     2u },  /* [/ActiveEcuC/Com/ComConfig/TurnRemdSwt_oHUT54_oC03_for_EL_CAN_V2_1_06f5df9c_Rx, /ActiveEcuC/Com/ComConfig/HUT54_oC03_for_EL_CAN_V2_1_82644d00_Rx] */
  { /*    46 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        2u,         24u,       42u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           3u,           0u,          19u,                                18u,                     3u },  /* [/ActiveEcuC/Com/ComConfig/VCU_BrkPedlSts_oVCU6_oC03_for_EL_CAN_V2_1_66fed013_Rx, /ActiveEcuC/Com/ComConfig/VCU6_oC03_for_EL_CAN_V2_1_e209e1d3_Rx] */
  { /*    47 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        3u,         21u,       43u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           2u,           0u,          18u,                                17u,                     2u },  /* [/ActiveEcuC/Com/ComConfig/VCU_ChrgnSts_oVCU3_oC03_for_EL_CAN_V2_1_87b3fa1f_Rx, /ActiveEcuC/Com/ComConfig/VCU3_oC03_for_EL_CAN_V2_1_a9801613_Rx] */
  { /*    48 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        4u,         20u,       44u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           2u,           0u,          17u,                                16u,                     2u },  /* [/ActiveEcuC/Com/ComConfig/VCU_GearSts_oVCU2_oC03_for_EL_CAN_V2_1_71c2293d_Rx, /ActiveEcuC/Com/ComConfig/VCU2_oC03_for_EL_CAN_V2_1_bea872d3_Rx] */
  { /*    49 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        1u,         13u,       45u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           1u,           0u,           0u,                                 0u,                     1u },  /* [/ActiveEcuC/Com/ComConfig/VehSpdVld_oABS3_oC03_for_EL_CAN_V2_1_32497dd3_Rx, /ActiveEcuC/Com/ComConfig/ABS3_oC03_for_EL_CAN_V2_1_5328da88_Rx] */
    /* Index    InitValueUsed  ApplType                           BitLength  BitPosition  BufferIdx  BusAcc                                 ByteLength  BytePosition  InitValueIdx  RxPduInfoIdx  RxTOutInfoIdx                       StartByteInPduPosition        Referable Keys */
  { /*    50 */          TRUE, COM_UINT16_APPLTYPEOFRXACCESSINFO,       13u,         16u,        3u, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1u,           2u,           0u,           0u,                                 0u,                     1u },  /* [/ActiveEcuC/Com/ComConfig/VehSpd_oABS3_oC03_for_EL_CAN_V2_1_23260d94_Rx, /ActiveEcuC/Com/ComConfig/ABS3_oC03_for_EL_CAN_V2_1_5328da88_Rx] */
  { /*    51 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        4u,         12u,       46u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           1u,           0u,           2u,                                 2u,                     1u },  /* [/ActiveEcuC/Com/ComConfig/WelcomeAnimationType_oBCM17_oC03_for_EL_CAN_V2_1_c76d0f7a_Rx, /ActiveEcuC/Com/ComConfig/BCM17_oC03_for_EL_CAN_V2_1_e4ac4a6c_Rx] */
  { /*    52 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        3u,          9u,       47u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           1u,           0u,          10u, COM_NO_RXTOUTINFOIDXOFRXACCESSINFO,                     1u },  /* [/ActiveEcuC/Com/ComConfig/WelcomePatTypSet_oHUT54_oC03_for_EL_CAN_V2_1_ac7026e0_Rx, /ActiveEcuC/Com/ComConfig/HUT54_oC03_for_EL_CAN_V2_1_82644d00_Rx] */
  { /*    53 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        2u,         12u,       48u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           1u,           0u,          10u, COM_NO_RXTOUTINFOIDXOFRXACCESSINFO,                     1u },  /* [/ActiveEcuC/Com/ComConfig/WelcomeSwt_oHUT54_oC03_for_EL_CAN_V2_1_351ff7b4_Rx, /ActiveEcuC/Com/ComConfig/HUT54_oC03_for_EL_CAN_V2_1_82644d00_Rx] */
  { /*    54 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        3u,         16u,       49u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           2u,           0u,          10u, COM_NO_RXTOUTINFOIDXOFRXACCESSINFO,                     2u }   /* [/ActiveEcuC/Com/ComConfig/WordTypSet_oHUT54_oC03_for_EL_CAN_V2_1_035aa6cb_Rx, /ActiveEcuC/Com/ComConfig/HUT54_oC03_for_EL_CAN_V2_1_82644d00_Rx] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxAccessInfoInd
**********************************************************************************************************************/
/** 
  \var    Com_RxAccessInfoInd
  \brief  the indexes of the 1:1 sorted relation pointing to Com_RxAccessInfo
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_RxAccessInfoIndType, COM_CONST) Com_RxAccessInfoInd[55] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     RxAccessInfoInd      Referable Keys */
  /*     0 */               5u,  /* [/ActiveEcuC/Com/ComConfig/ABS3_oC03_for_EL_CAN_V2_1_5328da88_Rx] */
  /*     1 */              26u,  /* [/ActiveEcuC/Com/ComConfig/ABS3_oC03_for_EL_CAN_V2_1_5328da88_Rx] */
  /*     2 */              49u,  /* [/ActiveEcuC/Com/ComConfig/ABS3_oC03_for_EL_CAN_V2_1_5328da88_Rx] */
  /*     3 */              50u,  /* [/ActiveEcuC/Com/ComConfig/ABS3_oC03_for_EL_CAN_V2_1_5328da88_Rx] */
  /*     4 */               7u,  /* [/ActiveEcuC/Com/ComConfig/BCM10_oC03_for_EL_CAN_V2_1_8175742c_Rx] */
  /*     5 */              16u,  /* [/ActiveEcuC/Com/ComConfig/BCM10_oC03_for_EL_CAN_V2_1_8175742c_Rx] */
  /*     6 */              24u,  /* [/ActiveEcuC/Com/ComConfig/BCM10_oC03_for_EL_CAN_V2_1_8175742c_Rx] */
  /*     7 */              28u,  /* [/ActiveEcuC/Com/ComConfig/BCM10_oC03_for_EL_CAN_V2_1_8175742c_Rx] */
  /*     8 */               0u,  /* [/ActiveEcuC/Com/ComConfig/BCM17_oC03_for_EL_CAN_V2_1_e4ac4a6c_Rx] */
  /*     9 */               1u,  /* [/ActiveEcuC/Com/ComConfig/BCM17_oC03_for_EL_CAN_V2_1_e4ac4a6c_Rx] */
  /*    10 */              13u,  /* [/ActiveEcuC/Com/ComConfig/BCM17_oC03_for_EL_CAN_V2_1_e4ac4a6c_Rx] */
  /*    11 */              19u,  /* [/ActiveEcuC/Com/ComConfig/BCM17_oC03_for_EL_CAN_V2_1_e4ac4a6c_Rx] */
  /*    12 */              51u,  /* [/ActiveEcuC/Com/ComConfig/BCM17_oC03_for_EL_CAN_V2_1_e4ac4a6c_Rx] */
  /*    13 */               4u,  /* [/ActiveEcuC/Com/ComConfig/BCM23_oC03_for_EL_CAN_V2_1_cee8e051_Rx] */
  /*    14 */               3u,  /* [/ActiveEcuC/Com/ComConfig/BMS1_oC03_for_EL_CAN_V2_1_ab80ae92_Rx] */
  /*    15 */               2u,  /* [/ActiveEcuC/Com/ComConfig/BMS17_oC03_for_EL_CAN_V2_1_be27a4ae_Rx] */
  /*    16 */              17u,  /* [/ActiveEcuC/Com/ComConfig/CSA1_oC03_for_EL_CAN_V2_1_ffb47aea_Rx] */
  /*    17 */              23u,  /* [/ActiveEcuC/Com/ComConfig/CSA1_oC03_for_EL_CAN_V2_1_ffb47aea_Rx] */
  /*    18 */              10u,  /* [/ActiveEcuC/Com/ComConfig/EEM1_oC03_for_EL_CAN_V2_1_5bdcd994_Rx] */
  /*    19 */              31u,  /* [/ActiveEcuC/Com/ComConfig/EEM1_oC03_for_EL_CAN_V2_1_5bdcd994_Rx] */
  /*    20 */              44u,  /* [/ActiveEcuC/Com/ComConfig/EEM1_oC03_for_EL_CAN_V2_1_5bdcd994_Rx] */
  /*    21 */              29u,  /* [/ActiveEcuC/Com/ComConfig/GW1_oC03_for_EL_CAN_V2_1_48654b76_Rx] */
  /*    22 */              30u,  /* [/ActiveEcuC/Com/ComConfig/GW1_oC03_for_EL_CAN_V2_1_48654b76_Rx] */
  /*    23 */              34u,  /* [/ActiveEcuC/Com/ComConfig/HUT34_oC03_for_EL_CAN_V2_1_6fae3f7a_Rx] */
  /*    24 */              35u,  /* [/ActiveEcuC/Com/ComConfig/HUT34_oC03_for_EL_CAN_V2_1_6fae3f7a_Rx] */
  /*    25 */              36u,  /* [/ActiveEcuC/Com/ComConfig/HUT34_oC03_for_EL_CAN_V2_1_6fae3f7a_Rx] */
  /*    26 */              37u,  /* [/ActiveEcuC/Com/ComConfig/HUT34_oC03_for_EL_CAN_V2_1_6fae3f7a_Rx] */
  /*    27 */              38u,  /* [/ActiveEcuC/Com/ComConfig/HUT34_oC03_for_EL_CAN_V2_1_6fae3f7a_Rx] */
  /*    28 */              39u,  /* [/ActiveEcuC/Com/ComConfig/HUT34_oC03_for_EL_CAN_V2_1_6fae3f7a_Rx] */
  /*    29 */              40u,  /* [/ActiveEcuC/Com/ComConfig/HUT34_oC03_for_EL_CAN_V2_1_6fae3f7a_Rx] */
  /*    30 */              41u,  /* [/ActiveEcuC/Com/ComConfig/HUT34_oC03_for_EL_CAN_V2_1_6fae3f7a_Rx] */
  /*    31 */              42u,  /* [/ActiveEcuC/Com/ComConfig/HUT34_oC03_for_EL_CAN_V2_1_6fae3f7a_Rx] */
  /*    32 */               8u,  /* [/ActiveEcuC/Com/ComConfig/HUT54_oC03_for_EL_CAN_V2_1_82644d00_Rx] */
  /*    33 */               9u,  /* [/ActiveEcuC/Com/ComConfig/HUT54_oC03_for_EL_CAN_V2_1_82644d00_Rx] */
  /*    34 */              11u,  /* [/ActiveEcuC/Com/ComConfig/HUT54_oC03_for_EL_CAN_V2_1_82644d00_Rx] */
  /*    35 */              12u,  /* [/ActiveEcuC/Com/ComConfig/HUT54_oC03_for_EL_CAN_V2_1_82644d00_Rx] */
  /*    36 */              25u,  /* [/ActiveEcuC/Com/ComConfig/HUT54_oC03_for_EL_CAN_V2_1_82644d00_Rx] */
  /*    37 */              43u,  /* [/ActiveEcuC/Com/ComConfig/HUT54_oC03_for_EL_CAN_V2_1_82644d00_Rx] */
  /*    38 */              45u,  /* [/ActiveEcuC/Com/ComConfig/HUT54_oC03_for_EL_CAN_V2_1_82644d00_Rx] */
  /*    39 */              52u,  /* [/ActiveEcuC/Com/ComConfig/HUT54_oC03_for_EL_CAN_V2_1_82644d00_Rx] */
  /*    40 */              53u,  /* [/ActiveEcuC/Com/ComConfig/HUT54_oC03_for_EL_CAN_V2_1_82644d00_Rx] */
  /*    41 */              54u,  /* [/ActiveEcuC/Com/ComConfig/HUT54_oC03_for_EL_CAN_V2_1_82644d00_Rx] */
  /*    42 */              14u,  /* [/ActiveEcuC/Com/ComConfig/IP2_oC03_for_EL_CAN_V2_1_65941076_Rx] */
  /*    43 */              15u,  /* [/ActiveEcuC/Com/ComConfig/IP2_oC03_for_EL_CAN_V2_1_65941076_Rx] */
  /*    44 */              18u,  /* [/ActiveEcuC/Com/ComConfig/MCU_5_oC03_for_EL_CAN_V2_1_002cb201_Rx] */
  /*    45 */              20u,  /* [/ActiveEcuC/Com/ComConfig/OBC3_oC03_for_EL_CAN_V2_1_158aa3d5_Rx] */
  /*    46 */               6u,  /* [/ActiveEcuC/Com/ComConfig/PEPS2_oC03_for_EL_CAN_V2_1_d41abfa7_Rx] */
  /*    47 */              27u,  /* [/ActiveEcuC/Com/ComConfig/PEPS2_oC03_for_EL_CAN_V2_1_d41abfa7_Rx] */
  /*    48 */              32u,  /* [/ActiveEcuC/Com/ComConfig/PEPS2_oC03_for_EL_CAN_V2_1_d41abfa7_Rx] */
  /*    49 */              33u,  /* [/ActiveEcuC/Com/ComConfig/PEPS2_oC03_for_EL_CAN_V2_1_d41abfa7_Rx] */
  /* Index     RxAccessInfoInd      Referable Keys */
  /*    50 */              22u,  /* [/ActiveEcuC/Com/ComConfig/RMCU4_oC03_for_EL_CAN_V2_1_55159990_Rx] */
  /*    51 */              21u,  /* [/ActiveEcuC/Com/ComConfig/R_PBOX1_oC03_for_EL_CAN_V2_1_7854cc6e_Rx] */
  /*    52 */              48u,  /* [/ActiveEcuC/Com/ComConfig/VCU2_oC03_for_EL_CAN_V2_1_bea872d3_Rx] */
  /*    53 */              47u,  /* [/ActiveEcuC/Com/ComConfig/VCU3_oC03_for_EL_CAN_V2_1_a9801613_Rx] */
  /*    54 */              46u   /* [/ActiveEcuC/Com/ComConfig/VCU6_oC03_for_EL_CAN_V2_1_e209e1d3_Rx] */
};
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxCbkFuncPtr
**********************************************************************************************************************/
/** 
  \var    Com_RxCbkFuncPtr
  \brief  Function pointer table containing configured notification and invalid notifications function pointer for signals and signal groups.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(ComRxCbkType, COM_CONST) Com_RxCbkFuncPtr[55] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     RxCbkFuncPtr                                      Referable Keys */
  /*     0 */ ComEx_COMCbkNr_CheckSum_ABS3_Rx              ,  /* [/ActiveEcuC/Com/ComConfig/CheckSum_ABS3_oABS3_oC03_for_EL_CAN_V2_1_5745e086_RxAck] */
  /*     1 */ ComEx_COMCbkNr_RollingCounter_ABS3_Rx        ,  /* [/ActiveEcuC/Com/ComConfig/RollingCounter_ABS3_oABS3_oC03_for_EL_CAN_V2_1_b6ac7000_RxAck] */
  /*     2 */ ComEx_COMCbkNr_VehSpdVld_Rx                  ,  /* [/ActiveEcuC/Com/ComConfig/VehSpdVld_oABS3_oC03_for_EL_CAN_V2_1_32497dd3_RxAck] */
  /*     3 */ ComEx_COMCbkNr_VehSpd_Rx                     ,  /* [/ActiveEcuC/Com/ComConfig/VehSpd_oABS3_oC03_for_EL_CAN_V2_1_23260d94_RxAck] */
  /*     4 */ ComEx_COMCbkNr_Checksum_BCM10_Rx             ,  /* [/ActiveEcuC/Com/ComConfig/Checksum_BCM10_oBCM10_oC03_for_EL_CAN_V2_1_819e75d3_RxAck] */
  /*     5 */ ComEx_COMCbkNr_LTurnLampWorkCmd_Rx           ,  /* [/ActiveEcuC/Com/ComConfig/LTurnLampWorkCmd_oBCM10_oC03_for_EL_CAN_V2_1_7a1a08f4_RxAck] */
  /*     6 */ ComEx_COMCbkNr_RTurnLmpWorkCmd_Rx            ,  /* [/ActiveEcuC/Com/ComConfig/RTurnLmpWorkCmd_oBCM10_oC03_for_EL_CAN_V2_1_10ea9ba1_RxAck] */
  /*     7 */ ComEx_COMCbkNr_Rollingcounter_BCM10_Rx       ,  /* [/ActiveEcuC/Com/ComConfig/Rollingcounter_BCM10_oBCM10_oC03_for_EL_CAN_V2_1_6dd2f1f9_RxAck] */
  /*     8 */ ComEx_COMCbkNr_AnimationReq_Rx               ,  /* [/ActiveEcuC/Com/ComConfig/AnimationReq_oBCM17_oC03_for_EL_CAN_V2_1_1db28c46_RxAck] */
  /*     9 */ ComEx_COMCbkNr_ApproachLightAnimationType_Rx ,  /* [/ActiveEcuC/Com/ComConfig/ApproachLightAnimationType_oBCM17_oC03_for_EL_CAN_V2_1_5b20a81e_RxAck] */
  /*    10 */ ComEx_COMCbkNr_GoodbyeAnimationType_Rx       ,  /* [/ActiveEcuC/Com/ComConfig/GoodbyeAnimationType_oBCM17_oC03_for_EL_CAN_V2_1_bc8c4dab_RxAck] */
  /*    11 */ ComEx_COMCbkNr_MecDancAnimationType_Rx       ,  /* [/ActiveEcuC/Com/ComConfig/MecDancAnimationType_oBCM17_oC03_for_EL_CAN_V2_1_6bb5a98f_RxAck] */
  /*    12 */ ComEx_COMCbkNr_WelcomeAnimationType_Rx       ,  /* [/ActiveEcuC/Com/ComConfig/WelcomeAnimationType_oBCM17_oC03_for_EL_CAN_V2_1_c76d0f7a_RxAck] */
  /*    13 */ ComEx_COMCbkNr_CEMDetminCdnSts_Rx            ,  /* [/ActiveEcuC/Com/ComConfig/CEMDetminCdnSts_oBCM23_oC03_for_EL_CAN_V2_1_df6348d5_RxAck] */
  /*    14 */ ComEx_COMCbkNr_BMS_SOC_Rx                    ,  /* [/ActiveEcuC/Com/ComConfig/BMS_SOC_oBMS1_oC03_for_EL_CAN_V2_1_a261d1ce_RxAck] */
  /*    15 */ ComEx_COMCbkNr_BMS_DCChrgConnect_Rx          ,  /* [/ActiveEcuC/Com/ComConfig/BMS_DCChrgConnect_oBMS17_oC03_for_EL_CAN_V2_1_91db617c_RxAck] */
  /*    16 */ ComEx_COMCbkRxTOut_LTurnLmpSwtSts_Rx         ,  /* [/ActiveEcuC/Com/ComConfig/LTurnLmpSwtSts_oCSA1_oC03_for_EL_CAN_V2_1_458e5c96_RxAck] */
  /*    17 */ ComEx_COMCbkNr_RTurnLmpSwtSts_Rx             ,  /* [/ActiveEcuC/Com/ComConfig/RTurnLmpSwtSts_oCSA1_oC03_for_EL_CAN_V2_1_2fe59187_RxAck] */
  /*    18 */ ComEx_COMCbkNr_DeepSlpCmd_Rx                 ,  /* [/ActiveEcuC/Com/ComConfig/DeepSlpCmd_oEEM1_oC03_for_EL_CAN_V2_1_41fb7d93_RxAck] */
  /*    19 */ ComEx_COMCbkNr_Stat_PwrSv_Lvl_Rx             ,  /* [/ActiveEcuC/Com/ComConfig/Stat_PwrSv_Lvl_oEEM1_oC03_for_EL_CAN_V2_1_a4eaa63e_RxAck] */
  /*    20 */ ComEx_COMCbkNr_TranPMode_Sts_Rx              ,  /* [/ActiveEcuC/Com/ComConfig/TranPMode_Sts_oEEM1_oC03_for_EL_CAN_V2_1_a5a3838d_RxAck] */
  /*    21 */ ComEx_COMCbkNr_ScenarioID_Rx                 ,  /* [/ActiveEcuC/Com/ComConfig/ScenarioID_oGW1_oC03_for_EL_CAN_V2_1_b0249678_RxAck] */
  /*    22 */ ComEx_COMCbkNr_ScenarioReq_Rx                ,  /* [/ActiveEcuC/Com/ComConfig/ScenarioReq_oGW1_oC03_for_EL_CAN_V2_1_d81adfac_RxAck] */
  /*    23 */ ComEx_COMCbkNr_TimeIndcn_Rx                  ,  /* [/ActiveEcuC/Com/ComConfig/TimeIndcn_oHUT34_oC03_for_EL_CAN_V2_1_d29435a0_RxAck] */
  /*    24 */ ComEx_COMCbkNr_TimeMod_Rx                    ,  /* [/ActiveEcuC/Com/ComConfig/TimeMod_oHUT34_oC03_for_EL_CAN_V2_1_baa135ee_RxAck] */
  /*    25 */ ComEx_COMCbkNr_Time_Day_Rx                   ,  /* [/ActiveEcuC/Com/ComConfig/Time_Day_oHUT34_oC03_for_EL_CAN_V2_1_5996a937_RxAck] */
  /*    26 */ ComEx_COMCbkNr_Time_Hour_Rx                  ,  /* [/ActiveEcuC/Com/ComConfig/Time_Hour_oHUT34_oC03_for_EL_CAN_V2_1_2c4ebd6a_RxAck] */
  /*    27 */ ComEx_COMCbkNr_Time_Minutes_Rx               ,  /* [/ActiveEcuC/Com/ComConfig/Time_Minutes_oHUT34_oC03_for_EL_CAN_V2_1_da3ecd44_RxAck] */
  /*    28 */ ComEx_COMCbkNr_Time_Month_Rx                 ,  /* [/ActiveEcuC/Com/ComConfig/Time_Month_oHUT34_oC03_for_EL_CAN_V2_1_33ed510d_RxAck] */
  /*    29 */ ComEx_COMCbkNr_Time_Second_Rx                ,  /* [/ActiveEcuC/Com/ComConfig/Time_Second_oHUT34_oC03_for_EL_CAN_V2_1_9732895b_RxAck] */
  /*    30 */ ComEx_COMCbkNr_Time_Year_Left_Rx             ,  /* [/ActiveEcuC/Com/ComConfig/Time_Year_Left_oHUT34_oC03_for_EL_CAN_V2_1_f1a91267_RxAck] */
  /*    31 */ ComEx_COMCbkNr_Time_Year_Right_Rx            ,  /* [/ActiveEcuC/Com/ComConfig/Time_Year_Right_oHUT34_oC03_for_EL_CAN_V2_1_fa890340_RxAck] */
  /*    32 */ ComEx_COMCbkNr_ChrgDispPatTypSet_Rx          ,  /* [/ActiveEcuC/Com/ComConfig/ChrgDispPatTypSet_oHUT54_oC03_for_EL_CAN_V2_1_f6de33f3_RxAck] */
  /*    33 */ ComEx_COMCbkNr_ChrgPatDispSwt_Rx             ,  /* [/ActiveEcuC/Com/ComConfig/ChrgPatDispSwt_oHUT54_oC03_for_EL_CAN_V2_1_f66d5f08_RxAck] */
  /*    34 */ ComEx_COMCbkNr_EIDCSwt_Rx                    ,  /* [/ActiveEcuC/Com/ComConfig/EIDCSwt_oHUT54_oC03_for_EL_CAN_V2_1_ac2debcb_RxAck] */
  /*    35 */ ComEx_COMCbkNr_EmojiTypSet_Rx                ,  /* [/ActiveEcuC/Com/ComConfig/EmojiTypSet_oHUT54_oC03_for_EL_CAN_V2_1_ac4f7c91_RxAck] */
  /*    36 */ ComEx_COMCbkNr_RemindTypSet_Rx               ,  /* [/ActiveEcuC/Com/ComConfig/RemindTypSet_oHUT54_oC03_for_EL_CAN_V2_1_fc32c110_RxAck] */
  /*    37 */ ComEx_COMCbkNr_TopicTypSet_Rx                ,  /* [/ActiveEcuC/Com/ComConfig/TopicTypSet_oHUT54_oC03_for_EL_CAN_V2_1_71504e9d_RxAck] */
  /*    38 */ ComEx_COMCbkNr_TurnRemdSwt_Rx                ,  /* [/ActiveEcuC/Com/ComConfig/TurnRemdSwt_oHUT54_oC03_for_EL_CAN_V2_1_06f5df9c_RxAck] */
  /*    39 */ ComEx_COMCbkNr_WelcomePatTypSet_Rx           ,  /* [/ActiveEcuC/Com/ComConfig/WelcomePatTypSet_oHUT54_oC03_for_EL_CAN_V2_1_ac7026e0_RxAck] */
  /*    40 */ ComEx_COMCbkNr_WelcomeSwt_Rx                 ,  /* [/ActiveEcuC/Com/ComConfig/WelcomeSwt_oHUT54_oC03_for_EL_CAN_V2_1_351ff7b4_RxAck] */
  /*    41 */ ComEx_COMCbkNr_WordTypSet_Rx                 ,  /* [/ActiveEcuC/Com/ComConfig/WordTypSet_oHUT54_oC03_for_EL_CAN_V2_1_035aa6cb_RxAck] */
  /*    42 */ ComEx_COMCbkNr_IP_VehTotDistanceValid_Rx     ,  /* [/ActiveEcuC/Com/ComConfig/IP_VehTotDistanceValid_oIP2_oC03_for_EL_CAN_V2_1_234ac38e_RxAck] */
  /*    43 */ ComEx_COMCbkNr_IP_VehTotDistance_Rx          ,  /* [/ActiveEcuC/Com/ComConfig/IP_VehTotDistance_oIP2_oC03_for_EL_CAN_V2_1_a238a7cc_RxAck] */
  /*    44 */ ComEx_COMCbkNr_MCU_ActRotSpd_Rx              ,  /* [/ActiveEcuC/Com/ComConfig/MCU_ActRotSpd_oMCU_5_oC03_for_EL_CAN_V2_1_c2eb67f0_RxAck] */
  /*    45 */ ComEx_COMCbkNr_OBC_CCLineConnectSts_Rx       ,  /* [/ActiveEcuC/Com/ComConfig/OBC_CCLineConnectSts_oOBC3_oC03_for_EL_CAN_V2_1_a7854723_RxAck] */
  /*    46 */ ComEx_COMCbkNr_CheckSum_PEPS2_Rx             ,  /* [/ActiveEcuC/Com/ComConfig/CheckSum_PEPS2_oPEPS2_oC03_for_EL_CAN_V2_1_06064851_RxAck] */
  /*    47 */ ComEx_COMCbkNr_RollingCounter_PEPS2_Rx       ,  /* [/ActiveEcuC/Com/ComConfig/RollingCounter_PEPS2_oPEPS2_oC03_for_EL_CAN_V2_1_9bd00531_RxAck] */
  /*    48 */ ComEx_COMCbkNr_SysPowerModVld_Rx             ,  /* [/ActiveEcuC/Com/ComConfig/SysPowerModVld_oPEPS2_oC03_for_EL_CAN_V2_1_b6c20e3c_RxAck] */
  /*    49 */ ComEx_COMCbkNr_SysPowerMod_Rx                ,  /* [/ActiveEcuC/Com/ComConfig/SysPowerMod_oPEPS2_oC03_for_EL_CAN_V2_1_37fb939a_RxAck] */
  /* Index     RxCbkFuncPtr                                      Referable Keys */
  /*    50 */ ComEx_COMCbkNr_RMCU_ActRotSpd_Rx             ,  /* [/ActiveEcuC/Com/ComConfig/RMCU_ActRotSpd_oRMCU4_oC03_for_EL_CAN_V2_1_a08a2435_RxAck] */
  /*    51 */ ComEx_COMCbkNr_PosnLmpOutpSts_R_PBox_Rx      ,  /* [/ActiveEcuC/Com/ComConfig/PosnLmpOutpSts_R_PBox_oR_PBOX1_oC03_for_EL_CAN_V2_1_c63ace4d_RxAck] */
  /*    52 */ ComEx_COMCbkNr_VCU_GearSts_Rx                ,  /* [/ActiveEcuC/Com/ComConfig/VCU_GearSts_oVCU2_oC03_for_EL_CAN_V2_1_71c2293d_RxAck] */
  /*    53 */ ComEx_COMCbkNr_VCU_ChrgnSts_Rx               ,  /* [/ActiveEcuC/Com/ComConfig/VCU_ChrgnSts_oVCU3_oC03_for_EL_CAN_V2_1_87b3fa1f_RxAck] */
  /*    54 */ ComEx_COMCbkNr_VCU_BrkPedlSts_Rx                /* [/ActiveEcuC/Com/ComConfig/VCU_BrkPedlSts_oVCU6_oC03_for_EL_CAN_V2_1_66fed013_RxAck] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxPduInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxPduInfo
  \brief  Contains all relevant common information for Rx I-PDUs.
  \details
  Element                            Description
  IPduGroupInfoOfRxPduInfoIndUsed    TRUE, if the 0:n relation has 1 relation pointing to Com_IPduGroupInfoOfRxPduInfoInd
  RxTOutInfoUsed                     TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_RxTOutInfo
  RxDefPduBufferStartIdx             the start index of the 0:n relation pointing to Com_RxDefPduBuffer
  RxSigInfoEndIdx                    the end index of the 0:n relation pointing to Com_RxSigInfo
  RxSigInfoStartIdx                  the start index of the 0:n relation pointing to Com_RxSigInfo
  RxTOutInfoIndEndIdx                the end index of the 0:n relation pointing to Com_RxTOutInfoInd
  RxTOutInfoIndStartIdx              the start index of the 0:n relation pointing to Com_RxTOutInfoInd
  Type                               Defines whether rx Pdu is a NORMAL or TP IPdu.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_RxPduInfoType, COM_CONST) Com_RxPduInfo[20] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    IPduGroupInfoOfRxPduInfoIndUsed  RxTOutInfoUsed  RxDefPduBufferStartIdx  RxSigInfoEndIdx  RxSigInfoStartIdx  RxTOutInfoIndEndIdx                    RxTOutInfoIndStartIdx                    Type                              Referable Keys */
  { /*     0 */                            TRUE,           TRUE,                     0u,              4u,                0u,                                    1u,                                      0u, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/ABS3_oC03_for_EL_CAN_V2_1_5328da88_Rx, /ActiveEcuC/Com/ComConfig/EIDC_oC03_for_EL_CAN_V2_1_Rx_0f13cc3b] */
  { /*     1 */                            TRUE,           TRUE,                     8u,              8u,                4u,                                    2u,                                      1u, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/BCM10_oC03_for_EL_CAN_V2_1_8175742c_Rx, /ActiveEcuC/Com/ComConfig/EIDC_oC03_for_EL_CAN_V2_1_Rx_0f13cc3b] */
  { /*     2 */                            TRUE,           TRUE,                    16u,             13u,                8u,                                    3u,                                      2u, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/BCM17_oC03_for_EL_CAN_V2_1_e4ac4a6c_Rx, /ActiveEcuC/Com/ComConfig/EIDC_oC03_for_EL_CAN_V2_1_Rx_0f13cc3b] */
  { /*     3 */                            TRUE,           TRUE,                    24u,             14u,               13u,                                    4u,                                      3u, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/BCM23_oC03_for_EL_CAN_V2_1_cee8e051_Rx, /ActiveEcuC/Com/ComConfig/EIDC_oC03_for_EL_CAN_V2_1_Rx_0f13cc3b] */
  { /*     4 */                            TRUE,           TRUE,                    32u,             15u,               14u,                                    5u,                                      4u, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/BMS1_oC03_for_EL_CAN_V2_1_ab80ae92_Rx, /ActiveEcuC/Com/ComConfig/EIDC_oC03_for_EL_CAN_V2_1_Rx_0f13cc3b] */
  { /*     5 */                            TRUE,           TRUE,                    40u,             16u,               15u,                                    6u,                                      5u, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/BMS17_oC03_for_EL_CAN_V2_1_be27a4ae_Rx, /ActiveEcuC/Com/ComConfig/EIDC_oC03_for_EL_CAN_V2_1_Rx_0f13cc3b] */
  { /*     6 */                            TRUE,           TRUE,                    48u,             18u,               16u,                                    7u,                                      6u, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/CSA1_oC03_for_EL_CAN_V2_1_ffb47aea_Rx, /ActiveEcuC/Com/ComConfig/EIDC_oC03_for_EL_CAN_V2_1_Rx_0f13cc3b] */
  { /*     7 */                            TRUE,           TRUE,                    56u,             21u,               18u,                                    8u,                                      7u, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/EEM1_oC03_for_EL_CAN_V2_1_5bdcd994_Rx, /ActiveEcuC/Com/ComConfig/EIDC_oC03_for_EL_CAN_V2_1_Rx_0f13cc3b] */
  { /*     8 */                            TRUE,           TRUE,                    64u,             23u,               21u,                                    9u,                                      8u, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/GW1_oC03_for_EL_CAN_V2_1_48654b76_Rx, /ActiveEcuC/Com/ComConfig/EIDC_oC03_for_EL_CAN_V2_1_Rx_0f13cc3b] */
  { /*     9 */                            TRUE,           TRUE,                    72u,             32u,               23u,                                   10u,                                      9u, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/HUT34_oC03_for_EL_CAN_V2_1_6fae3f7a_Rx, /ActiveEcuC/Com/ComConfig/EIDC_oC03_for_EL_CAN_V2_1_Rx_0f13cc3b] */
  { /*    10 */                            TRUE,          FALSE,                    80u,             42u,               32u, COM_NO_RXTOUTINFOINDENDIDXOFRXPDUINFO, COM_NO_RXTOUTINFOINDSTARTIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/HUT54_oC03_for_EL_CAN_V2_1_82644d00_Rx, /ActiveEcuC/Com/ComConfig/EIDC_oC03_for_EL_CAN_V2_1_Rx_0f13cc3b] */
  { /*    11 */                            TRUE,           TRUE,                    88u,             44u,               42u,                                   11u,                                     10u, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/IP2_oC03_for_EL_CAN_V2_1_65941076_Rx, /ActiveEcuC/Com/ComConfig/EIDC_oC03_for_EL_CAN_V2_1_Rx_0f13cc3b] */
  { /*    12 */                            TRUE,           TRUE,                    96u,             45u,               44u,                                   12u,                                     11u, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/MCU_5_oC03_for_EL_CAN_V2_1_002cb201_Rx, /ActiveEcuC/Com/ComConfig/EIDC_oC03_for_EL_CAN_V2_1_Rx_0f13cc3b] */
  { /*    13 */                            TRUE,           TRUE,                   104u,             46u,               45u,                                   13u,                                     12u, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/OBC3_oC03_for_EL_CAN_V2_1_158aa3d5_Rx, /ActiveEcuC/Com/ComConfig/EIDC_oC03_for_EL_CAN_V2_1_Rx_0f13cc3b] */
  { /*    14 */                            TRUE,           TRUE,                   112u,             50u,               46u,                                   14u,                                     13u, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/PEPS2_oC03_for_EL_CAN_V2_1_d41abfa7_Rx, /ActiveEcuC/Com/ComConfig/EIDC_oC03_for_EL_CAN_V2_1_Rx_0f13cc3b] */
  { /*    15 */                            TRUE,           TRUE,                   120u,             51u,               50u,                                   15u,                                     14u, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/RMCU4_oC03_for_EL_CAN_V2_1_55159990_Rx, /ActiveEcuC/Com/ComConfig/EIDC_oC03_for_EL_CAN_V2_1_Rx_0f13cc3b] */
  { /*    16 */                            TRUE,           TRUE,                   128u,             52u,               51u,                                   16u,                                     15u, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/R_PBOX1_oC03_for_EL_CAN_V2_1_7854cc6e_Rx, /ActiveEcuC/Com/ComConfig/EIDC_oC03_for_EL_CAN_V2_1_Rx_0f13cc3b] */
  { /*    17 */                            TRUE,           TRUE,                   136u,             53u,               52u,                                   17u,                                     16u, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/VCU2_oC03_for_EL_CAN_V2_1_bea872d3_Rx, /ActiveEcuC/Com/ComConfig/EIDC_oC03_for_EL_CAN_V2_1_Rx_0f13cc3b] */
  { /*    18 */                            TRUE,           TRUE,                   144u,             54u,               53u,                                   18u,                                     17u, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/VCU3_oC03_for_EL_CAN_V2_1_a9801613_Rx, /ActiveEcuC/Com/ComConfig/EIDC_oC03_for_EL_CAN_V2_1_Rx_0f13cc3b] */
  { /*    19 */                            TRUE,           TRUE,                   152u,             55u,               54u,                                   19u,                                     18u, COM_NORMAL_TYPEOFRXPDUINFO }   /* [/ActiveEcuC/Com/ComConfig/VCU6_oC03_for_EL_CAN_V2_1_e209e1d3_Rx, /ActiveEcuC/Com/ComConfig/EIDC_oC03_for_EL_CAN_V2_1_Rx_0f13cc3b] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxSigInfo
  \brief  Contains all relevant information for Rx signals.
  \details
  Element             Description
  RxAccessInfoIdx     the index of the 1:1 relation pointing to Com_RxAccessInfo
  RxTOutInfoIdx       the index of the 0:1 relation pointing to Com_RxTOutInfo
  SignalProcessing
  ValidDlc            Minimum length of PDU required to completely receive the signal or signal group.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_RxSigInfoType, COM_CONST) Com_RxSigInfo[55] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    RxAccessInfoIdx  RxTOutInfoIdx                    SignalProcessing                          ValidDlc        Referable Keys */
  { /*     0 */              5u,                              0u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1u },  /* [/ActiveEcuC/Com/ComConfig/ABS3_oC03_for_EL_CAN_V2_1_5328da88_Rx] */
  { /*     1 */             26u,                              0u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       8u },  /* [/ActiveEcuC/Com/ComConfig/ABS3_oC03_for_EL_CAN_V2_1_5328da88_Rx] */
  { /*     2 */             49u,                              0u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2u },  /* [/ActiveEcuC/Com/ComConfig/ABS3_oC03_for_EL_CAN_V2_1_5328da88_Rx] */
  { /*     3 */             50u,                              0u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3u },  /* [/ActiveEcuC/Com/ComConfig/ABS3_oC03_for_EL_CAN_V2_1_5328da88_Rx] */
  { /*     4 */              7u,                              1u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1u },  /* [/ActiveEcuC/Com/ComConfig/BCM10_oC03_for_EL_CAN_V2_1_8175742c_Rx] */
  { /*     5 */             16u,                              1u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2u },  /* [/ActiveEcuC/Com/ComConfig/BCM10_oC03_for_EL_CAN_V2_1_8175742c_Rx] */
  { /*     6 */             24u,                              1u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2u },  /* [/ActiveEcuC/Com/ComConfig/BCM10_oC03_for_EL_CAN_V2_1_8175742c_Rx] */
  { /*     7 */             28u,                              1u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       8u },  /* [/ActiveEcuC/Com/ComConfig/BCM10_oC03_for_EL_CAN_V2_1_8175742c_Rx] */
  { /*     8 */              0u,                              2u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2u },  /* [/ActiveEcuC/Com/ComConfig/BCM17_oC03_for_EL_CAN_V2_1_e4ac4a6c_Rx] */
  { /*     9 */              1u,                              2u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3u },  /* [/ActiveEcuC/Com/ComConfig/BCM17_oC03_for_EL_CAN_V2_1_e4ac4a6c_Rx] */
  { /*    10 */             13u,                              2u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4u },  /* [/ActiveEcuC/Com/ComConfig/BCM17_oC03_for_EL_CAN_V2_1_e4ac4a6c_Rx] */
  { /*    11 */             19u,                              2u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       8u },  /* [/ActiveEcuC/Com/ComConfig/BCM17_oC03_for_EL_CAN_V2_1_e4ac4a6c_Rx] */
  { /*    12 */             51u,                              2u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2u },  /* [/ActiveEcuC/Com/ComConfig/BCM17_oC03_for_EL_CAN_V2_1_e4ac4a6c_Rx] */
  { /*    13 */              4u,                              3u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5u },  /* [/ActiveEcuC/Com/ComConfig/BCM23_oC03_for_EL_CAN_V2_1_cee8e051_Rx] */
  { /*    14 */              3u,                              4u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       8u },  /* [/ActiveEcuC/Com/ComConfig/BMS1_oC03_for_EL_CAN_V2_1_ab80ae92_Rx] */
  { /*    15 */              2u,                              5u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       7u },  /* [/ActiveEcuC/Com/ComConfig/BMS17_oC03_for_EL_CAN_V2_1_be27a4ae_Rx] */
  { /*    16 */             17u,                              6u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3u },  /* [/ActiveEcuC/Com/ComConfig/CSA1_oC03_for_EL_CAN_V2_1_ffb47aea_Rx] */
  { /*    17 */             23u,                              6u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3u },  /* [/ActiveEcuC/Com/ComConfig/CSA1_oC03_for_EL_CAN_V2_1_ffb47aea_Rx] */
  { /*    18 */             10u,                              7u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1u },  /* [/ActiveEcuC/Com/ComConfig/EEM1_oC03_for_EL_CAN_V2_1_5bdcd994_Rx] */
  { /*    19 */             31u,                              7u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1u },  /* [/ActiveEcuC/Com/ComConfig/EEM1_oC03_for_EL_CAN_V2_1_5bdcd994_Rx] */
  { /*    20 */             44u,                              7u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1u },  /* [/ActiveEcuC/Com/ComConfig/EEM1_oC03_for_EL_CAN_V2_1_5bdcd994_Rx] */
  { /*    21 */             29u,                              8u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1u },  /* [/ActiveEcuC/Com/ComConfig/GW1_oC03_for_EL_CAN_V2_1_48654b76_Rx] */
  { /*    22 */             30u,                              8u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2u },  /* [/ActiveEcuC/Com/ComConfig/GW1_oC03_for_EL_CAN_V2_1_48654b76_Rx] */
  { /*    23 */             34u,                              9u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3u },  /* [/ActiveEcuC/Com/ComConfig/HUT34_oC03_for_EL_CAN_V2_1_6fae3f7a_Rx] */
  { /*    24 */             35u,                              9u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3u },  /* [/ActiveEcuC/Com/ComConfig/HUT34_oC03_for_EL_CAN_V2_1_6fae3f7a_Rx] */
  { /*    25 */             36u,                              9u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       7u },  /* [/ActiveEcuC/Com/ComConfig/HUT34_oC03_for_EL_CAN_V2_1_6fae3f7a_Rx] */
  { /*    26 */             37u,                              9u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2u },  /* [/ActiveEcuC/Com/ComConfig/HUT34_oC03_for_EL_CAN_V2_1_6fae3f7a_Rx] */
  { /*    27 */             38u,                              9u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3u },  /* [/ActiveEcuC/Com/ComConfig/HUT34_oC03_for_EL_CAN_V2_1_6fae3f7a_Rx] */
  { /*    28 */             39u,                              9u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       6u },  /* [/ActiveEcuC/Com/ComConfig/HUT34_oC03_for_EL_CAN_V2_1_6fae3f7a_Rx] */
  { /*    29 */             40u,                              9u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4u },  /* [/ActiveEcuC/Com/ComConfig/HUT34_oC03_for_EL_CAN_V2_1_6fae3f7a_Rx] */
  { /*    30 */             41u,                              9u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5u },  /* [/ActiveEcuC/Com/ComConfig/HUT34_oC03_for_EL_CAN_V2_1_6fae3f7a_Rx] */
  { /*    31 */             42u,                              9u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5u },  /* [/ActiveEcuC/Com/ComConfig/HUT34_oC03_for_EL_CAN_V2_1_6fae3f7a_Rx] */
  { /*    32 */              8u, COM_NO_RXTOUTINFOIDXOFRXSIGINFO, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3u },  /* [/ActiveEcuC/Com/ComConfig/HUT54_oC03_for_EL_CAN_V2_1_82644d00_Rx] */
  { /*    33 */              9u, COM_NO_RXTOUTINFOIDXOFRXSIGINFO, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3u },  /* [/ActiveEcuC/Com/ComConfig/HUT54_oC03_for_EL_CAN_V2_1_82644d00_Rx] */
  { /*    34 */             11u, COM_NO_RXTOUTINFOIDXOFRXSIGINFO, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1u },  /* [/ActiveEcuC/Com/ComConfig/HUT54_oC03_for_EL_CAN_V2_1_82644d00_Rx] */
  { /*    35 */             12u, COM_NO_RXTOUTINFOIDXOFRXSIGINFO, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1u },  /* [/ActiveEcuC/Com/ComConfig/HUT54_oC03_for_EL_CAN_V2_1_82644d00_Rx] */
  { /*    36 */             25u, COM_NO_RXTOUTINFOIDXOFRXSIGINFO, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2u },  /* [/ActiveEcuC/Com/ComConfig/HUT54_oC03_for_EL_CAN_V2_1_82644d00_Rx] */
  { /*    37 */             43u, COM_NO_RXTOUTINFOIDXOFRXSIGINFO, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1u },  /* [/ActiveEcuC/Com/ComConfig/HUT54_oC03_for_EL_CAN_V2_1_82644d00_Rx] */
  { /*    38 */             45u, COM_NO_RXTOUTINFOIDXOFRXSIGINFO, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3u },  /* [/ActiveEcuC/Com/ComConfig/HUT54_oC03_for_EL_CAN_V2_1_82644d00_Rx] */
  { /*    39 */             52u, COM_NO_RXTOUTINFOIDXOFRXSIGINFO, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2u },  /* [/ActiveEcuC/Com/ComConfig/HUT54_oC03_for_EL_CAN_V2_1_82644d00_Rx] */
  { /*    40 */             53u, COM_NO_RXTOUTINFOIDXOFRXSIGINFO, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2u },  /* [/ActiveEcuC/Com/ComConfig/HUT54_oC03_for_EL_CAN_V2_1_82644d00_Rx] */
  { /*    41 */             54u, COM_NO_RXTOUTINFOIDXOFRXSIGINFO, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3u },  /* [/ActiveEcuC/Com/ComConfig/HUT54_oC03_for_EL_CAN_V2_1_82644d00_Rx] */
  { /*    42 */             14u,                             10u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       6u },  /* [/ActiveEcuC/Com/ComConfig/IP2_oC03_for_EL_CAN_V2_1_65941076_Rx] */
  { /*    43 */             15u,                             10u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4u },  /* [/ActiveEcuC/Com/ComConfig/IP2_oC03_for_EL_CAN_V2_1_65941076_Rx] */
  { /*    44 */             18u,                             11u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       6u },  /* [/ActiveEcuC/Com/ComConfig/MCU_5_oC03_for_EL_CAN_V2_1_002cb201_Rx] */
  { /*    45 */             20u,                             12u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       8u },  /* [/ActiveEcuC/Com/ComConfig/OBC3_oC03_for_EL_CAN_V2_1_158aa3d5_Rx] */
  { /*    46 */              6u,                             13u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1u },  /* [/ActiveEcuC/Com/ComConfig/PEPS2_oC03_for_EL_CAN_V2_1_d41abfa7_Rx] */
  { /*    47 */             27u,                             13u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       8u },  /* [/ActiveEcuC/Com/ComConfig/PEPS2_oC03_for_EL_CAN_V2_1_d41abfa7_Rx] */
  { /*    48 */             32u,                             13u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2u },  /* [/ActiveEcuC/Com/ComConfig/PEPS2_oC03_for_EL_CAN_V2_1_d41abfa7_Rx] */
  { /*    49 */             33u,                             13u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2u },  /* [/ActiveEcuC/Com/ComConfig/PEPS2_oC03_for_EL_CAN_V2_1_d41abfa7_Rx] */
    /* Index    RxAccessInfoIdx  RxTOutInfoIdx                    SignalProcessing                          ValidDlc        Referable Keys */
  { /*    50 */             22u,                             14u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5u },  /* [/ActiveEcuC/Com/ComConfig/RMCU4_oC03_for_EL_CAN_V2_1_55159990_Rx] */
  { /*    51 */             21u,                             15u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2u },  /* [/ActiveEcuC/Com/ComConfig/R_PBOX1_oC03_for_EL_CAN_V2_1_7854cc6e_Rx] */
  { /*    52 */             48u,                             16u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3u },  /* [/ActiveEcuC/Com/ComConfig/VCU2_oC03_for_EL_CAN_V2_1_bea872d3_Rx] */
  { /*    53 */             47u,                             17u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3u },  /* [/ActiveEcuC/Com/ComConfig/VCU3_oC03_for_EL_CAN_V2_1_a9801613_Rx] */
  { /*    54 */             46u,                             18u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4u }   /* [/ActiveEcuC/Com/ComConfig/VCU6_oC03_for_EL_CAN_V2_1_e209e1d3_Rx] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxTOutInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxTOutInfo
  \brief  Contains all relevant information for signal based and I-PDu based Rx deadline monitoring.
  \details
  Element                        Description
  CbkRxTOutFuncPtrIndEndIdx      the end index of the 0:n relation pointing to Com_CbkRxTOutFuncPtrInd
  CbkRxTOutFuncPtrIndStartIdx    the start index of the 0:n relation pointing to Com_CbkRxTOutFuncPtrInd
  Factor                         Deadline monitoring timeout factor.
  FirstFactor                    Timeout factor for first deadline monitoring.
  RxPduInfoIdx                   the index of the 1:1 relation pointing to Com_RxPduInfo
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_RxTOutInfoType, COM_CONST) Com_RxTOutInfo[19] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    CbkRxTOutFuncPtrIndEndIdx  CbkRxTOutFuncPtrIndStartIdx  Factor  FirstFactor  RxPduInfoIdx        Referable Keys */
  { /*     0 */                        4u,                          0u,     3u,          0u,           0u },  /* [/ActiveEcuC/Com/ComConfig/CheckSum_ABS3_oABS3_oC03_for_EL_CAN_V2_1_5745e086_Rx, /ActiveEcuC/Com/ComConfig/ABS3_oC03_for_EL_CAN_V2_1_5328da88_Rx, /ActiveEcuC/Com/ComConfig/ABS3_oC03_for_EL_CAN_V2_1_5328da88_RxPduBased, /ActiveEcuC/Com/ComConfig/RollingCounter_ABS3_oABS3_oC03_for_EL_CAN_V2_1_b6ac7000_Rx, /ActiveEcuC/Com/ComConfig/VehSpdVld_oABS3_oC03_for_EL_CAN_V2_1_32497dd3_Rx, /ActiveEcuC/Com/ComConfig/VehSpd_oABS3_oC03_for_EL_CAN_V2_1_23260d94_Rx] */
  { /*     1 */                        8u,                          4u,     6u,          0u,           1u },  /* [/ActiveEcuC/Com/ComConfig/Checksum_BCM10_oBCM10_oC03_for_EL_CAN_V2_1_819e75d3_Rx, /ActiveEcuC/Com/ComConfig/BCM10_oC03_for_EL_CAN_V2_1_8175742c_Rx, /ActiveEcuC/Com/ComConfig/BCM10_oC03_for_EL_CAN_V2_1_8175742c_RxPduBased, /ActiveEcuC/Com/ComConfig/LTurnLampWorkCmd_oBCM10_oC03_for_EL_CAN_V2_1_7a1a08f4_Rx, /ActiveEcuC/Com/ComConfig/RTurnLmpWorkCmd_oBCM10_oC03_for_EL_CAN_V2_1_10ea9ba1_Rx, /ActiveEcuC/Com/ComConfig/Rollingcounter_BCM10_oBCM10_oC03_for_EL_CAN_V2_1_6dd2f1f9_Rx] */
  { /*     2 */                       13u,                          8u,     6u,          0u,           2u },  /* [/ActiveEcuC/Com/ComConfig/AnimationReq_oBCM17_oC03_for_EL_CAN_V2_1_1db28c46_Rx, /ActiveEcuC/Com/ComConfig/BCM17_oC03_for_EL_CAN_V2_1_e4ac4a6c_Rx, /ActiveEcuC/Com/ComConfig/BCM17_oC03_for_EL_CAN_V2_1_e4ac4a6c_RxPduBased, /ActiveEcuC/Com/ComConfig/ApproachLightAnimationType_oBCM17_oC03_for_EL_CAN_V2_1_5b20a81e_Rx, /ActiveEcuC/Com/ComConfig/GoodbyeAnimationType_oBCM17_oC03_for_EL_CAN_V2_1_bc8c4dab_Rx, /ActiveEcuC/Com/ComConfig/MecDancAnimationType_oBCM17_oC03_for_EL_CAN_V2_1_6bb5a98f_Rx, /ActiveEcuC/Com/ComConfig/WelcomeAnimationType_oBCM17_oC03_for_EL_CAN_V2_1_c76d0f7a_Rx] */
  { /*     3 */                       14u,                         13u,    11u,          0u,           3u },  /* [/ActiveEcuC/Com/ComConfig/CEMDetminCdnSts_oBCM23_oC03_for_EL_CAN_V2_1_df6348d5_Rx, /ActiveEcuC/Com/ComConfig/BCM23_oC03_for_EL_CAN_V2_1_cee8e051_Rx, /ActiveEcuC/Com/ComConfig/BCM23_oC03_for_EL_CAN_V2_1_cee8e051_RxPduBased] */
  { /*     4 */                       15u,                         14u,     2u,          0u,           4u },  /* [/ActiveEcuC/Com/ComConfig/BMS_SOC_oBMS1_oC03_for_EL_CAN_V2_1_a261d1ce_Rx, /ActiveEcuC/Com/ComConfig/BMS1_oC03_for_EL_CAN_V2_1_ab80ae92_Rx, /ActiveEcuC/Com/ComConfig/BMS1_oC03_for_EL_CAN_V2_1_ab80ae92_RxPduBased] */
  { /*     5 */                       16u,                         15u,    11u,          0u,           5u },  /* [/ActiveEcuC/Com/ComConfig/BMS_DCChrgConnect_oBMS17_oC03_for_EL_CAN_V2_1_91db617c_Rx, /ActiveEcuC/Com/ComConfig/BMS17_oC03_for_EL_CAN_V2_1_be27a4ae_Rx, /ActiveEcuC/Com/ComConfig/BMS17_oC03_for_EL_CAN_V2_1_be27a4ae_RxPduBased] */
  { /*     6 */                       18u,                         16u,     3u,          0u,           6u },  /* [/ActiveEcuC/Com/ComConfig/LTurnLmpSwtSts_oCSA1_oC03_for_EL_CAN_V2_1_458e5c96_Rx, /ActiveEcuC/Com/ComConfig/CSA1_oC03_for_EL_CAN_V2_1_ffb47aea_Rx, /ActiveEcuC/Com/ComConfig/CSA1_oC03_for_EL_CAN_V2_1_ffb47aea_RxPduBased, /ActiveEcuC/Com/ComConfig/RTurnLmpSwtSts_oCSA1_oC03_for_EL_CAN_V2_1_2fe59187_Rx] */
  { /*     7 */                       21u,                         18u,    11u,          0u,           7u },  /* [/ActiveEcuC/Com/ComConfig/DeepSlpCmd_oEEM1_oC03_for_EL_CAN_V2_1_41fb7d93_Rx, /ActiveEcuC/Com/ComConfig/EEM1_oC03_for_EL_CAN_V2_1_5bdcd994_Rx, /ActiveEcuC/Com/ComConfig/EEM1_oC03_for_EL_CAN_V2_1_5bdcd994_RxPduBased, /ActiveEcuC/Com/ComConfig/Stat_PwrSv_Lvl_oEEM1_oC03_for_EL_CAN_V2_1_a4eaa63e_Rx, /ActiveEcuC/Com/ComConfig/TranPMode_Sts_oEEM1_oC03_for_EL_CAN_V2_1_a5a3838d_Rx] */
  { /*     8 */                       23u,                         21u,     6u,          0u,           8u },  /* [/ActiveEcuC/Com/ComConfig/ScenarioID_oGW1_oC03_for_EL_CAN_V2_1_b0249678_Rx, /ActiveEcuC/Com/ComConfig/GW1_oC03_for_EL_CAN_V2_1_48654b76_Rx, /ActiveEcuC/Com/ComConfig/GW1_oC03_for_EL_CAN_V2_1_48654b76_RxPduBased, /ActiveEcuC/Com/ComConfig/ScenarioReq_oGW1_oC03_for_EL_CAN_V2_1_d81adfac_Rx] */
  { /*     9 */                       32u,                         23u,   101u,          0u,           9u },  /* [/ActiveEcuC/Com/ComConfig/TimeIndcn_oHUT34_oC03_for_EL_CAN_V2_1_d29435a0_Rx, /ActiveEcuC/Com/ComConfig/HUT34_oC03_for_EL_CAN_V2_1_6fae3f7a_Rx, /ActiveEcuC/Com/ComConfig/HUT34_oC03_for_EL_CAN_V2_1_6fae3f7a_RxPduBased, /ActiveEcuC/Com/ComConfig/TimeMod_oHUT34_oC03_for_EL_CAN_V2_1_baa135ee_Rx, /ActiveEcuC/Com/ComConfig/Time_Day_oHUT34_oC03_for_EL_CAN_V2_1_5996a937_Rx, /ActiveEcuC/Com/ComConfig/Time_Hour_oHUT34_oC03_for_EL_CAN_V2_1_2c4ebd6a_Rx, /ActiveEcuC/Com/ComConfig/Time_Minutes_oHUT34_oC03_for_EL_CAN_V2_1_da3ecd44_Rx, /ActiveEcuC/Com/ComConfig/Time_Month_oHUT34_oC03_for_EL_CAN_V2_1_33ed510d_Rx, /ActiveEcuC/Com/ComConfig/Time_Second_oHUT34_oC03_for_EL_CAN_V2_1_9732895b_Rx, /ActiveEcuC/Com/ComConfig/Time_Year_Left_oHUT34_oC03_for_EL_CAN_V2_1_f1a91267_Rx, /ActiveEcuC/Com/ComConfig/Time_Year_Right_oHUT34_oC03_for_EL_CAN_V2_1_fa890340_Rx] */
  { /*    10 */                       34u,                         32u,     6u,          0u,          11u },  /* [/ActiveEcuC/Com/ComConfig/IP_VehTotDistanceValid_oIP2_oC03_for_EL_CAN_V2_1_234ac38e_Rx, /ActiveEcuC/Com/ComConfig/IP2_oC03_for_EL_CAN_V2_1_65941076_Rx, /ActiveEcuC/Com/ComConfig/IP2_oC03_for_EL_CAN_V2_1_65941076_RxPduBased, /ActiveEcuC/Com/ComConfig/IP_VehTotDistance_oIP2_oC03_for_EL_CAN_V2_1_a238a7cc_Rx] */
  { /*    11 */                       35u,                         34u,     2u,          0u,          12u },  /* [/ActiveEcuC/Com/ComConfig/MCU_ActRotSpd_oMCU_5_oC03_for_EL_CAN_V2_1_c2eb67f0_Rx, /ActiveEcuC/Com/ComConfig/MCU_5_oC03_for_EL_CAN_V2_1_002cb201_Rx, /ActiveEcuC/Com/ComConfig/MCU_5_oC03_for_EL_CAN_V2_1_002cb201_RxPduBased] */
  { /*    12 */                       36u,                         35u,    11u,          0u,          13u },  /* [/ActiveEcuC/Com/ComConfig/OBC_CCLineConnectSts_oOBC3_oC03_for_EL_CAN_V2_1_a7854723_Rx, /ActiveEcuC/Com/ComConfig/OBC3_oC03_for_EL_CAN_V2_1_158aa3d5_Rx, /ActiveEcuC/Com/ComConfig/OBC3_oC03_for_EL_CAN_V2_1_158aa3d5_RxPduBased] */
  { /*    13 */                       40u,                         36u,     6u,          0u,          14u },  /* [/ActiveEcuC/Com/ComConfig/CheckSum_PEPS2_oPEPS2_oC03_for_EL_CAN_V2_1_06064851_Rx, /ActiveEcuC/Com/ComConfig/PEPS2_oC03_for_EL_CAN_V2_1_d41abfa7_Rx, /ActiveEcuC/Com/ComConfig/PEPS2_oC03_for_EL_CAN_V2_1_d41abfa7_RxPduBased, /ActiveEcuC/Com/ComConfig/RollingCounter_PEPS2_oPEPS2_oC03_for_EL_CAN_V2_1_9bd00531_Rx, /ActiveEcuC/Com/ComConfig/SysPowerModVld_oPEPS2_oC03_for_EL_CAN_V2_1_b6c20e3c_Rx, /ActiveEcuC/Com/ComConfig/SysPowerMod_oPEPS2_oC03_for_EL_CAN_V2_1_37fb939a_Rx] */
  { /*    14 */                       41u,                         40u,     2u,          0u,          15u },  /* [/ActiveEcuC/Com/ComConfig/RMCU_ActRotSpd_oRMCU4_oC03_for_EL_CAN_V2_1_a08a2435_Rx, /ActiveEcuC/Com/ComConfig/RMCU4_oC03_for_EL_CAN_V2_1_55159990_Rx, /ActiveEcuC/Com/ComConfig/RMCU4_oC03_for_EL_CAN_V2_1_55159990_RxPduBased] */
  { /*    15 */                       42u,                         41u,     6u,          0u,          16u },  /* [/ActiveEcuC/Com/ComConfig/PosnLmpOutpSts_R_PBox_oR_PBOX1_oC03_for_EL_CAN_V2_1_c63ace4d_Rx, /ActiveEcuC/Com/ComConfig/R_PBOX1_oC03_for_EL_CAN_V2_1_7854cc6e_Rx, /ActiveEcuC/Com/ComConfig/R_PBOX1_oC03_for_EL_CAN_V2_1_7854cc6e_RxPduBased] */
  { /*    16 */                       43u,                         42u,     6u,          0u,          17u },  /* [/ActiveEcuC/Com/ComConfig/VCU_GearSts_oVCU2_oC03_for_EL_CAN_V2_1_71c2293d_Rx, /ActiveEcuC/Com/ComConfig/VCU2_oC03_for_EL_CAN_V2_1_bea872d3_Rx, /ActiveEcuC/Com/ComConfig/VCU2_oC03_for_EL_CAN_V2_1_bea872d3_RxPduBased] */
  { /*    17 */                       44u,                         43u,    11u,          0u,          18u },  /* [/ActiveEcuC/Com/ComConfig/VCU_ChrgnSts_oVCU3_oC03_for_EL_CAN_V2_1_87b3fa1f_Rx, /ActiveEcuC/Com/ComConfig/VCU3_oC03_for_EL_CAN_V2_1_a9801613_Rx, /ActiveEcuC/Com/ComConfig/VCU3_oC03_for_EL_CAN_V2_1_a9801613_RxPduBased] */
  { /*    18 */                       45u,                         44u,     2u,          0u,          19u }   /* [/ActiveEcuC/Com/ComConfig/VCU_BrkPedlSts_oVCU6_oC03_for_EL_CAN_V2_1_66fed013_Rx, /ActiveEcuC/Com/ComConfig/VCU6_oC03_for_EL_CAN_V2_1_e209e1d3_Rx, /ActiveEcuC/Com/ComConfig/VCU6_oC03_for_EL_CAN_V2_1_e209e1d3_RxPduBased] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxModeFalse
**********************************************************************************************************************/
/** 
  \var    Com_TxModeFalse
  \brief  Contains all relevant information for transmission mode false.
  \details
  Element     Description
  Periodic    TRUE if transmission mode contains a cyclic part.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_TxModeFalseType, COM_CONST) Com_TxModeFalse[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Periodic        Referable Keys */
  { /*     0 */    FALSE },  /* [/ActiveEcuC/Com/ComConfig/ComIPdu_userData_tx] */
  { /*     1 */     TRUE }   /* [/ActiveEcuC/Com/ComConfig/EIDC1_oC03_for_EL_CAN_V2_1_4a10c7b4_Tx] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxModeInfo
**********************************************************************************************************************/
/** 
  \var    Com_TxModeInfo
  \brief  Contains all relevant information for transmission mode handling.
  \details
  Element     Description
  InitMode    Initial transmission mode selector of the Tx I-PDU.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_TxModeInfoType, COM_CONST) Com_TxModeInfo[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    InitMode        Referable Keys */
  { /*     0 */     TRUE },  /* [/ActiveEcuC/Com/ComConfig/ComIPdu_userData_tx] */
  { /*     1 */     TRUE }   /* [/ActiveEcuC/Com/ComConfig/EIDC1_oC03_for_EL_CAN_V2_1_4a10c7b4_Tx] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxModeTrue
**********************************************************************************************************************/
/** 
  \var    Com_TxModeTrue
  \brief  Contains all relevant information for transmission mode true.
  \details
  Element     Description
  Periodic    TRUE if transmission mode contains a cyclic part.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_TxModeTrueType, COM_CONST) Com_TxModeTrue[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Periodic        Referable Keys */
  { /*     0 */    FALSE },  /* [/ActiveEcuC/Com/ComConfig/ComIPdu_userData_tx] */
  { /*     1 */     TRUE }   /* [/ActiveEcuC/Com/ComConfig/EIDC1_oC03_for_EL_CAN_V2_1_4a10c7b4_Tx] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxPduInfo
**********************************************************************************************************************/
/** 
  \var    Com_TxPduInfo
  \brief  Contains all relevant information for Tx I-PDUs.
  \details
  Element                                Description
  TxPduInitValueUsed                     TRUE, if the 0:n relation has 1 relation pointing to Com_TxPduInitValue
  ExternalId                             External ID used to call PduR_ComTransmit().
  IPduGroupInfoOfTxPduInfoIndEndIdx      the end index of the 0:n relation pointing to Com_IPduGroupInfoOfTxPduInfoInd
  IPduGroupInfoOfTxPduInfoIndStartIdx    the start index of the 0:n relation pointing to Com_IPduGroupInfoOfTxPduInfoInd
  MetaDataLength                         Length of MetaData.
  TxBufferLength                         the number of relations pointing to Com_TxBuffer
  TxPduInitValueEndIdx                   the end index of the 0:n relation pointing to Com_TxPduInitValue
  TxPduInitValueStartIdx                 the start index of the 0:n relation pointing to Com_TxPduInitValue
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_TxPduInfoType, COM_CONST) Com_TxPduInfo[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    TxPduInitValueUsed  ExternalId                               IPduGroupInfoOfTxPduInfoIndEndIdx                    IPduGroupInfoOfTxPduInfoIndStartIdx                    MetaDataLength  TxBufferLength  TxPduInitValueEndIdx  TxPduInitValueStartIdx        Referable Keys */
  { /*     0 */               TRUE,          PduRConf_PduRSrcPdu_PduRSrcPdu, COM_NO_IPDUGROUPINFOOFTXPDUINFOINDENDIDXOFTXPDUINFO, COM_NO_IPDUGROUPINFOOFTXPDUINFOINDSTARTIDXOFTXPDUINFO,             0u,             6u,                   6u,                     0u },  /* [/ActiveEcuC/Com/ComConfig/ComIPdu_userData_tx] */
  { /*     1 */               TRUE, PduRConf_PduRSrcPdu_PduRSrcPdu_e9672331,                                                  1u,                                                    0u,             0u,             8u,                  14u,                     6u }   /* [/ActiveEcuC/Com/ComConfig/EIDC1_oC03_for_EL_CAN_V2_1_4a10c7b4_Tx, /ActiveEcuC/Com/ComConfig/EIDC_oC03_for_EL_CAN_V2_1_Tx_59496bbd] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxPduInitValue
**********************************************************************************************************************/
/** 
  \var    Com_TxPduInitValue
  \brief  Initial values used for Tx I-PDU buffer initialization.
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_TxPduInitValueType, COM_CONST) Com_TxPduInitValue[14] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     TxPduInitValue      Referable Keys */
  /*     0 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/ComIPdu_userData_tx] */
  /*     1 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/ComIPdu_userData_tx] */
  /*     2 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/ComIPdu_userData_tx] */
  /*     3 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/ComIPdu_userData_tx] */
  /*     4 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/ComIPdu_userData_tx] */
  /*     5 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/ComIPdu_userData_tx] */
  /*     6 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/EIDC1_oC03_for_EL_CAN_V2_1_4a10c7b4_Tx] */
  /*     7 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/EIDC1_oC03_for_EL_CAN_V2_1_4a10c7b4_Tx] */
  /*     8 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/EIDC1_oC03_for_EL_CAN_V2_1_4a10c7b4_Tx] */
  /*     9 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/EIDC1_oC03_for_EL_CAN_V2_1_4a10c7b4_Tx] */
  /*    10 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/EIDC1_oC03_for_EL_CAN_V2_1_4a10c7b4_Tx] */
  /*    11 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/EIDC1_oC03_for_EL_CAN_V2_1_4a10c7b4_Tx] */
  /*    12 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/EIDC1_oC03_for_EL_CAN_V2_1_4a10c7b4_Tx] */
  /*    13 */           0x00u   /* [/ActiveEcuC/Com/ComConfig/EIDC1_oC03_for_EL_CAN_V2_1_4a10c7b4_Tx] */
};
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxSigInfo
**********************************************************************************************************************/
/** 
  \var    Com_TxSigInfo
  \brief  Contains all relevant information for Tx signals and group signals.
  \details
  Element                   Description
  BitLength                 Bit length of the signal or group signal.
  BitPosition               Little endian bit position of the signal or group signal within the I-PDU.
  BusAcc                    BUS access algorithm for signal or group signal packing / un-packing.
  StartByteInPduPosition    Start Byte position of the signal or group signal within the I-PDU.
  TxBufferLength            the number of relations pointing to Com_TxBuffer
  TxBufferStartIdx          the start index of the 0:n relation pointing to Com_TxBuffer
  TxPduInfoIdx              the index of the 1:1 relation pointing to Com_TxPduInfo
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_TxSigInfoType, COM_CONST) Com_TxSigInfo[12] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    BitLength  BitPosition  BusAcc                      StartByteInPduPosition  TxBufferLength  TxBufferStartIdx  TxPduInfoIdx        Referable Keys */
  { /*     0 */        1u,         22u, COM_NBIT_BUSACCOFTXSIGINFO,                     2u,             1u,               8u,           1u },  /* [/ActiveEcuC/Com/ComConfig/ChrgDispPatFailSts_oEIDC1_oC03_for_EL_CAN_V2_1_ad1e97ef_Tx, /ActiveEcuC/Com/ComConfig/EIDC1_oC03_for_EL_CAN_V2_1_4a10c7b4_Tx] */
  { /*     1 */        1u,         16u, COM_NBIT_BUSACCOFTXSIGINFO,                     2u,             1u,               2u,           0u },  /* [/ActiveEcuC/Com/ComConfig/ComSignal_userData_byte2_tx, /ActiveEcuC/Com/ComConfig/ComIPdu_userData_tx] */
  { /*     2 */        3u,         24u, COM_NBIT_BUSACCOFTXSIGINFO,                     3u,             1u,               3u,           0u },  /* [/ActiveEcuC/Com/ComConfig/ComSignal_userdata_Byte3_tx, /ActiveEcuC/Com/ComConfig/ComIPdu_userData_tx] */
  { /*     3 */        3u,         24u, COM_NBIT_BUSACCOFTXSIGINFO,                     3u,             1u,               9u,           1u },  /* [/ActiveEcuC/Com/ComConfig/CurrChrgDispSts_oEIDC1_oC03_for_EL_CAN_V2_1_b91c73c4_Tx, /ActiveEcuC/Com/ComConfig/EIDC1_oC03_for_EL_CAN_V2_1_4a10c7b4_Tx] */
  { /*     4 */        3u,         12u, COM_NBIT_BUSACCOFTXSIGINFO,                     1u,             1u,               7u,           1u },  /* [/ActiveEcuC/Com/ComConfig/CurrEmojiSts_oEIDC1_oC03_for_EL_CAN_V2_1_6bd59cd2_Tx, /ActiveEcuC/Com/ComConfig/EIDC1_oC03_for_EL_CAN_V2_1_4a10c7b4_Tx] */
  { /*     5 */        3u,         16u, COM_NBIT_BUSACCOFTXSIGINFO,                     2u,             1u,               8u,           1u },  /* [/ActiveEcuC/Com/ComConfig/CurrRemdSts_oEIDC1_oC03_for_EL_CAN_V2_1_d08f6960_Tx, /ActiveEcuC/Com/ComConfig/EIDC1_oC03_for_EL_CAN_V2_1_4a10c7b4_Tx] */
  { /*     6 */        2u,         10u, COM_NBIT_BUSACCOFTXSIGINFO,                     1u,             1u,               7u,           1u },  /* [/ActiveEcuC/Com/ComConfig/CurrTopicSts_oEIDC1_oC03_for_EL_CAN_V2_1_fe35aa4e_Tx, /ActiveEcuC/Com/ComConfig/EIDC1_oC03_for_EL_CAN_V2_1_4a10c7b4_Tx] */
  { /*     7 */        3u,         19u, COM_NBIT_BUSACCOFTXSIGINFO,                     2u,             1u,               8u,           1u },  /* [/ActiveEcuC/Com/ComConfig/CurrWelcomeSts_oEIDC1_oC03_for_EL_CAN_V2_1_adc4e5a0_Tx, /ActiveEcuC/Com/ComConfig/EIDC1_oC03_for_EL_CAN_V2_1_4a10c7b4_Tx] */
  { /*     8 */        3u,         27u, COM_NBIT_BUSACCOFTXSIGINFO,                     3u,             1u,               9u,           1u },  /* [/ActiveEcuC/Com/ComConfig/CurrWordSts_oEIDC1_oC03_for_EL_CAN_V2_1_141f7025_Tx, /ActiveEcuC/Com/ComConfig/EIDC1_oC03_for_EL_CAN_V2_1_4a10c7b4_Tx] */
  { /*     9 */        2u,          8u, COM_NBIT_BUSACCOFTXSIGINFO,                     1u,             1u,               7u,           1u },  /* [/ActiveEcuC/Com/ComConfig/EIDCOpenFBSts_oEIDC1_oC03_for_EL_CAN_V2_1_c910b9b6_Tx, /ActiveEcuC/Com/ComConfig/EIDC1_oC03_for_EL_CAN_V2_1_4a10c7b4_Tx] */
  { /*    10 */        1u,         23u, COM_NBIT_BUSACCOFTXSIGINFO,                     2u,             1u,               8u,           1u },  /* [/ActiveEcuC/Com/ComConfig/TurnRemdFailSts_oEIDC1_oC03_for_EL_CAN_V2_1_5d16f6d4_Tx, /ActiveEcuC/Com/ComConfig/EIDC1_oC03_for_EL_CAN_V2_1_4a10c7b4_Tx] */
  { /*    11 */        1u,         15u, COM_NBIT_BUSACCOFTXSIGINFO,                     1u,             1u,               7u,           1u }   /* [/ActiveEcuC/Com/ComConfig/WelcomePatFailSts_oEIDC1_oC03_for_EL_CAN_V2_1_29fa7824_Tx, /ActiveEcuC/Com/ComConfig/EIDC1_oC03_for_EL_CAN_V2_1_4a10c7b4_Tx] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_CurrentTxMode
**********************************************************************************************************************/
/** 
  \var    Com_CurrentTxMode
  \brief  Current transmission mode state of all Tx I-PDUs.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_CurrentTxModeType, COM_VAR_NOINIT) Com_CurrentTxMode[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/ComIPdu_userData_tx] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/EIDC1_oC03_for_EL_CAN_V2_1_4a10c7b4_Tx, /ActiveEcuC/Com/ComConfig/EIDC_oC03_for_EL_CAN_V2_1_Tx_59496bbd] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_CycleTimeCnt
**********************************************************************************************************************/
/** 
  \var    Com_CycleTimeCnt
  \brief  Current counter value of cyclic transmission.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_CycleTimeCntType, COM_VAR_NOINIT) Com_CycleTimeCnt[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/ComIPdu_userData_tx] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/EIDC1_oC03_for_EL_CAN_V2_1_4a10c7b4_Tx, /ActiveEcuC/Com/ComConfig/EIDC_oC03_for_EL_CAN_V2_1_Tx_59496bbd] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_CyclicSendRequest
**********************************************************************************************************************/
/** 
  \var    Com_CyclicSendRequest
  \brief  Cyclic send request flag used to indicate cyclic transmission mode for all Tx I-PDU.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_CyclicSendRequestType, COM_VAR_NOINIT) Com_CyclicSendRequest[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/ComIPdu_userData_tx] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/EIDC1_oC03_for_EL_CAN_V2_1_4a10c7b4_Tx, /ActiveEcuC/Com/ComConfig/EIDC_oC03_for_EL_CAN_V2_1_Tx_59496bbd] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_HandleRxPduDeferred
**********************************************************************************************************************/
/** 
  \var    Com_HandleRxPduDeferred
  \brief  Array indicating received Rx I-PDUs to be processed deferred within the next call of Com_MainfunctionRx().
*/ 
#define COM_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_HandleRxPduDeferredUType, COM_VAR_NOINIT) Com_HandleRxPduDeferred;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/ABS3_oC03_for_EL_CAN_V2_1_5328da88_Rx] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/BCM10_oC03_for_EL_CAN_V2_1_8175742c_Rx] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/BCM17_oC03_for_EL_CAN_V2_1_e4ac4a6c_Rx] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/BCM23_oC03_for_EL_CAN_V2_1_cee8e051_Rx] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/BMS1_oC03_for_EL_CAN_V2_1_ab80ae92_Rx] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/BMS17_oC03_for_EL_CAN_V2_1_be27a4ae_Rx] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/CSA1_oC03_for_EL_CAN_V2_1_ffb47aea_Rx] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/EEM1_oC03_for_EL_CAN_V2_1_5bdcd994_Rx] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/GW1_oC03_for_EL_CAN_V2_1_48654b76_Rx] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/HUT34_oC03_for_EL_CAN_V2_1_6fae3f7a_Rx] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/HUT54_oC03_for_EL_CAN_V2_1_82644d00_Rx] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/IP2_oC03_for_EL_CAN_V2_1_65941076_Rx] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/MCU_5_oC03_for_EL_CAN_V2_1_002cb201_Rx] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/OBC3_oC03_for_EL_CAN_V2_1_158aa3d5_Rx] */
  /*    14 */  /* [/ActiveEcuC/Com/ComConfig/PEPS2_oC03_for_EL_CAN_V2_1_d41abfa7_Rx] */
  /*    15 */  /* [/ActiveEcuC/Com/ComConfig/RMCU4_oC03_for_EL_CAN_V2_1_55159990_Rx] */
  /*    16 */  /* [/ActiveEcuC/Com/ComConfig/R_PBOX1_oC03_for_EL_CAN_V2_1_7854cc6e_Rx] */
  /*    17 */  /* [/ActiveEcuC/Com/ComConfig/VCU2_oC03_for_EL_CAN_V2_1_bea872d3_Rx] */
  /*    18 */  /* [/ActiveEcuC/Com/ComConfig/VCU3_oC03_for_EL_CAN_V2_1_a9801613_Rx] */
  /*    19 */  /* [/ActiveEcuC/Com/ComConfig/VCU6_oC03_for_EL_CAN_V2_1_e209e1d3_Rx] */

#define COM_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_IPduGroupState
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_IPduGroupStateType, COM_VAR_NOINIT) Com_IPduGroupState[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/EIDC_oC03_for_EL_CAN_V2_1_Rx_0f13cc3b, /ActiveEcuC/Com/ComConfig/RMCU4_oC03_for_EL_CAN_V2_1_55159990_Rx, /ActiveEcuC/Com/ComConfig/BCM17_oC03_for_EL_CAN_V2_1_e4ac4a6c_Rx, /ActiveEcuC/Com/ComConfig/PEPS2_oC03_for_EL_CAN_V2_1_d41abfa7_Rx, /ActiveEcuC/Com/ComConfig/BCM10_oC03_for_EL_CAN_V2_1_8175742c_Rx, /ActiveEcuC/Com/ComConfig/CSA1_oC03_for_EL_CAN_V2_1_ffb47aea_Rx, /ActiveEcuC/Com/ComConfig/VCU2_oC03_for_EL_CAN_V2_1_bea872d3_Rx, /ActiveEcuC/Com/ComConfig/OBC3_oC03_for_EL_CAN_V2_1_158aa3d5_Rx, /ActiveEcuC/Com/ComConfig/HUT34_oC03_for_EL_CAN_V2_1_6fae3f7a_Rx, /ActiveEcuC/Com/ComConfig/HUT54_oC03_for_EL_CAN_V2_1_82644d00_Rx, /ActiveEcuC/Com/ComConfig/MCU_5_oC03_for_EL_CAN_V2_1_002cb201_Rx, /ActiveEcuC/Com/ComConfig/BMS17_oC03_for_EL_CAN_V2_1_be27a4ae_Rx, /ActiveEcuC/Com/ComConfig/GW1_oC03_for_EL_CAN_V2_1_48654b76_Rx, /ActiveEcuC/Com/ComConfig/VCU3_oC03_for_EL_CAN_V2_1_a9801613_Rx, /ActiveEcuC/Com/ComConfig/ABS3_oC03_for_EL_CAN_V2_1_5328da88_Rx, /ActiveEcuC/Com/ComConfig/R_PBOX1_oC03_for_EL_CAN_V2_1_7854cc6e_Rx, /ActiveEcuC/Com/ComConfig/EEM1_oC03_for_EL_CAN_V2_1_5bdcd994_Rx, /ActiveEcuC/Com/ComConfig/IP2_oC03_for_EL_CAN_V2_1_65941076_Rx, /ActiveEcuC/Com/ComConfig/BCM23_oC03_for_EL_CAN_V2_1_cee8e051_Rx, /ActiveEcuC/Com/ComConfig/BMS1_oC03_for_EL_CAN_V2_1_ab80ae92_Rx, /ActiveEcuC/Com/ComConfig/VCU6_oC03_for_EL_CAN_V2_1_e209e1d3_Rx] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/EIDC_oC03_for_EL_CAN_V2_1_Tx_59496bbd, /ActiveEcuC/Com/ComConfig/EIDC1_oC03_for_EL_CAN_V2_1_4a10c7b4_Tx] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_Initialized
**********************************************************************************************************************/
/** 
  \var    Com_Initialized
  \brief  Initialization state of Com. TRUE, if Com_Init() has been called, else FALSE.
*/ 
#define COM_START_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_InitializedType, COM_VAR_ZERO_INIT) Com_Initialized = FALSE;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define COM_STOP_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxDeadlineMonitoringISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_RxDeadlineMonitoringISRLockCounterType, COM_VAR_NOINIT) Com_RxDeadlineMonitoringISRLockCounter;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxDefPduBuffer
**********************************************************************************************************************/
/** 
  \var    Com_RxDefPduBuffer
  \brief  Rx I-PDU buffer for deferred signal processing.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_RxDefPduBufferUType, COM_VAR_NOINIT) Com_RxDefPduBuffer;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/ABS3_oC03_for_EL_CAN_V2_1_5328da88_Rx] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/ABS3_oC03_for_EL_CAN_V2_1_5328da88_Rx] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/ABS3_oC03_for_EL_CAN_V2_1_5328da88_Rx] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/BCM10_oC03_for_EL_CAN_V2_1_8175742c_Rx] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/BCM10_oC03_for_EL_CAN_V2_1_8175742c_Rx] */
  /*    15 */  /* [/ActiveEcuC/Com/ComConfig/BCM10_oC03_for_EL_CAN_V2_1_8175742c_Rx] */
  /*    16 */  /* [/ActiveEcuC/Com/ComConfig/BCM17_oC03_for_EL_CAN_V2_1_e4ac4a6c_Rx] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/BCM17_oC03_for_EL_CAN_V2_1_e4ac4a6c_Rx] */
  /*    23 */  /* [/ActiveEcuC/Com/ComConfig/BCM17_oC03_for_EL_CAN_V2_1_e4ac4a6c_Rx] */
  /*    24 */  /* [/ActiveEcuC/Com/ComConfig/BCM23_oC03_for_EL_CAN_V2_1_cee8e051_Rx] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/BCM23_oC03_for_EL_CAN_V2_1_cee8e051_Rx] */
  /*    31 */  /* [/ActiveEcuC/Com/ComConfig/BCM23_oC03_for_EL_CAN_V2_1_cee8e051_Rx] */
  /*    32 */  /* [/ActiveEcuC/Com/ComConfig/BMS1_oC03_for_EL_CAN_V2_1_ab80ae92_Rx] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/BMS1_oC03_for_EL_CAN_V2_1_ab80ae92_Rx] */
  /*    39 */  /* [/ActiveEcuC/Com/ComConfig/BMS1_oC03_for_EL_CAN_V2_1_ab80ae92_Rx] */
  /*    40 */  /* [/ActiveEcuC/Com/ComConfig/BMS17_oC03_for_EL_CAN_V2_1_be27a4ae_Rx] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/BMS17_oC03_for_EL_CAN_V2_1_be27a4ae_Rx] */
  /*    47 */  /* [/ActiveEcuC/Com/ComConfig/BMS17_oC03_for_EL_CAN_V2_1_be27a4ae_Rx] */
  /*    48 */  /* [/ActiveEcuC/Com/ComConfig/CSA1_oC03_for_EL_CAN_V2_1_ffb47aea_Rx] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/CSA1_oC03_for_EL_CAN_V2_1_ffb47aea_Rx] */
  /*    55 */  /* [/ActiveEcuC/Com/ComConfig/CSA1_oC03_for_EL_CAN_V2_1_ffb47aea_Rx] */
  /*    56 */  /* [/ActiveEcuC/Com/ComConfig/EEM1_oC03_for_EL_CAN_V2_1_5bdcd994_Rx] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/EEM1_oC03_for_EL_CAN_V2_1_5bdcd994_Rx] */
  /*    63 */  /* [/ActiveEcuC/Com/ComConfig/EEM1_oC03_for_EL_CAN_V2_1_5bdcd994_Rx] */
  /*    64 */  /* [/ActiveEcuC/Com/ComConfig/GW1_oC03_for_EL_CAN_V2_1_48654b76_Rx] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/GW1_oC03_for_EL_CAN_V2_1_48654b76_Rx] */
  /*    71 */  /* [/ActiveEcuC/Com/ComConfig/GW1_oC03_for_EL_CAN_V2_1_48654b76_Rx] */
  /*    72 */  /* [/ActiveEcuC/Com/ComConfig/HUT34_oC03_for_EL_CAN_V2_1_6fae3f7a_Rx] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/HUT34_oC03_for_EL_CAN_V2_1_6fae3f7a_Rx] */
  /*    79 */  /* [/ActiveEcuC/Com/ComConfig/HUT34_oC03_for_EL_CAN_V2_1_6fae3f7a_Rx] */
  /*    80 */  /* [/ActiveEcuC/Com/ComConfig/HUT54_oC03_for_EL_CAN_V2_1_82644d00_Rx] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/HUT54_oC03_for_EL_CAN_V2_1_82644d00_Rx] */
  /*    87 */  /* [/ActiveEcuC/Com/ComConfig/HUT54_oC03_for_EL_CAN_V2_1_82644d00_Rx] */
  /*    88 */  /* [/ActiveEcuC/Com/ComConfig/IP2_oC03_for_EL_CAN_V2_1_65941076_Rx] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/IP2_oC03_for_EL_CAN_V2_1_65941076_Rx] */
  /*    95 */  /* [/ActiveEcuC/Com/ComConfig/IP2_oC03_for_EL_CAN_V2_1_65941076_Rx] */
  /*    96 */  /* [/ActiveEcuC/Com/ComConfig/MCU_5_oC03_for_EL_CAN_V2_1_002cb201_Rx] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/MCU_5_oC03_for_EL_CAN_V2_1_002cb201_Rx] */
  /*   103 */  /* [/ActiveEcuC/Com/ComConfig/MCU_5_oC03_for_EL_CAN_V2_1_002cb201_Rx] */
  /*   104 */  /* [/ActiveEcuC/Com/ComConfig/OBC3_oC03_for_EL_CAN_V2_1_158aa3d5_Rx] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/OBC3_oC03_for_EL_CAN_V2_1_158aa3d5_Rx] */
  /*   111 */  /* [/ActiveEcuC/Com/ComConfig/OBC3_oC03_for_EL_CAN_V2_1_158aa3d5_Rx] */
  /*   112 */  /* [/ActiveEcuC/Com/ComConfig/PEPS2_oC03_for_EL_CAN_V2_1_d41abfa7_Rx] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/PEPS2_oC03_for_EL_CAN_V2_1_d41abfa7_Rx] */
  /*   119 */  /* [/ActiveEcuC/Com/ComConfig/PEPS2_oC03_for_EL_CAN_V2_1_d41abfa7_Rx] */
  /*   120 */  /* [/ActiveEcuC/Com/ComConfig/RMCU4_oC03_for_EL_CAN_V2_1_55159990_Rx] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/RMCU4_oC03_for_EL_CAN_V2_1_55159990_Rx] */
  /*   127 */  /* [/ActiveEcuC/Com/ComConfig/RMCU4_oC03_for_EL_CAN_V2_1_55159990_Rx] */
  /*   128 */  /* [/ActiveEcuC/Com/ComConfig/R_PBOX1_oC03_for_EL_CAN_V2_1_7854cc6e_Rx] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/R_PBOX1_oC03_for_EL_CAN_V2_1_7854cc6e_Rx] */
  /*   135 */  /* [/ActiveEcuC/Com/ComConfig/R_PBOX1_oC03_for_EL_CAN_V2_1_7854cc6e_Rx] */
  /* Index        Referable Keys */
  /*   136 */  /* [/ActiveEcuC/Com/ComConfig/VCU2_oC03_for_EL_CAN_V2_1_bea872d3_Rx] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/VCU2_oC03_for_EL_CAN_V2_1_bea872d3_Rx] */
  /*   143 */  /* [/ActiveEcuC/Com/ComConfig/VCU2_oC03_for_EL_CAN_V2_1_bea872d3_Rx] */
  /*   144 */  /* [/ActiveEcuC/Com/ComConfig/VCU3_oC03_for_EL_CAN_V2_1_a9801613_Rx] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/VCU3_oC03_for_EL_CAN_V2_1_a9801613_Rx] */
  /*   151 */  /* [/ActiveEcuC/Com/ComConfig/VCU3_oC03_for_EL_CAN_V2_1_a9801613_Rx] */
  /*   152 */  /* [/ActiveEcuC/Com/ComConfig/VCU6_oC03_for_EL_CAN_V2_1_e209e1d3_Rx] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/VCU6_oC03_for_EL_CAN_V2_1_e209e1d3_Rx] */
  /*   159 */  /* [/ActiveEcuC/Com/ComConfig/VCU6_oC03_for_EL_CAN_V2_1_e209e1d3_Rx] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxDeferredFctPtrCache
**********************************************************************************************************************/
/** 
  \var    Com_RxDeferredFctPtrCache
  \brief  Cache for deferred Rx (invalid) notification.
*/ 
#define COM_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_RxDeferredFctPtrCacheType, COM_VAR_NOINIT) Com_RxDeferredFctPtrCache[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define COM_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxDeferredProcessingISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_RxDeferredProcessingISRLockCounterType, COM_VAR_NOINIT) Com_RxDeferredProcessingISRLockCounter;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxDlMonDivisorCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_RxDlMonDivisorCounterType, COM_VAR_NOINIT) Com_RxDlMonDivisorCounter;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxIPduGroupISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_RxIPduGroupISRLockCounterType, COM_VAR_NOINIT) Com_RxIPduGroupISRLockCounter;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxPduDmState
**********************************************************************************************************************/
/** 
  \var    Com_RxPduDmState
  \brief  Rx I-PDU based deadline monitoring state (started/stopped) of the corresponding I-PDU-Group.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_RxPduDmStateType, COM_VAR_NOINIT) Com_RxPduDmState[19];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/CheckSum_ABS3_oABS3_oC03_for_EL_CAN_V2_1_5745e086_Rx, /ActiveEcuC/Com/ComConfig/ABS3_oC03_for_EL_CAN_V2_1_5328da88_Rx, /ActiveEcuC/Com/ComConfig/ABS3_oC03_for_EL_CAN_V2_1_5328da88_RxPduBased, /ActiveEcuC/Com/ComConfig/RollingCounter_ABS3_oABS3_oC03_for_EL_CAN_V2_1_b6ac7000_Rx, /ActiveEcuC/Com/ComConfig/VehSpdVld_oABS3_oC03_for_EL_CAN_V2_1_32497dd3_Rx, /ActiveEcuC/Com/ComConfig/VehSpd_oABS3_oC03_for_EL_CAN_V2_1_23260d94_Rx] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/Checksum_BCM10_oBCM10_oC03_for_EL_CAN_V2_1_819e75d3_Rx, /ActiveEcuC/Com/ComConfig/BCM10_oC03_for_EL_CAN_V2_1_8175742c_Rx, /ActiveEcuC/Com/ComConfig/BCM10_oC03_for_EL_CAN_V2_1_8175742c_RxPduBased, /ActiveEcuC/Com/ComConfig/LTurnLampWorkCmd_oBCM10_oC03_for_EL_CAN_V2_1_7a1a08f4_Rx, /ActiveEcuC/Com/ComConfig/RTurnLmpWorkCmd_oBCM10_oC03_for_EL_CAN_V2_1_10ea9ba1_Rx, /ActiveEcuC/Com/ComConfig/Rollingcounter_BCM10_oBCM10_oC03_for_EL_CAN_V2_1_6dd2f1f9_Rx] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/AnimationReq_oBCM17_oC03_for_EL_CAN_V2_1_1db28c46_Rx, /ActiveEcuC/Com/ComConfig/BCM17_oC03_for_EL_CAN_V2_1_e4ac4a6c_Rx, /ActiveEcuC/Com/ComConfig/BCM17_oC03_for_EL_CAN_V2_1_e4ac4a6c_RxPduBased, /ActiveEcuC/Com/ComConfig/ApproachLightAnimationType_oBCM17_oC03_for_EL_CAN_V2_1_5b20a81e_Rx, /ActiveEcuC/Com/ComConfig/GoodbyeAnimationType_oBCM17_oC03_for_EL_CAN_V2_1_bc8c4dab_Rx, /ActiveEcuC/Com/ComConfig/MecDancAnimationType_oBCM17_oC03_for_EL_CAN_V2_1_6bb5a98f_Rx, /ActiveEcuC/Com/ComConfig/WelcomeAnimationType_oBCM17_oC03_for_EL_CAN_V2_1_c76d0f7a_Rx] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/CEMDetminCdnSts_oBCM23_oC03_for_EL_CAN_V2_1_df6348d5_Rx, /ActiveEcuC/Com/ComConfig/BCM23_oC03_for_EL_CAN_V2_1_cee8e051_Rx, /ActiveEcuC/Com/ComConfig/BCM23_oC03_for_EL_CAN_V2_1_cee8e051_RxPduBased] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/BMS_SOC_oBMS1_oC03_for_EL_CAN_V2_1_a261d1ce_Rx, /ActiveEcuC/Com/ComConfig/BMS1_oC03_for_EL_CAN_V2_1_ab80ae92_Rx, /ActiveEcuC/Com/ComConfig/BMS1_oC03_for_EL_CAN_V2_1_ab80ae92_RxPduBased] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/BMS_DCChrgConnect_oBMS17_oC03_for_EL_CAN_V2_1_91db617c_Rx, /ActiveEcuC/Com/ComConfig/BMS17_oC03_for_EL_CAN_V2_1_be27a4ae_Rx, /ActiveEcuC/Com/ComConfig/BMS17_oC03_for_EL_CAN_V2_1_be27a4ae_RxPduBased] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/LTurnLmpSwtSts_oCSA1_oC03_for_EL_CAN_V2_1_458e5c96_Rx, /ActiveEcuC/Com/ComConfig/CSA1_oC03_for_EL_CAN_V2_1_ffb47aea_Rx, /ActiveEcuC/Com/ComConfig/CSA1_oC03_for_EL_CAN_V2_1_ffb47aea_RxPduBased, /ActiveEcuC/Com/ComConfig/RTurnLmpSwtSts_oCSA1_oC03_for_EL_CAN_V2_1_2fe59187_Rx] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/DeepSlpCmd_oEEM1_oC03_for_EL_CAN_V2_1_41fb7d93_Rx, /ActiveEcuC/Com/ComConfig/EEM1_oC03_for_EL_CAN_V2_1_5bdcd994_Rx, /ActiveEcuC/Com/ComConfig/EEM1_oC03_for_EL_CAN_V2_1_5bdcd994_RxPduBased, /ActiveEcuC/Com/ComConfig/Stat_PwrSv_Lvl_oEEM1_oC03_for_EL_CAN_V2_1_a4eaa63e_Rx, /ActiveEcuC/Com/ComConfig/TranPMode_Sts_oEEM1_oC03_for_EL_CAN_V2_1_a5a3838d_Rx] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/ScenarioID_oGW1_oC03_for_EL_CAN_V2_1_b0249678_Rx, /ActiveEcuC/Com/ComConfig/GW1_oC03_for_EL_CAN_V2_1_48654b76_Rx, /ActiveEcuC/Com/ComConfig/GW1_oC03_for_EL_CAN_V2_1_48654b76_RxPduBased, /ActiveEcuC/Com/ComConfig/ScenarioReq_oGW1_oC03_for_EL_CAN_V2_1_d81adfac_Rx] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/TimeIndcn_oHUT34_oC03_for_EL_CAN_V2_1_d29435a0_Rx, /ActiveEcuC/Com/ComConfig/HUT34_oC03_for_EL_CAN_V2_1_6fae3f7a_Rx, /ActiveEcuC/Com/ComConfig/HUT34_oC03_for_EL_CAN_V2_1_6fae3f7a_RxPduBased, /ActiveEcuC/Com/ComConfig/TimeMod_oHUT34_oC03_for_EL_CAN_V2_1_baa135ee_Rx, /ActiveEcuC/Com/ComConfig/Time_Day_oHUT34_oC03_for_EL_CAN_V2_1_5996a937_Rx, /ActiveEcuC/Com/ComConfig/Time_Hour_oHUT34_oC03_for_EL_CAN_V2_1_2c4ebd6a_Rx, /ActiveEcuC/Com/ComConfig/Time_Minutes_oHUT34_oC03_for_EL_CAN_V2_1_da3ecd44_Rx, /ActiveEcuC/Com/ComConfig/Time_Month_oHUT34_oC03_for_EL_CAN_V2_1_33ed510d_Rx, /ActiveEcuC/Com/ComConfig/Time_Second_oHUT34_oC03_for_EL_CAN_V2_1_9732895b_Rx, /ActiveEcuC/Com/ComConfig/Time_Year_Left_oHUT34_oC03_for_EL_CAN_V2_1_f1a91267_Rx, /ActiveEcuC/Com/ComConfig/Time_Year_Right_oHUT34_oC03_for_EL_CAN_V2_1_fa890340_Rx] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/IP_VehTotDistanceValid_oIP2_oC03_for_EL_CAN_V2_1_234ac38e_Rx, /ActiveEcuC/Com/ComConfig/IP2_oC03_for_EL_CAN_V2_1_65941076_Rx, /ActiveEcuC/Com/ComConfig/IP2_oC03_for_EL_CAN_V2_1_65941076_RxPduBased, /ActiveEcuC/Com/ComConfig/IP_VehTotDistance_oIP2_oC03_for_EL_CAN_V2_1_a238a7cc_Rx] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/MCU_ActRotSpd_oMCU_5_oC03_for_EL_CAN_V2_1_c2eb67f0_Rx, /ActiveEcuC/Com/ComConfig/MCU_5_oC03_for_EL_CAN_V2_1_002cb201_Rx, /ActiveEcuC/Com/ComConfig/MCU_5_oC03_for_EL_CAN_V2_1_002cb201_RxPduBased] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/OBC_CCLineConnectSts_oOBC3_oC03_for_EL_CAN_V2_1_a7854723_Rx, /ActiveEcuC/Com/ComConfig/OBC3_oC03_for_EL_CAN_V2_1_158aa3d5_Rx, /ActiveEcuC/Com/ComConfig/OBC3_oC03_for_EL_CAN_V2_1_158aa3d5_RxPduBased] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/CheckSum_PEPS2_oPEPS2_oC03_for_EL_CAN_V2_1_06064851_Rx, /ActiveEcuC/Com/ComConfig/PEPS2_oC03_for_EL_CAN_V2_1_d41abfa7_Rx, /ActiveEcuC/Com/ComConfig/PEPS2_oC03_for_EL_CAN_V2_1_d41abfa7_RxPduBased, /ActiveEcuC/Com/ComConfig/RollingCounter_PEPS2_oPEPS2_oC03_for_EL_CAN_V2_1_9bd00531_Rx, /ActiveEcuC/Com/ComConfig/SysPowerModVld_oPEPS2_oC03_for_EL_CAN_V2_1_b6c20e3c_Rx, /ActiveEcuC/Com/ComConfig/SysPowerMod_oPEPS2_oC03_for_EL_CAN_V2_1_37fb939a_Rx] */
  /*    14 */  /* [/ActiveEcuC/Com/ComConfig/RMCU_ActRotSpd_oRMCU4_oC03_for_EL_CAN_V2_1_a08a2435_Rx, /ActiveEcuC/Com/ComConfig/RMCU4_oC03_for_EL_CAN_V2_1_55159990_Rx, /ActiveEcuC/Com/ComConfig/RMCU4_oC03_for_EL_CAN_V2_1_55159990_RxPduBased] */
  /*    15 */  /* [/ActiveEcuC/Com/ComConfig/PosnLmpOutpSts_R_PBox_oR_PBOX1_oC03_for_EL_CAN_V2_1_c63ace4d_Rx, /ActiveEcuC/Com/ComConfig/R_PBOX1_oC03_for_EL_CAN_V2_1_7854cc6e_Rx, /ActiveEcuC/Com/ComConfig/R_PBOX1_oC03_for_EL_CAN_V2_1_7854cc6e_RxPduBased] */
  /*    16 */  /* [/ActiveEcuC/Com/ComConfig/VCU_GearSts_oVCU2_oC03_for_EL_CAN_V2_1_71c2293d_Rx, /ActiveEcuC/Com/ComConfig/VCU2_oC03_for_EL_CAN_V2_1_bea872d3_Rx, /ActiveEcuC/Com/ComConfig/VCU2_oC03_for_EL_CAN_V2_1_bea872d3_RxPduBased] */
  /*    17 */  /* [/ActiveEcuC/Com/ComConfig/VCU_ChrgnSts_oVCU3_oC03_for_EL_CAN_V2_1_87b3fa1f_Rx, /ActiveEcuC/Com/ComConfig/VCU3_oC03_for_EL_CAN_V2_1_a9801613_Rx, /ActiveEcuC/Com/ComConfig/VCU3_oC03_for_EL_CAN_V2_1_a9801613_RxPduBased] */
  /*    18 */  /* [/ActiveEcuC/Com/ComConfig/VCU_BrkPedlSts_oVCU6_oC03_for_EL_CAN_V2_1_66fed013_Rx, /ActiveEcuC/Com/ComConfig/VCU6_oC03_for_EL_CAN_V2_1_e209e1d3_Rx, /ActiveEcuC/Com/ComConfig/VCU6_oC03_for_EL_CAN_V2_1_e209e1d3_RxPduBased] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxPduGrpActive
**********************************************************************************************************************/
/** 
  \var    Com_RxPduGrpActive
  \brief  Rx I-PDU based state (started/stopped) of the corresponding I-PDU-Group.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_RxPduGrpActiveType, COM_VAR_NOINIT) Com_RxPduGrpActive[20];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/ABS3_oC03_for_EL_CAN_V2_1_5328da88_Rx, /ActiveEcuC/Com/ComConfig/EIDC_oC03_for_EL_CAN_V2_1_Rx_0f13cc3b] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/BCM10_oC03_for_EL_CAN_V2_1_8175742c_Rx, /ActiveEcuC/Com/ComConfig/EIDC_oC03_for_EL_CAN_V2_1_Rx_0f13cc3b] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/BCM17_oC03_for_EL_CAN_V2_1_e4ac4a6c_Rx, /ActiveEcuC/Com/ComConfig/EIDC_oC03_for_EL_CAN_V2_1_Rx_0f13cc3b] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/BCM23_oC03_for_EL_CAN_V2_1_cee8e051_Rx, /ActiveEcuC/Com/ComConfig/EIDC_oC03_for_EL_CAN_V2_1_Rx_0f13cc3b] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/BMS1_oC03_for_EL_CAN_V2_1_ab80ae92_Rx, /ActiveEcuC/Com/ComConfig/EIDC_oC03_for_EL_CAN_V2_1_Rx_0f13cc3b] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/BMS17_oC03_for_EL_CAN_V2_1_be27a4ae_Rx, /ActiveEcuC/Com/ComConfig/EIDC_oC03_for_EL_CAN_V2_1_Rx_0f13cc3b] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/CSA1_oC03_for_EL_CAN_V2_1_ffb47aea_Rx, /ActiveEcuC/Com/ComConfig/EIDC_oC03_for_EL_CAN_V2_1_Rx_0f13cc3b] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/EEM1_oC03_for_EL_CAN_V2_1_5bdcd994_Rx, /ActiveEcuC/Com/ComConfig/EIDC_oC03_for_EL_CAN_V2_1_Rx_0f13cc3b] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/GW1_oC03_for_EL_CAN_V2_1_48654b76_Rx, /ActiveEcuC/Com/ComConfig/EIDC_oC03_for_EL_CAN_V2_1_Rx_0f13cc3b] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/HUT34_oC03_for_EL_CAN_V2_1_6fae3f7a_Rx, /ActiveEcuC/Com/ComConfig/EIDC_oC03_for_EL_CAN_V2_1_Rx_0f13cc3b] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/HUT54_oC03_for_EL_CAN_V2_1_82644d00_Rx, /ActiveEcuC/Com/ComConfig/EIDC_oC03_for_EL_CAN_V2_1_Rx_0f13cc3b] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/IP2_oC03_for_EL_CAN_V2_1_65941076_Rx, /ActiveEcuC/Com/ComConfig/EIDC_oC03_for_EL_CAN_V2_1_Rx_0f13cc3b] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/MCU_5_oC03_for_EL_CAN_V2_1_002cb201_Rx, /ActiveEcuC/Com/ComConfig/EIDC_oC03_for_EL_CAN_V2_1_Rx_0f13cc3b] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/OBC3_oC03_for_EL_CAN_V2_1_158aa3d5_Rx, /ActiveEcuC/Com/ComConfig/EIDC_oC03_for_EL_CAN_V2_1_Rx_0f13cc3b] */
  /*    14 */  /* [/ActiveEcuC/Com/ComConfig/PEPS2_oC03_for_EL_CAN_V2_1_d41abfa7_Rx, /ActiveEcuC/Com/ComConfig/EIDC_oC03_for_EL_CAN_V2_1_Rx_0f13cc3b] */
  /*    15 */  /* [/ActiveEcuC/Com/ComConfig/RMCU4_oC03_for_EL_CAN_V2_1_55159990_Rx, /ActiveEcuC/Com/ComConfig/EIDC_oC03_for_EL_CAN_V2_1_Rx_0f13cc3b] */
  /*    16 */  /* [/ActiveEcuC/Com/ComConfig/R_PBOX1_oC03_for_EL_CAN_V2_1_7854cc6e_Rx, /ActiveEcuC/Com/ComConfig/EIDC_oC03_for_EL_CAN_V2_1_Rx_0f13cc3b] */
  /*    17 */  /* [/ActiveEcuC/Com/ComConfig/VCU2_oC03_for_EL_CAN_V2_1_bea872d3_Rx, /ActiveEcuC/Com/ComConfig/EIDC_oC03_for_EL_CAN_V2_1_Rx_0f13cc3b] */
  /*    18 */  /* [/ActiveEcuC/Com/ComConfig/VCU3_oC03_for_EL_CAN_V2_1_a9801613_Rx, /ActiveEcuC/Com/ComConfig/EIDC_oC03_for_EL_CAN_V2_1_Rx_0f13cc3b] */
  /*    19 */  /* [/ActiveEcuC/Com/ComConfig/VCU6_oC03_for_EL_CAN_V2_1_e209e1d3_Rx, /ActiveEcuC/Com/ComConfig/EIDC_oC03_for_EL_CAN_V2_1_Rx_0f13cc3b] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigBufferUInt16
**********************************************************************************************************************/
/** 
  \var    Com_RxSigBufferUInt16
  \brief  Rx Signal and Group Signal Buffer. (UINT16)
*/ 
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_RxSigBufferUInt16Type, COM_VAR_NOINIT) Com_RxSigBufferUInt16[4];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/BMS_SOC_oBMS1_oC03_for_EL_CAN_V2_1_a261d1ce_Rx, /ActiveEcuC/Com/ComConfig/BMS_SOC_oBMS1_oC03_for_EL_CAN_V2_1_a261d1ce_Rx_RxSignalBufferRouting] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/MCU_ActRotSpd_oMCU_5_oC03_for_EL_CAN_V2_1_c2eb67f0_Rx, /ActiveEcuC/Com/ComConfig/MCU_ActRotSpd_oMCU_5_oC03_for_EL_CAN_V2_1_c2eb67f0_Rx_RxSignalBufferRouting] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/RMCU_ActRotSpd_oRMCU4_oC03_for_EL_CAN_V2_1_a08a2435_Rx, /ActiveEcuC/Com/ComConfig/RMCU_ActRotSpd_oRMCU4_oC03_for_EL_CAN_V2_1_a08a2435_Rx_RxSignalBufferRouting] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/VehSpd_oABS3_oC03_for_EL_CAN_V2_1_23260d94_Rx, /ActiveEcuC/Com/ComConfig/VehSpd_oABS3_oC03_for_EL_CAN_V2_1_23260d94_Rx_RxSignalBufferRouting] */

#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigBufferUInt32
**********************************************************************************************************************/
/** 
  \var    Com_RxSigBufferUInt32
  \brief  Rx Signal and Group Signal Buffer. (UINT32)
*/ 
#define COM_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_RxSigBufferUInt32Type, COM_VAR_NOINIT) Com_RxSigBufferUInt32[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/IP_VehTotDistance_oIP2_oC03_for_EL_CAN_V2_1_a238a7cc_Rx, /ActiveEcuC/Com/ComConfig/IP_VehTotDistance_oIP2_oC03_for_EL_CAN_V2_1_a238a7cc_Rx_RxSignalBufferRouting] */

#define COM_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigBufferUInt8
**********************************************************************************************************************/
/** 
  \var    Com_RxSigBufferUInt8
  \brief  Rx Signal and Group Signal Buffer. (BOOLEAN, UINT8)
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_RxSigBufferUInt8Type, COM_VAR_NOINIT) Com_RxSigBufferUInt8[50];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/AnimationReq_oBCM17_oC03_for_EL_CAN_V2_1_1db28c46_Rx, /ActiveEcuC/Com/ComConfig/AnimationReq_oBCM17_oC03_for_EL_CAN_V2_1_1db28c46_Rx_RxSignalBufferRouting] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/ApproachLightAnimationType_oBCM17_oC03_for_EL_CAN_V2_1_5b20a81e_Rx, /ActiveEcuC/Com/ComConfig/ApproachLightAnimationType_oBCM17_oC03_for_EL_CAN_V2_1_5b20a81e_Rx_RxSignalBufferRouting] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/BMS_DCChrgConnect_oBMS17_oC03_for_EL_CAN_V2_1_91db617c_Rx, /ActiveEcuC/Com/ComConfig/BMS_DCChrgConnect_oBMS17_oC03_for_EL_CAN_V2_1_91db617c_Rx_RxSignalBufferRouting] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/CEMDetminCdnSts_oBCM23_oC03_for_EL_CAN_V2_1_df6348d5_Rx, /ActiveEcuC/Com/ComConfig/CEMDetminCdnSts_oBCM23_oC03_for_EL_CAN_V2_1_df6348d5_Rx_RxSignalBufferRouting] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/CheckSum_ABS3_oABS3_oC03_for_EL_CAN_V2_1_5745e086_Rx, /ActiveEcuC/Com/ComConfig/CheckSum_ABS3_oABS3_oC03_for_EL_CAN_V2_1_5745e086_Rx_RxSignalBufferRouting] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/CheckSum_PEPS2_oPEPS2_oC03_for_EL_CAN_V2_1_06064851_Rx, /ActiveEcuC/Com/ComConfig/CheckSum_PEPS2_oPEPS2_oC03_for_EL_CAN_V2_1_06064851_Rx_RxSignalBufferRouting] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/Checksum_BCM10_oBCM10_oC03_for_EL_CAN_V2_1_819e75d3_Rx, /ActiveEcuC/Com/ComConfig/Checksum_BCM10_oBCM10_oC03_for_EL_CAN_V2_1_819e75d3_Rx_RxSignalBufferRouting] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/ChrgDispPatTypSet_oHUT54_oC03_for_EL_CAN_V2_1_f6de33f3_Rx, /ActiveEcuC/Com/ComConfig/ChrgDispPatTypSet_oHUT54_oC03_for_EL_CAN_V2_1_f6de33f3_Rx_RxSignalBufferRouting] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/ChrgPatDispSwt_oHUT54_oC03_for_EL_CAN_V2_1_f66d5f08_Rx, /ActiveEcuC/Com/ComConfig/ChrgPatDispSwt_oHUT54_oC03_for_EL_CAN_V2_1_f66d5f08_Rx_RxSignalBufferRouting] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/DeepSlpCmd_oEEM1_oC03_for_EL_CAN_V2_1_41fb7d93_Rx, /ActiveEcuC/Com/ComConfig/DeepSlpCmd_oEEM1_oC03_for_EL_CAN_V2_1_41fb7d93_Rx_RxSignalBufferRouting] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/EIDCSwt_oHUT54_oC03_for_EL_CAN_V2_1_ac2debcb_Rx, /ActiveEcuC/Com/ComConfig/EIDCSwt_oHUT54_oC03_for_EL_CAN_V2_1_ac2debcb_Rx_RxSignalBufferRouting] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/EmojiTypSet_oHUT54_oC03_for_EL_CAN_V2_1_ac4f7c91_Rx, /ActiveEcuC/Com/ComConfig/EmojiTypSet_oHUT54_oC03_for_EL_CAN_V2_1_ac4f7c91_Rx_RxSignalBufferRouting] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/GoodbyeAnimationType_oBCM17_oC03_for_EL_CAN_V2_1_bc8c4dab_Rx, /ActiveEcuC/Com/ComConfig/GoodbyeAnimationType_oBCM17_oC03_for_EL_CAN_V2_1_bc8c4dab_Rx_RxSignalBufferRouting] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/IP_VehTotDistanceValid_oIP2_oC03_for_EL_CAN_V2_1_234ac38e_Rx, /ActiveEcuC/Com/ComConfig/IP_VehTotDistanceValid_oIP2_oC03_for_EL_CAN_V2_1_234ac38e_Rx_RxSignalBufferRouting] */
  /*    14 */  /* [/ActiveEcuC/Com/ComConfig/LTurnLampWorkCmd_oBCM10_oC03_for_EL_CAN_V2_1_7a1a08f4_Rx, /ActiveEcuC/Com/ComConfig/LTurnLampWorkCmd_oBCM10_oC03_for_EL_CAN_V2_1_7a1a08f4_Rx_RxSignalBufferRouting] */
  /*    15 */  /* [/ActiveEcuC/Com/ComConfig/LTurnLmpSwtSts_oCSA1_oC03_for_EL_CAN_V2_1_458e5c96_Rx, /ActiveEcuC/Com/ComConfig/LTurnLmpSwtSts_oCSA1_oC03_for_EL_CAN_V2_1_458e5c96_Rx_RxSignalBufferRouting] */
  /*    16 */  /* [/ActiveEcuC/Com/ComConfig/MecDancAnimationType_oBCM17_oC03_for_EL_CAN_V2_1_6bb5a98f_Rx, /ActiveEcuC/Com/ComConfig/MecDancAnimationType_oBCM17_oC03_for_EL_CAN_V2_1_6bb5a98f_Rx_RxSignalBufferRouting] */
  /*    17 */  /* [/ActiveEcuC/Com/ComConfig/OBC_CCLineConnectSts_oOBC3_oC03_for_EL_CAN_V2_1_a7854723_Rx, /ActiveEcuC/Com/ComConfig/OBC_CCLineConnectSts_oOBC3_oC03_for_EL_CAN_V2_1_a7854723_Rx_RxSignalBufferRouting] */
  /*    18 */  /* [/ActiveEcuC/Com/ComConfig/PosnLmpOutpSts_R_PBox_oR_PBOX1_oC03_for_EL_CAN_V2_1_c63ace4d_Rx, /ActiveEcuC/Com/ComConfig/PosnLmpOutpSts_R_PBox_oR_PBOX1_oC03_for_EL_CAN_V2_1_c63ace4d_Rx_RxSignalBufferRouting] */
  /*    19 */  /* [/ActiveEcuC/Com/ComConfig/RTurnLmpSwtSts_oCSA1_oC03_for_EL_CAN_V2_1_2fe59187_Rx, /ActiveEcuC/Com/ComConfig/RTurnLmpSwtSts_oCSA1_oC03_for_EL_CAN_V2_1_2fe59187_Rx_RxSignalBufferRouting] */
  /*    20 */  /* [/ActiveEcuC/Com/ComConfig/RTurnLmpWorkCmd_oBCM10_oC03_for_EL_CAN_V2_1_10ea9ba1_Rx, /ActiveEcuC/Com/ComConfig/RTurnLmpWorkCmd_oBCM10_oC03_for_EL_CAN_V2_1_10ea9ba1_Rx_RxSignalBufferRouting] */
  /*    21 */  /* [/ActiveEcuC/Com/ComConfig/RemindTypSet_oHUT54_oC03_for_EL_CAN_V2_1_fc32c110_Rx, /ActiveEcuC/Com/ComConfig/RemindTypSet_oHUT54_oC03_for_EL_CAN_V2_1_fc32c110_Rx_RxSignalBufferRouting] */
  /*    22 */  /* [/ActiveEcuC/Com/ComConfig/RollingCounter_ABS3_oABS3_oC03_for_EL_CAN_V2_1_b6ac7000_Rx, /ActiveEcuC/Com/ComConfig/RollingCounter_ABS3_oABS3_oC03_for_EL_CAN_V2_1_b6ac7000_Rx_RxSignalBufferRouting] */
  /*    23 */  /* [/ActiveEcuC/Com/ComConfig/RollingCounter_PEPS2_oPEPS2_oC03_for_EL_CAN_V2_1_9bd00531_Rx, /ActiveEcuC/Com/ComConfig/RollingCounter_PEPS2_oPEPS2_oC03_for_EL_CAN_V2_1_9bd00531_Rx_RxSignalBufferRouting] */
  /*    24 */  /* [/ActiveEcuC/Com/ComConfig/Rollingcounter_BCM10_oBCM10_oC03_for_EL_CAN_V2_1_6dd2f1f9_Rx, /ActiveEcuC/Com/ComConfig/Rollingcounter_BCM10_oBCM10_oC03_for_EL_CAN_V2_1_6dd2f1f9_Rx_RxSignalBufferRouting] */
  /*    25 */  /* [/ActiveEcuC/Com/ComConfig/ScenarioID_oGW1_oC03_for_EL_CAN_V2_1_b0249678_Rx, /ActiveEcuC/Com/ComConfig/ScenarioID_oGW1_oC03_for_EL_CAN_V2_1_b0249678_Rx_RxSignalBufferRouting] */
  /*    26 */  /* [/ActiveEcuC/Com/ComConfig/ScenarioReq_oGW1_oC03_for_EL_CAN_V2_1_d81adfac_Rx, /ActiveEcuC/Com/ComConfig/ScenarioReq_oGW1_oC03_for_EL_CAN_V2_1_d81adfac_Rx_RxSignalBufferRouting] */
  /*    27 */  /* [/ActiveEcuC/Com/ComConfig/Stat_PwrSv_Lvl_oEEM1_oC03_for_EL_CAN_V2_1_a4eaa63e_Rx, /ActiveEcuC/Com/ComConfig/Stat_PwrSv_Lvl_oEEM1_oC03_for_EL_CAN_V2_1_a4eaa63e_Rx_RxSignalBufferRouting] */
  /*    28 */  /* [/ActiveEcuC/Com/ComConfig/SysPowerModVld_oPEPS2_oC03_for_EL_CAN_V2_1_b6c20e3c_Rx, /ActiveEcuC/Com/ComConfig/SysPowerModVld_oPEPS2_oC03_for_EL_CAN_V2_1_b6c20e3c_Rx_RxSignalBufferRouting] */
  /*    29 */  /* [/ActiveEcuC/Com/ComConfig/SysPowerMod_oPEPS2_oC03_for_EL_CAN_V2_1_37fb939a_Rx, /ActiveEcuC/Com/ComConfig/SysPowerMod_oPEPS2_oC03_for_EL_CAN_V2_1_37fb939a_Rx_RxSignalBufferRouting] */
  /*    30 */  /* [/ActiveEcuC/Com/ComConfig/TimeIndcn_oHUT34_oC03_for_EL_CAN_V2_1_d29435a0_Rx, /ActiveEcuC/Com/ComConfig/TimeIndcn_oHUT34_oC03_for_EL_CAN_V2_1_d29435a0_Rx_RxSignalBufferRouting] */
  /*    31 */  /* [/ActiveEcuC/Com/ComConfig/TimeMod_oHUT34_oC03_for_EL_CAN_V2_1_baa135ee_Rx, /ActiveEcuC/Com/ComConfig/TimeMod_oHUT34_oC03_for_EL_CAN_V2_1_baa135ee_Rx_RxSignalBufferRouting] */
  /*    32 */  /* [/ActiveEcuC/Com/ComConfig/Time_Day_oHUT34_oC03_for_EL_CAN_V2_1_5996a937_Rx, /ActiveEcuC/Com/ComConfig/Time_Day_oHUT34_oC03_for_EL_CAN_V2_1_5996a937_Rx_RxSignalBufferRouting] */
  /*    33 */  /* [/ActiveEcuC/Com/ComConfig/Time_Hour_oHUT34_oC03_for_EL_CAN_V2_1_2c4ebd6a_Rx, /ActiveEcuC/Com/ComConfig/Time_Hour_oHUT34_oC03_for_EL_CAN_V2_1_2c4ebd6a_Rx_RxSignalBufferRouting] */
  /*    34 */  /* [/ActiveEcuC/Com/ComConfig/Time_Minutes_oHUT34_oC03_for_EL_CAN_V2_1_da3ecd44_Rx, /ActiveEcuC/Com/ComConfig/Time_Minutes_oHUT34_oC03_for_EL_CAN_V2_1_da3ecd44_Rx_RxSignalBufferRouting] */
  /*    35 */  /* [/ActiveEcuC/Com/ComConfig/Time_Month_oHUT34_oC03_for_EL_CAN_V2_1_33ed510d_Rx, /ActiveEcuC/Com/ComConfig/Time_Month_oHUT34_oC03_for_EL_CAN_V2_1_33ed510d_Rx_RxSignalBufferRouting] */
  /*    36 */  /* [/ActiveEcuC/Com/ComConfig/Time_Second_oHUT34_oC03_for_EL_CAN_V2_1_9732895b_Rx, /ActiveEcuC/Com/ComConfig/Time_Second_oHUT34_oC03_for_EL_CAN_V2_1_9732895b_Rx_RxSignalBufferRouting] */
  /*    37 */  /* [/ActiveEcuC/Com/ComConfig/Time_Year_Left_oHUT34_oC03_for_EL_CAN_V2_1_f1a91267_Rx, /ActiveEcuC/Com/ComConfig/Time_Year_Left_oHUT34_oC03_for_EL_CAN_V2_1_f1a91267_Rx_RxSignalBufferRouting] */
  /*    38 */  /* [/ActiveEcuC/Com/ComConfig/Time_Year_Right_oHUT34_oC03_for_EL_CAN_V2_1_fa890340_Rx, /ActiveEcuC/Com/ComConfig/Time_Year_Right_oHUT34_oC03_for_EL_CAN_V2_1_fa890340_Rx_RxSignalBufferRouting] */
  /*    39 */  /* [/ActiveEcuC/Com/ComConfig/TopicTypSet_oHUT54_oC03_for_EL_CAN_V2_1_71504e9d_Rx, /ActiveEcuC/Com/ComConfig/TopicTypSet_oHUT54_oC03_for_EL_CAN_V2_1_71504e9d_Rx_RxSignalBufferRouting] */
  /*    40 */  /* [/ActiveEcuC/Com/ComConfig/TranPMode_Sts_oEEM1_oC03_for_EL_CAN_V2_1_a5a3838d_Rx, /ActiveEcuC/Com/ComConfig/TranPMode_Sts_oEEM1_oC03_for_EL_CAN_V2_1_a5a3838d_Rx_RxSignalBufferRouting] */
  /*    41 */  /* [/ActiveEcuC/Com/ComConfig/TurnRemdSwt_oHUT54_oC03_for_EL_CAN_V2_1_06f5df9c_Rx, /ActiveEcuC/Com/ComConfig/TurnRemdSwt_oHUT54_oC03_for_EL_CAN_V2_1_06f5df9c_Rx_RxSignalBufferRouting] */
  /*    42 */  /* [/ActiveEcuC/Com/ComConfig/VCU_BrkPedlSts_oVCU6_oC03_for_EL_CAN_V2_1_66fed013_Rx, /ActiveEcuC/Com/ComConfig/VCU_BrkPedlSts_oVCU6_oC03_for_EL_CAN_V2_1_66fed013_Rx_RxSignalBufferRouting] */
  /*    43 */  /* [/ActiveEcuC/Com/ComConfig/VCU_ChrgnSts_oVCU3_oC03_for_EL_CAN_V2_1_87b3fa1f_Rx, /ActiveEcuC/Com/ComConfig/VCU_ChrgnSts_oVCU3_oC03_for_EL_CAN_V2_1_87b3fa1f_Rx_RxSignalBufferRouting] */
  /*    44 */  /* [/ActiveEcuC/Com/ComConfig/VCU_GearSts_oVCU2_oC03_for_EL_CAN_V2_1_71c2293d_Rx, /ActiveEcuC/Com/ComConfig/VCU_GearSts_oVCU2_oC03_for_EL_CAN_V2_1_71c2293d_Rx_RxSignalBufferRouting] */
  /*    45 */  /* [/ActiveEcuC/Com/ComConfig/VehSpdVld_oABS3_oC03_for_EL_CAN_V2_1_32497dd3_Rx, /ActiveEcuC/Com/ComConfig/VehSpdVld_oABS3_oC03_for_EL_CAN_V2_1_32497dd3_Rx_RxSignalBufferRouting] */
  /*    46 */  /* [/ActiveEcuC/Com/ComConfig/WelcomeAnimationType_oBCM17_oC03_for_EL_CAN_V2_1_c76d0f7a_Rx, /ActiveEcuC/Com/ComConfig/WelcomeAnimationType_oBCM17_oC03_for_EL_CAN_V2_1_c76d0f7a_Rx_RxSignalBufferRouting] */
  /*    47 */  /* [/ActiveEcuC/Com/ComConfig/WelcomePatTypSet_oHUT54_oC03_for_EL_CAN_V2_1_ac7026e0_Rx, /ActiveEcuC/Com/ComConfig/WelcomePatTypSet_oHUT54_oC03_for_EL_CAN_V2_1_ac7026e0_Rx_RxSignalBufferRouting] */
  /*    48 */  /* [/ActiveEcuC/Com/ComConfig/WelcomeSwt_oHUT54_oC03_for_EL_CAN_V2_1_351ff7b4_Rx, /ActiveEcuC/Com/ComConfig/WelcomeSwt_oHUT54_oC03_for_EL_CAN_V2_1_351ff7b4_Rx_RxSignalBufferRouting] */
  /*    49 */  /* [/ActiveEcuC/Com/ComConfig/WordTypSet_oHUT54_oC03_for_EL_CAN_V2_1_035aa6cb_Rx, /ActiveEcuC/Com/ComConfig/WordTypSet_oHUT54_oC03_for_EL_CAN_V2_1_035aa6cb_Rx_RxSignalBufferRouting] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxTOutCnt
**********************************************************************************************************************/
/** 
  \var    Com_RxTOutCnt
  \brief  This array holds timeout counters for all Rx timeout objects.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_RxTOutCntType, COM_VAR_NOINIT) Com_RxTOutCnt[19];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/CheckSum_ABS3_oABS3_oC03_for_EL_CAN_V2_1_5745e086_Rx, /ActiveEcuC/Com/ComConfig/ABS3_oC03_for_EL_CAN_V2_1_5328da88_Rx, /ActiveEcuC/Com/ComConfig/ABS3_oC03_for_EL_CAN_V2_1_5328da88_RxPduBased, /ActiveEcuC/Com/ComConfig/RollingCounter_ABS3_oABS3_oC03_for_EL_CAN_V2_1_b6ac7000_Rx, /ActiveEcuC/Com/ComConfig/VehSpdVld_oABS3_oC03_for_EL_CAN_V2_1_32497dd3_Rx, /ActiveEcuC/Com/ComConfig/VehSpd_oABS3_oC03_for_EL_CAN_V2_1_23260d94_Rx] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/Checksum_BCM10_oBCM10_oC03_for_EL_CAN_V2_1_819e75d3_Rx, /ActiveEcuC/Com/ComConfig/BCM10_oC03_for_EL_CAN_V2_1_8175742c_Rx, /ActiveEcuC/Com/ComConfig/BCM10_oC03_for_EL_CAN_V2_1_8175742c_RxPduBased, /ActiveEcuC/Com/ComConfig/LTurnLampWorkCmd_oBCM10_oC03_for_EL_CAN_V2_1_7a1a08f4_Rx, /ActiveEcuC/Com/ComConfig/RTurnLmpWorkCmd_oBCM10_oC03_for_EL_CAN_V2_1_10ea9ba1_Rx, /ActiveEcuC/Com/ComConfig/Rollingcounter_BCM10_oBCM10_oC03_for_EL_CAN_V2_1_6dd2f1f9_Rx] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/AnimationReq_oBCM17_oC03_for_EL_CAN_V2_1_1db28c46_Rx, /ActiveEcuC/Com/ComConfig/BCM17_oC03_for_EL_CAN_V2_1_e4ac4a6c_Rx, /ActiveEcuC/Com/ComConfig/BCM17_oC03_for_EL_CAN_V2_1_e4ac4a6c_RxPduBased, /ActiveEcuC/Com/ComConfig/ApproachLightAnimationType_oBCM17_oC03_for_EL_CAN_V2_1_5b20a81e_Rx, /ActiveEcuC/Com/ComConfig/GoodbyeAnimationType_oBCM17_oC03_for_EL_CAN_V2_1_bc8c4dab_Rx, /ActiveEcuC/Com/ComConfig/MecDancAnimationType_oBCM17_oC03_for_EL_CAN_V2_1_6bb5a98f_Rx, /ActiveEcuC/Com/ComConfig/WelcomeAnimationType_oBCM17_oC03_for_EL_CAN_V2_1_c76d0f7a_Rx] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/CEMDetminCdnSts_oBCM23_oC03_for_EL_CAN_V2_1_df6348d5_Rx, /ActiveEcuC/Com/ComConfig/BCM23_oC03_for_EL_CAN_V2_1_cee8e051_Rx, /ActiveEcuC/Com/ComConfig/BCM23_oC03_for_EL_CAN_V2_1_cee8e051_RxPduBased] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/BMS_SOC_oBMS1_oC03_for_EL_CAN_V2_1_a261d1ce_Rx, /ActiveEcuC/Com/ComConfig/BMS1_oC03_for_EL_CAN_V2_1_ab80ae92_Rx, /ActiveEcuC/Com/ComConfig/BMS1_oC03_for_EL_CAN_V2_1_ab80ae92_RxPduBased] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/BMS_DCChrgConnect_oBMS17_oC03_for_EL_CAN_V2_1_91db617c_Rx, /ActiveEcuC/Com/ComConfig/BMS17_oC03_for_EL_CAN_V2_1_be27a4ae_Rx, /ActiveEcuC/Com/ComConfig/BMS17_oC03_for_EL_CAN_V2_1_be27a4ae_RxPduBased] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/LTurnLmpSwtSts_oCSA1_oC03_for_EL_CAN_V2_1_458e5c96_Rx, /ActiveEcuC/Com/ComConfig/CSA1_oC03_for_EL_CAN_V2_1_ffb47aea_Rx, /ActiveEcuC/Com/ComConfig/CSA1_oC03_for_EL_CAN_V2_1_ffb47aea_RxPduBased, /ActiveEcuC/Com/ComConfig/RTurnLmpSwtSts_oCSA1_oC03_for_EL_CAN_V2_1_2fe59187_Rx] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/DeepSlpCmd_oEEM1_oC03_for_EL_CAN_V2_1_41fb7d93_Rx, /ActiveEcuC/Com/ComConfig/EEM1_oC03_for_EL_CAN_V2_1_5bdcd994_Rx, /ActiveEcuC/Com/ComConfig/EEM1_oC03_for_EL_CAN_V2_1_5bdcd994_RxPduBased, /ActiveEcuC/Com/ComConfig/Stat_PwrSv_Lvl_oEEM1_oC03_for_EL_CAN_V2_1_a4eaa63e_Rx, /ActiveEcuC/Com/ComConfig/TranPMode_Sts_oEEM1_oC03_for_EL_CAN_V2_1_a5a3838d_Rx] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/ScenarioID_oGW1_oC03_for_EL_CAN_V2_1_b0249678_Rx, /ActiveEcuC/Com/ComConfig/GW1_oC03_for_EL_CAN_V2_1_48654b76_Rx, /ActiveEcuC/Com/ComConfig/GW1_oC03_for_EL_CAN_V2_1_48654b76_RxPduBased, /ActiveEcuC/Com/ComConfig/ScenarioReq_oGW1_oC03_for_EL_CAN_V2_1_d81adfac_Rx] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/TimeIndcn_oHUT34_oC03_for_EL_CAN_V2_1_d29435a0_Rx, /ActiveEcuC/Com/ComConfig/HUT34_oC03_for_EL_CAN_V2_1_6fae3f7a_Rx, /ActiveEcuC/Com/ComConfig/HUT34_oC03_for_EL_CAN_V2_1_6fae3f7a_RxPduBased, /ActiveEcuC/Com/ComConfig/TimeMod_oHUT34_oC03_for_EL_CAN_V2_1_baa135ee_Rx, /ActiveEcuC/Com/ComConfig/Time_Day_oHUT34_oC03_for_EL_CAN_V2_1_5996a937_Rx, /ActiveEcuC/Com/ComConfig/Time_Hour_oHUT34_oC03_for_EL_CAN_V2_1_2c4ebd6a_Rx, /ActiveEcuC/Com/ComConfig/Time_Minutes_oHUT34_oC03_for_EL_CAN_V2_1_da3ecd44_Rx, /ActiveEcuC/Com/ComConfig/Time_Month_oHUT34_oC03_for_EL_CAN_V2_1_33ed510d_Rx, /ActiveEcuC/Com/ComConfig/Time_Second_oHUT34_oC03_for_EL_CAN_V2_1_9732895b_Rx, /ActiveEcuC/Com/ComConfig/Time_Year_Left_oHUT34_oC03_for_EL_CAN_V2_1_f1a91267_Rx, /ActiveEcuC/Com/ComConfig/Time_Year_Right_oHUT34_oC03_for_EL_CAN_V2_1_fa890340_Rx] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/IP_VehTotDistanceValid_oIP2_oC03_for_EL_CAN_V2_1_234ac38e_Rx, /ActiveEcuC/Com/ComConfig/IP2_oC03_for_EL_CAN_V2_1_65941076_Rx, /ActiveEcuC/Com/ComConfig/IP2_oC03_for_EL_CAN_V2_1_65941076_RxPduBased, /ActiveEcuC/Com/ComConfig/IP_VehTotDistance_oIP2_oC03_for_EL_CAN_V2_1_a238a7cc_Rx] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/MCU_ActRotSpd_oMCU_5_oC03_for_EL_CAN_V2_1_c2eb67f0_Rx, /ActiveEcuC/Com/ComConfig/MCU_5_oC03_for_EL_CAN_V2_1_002cb201_Rx, /ActiveEcuC/Com/ComConfig/MCU_5_oC03_for_EL_CAN_V2_1_002cb201_RxPduBased] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/OBC_CCLineConnectSts_oOBC3_oC03_for_EL_CAN_V2_1_a7854723_Rx, /ActiveEcuC/Com/ComConfig/OBC3_oC03_for_EL_CAN_V2_1_158aa3d5_Rx, /ActiveEcuC/Com/ComConfig/OBC3_oC03_for_EL_CAN_V2_1_158aa3d5_RxPduBased] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/CheckSum_PEPS2_oPEPS2_oC03_for_EL_CAN_V2_1_06064851_Rx, /ActiveEcuC/Com/ComConfig/PEPS2_oC03_for_EL_CAN_V2_1_d41abfa7_Rx, /ActiveEcuC/Com/ComConfig/PEPS2_oC03_for_EL_CAN_V2_1_d41abfa7_RxPduBased, /ActiveEcuC/Com/ComConfig/RollingCounter_PEPS2_oPEPS2_oC03_for_EL_CAN_V2_1_9bd00531_Rx, /ActiveEcuC/Com/ComConfig/SysPowerModVld_oPEPS2_oC03_for_EL_CAN_V2_1_b6c20e3c_Rx, /ActiveEcuC/Com/ComConfig/SysPowerMod_oPEPS2_oC03_for_EL_CAN_V2_1_37fb939a_Rx] */
  /*    14 */  /* [/ActiveEcuC/Com/ComConfig/RMCU_ActRotSpd_oRMCU4_oC03_for_EL_CAN_V2_1_a08a2435_Rx, /ActiveEcuC/Com/ComConfig/RMCU4_oC03_for_EL_CAN_V2_1_55159990_Rx, /ActiveEcuC/Com/ComConfig/RMCU4_oC03_for_EL_CAN_V2_1_55159990_RxPduBased] */
  /*    15 */  /* [/ActiveEcuC/Com/ComConfig/PosnLmpOutpSts_R_PBox_oR_PBOX1_oC03_for_EL_CAN_V2_1_c63ace4d_Rx, /ActiveEcuC/Com/ComConfig/R_PBOX1_oC03_for_EL_CAN_V2_1_7854cc6e_Rx, /ActiveEcuC/Com/ComConfig/R_PBOX1_oC03_for_EL_CAN_V2_1_7854cc6e_RxPduBased] */
  /*    16 */  /* [/ActiveEcuC/Com/ComConfig/VCU_GearSts_oVCU2_oC03_for_EL_CAN_V2_1_71c2293d_Rx, /ActiveEcuC/Com/ComConfig/VCU2_oC03_for_EL_CAN_V2_1_bea872d3_Rx, /ActiveEcuC/Com/ComConfig/VCU2_oC03_for_EL_CAN_V2_1_bea872d3_RxPduBased] */
  /*    17 */  /* [/ActiveEcuC/Com/ComConfig/VCU_ChrgnSts_oVCU3_oC03_for_EL_CAN_V2_1_87b3fa1f_Rx, /ActiveEcuC/Com/ComConfig/VCU3_oC03_for_EL_CAN_V2_1_a9801613_Rx, /ActiveEcuC/Com/ComConfig/VCU3_oC03_for_EL_CAN_V2_1_a9801613_RxPduBased] */
  /*    18 */  /* [/ActiveEcuC/Com/ComConfig/VCU_BrkPedlSts_oVCU6_oC03_for_EL_CAN_V2_1_66fed013_Rx, /ActiveEcuC/Com/ComConfig/VCU6_oC03_for_EL_CAN_V2_1_e209e1d3_Rx, /ActiveEcuC/Com/ComConfig/VCU6_oC03_for_EL_CAN_V2_1_e209e1d3_RxPduBased] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TransmitRequest
**********************************************************************************************************************/
/** 
  \var    Com_TransmitRequest
  \brief  Transmit request flag used for decoupled Tx I-PDU tranmission.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_TransmitRequestType, COM_VAR_NOINIT) Com_TransmitRequest[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/ComIPdu_userData_tx] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/EIDC1_oC03_for_EL_CAN_V2_1_4a10c7b4_Tx, /ActiveEcuC/Com/ComConfig/EIDC_oC03_for_EL_CAN_V2_1_Tx_59496bbd] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxBuffer
**********************************************************************************************************************/
/** 
  \var    Com_TxBuffer
  \brief  Shared uint8 buffer for Tx I-PDUs and ComSignalGroup shadow buffer.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_TxBufferType, COM_VAR_NOINIT) Com_TxBuffer[14];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/ComIPdu_userData_tx] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/ComIPdu_userData_tx] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/ComIPdu_userData_tx, /ActiveEcuC/Com/ComConfig/ComSignal_userData_byte2_tx] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/ComIPdu_userData_tx, /ActiveEcuC/Com/ComConfig/ComSignal_userdata_Byte3_tx] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/ComIPdu_userData_tx] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/ComIPdu_userData_tx] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/EIDC1_oC03_for_EL_CAN_V2_1_4a10c7b4_Tx] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/EIDC1_oC03_for_EL_CAN_V2_1_4a10c7b4_Tx, /ActiveEcuC/Com/ComConfig/CurrEmojiSts_oEIDC1_oC03_for_EL_CAN_V2_1_6bd59cd2_Tx, /ActiveEcuC/Com/ComConfig/CurrTopicSts_oEIDC1_oC03_for_EL_CAN_V2_1_fe35aa4e_Tx, /ActiveEcuC/Com/ComConfig/EIDCOpenFBSts_oEIDC1_oC03_for_EL_CAN_V2_1_c910b9b6_Tx, /ActiveEcuC/Com/ComConfig/WelcomePatFailSts_oEIDC1_oC03_for_EL_CAN_V2_1_29fa7824_Tx] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/EIDC1_oC03_for_EL_CAN_V2_1_4a10c7b4_Tx, /ActiveEcuC/Com/ComConfig/ChrgDispPatFailSts_oEIDC1_oC03_for_EL_CAN_V2_1_ad1e97ef_Tx, /ActiveEcuC/Com/ComConfig/CurrRemdSts_oEIDC1_oC03_for_EL_CAN_V2_1_d08f6960_Tx, /ActiveEcuC/Com/ComConfig/CurrWelcomeSts_oEIDC1_oC03_for_EL_CAN_V2_1_adc4e5a0_Tx, /ActiveEcuC/Com/ComConfig/TurnRemdFailSts_oEIDC1_oC03_for_EL_CAN_V2_1_5d16f6d4_Tx] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/EIDC1_oC03_for_EL_CAN_V2_1_4a10c7b4_Tx, /ActiveEcuC/Com/ComConfig/CurrChrgDispSts_oEIDC1_oC03_for_EL_CAN_V2_1_b91c73c4_Tx, /ActiveEcuC/Com/ComConfig/CurrWordSts_oEIDC1_oC03_for_EL_CAN_V2_1_141f7025_Tx] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/EIDC1_oC03_for_EL_CAN_V2_1_4a10c7b4_Tx] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/EIDC1_oC03_for_EL_CAN_V2_1_4a10c7b4_Tx] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/EIDC1_oC03_for_EL_CAN_V2_1_4a10c7b4_Tx] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxCycleCounterDivisorCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_TxCycleCounterDivisorCounterType, COM_VAR_NOINIT) Com_TxCycleCounterDivisorCounter;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxCyclicProcessingISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_TxCyclicProcessingISRLockCounterType, COM_VAR_NOINIT) Com_TxCyclicProcessingISRLockCounter;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxIPduGroupISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_TxIPduGroupISRLockCounterType, COM_VAR_NOINIT) Com_TxIPduGroupISRLockCounter;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxPduGrpActive
**********************************************************************************************************************/
/** 
  \var    Com_TxPduGrpActive
  \brief  Tx I-PDU based state (started/stopped) of the corresponding I-PDU-Group.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_TxPduGrpActiveType, COM_VAR_NOINIT) Com_TxPduGrpActive[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/ComIPdu_userData_tx] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/EIDC1_oC03_for_EL_CAN_V2_1_4a10c7b4_Tx, /ActiveEcuC/Com/ComConfig/EIDC_oC03_for_EL_CAN_V2_1_Tx_59496bbd] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxProcessingISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_TxProcessingISRLockCounterType, COM_VAR_NOINIT) Com_TxProcessingISRLockCounter;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxSduLength
**********************************************************************************************************************/
/** 
  \var    Com_TxSduLength
  \brief  This var Array contains the Com Ipdu Length.
*/ 
#define COM_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_TxSduLengthType, COM_VAR_NOINIT) Com_TxSduLength[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/ComIPdu_userData_tx] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/EIDC1_oC03_for_EL_CAN_V2_1_4a10c7b4_Tx, /ActiveEcuC/Com/ComConfig/EIDC_oC03_for_EL_CAN_V2_1_Tx_59496bbd] */

#define COM_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
  LOCAL FUNCTION PROTOTYPES
**********************************************************************************************************************/



/**********************************************************************************************************************
  LOCAL FUNCTIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTIONS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/






/**********************************************************************************************************************
  END OF FILE: Com_Lcfg.c
**********************************************************************************************************************/

