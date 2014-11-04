#ifndef ALLBLOCKSFORM_H
#define ALLBLOCKSFORM_H

#include "ui_AllBlocksForm.h"
#ifdef Q_OS_WIN32
#include <windows.h>
#include <windowsx.h>
#endif
const int VALUE_DIS = 600;

class AllBlocksForm : public QWidget, private Ui::AllBlocksForm
{
    Q_OBJECT

public:
    explicit AllBlocksForm(const QRect &rect, QWidget *parent = 0);
    enum {Digital, Analog, Time, Servo, Flow, MindKit, Serial,
          Adv, Convert, Bluetooth, Moto, Math, Interrupts, Storager, Ethernet
          , LCD, I2C, UserBB, Unkown};

    //这部分最终要集成到WidgetBase里面

    enum
    {
        LEFT,
        RIGHT,
        TOP,
        BOTTOM,
        LEFTTOP,
        RIGHTTOP,
        LEFTBOTTOM,
        RIGHTBOTTOM
    };

signals:
    void signalShowMindKit();
    void signalShowIntroduce(const QString &type);

protected:
    void changeEvent(QEvent *e);
    void showEvent(QShowEvent *event);
    void resizeEvent(QResizeEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
//    void mouseReleaseEvent(QMouseEvent *event);

private slots:
    void on_pushButtonReturn_clicked();

    void on_pushButtonMindKit_clicked();
    void on_pushButtonDigital_clicked();
    void on_pushButtonAnalog_clicked();
    void on_pushButtonTime_clicked();
    void on_pushButtonServo_clicked();
    void on_pushButtonFlow_clicked();
    void on_pushButtonSerial_clicked();
    void on_pushButtonAdv_clicked();
    void on_pushButtonConvert_clicked();
    void on_pushButtonBluetooth_clicked();
    void on_pushButtonMoto_clicked();
    void on_pushButtonMath_clicked();
    void on_pushButtonInterrupts_clicked();
    void on_pushButtonStorager_clicked();
    void on_pushButtonEthernet_clicked();
    void on_pushButtonLCD_clicked();
    void on_pushButtonI2C_clicked();
    void on_pushButtonUser_clicked();
    void on_pushButtonUnknown_clicked();

    void slotStartAnimation();

private:
    void initSetting();
    void initData();
    void initGui();
    void showIntroduce(const QString &type);

    ///////
    int                getSideType(QPoint point);
    bool            setCursorShape(int flag);
    void            changeRectSize(int flag,QPoint globalPos);
    void resizeSubWidget(int width, int height);

private:
    int buttonId_;
    QSize initSize_;
    QRect rect_;
    //////////////////////////////////
    QPoint            m_movePoint;    //移动的距离
    bool            m_pressMouse;    //按下鼠标左键
    bool            m_changeRect;    //窗口改变大小
    bool            m_curChanged;    //鼠标形状改变
    int                m_curShape;        //鼠标形状

    int                m_minWidth;
    int                m_minHeight;

    QPoint offset_;
    QWidget *pParent_;
};

#endif // ALLBLOCKSFORM_H
