#include "WidgetForListWidgetBegin.h"

WidgetForListWidgetBegin::WidgetForListWidgetBegin(const QString &name, const QString &type,
												   const QPixmap &image, QWidget *parent)
	: QWidget(parent)
{
	setupUi(this);
	labelText->setText(name);
	labelType->setText(type);
	labelImage->setPixmap(image);
}

void WidgetForListWidgetBegin::changeEvent(QEvent *e)
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
