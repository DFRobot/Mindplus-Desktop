#include "ListWidget.h"
#include <QDropEvent>
#include <QDebug>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QPainter>
#include <QPen>
#include <QMimeData>
#include <QDrag>

#include "ListWidgetItem.h"
#include "ListWidgetItemWidget_Component.h"
#include "Common.h"

ListWidget::ListWidget(QWidget *parent)
	: QListWidget(parent)
{
	//设置无焦点
	this->setFocusPolicy(Qt::NoFocus);
	//设置选择模式为单选
	this->setSelectionMode(QAbstractItemView::SingleSelection);
	//接受拖放
	//this->setAcceptDrops(true);
	//设置显示将要被放置的位置
	this->setDropIndicatorShown(true);
	setFrameShape(QFrame::NoFrame);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void ListWidget::dropEvent(QDropEvent *event)
{
	//为了防止自身拖拽
	if(event->source() == this)
	{
		return;
	}
}

void ListWidget::mousePressEvent(QMouseEvent *event)
{
    QListWidget::mousePressEvent(event);

	QListWidgetItem* pTopItem = this->itemAt(10, 10);
	if(NULL == pTopItem)
	{
		qDebug() << "获取顶端的item失败";
		return;
	}
	int topItemIndex = this->row(pTopItem);

	QListWidgetItem *pItem = this->itemAt(event->pos());
	if(NULL == pItem)
	{
		qDebug() << "获取当前的item失败";
		return;
	}

	int itemIndex = pItem->data(ListWidgetItemData::index).toInt();
	QString bbName = pItem->data(ListWidgetItemData::blockName).toString();
	qDebug() << "点击的时候bbName是:" << bbName;

    QMimeData *pMimeData = new QMimeData;
	pMimeData->setText(bbName);
    QDrag *pDrag = new QDrag(this);

	QPixmap pix(180, 40);
    pix.fill(QColor(73, 160, 191));
    QPainter painter(&pix);
    painter.setPen(QPen(QColor(255, 255, 255)));
	painter.drawText(pix.rect(), Qt::AlignCenter, bbName);

    pDrag->setMimeData(pMimeData);
    pDrag->setPixmap(pix);  //移动中显示的图片

	QPoint offset = QPoint(0, 50*(itemIndex-topItemIndex)+2);

    pDrag->setHotSpot(event->pos() - offset);
    //执行拖放
	pDrag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction);
}


