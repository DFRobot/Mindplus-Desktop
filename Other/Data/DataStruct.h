#ifndef DATASTRUCT_H
#define DATASTRUCT_H
#include <QVector>
#include <QString>

struct BehaviorIn
{
	bool isEmpty()
	{
		return name.isEmpty();
	}
    int id;
    QString name;
    bool bVisible;
    QString imagePath;
    QString toolTip;
};

struct BehaviorOut
{
	bool isEmpty()
	{
		return name.isEmpty();
	}
    int id;
    QString name;
    bool bVisible;
    QString imagePath;
    QString toolTip;
};

struct Code
{
    QString codeInclude;
    QString codeClass;
    QString codeParameter;
    QString codeSetup;
    QString codePreWork;
    QString codeMainWork;
    QString codeLastWork;
    QString codeVoid;
};

struct ParamIn
{
	bool isEmpty()
	{
		return name.isEmpty();
	}
    int id;
    QString name;
    QString type;
    QString value;
    bool bVisble;
    QString imagePath;
    QString uiType;
    QString toolTip;
};

struct ParamOut
{
	bool isEmpty()
	{
		return name.isEmpty();
	}
	int id;
    QString name;
    QString type;
    bool bVisble;
    QString imagePath;
    QString uiType;
    QString toolTip;
};

struct UI
{
	bool isEmpty()
	{
		return name.isEmpty();
	}
    QString fileName;
    QString name;
    int nameOffsetX;
    int nameOffsetY;
    int sizeX;
    int sizeY;
    QString type;
    QString tag;
    bool bVisible;
    int doubleClick;
    QByteArray ImagePath;
    int imageOffsetX;
    int imageOffsetY;
    QString toolTip;
};

struct Description
{
    QByteArray imageData;
    QString text;
};

struct DataStruct
{
	bool isEmpty()
	{
		return (behaviorIn.isEmpty() & behaviorOut.isEmpty() & paramIn.isEmpty() & paramOut.isEmpty());
	}

    Code code;      //代码
    UI ui;                  //root
    QVector<BehaviorIn> behaviorIn;
    QVector<BehaviorOut> behaviorOut;
    QVector<ParamIn> paramIn;
    QVector<ParamOut> paramOut;
    Description description;
};

#endif // DATASTRUCT_H
