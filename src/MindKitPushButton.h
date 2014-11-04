#ifndef MINDKITPUSHBUTTON_H
#define MINDKITPUSHBUTTON_H

#include <QPushButton>

class MindKitPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MindKitPushButton(QWidget *parent = 0);
    void setName(const QString &name) { name_ = name; }

signals:
    void signalHideMindKit();
    void signalMindKitPushButtonPointer(MindKitPushButton *pointer);

public slots:

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    QPoint dragStartPosition;
    QString name_;
};

#endif // MINDKITPUSHBUTTON_H
