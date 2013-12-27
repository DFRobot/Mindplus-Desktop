/********************************************************************************
** Form generated from reading UI file 'SerialSettingWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIALSETTINGWIDGET_H
#define UI_SERIALSETTINGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SerialSettingWidget
{
public:
    QLabel *labelBoard;
    QLabel *labelSerial;
    QLabel *labelImage;

    void setupUi(QWidget *SerialSettingWidget)
    {
        if (SerialSettingWidget->objectName().isEmpty())
            SerialSettingWidget->setObjectName(QStringLiteral("SerialSettingWidget"));
        SerialSettingWidget->resize(161, 50);
        SerialSettingWidget->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"	font: 12px \"Helvetica\";\n"
"	color: rgb(255, 255, 255);\n"
"}"));
        labelBoard = new QLabel(SerialSettingWidget);
        labelBoard->setObjectName(QStringLiteral("labelBoard"));
        labelBoard->setGeometry(QRect(48, 10, 113, 13));
        labelBoard->setStyleSheet(QStringLiteral(""));
        labelSerial = new QLabel(SerialSettingWidget);
        labelSerial->setObjectName(QStringLiteral("labelSerial"));
        labelSerial->setGeometry(QRect(48, 30, 113, 13));
        labelSerial->setStyleSheet(QStringLiteral(""));
        labelImage = new QLabel(SerialSettingWidget);
        labelImage->setObjectName(QStringLiteral("labelImage"));
        labelImage->setGeometry(QRect(10, 12, 26, 26));

        retranslateUi(SerialSettingWidget);

        QMetaObject::connectSlotsByName(SerialSettingWidget);
    } // setupUi

    void retranslateUi(QWidget *SerialSettingWidget)
    {
        SerialSettingWidget->setWindowTitle(QApplication::translate("SerialSettingWidget", "Form", 0));
        labelBoard->setText(QString());
        labelSerial->setText(QString());
        labelImage->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SerialSettingWidget: public Ui_SerialSettingWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIALSETTINGWIDGET_H
