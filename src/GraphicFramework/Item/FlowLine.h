#ifndef FLOWLINE_H
#define FLOWLINE_H

#include <QGraphicsLineItem>
#include <QPointer>
#include "GraphicFramework/Item/GraphicsItemBase.h"

QT_BEGIN_NAMESPACE
class QGraphicsPolygonItem;
class QGraphicsLineItem;
class QGraphicsScene;
class QRectF;
class QGraphicsSceneMouseEvent;
class QPainterPath;
class QGraphicsOpacityEffect;
QT_END_NAMESPACE

class FlowLine : public QObject, public QGraphicsPathItem
{
    Q_OBJECT
public:
	explicit FlowLine(const QPainterPath & path, const QPointF &startPos, const QPointF &endPos,
					  QString name = "", QColor color = Qt::red, QGraphicsItem * parent = 0);
	explicit FlowLine(const QPainterPath & path, GraphicsItemBase *pStartItem,
					  GraphicsItemBase *pEndItem,QColor color = Qt::red, QGraphicsItem * parent = 0);

    enum { Type = UserType + 10 };
    int type() const { return Type; }
    //返回图形的有效矩形区域
    QRectF boundingRect() const;
    //返回图形更为精确的区域->为了更好的实现碰撞检测
    QPainterPath shape() const;
    //为了删除线的时候清空数据库中数据所用
    void setBothendsName(const QString &start, const QString &end)
    {
        startName_ = start;
        endName_ = end;
        name_ = startName_+endName_;
    }
    QString getName() const { return name_; }
    void setName(const QString &name) {name_ = name;}
    void setLinePath(const QPainterPath &path);
    QPainterPath getLinePath(){return path_;}
    void deleteLine();
    //透明渐变效果相关
    Q_PROPERTY(qreal opacity READ opacity WRITE setOpacity FINAL)
    void setOpacity(qreal opactiy);

    void sendSelected();

signals:
    void signalDeleteLine(FlowLine *p);
    void signalFocusIn(FlowLine *p, const QString &startName, const QString &endName);

public slots:
    void slotEndItemMoveOffset(const QPointF &offset);
    void slotStartItemMoveOffset(const QPointF &offset);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
    void timerEvent(QTimerEvent *event);

	/**
	 * @brief keyPressEvent 重载键盘事件,为了响应delete按键
	 * @param event
	 */
    void keyPressEvent(QKeyEvent *event);

    //自定义的function
    qreal opacity() const{return opactiy_;}
    void initOpacity();

private slots:

private:
    void initSetting();
    void initData();

private:
    QPointer<GraphicsItemBase> pStartItem_;
    QPointer<GraphicsItemBase> pEndItem_;
    QString name_;
    QString startName_;
    QString endName_;
    QPointF startPos_;
    QPointF endPos_;
    QColor color_;
    qreal dashOffset_;
    QPainterPath path_;
    int timerLock_;
	int timerId_;

    //动画效果相关, 主要是透明度
    QGraphicsOpacityEffect *pGraphicsOpacityEffect_;
    qreal opactiy_;

	//线的拖动
	bool bDrag_;
};

#endif // FLOWLINE_H
