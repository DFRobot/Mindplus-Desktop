/********************************************************************************
** Form generated from reading UI file 'AllBlocksForm.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALLBLOCKSFORM_H
#define UI_ALLBLOCKSFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "PushButtonBlock.h"

QT_BEGIN_NAMESPACE

class Ui_AllBlocksForm
{
public:
    QGridLayout *gridLayout_4;
    QWidget *widgetLeft;
    QWidget *widgetRight;
    QWidget *widget;
    QPushButton *pushButtonReturn;
    QWidget *widget_3;
    QGridLayout *gridLayout_3;
    PushButtonBlock *pushButtonInterrupts;
    PushButtonBlock *pushButtonStorager;
    PushButtonBlock *pushButtonEthernet;
    PushButtonBlock *pushButtonLCD;
    PushButtonBlock *pushButtonI2C;
    PushButtonBlock *pushButtonUser;
    PushButtonBlock *pushButtonUnknown;
    QWidget *widget_2;
    QGridLayout *gridLayout_2;
    PushButtonBlock *pushButtonSerial;
    PushButtonBlock *pushButtonAdv;
    PushButtonBlock *pushButtonConvert;
    PushButtonBlock *pushButtonBluetooth;
    PushButtonBlock *pushButtonMoto;
    PushButtonBlock *pushButtonMath;
    QWidget *widget_1;
    QGridLayout *gridLayout;
    PushButtonBlock *pushButtonDigital;
    PushButtonBlock *pushButtonAnalog;
    PushButtonBlock *pushButtonTime;
    PushButtonBlock *pushButtonServo;
    PushButtonBlock *pushButtonFlow;
    PushButtonBlock *pushButtonMindKit;

    void setupUi(QWidget *AllBlocksForm)
    {
        if (AllBlocksForm->objectName().isEmpty())
            AllBlocksForm->setObjectName(QStringLiteral("AllBlocksForm"));
        AllBlocksForm->resize(1024, 675);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AllBlocksForm->sizePolicy().hasHeightForWidth());
        AllBlocksForm->setSizePolicy(sizePolicy);
        AllBlocksForm->setMinimumSize(QSize(1024, 675));
        gridLayout_4 = new QGridLayout(AllBlocksForm);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        widgetLeft = new QWidget(AllBlocksForm);
        widgetLeft->setObjectName(QStringLiteral("widgetLeft"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widgetLeft->sizePolicy().hasHeightForWidth());
        widgetLeft->setSizePolicy(sizePolicy1);
        widgetLeft->setMinimumSize(QSize(180, 675));
        widgetLeft->setMaximumSize(QSize(180, 16777215));
        widgetLeft->setMouseTracking(true);
        widgetLeft->setStyleSheet(QStringLiteral("border-image: url(:/resource/images/common/Transparent_White_90.png);"));

        gridLayout_4->addWidget(widgetLeft, 0, 0, 1, 1);

        widgetRight = new QWidget(AllBlocksForm);
        widgetRight->setObjectName(QStringLiteral("widgetRight"));
        widgetRight->setMouseTracking(true);
        widgetRight->setStyleSheet(QLatin1String("QWidget#widgetRight\n"
"{\n"
"	border-image: url(:/resource/images/common/Transparent_Black_90.png);\n"
"}"));
        widget = new QWidget(widgetRight);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 841, 51));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy2);
        widget->setMinimumSize(QSize(0, 41));
        pushButtonReturn = new QPushButton(widget);
        pushButtonReturn->setObjectName(QStringLiteral("pushButtonReturn"));
        pushButtonReturn->setGeometry(QRect(790, 0, 50, 43));
        pushButtonReturn->setStyleSheet(QStringLiteral("border-image: url(:/images/Back.png);"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/resource/images/common/Back.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonReturn->setIcon(icon);
        pushButtonReturn->setIconSize(QSize(50, 43));
        pushButtonReturn->setFlat(true);
        widget_3 = new QWidget(widgetRight);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setGeometry(QRect(570, 100, 250, 510));
        sizePolicy1.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy1);
        widget_3->setMinimumSize(QSize(250, 510));
        gridLayout_3 = new QGridLayout(widget_3);
        gridLayout_3->setSpacing(10);
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        pushButtonInterrupts = new PushButtonBlock(widget_3);
        pushButtonInterrupts->setObjectName(QStringLiteral("pushButtonInterrupts"));
        sizePolicy1.setHeightForWidth(pushButtonInterrupts->sizePolicy().hasHeightForWidth());
        pushButtonInterrupts->setSizePolicy(sizePolicy1);
        pushButtonInterrupts->setStyleSheet(QStringLiteral("background-color: rgb(211, 74, 76);"));

        gridLayout_3->addWidget(pushButtonInterrupts, 0, 0, 1, 1);

        pushButtonStorager = new PushButtonBlock(widget_3);
        pushButtonStorager->setObjectName(QStringLiteral("pushButtonStorager"));
        sizePolicy1.setHeightForWidth(pushButtonStorager->sizePolicy().hasHeightForWidth());
        pushButtonStorager->setSizePolicy(sizePolicy1);
        pushButtonStorager->setStyleSheet(QStringLiteral("border-image: url(:/resource/images/bb_classify/Storager.png);"));
        pushButtonStorager->setIconSize(QSize(120, 120));
        pushButtonStorager->setFlat(true);

        gridLayout_3->addWidget(pushButtonStorager, 0, 1, 1, 1);

        pushButtonEthernet = new PushButtonBlock(widget_3);
        pushButtonEthernet->setObjectName(QStringLiteral("pushButtonEthernet"));
        sizePolicy1.setHeightForWidth(pushButtonEthernet->sizePolicy().hasHeightForWidth());
        pushButtonEthernet->setSizePolicy(sizePolicy1);
        pushButtonEthernet->setStyleSheet(QStringLiteral("border-image: url(:/resource/images/bb_classify/Ethernet.png);"));
        pushButtonEthernet->setIconSize(QSize(120, 120));
        pushButtonEthernet->setFlat(true);

        gridLayout_3->addWidget(pushButtonEthernet, 1, 0, 1, 1);

        pushButtonLCD = new PushButtonBlock(widget_3);
        pushButtonLCD->setObjectName(QStringLiteral("pushButtonLCD"));
        sizePolicy1.setHeightForWidth(pushButtonLCD->sizePolicy().hasHeightForWidth());
        pushButtonLCD->setSizePolicy(sizePolicy1);
        pushButtonLCD->setStyleSheet(QStringLiteral("border-image: url(:/resource/images/bb_classify/LCD.png);"));
        pushButtonLCD->setIconSize(QSize(120, 120));
        pushButtonLCD->setFlat(true);

        gridLayout_3->addWidget(pushButtonLCD, 1, 1, 1, 1);

        pushButtonI2C = new PushButtonBlock(widget_3);
        pushButtonI2C->setObjectName(QStringLiteral("pushButtonI2C"));
        sizePolicy1.setHeightForWidth(pushButtonI2C->sizePolicy().hasHeightForWidth());
        pushButtonI2C->setSizePolicy(sizePolicy1);
        pushButtonI2C->setStyleSheet(QStringLiteral("background-color: rgb(211, 74, 76);"));

        gridLayout_3->addWidget(pushButtonI2C, 2, 0, 1, 1);

        pushButtonUser = new PushButtonBlock(widget_3);
        pushButtonUser->setObjectName(QStringLiteral("pushButtonUser"));
        sizePolicy1.setHeightForWidth(pushButtonUser->sizePolicy().hasHeightForWidth());
        pushButtonUser->setSizePolicy(sizePolicy1);
        pushButtonUser->setStyleSheet(QStringLiteral("border-image: url(:/resource/images/bb_classify/UserBlock.png);"));
        pushButtonUser->setIconSize(QSize(120, 120));
        pushButtonUser->setFlat(true);

        gridLayout_3->addWidget(pushButtonUser, 2, 1, 1, 1);

        pushButtonUnknown = new PushButtonBlock(widget_3);
        pushButtonUnknown->setObjectName(QStringLiteral("pushButtonUnknown"));
        sizePolicy1.setHeightForWidth(pushButtonUnknown->sizePolicy().hasHeightForWidth());
        pushButtonUnknown->setSizePolicy(sizePolicy1);
        pushButtonUnknown->setStyleSheet(QStringLiteral("border-image: url(:/resource/images/bb_classify/Unknown.png);"));
        pushButtonUnknown->setIconSize(QSize(248, 120));
        pushButtonUnknown->setFlat(true);

        gridLayout_3->addWidget(pushButtonUnknown, 3, 0, 1, 2);

        widget_2 = new QWidget(widgetRight);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(300, 100, 250, 510));
        sizePolicy1.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy1);
        widget_2->setMinimumSize(QSize(250, 510));
        gridLayout_2 = new QGridLayout(widget_2);
        gridLayout_2->setSpacing(10);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        pushButtonSerial = new PushButtonBlock(widget_2);
        pushButtonSerial->setObjectName(QStringLiteral("pushButtonSerial"));
        sizePolicy1.setHeightForWidth(pushButtonSerial->sizePolicy().hasHeightForWidth());
        pushButtonSerial->setSizePolicy(sizePolicy1);
        pushButtonSerial->setStyleSheet(QStringLiteral("background-color: rgb(146, 186, 73);"));

        gridLayout_2->addWidget(pushButtonSerial, 0, 0, 1, 2);

        pushButtonAdv = new PushButtonBlock(widget_2);
        pushButtonAdv->setObjectName(QStringLiteral("pushButtonAdv"));
        sizePolicy1.setHeightForWidth(pushButtonAdv->sizePolicy().hasHeightForWidth());
        pushButtonAdv->setSizePolicy(sizePolicy1);
        pushButtonAdv->setStyleSheet(QStringLiteral("border-image: url(:/resource/images/bb_classify/AdvIO.png);"));
        pushButtonAdv->setIconSize(QSize(120, 120));
        pushButtonAdv->setFlat(true);

        gridLayout_2->addWidget(pushButtonAdv, 1, 0, 1, 1);

        pushButtonConvert = new PushButtonBlock(widget_2);
        pushButtonConvert->setObjectName(QStringLiteral("pushButtonConvert"));
        sizePolicy1.setHeightForWidth(pushButtonConvert->sizePolicy().hasHeightForWidth());
        pushButtonConvert->setSizePolicy(sizePolicy1);
        pushButtonConvert->setStyleSheet(QStringLiteral("background-color: rgb(146, 186, 73);"));

        gridLayout_2->addWidget(pushButtonConvert, 1, 1, 1, 1);

        pushButtonBluetooth = new PushButtonBlock(widget_2);
        pushButtonBluetooth->setObjectName(QStringLiteral("pushButtonBluetooth"));
        sizePolicy1.setHeightForWidth(pushButtonBluetooth->sizePolicy().hasHeightForWidth());
        pushButtonBluetooth->setSizePolicy(sizePolicy1);
        pushButtonBluetooth->setStyleSheet(QStringLiteral("border-image: url(:/resource/images/bb_classify/Bluetooth.png);"));
        pushButtonBluetooth->setIconSize(QSize(120, 120));
        pushButtonBluetooth->setFlat(true);

        gridLayout_2->addWidget(pushButtonBluetooth, 2, 0, 1, 1);

        pushButtonMoto = new PushButtonBlock(widget_2);
        pushButtonMoto->setObjectName(QStringLiteral("pushButtonMoto"));
        sizePolicy1.setHeightForWidth(pushButtonMoto->sizePolicy().hasHeightForWidth());
        pushButtonMoto->setSizePolicy(sizePolicy1);
        pushButtonMoto->setStyleSheet(QStringLiteral("border-image: url(:/resource/images/bb_classify/moto.png);"));
        pushButtonMoto->setIconSize(QSize(120, 120));
        pushButtonMoto->setFlat(true);

        gridLayout_2->addWidget(pushButtonMoto, 2, 1, 1, 1);

        pushButtonMath = new PushButtonBlock(widget_2);
        pushButtonMath->setObjectName(QStringLiteral("pushButtonMath"));
        sizePolicy1.setHeightForWidth(pushButtonMath->sizePolicy().hasHeightForWidth());
        pushButtonMath->setSizePolicy(sizePolicy1);
        pushButtonMath->setStyleSheet(QStringLiteral("border-image: url(:/resource/images/bb_classify/Math.png);"));
        pushButtonMath->setIconSize(QSize(248, 120));
        pushButtonMath->setFlat(true);

        gridLayout_2->addWidget(pushButtonMath, 3, 0, 1, 2);

        widget_1 = new QWidget(widgetRight);
        widget_1->setObjectName(QStringLiteral("widget_1"));
        widget_1->setGeometry(QRect(30, 100, 250, 510));
        sizePolicy1.setHeightForWidth(widget_1->sizePolicy().hasHeightForWidth());
        widget_1->setSizePolicy(sizePolicy1);
        widget_1->setMinimumSize(QSize(250, 510));
        gridLayout = new QGridLayout(widget_1);
        gridLayout->setSpacing(10);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButtonDigital = new PushButtonBlock(widget_1);
        pushButtonDigital->setObjectName(QStringLiteral("pushButtonDigital"));
        sizePolicy1.setHeightForWidth(pushButtonDigital->sizePolicy().hasHeightForWidth());
        pushButtonDigital->setSizePolicy(sizePolicy1);
        pushButtonDigital->setStyleSheet(QStringLiteral("border-image: url(:/resource/images/bb_classify/DigitalIO.png);"));
        pushButtonDigital->setIconSize(QSize(120, 120));
        pushButtonDigital->setFlat(true);

        gridLayout->addWidget(pushButtonDigital, 0, 0, 1, 1);

        pushButtonAnalog = new PushButtonBlock(widget_1);
        pushButtonAnalog->setObjectName(QStringLiteral("pushButtonAnalog"));
        sizePolicy1.setHeightForWidth(pushButtonAnalog->sizePolicy().hasHeightForWidth());
        pushButtonAnalog->setSizePolicy(sizePolicy1);
        pushButtonAnalog->setStyleSheet(QStringLiteral("border-image: url(:/resource/images/bb_classify/AnalogIO.png);"));
        pushButtonAnalog->setIconSize(QSize(120, 120));
        pushButtonAnalog->setFlat(true);

        gridLayout->addWidget(pushButtonAnalog, 0, 1, 1, 1);

        pushButtonTime = new PushButtonBlock(widget_1);
        pushButtonTime->setObjectName(QStringLiteral("pushButtonTime"));
        sizePolicy1.setHeightForWidth(pushButtonTime->sizePolicy().hasHeightForWidth());
        pushButtonTime->setSizePolicy(sizePolicy1);
        pushButtonTime->setStyleSheet(QStringLiteral("border-image: url(:/resource/images/bb_classify/Time.png);"));
        pushButtonTime->setIconSize(QSize(248, 120));
        pushButtonTime->setFlat(true);

        gridLayout->addWidget(pushButtonTime, 1, 0, 1, 2);

        pushButtonServo = new PushButtonBlock(widget_1);
        pushButtonServo->setObjectName(QStringLiteral("pushButtonServo"));
        sizePolicy1.setHeightForWidth(pushButtonServo->sizePolicy().hasHeightForWidth());
        pushButtonServo->setSizePolicy(sizePolicy1);
        pushButtonServo->setStyleSheet(QStringLiteral("border-image: url(:/resource/images/bb_classify/Servo.png);"));
        pushButtonServo->setIconSize(QSize(120, 120));
        pushButtonServo->setFlat(true);

        gridLayout->addWidget(pushButtonServo, 2, 0, 1, 1);

        pushButtonFlow = new PushButtonBlock(widget_1);
        pushButtonFlow->setObjectName(QStringLiteral("pushButtonFlow"));
        sizePolicy1.setHeightForWidth(pushButtonFlow->sizePolicy().hasHeightForWidth());
        pushButtonFlow->setSizePolicy(sizePolicy1);
        pushButtonFlow->setStyleSheet(QStringLiteral("border-image: url(:/resource/images/bb_classify/Flow.png);"));
        pushButtonFlow->setIconSize(QSize(120, 120));
        pushButtonFlow->setFlat(true);

        gridLayout->addWidget(pushButtonFlow, 2, 1, 1, 1);

        pushButtonMindKit = new PushButtonBlock(widget_1);
        pushButtonMindKit->setObjectName(QStringLiteral("pushButtonMindKit"));
        sizePolicy1.setHeightForWidth(pushButtonMindKit->sizePolicy().hasHeightForWidth());
        pushButtonMindKit->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(14);
        pushButtonMindKit->setFont(font);
        pushButtonMindKit->setStyleSheet(QStringLiteral("border-image: url(:/resource/images/bb_classify/mindkit.png);"));
        pushButtonMindKit->setFlat(false);

        gridLayout->addWidget(pushButtonMindKit, 3, 0, 1, 2);


        gridLayout_4->addWidget(widgetRight, 0, 1, 1, 1);


        retranslateUi(AllBlocksForm);

        QMetaObject::connectSlotsByName(AllBlocksForm);
    } // setupUi

    void retranslateUi(QWidget *AllBlocksForm)
    {
        AllBlocksForm->setWindowTitle(QApplication::translate("AllBlocksForm", "Form", 0));
        pushButtonReturn->setText(QString());
        pushButtonInterrupts->setText(QString());
        pushButtonStorager->setText(QString());
        pushButtonEthernet->setText(QString());
        pushButtonLCD->setText(QString());
        pushButtonI2C->setText(QString());
        pushButtonUser->setText(QString());
        pushButtonUnknown->setText(QString());
        pushButtonSerial->setText(QString());
        pushButtonAdv->setText(QString());
        pushButtonConvert->setText(QString());
        pushButtonBluetooth->setText(QString());
        pushButtonMoto->setText(QString());
        pushButtonMath->setText(QString());
        pushButtonDigital->setText(QString());
        pushButtonAnalog->setText(QString());
        pushButtonTime->setText(QString());
        pushButtonServo->setText(QString());
        pushButtonFlow->setText(QString());
        pushButtonMindKit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AllBlocksForm: public Ui_AllBlocksForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALLBLOCKSFORM_H
