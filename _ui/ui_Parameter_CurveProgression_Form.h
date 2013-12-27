/********************************************************************************
** Form generated from reading UI file 'Parameter_CurveProgression_Form.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARAMETER_CURVEPROGRESSION_FORM_H
#define UI_PARAMETER_CURVEPROGRESSION_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include "CurveProgressionWidget.h"
#include "PushButtonDone.h"

QT_BEGIN_NAMESPACE

class Ui_Parameter_CurveProgression_Form
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widgetBg;
    PushButtonDone *pushButton;
    CurveProgressionWidget *curveBG;
    QDoubleSpinBox *currentPosY;
    QDoubleSpinBox *currentPosX;
    QLabel *currentPosLabel_2;

    void setupUi(QWidget *Parameter_CurveProgression_Form)
    {
        if (Parameter_CurveProgression_Form->objectName().isEmpty())
            Parameter_CurveProgression_Form->setObjectName(QStringLiteral("Parameter_CurveProgression_Form"));
        Parameter_CurveProgression_Form->resize(1025, 675);
        Parameter_CurveProgression_Form->setMinimumSize(QSize(1025, 675));
        Parameter_CurveProgression_Form->setStyleSheet(QLatin1String("QWidget#Parameter_CurveProgression_Form\n"
"{\n"
"	border-image: url(:/resource/images/common/Transparent_Black_70.png);\n"
"}"));
        gridLayout = new QGridLayout(Parameter_CurveProgression_Form);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalSpacer = new QSpacerItem(20, 92, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(307, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 91, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(307, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        widgetBg = new QWidget(Parameter_CurveProgression_Form);
        widgetBg->setObjectName(QStringLiteral("widgetBg"));
        widgetBg->setMinimumSize(QSize(800, 480));
        widgetBg->setMaximumSize(QSize(800, 480));
        widgetBg->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        pushButton = new PushButtonDone(widgetBg);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(690, 400, 112, 82));
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
        curveBG = new CurveProgressionWidget(widgetBg);
        curveBG->setObjectName(QStringLiteral("curveBG"));
        curveBG->setGeometry(QRect(20, 20, 761, 381));
        curveBG->setAutoFillBackground(false);
        curveBG->setStyleSheet(QStringLiteral("border-image: url(:/resource/images/parameter_input/CurveProgression/CurveProgression_BG.png);"));
        currentPosY = new QDoubleSpinBox(widgetBg);
        currentPosY->setObjectName(QStringLiteral("currentPosY"));
        currentPosY->setGeometry(QRect(447, 426, 62, 22));
        currentPosY->setStyleSheet(QString::fromUtf8("font: 8pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        currentPosY->setDecimals(1);
        currentPosY->setMaximum(100);
        currentPosY->setSingleStep(0.1);
        currentPosX = new QDoubleSpinBox(widgetBg);
        currentPosX->setObjectName(QStringLiteral("currentPosX"));
        currentPosX->setGeometry(QRect(380, 426, 62, 22));
        currentPosX->setStyleSheet(QString::fromUtf8("font: 8pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        currentPosX->setDecimals(1);
        currentPosX->setMaximum(100);
        currentPosX->setSingleStep(0.1);
        currentPosLabel_2 = new QLabel(widgetBg);
        currentPosLabel_2->setObjectName(QStringLiteral("currentPosLabel_2"));
        currentPosLabel_2->setGeometry(QRect(289, 429, 91, 16));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(8);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        currentPosLabel_2->setFont(font1);
        currentPosLabel_2->setStyleSheet(QString::fromUtf8("font: 8pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout->addWidget(widgetBg, 1, 1, 1, 1);


        retranslateUi(Parameter_CurveProgression_Form);

        QMetaObject::connectSlotsByName(Parameter_CurveProgression_Form);
    } // setupUi

    void retranslateUi(QWidget *Parameter_CurveProgression_Form)
    {
        Parameter_CurveProgression_Form->setWindowTitle(QApplication::translate("Parameter_CurveProgression_Form", "Form", 0));
        pushButton->setText(QApplication::translate("Parameter_CurveProgression_Form", "Done", 0));
        pushButton->setShortcut(QApplication::translate("Parameter_CurveProgression_Form", "Ctrl+Return", 0));
        currentPosY->setSuffix(QApplication::translate("Parameter_CurveProgression_Form", "%", 0));
        currentPosX->setSuffix(QApplication::translate("Parameter_CurveProgression_Form", "%", 0));
        currentPosLabel_2->setText(QApplication::translate("Parameter_CurveProgression_Form", "Current Postion:", 0));
    } // retranslateUi

};

namespace Ui {
    class Parameter_CurveProgression_Form: public Ui_Parameter_CurveProgression_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAMETER_CURVEPROGRESSION_FORM_H
