#ifndef PARAMETERITEM_H
#define PARAMETERITEM_H

#include "GraphicsItemBase.h"
#include <QFontDatabase>
//参数类, 分为参数输入和参数输出
class ParameterItem :public GraphicsItemBase
{
    Q_OBJECT
public:
    explicit ParameterItem(const QRect &rect, const QPixmap &bgImage, QGraphicsItem *parent = 0);
    void setPropertyValue(int id, const QString &name, const QString &itemType, const QString &itemTypeDetail, const QString &value, const QString &type, const QString &typeUi, const QString &imgPath);
    void addMouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    void addWidgetMainPointer(QWidget *p){pWidgetMain_ = p;}

    enum
    {
        Type = UserType + 2
    };
    int type() const
    {
        return Type;
    }

    //返回可用矩形区域
    QRectF boundingRect() const;

    ///////////////公共读写方法
    QString getType() const{ return type_;}
    void setType(const QString &type){ type_ = type;}

    QString getValue() const{ return value_; }
    void setValue(const QString &value);

    QString getImagePath() const { return imagePath_; }
    void setImagePath(const QString &imgPath){ imagePath_ = imgPath;}

    QString getTypeUi() const{ return typeUi_; }
    void setTypeUi(const QString &type){ typeUi_ = type; }

    QPixmap getImage(){ return bgPixmap_; }
    void setImage(const QPixmap &pix){bgPixmap_ = pix;}

    void setHide(bool hide) { bHide_ = hide; }
    bool isHide() { return bHide_; }

signals:
    //用于通知外部数据变更(直接交予scene处理)
    void signalParamValueChange(const QString &type, const QString &newValue, const QString &paramName);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

private slots:
    void slotValueChange(const QString &value);

private:
    void initSetting();
    void initData();

private:
    QString type_;
    QString value_;
    QString imagePath_;
    QString typeUi_;
    QPointF offset_;
    QFont font_;
    QWidget *pWidgetMain_;
    bool mouseOver_;
    bool bHide_;
};

#endif // PARAMETERITEM_H
