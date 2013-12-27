/********************************************************************************
** Form generated from reading UI file 'UploadWaitForm.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPLOADWAITFORM_H
#define UI_UPLOADWAITFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include "Label.h"
#include "PushButtonDone.h"

QT_BEGIN_NAMESPACE

class Ui_UploadWaitForm
{
public:
    QGridLayout *gridLayout_2;
    QWidget *widget;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QWidget *widget_2;
    QGridLayout *gridLayout_3;
    QWidget *widgetWaitBg;
    QGridLayout *gridLayout_4;
    QWidget *widgetWait;
    QWidget *widget_4;
    Label *labelString;
    Label *labelState;
    Label *labelImage;
    PushButtonDone *pushButtonCancel;
    QLabel *labelCancel;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *UploadWaitForm)
    {
        if (UploadWaitForm->objectName().isEmpty())
            UploadWaitForm->setObjectName(QStringLiteral("UploadWaitForm"));
        UploadWaitForm->resize(1025, 675);
        UploadWaitForm->setStyleSheet(QStringLiteral("background-color: rgba(179, 225, 255, 0);"));
        gridLayout_2 = new QGridLayout(UploadWaitForm);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(UploadWaitForm);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setStyleSheet(QLatin1String("QWidget#widget\n"
"{\n"
"	border-image: url(:/resource/images/common/Transparent_Black_80.png);\n"
"}"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 260, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 0, 1, 1);

        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy);
        widget_2->setMinimumSize(QSize(1025, 150));
        widget_2->setMaximumSize(QSize(16777215, 150));
        gridLayout_3 = new QGridLayout(widget_2);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        widgetWaitBg = new QWidget(widget_2);
        widgetWaitBg->setObjectName(QStringLiteral("widgetWaitBg"));
        sizePolicy.setHeightForWidth(widgetWaitBg->sizePolicy().hasHeightForWidth());
        widgetWaitBg->setSizePolicy(sizePolicy);
        widgetWaitBg->setMinimumSize(QSize(1025, 150));
        widgetWaitBg->setMaximumSize(QSize(16777215, 150));
        widgetWaitBg->setStyleSheet(QLatin1String("QWidget#widgetWaitBg\n"
"{\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}"));
        gridLayout_4 = new QGridLayout(widgetWaitBg);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        widgetWait = new QWidget(widgetWaitBg);
        widgetWait->setObjectName(QStringLiteral("widgetWait"));
        sizePolicy.setHeightForWidth(widgetWait->sizePolicy().hasHeightForWidth());
        widgetWait->setSizePolicy(sizePolicy);
        widgetWait->setMinimumSize(QSize(1025, 141));
        widgetWait->setMaximumSize(QSize(16777215, 141));
        widgetWait->setStyleSheet(QLatin1String("QWidget#widgetWait\n"
"{\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        widget_4 = new QWidget(widgetWait);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setGeometry(QRect(20, 20, 701, 91));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_4->sizePolicy().hasHeightForWidth());
        widget_4->setSizePolicy(sizePolicy1);
        widget_4->setMinimumSize(QSize(541, 91));
        labelString = new Label(widget_4);
        labelString->setObjectName(QStringLiteral("labelString"));
        labelString->setGeometry(QRect(190, 0, 161, 31));
        QFont font;
        font.setFamily(QStringLiteral("Nexa Light"));
        font.setPointSize(17);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        font.setKerning(true);
        font.setStyleStrategy(QFont::PreferDefault);
        labelString->setFont(font);
        labelString->setStyleSheet(QStringLiteral("color: rgb(82, 164, 225);"));
        labelState = new Label(widget_4);
        labelState->setObjectName(QStringLiteral("labelState"));
        labelState->setGeometry(QRect(190, 30, 501, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(11);
        labelState->setFont(font1);
        labelState->setStyleSheet(QStringLiteral(""));
        labelImage = new Label(widget_4);
        labelImage->setObjectName(QStringLiteral("labelImage"));
        labelImage->setGeometry(QRect(90, 0, 83, 84));
        pushButtonCancel = new PushButtonDone(widgetWait);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        pushButtonCancel->setGeometry(QRect(913, 60, 112, 82));
        QFont font2;
        font2.setFamily(QStringLiteral("Nexa Light"));
        font2.setPointSize(26);
        pushButtonCancel->setFont(font2);
        pushButtonCancel->setStyleSheet(QLatin1String("QPushButton\n"
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
        labelCancel = new QLabel(widgetWait);
        labelCancel->setObjectName(QStringLiteral("labelCancel"));
        labelCancel->setGeometry(QRect(920, 90, 101, 51));
        labelCancel->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"	font: 30px \"Helvetica\";\n"
"	color: rgb(0, 0, 0);\n"
"}\n"
"QLabel:hover\n"
"{\n"
"	font: 30px \"Helvetica\";\n"
"	color: rgb(82, 164, 225);\n"
"}\n"
"QLabel:pressed\n"
"{\n"
"	font: 30px \"Helvetica\";\n"
"	color: rgb(0, 0, 0);\n"
"}"));
        labelCancel->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(widgetWait, 0, 0, 1, 1);


        gridLayout_3->addWidget(widgetWaitBg, 0, 0, 1, 1);


        gridLayout->addWidget(widget_2, 1, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 259, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 0, 1, 1);


        gridLayout_2->addWidget(widget, 0, 0, 1, 1);


        retranslateUi(UploadWaitForm);

        QMetaObject::connectSlotsByName(UploadWaitForm);
    } // setupUi

    void retranslateUi(QWidget *UploadWaitForm)
    {
        UploadWaitForm->setWindowTitle(QApplication::translate("UploadWaitForm", "Form", 0));
        labelString->setText(QApplication::translate("UploadWaitForm", "Please Wait...", 0));
        labelState->setText(QApplication::translate("UploadWaitForm", "Compiling...", 0));
        labelImage->setText(QString());
        pushButtonCancel->setText(QString());
        labelCancel->setText(QApplication::translate("UploadWaitForm", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class UploadWaitForm: public Ui_UploadWaitForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPLOADWAITFORM_H
