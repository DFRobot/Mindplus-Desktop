#ifndef SERIALDATATHREAD_H
#define SERIALDATATHREAD_H

#include <QObject>
#include <QTextEdit>
class QextSerialPort;
class SerialPortToolForm;
class SerialDataThread;

class SerialDataThread : public QObject
{
	Q_OBJECT
public:
	explicit SerialDataThread(QextSerialPort *pSerial, QTextEdit *pTextEdit, QObject *parent = 0);
	void setMindWrap(bool b);

signals:
	
public slots:
	void slotReadyRead();

private:
	QSet<QString> getAllMatchResults(const QString text, const QString regexp);

private:
	QextSerialPort *pSerialPort_;
	QTextEdit *pTextEditRead_;
	QString buffer_;
	bool bMindWrap_;
};

#endif // SERIALDATATHREAD_H
