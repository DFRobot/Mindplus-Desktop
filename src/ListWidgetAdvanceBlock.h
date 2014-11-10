#ifndef LISTWIDGETADVANCEBLOCK_H
#define LISTWIDGETADVANCEBLOCK_H

#include "ListWidget.h"

class ListWidgetAdvanceBlock : public ListWidget
{
    Q_OBJECT
public:
    explicit ListWidgetAdvanceBlock(QWidget *parent = 0);

signals:
    void signalShowHelp(const QString &blockName);

protected:
    void mousePressEvent(QMouseEvent *event);
};

#endif // LISTWIDGETADVANCEBLOCK_H
