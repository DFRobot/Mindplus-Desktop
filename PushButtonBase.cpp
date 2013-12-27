#include "PushButtonBase.h"
#include <QGraphicsOpacityEffect>
#include <QPainter>
#include <QDrag>
#include <QMimeData>
#include <QMouseEvent>
#include <QApplication>

PushButtonBase::PushButtonBase(QWidget *parent)
    : QPushButton(parent)
{
    this->initOpacity();
}

void PushButtonBase::setOpacity(qreal opactiy)
{
    opactiy_ = opactiy;
    pGraphicsOpacityEffect_->setOpacity(opactiy_);
    emit signalOpacityChage();
}

void PushButtonBase::initOpacity()
{
    pGraphicsOpacityEffect_ = new QGraphicsOpacityEffect(this);
    opactiy_ = 1.0;   //刚开始就是不透明的
    pGraphicsOpacityEffect_->setOpacity(opactiy_);
    this->setGraphicsEffect(pGraphicsOpacityEffect_);
}

void PushButtonBase::paintEvent(QPaintEvent *)
{
    QPixmap pix = image_;
    QPainter painter(&pix);
    painter.setTransform(textTransform_);
    painter.setFont(font_);
    painter.drawText(this->rect(), text_);
    image_ = pix;

    QPainter paint(this);
    paint.drawPixmap(rect(), image_);
}

//为拖拽做准备
void PushButtonBase::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        dragStartPosition = event->pos();
    }
}

void PushButtonBase::mouseMoveEvent(QMouseEvent *event)
{
    if (!(event->buttons() & Qt::LeftButton))
    {
        return;
    }
    if ((event->pos() - dragStartPosition).manhattanLength()
            < QApplication::startDragDistance())
    {
        return;
    }

    QMimeData *pMimeData = new QMimeData;
    QDrag *pDrag = new QDrag(this);

    pMimeData->setText(name_);
    pDrag->setMimeData(pMimeData);
    pDrag->setPixmap(image_);  //移动中显示的图片
    //拖拽时候鼠标的偏移
    QPoint offset = event->pos();
    pDrag->setHotSpot(event->pos() - offset);
    //执行拖放
    pDrag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction);
}



