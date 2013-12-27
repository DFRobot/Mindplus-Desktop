/********************************************************************************
** Form generated from reading UI file 'FunctionArea.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FUNCTIONAREA_H
#define UI_FUNCTIONAREA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include "FunctionAreaWidget.h"

QT_BEGIN_NAMESPACE

class Ui_FunctionArea
{
public:
    FunctionAreaWidget *widgetNewProject;
    FunctionAreaWidget *widgetOpen;
    FunctionAreaWidget *widgetUpload;
    FunctionAreaWidget *widgetSave;
    QLabel *labelSplitLine;

    void setupUi(QWidget *FunctionArea)
    {
        if (FunctionArea->objectName().isEmpty())
            FunctionArea->setObjectName(QStringLiteral("FunctionArea"));
        FunctionArea->resize(204, 50);
        FunctionArea->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);"));
        widgetNewProject = new FunctionAreaWidget(FunctionArea);
        widgetNewProject->setObjectName(QStringLiteral("widgetNewProject"));
        widgetNewProject->setGeometry(QRect(0, 0, 44, 50));
        widgetNewProject->setStyleSheet(QStringLiteral(""));
        widgetOpen = new FunctionAreaWidget(FunctionArea);
        widgetOpen->setObjectName(QStringLiteral("widgetOpen"));
        widgetOpen->setGeometry(QRect(50, 0, 44, 50));
        widgetOpen->setStyleSheet(QStringLiteral(""));
        widgetUpload = new FunctionAreaWidget(FunctionArea);
        widgetUpload->setObjectName(QStringLiteral("widgetUpload"));
        widgetUpload->setGeometry(QRect(160, 0, 44, 50));
        widgetSave = new FunctionAreaWidget(FunctionArea);
        widgetSave->setObjectName(QStringLiteral("widgetSave"));
        widgetSave->setGeometry(QRect(100, 0, 44, 50));
        labelSplitLine = new QLabel(FunctionArea);
        labelSplitLine->setObjectName(QStringLiteral("labelSplitLine"));
        labelSplitLine->setGeometry(QRect(150, 13, 4, 24));
        labelSplitLine->setStyleSheet(QStringLiteral("border-image: url(:/resource/images/tool_area/TopToolBar_SplitLine.png);"));

        retranslateUi(FunctionArea);

        QMetaObject::connectSlotsByName(FunctionArea);
    } // setupUi

    void retranslateUi(QWidget *FunctionArea)
    {
        FunctionArea->setWindowTitle(QApplication::translate("FunctionArea", "Form", 0));
        labelSplitLine->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FunctionArea: public Ui_FunctionArea {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FUNCTIONAREA_H
