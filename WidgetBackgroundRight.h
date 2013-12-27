#ifndef WIDGETBACKGROUNDRIGHT_H
#define WIDGETBACKGROUNDRIGHT_H

#include <QWidget>

class WidgetBackgroundRight : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetBackgroundRight(QWidget *parent = 0);

signals:
    
public slots:

protected:
    void paintEvent(QPaintEvent *);
    
private:
    QPixmap *pImage_;
};

#endif // WIDGETBACKGROUNDRIGHT_H
