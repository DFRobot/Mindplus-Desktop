#include "Parameter_DigitalPin_Form.h"
#include <QPainter>
#include <QKeyEvent>
#include <QDebug>
#include <QSettings>

#include "Animation.h"

Parameter_DigitalPin_Form::Parameter_DigitalPin_Form(const QRect rect, QWidget *parent) :
	QWidget(parent)
  , rect_(rect)
{
	setupUi(this);
	initSetting();
	initGui();
}

void Parameter_DigitalPin_Form::setValue(const QString &value)
{
	value_ = value;
	lineEdit->setText(value_);
	switch (value_.toInt()){
		case 0:
			on_DigitalPin_0_clicked();
			break;
		case 1:
			on_DigitalPin_1_clicked();
			break;
		case 2:
			on_DigitalPin_2_clicked();
			break;
		case 3:
			on_DigitalPin_3_clicked();
			break;
		case 4:
			on_DigitalPin_4_clicked();
			break;
		case 5:
			on_DigitalPin_5_clicked();
			break;
		case 6:
			on_DigitalPin_6_clicked();
			break;
		case 7:
			on_DigitalPin_7_clicked();
			break;
		case 8:
			on_DigitalPin_8_clicked();
			break;
		case 9:
			on_DigitalPin_9_clicked();
			break;
		case 10:
			on_DigitalPin_10_clicked();
			break;
		case 11:
			on_DigitalPin_11_clicked();
			break;
		case 12:
			on_DigitalPin_12_clicked();
			break;
		case 13:
			on_DigitalPin_13_clicked();
			break;

	}

}

void Parameter_DigitalPin_Form::changeEvent(QEvent *e)
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

void Parameter_DigitalPin_Form::paintEvent(QPaintEvent *)
{
	QStyleOption opt;
	opt.init(this);
	QPainter p(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

bool Parameter_DigitalPin_Form::eventFilter(QObject *target, QEvent *event)
{
	QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
	if(lineEdit == target  || this == target)
	{
		if(QEvent::KeyPress == event->type())
		{
			if(Qt::Key_Enter == keyEvent->key()
					|| Qt::Key_Return == keyEvent->key())
			{
				this->on_pushButton_clicked();
			}
			else
			{
				return QWidget::eventFilter(target, event);
			}
		}
		else
		{
			return QWidget::eventFilter(target, event);
		}
	}
	else
	{
		return QWidget::eventFilter(target, event);
	}
}

void Parameter_DigitalPin_Form::showEvent(QShowEvent *event)
{
	this->setGeometry(rect_);
}

void Parameter_DigitalPin_Form::initSetting()
{
	//this->setWindowState(Qt::WindowActive);
	lineEdit->installEventFilter(this);
	this->installEventFilter(this);
	lineEdit->setFocus();

	this->setAttribute(Qt::WA_TranslucentBackground, true);
	//恩原来是tool
	this->setWindowFlags(Qt::FramelessWindowHint /*| Qt::Tool*/);
	lineEdit->setValidator(new QDoubleValidator(-32768, 32767, 3));
	connect(lineEdit, SIGNAL(textEdited(QString)), this, SLOT(slotTextEdited(QString)));
	pushButton->setWindowFlags(Qt::FramelessWindowHint);
	pushButton->setAttribute(Qt::WA_TranslucentBackground);
}

void Parameter_DigitalPin_Form::initGui()
{
	this->move(1, 1);
	Animation::opacityAnimation(pushButton, 150, 0, 1, QEasingCurve::OutQuart);
	Animation::posAnimation(pushButton, 150, pushButton->pos() + QPoint(50, 0) , pushButton->pos(), QEasingCurve::OutQuart);
}

void Parameter_DigitalPin_Form::on_pushButton_clicked()
{
	emit signalValue(value_);
	close();
}

void Parameter_DigitalPin_Form::slotTextEdited(const QString &value)
{
	value_ = value;
	if("" == value)
	{
		value_ = "0";
	}
	if(value_.size() > 1)
	{
		if(value_[0] == '.')
		{
			value_.insert(0, "0");
			//qDebug() << "添加0头的情况"<< value_;
		}
		else if(value_[0] == '0' && value_[1] != '.')
		{
			value_.remove(0,1);
			//qDebug() << "删除前面多余0头的情况" << value_;
		}
	}
}

void Parameter_DigitalPin_Form::on_DigitalPin_0_clicked()
{
	DigitalPin_0->setIconSize(QSize(20,37));
	DigitalPin_1->setIconSize(QSize(0,37));
	DigitalPin_2->setIconSize(QSize(0,37));
	DigitalPin_3->setIconSize(QSize(0,37));
	DigitalPin_4->setIconSize(QSize(0,37));
	DigitalPin_5->setIconSize(QSize(0,37));
	DigitalPin_6->setIconSize(QSize(0,37));
	DigitalPin_7->setIconSize(QSize(0,37));
	DigitalPin_8->setIconSize(QSize(0,37));
	DigitalPin_9->setIconSize(QSize(0,37));
	DigitalPin_10->setIconSize(QSize(0,37));
	DigitalPin_11->setIconSize(QSize(0,37));
	DigitalPin_12->setIconSize(QSize(0,37));
	DigitalPin_13->setIconSize(QSize(0,37));

	lineEdit->setText("0");
	value_ = "0";
}

void Parameter_DigitalPin_Form::on_DigitalPin_1_clicked()
{
	DigitalPin_0->setIconSize(QSize(0,37));
	DigitalPin_1->setIconSize(QSize(20,37));
	DigitalPin_2->setIconSize(QSize(0,37));
	DigitalPin_3->setIconSize(QSize(0,37));
	DigitalPin_4->setIconSize(QSize(0,37));
	DigitalPin_5->setIconSize(QSize(0,37));
	DigitalPin_6->setIconSize(QSize(0,37));
	DigitalPin_7->setIconSize(QSize(0,37));
	DigitalPin_8->setIconSize(QSize(0,37));
	DigitalPin_9->setIconSize(QSize(0,37));
	DigitalPin_10->setIconSize(QSize(0,37));
	DigitalPin_11->setIconSize(QSize(0,37));
	DigitalPin_12->setIconSize(QSize(0,37));
	DigitalPin_13->setIconSize(QSize(0,37));

	lineEdit->setText("1");
	value_ = "1";
}

void Parameter_DigitalPin_Form::on_DigitalPin_2_clicked()
{
	DigitalPin_0->setIconSize(QSize(0,37));
	DigitalPin_1->setIconSize(QSize(0,37));
	DigitalPin_2->setIconSize(QSize(20,37));
	DigitalPin_3->setIconSize(QSize(0,37));
	DigitalPin_4->setIconSize(QSize(0,37));
	DigitalPin_5->setIconSize(QSize(0,37));
	DigitalPin_6->setIconSize(QSize(0,37));
	DigitalPin_7->setIconSize(QSize(0,37));
	DigitalPin_8->setIconSize(QSize(0,37));
	DigitalPin_9->setIconSize(QSize(0,37));
	DigitalPin_10->setIconSize(QSize(0,37));
	DigitalPin_11->setIconSize(QSize(0,37));
	DigitalPin_12->setIconSize(QSize(0,37));
	DigitalPin_13->setIconSize(QSize(0,37));

	lineEdit->setText("2");
	value_ = "2";
}

void Parameter_DigitalPin_Form::on_DigitalPin_3_clicked()
{
	DigitalPin_0->setIconSize(QSize(0,37));
	DigitalPin_1->setIconSize(QSize(0,37));
	DigitalPin_2->setIconSize(QSize(0,37));
	DigitalPin_3->setIconSize(QSize(20,37));
	DigitalPin_4->setIconSize(QSize(0,37));
	DigitalPin_5->setIconSize(QSize(0,37));
	DigitalPin_6->setIconSize(QSize(0,37));
	DigitalPin_7->setIconSize(QSize(0,37));
	DigitalPin_8->setIconSize(QSize(0,37));
	DigitalPin_9->setIconSize(QSize(0,37));
	DigitalPin_10->setIconSize(QSize(0,37));
	DigitalPin_11->setIconSize(QSize(0,37));
	DigitalPin_12->setIconSize(QSize(0,37));
	DigitalPin_13->setIconSize(QSize(0,37));

	lineEdit->setText("3");
	value_ = "3";
}

void Parameter_DigitalPin_Form::on_DigitalPin_4_clicked()
{
	DigitalPin_0->setIconSize(QSize(0,37));
	DigitalPin_1->setIconSize(QSize(0,37));
	DigitalPin_2->setIconSize(QSize(0,37));
	DigitalPin_3->setIconSize(QSize(0,37));
	DigitalPin_4->setIconSize(QSize(20,37));
	DigitalPin_5->setIconSize(QSize(0,37));
	DigitalPin_6->setIconSize(QSize(0,37));
	DigitalPin_7->setIconSize(QSize(0,37));
	DigitalPin_8->setIconSize(QSize(0,37));
	DigitalPin_9->setIconSize(QSize(0,37));
	DigitalPin_10->setIconSize(QSize(0,37));
	DigitalPin_11->setIconSize(QSize(0,37));
	DigitalPin_12->setIconSize(QSize(0,37));
	DigitalPin_13->setIconSize(QSize(0,37));

	lineEdit->setText("4");
	value_ = "4";
}

void Parameter_DigitalPin_Form::on_DigitalPin_5_clicked()
{
	DigitalPin_0->setIconSize(QSize(0,37));
	DigitalPin_1->setIconSize(QSize(0,37));
	DigitalPin_2->setIconSize(QSize(0,37));
	DigitalPin_3->setIconSize(QSize(0,37));
	DigitalPin_4->setIconSize(QSize(0,37));
	DigitalPin_5->setIconSize(QSize(20,37));
	DigitalPin_6->setIconSize(QSize(0,37));
	DigitalPin_7->setIconSize(QSize(0,37));
	DigitalPin_8->setIconSize(QSize(0,37));
	DigitalPin_9->setIconSize(QSize(0,37));
	DigitalPin_10->setIconSize(QSize(0,37));
	DigitalPin_11->setIconSize(QSize(0,37));
	DigitalPin_12->setIconSize(QSize(0,37));
	DigitalPin_13->setIconSize(QSize(0,37));

	lineEdit->setText("5");
	value_ = "5";
}

void Parameter_DigitalPin_Form::on_DigitalPin_6_clicked()
{
	DigitalPin_0->setIconSize(QSize(0,37));
	DigitalPin_1->setIconSize(QSize(0,37));
	DigitalPin_2->setIconSize(QSize(0,37));
	DigitalPin_3->setIconSize(QSize(0,37));
	DigitalPin_4->setIconSize(QSize(0,37));
	DigitalPin_5->setIconSize(QSize(0,37));
	DigitalPin_6->setIconSize(QSize(20,37));
	DigitalPin_7->setIconSize(QSize(0,37));
	DigitalPin_8->setIconSize(QSize(0,37));
	DigitalPin_9->setIconSize(QSize(0,37));
	DigitalPin_10->setIconSize(QSize(0,37));
	DigitalPin_11->setIconSize(QSize(0,37));
	DigitalPin_12->setIconSize(QSize(0,37));
	DigitalPin_13->setIconSize(QSize(0,37));

	lineEdit->setText("6");
	value_ = "6";
}
void Parameter_DigitalPin_Form::on_DigitalPin_7_clicked()
{
	DigitalPin_0->setIconSize(QSize(00,37));
	DigitalPin_1->setIconSize(QSize(0,37));
	DigitalPin_2->setIconSize(QSize(0,37));
	DigitalPin_3->setIconSize(QSize(0,37));
	DigitalPin_4->setIconSize(QSize(0,37));
	DigitalPin_5->setIconSize(QSize(0,37));
	DigitalPin_6->setIconSize(QSize(0,37));
	DigitalPin_7->setIconSize(QSize(20,37));
	DigitalPin_8->setIconSize(QSize(0,37));
	DigitalPin_9->setIconSize(QSize(0,37));
	DigitalPin_10->setIconSize(QSize(0,37));
	DigitalPin_11->setIconSize(QSize(0,37));
	DigitalPin_12->setIconSize(QSize(0,37));
	DigitalPin_13->setIconSize(QSize(0,37));

	lineEdit->setText("7");
	value_ = "7";
}
void Parameter_DigitalPin_Form::on_DigitalPin_8_clicked()
{
	DigitalPin_0->setIconSize(QSize(0,37));
	DigitalPin_1->setIconSize(QSize(0,37));
	DigitalPin_2->setIconSize(QSize(0,37));
	DigitalPin_3->setIconSize(QSize(0,37));
	DigitalPin_4->setIconSize(QSize(0,37));
	DigitalPin_5->setIconSize(QSize(0,37));
	DigitalPin_6->setIconSize(QSize(0,37));
	DigitalPin_7->setIconSize(QSize(0,37));
	DigitalPin_8->setIconSize(QSize(20,37));
	DigitalPin_9->setIconSize(QSize(0,37));
	DigitalPin_10->setIconSize(QSize(0,37));
	DigitalPin_11->setIconSize(QSize(0,37));
	DigitalPin_12->setIconSize(QSize(0,37));
	DigitalPin_13->setIconSize(QSize(0,37));

	lineEdit->setText("8");
	value_ = "8";
}
void Parameter_DigitalPin_Form::on_DigitalPin_9_clicked()
{
	DigitalPin_0->setIconSize(QSize(0,37));
	DigitalPin_1->setIconSize(QSize(0,37));
	DigitalPin_2->setIconSize(QSize(0,37));
	DigitalPin_3->setIconSize(QSize(0,37));
	DigitalPin_4->setIconSize(QSize(0,37));
	DigitalPin_5->setIconSize(QSize(0,37));
	DigitalPin_6->setIconSize(QSize(0,37));
	DigitalPin_7->setIconSize(QSize(0,37));
	DigitalPin_8->setIconSize(QSize(0,37));
	DigitalPin_9->setIconSize(QSize(20,37));
	DigitalPin_10->setIconSize(QSize(0,37));
	DigitalPin_11->setIconSize(QSize(0,37));
	DigitalPin_12->setIconSize(QSize(0,37));
	DigitalPin_13->setIconSize(QSize(0,37));

	lineEdit->setText("9");
	value_ = "9";
}
void Parameter_DigitalPin_Form::on_DigitalPin_10_clicked()
{
	DigitalPin_0->setIconSize(QSize(0,37));
	DigitalPin_1->setIconSize(QSize(0,37));
	DigitalPin_2->setIconSize(QSize(0,37));
	DigitalPin_3->setIconSize(QSize(0,37));
	DigitalPin_4->setIconSize(QSize(0,37));
	DigitalPin_5->setIconSize(QSize(0,37));
	DigitalPin_6->setIconSize(QSize(0,37));
	DigitalPin_7->setIconSize(QSize(0,37));
	DigitalPin_8->setIconSize(QSize(0,37));
	DigitalPin_9->setIconSize(QSize(0,37));
	DigitalPin_10->setIconSize(QSize(20,37));
	DigitalPin_11->setIconSize(QSize(0,37));
	DigitalPin_12->setIconSize(QSize(0,37));
	DigitalPin_13->setIconSize(QSize(0,37));

	lineEdit->setText("10");
	value_ = "10";
}
void Parameter_DigitalPin_Form::on_DigitalPin_11_clicked()
{
	DigitalPin_0->setIconSize(QSize(0,37));
	DigitalPin_1->setIconSize(QSize(0,37));
	DigitalPin_2->setIconSize(QSize(0,37));
	DigitalPin_3->setIconSize(QSize(0,37));
	DigitalPin_4->setIconSize(QSize(0,37));
	DigitalPin_5->setIconSize(QSize(0,37));
	DigitalPin_6->setIconSize(QSize(0,37));
	DigitalPin_7->setIconSize(QSize(0,37));
	DigitalPin_8->setIconSize(QSize(0,37));
	DigitalPin_9->setIconSize(QSize(0,37));
	DigitalPin_10->setIconSize(QSize(0,37));
	DigitalPin_11->setIconSize(QSize(20,37));
	DigitalPin_12->setIconSize(QSize(0,37));
	DigitalPin_13->setIconSize(QSize(0,37));

	lineEdit->setText("11");
	value_ = "11";
}
void Parameter_DigitalPin_Form::on_DigitalPin_12_clicked()
{
	DigitalPin_0->setIconSize(QSize(0,37));
	DigitalPin_1->setIconSize(QSize(0,37));
	DigitalPin_2->setIconSize(QSize(0,37));
	DigitalPin_3->setIconSize(QSize(0,37));
	DigitalPin_4->setIconSize(QSize(0,37));
	DigitalPin_5->setIconSize(QSize(0,37));
	DigitalPin_6->setIconSize(QSize(0,37));
	DigitalPin_7->setIconSize(QSize(0,37));
	DigitalPin_8->setIconSize(QSize(0,37));
	DigitalPin_9->setIconSize(QSize(0,37));
	DigitalPin_10->setIconSize(QSize(0,37));
	DigitalPin_11->setIconSize(QSize(0,37));
	DigitalPin_12->setIconSize(QSize(20,37));
	DigitalPin_13->setIconSize(QSize(0,37));

	lineEdit->setText("12");
	value_ = "12";
}
void Parameter_DigitalPin_Form::on_DigitalPin_13_clicked()
{
	DigitalPin_0->setIconSize(QSize(0,37));
	DigitalPin_1->setIconSize(QSize(0,37));
	DigitalPin_2->setIconSize(QSize(0,37));
	DigitalPin_3->setIconSize(QSize(0,37));
	DigitalPin_4->setIconSize(QSize(0,37));
	DigitalPin_5->setIconSize(QSize(0,37));
	DigitalPin_6->setIconSize(QSize(0,37));
	DigitalPin_7->setIconSize(QSize(0,37));
	DigitalPin_8->setIconSize(QSize(0,37));
	DigitalPin_9->setIconSize(QSize(0,37));
	DigitalPin_10->setIconSize(QSize(0,37));
	DigitalPin_11->setIconSize(QSize(0,37));
	DigitalPin_12->setIconSize(QSize(0,37));
	DigitalPin_13->setIconSize(QSize(20,37));

	lineEdit->setText("13");
	value_ = "13";
}

void Parameter_DigitalPin_Form::on_pushButtonMindkit_clicked()
{
	qDebug() << "切换";
	QSettings settingTmp("./resource/setting.ini", QSettings::IniFormat);
	//QString value = settingTmp.value("Personal/pinmodule").toString();
	settingTmp.setValue("Personal/pinmodule", "mindkit");
}
