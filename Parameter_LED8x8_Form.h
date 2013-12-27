#ifndef PARAMETER_LED8X8_FORM_H
#define PARAMETER_LED8X8_FORM_H

#include "ui_Parameter_LED8x8_Form.h"

class Parameter_LED8x8_Form : public QWidget, private Ui::Parameter_LED8x8_Form
{
    Q_OBJECT

public:
    explicit Parameter_LED8x8_Form(const QRect rect, QWidget *parent = 0);
    void setValue(const QString &value);

signals:
    void signalValue(const QString &value);
    void signalValueChange(const QString &value);

protected:
    void changeEvent(QEvent *e);
    void paintEvent(QPaintEvent *);
    //void keyPressEvent(QKeyEvent *event);
    bool eventFilter(QObject *target, QEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void showEvent(QShowEvent *event);

private slots:
    void on_pushButton_clicked();
    //void slotChangeLED();
    //void slotHoldLED();
    //void slotTextEdited(const QString &value);

private:
    void initSetting();
    void initGui();
    void SetLED();

private:
    QString value_;
    int callCount_;
    int ledState_[64];
    int mouse_press_;
    int mouse_posX_;
    int mouse_posY_;
    QList<QLabel *> LEDsList_;

    QPoint offset_;
    QWidget *pParent_;
    QRect rect_;
};

#endif // PARAMETER_LED8x8_FORM_H
