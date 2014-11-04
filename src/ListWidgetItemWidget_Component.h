#ifndef LISTITEMWIDGT_FORM_H
#define LISTITEMWIDGT_FORM_H

#include "ui_ListWidgetItemWidget_Component.h"

class ListWidgetItemWidget_Component : public QWidget, private Ui::ListWidgetItemWidget_Component
{
    Q_OBJECT

public:
    explicit ListWidgetItemWidget_Component(const QString &name, QWidget *parent);
    QString getName() const { return name_; }
    void setEnabledHoverEvent(bool b){ bEnableHoverEvent_ = b;}
    void setIntroduceInfor(const QPixmap &image, const QString &text);

signals:
    void signalIntroduce(const QPixmap &image, const QString &text);

protected:
    void changeEvent(QEvent *e);
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);

private slots:

private:
    void initGui();

private:
    QString name_;
    bool bEnableHoverEvent_;
    QPixmap image_;
    QString text_;
};

#endif // LISTITEMWIDGT_FORM_H
