/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DiagGenerateTool/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[23];
    char stringdata0[351];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 15), // "Slot_OpenConfig"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 7), // "checked"
QT_MOC_LITERAL(4, 36, 21), // "Slot_TreeView_Clicled"
QT_MOC_LITERAL(5, 58, 11), // "QModelIndex"
QT_MOC_LITERAL(6, 70, 5), // "index"
QT_MOC_LITERAL(7, 76, 40), // "Slot_DidTable_customContextMe..."
QT_MOC_LITERAL(8, 117, 3), // "pos"
QT_MOC_LITERAL(9, 121, 40), // "Slot_RidTable_customContextMe..."
QT_MOC_LITERAL(10, 162, 11), // "Slot_AddDID"
QT_MOC_LITERAL(11, 174, 11), // "Slot_DelDID"
QT_MOC_LITERAL(12, 186, 11), // "Slot_AddRID"
QT_MOC_LITERAL(13, 198, 11), // "Slot_DelRID"
QT_MOC_LITERAL(14, 210, 13), // "Slot_Generate"
QT_MOC_LITERAL(15, 224, 19), // "Slot_UpdateDidInfos"
QT_MOC_LITERAL(16, 244, 14), // "QStandardItem*"
QT_MOC_LITERAL(17, 259, 4), // "item"
QT_MOC_LITERAL(18, 264, 19), // "Slot_UpdateRidInfos"
QT_MOC_LITERAL(19, 284, 26), // "Slot_UpdateDcmGeneralInfos"
QT_MOC_LITERAL(20, 311, 23), // "Slot_FileMenu_Triggered"
QT_MOC_LITERAL(21, 335, 8), // "QAction*"
QT_MOC_LITERAL(22, 344, 6) // "Action"

    },
    "MainWindow\0Slot_OpenConfig\0\0checked\0"
    "Slot_TreeView_Clicled\0QModelIndex\0"
    "index\0Slot_DidTable_customContextMenuRequested\0"
    "pos\0Slot_RidTable_customContextMenuRequested\0"
    "Slot_AddDID\0Slot_DelDID\0Slot_AddRID\0"
    "Slot_DelRID\0Slot_Generate\0Slot_UpdateDidInfos\0"
    "QStandardItem*\0item\0Slot_UpdateRidInfos\0"
    "Slot_UpdateDcmGeneralInfos\0"
    "Slot_FileMenu_Triggered\0QAction*\0"
    "Action"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x0a /* Public */,
       4,    1,   82,    2, 0x0a /* Public */,
       7,    1,   85,    2, 0x0a /* Public */,
       9,    1,   88,    2, 0x0a /* Public */,
      10,    1,   91,    2, 0x0a /* Public */,
      11,    1,   94,    2, 0x0a /* Public */,
      12,    1,   97,    2, 0x0a /* Public */,
      13,    1,  100,    2, 0x0a /* Public */,
      14,    1,  103,    2, 0x0a /* Public */,
      15,    1,  106,    2, 0x0a /* Public */,
      18,    1,  109,    2, 0x0a /* Public */,
      19,    1,  112,    2, 0x0a /* Public */,
      20,    1,  115,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::QPoint,    8,
    QMetaType::Void, QMetaType::QPoint,    8,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void, 0x80000000 | 21,   22,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Slot_OpenConfig((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->Slot_TreeView_Clicled((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 2: _t->Slot_DidTable_customContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 3: _t->Slot_RidTable_customContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 4: _t->Slot_AddDID((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->Slot_DelDID((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->Slot_AddRID((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->Slot_DelRID((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->Slot_Generate((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->Slot_UpdateDidInfos((*reinterpret_cast< QStandardItem*(*)>(_a[1]))); break;
        case 10: _t->Slot_UpdateRidInfos((*reinterpret_cast< QStandardItem*(*)>(_a[1]))); break;
        case 11: _t->Slot_UpdateDcmGeneralInfos((*reinterpret_cast< QStandardItem*(*)>(_a[1]))); break;
        case 12: _t->Slot_FileMenu_Triggered((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
