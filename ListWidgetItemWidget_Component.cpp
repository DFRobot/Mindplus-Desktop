#include "ListWidgetItemWidget_Component.h"
#include <QDebug>
#include <QPainter>
#include <QStyleOption>

ListWidgetItemWidget_Component::ListWidgetItemWidget_Component(const QString &name, QWidget *parent)
    : QWidget(parent)
    , name_(name)
    , bEnableHoverEvent_(false)
{
    setupUi(this);
    this->initGui();
}

void ListWidgetItemWidget_Component::setIntroduceInfor(const QPixmap &image, const QString &text)
{
    image_ = image;
    text_ = text;
}

void ListWidgetItemWidget_Component::changeEvent(QEvent *e)
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

void ListWidgetItemWidget_Component::enterEvent(QEvent *event)
{
    if(bEnableHoverEvent_)
    {
        qDebug() << "enter item";
        emit signalIntroduce(image_, text_);
    }
}

void ListWidgetItemWidget_Component::leaveEvent(QEvent *event)
{
    if(bEnableHoverEvent_)
    {
        qDebug() << "leave item";
    }
}

void ListWidgetItemWidget_Component::initGui()
{
    labelName->setText(name_);
}
