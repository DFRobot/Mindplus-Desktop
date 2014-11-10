#ifndef CURVEPROGRESSIONWIDGET_H
#define CURVEPROGRESSIONWIDGET_H

#include <QWidget>

class CurveProgressionWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CurveProgressionWidget(QWidget *parent = 0);

    int pointNumber_;
    int currentPointIndex_;
    QPoint points_[99];
    QList<QPoint *> pointList_;
    QList<float> pointsDataX_;
    QList<float> pointsDataY_;

    int bound_;
    int redPointSize_;
    int whitePointSize_;

    
signals:
    
public slots:
    
private:


protected:
    void paintEvent(QPaintEvent *event);
};

#endif // CURVEPROGRESSIONWIDGET_H
