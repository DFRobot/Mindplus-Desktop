/********************************************************************************
** Form generated from reading UI file 'WidgetForListWidgetBegin.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETFORLISTWIDGETBEGIN_H
#define UI_WIDGETFORLISTWIDGETBEGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetForListWidgetBegin
{
public:
    QGridLayout *gridLayout;
    QLabel *labelImage;
    QLabel *labelText;
    QLabel *labelType;

    void setupUi(QWidget *WidgetForListWidgetBegin)
    {
        if (WidgetForListWidgetBegin->objectName().isEmpty())
            WidgetForListWidgetBegin->setObjectName(QStringLiteral("WidgetForListWidgetBegin"));
        WidgetForListWidgetBegin->resize(180, 43);
        WidgetForListWidgetBegin->setStyleSheet(QLatin1String("QWidget#WidgetForListWidgetBegin\n"
"{\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
"QWidget#WidgetForListWidgetBegin:hover\n"
"{\n"
"	background-color: rgb(214, 255, 117);\n"
"}\n"
"QWidget#WidgetForListWidgetBegin:pressed\n"
"{\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        gridLayout = new QGridLayout(WidgetForListWidgetBegin);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(5);
        gridLayout->setVerticalSpacing(0);
        gridLayout->setContentsMargins(5, 0, 0, 0);
        labelImage = new QLabel(WidgetForListWidgetBegin);
        labelImage->setObjectName(QStringLiteral("labelImage"));
        labelImage->setMinimumSize(QSize(44, 39));
        labelImage->setMaximumSize(QSize(44, 39));
        labelImage->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(labelImage, 0, 0, 2, 1);

        labelText = new QLabel(WidgetForListWidgetBegin);
        labelText->setObjectName(QStringLiteral("labelText"));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(11);
        labelText->setFont(font);
        labelText->setStyleSheet(QStringLiteral("font: 90 14px \"Arial\";"));

        gridLayout->addWidget(labelText, 0, 1, 1, 1);

        labelType = new QLabel(WidgetForListWidgetBegin);
        labelType->setObjectName(QStringLiteral("labelType"));
        labelType->setStyleSheet(QLatin1String("color: rgb(127, 127, 127);\n"
"font: 12px \"arial\";"));

        gridLayout->addWidget(labelType, 1, 1, 1, 1);


        retranslateUi(WidgetForListWidgetBegin);

        QMetaObject::connectSlotsByName(WidgetForListWidgetBegin);
    } // setupUi

    void retranslateUi(QWidget *WidgetForListWidgetBegin)
    {
        WidgetForListWidgetBegin->setWindowTitle(QApplication::translate("WidgetForListWidgetBegin", "Form", 0));
        labelImage->setText(QString());
        labelText->setText(QString());
        labelType->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WidgetForListWidgetBegin: public Ui_WidgetForListWidgetBegin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETFORLISTWIDGETBEGIN_H
