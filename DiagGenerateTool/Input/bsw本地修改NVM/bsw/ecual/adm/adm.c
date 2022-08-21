
/*----------------------------------------------------------------------------
** Types declaration
*/
/* Standard LEAREW types. */
#include <stddef.h>
/*----------------------------------------------------------------------------
** Imports
*/
#include "Cpu.h"
/* Prototypes */
#include "adm_api.h"

/* Private interface */
#include "adm_cfg.h"

/* ADC interface */
#include "adConv1.h"
#include "IohwAb.h"

/*----------------------------------------------------------------------------
** Define constants
*/


/*----------------------------------------------------------------------------
** Private functions declaration
*/


/*----------------------------------------------------------------------------
** Local data
*/
static uint16 PTD2_ADCInput_data = 100;
static uint16 PTD4_ADCInput_data = 100;
static uint16 PTB12_ADCInput_data = 100;


/*----------------------------------------------------------------------------
** External data
*/
/*----------------------------------------------------------------------------
** Functions implementation
*/
    /*------------------------------------------------------------------------
    ** Description:   Initialize the Analog Digital Converter Module
    ** Precondition:  None
    ** Postcondition: None
    ** Return:        None
    **----------------------------------------------------------------------*/
    void ADM_Init(void)
    {

    }

    /*------------------------------------------------------------------------
    ** Description:   Update the Analog Digital manager inputs
    ** Precondition:  None
    ** Postcondition: None
    ** Return:        None
    **----------------------------------------------------------------------*/
    void ADM_Task(void)
    {
    	IoHwAb_DioWritePin(IoHwAb_VBATT_AN_EN_PIN,IoHwAb_DIO_HIGH);
    	/*PTD2*/
        /* Configure ADC channel and software trigger a conversion */
        ADC_DRV_ConfigChan(INST_ADCONV1, 0, &adConv1_ChnConfig0);
        /* Wait for the conversion to be done */
        ADC_DRV_WaitConvDone(INST_ADCONV1);
        /* Store the channel result into a local variable */
        ADC_DRV_GetChanResult(INST_ADCONV1, 0, &PTD2_ADCInput_data);

		/*PTD4*/
        /* Configure ADC channel and software trigger a conversion */
        ADC_DRV_ConfigChan(INST_ADCONV1, 0, &adConv1_ChnConfig1);
        /* Wait for the conversion to be done */
        ADC_DRV_WaitConvDone(INST_ADCONV1);
        /* Store the channel result into a local variable */
        ADC_DRV_GetChanResult(INST_ADCONV1, 0, &PTD4_ADCInput_data);

		/*PTB12*/
        /* Configure ADC channel and software trigger a conversion */
        ADC_DRV_ConfigChan(INST_ADCONV1, 0, &adConv1_ChnConfig2);
        /* Wait for the conversion to be done */
        ADC_DRV_WaitConvDone(INST_ADCONV1);
        /* Store the channel result into a local variable */
        ADC_DRV_GetChanResult(INST_ADCONV1, 0, &PTB12_ADCInput_data);

    }

    /*----------------------------------------------------------------------------
    ** Function    :  ADM_Shutdown
    ** Description :  stop conversion.
    ** Activated by:  
    **--------------------------------------------------------------------------*/
    void ADM_Shutdown(void)
    {

    }

    /*----------------------------------------------------------------------------
    ** Function    :  ADM_Resume
    ** Description :  Initialize the ADM module .
    ** Activated by:  
    **--------------------------------------------------------------------------*/
    void ADM_Resume(void)
    {
		/* Configure and calibrate the ADC converter
		 *	-	See ADC component for the configuration details
		 */

    }

    /*----------------------------------------------------------------------------
    ** Function    :  ADM_Read_PTD2_ADC
    ** Description :  Read PTD2 ADC Value .
    ** Activated by:  
    **--------------------------------------------------------------------------*/
    uint16 ADM_Read_PTD2_ADC(void)
    {
        return PTD2_ADCInput_data;
    }
