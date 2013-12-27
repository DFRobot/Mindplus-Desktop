/********************************************************************************
** Form generated from reading UI file 'Parameter_DigitalPin_Form.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARAMETER_DIGITALPIN_FORM_H
#define UI_PARAMETER_DIGITALPIN_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include "PushButtonDone.h"

QT_BEGIN_NAMESPACE

class Ui_Parameter_DigitalPin_Form
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QWidget *widgetBg;
    PushButtonDone *pushButton;
    QLineEdit *lineEdit;
    QLabel *label;
    QLabel *backgourndimage;
    QPushButton *DigitalPin_0;
    QPushButton *DigitalPin_1;
    QPushButton *DigitalPin_2;
    QPushButton *DigitalPin_3;
    QPushButton *DigitalPin_4;
    QPushButton *DigitalPin_5;
    QPushButton *DigitalPin_6;
    QPushButton *DigitalPin_7;
    QPushButton *DigitalPin_8;
    QPushButton *DigitalPin_9;
    QPushButton *DigitalPin_10;
    QPushButton *DigitalPin_11;
    QPushButton *DigitalPin_12;
    QPushButton *DigitalPin_13;
    QPushButton *pushButtonMindkit;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *Parameter_DigitalPin_Form)
    {
        if (Parameter_DigitalPin_Form->objectName().isEmpty())
            Parameter_DigitalPin_Form->setObjectName(QStringLiteral("Parameter_DigitalPin_Form"));
        Parameter_DigitalPin_Form->resize(1025, 675);
        Parameter_DigitalPin_Form->setMinimumSize(QSize(1025, 675));
        Parameter_DigitalPin_Form->setStyleSheet(QLatin1String("QWidget#Parameter_DigitalPin_Form\n"
"{\n"
"	border-image: url(:/resource/images/common/Transparent_Black_70.png);\n"
"}"));
        gridLayout = new QGridLayout(Parameter_DigitalPin_Form);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalSpacer = new QSpacerItem(20, 114, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(259, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        widgetBg = new QWidget(Parameter_DigitalPin_Form);
        widgetBg->setObjectName(QStringLiteral("widgetBg"));
        widgetBg->setMinimumSize(QSize(471, 411));
        widgetBg->setMaximumSize(QSize(471, 411));
        widgetBg->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        pushButton = new PushButtonDone(widgetBg);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(360, 330, 112, 82));
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
        lineEdit = new QLineEdit(widgetBg);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(110, 350, 211, 31));
        lineEdit->setStyleSheet(QStringLiteral("font: 17pt \"Microsoft YaHei UI\";"));
        label = new QLabel(widgetBg);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 352, 31, 25));
        label->setStyleSheet(QLatin1String("color: rgb(105, 105, 105);\n"
"font: 13pt \"Microsoft JhengHei\";"));
        backgourndimage = new QLabel(widgetBg);
        backgourndimage->setObjectName(QStringLiteral("backgourndimage"));
        backgourndimage->setGeometry(QRect(20, 10, 421, 321));
        backgourndimage->setPixmap(QPixmap(QString::fromUtf8(":/resource/images/parameter_input/DigitalPin/ArduinoUNO_Digital.png")));
        DigitalPin_0 = new QPushButton(widgetBg);
        DigitalPin_0->setObjectName(QStringLiteral("DigitalPin_0"));
        DigitalPin_0->setGeometry(QRect(403, 13, 16, 41));
        DigitalPin_0->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-color: rgba(0, 255, 0, 0);\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	border-color: rgba(255, 0, 0, 0);\n"
"}"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/resource/images/parameter_input/AnalogPin/SelectBox.png"), QSize(), QIcon::Normal, QIcon::Off);
        DigitalPin_0->setIcon(icon);
        DigitalPin_0->setIconSize(QSize(0, 37));
        DigitalPin_0->setFlat(true);
        DigitalPin_1 = new QPushButton(widgetBg);
        DigitalPin_1->setObjectName(QStringLiteral("DigitalPin_1"));
        DigitalPin_1->setGeometry(QRect(388, 13, 16, 41));
        DigitalPin_1->setIcon(icon);
        DigitalPin_1->setIconSize(QSize(0, 37));
        DigitalPin_1->setFlat(true);
        DigitalPin_2 = new QPushButton(widgetBg);
        DigitalPin_2->setObjectName(QStringLiteral("DigitalPin_2"));
        DigitalPin_2->setGeometry(QRect(373, 13, 16, 41));
        DigitalPin_2->setIcon(icon);
        DigitalPin_2->setIconSize(QSize(0, 37));
        DigitalPin_2->setFlat(true);
        DigitalPin_3 = new QPushButton(widgetBg);
        DigitalPin_3->setObjectName(QStringLiteral("DigitalPin_3"));
        DigitalPin_3->setGeometry(QRect(357, 13, 16, 41));
        DigitalPin_3->setIcon(icon);
        DigitalPin_3->setIconSize(QSize(0, 37));
        DigitalPin_3->setFlat(true);
        DigitalPin_4 = new QPushButton(widgetBg);
        DigitalPin_4->setObjectName(QStringLiteral("DigitalPin_4"));
        DigitalPin_4->setGeometry(QRect(342, 13, 16, 41));
        DigitalPin_4->setIcon(icon);
        DigitalPin_4->setIconSize(QSize(0, 37));
        DigitalPin_4->setFlat(true);
        DigitalPin_5 = new QPushButton(widgetBg);
        DigitalPin_5->setObjectName(QStringLiteral("DigitalPin_5"));
        DigitalPin_5->setGeometry(QRect(327, 13, 16, 41));
        DigitalPin_5->setIcon(icon);
        DigitalPin_5->setIconSize(QSize(0, 37));
        DigitalPin_5->setFlat(true);
        DigitalPin_6 = new QPushButton(widgetBg);
        DigitalPin_6->setObjectName(QStringLiteral("DigitalPin_6"));
        DigitalPin_6->setGeometry(QRect(312, 13, 16, 41));
        DigitalPin_6->setIcon(icon);
        DigitalPin_6->setIconSize(QSize(0, 37));
        DigitalPin_6->setFlat(true);
        DigitalPin_7 = new QPushButton(widgetBg);
        DigitalPin_7->setObjectName(QStringLiteral("DigitalPin_7"));
        DigitalPin_7->setGeometry(QRect(297, 13, 16, 41));
        DigitalPin_7->setIcon(icon);
        DigitalPin_7->setIconSize(QSize(0, 37));
        DigitalPin_7->setFlat(true);
        DigitalPin_8 = new QPushButton(widgetBg);
        DigitalPin_8->setObjectName(QStringLiteral("DigitalPin_8"));
        DigitalPin_8->setGeometry(QRect(267, 13, 16, 41));
        DigitalPin_8->setIcon(icon);
        DigitalPin_8->setIconSize(QSize(0, 37));
        DigitalPin_8->setFlat(true);
        DigitalPin_9 = new QPushButton(widgetBg);
        DigitalPin_9->setObjectName(QStringLiteral("DigitalPin_9"));
        DigitalPin_9->setGeometry(QRect(252, 13, 16, 41));
        DigitalPin_9->setIcon(icon);
        DigitalPin_9->setIconSize(QSize(0, 37));
        DigitalPin_9->setFlat(true);
        DigitalPin_10 = new QPushButton(widgetBg);
        DigitalPin_10->setObjectName(QStringLiteral("DigitalPin_10"));
        DigitalPin_10->setGeometry(QRect(237, 13, 16, 41));
        DigitalPin_10->setIcon(icon);
        DigitalPin_10->setIconSize(QSize(0, 37));
        DigitalPin_10->setFlat(true);
        DigitalPin_11 = new QPushButton(widgetBg);
        DigitalPin_11->setObjectName(QStringLiteral("DigitalPin_11"));
        DigitalPin_11->setGeometry(QRect(222, 13, 16, 41));
        DigitalPin_11->setIcon(icon);
        DigitalPin_11->setIconSize(QSize(0, 37));
        DigitalPin_11->setFlat(true);
        DigitalPin_12 = new QPushButton(widgetBg);
        DigitalPin_12->setObjectName(QStringLiteral("DigitalPin_12"));
        DigitalPin_12->setGeometry(QRect(207, 13, 16, 41));
        DigitalPin_12->setIcon(icon);
        DigitalPin_12->setIconSize(QSize(0, 37));
        DigitalPin_12->setFlat(true);
        DigitalPin_13 = new QPushButton(widgetBg);
        DigitalPin_13->setObjectName(QStringLiteral("DigitalPin_13"));
        DigitalPin_13->setGeometry(QRect(192, 13, 16, 41));
        DigitalPin_13->setIcon(icon);
        DigitalPin_13->setIconSize(QSize(0, 37));
        DigitalPin_13->setFlat(true);
        pushButtonMindkit = new QPushButton(widgetBg);
        pushButtonMindkit->setObjectName(QStringLiteral("pushButtonMindkit"));
        pushButtonMindkit->setGeometry(QRect(0, 390, 75, 23));

        gridLayout->addWidget(widgetBg, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(259, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 114, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);

        QWidget::setTabOrder(lineEdit, pushButton);

        retranslateUi(Parameter_DigitalPin_Form);

        QMetaObject::connectSlotsByName(Parameter_DigitalPin_Form);
    } // setupUi

    void retranslateUi(QWidget *Parameter_DigitalPin_Form)
    {
        Parameter_DigitalPin_Form->setWindowTitle(QApplication::translate("Parameter_DigitalPin_Form", "Form", 0));
        pushButton->setText(QApplication::translate("Parameter_DigitalPin_Form", "Done", 0));
        pushButton->setShortcut(QApplication::translate("Parameter_DigitalPin_Form", "Ctrl+Return", 0));
        label->setText(QApplication::translate("Parameter_DigitalPin_Form", "Pin:", 0));
        backgourndimage->setText(QString());
        DigitalPin_0->setText(QString());
        DigitalPin_1->setText(QString());
        DigitalPin_2->setText(QString());
        DigitalPin_3->setText(QString());
        DigitalPin_4->setText(QString());
        DigitalPin_5->setText(QString());
        DigitalPin_6->setText(QString());
        DigitalPin_7->setText(QString());
        DigitalPin_8->setText(QString());
        DigitalPin_9->setText(QString());
        DigitalPin_10->setText(QString());
        DigitalPin_11->setText(QString());
        DigitalPin_12->setText(QString());
        DigitalPin_13->setText(QString());
        pushButtonMindkit->setText(QApplication::translate("Parameter_DigitalPin_Form", "MindKit", 0));
    } // retranslateUi

};

namespace Ui {
    class Parameter_DigitalPin_Form: public Ui_Parameter_DigitalPin_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAMETER_DIGITALPIN_FORM_H
