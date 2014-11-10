#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include <QListWidget>
#include "DataStruct.h"

class ListWidget : public QListWidget
{
    Q_OBJECT
public:
    explicit ListWidget(QWidget *parent = 0);

protected:
	//void paintEvent(QPaintEvent *event);
	void dropEvent(QDropEvent *event);
	void mousePressEvent(QMouseEvent *event);
};

#endif // LISTWIDGET_H
