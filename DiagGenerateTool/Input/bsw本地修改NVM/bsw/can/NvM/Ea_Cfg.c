/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2013. Visteon Corporation owns all rights to           *
* this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right,           *
* under the copyright laws of the United States or those of any              *
* other country that may have jurisdiction, to protect this work             *
* as an unpublished work, in the event of an inadvertent or                  *
* deliberate unauthorized publication. Visteon Corporation also              *
* reserves its rights under all copyright laws to protect this               *
* work as a published work, when appropriate. Those having access            *
* to this work may not copy it, use it, modify it or disclose the            *
* information contained in it without the written authorization              *
* of Visteon Corporation.                                                    *
*                                                                            *
******************************************************************************/
/*****************************************************************************
*  File Name         :  Ea_Cfg.c                                             *
*  Module Short Name :  Ea                                                   *
*  Description       : Generated Configuration file for Ea                   *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS Multi                                              *
* Target Hardware  :                                                         *
*                                                                            *
******************************************************************************/
#ifndef EA_CFG_C
#define EA_CFG_C
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "Ea_Cfg.h"
#include "Nvm_Adapt.h" /* Qiuhuaqing Modify */
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
#define NVBlockDescriptor_ClusterSettings_ADDR 0
#define NVBlockDescriptor_ClusterSettings_SIZE sizeof(NV_Data_ClusterSettings)

#define NVBlockDescriptor_DemPrimary_000_ADDR NVBlockDescriptor_ClusterSettings_ADDR + NVBlockDescriptor_ClusterSettings_SIZE + 2
#define NVBlockDescriptor_DemPrimary_000_SIZE 24

#define NVBlockDescriptor_DemPrimary_001_ADDR NVBlockDescriptor_DemPrimary_000_ADDR + NVBlockDescriptor_DemPrimary_000_SIZE + 2
#define NVBlockDescriptor_DemPrimary_001_SIZE 24

#define NVBlockDescriptor_DemPrimary_002_ADDR NVBlockDescriptor_DemPrimary_001_ADDR + NVBlockDescriptor_DemPrimary_001_SIZE + 2
#define NVBlockDescriptor_DemPrimary_002_SIZE 24

#define NVBlockDescriptor_DemPrimary_003_ADDR NVBlockDescriptor_DemPrimary_002_ADDR + NVBlockDescriptor_DemPrimary_002_SIZE + 2
#define NVBlockDescriptor_DemPrimary_003_SIZE 24

#define NVBlockDescriptor_DemPrimary_004_ADDR NVBlockDescriptor_DemPrimary_003_ADDR + NVBlockDescriptor_DemPrimary_003_SIZE + 2
#define NVBlockDescriptor_DemPrimary_004_SIZE 24

#define NVBlockDescriptor_DemPrimary_005_ADDR NVBlockDescriptor_DemPrimary_004_ADDR + NVBlockDescriptor_DemPrimary_004_SIZE + 2
#define NVBlockDescriptor_DemPrimary_005_SIZE 24

#define NVBlockDescriptor_DemPrimary_006_ADDR NVBlockDescriptor_DemPrimary_005_ADDR + NVBlockDescriptor_DemPrimary_005_SIZE + 2
#define NVBlockDescriptor_DemPrimary_006_SIZE 24

#define NVBlockDescriptor_DemPrimary_007_ADDR NVBlockDescriptor_DemPrimary_006_ADDR + NVBlockDescriptor_DemPrimary_006_SIZE + 2
#define NVBlockDescriptor_DemPrimary_007_SIZE 24

#define NVBlockDescriptor_DemPrimary_008_ADDR NVBlockDescriptor_DemPrimary_007_ADDR + NVBlockDescriptor_DemPrimary_007_SIZE + 2
#define NVBlockDescriptor_DemPrimary_008_SIZE 24

#define NVBlockDescriptor_DemPrimary_009_ADDR NVBlockDescriptor_DemPrimary_008_ADDR + NVBlockDescriptor_DemPrimary_008_SIZE + 2
#define NVBlockDescriptor_DemPrimary_009_SIZE 24

#define NVBlockDescriptor_DemPrimary_010_ADDR NVBlockDescriptor_DemPrimary_009_ADDR + NVBlockDescriptor_DemPrimary_009_SIZE + 2
#define NVBlockDescriptor_DemPrimary_010_SIZE 24

#define NVBlockDescriptor_DemPrimary_011_ADDR NVBlockDescriptor_DemPrimary_010_ADDR + NVBlockDescriptor_DemPrimary_010_SIZE + 2
#define NVBlockDescriptor_DemPrimary_011_SIZE 24

#define NVBlockDescriptor_DemPrimary_012_ADDR NVBlockDescriptor_DemPrimary_011_ADDR + NVBlockDescriptor_DemPrimary_011_SIZE + 2
#define NVBlockDescriptor_DemPrimary_012_SIZE 24

#define NVBlockDescriptor_DemPrimary_013_ADDR NVBlockDescriptor_DemPrimary_012_ADDR + NVBlockDescriptor_DemPrimary_012_SIZE + 2
#define NVBlockDescriptor_DemPrimary_013_SIZE 24

#define NVBlockDescriptor_DemPrimary_014_ADDR NVBlockDescriptor_DemPrimary_013_ADDR + NVBlockDescriptor_DemPrimary_013_SIZE + 2
#define NVBlockDescriptor_DemPrimary_014_SIZE 24

#define NVBlockDescriptor_DemPrimary_015_ADDR NVBlockDescriptor_DemPrimary_014_ADDR + NVBlockDescriptor_DemPrimary_014_SIZE + 2
#define NVBlockDescriptor_DemPrimary_015_SIZE 24

#define NVBlockDescriptor_DemPrimary_016_ADDR NVBlockDescriptor_DemPrimary_015_ADDR + NVBlockDescriptor_DemPrimary_015_SIZE + 2
#define NVBlockDescriptor_DemPrimary_016_SIZE 24

#define NVBlockDescriptor_DemPrimary_017_ADDR NVBlockDescriptor_DemPrimary_016_ADDR + NVBlockDescriptor_DemPrimary_016_SIZE + 2
#define NVBlockDescriptor_DemPrimary_017_SIZE 24

#define NVBlockDescriptor_DemPrimary_018_ADDR NVBlockDescriptor_DemPrimary_017_ADDR + NVBlockDescriptor_DemPrimary_017_SIZE + 2
#define NVBlockDescriptor_DemPrimary_018_SIZE 24

#define NVBlockDescriptor_DemPrimary_019_ADDR NVBlockDescriptor_DemPrimary_018_ADDR + NVBlockDescriptor_DemPrimary_018_SIZE + 2
#define NVBlockDescriptor_DemPrimary_019_SIZE 24

#define NVBlockDescriptor_DemPrimary_020_ADDR NVBlockDescriptor_DemPrimary_019_ADDR + NVBlockDescriptor_DemPrimary_019_SIZE + 2
#define NVBlockDescriptor_DemPrimary_020_SIZE 24

#define NVBlockDescriptor_DemStatusData_ADDR NVBlockDescriptor_DemPrimary_020_ADDR + NVBlockDescriptor_DemPrimary_020_SIZE + 2
#define NVBlockDescriptor_DemStatusData_SIZE 32

#define NVBlockDescriptor_DemAdminData_ADDR NVBlockDescriptor_DemStatusData_ADDR + NVBlockDescriptor_DemStatusData_SIZE + 2
#define NVBlockDescriptor_DemAdminData_SIZE 10

#define NVBlockDescriptor_Odometer_Buffer0_ADDR NVBlockDescriptor_DemAdminData_ADDR + NVBlockDescriptor_DemAdminData_SIZE + 2
#define NVBlockDescriptor_Odometer_Buffer0_SIZE sizeof(NVOdoDataSetType)

#define NVBlockDescriptor_Odometer_Buffer1_ADDR NVBlockDescriptor_Odometer_Buffer0_ADDR + NVBlockDescriptor_Odometer_Buffer0_SIZE + 2
#define NVBlockDescriptor_Odometer_Buffer1_SIZE sizeof(NVOdoDataSetType)

#define NVBlockDescriptor_Odometer_Buffer2_ADDR NVBlockDescriptor_Odometer_Buffer1_ADDR + NVBlockDescriptor_Odometer_Buffer1_SIZE + 2
#define NVBlockDescriptor_Odometer_Buffer2_SIZE sizeof(NVOdoDataSetType)

#define NVBlockDescriptor_Odometer_Buffer3_ADDR NVBlockDescriptor_Odometer_Buffer2_ADDR + NVBlockDescriptor_Odometer_Buffer2_SIZE + 2
#define NVBlockDescriptor_Odometer_Buffer3_SIZE sizeof(NVOdoDataSetType)

#define NVBlockDescriptor_Odometer_Buffer4_ADDR NVBlockDescriptor_Odometer_Buffer3_ADDR + NVBlockDescriptor_Odometer_Buffer3_SIZE + 2
#define NVBlockDescriptor_Odometer_Buffer4_SIZE sizeof(NVOdoDataSetType)

#define NVBlockDescriptor_DimBuffer_ADDR  NVBlockDescriptor_Odometer_Buffer4_ADDR + NVBlockDescriptor_Odometer_Buffer4_SIZE + 2
#define NVBlockDescriptor_DimBuffer_SIZE sizeof(NVDimDataSetType)

#define NVBlockDescriptor_ClusterSIAResetOffset_ADDR NVBlockDescriptor_DimBuffer_ADDR + NVBlockDescriptor_DimBuffer_SIZE + 2
#define NVBlockDescriptor_ClusterSIAResetOffset_SIZE sizeof(NV_Data_Cluster_SIA_Reset_Odo_OffSet)

#define NVBlockDescriptor_Cluster_Optional_Feature_Configure_ADDR NVBlockDescriptor_ClusterSIAResetOffset_ADDR + NVBlockDescriptor_ClusterSIAResetOffset_SIZE + 2
#define NVBlockDescriptor_Cluster_Optional_Feature_Configure_SIZE sizeof(NV_Data_Cluster_Optional_Feature_Configure)

#define NVBlockDescriptor_Cluster_Backup_Odo_Counter_ADDR NVBlockDescriptor_Cluster_Optional_Feature_Configure_ADDR + NVBlockDescriptor_Cluster_Optional_Feature_Configure_SIZE + 2
#define NVBlockDescriptor_Cluster_Backup_Odo_Counter_SIZE sizeof(NV_Data_Cluster_ODO_Backup_Counter)

#define NVBlockDescriptor_TripBDistanceBuffer_ADDR NVBlockDescriptor_Cluster_Backup_Odo_Counter_ADDR + NVBlockDescriptor_Cluster_Backup_Odo_Counter_SIZE + 2
#define NVBlockDescriptor_TripBDistanceBuffer_SIZE sizeof(NVTripBDistDataSetType)

#define NVBlockDescriptor_TripBAfeBuffer_ADDR NVBlockDescriptor_TripBDistanceBuffer_ADDR + NVBlockDescriptor_TripBDistanceBuffer_SIZE + 2
#define NVBlockDescriptor_TripBAfeBuffer_SIZE sizeof(NVTripBAfeDataSetType)

#define NVBlockDescriptor_VehicleSwVersion_ADDR NVBlockDescriptor_TripBAfeBuffer_ADDR + NVBlockDescriptor_TripBAfeBuffer_SIZE + 2
#define NVBlockDescriptor_VehicleSwVersion_SIZE sizeof(NV_ECUSoftwareVersion_2Byte)

#define NVBlockDescriptor_VehicleConfigure_ADDR NVBlockDescriptor_VehicleSwVersion_ADDR + NVBlockDescriptor_VehicleSwVersion_SIZE + 2
#define NVBlockDescriptor_VehicleConfigure_SIZE sizeof(NV_Cluster_Vehicle_Configure)

#define NVBlockDescriptor_FuelLevel_ADDR NVBlockDescriptor_VehicleConfigure_ADDR + NVBlockDescriptor_VehicleConfigure_SIZE + 2
#define NVBlockDescriptor_FuelLevel_SIZE sizeof(NV_ECUFuelLevel_4Byte)

#define NVBlockDescriptor_VehicleVINNumber_ADDR NVBlockDescriptor_FuelLevel_ADDR + NVBlockDescriptor_FuelLevel_SIZE + 2
#define NVBlockDescriptor_VehicleVINNumber_SIZE sizeof(NV_VIN_Number_17Bytes_Type)

#define NVBlockDescriptor_DTE_LastData_ADDR NVBlockDescriptor_VehicleVINNumber_ADDR + NVBlockDescriptor_VehicleVINNumber_SIZE + 2
#define NVBlockDescriptor_DTE_LastData_SIZE sizeof(NV_DTE_LastDataType)

#define NVBlockDescriptor_ECUCfgFlag_ADDR NVBlockDescriptor_DTE_LastData_ADDR + NVBlockDescriptor_DTE_LastData_SIZE + 2
#define NVBlockDescriptor_ECUCfgFlag_SIZE sizeof(NV_ECUCfgFlag_4Byte)

#define NVBlockDescriptor_OdoClearCounts_ADDR NVBlockDescriptor_ECUCfgFlag_ADDR + NVBlockDescriptor_ECUCfgFlag_SIZE + 2
#define NVBlockDescriptor_OdoClearCounts_SIZE sizeof(NV_ECUOdoClearCounts_4Byte)

#define NVBlockDescriptor_Cluster_ProductPartNumber_ADDR NVBlockDescriptor_OdoClearCounts_ADDR + NVBlockDescriptor_OdoClearCounts_SIZE + 2
#define NVBlockDescriptor_Cluster_ProductPartNumber_SIZE sizeof(NV_ECUProductPartNumber_14Byte)

#define NVBlockDescriptor_Cluster_SystemName_ADDR NVBlockDescriptor_Cluster_ProductPartNumber_ADDR + NVBlockDescriptor_Cluster_ProductPartNumber_SIZE + 2
#define NVBlockDescriptor_Cluster_SystemName_SIZE sizeof(NV_ECUSystemName_3Byte)

#define NVBlockDescriptor_Cluster_SupplierIdentifier_ADDR NVBlockDescriptor_Cluster_SystemName_ADDR + NVBlockDescriptor_Cluster_SystemName_SIZE + 2
#define NVBlockDescriptor_Cluster_SupplierIdentifier_SIZE sizeof(NV_ECUSupplierIdentifier_6Byte)

#define NVBlockDescriptor_Cluster_SoftwareVersionNumberOEM_ADDR NVBlockDescriptor_Cluster_SupplierIdentifier_ADDR + NVBlockDescriptor_Cluster_SupplierIdentifier_SIZE + 2
#define NVBlockDescriptor_Cluster_SoftwareVersionNumberOEM_SIZE sizeof(NV_ECUSoftwareVersionNumberOEM_2Byte)

#define NVBlockDescriptor_Cluster_HardwareVersionNumberOEM_ADDR NVBlockDescriptor_Cluster_SoftwareVersionNumberOEM_ADDR + NVBlockDescriptor_Cluster_SoftwareVersionNumberOEM_SIZE + 2
#define NVBlockDescriptor_Cluster_HardwareVersionNumberOEM_SIZE sizeof(NV_ECUHardwareVersionNumberOEM_2Byte)

#define NVBlockDescriptor_Cluster_SoftwareCheck_ADDR NVBlockDescriptor_Cluster_HardwareVersionNumberOEM_ADDR + NVBlockDescriptor_Cluster_HardwareVersionNumberOEM_SIZE + 2
#define NVBlockDescriptor_Cluster_SoftwareCheck_SIZE sizeof(NV_ECUSoftwareCheck_2Byte)

#define NVBlockDescriptor_Cluster_ProgrammingDate_ADDR NVBlockDescriptor_Cluster_SoftwareCheck_ADDR + NVBlockDescriptor_Cluster_SoftwareCheck_SIZE + 2
#define NVBlockDescriptor_Cluster_ProgrammingDate_SIZE sizeof(NV_ECUProgrammingDate_4Byte)

#define NVBlockDescriptor_Cluster_RepairInformation_ADDR NVBlockDescriptor_Cluster_ProgrammingDate_ADDR + NVBlockDescriptor_Cluster_ProgrammingDate_SIZE + 2
#define NVBlockDescriptor_Cluster_RepairInformation_SIZE sizeof(NV_ECURepairInformation_12Byte)

#define NVBlockDescriptor_Cluster_ECUSerialNumber_ADDR NVBlockDescriptor_Cluster_RepairInformation_ADDR + NVBlockDescriptor_Cluster_RepairInformation_SIZE + 2
#define NVBlockDescriptor_Cluster_ECUSerialNumber_SIZE sizeof(NV_ECUSerialNumber_12Byte)

#define NVBlockDescriptor_Cluster_HardwareVersion_ADDR NVBlockDescriptor_Cluster_ECUSerialNumber_ADDR + NVBlockDescriptor_Cluster_ECUSerialNumber_SIZE + 2
#define NVBlockDescriptor_Cluster_HardwareVersion_SIZE sizeof(NV_ECUHardwareVersion_2Byte)

#define NVBlockDescriptor_Cluster_ECUManufacturingDate_ADDR NVBlockDescriptor_Cluster_HardwareVersion_ADDR + NVBlockDescriptor_Cluster_HardwareVersion_SIZE + 2
#define NVBlockDescriptor_Cluster_ECUManufacturingDate_SIZE sizeof(NV_ECUManufacturingDate_3Byte)

#define NVBlockDescriptor_Cluster_DiagTestBlock_ADDR NVBlockDescriptor_Cluster_ECUManufacturingDate_ADDR + NVBlockDescriptor_Cluster_ECUManufacturingDate_SIZE + 2
#define NVBlockDescriptor_Cluster_DiagTestBlock_SIZE sizeof(NV_ECUDiagTestBlock_4Byte)

#define NVBlockDescriptor_Cluster_ResetReason_ADDR NVBlockDescriptor_Cluster_DiagTestBlock_ADDR + NVBlockDescriptor_Cluster_DiagTestBlock_SIZE + 2
#define NVBlockDescriptor_Cluster_ResetReason_SIZE sizeof(NV_ECUResetReason_32Byte)

#define NVBlockDescriptor_ClusterVariableBlock_ADDR NVBlockDescriptor_Cluster_ResetReason_ADDR + NVBlockDescriptor_Cluster_ResetReason_SIZE + 2
#define NVBlockDescriptor_ClusterVariableBlock_SIZE sizeof(NV_Data_Cluster_Variable_Block)

#define NVBlockDescriptor_Cluster_EOLAssemblyDate_ADDR NVBlockDescriptor_ClusterVariableBlock_ADDR + NVBlockDescriptor_ClusterVariableBlock_SIZE + 2
#define NVBlockDescriptor_Cluster_EOLAssemblyDate_SIZE sizeof(NV_Date_SetType)

#define NVBlockDescriptor_Cluster_EOLAssemblyPlantNum_ADDR NVBlockDescriptor_Cluster_EOLAssemblyDate_ADDR + NVBlockDescriptor_Cluster_EOLAssemblyDate_SIZE + 2
#define NVBlockDescriptor_Cluster_EOLAssemblyPlantNum_SIZE sizeof(NV_Assembly_Plant_Num_DataType)

#define NVBlockDescriptor_Cluster_EOLCustomerReference_ADDR NVBlockDescriptor_Cluster_EOLAssemblyPlantNum_ADDR + NVBlockDescriptor_Cluster_EOLAssemblyPlantNum_SIZE + 2
#define NVBlockDescriptor_Cluster_EOLCustomerReference_SIZE sizeof(NV_Customer_Reference_DataType)

#define NVBlockDescriptor_Cluster_EOLEEPROM_ADDR NVBlockDescriptor_Cluster_EOLCustomerReference_ADDR + NVBlockDescriptor_Cluster_EOLCustomerReference_SIZE + 2
#define NVBlockDescriptor_Cluster_EOLEEPROM_SIZE sizeof(NV_EEPROM_SetType)

#define NVBlockDescriptor_Cluster_EOLEquippedPCB_ADDR NVBlockDescriptor_Cluster_EOLEEPROM_ADDR + NVBlockDescriptor_Cluster_EOLEEPROM_SIZE + 2
#define NVBlockDescriptor_Cluster_EOLEquippedPCB_SIZE sizeof(NV_PCB_SetType)

#define NVBlockDescriptor_Cluster_EOLManuDate_ADDR NVBlockDescriptor_Cluster_EOLEquippedPCB_ADDR + NVBlockDescriptor_Cluster_EOLEquippedPCB_SIZE + 2
#define NVBlockDescriptor_Cluster_EOLManuDate_SIZE sizeof(NV_Date_Manu_SetType)

#define NVBlockDescriptor_Cluster_EOLProductCustomization_ADDR NVBlockDescriptor_Cluster_EOLManuDate_ADDR + NVBlockDescriptor_Cluster_EOLManuDate_SIZE + 2
#define NVBlockDescriptor_Cluster_EOLProductCustomization_SIZE sizeof(NV_Product_Customization_DataType)

#define NVBlockDescriptor_Cluster_EOLReservedData_ADDR NVBlockDescriptor_Cluster_EOLProductCustomization_ADDR + NVBlockDescriptor_Cluster_EOLProductCustomization_SIZE + 2
#define NVBlockDescriptor_Cluster_EOLReservedData_SIZE sizeof(NV_Reserved_DataType)

#define NVBlockDescriptor_Cluster_EOLSMDPlantNum_ADDR NVBlockDescriptor_Cluster_EOLReservedData_ADDR + NVBlockDescriptor_Cluster_EOLReservedData_SIZE + 2
#define NVBlockDescriptor_Cluster_EOLSMDPlantNum_SIZE sizeof(NV_SMD_PLant_Num_DataType)

#define NVBlockDescriptor_Cluster_EOLSAVEProduct_ADDR NVBlockDescriptor_Cluster_EOLSMDPlantNum_ADDR + NVBlockDescriptor_Cluster_EOLSMDPlantNum_SIZE + 2
#define NVBlockDescriptor_Cluster_EOLSAVEProduct_SIZE sizeof(NV_SAVE_Product_SetType)

#define NVBlockDescriptor_Cluster_EOLSerialNumberPCB_ADDR NVBlockDescriptor_Cluster_EOLSAVEProduct_ADDR + NVBlockDescriptor_Cluster_EOLSAVEProduct_SIZE + 2
#define NVBlockDescriptor_Cluster_EOLSerialNumberPCB_SIZE sizeof(NV_Serial_PCB_SetType)

#define NVBlockDescriptor_Cluster_EOLSerialNumberProduct_ADDR NVBlockDescriptor_Cluster_EOLSerialNumberPCB_ADDR + NVBlockDescriptor_Cluster_EOLSerialNumberPCB_SIZE + 2
#define NVBlockDescriptor_Cluster_EOLSerialNumberProduct_SIZE sizeof(NV_Serial_Number_Product_SetType)

#define NVBlockDescriptor_Cluster_EOLTracebilityByte_ADDR NVBlockDescriptor_Cluster_EOLSerialNumberProduct_ADDR + NVBlockDescriptor_Cluster_EOLSerialNumberProduct_SIZE + 2
#define NVBlockDescriptor_Cluster_EOLTracebilityByte_SIZE sizeof(NV_Tracebility_Byte_DataType)

#define NVBlockDescriptor_Cluster_SW_Check_ADDR NVBlockDescriptor_Cluster_EOLTracebilityByte_ADDR + NVBlockDescriptor_Cluster_EOLTracebilityByte_SIZE + 2
#define NVBlockDescriptor_Cluster_SW_Check_SIZE sizeof(NV_Software_Check_DataType)

#define NVBlockDescriptor_DTC_AgeTimes_ADDR NVBlockDescriptor_Cluster_SW_Check_ADDR + NVBlockDescriptor_Cluster_SW_Check_SIZE + 2
#define NVBlockDescriptor_DTC_AgeTimes_SIZE sizeof(NV_DTC_AgeTimes_SetType)

#define NVBlockDescriptor_EctConfiguration_ADDR NVBlockDescriptor_DTC_AgeTimes_ADDR + NVBlockDescriptor_DTC_AgeTimes_SIZE + 2
#define NVBlockDescriptor_EctConfiguration_SIZE 8

#define NVBlockDescriptor_Interpolations_ADDR NVBlockDescriptor_EctConfiguration_ADDR + NVBlockDescriptor_EctConfiguration_SIZE + 2
#define NVBlockDescriptor_Interpolations_SIZE 64
/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/


/*****************************************************************************
*                                Globally  accessed Variable Declarations    *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/
const uint8 Ea_DatasetSelectionBits  = 0;

const Ea_ConfigType Ea_Config[EA_NUM_BLOCKS]=
{
    {
        0,                       /* BlockBaseAddress */
        8,                       /* BlockSize        */
        1,                       /* NoOfInstances    */
        2                        /* Bit0 - ImmediateData, Bit1 - Verification Enabled   */
    },
    {
        NVBlockDescriptor_ClusterSettings_ADDR,                       /* BlockBaseAddress */
        NVBlockDescriptor_ClusterSettings_SIZE,                      /* BlockSize        */
        1,                       /* NoOfInstances    */
        2                        /* Bit0 - ImmediateData, Bit1 - Verification Enabled   */
    },
    {
        NVBlockDescriptor_DemPrimary_000_ADDR,                     /* BlockBaseAddress */
        NVBlockDescriptor_DemPrimary_000_SIZE,                       /* BlockSize        */
        1,                       /* NoOfInstances    */
        0                        /* Bit0 - ImmediateData, Bit1 - Verification Enabled   */
    },
    {
        NVBlockDescriptor_DemPrimary_001_ADDR,                     /* BlockBaseAddress */
        NVBlockDescriptor_DemPrimary_001_SIZE,                       /* BlockSize        */
        1,                       /* NoOfInstances    */
        0                        /* Bit0 - ImmediateData, Bit1 - Verification Enabled   */
    },
    {
        NVBlockDescriptor_DemPrimary_002_ADDR,                     /* BlockBaseAddress */
        NVBlockDescriptor_DemPrimary_002_SIZE,                       /* BlockSize        */
        1,                       /* NoOfInstances    */
        0                        /* Bit0 - ImmediateData, Bit1 - Verification Enabled   */
    },
    {
        NVBlockDescriptor_DemPrimary_003_ADDR,                     /* BlockBaseAddress */
        NVBlockDescriptor_DemPrimary_003_SIZE,                       /* BlockSize        */
        1,                       /* NoOfInstances    */
        0                        /* Bit0 - ImmediateData, Bit1 - Verification Enabled   */
    },
    {
        NVBlockDescriptor_DemPrimary_004_ADDR,                     /* BlockBaseAddress */
        NVBlockDescriptor_DemPrimary_004_SIZE,                       /* BlockSize        */
        1,                       /* NoOfInstances    */
        0                        /* Bit0 - ImmediateData, Bit1 - Verification Enabled   */
    },
    {
        NVBlockDescriptor_DemPrimary_005_ADDR,                     /* BlockBaseAddress */
        NVBlockDescriptor_DemPrimary_005_SIZE,                       /* BlockSize        */
        1,                       /* NoOfInstances    */
        0                        /* Bit0 - ImmediateData, Bit1 - Verification Enabled   */
    },
    {
        NVBlockDescriptor_DemPrimary_006_ADDR,                     /* BlockBaseAddress */
        NVBlockDescriptor_DemPrimary_006_SIZE,                       /* BlockSize        */
        1,                       /* NoOfInstances    */
        0                        /* Bit0 - ImmediateData, Bit1 - Verification Enabled   */
    },
    {
        NVBlockDescriptor_DemPrimary_007_ADDR,                     /* BlockBaseAddress */
        NVBlockDescriptor_DemPrimary_007_SIZE,                       /* BlockSize        */
        1,                       /* NoOfInstances    */
        0                        /* Bit0 - ImmediateData, Bit1 - Verification Enabled   */
    },
    {
        NVBlockDescriptor_DemPrimary_008_ADDR,                     /* BlockBaseAddress */
        NVBlockDescriptor_DemPrimary_008_SIZE,                       /* BlockSize        */
        1,                       /* NoOfInstances    */
        0                        /* Bit0 - ImmediateData, Bit1 - Verification Enabled   */
    },
    {
        NVBlockDescriptor_DemPrimary_009_ADDR,                     /* BlockBaseAddress */
        NVBlockDescriptor_DemPrimary_009_SIZE,                       /* BlockSize        */
        1,                       /* NoOfInstances    */
        0                        /* Bit0 - ImmediateData, Bit1 - Verification Enabled   */
    },
    {
        NVBlockDescriptor_DemPrimary_010_ADDR,                     /* BlockBaseAddress */
        NVBlockDescriptor_DemPrimary_010_SIZE,                       /* BlockSize        */
        1,                       /* NoOfInstances    */
        0                        /* Bit0 - ImmediateData, Bit1 - Verification Enabled   */
    },
    {
        NVBlockDescriptor_DemPrimary_011_ADDR,                     /* BlockBaseAddress */
        NVBlockDescriptor_DemPrimary_011_SIZE,                       /* BlockSize        */
        1,                       /* NoOfInstances    */
        0                        /* Bit0 - ImmediateData, Bit1 - Verification Enabled   */
    },
    {
        NVBlockDescriptor_DemPrimary_012_ADDR,                     /* BlockBaseAddress */
        NVBlockDescriptor_DemPrimary_012_SIZE,                       /* BlockSize        */
        1,                       /* NoOfInstances    */
        0                        /* Bit0 - ImmediateData, Bit1 - Verification Enabled   */
    },
    {
        NVBlockDescriptor_DemPrimary_013_ADDR,                     /* BlockBaseAddress */
        NVBlockDescriptor_DemPrimary_013_SIZE,                       /* BlockSize        */
        1,                       /* NoOfInstances    */
        0                        /* Bit0 - ImmediateData, Bit1 - Verification Enabled   */
    },
    {
        NVBlockDescriptor_DemPrimary_014_ADDR,                     /* BlockBaseAddress */
        NVBlockDescriptor_DemPrimary_014_SIZE,                       /* BlockSize        */
        1,                       /* NoOfInstances    */
        0                        /* Bit0 - ImmediateData, Bit1 - Verification Enabled   */
    },
    {
        NVBlockDescriptor_DemPrimary_015_ADDR,                     /* BlockBaseAddress */
        NVBlockDescriptor_DemPrimary_015_SIZE,                       /* BlockSize        */
        1,                       /* NoOfInstances    */
        0                        /* Bit0 - ImmediateData, Bit1 - Verification Enabled   */
    },
    {
        NVBlockDescriptor_DemPrimary_016_ADDR,                     /* BlockBaseAddress */
        NVBlockDescriptor_DemPrimary_016_SIZE,                       /* BlockSize        */
        1,                       /* NoOfInstances    */
        0                        /* Bit0 - ImmediateData, Bit1 - Verification Enabled   */
    },
    {
        NVBlockDescriptor_DemPrimary_017_ADDR,                     /* BlockBaseAddress */
        NVBlockDescriptor_DemPrimary_017_SIZE,                       /* BlockSize        */
        1,                       /* NoOfInstances    */
        0                        /* Bit0 - ImmediateData, Bit1 - Verification Enabled   */
    },
    {
        NVBlockDescriptor_DemPrimary_018_ADDR,                     /* BlockBaseAddress */
        NVBlockDescriptor_DemPrimary_018_SIZE,                       /* BlockSize        */
        1,                       /* NoOfInstances    */
        0                        /* Bit0 - ImmediateData, Bit1 - Verification Enabled   */
    },
    {
        NVBlockDescriptor_DemPrimary_019_ADDR,                     /* BlockBaseAddress */
        NVBlockDescriptor_DemPrimary_019_SIZE,                       /* BlockSize        */
        1,                       /* NoOfInstances    */
        0                        /* Bit0 - ImmediateData, Bit1 - Verification Enabled   */
    },
    {
        NVBlockDescriptor_DemPrimary_020_ADDR,                     /* BlockBaseAddress */
        NVBlockDescriptor_DemPrimary_020_SIZE,                       /* BlockSize        */
        1,                       /* NoOfInstances    */
        0                        /* Bit0 - ImmediateData, Bit1 - Verification Enabled   */
    },
    {
        NVBlockDescriptor_DemStatusData_ADDR,                     /* BlockBaseAddress */
        NVBlockDescriptor_DemStatusData_SIZE,                       /* BlockSize        */
        1,                      /* NoOfInstances    */
        0                        /* Bit0 - ImmediateData, Bit1 - Verification Enabled   */
    },
    {
        NVBlockDescriptor_DemAdminData_ADDR,                      /* BlockBaseAddress */
        NVBlockDescriptor_DemAdminData_SIZE,                       /* BlockSize        */
        1,                       /* NoOfInstances    */
        0                        /* Bit0 - ImmediateData, Bit1 - Verification Enabled   */
    },
};
/*****************************************************************************
*                                 Locally used Variable Declarations         *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/

/*****************************************************************************
*                              Limited Scope Prototypes                      *
******************************************************************************/
/*****************************************************************************
*                   Functions                                                *
******************************************************************************/

#endif /* EA_CFG_C */
/*****************************************************************************
*     End of File
*
*******************************************************************************/
/****************************************************************************
*   for each change to this file, be sure to record:                        *
*      1.  who made the change and when the change was made                 *
*      2.  why the change was made and the intended result                  *
*   Following block needs to be repeated for each change                    *
*****************************************************************************/
/**-------------------------------------------------------------------------*/
/*Date              : 13-01-2016                                            */
/*Version           :                                                       */
/*By                : kshaik1                                               */
/*Traceability      :                                                       */
/*Change Description: Datadesign And Framework implemented, Initial Version */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 04-03-2016                                            */
/*Version           :                                                       */
/*By                : kshaik1                                               */
/*Traceability      : 538817                                                */
/*Change Description: EA configuration updated for TransTemp Gauge          */
/*--------------------------------------------------------------------------*/
