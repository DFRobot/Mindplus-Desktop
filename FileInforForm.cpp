#include "FileInforForm.h"
#include <QMouseEvent>
#include "WidgetMain.h"

FileInforForm::FileInforForm(QWidget *parent)
    : QWidget(parent)
    , pParent_(parent)

{
    setupUi(this);
    this->initData();
    this->initGui();
}

void FileInforForm::changeEvent(QEvent *e)
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

void FileInforForm::mousePressEvent(QMouseEvent *event)
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

void FileInforForm::mouseMoveEvent(QMouseEvent *event)
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

void FileInforForm::on_pushButtonReturn_clicked()
{
    close();
}

void FileInforForm::initData()
{
    //list_subWindows.append(this);
}

void FileInforForm::initGui()
{
    this->move(1, 1);
}
