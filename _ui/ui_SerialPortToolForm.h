/********************************************************************************
** Form generated from reading UI file 'SerialPortToolForm.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIALPORTTOOLFORM_H
#define UI_SERIALPORTTOOLFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SerialPortToolForm
{
public:
    QGridLayout *gridLayout_3;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QTextEdit *textEditRead;
    QWidget *widget_2;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *comboBoxPort;
    QComboBox *comboBoxBaud;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *checkBoxMind;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_3;
    QGridLayout *gridLayout;
    QTextEdit *textEditSend;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonSend;

    void setupUi(QWidget *SerialPortToolForm)
    {
        if (SerialPortToolForm->objectName().isEmpty())
            SerialPortToolForm->setObjectName(QStringLiteral("SerialPortToolForm"));
        SerialPortToolForm->resize(405, 591);
        gridLayout_3 = new QGridLayout(SerialPortToolForm);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        widget = new QWidget(SerialPortToolForm);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setStyleSheet(QStringLiteral("background-color: rgb(248, 148, 102);"));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(2, 2, 2, 2);
        textEditRead = new QTextEdit(widget);
        textEditRead->setObjectName(QStringLiteral("textEditRead"));
        textEditRead->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        textEditRead->setFrameShape(QFrame::NoFrame);
        textEditRead->setFrameShadow(QFrame::Plain);
        textEditRead->setLineWidth(0);

        gridLayout_2->addWidget(textEditRead, 0, 0, 1, 1);


        gridLayout_3->addWidget(widget, 0, 0, 1, 1);

        widget_2 = new QWidget(SerialPortToolForm);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(381, 61));
        widget_2->setMaximumSize(QSize(16777215, 61));
        gridLayout_4 = new QGridLayout(widget_2);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        comboBoxPort = new QComboBox(widget_2);
        comboBoxPort->setObjectName(QStringLiteral("comboBoxPort"));

        horizontalLayout_2->addWidget(comboBoxPort);

        comboBoxBaud = new QComboBox(widget_2);
        comboBoxBaud->setObjectName(QStringLiteral("comboBoxBaud"));

        horizontalLayout_2->addWidget(comboBoxBaud);

        horizontalSpacer_3 = new QSpacerItem(40, 13, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        checkBoxMind = new QCheckBox(widget_2);
        checkBoxMind->setObjectName(QStringLiteral("checkBoxMind"));

        horizontalLayout_2->addWidget(checkBoxMind);


        gridLayout_4->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setStyleSheet(QStringLiteral("background-color: rgb(248, 148, 102);"));
        gridLayout = new QGridLayout(widget_3);
        gridLayout->setSpacing(2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(2, 2, 2, 2);
        textEditSend = new QTextEdit(widget_3);
        textEditSend->setObjectName(QStringLiteral("textEditSend"));
        textEditSend->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        textEditSend->setFrameShape(QFrame::NoFrame);
        textEditSend->setFrameShadow(QFrame::Plain);
        textEditSend->setLineWidth(0);
        textEditSend->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEditSend->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout->addWidget(textEditSend, 0, 0, 1, 1);


        horizontalLayout->addWidget(widget_3);

        horizontalSpacer = new QSpacerItem(48, 18, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButtonSend = new QPushButton(widget_2);
        pushButtonSend->setObjectName(QStringLiteral("pushButtonSend"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButtonSend->sizePolicy().hasHeightForWidth());
        pushButtonSend->setSizePolicy(sizePolicy);
        pushButtonSend->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(pushButtonSend);


        gridLayout_4->addLayout(horizontalLayout, 1, 0, 1, 1);


        gridLayout_3->addWidget(widget_2, 1, 0, 1, 1);


        retranslateUi(SerialPortToolForm);

        QMetaObject::connectSlotsByName(SerialPortToolForm);
    } // setupUi

    void retranslateUi(QWidget *SerialPortToolForm)
    {
        SerialPortToolForm->setWindowTitle(QApplication::translate("SerialPortToolForm", "Form", 0));
        comboBoxBaud->clear();
        comboBoxBaud->insertItems(0, QStringList()
         << QApplication::translate("SerialPortToolForm", "1200", 0)
         << QApplication::translate("SerialPortToolForm", "2400", 0)
         << QApplication::translate("SerialPortToolForm", "4800", 0)
         << QApplication::translate("SerialPortToolForm", "9600", 0)
         << QApplication::translate("SerialPortToolForm", "19200", 0)
         << QApplication::translate("SerialPortToolForm", "38400", 0)
         << QApplication::translate("SerialPortToolForm", "57600", 0)
         << QApplication::translate("SerialPortToolForm", "115200", 0)
         << QApplication::translate("SerialPortToolForm", "128000", 0)
         << QApplication::translate("SerialPortToolForm", "250000", 0)
         << QApplication::translate("SerialPortToolForm", "256000", 0)
        );
        checkBoxMind->setText(QApplication::translate("SerialPortToolForm", "Mind+ wrap", 0));
        pushButtonSend->setText(QApplication::translate("SerialPortToolForm", "Send", 0));
    } // retranslateUi

};

namespace Ui {
    class SerialPortToolForm: public Ui_SerialPortToolForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIALPORTTOOLFORM_H
