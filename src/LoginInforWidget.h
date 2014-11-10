#ifndef LOGININFORWIDGET_H
#define LOGININFORWIDGET_H

#include "ui_LoginInforWidget.h"

class LoginInforWidget : public QWidget, private Ui::LoginInforWidget
{
    Q_OBJECT

public:
    explicit LoginInforWidget(QWidget *parent = 0);

protected:
    void changeEvent(QEvent *e);
    void paintEvent(QPaintEvent *event);
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);
};

#endif // LOGININFORWIDGET_H
