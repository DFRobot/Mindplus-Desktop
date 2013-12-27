#ifndef LISTWIDGETITEM_H
#define LISTWIDGETITEM_H

#include <QListWidgetItem>
#include "DataStruct.h"

class ListWidgetItemWidget_Component;

class ListWidgetItem : public QObject, public QListWidgetItem
{
    Q_OBJECT
public:
    explicit ListWidgetItem(ListWidgetItemWidget_Component *p);
    ListWidgetItemWidget_Component *pWidget_;
    DataStruct data_;

signals:

public slots:

private:
};

#endif // LISTWIDGETITEM_H
