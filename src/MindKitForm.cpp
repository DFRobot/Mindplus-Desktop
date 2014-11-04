#include "MindKitForm.h"
#include <QMouseEvent>
#include <QTimer>
#include "MindKitPushButton.h"

MindKitForm::MindKitForm(QWidget *parent)
    : QWidget(parent)
    , pParent_(parent)
{
    setupUi(this);
}

void MindKitForm::changeEvent(QEvent *e)
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

void MindKitForm::mousePressEvent(QMouseEvent *event)
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

void MindKitForm::mouseMoveEvent(QMouseEvent *event)
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

void MindKitForm::showEvent(QShowEvent *)
{
    QTimer::singleShot(100, this, SLOT(slotInitPushbutton()));
}

void MindKitForm::on_pushButtonReturn_clicked()
{
    close();
}

void MindKitForm::slotInitPushbutton()
{
    QList<QPushButton *> listMindKitPushButton;
    listMindKitPushButton << pushButton_1 << pushButton_2 << pushButton_3
                          << pushButton_4 << pushButton_5 << pushButton_6 << pushButton_7 << pushButton_8;
    QStringList listName;
    listName << "KitButton" << "KitRotationSensor" << "KitLightSensor" << "KitInfraredSensorSwitch"
             << "KitLED" << "KitServo" << "KitBuzzer" << "KitIRReceiver";

    for(int i = 0; i != listName.size(); ++i)
    {
        MindKitPushButton *p = qobject_cast<MindKitPushButton *>(listMindKitPushButton.at(i));
        if(!p)
        {
            continue;
        }
        p->setName(listName.at(i));
        connect(p, SIGNAL(signalHideMindKit()), this, SLOT(hide()));
        connect(p, SIGNAL(signalMindKitPushButtonPointer(MindKitPushButton*)), this, SIGNAL(signalMindKitPushButtonPointer(MindKitPushButton*)));
    }
}

void MindKitForm::initGui()
{
    this->move(1, 1);
}
