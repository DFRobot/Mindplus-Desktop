#include "ListWidgetItemWidget_Photo.h"

ListWidgetItemWidget_Photo::ListWidgetItemWidget_Photo(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
}

void ListWidgetItemWidget_Photo::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
        case QEvent::LanguageChange:
            retranslateUi(this);
            break;
        default:
            break;
    }
}
