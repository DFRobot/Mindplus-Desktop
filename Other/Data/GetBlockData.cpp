#include "GetBlockData.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QSqlRecord>
#include <QFileInfo>

GetBlockData::GetBlockData(QObject *parent)
	: QObject(parent)
{
}

DataStruct GetBlockData::getBlockData(const QString &blockPath)
{
	if(blockPath.contains("Buffer.mpb"))
	//if(blockPath.contains("buffer.dll"))
	{
		return DataStruct();
	}
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	//qDebug() << "这个地方路径有错?" << blockPath;
	db.setDatabaseName(blockPath);

	if(!db.open())
	{
		return DataStruct();
	}

	DataStruct data;
	QString cmd;
	QSqlQuery query(db);
	//中间
	{
		cmd = QString("select * from ui");
		//qDebug() << cmd;
		query.exec(cmd);
		while (query.next())
		{
			QString blockFileName = QFileInfo(blockPath).baseName();
			data.ui.fileName = blockFileName;
			data.ui.name = query.value(0).toString();
			data.ui.nameOffsetX = query.value(1).toInt();
			data.ui.nameOffsetY = query.value(2).toInt();
			data.ui.sizeX = query.value(3).toInt();
			data.ui.sizeY = query.value(4).toInt();
			data.ui.type = query.value(5).toString();
			data.ui.tag = query.value(6).toString();
			data.ui.bVisible = query.value(7).toBool();
			data.ui.doubleClick = query.value(8).toInt();
			data.ui.ImagePath = query.value(9).toByteArray();

			if(data.ui.ImagePath.isEmpty())
			{
				//qDebug() << "读取数据的时候没有图片数据";
			}

			data.ui.imageOffsetX = query.value(10).toInt();
			data.ui.imageOffsetY = query.value(11).toInt();
		}
	}
	//左
	{
		cmd = QString("select * from behaviorIn");
		//qDebug() << cmd;
		query.exec(cmd);

		while (query.next())
		{
			BehaviorIn Bi;
			Bi.id = query.value(0).toInt();
			Bi.name = query.value(1).toString();
			Bi.bVisible = query.value(2).toBool();
			QString imgPath = query.value(3).toString();
			Bi.toolTip = query.value(4).toString();

			if(imgPath.isEmpty())
			{
				imgPath = "./resource/images/UI_Block_BI.png";
				//qDebug() << "图片没有数据 bi";
			}
			Bi.imagePath = imgPath;
			data.behaviorIn.append(Bi);
		}
	}
	//右
	{
		cmd = QString("select * from behaviorOut");
		//qDebug() << cmd;
		query.exec(cmd);

		while (query.next())
		{
			BehaviorOut Bo;
			Bo.id = query.value(0).toInt();
			Bo.name = query.value(1).toString();
			Bo.bVisible= query.value(2).toBool();
			QString imgPath = query.value(3).toString();
			Bo.toolTip = query.value(4).toString();

			if(imgPath.isEmpty())
			{
				imgPath = "./resource/images/UI_Block_BO.png";
				//qDebug() << "图片没有数据 bo";
			}
			Bo.imagePath = imgPath;
			data.behaviorOut.append(Bo);
		}
	}
	//上
	{
		cmd = QString("select * from paramIn");
		//qDebug() << cmd;
		query.exec(cmd);

		while (query.next())
		{
			ParamIn Pi;
			Pi.id = query.value(0).toInt();
			Pi.name = query.value(1).toString();
			Pi.type = query.value(2).toString();
			Pi.value = query.value(3).toString();
			Pi.bVisble = query.value(4).toBool();
			QString imgPath = query.value(5).toString();
			Pi.uiType = query.value(6).toString();
			Pi.toolTip = query.value(7).toString();
			if(imgPath.isEmpty())
			{
				imgPath = "./resource/images/UI_Block_Pin.png";
				//qDebug() << "图片没有数据 pin";
			}
			Pi.imagePath = imgPath;
			data.paramIn.append(Pi);
		}
	}
	//下
	{
		cmd = QString("select * from paramOut");
		query.exec(cmd);
		while (query.next())
		{
			ParamOut Po;
			Po.id = query.value(0).toInt();
			Po.name = query.value(1).toString();
			Po.type = query.value(2).toString();

			Po.bVisble = query.value(3).toBool();
			QString imgPath = query.value(4).toString();
			Po.uiType = query.value(5).toString();
			Po.toolTip = query.value(6).toString();

			if(imgPath.isEmpty())
			{
				imgPath = "./resource/images/UI_Block_Pout.png";
				//qDebug() << "图片没有数据 pout";
			}
			Po.imagePath = imgPath;
			data.paramOut.append(Po);
		}
	}
	//额外描述信息
	{
		cmd = QString("select * from description");
		//qDebug() << cmd;
		query.exec(cmd);
		if(query.next())
		{
			data.description.imageData = query.value(1).toByteArray();
			data.description.text = query.value(2).toString();
			data.ui.toolTip = query.value(2).toString();
		}
	}

	db.close();

	return data;
}

