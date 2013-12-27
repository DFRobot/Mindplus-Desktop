#ifndef FUNCTIONAREA_H
#define FUNCTIONAREA_H

#include "ui_FunctionArea.h"
#include <QWidget>

class FunctionArea : public QWidget, private Ui::FunctionArea
{
    Q_OBJECT
    
public:
    explicit FunctionArea(QWidget *parent = 0);
    
signals:
    void signalNewProjectClick();
    void signalUploadClick();
    void signalSaveClick();
    void signalOpenClick();

protected:
    void changeEvent(QEvent *e);

private:
    void initData();

private:

};

#endif // FUNCTIONAREA_H
