# include "Std_Types.h"
/*! This type is a 32bit bitmask where each bit represents a wakeup source. */
 typedef uint32 EcuM_WakeupSourceType;

 /***********************************************************************************************************************
 *  EcuM_CheckWakeup
 **********************************************************************************************************************/
/*! \brief       Check a wake-up event.
 *  \details     Polls a wake-up source for occurred wake-up event. It sets up the PLL and check other wakeup sources
 *               that may be connected to the same interrupt.
 *  \param[in]   WakeupSource     the source of the wake-up event.
 *  \pre         -
 *  \context     TASK | ISR
 *  \reentrant   TRUE for different wakeup sources.
 *  \synchronous TRUE
 *  \trace       CREQ-499
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_CheckWakeup(EcuM_WakeupSourceType wakeupSource);

/***********************************************************************************************************************
 *  EcuM_SetWakeupEvent
 **********************************************************************************************************************/
/*! \brief       Set a wake-up event.
 *  \details     Marks a wake-up event as pending if validation is required.
 *               If no validation is required then EcuM_ValidateSetWakeupEvent will be called within this function to
 *               mark this source as validated.
 *  \param[in]   WakeupSource     the source of the wake-up event.
 *  \pre         -
 *  \context     TASK | ISR
 *  \reentrant   TRUE for different wakeup sources.
 *  \synchronous TRUE
 *  \trace       CREQ-465
 *  \note        This API can only handle one wakeup source, so only one bit is allowed to be set in the mask.
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_SetWakeupEvent(EcuM_WakeupSourceType WakeupSource);