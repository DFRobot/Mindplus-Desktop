#include "IntroduceForm.h"
#include <QFile>
#include <QDir>
#include <QDebug>
#include <QStringList>
#include <QMouseEvent>
#include <QFileInfo>

#include "DataBaseCreateComponent.h"
#include "ListWidgetItemWidget_Component.h"
#include "ListWidgetItem.h"
#include "DataStruct.h"
#include "WidgetMain.h"
#include "EditScene.h"

IntroduceForm::IntroduceForm(const QRect &rect, QHash<QString, DataStruct> *p, const QString &type, QWidget *parent)
    : QWidget(parent)
    , pHash_moduelName_dataStruct_(p)
    , type_(type)
    , pParent_(parent)
    , rect_(rect)
{
    setupUi(this);
    initData();
    initGui();
}

void IntroduceForm::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type())
    {
        case QEvent::LanguageChange:
            retranslateUi(this);
            break;
        default:
            break;
    }
}

void IntroduceForm::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        QWidget *pParent_ = static_cast<QWidget *>(this->parent());
        if(NULL == pParent_)
        {
            return;
        }
        offset_ = event->globalPos() - pParent_->frameGeometry().topLeft();
    }
}

void IntroduceForm::mouseMoveEvent(QMouseEvent *event)
{
    if (!(event->buttons() & Qt::LeftButton))
    {
        return;
    }
    if ((event->pos() - offset_).manhattanLength()
            < QApplication::startDragDistance())
    {
        return;
    }
    pParent_->move(event->globalPos() - offset_);
}

void IntroduceForm::showEvent(QShowEvent *)
{
    this->setGeometry(rect_);
}

void IntroduceForm::initData()
{
    WidgetMain *p = qobject_cast<WidgetMain *>(parentWidget());
    EditScene *pScene =  p->getScenePointer();
	//pScene->setListWidgetIntroducePointer(listWidget);

    QStringList listComponentsName = getComponentsName("./resource/Blocks/");
    connect(listWidget, SIGNAL(signalHideSubWindows()), this, SIGNAL(signalHideSubWindows()));
    connect(listWidget, SIGNAL(signalShowSubWindows()), this, SIGNAL(signalShowSubWindows()));
    //填充ListWidget的数据
    int itemIndex = 0;
    foreach (QString bbName, listComponentsName)
    {
        qDebug() << bbName;

        QString name = pHash_moduelName_dataStruct_->value(bbName).ui.name;
        QString type = pHash_moduelName_dataStruct_->value(bbName).ui.type;

        //根据type来判断是否是自己关心的类型
        if(type_ != type)
        {
            continue;
        }

        QImage image;
        QByteArray imageData = pHash_moduelName_dataStruct_->value(bbName).description.imageData;
        QString description = pHash_moduelName_dataStruct_->value(bbName).description.text;
        image.loadFromData(imageData, "PNG");
        if(imageData.isEmpty())
        {
            qDebug() << "数据库中没有图片数据";
        }

        ListWidgetItemWidget_Component *pItemWidget = new ListWidgetItemWidget_Component(name, listWidget);
        pItemWidget->setEnabledHoverEvent(true);
        pItemWidget->setIntroduceInfor(QPixmap::fromImage(image), description);
        connect(pItemWidget, SIGNAL(signalIntroduce(QPixmap,QString)), this, SLOT(slotIntroduce(QPixmap,QString)));
        ListWidgetItem *pItem = new ListWidgetItem(pItemWidget);
        pItem->setData(Qt::UserRole, itemIndex++);
        pItem->setData(Qt::UserRole+1, name);
        pItem->setData(Qt::UserRole+2, description);
        pItem->data_ = pHash_moduelName_dataStruct_->value(bbName);

        //解决了左边icon右边Widget的问题
        pItem->setSizeHint(QSize(41, 31));
        listWidget->addItem(pItem);
        listWidget->setItemWidget(pItem, pItemWidget);
    }

    qDebug() << "一共有多少个模块:" << itemIndex;
    //listWidget->setItemNumber(itemIndex);
}

void IntroduceForm::initGui()
{
    this->move(1, 1);
}

QStringList IntroduceForm::getComponentsName(const QString &dirPath)
{
	QDir dir(dirPath);
	QStringList filters;
	filters << "Buffer.mpb" << "." << "..";
	//filters << "buffer.dll" << "." << "..";
	dir.setNameFilters(filters);
	dir.setSorting(QDir::Name);	//排序,可有可无

	QStringList tmp;
	foreach (const QString &fileName, dir.entryList())
	{
		QString filePath = dirPath + "/" + fileName;
		QFileInfo infor(filePath);
		tmp.append(infor.baseName());
	}
	return tmp;
}

void IntroduceForm::on_pushButtonClose_clicked()
{
    close();
}

void IntroduceForm::slotIntroduce(const QPixmap &image, const QString &text)
{
    labelImage->resize(image.size());
    labelImage->setPixmap(image);
    labelText->move(labelImage->x(), labelImage->y()+labelImage->height());
    labelText->setText(text);
}
