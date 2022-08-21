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
 *              File: Com_Cfg.h
 *   Generation Time: 2022-07-21 09:20:09
 *           Project: C03 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.24
 *
 *
 *********************************************************************************************************************/


#if !defined (COM_CFG_H)
# define COM_CFG_H

/**********************************************************************************************************************
 * MISRA JUSTIFICATION
 *********************************************************************************************************************/

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
# include "Com_Types.h"
# include "Com_PBcfg.h"
# include "Com_Cbk.h"
# include "PduR_Cfg.h"

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/

#ifndef COM_USE_DUMMY_STATEMENT
#define COM_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef COM_DUMMY_STATEMENT
#define COM_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef COM_DUMMY_STATEMENT_CONST
#define COM_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef COM_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define COM_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef COM_ATOMIC_VARIABLE_ACCESS
#define COM_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef COM_PROCESSOR_RH850_1651
#define COM_PROCESSOR_RH850_1651
#endif
#ifndef COM_COMP_GREENHILLS
#define COM_COMP_GREENHILLS
#endif
#ifndef COM_GEN_GENERATOR_MSR
#define COM_GEN_GENERATOR_MSR
#endif
#ifndef COM_CPUTYPE_BITORDER_LSB2MSB
#define COM_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef COM_CONFIGURATION_VARIANT_PRECOMPILE
#define COM_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef COM_CONFIGURATION_VARIANT_LINKTIME
#define COM_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef COM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define COM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef COM_CONFIGURATION_VARIANT
#define COM_CONFIGURATION_VARIANT COM_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef COM_POSTBUILD_VARIANT_SUPPORT
#define COM_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  ComPCDataSwitches  Com Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define COM_ACTIVATABLERXCOMIPDUS                                                                   STD_OFF  /**< Deactivateable: 'Com_ActivatableRxComIPdus' Reason: 'Deactivated as OptimizedIPduGroupControl is set to false.' */
#define COM_RXPDUINFOIDXOFACTIVATABLERXCOMIPDUS                                                     STD_OFF  /**< Deactivateable: 'Com_ActivatableRxComIPdus.RxPduInfoIdx' Reason: 'Deactivated as OptimizedIPduGroupControl is set to false.' */
#define COM_ACTIVATABLETXCOMIPDUS                                                                   STD_OFF  /**< Deactivateable: 'Com_ActivatableTxComIPdus' Reason: 'Deactivated as OptimizedIPduGroupControl is set to false.' */
#define COM_TXPDUINFOIDXOFACTIVATABLETXCOMIPDUS                                                     STD_OFF  /**< Deactivateable: 'Com_ActivatableTxComIPdus.TxPduInfoIdx' Reason: 'Deactivated as OptimizedIPduGroupControl is set to false.' */
#define COM_ALWAYSACTIVERXCOMIPDUS                                                                  STD_OFF  /**< Deactivateable: 'Com_AlwaysActiveRxComIPdus' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_RXPDUINFOIDXOFALWAYSACTIVERXCOMIPDUS                                                    STD_OFF  /**< Deactivateable: 'Com_AlwaysActiveRxComIPdus.RxPduInfoIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_ALWAYSACTIVETXCOMIPDUS                                                                  STD_ON
#define COM_TXPDUINFOIDXOFALWAYSACTIVETXCOMIPDUS                                                    STD_ON
#define COM_CBKRXTOUTFUNCPTR                                                                        STD_ON
#define COM_CBKRXTOUTFUNCPTRIND                                                                     STD_ON
#define COM_CBKTXACKDEFFUNCPTR                                                                      STD_OFF  /**< Deactivateable: 'Com_CbkTxAckDefFuncPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CBKTXACKDEFFUNCPTRIND                                                                   STD_OFF  /**< Deactivateable: 'Com_CbkTxAckDefFuncPtrInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CBKTXACKIMFUNCPTR                                                                       STD_OFF  /**< Deactivateable: 'Com_CbkTxAckImFuncPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CBKTXACKIMFUNCPTRIND                                                                    STD_OFF  /**< Deactivateable: 'Com_CbkTxAckImFuncPtrInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CBKTXERRFUNCPTR                                                                         STD_OFF  /**< Deactivateable: 'Com_CbkTxErrFuncPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CBKTXERRFUNCPTRIND                                                                      STD_OFF  /**< Deactivateable: 'Com_CbkTxErrFuncPtrInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CBKTXTOUTFUNCPTR                                                                        STD_OFF  /**< Deactivateable: 'Com_CbkTxTOutFuncPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CBKTXTOUTFUNCPTRIND                                                                     STD_OFF  /**< Deactivateable: 'Com_CbkTxTOutFuncPtrInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONFIGID                                                                                STD_ON
#define COM_CONSTVALUEARRAYBASED                                                                    STD_OFF  /**< Deactivateable: 'Com_ConstValueArrayBased' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUEFLOAT32                                                                       STD_OFF  /**< Deactivateable: 'Com_ConstValueFloat32' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUEFLOAT64                                                                       STD_OFF  /**< Deactivateable: 'Com_ConstValueFloat64' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUESINT16                                                                        STD_OFF  /**< Deactivateable: 'Com_ConstValueSInt16' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUESINT32                                                                        STD_OFF  /**< Deactivateable: 'Com_ConstValueSInt32' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUESINT64                                                                        STD_OFF  /**< Deactivateable: 'Com_ConstValueSInt64' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUESINT8                                                                         STD_OFF  /**< Deactivateable: 'Com_ConstValueSInt8' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUESIGGRPARRAYACCESS                                                             STD_OFF  /**< Deactivateable: 'Com_ConstValueSigGrpArrayAccess' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUEUINT16                                                                        STD_ON
#define COM_CONSTVALUEUINT32                                                                        STD_ON
#define COM_CONSTVALUEUINT64                                                                        STD_OFF  /**< Deactivateable: 'Com_ConstValueUInt64' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUEUINT8                                                                         STD_ON
#define COM_CURRENTTXMODE                                                                           STD_ON
#define COM_CYCLETIMECNT                                                                            STD_ON
#define COM_CYCLICSENDREQUEST                                                                       STD_ON
#define COM_DEFERREDGWMAPPINGEVENT                                                                  STD_OFF  /**< Deactivateable: 'Com_DeferredGwMappingEvent' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_DEFERREDGWMAPPINGINFO                                                                   STD_OFF  /**< Deactivateable: 'Com_DeferredGwMappingInfo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_RXPDUINFOIDXOFDEFERREDGWMAPPINGINFO                                                     STD_OFF  /**< Deactivateable: 'Com_DeferredGwMappingInfo.RxPduInfoIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_DELAYTIMECNT                                                                            STD_OFF  /**< Deactivateable: 'Com_DelayTimeCnt' Reason: 'MinimumDelayTime is not configured or always zero.' */
#define COM_DIRECTTRIGGER                                                                           STD_OFF  /**< Deactivateable: 'Com_DirectTrigger' Reason: 'the parameter is only needed if ComEnableMDTForCyclicTransmission is equals FALSE.' */
#define COM_FILTERINFO_FLOAT32                                                                      STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float32' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_FILTERALGOOFFILTERINFO_FLOAT32                                                          STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMASKOFFILTERINFO_FLOAT32                                                          STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float32.FilterMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMAXOFFILTERINFO_FLOAT32                                                           STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float32.FilterMax' Reason: 'FilterMin, FilterMax, FilterX are deactivated for Float32 and Float64 Filter Info, because they aren't configurable.' */
#define COM_FILTERMINOFFILTERINFO_FLOAT32                                                           STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float32.FilterMin' Reason: 'FilterMin, FilterMax, FilterX are deactivated for Float32 and Float64 Filter Info, because they aren't configurable.' */
#define COM_FILTERXOFFILTERINFO_FLOAT32                                                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float32.FilterX' Reason: 'FilterMin, FilterMax, FilterX are deactivated for Float32 and Float64 Filter Info, because they aren't configurable.' */
#define COM_FILTERINFO_FLOAT64                                                                      STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float64' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_FILTERALGOOFFILTERINFO_FLOAT64                                                          STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMASKOFFILTERINFO_FLOAT64                                                          STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float64.FilterMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMAXOFFILTERINFO_FLOAT64                                                           STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float64.FilterMax' Reason: 'FilterMin, FilterMax, FilterX are deactivated for Float32 and Float64 Filter Info, because they aren't configurable.' */
#define COM_FILTERMINOFFILTERINFO_FLOAT64                                                           STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float64.FilterMin' Reason: 'FilterMin, FilterMax, FilterX are deactivated for Float32 and Float64 Filter Info, because they aren't configurable.' */
#define COM_FILTERXOFFILTERINFO_FLOAT64                                                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float64.FilterX' Reason: 'FilterMin, FilterMax, FilterX are deactivated for Float32 and Float64 Filter Info, because they aren't configurable.' */
#define COM_FILTERINFO_SINT16                                                                       STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_FILTERALGOOFFILTERINFO_SINT16                                                           STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMASKOFFILTERINFO_SINT16                                                           STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMAXOFFILTERINFO_SINT16                                                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterMax' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMINOFFILTERINFO_SINT16                                                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterMin' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERXOFFILTERINFO_SINT16                                                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterX' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERINFO_SINT32                                                                       STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_FILTERALGOOFFILTERINFO_SINT32                                                           STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMASKOFFILTERINFO_SINT32                                                           STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMAXOFFILTERINFO_SINT32                                                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterMax' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMINOFFILTERINFO_SINT32                                                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterMin' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERXOFFILTERINFO_SINT32                                                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterX' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERINFO_SINT64                                                                       STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_FILTERALGOOFFILTERINFO_SINT64                                                           STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMASKOFFILTERINFO_SINT64                                                           STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMAXOFFILTERINFO_SINT64                                                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterMax' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMINOFFILTERINFO_SINT64                                                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterMin' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERXOFFILTERINFO_SINT64                                                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterX' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERINFO_SINT8                                                                        STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_FILTERALGOOFFILTERINFO_SINT8                                                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMASKOFFILTERINFO_SINT8                                                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMAXOFFILTERINFO_SINT8                                                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterMax' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMINOFFILTERINFO_SINT8                                                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterMin' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERXOFFILTERINFO_SINT8                                                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterX' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERINFO_UINT16                                                                       STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt16' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_FILTERALGOOFFILTERINFO_UINT16                                                           STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMASKOFFILTERINFO_UINT16                                                           STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt16.FilterMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMAXOFFILTERINFO_UINT16                                                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt16.FilterMax' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMINOFFILTERINFO_UINT16                                                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt16.FilterMin' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERXOFFILTERINFO_UINT16                                                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt16.FilterX' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERINFO_UINT32                                                                       STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_FILTERALGOOFFILTERINFO_UINT32                                                           STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMASKOFFILTERINFO_UINT32                                                           STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMAXOFFILTERINFO_UINT32                                                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterMax' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMINOFFILTERINFO_UINT32                                                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterMin' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERXOFFILTERINFO_UINT32                                                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterX' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERINFO_UINT64                                                                       STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_FILTERALGOOFFILTERINFO_UINT64                                                           STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMASKOFFILTERINFO_UINT64                                                           STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMAXOFFILTERINFO_UINT64                                                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterMax' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMINOFFILTERINFO_UINT64                                                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterMin' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERXOFFILTERINFO_UINT64                                                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterX' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERINFO_UINT8                                                                        STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_FILTERALGOOFFILTERINFO_UINT8                                                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMASKOFFILTERINFO_UINT8                                                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8.FilterMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMAXOFFILTERINFO_UINT8                                                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8.FilterMax' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMINOFFILTERINFO_UINT8                                                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8.FilterMin' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERXOFFILTERINFO_UINT8                                                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8.FilterX' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERINFO_UINT8_N                                                                      STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_FILTERALGOOFFILTERINFO_UINT8_N                                                          STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMASKOFFILTERINFO_UINT8_N                                                          STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMAXOFFILTERINFO_UINT8_N                                                           STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterMax' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMINOFFILTERINFO_UINT8_N                                                           STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterMin' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERXOFFILTERINFO_UINT8_N                                                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterX' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FINALMAGICNUMBER                                                                        STD_OFF  /**< Deactivateable: 'Com_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define COM_GATEWAYDESCRIPTIONPROCESSINGISRLOCKCOUNTER                                              STD_OFF  /**< Deactivateable: 'Com_GatewayDescriptionProcessingISRLockCounter' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_GATEWAYDESCRIPTIONPROCESSINGISRLOCKTHRESHOLD                                            STD_OFF  /**< Deactivateable: 'Com_GatewayDescriptionProcessingISRLockThreshold' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_GATEWAYPROCESSINGISRLOCKCOUNTER                                                         STD_OFF  /**< Deactivateable: 'Com_GatewayProcessingISRLockCounter' Reason: 'Signal Gateway is not configured.' */
#define COM_GATEWAYPROCESSINGISRLOCKTHRESHOLD                                                       STD_OFF  /**< Deactivateable: 'Com_GatewayProcessingISRLockThreshold' Reason: 'Signal Gateway is not configured.' */
#define COM_GWDESCRIPTIONACCESSINFO                                                                 STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_BITOFFSETOFGWDESCRIPTIONACCESSINFO                                                      STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.BitOffset' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_BITSIZEOFGWDESCRIPTIONACCESSINFO                                                        STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.BitSize' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_COPYTYPEOFGWDESCRIPTIONACCESSINFO                                                       STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.CopyType' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_ENDIANNESSOFGWDESCRIPTIONACCESSINFO                                                     STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Endianness' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_GWSOURCESTARTBITINDEXOFGWDESCRIPTIONACCESSINFO                                          STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.GwSourceStartBitIndex' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_RXUBIDXOFGWDESCRIPTIONACCESSINFO                                                        STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.RxUbIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_RXUBMASKIDXOFGWDESCRIPTIONACCESSINFO                                                    STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.RxUbMaskIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_RXUBMASKUSEDOFGWDESCRIPTIONACCESSINFO                                                   STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.RxUbMaskUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_SOURCEDESCRIPTIONMASKENDMASKIDXOFGWDESCRIPTIONACCESSINFO                                STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.SourceDescriptionMaskEndMaskIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_SOURCEDESCRIPTIONMASKENDMASKUSEDOFGWDESCRIPTIONACCESSINFO                               STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.SourceDescriptionMaskEndMaskUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_SOURCEDESCRIPTIONMASKIDXOFGWDESCRIPTIONACCESSINFO                                       STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.SourceDescriptionMaskIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_SOURCESTARTBYTEPOSITIONOFGWDESCRIPTIONACCESSINFO                                        STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.SourceStartBytePosition' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_TXBUFFERENDIDXOFGWDESCRIPTIONACCESSINFO                                                 STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.TxBufferEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_TXBUFFERLENGTHOFGWDESCRIPTIONACCESSINFO                                                 STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.TxBufferLength' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_TXBUFFERSTARTIDXOFGWDESCRIPTIONACCESSINFO                                               STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.TxBufferStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_TXBUFFERUBIDXOFGWDESCRIPTIONACCESSINFO                                                  STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.TxBufferUbIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_TXBUFFERUBUSEDOFGWDESCRIPTIONACCESSINFO                                                 STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.TxBufferUbUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_TXPDUINFOIDXOFGWDESCRIPTIONACCESSINFO                                                   STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.TxPduInfoIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_TXUBMASKIDXOFGWDESCRIPTIONACCESSINFO                                                    STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.TxUbMaskIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_TXUBMASKUSEDOFGWDESCRIPTIONACCESSINFO                                                   STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.TxUbMaskUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_TYPEOFGWDESCRIPTIONACCESSINFO                                                           STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Type' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_VALIDDLCOFGWDESCRIPTIONACCESSINFO                                                       STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.ValidDlc' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_GWEVENT                                                                                 STD_OFF  /**< Deactivateable: 'Com_GwEvent' Reason: 'The gateway is deactivated!' */
#define COM_GWEVENTCACHE                                                                            STD_OFF  /**< Deactivateable: 'Com_GwEventCache' Reason: 'No Deferred Description Routings exist' */
#define COM_GWEVENTCACHEINDEX                                                                       STD_OFF  /**< Deactivateable: 'Com_GwEventCacheIndex' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_GWGRPSIGMAPPING                                                                         STD_OFF  /**< Deactivateable: 'Com_GwGrpSigMapping' Reason: 'The gateway is deactivated!' */
#define COM_RXACCESSINFOIDXOFGWGRPSIGMAPPING                                                        STD_OFF  /**< Deactivateable: 'Com_GwGrpSigMapping.RxAccessInfoIdx' Reason: 'The gateway is deactivated!' */
#define COM_TXSIGIDOFGWGRPSIGMAPPING                                                                STD_OFF  /**< Deactivateable: 'Com_GwGrpSigMapping.TxSigId' Reason: 'The gateway is deactivated!' */
#define COM_GWINFO                                                                                  STD_OFF  /**< Deactivateable: 'Com_GwInfo' Reason: 'The gateway is deactivated!' */
#define COM_GWSIGGRPMAPPINGENDIDXOFGWINFO                                                           STD_OFF  /**< Deactivateable: 'Com_GwInfo.GwSigGrpMappingEndIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWSIGGRPMAPPINGSTARTIDXOFGWINFO                                                         STD_OFF  /**< Deactivateable: 'Com_GwInfo.GwSigGrpMappingStartIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWSIGGRPMAPPINGUSEDOFGWINFO                                                             STD_OFF  /**< Deactivateable: 'Com_GwInfo.GwSigGrpMappingUsed' Reason: 'The gateway is deactivated!' */
#define COM_GWSIGMAPPINGENDIDXOFGWINFO                                                              STD_OFF  /**< Deactivateable: 'Com_GwInfo.GwSigMappingEndIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWSIGMAPPINGSTARTIDXOFGWINFO                                                            STD_OFF  /**< Deactivateable: 'Com_GwInfo.GwSigMappingStartIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWSIGMAPPINGUSEDOFGWINFO                                                                STD_OFF  /**< Deactivateable: 'Com_GwInfo.GwSigMappingUsed' Reason: 'The gateway is deactivated!' */
#define COM_GWROUTINGTIMEOUTCOUNTER                                                                 STD_OFF  /**< Deactivateable: 'Com_GwRoutingTimeoutCounter' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_GWSIGGRPMAPPING                                                                         STD_OFF  /**< Deactivateable: 'Com_GwSigGrpMapping' Reason: 'The gateway is deactivated!' */
#define COM_GWGRPSIGMAPPINGENDIDXOFGWSIGGRPMAPPING                                                  STD_OFF  /**< Deactivateable: 'Com_GwSigGrpMapping.GwGrpSigMappingEndIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWGRPSIGMAPPINGSTARTIDXOFGWSIGGRPMAPPING                                                STD_OFF  /**< Deactivateable: 'Com_GwSigGrpMapping.GwGrpSigMappingStartIdx' Reason: 'The gateway is deactivated!' */
#define COM_TXSIGGRPIDOFGWSIGGRPMAPPING                                                             STD_OFF  /**< Deactivateable: 'Com_GwSigGrpMapping.TxSigGrpId' Reason: 'The gateway is deactivated!' */
#define COM_GWSIGMAPPING                                                                            STD_OFF  /**< Deactivateable: 'Com_GwSigMapping' Reason: 'The gateway is deactivated!' */
#define COM_RXACCESSINFOIDXOFGWSIGMAPPING                                                           STD_OFF  /**< Deactivateable: 'Com_GwSigMapping.RxAccessInfoIdx' Reason: 'The gateway is deactivated!' */
#define COM_TXSIGIDOFGWSIGMAPPING                                                                   STD_OFF  /**< Deactivateable: 'Com_GwSigMapping.TxSigId' Reason: 'The gateway is deactivated!' */
#define COM_GWTIMEOUTINFO                                                                           STD_OFF  /**< Deactivateable: 'Com_GwTimeoutInfo' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_GWROUTINGTIMEOUTFACTOROFGWTIMEOUTINFO                                                   STD_OFF  /**< Deactivateable: 'Com_GwTimeoutInfo.GwRoutingTimeoutFactor' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXPDUINFOIDXOFGWTIMEOUTINFO                                                             STD_OFF  /**< Deactivateable: 'Com_GwTimeoutInfo.TxPduInfoIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_GWTXPDUDESCRIPTIONINFO                                                                  STD_OFF  /**< Deactivateable: 'Com_GwTxPduDescriptionInfo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_GWDESCRIPTIONACCESSINFOENDIDXOFGWTXPDUDESCRIPTIONINFO                                   STD_OFF  /**< Deactivateable: 'Com_GwTxPduDescriptionInfo.GwDescriptionAccessInfoEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_GWDESCRIPTIONACCESSINFOSTARTIDXOFGWTXPDUDESCRIPTIONINFO                                 STD_OFF  /**< Deactivateable: 'Com_GwTxPduDescriptionInfo.GwDescriptionAccessInfoStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_HANDLERXDEFERREDGWDESCRIPTION                                                           STD_OFF  /**< Deactivateable: 'Com_HandleRxDeferredGwDescription' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_HANDLERXPDUDEFERRED                                                                     STD_ON
#define COM_HANDLETXPDUDEFERRED                                                                     STD_OFF  /**< Deactivateable: 'Com_HandleTxPduDeferred' Reason: 'This array is deactivated, because no Tx notification functions for deferred signal processing are configured.' */
#define COM_IPDUGROUPINFO                                                                           STD_ON
#define COM_IPDUGROUPINFOTOSUBIPDUGROUPSINDENDIDXOFIPDUGROUPINFO                                    STD_ON
#define COM_IPDUGROUPINFOTOSUBIPDUGROUPSINDSTARTIDXOFIPDUGROUPINFO                                  STD_ON
#define COM_IPDUGROUPINFOTOSUBIPDUGROUPSINDUSEDOFIPDUGROUPINFO                                      STD_ON
#define COM_INVALIDHNDOFIPDUGROUPINFO                                                               STD_OFF  /**< Deactivateable: 'Com_IPduGroupInfo.InvalidHnd' Reason: 'the value of Com_InvalidHndOfIPduGroupInfo is always 'false' due to this, the array is deactivated.' */
#define COM_RXPDUINFOINDENDIDXOFIPDUGROUPINFO                                                       STD_ON
#define COM_RXPDUINFOINDSTARTIDXOFIPDUGROUPINFO                                                     STD_ON
#define COM_RXPDUINFOINDUSEDOFIPDUGROUPINFO                                                         STD_ON
#define COM_TXPDUINFOINDENDIDXOFIPDUGROUPINFO                                                       STD_ON
#define COM_TXPDUINFOINDSTARTIDXOFIPDUGROUPINFO                                                     STD_ON
#define COM_TXPDUINFOINDUSEDOFIPDUGROUPINFO                                                         STD_ON
#define COM_IPDUGROUPINFOOFRXPDUINFOIND                                                             STD_ON
#define COM_IPDUGROUPINFOOFTXPDUINFOIND                                                             STD_ON
#define COM_IPDUGROUPINFOTOSUBIPDUGROUPSIND                                                         STD_ON
#define COM_IPDUGROUPSTATE                                                                          STD_ON
#define COM_INITDATAHASHCODE                                                                        STD_OFF  /**< Deactivateable: 'Com_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define COM_INITIALIZED                                                                             STD_ON
#define COM_PDUGRPCNT                                                                               STD_ON
#define COM_PDUGRPVECTOR                                                                            STD_OFF  /**< Deactivateable: 'Com_PduGrpVector' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'true'' */
#define COM_REPCNT                                                                                  STD_OFF  /**< Deactivateable: 'Com_RepCnt' Reason: 'This array is deactivated, because no transmission mode with repetitions is configured.' */
#define COM_REPCYCLECNT                                                                             STD_OFF  /**< Deactivateable: 'Com_RepCycleCnt' Reason: 'This array is deactivated, because no transmission mode with repetitions is configured.' */
#define COM_RXACCESSINFO                                                                            STD_ON
#define COM_APPLTYPEOFRXACCESSINFO                                                                  STD_ON
#define COM_BITLENGTHOFRXACCESSINFO                                                                 STD_ON
#define COM_BITPOSITIONOFRXACCESSINFO                                                               STD_ON
#define COM_BUFFERIDXOFRXACCESSINFO                                                                 STD_ON
#define COM_BUFFERUSEDOFRXACCESSINFO                                                                STD_ON
#define COM_BUSACCOFRXACCESSINFO                                                                    STD_ON
#define COM_BYTELENGTHOFRXACCESSINFO                                                                STD_ON
#define COM_BYTEPOSITIONOFRXACCESSINFO                                                              STD_ON
#define COM_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO                                       STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ConstValueArrayBasedInitValueEndIdx' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedInitValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEARRAYBASEDINITVALUELENGTHOFRXACCESSINFO                                       STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ConstValueArrayBasedInitValueLength' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedInitValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO                                     STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ConstValueArrayBasedInitValueStartIdx' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedInitValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEARRAYBASEDINITVALUEUSEDOFRXACCESSINFO                                         STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ConstValueArrayBasedInitValueUsed' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedInitValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEARRAYBASEDINVVALUEENDIDXOFRXACCESSINFO                                        STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ConstValueArrayBasedInvValueEndIdx' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedInvValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEARRAYBASEDINVVALUELENGTHOFRXACCESSINFO                                        STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ConstValueArrayBasedInvValueLength' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedInvValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEARRAYBASEDINVVALUESTARTIDXOFRXACCESSINFO                                      STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ConstValueArrayBasedInvValueStartIdx' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedInvValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEARRAYBASEDINVVALUEUSEDOFRXACCESSINFO                                          STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ConstValueArrayBasedInvValueUsed' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedInvValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEARRAYBASEDRXDATATIMEOUTSUBSTITUTIONVALUEENDIDXOFRXACCESSINFO                  STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ConstValueArrayBasedRxDataTimeoutSubstitutionValueEndIdx' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedRxDataTimeoutSubstitutionValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEARRAYBASEDRXDATATIMEOUTSUBSTITUTIONVALUELENGTHOFRXACCESSINFO                  STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ConstValueArrayBasedRxDataTimeoutSubstitutionValueLength' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedRxDataTimeoutSubstitutionValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEARRAYBASEDRXDATATIMEOUTSUBSTITUTIONVALUESTARTIDXOFRXACCESSINFO                STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ConstValueArrayBasedRxDataTimeoutSubstitutionValueStartIdx' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedRxDataTimeoutSubstitutionValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEARRAYBASEDRXDATATIMEOUTSUBSTITUTIONVALUEUSEDOFRXACCESSINFO                    STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ConstValueArrayBasedRxDataTimeoutSubstitutionValueUsed' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedRxDataTimeoutSubstitutionValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_FILTERINFOIDXOFRXACCESSINFO                                                             STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.FilterInfoIdx' Reason: 'the optional indirection is deactivated because FilterInfoUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_FILTERINFOUSEDOFRXACCESSINFO                                                            STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.FilterInfoUsed' Reason: 'the optional indirection is deactivated because FilterInfoUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_GWINFOIDXOFRXACCESSINFO                                                                 STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.GwInfoIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWINFOUSEDOFRXACCESSINFO                                                                STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.GwInfoUsed' Reason: 'The gateway is deactivated!' */
#define COM_INITVALUEIDXOFRXACCESSINFO                                                              STD_ON
#define COM_INITVALUEUSEDOFRXACCESSINFO                                                             STD_ON
#define COM_INVVALUEIDXOFRXACCESSINFO                                                               STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.InvValueIdx' Reason: 'the optional indirection is deactivated because InvValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_INVVALUEUSEDOFRXACCESSINFO                                                              STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.InvValueUsed' Reason: 'the optional indirection is deactivated because InvValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_INVALIDHNDOFRXACCESSINFO                                                                STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.InvalidHnd' Reason: 'the value of Com_InvalidHndOfRxAccessInfo is always 'false' due to this, the array is deactivated.' */
#define COM_ISGROUPSIGNALOFRXACCESSINFO                                                             STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.IsGroupSignal' Reason: 'the value of Com_IsGroupSignalOfRxAccessInfo is always 'false' due to this, the array is deactivated.' */
#define COM_ROUTINGBUFFERIDXOFRXACCESSINFO                                                          STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RoutingBufferIdx' Reason: 'The gateway is deactivated!' */
#define COM_ROUTINGBUFFERUSEDOFRXACCESSINFO                                                         STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RoutingBufferUsed' Reason: 'The gateway is deactivated!' */
#define COM_RXDATATIMEOUTSUBSTITUTIONVALUEIDXOFRXACCESSINFO                                         STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxDataTimeoutSubstitutionValueIdx' Reason: 'the optional indirection is deactivated because RxDataTimeoutSubstitutionValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXDATATIMEOUTSUBSTITUTIONVALUEUSEDOFRXACCESSINFO                                        STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxDataTimeoutSubstitutionValueUsed' Reason: 'the optional indirection is deactivated because RxDataTimeoutSubstitutionValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXPDUINFOIDXOFRXACCESSINFO                                                              STD_ON
#define COM_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO                                         STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxSigBufferArrayBasedBufferEndIdx' Reason: 'the optional indirection is deactivated because RxSigBufferArrayBasedBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXSIGBUFFERARRAYBASEDBUFFERLENGTHOFRXACCESSINFO                                         STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxSigBufferArrayBasedBufferLength' Reason: 'the optional indirection is deactivated because RxSigBufferArrayBasedBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO                                       STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxSigBufferArrayBasedBufferStartIdx' Reason: 'the optional indirection is deactivated because RxSigBufferArrayBasedBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXSIGBUFFERARRAYBASEDBUFFERUSEDOFRXACCESSINFO                                           STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxSigBufferArrayBasedBufferUsed' Reason: 'the optional indirection is deactivated because RxSigBufferArrayBasedBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO                                  STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxSigBufferArrayBasedRoutingBufferEndIdx' Reason: 'The gateway is deactivated!' */
#define COM_RXSIGBUFFERARRAYBASEDROUTINGBUFFERLENGTHOFRXACCESSINFO                                  STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxSigBufferArrayBasedRoutingBufferLength' Reason: 'The gateway is deactivated!' */
#define COM_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO                                STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxSigBufferArrayBasedRoutingBufferStartIdx' Reason: 'The gateway is deactivated!' */
#define COM_RXSIGBUFFERARRAYBASEDROUTINGBUFFERUSEDOFRXACCESSINFO                                    STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxSigBufferArrayBasedRoutingBufferUsed' Reason: 'The gateway is deactivated!' */
#define COM_RXSIGBUFFERARRAYBASEDSHDBUFFERENDIDXOFRXACCESSINFO                                      STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxSigBufferArrayBasedShdBufferEndIdx' Reason: 'the optional indirection is deactivated because RxSigBufferArrayBasedShdBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXSIGBUFFERARRAYBASEDSHDBUFFERLENGTHOFRXACCESSINFO                                      STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxSigBufferArrayBasedShdBufferLength' Reason: 'the optional indirection is deactivated because RxSigBufferArrayBasedShdBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXSIGBUFFERARRAYBASEDSHDBUFFERSTARTIDXOFRXACCESSINFO                                    STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxSigBufferArrayBasedShdBufferStartIdx' Reason: 'the optional indirection is deactivated because RxSigBufferArrayBasedShdBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXSIGBUFFERARRAYBASEDSHDBUFFERUSEDOFRXACCESSINFO                                        STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxSigBufferArrayBasedShdBufferUsed' Reason: 'the optional indirection is deactivated because RxSigBufferArrayBasedShdBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXTOUTINFOIDXOFRXACCESSINFO                                                             STD_ON
#define COM_RXTOUTINFOUSEDOFRXACCESSINFO                                                            STD_ON
#define COM_SHDBUFFERIDXOFRXACCESSINFO                                                              STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ShdBufferIdx' Reason: 'the optional indirection is deactivated because ShdBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_SHDBUFFERUSEDOFRXACCESSINFO                                                             STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ShdBufferUsed' Reason: 'the optional indirection is deactivated because ShdBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_SIGNEXTREQUIREDOFRXACCESSINFO                                                           STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.SignExtRequired' Reason: 'the value of Com_SignExtRequiredOfRxAccessInfo is always 'false' due to this, the array is deactivated.' */
#define COM_STARTBYTEINPDUPOSITIONOFRXACCESSINFO                                                    STD_ON
#define COM_TMPBUFFERIDXOFRXACCESSINFO                                                              STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.TmpBufferIdx' Reason: 'the optional indirection is deactivated because TmpBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TMPBUFFERUSEDOFRXACCESSINFO                                                             STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.TmpBufferUsed' Reason: 'the optional indirection is deactivated because TmpBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TMPRXSHDBUFFERARRAYBASEDTMPBUFFERENDIDXOFRXACCESSINFO                                   STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.TmpRxShdBufferArrayBasedTmpBufferEndIdx' Reason: 'the optional indirection is deactivated because TmpRxShdBufferArrayBasedTmpBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TMPRXSHDBUFFERARRAYBASEDTMPBUFFERLENGTHOFRXACCESSINFO                                   STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.TmpRxShdBufferArrayBasedTmpBufferLength' Reason: 'the optional indirection is deactivated because TmpRxShdBufferArrayBasedTmpBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TMPRXSHDBUFFERARRAYBASEDTMPBUFFERSTARTIDXOFRXACCESSINFO                                 STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.TmpRxShdBufferArrayBasedTmpBufferStartIdx' Reason: 'the optional indirection is deactivated because TmpRxShdBufferArrayBasedTmpBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TMPRXSHDBUFFERARRAYBASEDTMPBUFFERUSEDOFRXACCESSINFO                                     STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.TmpRxShdBufferArrayBasedTmpBufferUsed' Reason: 'the optional indirection is deactivated because TmpRxShdBufferArrayBasedTmpBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXACCESSINFOGRPSIGIND                                                                   STD_OFF  /**< Deactivateable: 'Com_RxAccessInfoGrpSigInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXACCESSINFOIND                                                                         STD_ON
#define COM_RXACCESSINFOREPLACEGRPSIGIND                                                            STD_OFF  /**< Deactivateable: 'Com_RxAccessInfoReplaceGrpSigInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXACCESSINFOREPLACESIGIND                                                               STD_OFF  /**< Deactivateable: 'Com_RxAccessInfoReplaceSigInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXCBKFUNCPTR                                                                            STD_ON
#define COM_RXDEADLINEMONITORINGISRLOCKCOUNTER                                                      STD_ON
#define COM_RXDEADLINEMONITORINGISRLOCKTHRESHOLD                                                    STD_ON
#define COM_RXDEFPDUBUFFER                                                                          STD_ON
#define COM_RXDEFERREDEVENTCACHE                                                                    STD_OFF  /**< Deactivateable: 'Com_RxDeferredEventCache' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDeferredEventCacheSupport] is configured to 'false'' */
#define COM_RXDEFERREDFCTPTRCACHE                                                                   STD_ON
#define COM_RXDEFERREDPROCESSINGISRLOCKCOUNTER                                                      STD_ON
#define COM_RXDEFERREDPROCESSINGISRLOCKTHRESHOLD                                                    STD_ON
#define COM_RXDLMONDIVISOR                                                                          STD_ON
#define COM_RXDLMONDIVISORCOUNTER                                                                   STD_ON
#define COM_RXDYNSIGNALLENGTH                                                                       STD_OFF  /**< Deactivateable: 'Com_RxDynSignalLength' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXDYNSIGNALTMPLENGTHFORSIGNALGROUPS                                                     STD_OFF  /**< Deactivateable: 'Com_RxDynSignalTmpLengthForSignalGroups' Reason: 'No dynamic length group signals are present' */
#define COM_RXIPDUGROUPISRLOCKCOUNTER                                                               STD_ON
#define COM_RXIPDUGROUPISRLOCKTHRESHOLD                                                             STD_ON
#define COM_RXNEXTEVENTCACHEENTY                                                                    STD_OFF  /**< Deactivateable: 'Com_RxNextEventCacheEnty' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDeferredEventCacheSupport] is configured to 'false'' */
#define COM_RXPDUCALLOUTFUNCPTR                                                                     STD_OFF  /**< Deactivateable: 'Com_RxPduCalloutFuncPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXPDUDMSTATE                                                                            STD_ON
#define COM_RXPDUGRPACTIVE                                                                          STD_ON
#define COM_RXPDUINFO                                                                               STD_ON
#define COM_DEFERREDGWMAPPINGINFOIDXOFRXPDUINFO                                                     STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.DeferredGwMappingInfoIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_DEFERREDGWMAPPINGINFOUSEDOFRXPDUINFO                                                    STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.DeferredGwMappingInfoUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_GWINFOENDIDXOFRXPDUINFO                                                                 STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.GwInfoEndIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWINFOSTARTIDXOFRXPDUINFO                                                               STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.GwInfoStartIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWINFOUSEDOFRXPDUINFO                                                                   STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.GwInfoUsed' Reason: 'The gateway is deactivated!' */
#define COM_GWTXPDUDESCRIPTIONINFOENDIDXOFRXPDUINFO                                                 STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.GwTxPduDescriptionInfoEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_GWTXPDUDESCRIPTIONINFOSTARTIDXOFRXPDUINFO                                               STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.GwTxPduDescriptionInfoStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_GWTXPDUDESCRIPTIONINFOUSEDOFRXPDUINFO                                                   STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.GwTxPduDescriptionInfoUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_HANDLERXDEFERREDGWDESCRIPTIONIDXOFRXPDUINFO                                             STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.HandleRxDeferredGwDescriptionIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_HANDLERXDEFERREDGWDESCRIPTIONUSEDOFRXPDUINFO                                            STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.HandleRxDeferredGwDescriptionUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_HANDLERXPDUDEFERREDIDXOFRXPDUINFO                                                       STD_ON
#define COM_HANDLERXPDUDEFERREDUSEDOFRXPDUINFO                                                      STD_ON
#define COM_IPDUGROUPINFOOFRXPDUINFOINDENDIDXOFRXPDUINFO                                            STD_ON
#define COM_IPDUGROUPINFOOFRXPDUINFOINDSTARTIDXOFRXPDUINFO                                          STD_ON
#define COM_IPDUGROUPINFOOFRXPDUINFOINDUSEDOFRXPDUINFO                                              STD_ON
#define COM_INVALIDHNDOFRXPDUINFO                                                                   STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.InvalidHnd' Reason: 'the value of Com_InvalidHndOfRxPduInfo is always 'false' due to this, the array is deactivated.' */
#define COM_METADATALENGTHOFRXPDUINFO                                                               STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.MetaDataLength' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMetaDataSupport] is configured to 'false'' */
#define COM_PDUGRPVECTORENDIDXOFRXPDUINFO                                                           STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.PduGrpVectorEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'true'' */
#define COM_PDUGRPVECTORSTARTIDXOFRXPDUINFO                                                         STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.PduGrpVectorStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'true'' */
#define COM_PDUGRPVECTORUSEDOFRXPDUINFO                                                             STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.PduGrpVectorUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'true'' */
#define COM_RXACCESSINFOINDENDIDXOFRXPDUINFO                                                        STD_ON
#define COM_RXACCESSINFOINDSTARTIDXOFRXPDUINFO                                                      STD_ON
#define COM_RXACCESSINFOINDUSEDOFRXPDUINFO                                                          STD_ON
#define COM_RXDEFPDUBUFFERENDIDXOFRXPDUINFO                                                         STD_ON
#define COM_RXDEFPDUBUFFERLENGTHOFRXPDUINFO                                                         STD_ON
#define COM_RXDEFPDUBUFFERSTARTIDXOFRXPDUINFO                                                       STD_ON
#define COM_RXDEFPDUBUFFERUSEDOFRXPDUINFO                                                           STD_ON
#define COM_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO                                                       STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.RxPduCalloutFuncPtrIdx' Reason: 'the optional indirection is deactivated because RxPduCalloutFuncPtrUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXPDUCALLOUTFUNCPTRUSEDOFRXPDUINFO                                                      STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.RxPduCalloutFuncPtrUsed' Reason: 'the optional indirection is deactivated because RxPduCalloutFuncPtrUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXSIGGRPINFOINDENDIDXOFRXPDUINFO                                                        STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.RxSigGrpInfoIndEndIdx' Reason: 'the optional indirection is deactivated because RxSigGrpInfoIndUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXSIGGRPINFOINDSTARTIDXOFRXPDUINFO                                                      STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.RxSigGrpInfoIndStartIdx' Reason: 'the optional indirection is deactivated because RxSigGrpInfoIndUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXSIGGRPINFOINDUSEDOFRXPDUINFO                                                          STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.RxSigGrpInfoIndUsed' Reason: 'the optional indirection is deactivated because RxSigGrpInfoIndUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXSIGINFOENDIDXOFRXPDUINFO                                                              STD_ON
#define COM_RXSIGINFOSTARTIDXOFRXPDUINFO                                                            STD_ON
#define COM_RXSIGINFOUSEDOFRXPDUINFO                                                                STD_ON
#define COM_RXTOUTINFOIDXOFRXPDUINFO                                                                STD_ON
#define COM_RXTOUTINFOINDENDIDXOFRXPDUINFO                                                          STD_ON
#define COM_RXTOUTINFOINDSTARTIDXOFRXPDUINFO                                                        STD_ON
#define COM_RXTOUTINFOINDUSEDOFRXPDUINFO                                                            STD_ON
#define COM_RXTOUTINFOUSEDOFRXPDUINFO                                                               STD_ON
#define COM_RXTPINFOIDXOFRXPDUINFO                                                                  STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.RxTpInfoIdx' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXTPINFOUSEDOFRXPDUINFO                                                                 STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.RxTpInfoUsed' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_SIGNALPROCESSINGOFRXPDUINFO                                                             STD_ON
#define COM_TYPEOFRXPDUINFO                                                                         STD_ON
#define COM_RXPDUINFOIND                                                                            STD_ON
#define COM_RXSIGARRAYACCESSSIGGRPBUFFER                                                            STD_OFF  /**< Deactivateable: 'Com_RxSigArrayAccessSigGrpBuffer' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGBUFFERARRAYBASED                                                                   STD_OFF  /**< Deactivateable: 'Com_RxSigBufferArrayBased' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGBUFFERFLOAT32                                                                      STD_OFF  /**< Deactivateable: 'Com_RxSigBufferFloat32' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGBUFFERFLOAT64                                                                      STD_OFF  /**< Deactivateable: 'Com_RxSigBufferFloat64' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGBUFFERSINT16                                                                       STD_OFF  /**< Deactivateable: 'Com_RxSigBufferSInt16' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGBUFFERSINT32                                                                       STD_OFF  /**< Deactivateable: 'Com_RxSigBufferSInt32' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGBUFFERSINT64                                                                       STD_OFF  /**< Deactivateable: 'Com_RxSigBufferSInt64' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGBUFFERSINT8                                                                        STD_OFF  /**< Deactivateable: 'Com_RxSigBufferSInt8' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGBUFFERUINT16                                                                       STD_ON
#define COM_RXSIGBUFFERUINT32                                                                       STD_ON
#define COM_RXSIGBUFFERUINT64                                                                       STD_OFF  /**< Deactivateable: 'Com_RxSigBufferUInt64' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGBUFFERUINT8                                                                        STD_ON
#define COM_RXSIGBUFFERZEROBIT                                                                      STD_OFF  /**< Deactivateable: 'Com_RxSigBufferZeroBit' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGGRPINFO                                                                            STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_ARRAYACCESSUSEDOFRXSIGGRPINFO                                                           STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.ArrayAccessUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_CONSTVALUESIGGRPARRAYACCESSENDIDXOFRXSIGGRPINFO                                         STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.ConstValueSigGrpArrayAccessEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUESIGGRPARRAYACCESSLENGTHOFRXSIGGRPINFO                                         STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.ConstValueSigGrpArrayAccessLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUESIGGRPARRAYACCESSSTARTIDXOFRXSIGGRPINFO                                       STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.ConstValueSigGrpArrayAccessStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUESIGGRPARRAYACCESSUSEDOFRXSIGGRPINFO                                           STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.ConstValueSigGrpArrayAccessUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUEUINT8ENDIDXOFRXSIGGRPINFO                                                     STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.ConstValueUInt8EndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUEUINT8LENGTHOFRXSIGGRPINFO                                                     STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.ConstValueUInt8Length' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUEUINT8STARTIDXOFRXSIGGRPINFO                                                   STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.ConstValueUInt8StartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUEUINT8USEDOFRXSIGGRPINFO                                                       STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.ConstValueUInt8Used' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTEREVENTOFRXSIGGRPINFO                                                               STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.FilterEvent' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_GWINFOIDXOFRXSIGGRPINFO                                                                 STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.GwInfoIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWINFOUSEDOFRXSIGGRPINFO                                                                STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.GwInfoUsed' Reason: 'The gateway is deactivated!' */
#define COM_INVEVENTOFRXSIGGRPINFO                                                                  STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.InvEvent' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_INVALIDHNDOFRXSIGGRPINFO                                                                STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.InvalidHnd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXACCESSINFOGRPSIGINDENDIDXOFRXSIGGRPINFO                                               STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxAccessInfoGrpSigIndEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXACCESSINFOGRPSIGINDSTARTIDXOFRXSIGGRPINFO                                             STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxAccessInfoGrpSigIndStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXACCESSINFOGRPSIGINDUSEDOFRXSIGGRPINFO                                                 STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxAccessInfoGrpSigIndUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXCBKFUNCPTRACKIDXOFRXSIGGRPINFO                                                        STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxCbkFuncPtrAckIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXCBKFUNCPTRACKUSEDOFRXSIGGRPINFO                                                       STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxCbkFuncPtrAckUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXCBKFUNCPTRINVACKIDXOFRXSIGGRPINFO                                                     STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxCbkFuncPtrInvAckIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXCBKFUNCPTRINVACKUSEDOFRXSIGGRPINFO                                                    STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxCbkFuncPtrInvAckUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXPDUINFOIDXOFRXSIGGRPINFO                                                              STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxPduInfoIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGARRAYACCESSSIGGRPBUFFERENDIDXOFRXSIGGRPINFO                                        STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxSigArrayAccessSigGrpBufferEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGARRAYACCESSSIGGRPBUFFERLENGTHOFRXSIGGRPINFO                                        STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxSigArrayAccessSigGrpBufferLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGARRAYACCESSSIGGRPBUFFERSTARTIDXOFRXSIGGRPINFO                                      STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxSigArrayAccessSigGrpBufferStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGARRAYACCESSSIGGRPBUFFERUSEDOFRXSIGGRPINFO                                          STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxSigArrayAccessSigGrpBufferUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGBUFFERUINT8ENDIDXOFRXSIGGRPINFO                                                    STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxSigBufferUInt8EndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGBUFFERUINT8LENGTHOFRXSIGGRPINFO                                                    STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxSigBufferUInt8Length' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGBUFFERUINT8STARTIDXOFRXSIGGRPINFO                                                  STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxSigBufferUInt8StartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGBUFFERUINT8USEDOFRXSIGGRPINFO                                                      STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxSigBufferUInt8Used' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXTOUTINFOIDXOFRXSIGGRPINFO                                                             STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxTOutInfoIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXTOUTINFOUSEDOFRXSIGGRPINFO                                                            STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxTOutInfoUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_SHDBUFFERREQUIREDOFRXSIGGRPINFO                                                         STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.ShdBufferRequired' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_SIGNALPROCESSINGOFRXSIGGRPINFO                                                          STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.SignalProcessing' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_STARTBYTEPOSITIONOFRXSIGGRPINFO                                                         STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.StartBytePosition' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_UBIDXOFRXSIGGRPINFO                                                                     STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.UbIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_UBMASKIDXOFRXSIGGRPINFO                                                                 STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.UbMaskIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_UBMASKUSEDOFRXSIGGRPINFO                                                                STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.UbMaskUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_VALIDDLCOFRXSIGGRPINFO                                                                  STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.ValidDlc' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGGRPINFOIND                                                                         STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfoInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGINFO                                                                               STD_ON
#define COM_GWINFOIDXOFRXSIGINFO                                                                    STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.GwInfoIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWINFOUSEDOFRXSIGINFO                                                                   STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.GwInfoUsed' Reason: 'The gateway is deactivated!' */
#define COM_RXACCESSINFOIDXOFRXSIGINFO                                                              STD_ON
#define COM_RXCBKFUNCPTRACKIDXOFRXSIGINFO                                                           STD_ON
#define COM_RXCBKFUNCPTRACKUSEDOFRXSIGINFO                                                          STD_ON
#define COM_RXCBKFUNCPTRINVACKIDXOFRXSIGINFO                                                        STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.RxCbkFuncPtrInvAckIdx' Reason: 'the optional indirection is deactivated because RxCbkFuncPtrInvAckUsedOfRxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXCBKFUNCPTRINVACKUSEDOFRXSIGINFO                                                       STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.RxCbkFuncPtrInvAckUsed' Reason: 'the optional indirection is deactivated because RxCbkFuncPtrInvAckUsedOfRxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXTOUTINFOIDXOFRXSIGINFO                                                                STD_ON
#define COM_RXTOUTINFOUSEDOFRXSIGINFO                                                               STD_ON
#define COM_SIGNALPROCESSINGOFRXSIGINFO                                                             STD_ON
#define COM_UBIDXOFRXSIGINFO                                                                        STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.UbIdx' Reason: 'the value of Com_UbIdxOfRxSigInfo is always 'COM_NO_UBIDXOFRXSIGINFO' due to this, the array is deactivated.' */
#define COM_UBMASKIDXOFRXSIGINFO                                                                    STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.UbMaskIdx' Reason: 'the optional indirection is deactivated because UbMaskUsedOfRxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_UBMASKUSEDOFRXSIGINFO                                                                   STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.UbMaskUsed' Reason: 'the optional indirection is deactivated because UbMaskUsedOfRxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_VALIDDLCOFRXSIGINFO                                                                     STD_ON
#define COM_RXTOUTCNT                                                                               STD_ON
#define COM_RXTOUTINFO                                                                              STD_ON
#define COM_CBKRXTOUTFUNCPTRINDENDIDXOFRXTOUTINFO                                                   STD_ON
#define COM_CBKRXTOUTFUNCPTRINDSTARTIDXOFRXTOUTINFO                                                 STD_ON
#define COM_CBKRXTOUTFUNCPTRINDUSEDOFRXTOUTINFO                                                     STD_ON
#define COM_FACTOROFRXTOUTINFO                                                                      STD_ON
#define COM_FIRSTFACTOROFRXTOUTINFO                                                                 STD_ON
#define COM_RXACCESSINFOREPLACEGRPSIGINDENDIDXOFRXTOUTINFO                                          STD_OFF  /**< Deactivateable: 'Com_RxTOutInfo.RxAccessInfoReplaceGrpSigIndEndIdx' Reason: 'the optional indirection is deactivated because RxAccessInfoReplaceGrpSigIndUsedOfRxTOutInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXACCESSINFOREPLACEGRPSIGINDSTARTIDXOFRXTOUTINFO                                        STD_OFF  /**< Deactivateable: 'Com_RxTOutInfo.RxAccessInfoReplaceGrpSigIndStartIdx' Reason: 'the optional indirection is deactivated because RxAccessInfoReplaceGrpSigIndUsedOfRxTOutInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXACCESSINFOREPLACEGRPSIGINDUSEDOFRXTOUTINFO                                            STD_OFF  /**< Deactivateable: 'Com_RxTOutInfo.RxAccessInfoReplaceGrpSigIndUsed' Reason: 'the optional indirection is deactivated because RxAccessInfoReplaceGrpSigIndUsedOfRxTOutInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXACCESSINFOREPLACESIGINDENDIDXOFRXTOUTINFO                                             STD_OFF  /**< Deactivateable: 'Com_RxTOutInfo.RxAccessInfoReplaceSigIndEndIdx' Reason: 'the optional indirection is deactivated because RxAccessInfoReplaceSigIndUsedOfRxTOutInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXACCESSINFOREPLACESIGINDSTARTIDXOFRXTOUTINFO                                           STD_OFF  /**< Deactivateable: 'Com_RxTOutInfo.RxAccessInfoReplaceSigIndStartIdx' Reason: 'the optional indirection is deactivated because RxAccessInfoReplaceSigIndUsedOfRxTOutInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXACCESSINFOREPLACESIGINDUSEDOFRXTOUTINFO                                               STD_OFF  /**< Deactivateable: 'Com_RxTOutInfo.RxAccessInfoReplaceSigIndUsed' Reason: 'the optional indirection is deactivated because RxAccessInfoReplaceSigIndUsedOfRxTOutInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXPDUINFOIDXOFRXTOUTINFO                                                                STD_ON
#define COM_RXTOUTINFOIND                                                                           STD_ON
#define COM_RXTPBUFFER                                                                              STD_OFF  /**< Deactivateable: 'Com_RxTpBuffer' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXTPCONNECTIONSTATE                                                                     STD_OFF  /**< Deactivateable: 'Com_RxTpConnectionState' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXTPINFO                                                                                STD_OFF  /**< Deactivateable: 'Com_RxTpInfo' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_BUFFERSIZEOFRXTPINFO                                                                    STD_OFF  /**< Deactivateable: 'Com_RxTpInfo.BufferSize' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_DYNAMICINITIALLENGTHOFRXTPINFO                                                          STD_OFF  /**< Deactivateable: 'Com_RxTpInfo.DynamicInitialLength' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXACCESSINFODYNSIGIDXOFRXTPINFO                                                         STD_OFF  /**< Deactivateable: 'Com_RxTpInfo.RxAccessInfoDynSigIdx' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXACCESSINFODYNSIGUSEDOFRXTPINFO                                                        STD_OFF  /**< Deactivateable: 'Com_RxTpInfo.RxAccessInfoDynSigUsed' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXTPBUFFERENDIDXOFRXTPINFO                                                              STD_OFF  /**< Deactivateable: 'Com_RxTpInfo.RxTpBufferEndIdx' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXTPBUFFERMETADATAENDIDXOFRXTPINFO                                                      STD_OFF  /**< Deactivateable: 'Com_RxTpInfo.RxTpBufferMetaDataEndIdx' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXTPBUFFERMETADATALENGTHOFRXTPINFO                                                      STD_OFF  /**< Deactivateable: 'Com_RxTpInfo.RxTpBufferMetaDataLength' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXTPBUFFERMETADATASTARTIDXOFRXTPINFO                                                    STD_OFF  /**< Deactivateable: 'Com_RxTpInfo.RxTpBufferMetaDataStartIdx' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXTPBUFFERMETADATAUSEDOFRXTPINFO                                                        STD_OFF  /**< Deactivateable: 'Com_RxTpInfo.RxTpBufferMetaDataUsed' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXTPBUFFERSTARTIDXOFRXTPINFO                                                            STD_OFF  /**< Deactivateable: 'Com_RxTpInfo.RxTpBufferStartIdx' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXTPBUFFERUSEDOFRXTPINFO                                                                STD_OFF  /**< Deactivateable: 'Com_RxTpInfo.RxTpBufferUsed' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXTPSDULENGTH                                                                           STD_OFF  /**< Deactivateable: 'Com_RxTpSduLength' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXTPWRITTENBYTESCOUNTER                                                                 STD_OFF  /**< Deactivateable: 'Com_RxTpWrittenBytesCounter' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_SIGGRPARRAYFILTERINFO                                                                   STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_CONSTVALUEUINT8FILTERMASKENDIDXOFSIGGRPARRAYFILTERINFO                                  STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.ConstValueUInt8FilterMaskEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_CONSTVALUEUINT8FILTERMASKLENGTHOFSIGGRPARRAYFILTERINFO                                  STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.ConstValueUInt8FilterMaskLength' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_CONSTVALUEUINT8FILTERMASKSTARTIDXOFSIGGRPARRAYFILTERINFO                                STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.ConstValueUInt8FilterMaskStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_CONSTVALUEUINT8FILTERMASKUSEDOFSIGGRPARRAYFILTERINFO                                    STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.ConstValueUInt8FilterMaskUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_CONSTVALUEUINT8FILTERVALUEXENDIDXOFSIGGRPARRAYFILTERINFO                                STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.ConstValueUInt8FilterValueXEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_CONSTVALUEUINT8FILTERVALUEXLENGTHOFSIGGRPARRAYFILTERINFO                                STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.ConstValueUInt8FilterValueXLength' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_CONSTVALUEUINT8FILTERVALUEXSTARTIDXOFSIGGRPARRAYFILTERINFO                              STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.ConstValueUInt8FilterValueXStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_CONSTVALUEUINT8FILTERVALUEXUSEDOFSIGGRPARRAYFILTERINFO                                  STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.ConstValueUInt8FilterValueXUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_FILTERALGOOFSIGGRPARRAYFILTERINFO                                                       STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.FilterAlgo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_OFFSETINSIGNALGROUPOFSIGGRPARRAYFILTERINFO                                              STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.OffsetInSignalGroup' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_SIGGRPEVENTFLAG                                                                         STD_OFF  /**< Deactivateable: 'Com_SigGrpEventFlag' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_SIZEOFALWAYSACTIVETXCOMIPDUS                                                            STD_ON
#define COM_SIZEOFCBKRXTOUTFUNCPTR                                                                  STD_ON
#define COM_SIZEOFCBKRXTOUTFUNCPTRIND                                                               STD_ON
#define COM_SIZEOFCONSTVALUEUINT16                                                                  STD_ON
#define COM_SIZEOFCONSTVALUEUINT32                                                                  STD_ON
#define COM_SIZEOFCONSTVALUEUINT8                                                                   STD_ON
#define COM_SIZEOFCURRENTTXMODE                                                                     STD_ON
#define COM_SIZEOFCYCLETIMECNT                                                                      STD_ON
#define COM_SIZEOFCYCLICSENDREQUEST                                                                 STD_ON
#define COM_SIZEOFHANDLERXPDUDEFERRED                                                               STD_ON
#define COM_SIZEOFIPDUGROUPINFO                                                                     STD_ON
#define COM_SIZEOFIPDUGROUPINFOOFRXPDUINFOIND                                                       STD_ON
#define COM_SIZEOFIPDUGROUPINFOOFTXPDUINFOIND                                                       STD_ON
#define COM_SIZEOFIPDUGROUPINFOTOSUBIPDUGROUPSIND                                                   STD_ON
#define COM_SIZEOFIPDUGROUPSTATE                                                                    STD_ON
#define COM_SIZEOFRXACCESSINFO                                                                      STD_ON
#define COM_SIZEOFRXACCESSINFOIND                                                                   STD_ON
#define COM_SIZEOFRXCBKFUNCPTR                                                                      STD_ON
#define COM_SIZEOFRXDEFPDUBUFFER                                                                    STD_ON
#define COM_SIZEOFRXDEFERREDFCTPTRCACHE                                                             STD_ON
#define COM_SIZEOFRXPDUDMSTATE                                                                      STD_ON
#define COM_SIZEOFRXPDUGRPACTIVE                                                                    STD_ON
#define COM_SIZEOFRXPDUINFO                                                                         STD_ON
#define COM_SIZEOFRXPDUINFOIND                                                                      STD_ON
#define COM_SIZEOFRXSIGBUFFERUINT16                                                                 STD_ON
#define COM_SIZEOFRXSIGBUFFERUINT32                                                                 STD_ON
#define COM_SIZEOFRXSIGBUFFERUINT8                                                                  STD_ON
#define COM_SIZEOFRXSIGINFO                                                                         STD_ON
#define COM_SIZEOFRXTOUTCNT                                                                         STD_ON
#define COM_SIZEOFRXTOUTINFO                                                                        STD_ON
#define COM_SIZEOFRXTOUTINFOIND                                                                     STD_ON
#define COM_SIZEOFTRANSMITREQUEST                                                                   STD_ON
#define COM_SIZEOFTXBUFFER                                                                          STD_ON
#define COM_SIZEOFTXCYCLICPDU                                                                       STD_ON
#define COM_SIZEOFTXMODEFALSE                                                                       STD_ON
#define COM_SIZEOFTXMODEINFO                                                                        STD_ON
#define COM_SIZEOFTXMODETRUE                                                                        STD_ON
#define COM_SIZEOFTXPDUGRPACTIVE                                                                    STD_ON
#define COM_SIZEOFTXPDUINFO                                                                         STD_ON
#define COM_SIZEOFTXPDUINFOIND                                                                      STD_ON
#define COM_SIZEOFTXPDUINITVALUE                                                                    STD_ON
#define COM_SIZEOFTXSDULENGTH                                                                       STD_ON
#define COM_SIZEOFTXSIGINFO                                                                         STD_ON
#define COM_SOURCEDESCRIPTIONMASK                                                                   STD_OFF  /**< Deactivateable: 'Com_SourceDescriptionMask' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_TMPRXBUFFER                                                                             STD_OFF  /**< Deactivateable: 'Com_TmpRxBuffer' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TMPRXSHDBUFFERARRAYBASED                                                                STD_OFF  /**< Deactivateable: 'Com_TmpRxShdBufferArrayBased' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TMPRXSHDBUFFERFLOAT32                                                                   STD_OFF  /**< Deactivateable: 'Com_TmpRxShdBufferFloat32' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TMPRXSHDBUFFERFLOAT64                                                                   STD_OFF  /**< Deactivateable: 'Com_TmpRxShdBufferFloat64' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TMPRXSHDBUFFERSINT16                                                                    STD_OFF  /**< Deactivateable: 'Com_TmpRxShdBufferSInt16' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TMPRXSHDBUFFERSINT32                                                                    STD_OFF  /**< Deactivateable: 'Com_TmpRxShdBufferSInt32' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TMPRXSHDBUFFERSINT64                                                                    STD_OFF  /**< Deactivateable: 'Com_TmpRxShdBufferSInt64' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TMPRXSHDBUFFERSINT8                                                                     STD_OFF  /**< Deactivateable: 'Com_TmpRxShdBufferSInt8' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TMPRXSHDBUFFERUINT16                                                                    STD_OFF  /**< Deactivateable: 'Com_TmpRxShdBufferUInt16' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TMPRXSHDBUFFERUINT32                                                                    STD_OFF  /**< Deactivateable: 'Com_TmpRxShdBufferUInt32' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TMPRXSHDBUFFERUINT64                                                                    STD_OFF  /**< Deactivateable: 'Com_TmpRxShdBufferUInt64' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TMPRXSHDBUFFERUINT8                                                                     STD_OFF  /**< Deactivateable: 'Com_TmpRxShdBufferUInt8' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TRANSMITREQUEST                                                                         STD_ON
#define COM_TXBUFFER                                                                                STD_ON
#define COM_TXCYCLECOUNTERDIVISOR                                                                   STD_ON
#define COM_TXCYCLECOUNTERDIVISORCOUNTER                                                            STD_ON
#define COM_TXCYCLICPDU                                                                             STD_ON
#define COM_TXPDUINFOIDXOFTXCYCLICPDU                                                               STD_ON
#define COM_TXCYCLICPROCESSINGISRLOCKCOUNTER                                                        STD_ON
#define COM_TXCYCLICPROCESSINGISRLOCKTHRESHOLD                                                      STD_ON
#define COM_TXDEADLINEMONITORINGISRLOCKCOUNTER                                                      STD_OFF  /**< Deactivateable: 'Com_TxDeadlineMonitoringISRLockCounter' Reason: 'No Tx Signals or SignalGroups with a configured timeout are present. ' */
#define COM_TXDEADLINEMONITORINGISRLOCKTHRESHOLD                                                    STD_OFF  /**< Deactivateable: 'Com_TxDeadlineMonitoringISRLockThreshold' Reason: 'No Tx Signals or SignalGroups with a configured timeout are present. ' */
#define COM_TXDLMONDIVISOR                                                                          STD_OFF  /**< Deactivateable: 'Com_TxDlMonDivisor' Reason: 'Timing domain and corresponding timing divisor are deactivated, because no value is configured for TxDlMonTimeBase.' */
#define COM_TXDLMONDIVISORCOUNTER                                                                   STD_OFF  /**< Deactivateable: 'Com_TxDlMonDivisorCounter' Reason: 'Timing domain and corresponding timing divisor are deactivated, because no value is configured for TxDlMonTimeBase.' */
#define COM_TXDYNSIGNALLENGTH                                                                       STD_OFF  /**< Deactivateable: 'Com_TxDynSignalLength' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXFILTERINITSTATE                                                                       STD_OFF  /**< Deactivateable: 'Com_TxFilterInitState' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITVALUEARRAYBASED                                                             STD_OFF  /**< Deactivateable: 'Com_TxFilterInitValueArrayBased' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITVALUEFLOAT32                                                                STD_OFF  /**< Deactivateable: 'Com_TxFilterInitValueFloat32' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITVALUEFLOAT64                                                                STD_OFF  /**< Deactivateable: 'Com_TxFilterInitValueFloat64' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITVALUESINT16                                                                 STD_OFF  /**< Deactivateable: 'Com_TxFilterInitValueSInt16' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITVALUESINT32                                                                 STD_OFF  /**< Deactivateable: 'Com_TxFilterInitValueSInt32' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITVALUESINT64                                                                 STD_OFF  /**< Deactivateable: 'Com_TxFilterInitValueSInt64' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITVALUESINT8                                                                  STD_OFF  /**< Deactivateable: 'Com_TxFilterInitValueSInt8' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITVALUESIGGRPARRAYACCESS                                                      STD_OFF  /**< Deactivateable: 'Com_TxFilterInitValueSigGrpArrayAccess' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITVALUEUINT16                                                                 STD_OFF  /**< Deactivateable: 'Com_TxFilterInitValueUInt16' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITVALUEUINT32                                                                 STD_OFF  /**< Deactivateable: 'Com_TxFilterInitValueUInt32' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITVALUEUINT64                                                                 STD_OFF  /**< Deactivateable: 'Com_TxFilterInitValueUInt64' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITVALUEUINT8                                                                  STD_OFF  /**< Deactivateable: 'Com_TxFilterInitValueUInt8' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTEROLDVALUEARRAYBASED                                                              STD_OFF  /**< Deactivateable: 'Com_TxFilterOldValueArrayBased' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTEROLDVALUEFLOAT32                                                                 STD_OFF  /**< Deactivateable: 'Com_TxFilterOldValueFloat32' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTEROLDVALUEFLOAT64                                                                 STD_OFF  /**< Deactivateable: 'Com_TxFilterOldValueFloat64' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTEROLDVALUESINT16                                                                  STD_OFF  /**< Deactivateable: 'Com_TxFilterOldValueSInt16' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTEROLDVALUESINT32                                                                  STD_OFF  /**< Deactivateable: 'Com_TxFilterOldValueSInt32' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTEROLDVALUESINT64                                                                  STD_OFF  /**< Deactivateable: 'Com_TxFilterOldValueSInt64' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTEROLDVALUESINT8                                                                   STD_OFF  /**< Deactivateable: 'Com_TxFilterOldValueSInt8' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTEROLDVALUEUINT16                                                                  STD_OFF  /**< Deactivateable: 'Com_TxFilterOldValueUInt16' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTEROLDVALUEUINT32                                                                  STD_OFF  /**< Deactivateable: 'Com_TxFilterOldValueUInt32' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTEROLDVALUEUINT64                                                                  STD_OFF  /**< Deactivateable: 'Com_TxFilterOldValueUInt64' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTEROLDVALUEUINT8                                                                   STD_OFF  /**< Deactivateable: 'Com_TxFilterOldValueUInt8' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERSTATE                                                                           STD_OFF  /**< Deactivateable: 'Com_TxFilterState' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXIPDUGROUPISRLOCKCOUNTER                                                               STD_ON
#define COM_TXIPDUGROUPISRLOCKTHRESHOLD                                                             STD_ON
#define COM_TXMODEFALSE                                                                             STD_ON
#define COM_DIRECTOFTXMODEFALSE                                                                     STD_OFF  /**< Deactivateable: 'Com_TxModeFalse.Direct' Reason: 'the value of Com_DirectOfTxModeFalse is always 'false' due to this, the array is deactivated.' */
#define COM_PERIODICOFTXMODEFALSE                                                                   STD_ON
#define COM_REPCNTOFTXMODEFALSE                                                                     STD_OFF  /**< Deactivateable: 'Com_TxModeFalse.RepCnt' Reason: 'the value of Com_RepCntOfTxModeFalse is always '0' due to this, the array is deactivated.' */
#define COM_REPPERIODOFTXMODEFALSE                                                                  STD_OFF  /**< Deactivateable: 'Com_TxModeFalse.RepPeriod' Reason: 'the value of Com_RepPeriodOfTxModeFalse is always '0' due to this, the array is deactivated.' */
#define COM_TIMEOFFSETOFTXMODEFALSE                                                                 STD_OFF  /**< Deactivateable: 'Com_TxModeFalse.TimeOffset' Reason: 'the value of Com_TimeOffsetOfTxModeFalse is always '1' due to this, the array is deactivated.' */
#define COM_TIMEPERIODOFTXMODEFALSE                                                                 STD_ON
#define COM_TXMODEINFO                                                                              STD_ON
#define COM_INITMODEOFTXMODEINFO                                                                    STD_ON
#define COM_INVALIDHNDOFTXMODEINFO                                                                  STD_OFF  /**< Deactivateable: 'Com_TxModeInfo.InvalidHnd' Reason: 'the value of Com_InvalidHndOfTxModeInfo is always 'false' due to this, the array is deactivated.' */
#define COM_MINIMUMDELAYOFTXMODEINFO                                                                STD_OFF  /**< Deactivateable: 'Com_TxModeInfo.MinimumDelay' Reason: 'the value of Com_MinimumDelayOfTxModeInfo is always '0' due to this, the array is deactivated.' */
#define COM_TXFILTERINITSTATEENDIDXOFTXMODEINFO                                                     STD_OFF  /**< Deactivateable: 'Com_TxModeInfo.TxFilterInitStateEndIdx' Reason: 'the optional indirection is deactivated because TxFilterInitStateUsedOfTxModeInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXFILTERINITSTATESTARTIDXOFTXMODEINFO                                                   STD_OFF  /**< Deactivateable: 'Com_TxModeInfo.TxFilterInitStateStartIdx' Reason: 'the optional indirection is deactivated because TxFilterInitStateUsedOfTxModeInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXFILTERINITSTATEUSEDOFTXMODEINFO                                                       STD_OFF  /**< Deactivateable: 'Com_TxModeInfo.TxFilterInitStateUsed' Reason: 'the optional indirection is deactivated because TxFilterInitStateUsedOfTxModeInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXMODEFALSEIDXOFTXMODEINFO                                                              STD_ON
#define COM_TXMODETRUEIDXOFTXMODEINFO                                                               STD_ON
#define COM_TXSIGINFOFILTERINITVALUEINDENDIDXOFTXMODEINFO                                           STD_OFF  /**< Deactivateable: 'Com_TxModeInfo.TxSigInfoFilterInitValueIndEndIdx' Reason: 'the optional indirection is deactivated because TxSigInfoFilterInitValueIndUsedOfTxModeInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXSIGINFOFILTERINITVALUEINDSTARTIDXOFTXMODEINFO                                         STD_OFF  /**< Deactivateable: 'Com_TxModeInfo.TxSigInfoFilterInitValueIndStartIdx' Reason: 'the optional indirection is deactivated because TxSigInfoFilterInitValueIndUsedOfTxModeInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXSIGINFOFILTERINITVALUEINDUSEDOFTXMODEINFO                                             STD_OFF  /**< Deactivateable: 'Com_TxModeInfo.TxSigInfoFilterInitValueIndUsed' Reason: 'the optional indirection is deactivated because TxSigInfoFilterInitValueIndUsedOfTxModeInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXMODETRUE                                                                              STD_ON
#define COM_DIRECTOFTXMODETRUE                                                                      STD_OFF  /**< Deactivateable: 'Com_TxModeTrue.Direct' Reason: 'the value of Com_DirectOfTxModeTrue is always 'false' due to this, the array is deactivated.' */
#define COM_PERIODICOFTXMODETRUE                                                                    STD_ON
#define COM_REPCNTOFTXMODETRUE                                                                      STD_OFF  /**< Deactivateable: 'Com_TxModeTrue.RepCnt' Reason: 'the value of Com_RepCntOfTxModeTrue is always '0' due to this, the array is deactivated.' */
#define COM_REPPERIODOFTXMODETRUE                                                                   STD_OFF  /**< Deactivateable: 'Com_TxModeTrue.RepPeriod' Reason: 'the value of Com_RepPeriodOfTxModeTrue is always '0' due to this, the array is deactivated.' */
#define COM_TIMEOFFSETOFTXMODETRUE                                                                  STD_OFF  /**< Deactivateable: 'Com_TxModeTrue.TimeOffset' Reason: 'the value of Com_TimeOffsetOfTxModeTrue is always '1' due to this, the array is deactivated.' */
#define COM_TIMEPERIODOFTXMODETRUE                                                                  STD_ON
#define COM_TXPDUCALLOUTFUNCPTR                                                                     STD_OFF  /**< Deactivateable: 'Com_TxPduCalloutFuncPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXPDUGRPACTIVE                                                                          STD_ON
#define COM_TXPDUINFO                                                                               STD_ON
#define COM_CANCELLATIONSUPPORTOFTXPDUINFO                                                          STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.CancellationSupport' Reason: '/ActiveEcuC/PduR/Com[0:PduRCancelTransmit] is configured to 'false'' */
#define COM_CBKTXACKDEFFUNCPTRINDENDIDXOFTXPDUINFO                                                  STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.CbkTxAckDefFuncPtrIndEndIdx' Reason: 'the optional indirection is deactivated because CbkTxAckDefFuncPtrIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CBKTXACKDEFFUNCPTRINDSTARTIDXOFTXPDUINFO                                                STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.CbkTxAckDefFuncPtrIndStartIdx' Reason: 'the optional indirection is deactivated because CbkTxAckDefFuncPtrIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CBKTXACKDEFFUNCPTRINDUSEDOFTXPDUINFO                                                    STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.CbkTxAckDefFuncPtrIndUsed' Reason: 'the optional indirection is deactivated because CbkTxAckDefFuncPtrIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CBKTXACKIMFUNCPTRINDENDIDXOFTXPDUINFO                                                   STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.CbkTxAckImFuncPtrIndEndIdx' Reason: 'the optional indirection is deactivated because CbkTxAckImFuncPtrIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CBKTXACKIMFUNCPTRINDSTARTIDXOFTXPDUINFO                                                 STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.CbkTxAckImFuncPtrIndStartIdx' Reason: 'the optional indirection is deactivated because CbkTxAckImFuncPtrIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CBKTXACKIMFUNCPTRINDUSEDOFTXPDUINFO                                                     STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.CbkTxAckImFuncPtrIndUsed' Reason: 'the optional indirection is deactivated because CbkTxAckImFuncPtrIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CBKTXERRFUNCPTRINDENDIDXOFTXPDUINFO                                                     STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.CbkTxErrFuncPtrIndEndIdx' Reason: 'the optional indirection is deactivated because CbkTxErrFuncPtrIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CBKTXERRFUNCPTRINDSTARTIDXOFTXPDUINFO                                                   STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.CbkTxErrFuncPtrIndStartIdx' Reason: 'the optional indirection is deactivated because CbkTxErrFuncPtrIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CBKTXERRFUNCPTRINDUSEDOFTXPDUINFO                                                       STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.CbkTxErrFuncPtrIndUsed' Reason: 'the optional indirection is deactivated because CbkTxErrFuncPtrIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CLRUBOFTXPDUINFO                                                                        STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.ClrUb' Reason: 'This array is deactivated, because no Tx I-PDUs with update-bits are configured.' */
#define COM_CONSTVALUEUINT8UBCLEARMASKENDIDXOFTXPDUINFO                                             STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.ConstValueUInt8UbClearMaskEndIdx' Reason: 'the optional indirection is deactivated because ConstValueUInt8UbClearMaskUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEUINT8UBCLEARMASKSTARTIDXOFTXPDUINFO                                           STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.ConstValueUInt8UbClearMaskStartIdx' Reason: 'the optional indirection is deactivated because ConstValueUInt8UbClearMaskUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEUINT8UBCLEARMASKUSEDOFTXPDUINFO                                               STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.ConstValueUInt8UbClearMaskUsed' Reason: 'the optional indirection is deactivated because ConstValueUInt8UbClearMaskUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXTERNALIDOFTXPDUINFO                                                                   STD_ON
#define COM_GWTIMEOUTINFOIDXOFTXPDUINFO                                                             STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.GwTimeoutInfoIdx' Reason: 'the optional indirection is deactivated because GwTimeoutInfoUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_GWTIMEOUTINFOUSEDOFTXPDUINFO                                                            STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.GwTimeoutInfoUsed' Reason: 'the optional indirection is deactivated because GwTimeoutInfoUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_IPDUGROUPINFOOFTXPDUINFOINDENDIDXOFTXPDUINFO                                            STD_ON
#define COM_IPDUGROUPINFOOFTXPDUINFOINDSTARTIDXOFTXPDUINFO                                          STD_ON
#define COM_IPDUGROUPINFOOFTXPDUINFOINDUSEDOFTXPDUINFO                                              STD_ON
#define COM_INVALIDHNDOFTXPDUINFO                                                                   STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.InvalidHnd' Reason: 'the value of Com_InvalidHndOfTxPduInfo is always 'false' due to this, the array is deactivated.' */
#define COM_METADATALENGTHOFTXPDUINFO                                                               STD_ON
#define COM_PDUGRPVECTORENDIDXOFTXPDUINFO                                                           STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.PduGrpVectorEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'true'' */
#define COM_PDUGRPVECTORSTARTIDXOFTXPDUINFO                                                         STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.PduGrpVectorStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'true'' */
#define COM_PDUGRPVECTORUSEDOFTXPDUINFO                                                             STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.PduGrpVectorUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'true'' */
#define COM_PDUWITHMETADATALENGTHOFTXPDUINFO                                                        STD_ON
#define COM_TXBUFFERENDIDXOFTXPDUINFO                                                               STD_ON
#define COM_TXBUFFERLENGTHOFTXPDUINFO                                                               STD_ON
#define COM_TXBUFFERMETADATAENDIDXOFTXPDUINFO                                                       STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxBufferMetaDataEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMetaDataSupport] is configured to 'false'' */
#define COM_TXBUFFERMETADATALENGTHOFTXPDUINFO                                                       STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxBufferMetaDataLength' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMetaDataSupport] is configured to 'false'' */
#define COM_TXBUFFERMETADATASTARTIDXOFTXPDUINFO                                                     STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxBufferMetaDataStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMetaDataSupport] is configured to 'false'' */
#define COM_TXBUFFERMETADATAUSEDOFTXPDUINFO                                                         STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxBufferMetaDataUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMetaDataSupport] is configured to 'false'' */
#define COM_TXBUFFERSTARTIDXOFTXPDUINFO                                                             STD_ON
#define COM_TXBUFFERUSEDOFTXPDUINFO                                                                 STD_ON
#define COM_TXPDUCALLOUTFUNCPTRIDXOFTXPDUINFO                                                       STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxPduCalloutFuncPtrIdx' Reason: 'the optional indirection is deactivated because TxPduCalloutFuncPtrUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXPDUCALLOUTFUNCPTRUSEDOFTXPDUINFO                                                      STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxPduCalloutFuncPtrUsed' Reason: 'the optional indirection is deactivated because TxPduCalloutFuncPtrUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXPDUINITVALUEENDIDXOFTXPDUINFO                                                         STD_ON
#define COM_TXPDUINITVALUEMETADATAENDIDXOFTXPDUINFO                                                 STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxPduInitValueMetaDataEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMetaDataSupport] is configured to 'false'' */
#define COM_TXPDUINITVALUEMETADATASTARTIDXOFTXPDUINFO                                               STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxPduInitValueMetaDataStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMetaDataSupport] is configured to 'false'' */
#define COM_TXPDUINITVALUEMETADATAUSEDOFTXPDUINFO                                                   STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxPduInitValueMetaDataUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMetaDataSupport] is configured to 'false'' */
#define COM_TXPDUINITVALUESTARTIDXOFTXPDUINFO                                                       STD_ON
#define COM_TXPDUINITVALUEUSEDOFTXPDUINFO                                                           STD_ON
#define COM_TXPDUTTCALLOUTFUNCPTRIDXOFTXPDUINFO                                                     STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxPduTTCalloutFuncPtrIdx' Reason: 'the optional indirection is deactivated because TxPduTTCalloutFuncPtrUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXPDUTTCALLOUTFUNCPTRUSEDOFTXPDUINFO                                                    STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxPduTTCalloutFuncPtrUsed' Reason: 'the optional indirection is deactivated because TxPduTTCalloutFuncPtrUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXSIGGRPINFOINDENDIDXOFTXPDUINFO                                                        STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxSigGrpInfoIndEndIdx' Reason: 'the optional indirection is deactivated because TxSigGrpInfoIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXSIGGRPINFOINDSTARTIDXOFTXPDUINFO                                                      STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxSigGrpInfoIndStartIdx' Reason: 'the optional indirection is deactivated because TxSigGrpInfoIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXSIGGRPINFOINDUSEDOFTXPDUINFO                                                          STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxSigGrpInfoIndUsed' Reason: 'the optional indirection is deactivated because TxSigGrpInfoIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXTOUTINFOIDXOFTXPDUINFO                                                                STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxTOutInfoIdx' Reason: 'the optional indirection is deactivated because TxTOutInfoUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXTOUTINFOUSEDOFTXPDUINFO                                                               STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxTOutInfoUsed' Reason: 'the optional indirection is deactivated because TxTOutInfoUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXTPINFOIDXOFTXPDUINFO                                                                  STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxTpInfoIdx' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXTPINFOUSEDOFTXPDUINFO                                                                 STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxTpInfoUsed' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXPDUINFOIND                                                                            STD_ON
#define COM_TXPDUINITVALUE                                                                          STD_ON
#define COM_TXPDUTTCALLOUTFUNCPTR                                                                   STD_OFF  /**< Deactivateable: 'Com_TxPduTTCalloutFuncPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXPROCESSINGISRLOCKCOUNTER                                                              STD_ON
#define COM_TXPROCESSINGISRLOCKTHRESHOLD                                                            STD_ON
#define COM_TXSDULENGTH                                                                             STD_ON
#define COM_TXSIGGRPINFO                                                                            STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_ARRAYACCESSUSEDOFTXSIGGRPINFO                                                           STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.ArrayAccessUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_INVALIDHNDOFTXSIGGRPINFO                                                                STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.InvalidHnd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_PDUOFFSETOFTXSIGGRPINFO                                                                 STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.PduOffset' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_SIGGROUPONCHANGEOFFSETOFTXSIGGRPINFO                                                    STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.SigGroupOnChangeOffset' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_SIGGROUPONCHANGESTARTPOSITIONOFTXSIGGRPINFO                                             STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.SigGroupOnChangeStartPosition' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_SIGGROUPONCHANGEWITHOUTREPOFFSETOFTXSIGGRPINFO                                          STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.SigGroupOnChangeWithoutRepOffset' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_SIGGROUPONCHANGEWITHOUTREPSTARTPOSITIONOFTXSIGGRPINFO                                   STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.SigGroupOnChangeWithoutRepStartPosition' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_SIGGRPARRAYFILTERINFOENDIDXOFTXSIGGRPINFO                                               STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.SigGrpArrayFilterInfoEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_SIGGRPARRAYFILTERINFOSTARTIDXOFTXSIGGRPINFO                                             STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.SigGrpArrayFilterInfoStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_SIGGRPARRAYFILTERINFOUSEDOFTXSIGGRPINFO                                                 STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.SigGrpArrayFilterInfoUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_TRANSFERPROPERTYOFTXSIGGRPINFO                                                          STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TransferProperty' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXBUFFERENDIDXOFTXSIGGRPINFO                                                            STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxBufferEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXBUFFERLENGTHOFTXSIGGRPINFO                                                            STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxBufferLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXBUFFERSIGGRPINTXIPDUENDIDXOFTXSIGGRPINFO                                              STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxBufferSigGrpInTxIPDUEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXBUFFERSIGGRPINTXIPDULENGTHOFTXSIGGRPINFO                                              STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxBufferSigGrpInTxIPDULength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXBUFFERSIGGRPINTXIPDUSTARTIDXOFTXSIGGRPINFO                                            STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxBufferSigGrpInTxIPDUStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXBUFFERSTARTIDXOFTXSIGGRPINFO                                                          STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxBufferStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXBUFFERUBIDXINTXBUFFERIDXOFTXSIGGRPINFO                                                STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxBufferUbIdxInTxBufferIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXBUFFERUBIDXINTXBUFFERUSEDOFTXSIGGRPINFO                                               STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxBufferUbIdxInTxBufferUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXBUFFERUSEDOFTXSIGGRPINFO                                                              STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxBufferUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITSTATEENDIDXOFTXSIGGRPINFO                                                   STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxFilterInitStateEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITSTATESTARTIDXOFTXSIGGRPINFO                                                 STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxFilterInitStateStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITSTATEUSEDOFTXSIGGRPINFO                                                     STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxFilterInitStateUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXPDUINFOIDXOFTXSIGGRPINFO                                                              STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxPduInfoIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXSIGGRPMASKENDIDXOFTXSIGGRPINFO                                                        STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpMaskEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXSIGGRPMASKLENGTHOFTXSIGGRPINFO                                                        STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpMaskLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXSIGGRPMASKSTARTIDXOFTXSIGGRPINFO                                                      STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpMaskStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXSIGGRPMASKUSEDOFTXSIGGRPINFO                                                          STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpMaskUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXSIGGRPONCHANGEMASKONCHANGEENDIDXOFTXSIGGRPINFO                                        STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpOnChangeMaskOnChangeEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_TXSIGGRPONCHANGEMASKONCHANGELENGTHOFTXSIGGRPINFO                                        STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpOnChangeMaskOnChangeLength' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_TXSIGGRPONCHANGEMASKONCHANGESTARTIDXOFTXSIGGRPINFO                                      STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpOnChangeMaskOnChangeStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_TXSIGGRPONCHANGEMASKONCHANGEUSEDOFTXSIGGRPINFO                                          STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpOnChangeMaskOnChangeUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_TXSIGGRPONCHANGEMASKONCHANGEWITHOUTREPENDIDXOFTXSIGGRPINFO                              STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpOnChangeMaskOnChangeWithoutRepEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_TXSIGGRPONCHANGEMASKONCHANGEWITHOUTREPLENGTHOFTXSIGGRPINFO                              STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpOnChangeMaskOnChangeWithoutRepLength' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_TXSIGGRPONCHANGEMASKONCHANGEWITHOUTREPSTARTIDXOFTXSIGGRPINFO                            STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpOnChangeMaskOnChangeWithoutRepStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_TXSIGGRPONCHANGEMASKONCHANGEWITHOUTREPUSEDOFTXSIGGRPINFO                                STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpOnChangeMaskOnChangeWithoutRepUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_TXSIGINFOINVVALUEINDENDIDXOFTXSIGGRPINFO                                                STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigInfoInvValueIndEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXSIGINFOINVVALUEINDSTARTIDXOFTXSIGGRPINFO                                              STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigInfoInvValueIndStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXSIGINFOINVVALUEINDUSEDOFTXSIGGRPINFO                                                  STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigInfoInvValueIndUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_UBMASKIDXOFTXSIGGRPINFO                                                                 STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.UbMaskIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_UBMASKUSEDOFTXSIGGRPINFO                                                                STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.UbMaskUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXSIGGRPINFOIND                                                                         STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfoInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXSIGGRPMASK                                                                            STD_OFF  /**< Deactivateable: 'Com_TxSigGrpMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXSIGGRPONCHANGEMASK                                                                    STD_OFF  /**< Deactivateable: 'Com_TxSigGrpOnChangeMask' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_TXSIGINFO                                                                               STD_ON
#define COM_APPLTYPEOFTXSIGINFO                                                                     STD_ON
#define COM_BITLENGTHOFTXSIGINFO                                                                    STD_ON
#define COM_BITPOSITIONOFTXSIGINFO                                                                  STD_ON
#define COM_BUSACCOFTXSIGINFO                                                                       STD_ON
#define COM_BYTELENGTHOFTXSIGINFO                                                                   STD_ON
#define COM_BYTEPOSITIONOFTXSIGINFO                                                                 STD_ON
#define COM_CONSTVALUEARRAYBASEDINVVALUEENDIDXOFTXSIGINFO                                           STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.ConstValueArrayBasedInvValueEndIdx' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedInvValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEARRAYBASEDINVVALUELENGTHOFTXSIGINFO                                           STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.ConstValueArrayBasedInvValueLength' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedInvValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEARRAYBASEDINVVALUESTARTIDXOFTXSIGINFO                                         STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.ConstValueArrayBasedInvValueStartIdx' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedInvValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEARRAYBASEDINVVALUEUSEDOFTXSIGINFO                                             STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.ConstValueArrayBasedInvValueUsed' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedInvValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_FILTERINFOIDXOFTXSIGINFO                                                                STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.FilterInfoIdx' Reason: 'the optional indirection is deactivated because FilterInfoUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_FILTERINFOUSEDOFTXSIGINFO                                                               STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.FilterInfoUsed' Reason: 'the optional indirection is deactivated because FilterInfoUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_FILTERINITVALUEIDXOFTXSIGINFO                                                           STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.FilterInitValueIdx' Reason: 'the optional indirection is deactivated because FilterInitValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_FILTERINITVALUEUSEDOFTXSIGINFO                                                          STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.FilterInitValueUsed' Reason: 'the optional indirection is deactivated because FilterInitValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_INVVALUEIDXOFTXSIGINFO                                                                  STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.InvValueIdx' Reason: 'the optional indirection is deactivated because InvValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_INVVALUEUSEDOFTXSIGINFO                                                                 STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.InvValueUsed' Reason: 'the optional indirection is deactivated because InvValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_INVALIDHNDOFTXSIGINFO                                                                   STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.InvalidHnd' Reason: 'the value of Com_InvalidHndOfTxSigInfo is always 'false' due to this, the array is deactivated.' */
#define COM_ONCHANGEIDXOFTXSIGINFO                                                                  STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.OnChangeIdx' Reason: 'the optional indirection is deactivated because OnChangeUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_ONCHANGEUSEDOFTXSIGINFO                                                                 STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.OnChangeUsed' Reason: 'the optional indirection is deactivated because OnChangeUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_STARTBYTEINPDUPOSITIONOFTXSIGINFO                                                       STD_ON
#define COM_TRIGGEREDOFTXSIGINFO                                                                    STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.Triggered' Reason: 'the value of Com_TriggeredOfTxSigInfo is always 'false' due to this, the array is deactivated.' */
#define COM_TXBUFFERENDIDXOFTXSIGINFO                                                               STD_ON
#define COM_TXBUFFERLENGTHOFTXSIGINFO                                                               STD_ON
#define COM_TXBUFFERSTARTIDXOFTXSIGINFO                                                             STD_ON
#define COM_TXBUFFERUBIDXINTXBUFFERIDXOFTXSIGINFO                                                   STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.TxBufferUbIdxInTxBufferIdx' Reason: 'the optional indirection is deactivated because TxBufferUbIdxInTxBufferUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXBUFFERUBIDXINTXBUFFERUSEDOFTXSIGINFO                                                  STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.TxBufferUbIdxInTxBufferUsed' Reason: 'the optional indirection is deactivated because TxBufferUbIdxInTxBufferUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXBUFFERUSEDOFTXSIGINFO                                                                 STD_ON
#define COM_TXFILTERINITSTATEIDXOFTXSIGINFO                                                         STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.TxFilterInitStateIdx' Reason: 'the optional indirection is deactivated because TxFilterInitStateUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXFILTERINITSTATEUSEDOFTXSIGINFO                                                        STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.TxFilterInitStateUsed' Reason: 'the optional indirection is deactivated because TxFilterInitStateUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXFILTERINITVALUEARRAYBASEDFILTERINITVALUEENDIDXOFTXSIGINFO                             STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.TxFilterInitValueArrayBasedFilterInitValueEndIdx' Reason: 'the optional indirection is deactivated because TxFilterInitValueArrayBasedFilterInitValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXFILTERINITVALUEARRAYBASEDFILTERINITVALUELENGTHOFTXSIGINFO                             STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.TxFilterInitValueArrayBasedFilterInitValueLength' Reason: 'the optional indirection is deactivated because TxFilterInitValueArrayBasedFilterInitValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXFILTERINITVALUEARRAYBASEDFILTERINITVALUESTARTIDXOFTXSIGINFO                           STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.TxFilterInitValueArrayBasedFilterInitValueStartIdx' Reason: 'the optional indirection is deactivated because TxFilterInitValueArrayBasedFilterInitValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXFILTERINITVALUEARRAYBASEDFILTERINITVALUEUSEDOFTXSIGINFO                               STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.TxFilterInitValueArrayBasedFilterInitValueUsed' Reason: 'the optional indirection is deactivated because TxFilterInitValueArrayBasedFilterInitValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXPDUINFOIDXOFTXSIGINFO                                                                 STD_ON
#define COM_TXSIGGRPINFOIDXOFTXSIGINFO                                                              STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.TxSigGrpInfoIdx' Reason: 'the optional indirection is deactivated because TxSigGrpInfoUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXSIGGRPINFOUSEDOFTXSIGINFO                                                             STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.TxSigGrpInfoUsed' Reason: 'the optional indirection is deactivated because TxSigGrpInfoUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_UBMASKIDXOFTXSIGINFO                                                                    STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.UbMaskIdx' Reason: 'the optional indirection is deactivated because UbMaskUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_UBMASKUSEDOFTXSIGINFO                                                                   STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.UbMaskUsed' Reason: 'the optional indirection is deactivated because UbMaskUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_WITHOUTREPOFTXSIGINFO                                                                   STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.WithoutRep' Reason: 'the value of Com_WithoutRepOfTxSigInfo is always 'false' due to this, the array is deactivated.' */
#define COM_TXSIGINFOFILTERINITVALUEIND                                                             STD_OFF  /**< Deactivateable: 'Com_TxSigInfoFilterInitValueInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXSIGINFOINVVALUEIND                                                                    STD_OFF  /**< Deactivateable: 'Com_TxSigInfoInvValueInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXTOUTCNT                                                                               STD_OFF  /**< Deactivateable: 'Com_TxTOutCnt' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXTOUTINFO                                                                              STD_OFF  /**< Deactivateable: 'Com_TxTOutInfo' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_CBKTXTOUTFUNCPTRINDENDIDXOFTXTOUTINFO                                                   STD_OFF  /**< Deactivateable: 'Com_TxTOutInfo.CbkTxTOutFuncPtrIndEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CBKTXTOUTFUNCPTRINDSTARTIDXOFTXTOUTINFO                                                 STD_OFF  /**< Deactivateable: 'Com_TxTOutInfo.CbkTxTOutFuncPtrIndStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CBKTXTOUTFUNCPTRINDUSEDOFTXTOUTINFO                                                     STD_OFF  /**< Deactivateable: 'Com_TxTOutInfo.CbkTxTOutFuncPtrIndUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FACTOROFTXTOUTINFO                                                                      STD_OFF  /**< Deactivateable: 'Com_TxTOutInfo.Factor' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_MODEOFTXTOUTINFO                                                                        STD_OFF  /**< Deactivateable: 'Com_TxTOutInfo.Mode' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXPDUINFOIDXOFTXTOUTINFO                                                                STD_OFF  /**< Deactivateable: 'Com_TxTOutInfo.TxPduInfoIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXTMPTPPDULENGTH                                                                        STD_OFF  /**< Deactivateable: 'Com_TxTmpTpPduLength' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXTPCONNECTIONSTATE                                                                     STD_OFF  /**< Deactivateable: 'Com_TxTpConnectionState' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXTPINFO                                                                                STD_OFF  /**< Deactivateable: 'Com_TxTpInfo' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_BUFFERSIZEOFTXTPINFO                                                                    STD_OFF  /**< Deactivateable: 'Com_TxTpInfo.BufferSize' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_DYNAMICINITIALLENGTHOFTXTPINFO                                                          STD_OFF  /**< Deactivateable: 'Com_TxTpInfo.DynamicInitialLength' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXBUFFERENDIDXOFTXTPINFO                                                                STD_OFF  /**< Deactivateable: 'Com_TxTpInfo.TxBufferEndIdx' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXBUFFERLENGTHOFTXTPINFO                                                                STD_OFF  /**< Deactivateable: 'Com_TxTpInfo.TxBufferLength' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXBUFFERSTARTIDXOFTXTPINFO                                                              STD_OFF  /**< Deactivateable: 'Com_TxTpInfo.TxBufferStartIdx' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXBUFFERUSEDOFTXTPINFO                                                                  STD_OFF  /**< Deactivateable: 'Com_TxTpInfo.TxBufferUsed' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXSIGINFODYNSIGIDXOFTXTPINFO                                                            STD_OFF  /**< Deactivateable: 'Com_TxTpInfo.TxSigInfoDynSigIdx' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXSIGINFODYNSIGUSEDOFTXTPINFO                                                           STD_OFF  /**< Deactivateable: 'Com_TxTpInfo.TxSigInfoDynSigUsed' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXTPSDULENGTH                                                                           STD_OFF  /**< Deactivateable: 'Com_TxTpSduLength' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXTPWRITTENBYTESCOUNTER                                                                 STD_OFF  /**< Deactivateable: 'Com_TxTpWrittenBytesCounter' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_WAITINGFORCONFIRMATION                                                                  STD_OFF  /**< Deactivateable: 'Com_WaitingForConfirmation' Reason: 'This array is deactivated, because no Tx error notification functions are configured.' */
#define COM_PCCONFIG                                                                                STD_ON
#define COM_ALWAYSACTIVETXCOMIPDUSOFPCCONFIG                                                        STD_ON
#define COM_CBKRXTOUTFUNCPTRINDOFPCCONFIG                                                           STD_ON
#define COM_CBKRXTOUTFUNCPTROFPCCONFIG                                                              STD_ON
#define COM_CONFIGIDOFPCCONFIG                                                                      STD_ON
#define COM_CONSTVALUEUINT16OFPCCONFIG                                                              STD_ON
#define COM_CONSTVALUEUINT32OFPCCONFIG                                                              STD_ON
#define COM_CONSTVALUEUINT8OFPCCONFIG                                                               STD_ON
#define COM_CURRENTTXMODEOFPCCONFIG                                                                 STD_ON
#define COM_CYCLETIMECNTOFPCCONFIG                                                                  STD_ON
#define COM_CYCLICSENDREQUESTOFPCCONFIG                                                             STD_ON
#define COM_FINALMAGICNUMBEROFPCCONFIG                                                              STD_OFF  /**< Deactivateable: 'Com_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define COM_GATEWAYDESCRIPTIONPROCESSINGISRLOCKTHRESHOLDOFPCCONFIG                                  STD_OFF  /**< Deactivateable: 'Com_PCConfig.GatewayDescriptionProcessingISRLockThreshold' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_GATEWAYPROCESSINGISRLOCKTHRESHOLDOFPCCONFIG                                             STD_OFF  /**< Deactivateable: 'Com_PCConfig.GatewayProcessingISRLockThreshold' Reason: 'Signal Gateway is not configured.' */
#define COM_HANDLERXPDUDEFERREDOFPCCONFIG                                                           STD_ON
#define COM_IPDUGROUPINFOOFPCCONFIG                                                                 STD_ON
#define COM_IPDUGROUPINFOOFRXPDUINFOINDOFPCCONFIG                                                   STD_ON
#define COM_IPDUGROUPINFOOFTXPDUINFOINDOFPCCONFIG                                                   STD_ON
#define COM_IPDUGROUPINFOTOSUBIPDUGROUPSINDOFPCCONFIG                                               STD_ON
#define COM_IPDUGROUPSTATEOFPCCONFIG                                                                STD_ON
#define COM_INITDATAHASHCODEOFPCCONFIG                                                              STD_OFF  /**< Deactivateable: 'Com_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define COM_INITIALIZEDOFPCCONFIG                                                                   STD_ON
#define COM_PDUGRPCNTOFPCCONFIG                                                                     STD_ON
#define COM_RXACCESSINFOINDOFPCCONFIG                                                               STD_ON
#define COM_RXACCESSINFOOFPCCONFIG                                                                  STD_ON
#define COM_RXCBKFUNCPTROFPCCONFIG                                                                  STD_ON
#define COM_RXDEADLINEMONITORINGISRLOCKCOUNTEROFPCCONFIG                                            STD_ON
#define COM_RXDEADLINEMONITORINGISRLOCKTHRESHOLDOFPCCONFIG                                          STD_ON
#define COM_RXDEFPDUBUFFEROFPCCONFIG                                                                STD_ON
#define COM_RXDEFERREDFCTPTRCACHEOFPCCONFIG                                                         STD_ON
#define COM_RXDEFERREDPROCESSINGISRLOCKCOUNTEROFPCCONFIG                                            STD_ON
#define COM_RXDEFERREDPROCESSINGISRLOCKTHRESHOLDOFPCCONFIG                                          STD_ON
#define COM_RXDLMONDIVISORCOUNTEROFPCCONFIG                                                         STD_ON
#define COM_RXDLMONDIVISOROFPCCONFIG                                                                STD_ON
#define COM_RXIPDUGROUPISRLOCKCOUNTEROFPCCONFIG                                                     STD_ON
#define COM_RXIPDUGROUPISRLOCKTHRESHOLDOFPCCONFIG                                                   STD_ON
#define COM_RXPDUDMSTATEOFPCCONFIG                                                                  STD_ON
#define COM_RXPDUGRPACTIVEOFPCCONFIG                                                                STD_ON
#define COM_RXPDUINFOINDOFPCCONFIG                                                                  STD_ON
#define COM_RXPDUINFOOFPCCONFIG                                                                     STD_ON
#define COM_RXSIGBUFFERUINT16OFPCCONFIG                                                             STD_ON
#define COM_RXSIGBUFFERUINT32OFPCCONFIG                                                             STD_ON
#define COM_RXSIGBUFFERUINT8OFPCCONFIG                                                              STD_ON
#define COM_RXSIGINFOOFPCCONFIG                                                                     STD_ON
#define COM_RXTOUTCNTOFPCCONFIG                                                                     STD_ON
#define COM_RXTOUTINFOINDOFPCCONFIG                                                                 STD_ON
#define COM_RXTOUTINFOOFPCCONFIG                                                                    STD_ON
#define COM_SIZEOFALWAYSACTIVETXCOMIPDUSOFPCCONFIG                                                  STD_ON
#define COM_SIZEOFCBKRXTOUTFUNCPTRINDOFPCCONFIG                                                     STD_ON
#define COM_SIZEOFCBKRXTOUTFUNCPTROFPCCONFIG                                                        STD_ON
#define COM_SIZEOFCONSTVALUEUINT16OFPCCONFIG                                                        STD_ON
#define COM_SIZEOFCONSTVALUEUINT32OFPCCONFIG                                                        STD_ON
#define COM_SIZEOFCONSTVALUEUINT8OFPCCONFIG                                                         STD_ON
#define COM_SIZEOFCURRENTTXMODEOFPCCONFIG                                                           STD_ON
#define COM_SIZEOFCYCLETIMECNTOFPCCONFIG                                                            STD_ON
#define COM_SIZEOFCYCLICSENDREQUESTOFPCCONFIG                                                       STD_ON
#define COM_SIZEOFHANDLERXPDUDEFERREDOFPCCONFIG                                                     STD_ON
#define COM_SIZEOFIPDUGROUPINFOOFPCCONFIG                                                           STD_ON
#define COM_SIZEOFIPDUGROUPINFOOFRXPDUINFOINDOFPCCONFIG                                             STD_ON
#define COM_SIZEOFIPDUGROUPINFOOFTXPDUINFOINDOFPCCONFIG                                             STD_ON
#define COM_SIZEOFIPDUGROUPINFOTOSUBIPDUGROUPSINDOFPCCONFIG                                         STD_ON
#define COM_SIZEOFIPDUGROUPSTATEOFPCCONFIG                                                          STD_ON
#define COM_SIZEOFRXACCESSINFOINDOFPCCONFIG                                                         STD_ON
#define COM_SIZEOFRXACCESSINFOOFPCCONFIG                                                            STD_ON
#define COM_SIZEOFRXCBKFUNCPTROFPCCONFIG                                                            STD_ON
#define COM_SIZEOFRXDEFPDUBUFFEROFPCCONFIG                                                          STD_ON
#define COM_SIZEOFRXDEFERREDFCTPTRCACHEOFPCCONFIG                                                   STD_ON
#define COM_SIZEOFRXPDUDMSTATEOFPCCONFIG                                                            STD_ON
#define COM_SIZEOFRXPDUGRPACTIVEOFPCCONFIG                                                          STD_ON
#define COM_SIZEOFRXPDUINFOINDOFPCCONFIG                                                            STD_ON
#define COM_SIZEOFRXPDUINFOOFPCCONFIG                                                               STD_ON
#define COM_SIZEOFRXSIGBUFFERUINT16OFPCCONFIG                                                       STD_ON
#define COM_SIZEOFRXSIGBUFFERUINT32OFPCCONFIG                                                       STD_ON
#define COM_SIZEOFRXSIGBUFFERUINT8OFPCCONFIG                                                        STD_ON
#define COM_SIZEOFRXSIGINFOOFPCCONFIG                                                               STD_ON
#define COM_SIZEOFRXTOUTCNTOFPCCONFIG                                                               STD_ON
#define COM_SIZEOFRXTOUTINFOINDOFPCCONFIG                                                           STD_ON
#define COM_SIZEOFRXTOUTINFOOFPCCONFIG                                                              STD_ON
#define COM_SIZEOFTRANSMITREQUESTOFPCCONFIG                                                         STD_ON
#define COM_SIZEOFTXBUFFEROFPCCONFIG                                                                STD_ON
#define COM_SIZEOFTXCYCLICPDUOFPCCONFIG                                                             STD_ON
#define COM_SIZEOFTXMODEFALSEOFPCCONFIG                                                             STD_ON
#define COM_SIZEOFTXMODEINFOOFPCCONFIG                                                              STD_ON
#define COM_SIZEOFTXMODETRUEOFPCCONFIG                                                              STD_ON
#define COM_SIZEOFTXPDUGRPACTIVEOFPCCONFIG                                                          STD_ON
#define COM_SIZEOFTXPDUINFOINDOFPCCONFIG                                                            STD_ON
#define COM_SIZEOFTXPDUINFOOFPCCONFIG                                                               STD_ON
#define COM_SIZEOFTXPDUINITVALUEOFPCCONFIG                                                          STD_ON
#define COM_SIZEOFTXSDULENGTHOFPCCONFIG                                                             STD_ON
#define COM_SIZEOFTXSIGINFOOFPCCONFIG                                                               STD_ON
#define COM_TRANSMITREQUESTOFPCCONFIG                                                               STD_ON
#define COM_TXBUFFEROFPCCONFIG                                                                      STD_ON
#define COM_TXCYCLECOUNTERDIVISORCOUNTEROFPCCONFIG                                                  STD_ON
#define COM_TXCYCLECOUNTERDIVISOROFPCCONFIG                                                         STD_ON
#define COM_TXCYCLICPDUOFPCCONFIG                                                                   STD_ON
#define COM_TXCYCLICPROCESSINGISRLOCKCOUNTEROFPCCONFIG                                              STD_ON
#define COM_TXCYCLICPROCESSINGISRLOCKTHRESHOLDOFPCCONFIG                                            STD_ON
#define COM_TXDEADLINEMONITORINGISRLOCKTHRESHOLDOFPCCONFIG                                          STD_OFF  /**< Deactivateable: 'Com_PCConfig.TxDeadlineMonitoringISRLockThreshold' Reason: 'No Tx Signals or SignalGroups with a configured timeout are present. ' */
#define COM_TXDLMONDIVISOROFPCCONFIG                                                                STD_OFF  /**< Deactivateable: 'Com_PCConfig.TxDlMonDivisor' Reason: 'Timing domain and corresponding timing divisor are deactivated, because no value is configured for TxDlMonTimeBase.' */
#define COM_TXIPDUGROUPISRLOCKCOUNTEROFPCCONFIG                                                     STD_ON
#define COM_TXIPDUGROUPISRLOCKTHRESHOLDOFPCCONFIG                                                   STD_ON
#define COM_TXMODEFALSEOFPCCONFIG                                                                   STD_ON
#define COM_TXMODEINFOOFPCCONFIG                                                                    STD_ON
#define COM_TXMODETRUEOFPCCONFIG                                                                    STD_ON
#define COM_TXPDUGRPACTIVEOFPCCONFIG                                                                STD_ON
#define COM_TXPDUINFOINDOFPCCONFIG                                                                  STD_ON
#define COM_TXPDUINFOOFPCCONFIG                                                                     STD_ON
#define COM_TXPDUINITVALUEOFPCCONFIG                                                                STD_ON
#define COM_TXPROCESSINGISRLOCKCOUNTEROFPCCONFIG                                                    STD_ON
#define COM_TXPROCESSINGISRLOCKTHRESHOLDOFPCCONFIG                                                  STD_ON
#define COM_TXSDULENGTHOFPCCONFIG                                                                   STD_ON
#define COM_TXSIGINFOOFPCCONFIG                                                                     STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  ComPCMinNumericValueDefines  Com Min Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the minimum value in numerical based data.
  \{
*/ 
#define COM_MIN_CYCLETIMECNT                                                                        0u
#define COM_MIN_HANDLERXPDUDEFERRED                                                                 0u
#define COM_MIN_RXDEADLINEMONITORINGISRLOCKCOUNTER                                                  0u
#define COM_MIN_RXDEFPDUBUFFER                                                                      0u
#define COM_MIN_RXDEFERREDFCTPTRCACHE                                                               0u
#define COM_MIN_RXDEFERREDPROCESSINGISRLOCKCOUNTER                                                  0u
#define COM_MIN_RXDLMONDIVISORCOUNTER                                                               0u
#define COM_MIN_RXIPDUGROUPISRLOCKCOUNTER                                                           0u
#define COM_MIN_RXSIGBUFFERUINT16                                                                   0u
#define COM_MIN_RXSIGBUFFERUINT32                                                                   0u
#define COM_MIN_RXSIGBUFFERUINT8                                                                    0u
#define COM_MIN_RXTOUTCNT                                                                           0u
#define COM_MIN_TXBUFFER                                                                            0u
#define COM_MIN_TXCYCLECOUNTERDIVISORCOUNTER                                                        0u
#define COM_MIN_TXCYCLICPROCESSINGISRLOCKCOUNTER                                                    0u
#define COM_MIN_TXIPDUGROUPISRLOCKCOUNTER                                                           0u
#define COM_MIN_TXPROCESSINGISRLOCKCOUNTER                                                          0u
#define COM_MIN_TXSDULENGTH                                                                         0u
/** 
  \}
*/ 

/** 
  \defgroup  ComPCMaxNumericValueDefines  Com Max Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the maximum value in numerical based data.
  \{
*/ 
#define COM_MAX_CYCLETIMECNT                                                                        255u
#define COM_MAX_HANDLERXPDUDEFERRED                                                                 4294967295u
#define COM_MAX_RXDEADLINEMONITORINGISRLOCKCOUNTER                                                  65535u
#define COM_MAX_RXDEFPDUBUFFER                                                                      255u
#define COM_MAX_RXDEFERREDFCTPTRCACHE                                                               4294967295u
#define COM_MAX_RXDEFERREDPROCESSINGISRLOCKCOUNTER                                                  65535u
#define COM_MAX_RXDLMONDIVISORCOUNTER                                                               65535u
#define COM_MAX_RXIPDUGROUPISRLOCKCOUNTER                                                           65535u
#define COM_MAX_RXSIGBUFFERUINT16                                                                   65535u
#define COM_MAX_RXSIGBUFFERUINT32                                                                   4294967295u
#define COM_MAX_RXSIGBUFFERUINT8                                                                    255u
#define COM_MAX_RXTOUTCNT                                                                           255u
#define COM_MAX_TXBUFFER                                                                            255u
#define COM_MAX_TXCYCLECOUNTERDIVISORCOUNTER                                                        65535u
#define COM_MAX_TXCYCLICPROCESSINGISRLOCKCOUNTER                                                    65535u
#define COM_MAX_TXIPDUGROUPISRLOCKCOUNTER                                                           65535u
#define COM_MAX_TXPROCESSINGISRLOCKCOUNTER                                                          65535u
#define COM_MAX_TXSDULENGTH                                                                         4294967295u
/** 
  \}
*/ 

/** 
  \defgroup  ComPCNoReferenceDefines  Com No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define COM_NO_IPDUGROUPINFOTOSUBIPDUGROUPSINDENDIDXOFIPDUGROUPINFO                                 255u
#define COM_NO_IPDUGROUPINFOTOSUBIPDUGROUPSINDSTARTIDXOFIPDUGROUPINFO                               255u
#define COM_NO_RXPDUINFOINDENDIDXOFIPDUGROUPINFO                                                    255u
#define COM_NO_RXPDUINFOINDSTARTIDXOFIPDUGROUPINFO                                                  255u
#define COM_NO_TXPDUINFOINDENDIDXOFIPDUGROUPINFO                                                    255u
#define COM_NO_TXPDUINFOINDSTARTIDXOFIPDUGROUPINFO                                                  255u
#define COM_NO_BUFFERIDXOFRXACCESSINFO                                                              255u
#define COM_NO_INITVALUEIDXOFRXACCESSINFO                                                           255u
#define COM_NO_RXTOUTINFOIDXOFRXACCESSINFO                                                          255u
#define COM_NO_HANDLERXPDUDEFERREDIDXOFRXPDUINFO                                                    255u
#define COM_NO_IPDUGROUPINFOOFRXPDUINFOINDENDIDXOFRXPDUINFO                                         255u
#define COM_NO_IPDUGROUPINFOOFRXPDUINFOINDSTARTIDXOFRXPDUINFO                                       255u
#define COM_NO_RXACCESSINFOINDENDIDXOFRXPDUINFO                                                     255u
#define COM_NO_RXACCESSINFOINDSTARTIDXOFRXPDUINFO                                                   255u
#define COM_NO_RXDEFPDUBUFFERENDIDXOFRXPDUINFO                                                      255u
#define COM_NO_RXDEFPDUBUFFERSTARTIDXOFRXPDUINFO                                                    255u
#define COM_NO_RXSIGINFOENDIDXOFRXPDUINFO                                                           255u
#define COM_NO_RXSIGINFOSTARTIDXOFRXPDUINFO                                                         255u
#define COM_NO_RXTOUTINFOIDXOFRXPDUINFO                                                             255u
#define COM_NO_RXTOUTINFOINDENDIDXOFRXPDUINFO                                                       255u
#define COM_NO_RXTOUTINFOINDSTARTIDXOFRXPDUINFO                                                     255u
#define COM_NO_RXCBKFUNCPTRACKIDXOFRXSIGINFO                                                        255u
#define COM_NO_RXTOUTINFOIDXOFRXSIGINFO                                                             255u
#define COM_NO_CBKRXTOUTFUNCPTRINDENDIDXOFRXTOUTINFO                                                255u
#define COM_NO_CBKRXTOUTFUNCPTRINDSTARTIDXOFRXTOUTINFO                                              255u
#define COM_NO_IPDUGROUPINFOOFTXPDUINFOINDENDIDXOFTXPDUINFO                                         255u
#define COM_NO_IPDUGROUPINFOOFTXPDUINFOINDSTARTIDXOFTXPDUINFO                                       255u
#define COM_NO_TXBUFFERENDIDXOFTXPDUINFO                                                            255u
#define COM_NO_TXBUFFERSTARTIDXOFTXPDUINFO                                                          255u
#define COM_NO_TXPDUINITVALUEENDIDXOFTXPDUINFO                                                      255u
#define COM_NO_TXPDUINITVALUESTARTIDXOFTXPDUINFO                                                    255u
#define COM_NO_TXBUFFERENDIDXOFTXSIGINFO                                                            255u
#define COM_NO_TXBUFFERSTARTIDXOFTXSIGINFO                                                          255u
/** 
  \}
*/ 

/** 
  \defgroup  ComPCEnumExistsDefines  Com Enum Exists Defines (PRE_COMPILE)
  \brief  These defines can be used to deactivate enumeration based code sequences if the enumeration value does not exist in the configuration data.
  \{
*/ 
#define COM_EXISTS_ALWAYS_FILTERALGOOFFILTERINFO_FLOAT32                                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEVER_FILTERALGOOFFILTERINFO_FLOAT32                                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_MASKED_OLD_FILTERALGOOFFILTERINFO_FLOAT32                     STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_X_FILTERALGOOFFILTERINFO_FLOAT32                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_EQUALS_X_FILTERALGOOFFILTERINFO_FLOAT32                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_OUTSIDE_FILTERALGOOFFILTERINFO_FLOAT32                                    STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_WITHIN_FILTERALGOOFFILTERINFO_FLOAT32                                     STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NONE_FILTERALGOOFFILTERINFO_FLOAT32                                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_ALWAYS_FILTERALGOOFFILTERINFO_FLOAT64                                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEVER_FILTERALGOOFFILTERINFO_FLOAT64                                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_MASKED_OLD_FILTERALGOOFFILTERINFO_FLOAT64                     STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_X_FILTERALGOOFFILTERINFO_FLOAT64                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_EQUALS_X_FILTERALGOOFFILTERINFO_FLOAT64                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_OUTSIDE_FILTERALGOOFFILTERINFO_FLOAT64                                    STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_WITHIN_FILTERALGOOFFILTERINFO_FLOAT64                                     STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NONE_FILTERALGOOFFILTERINFO_FLOAT64                                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_ALWAYS_FILTERALGOOFFILTERINFO_SINT16                                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEVER_FILTERALGOOFFILTERINFO_SINT16                                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_MASKED_OLD_FILTERALGOOFFILTERINFO_SINT16                      STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_X_FILTERALGOOFFILTERINFO_SINT16                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_EQUALS_X_FILTERALGOOFFILTERINFO_SINT16                                STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_OUTSIDE_FILTERALGOOFFILTERINFO_SINT16                                     STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_WITHIN_FILTERALGOOFFILTERINFO_SINT16                                      STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NONE_FILTERALGOOFFILTERINFO_SINT16                                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_ALWAYS_FILTERALGOOFFILTERINFO_SINT32                                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEVER_FILTERALGOOFFILTERINFO_SINT32                                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_MASKED_OLD_FILTERALGOOFFILTERINFO_SINT32                      STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_X_FILTERALGOOFFILTERINFO_SINT32                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_EQUALS_X_FILTERALGOOFFILTERINFO_SINT32                                STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_OUTSIDE_FILTERALGOOFFILTERINFO_SINT32                                     STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_WITHIN_FILTERALGOOFFILTERINFO_SINT32                                      STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NONE_FILTERALGOOFFILTERINFO_SINT32                                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_ALWAYS_FILTERALGOOFFILTERINFO_SINT64                                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEVER_FILTERALGOOFFILTERINFO_SINT64                                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_MASKED_OLD_FILTERALGOOFFILTERINFO_SINT64                      STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_X_FILTERALGOOFFILTERINFO_SINT64                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_EQUALS_X_FILTERALGOOFFILTERINFO_SINT64                                STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_OUTSIDE_FILTERALGOOFFILTERINFO_SINT64                                     STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_WITHIN_FILTERALGOOFFILTERINFO_SINT64                                      STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NONE_FILTERALGOOFFILTERINFO_SINT64                                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_ALWAYS_FILTERALGOOFFILTERINFO_SINT8                                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEVER_FILTERALGOOFFILTERINFO_SINT8                                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_MASKED_OLD_FILTERALGOOFFILTERINFO_SINT8                       STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_X_FILTERALGOOFFILTERINFO_SINT8                                STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_EQUALS_X_FILTERALGOOFFILTERINFO_SINT8                                 STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_OUTSIDE_FILTERALGOOFFILTERINFO_SINT8                                      STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_WITHIN_FILTERALGOOFFILTERINFO_SINT8                                       STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NONE_FILTERALGOOFFILTERINFO_SINT8                                                STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_ALWAYS_FILTERALGOOFFILTERINFO_UINT16                                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEVER_FILTERALGOOFFILTERINFO_UINT16                                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_MASKED_OLD_FILTERALGOOFFILTERINFO_UINT16                      STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_X_FILTERALGOOFFILTERINFO_UINT16                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_EQUALS_X_FILTERALGOOFFILTERINFO_UINT16                                STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_OUTSIDE_FILTERALGOOFFILTERINFO_UINT16                                     STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_WITHIN_FILTERALGOOFFILTERINFO_UINT16                                      STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NONE_FILTERALGOOFFILTERINFO_UINT16                                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_ALWAYS_FILTERALGOOFFILTERINFO_UINT32                                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEVER_FILTERALGOOFFILTERINFO_UINT32                                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_MASKED_OLD_FILTERALGOOFFILTERINFO_UINT32                      STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_X_FILTERALGOOFFILTERINFO_UINT32                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_EQUALS_X_FILTERALGOOFFILTERINFO_UINT32                                STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_OUTSIDE_FILTERALGOOFFILTERINFO_UINT32                                     STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_WITHIN_FILTERALGOOFFILTERINFO_UINT32                                      STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NONE_FILTERALGOOFFILTERINFO_UINT32                                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_ALWAYS_FILTERALGOOFFILTERINFO_UINT64                                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEVER_FILTERALGOOFFILTERINFO_UINT64                                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_MASKED_OLD_FILTERALGOOFFILTERINFO_UINT64                      STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_X_FILTERALGOOFFILTERINFO_UINT64                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_EQUALS_X_FILTERALGOOFFILTERINFO_UINT64                                STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_OUTSIDE_FILTERALGOOFFILTERINFO_UINT64                                     STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_WITHIN_FILTERALGOOFFILTERINFO_UINT64                                      STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NONE_FILTERALGOOFFILTERINFO_UINT64                                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_ALWAYS_FILTERALGOOFFILTERINFO_UINT8                                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEVER_FILTERALGOOFFILTERINFO_UINT8                                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_MASKED_OLD_FILTERALGOOFFILTERINFO_UINT8                       STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_X_FILTERALGOOFFILTERINFO_UINT8                                STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_EQUALS_X_FILTERALGOOFFILTERINFO_UINT8                                 STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_OUTSIDE_FILTERALGOOFFILTERINFO_UINT8                                      STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_WITHIN_FILTERALGOOFFILTERINFO_UINT8                                       STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NONE_FILTERALGOOFFILTERINFO_UINT8                                                STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_ALWAYS_FILTERALGOOFFILTERINFO_UINT8_N                                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEVER_FILTERALGOOFFILTERINFO_UINT8_N                                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_MASKED_OLD_FILTERALGOOFFILTERINFO_UINT8_N                     STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_X_FILTERALGOOFFILTERINFO_UINT8_N                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_EQUALS_X_FILTERALGOOFFILTERINFO_UINT8_N                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_OUTSIDE_FILTERALGOOFFILTERINFO_UINT8_N                                    STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_WITHIN_FILTERALGOOFFILTERINFO_UINT8_N                                     STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NONE_FILTERALGOOFFILTERINFO_UINT8_N                                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_DIRECT_COPYTYPEOFGWDESCRIPTIONACCESSINFO                                         STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.CopyType' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_RIGHTSHIFT_COPYTYPEOFGWDESCRIPTIONACCESSINFO                                     STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.CopyType' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_LEFTSHIFT_COPYTYPEOFGWDESCRIPTIONACCESSINFO                                      STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.CopyType' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_BIG_ENDIAN_ENDIANNESSOFGWDESCRIPTIONACCESSINFO                                   STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Endianness' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_LITTLE_ENDIAN_ENDIANNESSOFGWDESCRIPTIONACCESSINFO                                STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Endianness' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_IMMEDIATE_PENDING_TYPEOFGWDESCRIPTIONACCESSINFO                                  STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Type' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_IMMEDIATE_TRIGGERED_TYPEOFGWDESCRIPTIONACCESSINFO                                STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Type' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_IMMEDIATE_TRIGGERED_ONCHANGE_TYPEOFGWDESCRIPTIONACCESSINFO                       STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Type' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_IMMEDIATE_TRIGGERED_ONCHANGE_WITHOUTREP_TYPEOFGWDESCRIPTIONACCESSINFO            STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Type' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_IMMEDIATE_TRIGGERED_WITHOUTREP_TYPEOFGWDESCRIPTIONACCESSINFO                     STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Type' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_DEFERRED_PENDING_TYPEOFGWDESCRIPTIONACCESSINFO                                   STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Type' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_DEFERRED_TRIGGERED_TYPEOFGWDESCRIPTIONACCESSINFO                                 STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Type' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_DEFERRED_TRIGGERED_ONCHANGE_TYPEOFGWDESCRIPTIONACCESSINFO                        STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Type' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_DEFERRED_TRIGGERED_ONCHANGE_WITHOUTREP_TYPEOFGWDESCRIPTIONACCESSINFO             STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Type' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_DEFERRED_TRIGGERED_WITHOUTREP_TYPEOFGWDESCRIPTIONACCESSINFO                      STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Type' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_UINT8_APPLTYPEOFRXACCESSINFO                                                     STD_ON
#define COM_EXISTS_SINT8_APPLTYPEOFRXACCESSINFO                                                     STD_OFF
#define COM_EXISTS_UINT16_APPLTYPEOFRXACCESSINFO                                                    STD_ON
#define COM_EXISTS_SINT16_APPLTYPEOFRXACCESSINFO                                                    STD_OFF
#define COM_EXISTS_UINT32_APPLTYPEOFRXACCESSINFO                                                    STD_ON
#define COM_EXISTS_SINT32_APPLTYPEOFRXACCESSINFO                                                    STD_OFF
#define COM_EXISTS_UINT64_APPLTYPEOFRXACCESSINFO                                                    STD_OFF
#define COM_EXISTS_SINT64_APPLTYPEOFRXACCESSINFO                                                    STD_OFF
#define COM_EXISTS_UINT8_N_APPLTYPEOFRXACCESSINFO                                                   STD_OFF
#define COM_EXISTS_UINT8_DYN_APPLTYPEOFRXACCESSINFO                                                 STD_OFF
#define COM_EXISTS_ZEROBIT_APPLTYPEOFRXACCESSINFO                                                   STD_OFF
#define COM_EXISTS_FLOAT32_APPLTYPEOFRXACCESSINFO                                                   STD_OFF
#define COM_EXISTS_FLOAT64_APPLTYPEOFRXACCESSINFO                                                   STD_OFF
#define COM_EXISTS_NBIT_BUSACCOFRXACCESSINFO                                                        STD_ON
#define COM_EXISTS_BYTE_BUSACCOFRXACCESSINFO                                                        STD_ON
#define COM_EXISTS_NBYTE_BUSACCOFRXACCESSINFO                                                       STD_OFF
#define COM_EXISTS_NBYTE_SW_BUSACCOFRXACCESSINFO                                                    STD_ON
#define COM_EXISTS_NBITNBYTE_BUSACCOFRXACCESSINFO                                                   STD_OFF
#define COM_EXISTS_NBITNBYTE_SW_BUSACCOFRXACCESSINFO                                                STD_ON
#define COM_EXISTS_ARRAY_BASED_BUSACCOFRXACCESSINFO                                                 STD_OFF
#define COM_EXISTS_DEFERRED_SIGNALPROCESSINGOFRXPDUINFO                                             STD_ON
#define COM_EXISTS_IMMEDIATE_SIGNALPROCESSINGOFRXPDUINFO                                            STD_OFF
#define COM_EXISTS_NORMAL_TYPEOFRXPDUINFO                                                           STD_ON
#define COM_EXISTS_TP_TYPEOFRXPDUINFO                                                               STD_OFF
#define COM_EXISTS_DEFERRED_SIGNALPROCESSINGOFRXSIGGRPINFO                                          STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.SignalProcessing' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_IMMEDIATE_SIGNALPROCESSINGOFRXSIGGRPINFO                                         STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.SignalProcessing' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO                                             STD_ON
#define COM_EXISTS_IMMEDIATE_SIGNALPROCESSINGOFRXSIGINFO                                            STD_OFF
#define COM_EXISTS_ALWAYS_FILTERALGOOFSIGGRPARRAYFILTERINFO                                         STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.FilterAlgo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_EXISTS_NEVER_FILTERALGOOFSIGGRPARRAYFILTERINFO                                          STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.FilterAlgo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_MASKED_OLD_FILTERALGOOFSIGGRPARRAYFILTERINFO                  STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.FilterAlgo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_X_FILTERALGOOFSIGGRPARRAYFILTERINFO                           STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.FilterAlgo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_EXISTS_MASKED_NEW_EQUALS_X_FILTERALGOOFSIGGRPARRAYFILTERINFO                            STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.FilterAlgo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_EXISTS_NEW_IS_OUTSIDE_FILTERALGOOFSIGGRPARRAYFILTERINFO                                 STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.FilterAlgo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_EXISTS_NEW_IS_WITHIN_FILTERALGOOFSIGGRPARRAYFILTERINFO                                  STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.FilterAlgo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_EXISTS_NONE_FILTERALGOOFSIGGRPARRAYFILTERINFO                                           STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.FilterAlgo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_EXISTS_TRANSMIT_CLRUBOFTXPDUINFO                                                        STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.ClrUb' Reason: 'This array is deactivated, because no Tx I-PDUs with update-bits are configured.' */
#define COM_EXISTS_TRIGGER_TRANSMIT_CLRUBOFTXPDUINFO                                                STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.ClrUb' Reason: 'This array is deactivated, because no Tx I-PDUs with update-bits are configured.' */
#define COM_EXISTS_NOT_USED_CLRUBOFTXPDUINFO                                                        STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.ClrUb' Reason: 'This array is deactivated, because no Tx I-PDUs with update-bits are configured.' */
#define COM_EXISTS_CONFIRMATION_CLRUBOFTXPDUINFO                                                    STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.ClrUb' Reason: 'This array is deactivated, because no Tx I-PDUs with update-bits are configured.' */
#define COM_EXISTS_PENDING_TRANSFERPROPERTYOFTXSIGGRPINFO                                           STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TransferProperty' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_TRIGGERED_TRANSFERPROPERTYOFTXSIGGRPINFO                                         STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TransferProperty' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_TRIGGERED_WITHOUT_REPETITION_TRANSFERPROPERTYOFTXSIGGRPINFO                      STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TransferProperty' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_TRIGGERED_ON_CHANGE_TRANSFERPROPERTYOFTXSIGGRPINFO                               STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TransferProperty' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_TRIGGERED_ON_CHANGE_WITHOUT_REPETITION_TRANSFERPROPERTYOFTXSIGGRPINFO            STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TransferProperty' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_UINT8_APPLTYPEOFTXSIGINFO                                                        STD_ON
#define COM_EXISTS_SINT8_APPLTYPEOFTXSIGINFO                                                        STD_OFF
#define COM_EXISTS_UINT16_APPLTYPEOFTXSIGINFO                                                       STD_OFF
#define COM_EXISTS_SINT16_APPLTYPEOFTXSIGINFO                                                       STD_OFF
#define COM_EXISTS_UINT32_APPLTYPEOFTXSIGINFO                                                       STD_OFF
#define COM_EXISTS_SINT32_APPLTYPEOFTXSIGINFO                                                       STD_OFF
#define COM_EXISTS_UINT64_APPLTYPEOFTXSIGINFO                                                       STD_OFF
#define COM_EXISTS_SINT64_APPLTYPEOFTXSIGINFO                                                       STD_OFF
#define COM_EXISTS_UINT8_N_APPLTYPEOFTXSIGINFO                                                      STD_OFF
#define COM_EXISTS_UINT8_DYN_APPLTYPEOFTXSIGINFO                                                    STD_OFF
#define COM_EXISTS_ZEROBIT_APPLTYPEOFTXSIGINFO                                                      STD_OFF
#define COM_EXISTS_FLOAT32_APPLTYPEOFTXSIGINFO                                                      STD_OFF
#define COM_EXISTS_FLOAT64_APPLTYPEOFTXSIGINFO                                                      STD_OFF
#define COM_EXISTS_NBIT_BUSACCOFTXSIGINFO                                                           STD_ON
#define COM_EXISTS_BYTE_BUSACCOFTXSIGINFO                                                           STD_OFF
#define COM_EXISTS_NBYTE_BUSACCOFTXSIGINFO                                                          STD_OFF
#define COM_EXISTS_NBYTE_SW_BUSACCOFTXSIGINFO                                                       STD_OFF
#define COM_EXISTS_NBITNBYTE_BUSACCOFTXSIGINFO                                                      STD_OFF
#define COM_EXISTS_NBITNBYTE_SW_BUSACCOFTXSIGINFO                                                   STD_OFF
#define COM_EXISTS_ARRAY_BASED_BUSACCOFTXSIGINFO                                                    STD_OFF
#define COM_EXISTS_NORMAL_MODEOFTXTOUTINFO                                                          STD_OFF  /**< Deactivateable: 'Com_TxTOutInfo.Mode' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NONE_MODEOFTXTOUTINFO                                                            STD_OFF  /**< Deactivateable: 'Com_TxTOutInfo.Mode' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
/** 
  \}
*/ 

/** 
  \defgroup  ComPCEnumDefines  Com Enum Defines (PRE_COMPILE)
  \brief  These defines are the enumeration values of enumeration based CONST and VAR data.
  \{
*/ 
#define COM_INACTIVE_IPDUGROUPSTATE                                                                 0x00u
#define COM_ACTIVE_DMINACTIVE_IPDUGROUPSTATE                                                        0x01u
#define COM_ACTIVE_DMACTIVE_IPDUGROUPSTATE                                                          0x02u
#define COM_UINT8_APPLTYPEOFRXACCESSINFO                                                            0x00u
#define COM_UINT16_APPLTYPEOFRXACCESSINFO                                                           0x02u
#define COM_UINT32_APPLTYPEOFRXACCESSINFO                                                           0x04u
#define COM_NBIT_BUSACCOFRXACCESSINFO                                                               0x00u
#define COM_BYTE_BUSACCOFRXACCESSINFO                                                               0x01u
#define COM_NBYTE_SW_BUSACCOFRXACCESSINFO                                                           0x03u
#define COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO                                                       0x05u
#define COM_INACTIVE_RXPDUDMSTATE                                                                   0x00u
#define COM_ACTIVE_RXPDUDMSTATE                                                                     0x01u
#define COM_PURE_DM_STATE_MASK_RXPDUDMSTATE                                                         0x01u
#define COM_OCCURRED_RXPDUDMSTATE                                                                   0x03u
#define COM_OCCURRED_FLAG_RXPDUDMSTATE                                                              0x02u
#define COM_CLEAR_OCCURRED_FLAG_RXPDUDMSTATE                                                        0xFDu
#define COM_DEFERRED_SIGNALPROCESSINGOFRXPDUINFO                                                    0x00u
#define COM_NORMAL_TYPEOFRXPDUINFO                                                                  0x00u
#define COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO                                                    0x00u
#define COM_UINT8_APPLTYPEOFTXSIGINFO                                                               0x00u
#define COM_NBIT_BUSACCOFTXSIGINFO                                                                  0x00u
/** 
  \}
*/ 

/** 
  \defgroup  ComPCIsReducedToDefineDefines  Com Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define COM_ISDEF_TXPDUINFOIDXOFALWAYSACTIVETXCOMIPDUS                                              STD_OFF
#define COM_ISDEF_CBKRXTOUTFUNCPTR                                                                  STD_OFF
#define COM_ISDEF_CBKRXTOUTFUNCPTRIND                                                               STD_OFF
#define COM_ISDEF_CONSTVALUEUINT16                                                                  STD_OFF
#define COM_ISDEF_CONSTVALUEUINT32                                                                  STD_OFF
#define COM_ISDEF_CONSTVALUEUINT8                                                                   STD_OFF
#define COM_ISDEF_IPDUGROUPINFOTOSUBIPDUGROUPSINDENDIDXOFIPDUGROUPINFO                              STD_OFF
#define COM_ISDEF_IPDUGROUPINFOTOSUBIPDUGROUPSINDSTARTIDXOFIPDUGROUPINFO                            STD_OFF
#define COM_ISDEF_IPDUGROUPINFOTOSUBIPDUGROUPSINDUSEDOFIPDUGROUPINFO                                STD_OFF
#define COM_ISDEF_RXPDUINFOINDENDIDXOFIPDUGROUPINFO                                                 STD_OFF
#define COM_ISDEF_RXPDUINFOINDSTARTIDXOFIPDUGROUPINFO                                               STD_OFF
#define COM_ISDEF_RXPDUINFOINDUSEDOFIPDUGROUPINFO                                                   STD_OFF
#define COM_ISDEF_TXPDUINFOINDENDIDXOFIPDUGROUPINFO                                                 STD_OFF
#define COM_ISDEF_TXPDUINFOINDSTARTIDXOFIPDUGROUPINFO                                               STD_OFF
#define COM_ISDEF_TXPDUINFOINDUSEDOFIPDUGROUPINFO                                                   STD_OFF
#define COM_ISDEF_IPDUGROUPINFOOFRXPDUINFOIND                                                       STD_OFF
#define COM_ISDEF_IPDUGROUPINFOOFTXPDUINFOIND                                                       STD_OFF
#define COM_ISDEF_IPDUGROUPINFOTOSUBIPDUGROUPSIND                                                   STD_OFF
#define COM_ISDEF_APPLTYPEOFRXACCESSINFO                                                            STD_OFF
#define COM_ISDEF_BITLENGTHOFRXACCESSINFO                                                           STD_OFF
#define COM_ISDEF_BITPOSITIONOFRXACCESSINFO                                                         STD_OFF
#define COM_ISDEF_BUFFERIDXOFRXACCESSINFO                                                           STD_OFF
#define COM_ISDEF_BUFFERUSEDOFRXACCESSINFO                                                          STD_OFF
#define COM_ISDEF_BUSACCOFRXACCESSINFO                                                              STD_OFF
#define COM_ISDEF_BYTELENGTHOFRXACCESSINFO                                                          STD_OFF
#define COM_ISDEF_BYTEPOSITIONOFRXACCESSINFO                                                        STD_OFF
#define COM_ISDEF_INITVALUEIDXOFRXACCESSINFO                                                        STD_OFF
#define COM_ISDEF_INITVALUEUSEDOFRXACCESSINFO                                                       STD_OFF
#define COM_ISDEF_RXPDUINFOIDXOFRXACCESSINFO                                                        STD_OFF
#define COM_ISDEF_RXTOUTINFOIDXOFRXACCESSINFO                                                       STD_OFF
#define COM_ISDEF_RXTOUTINFOUSEDOFRXACCESSINFO                                                      STD_OFF
#define COM_ISDEF_STARTBYTEINPDUPOSITIONOFRXACCESSINFO                                              STD_OFF
#define COM_ISDEF_RXACCESSINFOIND                                                                   STD_OFF
#define COM_ISDEF_RXCBKFUNCPTR                                                                      STD_OFF
#define COM_ISDEF_HANDLERXPDUDEFERREDIDXOFRXPDUINFO                                                 STD_OFF
#define COM_ISDEF_HANDLERXPDUDEFERREDUSEDOFRXPDUINFO                                                STD_OFF
#define COM_ISDEF_IPDUGROUPINFOOFRXPDUINFOINDENDIDXOFRXPDUINFO                                      STD_OFF
#define COM_ISDEF_IPDUGROUPINFOOFRXPDUINFOINDSTARTIDXOFRXPDUINFO                                    STD_OFF
#define COM_ISDEF_IPDUGROUPINFOOFRXPDUINFOINDUSEDOFRXPDUINFO                                        STD_OFF
#define COM_ISDEF_RXACCESSINFOINDENDIDXOFRXPDUINFO                                                  STD_OFF
#define COM_ISDEF_RXACCESSINFOINDSTARTIDXOFRXPDUINFO                                                STD_OFF
#define COM_ISDEF_RXACCESSINFOINDUSEDOFRXPDUINFO                                                    STD_OFF
#define COM_ISDEF_RXDEFPDUBUFFERENDIDXOFRXPDUINFO                                                   STD_OFF
#define COM_ISDEF_RXDEFPDUBUFFERLENGTHOFRXPDUINFO                                                   STD_OFF
#define COM_ISDEF_RXDEFPDUBUFFERSTARTIDXOFRXPDUINFO                                                 STD_OFF
#define COM_ISDEF_RXDEFPDUBUFFERUSEDOFRXPDUINFO                                                     STD_OFF
#define COM_ISDEF_RXSIGINFOENDIDXOFRXPDUINFO                                                        STD_OFF
#define COM_ISDEF_RXSIGINFOSTARTIDXOFRXPDUINFO                                                      STD_OFF
#define COM_ISDEF_RXSIGINFOUSEDOFRXPDUINFO                                                          STD_OFF
#define COM_ISDEF_RXTOUTINFOIDXOFRXPDUINFO                                                          STD_OFF
#define COM_ISDEF_RXTOUTINFOINDENDIDXOFRXPDUINFO                                                    STD_OFF
#define COM_ISDEF_RXTOUTINFOINDSTARTIDXOFRXPDUINFO                                                  STD_OFF
#define COM_ISDEF_RXTOUTINFOINDUSEDOFRXPDUINFO                                                      STD_OFF
#define COM_ISDEF_RXTOUTINFOUSEDOFRXPDUINFO                                                         STD_OFF
#define COM_ISDEF_SIGNALPROCESSINGOFRXPDUINFO                                                       STD_OFF
#define COM_ISDEF_TYPEOFRXPDUINFO                                                                   STD_OFF
#define COM_ISDEF_RXPDUINFOIND                                                                      STD_OFF
#define COM_ISDEF_RXACCESSINFOIDXOFRXSIGINFO                                                        STD_OFF
#define COM_ISDEF_RXCBKFUNCPTRACKIDXOFRXSIGINFO                                                     STD_OFF
#define COM_ISDEF_RXCBKFUNCPTRACKUSEDOFRXSIGINFO                                                    STD_OFF
#define COM_ISDEF_RXTOUTINFOIDXOFRXSIGINFO                                                          STD_OFF
#define COM_ISDEF_RXTOUTINFOUSEDOFRXSIGINFO                                                         STD_OFF
#define COM_ISDEF_SIGNALPROCESSINGOFRXSIGINFO                                                       STD_OFF
#define COM_ISDEF_VALIDDLCOFRXSIGINFO                                                               STD_OFF
#define COM_ISDEF_CBKRXTOUTFUNCPTRINDENDIDXOFRXTOUTINFO                                             STD_OFF
#define COM_ISDEF_CBKRXTOUTFUNCPTRINDSTARTIDXOFRXTOUTINFO                                           STD_OFF
#define COM_ISDEF_CBKRXTOUTFUNCPTRINDUSEDOFRXTOUTINFO                                               STD_OFF
#define COM_ISDEF_FACTOROFRXTOUTINFO                                                                STD_OFF
#define COM_ISDEF_FIRSTFACTOROFRXTOUTINFO                                                           STD_OFF
#define COM_ISDEF_RXPDUINFOIDXOFRXTOUTINFO                                                          STD_OFF
#define COM_ISDEF_RXTOUTINFOIND                                                                     STD_OFF
#define COM_ISDEF_TXPDUINFOIDXOFTXCYCLICPDU                                                         STD_OFF
#define COM_ISDEF_PERIODICOFTXMODEFALSE                                                             STD_OFF
#define COM_ISDEF_TIMEPERIODOFTXMODEFALSE                                                           STD_OFF
#define COM_ISDEF_INITMODEOFTXMODEINFO                                                              STD_OFF
#define COM_ISDEF_TXMODEFALSEIDXOFTXMODEINFO                                                        STD_OFF
#define COM_ISDEF_TXMODETRUEIDXOFTXMODEINFO                                                         STD_OFF
#define COM_ISDEF_PERIODICOFTXMODETRUE                                                              STD_OFF
#define COM_ISDEF_TIMEPERIODOFTXMODETRUE                                                            STD_OFF
#define COM_ISDEF_EXTERNALIDOFTXPDUINFO                                                             STD_OFF
#define COM_ISDEF_IPDUGROUPINFOOFTXPDUINFOINDENDIDXOFTXPDUINFO                                      STD_OFF
#define COM_ISDEF_IPDUGROUPINFOOFTXPDUINFOINDSTARTIDXOFTXPDUINFO                                    STD_OFF
#define COM_ISDEF_IPDUGROUPINFOOFTXPDUINFOINDUSEDOFTXPDUINFO                                        STD_OFF
#define COM_ISDEF_METADATALENGTHOFTXPDUINFO                                                         STD_OFF
#define COM_ISDEF_PDUWITHMETADATALENGTHOFTXPDUINFO                                                  STD_OFF
#define COM_ISDEF_TXBUFFERENDIDXOFTXPDUINFO                                                         STD_OFF
#define COM_ISDEF_TXBUFFERLENGTHOFTXPDUINFO                                                         STD_OFF
#define COM_ISDEF_TXBUFFERSTARTIDXOFTXPDUINFO                                                       STD_OFF
#define COM_ISDEF_TXBUFFERUSEDOFTXPDUINFO                                                           STD_OFF
#define COM_ISDEF_TXPDUINITVALUEENDIDXOFTXPDUINFO                                                   STD_OFF
#define COM_ISDEF_TXPDUINITVALUESTARTIDXOFTXPDUINFO                                                 STD_OFF
#define COM_ISDEF_TXPDUINITVALUEUSEDOFTXPDUINFO                                                     STD_OFF
#define COM_ISDEF_TXPDUINFOIND                                                                      STD_OFF
#define COM_ISDEF_TXPDUINITVALUE                                                                    STD_OFF
#define COM_ISDEF_APPLTYPEOFTXSIGINFO                                                               STD_OFF
#define COM_ISDEF_BITLENGTHOFTXSIGINFO                                                              STD_OFF
#define COM_ISDEF_BITPOSITIONOFTXSIGINFO                                                            STD_OFF
#define COM_ISDEF_BUSACCOFTXSIGINFO                                                                 STD_OFF
#define COM_ISDEF_BYTELENGTHOFTXSIGINFO                                                             STD_OFF
#define COM_ISDEF_BYTEPOSITIONOFTXSIGINFO                                                           STD_OFF
#define COM_ISDEF_STARTBYTEINPDUPOSITIONOFTXSIGINFO                                                 STD_OFF
#define COM_ISDEF_TXBUFFERENDIDXOFTXSIGINFO                                                         STD_OFF
#define COM_ISDEF_TXBUFFERLENGTHOFTXSIGINFO                                                         STD_OFF
#define COM_ISDEF_TXBUFFERSTARTIDXOFTXSIGINFO                                                       STD_OFF
#define COM_ISDEF_TXBUFFERUSEDOFTXSIGINFO                                                           STD_OFF
#define COM_ISDEF_TXPDUINFOIDXOFTXSIGINFO                                                           STD_OFF
#define COM_ISDEF_ALWAYSACTIVETXCOMIPDUSOFPCCONFIG                                                  STD_ON
#define COM_ISDEF_CBKRXTOUTFUNCPTRINDOFPCCONFIG                                                     STD_ON
#define COM_ISDEF_CBKRXTOUTFUNCPTROFPCCONFIG                                                        STD_ON
#define COM_ISDEF_CONSTVALUEUINT16OFPCCONFIG                                                        STD_ON
#define COM_ISDEF_CONSTVALUEUINT32OFPCCONFIG                                                        STD_ON
#define COM_ISDEF_CONSTVALUEUINT8OFPCCONFIG                                                         STD_ON
#define COM_ISDEF_CURRENTTXMODEOFPCCONFIG                                                           STD_ON
#define COM_ISDEF_CYCLETIMECNTOFPCCONFIG                                                            STD_ON
#define COM_ISDEF_CYCLICSENDREQUESTOFPCCONFIG                                                       STD_ON
#define COM_ISDEF_HANDLERXPDUDEFERREDOFPCCONFIG                                                     STD_ON
#define COM_ISDEF_IPDUGROUPINFOOFPCCONFIG                                                           STD_ON
#define COM_ISDEF_IPDUGROUPINFOOFRXPDUINFOINDOFPCCONFIG                                             STD_ON
#define COM_ISDEF_IPDUGROUPINFOOFTXPDUINFOINDOFPCCONFIG                                             STD_ON
#define COM_ISDEF_IPDUGROUPINFOTOSUBIPDUGROUPSINDOFPCCONFIG                                         STD_ON
#define COM_ISDEF_IPDUGROUPSTATEOFPCCONFIG                                                          STD_ON
#define COM_ISDEF_INITIALIZEDOFPCCONFIG                                                             STD_ON
#define COM_ISDEF_RXACCESSINFOINDOFPCCONFIG                                                         STD_ON
#define COM_ISDEF_RXACCESSINFOOFPCCONFIG                                                            STD_ON
#define COM_ISDEF_RXCBKFUNCPTROFPCCONFIG                                                            STD_ON
#define COM_ISDEF_RXDEADLINEMONITORINGISRLOCKCOUNTEROFPCCONFIG                                      STD_ON
#define COM_ISDEF_RXDEFPDUBUFFEROFPCCONFIG                                                          STD_ON
#define COM_ISDEF_RXDEFERREDFCTPTRCACHEOFPCCONFIG                                                   STD_ON
#define COM_ISDEF_RXDEFERREDPROCESSINGISRLOCKCOUNTEROFPCCONFIG                                      STD_ON
#define COM_ISDEF_RXDLMONDIVISORCOUNTEROFPCCONFIG                                                   STD_ON
#define COM_ISDEF_RXIPDUGROUPISRLOCKCOUNTEROFPCCONFIG                                               STD_ON
#define COM_ISDEF_RXPDUDMSTATEOFPCCONFIG                                                            STD_ON
#define COM_ISDEF_RXPDUGRPACTIVEOFPCCONFIG                                                          STD_ON
#define COM_ISDEF_RXPDUINFOINDOFPCCONFIG                                                            STD_ON
#define COM_ISDEF_RXPDUINFOOFPCCONFIG                                                               STD_ON
#define COM_ISDEF_RXSIGBUFFERUINT16OFPCCONFIG                                                       STD_ON
#define COM_ISDEF_RXSIGBUFFERUINT32OFPCCONFIG                                                       STD_ON
#define COM_ISDEF_RXSIGBUFFERUINT8OFPCCONFIG                                                        STD_ON
#define COM_ISDEF_RXSIGINFOOFPCCONFIG                                                               STD_ON
#define COM_ISDEF_RXTOUTCNTOFPCCONFIG                                                               STD_ON
#define COM_ISDEF_RXTOUTINFOINDOFPCCONFIG                                                           STD_ON
#define COM_ISDEF_RXTOUTINFOOFPCCONFIG                                                              STD_ON
#define COM_ISDEF_TRANSMITREQUESTOFPCCONFIG                                                         STD_ON
#define COM_ISDEF_TXBUFFEROFPCCONFIG                                                                STD_ON
#define COM_ISDEF_TXCYCLECOUNTERDIVISORCOUNTEROFPCCONFIG                                            STD_ON
#define COM_ISDEF_TXCYCLICPDUOFPCCONFIG                                                             STD_ON
#define COM_ISDEF_TXCYCLICPROCESSINGISRLOCKCOUNTEROFPCCONFIG                                        STD_ON
#define COM_ISDEF_TXIPDUGROUPISRLOCKCOUNTEROFPCCONFIG                                               STD_ON
#define COM_ISDEF_TXMODEFALSEOFPCCONFIG                                                             STD_ON
#define COM_ISDEF_TXMODEINFOOFPCCONFIG                                                              STD_ON
#define COM_ISDEF_TXMODETRUEOFPCCONFIG                                                              STD_ON
#define COM_ISDEF_TXPDUGRPACTIVEOFPCCONFIG                                                          STD_ON
#define COM_ISDEF_TXPDUINFOINDOFPCCONFIG                                                            STD_ON
#define COM_ISDEF_TXPDUINFOOFPCCONFIG                                                               STD_ON
#define COM_ISDEF_TXPDUINITVALUEOFPCCONFIG                                                          STD_ON
#define COM_ISDEF_TXPROCESSINGISRLOCKCOUNTEROFPCCONFIG                                              STD_ON
#define COM_ISDEF_TXSDULENGTHOFPCCONFIG                                                             STD_ON
#define COM_ISDEF_TXSIGINFOOFPCCONFIG                                                               STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  ComPCEqualsAlwaysToDefines  Com Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define COM_EQ2_TXPDUINFOIDXOFALWAYSACTIVETXCOMIPDUS                                                
#define COM_EQ2_CBKRXTOUTFUNCPTR                                                                    
#define COM_EQ2_CBKRXTOUTFUNCPTRIND                                                                 
#define COM_EQ2_CONSTVALUEUINT16                                                                    
#define COM_EQ2_CONSTVALUEUINT32                                                                    
#define COM_EQ2_CONSTVALUEUINT8                                                                     
#define COM_EQ2_IPDUGROUPINFOTOSUBIPDUGROUPSINDENDIDXOFIPDUGROUPINFO                                
#define COM_EQ2_IPDUGROUPINFOTOSUBIPDUGROUPSINDSTARTIDXOFIPDUGROUPINFO                              
#define COM_EQ2_IPDUGROUPINFOTOSUBIPDUGROUPSINDUSEDOFIPDUGROUPINFO                                  
#define COM_EQ2_RXPDUINFOINDENDIDXOFIPDUGROUPINFO                                                   
#define COM_EQ2_RXPDUINFOINDSTARTIDXOFIPDUGROUPINFO                                                 
#define COM_EQ2_RXPDUINFOINDUSEDOFIPDUGROUPINFO                                                     
#define COM_EQ2_TXPDUINFOINDENDIDXOFIPDUGROUPINFO                                                   
#define COM_EQ2_TXPDUINFOINDSTARTIDXOFIPDUGROUPINFO                                                 
#define COM_EQ2_TXPDUINFOINDUSEDOFIPDUGROUPINFO                                                     
#define COM_EQ2_IPDUGROUPINFOOFRXPDUINFOIND                                                         
#define COM_EQ2_IPDUGROUPINFOOFTXPDUINFOIND                                                         
#define COM_EQ2_IPDUGROUPINFOTOSUBIPDUGROUPSIND                                                     
#define COM_EQ2_APPLTYPEOFRXACCESSINFO                                                              
#define COM_EQ2_BITLENGTHOFRXACCESSINFO                                                             
#define COM_EQ2_BITPOSITIONOFRXACCESSINFO                                                           
#define COM_EQ2_BUFFERIDXOFRXACCESSINFO                                                             
#define COM_EQ2_BUFFERUSEDOFRXACCESSINFO                                                            
#define COM_EQ2_BUSACCOFRXACCESSINFO                                                                
#define COM_EQ2_BYTELENGTHOFRXACCESSINFO                                                            
#define COM_EQ2_BYTEPOSITIONOFRXACCESSINFO                                                          
#define COM_EQ2_INITVALUEIDXOFRXACCESSINFO                                                          
#define COM_EQ2_INITVALUEUSEDOFRXACCESSINFO                                                         
#define COM_EQ2_RXPDUINFOIDXOFRXACCESSINFO                                                          
#define COM_EQ2_RXTOUTINFOIDXOFRXACCESSINFO                                                         
#define COM_EQ2_RXTOUTINFOUSEDOFRXACCESSINFO                                                        
#define COM_EQ2_STARTBYTEINPDUPOSITIONOFRXACCESSINFO                                                
#define COM_EQ2_RXACCESSINFOIND                                                                     
#define COM_EQ2_RXCBKFUNCPTR                                                                        
#define COM_EQ2_HANDLERXPDUDEFERREDIDXOFRXPDUINFO                                                   
#define COM_EQ2_HANDLERXPDUDEFERREDUSEDOFRXPDUINFO                                                  
#define COM_EQ2_IPDUGROUPINFOOFRXPDUINFOINDENDIDXOFRXPDUINFO                                        
#define COM_EQ2_IPDUGROUPINFOOFRXPDUINFOINDSTARTIDXOFRXPDUINFO                                      
#define COM_EQ2_IPDUGROUPINFOOFRXPDUINFOINDUSEDOFRXPDUINFO                                          
#define COM_EQ2_RXACCESSINFOINDENDIDXOFRXPDUINFO                                                    
#define COM_EQ2_RXACCESSINFOINDSTARTIDXOFRXPDUINFO                                                  
#define COM_EQ2_RXACCESSINFOINDUSEDOFRXPDUINFO                                                      
#define COM_EQ2_RXDEFPDUBUFFERENDIDXOFRXPDUINFO                                                     
#define COM_EQ2_RXDEFPDUBUFFERLENGTHOFRXPDUINFO                                                     
#define COM_EQ2_RXDEFPDUBUFFERSTARTIDXOFRXPDUINFO                                                   
#define COM_EQ2_RXDEFPDUBUFFERUSEDOFRXPDUINFO                                                       
#define COM_EQ2_RXSIGINFOENDIDXOFRXPDUINFO                                                          
#define COM_EQ2_RXSIGINFOSTARTIDXOFRXPDUINFO                                                        
#define COM_EQ2_RXSIGINFOUSEDOFRXPDUINFO                                                            
#define COM_EQ2_RXTOUTINFOIDXOFRXPDUINFO                                                            
#define COM_EQ2_RXTOUTINFOINDENDIDXOFRXPDUINFO                                                      
#define COM_EQ2_RXTOUTINFOINDSTARTIDXOFRXPDUINFO                                                    
#define COM_EQ2_RXTOUTINFOINDUSEDOFRXPDUINFO                                                        
#define COM_EQ2_RXTOUTINFOUSEDOFRXPDUINFO                                                           
#define COM_EQ2_SIGNALPROCESSINGOFRXPDUINFO                                                         
#define COM_EQ2_TYPEOFRXPDUINFO                                                                     
#define COM_EQ2_RXPDUINFOIND                                                                        
#define COM_EQ2_RXACCESSINFOIDXOFRXSIGINFO                                                          
#define COM_EQ2_RXCBKFUNCPTRACKIDXOFRXSIGINFO                                                       
#define COM_EQ2_RXCBKFUNCPTRACKUSEDOFRXSIGINFO                                                      
#define COM_EQ2_RXTOUTINFOIDXOFRXSIGINFO                                                            
#define COM_EQ2_RXTOUTINFOUSEDOFRXSIGINFO                                                           
#define COM_EQ2_SIGNALPROCESSINGOFRXSIGINFO                                                         
#define COM_EQ2_VALIDDLCOFRXSIGINFO                                                                 
#define COM_EQ2_CBKRXTOUTFUNCPTRINDENDIDXOFRXTOUTINFO                                               
#define COM_EQ2_CBKRXTOUTFUNCPTRINDSTARTIDXOFRXTOUTINFO                                             
#define COM_EQ2_CBKRXTOUTFUNCPTRINDUSEDOFRXTOUTINFO                                                 
#define COM_EQ2_FACTOROFRXTOUTINFO                                                                  
#define COM_EQ2_FIRSTFACTOROFRXTOUTINFO                                                             
#define COM_EQ2_RXPDUINFOIDXOFRXTOUTINFO                                                            
#define COM_EQ2_RXTOUTINFOIND                                                                       
#define COM_EQ2_TXPDUINFOIDXOFTXCYCLICPDU                                                           
#define COM_EQ2_PERIODICOFTXMODEFALSE                                                               
#define COM_EQ2_TIMEPERIODOFTXMODEFALSE                                                             
#define COM_EQ2_INITMODEOFTXMODEINFO                                                                
#define COM_EQ2_TXMODEFALSEIDXOFTXMODEINFO                                                          
#define COM_EQ2_TXMODETRUEIDXOFTXMODEINFO                                                           
#define COM_EQ2_PERIODICOFTXMODETRUE                                                                
#define COM_EQ2_TIMEPERIODOFTXMODETRUE                                                              
#define COM_EQ2_EXTERNALIDOFTXPDUINFO                                                               
#define COM_EQ2_IPDUGROUPINFOOFTXPDUINFOINDENDIDXOFTXPDUINFO                                        
#define COM_EQ2_IPDUGROUPINFOOFTXPDUINFOINDSTARTIDXOFTXPDUINFO                                      
#define COM_EQ2_IPDUGROUPINFOOFTXPDUINFOINDUSEDOFTXPDUINFO                                          
#define COM_EQ2_METADATALENGTHOFTXPDUINFO                                                           
#define COM_EQ2_PDUWITHMETADATALENGTHOFTXPDUINFO                                                    
#define COM_EQ2_TXBUFFERENDIDXOFTXPDUINFO                                                           
#define COM_EQ2_TXBUFFERLENGTHOFTXPDUINFO                                                           
#define COM_EQ2_TXBUFFERSTARTIDXOFTXPDUINFO                                                         
#define COM_EQ2_TXBUFFERUSEDOFTXPDUINFO                                                             
#define COM_EQ2_TXPDUINITVALUEENDIDXOFTXPDUINFO                                                     
#define COM_EQ2_TXPDUINITVALUESTARTIDXOFTXPDUINFO                                                   
#define COM_EQ2_TXPDUINITVALUEUSEDOFTXPDUINFO                                                       
#define COM_EQ2_TXPDUINFOIND                                                                        
#define COM_EQ2_TXPDUINITVALUE                                                                      
#define COM_EQ2_APPLTYPEOFTXSIGINFO                                                                 
#define COM_EQ2_BITLENGTHOFTXSIGINFO                                                                
#define COM_EQ2_BITPOSITIONOFTXSIGINFO                                                              
#define COM_EQ2_BUSACCOFTXSIGINFO                                                                   
#define COM_EQ2_BYTELENGTHOFTXSIGINFO                                                               
#define COM_EQ2_BYTEPOSITIONOFTXSIGINFO                                                             
#define COM_EQ2_STARTBYTEINPDUPOSITIONOFTXSIGINFO                                                   
#define COM_EQ2_TXBUFFERENDIDXOFTXSIGINFO                                                           
#define COM_EQ2_TXBUFFERLENGTHOFTXSIGINFO                                                           
#define COM_EQ2_TXBUFFERSTARTIDXOFTXSIGINFO                                                         
#define COM_EQ2_TXBUFFERUSEDOFTXSIGINFO                                                             
#define COM_EQ2_TXPDUINFOIDXOFTXSIGINFO                                                             
#define COM_EQ2_ALWAYSACTIVETXCOMIPDUSOFPCCONFIG                                                    Com_AlwaysActiveTxComIPdus
#define COM_EQ2_CBKRXTOUTFUNCPTRINDOFPCCONFIG                                                       Com_CbkRxTOutFuncPtrInd
#define COM_EQ2_CBKRXTOUTFUNCPTROFPCCONFIG                                                          Com_CbkRxTOutFuncPtr
#define COM_EQ2_CONSTVALUEUINT16OFPCCONFIG                                                          Com_ConstValueUInt16
#define COM_EQ2_CONSTVALUEUINT32OFPCCONFIG                                                          Com_ConstValueUInt32
#define COM_EQ2_CONSTVALUEUINT8OFPCCONFIG                                                           Com_ConstValueUInt8
#define COM_EQ2_CURRENTTXMODEOFPCCONFIG                                                             Com_CurrentTxMode
#define COM_EQ2_CYCLETIMECNTOFPCCONFIG                                                              Com_CycleTimeCnt
#define COM_EQ2_CYCLICSENDREQUESTOFPCCONFIG                                                         Com_CyclicSendRequest
#define COM_EQ2_HANDLERXPDUDEFERREDOFPCCONFIG                                                       Com_HandleRxPduDeferred.raw
#define COM_EQ2_IPDUGROUPINFOOFPCCONFIG                                                             Com_IPduGroupInfo
#define COM_EQ2_IPDUGROUPINFOOFRXPDUINFOINDOFPCCONFIG                                               Com_IPduGroupInfoOfRxPduInfoInd
#define COM_EQ2_IPDUGROUPINFOOFTXPDUINFOINDOFPCCONFIG                                               Com_IPduGroupInfoOfTxPduInfoInd
#define COM_EQ2_IPDUGROUPINFOTOSUBIPDUGROUPSINDOFPCCONFIG                                           Com_IPduGroupInfoToSubIPduGroupsInd
#define COM_EQ2_IPDUGROUPSTATEOFPCCONFIG                                                            Com_IPduGroupState
#define COM_EQ2_INITIALIZEDOFPCCONFIG                                                               (&(Com_Initialized))
#define COM_EQ2_RXACCESSINFOINDOFPCCONFIG                                                           Com_RxAccessInfoInd
#define COM_EQ2_RXACCESSINFOOFPCCONFIG                                                              Com_RxAccessInfo
#define COM_EQ2_RXCBKFUNCPTROFPCCONFIG                                                              Com_RxCbkFuncPtr
#define COM_EQ2_RXDEADLINEMONITORINGISRLOCKCOUNTEROFPCCONFIG                                        (&(Com_RxDeadlineMonitoringISRLockCounter))
#define COM_EQ2_RXDEFPDUBUFFEROFPCCONFIG                                                            Com_RxDefPduBuffer.raw
#define COM_EQ2_RXDEFERREDFCTPTRCACHEOFPCCONFIG                                                     Com_RxDeferredFctPtrCache
#define COM_EQ2_RXDEFERREDPROCESSINGISRLOCKCOUNTEROFPCCONFIG                                        (&(Com_RxDeferredProcessingISRLockCounter))
#define COM_EQ2_RXDLMONDIVISORCOUNTEROFPCCONFIG                                                     (&(Com_RxDlMonDivisorCounter))
#define COM_EQ2_RXIPDUGROUPISRLOCKCOUNTEROFPCCONFIG                                                 (&(Com_RxIPduGroupISRLockCounter))
#define COM_EQ2_RXPDUDMSTATEOFPCCONFIG                                                              Com_RxPduDmState
#define COM_EQ2_RXPDUGRPACTIVEOFPCCONFIG                                                            Com_RxPduGrpActive
#define COM_EQ2_RXPDUINFOINDOFPCCONFIG                                                              Com_RxPduInfoInd
#define COM_EQ2_RXPDUINFOOFPCCONFIG                                                                 Com_RxPduInfo
#define COM_EQ2_RXSIGBUFFERUINT16OFPCCONFIG                                                         Com_RxSigBufferUInt16
#define COM_EQ2_RXSIGBUFFERUINT32OFPCCONFIG                                                         Com_RxSigBufferUInt32
#define COM_EQ2_RXSIGBUFFERUINT8OFPCCONFIG                                                          Com_RxSigBufferUInt8
#define COM_EQ2_RXSIGINFOOFPCCONFIG                                                                 Com_RxSigInfo
#define COM_EQ2_RXTOUTCNTOFPCCONFIG                                                                 Com_RxTOutCnt
#define COM_EQ2_RXTOUTINFOINDOFPCCONFIG                                                             Com_RxTOutInfoInd
#define COM_EQ2_RXTOUTINFOOFPCCONFIG                                                                Com_RxTOutInfo
#define COM_EQ2_TRANSMITREQUESTOFPCCONFIG                                                           Com_TransmitRequest
#define COM_EQ2_TXBUFFEROFPCCONFIG                                                                  Com_TxBuffer
#define COM_EQ2_TXCYCLECOUNTERDIVISORCOUNTEROFPCCONFIG                                              (&(Com_TxCycleCounterDivisorCounter))
#define COM_EQ2_TXCYCLICPDUOFPCCONFIG                                                               Com_TxCyclicPdu
#define COM_EQ2_TXCYCLICPROCESSINGISRLOCKCOUNTEROFPCCONFIG                                          (&(Com_TxCyclicProcessingISRLockCounter))
#define COM_EQ2_TXIPDUGROUPISRLOCKCOUNTEROFPCCONFIG                                                 (&(Com_TxIPduGroupISRLockCounter))
#define COM_EQ2_TXMODEFALSEOFPCCONFIG                                                               Com_TxModeFalse
#define COM_EQ2_TXMODEINFOOFPCCONFIG                                                                Com_TxModeInfo
#define COM_EQ2_TXMODETRUEOFPCCONFIG                                                                Com_TxModeTrue
#define COM_EQ2_TXPDUGRPACTIVEOFPCCONFIG                                                            Com_TxPduGrpActive
#define COM_EQ2_TXPDUINFOINDOFPCCONFIG                                                              Com_TxPduInfoInd
#define COM_EQ2_TXPDUINFOOFPCCONFIG                                                                 Com_TxPduInfo
#define COM_EQ2_TXPDUINITVALUEOFPCCONFIG                                                            Com_TxPduInitValue
#define COM_EQ2_TXPROCESSINGISRLOCKCOUNTEROFPCCONFIG                                                (&(Com_TxProcessingISRLockCounter))
#define COM_EQ2_TXSDULENGTHOFPCCONFIG                                                               Com_TxSduLength
#define COM_EQ2_TXSIGINFOOFPCCONFIG                                                                 Com_TxSigInfo
/** 
  \}
*/ 

/** 
  \defgroup  ComPCSymbolicInitializationPointers  Com Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define Com_Config_Ptr                                                                              NULL_PTR  /**< symbolic identifier which shall be used to initialize 'Com' */
/** 
  \}
*/ 

/** 
  \defgroup  ComPCInitializationSymbols  Com Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define Com_Config                                                                                  NULL_PTR  /**< symbolic identifier which could be used to initialize 'Com */
/** 
  \}
*/ 

/** 
  \defgroup  ComPCGeneral  Com General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define COM_CHECK_INIT_POINTER                                                                      STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define COM_FINAL_MAGIC_NUMBER                                                                      0x321Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of Com */
#define COM_INDIVIDUAL_POSTBUILD                                                                    STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'Com' is not configured to be postbuild capable. */
#define COM_INIT_DATA                                                                               COM_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define COM_INIT_DATA_HASH_CODE                                                                     -917688657  /**< the precompile constant to validate the initialization structure at initialization time of Com with a hashcode. The seed value is '0x321Eu' */
#define COM_USE_ECUM_BSW_ERROR_HOOK                                                                 STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define COM_USE_INIT_POINTER                                                                        STD_OFF  /**< STD_ON if the init pointer Com shall be used. */
/** 
  \}
*/ 



/* General */
#define COM_DEV_ERROR_DETECT                 STD_OFF  /**< /ActiveEcuC/Com/ComGeneral[0:ComSafeBswChecks] || /ActiveEcuC/Com/ComGeneral[0:ComConfigurationUseDet] */
#define COM_DEV_ERROR_REPORT                 STD_OFF  /**< /ActiveEcuC/Com/ComGeneral[0:ComConfigurationUseDet] */
#define COM_RETRY_FAILED_TRANSMIT_REQUESTS   STD_ON  /**< /ActiveEcuC/Com/ComGeneral[0:ComRetryFailedTransmitRequests] */
#define COM_IPDUCALLOUT_USEPDUINFOPTR        STD_ON  /**< /ActiveEcuC/Com/ComGeneral[0:ComAdvancedIPduCallouts] */

/* Optimization */
#define COM_RECEIVE_SIGNAL_MACRO_API         STD_OFF

/* API */
#define COM_COMMUNICATION_INTERFACE          STD_ON  /**< /ActiveEcuC/PduR/Com[0:PduRCommunicationInterface] */
#define COM_TRANSPORT_PROTOCOL               STD_OFF  /**< /ActiveEcuC/PduR/Com[0:PduRTransportProtocol] */

#define COM_TRIGGER_TRANSMIT_API             STD_ON  /**< /ActiveEcuC/PduR/Com[0:PduRTriggertransmit] */
#define COM_TX_CONFIRMATION_API              STD_ON  /**< /ActiveEcuC/PduR/Com[0:PduRTxConfirmation] */
#define COM_TRIGGER_IPDU_SEND_WITH_META_DATA_API    STD_OFF  /**< /ActiveEcuC/Com/ComGeneral[0:ComMetaDataSupport] */
#define COM_MAIN_FUNCTION_ROUTE_SIGNALS_API  STD_OFF  /**< /ActiveEcuC/Com/ComGeneral[0:ComSignalGateway] || /ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] */
#define COM_ENABLE_SIGNAL_GROUP_ARRAY_API    STD_OFF  /**< /ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] */

#define COM_VERSION_INFO_API                 STD_OFF  /**< /ActiveEcuC/Com/ComGeneral[0:ComVersionInfoApi] */
#define COM_GENERATED_DESCRIPTION_ROUTING    STD_OFF  /**< /ActiveEcuC/Com/ComGeneral[0:ComDescriptionRoutingCodeGeneration] */

#define COM_LMGT_MAXIPDUGROUPVECTORBYTECNT   1U
#define COM_SUPPORTED_IPDU_GROUPS            2uL  /**< /ActiveEcuC/Com/ComGeneral[0:ComSupportedIPduGroups] */

#define COM_RXIMMEDIATEFCTPTRCACHE           STD_OFF
#define COM_RXIMMEDIATEFCTPTRCACHESIZE       0U

/**
  \brief  Constants to compare floating-point values according to ISO C-99 standard.
  \details  -
    \{
*/
#define COM_FLT_EPSILON                      1E-5
#define COM_DBL_EPSILON                      1E-9
/**
  \}
*/




/**
 * \defgroup ComHandleIdsComRxSig Handle IDs of handle space ComRxSig.
 * \brief Rx Signals
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define ComConf_ComSignal_AnimationReq_oBCM17_oC03_for_EL_CAN_V2_1_1db28c46_Rx 0u
#define ComConf_ComSignal_ApproachLightAnimationType_oBCM17_oC03_for_EL_CAN_V2_1_5b20a81e_Rx 1u
#define ComConf_ComSignal_BMS_DCChrgConnect_oBMS17_oC03_for_EL_CAN_V2_1_91db617c_Rx 2u
#define ComConf_ComSignal_BMS_SOC_oBMS1_oC03_for_EL_CAN_V2_1_a261d1ce_Rx 3u
#define ComConf_ComSignal_CEMDetminCdnSts_oBCM23_oC03_for_EL_CAN_V2_1_df6348d5_Rx 4u
#define ComConf_ComSignal_CheckSum_ABS3_oABS3_oC03_for_EL_CAN_V2_1_5745e086_Rx 5u
#define ComConf_ComSignal_CheckSum_PEPS2_oPEPS2_oC03_for_EL_CAN_V2_1_06064851_Rx 6u
#define ComConf_ComSignal_Checksum_BCM10_oBCM10_oC03_for_EL_CAN_V2_1_819e75d3_Rx 7u
#define ComConf_ComSignal_ChrgDispPatTypSet_oHUT54_oC03_for_EL_CAN_V2_1_f6de33f3_Rx 8u
#define ComConf_ComSignal_ChrgPatDispSwt_oHUT54_oC03_for_EL_CAN_V2_1_f66d5f08_Rx 9u
#define ComConf_ComSignal_DeepSlpCmd_oEEM1_oC03_for_EL_CAN_V2_1_41fb7d93_Rx 10u
#define ComConf_ComSignal_EIDCSwt_oHUT54_oC03_for_EL_CAN_V2_1_ac2debcb_Rx 11u
#define ComConf_ComSignal_EmojiTypSet_oHUT54_oC03_for_EL_CAN_V2_1_ac4f7c91_Rx 12u
#define ComConf_ComSignal_GoodbyeAnimationType_oBCM17_oC03_for_EL_CAN_V2_1_bc8c4dab_Rx 13u
#define ComConf_ComSignal_IP_VehTotDistanceValid_oIP2_oC03_for_EL_CAN_V2_1_234ac38e_Rx 14u
#define ComConf_ComSignal_IP_VehTotDistance_oIP2_oC03_for_EL_CAN_V2_1_a238a7cc_Rx 15u
#define ComConf_ComSignal_LTurnLampWorkCmd_oBCM10_oC03_for_EL_CAN_V2_1_7a1a08f4_Rx 16u
#define ComConf_ComSignal_LTurnLmpSwtSts_oCSA1_oC03_for_EL_CAN_V2_1_458e5c96_Rx 17u
#define ComConf_ComSignal_MCU_ActRotSpd_oMCU_5_oC03_for_EL_CAN_V2_1_c2eb67f0_Rx 18u
#define ComConf_ComSignal_MecDancAnimationType_oBCM17_oC03_for_EL_CAN_V2_1_6bb5a98f_Rx 19u
#define ComConf_ComSignal_OBC_CCLineConnectSts_oOBC3_oC03_for_EL_CAN_V2_1_a7854723_Rx 20u
#define ComConf_ComSignal_PosnLmpOutpSts_R_PBox_oR_PBOX1_oC03_for_EL_CAN_V2_1_c63ace4d_Rx 21u
#define ComConf_ComSignal_RMCU_ActRotSpd_oRMCU4_oC03_for_EL_CAN_V2_1_a08a2435_Rx 22u
#define ComConf_ComSignal_RTurnLmpSwtSts_oCSA1_oC03_for_EL_CAN_V2_1_2fe59187_Rx 23u
#define ComConf_ComSignal_RTurnLmpWorkCmd_oBCM10_oC03_for_EL_CAN_V2_1_10ea9ba1_Rx 24u
#define ComConf_ComSignal_RemindTypSet_oHUT54_oC03_for_EL_CAN_V2_1_fc32c110_Rx 25u
#define ComConf_ComSignal_RollingCounter_ABS3_oABS3_oC03_for_EL_CAN_V2_1_b6ac7000_Rx 26u
#define ComConf_ComSignal_RollingCounter_PEPS2_oPEPS2_oC03_for_EL_CAN_V2_1_9bd00531_Rx 27u
#define ComConf_ComSignal_Rollingcounter_BCM10_oBCM10_oC03_for_EL_CAN_V2_1_6dd2f1f9_Rx 28u
#define ComConf_ComSignal_ScenarioID_oGW1_oC03_for_EL_CAN_V2_1_b0249678_Rx 29u
#define ComConf_ComSignal_ScenarioReq_oGW1_oC03_for_EL_CAN_V2_1_d81adfac_Rx 30u
#define ComConf_ComSignal_Stat_PwrSv_Lvl_oEEM1_oC03_for_EL_CAN_V2_1_a4eaa63e_Rx 31u
#define ComConf_ComSignal_SysPowerModVld_oPEPS2_oC03_for_EL_CAN_V2_1_b6c20e3c_Rx 32u
#define ComConf_ComSignal_SysPowerMod_oPEPS2_oC03_for_EL_CAN_V2_1_37fb939a_Rx 33u
#define ComConf_ComSignal_TimeIndcn_oHUT34_oC03_for_EL_CAN_V2_1_d29435a0_Rx 34u
#define ComConf_ComSignal_TimeMod_oHUT34_oC03_for_EL_CAN_V2_1_baa135ee_Rx 35u
#define ComConf_ComSignal_Time_Day_oHUT34_oC03_for_EL_CAN_V2_1_5996a937_Rx 36u
#define ComConf_ComSignal_Time_Hour_oHUT34_oC03_for_EL_CAN_V2_1_2c4ebd6a_Rx 37u
#define ComConf_ComSignal_Time_Minutes_oHUT34_oC03_for_EL_CAN_V2_1_da3ecd44_Rx 38u
#define ComConf_ComSignal_Time_Month_oHUT34_oC03_for_EL_CAN_V2_1_33ed510d_Rx 39u
#define ComConf_ComSignal_Time_Second_oHUT34_oC03_for_EL_CAN_V2_1_9732895b_Rx 40u
#define ComConf_ComSignal_Time_Year_Left_oHUT34_oC03_for_EL_CAN_V2_1_f1a91267_Rx 41u
#define ComConf_ComSignal_Time_Year_Right_oHUT34_oC03_for_EL_CAN_V2_1_fa890340_Rx 42u
#define ComConf_ComSignal_TopicTypSet_oHUT54_oC03_for_EL_CAN_V2_1_71504e9d_Rx 43u
#define ComConf_ComSignal_TranPMode_Sts_oEEM1_oC03_for_EL_CAN_V2_1_a5a3838d_Rx 44u
#define ComConf_ComSignal_TurnRemdSwt_oHUT54_oC03_for_EL_CAN_V2_1_06f5df9c_Rx 45u
#define ComConf_ComSignal_VCU_BrkPedlSts_oVCU6_oC03_for_EL_CAN_V2_1_66fed013_Rx 46u
#define ComConf_ComSignal_VCU_ChrgnSts_oVCU3_oC03_for_EL_CAN_V2_1_87b3fa1f_Rx 47u
#define ComConf_ComSignal_VCU_GearSts_oVCU2_oC03_for_EL_CAN_V2_1_71c2293d_Rx 48u
#define ComConf_ComSignal_VehSpdVld_oABS3_oC03_for_EL_CAN_V2_1_32497dd3_Rx 49u
#define ComConf_ComSignal_VehSpd_oABS3_oC03_for_EL_CAN_V2_1_23260d94_Rx 50u
#define ComConf_ComSignal_WelcomeAnimationType_oBCM17_oC03_for_EL_CAN_V2_1_c76d0f7a_Rx 51u
#define ComConf_ComSignal_WelcomePatTypSet_oHUT54_oC03_for_EL_CAN_V2_1_ac7026e0_Rx 52u
#define ComConf_ComSignal_WelcomeSwt_oHUT54_oC03_for_EL_CAN_V2_1_351ff7b4_Rx 53u
#define ComConf_ComSignal_WordTypSet_oHUT54_oC03_for_EL_CAN_V2_1_035aa6cb_Rx 54u
/**\} */

/**
 * \defgroup ComHandleIdsComTxSig Handle IDs of handle space ComTxSig.
 * \brief Tx Signals
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define ComConf_ComSignal_ChrgDispPatFailSts_oEIDC1_oC03_for_EL_CAN_V2_1_ad1e97ef_Tx 0u
#define ComConf_ComSignal_ComSignal_userData_byte2_tx                 1u
#define ComConf_ComSignal_ComSignal_userdata_Byte3_tx                 2u
#define ComConf_ComSignal_CurrChrgDispSts_oEIDC1_oC03_for_EL_CAN_V2_1_b91c73c4_Tx 3u
#define ComConf_ComSignal_CurrEmojiSts_oEIDC1_oC03_for_EL_CAN_V2_1_6bd59cd2_Tx 4u
#define ComConf_ComSignal_CurrRemdSts_oEIDC1_oC03_for_EL_CAN_V2_1_d08f6960_Tx 5u
#define ComConf_ComSignal_CurrTopicSts_oEIDC1_oC03_for_EL_CAN_V2_1_fe35aa4e_Tx 6u
#define ComConf_ComSignal_CurrWelcomeSts_oEIDC1_oC03_for_EL_CAN_V2_1_adc4e5a0_Tx 7u
#define ComConf_ComSignal_CurrWordSts_oEIDC1_oC03_for_EL_CAN_V2_1_141f7025_Tx 8u
#define ComConf_ComSignal_EIDCOpenFBSts_oEIDC1_oC03_for_EL_CAN_V2_1_c910b9b6_Tx 9u
#define ComConf_ComSignal_TurnRemdFailSts_oEIDC1_oC03_for_EL_CAN_V2_1_5d16f6d4_Tx 10u
#define ComConf_ComSignal_WelcomePatFailSts_oEIDC1_oC03_for_EL_CAN_V2_1_29fa7824_Tx 11u
/**\} */







/**
 * \defgroup ComHandleIds Handle IDs.
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define ComConf_ComIPduGroup_EIDC_oC03_for_EL_CAN_V2_1_Rx_0f13cc3b    0u
#define ComConf_ComIPduGroup_EIDC_oC03_for_EL_CAN_V2_1_Tx_59496bbd    1u
/**\} */

/**********************************************************************************************************************
  GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 Macros_3453 */  /* MD_MSR_FctLikeMacro */
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  ComPCGetConstantDuplicatedRootDataMacros  Com Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define Com_GetAlwaysActiveTxComIPdusOfPCConfig()                                                   Com_AlwaysActiveTxComIPdus  /**< the pointer to Com_AlwaysActiveTxComIPdus */
#define Com_GetCbkRxTOutFuncPtrIndOfPCConfig()                                                      Com_CbkRxTOutFuncPtrInd  /**< the pointer to Com_CbkRxTOutFuncPtrInd */
#define Com_GetCbkRxTOutFuncPtrOfPCConfig()                                                         Com_CbkRxTOutFuncPtr  /**< the pointer to Com_CbkRxTOutFuncPtr */
#define Com_GetConfigIdOfPCConfig()                                                                 0u  /**< DefinitionRef: /MICROSAR/Com/ComConfig/ComConfigurationId */
#define Com_GetConstValueUInt16OfPCConfig()                                                         Com_ConstValueUInt16  /**< the pointer to Com_ConstValueUInt16 */
#define Com_GetConstValueUInt32OfPCConfig()                                                         Com_ConstValueUInt32  /**< the pointer to Com_ConstValueUInt32 */
#define Com_GetConstValueUInt8OfPCConfig()                                                          Com_ConstValueUInt8  /**< the pointer to Com_ConstValueUInt8 */
#define Com_GetCurrentTxModeOfPCConfig()                                                            Com_CurrentTxMode  /**< the pointer to Com_CurrentTxMode */
#define Com_GetCycleTimeCntOfPCConfig()                                                             Com_CycleTimeCnt  /**< the pointer to Com_CycleTimeCnt */
#define Com_GetCyclicSendRequestOfPCConfig()                                                        Com_CyclicSendRequest  /**< the pointer to Com_CyclicSendRequest */
#define Com_GetHandleRxPduDeferredOfPCConfig()                                                      Com_HandleRxPduDeferred.raw  /**< the pointer to Com_HandleRxPduDeferred */
#define Com_GetIPduGroupInfoOfPCConfig()                                                            Com_IPduGroupInfo  /**< the pointer to Com_IPduGroupInfo */
#define Com_GetIPduGroupInfoOfRxPduInfoIndOfPCConfig()                                              Com_IPduGroupInfoOfRxPduInfoInd  /**< the pointer to Com_IPduGroupInfoOfRxPduInfoInd */
#define Com_GetIPduGroupInfoOfTxPduInfoIndOfPCConfig()                                              Com_IPduGroupInfoOfTxPduInfoInd  /**< the pointer to Com_IPduGroupInfoOfTxPduInfoInd */
#define Com_GetIPduGroupInfoToSubIPduGroupsIndOfPCConfig()                                          Com_IPduGroupInfoToSubIPduGroupsInd  /**< the pointer to Com_IPduGroupInfoToSubIPduGroupsInd */
#define Com_GetIPduGroupStateOfPCConfig()                                                           Com_IPduGroupState  /**< the pointer to Com_IPduGroupState */
#define Com_GetInitializedOfPCConfig()                                                              (&(Com_Initialized))  /**< the pointer to Com_Initialized */
#define Com_GetPduGrpCntOfPCConfig()                                                                0u
#define Com_GetRxAccessInfoIndOfPCConfig()                                                          Com_RxAccessInfoInd  /**< the pointer to Com_RxAccessInfoInd */
#define Com_GetRxAccessInfoOfPCConfig()                                                             Com_RxAccessInfo  /**< the pointer to Com_RxAccessInfo */
#define Com_GetRxCbkFuncPtrOfPCConfig()                                                             Com_RxCbkFuncPtr  /**< the pointer to Com_RxCbkFuncPtr */
#define Com_GetRxDeadlineMonitoringISRLockCounterOfPCConfig()                                       (&(Com_RxDeadlineMonitoringISRLockCounter))  /**< the pointer to Com_RxDeadlineMonitoringISRLockCounter */
#define Com_GetRxDeadlineMonitoringISRLockThresholdOfPCConfig()                                     1u
#define Com_GetRxDefPduBufferOfPCConfig()                                                           Com_RxDefPduBuffer.raw  /**< the pointer to Com_RxDefPduBuffer */
#define Com_GetRxDeferredFctPtrCacheOfPCConfig()                                                    Com_RxDeferredFctPtrCache  /**< the pointer to Com_RxDeferredFctPtrCache */
#define Com_GetRxDeferredProcessingISRLockCounterOfPCConfig()                                       (&(Com_RxDeferredProcessingISRLockCounter))  /**< the pointer to Com_RxDeferredProcessingISRLockCounter */
#define Com_GetRxDeferredProcessingISRLockThresholdOfPCConfig()                                     1u
#define Com_GetRxDlMonDivisorCounterOfPCConfig()                                                    (&(Com_RxDlMonDivisorCounter))  /**< the pointer to Com_RxDlMonDivisorCounter */
#define Com_GetRxDlMonDivisorOfPCConfig()                                                           8u  /**< Divisor for DefinitionRef: /MICROSAR/Com/ComConfig/ComTimeBase/ComRxDlMonTimeBase */
#define Com_GetRxIPduGroupISRLockCounterOfPCConfig()                                                (&(Com_RxIPduGroupISRLockCounter))  /**< the pointer to Com_RxIPduGroupISRLockCounter */
#define Com_GetRxIPduGroupISRLockThresholdOfPCConfig()                                              1u
#define Com_GetRxPduDmStateOfPCConfig()                                                             Com_RxPduDmState  /**< the pointer to Com_RxPduDmState */
#define Com_GetRxPduGrpActiveOfPCConfig()                                                           Com_RxPduGrpActive  /**< the pointer to Com_RxPduGrpActive */
#define Com_GetRxPduInfoIndOfPCConfig()                                                             Com_RxPduInfoInd  /**< the pointer to Com_RxPduInfoInd */
#define Com_GetRxPduInfoOfPCConfig()                                                                Com_RxPduInfo  /**< the pointer to Com_RxPduInfo */
#define Com_GetRxSigBufferUInt16OfPCConfig()                                                        Com_RxSigBufferUInt16  /**< the pointer to Com_RxSigBufferUInt16 */
#define Com_GetRxSigBufferUInt32OfPCConfig()                                                        Com_RxSigBufferUInt32  /**< the pointer to Com_RxSigBufferUInt32 */
#define Com_GetRxSigBufferUInt8OfPCConfig()                                                         Com_RxSigBufferUInt8  /**< the pointer to Com_RxSigBufferUInt8 */
#define Com_GetRxSigInfoOfPCConfig()                                                                Com_RxSigInfo  /**< the pointer to Com_RxSigInfo */
#define Com_GetRxTOutCntOfPCConfig()                                                                Com_RxTOutCnt  /**< the pointer to Com_RxTOutCnt */
#define Com_GetRxTOutInfoIndOfPCConfig()                                                            Com_RxTOutInfoInd  /**< the pointer to Com_RxTOutInfoInd */
#define Com_GetRxTOutInfoOfPCConfig()                                                               Com_RxTOutInfo  /**< the pointer to Com_RxTOutInfo */
#define Com_GetSizeOfAlwaysActiveTxComIPdusOfPCConfig()                                             1u  /**< the number of accomplishable value elements in Com_AlwaysActiveTxComIPdus */
#define Com_GetSizeOfCbkRxTOutFuncPtrIndOfPCConfig()                                                45u  /**< the number of accomplishable value elements in Com_CbkRxTOutFuncPtrInd */
#define Com_GetSizeOfCbkRxTOutFuncPtrOfPCConfig()                                                   45u  /**< the number of accomplishable value elements in Com_CbkRxTOutFuncPtr */
#define Com_GetSizeOfConstValueUInt16OfPCConfig()                                                   1u  /**< the number of accomplishable value elements in Com_ConstValueUInt16 */
#define Com_GetSizeOfConstValueUInt32OfPCConfig()                                                   1u  /**< the number of accomplishable value elements in Com_ConstValueUInt32 */
#define Com_GetSizeOfConstValueUInt8OfPCConfig()                                                    1u  /**< the number of accomplishable value elements in Com_ConstValueUInt8 */
#define Com_GetSizeOfHandleRxPduDeferredOfPCConfig()                                                20u  /**< the number of accomplishable value elements in Com_HandleRxPduDeferred */
#define Com_GetSizeOfIPduGroupInfoOfPCConfig()                                                      2u  /**< the number of accomplishable value elements in Com_IPduGroupInfo */
#define Com_GetSizeOfIPduGroupInfoOfRxPduInfoIndOfPCConfig()                                        20u  /**< the number of accomplishable value elements in Com_IPduGroupInfoOfRxPduInfoInd */
#define Com_GetSizeOfIPduGroupInfoOfTxPduInfoIndOfPCConfig()                                        1u  /**< the number of accomplishable value elements in Com_IPduGroupInfoOfTxPduInfoInd */
#define Com_GetSizeOfIPduGroupInfoToSubIPduGroupsIndOfPCConfig()                                    2u  /**< the number of accomplishable value elements in Com_IPduGroupInfoToSubIPduGroupsInd */
#define Com_GetSizeOfRxAccessInfoIndOfPCConfig()                                                    55u  /**< the number of accomplishable value elements in Com_RxAccessInfoInd */
#define Com_GetSizeOfRxAccessInfoOfPCConfig()                                                       55u  /**< the number of accomplishable value elements in Com_RxAccessInfo */
#define Com_GetSizeOfRxCbkFuncPtrOfPCConfig()                                                       55u  /**< the number of accomplishable value elements in Com_RxCbkFuncPtr */
#define Com_GetSizeOfRxDefPduBufferOfPCConfig()                                                     160u  /**< the number of accomplishable value elements in Com_RxDefPduBuffer */
#define Com_GetSizeOfRxDeferredFctPtrCacheOfPCConfig()                                              1u  /**< the number of accomplishable value elements in Com_RxDeferredFctPtrCache */
#define Com_GetSizeOfRxPduInfoIndOfPCConfig()                                                       20u  /**< the number of accomplishable value elements in Com_RxPduInfoInd */
#define Com_GetSizeOfRxPduInfoOfPCConfig()                                                          20u  /**< the number of accomplishable value elements in Com_RxPduInfo */
#define Com_GetSizeOfRxSigBufferUInt16OfPCConfig()                                                  4u  /**< the number of accomplishable value elements in Com_RxSigBufferUInt16 */
#define Com_GetSizeOfRxSigBufferUInt32OfPCConfig()                                                  1u  /**< the number of accomplishable value elements in Com_RxSigBufferUInt32 */
#define Com_GetSizeOfRxSigBufferUInt8OfPCConfig()                                                   50u  /**< the number of accomplishable value elements in Com_RxSigBufferUInt8 */
#define Com_GetSizeOfRxSigInfoOfPCConfig()                                                          55u  /**< the number of accomplishable value elements in Com_RxSigInfo */
#define Com_GetSizeOfRxTOutInfoIndOfPCConfig()                                                      19u  /**< the number of accomplishable value elements in Com_RxTOutInfoInd */
#define Com_GetSizeOfRxTOutInfoOfPCConfig()                                                         19u  /**< the number of accomplishable value elements in Com_RxTOutInfo */
#define Com_GetSizeOfTxBufferOfPCConfig()                                                           14u  /**< the number of accomplishable value elements in Com_TxBuffer */
#define Com_GetSizeOfTxCyclicPduOfPCConfig()                                                        1u  /**< the number of accomplishable value elements in Com_TxCyclicPdu */
#define Com_GetSizeOfTxModeFalseOfPCConfig()                                                        2u  /**< the number of accomplishable value elements in Com_TxModeFalse */
#define Com_GetSizeOfTxModeInfoOfPCConfig()                                                         2u  /**< the number of accomplishable value elements in Com_TxModeInfo */
#define Com_GetSizeOfTxModeTrueOfPCConfig()                                                         2u  /**< the number of accomplishable value elements in Com_TxModeTrue */
#define Com_GetSizeOfTxPduInfoIndOfPCConfig()                                                       1u  /**< the number of accomplishable value elements in Com_TxPduInfoInd */
#define Com_GetSizeOfTxPduInfoOfPCConfig()                                                          2u  /**< the number of accomplishable value elements in Com_TxPduInfo */
#define Com_GetSizeOfTxPduInitValueOfPCConfig()                                                     14u  /**< the number of accomplishable value elements in Com_TxPduInitValue */
#define Com_GetSizeOfTxSigInfoOfPCConfig()                                                          12u  /**< the number of accomplishable value elements in Com_TxSigInfo */
#define Com_GetTransmitRequestOfPCConfig()                                                          Com_TransmitRequest  /**< the pointer to Com_TransmitRequest */
#define Com_GetTxBufferOfPCConfig()                                                                 Com_TxBuffer  /**< the pointer to Com_TxBuffer */
#define Com_GetTxCycleCounterDivisorCounterOfPCConfig()                                             (&(Com_TxCycleCounterDivisorCounter))  /**< the pointer to Com_TxCycleCounterDivisorCounter */
#define Com_GetTxCycleCounterDivisorOfPCConfig()                                                    40u  /**< Divisor for DefinitionRef: /MICROSAR/Com/ComConfig/ComTimeBase/ComTxCycleCounterTimeBase */
#define Com_GetTxCyclicPduOfPCConfig()                                                              Com_TxCyclicPdu  /**< the pointer to Com_TxCyclicPdu */
#define Com_GetTxCyclicProcessingISRLockCounterOfPCConfig()                                         (&(Com_TxCyclicProcessingISRLockCounter))  /**< the pointer to Com_TxCyclicProcessingISRLockCounter */
#define Com_GetTxCyclicProcessingISRLockThresholdOfPCConfig()                                       1u
#define Com_GetTxIPduGroupISRLockCounterOfPCConfig()                                                (&(Com_TxIPduGroupISRLockCounter))  /**< the pointer to Com_TxIPduGroupISRLockCounter */
#define Com_GetTxIPduGroupISRLockThresholdOfPCConfig()                                              1u
#define Com_GetTxModeFalseOfPCConfig()                                                              Com_TxModeFalse  /**< the pointer to Com_TxModeFalse */
#define Com_GetTxModeInfoOfPCConfig()                                                               Com_TxModeInfo  /**< the pointer to Com_TxModeInfo */
#define Com_GetTxModeTrueOfPCConfig()                                                               Com_TxModeTrue  /**< the pointer to Com_TxModeTrue */
#define Com_GetTxPduGrpActiveOfPCConfig()                                                           Com_TxPduGrpActive  /**< the pointer to Com_TxPduGrpActive */
#define Com_GetTxPduInfoIndOfPCConfig()                                                             Com_TxPduInfoInd  /**< the pointer to Com_TxPduInfoInd */
#define Com_GetTxPduInfoOfPCConfig()                                                                Com_TxPduInfo  /**< the pointer to Com_TxPduInfo */
#define Com_GetTxPduInitValueOfPCConfig()                                                           Com_TxPduInitValue  /**< the pointer to Com_TxPduInitValue */
#define Com_GetTxProcessingISRLockCounterOfPCConfig()                                               (&(Com_TxProcessingISRLockCounter))  /**< the pointer to Com_TxProcessingISRLockCounter */
#define Com_GetTxProcessingISRLockThresholdOfPCConfig()                                             1u
#define Com_GetTxSduLengthOfPCConfig()                                                              Com_TxSduLength  /**< the pointer to Com_TxSduLength */
#define Com_GetTxSigInfoOfPCConfig()                                                                Com_TxSigInfo  /**< the pointer to Com_TxSigInfo */
/** 
  \}
*/ 

/** 
  \defgroup  ComPCGetDuplicatedRootDataMacros  Com Get Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated root data elements.
  \{
*/ 
#define Com_GetSizeOfCurrentTxModeOfPCConfig()                                                      Com_GetSizeOfTxPduInfoOfPCConfig()  /**< the number of accomplishable value elements in Com_CurrentTxMode */
#define Com_GetSizeOfCycleTimeCntOfPCConfig()                                                       Com_GetSizeOfTxPduInfoOfPCConfig()  /**< the number of accomplishable value elements in Com_CycleTimeCnt */
#define Com_GetSizeOfCyclicSendRequestOfPCConfig()                                                  Com_GetSizeOfTxPduInfoOfPCConfig()  /**< the number of accomplishable value elements in Com_CyclicSendRequest */
#define Com_GetSizeOfIPduGroupStateOfPCConfig()                                                     Com_GetSizeOfIPduGroupInfoOfPCConfig()  /**< the number of accomplishable value elements in Com_IPduGroupState */
#define Com_GetSizeOfRxPduDmStateOfPCConfig()                                                       Com_GetSizeOfRxTOutInfoOfPCConfig()  /**< the number of accomplishable value elements in Com_RxPduDmState */
#define Com_GetSizeOfRxPduGrpActiveOfPCConfig()                                                     Com_GetSizeOfRxPduInfoOfPCConfig()  /**< the number of accomplishable value elements in Com_RxPduGrpActive */
#define Com_GetSizeOfRxTOutCntOfPCConfig()                                                          Com_GetSizeOfRxTOutInfoOfPCConfig()  /**< the number of accomplishable value elements in Com_RxTOutCnt */
#define Com_GetSizeOfTransmitRequestOfPCConfig()                                                    Com_GetSizeOfTxPduInfoOfPCConfig()  /**< the number of accomplishable value elements in Com_TransmitRequest */
#define Com_GetSizeOfTxPduGrpActiveOfPCConfig()                                                     Com_GetSizeOfTxPduInfoOfPCConfig()  /**< the number of accomplishable value elements in Com_TxPduGrpActive */
#define Com_GetSizeOfTxSduLengthOfPCConfig()                                                        Com_GetSizeOfTxPduInfoOfPCConfig()  /**< the number of accomplishable value elements in Com_TxSduLength */
/** 
  \}
*/ 

/** 
  \defgroup  ComPCGetDataMacros  Com Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define Com_GetCbkRxTOutFuncPtr(Index)                                                              (Com_GetCbkRxTOutFuncPtrOfPCConfig()[(Index)])
#define Com_GetConstValueUInt16(Index)                                                              (Com_GetConstValueUInt16OfPCConfig()[(Index)])
#define Com_GetConstValueUInt32(Index)                                                              (Com_GetConstValueUInt32OfPCConfig()[(Index)])
#define Com_GetConstValueUInt8(Index)                                                               (Com_GetConstValueUInt8OfPCConfig()[(Index)])
#define Com_IsCurrentTxMode(Index)                                                                  ((Com_GetCurrentTxModeOfPCConfig()[(Index)]) != FALSE)
#define Com_GetCycleTimeCnt(Index)                                                                  (Com_GetCycleTimeCntOfPCConfig()[(Index)])
#define Com_IsCyclicSendRequest(Index)                                                              ((Com_GetCyclicSendRequestOfPCConfig()[(Index)]) != FALSE)
#define Com_GetHandleRxPduDeferred(Index)                                                           (Com_GetHandleRxPduDeferredOfPCConfig()[(Index)])
#define Com_GetRxPduInfoIndEndIdxOfIPduGroupInfo(Index)                                             (Com_GetIPduGroupInfoOfPCConfig()[(Index)].RxPduInfoIndEndIdxOfIPduGroupInfo)
#define Com_GetRxPduInfoIndStartIdxOfIPduGroupInfo(Index)                                           (Com_GetIPduGroupInfoOfPCConfig()[(Index)].RxPduInfoIndStartIdxOfIPduGroupInfo)
#define Com_GetTxPduInfoIndEndIdxOfIPduGroupInfo(Index)                                             (Com_GetIPduGroupInfoOfPCConfig()[(Index)].TxPduInfoIndEndIdxOfIPduGroupInfo)
#define Com_GetTxPduInfoIndStartIdxOfIPduGroupInfo(Index)                                           (Com_GetIPduGroupInfoOfPCConfig()[(Index)].TxPduInfoIndStartIdxOfIPduGroupInfo)
#define Com_IsTxPduInfoIndUsedOfIPduGroupInfo(Index)                                                ((Com_GetIPduGroupInfoOfPCConfig()[(Index)].TxPduInfoIndUsedOfIPduGroupInfo) != FALSE)
#define Com_GetIPduGroupInfoOfRxPduInfoInd(Index)                                                   (Com_GetIPduGroupInfoOfRxPduInfoIndOfPCConfig()[(Index)])
#define Com_GetIPduGroupState(Index)                                                                (Com_GetIPduGroupStateOfPCConfig()[(Index)])
#define Com_IsInitialized()                                                                         (((*(Com_GetInitializedOfPCConfig()))) != FALSE)
#define Com_GetApplTypeOfRxAccessInfo(Index)                                                        (Com_GetRxAccessInfoOfPCConfig()[(Index)].ApplTypeOfRxAccessInfo)
#define Com_GetBitLengthOfRxAccessInfo(Index)                                                       (Com_GetRxAccessInfoOfPCConfig()[(Index)].BitLengthOfRxAccessInfo)
#define Com_GetBitPositionOfRxAccessInfo(Index)                                                     (Com_GetRxAccessInfoOfPCConfig()[(Index)].BitPositionOfRxAccessInfo)
#define Com_GetBufferIdxOfRxAccessInfo(Index)                                                       (Com_GetRxAccessInfoOfPCConfig()[(Index)].BufferIdxOfRxAccessInfo)
#define Com_GetBusAccOfRxAccessInfo(Index)                                                          (Com_GetRxAccessInfoOfPCConfig()[(Index)].BusAccOfRxAccessInfo)
#define Com_GetByteLengthOfRxAccessInfo(Index)                                                      (Com_GetRxAccessInfoOfPCConfig()[(Index)].ByteLengthOfRxAccessInfo)
#define Com_GetBytePositionOfRxAccessInfo(Index)                                                    (Com_GetRxAccessInfoOfPCConfig()[(Index)].BytePositionOfRxAccessInfo)
#define Com_GetInitValueIdxOfRxAccessInfo(Index)                                                    (Com_GetRxAccessInfoOfPCConfig()[(Index)].InitValueIdxOfRxAccessInfo)
#define Com_IsInitValueUsedOfRxAccessInfo(Index)                                                    ((Com_GetRxAccessInfoOfPCConfig()[(Index)].InitValueUsedOfRxAccessInfo) != FALSE)
#define Com_GetRxPduInfoIdxOfRxAccessInfo(Index)                                                    (Com_GetRxAccessInfoOfPCConfig()[(Index)].RxPduInfoIdxOfRxAccessInfo)
#define Com_GetRxTOutInfoIdxOfRxAccessInfo(Index)                                                   (Com_GetRxAccessInfoOfPCConfig()[(Index)].RxTOutInfoIdxOfRxAccessInfo)
#define Com_GetStartByteInPduPositionOfRxAccessInfo(Index)                                          (Com_GetRxAccessInfoOfPCConfig()[(Index)].StartByteInPduPositionOfRxAccessInfo)
#define Com_GetRxAccessInfoInd(Index)                                                               (Com_GetRxAccessInfoIndOfPCConfig()[(Index)])
#define Com_GetRxCbkFuncPtr(Index)                                                                  (Com_GetRxCbkFuncPtrOfPCConfig()[(Index)])
#define Com_GetRxDeadlineMonitoringISRLockCounter()                                                 ((*(Com_GetRxDeadlineMonitoringISRLockCounterOfPCConfig())))
#define Com_GetRxDefPduBuffer(Index)                                                                (Com_GetRxDefPduBufferOfPCConfig()[(Index)])
#define Com_GetRxDeferredFctPtrCache(Index)                                                         (Com_GetRxDeferredFctPtrCacheOfPCConfig()[(Index)])
#define Com_GetRxDeferredProcessingISRLockCounter()                                                 ((*(Com_GetRxDeferredProcessingISRLockCounterOfPCConfig())))
#define Com_GetRxDlMonDivisorCounter()                                                              ((*(Com_GetRxDlMonDivisorCounterOfPCConfig())))
#define Com_GetRxIPduGroupISRLockCounter()                                                          ((*(Com_GetRxIPduGroupISRLockCounterOfPCConfig())))
#define Com_GetRxPduDmState(Index)                                                                  (Com_GetRxPduDmStateOfPCConfig()[(Index)])
#define Com_IsRxPduGrpActive(Index)                                                                 ((Com_GetRxPduGrpActiveOfPCConfig()[(Index)]) != FALSE)
#define Com_IsIPduGroupInfoOfRxPduInfoIndUsedOfRxPduInfo(Index)                                     ((Com_GetRxPduInfoOfPCConfig()[(Index)].IPduGroupInfoOfRxPduInfoIndUsedOfRxPduInfo) != FALSE)
#define Com_GetRxDefPduBufferStartIdxOfRxPduInfo(Index)                                             (Com_GetRxPduInfoOfPCConfig()[(Index)].RxDefPduBufferStartIdxOfRxPduInfo)
#define Com_GetRxSigInfoEndIdxOfRxPduInfo(Index)                                                    (Com_GetRxPduInfoOfPCConfig()[(Index)].RxSigInfoEndIdxOfRxPduInfo)
#define Com_GetRxSigInfoStartIdxOfRxPduInfo(Index)                                                  (Com_GetRxPduInfoOfPCConfig()[(Index)].RxSigInfoStartIdxOfRxPduInfo)
#define Com_GetRxTOutInfoIndEndIdxOfRxPduInfo(Index)                                                (Com_GetRxPduInfoOfPCConfig()[(Index)].RxTOutInfoIndEndIdxOfRxPduInfo)
#define Com_GetRxTOutInfoIndStartIdxOfRxPduInfo(Index)                                              (Com_GetRxPduInfoOfPCConfig()[(Index)].RxTOutInfoIndStartIdxOfRxPduInfo)
#define Com_IsRxTOutInfoUsedOfRxPduInfo(Index)                                                      ((Com_GetRxPduInfoOfPCConfig()[(Index)].RxTOutInfoUsedOfRxPduInfo) != FALSE)
#define Com_GetTypeOfRxPduInfo(Index)                                                               (Com_GetRxPduInfoOfPCConfig()[(Index)].TypeOfRxPduInfo)
#define Com_GetRxSigBufferUInt16(Index)                                                             (Com_GetRxSigBufferUInt16OfPCConfig()[(Index)])
#define Com_GetRxSigBufferUInt32(Index)                                                             (Com_GetRxSigBufferUInt32OfPCConfig()[(Index)])
#define Com_GetRxSigBufferUInt8(Index)                                                              (Com_GetRxSigBufferUInt8OfPCConfig()[(Index)])
#define Com_GetRxAccessInfoIdxOfRxSigInfo(Index)                                                    (Com_GetRxSigInfoOfPCConfig()[(Index)].RxAccessInfoIdxOfRxSigInfo)
#define Com_GetRxTOutInfoIdxOfRxSigInfo(Index)                                                      (Com_GetRxSigInfoOfPCConfig()[(Index)].RxTOutInfoIdxOfRxSigInfo)
#define Com_GetSignalProcessingOfRxSigInfo(Index)                                                   (Com_GetRxSigInfoOfPCConfig()[(Index)].SignalProcessingOfRxSigInfo)
#define Com_GetValidDlcOfRxSigInfo(Index)                                                           (Com_GetRxSigInfoOfPCConfig()[(Index)].ValidDlcOfRxSigInfo)
#define Com_GetRxTOutCnt(Index)                                                                     (Com_GetRxTOutCntOfPCConfig()[(Index)])
#define Com_GetCbkRxTOutFuncPtrIndEndIdxOfRxTOutInfo(Index)                                         (Com_GetRxTOutInfoOfPCConfig()[(Index)].CbkRxTOutFuncPtrIndEndIdxOfRxTOutInfo)
#define Com_GetCbkRxTOutFuncPtrIndStartIdxOfRxTOutInfo(Index)                                       (Com_GetRxTOutInfoOfPCConfig()[(Index)].CbkRxTOutFuncPtrIndStartIdxOfRxTOutInfo)
#define Com_GetFactorOfRxTOutInfo(Index)                                                            (Com_GetRxTOutInfoOfPCConfig()[(Index)].FactorOfRxTOutInfo)
#define Com_GetFirstFactorOfRxTOutInfo(Index)                                                       (Com_GetRxTOutInfoOfPCConfig()[(Index)].FirstFactorOfRxTOutInfo)
#define Com_GetRxPduInfoIdxOfRxTOutInfo(Index)                                                      (Com_GetRxTOutInfoOfPCConfig()[(Index)].RxPduInfoIdxOfRxTOutInfo)
#define Com_IsTransmitRequest(Index)                                                                ((Com_GetTransmitRequestOfPCConfig()[(Index)]) != FALSE)
#define Com_GetTxBuffer(Index)                                                                      (Com_GetTxBufferOfPCConfig()[(Index)])
#define Com_GetTxCycleCounterDivisorCounter()                                                       ((*(Com_GetTxCycleCounterDivisorCounterOfPCConfig())))
#define Com_GetTxCyclicProcessingISRLockCounter()                                                   ((*(Com_GetTxCyclicProcessingISRLockCounterOfPCConfig())))
#define Com_GetTxIPduGroupISRLockCounter()                                                          ((*(Com_GetTxIPduGroupISRLockCounterOfPCConfig())))
#define Com_IsPeriodicOfTxModeFalse(Index)                                                          ((Com_GetTxModeFalseOfPCConfig()[(Index)].PeriodicOfTxModeFalse) != FALSE)
#define Com_IsInitModeOfTxModeInfo(Index)                                                           ((Com_GetTxModeInfoOfPCConfig()[(Index)].InitModeOfTxModeInfo) != FALSE)
#define Com_IsPeriodicOfTxModeTrue(Index)                                                           ((Com_GetTxModeTrueOfPCConfig()[(Index)].PeriodicOfTxModeTrue) != FALSE)
#define Com_IsTxPduGrpActive(Index)                                                                 ((Com_GetTxPduGrpActiveOfPCConfig()[(Index)]) != FALSE)
#define Com_GetExternalIdOfTxPduInfo(Index)                                                         (Com_GetTxPduInfoOfPCConfig()[(Index)].ExternalIdOfTxPduInfo)
#define Com_GetIPduGroupInfoOfTxPduInfoIndEndIdxOfTxPduInfo(Index)                                  (Com_GetTxPduInfoOfPCConfig()[(Index)].IPduGroupInfoOfTxPduInfoIndEndIdxOfTxPduInfo)
#define Com_GetIPduGroupInfoOfTxPduInfoIndStartIdxOfTxPduInfo(Index)                                (Com_GetTxPduInfoOfPCConfig()[(Index)].IPduGroupInfoOfTxPduInfoIndStartIdxOfTxPduInfo)
#define Com_GetMetaDataLengthOfTxPduInfo(Index)                                                     (Com_GetTxPduInfoOfPCConfig()[(Index)].MetaDataLengthOfTxPduInfo)
#define Com_GetTxBufferLengthOfTxPduInfo(Index)                                                     (Com_GetTxPduInfoOfPCConfig()[(Index)].TxBufferLengthOfTxPduInfo)
#define Com_GetTxPduInitValueEndIdxOfTxPduInfo(Index)                                               (Com_GetTxPduInfoOfPCConfig()[(Index)].TxPduInitValueEndIdxOfTxPduInfo)
#define Com_GetTxPduInitValueStartIdxOfTxPduInfo(Index)                                             (Com_GetTxPduInfoOfPCConfig()[(Index)].TxPduInitValueStartIdxOfTxPduInfo)
#define Com_IsTxPduInitValueUsedOfTxPduInfo(Index)                                                  ((Com_GetTxPduInfoOfPCConfig()[(Index)].TxPduInitValueUsedOfTxPduInfo) != FALSE)
#define Com_GetTxPduInitValue(Index)                                                                (Com_GetTxPduInitValueOfPCConfig()[(Index)])
#define Com_GetTxProcessingISRLockCounter()                                                         ((*(Com_GetTxProcessingISRLockCounterOfPCConfig())))
#define Com_GetTxSduLength(Index)                                                                   (Com_GetTxSduLengthOfPCConfig()[(Index)])
#define Com_GetBitLengthOfTxSigInfo(Index)                                                          (Com_GetTxSigInfoOfPCConfig()[(Index)].BitLengthOfTxSigInfo)
#define Com_GetBitPositionOfTxSigInfo(Index)                                                        (Com_GetTxSigInfoOfPCConfig()[(Index)].BitPositionOfTxSigInfo)
#define Com_GetBusAccOfTxSigInfo(Index)                                                             (Com_GetTxSigInfoOfPCConfig()[(Index)].BusAccOfTxSigInfo)
#define Com_GetStartByteInPduPositionOfTxSigInfo(Index)                                             (Com_GetTxSigInfoOfPCConfig()[(Index)].StartByteInPduPositionOfTxSigInfo)
#define Com_GetTxBufferLengthOfTxSigInfo(Index)                                                     (Com_GetTxSigInfoOfPCConfig()[(Index)].TxBufferLengthOfTxSigInfo)
#define Com_GetTxBufferStartIdxOfTxSigInfo(Index)                                                   (Com_GetTxSigInfoOfPCConfig()[(Index)].TxBufferStartIdxOfTxSigInfo)
#define Com_GetTxPduInfoIdxOfTxSigInfo(Index)                                                       (Com_GetTxSigInfoOfPCConfig()[(Index)].TxPduInfoIdxOfTxSigInfo)
/** 
  \}
*/ 

/** 
  \defgroup  ComPCGetDeduplicatedDataMacros  Com Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define Com_GetTxPduInfoIdxOfAlwaysActiveTxComIPdus(Index)                                          ((Com_TxPduInfoIdxOfAlwaysActiveTxComIPdusType)((Index)))  /**< the index of the 1:1 relation pointing to Com_TxPduInfo */
#define Com_GetCbkRxTOutFuncPtrInd(Index)                                                           ((Com_CbkRxTOutFuncPtrIndType)((Index)))  /**< the indexes of the 1:1 sorted relation pointing to Com_CbkRxTOutFuncPtr */
#define Com_GetConfigId()                                                                           Com_GetConfigIdOfPCConfig()
#define Com_GetIPduGroupInfoToSubIPduGroupsIndEndIdxOfIPduGroupInfo(Index)                          ((Com_IPduGroupInfoToSubIPduGroupsIndEndIdxOfIPduGroupInfoType)((((Com_IPduGroupInfoToSubIPduGroupsIndEndIdxOfIPduGroupInfoType)(Index)) + 1u)))  /**< the end index of the 0:n relation pointing to Com_IPduGroupInfoToSubIPduGroupsInd */
#define Com_GetIPduGroupInfoToSubIPduGroupsIndStartIdxOfIPduGroupInfo(Index)                        ((Com_IPduGroupInfoToSubIPduGroupsIndStartIdxOfIPduGroupInfoType)((Index)))  /**< the start index of the 0:n relation pointing to Com_IPduGroupInfoToSubIPduGroupsInd */
#define Com_IsIPduGroupInfoToSubIPduGroupsIndUsedOfIPduGroupInfo(Index)                             (((boolean)(Com_GetIPduGroupInfoToSubIPduGroupsIndStartIdxOfIPduGroupInfo(Index) != COM_NO_IPDUGROUPINFOTOSUBIPDUGROUPSINDSTARTIDXOFIPDUGROUPINFO)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_IPduGroupInfoToSubIPduGroupsInd */
#define Com_IsRxPduInfoIndUsedOfIPduGroupInfo(Index)                                                (((!(Com_IsTxPduInfoIndUsedOfIPduGroupInfo(Index)))) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_RxPduInfoInd */
#define Com_GetIPduGroupInfoOfTxPduInfoInd(Index)                                                   ((Com_IPduGroupInfoOfTxPduInfoIndType)((((Com_IPduGroupInfoOfTxPduInfoIndType)(Index)) + 1u)))  /**< the indexes of the 1:1 sorted relation pointing to Com_IPduGroupInfo */
#define Com_GetIPduGroupInfoToSubIPduGroupsInd(Index)                                               ((Com_IPduGroupInfoToSubIPduGroupsIndType)((Index)))  /**< the indexes of the 1:1 sorted relation pointing to Com_IPduGroupInfo */
#define Com_GetPduGrpCnt()                                                                          Com_GetPduGrpCntOfPCConfig()
#define Com_IsBufferUsedOfRxAccessInfo(Index)                                                       Com_IsInitValueUsedOfRxAccessInfo(Index)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_RxSigBufferUInt8,Com_RxSigBufferUInt16,Com_RxSigBufferUInt32,Com_RxSigBufferUInt64,Com_RxSigBufferZeroBit,Com_RxSigBufferSInt8,Com_RxSigBufferSInt16,Com_RxSigBufferSInt32,Com_RxSigBufferSInt64,Com_RxSigBufferFloat32,Com_RxSigBufferFloat64 */
#define Com_IsRxTOutInfoUsedOfRxAccessInfo(Index)                                                   (((boolean)(Com_GetRxTOutInfoIdxOfRxAccessInfo(Index) != COM_NO_RXTOUTINFOIDXOFRXACCESSINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_RxTOutInfo */
#define Com_GetRxDeadlineMonitoringISRLockThreshold()                                               Com_GetRxDeadlineMonitoringISRLockThresholdOfPCConfig()
#define Com_GetRxDeferredProcessingISRLockThreshold()                                               Com_GetRxDeferredProcessingISRLockThresholdOfPCConfig()
#define Com_GetRxDlMonDivisor()                                                                     Com_GetRxDlMonDivisorOfPCConfig()
#define Com_GetRxIPduGroupISRLockThreshold()                                                        Com_GetRxIPduGroupISRLockThresholdOfPCConfig()
#define Com_GetHandleRxPduDeferredIdxOfRxPduInfo(Index)                                             ((Com_HandleRxPduDeferredIdxOfRxPduInfoType)((Index)))  /**< the index of the 0:1 relation pointing to Com_HandleRxPduDeferred */
#define Com_IsHandleRxPduDeferredUsedOfRxPduInfo(Index)                                             Com_IsIPduGroupInfoOfRxPduInfoIndUsedOfRxPduInfo(Index)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_HandleRxPduDeferred */
#define Com_GetIPduGroupInfoOfRxPduInfoIndEndIdxOfRxPduInfo(Index)                                  ((Com_IPduGroupInfoOfRxPduInfoIndEndIdxOfRxPduInfoType)((((Com_IPduGroupInfoOfRxPduInfoIndEndIdxOfRxPduInfoType)(Index)) + 1u)))  /**< the end index of the 0:n relation pointing to Com_IPduGroupInfoOfRxPduInfoInd */
#define Com_GetIPduGroupInfoOfRxPduInfoIndStartIdxOfRxPduInfo(Index)                                ((Com_IPduGroupInfoOfRxPduInfoIndStartIdxOfRxPduInfoType)((Index)))  /**< the start index of the 0:n relation pointing to Com_IPduGroupInfoOfRxPduInfoInd */
#define Com_GetRxAccessInfoIndEndIdxOfRxPduInfo(Index)                                              Com_GetRxSigInfoEndIdxOfRxPduInfo(Index)  /**< the end index of the 0:n relation pointing to Com_RxAccessInfoInd */
#define Com_GetRxAccessInfoIndStartIdxOfRxPduInfo(Index)                                            Com_GetRxSigInfoStartIdxOfRxPduInfo(Index)  /**< the start index of the 0:n relation pointing to Com_RxAccessInfoInd */
#define Com_IsRxAccessInfoIndUsedOfRxPduInfo(Index)                                                 Com_IsIPduGroupInfoOfRxPduInfoIndUsedOfRxPduInfo(Index)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_RxAccessInfoInd */
#define Com_GetRxDefPduBufferEndIdxOfRxPduInfo(Index)                                               ((Com_RxDefPduBufferEndIdxOfRxPduInfoType)((Com_GetRxDefPduBufferStartIdxOfRxPduInfo(Index) + 8u)))  /**< the end index of the 0:n relation pointing to Com_RxDefPduBuffer */
#define Com_GetRxDefPduBufferLengthOfRxPduInfo(Index)                                               ((Com_RxDefPduBufferLengthOfRxPduInfoType)((Com_GetTypeOfRxPduInfo(Index) + 0x08u)))  /**< the number of relations pointing to Com_RxDefPduBuffer */
#define Com_IsRxDefPduBufferUsedOfRxPduInfo(Index)                                                  Com_IsIPduGroupInfoOfRxPduInfoIndUsedOfRxPduInfo(Index)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_RxDefPduBuffer */
#define Com_IsRxSigInfoUsedOfRxPduInfo(Index)                                                       Com_IsIPduGroupInfoOfRxPduInfoIndUsedOfRxPduInfo(Index)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_RxSigInfo */
#define Com_GetRxTOutInfoIdxOfRxPduInfo(Index)                                                      Com_GetRxTOutInfoIndStartIdxOfRxPduInfo(Index)  /**< the index of the 0:1 relation pointing to Com_RxTOutInfo */
#define Com_IsRxTOutInfoIndUsedOfRxPduInfo(Index)                                                   Com_IsRxTOutInfoUsedOfRxPduInfo(Index)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_RxTOutInfoInd */
#define Com_GetSignalProcessingOfRxPduInfo(Index)                                                   Com_GetTypeOfRxPduInfo(Index)  /**< Defines whether rx Pdu is processed in DEFERRED or IMMEDIATE fashion. */
#define Com_GetRxPduInfoInd(Index)                                                                  ((Com_RxPduInfoIndType)((Index)))  /**< the indexes of the 1:1 sorted relation pointing to Com_RxPduInfo */
#define Com_GetRxCbkFuncPtrAckIdxOfRxSigInfo(Index)                                                 ((Com_RxCbkFuncPtrAckIdxOfRxSigInfoType)((Index)))  /**< the index of the 0:1 relation pointing to Com_RxCbkFuncPtr */
#define Com_IsRxCbkFuncPtrAckUsedOfRxSigInfo(Index)                                                 (((boolean)(Com_GetRxCbkFuncPtrAckIdxOfRxSigInfo(Index) != COM_NO_RXCBKFUNCPTRACKIDXOFRXSIGINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_RxCbkFuncPtr */
#define Com_IsRxTOutInfoUsedOfRxSigInfo(Index)                                                      (((boolean)(Com_GetRxTOutInfoIdxOfRxSigInfo(Index) != COM_NO_RXTOUTINFOIDXOFRXSIGINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_RxTOutInfo */
#define Com_IsCbkRxTOutFuncPtrIndUsedOfRxTOutInfo(Index)                                            (((boolean)(Com_GetCbkRxTOutFuncPtrIndStartIdxOfRxTOutInfo(Index) != COM_NO_CBKRXTOUTFUNCPTRINDSTARTIDXOFRXTOUTINFO)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_CbkRxTOutFuncPtrInd */
#define Com_GetRxTOutInfoInd(Index)                                                                 ((Com_RxTOutInfoIndType)((Index)))  /**< the indexes of the 1:1 sorted relation pointing to Com_RxTOutInfo */
#define Com_GetSizeOfAlwaysActiveTxComIPdus()                                                       Com_GetSizeOfAlwaysActiveTxComIPdusOfPCConfig()
#define Com_GetSizeOfCbkRxTOutFuncPtr()                                                             Com_GetSizeOfCbkRxTOutFuncPtrOfPCConfig()
#define Com_GetSizeOfCbkRxTOutFuncPtrInd()                                                          Com_GetSizeOfCbkRxTOutFuncPtrIndOfPCConfig()
#define Com_GetSizeOfConstValueUInt16()                                                             Com_GetSizeOfConstValueUInt16OfPCConfig()
#define Com_GetSizeOfConstValueUInt32()                                                             Com_GetSizeOfConstValueUInt32OfPCConfig()
#define Com_GetSizeOfConstValueUInt8()                                                              Com_GetSizeOfConstValueUInt8OfPCConfig()
#define Com_GetSizeOfCurrentTxMode()                                                                Com_GetSizeOfCurrentTxModeOfPCConfig()
#define Com_GetSizeOfCycleTimeCnt()                                                                 Com_GetSizeOfCycleTimeCntOfPCConfig()
#define Com_GetSizeOfCyclicSendRequest()                                                            Com_GetSizeOfCyclicSendRequestOfPCConfig()
#define Com_GetSizeOfHandleRxPduDeferred()                                                          Com_GetSizeOfHandleRxPduDeferredOfPCConfig()
#define Com_GetSizeOfIPduGroupInfo()                                                                Com_GetSizeOfIPduGroupInfoOfPCConfig()
#define Com_GetSizeOfIPduGroupInfoOfRxPduInfoInd()                                                  Com_GetSizeOfIPduGroupInfoOfRxPduInfoIndOfPCConfig()
#define Com_GetSizeOfIPduGroupInfoOfTxPduInfoInd()                                                  Com_GetSizeOfIPduGroupInfoOfTxPduInfoIndOfPCConfig()
#define Com_GetSizeOfIPduGroupInfoToSubIPduGroupsInd()                                              Com_GetSizeOfIPduGroupInfoToSubIPduGroupsIndOfPCConfig()
#define Com_GetSizeOfIPduGroupState()                                                               Com_GetSizeOfIPduGroupStateOfPCConfig()
#define Com_GetSizeOfRxAccessInfo()                                                                 Com_GetSizeOfRxAccessInfoOfPCConfig()
#define Com_GetSizeOfRxAccessInfoInd()                                                              Com_GetSizeOfRxAccessInfoIndOfPCConfig()
#define Com_GetSizeOfRxCbkFuncPtr()                                                                 Com_GetSizeOfRxCbkFuncPtrOfPCConfig()
#define Com_GetSizeOfRxDefPduBuffer()                                                               Com_GetSizeOfRxDefPduBufferOfPCConfig()
#define Com_GetSizeOfRxDeferredFctPtrCache()                                                        Com_GetSizeOfRxDeferredFctPtrCacheOfPCConfig()
#define Com_GetSizeOfRxPduDmState()                                                                 Com_GetSizeOfRxPduDmStateOfPCConfig()
#define Com_GetSizeOfRxPduGrpActive()                                                               Com_GetSizeOfRxPduGrpActiveOfPCConfig()
#define Com_GetSizeOfRxPduInfo()                                                                    Com_GetSizeOfRxPduInfoOfPCConfig()
#define Com_GetSizeOfRxPduInfoInd()                                                                 Com_GetSizeOfRxPduInfoIndOfPCConfig()
#define Com_GetSizeOfRxSigBufferUInt16()                                                            Com_GetSizeOfRxSigBufferUInt16OfPCConfig()
#define Com_GetSizeOfRxSigBufferUInt32()                                                            Com_GetSizeOfRxSigBufferUInt32OfPCConfig()
#define Com_GetSizeOfRxSigBufferUInt8()                                                             Com_GetSizeOfRxSigBufferUInt8OfPCConfig()
#define Com_GetSizeOfRxSigInfo()                                                                    Com_GetSizeOfRxSigInfoOfPCConfig()
#define Com_GetSizeOfRxTOutCnt()                                                                    Com_GetSizeOfRxTOutCntOfPCConfig()
#define Com_GetSizeOfRxTOutInfo()                                                                   Com_GetSizeOfRxTOutInfoOfPCConfig()
#define Com_GetSizeOfRxTOutInfoInd()                                                                Com_GetSizeOfRxTOutInfoIndOfPCConfig()
#define Com_GetSizeOfTransmitRequest()                                                              Com_GetSizeOfTransmitRequestOfPCConfig()
#define Com_GetSizeOfTxBuffer()                                                                     Com_GetSizeOfTxBufferOfPCConfig()
#define Com_GetSizeOfTxCyclicPdu()                                                                  Com_GetSizeOfTxCyclicPduOfPCConfig()
#define Com_GetSizeOfTxModeFalse()                                                                  Com_GetSizeOfTxModeFalseOfPCConfig()
#define Com_GetSizeOfTxModeInfo()                                                                   Com_GetSizeOfTxModeInfoOfPCConfig()
#define Com_GetSizeOfTxModeTrue()                                                                   Com_GetSizeOfTxModeTrueOfPCConfig()
#define Com_GetSizeOfTxPduGrpActive()                                                               Com_GetSizeOfTxPduGrpActiveOfPCConfig()
#define Com_GetSizeOfTxPduInfo()                                                                    Com_GetSizeOfTxPduInfoOfPCConfig()
#define Com_GetSizeOfTxPduInfoInd()                                                                 Com_GetSizeOfTxPduInfoIndOfPCConfig()
#define Com_GetSizeOfTxPduInitValue()                                                               Com_GetSizeOfTxPduInitValueOfPCConfig()
#define Com_GetSizeOfTxSduLength()                                                                  Com_GetSizeOfTxSduLengthOfPCConfig()
#define Com_GetSizeOfTxSigInfo()                                                                    Com_GetSizeOfTxSigInfoOfPCConfig()
#define Com_GetTxCycleCounterDivisor()                                                              Com_GetTxCycleCounterDivisorOfPCConfig()
#define Com_GetTxPduInfoIdxOfTxCyclicPdu(Index)                                                     ((Com_TxPduInfoIdxOfTxCyclicPduType)((((Com_TxPduInfoIdxOfTxCyclicPduType)(Index)) + 1u)))  /**< the index of the 1:1 relation pointing to Com_TxPduInfo */
#define Com_GetTxCyclicProcessingISRLockThreshold()                                                 Com_GetTxCyclicProcessingISRLockThresholdOfPCConfig()
#define Com_GetTxIPduGroupISRLockThreshold()                                                        Com_GetTxIPduGroupISRLockThresholdOfPCConfig()
#define Com_GetTimePeriodOfTxModeFalse(Index)                                                       ((Com_TimePeriodOfTxModeFalseType)((Index)))  /**< Cycle time factor. */
#define Com_GetTxModeFalseIdxOfTxModeInfo(Index)                                                    ((Com_TxModeFalseIdxOfTxModeInfoType)((Index)))  /**< the index of the 1:1 relation pointing to Com_TxModeFalse */
#define Com_GetTxModeTrueIdxOfTxModeInfo(Index)                                                     ((Com_TxModeTrueIdxOfTxModeInfoType)((Index)))  /**< the index of the 1:1 relation pointing to Com_TxModeTrue */
#define Com_GetTimePeriodOfTxModeTrue(Index)                                                        ((Com_TimePeriodOfTxModeTrueType)((Index)))  /**< Cycle time factor. */
#define Com_IsIPduGroupInfoOfTxPduInfoIndUsedOfTxPduInfo(Index)                                     (((boolean)(Com_GetIPduGroupInfoOfTxPduInfoIndStartIdxOfTxPduInfo(Index) != COM_NO_IPDUGROUPINFOOFTXPDUINFOINDSTARTIDXOFTXPDUINFO)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_IPduGroupInfoOfTxPduInfoInd */
#define Com_GetPduWithMetaDataLengthOfTxPduInfo(Index)                                              Com_GetTxBufferLengthOfTxPduInfo(Index)  /**< Length of Pdu with MetaData. */
#define Com_GetTxBufferEndIdxOfTxPduInfo(Index)                                                     Com_GetTxPduInitValueEndIdxOfTxPduInfo(Index)  /**< the end index of the 0:n relation pointing to Com_TxBuffer */
#define Com_GetTxBufferStartIdxOfTxPduInfo(Index)                                                   Com_GetTxPduInitValueStartIdxOfTxPduInfo(Index)  /**< the start index of the 0:n relation pointing to Com_TxBuffer */
#define Com_IsTxBufferUsedOfTxPduInfo(Index)                                                        Com_IsTxPduInitValueUsedOfTxPduInfo(Index)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_TxBuffer */
#define Com_GetTxPduInfoInd(Index)                                                                  ((Com_TxPduInfoIndType)((((Com_TxPduInfoIndType)(Index)) + 1u)))  /**< the indexes of the 1:1 sorted relation pointing to Com_TxPduInfo */
#define Com_GetTxProcessingISRLockThreshold()                                                       Com_GetTxProcessingISRLockThresholdOfPCConfig()
#define Com_GetApplTypeOfTxSigInfo(Index)                                                           Com_GetBusAccOfTxSigInfo(Index)  /**< Application data type. */
#define Com_GetByteLengthOfTxSigInfo(Index)                                                         Com_GetBusAccOfTxSigInfo(Index)  /**< Byte length of the signal or group signal. */
#define Com_GetBytePositionOfTxSigInfo(Index)                                                       Com_GetStartByteInPduPositionOfTxSigInfo(Index)  /**< Little endian byte position of the signal or group signal within the I-PDU. */
#define Com_GetTxBufferEndIdxOfTxSigInfo(Index)                                                     ((Com_TxBufferEndIdxOfTxSigInfoType)((Com_GetTxBufferStartIdxOfTxSigInfo(Index) + 1u)))  /**< the end index of the 0:n relation pointing to Com_TxBuffer */
#define Com_IsTxBufferUsedOfTxSigInfo(Index)                                                        (((boolean)(Com_GetTxBufferLengthOfTxSigInfo(Index) != 0u)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_TxBuffer */
/** 
  \}
*/ 

/** 
  \defgroup  ComPCSetDataMacros  Com Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define Com_SetCurrentTxMode(Index, Value)                                                          Com_GetCurrentTxModeOfPCConfig()[(Index)] = (Value)
#define Com_SetCycleTimeCnt(Index, Value)                                                           Com_GetCycleTimeCntOfPCConfig()[(Index)] = (Value)
#define Com_SetCyclicSendRequest(Index, Value)                                                      Com_GetCyclicSendRequestOfPCConfig()[(Index)] = (Value)
#define Com_SetHandleRxPduDeferred(Index, Value)                                                    Com_GetHandleRxPduDeferredOfPCConfig()[(Index)] = (Value)
#define Com_SetIPduGroupState(Index, Value)                                                         Com_GetIPduGroupStateOfPCConfig()[(Index)] = (Value)
#define Com_SetInitialized(Value)                                                                   (*(Com_GetInitializedOfPCConfig())) = (Value)
#define Com_SetRxDeadlineMonitoringISRLockCounter(Value)                                            (*(Com_GetRxDeadlineMonitoringISRLockCounterOfPCConfig())) = (Value)
#define Com_SetRxDefPduBuffer(Index, Value)                                                         Com_GetRxDefPduBufferOfPCConfig()[(Index)] = (Value)
#define Com_SetRxDeferredFctPtrCache(Index, Value)                                                  Com_GetRxDeferredFctPtrCacheOfPCConfig()[(Index)] = (Value)
#define Com_SetRxDeferredProcessingISRLockCounter(Value)                                            (*(Com_GetRxDeferredProcessingISRLockCounterOfPCConfig())) = (Value)
#define Com_SetRxDlMonDivisorCounter(Value)                                                         (*(Com_GetRxDlMonDivisorCounterOfPCConfig())) = (Value)
#define Com_SetRxIPduGroupISRLockCounter(Value)                                                     (*(Com_GetRxIPduGroupISRLockCounterOfPCConfig())) = (Value)
#define Com_SetRxPduDmState(Index, Value)                                                           Com_GetRxPduDmStateOfPCConfig()[(Index)] = (Value)
#define Com_SetRxPduGrpActive(Index, Value)                                                         Com_GetRxPduGrpActiveOfPCConfig()[(Index)] = (Value)
#define Com_SetRxSigBufferUInt16(Index, Value)                                                      Com_GetRxSigBufferUInt16OfPCConfig()[(Index)] = (Value)
#define Com_SetRxSigBufferUInt32(Index, Value)                                                      Com_GetRxSigBufferUInt32OfPCConfig()[(Index)] = (Value)
#define Com_SetRxSigBufferUInt8(Index, Value)                                                       Com_GetRxSigBufferUInt8OfPCConfig()[(Index)] = (Value)
#define Com_SetRxTOutCnt(Index, Value)                                                              Com_GetRxTOutCntOfPCConfig()[(Index)] = (Value)
#define Com_SetTransmitRequest(Index, Value)                                                        Com_GetTransmitRequestOfPCConfig()[(Index)] = (Value)
#define Com_SetTxBuffer(Index, Value)                                                               Com_GetTxBufferOfPCConfig()[(Index)] = (Value)
#define Com_SetTxCycleCounterDivisorCounter(Value)                                                  (*(Com_GetTxCycleCounterDivisorCounterOfPCConfig())) = (Value)
#define Com_SetTxCyclicProcessingISRLockCounter(Value)                                              (*(Com_GetTxCyclicProcessingISRLockCounterOfPCConfig())) = (Value)
#define Com_SetTxIPduGroupISRLockCounter(Value)                                                     (*(Com_GetTxIPduGroupISRLockCounterOfPCConfig())) = (Value)
#define Com_SetTxPduGrpActive(Index, Value)                                                         Com_GetTxPduGrpActiveOfPCConfig()[(Index)] = (Value)
#define Com_SetTxProcessingISRLockCounter(Value)                                                    (*(Com_GetTxProcessingISRLockCounterOfPCConfig())) = (Value)
#define Com_SetTxSduLength(Index, Value)                                                            Com_GetTxSduLengthOfPCConfig()[(Index)] = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  ComPCGetAddressOfDataMacros  Com Get Address Of Data Macros (PRE_COMPILE)
  \brief  These macros can be used to get the data by the address operator.
  \{
*/ 
#define Com_GetAddrConstValueUInt16(Index)                                                          (&Com_GetConstValueUInt16(Index))
#define Com_GetAddrConstValueUInt32(Index)                                                          (&Com_GetConstValueUInt32(Index))
#define Com_GetAddrConstValueUInt8(Index)                                                           (&Com_GetConstValueUInt8(Index))
#define Com_GetAddrRxDefPduBuffer(Index)                                                            (&Com_GetRxDefPduBuffer(Index))
#define Com_GetAddrRxDeferredFctPtrCache(Index)                                                     (&Com_GetRxDeferredFctPtrCache(Index))
#define Com_GetAddrRxSigBufferUInt16(Index)                                                         (&Com_GetRxSigBufferUInt16(Index))
#define Com_GetAddrRxSigBufferUInt32(Index)                                                         (&Com_GetRxSigBufferUInt32(Index))
#define Com_GetAddrRxSigBufferUInt8(Index)                                                          (&Com_GetRxSigBufferUInt8(Index))
#define Com_GetAddrTxBuffer(Index)                                                                  (&Com_GetTxBuffer(Index))
#define Com_GetAddrTxPduInitValue(Index)                                                            (&Com_GetTxPduInitValue(Index))
/** 
  \}
*/ 

/** 
  \defgroup  ComPCHasMacros  Com Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define Com_HasAlwaysActiveTxComIPdus()                                                             (TRUE != FALSE)
#define Com_HasTxPduInfoIdxOfAlwaysActiveTxComIPdus()                                               (TRUE != FALSE)
#define Com_HasCbkRxTOutFuncPtr()                                                                   (TRUE != FALSE)
#define Com_HasCbkRxTOutFuncPtrInd()                                                                (TRUE != FALSE)
#define Com_HasConfigId()                                                                           (TRUE != FALSE)
#define Com_HasConstValueUInt16()                                                                   (TRUE != FALSE)
#define Com_HasConstValueUInt32()                                                                   (TRUE != FALSE)
#define Com_HasConstValueUInt8()                                                                    (TRUE != FALSE)
#define Com_HasCurrentTxMode()                                                                      (TRUE != FALSE)
#define Com_HasCycleTimeCnt()                                                                       (TRUE != FALSE)
#define Com_HasCyclicSendRequest()                                                                  (TRUE != FALSE)
#define Com_HasHandleRxPduDeferred()                                                                (TRUE != FALSE)
#define Com_HasIPduGroupInfo()                                                                      (TRUE != FALSE)
#define Com_HasIPduGroupInfoToSubIPduGroupsIndEndIdxOfIPduGroupInfo()                               (TRUE != FALSE)
#define Com_HasIPduGroupInfoToSubIPduGroupsIndStartIdxOfIPduGroupInfo()                             (TRUE != FALSE)
#define Com_HasIPduGroupInfoToSubIPduGroupsIndUsedOfIPduGroupInfo()                                 (TRUE != FALSE)
#define Com_HasRxPduInfoIndEndIdxOfIPduGroupInfo()                                                  (TRUE != FALSE)
#define Com_HasRxPduInfoIndStartIdxOfIPduGroupInfo()                                                (TRUE != FALSE)
#define Com_HasRxPduInfoIndUsedOfIPduGroupInfo()                                                    (TRUE != FALSE)
#define Com_HasTxPduInfoIndEndIdxOfIPduGroupInfo()                                                  (TRUE != FALSE)
#define Com_HasTxPduInfoIndStartIdxOfIPduGroupInfo()                                                (TRUE != FALSE)
#define Com_HasTxPduInfoIndUsedOfIPduGroupInfo()                                                    (TRUE != FALSE)
#define Com_HasIPduGroupInfoOfRxPduInfoInd()                                                        (TRUE != FALSE)
#define Com_HasIPduGroupInfoOfTxPduInfoInd()                                                        (TRUE != FALSE)
#define Com_HasIPduGroupInfoToSubIPduGroupsInd()                                                    (TRUE != FALSE)
#define Com_HasIPduGroupState()                                                                     (TRUE != FALSE)
#define Com_HasInitialized()                                                                        (TRUE != FALSE)
#define Com_HasPduGrpCnt()                                                                          (TRUE != FALSE)
#define Com_HasRxAccessInfo()                                                                       (TRUE != FALSE)
#define Com_HasApplTypeOfRxAccessInfo()                                                             (TRUE != FALSE)
#define Com_HasBitLengthOfRxAccessInfo()                                                            (TRUE != FALSE)
#define Com_HasBitPositionOfRxAccessInfo()                                                          (TRUE != FALSE)
#define Com_HasBufferIdxOfRxAccessInfo()                                                            (TRUE != FALSE)
#define Com_HasBufferUsedOfRxAccessInfo()                                                           (TRUE != FALSE)
#define Com_HasBusAccOfRxAccessInfo()                                                               (TRUE != FALSE)
#define Com_HasByteLengthOfRxAccessInfo()                                                           (TRUE != FALSE)
#define Com_HasBytePositionOfRxAccessInfo()                                                         (TRUE != FALSE)
#define Com_HasInitValueIdxOfRxAccessInfo()                                                         (TRUE != FALSE)
#define Com_HasInitValueUsedOfRxAccessInfo()                                                        (TRUE != FALSE)
#define Com_HasRxPduInfoIdxOfRxAccessInfo()                                                         (TRUE != FALSE)
#define Com_HasRxTOutInfoIdxOfRxAccessInfo()                                                        (TRUE != FALSE)
#define Com_HasRxTOutInfoUsedOfRxAccessInfo()                                                       (TRUE != FALSE)
#define Com_HasStartByteInPduPositionOfRxAccessInfo()                                               (TRUE != FALSE)
#define Com_HasRxAccessInfoInd()                                                                    (TRUE != FALSE)
#define Com_HasRxCbkFuncPtr()                                                                       (TRUE != FALSE)
#define Com_HasRxDeadlineMonitoringISRLockCounter()                                                 (TRUE != FALSE)
#define Com_HasRxDeadlineMonitoringISRLockThreshold()                                               (TRUE != FALSE)
#define Com_HasRxDefPduBuffer()                                                                     (TRUE != FALSE)
#define Com_HasRxDeferredFctPtrCache()                                                              (TRUE != FALSE)
#define Com_HasRxDeferredProcessingISRLockCounter()                                                 (TRUE != FALSE)
#define Com_HasRxDeferredProcessingISRLockThreshold()                                               (TRUE != FALSE)
#define Com_HasRxDlMonDivisor()                                                                     (TRUE != FALSE)
#define Com_HasRxDlMonDivisorCounter()                                                              (TRUE != FALSE)
#define Com_HasRxIPduGroupISRLockCounter()                                                          (TRUE != FALSE)
#define Com_HasRxIPduGroupISRLockThreshold()                                                        (TRUE != FALSE)
#define Com_HasRxPduDmState()                                                                       (TRUE != FALSE)
#define Com_HasRxPduGrpActive()                                                                     (TRUE != FALSE)
#define Com_HasRxPduInfo()                                                                          (TRUE != FALSE)
#define Com_HasHandleRxPduDeferredIdxOfRxPduInfo()                                                  (TRUE != FALSE)
#define Com_HasHandleRxPduDeferredUsedOfRxPduInfo()                                                 (TRUE != FALSE)
#define Com_HasIPduGroupInfoOfRxPduInfoIndEndIdxOfRxPduInfo()                                       (TRUE != FALSE)
#define Com_HasIPduGroupInfoOfRxPduInfoIndStartIdxOfRxPduInfo()                                     (TRUE != FALSE)
#define Com_HasIPduGroupInfoOfRxPduInfoIndUsedOfRxPduInfo()                                         (TRUE != FALSE)
#define Com_HasRxAccessInfoIndEndIdxOfRxPduInfo()                                                   (TRUE != FALSE)
#define Com_HasRxAccessInfoIndStartIdxOfRxPduInfo()                                                 (TRUE != FALSE)
#define Com_HasRxAccessInfoIndUsedOfRxPduInfo()                                                     (TRUE != FALSE)
#define Com_HasRxDefPduBufferEndIdxOfRxPduInfo()                                                    (TRUE != FALSE)
#define Com_HasRxDefPduBufferLengthOfRxPduInfo()                                                    (TRUE != FALSE)
#define Com_HasRxDefPduBufferStartIdxOfRxPduInfo()                                                  (TRUE != FALSE)
#define Com_HasRxDefPduBufferUsedOfRxPduInfo()                                                      (TRUE != FALSE)
#define Com_HasRxSigInfoEndIdxOfRxPduInfo()                                                         (TRUE != FALSE)
#define Com_HasRxSigInfoStartIdxOfRxPduInfo()                                                       (TRUE != FALSE)
#define Com_HasRxSigInfoUsedOfRxPduInfo()                                                           (TRUE != FALSE)
#define Com_HasRxTOutInfoIdxOfRxPduInfo()                                                           (TRUE != FALSE)
#define Com_HasRxTOutInfoIndEndIdxOfRxPduInfo()                                                     (TRUE != FALSE)
#define Com_HasRxTOutInfoIndStartIdxOfRxPduInfo()                                                   (TRUE != FALSE)
#define Com_HasRxTOutInfoIndUsedOfRxPduInfo()                                                       (TRUE != FALSE)
#define Com_HasRxTOutInfoUsedOfRxPduInfo()                                                          (TRUE != FALSE)
#define Com_HasSignalProcessingOfRxPduInfo()                                                        (TRUE != FALSE)
#define Com_HasTypeOfRxPduInfo()                                                                    (TRUE != FALSE)
#define Com_HasRxPduInfoInd()                                                                       (TRUE != FALSE)
#define Com_HasRxSigBufferUInt16()                                                                  (TRUE != FALSE)
#define Com_HasRxSigBufferUInt32()                                                                  (TRUE != FALSE)
#define Com_HasRxSigBufferUInt8()                                                                   (TRUE != FALSE)
#define Com_HasRxSigInfo()                                                                          (TRUE != FALSE)
#define Com_HasRxAccessInfoIdxOfRxSigInfo()                                                         (TRUE != FALSE)
#define Com_HasRxCbkFuncPtrAckIdxOfRxSigInfo()                                                      (TRUE != FALSE)
#define Com_HasRxCbkFuncPtrAckUsedOfRxSigInfo()                                                     (TRUE != FALSE)
#define Com_HasRxTOutInfoIdxOfRxSigInfo()                                                           (TRUE != FALSE)
#define Com_HasRxTOutInfoUsedOfRxSigInfo()                                                          (TRUE != FALSE)
#define Com_HasSignalProcessingOfRxSigInfo()                                                        (TRUE != FALSE)
#define Com_HasValidDlcOfRxSigInfo()                                                                (TRUE != FALSE)
#define Com_HasRxTOutCnt()                                                                          (TRUE != FALSE)
#define Com_HasRxTOutInfo()                                                                         (TRUE != FALSE)
#define Com_HasCbkRxTOutFuncPtrIndEndIdxOfRxTOutInfo()                                              (TRUE != FALSE)
#define Com_HasCbkRxTOutFuncPtrIndStartIdxOfRxTOutInfo()                                            (TRUE != FALSE)
#define Com_HasCbkRxTOutFuncPtrIndUsedOfRxTOutInfo()                                                (TRUE != FALSE)
#define Com_HasFactorOfRxTOutInfo()                                                                 (TRUE != FALSE)
#define Com_HasFirstFactorOfRxTOutInfo()                                                            (TRUE != FALSE)
#define Com_HasRxPduInfoIdxOfRxTOutInfo()                                                           (TRUE != FALSE)
#define Com_HasRxTOutInfoInd()                                                                      (TRUE != FALSE)
#define Com_HasSizeOfAlwaysActiveTxComIPdus()                                                       (TRUE != FALSE)
#define Com_HasSizeOfCbkRxTOutFuncPtr()                                                             (TRUE != FALSE)
#define Com_HasSizeOfCbkRxTOutFuncPtrInd()                                                          (TRUE != FALSE)
#define Com_HasSizeOfConstValueUInt16()                                                             (TRUE != FALSE)
#define Com_HasSizeOfConstValueUInt32()                                                             (TRUE != FALSE)
#define Com_HasSizeOfConstValueUInt8()                                                              (TRUE != FALSE)
#define Com_HasSizeOfCurrentTxMode()                                                                (TRUE != FALSE)
#define Com_HasSizeOfCycleTimeCnt()                                                                 (TRUE != FALSE)
#define Com_HasSizeOfCyclicSendRequest()                                                            (TRUE != FALSE)
#define Com_HasSizeOfHandleRxPduDeferred()                                                          (TRUE != FALSE)
#define Com_HasSizeOfIPduGroupInfo()                                                                (TRUE != FALSE)
#define Com_HasSizeOfIPduGroupInfoOfRxPduInfoInd()                                                  (TRUE != FALSE)
#define Com_HasSizeOfIPduGroupInfoOfTxPduInfoInd()                                                  (TRUE != FALSE)
#define Com_HasSizeOfIPduGroupInfoToSubIPduGroupsInd()                                              (TRUE != FALSE)
#define Com_HasSizeOfIPduGroupState()                                                               (TRUE != FALSE)
#define Com_HasSizeOfRxAccessInfo()                                                                 (TRUE != FALSE)
#define Com_HasSizeOfRxAccessInfoInd()                                                              (TRUE != FALSE)
#define Com_HasSizeOfRxCbkFuncPtr()                                                                 (TRUE != FALSE)
#define Com_HasSizeOfRxDefPduBuffer()                                                               (TRUE != FALSE)
#define Com_HasSizeOfRxDeferredFctPtrCache()                                                        (TRUE != FALSE)
#define Com_HasSizeOfRxPduDmState()                                                                 (TRUE != FALSE)
#define Com_HasSizeOfRxPduGrpActive()                                                               (TRUE != FALSE)
#define Com_HasSizeOfRxPduInfo()                                                                    (TRUE != FALSE)
#define Com_HasSizeOfRxPduInfoInd()                                                                 (TRUE != FALSE)
#define Com_HasSizeOfRxSigBufferUInt16()                                                            (TRUE != FALSE)
#define Com_HasSizeOfRxSigBufferUInt32()                                                            (TRUE != FALSE)
#define Com_HasSizeOfRxSigBufferUInt8()                                                             (TRUE != FALSE)
#define Com_HasSizeOfRxSigInfo()                                                                    (TRUE != FALSE)
#define Com_HasSizeOfRxTOutCnt()                                                                    (TRUE != FALSE)
#define Com_HasSizeOfRxTOutInfo()                                                                   (TRUE != FALSE)
#define Com_HasSizeOfRxTOutInfoInd()                                                                (TRUE != FALSE)
#define Com_HasSizeOfTransmitRequest()                                                              (TRUE != FALSE)
#define Com_HasSizeOfTxBuffer()                                                                     (TRUE != FALSE)
#define Com_HasSizeOfTxCyclicPdu()                                                                  (TRUE != FALSE)
#define Com_HasSizeOfTxModeFalse()                                                                  (TRUE != FALSE)
#define Com_HasSizeOfTxModeInfo()                                                                   (TRUE != FALSE)
#define Com_HasSizeOfTxModeTrue()                                                                   (TRUE != FALSE)
#define Com_HasSizeOfTxPduGrpActive()                                                               (TRUE != FALSE)
#define Com_HasSizeOfTxPduInfo()                                                                    (TRUE != FALSE)
#define Com_HasSizeOfTxPduInfoInd()                                                                 (TRUE != FALSE)
#define Com_HasSizeOfTxPduInitValue()                                                               (TRUE != FALSE)
#define Com_HasSizeOfTxSduLength()                                                                  (TRUE != FALSE)
#define Com_HasSizeOfTxSigInfo()                                                                    (TRUE != FALSE)
#define Com_HasTransmitRequest()                                                                    (TRUE != FALSE)
#define Com_HasTxBuffer()                                                                           (TRUE != FALSE)
#define Com_HasTxCycleCounterDivisor()                                                              (TRUE != FALSE)
#define Com_HasTxCycleCounterDivisorCounter()                                                       (TRUE != FALSE)
#define Com_HasTxCyclicPdu()                                                                        (TRUE != FALSE)
#define Com_HasTxPduInfoIdxOfTxCyclicPdu()                                                          (TRUE != FALSE)
#define Com_HasTxCyclicProcessingISRLockCounter()                                                   (TRUE != FALSE)
#define Com_HasTxCyclicProcessingISRLockThreshold()                                                 (TRUE != FALSE)
#define Com_HasTxIPduGroupISRLockCounter()                                                          (TRUE != FALSE)
#define Com_HasTxIPduGroupISRLockThreshold()                                                        (TRUE != FALSE)
#define Com_HasTxModeFalse()                                                                        (TRUE != FALSE)
#define Com_HasPeriodicOfTxModeFalse()                                                              (TRUE != FALSE)
#define Com_HasTimePeriodOfTxModeFalse()                                                            (TRUE != FALSE)
#define Com_HasTxModeInfo()                                                                         (TRUE != FALSE)
#define Com_HasInitModeOfTxModeInfo()                                                               (TRUE != FALSE)
#define Com_HasTxModeFalseIdxOfTxModeInfo()                                                         (TRUE != FALSE)
#define Com_HasTxModeTrueIdxOfTxModeInfo()                                                          (TRUE != FALSE)
#define Com_HasTxModeTrue()                                                                         (TRUE != FALSE)
#define Com_HasPeriodicOfTxModeTrue()                                                               (TRUE != FALSE)
#define Com_HasTimePeriodOfTxModeTrue()                                                             (TRUE != FALSE)
#define Com_HasTxPduGrpActive()                                                                     (TRUE != FALSE)
#define Com_HasTxPduInfo()                                                                          (TRUE != FALSE)
#define Com_HasExternalIdOfTxPduInfo()                                                              (TRUE != FALSE)
#define Com_HasIPduGroupInfoOfTxPduInfoIndEndIdxOfTxPduInfo()                                       (TRUE != FALSE)
#define Com_HasIPduGroupInfoOfTxPduInfoIndStartIdxOfTxPduInfo()                                     (TRUE != FALSE)
#define Com_HasIPduGroupInfoOfTxPduInfoIndUsedOfTxPduInfo()                                         (TRUE != FALSE)
#define Com_HasMetaDataLengthOfTxPduInfo()                                                          (TRUE != FALSE)
#define Com_HasPduWithMetaDataLengthOfTxPduInfo()                                                   (TRUE != FALSE)
#define Com_HasTxBufferEndIdxOfTxPduInfo()                                                          (TRUE != FALSE)
#define Com_HasTxBufferLengthOfTxPduInfo()                                                          (TRUE != FALSE)
#define Com_HasTxBufferStartIdxOfTxPduInfo()                                                        (TRUE != FALSE)
#define Com_HasTxBufferUsedOfTxPduInfo()                                                            (TRUE != FALSE)
#define Com_HasTxPduInitValueEndIdxOfTxPduInfo()                                                    (TRUE != FALSE)
#define Com_HasTxPduInitValueStartIdxOfTxPduInfo()                                                  (TRUE != FALSE)
#define Com_HasTxPduInitValueUsedOfTxPduInfo()                                                      (TRUE != FALSE)
#define Com_HasTxPduInfoInd()                                                                       (TRUE != FALSE)
#define Com_HasTxPduInitValue()                                                                     (TRUE != FALSE)
#define Com_HasTxProcessingISRLockCounter()                                                         (TRUE != FALSE)
#define Com_HasTxProcessingISRLockThreshold()                                                       (TRUE != FALSE)
#define Com_HasTxSduLength()                                                                        (TRUE != FALSE)
#define Com_HasTxSigInfo()                                                                          (TRUE != FALSE)
#define Com_HasApplTypeOfTxSigInfo()                                                                (TRUE != FALSE)
#define Com_HasBitLengthOfTxSigInfo()                                                               (TRUE != FALSE)
#define Com_HasBitPositionOfTxSigInfo()                                                             (TRUE != FALSE)
#define Com_HasBusAccOfTxSigInfo()                                                                  (TRUE != FALSE)
#define Com_HasByteLengthOfTxSigInfo()                                                              (TRUE != FALSE)
#define Com_HasBytePositionOfTxSigInfo()                                                            (TRUE != FALSE)
#define Com_HasStartByteInPduPositionOfTxSigInfo()                                                  (TRUE != FALSE)
#define Com_HasTxBufferEndIdxOfTxSigInfo()                                                          (TRUE != FALSE)
#define Com_HasTxBufferLengthOfTxSigInfo()                                                          (TRUE != FALSE)
#define Com_HasTxBufferStartIdxOfTxSigInfo()                                                        (TRUE != FALSE)
#define Com_HasTxBufferUsedOfTxSigInfo()                                                            (TRUE != FALSE)
#define Com_HasTxPduInfoIdxOfTxSigInfo()                                                            (TRUE != FALSE)
#define Com_HasPCConfig()                                                                           (TRUE != FALSE)
#define Com_HasAlwaysActiveTxComIPdusOfPCConfig()                                                   (TRUE != FALSE)
#define Com_HasCbkRxTOutFuncPtrIndOfPCConfig()                                                      (TRUE != FALSE)
#define Com_HasCbkRxTOutFuncPtrOfPCConfig()                                                         (TRUE != FALSE)
#define Com_HasConfigIdOfPCConfig()                                                                 (TRUE != FALSE)
#define Com_HasConstValueUInt16OfPCConfig()                                                         (TRUE != FALSE)
#define Com_HasConstValueUInt32OfPCConfig()                                                         (TRUE != FALSE)
#define Com_HasConstValueUInt8OfPCConfig()                                                          (TRUE != FALSE)
#define Com_HasCurrentTxModeOfPCConfig()                                                            (TRUE != FALSE)
#define Com_HasCycleTimeCntOfPCConfig()                                                             (TRUE != FALSE)
#define Com_HasCyclicSendRequestOfPCConfig()                                                        (TRUE != FALSE)
#define Com_HasHandleRxPduDeferredOfPCConfig()                                                      (TRUE != FALSE)
#define Com_HasIPduGroupInfoOfPCConfig()                                                            (TRUE != FALSE)
#define Com_HasIPduGroupInfoOfRxPduInfoIndOfPCConfig()                                              (TRUE != FALSE)
#define Com_HasIPduGroupInfoOfTxPduInfoIndOfPCConfig()                                              (TRUE != FALSE)
#define Com_HasIPduGroupInfoToSubIPduGroupsIndOfPCConfig()                                          (TRUE != FALSE)
#define Com_HasIPduGroupStateOfPCConfig()                                                           (TRUE != FALSE)
#define Com_HasInitializedOfPCConfig()                                                              (TRUE != FALSE)
#define Com_HasPduGrpCntOfPCConfig()                                                                (TRUE != FALSE)
#define Com_HasRxAccessInfoIndOfPCConfig()                                                          (TRUE != FALSE)
#define Com_HasRxAccessInfoOfPCConfig()                                                             (TRUE != FALSE)
#define Com_HasRxCbkFuncPtrOfPCConfig()                                                             (TRUE != FALSE)
#define Com_HasRxDeadlineMonitoringISRLockCounterOfPCConfig()                                       (TRUE != FALSE)
#define Com_HasRxDeadlineMonitoringISRLockThresholdOfPCConfig()                                     (TRUE != FALSE)
#define Com_HasRxDefPduBufferOfPCConfig()                                                           (TRUE != FALSE)
#define Com_HasRxDeferredFctPtrCacheOfPCConfig()                                                    (TRUE != FALSE)
#define Com_HasRxDeferredProcessingISRLockCounterOfPCConfig()                                       (TRUE != FALSE)
#define Com_HasRxDeferredProcessingISRLockThresholdOfPCConfig()                                     (TRUE != FALSE)
#define Com_HasRxDlMonDivisorCounterOfPCConfig()                                                    (TRUE != FALSE)
#define Com_HasRxDlMonDivisorOfPCConfig()                                                           (TRUE != FALSE)
#define Com_HasRxIPduGroupISRLockCounterOfPCConfig()                                                (TRUE != FALSE)
#define Com_HasRxIPduGroupISRLockThresholdOfPCConfig()                                              (TRUE != FALSE)
#define Com_HasRxPduDmStateOfPCConfig()                                                             (TRUE != FALSE)
#define Com_HasRxPduGrpActiveOfPCConfig()                                                           (TRUE != FALSE)
#define Com_HasRxPduInfoIndOfPCConfig()                                                             (TRUE != FALSE)
#define Com_HasRxPduInfoOfPCConfig()                                                                (TRUE != FALSE)
#define Com_HasRxSigBufferUInt16OfPCConfig()                                                        (TRUE != FALSE)
#define Com_HasRxSigBufferUInt32OfPCConfig()                                                        (TRUE != FALSE)
#define Com_HasRxSigBufferUInt8OfPCConfig()                                                         (TRUE != FALSE)
#define Com_HasRxSigInfoOfPCConfig()                                                                (TRUE != FALSE)
#define Com_HasRxTOutCntOfPCConfig()                                                                (TRUE != FALSE)
#define Com_HasRxTOutInfoIndOfPCConfig()                                                            (TRUE != FALSE)
#define Com_HasRxTOutInfoOfPCConfig()                                                               (TRUE != FALSE)
#define Com_HasSizeOfAlwaysActiveTxComIPdusOfPCConfig()                                             (TRUE != FALSE)
#define Com_HasSizeOfCbkRxTOutFuncPtrIndOfPCConfig()                                                (TRUE != FALSE)
#define Com_HasSizeOfCbkRxTOutFuncPtrOfPCConfig()                                                   (TRUE != FALSE)
#define Com_HasSizeOfConstValueUInt16OfPCConfig()                                                   (TRUE != FALSE)
#define Com_HasSizeOfConstValueUInt32OfPCConfig()                                                   (TRUE != FALSE)
#define Com_HasSizeOfConstValueUInt8OfPCConfig()                                                    (TRUE != FALSE)
#define Com_HasSizeOfCurrentTxModeOfPCConfig()                                                      (TRUE != FALSE)
#define Com_HasSizeOfCycleTimeCntOfPCConfig()                                                       (TRUE != FALSE)
#define Com_HasSizeOfCyclicSendRequestOfPCConfig()                                                  (TRUE != FALSE)
#define Com_HasSizeOfHandleRxPduDeferredOfPCConfig()                                                (TRUE != FALSE)
#define Com_HasSizeOfIPduGroupInfoOfPCConfig()                                                      (TRUE != FALSE)
#define Com_HasSizeOfIPduGroupInfoOfRxPduInfoIndOfPCConfig()                                        (TRUE != FALSE)
#define Com_HasSizeOfIPduGroupInfoOfTxPduInfoIndOfPCConfig()                                        (TRUE != FALSE)
#define Com_HasSizeOfIPduGroupInfoToSubIPduGroupsIndOfPCConfig()                                    (TRUE != FALSE)
#define Com_HasSizeOfIPduGroupStateOfPCConfig()                                                     (TRUE != FALSE)
#define Com_HasSizeOfRxAccessInfoIndOfPCConfig()                                                    (TRUE != FALSE)
#define Com_HasSizeOfRxAccessInfoOfPCConfig()                                                       (TRUE != FALSE)
#define Com_HasSizeOfRxCbkFuncPtrOfPCConfig()                                                       (TRUE != FALSE)
#define Com_HasSizeOfRxDefPduBufferOfPCConfig()                                                     (TRUE != FALSE)
#define Com_HasSizeOfRxDeferredFctPtrCacheOfPCConfig()                                              (TRUE != FALSE)
#define Com_HasSizeOfRxPduDmStateOfPCConfig()                                                       (TRUE != FALSE)
#define Com_HasSizeOfRxPduGrpActiveOfPCConfig()                                                     (TRUE != FALSE)
#define Com_HasSizeOfRxPduInfoIndOfPCConfig()                                                       (TRUE != FALSE)
#define Com_HasSizeOfRxPduInfoOfPCConfig()                                                          (TRUE != FALSE)
#define Com_HasSizeOfRxSigBufferUInt16OfPCConfig()                                                  (TRUE != FALSE)
#define Com_HasSizeOfRxSigBufferUInt32OfPCConfig()                                                  (TRUE != FALSE)
#define Com_HasSizeOfRxSigBufferUInt8OfPCConfig()                                                   (TRUE != FALSE)
#define Com_HasSizeOfRxSigInfoOfPCConfig()                                                          (TRUE != FALSE)
#define Com_HasSizeOfRxTOutCntOfPCConfig()                                                          (TRUE != FALSE)
#define Com_HasSizeOfRxTOutInfoIndOfPCConfig()                                                      (TRUE != FALSE)
#define Com_HasSizeOfRxTOutInfoOfPCConfig()                                                         (TRUE != FALSE)
#define Com_HasSizeOfTransmitRequestOfPCConfig()                                                    (TRUE != FALSE)
#define Com_HasSizeOfTxBufferOfPCConfig()                                                           (TRUE != FALSE)
#define Com_HasSizeOfTxCyclicPduOfPCConfig()                                                        (TRUE != FALSE)
#define Com_HasSizeOfTxModeFalseOfPCConfig()                                                        (TRUE != FALSE)
#define Com_HasSizeOfTxModeInfoOfPCConfig()                                                         (TRUE != FALSE)
#define Com_HasSizeOfTxModeTrueOfPCConfig()                                                         (TRUE != FALSE)
#define Com_HasSizeOfTxPduGrpActiveOfPCConfig()                                                     (TRUE != FALSE)
#define Com_HasSizeOfTxPduInfoIndOfPCConfig()                                                       (TRUE != FALSE)
#define Com_HasSizeOfTxPduInfoOfPCConfig()                                                          (TRUE != FALSE)
#define Com_HasSizeOfTxPduInitValueOfPCConfig()                                                     (TRUE != FALSE)
#define Com_HasSizeOfTxSduLengthOfPCConfig()                                                        (TRUE != FALSE)
#define Com_HasSizeOfTxSigInfoOfPCConfig()                                                          (TRUE != FALSE)
#define Com_HasTransmitRequestOfPCConfig()                                                          (TRUE != FALSE)
#define Com_HasTxBufferOfPCConfig()                                                                 (TRUE != FALSE)
#define Com_HasTxCycleCounterDivisorCounterOfPCConfig()                                             (TRUE != FALSE)
#define Com_HasTxCycleCounterDivisorOfPCConfig()                                                    (TRUE != FALSE)
#define Com_HasTxCyclicPduOfPCConfig()                                                              (TRUE != FALSE)
#define Com_HasTxCyclicProcessingISRLockCounterOfPCConfig()                                         (TRUE != FALSE)
#define Com_HasTxCyclicProcessingISRLockThresholdOfPCConfig()                                       (TRUE != FALSE)
#define Com_HasTxIPduGroupISRLockCounterOfPCConfig()                                                (TRUE != FALSE)
#define Com_HasTxIPduGroupISRLockThresholdOfPCConfig()                                              (TRUE != FALSE)
#define Com_HasTxModeFalseOfPCConfig()                                                              (TRUE != FALSE)
#define Com_HasTxModeInfoOfPCConfig()                                                               (TRUE != FALSE)
#define Com_HasTxModeTrueOfPCConfig()                                                               (TRUE != FALSE)
#define Com_HasTxPduGrpActiveOfPCConfig()                                                           (TRUE != FALSE)
#define Com_HasTxPduInfoIndOfPCConfig()                                                             (TRUE != FALSE)
#define Com_HasTxPduInfoOfPCConfig()                                                                (TRUE != FALSE)
#define Com_HasTxPduInitValueOfPCConfig()                                                           (TRUE != FALSE)
#define Com_HasTxProcessingISRLockCounterOfPCConfig()                                               (TRUE != FALSE)
#define Com_HasTxProcessingISRLockThresholdOfPCConfig()                                             (TRUE != FALSE)
#define Com_HasTxSduLengthOfPCConfig()                                                              (TRUE != FALSE)
#define Com_HasTxSigInfoOfPCConfig()                                                                (TRUE != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  ComPCIncrementDataMacros  Com Increment Data Macros (PRE_COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define Com_IncCycleTimeCnt(Index)                                                                  Com_GetCycleTimeCnt(Index)++
#define Com_IncHandleRxPduDeferred(Index)                                                           Com_GetHandleRxPduDeferred(Index)++
#define Com_IncRxDeadlineMonitoringISRLockCounter()                                                 Com_GetRxDeadlineMonitoringISRLockCounter()++
#define Com_IncRxDefPduBuffer(Index)                                                                Com_GetRxDefPduBuffer(Index)++
#define Com_IncRxDeferredFctPtrCache(Index)                                                         Com_GetRxDeferredFctPtrCache(Index)++
#define Com_IncRxDeferredProcessingISRLockCounter()                                                 Com_GetRxDeferredProcessingISRLockCounter()++
#define Com_IncRxDlMonDivisorCounter()                                                              Com_GetRxDlMonDivisorCounter()++
#define Com_IncRxIPduGroupISRLockCounter()                                                          Com_GetRxIPduGroupISRLockCounter()++
#define Com_IncRxSigBufferUInt16(Index)                                                             Com_GetRxSigBufferUInt16(Index)++
#define Com_IncRxSigBufferUInt32(Index)                                                             Com_GetRxSigBufferUInt32(Index)++
#define Com_IncRxSigBufferUInt8(Index)                                                              Com_GetRxSigBufferUInt8(Index)++
#define Com_IncRxTOutCnt(Index)                                                                     Com_GetRxTOutCnt(Index)++
#define Com_IncTxBuffer(Index)                                                                      Com_GetTxBuffer(Index)++
#define Com_IncTxCycleCounterDivisorCounter()                                                       Com_GetTxCycleCounterDivisorCounter()++
#define Com_IncTxCyclicProcessingISRLockCounter()                                                   Com_GetTxCyclicProcessingISRLockCounter()++
#define Com_IncTxIPduGroupISRLockCounter()                                                          Com_GetTxIPduGroupISRLockCounter()++
#define Com_IncTxProcessingISRLockCounter()                                                         Com_GetTxProcessingISRLockCounter()++
#define Com_IncTxSduLength(Index)                                                                   Com_GetTxSduLength(Index)++
/** 
  \}
*/ 

/** 
  \defgroup  ComPCDecrementDataMacros  Com Decrement Data Macros (PRE_COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define Com_DecCycleTimeCnt(Index)                                                                  Com_GetCycleTimeCnt(Index)--
#define Com_DecHandleRxPduDeferred(Index)                                                           Com_GetHandleRxPduDeferred(Index)--
#define Com_DecRxDeadlineMonitoringISRLockCounter()                                                 Com_GetRxDeadlineMonitoringISRLockCounter()--
#define Com_DecRxDefPduBuffer(Index)                                                                Com_GetRxDefPduBuffer(Index)--
#define Com_DecRxDeferredFctPtrCache(Index)                                                         Com_GetRxDeferredFctPtrCache(Index)--
#define Com_DecRxDeferredProcessingISRLockCounter()                                                 Com_GetRxDeferredProcessingISRLockCounter()--
#define Com_DecRxDlMonDivisorCounter()                                                              Com_GetRxDlMonDivisorCounter()--
#define Com_DecRxIPduGroupISRLockCounter()                                                          Com_GetRxIPduGroupISRLockCounter()--
#define Com_DecRxSigBufferUInt16(Index)                                                             Com_GetRxSigBufferUInt16(Index)--
#define Com_DecRxSigBufferUInt32(Index)                                                             Com_GetRxSigBufferUInt32(Index)--
#define Com_DecRxSigBufferUInt8(Index)                                                              Com_GetRxSigBufferUInt8(Index)--
#define Com_DecRxTOutCnt(Index)                                                                     Com_GetRxTOutCnt(Index)--
#define Com_DecTxBuffer(Index)                                                                      Com_GetTxBuffer(Index)--
#define Com_DecTxCycleCounterDivisorCounter()                                                       Com_GetTxCycleCounterDivisorCounter()--
#define Com_DecTxCyclicProcessingISRLockCounter()                                                   Com_GetTxCyclicProcessingISRLockCounter()--
#define Com_DecTxIPduGroupISRLockCounter()                                                          Com_GetTxIPduGroupISRLockCounter()--
#define Com_DecTxProcessingISRLockCounter()                                                         Com_GetTxProcessingISRLockCounter()--
#define Com_DecTxSduLength(Index)                                                                   Com_GetTxSduLength(Index)--
/** 
  \}
*/ 

  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  ComPCIterableTypes  Com Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate Com_AlwaysActiveTxComIPdus */
typedef uint8_least Com_AlwaysActiveTxComIPdusIterType;

/**   \brief  type used to iterate Com_CbkRxTOutFuncPtr */
typedef uint8_least Com_CbkRxTOutFuncPtrIterType;

/**   \brief  type used to iterate Com_CbkRxTOutFuncPtrInd */
typedef uint8_least Com_CbkRxTOutFuncPtrIndIterType;

/**   \brief  type used to iterate Com_ConstValueUInt16 */
typedef uint8_least Com_ConstValueUInt16IterType;

/**   \brief  type used to iterate Com_ConstValueUInt32 */
typedef uint8_least Com_ConstValueUInt32IterType;

/**   \brief  type used to iterate Com_ConstValueUInt8 */
typedef uint8_least Com_ConstValueUInt8IterType;

/**   \brief  type used to iterate Com_HandleRxPduDeferred */
typedef uint8_least Com_HandleRxPduDeferredIterType;

/**   \brief  type used to iterate Com_IPduGroupInfo */
typedef uint8_least Com_IPduGroupInfoIterType;

/**   \brief  type used to iterate Com_IPduGroupInfoOfRxPduInfoInd */
typedef uint8_least Com_IPduGroupInfoOfRxPduInfoIndIterType;

/**   \brief  type used to iterate Com_IPduGroupInfoOfTxPduInfoInd */
typedef uint8_least Com_IPduGroupInfoOfTxPduInfoIndIterType;

/**   \brief  type used to iterate Com_IPduGroupInfoToSubIPduGroupsInd */
typedef uint8_least Com_IPduGroupInfoToSubIPduGroupsIndIterType;

/**   \brief  type used to iterate Com_RxAccessInfo */
typedef uint8_least Com_RxAccessInfoIterType;

/**   \brief  type used to iterate Com_RxAccessInfoInd */
typedef uint8_least Com_RxAccessInfoIndIterType;

/**   \brief  type used to iterate Com_RxCbkFuncPtr */
typedef uint8_least Com_RxCbkFuncPtrIterType;

/**   \brief  type used to iterate Com_RxDefPduBuffer */
typedef uint8_least Com_RxDefPduBufferIterType;

/**   \brief  type used to iterate Com_RxDeferredFctPtrCache */
typedef uint8_least Com_RxDeferredFctPtrCacheIterType;

/**   \brief  type used to iterate Com_RxPduInfo */
typedef uint8_least Com_RxPduInfoIterType;

/**   \brief  type used to iterate Com_RxPduInfoInd */
typedef uint8_least Com_RxPduInfoIndIterType;

/**   \brief  type used to iterate Com_RxSigBufferUInt16 */
typedef uint8_least Com_RxSigBufferUInt16IterType;

/**   \brief  type used to iterate Com_RxSigBufferUInt32 */
typedef uint8_least Com_RxSigBufferUInt32IterType;

/**   \brief  type used to iterate Com_RxSigBufferUInt8 */
typedef uint8_least Com_RxSigBufferUInt8IterType;

/**   \brief  type used to iterate Com_RxSigInfo */
typedef uint8_least Com_RxSigInfoIterType;

/**   \brief  type used to iterate Com_RxTOutInfo */
typedef uint8_least Com_RxTOutInfoIterType;

/**   \brief  type used to iterate Com_RxTOutInfoInd */
typedef uint8_least Com_RxTOutInfoIndIterType;

/**   \brief  type used to iterate Com_TxBuffer */
typedef uint8_least Com_TxBufferIterType;

/**   \brief  type used to iterate Com_TxCyclicPdu */
typedef uint8_least Com_TxCyclicPduIterType;

/**   \brief  type used to iterate Com_TxModeFalse */
typedef uint8_least Com_TxModeFalseIterType;

/**   \brief  type used to iterate Com_TxModeInfo */
typedef uint8_least Com_TxModeInfoIterType;

/**   \brief  type used to iterate Com_TxModeTrue */
typedef uint8_least Com_TxModeTrueIterType;

/**   \brief  type used to iterate Com_TxPduInfo */
typedef uint8_least Com_TxPduInfoIterType;

/**   \brief  type used to iterate Com_TxPduInfoInd */
typedef uint8_least Com_TxPduInfoIndIterType;

/**   \brief  type used to iterate Com_TxPduInitValue */
typedef uint8_least Com_TxPduInitValueIterType;

/**   \brief  type used to iterate Com_TxSigInfo */
typedef uint8_least Com_TxSigInfoIterType;

/** 
  \}
*/ 

/** 
  \defgroup  ComPCIterableTypesWithSizeRelations  Com Iterable Types With Size Relations (PRE_COMPILE)
  \brief  These type definitions are used to iterate over a VAR based array with the same iterator as the related CONST array.
  \{
*/ 
/**   \brief  type used to iterate Com_CurrentTxMode */
typedef Com_TxPduInfoIterType Com_CurrentTxModeIterType;

/**   \brief  type used to iterate Com_CycleTimeCnt */
typedef Com_TxPduInfoIterType Com_CycleTimeCntIterType;

/**   \brief  type used to iterate Com_CyclicSendRequest */
typedef Com_TxPduInfoIterType Com_CyclicSendRequestIterType;

/**   \brief  type used to iterate Com_IPduGroupState */
typedef Com_IPduGroupInfoIterType Com_IPduGroupStateIterType;

/**   \brief  type used to iterate Com_RxPduDmState */
typedef Com_RxTOutInfoIterType Com_RxPduDmStateIterType;

/**   \brief  type used to iterate Com_RxPduGrpActive */
typedef Com_RxPduInfoIterType Com_RxPduGrpActiveIterType;

/**   \brief  type used to iterate Com_RxTOutCnt */
typedef Com_RxTOutInfoIterType Com_RxTOutCntIterType;

/**   \brief  type used to iterate Com_TransmitRequest */
typedef Com_TxPduInfoIterType Com_TransmitRequestIterType;

/**   \brief  type used to iterate Com_TxPduGrpActive */
typedef Com_TxPduInfoIterType Com_TxPduGrpActiveIterType;

/**   \brief  type used to iterate Com_TxSduLength */
typedef Com_TxPduInfoIterType Com_TxSduLengthIterType;

/** 
  \}
*/ 

/** 
  \defgroup  ComPCValueTypes  Com Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for Com_TxPduInfoIdxOfAlwaysActiveTxComIPdus */
typedef uint8 Com_TxPduInfoIdxOfAlwaysActiveTxComIPdusType;

/**   \brief  value based type definition for Com_CbkRxTOutFuncPtrInd */
typedef uint8 Com_CbkRxTOutFuncPtrIndType;

/**   \brief  value based type definition for Com_ConfigId */
typedef uint8 Com_ConfigIdType;

/**   \brief  value based type definition for Com_ConstValueUInt16 */
typedef uint16 Com_ConstValueUInt16Type;

/**   \brief  value based type definition for Com_ConstValueUInt32 */
typedef uint32 Com_ConstValueUInt32Type;

/**   \brief  value based type definition for Com_ConstValueUInt8 */
typedef uint8 Com_ConstValueUInt8Type;

/**   \brief  value based type definition for Com_CurrentTxMode */
typedef boolean Com_CurrentTxModeType;

/**   \brief  value based type definition for Com_CycleTimeCnt */
typedef uint8 Com_CycleTimeCntType;

/**   \brief  value based type definition for Com_CyclicSendRequest */
typedef boolean Com_CyclicSendRequestType;

/**   \brief  value based type definition for Com_HandleRxPduDeferred */
typedef PduLengthType Com_HandleRxPduDeferredType;

/**   \brief  value based type definition for Com_IPduGroupInfoToSubIPduGroupsIndEndIdxOfIPduGroupInfo */
typedef uint8 Com_IPduGroupInfoToSubIPduGroupsIndEndIdxOfIPduGroupInfoType;

/**   \brief  value based type definition for Com_IPduGroupInfoToSubIPduGroupsIndStartIdxOfIPduGroupInfo */
typedef uint8 Com_IPduGroupInfoToSubIPduGroupsIndStartIdxOfIPduGroupInfoType;

/**   \brief  value based type definition for Com_IPduGroupInfoToSubIPduGroupsIndUsedOfIPduGroupInfo */
typedef boolean Com_IPduGroupInfoToSubIPduGroupsIndUsedOfIPduGroupInfoType;

/**   \brief  value based type definition for Com_RxPduInfoIndEndIdxOfIPduGroupInfo */
typedef uint8 Com_RxPduInfoIndEndIdxOfIPduGroupInfoType;

/**   \brief  value based type definition for Com_RxPduInfoIndStartIdxOfIPduGroupInfo */
typedef uint8 Com_RxPduInfoIndStartIdxOfIPduGroupInfoType;

/**   \brief  value based type definition for Com_RxPduInfoIndUsedOfIPduGroupInfo */
typedef boolean Com_RxPduInfoIndUsedOfIPduGroupInfoType;

/**   \brief  value based type definition for Com_TxPduInfoIndEndIdxOfIPduGroupInfo */
typedef uint8 Com_TxPduInfoIndEndIdxOfIPduGroupInfoType;

/**   \brief  value based type definition for Com_TxPduInfoIndStartIdxOfIPduGroupInfo */
typedef uint8 Com_TxPduInfoIndStartIdxOfIPduGroupInfoType;

/**   \brief  value based type definition for Com_TxPduInfoIndUsedOfIPduGroupInfo */
typedef boolean Com_TxPduInfoIndUsedOfIPduGroupInfoType;

/**   \brief  value based type definition for Com_IPduGroupInfoOfRxPduInfoInd */
typedef uint8 Com_IPduGroupInfoOfRxPduInfoIndType;

/**   \brief  value based type definition for Com_IPduGroupInfoOfTxPduInfoInd */
typedef uint8 Com_IPduGroupInfoOfTxPduInfoIndType;

/**   \brief  value based type definition for Com_IPduGroupInfoToSubIPduGroupsInd */
typedef uint8 Com_IPduGroupInfoToSubIPduGroupsIndType;

/**   \brief  value based type definition for Com_IPduGroupState */
typedef uint8 Com_IPduGroupStateType;

/**   \brief  value based type definition for Com_Initialized */
typedef boolean Com_InitializedType;

/**   \brief  value based type definition for Com_PduGrpCnt */
typedef uint8 Com_PduGrpCntType;

/**   \brief  value based type definition for Com_ApplTypeOfRxAccessInfo */
typedef uint8 Com_ApplTypeOfRxAccessInfoType;

/**   \brief  value based type definition for Com_BitLengthOfRxAccessInfo */
typedef uint8 Com_BitLengthOfRxAccessInfoType;

/**   \brief  value based type definition for Com_BitPositionOfRxAccessInfo */
typedef uint8 Com_BitPositionOfRxAccessInfoType;

/**   \brief  value based type definition for Com_BufferIdxOfRxAccessInfo */
typedef uint8 Com_BufferIdxOfRxAccessInfoType;

/**   \brief  value based type definition for Com_BufferUsedOfRxAccessInfo */
typedef boolean Com_BufferUsedOfRxAccessInfoType;

/**   \brief  value based type definition for Com_BusAccOfRxAccessInfo */
typedef uint8 Com_BusAccOfRxAccessInfoType;

/**   \brief  value based type definition for Com_ByteLengthOfRxAccessInfo */
typedef uint8 Com_ByteLengthOfRxAccessInfoType;

/**   \brief  value based type definition for Com_BytePositionOfRxAccessInfo */
typedef uint8 Com_BytePositionOfRxAccessInfoType;

/**   \brief  value based type definition for Com_InitValueIdxOfRxAccessInfo */
typedef uint8 Com_InitValueIdxOfRxAccessInfoType;

/**   \brief  value based type definition for Com_InitValueUsedOfRxAccessInfo */
typedef boolean Com_InitValueUsedOfRxAccessInfoType;

/**   \brief  value based type definition for Com_RxPduInfoIdxOfRxAccessInfo */
typedef uint8 Com_RxPduInfoIdxOfRxAccessInfoType;

/**   \brief  value based type definition for Com_RxTOutInfoIdxOfRxAccessInfo */
typedef uint8 Com_RxTOutInfoIdxOfRxAccessInfoType;

/**   \brief  value based type definition for Com_RxTOutInfoUsedOfRxAccessInfo */
typedef boolean Com_RxTOutInfoUsedOfRxAccessInfoType;

/**   \brief  value based type definition for Com_StartByteInPduPositionOfRxAccessInfo */
typedef uint8 Com_StartByteInPduPositionOfRxAccessInfoType;

/**   \brief  value based type definition for Com_RxAccessInfoInd */
typedef uint8 Com_RxAccessInfoIndType;

/**   \brief  value based type definition for Com_RxDeadlineMonitoringISRLockCounter */
typedef uint16 Com_RxDeadlineMonitoringISRLockCounterType;

/**   \brief  value based type definition for Com_RxDeadlineMonitoringISRLockThreshold */
typedef uint8 Com_RxDeadlineMonitoringISRLockThresholdType;

/**   \brief  value based type definition for Com_RxDefPduBuffer */
typedef uint8 Com_RxDefPduBufferType;

/**   \brief  value based type definition for Com_RxDeferredFctPtrCache */
typedef uint32 Com_RxDeferredFctPtrCacheType;

/**   \brief  value based type definition for Com_RxDeferredProcessingISRLockCounter */
typedef uint16 Com_RxDeferredProcessingISRLockCounterType;

/**   \brief  value based type definition for Com_RxDeferredProcessingISRLockThreshold */
typedef uint8 Com_RxDeferredProcessingISRLockThresholdType;

/**   \brief  value based type definition for Com_RxDlMonDivisor */
typedef uint8 Com_RxDlMonDivisorType;

/**   \brief  value based type definition for Com_RxDlMonDivisorCounter */
typedef uint16 Com_RxDlMonDivisorCounterType;

/**   \brief  value based type definition for Com_RxIPduGroupISRLockCounter */
typedef uint16 Com_RxIPduGroupISRLockCounterType;

/**   \brief  value based type definition for Com_RxIPduGroupISRLockThreshold */
typedef uint8 Com_RxIPduGroupISRLockThresholdType;

/**   \brief  value based type definition for Com_RxPduDmState */
typedef uint8 Com_RxPduDmStateType;

/**   \brief  value based type definition for Com_RxPduGrpActive */
typedef boolean Com_RxPduGrpActiveType;

/**   \brief  value based type definition for Com_HandleRxPduDeferredIdxOfRxPduInfo */
typedef uint8 Com_HandleRxPduDeferredIdxOfRxPduInfoType;

/**   \brief  value based type definition for Com_HandleRxPduDeferredUsedOfRxPduInfo */
typedef boolean Com_HandleRxPduDeferredUsedOfRxPduInfoType;

/**   \brief  value based type definition for Com_IPduGroupInfoOfRxPduInfoIndEndIdxOfRxPduInfo */
typedef uint8 Com_IPduGroupInfoOfRxPduInfoIndEndIdxOfRxPduInfoType;

/**   \brief  value based type definition for Com_IPduGroupInfoOfRxPduInfoIndStartIdxOfRxPduInfo */
typedef uint8 Com_IPduGroupInfoOfRxPduInfoIndStartIdxOfRxPduInfoType;

/**   \brief  value based type definition for Com_IPduGroupInfoOfRxPduInfoIndUsedOfRxPduInfo */
typedef boolean Com_IPduGroupInfoOfRxPduInfoIndUsedOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxAccessInfoIndEndIdxOfRxPduInfo */
typedef uint8 Com_RxAccessInfoIndEndIdxOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxAccessInfoIndStartIdxOfRxPduInfo */
typedef uint8 Com_RxAccessInfoIndStartIdxOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxAccessInfoIndUsedOfRxPduInfo */
typedef boolean Com_RxAccessInfoIndUsedOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxDefPduBufferEndIdxOfRxPduInfo */
typedef uint8 Com_RxDefPduBufferEndIdxOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxDefPduBufferLengthOfRxPduInfo */
typedef uint8 Com_RxDefPduBufferLengthOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxDefPduBufferStartIdxOfRxPduInfo */
typedef uint8 Com_RxDefPduBufferStartIdxOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxDefPduBufferUsedOfRxPduInfo */
typedef boolean Com_RxDefPduBufferUsedOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxSigInfoEndIdxOfRxPduInfo */
typedef uint8 Com_RxSigInfoEndIdxOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxSigInfoStartIdxOfRxPduInfo */
typedef uint8 Com_RxSigInfoStartIdxOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxSigInfoUsedOfRxPduInfo */
typedef boolean Com_RxSigInfoUsedOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxTOutInfoIdxOfRxPduInfo */
typedef uint8 Com_RxTOutInfoIdxOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxTOutInfoIndEndIdxOfRxPduInfo */
typedef uint8 Com_RxTOutInfoIndEndIdxOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxTOutInfoIndStartIdxOfRxPduInfo */
typedef uint8 Com_RxTOutInfoIndStartIdxOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxTOutInfoIndUsedOfRxPduInfo */
typedef boolean Com_RxTOutInfoIndUsedOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxTOutInfoUsedOfRxPduInfo */
typedef boolean Com_RxTOutInfoUsedOfRxPduInfoType;

/**   \brief  value based type definition for Com_SignalProcessingOfRxPduInfo */
typedef uint8 Com_SignalProcessingOfRxPduInfoType;

/**   \brief  value based type definition for Com_TypeOfRxPduInfo */
typedef uint8 Com_TypeOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxPduInfoInd */
typedef uint8 Com_RxPduInfoIndType;

/**   \brief  value based type definition for Com_RxSigBufferUInt16 */
typedef uint16 Com_RxSigBufferUInt16Type;

/**   \brief  value based type definition for Com_RxSigBufferUInt32 */
typedef uint32 Com_RxSigBufferUInt32Type;

/**   \brief  value based type definition for Com_RxSigBufferUInt8 */
typedef uint8 Com_RxSigBufferUInt8Type;

/**   \brief  value based type definition for Com_RxAccessInfoIdxOfRxSigInfo */
typedef uint8 Com_RxAccessInfoIdxOfRxSigInfoType;

/**   \brief  value based type definition for Com_RxCbkFuncPtrAckIdxOfRxSigInfo */
typedef uint8 Com_RxCbkFuncPtrAckIdxOfRxSigInfoType;

/**   \brief  value based type definition for Com_RxCbkFuncPtrAckUsedOfRxSigInfo */
typedef boolean Com_RxCbkFuncPtrAckUsedOfRxSigInfoType;

/**   \brief  value based type definition for Com_RxTOutInfoIdxOfRxSigInfo */
typedef uint8 Com_RxTOutInfoIdxOfRxSigInfoType;

/**   \brief  value based type definition for Com_RxTOutInfoUsedOfRxSigInfo */
typedef boolean Com_RxTOutInfoUsedOfRxSigInfoType;

/**   \brief  value based type definition for Com_SignalProcessingOfRxSigInfo */
typedef uint8 Com_SignalProcessingOfRxSigInfoType;

/**   \brief  value based type definition for Com_ValidDlcOfRxSigInfo */
typedef uint8 Com_ValidDlcOfRxSigInfoType;

/**   \brief  value based type definition for Com_RxTOutCnt */
typedef uint8 Com_RxTOutCntType;

/**   \brief  value based type definition for Com_CbkRxTOutFuncPtrIndEndIdxOfRxTOutInfo */
typedef uint8 Com_CbkRxTOutFuncPtrIndEndIdxOfRxTOutInfoType;

/**   \brief  value based type definition for Com_CbkRxTOutFuncPtrIndStartIdxOfRxTOutInfo */
typedef uint8 Com_CbkRxTOutFuncPtrIndStartIdxOfRxTOutInfoType;

/**   \brief  value based type definition for Com_CbkRxTOutFuncPtrIndUsedOfRxTOutInfo */
typedef boolean Com_CbkRxTOutFuncPtrIndUsedOfRxTOutInfoType;

/**   \brief  value based type definition for Com_FactorOfRxTOutInfo */
typedef uint8 Com_FactorOfRxTOutInfoType;

/**   \brief  value based type definition for Com_FirstFactorOfRxTOutInfo */
typedef uint8 Com_FirstFactorOfRxTOutInfoType;

/**   \brief  value based type definition for Com_RxPduInfoIdxOfRxTOutInfo */
typedef uint8 Com_RxPduInfoIdxOfRxTOutInfoType;

/**   \brief  value based type definition for Com_RxTOutInfoInd */
typedef uint8 Com_RxTOutInfoIndType;

/**   \brief  value based type definition for Com_SizeOfAlwaysActiveTxComIPdus */
typedef uint8 Com_SizeOfAlwaysActiveTxComIPdusType;

/**   \brief  value based type definition for Com_SizeOfCbkRxTOutFuncPtr */
typedef uint8 Com_SizeOfCbkRxTOutFuncPtrType;

/**   \brief  value based type definition for Com_SizeOfCbkRxTOutFuncPtrInd */
typedef uint8 Com_SizeOfCbkRxTOutFuncPtrIndType;

/**   \brief  value based type definition for Com_SizeOfConstValueUInt16 */
typedef uint8 Com_SizeOfConstValueUInt16Type;

/**   \brief  value based type definition for Com_SizeOfConstValueUInt32 */
typedef uint8 Com_SizeOfConstValueUInt32Type;

/**   \brief  value based type definition for Com_SizeOfConstValueUInt8 */
typedef uint8 Com_SizeOfConstValueUInt8Type;

/**   \brief  value based type definition for Com_SizeOfCurrentTxMode */
typedef uint8 Com_SizeOfCurrentTxModeType;

/**   \brief  value based type definition for Com_SizeOfCycleTimeCnt */
typedef uint8 Com_SizeOfCycleTimeCntType;

/**   \brief  value based type definition for Com_SizeOfCyclicSendRequest */
typedef uint8 Com_SizeOfCyclicSendRequestType;

/**   \brief  value based type definition for Com_SizeOfHandleRxPduDeferred */
typedef uint8 Com_SizeOfHandleRxPduDeferredType;

/**   \brief  value based type definition for Com_SizeOfIPduGroupInfo */
typedef uint8 Com_SizeOfIPduGroupInfoType;

/**   \brief  value based type definition for Com_SizeOfIPduGroupInfoOfRxPduInfoInd */
typedef uint8 Com_SizeOfIPduGroupInfoOfRxPduInfoIndType;

/**   \brief  value based type definition for Com_SizeOfIPduGroupInfoOfTxPduInfoInd */
typedef uint8 Com_SizeOfIPduGroupInfoOfTxPduInfoIndType;

/**   \brief  value based type definition for Com_SizeOfIPduGroupInfoToSubIPduGroupsInd */
typedef uint8 Com_SizeOfIPduGroupInfoToSubIPduGroupsIndType;

/**   \brief  value based type definition for Com_SizeOfIPduGroupState */
typedef uint8 Com_SizeOfIPduGroupStateType;

/**   \brief  value based type definition for Com_SizeOfRxAccessInfo */
typedef uint8 Com_SizeOfRxAccessInfoType;

/**   \brief  value based type definition for Com_SizeOfRxAccessInfoInd */
typedef uint8 Com_SizeOfRxAccessInfoIndType;

/**   \brief  value based type definition for Com_SizeOfRxCbkFuncPtr */
typedef uint8 Com_SizeOfRxCbkFuncPtrType;

/**   \brief  value based type definition for Com_SizeOfRxDefPduBuffer */
typedef uint8 Com_SizeOfRxDefPduBufferType;

/**   \brief  value based type definition for Com_SizeOfRxDeferredFctPtrCache */
typedef uint8 Com_SizeOfRxDeferredFctPtrCacheType;

/**   \brief  value based type definition for Com_SizeOfRxPduDmState */
typedef uint8 Com_SizeOfRxPduDmStateType;

/**   \brief  value based type definition for Com_SizeOfRxPduGrpActive */
typedef uint8 Com_SizeOfRxPduGrpActiveType;

/**   \brief  value based type definition for Com_SizeOfRxPduInfo */
typedef uint8 Com_SizeOfRxPduInfoType;

/**   \brief  value based type definition for Com_SizeOfRxPduInfoInd */
typedef uint8 Com_SizeOfRxPduInfoIndType;

/**   \brief  value based type definition for Com_SizeOfRxSigBufferUInt16 */
typedef uint8 Com_SizeOfRxSigBufferUInt16Type;

/**   \brief  value based type definition for Com_SizeOfRxSigBufferUInt32 */
typedef uint8 Com_SizeOfRxSigBufferUInt32Type;

/**   \brief  value based type definition for Com_SizeOfRxSigBufferUInt8 */
typedef uint8 Com_SizeOfRxSigBufferUInt8Type;

/**   \brief  value based type definition for Com_SizeOfRxSigInfo */
typedef uint8 Com_SizeOfRxSigInfoType;

/**   \brief  value based type definition for Com_SizeOfRxTOutCnt */
typedef uint8 Com_SizeOfRxTOutCntType;

/**   \brief  value based type definition for Com_SizeOfRxTOutInfo */
typedef uint8 Com_SizeOfRxTOutInfoType;

/**   \brief  value based type definition for Com_SizeOfRxTOutInfoInd */
typedef uint8 Com_SizeOfRxTOutInfoIndType;

/**   \brief  value based type definition for Com_SizeOfTransmitRequest */
typedef uint8 Com_SizeOfTransmitRequestType;

/**   \brief  value based type definition for Com_SizeOfTxBuffer */
typedef uint8 Com_SizeOfTxBufferType;

/**   \brief  value based type definition for Com_SizeOfTxCyclicPdu */
typedef uint8 Com_SizeOfTxCyclicPduType;

/**   \brief  value based type definition for Com_SizeOfTxModeFalse */
typedef uint8 Com_SizeOfTxModeFalseType;

/**   \brief  value based type definition for Com_SizeOfTxModeInfo */
typedef uint8 Com_SizeOfTxModeInfoType;

/**   \brief  value based type definition for Com_SizeOfTxModeTrue */
typedef uint8 Com_SizeOfTxModeTrueType;

/**   \brief  value based type definition for Com_SizeOfTxPduGrpActive */
typedef uint8 Com_SizeOfTxPduGrpActiveType;

/**   \brief  value based type definition for Com_SizeOfTxPduInfo */
typedef uint8 Com_SizeOfTxPduInfoType;

/**   \brief  value based type definition for Com_SizeOfTxPduInfoInd */
typedef uint8 Com_SizeOfTxPduInfoIndType;

/**   \brief  value based type definition for Com_SizeOfTxPduInitValue */
typedef uint8 Com_SizeOfTxPduInitValueType;

/**   \brief  value based type definition for Com_SizeOfTxSduLength */
typedef uint8 Com_SizeOfTxSduLengthType;

/**   \brief  value based type definition for Com_SizeOfTxSigInfo */
typedef uint8 Com_SizeOfTxSigInfoType;

/**   \brief  value based type definition for Com_TransmitRequest */
typedef boolean Com_TransmitRequestType;

/**   \brief  value based type definition for Com_TxBuffer */
typedef uint8 Com_TxBufferType;

/**   \brief  value based type definition for Com_TxCycleCounterDivisor */
typedef uint8 Com_TxCycleCounterDivisorType;

/**   \brief  value based type definition for Com_TxCycleCounterDivisorCounter */
typedef uint16 Com_TxCycleCounterDivisorCounterType;

/**   \brief  value based type definition for Com_TxPduInfoIdxOfTxCyclicPdu */
typedef uint8 Com_TxPduInfoIdxOfTxCyclicPduType;

/**   \brief  value based type definition for Com_TxCyclicProcessingISRLockCounter */
typedef uint16 Com_TxCyclicProcessingISRLockCounterType;

/**   \brief  value based type definition for Com_TxCyclicProcessingISRLockThreshold */
typedef uint8 Com_TxCyclicProcessingISRLockThresholdType;

/**   \brief  value based type definition for Com_TxIPduGroupISRLockCounter */
typedef uint16 Com_TxIPduGroupISRLockCounterType;

/**   \brief  value based type definition for Com_TxIPduGroupISRLockThreshold */
typedef uint8 Com_TxIPduGroupISRLockThresholdType;

/**   \brief  value based type definition for Com_PeriodicOfTxModeFalse */
typedef boolean Com_PeriodicOfTxModeFalseType;

/**   \brief  value based type definition for Com_TimePeriodOfTxModeFalse */
typedef uint8 Com_TimePeriodOfTxModeFalseType;

/**   \brief  value based type definition for Com_InitModeOfTxModeInfo */
typedef boolean Com_InitModeOfTxModeInfoType;

/**   \brief  value based type definition for Com_TxModeFalseIdxOfTxModeInfo */
typedef uint8 Com_TxModeFalseIdxOfTxModeInfoType;

/**   \brief  value based type definition for Com_TxModeTrueIdxOfTxModeInfo */
typedef uint8 Com_TxModeTrueIdxOfTxModeInfoType;

/**   \brief  value based type definition for Com_PeriodicOfTxModeTrue */
typedef boolean Com_PeriodicOfTxModeTrueType;

/**   \brief  value based type definition for Com_TimePeriodOfTxModeTrue */
typedef uint8 Com_TimePeriodOfTxModeTrueType;

/**   \brief  value based type definition for Com_TxPduGrpActive */
typedef boolean Com_TxPduGrpActiveType;

/**   \brief  value based type definition for Com_ExternalIdOfTxPduInfo */
typedef uint8 Com_ExternalIdOfTxPduInfoType;

/**   \brief  value based type definition for Com_IPduGroupInfoOfTxPduInfoIndEndIdxOfTxPduInfo */
typedef uint8 Com_IPduGroupInfoOfTxPduInfoIndEndIdxOfTxPduInfoType;

/**   \brief  value based type definition for Com_IPduGroupInfoOfTxPduInfoIndStartIdxOfTxPduInfo */
typedef uint8 Com_IPduGroupInfoOfTxPduInfoIndStartIdxOfTxPduInfoType;

/**   \brief  value based type definition for Com_IPduGroupInfoOfTxPduInfoIndUsedOfTxPduInfo */
typedef boolean Com_IPduGroupInfoOfTxPduInfoIndUsedOfTxPduInfoType;

/**   \brief  value based type definition for Com_MetaDataLengthOfTxPduInfo */
typedef uint8 Com_MetaDataLengthOfTxPduInfoType;

/**   \brief  value based type definition for Com_PduWithMetaDataLengthOfTxPduInfo */
typedef uint8 Com_PduWithMetaDataLengthOfTxPduInfoType;

/**   \brief  value based type definition for Com_TxBufferEndIdxOfTxPduInfo */
typedef uint8 Com_TxBufferEndIdxOfTxPduInfoType;

/**   \brief  value based type definition for Com_TxBufferLengthOfTxPduInfo */
typedef uint8 Com_TxBufferLengthOfTxPduInfoType;

/**   \brief  value based type definition for Com_TxBufferStartIdxOfTxPduInfo */
typedef uint8 Com_TxBufferStartIdxOfTxPduInfoType;

/**   \brief  value based type definition for Com_TxBufferUsedOfTxPduInfo */
typedef boolean Com_TxBufferUsedOfTxPduInfoType;

/**   \brief  value based type definition for Com_TxPduInitValueEndIdxOfTxPduInfo */
typedef uint8 Com_TxPduInitValueEndIdxOfTxPduInfoType;

/**   \brief  value based type definition for Com_TxPduInitValueStartIdxOfTxPduInfo */
typedef uint8 Com_TxPduInitValueStartIdxOfTxPduInfoType;

/**   \brief  value based type definition for Com_TxPduInitValueUsedOfTxPduInfo */
typedef boolean Com_TxPduInitValueUsedOfTxPduInfoType;

/**   \brief  value based type definition for Com_TxPduInfoInd */
typedef uint8 Com_TxPduInfoIndType;

/**   \brief  value based type definition for Com_TxPduInitValue */
typedef uint8 Com_TxPduInitValueType;

/**   \brief  value based type definition for Com_TxProcessingISRLockCounter */
typedef uint16 Com_TxProcessingISRLockCounterType;

/**   \brief  value based type definition for Com_TxProcessingISRLockThreshold */
typedef uint8 Com_TxProcessingISRLockThresholdType;

/**   \brief  value based type definition for Com_TxSduLength */
typedef PduLengthType Com_TxSduLengthType;

/**   \brief  value based type definition for Com_ApplTypeOfTxSigInfo */
typedef uint8 Com_ApplTypeOfTxSigInfoType;

/**   \brief  value based type definition for Com_BitLengthOfTxSigInfo */
typedef uint8 Com_BitLengthOfTxSigInfoType;

/**   \brief  value based type definition for Com_BitPositionOfTxSigInfo */
typedef uint8 Com_BitPositionOfTxSigInfoType;

/**   \brief  value based type definition for Com_BusAccOfTxSigInfo */
typedef uint8 Com_BusAccOfTxSigInfoType;

/**   \brief  value based type definition for Com_ByteLengthOfTxSigInfo */
typedef uint8 Com_ByteLengthOfTxSigInfoType;

/**   \brief  value based type definition for Com_BytePositionOfTxSigInfo */
typedef uint8 Com_BytePositionOfTxSigInfoType;

/**   \brief  value based type definition for Com_StartByteInPduPositionOfTxSigInfo */
typedef uint8 Com_StartByteInPduPositionOfTxSigInfoType;

/**   \brief  value based type definition for Com_TxBufferEndIdxOfTxSigInfo */
typedef uint8 Com_TxBufferEndIdxOfTxSigInfoType;

/**   \brief  value based type definition for Com_TxBufferLengthOfTxSigInfo */
typedef uint8 Com_TxBufferLengthOfTxSigInfoType;

/**   \brief  value based type definition for Com_TxBufferStartIdxOfTxSigInfo */
typedef uint8 Com_TxBufferStartIdxOfTxSigInfoType;

/**   \brief  value based type definition for Com_TxBufferUsedOfTxSigInfo */
typedef boolean Com_TxBufferUsedOfTxSigInfoType;

/**   \brief  value based type definition for Com_TxPduInfoIdxOfTxSigInfo */
typedef uint8 Com_TxPduInfoIdxOfTxSigInfoType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  ComPCStructTypes  Com Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in Com_AlwaysActiveTxComIPdus */
typedef struct sCom_AlwaysActiveTxComIPdusType
{
  uint8 Com_AlwaysActiveTxComIPdusNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Com_AlwaysActiveTxComIPdusType;

/**   \brief  type used in Com_IPduGroupInfo */
typedef struct sCom_IPduGroupInfoType
{
  Com_TxPduInfoIndUsedOfIPduGroupInfoType TxPduInfoIndUsedOfIPduGroupInfo;  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_TxPduInfoInd */
  Com_RxPduInfoIndEndIdxOfIPduGroupInfoType RxPduInfoIndEndIdxOfIPduGroupInfo;  /**< the end index of the 0:n relation pointing to Com_RxPduInfoInd */
  Com_RxPduInfoIndStartIdxOfIPduGroupInfoType RxPduInfoIndStartIdxOfIPduGroupInfo;  /**< the start index of the 0:n relation pointing to Com_RxPduInfoInd */
  Com_TxPduInfoIndEndIdxOfIPduGroupInfoType TxPduInfoIndEndIdxOfIPduGroupInfo;  /**< the end index of the 0:n relation pointing to Com_TxPduInfoInd */
  Com_TxPduInfoIndStartIdxOfIPduGroupInfoType TxPduInfoIndStartIdxOfIPduGroupInfo;  /**< the start index of the 0:n relation pointing to Com_TxPduInfoInd */
} Com_IPduGroupInfoType;

/**   \brief  type used in Com_RxAccessInfo */
typedef struct sCom_RxAccessInfoType
{
  Com_InitValueUsedOfRxAccessInfoType InitValueUsedOfRxAccessInfo;  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_ConstValueUInt8,Com_ConstValueUInt16,Com_ConstValueUInt32,Com_ConstValueUInt64,Com_ConstValueSInt8,Com_ConstValueSInt16,Com_ConstValueSInt32,Com_ConstValueSInt64,Com_ConstValueFloat32,Com_ConstValueFloat64 */
  Com_ApplTypeOfRxAccessInfoType ApplTypeOfRxAccessInfo;  /**< Application data type. */
  Com_BitLengthOfRxAccessInfoType BitLengthOfRxAccessInfo;  /**< Bit length of the signal or group signal. */
  Com_BitPositionOfRxAccessInfoType BitPositionOfRxAccessInfo;  /**< Little endian bit position of the signal or group signal within the I-PDU. */
  Com_BufferIdxOfRxAccessInfoType BufferIdxOfRxAccessInfo;  /**< the index of the 0:1 relation pointing to Com_RxSigBufferUInt8,Com_RxSigBufferUInt16,Com_RxSigBufferUInt32,Com_RxSigBufferUInt64,Com_RxSigBufferZeroBit,Com_RxSigBufferSInt8,Com_RxSigBufferSInt16,Com_RxSigBufferSInt32,Com_RxSigBufferSInt64,Com_RxSigBufferFloat32,Com_RxSigBufferFloat64 */
  Com_BusAccOfRxAccessInfoType BusAccOfRxAccessInfo;  /**< BUS access algorithm for signal or group signal packing / un-packing. */
  Com_ByteLengthOfRxAccessInfoType ByteLengthOfRxAccessInfo;  /**< Byte length of the signal or group signal. */
  Com_BytePositionOfRxAccessInfoType BytePositionOfRxAccessInfo;  /**< Little endian byte position of the signal or group signal within the I-PDU. */
  Com_InitValueIdxOfRxAccessInfoType InitValueIdxOfRxAccessInfo;  /**< the index of the 0:1 relation pointing to Com_ConstValueUInt8,Com_ConstValueUInt16,Com_ConstValueUInt32,Com_ConstValueUInt64,Com_ConstValueSInt8,Com_ConstValueSInt16,Com_ConstValueSInt32,Com_ConstValueSInt64,Com_ConstValueFloat32,Com_ConstValueFloat64 */
  Com_RxPduInfoIdxOfRxAccessInfoType RxPduInfoIdxOfRxAccessInfo;  /**< the index of the 1:1 relation pointing to Com_RxPduInfo */
  Com_RxTOutInfoIdxOfRxAccessInfoType RxTOutInfoIdxOfRxAccessInfo;  /**< the index of the 0:1 relation pointing to Com_RxTOutInfo */
  Com_StartByteInPduPositionOfRxAccessInfoType StartByteInPduPositionOfRxAccessInfo;  /**< Start Byte position of the signal or group signal within the I-PDU. */
} Com_RxAccessInfoType;

/**   \brief  type used in Com_RxPduInfo */
typedef struct sCom_RxPduInfoType
{
  Com_IPduGroupInfoOfRxPduInfoIndUsedOfRxPduInfoType IPduGroupInfoOfRxPduInfoIndUsedOfRxPduInfo;  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_IPduGroupInfoOfRxPduInfoInd */
  Com_RxTOutInfoUsedOfRxPduInfoType RxTOutInfoUsedOfRxPduInfo;  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_RxTOutInfo */
  Com_RxDefPduBufferStartIdxOfRxPduInfoType RxDefPduBufferStartIdxOfRxPduInfo;  /**< the start index of the 0:n relation pointing to Com_RxDefPduBuffer */
  Com_RxSigInfoEndIdxOfRxPduInfoType RxSigInfoEndIdxOfRxPduInfo;  /**< the end index of the 0:n relation pointing to Com_RxSigInfo */
  Com_RxSigInfoStartIdxOfRxPduInfoType RxSigInfoStartIdxOfRxPduInfo;  /**< the start index of the 0:n relation pointing to Com_RxSigInfo */
  Com_RxTOutInfoIndEndIdxOfRxPduInfoType RxTOutInfoIndEndIdxOfRxPduInfo;  /**< the end index of the 0:n relation pointing to Com_RxTOutInfoInd */
  Com_RxTOutInfoIndStartIdxOfRxPduInfoType RxTOutInfoIndStartIdxOfRxPduInfo;  /**< the start index of the 0:n relation pointing to Com_RxTOutInfoInd */
  Com_TypeOfRxPduInfoType TypeOfRxPduInfo;  /**< Defines whether rx Pdu is a NORMAL or TP IPdu. */
} Com_RxPduInfoType;

/**   \brief  type used in Com_RxSigInfo */
typedef struct sCom_RxSigInfoType
{
  Com_RxAccessInfoIdxOfRxSigInfoType RxAccessInfoIdxOfRxSigInfo;  /**< the index of the 1:1 relation pointing to Com_RxAccessInfo */
  Com_RxTOutInfoIdxOfRxSigInfoType RxTOutInfoIdxOfRxSigInfo;  /**< the index of the 0:1 relation pointing to Com_RxTOutInfo */
  Com_SignalProcessingOfRxSigInfoType SignalProcessingOfRxSigInfo;
  Com_ValidDlcOfRxSigInfoType ValidDlcOfRxSigInfo;  /**< Minimum length of PDU required to completely receive the signal or signal group. */
} Com_RxSigInfoType;

/**   \brief  type used in Com_RxTOutInfo */
typedef struct sCom_RxTOutInfoType
{
  Com_CbkRxTOutFuncPtrIndEndIdxOfRxTOutInfoType CbkRxTOutFuncPtrIndEndIdxOfRxTOutInfo;  /**< the end index of the 0:n relation pointing to Com_CbkRxTOutFuncPtrInd */
  Com_CbkRxTOutFuncPtrIndStartIdxOfRxTOutInfoType CbkRxTOutFuncPtrIndStartIdxOfRxTOutInfo;  /**< the start index of the 0:n relation pointing to Com_CbkRxTOutFuncPtrInd */
  Com_FactorOfRxTOutInfoType FactorOfRxTOutInfo;  /**< Deadline monitoring timeout factor. */
  Com_FirstFactorOfRxTOutInfoType FirstFactorOfRxTOutInfo;  /**< Timeout factor for first deadline monitoring. */
  Com_RxPduInfoIdxOfRxTOutInfoType RxPduInfoIdxOfRxTOutInfo;  /**< the index of the 1:1 relation pointing to Com_RxPduInfo */
} Com_RxTOutInfoType;

/**   \brief  type used in Com_TxCyclicPdu */
typedef struct sCom_TxCyclicPduType
{
  uint8 Com_TxCyclicPduNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Com_TxCyclicPduType;

/**   \brief  type used in Com_TxModeFalse */
typedef struct sCom_TxModeFalseType
{
  Com_PeriodicOfTxModeFalseType PeriodicOfTxModeFalse;  /**< TRUE if transmission mode contains a cyclic part. */
} Com_TxModeFalseType;

/**   \brief  type used in Com_TxModeInfo */
typedef struct sCom_TxModeInfoType
{
  Com_InitModeOfTxModeInfoType InitModeOfTxModeInfo;  /**< Initial transmission mode selector of the Tx I-PDU. */
} Com_TxModeInfoType;

/**   \brief  type used in Com_TxModeTrue */
typedef struct sCom_TxModeTrueType
{
  Com_PeriodicOfTxModeTrueType PeriodicOfTxModeTrue;  /**< TRUE if transmission mode contains a cyclic part. */
} Com_TxModeTrueType;

/**   \brief  type used in Com_TxPduInfo */
typedef struct sCom_TxPduInfoType
{
  Com_TxPduInitValueUsedOfTxPduInfoType TxPduInitValueUsedOfTxPduInfo;  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_TxPduInitValue */
  Com_ExternalIdOfTxPduInfoType ExternalIdOfTxPduInfo;  /**< External ID used to call PduR_ComTransmit(). */
  Com_IPduGroupInfoOfTxPduInfoIndEndIdxOfTxPduInfoType IPduGroupInfoOfTxPduInfoIndEndIdxOfTxPduInfo;  /**< the end index of the 0:n relation pointing to Com_IPduGroupInfoOfTxPduInfoInd */
  Com_IPduGroupInfoOfTxPduInfoIndStartIdxOfTxPduInfoType IPduGroupInfoOfTxPduInfoIndStartIdxOfTxPduInfo;  /**< the start index of the 0:n relation pointing to Com_IPduGroupInfoOfTxPduInfoInd */
  Com_MetaDataLengthOfTxPduInfoType MetaDataLengthOfTxPduInfo;  /**< Length of MetaData. */
  Com_TxBufferLengthOfTxPduInfoType TxBufferLengthOfTxPduInfo;  /**< the number of relations pointing to Com_TxBuffer */
  Com_TxPduInitValueEndIdxOfTxPduInfoType TxPduInitValueEndIdxOfTxPduInfo;  /**< the end index of the 0:n relation pointing to Com_TxPduInitValue */
  Com_TxPduInitValueStartIdxOfTxPduInfoType TxPduInitValueStartIdxOfTxPduInfo;  /**< the start index of the 0:n relation pointing to Com_TxPduInitValue */
} Com_TxPduInfoType;

/**   \brief  type used in Com_TxSigInfo */
typedef struct sCom_TxSigInfoType
{
  Com_BitLengthOfTxSigInfoType BitLengthOfTxSigInfo;  /**< Bit length of the signal or group signal. */
  Com_BitPositionOfTxSigInfoType BitPositionOfTxSigInfo;  /**< Little endian bit position of the signal or group signal within the I-PDU. */
  Com_BusAccOfTxSigInfoType BusAccOfTxSigInfo;  /**< BUS access algorithm for signal or group signal packing / un-packing. */
  Com_StartByteInPduPositionOfTxSigInfoType StartByteInPduPositionOfTxSigInfo;  /**< Start Byte position of the signal or group signal within the I-PDU. */
  Com_TxBufferLengthOfTxSigInfoType TxBufferLengthOfTxSigInfo;  /**< the number of relations pointing to Com_TxBuffer */
  Com_TxBufferStartIdxOfTxSigInfoType TxBufferStartIdxOfTxSigInfo;  /**< the start index of the 0:n relation pointing to Com_TxBuffer */
  Com_TxPduInfoIdxOfTxSigInfoType TxPduInfoIdxOfTxSigInfo;  /**< the index of the 1:1 relation pointing to Com_TxPduInfo */
} Com_TxSigInfoType;

/** 
  \}
*/ 

/** 
  \defgroup  ComPCSymbolicStructTypes  Com Symbolic Struct Types (PRE_COMPILE)
  \brief  These structs are used in unions to have a symbol based data representation style.
  \{
*/ 
/**   \brief  type to be used as symbolic data element access to Com_HandleRxPduDeferred */
typedef struct Com_HandleRxPduDeferredStructSTag
{
  Com_HandleRxPduDeferredType ABS3_oC03_for_EL_CAN_V2_1_5328da88_Rx;
  Com_HandleRxPduDeferredType BCM10_oC03_for_EL_CAN_V2_1_8175742c_Rx;
  Com_HandleRxPduDeferredType BCM17_oC03_for_EL_CAN_V2_1_e4ac4a6c_Rx;
  Com_HandleRxPduDeferredType BCM23_oC03_for_EL_CAN_V2_1_cee8e051_Rx;
  Com_HandleRxPduDeferredType BMS1_oC03_for_EL_CAN_V2_1_ab80ae92_Rx;
  Com_HandleRxPduDeferredType BMS17_oC03_for_EL_CAN_V2_1_be27a4ae_Rx;
  Com_HandleRxPduDeferredType CSA1_oC03_for_EL_CAN_V2_1_ffb47aea_Rx;
  Com_HandleRxPduDeferredType EEM1_oC03_for_EL_CAN_V2_1_5bdcd994_Rx;
  Com_HandleRxPduDeferredType GW1_oC03_for_EL_CAN_V2_1_48654b76_Rx;
  Com_HandleRxPduDeferredType HUT34_oC03_for_EL_CAN_V2_1_6fae3f7a_Rx;
  Com_HandleRxPduDeferredType HUT54_oC03_for_EL_CAN_V2_1_82644d00_Rx;
  Com_HandleRxPduDeferredType IP2_oC03_for_EL_CAN_V2_1_65941076_Rx;
  Com_HandleRxPduDeferredType MCU_5_oC03_for_EL_CAN_V2_1_002cb201_Rx;
  Com_HandleRxPduDeferredType OBC3_oC03_for_EL_CAN_V2_1_158aa3d5_Rx;
  Com_HandleRxPduDeferredType PEPS2_oC03_for_EL_CAN_V2_1_d41abfa7_Rx;
  Com_HandleRxPduDeferredType RMCU4_oC03_for_EL_CAN_V2_1_55159990_Rx;
  Com_HandleRxPduDeferredType R_PBOX1_oC03_for_EL_CAN_V2_1_7854cc6e_Rx;
  Com_HandleRxPduDeferredType VCU2_oC03_for_EL_CAN_V2_1_bea872d3_Rx;
  Com_HandleRxPduDeferredType VCU3_oC03_for_EL_CAN_V2_1_a9801613_Rx;
  Com_HandleRxPduDeferredType VCU6_oC03_for_EL_CAN_V2_1_e209e1d3_Rx;
} Com_HandleRxPduDeferredStructSType;

/**   \brief  type to be used as symbolic data element access to Com_RxDefPduBuffer */
typedef struct Com_RxDefPduBufferStructSTag
{
  Com_RxDefPduBufferType ABS3_oC03_for_EL_CAN_V2_1_5328da88_Rx[8];
  Com_RxDefPduBufferType BCM10_oC03_for_EL_CAN_V2_1_8175742c_Rx[8];
  Com_RxDefPduBufferType BCM17_oC03_for_EL_CAN_V2_1_e4ac4a6c_Rx[8];
  Com_RxDefPduBufferType BCM23_oC03_for_EL_CAN_V2_1_cee8e051_Rx[8];
  Com_RxDefPduBufferType BMS1_oC03_for_EL_CAN_V2_1_ab80ae92_Rx[8];
  Com_RxDefPduBufferType BMS17_oC03_for_EL_CAN_V2_1_be27a4ae_Rx[8];
  Com_RxDefPduBufferType CSA1_oC03_for_EL_CAN_V2_1_ffb47aea_Rx[8];
  Com_RxDefPduBufferType EEM1_oC03_for_EL_CAN_V2_1_5bdcd994_Rx[8];
  Com_RxDefPduBufferType GW1_oC03_for_EL_CAN_V2_1_48654b76_Rx[8];
  Com_RxDefPduBufferType HUT34_oC03_for_EL_CAN_V2_1_6fae3f7a_Rx[8];
  Com_RxDefPduBufferType HUT54_oC03_for_EL_CAN_V2_1_82644d00_Rx[8];
  Com_RxDefPduBufferType IP2_oC03_for_EL_CAN_V2_1_65941076_Rx[8];
  Com_RxDefPduBufferType MCU_5_oC03_for_EL_CAN_V2_1_002cb201_Rx[8];
  Com_RxDefPduBufferType OBC3_oC03_for_EL_CAN_V2_1_158aa3d5_Rx[8];
  Com_RxDefPduBufferType PEPS2_oC03_for_EL_CAN_V2_1_d41abfa7_Rx[8];
  Com_RxDefPduBufferType RMCU4_oC03_for_EL_CAN_V2_1_55159990_Rx[8];
  Com_RxDefPduBufferType R_PBOX1_oC03_for_EL_CAN_V2_1_7854cc6e_Rx[8];
  Com_RxDefPduBufferType VCU2_oC03_for_EL_CAN_V2_1_bea872d3_Rx[8];
  Com_RxDefPduBufferType VCU3_oC03_for_EL_CAN_V2_1_a9801613_Rx[8];
  Com_RxDefPduBufferType VCU6_oC03_for_EL_CAN_V2_1_e209e1d3_Rx[8];
} Com_RxDefPduBufferStructSType;

/** 
  \}
*/ 

/** 
  \defgroup  ComPCUnionIndexAndSymbolTypes  Com Union Index And Symbol Types (PRE_COMPILE)
  \brief  These unions are used to access arrays in an index and symbol based style.
  \{
*/ 
/**   \brief  type to access Com_HandleRxPduDeferred in an index and symbol based style. */
typedef union Com_HandleRxPduDeferredUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  Com_HandleRxPduDeferredType raw[20];
  Com_HandleRxPduDeferredStructSType str;
} Com_HandleRxPduDeferredUType;

/**   \brief  type to access Com_RxDefPduBuffer in an index and symbol based style. */
typedef union Com_RxDefPduBufferUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  Com_RxDefPduBufferType raw[160];
  Com_RxDefPduBufferStructSType str;
} Com_RxDefPduBufferUType;

/** 
  \}
*/ 

/** 
  \defgroup  ComPCRootPointerTypes  Com Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to Com_AlwaysActiveTxComIPdus */
typedef P2CONST(Com_AlwaysActiveTxComIPdusType, TYPEDEF, COM_CONST) Com_AlwaysActiveTxComIPdusPtrType;

/**   \brief  type used to point to Com_CbkRxTOutFuncPtr */
typedef P2CONST(ComCbkRxTOutType, TYPEDEF, COM_CONST) Com_CbkRxTOutFuncPtrPtrType;

/**   \brief  type used to point to Com_CbkRxTOutFuncPtrInd */
typedef P2CONST(Com_CbkRxTOutFuncPtrIndType, TYPEDEF, COM_CONST) Com_CbkRxTOutFuncPtrIndPtrType;

/**   \brief  type used to point to Com_ConstValueUInt16 */
typedef P2CONST(Com_ConstValueUInt16Type, TYPEDEF, COM_CONST) Com_ConstValueUInt16PtrType;

/**   \brief  type used to point to Com_ConstValueUInt32 */
typedef P2CONST(Com_ConstValueUInt32Type, TYPEDEF, COM_CONST) Com_ConstValueUInt32PtrType;

/**   \brief  type used to point to Com_ConstValueUInt8 */
typedef P2CONST(Com_ConstValueUInt8Type, TYPEDEF, COM_CONST) Com_ConstValueUInt8PtrType;

/**   \brief  type used to point to Com_CurrentTxMode */
typedef P2VAR(Com_CurrentTxModeType, TYPEDEF, COM_VAR_NOINIT) Com_CurrentTxModePtrType;

/**   \brief  type used to point to Com_CycleTimeCnt */
typedef P2VAR(Com_CycleTimeCntType, TYPEDEF, COM_VAR_NOINIT) Com_CycleTimeCntPtrType;

/**   \brief  type used to point to Com_CyclicSendRequest */
typedef P2VAR(Com_CyclicSendRequestType, TYPEDEF, COM_VAR_NOINIT) Com_CyclicSendRequestPtrType;

/**   \brief  type used to point to Com_HandleRxPduDeferred */
typedef P2VAR(Com_HandleRxPduDeferredType, TYPEDEF, COM_VAR_NOINIT) Com_HandleRxPduDeferredPtrType;

/**   \brief  type used to point to Com_IPduGroupInfo */
typedef P2CONST(Com_IPduGroupInfoType, TYPEDEF, COM_CONST) Com_IPduGroupInfoPtrType;

/**   \brief  type used to point to Com_IPduGroupInfoOfRxPduInfoInd */
typedef P2CONST(Com_IPduGroupInfoOfRxPduInfoIndType, TYPEDEF, COM_CONST) Com_IPduGroupInfoOfRxPduInfoIndPtrType;

/**   \brief  type used to point to Com_IPduGroupInfoOfTxPduInfoInd */
typedef P2CONST(Com_IPduGroupInfoOfTxPduInfoIndType, TYPEDEF, COM_CONST) Com_IPduGroupInfoOfTxPduInfoIndPtrType;

/**   \brief  type used to point to Com_IPduGroupInfoToSubIPduGroupsInd */
typedef P2CONST(Com_IPduGroupInfoToSubIPduGroupsIndType, TYPEDEF, COM_CONST) Com_IPduGroupInfoToSubIPduGroupsIndPtrType;

/**   \brief  type used to point to Com_IPduGroupState */
typedef P2VAR(Com_IPduGroupStateType, TYPEDEF, COM_VAR_NOINIT) Com_IPduGroupStatePtrType;

/**   \brief  type used to point to Com_Initialized */
typedef P2VAR(Com_InitializedType, TYPEDEF, COM_VAR_ZERO_INIT) Com_InitializedPtrType;

/**   \brief  type used to point to Com_RxAccessInfo */
typedef P2CONST(Com_RxAccessInfoType, TYPEDEF, COM_CONST) Com_RxAccessInfoPtrType;

/**   \brief  type used to point to Com_RxAccessInfoInd */
typedef P2CONST(Com_RxAccessInfoIndType, TYPEDEF, COM_CONST) Com_RxAccessInfoIndPtrType;

/**   \brief  type used to point to Com_RxCbkFuncPtr */
typedef P2CONST(ComRxCbkType, TYPEDEF, COM_CONST) Com_RxCbkFuncPtrPtrType;

/**   \brief  type used to point to Com_RxDeadlineMonitoringISRLockCounter */
typedef P2VAR(Com_RxDeadlineMonitoringISRLockCounterType, TYPEDEF, COM_VAR_NOINIT) Com_RxDeadlineMonitoringISRLockCounterPtrType;

/**   \brief  type used to point to Com_RxDefPduBuffer */
typedef P2VAR(Com_RxDefPduBufferType, TYPEDEF, COM_VAR_NOINIT) Com_RxDefPduBufferPtrType;

/**   \brief  type used to point to Com_RxDeferredFctPtrCache */
typedef P2VAR(Com_RxDeferredFctPtrCacheType, TYPEDEF, COM_VAR_NOINIT) Com_RxDeferredFctPtrCachePtrType;

/**   \brief  type used to point to Com_RxDeferredProcessingISRLockCounter */
typedef P2VAR(Com_RxDeferredProcessingISRLockCounterType, TYPEDEF, COM_VAR_NOINIT) Com_RxDeferredProcessingISRLockCounterPtrType;

/**   \brief  type used to point to Com_RxDlMonDivisorCounter */
typedef P2VAR(Com_RxDlMonDivisorCounterType, TYPEDEF, COM_VAR_NOINIT) Com_RxDlMonDivisorCounterPtrType;

/**   \brief  type used to point to Com_RxIPduGroupISRLockCounter */
typedef P2VAR(Com_RxIPduGroupISRLockCounterType, TYPEDEF, COM_VAR_NOINIT) Com_RxIPduGroupISRLockCounterPtrType;

/**   \brief  type used to point to Com_RxPduDmState */
typedef P2VAR(Com_RxPduDmStateType, TYPEDEF, COM_VAR_NOINIT) Com_RxPduDmStatePtrType;

/**   \brief  type used to point to Com_RxPduGrpActive */
typedef P2VAR(Com_RxPduGrpActiveType, TYPEDEF, COM_VAR_NOINIT) Com_RxPduGrpActivePtrType;

/**   \brief  type used to point to Com_RxPduInfo */
typedef P2CONST(Com_RxPduInfoType, TYPEDEF, COM_CONST) Com_RxPduInfoPtrType;

/**   \brief  type used to point to Com_RxPduInfoInd */
typedef P2CONST(Com_RxPduInfoIndType, TYPEDEF, COM_CONST) Com_RxPduInfoIndPtrType;

/**   \brief  type used to point to Com_RxSigBufferUInt16 */
typedef P2VAR(Com_RxSigBufferUInt16Type, TYPEDEF, COM_VAR_NOINIT) Com_RxSigBufferUInt16PtrType;

/**   \brief  type used to point to Com_RxSigBufferUInt32 */
typedef P2VAR(Com_RxSigBufferUInt32Type, TYPEDEF, COM_VAR_NOINIT) Com_RxSigBufferUInt32PtrType;

/**   \brief  type used to point to Com_RxSigBufferUInt8 */
typedef P2VAR(Com_RxSigBufferUInt8Type, TYPEDEF, COM_VAR_NOINIT) Com_RxSigBufferUInt8PtrType;

/**   \brief  type used to point to Com_RxSigInfo */
typedef P2CONST(Com_RxSigInfoType, TYPEDEF, COM_CONST) Com_RxSigInfoPtrType;

/**   \brief  type used to point to Com_RxTOutCnt */
typedef P2VAR(Com_RxTOutCntType, TYPEDEF, COM_VAR_NOINIT) Com_RxTOutCntPtrType;

/**   \brief  type used to point to Com_RxTOutInfo */
typedef P2CONST(Com_RxTOutInfoType, TYPEDEF, COM_CONST) Com_RxTOutInfoPtrType;

/**   \brief  type used to point to Com_RxTOutInfoInd */
typedef P2CONST(Com_RxTOutInfoIndType, TYPEDEF, COM_CONST) Com_RxTOutInfoIndPtrType;

/**   \brief  type used to point to Com_TransmitRequest */
typedef P2VAR(Com_TransmitRequestType, TYPEDEF, COM_VAR_NOINIT) Com_TransmitRequestPtrType;

/**   \brief  type used to point to Com_TxBuffer */
typedef P2VAR(Com_TxBufferType, TYPEDEF, COM_VAR_NOINIT) Com_TxBufferPtrType;

/**   \brief  type used to point to Com_TxCycleCounterDivisorCounter */
typedef P2VAR(Com_TxCycleCounterDivisorCounterType, TYPEDEF, COM_VAR_NOINIT) Com_TxCycleCounterDivisorCounterPtrType;

/**   \brief  type used to point to Com_TxCyclicPdu */
typedef P2CONST(Com_TxCyclicPduType, TYPEDEF, COM_CONST) Com_TxCyclicPduPtrType;

/**   \brief  type used to point to Com_TxCyclicProcessingISRLockCounter */
typedef P2VAR(Com_TxCyclicProcessingISRLockCounterType, TYPEDEF, COM_VAR_NOINIT) Com_TxCyclicProcessingISRLockCounterPtrType;

/**   \brief  type used to point to Com_TxIPduGroupISRLockCounter */
typedef P2VAR(Com_TxIPduGroupISRLockCounterType, TYPEDEF, COM_VAR_NOINIT) Com_TxIPduGroupISRLockCounterPtrType;

/**   \brief  type used to point to Com_TxModeFalse */
typedef P2CONST(Com_TxModeFalseType, TYPEDEF, COM_CONST) Com_TxModeFalsePtrType;

/**   \brief  type used to point to Com_TxModeInfo */
typedef P2CONST(Com_TxModeInfoType, TYPEDEF, COM_CONST) Com_TxModeInfoPtrType;

/**   \brief  type used to point to Com_TxModeTrue */
typedef P2CONST(Com_TxModeTrueType, TYPEDEF, COM_CONST) Com_TxModeTruePtrType;

/**   \brief  type used to point to Com_TxPduGrpActive */
typedef P2VAR(Com_TxPduGrpActiveType, TYPEDEF, COM_VAR_NOINIT) Com_TxPduGrpActivePtrType;

/**   \brief  type used to point to Com_TxPduInfo */
typedef P2CONST(Com_TxPduInfoType, TYPEDEF, COM_CONST) Com_TxPduInfoPtrType;

/**   \brief  type used to point to Com_TxPduInfoInd */
typedef P2CONST(Com_TxPduInfoIndType, TYPEDEF, COM_CONST) Com_TxPduInfoIndPtrType;

/**   \brief  type used to point to Com_TxPduInitValue */
typedef P2CONST(Com_TxPduInitValueType, TYPEDEF, COM_CONST) Com_TxPduInitValuePtrType;

/**   \brief  type used to point to Com_TxProcessingISRLockCounter */
typedef P2VAR(Com_TxProcessingISRLockCounterType, TYPEDEF, COM_VAR_NOINIT) Com_TxProcessingISRLockCounterPtrType;

/**   \brief  type used to point to Com_TxSduLength */
typedef P2VAR(Com_TxSduLengthType, TYPEDEF, COM_VAR_NOINIT) Com_TxSduLengthPtrType;

/**   \brief  type used to point to Com_TxSigInfo */
typedef P2CONST(Com_TxSigInfoType, TYPEDEF, COM_CONST) Com_TxSigInfoPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  ComPCRootValueTypes  Com Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in Com_PCConfig */
typedef struct sCom_PCConfigType
{
  uint8 Com_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Com_PCConfigType;

typedef Com_PCConfigType Com_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/** 
  \}
*/ 



/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  Com_CbkRxTOutFuncPtr
**********************************************************************************************************************/
/** 
  \var    Com_CbkRxTOutFuncPtr
  \brief  Function pointer table containing configured Rx timeout notifications for signals and signal groups.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComCbkRxTOutType, COM_CONST) Com_CbkRxTOutFuncPtr[45];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_ConstValueUInt16
**********************************************************************************************************************/
/** 
  \var    Com_ConstValueUInt16
  \brief  Optimized array of commonly used values like initial or invalid values. (UINT16)
*/ 
#define COM_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Com_ConstValueUInt16Type, COM_CONST) Com_ConstValueUInt16[1];
#define COM_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_ConstValueUInt32
**********************************************************************************************************************/
/** 
  \var    Com_ConstValueUInt32
  \brief  Optimized array of commonly used values like initial or invalid values. (UINT32)
*/ 
#define COM_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Com_ConstValueUInt32Type, COM_CONST) Com_ConstValueUInt32[1];
#define COM_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_ConstValueUInt8
**********************************************************************************************************************/
/** 
  \var    Com_ConstValueUInt8
  \brief  Optimized array of commonly used values like initial or invalid values. (BOOLEAN, UINT8)
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Com_ConstValueUInt8Type, COM_CONST) Com_ConstValueUInt8[1];
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_IPduGroupInfo
**********************************************************************************************************************/
/** 
  \var    Com_IPduGroupInfo
  \brief  Contains all I-Pdu Group relevant information
  \details
  Element                 Description
  TxPduInfoIndUsed        TRUE, if the 0:n relation has 1 relation pointing to Com_TxPduInfoInd
  RxPduInfoIndEndIdx      the end index of the 0:n relation pointing to Com_RxPduInfoInd
  RxPduInfoIndStartIdx    the start index of the 0:n relation pointing to Com_RxPduInfoInd
  TxPduInfoIndEndIdx      the end index of the 0:n relation pointing to Com_TxPduInfoInd
  TxPduInfoIndStartIdx    the start index of the 0:n relation pointing to Com_TxPduInfoInd
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Com_IPduGroupInfoType, COM_CONST) Com_IPduGroupInfo[2];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_IPduGroupInfoOfRxPduInfoInd
**********************************************************************************************************************/
/** 
  \var    Com_IPduGroupInfoOfRxPduInfoInd
  \brief  the indexes of the 1:1 sorted relation pointing to Com_IPduGroupInfo
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Com_IPduGroupInfoOfRxPduInfoIndType, COM_CONST) Com_IPduGroupInfoOfRxPduInfoInd[20];
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxAccessInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxAccessInfo
  \brief  Contains all signal layout information necessary for signal access within an I-PDU.
  \details
  Element                   Description
  InitValueUsed             TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_ConstValueUInt8,Com_ConstValueUInt16,Com_ConstValueUInt32,Com_ConstValueUInt64,Com_ConstValueSInt8,Com_ConstValueSInt16,Com_ConstValueSInt32,Com_ConstValueSInt64,Com_ConstValueFloat32,Com_ConstValueFloat64
  ApplType                  Application data type.
  BitLength                 Bit length of the signal or group signal.
  BitPosition               Little endian bit position of the signal or group signal within the I-PDU.
  BufferIdx                 the index of the 0:1 relation pointing to Com_RxSigBufferUInt8,Com_RxSigBufferUInt16,Com_RxSigBufferUInt32,Com_RxSigBufferUInt64,Com_RxSigBufferZeroBit,Com_RxSigBufferSInt8,Com_RxSigBufferSInt16,Com_RxSigBufferSInt32,Com_RxSigBufferSInt64,Com_RxSigBufferFloat32,Com_RxSigBufferFloat64
  BusAcc                    BUS access algorithm for signal or group signal packing / un-packing.
  ByteLength                Byte length of the signal or group signal.
  BytePosition              Little endian byte position of the signal or group signal within the I-PDU.
  InitValueIdx              the index of the 0:1 relation pointing to Com_ConstValueUInt8,Com_ConstValueUInt16,Com_ConstValueUInt32,Com_ConstValueUInt64,Com_ConstValueSInt8,Com_ConstValueSInt16,Com_ConstValueSInt32,Com_ConstValueSInt64,Com_ConstValueFloat32,Com_ConstValueFloat64
  RxPduInfoIdx              the index of the 1:1 relation pointing to Com_RxPduInfo
  RxTOutInfoIdx             the index of the 0:1 relation pointing to Com_RxTOutInfo
  StartByteInPduPosition    Start Byte position of the signal or group signal within the I-PDU.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Com_RxAccessInfoType, COM_CONST) Com_RxAccessInfo[55];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxAccessInfoInd
**********************************************************************************************************************/
/** 
  \var    Com_RxAccessInfoInd
  \brief  the indexes of the 1:1 sorted relation pointing to Com_RxAccessInfo
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Com_RxAccessInfoIndType, COM_CONST) Com_RxAccessInfoInd[55];
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxCbkFuncPtr
**********************************************************************************************************************/
/** 
  \var    Com_RxCbkFuncPtr
  \brief  Function pointer table containing configured notification and invalid notifications function pointer for signals and signal groups.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComRxCbkType, COM_CONST) Com_RxCbkFuncPtr[55];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxPduInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxPduInfo
  \brief  Contains all relevant common information for Rx I-PDUs.
  \details
  Element                            Description
  IPduGroupInfoOfRxPduInfoIndUsed    TRUE, if the 0:n relation has 1 relation pointing to Com_IPduGroupInfoOfRxPduInfoInd
  RxTOutInfoUsed                     TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_RxTOutInfo
  RxDefPduBufferStartIdx             the start index of the 0:n relation pointing to Com_RxDefPduBuffer
  RxSigInfoEndIdx                    the end index of the 0:n relation pointing to Com_RxSigInfo
  RxSigInfoStartIdx                  the start index of the 0:n relation pointing to Com_RxSigInfo
  RxTOutInfoIndEndIdx                the end index of the 0:n relation pointing to Com_RxTOutInfoInd
  RxTOutInfoIndStartIdx              the start index of the 0:n relation pointing to Com_RxTOutInfoInd
  Type                               Defines whether rx Pdu is a NORMAL or TP IPdu.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Com_RxPduInfoType, COM_CONST) Com_RxPduInfo[20];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxSigInfo
  \brief  Contains all relevant information for Rx signals.
  \details
  Element             Description
  RxAccessInfoIdx     the index of the 1:1 relation pointing to Com_RxAccessInfo
  RxTOutInfoIdx       the index of the 0:1 relation pointing to Com_RxTOutInfo
  SignalProcessing
  ValidDlc            Minimum length of PDU required to completely receive the signal or signal group.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Com_RxSigInfoType, COM_CONST) Com_RxSigInfo[55];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxTOutInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxTOutInfo
  \brief  Contains all relevant information for signal based and I-PDu based Rx deadline monitoring.
  \details
  Element                        Description
  CbkRxTOutFuncPtrIndEndIdx      the end index of the 0:n relation pointing to Com_CbkRxTOutFuncPtrInd
  CbkRxTOutFuncPtrIndStartIdx    the start index of the 0:n relation pointing to Com_CbkRxTOutFuncPtrInd
  Factor                         Deadline monitoring timeout factor.
  FirstFactor                    Timeout factor for first deadline monitoring.
  RxPduInfoIdx                   the index of the 1:1 relation pointing to Com_RxPduInfo
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Com_RxTOutInfoType, COM_CONST) Com_RxTOutInfo[19];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxModeFalse
**********************************************************************************************************************/
/** 
  \var    Com_TxModeFalse
  \brief  Contains all relevant information for transmission mode false.
  \details
  Element     Description
  Periodic    TRUE if transmission mode contains a cyclic part.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Com_TxModeFalseType, COM_CONST) Com_TxModeFalse[2];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxModeInfo
**********************************************************************************************************************/
/** 
  \var    Com_TxModeInfo
  \brief  Contains all relevant information for transmission mode handling.
  \details
  Element     Description
  InitMode    Initial transmission mode selector of the Tx I-PDU.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Com_TxModeInfoType, COM_CONST) Com_TxModeInfo[2];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxModeTrue
**********************************************************************************************************************/
/** 
  \var    Com_TxModeTrue
  \brief  Contains all relevant information for transmission mode true.
  \details
  Element     Description
  Periodic    TRUE if transmission mode contains a cyclic part.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Com_TxModeTrueType, COM_CONST) Com_TxModeTrue[2];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxPduInfo
**********************************************************************************************************************/
/** 
  \var    Com_TxPduInfo
  \brief  Contains all relevant information for Tx I-PDUs.
  \details
  Element                                Description
  TxPduInitValueUsed                     TRUE, if the 0:n relation has 1 relation pointing to Com_TxPduInitValue
  ExternalId                             External ID used to call PduR_ComTransmit().
  IPduGroupInfoOfTxPduInfoIndEndIdx      the end index of the 0:n relation pointing to Com_IPduGroupInfoOfTxPduInfoInd
  IPduGroupInfoOfTxPduInfoIndStartIdx    the start index of the 0:n relation pointing to Com_IPduGroupInfoOfTxPduInfoInd
  MetaDataLength                         Length of MetaData.
  TxBufferLength                         the number of relations pointing to Com_TxBuffer
  TxPduInitValueEndIdx                   the end index of the 0:n relation pointing to Com_TxPduInitValue
  TxPduInitValueStartIdx                 the start index of the 0:n relation pointing to Com_TxPduInitValue
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Com_TxPduInfoType, COM_CONST) Com_TxPduInfo[2];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxPduInitValue
**********************************************************************************************************************/
/** 
  \var    Com_TxPduInitValue
  \brief  Initial values used for Tx I-PDU buffer initialization.
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Com_TxPduInitValueType, COM_CONST) Com_TxPduInitValue[14];
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxSigInfo
**********************************************************************************************************************/
/** 
  \var    Com_TxSigInfo
  \brief  Contains all relevant information for Tx signals and group signals.
  \details
  Element                   Description
  BitLength                 Bit length of the signal or group signal.
  BitPosition               Little endian bit position of the signal or group signal within the I-PDU.
  BusAcc                    BUS access algorithm for signal or group signal packing / un-packing.
  StartByteInPduPosition    Start Byte position of the signal or group signal within the I-PDU.
  TxBufferLength            the number of relations pointing to Com_TxBuffer
  TxBufferStartIdx          the start index of the 0:n relation pointing to Com_TxBuffer
  TxPduInfoIdx              the index of the 1:1 relation pointing to Com_TxPduInfo
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Com_TxSigInfoType, COM_CONST) Com_TxSigInfo[12];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_CurrentTxMode
**********************************************************************************************************************/
/** 
  \var    Com_CurrentTxMode
  \brief  Current transmission mode state of all Tx I-PDUs.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_CurrentTxModeType, COM_VAR_NOINIT) Com_CurrentTxMode[2];
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_CycleTimeCnt
**********************************************************************************************************************/
/** 
  \var    Com_CycleTimeCnt
  \brief  Current counter value of cyclic transmission.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_CycleTimeCntType, COM_VAR_NOINIT) Com_CycleTimeCnt[2];
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_CyclicSendRequest
**********************************************************************************************************************/
/** 
  \var    Com_CyclicSendRequest
  \brief  Cyclic send request flag used to indicate cyclic transmission mode for all Tx I-PDU.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_CyclicSendRequestType, COM_VAR_NOINIT) Com_CyclicSendRequest[2];
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_HandleRxPduDeferred
**********************************************************************************************************************/
/** 
  \var    Com_HandleRxPduDeferred
  \brief  Array indicating received Rx I-PDUs to be processed deferred within the next call of Com_MainfunctionRx().
*/ 
#define COM_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_HandleRxPduDeferredUType, COM_VAR_NOINIT) Com_HandleRxPduDeferred;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define COM_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_IPduGroupState
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_IPduGroupStateType, COM_VAR_NOINIT) Com_IPduGroupState[2];
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_Initialized
**********************************************************************************************************************/
/** 
  \var    Com_Initialized
  \brief  Initialization state of Com. TRUE, if Com_Init() has been called, else FALSE.
*/ 
#define COM_START_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_InitializedType, COM_VAR_ZERO_INIT) Com_Initialized;
#define COM_STOP_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxDeadlineMonitoringISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_RxDeadlineMonitoringISRLockCounterType, COM_VAR_NOINIT) Com_RxDeadlineMonitoringISRLockCounter;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxDefPduBuffer
**********************************************************************************************************************/
/** 
  \var    Com_RxDefPduBuffer
  \brief  Rx I-PDU buffer for deferred signal processing.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_RxDefPduBufferUType, COM_VAR_NOINIT) Com_RxDefPduBuffer;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxDeferredFctPtrCache
**********************************************************************************************************************/
/** 
  \var    Com_RxDeferredFctPtrCache
  \brief  Cache for deferred Rx (invalid) notification.
*/ 
#define COM_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_RxDeferredFctPtrCacheType, COM_VAR_NOINIT) Com_RxDeferredFctPtrCache[1];
#define COM_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxDeferredProcessingISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_RxDeferredProcessingISRLockCounterType, COM_VAR_NOINIT) Com_RxDeferredProcessingISRLockCounter;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxDlMonDivisorCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_RxDlMonDivisorCounterType, COM_VAR_NOINIT) Com_RxDlMonDivisorCounter;
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxIPduGroupISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_RxIPduGroupISRLockCounterType, COM_VAR_NOINIT) Com_RxIPduGroupISRLockCounter;
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxPduDmState
**********************************************************************************************************************/
/** 
  \var    Com_RxPduDmState
  \brief  Rx I-PDU based deadline monitoring state (started/stopped) of the corresponding I-PDU-Group.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_RxPduDmStateType, COM_VAR_NOINIT) Com_RxPduDmState[19];
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxPduGrpActive
**********************************************************************************************************************/
/** 
  \var    Com_RxPduGrpActive
  \brief  Rx I-PDU based state (started/stopped) of the corresponding I-PDU-Group.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_RxPduGrpActiveType, COM_VAR_NOINIT) Com_RxPduGrpActive[20];
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigBufferUInt16
**********************************************************************************************************************/
/** 
  \var    Com_RxSigBufferUInt16
  \brief  Rx Signal and Group Signal Buffer. (UINT16)
*/ 
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_RxSigBufferUInt16Type, COM_VAR_NOINIT) Com_RxSigBufferUInt16[4];
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigBufferUInt32
**********************************************************************************************************************/
/** 
  \var    Com_RxSigBufferUInt32
  \brief  Rx Signal and Group Signal Buffer. (UINT32)
*/ 
#define COM_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_RxSigBufferUInt32Type, COM_VAR_NOINIT) Com_RxSigBufferUInt32[1];
#define COM_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigBufferUInt8
**********************************************************************************************************************/
/** 
  \var    Com_RxSigBufferUInt8
  \brief  Rx Signal and Group Signal Buffer. (BOOLEAN, UINT8)
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_RxSigBufferUInt8Type, COM_VAR_NOINIT) Com_RxSigBufferUInt8[50];
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxTOutCnt
**********************************************************************************************************************/
/** 
  \var    Com_RxTOutCnt
  \brief  This array holds timeout counters for all Rx timeout objects.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_RxTOutCntType, COM_VAR_NOINIT) Com_RxTOutCnt[19];
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TransmitRequest
**********************************************************************************************************************/
/** 
  \var    Com_TransmitRequest
  \brief  Transmit request flag used for decoupled Tx I-PDU tranmission.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_TransmitRequestType, COM_VAR_NOINIT) Com_TransmitRequest[2];
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxBuffer
**********************************************************************************************************************/
/** 
  \var    Com_TxBuffer
  \brief  Shared uint8 buffer for Tx I-PDUs and ComSignalGroup shadow buffer.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_TxBufferType, COM_VAR_NOINIT) Com_TxBuffer[14];
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxCycleCounterDivisorCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_TxCycleCounterDivisorCounterType, COM_VAR_NOINIT) Com_TxCycleCounterDivisorCounter;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxCyclicProcessingISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_TxCyclicProcessingISRLockCounterType, COM_VAR_NOINIT) Com_TxCyclicProcessingISRLockCounter;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxIPduGroupISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_TxIPduGroupISRLockCounterType, COM_VAR_NOINIT) Com_TxIPduGroupISRLockCounter;
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxPduGrpActive
**********************************************************************************************************************/
/** 
  \var    Com_TxPduGrpActive
  \brief  Tx I-PDU based state (started/stopped) of the corresponding I-PDU-Group.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_TxPduGrpActiveType, COM_VAR_NOINIT) Com_TxPduGrpActive[2];
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxProcessingISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_TxProcessingISRLockCounterType, COM_VAR_NOINIT) Com_TxProcessingISRLockCounter;
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxSduLength
**********************************************************************************************************************/
/** 
  \var    Com_TxSduLength
  \brief  This var Array contains the Com Ipdu Length.
*/ 
#define COM_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_TxSduLengthType, COM_VAR_NOINIT) Com_TxSduLength[2];
#define COM_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



/**********************************************************************************************************************
  RECEIVE MACRO API
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/


/* User Config File Start */

/* User Config File End */


#endif  /* COM_CFG_H */
/**********************************************************************************************************************
  END OF FILE: Com_Cfg.h
**********************************************************************************************************************/

