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
 *          File:  Rte_DcmExt_Type.h
 *        Config:  Turing.dpa"
 *   ECU-Project:  Cluster
 *
 *     Generator:  MICROSAR RTE Generator Version 4.8.0
 *                 RTE Core Version 1.8.0
 *       License:  Unlimited license CBD1400814 for Visteon Corporation
 *
 *   Description:  Application types header file for SW-C <DcmExt>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_DCMEXT_TYPE_H
# define _RTE_DCMEXT_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/



#  ifndef eIOPinInId_MDI_IGN_INPUT
#   define eIOPinInId_MDI_IGN_INPUT (0U)
#  endif

#  ifndef eIOPinInId_MDI_CHARGE_SW
#   define eIOPinInId_MDI_CHARGE_SW (1U)
#  endif

#  ifndef eIOPinInId_MDI_OIL_PRESSURE_SW
#   define eIOPinInId_MDI_OIL_PRESSURE_SW (2U)
#  endif

#  ifndef eIOPinInId_MDI_BRAKE_OIL_SW
#   define eIOPinInId_MDI_BRAKE_OIL_SW (3U)
#  endif

#  ifndef eIOPinInId_MDI_PKB_SW
#   define eIOPinInId_MDI_PKB_SW (4U)
#  endif

#  ifndef eIOPinInId_MDI_SEATBELT_SW
#   define eIOPinInId_MDI_SEATBELT_SW (5U)
#  endif

#  ifndef eIOPinInId_MDI_AIRBAG_SW
#   define eIOPinInId_MDI_AIRBAG_SW (6U)
#  endif

#  ifndef eIOPinInId_Count
#   define eIOPinInId_Count (7U)
#  endif

#  ifndef eIOVoltageInId_MAI_BAT
#   define eIOVoltageInId_MAI_BAT (0)
#  endif

#  ifndef eIOVoltageInId_MAI_PASSENGER_SEATBELT
#   define eIOVoltageInId_MAI_PASSENGER_SEATBELT (1)
#  endif

#  ifndef eIOVoltageInId_MAI_FUEL
#   define eIOVoltageInId_MAI_FUEL (2)
#  endif

#  ifndef eIOVoltageInId_MAI_P_BAT_C
#   define eIOVoltageInId_MAI_P_BAT_C (3)
#  endif

#  ifndef eIOVoltageInId_MAI_P_BAT_C_1
#   define eIOVoltageInId_MAI_P_BAT_C_1 (4)
#  endif

#  ifndef eIOVoltageInId_TFT_THERMISTOR
#   define eIOVoltageInId_TFT_THERMISTOR (5)
#  endif

#  ifndef eIOVoltageInId_Count
#   define eIOVoltageInId_Count (6)
#  endif

#  ifndef eTimerHandle0
#   define eTimerHandle0 (0U)
#  endif

#  ifndef eNvmExtHandle
#   define eNvmExtHandle (1U)
#  endif

#  ifndef eSndCdd_SleepTimeout_Handle
#   define eSndCdd_SleepTimeout_Handle (2U)
#  endif

#  ifndef eTimerHandle6
#   define eTimerHandle6 (3U)
#  endif

#  ifndef eDcmHandleSecurity
#   define eDcmHandleSecurity (4U)
#  endif

#  ifndef eTimerHandleTftDrv
#   define eTimerHandleTftDrv (5U)
#  endif

#  ifndef eTimerHandleGdtCdd
#   define eTimerHandleGdtCdd (6U)
#  endif

#  ifndef eTimerHandleFuelInvalidWait
#   define eTimerHandleFuelInvalidWait (7U)
#  endif

#  ifndef eTimerHandleFuelMissingWait
#   define eTimerHandleFuelMissingWait (8U)
#  endif

#  ifndef eTimerHandleVehSpdSampleWait
#   define eTimerHandleVehSpdSampleWait (9U)
#  endif

#  ifndef eTimerHandleVehSpdInvalidWait
#   define eTimerHandleVehSpdInvalidWait (10U)
#  endif

#  ifndef eTimerHandleTachSampleWait
#   define eTimerHandleTachSampleWait (11U)
#  endif

#  ifndef eParkBrakeWarnTimer
#   define eParkBrakeWarnTimer (12U)
#  endif

#  ifndef eOilPresTimer
#   define eOilPresTimer (13U)
#  endif

#  ifndef eTimerHandleFuelLevelSampleWait
#   define eTimerHandleFuelLevelSampleWait (14U)
#  endif

#  ifndef eTpmsTimer
#   define eTpmsTimer (15U)
#  endif

#  ifndef eStartStopTTTimer
#   define eStartStopTTTimer (16U)
#  endif

#  ifndef eTimerHandleCoolantMissingWait
#   define eTimerHandleCoolantMissingWait (17U)
#  endif

#  ifndef eTimerHandleLowFuelMissingWait
#   define eTimerHandleLowFuelMissingWait (18U)
#  endif

#  ifndef eTimerHandleLightOnMissingWait
#   define eTimerHandleLightOnMissingWait (19U)
#  endif

#  ifndef eTimerHandleDoorOpenESC2MissingWait
#   define eTimerHandleDoorOpenESC2MissingWait (20U)
#  endif

#  ifndef eTimerHandleScc1MissingWait
#   define eTimerHandleScc1MissingWait (21U)
#  endif

#  ifndef eCallbackTimerOdoMdl
#   define eCallbackTimerOdoMdl (22U)
#  endif

#  ifndef eThrottleTimerOdoMdl
#   define eThrottleTimerOdoMdl (23U)
#  endif

#  ifndef eTimerOdologicalSpdInvalid
#   define eTimerOdologicalSpdInvalid (24U)
#  endif

#  ifndef eTimerHandleGW_TCU1Missing
#   define eTimerHandleGW_TCU1Missing (25U)
#  endif

#  ifndef eTimerCruiseMdl
#   define eTimerCruiseMdl (26U)
#  endif

#  ifndef eTimerSIAMdl
#   define eTimerSIAMdl (27U)
#  endif

#  ifndef eSiaTTTimer
#   define eSiaTTTimer (28U)
#  endif

#  ifndef eTimerSIAMdlTwo
#   define eTimerSIAMdlTwo (29U)
#  endif

#  ifndef eTimerSIAMdlThree
#   define eTimerSIAMdlThree (30U)
#  endif

#  ifndef eTimer_IFE_Spd_Invalid
#   define eTimer_IFE_Spd_Invalid (31U)
#  endif

#  ifndef eTimer_IFE_Fuel_Invalid
#   define eTimer_IFE_Fuel_Invalid (32U)
#  endif

#  ifndef eTimerHandleTripA
#   define eTimerHandleTripA (33U)
#  endif

#  ifndef eTimerHandleTripB
#   define eTimerHandleTripB (34U)
#  endif

#  ifndef eTimer_fuelMiss_2Min
#   define eTimer_fuelMiss_2Min (35U)
#  endif

#  ifndef eTimer_SpeedInValid_1s
#   define eTimer_SpeedInValid_1s (36U)
#  endif

#  ifndef eTimer_InstantFuelInValid_1s
#   define eTimer_InstantFuelInValid_1s (37U)
#  endif

#  ifndef eTimerRstTripMdl
#   define eTimerRstTripMdl (38U)
#  endif

#  ifndef eTimerHandleSpdMissingTripA
#   define eTimerHandleSpdMissingTripA (39U)
#  endif

#  ifndef eTimer10sTripBMdl
#   define eTimer10sTripBMdl (40U)
#  endif

#  ifndef eTimer10sTripAMdl
#   define eTimer10sTripAMdl (41U)
#  endif

#  ifndef eTimerBattmdl_dem5s
#   define eTimerBattmdl_dem5s (42U)
#  endif

#  ifndef eTimerModmdl_dem5s
#   define eTimerModmdl_dem5s (43U)
#  endif

#  ifndef eCrankTimer_5s
#   define eCrankTimer_5s (44U)
#  endif

#  ifndef eTimer_DteRefresh10s
#   define eTimer_DteRefresh10s (45U)
#  endif

#  ifndef eTimerMax
#   define eTimerMax (46U)
#  endif

#  ifndef DEFAULT_SESSION
#   define DEFAULT_SESSION (1U)
#  endif

#  ifndef PROGRAMMING_SESSION
#   define PROGRAMMING_SESSION (2U)
#  endif

#  ifndef EXTENDED_SESSION
#   define EXTENDED_SESSION (3U)
#  endif

#  ifndef EOL_SESSION
#   define EOL_SESSION (4U)
#  endif

#  ifndef eIGN_OFF
#   define eIGN_OFF (1U)
#  endif

#  ifndef eIGN_RUN
#   define eIGN_RUN (2U)
#  endif

#  ifndef eIGN_COUNT
#   define eIGN_COUNT (2U)
#  endif

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_DCMEXT_TYPE_H */
