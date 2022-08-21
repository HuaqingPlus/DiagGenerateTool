/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  Copyright (c) 2006-2015 by Vector Informatik GmbH.                                             All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_DcmExt.h
 *        Config:  Turing.dpa"
 *   ECU-Project:  Cluster
 *
 *     Generator:  MICROSAR RTE Generator Version 4.8.0
 *                 RTE Core Version 1.8.0
 *       License:  Unlimited license CBD1400814 for Visteon Corporation
 *
 *   Description:  Application header file for SW-C <DcmExt>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_DCMEXT_H
# define _RTE_DCMEXT_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
#  define RTE_PTR2ARRAYBASETYPE_PASSING
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_DcmExt_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(Boolean, RTE_VAR_INIT) Rte_Graph_270_Flag; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_Graph_270_level; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_Graph_216_Coolant_Count; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_Graph_216_Coolant_Flag; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_Graph_216_Fuel_Flag; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_Graph_216_Fule_Count; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_Graph_62_Flag; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_Graph_62_Type; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_DcmExt_tiSR_DcmExt_To_GdtCtrl_Black; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_DcmExt_tiSR_DcmExt_To_GdtCtrl_Blue; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_DcmExt_tiSR_DcmExt_To_GdtCtrl_Flag; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_DcmExt_tiSR_DcmExt_To_GdtCtrl_Green; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_DcmExt_tiSR_DcmExt_To_GdtCtrl_Red; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_DcmExt_tiSR_DcmExt_To_GdtCtrl_White; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_Graph_26_flag; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_INIT) Rte_Graph_26_value; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint16, RTE_VAR_INIT) Rte_Graph_26_write_value; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint16, RTE_VAR_INIT) Rte_DcmExt_tiSR_SiA_To_DCM_MaintenanceMile; /* PRQA S 0850 */ /* MD_MSR_19.8 */
//extern VAR(NV_Data_ClusterSettings, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_ClusterSettings; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(eIgnState, RTE_VAR_INIT) Rte_ModMdl_ppIgnState_IGNState; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint16, RTE_VAR_INIT) Rte_ComVnimMdl_ppSR_CANMSG_GWS1_ComIn_EMS_EngSpd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_ComVnimMdl_ppSR_CANMSG_GWS1_ComIn_NR; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_ComVnimMdl_ppSR_CANMSG_GWS1_ComIn_Tout; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint16, RTE_VAR_INIT) Rte_ComVnimMdl_ppSR_CANMSG_GWS3_ComIn_EMS_EngFilterSpd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_ComVnimMdl_ppSR_CANMSG_GWS3_ComIn_NR; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_ComVnimMdl_ppSR_CANMSG_GWS3_ComIn_Tout; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint16, RTE_VAR_INIT) Rte_ComVnimMdl_ppiSR_CANMSG_GW_ESC2_ComIn_ESC_VehSpd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_ComVnimMdl_ppiSR_CANMSG_GW_ESC2_ComIn_NR; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_ComVnimMdl_ppiSR_CANMSG_GW_ESC2_ComIn_Tout; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint16, RTE_VAR_INIT) Rte_ComVnimMdl_ppSR_CANMSG_IBCM6_ComIn_BCM_BattVolt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_ComVnimMdl_ppSR_CANMSG_IBCM6_ComIn_NR; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_ComVnimMdl_ppSR_CANMSG_IBCM6_ComIn_Tout; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_ComVnimMdl_ppSR_CANMSG_MP5_Time_ComIn_MP5_TBOX_Time_Date; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_ComVnimMdl_ppSR_CANMSG_MP5_Time_ComIn_MP5_TBOX_Time_Hour; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_ComVnimMdl_ppSR_CANMSG_MP5_Time_ComIn_MP5_TBOX_Time_Minute; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_ComVnimMdl_ppSR_CANMSG_MP5_Time_ComIn_MP5_TBOX_Time_Month; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_ComVnimMdl_ppSR_CANMSG_MP5_Time_ComIn_MP5_TBOX_Time_Second; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_ComVnimMdl_ppSR_CANMSG_MP5_Time_ComIn_MP5_TBOX_Time_Year; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_ComVnimMdl_ppSR_CANMSG_MP5_Time_ComIn_NR; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_ComVnimMdl_ppSR_CANMSG_MP5_Time_ComIn_Tout; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_INIT) Rte_OdoMdl_tiSR_OdoOutKiloMeters_KiloMeters; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_DimDerateMdl_tiSR_DimDerateMdl_DcmExt_value; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_INIT) Rte_SpdMdl_tiSR_TISpdMdl_Send_DigitalValue; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_INIT) Rte_SpdMdl_tiSR_TISpdMdl_Send_value; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_INIT) Rte_TachMdl_tiSR_TITachMdl_Send_value; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_INIT) Rte_TripMdl_tiSR_TripMdl_DcmExt_DTE_LastData; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_INIT) Rte_TripMdl_tiSR_TripMdl_DcmExt_DTE_RAFC; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint16, RTE_VAR_INIT) Rte_TripMdl_tiSR_TripMdl_To_Dcmext_AFC; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */

# ifndef RTE_CORE

#  define RTE_START_SEC_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* RTE Helper-Functions */
//FUNC(void, RTE_CODE) Rte_MemCpy(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint16_least num);
//FUNC(void, RTE_CODE) Rte_MemCpy32(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint16_least num);

#  define RTE_STOP_SEC_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_NV_ETM_Timeouts_ETM_ENTER (0U)
#  define Rte_InitValue_NV_ETM_Timeouts_ETM_ENTRY (0U)
#  define Rte_InitValue_NV_ETM_Timeouts_ETM_EXIT (0U)
#  define Rte_InitValue_TIModMdlIgnState_IGNState (0U)
#  define Rte_InitValue_rpSR_CANMSG_GW_EMS1_EMS_EngSpd (0U)
#  define Rte_InitValue_rpSR_CANMSG_GW_EMS1_EMS_EngSpdSignalFailure (0U)
#  define Rte_InitValue_rpSR_CANMSG_GW_EMS1_NR (0U)
#  define Rte_InitValue_rpSR_CANMSG_GW_EMS1_Tout (0U)
#  define Rte_InitValue_rpSR_CANMSG_GW_EMS3_EMS_EngFilterSpd (0U)
#  define Rte_InitValue_rpSR_CANMSG_GW_EMS3_NR (0U)
#  define Rte_InitValue_rpSR_CANMSG_GW_EMS3_Tout (0U)
#  define Rte_InitValue_rpSR_CANMSG_GW_ESC2_ABSAlarmSig (0U)
#  define Rte_InitValue_rpSR_CANMSG_GW_ESC2_Brake_fluidleveAlarm (0U)
#  define Rte_InitValue_rpSR_CANMSG_GW_ESC2_EBDAlarmSig (0U)
#  define Rte_InitValue_rpSR_CANMSG_GW_ESC2_ESC_VehSpd (0U)
#  define Rte_InitValue_rpSR_CANMSG_GW_ESC2_NR (0U)
#  define Rte_InitValue_rpSR_CANMSG_GW_ESC2_Tout (0U)
#  define Rte_InitValue_rpSR_CANMSG_GW_ESC2_VehSpdValidFlag (0U)
#  define Rte_InitValue_rpSR_CANMSG_IBCM6_BCM_BattVolt (0U)
#  define Rte_InitValue_rpSR_CANMSG_IBCM6_BCM_CarMode (0U)
#  define Rte_InitValue_rpSR_CANMSG_IBCM6_BCM_LowPowerWarning (0U)
#  define Rte_InitValue_rpSR_CANMSG_IBCM6_NR (0U)
#  define Rte_InitValue_rpSR_CANMSG_IBCM6_Tout (0U)
#  define Rte_InitValue_rpSR_CANMSG_MP5_Time_MP5_TBOX_Time_Date (0U)
#  define Rte_InitValue_rpSR_CANMSG_MP5_Time_MP5_TBOX_Time_Hour (0U)
#  define Rte_InitValue_rpSR_CANMSG_MP5_Time_MP5_TBOX_Time_Minute (0U)
#  define Rte_InitValue_rpSR_CANMSG_MP5_Time_MP5_TBOX_Time_Month (0U)
#  define Rte_InitValue_rpSR_CANMSG_MP5_Time_MP5_TBOX_Time_Second (0U)
#  define Rte_InitValue_rpSR_CANMSG_MP5_Time_MP5_TBOX_Time_System (0U)
#  define Rte_InitValue_rpSR_CANMSG_MP5_Time_MP5_TBOX_Time_Valid (0U)
#  define Rte_InitValue_rpSR_CANMSG_MP5_Time_MP5_TBOX_Time_Year (0U)
#  define Rte_InitValue_rpSR_CANMSG_MP5_Time_NR (0U)
#  define Rte_InitValue_rpSR_CANMSG_MP5_Time_Tout (0U)
#  define Rte_InitValue_rpSR_IGNState_IGNState (0U)
#  define Rte_InitValue_rpSR_OdoOutKiloMeters_KiloMeters (0U)
#  define Rte_InitValue_tiSR_DcmExt_DimPwm_Flag (FALSE)
#  define Rte_InitValue_tiSR_DcmExt_DimPwm_level (0U)
#  define Rte_InitValue_tiSR_DcmExt_To_BarView_Coolant_Count (0U)
#  define Rte_InitValue_tiSR_DcmExt_To_BarView_Coolant_Flag (FALSE)
#  define Rte_InitValue_tiSR_DcmExt_To_BarView_Fuel_Flag (FALSE)
#  define Rte_InitValue_tiSR_DcmExt_To_BarView_Fule_Count (0U)
#  define Rte_InitValue_tiSR_DcmExt_To_ChimeMdl_Flag (FALSE)
#  define Rte_InitValue_tiSR_DcmExt_To_ChimeMdl_Type (0U)
#  define Rte_InitValue_tiSR_DcmExt_To_GdtCtrl_Black (0U)
#  define Rte_InitValue_tiSR_DcmExt_To_GdtCtrl_Blue (0U)
#  define Rte_InitValue_tiSR_DcmExt_To_GdtCtrl_Flag (FALSE)
#  define Rte_InitValue_tiSR_DcmExt_To_GdtCtrl_Green (0U)
#  define Rte_InitValue_tiSR_DcmExt_To_GdtCtrl_Red (0U)
#  define Rte_InitValue_tiSR_DcmExt_To_GdtCtrl_White (0U)
#  define Rte_InitValue_tiSR_DcmExt_to_SIAMdl_flag (FALSE)
#  define Rte_InitValue_tiSR_DcmExt_to_SIAMdl_value (0U)
#  define Rte_InitValue_tiSR_DcmExt_to_SIAMdl_write_value (0U)
#  define Rte_InitValue_tiSR_DimDerateMdl_DcmExt_value (0U)
#  define Rte_InitValue_tiSR_SiA_To_DCM_MaintenanceMile (0U)
#  define Rte_InitValue_tiSR_TISpdMdl_DigitalValue (0U)
#  define Rte_InitValue_tiSR_TITachMdl_value (0U)
#  define Rte_InitValue_tiSR_TripMdl_DcmExt_DTE_LastData (0U)
#  define Rte_InitValue_tiSR_TripMdl_DcmExt_DTE_RAFC (0U)
#  define Rte_InitValue_tiSR_TripMdl_To_Dcmext_AFC (0U)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_Assembly_Date_Element(P2VAR(SDate_DataType, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_Assembly_Date_Element(P2VAR(NV_Date_SetType, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_Assembly_Plant_Num_Element(P2VAR(SAssembly_Plant_Num_DataType, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_Assembly_Plant_Num_Element(P2VAR(NV_Assembly_Plant_Num_DataType, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_Cluster_DiagTestBlock_DiagTestBlock(P2VAR(Rte_DT_NV_ECUDiagTestBlock_4Byte_0, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_Cluster_DiagTestBlock_DiagTestBlock(P2VAR(NV_ECUDiagTestBlock_4Byte, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_Cluster_ECUManufacturingDate_ManufacturingDate(P2VAR(Rte_DT_NV_ECUManufacturingDate_3Byte_0, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_Cluster_ECUManufacturingDate_ManufacturingDate(P2VAR(NV_ECUManufacturingDate_3Byte, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_Cluster_ECUOdoClearCounts_Element(P2VAR(Rte_DT_NV_ECUOdoClearCounts_4Byte_0, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_Cluster_ECUOdoClearCounts_Element(P2VAR(NV_ECUOdoClearCounts_4Byte, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_Cluster_ECUSerialNumber_ECUSerialNumber(P2VAR(Rte_DT_NV_ECUSerialNumber_12Byte_0, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_Cluster_ECUSerialNumber_ECUSerialNumber(P2VAR(NV_ECUSerialNumber_12Byte, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_Cluster_HardwareVersion_HardwareVersion(P2VAR(Rte_DT_NV_ECUHardwareVersion_2Byte_0, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_Cluster_HardwareVersion_HardwareVersion(P2VAR(NV_ECUHardwareVersion_2Byte, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_Cluster_HardwareVersionNumberOEM_HardwareVersionNumberOEM(P2VAR(Rte_DT_NV_ECUHardwareVersionNumberOEM_2Byte_0, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_Cluster_HardwareVersionNumberOEM_HardwareVersionNumberOEM(P2VAR(NV_ECUHardwareVersionNumberOEM_2Byte, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_Cluster_ProductPartNumber_ProductPartNumber(P2VAR(Rte_DT_NV_ECUProductPartNumber_14Byte_0, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_Cluster_ProductPartNumber_ProductPartNumber(P2VAR(NV_ECUProductPartNumber_14Byte, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_Cluster_ProgrammingDate_ProgrammingDate(P2VAR(Rte_DT_NV_ECUProgrammingDate_4Byte_0, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_Cluster_ProgrammingDate_ProgrammingDate(P2VAR(NV_ECUProgrammingDate_4Byte, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_Cluster_RepairInformation_RepairInformation(P2VAR(Rte_DT_NV_ECURepairInformation_12Byte_0, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_Cluster_RepairInformation_RepairInformation(P2VAR(NV_ECURepairInformation_12Byte, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_Cluster_ResetReason_ResetReason(P2VAR(Rte_DT_NV_ECUResetReason_32Byte_0, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_Cluster_ResetReason_ResetReason(P2VAR(NV_ECUResetReason_32Byte, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_Cluster_SoftwareCheck_SoftwareCheck(P2VAR(Rte_DT_NV_ECUSoftwareCheck_2Byte_0, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_Cluster_SoftwareCheck_SoftwareCheck(P2VAR(NV_ECUSoftwareCheck_2Byte, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_Cluster_SoftwareVersion_SoftwareVersion(P2VAR(Rte_DT_NV_ECUSoftwareVersion_2Byte_0, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_Cluster_SoftwareVersion_SoftwareVersion(P2VAR(NV_ECUSoftwareVersion_2Byte, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_Cluster_SoftwareVersionNumberOEM_SoftwareVersionNumberOEM(P2VAR(Rte_DT_NV_ECUSoftwareVersionNumberOEM_2Byte_0, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_Cluster_SoftwareVersionNumberOEM_SoftwareVersionNumberOEM(P2VAR(NV_ECUSoftwareVersionNumberOEM_2Byte, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_Cluster_SupplierIdentifier_SupplierIdentifier(P2VAR(Rte_DT_NV_ECUSupplierIdentifier_6Byte_0, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_Cluster_SupplierIdentifier_SupplierIdentifier(P2VAR(NV_ECUSupplierIdentifier_6Byte, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_Cluster_SystemName_SystemName(P2VAR(Rte_DT_NV_ECUSystemName_3Byte_0, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_Cluster_SystemName_SystemName(P2VAR(NV_ECUSystemName_3Byte, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_Cluster_VIN_Number_VIN_Number(P2VAR(Rte_DT_NV_VIN_Number_17Bytes_Type_0, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_Cluster_VIN_Number_VIN_Number(P2VAR(NV_VIN_Number_17Bytes_Type, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_Customer_Reference_Element(P2VAR(SCustomer_Reference, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_Customer_Reference_Element(P2VAR(NV_Customer_Reference_DataType, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_DTC_AgeTimes_Element(P2VAR(SDTCAgeTimesSet, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_DTC_AgeTimes_Element(P2VAR(NV_DTC_AgeTimes_SetType, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_ECUCfgFlag_Element(P2VAR(Rte_DT_NV_ECUCfgFlag_4Byte_0, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_ECUCfgFlag_Element(P2VAR(NV_ECUCfgFlag_4Byte, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_ECUDeliveryAssemblyNumber_Value(P2VAR(Rte_DT_NvM_ECU24BytesNumberType_0, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_ECUDeliveryAssemblyNumber_Value(P2VAR(NvM_ECU24BytesNumberType, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_ECUFuelLevel_Element(P2VAR(Rte_DT_NV_ECUFuelLevel_4Byte_0, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_ECUFuelLevel_Element(P2VAR(NV_ECUFuelLevel_4Byte, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_EEPROM_Element(P2VAR(SEEPROM_DataSet, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_EEPROM_Element(P2VAR(NV_EEPROM_SetType, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_Equipped_PCB_Element(P2VAR(SPCBDataSet, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_Equipped_PCB_Element(P2VAR(NV_PCB_SetType, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_Manu_Date_Element(P2VAR(SManu_Date_SetType, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_Manu_Date_Element(P2VAR(NV_Date_Manu_SetType, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_ProductInfo_Value(P2VAR(Rte_DT_NvM_ProductInfo_0, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_ProductInfo_Value(P2VAR(NvM_ProductInfo, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_Product_Customization_Element(P2VAR(SProduct_Customization_SetType, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_Product_Customization_Element(P2VAR(NV_Product_Customization_DataType, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_Reserved_Data_Element(P2VAR(SReserved_SetType, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_Reserved_Data_Element(P2VAR(NV_Reserved_DataType, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_SMD_Plant_Num_Element(P2VAR(SSMD_PLant_Num_SetType, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_SMD_Plant_Num_Element(P2VAR(NV_SMD_PLant_Num_DataType, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_SSAVE_Product_Element(P2VAR(SAVE_Product, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_SSAVE_Product_Element(P2VAR(NV_SAVE_Product_SetType, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_Serial_Num_PCB_Element(P2VAR(SSerial_Num_PCB, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_Serial_Num_PCB_Element(P2VAR(NV_Serial_PCB_SetType, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_Serial_Number_Product_Element(P2VAR(Serial_Number_Product, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_Serial_Number_Product_Element(P2VAR(NV_Serial_Number_Product_SetType, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_Software_Check_Element(P2VAR(SSoftwareCheckDataSet, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_Software_Check_Element(P2VAR(NV_Software_Check_DataType, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_Tracebility_Byte_Element(P2VAR(STracebility_Byte, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_Tracebility_Byte_Element(P2VAR(NV_Tracebility_Byte_DataType, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_Vehicle_Configure_VehicleConfigSetArray(P2VAR(Rte_DT_NV_Cluster_Vehicle_Configure_0, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DcmExt_NV_Vehicle_Configure_VehicleConfigSetArray(P2VAR(NV_Cluster_Vehicle_Configure, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_Assembly_Date_Element(P2CONST(SDate_DataType, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_Assembly_Date_Element(P2CONST(NV_Date_SetType, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_Assembly_Plant_Num_Element(P2CONST(SAssembly_Plant_Num_DataType, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_Assembly_Plant_Num_Element(P2CONST(NV_Assembly_Plant_Num_DataType, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_Cluster_DiagTestBlock_DiagTestBlock(P2CONST(Rte_DT_NV_ECUDiagTestBlock_4Byte_0, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_Cluster_DiagTestBlock_DiagTestBlock(P2CONST(NV_ECUDiagTestBlock_4Byte, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_Cluster_ECUManufacturingDate_ManufacturingDate(P2CONST(Rte_DT_NV_ECUManufacturingDate_3Byte_0, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_Cluster_ECUManufacturingDate_ManufacturingDate(P2CONST(NV_ECUManufacturingDate_3Byte, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_Cluster_ECUOdoClearCounts_Element(P2CONST(Rte_DT_NV_ECUOdoClearCounts_4Byte_0, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_Cluster_ECUOdoClearCounts_Element(P2CONST(NV_ECUOdoClearCounts_4Byte, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_Cluster_ECUSerialNumber_ECUSerialNumber(P2CONST(Rte_DT_NV_ECUSerialNumber_12Byte_0, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_Cluster_ECUSerialNumber_ECUSerialNumber(P2CONST(NV_ECUSerialNumber_12Byte, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_Cluster_HardwareVersion_HardwareVersion(P2CONST(Rte_DT_NV_ECUHardwareVersion_2Byte_0, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_Cluster_HardwareVersion_HardwareVersion(P2CONST(NV_ECUHardwareVersion_2Byte, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_Cluster_HardwareVersionNumberOEM_HardwareVersionNumberOEM(P2CONST(Rte_DT_NV_ECUHardwareVersionNumberOEM_2Byte_0, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_Cluster_HardwareVersionNumberOEM_HardwareVersionNumberOEM(P2CONST(NV_ECUHardwareVersionNumberOEM_2Byte, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_Cluster_ProductPartNumber_ProductPartNumber(P2CONST(Rte_DT_NV_ECUProductPartNumber_14Byte_0, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_Cluster_ProductPartNumber_ProductPartNumber(P2CONST(NV_ECUProductPartNumber_14Byte, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_Cluster_ProgrammingDate_ProgrammingDate(P2CONST(Rte_DT_NV_ECUProgrammingDate_4Byte_0, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_Cluster_ProgrammingDate_ProgrammingDate(P2CONST(NV_ECUProgrammingDate_4Byte, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_Cluster_RepairInformation_RepairInformation(P2CONST(Rte_DT_NV_ECURepairInformation_12Byte_0, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_Cluster_RepairInformation_RepairInformation(P2CONST(NV_ECURepairInformation_12Byte, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_Cluster_SoftwareCheck_SoftwareCheck(P2CONST(Rte_DT_NV_ECUSoftwareCheck_2Byte_0, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_Cluster_SoftwareCheck_SoftwareCheck(P2CONST(NV_ECUSoftwareCheck_2Byte, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_Cluster_SoftwareVersion_SoftwareVersion(P2CONST(Rte_DT_NV_ECUSoftwareVersion_2Byte_0, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_Cluster_SoftwareVersion_SoftwareVersion(P2CONST(NV_ECUSoftwareVersion_2Byte, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_Cluster_SoftwareVersionNumberOEM_SoftwareVersionNumberOEM(P2CONST(Rte_DT_NV_ECUSoftwareVersionNumberOEM_2Byte_0, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_Cluster_SoftwareVersionNumberOEM_SoftwareVersionNumberOEM(P2CONST(NV_ECUSoftwareVersionNumberOEM_2Byte, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_Cluster_SupplierIdentifier_SupplierIdentifier(P2CONST(Rte_DT_NV_ECUSupplierIdentifier_6Byte_0, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_Cluster_SupplierIdentifier_SupplierIdentifier(P2CONST(NV_ECUSupplierIdentifier_6Byte, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_Cluster_SystemName_SystemName(P2CONST(Rte_DT_NV_ECUSystemName_3Byte_0, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_Cluster_SystemName_SystemName(P2CONST(NV_ECUSystemName_3Byte, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_Cluster_VIN_Number_VIN_Number(P2CONST(Rte_DT_NV_VIN_Number_17Bytes_Type_0, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_Cluster_VIN_Number_VIN_Number(P2CONST(NV_VIN_Number_17Bytes_Type, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_Customer_Reference_Element(P2CONST(SCustomer_Reference, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_Customer_Reference_Element(P2CONST(NV_Customer_Reference_DataType, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_DTC_AgeTimes_Element(P2CONST(SDTCAgeTimesSet, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_DTC_AgeTimes_Element(P2CONST(NV_DTC_AgeTimes_SetType, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_ECUCfgFlag_Element(P2CONST(Rte_DT_NV_ECUCfgFlag_4Byte_0, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_ECUCfgFlag_Element(P2CONST(NV_ECUCfgFlag_4Byte, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_EEPROM_Element(P2CONST(SEEPROM_DataSet, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_EEPROM_Element(P2CONST(NV_EEPROM_SetType, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_ETM_Timeouts_ETM_ENTER(uint8 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_ETM_Timeouts_ETM_ENTRY(uint8 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_ETM_Timeouts_ETM_EXIT(uint8 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_Equipped_PCB_Element(P2CONST(SPCBDataSet, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_Equipped_PCB_Element(P2CONST(NV_PCB_SetType, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_Manu_Date_Element(P2CONST(SManu_Date_SetType, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_Manu_Date_Element(P2CONST(NV_Date_Manu_SetType, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_Product_Customization_Element(P2CONST(SProduct_Customization_SetType, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_Product_Customization_Element(P2CONST(NV_Product_Customization_DataType, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_Reserved_Data_Element(P2CONST(SReserved_SetType, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_Reserved_Data_Element(P2CONST(NV_Reserved_DataType, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_SMD_Plant_Num_Element(P2CONST(SSMD_PLant_Num_SetType, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_SMD_Plant_Num_Element(P2CONST(NV_SMD_PLant_Num_DataType, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_SSAVE_Product_Element(P2CONST(SAVE_Product, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_SSAVE_Product_Element(P2CONST(NV_SAVE_Product_SetType, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_Serial_Num_PCB_Element(P2CONST(SSerial_Num_PCB, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_Serial_Num_PCB_Element(P2CONST(NV_Serial_PCB_SetType, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_Serial_Number_Product_Element(P2CONST(Serial_Number_Product, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_Serial_Number_Product_Element(P2CONST(NV_Serial_Number_Product_SetType, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_Software_Check_Element(P2CONST(SSoftwareCheckDataSet, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_Software_Check_Element(P2CONST(NV_Software_Check_DataType, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_Tracebility_Byte_Element(P2CONST(STracebility_Byte, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_Tracebility_Byte_Element(P2CONST(NV_Tracebility_Byte_DataType, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_Vehicle_Configure_VehicleConfigSetArray(P2CONST(Rte_DT_NV_Cluster_Vehicle_Configure_0, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
////FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_NV_Vehicle_Configure_VehicleConfigSetArray(P2CONST(NV_Cluster_Vehicle_Configure, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
//FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DcmExt_ppSR_TIDcm_DID_IOC_DCM_IOC_Value(P2CONST(DCM_IOC_Type, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
////#  define Rte_Read_NV_Assembly_Date_Element Rte_Read_DcmExt_NV_Assembly_Date_Element
////#  define Rte_Read_NV_Assembly_Plant_Num_Element Rte_Read_DcmExt_NV_Assembly_Plant_Num_Element
////#  define Rte_Read_NV_Cluster_DiagTestBlock_DiagTestBlock Rte_Read_DcmExt_NV_Cluster_DiagTestBlock_DiagTestBlock
////#  define Rte_Read_NV_Cluster_ECUManufacturingDate_ManufacturingDate Rte_Read_DcmExt_NV_Cluster_ECUManufacturingDate_ManufacturingDate
////#  define Rte_Read_NV_Cluster_ECUOdoClearCounts_Element Rte_Read_DcmExt_NV_Cluster_ECUOdoClearCounts_Element
////#  define Rte_Read_NV_Cluster_ECUSerialNumber_ECUSerialNumber Rte_Read_DcmExt_NV_Cluster_ECUSerialNumber_ECUSerialNumber
////#  define Rte_Read_NV_Cluster_HardwareVersion_HardwareVersion Rte_Read_DcmExt_NV_Cluster_HardwareVersion_HardwareVersion
////#  define Rte_Read_NV_Cluster_HardwareVersionNumberOEM_HardwareVersionNumberOEM Rte_Read_DcmExt_NV_Cluster_HardwareVersionNumberOEM_HardwareVersionNumberOEM
////#  define Rte_Read_NV_Cluster_ProductPartNumber_ProductPartNumber Rte_Read_DcmExt_NV_Cluster_ProductPartNumber_ProductPartNumber
////#  define Rte_Read_NV_Cluster_ProgrammingDate_ProgrammingDate Rte_Read_DcmExt_NV_Cluster_ProgrammingDate_ProgrammingDate
////#  define Rte_Read_NV_Cluster_RepairInformation_RepairInformation Rte_Read_DcmExt_NV_Cluster_RepairInformation_RepairInformation
////#  define Rte_Read_NV_Cluster_ResetReason_ResetReason Rte_Read_DcmExt_NV_Cluster_ResetReason_ResetReason
////#  define Rte_Read_NV_Cluster_SoftwareCheck_SoftwareCheck Rte_Read_DcmExt_NV_Cluster_SoftwareCheck_SoftwareCheck
////#  define Rte_Read_NV_Cluster_SoftwareVersion_SoftwareVersion Rte_Read_DcmExt_NV_Cluster_SoftwareVersion_SoftwareVersion
////#  define Rte_Read_NV_Cluster_SoftwareVersionNumberOEM_SoftwareVersionNumberOEM Rte_Read_DcmExt_NV_Cluster_SoftwareVersionNumberOEM_SoftwareVersionNumberOEM
////#  define Rte_Read_NV_Cluster_SupplierIdentifier_SupplierIdentifier Rte_Read_DcmExt_NV_Cluster_SupplierIdentifier_SupplierIdentifier
////#  define Rte_Read_NV_Cluster_SystemName_SystemName Rte_Read_DcmExt_NV_Cluster_SystemName_SystemName
////#  define Rte_Read_NV_Cluster_VIN_Number_VIN_Number Rte_Read_DcmExt_NV_Cluster_VIN_Number_VIN_Number
////#  define Rte_Read_NV_Customer_Reference_Element Rte_Read_DcmExt_NV_Customer_Reference_Element
////#  define Rte_Read_NV_DTC_AgeTimes_Element Rte_Read_DcmExt_NV_DTC_AgeTimes_Element
////#  define Rte_Read_NV_ECUCfgFlag_Element Rte_Read_DcmExt_NV_ECUCfgFlag_Element
////#  define Rte_Read_NV_ECUDeliveryAssemblyNumber_Value Rte_Read_DcmExt_NV_ECUDeliveryAssemblyNumber_Value
////#  define Rte_Read_NV_ECUFuelLevel_Element Rte_Read_DcmExt_NV_ECUFuelLevel_Element
////#  define Rte_Read_NV_EEPROM_Element Rte_Read_DcmExt_NV_EEPROM_Element
////#  define Rte_Read_NV_ETM_Timeouts_ETM_ENTER Rte_Read_DcmExt_NV_ETM_Timeouts_ETM_ENTER
////#  define Rte_Read_DcmExt_NV_ETM_Timeouts_ETM_ENTER(data) (*(data) = Rte_NvBlockSwComponentType_NVBlockDescriptor_ClusterSettings.ETM_Enter, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
////#  define Rte_Read_NV_ETM_Timeouts_ETM_ENTRY Rte_Read_DcmExt_NV_ETM_Timeouts_ETM_ENTRY
////#  define Rte_Read_DcmExt_NV_ETM_Timeouts_ETM_ENTRY(data) (*(data) = Rte_NvBlockSwComponentType_NVBlockDescriptor_ClusterSettings.ETM_Entry, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
////#  define Rte_Read_NV_ETM_Timeouts_ETM_EXIT Rte_Read_DcmExt_NV_ETM_Timeouts_ETM_EXIT
////#  define Rte_Read_DcmExt_NV_ETM_Timeouts_ETM_EXIT(data) (*(data) = Rte_NvBlockSwComponentType_NVBlockDescriptor_ClusterSettings.ETM_Exit, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
////#  define Rte_Read_NV_Equipped_PCB_Element Rte_Read_DcmExt_NV_Equipped_PCB_Element
////#  define Rte_Read_NV_Manu_Date_Element Rte_Read_DcmExt_NV_Manu_Date_Element
////#  define Rte_Read_NV_ProductInfo_Value Rte_Read_DcmExt_NV_ProductInfo_Value
////#  define Rte_Read_NV_Product_Customization_Element Rte_Read_DcmExt_NV_Product_Customization_Element
////#  define Rte_Read_NV_Reserved_Data_Element Rte_Read_DcmExt_NV_Reserved_Data_Element
////#  define Rte_Read_NV_SMD_Plant_Num_Element Rte_Read_DcmExt_NV_SMD_Plant_Num_Element
////#  define Rte_Read_NV_SSAVE_Product_Element Rte_Read_DcmExt_NV_SSAVE_Product_Element
////#  define Rte_Read_NV_Serial_Num_PCB_Element Rte_Read_DcmExt_NV_Serial_Num_PCB_Element
////#  define Rte_Read_NV_Serial_Number_Product_Element Rte_Read_DcmExt_NV_Serial_Number_Product_Element
////#  define Rte_Read_NV_Software_Check_Element Rte_Read_DcmExt_NV_Software_Check_Element
////#  define Rte_Read_NV_Tracebility_Byte_Element Rte_Read_DcmExt_NV_Tracebility_Byte_Element
////#  define Rte_Read_NV_VehicleManufacturerECUSoftwareNumber_Value Rte_Read_DcmExt_NV_VehicleManufacturerECUSoftwareNumber_Value
//#  define Rte_Read_DcmExt_NV_VehicleManufacturerECUSoftwareNumber_Value(data) ( \
    Rte_MemCpy32(data, Rte_C_NvM_ECU24BytesNumberType_0, sizeof(NvM_ECU24BytesNumberType)) \
    ,((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
////#  define Rte_Read_NV_Vehicle_Configure_VehicleConfigSetArray Rte_Read_DcmExt_NV_Vehicle_Configure_VehicleConfigSetArray
//#  define Rte_Read_TIModMdlIgnState_IGNState Rte_Read_DcmExt_TIModMdlIgnState_IGNState
//#  define Rte_Read_DcmExt_TIModMdlIgnState_IGNState(data) (*(data) = Rte_ModMdl_ppIgnState_IGNState, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Read_rpSR_CANMSG_GW_EMS1_EMS_EngSpd Rte_Read_DcmExt_rpSR_CANMSG_GW_EMS1_EMS_EngSpd
//#  define Rte_Read_DcmExt_rpSR_CANMSG_GW_EMS1_EMS_EngSpd(data) (*(data) = Rte_ComVnimMdl_ppSR_CANMSG_GWS1_ComIn_EMS_EngSpd, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Read_rpSR_CANMSG_GW_EMS1_NR Rte_Read_DcmExt_rpSR_CANMSG_GW_EMS1_NR
//#  define Rte_Read_DcmExt_rpSR_CANMSG_GW_EMS1_NR(data) (*(data) = Rte_ComVnimMdl_ppSR_CANMSG_GWS1_ComIn_NR, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Read_rpSR_CANMSG_GW_EMS1_Tout Rte_Read_DcmExt_rpSR_CANMSG_GW_EMS1_Tout
//#  define Rte_Read_DcmExt_rpSR_CANMSG_GW_EMS1_Tout(data) (*(data) = Rte_ComVnimMdl_ppSR_CANMSG_GWS1_ComIn_Tout, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Read_rpSR_CANMSG_GW_EMS3_EMS_EngFilterSpd Rte_Read_DcmExt_rpSR_CANMSG_GW_EMS3_EMS_EngFilterSpd
//#  define Rte_Read_DcmExt_rpSR_CANMSG_GW_EMS3_EMS_EngFilterSpd(data) (*(data) = Rte_ComVnimMdl_ppSR_CANMSG_GWS3_ComIn_EMS_EngFilterSpd, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Read_rpSR_CANMSG_GW_EMS3_NR Rte_Read_DcmExt_rpSR_CANMSG_GW_EMS3_NR
//#  define Rte_Read_DcmExt_rpSR_CANMSG_GW_EMS3_NR(data) (*(data) = Rte_ComVnimMdl_ppSR_CANMSG_GWS3_ComIn_NR, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Read_rpSR_CANMSG_GW_EMS3_Tout Rte_Read_DcmExt_rpSR_CANMSG_GW_EMS3_Tout
//#  define Rte_Read_DcmExt_rpSR_CANMSG_GW_EMS3_Tout(data) (*(data) = Rte_ComVnimMdl_ppSR_CANMSG_GWS3_ComIn_Tout, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Read_rpSR_CANMSG_GW_ESC2_ESC_VehSpd Rte_Read_DcmExt_rpSR_CANMSG_GW_ESC2_ESC_VehSpd
//#  define Rte_Read_DcmExt_rpSR_CANMSG_GW_ESC2_ESC_VehSpd(data) (*(data) = Rte_ComVnimMdl_ppiSR_CANMSG_GW_ESC2_ComIn_ESC_VehSpd, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Read_rpSR_CANMSG_GW_ESC2_NR Rte_Read_DcmExt_rpSR_CANMSG_GW_ESC2_NR
//#  define Rte_Read_DcmExt_rpSR_CANMSG_GW_ESC2_NR(data) (*(data) = Rte_ComVnimMdl_ppiSR_CANMSG_GW_ESC2_ComIn_NR, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Read_rpSR_CANMSG_GW_ESC2_Tout Rte_Read_DcmExt_rpSR_CANMSG_GW_ESC2_Tout
//#  define Rte_Read_DcmExt_rpSR_CANMSG_GW_ESC2_Tout(data) (*(data) = Rte_ComVnimMdl_ppiSR_CANMSG_GW_ESC2_ComIn_Tout, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Read_rpSR_CANMSG_IBCM6_BCM_BattVolt Rte_Read_DcmExt_rpSR_CANMSG_IBCM6_BCM_BattVolt
//#  define Rte_Read_DcmExt_rpSR_CANMSG_IBCM6_BCM_BattVolt(data) (*(data) = Rte_ComVnimMdl_ppSR_CANMSG_IBCM6_ComIn_BCM_BattVolt, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Read_rpSR_CANMSG_IBCM6_NR Rte_Read_DcmExt_rpSR_CANMSG_IBCM6_NR
//#  define Rte_Read_DcmExt_rpSR_CANMSG_IBCM6_NR(data) (*(data) = Rte_ComVnimMdl_ppSR_CANMSG_IBCM6_ComIn_NR, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Read_rpSR_CANMSG_IBCM6_Tout Rte_Read_DcmExt_rpSR_CANMSG_IBCM6_Tout
//#  define Rte_Read_DcmExt_rpSR_CANMSG_IBCM6_Tout(data) (*(data) = Rte_ComVnimMdl_ppSR_CANMSG_IBCM6_ComIn_Tout, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Read_rpSR_CANMSG_MP5_Time_MP5_TBOX_Time_Date Rte_Read_DcmExt_rpSR_CANMSG_MP5_Time_MP5_TBOX_Time_Date
//#  define Rte_Read_DcmExt_rpSR_CANMSG_MP5_Time_MP5_TBOX_Time_Date(data) (*(data) = Rte_ComVnimMdl_ppSR_CANMSG_MP5_Time_ComIn_MP5_TBOX_Time_Date, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Read_rpSR_CANMSG_MP5_Time_MP5_TBOX_Time_Hour Rte_Read_DcmExt_rpSR_CANMSG_MP5_Time_MP5_TBOX_Time_Hour
//#  define Rte_Read_DcmExt_rpSR_CANMSG_MP5_Time_MP5_TBOX_Time_Hour(data) (*(data) = Rte_ComVnimMdl_ppSR_CANMSG_MP5_Time_ComIn_MP5_TBOX_Time_Hour, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Read_rpSR_CANMSG_MP5_Time_MP5_TBOX_Time_Minute Rte_Read_DcmExt_rpSR_CANMSG_MP5_Time_MP5_TBOX_Time_Minute
//#  define Rte_Read_DcmExt_rpSR_CANMSG_MP5_Time_MP5_TBOX_Time_Minute(data) (*(data) = Rte_ComVnimMdl_ppSR_CANMSG_MP5_Time_ComIn_MP5_TBOX_Time_Minute, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Read_rpSR_CANMSG_MP5_Time_MP5_TBOX_Time_Month Rte_Read_DcmExt_rpSR_CANMSG_MP5_Time_MP5_TBOX_Time_Month
//#  define Rte_Read_DcmExt_rpSR_CANMSG_MP5_Time_MP5_TBOX_Time_Month(data) (*(data) = Rte_ComVnimMdl_ppSR_CANMSG_MP5_Time_ComIn_MP5_TBOX_Time_Month, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Read_rpSR_CANMSG_MP5_Time_MP5_TBOX_Time_Second Rte_Read_DcmExt_rpSR_CANMSG_MP5_Time_MP5_TBOX_Time_Second
//#  define Rte_Read_DcmExt_rpSR_CANMSG_MP5_Time_MP5_TBOX_Time_Second(data) (*(data) = Rte_ComVnimMdl_ppSR_CANMSG_MP5_Time_ComIn_MP5_TBOX_Time_Second, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Read_rpSR_CANMSG_MP5_Time_MP5_TBOX_Time_Year Rte_Read_DcmExt_rpSR_CANMSG_MP5_Time_MP5_TBOX_Time_Year
//#  define Rte_Read_DcmExt_rpSR_CANMSG_MP5_Time_MP5_TBOX_Time_Year(data) (*(data) = Rte_ComVnimMdl_ppSR_CANMSG_MP5_Time_ComIn_MP5_TBOX_Time_Year, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Read_rpSR_CANMSG_MP5_Time_NR Rte_Read_DcmExt_rpSR_CANMSG_MP5_Time_NR
//#  define Rte_Read_DcmExt_rpSR_CANMSG_MP5_Time_NR(data) (*(data) = Rte_ComVnimMdl_ppSR_CANMSG_MP5_Time_ComIn_NR, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Read_rpSR_CANMSG_MP5_Time_Tout Rte_Read_DcmExt_rpSR_CANMSG_MP5_Time_Tout
//#  define Rte_Read_DcmExt_rpSR_CANMSG_MP5_Time_Tout(data) (*(data) = Rte_ComVnimMdl_ppSR_CANMSG_MP5_Time_ComIn_Tout, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Read_rpSR_OdoOutKiloMeters_KiloMeters Rte_Read_DcmExt_rpSR_OdoOutKiloMeters_KiloMeters
//#  define Rte_Read_DcmExt_rpSR_OdoOutKiloMeters_KiloMeters(data) (*(data) = Rte_OdoMdl_tiSR_OdoOutKiloMeters_KiloMeters, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Read_tiSR_DcmExt_DimPwm_Flag Rte_Read_DcmExt_tiSR_DcmExt_DimPwm_Flag
//#  define Rte_Read_DcmExt_tiSR_DcmExt_DimPwm_Flag(data) (*(data) = Rte_Graph_270_Flag, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Read_tiSR_DcmExt_DimPwm_level Rte_Read_DcmExt_tiSR_DcmExt_DimPwm_level
//#  define Rte_Read_DcmExt_tiSR_DcmExt_DimPwm_level(data) (*(data) = Rte_Graph_270_level, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Read_tiSR_DcmExt_To_BarView_Coolant_Count Rte_Read_DcmExt_tiSR_DcmExt_To_BarView_Coolant_Count
//#  define Rte_Read_DcmExt_tiSR_DcmExt_To_BarView_Coolant_Count(data) (*(data) = Rte_Graph_216_Coolant_Count, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Read_tiSR_DcmExt_To_BarView_Coolant_Flag Rte_Read_DcmExt_tiSR_DcmExt_To_BarView_Coolant_Flag
//#  define Rte_Read_DcmExt_tiSR_DcmExt_To_BarView_Coolant_Flag(data) (*(data) = Rte_Graph_216_Coolant_Flag, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Read_tiSR_DcmExt_To_BarView_Fuel_Flag Rte_Read_DcmExt_tiSR_DcmExt_To_BarView_Fuel_Flag
//#  define Rte_Read_DcmExt_tiSR_DcmExt_To_BarView_Fuel_Flag(data) (*(data) = Rte_Graph_216_Fuel_Flag, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Read_tiSR_DcmExt_To_BarView_Fule_Count Rte_Read_DcmExt_tiSR_DcmExt_To_BarView_Fule_Count
//#  define Rte_Read_DcmExt_tiSR_DcmExt_To_BarView_Fule_Count(data) (*(data) = Rte_Graph_216_Fule_Count, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Read_tiSR_DcmExt_To_ChimeMdl_Flag Rte_Read_DcmExt_tiSR_DcmExt_To_ChimeMdl_Flag
//#  define Rte_Read_DcmExt_tiSR_DcmExt_To_ChimeMdl_Flag(data) (*(data) = Rte_Graph_62_Flag, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Read_tiSR_DcmExt_To_ChimeMdl_Type Rte_Read_DcmExt_tiSR_DcmExt_To_ChimeMdl_Type
//#  define Rte_Read_DcmExt_tiSR_DcmExt_To_ChimeMdl_Type(data) (*(data) = Rte_Graph_62_Type, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Read_tiSR_DcmExt_To_GdtCtrl_Black Rte_Read_DcmExt_tiSR_DcmExt_To_GdtCtrl_Black
//#  define Rte_Read_DcmExt_tiSR_DcmExt_To_GdtCtrl_Black(data) (*(data) = Rte_DcmExt_tiSR_DcmExt_To_GdtCtrl_Black, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Read_tiSR_DcmExt_To_GdtCtrl_Blue Rte_Read_DcmExt_tiSR_DcmExt_To_GdtCtrl_Blue
//#  define Rte_Read_DcmExt_tiSR_DcmExt_To_GdtCtrl_Blue(data) (*(data) = Rte_DcmExt_tiSR_DcmExt_To_GdtCtrl_Blue, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Read_tiSR_DcmExt_To_GdtCtrl_Flag Rte_Read_DcmExt_tiSR_DcmExt_To_GdtCtrl_Flag
//#  define Rte_Read_DcmExt_tiSR_DcmExt_To_GdtCtrl_Flag(data) (*(data) = Rte_DcmExt_tiSR_DcmExt_To_GdtCtrl_Flag, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Read_tiSR_DcmExt_To_GdtCtrl_Green Rte_Read_DcmExt_tiSR_DcmExt_To_GdtCtrl_Green
//#  define Rte_Read_DcmExt_tiSR_DcmExt_To_GdtCtrl_Green(data) (*(data) = Rte_DcmExt_tiSR_DcmExt_To_GdtCtrl_Green, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Read_tiSR_DcmExt_To_GdtCtrl_Red Rte_Read_DcmExt_tiSR_DcmExt_To_GdtCtrl_Red
//#  define Rte_Read_DcmExt_tiSR_DcmExt_To_GdtCtrl_Red(data) (*(data) = Rte_DcmExt_tiSR_DcmExt_To_GdtCtrl_Red, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Read_tiSR_DcmExt_To_GdtCtrl_White Rte_Read_DcmExt_tiSR_DcmExt_To_GdtCtrl_White
//#  define Rte_Read_DcmExt_tiSR_DcmExt_To_GdtCtrl_White(data) (*(data) = Rte_DcmExt_tiSR_DcmExt_To_GdtCtrl_White, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Read_tiSR_DcmExt_to_SIAMdl_flag Rte_Read_DcmExt_tiSR_DcmExt_to_SIAMdl_flag
//#  define Rte_Read_DcmExt_tiSR_DcmExt_to_SIAMdl_flag(data) (*(data) = Rte_Graph_26_flag, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Read_tiSR_DcmExt_to_SIAMdl_value Rte_Read_DcmExt_tiSR_DcmExt_to_SIAMdl_value
//#  define Rte_Read_DcmExt_tiSR_DcmExt_to_SIAMdl_value(data) (*(data) = Rte_Graph_26_value, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Read_tiSR_DcmExt_to_SIAMdl_write_value Rte_Read_DcmExt_tiSR_DcmExt_to_SIAMdl_write_value
//#  define Rte_Read_DcmExt_tiSR_DcmExt_to_SIAMdl_write_value(data) (*(data) = Rte_Graph_26_write_value, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Read_tiSR_DimDerateMdl_DcmExt_value Rte_Read_DcmExt_tiSR_DimDerateMdl_DcmExt_value
//#  define Rte_Read_DcmExt_tiSR_DimDerateMdl_DcmExt_value(data) (*(data) = Rte_DimDerateMdl_tiSR_DimDerateMdl_DcmExt_value, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Read_tiSR_SiA_To_DCM_MaintenanceMile Rte_Read_DcmExt_tiSR_SiA_To_DCM_MaintenanceMile
//#  define Rte_Read_DcmExt_tiSR_SiA_To_DCM_MaintenanceMile(data) (*(data) = Rte_DcmExt_tiSR_SiA_To_DCM_MaintenanceMile, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Read_tiSR_TISpdMdl_DigitalValue Rte_Read_DcmExt_tiSR_TISpdMdl_DigitalValue
//#  define Rte_Read_DcmExt_tiSR_TISpdMdl_DigitalValue(data) (*(data) = Rte_SpdMdl_tiSR_TISpdMdl_Send_DigitalValue, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Read_tiSR_TISpdMdl_value Rte_Read_DcmExt_tiSR_TISpdMdl_value
//#  define Rte_Read_DcmExt_tiSR_TISpdMdl_value(data) (*(data) = Rte_SpdMdl_tiSR_TISpdMdl_Send_value, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Read_tiSR_TITachMdl_value Rte_Read_DcmExt_tiSR_TITachMdl_value
//#  define Rte_Read_DcmExt_tiSR_TITachMdl_value(data) (*(data) = Rte_TachMdl_tiSR_TITachMdl_Send_value, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Read_tiSR_TripMdl_DcmExt_DTE_LastData Rte_Read_DcmExt_tiSR_TripMdl_DcmExt_DTE_LastData
//#  define Rte_Read_DcmExt_tiSR_TripMdl_DcmExt_DTE_LastData(data) (*(data) = Rte_TripMdl_tiSR_TripMdl_DcmExt_DTE_LastData, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Read_tiSR_TripMdl_DcmExt_DTE_RAFC Rte_Read_DcmExt_tiSR_TripMdl_DcmExt_DTE_RAFC
//#  define Rte_Read_DcmExt_tiSR_TripMdl_DcmExt_DTE_RAFC(data) (*(data) = Rte_TripMdl_tiSR_TripMdl_DcmExt_DTE_RAFC, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Read_tiSR_TripMdl_To_Dcmext_AFC Rte_Read_DcmExt_tiSR_TripMdl_To_Dcmext_AFC
//#  define Rte_Read_DcmExt_tiSR_TripMdl_To_Dcmext_AFC(data) (*(data) = Rte_TripMdl_tiSR_TripMdl_To_Dcmext_AFC, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
//#  define Rte_Write_NV_Assembly_Date_Element Rte_Write_DcmExt_NV_Assembly_Date_Element
//#  define Rte_Write_NV_Assembly_Plant_Num_Element Rte_Write_DcmExt_NV_Assembly_Plant_Num_Element
//#  define Rte_Write_NV_Cluster_DiagTestBlock_DiagTestBlock Rte_Write_DcmExt_NV_Cluster_DiagTestBlock_DiagTestBlock
//#  define Rte_Write_NV_Cluster_ECUManufacturingDate_ManufacturingDate Rte_Write_DcmExt_NV_Cluster_ECUManufacturingDate_ManufacturingDate
//#  define Rte_Write_NV_Cluster_ECUOdoClearCounts_Element Rte_Write_DcmExt_NV_Cluster_ECUOdoClearCounts_Element
//#  define Rte_Write_NV_Cluster_ECUSerialNumber_ECUSerialNumber Rte_Write_DcmExt_NV_Cluster_ECUSerialNumber_ECUSerialNumber
//#  define Rte_Write_NV_Cluster_HardwareVersion_HardwareVersion Rte_Write_DcmExt_NV_Cluster_HardwareVersion_HardwareVersion
//#  define Rte_Write_NV_Cluster_HardwareVersionNumberOEM_HardwareVersionNumberOEM Rte_Write_DcmExt_NV_Cluster_HardwareVersionNumberOEM_HardwareVersionNumberOEM
//#  define Rte_Write_NV_Cluster_ProductPartNumber_ProductPartNumber Rte_Write_DcmExt_NV_Cluster_ProductPartNumber_ProductPartNumber
//#  define Rte_Write_NV_Cluster_ProgrammingDate_ProgrammingDate Rte_Write_DcmExt_NV_Cluster_ProgrammingDate_ProgrammingDate
//#  define Rte_Write_NV_Cluster_RepairInformation_RepairInformation Rte_Write_DcmExt_NV_Cluster_RepairInformation_RepairInformation
//#  define Rte_Write_NV_Cluster_SoftwareCheck_SoftwareCheck Rte_Write_DcmExt_NV_Cluster_SoftwareCheck_SoftwareCheck
//#  define Rte_Write_NV_Cluster_SoftwareVersion_SoftwareVersion Rte_Write_DcmExt_NV_Cluster_SoftwareVersion_SoftwareVersion
//#  define Rte_Write_NV_Cluster_SoftwareVersionNumberOEM_SoftwareVersionNumberOEM Rte_Write_DcmExt_NV_Cluster_SoftwareVersionNumberOEM_SoftwareVersionNumberOEM
//#  define Rte_Write_NV_Cluster_SupplierIdentifier_SupplierIdentifier Rte_Write_DcmExt_NV_Cluster_SupplierIdentifier_SupplierIdentifier
//#  define Rte_Write_NV_Cluster_SystemName_SystemName Rte_Write_DcmExt_NV_Cluster_SystemName_SystemName
//#  define Rte_Write_NV_Cluster_VIN_Number_VIN_Number Rte_Write_DcmExt_NV_Cluster_VIN_Number_VIN_Number
//#  define Rte_Write_NV_Customer_Reference_Element Rte_Write_DcmExt_NV_Customer_Reference_Element
#  define Rte_Write_NV_DTC_AgeTimes_Element Rte_Write_DcmExt_NV_DTC_AgeTimes_Element
//#  define Rte_Write_NV_ECUCfgFlag_Element Rte_Write_DcmExt_NV_ECUCfgFlag_Element
//#  define Rte_Write_NV_EEPROM_Element Rte_Write_DcmExt_NV_EEPROM_Element
//#  define Rte_Write_NV_ETM_Timeouts_ETM_ENTER Rte_Write_DcmExt_NV_ETM_Timeouts_ETM_ENTER
//#  define Rte_Write_NV_ETM_Timeouts_ETM_ENTRY Rte_Write_DcmExt_NV_ETM_Timeouts_ETM_ENTRY
//#  define Rte_Write_NV_ETM_Timeouts_ETM_EXIT Rte_Write_DcmExt_NV_ETM_Timeouts_ETM_EXIT
//#  define Rte_Write_NV_Equipped_PCB_Element Rte_Write_DcmExt_NV_Equipped_PCB_Element
//#  define Rte_Write_NV_Manu_Date_Element Rte_Write_DcmExt_NV_Manu_Date_Element
//#  define Rte_Write_NV_Product_Customization_Element Rte_Write_DcmExt_NV_Product_Customization_Element
//#  define Rte_Write_NV_Reserved_Data_Element Rte_Write_DcmExt_NV_Reserved_Data_Element
//#  define Rte_Write_NV_SMD_Plant_Num_Element Rte_Write_DcmExt_NV_SMD_Plant_Num_Element
//#  define Rte_Write_NV_SSAVE_Product_Element Rte_Write_DcmExt_NV_SSAVE_Product_Element
//#  define Rte_Write_NV_Serial_Num_PCB_Element Rte_Write_DcmExt_NV_Serial_Num_PCB_Element
//#  define Rte_Write_NV_Serial_Number_Product_Element Rte_Write_DcmExt_NV_Serial_Number_Product_Element
//#  define Rte_Write_NV_Software_Check_Element Rte_Write_DcmExt_NV_Software_Check_Element
//#  define Rte_Write_NV_Tracebility_Byte_Element Rte_Write_DcmExt_NV_Tracebility_Byte_Element
//#  define Rte_Write_NV_Vehicle_Configure_VehicleConfigSetArray Rte_Write_DcmExt_NV_Vehicle_Configure_VehicleConfigSetArray
//#  define Rte_Write_ppSR_TIDcm_DID_IOC_DCM_IOC_Value Rte_Write_DcmExt_ppSR_TIDcm_DID_IOC_DCM_IOC_Value
//#  define Rte_Write_tiSR_DcmExt_DimPwm_Flag Rte_Write_DcmExt_tiSR_DcmExt_DimPwm_Flag
//#  define Rte_Write_DcmExt_tiSR_DcmExt_DimPwm_Flag(data) (Rte_Graph_270_Flag = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Write_tiSR_DcmExt_DimPwm_level Rte_Write_DcmExt_tiSR_DcmExt_DimPwm_level
//#  define Rte_Write_DcmExt_tiSR_DcmExt_DimPwm_level(data) (Rte_Graph_270_level = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Write_tiSR_DcmExt_To_BarView_Coolant_Count Rte_Write_DcmExt_tiSR_DcmExt_To_BarView_Coolant_Count
//#  define Rte_Write_DcmExt_tiSR_DcmExt_To_BarView_Coolant_Count(data) (Rte_Graph_216_Coolant_Count = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Write_tiSR_DcmExt_To_BarView_Coolant_Flag Rte_Write_DcmExt_tiSR_DcmExt_To_BarView_Coolant_Flag
//#  define Rte_Write_DcmExt_tiSR_DcmExt_To_BarView_Coolant_Flag(data) (Rte_Graph_216_Coolant_Flag = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Write_tiSR_DcmExt_To_BarView_Fuel_Flag Rte_Write_DcmExt_tiSR_DcmExt_To_BarView_Fuel_Flag
//#  define Rte_Write_DcmExt_tiSR_DcmExt_To_BarView_Fuel_Flag(data) (Rte_Graph_216_Fuel_Flag = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Write_tiSR_DcmExt_To_BarView_Fule_Count Rte_Write_DcmExt_tiSR_DcmExt_To_BarView_Fule_Count
//#  define Rte_Write_DcmExt_tiSR_DcmExt_To_BarView_Fule_Count(data) (Rte_Graph_216_Fule_Count = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Write_tiSR_DcmExt_To_ChimeMdl_Flag Rte_Write_DcmExt_tiSR_DcmExt_To_ChimeMdl_Flag
//#  define Rte_Write_DcmExt_tiSR_DcmExt_To_ChimeMdl_Flag(data) (Rte_Graph_62_Flag = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Write_tiSR_DcmExt_To_ChimeMdl_Type Rte_Write_DcmExt_tiSR_DcmExt_To_ChimeMdl_Type
//#  define Rte_Write_DcmExt_tiSR_DcmExt_To_ChimeMdl_Type(data) (Rte_Graph_62_Type = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Write_tiSR_DcmExt_To_GdtCtrl_Black Rte_Write_DcmExt_tiSR_DcmExt_To_GdtCtrl_Black
//#  define Rte_Write_DcmExt_tiSR_DcmExt_To_GdtCtrl_Black(data) (Rte_DcmExt_tiSR_DcmExt_To_GdtCtrl_Black = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Write_tiSR_DcmExt_To_GdtCtrl_Blue Rte_Write_DcmExt_tiSR_DcmExt_To_GdtCtrl_Blue
//#  define Rte_Write_DcmExt_tiSR_DcmExt_To_GdtCtrl_Blue(data) (Rte_DcmExt_tiSR_DcmExt_To_GdtCtrl_Blue = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Write_tiSR_DcmExt_To_GdtCtrl_Flag Rte_Write_DcmExt_tiSR_DcmExt_To_GdtCtrl_Flag
//#  define Rte_Write_DcmExt_tiSR_DcmExt_To_GdtCtrl_Flag(data) (Rte_DcmExt_tiSR_DcmExt_To_GdtCtrl_Flag = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Write_tiSR_DcmExt_To_GdtCtrl_Green Rte_Write_DcmExt_tiSR_DcmExt_To_GdtCtrl_Green
//#  define Rte_Write_DcmExt_tiSR_DcmExt_To_GdtCtrl_Green(data) (Rte_DcmExt_tiSR_DcmExt_To_GdtCtrl_Green = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Write_tiSR_DcmExt_To_GdtCtrl_Red Rte_Write_DcmExt_tiSR_DcmExt_To_GdtCtrl_Red
//#  define Rte_Write_DcmExt_tiSR_DcmExt_To_GdtCtrl_Red(data) (Rte_DcmExt_tiSR_DcmExt_To_GdtCtrl_Red = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Write_tiSR_DcmExt_To_GdtCtrl_White Rte_Write_DcmExt_tiSR_DcmExt_To_GdtCtrl_White
//#  define Rte_Write_DcmExt_tiSR_DcmExt_To_GdtCtrl_White(data) (Rte_DcmExt_tiSR_DcmExt_To_GdtCtrl_White = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Write_tiSR_DcmExt_to_SIAMdl_flag Rte_Write_DcmExt_tiSR_DcmExt_to_SIAMdl_flag
//#  define Rte_Write_DcmExt_tiSR_DcmExt_to_SIAMdl_flag(data) (Rte_Graph_26_flag = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Write_tiSR_DcmExt_to_SIAMdl_value Rte_Write_DcmExt_tiSR_DcmExt_to_SIAMdl_value
//#  define Rte_Write_DcmExt_tiSR_DcmExt_to_SIAMdl_value(data) (Rte_Graph_26_value = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Write_tiSR_DcmExt_to_SIAMdl_write_value Rte_Write_DcmExt_tiSR_DcmExt_to_SIAMdl_write_value
//#  define Rte_Write_DcmExt_tiSR_DcmExt_to_SIAMdl_write_value(data) (Rte_Graph_26_write_value = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
//#  define Rte_Write_tiSR_SiA_To_DCM_MaintenanceMile Rte_Write_DcmExt_tiSR_SiA_To_DCM_MaintenanceMile
//#  define Rte_Write_DcmExt_tiSR_SiA_To_DCM_MaintenanceMile(data) (Rte_DcmExt_tiSR_SiA_To_DCM_MaintenanceMile = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_VEHICLECFGMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
//FUNC(void, RTE_VEHICLECFGMDL_APPL_CODE) CVehicleCfgMdl_SetECUCfgFlag(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_VEHICLECFGMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_SetECUCfgFlag_Operation() (CVehicleCfgMdl_SetECUCfgFlag(), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_ODOMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
//FUNC(void, RTE_ODOMDL_APPL_CODE) COdoMdl_SetOdoTotalMeter(uint32 OdoTotalMeter, P2VAR(boolean, AUTOMATIC, RTE_ODOMDL_APPL_VAR) ret); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_ODOMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_SetOdoTotalMeter_Operation(arg1, arg2) (COdoMdl_SetOdoTotalMeter(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
//FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) CIoHwAb_Impl_GetPin(EIOPinInId Id, P2VAR(Boolean, AUTOMATIC, RTE_IOHWAB_APPL_VAR) Pin); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCS_TIIoHwAb_DIn_Impl_GetPin CIoHwAb_Impl_GetPin
#  define RTE_START_SEC_TRIPMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
//FUNC(void, RTE_TRIPMDL_APPL_CODE) CTripMdl_DcmExt_ClearDTE(P2VAR(uint8, AUTOMATIC, RTE_TRIPMDL_APPL_VAR) flag); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_TRIPMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCS_Trip_to_Dcmext_clag_tc_dcm_clear_dte_E2(arg1) (CTripMdl_DcmExt_ClearDTE(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
//FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) CIoHwAb_Impl_GetVoltage(EIOVoltageInId Id, P2VAR(TIOAppData, AUTOMATIC, RTE_IOHWAB_APPL_VAR) Voltage); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_tiCS_TIIoHwAb_AIn_Impl_GetVoltage CIoHwAb_Impl_GetVoltage
#  define RTE_START_SEC_TMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
//FUNC(void, RTE_TMEXT_APPL_CODE) TmExt_Timer_IsElapsed(HTimer hTimer, uint32 Timeout, P2VAR(boolean, AUTOMATIC, RTE_TMEXT_APPL_VAR) IsElapsed); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_TMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_tiCS_TITmExt_TmExt_Timer_IsElapsed(arg1, arg2, arg3) (TmExt_Timer_IsElapsed(arg1, arg2, arg3), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_TMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
//FUNC(void, RTE_TMEXT_APPL_CODE) TmExt_Timer_Start(HTimer hTimer); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_TMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_tiCS_TITmExt_TmExt_Timer_Start(arg1) (TmExt_Timer_Start(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_TMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
//FUNC(void, RTE_TMEXT_APPL_CODE) TmExt_Timer_Stop(HTimer hTimer); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_TMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_tiCS_TITmExt_TmExt_Timer_Stop(arg1) (TmExt_Timer_Stop(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define DcmExt_START_SEC_CODE
//# include "DcmExt_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CDcmExt_GetCurrentSessionType CDcmExt_GetCurrentSessionType
#  define RTE_RUNNABLE_dummy dummy
# endif

//FUNC(void, DcmExt_CODE) CDcmExt_GetCurrentSessionType(P2VAR(SessionId, AUTOMATIC, RTE_DCMEXT_APPL_VAR) session); /* PRQA S 0850 */ /* MD_MSR_19.8 */
//FUNC(void, DcmExt_CODE) dummy(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define DcmExt_STOP_SEC_CODE
//# include "DcmExt_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_tiCS_TIIoHwAb_AIn_E_NOT_OK (1U)

#  define RTE_E_tiCS_TIIoHwAb_DIn_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_DCMEXT_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
