#ifndef ROOTITEM_H
#define ROOTITEM_H

#include "GraphicsItemBase.h"
#include <QFontDatabase>

class BackgroupItem;

class RootItem :public GraphicsItemBase
{
    Q_OBJECT
public:
    explicit RootItem(const QString &str, const QRect &rect, const QPixmap &bgImage, QGraphicsItem *parent = 0);
    void setPropertyValue(const QString &name, const QString &itemType, const QString &itemTypeDetail, int x, int y, const QString &type, const QString &tag, int doubleType, int x2, int y2);

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
    //精确的返回边缘路径

    //公共读写方法
    QString getName() const{ return name_; }
    void setName(const QString &name){ name_ = name;}

    QPoint getNameOffsetPos(){ return QPoint(nameOffsetX, nameOffsetY);}
    void setNameOffsetPos(const QPoint &pos){ nameOffsetX = pos.x(); nameOffsetY = pos.y(); }

    QSize getSize() const {return QSize(sizeX_, sizeY_);}
    void setSize(const QSize &size){sizeX_ = size.width(); sizeY_ = size.height();}
    void setSize(int width, int height){sizeX_ = width; sizeY_ = height;}

    QString getType() const{ return type_;}
    void setType(const QString &type){ type_ = type;}

    QString getTag() const{ return tag_; }
    void setTag(const QString &tag){ tag_ = tag;}

    int getDoubleClickType() const{return doubleType_;}
    void setDoubleClickType(int type){ doubleType_ = type; }

    QPoint getImageOffset() const {return QPoint(imageOffsetX, imageOffsetY);}
    void setImageOffset(int x, int y) {imageOffsetX = x; imageOffsetY = y;}
    void setImageOffset(const QPoint &point){imageOffsetX = point.x(); imageOffsetY = point.y();}

    void setImage(const QPixmap &pix) {image_ = pix;}
    QPixmap getImage() {return image_;}

signals:
    void signalDeleteItem(const QString &name);
    void signalSetHandlesChildEvents(bool enable);
    void signalMousePressedOffset(const QPointF &offset);
    void signalOldPoint(const QPointF &oldPos);

	void signalFocusInGroup(const QString &name);

public slots:

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    //对外通知鼠标相对group坐标系的偏移的
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    //移动之前group处于不接受所有事件的状态, 移动距离超过manhattan距离的时候, group接收所有事件
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    //移动释放的时候group从新设置为不接收所有事件的状态, 在这里设置是不行的 因为已经由group来接管事件的处理了
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);

    void focusInEvent(QFocusEvent *event);

private:
    void initSetting();
    void initData();

private:
    //这两个应该是根据参数来确定
    int sizeX_;
    int sizeY_;
    QString string_;

    //数据描述
    int nameOffsetX;
    int nameOffsetY;
    QString type_;                    //这个是做嘛的?
    QString tag_;             //是精确匹配还是模糊?
    //bool bbVisible_; 这里不需要
    int doubleType_;
    int imageOffsetX;
    int imageOffsetY;

    QPointF posStart_;
    QPointF offset_;
    QPointF offsetSelf_;
    QFont font_;

    QPoint pressStartPosition_;

    //自定义图案
    QPixmap image_;             //图案
    QPoint imageOffset_;    //偏移
    int pixelsWide_ ;
    int pixelsHigh_ ;
};

#endif // ROOTITEM_H
