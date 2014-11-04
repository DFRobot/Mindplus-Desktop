#ifndef UPLOADWAITFORM_H
#define UPLOADWAITFORM_H

#include "ui_UploadWaitForm.h"
#include <QProcess>

class UploadWaitForm : public QWidget, private Ui::UploadWaitForm
{
    Q_OBJECT

public:
    explicit UploadWaitForm(const QRect &rect, QWidget *parent = 0);

signals:
    void signalCancel();

public slots:
    void SlotTypeConversionError(const QString &error);
    void SlotPortError(const QString &error);
    void SlotBoardError(const QString &error);
    void SlotCompileEnd();

protected:
    void changeEvent(QEvent *e);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void showEvent(QShowEvent *event);
    //主要是为了labelCancel
    bool eventFilter(QObject *target, QEvent *event);
    //主要是为了按下回车键
    void keyPressEvent(QKeyEvent *event);

private slots:
    void on_pushButtonCancel_clicked();
    void slotAdvanceProgress(float progress, int sec);
    void slotRemoveTempFile();

private:
    void initSetting();
    void initData();
    void initGui();
    void uploadError(const QString &errorString, const QPixmap &image);
    void removeTempFile(const QString &dirPath);

private:
    float last_;
    float current_;
    QProcess process_;
    QPoint offset_;
    QWidget *pParent_;
    QRect rect_;

    bool bError_;
    bool bDone_;

	QWidget *pWidgetProgressBar_;
};

#endif // UPLOADWAITFORM_H
