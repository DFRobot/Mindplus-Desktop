#ifndef PARAMETER_OPERATOR_FORM_H
#define PARAMETER_OPERATOR_FORM_H

#include "ui_Parameter_operator_Form.h"

class Parameter_operator_Form : public QWidget, private Ui::Parameter_operator_Form
{
    Q_OBJECT

public:
    explicit Parameter_operator_Form(const QRect rect, QWidget *parent = 0);
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
    //void on_pushButton_clicked();
    //void slotTextEdited(const QString &value);

    void on_operator_0_clicked();
    void on_operator_1_clicked();
    void on_operator_2_clicked();
    void on_operator_3_clicked();
    void on_operator_4_clicked();
    void on_operator_5_clicked();

private:
    void initSetting();
    void initGui();

private:
    QString value_;
    int callCount_;
    QRect rect_;
};

#endif // PARAMETER_OPERATOR_FORM_H
