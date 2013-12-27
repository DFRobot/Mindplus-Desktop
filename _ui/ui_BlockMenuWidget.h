/********************************************************************************
** Form generated from reading UI file 'BlockMenuWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BLOCKMENUWIDGET_H
#define UI_BLOCKMENUWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BlockMenuWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *labelImage;

    void setupUi(QWidget *BlockMenuWidget)
    {
        if (BlockMenuWidget->objectName().isEmpty())
            BlockMenuWidget->setObjectName(QStringLiteral("BlockMenuWidget"));
        BlockMenuWidget->resize(81, 81);
        gridLayout = new QGridLayout(BlockMenuWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        labelImage = new QLabel(BlockMenuWidget);
        labelImage->setObjectName(QStringLiteral("labelImage"));

        gridLayout->addWidget(labelImage, 0, 0, 1, 1);


        retranslateUi(BlockMenuWidget);

        QMetaObject::connectSlotsByName(BlockMenuWidget);
    } // setupUi

    void retranslateUi(QWidget *BlockMenuWidget)
    {
        BlockMenuWidget->setWindowTitle(QApplication::translate("BlockMenuWidget", "Form", 0));
        labelImage->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class BlockMenuWidget: public Ui_BlockMenuWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLOCKMENUWIDGET_H
