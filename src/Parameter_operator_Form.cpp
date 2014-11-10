#include "Parameter_operator_Form.h"
#include <QPainter>
#include <QKeyEvent>
#include "Animation.h"

Parameter_operator_Form::Parameter_operator_Form(const QRect rect, QWidget *parent) :
    QWidget(parent)
  , rect_(rect)
{
    setupUi(this);
    initSetting();
    initGui();
}

void Parameter_operator_Form::setValue(const QString &value)
{
    value_ = value;
    //lineEdit->setText(value_);
}

void Parameter_operator_Form::changeEvent(QEvent *e)
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

void Parameter_operator_Form::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

bool Parameter_operator_Form::eventFilter(QObject *target, QEvent *event)
{
    /*
    QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
    if(lineEdit == target  || this == target)
    {
        if(QEvent::KeyPress == event->type())
        {
            if(Qt::Key_Enter == keyEvent->key()
                    || Qt::Key_Return == keyEvent->key())
            {
                //this->on_pushButton_clicked();
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
    */
}

void Parameter_operator_Form::showEvent(QShowEvent *event)
{
    this->setGeometry(rect_);
}

void Parameter_operator_Form::initSetting()
{
    //this->setWindowState(Qt::WindowActive);
    //lineEdit->installEventFilter(this);
    this->installEventFilter(this);
    //lineEdit->setFocus();

    this->setAttribute(Qt::WA_TranslucentBackground, true);
    //恩原来是tool
    this->setWindowFlags(Qt::FramelessWindowHint /*| Qt::Tool*/);
    //lineEdit->setValidator(new QDoubleValidator(-32768, 32767, 3));
    //connect(lineEdit, SIGNAL(textEdited(QString)), this, SLOT(slotTextEdited(QString)));
    //pushButton->setWindowFlags(Qt::FramelessWindowHint);
    //pushButton->setAttribute(Qt::WA_TranslucentBackground);
}

void Parameter_operator_Form::initGui()
{
    this->move(1, 1);
    //Animation::opacityAnimation(pushButton, 150, 0, 1, QEasingCurve::OutQuart);
    //Animation::posAnimation(pushButton, 150, pushButton->pos() + QPoint(50, 0) , pushButton->pos(), QEasingCurve::OutQuart);
}
/*
void Parameter_operator_Form::on_pushButton_clicked()
{
    emit signalValue(value_);
    close();
}
*/
/*
void Parameter_operator_Form::slotTextEdited(const QString &value)
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
*/
void Parameter_operator_Form::on_operator_0_clicked()
{
    value_ = "0";

    emit signalValue(value_);
    close();
}
void Parameter_operator_Form::on_operator_1_clicked()
{
    value_ = "1";

    emit signalValue(value_);
    close();
}
void Parameter_operator_Form::on_operator_2_clicked()
{
    value_ = "2";

    emit signalValue(value_);
    close();
}
void Parameter_operator_Form::on_operator_3_clicked()
{
    value_ = "3";

    emit signalValue(value_);
    close();
}
void Parameter_operator_Form::on_operator_4_clicked()
{
    value_ = "4";

    emit signalValue(value_);
    close();
}
void Parameter_operator_Form::on_operator_5_clicked()
{
    value_ = "5";

    emit signalValue(value_);
    close();
}
