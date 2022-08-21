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
 *            Module: CanIf
 *           Program: MSR_Vector_SLP4
 *          Customer: Nobo Automotive Systems Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F7016513ABG
 *    License Scope : The usage is restricted to CBD2000298_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: CanIf_Lcfg.c
 *   Generation Time: 2022-07-22 13:24:56
 *           Project: C03 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.24
 *
 *
 *********************************************************************************************************************/

#define CANIF_LCFG_SOURCE

/**********************************************************************************************************************
  \file  Includes
**********************************************************************************************************************/
/** 
  \brief  Required external files.
*/ 

#include "CanIf_Cfg.h"

 /*  CanNm Header Files  */ 
#include "CanNm_Cfg.h"
#include "CanNm_Cbk.h"
 /*  CanTp Header Files  */ 
#include "CanTp_Cfg.h"
#include "CanTp_Cbk.h"
 /*  PduR Header Files  */ 
#include "PduR_Cfg.h"
#include "PduR_CanIf.h"
 /*  CanSM Header Files  */ 
#include "CanSM_Cbk.h"

#define CANIF_START_SEC_APPL_CODE

#include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

/**********************************************************************************************************************
  \var  Prototypes of callback functions
**********************************************************************************************************************/

/** 
  \brief  Tx confirmation functions.
*/



/** 
  \brief  Rx indication functions.
*/




 /** 
  \brief  Wake-up validation function.
*/

FUNC(void, CANIF_APPL_CODE) CDD_ValidateWakeupEvent(EcuM_WakeupSourceType CanWakeupEvents);

#define CANIF_STOP_SEC_APPL_CODE

#include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

/**********************************************************************************************************************
  ComStackLib
**********************************************************************************************************************/
/**********************************************************************************************************************
  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA TYPES AND STRUCTURES
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
  CanIf_BusOffNotificationFctPtr
**********************************************************************************************************************/
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_BusOffNotificationFctType, CANIF_CONST) CanIf_BusOffNotificationFctPtr = CanSM_ControllerBusOff;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_CtrlConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_CtrlConfig
  \details
  Element              Description
  RxDHRandomNumber1    Rx - DoubleHash - 1st random number.
  RxDHRandomNumber2    Rx - DoubleHash - 2nd random number.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_CtrlConfigType, CANIF_CONST) CanIf_CtrlConfig[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    RxDHRandomNumber1  RxDHRandomNumber2        Comment */
  { /*     0 */           0xADB6u,           0x65EEu }   /* [CAN channel with handle ID: 0] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_CtrlModeIndicationFctPtr
**********************************************************************************************************************/
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_CtrlModeIndicationFctType, CANIF_CONST) CanIf_CtrlModeIndicationFctPtr = CanSM_ControllerModeIndication;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_MailBoxConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_MailBoxConfig
  \brief  Mailbox table.
  \details
  Element          Description
  CtrlStatesIdx    the index of the 1:1 relation pointing to CanIf_CtrlStates
  PduIdFirst       "First" PDU mapped to mailbox.
  PduIdLast        "Last" PDU mapped to mailbox.
  MailBoxType      Type of mailbox: Rx-/Tx- BasicCAN/FullCAN/unused.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_MailBoxConfigType, CANIF_CONST) CanIf_MailBoxConfig[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    CtrlStatesIdx                                                                                    PduIdFirst                           PduIdLast                           MailBoxType                    Referable Keys */
  { /*     0 */            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_C03_for_EL_CAN_V2_1_fdbf7169 */,         1u  /* RxPduId */          ,       22u  /* RxPduId  */         , CANIF_RxBasicCANMailbox },  /* [/ActiveEcuC/Can/CanConfigSet/CN_C03_for_EL_CAN_V2_1_275479c7_Rx] */
  { /*     1 */            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_C03_for_EL_CAN_V2_1_fdbf7169 */,         0u  /* Unused, TxPduId 0 */,        0u  /* Unused, TxPduId 2 */, CANIF_TxBasicCANMailbox }   /* [/ActiveEcuC/Can/CanConfigSet/CN_C03_for_EL_CAN_V2_1_776d6b8e_Tx] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_RxDHAdjust
**********************************************************************************************************************/
/** 
  \var    CanIf_RxDHAdjust
  \brief  Rx - DoubleHash - adjust values.
*/ 
#define CANIF_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_RxDHAdjustType, CANIF_CONST) CanIf_RxDHAdjust[25] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     RxDHAdjust  */
  /*     0 */       0x00u,
  /*     1 */       0x0Fu,
  /*     2 */       0x01u,
  /*     3 */       0x08u,
  /*     4 */       0x04u,
  /*     5 */       0x0Cu,
  /*     6 */       0x05u,
  /*     7 */       0x0Eu,
  /*     8 */       0x12u,
  /*     9 */       0x0Cu,
  /*    10 */       0x07u,
  /*    11 */       0x15u,
  /*    12 */       0x0Cu,
  /*    13 */       0x13u,
  /*    14 */       0x16u,
  /*    15 */       0x15u,
  /*    16 */       0x02u,
  /*    17 */       0x12u,
  /*    18 */       0x13u,
  /*    19 */       0x15u,
  /*    20 */       0x08u,
  /*    21 */       0x11u,
  /*    22 */       0x0Fu,
  /*    23 */       0x15u,
  /*    24 */       0x11u
};
#define CANIF_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_RxIndicationFctList
**********************************************************************************************************************/
/** 
  \var    CanIf_RxIndicationFctList
  \brief  Rx indication functions table.
  \details
  Element               Description
  RxIndicationFct       Rx indication function.
  RxIndicationLayout    Layout of Rx indication function.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_RxIndicationFctListType, CANIF_CONST) CanIf_RxIndicationFctList[4] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    RxIndicationFct                                               RxIndicationLayout                                                                 Referable Keys */
  { /*     0 */  { (CanIf_SimpleRxIndicationFctType)NULL_PTR }              , CanIf_SimpleRxIndicationLayout    /* PRQA S 0313 */ /* MD_CanIf_Rule11.1 */ },  /* [NULL_PTR] */
  { /*     1 */  { (CanIf_SimpleRxIndicationFctType)CanNm_RxIndication }    , CanIf_AdvancedRxIndicationLayout  /* PRQA S 0313 */ /* MD_CanIf_Rule11.1 */ },  /* [CanNm_RxIndication] */
  { /*     2 */  { (CanIf_SimpleRxIndicationFctType)CanTp_RxIndication }    , CanIf_AdvancedRxIndicationLayout  /* PRQA S 0313 */ /* MD_CanIf_Rule11.1 */ },  /* [CanTp_RxIndication] */
  { /*     3 */  { (CanIf_SimpleRxIndicationFctType)PduR_CanIfRxIndication }, CanIf_AdvancedRxIndicationLayout  /* PRQA S 0313 */ /* MD_CanIf_Rule11.1 */ }   /* [PduR_CanIfRxIndication] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_RxPduConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_RxPduConfig
  \brief  Rx-PDU configuration table.
  \details
  Element                   Description
  UpperPduId                PDU ID defined by upper layer.
  RxPduCanId                Rx-PDU: CAN identifier.
  RxPduMask                 Rx-PDU: CAN identifier mask.
  IsCanNmRxPdu              TRUE: CAN-Nm Rx-PDU (for Wakeup validation), FALSE: No CAN-Nm Rx-PDU
  RxIndicationFctListIdx    the index of the 1:1 relation pointing to CanIf_RxIndicationFctList
  RxPduDlc                  Rx-PDU length (DLC).
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_RxPduConfigType, CANIF_CONST) CanIf_RxPduConfig[23] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    UpperPduId                                                RxPduCanId                                                                          RxPduMask                                                          IsCanNmRxPdu  RxIndicationFctListIdx                                RxPduDlc                                    Comment                                                                           Referable Keys */
  { /*     0 */ CanNmConf_CanNmRxPdu_C03_for_EL_CAN_V2_1_CAN_db47340e_Rx,    0x0500u  /* Lower CanId of range: EIDC_d00ebf9b_Rx, 2.0- or FD-PDU */          ,   0x6563u  /* Upper CanId of range: EIDC_d00ebf9b_Rx */          , TRUE        ,                     1u  /* CanNm_RxIndication */    ,       8u  /* DLC-Check is enabled */ },  /* [PDU: EIDC_d00ebf9b_Rx, Lower CanId of range: 0x500]                  */  /* [CanIfConf_CanIfRxPduCfg_EIDC_d00ebf9b_Rx] */
  { /*     1 */ CanTpConf_CanTpRxNPdu_CanTpRxNPdu_cc4262e8              ,    0x0760u  /* DiagFuncReq_Tp_oC03_for_EL_CAN_V2_1_5e7f56fc_Rx, 2.0- or FD-PDU */ ,   0x07FFu  /* DiagFuncReq_Tp_oC03_for_EL_CAN_V2_1_5e7f56fc_Rx */ , FALSE       ,                     2u  /* CanTp_RxIndication */    ,       8u  /* DLC-Check is enabled */ },  /* [PDU: DiagFuncReq_Tp_oC03_for_EL_CAN_V2_1_5e7f56fc_Rx, CanId: 0x760]  */  /* [CanIfConf_CanIfRxPduCfg_DiagFuncReq_Tp_oC03_for_EL_CAN_V2_1_5e7f56fc_Rx] */
  { /*     2 */ CanTpConf_CanTpRxNPdu_CanTpRxNPdu_566a9de7              ,    0x06A2u  /* EIDC_Phy_Req_Tp_oC03_for_EL_CAN_V2_1_8ecafd3d_Rx, 2.0- or FD-PDU */,   0x07FFu  /* EIDC_Phy_Req_Tp_oC03_for_EL_CAN_V2_1_8ecafd3d_Rx */, FALSE       ,                     2u  /* CanTp_RxIndication */    ,       8u  /* DLC-Check is enabled */ },  /* [PDU: EIDC_Phy_Req_Tp_oC03_for_EL_CAN_V2_1_8ecafd3d_Rx, CanId: 0x6a2] */  /* [CanIfConf_CanIfRxPduCfg_EIDC_Phy_Req_Tp_oC03_for_EL_CAN_V2_1_8ecafd3d_Rx] */
  { /*     3 */ PduRConf_PduRSrcPdu_PduRSrcPdu_3a99a829                 ,    0x0370u  /* HUT34_oC03_for_EL_CAN_V2_1_143ece40_Rx, 2.0- or FD-PDU */          ,   0x07FFu  /* HUT34_oC03_for_EL_CAN_V2_1_143ece40_Rx */          , FALSE       ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */ },  /* [PDU: HUT34_oC03_for_EL_CAN_V2_1_143ece40_Rx, CanId: 0x370]           */  /* [CanIfConf_CanIfRxPduCfg_HUT34_oC03_for_EL_CAN_V2_1_143ece40_Rx] */
  { /*     4 */ PduRConf_PduRSrcPdu_PduRSrcPdu_ab68ea3f                 ,    0x031Fu  /* OBC3_oC03_for_EL_CAN_V2_1_f116260f_Rx, 2.0- or FD-PDU */           ,   0x07FFu  /* OBC3_oC03_for_EL_CAN_V2_1_f116260f_Rx */           , FALSE       ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */ },  /* [PDU: OBC3_oC03_for_EL_CAN_V2_1_f116260f_Rx, CanId: 0x31f]            */  /* [CanIfConf_CanIfRxPduCfg_OBC3_oC03_for_EL_CAN_V2_1_f116260f_Rx] */
  { /*     5 */ PduRConf_PduRSrcPdu_PduRSrcPdu_980de097                 ,    0x02FFu  /* BMS17_oC03_for_EL_CAN_V2_1_ad6fc498_Rx, 2.0- or FD-PDU */          ,   0x07FFu  /* BMS17_oC03_for_EL_CAN_V2_1_ad6fc498_Rx */          , FALSE       ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */ },  /* [PDU: BMS17_oC03_for_EL_CAN_V2_1_ad6fc498_Rx, CanId: 0x2ff]           */  /* [CanIfConf_CanIfRxPduCfg_BMS17_oC03_for_EL_CAN_V2_1_ad6fc498_Rx] */
  { /*     6 */ PduRConf_PduRSrcPdu_PduRSrcPdu_4466940f                 ,    0x02E7u  /* BCM10_oC03_for_EL_CAN_V2_1_7a878984_Rx, 2.0- or FD-PDU */          ,   0x07FFu  /* BCM10_oC03_for_EL_CAN_V2_1_7a878984_Rx */          , FALSE       ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */ },  /* [PDU: BCM10_oC03_for_EL_CAN_V2_1_7a878984_Rx, CanId: 0x2e7]           */  /* [CanIfConf_CanIfRxPduCfg_BCM10_oC03_for_EL_CAN_V2_1_7a878984_Rx] */
  { /*     7 */ PduRConf_PduRSrcPdu_PduRSrcPdu_2c3755d1                 ,    0x02DFu  /* BCM23_oC03_for_EL_CAN_V2_1_48d68db7_Rx, 2.0- or FD-PDU */          ,   0x07FFu  /* BCM23_oC03_for_EL_CAN_V2_1_48d68db7_Rx */          , FALSE       ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */ },  /* [PDU: BCM23_oC03_for_EL_CAN_V2_1_48d68db7_Rx, CanId: 0x2df]           */  /* [CanIfConf_CanIfRxPduCfg_BCM23_oC03_for_EL_CAN_V2_1_48d68db7_Rx] */
  { /*     8 */ PduRConf_PduRSrcPdu_PduRSrcPdu_4a521786                 ,    0x02A8u  /* EEM1_oC03_for_EL_CAN_V2_1_10af1dec_Rx, 2.0- or FD-PDU */           ,   0x07FFu  /* EEM1_oC03_for_EL_CAN_V2_1_10af1dec_Rx */           , FALSE       ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */ },  /* [PDU: EEM1_oC03_for_EL_CAN_V2_1_10af1dec_Rx, CanId: 0x2a8]            */  /* [CanIfConf_CanIfRxPduCfg_EEM1_oC03_for_EL_CAN_V2_1_10af1dec_Rx] */
  { /*     9 */ PduRConf_PduRSrcPdu_PduRSrcPdu_189ccf5d                 ,    0x0295u  /* PEPS2_oC03_for_EL_CAN_V2_1_f31f5d58_Rx, 2.0- or FD-PDU */          ,   0x07FFu  /* PEPS2_oC03_for_EL_CAN_V2_1_f31f5d58_Rx */          , FALSE       ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */ },  /* [PDU: PEPS2_oC03_for_EL_CAN_V2_1_f31f5d58_Rx, CanId: 0x295]           */  /* [CanIfConf_CanIfRxPduCfg_PEPS2_oC03_for_EL_CAN_V2_1_f31f5d58_Rx] */
  { /*    10 */ PduRConf_PduRSrcPdu_PduRSrcPdu_2d386857                 ,    0x0294u  /* VCU3_oC03_for_EL_CAN_V2_1_daf816cd_Rx, 2.0- or FD-PDU */           ,   0x07FFu  /* VCU3_oC03_for_EL_CAN_V2_1_daf816cd_Rx */           , FALSE       ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */ },  /* [PDU: VCU3_oC03_for_EL_CAN_V2_1_daf816cd_Rx, CanId: 0x294]            */  /* [CanIfConf_CanIfRxPduCfg_VCU3_oC03_for_EL_CAN_V2_1_daf816cd_Rx] */
  { /*    11 */ PduRConf_PduRSrcPdu_PduRSrcPdu_f526491e                 ,    0x027Fu  /* IP2_oC03_for_EL_CAN_V2_1_b4a8da0a_Rx, 2.0- or FD-PDU */            ,   0x07FFu  /* IP2_oC03_for_EL_CAN_V2_1_b4a8da0a_Rx */            , FALSE       ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */ },  /* [PDU: IP2_oC03_for_EL_CAN_V2_1_b4a8da0a_Rx, CanId: 0x27f]             */  /* [CanIfConf_CanIfRxPduCfg_IP2_oC03_for_EL_CAN_V2_1_b4a8da0a_Rx] */
  { /*    12 */ PduRConf_PduRSrcPdu_PduRSrcPdu_0334d61b                 ,    0x0265u  /* ABS3_oC03_for_EL_CAN_V2_1_10dc2254_Rx, 2.0- or FD-PDU */           ,   0x07FFu  /* ABS3_oC03_for_EL_CAN_V2_1_10dc2254_Rx */           , FALSE       ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */ },  /* [PDU: ABS3_oC03_for_EL_CAN_V2_1_10dc2254_Rx, CanId: 0x265]            */  /* [CanIfConf_CanIfRxPduCfg_ABS3_oC03_for_EL_CAN_V2_1_10dc2254_Rx] */
  { /*    13 */ PduRConf_PduRSrcPdu_PduRSrcPdu_4042d41e                 ,    0x023Eu  /* BCM17_oC03_for_EL_CAN_V2_1_d096ac17_Rx, 2.0- or FD-PDU */          ,   0x07FFu  /* BCM17_oC03_for_EL_CAN_V2_1_d096ac17_Rx */          , FALSE       ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */ },  /* [PDU: BCM17_oC03_for_EL_CAN_V2_1_d096ac17_Rx, CanId: 0x23e]           */  /* [CanIfConf_CanIfRxPduCfg_BCM17_oC03_for_EL_CAN_V2_1_d096ac17_Rx] */
  { /*    14 */ PduRConf_PduRSrcPdu_PduRSrcPdu_bdde61e0                 ,    0x0239u  /* GW1_oC03_for_EL_CAN_V2_1_ea292310_Rx, 2.0- or FD-PDU */            ,   0x07FFu  /* GW1_oC03_for_EL_CAN_V2_1_ea292310_Rx */            , FALSE       ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */ },  /* [PDU: GW1_oC03_for_EL_CAN_V2_1_ea292310_Rx, CanId: 0x239]             */  /* [CanIfConf_CanIfRxPduCfg_GW1_oC03_for_EL_CAN_V2_1_ea292310_Rx] */
  { /*    15 */ PduRConf_PduRSrcPdu_PduRSrcPdu_248a65bc                 ,    0x01F7u  /* HUT54_oC03_for_EL_CAN_V2_1_2d6081c5_Rx, 2.0- or FD-PDU */          ,   0x07FFu  /* HUT54_oC03_for_EL_CAN_V2_1_2d6081c5_Rx */          , FALSE       ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */ },  /* [PDU: HUT54_oC03_for_EL_CAN_V2_1_2d6081c5_Rx, CanId: 0x1f7]           */  /* [CanIfConf_CanIfRxPduCfg_HUT54_oC03_for_EL_CAN_V2_1_2d6081c5_Rx] */
  { /*    16 */ PduRConf_PduRSrcPdu_PduRSrcPdu_b249ed83                 ,    0x019Cu  /* R_PBOX1_oC03_for_EL_CAN_V2_1_319fe0ab_Rx, 2.0- or FD-PDU */        ,   0x07FFu  /* R_PBOX1_oC03_for_EL_CAN_V2_1_319fe0ab_Rx */        , FALSE       ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */ },  /* [PDU: R_PBOX1_oC03_for_EL_CAN_V2_1_319fe0ab_Rx, CanId: 0x19c]         */  /* [CanIfConf_CanIfRxPduCfg_R_PBOX1_oC03_for_EL_CAN_V2_1_319fe0ab_Rx] */
  { /*    17 */ PduRConf_PduRSrcPdu_PduRSrcPdu_81d0b539                 ,    0x0194u  /* VCU2_oC03_for_EL_CAN_V2_1_22ca0bce_Rx, 2.0- or FD-PDU */           ,   0x07FFu  /* VCU2_oC03_for_EL_CAN_V2_1_22ca0bce_Rx */           , FALSE       ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */ },  /* [PDU: VCU2_oC03_for_EL_CAN_V2_1_22ca0bce_Rx, CanId: 0x194]            */  /* [CanIfConf_CanIfRxPduCfg_VCU2_oC03_for_EL_CAN_V2_1_22ca0bce_Rx] */
  { /*    18 */ PduRConf_PduRSrcPdu_PduRSrcPdu_8a7ea6f5                 ,    0x0165u  /* CSA1_oC03_for_EL_CAN_V2_1_804a6834_Rx, 2.0- or FD-PDU */           ,   0x07FFu  /* CSA1_oC03_for_EL_CAN_V2_1_804a6834_Rx */           , FALSE       ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */ },  /* [PDU: CSA1_oC03_for_EL_CAN_V2_1_804a6834_Rx, CanId: 0x165]            */  /* [CanIfConf_CanIfRxPduCfg_CSA1_oC03_for_EL_CAN_V2_1_804a6834_Rx] */
  { /*    19 */ PduRConf_PduRSrcPdu_PduRSrcPdu_b1d6a3ac                 ,    0x00E7u  /* RMCU4_oC03_for_EL_CAN_V2_1_2d4c42d7_Rx, 2.0- or FD-PDU */          ,   0x07FFu  /* RMCU4_oC03_for_EL_CAN_V2_1_2d4c42d7_Rx */          , FALSE       ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */ },  /* [PDU: RMCU4_oC03_for_EL_CAN_V2_1_2d4c42d7_Rx, CanId: 0xe7]            */  /* [CanIfConf_CanIfRxPduCfg_RMCU4_oC03_for_EL_CAN_V2_1_2d4c42d7_Rx] */
  { /*    20 */ PduRConf_PduRSrcPdu_PduRSrcPdu_b7c754b1                 ,    0x00D4u  /* VCU6_oC03_for_EL_CAN_V2_1_74e07340_Rx, 2.0- or FD-PDU */           ,   0x07FFu  /* VCU6_oC03_for_EL_CAN_V2_1_74e07340_Rx */           , FALSE       ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */ },  /* [PDU: VCU6_oC03_for_EL_CAN_V2_1_74e07340_Rx, CanId: 0xd4]             */  /* [CanIfConf_CanIfRxPduCfg_VCU6_oC03_for_EL_CAN_V2_1_74e07340_Rx] */
  { /*    21 */ PduRConf_PduRSrcPdu_PduRSrcPdu_6f17b236                 ,    0x00D2u  /* MCU_5_oC03_for_EL_CAN_V2_1_d41a8452_Rx, 2.0- or FD-PDU */          ,   0x07FFu  /* MCU_5_oC03_for_EL_CAN_V2_1_d41a8452_Rx */          , FALSE       ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */ },  /* [PDU: MCU_5_oC03_for_EL_CAN_V2_1_d41a8452_Rx, CanId: 0xd2]            */  /* [CanIfConf_CanIfRxPduCfg_MCU_5_oC03_for_EL_CAN_V2_1_d41a8452_Rx] */
  { /*    22 */ PduRConf_PduRSrcPdu_PduRSrcPdu_6c53f7c1                 ,    0x00C4u  /* BMS1_oC03_for_EL_CAN_V2_1_6aa0fb4e_Rx, 2.0- or FD-PDU */           ,   0x07FFu  /* BMS1_oC03_for_EL_CAN_V2_1_6aa0fb4e_Rx */           , FALSE       ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */ }   /* [PDU: BMS1_oC03_for_EL_CAN_V2_1_6aa0fb4e_Rx, CanId: 0xc4]             */  /* [CanIfConf_CanIfRxPduCfg_BMS1_oC03_for_EL_CAN_V2_1_6aa0fb4e_Rx] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxConfirmationFctList
**********************************************************************************************************************/
/** 
  \var    CanIf_TxConfirmationFctList
  \brief  Tx confirmation functions table.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_TxConfirmationFctType, CANIF_CONST) CanIf_TxConfirmationFctList[4] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     TxConfirmationFctList                      Referable Keys */
  /*     0 */ (CanIf_TxConfirmationFctType)NULL_PTR ,  /* [NULL_PTR] */
  /*     1 */ CanNm_TxConfirmation                  ,  /* [CanNm_TxConfirmation] */
  /*     2 */ CanTp_TxConfirmation                  ,  /* [CanTp_TxConfirmation] */
  /*     3 */ PduR_CanIfTxConfirmation                 /* [PduR_CanIfTxConfirmation] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxPduConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_TxPduConfig
  \brief  Tx-PDUs - configuration.
  \details
  Element                     Description
  UpperLayerTxPduId           Upper layer handle ID (8bit / 16bit).
  CanId                       CAN identifier (16bit / 32bit).
  IsTxPduTruncation           TRUE: Truncation of Tx-PDU is enabled, FALSE: Truncation of Tx-PDU is disabled
  CtrlStatesIdx               the index of the 1:1 relation pointing to CanIf_CtrlStates
  MailBoxConfigIdx            the index of the 1:1 relation pointing to CanIf_MailBoxConfig
  TxConfirmationFctListIdx    the index of the 1:1 relation pointing to CanIf_TxConfirmationFctList
  TxPduLength                 Tx-PDU length.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_TxPduConfigType, CANIF_CONST) CanIf_TxPduConfig[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    UpperLayerTxPduId                                              CanId    IsTxPduTruncation  CtrlStatesIdx                                                                                    MailBoxConfigIdx                                                                         TxConfirmationFctListIdx                                  TxPduLength        Comment                                                              Referable Keys */
  { /*     0 */ CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_566a9de7               , 0x06A3u, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_C03_for_EL_CAN_V2_1_fdbf7169 */,               1u  /* /ActiveEcuC/Can/CanConfigSet/CN_C03_for_EL_CAN_V2_1_776d6b8e_Tx */,                       2u  /* CanTp_TxConfirmation */    ,          8u },  /* [PDU: EIDC_Phy_Resp_Tp_oC03_for_EL_CAN_V2_1_a1fe608c_Tx] */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/EIDC_Phy_Resp_Tp_oC03_for_EL_CAN_V2_1_a1fe608c_Tx] */
  { /*     1 */ CanNmConf_CanNmTxPdu_EIDC_NM_oC03_for_EL_CAN_V2_1_1aed8ca4_Tx, 0x0556u, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_C03_for_EL_CAN_V2_1_fdbf7169 */,               1u  /* /ActiveEcuC/Can/CanConfigSet/CN_C03_for_EL_CAN_V2_1_776d6b8e_Tx */,                       1u  /* CanNm_TxConfirmation */    ,          8u },  /* [PDU: EIDC_NM_oC03_for_EL_CAN_V2_1_323e586b_Tx]          */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/EIDC_NM_oC03_for_EL_CAN_V2_1_323e586b_Tx] */
  { /*     2 */ PduRConf_PduRDestPdu_EIDC1_oC03_for_EL_CAN_V2_1_17d720dc_Tx  , 0x033Au, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_C03_for_EL_CAN_V2_1_fdbf7169 */,               1u  /* /ActiveEcuC/Can/CanConfigSet/CN_C03_for_EL_CAN_V2_1_776d6b8e_Tx */,                       3u  /* PduR_CanIfTxConfirmation */,          8u }   /* [PDU: EIDC1_oC03_for_EL_CAN_V2_1_fd2fa739_Tx]            */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/EIDC1_oC03_for_EL_CAN_V2_1_fd2fa739_Tx] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_WakeUpConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_WakeUpConfig
  \brief  Wake-up source configuration
  \details
  Element                Description
  Controller             CAN controller handle ID
  WakeUpSource           Wake-up source identifier
  WakeUpTargetAddress    Logical handle ID of target (CAN controller / transceiver)
  WakeUpTargetModule     Target for wake-up source: CAN controller / transceiver
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_WakeUpConfigType, CANIF_CONST) CanIf_WakeUpConfig[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Controller  WakeUpSource  WakeUpTargetAddress  WakeUpTargetModule             Comment */
  { /*     0 */         0u,          32u,                  0u, CANIF_WAKEUPREQUEST_CAN } 
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_WakeUpValidationFctPtr
**********************************************************************************************************************/
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_WakeUpValidationFctType, CANIF_CONST) CanIf_WakeUpValidationFctPtr = CDD_ValidateWakeupEvent;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_CtrlStates
**********************************************************************************************************************/
/** 
  \var    CanIf_CtrlStates
  \details
  Element                  Description
  CtrlMode                 Controller mode.
  PduMode                  PDU mode state.
  WakeUpValidationState    Wake-up validation state.
*/ 
#define CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanIf_CtrlStatesUType, CANIF_VAR_NOINIT) CanIf_CtrlStates;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_C03_for_EL_CAN_V2_1_fdbf7169] */

#define CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/



