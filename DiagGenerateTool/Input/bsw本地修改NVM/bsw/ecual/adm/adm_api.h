
#ifndef ADM_API_H
#define ADM_API_H

#include "Platform_Types.h"
    /*----------------------------------------------------------------------------
    ** Types declaration
    */

    /*----------------------------------------------------------------------------
    ** Imports
    */
    	

    /*----------------------------------------------------------------------------
    ** Define constants
    */


    /*----------------------------------------------------------------------------
    ** Public functions declaration
    */
        /*----------------------------------------------------------------------------
        ** Function    :  ADM_Init
        ** Description :  Initialization of the ADM module.
        ** Periodicity :  Once, at start-up
        **--------------------------------------------------------------------------*/
        extern void ADM_Init(void);

        /*----------------------------------------------------------------------------
        ** Function        :  ADM_Task
        ** Description :  Periodic task for ADM. It starts / stops ADC conversion, reads
        **                and raw ADC results and publishs them to AIP.
        ** Periodicity :  2 ms
        **--------------------------------------------------------------------------*/
        extern void ADM_Task(void);

		/*----------------------------------------------------------------------------
        ** Function        :  ADM_Shutdown
        ** Description :  stop conversion.
        ** Periodicity :  
        **--------------------------------------------------------------------------*/
        extern void ADM_Shutdown(void);

		/*----------------------------------------------------------------------------
        ** Function        :  ADM_Resume
        ** Description :  Initialize the ADM module .
        ** Periodicity :  
        **--------------------------------------------------------------------------*/
        extern void ADM_Resume(void);

		/*----------------------------------------------------------------------------
        ** Function        :  ADM_Read_PTD2_ADC
        ** Description :  Read PTD2 ADC Value .
        ** Periodicity :  
        **--------------------------------------------------------------------------*/
        extern uint16 ADM_Read_PTD2_ADC(void);

#endif
