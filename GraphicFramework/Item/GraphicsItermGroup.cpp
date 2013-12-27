#include "GraphicsItermGroup.h"
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsSceneMouseEvent>
#include <QPropertyAnimation>
#include <QEasingCurve>
#include <QAbstractAnimation>
#include <QGraphicsScene>
#include <QPainter>
#include <QTimer>
#include "GraphicFramework/Item/GraphicsItemBase.h"
#include "GraphicFramework/Item/ParameterItem.h"
#include "GraphicFramework/Scene/EditScene.h"
#include "GraphicFramework/Item/RootItem.h"
#include "GraphicFramework/Item/FlowLine.h"
#include "GraphicFramework/Item/BehaviourItem.h"
#include "Animation.h"

const int BASE_OFFSET = 40;
const int BASE_SIZE_X = 40;
const int BASE_SIZE_Y = 30;
//fuck的坐标系

GraphicsItermGroup::GraphicsItermGroup(const QRect &rect, int sizeX, int sizeY, EditScene *pScene, QObject *parent)
    : QObject(parent)
    , rect_(rect)
    , sizeX_(sizeX)
    , sizeY_(sizeY)
    , countParmaeterIn_(0)
    , countParmaeterOut_(0)
    , countBehaviorIn_(0)
    , countBehaviorOut_(0)
    , pRoot_(NULL)
    , pScene_(pScene)
    , itemCount_(0)
    , rootName_("")
    , groupId_(-1)
    , bHideLine_(false)
    , bHaveBehaviorOut_(false)
	, blockName_("")
{
    this->initSetting();
    this->initData();
    qDebug() << "你妹的sizeX_:" <<sizeX_ << "sizeY_:" <<sizeY_;
}

GraphicsItermGroup &GraphicsItermGroup::operator=(const GraphicsItermGroup &rhs)
{
    if(this == &rhs)
    {
        return *this;
    }
    //给parameter赋值
    for(int i = 0; i != list_parameter_.size(); ++i)
    {
        QString value = rhs.list_parameter_.at(i)->getValue();
        list_parameter_.at(i)->setValue(value);
    }
    offsetMouseToLeftTop_ = rhs.offsetMouseToLeftTop_;

    return *this;
}

//这里存在隐患啊
QRectF GraphicsItermGroup::boundingRect() const
{
    return QRectF(rect_);
}

QPainterPath GraphicsItermGroup::shape() const
{
    QPainterPath path;
    path.addRect(rect_);
    return path;
}

void GraphicsItermGroup::addMouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    mouseMoveEvent(event);
}

void GraphicsItermGroup::addMouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    mouseReleaseEvent(event);
}

void GraphicsItermGroup::addRoot(GraphicsItemBase *p)
{
    pRoot_ = p;
    rootName_ = pRoot_->getName();
    addToGroup(p);
    ++itemCount_;
    p->setPos(20, 30); //还是看数字最直观

    RootItem *pRoot = static_cast<RootItem *>(p);
    connect(pRoot, SIGNAL(signalSetHandlesChildEvents(bool)), this, SLOT(slotSetHandlesChildEvents(bool)));
    connect(pRoot, SIGNAL(signalMousePressedOffset(QPointF)), this, SLOT(slotMousePressedOffset(QPointF)));
    connect(pRoot, SIGNAL(signalOldPoint(QPointF)), this, SLOT(slotOldPoint(QPointF)));
    connect(pRoot, SIGNAL(signalDeleteItem(QString)), this, SLOT(slotDeleteItem(QString)));

    list_item_self_ << p;
}

//上
void GraphicsItermGroup::addParameterIn(GraphicsItemBase *p)
{
    addToGroup(p);
    list_parameter_.append(static_cast<ParameterItem*>(p));
    ++itemCount_;
    int offsetX = countParmaeterIn_ * 50 + 20 +6;
    int offsetY = 30 - 20; //BASE_OFFSET/2 ->中心的偏移
    p->setPos(offsetX, offsetY);

	p->setFindPathPointOffset(QPoint(countParmaeterIn_* 50 +20+20, 0));
	//p->setFindPathPointOffset(QPoint(countParmaeterIn_* 50 +20+20, -20));
    p->setFindPathPointEndOffset( QPoint(countParmaeterIn_* 50+ 20 +20/*+5*/, 15));
    ++countParmaeterIn_;
    list_item_self_ << p;
}

//下这里基本上是正确的
void GraphicsItermGroup::addParameterOut(GraphicsItemBase *p)
{
    addToGroup(p);
    ++itemCount_;
    int offsetX = countParmaeterOut_ * 50 + 20 +13;
    int offsetY = rect_.height() - 15;
    p->setPos(offsetX, offsetY);
    //取整加10 保证点在路障之外,且能被寻路到(10*10对齐)
	p->setFindPathPointOffset(QPoint(countParmaeterOut_* 50+ 20 +20, rect_.height()));
	//p->setFindPathPointOffset(QPoint(countParmaeterOut_* 50+ 20 +20, rect_.height()+20));
	p->setFindPathPointEndOffset(QPoint(countParmaeterOut_* 50+ 20 +20/*+5*/, rect_.height()-3));//和这里一点关系都没有啊

    ++countParmaeterOut_;
    list_item_self_ << p;
}

//左
void GraphicsItermGroup::addBehaviorIn(GraphicsItemBase *p)
{
    addToGroup(p);
    list_behavior_.append(static_cast<BehaviourItem*>(p));
    ++itemCount_;
    int offsetX = 20 - 12;
    int offsetY = (countBehaviorIn_ * 30) + 30 +5; // 三角形的高度是20 但是上下留空隙5 所以是30    模块的坐标是20，30     5，12是嵌入到的视觉效果
    p->setPos(offsetX, offsetY);

	p->setFindPathPointOffset(QPoint(0, offsetY+15));
	//p->setFindPathPointOffset(QPoint(-20, offsetY+15));
    p->setFindPathPointEndOffset(QPoint(10, offsetY+15));

    //一笔画相关
    {
        map_behaviourInPointer_index_[p] = countBehaviorIn_;
    }

    ++countBehaviorIn_;
    list_item_self_ << p;
}

//右
void GraphicsItermGroup::addBehaviorOut(GraphicsItemBase *p)
{
    addToGroup(p);
    list_behavior_.append(static_cast<BehaviourItem*>(p));
    ++itemCount_;
    int offsetX = rect_.width() - 20 - 2; //BASE_OFFSET/2 ->中心的偏移
    int offsetY = (countBehaviorOut_ * 30) + 30 +5;
    p->setPos(offsetX, offsetY);
	p->setFindPathPointOffset(QPoint(rect_.width(), offsetY +15));
	//p->setFindPathPointOffset(QPoint(rect_.width()+20, offsetY +15));
    p->setFindPathPointEndOffset(QPoint(rect_.width()-10, offsetY +15));

    //一笔画相关
    {
        bHaveBehaviorOut_ = true;//一笔画终止条件
        map_behaviourOutPointer_index_[p] = countBehaviorOut_;
    }

    ++countBehaviorOut_;
    list_item_self_ << p;
}

/*!
 * \brief GraphicsItermGroup::setOffsetMousePosToGroupLeftTop 设置鼠标Group的左上角坐标偏移
 * \param pos 偏移量
 */
void GraphicsItermGroup::setOffsetMousePosToGroupLeftTop(const QPointF &offset)
{
    offsetMouseToLeftTop_ = offset;
}

/*!
 * \brief GraphicsItermGroup::sendOffsetPreviousPosToCurrentPos emit上一个位置和这一个位置的偏移
 */
void GraphicsItermGroup::sendGroupCurrentPos()
{
    qDebug() << "这里调出的???????";
    emit signalGroupCurrentPos(this->scenePos());
}

void GraphicsItermGroup::addConnectSelfLine(FlowLine *p)
{//暂时不需要考虑清空的问题, 到时候增加删除线的功能的时候再加入删除
    list_connect_self_line_ << p;
}

void GraphicsItermGroup::deleteRecoverLine(FlowLine *p)
{
	int count =list_recover_line_.removeAll(p);
	if(0 == count)
	{
		qDebug() << "找不到要删除的线段（要恢复的）";
	}
}

void GraphicsItermGroup::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Delete)
    {
        pRoot_->addKeyEvent(event);
        event->accept();
    }
    else
    {
        QGraphicsItemGroup::keyPressEvent(event);
    }
}

void GraphicsItermGroup::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    //qDebug() << "事件先到这里";
    if(offsetMouseToLeftTop_.isNull())
    {
        return;
    }
    int x = (event->scenePos() - offsetMouseToLeftTop_).x();
    int y = (event->scenePos() - offsetMouseToLeftTop_).y();

    x = qRound(x / 10.0) * 10;
    y = qRound(y / 10.0) * 10;

    int width = pScene_.data()->getGridSizeWidth();
    int height = pScene_.data()->getGridSizeHeight();
    //超出上届
    if(x + this->getSize().width() > width)
    {
        x = width - this->getSize().width();
    }
    if(y + this->getSize().height() > height)
    {
        y = height - this->getSize().height();
    }
    //超出下届
    if(x < 0)
    {
        x = 0;
    }
    if(y < 0)
    {
        y = 0;
    }

    if(!bHideLine_)
    {
        qDebug() << "渐变让线消失";
        foreach (FlowLine *pLine, list_connect_self_line_)
        {
            Animation::opacityAnimation(pLine, 100, 1, 0);
        }
        bHideLine_ = true;
    }

    this->setPos(x, y);
    event->accept();
}

//鼠标释放的时候通知group可以处理单个字item的事件
void GraphicsItermGroup::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(handlesChildEvents())
    {
        //如果是按照拖出来的东西也会对齐的话这里就是多余的, 如果拖出来的时候不会对齐这里就是必要的
        int x = (event->scenePos() - offsetMouseToLeftTop_).x();
        int y = (event->scenePos() - offsetMouseToLeftTop_).y();

        x = qRound(x / 10.0) * 10;
        y = qRound(y / 10.0) * 10;
        //this->setPos(QPointF(x, y));

        this->setHandlesChildEvents(false);
        emit signalGroupCurrentPos(this->scenePos());
        //oldPos_ = this->scenePos();
        offsetMouseToLeftTop_ = QPointF();

        QList<QGraphicsItem *> list_line_ = this->collidingItems();
        if(list_line_.size() > itemCount_)
        {
			//检测哪些线是需要重连的
            findCollideLine();
        }
        else
        {
            recoverLinePath();
        }

        if(bHideLine_)
        {
            foreach (FlowLine *pLine, list_connect_self_line_)
            {
                Animation::opacityAnimation(pLine, 100, 0, 1);
            }
        }

        bHideLine_ = false;
    }
    else
    {
        qDebug() << "不是你处理的事件....";
    }
}

void GraphicsItermGroup::slotSetHandlesChildEvents(bool enable)
{
    qDebug() << "setHandlesChildEvents  " << enable;
    this->setHandlesChildEvents(enable);
}

void GraphicsItermGroup::slotMousePressedOffset(const QPointF &offset)
{
    offsetMouseToLeftTop_ = offset;
}

void GraphicsItermGroup::slotOldPoint(const QPointF &oldPos)
{
    oldPos_ = oldPos;
}

void GraphicsItermGroup::slotDeleteItem(const QString &name)
{
    //Q_UNUSED(name)
    if(name == this->getRootName())
    {
        qDebug() << "这里被调用几次?" << name;

        deleteGroupItem();

        if(pScene_)
        {
            pScene_.data()->deleteGraphicsGroup(this, name);
        }

		recoverLinePath();
        this->deleteLater();
    }
}

/*!
 * \brief 在Group中删除链接到自身的线(连接到自身, 被自身挡住所绕开)
 * \param p 线的指针
 */
void GraphicsItermGroup::slotDeleteLine(FlowLine *p)
{
	list_connect_self_line_.removeAll(p);
	list_recover_line_.removeAll(p);
}

//删除group的item和line
void GraphicsItermGroup::deleteGroupItem()
{
    //删除group中有的模块
    if(!list_item_self_.isEmpty())
    {
        foreach (GraphicsItemBase *p, list_item_self_)
        {
            //Scene记录模块的hash表中删除

            pScene_.data()->deleteItem(p->data(ITEM_NAME).toString());
            removeFromGroup(p);
            p->deleteLater();
        }
        list_item_self_.clear();
    }
    //删除group中有的线
    if(!list_connect_self_line_.isEmpty())
    {
        qDebug() << "要删除几根线呢?" <<list_connect_self_line_.size();
        foreach (FlowLine *p, list_connect_self_line_)
        {
            p->deleteLine();
        }
        list_connect_self_line_.clear();
    }
}

void GraphicsItermGroup::initSetting()
{
    this->setFlag(QGraphicsItem::ItemIsMovable);
    this->setAcceptHoverEvents(true);
    this->setHandlesChildEvents(false);
}

void GraphicsItermGroup::initData()
{
    this->setData(Qt::UserRole+4, "group");
    countParmaeterIn_ = 0;
    countParmaeterOut_ = 0;
    countBehaviorIn_ = 0;
    countBehaviorOut_ = 0;
	this->setZValue(10000);
}

void GraphicsItermGroup::addAnimation(int x, int y)
{
    QPropertyAnimation *pAnimation = new QPropertyAnimation(this, "pos");
    pAnimation->setEasingCurve(QEasingCurve::OutCubic);
    pAnimation->setDuration(200);
    pAnimation->setStartValue(this->pos());
    pAnimation->setEndValue(QPointF(x,y));
    pAnimation->start(QAbstractAnimation::DeleteWhenStopped);
}

void GraphicsItermGroup::findCollideLine()
{
    foreach (QGraphicsItem *p, this->collidingItems())
    {
        if(p->data(Qt::UserRole+4).toString() == "line")
        {
            qDebug() << "fuck这是线啊";
            FlowLine *pLine = static_cast<FlowLine *>(p);
            if(!list_recover_line_.contains(pLine)
                    && !list_connect_self_line_.contains(pLine))
            {
                list_recover_line_.append(pLine);
                connect(pLine, SIGNAL(signalDeleteLine(FlowLine*)), this, SLOT(slotDeleteLine(FlowLine*)));
            }
            //这里可能会有效率问题, 如果出现了的话就在这里排除是自身连接的线
            if(!list_connect_self_line_.contains(pLine))
            {
                qDebug() << "达到料想的排除效果了";
                pLine->slotEndItemMoveOffset(QPointF(0, 0));
            }
            else
            {
                qDebug() << "碰撞检测中没有可以排除连接自身的线";
            }
        }
        else
        {
            qDebug() << p->data(Qt::UserRole+4).toString();
        }
    }
}

void GraphicsItermGroup::recoverLinePath()
{
    qDebug() <<"要还原的线有那么多" << list_recover_line_.size();
    foreach (FlowLine *line, list_recover_line_)
    {
        line->slotEndItemMoveOffset(QPointF(0, 0));
    }
    list_recover_line_.clear();
}
