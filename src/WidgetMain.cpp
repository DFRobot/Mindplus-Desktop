#include "WidgetMain.h"
#include <QMouseEvent>
#include <QDebug>
#include <QDesktopWidget>
#include <QApplication>
#include <QFile>
#include <QDir>
#include <QTreeWidgetItemIterator>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QProcess>
#include <QMessageBox>
#include <QFileDialog>
#include <QThread>
#include <QResizeEvent>
#include <QPainter>
#include <QFileInfo>
#include <QPaintEvent>
#include <QSettings>
#include <QTimer>
#include <QCloseEvent>
#include <QMenu>
#include <QScrollBar>
#include <QScrollArea>

#include "DataStruct.h"
#include "DataBaseCreateComponent.h"
#include "DatabaseEditComponent.h"
#include "EditScene.h"
#include "GraphicsItemBase.h"
#include "DFRobotUploader.h"
#include "Uploader.h"
#include "UploadSettingForm.h"
#include "ListWidget.h"
#include "ListWidgetItem.h"
#include "ListWidgetItemWidget_Component.h"
#include "WidgetShowScene.h"
#include "FunctionArea.h"
#include "UploadWaitForm.h"
#include "FileInforForm.h"
#include "AllBlocksForm.h"
#include "MindKitForm.h"
#include "IntroduceForm.h"
#include "Parameter_Integer_Form.h"
#include "Parameter_LED8x8_Form.h"
#include "Parameter_String_Form.h"
#include "Parameter_Time_Form.h"
#include "MindKitPushButton.h"
#include "AffirmForm.h"
#include "CallUpdateProgram.h"
#include "SerialSettingWidget.h"
#include "Animation.h"
#include "Common.h"
#include "Label.h"
#include "GetBlockData.h"
#include "FlowLine.h"
#include "Translate.h"
#include "BlockMenuWidget.h"
#include "ListWidgetAdvanceBlock.h"
#include "WidgetForListWidgetBegin.h"
#include "SerialPortToolForm.h"

const int PRESSED_CLOSE = 1;
const int PRESSED_NEW_PROJECT = 2;

WidgetMain::WidgetMain(QWidget *parent)
    : QWidget(parent)
    , offset_()
    , boardIndex_("")
    , pUploadSetting_(NULL)
    , pEditScene_(NULL)
    , pFunctionArea_(NULL)
    , pSerialSetting_(NULL)
    , affirmType_(-1)
    , pDustbin_(NULL)
    , bDustbinShow_(false)
    , type_(-1)
    , pageIndex_(0)
    , pAllBlockMenu_(NULL)
	, pListWidget_(NULL)
	, pSerialPortTool_(NULL)
{
    setupUi(this);
    initSetting();
    initData();
    initGui();
}

QHash<QString, DataStruct> *WidgetMain::getComponentsData()
{
    return &hash_blockPath_blockData_;
}

EditScene *WidgetMain::getScenePointer()
{
    return pEditScene_;
}

//用于页面文字国际化
void WidgetMain::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type())
    {
        case QEvent::LanguageChange:
        {
            retranslateUi(this);
            break;
        }
        default:
        {
            break;
        }
    }
}

//事件过滤器, 现在用于响应标题栏的鼠标事件,目的在于拖动窗口和双击窗口最大化的功能
bool WidgetMain::eventFilter(QObject *target, QEvent *event)
{
	if(target == widgetMove
			|| target == labelLogo
			|| pushButtonInfor == target)
    {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
        switch(event->type())
        {
            case QEvent::MouseButtonPress:
            {
                if(Qt::LeftButton == mouseEvent->button())
                {
                    //获取屏幕左上角坐标与软件左上角坐标的偏移
                    offset_ = mouseEvent->globalPos() - frameGeometry().topLeft();
                    return true;
                }
                else
                {
                    return false;
                }
                break;
            }
            case QEvent::MouseMove:
            {
                if (Qt::LeftButton == mouseEvent->buttons() )
                {
                    move(mouseEvent->globalPos() - offset_);
                    return true;
                }
                else
                {
                    return false;
                }
                break;
            }
            case QEvent::MouseButtonDblClick:
            {
                if (Qt::LeftButton  == mouseEvent->button() && mouseEvent->y() <= widgetMove->height())
                {
                    if(windowState() != Qt::WindowFullScreen)
                    {
                        this->setWindowState(Qt::WindowFullScreen);
                    }
                    else
                    {
                        this->setWindowState(Qt::WindowNoState);
                    }
                    return true;
                }
                else
                {
                    return false;
                }
                break;
            }
            default:
            {
                //...
                break;
            }
                return true;
        }
    }
    else if(pDustbin_ == target)
    {
        if(QEvent::MouseButtonPress == event->type())
        {
            //在这里进行删除处理
            if(FOCUS_GROUP == type_)
            {
                if(!groupName_.isEmpty())
                {
                    Q_EMIT signalDeleteGroup(groupName_);
                    clearDustbinData();
                }
            }
            else if(FOCUS_LINE == type_)
            {
                if(pFlowLine_
                        && !startName_.isEmpty()
                        && !endName_.isEmpty())
                {
                    pFlowLine_->deleteLine();
                    clearDustbinData();
                }
            }
            else
            {
                qDebug() << "没有要删除的类型, 哪里赋值错了么?" << type_;
            }
            event->accept();
            return true;
        }
        else
        {
            event->ignore();
            return false;
        }
    }
    else if(widgetLeft == target)
    {
        if(QEvent::Resize == event->type()
                || QEvent::Show)
        {
            //这里move
			if(NULL != pSerialSetting_)
			{
				pSerialSetting_->move(widgetLeft->width()+5, widgetTitle->height()+3);
			}
			if(NULL != pFunctionArea_)
			{
				pFunctionArea_->move(splitter->sizes().at(0) + (widgetOption->width()-pFunctionArea_->width())/2, 31);
			}

            event->accept();
            return true;
        }
        else
        {
            event->ignore();
            return false;
        }
    }
	else if(pBackStart_ == target)
	{
		QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
		if(QEvent::MouseButtonPress == mouseEvent->type())
		{
			qDebug() << "啊被按住了~~";
			pEditScene_->backStart();
			event->accept();
			pBackStart_->hide();
			return true;
		}
		return QWidget::eventFilter(target, event);
	}
    else
    {
        return QWidget::eventFilter(target, event);
    }
}

void WidgetMain::resizeEvent(QResizeEvent *event)
{
    qDebug() << event->size();
    if(widgetTitle->width() != 100)
    {
        pushButtonInfor->move((widgetTitle->width() - pushButtonInfor->width()) /2 - 5, 0);
    }
	pSerialPortToolLabel_->move(this->width()-200, 31);
    widgetLoginInfor->move((widgetTitle->width() * 3/4) - (widgetLoginInfor->width() / 2), 0);
    qDebug() << "resizeEvent:" << "widgetOption->x():" << widgetOption->x() <<
                "(widgetOption->width()-pFunctionArea_->width())/2" << (widgetOption->width()-pFunctionArea_->width())/2;
    pFunctionArea_->move(splitter->sizes().at(0) + (widgetOption->width()-pFunctionArea_->width())/2, 31);
    pSerialSetting_->move(widgetLeft->width()+5, widgetTitle->height()+3);

    qDebug() << "更改大小了" << widgetShowScene->size();
}

void WidgetMain::showEvent(QShowEvent *event)
{
    Q_UNUSED(event);
	//pSerialPortTool_->show();
    pushButtonInfor->move(widgetTitle->width() * 1/2 - pushButtonInfor->width() / 2, 0);

    widgetLoginInfor->move((widgetTitle->width() * 3/4) - (widgetLoginInfor->width() / 2), 0);
    widgetLoginInfor->hide();
    //应该根据QSetting来进行配置
    splitter_2->setSizes(QList<int>() << 120 << 130);
    splitter_4->setSizes(QList<int>() << 450 << 150);
    {
        QSettings settingTmp("./resource/setting.ini", QSettings::IniFormat);
        QString value = settingTmp.value(tr("Normal/default")).toString();
        if("begin" == value)
        {

            splitter->setSizes(QList<int>() << 181 << width()-181);
            {
                QListWidgetItem *pCurrent = listWidgetMenu->item(0);
                QListWidgetItem *pprevious = listWidgetMenu->item(1);
                stackedWidget->setCurrentIndex(0);
                slotCurrentItemChanged(pCurrent, pprevious);
            }
        }
        else if("advanced" == value)
        {
            stackedWidget->setCurrentIndex(1);
            splitter->setSizes(QList<int>() << 250 << width()-250);
            {
                QListWidgetItem *pCurrent = listWidgetMenu->item(1);
                QListWidgetItem *pPrevious = listWidgetMenu->item(0);
                stackedWidget->setCurrentIndex(1);
                slotCurrentItemChanged(pCurrent, pPrevious);
            }
        }
        else
        {
            qDebug() << "QSetting 读取数据失败!" <<value;
        }
    }
	//pEditScene_->setInitScroll(0, -460);
}

#ifdef Q_OS_WIN
bool WidgetMain::winEvent(MSG *message, long *result)
{
	if(WM_NCHITTEST == message->message)
	{
		int xPos = GET_X_LPARAM(message->lParam) - this->frameGeometry().x();
		int yPos = GET_Y_LPARAM(message->lParam) - this->frameGeometry().y();
//        qDebug() << "current pos xPos = " << xPos << "yPos = " <<yPos;
		if(NULL == this->childAt(xPos,yPos))
		{
			*result = HTCAPTION;
		}
		else
		{
//			return QWidget::winEvent(message, result);
		}

		if(xPos > 0 && xPos < 4 && yPos > 0 && yPos < 4)
		{
			*result = HTTOPLEFT;
//            qDebug() << "HTTOPLEFT";
		}
		else if(xPos > (this->width() - 4) && xPos < (this->width() - 0) && yPos > 0 && yPos < 4)
		{
			*result = HTTOPRIGHT;
//            qDebug() << "HTTOPRIGHT";
		}
		else if(xPos > 0 && xPos < 4 && yPos > (this->height() - 4) && yPos < (this->height() - 0))
		{
			*result = HTBOTTOMLEFT;
//            qDebug() << "HTBOTTOMLEFT";
		}
		else if(xPos > (this->width() - 4) && xPos < (this->width() - 0) && yPos > (this->height() - 4) && yPos < (this->height() - 0))
		{
			*result = HTBOTTOMRIGHT;
//            qDebug() << "HTBOTTOMRIGHT";
		}
		else if(xPos > 0 && xPos < 4)
		{
			*result = HTLEFT;
//            qDebug() << "HTLEFT";
		}
		else if(xPos > (this->width() - 4) && xPos < (this->width() - 0))
		{
			*result = HTRIGHT;
//            qDebug() << "HTRIGHT";
		}
		else if(yPos > 0 && yPos < 4)
		{
			*result = HTTOP;
//            qDebug() << "HTTOP";
		}
		else if(yPos > (this->height() - 4) && yPos < (this->height() - 0))
		{
			*result = HTBOTTOM;
//            qDebug() << "HTBOTTOM";
		}
		return true;
	}

//	return QWidget::winEvent(message, result);
}
#endif

//关闭按钮
void WidgetMain::on_pushButtonClose_clicked()
{
    affirmType_ = PRESSED_CLOSE;
    AffirmForm *pAffirmForm = new AffirmForm(this->rect(), this);
    connect(pAffirmForm, SIGNAL(signalBack()), this, SLOT(slotPressBack()));
    connect(pAffirmForm, SIGNAL(signalNotSave()), this, SLOT(slotPressNotSave()));
    connect(pAffirmForm, SIGNAL(signalSave()), this, SLOT(slotPressSave()));
    pAffirmForm->setAttribute(Qt::WA_DeleteOnClose);
    //this->activateWindow();
    pAffirmForm->show();
}

//最大化按钮
void WidgetMain::on_pushButtonMaxSize_clicked()
{
    if(windowState() != Qt::WindowFullScreen)
    {
        this->setWindowState(Qt::WindowFullScreen);
    }
	else
	{
		this->setWindowState(Qt::WindowNoState);
	}
}

void WidgetMain::initSetting()
{
    this->setWindowFlags(Qt::FramelessWindowHint);
    //this->setWindowFlags(Qt::WindowStaysOnTopHint);
    widgetMove->installEventFilter(this);
}

void WidgetMain::initData()
{
	//设置TreeWidget的font大小
	{
		auto font = treeWidget->font();
		font.setPixelSize(11);
		treeWidget->setFont(font);
	}
	pushButtonInfor->installEventFilter(this);

    pDustbin_ = new Label(this);//还可以用他的hover,通过eventfilter
    pDustbin_->hide();

	pBackStart_ = new QLabel(this);
	pBackStart_->installEventFilter(this);
	QPixmap pix("./resource/images/bb/JumpToStart_idle.png");
	pBackStart_->resize(pix.size());
	pBackStart_->setPixmap(pix);
	{
		int y = widgetTitle->height()+widgetMenu->height()+10+255;
		pBackStart_->move(widgetLeft->width()+10, y);
	}
	//pBackStart_->setOpacity(0);
	pBackStart_->hide();

	pSerialPortToolLabel_ = new FunctionAreaWidget(this);
	connect(pSerialPortToolLabel_, SIGNAL(signalClick()), this, SLOT(slotCreateSerialTool()));
	pSerialPortToolLabel_->addData(QPixmap("./resource/images/tool_area/TopToolBar_Serial.png"), "Serial");
	pSerialPortToolLabel_->move(this->width()-200, 31);
	pSerialPortToolLabel_->show();
    {
        QPixmap pix("./resource/images/tool_area/TopToolBar_del");
        pDustbin_->resize(pix.size());
        pDustbin_->setPixmap(pix);
    }

    labelLogo->installEventFilter(this);
    pDustbin_->installEventFilter(this);
    widgetLeft->installEventFilter(this);

    pAllBlockMenu_ = new QMenu(this);

    {
        // 啦拉拉在这里检测所有的模块
        QString path = "./resource/Blocks";
        QDir dir(path);
        dir.setFilter(QDir::AllDirs | QDir::NoDotAndDotDot);
        foreach (const QString &dirName, dir.entryList())
        {
            //ListWidgetItem
            QString dirPath = path + "/" +dirName;
            QTreeWidgetItem *pTreeItem = new QTreeWidgetItem(treeWidget, QStringList(dirName));
            pTreeItem->setSizeHint(0, QSize(100,20));
            pTreeItem->setData(0,Qt::UserRole+1,dirPath);
            map_treeWidgetItemPointer_pageIndex_.insert(pTreeItem, pageIndex_++);
            //menu
            QMenu *pMenu = pAllBlockMenu_->addMenu(dirName);
            scanBlocks(dirPath, pTreeItem, pMenu);
        }
        {
            //treeWidget->setCurrentIndex(treeWidget->indexAt(QPoint(5, 5)));
        }
    }

    {
        QPixmap pixNormal("./resource/images/common/Blocks_Begin.png");
        QPixmap pixHover("./resource/images/common/Blocks_Begin_p.png");
        QPixmap pixPressed("./resource/images/common/Blocks_Begin_o.png");
        pixNormal.scaled(QSize(26, 26));
        pixHover.scaled(QSize(26, 26));
        QListWidgetItem *pItem = new QListWidgetItem("");
        pItem->setSizeHint(QSize(38, 38));//26*26
        BlockMenuWidget *pWidget = new BlockMenuWidget(pixNormal, pixHover, pixPressed);

        listWidgetMenu->addItem(pItem);
        listWidgetMenu->setItemWidget(pItem, pWidget);
    }
    {
        QPixmap pixNormal("./resource/images/common/Blocks_All.png");
        QPixmap pixHover("./resource/images/common/Blocks_All_p.png");
        QPixmap pixPressed("./resource/images/common/Blocks_All_o.png");
        pixNormal.scaled(QSize(26, 26));
        pixHover.scaled(QSize(26, 26));
        QListWidgetItem *pItem = new QListWidgetItem("");
        pItem->setSizeHint(QSize(38, 38));
        BlockMenuWidget *pWidget = new BlockMenuWidget(pixNormal, pixHover, pixPressed);

        listWidgetMenu->addItem(pItem);
        listWidgetMenu->setItemWidget(pItem, pWidget);
    }
    connect(listWidgetMenu, SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)), this,
                                   SLOT(slotCurrentItemChanged(QListWidgetItem*,QListWidgetItem*)));

    pEditScene_ = new EditScene(QRectF(0, 0, 840, 640), widgetShowScene);
    pEditScene_->setWidgetMain(this);
    pEditScene_->setComponentData(&hash_blockPath_blockData_);
    pEditScene_->addModuleTagData(map_moduleName_moduleTag_);
    widgetShowScene->setScenePointer(pEditScene_ );
    //	pEditScene_->setListWidgetModulePointer(listWidget);
	connect(pEditScene_, SIGNAL(signalViewOffset(QPoint)), this, SLOT(slotViewOffset(QPoint)));
    connect(pEditScene_, SIGNAL(signalShowSubWindows()), this, SLOT(slotShowSubWindows()));
    connect(pEditScene_, SIGNAL(signalFocusInLine(FlowLine*,QString,QString)), this,
            SLOT(slotFocusInLine(FlowLine*,QString,QString)));
    connect(pEditScene_, SIGNAL(signalFocusInGroup(QString)), this, SLOT(slotFocusInGroup(QString)));
    connect(this, SIGNAL(signalCreateGroup(QString)), pEditScene_, SLOT(slotCreateGroup(QString)));

    createListWidget();
    pListWidget_ = static_cast<ListWidgetAdvanceBlock*>(stackedWidgetBlockType->currentWidget());

	QTimer::singleShot(50, this, SLOT(slotOpenAutoUpdate()));
}

void WidgetMain::initGui()
{
    pFunctionArea_ = new FunctionArea(this);
    pFunctionArea_->show();

    connect(pFunctionArea_, SIGNAL(signalNewProjectClick()), this, SLOT(slotClickNewProject()));
    connect(pFunctionArea_, SIGNAL(signalOpenClick()), this, SLOT(slotClickOpen()));
    connect(pFunctionArea_, SIGNAL(signalSaveClick()), this, SLOT(slotClickSave()));
    connect(pFunctionArea_, SIGNAL(signalUploadClick()), this, SLOT(slotClickUpload()));

    pSerialSetting_ = new SerialSettingWidget(this);
    connect(pSerialSetting_, SIGNAL(signalClick()), this, SLOT(slotPressSerialSetting()));
    pSerialSetting_->show();
}

void WidgetMain::on_pushButtonMinSize_clicked()
{
    this->showMinimized();
}

void WidgetMain::slotClickUpload()
{
	{
		//如果存在串口监视的则暂停
		if(NULL != pSerialPortTool_)
		{
			pSerialPortTool_->closePort();
			pSerialPortTool_->close();
		}
	}
    //加入是否已经设置好串口的判断
    if(pSerialSetting_->getBoardType() == tr("Plase Set Arduino Type")
            || pSerialSetting_->getSerialPort() == tr("Serial Port"))
    {
        //在此调出串口设置界面让其设置
        createUploadSetting();
    }
    else
    {
        UploadWaitForm *p = new UploadWaitForm(this->rect(), this);
        p->setAttribute(Qt::WA_DeleteOnClose);
        QSettings settingTmp("./resource/setting.ini", QSettings::IniFormat);
        QString value = settingTmp.value(tr("Normal/uploader")).toString();
        QString filePath;
        if(value == "ArduinoUploader")
        {
#ifdef Q_OS_MAC
			QDir dir("./resource/tools/ArduinoUploader/ArduinoUploader.app/Contents/MacOS");
			if(!dir.exists("Temp"))
			{
				dir.mkdir("Temp");
			}
            filePath = "./resource/tools/ArduinoUploader/ArduinoUploader.app/Contents/MacOS/Temp/code.cpp";
#else
			QDir dir("./resource/tools/ArduinoUploader");
			if(!dir.exists("Temp"))
			{
				dir.mkdir("Temp");
			}
            filePath = "./resource/tools/ArduinoUploader/Temp/code.cpp";
#endif
        }
        else if(value == "DFRobotUploader")
        {
#ifdef Q_OS_MAC
			QDir dir("./resource/tools/ArduinoUploader/ArduinoUploader.app/Contents/MacOS");
			if(!dir.exists("Temp"))
			{
				dir.mkdir("Temp");
			}
			filePath = "./resource/tools/ArduinoUploader/ArduinoUploader.app/Contents/MacOS/Temp/code.cpp";
#else
			QDir dir("./resource/tools/ArduinoUploader");
			if(!dir.exists("Temp"))
			{
				dir.mkdir("Temp");
			}
			filePath = "./resource/tools/ArduinoUploader/Temp/code.cpp";
#endif
        }

        Uploader  *pUpload = new Uploader(filePath, boardIndex_, pSerialSetting_->getSerialPort());
        QThread *pThread = new QThread;
        pUpload->moveToThread(pThread);
        connect(pThread, SIGNAL(started()), pUpload, SLOT(slotStart()));
        connect(pUpload, SIGNAL(signalCurrentProgress(float, int)), p, SLOT(slotAdvanceProgress(float,int)), Qt::QueuedConnection);

        connect(pUpload, SIGNAL(signalBoardError(QString)), p, SLOT(SlotBoardError(QString)), Qt::QueuedConnection);
        connect(pUpload, SIGNAL(signalTypeConversionError(QString)), p, SLOT(SlotTypeConversionError(QString)), Qt::QueuedConnection);
        connect(pUpload, SIGNAL(signalPortError(QString)), p, SLOT(SlotPortError(QString)), Qt::QueuedConnection);
        connect(pUpload, SIGNAL(signalCompileEnd()), p, SLOT(SlotCompileEnd()));
        connect(p, SIGNAL(signalCancel()), pThread, SLOT(terminate()));

        p->show();
        pThread->start();
    }
}

void WidgetMain::slotClickSave()
{
    saveCurrentState();
}

void WidgetMain::slotClickOpen()
{
    this->on_pushButtonLoad_clicked();
}

void WidgetMain::slotClickNewProject()
{
    affirmType_ = PRESSED_NEW_PROJECT;
    AffirmForm *pAffirmForm = new AffirmForm(this->rect(), this);
    connect(pAffirmForm, SIGNAL(signalBack()), this, SLOT(slotPressBack()));
    connect(pAffirmForm, SIGNAL(signalNotSave()), this, SLOT(slotPressNotSave()));
    connect(pAffirmForm, SIGNAL(signalSave()), this, SLOT(slotPressSave()));
    pAffirmForm->setAttribute(Qt::WA_DeleteOnClose);
    //this->activateWindow();
    pAffirmForm->show();
}

void WidgetMain::slotBoardTypeItemClicked(const QString &boardName, const QString &index)
{
    //labelType->setText(boardName);
    //    widgetUpload->setUploadParameter(boardName, "");
    pSerialSetting_->setBoardType(boardName);
    boardIndex_ = index;
}

void WidgetMain::slotSerialItemClicked(const QString &serialName)
{
    //labelSerial->setText(serialName);
    pSerialSetting_->setSerialPort(serialName);
    //widgetUpload->setUploadParameter("", serialName);
}

void WidgetMain::slotShowMindKit()
{
    if(pMindKitForm_)
    {
        pMindKitForm_.data()->raise();
        pMindKitForm_.data()->show();
        return;
    }
    pMindKitForm_ = new MindKitForm(this);
    connect(pMindKitForm_.data(), SIGNAL(signalMindKitPushButtonPointer(MindKitPushButton*)), this, SLOT(slotMindKitPushButtonPointer(MindKitPushButton*)));
    pMindKitForm_.data()->show();
}

void WidgetMain::slotHideMindKit()
{
    if(pMindKitForm_)
    {
        pMindKitForm_.data()->hide();
    }
}

void WidgetMain::slotDone()
{
    slotClickUpload();
}

void WidgetMain::slotShowIntroduce(const QString &type)
{
    if(pIntroduceForm_)
    {
        pIntroduceForm_.data()->raise();
        pIntroduceForm_.data()->show();
        return;
    }
    pIntroduceForm_ = new IntroduceForm(this->rect(), &hash_blockPath_blockData_, type, this);
    //connect(pIntroduceForm_, SIGNAL(signalClose(QWidget*)), this, SLOT(slotSubWindowsClose(QWidget*)));
    connect(pIntroduceForm_, SIGNAL(signalHideSubWindows()), this, SLOT(slotHideSubWindows()));
    connect(pIntroduceForm_, SIGNAL(signalShowSubWindows()), this, SLOT(slotShowSubWindows()));

    pIntroduceForm_->setObjectName("IntroduceForm");
    pIntroduceForm_->setAttribute(Qt::WA_DeleteOnClose);
    pIntroduceForm_->show();
}

void WidgetMain::slotHideSubWindows()
{
    if(pIntroduceForm_)
    {
        pIntroduceForm_.data()->hide();
    }
}

void WidgetMain::slotShowSubWindows()
{
    if(pIntroduceForm_)
    {
        //pIntroduceForm_.data()->raise();
        qDebug() << "要恢复";
        pIntroduceForm_.data()->show();
    }
}

void WidgetMain::slotMindKitPushButtonPointer(MindKitPushButton *pointer)
{
    pEditScene_->setMindKitPushButtonPointer(pointer);
}

/*!
 * \brief 在这里调用自动更新
 */
void WidgetMain::slotOpenAutoUpdate()
{
//    QThread *p = new QThread(this);

//    CallUpdateProgram * pCall = new CallUpdateProgram();
//    connect(p, SIGNAL(started()), pCall, SLOT(slotCallUpdateProgram()));
//    pCall->moveToThread(p);

//    p->start();
//	qDebug() << "初始化你妹";
}

void WidgetMain::on_pushButtonSetting_clicked()
{
    createUploadSetting();
}

void WidgetMain::on_pushButtonSave_clicked()
{
    qDebug() << "话说要保存文件了";
    QString fileSavePath = QFileDialog::getSaveFileName(this, tr("保存文件"), ".", "*.mps");

    pEditScene_->saveFile(fileSavePath.toUtf8());
}

void WidgetMain::on_pushButtonLoad_clicked()
{
	QString filePath = QFileDialog::getOpenFileName(this, tr("选择文件"), ".", "*.mps");
	if(!filePath.isEmpty())
	{
		qDebug() << filePath.toUtf8();
		QSqlDatabase db = QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE", "load"));
		db.setDatabaseName(filePath.toUtf8());

		if(!db.open())
		{
			qDebug() << "加载中间文件失败";
			return;
		}
		////清空当前
		pEditScene_->setReset();

		QSqlQuery query(db);
		query.exec("select * from items");
		while (query.next())
		{
			QString bbName = query.value(0).toString();
			int id = query.value(1).toInt();
			QPointF point(query.value(2).toInt(), query.value(3).toInt());

			if(!hash_blockPath_blockData_.contains(bbName))
			{
				qDebug() << "找不到模块" << bbName << "对应的数据";
				continue;
			}

			pEditScene_->createItemGroup(point, bbName, id, true, "", "");
		}

		query.exec("select * from lines");
		while (query.next())
		{
			QString startName = query.value(0).toString();
			QString endName = query.value(1).toString();
			//需要一个根据模块返回对应指针的东西

			GraphicsItemBase *pStartItem = pEditScene_->getItemPointer(startName);
			GraphicsItemBase *pEndItem =pEditScene_->getItemPointer(endName);
			if(NULL != pStartItem
					&& NULL != pEndItem)
			{
				QString startDetailType = pStartItem->getItemTypeDetail();
				if("start" == startName)
				{
					startDetailType = "start";
				}

				QString endDetailType = pEndItem->getItemTypeDetail();
				if(startDetailType == "parameterIn"
						&& endDetailType == "parameterOut")
				{//parameterIn只能和parameterOut相连
					qDebug() << pEndItem->data(ITEM_TYPE_DETAIL).toString() << pEndItem->data(ITEM_NAME).toString();
					QString a = tr("LocalParameter_") + pEditScene_->pDatabaseEditComponent_->getParamterId(pStartItem->data(ITEM_NAME).toString());
					pEditScene_->setStartItem(pStartItem);
					qDebug() << "nimeide ????" << pStartItem->getFindPathPoint();

					pEditScene_->addLinePreprocess(pEndItem, pEndItem->data(ITEM_NAME).toString() , a);
				}
				else if(startDetailType == "parameterOut"
						&& endDetailType == "parameterIn")
				{
					//这里查表取出param的位置
					QString a = tr("LocalParameter_") + pEditScene_->pDatabaseEditComponent_->getParamterId(pEndItem->data(ITEM_NAME).toString());
					qDebug() << a;
					pEditScene_->setStartItem(pStartItem);
					qDebug() << "nimeide ????" << pStartItem->getFindPathPoint();

					pEditScene_->addLinePreprocess(pEndItem,  pStartItem->data(ITEM_NAME).toString(), a);
				}
				else if("start" == startDetailType
						&& "behaviourIn" == endDetailType)
				{   //下面看起来很冗余的判断实际上是为了修正连线后流动的方向
					qDebug() << "可以释放 behavior";
					if(pStartItem)
					{   //下面看起来很冗余的判断实际上是为了修正连线后流动的方向
						pEditScene_->addLinePreprocess(pStartItem, pEndItem);
					}
				}
				else if("behaviourIn" == startDetailType
						&&"start" == endDetailType)
				{
					if(pStartItem)
					{
						pEditScene_->addLinePreprocess(pEndItem, pStartItem);
					}
				}
				else if("behaviourIn" == startDetailType
						&& "behaviourOut" == endDetailType)
				{
					if(pStartItem)
					{   //下面看起来很冗余的判断实际上是为了修正连线后流动的方向
						pEditScene_->addLinePreprocess(pEndItem, pStartItem);
					}
				}
				else if("behaviourOut" == startDetailType
						&& "behaviourIn" == endDetailType)
				{
					if(pStartItem)
					{   //下面看起来很冗余的判断实际上是为了修正连线后流动的方向
						pEditScene_->addLinePreprocess(pStartItem, pEndItem);
					}
				}
			}
			else
			{
				qDebug() <<"竟然会返回NULL指针, 什么情况!!";
			}
		}

		//这里需要在创建模块之后, 这里还是有隐患
		query.exec("select * from number");
		while (query.next())
		{
			QString name = query.value(0).toString();
			int count = query.value(1).toInt();

			qDebug() << name << count << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
			pEditScene_->setComponentCount(name, count);
		}

		query.exec("select * from parameter");
		while (query.next())
		{
			QString name = query.value(0).toString();
			QString value = query.value(1).toString();

			qDebug() << name << value << "ASDASDDFSDG%%%%%%%%%%%%%";
			pEditScene_->setParameterValue(name, value);
		}
	}
}

void WidgetMain::on_pushButtonInfor_clicked()
{
    //    qDebug() << "填写信息";
    //    FileInforForm *pFileInforForm = new FileInforForm(this);

    //    pFileInforForm->setAttribute(Qt::WA_DeleteOnClose);
    //    pFileInforForm->show();
}

void WidgetMain::createUploadSetting()
{
    if(NULL == pUploadSetting_)
    {
        pUploadSetting_ = new UploadSettingForm(this->rect(), this);
        connect(pUploadSetting_.data(), SIGNAL(signalDone()), this, SLOT(slotDone()));
        connect(pUploadSetting_, SIGNAL(signalSelectBoardType(QString,QString)), this, SLOT(slotBoardTypeItemClicked(QString,QString)));
        connect(pUploadSetting_, SIGNAL(signalSelectSerial(QString)), this, SLOT(slotSerialItemClicked(QString)));

        pUploadSetting_ ->setAttribute(Qt::WA_DeleteOnClose);
        qDebug() << this->pos();
        pUploadSetting_->show();
    }
}

bool WidgetMain::saveCurrentState()
{
    qDebug() << "话说要保存文件了";
    QString fileSavePath = QFileDialog::getSaveFileName(this, tr("保存文件"), ".", "*.mps");
    if(fileSavePath.isEmpty())
    {
        return false;
    }
    else
    {
        pEditScene_->saveFile(fileSavePath);
        return true;
    }
}

void WidgetMain::clearDustbinData()
{
    pFlowLine_ = NULL;
    startName_ = "";
    endName_ = "";
    groupName_ = "";
}

/**
 * @brief 遍历所有的Block
 * @param dirPath 目录路径
 */
void WidgetMain::scanBlocks(const QString &dirPath, QTreeWidgetItem *parentItem, QMenu *parentMenu)
{
    QDir dir(dirPath);
	DataStruct data;
    {
        dir.setFilter(QDir::Files);

        QStringList tmp;
        foreach (const QString &fileName, dir.entryList())
        {
            QString filePath = dirPath + "/" + fileName;
            //啦拉拉在这里读取数据
            QFileInfo infor(filePath);
            if(0 == infor.size())
            {
                continue;
            }
			data = GetBlockData::getBlockData(filePath);
            Translate::map_fileName_filePath_.insert(infor.baseName(), filePath);
            if(!data.isEmpty())
            {
				hash_blockPath_blockData_.insert(data.ui.name, data);//创建的时候需要的是模块的文件名
				map_moduleName_moduleTag_.insert(data.ui.name, data.ui.tag);//ui.fileName是模块的显示的名字...
				tmp.append(data.ui.name);
            }

            //处理menu相关
            QAction *pAction = parentMenu->addAction(infor.baseName());
            connect(pAction, SIGNAL(triggered()), this, SLOT(slotActionTriggered()));
        }
        map_dirPath_blockNames_.insert(dirPath, tmp);
    }

    {
        dir.setFilter(QDir::Dirs | QDir::NoDotAndDotDot);

        foreach (const QString &dirName, dir.entryList())
        {
            QString childDirPath = dirPath + "/" + dirName;
            //对treeWidget的处理
            QTreeWidgetItem *pChildItem = new QTreeWidgetItem(parentItem, QStringList(QString(dirName)));
            //QTreeWidgetItem *pChildItem = new ListWidget(parentItem, QStringList(QString(dirName)));
            pChildItem->setData(0,Qt::UserRole+1,dirPath);
            pChildItem->setSizeHint(0, QSize(100, 20));
            parentItem->addChild(pChildItem);
            map_treeWidgetItemPointer_pageIndex_.insert(pChildItem, pageIndex_++);

            //memu
            QMenu *pMenu = parentMenu->addMenu(dirName);
            scanBlocks(childDirPath, pChildItem, pMenu);
        }
    }
}

void WidgetMain::createListWidget()
{
    {//创建Advanced面板的listWidget
        QMap<QString, QStringList>::iterator iter;
        int index = 0;
        for(iter = map_dirPath_blockNames_.begin(); iter != map_dirPath_blockNames_.end(); ++iter)
        {
            QString dirPath = iter.key();
            QStringList blocks = iter.value();

			ListWidgetAdvanceBlock *pListWidget = new ListWidgetAdvanceBlock();
			//调整QListView的item的字体大小，使用QSS设置失败，现在使用QFont的方式调整。。
			QFont font = pListWidget->font();
			font.setPixelSize(11);
			pListWidget->setFont(font);

            connect(pListWidget, SIGNAL(signalShowHelp(QString)), SLOT(slotShowHelp(QString)));
            pEditScene_->addListWidgetPointer(pListWidget);
            int tmp = 0;
            foreach (const QString &bbName, blocks)
            {
                QListWidgetItem *pItem = new QListWidgetItem(bbName);

                pItem->setData(Qt::UserRole, tmp++);
                pItem->setData(Qt::UserRole+1, bbName);

                pItem->setSizeHint(QSize(300, 20));
                pListWidget->addItem(pItem);
            }

            stackedWidgetBlockType->insertWidget(index, pListWidget);
            //map_treeWidgetItemPointer_pageIndex_.insert(dirPath, index);
            ++index;
        }
    }
    {//创建Begin面板的listWidget
        //listWidgetBeginner1
        {
            QVector<ListWidgetBeginData> datas;

			datas.append(ListWidgetBeginData("Button" , "Digital Input" , "Button", "./resource/images/BeginnerToolbar/BeginnerToolbar_Button.png"));
			datas.append(ListWidgetBeginData("LED" , "Digital Output" , "LED", "./resource/images/BeginnerToolbar/BeginnerToolbar_LED.png"));
			datas.append(ListWidgetBeginData("Rotation Sensor" , "Analog Input" , "Rotation Sensor", "./resource/images/BeginnerToolbar/BeginnerToolbar_RotationSensor.png"));
			datas.append(ListWidgetBeginData("Servo" , "RC servo motors" , "Servo", "./resource/images/BeginnerToolbar/BeginnerToolbar_Servo.png"));
            datas.append(ListWidgetBeginData("LM35" , "Temperature Sensor" , "LM35", "./resource/images/BeginnerToolbar/BeginnerToolbar_LM35.png"));
			datas.append(ListWidgetBeginData("Speaker" , "or Buzzer" , "Speaker", "./resource/images/BeginnerToolbar/BeginnerToolbar_Speaker.png"));
			datas.append(ListWidgetBeginData("IR Receiver" , "Receie IR signal" , "IR Remote", "./resource/images/BeginnerToolbar/BeginnerToolbar_IRRemote.png"));

            createBeginerList(datas, listWidgetBeginner1);
            pEditScene_->addListWidgetPointer(listWidgetBeginner1);
        }

        {
            QVector<ListWidgetBeginData> datas;

			datas.append(ListWidgetBeginData("Delay" , "wait a second" , "Delay", "./resource/images/BeginnerToolbar/BeginnerToolbar_Delay.png"));
			datas.append(ListWidgetBeginData("Switch" , "trun on, trun off" , "Switch", "./resource/images/BeginnerToolbar/BeginnerToolbar_Switch.png"));
            datas.append(ListWidgetBeginData("IF" , "if...then..." , "IF", "./resource/images/BeginnerToolbar/BeginnerToolbar_Triger.png"));

            createBeginerList(datas, listWidgetBeginner2);
            pEditScene_->addListWidgetPointer(listWidgetBeginner2);
        }
    }
}

void WidgetMain::createBeginerList(const QVector<ListWidgetBeginData> &datas, QListWidget *pListWidget)
{
    for(int i = 0; i != datas.size(); ++i)
    {
        QListWidgetItem *pItem = new QListWidgetItem();
        pItem->setData(ListWidgetItemData::index, i);
        pItem->setData(ListWidgetItemData::blockName, datas.at(i).name);
        pItem->setSizeHint(QSize(44, 38));
        QPixmap pix(datas.at(i).imagePath);
        pix.scaled(44, 38);

        WidgetForListWidgetBegin *pWidget = new WidgetForListWidgetBegin(datas.at(i).text, datas.at(i).type, pix);

        pListWidget->addItem(pItem);
        pListWidget->setItemWidget(pItem, pWidget);
    }
}

void WidgetMain::on_pushButtonAllBlocks_clicked()
{
    AllBlocksForm *p = new AllBlocksForm(this->rect(), this);
    connect(p, SIGNAL(signalShowMindKit()), this, SLOT(slotShowMindKit()));
    connect(p, SIGNAL(signalShowIntroduce(QString)), this, SLOT(slotShowIntroduce(QString)));

    p->setAttribute(Qt::WA_DeleteOnClose);
    p->show();
}

void WidgetMain::slotPressBack()
{
    AffirmForm *p = qobject_cast<AffirmForm *>(sender());
    if(p)
    {
        p->close();
    }
}

void WidgetMain::slotPressNotSave()
{
    if(PRESSED_CLOSE == affirmType_ )
    {
        this->close();
    }
    else if(PRESSED_NEW_PROJECT == affirmType_ )
    {
        pEditScene_->setReset();
        AffirmForm *p = qobject_cast<AffirmForm *>(sender());
        if(p)
        {
            p->close();
        }
    }
}

void WidgetMain::slotPressSave()
{
    if(saveCurrentState())
    {
        if(PRESSED_CLOSE == affirmType_ )
        {
            this->close();
        }
        else if(PRESSED_NEW_PROJECT == affirmType_ )
        {
            pEditScene_->setReset();
            AffirmForm *p = qobject_cast<AffirmForm *>(sender());
            if(p)
            {
                p->close();
            }
        }
    }
    else
    {
        pEditScene_->setReset();
        AffirmForm *p = qobject_cast<AffirmForm *>(sender());
        if(p)
        {
            p->close();
        }
    }
}

void WidgetMain::slotPressSerialSetting()
{
    qDebug() << "按下选中串口";
    createUploadSetting();
}

/**
 * @brief 显示垃圾箱
 */
void WidgetMain::slotShowDustbin()
{
    qDebug() << "call in fadeIn show?????????????????????????? " <<bDustbinShow_;
    if(!bDustbinShow_)
    {
        qDebug() << "fadeIn";
        Animation::opacityAnimation(pDustbin_, 100, 0, 1);
        Animation::posAnimation(pDustbin_, 100, QPoint(width() - 27, 27+5), QPoint(width() - 40, 27+5));
        bDustbinShow_ = true;
    }
}

/**
 * @brief 隐藏垃圾箱
 */
void WidgetMain::slotHideDusbin()
{
    qDebug() << "call in fadeOut show?????????????????????????? " <<bDustbinShow_;
    if(bDustbinShow_)
    {
        qDebug() << "fadeOut";
        Animation::opacityAnimation(pDustbin_, 100, 1, 0);
        Animation::posAnimation(pDustbin_, 100, QPoint(width() - 27, 27+5), QPoint(width() - 40, 27+5));
        bDustbinShow_ = false;
    }
}

void WidgetMain::slotFocusInLine(FlowLine *p, const QString &startName, const QString &endName)
{
    pFlowLine_ = p;
    startName_ = startName;
    endName_ = endName;
    type_ = FOCUS_LINE;
    //然后在这里调出
    //slotShowDustbin();
    pDustbin_->show();
    pDustbin_->move(width() - 40, 40);
}

void WidgetMain::slotFocusInGroup(const QString &name)
{
    qDebug() << "你妹的这里就丢了数据? " <<name;
    groupName_ = name;
    type_ = FOCUS_GROUP;
    //然后在这里调出, 我需要一个通用的淡入淡出的方法
    qDebug() << "应该显示了";
    pDustbin_->move(width() - 40, 40);
    pDustbin_->show();
}

void WidgetMain::slotFocusOut()
{
    qDebug() << "应该隐藏了";
    pDustbin_->hide();
}

void WidgetMain::slotCurrentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    if (!current)
    {
        current = previous;
    }
    else
    {
        //处理其他
        for(int i = 0; i != listWidgetMenu->count(); ++i)
        {
            QWidget *pOther = listWidgetMenu->itemWidget(listWidgetMenu->item(i));
            BlockMenuWidget *pOtherWidget = static_cast<BlockMenuWidget *>(pOther);
            if(pOtherWidget)
            {
                pOtherWidget->setImageState(NORMAL);
            }
        }

        QWidget *p = listWidgetMenu->itemWidget(current);
        BlockMenuWidget *pWidget = static_cast<BlockMenuWidget *>(p);
        if(pWidget)
        {
            pWidget->setImageState(PRESSED);
        }
    }

    int index = listWidgetMenu->row(current);
    stackedWidget->setCurrentIndex(index);
    if(0 == index)
    {
        splitter->setSizes(QList<int>() << 181 << width()-181);
    }
    else if(1 == index)
    {
        splitter->setSizes(QList<int>() << 250 << width()-250);
    }
    else
    {
        qDebug() << "切换页面的时候脑残了!" << index;
    }
}

void WidgetMain::slotShowHelp(const QString &blockName)
{
    if(hash_blockPath_blockData_.contains(blockName))
    {
		//textEditIntroduce->setHtml(hash_blockPath_blockData_.value(blockName).description.text);
		textEditIntroduce->setPlainText(hash_blockPath_blockData_.value(blockName).description.text);
    }
    else
    {
        qDebug() << "要显示帮助的时候找不到对应的模块!";
	}
}

void WidgetMain::slotViewOffset(const QPoint offset)
{
	if(offset.x() > -120
			&& offset.y() > -300)
	{//在中间范围内
		qDebug() << "在中间范围内" << offset;
		//if(pBackStart_->opacity() > 0)
		pBackStart_->hide();
	}
	else
	{
		qDebug() << "不在范围内" << offset;
		//if(pBackStart_->opacity() < 1)
		if(offset.x() < -120
						&& offset.y() < -250)
		{
			qDebug() << "左上角： " <<splitter->sizes().at(0)+10 << widgetTitle->height()+widgetMenu->height()+15;
			pBackStart_->move(splitter->sizes().at(0)+10, widgetTitle->height()+widgetMenu->height()+15);
		}
		else if(offset.x() < -120
				&& offset.y() >-250)
		{//贴左边 x不变,y变
			int y = widgetTitle->height()+widgetMenu->height()+10+255;
			qDebug() << "贴左边： " <<splitter->sizes().at(0)+10 << y+offset.y();
			pBackStart_->move(splitter->sizes().at(0)+10, y+offset.y());
		}
		else if(offset.x() > -120
				&& offset.y() <-250)
		{//贴上面
			qDebug() << "贴上面" << splitter->sizes().at(0)+10<< widgetTitle->height()+widgetMenu->height()+15;
			pBackStart_->move(splitter->sizes().at(0)+10, widgetTitle->height()+widgetMenu->height()+15);
		}
		//pBackStart_->move(500, 500);
		qDebug() <<  pBackStart_->size();
		pBackStart_->raise();
		pBackStart_->show();
	}
}

void WidgetMain::slotActionTriggered()
{
    QAction *pAction = static_cast<QAction *>(sender());
    if(!pAction)
    {
        qDebug() << "pAction is null!";
        return;
    }
    QString bbName = pAction->text();
    if(!bbName.isEmpty())
    {
        emit signalCreateGroup(bbName);
	}
}

void WidgetMain::slotCreateSerialTool()
{
	if(NULL == pSerialPortTool_)
	{
		pSerialPortTool_ = new SerialPortToolForm();
		connect(pSerialPortTool_, SIGNAL(destroyed()), this, SLOT(slotSerialToolClose()));
		pSerialPortTool_->setWindowTitle(tr("Serial Monitor"));
		pSerialPortTool_->setAttribute(Qt::WA_DeleteOnClose);
	}
	pSerialPortTool_->raise();
	pSerialPortTool_->show();
}

void WidgetMain::slotSerialToolClose()
{
	pSerialPortTool_ = NULL;
}

void WidgetMain::on_treeWidget_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous)
{
    if(!current)
    {
        current = previous;
    }
    //QString dirPath = current->data(0, Qt::UserRole+1).toString();
    if(!map_treeWidgetItemPointer_pageIndex_.contains(current))
    {
        qDebug() << "不包含对应的地址" << current;
        return;
    }
    stackedWidgetBlockType->setCurrentIndex(map_treeWidgetItemPointer_pageIndex_.value(current));
    qDebug() << map_treeWidgetItemPointer_pageIndex_.value(current);
    pListWidget_ = static_cast<ListWidgetAdvanceBlock*>(stackedWidgetBlockType->currentWidget());
}

void WidgetMain::on_pushButtonMemu_clicked()
{
    pAllBlockMenu_->show();
}

void WidgetMain::on_pushButtonUpward_clicked()
{
    if(NULL != pListWidget_)
    {
        pListWidget_->verticalScrollBar()->setValue(pListWidget_->verticalScrollBar()->value()-1);
    }
}

void WidgetMain::on_pushButtonDownward_clicked()
{
    if(NULL != pListWidget_)
    {
        pListWidget_->verticalScrollBar()->setValue(pListWidget_->verticalScrollBar()->value()+1);
    }
}
