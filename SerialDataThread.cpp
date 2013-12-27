#include "SerialDataThread.h"

#include <QDebug>
#include <QRegExp>
#include <QStringList>
#include <QSet>

#include "QExtserialport/qextserialport.h"

SerialDataThread::SerialDataThread(QextSerialPort *pSerial, QTextEdit *pTextEdit, QObject *parent)
	: QObject(parent)
	, pSerialPort_(pSerial)
	, pTextEditRead_(pTextEdit)
	, buffer_("")
	, bMindWrap_(false)
{
}

void SerialDataThread::setMindWrap(bool b)
{
	bMindWrap_ = b;
}

void SerialDataThread::slotReadyRead()
{
	buffer_ += pSerialPort_->readAll();
	if(bMindWrap_)
	{
		QSet<QString> sets = getAllMatchResults(buffer_, R"(<[\s\w]*>[\s \w]*;)");//原生字符串真好用..

		if(!sets.isEmpty())
		{
			for(int i = 0;  i != sets.size(); ++i)
			{
				pTextEditRead_->append(sets.toList().at(i));
			}
			buffer_.clear();
		}
	}
	else
	{
		if(buffer_ != "\n")
		{
			pTextEditRead_->setText(pTextEditRead_->toPlainText()+buffer_);
			buffer_.clear();
		}
	}
}

QSet<QString> SerialDataThread::getAllMatchResults(const QString text, const QString regexp)
{
	QSet<QString> resultSet;
	QRegExp rx(regexp);
	int pos = 0;
	while ((pos = rx.indexIn(text, pos)) != -1)
	{
		pos += rx.matchedLength();
		QString result = rx.cap(0);
		resultSet << result;
	}
	return resultSet;
}
