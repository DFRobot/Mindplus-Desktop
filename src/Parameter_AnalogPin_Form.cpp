#include "Parameter_AnalogPin_Form.h"
#include <QPainter>
#include <QKeyEvent>
#include <QSettings>

#include "Animation.h"

Parameter_AnalogPin_Form::Parameter_AnalogPin_Form(const QRect rect, QWidget *parent)
    : QWidget(parent)
  , rect_(rect)
{
    setupUi(this);
    initSetting();
    initGui();
}

void Parameter_AnalogPin_Form::setValue(const QString &value)
{
    value_ = value;
    lineEdit->setText(value_);
    switch (value_.toInt()){
    case 0:
        on_AnalogPin_0_clicked();
    break;
    case 1:
        on_AnalogPin_1_clicked();
    break;
    case 2:
        on_AnalogPin_2_clicked();
    break;
    case 3:
        on_AnalogPin_3_clicked();
    break;
    case 4:
        on_AnalogPin_4_clicked();
    break;
    case 5:
        on_AnalogPin_5_clicked();
    break;
    }

}

void Parameter_AnalogPin_Form::changeEvent(QEvent *e)
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

void Parameter_AnalogPin_Form::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

bool Parameter_AnalogPin_Form::eventFilter(QObject *target, QEvent *event)
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

void Parameter_AnalogPin_Form::showEvent(QShowEvent *event)
{
    this->setGeometry(rect_);
}

void Parameter_AnalogPin_Form::initSetting()
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

void Parameter_AnalogPin_Form::initGui()
{
    this->move(1, 1);
    Animation::opacityAnimation(pushButton, 150, 0, 1, QEasingCurve::OutQuart);
    Animation::posAnimation(pushButton, 150, pushButton->pos() + QPoint(50, 0) , pushButton->pos(), QEasingCurve::OutQuart);
}

void Parameter_AnalogPin_Form::on_pushButton_clicked()
{
    emit signalValue(value_);
    close();
}

void Parameter_AnalogPin_Form::slotTextEdited(const QString &value)
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

void Parameter_AnalogPin_Form::on_AnalogPin_0_clicked()
{
    AnalogPin_0->setIconSize(QSize(20,37));
    AnalogPin_1->setIconSize(QSize(0,37));
    AnalogPin_2->setIconSize(QSize(0,37));
    AnalogPin_3->setIconSize(QSize(0,37));
    AnalogPin_4->setIconSize(QSize(0,37));
    AnalogPin_5->setIconSize(QSize(0,37));

    lineEdit->setText("0");
    value_ = "0";
}

void Parameter_AnalogPin_Form::on_AnalogPin_1_clicked()
{
    AnalogPin_0->setIconSize(QSize(0,37));
    AnalogPin_1->setIconSize(QSize(20,37));
    AnalogPin_2->setIconSize(QSize(0,37));
    AnalogPin_3->setIconSize(QSize(0,37));
    AnalogPin_4->setIconSize(QSize(0,37));
    AnalogPin_5->setIconSize(QSize(0,37));

    lineEdit->setText("1");
    value_ = "1";
}

void Parameter_AnalogPin_Form::on_AnalogPin_2_clicked()
{
    AnalogPin_0->setIconSize(QSize(0,37));
    AnalogPin_1->setIconSize(QSize(0,37));
    AnalogPin_2->setIconSize(QSize(20,37));
    AnalogPin_3->setIconSize(QSize(0,37));
    AnalogPin_4->setIconSize(QSize(0,37));
    AnalogPin_5->setIconSize(QSize(0,37));

    lineEdit->setText("2");
    value_ = "2";
}

void Parameter_AnalogPin_Form::on_AnalogPin_3_clicked()
{
    AnalogPin_0->setIconSize(QSize(0,37));
    AnalogPin_1->setIconSize(QSize(0,37));
    AnalogPin_2->setIconSize(QSize(0,37));
    AnalogPin_3->setIconSize(QSize(20,37));
    AnalogPin_4->setIconSize(QSize(0,37));
    AnalogPin_5->setIconSize(QSize(0,37));

    lineEdit->setText("3");
    value_ = "3";
}

void Parameter_AnalogPin_Form::on_AnalogPin_4_clicked()
{
    AnalogPin_0->setIconSize(QSize(0,37));
    AnalogPin_1->setIconSize(QSize(0,37));
    AnalogPin_2->setIconSize(QSize(0,37));
    AnalogPin_3->setIconSize(QSize(0,37));
    AnalogPin_4->setIconSize(QSize(20,37));
    AnalogPin_5->setIconSize(QSize(0,37));

    lineEdit->setText("4");
    value_ = "4";
}

void Parameter_AnalogPin_Form::on_AnalogPin_5_clicked()
{
    AnalogPin_0->setIconSize(QSize(0,37));
    AnalogPin_1->setIconSize(QSize(0,37));
    AnalogPin_2->setIconSize(QSize(0,37));
    AnalogPin_3->setIconSize(QSize(0,37));
    AnalogPin_4->setIconSize(QSize(0,37));
    AnalogPin_5->setIconSize(QSize(20,37));

    lineEdit->setText("5");
    value_ = "5";
}

void Parameter_AnalogPin_Form::on_pushButtonMindkit_clicked()
{
	QSettings settingTmp("./resource/setting.ini", QSettings::IniFormat);
	//QString value = settingTmp.value("Personal/pinmodule").toString();
	settingTmp.setValue("Personal/pinmodule", "mindkit");
}
