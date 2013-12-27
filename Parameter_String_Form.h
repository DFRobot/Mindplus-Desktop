#ifndef Parameter_String_Form_H
#define Parameter_String_Form_H

#include "ui_Parameter_String_Form.h"

class Parameter_String_Form : public QWidget, private Ui::Parameter_String_Form
{
    Q_OBJECT

public:
    explicit Parameter_String_Form(const QRect rect, QWidget *parent = 0);
    void setValue(const QString &value);

signals:
    void signalValue(const QString &value);

protected:
    void changeEvent(QEvent *e);
    void paintEvent(QPaintEvent *);
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
    QPoint offset_;
    QWidget *pParent_;
    QRect rect_;
};

#endif // Parameter_String_Form_H
