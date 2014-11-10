#ifndef PARAMETER_ANALOGPIN_FORM_H
#define PARAMETER_ANALOGPIN_FORM_H

#include "ui_Parameter_AnalogPin_Form.h"

class Parameter_AnalogPin_Form : public QWidget, private Ui::Parameter_AnalogPin_Form
{
    Q_OBJECT

public:
    explicit Parameter_AnalogPin_Form(const QRect rect, QWidget *parent = 0);
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

    void on_AnalogPin_0_clicked();

    void on_AnalogPin_1_clicked();

    void on_AnalogPin_2_clicked();

    void on_AnalogPin_3_clicked();

    void on_AnalogPin_4_clicked();

    void on_AnalogPin_5_clicked();

	void on_pushButtonMindkit_clicked();

private:
    void initSetting();
    void initGui();

private:
    QString value_;
    int callCount_;
    QRect rect_;
};

#endif // PARAMETER_ANALOGPIN_FORM_H
