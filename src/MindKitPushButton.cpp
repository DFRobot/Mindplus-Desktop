#include "MindKitPushButton.h"
#include <QDropEvent>
#include <QDebug>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QPainter>
#include <QPen>
#include <QMimeData>
#include <QDrag>
#include <QApplication>

MindKitPushButton::MindKitPushButton(QWidget *parent)
    : QPushButton(parent)
{
}

void MindKitPushButton::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
        dragStartPosition = event->pos();
}

void MindKitPushButton::mouseMoveEvent(QMouseEvent *event)
{
    if (!(event->buttons() & Qt::LeftButton))
        return;
    if ((event->pos() - dragStartPosition).manhattanLength()
            < QApplication::startDragDistance())
        return;

    QMimeData *pMimeData = new QMimeData;
    QDrag *pDrag = new QDrag(this);

    QPixmap pix(170, 28);
    pix.fill(QColor(73, 160, 191));
    QPainter painter(&pix);
    painter.setPen(QPen(QColor(255, 255, 255)));
    painter.drawText(pix.rect(), Qt::AlignCenter, name_);
    pMimeData->setText(name_);
    pDrag->setMimeData(pMimeData);
    pDrag->setPixmap(pix);  //移动中显示的图片

    QPoint offset = QPoint(170/2, 28/2);

    pDrag->setHotSpot(offset);

    emit signalHideMindKit();
    emit signalMindKitPushButtonPointer(this);
    //执行拖放
    pDrag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction);
}
