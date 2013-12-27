#include "RootItem.h"
#include <QPainter>
#include <QDebug>
#include <QLabel>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QApplication>
#include <CustomFont.h>

RootItem::RootItem(const QString &str, const QRect &rect, const QPixmap &bgImage, QGraphicsItem *parent)
    : GraphicsItemBase(rect, bgImage, parent)
    , string_(str)
{
    initSetting();
    initData();
}

void RootItem::setPropertyValue(const QString &name, const QString &itemType, const QString &itemTypeDetail, int x, int y, const QString &type, const QString &tag, int doubleType, int x2, int y2)
{
    GraphicsItemBase::setPropertyValue(-1, name, itemType, itemTypeDetail);
    nameOffsetX = x;
    nameOffsetY = y;
    type_ = type;
    tag_ = tag;
    doubleType_ = doubleType;
    imageOffsetX = x2;
    imageOffsetY = y2;
}

QRectF RootItem::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF(0 - penWidth/2, 0-penWidth/2, bgRect_.width()+penWidth, bgRect_.height()+penWidth);
}

void RootItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    //qDebug() << "paint!!!!!!";
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QPen pen(QColor(255,255,255));
    if(hasFocus()){
        pen.setWidth(3);
        pen.setColor(QColor(255,255,100));

    }else{
        pen.setWidth(1);
        pen.setColor(QColor(0,0,0,80));
    }

    painter->setPen(pen);
    painter->drawRect(bgRect_);
    pen.setWidth(3);
    pen.setColor(QColor(0,0,0,30));
    painter->setPen(pen);
    painter->drawRect(bgRect_);
    ////第二层 模块本身
    painter->setPen(QPen((QColor(59, 130, 156))));
    painter->setBrush(QBrush(QColor(59, 130, 156)));
    painter->drawRect(bgRect_);

    painter->setFont(font_);
    //qDebug() << "这里的大小不对么?" << bgRect_;
    QPointF imgPos = QPointF((this->bgRect_.width()-bgPixmap_.width())/2, (bgRect_.height()-bgPixmap_.height())/2);
    painter->drawPixmap(imgPos+QPointF(imageOffsetX, imageOffsetY), bgPixmap_);
    painter->setPen(QPen(QColor(255,255,255)));
    painter->drawText(bgRect_.x() + nameOffsetX, bgRect_.y()+nameOffsetY, bgRect_.width(), bgRect_.height(), Qt::AlignCenter, string_);
}

void RootItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //qDebug() << "root pressed~~~~!!@!@##$%#$^&" << event->scenePos() - parentItem()->scenePos();
    emit signalMousePressedOffset(event->scenePos() - parentItem()->scenePos());
    emit signalOldPoint(parentItem()->scenePos());

    QGraphicsItem::mousePressEvent(event);
}

//移动之前group处于不接受所有事件的状态, 移动距离超过manhattan距离的时候, group接收所有事件
void RootItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if ((event->scenePos().toPoint() - pressStartPosition_).manhattanLength()
              < QApplication::startDragDistance())
    {
        return;
    }

    emit signalSetHandlesChildEvents(true);
}

//移动释放的时候group从新设置为不接收所有事件的状态
void RootItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    qDebug() << "鼠标释放 要设置SetHandlesChildEvents(false);";
    emit signalSetHandlesChildEvents(false);
}

void RootItem::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "他没有收到么";
    if(event->key() == Qt::Key_Delete)
    {
        qDebug() << "按下删除";
        emit signalDeleteItem(name_);
        //this->scene()->removeItem(this);
    }

    QGraphicsItem::keyPressEvent(event);
}

void RootItem::focusInEvent(QFocusEvent *event)
{
    qDebug() << "root focus in event , and name_ is " << name_;
	emit signalFocusInGroup(name_);
    update();
    GraphicsItemBase::focusInEvent(event);
}

void RootItem::initSetting()
{
    //自己重载鼠标事件还是不能解决这个问题
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
    setFlag(QGraphicsItem::ItemIsFocusable, true);
    this->setAcceptDrops(true);
    this->setAcceptHoverEvents(true);
}

void RootItem::initData()
{
	//font_ = CustomFont::getCustomFont("msyh.ttc",9);
    //计算名字的长度
    QFontMetrics fm(font_);
    pixelsWide_ = fm.width(name_);
    pixelsHigh_ = fm.height();
}
