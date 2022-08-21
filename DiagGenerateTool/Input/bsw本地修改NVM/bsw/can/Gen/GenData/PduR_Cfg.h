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
 *              File: PduR_Cfg.h
 *   Generation Time: 2022-07-21 09:21:31
 *           Project: C03 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.24
 *
 *
 *********************************************************************************************************************/

#if !defined (PDUR_CFG_H)
# define PDUR_CFG_H

/**********************************************************************************************************************
 * MISRA JUSTIFICATION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "PduR_Types.h"

/**********************************************************************************************************************
 * GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#ifndef PDUR_USE_DUMMY_STATEMENT
#define PDUR_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef PDUR_DUMMY_STATEMENT
#define PDUR_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef PDUR_DUMMY_STATEMENT_CONST
#define PDUR_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef PDUR_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define PDUR_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef PDUR_ATOMIC_VARIABLE_ACCESS
#define PDUR_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef PDUR_PROCESSOR_RH850_1651
#define PDUR_PROCESSOR_RH850_1651
#endif
#ifndef PDUR_COMP_GREENHILLS
#define PDUR_COMP_GREENHILLS
#endif
#ifndef PDUR_GEN_GENERATOR_MSR
#define PDUR_GEN_GENERATOR_MSR
#endif
#ifndef PDUR_CPUTYPE_BITORDER_LSB2MSB
#define PDUR_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef PDUR_CONFIGURATION_VARIANT_PRECOMPILE
#define PDUR_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef PDUR_CONFIGURATION_VARIANT_LINKTIME
#define PDUR_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef PDUR_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define PDUR_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef PDUR_CONFIGURATION_VARIANT
#define PDUR_CONFIGURATION_VARIANT PDUR_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef PDUR_POSTBUILD_VARIANT_SUPPORT
#define PDUR_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif



#define PDUR_DEV_ERROR_DETECT STD_OFF  /**< /ActiveEcuC/PduR/PduRGeneral[0:PduRSafeBswChecks] || /ActiveEcuC/PduR/PduRGeneral[0:PduRDevErrorDetect] */
#define PDUR_DEV_ERROR_REPORT STD_OFF  /**< /ActiveEcuC/PduR/PduRGeneral[0:PduRDevErrorDetect] */

#define PDUR_EXTENDED_ERROR_CHECKS STD_OFF  /**< /ActiveEcuC/PduR/PduRGeneral[0:PduRExtendedErrorChecks] */

#define PDUR_METADATA_SUPPORT STD_OFF  /**< /ActiveEcuC/PduR/PduRGeneral[0:PduRMetaDataSupport] */
#define PDUR_VERSION_INFO_API STD_OFF  /**< /ActiveEcuC/PduR/PduRGeneral[0:PduRVersionInfoApi] */

#define PDUR_ERROR_NOTIFICATION STD_OFF

#define PDUR_MAIN_FUNCTION STD_OFF

#define PDUR_MULTICORE STD_OFF /**< /ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] */

#define PduR_PBConfigIdType uint32

 
 /*  DET Error define list  */ 
#define PDUR_FCT_CANIFRXIND 0x01u 
#define PDUR_FCT_CANIFTX 0x09u 
#define PDUR_FCT_CANIFTXCFM 0x02u 
#define PDUR_FCT_CANTPRXIND 0x05u 
#define PDUR_FCT_CANTPTX 0x09u 
#define PDUR_FCT_CANTPTXCFM 0x08u 
#define PDUR_FCT_CANTPSOR 0x06u 
#define PDUR_FCT_CANTPCPYRX 0x04u 
#define PDUR_FCT_CANTPCPYTX 0x07u 
#define PDUR_FCT_COMTX 0x89u 
#define PDUR_FCT_DCMTX 0x99u 
#define PDUR_FCT_CANNMRXIND 0x11u 
#define PDUR_FCT_CANNMTX 0x19u 
#define PDUR_FCT_CANNMTXCFM 0x12u 
#define PDUR_FCT_CANNMTT 0x13u 
 /*   PduR_CanIfIfRxIndication  PduR_CanIfTransmit  PduR_CanIfTxConfirmation  PduR_CanTpTpRxIndication  PduR_CanTpTransmit  PduR_CanTpTxConfirmation  PduR_CanTpStartOfReception  PduR_CanTpCopyRxData  PduR_CanTpCopyTxData  PduR_ComTransmit  PduR_DcmTransmit  PduR_CanNmIfRxIndication  PduR_CanNmTransmit  PduR_CanNmTxConfirmation  PduR_CanNmTriggerTransmit  */ 



/**
 * \defgroup PduRHandleIdsIfRxDest Handle IDs of handle space IfRxDest.
 * \brief Communication interface Rx destination PDUs
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRDestPdu_ABS3_oC03_for_EL_CAN_V2_1_97a6dd96_Rx_0334d61b_Rx 0u
#define PduRConf_PduRDestPdu_BCM10_oC03_for_EL_CAN_V2_1_07870cd9_Rx_4466940f_Rx 1u
#define PduRConf_PduRDestPdu_BCM17_oC03_for_EL_CAN_V2_1_1cacdce3_Rx_4042d41e_Rx 2u
#define PduRConf_PduRDestPdu_BCM23_oC03_for_EL_CAN_V2_1_38e01a3a_Rx_2c3755d1_Rx 3u
#define PduRConf_PduRDestPdu_BMS1_oC03_for_EL_CAN_V2_1_39195f27_Rx_6c53f7c1_Rx 4u
#define PduRConf_PduRDestPdu_BMS17_oC03_for_EL_CAN_V2_1_099650be_Rx_980de097_Rx 5u
#define PduRConf_PduRDestPdu_CSA1_oC03_for_EL_CAN_V2_1_dc95e547_Rx_8a7ea6f5_Rx 6u
#define PduRConf_PduRDestPdu_EEM1_oC03_for_EL_CAN_V2_1_0062b0bf_Rx_4a521786_Rx 7u
#define PduRConf_PduRDestPdu_GW1_oC03_for_EL_CAN_V2_1_c1342e70_Rx_bdde61e0_Rx 8u
#define PduRConf_PduRDestPdu_HUT34_oC03_for_EL_CAN_V2_1_645b83e7_Rx_3a99a829_Rx 9u
#define PduRConf_PduRDestPdu_HUT54_oC03_for_EL_CAN_V2_1_cb808d88_Rx_248a65bc_Rx 10u
#define PduRConf_PduRDestPdu_IP2_oC03_for_EL_CAN_V2_1_1f94e7ab_Rx_f526491e_Rx 11u
#define PduRConf_PduRDestPdu_MCU_5_oC03_for_EL_CAN_V2_1_1cee0a50_Rx_6f17b236_Rx 12u
#define PduRConf_PduRDestPdu_OBC3_oC03_for_EL_CAN_V2_1_b52cba07_Rx_ab68ea3f_Rx 13u
#define PduRConf_PduRDestPdu_PEPS2_oC03_for_EL_CAN_V2_1_f4dd9817_Rx_189ccf5d_Rx 14u
#define PduRConf_PduRDestPdu_RMCU4_oC03_for_EL_CAN_V2_1_c01f5396_Rx_b1d6a3ac_Rx 15u
#define PduRConf_PduRDestPdu_R_PBOX1_oC03_for_EL_CAN_V2_1_9e411673_Rx_b249ed83_Rx 16u
#define PduRConf_PduRDestPdu_VCU2_oC03_for_EL_CAN_V2_1_92b95749_Rx_81d0b539_Rx 17u
#define PduRConf_PduRDestPdu_VCU3_oC03_for_EL_CAN_V2_1_5887a4da_Rx_2d386857_Rx 18u
#define PduRConf_PduRDestPdu_VCU6_oC03_for_EL_CAN_V2_1_0ca09587_Rx_b7c754b1_Rx 19u
/**\} */

/**
 * \defgroup PduRHandleIdsIfRxSrc Handle IDs of handle space IfRxSrc.
 * \brief Communication interface Rx source PDUs
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_2c3755d1                       3u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_2d386857                       18u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_3a99a829                       9u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_4a521786                       7u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_6c53f7c1                       4u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_6f17b236                       12u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_8a7ea6f5                       6u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_81d0b539                       17u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_189ccf5d                       14u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_248a65bc                       10u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_980de097                       5u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_0334d61b                       0u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_4042d41e                       2u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_4466940f                       1u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_ab68ea3f                       13u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_b1d6a3ac                       15u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_b7c754b1                       19u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_b249ed83                       16u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_bdde61e0                       8u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_f526491e                       11u
/**\} */

/**
 * \defgroup PduRHandleIdsIfTpTxSrc Handle IDs of handle space IfTpTxSrc.
 * \brief Communication interface and transport protocol Tx PDUs
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRSrcPdu_PduRSrcPdu                                2u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_3a56b5c8                       1u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_e9672331                       0u
/**\} */

/**
 * \defgroup PduRHandleIdsIfTxDest Handle IDs of handle space IfTxDest.
 * \brief Communication interface Tx destination PDUs
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRDestPdu_EIDC1_oC03_for_EL_CAN_V2_1_17d720dc_Tx   0u
#define PduRConf_PduRDestPdu_PduRDestPdu                              1u
/**\} */

/**
 * \defgroup PduRHandleIdsTpRxDest Handle IDs of handle space TpRxDest.
 * \brief Transport protocol Rx destination PDUs
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRDestPdu_DiagFuncReq_oC03_for_EL_CAN_V2_1_ebce8a95_Rx_6f6e60a2_Rx 0u
#define PduRConf_PduRDestPdu_EIDC_Phy_Req_oC03_for_EL_CAN_V2_1_0af433a2_Rx_446e9331_Rx 1u
/**\} */

/**
 * \defgroup PduRHandleIdsTpRxSrc Handle IDs of handle space TpRxSrc.
 * \brief Transport protocol Rx source PDUs
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_6f6e60a2                       0u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_446e9331                       1u
/**\} */

/**
 * \defgroup PduRHandleIdsTpTxDest Handle IDs of handle space TpTxDest.
 * \brief Transport protocol Tx PDUs
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRDestPdu_EIDC_Phy_Resp_oC03_for_EL_CAN_V2_1_0b15e5b1_Tx 0u
/**\} */


/* User Config File Start */

/* User Config File End */


/**********************************************************************************************************************
 * GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif  /* PDUR_CFG_H */
/**********************************************************************************************************************
 * END OF FILE: PduR_Cfg.h
 *********************************************************************************************************************/

