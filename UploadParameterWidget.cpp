#include "UploadParameterWidget.h"
#include <QPainter>
#include <QPaintEvent>
#include <QStyleOption>

UploadParameterWidget::UploadParameterWidget(QWidget *parent)
	: QWidget(parent)
{
    setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
}

void UploadParameterWidget::setUploadParameter(const QString &type, const QString &serial)
{
    if(!type.isEmpty())
    {
        labelBoard->setText(tr("Arduino Type:") + type);
        labelBoard->adjustSize();
        labelSerial->move(labelBoard->x() + labelBoard->width(), labelBoard->y());
    }
    if(serial.isEmpty())
    {
        labelSerial->setText(tr("Serial Port:") + serial);
    }
}

QString UploadParameterWidget::getBoard() const
{
    return labelBoard->text();
}

QString UploadParameterWidget::getSerial() const
{
    return labelSerial->text();
}

void UploadParameterWidget::changeEvent(QEvent *e)
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

void UploadParameterWidget::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void UploadParameterWidget::enterEvent(QEvent *)
{
    labelBoard->setStyleSheet("color: rgb(73, 160, 193);");
    labelSerial->setStyleSheet("color: rgb(73, 160, 193);");
}

void UploadParameterWidget::leaveEvent(QEvent *)
{
    labelBoard->setStyleSheet("color: rgb(255, 255, 255);");
    labelSerial->setStyleSheet("color: rgb(255, 255, 255);");
}


