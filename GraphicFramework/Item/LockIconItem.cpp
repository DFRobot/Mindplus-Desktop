#include "LockIconItem.h"
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsEffect>

LockIconItem::LockIconItem(const QRect &rect, const QPixmap &bgImage, QGraphicsItem *parent)
    : GraphicsItemBase(rect, bgImage, parent)
    , pEndItem_(NULL)
	, timerId_(-1)
{
    initData();
}

void LockIconItem::setRect(const QRect &rect)
{
    bgRect_ = rect;
}

void LockIconItem::setRePoint(const QPoint &pos)
{
    point_ = pos;
}

QRectF LockIconItem::boundingRect() const
{
	return QRectF(bgRect_);
}

void LockIconItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setRenderHint(QPainter::Antialiasing, true);
	painter->drawPixmap(-14, -14, bgRect_.width(), bgRect_.height(), bgPixmap_);
}

void LockIconItem::initData()
{
    this->setData(Qt::UserRole+4, "lockItem");
    this->setData(ITEM_TYPE_DETAIL, "lockItem");
}
