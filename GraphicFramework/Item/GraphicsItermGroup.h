#ifndef GRAPHICSITERMGROUP_H
#define GRAPHICSITERMGROUP_H

#include <QObject>
#include <QGraphicsItemGroup>
#include <QPointer>
class GraphicsItemBase;
class EditScene;
class FlowLine;
class ParameterItem;
class BehaviourItem;

class GraphicsItermGroup : public QObject , public QGraphicsItemGroup
{
    Q_OBJECT
public:
    explicit GraphicsItermGroup(const QRect &rect, int sizeX, int sizeY, EditScene *pScene, QObject *parent = 0);

    //重载个=号好了
    GraphicsItermGroup & operator= (const GraphicsItermGroup &rhs);
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void addMouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void addMouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    QString getRootName() {return rootName_; }

    void addRoot(GraphicsItemBase *p);
    void addParameterIn(GraphicsItemBase *p);
    void addParameterOut(GraphicsItemBase *p);
    void addBehaviorIn(GraphicsItemBase *p);
    void addBehaviorOut(GraphicsItemBase *p);

    QSize getSize() const{ return QSize(rect_.width(), rect_.height()); }
    void setOffsetMousePosToGroupLeftTop(const QPointF &offset);
    void sendGroupCurrentPos();

    void addConnectSelfLine(FlowLine *p);
	/**
	 * @brief GraphicsItermGroup::deleteRecoverLine 删除那些被自己挡住的线的记录
	 * @param p 线的指针
	 */
    void deleteRecoverLine(FlowLine *p);
    void deleteGroupItem();
    void setGroupId(int id){groupId_ = id;}
    int getGroupId() const {return groupId_;}
    //一句话
    Q_PROPERTY(QPointF pos READ pos WRITE setPos FINAL)
    bool isHaveBehaviorOut() { return bHaveBehaviorOut_; }

    //一笔画,所用到的数据结构
    QList<bool> listBehaviourInUse_;
    QList<bool> listBehaviourOutUse_;

    QList<BehaviourItem *>  listBehaviourIn_;
    QList<BehaviourItem *>  listBehaviourOut_;

    QMap<GraphicsItemBase *, int> map_behaviourOutPointer_index_;
    QMap<GraphicsItemBase *, int> map_behaviourInPointer_index_;

	//保存时候的名字
	void setBlockName(const QString &name) { blockName_ = name; }
	QString getBlockName() const { return blockName_; }

signals:
    void signalGroupCurrentPos(const QPointF &offset);

public slots:
    void slotDeleteLine(FlowLine *p);
    void slotOldPoint(const QPointF &oldPos);
    void slotMousePressedOffset(const QPointF &offset);

protected:
    void keyPressEvent(QKeyEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private slots:
    void slotSetHandlesChildEvents(bool enable);
    void slotDeleteItem(const QString &name);

private:
    void initSetting();
    void initData();
    void addAnimation(int x, int y);

	/**
	 * @brief GraphicsItermGroup::findCollideLine 这里会让有碰撞的线重新寻路
	 */
    void findCollideLine();
    void recoverLinePath();

private:
    QRect rect_;
    //root周围的部件统计, 主要用于计算坐标偏移量
    int sizeX_;
    int sizeY_;
    //统计各个item的计数器
    int countParmaeterIn_;
    int countParmaeterOut_;
    int countBehaviorIn_;
    int countBehaviorOut_;
    //一些item的指针
    GraphicsItemBase *pRoot_;
    QList<GraphicsItemBase *> list_item_self_;
    QList<ParameterItem *> list_parameter_;
    QList<BehaviourItem *> list_behavior_;
    QPointF offsetMouseToLeftTop_;
    QPointF oldPos_;

    QPointer<EditScene> pScene_;
    QList<FlowLine *> list_recover_line_;
    QList<FlowLine *> list_connect_self_line_;
    int itemCount_;
    QString rootName_;
    int groupId_;

    //线段判断
    bool bHideLine_;

    bool bHaveBehaviorOut_;
	//保存模块的时候名字相关
	QString blockName_;
};

#endif // GRAPHICSITERMGROUP_H
