/********************************************************************************
** Form generated from reading UI file 'MindKitForm.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MINDKITFORM_H
#define UI_MINDKITFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "MindKitPushButton.h"

QT_BEGIN_NAMESPACE

class Ui_MindKitForm
{
public:
    QGridLayout *gridLayout;
    QWidget *widgetLeft;
    QWidget *widget;
    QLabel *label;
    QWidget *widgetRight;
    QPushButton *pushButtonReturn;
    MindKitPushButton *pushButton_1;
    MindKitPushButton *pushButton_2;
    MindKitPushButton *pushButton_3;
    MindKitPushButton *pushButton_4;
    MindKitPushButton *pushButton_5;
    MindKitPushButton *pushButton_7;
    MindKitPushButton *pushButton_6;
    MindKitPushButton *pushButton_8;

    void setupUi(QWidget *MindKitForm)
    {
        if (MindKitForm->objectName().isEmpty())
            MindKitForm->setObjectName(QStringLiteral("MindKitForm"));
        MindKitForm->resize(1025, 675);
        MindKitForm->setMinimumSize(QSize(1025, 675));
        gridLayout = new QGridLayout(MindKitForm);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        widgetLeft = new QWidget(MindKitForm);
        widgetLeft->setObjectName(QStringLiteral("widgetLeft"));
        widgetLeft->setMinimumSize(QSize(180, 675));
        widgetLeft->setStyleSheet(QLatin1String("QWidget#widgetLeft\n"
"{\n"
"	border-image: url(:/resource/images/common/Transparent_White_90.png);\n"
"}"));
        widget = new QWidget(widgetLeft);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 210, 161, 140));
        widget->setStyleSheet(QStringLiteral("border-image: url(:/resource/images/bb_mind_kit/kit_Arrow.png);"));
        label = new QLabel(widgetLeft);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 370, 161, 101));
        label->setStyleSheet(QStringLiteral("font: 13pt \"Microsoft YaHei UI\";"));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label->setWordWrap(true);

        gridLayout->addWidget(widgetLeft, 0, 0, 1, 1);

        widgetRight = new QWidget(MindKitForm);
        widgetRight->setObjectName(QStringLiteral("widgetRight"));
        widgetRight->setMinimumSize(QSize(845, 675));
        widgetRight->setStyleSheet(QLatin1String("QWidget#widgetRight\n"
"{\n"
"	border-image: url(:/resource/images/common/Transparent_Black_90.png);\n"
"}"));
        pushButtonReturn = new QPushButton(widgetRight);
        pushButtonReturn->setObjectName(QStringLiteral("pushButtonReturn"));
        pushButtonReturn->setGeometry(QRect(790, 0, 48, 39));
        pushButtonReturn->setStyleSheet(QStringLiteral("border-image: url(:/resource/images/common/Back.png);"));
        pushButton_1 = new MindKitPushButton(widgetRight);
        pushButton_1->setObjectName(QStringLiteral("pushButton_1"));
        pushButton_1->setGeometry(QRect(70, 70, 131, 121));
        pushButton_1->setStyleSheet(QStringLiteral("border-image: url(:/resource/images/bb_mind_kit/kit_Button.png);"));
        pushButton_2 = new MindKitPushButton(widgetRight);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(250, 30, 131, 111));
        pushButton_2->setStyleSheet(QStringLiteral("border-image: url(:/resource/images/bb_mind_kit/kit_RotationSensor.png);"));
        pushButton_3 = new MindKitPushButton(widgetRight);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(500, 40, 101, 111));
        pushButton_3->setStyleSheet(QStringLiteral("border-image: url(:/resource/images/bb_mind_kit/kit_LightSensor.png);"));
        pushButton_4 = new MindKitPushButton(widgetRight);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(600, 210, 151, 121));
        pushButton_4->setStyleSheet(QStringLiteral("border-image: url(:/resource/images/bb_mind_kit/kit_CloseSensor.png);"));
        pushButton_5 = new MindKitPushButton(widgetRight);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(100, 320, 131, 111));
        pushButton_5->setStyleSheet(QStringLiteral("border-image: url(:/resource/images/bb_mind_kit/kit_LED.png);"));
        pushButton_7 = new MindKitPushButton(widgetRight);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(600, 430, 161, 111));
        pushButton_7->setStyleSheet(QStringLiteral("border-image: url(:/resource/images/bb_mind_kit/kit_Buzzer.png);"));
        pushButton_6 = new MindKitPushButton(widgetRight);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(320, 260, 171, 111));
        pushButton_6->setStyleSheet(QStringLiteral("border-image: url(:/resource/images/bb_mind_kit/kit_Servo.png);"));
        pushButton_8 = new MindKitPushButton(widgetRight);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(280, 490, 181, 111));
        pushButton_8->setStyleSheet(QStringLiteral("border-image: url(:/resource/images/bb_mind_kit/kit_IRRec.png);"));

        gridLayout->addWidget(widgetRight, 0, 1, 1, 1);


        retranslateUi(MindKitForm);

        QMetaObject::connectSlotsByName(MindKitForm);
    } // setupUi

    void retranslateUi(QWidget *MindKitForm)
    {
        MindKitForm->setWindowTitle(QApplication::translate("MindKitForm", "Form", 0));
        label->setText(QApplication::translate("MindKitForm", "\345\234\250\345\217\263\350\276\271\346\211\276\345\210\260\344\275\240\346\203\263\345\212\240\345\205\245\347\232\204\346\250\241\345\235\227\346\213\226\346\213\275\345\260\206\345\205\266\345\212\240\345\205\245\344\275\240\347\232\204\344\275\234\345\223\201\345\275\223\344\270\255", 0));
        pushButtonReturn->setText(QString());
        pushButton_1->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
        pushButton_5->setText(QString());
        pushButton_7->setText(QString());
        pushButton_6->setText(QString());
        pushButton_8->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MindKitForm: public Ui_MindKitForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MINDKITFORM_H
