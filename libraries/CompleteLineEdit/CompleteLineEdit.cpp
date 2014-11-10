#include "CompleteLineEdit.h"
#include <QKeyEvent>
#include <QListView>
#include <QStringListModel>
#include <QDebug>
#include <QMap>
#include "DataStruct.h"

CompleteLineEdit::CompleteLineEdit(QWidget *parent)
    : QLineEdit(parent)
{
    initData();
}

void CompleteLineEdit::setCompleteList(const QStringList &listComplete)
{
    this->listComplete_ = listComplete;
}

void CompleteLineEdit::initData()
{
    pListView_ = new QListView(this);
	pListView_->setIconSize(QSize(40, 40));
//	pListView_->sets
    connect(pListView_, SIGNAL(clicked(const QModelIndex &)), this, SLOT(slotCompleteText(const QModelIndex &)));
    pListView_->setWindowFlags(Qt::ToolTip);	//用Popup的时候会阻塞
    pStandardItemModel_ = new QStandardItemModel(this);
    connect(this, SIGNAL(textChanged(const QString &)), this, SLOT(slotCompleterInputText(const QString &)));
}

void CompleteLineEdit::keyPressEvent(QKeyEvent *e)
{
    //
    if (!pListView_->isHidden())
    {
        int count = pListView_->model()->rowCount();	//一共有多少项
        //qDebug() << trUtf8("一共有") << count;
        QModelIndex currentIndex = pListView_->currentIndex();

        switch(e->key())
        {
            case Qt::Key_Down:
            {// 按向下方向键时，移动光标选中 下一个 完成列表中的项
                ////qDebug()<<QString::fromUtf8("按下方向键下");
                int row = currentIndex.row() + 1;
                if (row >= count)
                {
                    row = 0;
                }
                QModelIndex index = pListView_->model()->index(row, 0);
                pListView_->setCurrentIndex(index);
                break;
            }
            case Qt::Key_Up:
            {// 按向下方向键时，移动光标选中 上一个 完成列表中的项
                ////qDebug()<<QString::fromUtf8("按下方向键上");
                int row = currentIndex.row() - 1;
                if (row < 0)
                {
                    row = count - 1;
                }
                QModelIndex index = pListView_->model()->index(row, 0);
                pListView_->setCurrentIndex(index);
                break;
            }
            case Qt::Key_Escape:
            {// 按下Esc键时，隐藏完成列表
                pListView_->hide();
                emit signalEsc();
                break;
            }
            case Qt::Key_Return:
            {// 按下回车键时，使用完成列表中选中的项，并隐藏完成列表
                if (currentIndex.isValid())
                {
                    QString name = pListView_->currentIndex().data().toString();
                    setText(name);
                    emit signalSelectItem(name);
                }
                pListView_->hide();
                //qDebug()<<QString::fromUtf8("在这里调出流云的对话框~~");
                break;
            }
            default:
            {// 其他情况，隐藏完成列表，并使用QLineEdit的键盘按下事件
                pListView_->hide();
                QLineEdit::keyPressEvent(e);
                break;
            }
        }//end of switch
    }
    else
    {//嗯把其他的东西扔给基类总是明知的选择
        QLineEdit::keyPressEvent(e);
    }
}
void CompleteLineEdit::slotCompleterInputText(const QString &inputText)
{
    if (inputText.isEmpty())
    {
        pListView_->hide();
        return;
    }
    if ((inputText.length() > 1) && (!pListView_->isHidden()))
    {
        return;
    }

    // 如果完整的完成列表中的某个单词包含输入的文本，则加入要显示的完成列表串中
    QStringList sl;

    QMap<QString, QString>::iterator iter = map_moduleName_moduleTag_.begin();
    for(; iter != map_moduleName_moduleTag_.end(); ++iter)
    {
		QString moduleName = iter.key();
        QString moduleTag = iter.value();
		if(moduleName.contains(inputText, Qt::CaseInsensitive))
        {
            sl << moduleName;
        }
		else if(moduleTag.contains(inputText, Qt::CaseInsensitive))
        {
            sl << moduleName;
        }
    }

    pStandardItemModel_->clear();

    foreach (QString word, sl)
    {
        QStandardItem *item = new QStandardItem(word);
		//item->setSizeHint(QSize(20, 200));
        pStandardItemModel_->appendRow(item);
    }

    pListView_->setModel(pStandardItemModel_);

    if (0 == pStandardItemModel_->rowCount())
    {
        return;
    }

    // 完成列表的定位
    pListView_->setMinimumWidth(width());
    pListView_->setMaximumWidth(width());

    QPoint p(0, height());
    int x = mapToGlobal(p).x();
    int y = mapToGlobal(p).y() + 1;

    pListView_->move(x, y);
    pListView_->show();
	this->setFocus();
}

void CompleteLineEdit::slotCompleteText(const QModelIndex &index)
{
    QString name = index.data().toString();
    setText(name);

    emit signalSelectItem(name);

//    pListView_->hide();
	this->hide();
}

void CompleteLineEdit::hide()
{
    QLineEdit::hide();
    if(!pListView_->isHidden())
	{
        pListView_->hide();
    }
	pListView_->clearFocus();
	this->clearFocus();
}

void CompleteLineEdit::addModulesData(const QMap<QString, QString> &data)
{
	map_moduleName_moduleTag_ = data;
}

void CompleteLineEdit::show()
{
	qDebug() << "设置焦点";
	QLineEdit::show();
	if (text().isEmpty())
	{
		pListView_->hide();
	}
	this->setFocus();
}


