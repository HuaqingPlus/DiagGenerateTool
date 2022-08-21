#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "TableView_Delegate.h"

/****************************************************
 * ComboBox_Delegate
 ****************************************************/
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

    //qDebug() << "Internal:" << index.row() << index.column() << text << tindex;
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


/****************************************************
 * CheckBoxDelegate
 ****************************************************/
static QRect CheckBoxRect(const QStyleOptionViewItem &viewItemStyleOptions)/*const*/
{
    //绘制按钮所需要的参数
    QStyleOptionButton checkBoxStyleOption;
    //按照给定的风格参数 返回元素子区域
    QRect checkBoxRect = QApplication::style()->subElementRect( QStyle::SE_CheckBoxIndicator, &checkBoxStyleOption);
    //返回QCheckBox坐标
    QPoint checkBoxPoint(viewItemStyleOptions.rect.x() + viewItemStyleOptions.rect.width() / 2 - checkBoxRect.width() / 2,
                         viewItemStyleOptions.rect.y() + viewItemStyleOptions.rect.height() / 2 - checkBoxRect.height() / 2);
    //返回QCheckBox几何形状
    return QRect(checkBoxPoint, checkBoxRect.size());
}

CheckBoxDelegate::CheckBoxDelegate(QObject *parent):
    QStyledItemDelegate(parent)
{

}

void CheckBoxDelegate::setColumn(int col)
{
    qDebug() << "SetColumn: " << col;
    column = col;
}

// 绘制CheckBox
void CheckBoxDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option,const QModelIndex& index)const
{
    bool checked = index.model()->data(index, Qt::DisplayRole).toBool();

    //qDebug() << "ChekcBox Delegate: Paint " << column << checked << index.model()->data(index, Qt::DisplayRole);
    if(index.column() == column)
    {
        QStyleOptionButton checkBoxStyleOption;
        checkBoxStyleOption.state |= QStyle::State_Enabled;
        checkBoxStyleOption.state |= checked? QStyle::State_On : QStyle::State_Off;
        checkBoxStyleOption.rect = CheckBoxRect(option);

        QApplication::style()->drawControl(QStyle::CE_CheckBox,&checkBoxStyleOption,painter);
    }
    else
    {
        QStyledItemDelegate::paint(painter, option, index);
    }
}

// 响应鼠标事件，更新数据
bool CheckBoxDelegate::editorEvent(QEvent *event,
                                QAbstractItemModel *model,
                                const QStyleOptionViewItem &option,
                                const QModelIndex &index)
{
    if(index.column() == column)
    {
        if((event->type() == QEvent::MouseButtonRelease) ||
           (event->type() == QEvent::MouseButtonDblClick))
        {
            QMouseEvent *mouseEvent = (QMouseEvent*)(event);

            if((mouseEvent->button() != Qt::LeftButton) ||
               (!CheckBoxRect(option).contains(mouseEvent->pos())))
            {
                return true;
            }
            if(event->type() == QEvent::MouseButtonDblClick)
            {
                return true;
            }
        }
        else if(event->type() == QEvent::KeyPress)
        {
            if(((QKeyEvent*)(event))->key() != Qt::Key_Space &&
               ((QKeyEvent*)(event))->key() != Qt::Key_Select)
            {
                return false;
            }
        }
        else
        {
            return false;
        }

        bool checked = index.model()->data(index, Qt::DisplayRole).toBool();
        int data = checked ? 0 : 1;     //互逆
        return model->setData(index, data, Qt::EditRole);
    }
    else
    {
        return QStyledItemDelegate::editorEvent(event, model, option, index);
    }
}
