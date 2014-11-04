#include "GraphicsItemBase.h"
#include <QDebug>
#include <QTimer>
#include <QGraphicsOpacityEffect>

GraphicsItemBase::GraphicsItemBase(const QRect &rect, const QPixmap &bgImage, QGraphicsItem *parent)
    : QGraphicsObject(parent)
    , bgRect_(rect)
    , bgPixmap_(bgImage)
{
    pTimer_ = new QTimer(this);
    //initOpacity();
}

void GraphicsItemBase::setPropertyValue(int id, const QString &name, const QString &itemType, const QString &itemTypeDetail)
{
    id_ = id;
    name_ = name;
    itemType_ = itemType;
    itemTypeDetail_ = itemTypeDetail;
}

void GraphicsItemBase::addKeyEvent(QKeyEvent *event)
{
    this->keyPressEvent(event);
}

QRect GraphicsItemBase::getRect() const
{
    int w = bgRect_.width();
    int h = bgRect_.height();

    return QRect(this->scenePos().toPoint(), QSize(w, h));
}

QPoint GraphicsItemBase::getCenterPoint()
{
    return QPoint(bgRect_.width()/2, bgRect_.height()/2);
}

/*!
 * \brief GraphicsItemBase::setFindPathPointOffset 设置寻路终点和group左上角的偏移
 * \param offset 偏移量
 */
void GraphicsItemBase::setFindPathPointOffset(const QPoint &offset)
{
    findPathPointOffset_ = offset;
}

/*!
 * \brief GraphicsItemBase::getFindPathPoint 获取寻路终点坐标
 * \return 当存在parentItem的时候, 返回寻路终点坐标, 当路径不存在的时候返回空值
 */
QPoint GraphicsItemBase::getFindPathPoint() const
{
    if(NULL == parentItem())
    {
        if("start" == this->data(ITEM_TYPE).toString())
        {
            qDebug() << "这货运行了啊";
            return findPathPointOffset_ + scenePos().toPoint();
        }
        else
        {
            return QPoint();
        }
    }
    qDebug() << "findPathPointOffset_:" << findPathPointOffset_ << "parentItem()->scenePos().toPoint():" << parentItem()->scenePos().toPoint();
    return findPathPointOffset_ + parentItem()->scenePos().toPoint();
}

/*!
 * \brief GraphicsItemBase::getFindPathPointOffset
 * \return
 */
QPoint GraphicsItemBase::getFindPathPointOffset() const
{
    return findPathPointOffset_;
}

/*!
 * \brief GraphicsItemBase::setFindPathPointEndOffset 设置路径终点和Group左上角的偏移
 * \param offset
 */
void GraphicsItemBase::setFindPathPointEndOffset(const QPoint &offset)
{
    findPathPointEndOffset_ = offset;
}

/*!
 * \brief GraphicsItemBase::getFindPathPointEnd 获取寻路路径终点的坐标
 * \return 当存在parentItem的时候, 返回寻路的路径终点坐标, 当路径不存在的时候返回空值
 */
QPoint GraphicsItemBase::getFindPathPointEnd() const
{
    if(NULL == parentItem())
    {
        if("start" == this->data(ITEM_TYPE).toString())
        {
            qDebug() << "这货运行了啊";
            return findPathPointEndOffset_ + scenePos().toPoint();
        }
        else
        {
            return QPoint();
        }
    }
    return findPathPointEndOffset_ + parentItem()->scenePos().toPoint();
}

/*!
 * \brief GraphicsItemBase::getFindPathPointEndOffset 获取寻路终点和group左上角坐标平的偏移量
 * \return 偏移量
 */
QPoint GraphicsItemBase::getFindPathPointEndOffset() const
{
    return findPathPointEndOffset_;
}
