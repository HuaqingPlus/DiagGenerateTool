#ifndef PROJECTMANAGER_H
#define PROJECTMANAGER_H
#include "mainwindow.h"

extern QList<S_DcmGeneral_Infos_User_Type*> List_DcmGeneral_Infos_User;
extern QList<S_DID_Infos_User_Type* > List_DID_Infos_User;
extern QList<S_RID_Infos_User_Type* > List_RID_Infos_User;
extern QList<S_OpCycle_Infos_User_Type*> List_OpCycle_Infos_User;
extern QList<S_Debounce_Infos_User_Type*> List_Debounce_Infos_User;
extern QList<S_DTC_Infos_User_Type* > List_DTC_Infos_User;
extern QList<S_NVM_Infos_User_Type* > List_NVM_Infos_User;
extern QList<S_FEE_Infos_User_Type* > List_FEE_Infos_User;

extern void PM_SaveConfigInfo(void);
extern void PM_NewProject(void);

#endif // PROJECTMANAGER_H
