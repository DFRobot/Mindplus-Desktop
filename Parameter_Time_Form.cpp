#include "Parameter_Time_Form.h"
#include <QPainter>
#include <QRegExp>
#include <QDebug>
#include <QTime>
#include <QKeyEvent>
#include "Animation.h"

Parameter_Time_Form::Parameter_Time_Form(const QRect rect, QWidget *parent)
    : QWidget(parent)
    , min_(0)
    , sec_(0)
    , msec_(0)
    , pParent_(parent)
    , rect_(rect)
{
    setupUi(this);
    initSetting();
    initGui();
}

void Parameter_Time_Form::setValue(const QString &value)
{
	QTime time(0,0,0);
	int msec = value.toInt();
	time = time.addMSecs(msec);
	QString tmp = time.toString("m-s-z");
    QStringList tmpList = tmp.split("-");
    lineEditMin->setText(tmpList[0]);
    lineEditSec->setText(tmpList[1]);
    lineEditMsec->setText(tmpList[2]);
}

void Parameter_Time_Form::changeEvent(QEvent *e)
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

void Parameter_Time_Form::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

bool Parameter_Time_Form::eventFilter(QObject *target, QEvent *event)
{
    QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
    if(lineEditMin == target || lineEditSec == target || lineEditMsec == target || this == target)
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

void Parameter_Time_Form::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        QWidget *pParent_ = static_cast<QWidget *>(this->parent());
        if(NULL == pParent_)
        {
            return;
        }
        offset_ = event->globalPos() - pParent_->frameGeometry().topLeft();
    }
}

void Parameter_Time_Form::mouseMoveEvent(QMouseEvent *event)
{
    if (!(event->buttons() & Qt::LeftButton))
    {
        return;
    }
    if ((event->pos() - offset_).manhattanLength()
            < QApplication::startDragDistance())
    {
        return;
    }
    pParent_->move(event->globalPos() - offset_);
}

void Parameter_Time_Form::showEvent(QShowEvent *event)
{
    this->setGeometry(rect_);
}

void Parameter_Time_Form::initSetting()
{
    //用正则表达式限定输入范围, 呵呵现学现用
    //QRegExp regExp("0\.[0-9]*|[0-9]+\.?[0-9]*");
    //lineEditMin->setValidator(new QRegExpValidator(regExp));
    //lineEditSec->setValidator(new QRegExpValidator(regExp));
    //lineEditMsec->setValidator(new QIntValidator(0, 1000));
    lineEditMin->installEventFilter(this);
    lineEditSec->installEventFilter(this);
    lineEditMsec->installEventFilter(this);
    this->installEventFilter(this);
    lineEditMsec->setFocus();

    lineEditMin->setValidator(new QDoubleValidator(0, 65535, 2));
    lineEditSec->setValidator(new QDoubleValidator(0, 65535, 3));
    lineEditMsec->setValidator(new QIntValidator(0, 100000));

    this->setAttribute(Qt::WA_TranslucentBackground, true);
    //恩原来是tool
    this->setWindowFlags(Qt::FramelessWindowHint);

    //connect(lineEdit, SIGNAL(textEdited(QString)), this, SLOT(slotTextEdited(QString)));
    pushButton->setWindowFlags(Qt::FramelessWindowHint);
    pushButton->setAttribute(Qt::WA_TranslucentBackground);
}

void Parameter_Time_Form::initGui()
{
    this->move(1, 1);
    Animation::opacityAnimation(pushButton, 150, 0, 1, QEasingCurve::OutQuart);
    Animation::posAnimation(pushButton, 150, pushButton->pos() + QPoint(50, 0) , pushButton->pos(), QEasingCurve::OutQuart);
}

void Parameter_Time_Form::changeValue()
{
    float min = lineEditMin->text().toFloat();
    int sec = lineEditSec->text().toFloat();
    int msec = lineEditMsec->text().toInt();

    if(lineEditSec->text().indexOf(".") != -1)
    {//处理小数点的情况
        QString tmp = lineEditSec->text();
        tmp = tr("0") + tmp.right(tmp.size() - tmp.indexOf(".") );
        qDebug()<<"小数点" << tmp.toFloat();
        //用float的话会有精度损失....fuck
        msec += (tmp.toDouble()*1000);
    }

    sec += msec/1000;
    msec %= 1000;

    min += sec / 60;
    sec %= 60;

    min_ = min;
    sec_ = sec;
    msec_ = msec;

    lineEditMin->setText(QString::number(min_));
    lineEditSec->setText(QString::number(sec_));
    lineEditMsec->setText(QString::number(msec_));
}

void Parameter_Time_Form::on_pushButton_clicked()
{
    changeValue();
    int value = min_*60*1000 + sec_*1000 + msec_;
    emit signalValueChange(QString::number(value));
    close();
}
