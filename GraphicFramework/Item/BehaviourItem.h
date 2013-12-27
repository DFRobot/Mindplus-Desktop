#ifndef BEHAVIOURITEM_H
#define BEHAVIOURITEM_H

#include "GraphicsItemBase.h"

class BehaviourItem :public GraphicsItemBase
{
    Q_OBJECT
public:
    explicit BehaviourItem(const QRect &rect, const QPixmap &bgImage, QGraphicsItem *parent = 0);
    void setPropertyValue(int id, const QString &name, const QString &itemType, const QString &itemTypeDetail, const QString &imagePath);
    enum
    {
        Type = UserType + 3
    };
    int type() const
    {
        return Type;
    }

    //返回可用矩形区域
    QRectF boundingRect() const;

    //公开的读写方法
    QString getImagePath() const { return imagePath_; }
    void setImagePath(const QString &imgPath){ imagePath_ = imgPath;}

    QPixmap getImage(){ return bgPixmap_ ;}
    void setImage(const QPixmap &pix){bgPixmap_ = pix;}

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

private:
    void initSetting();

private:
    QString imagePath_;
	QPointF offset_;
    bool mouseOver_;
};

#endif // BEHAVIOURITEM_H
