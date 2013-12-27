#include "BlockMenuWidget.h"
#include <QPainter>
#include <QDebug>
#include <QMouseEvent>

#include "Common.h"

BlockMenuWidget::BlockMenuWidget(const QPixmap &normal, const QPixmap &hover, const QPixmap &pressed, QWidget *parent)
	: QWidget(parent)
	, imageNormal_(normal)
	, imageHover_(hover)
	, imagePressed_(pressed)
	, state_(-1)
{
	setupUi(this);
	labelImage->setPixmap(imageNormal_);
}

void BlockMenuWidget::setImageState(int state)
{
	switch (state)
	{
		case NORMAL:
		{
			labelImage->setPixmap(imageNormal_);
			state_ = NORMAL;
			break;
		}
		case HOVER:
		{
			labelImage->setPixmap(imageHover_);
			state_ = HOVER;
			break;
		}
		case PRESSED:
		{
			labelImage->setPixmap(imagePressed_);
			state_ = PRESSED;
			break;
		}
		default:
			break;
	}
}

void BlockMenuWidget::changeEvent(QEvent *e)
{
	QWidget::changeEvent(e);
	switch (e->type()) {
		case QEvent::LanguageChange:
			retranslateUi(this);
			break;
		default:
			break;
	}
}

//变image
void BlockMenuWidget::enterEvent(QEvent *event)
{
	if(PRESSED != state_)
	{
		state_ = HOVER;
		labelImage->setPixmap(imageHover_);
		//update();
	}
	event->accept();
}

//变image
void BlockMenuWidget::leaveEvent(QEvent *event)
{
	if(PRESSED != state_)
	{
		state_ = NORMAL;
		labelImage->setPixmap(imageNormal_);
	}
	event->accept();
}

void BlockMenuWidget::mousePressEvent(QMouseEvent *event)
{
	state_ = PRESSED;
	labelImage->setPixmap(imagePressed_);
	//update();
	event->ignore();
	qDebug() << "mousePressEvent";
}
