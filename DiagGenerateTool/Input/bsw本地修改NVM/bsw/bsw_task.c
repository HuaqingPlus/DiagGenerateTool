
/*----------------------------------------------------------------------------
** Types declaration
*/
    /* Standard LEAREW types. */
    #include <stddef.h>

/*----------------------------------------------------------------------------
** Imports
*/
#include "Cpu.h"
#include "task.h"
#include "can_task.h"
#include "adm_api.h"
#include "slp_api.h"

/*----------------------------------------------------------------------------
** Define constants
*/

/*----------------------------------------------------------------------------
** Private functions declaration
*/

/*----------------------------------------------------------------------------
** Local data
*/
		

/*----------------------------------------------------------------------------
** Functions implementation
*/

    /*------------------------------------------------------------------------
    ** Description :  Preinitialization. This is the first call on main.
    ** Precondition:  None
    ** Postcondition: None
    ** Return   :     None
    **----------------------------------------------------------------------*/
    void Bsw_task_5ms(void * para){
  		CAN_RequsetCommodeInit();
    	for(;;)
		{
    		CanMianFunction();
			vTaskDelay(5);
    	}
    }

	void Bsw_task_50ms(void * para){
		
		for(;;)
		{
			ADM_Task();
			SLP_SleepMode_MainTask();
			CanIf_CheckValidation(32);
			vTaskDelay(50);
		}
	}
	
