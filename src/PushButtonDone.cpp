#include "PushButtonDone.h"
#include <QPainter>
#include <QStyleOption>
#include <QGraphicsOpacityEffect>

PushButtonDone::PushButtonDone(QWidget *parent)
    : QPushButton(parent)
    , pGraphicsOpacityEffect_(NULL)
    , opactiy_(1)
    , text_("Done")
{
    this->initOpacity();
}

void PushButtonDone::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

    if("Cancel" == text_)
    {
        QFont font = p.font();
        font.setPointSize(24);
        p.setFont(font);
    }

    p.drawText(QPoint(9, 65), text_);
}

void PushButtonDone::setOpacity(qreal opactiy)
{
    opactiy_ = opactiy;
    pGraphicsOpacityEffect_->setOpacity(opactiy_);
    emit signalOpacityChage();
}

void PushButtonDone::setText(const QString &text)
{
    text_ = text;
    QPushButton::setText(text);
}

void PushButtonDone::initOpacity()
{
    pGraphicsOpacityEffect_ = new QGraphicsOpacityEffect(this);
    opactiy_ = 1;   //刚开始就是不透明的
    this->setGraphicsEffect(pGraphicsOpacityEffect_);
}
