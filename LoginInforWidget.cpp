#include "LoginInforWidget.h"
#include <QPainter>
LoginInforWidget::LoginInforWidget(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    labelName->setStyleSheet("color: rgb(255, 255, 255);");
    labelImage->setStyleSheet("border-image: url(:/resource/images/left_area/LeftToolBar_user.png);");
}

void LoginInforWidget::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
        case QEvent::LanguageChange:
            retranslateUi(this);
            break;
        default:
			break;
    }
}

void LoginInforWidget::paintEvent(QPaintEvent *event)
{
    //Q_UNUSED(event);
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(event);
}

void LoginInforWidget::enterEvent(QEvent *event)
{
    Q_UNUSED(event);
    labelName->setStyleSheet("color: rgb(73, 160, 193);");
    labelImage->setStyleSheet("border-image: url(:/resource/images/left_area/LeftToolBar_user_OVER.png);");
}

void LoginInforWidget::leaveEvent(QEvent *event)
{
    Q_UNUSED(event);
    labelName->setStyleSheet("color: rgb(255, 255, 255);");
    labelImage->setStyleSheet("border-image: url(:/resource/images/left_area/LeftToolBar_user.png);");
}
