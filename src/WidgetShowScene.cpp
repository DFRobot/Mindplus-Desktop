#include "WidgetShowScene.h"
#include <QGridLayout>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QDebug>
#include <QResizeEvent>
#include <QPainter>
#include "OperationsManagement.h"
#include "EditScene.h"
#include "ListWidget.h"

WidgetShowScene::WidgetShowScene(QWidget *parent)
	: QWidget(parent)
{
}

void WidgetShowScene::setScenePointer(EditScene *p)
{
	pEditScene_ = p;
	pEditScene_->setItemIndexMethod(QGraphicsScene::NoIndex);

	pView_ = new OperationsManagement(pEditScene_);
	connect(pView_, SIGNAL(signalViewScale(qreal)), pEditScene_, SLOT(slotViewScale(qreal)));
	pView_->setCacheMode(QGraphicsView::CacheBackground);
	pView_->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
	pView_->showMaximized();
	pView_->setFrameShape(QFrame::NoFrame);
	QGridLayout *layout = new QGridLayout;
	layout->addWidget(pView_);
	layout->setSpacing(0);
	layout->setHorizontalSpacing(0);
	layout->setVerticalSpacing(0);
	//这一句看来是有用的
	layout->setMargin(0);
	//也不是这个
	this->setLayout(layout);
}

void WidgetShowScene::showEvent(QShowEvent *event)
{
	qDebug() << "这个时候width: " << this->width() << "height : " << this->height();
	pEditScene_->setSceneRect(0,  0, 4090, 2610);
	pEditScene_->setGridSize(4090, 2610);
	event->accept();
}
