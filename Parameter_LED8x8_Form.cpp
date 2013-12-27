#include "Parameter_LED8x8_Form.h"
#include <QPainter>
#include <QDebug>
#include <QKeyEvent>
#include "Animation.h"

//QPushButton *currentLED;

Parameter_LED8x8_Form::Parameter_LED8x8_Form(const QRect rect, QWidget *parent)
    : QWidget(parent)
    , pParent_(parent)
    , rect_(rect)
{
    setupUi(this);
    initSetting();
    initGui();
}

void Parameter_LED8x8_Form::setValue(const QString &value)
{

    value_ = value;

    for (int i = 1; i < 65 ; i ++){
        if ( value_[i].digitValue() == 1) {
            QPixmap singleLED_Light("resource/images/parameter_input/LED_Matrix/ParameterSetup_8x8LED_Single.png");
            LEDsList_.at(i-1)->setPixmap(singleLED_Light);
            ledState_[i-1] = 1;
        }else{
            QPixmap singleLED_Dark("resource/images/parameter_input/LED_Matrix/ParameterSetup_8x8LED_Single_Dark.png");
            LEDsList_.at(i-1)->setPixmap(singleLED_Dark);
            ledState_[i-1] = 0;
        }
    }

}

void Parameter_LED8x8_Form::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        retranslateUi(this);
        break;
    default:
        break;
    }
}

void Parameter_LED8x8_Form::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

bool Parameter_LED8x8_Form::eventFilter(QObject *target, QEvent *event)
{
    QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
    //if(lineEdit == target  || this == target)
    //{
    if(QEvent::KeyPress == event->type())
    {
        if(Qt::Key_Enter == keyEvent->key()
                || Qt::Key_Return == keyEvent->key())
        {
            this->on_pushButton_clicked();
        }
        else
        {
            return QWidget::eventFilter(target, event);
        }
    }
    else
    {
        return QWidget::eventFilter(target, event);
    }
    //}
    //else
    //{
    //return QWidget::eventFilter(target, event);
    //}
}

void Parameter_LED8x8_Form::mouseMoveEvent(QMouseEvent *event)
{
    mouse_posX_ = event->pos().x();
    mouse_posY_ = event->pos().y();

    if (mouse_press_ > 0){
        SetLED();
    }
}

void Parameter_LED8x8_Form::mousePressEvent(QMouseEvent *event)
{
    event->button();
    mouse_posX_ = event->pos().x();
    mouse_posY_ = event->pos().y();

    if (event->button() == Qt::LeftButton){
        mouse_press_ = 1;
    }else if (event->button() == Qt::RightButton){
        mouse_press_ = 2;
    }

    ///////////////////鼠标按下的瞬间就先来一次/////////////
    SetLED();
}

void Parameter_LED8x8_Form::SetLED()
{
    int mouseX = mouse_posX_;
    int mouseY = mouse_posY_;
    int widget_pos_x = widgetBg->x();
    int widget_pos_y = widgetBg->y();
    int bgi_pos_x = bgimage->x();
    int bgi_pos_y = bgimage->y();

    mouseX = mouseX - widget_pos_x - bgi_pos_x;
    mouseY = mouseY - widget_pos_y - bgi_pos_y;
    if (mouseX < 0 ) mouseX = 0;
    if (mouseY < 0 ) mouseY = 0;
    int x = int (mouseX/43);
    int y = int (mouseY/43);

    if (x > 7) x = 7;
    if (y > 7) y = 7;

    if (mouse_press_ == 1){
        QPixmap singleLED_Light("resource/images/parameter_input/LED_Matrix/ParameterSetup_8x8LED_Single.png");
        LEDsList_.at(y*8+x)->setPixmap(singleLED_Light);
        ledState_[y*8+x] = 1;
    }else if(mouse_press_ == 2){
        QPixmap singleLED_Dark("resource/images/parameter_input/LED_Matrix/ParameterSetup_8x8LED_Single_Dark.png");
        LEDsList_.at(y*8+x)->setPixmap(singleLED_Dark);
        ledState_[y*8+x] = 0;
    }
}

void Parameter_LED8x8_Form::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);

/*
    if (mouse_posX_ == event->pos().x() && mouse_posY_ == event->pos().y()){
        if (mouse_press_ == 1){
            QPixmap singleLED_Dark("resource/images/parameter_input/LED_Matrix/ParameterSetup_8x8LED_Single_Dark.png");
            //LEDsList_.at(y*8+x)->setPixmap(singleLED_Dark);
            ledState_[y*8+x] = 0;
        }
    }
        */
    ///这里一直报错 不知道为什么不能设置

    mouse_press_ = 0;
}

void Parameter_LED8x8_Form::showEvent(QShowEvent *event)
{
    this->setGeometry(rect_);
}

void Parameter_LED8x8_Form::initSetting()
{
    //this->setWindowState(Qt::WindowActive);
    this->installEventFilter(this);
    this->setFocus();

    this->setAttribute(Qt::WA_TranslucentBackground, true);
    //恩原来是tool
    this->setWindowFlags(Qt::FramelessWindowHint /*| Qt::Tool*/);

    pushButton->setWindowFlags(Qt::FramelessWindowHint);
    pushButton->setAttribute(Qt::WA_TranslucentBackground);

    for (int i = 0 ; i < 8 ; i ++){
        for (int j = 0 ; j < 8 ; j ++){
            ledState_[i*8+j] = 0;
        }
    }


    int widget_pos_x = (rect_.width() - widgetBg->width()) / 2;   //根据屏幕分辨率 计算窗体位置
    int widget_pos_y = (rect_.height() - widgetBg->height()) / 2;
    int bgi_pos_x = bgimage->x();
    int bgi_pos_y = bgimage->y();

    QPixmap singleLED_Dark("resource/images/parameter_input/LED_Matrix/ParameterSetup_8x8LED_Single_Dark.png");

    for (int i = 0 ; i < 8 ; i ++){
        for (int j = 0 ; j < 8 ; j ++){
            QLabel *p = new QLabel(this);
            p->setObjectName(QString::number((i*8+j)));

            p->move(widget_pos_x + bgi_pos_x + 5 + j*43,widget_pos_y + bgi_pos_y + 5 + i*43);
            p->resize(32,32);
            p->setPixmap(singleLED_Dark);

            p->setAttribute(Qt::WA_TranslucentBackground);
            LEDsList_.append(p);
            ledState_[j*8+i] = 0;
        }
    }

}

void Parameter_LED8x8_Form::initGui()
{
    this->move(1, 1);
    Animation::opacityAnimation(pushButton, 150, 0, 1, QEasingCurve::OutQuart);
    Animation::posAnimation(pushButton, 150, pushButton->pos() + QPoint(50, 0) , pushButton->pos(), QEasingCurve::OutQuart);
}



void Parameter_LED8x8_Form::on_pushButton_clicked()
{
    QString result = "\"";
    for (int i = 0 ; i < 64 ; i ++){
        result.append(QString::number(ledState_[i]));
    }
    result.append("\"");

    value_ = result;
    //qDebug() << result;

    emit signalValueChange(value_);
    close();
}
