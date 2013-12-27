/********************************************************************************
** Form generated from reading UI file 'LoginInforWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGININFORWIDGET_H
#define UI_LOGININFORWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginInforWidget
{
public:
    QLabel *labelImage;
    QLabel *labelName;

    void setupUi(QWidget *LoginInforWidget)
    {
        if (LoginInforWidget->objectName().isEmpty())
            LoginInforWidget->setObjectName(QStringLiteral("LoginInforWidget"));
        LoginInforWidget->resize(111, 27);
        LoginInforWidget->setMinimumSize(QSize(111, 27));
        LoginInforWidget->setMaximumSize(QSize(16777215, 27));
        LoginInforWidget->setStyleSheet(QStringLiteral("font: 9pt \"Microsoft YaHei UI\";"));
        labelImage = new QLabel(LoginInforWidget);
        labelImage->setObjectName(QStringLiteral("labelImage"));
        labelImage->setGeometry(QRect(85, 6, 16, 16));
        labelImage->setStyleSheet(QStringLiteral(""));
        labelName = new QLabel(LoginInforWidget);
        labelName->setObjectName(QStringLiteral("labelName"));
        labelName->setGeometry(QRect(0, 0, 78, 27));
        labelName->setMinimumSize(QSize(78, 26));
        labelName->setMaximumSize(QSize(16777215, 27));
        labelName->setStyleSheet(QStringLiteral(""));
        labelName->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        retranslateUi(LoginInforWidget);

        QMetaObject::connectSlotsByName(LoginInforWidget);
    } // setupUi

    void retranslateUi(QWidget *LoginInforWidget)
    {
        LoginInforWidget->setWindowTitle(QApplication::translate("LoginInforWidget", "Form", 0));
        labelImage->setText(QString());
        labelName->setText(QApplication::translate("LoginInforWidget", "Login", 0));
    } // retranslateUi

};

namespace Ui {
    class LoginInforWidget: public Ui_LoginInforWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGININFORWIDGET_H
