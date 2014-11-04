#include "WidgetBackgroundRight.h"
#include <QPainter>

WidgetBackgroundRight::WidgetBackgroundRight(QWidget *parent)
	: QWidget(parent)
{
    pImage_ = new QPixmap("./resource/images/left_area/LeftToolBar_Shadow.png");
}

void WidgetBackgroundRight::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, 36, this->height(), *pImage_);
}
