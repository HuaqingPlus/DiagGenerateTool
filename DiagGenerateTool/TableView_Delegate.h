#ifndef TABLEVIEW_DELEGATE_H
#define TABLEVIEW_DELEGATE_H

#include "mainwindow.h"
#include <QItemDelegate>
#include <QStyledItemDelegate>
#include <QMouseEvent>

//ComboBox 代理类,
class ComboBox_Delegate: public QItemDelegate
{
    Q_OBJECT
public:
    //构造函数
   ComboBox_Delegate(QObject *parent = 0);


   void setItems(const QStringList &texts);

public:

    //重写函数
    QWidget *createEditor(QWidget *parent,
                          const QStyleOptionViewItem &option,
                          const QModelIndex &index) const;

    void setEditorData(QWidget *editor, const QModelIndex &index) const;

    void setModelData(QWidget *editor,
                      QAbstractItemModel *model,
                      const QModelIndex &index)const;

    void updateEditorGeometry(QWidget *editor,
                               const QStyleOptionViewItem &option,
                               const QModelIndex &index) const;
    //重写函数
    void setCurrentIndex(QWidget *editor, int index) const;

private:
    QStringList _texts;

};


//CheckBox 代理类
class CheckBoxDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    CheckBoxDelegate(QObject *parent = 0);

    void setColumn(int col);

protected:
    void paint(QPainter* painter,const QStyleOptionViewItem& option,const QModelIndex& index) const;
    bool editorEvent(QEvent *event,QAbstractItemModel *model,const QStyleOptionViewItem &option,const QModelIndex &index);

private:
    int column;         //设置复选框的列
};

#endif // TABLEVIEW_DELEGATE_H
