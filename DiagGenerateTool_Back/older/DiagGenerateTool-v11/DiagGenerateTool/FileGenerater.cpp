#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "FileGenerater.h"

#define RELEASE

extern MainWindow* MW;
//define in mainwindow.cpp
extern QList<S_DcmGeneral_Infos_User_Type*> List_DcmGeneral_Infos_User;
extern QList<S_DID_Infos_User_Type* > List_DID_Infos_User;
extern QList<S_RID_Infos_User_Type* > List_RID_Infos_User;
extern QList<S_OpCycle_Infos_User_Type*> List_OpCycle_Infos_User;
extern QList<S_Debounce_Infos_User_Type*> List_Debounce_Infos_User;
extern QList<S_DTC_Infos_User_Type* > List_DTC_Infos_User;

extern QStandardItemModel StdModel_Did;
extern QStandardItemModel StdModel_Rid;
extern QStandardItemModel StdModel_DcmGeneral;
extern QStandardItemModel StdModel_OpCycle;
extern QStandardItemModel StdModel_Debounce;
extern QStandardItemModel StdModel_DTC;

extern QStringList StrList_AlgoClass;
extern QStringList StrList_Behavior;
extern QStringList StrList_EventKind;

//用于生成文件，以string形式记录所有的配置
QString Str_File_DcmGemeral_Configs;
S_File_DidConfigs_Type S_File_DidConfigs;
S_File_RidConfigs_Type S_File_RidConfigs;
S_File_DcmConfigs_Type S_File_DcmConfigs;

S_File_Dem_Generate_Type S_File_DemConfigs;

//RID配置
QList<uint16> List_Rid;
QList<Dcm_DspRidInfoType> List_RidInfo;
QList<Dcm_DspRidSignalInfoType> List_RidSignalInfo;
QList<S_RID_RTN_Record_Type> List_RTN_Record;

//DID配置信息
//用于生成DID_XXXX和DCM_TABLE_SUPPORTED_DID
QList<uint16> List_Did;

//根据配置信息，再扩展其他需要的配置信息
QList<S_DID_Configs_Type> List_DID_Configs;

//记录DID 操作，数据长度等信息
//用于生成DCM_TABLE_DID_INFO
QList<Dcm_DspDidInfoType> List_DidInfo;

//记录State_Ref及其他,
//用于生成DCM_TABLE_DID_OPERATION_INFO
QList<Dcm_DspDidOpInfoType> List_DidOpInfo;

//QStringList List_Funtion;
QList<S_ReadFunction_Type> List_Read_Funtion;
QList<S_ReadFunction_Type> List_Write_Funtion;
QStringList List_IOC_Funtion;

//用户代码
QString Str_UserCode_Common;
QList<S_UserCode_Type*> List_UserCode;

//Don't Remove Flag
QString Str_ComCode_StartFlag[4];
QString Str_ComCode_EndFlag[4];
QString Str_FunCode_StartFlag[4];
QString Str_FunCode_EndFlag[4];

QString Str_UserComCode_StartFlag;
QString Str_UserComCode_EndFlag;
QString Str_UserFunCode_StartFlag;
QString Str_UserFunCode_EndFlag;

QStringList StrList_Bool = {"FALSE", "TRUE"};

//Generate File Result
boolean Result_Generate = true;

void FG_Init(void)
{
    Str_ComCode_StartFlag[0] = QString("/****************************************************************************/\n");
    Str_ComCode_StartFlag[1] = QString("/*                      !!! Don't Remove This Comment !!!                   */\n");
    Str_ComCode_StartFlag[2] = QString("/*                              User's Code Start                           */\n");
    Str_ComCode_StartFlag[3] = QString("/****************************************************************************/\n");

    Str_ComCode_EndFlag[0] = QString("/****************************************************************************/\n");
    Str_ComCode_EndFlag[1] = QString("/*                        !!! Don't Remove This Comment !!!                 */\n");
    Str_ComCode_EndFlag[2] = QString("/*                                User's Code end                           */\n");
    Str_ComCode_EndFlag[3] = QString("/****************************************************************************/\n");

    Str_FunCode_StartFlag[0] = QString("/*********************************************/\n");
    Str_FunCode_StartFlag[1] = QString("/*     !!! Don't Remove This Comment !!!     */\n");
    Str_FunCode_StartFlag[2] = QString("/*         User's Function Code Start        */\n");
    Str_FunCode_StartFlag[3] = QString("/*********************************************/\n");

    Str_FunCode_EndFlag[0] = QString("/*********************************************/\n");
    Str_FunCode_EndFlag[1] = QString("/*     !!! Don't Remove This Comment !!!     */\n");
    Str_FunCode_EndFlag[2] = QString("/*         User's Function Code end          */\n");
    Str_FunCode_EndFlag[3] = QString("/*********************************************/\n");

    Str_UserComCode_StartFlag = Str_ComCode_StartFlag[0] + Str_ComCode_StartFlag[1] +\
                                Str_ComCode_StartFlag[2] + Str_ComCode_StartFlag[3];
    Str_UserComCode_EndFlag = Str_ComCode_EndFlag[0] + Str_ComCode_EndFlag[1] +\
                              Str_ComCode_EndFlag[2] + Str_ComCode_EndFlag[3];

    Str_UserFunCode_StartFlag = Str_FunCode_StartFlag[0] + Str_FunCode_StartFlag[1] +\
                                Str_FunCode_StartFlag[2] + Str_FunCode_StartFlag[3];
    Str_UserFunCode_EndFlag = Str_FunCode_EndFlag[0] + Str_FunCode_EndFlag[1] +\
                              Str_FunCode_EndFlag[2] + Str_FunCode_EndFlag[3];
}

//创建文件
void FG_Process(void)
{
    FG_Init();
    //1. StdModel_xxxx -> List_xxxx_Infos_User (用户增删操作，反向修改List_xxxx_Infos_User)
    //And, List_xxxx_Infos_User -> List_Config_xxxx (解析用户配置信息，生成对应的配置信息)
    MW->Slot_UpdateDcmGeneralInfos(StdModel_Did.item(0,0));
    MW->Slot_UpdateDidInfos(StdModel_Rid.item(0,0));
    MW->Slot_UpdateRidInfos(StdModel_DcmGeneral.item(0,0));
    MW->Slot_UpdateOpCycleInfos(StdModel_OpCycle.item(0,0));
    MW->Slot_UpdateDebounceInfos(StdModel_Debounce.item(0,0));
    MW->Slot_UpdateDTCInfos(StdModel_DTC.item(0,0));

    //2. List_xxxx_Info_User -> xml (保存工程)
    PM_SaveConfigInfo();

    //3. List_Config_xxxx -> xxx_Generate.x (生成配置文件)
    FG_GetUserCode();
    FG_ParseConfig();
    Generate_Dcm_Cfg_Generate_h();
    Generate_DcmExt_Generate_c();
    Generate_DcmExt_Generate_h();
    Generate_Dem_Cfg_Generate_h();

    if(Result_Generate)
    {
        QMessageBox MsgBox;
        MsgBox.setText("Files Generate Success...");
        MsgBox.exec();
    }
}

void FG_ParseConfig(void)
{
    FG_ParseDcmGeneralConfig();
    FG_ParseDidConfig();
    FG_ParseRidConfig();
    FG_ParseOpCycleConfig();
    FG_ParseDebounceConfig();
    FG_ParseDTCConfig();
}

void FG_ParseDcmGeneralConfig()
{
    uint8 i = 0;
    QString Str_Temp;
    Str_File_DcmGemeral_Configs.clear();
    Str_Temp = "//DcmGeneralConfig\n";
    for(i =0; i < List_DcmGeneral_Infos_User.count(); i++)
    {
        Str_Temp.append(QString("#define %1\t\t(%2u)\n")\
                .arg(List_DcmGeneral_Infos_User.at(i)->Item)\
                .arg(List_DcmGeneral_Infos_User.at(i)->Value));
    }
    Str_File_DcmGemeral_Configs = Str_Temp;
}

void FG_ParseDidConfig()
{
    uint8 i = 0;
    uint8 j = 0;
    QString Str_Temp;
    QString Str_Temp_Functions;
    QString Str_UserCode;
    List_Read_Funtion.clear();
    List_Write_Funtion.clear();
    List_IOC_Funtion.clear();
    S_File_DidConfigs.Str_ReadFunctions_Declaration.clear();
    S_File_DidConfigs.Str_WriteFunctions_Declaration.clear();
    S_File_DidConfigs.Str_IOCFunctions_Declaration.clear();

    //PID Define
    Str_Temp = QString("//PID Define\n");
    for(i = 0; i < List_Did.count(); i++)
    {
        QString Str_Did = QString::number(List_Did.at(i), 16).toUpper();
        Str_Temp.append(QString("#define PID_%1").arg(Str_Did)) \
                .append(QString("\t\t((uint16)0x%1)\n").arg(Str_Did));
    }
    S_File_DidConfigs.Str_DidMacros = Str_Temp;
    S_File_DidConfigs.Str_DidCount = QString("#define DcmNumOfDIDSupported\t\t((uint8)%1)").arg(List_Did.count());

    //DCM_TABLE_SUPPORTED_DID
    Str_Temp = QString("#ifndef DCM_TABLE_SUPPORTED_DID\n").append("#define DCM_TABLE_SUPPORTED_DID \\");
    for(i = 0; i < List_Did.count(); i++)
    {
        QString Str_Did = QString::number(List_Did.at(i), 16).toUpper();
        Str_Temp.append(QString("\n\tPID_%1, \\").arg(Str_Did));
    }
    Str_Temp.append("\n\n#endif\n");
    S_File_DidConfigs.Str_DidTable = Str_Temp;

    //DCM_TABLE_DID_INFO
    Str_Temp.clear();
    Str_Temp = QString("#ifndef DCM_TABLE_DID_INFO\n").append("#define DCM_TABLE_DID_INFO \\\n");
    for(i = 0; i < List_DidInfo.count(); i++)
    {
        Str_Temp.append("{");
        Str_Temp.append(QString("%1, %2, %3}, \\\n") \
                .arg(List_DidInfo.at(i).Length, 2) \
                .arg(List_DidInfo.at(i).OpInfoRef, 2) \
                .arg(List_DidInfo.at(i).Operations, 2));
    }
    Str_Temp.append("\n#endif\n");
    S_File_DidConfigs.Str_DidInfoTable = Str_Temp;


    //DCM_TABLE_DID_OPERATION_INFO
    Str_Temp = QString("#ifndef DCM_TABLE_DID_OPERATION_INFO\n").append("#define DCM_TABLE_DID_OPERATION_INFO \\\n");
    for(i = 0; i < List_DidOpInfo.count(); i++)
    {
        Str_Temp.append("{");
        Str_Temp.append(QString("0x%1, 0x%2, 0x%3}, \\\n") \
                .arg(List_DidOpInfo.at(i).State_Ref, 2, 16, QChar('0')) \
                .arg(List_DidOpInfo.at(i).SignalInfo_Ref, 2, 16, QChar('0')) \
                .arg(List_DidOpInfo.at(i).CallTypes, 2, 16, QChar('0')));
    }
    Str_Temp.append("\n#endif\n");
    S_File_DidConfigs.Str_DidOpInfoCount = QString("#define DcmDspNumOfDidOpInfo\t\t((uint16)%1)").arg(List_DidOpInfo.count());
    S_File_DidConfigs.Str_DidOpInfoTable = Str_Temp;

    //DCM_TABLE_READ
    //Str_Temp.append("#ifdef SERVICE_22_SUPPORTED\n");
    Str_Temp = QString("#ifndef DCM_TABLE_READ\n").append("#define DCM_TABLE_READ \\\n");
    for(i = 0; i < List_Did.count(); i++)
    {
        QString Str_Did = QString::number(List_Did.at(i), 16).toUpper();
        QString Str_Did_Function;
        S_ReadFunction_Type S_ReadFunction_Temp;
        if(0 != (List_DidInfo.at(i).Operations & DID_READ))
        {
            Str_Did_Function.append(QString("fdiag_app_%1_Read").arg(Str_Did));
            S_ReadFunction_Temp.DataLen = List_DidInfo.at(i).Length;
            S_ReadFunction_Temp.Str_ReadFunction = Str_Did_Function;

            List_Read_Funtion.append(S_ReadFunction_Temp);
            if(!S_File_DcmConfigs.Str_ServiceDefine.contains("#define SERVICE_22_SUPPORTED\n"))
            {
                S_File_DcmConfigs.Str_ServiceDefine.append("#define SERVICE_22_SUPPORTED\n");
            }
        }
        else
        {
            continue;
        }
        Str_Temp.append("{");
        Str_Temp.append(QString("PID_%1,\t\t").arg(Str_Did)).append(Str_Did_Function);
        Str_Temp.append("},\\\n");
    }
    Str_Temp.append("\n#endif\n");
    S_File_DidConfigs.Str_DcmTable_Read = Str_Temp;

    //DCM_TABLE_WRITE
    //Str_Temp.append("#ifdef SERVICE_2E_SUPPORTED\n");
    Str_Temp = QString("#ifndef DCM_TABLE_WRITE\n").append("#define DCM_TABLE_WRITE \\\n");
    for(i = 0; i < List_Did.count(); i++)
    {
        QString Str_Did = QString::number(List_Did.at(i), 16).toUpper();
        QString Str_Did_Function;
        S_ReadFunction_Type S_WriteFunction_Temp;
        if(0 != (List_DidInfo.at(i).Operations & DID_WRITE))
        {
            Str_Did_Function.append(QString("fdiag_app_%1_Write").arg(Str_Did));
            S_WriteFunction_Temp.DataLen = List_DidInfo.at(i).Length;
            S_WriteFunction_Temp.Str_ReadFunction = Str_Did_Function;

            List_Write_Funtion.append(S_WriteFunction_Temp);
            if(!S_File_DcmConfigs.Str_ServiceDefine.contains("#define SERVICE_2E_SUPPORTED\n"))
            {
                S_File_DcmConfigs.Str_ServiceDefine.append("#define SERVICE_2E_SUPPORTED\n");
            }
        }
        else
        {
            continue;
        }
        Str_Temp.append("{");
        Str_Temp.append(QString("PID_%1,\t\t").arg(Str_Did)).append(Str_Did_Function);
        Str_Temp.append("},\\\n");
    }
    Str_Temp.append("\n#endif\n");
    S_File_DidConfigs.Str_DcmTable_Write = Str_Temp;

    //DCM_TABLE_IOCTRL
    //Str_Temp.append("#ifdef SERVICE_2F_SUPPORTED\n");
    if(!S_File_DcmConfigs.Str_ServiceDefine.contains("#define SERVICE_2F_SUPPORTED\n"))
    {
        S_File_DcmConfigs.Str_ServiceDefine.append("#define SERVICE_2F_SUPPORTED\n");
    }
    Str_Temp = QString("#ifndef DCM_TABLE_IOCTRL\n").append("#define DCM_TABLE_IOCTRL \\\n");
    for(i = 0; i < List_Did.count(); i++)
    {
        QString Str_Did = QString::number(List_Did.at(i), 16).toUpper();
        QString Str_Did_Function;
        if(0 != (List_DidInfo.at(i).Operations & DID_IOCTRL))
        {
            Str_Did_Function.append(QString("fdiag_app_%1_IOC").arg(Str_Did));
            List_IOC_Funtion.append(Str_Did_Function);
//            if(!S_File_DcmConfigs.Str_ServiceDefine.contains("#define SERVICE_2F_SUPPORTED\n"))
//            {
//                S_File_DcmConfigs.Str_ServiceDefine.append("#define SERVICE_2F_SUPPORTED\n");
//            }
        }
        else
        {
            continue;
        }
        Str_Temp.append("{\\\n");
        Str_Temp.append(QString("\tPID_%1,\\\n").arg(Str_Did)) \
                .append("\tRETURN_CONTROL_ECU|FREEZE_CURRENT_STATE|RESET_TO_DEFAULT|SHORT_TERM_ADJUST,\\\n") \
                .append("\tDID_0x2FDID_SIZE_2,\\\n") \
                .append("\tNULL_PTR, \\\n") \
                .append(Str_Did_Function.insert(0, "\t").append(", \\\n")) \
                .append("\tNULL_PTR, \\\n");
        Str_Temp.append("},\\\n");
    }
    Str_Temp.append("\n#endif\n");
    S_File_DidConfigs.Str_DcmTable_IOCTRL = Str_Temp;


    //Read Functions
    Str_Temp.clear();
    Str_UserCode.clear();
    Str_Temp_Functions.clear();
    Str_Temp.append("#ifdef SERVICE_22_SUPPORTED\n");
    Str_Temp_Functions.append("#ifdef SERVICE_22_SUPPORTED\n");
    for(i = 0; i < List_Read_Funtion.count(); i++)
    {
        QString Str_ReadFun_Name;
        Str_ReadFun_Name = QString("uint8 %1(uint8 Buff[])").arg(List_Read_Funtion.at(i).Str_ReadFunction);

        //1.Read函数注释
        Str_Temp.append("/****************************************************************************\n") \
                .append(QString("Function Name     : %1\n").arg(List_Read_Funtion.at(i).Str_ReadFunction)) \
                .append("Description       : This function is used to read \n") \
                .append("Invocation        : diagnosis_app \n") \
                .append("Parameters        : None \n") \
                .append("Return Value      : UINT8 \n") \
                .append("Critical Section  : None \n") \
                .append("******************************************************************************/\n");

        //2.Don't Remove Start
        Str_Temp.append(Str_ReadFun_Name + ("\n")) \
                .append("{ \n")\
                .append(Str_UserFunCode_StartFlag);

        //3.用户代码
        Str_UserCode.clear();
        for(j = 0; j < List_UserCode.count(); j++)
        {
            if(List_UserCode.at(j)->Str_FunctionName == (Str_ReadFun_Name + "\n"))
            {
                Str_UserCode = List_UserCode.at(j)->Str_UserCode;
                break;
            }
        }
        if(Str_UserCode.isEmpty())
        {
            Str_UserCode =  QString("\tuint8 fl_DataLen = ((uint8)%1);\n").arg(List_Read_Funtion.at(i).DataLen)\
                            .append("\treturn (fl_DataLen);\n");
        }
        Str_Temp.append(Str_UserCode);

        //4.Don't Remove End
        Str_Temp.append(Str_UserFunCode_EndFlag)\
                .append("} \n\n");

        Str_Temp_Functions.append(Str_ReadFun_Name.append(";\n"));
    }
    Str_Temp.append("#endif\n");
    Str_Temp_Functions.append("\nstatic const PID_RECORD diag_pid_table_rom[] = \n") \
            .append("{\n\tDCM_TABLE_READ\n\t{0,NULL_PTR}\n}; \n")\
            .append("#endif\n");

    S_File_DidConfigs.Str_ReadFunctions_Define = Str_Temp;
    S_File_DidConfigs.Str_ReadFunctions_Declaration = Str_Temp_Functions;

    //Write Functions
    Str_UserCode.clear();
    Str_Temp.clear();
    Str_Temp_Functions.clear();
    Str_Temp.append("#ifdef SERVICE_2E_SUPPORTED\n");
    Str_Temp_Functions.append("#ifdef SERVICE_2E_SUPPORTED\n");
    for(i = 0; i < List_Write_Funtion.count(); i++)
    {
        QString Str_WriteFun_Name;
        Str_WriteFun_Name = QString("uint8 %1(uint8 Buff[])").arg(List_Write_Funtion.at(i).Str_ReadFunction);

        //1.函数声明
        Str_Temp.append("/****************************************************************************\n") \
                .append(QString("Function Name     : %1\n").arg(List_Write_Funtion.at(i).Str_ReadFunction)) \
                .append("Description       : This function is used to write \n") \
                .append("Invocation        : diagnosis_app \n") \
                .append("Parameters        : None \n") \
                .append("Return Value      : UINT8 \n") \
                .append("Critical Section  : None \n") \
                .append("******************************************************************************/\n");

        //2.Don't Remove Start
        Str_Temp.append(Str_WriteFun_Name + ("\n")) \
                .append("{ \n")\
                .append(Str_UserFunCode_StartFlag);

        //3.用户代码
        Str_UserCode.clear();
        for(j = 0; j < List_UserCode.count(); j++)
        {
            if(List_UserCode.at(j)->Str_FunctionName == (Str_WriteFun_Name + "\n"))
            {
                Str_UserCode = List_UserCode.at(j)->Str_UserCode;
                break;
            }
        }
        if(Str_UserCode.isEmpty())
        {
            Str_UserCode =  QString("\tuint8 fl_DataLen = ((uint8)%1);\n").arg(List_Write_Funtion.at(i).DataLen)\
                            .append("\treturn (fl_DataLen);\n");
        }
        Str_Temp.append(Str_UserCode);

        //4.Don't Remove End
        Str_Temp.append(Str_UserFunCode_EndFlag)\
                .append("} \n\n");

        Str_Temp_Functions.append(Str_WriteFun_Name.append(";\n"));
    }
    Str_Temp.append("#endif\n");
    Str_Temp_Functions.append("\nstatic const PID_RECORD diag_write_pid_table_rom[] = \n") \
            .append("{\n\tDCM_TABLE_WRITE\n\t{0,NULL_PTR}\n}; \n")\
            .append("#endif\n");

    S_File_DidConfigs.Str_WriteFunctions_Declaration = Str_Temp_Functions;
    S_File_DidConfigs.Str_WriteFunctions_Define = Str_Temp;

    //IOC Functions
    Str_Temp.clear();
    Str_UserCode.clear();
    Str_Temp_Functions.clear();
    Str_Temp.append("#ifdef SERVICE_2F_SUPPORTED\n");
    Str_Temp_Functions.append("#ifdef SERVICE_2F_SUPPORTED\n");
    S_File_DidConfigs.Str_IOCFunctions_Declaration.append("#ifdef SERVICE_2F_SUPPORTED\n");
    for(i = 0; i < List_IOC_Funtion.count(); i++)
    {
        QString Str_IOC_FunName;
        Str_IOC_FunName.append(QString("uint8 %1(uint8 fl_ctrl_parameter, uint8 *fl_get_ctrl_value)").arg(List_IOC_Funtion.at(i)));

        //函数声明
        Str_Temp.append("/****************************************************************************\n") \
                .append(QString("Function Name     : %1\n").arg(List_IOC_Funtion.at(i))) \
                .append("Description       : This function is used to control IO \n") \
                .append("Invocation        : diagnosis_app \n") \
                .append("Parameters        : None \n") \
                .append("Return Value      : UINT8 \n") \
                .append("Critical Section  : None \n") \
                .append("******************************************************************************/\n");

        Str_Temp.append(Str_IOC_FunName + ("\n"))\
                .append("{ \n")\
                .append(Str_UserFunCode_StartFlag);

        //用户代码
        Str_UserCode.clear();
        for(j = 0; j < List_UserCode.count(); j++)
        {
            if(List_UserCode.at(j)->Str_FunctionName == (Str_IOC_FunName + "\n"))
            {
                Str_UserCode = List_UserCode.at(j)->Str_UserCode;
                break;
            }
        }
        if(Str_UserCode.isEmpty())
        {
            Str_UserCode =  QString("\treturn (E_OK);\n");
        }
        Str_Temp.append(Str_UserCode);

        Str_Temp.append(Str_UserFunCode_EndFlag)\
                .append("} \n\n");

        Str_Temp_Functions.append(Str_IOC_FunName.append(";\n"));
    }
    Str_Temp_Functions.append("\nstatic const IOCTL_RECORD ioctl_diag_table_rom[] = \n") \
            .append("{\n\tDCM_TABLE_IOCTRL\n\t{0, 0, 0, NULL_PTR, NULL_PTR, NULL_PTR}\n}; \n")\
            .append("#endif\n");
    Str_Temp.append("#endif\n");
    S_File_DidConfigs.Str_IOCFunctions_Define = Str_Temp;
    S_File_DidConfigs.Str_IOCFunctions_Declaration = Str_Temp_Functions;
}

void FG_ParseRidConfig(void)
{
    uint8 i = 0;
    uint8 j = 0;
    QString Str_UserCode;
    QString Str_Temp;
    QString Str_Temp_Functions;

    S_File_RidConfigs.Str_RidFunctions_Define.clear();
    S_File_RidConfigs.Str_RidFunctions_Declaration.clear();

    //Service Define
    if(0 != List_Rid.count())
    {
        if(!S_File_DcmConfigs.Str_ServiceDefine.contains("#define SERVICE_31_SUPPORTED\n"))
        {
            S_File_DcmConfigs.Str_ServiceDefine.append("#define SERVICE_31_SUPPORTED\n");
        }
    }
    //RID Define
    Str_Temp = QString("//RID Define\n");
    for(i = 0; i < List_Rid.count(); i++)
    {
        QString Str_Rid = QString::number(List_Rid.at(i), 16).toUpper();
        Str_Temp.append(QString("#define RID_%1").arg(Str_Rid,4,QChar('0'))) \
                .append(QString("\t\t((uint16)0x%1)\n").arg(Str_Rid,4,QChar('0')));
    }
    S_File_RidConfigs.Str_RidMacros = Str_Temp;
    S_File_RidConfigs.Str_RidCount = QString("#define DcmNumOfRIDSupported\t\t((uint8)%1)").arg(List_Rid.count());

    //DCM_TABLE_SUPPORTED_RID
    Str_Temp = QString("#ifndef DCM_TABLE_SUPPORTED_RID\n").append("#define DCM_TABLE_SUPPORTED_RID \\");
    for(i = 0; i < List_Rid.count(); i++)
    {
        QString Str_Rid = QString::number(List_Rid.at(i), 16).toUpper();
        Str_Temp.append(QString("\n\tRID_%1, \\").arg(Str_Rid, 4, QChar('0')));
    }
    Str_Temp.append("\n\n#endif\n");
    S_File_RidConfigs.Str_RidTable = Str_Temp;

    //DCM_TABLE_RID_INFO
    Str_Temp.clear();
    Str_Temp = QString("#ifndef DCM_TABLE_RID_INFO\n").append("#define DCM_TABLE_RID_INFO \\\n");
    for(i = 0; i < List_RidInfo.count(); i++)
    {
        Str_Temp.append(QString("{0x%1, 0x%2, 0x%3}, \\\n") \
                .arg(QString::number(List_RidInfo.at(i).SignalInfo_Ref,16), 1, QChar('0')) \
                .arg(QString::number(List_RidInfo.at(i).State_Ref, 16), 1, QChar('0')) \
                .arg(QString::number(List_RidInfo.at(i).Operation,16).toUpper(), 2, QChar('0')));
    }
    Str_Temp.append("\n#endif\n");
    S_File_RidConfigs.Str_RidInfoTable = Str_Temp;

    //DCM_TABLE_RID_SIGNAL_INFO
    Str_Temp.clear();
    Str_Temp = QString("#ifndef DCM_TABLE_RID_SIGNAL_INFO\n").append("#define DCM_TABLE_RID_SIGNAL_INFO \\\n");
    for(i = 0; i < List_RidSignalInfo.count(); i++)
    {
        QString Str_RidOpFunc_Ref = QString::number(List_RidSignalInfo.at(i).RidOpFunc_Ref, 16).toUpper();
        QString Str_Req_Length = QString::number(List_RidSignalInfo.at(i).Req_Length, 16).toUpper();
        QString Str_Resp_Length = QString::number(List_RidSignalInfo.at(i).Resp_Length, 16).toUpper();
        QString Str_OpType = QString::number(List_RidSignalInfo.at(i).OpType, 16).toUpper();
        Str_Temp.append(QString("{0x%1, 0x%2, 0x%3, 0x%4}, \\\n") \
                        .arg(Str_RidOpFunc_Ref, 1, QChar('0')) \
                        .arg(Str_Req_Length, 1, QChar('0')) \
                        .arg(Str_Resp_Length, 2, QChar('0')) \
                        .arg(Str_OpType, 2, QChar('0')));
    }
    Str_Temp.append("\n#endif\n");
    S_File_RidConfigs.Str_RidSignalInfoCount = QString("#define DcmDspNumOfRidSignalInfo\t\t((uint16)%1)").arg(List_RidSignalInfo.count());
    S_File_RidConfigs.Str_RidSignalInfoTable = Str_Temp;

    //DCM_TABLE_ROUTINE_CONTROL
    Str_Temp.clear();
    Str_Temp = QString("#ifndef DCM_TABLE_ROUTINE_CONTROL\n").append("#define DCM_TABLE_ROUTINE_CONTROL\t\t\\\n");
    for(i = 0; i < List_RTN_Record.count(); i++)
    {
        QString Str_Rid = QString::number(List_Rid.at(i), 16).toUpper();
        Str_Temp.append(QString("{\\\n\t%1,\\\n \t%2,\\\n \t%3,\\\n \t%4,\\\n \t%5,\\\n \t%6,\\\n \t%7,\\\n \t%8,\\\n \t%9,\\\n \t%10,\\\n \t%11\\\n}, \\\n") \
                        .arg("DR_TIME_NOT_REQ") \
                        .arg(QString("RID_%1").arg(Str_Rid, 4, QChar('0'))) \
                        .arg(QString("ROUTINE_TYPE_2 | RC_STOP_SERVICE")) \
                        .arg(List_RTN_Record.at(i).sup_session)\
                        .arg(List_RTN_Record.at(i).sess_sec_stat)\
                        .arg(List_RTN_Record.at(i).supp_seclvl)\
                        .arg(QString("LHVSD_CHECK_NOT_NEEDED"))\
                        .arg(List_RTN_Record.at(i).Str_StartFunction)\
                        .arg(List_RTN_Record.at(i).Str_ResultFunction)\
                        .arg(List_RTN_Record.at(i).Str_StatusFunction)\
                        .arg(List_RTN_Record.at(i).Str_StopFunction));
    }
    Str_Temp.append("\n#endif\n");
    S_File_RidConfigs.Str_Rid_RTN_Record = Str_Temp;

    //Rid Functions Define and Declaration
    Str_Temp.clear();
    Str_Temp_Functions.clear();
    Str_Temp.append("#ifdef SERVICE_31_SUPPORTED\n");
    Str_Temp_Functions.append("#ifdef SERVICE_31_SUPPORTED\n");
    for(i = 0; i < List_RTN_Record.count(); i++)
    {
        QString Str_Start_FunctionName = List_RTN_Record.at(i).Str_StartFunction;
        QString Str_Result_FunctionName = List_RTN_Record.at(i).Str_ResultFunction;
        QString Str_Status_FunctionName = List_RTN_Record.at(i).Str_StatusFunction;
        QString Str_Stop_FunctionName = List_RTN_Record.at(i).Str_StopFunction;
        QString Strline_FunName;
        Strline_FunName = QString("uint8 %1(uint8 p_diag_buf_U8A[],uint16 *p_resdatalen_ptr) \n")\
                .arg(Str_Start_FunctionName);

        //Start 函数声明
        Str_Temp.append("/****************************************************************************\n") \
                .append(QString("Function Name     : %1\n").arg(Str_Start_FunctionName)) \
                .append("Description       : This function is used to Start Routine \n") \
                .append("Invocation        : diagnosis_app \n") \
                .append("Parameters        : None \n") \
                .append("Return Value      : uint8, uint16* \n") \
                .append("Critical Section  : None \n") \
                .append("******************************************************************************/\n");
        Str_Temp.append(Strline_FunName);

        //2.Don't Remove Start
        Str_Temp.append("{ \n")\
                .append(Str_UserFunCode_StartFlag);

        //3.用户代码
        Str_UserCode.clear();
        for(j = 0; j < List_UserCode.count(); j++)
        {
            if(List_UserCode.at(j)->Str_FunctionName == Strline_FunName)
            {
                Str_UserCode = List_UserCode.at(j)->Str_UserCode;
                break;
            }
        }
        if(Str_UserCode.isEmpty())
        {
            Str_UserCode =  QString("\treturn (E_OK);\n");
        }
        Str_Temp.append(Str_UserCode);

        //4.Don't Remove End
        Str_Temp.append(Str_UserFunCode_EndFlag)\
                .append("} \n\n");

        //Start 函数定义
        Str_Temp_Functions.append(QString("uint8 %1(uint8 p_diag_buf_U8A[],uint16 *p_resdatalen_ptr); \n")\
                                  .arg(Str_Start_FunctionName));

        //Result 函数声明
        Strline_FunName = QString("uint8 %1(uint8 p_diag_buf_U8A[],uint16 *p_resdatalen_ptr) \n")\
                .arg(Str_Result_FunctionName);

        Str_Temp.append("/****************************************************************************\n") \
                .append(QString("Function Name     : %1\n").arg(Str_Result_FunctionName)) \
                .append("Description       : This function is used to get routine result  \n") \
                .append("Invocation        : diagnosis_app \n") \
                .append("Parameters        : None \n") \
                .append("Return Value      : uint8, uint16* \n") \
                .append("Critical Section  : None \n") \
                .append("******************************************************************************/\n");
        Str_Temp.append(Strline_FunName);

        //2.Don't Remove Start
        Str_Temp.append("{ \n")\
                .append(Str_UserFunCode_StartFlag);

        //3.用户代码
        Str_UserCode.clear();
        for(j = 0; j < List_UserCode.count(); j++)
        {
            if(List_UserCode.at(j)->Str_FunctionName == Strline_FunName)
            {
                Str_UserCode = List_UserCode.at(j)->Str_UserCode;
                break;
            }
        }
        if(Str_UserCode.isEmpty())
        {
            Str_UserCode =  QString("\treturn (E_OK);\n");
        }
        Str_Temp.append(Str_UserCode);

        //4.Don't Remove End
        Str_Temp.append(Str_UserFunCode_EndFlag)\
                .append("} \n\n");

        //Result 函数定义
        Str_Temp_Functions.append(QString("uint8 %1(uint8 p_diag_buf_U8A[],uint16 *p_resdatalen_ptr); \n")\
                                  .arg(Str_Result_FunctionName));

        //Status 函数声明
        Strline_FunName = QString("boolean %1(void) \n").arg(Str_Status_FunctionName);
        Str_Temp.append("/****************************************************************************\n") \
                .append(QString("Function Name     : %1\n").arg(Str_Status_FunctionName)) \
                .append("Description       : This function is used to get routine status \n") \
                .append("Invocation        : diagnosis_app \n") \
                .append("Parameters        : None \n") \
                .append("Return Value      : boolean \n") \
                .append("Critical Section  : None \n") \
                .append("******************************************************************************/\n");
        Str_Temp.append(Strline_FunName);


        //2.Don't Remove Start
        Str_Temp.append("{ \n")\
                .append(Str_UserFunCode_StartFlag);

        //3.用户代码
        Str_UserCode.clear();
        for(j = 0; j < List_UserCode.count(); j++)
        {
            if(List_UserCode.at(j)->Str_FunctionName == Strline_FunName)
            {
                Str_UserCode = List_UserCode.at(j)->Str_UserCode;
                break;
            }
        }
        if(Str_UserCode.isEmpty())
        {
            Str_UserCode =  QString("\treturn (TRUE);\n");
        }
        Str_Temp.append(Str_UserCode);

        //4.Don't Remove End
        Str_Temp.append(Str_UserFunCode_EndFlag)\
                .append("} \n\n");

        //Status 函数定义
        Str_Temp_Functions.append(QString("boolean %1(void); \n").arg(Str_Status_FunctionName));

        //Stop 函数声明
        Strline_FunName = QString("void %1(void)\n").arg(Str_Stop_FunctionName);
        Str_Temp.append("/****************************************************************************\n") \
                .append(QString("Function Name     : %1\n").arg(Str_Stop_FunctionName)) \
                .append("Description       : This function is used to Stop Routine \n") \
                .append("Invocation        : diagnosis_app \n") \
                .append("Parameters        : None \n") \
                .append("Return Value      : void \n") \
                .append("Critical Section  : None \n") \
                .append("******************************************************************************/\n");
        Str_Temp.append(Strline_FunName);

        //2.Don't Remove Start
        Str_Temp.append("{ \n")\
                .append(Str_UserFunCode_StartFlag);

        //3.用户代码
        Str_UserCode.clear();
        for(j = 0; j < List_UserCode.count(); j++)
        {
            if(List_UserCode.at(j)->Str_FunctionName == Strline_FunName)
            {
                Str_UserCode = List_UserCode.at(j)->Str_UserCode;
                break;
            }
        }
        if(Str_UserCode.isEmpty())
        {
            Str_UserCode =  QString("\treturn;\n");
        }
        Str_Temp.append(Str_UserCode);

        //4.Don't Remove End
        Str_Temp.append(Str_UserFunCode_EndFlag)\
                .append("} \n\n");

        //Stop 函数定义
        Str_Temp_Functions.append(QString("void %1(void); \n").arg(Str_Stop_FunctionName));
        Str_Temp_Functions.append("\n");
    }

    Str_Temp.append("#endif\n");
    Str_Temp_Functions.append("static RTN_CTRL_RECORD diag_routine_ctrl_table_rom[] = \n") \
            .append("{\n\tDCM_TABLE_ROUTINE_CONTROL\n\t{0, 0, 0, 0, 0, 0, 0, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR}\n}; \n")\
            .append("#endif\n");

    S_File_RidConfigs.Str_RidFunctions_Define = Str_Temp;
    S_File_RidConfigs.Str_RidFunctions_Declaration = Str_Temp_Functions;
}

void FG_ParseOpCycleConfig()
{
    uint8 i = 0;
    uint8 j = 0;
    uint8 row = 0;
    QString Str_Temp;

    row = List_OpCycle_Infos_User.count();
    S_File_DemConfigs.Str_OpCycle_Table.clear();

    Str_Temp = "//OpCycle Table\n";
    Str_Temp .append(QString("#define Dem_Cfg_Num_Of_OpCycle\t\t((uint8)%1)\n\n").arg(row));
    Str_Temp .append("#ifndef DEM_TABLE_OPCYCLE\n")\
             .append("#define DEM_TABLE_OPCYCLE \\\n")\
             .append("\t/*Index, Id, Type, AutoStart, AutoStop*/\\\n")\
             .append("\t{ /* 0 */DemOpCycle_Ignition, 0, 0, 0 },\\\n");
    for(i = 1; i < row; i++)
    {
       Str_Temp.append(QString("\t{ /* %1 */DemOpCycle_Profile%2, %3, %4, %5},\\\n" )\
               .arg(i).arg(i+1)\
               .arg(QString::number(List_OpCycle_Infos_User.at(i)->Type))\
               .arg(QString::number(List_OpCycle_Infos_User.at(i)->AutoStart))\
               .arg(QString::number(List_OpCycle_Infos_User.at(i)->AutoStop)));
    }
    Str_Temp.append("\n#endif\n\n");
    S_File_DemConfigs.Str_OpCycle_Table = Str_Temp;
}

void FG_ParseDebounceConfig()
{
    uint8 i = 0;
    uint8 j = 0;
    uint8 row = 0;
    QString Str_Temp;

    row = List_Debounce_Infos_User.count();
    S_File_DemConfigs.Str_Debounce_Table.clear();
    
    Str_Temp = "//Debounce Table\n";
    Str_Temp .append(QString("#define Dem_Cfg_Num_Of_DebounceTable\t\t((uint8)%1)\n\n").arg(row));
    Str_Temp .append("#ifndef DEM_TABLE_DEBOUNCE\n")\
             .append("#define DEM_TABLE_DEBOUNCE \\\n")\
             .append("\t/*Index, F.Td, P.Td, FT.Td, PT.Td, Dec-Stp, Inc-Stp, JmpUpVal, JmpDwnVal, Algo, JmpUp, Jmpdwn, Behavior*/ \\\n");

    for(i = 0; i < row; i++)
    {
        //StrList_AlgoClass.at(
        //StrList_Behavior.at(
        Str_Temp.append(QString("\t{ /* %1 */%2, %3, %4, %5, %6, %7, %8, %9, %10, %11, %12, %13},\\\n")\
                .arg(i)\
                .arg(List_Debounce_Infos_User.at(i)->FailedThershold)\
                .arg(List_Debounce_Infos_User.at(i)->PassedThershold)\
                .arg(List_Debounce_Infos_User.at(i)->FailedTimeThershold)\
                .arg(List_Debounce_Infos_User.at(i)->PassedTimeThershold)\
                .arg(List_Debounce_Infos_User.at(i)->DecStepSize)\
                .arg(List_Debounce_Infos_User.at(i)->IncStepSize)\
                .arg(List_Debounce_Infos_User.at(i)->JumpUpValue)\
                .arg(List_Debounce_Infos_User.at(i)->JumpDownValue)\
                .arg(StrList_AlgoClass.at(List_Debounce_Infos_User.at(i)->AlgoClass))\
                .arg(List_Debounce_Infos_User.at(i)->JumpUp)\
                .arg(List_Debounce_Infos_User.at(i)->JumpDown)\
                .arg(StrList_Behavior.at(List_Debounce_Infos_User.at(i)->behavior)));
    }
    Str_Temp.append("\n#endif\n\n");
    S_File_DemConfigs.Str_Debounce_Table = Str_Temp;
}

void FG_ParseDTCConfig()
{
    uint8 i = 0;
    uint8 j = 0;
    uint8 row = 0;
    QString Str_Temp_DTC_Value;
    QString Str_Temp_DTC_Attributes;
    QString Str_Temp_Event_Paramters;
    QString Str_Temp_DTC_Value_Define;

    
    row = List_DTC_Infos_User.count();
    S_File_DemConfigs.Str_DTC_Table.clear();
    S_File_DemConfigs.Str_DTC_Attributes_Table.clear();
    S_File_DemConfigs.Str_Event_Parameters_Table.clear();
    Str_Temp_DTC_Value_Define = "//Index of Event \n";

    Str_Temp_DTC_Value = "//DTC Value\n";
    Str_Temp_DTC_Value .append(QString("#define Dem_Cfg_Num_Of_Event\t\t((uint8)%1)\n").arg(row));
    Str_Temp_DTC_Value .append(QString("#define Dem_Cfg_Num_Of_DTC\t\t\t(Dem_Cfg_Num_Of_Event)\n\n"));
    Str_Temp_DTC_Value .append("#ifndef DEM_TABLE_DTC\n")\
                       .append("#define DEM_TABLE_DTC \\\n")\
                       .append("\t/*Index  Dtc Value, DTC Attribute Ref*/\\\n");

    Str_Temp_DTC_Attributes = "//DTC Attributes Table\n";
    Str_Temp_DTC_Attributes .append("#ifndef DEM_TABLE_DTC_ATTRIBUTES\n")\
                            .append("#define DEM_TABLE_DTC_ATTRIBUTES \\\n")\
                            .append("\t/*Index, AgingThershold, AgingOpCycleRef, ImmediateNvStorageAllowed, AgingAllowed*/\\\n");

    Str_Temp_Event_Paramters = "//Event Table\n";
    Str_Temp_Event_Paramters .append("#ifndef DEM_TABLE_EVENT_PARAMETERS\n")\
                             .append("#define DEM_TABLE_EVENT_PARAMETERS \\\n")\
                             .append("\t/* Index CB_InitMForE, Event ID, EventKind, FDCThershold, Debounce TabRef, OpCycleRef, DTC TabRef, EnCntRef, StrCntRef, Available Status  */\\\n");


    for(i = 0; i < row; i++)
    {
        QString Str_Dtc = QString::number(List_DTC_Infos_User.at(i)->Value, 16).toUpper();

        Str_Temp_DTC_Value_Define.append(QString("#define INDEX_DTC_EVENT_%1\t\t(0x%2)\n")\
                                 .arg(Str_Dtc, 6, QChar('0')).arg(i));

        Str_Temp_DTC_Value.append(QString("\t{ /* %1 */0x%2, %3},\\\n")\
                          .arg(i).arg(Str_Dtc, 6, QChar('0'))\
                          .arg(List_DTC_Infos_User.at(i)->AttrbsRef));
                          
        Str_Temp_DTC_Attributes.append(QString("\t{ /* %1 */%2, %3, %4, %5},\\\n")\
                               .arg(i)\
                               .arg(List_DTC_Infos_User.at(i)->AgingThershold)\
                               .arg(List_DTC_Infos_User.at(i)->AgingOpCycleRef)\
                               .arg(StrList_Bool.at(List_DTC_Infos_User.at(i)->ImmediateNvStorageAllowed))\
                               .arg(StrList_Bool.at(List_DTC_Infos_User.at(i)->AgingAllowed)));
        
        Str_Temp_Event_Paramters.append(QString("\t{ /* %1 */%2, %3, %4, %5, %6, %7, %8, %9, %10, %11},\\\n")\
                                .arg(i)\
                                .arg(List_DTC_Infos_User.at(i)->DemCallbackInitMForE)\
                                .arg(List_DTC_Infos_User.at(i)->Id)\
                                .arg(StrList_EventKind.at(List_DTC_Infos_User.at(i)->EventKind))\
                                .arg(List_DTC_Infos_User.at(i)->FailureCycleCounterThershold)\
                                .arg(List_DTC_Infos_User.at(i)->DebounceTableRef)\
                                .arg(List_DTC_Infos_User.at(i)->OpCycleRef)\
                                .arg(List_DTC_Infos_User.at(i)->DTCTableRef)\
                                .arg(List_DTC_Infos_User.at(i)->EnableConditionRef)\
                                .arg(List_DTC_Infos_User.at(i)->StorageConditionRef)\
                                .arg(StrList_Bool.at(List_DTC_Infos_User.at(i)->AvailableStatus)));
    }
    
    Str_Temp_DTC_Value.append("\n#endif\n\n");
    Str_Temp_DTC_Attributes.append("\n#endif\n\n");
    Str_Temp_Event_Paramters.append("\n#endif\n\n");

    S_File_DemConfigs.Str_DTC_Value_Define = Str_Temp_DTC_Value_Define;
    S_File_DemConfigs.Str_DTC_Table = Str_Temp_DTC_Value;
    S_File_DemConfigs.Str_DTC_Attributes_Table = Str_Temp_DTC_Attributes;
    S_File_DemConfigs.Str_Event_Parameters_Table = Str_Temp_Event_Paramters;
}

void Generate_Dcm_Cfg_Generate_h(void)
{
#ifdef RELEASE
    QString Str_ConfigFile_Name = "./../Output/Dcm_Cfg_Generate.h";
#else
    QString Str_ConfigFile_Name = "./../DiagGenerateTool/Output/Dcm_Cfg_Generate.h";
#endif
    QFile File_Config(Str_ConfigFile_Name);
    QTextStream Text_Out(&File_Config);

    //移除之前的生成文件
    if(File_Config.exists())
    {
      File_Config.remove();
    }

    if(false != File_Config.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        //写入文件头
        Text_Out << "/*********************************************************************/" << endl\
                 << "/*                       DiagTool.Generate Start                     */" << endl\
                 << "/*********************************************************************/" << endl\
                 << endl \
                 << "#ifndef __DCM_CFG_GENERATE_H__" << endl\
                 << "#define __DCM_CFG_GENERATE_H__" << endl \
                 << endl;

        Text_Out << Str_File_DcmGemeral_Configs << endl << endl;

        Text_Out << S_File_DidConfigs.Str_DidCount << endl;
        Text_Out << S_File_DidConfigs.Str_DidOpInfoCount << endl << endl;
        Text_Out << S_File_DidConfigs.Str_DidMacros << endl << endl;
        Text_Out << S_File_DidConfigs.Str_DidTable << endl << endl;
        Text_Out << S_File_DidConfigs.Str_DidInfoTable << endl << endl;
        Text_Out << S_File_DidConfigs.Str_DidOpInfoTable << endl << endl;

        Text_Out << S_File_RidConfigs.Str_RidCount << endl;
        Text_Out << S_File_RidConfigs.Str_RidSignalInfoCount << endl << endl;
        Text_Out << S_File_RidConfigs.Str_RidMacros << endl << endl;
        Text_Out << S_File_RidConfigs.Str_RidTable << endl << endl;
        Text_Out << S_File_RidConfigs.Str_RidInfoTable << endl << endl;
        Text_Out << S_File_RidConfigs.Str_RidSignalInfoTable << endl << endl;

        //写入文件尾
        Text_Out << endl \
                 << "#endif" << endl \
                 << "/*********************************************************************/" << endl\
                 << "/*                       DiagTool.Generate Stop                      */" << endl\
                 << "/*********************************************************************/" << endl\
                 << endl;
        File_Config.close();
    }
    else
    {
        qDebug("File Open Failed");
        Result_Generate = false;
    }
}

void Generate_DcmExt_Generate_c(void)
{
#ifdef RELEASE
    QString Str_ConfigFile_Name = "./../Output/DcmExt_Generate.c";
#else
    QString Str_ConfigFile_Name = "./../DiagGenerateTool/Output/DcmExt_Generate.c";
#endif
    QFile File_Config(Str_ConfigFile_Name);
    QTextStream Text_Out(&File_Config);

    //移除之前的生成文件
    if(File_Config.exists())
    {
      File_Config.remove();
    }

    if(false != File_Config.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        //写入文件头
        Text_Out << "/*********************************************************************/" << endl\
                 << "/*                       DiagTool.Generate Start                     */" << endl\
                 << "/*********************************************************************/" << endl\
                 << endl \
                 << "#ifndef __DCMEXT_GENERATE_C__" << endl\
                 << "#define __DCMEXT_GENERATE_C__" << endl \
                 << endl;

        Text_Out << "#include \"DcmExt.h\"" << endl;
        Text_Out << "#include \"DcmExt_Generate.h\"" << endl;
        Text_Out << "#include \"NvM_Server.h\"" << endl << endl;

        Text_Out << "#define E_OK        (0u)" << endl;
        Text_Out << "#define E_NOT_OK    (1u)" << endl << endl;

        Text_Out << Str_UserComCode_StartFlag;
        Text_Out << Str_UserCode_Common;
        Text_Out << Str_UserComCode_EndFlag << endl;

        Text_Out << S_File_DidConfigs.Str_ReadFunctions_Define << endl;
        Text_Out << S_File_DidConfigs.Str_WriteFunctions_Define << endl;
        Text_Out << S_File_DidConfigs.Str_IOCFunctions_Define << endl;
        Text_Out << S_File_RidConfigs.Str_RidFunctions_Define << endl;

        //写入文件尾
        Text_Out << endl \
                 << "#endif" << endl \
                 << "/*********************************************************************/" << endl\
                 << "/*                       DiagTool.Generate Stop                      */" << endl\
                 << "/*********************************************************************/" << endl\
                 << endl;
        File_Config.close();
    }
    else
    {
        qDebug("File Open Failed");
        Result_Generate = false;
    }
}

void Generate_DcmExt_Generate_h(void)
{
#ifdef RELEASE
    QString Str_ConfigFile_Name = "./../Output/DcmExt_Generate.h";
#else
    QString Str_ConfigFile_Name = "./../DiagGenerateTool/Output/DcmExt_Generate.h";
#endif
    QFile File_Config(Str_ConfigFile_Name);
    QTextStream Text_Out(&File_Config);

    //移除之前的生成文件
    if(File_Config.exists())
    {
      File_Config.remove();
    }

    if(false != File_Config.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        //写入文件头
        Text_Out << "/*********************************************************************/" << endl\
                 << "/*                       DiagTool.Generate Start                     */" << endl\
                 << "/*********************************************************************/" << endl\
                 << endl \
                 << "#ifndef __DCMEXT_GENERATE_H__" << endl\
                 << "#define __DCMEXT_GENERATE_H__" << endl \
                 << endl;

        Text_Out << "#include \"Std_Types.h\"" << endl << endl;

        Text_Out << "#define DID_0x2FDID_SIZE_2\t\t ((uint8)2)\n";
        Text_Out << "#define DR_TIME_NOT_REQ\t\t ((uint32)0)\n";
        Text_Out << "#define ROUTINE_TYPE_1\t\t(0x01u)\n";
        Text_Out << "#define ROUTINE_TYPE_2\t\t(0x02u)\n";
        Text_Out << "#define RC_STOP_SERVICE\t\t(0x04u)\n";
        Text_Out << "#define RC_SELFTEST\t\t(0x10u)\n";
        Text_Out << "#define NO_SPACE_AVAILABLE\t\t(0xFF)\n";
        Text_Out << "#define LHVSD_CHECK_NEEDED\t\t(0xFF)\n";
        Text_Out << "#define LHVSD_CHECK_NOT_NEEDED\t\t(0x00)\n\n";

        Text_Out << S_File_DcmConfigs.Str_ServiceDefine << endl;

        Text_Out << S_File_DidConfigs.Str_DidMacros << endl;
        Text_Out << S_File_DidConfigs.Str_DcmTable_Read << endl;
        Text_Out << S_File_DidConfigs.Str_DcmTable_Write << endl;
        Text_Out << S_File_DidConfigs.Str_DcmTable_IOCTRL << endl;
        Text_Out << S_File_DidConfigs.Str_ReadFunctions_Declaration << endl;
        Text_Out << S_File_DidConfigs.Str_WriteFunctions_Declaration << endl;
        Text_Out << S_File_DidConfigs.Str_IOCFunctions_Declaration << endl;

        Text_Out << S_File_RidConfigs.Str_RidMacros << endl;
        Text_Out << S_File_RidConfigs.Str_Rid_RTN_Record << endl;
        Text_Out << S_File_RidConfigs.Str_RidFunctions_Declaration << endl;


        //写入文件尾
        Text_Out << endl \
                 << "#endif" << endl \
                 << "/*********************************************************************/" << endl\
                 << "/*                       DiagTool.Generate Stop                      */" << endl\
                 << "/*********************************************************************/" << endl\
                 << endl;
        File_Config.close();
    }
    else
    {
        qDebug("File Open Failed");
        Result_Generate = false;
    }
}

void Generate_Dem_Cfg_Generate_h(void)
{
#ifdef RELEASE
    QString Str_ConfigFile_Name = "./../Output/Dem_Cfg_Generate.h";
#else
    QString Str_ConfigFile_Name = "./../DiagGenerateTool/Output/Dem_Cfg_Generate.h";
#endif
    QFile File_Config(Str_ConfigFile_Name);
    QTextStream Text_Out(&File_Config);

    //移除之前的生成文件
    if(File_Config.exists())
    {
      File_Config.remove();
    }

    if(false != File_Config.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        //写入文件头
        S_File_DemConfigs.Str_File_Start = QString("/*********************************************************************/\n")\
                 .append("/*                       DiagTool.Generate Start                     */\n")\
                 .append("/*********************************************************************/\n")\
                 .append("\n")\
                 .append("#ifndef __DEM_CFG_GENERATE_H__\n")\
                 .append("#define __DEM_CFG_GENERATE_H__\n")\
                 .append("\n");
        S_File_DemConfigs.Str_File_Start.append("#include \"Std_Types.h\"\n\n");

        S_File_DemConfigs.Str_Macro_Define = QString("//Dem Event Kind\n")\
                 .append("#define DEM_EVENT_KIND_BSW\t\t ((uint8)0)\n")\
                 .append("#define DEM_EVENT_KIND_SWC\t\t ((uint8)1)\n\n");

        S_File_DemConfigs.Str_Macro_Define.append("//Dem Debounce class\n")\
                 .append("#define DEM_CFG_DEBOUNCETYPE_COUNTER\t\t((uint8)0)\n")\
                 .append("#define DEM_CFG_DEBOUNCETYPE_TIMER\t\t((uint8)1)\n")\
                 .append("#define DEM_CFG_DEBOUNCETYPE_EXTERNAL\t\t((uint8)2)\n")\
                 .append("#define DEM_CFG_DEBOUNCETYPE_INVALID\t\t((uint8)3)\n\n")\
                 .append("#define DEM_DEBOUNCE_FREEZE\t\t((uint8)0)\n")\
                 .append("#define DEM_DEBOUNCE_RESET\t\t((uint8)1)\n\n");

        S_File_DemConfigs.Str_Macro_Define.append("//Dem Operation Cycle ID's\n")\
                 .append("#define DemOpCycle_Ignition\t\t((uint8)0)\n")\
                 .append("#define DemOpCycle_Profile2\t\t((uint8)1)\n")\
                 .append("#define DemOpCycle_Profile3\t\t((uint8)2)\n")\
                 .append("#define DemOpCycle_Profile4\t\t((uint8)3)\n\n");

        Text_Out << S_File_DemConfigs.Str_File_Start << endl;
        Text_Out << S_File_DemConfigs.Str_Macro_Define << endl;
        Text_Out << S_File_DemConfigs.Str_OpCycle_Table << endl;
        Text_Out << S_File_DemConfigs.Str_Debounce_Table << endl;
        Text_Out << S_File_DemConfigs.Str_DTC_Table << endl;
        Text_Out << S_File_DemConfigs.Str_DTC_Value_Define << endl;
        Text_Out << S_File_DemConfigs.Str_DTC_Attributes_Table << endl;
        Text_Out << S_File_DemConfigs.Str_Event_Parameters_Table << endl;

        //写入文件尾
        Text_Out << endl \
                 << "#endif" << endl \
                 << "/*********************************************************************/" << endl\
                 << "/*                       DiagTool.Generate Stop                      */" << endl\
                 << "/*********************************************************************/" << endl\
                 << endl;
        File_Config.close();
    }
    else
    {
        qDebug("File Open Failed");
        Result_Generate = false;
    }
}

void FG_GetUserCode(void)
{
#ifdef RELEASE
    QString Str_ConfigFile_Name = "./../Output/DcmExt_Generate.c";
#else
    QString Str_ConfigFile_Name = "./../DiagGenerateTool/Output/DcmExt_Generate.c";
#endif
    QString Str_line;
    QRegExp Rex(".*[0-9A-F]{4}.*");//正则表达式，匹配4个(0-9或A-F)的值
    QString Str_CurFunName;

    bool Result = false;
    S_UserCode_Type* Ptr_UserFunCode_Temp;
    QFile File_Config(Str_ConfigFile_Name);
    QTextStream Text_Out(&File_Config);

//    if(File_Config.exists())
//    {
//      File_Config.remove();
//    }

    //逐行读取，取出用户代码
    Str_UserCode_Common.clear();
    List_UserCode.clear();
    if(false != File_Config.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        while(!File_Config.atEnd())
        {
            Str_line = File_Config.readLine();
            //获取ComUserCode
            if(Str_UserCode_Common.isEmpty())
            {
                if(Str_line == Str_ComCode_StartFlag[0])
                {
                   Str_line = File_Config.readLine();
                   if(Str_line == Str_ComCode_StartFlag[1])
                   {
                       Str_line = File_Config.readLine();
                       if(Str_line == Str_ComCode_StartFlag[2])
                       {
                           Str_line = File_Config.readLine();
                           if(Str_line == Str_ComCode_StartFlag[3])
                           {
                                Str_line = File_Config.readLine();
                                while(Str_line != Str_ComCode_EndFlag[0])
                                {
                                    Str_UserCode_Common.append(Str_line);
                                    Str_line = File_Config.readLine();
                                }
                           }
                       }
                   }
                }
            }

            //获取FunUserCode
            //匹配正则表达式
            Result = Rex.exactMatch(Str_line);
            //匹配成功，说明当前行定义有ID值，获取该行数据
            if(false != Result)
            {
                QString Str_Match;
                QString Str_Section;
                //int index;
                Str_Match = Rex.capturedTexts().at(0);
                Str_CurFunName = Str_Match;
//                //根据正则表达式，找到ID在当前字符串的index
//                index = Str_Match.indexOf(QRegExp("[0-9A-F]{4}_Read"));
//                if((-1) != index)
//                {
//                    qDebug() << Str_Match;
//                    //从当前index,往后找4位
//                    Str_CurFunName = Str_Match.mid(index, 4).toUShort(&Result, 16);
//                    qDebug() << "Id Found: " << QString::number(CurId,16);
//                }
//                else
//                {
//                    Str_CurFunName = 0xFFFF;
//                }
            }

            if(Str_line == Str_FunCode_StartFlag[0])
            {
               Str_line = File_Config.readLine();
               if(Str_line == Str_FunCode_StartFlag[1])
               {
                   Str_line = File_Config.readLine();
                   if(Str_line == Str_FunCode_StartFlag[2])
                   {
                       Str_line = File_Config.readLine();
                       if(Str_line == Str_FunCode_StartFlag[3])
                       {
                           Ptr_UserFunCode_Temp = new S_UserCode_Type;
                           Ptr_UserFunCode_Temp->Str_FunctionName = Str_CurFunName;

                           Str_line = File_Config.readLine();
                            while(Str_line != Str_FunCode_EndFlag[0])
                            {
                                Ptr_UserFunCode_Temp->Str_UserCode.append(Str_line);
                                 Str_line = File_Config.readLine();
                            }
                            List_UserCode.append(Ptr_UserFunCode_Temp);
                       }
                   }
               }
            }
        }
    }
    File_Config.close();
}

