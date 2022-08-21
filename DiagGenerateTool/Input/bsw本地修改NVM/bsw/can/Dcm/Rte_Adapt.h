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
 *          File:  Rte_Type.h
 *        Config:  Turing.dpa"
 *   ECU-Project:  Cluster
 *
 *     Generator:  MICROSAR RTE Generator Version 4.8.0
 *                 RTE Core Version 1.8.0
 *       License:  Unlimited license CBD1400814 for Visteon Corporation
 *
 *   Description:  Header file containing user defined AUTOSAR types and RTE structures
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_ADAPT_H
# define _RTE_ADAPT_H

# include "Rte.h"

/* Qiuhuaqing Modify, Add Macro to adapt D53.Diagnosis, Start */

/**********************************************************************************************************************
 * Data type definitions
 *********************************************************************************************************************/

# define Rte_TypeDef_Boolean
typedef boolean Boolean;

# define Rte_TypeDef_eIgnState
typedef uint8 eIgnState;


# define Rte_TypeDef_SessionId
typedef uint8 SessionId;

# define Rte_TypeDef_HTimer
typedef uint8 HTimer;

# define Rte_TypeDef_UInt16
typedef uint16 UInt16;

# define Rte_TypeDef_UInt32
typedef uint32 UInt32;

# define Rte_TypeDef_UInt8
typedef uint8 UInt8;

/* FUNC macro for the declaration and definition of functions, that ensures correct syntax of function declarations
   rettype     return type of the function
   memclass    classification of the function itself*/
//# define FUNC(rettype, memclass) rettype

/* FUNC_P2CONST macro for declaration and definition of functions returning a pointer to a constant, that ensures 
     correct syntax of function declarations.
   rettype     return type of the function
   ptrclass    defines the classification of the pointer’s distance 
   memclass    classification of the function itself*/
//# define FUNC_P2CONST(rettype, ptrclass, memclass) const rettype*

/* FUNC_P2VAR macro for the declaration and definition of functions returning a pointer to a variable, that ensures
     correct syntax of function declarations
   rettype     return type of the function
   ptrclass    defines the classification of the pointer’s distance 
   memclass    classification of the function itself*/
//# define FUNC_P2VAR(rettype, ptrclass, memclass)  rettype*

/* P2VAR macro for the declaration and definition of pointers in RAM, pointing to variables
   ptrtype     type of the referenced variable memclass
   memclass    classification of the pointer’s variable itself
   ptrclass    defines the classification of the pointer’s distance
 */
//# define P2VAR(ptrtype, memclass, ptrclass) ptrtype*

/* P2CONST macro for the declaration and definition of pointers in RAM pointing to constants
   ptrtype     type of the referenced data
   memclass    classification of the pointer's variable itself
   ptrclass    defines the classification of the pointer's distance
 */
//# define P2CONST(ptrtype, memclass, ptrclass) const ptrtype*

/* CONSTP2VAR macro for the declaration and definition of constant pointers accessing variables
   ptrtype     type of the referenced data
   memclass    classification of the pointer's variable itself
   ptrclass    defines the classification of the pointer's distance
 */
//# define CONSTP2VAR(ptrtype, memclass, ptrclass) ptrtype* const

/* CONSTP2CONST macro for the declaration and definition of constant pointers accessing constants
   ptrtype     type of the referenced data
   memclass    classification of the pointer's variable itself
   ptrclass    defines the classification of the pointer's distance
 */
//# define CONSTP2CONST(ptrtype, memclass, ptrclass) const ptrtype* const

/* P2FUNC macro for the type definition of pointers to functions
   rettype     return type of the function
   ptrclass    defines the classification of the pointer's distance
   fctname     function name respectivly name of the defined type
 */
//# define P2FUNC(rettype, ptrclass, fctname) rettype (* fctname)

/* CONST macro for the declaration and definition of constants
   type        type of the constant
   memclass    classification of the constant itself
 */
//# define CONST(type, memclass) const type

/* VAR macro for the declaration and definition of variables
   vartype        type of the variable
   memclass    classification of the variable itself
 */

#if !defined BIT31
#define BIT31                   (0x80000000u)
#endif

#if !defined BIT30
#define BIT30                   (0x40000000u)
#endif

#if !defined BIT29
#define BIT29                   (0x20000000u)
#endif

#if !defined BIT28
#define BIT28                   (0x10000000u)
#endif

#if !defined BIT27
#define BIT27                   (0x08000000u)
#endif

#if !defined BIT26
#define BIT26                   (0x04000000u)
#endif

#if !defined BIT25
#define BIT25                   (0x02000000u)
#endif

#if !defined BIT24
#define BIT24                   (0x01000000u)
#endif

#if !defined BIT23
#define BIT23                   (0x00800000u)
#endif

#if !defined BIT22
#define BIT22                   (0x00400000u)
#endif

#if !defined BIT21
#define BIT21                   (0x00200000u)
#endif

#if !defined BIT20
#define BIT20                   (0x00100000u)
#endif

#if !defined BIT19
#define BIT19                   (0x00080000u)
#endif

#if !defined BIT18
#define BIT18                   (0x00040000u)
#endif

#if !defined BIT17
#define BIT17                   (0x00020000u)
#endif

#if !defined BIT16
#define BIT16                   (0x00010000u)
#endif

#if !defined BIT15
#define BIT15                   (0x00008000u)
#endif

#if !defined BIT14
#define BIT14                   (0x00004000u)
#endif

#if !defined BIT13
#define BIT13                   (0x00002000u)
#endif

#if !defined BIT12
#define BIT12                   (0x00001000u)
#endif

#if !defined BIT11
#define BIT11                   (0x00000800u)
#endif

#if !defined BIT10
#define BIT10                   (0x00000400u)
#endif

#if !defined BIT9
#define BIT9                    (0x00000200u)
#endif

#if !defined BIT8
#define BIT8                    (0x00000100u)
#endif

#if !defined BIT7
#define BIT7                    (0x00000080u)
#endif

#if !defined BIT6
#define BIT6                    (0x00000040u)
#endif

#if !defined BIT5
#define BIT5                    (0x00000020u)
#endif

#if !defined BIT4
#define BIT4                    (0x00000010u)
#endif

#if !defined BIT3
#define BIT3                    (0x00000008u)
#endif

#if !defined BIT2
#define BIT2                    (0x00000004u)
#endif

#if !defined BIT1
#define BIT1                    (0x00000002u)
#endif

#if !defined BIT0
#define BIT0                    (0x00000001u)
#endif


# define Rte_TypeDef_SDM_ENABLE_TYPE
typedef uint8 SDM_ENABLE_TYPE;

# define Rte_TypeDef_SELF_CHECKING_ENABLE_Type
typedef uint8 SELF_CHECKING_ENABLE_Type;



# define Rte_TypeDef_Dlt_VerboseBufferType
typedef uint8 Dlt_VerboseBufferType[128];

# define Rte_TypeDef_AppCtrlType
typedef UInt8 AppCtrlType;






# define Rte_TypeDef_Dcm_ControlDtcSettingType
typedef uint8 Dcm_ControlDtcSettingType;


# define Rte_TypeDef_Dcm_EcuResetType
typedef uint8 Dcm_EcuResetType;




# define Rte_TypeDef_Dcm_SecLevelType
typedef uint8 Dcm_SecLevelType;



# define Rte_TypeDef_Dem_EventStatusExtendedType
typedef uint8 Dem_EventStatusExtendedType;

# define Rte_TypeDef_Dlt_SessionIDType
typedef uint32 Dlt_SessionIDType;

#define DEM_PROCESS_AGING_CTR_EXTERN 	FALSE

#define DemImmediateNvStorageLimit		255U

#define DemStatusBitStorageTestFailed	TRUE

/***	***/
#define DemOperationCycleStatusStorage		TRUE

/***	DemSuppressionSupport	***/
#define DEM_DTC_SUPPRESSION				FALSE
#define DEM_NO_SUPPRESSION				TRUE

#define DemTypeOfDTCSupported			DEM_DTC_TRANSLATION_ISO14229_1

//typedef uint8 Dem_FilterWithSeverityType;
#define DEM_FILTER_WITH_SEVERITY_YES  0x00U
#define DEM_FILTER_WITH_SEVERITY_NO   0x01U

//     typedef uint8 Dem_FilterForFDCType;
#define DEM_FILTER_FOR_FDC_YES        0x00U
#define DEM_FILTER_FOR_FDC_NO         0x01U


/* DTC Aging */
# define Rte_TypeDef_Rte_DT_SDTCAgeTimesSet_0
typedef uint8 Rte_DT_SDTCAgeTimesSet_0;

# define Rte_TypeDef_Rte_DT_SDTCAgeTimesSet_1
typedef uint8 Rte_DT_SDTCAgeTimesSet_1;

# define Rte_TypeDef_Rte_DT_SDTCAgeTimesSet_10
typedef uint8 Rte_DT_SDTCAgeTimesSet_10;

# define Rte_TypeDef_Rte_DT_SDTCAgeTimesSet_11
typedef uint8 Rte_DT_SDTCAgeTimesSet_11;

# define Rte_TypeDef_Rte_DT_SDTCAgeTimesSet_12
typedef uint8 Rte_DT_SDTCAgeTimesSet_12;

# define Rte_TypeDef_Rte_DT_SDTCAgeTimesSet_13
typedef uint8 Rte_DT_SDTCAgeTimesSet_13;

# define Rte_TypeDef_Rte_DT_SDTCAgeTimesSet_14
typedef uint8 Rte_DT_SDTCAgeTimesSet_14;

# define Rte_TypeDef_Rte_DT_SDTCAgeTimesSet_15
typedef uint8 Rte_DT_SDTCAgeTimesSet_15;

# define Rte_TypeDef_Rte_DT_SDTCAgeTimesSet_16
typedef uint8 Rte_DT_SDTCAgeTimesSet_16;

# define Rte_TypeDef_Rte_DT_SDTCAgeTimesSet_17
typedef uint8 Rte_DT_SDTCAgeTimesSet_17;

# define Rte_TypeDef_Rte_DT_SDTCAgeTimesSet_18
typedef uint8 Rte_DT_SDTCAgeTimesSet_18;

# define Rte_TypeDef_Rte_DT_SDTCAgeTimesSet_19
typedef uint8 Rte_DT_SDTCAgeTimesSet_19;

# define Rte_TypeDef_Rte_DT_SDTCAgeTimesSet_2
typedef uint8 Rte_DT_SDTCAgeTimesSet_2;

# define Rte_TypeDef_Rte_DT_SDTCAgeTimesSet_20
typedef uint8 Rte_DT_SDTCAgeTimesSet_20;

# define Rte_TypeDef_Rte_DT_SDTCAgeTimesSet_21
typedef uint8 Rte_DT_SDTCAgeTimesSet_21;

# define Rte_TypeDef_Rte_DT_SDTCAgeTimesSet_22
typedef uint8 Rte_DT_SDTCAgeTimesSet_22;

# define Rte_TypeDef_Rte_DT_SDTCAgeTimesSet_3
typedef uint8 Rte_DT_SDTCAgeTimesSet_3;

# define Rte_TypeDef_Rte_DT_SDTCAgeTimesSet_4
typedef uint8 Rte_DT_SDTCAgeTimesSet_4;

# define Rte_TypeDef_Rte_DT_SDTCAgeTimesSet_5
typedef uint8 Rte_DT_SDTCAgeTimesSet_5;

# define Rte_TypeDef_Rte_DT_SDTCAgeTimesSet_6
typedef uint8 Rte_DT_SDTCAgeTimesSet_6;

# define Rte_TypeDef_Rte_DT_SDTCAgeTimesSet_7
typedef uint8 Rte_DT_SDTCAgeTimesSet_7;

# define Rte_TypeDef_Rte_DT_SDTCAgeTimesSet_8
typedef uint8 Rte_DT_SDTCAgeTimesSet_8;

# define Rte_TypeDef_Rte_DT_SDTCAgeTimesSet_9
typedef uint8 Rte_DT_SDTCAgeTimesSet_9;


# define Rte_TypeDef_SDTCAgeTimesSet
typedef struct
{
  Rte_DT_SDTCAgeTimesSet_0 DTC0;
  Rte_DT_SDTCAgeTimesSet_1 DTC1;
  Rte_DT_SDTCAgeTimesSet_2 DTC2;
  Rte_DT_SDTCAgeTimesSet_3 DTC3;
  Rte_DT_SDTCAgeTimesSet_4 DTC4;
  Rte_DT_SDTCAgeTimesSet_5 DTC5;
  Rte_DT_SDTCAgeTimesSet_6 DTC6;
  Rte_DT_SDTCAgeTimesSet_7 DTC7;
  Rte_DT_SDTCAgeTimesSet_8 DTC8;
  Rte_DT_SDTCAgeTimesSet_9 DTC9;
  Rte_DT_SDTCAgeTimesSet_10 DTC10;
  Rte_DT_SDTCAgeTimesSet_11 DTC11;
  Rte_DT_SDTCAgeTimesSet_12 DTC12;
  Rte_DT_SDTCAgeTimesSet_13 DTC13;
  Rte_DT_SDTCAgeTimesSet_14 DTC14;
  Rte_DT_SDTCAgeTimesSet_15 DTC15;
  Rte_DT_SDTCAgeTimesSet_16 DTC16;
  Rte_DT_SDTCAgeTimesSet_17 DTC17;
  Rte_DT_SDTCAgeTimesSet_18 DTC18;
  Rte_DT_SDTCAgeTimesSet_19 DTC19;
  Rte_DT_SDTCAgeTimesSet_20 DTC20;
  Rte_DT_SDTCAgeTimesSet_21 DTC21;
  Rte_DT_SDTCAgeTimesSet_22 DTC22;
} SDTCAgeTimesSet;

# define Rte_TypeDef_NV_DTC_AgeTimes_SetType
typedef SDTCAgeTimesSet NV_DTC_AgeTimes_SetType[1];

# define Rte_TypeDef_DCM_IOC_Type
typedef struct
{
  uint16 DID_IOC_Number;
  uint16 DID_IOC_Parament;
  uint8 DID_IOC_State[4];
} DCM_IOC_Type;

/* Qiuhuaqing Modify, Add Macro to adapt D53.Diagnosis, End */
#endif /* _RTE_TYPE_H */

