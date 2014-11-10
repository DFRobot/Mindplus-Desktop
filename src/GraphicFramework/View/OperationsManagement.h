#ifndef OPERATIONSMANAGEMENT_H
#define OPERATIONSMANAGEMENT_H

#include <QGraphicsView>

class OperationsManagement : public QGraphicsView
{
    Q_OBJECT
public:
    explicit OperationsManagement(QGraphicsScene *scene = 0, QWidget *parent = 0);
    
signals:
	void signalViewScale(qreal Scale);
    
public slots:

protected:
    bool viewportEvent(QEvent *event);

private:
    void initSetting();

private:
    //缩放比例
    qreal totalScaleFactor_;
};

#endif // OPERATIONSMANAGEMENT_H
