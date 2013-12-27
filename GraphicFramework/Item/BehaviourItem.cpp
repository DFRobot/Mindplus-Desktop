#include "BehaviourItem.h"
#include <QPainter>
#include <QDebug>
#include <QGraphicsScene>
#include <QCursor>

BehaviourItem::BehaviourItem(const QRect &rect, const QPixmap &bgImage, QGraphicsItem *parent) :
    GraphicsItemBase(rect, bgImage, parent)
{
    initSetting();
}

void BehaviourItem::setPropertyValue(int id, const QString &name, const QString &itemType, const QString &itemTypeDetail, const QString &imagePath)
{
    GraphicsItemBase::setPropertyValue(id, name, itemType, itemTypeDetail);
    imagePath_ = imagePath;
}

QRectF BehaviourItem::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF(0 - penWidth/2, 0-penWidth/2, bgRect_.width()+penWidth, bgRect_.height()+penWidth);
}

void BehaviourItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    QColor penColor;
    if (mouseOver_){
        penColor.setRgb(255, 237, 137);

    }else{
        penColor.setRgb(178, 236, 255);
    }

    QPen pen(penColor);
    QBrush brush(penColor);
    painter->setPen(pen);
    painter->setBrush(brush);
    QPointF points[3] = {
        QPointF(0, 0),
        QPointF(0, 20),
        QPointF(18, 10),
    };
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->drawPolygon(points, 3);
}

void BehaviourItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << findPathPointOffset_;
    qDebug() << this->scenePos();
    QGraphicsObject::mousePressEvent(event);
}

void BehaviourItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    Q_UNUSED(event);
    mouseOver_ = true;
	update();
}

void BehaviourItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    Q_UNUSED(event);
    mouseOver_ = false;
	update();
}


void BehaviourItem::initSetting()
{
    this->setAcceptHoverEvents(true);
    this->setAcceptDrops(true);
    mouseOver_ = false;
}
