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
 *            Module: PduR
 *           Program: MSR_Vector_SLP4
 *          Customer: Nobo Automotive Systems Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F7016513ABG
 *    License Scope : The usage is restricted to CBD2000298_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: PduR_Lcfg.c
 *   Generation Time: 2022-06-27 14:57:38
 *           Project: C03 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.24
 *
 *
 *********************************************************************************************************************/

#define PDUR_LCFG_SOURCE

/**********************************************************************************************************************
 * MISRA / PCLINT JUSTIFICATION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "PduR.h"
#include "PduR_Fm.h"
#include "PduR_IFQ.h"
#include "PduR_Sm.h"
#include "PduR_RmIf.h"
#include "PduR_RmTp.h"
#include "PduR_RmTp_TxInst.h"
#include "SchM_PduR.h"
#if(PDUR_DEV_ERROR_REPORT == STD_ON)
# include "Det.h"
#endif
# include "PduR_Lcfg.h"



/* Include headers with callbacks */
#include "PduR_CanIf.h"
#include "PduR_CanTp.h"
#include "PduR_Com.h"
#include "PduR_Dcm.h"
#include "PduR_CanNm.h"


/**********************************************************************************************************************
 * LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/* Exclusive Area Wrapper functions */
static FUNC(void, PDUR_CODE) PduR_SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0(void);
static FUNC(void, PDUR_CODE) PduR_SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0(void);
  
/**********************************************************************************************************************
 * LOCAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * GLOBAL DATA
 *********************************************************************************************************************/
/* \trace SPEC-663, SPEC-661 */

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  PduR_ExclusiveAreaRom
**********************************************************************************************************************/
/** 
  \var    PduR_ExclusiveAreaRom
  \brief  PduR Exclusive Area Locks
  \details
  Element    Description
  Lock       Lock function
  Unlock     Unlock function
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(PduR_ExclusiveAreaRomType, PDUR_CONST) PduR_ExclusiveAreaRom[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Lock                                        Unlock                                           Referable Keys */
  { /*     0 */ PduR_SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0, PduR_SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0 }   /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRLock_PduRExclusiveArea] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_GeneralPropertiesRom
**********************************************************************************************************************/
/** 
  \var    PduR_GeneralPropertiesRom
  \brief  General Properties Switches of the PduR.
  \details
  Element         Description
  hasIfRouting
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(PduR_GeneralPropertiesRomType, PDUR_CONST) PduR_GeneralPropertiesRom[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    hasIfRouting        Referable Keys */
  { /*     0 */         TRUE }   /* [/ActiveEcuC/PduR] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_MmRom
**********************************************************************************************************************/
/** 
  \var    PduR_MmRom
  \brief  Module manager: Contains all function pointers of the bordering modules.
  \details
  Element                         Description
  DestApplicationManagerRomIdx    the index of the 1:1 relation pointing to PduR_DestApplicationManagerRom
  MaskedBits                      contains bitcoded the boolean data of PduR_LoIfOfMmRom, PduR_LoTpOfMmRom, PduR_RmGDestRomUsedOfMmRom, PduR_UpIfOfMmRom, PduR_UpTpOfMmRom
  RmGDestRomEndIdx                the end index of the 0:n relation pointing to PduR_RmGDestRom
  RmGDestRomStartIdx              the start index of the 0:n relation pointing to PduR_RmGDestRom
  UpTpCopyRxDataFctPtr            Transport protocol CopyRxData function pointers
  UpTpCopyTxDataFctPtr            Transport protocol CopyTxData function pointers
  UpIfRxIndicationFctPtr          Upper layer communication interface Rx indication function pointers.
  UpIfTxConfirmationFctPtr        Upper layer communication interface Tx confimation function pointers
  UpTpStartOfReceptionFctPtr      Transport protocol StartOfReception function pointers
  UpTpTpRxIndicationFctPtr        Transport protocol TpRxIndication function pointers
  UpTpTpTxConfirmationFctPtr      Transport protocol TpTxConfimation function pointers
  LoIfTransmitFctPtr              Lower layer If transmit function pointers
  LoTpTransmitFctPtr              Lower layer Tp transmit function pointers
  UpIfTriggerTransmitFctPtr       Upper layer trigger transmit function pointers
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(PduR_MmRomType, PDUR_CONST) PduR_MmRom[5] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    DestApplicationManagerRomIdx  MaskedBits  RmGDestRomEndIdx  RmGDestRomStartIdx  UpTpCopyRxDataFctPtr  UpTpCopyTxDataFctPtr  UpIfRxIndicationFctPtr  UpIfTxConfirmationFctPtr  UpTpStartOfReceptionFctPtr  UpTpTpRxIndicationFctPtr  UpTpTpTxConfirmationFctPtr  LoIfTransmitFctPtr  LoTpTransmitFctPtr  UpIfTriggerTransmitFctPtr        Comment                        Referable Keys */
  { /*     0 */                           0u,      0x14u,               1u,                 0u, NULL_PTR            , NULL_PTR            , NULL_PTR              , NULL_PTR                , NULL_PTR                  , NULL_PTR                , NULL_PTR                  , CanIf_Transmit    , NULL_PTR          , NULL_PTR                  },  /* [BswModule: CanIf] */  /* [/ActiveEcuC/PduR/CanIf, /ActiveEcuC/PduR] */
  { /*     1 */                           0u,      0x14u,               2u,                 1u, NULL_PTR            , NULL_PTR            , NULL_PTR              , NULL_PTR                , NULL_PTR                  , NULL_PTR                , NULL_PTR                  , CanNm_Transmit    , NULL_PTR          , NULL_PTR                  },  /* [BswModule: CanNm] */  /* [/ActiveEcuC/PduR/CanNm, /ActiveEcuC/PduR] */
  { /*     2 */                           0u,      0x0Cu,               3u,                 2u, NULL_PTR            , NULL_PTR            , NULL_PTR              , NULL_PTR                , NULL_PTR                  , NULL_PTR                , NULL_PTR                  , NULL_PTR          , CanTp_Transmit    , NULL_PTR                  },  /* [BswModule: CanTp] */  /* [/ActiveEcuC/PduR/CanTp, /ActiveEcuC/PduR] */
  { /*     3 */                           0u,      0x06u,              23u,                 3u, NULL_PTR            , NULL_PTR            , Com_RxIndication      , Com_TxConfirmation      , NULL_PTR                  , NULL_PTR                , NULL_PTR                  , NULL_PTR          , NULL_PTR          , Com_TriggerTransmit       },  /* [BswModule: Com]   */  /* [/ActiveEcuC/PduR/Com, /ActiveEcuC/PduR] */
  { /*     4 */                           0u,      0x05u,              25u,                23u, Dcm_CopyRxData      , Dcm_CopyTxData      , NULL_PTR              , NULL_PTR                , Dcm_StartOfReception      , Dcm_TpRxIndication      , Dcm_TpTxConfirmation      , NULL_PTR          , NULL_PTR          , NULL_PTR                  }   /* [BswModule: Dcm]   */  /* [/ActiveEcuC/PduR/Dcm, /ActiveEcuC/PduR] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_PartitionIdentifiers
**********************************************************************************************************************/
/** 
  \var    PduR_PartitionIdentifiers
  \brief  the partition context in Config
  \details
  Element         Description
  PartitionSNV
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(PduR_PartitionIdentifiersType, PDUR_CONST) PduR_PartitionIdentifiers[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PartitionSNV       */
  { /*     0 */ CommonSharedMemory }
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_RmDestRom
**********************************************************************************************************************/
/** 
  \var    PduR_RmDestRom
  \brief  PduR RoutiongPathManager destPdu Table
  \details
  Element                      Description
  PartitionIndexOfCsl      
  PduLengthHandlingStrategy    The strategy how larger than configured If Pdus are handled.
  RmGDestRomIdx                the index of the 1:1 relation pointing to PduR_RmGDestRom
  RmSrcRomIdx                  the index of the 1:1 relation pointing to PduR_RmSrcRom
  RoutingType                  Type of the Routing (API Forwarding, Gateway).
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(PduR_RmDestRomType, PDUR_CONST) PduR_RmDestRom[25] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PartitionIndexOfCsl                            PduLengthHandlingStrategy                         RmGDestRomIdx  RmSrcRomIdx  RoutingType                                                 Comment                                                                              Referable Keys */
  { /*     0 */                  0u  /* CommonSharedMemory */, PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,            1u,         24u, PDUR_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: PduRDestPdu]                                               */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/PduRRoutingPath_userdata_tx/PduRSrcPdu, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/PduRRoutingPath_userdata_tx/PduRDestPdu] */
  { /*     1 */                  0u  /* CommonSharedMemory */, PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,            3u,          0u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: ABS3_oC03_for_EL_CAN_V2_1_97a6dd96_Rx_0334d61b_Rx]         */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ABS3_oC03_for_EL_CAN_V2_1_97a6dd96_Rx/PduRSrcPdu_0334d61b, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ABS3_oC03_for_EL_CAN_V2_1_97a6dd96_Rx/ABS3_oC03_for_EL_CAN_V2_1_97a6dd96_Rx_0334d61b_Rx] */
  { /*     2 */                  0u  /* CommonSharedMemory */, PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           17u,         14u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: PEPS2_oC03_for_EL_CAN_V2_1_f4dd9817_Rx_189ccf5d_Rx]        */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/PEPS2_oC03_for_EL_CAN_V2_1_f4dd9817_Rx/PduRSrcPdu_189ccf5d, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/PEPS2_oC03_for_EL_CAN_V2_1_f4dd9817_Rx/PEPS2_oC03_for_EL_CAN_V2_1_f4dd9817_Rx_189ccf5d_Rx] */
  { /*     3 */                  0u  /* CommonSharedMemory */, PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           13u,         10u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: HUT54_oC03_for_EL_CAN_V2_1_cb808d88_Rx_248a65bc_Rx]        */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/HUT54_oC03_for_EL_CAN_V2_1_cb808d88_Rx/PduRSrcPdu_248a65bc, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/HUT54_oC03_for_EL_CAN_V2_1_cb808d88_Rx/HUT54_oC03_for_EL_CAN_V2_1_cb808d88_Rx_248a65bc_Rx] */
  { /*     4 */                  0u  /* CommonSharedMemory */, PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,            6u,          3u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: BCM23_oC03_for_EL_CAN_V2_1_38e01a3a_Rx_2c3755d1_Rx]        */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/BCM23_oC03_for_EL_CAN_V2_1_38e01a3a_Rx/PduRSrcPdu_2c3755d1, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/BCM23_oC03_for_EL_CAN_V2_1_38e01a3a_Rx/BCM23_oC03_for_EL_CAN_V2_1_38e01a3a_Rx_2c3755d1_Rx] */
  { /*     5 */                  0u  /* CommonSharedMemory */, PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           21u,         18u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: VCU3_oC03_for_EL_CAN_V2_1_5887a4da_Rx_2d386857_Rx]         */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/VCU3_oC03_for_EL_CAN_V2_1_5887a4da_Rx/PduRSrcPdu_2d386857, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/VCU3_oC03_for_EL_CAN_V2_1_5887a4da_Rx/VCU3_oC03_for_EL_CAN_V2_1_5887a4da_Rx_2d386857_Rx] */
  { /*     6 */                  0u  /* CommonSharedMemory */, PDUR_UNUSED_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,            2u,         23u, PDUR_TP_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: EIDC_Phy_Resp_oC03_for_EL_CAN_V2_1_0b15e5b1_Tx]            */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/EIDC_Phy_Resp_oC03_for_EL_CAN_V2_1_2f1664de_Tx/PduRSrcPdu_3a56b5c8, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/EIDC_Phy_Resp_oC03_for_EL_CAN_V2_1_2f1664de_Tx/EIDC_Phy_Resp_oC03_for_EL_CAN_V2_1_0b15e5b1_Tx] */
  { /*     7 */                  0u  /* CommonSharedMemory */, PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           12u,          9u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: HUT34_oC03_for_EL_CAN_V2_1_645b83e7_Rx_3a99a829_Rx]        */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/HUT34_oC03_for_EL_CAN_V2_1_645b83e7_Rx/PduRSrcPdu_3a99a829, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/HUT34_oC03_for_EL_CAN_V2_1_645b83e7_Rx/HUT34_oC03_for_EL_CAN_V2_1_645b83e7_Rx_3a99a829_Rx] */
  { /*     8 */                  0u  /* CommonSharedMemory */, PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,            5u,          2u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: BCM17_oC03_for_EL_CAN_V2_1_1cacdce3_Rx_4042d41e_Rx]        */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/BCM17_oC03_for_EL_CAN_V2_1_1cacdce3_Rx/PduRSrcPdu_4042d41e, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/BCM17_oC03_for_EL_CAN_V2_1_1cacdce3_Rx/BCM17_oC03_for_EL_CAN_V2_1_1cacdce3_Rx_4042d41e_Rx] */
  { /*     9 */                  0u  /* CommonSharedMemory */, PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,            4u,          1u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: BCM10_oC03_for_EL_CAN_V2_1_07870cd9_Rx_4466940f_Rx]        */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/BCM10_oC03_for_EL_CAN_V2_1_07870cd9_Rx/PduRSrcPdu_4466940f, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/BCM10_oC03_for_EL_CAN_V2_1_07870cd9_Rx/BCM10_oC03_for_EL_CAN_V2_1_07870cd9_Rx_4466940f_Rx] */
  { /*    10 */                  0u  /* CommonSharedMemory */, PDUR_UNUSED_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           24u,         21u, PDUR_TP_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: EIDC_Phy_Req_oC03_for_EL_CAN_V2_1_0af433a2_Rx_446e9331_Rx] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/EIDC_Phy_Req_oC03_for_EL_CAN_V2_1_0af433a2_Rx/PduRSrcPdu_446e9331, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/EIDC_Phy_Req_oC03_for_EL_CAN_V2_1_0af433a2_Rx/EIDC_Phy_Req_oC03_for_EL_CAN_V2_1_0af433a2_Rx_446e9331_Rx] */
  { /*    11 */                  0u  /* CommonSharedMemory */, PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           10u,          7u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: EEM1_oC03_for_EL_CAN_V2_1_0062b0bf_Rx_4a521786_Rx]         */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/EEM1_oC03_for_EL_CAN_V2_1_0062b0bf_Rx/PduRSrcPdu_4a521786, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/EEM1_oC03_for_EL_CAN_V2_1_0062b0bf_Rx/EEM1_oC03_for_EL_CAN_V2_1_0062b0bf_Rx_4a521786_Rx] */
  { /*    12 */                  0u  /* CommonSharedMemory */, PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,            8u,          4u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: BMS1_oC03_for_EL_CAN_V2_1_39195f27_Rx_6c53f7c1_Rx]         */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/BMS1_oC03_for_EL_CAN_V2_1_39195f27_Rx/PduRSrcPdu_6c53f7c1, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/BMS1_oC03_for_EL_CAN_V2_1_39195f27_Rx/BMS1_oC03_for_EL_CAN_V2_1_39195f27_Rx_6c53f7c1_Rx] */
  { /*    13 */                  0u  /* CommonSharedMemory */, PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           15u,         12u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: MCU_5_oC03_for_EL_CAN_V2_1_1cee0a50_Rx_6f17b236_Rx]        */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MCU_5_oC03_for_EL_CAN_V2_1_1cee0a50_Rx/PduRSrcPdu_6f17b236, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MCU_5_oC03_for_EL_CAN_V2_1_1cee0a50_Rx/MCU_5_oC03_for_EL_CAN_V2_1_1cee0a50_Rx_6f17b236_Rx] */
  { /*    14 */                  0u  /* CommonSharedMemory */, PDUR_UNUSED_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           23u,         20u, PDUR_TP_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: DiagFuncReq_oC03_for_EL_CAN_V2_1_ebce8a95_Rx_6f6e60a2_Rx]  */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/DiagFuncReq_oC03_for_EL_CAN_V2_1_ebce8a95_Rx/PduRSrcPdu_6f6e60a2, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/DiagFuncReq_oC03_for_EL_CAN_V2_1_ebce8a95_Rx/DiagFuncReq_oC03_for_EL_CAN_V2_1_ebce8a95_Rx_6f6e60a2_Rx] */
  { /*    15 */                  0u  /* CommonSharedMemory */, PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           20u,         17u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: VCU2_oC03_for_EL_CAN_V2_1_92b95749_Rx_81d0b539_Rx]         */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/VCU2_oC03_for_EL_CAN_V2_1_92b95749_Rx/PduRSrcPdu_81d0b539, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/VCU2_oC03_for_EL_CAN_V2_1_92b95749_Rx/VCU2_oC03_for_EL_CAN_V2_1_92b95749_Rx_81d0b539_Rx] */
  { /*    16 */                  0u  /* CommonSharedMemory */, PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,            9u,          6u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: CSA1_oC03_for_EL_CAN_V2_1_dc95e547_Rx_8a7ea6f5_Rx]         */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/CSA1_oC03_for_EL_CAN_V2_1_dc95e547_Rx/PduRSrcPdu_8a7ea6f5, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/CSA1_oC03_for_EL_CAN_V2_1_dc95e547_Rx/CSA1_oC03_for_EL_CAN_V2_1_dc95e547_Rx_8a7ea6f5_Rx] */
  { /*    17 */                  0u  /* CommonSharedMemory */, PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,            7u,          5u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: BMS17_oC03_for_EL_CAN_V2_1_099650be_Rx_980de097_Rx]        */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/BMS17_oC03_for_EL_CAN_V2_1_099650be_Rx/PduRSrcPdu_980de097, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/BMS17_oC03_for_EL_CAN_V2_1_099650be_Rx/BMS17_oC03_for_EL_CAN_V2_1_099650be_Rx_980de097_Rx] */
  { /*    18 */                  0u  /* CommonSharedMemory */, PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           16u,         13u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: OBC3_oC03_for_EL_CAN_V2_1_b52cba07_Rx_ab68ea3f_Rx]         */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/OBC3_oC03_for_EL_CAN_V2_1_b52cba07_Rx/PduRSrcPdu_ab68ea3f, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/OBC3_oC03_for_EL_CAN_V2_1_b52cba07_Rx/OBC3_oC03_for_EL_CAN_V2_1_b52cba07_Rx_ab68ea3f_Rx] */
  { /*    19 */                  0u  /* CommonSharedMemory */, PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           18u,         15u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: RMCU4_oC03_for_EL_CAN_V2_1_c01f5396_Rx_b1d6a3ac_Rx]        */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/RMCU4_oC03_for_EL_CAN_V2_1_c01f5396_Rx/PduRSrcPdu_b1d6a3ac, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/RMCU4_oC03_for_EL_CAN_V2_1_c01f5396_Rx/RMCU4_oC03_for_EL_CAN_V2_1_c01f5396_Rx_b1d6a3ac_Rx] */
  { /*    20 */                  0u  /* CommonSharedMemory */, PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           19u,         16u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: R_PBOX1_oC03_for_EL_CAN_V2_1_9e411673_Rx_b249ed83_Rx]      */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/R_PBOX1_oC03_for_EL_CAN_V2_1_9e411673_Rx/PduRSrcPdu_b249ed83, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/R_PBOX1_oC03_for_EL_CAN_V2_1_9e411673_Rx/R_PBOX1_oC03_for_EL_CAN_V2_1_9e411673_Rx_b249ed83_Rx] */
  { /*    21 */                  0u  /* CommonSharedMemory */, PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           22u,         19u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: VCU6_oC03_for_EL_CAN_V2_1_0ca09587_Rx_b7c754b1_Rx]         */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/VCU6_oC03_for_EL_CAN_V2_1_0ca09587_Rx/PduRSrcPdu_b7c754b1, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/VCU6_oC03_for_EL_CAN_V2_1_0ca09587_Rx/VCU6_oC03_for_EL_CAN_V2_1_0ca09587_Rx_b7c754b1_Rx] */
  { /*    22 */                  0u  /* CommonSharedMemory */, PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           11u,          8u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: GW1_oC03_for_EL_CAN_V2_1_c1342e70_Rx_bdde61e0_Rx]          */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/GW1_oC03_for_EL_CAN_V2_1_c1342e70_Rx/PduRSrcPdu_bdde61e0, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/GW1_oC03_for_EL_CAN_V2_1_c1342e70_Rx/GW1_oC03_for_EL_CAN_V2_1_c1342e70_Rx_bdde61e0_Rx] */
  { /*    23 */                  0u  /* CommonSharedMemory */, PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,            0u,         22u, PDUR_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: EIDC1_oC03_for_EL_CAN_V2_1_17d720dc_Tx]                    */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/EIDC1_oC03_for_EL_CAN_V2_1_4a10c7b4_Tx/PduRSrcPdu_e9672331, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/EIDC1_oC03_for_EL_CAN_V2_1_4a10c7b4_Tx/EIDC1_oC03_for_EL_CAN_V2_1_17d720dc_Tx] */
  { /*    24 */                  0u  /* CommonSharedMemory */, PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           14u,         11u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM }   /* [PduRDestPdu: IP2_oC03_for_EL_CAN_V2_1_1f94e7ab_Rx_f526491e_Rx]          */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/IP2_oC03_for_EL_CAN_V2_1_1f94e7ab_Rx/PduRSrcPdu_f526491e, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/IP2_oC03_for_EL_CAN_V2_1_1f94e7ab_Rx/IP2_oC03_for_EL_CAN_V2_1_1f94e7ab_Rx_f526491e_Rx] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_RmGDestRom
**********************************************************************************************************************/
/** 
  \var    PduR_RmGDestRom
  \brief  PduR RoutingPathManager global destPdu Table
  \details
  Element                Description
  DestHnd                handle to be used as parameter for the StartOfReception, CopyRxData, Transmit or RxIndication function call.
  Direction              Direction of this Pdu: Rx or Tx
  MaxPduLength           Configured PduLength + metadata length.
  MmRomIdx               the index of the 1:1 relation pointing to PduR_MmRom
  PartitionIndexOfCsl
  RmDestRomIdx           the index of the 1:1 relation pointing to PduR_RmDestRom
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(PduR_RmGDestRomType, PDUR_CONST) PduR_RmGDestRom[25] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    DestHnd                                                                          Direction                      MaxPduLength  MmRomIdx  PartitionIndexOfCsl                            RmDestRomIdx        Comment                                                                          Referable Keys */
  { /*     0 */                  CanIfConf_CanIfTxPduCfg_EIDC1_oC03_for_EL_CAN_V2_1_fd2fa739_Tx, PDUR_TX_DIRECTIONOFRMGDESTROM,           8u,       0u,                  0u  /* CommonSharedMemory */,          23u },  /* [Global PduRDestPdu: EIDC1_oC03_for_EL_CAN_V2_1_17d720dc_Tx]         */  /* [/ActiveEcuC/EcuC/EcucPduCollection/EIDC1_oC03_for_EL_CAN_V2_1_17d720dc_Tx, /ActiveEcuC/PduR/CanIf] */
  { /*     1 */                                 CanNmConf_CanNmUserDataTxPdu_CanNmUserDataTxPdu, PDUR_TX_DIRECTIONOFRMGDESTROM,           6u,       1u,                  0u  /* CommonSharedMemory */,           0u },  /* [Global PduRDestPdu: Pdu_Nm_userData_Tx]                             */  /* [/ActiveEcuC/EcuC/EcucPduCollection/Pdu_Nm_userData_Tx, /ActiveEcuC/PduR/CanNm] */
  { /*     2 */                                      CanTpConf_CanTpTxNSdu_CanTpTxNSdu_d9548202, PDUR_TX_DIRECTIONOFRMGDESTROM,           8u,       2u,                  0u  /* CommonSharedMemory */,           6u },  /* [Global PduRDestPdu: EIDC_Phy_Resp_oC03_for_EL_CAN_V2_1_0b15e5b1_Tx] */  /* [/ActiveEcuC/EcuC/EcucPduCollection/EIDC_Phy_Resp_oC03_for_EL_CAN_V2_1_0b15e5b1_Tx, /ActiveEcuC/PduR/CanTp] */
  { /*     3 */                           ComConf_ComIPdu_ABS3_oC03_for_EL_CAN_V2_1_5328da88_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,           8u,       3u,                  0u  /* CommonSharedMemory */,           1u },  /* [Global PduRDestPdu: ABS3_oC03_for_EL_CAN_V2_1_5328da88_Rx]          */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ABS3_oC03_for_EL_CAN_V2_1_5328da88_Rx, /ActiveEcuC/PduR/Com] */
  { /*     4 */                          ComConf_ComIPdu_BCM10_oC03_for_EL_CAN_V2_1_8175742c_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,           8u,       3u,                  0u  /* CommonSharedMemory */,           9u },  /* [Global PduRDestPdu: BCM10_oC03_for_EL_CAN_V2_1_8175742c_Rx]         */  /* [/ActiveEcuC/EcuC/EcucPduCollection/BCM10_oC03_for_EL_CAN_V2_1_8175742c_Rx, /ActiveEcuC/PduR/Com] */
  { /*     5 */                          ComConf_ComIPdu_BCM17_oC03_for_EL_CAN_V2_1_e4ac4a6c_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,           8u,       3u,                  0u  /* CommonSharedMemory */,           8u },  /* [Global PduRDestPdu: BCM17_oC03_for_EL_CAN_V2_1_e4ac4a6c_Rx]         */  /* [/ActiveEcuC/EcuC/EcucPduCollection/BCM17_oC03_for_EL_CAN_V2_1_e4ac4a6c_Rx, /ActiveEcuC/PduR/Com] */
  { /*     6 */                          ComConf_ComIPdu_BCM23_oC03_for_EL_CAN_V2_1_cee8e051_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,           8u,       3u,                  0u  /* CommonSharedMemory */,           4u },  /* [Global PduRDestPdu: BCM23_oC03_for_EL_CAN_V2_1_cee8e051_Rx]         */  /* [/ActiveEcuC/EcuC/EcucPduCollection/BCM23_oC03_for_EL_CAN_V2_1_cee8e051_Rx, /ActiveEcuC/PduR/Com] */
  { /*     7 */                          ComConf_ComIPdu_BMS17_oC03_for_EL_CAN_V2_1_be27a4ae_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,           8u,       3u,                  0u  /* CommonSharedMemory */,          17u },  /* [Global PduRDestPdu: BMS17_oC03_for_EL_CAN_V2_1_be27a4ae_Rx]         */  /* [/ActiveEcuC/EcuC/EcucPduCollection/BMS17_oC03_for_EL_CAN_V2_1_be27a4ae_Rx, /ActiveEcuC/PduR/Com] */
  { /*     8 */                           ComConf_ComIPdu_BMS1_oC03_for_EL_CAN_V2_1_ab80ae92_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,           8u,       3u,                  0u  /* CommonSharedMemory */,          12u },  /* [Global PduRDestPdu: BMS1_oC03_for_EL_CAN_V2_1_ab80ae92_Rx]          */  /* [/ActiveEcuC/EcuC/EcucPduCollection/BMS1_oC03_for_EL_CAN_V2_1_ab80ae92_Rx, /ActiveEcuC/PduR/Com] */
  { /*     9 */                           ComConf_ComIPdu_CSA1_oC03_for_EL_CAN_V2_1_ffb47aea_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,           8u,       3u,                  0u  /* CommonSharedMemory */,          16u },  /* [Global PduRDestPdu: CSA1_oC03_for_EL_CAN_V2_1_ffb47aea_Rx]          */  /* [/ActiveEcuC/EcuC/EcucPduCollection/CSA1_oC03_for_EL_CAN_V2_1_ffb47aea_Rx, /ActiveEcuC/PduR/Com] */
  { /*    10 */                           ComConf_ComIPdu_EEM1_oC03_for_EL_CAN_V2_1_5bdcd994_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,           8u,       3u,                  0u  /* CommonSharedMemory */,          11u },  /* [Global PduRDestPdu: EEM1_oC03_for_EL_CAN_V2_1_5bdcd994_Rx]          */  /* [/ActiveEcuC/EcuC/EcucPduCollection/EEM1_oC03_for_EL_CAN_V2_1_5bdcd994_Rx, /ActiveEcuC/PduR/Com] */
  { /*    11 */                            ComConf_ComIPdu_GW1_oC03_for_EL_CAN_V2_1_48654b76_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,           8u,       3u,                  0u  /* CommonSharedMemory */,          22u },  /* [Global PduRDestPdu: GW1_oC03_for_EL_CAN_V2_1_48654b76_Rx]           */  /* [/ActiveEcuC/EcuC/EcucPduCollection/GW1_oC03_for_EL_CAN_V2_1_48654b76_Rx, /ActiveEcuC/PduR/Com] */
  { /*    12 */                          ComConf_ComIPdu_HUT34_oC03_for_EL_CAN_V2_1_6fae3f7a_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,           8u,       3u,                  0u  /* CommonSharedMemory */,           7u },  /* [Global PduRDestPdu: HUT34_oC03_for_EL_CAN_V2_1_6fae3f7a_Rx]         */  /* [/ActiveEcuC/EcuC/EcucPduCollection/HUT34_oC03_for_EL_CAN_V2_1_6fae3f7a_Rx, /ActiveEcuC/PduR/Com] */
  { /*    13 */                          ComConf_ComIPdu_HUT54_oC03_for_EL_CAN_V2_1_82644d00_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,           8u,       3u,                  0u  /* CommonSharedMemory */,           3u },  /* [Global PduRDestPdu: HUT54_oC03_for_EL_CAN_V2_1_82644d00_Rx]         */  /* [/ActiveEcuC/EcuC/EcucPduCollection/HUT54_oC03_for_EL_CAN_V2_1_82644d00_Rx, /ActiveEcuC/PduR/Com] */
  { /*    14 */                            ComConf_ComIPdu_IP2_oC03_for_EL_CAN_V2_1_65941076_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,           8u,       3u,                  0u  /* CommonSharedMemory */,          24u },  /* [Global PduRDestPdu: IP2_oC03_for_EL_CAN_V2_1_65941076_Rx]           */  /* [/ActiveEcuC/EcuC/EcucPduCollection/IP2_oC03_for_EL_CAN_V2_1_65941076_Rx, /ActiveEcuC/PduR/Com] */
  { /*    15 */                          ComConf_ComIPdu_MCU_5_oC03_for_EL_CAN_V2_1_002cb201_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,           8u,       3u,                  0u  /* CommonSharedMemory */,          13u },  /* [Global PduRDestPdu: MCU_5_oC03_for_EL_CAN_V2_1_002cb201_Rx]         */  /* [/ActiveEcuC/EcuC/EcucPduCollection/MCU_5_oC03_for_EL_CAN_V2_1_002cb201_Rx, /ActiveEcuC/PduR/Com] */
  { /*    16 */                           ComConf_ComIPdu_OBC3_oC03_for_EL_CAN_V2_1_158aa3d5_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,           8u,       3u,                  0u  /* CommonSharedMemory */,          18u },  /* [Global PduRDestPdu: OBC3_oC03_for_EL_CAN_V2_1_158aa3d5_Rx]          */  /* [/ActiveEcuC/EcuC/EcucPduCollection/OBC3_oC03_for_EL_CAN_V2_1_158aa3d5_Rx, /ActiveEcuC/PduR/Com] */
  { /*    17 */                          ComConf_ComIPdu_PEPS2_oC03_for_EL_CAN_V2_1_d41abfa7_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,           8u,       3u,                  0u  /* CommonSharedMemory */,           2u },  /* [Global PduRDestPdu: PEPS2_oC03_for_EL_CAN_V2_1_d41abfa7_Rx]         */  /* [/ActiveEcuC/EcuC/EcucPduCollection/PEPS2_oC03_for_EL_CAN_V2_1_d41abfa7_Rx, /ActiveEcuC/PduR/Com] */
  { /*    18 */                          ComConf_ComIPdu_RMCU4_oC03_for_EL_CAN_V2_1_55159990_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,           8u,       3u,                  0u  /* CommonSharedMemory */,          19u },  /* [Global PduRDestPdu: RMCU4_oC03_for_EL_CAN_V2_1_55159990_Rx]         */  /* [/ActiveEcuC/EcuC/EcucPduCollection/RMCU4_oC03_for_EL_CAN_V2_1_55159990_Rx, /ActiveEcuC/PduR/Com] */
  { /*    19 */                        ComConf_ComIPdu_R_PBOX1_oC03_for_EL_CAN_V2_1_7854cc6e_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,           8u,       3u,                  0u  /* CommonSharedMemory */,          20u },  /* [Global PduRDestPdu: R_PBOX1_oC03_for_EL_CAN_V2_1_7854cc6e_Rx]       */  /* [/ActiveEcuC/EcuC/EcucPduCollection/R_PBOX1_oC03_for_EL_CAN_V2_1_7854cc6e_Rx, /ActiveEcuC/PduR/Com] */
  { /*    20 */                           ComConf_ComIPdu_VCU2_oC03_for_EL_CAN_V2_1_bea872d3_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,           8u,       3u,                  0u  /* CommonSharedMemory */,          15u },  /* [Global PduRDestPdu: VCU2_oC03_for_EL_CAN_V2_1_bea872d3_Rx]          */  /* [/ActiveEcuC/EcuC/EcucPduCollection/VCU2_oC03_for_EL_CAN_V2_1_bea872d3_Rx, /ActiveEcuC/PduR/Com] */
  { /*    21 */                           ComConf_ComIPdu_VCU3_oC03_for_EL_CAN_V2_1_a9801613_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,           8u,       3u,                  0u  /* CommonSharedMemory */,           5u },  /* [Global PduRDestPdu: VCU3_oC03_for_EL_CAN_V2_1_a9801613_Rx]          */  /* [/ActiveEcuC/EcuC/EcucPduCollection/VCU3_oC03_for_EL_CAN_V2_1_a9801613_Rx, /ActiveEcuC/PduR/Com] */
  { /*    22 */                           ComConf_ComIPdu_VCU6_oC03_for_EL_CAN_V2_1_e209e1d3_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,           8u,       3u,                  0u  /* CommonSharedMemory */,          21u },  /* [Global PduRDestPdu: VCU6_oC03_for_EL_CAN_V2_1_e209e1d3_Rx]          */  /* [/ActiveEcuC/EcuC/EcucPduCollection/VCU6_oC03_for_EL_CAN_V2_1_e209e1d3_Rx, /ActiveEcuC/PduR/Com] */
  { /*    23 */  DcmConf_DcmDslProtocolRx_DiagFuncReq_oC03_for_EL_CAN_V2_1_d3b22489_Rx_0e418c44, PDUR_RX_DIRECTIONOFRMGDESTROM,           7u,       4u,                  0u  /* CommonSharedMemory */,          14u },  /* [Global PduRDestPdu: DiagFuncReq_oC03_for_EL_CAN_V2_1_d3b22489_Rx]   */  /* [/ActiveEcuC/EcuC/EcucPduCollection/DiagFuncReq_oC03_for_EL_CAN_V2_1_d3b22489_Rx, /ActiveEcuC/PduR/Dcm] */
  { /*    24 */ DcmConf_DcmDslProtocolRx_EIDC_Phy_Req_oC03_for_EL_CAN_V2_1_4d7a4bf5_Rx_3b1e07c2, PDUR_RX_DIRECTIONOFRMGDESTROM,           8u,       4u,                  0u  /* CommonSharedMemory */,          10u }   /* [Global PduRDestPdu: EIDC_Phy_Req_oC03_for_EL_CAN_V2_1_4d7a4bf5_Rx]  */  /* [/ActiveEcuC/EcuC/EcucPduCollection/EIDC_Phy_Req_oC03_for_EL_CAN_V2_1_4d7a4bf5_Rx, /ActiveEcuC/PduR/Dcm] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_RmSrcRom
**********************************************************************************************************************/
/** 
  \var    PduR_RmSrcRom
  \brief  PduR RoutiongManager SrcPdu Table
  \details
  Element                Description
  MaskedBits             contains bitcoded the boolean data of PduR_TriggerTransmitSupportedOfRmSrcRom, PduR_TxConfirmationSupportedOfRmSrcRom
  MmRomIdx               the index of the 1:1 relation pointing to PduR_MmRom
  PartitionIndexOfCsl
  RmDestRomStartIdx      the start index of the 1:n relation pointing to PduR_RmDestRom
  SrcHnd                 handle to be used as parameter for the TxConfirmation or TriggerTransmit function call.
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(PduR_RmSrcRomType, PDUR_CONST) PduR_RmSrcRom[25] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    MaskedBits  MmRomIdx  PartitionIndexOfCsl                            RmDestRomStartIdx  SrcHnd                                                                                  Comment                                       Referable Keys */
  { /*     0 */      0x00u,       0u,                  0u  /* CommonSharedMemory */,                1u,                                                         PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_0334d61b] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ABS3_oC03_for_EL_CAN_V2_1_97a6dd96_Rx/PduRSrcPdu_0334d61b] */
  { /*     1 */      0x00u,       0u,                  0u  /* CommonSharedMemory */,                9u,                                                         PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_4466940f] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/BCM10_oC03_for_EL_CAN_V2_1_07870cd9_Rx/PduRSrcPdu_4466940f] */
  { /*     2 */      0x00u,       0u,                  0u  /* CommonSharedMemory */,                8u,                                                         PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_4042d41e] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/BCM17_oC03_for_EL_CAN_V2_1_1cacdce3_Rx/PduRSrcPdu_4042d41e] */
  { /*     3 */      0x00u,       0u,                  0u  /* CommonSharedMemory */,                4u,                                                         PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_2c3755d1] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/BCM23_oC03_for_EL_CAN_V2_1_38e01a3a_Rx/PduRSrcPdu_2c3755d1] */
  { /*     4 */      0x00u,       0u,                  0u  /* CommonSharedMemory */,               12u,                                                         PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_6c53f7c1] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/BMS1_oC03_for_EL_CAN_V2_1_39195f27_Rx/PduRSrcPdu_6c53f7c1] */
  { /*     5 */      0x00u,       0u,                  0u  /* CommonSharedMemory */,               17u,                                                         PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_980de097] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/BMS17_oC03_for_EL_CAN_V2_1_099650be_Rx/PduRSrcPdu_980de097] */
  { /*     6 */      0x00u,       0u,                  0u  /* CommonSharedMemory */,               16u,                                                         PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_8a7ea6f5] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/CSA1_oC03_for_EL_CAN_V2_1_dc95e547_Rx/PduRSrcPdu_8a7ea6f5] */
  { /*     7 */      0x00u,       0u,                  0u  /* CommonSharedMemory */,               11u,                                                         PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_4a521786] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/EEM1_oC03_for_EL_CAN_V2_1_0062b0bf_Rx/PduRSrcPdu_4a521786] */
  { /*     8 */      0x00u,       0u,                  0u  /* CommonSharedMemory */,               22u,                                                         PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_bdde61e0] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/GW1_oC03_for_EL_CAN_V2_1_c1342e70_Rx/PduRSrcPdu_bdde61e0] */
  { /*     9 */      0x00u,       0u,                  0u  /* CommonSharedMemory */,                7u,                                                         PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_3a99a829] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/HUT34_oC03_for_EL_CAN_V2_1_645b83e7_Rx/PduRSrcPdu_3a99a829] */
  { /*    10 */      0x00u,       0u,                  0u  /* CommonSharedMemory */,                3u,                                                         PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_248a65bc] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/HUT54_oC03_for_EL_CAN_V2_1_cb808d88_Rx/PduRSrcPdu_248a65bc] */
  { /*    11 */      0x00u,       0u,                  0u  /* CommonSharedMemory */,               24u,                                                         PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_f526491e] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/IP2_oC03_for_EL_CAN_V2_1_1f94e7ab_Rx/PduRSrcPdu_f526491e] */
  { /*    12 */      0x00u,       0u,                  0u  /* CommonSharedMemory */,               13u,                                                         PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_6f17b236] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MCU_5_oC03_for_EL_CAN_V2_1_1cee0a50_Rx/PduRSrcPdu_6f17b236] */
  { /*    13 */      0x00u,       0u,                  0u  /* CommonSharedMemory */,               18u,                                                         PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_ab68ea3f] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/OBC3_oC03_for_EL_CAN_V2_1_b52cba07_Rx/PduRSrcPdu_ab68ea3f] */
  { /*    14 */      0x00u,       0u,                  0u  /* CommonSharedMemory */,                2u,                                                         PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_189ccf5d] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/PEPS2_oC03_for_EL_CAN_V2_1_f4dd9817_Rx/PduRSrcPdu_189ccf5d] */
  { /*    15 */      0x00u,       0u,                  0u  /* CommonSharedMemory */,               19u,                                                         PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_b1d6a3ac] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/RMCU4_oC03_for_EL_CAN_V2_1_c01f5396_Rx/PduRSrcPdu_b1d6a3ac] */
  { /*    16 */      0x00u,       0u,                  0u  /* CommonSharedMemory */,               20u,                                                         PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_b249ed83] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/R_PBOX1_oC03_for_EL_CAN_V2_1_9e411673_Rx/PduRSrcPdu_b249ed83] */
  { /*    17 */      0x00u,       0u,                  0u  /* CommonSharedMemory */,               15u,                                                         PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_81d0b539] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/VCU2_oC03_for_EL_CAN_V2_1_92b95749_Rx/PduRSrcPdu_81d0b539] */
  { /*    18 */      0x00u,       0u,                  0u  /* CommonSharedMemory */,                5u,                                                         PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_2d386857] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/VCU3_oC03_for_EL_CAN_V2_1_5887a4da_Rx/PduRSrcPdu_2d386857] */
  { /*    19 */      0x00u,       0u,                  0u  /* CommonSharedMemory */,               21u,                                                         PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_b7c754b1] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/VCU6_oC03_for_EL_CAN_V2_1_0ca09587_Rx/PduRSrcPdu_b7c754b1] */
  { /*    20 */      0x00u,       2u,                  0u  /* CommonSharedMemory */,               14u,                                                         PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_6f6e60a2] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/DiagFuncReq_oC03_for_EL_CAN_V2_1_ebce8a95_Rx/PduRSrcPdu_6f6e60a2] */
  { /*    21 */      0x00u,       2u,                  0u  /* CommonSharedMemory */,               10u,                                                         PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_446e9331] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/EIDC_Phy_Req_oC03_for_EL_CAN_V2_1_0af433a2_Rx/PduRSrcPdu_446e9331] */
  { /*    22 */      0x01u,       3u,                  0u  /* CommonSharedMemory */,               23u,                           ComConf_ComIPdu_EIDC1_oC03_for_EL_CAN_V2_1_4a10c7b4_Tx },  /* [PduRSrcPdu: PduRSrcPdu_e9672331] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/EIDC1_oC03_for_EL_CAN_V2_1_4a10c7b4_Tx/PduRSrcPdu_e9672331] */
  { /*    23 */      0x00u,       4u,                  0u  /* CommonSharedMemory */,                6u, DcmConf_DcmDslProtocolTx_EIDC_Phy_Resp_oC03_for_EL_CAN_V2_1_2f1664de_Tx_229d1f3a },  /* [PduRSrcPdu: PduRSrcPdu_3a56b5c8] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/EIDC_Phy_Resp_oC03_for_EL_CAN_V2_1_2f1664de_Tx/PduRSrcPdu_3a56b5c8] */
  { /*    24 */      0x02u,       3u,                  0u  /* CommonSharedMemory */,                0u,                                              ComConf_ComIPdu_ComIPdu_userData_tx }   /* [PduRSrcPdu: PduRSrcPdu]          */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/PduRRoutingPath_userdata_tx/PduRSrcPdu] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_RmTransmitFctPtr
**********************************************************************************************************************/
/** 
  \var    PduR_RmTransmitFctPtr
  \brief  Internal routing manager Transmit functions.
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(PduR_RmTransmitFctPtrType, PDUR_CONST) PduR_RmTransmitFctPtr[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     RmTransmitFctPtr                  Referable Keys */
  /*     0 */ PduR_RmIf_RoutePdu           ,  /* [PduR_RmIf_RoutePdu] */
  /*     1 */ PduR_RmTp_Transmit_MultiDest    /* [PduR_RmTp_Transmit_MultiDest] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_RxIf2Dest
**********************************************************************************************************************/
/** 
  \var    PduR_RxIf2Dest
  \brief  This table contains all routing information to perform the Rx handling of an interface routing. Used in the &lt;LLIf&gt;_RxIndication
  \details
  Element                Description
  PartitionIndexOfCsl
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(PduR_RxIf2DestType, PDUR_CONST) PduR_RxIf2Dest[20] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PartitionIndexOfCsl                                  Referable Keys */
  { /*     0 */                  0u  /* CommonSharedMemory */ },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ABS3_oC03_for_EL_CAN_V2_1_97a6dd96_Rx/PduRSrcPdu_0334d61b] */
  { /*     1 */                  0u  /* CommonSharedMemory */ },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/BCM10_oC03_for_EL_CAN_V2_1_07870cd9_Rx/PduRSrcPdu_4466940f] */
  { /*     2 */                  0u  /* CommonSharedMemory */ },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/BCM17_oC03_for_EL_CAN_V2_1_1cacdce3_Rx/PduRSrcPdu_4042d41e] */
  { /*     3 */                  0u  /* CommonSharedMemory */ },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/BCM23_oC03_for_EL_CAN_V2_1_38e01a3a_Rx/PduRSrcPdu_2c3755d1] */
  { /*     4 */                  0u  /* CommonSharedMemory */ },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/BMS1_oC03_for_EL_CAN_V2_1_39195f27_Rx/PduRSrcPdu_6c53f7c1] */
  { /*     5 */                  0u  /* CommonSharedMemory */ },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/BMS17_oC03_for_EL_CAN_V2_1_099650be_Rx/PduRSrcPdu_980de097] */
  { /*     6 */                  0u  /* CommonSharedMemory */ },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/CSA1_oC03_for_EL_CAN_V2_1_dc95e547_Rx/PduRSrcPdu_8a7ea6f5] */
  { /*     7 */                  0u  /* CommonSharedMemory */ },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/EEM1_oC03_for_EL_CAN_V2_1_0062b0bf_Rx/PduRSrcPdu_4a521786] */
  { /*     8 */                  0u  /* CommonSharedMemory */ },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/GW1_oC03_for_EL_CAN_V2_1_c1342e70_Rx/PduRSrcPdu_bdde61e0] */
  { /*     9 */                  0u  /* CommonSharedMemory */ },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/HUT34_oC03_for_EL_CAN_V2_1_645b83e7_Rx/PduRSrcPdu_3a99a829] */
  { /*    10 */                  0u  /* CommonSharedMemory */ },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/HUT54_oC03_for_EL_CAN_V2_1_cb808d88_Rx/PduRSrcPdu_248a65bc] */
  { /*    11 */                  0u  /* CommonSharedMemory */ },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/IP2_oC03_for_EL_CAN_V2_1_1f94e7ab_Rx/PduRSrcPdu_f526491e] */
  { /*    12 */                  0u  /* CommonSharedMemory */ },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MCU_5_oC03_for_EL_CAN_V2_1_1cee0a50_Rx/PduRSrcPdu_6f17b236] */
  { /*    13 */                  0u  /* CommonSharedMemory */ },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/OBC3_oC03_for_EL_CAN_V2_1_b52cba07_Rx/PduRSrcPdu_ab68ea3f] */
  { /*    14 */                  0u  /* CommonSharedMemory */ },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/PEPS2_oC03_for_EL_CAN_V2_1_f4dd9817_Rx/PduRSrcPdu_189ccf5d] */
  { /*    15 */                  0u  /* CommonSharedMemory */ },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/RMCU4_oC03_for_EL_CAN_V2_1_c01f5396_Rx/PduRSrcPdu_b1d6a3ac] */
  { /*    16 */                  0u  /* CommonSharedMemory */ },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/R_PBOX1_oC03_for_EL_CAN_V2_1_9e411673_Rx/PduRSrcPdu_b249ed83] */
  { /*    17 */                  0u  /* CommonSharedMemory */ },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/VCU2_oC03_for_EL_CAN_V2_1_92b95749_Rx/PduRSrcPdu_81d0b539] */
  { /*    18 */                  0u  /* CommonSharedMemory */ },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/VCU3_oC03_for_EL_CAN_V2_1_5887a4da_Rx/PduRSrcPdu_2d386857] */
  { /*    19 */                  0u  /* CommonSharedMemory */ }   /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/VCU6_oC03_for_EL_CAN_V2_1_0ca09587_Rx/PduRSrcPdu_b7c754b1] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_RxTp2Dest
**********************************************************************************************************************/
/** 
  \var    PduR_RxTp2Dest
  \brief  This table contains all routing information to perform the Rx handling of a Tp Routing. Used in the PduR_&lt;LLTp&gt;_StartOfReception, PduR_&lt;LLTp&gt;_CopyRxData and PduR_&lt;LLTp&gt;_RxIndication.
  \details
  Element                Description
  PartitionIndexOfCsl
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(PduR_RxTp2DestType, PDUR_CONST) PduR_RxTp2Dest[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PartitionIndexOfCsl                                  Referable Keys */
  { /*     0 */                  0u  /* CommonSharedMemory */ },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/DiagFuncReq_oC03_for_EL_CAN_V2_1_ebce8a95_Rx/PduRSrcPdu_6f6e60a2] */
  { /*     1 */                  0u  /* CommonSharedMemory */ }   /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/EIDC_Phy_Req_oC03_for_EL_CAN_V2_1_0af433a2_Rx/PduRSrcPdu_446e9331] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_Tx2Lo
**********************************************************************************************************************/
/** 
  \var    PduR_Tx2Lo
  \brief  Contains all information to route a Pdu from a upper layer to a lower layer module, or to cancel a transmission
  \details
  Element                Description
  PartitionIndexOfCsl
  RmTransmitFctPtrIdx    the index of the 1:1 relation pointing to PduR_RmTransmitFctPtr
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(PduR_Tx2LoType, PDUR_CONST) PduR_Tx2Lo[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PartitionIndexOfCsl                            RmTransmitFctPtrIdx        Referable Keys */
  { /*     0 */                  0u  /* CommonSharedMemory */,                  0u },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/EIDC1_oC03_for_EL_CAN_V2_1_4a10c7b4_Tx/PduRSrcPdu_e9672331] */
  { /*     1 */                  0u  /* CommonSharedMemory */,                  1u },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/EIDC_Phy_Resp_oC03_for_EL_CAN_V2_1_2f1664de_Tx/PduRSrcPdu_3a56b5c8] */
  { /*     2 */                  0u  /* CommonSharedMemory */,                  0u }   /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/PduRRoutingPath_userdata_tx/PduRSrcPdu] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_TxIf2Up
**********************************************************************************************************************/
/** 
  \var    PduR_TxIf2Up
  \brief  This table contains all routing information to perform the Tx handling of an interface routing. Used in the &lt;LLIf&gt;_TriggerTransmit and &lt;LLIf&gt;_TxConfirmation
  \details
  Element                Description
  TxConfirmationUsed     True, if any of the source PduRDestPdus uses a TxConfirmation.
  PartitionIndexOfCsl
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(PduR_TxIf2UpType, PDUR_CONST) PduR_TxIf2Up[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    TxConfirmationUsed  PartitionIndexOfCsl                                  Referable Keys */
  { /*     0 */               TRUE,                  0u  /* CommonSharedMemory */ },  /* [/ActiveEcuC/EcuC/EcucPduCollection/EIDC1_oC03_for_EL_CAN_V2_1_17d720dc_Tx] */
  { /*     1 */              FALSE,                  0u  /* CommonSharedMemory */ }   /* [/ActiveEcuC/EcuC/EcucPduCollection/Pdu_Nm_userData_Tx] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_Initialized
**********************************************************************************************************************/
/** 
  \var    PduR_Initialized
  \brief  Initialization state of PduR. TRUE, if PduR_Init() has been called, else FALSE
*/ 
#define PDUR_START_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(PduR_InitializedType, PDUR_VAR_ZERO_INIT) PduR_Initialized = FALSE;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define PDUR_STOP_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_PCPartitionConfig
**********************************************************************************************************************/
/** 
  \var    PduR_PCPartitionConfig
  \details
  Element        Description
  Initialized    the pointer to PduR_Initialized
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(PduR_PCPartitionConfigType, PDUR_CONST) PduR_PCPartitionConfig[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [] */
      (&(PduR_Initialized))  /**< the pointer to PduR_Initialized */
  }
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/


#define PDUR_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "PduR_MemMap.h"    /* PRQA S 5087 */        /* MD_MSR_MemMap */

#if(PDUR_USE_INIT_POINTER == STD_ON)
P2CONST(PduR_PBConfigType, PDUR_VAR_ZERO_INIT, PDUR_PBCFG) PduR_ConfigDataPtr = (const PduR_PBConfigType *) NULL_PTR;
#endif

#define PDUR_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "PduR_MemMap.h"    /* PRQA S 5087 */        /* MD_MSR_MemMap */

#define PDUR_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "PduR_MemMap.h"    /* PRQA S 5087 */        /* MD_MSR_MemMap */

VAR(boolean, PDUR_VAR_NOINIT) PduR_PreInitialized;

#define PDUR_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "PduR_MemMap.h"    /* PRQA S 5087 */        /* MD_MSR_MemMap */
  
/**********************************************************************************************************************
 * LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTIONS
**********************************************************************************************************************/
#define PDUR_START_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "PduR_MemMap.h"

/* Exclusive Area Wrapper functions */

/**********************************************************************************************************************
 * PduR_SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0
 *********************************************************************************************************************/
/*!
 * \internal
 * -  enter the EA  
 * \endinternal
 *********************************************************************************************************************/
static FUNC(void, PDUR_CODE) PduR_SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0(void)
{
  SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
}


/**********************************************************************************************************************
 * PduR_SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0
 *********************************************************************************************************************/
/*!
 * \internal
 * -  exit the EA  
 * \endinternal
 *********************************************************************************************************************/
static FUNC(void, PDUR_CODE) PduR_SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0(void)
{
  SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
}


/* Upper Layer Interface APIs */

/**********************************************************************************************************************
 * PduR_ComTransmit
 *********************************************************************************************************************/
/*!
 * \internal
 * - call upper layer Transmit function. 
 * \endinternal
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_ComTransmit(PduIdType id, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info) /* COV_PDUR_WRAPPER_FUNC */
{
  Std_ReturnType retVal = E_NOT_OK;        /* PRQA S 2981 */ /* MD_MSR_RetVal */
  
#if (PDUR_TX2LO == STD_ON) /* COV_PDUR_RX_OR_TX_ONLY_CONFIG */
  retVal = PduR_UpTransmit(id, info); /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ONLY */
#else
  PduR_Det_ReportError(PDUR_FCT_TX, PDUR_E_PDU_ID_INVALID);
#endif

  PDUR_DUMMY_STATEMENT(id);     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(info);   /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */

  return retVal;
}


/**********************************************************************************************************************
 * PduR_DcmTransmit
 *********************************************************************************************************************/
/*!
 * \internal
 * - call upper layer Transmit function. 
 * \endinternal
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_DcmTransmit(PduIdType id, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info) /* COV_PDUR_WRAPPER_FUNC */
{
  Std_ReturnType retVal = E_NOT_OK;        /* PRQA S 2981 */ /* MD_MSR_RetVal */
  
#if (PDUR_TX2LO == STD_ON) /* COV_PDUR_RX_OR_TX_ONLY_CONFIG */
  retVal = PduR_UpTransmit(id, info); /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ONLY */
#else
  PduR_Det_ReportError(PDUR_FCT_TX, PDUR_E_PDU_ID_INVALID);
#endif

  PDUR_DUMMY_STATEMENT(id);     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(info);   /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */

  return retVal;
}


/* Communication Interface APIs */

/**********************************************************************************************************************
 * PduR_CanIfRxIndication
 *********************************************************************************************************************/
/*!
 * \internal
 * -  call internal general IfRxIndication function.  
 * \endinternal
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_CanIfRxIndication(PduIdType RxPduId, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info) /* COV_PDUR_WRAPPER_FUNC */
{
#if (PDUR_RXIF2DEST == STD_ON) /* COV_PDUR_RX_OR_TX_ONLY_CONFIG */
  PduR_LoIfRxIndication(RxPduId, info);  /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ONLY */
#else
  PduR_Det_ReportError(PDUR_FCT_IFRXIND, PDUR_E_PDU_ID_INVALID);
#endif
  PDUR_DUMMY_STATEMENT(RxPduId);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(info);   		/* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}


/**********************************************************************************************************************
 * PduR_CanIfTxConfirmation
 *********************************************************************************************************************/
/*!
 * \internal
 * - call internal general communication interface TxConfirmation function.
 * \endinternal
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_CanIfTxConfirmation(PduIdType TxPduId) /* COV_PDUR_WRAPPER_FUNC */
{
#if (PDUR_TXCONFIRMATIONUSEDOFTXIF2UP == STD_ON)
  PduR_LoIfTxConfirmation(TxPduId);
#endif
  PDUR_DUMMY_STATEMENT(TxPduId);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}



/**********************************************************************************************************************
 * PduR_CanNmRxIndication
 *********************************************************************************************************************/
/*!
 * \internal
 * -  call internal general IfRxIndication function.  
 * \endinternal
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_CanNmRxIndication(PduIdType RxPduId, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info) /* COV_PDUR_WRAPPER_FUNC */
{
#if (PDUR_RXIF2DEST == STD_ON) /* COV_PDUR_RX_OR_TX_ONLY_CONFIG */
  PduR_LoIfRxIndication(RxPduId, info);  /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ONLY */
#else
  PduR_Det_ReportError(PDUR_FCT_IFRXIND, PDUR_E_PDU_ID_INVALID);
#endif
  PDUR_DUMMY_STATEMENT(RxPduId);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(info);   		/* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}



/**********************************************************************************************************************
 * PduR_CanNmTriggerTransmit
 *********************************************************************************************************************/
/*!
 * \internal
 * - call internal general TriggerTransmit function.  
 * \endinternal
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_CanNmTriggerTransmit(PduIdType TxPduId, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info)
{
  return PduR_LoIfTriggerTransmit(TxPduId, info); /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ONLY */
}


/* Transport Protocol APIs */

/**********************************************************************************************************************
 * PduR_CanTpStartOfReception
 *********************************************************************************************************************/
 /*!
 * \internal
 * - call transport protocoll StartOfReception function.  
 * \endinternal
 *********************************************************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_CanTpStartOfReception(PduIdType id, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info, PduLengthType TpSduLength, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr) /* COV_PDUR_WRAPPER_FUNC */
{
  BufReq_ReturnType retVal = BUFREQ_E_NOT_OK;        /* PRQA S 2981 */ /* MD_MSR_RetVal */

#if (PDUR_RXTP2DEST == STD_ON) /* COV_PDUR_RX_OR_TX_ONLY_CONFIG */
  retVal = PduR_LoTpStartOfReception(id, info, TpSduLength, bufferSizePtr); /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ONLY */
#else
  PduR_Det_ReportError(PDUR_FCT_SOR, PDUR_E_PDU_ID_INVALID);
#endif

  PDUR_DUMMY_STATEMENT(id);     		/* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(info);   		/* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(TpSduLength);    /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(bufferSizePtr);  /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */

  return retVal;
}


/**********************************************************************************************************************
 * PduR_CanTpCopyRxData
 *********************************************************************************************************************/
/*!
 * \internal
 * - call internal general CopyRxData.
 * \endinternal
 *********************************************************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_CanTpCopyRxData(PduIdType id, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr) /* COV_PDUR_WRAPPER_FUNC */
{
  BufReq_ReturnType retVal = BUFREQ_E_NOT_OK;        /* PRQA S 2981 */ /* MD_MSR_RetVal */
  
#if (PDUR_RXTP2DEST == STD_ON) /* COV_PDUR_RX_OR_TX_ONLY_CONFIG */
  retVal = PduR_LoTpCopyRxData(id, info, bufferSizePtr); /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ONLY */
#else
  PduR_Det_ReportError(PDUR_FCT_CPYRX, PDUR_E_PDU_ID_INVALID);
#endif

  PDUR_DUMMY_STATEMENT(id);     		/* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(info);  			/* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(bufferSizePtr);  /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  
  return retVal;
}


/**********************************************************************************************************************
 * PduR_CanTpCopyTxData
 *********************************************************************************************************************/
/*!
 * \internal
 * - call internal general CopyTxData.
 * \endinternal
 *********************************************************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_CanTpCopyTxData(PduIdType id, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info, P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr) /* COV_PDUR_WRAPPER_FUNC */
{
  BufReq_ReturnType retVal = BUFREQ_E_NOT_OK;        /* PRQA S 2981 */ /* MD_MSR_RetVal */
  
#if(PDUR_TXTP2SRC == STD_ON) /* COV_PDUR_RX_OR_TX_ONLY_CONFIG */
  retVal = PduR_LoTpCopyTxData(id, info, retry, availableDataPtr); /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ONLY */
#else
  PduR_Det_ReportError(PDUR_FCT_CPYTX, PDUR_E_PDU_ID_INVALID);
#endif

  PDUR_DUMMY_STATEMENT(id);     				/* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(info);  					/* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(retry);  				/* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(availableDataPtr);       /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  
  return retVal;
}


/**********************************************************************************************************************
 * PduR_CanTpRxIndication
 *********************************************************************************************************************/
/*!
 * \internal
 * - call Tp RxIndication function.
 * \endinternal
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_CanTpRxIndication(PduIdType id, Std_ReturnType result) /* COV_PDUR_WRAPPER_FUNC */
{
#if (PDUR_RXTP2DEST == STD_ON) /* COV_PDUR_RX_OR_TX_ONLY_CONFIG */
  PduR_LoTpRxIndication(id, result);
#else
  PduR_Det_ReportError(PDUR_FCT_TPRXIND, PDUR_E_PDU_ID_INVALID);
#endif

  PDUR_DUMMY_STATEMENT(id);     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(result); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}


/**********************************************************************************************************************
 * PduR_CanTpTxConfirmation
 *********************************************************************************************************************/
/*!
 * \internal
 * - call Tp TxConfirmation function 
 * \endinternal
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_CanTpTxConfirmation(PduIdType id, Std_ReturnType result) /* COV_PDUR_WRAPPER_FUNC */
{
#if (PDUR_TXTP2SRC == STD_ON) /* COV_PDUR_RX_OR_TX_ONLY_CONFIG */
  PduR_LoTpTxConfirmation(id, result);
#else
  PduR_Det_ReportError(PDUR_FCT_TPTXCFM, PDUR_E_PDU_ID_INVALID);
#endif

  PDUR_DUMMY_STATEMENT(id);     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(result); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}


/* CancelReceive global without UseTag API */

/* ChangeParameter global without UseTag  API */

/* Communication Interface / Transport Protocol APIs */

/* Communication Interface / Transport Protocol APIs */

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/


#define PDUR_STOP_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "PduR_MemMap.h"

/* SBSW_JUSTIFICATION_BEGIN

  \ID SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ID_AND_PTR
    \DESCRIPTION    The API is called with an Id and a pointer.
                    The API call is forwarded using a function pointer which is read using ComStackLib macros.
                    
    \COUNTERMEASURE \N The function pointer is read using the passed Id (and ComStackLib macros). 
                       The Id is a SNV provided by the lower layer. 
                       It is checked at runtime if it is in the valid range.
                       The pointer is provided by the lower layer and is assumed to be valid. It is passed as is to the corresponding function. 

  \ID SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ID_ONLY
    \DESCRIPTION    The API is called with an Id.
                    The API call is forwarded using a function pointer which is read using ComStackLib macros.
                    
    \COUNTERMEASURE \R The function pointer is read using the passed Id (and ComStackLib macros). 
                       The Id is a SNV provided by the lower layer. 
                       It is checked at runtime if it is in the valid range.
                       
  \ID SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ONLY
    \DESCRIPTION    The API call is forwarded to an internal function.
    \COUNTERMEASURE \N The parameter are checked in the called function.

 SBSW_JUSTIFICATION_END */
 
 /* COV_JUSTIFICATION_BEGIN
 
  \ID COV_PDUR_WRAPPER_FUNC
    \ACCEPT X
    \REASON Each neighbouring module call the same internal function. The call is covered by an other module. 
    
  \ID COV_PDUR_RX_OR_TX_ONLY_CONFIG
    \ACCEPT TX
    \REASON The API is mandatory if this Bsw module exists. In case of Rx or Tx only configs the API call is not forwarded to the internal function. 
 
 COV_JUSTIFICATION_END */
 

/**********************************************************************************************************************
 * END OF FILE: PduR_Lcfg.c
 *********************************************************************************************************************/

