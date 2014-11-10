#ifndef AFFIRMFORM_H
#define AFFIRMFORM_H

#include "ui_AffirmForm.h"

class AffirmForm : public QWidget, private Ui::AffirmForm
{
    Q_OBJECT

public:
    explicit AffirmForm(const QRect rect, QWidget *parent = 0);

signals:
    void signalBack();
    void signalNotSave();
    void signalSave();

protected:
    void changeEvent(QEvent *e);
    void paintEvent(QPaintEvent *event);
    void showEvent(QShowEvent *);
    bool eventFilter(QObject *target, QEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    void initData();
    void initGui();

private:
    QRect rect_;
    QPoint offset_;
    QWidget *pParent_;
};

#endif // AFFIRMFORM_H
