#ifndef FILEGENERATER_H
#define FILEGENERATER_H

#include "mainwindow.h"

#define DID_NONE        ((uint8)0)
#define DID_READ        ((uint8)1)
#define DID_WRITE       ((uint8)2)
#define DID_IOCTRL      ((uint8)4)

#define DCM_DIDMGR_OPCLS_READ_SYNC  ((uint8)1)
#define DCM_DIDMGR_OPCLS_READ_ASYNC ((uint8)2)

#define DCM_DIDMGR_OPCLS_WRITE_SYNC  ((uint8)1)
#define DCM_DIDMGR_OPCLS_WRITE_ASYNC ((uint8)2)


//生成的代码中的数据结构
//Did
typedef struct
{
  uint8 Length;       //Write Data Length
  uint8 OpInfoRef;    //引用DidOpInfo的index
  uint8 Operations;   //Read | Write | IO
}Dcm_DspDidInfoType;

typedef struct
{
  uint8 State_Ref;      //引用Dcm_DsdStateRefo的index
  uint8 SignalInfo_Ref; //都是0
  uint8 CallTypes;      //都是SYNC（同步）
}Dcm_DspDidOpInfoType;

//Rid
typedef struct
{
    uint8 SignalInfo_Ref;
    uint8 State_Ref;
    uint8 Operation;
}Dcm_DspRidInfoType;

typedef struct
{
    uint8 RidOpFunc_Ref;
    uint8 Req_Length;
    uint8 Resp_Length;
    uint8 OpType;
}Dcm_DspRidSignalInfoType;

//内部数据
//DID
typedef struct
{
    uint8 Sid;
    uint8 StateRef;
}State_SID_Ref_Type;

typedef struct
{
    uint16 Did;
    uint8 Length;
    uint8 OpInfoRef;
    uint8 Operation;
    uint8 State_Ref;
    uint8 SIgnalInfo_Ref;
    uint8 CallTypes;
}S_DID_Configs_Type;

typedef struct
{
    uint32  routine_time;
    uint16  routine_id;
    uint8   routine_type;
    uint8   sup_session;
    uint8   sess_sec_stat;
    uint8   supp_seclvl;
    uint8   DID_LHVSD_Check_Status;
    QString Str_StartFunction;//用String代替
    QString Str_ResultFunction;//用String代替
    QString Str_StatusFunction;//用String代替
    QString Str_StopFunction;//用String代替
}S_RID_RTN_Record_Type;

typedef struct
{
    QString Str_ServiceDefine;
    QString Diag_PhyReq_PduId;
    QString Diag_PhyRes_PduId;
    QString Diag_FunReq_PduId;
}S_File_DcmConfigs_Type;


typedef struct
{
    QString Str_DidCount;
    QString Str_DidOpInfoCount;
    QString Str_DidMacros;
    QString Str_DidTable;
    QString Str_DidInfoTable;
    QString Str_DidOpInfoTable;
    QString Str_DcmTable_Read;
    QString Str_DcmTable_Write;
    QString Str_DcmTable_IOCTRL;
    QString Str_ReadFunctions_Define;
    QString Str_WriteFunctions_Define;
    QString Str_IOCFunctions_Define;
    QString Str_ReadFunctions_Declaration;
    QString Str_WriteFunctions_Declaration;
    QString Str_IOCFunctions_Declaration;
}S_File_DidConfigs_Type;

typedef struct
{
    QString Str_RidCount;
    QString Str_RidSignalInfoCount;
    QString Str_RidMacros;
    QString Str_RidTable;
    QString Str_RidInfoTable;
    QString Str_RidSignalInfoTable;
    QString Str_Rid_RTN_Record;
    QString Str_RidFunctions_Define;
    QString Str_RidFunctions_Declaration;
}S_File_RidConfigs_Type;


typedef struct
{
    QString Str_File_Start;
    QString Str_Macro_Define;
    QString Str_OpCycle_Table;
    QString Str_Debounce_Table;
    QString Str_DTC_Value_Define;
    QString Str_DTC_Table;
    QString Str_DTC_Attributes_Table;
    QString Str_Event_Parameters_Table;
}S_File_Dem_Generate_Type;

//记录用户代码
typedef struct
{
    QString Str_FunctionName;
    QString Str_UserCode;
}S_UserCode_Type;


//配置数据
const State_SID_Ref_Type State_SID_Table[] = \
{\
    {0x22, 2},\
    {0x2E, 3},\
    {0x2F, 4},\
    {0x31, 5}
};

typedef struct
{
    uint8 DataLen;
    QString Str_ReadFunction;
}S_ReadFunction_Type;


//函数声明
void FG_Process(void);
void FG_GetUserCode(void);
void FG_ParseConfig(void);

void FG_ParseDcmGeneralConfig(void);
void FG_ParseDidConfig(void);
void FG_ParseRidConfig(void);
void FG_ParseOpCycleConfig();
void FG_ParseDebounceConfig();
void FG_ParseDTCConfig();

void Generate_Dcm_Cfg_Generate_h(void);
void Generate_DcmExt_Generate_c(void);
void Generate_DcmExt_Generate_h(void);
void Generate_Dem_Cfg_Generate_h(void);

extern void PM_NewProject(void);
extern void PM_OpenProject(void);
extern void PM_SaveConfigInfo(void);

#endif // FILEGENERATER_H
