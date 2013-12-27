#include "FunctionAreaWidget.h"
#include <QMouseEvent>
#include <QDebug>
#include <QPen>
#include <QPainter>

FunctionAreaWidget::FunctionAreaWidget(QWidget *parent)
    : QWidget(parent)
	, hover_(false)
    , fgImage_()
    , name_("")
{
    setupUi(this);
    this->initSetting();
}

void FunctionAreaWidget::addData(const QPixmap &foreground, const QString &name)
{
    fgImage_ = foreground;
    name_ = name;

    labelName->setText(name_);
	labelName->setScaledContents(false);
	labelImage->setPixmap(fgImage_);
}

void FunctionAreaWidget::setImage(const QPixmap &image)
{
    labelImage->setPixmap(image);
}

void FunctionAreaWidget::setName(const QString &name)
{
    labelName->setText(name);
}

void FunctionAreaWidget::changeEvent(QEvent *e)
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

void FunctionAreaWidget::paintEvent(QPaintEvent *event)
{
	if(hover_)
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

void FunctionAreaWidget::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    //变颜色加入对事件的响应
	hover_ = false;
	update();
    emit signalClick();
}

void FunctionAreaWidget::enterEvent(QEvent *)
{
	hover_ = true;
	update();
}

void FunctionAreaWidget::leaveEvent(QEvent *)
{
	hover_ = false;
	update();
}

void FunctionAreaWidget::initSetting()
{
    this->setMouseTracking(true);
}
