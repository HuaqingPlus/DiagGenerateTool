//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2015] Visteon Corporation
// All Rights Reserved.
//
// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
// under all copyright laws to protect this work as a published work, when appropriate.
// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
// without the written authorization of Visteon Corporation.
//
//---------------------------------------------------------------------------------------------------------------------
#ifndef ECUMEXT_H
#define ECUMEXT_H

#include "Rte_Type.h"
//----------------------------------------------------------------------------------------------------------------------
// Included files
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
// Constant data
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
// Exported type
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
// Exported data
//----------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------
// Constant exported data
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
// Exported Macros
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
// Exported functions
//----------------------------------------------------------------------------------------------------------------------
extern void NvM_MultiBlockJobEndNotification(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult);

extern void EcuMExt_IGNIntDetected (void);
extern void EcuMExt_DisplayFunDetected (void);
extern void EcuMExt_ILLInputDetected (void);
extern void EcuMExt_OvervoltageDetected (void);
extern void EcuMExt_VCANRxIntDetected (void);
extern void EcumStateEnterFullRun(void);
//extern Std_ReturnType EcuMExt_GetKeyPos (EKeyPos *KeyPosPtr); /* Qiuhuaqing Modify,  To be Release after NVM Finished */
extern boolean EcuMExt_GetNvmReadAllStatus(void);
extern void EcuMExt_ClrReadAllStatus(void);
extern void VCANRXPinToEINT3(void);
extern void IGNIntToEINT7(void);
extern void ILLInputToEINT8(void);
extern void DisplayFunToEINT13(void);

#endif  // ECUMEXT_H
