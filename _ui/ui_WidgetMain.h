/********************************************************************************
** Form generated from reading UI file 'WidgetMain.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETMAIN_H
#define UI_WIDGETMAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>
#include "ListWidget.h"
#include "WidgetBackgroundRight.h"
#include "WidgetShowScene.h"
#include "logininforwidget.h"

QT_BEGIN_NAMESPACE

class Ui_WidgetMain
{
public:
    QGridLayout *gridLayout_15;
    QWidget *widgetTitle;
    QHBoxLayout *horizontalLayout;
    QWidget *widgetMove;
    QPushButton *pushButtonInfor;
    LoginInforWidget *widgetLoginInfor;
    QLabel *labelLogo;
    QWidget *widgetRightTop;
    QPushButton *pushButtonMinSize;
    QPushButton *pushButtonMaxSize;
    QPushButton *pushButtonClose;
    QWidget *widgetMain;
    QGridLayout *gridLayout_5;
    QSplitter *splitter;
    QWidget *widgetLeft;
    QGridLayout *gridLayout;
    QWidget *widget_2;
    QGridLayout *gridLayout_4;
    QStackedWidget *stackedWidget;
    QWidget *page_2;
    QGridLayout *gridLayout_10;
    QWidget *widgetBeginner;
    QGridLayout *gridLayout_12;
    ListWidget *listWidgetBeginner1;
    QLabel *labelSplit;
    ListWidget *listWidgetBeginner2;
    QWidget *page;
    QGridLayout *gridLayout_9;
    QWidget *widgetAdvanced;
    QGridLayout *gridLayout_11;
    QSplitter *splitter_4;
    QWidget *widgetListWidget;
    QGridLayout *gridLayout_6;
    QSplitter *splitter_2;
    QWidget *widget_5;
    QGridLayout *gridLayout_7;
    QTreeWidget *treeWidget;
    QWidget *widgetBlockType;
    QGridLayout *gridLayout_8;
    QWidget *widgetpward;
    QGridLayout *gridLayout_13;
    QPushButton *pushButtonUpward;
    QStackedWidget *stackedWidgetBlockType;
    QWidget *page_3;
    QWidget *page_4;
    QWidget *widget_8;
    QGridLayout *gridLayout_14;
    QPushButton *pushButtonDownward;
    QTextEdit *textEditIntroduce;
    QWidget *widgetMenu;
    QGridLayout *gridLayout_3;
    QListWidget *listWidgetMenu;
    WidgetBackgroundRight *widgetRight;
    QGridLayout *gridLayout_2;
    QWidget *widgetOption;
    WidgetShowScene *widgetShowScene;

    void setupUi(QWidget *WidgetMain)
    {
        if (WidgetMain->objectName().isEmpty())
            WidgetMain->setObjectName(QStringLiteral("WidgetMain"));
        WidgetMain->resize(1026, 677);
        WidgetMain->setMinimumSize(QSize(1026, 675));
        WidgetMain->setStyleSheet(QLatin1String("QWidget#WidgetMain\n"
"{\n"
"	background-color: rgba(127, 127, 127, 127);\n"
"}"));
        gridLayout_15 = new QGridLayout(WidgetMain);
        gridLayout_15->setSpacing(0);
        gridLayout_15->setObjectName(QStringLiteral("gridLayout_15"));
        gridLayout_15->setContentsMargins(1, 1, 1, 1);
        widgetTitle = new QWidget(WidgetMain);
        widgetTitle->setObjectName(QStringLiteral("widgetTitle"));
        widgetTitle->setMinimumSize(QSize(1024, 27));
        widgetTitle->setMaximumSize(QSize(16777215, 27));
        widgetTitle->setStyleSheet(QStringLiteral("border-image: url(:/resource/images/title/titlebg.png);"));
        horizontalLayout = new QHBoxLayout(widgetTitle);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widgetMove = new QWidget(widgetTitle);
        widgetMove->setObjectName(QStringLiteral("widgetMove"));
        widgetMove->setMinimumSize(QSize(0, 27));
        widgetMove->setMaximumSize(QSize(16777215, 27));
        widgetMove->setStyleSheet(QStringLiteral(""));
        pushButtonInfor = new QPushButton(widgetMove);
        pushButtonInfor->setObjectName(QStringLiteral("pushButtonInfor"));
        pushButtonInfor->setGeometry(QRect(360, 0, 91, 27));
        pushButtonInfor->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"	color: rgb(255, 255, 255);\n"
"	border-color: rgba(255, 255, 255, 0);\n"
"	font: 9pt \"Microsoft YaHei UI\";\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"	color: rgb(73, 160, 193);\n"
"	border-color: rgba(255, 255, 255, 0);\n"
"	font: 9pt \"Microsoft YaHei UI\";\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"	color: rgb(236, 209, 209);	\n"
"	border-color: rgba(255, 255, 255, 0);\n"
"	font: 9pt \"Microsoft YaHei UI\";\n"
"}"));
        widgetLoginInfor = new LoginInforWidget(widgetMove);
        widgetLoginInfor->setObjectName(QStringLiteral("widgetLoginInfor"));
        widgetLoginInfor->setGeometry(QRect(710, 0, 111, 27));
        widgetLoginInfor->setMinimumSize(QSize(111, 27));
        widgetLoginInfor->setStyleSheet(QLatin1String("\n"
"	border-image: url(:/resource/images/title/titlebg.png);\n"
"	font: 9pt \"Microsoft YaHei UI\";\n"
""));
        labelLogo = new QLabel(widgetMove);
        labelLogo->setObjectName(QStringLiteral("labelLogo"));
        labelLogo->setGeometry(QRect(5, 4, 37, 18));
        labelLogo->setStyleSheet(QLatin1String("QWidget#labelLogo\n"
"{\n"
"	border-image: url(:/resource/images/title/Title.png);\n"
"}"));

        horizontalLayout->addWidget(widgetMove);

        widgetRightTop = new QWidget(widgetTitle);
        widgetRightTop->setObjectName(QStringLiteral("widgetRightTop"));
        widgetRightTop->setMinimumSize(QSize(75, 27));
        widgetRightTop->setMaximumSize(QSize(75, 31));
        widgetRightTop->setStyleSheet(QStringLiteral(""));
        pushButtonMinSize = new QPushButton(widgetRightTop);
        pushButtonMinSize->setObjectName(QStringLiteral("pushButtonMinSize"));
        pushButtonMinSize->setGeometry(QRect(0, 0, 25, 25));
        pushButtonMinSize->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-image: url(:/resource/images/title/Title_minimize.png);\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	border-image: url(:/resource/images/title/Title_minimize_OVER.png);\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	border-image: url(:/resource/images/title/Title_minimize.png);\n"
"}"));
        pushButtonMaxSize = new QPushButton(widgetRightTop);
        pushButtonMaxSize->setObjectName(QStringLiteral("pushButtonMaxSize"));
        pushButtonMaxSize->setGeometry(QRect(25, 0, 25, 25));
        pushButtonMaxSize->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-image: url(:/resource/images/title/Title_maximize.png);\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	border-image: url(:/resource/images/title/Title_maximize_OVER.png);\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	border-image: url(:/resource/images/title/Title_maximize.png);\n"
"}"));
        pushButtonClose = new QPushButton(widgetRightTop);
        pushButtonClose->setObjectName(QStringLiteral("pushButtonClose"));
        pushButtonClose->setGeometry(QRect(50, 0, 25, 25));
        pushButtonClose->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-image: url(:/resource/images/title/Title_close.png);\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	border-image: url(:/resource/images/title/Title_close_OVER.png);\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	border-image: url(:/resource/images/title/Title_close.png);\n"
"}"));

        horizontalLayout->addWidget(widgetRightTop);


        gridLayout_15->addWidget(widgetTitle, 0, 0, 1, 1);

        widgetMain = new QWidget(WidgetMain);
        widgetMain->setObjectName(QStringLiteral("widgetMain"));
        widgetMain->setMinimumSize(QSize(1024, 648));
        gridLayout_5 = new QGridLayout(widgetMain);
        gridLayout_5->setSpacing(0);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        splitter = new QSplitter(widgetMain);
        splitter->setObjectName(QStringLiteral("splitter"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy);
        splitter->setStyleSheet(QStringLiteral(""));
        splitter->setFrameShadow(QFrame::Plain);
        splitter->setLineWidth(0);
        splitter->setOrientation(Qt::Horizontal);
        splitter->setHandleWidth(1);
        widgetLeft = new QWidget(splitter);
        widgetLeft->setObjectName(QStringLiteral("widgetLeft"));
        widgetLeft->setMinimumSize(QSize(0, 648));
        widgetLeft->setMaximumSize(QSize(600, 16777215));
        widgetLeft->setStyleSheet(QLatin1String("QWidget#widgetLeft\n"
"{\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
""));
        gridLayout = new QGridLayout(widgetLeft);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(widgetLeft);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        gridLayout_4 = new QGridLayout(widget_2);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(widget_2);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        gridLayout_10 = new QGridLayout(page_2);
        gridLayout_10->setSpacing(0);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        gridLayout_10->setContentsMargins(0, 0, 0, 0);
        widgetBeginner = new QWidget(page_2);
        widgetBeginner->setObjectName(QStringLiteral("widgetBeginner"));
        widgetBeginner->setStyleSheet(QLatin1String("QListView::item\n"
"{\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
"QListView::item::hover\n"
"{\n"
"	background-color: rgb(214, 255, 177);\n"
"}\n"
""));
        gridLayout_12 = new QGridLayout(widgetBeginner);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        gridLayout_12->setHorizontalSpacing(6);
        gridLayout_12->setVerticalSpacing(0);
        gridLayout_12->setContentsMargins(0, 1, 0, 0);
        listWidgetBeginner1 = new ListWidget(widgetBeginner);
        listWidgetBeginner1->setObjectName(QStringLiteral("listWidgetBeginner1"));
        listWidgetBeginner1->setMinimumSize(QSize(0, 362));
        listWidgetBeginner1->setFocusPolicy(Qt::NoFocus);
        listWidgetBeginner1->setStyleSheet(QStringLiteral(""));
        listWidgetBeginner1->setFrameShape(QFrame::NoFrame);
        listWidgetBeginner1->setFrameShadow(QFrame::Plain);
        listWidgetBeginner1->setLineWidth(0);
        listWidgetBeginner1->setSpacing(6);

        gridLayout_12->addWidget(listWidgetBeginner1, 0, 0, 1, 1);

        labelSplit = new QLabel(widgetBeginner);
        labelSplit->setObjectName(QStringLiteral("labelSplit"));
        labelSplit->setMinimumSize(QSize(0, 1));
        labelSplit->setMaximumSize(QSize(16777215, 1));
        labelSplit->setStyleSheet(QStringLiteral("background-image: url(:/resource/images/BeginnerToolbar/BeginnerToolbar_SplitLine.png);"));

        gridLayout_12->addWidget(labelSplit, 1, 0, 1, 1);

        listWidgetBeginner2 = new ListWidget(widgetBeginner);
        listWidgetBeginner2->setObjectName(QStringLiteral("listWidgetBeginner2"));
        listWidgetBeginner2->setFocusPolicy(Qt::NoFocus);
        listWidgetBeginner2->setStyleSheet(QStringLiteral(""));
        listWidgetBeginner2->setFrameShape(QFrame::NoFrame);
        listWidgetBeginner2->setFrameShadow(QFrame::Plain);
        listWidgetBeginner2->setLineWidth(0);
        listWidgetBeginner2->setSpacing(6);

        gridLayout_12->addWidget(listWidgetBeginner2, 2, 0, 1, 1);


        gridLayout_10->addWidget(widgetBeginner, 0, 0, 1, 1);

        stackedWidget->addWidget(page_2);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        gridLayout_9 = new QGridLayout(page);
        gridLayout_9->setSpacing(0);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        gridLayout_9->setContentsMargins(0, 0, 0, 0);
        widgetAdvanced = new QWidget(page);
        widgetAdvanced->setObjectName(QStringLiteral("widgetAdvanced"));
        gridLayout_11 = new QGridLayout(widgetAdvanced);
        gridLayout_11->setSpacing(0);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        gridLayout_11->setContentsMargins(0, 0, 0, 0);
        splitter_4 = new QSplitter(widgetAdvanced);
        splitter_4->setObjectName(QStringLiteral("splitter_4"));
        splitter_4->setLineWidth(0);
        splitter_4->setOrientation(Qt::Vertical);
        splitter_4->setHandleWidth(1);
        widgetListWidget = new QWidget(splitter_4);
        widgetListWidget->setObjectName(QStringLiteral("widgetListWidget"));
        widgetListWidget->setStyleSheet(QLatin1String("QWidget#widgetListWidget\n"
"{\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        gridLayout_6 = new QGridLayout(widgetListWidget);
        gridLayout_6->setSpacing(0);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        splitter_2 = new QSplitter(widgetListWidget);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setFrameShadow(QFrame::Sunken);
        splitter_2->setLineWidth(0);
        splitter_2->setOrientation(Qt::Horizontal);
        splitter_2->setHandleWidth(1);
        widget_5 = new QWidget(splitter_2);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        gridLayout_7 = new QGridLayout(widget_5);
        gridLayout_7->setSpacing(0);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 21, 0, 0);
        treeWidget = new QTreeWidget(widget_5);
        treeWidget->headerItem()->setText(0, QString());
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setFocusPolicy(Qt::NoFocus);
        treeWidget->setStyleSheet(QLatin1String("QTreeView::item\n"
"{\n"
"	font: 11px \"arial\";\n"
"	color: rgb(127, 127, 127);\n"
"}\n"
"QTreeView::item::hover\n"
"{\n"
"	font: 11px \"arial\";\n"
"	background-color: rgb(0, 0, 0);\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"QTreeView::item::selected\n"
"{\n"
"	font: 11px \"arial\";\n"
"	background-color: rgb(0, 0, 0);\n"
"	color: rgb(255, 255, 255);\n"
"}"));
        treeWidget->setFrameShape(QFrame::NoFrame);
        treeWidget->setFrameShadow(QFrame::Sunken);
        treeWidget->setLineWidth(0);
        treeWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        treeWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        treeWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        treeWidget->header()->setVisible(false);

        gridLayout_7->addWidget(treeWidget, 0, 0, 1, 1);

        splitter_2->addWidget(widget_5);
        widgetBlockType = new QWidget(splitter_2);
        widgetBlockType->setObjectName(QStringLiteral("widgetBlockType"));
        widgetBlockType->setMinimumSize(QSize(100, 0));
        gridLayout_8 = new QGridLayout(widgetBlockType);
        gridLayout_8->setSpacing(0);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        widgetpward = new QWidget(widgetBlockType);
        widgetpward->setObjectName(QStringLiteral("widgetpward"));
        widgetpward->setMinimumSize(QSize(0, 21));
        widgetpward->setMaximumSize(QSize(16777215, 21));
        widgetpward->setStyleSheet(QStringLiteral("background-color: rgb(233, 233, 233);"));
        gridLayout_13 = new QGridLayout(widgetpward);
        gridLayout_13->setSpacing(0);
        gridLayout_13->setObjectName(QStringLiteral("gridLayout_13"));
        gridLayout_13->setContentsMargins(0, 0, 0, 0);
        pushButtonUpward = new QPushButton(widgetpward);
        pushButtonUpward->setObjectName(QStringLiteral("pushButtonUpward"));
        pushButtonUpward->setMinimumSize(QSize(0, 12));
        pushButtonUpward->setMaximumSize(QSize(3000, 12));
        pushButtonUpward->setStyleSheet(QLatin1String("image: url(:/resource/images/common/roll_up.png);\n"
"border:none"));

        gridLayout_13->addWidget(pushButtonUpward, 0, 0, 1, 1);


        gridLayout_8->addWidget(widgetpward, 0, 0, 1, 1);

        stackedWidgetBlockType = new QStackedWidget(widgetBlockType);
        stackedWidgetBlockType->setObjectName(QStringLiteral("stackedWidgetBlockType"));
        stackedWidgetBlockType->setStyleSheet(QLatin1String("QListView::item\n"
"{\n"
"	font: 5px;\n"
"	color: rgb(127, 127, 127);\n"
"}\n"
"QListView::item::hover\n"
"{\n"
"	font: 11px \"arial\";\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(0,0,0);\n"
"}\n"
"QListView::item::selected\n"
"{\n"
"	font: 11px \"arial\";\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(0,0,0);\n"
"}\n"
"QListView\n"
"{\n"
"	background-color: rgb(233, 233, 233);\n"
"}\n"
"QStackedWidget\n"
"{\n"
"    background-color: rgb(233, 233, 233);\n"
"}\n"
"QListView {\n"
"    show-decoration-selected: 1; /* make the selection span the entire width of the view */\n"
"}"));
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        stackedWidgetBlockType->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        stackedWidgetBlockType->addWidget(page_4);

        gridLayout_8->addWidget(stackedWidgetBlockType, 1, 0, 1, 1);

        widget_8 = new QWidget(widgetBlockType);
        widget_8->setObjectName(QStringLiteral("widget_8"));
        widget_8->setMinimumSize(QSize(0, 21));
        widget_8->setMaximumSize(QSize(16777215, 21));
        widget_8->setStyleSheet(QStringLiteral("background-color: rgb(233, 233, 233);"));
        gridLayout_14 = new QGridLayout(widget_8);
        gridLayout_14->setSpacing(0);
        gridLayout_14->setObjectName(QStringLiteral("gridLayout_14"));
        gridLayout_14->setContentsMargins(0, 0, 0, 0);
        pushButtonDownward = new QPushButton(widget_8);
        pushButtonDownward->setObjectName(QStringLiteral("pushButtonDownward"));
        pushButtonDownward->setMinimumSize(QSize(0, 12));
        pushButtonDownward->setMaximumSize(QSize(3000, 12));
        pushButtonDownward->setStyleSheet(QLatin1String("image: url(:/resource/images/common/roll_down.png);\n"
"border:none"));

        gridLayout_14->addWidget(pushButtonDownward, 0, 0, 1, 1);


        gridLayout_8->addWidget(widget_8, 2, 0, 1, 1);

        splitter_2->addWidget(widgetBlockType);

        gridLayout_6->addWidget(splitter_2, 0, 0, 1, 1);

        splitter_4->addWidget(widgetListWidget);
        textEditIntroduce = new QTextEdit(splitter_4);
        textEditIntroduce->setObjectName(QStringLiteral("textEditIntroduce"));
        textEditIntroduce->setStyleSheet(QStringLiteral("background-color: rgb(220, 220, 220);"));
        textEditIntroduce->setFrameShape(QFrame::NoFrame);
        textEditIntroduce->setFrameShadow(QFrame::Sunken);
        textEditIntroduce->setLineWidth(0);
        textEditIntroduce->setReadOnly(true);
        splitter_4->addWidget(textEditIntroduce);

        gridLayout_11->addWidget(splitter_4, 0, 0, 1, 1);


        gridLayout_9->addWidget(widgetAdvanced, 0, 0, 1, 1);

        stackedWidget->addWidget(page);

        gridLayout_4->addWidget(stackedWidget, 0, 0, 1, 1);


        gridLayout->addWidget(widget_2, 0, 0, 1, 1);

        widgetMenu = new QWidget(widgetLeft);
        widgetMenu->setObjectName(QStringLiteral("widgetMenu"));
        widgetMenu->setMinimumSize(QSize(0, 50));
        widgetMenu->setMaximumSize(QSize(16777215, 50));
        widgetMenu->setStyleSheet(QStringLiteral("background-color: rgb(204, 204, 204);"));
        gridLayout_3 = new QGridLayout(widgetMenu);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(13, 0, 0, 0);
        listWidgetMenu = new QListWidget(widgetMenu);
        listWidgetMenu->setObjectName(QStringLiteral("listWidgetMenu"));
        listWidgetMenu->setFocusPolicy(Qt::TabFocus);
        listWidgetMenu->setFrameShape(QFrame::NoFrame);
        listWidgetMenu->setFrameShadow(QFrame::Plain);
        listWidgetMenu->setLineWidth(0);
        listWidgetMenu->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidgetMenu->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidgetMenu->setIconSize(QSize(38, 38));
        listWidgetMenu->setFlow(QListView::LeftToRight);
        listWidgetMenu->setSpacing(1);
        listWidgetMenu->setViewMode(QListView::ListMode);

        gridLayout_3->addWidget(listWidgetMenu, 0, 0, 1, 1);


        gridLayout->addWidget(widgetMenu, 1, 0, 1, 1);

        splitter->addWidget(widgetLeft);
        widgetRight = new WidgetBackgroundRight(splitter);
        widgetRight->setObjectName(QStringLiteral("widgetRight"));
        widgetRight->setMinimumSize(QSize(0, 648));
        widgetRight->setStyleSheet(QLatin1String("QWidget#widgetRight\n"
"{\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}"));
        gridLayout_2 = new QGridLayout(widgetRight);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        widgetOption = new QWidget(widgetRight);
        widgetOption->setObjectName(QStringLiteral("widgetOption"));
        widgetOption->setMinimumSize(QSize(0, 54));
        widgetOption->setMaximumSize(QSize(16777215, 54));
        widgetOption->setStyleSheet(QStringLiteral("background-color: rgb(66, 178, 228);"));

        gridLayout_2->addWidget(widgetOption, 0, 0, 1, 1);

        widgetShowScene = new WidgetShowScene(widgetRight);
        widgetShowScene->setObjectName(QStringLiteral("widgetShowScene"));
        widgetShowScene->setMinimumSize(QSize(0, 0));
        widgetShowScene->setStyleSheet(QLatin1String("QWidget#widgetShowScene\n"
"{\n"
"	background-color: rgb(51, 51, 51);\n"
"}\n"
"QGraphicsView\n"
"{\n"
"	background-color: rgb(51, 51, 51);\n"
"}"));

        gridLayout_2->addWidget(widgetShowScene, 1, 0, 1, 1);

        splitter->addWidget(widgetRight);

        gridLayout_5->addWidget(splitter, 0, 0, 1, 1);


        gridLayout_15->addWidget(widgetMain, 1, 0, 1, 1);


        retranslateUi(WidgetMain);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(WidgetMain);
    } // setupUi

    void retranslateUi(QWidget *WidgetMain)
    {
        WidgetMain->setWindowTitle(QApplication::translate("WidgetMain", "Form", 0));
        pushButtonInfor->setText(QString());
        labelLogo->setText(QString());
        pushButtonMinSize->setText(QString());
        pushButtonMaxSize->setText(QString());
        pushButtonClose->setText(QString());
        labelSplit->setText(QString());
        pushButtonUpward->setText(QString());
        pushButtonDownward->setText(QString());
        textEditIntroduce->setHtml(QApplication::translate("WidgetMain", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Lucida Grande'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'SimSun'; font-size:9pt;\"><br /></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class WidgetMain: public Ui_WidgetMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETMAIN_H
