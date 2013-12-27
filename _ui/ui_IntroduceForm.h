/********************************************************************************
** Form generated from reading UI file 'IntroduceForm.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTRODUCEFORM_H
#define UI_INTRODUCEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include "IntroduceFromRight.h"

QT_BEGIN_NAMESPACE

class Ui_IntroduceForm
{
public:
    QGridLayout *gridLayout;
    QWidget *widgetLeft;
    QGridLayout *gridLayout_2;
    QWidget *widgetList;
    QGridLayout *gridLayout_3;
    QListWidget *listWidget;
    QWidget *widgetDown;
    QWidget *widget_4;
    QWidget *widgetBottom;
    QWidget *widgetLogo;
    QWidget *widgetUp;
    QWidget *widget_2;
    IntroduceFromRight *widgetShowIntroduce;
    QGridLayout *gridLayout_4;
    QWidget *widgetMid;
    QWidget *widgetRight;
    QGridLayout *gridLayout_5;
    QWidget *widgetTitle;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonClose;
    QWidget *widget;
    QLabel *labelText;
    QLabel *labelImage;

    void setupUi(QWidget *IntroduceForm)
    {
        if (IntroduceForm->objectName().isEmpty())
            IntroduceForm->setObjectName(QStringLiteral("IntroduceForm"));
        IntroduceForm->resize(1025, 675);
        IntroduceForm->setMinimumSize(QSize(1025, 675));
        gridLayout = new QGridLayout(IntroduceForm);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        widgetLeft = new QWidget(IntroduceForm);
        widgetLeft->setObjectName(QStringLiteral("widgetLeft"));
        widgetLeft->setMinimumSize(QSize(180, 675));
        widgetLeft->setMaximumSize(QSize(180, 16777215));
        widgetLeft->setStyleSheet(QLatin1String("QWidget#widgetLeft\n"
"{\n"
"	border-image: url(:/resource/images/common/Transparent_White_80.png);\n"
"}"));
        gridLayout_2 = new QGridLayout(widgetLeft);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        widgetList = new QWidget(widgetLeft);
        widgetList->setObjectName(QStringLiteral("widgetList"));
        widgetList->setMinimumSize(QSize(180, 0));
        widgetList->setMaximumSize(QSize(180, 16777215));
        widgetList->setStyleSheet(QStringLiteral(""));
        gridLayout_3 = new QGridLayout(widgetList);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(7, 0, 7, 0);
        listWidget = new QListWidget(widgetList);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setStyleSheet(QStringLiteral(""));
        listWidget->setSpacing(3);

        gridLayout_3->addWidget(listWidget, 0, 0, 1, 1);


        gridLayout_2->addWidget(widgetList, 2, 0, 1, 1);

        widgetDown = new QWidget(widgetLeft);
        widgetDown->setObjectName(QStringLiteral("widgetDown"));
        widgetDown->setMinimumSize(QSize(180, 21));
        widgetDown->setMaximumSize(QSize(180, 21));
        widgetDown->setStyleSheet(QStringLiteral(""));
        widget_4 = new QWidget(widgetDown);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setGeometry(QRect(30, 0, 120, 12));
        widget_4->setStyleSheet(QStringLiteral("border-image: url(:/resource/images/bb_classify/roll_down.png);"));

        gridLayout_2->addWidget(widgetDown, 3, 0, 1, 1);

        widgetBottom = new QWidget(widgetLeft);
        widgetBottom->setObjectName(QStringLiteral("widgetBottom"));
        widgetBottom->setMinimumSize(QSize(180, 76));
        widgetBottom->setMaximumSize(QSize(180, 76));
        widgetBottom->setStyleSheet(QStringLiteral(""));

        gridLayout_2->addWidget(widgetBottom, 4, 0, 1, 1);

        widgetLogo = new QWidget(widgetLeft);
        widgetLogo->setObjectName(QStringLiteral("widgetLogo"));
        widgetLogo->setMinimumSize(QSize(180, 61));
        widgetLogo->setMaximumSize(QSize(180, 61));
        widgetLogo->setStyleSheet(QLatin1String("QWidget#label\n"
"{\n"
"	border-image: url(:/resource/images/common/Transparent_White_70.png);\n"
"}"));

        gridLayout_2->addWidget(widgetLogo, 0, 0, 1, 1);

        widgetUp = new QWidget(widgetLeft);
        widgetUp->setObjectName(QStringLiteral("widgetUp"));
        widgetUp->setMinimumSize(QSize(180, 21));
        widgetUp->setMaximumSize(QSize(180, 21));
        widgetUp->setStyleSheet(QStringLiteral(""));
        widget_2 = new QWidget(widgetUp);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(30, 10, 120, 12));
        widget_2->setStyleSheet(QStringLiteral("border-image: url(:/resource/images/bb_classify/roll_up.png);"));

        gridLayout_2->addWidget(widgetUp, 1, 0, 1, 1);


        gridLayout->addWidget(widgetLeft, 0, 0, 1, 1);

        widgetShowIntroduce = new IntroduceFromRight(IntroduceForm);
        widgetShowIntroduce->setObjectName(QStringLiteral("widgetShowIntroduce"));
        widgetShowIntroduce->setMinimumSize(QSize(845, 675));
        widgetShowIntroduce->setStyleSheet(QLatin1String("QWidget#widgetShowIntroduce\n"
"{\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
""));
        gridLayout_4 = new QGridLayout(widgetShowIntroduce);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        widgetMid = new QWidget(widgetShowIntroduce);
        widgetMid->setObjectName(QStringLiteral("widgetMid"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widgetMid->sizePolicy().hasHeightForWidth());
        widgetMid->setSizePolicy(sizePolicy);
        widgetMid->setMinimumSize(QSize(235, 675));
        widgetMid->setMaximumSize(QSize(235, 16777215));
        widgetMid->setStyleSheet(QStringLiteral("border-image: url(:/resource/images/bb_classify/blackwithblueline.png);"));

        gridLayout_4->addWidget(widgetMid, 0, 0, 1, 1);

        widgetRight = new QWidget(widgetShowIntroduce);
        widgetRight->setObjectName(QStringLiteral("widgetRight"));
        gridLayout_5 = new QGridLayout(widgetRight);
        gridLayout_5->setSpacing(0);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        widgetTitle = new QWidget(widgetRight);
        widgetTitle->setObjectName(QStringLiteral("widgetTitle"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widgetTitle->sizePolicy().hasHeightForWidth());
        widgetTitle->setSizePolicy(sizePolicy1);
        widgetTitle->setMinimumSize(QSize(531, 51));
        horizontalLayout = new QHBoxLayout(widgetTitle);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, -1, -1);
        horizontalSpacer = new QSpacerItem(466, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButtonClose = new QPushButton(widgetTitle);
        pushButtonClose->setObjectName(QStringLiteral("pushButtonClose"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButtonClose->sizePolicy().hasHeightForWidth());
        pushButtonClose->setSizePolicy(sizePolicy2);
        pushButtonClose->setMinimumSize(QSize(50, 43));
        pushButtonClose->setMaximumSize(QSize(50, 43));
        pushButtonClose->setStyleSheet(QStringLiteral("border-image: url(:/resource/images/common/Back_black.png);"));

        horizontalLayout->addWidget(pushButtonClose);


        gridLayout_5->addWidget(widgetTitle, 0, 0, 1, 1);

        widget = new QWidget(widgetRight);
        widget->setObjectName(QStringLiteral("widget"));
        labelText = new QLabel(widget);
        labelText->setObjectName(QStringLiteral("labelText"));
        labelText->setGeometry(QRect(20, 240, 471, 301));
        labelText->setStyleSheet(QStringLiteral(""));
        labelText->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        labelText->setWordWrap(true);
        labelImage = new QLabel(widget);
        labelImage->setObjectName(QStringLiteral("labelImage"));
        labelImage->setGeometry(QRect(20, 20, 261, 171));
        labelImage->setStyleSheet(QStringLiteral(""));

        gridLayout_5->addWidget(widget, 1, 0, 1, 1);


        gridLayout_4->addWidget(widgetRight, 0, 1, 1, 1);


        gridLayout->addWidget(widgetShowIntroduce, 0, 1, 1, 1);


        retranslateUi(IntroduceForm);

        QMetaObject::connectSlotsByName(IntroduceForm);
    } // setupUi

    void retranslateUi(QWidget *IntroduceForm)
    {
        IntroduceForm->setWindowTitle(QApplication::translate("IntroduceForm", "Form", 0));
        pushButtonClose->setText(QString());
        labelText->setText(QString());
        labelImage->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class IntroduceForm: public Ui_IntroduceForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTRODUCEFORM_H
