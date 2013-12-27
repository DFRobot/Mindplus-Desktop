/********************************************************************************
** Form generated from reading UI file 'Parameter_operator_Form.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARAMETER_OPERATOR_FORM_H
#define UI_PARAMETER_OPERATOR_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Parameter_operator_Form
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QWidget *widgetBg;
    QPushButton *operator_0;
    QPushButton *operator_1;
    QPushButton *operator_2;
    QPushButton *operator_3;
    QPushButton *operator_4;
    QPushButton *operator_5;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *Parameter_operator_Form)
    {
        if (Parameter_operator_Form->objectName().isEmpty())
            Parameter_operator_Form->setObjectName(QStringLiteral("Parameter_operator_Form"));
        Parameter_operator_Form->resize(1025, 675);
        Parameter_operator_Form->setMinimumSize(QSize(1025, 675));
        Parameter_operator_Form->setMaximumSize(QSize(16777215, 675));
        Parameter_operator_Form->setStyleSheet(QLatin1String("QWidget#Parameter_operator_Form\n"
"{\n"
"	border-image: url(:/resource/images/common/Transparent_Black_70.png);\n"
"}"));
        gridLayout = new QGridLayout(Parameter_operator_Form);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalSpacer = new QSpacerItem(20, 229, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(304, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        widgetBg = new QWidget(Parameter_operator_Form);
        widgetBg->setObjectName(QStringLiteral("widgetBg"));
        widgetBg->setMinimumSize(QSize(381, 181));
        widgetBg->setMaximumSize(QSize(381, 181));
        widgetBg->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        operator_0 = new QPushButton(widgetBg);
        operator_0->setObjectName(QStringLiteral("operator_0"));
        operator_0->setGeometry(QRect(160, 20, 61, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(18);
        operator_0->setFont(font);
        operator_0->setStyleSheet(QLatin1String("background-color: rgb(59, 59, 59);\n"
"color: rgb(255, 255, 255);"));
        operator_0->setIconSize(QSize(0, 37));
        operator_0->setFlat(false);
        operator_1 = new QPushButton(widgetBg);
        operator_1->setObjectName(QStringLiteral("operator_1"));
        operator_1->setGeometry(QRect(160, 100, 61, 61));
        operator_1->setFont(font);
        operator_1->setStyleSheet(QLatin1String("background-color: rgb(59, 59, 59);\n"
"color: rgb(255, 255, 255);"));
        operator_1->setIconSize(QSize(0, 37));
        operator_1->setFlat(false);
        operator_2 = new QPushButton(widgetBg);
        operator_2->setObjectName(QStringLiteral("operator_2"));
        operator_2->setGeometry(QRect(80, 20, 61, 61));
        operator_2->setFont(font);
        operator_2->setStyleSheet(QLatin1String("background-color: rgb(59, 59, 59);\n"
"color: rgb(255, 255, 255);"));
        operator_2->setIconSize(QSize(0, 37));
        operator_2->setFlat(false);
        operator_3 = new QPushButton(widgetBg);
        operator_3->setObjectName(QStringLiteral("operator_3"));
        operator_3->setGeometry(QRect(80, 100, 61, 61));
        operator_3->setFont(font);
        operator_3->setStyleSheet(QLatin1String("background-color: rgb(59, 59, 59);\n"
"color: rgb(255, 255, 255);"));
        operator_3->setIconSize(QSize(0, 37));
        operator_3->setFlat(false);
        operator_4 = new QPushButton(widgetBg);
        operator_4->setObjectName(QStringLiteral("operator_4"));
        operator_4->setGeometry(QRect(240, 20, 61, 61));
        operator_4->setFont(font);
        operator_4->setStyleSheet(QLatin1String("background-color: rgb(59, 59, 59);\n"
"color: rgb(255, 255, 255);"));
        operator_4->setIconSize(QSize(0, 37));
        operator_4->setFlat(false);
        operator_5 = new QPushButton(widgetBg);
        operator_5->setObjectName(QStringLiteral("operator_5"));
        operator_5->setGeometry(QRect(240, 100, 61, 61));
        operator_5->setFont(font);
        operator_5->setStyleSheet(QLatin1String("background-color: rgb(59, 59, 59);\n"
"color: rgb(255, 255, 255);"));
        operator_5->setIconSize(QSize(0, 37));
        operator_5->setFlat(false);

        gridLayout->addWidget(widgetBg, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(304, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 229, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);


        retranslateUi(Parameter_operator_Form);

        QMetaObject::connectSlotsByName(Parameter_operator_Form);
    } // setupUi

    void retranslateUi(QWidget *Parameter_operator_Form)
    {
        Parameter_operator_Form->setWindowTitle(QApplication::translate("Parameter_operator_Form", "Form", 0));
        operator_0->setText(QApplication::translate("Parameter_operator_Form", "=", 0));
        operator_1->setText(QApplication::translate("Parameter_operator_Form", "\342\211\240", 0));
        operator_2->setText(QApplication::translate("Parameter_operator_Form", "<", 0));
        operator_3->setText(QApplication::translate("Parameter_operator_Form", "<=", 0));
        operator_4->setText(QApplication::translate("Parameter_operator_Form", ">", 0));
        operator_5->setText(QApplication::translate("Parameter_operator_Form", ">=", 0));
    } // retranslateUi

};

namespace Ui {
    class Parameter_operator_Form: public Ui_Parameter_operator_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAMETER_OPERATOR_FORM_H
