#ifndef PARAMETER_TIME_FORM_H
#define PARAMETER_TIME_FORM_H

#include "ui_Parameter_Time_Form.h"

class Parameter_Time_Form : public QWidget, private Ui::Parameter_Time_Form
{
    Q_OBJECT

public:
    explicit Parameter_Time_Form(const QRect rect, QWidget *parent = 0);
    void setValue(const QString &value);

signals:
    void signalValueChange(const QString &value);

protected:
    void changeEvent(QEvent *e);
    void paintEvent(QPaintEvent *);
    bool eventFilter(QObject *target, QEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void showEvent(QShowEvent *event);

private slots:
    void on_pushButton_clicked();

private:
    void initSetting();
    void initGui();

    void changeValue();

private:
    float min_;
    int sec_;
    int msec_;
    QPoint offset_;
    QWidget *pParent_;
    QRect rect_;
};

#endif // PARAMETER_TIME_FORM_H
