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
 *          File:  Rte_NVMExtMdl_Type.h
 *        Config:  Turing.dpa"
 *   ECU-Project:  Cluster
 *
 *     Generator:  MICROSAR RTE Generator Version 4.8.0
 *                 RTE Core Version 1.8.0
 *       License:  Unlimited license CBD1400814 for Visteon Corporation
 *
 *   Description:  Application types header file for SW-C <NVMExtMdl>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_NVMEXTMDL_TYPE_H
# define _RTE_NVMEXTMDL_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef ACTEMP_SET_DISABLE
#   define ACTEMP_SET_DISABLE (0U)
#  endif

#  ifndef ACTEMP_SET_ENABLE
#   define ACTEMP_SET_ENABLE (1U)
#  endif

#  ifndef AUDIO_INFO_DISPLAY_SET_DISABLE
#   define AUDIO_INFO_DISPLAY_SET_DISABLE (0U)
#  endif

#  ifndef AUDIO_INFO_DISPLAY_SET_ENABLE
#   define AUDIO_INFO_DISPLAY_SET_ENABLE (1U)
#  endif

#  ifndef CALENDAR_CLOCK_SET_DISABLE
#   define CALENDAR_CLOCK_SET_DISABLE (0U)
#  endif

#  ifndef CALENDAR_CLOCK_SET_CLOCK
#   define CALENDAR_CLOCK_SET_CLOCK (1U)
#  endif

#  ifndef CALENDAR_CLOCK_SET_CALENDAR
#   define CALENDAR_CLOCK_SET_CALENDAR (2U)
#  endif

#  ifndef CALENDAR_CLOCK_SET_CLOCK_CALENDAR
#   define CALENDAR_CLOCK_SET_CLOCK_CALENDAR (3U)
#  endif

#  ifndef CAMERA_DISPLAY_SET_DISABLE
#   define CAMERA_DISPLAY_SET_DISABLE (0U)
#  endif

#  ifndef CAMERA_DISPLAY_SET_AVM_MODE
#   define CAMERA_DISPLAY_SET_AVM_MODE (1U)
#  endif

#  ifndef CAMERA_DISPLAY_SET_MPC_MODE
#   define CAMERA_DISPLAY_SET_MPC_MODE (2U)
#  endif

#  ifndef CAMERA_DISPLAY_SET_AVMMPC_MODE
#   define CAMERA_DISPLAY_SET_AVMMPC_MODE (3U)
#  endif

#  ifndef CRUISE_CONTROL_SET_DISABLE
#   define CRUISE_CONTROL_SET_DISABLE (0U)
#  endif

#  ifndef CRUISE_CONTROL_SET_ENABLE
#   define CRUISE_CONTROL_SET_ENABLE (1U)
#  endif

#  ifndef CRUISE_CONTROL_SET_ACC
#   define CRUISE_CONTROL_SET_ACC (2U)
#  endif

#  ifndef CRUISE_CONTROL_SET_RESERVED
#   define CRUISE_CONTROL_SET_RESERVED (3U)
#  endif

#  ifndef DRIVER_FATIGUE_WARNING_SET_DISABLE
#   define DRIVER_FATIGUE_WARNING_SET_DISABLE (0U)
#  endif

#  ifndef DRIVER_FATIGUE_WARNING_SET_ENABLE
#   define DRIVER_FATIGUE_WARNING_SET_ENABLE (1U)
#  endif

#  ifndef DVR_DISABLE
#   define DVR_DISABLE (0U)
#  endif

#  ifndef DVR_ENABLE
#   define DVR_ENABLE (1U)
#  endif

#  ifndef eCmpCmd_Init
#   define eCmpCmd_Init (0U)
#  endif

#  ifndef eCmpCmd_DeInit
#   define eCmpCmd_DeInit (1U)
#  endif

#  ifndef eCmpCmd_Activate
#   define eCmpCmd_Activate (2U)
#  endif

#  ifndef eCmpCmd_DeActivate
#   define eCmpCmd_DeActivate (3U)
#  endif

#  ifndef eCmpCmd_Reset
#   define eCmpCmd_Reset (4U)
#  endif

#  ifndef eCmpCmd_ReStart
#   define eCmpCmd_ReStart (5U)
#  endif

#  ifndef eCmpCmd_ExternalCount
#   define eCmpCmd_ExternalCount (6U)
#  endif

#  ifndef eCmpCmd_DiagStart
#   define eCmpCmd_DiagStart (7U)
#  endif

#  ifndef eCmpCmd_DiagStop
#   define eCmpCmd_DiagStop (8U)
#  endif

#  ifndef eCmpCmd_Count
#   define eCmpCmd_Count (9U)
#  endif

#  ifndef ENGINE_SET_A151
#   define ENGINE_SET_A151 (0U)
#  endif

#  ifndef ENGINE_SET_RESERVED
#   define ENGINE_SET_RESERVED (1U)
#  endif

#  ifndef EPS_SET_DISABLE
#   define EPS_SET_DISABLE (0U)
#  endif

#  ifndef EPS_SET_ENABLE
#   define EPS_SET_ENABLE (1U)
#  endif

#  ifndef ESCL_SET_DISABLE
#   define ESCL_SET_DISABLE (0U)
#  endif

#  ifndef ESCL_SET_ENABLE
#   define ESCL_SET_ENABLE (1U)
#  endif

#  ifndef ABS_SET_ENABLE
#   define ABS_SET_ENABLE (0U)
#  endif

#  ifndef ESP_SET_ENABLE
#   define ESP_SET_ENABLE (1U)
#  endif

#  ifndef FUEL_TANK_SET_TYPE1
#   define FUEL_TANK_SET_TYPE1 (0U)
#  endif

#  ifndef FUEL_TANK_SET_TYPE2
#   define FUEL_TANK_SET_TYPE2 (1U)
#  endif

#  ifndef FUEL_TANK_SET_TYPE3
#   define FUEL_TANK_SET_TYPE3 (2U)
#  endif

#  ifndef FUEL_TANK_SET_TYPE4
#   define FUEL_TANK_SET_TYPE4 (3U)
#  endif

#  ifndef FUEL_TANK_SET_RESERVED
#   define FUEL_TANK_SET_RESERVED (4U)
#  endif

#  ifndef GEARBOX_SET_MT_MODE
#   define GEARBOX_SET_MT_MODE (0U)
#  endif

#  ifndef GEARBOX_SET_AT_MODE
#   define GEARBOX_SET_AT_MODE (1U)
#  endif

#  ifndef GEARBOX_SET_CVT_MODE
#   define GEARBOX_SET_CVT_MODE (2U)
#  endif

#  ifndef GEARBOX_SET_RESERVED_MODE
#   define GEARBOX_SET_RESERVED_MODE (3U)
#  endif

#  ifndef SET_NORMAL_GENERATOR_MODE
#   define SET_NORMAL_GENERATOR_MODE (0U)
#  endif

#  ifndef SET_SMART_GENERATOR_MODE
#   define SET_SMART_GENERATOR_MODE (1U)
#  endif

#  ifndef LANGUAGE_SET_CHINESE
#   define LANGUAGE_SET_CHINESE (0U)
#  endif

#  ifndef LANGUAGE_SET_ENGLISH
#   define LANGUAGE_SET_ENGLISH (1U)
#  endif

#  ifndef LANGUAGE_SET_ARAB
#   define LANGUAGE_SET_ARAB (2U)
#  endif

#  ifndef LANGUAGE_SET_RESERVED
#   define LANGUAGE_SET_RESERVED (3U)
#  endif

#  ifndef MAINTENANCE_INTERVAL_SET_5000KM
#   define MAINTENANCE_INTERVAL_SET_5000KM (0U)
#  endif

#  ifndef MAINTENANCE_INTERVAL_SET_7500KM
#   define MAINTENANCE_INTERVAL_SET_7500KM (1U)
#  endif

#  ifndef MAINTENANCE_INTERVAL_SET_RESERVED
#   define MAINTENANCE_INTERVAL_SET_RESERVED (2U)
#  endif

#  ifndef NAVIGATION_DISPLAY_SET_DISABLE
#   define NAVIGATION_DISPLAY_SET_DISABLE (0U)
#  endif

#  ifndef NAVIGATION_DISPLAY_SET_TBT
#   define NAVIGATION_DISPLAY_SET_TBT (1U)
#  endif

#  ifndef NAVIGATION_DISPLAY_SET_LVDS
#   define NAVIGATION_DISPLAY_SET_LVDS (2U)
#  endif

#  ifndef NAVIGATION_DISPLAY_SET_RESERVED
#   define NAVIGATION_DISPLAY_SET_RESERVED (3U)
#  endif

#  ifndef NVM_REQ_OK
#   define NVM_REQ_OK (0U)
#  endif

#  ifndef NVM_REQ_NOT_OK
#   define NVM_REQ_NOT_OK (1U)
#  endif

#  ifndef NVM_REQ_PENDING
#   define NVM_REQ_PENDING (2U)
#  endif

#  ifndef NVM_REQ_INTEGRITY_FAILED
#   define NVM_REQ_INTEGRITY_FAILED (3U)
#  endif

#  ifndef NVM_REQ_BLOCK_SKIPPED
#   define NVM_REQ_BLOCK_SKIPPED (4U)
#  endif

#  ifndef NVM_REQ_NV_INVALIDATED
#   define NVM_REQ_NV_INVALIDATED (5U)
#  endif

#  ifndef NVM_REQ_CANCELED
#   define NVM_REQ_CANCELED (6U)
#  endif

#  ifndef NVM_REQ_REDUNDANCY_FAILED
#   define NVM_REQ_REDUNDANCY_FAILED (7U)
#  endif

#  ifndef NVM_REQ_RESTORED_FROM_ROM
#   define NVM_REQ_RESTORED_FROM_ROM (8U)
#  endif

#  ifndef NVM_REQ_OK
#   define NVM_REQ_OK (0U)
#  endif

#  ifndef NVM_REQ_NOT_OK
#   define NVM_REQ_NOT_OK (1U)
#  endif

#  ifndef NVM_REQ_PENDING
#   define NVM_REQ_PENDING (2U)
#  endif

#  ifndef NVM_REQ_INTEGRITY_FAILED
#   define NVM_REQ_INTEGRITY_FAILED (3U)
#  endif

#  ifndef NVM_REQ_BLOCK_SKIPPED
#   define NVM_REQ_BLOCK_SKIPPED (4U)
#  endif

#  ifndef NVM_REQ_NV_INVALIDATED
#   define NVM_REQ_NV_INVALIDATED (5U)
#  endif

#  ifndef NVM_REQ_CANCELED
#   define NVM_REQ_CANCELED (6U)
#  endif

#  ifndef NVM_REQ_REDUNDANCY_FAILED
#   define NVM_REQ_REDUNDANCY_FAILED (7U)
#  endif

#  ifndef NVM_REQ_RESTORED_FROM_ROM
#   define NVM_REQ_RESTORED_FROM_ROM (8U)
#  endif

#  ifndef NVM_READ_BLOCK
#   define NVM_READ_BLOCK (6U)
#  endif

#  ifndef NVM_WRITE_BLOCK
#   define NVM_WRITE_BLOCK (7U)
#  endif

#  ifndef NVM_RESTORE_BLOCK_DEFAULTS
#   define NVM_RESTORE_BLOCK_DEFAULTS (8U)
#  endif

#  ifndef NVM_ERASE_BLOCK
#   define NVM_ERASE_BLOCK (9U)
#  endif

#  ifndef NVM_INVALIDATE_NV_BLOCK
#   define NVM_INVALIDATE_NV_BLOCK (11U)
#  endif

#  ifndef NVM_READ_ALL
#   define NVM_READ_ALL (12U)
#  endif

#  ifndef NVM_READ_BLOCK
#   define NVM_READ_BLOCK (6U)
#  endif

#  ifndef NVM_WRITE_BLOCK
#   define NVM_WRITE_BLOCK (7U)
#  endif

#  ifndef NVM_RESTORE_BLOCK_DEFAULTS
#   define NVM_RESTORE_BLOCK_DEFAULTS (8U)
#  endif

#  ifndef NVM_ERASE_BLOCK
#   define NVM_ERASE_BLOCK (9U)
#  endif

#  ifndef NVM_INVALIDATE_NV_BLOCK
#   define NVM_INVALIDATE_NV_BLOCK (11U)
#  endif

#  ifndef NVM_READ_ALL
#   define NVM_READ_ALL (12U)
#  endif

#  ifndef OVERSPEED_ALARM_SET_DISABLE
#   define OVERSPEED_ALARM_SET_DISABLE (0U)
#  endif

#  ifndef OVERSPEED_ALARM_SET_ENABLE
#   define OVERSPEED_ALARM_SET_ENABLE (1U)
#  endif

#  ifndef PARKING_BRAKE_SET_MACHINE_MODE
#   define PARKING_BRAKE_SET_MACHINE_MODE (0U)
#  endif

#  ifndef PARKING_BRAKE_SET_EPB_MODE
#   define PARKING_BRAKE_SET_EPB_MODE (1U)
#  endif

#  ifndef PARKING_BRAKE_SET_AUTOHOLD_MODE
#   define PARKING_BRAKE_SET_AUTOHOLD_MODE (2U)
#  endif

#  ifndef PARKING_BRAKE_SET_RESERVED_MODE
#   define PARKING_BRAKE_SET_RESERVED_MODE (3U)
#  endif

#  ifndef PAS_SET_DISABLE
#   define PAS_SET_DISABLE (0U)
#  endif

#  ifndef PAS_SET_HARD_PAS_MODE
#   define PAS_SET_HARD_PAS_MODE (1U)
#  endif

#  ifndef PAS_SET_CAN_PAS_MODE
#   define PAS_SET_CAN_PAS_MODE (2U)
#  endif

#  ifndef PAS_SET_RESERVED_MODE
#   define PAS_SET_RESERVED_MODE (3U)
#  endif

#  ifndef PEPS_SET_DISABLE
#   define PEPS_SET_DISABLE (0U)
#  endif

#  ifndef PEPS_SET_ENABLE
#   define PEPS_SET_ENABLE (1U)
#  endif

#  ifndef REQUEST_SHIFT_SET_DISABLE
#   define REQUEST_SHIFT_SET_DISABLE (0U)
#  endif

#  ifndef REQUEST_SHIFT_SET_ENABLE
#   define REQUEST_SHIFT_SET_ENABLE (1U)
#  endif

#  ifndef REVERSE_WARNING_SET_DISABLE
#   define REVERSE_WARNING_SET_DISABLE (0U)
#  endif

#  ifndef REVERSE_WARNING_SET_ENABLE
#   define REVERSE_WARNING_SET_ENABLE (1U)
#  endif

#  ifndef SDM_SET_DISABLE
#   define SDM_SET_DISABLE (0U)
#  endif

#  ifndef SDM_SET_ENABLE
#   define SDM_SET_ENABLE (1U)
#  endif

#  ifndef SELF_CHECKING_SET_DISABLE
#   define SELF_CHECKING_SET_DISABLE (0U)
#  endif

#  ifndef SELF_CHECKING_SET_ENABLE
#   define SELF_CHECKING_SET_ENABLE (1U)
#  endif

#  ifndef STARTSTOP_SET_DISABLE
#   define STARTSTOP_SET_DISABLE (0U)
#  endif

#  ifndef STARTSTOP_SET_ENABLE
#   define STARTSTOP_SET_ENABLE (1U)
#  endif

#  ifndef STARTUP_MUSIC_DISABLE
#   define STARTUP_MUSIC_DISABLE (0U)
#  endif

#  ifndef STARTUP_MUSIC_ENABLE
#   define STARTUP_MUSIC_ENABLE (1U)
#  endif

#  ifndef TELEPHONE_INFO_DISPLAY_SET_DISABLE
#   define TELEPHONE_INFO_DISPLAY_SET_DISABLE (0U)
#  endif

#  ifndef TELEPHONE_INFO_DISPLAY_SET_ENABLE
#   define TELEPHONE_INFO_DISPLAY_SET_ENABLE (1U)
#  endif

#  ifndef TPMS_SET_DISABLE
#   define TPMS_SET_DISABLE (0U)
#  endif

#  ifndef TPMS_SET_INDIRECT_MODE
#   define TPMS_SET_INDIRECT_MODE (1U)
#  endif

#  ifndef TPMS_SET_DIRECT_MODE
#   define TPMS_SET_DIRECT_MODE (2U)
#  endif

#  ifndef TPMS_SET_RESERVED_MODE
#   define TPMS_SET_RESERVED_MODE (3U)
#  endif

#  ifndef UNIT_SET_METRIC
#   define UNIT_SET_METRIC (0U)
#  endif

#  ifndef UNIT_SET_ENGLISH
#   define UNIT_SET_ENGLISH (1U)
#  endif

#  ifndef VEHICLE_LOGO_SET_DISABLE
#   define VEHICLE_LOGO_SET_DISABLE (0U)
#  endif

#  ifndef VEHICLE_LOGO_SET_BAIC
#   define VEHICLE_LOGO_SET_BAIC (1U)
#  endif

#  ifndef VEHICLE_LOGO_SET_BAIC_WEIWANG
#   define VEHICLE_LOGO_SET_BAIC_WEIWANG (2U)
#  endif

#  ifndef VEHICLE_LOGO_SET_CHANGHE
#   define VEHICLE_LOGO_SET_CHANGHE (3U)
#  endif

#  ifndef VEHICLE_LOGO_SET_OTHER
#   define VEHICLE_LOGO_SET_OTHER (4U)
#  endif

#  ifndef VEHICLE_MODELS_SET_C40D
#   define VEHICLE_MODELS_SET_C40D (0U)
#  endif

#  ifndef VEHICLE_MODELS_SET_C53F
#   define VEHICLE_MODELS_SET_C53F (1U)
#  endif

#  ifndef VEHICLE_MODELS_SET_C51E
#   define VEHICLE_MODELS_SET_C51E (2U)
#  endif

#  ifndef VEHICLE_MODELS_SET_RESERVED
#   define VEHICLE_MODELS_SET_RESERVED (3U)
#  endif

#  ifndef VEHICLE_TYPE_SET_HATCHBACK_MODE
#   define VEHICLE_TYPE_SET_HATCHBACK_MODE (0U)
#  endif

#  ifndef VEHICLE_TYPE_SET_SEDAN_MODE
#   define VEHICLE_TYPE_SET_SEDAN_MODE (1U)
#  endif

#  ifndef VEHICLE_TYPE_SET_SUV_MODE
#   define VEHICLE_TYPE_SET_SUV_MODE (2U)
#  endif

#  ifndef VEHICLE_TYPE_SET_MPV_MODE
#   define VEHICLE_TYPE_SET_MPV_MODE (3U)
#  endif

#  ifndef WHEEL_POSITION_SET_LEFT
#   define WHEEL_POSITION_SET_LEFT (0U)
#  endif

#  ifndef WHEEL_POSITION_SET_RIGHT
#   define WHEEL_POSITION_SET_RIGHT (1U)
#  endif

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_NVMEXTMDL_TYPE_H */
