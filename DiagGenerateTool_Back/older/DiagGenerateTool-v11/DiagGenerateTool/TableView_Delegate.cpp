#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "TableView_Delegate.h"


ComboBox_Delegate::ComboBox_Delegate(QObject *parent) :
    QItemDelegate(parent)
{

}

QWidget* ComboBox_Delegate::createEditor(QWidget *parent,
                      const QStyleOptionViewItem &option,
                      const QModelIndex &index) const
{

    QComboBox* editor = new QComboBox(parent);
    editor->addItems(_texts);
    //editor->setCurrentIndex(0);
    return editor;
}

void ComboBox_Delegate::setItems(const QStringList &texts)
{
    _texts = texts;
}

void ComboBox_Delegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QString text = index.model()->data(index, Qt::EditRole).toString();
    QComboBox *comboBox = static_cast<QComboBox*>(editor);
    text = comboBox->currentText();
    int tindex = comboBox->findText(text);
    comboBox->setCurrentIndex(tindex);

    qDebug() << "Internal:" << index.row() << index.column() << text << tindex;
}

void ComboBox_Delegate::setModelData(QWidget *editor,
                  QAbstractItemModel *model,
                  const QModelIndex &index)const
{
    QComboBox *comboBox = static_cast<QComboBox*>(editor);
    QString text = comboBox->currentText();
    model->setData(index, text, Qt::EditRole);
}
void ComboBox_Delegate::updateEditorGeometry(QWidget *editor,const QStyleOptionViewItem &option, const QModelIndex &/*index*/) const
{
    editor->setGeometry(option.rect);
    QComboBox *comboBox = static_cast<QComboBox*>(editor);
}

//重写函数
void ComboBox_Delegate::setCurrentIndex(QWidget *editor, int index) const
{
    QComboBox *comboBox = static_cast<QComboBox*>(editor);
    comboBox->setCurrentIndex(index);
}
