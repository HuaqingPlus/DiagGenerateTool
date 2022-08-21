#ifndef __NVM_ADAPT_H__
#define __NVM_ADAPT_H__

#include "Std_Types.h"

#define NVM_CODE

/* used for references on application variables */
# define RTE_NVM_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_NVM_APPL_DATA

/* used for references on application functions */
# define RTE_NVM_APPL_CODE

/* used for references on application constants */
# define RTE_NVM_APPL_CONST

/* used for SWC specific code */
# define NvM_CODE

/* used for references on application variables */
# define RTE_DCMEXT_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_DCMEXT_APPL_DATA

/* used for references on application functions */
# define RTE_DCMEXT_APPL_CODE

/* used for references on application constants */
# define RTE_DCMEXT_APPL_CONST


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: NvM_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define NvM_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: NvM_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define NvM_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define NvM_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define NvM_VAR_ZERO_INIT

# define Rte_TypeDef_UInt16
typedef uint16 UInt16;

# define Rte_TypeDef_UInt32
typedef uint32 UInt32;

# define Rte_TypeDef_UInt8
typedef uint8 UInt8;

# define Rte_TypeDef_STRUCT_ECT_CONFIGURATION
typedef struct
{
  UInt8 ECT_TP0;
  UInt8 ECT_TP1;
  UInt8 ECT_TP2;
  UInt8 ECT_TP3;
  UInt8 ECT_Mini;
  UInt8 ECT_Plateau;
  UInt8 ECT_Maxi;
  UInt8 Padding;
} STRUCT_ECT_CONFIGURATION;


#  define Rte_TypeDef_Rte_DT_NV_ActiveDiagnosticInfo_4Bytes_Type_0
typedef uint8 Rte_DT_NV_ActiveDiagnosticInfo_4Bytes_Type_0;

#  define Rte_TypeDef_Rte_DT_NV_BootSoftwareCode_4Byte_Type_0
typedef uint8 Rte_DT_NV_BootSoftwareCode_4Byte_Type_0;

#  define Rte_TypeDef_Rte_DT_NV_Data_Cluster_PPK_0
typedef uint16 Rte_DT_NV_Data_Cluster_PPK_0;

#  define Rte_TypeDef_Rte_DT_NV_DemStatus_42Bytes_Type_0
typedef uint8 Rte_DT_NV_DemStatus_42Bytes_Type_0;

#  define Rte_TypeDef_Rte_DT_NV_Dem_8Bytes_Type_0
typedef uint8 Rte_DT_NV_Dem_8Bytes_Type_0;

#  define Rte_TypeDef_Rte_DT_NV_ECUHardwareVersionNumber_4Byte_Type_0
typedef uint8 Rte_DT_NV_ECUHardwareVersionNumber_4Byte_Type_0;

#  define Rte_TypeDef_Rte_DT_NV_ECUSerialNumber_16Byte_Type_0
typedef uint8 Rte_DT_NV_ECUSerialNumber_16Byte_Type_0;

#  define Rte_TypeDef_Rte_DT_NV_ECUSoftwareVersionNum_4Byte_Type_0
typedef uint8 Rte_DT_NV_ECUSoftwareVersionNum_4Byte_Type_0;

#  define Rte_TypeDef_Rte_DT_NV_Fingerprint_F150_10Bytes_Type_0
typedef uint8 Rte_DT_NV_Fingerprint_F150_10Bytes_Type_0;

#  define Rte_TypeDef_Rte_DT_NV_Fingerprint_F184_9Bytes_Type_0
typedef uint8 Rte_DT_NV_Fingerprint_F184_9Bytes_Type_0;

#  define Rte_TypeDef_Rte_DT_NV_PartNumAlpCode9Bytes_Type_0
typedef uint8 Rte_DT_NV_PartNumAlpCode9Bytes_Type_0;

#  define Rte_TypeDef_Rte_DT_NV_ProgrammingDate_6Byte_Type_0
typedef uint8 Rte_DT_NV_ProgrammingDate_6Byte_Type_0;

#  define Rte_TypeDef_Rte_DT_NV_SysSupplierId_10Byte_Type_0
typedef uint8 Rte_DT_NV_SysSupplierId_10Byte_Type_0;

#  define Rte_TypeDef_Rte_DT_NV_SystemName9Bytes_Type_0
typedef uint8 Rte_DT_NV_SystemName9Bytes_Type_0;

#  define Rte_TypeDef_Rte_DT_NV_VehicleDefinitionBitmap_20Byte_Type_0
typedef uint8 Rte_DT_NV_VehicleDefinitionBitmap_20Byte_Type_0;

#  define Rte_TypeDef_Rte_DT_NvM_ECUSerialNumberType_0
typedef uint8 Rte_DT_NvM_ECUSerialNumberType_0;


#  define Rte_TypeDef_Rte_DT_Gauge_Correction_Table_X_0
typedef uint16 Rte_DT_Gauge_Correction_Table_X_0;

#  define Rte_TypeDef_Rte_DT_Gauge_Correction_Table_Y_0
typedef uint16 Rte_DT_Gauge_Correction_Table_Y_0;

#  define Rte_TypeDef_Rte_DT_Gauge_Mapping_Table_X_0
typedef uint16 Rte_DT_Gauge_Mapping_Table_X_0;

#  define Rte_TypeDef_Rte_DT_Gauge_Mapping_Table_Y_0
typedef uint16 Rte_DT_Gauge_Mapping_Table_Y_0;

#  define Rte_TypeDef_Gauge_Correction_Table_X
typedef Rte_DT_Gauge_Correction_Table_X_0 Gauge_Correction_Table_X[6];

#  define Rte_TypeDef_Gauge_Correction_Table_Y
typedef Rte_DT_Gauge_Correction_Table_Y_0 Gauge_Correction_Table_Y[6];

#  define Rte_TypeDef_Gauge_Mapping_Table_X
typedef Rte_DT_Gauge_Mapping_Table_X_0 Gauge_Mapping_Table_X[6];

#  define Rte_TypeDef_Gauge_Mapping_Table_Y
typedef Rte_DT_Gauge_Mapping_Table_Y_0 Gauge_Mapping_Table_Y[6];


# define Rte_TypeDef_Rte_DT_NV_Cluster_Vehicle_Configure_0
typedef uint8 Rte_DT_NV_Cluster_Vehicle_Configure_0;

# define Rte_TypeDef_Rte_DT_NV_Data_ClusterSettings_0
typedef uint16 Rte_DT_NV_Data_ClusterSettings_0;

# define Rte_TypeDef_Rte_DT_NV_Data_ClusterSettings_1
typedef uint16 Rte_DT_NV_Data_ClusterSettings_1;

# define Rte_TypeDef_Rte_DT_NV_Data_ClusterSettings_10
typedef boolean Rte_DT_NV_Data_ClusterSettings_10;

# define Rte_TypeDef_Rte_DT_NV_Data_ClusterSettings_11
typedef uint16 Rte_DT_NV_Data_ClusterSettings_11;

# define Rte_TypeDef_Rte_DT_NV_Data_ClusterSettings_12
typedef uint16 Rte_DT_NV_Data_ClusterSettings_12;

# define Rte_TypeDef_Rte_DT_NV_Data_ClusterSettings_13
typedef uint16 Rte_DT_NV_Data_ClusterSettings_13;

# define Rte_TypeDef_Rte_DT_NV_Data_ClusterSettings_14
typedef uint8 Rte_DT_NV_Data_ClusterSettings_14;

# define Rte_TypeDef_Rte_DT_NV_Data_ClusterSettings_15
typedef uint16 Rte_DT_NV_Data_ClusterSettings_15;

# define Rte_TypeDef_Rte_DT_NV_Data_ClusterSettings_16
typedef boolean Rte_DT_NV_Data_ClusterSettings_16;

# define Rte_TypeDef_Rte_DT_NV_Data_ClusterSettings_17
typedef uint16 Rte_DT_NV_Data_ClusterSettings_17;

# define Rte_TypeDef_Rte_DT_NV_Data_ClusterSettings_18
typedef uint8 Rte_DT_NV_Data_ClusterSettings_18;

# define Rte_TypeDef_Rte_DT_NV_Data_ClusterSettings_19
typedef uint8 Rte_DT_NV_Data_ClusterSettings_19;

# define Rte_TypeDef_Rte_DT_NV_Data_ClusterSettings_2
typedef uint8 Rte_DT_NV_Data_ClusterSettings_2;

# define Rte_TypeDef_Rte_DT_NV_Data_ClusterSettings_20
typedef uint8 Rte_DT_NV_Data_ClusterSettings_20;

# define Rte_TypeDef_Rte_DT_NV_Data_ClusterSettings_3
typedef uint16 Rte_DT_NV_Data_ClusterSettings_3;

# define Rte_TypeDef_Rte_DT_NV_Data_ClusterSettings_4
typedef boolean Rte_DT_NV_Data_ClusterSettings_4;

# define Rte_TypeDef_Rte_DT_NV_Data_ClusterSettings_5
typedef uint16 Rte_DT_NV_Data_ClusterSettings_5;

# define Rte_TypeDef_Rte_DT_NV_Data_ClusterSettings_6
typedef uint16 Rte_DT_NV_Data_ClusterSettings_6;

# define Rte_TypeDef_Rte_DT_NV_Data_ClusterSettings_7
typedef uint16 Rte_DT_NV_Data_ClusterSettings_7;

# define Rte_TypeDef_Rte_DT_NV_Data_ClusterSettings_8
typedef uint8 Rte_DT_NV_Data_ClusterSettings_8;

# define Rte_TypeDef_Rte_DT_NV_Data_ClusterSettings_9
typedef uint16 Rte_DT_NV_Data_ClusterSettings_9;

# define Rte_TypeDef_Rte_DT_NV_Data_Cluster_Maintenance_0
typedef uint16 Rte_DT_NV_Data_Cluster_Maintenance_0;

# define Rte_TypeDef_Rte_DT_NV_Data_Cluster_ODO_Backup_Counter_0
typedef uint8 Rte_DT_NV_Data_Cluster_ODO_Backup_Counter_0;

# define Rte_TypeDef_Rte_DT_NV_Data_Cluster_Optional_Feature_Configure_0
typedef uint8 Rte_DT_NV_Data_Cluster_Optional_Feature_Configure_0;

# define Rte_TypeDef_Rte_DT_NV_Data_Cluster_Optional_Feature_Configure_1
typedef uint8 Rte_DT_NV_Data_Cluster_Optional_Feature_Configure_1;

# define Rte_TypeDef_Rte_DT_NV_Data_Cluster_Optional_Feature_Configure_2
typedef uint8 Rte_DT_NV_Data_Cluster_Optional_Feature_Configure_2;

# define Rte_TypeDef_Rte_DT_NV_Data_Cluster_Optional_Feature_Configure_3
typedef uint8 Rte_DT_NV_Data_Cluster_Optional_Feature_Configure_3;

# define Rte_TypeDef_Rte_DT_NV_Data_Cluster_Optional_Feature_Configure_4
typedef uint8 Rte_DT_NV_Data_Cluster_Optional_Feature_Configure_4;

# define Rte_TypeDef_Rte_DT_NV_Data_Cluster_Optional_Feature_Configure_5
typedef uint8 Rte_DT_NV_Data_Cluster_Optional_Feature_Configure_5;

# define Rte_TypeDef_Rte_DT_NV_Data_Cluster_Optional_Feature_Configure_6
typedef uint8 Rte_DT_NV_Data_Cluster_Optional_Feature_Configure_6;

# define Rte_TypeDef_Rte_DT_NV_Data_Cluster_Optional_Feature_Configure_7
typedef uint8 Rte_DT_NV_Data_Cluster_Optional_Feature_Configure_7;

# define Rte_TypeDef_Rte_DT_NV_Data_Cluster_Optional_Feature_Configure_8
typedef uint8 Rte_DT_NV_Data_Cluster_Optional_Feature_Configure_8;

# define Rte_TypeDef_Rte_DT_NV_Data_Cluster_Optional_Feature_Configure_9
typedef uint8 Rte_DT_NV_Data_Cluster_Optional_Feature_Configure_9;

# define Rte_TypeDef_Rte_DT_NV_Data_Cluster_Reset_OffSet_0
typedef uint32 Rte_DT_NV_Data_Cluster_Reset_OffSet_0;

# define Rte_TypeDef_Rte_DT_NV_Data_Cluster_Reset_OffSet_1
typedef uint32 Rte_DT_NV_Data_Cluster_Reset_OffSet_1;

# define Rte_TypeDef_Rte_DT_NV_Data_Cluster_Reset_OffSet_2
typedef uint8 Rte_DT_NV_Data_Cluster_Reset_OffSet_2;

# define Rte_TypeDef_Rte_DT_NV_Data_Cluster_SIA_Reset_Odo_OffSet_0
typedef uint32 Rte_DT_NV_Data_Cluster_SIA_Reset_Odo_OffSet_0;

# define Rte_TypeDef_Rte_DT_NV_Data_Cluster_SIA_Reset_Odo_OffSet_1
typedef uint32 Rte_DT_NV_Data_Cluster_SIA_Reset_Odo_OffSet_1;

# define Rte_TypeDef_Rte_DT_NV_Data_Cluster_SIA_Reset_Odo_OffSet_2
typedef uint16 Rte_DT_NV_Data_Cluster_SIA_Reset_Odo_OffSet_2;

# define Rte_TypeDef_Rte_DT_NV_Data_Cluster_SIA_Reset_Odo_OffSet_3
typedef uint16 Rte_DT_NV_Data_Cluster_SIA_Reset_Odo_OffSet_3;

# define Rte_TypeDef_Rte_DT_NV_Data_Cluster_Variable_Block_0
typedef uint32 Rte_DT_NV_Data_Cluster_Variable_Block_0;

# define Rte_TypeDef_Rte_DT_NV_Data_Cluster_Variable_Block_1
typedef uint32 Rte_DT_NV_Data_Cluster_Variable_Block_1;

# define Rte_TypeDef_Rte_DT_NV_Data_Cluster_Variable_Block_2
typedef uint8 Rte_DT_NV_Data_Cluster_Variable_Block_2;

# define Rte_TypeDef_Rte_DT_NV_Data_Cluster_Variable_Block_3
typedef uint8 Rte_DT_NV_Data_Cluster_Variable_Block_3;

# define Rte_TypeDef_Rte_DT_NV_Data_Cluster_Variable_Block_4
typedef uint8 Rte_DT_NV_Data_Cluster_Variable_Block_4;

# define Rte_TypeDef_Rte_DT_NV_Data_Cluster_Variable_Block_5
typedef uint8 Rte_DT_NV_Data_Cluster_Variable_Block_5;

# define Rte_TypeDef_Rte_DT_NV_Data_Cluster_Variable_Block_6
typedef uint8 Rte_DT_NV_Data_Cluster_Variable_Block_6;

# define Rte_TypeDef_Rte_DT_NV_Data_Cluster_Variable_Block_7
typedef uint8 Rte_DT_NV_Data_Cluster_Variable_Block_7;

# define Rte_TypeDef_Rte_DT_NV_Data_Cluster_Variable_Block_8
typedef uint8 Rte_DT_NV_Data_Cluster_Variable_Block_8;

# define Rte_TypeDef_Rte_DT_NV_DemAdmin_14Bytes_Type_0
typedef uint8 Rte_DT_NV_DemAdmin_14Bytes_Type_0;

# define Rte_TypeDef_Rte_DT_NV_ECUCfgFlag_4Byte_0
typedef uint8 Rte_DT_NV_ECUCfgFlag_4Byte_0;

# define Rte_TypeDef_Rte_DT_NV_ECUDiagTestBlock_4Byte_0
typedef uint8 Rte_DT_NV_ECUDiagTestBlock_4Byte_0;

# define Rte_TypeDef_Rte_DT_NV_ECUFuelLevel_4Byte_0
typedef uint8 Rte_DT_NV_ECUFuelLevel_4Byte_0;

# define Rte_TypeDef_Rte_DT_NV_ECUHardwareVersionNumberOEM_2Byte_0
typedef uint8 Rte_DT_NV_ECUHardwareVersionNumberOEM_2Byte_0;

# define Rte_TypeDef_Rte_DT_NV_ECUHardwareVersion_2Byte_0
typedef uint8 Rte_DT_NV_ECUHardwareVersion_2Byte_0;

# define Rte_TypeDef_Rte_DT_NV_ECUManufacturingDate_3Byte_0
typedef uint8 Rte_DT_NV_ECUManufacturingDate_3Byte_0;

# define Rte_TypeDef_Rte_DT_NV_ECUOdoClearCounts_4Byte_0
typedef uint8 Rte_DT_NV_ECUOdoClearCounts_4Byte_0;

# define Rte_TypeDef_Rte_DT_NV_ECUProductPartNumber_14Byte_0
typedef uint8 Rte_DT_NV_ECUProductPartNumber_14Byte_0;

# define Rte_TypeDef_Rte_DT_NV_ECUProgrammingDate_4Byte_0
typedef uint8 Rte_DT_NV_ECUProgrammingDate_4Byte_0;

# define Rte_TypeDef_Rte_DT_NV_ECURepairInformation_12Byte_0
typedef uint8 Rte_DT_NV_ECURepairInformation_12Byte_0;

# define Rte_TypeDef_Rte_DT_NV_ECUResetReason_32Byte_0
typedef uint8 Rte_DT_NV_ECUResetReason_32Byte_0;

# define Rte_TypeDef_Rte_DT_NV_ECUSerialNumber_12Byte_0
typedef uint8 Rte_DT_NV_ECUSerialNumber_12Byte_0;

# define Rte_TypeDef_Rte_DT_NV_ECUSoftwareCheck_2Byte_0
typedef uint8 Rte_DT_NV_ECUSoftwareCheck_2Byte_0;

# define Rte_TypeDef_Rte_DT_NV_ECUSoftwareVersionNumberOEM_2Byte_0
typedef uint8 Rte_DT_NV_ECUSoftwareVersionNumberOEM_2Byte_0;

# define Rte_TypeDef_Rte_DT_NV_ECUSoftwareVersion_2Byte_0
typedef uint8 Rte_DT_NV_ECUSoftwareVersion_2Byte_0;

# define Rte_TypeDef_Rte_DT_NV_ECUSupplierIdentifier_6Byte_0
typedef uint8 Rte_DT_NV_ECUSupplierIdentifier_6Byte_0;

# define Rte_TypeDef_Rte_DT_NV_ECUSystemName_3Byte_0
typedef uint8 Rte_DT_NV_ECUSystemName_3Byte_0;

# define Rte_TypeDef_Rte_DT_NV_VIN_Number_17Bytes_Type_0
typedef uint8 Rte_DT_NV_VIN_Number_17Bytes_Type_0;

# define Rte_TypeDef_Rte_DT_NvM_ECU24BytesNumberType_0
typedef uint8 Rte_DT_NvM_ECU24BytesNumberType_0;

# define Rte_TypeDef_Rte_DT_NvM_ProductInfo_0
typedef uint8 Rte_DT_NvM_ProductInfo_0;

# define Rte_TypeDef_NV_Data_ClusterSettings
typedef struct
{
  Rte_DT_NV_Data_ClusterSettings_0 RPM_Gauge_Sleep_Offset;
  Rte_DT_NV_Data_ClusterSettings_1 RPM_Gauge_Zero_Software;
  Rte_DT_NV_Data_ClusterSettings_2 RPM_Gauge_Magnetic_Offset;
  Rte_DT_NV_Data_ClusterSettings_3 RPM_Hysteresis_Angle_Value;
  Rte_DT_NV_Data_ClusterSettings_4 RPM_Hysteresis_Direction_Value;
  Rte_DT_NV_Data_ClusterSettings_5 RPM_OverDrive_Offset_Value;
  Rte_DT_NV_Data_ClusterSettings_6 Ect_Gauge_Sleep_Offset;
  Rte_DT_NV_Data_ClusterSettings_7 Ect_Gauge_Zero_Software;
  Rte_DT_NV_Data_ClusterSettings_8 Ect_Gauge_Magnetic_Offset;
  Rte_DT_NV_Data_ClusterSettings_9 Ect_Hysteresis_Angle_Value;
  Rte_DT_NV_Data_ClusterSettings_10 Ect_Hysteresis_Direction_Value;
  Rte_DT_NV_Data_ClusterSettings_11 Ect_OverDrive_Offset_Value;
  Rte_DT_NV_Data_ClusterSettings_12 Fuel_Gauge_Sleep_Offset;
  Rte_DT_NV_Data_ClusterSettings_13 Fuel_Gauge_Zero_Software;
  Rte_DT_NV_Data_ClusterSettings_14 Fuel_Gauge_Magnetic_Offset;
  Rte_DT_NV_Data_ClusterSettings_15 Fuel_Hysteresis_Angle_Value;
  Rte_DT_NV_Data_ClusterSettings_16 Fuel_Hysteresis_Direction_Value;
  Rte_DT_NV_Data_ClusterSettings_17 Fuel_OverDrive_Offset_Value;
  Rte_DT_NV_Data_ClusterSettings_18 ETM_Entry;
  Rte_DT_NV_Data_ClusterSettings_19 ETM_Enter;
  Rte_DT_NV_Data_ClusterSettings_20 ETM_Exit;
} NV_Data_ClusterSettings;

# define Rte_TypeDef_NV_Data_Cluster_Maintenance
typedef struct
{
  Rte_DT_NV_Data_Cluster_Maintenance_0 Maintenance;
} NV_Data_Cluster_Maintenance;

# define Rte_TypeDef_NV_Data_Cluster_ODO_Backup_Counter
typedef struct
{
  Rte_DT_NV_Data_Cluster_ODO_Backup_Counter_0 ODO_Backup_Value;
} NV_Data_Cluster_ODO_Backup_Counter;

# define Rte_TypeDef_NV_Data_Cluster_Optional_Feature_Configure
typedef struct
{
  Rte_DT_NV_Data_Cluster_Optional_Feature_Configure_0 Option_Configure_Byte0;
  Rte_DT_NV_Data_Cluster_Optional_Feature_Configure_1 Option_Configure_Byte1;
  Rte_DT_NV_Data_Cluster_Optional_Feature_Configure_2 Option_Configure_Byte2;
  Rte_DT_NV_Data_Cluster_Optional_Feature_Configure_3 Option_Configure_Byte3;
  Rte_DT_NV_Data_Cluster_Optional_Feature_Configure_4 Option_Configure_Byte4;
  Rte_DT_NV_Data_Cluster_Optional_Feature_Configure_5 Option_Configure_Byte5;
  Rte_DT_NV_Data_Cluster_Optional_Feature_Configure_6 Option_Configure_Byte6;
  Rte_DT_NV_Data_Cluster_Optional_Feature_Configure_7 Option_Configure_Byte7;
  Rte_DT_NV_Data_Cluster_Optional_Feature_Configure_8 Option_Configure_Byte8;
  Rte_DT_NV_Data_Cluster_Optional_Feature_Configure_9 Option_Configure_Byte9;
} NV_Data_Cluster_Optional_Feature_Configure;

# define Rte_TypeDef_NV_Data_Cluster_Reset_OffSet
typedef struct
{
  Rte_DT_NV_Data_Cluster_Reset_OffSet_0 Reset_Kilometer_Offset;
  Rte_DT_NV_Data_Cluster_Reset_OffSet_1 Reset_Mile_Offset;
  Rte_DT_NV_Data_Cluster_Reset_OffSet_2 Reset_Counter;
} NV_Data_Cluster_Reset_OffSet;

# define Rte_TypeDef_NV_Data_Cluster_SIA_Reset_Odo_OffSet
typedef struct
{
  Rte_DT_NV_Data_Cluster_SIA_Reset_Odo_OffSet_0 Reset_Kilometer_Offset;
  Rte_DT_NV_Data_Cluster_SIA_Reset_Odo_OffSet_1 Reset_Mile_Offset;
  Rte_DT_NV_Data_Cluster_SIA_Reset_Odo_OffSet_2 Store_Kilometer_Value;
  Rte_DT_NV_Data_Cluster_SIA_Reset_Odo_OffSet_3 Store_Mile_Value;
} NV_Data_Cluster_SIA_Reset_Odo_OffSet;

# define Rte_TypeDef_NV_Data_Cluster_Variable_Block
typedef struct
{
  Rte_DT_NV_Data_Cluster_Variable_Block_0 ODO_Backup_Kilometer_Offset;
  Rte_DT_NV_Data_Cluster_Variable_Block_1 ODO_Backup_Mile_Offset;
  Rte_DT_NV_Data_Cluster_Variable_Block_2 ODO_Backup_Sign;
  Rte_DT_NV_Data_Cluster_Variable_Block_3 DimMdl_NightInitLevel;
  Rte_DT_NV_Data_Cluster_Variable_Block_4 DimMdl_NightPanelInitLevel;
  Rte_DT_NV_Data_Cluster_Variable_Block_5 DimMdl_NightRatio;
  Rte_DT_NV_Data_Cluster_Variable_Block_6 DimMdl_NightPanelRatio;
  Rte_DT_NV_Data_Cluster_Variable_Block_7 VeIPC_VEH_SPD_PARK_BRK;
  Rte_DT_NV_Data_Cluster_Variable_Block_8 CheckCal;
} NV_Data_Cluster_Variable_Block;


#  define Rte_TypeDef_NV_Data_Interpolations
typedef struct
{
  Gauge_Mapping_Table_X Speedo_Gauge_Mapping_Table_X;
  Gauge_Mapping_Table_Y Speedo_Gauge_Mapping_Table_Y;
  Gauge_Correction_Table_X Speedo_Gauge_Correction_Table_X;
  Gauge_Correction_Table_Y Speedo_Gauge_Correction_Table_Y;
  Gauge_Mapping_Table_X RPM_Gauge_Mapping_Table_X;
  Gauge_Mapping_Table_Y RPM_Gauge_Mapping_Table_Y;
  Gauge_Correction_Table_X RPM_Gauge_Correction_Table_X;
  Gauge_Correction_Table_Y RPM_Gauge_Correction_Table_Y;
  Gauge_Mapping_Table_X Ect_Gauge_Mapping_Table_X;
  Gauge_Mapping_Table_Y Ect_Gauge_Mapping_Table_Y;
  Gauge_Correction_Table_X Ect_Gauge_Correction_Table_X;
  Gauge_Correction_Table_Y Ect_Gauge_Correction_Table_Y;
  Gauge_Mapping_Table_X Fuel_Gauge_Mapping_Table_X;
  Gauge_Mapping_Table_Y Fuel_Gauge_Mapping_Table_Y;
  Gauge_Correction_Table_X Fuel_Gauge_Correction_Table_X;
  Gauge_Mapping_Table_Y Fuel_Gauge_Correction_Table_Y;
} NV_Data_Interpolations;


//#define Rte_TypeDef_dtRef_VOID
//typedef void * dtRef_VOID;
//
//#define Rte_TypeDef_dtRef_const_VOID
//typedef const void * dtRef_const_VOID;
//
//#define Rte_TypeDef_Dem_OperationCycleIdType
//typedef uint8 Dem_OperationCycleIdType;
//
//#define Rte_TypeDef_Dem_DTCOriginType
//typedef uint16 Dem_DTCOriginType;

#define Rte_TypeDef_NvM_RequestResultType
typedef uint8 NvM_RequestResultType;

#define Rte_TypeDef_NvM_ServiceIdType
typedef uint8 NvM_ServiceIdType;




#define NULL ((void *)0)

#endif

