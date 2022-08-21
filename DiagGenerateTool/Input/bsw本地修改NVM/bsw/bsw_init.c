
/*----------------------------------------------------------------------------
** Types declaration
*/
    /* Standard LEAREW types. */
    #include <stddef.h>

/*----------------------------------------------------------------------------
** Imports
*/
#include "can_task.h"
#include "IoHwAb.h"
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
    void Bsw_Init(void){
    	IoHwAb_Init();
    	task_CanInitilization();
    }
