#include "PushButtonBlock.h"
#include <QDebug>
#include <QPainter>
#include <QFontDatabase>
#include <QStyleOption>
#include "Animation.h"
#include "CustomFont.h"

PushButtonBlock::PushButtonBlock(QWidget *parent)
    : QPushButton(parent)
    , name_("")
    , posDuration_(0)
    , opacityDuration_(0)
    , startPos_(0, 0)
    , endPos_(0, 0)
    , parentHeight_(0)
{
    initData();
    initOpacity();
    setOpacity(0);
}

void PushButtonBlock::paintEvent(QPaintEvent *event)
{
    QPushButton::paintEvent(event);

    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

    QPainter painter(this);
    painter.setPen(QPen(QColor(255, 255, 255)));

    parentHeight_ = parentWidget()->parentWidget()->height();

    if(675 < parentHeight_
            && 700 > parentHeight_ )
    {
        font_.setPointSize(9);
        painter.setFont(font_);
        painter.drawText(6, 110, name_);
    }
    else if(700 < parentHeight_
            && 800 > parentHeight_)
    {
        font_.setPointSize(11);
        painter.setFont(font_);
        painter.drawText(this->size().width()*0.05, this->size().height()*0.75, name_);
    }
    else if(950 < parentHeight_
            && 1100 > parentHeight_)
    {
        font_.setPointSize(15);
        painter.setFont(font_);
        painter.drawText(12, 180, name_);
    }
    else if(1280 < parentHeight_)
    {
        font_.setPointSize(19);
        painter.setFont(font_);
        painter.drawText(16, 210, name_);
    }
}

void PushButtonBlock::initData()
{
	//font_ = CustomFont::getCustomFont("msyh.ttc");
}

void PushButtonBlock::setOpacity(qreal opactiy)
{
    opactiy_ = opactiy;
    pGraphicsOpacityEffect_->setOpacity(opactiy_);
}

void PushButtonBlock::initOpacity()
{
    pGraphicsOpacityEffect_ = new QGraphicsOpacityEffect(this);
    opactiy_ = 0;   //刚开始就是不透明的
    pGraphicsOpacityEffect_->setOpacity(opactiy_);
    this->setGraphicsEffect(pGraphicsOpacityEffect_);
}
