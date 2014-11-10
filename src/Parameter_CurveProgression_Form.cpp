#include "Parameter_CurveProgression_Form.h"
#include <QPainter>
#include <QDebug>
#include <QKeyEvent>
#include <QList>
#include <QPoint>
#include "Animation.h"

Parameter_CurveProgression_Form::Parameter_CurveProgression_Form(const QRect rect, QWidget *parent)
    : QWidget(parent)
    , pParent_(parent)
    , rect_(rect)
{
    setupUi(this);
    initSetting();
    initGui();
}

void Parameter_CurveProgression_Form::setValue(const QString &value)
{
    value_ = value;
    QString strData = value_;

    QRect bgWidget(curveBG->rect());

    strData = strData.left(strData.size()-1);
    strData = strData.right(strData.size()-1);

    QStringList splitData = strData.split(',');

    for (int i = 0 ; i < splitData.size(); i += 2){
        QString firstStr = splitData.at(i);
        QString lastStr = splitData.at(i+1);
        firstStr = firstStr.right(firstStr.size()-1);
        lastStr = lastStr.left(lastStr.size()-1);

        float x = firstStr.toFloat();
        float y = lastStr.toFloat();

        QPoint *p1 = new QPoint();
        curveBG->pointList_.append(p1);

        curveBG->pointsDataX_.append(x);
        curveBG->pointsDataY_.append(y);
        //qDebug() << "x:" << x << " " << "y:" << y;
    }
}

void Parameter_CurveProgression_Form::changeEvent(QEvent *e)
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

void Parameter_CurveProgression_Form::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void Parameter_CurveProgression_Form::mouseMoveEvent(QMouseEvent *event)
{

    mouse_posX_ = event->pos().x() - ((rect_.width() - widgetBg->width()) / 2) - curveBG->x();
    mouse_posY_ = event->pos().y() - ((rect_.height() - widgetBg->height()) / 2) - curveBG->y();

    QRect bgWidget(curveBG->rect());
    //bgWidget.adjust(curveBG->bound_,curveBG->bound_,0,0);
    //qDebug() <<bgWidget ;
    int bgTop_ = bgWidget.top() +3;
    int bgBottom_ = bgWidget.bottom() -4;
    int bgLeft_ = bgWidget.left() +3;
    int bgRight_ = bgWidget.right() -4;

    //qDebug() << "WinSize left:" << bgLeft_ << "top:" << bgTop_ << "bgWidth:" << bgRight_ << "bgHeight:" << bgBottom_;
    //qDebug() << "width:" << bgWidget.width() << "height:" <<bgWidget.height();   //761 381

    if (mouse_posX_ < bgLeft_) mouse_posX_ = bgLeft_;
    if (mouse_posX_ > bgRight_) mouse_posX_ = bgRight_;
    if (mouse_posY_ < bgTop_) mouse_posY_ = bgTop_;
    if (mouse_posY_ > bgBottom_) mouse_posY_ = bgBottom_;
    //边框约束
    //qDebug() << mouse_posX_ << " -mouse- " << mouse_posY_;

    if (curveBG->currentPointIndex_ == 0) mouse_posX_ = bgLeft_;
    if (curveBG->currentPointIndex_ == curveBG->pointList_.size() - 1) mouse_posX_ = bgRight_;
    //约束第一个点和最后一个点 不能左右移动

    if (mouse_press_ == 1 && curveBG->currentPointIndex_ != -1){
            curveBG->pointsDataX_.replace(curveBG->currentPointIndex_, (float(mouse_posX_-3))/753);
            curveBG->pointsDataY_.replace(curveBG->currentPointIndex_, (1 - ( float(mouse_posY_-3)/373)));

            //qDebug() << curveBG->pointsDataX_[curveBG->currentPointIndex_] << " -pos- " << curveBG->pointsDataY_[curveBG->currentPointIndex_];

            currentPosX->setValue(curveBG->pointsDataX_[curveBG->currentPointIndex_] *100);
            currentPosY->setValue(curveBG->pointsDataY_[curveBG->currentPointIndex_] *100);

        if (curveBG->currentPointIndex_ != 0 && curveBG->currentPointIndex_ != 1){
            if (curveBG->pointsDataX_[curveBG->currentPointIndex_] < curveBG->pointsDataX_[curveBG->currentPointIndex_ -1]){
                curveBG->pointList_.swap(curveBG->currentPointIndex_,curveBG->currentPointIndex_ -1);
                curveBG->pointsDataX_.swap(curveBG->currentPointIndex_,curveBG->currentPointIndex_ -1);
                curveBG->pointsDataY_.swap(curveBG->currentPointIndex_,curveBG->currentPointIndex_ -1);

                curveBG->currentPointIndex_ = curveBG->currentPointIndex_ -1;
            }
        }

        if (curveBG->currentPointIndex_ != curveBG->pointList_.size() - 2  && curveBG->currentPointIndex_ != curveBG->pointList_.size() - 1){
            if (curveBG->pointsDataX_[curveBG->currentPointIndex_] > curveBG->pointsDataX_[curveBG->currentPointIndex_ +1]){
                curveBG->pointList_.swap(curveBG->currentPointIndex_,curveBG->currentPointIndex_ +1);
                curveBG->pointsDataX_.swap(curveBG->currentPointIndex_,curveBG->currentPointIndex_ +1);
                curveBG->pointsDataY_.swap(curveBG->currentPointIndex_,curveBG->currentPointIndex_ +1);

                curveBG->currentPointIndex_ = curveBG->currentPointIndex_ +1;
            }
        }

    }

    curveBG->update();
}

void Parameter_CurveProgression_Form::mousePressEvent(QMouseEvent *event)
{

    mouse_posX_ = event->pos().x() - ((rect_.width() - widgetBg->width()) / 2) - curveBG->x();
    mouse_posY_ = event->pos().y() - ((rect_.height() - widgetBg->height()) / 2) - curveBG->y();

    QRect bgWidget(curveBG->rect());

    curveBG->currentPointIndex_ = -1;
    for (int i = 0 ; i < curveBG->pointList_.size() ; i ++){
        //qDebug() << curveBG->pointsDataX_[i]*(bgWidget.width()-4) << " " << mouse_posX_;
        if (abs(curveBG->pointsDataX_[i]*(bgWidget.width()-4) - mouse_posX_ ) < curveBG->bound_){
            if (abs(bgWidget.height() - curveBG->pointsDataY_[i]*(bgWidget.height()-4) - mouse_posY_ ) < curveBG->bound_){
                curveBG->currentPointIndex_ = i;

                curveBG->pointsDataX_.replace(curveBG->currentPointIndex_, (float(mouse_posX_-3))/753);
                curveBG->pointsDataY_.replace(curveBG->currentPointIndex_, (1 - ( float(mouse_posY_-3)/373)));
                //for percent * 100
            }
        }
    }
    //qDebug() << curveBG->currentPointIndex_;

    mouse_press_ = 1;
    curveBG->update();
}

void Parameter_CurveProgression_Form::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);

    mouse_press_ = 0;
}

void Parameter_CurveProgression_Form::mouseDoubleClickEvent(QMouseEvent *event)
{

    mouse_posX_ = event->pos().x() - ((rect_.width() - widgetBg->width()) / 2) - curveBG->x();
    mouse_posY_ = event->pos().y() - ((rect_.height() - widgetBg->height()) / 2) - curveBG->y();

   // qDebug() << mouse_posX_;

    QRect bgWidget(curveBG->rect());
    bgWidget.adjust(curveBG->bound_,curveBG->bound_,-curveBG->bound_,-curveBG->bound_);

    if (mouse_posX_ > bgWidget.left() && mouse_posX_ < bgWidget.width() && mouse_posY_ > bgWidget.top() && mouse_posY_ < bgWidget.height()){
        //QPoint widget_pos(((rect_.width() - widgetBg->width()) / 2),((rect_.height() - widgetBg->height()) / 2));//根据屏幕分辨率 计算窗体位置
        //QPoint pos = event->pos() - widget_pos - QPoint(20,20);    //20的边框
        QPoint pos(mouse_posX_,mouse_posY_);
        QPoint *p1 = new QPoint(pos);
        QRect bgWidget(curveBG->rect());

        int insertIndex = 0;
        for (int i = 0 ; i < curveBG->pointList_.size() ; i++){
            if (mouse_posX_ < curveBG->pointsDataX_.at(i)* bgWidget.width()){
                insertIndex = i;
                break;
            }
        }

        curveBG->currentPointIndex_ = insertIndex;
        curveBG->pointList_.insert(insertIndex,p1);

        curveBG->pointsDataX_.insert(insertIndex,float(pos.x())/bgWidget.width());
        curveBG->pointsDataY_.insert(insertIndex,(1 - (float(pos.y())/bgWidget.height())));

        currentPosX->setValue(curveBG->pointsDataX_[curveBG->currentPointIndex_] *100);
        currentPosY->setValue(curveBG->pointsDataY_[curveBG->currentPointIndex_] *100);

        //for percent * 100
		curveBG->pointNumber_ += 1;
        //qDebug() <<  "curveBG->pointNumber_ : " << curveBG->pointNumber_;
        curveBG->update();
    }

}

void Parameter_CurveProgression_Form::showEvent(QShowEvent *event)
{
    this->setGeometry(rect_);
}

void Parameter_CurveProgression_Form::initSetting()
{
    //this->setWindowState(Qt::WindowActive);
    this->installEventFilter(this);
    this->setFocus();

    this->setAttribute(Qt::WA_TranslucentBackground, true);
    //恩原来是tool
    this->setWindowFlags(Qt::FramelessWindowHint /*| Qt::Tool*/);

    pushButton->setWindowFlags(Qt::FramelessWindowHint);
    pushButton->setAttribute(Qt::WA_TranslucentBackground);


/*
    //0,380    760,0
    QPoint *p1 = new QPoint(3,377);
    QPoint *p2 = new QPoint(757,3);
    curveBG->pointList_.append(p1);
    curveBG->pointList_.append(p2);

    curveBG->pointsDataX_.append(0);
    curveBG->pointsDataY_.append(0);
    //add new point to (0,0)
    curveBG->pointsDataX_.append(1.00f);
    curveBG->pointsDataY_.append(1.00f);
    //ad new point to (1,1)
*/
}

void Parameter_CurveProgression_Form::initGui()
{
    this->move(1, 1);
    Animation::opacityAnimation(pushButton, 150, 0, 1, QEasingCurve::OutQuart);
    Animation::posAnimation(pushButton, 150, pushButton->pos() + QPoint(50, 0) , pushButton->pos(), QEasingCurve::OutQuart);
}

void Parameter_CurveProgression_Form::on_pushButton_clicked()
{
    QString value = QString("[") + QString::number(curveBG->pointList_.size()) + QString("]") + QString("[") + "2" + QString("]");
	emit signalValueChange(value);

    QString result = "{";
    for (int i = 0 ; i < curveBG->pointList_.size() ; i ++){
        result.append("{");
        result.append(QString::number(curveBG->pointsDataX_.at(i)));
        result.append(",");
        result.append(QString::number(curveBG->pointsDataY_.at(i)));
        result.append("},");
    }
    result = result.left(result.size()-1);
    result.append("}");

    value_ = result;

    emit signalValueChange(value_);
    close();
}

void Parameter_CurveProgression_Form::slotPressCtrlPoint()
{
    QPushButton *p = qobject_cast<QPushButton *>(sender());
}
void Parameter_CurveProgression_Form::slotReleaseCtrlPoint()
{
    QPushButton *p = qobject_cast<QPushButton *>(sender());
}

bool Parameter_CurveProgression_Form::eventFilter(QObject *target, QEvent *event){

    QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
    QPushButton *ctrlPoint  = static_cast<QPushButton *>(target);

	if (target != this)
	{
        switch(event->type())
        {
            case QEvent::MouseButtonPress:
            {
                if(Qt::LeftButton == mouseEvent->button())
                {

                }
            }
            case QEvent::MouseButtonRelease:
            {
                if(Qt::LeftButton == mouseEvent->button())
                {

                }
            }
            case QEvent::MouseMove:
            {
                if (Qt::LeftButton == mouseEvent->button())
                {

                }
            }
            case QEvent::HoverMove:
            {
                ctrlPoint->move(mouseEvent->pos());
                //qDebug() << mouseEvent->pos();
            }
        }
    }

    QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
    //if(lineEdit == target  || this == target)
    //{
    if(QEvent::KeyPress == event->type())
    {
        if(Qt::Key_Enter == keyEvent->key()
                || Qt::Key_Return == keyEvent->key())
        {
            //this->on_pushButton_clicked();
            //禁用回车确认
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
}

void Parameter_CurveProgression_Form::on_currentPosX_valueChanged(double arg1)
{
    //float value = currentPosX->value();
    //if (value <= 0) value = 0.1;

    //currentPosX->setValue(arg1);
    //curveBG->pointList_[curveBG->currentPointIndex_]->setX(754*(arg1/100));
    curveBG->pointsDataX_[curveBG->currentPointIndex_] = arg1/100;

    curveBG->update();
}

void Parameter_CurveProgression_Form::on_currentPosY_valueChanged(double arg1)
{
    //float value = currentPosX->value();
    //if (value <= 0) value = 0.1;

    //currentPosY->setValue(arg1);
    //curveBG->pointList_[curveBG->currentPointIndex_]->setY(374*(1- arg1/100));
    curveBG->pointsDataY_[curveBG->currentPointIndex_] = arg1/100;

    curveBG->update();
}
