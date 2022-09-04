#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "FileGenerater.h"
#include "ProjectManager.h"
#include "TableView_Delegate.h"

//define in ProjectManger.c
extern QString Str_CurProject_Name;
extern S_NVM_Infos_User_Type S_NVM_Infos_Init_Value;
extern S_NVM_Infos_User_Type S_DTC_NVM_Infos_User_Default[3];

//define in FileGenerater.c
extern S_File_DidConfigs_Type S_File_DidConfigs;
extern S_File_RidConfigs_Type S_File_RidConfigs;
extern S_File_DcmConfigs_Type S_File_DcmConfigs;
extern QString Str_File_DcmGeneral_Configs;
extern QList<uint16> List_Did;
extern QList<uint16> List_Rid;
extern QList<Dcm_DspDidInfoType> List_DidInfo;
extern QList<Dcm_DspDidOpInfoType> List_DidOpInfo;
extern QList<Dcm_DspRidInfoType> List_RidInfo;
extern QList<Dcm_DspRidSignalInfoType> List_RidSignalInfo;
extern QList<S_RID_RTN_Record_Type> List_RTN_Record;
extern const State_SID_Ref_Type State_SID_Table[4];

//Project右键菜单
QString Str_ToolVersion = "DGT-v1.7-20220823";
QList<QAction*> List_Actions_Project;

//记录界面中的配置信息
//DcmGeneral配置
QList<S_DcmGeneral_Infos_User_Type*> List_DcmGeneral_Infos_User;
QList<S_RID_Infos_User_Type*> List_RID_Infos_User;
QList<S_DID_Infos_User_Type* > List_DID_Infos_User;
QList<S_OpCycle_Infos_User_Type*> List_OpCycle_Infos_User;
QList<S_Debounce_Infos_User_Type*> List_Debounce_Infos_User;
QList<S_DTC_Infos_User_Type* > List_DTC_Infos_User;
QList<S_NVM_Infos_User_Type* > List_NVM_Infos_User;
QList<S_FEE_Infos_User_Type* > List_FEE_Infos_User;
QList<S_NVM_Infos_User_Type* > List_DTC_NVM_Infos_User;

/* QTreeView的Item */
QStandardItem* Item_Diag[3];
QStandardItem* Item_DcmSub[3];
QStandardItem* Item_DemSub[4];
QStandardItem* Item_NVM[2];

uint8 l_DidTable_UpdateReason = TABLE_UPDATE_BY_OTHER;
uint8 l_RidTable_UpdateReason = TABLE_UPDATE_BY_OTHER;
uint8 l_OpCycleTable_UpdateReason = TABLE_UPDATE_BY_OTHER;
uint8 l_DebounceTable_UpdateReason = TABLE_UPDATE_BY_OTHER;
uint8 l_DTCTable_UpdateReason = TABLE_UPDATE_BY_OTHER;
uint8 l_NVMTable_UpdateReason = TABLE_UPDATE_BY_OTHER;

bool l_DidTableUpdate_Finished = true;
bool l_RidTableUpdate_Finished = true;
bool l_OpCycleTableUpdate_Finished = true;
bool l_DebounceTableUpdate_Finished = true;
bool l_DTCTableUpdate_Finished = true;
bool l_NVMTableUpdate_Finished = true;

QModelIndex Index_CurSelect;
//TreeView的item
QStandardItemModel StdModle_TreeConfig;

//DID右键菜单
QAction* Ptr_Action_AddDID;
QAction* Ptr_Action_DelDID;
QAction* Ptr_Action_InsertDID;
QMenu* Ptr_Menu_Did;

//RID右键菜单
QAction* Ptr_Action_AddRID;
QAction* Ptr_Action_DelRID;
QAction* Ptr_Action_InsertRID;
QMenu* Ptr_Menu_Rid;

//OpCycle右鍵菜单
QAction* Ptr_Action_AddOpCycle;
QAction* Ptr_Action_DelOpCycle;
QAction* Ptr_Action_InsertOpCycle;
QMenu* Ptr_Menu_OpCycle;

//Debounce右鍵菜单
QAction* Ptr_Action_AddDebounce;
QAction* Ptr_Action_DelDebounce;
QAction* Ptr_Action_InsertDebounce;
QMenu* Ptr_Menu_Debounce;

//DTC右鍵菜单
QAction* Ptr_Action_AddDTC;
QAction* Ptr_Action_DelDTC;
QAction* Ptr_Action_InsertDTC;
QMenu* Ptr_Menu_DTC;

//NVM 右鍵菜单
QAction* Ptr_Action_AddNVM;
QAction* Ptr_Action_DelNVM;
QAction* Ptr_Action_InsertNVM;
QMenu* Ptr_Menu_NVM;

/* QTabView的Item*/
QTableView* Ptr_TableView_Rid;
QTableView* Ptr_TableView_DcmGeneral;
QTableView* Ptr_TableView_OpCycle;
QTableView* Ptr_TableView_Debounce;
QTableView* Ptr_TableView_DTC;
QTableView* Ptr_TableView_NVM;
QTableView* Ptr_TableView_FEE;

//ComboBox 代理
QComboBox* Ptr_ComBox_Alogclass;
QComboBox* Ptr_ComBox_Behavior;
QComboBox* Ptr_Combox_EventKind;
QComboBox* Ptr_Combox_NvmDeviceKind;

ComboBox_Delegate* Ptr_ComBoxDelegate_AlgoClass;
ComboBox_Delegate* Ptr_ComBoxDelegate_Behavior;
ComboBox_Delegate* Ptr_ComBoxDelegate_EventKind;
ComboBox_Delegate* Ptr_ComBoxDelegate_DeviceKind;

//Checkbox 代理
CheckBoxDelegate* Ptr_Checkbox_Delegate_Did[4];

//数据模型
QStandardItemModel StdModel_Did;
QStandardItemModel StdModel_Rid;
QStandardItemModel StdModel_DcmGeneral;
QStandardItemModel StdModel_OpCycle;
QStandardItemModel StdModel_Debounce;
QStandardItemModel StdModel_DTC;
QStandardItemModel StdModel_NVM;
QStandardItemModel StdModel_FEE;

//常量
QStringList StrList_AlgoClass = {"DEM_CFG_DEBOUNCETYPE_COUNTER", "DEM_CFG_DEBOUNCETYPE_TIMER",\
                                 "DEM_CFG_DEBOUNCETYPE_EXTERNAL","DEM_CFG_DEBOUNCETYPE_INVALID"};
QStringList StrList_Behavior = {"DEM_DEBOUNCE_FREEZE", "DEM_DEBOUNCE_RESET"};
QStringList StrList_EventKind = {"DEM_EVENT_KIND_BSW", "DEM_EVENT_KIND_SWC"};
QStringList StrList_DeviceKind = {"MEMIF_FEE", "MEMIF_EA"};

//函数定义
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow_Init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::MainWindow_Init(void)
{

    //默认设置 Generate 不可点击
    ui->But_Generate->setEnabled(false);
    connect(ui->But_Generate, &QPushButton::clicked, this, &MainWindow::Slot_Generate);

    //增加菜单
    QStringList Str_Actinos;
    QAction* Ptr_Action_Temp;
    QMenu* Ptr_Menu_Project = new QMenu("File",this);
    Str_Actinos << "New Project" << "Open Project" << "Save Project" << "Save As" << "Close Project";
    for(uint8 i = 0; i < Str_Actinos.count(); i++)
    {
       Ptr_Action_Temp = new QAction(Str_Actinos.at(i));
       List_Actions_Project.append(Ptr_Action_Temp);
    }

    Ptr_Menu_Project->addActions(List_Actions_Project);
    //初始化时，"Save Project" "Save As" "Close Project",无法点击
    List_Actions_Project.at(2)->setEnabled(false);
    List_Actions_Project.at(3)->setEnabled(false);
    List_Actions_Project.at(4)->setEnabled(false);
    ui->menubar->addMenu(Ptr_Menu_Project);

    //设置菜单栏背景颜色
    ui->menubar->setStyleSheet("background-color:#D1D1D1");

    //关联File菜单槽函数
    connect(Ptr_Menu_Project, &QMenu::triggered, this, &MainWindow::Slot_FileMenu_Triggered);

    //每一项配置增加一个TableView
    qDebug() << "TableView Size: " << ui->TableView_Did->geometry();
    //Ptr_TableView_DcmGeneral = new QTableView(this);
    Ptr_TableView_DcmGeneral = new QTableView(ui->TableView_Did->parentWidget());
    Ptr_TableView_Rid = new QTableView(ui->TableView_Did->parentWidget());
    Ptr_TableView_OpCycle = new QTableView(ui->TableView_Did->parentWidget());
    Ptr_TableView_Debounce = new QTableView(ui->TableView_Did->parentWidget());
    Ptr_TableView_DTC = new QTableView(ui->TableView_Did->parentWidget());
    Ptr_TableView_NVM = new QTableView(ui->TableView_Did->parentWidget());
    Ptr_TableView_FEE = new QTableView(ui->TableView_Did->parentWidget());

    Ptr_TableView_DcmGeneral->setGeometry(ui->TableView_Did->geometry());
    //Ptr_TableView_DcmGeneral->setGeometry(ui->TableView_Did->geometry());
    Ptr_TableView_Rid->setGeometry(ui->TableView_Did->geometry());
    Ptr_TableView_OpCycle->setGeometry(ui->TableView_Did->geometry());
    Ptr_TableView_Debounce->setGeometry(ui->TableView_Did->geometry());
    Ptr_TableView_DTC->setGeometry(ui->TableView_Did->geometry());
    Ptr_TableView_NVM->setGeometry(ui->TableView_Did->geometry());
    Ptr_TableView_FEE->setGeometry(ui->TableView_Did->geometry());

    ui->TableView_Did->show();
    Ptr_TableView_DcmGeneral->hide();
    Ptr_TableView_Rid->hide();
    Ptr_TableView_OpCycle->hide();
    Ptr_TableView_Debounce->hide();
    Ptr_TableView_DTC->hide();
    Ptr_TableView_NVM->hide();
    Ptr_TableView_FEE->hide();
    ResizeLayout(ui->TableView_Did);

    //设置QTreeview的属性
    Item_Diag[0] = new QStandardItem("DCM Config");
    Item_DcmSub[0] = new QStandardItem("Dcm General Config");
    Item_DcmSub[1] = new QStandardItem("DID Table");
    Item_DcmSub[2] = new QStandardItem("RID Table");
    Item_Diag[0]->insertRow(0, Item_DcmSub[0]);
    Item_Diag[0]->insertRow(1, Item_DcmSub[1]);
    Item_Diag[0]->insertRow(2, Item_DcmSub[2]);

    Item_Diag[1] = new QStandardItem("DEM Config");
    Item_DemSub[0] = new QStandardItem("OpCycle Table");
    Item_DemSub[1] = new QStandardItem("Debounce Table");
    Item_DemSub[2] = new QStandardItem("DTC Config");
    Item_Diag[1]->insertRow(0, Item_DemSub[0]);
    Item_Diag[1]->insertRow(1, Item_DemSub[1]);
    Item_Diag[1]->insertRow(2, Item_DemSub[2]);

    Item_Diag[2] = new QStandardItem("NVM Config");
    Item_NVM[0] = new QStandardItem("NvM Block Config");
    Item_NVM[1] = new QStandardItem("FEE Config");
    Item_Diag[2]->insertRow(0, Item_NVM[0]);
    Item_Diag[2]->insertRow(1, Item_NVM[1]);

    StdModle_TreeConfig.insertRow(0, Item_Diag[0]);
    StdModle_TreeConfig.insertRow(1, Item_Diag[1]);
    StdModle_TreeConfig.insertRow(2, Item_Diag[2]);

    //禁止编辑
    Item_Diag[0]->setEditable(false);
    Item_Diag[1]->setEditable(false);
    Item_Diag[2]->setEditable(false);
    Item_DcmSub[0]->setEditable(false);
    Item_DcmSub[1]->setEditable(false);
    Item_DcmSub[2]->setEditable(false);
    Item_DemSub[0]->setEditable(false);
    Item_DemSub[1]->setEditable(false);
    Item_DemSub[2]->setEditable(false);
    Item_NVM[0]->setEditable(false);
    Item_NVM[1]->setEditable(false);

    //隐藏header
    ui->Tree_Config->setHeaderHidden(true);

    //设置QTreeView的属性
    connect(ui->Tree_Config, &QTreeView::clicked, this, &MainWindow::Slot_TreeView_Clicled);

    //增加DID Table右键菜单
    Ptr_Menu_Did = new QMenu(ui->TableView_Did);
    Ptr_Action_AddDID = Ptr_Menu_Did->addAction("Add Did");
    Ptr_Action_InsertDID = Ptr_Menu_Did->addAction("Insert Did");
    Ptr_Action_DelDID = Ptr_Menu_Did->addAction("Delete Did");

    ui->TableView_Did->addAction(Ptr_Action_AddDID);
    ui->TableView_Did->addAction(Ptr_Action_InsertDID);
    ui->TableView_Did->addAction(Ptr_Action_DelDID);

    connect(Ptr_Action_AddDID, &QAction::triggered, this, &MainWindow::Slot_AddDID);
    connect(Ptr_Action_DelDID, &QAction::triggered, this, &MainWindow::Slot_DelDID);
    connect(Ptr_Action_InsertDID, &QAction::triggered, this, &MainWindow::Slot_InsertDID);

    ui->TableView_Did->setContextMenuPolicy(Qt::CustomContextMenu);//必须设置
    connect(ui->TableView_Did, &QTableView::customContextMenuRequested, this, &MainWindow::Slot_DidTable_customContextMenuRequested);
    connect(&StdModel_Did, &QStandardItemModel::itemChanged, this, &MainWindow::Slot_UpdateDidInfos);

    //增加RID Table右键菜单
    Ptr_Menu_Rid = new QMenu(ui->TableView_Did);
    Ptr_Action_AddRID = Ptr_Menu_Rid->addAction("Add Rid");
    Ptr_Action_InsertRID = Ptr_Menu_Rid->addAction("Insert Rid");
    Ptr_Action_DelRID = Ptr_Menu_Rid->addAction("Delete Rid");

    Ptr_TableView_Rid->addAction(Ptr_Action_AddRID);
    Ptr_TableView_Rid->addAction(Ptr_Action_InsertRID);
    Ptr_TableView_Rid->addAction(Ptr_Action_DelRID);

    connect(Ptr_Action_AddRID, &QAction::triggered, this, &MainWindow::Slot_AddRID);
    connect(Ptr_Action_DelRID, &QAction::triggered, this, &MainWindow::Slot_DelRID);
    connect(Ptr_Action_InsertRID, &QAction::triggered, this, &MainWindow::Slot_InsertRID);

    Ptr_TableView_Rid->setContextMenuPolicy(Qt::CustomContextMenu);//必须设置
    connect(Ptr_TableView_Rid, &QTableView::customContextMenuRequested, this, &MainWindow::Slot_RidTable_customContextMenuRequested);
    connect(&StdModel_Rid, &QStandardItemModel::itemChanged, this, &MainWindow::Slot_UpdateRidInfos);

    //增加DcmGeneral表的槽函数
    connect(&StdModel_DcmGeneral, &QStandardItemModel::itemChanged, this, &MainWindow::Slot_UpdateDcmGeneralInfos);

    //增加 OpCycle 右键菜单
    Ptr_Menu_OpCycle = new QMenu(Ptr_TableView_OpCycle);
    Ptr_Action_AddOpCycle = Ptr_Menu_OpCycle->addAction("Add OpCycle");
    Ptr_Action_InsertOpCycle = Ptr_Menu_OpCycle->addAction("Insert OpCycle");
    Ptr_Action_DelOpCycle = Ptr_Menu_OpCycle->addAction("Delete OpCycle");

    Ptr_TableView_OpCycle->addAction(Ptr_Action_AddOpCycle);
    Ptr_TableView_OpCycle->addAction(Ptr_Action_InsertOpCycle);
    Ptr_TableView_OpCycle->addAction(Ptr_Action_DelOpCycle);

    connect(Ptr_Action_AddOpCycle, &QAction::triggered, this, &MainWindow::Slot_AddOpCycle);
    connect(Ptr_Action_DelOpCycle, &QAction::triggered, this, &MainWindow::Slot_DelOpCycle);
    connect(Ptr_Action_InsertOpCycle, &QAction::triggered, this, &MainWindow::Slot_InsertOpCycle);

    Ptr_TableView_OpCycle->setContextMenuPolicy(Qt::CustomContextMenu);//必须设置
    connect(Ptr_TableView_OpCycle, &QTableView::customContextMenuRequested, this, &MainWindow::Slot_OpCycleTable_customContextMenuRequested);
    connect(&StdModel_OpCycle, &QStandardItemModel::itemChanged, this, &MainWindow::Slot_UpdateOpCycleInfos);

    //增加 Debounce 右键菜单
    Ptr_Menu_Debounce = new QMenu(Ptr_TableView_Debounce);
    Ptr_Action_AddDebounce = Ptr_Menu_Debounce->addAction("Add Debounce");
    Ptr_Action_InsertDebounce = Ptr_Menu_Debounce->addAction("Insert Debounce");
    Ptr_Action_DelDebounce = Ptr_Menu_Debounce->addAction("Delete Debounce");

    Ptr_TableView_Debounce->addAction(Ptr_Action_AddDebounce);
    Ptr_TableView_Debounce->addAction(Ptr_Action_InsertDebounce);
    Ptr_TableView_Debounce->addAction(Ptr_Action_DelDebounce);

    connect(Ptr_Action_AddDebounce, &QAction::triggered, this, &MainWindow::Slot_AddDebounce);
    connect(Ptr_Action_DelDebounce, &QAction::triggered, this, &MainWindow::Slot_DelDebounce);
    connect(Ptr_Action_InsertDebounce, &QAction::triggered, this, &MainWindow::Slot_InsertDebounce);

    Ptr_TableView_Debounce->setContextMenuPolicy(Qt::CustomContextMenu);//必须设置
    connect(Ptr_TableView_Debounce, &QTableView::customContextMenuRequested, this, &MainWindow::Slot_DebounceTable_customContextMenuRequested);
    connect(&StdModel_Debounce, &QStandardItemModel::itemChanged, this, &MainWindow::Slot_UpdateDebounceInfos);

    //设置代理
    Ptr_ComBoxDelegate_AlgoClass = new ComboBox_Delegate(Ptr_TableView_Debounce);
    Ptr_ComBoxDelegate_Behavior = new ComboBox_Delegate(Ptr_TableView_Debounce);

    Ptr_ComBoxDelegate_AlgoClass->setItems(StrList_AlgoClass);
    Ptr_ComBoxDelegate_Behavior->setItems(StrList_Behavior);

    //增加 DTC 右键菜单
    Ptr_Menu_DTC = new QMenu(Ptr_TableView_DTC);
    Ptr_Action_AddDTC = Ptr_Menu_DTC->addAction("Add DTC");
    Ptr_Action_InsertDTC = Ptr_Menu_DTC->addAction("Insert DTC");
    Ptr_Action_DelDTC = Ptr_Menu_DTC->addAction("Delete DTC");

    Ptr_TableView_DTC->addAction(Ptr_Action_AddDTC);
    Ptr_TableView_DTC->addAction(Ptr_Action_InsertDTC);
    Ptr_TableView_DTC->addAction(Ptr_Action_DelDTC);

    connect(Ptr_Action_AddDTC, &QAction::triggered, this, &MainWindow::Slot_AddDTC);
    connect(Ptr_Action_DelDTC, &QAction::triggered, this, &MainWindow::Slot_DelDTC);
    connect(Ptr_Action_InsertDTC, &QAction::triggered, this, &MainWindow::Slot_InsertDTC);

    Ptr_TableView_DTC->setContextMenuPolicy(Qt::CustomContextMenu);//必须设置
    connect(Ptr_TableView_DTC, &QTableView::customContextMenuRequested, this, &MainWindow::Slot_DTCTable_customContextMenuRequested);
    connect(&StdModel_DTC, &QStandardItemModel::itemChanged, this, &MainWindow::Slot_UpdateDTCInfos);

    //设置代理
    Ptr_ComBoxDelegate_EventKind = new ComboBox_Delegate(Ptr_TableView_DTC);
    Ptr_ComBoxDelegate_EventKind->setItems(StrList_EventKind);

    //增加 NVM 右键菜单
    Ptr_Menu_NVM = new QMenu(Ptr_TableView_NVM);
    Ptr_Action_AddNVM = Ptr_Menu_NVM->addAction("Add NVM Block");
    Ptr_Action_InsertNVM = Ptr_Menu_NVM->addAction("Insert NVM Block");
    Ptr_Action_DelNVM = Ptr_Menu_NVM->addAction("Delete NVM Block");

    Ptr_TableView_NVM->addAction(Ptr_Action_AddNVM);
    Ptr_TableView_NVM->addAction(Ptr_Action_InsertNVM);
    Ptr_TableView_NVM->addAction(Ptr_Action_DelNVM);

    connect(Ptr_Action_AddNVM, &QAction::triggered, this, &MainWindow::Slot_AddNVM);
    connect(Ptr_Action_DelNVM, &QAction::triggered, this, &MainWindow::Slot_DelNVM);
    connect(Ptr_Action_InsertNVM, &QAction::triggered, this, &MainWindow::Slot_InsertNVM);

    Ptr_TableView_NVM->setContextMenuPolicy(Qt::CustomContextMenu);//必须设置
    connect(Ptr_TableView_NVM, &QTableView::customContextMenuRequested, this, &MainWindow::Slot_NVMTable_customContextMenuRequested);
    connect(&StdModel_NVM, &QStandardItemModel::itemChanged, this, &MainWindow::Slot_UpdateNVMInfos);

    //设置代理
    Ptr_ComBoxDelegate_DeviceKind = new ComboBox_Delegate(Ptr_TableView_NVM);
    Ptr_ComBoxDelegate_DeviceKind->setItems(StrList_DeviceKind);

    //增加DcmGeneral表的槽函数
    connect(&StdModel_FEE, &QStandardItemModel::itemChanged, this, &MainWindow::Slot_UpdateFEEInfos);
    
}

void MainWindow::Slot_FileMenu_Triggered(QAction* action)
{
    qDebug() << "Clicked Menu " << action->text();

    if(action->text() == "Open Project")
    {
        PM_OpenProject();

        //设置TreeView
        ui->Tree_Config->setModel(&StdModle_TreeConfig);
        //设置展开
        ui->Tree_Config->expandAll();

        //使能Generate, Save, Save As, Close
        ui->But_Generate->setEnabled(true);
        List_Actions_Project.at(2)->setEnabled(true);
        List_Actions_Project.at(3)->setEnabled(true);
        List_Actions_Project.at(4)->setEnabled(true);
        //禁止New和Open
        List_Actions_Project.at(0)->setEnabled(false);
        List_Actions_Project.at(1)->setEnabled(false);
    }
    else if(action->text() == "Save Project")
    {
        PM_SaveConfigInfo();
    }
    else if(action->text() == "New Project")
    {
        PM_NewProject();
        //设置TreeView
        ui->Tree_Config->setModel(&StdModle_TreeConfig);
        //设置展开
        ui->Tree_Config->expandAll();

        //使能Generate
        ui->But_Generate->setEnabled(true);
    }
    else if(action->text() == "Save As")
    {
        //将工程文件名字清除，再执行保存
        Str_CurProject_Name.clear();
        PM_SaveConfigInfo();

        //使能Generate
        ui->But_Generate->setEnabled(true);
    }
    else if(action->text() == "Close Project")
    {
        //清除TreeView
//        ui->Tree_Config->close();
//        ui->TableView_Did->close();
//        Ptr_TableView_DcmGeneral->close();
//        Ptr_TableView_Rid->close();
//        Ptr_TableView_OpCycle->close();
//        Ptr_TableView_Debounce->close();
//        Ptr_TableView_DTC->close();
//        Ptr_TableView_NVM->close();
//        Ptr_TableView_FEE->close();

        List_DID_Infos_User.clear();
        List_DcmGeneral_Infos_User.clear();
        List_RID_Infos_User.clear();
        List_DTC_Infos_User.clear();
        List_Debounce_Infos_User.clear();
        List_OpCycle_Infos_User.clear();
        List_NVM_Infos_User.clear();
        List_FEE_Infos_User.clear();

        TableView_UpdateDid();
        TableView_UpdateRid();
        TableView_UpdateDcmGeneral();
        TableView_UpdateOpCycle();
        TableView_UpdateDebounce();
        TableView_UpdateDTC();
        TableView_UpdateNVM();
        TableView_UpdateFEE();

        //禁止Generate
        ui->But_Generate->setEnabled(false);
        List_Actions_Project.at(2)->setEnabled(false);
        List_Actions_Project.at(3)->setEnabled(false);
        List_Actions_Project.at(4)->setEnabled(false);
        //使能New和Open
        List_Actions_Project.at(0)->setEnabled(true);
        List_Actions_Project.at(1)->setEnabled(true);

        //取消显示工程名
        this->setWindowTitle(Str_ToolVersion);
    }
}

void MainWindow::Slot_OpenConfig(bool checked)
{
    PM_OpenProject();
}

void MainWindow::Slot_TreeView_Clicled(QModelIndex index)
{
    QString Str_ItemName = ui->Tree_Config->model()->itemData(index).values().at(0).toString();
    if(Str_ItemName == "DID Table")
    {
        ui->TableView_Did->show();
        Ptr_TableView_Rid->hide();
        Ptr_TableView_DcmGeneral->hide();
        Ptr_TableView_OpCycle->hide();
        Ptr_TableView_Debounce->hide();
        Ptr_TableView_DTC->hide();
        Ptr_TableView_FEE->hide();

        ResizeLayout(ui->TableView_Did);
        TableView_UpdateDid();
    }
    else if(Str_ItemName == "RID Table")
    {
        ui->TableView_Did->hide();
        Ptr_TableView_Rid->show();
        Ptr_TableView_DcmGeneral->hide();
        Ptr_TableView_OpCycle->hide();
        Ptr_TableView_Debounce->hide();
        Ptr_TableView_DTC->hide();
        Ptr_TableView_FEE->hide();

        ResizeLayout(Ptr_TableView_Rid);
        TableView_UpdateRid();
    }
    else if(Str_ItemName == "Dcm General Config")
    {
        ui->TableView_Did->hide();
        Ptr_TableView_Rid->hide();
        Ptr_TableView_DcmGeneral->show();
        Ptr_TableView_OpCycle->hide();
        Ptr_TableView_Debounce->hide();
        Ptr_TableView_DTC->hide();
        Ptr_TableView_NVM->hide();
        Ptr_TableView_FEE->hide();

        ResizeLayout(Ptr_TableView_DcmGeneral);
        TableView_UpdateDcmGeneral();
    }
    else if(Str_ItemName == "OpCycle Table")
    {
        ui->TableView_Did->hide();
        Ptr_TableView_Rid->hide();
        Ptr_TableView_DcmGeneral->hide();
        Ptr_TableView_OpCycle->show();
        Ptr_TableView_Debounce->hide();
        Ptr_TableView_DTC->hide();
        Ptr_TableView_NVM->hide();
        Ptr_TableView_FEE->hide();

        ResizeLayout(Ptr_TableView_OpCycle);
        TableView_UpdateOpCycle();
    }
    else if(Str_ItemName == "Debounce Table")
    {
        ui->TableView_Did->hide();
        Ptr_TableView_Rid->hide();
        Ptr_TableView_DcmGeneral->hide();
        Ptr_TableView_OpCycle->hide();
        Ptr_TableView_Debounce->show();
        Ptr_TableView_DTC->hide();
        Ptr_TableView_NVM->hide();
        Ptr_TableView_FEE->hide();

        ResizeLayout(Ptr_TableView_Debounce);
        TableView_UpdateDebounce();
    }
    else if(Str_ItemName == "DTC Config")
    {
        ui->TableView_Did->hide();
        Ptr_TableView_Rid->hide();
        Ptr_TableView_DcmGeneral->hide();
        Ptr_TableView_OpCycle->hide();
        Ptr_TableView_Debounce->hide();
        Ptr_TableView_DTC->show();
        Ptr_TableView_NVM->hide();
        Ptr_TableView_FEE->hide();

        ResizeLayout(Ptr_TableView_DTC);
        TableView_UpdateDTC();
    }
    else if(Str_ItemName == "NvM Block Config")
    {
        ui->TableView_Did->hide();
        Ptr_TableView_Rid->hide();
        Ptr_TableView_DcmGeneral->hide();
        Ptr_TableView_OpCycle->hide();
        Ptr_TableView_Debounce->hide();
        Ptr_TableView_DTC->hide();
        Ptr_TableView_FEE->hide();
        Ptr_TableView_NVM->show();

        ResizeLayout(Ptr_TableView_NVM);
        TableView_UpdateNVM();
    }
    else if(Str_ItemName == "FEE Config")
    {
        ui->TableView_Did->hide();
        Ptr_TableView_Rid->hide();
        Ptr_TableView_DcmGeneral->hide();
        Ptr_TableView_OpCycle->hide();
        Ptr_TableView_Debounce->hide();
        Ptr_TableView_DTC->hide();
        Ptr_TableView_NVM->hide();
        Ptr_TableView_FEE->show();

        ResizeLayout(Ptr_TableView_FEE);
        TableView_UpdateFEE();
    }
    else
    {
        /* ToBeDefine */
    }
}

//如果TableView为空时，右键任何位置都可以弹出菜单
//如果TableView不为空时，则只有在TabView有效index下才能弹出菜单,
void MainWindow::Slot_DidTable_customContextMenuRequested(const QPoint &pos)
{
    bool Enable_Menu = false;
    QModelIndex index = ui->TableView_Did->indexAt(pos);
    qDebug() << "index at : " << index;
    sint8 row = index.row();
    if(row == (-1))
    {
        if(List_Did.isEmpty())
        {
            Enable_Menu = true;
        }
        else
        {
            Enable_Menu = false;
        }
    }
    else
    {
        Enable_Menu = true;
        Index_CurSelect = index;
    }

    if(Enable_Menu == true)
    {
        //弹出Did右键菜单
        Ptr_Menu_Did->exec(QCursor::pos());
    }
}

void MainWindow::Slot_RidTable_customContextMenuRequested(const QPoint &pos)
{
    bool Enable_Menu = false;
    QModelIndex index = Ptr_TableView_Rid->indexAt(pos);
    qDebug() << "index at : " << index;
    sint8 row = index.row();
    if(row == (-1))
    {
        if(List_Rid.isEmpty())
        {
            Enable_Menu = true;
        }
        else
        {
            Enable_Menu = false;
        }
    }
    else
    {
        Enable_Menu = true;
        Index_CurSelect = index;
    }

    if(Enable_Menu == true)
    {
        //弹出Did右键菜单
        Ptr_Menu_Rid->exec(QCursor::pos());
    }
}

void MainWindow::Slot_OpCycleTable_customContextMenuRequested(const QPoint &pos)
{
    bool Enable_Menu = false;
    QModelIndex index = Ptr_TableView_OpCycle->indexAt(pos);
    qDebug() << "index at : " << index;
    sint8 row = index.row();
    if(row == (-1))
    {
        if(List_OpCycle_Infos_User.isEmpty())
        {
            Enable_Menu = true;
        }
        else
        {
            Enable_Menu = false;
        }
    }
    else
    {
        Enable_Menu = true;
        Index_CurSelect = index;
    }

    if(Enable_Menu == true)
    {
        //弹出Did右键菜单
        Ptr_Menu_OpCycle->exec(QCursor::pos());
    }
}

void MainWindow::Slot_DebounceTable_customContextMenuRequested(const QPoint &pos)
{
    bool Enable_Menu = false;
    QModelIndex index = Ptr_TableView_Debounce->indexAt(pos);
    qDebug() << "index at : " << index;
    sint8 row = index.row();
    if(row == (-1))
    {
        if(List_Debounce_Infos_User.isEmpty())
        {
            Enable_Menu = true;
        }
        else
        {
            Enable_Menu = false;
        }
    }
    else
    {
        Enable_Menu = true;
        Index_CurSelect = index;
    }

    if(Enable_Menu == true)
    {
        //弹出Did右键菜单
        Ptr_Menu_Debounce->exec(QCursor::pos());
    }
}

void MainWindow::Slot_DTCTable_customContextMenuRequested(const QPoint &pos)
{
    bool Enable_Menu = false;
    QModelIndex index = Ptr_TableView_DTC->indexAt(pos);
    qDebug() << "index at : " << index;
    sint8 row = index.row();
    if(row == (-1))
    {
        if(List_DTC_Infos_User.isEmpty())
        {
            Enable_Menu = true;
        }
        else
        {
            Enable_Menu = false;
        }
    }
    else
    {
        Enable_Menu = true;
        Index_CurSelect = index;
    }

    if(Enable_Menu == true)
    {
        //弹出Did右键菜单
        Ptr_Menu_DTC->exec(QCursor::pos());
    }
}

void MainWindow::Slot_NVMTable_customContextMenuRequested(const QPoint &pos)
{
    bool Enable_Menu = false;
    QModelIndex index = Ptr_TableView_NVM->indexAt(pos);
    qDebug() << " NvM CustomContextMenu, index at : " << index;
    sint8 row = index.row();
    if(row == (-1))
    {
        if(List_NVM_Infos_User.isEmpty())
        {
            Enable_Menu = true;
        }
        else
        {
            Enable_Menu = false;
        }
    }
    else
    {
        Enable_Menu = true;
        Index_CurSelect = index;
    }

    if(Enable_Menu == true)
    {
        //弹出Did右键菜单
        Ptr_Menu_NVM->exec(QCursor::pos());
    }
}

void MainWindow::Slot_AddDID(bool checked)
{
    qDebug("Add Did");
    //New 1个新的配置，加入到List中
    S_DID_Infos_User_Type* Ptr_Infos_Add = new S_DID_Infos_User_Type;
    Ptr_Infos_Add->Did = 0;
    Ptr_Infos_Add->DataLen = 0;
    Ptr_Infos_Add->Operation = DID_NONE;
    Ptr_Infos_Add->IsOnlyEol = 0;
    List_DID_Infos_User.append(Ptr_Infos_Add);

    // 避免执行TableView_UpdateDid操作后，触发多次TableView_xxxx的ItemChanged
    // 从而执行多次槽函数TableView_UpdateDid
    l_DidTable_UpdateReason = TABLE_UPDATE_BY_USER;
    l_DidTableUpdate_Finished = false;
    TableView_UpdateDid();
    l_DidTableUpdate_Finished = true;
    l_DidTable_UpdateReason = TABLE_UPDATE_BY_OTHER;

}

void MainWindow::Slot_DelDID(bool checked)
{
    qDebug("Del Did");
    QModelIndex CurIndex = Index_CurSelect;
    List_DID_Infos_User.removeAt(CurIndex.row());

   l_DidTable_UpdateReason = TABLE_UPDATE_BY_USER;
   l_DidTableUpdate_Finished = false;
   TableView_UpdateDid();
   l_DidTable_UpdateReason = TABLE_UPDATE_BY_OTHER;
   l_DidTableUpdate_Finished = true;
}

void MainWindow::Slot_InsertDID(bool checked)
{
     qDebug("Insert Did");
     QModelIndex CurIndex = Index_CurSelect;
     uint8 Index = CurIndex.row();

    //New 1个新的配置，加入到List中
    S_DID_Infos_User_Type* Ptr_Infos_Add = new S_DID_Infos_User_Type;
    Ptr_Infos_Add->Did = 0;
    Ptr_Infos_Add->DataLen = 0;
    Ptr_Infos_Add->Operation = DID_NONE;
    List_DID_Infos_User.insert(Index, Ptr_Infos_Add);

    // 避免执行TableView_UpdateDid操作后，触发多次TableView_xxxx的ItemChanged
    // 从而执行多次槽函数TableView_UpdateDid
    l_DidTable_UpdateReason = TABLE_UPDATE_BY_USER;
    l_DidTableUpdate_Finished = false;
    TableView_UpdateDid();
    l_DidTableUpdate_Finished = true;
    l_DidTable_UpdateReason = TABLE_UPDATE_BY_OTHER;
}

void MainWindow::Slot_AddRID(bool checked)
{
    qDebug("Add Rid");
    //New 1个新的配置，加入到List中
    S_RID_Infos_User_Type* Ptr_Infos_Add = new S_RID_Infos_User_Type;
    Ptr_Infos_Add->Rid = 0;
    Ptr_Infos_Add->Operation = 0xF;
    Ptr_Infos_Add->RoutineType = 0x06;
    Ptr_Infos_Add->RoutineControlOptionRecord = 0;
    List_RID_Infos_User.append(Ptr_Infos_Add);

    l_RidTable_UpdateReason = TABLE_UPDATE_BY_USER;
    l_RidTableUpdate_Finished = false;
    TableView_UpdateRid();
    l_RidTable_UpdateReason = TABLE_UPDATE_BY_OTHER;
    l_RidTableUpdate_Finished = false;
}

void MainWindow::Slot_DelRID(bool checked)
{
    qDebug("Del Rid");
    QModelIndex CurIndex = Index_CurSelect;
    List_RID_Infos_User.removeAt(CurIndex.row());

    l_RidTable_UpdateReason = TABLE_UPDATE_BY_USER;
    l_RidTableUpdate_Finished = false;
    TableView_UpdateRid();
    l_RidTable_UpdateReason = TABLE_UPDATE_BY_OTHER;
    l_RidTableUpdate_Finished = false;
}

void MainWindow::Slot_InsertRID(bool checked)
{
    qDebug("Insert Rid");
    QModelIndex CurIndex = Index_CurSelect;
    uint8 Index = CurIndex.row();

    //New 1个新的配置，加入到List中
    S_RID_Infos_User_Type* Ptr_Infos_Add = new S_RID_Infos_User_Type;
    Ptr_Infos_Add->Rid = 0;
    Ptr_Infos_Add->Operation = 0xF;
    Ptr_Infos_Add->RoutineType = 0x06;
    Ptr_Infos_Add->RoutineControlOptionRecord = 0;
    List_RID_Infos_User.insert(Index, Ptr_Infos_Add);

    l_RidTable_UpdateReason = TABLE_UPDATE_BY_USER;
    l_RidTableUpdate_Finished = false;
    TableView_UpdateRid();
    l_RidTable_UpdateReason = TABLE_UPDATE_BY_OTHER;
    l_RidTableUpdate_Finished = false;
}

void MainWindow::Slot_AddOpCycle(bool checked)
{
    qDebug("Add OpCycle");
    //New 1个新的配置，加入到List中
    S_OpCycle_Infos_User_Type* Ptr_Infos_Add = new S_OpCycle_Infos_User_Type;
    Ptr_Infos_Add->Id = List_OpCycle_Infos_User.count();
    Ptr_Infos_Add->Type = 0;
    Ptr_Infos_Add->AutoStart = 0;
    Ptr_Infos_Add->AutoStop = 0;
    List_OpCycle_Infos_User.append(Ptr_Infos_Add);

    l_OpCycleTable_UpdateReason = TABLE_UPDATE_BY_USER;
    l_OpCycleTableUpdate_Finished = false;
    TableView_UpdateOpCycle();
    l_OpCycleTable_UpdateReason = TABLE_UPDATE_BY_OTHER;
    l_OpCycleTableUpdate_Finished = false;
}

void MainWindow::Slot_DelOpCycle(bool checked)
{
    qDebug("Del OpCycle");
    QModelIndex CurIndex = Index_CurSelect;
    List_OpCycle_Infos_User.removeAt(CurIndex.row());

    l_OpCycleTable_UpdateReason = TABLE_UPDATE_BY_USER;
    l_OpCycleTableUpdate_Finished = false;
    TableView_UpdateOpCycle();
    l_OpCycleTable_UpdateReason = TABLE_UPDATE_BY_OTHER;
    l_OpCycleTableUpdate_Finished = false;
}

void MainWindow::Slot_InsertOpCycle(bool checked)
{
    qDebug("Insert OpCycle");
    QModelIndex CurIndex = Index_CurSelect;
    uint8 Index = CurIndex.row();

    //New 1个新的配置，加入到List中
    S_OpCycle_Infos_User_Type* Ptr_Infos_Add = new S_OpCycle_Infos_User_Type;
    Ptr_Infos_Add->Id = List_OpCycle_Infos_User.count();
    Ptr_Infos_Add->Type = 0;
    Ptr_Infos_Add->AutoStart = 0;
    Ptr_Infos_Add->AutoStop = 0;
    List_OpCycle_Infos_User.insert(Index, Ptr_Infos_Add);

    l_OpCycleTable_UpdateReason = TABLE_UPDATE_BY_USER;
    l_OpCycleTableUpdate_Finished = false;
    TableView_UpdateOpCycle();
    l_OpCycleTable_UpdateReason = TABLE_UPDATE_BY_OTHER;
    l_OpCycleTableUpdate_Finished = false;
}

void MainWindow::Slot_AddDebounce(bool checked)
{
    qDebug("Add Debounce");
    //New 1个新的配置，加入到List中
    S_Debounce_Infos_User_Type* Ptr_Infos_Add = new S_Debounce_Infos_User_Type;
    Ptr_Infos_Add->FailedThershold = 0;
    Ptr_Infos_Add->PassedThershold = 0;
    Ptr_Infos_Add->FailedTimeThershold = 0;
    Ptr_Infos_Add->PassedTimeThershold = 0;
    Ptr_Infos_Add->DecStepSize = -1;
    Ptr_Infos_Add->IncStepSize = 1;
    Ptr_Infos_Add->JumpUpValue = 0;
    Ptr_Infos_Add->JumpDownValue = 0;
    Ptr_Infos_Add->AlgoClass = 0;
    Ptr_Infos_Add->JumpUp = false;
    Ptr_Infos_Add->JumpDown = false;
    Ptr_Infos_Add->behavior = 0;
    List_Debounce_Infos_User.append(Ptr_Infos_Add);

    l_DebounceTable_UpdateReason = TABLE_UPDATE_BY_USER;
    l_DebounceTableUpdate_Finished = false;
    TableView_UpdateDebounce();
    l_DebounceTable_UpdateReason = TABLE_UPDATE_BY_OTHER;
    l_DebounceTableUpdate_Finished = false;
}

void MainWindow::Slot_DelDebounce(bool checked)
{
    qDebug("Del Debounce");
    QModelIndex CurIndex = Index_CurSelect;
    List_Debounce_Infos_User.removeAt(CurIndex.row());

    l_DebounceTable_UpdateReason = TABLE_UPDATE_BY_USER;
    l_DebounceTableUpdate_Finished = false;
    TableView_UpdateDebounce();
    l_DebounceTable_UpdateReason = TABLE_UPDATE_BY_OTHER;
    l_DebounceTableUpdate_Finished = false;
}

void MainWindow::Slot_InsertDebounce(bool checked)
{
    qDebug("Insert Debounce");
    QModelIndex CurIndex = Index_CurSelect;
    uint8 Index = CurIndex.row();

    //New 1个新的配置，加入到List中
    S_Debounce_Infos_User_Type* Ptr_Infos_Add = new S_Debounce_Infos_User_Type;
    Ptr_Infos_Add->FailedThershold = 0;
    Ptr_Infos_Add->PassedThershold = 0;
    Ptr_Infos_Add->FailedTimeThershold = 0;
    Ptr_Infos_Add->PassedTimeThershold = 0;
    Ptr_Infos_Add->DecStepSize = -1;
    Ptr_Infos_Add->IncStepSize = 1;
    Ptr_Infos_Add->JumpUpValue = 0;
    Ptr_Infos_Add->JumpDownValue = 0;
    Ptr_Infos_Add->AlgoClass = 0;
    Ptr_Infos_Add->JumpUp = false;
    Ptr_Infos_Add->JumpDown = false;
    Ptr_Infos_Add->behavior = 0;
    List_Debounce_Infos_User.insert(Index, Ptr_Infos_Add);

    l_DebounceTable_UpdateReason = TABLE_UPDATE_BY_USER;
    l_DebounceTableUpdate_Finished = false;
    TableView_UpdateDebounce();
    l_DebounceTable_UpdateReason = TABLE_UPDATE_BY_OTHER;
    l_DebounceTableUpdate_Finished = false;
}

void MainWindow::Slot_AddDTC(bool checked)
{
    qDebug("Add DTC");
    //New 1个新的配置，加入到List中
    S_DTC_Infos_User_Type* Ptr_Infos_Add = new S_DTC_Infos_User_Type;
    Ptr_Infos_Add->Value = 0;
    Ptr_Infos_Add->AttrbsRef = List_DTC_Infos_User.count();

    Ptr_Infos_Add->AgingThershold = 40;
    Ptr_Infos_Add->AgingOpCycleRef = 3;
    Ptr_Infos_Add->ImmediateNvStorageAllowed = true;
    Ptr_Infos_Add->AgingAllowed = true;

    Ptr_Infos_Add->DemCallbackInitMForE = "Null_Ptr";
    Ptr_Infos_Add->Id = List_DTC_Infos_User.count();
    Ptr_Infos_Add->EventKind = 0;
    Ptr_Infos_Add->FailureCycleCounterThershold = 255;
    Ptr_Infos_Add->DebounceTableRef = 1;    /* Counter Base */
    Ptr_Infos_Add->OpCycleRef = 3;
    Ptr_Infos_Add->DTCTableRef = List_DTC_Infos_User.count();
    Ptr_Infos_Add->EnableConditionRef = 0;
    Ptr_Infos_Add->StorageConditionRef = 0;
    Ptr_Infos_Add->AvailableStatus = 1;
    List_DTC_Infos_User.append(Ptr_Infos_Add);

    l_DTCTable_UpdateReason = TABLE_UPDATE_BY_USER;
    l_DTCTableUpdate_Finished = false;
    TableView_UpdateDTC();
    l_DTCTable_UpdateReason = TABLE_UPDATE_BY_OTHER;
    l_DTCTableUpdate_Finished = false;
}

void MainWindow::Slot_DelDTC(bool checked)
{
    qDebug("Del DTC");
    QModelIndex CurIndex = Index_CurSelect;
    List_DTC_Infos_User.removeAt(CurIndex.row());

    l_DTCTable_UpdateReason = TABLE_UPDATE_BY_USER;
    l_DTCTableUpdate_Finished = false;
    TableView_UpdateDTC();
    l_DTCTable_UpdateReason = TABLE_UPDATE_BY_OTHER;
    l_DTCTableUpdate_Finished = false;
}

void MainWindow::Slot_InsertDTC(bool checked)
{
    qDebug("Insert DTC");
    QModelIndex CurIndex = Index_CurSelect;
    uint8 Index = CurIndex.row();

    //New 1个新的配置，加入到List中
    S_DTC_Infos_User_Type* Ptr_Infos_Add = new S_DTC_Infos_User_Type;
    Ptr_Infos_Add->Value = 0;
    Ptr_Infos_Add->AttrbsRef = Index;

    Ptr_Infos_Add->AgingThershold = 40;
    Ptr_Infos_Add->AgingOpCycleRef = 3;
    Ptr_Infos_Add->ImmediateNvStorageAllowed = true;
    Ptr_Infos_Add->AgingAllowed = true;

    Ptr_Infos_Add->DemCallbackInitMForE = "Null_Ptr";
    Ptr_Infos_Add->Id = Index;
    Ptr_Infos_Add->EventKind = 0;
    Ptr_Infos_Add->FailureCycleCounterThershold = 255;
    Ptr_Infos_Add->DebounceTableRef = 1;    /* Counter Base */
    Ptr_Infos_Add->OpCycleRef = 3;
    Ptr_Infos_Add->DTCTableRef = Index;
    Ptr_Infos_Add->EnableConditionRef = 0;
    Ptr_Infos_Add->StorageConditionRef = 0;
    Ptr_Infos_Add->AvailableStatus = 1;
    List_DTC_Infos_User.insert(Index, Ptr_Infos_Add);

    l_DTCTable_UpdateReason = TABLE_UPDATE_BY_USER;
    l_DTCTableUpdate_Finished = false;
    TableView_UpdateDTC();
    l_DTCTable_UpdateReason = TABLE_UPDATE_BY_OTHER;
    l_DTCTableUpdate_Finished = false;
}

void MainWindow::Slot_AddNVM(bool checked)
{
    qDebug("Add NVM");
    //New 1个新的配置，加入到List中
    S_NVM_Infos_User_Type* Ptr_Infos_Add = new S_NVM_Infos_User_Type;
    Ptr_Infos_Add->Str_InitFun = "NULL";
    Ptr_Infos_Add->Str_BlockName = "NvMConf_NvMBlockDescriptor_";
    Ptr_Infos_Add->Str_JobFinishedFunction = "Rte_Call_xxxx_JobFinished";
    Ptr_Infos_Add->Str_RamBlockDataAddress = "NvmRamData_";
    Ptr_Infos_Add->Str_RomBlockDataAddress = "NvmRomData_";
    Ptr_Infos_Add->Str_RomBlockDefaultData = "0";
    Ptr_Infos_Add->BlockJobPriority = 1;
    Ptr_Infos_Add->MaxNumReadRetries = 0;
    Ptr_Infos_Add->MaxNumWriteRetries = 0;
    Ptr_Infos_Add->NvBlockNum = 0;
    Ptr_Infos_Add->NvRamDeviceId = 0;
    Ptr_Infos_Add->RomBlockNum = 0;
    Ptr_Infos_Add->BlockCrcType = 2;
    Ptr_Infos_Add->BlockManagementType = 0;
    Ptr_Infos_Add->NvBlockBaseNumber = 0;
    Ptr_Infos_Add->Str_NvBlockLength = "0";
    Ptr_Infos_Add->NvRamBlockIdentifier = 0;
    Ptr_Infos_Add->BlockUseCrc = 0;
    Ptr_Infos_Add->BlockUseSetRamBlockStatus = 0;
    Ptr_Infos_Add->BlockWriteProt = 0;
    Ptr_Infos_Add->BswMBlockStatusInformation = 0;
    Ptr_Infos_Add->CalcRamBlockCrc = 0;
    Ptr_Infos_Add->SelectBlockForReadAll = 1;
    Ptr_Infos_Add->SelectBlockForWriteAll = 1;
    Ptr_Infos_Add->WriteBlockOnce = 0;

    List_NVM_Infos_User.append(Ptr_Infos_Add);

    l_NVMTable_UpdateReason = TABLE_UPDATE_BY_USER;
    l_NVMTableUpdate_Finished = false;
    TableView_UpdateNVM();
    l_NVMTable_UpdateReason = TABLE_UPDATE_BY_OTHER;
    l_NVMTableUpdate_Finished = false;
}

void MainWindow::Slot_DelNVM(bool checked)
{
    qDebug("Del NVM");
    QModelIndex CurIndex = Index_CurSelect;
    List_NVM_Infos_User.removeAt(CurIndex.row());

    l_NVMTable_UpdateReason = TABLE_UPDATE_BY_USER;
    l_NVMTableUpdate_Finished = false;
    TableView_UpdateNVM();
    l_NVMTable_UpdateReason = TABLE_UPDATE_BY_OTHER;
    l_NVMTableUpdate_Finished = false;
}

void MainWindow::Slot_InsertNVM(bool checked)
{
    qDebug("Add NVM");
    QModelIndex CurIndex = Index_CurSelect;
    uint8 Index = CurIndex.row();

    //New 1个新的配置，加入到List中
    S_NVM_Infos_User_Type* Ptr_Infos_Add = new S_NVM_Infos_User_Type;
    Ptr_Infos_Add->Str_InitFun = "NULL";
    Ptr_Infos_Add->Str_BlockName = "";
    Ptr_Infos_Add->Str_JobFinishedFunction = "Rte_Call_xxxx_JobFinished";
    Ptr_Infos_Add->Str_RamBlockDataAddress = "NvmRamData_";
    Ptr_Infos_Add->Str_RomBlockDataAddress = "NvmRomData_";
    Ptr_Infos_Add->Str_RomBlockDefaultData = "0";
    Ptr_Infos_Add->BlockJobPriority = 1;
    Ptr_Infos_Add->MaxNumReadRetries = 0;
    Ptr_Infos_Add->MaxNumWriteRetries = 0;
    Ptr_Infos_Add->NvBlockNum = 0;
    Ptr_Infos_Add->NvRamDeviceId = 0;
    Ptr_Infos_Add->RomBlockNum = 0;
    Ptr_Infos_Add->BlockCrcType = 2;
    Ptr_Infos_Add->BlockManagementType = 0;
    Ptr_Infos_Add->NvBlockBaseNumber = Index;
    Ptr_Infos_Add->Str_NvBlockLength = "0";
    Ptr_Infos_Add->NvRamBlockIdentifier = 0;
    Ptr_Infos_Add->BlockUseCrc = 0;
    Ptr_Infos_Add->BlockUseSetRamBlockStatus = 0;
    Ptr_Infos_Add->BlockWriteProt = 0;
    Ptr_Infos_Add->BswMBlockStatusInformation = 0;
    Ptr_Infos_Add->CalcRamBlockCrc = 0;
    Ptr_Infos_Add->SelectBlockForReadAll = 1;
    Ptr_Infos_Add->SelectBlockForWriteAll = 1;
    Ptr_Infos_Add->WriteBlockOnce = 0;

    List_NVM_Infos_User.insert(Index, Ptr_Infos_Add);

    l_NVMTable_UpdateReason = TABLE_UPDATE_BY_USER;
    l_NVMTableUpdate_Finished = false;
    TableView_UpdateNVM();
    l_NVMTable_UpdateReason = TABLE_UPDATE_BY_OTHER;
    l_NVMTableUpdate_Finished = false;
}

//根据List_XXXX_Infos_User 更新DcmGeneral TableView显示
void MainWindow::TableView_UpdateDcmGeneral(void)
{

    qDebug() << "Update Dcm General";
    uint8 row = 0;
    uint8 col = 0;
    QList<QStandardItem*> List_Row_Item;    //每一行的数据
    QStringList Strlist_Header;
    QStandardItem* Ptr_Item;
    //QStandardItem* Model_Header[4];
    //QList<QStandardItem*> List_StdItem_Temp;

    //Print_Info_User();
    //设置表行数和列数
    StdModel_DcmGeneral.clear();
    StdModel_DcmGeneral.setColumnCount(2);
    row = List_DcmGeneral_Infos_User.count();
    col = 2;

    //设置表头
    Strlist_Header << "Item" << "Value";
    for(int i = 0; i < Strlist_Header.size(); i++)
    {
        Ptr_Item = new QStandardItem(Strlist_Header.at(i));
        Ptr_Item->setTextAlignment(Qt::AlignCenter);
        StdModel_DcmGeneral.setHorizontalHeaderItem(i,Ptr_Item);
    }

    //设置DID表的信息
    for(int i = 0; i < row; i++)
    {
        QStandardItem* Ptr_Item_Temp[2];

        List_Row_Item.clear();
        Ptr_Item_Temp[0] = new QStandardItem(List_DcmGeneral_Infos_User.at(i)->Item);
        Ptr_Item_Temp[1] = new QStandardItem(List_DcmGeneral_Infos_User.at(i)->Value);

        //设置文字对齐
        Ptr_Item_Temp[0]->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
        Ptr_Item_Temp[1]->setTextAlignment(Qt::AlignCenter);

        //设置不可编辑
        Ptr_Item_Temp[0]->setEditable(false);

        List_Row_Item.append(Ptr_Item_Temp[0]);
        List_Row_Item.append(Ptr_Item_Temp[1]);

        StdModel_DcmGeneral.insertRow(i, List_Row_Item);
    }
    Ptr_TableView_DcmGeneral->setModel(&StdModel_DcmGeneral);
    Ptr_TableView_DcmGeneral->setColumnWidth(0, 200);
}

//根据List_XXXX_Infos_User 更新Did TableView显示
void MainWindow::TableView_UpdateDid(void)
{
    qDebug() << "Update TableView";
    uint8 row = 0;
    uint8 col = 0;
    QList<QStandardItem*> List_Row_Item;    //每一行的数据
    QStringList Strlist_Header;
    QStringList Strlist_HeaderTip;
    QStandardItem* Ptr_Item;
    QModelIndex index;
    CheckBoxDelegate* Ptr_CheckBoxDelegate[4];
    
    //清除数据
    StdModel_Did.clear();

    //设置表头和ToolTip,同时指定Model的列数
    Strlist_Header << "DID" << "READ" << "WRITE" << "DataLen(Byte)" << "IOCTRL" << "IsOnlyEOL";
    Strlist_HeaderTip << "DID" << QString::fromLocal8Bit("配置是否支持Read功能") \
                      << QString::fromLocal8Bit("配置是否支持Write功能") \
                      << QString::fromLocal8Bit("如果配置READ或WRITE 则数据长度应该指定")\
                      << QString::fromLocal8Bit("配置是否支持IOCTRL")\
                      << QString::fromLocal8Bit("配置是否为工厂诊断下的DID");


    for(int i = 0; i < Strlist_Header.size(); i++)
    {
        Ptr_Item = new QStandardItem(Strlist_Header.at(i));
        Ptr_Item->setTextAlignment(Qt::AlignCenter);
        Ptr_Item->setToolTip(Strlist_HeaderTip.at(i));
        StdModel_Did.setHorizontalHeaderItem(i,Ptr_Item);
    }

    //设置表行数和列数
    row = List_DID_Infos_User.count();
    col = StdModel_Did.columnCount();
    StdModel_Did.setColumnCount(col);

    //设置代理
    Ptr_CheckBoxDelegate[0] = new CheckBoxDelegate(ui->TableView_Did);
    Ptr_CheckBoxDelegate[1] = new CheckBoxDelegate(ui->TableView_Did);
    Ptr_CheckBoxDelegate[2] = new CheckBoxDelegate(ui->TableView_Did);
    Ptr_CheckBoxDelegate[3] = new CheckBoxDelegate(ui->TableView_Did);

    Ptr_CheckBoxDelegate[0]->setColumn(1);
    Ptr_CheckBoxDelegate[1]->setColumn(2);
    Ptr_CheckBoxDelegate[2]->setColumn(4);
    Ptr_CheckBoxDelegate[3]->setColumn(5);

    ui->TableView_Did->setItemDelegateForColumn(1,Ptr_CheckBoxDelegate[0]);
    ui->TableView_Did->setItemDelegateForColumn(2,Ptr_CheckBoxDelegate[1]);
    ui->TableView_Did->setItemDelegateForColumn(4,Ptr_CheckBoxDelegate[2]);
    ui->TableView_Did->setItemDelegateForColumn(5,Ptr_CheckBoxDelegate[3]);

    //设置DID表的信息, new出Model需要的Item
    for(int i = 0; i < row; i++)
    {
        
        // qDebug() << "i,j: " << List_DID_Infos_User.at(i)->Did\
        //             << List_DID_Infos_User.at(i)->Operation\
        //             << List_DID_Infos_User.at(i)->IsOnlyEol;
                    
        List_Row_Item.clear();
        for(int j = 0; j < col; j++)
        {

            Ptr_Item = new QStandardItem();
            //设置文字居中对齐
            Ptr_Item->setTextAlignment(Qt::AlignCenter);
            switch(j)
            {
                case (0):
                {
                    Ptr_Item->setText(QString::number(List_DID_Infos_User.at(i)->Did, 16).toUpper());
                }
                break;
                case (1):
                {
                    if((List_DID_Infos_User.at(i)->Operation & DID_READ) != 0)
                    {
                        Ptr_Item->setData(Qt::Checked, Qt::DisplayRole);
                    }
                    else
                    {
                        Ptr_Item->setData(Qt::Unchecked, Qt::DisplayRole);
                    }
                }
                break;
                case (2):
                {
                    if((List_DID_Infos_User.at(i)->Operation & DID_WRITE) != 0)
                    {
                        Ptr_Item->setData(Qt::Checked, Qt::DisplayRole);
                        //qDebug() << "Write Checked";
                    }
                    else
                    {
                        Ptr_Item->setData(Qt::Unchecked, Qt::DisplayRole);
                    }
                }
                break;
                case (3):
                {
                    Ptr_Item->setText(QString::number(List_DID_Infos_User.at(i)->DataLen, 10));
                }
                break;
                case (4):
                {
                    if((List_DID_Infos_User.at(i)->Operation & DID_IOCTRL) != 0)
                    {
                        Ptr_Item->setData(Qt::Checked, Qt::DisplayRole);
                    }
                    else
                    {
                        Ptr_Item->setData(Qt::Unchecked, Qt::DisplayRole);
                    }
                }
                break;
                case (5):
                {
                    if(List_DID_Infos_User.at(i)->IsOnlyEol != 0)
                    {
                        Ptr_Item->setData(Qt::Checked, Qt::DisplayRole);
                    }
                    else
                    {
                        Ptr_Item->setData(Qt::Unchecked, Qt::DisplayRole);
                    }
                }
                break;
                default:
                    break;
            }
            List_Row_Item.append(Ptr_Item);
            //qDebug() << "Row Data: " << Ptr_Item;
        }
        StdModel_Did.insertRow(i, List_Row_Item);
    }
    ui->TableView_Did->setModel(&StdModel_Did);
}

//根据List_XXXX_Infos_User 更新Rid TableView显示
void MainWindow::TableView_UpdateRid(void)
{
    QStringList Strlist_Header;
    QStringList Strlist_HeaderTip;
    QStandardItem* Ptr_Item;
    QList<QStandardItem*> List_Row_Item;    //每一行的数据
    QString Str_Rid;
    uint8 row = 0;
    uint8 col = 0;

    //设置表行数和列数
    StdModel_Rid.clear();
    StdModel_Rid.setColumnCount(4);
    row = List_RID_Infos_User.count();
    col = 4;

    //设置表头和ToolTip
    Strlist_Header << "RID" << "Operation" << "RCORL" << "RoutineType";
    Strlist_HeaderTip << "RID" << QString::fromLocal8Bit("配置Rid支持的操作") \
                      << QString::fromLocal8Bit("配置RoutineControlOptionRecord Length") \
                      << QString::fromLocal8Bit("配置Routine 类型");

    for(int i = 0; i < Strlist_Header.size(); i++)
    {
        Ptr_Item = new QStandardItem(Strlist_Header.at(i));
        Ptr_Item->setTextAlignment(Qt::AlignCenter);
        Ptr_Item->setToolTip(Strlist_HeaderTip.at(i));
        StdModel_Rid.setHorizontalHeaderItem(i,Ptr_Item);
    }

    //设置RID表的信息
    for(int i = 0; i < row; i++)
    {
        List_Row_Item.clear();
        for(int j = 0; j < col; j++)
        {
            Ptr_Item = new QStandardItem();
            //设置文字居中对齐
            Ptr_Item->setTextAlignment(Qt::AlignCenter);
            switch(j)
            {
                case (0):
                {
                    Str_Rid = QString::number(List_RID_Infos_User.at(i)->Rid, 16).toUpper();
                    Ptr_Item->setText(QString("%1").arg(Str_Rid, 4, QChar('0')));
                }
                break;
                case (1):
                {
                    Ptr_Item->setText("START | STOP | RESULT");
                    //设置不可编辑
                    Ptr_Item->setEditable(false);
                }
                break;
                case (2):
                {
                    Ptr_Item->setText(QString::number(List_RID_Infos_User.at(i)->RoutineControlOptionRecord, 10));
                }
                break;
                case (3):
                {
                    Ptr_Item->setText("ROUTINE_TYPE_2 | RC_STOP_SERVICE");
                    //设置不可编辑
                    Ptr_Item->setEditable(false);
                }
                break;
                default:
                    break;

            }
            List_Row_Item.append(Ptr_Item);
        }
        StdModel_Rid.insertRow(i, List_Row_Item);
    }

    Ptr_TableView_Rid->setModel(&StdModel_Rid);
    //第2和3列加宽
    Ptr_TableView_Rid->setColumnWidth(1, 200);
    Ptr_TableView_Rid->setColumnWidth(3, 300);
}

//根据List_XXXX_Infos_User 更新OpCycle TableView显示
void MainWindow::TableView_UpdateOpCycle(void)
{
    qDebug() << "Update OpCycle";
    uint8 row = 0;
    uint8 col = 0;
    QList<QStandardItem*> List_Row_Item;    //每一行的数据
    QStringList Strlist_Header;
    QStringList Strlist_HeaderTip;
    QStandardItem* Ptr_Item;
    CheckBoxDelegate* Ptr_CheckBoxDelegate[2];
    
    //清除数据
    StdModel_OpCycle.clear();

    //设置表头和ToolTip
    Strlist_Header << "OpCycleID" << "Type" << "AutoStart" << "AutoStop";
    Strlist_HeaderTip << QString::fromLocal8Bit("当前OpCycle的ID") \
                      << QString::fromLocal8Bit("类型名(暂时没用到，可忽略)") \
                      << QString::fromLocal8Bit("该OpCycle是否自动开启(在Dem_PreInit中)")\
                      << QString::fromLocal8Bit("该OpCycle是否自动停止");
    
    for(int i = 0; i < Strlist_Header.size(); i++)
    {
        Ptr_Item = new QStandardItem(Strlist_Header.at(i));
        Ptr_Item->setTextAlignment(Qt::AlignCenter);
        Ptr_Item->setToolTip(Strlist_HeaderTip.at(i));
        StdModel_OpCycle.setHorizontalHeaderItem(i,Ptr_Item);
    }

    //设置表行数和列数
    row = List_OpCycle_Infos_User.count();
    col = StdModel_OpCycle.columnCount();
    StdModel_OpCycle.setColumnCount(col);

    //设置代理
    Ptr_CheckBoxDelegate[0] = new CheckBoxDelegate(Ptr_TableView_OpCycle);
    Ptr_CheckBoxDelegate[1] = new CheckBoxDelegate(Ptr_TableView_OpCycle);
    
    Ptr_CheckBoxDelegate[0]->setColumn(2);
    Ptr_CheckBoxDelegate[1]->setColumn(3);

    Ptr_TableView_OpCycle->setItemDelegateForColumn(2,Ptr_CheckBoxDelegate[0]);
    Ptr_TableView_OpCycle->setItemDelegateForColumn(3,Ptr_CheckBoxDelegate[1]);

    //设置OpCycle表的信息
    for(uint8 i = 0; i < row; i++)
    {
        List_Row_Item.clear();
        for(uint8 j = 0; j < col; j++)
        {
            Ptr_Item = new QStandardItem();
            //设置文字居中对齐
            Ptr_Item->setTextAlignment(Qt::AlignCenter);
            switch(j)
            {
                case (0):
                    Ptr_Item->setText(QString::number(List_OpCycle_Infos_User.at(i)->Id, 10).toUpper());
                    break;
                case (1):
                    /* 禁止编辑, 使能Check */
                    Ptr_Item->setEditable(false);
                    Ptr_Item->setText(QString::number(List_OpCycle_Infos_User.at(i)->Type, 10).toUpper());
                    break;
                case (2):
                    if(0 != List_OpCycle_Infos_User.at(i)->AutoStart)
                    {
                        //Ptr_Item->setCheckState(Qt::Checked);
                        Ptr_Item->setData(Qt::Checked, Qt::DisplayRole);
                    }
                    else
                    {
                        //Ptr_Item->setCheckState(Qt::Unchecked);
                        Ptr_Item->setData(Qt::Unchecked, Qt::DisplayRole);
                    }
                    /* 禁止编辑, 使能Check */
                    // Ptr_Item->setEditable(false);
                    // Ptr_Item->setCheckable(true);
                    break;
                case (3):
                    if(0 != List_OpCycle_Infos_User.at(i)->AutoStop)
                    {
                        //Ptr_Item->setCheckState(Qt::Checked);
                        Ptr_Item->setData(Qt::Checked, Qt::DisplayRole);
                    }
                    else
                    {
                        //Ptr_Item->setCheckState(Qt::Unchecked);
                        Ptr_Item->setData(Qt::Unchecked, Qt::DisplayRole);
                    }
                    /* 禁止编辑, 使能Check */
                    // Ptr_Item->setEditable(false);
                    // Ptr_Item->setCheckable(true);
                    break;
                default:
                        break;
            }
            List_Row_Item.append(Ptr_Item);
        }
        StdModel_OpCycle.insertRow(i, List_Row_Item);
    }
    Ptr_TableView_OpCycle->setModel(&StdModel_OpCycle);

    //设置根据内容自动调整列宽
    Ptr_TableView_OpCycle->resizeColumnsToContents();
    //再加宽40
    for(uint8 i = 0; i < Ptr_TableView_OpCycle->horizontalHeader()->count(); i++)
    {
        Ptr_TableView_OpCycle->setColumnWidth(i, Ptr_TableView_OpCycle->columnWidth(i) + 40);
    }
}

//根据List_XXXX_Infos_User 更新Debounce TableView显示
void MainWindow::TableView_UpdateDebounce(void)
{
    qDebug() << "Update Debounce";
    uint8 row = 0;
    uint8 col = 0;
    QList<QStandardItem*> List_Row_Item;    //每一行的数据
    QStringList Strlist_Header;
    QStringList Strlist_HeaderTip;
    QStandardItem* Ptr_Item;
    CheckBoxDelegate* Ptr_CheckBoxDelegate[2];

    //清除数据
    StdModel_Debounce.clear();

    //设置模型
    Ptr_TableView_Debounce->setModel(&StdModel_Debounce);
    Ptr_TableView_Debounce->setItemDelegateForColumn(8,Ptr_ComBoxDelegate_AlgoClass);
    Ptr_TableView_Debounce->setItemDelegateForColumn(11,Ptr_ComBoxDelegate_Behavior);

    //设置表头和ToolTip
    Strlist_Header << "FailedThershold" << "PassedThershold" << "FailedTimeThershold" << "PassedTimeThershold" \
                   << "DecStepSize" << "IncStepSize" << "JumpUpValue" << "JumpDownValue"\
                   << "AlgoClass" << "JumpUp" << "JumpDown" << "behavior";
    Strlist_HeaderTip << QString::fromLocal8Bit("BaseCounter算法,Failed阈值") \
                      << QString::fromLocal8Bit("BaseCounter算法,Passed阈值") \
                      << QString::fromLocal8Bit("BaseTimer算法,Failed阈值")\
                      << QString::fromLocal8Bit("BaseTImer算法,Passed阈值")\
                      << QString::fromLocal8Bit("FDC减少的步长")\
                      << QString::fromLocal8Bit("FDC增加的步长")\
                      << QString::fromLocal8Bit("JumpUp的值")\
                      << QString::fromLocal8Bit("JumpDown的值")\
                      << QString::fromLocal8Bit("Debounce算法")\
                      << QString::fromLocal8Bit("是否允许JumpUp")\
                      << QString::fromLocal8Bit("是否允许JumpDown")\
                      << QString::fromLocal8Bit("EnCondition或StoreCondition条件不满足时的Debounce行为");

    for(int i = 0; i < Strlist_Header.size(); i++)
    {
        Ptr_Item = new QStandardItem(Strlist_Header.at(i));
        Ptr_Item->setTextAlignment(Qt::AlignCenter);
        Ptr_Item->setToolTip(Strlist_HeaderTip.at(i));
        StdModel_Debounce.setHorizontalHeaderItem(i,Ptr_Item);
    }
    
    //设置表行数和列数
    row = List_Debounce_Infos_User.count();
    col = StdModel_Debounce.columnCount();
    StdModel_Debounce.setColumnCount(col);

    //设置代理
    Ptr_CheckBoxDelegate[0] = new CheckBoxDelegate(Ptr_TableView_Debounce);
    Ptr_CheckBoxDelegate[1] = new CheckBoxDelegate(Ptr_TableView_Debounce);
    
    Ptr_CheckBoxDelegate[0]->setColumn(9);
    Ptr_CheckBoxDelegate[1]->setColumn(10);

    Ptr_TableView_Debounce->setItemDelegateForColumn(9,Ptr_CheckBoxDelegate[0]);
    Ptr_TableView_Debounce->setItemDelegateForColumn(10,Ptr_CheckBoxDelegate[1]);

    //设置Debounce表的信息
    for(uint8 i = 0; i < row; i++)
    {
        List_Row_Item.clear();
        for(uint8 j = 0; j < col; j++)
        {
            Ptr_Item = new QStandardItem();
            //设置文字居中对齐
            Ptr_Item->setTextAlignment(Qt::AlignCenter);
            switch(j)
            {
                case (0):
                    Ptr_Item->setText(QString::number(List_Debounce_Infos_User.at(i)->FailedThershold, 10).toUpper());
                    break;
                case (1):
                    Ptr_Item->setText(QString::number(List_Debounce_Infos_User.at(i)->PassedThershold, 10).toUpper());
                    break;
                case (2):
                    Ptr_Item->setText(QString::number(List_Debounce_Infos_User.at(i)->FailedTimeThershold, 10).toUpper());
                    break;
                case (3):
                    Ptr_Item->setText(QString::number(List_Debounce_Infos_User.at(i)->PassedTimeThershold, 10).toUpper());
                    break;
                case (4):
                    Ptr_Item->setText(QString::number(List_Debounce_Infos_User.at(i)->DecStepSize, 10).toUpper());
                    break;
                case (5):
                    Ptr_Item->setText(QString::number(List_Debounce_Infos_User.at(i)->IncStepSize, 10).toUpper());
                    break;
                case (6):
                    Ptr_Item->setText(QString::number(List_Debounce_Infos_User.at(i)->JumpUpValue, 10).toUpper());
                    break;
                case (7):
                    Ptr_Item->setText(QString::number(List_Debounce_Infos_User.at(i)->JumpDownValue, 10).toUpper());
                    break;
                case (8):
                    {
                        /* do nothing */
                    }
                break;
                case (9):
                    if(false != List_Debounce_Infos_User.at(i)->JumpUp)
                    {
                        //Ptr_Item->setCheckState(Qt::Checked);
                        Ptr_Item->setData(Qt::Checked, Qt::DisplayRole);
                    }
                    else
                    {
                        //Ptr_Item->setCheckState(Qt::Unchecked);
                        Ptr_Item->setData(Qt::Unchecked, Qt::DisplayRole);
                    }
                    /* 禁止编辑, 使能Check */
                    // Ptr_Item->setEditable(false);
                    // Ptr_Item->setCheckable(true);
                    break;
                case (10):
                    if(false != List_Debounce_Infos_User.at(i)->JumpDown)
                    {
                        //Ptr_Item->setCheckState(Qt::Checked);
                        Ptr_Item->setData(Qt::Checked, Qt::DisplayRole);
                    }
                    else
                    {
                        //Ptr_Item->setCheckState(Qt::Unchecked);
                        Ptr_Item->setData(Qt::Unchecked, Qt::DisplayRole);
                    }
                    /* 禁止编辑, 使能Check */
                    // Ptr_Item->setEditable(false);
                    // Ptr_Item->setCheckable(true);
                    break;
                case (11):
                    break;
                default:
                        break;
            }
            List_Row_Item.append(Ptr_Item);
        }

        StdModel_Debounce.insertRow(i, List_Row_Item);

        //根据用户值设置当前Combox显示,通过SetindexWidget()设置ComboBox后,TableView数据变化后,识别不了
        //Note:在Model中加入了该QStandItem之后，再设置Widget才会生效
        //        Ptr_TableView_Debounce->setIndexWidget(StdModel_Debounce.index(i,8),Ptr_ComBox_Alogclass);
        //        uint8 AlgoClass_u8 = List_Debounce_Infos_User.at(i)->AlgoClass;
        //         Ptr_ComBox_Alogclass->setCurrentIndex(AlgoClass_u8);

        //在给定索引处的项上打开一个持久编辑器。如果不存在编辑器，委托将创建一个新的编辑器
        QModelIndex index = StdModel_Debounce.index(i,8);
        Ptr_TableView_Debounce->openPersistentEditor(index);
        //根据 AlgoClass_u8 设置当前ComboBox的index
        uint8 AlgoClass_u8 = List_Debounce_Infos_User.at(i)->AlgoClass;
        Ptr_ComBox_Alogclass = (QComboBox*)Ptr_TableView_Debounce->indexWidget(index);
        Ptr_ComBox_Alogclass->setCurrentIndex(AlgoClass_u8);

        //在给定索引处的项上打开一个持久编辑器。如果不存在编辑器，委托将创建一个新的编辑器
        index = StdModel_Debounce.index(i,11);
        Ptr_TableView_Debounce->openPersistentEditor(index);
        //根据 Behavior_u8 设置当前ComboBox的index
        uint8 Behavior_u8 = List_Debounce_Infos_User.at(i)->behavior;
        Ptr_ComBox_Behavior = (QComboBox*)Ptr_TableView_Debounce->indexWidget(index);
        Ptr_ComBox_Behavior->setCurrentIndex(Behavior_u8);
    }

    //设置根据内容自动调整列宽
    Ptr_TableView_Debounce->resizeColumnsToContents();
    //再加宽40
    for(uint8 i = 0; i < Ptr_TableView_Debounce->horizontalHeader()->count(); i++)
    {
        Ptr_TableView_Debounce->setColumnWidth(i, Ptr_TableView_Debounce->columnWidth(i) + 40);
    }
}

//根据List_XXXX_Infos_User 更新DTC TableView显示
void MainWindow::TableView_UpdateDTC(void)
{
    qDebug() << "Update DTC";
    uint8 row = 0;
    uint8 col = 0;
    QList<QStandardItem*> List_Row_Item;    //每一行的数据
    QStringList Strlist_Header;
    QStringList Strlist_HeaderTip;
    QStandardItem* Ptr_Item;
    CheckBoxDelegate* Ptr_CheckBoxDelegate[3];
    
    //清除数据
    StdModel_DTC.clear();

    //设置表头和ToolTip
    Strlist_Header << "DTC Value" << "AttrbsRef" << "AgingThershold" << "AgingOpCycleRef" \
                   << "ImmediateNvStorageAllowed" << "AgingAllowed" << "InitFun" << "Event ID"\
                   << "EventKind" << "FailureCycleCounterThershold" << "DebounceTableRef" << "OpCycleRef"\
                   << "DTCTableRef" << "EnableConditionRef" << "StorageConditionRef" << "AvailableStatus";
    Strlist_HeaderTip << QString::fromLocal8Bit("DTC value") \
                      << QString::fromLocal8Bit("对AttrbsRef Table引用的index(自动配置)") \
                      << QString::fromLocal8Bit("老化的阈值")\
                      << QString::fromLocal8Bit("老化流程选择的OpCycle") \
                      << QString::fromLocal8Bit("是否允许立即存储E2(默认为TRUE)") \
                      << QString::fromLocal8Bit("是否允许DTC老化")\
                      << QString::fromLocal8Bit("DTC初始化函数或清除DTC后执行的函数")\
                      << QString::fromLocal8Bit("DTC对应的EventID(自动配置)") \
                      << QString::fromLocal8Bit("Event类型(BSW或ASW)") \
                      << QString::fromLocal8Bit("FaultDetectedCounter的阈值")\
                      << QString::fromLocal8Bit("DTC选择的DebounceTable引用")\
                      << QString::fromLocal8Bit("DTC OpCycle") \
                      << QString::fromLocal8Bit("DTC Value的引用(自动配置)") \
                      << QString::fromLocal8Bit("引用EnableCondition的Index")\
                      << QString::fromLocal8Bit("引用StoreleCondition的Index")\
                      << QString::fromLocal8Bit("是否允许该DTC被记录");

    for(int i = 0; i < Strlist_Header.size(); i++)
    {
        Ptr_Item = new QStandardItem(Strlist_Header.at(i));
        Ptr_Item->setTextAlignment(Qt::AlignCenter);
        Ptr_Item->setToolTip(Strlist_HeaderTip.at(i));
        StdModel_DTC.setHorizontalHeaderItem(i,Ptr_Item);
    }
    
    //设置表行数和列数
    row = List_DTC_Infos_User.count();
    col = StdModel_DTC.columnCount();
    StdModel_DTC.setColumnCount(col);

    //设置模型
    Ptr_TableView_DTC->setModel(&StdModel_DTC);
    Ptr_TableView_DTC->setItemDelegateForColumn(8,Ptr_ComBoxDelegate_EventKind);
    
    //设置代理
    Ptr_CheckBoxDelegate[0] = new CheckBoxDelegate(Ptr_TableView_DTC);
    Ptr_CheckBoxDelegate[1] = new CheckBoxDelegate(Ptr_TableView_DTC);
    Ptr_CheckBoxDelegate[2] = new CheckBoxDelegate(Ptr_TableView_DTC);
    
    Ptr_CheckBoxDelegate[0]->setColumn(4);
    Ptr_CheckBoxDelegate[1]->setColumn(5);
    Ptr_CheckBoxDelegate[2]->setColumn(15);

    Ptr_TableView_DTC->setItemDelegateForColumn(4,Ptr_CheckBoxDelegate[0]);
    Ptr_TableView_DTC->setItemDelegateForColumn(5,Ptr_CheckBoxDelegate[1]);
    Ptr_TableView_DTC->setItemDelegateForColumn(15,Ptr_CheckBoxDelegate[2]);

    //设置DTC表的信息
    for(uint8 i = 0; i < row; i++)
    {
        List_Row_Item.clear();
        for(uint8 j = 0; j < col; j++)
        {
            Ptr_Item = new QStandardItem();
            //设置文字居中对齐
            Ptr_Item->setTextAlignment(Qt::AlignCenter);
            switch(j)
            {
                case (0):
                    Ptr_Item->setText(QString::number(List_DTC_Infos_User.at(i)->Value, 16).toUpper());
                    break;
                case (1):
                    /* 禁止编辑, 使能Check */
                    Ptr_Item->setEditable(false);
                    //根据index来确定AttrbsRef
                    List_DTC_Infos_User.at(i)->AttrbsRef = i;
                    Ptr_Item->setText(QString::number(List_DTC_Infos_User.at(i)->AttrbsRef, 10).toUpper());
                    break;
                case (2):
                    Ptr_Item->setText(QString::number(List_DTC_Infos_User.at(i)->AgingThershold, 10).toUpper());
                    break;
                case (3):
                    /* 禁止编辑, 使能Check */
                    Ptr_Item->setEditable(false);
                    Ptr_Item->setText(QString::number(List_DTC_Infos_User.at(i)->AgingOpCycleRef, 10).toUpper());
                    break;
                case (4):
                    if(0 != List_DTC_Infos_User.at(i)->ImmediateNvStorageAllowed)
                    {
                        //Ptr_Item->setCheckState(Qt::Checked);
                        Ptr_Item->setData(Qt::Checked, Qt::DisplayRole);
                    }
                    else
                    {
                        //Ptr_Item->setCheckState(Qt::Unchecked);
                        Ptr_Item->setData(Qt::Unchecked, Qt::DisplayRole);
                    }
                    // /* 禁止编辑, 使能Check */
                    // Ptr_Item->setEditable(false);
                    // Ptr_Item->setCheckable(true);
                    break;
                case (5):
                    if(0 != List_DTC_Infos_User.at(i)->AgingAllowed)
                    {
                        //Ptr_Item->setCheckState(Qt::Checked);
                        Ptr_Item->setData(Qt::Checked, Qt::DisplayRole);
                    }
                    else
                    {
                        //Ptr_Item->setCheckState(Qt::Unchecked);
                        Ptr_Item->setData(Qt::Unchecked, Qt::DisplayRole);
                    }
                    // /* 禁止编辑, 使能Check */
                    // Ptr_Item->setEditable(false);
                    // Ptr_Item->setCheckable(true);
                    break;
                case (6):
                    /* 禁止编辑, 使能Check */
                    Ptr_Item->setEditable(false);
                    Ptr_Item->setText("Null_Ptr");
                    break;
                case (7):
                    //根据index来确定 DTCTableRef
                    List_DTC_Infos_User.at(i)->Id = i;
                    Ptr_Item->setText(QString::number(List_DTC_Infos_User.at(i)->Id, 10).toUpper());
                    break;
                case (8):
                    //QComboBox用全局变量控制
                    break;
                case (9):
                    Ptr_Item->setText(QString::number(List_DTC_Infos_User.at(i)->FailureCycleCounterThershold, 10).toUpper());
                    break;
                case (10):
                    Ptr_Item->setText(QString::number(List_DTC_Infos_User.at(i)->DebounceTableRef, 10).toUpper());
                    break;
                case (11):
                    /* 禁止编辑, 使能Check */
                    Ptr_Item->setEditable(false);
                    Ptr_Item->setText(QString::number(List_DTC_Infos_User.at(i)->OpCycleRef, 10).toUpper());
                    break;
                case (12):
                    /* 禁止编辑, 使能Check */
                    Ptr_Item->setEditable(false);
                    //根据index来确定 DTCTableRef
                    List_DTC_Infos_User.at(i)->DTCTableRef = i;
                    Ptr_Item->setText(QString::number(List_DTC_Infos_User.at(i)->DTCTableRef, 10).toUpper());
                    break;
                case (13):
                    /* 禁止编辑, 使能Check */
                    Ptr_Item->setEditable(false);
                    Ptr_Item->setText(QString::number(List_DTC_Infos_User.at(i)->EnableConditionRef, 10).toUpper());
                    break;
                case (14):
                    /* 禁止编辑, 使能Check */
                    Ptr_Item->setEditable(false);
                    Ptr_Item->setText(QString::number(List_DTC_Infos_User.at(i)->StorageConditionRef, 10).toUpper());
                    break;
                case (15):
                    if(false != List_DTC_Infos_User.at(i)->AvailableStatus)
                    {
                        //Ptr_Item->setCheckState(Qt::Checked);
                        Ptr_Item->setData(Qt::Checked, Qt::DisplayRole);
                    }
                    else
                    {
                        //Ptr_Item->setCheckState(Qt::Unchecked);
                        Ptr_Item->setData(Qt::Unchecked, Qt::DisplayRole);
                    }
                    /* 禁止编辑, 使能Check */
                    // Ptr_Item->setEditable(false);
                    // Ptr_Item->setCheckable(true);
                    break;
                default:
                    break;
            }
            List_Row_Item.append(Ptr_Item);
        }
        StdModel_DTC.insertRow(i, List_Row_Item);

        //在给定索引处的项上打开一个持久编辑器。如果不存在编辑器，委托将创建一个新的编辑器
        QModelIndex index = StdModel_DTC.index(i,8);
        Ptr_TableView_DTC->openPersistentEditor(index);

        //根据 EventKind_u8 设置当前ComboBox的index
        uint8 EventKind_u8 = List_DTC_Infos_User.at(i)->EventKind;
        Ptr_Combox_EventKind = (QComboBox*)(Ptr_TableView_DTC->indexWidget(index));
        Ptr_Combox_EventKind->setCurrentIndex(EventKind_u8);

    }

    //设置根据内容自动调整列宽
    Ptr_TableView_DTC->resizeColumnsToContents();
    //再加宽40
    for(uint8 i = 0; i < Ptr_TableView_DTC->horizontalHeader()->count(); i++)
    {
        Ptr_TableView_DTC->setColumnWidth(i, Ptr_TableView_DTC->columnWidth(i) + 40);
    }
}

//根据List_XXXX_Infos_User 更新NVM TableView显示
void MainWindow::TableView_UpdateNVM(void)
{
    qDebug() << "Update NVM";
    uint8 row = 0;
    uint8 col = 0;
    QList<QStandardItem*> List_Row_Item;    //每一行的数据
    QStringList Strlist_Header;
    QStringList Strlist_HeaderTip;
    QStandardItem* Ptr_Item;
    CheckBoxDelegate* Ptr_CheckBoxDelegate[2];

    //清除数据
    StdModel_NVM.clear();

    //设置表头和ToolTip
    Strlist_Header << "InitCallback" << "Block Name" << "Block Id" << "Block Length(Byte)" << "RamBlock" << "RomBlock" \
                   << "DefaultData" << "CallBack" << "BlockJobPriority" << "MaxNumReadRetries" << "MaxNumWriteRetries"\
                   << "NvRamDeviceId" << "BlockCrcType" << "NvM_BlockType" << "SelectBlockForReadAll"\
                   << "SelectBlockForWriteAll";
    Strlist_HeaderTip << QString::fromLocal8Bit("初始化Callback函数") \
                      << QString::fromLocal8Bit("Block Name") \
                      << QString::fromLocal8Bit("Block Id")\
                      << QString::fromLocal8Bit("Block Length(Byte)") \
                      << QString::fromLocal8Bit("RamBlock") \
                      << QString::fromLocal8Bit("RomBlock")\
                      << QString::fromLocal8Bit("默认数据")\
                      << QString::fromLocal8Bit("CallBack")\
                      << QString::fromLocal8Bit("优先级") \
                      << QString::fromLocal8Bit("重读次数") \
                      << QString::fromLocal8Bit("重写次数")\
                      << QString::fromLocal8Bit("驱动(FEE or EA)")\
                      << QString::fromLocal8Bit("CRC") \
                      << QString::fromLocal8Bit("Block Type") \
                      << QString::fromLocal8Bit("ReadAll时是否读取")\
                      << QString::fromLocal8Bit("WriteAll时是否写入");

    for(uint8 i = 0; i < Strlist_Header.size(); i++)
    {
        Ptr_Item = new QStandardItem(Strlist_Header.at(i));
        Ptr_Item->setTextAlignment(Qt::AlignCenter);
        Ptr_Item->setToolTip(Strlist_HeaderTip.at(i));
        StdModel_NVM.setHorizontalHeaderItem(i,Ptr_Item);
    }

    //设置表行数和列数
    row = List_NVM_Infos_User.count();
    col = StdModel_NVM.columnCount();
    StdModel_NVM.setColumnCount(col);

    //设置模型
    Ptr_TableView_NVM->setModel(&StdModel_NVM);

    //设置ComBOx代理
    Ptr_TableView_NVM->setItemDelegateForColumn(11,Ptr_ComBoxDelegate_DeviceKind);

    //设置CheckBox代理
    Ptr_CheckBoxDelegate[0] = new CheckBoxDelegate(Ptr_TableView_NVM);
    Ptr_CheckBoxDelegate[1] = new CheckBoxDelegate(Ptr_TableView_NVM);
    
    Ptr_CheckBoxDelegate[0]->setColumn(14);
    Ptr_CheckBoxDelegate[1]->setColumn(15);

    Ptr_TableView_NVM->setItemDelegateForColumn(14,Ptr_CheckBoxDelegate[0]);
    Ptr_TableView_NVM->setItemDelegateForColumn(15,Ptr_CheckBoxDelegate[1]);

    //设置NVM表的信息
    for(uint8 i = 0; i < row; i++)
    {
        List_Row_Item.clear();
        for(uint8 j = 0; j < col; j++)
        {
            Ptr_Item = new QStandardItem();
            //设置文字居中对齐
            Ptr_Item->setTextAlignment(Qt::AlignCenter);
            switch(j)
            {
                case (0):
                    /* 禁止编辑 */
                    Ptr_Item->setEditable(false);
                    Ptr_Item->setText(List_NVM_Infos_User.at(i)->Str_InitFun);
                    break;
                case (1):
                    //设置文字左对齐
                    Ptr_Item->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
                    Ptr_Item->setText(List_NVM_Infos_User.at(i)->Str_BlockName);
                    break;
                case (2):
                    /* 禁止编辑 */
                    //根据Index来更新 BlockId
                    List_NVM_Infos_User.at(i)->NvBlockBaseNumber = i;
                    Ptr_Item->setText(QString::number(List_NVM_Infos_User.at(i)->NvBlockBaseNumber));
                    break;
                case (3):
                    //设置文字左对齐
                    Ptr_Item->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
                    Ptr_Item->setText(List_NVM_Infos_User.at(i)->Str_NvBlockLength);
                    break;
                case (4):
                    //设置文字左对齐
                    Ptr_Item->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
                    Ptr_Item->setText(List_NVM_Infos_User.at(i)->Str_RamBlockDataAddress);
                    break;
                case (5):
                    //设置文字左对齐
                    Ptr_Item->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
                    Ptr_Item->setText(List_NVM_Infos_User.at(i)->Str_RomBlockDataAddress);
                    break;
                case (6):
                    //设置文字左对齐
                    Ptr_Item->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
                    Ptr_Item->setText(List_NVM_Infos_User.at(i)->Str_RomBlockDefaultData);
                    break;
                case (7):
                    //设置文字左对齐
                    Ptr_Item->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
                    Ptr_Item->setText(List_NVM_Infos_User.at(i)->Str_JobFinishedFunction);
                    break;
                case (8):
                    /* 禁止编辑 */
                    Ptr_Item->setEditable(false);
                    Ptr_Item->setText(QString::number(List_NVM_Infos_User.at(i)->BlockJobPriority));
                    break;
                case (9):
                    Ptr_Item->setText(QString::number(List_NVM_Infos_User.at(i)->MaxNumReadRetries));
                    break;
                case (10):
                    Ptr_Item->setText(QString::number(List_NVM_Infos_User.at(i)->MaxNumWriteRetries));
                    break;
                case (11): /* ComBox 用全局变量控制 */
                    //Ptr_Item->setText(QString::number(List_NVM_Infos_User.at(i)->NvRamDeviceId));
                    break;
                case (12):
                    /* 禁止编辑 */
                    Ptr_Item->setEditable(false);
                    Ptr_Item->setText(QString::number(List_NVM_Infos_User.at(i)->BlockCrcType));
                    break;
                case (13):
                    /* 禁止编辑 */
                    Ptr_Item->setEditable(false);
                    Ptr_Item->setText(QString::number(List_NVM_Infos_User.at(i)->BlockManagementType));
                    break;
                case (14): /* CheckBox */
                    if(0 != List_NVM_Infos_User.at(i)->SelectBlockForReadAll)
                    {
                        //Ptr_Item->setCheckState(Qt::Checked);
                        Ptr_Item->setData(Qt::Checked, Qt::DisplayRole);
                    }
                    else
                    {
                        //Ptr_Item->setCheckState(Qt::Unchecked);
                        Ptr_Item->setData(Qt::Unchecked, Qt::DisplayRole);
                    }
                    /* 禁止编辑, 使能Check */
                    // Ptr_Item->setEditable(false);
                    // Ptr_Item->setCheckable(true);
                    break;
                case (15): /* CheckBox */
                    if(0 != List_NVM_Infos_User.at(i)->SelectBlockForWriteAll)
                    {
                        //Ptr_Item->setCheckState(Qt::Checked);
                        Ptr_Item->setData(Qt::Checked, Qt::DisplayRole);
                    }
                    else
                    {
                        //Ptr_Item->setCheckState(Qt::Unchecked);
                        Ptr_Item->setData(Qt::Unchecked, Qt::DisplayRole);
                    }
                    /* 禁止编辑, 使能Check */
                    // Ptr_Item->setEditable(false);
                    // Ptr_Item->setCheckable(true);
                    break;
                default:
                        break;
            }
            List_Row_Item.append(Ptr_Item);
        }
        StdModel_NVM.insertRow(i, List_Row_Item);

        //在给定索引处的项上打开一个持久编辑器。如果不存在编辑器，委托将创建一个新的编辑器
        QModelIndex index = StdModel_NVM.index(i,11);
        Ptr_TableView_NVM->openPersistentEditor(index);

        //根据 ComBox类型 设置当前ComboBox的index
        uint8 DeviceKind_u8 = List_NVM_Infos_User.at(i)->NvRamDeviceId;
        Ptr_Combox_NvmDeviceKind = (QComboBox*)(Ptr_TableView_NVM->indexWidget(index));
        Ptr_Combox_NvmDeviceKind->setCurrentIndex(DeviceKind_u8);
    }

    //设置根据内容自动调整列宽
    Ptr_TableView_NVM->resizeColumnsToContents();
    //再加宽40
    for(uint8 i = 0; i < Ptr_TableView_NVM->horizontalHeader()->count(); i++)
    {
        Ptr_TableView_NVM->setColumnWidth(i, Ptr_TableView_NVM->columnWidth(i) + 40);
    }

    //默认数据列给500宽度
    Ptr_TableView_NVM->setColumnWidth(6, 500);
}

//根据List_XXXX_Infos_User 更新FEE TableView显示
void MainWindow::TableView_UpdateFEE(void)
{
    qDebug() << "Update FEE Table";
    uint8 row = 0;
    uint8 col = 0;
    QList<QStandardItem*> List_Row_Item;    //每一行的数据
    QStringList Strlist_Header;
    QStandardItem* Ptr_Item;

    //Print_Info_User();
    //设置表行数和列数
    StdModel_FEE.clear();
    StdModel_FEE.setColumnCount(2);
    row = List_FEE_Infos_User.count();
    col = 2;

    //设置表头
    Strlist_Header << "Item" << "Value";
    for(int i = 0; i < Strlist_Header.size(); i++)
    {
        Ptr_Item = new QStandardItem(Strlist_Header.at(i));
        Ptr_Item->setTextAlignment(Qt::AlignCenter);
        StdModel_FEE.setHorizontalHeaderItem(i,Ptr_Item);
    }

    //设置FEE表的信息
    for(int i = 0; i < row; i++)
    {
        QStandardItem* Ptr_Item_Temp[2];

        List_Row_Item.clear();
        Ptr_Item_Temp[0] = new QStandardItem(List_FEE_Infos_User.at(i)->Item);
        Ptr_Item_Temp[1] = new QStandardItem(List_FEE_Infos_User.at(i)->Value);

        //设置文字对齐
        Ptr_Item_Temp[0]->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
        Ptr_Item_Temp[1]->setTextAlignment(Qt::AlignCenter);
        //设置不可编辑
        Ptr_Item_Temp[0]->setEditable(false);

        List_Row_Item.append(Ptr_Item_Temp[0]);
        List_Row_Item.append(Ptr_Item_Temp[1]);

        StdModel_FEE.insertRow(i, List_Row_Item);
    }
    Ptr_TableView_FEE->setModel(&StdModel_FEE);
    Ptr_TableView_FEE->setColumnWidth(0, 200);
}

//根据用户在 DcmGeneran TabView上的配置信息，反向修改List_XXXX_Infos_User
void MainWindow::Slot_UpdateDcmGeneralInfos(QStandardItem *item)
{
    qDebug("Rid Data Changed...");

    uint8 i = 0;
    uint8 row = 0;
    S_DcmGeneral_Infos_User_Type* Ptr_DcmGeneral_Temp;

    row = StdModel_DcmGeneral.rowCount();

    //获取界面上用户配置的信息
    if(row != 0)
    {
        //删除原来的配置信息
        List_DcmGeneral_Infos_User.clear();
        //重新获取界面的配置信息，
        for(i = 0; i < row; i++)
        {
            Ptr_DcmGeneral_Temp = new S_DcmGeneral_Infos_User_Type;
            Ptr_DcmGeneral_Temp->Item = StdModel_DcmGeneral.item(i, 0)->text();
            Ptr_DcmGeneral_Temp->Value = StdModel_DcmGeneral.item(i, 1)->text();
            List_DcmGeneral_Infos_User.append(Ptr_DcmGeneral_Temp);
        }
    }
}

//根据用户在 Did TabView上的配置信息，反向修改List_XXXX_Infos_User
void MainWindow::Slot_UpdateDidInfos(QStandardItem *item)
{
    qDebug("Did Data Changed...");

    uint8 i = 0;
    uint8 j = 0;
    bool Result = 0;
    uint8 row = 0;
    uint8 col = 0;
    uint8 OpInfo_Counter = 0;
    S_DID_Infos_User_Type* Ptr_S_DidInfos_Temp_User;
    uint8 Did_Operation = 0;
    S_DID_Configs_Type* Ptr_S_DidConfigs_Temp;
    Dcm_DspDidInfoType S_DidInfo_Temp;
    Dcm_DspDidOpInfoType S_DidOpInfo_Temp;
    QModelIndex Index;
    QVariant IndexData;

    if((l_DidTable_UpdateReason == TABLE_UPDATE_BY_USER) && \
       (false != l_DidTableUpdate_Finished))
    {
        return;
    }

    row = StdModel_Did.rowCount();
    col = StdModel_Did.columnCount();
    Ptr_S_DidConfigs_Temp = new S_DID_Configs_Type;

    //清除当前的DID配置信息
    List_Did.clear();
    List_DidInfo.clear();
    List_DidOpInfo.clear();

    //获取界面上用户配置的信息
    if(row != 0)
    {
        //删除原来的配置信息
        List_DID_Infos_User.clear();
        //重新获取界面的配置信息，
        for(i = 0; i < row; i++)
        {
            Ptr_S_DidInfos_Temp_User = new S_DID_Infos_User_Type;
            Ptr_S_DidInfos_Temp_User->IsOnlyEol = 0;
            Ptr_S_DidInfos_Temp_User->Operation = 0;

            Did_Operation = DID_NONE;
            Ptr_S_DidInfos_Temp_User->Did = StdModel_Did.item(i,0)->text().toUInt(&Result, 16);
            Ptr_S_DidInfos_Temp_User->DataLen = StdModel_Did.item(i,3)->text().toUInt(&Result, 10);


            //            qDebug() << "RowData: " << StdModel_Did.item(i,1)->data(Qt::DisplayRole)\
            //                     << StdModel_Did.item(i,2)->data(Qt::DisplayRole)\
            //                     << StdModel_Did.item(i,4)->data(Qt::DisplayRole)\
            //                     << StdModel_Did.item(i,5)->data(Qt::DisplayRole);

            //从CheckBox中获取数据
            /* Read Flag */
            Index = StdModel_Did.index(i,1,QModelIndex());
            IndexData = StdModel_Did.data(Index,Qt::DisplayRole);
            if(IndexData == Qt::Checked)
            {
                Did_Operation |= DID_READ;
            }

            /* Write Flag */
            Index = StdModel_Did.index(i,2,QModelIndex());
            IndexData = StdModel_Did.data(Index,Qt::DisplayRole);
            if(StdModel_Did.data(Index,Qt::DisplayRole) == Qt::Checked)
            {
                Did_Operation |= DID_WRITE;
            }

            /* IoCtrl Flag */
            Index = StdModel_Did.index(i,4,QModelIndex());
            IndexData = StdModel_Did.data(Index,Qt::DisplayRole);
            if(IndexData == Qt::Checked)
            {
                Did_Operation |= DID_IOCTRL;
            }

            /* IsOnlyEol Flag */
            Index = StdModel_Did.index(i,5,QModelIndex());
            IndexData = StdModel_Did.data(Index,Qt::DisplayRole);
            if(IndexData == Qt::Checked)
            {
                Ptr_S_DidInfos_Temp_User->IsOnlyEol = 1;
            }
            else
            {
                Ptr_S_DidInfos_Temp_User->IsOnlyEol = 0;
            }

            Ptr_S_DidInfos_Temp_User->Operation = Did_Operation;
            List_DID_Infos_User.append(Ptr_S_DidInfos_Temp_User);
        }
    }

    //生成Did的配置表
    Print_Info_User();
    for(int i = 0; i < List_DID_Infos_User.count(); i++)
    {
        Ptr_S_DidConfigs_Temp->Did = List_DID_Infos_User.at(i)->Did;
        Ptr_S_DidConfigs_Temp->Length = List_DID_Infos_User.at(i)->DataLen;
        Ptr_S_DidConfigs_Temp->Operation = List_DID_Infos_User.at(i)->Operation;
        Ptr_S_DidConfigs_Temp->IsOnlyEol = List_DID_Infos_User.at(i)->IsOnlyEol;

        S_DidInfo_Temp.Length = Ptr_S_DidConfigs_Temp->Length;
        S_DidInfo_Temp.Operations = Ptr_S_DidConfigs_Temp->Operation;

        uint8 count = sizeof(State_SID_Table) / sizeof(State_SID_Table[0]);
        if(0 != (Ptr_S_DidConfigs_Temp->Operation & DID_READ))
        {
            for(int j = 0; j < count; j++)
            {
                if(State_SID_Table[j].Sid == (0x22))
                {
                    if(Ptr_S_DidConfigs_Temp->IsOnlyEol == 1)
                    {
                        S_DidOpInfo_Temp.State_Ref = State_SID_Table[j].Eol_StateRef; 
                    }
                    else
                    {
                        S_DidOpInfo_Temp.State_Ref = State_SID_Table[j].StateRef; 
                    }
                    break;
                }
            }
            S_DidOpInfo_Temp.Did = Ptr_S_DidConfigs_Temp->Did;
            S_DidOpInfo_Temp.CallTypes = 1;//默认值
            S_DidOpInfo_Temp.SignalInfo_Ref = 0;//默认值

            S_DidInfo_Temp.OpInfoRef = OpInfo_Counter;
            List_DidOpInfo.append(S_DidOpInfo_Temp);
            OpInfo_Counter++;
        }

        if(0 != (Ptr_S_DidConfigs_Temp->Operation & DID_WRITE))
        {
            for(int j = 0; j < count; j++)
            {
                if(State_SID_Table[j].Sid == (0x2E))
                { 
                    if(Ptr_S_DidConfigs_Temp->IsOnlyEol == 1)
                    {
                        S_DidOpInfo_Temp.State_Ref = State_SID_Table[j].Eol_StateRef; 
                    }
                    else
                    {
                        S_DidOpInfo_Temp.State_Ref = State_SID_Table[j].StateRef;
                    }
                    break;
                }
            }

            S_DidOpInfo_Temp.Did = Ptr_S_DidConfigs_Temp->Did;
            S_DidOpInfo_Temp.CallTypes = 1;//默认值
            S_DidOpInfo_Temp.SignalInfo_Ref = 0;//默认值

            List_DidOpInfo.append(S_DidOpInfo_Temp);
            OpInfo_Counter++;
        }


        if(0 != (Ptr_S_DidConfigs_Temp->Operation & DID_IOCTRL))
        {
            for(int j = 0; j < count; j++)
            {
                if(State_SID_Table[j].Sid == (0x2F))
                { 
                    if(Ptr_S_DidConfigs_Temp->IsOnlyEol == 1)
                    {
                        S_DidOpInfo_Temp.State_Ref = State_SID_Table[j].Eol_StateRef; 
                    }
                    else
                    {
                        S_DidOpInfo_Temp.State_Ref = State_SID_Table[j].StateRef;
                    }
                    break;
                }
            }

            S_DidOpInfo_Temp.Did = Ptr_S_DidConfigs_Temp->Did;
            S_DidOpInfo_Temp.CallTypes = 9;
            S_DidOpInfo_Temp.SignalInfo_Ref = 0;//默认值

            S_DidInfo_Temp.OpInfoRef = OpInfo_Counter;
            List_DidOpInfo.append(S_DidOpInfo_Temp);
            OpInfo_Counter++;
        }

        List_Did.append(Ptr_S_DidConfigs_Temp->Did);
        List_DidInfo.append(S_DidInfo_Temp);
    }
    //Print_Did_Infos();
}

//根据用户在 Rid TabView上的配置信息，反向修改List_XXXX_Infos_User
void MainWindow::Slot_UpdateRidInfos(QStandardItem *item)
{
    qDebug("Rid Data Changed...");

    uint8 i = 0;
    uint8 j = 0;
    bool Result = 0;
    uint8 row = 0;
    uint8 col = 0;
    uint8 State_Ref_Temp;
    S_RID_Infos_User_Type* Ptr_S_RidInfos_Temp_User;
    Dcm_DspRidInfoType S_RidInfo_Temp;
    Dcm_DspRidSignalInfoType S_RidSignalInfo_Temp;
    S_RID_RTN_Record_Type S_Rid_RTN_Record_Temp;

    if((l_RidTable_UpdateReason == TABLE_UPDATE_BY_USER) && \
       (false != l_RidTableUpdate_Finished))
    {
        return;
    }

    row = StdModel_Rid.rowCount();
    col = StdModel_Rid.columnCount();

    //清除当前的DID配置信息
    List_Rid.clear();
    List_RidInfo.clear();
    List_RidSignalInfo.clear();
    List_RTN_Record.clear();

    //获取界面上用户配置的信息
    if(row != 0)
    {
        //删除原来的配置信息
        List_RID_Infos_User.clear();
        //重新获取界面的配置信息，
        for(i = 0; i < row; i++)
        {
            Ptr_S_RidInfos_Temp_User = new S_RID_Infos_User_Type;

            Ptr_S_RidInfos_Temp_User->Rid = StdModel_Rid.item(i,0)->text().toUInt(&Result, 16);
            Ptr_S_RidInfos_Temp_User->Operation = 0xF;
            Ptr_S_RidInfos_Temp_User->RoutineType = 0x06;
            Ptr_S_RidInfos_Temp_User->RoutineControlOptionRecord = StdModel_Rid.item(i,2)->text().toUInt(&Result, 10);
            List_RID_Infos_User.append(Ptr_S_RidInfos_Temp_User);
        }
    }

    //生成Rid的配置表
    //获取0x31服务对应的State_Ref
    for(uint8 j = 0; j < sizeof(State_SID_Table) / sizeof(State_SID_Table[0]); j++)
    {
        if(State_SID_Table[j].Sid == (0x31))
        {
            State_Ref_Temp = State_SID_Table[j].StateRef;
            break;
        }
    }

    for(int i = 0; i < List_RID_Infos_User.count(); i++)
    {
        List_Rid.append(List_RID_Infos_User.at(i)->Rid);

        S_RidInfo_Temp.SignalInfo_Ref = i;
        S_RidInfo_Temp.State_Ref = State_Ref_Temp;
        S_RidInfo_Temp.Operation = 0xF;//默认值，暂不可配置
        List_RidInfo.append(S_RidInfo_Temp);

        S_RidSignalInfo_Temp.RidOpFunc_Ref = 0;//默认为0，实际代码中也只有1个Rid的分发函数
        S_RidSignalInfo_Temp.Req_Length = List_RID_Infos_User.at(i)->RoutineControlOptionRecord;
        S_RidSignalInfo_Temp.Resp_Length = 0xF;
        S_RidSignalInfo_Temp.OpType = 0xF;
        List_RidSignalInfo.append(S_RidSignalInfo_Temp);

        S_Rid_RTN_Record_Temp.routine_time = 0;//DR_TIME_NOT_REQ
        S_Rid_RTN_Record_Temp.routine_id = List_RID_Infos_User.at(i)->Rid;
        S_Rid_RTN_Record_Temp.routine_type = 0x06;//ROUTINE_TYPE_2|RC_STOP_SERVICE
        S_Rid_RTN_Record_Temp.sup_session = 0x04;
        S_Rid_RTN_Record_Temp.sess_sec_stat = 0x04;
        S_Rid_RTN_Record_Temp.supp_seclvl = 0;
        S_Rid_RTN_Record_Temp.DID_LHVSD_Check_Status = 0;//LHVSD_CHECK_NOT_NEEDED
        S_Rid_RTN_Record_Temp.Str_StartFunction = QString("ApplDiagStart_%1_RotineControl")\
                                                  .arg(List_RID_Infos_User.at(i)->Rid,4,16, QChar('0'));
        S_Rid_RTN_Record_Temp.Str_ResultFunction = QString("ApplDiagResults_%1_RotineControl")\
                                                  .arg(List_RID_Infos_User.at(i)->Rid,4,16, QChar('0'));
        S_Rid_RTN_Record_Temp.Str_StatusFunction = QString("ApplDiagStatus_%1_RotineControl")\
                                                  .arg(List_RID_Infos_User.at(i)->Rid,4,16, QChar('0'));
        S_Rid_RTN_Record_Temp.Str_StopFunction = QString("ApplDiagTerminal_%1_RotineControl")\
                                                  .arg(List_RID_Infos_User.at(i)->Rid,4,16, QChar('0'));
        List_RTN_Record.append(S_Rid_RTN_Record_Temp);
    }
}

//根据用户在 OpCycle TabView上的配置信息，反向修改List_XXXX_Infos_User
void MainWindow::Slot_UpdateOpCycleInfos(QStandardItem *item)
{
    qDebug("OpCycle Data Changed...");

    uint8 i = 0;
    uint8 j = 0;
    bool Result = 0;
    uint8 row = 0;
    uint8 col = 0;
    uint8 OpInfo_Counter = 0;
    S_OpCycle_Infos_User_Type* Ptr_S_OpCycleInfos_Temp_User;
    uint8 OpCycle_Operation = 0;
    QModelIndex Index;
    QVariant IndexData;

    if((l_OpCycleTable_UpdateReason == TABLE_UPDATE_BY_USER) && \
       (false != l_OpCycleTableUpdate_Finished))
    {
        return;
    }

    row = StdModel_OpCycle.rowCount();
    col = StdModel_OpCycle.columnCount();

    //Print_TableView();
    //获取界面上用户配置的信息
    if(row != 0)
    {
        //删除原来的配置信息
        List_OpCycle_Infos_User.clear();
        //重新获取界面的配置信息，
        for(i = 0; i < row; i++)
        {
            Ptr_S_OpCycleInfos_Temp_User = new S_OpCycle_Infos_User_Type;
            Ptr_S_OpCycleInfos_Temp_User->Id = StdModel_OpCycle.item(i,0)->text().toUInt(&Result, 10);
            Ptr_S_OpCycleInfos_Temp_User->Type = StdModel_OpCycle.item(i,1)->text().toUInt(&Result, 10);

            Index = StdModel_OpCycle.index(i,2,QModelIndex());
            IndexData = StdModel_OpCycle.data(Index,Qt::DisplayRole);
            if(Qt::Checked == IndexData)
            {
                Ptr_S_OpCycleInfos_Temp_User->AutoStart = 1;
            }
            else
            {
                Ptr_S_OpCycleInfos_Temp_User->AutoStart = 0;
            }

            Index = StdModel_OpCycle.index(i,3,QModelIndex());
            IndexData = StdModel_OpCycle.data(Index,Qt::DisplayRole);
            if(Qt::Checked == IndexData)
            {
                Ptr_S_OpCycleInfos_Temp_User->AutoStop = 1;
            }
            else
            {
                Ptr_S_OpCycleInfos_Temp_User->AutoStop = 0;
            }
        
            List_OpCycle_Infos_User.append(Ptr_S_OpCycleInfos_Temp_User);
        }
    }
}

//根据用户在 Debounce TabView上的配置信息，反向修改List_XXXX_Infos_User
void MainWindow::Slot_UpdateDebounceInfos(QStandardItem *item)
{
    qDebug("Debounce Data Changed...");

    uint8 i = 0;
    uint8 j = 0;
    bool Result = 0;
    uint8 row = 0;
    uint8 col = 0;
    QComboBox* Ptr_ComboBox;
    S_Debounce_Infos_User_Type* Ptr_S_DebounceInfos_Temp_User;
    QModelIndex Index;
    QVariant IndexData;

    if((l_DebounceTable_UpdateReason == TABLE_UPDATE_BY_USER) && \
       (false != l_DebounceTableUpdate_Finished))
    {
        return;
    }

    row = StdModel_Debounce.rowCount();
    col = StdModel_Debounce.columnCount();

    //Print_TableView();
    //获取界面上用户配置的信息
    if(row != 0)
    {
        //删除原来的配置信息
        List_Debounce_Infos_User.clear();
        //重新获取界面的配置信息，
        for(i = 0; i < row; i++)
        {
            Ptr_S_DebounceInfos_Temp_User = new S_Debounce_Infos_User_Type;

            Ptr_S_DebounceInfos_Temp_User->FailedThershold = StdModel_Debounce.item(i,0)->text().toInt(&Result, 10);
            Ptr_S_DebounceInfos_Temp_User->PassedThershold = StdModel_Debounce.item(i,1)->text().toInt(&Result, 10);
            Ptr_S_DebounceInfos_Temp_User->FailedTimeThershold = StdModel_Debounce.item(i,2)->text().toInt(&Result, 10);
            Ptr_S_DebounceInfos_Temp_User->PassedTimeThershold = StdModel_Debounce.item(i,3)->text().toInt(&Result, 10);
            Ptr_S_DebounceInfos_Temp_User->DecStepSize = StdModel_Debounce.item(i,4)->text().toInt(&Result, 10);
            Ptr_S_DebounceInfos_Temp_User->IncStepSize = StdModel_Debounce.item(i,5)->text().toInt(&Result, 10);
            Ptr_S_DebounceInfos_Temp_User->JumpUpValue = StdModel_Debounce.item(i,6)->text().toInt(&Result, 10);
            Ptr_S_DebounceInfos_Temp_User->JumpDownValue = StdModel_Debounce.item(i,7)->text().toInt(&Result, 10);

            //Index = StdModel_Debounce.index(i,9,QModelIndex());
            IndexData = StdModel_Debounce.item(i, 9)->data(Qt::DisplayRole);
            if(Qt::Checked == IndexData)
            {
                Ptr_S_DebounceInfos_Temp_User->JumpUp = 1;
            }
            else
            {
                Ptr_S_DebounceInfos_Temp_User->JumpUp = 0;
            }

            //Index = StdModel_OpCycle.index(i,10,QModelIndex());
            IndexData = StdModel_Debounce.item(i, 10)->data(Qt::DisplayRole);
            if(Qt::Checked == IndexData)
            {
                Ptr_S_DebounceInfos_Temp_User->JumpDown = 1;
            }
            else
            {
                Ptr_S_DebounceInfos_Temp_User->JumpDown = 0;
            }

            //根据ComboBox的值设置AlgoClass的值
            Ptr_ComboBox = (QComboBox*)Ptr_TableView_Debounce->indexWidget(StdModel_Debounce.index(i, 8));
            uint8 index = Ptr_ComboBox->currentIndex();
            Ptr_S_DebounceInfos_Temp_User->AlgoClass = index;

            //根据ComboBox的值设置behavior的值
            Ptr_ComboBox = (QComboBox*)Ptr_TableView_Debounce->indexWidget(StdModel_Debounce.index(i, 11));
            Ptr_S_DebounceInfos_Temp_User->behavior = Ptr_ComboBox->currentIndex();

            List_Debounce_Infos_User.append(Ptr_S_DebounceInfos_Temp_User);
        }
    }
}

//根据用户在 DTC TabView上的配置信息，反向修改List_XXXX_Infos_User
void MainWindow::Slot_UpdateDTCInfos(QStandardItem *item)
{
    qDebug("DTC Data Changed...");

    uint8 i = 0;
    uint8 j = 0;
    bool Result = 0;
    uint8 row = 0;
    uint8 col = 0;
    QComboBox* Ptr_ComboBox;
    S_DTC_Infos_User_Type* Ptr_S_DTCInfos_Temp_User;
    S_NVM_Infos_User_Type* DTC_NVM_UserType_Temp;
    QVariant IndexData;

    if((l_DTCTable_UpdateReason == TABLE_UPDATE_BY_USER) && \
       (false != l_DTCTableUpdate_Finished))
    {
        return;
    }

    row = StdModel_DTC.rowCount();
    col = StdModel_DTC.columnCount();

    //Print_TableView();
    //获取界面上用户配置的信息
    if(row != 0)
    {
        //删除原来的配置信息
        List_DTC_Infos_User.clear();
        List_DTC_NVM_Infos_User.clear();

        //重新获取界面的配置信息，
        for(i = 0; i < row; i++)
        {
            Ptr_S_DTCInfos_Temp_User = new S_DTC_Infos_User_Type;
            DTC_NVM_UserType_Temp = new S_NVM_Infos_User_Type;

            Ptr_S_DTCInfos_Temp_User->Value = StdModel_DTC.item(i,0)->text().toInt(&Result, 16);
            Ptr_S_DTCInfos_Temp_User->AttrbsRef = StdModel_DTC.item(i,1)->text().toInt(&Result, 10);
            Ptr_S_DTCInfos_Temp_User->AgingThershold = StdModel_DTC.item(i,2)->text().toInt(&Result, 10);
            Ptr_S_DTCInfos_Temp_User->AgingOpCycleRef = StdModel_DTC.item(i,3)->text().toInt(&Result, 10);

            //Ptr_S_DTCInfos_Temp_User->DemCallbackInitMForE = StdModel_DTC.item(i,6)->text();
            Ptr_S_DTCInfos_Temp_User->DemCallbackInitMForE = QString("((void *) 0)");
            Ptr_S_DTCInfos_Temp_User->Id = StdModel_DTC.item(i,7)->text().toInt(&Result, 10);

            Ptr_S_DTCInfos_Temp_User->FailureCycleCounterThershold = StdModel_DTC.item(i,9)->text().toInt(&Result, 10);
            Ptr_S_DTCInfos_Temp_User->DebounceTableRef = StdModel_DTC.item(i,10)->text().toInt(&Result, 10);
            Ptr_S_DTCInfos_Temp_User->OpCycleRef = StdModel_DTC.item(i,11)->text().toInt(&Result, 10);
            Ptr_S_DTCInfos_Temp_User->DTCTableRef = StdModel_DTC.item(i,12)->text().toInt(&Result, 10);
            Ptr_S_DTCInfos_Temp_User->EnableConditionRef = StdModel_DTC.item(i,13)->text().toInt(&Result, 10);
            Ptr_S_DTCInfos_Temp_User->StorageConditionRef = StdModel_DTC.item(i,14)->text().toInt(&Result, 10);

            IndexData = StdModel_DTC.item(i, 4)->data(Qt::DisplayRole);
            if(Qt::Checked == IndexData)
            {
                Ptr_S_DTCInfos_Temp_User->ImmediateNvStorageAllowed = 1;
            }
            else
            {
                Ptr_S_DTCInfos_Temp_User->ImmediateNvStorageAllowed = 0;
            }
            
            IndexData = StdModel_DTC.item(i, 5)->data(Qt::DisplayRole);
            if(Qt::Checked == IndexData)
            {
                Ptr_S_DTCInfos_Temp_User->AgingAllowed = 1;
            }
            else
            {
                Ptr_S_DTCInfos_Temp_User->AgingAllowed = 0;
            }

            IndexData = StdModel_DTC.item(i, 15)->data(Qt::DisplayRole);
            if(Qt::Checked == IndexData)
            {
                Ptr_S_DTCInfos_Temp_User->AvailableStatus = 1;
            }
            else
            {
                Ptr_S_DTCInfos_Temp_User->AvailableStatus = 0;
            }

            //根据ComboBox的值设置EventKind的值
            Ptr_ComboBox = (QComboBox*)Ptr_TableView_DTC->indexWidget(StdModel_DTC.index(i, 8));
            Ptr_S_DTCInfos_Temp_User->EventKind = Ptr_ComboBox->currentIndex();

            List_DTC_Infos_User.append(Ptr_S_DTCInfos_Temp_User);

            // 同时增加DTC对应的NVM配置
            //前3个为固定的NVM配置项
            if(i >= 3)
            {
                uint16 fl_DTC_No = i - 3;

                *DTC_NVM_UserType_Temp = S_NVM_Infos_Init_Value;
                //在初始值的基础上修改部分信息
                DTC_NVM_UserType_Temp->Str_BlockName = QString("DemCfg_NvMBlockDescriptor_DemPrimary_%1").arg(QString::number(fl_DTC_No),3,QChar('0'));
                DTC_NVM_UserType_Temp->Str_RamBlockDataAddress = QString("Dem_PrimaryEntry_%1").arg(QString::number(fl_DTC_No),3,QChar('0'));
                DTC_NVM_UserType_Temp->Str_NvBlockLength = "sizeof(Dem_Cfg_PrimaryMemEntryType)";
                DTC_NVM_UserType_Temp->Str_RomBlockDataAddress = "Dem_MemoryEntryInit";
                DTC_NVM_UserType_Temp->Str_JobFinishedFunction = "Dem_NvM_JobFinished";

                List_DTC_NVM_Infos_User.append(DTC_NVM_UserType_Temp);
            }
            else
            {
                *DTC_NVM_UserType_Temp = S_DTC_NVM_Infos_User_Default[i];
                List_DTC_NVM_Infos_User.insert(i,DTC_NVM_UserType_Temp);
            }
        }
        //重新刷新一下 List_NVM_Infos_User
        PM_NVMTable_AddDTC();
    }
}

//根据用户在 DTC TabView上的配置信息，反向修改List_XXXX_Infos_User
void MainWindow::Slot_UpdateNVMInfos(QStandardItem *item)
{
    qDebug("NVM Data Changed...");

    uint8 i = 0;
    uint8 j = 0;
    bool Result = 0;
    uint8 row = 0;
    uint8 col = 0;
    QComboBox* Ptr_ComboBox;
    S_NVM_Infos_User_Type* Ptr_S_NVMInfos_Temp_User;
    QVariant IndexData;

    if((l_NVMTable_UpdateReason == TABLE_UPDATE_BY_USER) && \
       (false != l_NVMTableUpdate_Finished))
    {
        return;
    }

    row = StdModel_NVM.rowCount();
    col = StdModel_NVM.columnCount();

    //Print_TableView();
    //获取界面上用户配置的信息
    if(row != 0)
    {
        //删除原来的配置信息
        List_NVM_Infos_User.clear();
        //重新获取界面的配置信息，
        for(i = 0; i < row; i++)
        {
            Ptr_S_NVMInfos_Temp_User = new S_NVM_Infos_User_Type;

            Ptr_S_NVMInfos_Temp_User->Str_InitFun = StdModel_NVM.item(i,0)->text();
            Ptr_S_NVMInfos_Temp_User->Str_BlockName = StdModel_NVM.item(i,1)->text();

            Ptr_S_NVMInfos_Temp_User->NvBlockBaseNumber = StdModel_NVM.item(i,2)->text().toInt(&Result, 10);
            Ptr_S_NVMInfos_Temp_User->Str_NvBlockLength = StdModel_NVM.item(i,3)->text();

            Ptr_S_NVMInfos_Temp_User->Str_RamBlockDataAddress = StdModel_NVM.item(i,4)->text();
            Ptr_S_NVMInfos_Temp_User->Str_RomBlockDataAddress = StdModel_NVM.item(i,5)->text();
            Ptr_S_NVMInfos_Temp_User->Str_RomBlockDefaultData = StdModel_NVM.item(i,6)->text();
            Ptr_S_NVMInfos_Temp_User->Str_JobFinishedFunction = StdModel_NVM.item(i,7)->text();

            Ptr_S_NVMInfos_Temp_User->BlockJobPriority = StdModel_NVM.item(i,8)->text().toInt(&Result, 10);
            Ptr_S_NVMInfos_Temp_User->MaxNumReadRetries = StdModel_NVM.item(i,9)->text().toInt(&Result, 10);
            Ptr_S_NVMInfos_Temp_User->MaxNumWriteRetries = StdModel_NVM.item(i,10)->text().toInt(&Result, 10);
            //Ptr_S_NVMInfos_Temp_User->NvRamDeviceId = StdModel_NVM.item(i,10)->text().toInt(&Result, 10);
            Ptr_S_NVMInfos_Temp_User->BlockCrcType = StdModel_NVM.item(i,12)->text().toInt(&Result, 10);
            Ptr_S_NVMInfos_Temp_User->BlockManagementType = StdModel_NVM.item(i,13)->text().toInt(&Result, 10);
            //Ptr_S_NVMInfos_Temp_User->SelectBlockForReadAll = StdModel_NVM.item(i,13)->text().toInt(&Result, 10);
            //Ptr_S_NVMInfos_Temp_User->SelectBlockForWriteAll = StdModel_NVM.item(i,14)->text().toInt(&Result, 10);
    
            IndexData = StdModel_NVM.item(i, 14)->data(Qt::DisplayRole);
            if(Qt::Checked == IndexData)
            {
                Ptr_S_NVMInfos_Temp_User->SelectBlockForReadAll = 1;
            }
            else
            {
                Ptr_S_NVMInfos_Temp_User->SelectBlockForReadAll = 0;
            }
    
            IndexData = StdModel_NVM.item(i, 15)->data(Qt::DisplayRole);
            if(Qt::Checked == IndexData)
            {
                Ptr_S_NVMInfos_Temp_User->SelectBlockForWriteAll = 1;
            }
            else
            {
                Ptr_S_NVMInfos_Temp_User->SelectBlockForWriteAll = 0;
            }

            //根据ComboBox的值设置DeviceKind的值
            Ptr_ComboBox = (QComboBox*)Ptr_TableView_NVM->indexWidget(StdModel_NVM.index(i, 11));
            Ptr_S_NVMInfos_Temp_User->NvRamDeviceId = Ptr_ComboBox->currentIndex();

            //其他不需要配置的项，设置为默认值
            Ptr_S_NVMInfos_Temp_User->NvBlockNum = 0;
            Ptr_S_NVMInfos_Temp_User->RomBlockNum = 0;
            Ptr_S_NVMInfos_Temp_User->NvRamBlockIdentifier = 0;
            Ptr_S_NVMInfos_Temp_User->BlockUseCrc = 0;
            Ptr_S_NVMInfos_Temp_User->BlockUseSetRamBlockStatus = 0;
            Ptr_S_NVMInfos_Temp_User->BlockWriteProt = 0;
            Ptr_S_NVMInfos_Temp_User->BswMBlockStatusInformation = 0;
            Ptr_S_NVMInfos_Temp_User->CalcRamBlockCrc = 0;
            Ptr_S_NVMInfos_Temp_User->WriteBlockOnce = 0;

            List_NVM_Infos_User.append(Ptr_S_NVMInfos_Temp_User);
        }
    }
}

//根据用户在 FEE TabView上的配置信息，反向修改List_XXXX_Infos_User
void MainWindow::Slot_UpdateFEEInfos(QStandardItem *item)
{
    qDebug("Rid Data Changed...");

    uint8 i = 0;
    uint8 row = 0;
    S_FEE_Infos_User_Type* Ptr_FEE_Temp;

    row = StdModel_FEE.rowCount();

    //获取界面上用户配置的信息
    if(row != 0)
    {
        //删除原来的配置信息
        List_FEE_Infos_User.clear();
        //重新获取界面的配置信息，
        for(i = 0; i < row; i++)
        {
            Ptr_FEE_Temp = new S_FEE_Infos_User_Type;
            Ptr_FEE_Temp->Item = StdModel_FEE.item(i, 0)->text();
            Ptr_FEE_Temp->Value = StdModel_FEE.item(i, 1)->text();
            List_FEE_Infos_User.append(Ptr_FEE_Temp);
        }
    }
}

//点击Generate后
void MainWindow::Slot_Generate(bool checked)
{
    qDebug("------Start: Generate ConfigFile Started");
    FG_Process();
    qDebug("------End: Generate ConfigFile Started");
}

void MainWindow::Print_Info_User(void)
{
    qDebug("------Start: Print User Config------");
    for(uint8 i = 0; i < List_DID_Infos_User.count(); i++)
    {
        qDebug() << QString::number(List_DID_Infos_User.at(i)->Did, 16) \
                 << List_DID_Infos_User.at(i)->DataLen \
                 << List_DID_Infos_User.at(i)->Operation \
                 << List_DID_Infos_User.at(i)->IsOnlyEol;
    }
    qDebug("------End: Print User Config------");
}

//打印用户配置的表格信息
void MainWindow::Print_TableView(void)
{
    uint8 i = 0;
    uint8 j = 0;
    bool Result = 0;
    uint8 row = StdModel_Did.rowCount();
    uint8 col = StdModel_Did.columnCount();

    qDebug() << "------Start: Print Table: Did------" << row << col;
    for(i = 0; i < row; i++)
    {
        qDebug() << StdModel_Did.item(i,0)->text().toUInt(&Result, 16) \
                 << StdModel_Did.item(i,1)->checkState() \
                 << StdModel_Did.item(i,2)->checkState() \
                 << StdModel_Did.item(i,3)->text().toUInt(&Result, 10) \
                 << StdModel_Did.item(i,4)->checkState() \
                 << StdModel_Did.item(i,5)->checkState();
    }
    qDebug() << "------End: Print Table: Did------";
}

//打印需生成的配置信息
void MainWindow::Print_Did_Infos(void)
{
    uint8 i = 0;
    uint8 j = 0;
    qDebug() << "------Start: Print Did Infos: ";

    qDebug() << "Did Table:";
    for(i = 0 ; i < List_Did.count(); i++)
    {
        qDebug() << QString::number(List_Did.at(i), 16);
    }

    qDebug() << "DidInfo Table:";
    qDebug() << "Length" << "OpInfoRef" << "Operations";
    for(i = 0; i < List_DidInfo.count(); i++)
    {
        qDebug() << List_DidInfo.at(i).Length \
                 << List_DidInfo.at(i).OpInfoRef \
                 << List_DidInfo.at(i).Operations;
    }

    qDebug() << "DidOpInfo Table:";
    qDebug() << "State_Ref" << "SignalInfo_Ref" << "CallTypes";
    for(i = 0; i < List_DidOpInfo.count(); i++)
    {
        qDebug() << List_DidOpInfo.at(i).State_Ref \
                 << List_DidOpInfo.at(i).SignalInfo_Ref \
                 << List_DidOpInfo.at(i).CallTypes;
    }
    qDebug() << "------End: Print Did Infos: ";
}

void MainWindow::ResizeLayout(QTableView* Ptr_Table)
{
    //qDebug() << "Central Layout: " << ui->centralwidget->layout()->objectName();
    ui->HLayout_Table->removeWidget((QWidget*)ui->HLayout_Table->itemAt(1));
    ui->HLayout_Table->addWidget(Ptr_Table);

    //布局中删掉所有窗口
//    ui->centralwidget->layout()->removeWidget(ui->TableView_Did);
//    ui->centralwidget->layout()->removeWidget(Ptr_TableView_DcmGeneral);
//    ui->centralwidget->layout()->removeWidget(Ptr_TableView_Rid);
//    ui->centralwidget->layout()->removeWidget(Ptr_TableView_OpCycle);
//    ui->centralwidget->layout()->removeWidget(Ptr_TableView_Debounce);
//    ui->centralwidget->layout()->removeWidget(Ptr_TableView_DTC);
//    ui->centralwidget->layout()->removeWidget(Ptr_TableView_NVM);
//    ui->centralwidget->layout()->removeWidget(Ptr_TableView_FEE);

//    //增加指定窗口
//    ui->Tree_Config->layout()->addWidget(Ptr_Table);
//    //设置顶部对齐
//    ui->centralwidget->layout()->setAlignment(Ptr_Table, Qt::AlignTop);
}

