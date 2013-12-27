#include "UploadWaitForm.h"
#include <QPropertyAnimation>
#include <QEasingCurve>
#include <QAbstractAnimation>
#include <QDebug>
#include <QMouseEvent>
#include <QTimer>
#include <QKeyEvent>
#include <QDir>
#include "Animation.h"

UploadWaitForm::UploadWaitForm(const QRect &rect, QWidget *parent)
    : QWidget(parent)
    , pParent_(parent)
    , rect_(rect)
    , bError_(false)
    , bDone_(false)
{
    setupUi(this);
    initSetting();
    initData();
    initGui();
}

void UploadWaitForm::SlotTypeConversionError(const QString &error)
{
    uploadError(error, QPixmap("./resource/images/upload/error.png"));
}

void UploadWaitForm::SlotPortError(const QString &error)
{
    uploadError(error, QPixmap("./resource/images/upload/error.png"));
}

void UploadWaitForm::SlotBoardError(const QString &error)
{
    uploadError(error, QPixmap("./resource/images/upload/error.png"));
}

void UploadWaitForm::SlotCompileEnd()
{
    qDebug() << "编译完成,现在上传";
    labelState->setText(tr("Upload..."));
}

void UploadWaitForm::changeEvent(QEvent *e)
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

void UploadWaitForm::mousePressEvent(QMouseEvent *event)
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

void UploadWaitForm::mouseMoveEvent(QMouseEvent *event)
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

void UploadWaitForm::showEvent(QShowEvent *event)
{
    this->setGeometry(rect_);
	pWidgetProgressBar_->move(widget_2->x(), widget_2->geometry().bottom()-8);
    labelCancel->move(this->width() - 112, labelCancel->y());
    event->accept();
}

bool UploadWaitForm::eventFilter(QObject *target, QEvent *event)
{
    if(target == labelCancel)
    {
        if(QEvent::MouseButtonPress == event->type())
        {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
            if(Qt::LeftButton == mouseEvent->button())
            {
                //先处理哪一个按下
                emit signalCancel();
                on_pushButtonCancel_clicked();
                //获取屏幕左上角坐标与软件左上角坐标的偏移
                this->mousePressEvent(mouseEvent);
                return true;
            }
        }
        else if (QEvent::MouseMove == event->type())
        {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
            this->mouseMoveEvent(mouseEvent);
            return true;
        }
        else
        {
//            QWidget::eventFilter(target, event);
            return false;
        }
    }
    else
    {
        return QWidget::eventFilter(target, event);
    }
}

void UploadWaitForm::keyPressEvent(QKeyEvent *event)
{
    //qDebug() << "怎么可能如此?";
    if(Qt::Key_Enter == event->key()
            || Qt::Key_Return == event->key())
    {
        if(bDone_)
        {
            on_pushButtonCancel_clicked();
        }
    }
}

void UploadWaitForm::on_pushButtonCancel_clicked()
{
	pWidgetProgressBar_->resize(0,11);
    slotRemoveTempFile();
    //好吧太干脆了..什么都不用管了....真他妈的明智啊....
    this->deleteLater();//fuck的比close好用多了
}

/*!
 * \brief 进度显示
 * \param progress 进度
 * \param sec 显示的速度
 */
void UploadWaitForm::slotAdvanceProgress(float progress, int sec = 500)
{
    qDebug() << "显示进度" <<progress;
    current_ = progress;
	QPropertyAnimation *pAnimation = new QPropertyAnimation(pWidgetProgressBar_, "geometry");
    pAnimation->setEasingCurve(QEasingCurve::Linear);
    pAnimation->setDuration(sec);
    int widthOld = this->width() * last_;
    int widthNew = this->width() * current_;
	pAnimation->setStartValue(QRect(pWidgetProgressBar_->x(), pWidgetProgressBar_->y(), widthOld, 11));
	pAnimation->setEndValue(QRect(pWidgetProgressBar_->x(), pWidgetProgressBar_->y(), widthNew, 11));
    pAnimation->start(QAbstractAnimation::DeleteWhenStopped);

    last_ = current_;
    if(current_ > 0.99)
    {
        labelCancel->hide();
        bDone_ = true;
        pushButtonCancel->setText(tr("Done"));
        labelState->setText(tr("Done Uploading."));
        labelImage->setPixmap(QPixmap("./resource/images/common/wait.png"));

        //取消图标动画
#ifdef Q_OS_MAC
        labelImage->setOpacity(1);
#else
        Animation::opacityAnimation(labelImage, 1000, 0, 1, QEasingCurve::OutQuart);
#endif
        Animation::posAnimation(labelImage, 500, QPoint(labelImage->pos().x()-50, labelImage->pos().y()) , QPoint(labelImage->pos().x(),labelImage->pos().y()), QEasingCurve::OutQuart);

        //Done图标动画
        pushButtonCancel->show();
#ifdef Q_OS_MAC
        pushButtonCancel->setOpacity(1);
#else
        Animation::opacityAnimation(pushButtonCancel, 1000, 0, 1, QEasingCurve::OutQuart);
#endif
        Animation::posAnimation(pushButtonCancel, 500, QPoint(this->width(), pushButtonCancel->pos().y()) , QPoint(this->width() - 112, pushButtonCancel->pos().y()), QEasingCurve::OutQuart);
        QTimer::singleShot(500, this, SLOT(slotRemoveTempFile()));
    }
}

void UploadWaitForm::slotRemoveTempFile()
{
    qDebug() << "删除临时文件";
#ifdef USE_RELEASE
	removeTempFile("./resource/tools/ArduinoUploader/Temp");
	removeTempFile("./resource/tools/ArduinoUploader/ArduinoUploader.app/Contents/MacOS/Temp");
#else
	qDebug() << "debug 模式不删除临时文件";
#endif
}

void UploadWaitForm::initSetting()
{
    this->setAttribute(Qt::WA_TranslucentBackground, true);
    this->setWindowFlags(Qt::FramelessWindowHint);

    pushButtonCancel->setWindowFlags(Qt::FramelessWindowHint);
    pushButtonCancel->setAttribute(Qt::WA_TranslucentBackground);
}

void UploadWaitForm::initData()
{
	pWidgetProgressBar_ = new QWidget(this);
	pWidgetProgressBar_->resize(0, 11);
	pWidgetProgressBar_->setStyleSheet("border-image: url(:/resource/images/upload/Upload_ProcessBar.png);");
    this->setFocus();
    labelCancel->installEventFilter(this);
    current_ = 0;
    last_ = 0;
    pushButtonCancel->hide();
}

void UploadWaitForm::initGui()
{
    this->move(1, 1);
}

void UploadWaitForm::uploadError(const QString &errorString, const QPixmap &image)
{
    if(false == bError_)
    {
        bError_ = true;

        labelState->setText(errorString);
        labelImage->setPixmap(image);

        bDone_ = true;
        labelCancel->hide();
        pushButtonCancel->setText(tr("Done"));

        //对号图标动画
#ifdef Q_OS_MAC
        labelImage->setOpacity(1);
#else
        Animation::opacityAnimation(labelImage, 1000, 0, 1, QEasingCurve::OutQuart);
#endif
        Animation::posAnimation(labelImage, 500, QPoint(labelImage->pos().x()-50, labelImage->pos().y()) , QPoint(labelImage->pos().x(),labelImage->pos().y()), QEasingCurve::OutQuart);


        pushButtonCancel->show();
#ifdef Q_OS_MAC
        pushButtonCancel->setOpacity(1);
#else
        Animation::opacityAnimation(pushButtonCancel, 1000, 0, 1, QEasingCurve::OutQuart);
#endif
        //Done图标动画
        Animation::posAnimation(pushButtonCancel, 500, QPoint(this->width(), pushButtonCancel->pos().y()) , QPoint(this->width() - 112, pushButtonCancel->pos().y()), QEasingCurve::OutQuart);
        slotRemoveTempFile();
    }
}

void UploadWaitForm::removeTempFile(const QString &dirPath)
{
    QDir dir(dirPath);
    dir.setFilter(QDir::Files);
    foreach (const QString &fileName, dir.entryList())
    {
        QString filePath = dirPath + "/" +fileName;
        if(QFile::exists(filePath))
        {
            if(!QFile::remove(filePath))
            {
                qDebug() << "清空临时文件夹的时候删除文件错误:" << filePath;
            }
        }
    }
}
