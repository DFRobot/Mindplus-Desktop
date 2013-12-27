#ifndef WIDGETSHOWSCENE_H
#define WIDGETSHOWSCENE_H

#include <QWidget>
#include "Other/Data/DataStruct.h"
class ListWidget;
class EditScene;
class OperationsManagement;
//graphic scene就加载在此
class WidgetShowScene : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetShowScene(QWidget *parent = 0);
    void setScenePointer(EditScene *p);

protected:
    //谁能想到, 竟然会出现这种行为不一致的事情发生呢
    void showEvent(QShowEvent *event);

private:
    EditScene *pEditScene_;
	OperationsManagement *pView_;
};

#endif // WIDGETSHOWSCENE_H
