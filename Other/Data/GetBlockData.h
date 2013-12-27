#ifndef GETBLOCKDATA_H
#define GETBLOCKDATA_H

#include <QObject>
#include "DataStruct.h"

class GetBlockData : public QObject
{
	Q_OBJECT
public:
	explicit GetBlockData(QObject *parent = 0);
	static DataStruct getBlockData(const QString &blockPath);
};

#endif // GETBLOCKDATA_H
