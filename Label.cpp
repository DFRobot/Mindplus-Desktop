#include "Label.h"
#include <QGraphicsOpacityEffect>

Label::Label(QWidget *parent) :
    QLabel(parent)
{
    this->initOpacity();
}

void Label::setOpacity(qreal opactiy)
{
    opactiy_ = opactiy;
    pGraphicsOpacityEffect_->setOpacity(opactiy_);
}

void Label::initOpacity()
{
    pGraphicsOpacityEffect_ = new QGraphicsOpacityEffect(this);
    opactiy_ = 1;   //刚开始就是不透明的
    pGraphicsOpacityEffect_->setOpacity(opactiy_);
    this->setGraphicsEffect(pGraphicsOpacityEffect_);
}
