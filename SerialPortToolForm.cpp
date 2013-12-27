#include "SerialPortToolForm.h"

#include <QDebug>
#include <QMessageBox>
#include <QTextCursor>
#include <QSet>
#include <QRegExp>
#include <QThread>

#include "SerialDataThread.h"

SerialPortToolForm::SerialPortToolForm(QWidget *parent)
	: QWidget(parent)
	, baud_("")
	, port_("")
	, bLineWrap_(false)
	, bMindWrap_(false)
	, pSerialPort_(NULL)
	, buffer_("")
{
	setupUi(this);
	initData();
}

void SerialPortToolForm::closePort()
{
	if(pSerialPort_->isOpen())
	{
		pSerialPort_->close();
	}
}

void SerialPortToolForm::changeEvent(QEvent *e)
{
	QWidget::changeEvent(e);
	switch (e->type()) {
		case QEvent::LanguageChange:
			retranslateUi(this);
			break;
		default:
			break;
	}
}

void SerialPortToolForm::showEvent(QShowEvent *)
{
	comboBoxBaud->setCurrentIndex(3);
}

void SerialPortToolForm::initData()
{
	{
		map_int_baud_[110] = BAUD110;
		map_int_baud_[300] = BAUD300;
		map_int_baud_[600] = BAUD600;
		map_int_baud_[1200] = BAUD1200;
		map_int_baud_[2400] = BAUD2400;
		map_int_baud_[4800] = BAUD4800;
		map_int_baud_[9600] = BAUD9600;
		map_int_baud_[19200] = BAUD19200;
		map_int_baud_[38400] = BAUD38400;
		map_int_baud_[57600] = BAUD57600;
		map_int_baud_[115200] = BAUD115200;
		map_int_baud_[128000] = BAUD128000;
		map_int_baud_[250000] = BAUD250000;
		map_int_baud_[256000] = BAUD256000;
	}

	textEditRead->setReadOnly(true);
	QList<QextPortInfo> ports = QextSerialEnumerator::getPorts();
	qDebug() << "没有货？？？" << ports.size();
	foreach (QextPortInfo port, ports)
	{
		comboBoxPort->addItem(port.portName);
	}
	pSerialPort_ = new QextSerialPort(QextSerialPort::EventDriven, this);
	QThread *pThread = new QThread();

	pSerialDataThread_ = new SerialDataThread(pSerialPort_, textEditRead, this);
	pSerialDataThread_->moveToThread(pThread);
	connect(pSerialPort_, SIGNAL(readyRead()), pSerialDataThread_, SLOT(slotReadyRead()), Qt::QueuedConnection);

	pThread->start();
}

void SerialPortToolForm::on_pushButtonSend_clicked()
{
	pSerialPort_->write(textEditSend->toPlainText().toLatin1());
}

void SerialPortToolForm::on_checkBoxMind_clicked(bool checked)
{
	bMindWrap_ = checked;
	pSerialDataThread_ ->setMindWrap(bMindWrap_);
}

void SerialPortToolForm::on_comboBoxBaud_currentTextChanged(const QString &arg1)
{
	Q_UNUSED(arg1);
	if(pSerialPort_->isOpen())
	{
		pSerialPort_->close();
	}
	//baud_ = arg1;
	pSerialPort_->setBaudRate(map_int_baud_.value(baud_.toInt()));
	pSerialPort_->setPortName(comboBoxPort->currentText());
	pSerialPort_->open(QIODevice::ReadWrite);
	if(!pSerialPort_->isOpen())
	{
		qDebug() << "不能打开什么情况" << pSerialPort_->errorString();
		QMessageBox::warning(this, tr("错误"), pSerialPort_->errorString());
	}
}

void SerialPortToolForm::on_comboBoxPort_currentIndexChanged(const QString &arg1)
{
	////
	Q_UNUSED(arg1);
	if(pSerialPort_)
	{
		on_comboBoxBaud_currentTextChanged("");
	}
}
