#ifndef COMMON_H
#define COMMON_H
///一些公共的声明
#include <QObject>

const int FOCUS_LINE = 1;
const int FOCUS_GROUP = 2;

const int DIR_PATH = 0x0100 + 1;
const int NORMAL = 0x1;
const int HOVER = 0x10;
const int PRESSED = 0x100;

const int MAX_WIDTH = 8460;
const int MAX_HIGHT = 5970;

namespace ListWidgetItemData
{
	const int index = Qt::UserRole;
	const int blockName = Qt::UserRole + 1;
}

#endif // COMMON_H
