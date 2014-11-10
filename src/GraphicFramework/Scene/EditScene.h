#ifndef EDITSCENE_H
#define EDITSCENE_H

#include <QGraphicsScene>
#include <QHash>
#include <Other/Data/DataStruct.h>
#include <QTime>
#include <QPointer>

class ParameterItem;
class ListWidget;
class DataBaseCreateComponent;
class DatabaseEditComponent;
class BehaviourItem;
class ParameterItem;
class FlowLine;
class CompleteLineEdit;
class FunctionWidget;
class StartItem;
class GraphicsItemBase;
class GraphicsItermGroup;
class LockIconItem;
class MindKitPushButton;
class DustbinItem;
class WidgetMain;

struct Node
{
    int type;   //当前, 未探索, 开放列表, 关闭列表, 路障
    //权重
    int f;
    int h;
    int g;
    //
    Node *parent;
    //坐标
    int x;
    int y;
};

//在这里管理所有的item,连带item的创建(数据库读入)

class EditScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit EditScene(QObject *parent = 0);
    explicit EditScene(const QRectF & sceneRect, QObject * parent = 0);
    /*! 拖拽移动或者复制时的键盘事件类型*/
    enum
    {
        KeyNull,/*!< 没有按下*/
        KeyOthersPress,/*!< 不关心的键盘按下类型*/
        KeyRelease,/*!< 键盘释放*/
        KeyEscPress,/*!< 按下ESC*/
        KeyShiftPress,/*!< 按下Shift没有Release*/
        KeyCtrlPress,/*!< press ctrl*/
        KeyAltPress/*!< press alt 为Mac OS 准备*/
    };
	enum DragDirection
	{
		Horizontal,/*!< 只能水平移动*/
		Vertical,/*!< 只能竖直移动*/
		None/*!< 无效值*/
	};
    //设置网格的大小
    void setGridSize(const QSize &size);
    void setGridSize(int width, int height);
    QSize getGridSize() const {return QSize(gridWidth_, gridHeight_);}
    int getGridSizeWidth() const { return gridWidth_; }
    int getGridSizeHeight() const { return gridHeight_; }

	void setComponentData(QHash<QString, DataStruct> *p) {pHash_blockPath_data_ = p;}
    GraphicsItermGroup *createItemGroup(const QPointF &pos, const QString &bbName, int defaultId, bool load, QString fullName, QString defaultValue);
	void setListWidgetModulePointer(ListWidget *p);
	void setListWidgetIntroducePointer(ListWidget *p);
    void setReset();
    void saveFile(const QString &filePath);
    void createLine(const QString &startName,const QString &endName, const QPointF &startPos, const QPointF &endPos, GraphicsItemBase *pStartItem, GraphicsItemBase *pEndItem);
    void createLine(GraphicsItemBase *pStartItem, GraphicsItemBase *pEndItem);
    void setComponentCount(const QString &name, int count);
    void setParameterValue(const QString &name, const QString &value);
    //需要一个寻路的函数
    QPainterPath findPath(const QPointF &startPos, const QPointF &endPos, const QPointF &PathStartPos, const QPointF &PathEndPos);
    QPainterPath findLinePath(const QPointF &startPos, const QPointF &endPos);
    //需要一个维护坐标状态网格(Vector)的函数

    void updateGridNodeData();
    //这里是删除单个group使用的
    void deleteGraphicsGroup(GraphicsItermGroup *p, const QString &name);
    //清除所有的group, 主要用在reset的时候
    void clearAllGraphicsGroup();
	void setWidgetMain(WidgetMain *p);
	WidgetMain* getWidgetMain() const { return pWidgetMain_;}
    QList<FlowLine *> getFlowLines(){return list_line_;}
    void deleteLine(FlowLine *p, const QString &startName, const QString &endName);
    void deleteItem(const QString &name);
    GraphicsItemBase * getItemPointer(const QString &name);

    void setStartItem(GraphicsItemBase *p);
    DataBaseCreateComponent *pDatabaseCreateComponet_;
    DatabaseEditComponent *pDatabaseEditComponent_;

    //paramIn与paramIn
    void addLinePreprocess(GraphicsItemBase *pPressItem, GraphicsItemBase *pReleaseItem, const QString &startName, const QString &endName);
    //paramIn与paramOut
    void addLinePreprocess(GraphicsItemBase *pReleaseItem, const QString &startName, const QString &endName);
    //behavior
    void addLinePreprocess(GraphicsItemBase *pStartItem, GraphicsItemBase *pEndItem);

    void addModuleTagData(const QMap<QString, QString> &data);
    void setMindKitPushButtonPointer(MindKitPushButton *pointer);
    void setBackgroundGrid(bool show);

    bool isHoverStart() { return bHoverStart_; }

	void setListWidgetPointer(const QList<QWidget *> &pListWidgets){ list_listWidgetPointer_ = pListWidgets;}
	void addListWidgetPointer(QWidget *pListWidget){list_listWidgetPointer_.append(pListWidget);}
	void setInitScroll(int x, int y);
	void backStart();

signals:
     void signalCreateComponent(const QPointF &pos, const QString &bbName, int bbId, bool load, QString fullName, QString defaultValue);
     void signalSetNewValue(const QString &newValue);
     void signalUpload();
     void signalSave();
     void signalOpen();
     void signalShowSubWindows();

	 void signalFocusOut();

	 void signalFocusInLine(FlowLine *p, const QString &startName, const QString &endName);
	 void signalFocusInGroup(const QString &name);

	 void signalViewOffset(const QPoint &offset);

public slots:
     void slotCreateItemGroup(const QPointF &pos, const QString &bbName, int defaultId, bool load, QString fullName, QString defaultValue);
     void slotParamValueChange(const QString &type, const QString &newValue, const QString &paramName);
	 void slotCreateGroup(const QString &bbName);
	 void slotViewScale(qreal scale);

protected:
    void dragMoveEvent(QGraphicsSceneDragDropEvent *event);
    void dropEvent(QGraphicsSceneDragDropEvent *event);

    //按下按键和释放按键都要进行判断
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    //既然在QGraphicsItemGroup中难以实现对mouseDoubleClicked的响应就在这里做吧
    //实验性质的代码, 目的在于实现快速的控件检索插入
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    void drawBackground(QPainter *painter, const QRectF &rect);
    void drawForeground(QPainter *painter, const QRectF &rect);

private slots:
    //搜索框中选择某一个项
    void slotSelectItem(const QString &name);
    //按下ESC按键在画布中隐藏搜索框
    void slotCompleteEsc();
    //清空画布
    void slotReset();

    //处理线和rootItem的删除信息
    void slotLineFocus(FlowLine *p, const QString &startName, const QString &endName);
    void slotGroupFocus(const QString &name);

private:
    void initData();
    void initGui();
    QString getParamNewName(const QString &oldName);
	QStringList getComponentsName(const QString &dirPath);
    inline int getManhattan(const Node &s, const Node &e);
    void moveGroup(GraphicsItermGroup *pGroup, const QPointF pos);

	/**
	 * @brief getLineSection 将联线分段
	 * @param path 线
	 * @return 线的很多段
	 */
	QList<QPainterPath> getLineSection(QPainterPath path);
	QPainterPath lineSectionX(QPainterPath path, QList<QPainterPath> &sections, int &index, const int size);
	QPainterPath lineSectionY(QPainterPath path, QList<QPainterPath> &sections, int &index, const int size);

	/**
	 * @brief getLineSectionIndex 给定点返回所属section的index
	 * @param pos 点坐标
	 * @return -1不在点上(偏离较大) 所属section的index
	 */
	int getLineSectionIndex(const QPoint &pos, FlowLine *pLine);

	/**
	 * @brief getDirection 给定index返回section的拖动方向
	 * @param index 编号
	 * @return 拖动的方向(Horizontal, Vertical)
	 */
	DragDirection getDirection(const int index);

	/**
	 * @brief getRefindPoint 得到与当前线段连接的某以线段较远一点的坐标
	 * @param currentPos1 当前线段的测试点坐标
	 * @param otherPos1 与其连接的另外一段线段的一个端点坐标
	 * @param otherPos2 另外一个端点坐标
	 * @return 较远的端点
	 */
	void getRefindPoint(const QPainterPath::Element &currentPos1,
						  const QPainterPath::Element &otherPos1, const QPainterPath::Element &otherPos2,
						  QPoint &startPos, QPoint &endPos) const;

	void jiaoshenme(const QPoint &startPos, QPoint &endPoint, const QPoint &offset, int index);

private:
	WidgetMain *pWidgetMain_;

    QString bbName_;
	ListWidget *pListWidgetModule_;
	ListWidget *pListWidgetIntroduce_;
	QList<QWidget *> list_listWidgetPointer_;
    //各个部件的一些引用计数
    QHash<QString, int> hash_component_count_;  //不同的部件的引用计数
	int paramterCount;                          //参数计数
	QHash<QString, int> hash_BBParam_index;     //模块有多少个参数

    //神奇的一件事情, 补完相关
    CompleteLineEdit *pCompleteLineEdit_;
    QStringList listComponentsName_;
    QGraphicsProxyWidget *pProxyCompleteWidget_;
    QPointF doubleClickPoint_;
	QHash<QString, DataStruct> *pHash_blockPath_data_;
    DataStruct bbData_;

    //线是要单独设计存储的.
    struct LineSaveInfor
    {
        QString startName;
        QString endName;
    };
    //用来存储中间文件的
    QHash<QString, LineSaveInfor> hash_Name_LineSaveInfor;
    QHash<QString, ParameterItem *> hash_Name_Paramter_;
    QHash<QString, GraphicsItemBase *> hash_name_item_pointer_;

    //A*的网格相关

    typedef QVector<QVector<Node> > GridNode;
    GridNode gridNode_;
    //Node *matrixNode_[65][103];
    //预留一个比较大的区域
    Node matrixNode_[261][409];
    //连线相关的
    //存具体的坐标, 还不如存一个item对象的指针, 这次用智能指针
   GraphicsItemBase *pLineStartItem_;
    //坐标
    QPointF startPos_;          //起点坐标
    QPointF endPos_;             //终点坐标
    //名字
    QString startName_;     //起点对应模块名字
    QString endName_;       //终点的模块名字
    //结点
    Node startNode_;            //起点结点
    Node endNode_;             //终点结点

    //开启列表和关闭列表
    QVector<Node*> openList;     //有大量的增删操作还需要排序,So与heap配合
    QVector<Node*> closeList;     //仅需要增加

    StartItem *pStartItem_;
    QList<GraphicsItermGroup *> list_graphicsItermGroup_;

    //控件拖放和空白处拖放的分辨,
    bool bDrag_;
    QList<FlowLine *> list_line_;

    //拖线
    bool bDragLine_;
    int endPosX;
    int endPosY;
    QPointer<FlowLine> pCurrentFlowLine_;
    int tmpCount;
    volatile int findFinish_;
    //锁定框
    bool bLock_;
    LockIconItem *pLockIconItem_;
    QPixmap transparentCursor_ ;

    //拖拽移动复制相关
    /*!
     * \brief 拖拽移动或复制时存储键盘状态
     */
    int keyType_;
    QPointer<GraphicsItermGroup> pOldGroup_;
    QPointer<GraphicsItermGroup> pNewGroup_;
    QPointF dragStartPosition_;
    QPointF dragOffset_;
    bool bCreateGroup_;

    //Grid大小
    int gridWidth_;
    int gridHeight_;

    //搜索框
    //QMap<QString, QString> map_moduleName_moduleTag_;
    //MindKitPushButton
    QPointer<MindKitPushButton> pMindKitPushButton_;

    //是否显示背景网格
    bool bGrid_;
    //QPixmap bgGrid_;
    QPointer<DustbinItem> pDustbinItem_;

	//移动线的
    bool bSelectLine_;
	QPoint lineStartPos_;//起点
	int lineOffsetX_;//x方向上偏移
	int lineOffsetY_;//y方向上偏移
	DragDirection dragDirection_;
	int sectionIndex_;
	QList<QPainterPath> lineSections_;
	FlowLine *pLineDrag_;

    //一笔画
    bool bScrawl_;//是否使用
    QList<GraphicsItermGroup *> connectList_;//连接列表,用于记录一笔画的时候所经过的所有模块
    bool bHoverStart_; //是否经过start 提供start支持
    bool bScrawlPath_;
    QPainterPath scrawlPath_;
    bool bMouseMove_;

	//镜头平移
	bool bMoveView_;
	QPoint moveViewStartPoint_;
	QPoint moveViewOffset_;//妈的从滚动条获取的数据不对,还是得自己维护这个东西
};

#endif // EDITSCENE_H
