#ifndef WIDGETFORLISTWIDGETBEGIN_H
#define WIDGETFORLISTWIDGETBEGIN_H

#include "ui_WidgetForListWidgetBegin.h"

class WidgetForListWidgetBegin : public QWidget, private Ui::WidgetForListWidgetBegin
{
	Q_OBJECT
	
public:
	explicit WidgetForListWidgetBegin(const QString &name, const QString &type, const QPixmap &image, QWidget *parent = 0);
	QString getName() {return labelText->text();}
	QString getType() {return labelType->text();}
	QPixmap getImage() {return *labelImage->pixmap();}

protected:
	void changeEvent(QEvent *e);
};

#endif // WIDGETFORLISTWIDGETBEGIN_H
