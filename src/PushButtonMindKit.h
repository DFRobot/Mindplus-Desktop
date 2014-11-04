#ifndef PUSHBUTTONMINDKIT_H
#define PUSHBUTTONMINDKIT_H

#include <QPushButton>

class PushButtonMindKit : public QPushButton
{
    Q_OBJECT
public:
    explicit PushButtonMindKit(QWidget *parent = 0);
    
signals:
    
public slots:
protected:
    //为了在派生类中实现样式, 还是得重载这家伙
    void paintEvent(QPaintEvent *);
    
};

#endif // PUSHBUTTONMINDKIT_H
