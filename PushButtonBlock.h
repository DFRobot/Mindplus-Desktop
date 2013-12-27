#ifndef PUSHBUTTONBLOCK_H
#define PUSHBUTTONBLOCK_H

#include <QPushButton>
#include <QGraphicsOpacityEffect>

class PushButtonBlock : public QPushButton
{
    Q_OBJECT
public:
    explicit PushButtonBlock(QWidget *parent = 0);
//    Q_PROPERTY(int posDuration READ getPosDuration WRITE setPosDuration FINAL)
//    Q_PROPERTY(int opacityDuration READ getOpacityDuration WRITE setOpacityDuration FINAL)
//    Q_PROPERTY(QPointF startPos READ getStartPos WRITE setStartPos FINAL)
//    Q_PROPERTY(QPointF endPos READ getEndPos WRITE setEndPos FINAL)
//    void setPosDuration(int duration){posDuration_ = duration;}
//    void setOpacityDuration(int duration){opacityDuration_ = duration;}
//    void setStartPos(const QPointF & pos){startPos_ = pos;}
//    void setEndPos(const QPointF & pos){endPos_ = pos;}
//    int getPosDuration() const{return posDuration_;}
//    int getOpacityDuration() const{return opacityDuration_;}
//    QPointF getStartPos() const {return startPos_;}
//    QPointF getEndPos() const{return endPos_;}
    Q_PROPERTY(qreal opacity READ opacity WRITE setOpacity FINAL)
    void setOpacity(qreal opactiy);
    void setName(const QString &name) {name_ = name;}

signals:

public slots:
protected:
    void paintEvent(QPaintEvent * event);

private:
    void initData();
    qreal opacity() const{return opactiy_;}
    void initOpacity();

private:
    QString name_;
    int posDuration_;
    int opacityDuration_;
    QPointF startPos_;
    QPointF endPos_;
    QFont font_;
    QGraphicsOpacityEffect *pGraphicsOpacityEffect_;
    qreal opactiy_;
    int parentHeight_;
};

#endif // PUSHBUTTONBLOCK_H
