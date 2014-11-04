#ifndef UPLOADPARAMETERWIDGET_H
#define UPLOADPARAMETERWIDGET_H

#include "ui_UploadParameterWidget.h"

class UploadParameterWidget : public QWidget, private Ui::UploadParameterWidget
{
    Q_OBJECT

public:
    explicit UploadParameterWidget(QWidget *parent = 0);
    void setUploadParameter(const QString & type, const QString &serial);
    QString getBoard() const;
    QString getSerial() const;

protected:
    void changeEvent(QEvent *e);
    void paintEvent(QPaintEvent *event);
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
};

#endif // UPLOADPARAMETERWIDGET_H
