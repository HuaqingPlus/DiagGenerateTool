#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtDebug>
#include <QFileDialog>
#include <QDir>
#include <QAbstractItemModel>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QTextCodec>
#include <QFile>
#include <QDomDocument>
#include <QComboBox>
#include <QAbstractItemModel>
#include <QItemDelegate>
#include <QMessageBox>
#include <QCheckBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

//数据类型定义
typedef uint8_t uint8;
typedef int8_t sint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef short sint16;
typedef bool boolean;

#define FALSE   (0)
#define TRUE    (1)
#define TABLE_UPDATE_BY_OTHER   ((uint8)0)
#define TABLE_UPDATE_BY_USER    ((uint8)1)


typedef struct
{
    uint16 Did;
    uint8 Operation;
    uint8 IsOnlyEol;
    uint16 DataLen;
}S_DID_Infos_User_Type;

//RID
typedef struct
{
    uint16 Rid;
    uint8 Operation;
    uint8 RoutineControlOptionRecord;
    uint8 RoutineType;
}S_RID_Infos_User_Type;

typedef struct
{
    QString Item;
    QString Value;
    QString Comment;
}S_DcmGeneral_Infos_User_Type;

typedef struct
{
    uint8 Id;
    uint8 Type;
    uint8 AutoStart;
    uint8 AutoStop;
}S_OpCycle_Infos_User_Type;

typedef struct
{
    sint16 FailedThershold;
    sint16 PassedThershold;
    sint16 FailedTimeThershold;
    sint16 PassedTimeThershold;
    sint8 DecStepSize;
    sint8 IncStepSize;
    sint8 JumpUpValue;
    sint8 JumpDownValue;
    uint8 AlgoClass;
    uint8 JumpUp;
    uint8 JumpDown;
    uint8 behavior;
}S_Debounce_Infos_User_Type;

typedef struct
{
    //Dem_Cfg_DTCType
    uint32 Value;
    uint8 AttrbsRef;

    //Dem_Cfg_DTCAttributesType
    uint8 AgingThershold;
    uint8 AgingOpCycleRef;
    uint8 ImmediateNvStorageAllowed;
    uint8 AgingAllowed;

    //Dem_Cfg_EventParameterType
    QString  DemCallbackInitMForE; /* 用QString 表示函数名 */
    uint16 Id;
    uint8 EventKind;
    uint8 FailureCycleCounterThershold;
    uint8 DebounceTableRef;
    uint8 OpCycleRef;
    uint8 DTCTableRef;
    uint8 EnableConditionRef;
    uint8 StorageConditionRef;
    uint8 AvailableStatus;
}S_DTC_Infos_User_Type;

typedef struct
{
    QString   Str_InitFun;
    QString   Str_BlockName;
    uint16    NvBlockBaseNumber;
    uint16    NvBlockLength;
    QString   Str_RamBlockDataAddress;
    QString   Str_RomBlockDataAddress;
    QString   Str_RomBlockDefaultData;
    QString   Str_JobFinishedFunction;
    uint8     BlockJobPriority;
    uint8     MaxNumReadRetries;
    uint8     MaxNumWriteRetries;
    uint8     NvRamDeviceId;
    uint8     BlockCrcType;
    uint8     BlockManagementType;
    uint8     SelectBlockForReadAll;
    uint8     SelectBlockForWriteAll;
    uint8     NvBlockNum;
    uint8     RomBlockNum;
    uint16    NvRamBlockIdentifier;
    uint8     BlockUseCrc;
    uint8     BlockUseSetRamBlockStatus;
    uint8     BlockWriteProt;
    uint8     BswMBlockStatusInformation;
    uint8     CalcRamBlockCrc;
    uint8     WriteBlockOnce;
}S_NVM_Infos_User_Type;

typedef struct
{
    QString Item;
    QString Value;
    QString Comment;
}S_FEE_Infos_User_Type;

//class 定义
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void MainWindow_Init(void);

public:
    void TableView_UpdateDid(void);
    void TableView_UpdateRid(void);
    void TableView_UpdateDcmGeneral(void);
    void TableView_UpdateOpCycle(void);
    void TableView_UpdateDebounce(void);
    void TableView_UpdateDTC(void);
    void TableView_UpdateNVM(void);
    void TableView_UpdateFEE(void);
    void Print_Info_User(void);
    void Print_TableView(void);
    void Print_Did_Infos(void);

public slots:
    void Slot_OpenConfig(bool checked);
    void Slot_TreeView_Clicled(QModelIndex index);
    void Slot_DidTable_customContextMenuRequested(const QPoint &pos);
    void Slot_RidTable_customContextMenuRequested(const QPoint &pos);
    void Slot_OpCycleTable_customContextMenuRequested(const QPoint &pos);
    void Slot_DebounceTable_customContextMenuRequested(const QPoint &pos);
    void Slot_DTCTable_customContextMenuRequested(const QPoint &pos);
    void Slot_NVMTable_customContextMenuRequested(const QPoint &pos);
    void Slot_AddDID(bool checked);
    void Slot_DelDID(bool checked);
    void Slot_InsertDID(bool checked);
    void Slot_AddRID(bool checked);
    void Slot_DelRID(bool checked);
    void Slot_InsertRID(bool checked);
    void Slot_AddOpCycle(bool checked);
    void Slot_DelOpCycle(bool checked);
    void Slot_InsertOpCycle(bool checked);
    void Slot_AddDebounce(bool checked);
    void Slot_DelDebounce(bool checked);
    void Slot_InsertDebounce(bool checked);
    void Slot_AddDTC(bool checked);
    void Slot_DelDTC(bool checked);
    void Slot_InsertDTC(bool checked);
    void Slot_AddNVM(bool checked);
    void Slot_DelNVM(bool checked);
    void Slot_InsertNVM(bool checked);
    void Slot_Generate(bool checked);
    void Slot_UpdateDidInfos(QStandardItem *item);
    void Slot_UpdateRidInfos(QStandardItem *item);
    void Slot_UpdateDcmGeneralInfos(QStandardItem *item);
    void Slot_UpdateOpCycleInfos(QStandardItem *item);
    void Slot_UpdateDebounceInfos(QStandardItem *item);
    void Slot_UpdateDTCInfos(QStandardItem *item);
    void Slot_UpdateNVMInfos(QStandardItem *item);
    void Slot_UpdateFEEInfos(QStandardItem *item);
    void Slot_FileMenu_Triggered(QAction* Action);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

