#ifndef INTRODUCEFORM_H
#define INTRODUCEFORM_H

#include "ui_IntroduceForm.h"
#include <QHash>
#include "dptr.h"
struct DataStruct;

class IntroduceForm : public QWidget, private Ui::IntroduceForm
{
    Q_OBJECT
public:
    explicit IntroduceForm(const QRect &rect, QHash<QString, DataStruct> *p, const QString &type, QWidget *parent = 0);

signals:
    void signalHideSubWindows();
    void signalShowSubWindows();

protected:
    void changeEvent(QEvent *e);

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void showEvent(QShowEvent *);

private slots:
    void on_pushButtonClose_clicked();
    void slotIntroduce(const QPixmap &image, const QString &text);

private:
    void initData();
    void initGui();
	QStringList getComponentsName(const QString &dirPath);

private:
    QString type_;//所选中的类型
    QHash<QString, DataStruct> *pHash_moduelName_dataStruct_;

    QPoint offset_;
    QWidget *pParent_;
    QRect rect_;
};

#endif // INTRODUCEFORM_H
