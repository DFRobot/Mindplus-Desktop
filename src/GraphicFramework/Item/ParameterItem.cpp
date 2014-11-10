#include "ParameterItem.h"
#include <QPainter>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QMessageBox>
#include <QInputDialog>
#include <QGraphicsScene>
#include <QSettings>

#include "EditScene.h"
#include "Parameter_Integer_Form.h"
#include "Parameter_AnalogPin_Form.h"
#include "Parameter_DigitalPin_Form.h"
#include "Parameter_operator_Form.h"
#include "Parameter_String_Form.h"
#include "Parameter_Time_Form.h"
#include "Parameter_LED8x8_Form.h"
#include "Parameter_CurveProgression_Form.h"
#include "CustomFont.h"

ParameterItem::ParameterItem(const QRect &rect, const QPixmap &bgImage, QGraphicsItem *parent)
    : GraphicsItemBase(rect, bgImage, parent)
    , bHide_(false)
{
    initSetting();
    initData();
}

void ParameterItem::setPropertyValue(int id, const QString &name, const QString &itemType, const QString &itemTypeDetail, const QString &value, const QString &type, const QString &typeUi, const QString &imgPath)
{
    GraphicsItemBase::setPropertyValue(id, name, itemType, itemTypeDetail);
    type_ = type;
    typeUi_ = typeUi;
    value_ = value;
    imagePath_ = imgPath;
}

void ParameterItem::addMouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    this->mouseDoubleClickEvent(event);
}

QRectF ParameterItem::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF(0 + penWidth/2, 0+penWidth/2, bgRect_.width()-penWidth, bgRect_.height()-penWidth);
}

void ParameterItem::setValue(const QString &value)
{
    value_ = value;
    emit signalParamValueChange(type_, value_, name_);
}

void ParameterItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QColor penColor;
    QColor fontColor;
    if (mouseOver_){
        penColor.setRgb(255, 237, 137);
        fontColor.setRgb(0,0,0);
    }else{
        penColor.setRgb(236, 109, 109);
        fontColor.setRgb(255,255,255);
    }

    QPen pen(penColor);
    QBrush brush(penColor);
    painter->setPen(pen);
    painter->setBrush(brush);
    painter->setRenderHint(QPainter::Antialiasing, false);
    if(bHide_)
    {
//        QPointF points[3] = {
//            QPointF(4, 14-9),
//            QPointF(20, 14-9),
//            QPointF(12, 14+20-14),
//        };
        QPointF points[3] = {
            QPointF(38/2 - 12, 14-13),
            QPointF(38/2+12, 14-13),
            QPointF(38/2, 14+20-13),
        };
        painter->setRenderHint(QPainter::Antialiasing, true);
        painter->drawPolygon(points, 3);
    }
    else if(this->data(ITEM_TYPE_DETAIL).toString() == tr("parameterIn"))
    {
        QPen pen(penColor);
        QBrush brush(penColor);
        painter->setFont(font_);
        painter->setPen(pen);
        painter->setBrush(brush);
        painter->setRenderHint(QPainter::Antialiasing, false);

        //painter->drawPixmap(bgRect_, bgPixmap_);
        //矩形
        painter->drawRect(0,0, 38 , 13);//fuck的为毛是这样
        //三角形
        QPointF points[3] = {
            QPointF(38/2 - 12, 14-9),
            QPointF(38/2+12, 14-9),
            QPointF(38/2, 14+20-9),
        };
        painter->setRenderHint(QPainter::Antialiasing, true);
        painter->drawPolygon(points, 3);
        painter->setPen(QPen(fontColor));
        if (typeUi_ == "LED8x8"){
            for (int y = 0 ; y < 8; y ++){
                for (int x = 0 ; x < 8; x ++){

                    if (value_[(y*8+x)+1].digitValue() == 1){
                        painter->setBrush(fontColor);
                        painter->drawPoint(15 + x,2 + y);
                        //painter->drawEllipse(15 + x*1.5,1 + y*1.5,1.5,1.5);
                    }
                }
            }
        }
        else if(typeUi_ == "operator"){
            QString operatorValue = "";

            if (value_ == "0"){
                operatorValue = "=";
            }else if (value_ == "1"){
                operatorValue = "≠";
            }else if (value_ == "2"){
                operatorValue = "<";
            }else if (value_ == "3"){
                operatorValue = "<=";
            }else if (value_ == "4"){
                operatorValue = ">";
            }else if (value_ == "5"){
                operatorValue = ">=";
            }

            painter->drawText(QRect(0, 0, 38, 13), Qt::AlignCenter, operatorValue);
        }else if(typeUi_ == "curve"){
            painter->drawPixmap(5,-1,QPixmap("./resource/images/parameter_input/CurveProgression/CurveProgression_Icon.png"));
        }
        else if(typeUi_ == "String"){
            QString withoutmark = "";
            withoutmark = value_.left(value_.size()-1);
            withoutmark = withoutmark.right(withoutmark.size()-1);

            painter->drawText(QRect(0, 0, 38, 13), Qt::AlignCenter, withoutmark);
        }
        else{
            painter->drawText(QRect(0, 0, 38, 13), Qt::AlignCenter, value_);
        }
    }
    else if(this->data(ITEM_TYPE_DETAIL).toString() == tr("parameterOut"))
    {
        //painter->drawPixmap(bgRect_, bgPixmap_);
        QPointF points[3] = {
            QPointF(4, 14-9),
            QPointF(20, 14-9),
            QPointF(12, 14+20-14),
        };
        painter->setRenderHint(QPainter::Antialiasing, true);
        painter->drawPolygon(points, 3);
    }
}

void ParameterItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    if(typeUi_ == "int")
    {//参数面板
        Parameter_Integer_Form *p = new Parameter_Integer_Form(pWidgetMain_->rect(), pWidgetMain_);
        p->setValue(value_);
        connect(p, SIGNAL(signalValue(QString)), this, SLOT(slotValueChange(QString)));
        p->show();
    }
	else if(typeUi_ == "analogpin"
			|| typeUi_ == "digitalpin")
    {//参数面板
		QSettings settingTmp("./resource/setting.ini", QSettings::IniFormat);
		bool value1 = settingTmp.value("Personal/remember").toBool();
		QString value2 = settingTmp.value("Personal/pinmodule").toString();

		if(true == value1
				&& "mindkit" == value2)
		{
			//显示新的
		}
		else
		{
			if("analogpin"== typeUi_ )
			{
				Parameter_AnalogPin_Form *p = new Parameter_AnalogPin_Form(pWidgetMain_->rect(), pWidgetMain_);
				p->setValue(value_);
				connect(p, SIGNAL(signalValue(QString)), this, SLOT(slotValueChange(QString)));
				p->show();
			}
			else
			{
				Parameter_DigitalPin_Form *p = new Parameter_DigitalPin_Form(pWidgetMain_->rect(), pWidgetMain_);
				p->setValue(value_);
				connect(p, SIGNAL(signalValue(QString)), this, SLOT(slotValueChange(QString)));
				p->show();
			}
		}
    }
    else if(typeUi_ == "operator")
    {//参数面板
        Parameter_operator_Form *p = new Parameter_operator_Form(pWidgetMain_->rect(), pWidgetMain_);
        p->setValue(value_);
        connect(p, SIGNAL(signalValue(QString)), this, SLOT(slotValueChange(QString)));
        p->show();
    }
    else if(typeUi_ == "bool")
    {//双击变值
        if(value_ == "true" || value_ == "1")
        {
            this->setValue("false");
        }
        else if(value_ == "false" || value_ == "0")
        {
            this->setValue("true");
        }
    }
    else if(typeUi_ == "String")
    {//参数面板
        Parameter_String_Form *p = new Parameter_String_Form(pWidgetMain_->rect(), pWidgetMain_);
        p->setValue(value_);
        connect(p, SIGNAL(signalValue(QString)), this, SLOT(slotValueChange(QString)));
        p->show();
    }
    else if(typeUi_ == "time")
    {
        Parameter_Time_Form *p = new Parameter_Time_Form(pWidgetMain_->rect(), pWidgetMain_);
        //好吧这部分现在是预留的
		if(p)
		{
			p->setValue(value_);
			connect(p, SIGNAL(signalValueChange(QString)), this, SLOT(slotValueChange(QString)));
			p->show();
		}
    }

    else if(typeUi_ == "LED8x8")
    {
        Parameter_LED8x8_Form *p = new Parameter_LED8x8_Form(pWidgetMain_->rect(), pWidgetMain_);
        //好吧这部分现在是预留的
        p->setValue(value_);
        connect(p, SIGNAL(signalValueChange(QString)), this, SLOT(slotValueChange(QString)));
        p->show();
    }
    else if(typeUi_ == "curve")
    {
        Parameter_CurveProgression_Form *p = new Parameter_CurveProgression_Form(pWidgetMain_->rect(), pWidgetMain_);
        //好吧这部分现在是预留的
        p->setValue(value_);
        connect(p, SIGNAL(signalValueChange(QString)), this, SLOT(slotValueChange(QString)));
        p->show();
    }

    update();
    qDebug() << "double clicked";
}

void ParameterItem::slotValueChange(const QString &value)
{
    this->setValue(value);
}

void ParameterItem::initSetting()
{
    this->setAcceptHoverEvents(true);
}

void ParameterItem::initData()
{
    mouseOver_ = false;
	//font_ = CustomFont::getCustomFont(tr("msyh.ttc"), 10);
}

void ParameterItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    Q_UNUSED(event);
    mouseOver_ = true;
	update();
}

void ParameterItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    Q_UNUSED(event);
    mouseOver_ = false;
	update();
}
