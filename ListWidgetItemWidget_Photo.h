#ifndef LISTWIDGETITEMWIDGET_PHOTO_H
#define LISTWIDGETITEMWIDGET_PHOTO_H

#include "ui_ListWidgetItemWidget_Photo.h"

class ListWidgetItemWidget_Photo : public QWidget, private Ui::ListWidgetItemWidget_Photo
{
    Q_OBJECT
    
public:
    explicit ListWidgetItemWidget_Photo(QWidget *parent = 0);
    
protected:
    void changeEvent(QEvent *e);
};

#endif // LISTWIDGETITEMWIDGET_PHOTO_H
