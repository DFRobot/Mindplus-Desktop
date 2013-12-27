/********************************************************************************
** Form generated from reading UI file 'UploadSettingForm.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPLOADSETTINGFORM_H
#define UI_UPLOADSETTINGFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UploadSettingForm
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QWidget *widgetBg;
    QWidget *widgetLeft;
    QLabel *label_3;
    QPushButton *pushButtonBack;
    QLabel *label;
    QLabel *label_2;
    QLabel *labelSplit;
    QLabel *labelSplit_2;
    QPushButton *pushButtonUpload;
    QLabel *label_4;
    QComboBox *comboBoxBoard;
    QComboBox *comboBoxSerialPort;
    QLabel *label_5;
    QPushButton *pushButtonUno;
    QPushButton *pushButtonLeonardo;
    QLabel *labelTipToard;
    QLabel *labelTipSerialPort;

    void setupUi(QWidget *UploadSettingForm)
    {
        if (UploadSettingForm->objectName().isEmpty())
            UploadSettingForm->setObjectName(QStringLiteral("UploadSettingForm"));
        UploadSettingForm->resize(1025, 675);
        UploadSettingForm->setStyleSheet(QLatin1String("QWidget#UploadSettingForm\n"
"{\n"
"	border-image: url(:/resource/images/common/Transparent_Black_80.png);\n"
"}"));
        gridLayout = new QGridLayout(UploadSettingForm);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalSpacer = new QSpacerItem(20, 145, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 144, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 0, 1, 1);

        widgetBg = new QWidget(UploadSettingForm);
        widgetBg->setObjectName(QStringLiteral("widgetBg"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widgetBg->sizePolicy().hasHeightForWidth());
        widgetBg->setSizePolicy(sizePolicy);
        widgetBg->setMinimumSize(QSize(1025, 431));
        widgetBg->setStyleSheet(QLatin1String("QWidget#widgetBg\n"
"{\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
"QListView::item::hover\n"
"{\n"
"\n"
"}\n"
""));
        widgetLeft = new QWidget(widgetBg);
        widgetLeft->setObjectName(QStringLiteral("widgetLeft"));
        widgetLeft->setGeometry(QRect(0, 0, 280, 431));
        widgetLeft->setStyleSheet(QLatin1String("QWidget#widgetLeft\n"
"{\n"
"	background-color: rgb(149, 212, 244);\n"
"}"));
        label_3 = new QLabel(widgetLeft);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 180, 241, 51));
        label_3->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font: 35px \"arial\";"));
        pushButtonBack = new QPushButton(widgetLeft);
        pushButtonBack->setObjectName(QStringLiteral("pushButtonBack"));
        pushButtonBack->setGeometry(QRect(20, 20, 50, 50));
        pushButtonBack->setStyleSheet(QStringLiteral("border-image: url(:/resource/images/upload_setting/Back.png);"));
        label = new QLabel(widgetBg);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(340, 80, 81, 61));
        label->setStyleSheet(QLatin1String("color: rgb(149, 212, 244);\n"
"font: 70px \"Helvetica\";"));
        label->setTextFormat(Qt::PlainText);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(widgetBg);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(340, 240, 81, 61));
        label_2->setStyleSheet(QLatin1String("color: rgb(149, 212, 244);\n"
"font: 70px \"Helvetica\";"));
        labelSplit = new QLabel(widgetBg);
        labelSplit->setObjectName(QStringLiteral("labelSplit"));
        labelSplit->setGeometry(QRect(346, 40, 575, 1));
        labelSplit->setStyleSheet(QStringLiteral("background-color: rgb(210, 210, 210);"));
        labelSplit_2 = new QLabel(widgetBg);
        labelSplit_2->setObjectName(QStringLiteral("labelSplit_2"));
        labelSplit_2->setGeometry(QRect(346, 200, 575, 1));
        labelSplit_2->setStyleSheet(QStringLiteral("background-color: rgb(210, 210, 210);"));
        pushButtonUpload = new QPushButton(widgetBg);
        pushButtonUpload->setObjectName(QStringLiteral("pushButtonUpload"));
        pushButtonUpload->setGeometry(QRect(510, 330, 261, 91));
        pushButtonUpload->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	color: rgb(0, 0, 0);\n"
"	font: 70px \"arial\";\n"
"	border:none\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	color: rgb(149, 212, 244);\n"
"	font: 70px \"arial\";\n"
"	border:none\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	color: rgb(149, 212, 0);\n"
"	font: 70px \"arial\";\n"
"	border:none\n"
"}"));
        label_4 = new QLabel(widgetBg);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(440, 80, 251, 21));
        label_4->setStyleSheet(QLatin1String("color: rgb(150, 150, 150);\n"
"font: 20px \"arial\";"));
        comboBoxBoard = new QComboBox(widgetBg);
        comboBoxBoard->setObjectName(QStringLiteral("comboBoxBoard"));
        comboBoxBoard->setGeometry(QRect(440, 100, 255, 35));
        comboBoxBoard->setMaximumSize(QSize(300, 35));
        comboBoxBoard->setStyleSheet(QStringLiteral(""));
        comboBoxSerialPort = new QComboBox(widgetBg);
        comboBoxSerialPort->setObjectName(QStringLiteral("comboBoxSerialPort"));
        comboBoxSerialPort->setGeometry(QRect(440, 260, 255, 33));
        label_5 = new QLabel(widgetBg);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(440, 240, 241, 21));
        label_5->setStyleSheet(QLatin1String("color: rgb(150, 150, 150);\n"
"font: 20px \"arial\";"));
        pushButtonUno = new QPushButton(widgetBg);
        pushButtonUno->setObjectName(QStringLiteral("pushButtonUno"));
        pushButtonUno->setGeometry(QRect(740, 130, 59, 40));
        pushButtonUno->setStyleSheet(QStringLiteral("border-image: url(:/resource/images/upload_setting/MiniUno.png);"));
        pushButtonLeonardo = new QPushButton(widgetBg);
        pushButtonLeonardo->setObjectName(QStringLiteral("pushButtonLeonardo"));
        pushButtonLeonardo->setGeometry(QRect(820, 130, 59, 40));
        pushButtonLeonardo->setStyleSheet(QStringLiteral("border-image: url(:/resource/images/upload_setting/MiniLeonardo.png);"));
        labelTipToard = new QLabel(widgetBg);
        labelTipToard->setObjectName(QStringLiteral("labelTipToard"));
        labelTipToard->setGeometry(QRect(890, 70, 16, 16));
        labelTipToard->setStyleSheet(QLatin1String("QLabel#labelTipToard\n"
"{\n"
"	border-image: url(:/resource/images/upload_setting/tips.png);\n"
"}"));
        labelTipSerialPort = new QLabel(widgetBg);
        labelTipSerialPort->setObjectName(QStringLiteral("labelTipSerialPort"));
        labelTipSerialPort->setGeometry(QRect(890, 240, 16, 16));
        labelTipSerialPort->setStyleSheet(QLatin1String("QLabel#labelTipSerialPort\n"
"{\n"
"	border-image: url(:/resource/images/upload_setting/tips.png);\n"
"}"));

        gridLayout->addWidget(widgetBg, 1, 0, 1, 1);


        retranslateUi(UploadSettingForm);

        QMetaObject::connectSlotsByName(UploadSettingForm);
    } // setupUi

    void retranslateUi(QWidget *UploadSettingForm)
    {
        UploadSettingForm->setWindowTitle(QApplication::translate("UploadSettingForm", "Form", 0));
        label_3->setText(QApplication::translate("UploadSettingForm", "Upload Setting", 0));
        pushButtonBack->setText(QString());
        label->setText(QApplication::translate("UploadSettingForm", "01", 0));
        label_2->setText(QApplication::translate("UploadSettingForm", "02", 0));
        labelSplit->setText(QString());
        labelSplit_2->setText(QString());
        pushButtonUpload->setText(QApplication::translate("UploadSettingForm", "Upload", 0));
        label_4->setText(QApplication::translate("UploadSettingForm", "Select Arduino Board", 0));
        comboBoxBoard->clear();
        comboBoxBoard->insertItems(0, QStringList()
         << QApplication::translate("UploadSettingForm", "-------------Common----------------", 0)
         << QApplication::translate("UploadSettingForm", "Arduino Uno", 0)
         << QApplication::translate("UploadSettingForm", "Arduino Leonardo", 0)
         << QApplication::translate("UploadSettingForm", "-------------Arduino----------------", 0)
         << QApplication::translate("UploadSettingForm", "Arduino Duemilanove ATmega328", 0)
         << QApplication::translate("UploadSettingForm", "Arduino Duemilanove ATmega168", 0)
         << QApplication::translate("UploadSettingForm", "Arduino Nano ATmega328", 0)
         << QApplication::translate("UploadSettingForm", "Arduino Nano ATmega168", 0)
         << QApplication::translate("UploadSettingForm", "Arduino Mega 2560 or Mega ADK", 0)
         << QApplication::translate("UploadSettingForm", "Arduino Mega (ATmega1280)", 0)
         << QApplication::translate("UploadSettingForm", "Arduino Esplora", 0)
         << QApplication::translate("UploadSettingForm", "Arduino Micro", 0)
         << QApplication::translate("UploadSettingForm", "Arduino Mini ATmega328", 0)
         << QApplication::translate("UploadSettingForm", "Arduino Mini ATmega168", 0)
         << QApplication::translate("UploadSettingForm", "Arduino Ethernet", 0)
         << QApplication::translate("UploadSettingForm", "Arduino Fio", 0)
         << QApplication::translate("UploadSettingForm", "Arduino BT ATmega328", 0)
         << QApplication::translate("UploadSettingForm", "Arduino BT ATmega168", 0)
         << QApplication::translate("UploadSettingForm", "LilyPad Arduino USB", 0)
         << QApplication::translate("UploadSettingForm", "LilyPad Arduino ATmega328", 0)
         << QApplication::translate("UploadSettingForm", "LilyPad Arduino ATmega168", 0)
         << QApplication::translate("UploadSettingForm", "Arduino Pro Mini (5V,16 MHz)  ATmega328", 0)
         << QApplication::translate("UploadSettingForm", "Arduino Pro Mini (5V,16 MHz)  ATmega168", 0)
         << QApplication::translate("UploadSettingForm", "Arduino Pro Mini (3.3V,8 MHz) ATmega328", 0)
         << QApplication::translate("UploadSettingForm", "Arduino Pro Mini (3.3V,8 MHz) ATmega168", 0)
         << QApplication::translate("UploadSettingForm", "Arduino NG or older ATmega168", 0)
         << QApplication::translate("UploadSettingForm", "Arduino NG or older ATmega8", 0)
         << QApplication::translate("UploadSettingForm", "Arduino Robot Control", 0)
         << QApplication::translate("UploadSettingForm", "Arduino Robot Motor", 0)
         << QApplication::translate("UploadSettingForm", "-------------DFRobot----------------", 0)
         << QApplication::translate("UploadSettingForm", "Flyduino", 0)
         << QApplication::translate("UploadSettingForm", "X-Board", 0)
         << QApplication::translate("UploadSettingForm", "X-Board V2", 0)
         << QApplication::translate("UploadSettingForm", "RoMeo", 0)
         << QApplication::translate("UploadSettingForm", "RoMeo V2", 0)
        );
        label_5->setText(QApplication::translate("UploadSettingForm", "Select Serial Port", 0));
        pushButtonUno->setText(QString());
        pushButtonLeonardo->setText(QString());
#ifndef QT_NO_TOOLTIP
        labelTipToard->setToolTip(QApplication::translate("UploadSettingForm", "<html><head/><body><p>Please select your Arduino board.</p><p><br/></p><p>\351\200\211\346\213\251\344\275\240\344\275\277\347\224\250\347\232\204Arduino\347\224\265\350\267\257\346\235\277</p><p>\345\246\202\346\236\234\345\234\250\345\210\227\350\241\250\344\270\255\346\211\276\344\270\215\345\210\260\344\275\240\351\234\200\350\246\201\347\232\204\345\236\213\345\217\267 \350\257\267\346\237\245\351\230\205\344\275\240\344\275\277\347\224\250\347\232\204\347\224\265\350\267\257\346\235\277\347\232\204\345\205\274\345\256\271Arduino\345\236\213\345\217\267</p><p><br/></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        labelTipToard->setText(QString());
#ifndef QT_NO_TOOLTIP
        labelTipSerialPort->setToolTip(QApplication::translate("UploadSettingForm", "<html><head/><body><p>Please select your Arduino board serial port.</p><p><br/></p><p>\351\200\211\346\213\251\344\275\240\347\232\204Arduino\346\211\200\345\234\250\347\232\204\344\270\262\345\217\243(Serial COM)</p><p>\345\246\202\346\236\234\345\210\227\350\241\250\344\270\255\351\273\230\350\256\244\347\232\204\344\270\262\345\217\243\345\217\267\344\270\215\346\230\257\344\275\240\346\203\263\350\246\201\347\232\204 \350\257\267\346\211\213\345\267\245\344\277\256\346\224\271</p><p>**\345\275\223\344\275\240\346\212\212Arduino\346\217\222\345\205\245USB\345\217\243\346\227\266Mind+\344\274\232\350\207\252\345\212\250\347\233\221\346\265\213\345\210\260 \344\275\206\345\217\252\344\274\232\350\207\252\345\212\250\351\200\211\346\213\251\351\273\230\350\256\244\347\232\204\347\254\254\344\270\200\344\270\252\344\270\262\345\217\243\345\217\267</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        labelTipSerialPort->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class UploadSettingForm: public Ui_UploadSettingForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPLOADSETTINGFORM_H
