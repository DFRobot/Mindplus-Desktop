#ifndef UPLOADSETTINGFORM_H
#define UPLOADSETTINGFORM_H

#include "ui_UploadSettingForm.h"
#include <QPointer>
class ListWidgetItemWidget_UploadSetting;
class UploadSettingForm : public QWidget, private Ui::UploadSettingForm
{
    Q_OBJECT

public:
    explicit UploadSettingForm(const QRect &rect, QWidget *parent = 0);

signals:
    void signalSelectBoardType(const QString &boardName, const QString &boardIndex);
	void signalSelectBoard(const QString &board);
    void signalSelectSerial(const QString &serialName);
    void signalDone();

protected:
    void changeEvent(QEvent *e);
    void paintEvent(QPaintEvent *);

	void timerEvent(QTimerEvent *event);

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void showEvent(QShowEvent *event);
    void keyPressEvent(QKeyEvent *event);

private slots:
	void on_pushButtonUpload_clicked();
	void on_pushButtonBack_clicked();

	void slotBoardActivated(const QString &str);
	void slotSerialPortActivated(const QString &str);

	void on_pushButtonUno_clicked();

	void on_pushButtonLeonardo_clicked();

private:
    void initSetting();
    void initData();
    void initGui();

	QStringList getSerialPorts();

private:
    int countAnimationIndex_;

    //移动
    QPoint offset_;
    QWidget *pParent_;
    QRect rect_;

    //名字到对应序列的映射
    QMap<QString, int> map_name_index_;
	QSet<QString> serialPortsSet_;
	//
	QString currentSerialPort_;
	QString currentBoard_;
};

#endif // UPLOADSETTINGFORM_H
