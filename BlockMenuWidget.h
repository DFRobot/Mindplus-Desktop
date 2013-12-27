#ifndef BLOCKMENUWIDGET_H
#define BLOCKMENUWIDGET_H

#include "ui_BlockMenuWidget.h"

class BlockMenuWidget : public QWidget, private Ui::BlockMenuWidget
{
	Q_OBJECT
	
public:
	explicit BlockMenuWidget(const QPixmap &normal, const QPixmap &hover, const QPixmap &pressed, QWidget *parent = 0);
	void setImageState(int state);

protected:
	void changeEvent(QEvent *e);
	void enterEvent(QEvent *event);
	void leaveEvent(QEvent *event);
	void mousePressEvent(QMouseEvent *event);

private:
	QPixmap imageNormal_;
	QPixmap imageHover_;
	QPixmap imagePressed_;
	int state_;
};

#endif // BLOCKMENUWIDGET_H
