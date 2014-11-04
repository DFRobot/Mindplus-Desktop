#include "StartItem.h"
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QDebug>
#include <QCursor>

StartItem::StartItem(const QRect &rect, const QPixmap &bgImage, QGraphicsItem *parent) :
    GraphicsItemBase(rect, bgImage, parent)
{
    this->setData(Qt::UserRole, "start-default");
    this->setData(Qt::UserRole+4, "start");
    this->setData(Qt::UserRole+5, "start");
    this->setData(Qt::UserRole+8, "start");
    this->setName("start");
    findPathPointOffset_ = QPoint(100, 25);
    findPathPointEndOffset_ = QPoint(50, 25);
    itemType_ = "start";
    this->setAcceptHoverEvents(true);
}

QRectF StartItem::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF(0 - penWidth/2, 0-penWidth/2, bgRect_.width()+penWidth, bgRect_.height()+penWidth);
}

void StartItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawPixmap(QRect(bgRect_.topLeft(),QSize(107,40)), bgPixmap_);
}
