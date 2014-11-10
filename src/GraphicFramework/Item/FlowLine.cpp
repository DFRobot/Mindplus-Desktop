#include "FlowLine.h"
#include <math.h>
#include <QGraphicsPolygonItem>
#include <QGraphicsLineItem>
#include <QGraphicsScene>
#include <QPainterPath>
#include <QGraphicsSceneMouseEvent>
#include <QRectF>
#include <QPainter>
#include <QDebug>
#include <QPainterPathStroker>
#include <QStyleOptionGraphicsItem>
#include <QTimer>
#include <QKeyEvent>
#include <QGraphicsOpacityEffect>

#include "GraphicFramework/Scene/EditScene.h"
#include "GraphicFramework/Item/GraphicsItemBase.h"
#include "GraphicFramework/Item/GraphicsItermGroup.h"
#include "GraphicFramework/Item/ParameterItem.h"
#include "GraphicFramework/Scene/EditScene.h"
#include "Other/Data/DatabaseEditComponent.h"
#include "Animation.h"

FlowLine::FlowLine(const QPainterPath &path, const QPointF &startPos, const QPointF &endPos, QString name, QColor color, QGraphicsItem *parent)
    : QGraphicsPathItem(parent)
    , pStartItem_(NULL)
    , pEndItem_(NULL)
    , name_(name)
    , startName_("")
    , endName_("")
    , startPos_(startPos)
    , endPos_(endPos)
    , color_(color)
    , dashOffset_(0)
    , path_(path)
	, timerId_(-1)
	, bDrag_(false)
{
    this->setData(Qt::UserRole+4, "line");
    this->initData();
    this->initSetting();
}

FlowLine::FlowLine(const QPainterPath &path, GraphicsItemBase *pStartItem, GraphicsItemBase *pEndItem, QColor color, QGraphicsItem *parent)
    : QGraphicsPathItem(parent)
    , pStartItem_(pStartItem)
    , pEndItem_(pEndItem)
    , name_("")
    , startName_(pStartItem->getName())
    , endName_(pEndItem->getName())
    , startPos_(pStartItem->getFindPathPoint())
    , endPos_(pEndItem->getFindPathPoint())
    , color_(color)
    , dashOffset_(0)
    , path_(path)
{
    this->setData(Qt::UserRole+4, "line");
    this->initData();
    this->initSetting();
}

QRectF FlowLine::boundingRect() const
{
    return path_.controlPointRect();
}

QPainterPath FlowLine::shape() const
{
    QPainterPathStroker stroker;
    stroker.setCapStyle(Qt::RoundCap);
    stroker.setJoinStyle(Qt::RoundJoin);
    stroker.setCurveThreshold(100);
    stroker.setWidth(8);
    return stroker.createStroke(path_);
}

void FlowLine::setLinePath(const QPainterPath &path)
{
    path_ = path;
}

/**
 * @brief FlowLine::deleteLine 删除连线
 */
void FlowLine::deleteLine()
{//这里的代码看起来是没有逻辑问题的,问题有可能出在焦点没有切换.
    qDebug() << "要删除连线";
    if("parameterIn" == pStartItem_.data()->data(ITEM_TYPE_DETAIL).toString()
			|| "parameterIn" == pEndItem_.data()->data(ITEM_TYPE_DETAIL).toString())
	{//处理par
        ParameterItem *p = static_cast<ParameterItem *>(pEndItem_.data());
        if(p->isHide())
        {
			//Animation::opacityAnimation(p, 200, 0, 1);
            p->setHide(false);
            p->update();
        }
        EditScene *pScene = static_cast<EditScene *>(scene());
        if(pScene)
		{//这里是删除数据库中的数据的
            //删除linkage对应数据
            pScene->pDatabaseEditComponent_->deleteLinkage(pStartItem_.data()->data(Qt::UserRole+28).toString()
                                                           , pEndItem_.data()->data(Qt::UserRole+28).toString());
            //还原BBlist对应数据
			int index = pScene->pDatabaseEditComponent_->getParamterId(pEndItem_.data()->data(ITEM_NAME).toString()).toInt();
            pScene->pDatabaseEditComponent_->updateBBlist(pEndItem_.data()->data(Qt::UserRole+26).toString()
                                                          , pEndItem_.data()->data(Qt::UserRole+27).toInt()
                                                          , index);
        }
    }
    else
    {
        qDebug() << "需要修改端口占用";

        if("behaviour" == pStartItem_.data()->data(ITEM_TYPE).toString())
        {
            GraphicsItermGroup *pGroup = static_cast<GraphicsItermGroup *>(pStartItem_.data()->group());
            if(pGroup)
            {
                if(pGroup->map_behaviourOutPointer_index_.contains(pStartItem_.data()))
                {
                    int index = pGroup->map_behaviourOutPointer_index_.value(pStartItem_.data());
                    pGroup->listBehaviourOutUse_[index] = false;
                }
            }
        }
        if("behaviour" == pEndItem_.data()->data(ITEM_TYPE).toString())
        {
            GraphicsItermGroup *pGroup = static_cast<GraphicsItermGroup *>(pEndItem_.data()->group());
            if(pGroup)
            {
                if(pGroup->map_behaviourInPointer_index_.contains(pEndItem_.data()))
                {
                    int index = pGroup->map_behaviourInPointer_index_[pEndItem_.data()];
                    pGroup->listBehaviourInUse_[index] = false;
                }
            }
        }
    }

    QString tmp =pStartItem_.data()->data(ITEM_NAME).toString();
    if("start" == tmp)
    {
        tmp = "Start";
    }

    QString tmp2 = pEndItem_.data()->data(ITEM_NAME).toString();
    if("parameterIn" == pEndItem_.data()->data(ITEM_TYPE_DETAIL).toString())
    {
        EditScene *pScene = static_cast<EditScene *>(scene());
		QString strId = pScene->pDatabaseEditComponent_->getParamterId(tmp2);
        tmp2 = tr("LocalParameter_%1").arg(strId);
    }

    qDebug() << "删除线的两端" << tmp << tmp2;
	if(-1 != timerId_)
	{
		killTimer(timerId_);
		timerId_ = -1;
	}
    //Scene和Group都要响应
    //先在group删除记录自身连接的线
	emit signalDeleteLine(this);//在group中删除line相关的一些记录
    EditScene *pScene = static_cast<EditScene *>(scene());
    pScene->deleteLine(this, tmp, tmp2);
}

void FlowLine::sendSelected()
{
    qDebug() << "already send signalFocusIn";
    emit signalFocusIn(this, startName_, endName_);
	this->setZValue(zValue() + 1);
}

void FlowLine::setOpacity(qreal opactiy)
{
    opactiy_ = opactiy;
    pGraphicsOpacityEffect_->setOpacity(opactiy_);
}

void FlowLine::slotEndItemMoveOffset(const QPointF &offset)
{
    qDebug() << "终点来的信号" << offset;
    EditScene *p = static_cast<EditScene *>(this->scene());

    if(pEndItem_)
    {
        path_ = p->findPath(pStartItem_.data()->getFindPathPoint()
                            , pEndItem_.data()->getFindPathPoint()
                            , pStartItem_.data()->getFindPathPointEnd()
                            , pEndItem_.data()->getFindPathPointEnd());
    }
    else
    {
        qDebug() << "pEndItem_ is null";
    }

    this->update();
}

void FlowLine::slotStartItemMoveOffset(const QPointF &offset)
{
    qDebug() << "起点的信号";
    EditScene *p = static_cast<EditScene *>(this->scene());
    startPos_ = offset;

    if(pEndItem_)
    {
        path_ = p->findPath(pStartItem_.data()->getFindPathPoint()
                            , pEndItem_.data()->getFindPathPoint()
                            , pStartItem_.data()->getFindPathPointEnd()
                            , pEndItem_.data()->getFindPathPointEnd());
    }
    else
    {
        qDebug() << "pEndItem_ is null";
    }

    this->update();
}

void FlowLine::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setRenderHint(QPainter::Antialiasing, true);

    ////////////////////绘制线条//////////////////
    QPainterPathStroker stroker;
    stroker.setWidth(4);
    stroker.setJoinStyle(Qt::RoundJoin);
    stroker.setCapStyle(Qt::RoundCap);

    QBrush brush_BlueLine(QColor (60, 167, 206));
    QBrush brush_BlueLine_Selected(QColor (255, 234, 115));
    QBrush brush_BlueLine_FloatPoint(QColor (195, 237, 252));
    QBrush brush_BlueLine_FloatPoint_Selected(QColor (0, 0, 0 , 40));

    QBrush brush_RedLine(QColor (255, 95, 95));
    QBrush brush_RedLine_Selected(QColor (255, 234, 115));
    QBrush brush_RedLine_FloatPoint(QColor (255, 255, 255 , 225));
    QBrush brush_RedLine_FloatPoint_Selected(QColor (0, 0, 0 , 40));

    QBrush brush_Shadow(QColor (0, 0, 0, 40));

    QPainterPath stroke = stroker.createStroke(path_);
    QPainterPath strokeShadow = stroker.createStroke(path_);

    if(!isSelected())
    {//未选中时
        if(name_.contains("LocalParameter_"))
        {//parameter的联线
            painter->fillPath(stroke, brush_RedLine);

            stroker.setDashOffset(dashOffset_);
            QVector<qreal> dashes;
            qreal space = 15;
            dashes << 1 << space;
            stroker.setDashPattern(dashes);
            QPainterPath strokeFloatPoint = stroker.createStroke(path_);
            painter->fillPath(strokeFloatPoint, brush_RedLine_FloatPoint);
        }
        else
        {
            painter->fillPath(stroke, brush_BlueLine);

            stroker.setDashOffset(dashOffset_);
            QVector<qreal> dashes;
            qreal space = 8;
            dashes << 1 << space << 1 << space;
            stroker.setDashPattern(dashes);
            QPainterPath strokeFloatPoint = stroker.createStroke(path_);
            painter->fillPath(strokeFloatPoint, brush_BlueLine_FloatPoint);
        }
    }
    else
    {//选中时
        if(name_.contains("LocalParameter_"))
        {//parameter的联线
            painter->fillPath(stroke, brush_RedLine_Selected);

            stroker.setDashOffset(dashOffset_);
            QVector<qreal> dashes;
            qreal space = 15;
            dashes << 1 << space;
            stroker.setDashPattern(dashes);
            QPainterPath strokeFloatPoint = stroker.createStroke(path_);
            painter->fillPath(strokeFloatPoint, brush_BlueLine_FloatPoint_Selected);
        }
        else
        {//behavior的连线
            painter->fillPath(stroke, brush_BlueLine_Selected);

            stroker.setDashOffset(dashOffset_);
            QVector<qreal> dashes;
            qreal space = 8;
            dashes << 1 << space << 1 << space;
            stroker.setDashPattern(dashes);
            QPainterPath strokeFloatPoint = stroker.createStroke(path_);
            painter->fillPath(strokeFloatPoint, brush_RedLine_FloatPoint_Selected);
        }
    }

    /////////////设置阴影偏移/////////////
    for (int i = 0 ; i < strokeShadow.elementCount(); i ++)
    {
        strokeShadow.setElementPositionAt(i,strokeShadow.elementAt(i).x,strokeShadow.elementAt(i).y+2);
    }
    painter->fillPath(strokeShadow, brush_Shadow);

    ///////////后续处理////////////
    if (timerLock_ == 1)
    {
        dashOffset_ += 0.28;
    }

    timerLock_ = 0;

    //在这里设定好option,然后传递给基类,貌似可以不显示虚线
    QStyleOptionGraphicsItem op;
    op.initFrom(widget);
    op.state = QStyle::State_None;
    QGraphicsPathItem::paint(painter, &op, widget);
}

void FlowLine::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event);
    timerLock_ = 1;
	this->update();
//	if(this->scene() != NULL)
//	{
//		this->scene()->update();
//	}
}

void FlowLine::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "线接收了键盘信号";
    if(event->key() == Qt::Key_Delete)
    {
        deleteLine();
		event->accept();
		return;
    }
	event->ignore();
}

void FlowLine::initOpacity()
{
    pGraphicsOpacityEffect_ = new QGraphicsOpacityEffect(this);
    opactiy_ = 1.0;   //刚开始就是不透明的
    pGraphicsOpacityEffect_->setOpacity(opactiy_ );
    this->setGraphicsEffect(pGraphicsOpacityEffect_);
}

void FlowLine::initSetting()
{
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemIsFocusable, true);
}

void FlowLine::initData()
{
    timerLock_ = 0;
	timerId_ = startTimer(33);
    initOpacity();
}
