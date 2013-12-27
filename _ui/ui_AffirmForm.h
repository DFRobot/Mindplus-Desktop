/********************************************************************************
** Form generated from reading UI file 'AffirmForm.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AFFIRMFORM_H
#define UI_AFFIRMFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AffirmForm
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QWidget *widgetBg;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer;
    QWidget *widgetFunctionArea;
    QLabel *labelTitle;
    QLabel *labelBack;
    QLabel *labelNotSave;
    QLabel *labelSave;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *AffirmForm)
    {
        if (AffirmForm->objectName().isEmpty())
            AffirmForm->setObjectName(QStringLiteral("AffirmForm"));
        AffirmForm->resize(1025, 675);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AffirmForm->sizePolicy().hasHeightForWidth());
        AffirmForm->setSizePolicy(sizePolicy);
        AffirmForm->setMinimumSize(QSize(1025, 675));
        AffirmForm->setStyleSheet(QLatin1String("QWidget#AffirmForm\n"
"{\n"
"border-image: url(:/resource/images/common/Transparent_Black_70.png);\n"
"}"));
        gridLayout = new QGridLayout(AffirmForm);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(0);
        verticalSpacer = new QSpacerItem(20, 271, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 271, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 0, 1, 1);

        widgetBg = new QWidget(AffirmForm);
        widgetBg->setObjectName(QStringLiteral("widgetBg"));
        widgetBg->setMinimumSize(QSize(1025, 115));
        widgetBg->setStyleSheet(QLatin1String("QWidget#widgetBg\n"
"{\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        gridLayout_2 = new QGridLayout(widgetBg);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalSpacer = new QSpacerItem(127, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 0, 1, 1);

        widgetFunctionArea = new QWidget(widgetBg);
        widgetFunctionArea->setObjectName(QStringLiteral("widgetFunctionArea"));
        widgetFunctionArea->setMinimumSize(QSize(765, 115));
        widgetFunctionArea->setMaximumSize(QSize(765, 115));
        widgetFunctionArea->setStyleSheet(QStringLiteral(""));
        labelTitle = new QLabel(widgetFunctionArea);
        labelTitle->setObjectName(QStringLiteral("labelTitle"));
        labelTitle->setGeometry(QRect(20, 10, 181, 41));
        labelTitle->setStyleSheet(QLatin1String("font: 25pt \"Tahoma\";\n"
"color: rgb(82, 164, 225);"));
        labelTitle->setAlignment(Qt::AlignCenter);
        labelBack = new QLabel(widgetFunctionArea);
        labelBack->setObjectName(QStringLiteral("labelBack"));
        labelBack->setGeometry(QRect(230, 70, 81, 31));
        labelBack->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"	font: 17pt \"Tahoma\";\n"
"	color: rgb(0, 0, 0);\n"
"}\n"
"QLabel:hover\n"
"{\n"
"	font: 17pt \"Tahoma\";\n"
"	color: rgb(82, 164, 225);\n"
"}\n"
"QLabel:pressed\n"
"{\n"
"	font: 17pt \"Tahoma\";\n"
"	color: rgb(0, 0, 0);\n"
"}"));
        labelBack->setAlignment(Qt::AlignCenter);
        labelNotSave = new QLabel(widgetFunctionArea);
        labelNotSave->setObjectName(QStringLiteral("labelNotSave"));
        labelNotSave->setGeometry(QRect(320, 70, 121, 31));
        labelNotSave->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"	font: 17pt \"Tahoma\";\n"
"	color: rgb(0, 0, 0);\n"
"}\n"
"QLabel:hover\n"
"{\n"
"	font: 17pt \"Tahoma\";\n"
"	color: rgb(82, 164, 225);\n"
"}\n"
"QLabel:pressed\n"
"{\n"
"	font: 17pt \"Tahoma\";\n"
"	color: rgb(0, 0, 0);\n"
"}"));
        labelNotSave->setAlignment(Qt::AlignCenter);
        labelSave = new QLabel(widgetFunctionArea);
        labelSave->setObjectName(QStringLiteral("labelSave"));
        labelSave->setGeometry(QRect(460, 50, 161, 51));
        labelSave->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"	font: 37pt \"Tahoma\";\n"
"	color: rgb(0, 0, 0);\n"
"}\n"
"QLabel:hover\n"
"{\n"
"	font: 37pt \"Tahoma\";\n"
"	color: rgb(82, 164, 225);\n"
"}\n"
"QLabel:pressed\n"
"{\n"
"	font: 37pt \"Tahoma\";\n"
"	color: rgb(0, 0, 0);\n"
"}"));
        labelSave->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(widgetFunctionArea, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(127, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 2, 1, 1);


        gridLayout->addWidget(widgetBg, 1, 0, 1, 1);


        retranslateUi(AffirmForm);

        QMetaObject::connectSlotsByName(AffirmForm);
    } // setupUi

    void retranslateUi(QWidget *AffirmForm)
    {
        AffirmForm->setWindowTitle(QApplication::translate("AffirmForm", "Form", 0));
        labelTitle->setText(QApplication::translate("AffirmForm", "You Want?", 0));
        labelBack->setText(QApplication::translate("AffirmForm", "Cancel", 0));
        labelNotSave->setText(QApplication::translate("AffirmForm", "Don't Save", 0));
        labelSave->setText(QApplication::translate("AffirmForm", "Save", 0));
    } // retranslateUi

};

namespace Ui {
    class AffirmForm: public Ui_AffirmForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AFFIRMFORM_H
