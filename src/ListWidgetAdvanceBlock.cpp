#include "ListWidgetAdvanceBlock.h"
#include <QMouseEvent>
#include <QDebug>
#include <QMimeData>
#include <QDrag>
#include <QPen>
#include <QPainter>

#include "Common.h"

ListWidgetAdvanceBlock::ListWidgetAdvanceBlock(QWidget *parent)
    : ListWidget(parent)
{
    setFrameShape(QFrame::NoFrame);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void ListWidgetAdvanceBlock::mousePressEvent(QMouseEvent *event)
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

	int itemIndex = pItem->data(ListWidgetItemData::index/*Qt::UserRole*/).toInt();
	QString bbName = pItem->data(ListWidgetItemData::blockName/*Qt::UserRole+1*/).toString();
	qDebug() << "mousePress的时候bbName:" << bbName;
    emit signalShowHelp(bbName);

    QMimeData *pMimeData = new QMimeData;
    pMimeData->setText(bbName);
    QDrag *pDrag = new QDrag(this);

    QPixmap pix(150, 20);
    pix.fill(QColor(73, 160, 191));
    QPainter painter(&pix);
    painter.setPen(QPen(QColor(255, 255, 255)));
    painter.drawText(pix.rect(), Qt::AlignCenter, bbName);

    pDrag->setMimeData(pMimeData);
    pDrag->setPixmap(pix);  //移动中显示的图片

    QPoint offset = QPoint(0, 20*(itemIndex - topItemIndex));
    qDebug() << itemIndex << topItemIndex;
    pDrag->setHotSpot(event->pos() - offset);
    //执行拖放
    pDrag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction);
}
