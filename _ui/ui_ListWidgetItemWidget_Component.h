/********************************************************************************
** Form generated from reading UI file 'ListWidgetItemWidget_Component.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTWIDGETITEMWIDGET_COMPONENT_H
#define UI_LISTWIDGETITEMWIDGET_COMPONENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ListWidgetItemWidget_Component
{
public:
    QGridLayout *gridLayout;
    QLabel *labelName;

    void setupUi(QWidget *ListWidgetItemWidget_Component)
    {
        if (ListWidgetItemWidget_Component->objectName().isEmpty())
            ListWidgetItemWidget_Component->setObjectName(QStringLiteral("ListWidgetItemWidget_Component"));
        ListWidgetItemWidget_Component->resize(151, 21);
        ListWidgetItemWidget_Component->setMinimumSize(QSize(0, 21));
        ListWidgetItemWidget_Component->setMaximumSize(QSize(16777215, 21));
        ListWidgetItemWidget_Component->setStyleSheet(QStringLiteral(""));
        gridLayout = new QGridLayout(ListWidgetItemWidget_Component);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        labelName = new QLabel(ListWidgetItemWidget_Component);
        labelName->setObjectName(QStringLiteral("labelName"));
        labelName->setMinimumSize(QSize(0, 21));
        labelName->setMaximumSize(QSize(300, 21));
        labelName->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"	color: rgb(174, 174, 174);\n"
"}"));
        labelName->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelName, 0, 0, 1, 1);


        retranslateUi(ListWidgetItemWidget_Component);

        QMetaObject::connectSlotsByName(ListWidgetItemWidget_Component);
    } // setupUi

    void retranslateUi(QWidget *ListWidgetItemWidget_Component)
    {
        ListWidgetItemWidget_Component->setWindowTitle(QApplication::translate("ListWidgetItemWidget_Component", "Form", 0));
        labelName->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ListWidgetItemWidget_Component: public Ui_ListWidgetItemWidget_Component {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTWIDGETITEMWIDGET_COMPONENT_H
