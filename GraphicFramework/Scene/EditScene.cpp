#include "EditScene.h"
#include <QDrag>
#include <QMimeData>
#include <QGraphicsSceneDragDropEvent>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QGraphicsSceneMouseEvent>
#include <QInputDialog>
#include <QMessageBox>
#include <QLineF>
#include <QPainterPath>
#include <QGraphicsProxyWidget>
#include <QDir>
#include <QVariant>
#include <QMutex>
#include <QMutexLocker>
#include <qmath.h>
#include <QTimer>
#include <QGraphicsView>
#include <QApplication>
#include <QKeyEvent>
#include <QFocusEvent>
#include <QMimeData>
#include <QPainter>
#include <QSettings>
#include <QScrollBar>

#include "CompleteLineEdit.h"
#include "DatabaseEditComponent.h"
#include "ParameterItem.h"
#include "BehaviourItem.h"
#include "FlowLine.h"
#include "StartItem.h"
#include "RootItem.h"
#include "GraphicsItemBase.h"
#include "GraphicsItermGroup.h"
#include "LockIconItem.h"
#include "DataStruct.h"
#include "FunctionAreaWidget.h"
#include "Animation.h"
#include "MindKitPushButton.h"
#include "WidgetMain.h"
#include "ListWidget.h"

const int NOT_FINDE = -1;
const int NAME = 1;
const int POS_X = 2;
const int POS_Y = 3;

//MIN_CELL 最小单位,现在设定是20*20
int const MIN_CELL = 10;
int const MAX_ROW = 65;
int const MAX_COLUMN = 103;

int const POS_START = 0;
int const POS_END = 1;
int const POS_ROADBLOCK = 2;
int const POS_PATH = 3;

int const TYPE_CURRENT = 0;
int const TYPE_UNKONWN = 1;
int const TYPE_OPEN = 2;
int const TYPE_CLOSE = 3;
int const TYPE_ROADBLOCK = 4;
int const TYPE_START = 5;
int const TYPE_END = 6;

bool mcmp(Node *lhs, Node *rhs)//mark
{
	return (*lhs).f < (*rhs).f;
}

EditScene::EditScene(QObject *parent)
	: QGraphicsScene(parent)
	, bbName_ ("")
	, bGrid_(false)
	, bScrawl_(false)
	, bHoverStart_(false)
	, bScrawlPath_(false)
	, bMouseMove_(false)
{
	initData();
	initGui();
}

EditScene::EditScene(const QRectF &sceneRect, QObject *parent)
	: QGraphicsScene(sceneRect, parent)
	, bbName_("")
	, bGrid_(false)
	, bScrawl_(false)
	, bHoverStart_(false)
	, bScrawlPath_(false)
	, bMouseMove_(false)
{
	initData();
	initGui();
}

/*!
 * \brief EditScene::setGridSize 设置寻路网格大小
 * \param size 大小的QSize
 */
void EditScene::setGridSize(const QSize &size)
{
	setGridSize(size.width(), size.height());
	//pDustbinItem_.data()->setPos(this->width() - 50, 50);
}

/*!
 * \brief EditScene::setGridSize 设置寻路网格大小(重载)
 * \param width 宽度
 * \param height 高度
 */
void EditScene::setGridSize(int width, int height)
{
	int w = width;
	int h = height;
	w = w / 10 * 10;
	h = h / 10 * 10;
	gridWidth_ = w;
	gridHeight_ = h;
	qDebug() << "scene width:" << gridWidth_ << "height:" << gridHeight_;
}

void EditScene::setListWidgetModulePointer(ListWidget *p)
{
	pListWidgetModule_ = p;
}

void EditScene::setListWidgetIntroducePointer(ListWidget *p)
{
	pListWidgetIntroduce_ = p;
}

void EditScene::setReset()
{
	if(!this->items().isEmpty())
	{
		//清空全部item然后加入开始和水印
		//this->clear();
		//怀疑是事件传递的构成中对象完成析构导致崩溃
		foreach (GraphicsItermGroup *p, list_graphicsItermGroup_)
		{
			p->deleteGroupItem();
			delete p;
		}
		this->clearAllGraphicsGroup();
		//开始

		pDatabaseEditComponent_->clearData();

		//刚才没有清空这里导致出错....
		list_graphicsItermGroup_.clear();
		hash_component_count_.clear();
		paramterCount = 0;
		hash_BBParam_index.clear();
		//hash_Name_ItemSaveInfor.clear();
		hash_Name_LineSaveInfor.clear();
		hash_Name_Paramter_.clear();
		hash_name_item_pointer_.clear();
		//hash_name_item_pointer_[tr("start")] = pStartItem_;
		list_line_.clear();
		this->updateGridNodeData();
	}

	update();
}

void EditScene::saveFile(const QString &filePath)
{
	//打开文件
	//保存数据库
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "save");
	db.setDatabaseName(filePath);

	if(!db.open())
	{
		qDebug()<<tr("svae data can't open!!!!!")<<endl;
	}
	///打开数据库就创建表
	QSqlQuery query(db);
	//创建模块信息的表, 每一个模块需要名字, 编号, 以及其坐标
	query.exec("create table items ("
			   "name text ,"
			   "id int ,"
			   "x int,"
			   "y int)");
	//连线记录的表
	query.exec("create table lines("
			   "startName text ,"
			   "endName text) ");
	//记录了模块的统计数(只能加不会减)
	query.exec("create table number("
			   "name text ,"
			   "count text)");
	//记录参数的值的表
	query.exec("create table parameter("
			   "name text ,"
			   "value text)");

	query.exec("DELETE FROM items");
	//query.exec("delete from linkage");
	query.exec("delete from lines");
	query.exec("delete from number");
	query.exec("delete from parameter");

	//数据库中填充模块名字和位置
	QSqlDatabase::database().transaction();

	for(int i = 0; i != list_graphicsItermGroup_.size(); ++i)
	{
		//        QString name = list_graphicsItermGroup_.at(i)->getRootName();
		//        QStringList tmp = name.split("_");
		//        if(!tmp.isEmpty())
		//        {
		//            name = tmp[0];
		//        }
		QString name = list_graphicsItermGroup_.at(i)->getBlockName();
		query.prepare("INSERT INTO items (name, id, x, y) "
					  "VALUES (?,?,?,?)");
		query.bindValue(0, name);
		query.bindValue(1, list_graphicsItermGroup_.at(i)->getGroupId());
		query.bindValue(2, list_graphicsItermGroup_.at(i)->scenePos().toPoint().x());
		query.bindValue(3, list_graphicsItermGroup_.at(i)->scenePos().toPoint().y());
		query.exec();
	}
	//填线的信息
	QHash<QString, LineSaveInfor>::iterator iter1;
	for(iter1 = hash_Name_LineSaveInfor.begin(); iter1 != hash_Name_LineSaveInfor.end(); ++iter1)
	{
		LineSaveInfor lineinfor = iter1.value();
		qDebug() << lineinfor.startName << lineinfor.endName;
		query.prepare("INSERT INTO lines (startName, endName) "
					  "VALUES (?,?)");
		query.bindValue(0, lineinfor.startName);
		query.bindValue(1, lineinfor.endName);
		query.exec();
	}
	//填模块统计数
	QHash<QString, int>::iterator iter2;
	for(iter2 = hash_component_count_.begin(); iter2 != hash_component_count_.end(); ++iter2)
	{
		QString name = iter2.key();
		int count = iter2.value();

		qDebug() << "模块" <<name << "统计数为" << count;
		query.prepare("INSERT INTO number (name, count) "
					  "VALUES (?,?)");
		query.bindValue(0, name);
		query.bindValue(1, count);
		query.exec();
	}
	QSqlQuery query3 = pDatabaseEditComponent_->selectParameter();
	while (query3.next())
	{
		QString value = query3.value(0).toString();
		QString name = query3.value(1).toString();
		qDebug() << "paramter------" << name << value;
		query.prepare("INSERT INTO parameter (name, value) "
					  "VALUES (?,?)");
		query.bindValue(0, name);
		query.bindValue(1, value);
		query.exec();
	}
	QSqlDatabase::database().commit();
	db.close();
}

/*!
 * \brief 创建联线（paramIn和paramOut链接）
 * \param startName
 * \param endName
 * \param startPos
 * \param endPos
 * \param pStartItem
 * \param pEndItem
 */
void EditScene::createLine(const QString &startName,const QString &endName, const QPointF &startPos, const QPointF &endPos, GraphicsItemBase *pStartItem , GraphicsItemBase *pEndItem)
{
	if(!startName.isNull() && startPos != endPos)
	{
		//这里正式开始连线
		//先是数据库部分
		if(startName != endName)
		{
			if(startName.indexOf("LocalParameter") != -1)
			{
				pDatabaseEditComponent_->insertLinker(startName, endName);
			}
			else if( endName.indexOf("LocalParameter") != -1)
			{
				pDatabaseEditComponent_->insertLinker(startName, endName);
			}
			else
			{
				qDebug() << "param链接失算";
			}
		}
		QPainterPath path;
		LineSaveInfor lineInfor;

		lineInfor.startName = startName;
		lineInfor.endName = pEndItem->data(ITEM_NAME).toString();

		//连线寻路测试
		path = this->findPath(endPos , startPos
							  ,pStartItem->getFindPathPointEnd()
							  ,pEndItem->getFindPathPointEnd());

		if(!path.isEmpty())
		{
			//移动连线的两端到时候, 让线自动重连
			GraphicsItermGroup *pEndGroup = static_cast<GraphicsItermGroup *>(pEndItem->parentItem());
			GraphicsItermGroup *pStartGroup = static_cast<GraphicsItermGroup *>(pStartItem->parentItem());
			FlowLine *pMyLine = new FlowLine(path, pStartItem, pEndItem);

			list_line_.append(pMyLine);

			connect(pEndGroup, SIGNAL(signalGroupCurrentPos(QPointF)), pMyLine, SLOT(slotEndItemMoveOffset(QPointF)));
			connect(pStartGroup, SIGNAL(signalGroupCurrentPos(QPointF)), pMyLine, SLOT(slotStartItemMoveOffset(QPointF)));
			connect(pMyLine, SIGNAL(signalDeleteLine(FlowLine*)), pStartGroup, SLOT(slotDeleteLine(FlowLine*)));
			connect(pMyLine, SIGNAL(signalDeleteLine(FlowLine*)), pEndGroup, SLOT(slotDeleteLine(FlowLine*)));
			connect(pMyLine, SIGNAL(signalFocusIn(FlowLine*,QString,QString)),
					pWidgetMain_, SLOT(slotFocusInLine(FlowLine*,QString,QString)));
			connect(this, SIGNAL(signalFocusOut()), pWidgetMain_, SLOT(slotFocusOut()));

			if(NULL != pStartGroup
					&& pStartGroup == pEndGroup)
			{
				pStartGroup->addConnectSelfLine(pMyLine);
			}
			else
			{
				if(NULL != pStartGroup)
				{
					pStartGroup->addConnectSelfLine(pMyLine);
				}
				if(NULL != pEndGroup)
				{
					pEndGroup->addConnectSelfLine(pMyLine);
				}
			}

			QStringList tmpList1 = startName.split("_");
			QStringList tmpList2 = endName.split("_");
			//qDebug() <<"startName_:" << tmpList1[2] <<"endName_:"<<  tmpList2[2];
			if(startName == "start")
			{
				pMyLine->setBothendsName(startName, tmpList2[0]+"_"+tmpList2[1]);
			}
			else if(endName == "start")
			{
				pMyLine->setBothendsName(tmpList1[0]+"_"+tmpList1[1], endName);
			}
			else
			{
				pMyLine->setBothendsName(startName, endName);
			}

			hash_Name_LineSaveInfor.insertMulti(pMyLine->getName(), lineInfor);
			this->addItem(pMyLine);
			pMyLine->setZValue(-1);
		}
	}
}

/*!
 * \brief 非param之间的联线（behavior之间或者behavior和start）
 * \param pStartItem 联线起点模块指针
 * \param pEndItem 联线终点模块指针
 */
void EditScene::createLine(GraphicsItemBase *pStartItem, GraphicsItemBase *pEndItem)
{
	if(pStartItem != NULL && pEndItem != NULL && pStartItem != pEndItem)
	{
		////////////////////一笔画
		{
			//先填写占用情况, 小心start
			if(pStartItem->parentItem())
			{
				GraphicsItermGroup *pGroup = static_cast<GraphicsItermGroup *>(pStartItem->parentItem());
				int index= pGroup->map_behaviourOutPointer_index_[pStartItem];
				if(index >= 0
						&& index <= pGroup->listBehaviourInUse_.size())
				{
					pGroup->listBehaviourOutUse_[index] = true;
					pGroup->listBehaviourOut_[index] = static_cast<BehaviourItem *>(pStartItem);
				}
			}

			if(pEndItem->parentItem())
			{
				GraphicsItermGroup *pGroup = static_cast<GraphicsItermGroup *>(pEndItem->parentItem());
				int index = pGroup->map_behaviourInPointer_index_[pEndItem];
				if(index >= 0
						&& index <= pGroup->listBehaviourInUse_.size())
				{
					pGroup->listBehaviourInUse_[index] = true;
					pGroup->listBehaviourIn_[index] = static_cast<BehaviourItem *>(pEndItem);
				}
			}
		}
		//这里正式开始连线
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		////先是填充数据库部分
		QString startName = pStartItem->getName();
		QString endName = pEndItem->getName();
		qDebug() << "连线的两端~~ startName:" <<startName << endName;
		if("start" == startName)
		{
			pDatabaseEditComponent_->insertLinker("Start", endName);//因为翻译引擎的原因, 这里必须是大写的
		}
		else if("start" == endName)
		{
			pDatabaseEditComponent_->insertLinker("Start", startName);////因为翻译引擎的原因, 这里必须是大写的
		}
		else
		{
			//这里在做判断谁在左边谁在右边, 根据模块的名字进行排序, 保证bout的后续是bin, pout的后续是pin
			//先分割出部件名
			QStringList tmpList1 = startName.split("_");
			QStringList tmpList2 = endName.split("_");
			qDebug() <<"startName_:" << tmpList1[2] <<"endName_:"<<  tmpList2[2];
			if(tmpList1[2] < tmpList2[2])
			{
				pDatabaseEditComponent_->insertLinker(startName, endName);
			}
			else
			{
				pDatabaseEditComponent_->insertLinker(endName, startName);
			}
		}
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		///////////显示部分

		LineSaveInfor lineInfor;
		QPoint startPos = pStartItem->getFindPathPoint();
		QPoint endPos = pEndItem->getFindPathPoint();
		QPainterPath path = this->findPath(startPos , endPos
										   , pStartItem->getFindPathPointEnd()
										   ,pEndItem->getFindPathPointEnd());

		lineInfor.startName = startName;
		lineInfor.endName = endName;

		if(!path.isEmpty())
		{
			//移动连线的两端到时候, 让线自动重连
			FlowLine *pMyLine = new FlowLine(path, pStartItem, pEndItem);

			connect(pMyLine, SIGNAL(signalFocusIn(FlowLine*,QString,QString)), pWidgetMain_,
					SLOT(slotFocusInLine(FlowLine*,QString,QString)));
			connect(this, SIGNAL(signalFocusOut()), pWidgetMain_, SLOT(slotFocusOut()));

			GraphicsItermGroup *pStartGroup = NULL;
			if(pStartItem->data(Qt::UserRole+4).toString() != "start")
			{
				pStartGroup = static_cast<GraphicsItermGroup *>(pStartItem->parentItem());
				connect(pStartGroup, SIGNAL(signalGroupCurrentPos(QPointF)), pMyLine, SLOT(slotStartItemMoveOffset(QPointF)));
				connect(pMyLine, SIGNAL(signalDeleteLine(FlowLine*)), pStartGroup, SLOT(slotDeleteLine(FlowLine*)));
			}

			GraphicsItermGroup *pEndGroup = NULL;
			if(pEndItem->data(Qt::UserRole+4).toString() != "start")
			{
				pEndGroup = static_cast<GraphicsItermGroup *>(pEndItem->parentItem());
				connect(pEndGroup, SIGNAL(signalGroupCurrentPos(QPointF)), pMyLine, SLOT(slotEndItemMoveOffset(QPointF)));
				connect(pMyLine, SIGNAL(signalDeleteLine(FlowLine*)), pEndGroup, SLOT(slotDeleteLine(FlowLine*)));
			}

			list_line_.append(pMyLine);
			//把线添加到Group中, 每个group记录有所有连接自身的线
			if(NULL != pStartGroup
					&& pStartGroup == pEndGroup)
			{
				pStartGroup->addConnectSelfLine(pMyLine);
			}
			else
			{
				if(NULL != pStartGroup)
				{
					pStartGroup->addConnectSelfLine(pMyLine);
				}
				if(NULL != pEndGroup)
				{
					pEndGroup->addConnectSelfLine(pMyLine);
				}
			}

			QStringList tmpList1 = startName.split("_");
			QStringList tmpList2 = endName.split("_");
			//qDebug() <<"startName_:" << tmpList1[2] <<"endName_:"<<  tmpList2[2];
			if(startName == "start")
			{
				pMyLine->setBothendsName(startName, tmpList2[0]+"_"+tmpList2[1]);
			}
			else if(endName == "start")
			{
				pMyLine->setBothendsName(tmpList1[0]+"_"+tmpList1[1], endName);
			}
			else
			{
				pMyLine->setBothendsName(tmpList1[0]+"_"+tmpList1[1], tmpList2[0]+"_"+tmpList2[1]);
			}
			lineInfor.startName = startName;
			lineInfor.endName = endName;
			//这里要存储多个值
			hash_Name_LineSaveInfor.insertMulti(pMyLine->getName(), lineInfor);
			this->addItem(pMyLine);
			//this->update();
			pMyLine->setZValue(-1);
		}
	}
}

void EditScene::setComponentCount(const QString &name, int count)
{
	hash_component_count_[name] = count;
}

void EditScene::setParameterValue(const QString &name, const QString &value)
{
	if(hash_Name_Paramter_.contains(name))
	{
		ParameterItem *p = hash_Name_Paramter_[name];
		p->setValue(value);
	}
}

//寻路用的函数
//给定起点和终点, 返回适合的路径
QPainterPath EditScene::findPath(const QPointF &startPos, const QPointF &endPos, const QPointF &PathStartPos, const QPointF &PathEndPos)
{
	qDebug() << "寻路起点!!!:" << startPos<<"寻路终点~~:" << endPos;
	qDebug() << "路径起点!!!:" <<PathStartPos << "路径终点~:" << PathEndPos;
	//清空A*寻路的相关信息
	openList.clear();
	closeList.clear();

	int x1 = startPos.x();
	int y1 = startPos.y();
	int x2 = endPos.x();
	int y2 = endPos.y();

	this->updateGridNodeData();

	if(x1 > 4080 || x1 < 0 || y1 > 2600 || y1 < 0 || x2 > 4080|| x2 < 0 || y2 > 2600 || y2 < 0)
	{
		qDebug() << "超出下标";
		return QPainterPath();
	}
	qDebug()<< "数组非整数么?" <<y2/MIN_CELL << x2/MIN_CELL;
	Node *p = &matrixNode_[y2/MIN_CELL][x2/MIN_CELL];
	if(NULL == p)
	{
		return QPainterPath();
	}

	{
		if(p->type == POS_ROADBLOCK)
		{
			qDebug() << "终点是路障, 你是无论如何到找不到路径的.....";
			return QPainterPath();
		}
		else
		{
			int roadBlockNum = 0;
			int x = p->x / 10;
			int y = p->y / 10;

			for(int i = -1; i != 2; ++i)
			{
				for(int j = -1; j != 2; ++j)
				{
					if(y+i > 260 || x+j > 408 || y+i <0 || x+j < 0)
					{
						continue;
					}

					if(i == 0 && j == 0)
					{//在这里还能做点边界判断
						continue;
					}

					if(matrixNode_[y+i][x+j].type == TYPE_ROADBLOCK)
					{
						++roadBlockNum;
					}
				}
			}
			if(8 == roadBlockNum )
			{
				return QPainterPath();
			}
		}
	}

	p->type = TYPE_END;

	//初始化终点
	endNode_.x = x2;
	endNode_.y = y2;

	//初始化起点
	startNode_.x = x1;
	startNode_.y = y1;

	qDebug() << "寻路起点和终点22222: " << startPos << endPos;

	startNode_.f = 0;
	startNode_.g = 0;
	startNode_.h = getManhattan(startNode_, endNode_);

	//路障在鼠标事件中初始化了
	openList.push_back(&startNode_);
	qSort(openList.begin(), openList.end(), mcmp);

	while (!openList.isEmpty())
	{
		qSort(openList.begin(), openList.end(), mcmp);
		//寻找开启列表中F值最低的格子
		Node *pCurrentNode = openList.front();//还需要pop弹出来
		//从开放列表中删除
		openList.pop_front();
		pCurrentNode->type = TYPE_CLOSE;
		//添加到关闭列表
		closeList.push_back(pCurrentNode);
		//处理相邻的八个格子
		int x = pCurrentNode->x / 10;
		int y = pCurrentNode->y / 10;
		//qDebug() << x << y;
		matrixNode_[y][x].type = TYPE_CLOSE;
		//qDebug() << "新的起点:" << "(" <<  matrixNode_[y][x].x << "," << matrixNode_[y][x].y << ")";

		for(int i = -1; i != 2; ++i)
		{
			for(int j = -1; j != 2; ++j)
			{
				//边界问题
				if(y+i > 260 || x+j > 408 || y+i <0 || x+j < 0)
				{
					continue;
				}

				if(i == 0 && j == 0)
				{//在这里还能做点边界判断
					continue;
				}
				//跳过不可通过的(路障), 已经在closeList中的
				if(matrixNode_[y+i][x+j].type == TYPE_ROADBLOCK || matrixNode_[y+i][x+j].type  == TYPE_CLOSE)
				{
					continue;
				}

				//如果不在openList中(type==UNKNOWN)->加入openList设置parent并记录f,g,h
				if(TYPE_UNKONWN == matrixNode_[y+i][x+j].type)
				{
					matrixNode_[y+i][x+j].type = TYPE_OPEN;
					matrixNode_[y+i][x+j].parent = &matrixNode_[y][x];

					//计算H的值
					matrixNode_[y+i][x+j].h = getManhattan(matrixNode_[y+i][x+j], endNode_);

					//计算g的值,斜边的f是14,水平竖直是10
					if( i == 0 || j == 0)
					{
						//matrixNode_[y+i][x+j].g = 100000;
						matrixNode_[y+i][x+j].g = 10;
					}
					else
					{
						matrixNode_[y+i][x+j].g = 1400000;
						//matrixNode_[y+i][x+j].g = 14;
					}
					matrixNode_[y+i][x+j].f = matrixNode_[y+i][x+j].g + matrixNode_[y+i][x+j].h;
					openList.push_back((Node *)&matrixNode_[y+i][x+j]);
				}
				/*
				*如果在openList中,用G值参考检查新的路径是否更好
				*如果保持openList按F值排序,改变后需要重新对openList排序
				 */
				if(TYPE_OPEN == matrixNode_[y+i][x+j].type)
				{

					int g = matrixNode_[y][x].g;
					if(i == 0 || j == 0)
					{
						//g += 100000;
						g += 10;
					}
					else
					{
						g += 1400000;
						//g += 14;
					}
					if(g < matrixNode_[y+i][x+j].g)
					{//如果是这样,就把这一格的父节点改成当前格,并且重新计算这一格的G和F值.
						matrixNode_[y+i][x+j].parent = &matrixNode_[y][x];
						matrixNode_[y+i][x+j].g = g;
						matrixNode_[y+i][x+j].f = g + matrixNode_[y+i][x+j].h;
					}
				}
				else if(TYPE_END == matrixNode_[y+i][x+j].type)
				{
					matrixNode_[y+i][x+j].parent = &matrixNode_[y][x];
					endNode_ = matrixNode_[y+i][x+j];
					//qDebug() << "success!!!" <<" " << "(" <<matrixNode_[y+i][x+j].x << "," <<matrixNode_[y+i][x+j].y << ")";
					Node *p = &endNode_;
					QPainterPath path;
					qDebug() << "很是奇怪啊路径起点" <<QPoint(PathStartPos.x(), PathStartPos.y()) << "寻路起点" << QPoint(startPos.x(), startPos.y());
					qDebug() << "很是奇怪啊路径终点" <<QPoint(PathEndPos.x(), PathEndPos.y()) << "寻路终点" << QPoint(endPos.x(), endPos.y());
					//终点的偏移
					path.moveTo(PathEndPos.x()+5, PathEndPos.y()-5);

					//////将p中的点灌入到数组m_points里 方便处理曲线化
					QVector<QPointF> m_points;
					//////////////第一个节点添加坐标不对 所以多加一次 跳过第一个结点   +5修正视觉偏移
					m_points.append(QPointF(PathEndPos.x()+5, PathEndPos.y()-5));
					m_points.append(QPointF(PathEndPos.x()+5, PathEndPos.y()-5));
					while (p != NULL)
					{
						m_points.append(QPointF(p->x+5, p->y-5));
						qDebug() << QPointF(p->x+5, p->y-5);
						p = p->parent;
					}
					//起点的偏移
					m_points.append(QPointF(PathStartPos.x()+5, PathStartPos.y()-5));

					//////////////////////////
					int i=0;
					//调整曲线


					while (i + 2 < m_points.size()-1)
					{
						path.cubicTo(m_points.at(i), m_points.at(i+1), m_points.at(i+2));
						i += 3;
					}

					while (i < m_points.size())
					{
						path.lineTo(m_points.at(i).x(), m_points.at(i).y());
						i ++;
					}

					//this->update();
					//qDebug() << path;
					return path;
				}
			}
		}

		if(0 == openList.size())
		{
			qDebug() << trUtf8("没有找到路径");
			return QPainterPath();
		}
	}
	return QPainterPath();
}

QPainterPath EditScene::findLinePath(const QPointF &startPos, const QPointF &endPos)
{
	QPainterPath path;
	path.moveTo(startPos);
	path.lineTo(endPos- QPoint(0, 5) + QPoint(5, 0));
	return path;
}

void EditScene::updateGridNodeData()
{
	//重建网格
	//qDebug() << "这里是正常的001";
	//qDebug() <<"height"<< gridHeight_ << "width"<< gridWidth_;
	for(int i = 0; i <=  gridHeight_/10 &&i != 261; ++i)
	{
		for(int j = 0; j <= gridWidth_/10 && i != 409; ++j)
		{
			matrixNode_[i][j].x = j * MIN_CELL;                    //MIN_CELL 最小单位,现在设定是10*10
			matrixNode_[i][j].y = i * MIN_CELL;
			matrixNode_[i][j].type = TYPE_UNKONWN;
			matrixNode_[i][j].parent = NULL;
		}
	}

	//遍历所有的group, 填写自身Rect信息(每一个group连其周围一圈都是路障)
	GraphicsItermGroup *pItem;
	foreach (pItem, list_graphicsItermGroup_)
	{
		if(pItem == NULL)
		{
			continue;
		}
		//现在开始需要填表了
		int sizeX = pItem->getSize().width() / 10;
		int sizeY = pItem->getSize().height() / 10;
		int xPos = pItem->scenePos().x();
		int yPos = pItem->scenePos().y();
		qDebug() << "坐标:" << xPos << "," << yPos << "尺寸" << sizeX << sizeY << "原始" << pItem->getSize().width() << pItem->getSize().height();

		//在这里把group连带外部的一圈的整十坐标全部设置成为路障了
		for(int i = 1; i < sizeY; ++i)
		{
			for(int j = 1; j < sizeX; ++j)
			{
				if((i + yPos / MIN_CELL) < 0 || ( j + xPos / MIN_CELL) < 0 || (i + yPos / MIN_CELL) > 260 || (j + xPos / MIN_CELL) > 408)
				{
					continue;
				}
				if(POS_ROADBLOCK != matrixNode_[yPos/MIN_CELL+i][xPos/MIN_CELL+j].type)
				{
					//qDebug() << "要设置障碍在点"  <<xPos/MIN_CELL+j <<","  << yPos/MIN_CELL+i;
					matrixNode_[yPos/MIN_CELL+i][xPos/MIN_CELL+j].type = POS_ROADBLOCK;
				}
			}
		}
	}//end for foreach(listItem)
	//qDebug() << "这里是正常的004";
}

//这里是删除单个group使用的
void EditScene::deleteGraphicsGroup(GraphicsItermGroup *p, const QString &name)
{
	//pDustbinItem_.data()->fadeOut();
	emit signalFocusOut();
	pDatabaseEditComponent_->deleteComponent(name);

	if(list_graphicsItermGroup_.contains(p))
	{
		for(int i = 0; i != list_graphicsItermGroup_.size(); ++i)
		{
			if(list_graphicsItermGroup_.at(i) == p)
			{
				list_graphicsItermGroup_[i] = NULL;
				list_graphicsItermGroup_.removeAt(i);
				break;
			}
		}
	}
	this->updateGridNodeData();
}

void EditScene::clearAllGraphicsGroup()
{
	pDatabaseEditComponent_->clearData();
	list_graphicsItermGroup_.clear();
}

void EditScene::setWidgetMain(WidgetMain *p)
{
	pWidgetMain_ = p;
	connect(this, SIGNAL(signalFocusOut()), pWidgetMain_, SLOT(slotFocusOut()));
}

void EditScene::dragMoveEvent(QGraphicsSceneDragDropEvent *event)
{
	if(event->source() == (QWidget *)pListWidgetModule_
			|| event->source() == (QWidget *)pListWidgetIntroduce_
			|| event->source() == (QWidget *)pMindKitPushButton_
			|| list_listWidgetPointer_.contains(event->source()))
	{
		event->accept();
		event->setDropAction(Qt::CopyAction);
	}
	else
	{
		QGraphicsScene::dragMoveEvent(event);
	}
}

void EditScene::dropEvent(QGraphicsSceneDragDropEvent *event)
{
	if(event->source() == (QWidget *)pMindKitPushButton_)
	{
		qDebug() << "是 MindKitPushButton放下";
		bbName_ = event->mimeData()->text();
		qDebug() << "这货是什么?" << bbName_;
		emit signalCreateComponent(event->scenePos(), bbName_, -1, false, "", "");
	}
	else
	{
		bbName_ = event->mimeData()->text();
		emit signalCreateComponent(event->scenePos(), bbName_, -1,  false, "", "");
		qDebug() << "这货是什么?" << bbName_;
		if(event->source() == (QWidget *)pListWidgetIntroduce_)
		{
			//emit signalShowSubWindows(); //留着以后或许会用到
		}
	}

	QGraphicsScene::dropEvent(event);
}

/*!
 * \brief EditScene::keyPressEvent press键盘按键时候的处理
 *\主要处理Esc, delete, ctrl, alt, shift这几种事件
 * \param event 键盘触发事件
 */
void EditScene::keyPressEvent(QKeyEvent *event)
{
	if(Qt::Key_Escape == event->key())
	{
		qDebug() << "Press Esc";
		event->accept();

		if(KeyNull == keyType_
				&& pNewGroup_)
		{
			deleteGraphicsGroup(pNewGroup_, pNewGroup_.data()->getRootName());
			pNewGroup_.data()->deleteLater();
			pNewGroup_ = NULL;
		}
		qDebug() << "esc pressed !";
		this->update();
	}
	else if(Qt::Key_Control == event->key())
	{
		qDebug() << "Press Ctrl";
		event->accept();
		keyType_ = KeyCtrlPress;
	}
	else if(Qt::Key_Shift == event->key())
	{
		qDebug() << "Press Shift";
		event->accept();
		keyType_ = KeyShiftPress;
	}
	else if(Qt::Key_Alt == event->key())
	{
		qDebug() << "Press Alt";
		event->accept();
		keyType_ = KeyAltPress;

		//开启一笔画模式
		//bScrawl_ = true;
	}
	else
	{
		qDebug() << "Press Others";
		event->ignore();
		QGraphicsScene::keyPressEvent(event);
		keyType_ = KeyOthersPress;
	}
}

/*!
 * \brief EditScene::keyReleaseEvent release键盘按键时候的处理
 * \param event 键盘触发事件
 *\see 函数::keyPressEvent
 */
void EditScene::keyReleaseEvent(QKeyEvent *event)
{
	keyType_ = KeyNull;
	if(Qt::Key_Escape == event->key())
	{
		qDebug() << "release Esc";
		event->accept();
		keyType_ = KeyEscPress;
	}
	else if(Qt::Key_Control == event->key())
	{
		qDebug() << "release Ctrl";
		event->accept();
	}
	else if(Qt::Key_Shift == event->key())
	{
		qDebug() << "release Shift";
		event->accept();
	}
	else if(Qt::Key_Alt == event->key())
	{
		qDebug() << "release Alt";
		bScrawl_ = false;
		bScrawlPath_ = false;
		scrawlPath_ = QPainterPath();
		connectList_.clear();
		event->accept();
	}
	else
	{
		event->ignore();
		QGraphicsScene::keyReleaseEvent(event);
	}
}

void EditScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	bMouseMove_ = true;
#if QT_VERSION < 0x050000
	QGraphicsItem *pItem = this->itemAt(event->scenePos());
#else
	QGraphicsItem *pItem = this->itemAt(event->scenePos(), QTransform());
#endif
	if(keyType_ != KeyNull
			&& NULL != pItem)
	{//按下键盘并且选中模块的时候, 是要拖拽移动,复制模块了
		if (event->button() == Qt::LeftButton)
		{
			dragStartPosition_ = event->scenePos();
			if(tr("group") == pItem->parentItem()->data(ITEM_TYPE).toString())
			{
				dragOffset_ = dragStartPosition_ - pItem->parentItem()->scenePos();
			}
		}
		else
		{
			dragStartPosition_ = QPointF();
			dragOffset_ = QPointF();
		}
	}
	else
	{//一般鼠标按下的情况
		qDebug()<< "按下点的坐标" << event->scenePos();
		startName_.clear();
		endName_.clear();
		pLineStartItem_ = NULL;
		clearFocus();
		clearSelection();

		if(NULL == pItem
				/*|| pItem->data(Qt::UserRole+4).toString() == "group"*/)
		{//点击到空白主要处理两件事, 第一个就是隐藏掉已经show出来的搜索框, 第二个就是判断是否选中线
			if(pProxyCompleteWidget_->isVisible())
			{//隐藏已经显示的搜索框
				pProxyCompleteWidget_->hide();
				pCompleteLineEdit_->clear();
				update();
			}

			{
				qDebug() << "should hide the dustbin";
				emit signalFocusOut();
			}
			this->clearSelection();
			/////////////////////////////////////////////////////////////////
			/////////////选中线, 换一种思路, 用contains
			foreach (FlowLine *p, list_line_)
			{//先遍历所有的线, 选出坐标在线的矩形区域内的线
				if(p->contains(event->scenePos().toPoint()))
				{
					p->setSelected(true);
					qDebug() << "设置线的焦点使其接收键盘事件";
					p->setFocus(Qt::MouseFocusReason);
				}
				if(p->isSelected())
				{
					pLineDrag_ = p;
					bSelectLine_ = true;
					lineStartPos_ = event->scenePos().toPoint();
					sectionIndex_ = getLineSectionIndex(event->scenePos().toPoint(), p);
					dragDirection_ = getDirection(sectionIndex_);
					switch (dragDirection_)
					{
						case Horizontal:
						{
							qDebug() << "只可以左右移动";
							break;
						}
						case Vertical:
						{
							qDebug() << "只可以上下移动";
							break;
						}
						case None:
						{
							qDebug() << "草这是什么？";
							break;
						}
						default:
							break;
					}

					p->sendSelected();
					return;
				}
			}
			bMoveView_ = true;
			moveViewStartPoint_ = event->scenePos().toPoint();
		}
		else if(pItem->data(ITEM_TYPE).toString() == "root")
		{
			qDebug() << "点中的是root";
			Q_EMIT signalFocusInGroup(pItem->data(ITEM_NAME).toString());
			bDrag_ = true;
		}
		else if(pItem->data(Qt::UserRole+4).toString() == "line")
		{
			qDebug() << "线~~~~~~~~~~~";
			bSelectLine_ = true;
			lineStartPos_ = event->scenePos().toPoint();

			FlowLine *p = static_cast<FlowLine *>(pItem);
			pLineDrag_ = p;

			sectionIndex_ = getLineSectionIndex(event->scenePos().toPoint(), p);
			dragDirection_ = getDirection(sectionIndex_);

			switch ( dragDirection_ )
			{
				case Horizontal:
				{
					qDebug() << "只可以左右移动";
					break;
				}
				case Vertical:
				{
					qDebug() << "只可以上下移动";
					break;
				}
				case None:
				{
					qDebug() << "草这是什么？";
					break;
				}
				default:
					break;
			}

			p->setSelected(true);
			p->setFocus();
			p->sendSelected();
			return;
		}

		QString type = pItem->data(ITEM_TYPE).toString();
		if("param" == type || "behaviour" == type || "start" == type)
		{//草没有注释我自己差点都看不懂这两个的区别了
			qDebug() << "按下是" << type;
			startName_ = pItem->data(ITEM_NAME).toString();
			pLineStartItem_ = static_cast<GraphicsItemBase *>(pItem);
			//startPos_ = pLineStartItem_.data()->getFindPathPoint();
			startPos_ = pLineStartItem_->getFindPathPointEnd();
			qDebug() << "起点坐标是~~~~: " << startPos_;
			bDragLine_ = true;
			//区分数据线还是行为线的颜色
			if("param" == type)
			{
				qDebug() << "red line";
				pCurrentFlowLine_ = new FlowLine(QPainterPath(), startPos_, startPos_, "LocalParameter_");
			}
			else
			{
				qDebug() << "blue line";
				pCurrentFlowLine_ = new FlowLine(QPainterPath(), startPos_, startPos_, "");
			}
			pCurrentFlowLine_.data()->setZValue(-1);
			this->addItem(pCurrentFlowLine_);
		}
		else if("root" == type)
		{
			qDebug() << "按下是root";
		}
		else
		{
			qDebug() << "你妹出现意料之外的名字了";
		}

		QGraphicsScene::mousePressEvent(event);
	}
}

void EditScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	if(bMoveView_)
	{
		if ((event->scenePos() - moveViewStartPoint_).manhattanLength()
				< QApplication::startDragDistance())
			return;

		QTransform viewTransform = views().first()->transform();
		auto m11 = viewTransform.m11();

		QPoint offset = (event->scenePos() - moveViewStartPoint_).toPoint();
		offset = QPoint(offset.x()*m11, offset.y()*m11);

		auto offsetTest = moveViewOffset_ + QPoint(offset.x(), offset.y());

		if(offsetTest.x() <= 0
				|| offsetTest.y() <= 0)
		{
			if(offsetTest.x() <= 0
					&& offsetTest.y() > 0)
			{
				views().first()->scroll(offset.x(), 0);
				moveViewOffset_ += QPoint(offset.x(), 0);
			}
			else if(offsetTest.x() > 0
					&& offsetTest.y() <= 0)
			{
				views().first()->scroll(0, offset.y());
				moveViewOffset_ += QPoint(0, offset.y());
			}
			else
			{
				views().first()->scroll(offset.x(), offset.y());
				moveViewOffset_ += QPoint(offset.x(), offset.y());
			}

			qDebug() << "scroll:" <<moveViewOffset_ << "offset:" << offset.x() << offset.y();
			Q_EMIT signalViewOffset(moveViewOffset_);
			views().first()->resize(QSize(this->width(), this->height()));
		}
	}
	if(bScrawl_)
	{
		qDebug() << "一笔画模式";
		if(!bScrawlPath_)
		{
			scrawlPath_.moveTo(event->scenePos());
			bScrawlPath_ = true;
		}
		scrawlPath_.lineTo(event->scenePos());
		//这里为了显示绘制在Scene的前景色的一笔画的路径,必须保留
		this->update();
#if QT_VERSION < 0x050000
		GraphicsItemBase *pItem = static_cast<GraphicsItemBase *>(itemAt(event->scenePos()));
#else
		GraphicsItemBase *pItem = static_cast<GraphicsItemBase *>(itemAt(event->scenePos(), QTransform()));
#endif
		if(NULL != pItem)
		{
			GraphicsItermGroup *pGroup = NULL;

			if("root" == pItem->data(ITEM_TYPE).toString()
					|| "behavior" == pItem->data(ITEM_TYPE).toString()
					|| "parma" == pItem->data(ITEM_TYPE).toString())
			{
				//需要其parent转化
				if(pItem->group())
				{
					pGroup = static_cast<GraphicsItermGroup *>(pItem->group());
				}
			}
			else if("start" == pItem->data(ITEM_NAME).toString())
			{
				bHoverStart_ = true;
			}
			//            else if("group" == pItem->data(ITEM_TYPE).toString())
			//            {
			//                //直接转化
			//                pGroup = static_cast<GraphicsItermGroup *>(pItem);
			//            }
			else if("line" == pItem->data(ITEM_TYPE).toString())
			{
				//不予理睬
			}
			else
			{
				qDebug() << "纳尼, 又有这种匪夷所思的事情发生";
			}

			if(NULL != pGroup)
			{
				if(connectList_.isEmpty())
				{
					connectList_.append(pGroup);
				}
				else if(!connectList_.isEmpty()
						&& connectList_.at(connectList_.size()-1) != pGroup)
				{
					connectList_.append(pGroup);
				}
			}
			else
			{
				qDebug() << "pGroup is null !!!!!!";
			}
		}
	}
	else if(bDragLine_)
	{
		//qDebug() << "拖线";
		int x = event->scenePos().x();
		int y = event->scenePos().y();

#if QT_VERSION < 0x050000
		GraphicsItemBase *pItem = static_cast<GraphicsItemBase *>(itemAt(event->scenePos()));
#else
		GraphicsItemBase *pItem = static_cast<GraphicsItemBase *>(itemAt(event->scenePos(), QTransform()));
#endif

		QString type = pItem->data(ITEM_TYPE).toString();
		//然后这里还可以有一个类型匹配的, behaviour和behaviour连接, param和param连接, start和behaviour
		if(!type.isEmpty()
				&& (type == "param" || type == "behaviour" || type == "start"))
		{
			if(!bLock_)
			{
				if(pItem != pLineStartItem_)
				{
					pLockIconItem_->setPos(event->scenePos()/* - QPoint(10, 10)*/);
					pLockIconItem_->setData(ITEM_NAME, pItem->data(ITEM_NAME).toString());
					pLockIconItem_->addEndItem(pItem);
					bLock_ = true;
					pLockIconItem_->show();
					pLockIconItem_->setRePoint(pItem->scenePos().toPoint()+pItem->getCenterPoint());

					QApplication::setOverrideCursor(QCursor(tr("./resource/images/common/transparentCursor.png")));

					Animation::posAnimation(pLockIconItem_, 150, (event->scenePos().toPoint()), (pItem->scenePos().toPoint()+pItem->getCenterPoint()));
					Animation::opacityAnimation(pLockIconItem_, 150, 0, 1);

				}
				else
				{
					//qDebug() << "拖动起点是不应该出现动画的";
				}
			}
		}

		if(pItem->data(ITEM_NAME).toString() != pLockIconItem_->data(ITEM_NAME).toString()
				&& pItem != (QGraphicsItem *)pLockIconItem_)
		{
			if(bLock_)
			{
				Animation::posAnimation(pLockIconItem_, 150, (pLockIconItem_->getRePoint()), (event->scenePos().toPoint()));
				Animation::opacityAnimation(pLockIconItem_, 150, 1, 0);
				QApplication::restoreOverrideCursor();
			}
			//this->update();
			bLock_ = false;
		}

		if(endPosX != x
				|| endPosY != y)
		{
			endPosX = x;
			endPosY = y;

			//然后线就寻路
			if(pCurrentFlowLine_)
			{
				//自动吸附的情况下, 连线终点被定格, 不是自动吸附的情况下连线的 终点是随着鼠标自由变化
				if(bLock_)
				{
					//自动吸附只在param,behavior,start有用
					if(pItem->data(ITEM_TYPE).toString() == "behaviour"
							|| pItem->data(ITEM_TYPE).toString() == "param"
							|| pItem->data(ITEM_TYPE).toString() == "start")
					{
						pCurrentFlowLine_.data()->setLinePath(this->findLinePath(pItem->scenePos().toPoint() + QPoint(pItem->getWidth()/2, pItem->getheight()/2), startPos_));
					}
				}
				else
				{
					pCurrentFlowLine_.data()->setLinePath(this->findLinePath(QPointF(endPosX, endPosY), startPos_));
				}
				//这里如去掉的话,在拖线出来的时候就会有重影,因为没有重绘
				update();
			}
		}
	}
	else if(KeyCtrlPress == keyType_
			|| KeyShiftPress == keyType_
			/*|| KeyAltPress == keyType_*/)
	{
		qDebug() << "复制或者拖动";
		if (!(event->buttons() & Qt::LeftButton))
		{
			return;
		}
		if ((event->scenePos() - dragStartPosition_).manhattanLength()
				< QApplication::startDragDistance())
		{
			return;
		}

#if QT_VERSION < 0x050000
		QGraphicsItem *pItem = this->itemAt(event->scenePos());
#else
		QGraphicsItem *pItem = this->itemAt(event->scenePos(), QTransform());
#endif

		//处理移动和复制
		if(NULL != pItem
				&& "group" == pItem->parentItem()->data(ITEM_TYPE))
		{
			if(!bCreateGroup_)
			{//这里是让新创建的group
				pOldGroup_ = static_cast<GraphicsItermGroup *>(pItem->parentItem());
				QPointF pos =pOldGroup_->scenePos();
				if(!pOldGroup_)
				{
					qDebug() << "pOldGroup_ is Null!";
					return;
				}
				QString newGroupName =pOldGroup_->getRootName();
				QStringList tmpList = newGroupName.split("_");
				if(!tmpList.isEmpty())
				{
					newGroupName = tmpList[0];
				}

				pNewGroup_ = createItemGroup(pos, newGroupName, -1, false, "", "" );
				//赋值
				(*pNewGroup_) = (*pOldGroup_);
				bCreateGroup_ = true;
			}
		}
		if(pNewGroup_
				&& !dragOffset_.isNull())
		{//跟随鼠标移动
			pNewGroup_.data()->setHandlesChildEvents(true);
			pNewGroup_.data()->setOffsetMousePosToGroupLeftTop(dragOffset_);
			pNewGroup_.data()->addMouseMoveEvent(event);
		}
	}
	else if(KeyNull == keyType_)
	{//移动的情况
		//qDebug() << "移动";
		if(pNewGroup_
				&& !dragOffset_.isNull())
		{
			pNewGroup_.data()->setHandlesChildEvents(true);
			pNewGroup_.data()->setOffsetMousePosToGroupLeftTop(dragOffset_);
			pNewGroup_.data()->addMouseMoveEvent(event);
		}
	}

	QGraphicsScene::mouseMoveEvent(event);
	//this->update();
}

void EditScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	bScrawl_ = false;//关闭一笔画模式

	bMoveView_  = false;

	if(bSelectLine_)
	{
		//处理线的移动的
		QPoint offset = event->scenePos().toPoint() - lineStartPos_;
		offset = QPoint((offset.x()/10*10), (offset.y()/10*10));
		qDebug() << "没有移动？？？" << (offset == QPoint(0,0)) << (sectionIndex_) << lineSections_.size();
		if( offset != QPoint(0,0)
				&& sectionIndex_ >= 0
				&& (sectionIndex_ < lineSections_.size()))
		{
			QPainterPath section = lineSections_.at(sectionIndex_);

			auto fristPos = section.elementAt(0);
			auto endPos = section.elementAt(section.elementCount()-1);
			qDebug() << fristPos << endPos;

			//要确定前后的线段，这些需要重新连接
			QPoint startPoint(0,0);
			QPoint endPoint(0,0);
			{
				if(0 == sectionIndex_
						&& lineSections_.size() - 1 == sectionIndex_)
				{
					qDebug() <<  "这里不需要动";
					startPoint = QPoint(fristPos.x+10, fristPos.y);
					endPoint = QPoint(endPos.x, endPos.y);
					jiaoshenme(startPoint, endPoint, offset, sectionIndex_);
				}
				else
				{
					if(0 == sectionIndex_)
					{
						//第一段
						//要重新寻路第二段 用第一段的尾部进行判断
						if(sectionIndex_+1 < lineSections_.size())
						{
							QPainterPath ttt = lineSections_.at(sectionIndex_ + 1);
							getRefindPoint(section.elementAt(0), ttt.elementAt(0), ttt.elementAt(ttt.elementCount()-1), startPoint, endPoint);
							qDebug() << "是所期待的结果么？" << startPoint << endPoint;
							jiaoshenme(startPoint , endPoint, offset, sectionIndex_ + 1);
						}
					}
					else if(lineSections_.size() - 1 == sectionIndex_)
					{
						//最后一段,要寻路倒数第二段
						qDebug() << "要查在这里";
						if(sectionIndex_ > 0)
						{
							QPainterPath ttt = lineSections_.at(sectionIndex_ - 1);

							getRefindPoint(section.elementAt(0), ttt.elementAt(0), ttt.elementAt(ttt.elementCount()-1), startPoint, endPoint);
							qDebug() << "是所期待的结果么？" << startPoint << endPoint;
							jiaoshenme(startPoint , endPoint, offset,  sectionIndex_ - 1);
						}
					}
					else
					{
						//在中间要重新寻路前面一段和后面一段
						if(sectionIndex_+1 < lineSections_.size())
						{//后面一段
							QPainterPath ttt = lineSections_.at(sectionIndex_ + 1);

							getRefindPoint(section.elementAt(0), ttt.elementAt(0), ttt.elementAt(ttt.elementCount()-1), startPoint, endPoint);
							qDebug() << "是所期待的结果么？" << startPoint << endPoint;
							qDebug() << "后面一段" << startPoint << endPoint;
							jiaoshenme(startPoint , endPoint, offset,  sectionIndex_ + 1);
						}
						if(sectionIndex_ > 0)
						{//前面一段
							QPainterPath ttt = lineSections_.at(sectionIndex_ - 1);

							getRefindPoint(section.elementAt(0), ttt.elementAt(0), ttt.elementAt(ttt.elementCount()-1), startPoint, endPoint);
							qDebug() << "是所期待的结果么？" << startPoint << endPoint;
							qDebug() << "前面一段" << startPoint << endPoint;
							jiaoshenme(startPoint , endPoint, offset, sectionIndex_ - 1);
						}
					}
				}
			}

			//			if(Horizontal == dragDirection_)
			//			{
			//				qDebug() << "左右移动";
			//				for(int i = 0; i != section.elementCount(); ++i)
			//				{
			//					auto pos = section.elementAt(i);
			//					section.setElementPositionAt(i, pos.x+offset.x(), pos.y);
			//				}
			//			}
			//			else if(Vertical == dragDirection_)
			//			{
			//				qDebug() << "上下移动";
			//				for(int i = 0; i != section.elementCount(); ++i)
			//				{
			//					auto pos = section.elementAt(i);
			//					section.setElementPositionAt(i, pos.x, pos.y + offset.y());
			//				}
			//			}
			//			else
			//			{
			//				qDebug() << "None 移动";
			//			}

			//			{
			//				QPainterPath path1;
			//				path1.moveTo(fristPos.x, fristPos.y);
			//				path1.lineTo(section.elementAt(0).x, section.elementAt(0).y);

			//				QPainterPath path2;
			//				path2.moveTo(endPos.x, endPos.y);
			//				path2.lineTo(section.elementAt(section.elementCount()-1).x, section.elementAt(section.elementCount()-1).y);
			//				section.addPath(path1);
			//				section.addPath(path2);
			//			}

			lineSections_.replace(sectionIndex_, section);
			QPainterPath newPath;
			for(int i = 0; i != lineSections_.size(); ++i)
			{
				newPath += lineSections_.at(i);
			}
			if(pLineDrag_
					&& 0 != newPath.elementCount())
			{
				pLineDrag_->setLinePath(newPath);
				update();
			}
			else
			{
				qDebug() << "pLineDrag_ = NULL or newPath is empty";
			}
		}

		//还原数据
		lineOffsetX_ = 0;
		lineOffsetY_ = 0;
		lineStartPos_ = QPoint();
		bSelectLine_ = false;
	}

	bMouseMove_ = false;
	bScrawlPath_ = false;
	scrawlPath_ = QPainterPath();
	{
		if(1 < connectList_.size()
				|| (1 == connectList_.size() && bHoverStart_))//要两两连接,所以至少要两个
		{
			//两两连接
			//先来点前奏, 如果有start的话
			{
				if(bHoverStart_)
				{
					GraphicsItermGroup *pGroup = connectList_.at(0);
					BehaviourItem *pEndItem = NULL;
					for(int i = 0; i != pGroup->listBehaviourInUse_.size(); ++i)
					{
						if(!pGroup->listBehaviourInUse_.at(i))
						{
							pEndItem = pGroup->listBehaviourIn_.at(i);
							break;
						}
					}
					if(pEndItem)
					{
						createLine(pStartItem_, pEndItem);

					}
					bHoverStart_ = false;
				}
			}
			for(int i = 0; i != connectList_.size()-1; ++i)
			{
				BehaviourItem *pStartItem = NULL;
				BehaviourItem *pEndItem = NULL;

				GraphicsItermGroup *pFristGroup = connectList_.at(i);
				GraphicsItermGroup *pSecondGroup = connectList_.at(i+1);
				//进行连接的代码
				{
					for(int i = 0; i != pFristGroup->listBehaviourOutUse_.size(); ++i)
					{
						if(!pFristGroup->listBehaviourOutUse_.at(i))
						{
							//找到没有被占用的出口
							pStartItem = const_cast<BehaviourItem *>(pFristGroup->listBehaviourOut_.at(i));

							break;
						}
					}
					for(int i = 0; i != pSecondGroup->listBehaviourInUse_.size(); ++i)
					{
						if(!pSecondGroup->listBehaviourInUse_.at(i))
						{
							//找到没有被占用的入口
							pEndItem = const_cast<BehaviourItem *>(pSecondGroup->listBehaviourIn_.at(i));
							break;
						}
					}
					if(NULL != pStartItem
							&& NULL != pEndItem)
					{
						createLine(pStartItem, pEndItem);
					}
					else if (bHoverStart_
							 /*|| (NULL == pStartItem && NULL != pEndItem)*/)
					{
						//先来一段前奏, 先连接start相关的, 如果start被经过的话
						if(bHoverStart_)
						{
							//////////
							createLine(pStartItem_, pEndItem);
							bHoverStart_ = false;
						}
					}
				}
				//判断是否没有出口
				if(!pSecondGroup->isHaveBehaviorOut())
				{
					break;
				}
			}

			connectList_.clear();
		}
	}
#if QT_VERSION < 0x050000
	GraphicsItemBase *pReleaseItem = static_cast<GraphicsItemBase *>(this->itemAt(event->scenePos()));
#else
	GraphicsItemBase *pReleaseItem = static_cast<GraphicsItemBase *>(this->itemAt(event->scenePos(), QTransform()));
#endif
	if(KeyNull == keyType_)
	{
		QPointF tmp;

		if(pNewGroup_)
		{

			tmp = pNewGroup_.data()->scenePos();
			deleteGraphicsGroup(pNewGroup_, pNewGroup_.data()->getRootName());
			pNewGroup_.data()->deleteLater();
			pNewGroup_ = NULL;
		}
		if(pOldGroup_)
		{
			if(!tmp.isNull())
			{
				pOldGroup_.data()->setPos(tmp);
				pOldGroup_.data()->sendGroupCurrentPos();
				pOldGroup_.data()->setHandlesChildEvents(true);
				pOldGroup_.data()->addMouseReleaseEvent(event);
				pOldGroup_ = NULL;
			}
		}
	}
	else if(KeyEscPress == keyType_)
	{
		qDebug() << "这里应该什么都不干";
		keyType_ = KeyNull;
	}
	else if(KeyCtrlPress == keyType_
			/*&& KeyAltPress == keyType_*/)
	{

	}
	if(pNewGroup_)
	{
		pNewGroup_ = NULL;
	}
	if(pOldGroup_)
	{
		pOldGroup_ = NULL;
	}
	bCreateGroup_ = false;
	dragStartPosition_ = QPointF();
	dragOffset_ = QPointF();

	QApplication::restoreOverrideCursor();
	if(NULL == pReleaseItem)
	{   //崩溃的原因来自这里, 这里本意是想发出信息更变的通知的
		if(bDrag_)
		{//如果是拖动模块
			foreach (GraphicsItermGroup *p, list_graphicsItermGroup_)
			{
				p->sendGroupCurrentPos();
			}
		}

		if(bDragLine_)
		{//如果是拖线出来
			//这里应该释放刚才那条线的资源了
			if(pCurrentFlowLine_)
			{
				this->removeItem(pCurrentFlowLine_);
				delete pCurrentFlowLine_;
				bDragLine_ = false;
				this->update();
			}
		}

		return;
	}
	qDebug() << pReleaseItem->data(Qt::UserRole +4).toString() << "asjdhaakjsdaksjdhaksjdh";
	//过滤自身
	if(pLineStartItem_ == pReleaseItem)
	{
		qDebug() << "在自身释放~";
		if(bDragLine_)
		{//如果是拖线出来
			//这里应该释放刚才那条线的资源了
			if(pCurrentFlowLine_)
			{
				this->removeItem(pCurrentFlowLine_);
				delete pCurrentFlowLine_;
				bDragLine_ = false;
				this->update();
			}
		}
		return;
	}

	bDrag_ = false;
	bDragLine_ = false;
	if(pCurrentFlowLine_)
	{
		this->removeItem(pCurrentFlowLine_);
		delete pCurrentFlowLine_;
		bDragLine_ = false;
		if(bLock_)
		{
			qDebug() << "yao yinchangqilai";
			//pLockIconItem_->hide();
			Animation::opacityAnimation(pLockIconItem_, 150, 1, 0);
			bLock_ = false;
		}
		this->update();
	}

	QString endDetailType = pReleaseItem->data(ITEM_TYPE_DETAIL).toString();
	qDebug() << endDetailType << "endType!!!!!!!!";
	//因为自动吸附的锁定框会挡住下面的目标item 所以需要预先处理一下
	if("lockItem" == endDetailType)
	{
		LockIconItem *p =  static_cast<LockIconItem *>(pReleaseItem);
		pReleaseItem = p->getEndItem();        //取得锁定框挡住的item的指针(被盖在它的下面)
		endDetailType = pReleaseItem->data(ITEM_TYPE_DETAIL).toString();
	}

	QString startDetailType = pLineStartItem_->data(ITEM_TYPE_DETAIL).toString();

	if(startDetailType == "parameterIn"
			&& endDetailType == "parameterIn")
	{
		qDebug() << "好吧开干";
		QString startName = tr("LocalParameter_") + pDatabaseEditComponent_->getParamterId(pLineStartItem_->data(ITEM_NAME).toString());
		QString endName = tr("LocalParameter_") + pDatabaseEditComponent_->getParamterId(pReleaseItem->data(ITEM_NAME).toString());

		this->addLinePreprocess(pLineStartItem_, pReleaseItem, startName, endName);
		//endName对应的要被startName替代
		int index = endName.right(1).toInt();

		QString bbName = pDatabaseEditComponent_->getPrameterOwnerBBName(index);
		pReleaseItem->setData(Qt::UserRole+26, bbName);
		int bbbb = pReleaseItem->data(Qt::UserRole+27).toInt();

		pDatabaseEditComponent_->updateBBlist(bbName, bbbb, startName.right(1).toInt());
		//Animation::opacityAnimation(pReleaseItem, 200, 1, 0);
		ParameterItem *p = static_cast<ParameterItem *>(pReleaseItem);
		p->setHide(true);
		p->update();
	}
	else if(startDetailType == "parameterIn"
			&& endDetailType == "parameterOut")
	{//parameterIn只能和parameterOut相连
		qDebug() << pReleaseItem->data(ITEM_TYPE_DETAIL).toString() << pReleaseItem->data(ITEM_NAME).toString();
		QString a = tr("LocalParameter_") + pDatabaseEditComponent_->getParamterId(pLineStartItem_->data(ITEM_NAME).toString());
		qDebug() << a;

		this->addLinePreprocess(pReleaseItem, pReleaseItem->data(ITEM_NAME).toString() , a);
	}
	else if(startDetailType == "parameterOut"
			&& endDetailType == "parameterIn")
	{
		//这里查表取出param的位置
		QString a = tr("LocalParameter_") + pDatabaseEditComponent_->getParamterId(pReleaseItem->data(ITEM_NAME).toString());
		qDebug() << a;
		this->addLinePreprocess(pReleaseItem,  startName_, a);
	}
	else if("start" == startDetailType
			&& "behaviourIn" == endDetailType)
	{   //下面看起来很冗余的判断实际上是为了修正连线后流动的方向
		qDebug() << "可以释放 behavior";
		if(pLineStartItem_)
		{   //下面看起来很冗余的判断实际上是为了修正连线后流动的方向
			this->addLinePreprocess(pLineStartItem_, pReleaseItem);
		}
	}
	else if("behaviourIn" == startDetailType
			&&"start" == endDetailType)
	{
		if(pLineStartItem_)
		{
			this->addLinePreprocess(pReleaseItem, pLineStartItem_);
		}
	}
	else if("behaviourIn" == startDetailType
			&& "behaviourOut" == endDetailType)
	{
		if(pLineStartItem_)
		{   //下面看起来很冗余的判断实际上是为了修正连线后流动的方向
			this->addLinePreprocess(pReleaseItem, pLineStartItem_);
		}
	}
	else if("behaviourOut" == startDetailType
			&& "behaviourIn" == endDetailType)
	{
		if(pLineStartItem_)
		{   //下面看起来很冗余的判断实际上是为了修正连线后流动的方向
			this->addLinePreprocess(pLineStartItem_, pReleaseItem);
		}
	}
	else
	{
		//不能释放的处理
		qDebug() << "非法释放区域" << pReleaseItem->data(Qt::UserRole).toString();
		if(bDragLine_)
		{//如果是拖线出来
			//这里应该释放刚才那条线的资源了
			if(pCurrentFlowLine_)
			{
				this->removeItem(pCurrentFlowLine_);
				delete pCurrentFlowLine_;
				bDragLine_ = false;
				this->update();
			}
		}
		if(pLineStartItem_)
		{
			pLineStartItem_ = NULL;
		}
		this->update();
	}
	QGraphicsScene::mouseReleaseEvent(event);
}

void EditScene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
#if QT_VERSION < 0x050000
	QGraphicsItem *pItem = this->itemAt(event->scenePos());
#else
	QGraphicsItem *pItem = this->itemAt(event->scenePos(), QTransform());
#endif

	if(NULL == pItem)
	{
		qDebug() << "双击在空白区域, 果断弹出输入框";
		doubleClickPoint_ = event->scenePos() ;
		//        if(!pProxyCompleteWidget_->isVisible())
		//        {
		//            pProxyCompleteWidget_->show();
		//            pProxyCompleteWidget_->setFocus();
		//        }
		if(!pCompleteLineEdit_->isVisible())
		{
			pCompleteLineEdit_->show();
		}
		pProxyCompleteWidget_->setPos(doubleClickPoint_ - QPoint(0, 22));
	}
	else
	{
		QString tmp =  pItem->data(ITEM_TYPE).toString();
		qDebug() << tmp << "双击的类型";
		if("param" == tmp)
		{
			ParameterItem *p = static_cast<ParameterItem *>(pItem);
			p->addMouseDoubleClickEvent(event);
		}
	}
	//QGraphicsScene::mouseDoubleClickEvent(event);
}

/*!
 * \brief 绘制Scene背景目前主要是背景网格
 * \param painter
 * \param rect
 */
void EditScene::drawBackground(QPainter *painter, const QRectF &rect)
{
	Q_UNUSED(rect);

	if(bGrid_)
	{
		QPen pen;

		pen.setColor(QColor(60,60,60));
		pen.setStyle(Qt::DashLine);
		pen.setWidth(1.2);
		painter->setPen(pen);

		for(int i = 0; i != 2610; i += 10)
		{
			painter->drawLine(0, i, 4090, i);
		}

		for(int i = 0; i != 4090; i += 10)
		{
			painter->drawLine(i, 0, i, 2610);
		}
	}
}

/*!
 * \brief 绘制Scene的前景, 一笔画的路径绘制在此
 * \param painter
 * \param rect
 */
void EditScene::drawForeground(QPainter *painter, const QRectF &rect)
{
	Q_UNUSED(rect);

	if(bScrawl_
			&& bMouseMove_)
	{
		QPen pen;

		pen.setColor(QColor(60,60,60));
		pen.setStyle(Qt::DashLine);
		pen.setWidth(6);
		painter->setPen(pen);

		//这里需要一个路径
		painter->drawPath(scrawlPath_);
	}
}

void EditScene::slotSelectItem(const QString &name)
{
	qDebug() << "选择" << name;
	pCompleteLineEdit_->clear();
	pProxyCompleteWidget_->hide();
	pProxyCompleteWidget_->clearFocus();
	emit signalCreateComponent(doubleClickPoint_, name, -1,  false, "", "");
}

void EditScene::slotCompleteEsc()
{
	qDebug() << "complete控件中按下ESC";
	pCompleteLineEdit_->clear();
	pProxyCompleteWidget_->hide();
}

void EditScene::slotReset()
{
	this->setReset();
}

void EditScene::slotLineFocus(FlowLine *p, const QString &startName, const QString &endName)
{
	qDebug() << "要删除线, startName : " << startName  << "endName : " << endName;
	if(p)
	{
		p->deleteLine();
	}
}

void EditScene::slotGroupFocus(const QString &name)
{
	qDebug() << "要删除group: " << name;
	for(int i = 0; i != list_graphicsItermGroup_.size(); ++i)
	{
		if(name == list_graphicsItermGroup_.at(i)->getRootName())
		{
			qDebug() << "找到要删除的group, 删除之" << name;
			list_graphicsItermGroup_.at(i)->deleteGroupItem();
			list_graphicsItermGroup_.removeAt(i);
			return;
		}
	}
}

void EditScene::deleteLine(FlowLine *p, const QString &startName, const QString &endName)
{
	emit signalFocusOut(); //让主窗口隐藏垃圾箱
	//清空对应数据库 -> 主要是linkage表0
	pDatabaseEditComponent_->deleteLinkage(startName, endName);
	//然后删除线相关的东东
	list_line_.removeAll(p);

	//在Scene中移除
	removeItem(p);
	p->deleteLater();
	update();
}

/**
 * @brief EditScene::deleteItem 删除group的记录信息
 * @param name
 */
void EditScene::deleteItem(const QString &name)
{
	if(hash_name_item_pointer_.contains(name))
	{
		hash_name_item_pointer_.remove(name);
	}
	else
	{
		qDebug() << "删除模块各item的时候hash_name_item_pointer_中没有找到对应的name: " << name;
	}
}

GraphicsItemBase *EditScene::getItemPointer(const QString &name)
{
	if(hash_name_item_pointer_.contains(name))
	{
		return hash_name_item_pointer_[name];
	}
	else if(name == "start")
	{
		return pStartItem_;
	}
	else
	{
		qDebug() << "getItemPointer 的时候没有找到对应的name:" << name;
		return NULL;
	}
}

void EditScene::setStartItem(GraphicsItemBase *p)
{
	pLineStartItem_ = p;
	startPos_ = p->getFindPathPoint();
	qDebug() << startPos_;
}

void EditScene::initData()
{
	keyType_ = KeyNull;
	pOldGroup_= NULL;
	pNewGroup_ = NULL;
	bCreateGroup_ = false;

	gridWidth_ = -1;
	gridHeight_ = -1;
	pListWidgetModule_ = NULL;
	pListWidgetIntroduce_ = NULL;
	bSelectLine_ = false;

	lineOffsetX_ = 0;
	lineOffsetY_ = 0;
	pLineDrag_ = NULL;

	memset(&matrixNode_, 0, sizeof(matrixNode_));

	tmpCount = 0;
	bDrag_ = false;
	bDragLine_ = false;
	findFinish_ = 1;
	transparentCursor_.load("./resource/images/common/transparentCursor.png");

	QSettings settingTmp("./resource/setting.ini", QSettings::IniFormat);
	bGrid_ = settingTmp.value(tr("Normal/gridding")).toBool();
	//qDebug() << "gridding is" << value;

	bMoveView_ = false;
	moveViewOffset_ = QPoint(0,0);

	QPixmap pix("./resource/images/common/Cursor.png");
	pLockIconItem_ = new LockIconItem(QRect(0,0,28, 28), pix);
	pLockIconItem_->setData(ITEM_TYPE, "lockIconItem");
	this->addItem(pLockIconItem_);
	pLockIconItem_->setZValue(100);
	pLockIconItem_->hide();

	bLock_ = false;

	//init complete
	pCompleteLineEdit_ = new CompleteLineEdit;
	pProxyCompleteWidget_ = this->addWidget(pCompleteLineEdit_);
	pProxyCompleteWidget_->setData(ITEM_TYPE, "completeWidget");
	pProxyCompleteWidget_->setZValue(10.0);
	pProxyCompleteWidget_->hide();

	paramterCount = 0;
	pDatabaseEditComponent_ = new DatabaseEditComponent(this);

	connect(this, SIGNAL(signalCreateComponent(QPointF,QString,int,bool,QString,QString)), this, SLOT(slotCreateItemGroup(QPointF,QString,int,bool,QString,QString)));
	connect(pCompleteLineEdit_, SIGNAL(signalSelectItem(QString)), this, SLOT(slotSelectItem(QString)));
	connect(pCompleteLineEdit_, SIGNAL(signalEsc()), this, SLOT(slotCompleteEsc()));
}

void EditScene::initGui()
{
	//加入开始按钮
	QPixmap pix(100,40);
	pix.load("./resource/images/bb/Start.png");
	pStartItem_ = new StartItem(QRect(0,0,100,40), pix);
	pStartItem_->setZValue(10000);
	pStartItem_->setPos(0, 255);
	//pStartItem_->setFlag(QGraphicsItem::ItemIsMovable);
	this->addItem(pStartItem_);
	//hash_name_item_pointer_[tr("start")] = pStartItem_;

	this->update();
}

QString EditScene::getParamNewName(const QString &oldName)
{
	if(hash_BBParam_index.contains(oldName))
	{
		hash_BBParam_index[oldName] = ++ hash_BBParam_index[oldName];
	}
	else
	{
		hash_BBParam_index[oldName] = 0;
	}
	QString newName = oldName + "_" + QString::number(hash_BBParam_index[oldName]);
	qDebug() << "加入参数的标志之后的newParamName: " << newName;
	return newName;
}

/*!
 * \brief 添加联线前的预处理（针对paramIn 和paramIn联线,也就是数据共享时)
 * \param pPressItem    起始模块
 * \param pReleaseItem  终点模块
 * \param startName 起始模块名
 * \param endName 终点模块名
 */
void EditScene::addLinePreprocess(GraphicsItemBase *pPressItem, GraphicsItemBase *pReleaseItem, const QString &startName, const QString &endName)
{
	qDebug() << "起始paramIn name : "<< startName;
	qDebug() << "释放paramIn name : " << endName;
	pPressItem->setData(Qt::UserRole+28, startName);
	pReleaseItem->setData(Qt::UserRole+28, endName);

	this->createLine(startName, endName, pReleaseItem->getFindPathPoint(), pPressItem->getFindPathPoint(), pPressItem, pReleaseItem);

	this->update();
}

/*!
 * \brief   添加联线前的预处理（针对paramIn 和paramOut联线）, 主要是名字,位置,还有链接的先后顺序
 * \param pReleaseItem  释放鼠标时候的模块
 * \param startName 起始模块的名字
 * \param endName   终点模块的名字
 */
void EditScene::addLinePreprocess(GraphicsItemBase *pReleaseItem, const QString &startName, const QString &endName)
{
	endPos_ = pReleaseItem->getFindPathPoint();
	endName_ = endName;
	qDebug() << "起始模块名字是: "<< startName;
	qDebug() << "释放时候的模块名字是" << endName_;

	//再到显示线部分
	if(pReleaseItem->data(ITEM_TYPE_DETAIL).toString() == "parameterIn")
	{
		this->createLine(startName, endName_, endPos_, startPos_, pLineStartItem_, pReleaseItem);
	}
	else
	{
		this->createLine(startName, endName_, startPos_, endPos_, pReleaseItem, pLineStartItem_);
	}

	this->update();
}

/*!
 * \brief 添加联线前的预处理（针对behavior联线）, 主要是名字,位置,还有链接的先后顺序
 * \param pStartItem
 * \param pEndItem
 */
void EditScene::addLinePreprocess(GraphicsItemBase *pStartItem, GraphicsItemBase *pEndItem)
{
	startPos_ = pStartItem->getFindPathPoint();
	startName_ = pStartItem->getName();

	endPos_ = pEndItem->getFindPathPoint();
	endName_ = pEndItem->getName();
	this->createLine(pStartItem, pEndItem);
	this->update();
}

/*!
 * \brief 添加模块的tag信息
 * \param data
 */
void EditScene::addModuleTagData(const QMap<QString, QString> &data)
{
	pCompleteLineEdit_->addModulesData(data);
}

void EditScene::setMindKitPushButtonPointer(MindKitPushButton *pointer)
{
	pMindKitPushButton_ = pointer;
}

void EditScene::setBackgroundGrid(bool show)
{
	bGrid_ = show;
}

void EditScene::setInitScroll(int x, int y)
{
	views().first()->resize(QSize(this->width(), this->height()));
	moveViewOffset_ += QPoint(0, -460);
	//views().first()->scroll(x/10*10, y/10*10);
	views().first()->scroll(0, -460);
	views().first()->resize(QSize(this->width(), this->height()));
}

void EditScene::backStart()
{
	views().first()->scroll(-moveViewOffset_.x(), -moveViewOffset_.y());
	moveViewOffset_ = QPoint(0, 0);
	views().first()->resize(QSize(this->width(), this->height()));
}

QStringList EditScene::getComponentsName(const QString &dirPath)
{
	QDir dir(dirPath);
	QStringList filters;
	filters << "Buffer.mpb" << "." << "..";
	//filters << "buffer.dll" << "." << "..";
	dir.setNameFilters(filters);
	dir.setSorting(QDir::Name);	//排序,可有可无

	QStringList tmp;
	foreach (const QString &fileName, dir.entryList())
	{
		QString filePath = dirPath + "/" + fileName;
		QFileInfo infor(filePath);
		tmp.append(infor.baseName());
	}
	return tmp;
}

int EditScene::getManhattan(const Node &s, const Node &e)
{
	//return qAbs(s.x - e.x) + qAbs(s.y - e.y) ;
	//qDebug() << "这里比重似乎过大了" <<s.x << s.y << e.x << e.y;
	return (qAbs(s.x - e.x) + qAbs(s.y - e.y));
	//    int hDiagonal = qMin(qAbs(s.x - e.x), qAbs(s.y - e.y));
	//    int hStraight = qAbs(s.x - e.x) + qAbs(s.y - e.y);
	//    return hDiagonal * 14+ 10* (hStraight - 2*hDiagonal);
}

/*!
 * \brief EditScene::moveGroup 用于移动指定的group到指定坐标
 * \param pGroup 指向要移动的group的指针
 * \param pos 要移动的目的坐标
 */
void EditScene::moveGroup(GraphicsItermGroup *pGroup, const QPointF pos)
{
	pGroup->setPos(pos);
}

QList<QPainterPath> EditScene::getLineSection(QPainterPath path)
{
	QList<QPainterPath> sections;
	const int size = path.elementCount();

	int index = 0;
	auto pos1 = path.elementAt(index);
	auto pos2 = path.elementAt(++index);
	auto pos0 = pos2-pos1;

	while (qFuzzyIsNull(pos0.x())
		   && qFuzzyIsNull(pos0.y())
		   && index+1 < size)
	{
		pos1 = path.elementAt(index);
		pos2 = path.elementAt(++index);
		pos0 = pos2-pos1;
	}

	if(!qFuzzyIsNull(pos0.x())
			&& qFuzzyIsNull(pos0. y()))
	{
		QPainterPath tx = lineSectionX(path, sections, index, size);
		if(tx.elementCount() > 2)
		{
			sections +=tx;
		}
	}
	else if(qFuzzyIsNull(pos0.x())
			&& !qFuzzyIsNull(pos0. y()))
	{
		QPainterPath ty = lineSectionY(path, sections, index, size);
		if(ty.elementCount() > 2)
		{
			sections += ty;
		}
	}

	return sections;
}

QPainterPath EditScene::lineSectionX(QPainterPath path, QList<QPainterPath> &sections, int &index, const int size)
{
	//这样的判断方法是正确的
	QPainterPath tmp;

	auto pos = path.elementAt(index);
	tmp.moveTo(pos.x, pos.y);

	while (index < size)
	{
		auto pos1 = path.elementAt(index);
		if(index+1 >= size)
		{
			break;
		}
		auto pos2 = path.elementAt(++index);
		auto pos0 = pos2 - pos1;

		if(qFuzzyCompare(pos0.x(), pos0.y()))
		{//排除同一点
			continue;
		}
		if(qFuzzyCompare(pos2.x, 55)
				&& qFuzzyCompare(pos2.y, 275))
		{//排除同一点
			continue;
		}
		else if(!qFuzzyIsNull(pos0.x())
				&& qFuzzyIsNull(pos0. y()))
		{//x方向一条直线
			//qDebug()<< "相同直线上" << pos1<< pos2  << "       " << index << "     "<< size ;
			tmp.lineTo(pos2.x, pos2.y);
		}
		else
		{//y方向一条直线
			qDebug()<< "不相同直线上" << pos1<< pos2  << "       " << index << "     "<< size ;
			if(index+1 < size)
			{
				QPainterPath newSection = lineSectionY(path, sections, index, size);
				if(newSection.elementCount() > 2)
				{
					sections += newSection;
				}
			}
		}
	}

	return tmp;
}

QPainterPath EditScene::lineSectionY(QPainterPath path, QList<QPainterPath> &sections, int &index, const int size)
{
	//这样的判断方法是正确的
	QPainterPath tmp;

	auto pos = path.elementAt(index);
	tmp.moveTo(pos.x, pos.y);

	while (index < size)
	{
		auto pos1 = path.elementAt(index);
		if(index+1 >= size)
		{
			break;
		}
		auto pos2 = path.elementAt(++index);
		auto pos0 = pos2 - pos1;

		if(qFuzzyCompare(pos0.x(), pos0.y()))
		{//排除同一点
			continue;
		}
		if(qFuzzyCompare(pos2.x, 55)
				&& qFuzzyCompare(pos2.y, 275))
		{//排除同一点
			continue;
		}
		else if(qFuzzyIsNull(pos0.x())
				&& !qFuzzyIsNull(pos0. y()))
		{//y方向一条直线
			//qDebug()<< "相同直线上" << pos1<< pos2  << "       " << index << "     "<< size ;
			tmp.lineTo(pos2.x, pos2.y);
		}
		else
		{//y方向一条直线
			qDebug()<< "不相同直线上" << pos1<< pos2  << "       " << index << "     "<< size ;
			if(index+1 < size)
			{
				QPainterPath newSections = lineSectionX(path, sections, index, size);
				if(newSections.elementCount() > 2)
				{
					sections += newSections;
				}
			}
		}
	}

	return tmp;
}

int EditScene::getLineSectionIndex(const QPoint &pos, FlowLine *pLine)
{
	lineSections_ = getLineSection(pLine->getLinePath());
	QVector<int> values;

	int tempValue = 100;//初始化一个比较大的值
	int min = 100;
	for(int i = 0; i != lineSections_.size(); ++i)
	{
		tempValue = 100;
		QPainterPath section = lineSections_.at(i);
		for(int j = 0; j != section.elementCount(); ++j)
		{
			auto tmpPos = section.elementAt(j);

			int tmp = qAbs(pos.x()-tmpPos.x) + qAbs(pos.y()-tmpPos.y);
			if(tmp < tempValue)
			{
				tempValue = tmp;
				if(tmp < min)
				{
					min = tmp;
				}
			}
		}
		values.append(tempValue);
	}

	for(int i = 0; i != values.size(); ++i)
	{
		if(values.at(i) == min
				&& min < 10)
		{
			qDebug() << "这里难道不调用？？？~~~~~~~~~~~~~" << tempValue << "===" << values;
			return i;
		}
	}
	qDebug() << "这里难道不调用？？？~~~~~~~~~~~~~" << tempValue << "===" << values;
	return -1;
}

EditScene::DragDirection EditScene::getDirection(const int index)
{
	if(index >= 0
			&& index < lineSections_.size())
	{
		QPainterPath section = lineSections_.at(index);
		if(2 <= section.elementCount())
		{
			auto pos2 = section.elementAt(1);
			auto pos1 = section.elementAt(0);
			auto pos0 = pos2 - pos1;
			if(qFuzzyIsNull(pos0.x()))
			{
				return Horizontal;
			}
			else
			{
				return Vertical;
			}
		}
		else
		{
			qDebug() << "小于2怎么办";
		}
	}
	return None;
}

void EditScene::getRefindPoint(const QPainterPath::Element &currentPos1,
							   const QPainterPath::Element &otherPos1, const QPainterPath::Element &otherPos2,
							   QPoint &startPos, QPoint &endPos) const
{
	auto pf1f2 = currentPos1-otherPos1;
	auto pf1e2 = currentPos1-otherPos2;

	if((qAbs(pf1f2.x())+qAbs(pf1f2.y())) < (qAbs(pf1e2.x())+qAbs(pf1e2.y())))
	{
		startPos = QPoint(otherPos2.x, otherPos2.y);
		endPos = QPoint(otherPos1.x, otherPos1.y);
	}
	else
	{
		startPos = QPoint(otherPos1.x, otherPos1.y);
		endPos = QPoint(otherPos2.x, otherPos2.y);
	}
}

void EditScene::jiaoshenme(const QPoint &startPos, QPoint &endPoint, const QPoint &offset, int index)
{
	if(Horizontal == dragDirection_)
	{
		endPoint.setX(endPoint.x() + offset.x());
	}
	else if(Vertical == dragDirection_)
	{
		endPoint.setY(endPoint.y() + offset.y());
	}
	else
	{
		qDebug() << "None 移动";
	}

	//QPainterPath path = findPath(startPos+QPoint(-10, 5), endPoint+QPoint(-10, 5), startPos, endPoint);
	qDebug() << "寻路起点: " << startPos+QPoint(-5, 5) << "终点:" << endPoint+QPoint(-5, 5);
	qDebug() << "路径起点: " << startPos+QPoint(-5, 5) << "路径终点:" << endPoint+QPoint(-5, 5);
	//对其到整十
	QPainterPath path = findPath(startPos+QPoint(-5, 5), endPoint+QPoint(-5, 5), startPos+QPoint(-5, 5), endPoint+QPoint(-5, 5));
	qDebug() << "这里如何？" << path.elementAt(0) << path.elementAt(path.elementCount() - 1);
	lineSections_.replace(index, path);
}

/*!
 * \brief EditScene::createItemGroup 用于创建一个新的group并返回其指针
 * \param pos group创建的位置
 * \param bbName group的名字
 * \param defaultId group的编号
 * \param fullName 预留暂未使用
 * \param defaultValue 预留暂未使用
 * \return 新创建的group的指针
 */
GraphicsItermGroup* EditScene::createItemGroup(const QPointF &pos, const QString &bbName, int defaultId = -1, bool load = false, QString fullName = "", QString defaultValue = "")
{
	Q_UNUSED(defaultValue);
	//添加事物看看是不是能够有效改善速度
	QSqlDatabase::database().transaction();
	qDebug() << "坐标" <<pos;
	qDebug() << "要创建" << bbName;

	if(hash_component_count_.contains(bbName))
	{
		hash_component_count_[bbName] = ++hash_component_count_[bbName];
	}
	else
	{
		hash_component_count_[bbName] = 0;
	}
	int bbId = -1;
	if(defaultId >= 0)
	{
		bbId = defaultId;
	}
	else
	{
		bbId = hash_component_count_[bbName];
	}

	if(pHash_blockPath_data_->contains(bbName))
	{
		bbData_ = pHash_blockPath_data_->value(bbName);
	}

	//中间~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	QList<RootItem *> listRootItem;
	int sizeX;
	int sizeY;
	QString name = bbData_.ui.name;
	QString newName;
	if(fullName != "")
	{
		newName = fullName;
	}
	else
	{
		newName = bbData_.ui.fileName + "_" + QString::number(bbId);
	}
	int x1 = bbData_.ui.nameOffsetX;
	int y1 = bbData_.ui.nameOffsetY;
	sizeX = bbData_.ui.sizeX;
	sizeY = bbData_.ui.sizeY;
	QString type = bbData_.ui.type;
	QString tag = bbData_.ui.tag;
	//bool visible = bbData_.ui.bVisible;
	int doubleType = bbData_.ui.doubleClick;
	QPixmap pix;
	pix.loadFromData(bbData_.ui.ImagePath, "png");

	int x2 = bbData_.ui.imageOffsetX;
	int y2 = bbData_.ui.imageOffsetY;

	RootItem *tmpRoot = new RootItem(bbData_.ui.name, QRect(0, 0, sizeX* 50, sizeY* 30), pix);//模块尺寸是30*50

	hash_name_item_pointer_[newName] = tmpRoot;
	//tmpRoot->setToolTip(bbData_.ui.toolTip);
	tmpRoot->setPropertyValue(newName, "root", "root", x1, y1, type, tag, doubleType, x2, y2);
	//tmpRoot->setPos(pos);
	tmpRoot->setData(Qt::UserRole, tr("root-")+newName);
	qDebug() << "ITEM_NAME:" << newName;
	tmpRoot->setData(ITEM_NAME, newName);
	tmpRoot->setData(ITEM_TYPE, "root");
	tmpRoot->setData(ITEM_TYPE_DETAIL, "root");
	tmpRoot->setData(ITEM_SIZE_X, sizeX);
	tmpRoot->setData(ITEM_SIZE_Y, sizeY);

	//创建一个Group 尺寸是Root的width+2, height+2, 因为把周围要包起来
	GraphicsItermGroup *pItemGroup = new GraphicsItermGroup(QRect(0, 0, sizeX*50+20*2, sizeY*30+20*2), sizeX, sizeY, this);  //模块尺寸是30*50 外框20
	pItemGroup->setBlockName(bbName);
	connect(pWidgetMain_, SIGNAL(signalDeleteGroup(QString)), pItemGroup, SLOT(slotDeleteItem(QString)));

	pItemGroup->setData(ITEM_TYPE, "group");
	list_graphicsItermGroup_.append(pItemGroup);
	//加入到保存的信息中

	pItemGroup->setGroupId(bbId);

	pDatabaseEditComponent_->insertBBlist(newName, bbData_.ui.fileName);
	listRootItem << tmpRoot;
	//模块的参数计数
	int paramNum = 0;

	//左边~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	QList<BehaviourItem *> listBehaviourIn;
	for(int i = 0; i != bbData_.behaviorIn.size(); ++i)
	{
		//先读出数据库数据, 在这里拼装成为目标类
		int id = bbData_.behaviorIn.at(i).id;
		QString name = bbData_.behaviorIn.at(i).name;
		QString temp;
		if(fullName != "")
		{
			temp = fullName+"_"+name;
		}
		else
		{
			temp = bbData_.ui.fileName + "_" + QString::number(bbId)+"_"+name;
		}
		//bool visible = bbData_.behaviorIn.at(i).bVisible;
		QString imgPath = bbData_.behaviorIn.at(i).imagePath;

		if(imgPath.isEmpty())
		{
			imgPath = "./resource/images/bb/UI_Block_BI.png";
			//qDebug() << "图片没有数据 bi";
		}
		QPixmap pix(imgPath);

		BehaviourItem *tmp = new BehaviourItem(QRect(0, 0, 18, 20), pix);
		hash_name_item_pointer_[temp] = tmp;
		tmp->setToolTip(bbData_.behaviorIn.at(i).toolTip);
		tmp->setPropertyValue(id, temp, "behaviour", "behaviourIn", imgPath);
		tmp->setData(ITEM_NAME, temp);
		qDebug() << "ITEM_NAME:" << temp;
		tmp->setData(ITEM_TYPE, "behaviour");
		tmp->setData(ITEM_TYPE_DETAIL, "behaviourIn");
		tmp->setData(Qt::UserRole, "behaviour-"+temp);

		listBehaviourIn << tmp;
		pItemGroup->listBehaviourInUse_.append(false);
		pItemGroup->listBehaviourIn_.append(tmp);
	}
	qDebug() << "behavior 有 " << listBehaviourIn.size();

	//右边~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	QList<BehaviourItem *> listBehaviourOut;
	for(int i = 0; i != bbData_.behaviorOut.size(); ++i)
	{
		int id = bbData_.behaviorOut.at(i).id;
		QString name = bbData_.behaviorOut.at(i).name;

		QString temp;
		if(fullName != "")
		{
			temp = fullName+"_"+name;
		}
		else
		{
			temp = bbData_.ui.fileName + "_" + QString::number(bbId)+"_"+name;
		}
		//bool visible = bbData_.behaviorOut.at(i).bVisible;
		QString imgPath = bbData_.behaviorOut.at(i).imagePath;

		if(imgPath.isEmpty())
		{
			imgPath = "./resource/images/bb/UI_Block_BO.png";
			//qDebug() << "图片没有数据 bo";
		}
		QPixmap pix(imgPath);

		BehaviourItem *tmp = new BehaviourItem(QRect(0, 0, 18, 20), pix);
		hash_name_item_pointer_[temp] = tmp;
		tmp->setToolTip(bbData_.behaviorOut.at(i).toolTip);
		tmp->setPropertyValue(id, temp, "behaviour", "behaviourOut", imgPath);
		tmp->setData(ITEM_NAME, temp);
		qDebug() << "ITEM_NAME:" << temp;
		tmp->setData(ITEM_TYPE, "behaviour");
		tmp->setData(ITEM_TYPE_DETAIL, "behaviourOut");
		tmp->setData(Qt::UserRole, "behaviour-"+temp);

		//加入到列表中
		//tmp->setPosOffset(pos, sizeX*40.0-5, i*40.0+6);
		listBehaviourOut << tmp;

		pItemGroup->listBehaviourOutUse_.append(false);
		pItemGroup->listBehaviourOut_.append(tmp);
	}
	qDebug() <<" behaviour out 有 " << listBehaviourOut.size();

	//上面~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	QList<ParameterItem *> listParamIn;
	for(int i = 0; i != bbData_.paramIn.size(); ++i)
	{
		int id = bbData_.paramIn.at(i).id;
		QString name = bbData_.paramIn.at(i).name;
		QString temp;
		if(fullName != "")
		{
			temp = fullName+"_"+name;
		}
		else
		{
			temp = bbData_.ui.fileName + "_" + QString::number(bbId)+"_"+name;
		}

		QString type = bbData_.paramIn.at(i).type;
		QString value = bbData_.paramIn.at(i).value;
		//bool visible = bbData_.paramIn.at(i).bVisble;
		QString imgPath = bbData_.paramIn.at(i).imagePath;
		QString typeUi = bbData_.paramIn.at(i).uiType;
		if("bool" == typeUi)
		{
			if("0" == value)
			{
				value = "false";
			}
			else if("1" == value)
			{
				value = "true";
			}
		}
		if(imgPath.isEmpty())
		{
			imgPath = "./resource/images/bb/UI_Block_Pin.png";
			//qDebug() << "图片没有数据 pin";
		}
		QPixmap pix(imgPath);

		ParameterItem *tmp = new ParameterItem(QRect(0, 0, 38, 22), pix);
		tmp->addWidgetMainPointer(pWidgetMain_);
		hash_name_item_pointer_[temp] = tmp;
		tmp->setPropertyValue(id, temp, "param", "parameterIn", value,type, typeUi, imgPath);
		tmp->setToolTip(bbData_.paramIn.at(i).toolTip);
		tmp->setData(Qt::UserRole, "param-"+temp);
		tmp->setData(ITEM_NAME, temp);
		qDebug() << "ITEM_NAME:" << temp;
		tmp->setData(ITEM_TYPE, "param");
		tmp->setData(ITEM_TYPE_DETAIL, "parameterIn");
		//tmp->setData(Qt::UserRole + 20, "parameterIn");

		connect(tmp, SIGNAL(signalParamValueChange(QString,QString,QString)),this, SLOT(slotParamValueChange(QString,QString,QString)));
		//加入数据库中!!!!!!!!!!!!!!!!!!!!!!!!!!!
		pDatabaseEditComponent_->insertParamterData(paramterCount, type, value, temp, typeUi, "", "");

		//这里是处理bbName有空格的情况//////////////////////////////////////////////////////////
		QString name11;
		qDebug() << "@#%%$&%^*^&*(*(@@@@@@@@@@"<<bbData_.ui.fileName;
		if(NOT_FINDE == bbData_.ui.fileName.indexOf(" "))
		{
			name11 = bbData_.ui.fileName;
			qDebug() << "要写入BBList的名字是" <<name11;
		}
		else
		{
			QStringList tmpNameList = bbData_.ui.fileName.split(" ");
			QString name11 = tmpNameList[0]+ tmpNameList[1];
			qDebug() << "要写入BBList的名字是" <<name11;
		}

		tmp->setData(Qt::UserRole+27, paramNum);
		pDatabaseEditComponent_->updateBBlist(name11 + "_" + QString::number(bbId), paramNum++, paramterCount);
		//////////////////////////////////////////////////////////////////////////////////////////////////////

		hash_Name_Paramter_.insert(temp, tmp);
		listParamIn << tmp;
		++paramterCount;
	}
	qDebug() << "paramIn 有" << listParamIn.size();

	//下面~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	QList<ParameterItem *> listParamOut;
	for(int i = 0; i != bbData_.paramOut.size(); ++i)
	{
		int id = bbData_.paramOut.at(i).id;
		QString name = bbData_.paramOut.at(i).name;
		QString temp;
		if(fullName != "")
		{
			temp = fullName+"_"+name;
		}
		else
		{
			temp = bbData_.ui.fileName + "_" + QString::number(bbId)+"_"+name;
		}
		QString type = bbData_.paramOut.at(i).type;

		//bool visible = bbData_.paramOut.at(i).bVisble;
		QString imgPath = bbData_.paramOut.at(i).imagePath;
		QString typeUi = bbData_.paramOut.at(i).uiType;

		if(imgPath.isEmpty())
		{
			imgPath = "./resource/images/bb/UI_Block_Pout.png";
			//qDebug() << "图片没有数据 pout";
		}
		QPixmap pix(imgPath);

		ParameterItem *tmp = new ParameterItem(QRect(0, 0, 24, 20), pix);
		hash_name_item_pointer_[temp] = tmp;
		tmp->setPropertyValue(id, temp, tr("param"), tr("parameterOut"), "", type, typeUi, imgPath);
		tmp->setToolTip(bbData_.paramOut.at(i).toolTip);
		tmp->setData(Qt::UserRole, "param-"+temp);
		tmp->setData(ITEM_NAME, temp);
		qDebug() << "ITEM_NAME:" << temp;
		tmp->setData(ITEM_TYPE, "param");
		tmp->setData(ITEM_TYPE_DETAIL, "parameterOut");
		//tmp->setData(Qt::UserRole + 20, "down");
		listParamOut << tmp;
	}
	qDebug() << "paramOut 有" << listParamOut.size();

	//现在在scene中加入各个item
	RootItem *p = listRootItem.first();

	ParameterItem *p1;

	if(!load)
	{
		int x = pos.x();
		int y = pos.y();
		x -= pItemGroup->getSize().width()/2;
		y -=pItemGroup->getSize().height()/2;
		x = qRound((qreal)x / MIN_CELL) * MIN_CELL;
		y = qRound((qreal)y / MIN_CELL) * MIN_CELL;
		pItemGroup->setPos(x, y);
	}
	else
	{
		pItemGroup->setPos(pos);
	}

	foreach (p1, listParamOut)
	{
		pItemGroup->addParameterOut(p1);
	}
	foreach (p1, listParamIn)
	{
		pItemGroup->addParameterIn(p1);
	}

	BehaviourItem *p2;
	foreach (p2, listBehaviourOut)
	{
		pItemGroup->addBehaviorOut(p2);
	}
	foreach (p2, listBehaviourIn)
	{
		pItemGroup->addBehaviorIn(p2);
	}

	pItemGroup->addRoot(p);
	this->addItem(pItemGroup);

	QSqlDatabase::database().commit();
	return pItemGroup;
}

void EditScene::slotParamValueChange(const QString &type, const QString &newValue, const QString &paramName)
{
	qDebug() << "要更新的参数" << paramName << type << newValue;
	pDatabaseEditComponent_->updateParameter(type, newValue, paramName);
}

void EditScene::slotCreateGroup(const QString &bbName)
{
	/*pNewGroup_ = */createItemGroup(QPoint(100,100), bbName, -1, false, "", "" );
}

void EditScene::slotViewScale(qreal scale)
{
	//qDebug() << "slotViewScale" << scale;
	moveViewOffset_ = QPoint(moveViewOffset_.x()*scale, moveViewOffset_.y()*scale);
}

void EditScene::slotCreateItemGroup(const QPointF &pos, const QString &bbName, int defaultId, bool load, QString fullName, QString defaultValue)
{
	createItemGroup(pos, bbName, defaultId, load, fullName, defaultValue);
}
