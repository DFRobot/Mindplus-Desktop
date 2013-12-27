/********************************************************************************
** Form generated from reading UI file 'FunctionAreaWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FUNCTIONAREAWIDGET_H
#define UI_FUNCTIONAREAWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FunctionAreaWidget
{
public:
    QLabel *labelImage;
    QLabel *labelName;

    void setupUi(QWidget *FunctionAreaWidget)
    {
        if (FunctionAreaWidget->objectName().isEmpty())
            FunctionAreaWidget->setObjectName(QStringLiteral("FunctionAreaWidget"));
        FunctionAreaWidget->resize(44, 50);
        FunctionAreaWidget->setStyleSheet(QStringLiteral(""));
        labelImage = new QLabel(FunctionAreaWidget);
        labelImage->setObjectName(QStringLiteral("labelImage"));
        labelImage->setGeometry(QRect(9, 4, 26, 26));
        labelImage->setMinimumSize(QSize(0, 0));
        labelName = new QLabel(FunctionAreaWidget);
        labelName->setObjectName(QStringLiteral("labelName"));
        labelName->setGeometry(QRect(0, 35, 44, 15));
        labelName->setMinimumSize(QSize(0, 0));
        labelName->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font: 12px \"Helvetica\";"));
        labelName->setAlignment(Qt::AlignCenter);

        retranslateUi(FunctionAreaWidget);

        QMetaObject::connectSlotsByName(FunctionAreaWidget);
    } // setupUi

    void retranslateUi(QWidget *FunctionAreaWidget)
    {
        FunctionAreaWidget->setWindowTitle(QApplication::translate("FunctionAreaWidget", "Form", 0));
        labelImage->setText(QString());
        labelName->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FunctionAreaWidget: public Ui_FunctionAreaWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FUNCTIONAREAWIDGET_H
