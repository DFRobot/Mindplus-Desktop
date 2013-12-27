#ifndef PUSHBUTTONDONE_H
#define PUSHBUTTONDONE_H

#include <QPushButton>
class QGraphicsOpacityEffect;

class PushButtonDone : public QPushButton
{
    Q_OBJECT

public:
    explicit PushButtonDone(QWidget *parent = 0);
    Q_PROPERTY(qreal opacity READ opacity WRITE setOpacity NOTIFY signalOpacityChage FINAL)
    void setOpacity(qreal opactiy);
    void setText(const QString &text);

signals:
    void signalOpacityChage();

public slots:

protected:
    void paintEvent(QPaintEvent *);

private:
    qreal opacity() const{return opactiy_;}
    void initOpacity();

private:
    QGraphicsOpacityEffect *pGraphicsOpacityEffect_;
    qreal opactiy_;
    QString text_;
};

#endif // PUSHBUTTONDONE_H
