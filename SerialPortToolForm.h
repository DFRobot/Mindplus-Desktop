#ifndef SERIALPORTTOOLFORM_H
#define SERIALPORTTOOLFORM_H

#include "ui_SerialPortToolForm.h"

#include "QExtserialport/qextserialport.h"
#include "QExtserialport/qextserialenumerator.h"

class SerialDataThread;

class SerialPortToolForm : public QWidget, private Ui::SerialPortToolForm
{
	Q_OBJECT
	
public:
	explicit SerialPortToolForm(QWidget *parent = 0);
	void closePort();

protected:
	void changeEvent(QEvent *e);
	void showEvent(QShowEvent *);

private slots:
	void on_pushButtonSend_clicked();
	void on_checkBoxMind_clicked(bool checked);
	void on_comboBoxBaud_currentTextChanged(const QString &arg1);
	void on_comboBoxPort_currentIndexChanged(const QString &arg1);

private:
	void initData();
	void resetBaudRate(void);

private:
	QString baud_;
	QString port_;
	bool bLineWrap_;
	bool bMindWrap_;
	QextSerialPort *pSerialPort_;
	QString buffer_;
	SerialDataThread *pSerialDataThread_;
};

#endif // SERIALPORTTOOLFORM_H
