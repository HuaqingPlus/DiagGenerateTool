/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QPushButton *But_Generate;
    QHBoxLayout *HLayout_Table;
    QTreeView *Tree_Config;
    QTableView *TableView_Did;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1076, 548);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        But_Generate = new QPushButton(centralwidget);
        But_Generate->setObjectName(QString::fromUtf8("But_Generate"));
        But_Generate->setEnabled(true);
        But_Generate->setMinimumSize(QSize(80, 30));

        gridLayout_2->addWidget(But_Generate, 0, 0, 1, 1, Qt::AlignLeft);

        HLayout_Table = new QHBoxLayout();
        HLayout_Table->setObjectName(QString::fromUtf8("HLayout_Table"));
        HLayout_Table->setSizeConstraint(QLayout::SetDefaultConstraint);
        Tree_Config = new QTreeView(centralwidget);
        Tree_Config->setObjectName(QString::fromUtf8("Tree_Config"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Tree_Config->sizePolicy().hasHeightForWidth());
        Tree_Config->setSizePolicy(sizePolicy1);
        Tree_Config->setMinimumSize(QSize(250, 450));

        HLayout_Table->addWidget(Tree_Config, 0, Qt::AlignTop);

        TableView_Did = new QTableView(centralwidget);
        TableView_Did->setObjectName(QString::fromUtf8("TableView_Did"));
        TableView_Did->setEnabled(true);
        TableView_Did->setMinimumSize(QSize(800, 450));
        TableView_Did->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        TableView_Did->setSortingEnabled(false);

        HLayout_Table->addWidget(TableView_Did, 0, Qt::AlignTop);


        gridLayout_2->addLayout(HLayout_Table, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setEnabled(true);
        menubar->setGeometry(QRect(0, 0, 1076, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QString());
        But_Generate->setText(QApplication::translate("MainWindow", "Generate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
