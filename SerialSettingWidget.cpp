#include "SerialSettingWidget.h"
#include <QPainter>
#include <QPen>
#include <QEvent>
#include <QMouseEvent>

SerialSettingWidget::SerialSettingWidget(QWidget *parent)
	: QWidget(parent)
	, bHover_(false)
	, image_("./resource/images/tool_area/TopToolBar_setting.png")
{
	setupUi(this);
	labelImage->setPixmap(image_);
	labelBoard->installEventFilter(this);
	labelImage->installEventFilter(this);
	labelSerial->installEventFilter(this);

	labelBoard->setText("Plase Set Arduino Type");
	labelSerial->setText("Serial Port");
	this->setMouseTracking(true);
	autoAdjustSize();
	this->resize(this->width()+3, this->height());
}

void SerialSettingWidget::setSerialPort(const QString &serialPort)
{
	labelSerial->setText(serialPort);
	autoAdjustSize();
}

QString SerialSettingWidget::getSerialPort() const
{
	return labelSerial->text();
}

void SerialSettingWidget::setBoardType(const QString &boardType)
{
	labelBoard->setText(boardType);
	autoAdjustSize();
}

QString SerialSettingWidget::getBoardType() const
{
	return labelBoard->text();
}

void SerialSettingWidget::changeEvent(QEvent *e)
{
	QWidget::changeEvent(e);
	switch (e->type())
	{
		case QEvent::LanguageChange:
			retranslateUi(this);
			break;
		default:
			break;
	}
}

void SerialSettingWidget::paintEvent(QPaintEvent *event)
{
	if(bHover_)
	{
		QPainter paint(this);
		paint.setPen(QPen(QColor(51,51,51)));
		paint.setBrush(QBrush(QColor(51,51,51)));
		paint.drawRect(this->rect());
	}
	else
	{
		QWidget::paintEvent(event);
	}
}

bool SerialSettingWidget::eventFilter(QObject *target, QEvent *event)
{
	if(labelBoard == target
			|| labelImage == target
			|| labelSerial == target)
	{
		if(QEvent::MouseButtonPress == event->type())
		{
			emit signalClick();
			bHover_ = false;
			update();
			event->accept();
			return true;
		}
//		else if(QEvent::MouseMove == event->type())
//		{
//			bHover_ = true;
//			update();
//			event->accept();
//			return true;
//		}
		else
		{
			event->ignore();
			return false;
		}
	}
	else
	{
		event->ignore();
		return false;
	}
}

void SerialSettingWidget::enterEvent(QEvent *)
{
	bHover_ = true;
	update();
}

void SerialSettingWidget::leaveEvent(QEvent *)
{
	bHover_ = false;
	update();
}

void SerialSettingWidget::mousePressEvent(QMouseEvent *)
{
	bHover_ = false;
	update();
	emit signalClick();
}

void SerialSettingWidget::mouseMoveEvent(QMouseEvent *event)
{
	bHover_ = true;
	update();
	event->accept();
}

void SerialSettingWidget::autoAdjustSize()
{
	int lenBefore = labelBoard->width() > labelSerial->width() ? labelBoard->width() : labelSerial->width();

	labelBoard->adjustSize();
	labelSerial->adjustSize();
	int lenCurrent = labelBoard->width() > labelSerial->width() ? labelBoard->width() : labelSerial->width();

	this->resize(width()+lenCurrent-lenBefore+5, height());
}
