/********************************************************************************
** Form generated from reading UI file 'Parameter_LED8x8_Form.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARAMETER_LED8X8_FORM_H
#define UI_PARAMETER_LED8X8_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include "PushButtonDone.h"

QT_BEGIN_NAMESPACE

class Ui_Parameter_LED8x8_Form
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QWidget *widgetBg;
    PushButtonDone *pushButton;
    QLabel *bgimage;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *Parameter_LED8x8_Form)
    {
        if (Parameter_LED8x8_Form->objectName().isEmpty())
            Parameter_LED8x8_Form->setObjectName(QStringLiteral("Parameter_LED8x8_Form"));
        Parameter_LED8x8_Form->resize(1025, 675);
        Parameter_LED8x8_Form->setMinimumSize(QSize(1025, 675));
        Parameter_LED8x8_Form->setStyleSheet(QLatin1String("QWidget#Parameter_LED8x8_Form\n"
"{\n"
"	border-image: url(:/resource/images/common/Transparent_Black_70.png);\n"
"}"));
        gridLayout = new QGridLayout(Parameter_LED8x8_Form);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalSpacer = new QSpacerItem(20, 92, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(307, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        widgetBg = new QWidget(Parameter_LED8x8_Form);
        widgetBg->setObjectName(QStringLiteral("widgetBg"));
        widgetBg->setMinimumSize(QSize(375, 456));
        widgetBg->setMaximumSize(QSize(375, 456));
        widgetBg->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        pushButton = new PushButtonDone(widgetBg);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(265, 375, 112, 82));
        QFont font;
        font.setFamily(QStringLiteral("Nexa Light"));
        font.setPointSize(26);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        pushButton->setFont(font);
        pushButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-image: url(:/resource/images/upload_setting/Done.png);\n"
"	border-color: rgba(255, 255, 255, 0);\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	border-image: url(:/resource/images/upload_setting/Done_OVER.png);\n"
"	border-color: rgba(255, 255, 255, 0);\n"
"}"));
        pushButton->setDefault(false);
        bgimage = new QLabel(widgetBg);
        bgimage->setObjectName(QStringLiteral("bgimage"));
        bgimage->setGeometry(QRect(15, 15, 348, 345));
        bgimage->setPixmap(QPixmap(QString::fromUtf8(":/resource/images/parameter_input/LED_Matrix/ParameterSetup_8x8LED_Dark.png")));

        gridLayout->addWidget(widgetBg, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(307, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 91, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);


        retranslateUi(Parameter_LED8x8_Form);

        QMetaObject::connectSlotsByName(Parameter_LED8x8_Form);
    } // setupUi

    void retranslateUi(QWidget *Parameter_LED8x8_Form)
    {
        Parameter_LED8x8_Form->setWindowTitle(QApplication::translate("Parameter_LED8x8_Form", "Form", 0));
        pushButton->setText(QApplication::translate("Parameter_LED8x8_Form", "Done", 0));
        pushButton->setShortcut(QApplication::translate("Parameter_LED8x8_Form", "Ctrl+Return", 0));
        bgimage->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Parameter_LED8x8_Form: public Ui_Parameter_LED8x8_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAMETER_LED8X8_FORM_H
