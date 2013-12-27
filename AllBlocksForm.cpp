#include "AllBlocksForm.h"
#include <QDebug>
#include <QTimer>
#include <QMouseEvent>
#include <QShowEvent>
#include <QResizeEvent>
#include "Animation.h"
#include "IntroduceForm.h"
#include "WidgetMain.h"

AllBlocksForm::AllBlocksForm(const QRect &rect, QWidget *parent)
    :QWidget(parent)
    , buttonId_(0)
    , rect_(rect)
    ,m_pressMouse(false)
    ,m_changeRect(false)
    ,m_curChanged(false)
    ,m_curShape(0)
    ,m_minWidth(1024)
    ,m_minHeight(675)
    ,pParent_(parent)
{
    setupUi(this);
    initSetting();
    initData();
    initGui();
}

void AllBlocksForm::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type())
    {
        case QEvent::LanguageChange:
            retranslateUi(this);
            break;
        default:
            break;
    }
}

void AllBlocksForm::showEvent(QShowEvent *event)
{
    Q_UNUSED(event);
    qDebug() << "要调整的大小: " <<rect_;
    initSize_ = rect_.size();
    setGeometry(rect_);
    //resizeSubWidget(rect_.width(), rect_.height());
}

void AllBlocksForm::resizeEvent(QResizeEvent *event)
{
    int width = event->size().width();
    int height = event->size().height();
    resizeSubWidget(width, height);
}

void AllBlocksForm::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        QWidget *pParent_ = static_cast<QWidget *>(this->parent());
        if(NULL == pParent_)
        {
            return;
        }
        offset_ = event->globalPos() - pParent_->frameGeometry().topLeft();
    }
}

void AllBlocksForm::mouseMoveEvent(QMouseEvent *event)
{
    if (!(event->buttons() & Qt::LeftButton))
    {
        return;
    }
    if ((event->pos() - offset_).manhattanLength()
            < QApplication::startDragDistance())
    {
        return;
    }
    pParent_->move(event->globalPos() - offset_);
}

//void AllBlocksForm::mousePressEvent(QMouseEvent *event)
//{
//    qDebug() << "all blocks from mouse press event";
//    //    if(Qt::LeftButton == event->button())
//    //    {
//    //        m_ptPressGlobal = event->globalPos();
//    //        m_bLeftBtnPress = true;
//    //    }
//    if (event->button() == Qt::LeftButton)    //只能是鼠标左键移动和改变大小
//    {
//        m_pressMouse = true;

//        if (m_curChanged)
//        {
//            m_changeRect = true;
//            m_pressMouse = false; //防止整个窗口移动
//        }
//    }

//    m_movePoint = event->globalPos() - pos();    //窗口移动距离
//}

//void AllBlocksForm::mouseMoveEvent(QMouseEvent *event)
//{
//    qDebug() << "all blocks from mouse move event";
//    //    if(!m_bLeftBtnPress)
//    //    {
//    //        m_eDirection = pointValid(event->x(),event->y());
//    //        setCursorStyle(m_eDirection);
//    //    }
//    //    else
//    //    {
//    //        int nXGlobal = event->globalX();
//    //        int nYGlobal = event->globalY();
//    //        setDrayMove(nXGlobal, nYGlobal, m_eDirection);
//    //        m_ptPressGlobal =QPoint(nXGlobal, nYGlobal);
//    //    }
//    if (m_pressMouse)    //移动窗口
//    {
//        QPoint movePos = event->globalPos();
//        move(movePos - m_movePoint);
//    }
//    else    //改变窗口大小
//    {
//        if (!m_changeRect)    //如果没按下鼠标左键, 判断是否在边框    (主要是为了按下鼠标后不要再验证鼠标形状了)
//        {
//            m_curShape = getSideType(event->pos());
//            m_curChanged = setCursorShape(m_curShape);
//        }
//        else
//        {
//            changeRectSize(m_curShape,event->pos());
//        }
//    }
//}

//void AllBlocksForm::mouseReleaseEvent(QMouseEvent *event)
//{
//    qDebug() << "all blocks from mouse release event";
//    m_pressMouse = false;
//    m_changeRect = false;
//}

void AllBlocksForm::slotStartAnimation()
{
    switch(buttonId_++)
    {
        case Digital:
        {
            pushButtonDigital->setName("Digital");
            Animation::posAnimation(pushButtonDigital, 100, pushButtonDigital->pos()+QPoint(50, 0), pushButtonDigital->pos());
            Animation::opacityAnimation(pushButtonDigital, 100, 0, 1);
            break;
        }
        case Analog:
        {
            pushButtonAnalog->setName("Analog");
            Animation::posAnimation(pushButtonAnalog, 100, pushButtonAnalog->pos()+QPoint(50, 0), pushButtonAnalog->pos());
            Animation::opacityAnimation(pushButtonAnalog, 100, 0, 1);
            break;
        }
        case Time:
        {
            pushButtonTime->setName("Time");
            Animation::posAnimation(pushButtonTime, 100, pushButtonTime->pos()+QPoint(50, 0), pushButtonTime->pos());
            Animation::opacityAnimation(pushButtonTime, 100, 0, 1);
            break;
        }
        case Servo:
        {
            pushButtonServo->setName("Servo");
            Animation::posAnimation(pushButtonServo, 100, pushButtonServo->pos()+QPoint(50, 0), pushButtonServo->pos());
            Animation::opacityAnimation(pushButtonServo, 100, 0, 1);
            break;
        }
        case Flow:
        {
            pushButtonFlow->setName("Flow");
            Animation::posAnimation(pushButtonFlow, 100, pushButtonFlow->pos()+QPoint(50, 0), pushButtonFlow->pos());
            Animation::opacityAnimation(pushButtonFlow, 100, 0, 1);
            break;
        }
        case MindKit:
        {
            pushButtonMindKit->setName("MindKit");
            Animation::posAnimation(pushButtonMindKit, 100, pushButtonMindKit->pos()+QPoint(50, 0), pushButtonMindKit->pos());
            Animation::opacityAnimation(pushButtonMindKit, 100, 0, 1);
            break;
        }
        case Serial:
        {
            pushButtonSerial->setName("Serial");
            Animation::posAnimation(pushButtonSerial, 100, pushButtonSerial->pos()+QPoint(50, 0), pushButtonSerial->pos());
            Animation::opacityAnimation(pushButtonSerial, 100, 0, 1);
            break;
        }
        case Adv:
        {
            pushButtonAdv->setName("Adv");
            Animation::posAnimation(pushButtonAdv, 100, pushButtonAdv->pos()+QPoint(50, 0), pushButtonAdv->pos());
            Animation::opacityAnimation(pushButtonAdv, 100, 0, 1);
            break;
        }
        case Convert:
        {
            pushButtonConvert->setName("Convert");
            Animation::posAnimation(pushButtonConvert, 100, pushButtonConvert->pos()+QPoint(50, 0), pushButtonConvert->pos());
            Animation::opacityAnimation(pushButtonConvert, 100, 0, 1);
            break;
        }
        case Bluetooth:
        {
            pushButtonBluetooth->setName("Bluetooth");
            Animation::posAnimation(pushButtonBluetooth, 100, pushButtonBluetooth->pos()+QPoint(50, 0), pushButtonBluetooth->pos());
            Animation::opacityAnimation(pushButtonBluetooth, 100, 0, 1);
            break;
        }
        case Moto:
        {
            pushButtonMoto->setName("Moto");
            Animation::posAnimation(pushButtonMoto, 100, pushButtonMoto->pos()+QPoint(50, 0), pushButtonMoto->pos());
            Animation::opacityAnimation(pushButtonMoto, 100, 0, 1);
            break;
        }
        case Math:
        {
            pushButtonMath->setName("Math");
            Animation::posAnimation(pushButtonMath, 100, pushButtonMath->pos()+QPoint(50, 0), pushButtonMath->pos());
            Animation::opacityAnimation(pushButtonMath, 100, 0, 1);
            break;
        }
        case Interrupts:
        {
            pushButtonInterrupts->setName("Interrupts");
            Animation::posAnimation(pushButtonInterrupts, 100, pushButtonInterrupts->pos()+QPoint(50, 0), pushButtonInterrupts->pos());
            Animation::opacityAnimation(pushButtonInterrupts, 100, 0, 1);
            break;
        }
        case Storager:
        {
            pushButtonStorager->setName("Storager");
            Animation::posAnimation(pushButtonStorager, 100, pushButtonStorager->pos()+QPoint(50, 0), pushButtonStorager->pos());
            Animation::opacityAnimation(pushButtonStorager, 100, 0, 1);
            break;
        }
        case Ethernet:
        {
            pushButtonEthernet->setName("Ethernet");
            Animation::posAnimation(pushButtonEthernet, 100, pushButtonEthernet->pos()+QPoint(50, 0), pushButtonEthernet->pos());
            Animation::opacityAnimation(pushButtonEthernet, 100, 0, 1);
            break;
        }
        case LCD:
        {
            pushButtonLCD->setName("LCD");
            Animation::posAnimation(pushButtonLCD, 100, pushButtonLCD->pos()+QPoint(50, 0), pushButtonLCD->pos());
            Animation::opacityAnimation(pushButtonLCD, 100, 0, 1);
            break;
        }
        case I2C:
        {
            pushButtonI2C->setName("I2C");
            Animation::posAnimation(pushButtonI2C, 100, pushButtonI2C->pos()+QPoint(50, 0), pushButtonI2C->pos());
            Animation::opacityAnimation(pushButtonI2C, 100, 0, 1);
            break;
        }
        case UserBB:
        {
            pushButtonUser->setName("UserBB");
            Animation::posAnimation(pushButtonUser, 100, pushButtonUser->pos()+QPoint(50, 0), pushButtonUser->pos());
            Animation::opacityAnimation(pushButtonUser, 100, 0, 1);
            break;
        }
        case Unkown:
        {
            pushButtonUnknown->setName("Unkown");
            Animation::posAnimation(pushButtonUnknown, 100, pushButtonUnknown->pos()+QPoint(50, 0), pushButtonUnknown->pos());
            Animation::opacityAnimation(pushButtonUnknown, 100, 0, 1);
            break;
        }
        default:
        {
            //
        }
    }
}

void AllBlocksForm::initSetting()
{
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    setMouseTracking(true);
    if(hasMouseTracking())
    {
        qDebug() << "setMouseTracking true";
    }
    else
    {
        qDebug() << "setMouseTracking fail";
    }
    setMinimumSize(m_minWidth, m_minHeight);
}

void AllBlocksForm::initData()
{
}

void AllBlocksForm::on_pushButtonReturn_clicked()
{
    close();
}

void AllBlocksForm::initGui()
{
    this->move(1, 1);
    //可以分成三个组, 在showEvent的时候开始动画
    for(int i = 0; i != 19; ++i)
    {
        QTimer::singleShot(0+30*i, this, SLOT(slotStartAnimation()));
    }
}

void AllBlocksForm::showIntroduce(const QString &type)
{
    emit signalShowIntroduce(type);
    close();
}

int AllBlocksForm::getSideType(QPoint point)
{
    int lenth = 5;    //设置判断指针的距离
    if (point.x()<=this->rect().left()+lenth)
    {
        if (point.y()>=this->rect().bottom()-lenth)
        {
            return LEFTBOTTOM;
        }
        else if (point.y()<=this->rect().top()+lenth)
        {
            return LEFTTOP;
        }
        return LEFT;
    }
    else if (point.x()>=this->rect().right()-lenth)
    {
        if (point.y()>=this->rect().bottom()-lenth)
        {
            return RIGHTBOTTOM;
        }
        else if (point.y()<=this->rect().top()+lenth)
        {
            return RIGHTTOP;
        }
        return RIGHT;
    }
    else if (point.y()<=this->rect().top()+lenth)
    {
        return TOP;
    }
    else if (point.y()>=this->rect().bottom()-lenth)
    {
        return BOTTOM;
    }
    return -1;
}

bool AllBlocksForm::setCursorShape(int flag)
{
    QCursor curType;
    bool shapeChanged = false;
    switch (flag)
    {
        case LEFT:
        case RIGHT:
            curType = Qt::SizeHorCursor;
            shapeChanged = true;
            break;

        case TOP:
        case BOTTOM:
            curType = Qt::SizeVerCursor;
            shapeChanged = true;
            break;
        case LEFTTOP:
        case RIGHTBOTTOM:
            curType = Qt::SizeFDiagCursor;
            shapeChanged = true;
            break;
        case RIGHTTOP:
        case LEFTBOTTOM:
            curType = Qt::SizeBDiagCursor;
            shapeChanged = true;
            break;
        default:
            curType = Qt::ArrowCursor;
            break;
    }

    this->setCursor(curType);

    return shapeChanged;
}

void AllBlocksForm::changeRectSize(int flag, QPoint globalPos)
{
    globalPos = mapToParent(globalPos);
    int globalX = globalPos.x();
    int globalY = globalPos.y();
    int widgetX = this->pos().x();
    int widgetY = this->pos().y();
    int LMLenght = widgetX+this->width() - globalX;    //左移距离
    int RMLenght = globalX - widgetX +1;
    int TMLenght = widgetY + this->height() - globalY;
    int BMLenght = globalY - widgetY +1;

    if (LMLenght<=m_minWidth)    //防止向右最小时窗口移动
    {
        globalX = this->pos().x();
    }
    if (TMLenght<=m_minHeight)    //防止向下最小时窗口时移动
    {
        globalY = this->pos().y();
    }

    switch (flag)
    {
        case LEFT:
            setGeometry(globalX,widgetY,LMLenght,this->height());
            break;

        case RIGHT:
            setGeometry(widgetX,widgetY,RMLenght,this->height());
            break;

        case TOP:
            setGeometry(widgetX,globalY,this->width(),TMLenght);
            break;

        case BOTTOM:
            setGeometry(widgetX,widgetY,this->width(),BMLenght);
            break;

        case LEFTTOP:
            setGeometry(globalX,globalY,LMLenght,TMLenght);
            break;
        case LEFTBOTTOM:
            setGeometry(globalX,widgetY,LMLenght,BMLenght);
            break;

        case RIGHTTOP:
            setGeometry(widgetX,globalY,RMLenght,TMLenght);
            break;

        case RIGHTBOTTOM:
            setGeometry(widgetX,widgetY,RMLenght,BMLenght);
            break;
        default:
            break;
    }
    update();
}

void AllBlocksForm::resizeSubWidget(int width, int height)
{
    qDebug() << "resizeSubWidget" << width << height;

    if(height > 677)
    {
        double x = height/675.0;
        int offset = x*50 - 50;
        //背景
        //widget_0->resize(widget_0->size() * x);
        //第一个
        widget_1->resize(widget_1->size() * x);
        //第二个
        widget_2->move(widget_1->x()+widget_1->width() + 50+offset, widget_2->y());
        widget_2->resize(widget_2->size() * x);

        //第三个
        widget_3->move(widget_2->x() + widget_2->width() + 50+offset, widget_3->y());
        widget_3->resize(widget_3->size() * x);
    }
    else if(height == 677)
    {
        qDebug() << "换位置啊";
        widget_1->resize(250, 510);
        widget_1->move(30, 100);

        widget_2->resize(250, 510);
        widget_2->move(300, 100);

        widget_3->resize(250, 510);
        widget_3->move(570, 100);
    }

}

void AllBlocksForm::on_pushButtonMindKit_clicked()
{
    emit signalShowMindKit();
    close();
}

void AllBlocksForm::on_pushButtonDigital_clicked()
{
    //DigitalIO
    showIntroduce("DigitalIO");
}

void AllBlocksForm::on_pushButtonAnalog_clicked()
{
    showIntroduce("AnalogIO");
}

void AllBlocksForm::on_pushButtonTime_clicked()
{
    showIntroduce("Time");
}

void AllBlocksForm::on_pushButtonServo_clicked()
{
    showIntroduce("Servo");
}

void AllBlocksForm::on_pushButtonFlow_clicked()
{
    showIntroduce("Flow");
}

void AllBlocksForm::on_pushButtonSerial_clicked()
{
    showIntroduce("Serial");
}

void AllBlocksForm::on_pushButtonAdv_clicked()
{
    showIntroduce("AdvIO");
}

void AllBlocksForm::on_pushButtonConvert_clicked()
{
    showIntroduce("Convert");
}

void AllBlocksForm::on_pushButtonBluetooth_clicked()
{
    showIntroduce("Bluetooth");
}

void AllBlocksForm::on_pushButtonMoto_clicked()
{
    showIntroduce("Moto");
}

void AllBlocksForm::on_pushButtonMath_clicked()
{
    showIntroduce("Math");
}

void AllBlocksForm::on_pushButtonInterrupts_clicked()
{
    showIntroduce("Interrupts");
}

void AllBlocksForm::on_pushButtonStorager_clicked()
{
    showIntroduce("Storager");
}

void AllBlocksForm::on_pushButtonEthernet_clicked()
{
    showIntroduce("Ethernet");
}

void AllBlocksForm::on_pushButtonLCD_clicked()
{
    showIntroduce("LCD");
}

void AllBlocksForm::on_pushButtonI2C_clicked()
{
    showIntroduce("I2CSPI");
}

void AllBlocksForm::on_pushButtonUser_clicked()
{
    showIntroduce("User");
}

void AllBlocksForm::on_pushButtonUnknown_clicked()
{
    showIntroduce("Servo");
}
