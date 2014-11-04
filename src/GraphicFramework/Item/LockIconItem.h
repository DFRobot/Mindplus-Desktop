#ifndef LOCKICONITEM_H
#define LOCKICONITEM_H
#include "GraphicsItemBase.h"

class LockIconItem : public GraphicsItemBase
{
public:
    LockIconItem(const QRect &rect, const QPixmap &bgImage, QGraphicsItem *parent = 0);

    void setRect(const QRect &rect);
    void setRePoint(const QPoint &pos);
    QPoint getRePoint(){return point_;}

    enum
    {
        Type = UserType + 1
    };
    int type() const
    {
        return Type;
    }
    //返回可用矩形区域
    QRectF boundingRect() const;
    void addEndItem(GraphicsItemBase *p) {pEndItem_ = p;}
    GraphicsItemBase *getEndItem() {return pEndItem_;}

signals:

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    void initData();

private:
    GraphicsItemBase *pEndItem_;
    QPoint point_;
	int timerId_;
};

#endif // LOCKICONITEM_H
