#ifndef LABEL_H
#define LABEL_H

#include <QLabel>
class QGraphicsOpacityEffect;

class Label : public QLabel
{
    Q_OBJECT
public:
    explicit Label(QWidget *parent = 0);
    Q_PROPERTY(qreal opacity READ opacity WRITE setOpacity FINAL)
    void setOpacity(qreal opactiy);
	qreal opacity() const{return opactiy_;}

signals:

public slots:

    void initOpacity();

protected:
    QGraphicsOpacityEffect *pGraphicsOpacityEffect_;
    qreal opactiy_;
};

#endif // LABEL_H
