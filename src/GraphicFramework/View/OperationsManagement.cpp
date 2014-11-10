#include "OperationsManagement.h"
#include <QScrollBar>
#include <QTouchEvent>
#include <QWheelEvent>
#include <QDebug>
#include <QApplication>

//#include <QtOpenGL/QGLWidget>

OperationsManagement::OperationsManagement(QGraphicsScene *scene, QWidget *parent) :
    QGraphicsView(scene, parent), totalScaleFactor_(1)
{
    this->initSetting();
}

bool OperationsManagement::viewportEvent(QEvent *event)
{
    if(event->type() == QEvent::TouchBegin || QEvent::TouchUpdate == event->type() || event->type() == QEvent::TouchEnd)
    {
        QTouchEvent *touchEvent = static_cast<QTouchEvent *>(event);

        QList<QTouchEvent::TouchPoint> touchPoints = touchEvent->touchPoints();

        if (touchPoints.count() == 2)
        {
            // determine scale factor
            const QTouchEvent::TouchPoint &touchPoint0 = touchPoints.first();
            const QTouchEvent::TouchPoint &touchPoint1 = touchPoints.last();
            qreal currentScaleFactor = QLineF(touchPoint0.pos(), touchPoint1.pos()).length()  / QLineF(touchPoint0.startPos(), touchPoint1.startPos()).length();

            if (touchEvent->touchPointStates() & Qt::TouchPointReleased)
            {
                // if one of the fingers is released, remember the current scale
                // factor so that adding another finger later will continue zooming
                // by adding new scale factor to the existing remembered value.
                totalScaleFactor_ *= currentScaleFactor;

                currentScaleFactor = 1;
            }
            setTransform(QTransform().scale(totalScaleFactor_ * currentScaleFactor, totalScaleFactor_ * currentScaleFactor));
        }
		//return true;
    }
    else if(event->type() == QEvent::Wheel)
    {
        if(QApplication::keyboardModifiers () == Qt::ControlModifier)
        {
            qDebug() << "ctrl + 滚轮";
            QWheelEvent *e = static_cast<QWheelEvent *>(event);

            int numDegrees = e->delta() / 8;
            int numSteps = numDegrees / 15;

            if(numSteps >= 0)
            {
                qDebug() << "扩大";
                totalScaleFactor_ *= 1.1;
                setTransform(QTransform().scale(totalScaleFactor_, totalScaleFactor_));
            }
            else
            {
                qDebug() << "缩小";
                totalScaleFactor_ *= 0.9090909090909091;                // 10 / 11
                setTransform(QTransform().scale(totalScaleFactor_, totalScaleFactor_));
            }
			Q_EMIT signalViewScale(totalScaleFactor_);
        }
		else
		{
			event->accept();
			return true;
		}
    }
    return QGraphicsView::viewportEvent(event);
}

void OperationsManagement::initSetting()
{
    //接受触摸
    viewport()->setAttribute(Qt::WA_AcceptTouchEvents);
    //开启抗锯齿
    //this->setRenderHint(QPainter::Antialiasing, true);
    //开启缓存背景, 加速渲染速度 有用么?
    this->setCacheMode(CacheBackground);

	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	//this->setViewport(new QGLWidget(QGLFormat(QGL::SampleBuffers)));
	//this->setResizeAnchor(QGraphicsView::AnchorViewCenter);
	//this->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
	//this->setViewport(new QGLWidget(QGLFormat(QGL::DepthBuffer)));
    //    this->setDragMode(QGraphicsView::RubberBandDrag);
    //    this->setOptimizationFlags(QGraphicsView::DontSavePainterState);
    //    this->setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
    //    this->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    // setDragMode(ScrollHandDrag);
    //this->setMouseTracking(true);
}
