#include "UploadSettingForm.h"

#include <QVariant>
#include <QDebug>
#include <QTimer>
#include <QEasingCurve>
#include <QPainter>
#include <QMouseEvent>
#include <QListView>

#include "QExtserialport/qextserialenumerator.h"

#include "Animation.h"
#include "ListWidgetItemWidget_UploadSetting.h"

//以后其他动画的移动编号添加在这里
const int ANI_BOARD_TYPE = 0;
const int ANI_SERIAL_PORT = 1;
const int  ANI_CLASSICS = 2;
const int  ANI_POWERFUL = 3;
const int  ANI_DONE = 4;

UploadSettingForm::UploadSettingForm(const QRect &rect, QWidget *parent)
    : QWidget(parent)
    , pParent_(parent)
    , rect_(rect)
{
    setupUi(this);
	initSetting();
	initData();
	initGui();
}

void UploadSettingForm::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
	switch (e->type())
	{
        case QEvent::LanguageChange:
            retranslateUi(this);
            break;
        default:
            break;
    }
}

void UploadSettingForm::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void UploadSettingForm::timerEvent(QTimerEvent *event)
{
	Q_UNUSED(event);
	if(!currentSerialPort_.isEmpty()
			&& !currentBoard_.isEmpty())
	{
		qDebug() << "显示啊";
		pushButtonUpload->show();
	}
	else
	{
		pushButtonUpload->hide();
	}

	if(serialPortsSet_ == getSerialPorts().toSet())
	{
		return;
	}

	serialPortsSet_ = getSerialPorts().toSet();
	if(0 == serialPortsSet_.size())
	{
		currentSerialPort_ = "";
		Q_EMIT signalSelectSerial("");
	}
	else if(currentSerialPort_.isEmpty())
	{
		currentSerialPort_ = serialPortsSet_.toList().at(0);
		Q_EMIT signalSelectSerial(currentSerialPort_);
	}
	else if(!currentSerialPort_.isEmpty()
			&& currentSerialPort_ != serialPortsSet_.toList().at(0))
	{
		currentSerialPort_ = serialPortsSet_.toList().at(0);
		Q_EMIT signalSelectSerial(currentSerialPort_);
	}
	comboBoxSerialPort->clear();
	comboBoxSerialPort->addItems(serialPortsSet_.toList());
}

void UploadSettingForm::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        QWidget *pParent_ = static_cast<QWidget *>(this->parent());
        if(NULL == pParent_)
        {
            return;
        }
        offset_ = event->globalPos() - pParent_->frameGeometry().topLeft();
    }
}

void UploadSettingForm::mouseMoveEvent(QMouseEvent *event)
{
    if (!(event->buttons() & Qt::LeftButton))
    {
        return;
    }
    if ((event->pos() - offset_).manhattanLength()
            < QApplication::startDragDistance())
    {
        return;
    }
    pParent_->move(event->globalPos() - offset_);
}

void UploadSettingForm::showEvent(QShowEvent *event)
{
    setGeometry(rect_);
}

void UploadSettingForm::keyPressEvent(QKeyEvent *event)
{
    if(Qt::Key_Enter == event->key()
            || Qt::Key_Return == event->key())
    {
		on_pushButtonUpload_clicked();
    }
}

void UploadSettingForm::initSetting()
{
    setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground, true);
}

void UploadSettingForm::initData()
{
    this->setFocus();

	pushButtonUpload->hide();
	startTimer(300);

//    map_name_index_["Arduino Uno"] = 0;
//    map_name_index_["Arduino Duemilanove (328)"] = 1;
//    map_name_index_["Arduino Duemilanove (168)"] = 2;
//    map_name_index_["Arduino Nano (328)"] = 3;
//    map_name_index_["Arduino Nano (168)"] = 4;
//    map_name_index_["Arduino Mega 2560(ADK)"] = 5;
//    map_name_index_["Arduino Mega 1280"] = 6;
//    map_name_index_["Arduino Leonardo"] = 7;
//    map_name_index_["Arduino Esplora"] = 8;
//    map_name_index_["Arduino Micro"] = 9;
//    map_name_index_["Arduino Mini (328)"] = 10;
//    map_name_index_["Arduino Mini (168)"] = 11;
//    map_name_index_["Arduino Ethernet"] = 12;
//    map_name_index_["Arduino Fio"] = 13;
//    map_name_index_["Arduino BT (328)"] = 14;
//    map_name_index_["Arduino BT (168)"] = 15;
//    map_name_index_["LilyPad Arduino USB"] = 16;
//    map_name_index_["LilyPad Arduino (328)"] = 17;
//    map_name_index_["LilyPad Arduino (168)"] = 18;
//    map_name_index_["Arduino Pro Mini (328)"] = 19;
//    map_name_index_["Arduino Pro Mini (168)"] = 20;
//    map_name_index_["Arduino Pro Mini (328) 3.3V"] = 21;
//    map_name_index_["Arduino Pro Mini (168) 3.3V"] = 22;
//    map_name_index_["Arduino NG or older"] = 23;
//    map_name_index_["Arduino Mega 8"] = 24;

	{
		map_name_index_["Arduino Uno"] = 0;
		map_name_index_["Arduino Duemilanove ATmega328"] = 1;
		map_name_index_["Arduino Duemilanove ATmega168"] = 2;
		map_name_index_["Arduino Nano ATmega328"] = 3;
		map_name_index_["Arduino Nano ATmega168"] = 4;
		map_name_index_["Arduino Mega 2560 or Mega ADK"] = 5;
		map_name_index_["Arduino Mega (ATmega1280)"] = 6;
		map_name_index_["Arduino Leonardo"] = 7;
		map_name_index_["Arduino Esplora"] = 8;
		map_name_index_["Arduino Micro"] = 9;
		map_name_index_["Arduino Mini ATmega328"] = 10;
		map_name_index_["Arduino Mini ATmega168"] = 11;
		map_name_index_["Arduino Ethernet"] = 12;
		map_name_index_["Arduino Fio"] = 13;
		map_name_index_["Arduino BT ATmega328"] = 14;
		map_name_index_["Arduino BT ATmega168"] = 15;
		map_name_index_["LilyPad Arduino USB"] = 16;
		map_name_index_["LilyPad Arduino ATmega328"] = 17;
		map_name_index_["LilyPad Arduino ATmega168"] = 18;
		map_name_index_["Arduino Pro Mini (5V,16 MHz)  ATmega328"] = 19;
		map_name_index_["Arduino Pro Mini (5V,16 MHz)  ATmega168"] = 20;
		map_name_index_["Arduino Pro Mini (3.3V,8 MHz) ATmega328"] = 21;
		map_name_index_["Arduino Pro Mini (3.3V,8 MHz) ATmega168"] = 22;
		map_name_index_["Arduino NG or older ATmega168"] = 23;
		map_name_index_["Arduino NG or older ATmega8"] = 24;

//		map_name_index_["Arduino Robot Control"] = 25;
//		map_name_index_["Arduino Robot Motor"] = 26;
//		map_name_index_["Flyduino"] = 27;
//		map_name_index_["X-Board"] = 28;
//		map_name_index_["X-Board V2"] = 29;
		map_name_index_["RoMeo"] = 0;
		map_name_index_["RoMeo V2"] = 7;
	}
	connect(comboBoxBoard, SIGNAL(activated(QString)), this, SLOT(slotBoardActivated(QString)));
	connect(comboBoxSerialPort, SIGNAL(activated(QString)), this, SLOT(slotSerialPortActivated(QString)));
	comboBoxSerialPort->addItems(getSerialPorts());
}

void UploadSettingForm::initGui()
{
    this->move(1, 1);
	countAnimationIndex_ = 0;
}

QStringList UploadSettingForm::getSerialPorts()
{
	QStringList serialPorts;
	QList<QextPortInfo> ports = QextSerialEnumerator::getPorts();
	foreach (QextPortInfo port, ports)
	{
#ifdef Q_OS_MAC
		if(!port.portName.contains(".usbmodem"))
		{
			continue;
		}
#endif
		//ListWidgetItemWidget_UploadSetting *p1 = new ListWidgetItemWidget_UploadSetting(port.portName+"_"+port.friendName, listWidgetSerial);
		//comboBoxSerialPort->addItem(port.portName+"_"+port.friendName);
		serialPorts << port.portName;
//		qDebug() << "enumName:" << port.enumName <<"friendName:" <<port.friendName <<
//					"physName:" << port.physName << "portName:" << port.portName <<
//					"productID:" <<port.productID <<"vendorID:" <<port.vendorID;
	}

	return serialPorts;
}

void UploadSettingForm::on_pushButtonUpload_clicked()
{
	if(currentSerialPort_.isEmpty()
			&& comboBoxSerialPort->count() != 0)
	{
		Q_EMIT signalSelectSerial(comboBoxSerialPort->itemText(0));
	}
	emit signalDone();
	this->close();
}

void UploadSettingForm::on_pushButtonBack_clicked()
{
	close();
}

void UploadSettingForm::slotBoardActivated(const QString &str)
{
	if(!map_name_index_.contains(str))
	{
		qDebug() << "can't find :" << str;
		return;
	}
	int index = map_name_index_.value(str);
	qDebug() << "borad index :" << index;
	currentBoard_ = str;
	Q_EMIT signalSelectBoardType(str, QString::number(index));
}

void UploadSettingForm::slotSerialPortActivated(const QString &str)
{
	//currentBoard_ = str;
	qDebug() << "选择串口";
	currentSerialPort_ = str;
	Q_EMIT signalSelectSerial(str);
}

void UploadSettingForm::on_pushButtonUno_clicked()
{
	currentBoard_ = "Arduino Uno";
	Q_EMIT signalSelectBoardType(currentBoard_, QString::number(0));
	comboBoxBoard->setCurrentIndex(1);
	if(!currentSerialPort_.isEmpty())
	{
		on_pushButtonUpload_clicked();
	}
}

void UploadSettingForm::on_pushButtonLeonardo_clicked()
{
	currentBoard_ = "Arduino Leonardo";
	Q_EMIT signalSelectBoardType(currentBoard_, QString::number(7));
	comboBoxBoard->setCurrentIndex(2);
	if(!currentSerialPort_.isEmpty())
	{
		on_pushButtonUpload_clicked();
	}
}
