#ifndef ANIMATION_H
#define ANIMATION_H

#include <QObject>
#include <QEasingCurve>
#include <QAbstractAnimation>
#include <QPropertyAnimation>

class QRect;
class QPoint;
class QVariant;


class Animation : public QObject
{
    Q_OBJECT
public:
    //好吧暂时就这三个
    static void geometryAnimation(QObject *target, int duration, const QRect &start, const QRect &end, QEasingCurve easingCurve = QEasingCurve::Linear);
    static void posAnimation(QObject *target, int duration, const QPoint &start, const QPoint &end, QEasingCurve easingCurve = QEasingCurve::Linear);
    static void opacityAnimation(QObject *target, int duration, int start,  int end, QEasingCurve easingCurve = QEasingCurve::Linear);
    //提供并行, 和连续动画
    static void parallelAnimation(QList<QPropertyAnimation *> listPropertyAnimation);
    static void sequentialAnimation(QList<QPropertyAnimation *> listPropertyAnimation);
    static QPropertyAnimation *commonAnimation(QObject *target, const QString &propertyName, int duration, const QVariant &start, const QVariant &end, QEasingCurve easingCurve = QEasingCurve::Linear);
signals:

public slots:

protected:
    //不能声明类的对象, 这货只能用静态
    explicit Animation(QObject *parent = 0);
};

#endif // ANIMATION_H
