#ifndef PARAMETER_CURVEPROGRESSION_FORM_H
#define PARAMETER_CURVEPROGRESSION_FORM_H

#include "ui_Parameter_CurveProgression_Form.h"
#include <QLabel>

class Parameter_CurveProgression_Form : public QWidget, private Ui::Parameter_CurveProgression_Form
{
    Q_OBJECT

public:
    explicit Parameter_CurveProgression_Form(const QRect rect, QWidget *parent = 0);
    void setValue(const QString &value);

signals:
    void signalValue(const QString &value);
    void signalValueChange(const QString &value);
    void signalPressCtrlPoint();

protected:
    void changeEvent(QEvent *e);
    void paintEvent(QPaintEvent *);
    //void keyPressEvent(QKeyEvent *event);
    bool eventFilter(QObject *target, QEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *);
    void showEvent(QShowEvent *event);

private slots:
    void on_pushButton_clicked();
    void on_currentPosX_valueChanged(double arg1);
    void on_currentPosY_valueChanged(double arg1);

	void slotPressCtrlPoint();
	void slotReleaseCtrlPoint();

private:
    void initSetting();
    void initGui();
   // void SetLED();

private:
    QString value_;
    int callCount_;
    int mouse_press_;
    int mouse_posX_;
    int mouse_posY_;

    QList<QPushButton *> pointCtrlList_;
    QPushButton *currentCtrlPoint_;
    int holdCtrlPoint_;

    QPoint offset_;
    QWidget *pParent_;
    QRect rect_;
};

#endif // PARAMETER_CURVEPROGRESSION_FORM_H
