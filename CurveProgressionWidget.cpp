#include "CurveProgressionWidget.h"
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QDebug>

CurveProgressionWidget::CurveProgressionWidget(QWidget *parent) :
    QWidget(parent)
{
    bound_ = 5;
	pointNumber_ = 2;
    redPointSize_ = 7;
    whitePointSize_ = 5;
}

void CurveProgressionWidget::paintEvent(QPaintEvent *event)
{
    QPainter paint(this);

    paint.setBrush(QBrush(QColor(48,48,48)));
    QPen pen(QColor(255,255,255,0));

    QRect widgetRect_(this->rect());
    widgetRect_.adjust(bound_,bound_,-bound_,-bound_);
    paint.setPen(pen);

    paint.drawPixmap(0,0,QPixmap("./resource/images/parameter_input/CurveProgression/CurveProgression_BG.png"));
    //Draw Background

    for (int i = 0 ; i < pointList_.size() ; i++){
        points_[i].setX(3+ pointsDataX_.at(i)*(761-7));
        points_[i].setY(3+ (381-7)- pointsDataY_.at(i)*(381-7));
    }
    //get data of point

    pen.setWidthF(1);
    pen.setColor(QColor(255,255,255));
    paint.setPen(pen);
    paint.drawPolyline(points_, pointList_.size());
    //draw line

    for (int i = 0 ; i < pointList_.size() ; i++){
        paint.setPen(QPen(QColor(247,97,105,201)));
        paint.setBrush(QBrush(QColor(247,97,105,201)));
        paint.drawEllipse(points_[i].x() -((redPointSize_-1) /2),points_[i].y() -((redPointSize_-1) /2),redPointSize_,redPointSize_);
        //draw points(Red)

        if (currentPointIndex_ == i){
            paint.setPen(QPen(QColor(255,255,255)));
            paint.setBrush(QBrush(QColor(255,255,255)));
            paint.drawEllipse(points_[i].x() -((whitePointSize_-1) /2),points_[i].y() -((whitePointSize_-1) /2),whitePointSize_,whitePointSize_);
        }
        //draw current point(White)
    }

}
