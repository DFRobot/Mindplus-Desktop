#ifndef FILEINFORFORM_H
#define FILEINFORFORM_H

#include "ui_FileInforForm.h"

class FileInforForm : public QWidget, private Ui::FileInforForm
{
    Q_OBJECT

public:
    explicit FileInforForm(QWidget *parent = 0);

protected:
    void changeEvent(QEvent *e);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private slots:
    void on_pushButtonReturn_clicked();

private:
    void initData();
    void initGui();

private:
    QString projectName_;
    QString author_;
    QString category_;
    QString tag_;
    QString description_;

    QPoint offset_;
    QWidget *pParent_;
};

#endif // FILEINFORFORM_H
