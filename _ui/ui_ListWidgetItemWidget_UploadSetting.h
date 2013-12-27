/********************************************************************************
** Form generated from reading UI file 'ListWidgetItemWidget_UploadSetting.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTWIDGETITEMWIDGET_UPLOADSETTING_H
#define UI_LISTWIDGETITEMWIDGET_UPLOADSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ListWidgetItemWidget_UploadSetting
{
public:
    QGridLayout *gridLayout;
    QLabel *labelName;

    void setupUi(QWidget *ListWidgetItemWidget_UploadSetting)
    {
        if (ListWidgetItemWidget_UploadSetting->objectName().isEmpty())
            ListWidgetItemWidget_UploadSetting->setObjectName(QStringLiteral("ListWidgetItemWidget_UploadSetting"));
        ListWidgetItemWidget_UploadSetting->resize(191, 31);
        gridLayout = new QGridLayout(ListWidgetItemWidget_UploadSetting);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        labelName = new QLabel(ListWidgetItemWidget_UploadSetting);
        labelName->setObjectName(QStringLiteral("labelName"));
        labelName->setStyleSheet(QStringLiteral(""));
        labelName->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(labelName, 0, 0, 1, 1);


        retranslateUi(ListWidgetItemWidget_UploadSetting);

        QMetaObject::connectSlotsByName(ListWidgetItemWidget_UploadSetting);
    } // setupUi

    void retranslateUi(QWidget *ListWidgetItemWidget_UploadSetting)
    {
        ListWidgetItemWidget_UploadSetting->setWindowTitle(QApplication::translate("ListWidgetItemWidget_UploadSetting", "Form", 0));
        labelName->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ListWidgetItemWidget_UploadSetting: public Ui_ListWidgetItemWidget_UploadSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTWIDGETITEMWIDGET_UPLOADSETTING_H
