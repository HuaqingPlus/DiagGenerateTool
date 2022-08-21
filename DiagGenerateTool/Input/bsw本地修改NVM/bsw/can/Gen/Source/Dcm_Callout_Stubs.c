
/**********************************************************************************************************************
  COPYRIGHT
-----------------------------------------------------------------------------------------------------------------------
  \par      copyright
  \verbatim
  Copyright (c) 2019 by Vector Informatik GmbH.                                                  All rights reserved.

                This software is copyright protected and proprietary to Vector Informatik GmbH.
                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
                All other rights remain with Vector Informatik GmbH.
  \endverbatim
-----------------------------------------------------------------------------------------------------------------------
  FILE DESCRIPTION
-----------------------------------------------------------------------------------------------------------------------
  \file  File:  Dcm_Callout_Stubs.c
      Project:  Vector Basic Runtime System for MICROSAR4
       Module:  BrsMain

  \brief Description:  File for implementation of DCM callouts.
                       This file is a template only - please implement the callouts according to your needs.

  \attention Please note:
    The demo and example programs only show special aspects of the software. With regard to the fact
    that these programs are meant for demonstration purposes only, Vector Informatik liability shall be
    expressly excluded in cases of ordinary negligence, to the extent admissible by law or statute.
**********************************************************************************************************************/

/**********************************************************************************************************************
  AUTHOR IDENTITY
 ----------------------------------------------------------------------------------------------------------------------
  Name                          Initials      Company
  ----------------------------  ------------  -------------------------------------------------------------------------
  Benjamin Walter               visbwa        Vector Informatik GmbH
-----------------------------------------------------------------------------------------------------------------------
  REVISION HISTORY
 ----------------------------------------------------------------------------------------------------------------------
  Version   Date        Author  Description
 ----------------------------------------------------------------------------------------------------------------------
  01.00.00  2015-07-14  visbwa  Initial creation for usage with StartApplication
  01.00.01  2016-06-22  visbwa  Added sample code information block
  01.00.02  2016-08-29  visbwa  Added Dcm_DiagnosticService_0x38()
  01.00.03  2017-08-31  visbwa  Added callouts for Dcm_DiagnosticService 0x00, 0xB2, 0xB6 and 0xB7
  01.00.04  2017-12-06  visbwa  Reworked sample/example code disclaimer
  01.00.05  2019-02-01  visbwa  Added support for DCM ASR Version 4.2.2
**********************************************************************************************************************/

/**********************************************************************************************************************
*  EXAMPLE CODE ONLY
*  -------------------------------------------------------------------------------------------------------------------
*  This Example Code is only intended for illustrating an example of a possible BSW integration and BSW configuration.
*  The Example Code has not passed any quality control measures and may be incomplete. The Example Code is neither
*  intended nor qualified for use in series production. The Example Code as well as any of its modifications and/or
*  implementations must be tested with diligent care and must comply with all quality requirements which are necessary
*  according to the state of the art before their use.
*********************************************************************************************************************/

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#include "Dcm.h"
#include "Dcm_Cfg.h"

/**********************************************************************************************************************
  LOCAL FUNCTIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  PART 1 - STATIC PART
   These Callouts are announced within Dcm_Core.h.
   The existence is configuration specific
**********************************************************************************************************************/
FUNC(void, DCM_CALLOUT_CODE) Dcm_Confirmation(Dcm_IdContextType idContext
                                             ,PduIdType dcmRxPduId
                                             ,Dcm_ConfirmationStatusType status)
{
	((void)(idContext));
	((void)(dcmRxPduId));
	((void)(status));
}

#if (DCM_DIAG_JUMPTOFBL_ENABLED   == STD_ON) || \
    (DCM_DIAG_JUMPFROMFBL_ENABLED == STD_ON)
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_SetProgConditions(Dcm_ProgConditionsPtrType progConditions)
{
  /* This Callout is called during first call of Dcm_Mainfunction().
     If it returns DCM_E_NOT_OK, a Det-Error would be hit (0x35,0x00,0xf0,0x06) */
  ((void)(progConditions));
  return DCM_E_OK;
}
#endif

#if (DCM_DIAG_JUMPFROMFBL_ENABLED == STD_ON)
FUNC(Dcm_EcuStartModeType, DCM_CALLOUT_CODE) Dcm_GetProgConditions(Dcm_ProgConditionsPtrType progConditions)
{
  ((void)(progConditions));
  return DCM_E_NOT_OK;
}
#endif

# if (DCM_DIAG_STATE_RECOVERY_ENABLED == STD_ON)
/**********************************************************************************************************************
 *  Dcm_GetRecoveryStates()
 *********************************************************************************************************************/
/*! \brief          Collects the external stored internal Dcm state.
 *  \details        The Dcm_GetRecoveryStates() call-out is called upon DCM initialization and allows to restore the
 *                  previously via Dcm_ProvideRecoveryStates() stored internal Dcm state.
 *  \param[out]     RecoveryInfo     Parameter to be written by the DCM with all the information to be recovered.
 *  \return         DCM_E_OK         Result is valid and shall be processed
 *  \return         DCM_E_PENDING    Result is pending (e.g. NvM not yet ready)
 *  \return         DCM_E_NOT_OK     No information to be recovered or result reading failed
 *                                   DCM shall continue with the default initialized states.
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    FALSE
 *  \config         This function is only available if DCM_DIAG_STATE_RECOVERY_ENABLED = STD_ON
 *  \pre            Once this API is called, DCM will lock any external connection until the result is processed.
 *                  This is required in order to be able to switch into a consistent state without any influence from
 *                  outside.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_GetRecoveryStates(
  P2VAR(Dcm_RecoveryInfoType, AUTOMATIC, DCM_VAR_NOINIT) RecoveryInfo
  )
{
    return DCM_E_NOT_OK;
}
# endif

/**********************************************************************************************************************
  END of User implementation area
**********************************************************************************************************************/

