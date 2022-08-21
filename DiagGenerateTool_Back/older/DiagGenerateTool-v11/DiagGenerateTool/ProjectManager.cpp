#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ProjectManager.h"

extern MainWindow* MW;
//当前配置工程
QString Str_CurProject_Name;

#define DEM_CFG_DEBOUNCETYPE_COUNTER        (0)
#define DEM_CFG_DEBOUNCETYPE_TIMER          (1)
#define DEM_CFG_DEBOUNCETYPE_EXTERNAL       (2U)
#define DEM_CFG_DEBOUNCETYPE_INVALID        (3)

#define DEM_DEBOUNCE_FREEZE             (0U)
#define DEM_DEBOUNCE_RESET              (1U)

#define DEM_EVENT_KIND_BSW    0x00U
#define DEM_EVENT_KIND_SWC    0x01U

S_OpCycle_Infos_User_Type S_OpCycle_Infos_User_Default[4] =
{
    {0, 0, 0, 0 },\
    {1, 0, 0, 0 },\
    {2, 0, 0, 0 },\
    {3, 0, 1, 1 },\
};

//Debounce 默认值
S_Debounce_Infos_User_Type S_Debounce_Infos_User_Default[3] = \
{
    {0, 0, 100, 100, 0, 0, 0, 0, DEM_CFG_DEBOUNCETYPE_TIMER, 0, 0, DEM_DEBOUNCE_RESET },
    {127, -128, 0, 0, -1, 1, 0, 0, DEM_CFG_DEBOUNCETYPE_COUNTER, 0, 0, DEM_DEBOUNCE_RESET },
    {0, 0, 0, 0, 0, 0, 0, 0, DEM_CFG_DEBOUNCETYPE_INVALID, 0, 0, DEM_DEBOUNCE_RESET },
};

//DTC 默认值
S_DTC_Infos_User_Type S_DTC_Infos_User_Default[4] = \
{
    /* Index CB_InitMForE, Event ID, EventKind, FDCThershold, Debounce TabRef, OpCycleRef, DTC TabRef, EnCntRef, StrCntRef, Available Status  */
    { /* 0 */0x00FFFFFFUL, 0, 255U,4U, FALSE, FALSE, "((void *) 0)", 0, DEM_EVENT_KIND_BSW, 255U, 255U, 4U, 0U, 0x0,0x0, FALSE },
    { /* 1 */0x00000000UL, 1, 40U, 0, TRUE, TRUE, "((void *) 0)", 1, DEM_EVENT_KIND_BSW, 255U, 255U, 2,  1U, 0x0, 0x0, TRUE },
    { /* 2 */0x00000000UL, 2, 40U, 0, TRUE, TRUE, "((void *) 0)", 2, DEM_EVENT_KIND_SWC, 255U, 255U, 2,  2U, 0x0, 0x0, TRUE },
    { /* 3 */0x00F00316UL, 3, 40U, 0, TRUE, TRUE, "((void *) 0)", 3, DEM_EVENT_KIND_BSW, 255U, 1,   3,  3U, 0x0, 0x0, TRUE },
};

//新建一个工程
void PM_NewProject(void)
{
    uint8 i = 0;
    Str_CurProject_Name.clear();
    List_DID_Infos_User.clear();
    List_RID_Infos_User.clear();
    List_DcmGeneral_Infos_User.clear();
    List_OpCycle_Infos_User.clear();
    List_Debounce_Infos_User.clear();
    List_DTC_Infos_User.clear();

    //设置Dcm_General的默认配置项
    QStringList StrList_Items;
    QStringList StrList_Value;
    StrList_Items << "DcmTesterResponseAddr" \
                  << "DcmTesterSourcePhyAddr" \
                  << "DcmTesterSourceFuncAddr" \
                  << "DcmDslBufferSize";
    StrList_Value << "2" << "1" << "0" << "4095";

    for(uint8 i = 0; i < StrList_Items.count(); i++)
    {
        S_DcmGeneral_Infos_User_Type* Ptr_DcmGeneral_Test = new S_DcmGeneral_Infos_User_Type;
        Ptr_DcmGeneral_Test->Item = StrList_Items.at(i);
        Ptr_DcmGeneral_Test->Value = StrList_Value.at(i);

        List_DcmGeneral_Infos_User.append(Ptr_DcmGeneral_Test);
    }

    //设置OpCycle的默认值
    for(i = 0; i < 4; i++)
    {
        List_OpCycle_Infos_User.append(&S_OpCycle_Infos_User_Default[i]);
    }

    //设置DebounceTable默认值
    for(i = 0; i < 3; i++)
    {
        List_Debounce_Infos_User.append(&S_Debounce_Infos_User_Default[i]);
    }

    //设置DTC的默认值
    for(i = 0; i < 4; i++)
    {
        List_DTC_Infos_User.append(&S_DTC_Infos_User_Default[i]);
    }
}


//保存配置工程
void PM_SaveConfigInfo(void)
{
    uint8 i = 0;
    QFile File_DiagConfig;
    //QFile File_DiagConfig("./../DiagGenerateTool/Config/Diag_Config.xml");Str_FileName
    if(!Str_CurProject_Name.isEmpty())
    {
        File_DiagConfig.setFileName(Str_CurProject_Name);
    }
    else
    {
        Str_CurProject_Name = QFileDialog::getSaveFileName(nullptr,"Save Config File",\
                                                           "./../DiagGenerateTool/Config",\
                                                          ("xml (*.xml)"));
        File_DiagConfig.setFileName(Str_CurProject_Name);
    }
    QTextStream Text_Config(&File_DiagConfig);
    QDomText Text;
    QDomDocument Dom_DiagConfig;
    QDomElement SubNode;
    QDomProcessingInstruction Instruction;

    QDomElement Root = Dom_DiagConfig.createElement("DiagConfigs");
    QDomElement Child_l1_DcmConfig = Dom_DiagConfig.createElement("DcmConfig");
    QDomElement Child_l1_DemConfig = Dom_DiagConfig.createElement("DemConfig");

    QDomElement Child_l2_DcmGeneralConfig = Dom_DiagConfig.createElement("DcmGeneralConfig");
    QDomElement Child_l2_DidConfig = Dom_DiagConfig.createElement("DidConfig");
    QDomElement Child_l2_RidConfig = Dom_DiagConfig.createElement("RidConfig");

    QDomElement Child_l2_OpCycleConfig = Dom_DiagConfig.createElement("OpCycleConfig");
    QDomElement Child_l2_DebounceConfig = Dom_DiagConfig.createElement("DebounceConfig");
    QDomElement Child_l2_DTCConfig = Dom_DiagConfig.createElement("DTCConfig");

    //添加1级节点
    Root.appendChild(Child_l1_DcmConfig);
    Root.appendChild(Child_l1_DemConfig);

    //添加2级节点
    Child_l1_DcmConfig.appendChild(Child_l2_DcmGeneralConfig);
    Child_l1_DcmConfig.appendChild(Child_l2_DidConfig);
    Child_l1_DcmConfig.appendChild(Child_l2_RidConfig);

    Child_l1_DemConfig.appendChild(Child_l2_OpCycleConfig);
    Child_l1_DemConfig.appendChild(Child_l2_DebounceConfig);
    Child_l1_DemConfig.appendChild(Child_l2_DTCConfig);

    //DcmGeneralConfig 子节点
    for(i = 0; i < List_DcmGeneral_Infos_User.count(); i++)
    {
        SubNode = Dom_DiagConfig.createElement("subItem");
        SubNode.setTagName("DcmGeneralConfig:");
        SubNode.setAttribute(List_DcmGeneral_Infos_User.at(i)->Item, List_DcmGeneral_Infos_User.at(i)->Value);
        Child_l2_DcmGeneralConfig.appendChild(SubNode);
    }

    //DidConfig 子节点
    for(i = 0; i < List_DID_Infos_User.count(); i++)
    {
       SubNode = Dom_DiagConfig.createElement("subItem");
       SubNode.setTagName("DidConfig:");
       SubNode.setAttribute("Did", QString::number(List_DID_Infos_User.at(i)->Did, 16));
       SubNode.setAttribute("DataLen", QString::number(List_DID_Infos_User.at(i)->DataLen, 16));
       SubNode.setAttribute("Operation", QString::number(List_DID_Infos_User.at(i)->Operation, 16));
       Child_l2_DidConfig.appendChild(SubNode);
    }

    //RidConfig 子节点
    for(i = 0; i < List_RID_Infos_User.count(); i++)
    {
       SubNode = Dom_DiagConfig.createElement("subItem");
       SubNode.setTagName("RidConfig:");
       SubNode.setAttribute("Rid", QString::number(List_RID_Infos_User.at(i)->Rid, 16));
       SubNode.setAttribute("Operation", QString::number(List_RID_Infos_User.at(i)->Operation, 16));
       SubNode.setAttribute("RoutineType", QString::number(List_RID_Infos_User.at(i)->RoutineType, 16));
       SubNode.setAttribute("RoutineControlOptionRecord", QString::number(List_RID_Infos_User.at(i)->RoutineControlOptionRecord, 16));
       Child_l2_RidConfig.appendChild(SubNode);
    }

    //OpCycle 子节点
    for(i = 0; i < List_OpCycle_Infos_User.count(); i++)
    {
        SubNode = Dom_DiagConfig.createElement("subItem");
        SubNode.setTagName("OpCycleConfig:");
        SubNode.setAttribute("Id", QString::number(List_OpCycle_Infos_User.at(i)->Id, 10));
        SubNode.setAttribute("Type", QString::number(List_OpCycle_Infos_User.at(i)->Type, 10));
        SubNode.setAttribute("AutoStart", QString::number(List_OpCycle_Infos_User.at(i)->AutoStart, 10));
        SubNode.setAttribute("AutoStop", QString::number(List_OpCycle_Infos_User.at(i)->AutoStop, 10));
        Child_l2_OpCycleConfig.appendChild(SubNode);
    }

    //Debounce 子节点
    for(i = 0; i < List_Debounce_Infos_User.count(); i++)
    {
        SubNode = Dom_DiagConfig.createElement("subItem");
        SubNode.setTagName("DebounceConfig:");
        SubNode.setAttribute("FailedThershold", QString::number(List_Debounce_Infos_User.at(i)->FailedThershold, 10));
        SubNode.setAttribute("PassedThershold", QString::number(List_Debounce_Infos_User.at(i)->PassedThershold, 10));
        SubNode.setAttribute("FailedTimeThershold", QString::number(List_Debounce_Infos_User.at(i)->FailedTimeThershold, 10));
        SubNode.setAttribute("PassedTimeThershold", QString::number(List_Debounce_Infos_User.at(i)->PassedTimeThershold, 10));
        SubNode.setAttribute("DecStepSize", QString::number(List_Debounce_Infos_User.at(i)->DecStepSize, 10));
        SubNode.setAttribute("IncStepSize", QString::number(List_Debounce_Infos_User.at(i)->IncStepSize, 10));
        SubNode.setAttribute("JumpUpValue", QString::number(List_Debounce_Infos_User.at(i)->JumpUpValue, 10));
        SubNode.setAttribute("JumpDownValue", QString::number(List_Debounce_Infos_User.at(i)->JumpDownValue, 10));
        SubNode.setAttribute("AlgoClass", QString::number(List_Debounce_Infos_User.at(i)->AlgoClass, 10));
        SubNode.setAttribute("JumpUp", QString::number(List_Debounce_Infos_User.at(i)->JumpUp, 10));
        SubNode.setAttribute("JumpDown", QString::number(List_Debounce_Infos_User.at(i)->JumpDown, 10));
        SubNode.setAttribute("behavior", QString::number(List_Debounce_Infos_User.at(i)->behavior, 10));
        Child_l2_DebounceConfig.appendChild(SubNode);
    }

    //DTC 子节点
    for(i = 0; i < List_DTC_Infos_User.count(); i++)
    {
        SubNode = Dom_DiagConfig.createElement("subItem");
        SubNode.setTagName("DTCConfig:");
        SubNode.setAttribute("Value", QString::number(List_DTC_Infos_User.at(i)->Value, 16));
        SubNode.setAttribute("AttrbsRef", QString::number(List_DTC_Infos_User.at(i)->AttrbsRef, 10));
        SubNode.setAttribute("AgingThershold", QString::number(List_DTC_Infos_User.at(i)->AgingThershold, 10));
        SubNode.setAttribute("AgingOpCycleRef", QString::number(List_DTC_Infos_User.at(i)->AgingOpCycleRef, 10));
        SubNode.setAttribute("ImmediateNvStorageAllowed", QString::number(List_DTC_Infos_User.at(i)->ImmediateNvStorageAllowed, 10));
        SubNode.setAttribute("AgingAllowed", QString::number(List_DTC_Infos_User.at(i)->AgingAllowed, 10));
        SubNode.setAttribute("DemCallbackInitMForE", List_DTC_Infos_User.at(i)->DemCallbackInitMForE);
        SubNode.setAttribute("Id", QString::number(List_DTC_Infos_User.at(i)->Id, 10));
        SubNode.setAttribute("EventKind", QString::number(List_DTC_Infos_User.at(i)->EventKind, 10));
        SubNode.setAttribute("FailureCycleCounterThershold", QString::number(List_DTC_Infos_User.at(i)->FailureCycleCounterThershold, 10));
        SubNode.setAttribute("DebounceTableRef", QString::number(List_DTC_Infos_User.at(i)->DebounceTableRef, 10));
        SubNode.setAttribute("OpCycleRef", QString::number(List_DTC_Infos_User.at(i)->OpCycleRef, 10));
        SubNode.setAttribute("DTCTableRef", QString::number(List_DTC_Infos_User.at(i)->DTCTableRef, 10));
        SubNode.setAttribute("EnableConditionRef", QString::number(List_DTC_Infos_User.at(i)->EnableConditionRef, 10));
        SubNode.setAttribute("StorageConditionRef", QString::number(List_DTC_Infos_User.at(i)->StorageConditionRef, 10));
        SubNode.setAttribute("AvailableStatus", QString::number(List_DTC_Infos_User.at(i)->AvailableStatus, 10));
        Child_l2_DTCConfig.appendChild(SubNode);
    }

    //打开文件
    if(!File_DiagConfig.open(QFile::WriteOnly | QFile::Text))
    {
        qDebug() << "Open Config Failed";
        return;
    }
    else
    {
        qDebug() << "Open Config Success";
    }

    //加入说明
    //Instruction = Dom_DiagConfig.createProcessingInstruction("xml", "version = \"1.0\", encoding = \"UTF-8\"");
    //Dom_DiagConfig.appendChild(Instruction);
    Dom_DiagConfig.appendChild(Root);

    //保存文件，缩进量设置为4
    Dom_DiagConfig.save(Text_Config, 4);
    //关闭文件
    File_DiagConfig.close();
}



//读取配置
void PM_OpenProject(void)
{

    uint8 i = 0;
    uint8 j = 0;
    bool Result = false;
    QString Str_FileName = QFileDialog::getOpenFileName(nullptr,"Open Config File",\
                                                        "./../DiagGenerateTool/Config",\
                                                        ("xml (*.xml)"));
    Str_CurProject_Name = Str_FileName;
    
    List_DID_Infos_User.clear();
    List_RID_Infos_User.clear();
    List_DcmGeneral_Infos_User.clear();
    List_OpCycle_Infos_User.clear();
    List_Debounce_Infos_User.clear();
    List_DTC_Infos_User.clear();

    //QFile File_DiagConfig("./../DiagGenerateTool/Config/Diag_Config.xml");
    qDebug() << "ConfigFile Path" << Str_FileName;

    QFile File_DiagConfig(Str_FileName);
    QTextStream Text_Config(&File_DiagConfig);
    QDomText Text;
    QDomNodeList List_Node;
    QDomNamedNodeMap DomAttr_Map;
    QString Str_Key;
    QString Str_Value;

    S_DcmGeneral_Infos_User_Type* DcmGeneral_Temp;
    S_DID_Infos_User_Type* Did_UserType_Temp;
    S_RID_Infos_User_Type* Rid_UserType_Temp;
    S_OpCycle_Infos_User_Type* OpCycle_UserType_Temp;
    S_Debounce_Infos_User_Type* Debounce_UserType_Temp;
    S_DTC_Infos_User_Type* DTC_UserType_Temp;
    QDomDocument Dom_DiagConfig;

    //1. xml -> List_xxxx_Infos_User
    if(!File_DiagConfig.open(QFile::ReadOnly))
    {
        qDebug() << "Open Config Failed";
        return;
    }
    else
    {
        qDebug() << "Open Config Success";
        //将文件的内容读到DomDocument中
        QString Str;
        int ErrorLine;
        int ErrorColumn;
        if (!Dom_DiagConfig.setContent(&File_DiagConfig, false, &Str, &ErrorLine, &ErrorColumn))
        {
            qDebug() << "add setcontent error..." << "errorStr&&&&" \
                     << Str << "errorLine" << ErrorLine << "errorColume" << ErrorLine;
        }
        else
        {
            qDebug() << "Setcontent Succcess" ;
        }
        File_DiagConfig.close();
    }

    //DcmGeneral 配置
    //通过TagName获取所有NodeList
    List_Node = Dom_DiagConfig.elementsByTagName("DcmGeneralConfig:");
    //解析List_Node
    for(i = 0; i < List_Node.count(); i++)
    {
        DcmGeneral_Temp = new S_DcmGeneral_Infos_User_Type;
        DomAttr_Map = List_Node.at(i).attributes();
        for(j =0; j < DomAttr_Map.count(); j++)
        {
            Str_Key = DomAttr_Map.item(j).toAttr().name();
            Str_Value = DomAttr_Map.item(j).toAttr().value();
            DcmGeneral_Temp->Item = Str_Key;
            DcmGeneral_Temp->Value = Str_Value;
            List_DcmGeneral_Infos_User.append(DcmGeneral_Temp);
        }
    }

    //DID 配置
    List_Node = Dom_DiagConfig.elementsByTagName("DidConfig:");
    for(i = 0; i < List_Node.count(); i++)
    {
        Did_UserType_Temp = new S_DID_Infos_User_Type;
        DomAttr_Map = List_Node.at(i).attributes();
        for(j =0; j < DomAttr_Map.count(); j++)
        {
            Str_Key = DomAttr_Map.item(j).toAttr().name();
            Str_Value = DomAttr_Map.item(j).toAttr().value();
            if("Did" == Str_Key)
            {
                Did_UserType_Temp->Did = Str_Value.toUInt(&Result, 16);
            }
            else if("Operation" == Str_Key)
            {
                Did_UserType_Temp->Operation = Str_Value.toUInt(&Result, 16);
            }
            else if("DataLen" == Str_Key)
            {
                Did_UserType_Temp->DataLen = Str_Value.toUInt(&Result, 16);
            }
            else
            {
                /* do nothing */
            }
        }
        List_DID_Infos_User.append(Did_UserType_Temp);
    }

    //RID 配置
    List_Node = Dom_DiagConfig.elementsByTagName("RidConfig:");
    for(i = 0; i < List_Node.count(); i++)
    {
        Rid_UserType_Temp = new S_RID_Infos_User_Type;
        DomAttr_Map = List_Node.at(i).attributes();
        for(j =0; j < DomAttr_Map.count(); j++)
        {
            Str_Key = DomAttr_Map.item(j).toAttr().name();
            Str_Value = DomAttr_Map.item(j).toAttr().value();
            if("Rid" == Str_Key)
            {
                Rid_UserType_Temp->Rid = Str_Value.toUInt(&Result, 16);
            }
            else if("RoutineType" == Str_Key)
            {
                Rid_UserType_Temp->RoutineType = Str_Value.toUInt(&Result, 16);
            }
            else if("Operation" == Str_Key)
            {
                Rid_UserType_Temp->Operation = Str_Value.toUInt(&Result, 16);
            }
            else if("RoutineControlOptionRecord" == Str_Key)
            {
                Rid_UserType_Temp->RoutineControlOptionRecord = Str_Value.toUInt(&Result, 16);
            }
            else
            {
                /* do nothing */
            }
        }
        List_RID_Infos_User.append(Rid_UserType_Temp);
    }

    //OpCycle 配置
    List_Node = Dom_DiagConfig.elementsByTagName("OpCycleConfig:");
    for(i = 0; i < List_Node.count(); i++)
    {
        OpCycle_UserType_Temp = new S_OpCycle_Infos_User_Type;
        DomAttr_Map = List_Node.at(i).attributes();
        for(j =0; j < DomAttr_Map.count(); j++)
        {
            Str_Key = DomAttr_Map.item(j).toAttr().name();
            Str_Value = DomAttr_Map.item(j).toAttr().value();
            if("Id" == Str_Key)
            {
                OpCycle_UserType_Temp->Id = Str_Value.toUInt(&Result, 10);
            }
            else if("Type" == Str_Key)
            {
                OpCycle_UserType_Temp->Type = Str_Value.toUInt(&Result, 10);
            }
            else if("AutoStart" == Str_Key)
            {
                OpCycle_UserType_Temp->AutoStart = Str_Value.toUInt(&Result, 10);
            }
            else if("AutoStop" == Str_Key)
            {
                OpCycle_UserType_Temp->AutoStop = Str_Value.toUInt(&Result, 10);
            }
            else
            {
                /* do nothing */
            }
        }
        List_OpCycle_Infos_User.append(OpCycle_UserType_Temp);
    }

    //Debounce 配置
    List_Node = Dom_DiagConfig.elementsByTagName("DebounceConfig:");
    for(i = 0; i < List_Node.count(); i++)
    {
        Debounce_UserType_Temp = new S_Debounce_Infos_User_Type;
        DomAttr_Map = List_Node.at(i).attributes();
        for(j =0; j < DomAttr_Map.count(); j++)
        {
            Str_Key = DomAttr_Map.item(j).toAttr().name();
            Str_Value = DomAttr_Map.item(j).toAttr().value();
            if("FailedThershold" == Str_Key)
            {
                Debounce_UserType_Temp->FailedThershold = Str_Value.toInt(&Result, 10);
            }
            else if("PassedThershold" == Str_Key)
            {
                Debounce_UserType_Temp->PassedThershold = Str_Value.toInt(&Result, 10);
            }
            else if("FailedTimeThershold" == Str_Key)
            {
                Debounce_UserType_Temp->FailedTimeThershold = Str_Value.toInt(&Result, 10);
            }
            else if("PassedTimeThershold" == Str_Key)
            {
                Debounce_UserType_Temp->PassedTimeThershold = Str_Value.toInt(&Result, 10);
            }
            else if("DecStepSize" == Str_Key)
            {
                Debounce_UserType_Temp->DecStepSize = Str_Value.toInt(&Result, 10);
            }
            else if("IncStepSize" == Str_Key)
            {
                Debounce_UserType_Temp->IncStepSize = Str_Value.toInt(&Result, 10);
            }
            else if("JumpUpValue" == Str_Key)
            {
                Debounce_UserType_Temp->JumpUpValue = Str_Value.toInt(&Result, 10);
            }
            else if("JumpDownValue" == Str_Key)
            {
                Debounce_UserType_Temp->JumpDownValue = Str_Value.toInt(&Result, 10);
            }
            else if("AlgoClass" == Str_Key)
            {
                Debounce_UserType_Temp->AlgoClass = Str_Value.toInt(&Result, 10);
            }
            else if("JumpUp" == Str_Key)
            {
                Debounce_UserType_Temp->JumpUp = Str_Value.toInt(&Result, 10);
            }
            else if("JumpDown" == Str_Key)
            {
                Debounce_UserType_Temp->JumpDown = Str_Value.toInt(&Result, 10);
            }
            else if("behavior" == Str_Key)
            {
                Debounce_UserType_Temp->behavior = Str_Value.toInt(&Result, 10);
            }
            else
            {
                /* do nothing */
            }
        }
        List_Debounce_Infos_User.append(Debounce_UserType_Temp);
    }

    //DTC 配置
    List_Node = Dom_DiagConfig.elementsByTagName("DTCConfig:");
    for(i = 0; i < List_Node.count(); i++)
    {
        DTC_UserType_Temp = new S_DTC_Infos_User_Type;
        DomAttr_Map = List_Node.at(i).attributes();
        for(j =0; j < DomAttr_Map.count(); j++)
        {
            Str_Key = DomAttr_Map.item(j).toAttr().name();
            Str_Value = DomAttr_Map.item(j).toAttr().value();
            if("Value" == Str_Key)
            {
                DTC_UserType_Temp->Value = Str_Value.toInt(&Result, 16);
            }
            else if("AttrbsRef" == Str_Key)
            {
                DTC_UserType_Temp->AttrbsRef = Str_Value.toInt(&Result, 10);
            }
            else if("AgingThershold" == Str_Key)
            {
                DTC_UserType_Temp->AgingThershold = Str_Value.toInt(&Result, 10);
            }
            else if("AgingOpCycleRef" == Str_Key)
            {
                DTC_UserType_Temp->AgingOpCycleRef = Str_Value.toInt(&Result, 10);
            }
            else if("ImmediateNvStorageAllowed" == Str_Key)
            {
                DTC_UserType_Temp->ImmediateNvStorageAllowed = Str_Value.toInt(&Result, 10);
            }
            else if("AgingAllowed" == Str_Key)
            {
                DTC_UserType_Temp->AgingAllowed = Str_Value.toInt(&Result, 10);
            }
            else if("DemCallbackInitMForE" == Str_Key)
            {
                DTC_UserType_Temp->DemCallbackInitMForE = Str_Value;
            }
            else if("Id" == Str_Key)
            {
                DTC_UserType_Temp->Id = Str_Value.toInt(&Result, 10);
            }
            else if("EventKind" == Str_Key)
            {
                DTC_UserType_Temp->EventKind = Str_Value.toInt(&Result, 10);
            }
            else if("FailureCycleCounterThershold" == Str_Key)
            {
                DTC_UserType_Temp->FailureCycleCounterThershold = Str_Value.toInt(&Result, 10);
            }
            else if("DebounceTableRef" == Str_Key)
            {
                DTC_UserType_Temp->DebounceTableRef = Str_Value.toInt(&Result, 10);
            }
            else if("OpCycleRef" == Str_Key)
            {
                DTC_UserType_Temp->OpCycleRef = Str_Value.toInt(&Result, 10);
            }
            else if("DTCTableRef" == Str_Key)
            {
                DTC_UserType_Temp->DTCTableRef = Str_Value.toInt(&Result, 10);
            }
            else if("EnableConditionRef" == Str_Key)
            {
                DTC_UserType_Temp->EnableConditionRef = Str_Value.toInt(&Result, 10);
            }
            else if("StorageConditionRef" == Str_Key)
            {
                DTC_UserType_Temp->StorageConditionRef = Str_Value.toInt(&Result, 10);
            }
            else if("AvailableStatus" == Str_Key)
            {
                DTC_UserType_Temp->AvailableStatus = Str_Value.toInt(&Result, 10);
            }
            else
            {
                /* do nothing */
            }
        }
        List_DTC_Infos_User.append(DTC_UserType_Temp);
    }

    //2. List_xxxx_Infos_User -> StdModel_xxxx (用于界面显示)
    MW->TableView_UpdateDcmGeneral();
    MW->TableView_UpdateDid();
    MW->TableView_UpdateRid();    
    MW->TableView_UpdateOpCycle();
    MW->TableView_UpdateDebounce();
    MW->TableView_UpdateDTC();
}

