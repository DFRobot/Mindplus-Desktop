#include "IntroduceFromRight.h"
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QStyleOption>
#include <QPaintEvent>

IntroduceFromRight::IntroduceFromRight(QWidget *parent) :
    QWidget(parent)
{
}

void IntroduceFromRight::paintEvent(QPaintEvent *event)
{
    //QSS支持
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    //边框
    p.setPen(QPen(QColor(84, 179, 234)));
    p.setBrush(QBrush(QColor(84, 179, 234)));
    p.drawRect(0, 0, 2, this->height());
}
