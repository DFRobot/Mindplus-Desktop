#ifndef FUNCTIONWIDGET_H
#define FUNCTIONWIDGET_H

#include "ui_FunctionAreaWidget.h"

class FunctionAreaWidget : public QWidget, private Ui::FunctionAreaWidget
{
    Q_OBJECT
    
public:
    explicit FunctionAreaWidget(QWidget *parent = 0);
	void addData(const QPixmap &foreground, const QString &name);

    void setImage(const QPixmap &image);
    void setName(const QString &name);

    QString getName() const {return name_;}
    QPixmap getForeGroundImage() const { return fgImage_; }

signals:
    void signalClick();

protected:
    void changeEvent(QEvent *e);
	void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
	void enterEvent(QEvent *);
	void leaveEvent(QEvent *);

private:
    void initSetting();

private:
	bool hover_;
    QPixmap fgImage_;
    QString name_;
};

#endif // FUNCTIONWIDGET_H
