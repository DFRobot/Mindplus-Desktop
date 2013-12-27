#ifndef STARTITEM_H
#define STARTITEM_H

#include "GraphicsItemBase.h"

class StartItem :public GraphicsItemBase
{
    Q_OBJECT
public:
    explicit StartItem(const QRect &rect, const QPixmap &bgImage, QGraphicsItem *parent = 0);
    enum
    {
        Type = UserType + 9
    };
    int type() const
    {
        return Type;
    }

    QRectF boundingRect() const;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // STARTITEM_H
