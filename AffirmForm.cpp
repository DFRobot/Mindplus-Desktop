#include "AffirmForm.h"
#include <QMouseEvent>
#include <QPainter>

AffirmForm::AffirmForm(const QRect rect, QWidget *parent)
    : QWidget(parent)
    , rect_(rect)
    , pParent_(parent)
{
    setupUi(this);
    initData();
    initGui();
}

void AffirmForm::changeEvent(QEvent *e)
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

void AffirmForm::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void AffirmForm::showEvent(QShowEvent *)
{
    this->setGeometry(rect_);
}

bool AffirmForm::eventFilter(QObject *target, QEvent *event)
{
    if(target == labelBack
               || target == labelNotSave
            || target == labelSave)
       {
           if(QEvent::MouseButtonPress == event->type())
           {
               QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
               if(Qt::LeftButton == mouseEvent->button())
               {
                   //先处理哪一个按下
                   if(target == labelBack)
                   {
                       emit signalBack();
                   }
                   else if(target == labelNotSave)
                   {
                       emit signalNotSave();
                   }
                   else if(target == labelSave)
                   {
                       emit signalSave();
                   }
                   //获取屏幕左上角坐标与软件左上角坐标的偏移
                   this->mousePressEvent(mouseEvent);
                   return true;
               }
           }
           else if (QEvent::MouseMove == event->type())
           {
               QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
               this->mouseMoveEvent(mouseEvent);
               return true;
           }
           else
           {
#ifdef Q_OS_WIN32
			   QWidget::eventFilter(target, event);
#else
			   return false;
#endif
           }
       }
       else
       {
           return QWidget::eventFilter(target, event);
    }
}

void AffirmForm::mousePressEvent(QMouseEvent *event)
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

void AffirmForm::mouseMoveEvent(QMouseEvent *event)
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

void AffirmForm::initData()
{
    labelBack->installEventFilter(this);
    labelNotSave->installEventFilter(this);
    labelSave->installEventFilter(this);
}

void AffirmForm::initGui()
{
    move(1, 1);
}
