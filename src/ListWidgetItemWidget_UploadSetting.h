#ifndef LISTWIDGETITEM_2_H
#define LISTWIDGETITEM_2_H

#include "ui_ListWidgetItemWidget_UploadSetting.h"

class ListWidgetItemWidget_UploadSetting : public QWidget, private Ui::ListWidgetItemWidget_UploadSetting
{
    Q_OBJECT

public:
    explicit ListWidgetItemWidget_UploadSetting(const QString &name, QWidget *parent = 0);
    void setText(const QString &text);
    void setText();
    void setClicked(bool click);
    void setColor(const QColor &color);

protected:
    void changeEvent(QEvent *e);
    void paintEvent(QPaintEvent * event);

private:
    QString name_;
    QString type_;
    bool bClicked_;
};

#endif // LISTWIDGETITEM_2_H
