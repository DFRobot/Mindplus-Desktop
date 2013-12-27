#ifndef PUSHBUTTONBASE_H
#define PUSHBUTTONBASE_H

#include <QPushButton>
class QGraphicsOpacityEffect;

class PushButtonBase : public QPushButton
{
    Q_OBJECT
public:
    explicit PushButtonBase(QWidget *parent = 0);
    void setName(const QString &name) { name_ = name; }
    void setImage(const QPixmap &image, const QRect ){ image_ = image; }
    void setText(const QString &text){ text_ = text; }
    void setTextRotate(qreal rotate){ textTransform_ = textTransform_.rotate(rotate); }
    void setTextScale(qreal sx, qreal sy){ textTransform_ = textTransform_.scale(sx, sy); }
    void setTextTranslate(qreal dx, qreal dy){ textTransform_ = textTransform_.translate(dx, dy); }
    Q_PROPERTY(qreal opacity READ opacity WRITE setOpacity NOTIFY signalOpacityChage FINAL)
    void setOpacity(qreal opactiy);

signals:
    void signalOpacityChage();

public slots:

protected:
    //重载事件
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

    //自定义的function
    qreal opacity() const{return opactiy_;}
    void initOpacity();

protected:
    //动画效果相关, 主要是透明度
    QGraphicsOpacityEffect *pGraphicsOpacityEffect_;
    qreal opactiy_;

    //paint, 也就是显示相关
    QPixmap image_;
    QString text_;//控件显示的text
    QTransform textTransform_;
    QFont font_;

    //拖拽相关
    QString name_;//对应控件的名字
    QPoint dragStartPosition;
};

#endif // PUSHBUTTONBASE_H
