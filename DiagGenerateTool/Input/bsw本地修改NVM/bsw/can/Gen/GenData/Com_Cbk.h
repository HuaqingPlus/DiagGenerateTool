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
 *              File: Com_Cbk.h
 *   Generation Time: 2022-06-27 14:57:38
 *           Project: C03 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.24
 *
 *
 *********************************************************************************************************************/


#if !defined (COM_CBK_H)
# define COM_CBK_H

/**********************************************************************************************************************
  MISRA / PClint JUSTIFICATIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#include "Com_Cot.h"

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/



/**
 * \defgroup ComHandleIdsComRxPdu Handle IDs of handle space ComRxPdu.
 * \brief Rx Pdus
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define ComConf_ComIPdu_ABS3_oC03_for_EL_CAN_V2_1_5328da88_Rx         0u
#define ComConf_ComIPdu_BCM10_oC03_for_EL_CAN_V2_1_8175742c_Rx        1u
#define ComConf_ComIPdu_BCM17_oC03_for_EL_CAN_V2_1_e4ac4a6c_Rx        2u
#define ComConf_ComIPdu_BCM23_oC03_for_EL_CAN_V2_1_cee8e051_Rx        3u
#define ComConf_ComIPdu_BMS1_oC03_for_EL_CAN_V2_1_ab80ae92_Rx         4u
#define ComConf_ComIPdu_BMS17_oC03_for_EL_CAN_V2_1_be27a4ae_Rx        5u
#define ComConf_ComIPdu_CSA1_oC03_for_EL_CAN_V2_1_ffb47aea_Rx         6u
#define ComConf_ComIPdu_EEM1_oC03_for_EL_CAN_V2_1_5bdcd994_Rx         7u
#define ComConf_ComIPdu_GW1_oC03_for_EL_CAN_V2_1_48654b76_Rx          8u
#define ComConf_ComIPdu_HUT34_oC03_for_EL_CAN_V2_1_6fae3f7a_Rx        9u
#define ComConf_ComIPdu_HUT54_oC03_for_EL_CAN_V2_1_82644d00_Rx        10u
#define ComConf_ComIPdu_IP2_oC03_for_EL_CAN_V2_1_65941076_Rx          11u
#define ComConf_ComIPdu_MCU_5_oC03_for_EL_CAN_V2_1_002cb201_Rx        12u
#define ComConf_ComIPdu_OBC3_oC03_for_EL_CAN_V2_1_158aa3d5_Rx         13u
#define ComConf_ComIPdu_PEPS2_oC03_for_EL_CAN_V2_1_d41abfa7_Rx        14u
#define ComConf_ComIPdu_RMCU4_oC03_for_EL_CAN_V2_1_55159990_Rx        15u
#define ComConf_ComIPdu_R_PBOX1_oC03_for_EL_CAN_V2_1_7854cc6e_Rx      16u
#define ComConf_ComIPdu_VCU2_oC03_for_EL_CAN_V2_1_bea872d3_Rx         17u
#define ComConf_ComIPdu_VCU3_oC03_for_EL_CAN_V2_1_a9801613_Rx         18u
#define ComConf_ComIPdu_VCU6_oC03_for_EL_CAN_V2_1_e209e1d3_Rx         19u
/**\} */

/**
 * \defgroup ComHandleIdsComTxPdu Handle IDs of handle space ComTxPdu.
 * \brief Tx Pdus
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define ComConf_ComIPdu_ComIPdu_userData_tx                           0u
#define ComConf_ComIPdu_EIDC1_oC03_for_EL_CAN_V2_1_4a10c7b4_Tx        1u
/**\} */

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
#define COM_START_SEC_CODE
#include "MemMap.h"    /* PRQA S 5087 1 */ /*MD_MSR_MemMap */
/**********************************************************************************************************************
  Com_RxIndication
**********************************************************************************************************************/
/** \brief        This function is called by the lower layer after an I-PDU has been received.
    \param[in]    RxPduId      ID of AUTOSAR COM I-PDU that has been received. Identifies the data that has been received.
                               Range: 0..(maximum number of I-PDU IDs received by AUTOSAR COM) - 1
    \param[in]    PduInfoPtr   Payload information of the received I-PDU (pointer to data and data length).
    \return       none
    \context      The function can be called on interrupt and task level. It is not allowed to use CAT1 interrupts with Rte (BSW00326]). Due to this, the interrupt context shall be configured to a CAT2 interrupt if an Rte is used.
    \synchronous  TRUE
    \reentrant    TRUE, for different Handles
    \trace        SPEC-2737026
    \note         The function is called by the lower layer.
**********************************************************************************************************************/
FUNC(void, COM_CODE) Com_RxIndication(PduIdType RxPduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

/**********************************************************************************************************************
  Com_TxConfirmation
**********************************************************************************************************************/
/** \brief        This function is called by the lower layer after the PDU has been transmitted on the network.
                  A confirmation that is received for an I-PDU that does not require a confirmation is silently discarded.
    \param[in]    TxPduId   ID of AUTOSAR COM I-PDU that has been transmitted.
                            Range: 0..(maximum number of I-PDU IDs transmitted by AUTOSAR COM) - 1
    \return       none
    \context      The function can be called on interrupt and task level. It is not allowed to use CAT1 interrupts with Rte (BSW00326]). Due to this, the interrupt context shall be configured to a CAT2 interrupt if an Rte is used.
    \synchronous  TRUE
    \reentrant    TRUE, for different Handles
    \trace        SPEC-2737028
    \note         The function is called by the lower layer.
**********************************************************************************************************************/
FUNC(void, COM_CODE) Com_TxConfirmation(PduIdType TxPduId);

/**********************************************************************************************************************
  Com_TriggerTransmit
**********************************************************************************************************************/
/** \brief          This function is called by the lower layer when an AUTOSAR COM I-PDU shall be transmitted.
                    Within this function, AUTOSAR COM shall copy the contents of its I-PDU transmit buffer
                    to the L-PDU buffer given by SduPtr.
                    Use case:
                    This function is used e.g. by the LIN Master for sending out a LIN frame. In this case, the trigger transmit
                    can be initiated by the Master schedule table itself or a received LIN header.
                    This function is also used by the FlexRay Interface for requesting PDUs to be sent in static part
                    (synchronous to the FlexRay global time). Once the I-PDU has been successfully sent by the lower layer
                    (PDU-Router), the lower layer must call Com_TxConfirmation().
    \param[in]      TxPduId       ID of AUTOSAR COM I-PDU that is requested to be transmitted by AUTOSAR COM.
    \param[in,out]  PduInfoPtr    Contains a pointer to a buffer (SduDataPtr) where the SDU
                                  data shall be copied to, and the available buffer size in SduLengh.
                                  On return, the service will indicate the length of the copied SDU
                                  data in SduLength.
    \return         E_OK          SDU has been copied and SduLength indicates the number of copied bytes.
    \return         E_NOT_OK      No data has been copied, because
                                  Com is not initialized
                                  or TxPduId is not valid
                                  or PduInfoPtr is NULL_PTR
                                  or SduDataPtr is NULL_PTR
                                  or SduLength is too small.
    \context        TASK|ISR2
    \synchronous    TRUE
    \reentrant      TRUE, for different Handles
    \trace          SPEC-2737022, SPEC-2737023, SPEC-2737024
    \note           The function is called by the lower layer.
**********************************************************************************************************************/
FUNC(Std_ReturnType, COM_CODE) Com_TriggerTransmit(PduIdType TxPduId, P2VAR(PduInfoType, AUTOMATIC, COM_APPL_VAR) PduInfoPtr);


#define COM_STOP_SEC_CODE
#include "MemMap.h"    /* PRQA S 5087 1 */ /* MD_MSR_MemMap */

#endif  /* COM_CBK_H */
/**********************************************************************************************************************
  END OF FILE: Com_Cbk.h
**********************************************************************************************************************/

