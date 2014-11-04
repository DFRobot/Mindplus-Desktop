#include "Animation.h"
#include <QRect>
#include <QPoint>
#include <QVariant>
#include <QParallelAnimationGroup>
#include <QSequentialAnimationGroup>

Animation::Animation(QObject *parent) :
    QObject(parent)
{
}

void Animation::geometryAnimation(QObject *target, int duration, const QRect &start, const QRect &end, QEasingCurve easingCurve)
{
    QPropertyAnimation *p = commonAnimation(target, "geometry", duration, start, end, easingCurve);
    p->start(QAbstractAnimation::DeleteWhenStopped);
}

void Animation::posAnimation(QObject *target, int duration, const QPoint &start, const QPoint &end, QEasingCurve easingCurve)
{
    QPropertyAnimation *p = commonAnimation(target, "pos", duration, start, end, easingCurve);
    p->start(QAbstractAnimation::DeleteWhenStopped);
}

void Animation::opacityAnimation(QObject *target, int duration, int start, int end, QEasingCurve easingCurve)
{
    QPropertyAnimation *p = commonAnimation(target, "opacity", duration, start, end, easingCurve);
    p->start(QAbstractAnimation::DeleteWhenStopped);
}

void Animation::parallelAnimation(QList<QPropertyAnimation *> listPropertyAnimation)
{
    QParallelAnimationGroup group;
    foreach (QPropertyAnimation *p, listPropertyAnimation)
    {
        group.addAnimation(p);
    }
    group.start();
}

void Animation::sequentialAnimation(QList<QPropertyAnimation *> listPropertyAnimation)
{
    QSequentialAnimationGroup group;
    foreach (QPropertyAnimation *p, listPropertyAnimation)
    {
        group.addAnimation(p);
    }
    group.start();
}

QPropertyAnimation * Animation::commonAnimation(QObject *target, const QString &propertyName, int duration, const QVariant &start, const QVariant &end, QEasingCurve easingCurve)
{
	QPropertyAnimation *pAnimation = new QPropertyAnimation(target, propertyName.toUtf8().constData());
    pAnimation->setEasingCurve(easingCurve);
    pAnimation->setDuration(duration);
    pAnimation->setStartValue(start);
    pAnimation->setEndValue(end);
    return pAnimation;
}
