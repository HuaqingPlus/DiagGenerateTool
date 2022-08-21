#ifndef __DCMEXT__H
#define __DCMEXT__H


#include "Std_Types.h"

#  ifndef RETURN_CONTROL_ECU
#   define RETURN_CONTROL_ECU (0U)
#  endif

#  ifndef RESET_TO_DEFAULT
#   define RESET_TO_DEFAULT (1U)
#  endif

#  ifndef FREEZE_CURRENT_STATE
#   define FREEZE_CURRENT_STATE (2U)
#  endif

#  ifndef SHORT_TERM_ADJUST
#   define SHORT_TERM_ADJUST (3U)
#  endif

//=====================================================================================================================
//  TYPES
//=====================================================================================================================
typedef unsigned char  DG_MGR_UINT8;
typedef unsigned short DG_MGR_UINT16;
typedef unsigned long  DG_MGR_UINT32;
typedef	unsigned char  DG_MGR_BOOLEAN;

typedef struct
{
	uint32  routine_time;
	uint16  routine_id;
	uint8   routine_type;
	uint8   sup_session;
	uint8   sess_sec_stat;        /* DR security status - security req status corresponding to each session */
	uint8   supp_seclvl;          /* DR security level  - bit masked supp security levels as in SECURITY_RECORD */
	uint8   DID_LHVSD_Check_Status; /* Status variable to enable/disable the LVSD & HVSD check for each DIDs */
	uint8   (*start_routine_func)(uint8 p_msgdat_U8A[],uint16 *p_res_data_len_ptr);
	uint8   (*results_routine_func)(uint8 p_msgdat_U8A[],uint16 *p_res_data_len_ptr);
	boolean (*status_routine_func)(void);
    void    (*terminate_routine_func)(void);
}RTN_CTRL_RECORD;

typedef struct
{
    DG_MGR_UINT16 pid_number;/* The 16-bit PID number */
    DG_MGR_UINT8 (*pid_function_ptr)(DG_MGR_UINT8 *buffer);/* Pointer to function which provides pid data...ONLY CALLED IFpid_length IS ZERO. */
}PID_RECORD;

typedef struct
{
	uint16 DId;
    uint16 BlockId;
	uint8 len;
    Std_ReturnType (*nvm_write_function)(uint8 *buffer);
	Std_ReturnType (*nvm_read_function)(uint8 *buffer);
}Eol_Nvm_Block_RECORD;

/*
** Structure for incorporating product specific I/O control by Commmand ID requests
** (mode 0x2F).
** com_id           = identifies parameter for which I/O action is requested
** action_mask      = specifies which actions are supported for the id
** data_length      = length of parameter data
** data_ptr         = pointer to parameter data
** function_handler = function called to write parameter data
*/
typedef struct
{
    DG_MGR_UINT16 pid;
    DG_MGR_UINT8 action_mask;
    DG_MGR_UINT8 data_length;
    DG_MGR_UINT8 *data_ptr;
    DG_MGR_UINT8 (*function_handler)(DG_MGR_UINT8 control_option,DG_MGR_UINT8 *buffer);
    void (*recover_function)(void);
} IOCTL_RECORD;

#endif 

/*****************************************************************************
*     End of File
*
*******************************************************************************/


