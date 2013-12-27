#ifndef PARAMETER_INTEGER_FORM_H
#define PARAMETER_INTEGER_FORM_H

#include "ui_Parameter_Integer_Form.h"

class Parameter_Integer_Form : public QWidget, private Ui::Parameter_Integer_Form
{
    Q_OBJECT

public:
    explicit Parameter_Integer_Form(const QRect rect, QWidget *parent = 0);
    void setValue(const QString &value);

signals:
    void signalValue(const QString &value);

protected:
    void changeEvent(QEvent *e);
    void paintEvent(QPaintEvent *);
    //void keyPressEvent(QKeyEvent *event);
    bool eventFilter(QObject *target, QEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void showEvent(QShowEvent *event);

private slots:
    void on_pushButton_clicked();
    void slotTextEdited(const QString &value);

private:
    void initSetting();
    void initGui();

private:
    QString value_;
    int callCount_;

    QPoint offset_;
    QWidget *pParent_;
    QRect rect_;
};

#endif // PARAMETER_INTEGER_FORM_H
