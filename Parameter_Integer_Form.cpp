#include "Parameter_Integer_Form.h"
#include <QPainter>
#include <QDebug>
#include <QKeyEvent>
#include "Animation.h"
Parameter_Integer_Form::Parameter_Integer_Form(const QRect rect, QWidget *parent)
    : QWidget(parent)
    , pParent_(parent)
    , rect_(rect)
{
    setupUi(this);
    initSetting();
    initGui();
}

void Parameter_Integer_Form::setValue(const QString &value)
{
    value_ = value;
    lineEdit->setText(value_);
}

void Parameter_Integer_Form::changeEvent(QEvent *e)
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

void Parameter_Integer_Form::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

bool Parameter_Integer_Form::eventFilter(QObject *target, QEvent *event)
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

void Parameter_Integer_Form::mousePressEvent(QMouseEvent *event)
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

void Parameter_Integer_Form::mouseMoveEvent(QMouseEvent *event)
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

void Parameter_Integer_Form::showEvent(QShowEvent *event)
{
    this->setGeometry(rect_);
}

void Parameter_Integer_Form::initSetting()
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

void Parameter_Integer_Form::initGui()
{
    this->move(1, 1);
    Animation::opacityAnimation(pushButton, 150, 0, 1, QEasingCurve::OutQuart);
    Animation::posAnimation(pushButton, 150, pushButton->pos() + QPoint(50, 0) , pushButton->pos(), QEasingCurve::OutQuart);
}

void Parameter_Integer_Form::on_pushButton_clicked()
{
    emit signalValue(value_);
    close();
}

void Parameter_Integer_Form::slotTextEdited(const QString &value)
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
            qDebug() << "添加0头的情况"<< value_;
        }
        else if(value_[0] == '0' && value_[1] != '.')
        {
            value_.remove(0,1);
            qDebug() << "删除前面多余0头的情况" << value_;
        }
    }
}
