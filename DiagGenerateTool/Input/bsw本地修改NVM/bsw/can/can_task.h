/*----------------------------------------------------------------------------
** Project Name:
** #Archive: #
** #Author: #
** #Date: #
** (c) Copyright 2008, Lear Corporation
**----------------------------------------------------------------------------
** #Revision: 1 #
**----------------------------------------------------------------------------
** Target system:
** Compiler:
** Description:
**----------------------------------------------------------------------------
**               A U T H O R   I D E N T I T Y
**----------------------------------------------------------------------------
** Initials     Name                     Company
** --------     ---------------------    -------------------------------------
** JFIDALGO     Jesus Fidalgo            LEAR CORPORATION
** JFERNANDEZ   Josep Fernandez          LEAR CORPORATION
** ROLF         Roberto Lanuza           LEAR CORPORATION
** JLOBATO      Jose Lobato              LEAR CORPORATION
**----------------------------------------------------------------------------
**               R E V I S I O N   H I S T O R Y
**----------------------------------------------------------------------------
**
**--------------------------------------------------------------------------*/
#ifndef CAN_CFG_H
#define CAN_CFG_H

extern void CanMianFunction(void);
extern void task_CanInitilization(void);
extern void CAN_RequsetCommodeInit(void);
extern unsigned char CanIf_CheckValidation(unsigned long WakeupSource);
#endif
