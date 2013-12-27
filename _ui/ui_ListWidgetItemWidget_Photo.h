/********************************************************************************
** Form generated from reading UI file 'ListWidgetItemWidget_Photo.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTWIDGETITEMWIDGET_PHOTO_H
#define UI_LISTWIDGETITEMWIDGET_PHOTO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ListWidgetItemWidget_Photo
{
public:
    QLabel *labelImage;
    QLabel *labelName;

    void setupUi(QWidget *ListWidgetItemWidget_Photo)
    {
        if (ListWidgetItemWidget_Photo->objectName().isEmpty())
            ListWidgetItemWidget_Photo->setObjectName(QStringLiteral("ListWidgetItemWidget_Photo"));
        ListWidgetItemWidget_Photo->resize(251, 111);
        labelImage = new QLabel(ListWidgetItemWidget_Photo);
        labelImage->setObjectName(QStringLiteral("labelImage"));
        labelImage->setGeometry(QRect(0, 0, 251, 111));
        labelName = new QLabel(ListWidgetItemWidget_Photo);
        labelName->setObjectName(QStringLiteral("labelName"));
        labelName->setGeometry(QRect(0, 70, 251, 41));
        labelName->setStyleSheet(QLatin1String("background-color: rgb(46, 46, 46);\n"
"color: rgb(255, 255, 255);\n"
"font: 18pt \"Microsoft JhengHei\";"));
        labelName->setAlignment(Qt::AlignCenter);

        retranslateUi(ListWidgetItemWidget_Photo);

        QMetaObject::connectSlotsByName(ListWidgetItemWidget_Photo);
    } // setupUi

    void retranslateUi(QWidget *ListWidgetItemWidget_Photo)
    {
        ListWidgetItemWidget_Photo->setWindowTitle(QApplication::translate("ListWidgetItemWidget_Photo", "Form", 0));
        labelImage->setText(QString());
        labelName->setText(QApplication::translate("ListWidgetItemWidget_Photo", "Cocer", 0));
    } // retranslateUi

};

namespace Ui {
    class ListWidgetItemWidget_Photo: public Ui_ListWidgetItemWidget_Photo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTWIDGETITEMWIDGET_PHOTO_H
