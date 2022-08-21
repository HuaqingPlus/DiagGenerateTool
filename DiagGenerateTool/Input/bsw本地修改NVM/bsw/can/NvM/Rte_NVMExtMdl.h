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
 *          File:  Rte_NVMExtMdl.h
 *        Config:  Turing.dpa"
 *   ECU-Project:  Cluster
 *
 *     Generator:  MICROSAR RTE Generator Version 4.8.0
 *                 RTE Core Version 1.8.0
 *       License:  Unlimited license CBD1400814 for Visteon Corporation
 *
 *   Description:  Application header file for SW-C <NVMExtMdl>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_NVMEXTMDL_H
# define _RTE_NVMEXTMDL_H

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

# include "Rte_NVMExtMdl_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(ACTEMP_ENABLE_Type, RTE_VAR_INIT) Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_ACTEMP_ENABLE; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(AUDIO_INFO_DISPLAY_ENABLE_Type, RTE_VAR_INIT) Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_AUDIO_INFO_DISPLAY_ENABLE; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(CALENDAR_CLOCK_VARIETY_Type, RTE_VAR_INIT) Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_CALENDAR_CLOCK_VARIETY; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(CAMERA_DISPLAY_VARIETY_Type, RTE_VAR_INIT) Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_CAMERA_DISPLAY_VARIETY; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(CRUISE_CONTROL_VARIETY_Type, RTE_VAR_INIT) Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_CRUISE_CONTROL_VARIETY; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(DRIVER_FATIGUE_WARNING_ENABLE_Type, RTE_VAR_INIT) Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_DRIVER_FATIGUE_WARNING_ENABLE; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(DVR_Type, RTE_VAR_INIT) Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_DVR_ENABLE; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(ENGINE_VARIETY_Type, RTE_VAR_INIT) Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_ENGINE_VARIETY; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(EPS_ENABLE_Type, RTE_VAR_INIT) Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_EPS_ENABLE; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(ESCL_ENABLE_Type, RTE_VAR_INIT) Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_ESCL_ENABLE; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(ESPABS_ENABLE_Type, RTE_VAR_INIT) Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_ESPABS_ENABLE; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(FUEL_TANK_VARIETY_Type, RTE_VAR_INIT) Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_FUEL_TANK_VARIETY; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(GEAR_BOX_VARIETY_Type, RTE_VAR_INIT) Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_GEAR_BOX_VARIETY; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(GENERATOR_TYPE_VARIETY_Type, RTE_VAR_INIT) Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_GENERATOR_TYPE_VARIETY; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(LANGUAGE_VARIETY_Type, RTE_VAR_INIT) Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_LANGUAGE_VARIETY; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(MAINTENANCE_INTERVAL_VARIETY_Type, RTE_VAR_INIT) Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_MAINTENANCE_INTERVAL_VARIETY; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(NAVIGATION_DISPLAY_VARIETY_Type, RTE_VAR_INIT) Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_NAVIGATION_DISPLAY_VARIETY; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(OVERSPEED_ALARM_ENABLE_Type, RTE_VAR_INIT) Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_OVERSPEED_ALARM_ENABLE; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(PARKING_BRAKE_Type, RTE_VAR_INIT) Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_PARKING_BRAKE_VARIETY; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(PAS_VARIETY_Type, RTE_VAR_INIT) Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_PAS_VARIETY; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(PEPS_ENABLE_Type, RTE_VAR_INIT) Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_PEPS_ENABLE; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(REQUEST_SHIFT_ENABLE_Type, RTE_VAR_INIT) Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_REQUEST_SHIFT_ENABLE; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(REVERSE_WARNING_ENABLE_Type, RTE_VAR_INIT) Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_REVERSE_WARNING_ENABLE; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(SDM_ENABLE_TYPE, RTE_VAR_INIT) Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_SDM_ENABLE; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(SELF_CHECKING_ENABLE_Type, RTE_VAR_INIT) Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_SELF_CHECKING_ENABLE; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(STARTSTOP_ENABLE_Type, RTE_VAR_INIT) Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_STARTSTOP_ENABLE; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(STARTUP_MUSIC_VARIETY_Type, RTE_VAR_INIT) Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_STARTUP_MUSIC_ENABLE; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(TELEPHONE_INFO_DISPLAY_ENABLE_Type, RTE_VAR_INIT) Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_TELEPHONE_INFO_DISPLAY_ENABLE; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(TPMS_VARIETY_Type, RTE_VAR_INIT) Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_TPMS_VARIETY; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UNIT_VARIETY_Type, RTE_VAR_INIT) Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_UNIT_VARIETY; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(VEHICLE_LOGO_VARIETY_Type, RTE_VAR_INIT) Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_VEHICLE_LOGO_VARIETY; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(VEHICLE_MODELS_VARIETY_Type, RTE_VAR_INIT) Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_VEHICLE_MODELS_VARIETY; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(VEHICLE_VARIETY_Type, RTE_VAR_INIT) Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_VEHICLE_VARIETY; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(WHEEL_POSITION_VARIETY_Type, RTE_VAR_INIT) Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_WHEEL_POSITION_VARIETY; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_ACTEMP_ENABLE (0U)
#  define Rte_InitValue_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_AUDIO_INFO_DISPLAY_ENABLE (0U)
#  define Rte_InitValue_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_CALENDAR_CLOCK_VARIETY (0U)
#  define Rte_InitValue_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_CAMERA_DISPLAY_VARIETY (0U)
#  define Rte_InitValue_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_CRUISE_CONTROL_VARIETY (0U)
#  define Rte_InitValue_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_DRIVER_FATIGUE_WARNING_ENABLE (0U)
#  define Rte_InitValue_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_DVR_ENABLE (0U)
#  define Rte_InitValue_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_ENGINE_VARIETY (0U)
#  define Rte_InitValue_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_EPS_ENABLE (0U)
#  define Rte_InitValue_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_ESCL_ENABLE (0U)
#  define Rte_InitValue_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_ESPABS_ENABLE (0U)
#  define Rte_InitValue_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_FUEL_TANK_VARIETY (0U)
#  define Rte_InitValue_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_GEAR_BOX_VARIETY (0U)
#  define Rte_InitValue_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_GENERATOR_TYPE_VARIETY (0U)
#  define Rte_InitValue_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_LANGUAGE_VARIETY (0U)
#  define Rte_InitValue_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_MAINTENANCE_INTERVAL_VARIETY (0U)
#  define Rte_InitValue_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_NAVIGATION_DISPLAY_VARIETY (0U)
#  define Rte_InitValue_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_OVERSPEED_ALARM_ENABLE (0U)
#  define Rte_InitValue_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_PARKING_BRAKE_VARIETY (0U)
#  define Rte_InitValue_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_PAS_VARIETY (0U)
#  define Rte_InitValue_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_PEPS_ENABLE (0U)
#  define Rte_InitValue_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_REQUEST_SHIFT_ENABLE (0U)
#  define Rte_InitValue_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_REVERSE_WARNING_ENABLE (0U)
#  define Rte_InitValue_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_SDM_ENABLE (0U)
#  define Rte_InitValue_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_SELF_CHECKING_ENABLE (0U)
#  define Rte_InitValue_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_STARTSTOP_ENABLE (0U)
#  define Rte_InitValue_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_STARTUP_MUSIC_ENABLE (0U)
#  define Rte_InitValue_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_TELEPHONE_INFO_DISPLAY_ENABLE (0U)
#  define Rte_InitValue_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_TPMS_VARIETY (0U)
#  define Rte_InitValue_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_UNIT_VARIETY (0U)
#  define Rte_InitValue_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_VEHICLE_LOGO_VARIETY (0U)
#  define Rte_InitValue_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_VEHICLE_MODELS_VARIETY (0U)
#  define Rte_InitValue_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_VEHICLE_VARIETY (0U)
#  define Rte_InitValue_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_WHEEL_POSITION_VARIETY (0U)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_NVMExtMdl_NV_Cluster_ODO_Backup_Counter_ODO_Backup_Value(P2VAR(NV_Data_Cluster_ODO_Backup_Counter, AUTOMATIC, RTE_NVMEXTMDL_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_NVMExtMdl_NV_Cluster_Optional_Feature_Configure_Cluster_Feature_Configure_Value(P2VAR(NV_Data_Cluster_Optional_Feature_Configure, AUTOMATIC, RTE_NVMEXTMDL_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_NVMExtMdl_NV_Cluster_Variable_Block_Cluster_Variable_Block(P2VAR(NV_Data_Cluster_Variable_Block, AUTOMATIC, RTE_NVMEXTMDL_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_NVMExtMdl_NV_Dim_NvMOdoData_DimDataSetArray(P2VAR(SDimDataSet, AUTOMATIC, RTE_NVMEXTMDL_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_NVMExtMdl_NV_Dim_NvMOdoData_DimDataSetArray(P2VAR(NVDimDataSetType, AUTOMATIC, RTE_NVMEXTMDL_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_NVMExtMdl_NV_OdoMdl_NvMOdoData_Buffer0_OdoDataSetArray(P2VAR(SOdoDataSet, AUTOMATIC, RTE_NVMEXTMDL_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_NVMExtMdl_NV_OdoMdl_NvMOdoData_Buffer0_OdoDataSetArray(P2VAR(NVOdoDataSetType, AUTOMATIC, RTE_NVMEXTMDL_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_NVMExtMdl_NV_OdoMdl_NvMOdoData_Buffer1_OdoDataSetArray(P2VAR(SOdoDataSet, AUTOMATIC, RTE_NVMEXTMDL_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_NVMExtMdl_NV_OdoMdl_NvMOdoData_Buffer1_OdoDataSetArray(P2VAR(NVOdoDataSetType, AUTOMATIC, RTE_NVMEXTMDL_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_NVMExtMdl_NV_OdoMdl_NvMOdoData_Buffer2_OdoDataSetArray(P2VAR(SOdoDataSet, AUTOMATIC, RTE_NVMEXTMDL_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_NVMExtMdl_NV_OdoMdl_NvMOdoData_Buffer2_OdoDataSetArray(P2VAR(NVOdoDataSetType, AUTOMATIC, RTE_NVMEXTMDL_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_NVMExtMdl_NV_OdoMdl_NvMOdoData_Buffer3_OdoDataSetArray(P2VAR(SOdoDataSet, AUTOMATIC, RTE_NVMEXTMDL_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_NVMExtMdl_NV_OdoMdl_NvMOdoData_Buffer3_OdoDataSetArray(P2VAR(NVOdoDataSetType, AUTOMATIC, RTE_NVMEXTMDL_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_NVMExtMdl_NV_OdoMdl_NvMOdoData_Buffer4_OdoDataSetArray(P2VAR(SOdoDataSet, AUTOMATIC, RTE_NVMEXTMDL_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_NVMExtMdl_NV_OdoMdl_NvMOdoData_Buffer4_OdoDataSetArray(P2VAR(NVOdoDataSetType, AUTOMATIC, RTE_NVMEXTMDL_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_NVMExtMdl_NV_SIAMdl_Reset_Odo_OffSet_Offset_Value(P2VAR(NV_Data_Cluster_SIA_Reset_Odo_OffSet, AUTOMATIC, RTE_NVMEXTMDL_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_NVMExtMdl_NV_SIAMdl_Reset_Odo_OffSet_Store_Value(P2VAR(NV_Data_Cluster_SIA_Reset_Odo_OffSet, AUTOMATIC, RTE_NVMEXTMDL_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_NVMExtMdl_NV_TripMdl_NvMTripBAfeData_TripBAfeDataSetArray(P2VAR(STripBAfeDataSet, AUTOMATIC, RTE_NVMEXTMDL_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_NVMExtMdl_NV_TripMdl_NvMTripBAfeData_TripBAfeDataSetArray(P2VAR(NVTripBAfeDataSetType, AUTOMATIC, RTE_NVMEXTMDL_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_NVMExtMdl_NV_TripMdl_NvMTripBDistData_TripBDistDataSetArray(P2VAR(STripBDistDataSet, AUTOMATIC, RTE_NVMEXTMDL_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_NVMExtMdl_NV_TripMdl_NvMTripBDistData_TripBDistDataSetArray(P2VAR(NVTripBDistDataSetType, AUTOMATIC, RTE_NVMEXTMDL_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_NVMExtMdl_NV_Cluster_Optional_Feature_Configure_Cluster_Feature_Configure_Value(P2CONST(NV_Data_Cluster_Optional_Feature_Configure, AUTOMATIC, RTE_NVMEXTMDL_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_NVMExtMdl_NV_Dim_NvMOdoData_DimDataSetArray(P2CONST(SDimDataSet, AUTOMATIC, RTE_NVMEXTMDL_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_NVMExtMdl_NV_Dim_NvMOdoData_DimDataSetArray(P2CONST(NVDimDataSetType, AUTOMATIC, RTE_NVMEXTMDL_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_NVMExtMdl_NV_OdoMdl_NvMOdoData_Buffer0_OdoDataSetArray(P2CONST(SOdoDataSet, AUTOMATIC, RTE_NVMEXTMDL_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_NVMExtMdl_NV_OdoMdl_NvMOdoData_Buffer0_OdoDataSetArray(P2CONST(NVOdoDataSetType, AUTOMATIC, RTE_NVMEXTMDL_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_NVMExtMdl_NV_OdoMdl_NvMOdoData_Buffer1_OdoDataSetArray(P2CONST(SOdoDataSet, AUTOMATIC, RTE_NVMEXTMDL_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_NVMExtMdl_NV_OdoMdl_NvMOdoData_Buffer1_OdoDataSetArray(P2CONST(NVOdoDataSetType, AUTOMATIC, RTE_NVMEXTMDL_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_NVMExtMdl_NV_OdoMdl_NvMOdoData_Buffer2_OdoDataSetArray(P2CONST(SOdoDataSet, AUTOMATIC, RTE_NVMEXTMDL_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_NVMExtMdl_NV_OdoMdl_NvMOdoData_Buffer2_OdoDataSetArray(P2CONST(NVOdoDataSetType, AUTOMATIC, RTE_NVMEXTMDL_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_NVMExtMdl_NV_OdoMdl_NvMOdoData_Buffer3_OdoDataSetArray(P2CONST(SOdoDataSet, AUTOMATIC, RTE_NVMEXTMDL_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_NVMExtMdl_NV_OdoMdl_NvMOdoData_Buffer3_OdoDataSetArray(P2CONST(NVOdoDataSetType, AUTOMATIC, RTE_NVMEXTMDL_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_NVMExtMdl_NV_OdoMdl_NvMOdoData_Buffer4_OdoDataSetArray(P2CONST(SOdoDataSet, AUTOMATIC, RTE_NVMEXTMDL_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_NVMExtMdl_NV_OdoMdl_NvMOdoData_Buffer4_OdoDataSetArray(P2CONST(NVOdoDataSetType, AUTOMATIC, RTE_NVMEXTMDL_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_NVMExtMdl_NV_SIAMdl_Reset_Odo_OffSet_Offset_Value(P2CONST(NV_Data_Cluster_SIA_Reset_Odo_OffSet, AUTOMATIC, RTE_NVMEXTMDL_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_NVMExtMdl_NV_SIAMdl_Reset_Odo_OffSet_Store_Value(P2CONST(NV_Data_Cluster_SIA_Reset_Odo_OffSet, AUTOMATIC, RTE_NVMEXTMDL_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_NVMExtMdl_NV_TripMdl_NvMTripBAfeData_TripBAfeDataSetArray(P2CONST(STripBAfeDataSet, AUTOMATIC, RTE_NVMEXTMDL_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_NVMExtMdl_NV_TripMdl_NvMTripBAfeData_TripBAfeDataSetArray(P2CONST(NVTripBAfeDataSetType, AUTOMATIC, RTE_NVMEXTMDL_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_NVMExtMdl_NV_TripMdl_NvMTripBDistData_TripBDistDataSetArray(P2CONST(STripBDistDataSet, AUTOMATIC, RTE_NVMEXTMDL_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_NVMExtMdl_NV_TripMdl_NvMTripBDistData_TripBDistDataSetArray(P2CONST(NVTripBDistDataSetType, AUTOMATIC, RTE_NVMEXTMDL_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_NV_Cluster_ODO_Backup_Counter_ODO_Backup_Value Rte_Read_NVMExtMdl_NV_Cluster_ODO_Backup_Counter_ODO_Backup_Value
#  define Rte_Read_NV_Cluster_Optional_Feature_Configure_Cluster_Feature_Configure_Value Rte_Read_NVMExtMdl_NV_Cluster_Optional_Feature_Configure_Cluster_Feature_Configure_Value
#  define Rte_Read_NV_Cluster_Variable_Block_Cluster_Variable_Block Rte_Read_NVMExtMdl_NV_Cluster_Variable_Block_Cluster_Variable_Block
#  define Rte_Read_NV_Dim_NvMOdoData_DimDataSetArray Rte_Read_NVMExtMdl_NV_Dim_NvMOdoData_DimDataSetArray
#  define Rte_Read_NV_OdoMdl_NvMOdoData_Buffer0_OdoDataSetArray Rte_Read_NVMExtMdl_NV_OdoMdl_NvMOdoData_Buffer0_OdoDataSetArray
#  define Rte_Read_NV_OdoMdl_NvMOdoData_Buffer1_OdoDataSetArray Rte_Read_NVMExtMdl_NV_OdoMdl_NvMOdoData_Buffer1_OdoDataSetArray
#  define Rte_Read_NV_OdoMdl_NvMOdoData_Buffer2_OdoDataSetArray Rte_Read_NVMExtMdl_NV_OdoMdl_NvMOdoData_Buffer2_OdoDataSetArray
#  define Rte_Read_NV_OdoMdl_NvMOdoData_Buffer3_OdoDataSetArray Rte_Read_NVMExtMdl_NV_OdoMdl_NvMOdoData_Buffer3_OdoDataSetArray
#  define Rte_Read_NV_OdoMdl_NvMOdoData_Buffer4_OdoDataSetArray Rte_Read_NVMExtMdl_NV_OdoMdl_NvMOdoData_Buffer4_OdoDataSetArray
#  define Rte_Read_NV_SIAMdl_Reset_Odo_OffSet_Offset_Value Rte_Read_NVMExtMdl_NV_SIAMdl_Reset_Odo_OffSet_Offset_Value
#  define Rte_Read_NV_SIAMdl_Reset_Odo_OffSet_Store_Value Rte_Read_NVMExtMdl_NV_SIAMdl_Reset_Odo_OffSet_Store_Value
#  define Rte_Read_NV_TripMdl_NvMTripBAfeData_TripBAfeDataSetArray Rte_Read_NVMExtMdl_NV_TripMdl_NvMTripBAfeData_TripBAfeDataSetArray
#  define Rte_Read_NV_TripMdl_NvMTripBDistData_TripBDistDataSetArray Rte_Read_NVMExtMdl_NV_TripMdl_NvMTripBDistData_TripBDistDataSetArray


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_NV_Cluster_Optional_Feature_Configure_Cluster_Feature_Configure_Value Rte_Write_NVMExtMdl_NV_Cluster_Optional_Feature_Configure_Cluster_Feature_Configure_Value
#  define Rte_Write_NV_Dim_NvMOdoData_DimDataSetArray Rte_Write_NVMExtMdl_NV_Dim_NvMOdoData_DimDataSetArray
#  define Rte_Write_NV_OdoMdl_NvMOdoData_Buffer0_OdoDataSetArray Rte_Write_NVMExtMdl_NV_OdoMdl_NvMOdoData_Buffer0_OdoDataSetArray
#  define Rte_Write_NV_OdoMdl_NvMOdoData_Buffer1_OdoDataSetArray Rte_Write_NVMExtMdl_NV_OdoMdl_NvMOdoData_Buffer1_OdoDataSetArray
#  define Rte_Write_NV_OdoMdl_NvMOdoData_Buffer2_OdoDataSetArray Rte_Write_NVMExtMdl_NV_OdoMdl_NvMOdoData_Buffer2_OdoDataSetArray
#  define Rte_Write_NV_OdoMdl_NvMOdoData_Buffer3_OdoDataSetArray Rte_Write_NVMExtMdl_NV_OdoMdl_NvMOdoData_Buffer3_OdoDataSetArray
#  define Rte_Write_NV_OdoMdl_NvMOdoData_Buffer4_OdoDataSetArray Rte_Write_NVMExtMdl_NV_OdoMdl_NvMOdoData_Buffer4_OdoDataSetArray
#  define Rte_Write_NV_SIAMdl_Reset_Odo_OffSet_Offset_Value Rte_Write_NVMExtMdl_NV_SIAMdl_Reset_Odo_OffSet_Offset_Value
#  define Rte_Write_NV_SIAMdl_Reset_Odo_OffSet_Store_Value Rte_Write_NVMExtMdl_NV_SIAMdl_Reset_Odo_OffSet_Store_Value
#  define Rte_Write_NV_TripMdl_NvMTripBAfeData_TripBAfeDataSetArray Rte_Write_NVMExtMdl_NV_TripMdl_NvMTripBAfeData_TripBAfeDataSetArray
#  define Rte_Write_NV_TripMdl_NvMTripBDistData_TripBDistDataSetArray Rte_Write_NVMExtMdl_NV_TripMdl_NvMTripBDistData_TripBDistDataSetArray
#  define Rte_Write_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_ACTEMP_ENABLE Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_ACTEMP_ENABLE
#  define Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_ACTEMP_ENABLE(data) (Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_ACTEMP_ENABLE = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_AUDIO_INFO_DISPLAY_ENABLE Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_AUDIO_INFO_DISPLAY_ENABLE
#  define Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_AUDIO_INFO_DISPLAY_ENABLE(data) (Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_AUDIO_INFO_DISPLAY_ENABLE = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_CALENDAR_CLOCK_VARIETY Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_CALENDAR_CLOCK_VARIETY
#  define Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_CALENDAR_CLOCK_VARIETY(data) (Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_CALENDAR_CLOCK_VARIETY = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_CAMERA_DISPLAY_VARIETY Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_CAMERA_DISPLAY_VARIETY
#  define Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_CAMERA_DISPLAY_VARIETY(data) (Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_CAMERA_DISPLAY_VARIETY = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_CRUISE_CONTROL_VARIETY Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_CRUISE_CONTROL_VARIETY
#  define Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_CRUISE_CONTROL_VARIETY(data) (Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_CRUISE_CONTROL_VARIETY = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_DRIVER_FATIGUE_WARNING_ENABLE Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_DRIVER_FATIGUE_WARNING_ENABLE
#  define Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_DRIVER_FATIGUE_WARNING_ENABLE(data) (Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_DRIVER_FATIGUE_WARNING_ENABLE = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_DVR_ENABLE Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_DVR_ENABLE
#  define Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_DVR_ENABLE(data) (Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_DVR_ENABLE = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_ENGINE_VARIETY Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_ENGINE_VARIETY
#  define Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_ENGINE_VARIETY(data) (Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_ENGINE_VARIETY = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_EPS_ENABLE Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_EPS_ENABLE
#  define Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_EPS_ENABLE(data) (Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_EPS_ENABLE = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_ESCL_ENABLE Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_ESCL_ENABLE
#  define Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_ESCL_ENABLE(data) (Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_ESCL_ENABLE = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_ESPABS_ENABLE Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_ESPABS_ENABLE
#  define Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_ESPABS_ENABLE(data) (Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_ESPABS_ENABLE = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_FUEL_TANK_VARIETY Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_FUEL_TANK_VARIETY
#  define Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_FUEL_TANK_VARIETY(data) (Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_FUEL_TANK_VARIETY = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_GEAR_BOX_VARIETY Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_GEAR_BOX_VARIETY
#  define Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_GEAR_BOX_VARIETY(data) (Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_GEAR_BOX_VARIETY = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_GENERATOR_TYPE_VARIETY Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_GENERATOR_TYPE_VARIETY
#  define Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_GENERATOR_TYPE_VARIETY(data) (Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_GENERATOR_TYPE_VARIETY = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_LANGUAGE_VARIETY Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_LANGUAGE_VARIETY
#  define Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_LANGUAGE_VARIETY(data) (Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_LANGUAGE_VARIETY = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_MAINTENANCE_INTERVAL_VARIETY Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_MAINTENANCE_INTERVAL_VARIETY
#  define Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_MAINTENANCE_INTERVAL_VARIETY(data) (Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_MAINTENANCE_INTERVAL_VARIETY = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_NAVIGATION_DISPLAY_VARIETY Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_NAVIGATION_DISPLAY_VARIETY
#  define Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_NAVIGATION_DISPLAY_VARIETY(data) (Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_NAVIGATION_DISPLAY_VARIETY = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_OVERSPEED_ALARM_ENABLE Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_OVERSPEED_ALARM_ENABLE
#  define Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_OVERSPEED_ALARM_ENABLE(data) (Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_OVERSPEED_ALARM_ENABLE = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_PARKING_BRAKE_VARIETY Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_PARKING_BRAKE_VARIETY
#  define Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_PARKING_BRAKE_VARIETY(data) (Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_PARKING_BRAKE_VARIETY = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_PAS_VARIETY Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_PAS_VARIETY
#  define Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_PAS_VARIETY(data) (Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_PAS_VARIETY = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_PEPS_ENABLE Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_PEPS_ENABLE
#  define Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_PEPS_ENABLE(data) (Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_PEPS_ENABLE = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_REQUEST_SHIFT_ENABLE Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_REQUEST_SHIFT_ENABLE
#  define Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_REQUEST_SHIFT_ENABLE(data) (Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_REQUEST_SHIFT_ENABLE = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_REVERSE_WARNING_ENABLE Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_REVERSE_WARNING_ENABLE
#  define Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_REVERSE_WARNING_ENABLE(data) (Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_REVERSE_WARNING_ENABLE = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_SDM_ENABLE Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_SDM_ENABLE
#  define Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_SDM_ENABLE(data) (Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_SDM_ENABLE = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_SELF_CHECKING_ENABLE Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_SELF_CHECKING_ENABLE
#  define Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_SELF_CHECKING_ENABLE(data) (Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_SELF_CHECKING_ENABLE = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_STARTSTOP_ENABLE Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_STARTSTOP_ENABLE
#  define Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_STARTSTOP_ENABLE(data) (Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_STARTSTOP_ENABLE = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_STARTUP_MUSIC_ENABLE Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_STARTUP_MUSIC_ENABLE
#  define Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_STARTUP_MUSIC_ENABLE(data) (Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_STARTUP_MUSIC_ENABLE = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_TELEPHONE_INFO_DISPLAY_ENABLE Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_TELEPHONE_INFO_DISPLAY_ENABLE
#  define Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_TELEPHONE_INFO_DISPLAY_ENABLE(data) (Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_TELEPHONE_INFO_DISPLAY_ENABLE = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_TPMS_VARIETY Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_TPMS_VARIETY
#  define Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_TPMS_VARIETY(data) (Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_TPMS_VARIETY = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_UNIT_VARIETY Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_UNIT_VARIETY
#  define Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_UNIT_VARIETY(data) (Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_UNIT_VARIETY = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_VEHICLE_LOGO_VARIETY Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_VEHICLE_LOGO_VARIETY
#  define Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_VEHICLE_LOGO_VARIETY(data) (Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_VEHICLE_LOGO_VARIETY = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_VEHICLE_MODELS_VARIETY Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_VEHICLE_MODELS_VARIETY
#  define Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_VEHICLE_MODELS_VARIETY(data) (Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_VEHICLE_MODELS_VARIETY = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_VEHICLE_VARIETY Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_VEHICLE_VARIETY
#  define Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_VEHICLE_VARIETY(data) (Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_VEHICLE_VARIETY = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_WHEEL_POSITION_VARIETY Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_WHEEL_POSITION_VARIETY
#  define Rte_Write_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_WHEEL_POSITION_VARIETY(data) (Rte_NVMExtMdl_ppSR_pNVMExtMdl_TINVMExtMdl_Cluster_Optional_Configure_WHEEL_POSITION_VARIETY = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_DIMDERATEMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_DIMDERATEMDL_APPL_CODE) Sp_DimDataSet_NvMNotifyJobFinished_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DIMDERATEMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCS_Dim_TINVMMdl_NvMNotifyJobFinished_NvMNotifyJobFinished(arg1, arg2) (Sp_DimDataSet_NvMNotifyJobFinished_JobFinished(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_SIAMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_SIAMDL_APPL_CODE) SIAMdl_Optional_NvMNotifyJobFinished_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_SIAMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCS_TINVMMdl_SIA_Optional_NvMNotifyJobFinished_NvMNotifyJobFinished(arg1, arg2) (SIAMdl_Optional_NvMNotifyJobFinished_JobFinished(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_SIAMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_SIAMDL_APPL_CODE) SIAMdl_Reset_NvMNotifyJobFinished_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_SIAMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCS_TINVMMdl_SIA_Retset_NvMNotifyJobFinished_NvMNotifyJobFinished(arg1, arg2) (SIAMdl_Reset_NvMNotifyJobFinished_JobFinished(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_ODOMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_ODOMDL_APPL_CODE) OdoLogicalMdl_OdoResetOffSet_NvMNotifyJobFinished_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_ODOMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCS_TIOdoLogicalMdl_OdoResetOffSet_NvMNotifyJobFinished_NvMNotifyJobFinished(arg1, arg2) (OdoLogicalMdl_OdoResetOffSet_NvMNotifyJobFinished_JobFinished(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_ODOMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_ODOMDL_APPL_CODE) Sp_OdoDataSet_NvMNotifyJobFinished_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_ODOMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCS_TIOdoMdl_NvMNotifyJobFinished_NvMNotifyJobFinished(arg1, arg2) (Sp_OdoDataSet_NvMNotifyJobFinished_JobFinished(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_SIAMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_SIAMDL_APPL_CODE) SIAMdl_SIAMAINTENCE_NvMNotifyJobFinished_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_SIAMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCS_TISIAMdl_SIAMAINTENCE_NvMNotifyJobFinished_NvMNotifyJobFinished(arg1, arg2) (SIAMdl_SIAMAINTENCE_NvMNotifyJobFinished_JobFinished(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_TRIPMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_TRIPMDL_APPL_CODE) triBAfe_NvMNotifyJobFinished_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_TRIPMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCS_tripBAfe_TINVMMdl_NvMNotifyJobFinished_NvMNotifyJobFinished(arg1, arg2) (triBAfe_NvMNotifyJobFinished_JobFinished(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_TRIPMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_TRIPMDL_APPL_CODE) triBDist_NvMNotifyJobFinished_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_TRIPMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCS_tripBDist_TINVMMdl_NvMNotifyJobFinished_NvMNotifyJobFinished(arg1, arg2) (triBDist_NvMNotifyJobFinished_JobFinished(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define NVMExtMdl_START_SEC_CODE
# include "NVMExtMdl_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CNVMExtMdl_Impl_MainFunction CNVMExtMdl_Impl_MainFunction
#  define RTE_RUNNABLE_CNVMExtMdl_Impl_OnCommand CNVMExtMdl_Impl_OnCommand
#  define RTE_RUNNABLE_Sp_NvMNotifyJobFinished_Cluster_ODO_Backup_Counter Sp_NvMNotifyJobFinished_Cluster_ODO_Backup_Counter
#  define RTE_RUNNABLE_Sp_NvMNotifyJobFinished_Cluster_Optional_Configure Sp_NvMNotifyJobFinished_Cluster_Optional_Configure
#  define RTE_RUNNABLE_Sp_NvMNotifyJobFinished_Cluster_SIAResetOffset Sp_NvMNotifyJobFinished_Cluster_SIAResetOffset
#  define RTE_RUNNABLE_Sp_NvMNotifyJobFinished_Cluster_Variable_Block Sp_NvMNotifyJobFinished_Cluster_Variable_Block
#  define RTE_RUNNABLE_Sp_NvMNotifyJobFinished_JobFinished_Dim Sp_NvMNotifyJobFinished_JobFinished_Dim
#  define RTE_RUNNABLE_Sp_NvMNotifyJobFinished_JobFinished_OdoMdl_Buffer0 Sp_NvMNotifyJobFinished_JobFinished_OdoMdl_Buffer0
#  define RTE_RUNNABLE_Sp_NvMNotifyJobFinished_JobFinished_OdoMdl_Buffer1 Sp_NvMNotifyJobFinished_JobFinished_OdoMdl_Buffer1
#  define RTE_RUNNABLE_Sp_NvMNotifyJobFinished_JobFinished_OdoMdl_Buffer2 Sp_NvMNotifyJobFinished_JobFinished_OdoMdl_Buffer2
#  define RTE_RUNNABLE_Sp_NvMNotifyJobFinished_JobFinished_OdoMdl_Buffer3 Sp_NvMNotifyJobFinished_JobFinished_OdoMdl_Buffer3
#  define RTE_RUNNABLE_Sp_NvMNotifyJobFinished_JobFinished_OdoMdl_Buffer4 Sp_NvMNotifyJobFinished_JobFinished_OdoMdl_Buffer4
#  define RTE_RUNNABLE_Sp_NvMNotifyJobFinished_JobFinished_TripBAfe Sp_NvMNotifyJobFinished_JobFinished_TripBAfe
#  define RTE_RUNNABLE_Sp_NvMNotifyJobFinished_JobFinished_TripBDist Sp_NvMNotifyJobFinished_JobFinished_TripBDist
#  define RTE_RUNNABLE_Sp_OdoResetOffSet_NvMNotifyJobFinished_JobFinished Sp_OdoResetOffSet_NvMNotifyJobFinished_JobFinished
#  define RTE_RUNNABLE_Sp_SIAMAINTENCE_NvMNotifyJobFinished_JobFinished Sp_SIAMAINTENCE_NvMNotifyJobFinished_JobFinished
# endif

FUNC(void, NVMExtMdl_CODE) CNVMExtMdl_Impl_MainFunction(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, NVMExtMdl_CODE) CNVMExtMdl_Impl_OnCommand(ECmpCmd cmd); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, NVMExtMdl_CODE) Sp_NvMNotifyJobFinished_Cluster_ODO_Backup_Counter(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, NVMExtMdl_CODE) Sp_NvMNotifyJobFinished_Cluster_Optional_Configure(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, NVMExtMdl_CODE) Sp_NvMNotifyJobFinished_Cluster_SIAResetOffset(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, NVMExtMdl_CODE) Sp_NvMNotifyJobFinished_Cluster_Variable_Block(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, NVMExtMdl_CODE) Sp_NvMNotifyJobFinished_JobFinished_Dim(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, NVMExtMdl_CODE) Sp_NvMNotifyJobFinished_JobFinished_OdoMdl_Buffer0(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, NVMExtMdl_CODE) Sp_NvMNotifyJobFinished_JobFinished_OdoMdl_Buffer1(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, NVMExtMdl_CODE) Sp_NvMNotifyJobFinished_JobFinished_OdoMdl_Buffer2(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, NVMExtMdl_CODE) Sp_NvMNotifyJobFinished_JobFinished_OdoMdl_Buffer3(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, NVMExtMdl_CODE) Sp_NvMNotifyJobFinished_JobFinished_OdoMdl_Buffer4(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, NVMExtMdl_CODE) Sp_NvMNotifyJobFinished_JobFinished_TripBAfe(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, NVMExtMdl_CODE) Sp_NvMNotifyJobFinished_JobFinished_TripBDist(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, NVMExtMdl_CODE) Sp_OdoResetOffSet_NvMNotifyJobFinished_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, NVMExtMdl_CODE) Sp_SIAMAINTENCE_NvMNotifyJobFinished_JobFinished(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define NVMExtMdl_STOP_SEC_CODE
# include "NVMExtMdl_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_tiCS_TISystem_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_NVMEXTMDL_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
