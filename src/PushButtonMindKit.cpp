#include "PushButtonMindKit.h"
#include <QPainter>
#include <QStyleOption>

PushButtonMindKit::PushButtonMindKit(QWidget *parent) :
    QPushButton(parent)
{
}

void PushButtonMindKit::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
