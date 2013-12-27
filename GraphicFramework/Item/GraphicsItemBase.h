#ifndef GRAPHICSITEMBASE_H
#define GRAPHICSITEMBASE_H

#include <QGraphicsObject>

//UserRole, 别拿书本上的条条框框来喷这样怎么怎么不好, 擦,哥哥是故意暴露给其他地方用的
int const ITEM_TYPE = Qt::UserRole + 4;                        //类型(parma, behavior, root)
int const ITEM_NAME = Qt::UserRole + 5;                     //全名
int const ITEM_SIZE_X = Qt::UserRole + 6;
int const ITEM_SIZE_Y = Qt::UserRole + 7;
int const ITEM_TYPE_DETAIL = Qt::UserRole + 8;        //详细类型(parameterIn, parameterOut, BehaviorIn, BehaviorOut, root)

class QGraphicsOpacityEffect;

class GraphicsItemBase : public QGraphicsObject
{
    Q_OBJECT

public:
    explicit GraphicsItemBase(const QRect &rect, const QPixmap &bgImage, QGraphicsItem *parent = 0);

    void setPropertyValue(int id, const QString &name, const QString &itemType, const QString &itemTypeDetail);
    void addKeyEvent(QKeyEvent *event);
    //公共读写的方法
    void setId(int i){id_ = i;}
    int getId() const {return id_;}

    void setRect(const QRect &rect) {bgRect_ = rect;}
    QRect getRect() const ;

    void setPixmap(const QPixmap &image) {bgPixmap_ = image;}
    QPixmap getPixmap() const {return bgPixmap_;}

    void setName(const QString &name) {name_ = name;}
    QString getName() const {return name_;}

    int getWidth() const {return bgRect_.width();}
    int getheight() const {return bgRect_.height();}

    QPoint getCenterPoint();

    //寻路终点
    void setFindPathPointOffset(const QPoint &offset);
    QPoint getFindPathPoint() const;
    QPoint getFindPathPointOffset() const;
    //路径终点(寻路终点后再加一个点)
    void setFindPathPointEndOffset(const QPoint &offset);
    QPoint getFindPathPointEnd() const;
    QPoint getFindPathPointEndOffset() const;

    void setItemType(const QString &type) {itemType_ = type;}
    QString getItemType() {return itemType_;}

    void setItemTypeDetail(const QString &type) {itemType_ = type;}
    QString getItemTypeDetail() {return itemTypeDetail_;}

    Q_PROPERTY(QPointF pos READ pos WRITE setPos FINAL)

    QList<QPoint> list_unkown_point_;

signals:

protected:
    //公开给派生类的属性
    //外观描述
    QRect bgRect_;
    QPixmap bgPixmap_;

    //数据描述
    int id_;
    QString name_;  //全名
    QString itemType_;
    QString itemTypeDetail_;

    //序列帧的计时器, 用序列帧的话效率估计比不上自绘制, 先试试看看效果
    QTimer *pTimer_;

    //寻路用的点
    QPoint findPathPointOffset_;      //终点
    QPoint findPathPointEndOffset_;      //终点
};

#endif // GRAPHICSITEMBASE_H
