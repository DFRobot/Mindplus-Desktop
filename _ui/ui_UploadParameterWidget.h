/********************************************************************************
** Form generated from reading UI file 'UploadParameterWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPLOADPARAMETERWIDGET_H
#define UI_UPLOADPARAMETERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UploadParameterWidget
{
public:
    QLabel *labelBoard;
    QLabel *labelSerial;

    void setupUi(QWidget *UploadParameterWidget)
    {
        if (UploadParameterWidget->objectName().isEmpty())
            UploadParameterWidget->setObjectName(QStringLiteral("UploadParameterWidget"));
        UploadParameterWidget->resize(301, 27);
        UploadParameterWidget->setMinimumSize(QSize(211, 27));
        UploadParameterWidget->setMaximumSize(QSize(1000, 27));
        UploadParameterWidget->setStyleSheet(QStringLiteral("border-image: url(:/resource/images/title/titlebg.png);"));
        labelBoard = new QLabel(UploadParameterWidget);
        labelBoard->setObjectName(QStringLiteral("labelBoard"));
        labelBoard->setGeometry(QRect(0, 1, 191, 27));
        labelSerial = new QLabel(UploadParameterWidget);
        labelSerial->setObjectName(QStringLiteral("labelSerial"));
        labelSerial->setGeometry(QRect(200, 0, 101, 27));

        retranslateUi(UploadParameterWidget);

        QMetaObject::connectSlotsByName(UploadParameterWidget);
    } // setupUi

    void retranslateUi(QWidget *UploadParameterWidget)
    {
        UploadParameterWidget->setWindowTitle(QApplication::translate("UploadParameterWidget", "Form", 0));
        labelBoard->setText(QString());
        labelSerial->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class UploadParameterWidget: public Ui_UploadParameterWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPLOADPARAMETERWIDGET_H
