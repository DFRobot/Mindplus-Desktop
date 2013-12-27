#include "Parameter_String_Form.h"
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#include "Animation.h"

Parameter_String_Form::Parameter_String_Form(const QRect rect, QWidget *parent)
    : QWidget(parent)
    , pParent_(parent)
    , rect_(rect)
{
    setupUi(this);
    this->initSetting();
    this->initGui();
}

void Parameter_String_Form::setValue(const QString &value)
{
    value_ = value;
    QString withoutmark = "";
    //withoutmark = value_.section('"',1,1);
    withoutmark = value_.left(value_.size()-1);
    withoutmark = withoutmark.right(withoutmark.size()-1);
    lineEdit->setText(withoutmark);
    ////////自动去除引号
}

void Parameter_String_Form::changeEvent(QEvent *e)
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

void Parameter_String_Form::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

bool Parameter_String_Form::eventFilter(QObject *target, QEvent *event)
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

void Parameter_String_Form::mousePressEvent(QMouseEvent *event)
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

void Parameter_String_Form::mouseMoveEvent(QMouseEvent *event)
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

void Parameter_String_Form::showEvent(QShowEvent *event)
{
    this->setGeometry(rect_);
}

void Parameter_String_Form::initSetting()
{
    this->setAttribute(Qt::WA_TranslucentBackground, true);
    //恩原来是tool
    this->setWindowFlags(Qt::FramelessWindowHint);
    //lineEdit->setValidator(new QDoubleValidator(-32,768, 32,767, 3));
    connect(lineEdit, SIGNAL(textEdited(QString)), this, SLOT(slotTextEdited(QString)));
    pushButton->setWindowFlags(Qt::FramelessWindowHint);
    pushButton->setAttribute(Qt::WA_TranslucentBackground);
    lineEdit->setFocus();
	lineEdit->installEventFilter(this);
}

void Parameter_String_Form::initGui()
{
    this->move(1, 1);
    Animation::opacityAnimation(pushButton, 150, 0, 1, QEasingCurve::OutQuart);
    Animation::posAnimation(pushButton, 150, pushButton->pos() + QPoint(50, 0) , pushButton->pos(), QEasingCurve::OutQuart);
}

void Parameter_String_Form::on_pushButton_clicked()
{

    emit signalValue(value_);
    close();
}

void Parameter_String_Form::slotTextEdited(const QString &value)
{
    value_ = value;
    value_.insert(0,"\"");
    value_ += "\"";
    //自动加引号给字符串
}
