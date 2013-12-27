#ifndef SERIALSETTINGWIDGET_H
#define SERIALSETTINGWIDGET_H

#include "ui_SerialSettingWidget.h"

class SerialSettingWidget : public QWidget, private Ui::SerialSettingWidget
{
	Q_OBJECT
	
public:
	explicit SerialSettingWidget(QWidget *parent = 0);

	void setSerialPort(const QString &serialPort);
	QString getSerialPort() const;
	void setBoardType(const QString &boardType);
	QString getBoardType() const;

signals:
	void signalClick();

protected:
	void changeEvent(QEvent *e);
	void paintEvent(QPaintEvent *event);
	bool eventFilter(QObject *target, QEvent *event);
	void enterEvent(QEvent *);
	void leaveEvent(QEvent *);
	void mousePressEvent(QMouseEvent *);
	void mouseMoveEvent(QMouseEvent *event);

private:
	void autoAdjustSize();

private:
	bool bHover_;
	QPixmap image_;
};

#endif // SERIALSETTINGWIDGET_H
