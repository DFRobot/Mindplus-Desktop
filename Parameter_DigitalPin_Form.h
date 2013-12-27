#ifndef PARAMETER_DIGITALPIN_FORM_H
#define PARAMETER_DIGITALPIN_FORM_H

#include "ui_Parameter_DigitalPin_Form.h"

class Parameter_DigitalPin_Form : public QWidget, private Ui::Parameter_DigitalPin_Form
{
	Q_OBJECT

public:
	explicit Parameter_DigitalPin_Form(const QRect rect, QWidget *parent = 0);
	void setValue(const QString &value);

signals:
	void signalValue(const QString &value);

protected:
	void changeEvent(QEvent *e);
	void paintEvent(QPaintEvent *);
	//void keyPressEvent(QKeyEvent *event);
	bool eventFilter(QObject *target, QEvent *event);
	void showEvent(QShowEvent *event);

private slots:
	void on_pushButton_clicked();
	void slotTextEdited(const QString &value);

	void on_DigitalPin_0_clicked();

	void on_DigitalPin_1_clicked();

	void on_DigitalPin_2_clicked();

	void on_DigitalPin_3_clicked();

	void on_DigitalPin_4_clicked();

	void on_DigitalPin_5_clicked();

	void on_DigitalPin_6_clicked();

	void on_DigitalPin_7_clicked();

	void on_DigitalPin_8_clicked();

	void on_DigitalPin_9_clicked();

	void on_DigitalPin_10_clicked();

	void on_DigitalPin_11_clicked();

	void on_DigitalPin_12_clicked();

	void on_DigitalPin_13_clicked();

	void on_pushButtonMindkit_clicked();

private:
	void initSetting();
	void initGui();

private:
	QString value_;
	int callCount_;
	QRect rect_;
};

#endif // PARAMETER_DIGITALPIN_FORM_H
