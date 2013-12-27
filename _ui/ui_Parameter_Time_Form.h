/********************************************************************************
** Form generated from reading UI file 'Parameter_Time_Form.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARAMETER_TIME_FORM_H
#define UI_PARAMETER_TIME_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include "PushButtonDone.h"

QT_BEGIN_NAMESPACE

class Ui_Parameter_Time_Form
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QWidget *widgetBg;
    QLabel *label_4;
    PushButtonDone *pushButton;
    QLabel *label_6;
    QLabel *label;
    QLineEdit *lineEditMin;
    QLineEdit *lineEditSec;
    QLineEdit *lineEditMsec;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *Parameter_Time_Form)
    {
        if (Parameter_Time_Form->objectName().isEmpty())
            Parameter_Time_Form->setObjectName(QStringLiteral("Parameter_Time_Form"));
        Parameter_Time_Form->resize(1025, 675);
        Parameter_Time_Form->setMinimumSize(QSize(1025, 675));
        Parameter_Time_Form->setStyleSheet(QLatin1String("QWidget#Parameter_Time_Form\n"
"{\n"
"	border-image: url(:/resource/images/common/Transparent_Black_70.png);\n"
"}"));
        gridLayout = new QGridLayout(Parameter_Time_Form);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalSpacer = new QSpacerItem(20, 262, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(216, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        widgetBg = new QWidget(Parameter_Time_Form);
        widgetBg->setObjectName(QStringLiteral("widgetBg"));
        widgetBg->setMinimumSize(QSize(556, 115));
        widgetBg->setMaximumSize(QSize(556, 115));
        widgetBg->setStyleSheet(QLatin1String("QWidget#widgetBg\n"
"{\n"
"	border-image: url(:/resource/images/parameter_input/Normal/Background_Empty.png);\n"
"}"));
        label_4 = new QLabel(widgetBg);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(170, 48, 61, 22));
        label_4->setStyleSheet(QLatin1String("color: rgb(105, 105, 105);\n"
"font: 11pt \"Microsoft YaHei UI\";"));
        pushButton = new PushButtonDone(widgetBg);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(434, 23, 112, 82));
        QFont font;
        font.setFamily(QStringLiteral("Nexa Light"));
        font.setPointSize(26);
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
"}\n"
"QPushButton:pressed\n"
"{\n"
"	border-image: url(:/resource/images/upload_setting/Done.png);\n"
"	border-color: rgba(255, 255, 255, 0);\n"
"}"));
        label_6 = new QLabel(widgetBg);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(280, 48, 91, 22));
        label_6->setStyleSheet(QLatin1String("color: rgb(105, 105, 105);\n"
"font: 11pt \"Microsoft YaHei UI\";"));
        label = new QLabel(widgetBg);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 48, 61, 22));
        label->setStyleSheet(QLatin1String("color: rgb(105, 105, 105);\n"
"font: 11pt \"Microsoft YaHei UI\";"));
        lineEditMin = new QLineEdit(widgetBg);
        lineEditMin->setObjectName(QStringLiteral("lineEditMin"));
        lineEditMin->setGeometry(QRect(100, 41, 51, 31));
        lineEditMin->setStyleSheet(QStringLiteral("font: 17pt \"Microsoft YaHei UI\";"));
        lineEditSec = new QLineEdit(widgetBg);
        lineEditSec->setObjectName(QStringLiteral("lineEditSec"));
        lineEditSec->setGeometry(QRect(230, 41, 41, 31));
        lineEditSec->setStyleSheet(QStringLiteral("font: 17pt \"Microsoft YaHei UI\";"));
        lineEditMsec = new QLineEdit(widgetBg);
        lineEditMsec->setObjectName(QStringLiteral("lineEditMsec"));
        lineEditMsec->setGeometry(QRect(370, 41, 61, 31));
        lineEditMsec->setStyleSheet(QStringLiteral("font: 17pt \"Microsoft YaHei UI\";"));

        gridLayout->addWidget(widgetBg, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(217, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 262, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);

        QWidget::setTabOrder(lineEditMin, lineEditSec);
        QWidget::setTabOrder(lineEditSec, lineEditMsec);
        QWidget::setTabOrder(lineEditMsec, pushButton);

        retranslateUi(Parameter_Time_Form);

        QMetaObject::connectSlotsByName(Parameter_Time_Form);
    } // setupUi

    void retranslateUi(QWidget *Parameter_Time_Form)
    {
        Parameter_Time_Form->setWindowTitle(QApplication::translate("Parameter_Time_Form", "Form", 0));
        label_4->setText(QApplication::translate("Parameter_Time_Form", "Second:", 0));
        pushButton->setText(QString());
        label_6->setText(QApplication::translate("Parameter_Time_Form", "Millisecond:", 0));
        label->setText(QApplication::translate("Parameter_Time_Form", "Minute:", 0));
    } // retranslateUi

};

namespace Ui {
    class Parameter_Time_Form: public Ui_Parameter_Time_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAMETER_TIME_FORM_H
