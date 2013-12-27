/********************************************************************************
** Form generated from reading UI file 'FileInforForm.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEINFORFORM_H
#define UI_FILEINFORFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FileInforForm
{
public:
    QGridLayout *gridLayout;
    QWidget *widgetLeft;
    QWidget *widgetRight;
    QWidget *widgetTitel;
    QPushButton *pushButtonReturn;
    QLabel *label;
    QLineEdit *lineEditProjectName;
    QLineEdit *lineEditAuthor;
    QLineEdit *lineEditCategory;
    QLineEdit *lineEditTag;
    QTextEdit *textEditDescription;
    QListWidget *listWidgetPhoto;
    QLabel *label_2;

    void setupUi(QWidget *FileInforForm)
    {
        if (FileInforForm->objectName().isEmpty())
            FileInforForm->setObjectName(QStringLiteral("FileInforForm"));
        FileInforForm->resize(1025, 675);
        gridLayout = new QGridLayout(FileInforForm);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        widgetLeft = new QWidget(FileInforForm);
        widgetLeft->setObjectName(QStringLiteral("widgetLeft"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widgetLeft->sizePolicy().hasHeightForWidth());
        widgetLeft->setSizePolicy(sizePolicy);
        widgetLeft->setMinimumSize(QSize(180, 675));
        widgetLeft->setMaximumSize(QSize(180, 16777215));
        widgetLeft->setStyleSheet(QStringLiteral("border-image: url(:/images/Transparent_White_90.png);"));

        gridLayout->addWidget(widgetLeft, 0, 0, 1, 1);

        widgetRight = new QWidget(FileInforForm);
        widgetRight->setObjectName(QStringLiteral("widgetRight"));
        widgetRight->setStyleSheet(QLatin1String("QWidget#widgetRight\n"
"{\n"
"	background-color: rgba(4, 4, 4, 230);\n"
"}"));
        widgetTitel = new QWidget(widgetRight);
        widgetTitel->setObjectName(QStringLiteral("widgetTitel"));
        widgetTitel->setGeometry(QRect(0, 0, 844, 31));
        pushButtonReturn = new QPushButton(widgetTitel);
        pushButtonReturn->setObjectName(QStringLiteral("pushButtonReturn"));
        pushButtonReturn->setGeometry(QRect(0, 0, 41, 28));
        pushButtonReturn->setStyleSheet(QStringLiteral("border-image: url(:/resource/images/common/Back.png);"));
        label = new QLabel(widgetRight);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 30, 181, 41));
        QFont font;
        font.setFamily(QStringLiteral("Nexa Light"));
        font.setPointSize(26);
        font.setBold(false);
        font.setWeight(50);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        lineEditProjectName = new QLineEdit(widgetRight);
        lineEditProjectName->setObjectName(QStringLiteral("lineEditProjectName"));
        lineEditProjectName->setGeometry(QRect(30, 70, 451, 25));
        lineEditAuthor = new QLineEdit(widgetRight);
        lineEditAuthor->setObjectName(QStringLiteral("lineEditAuthor"));
        lineEditAuthor->setGeometry(QRect(30, 110, 451, 25));
        lineEditCategory = new QLineEdit(widgetRight);
        lineEditCategory->setObjectName(QStringLiteral("lineEditCategory"));
        lineEditCategory->setGeometry(QRect(30, 150, 451, 25));
        lineEditTag = new QLineEdit(widgetRight);
        lineEditTag->setObjectName(QStringLiteral("lineEditTag"));
        lineEditTag->setGeometry(QRect(30, 190, 451, 25));
        textEditDescription = new QTextEdit(widgetRight);
        textEditDescription->setObjectName(QStringLiteral("textEditDescription"));
        textEditDescription->setGeometry(QRect(30, 230, 591, 241));
        listWidgetPhoto = new QListWidget(widgetRight);
        listWidgetPhoto->setObjectName(QStringLiteral("listWidgetPhoto"));
        listWidgetPhoto->setGeometry(QRect(30, 530, 801, 111));
        listWidgetPhoto->setFlow(QListView::LeftToRight);
        listWidgetPhoto->setSpacing(20);
        label_2 = new QLabel(widgetRight);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 490, 241, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Nexa Light"));
        font1.setPointSize(26);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        label_2->setFont(font1);
        label_2->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(widgetRight, 0, 1, 1, 1);


        retranslateUi(FileInforForm);

        QMetaObject::connectSlotsByName(FileInforForm);
    } // setupUi

    void retranslateUi(QWidget *FileInforForm)
    {
        FileInforForm->setWindowTitle(QApplication::translate("FileInforForm", "Form", 0));
        pushButtonReturn->setText(QString());
        label->setText(QApplication::translate("FileInforForm", "Blink.mps", 0));
        label_2->setText(QApplication::translate("FileInforForm", "Screen shot", 0));
    } // retranslateUi

};

namespace Ui {
    class FileInforForm: public Ui_FileInforForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEINFORFORM_H
