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
	resetBaudRate();
}

void SerialPortToolForm::initData()
{
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

void SerialPortToolForm::on_comboBoxBaud_currentTextChanged(const QString &_baud)
{
	if(pSerialPort_->isOpen())
	{
		pSerialPort_->close();
	}
	/* As baud value is same a combo box value, directly reusing it.
	 * TODO: platform specific only baud values to be addded.
	 */
	BaudRateType baud = static_cast<BaudRateType>(_baud.toInt());
	pSerialPort_->setBaudRate(baud);
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
		resetBaudRate();
	}
}

/*
 * reset baud value to default [9600]
 */
void SerialPortToolForm::resetBaudRate(void)
{
	comboBoxBaud->setCurrentIndex(3);
}
