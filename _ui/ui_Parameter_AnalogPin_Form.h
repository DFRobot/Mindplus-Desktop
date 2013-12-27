/********************************************************************************
** Form generated from reading UI file 'Parameter_AnalogPin_Form.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARAMETER_ANALOGPIN_FORM_H
#define UI_PARAMETER_ANALOGPIN_FORM_H

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

class Ui_Parameter_AnalogPin_Form
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QWidget *widgetBg;
    PushButtonDone *pushButton;
    QLineEdit *lineEdit;
    QLabel *label;
    QLabel *label_2;
    QPushButton *AnalogPin_0;
    QPushButton *AnalogPin_1;
    QPushButton *AnalogPin_2;
    QPushButton *AnalogPin_3;
    QPushButton *AnalogPin_4;
    QPushButton *AnalogPin_5;
    QPushButton *pushButtonMindkit;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *Parameter_AnalogPin_Form)
    {
        if (Parameter_AnalogPin_Form->objectName().isEmpty())
            Parameter_AnalogPin_Form->setObjectName(QStringLiteral("Parameter_AnalogPin_Form"));
        Parameter_AnalogPin_Form->resize(1025, 675);
        Parameter_AnalogPin_Form->setMinimumSize(QSize(1025, 675));
        Parameter_AnalogPin_Form->setStyleSheet(QLatin1String("QWidget#Parameter_AnalogPin_Form\n"
"{\n"
"	border-image: url(:/resource/images/common/Transparent_Black_70.png);\n"
"}"));
        gridLayout = new QGridLayout(Parameter_AnalogPin_Form);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalSpacer = new QSpacerItem(20, 114, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(259, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        widgetBg = new QWidget(Parameter_AnalogPin_Form);
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
        label_2 = new QLabel(widgetBg);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 10, 421, 321));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/resource/images/parameter_input/AnalogPin/ArduinoUNO_Analog.png")));
        AnalogPin_0 = new QPushButton(widgetBg);
        AnalogPin_0->setObjectName(QStringLiteral("AnalogPin_0"));
        AnalogPin_0->setGeometry(QRect(327, 284, 16, 41));
        AnalogPin_0->setStyleSheet(QLatin1String("QPushButton\n"
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
        AnalogPin_0->setIcon(icon);
        AnalogPin_0->setIconSize(QSize(0, 37));
        AnalogPin_0->setFlat(true);
        AnalogPin_1 = new QPushButton(widgetBg);
        AnalogPin_1->setObjectName(QStringLiteral("AnalogPin_1"));
        AnalogPin_1->setGeometry(QRect(342, 284, 16, 41));
        AnalogPin_1->setIcon(icon);
        AnalogPin_1->setIconSize(QSize(0, 37));
        AnalogPin_1->setFlat(true);
        AnalogPin_2 = new QPushButton(widgetBg);
        AnalogPin_2->setObjectName(QStringLiteral("AnalogPin_2"));
        AnalogPin_2->setGeometry(QRect(357, 284, 16, 41));
        AnalogPin_2->setIcon(icon);
        AnalogPin_2->setIconSize(QSize(0, 37));
        AnalogPin_2->setFlat(true);
        AnalogPin_3 = new QPushButton(widgetBg);
        AnalogPin_3->setObjectName(QStringLiteral("AnalogPin_3"));
        AnalogPin_3->setGeometry(QRect(373, 284, 16, 41));
        AnalogPin_3->setIcon(icon);
        AnalogPin_3->setIconSize(QSize(0, 37));
        AnalogPin_3->setFlat(true);
        AnalogPin_4 = new QPushButton(widgetBg);
        AnalogPin_4->setObjectName(QStringLiteral("AnalogPin_4"));
        AnalogPin_4->setGeometry(QRect(389, 284, 16, 41));
        AnalogPin_4->setIcon(icon);
        AnalogPin_4->setIconSize(QSize(0, 37));
        AnalogPin_4->setFlat(true);
        AnalogPin_5 = new QPushButton(widgetBg);
        AnalogPin_5->setObjectName(QStringLiteral("AnalogPin_5"));
        AnalogPin_5->setGeometry(QRect(403, 284, 16, 41));
        AnalogPin_5->setIcon(icon);
        AnalogPin_5->setIconSize(QSize(0, 37));
        AnalogPin_5->setFlat(true);
        pushButtonMindkit = new QPushButton(widgetBg);
        pushButtonMindkit->setObjectName(QStringLiteral("pushButtonMindkit"));
        pushButtonMindkit->setGeometry(QRect(0, 382, 61, 31));

        gridLayout->addWidget(widgetBg, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(259, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 114, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);

        QWidget::setTabOrder(lineEdit, pushButton);

        retranslateUi(Parameter_AnalogPin_Form);

        QMetaObject::connectSlotsByName(Parameter_AnalogPin_Form);
    } // setupUi

    void retranslateUi(QWidget *Parameter_AnalogPin_Form)
    {
        Parameter_AnalogPin_Form->setWindowTitle(QApplication::translate("Parameter_AnalogPin_Form", "Form", 0));
        pushButton->setText(QApplication::translate("Parameter_AnalogPin_Form", "Done", 0));
        pushButton->setShortcut(QApplication::translate("Parameter_AnalogPin_Form", "Ctrl+Return", 0));
        label->setText(QApplication::translate("Parameter_AnalogPin_Form", "Pin:", 0));
        label_2->setText(QString());
        AnalogPin_0->setText(QString());
        AnalogPin_1->setText(QString());
        AnalogPin_2->setText(QString());
        AnalogPin_3->setText(QString());
        AnalogPin_4->setText(QString());
        AnalogPin_5->setText(QString());
        pushButtonMindkit->setText(QApplication::translate("Parameter_AnalogPin_Form", "Mindkit", 0));
    } // retranslateUi

};

namespace Ui {
    class Parameter_AnalogPin_Form: public Ui_Parameter_AnalogPin_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAMETER_ANALOGPIN_FORM_H
