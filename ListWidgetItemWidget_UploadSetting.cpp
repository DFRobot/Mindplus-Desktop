#include "ListWidgetItemWidget_UploadSetting.h"
#include <QMouseEvent>
#include <QDebug>
#include <QPainter>

ListWidgetItemWidget_UploadSetting::ListWidgetItemWidget_UploadSetting(const QString &name, QWidget *parent)
    : QWidget(parent)
    , bClicked_(false)
{
    if(name.contains("_"))
    {
        name_ = name.split("_")[0];
        type_ = name.split("_")[1];
    }
    else
    {
        name_ = name;
        type_ = "";
    }

    setupUi(this);
    setMouseTracking(true);
}

void ListWidgetItemWidget_UploadSetting::setText(const QString &text)
{
    labelName->setText(text);
}

void ListWidgetItemWidget_UploadSetting::setText()
{
    labelName->setText(name_);
}

void ListWidgetItemWidget_UploadSetting::setClicked(bool click)
{
    bClicked_ = click;
    update();
}

void ListWidgetItemWidget_UploadSetting::setColor(const QColor &color)
{
    QPixmap pix(labelName->size());
    pix.fill(color);
    labelName->setPixmap(pix);
}

void ListWidgetItemWidget_UploadSetting::changeEvent(QEvent *e)
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

void ListWidgetItemWidget_UploadSetting::paintEvent(QPaintEvent */*event*/)
{
    //    QWidget::paintEvent(event);
    //    QStyleOption opt;
    //    opt.init(this);
    //    QPainter p(this);
    //    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

    QPainter painter(this);
    if(bClicked_)
    {
        painter.setPen(QPen(QColor(82, 164, 225)));
        painter.setBrush(QBrush(QColor(82, 164, 225)));
        painter.drawRect(this->rect());
        painter.setPen(QPen(QColor(255,255,255)));

        if(!type_.isEmpty())
        {
			painter.drawText(this->rect(),Qt::AlignLeft|Qt::AlignVCenter,name_ + " " + type_);
        }
        else
        {
			painter.drawText(this->rect(),Qt::AlignLeft|Qt::AlignVCenter,name_);
        }
    }
    else
    {
        painter.setPen(QPen(QColor(255, 255, 255)));
        painter.setBrush(QBrush(QColor(255, 255, 255)));
        painter.drawRect(this->rect());
        painter.setPen(QPen(QColor(0,0,0)));
        if(!type_.isEmpty())
        {
			painter.drawText(this->rect(),Qt::AlignLeft|Qt::AlignVCenter,name_ + " " + type_);
        }
        else
        {
			painter.drawText(this->rect(),Qt::AlignLeft|Qt::AlignVCenter,name_);
        }
    }
}
