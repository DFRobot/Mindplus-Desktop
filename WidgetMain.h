#ifndef WIDGETMAIN_H
#define WIDGETMAIN_H

#include "ui_WidgetMain.h"
#include <QPointer>
#ifdef Q_OS_WIN32
#include <windows.h>
#include <windowsx.h>
#endif
#include <QLocalServer>
#include <QLocalSocket>

class TreeWidgetComponent;
class UploadSettingForm;
class FunctionArea;
class EditScene;
class IntroduceForm;
class MindKitForm;
class MindKitPushButton;
class SerialSettingWidget;
class FlowLine;
class Label;
class ListWidgetAdvanceBlock;
class SerialPortToolForm;
class FunctionAreaWidget;

/**
 * @brief 存储初级模块的数据的
 */
struct ListWidgetBeginData
{
    ListWidgetBeginData()
        : name("")
        , type("")
        , text("")
        , imagePath("")
    {
    }

    ListWidgetBeginData(const QString &name, const QString &type, const QString &text, const QString &imagePath)
        : name(name)
        , type(type)
        , text(text)
        , imagePath(imagePath)
    {
    }

    ListWidgetBeginData(const ListWidgetBeginData &other)
    {
        name = other.name;
        type = other.type;
        text = other.text;
        imagePath = other.imagePath;
    }

    friend QDataStream & operator << (QDataStream &out, const ListWidgetBeginData &d)
    {
        out << d.name << d.type << d.text << d.imagePath;
        return out;
    }
    friend QDataStream & operator >> (QDataStream &in, ListWidgetBeginData &d)
    {
        in >> d.name >> d.type >> d.text >> d.imagePath;
        return in;
    }

    QString name;//模块名,查找的依据
    QString type;//类型
    QString text;//辅助显示的
    QString imagePath;
};

class WidgetMain : public QWidget, private Ui::WidgetMain
{
    Q_OBJECT

public:
    explicit WidgetMain(QWidget *parent = 0);
    QHash<QString, DataStruct> * getComponentsData();
    EditScene * getScenePointer();
signals:
    //组件拼装完毕后发出的信号
    void signalCreateComponentFinish();
    void signalCreateGroup(const QString &bbName);
    void signalDeleteGroup(const QString &name);
    void signalDeleteLine(FlowLine *p, const QString &startName, const QString &endName);

protected:
    //void paintEvent(QPaintEvent *event);
    void changeEvent(QEvent *e);
    bool eventFilter(QObject *target, QEvent *event);
    void resizeEvent(QResizeEvent *event);
    void showEvent(QShowEvent *event);

#ifdef Q_OS_WIN32
	bool winEvent(MSG *message, long *result);
#endif

private slots:
    void on_pushButtonClose_clicked();
    void on_pushButtonMaxSize_clicked();
    void on_pushButtonMinSize_clicked();
    void on_pushButtonSetting_clicked();
    void on_pushButtonSave_clicked();
    void on_pushButtonLoad_clicked();
    void on_pushButtonInfor_clicked();
    void on_pushButtonAllBlocks_clicked();
    void on_treeWidget_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous);
    void on_pushButtonMemu_clicked();
	void on_pushButtonUpward_clicked();
	void on_pushButtonDownward_clicked();

    void slotClickUpload();
    void slotClickSave();
    void slotClickOpen();
    void slotClickNewProject();
    void slotBoardTypeItemClicked(const QString &boardName, const QString &index);
    void slotSerialItemClicked(const QString &serialName);
    void slotShowMindKit();
    void slotHideMindKit();
    void slotDone();

    void slotShowIntroduce(const QString &type);
    void slotHideSubWindows();
    void slotShowSubWindows();
    void slotMindKitPushButtonPointer(MindKitPushButton *pointer);

    void slotOpenAutoUpdate();
    void slotPressBack();
    void slotPressNotSave();
    void slotPressSave();
    void slotPressSerialSetting();
    void slotShowDustbin();
    void slotHideDusbin();

    //Root以及Line的焦点
    void slotFocusInLine(FlowLine *p, const QString &startName, const QString &endName);
    void slotFocusInGroup(const QString &name);
    void slotFocusOut();
    void slotCurrentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void slotShowHelp(const QString &blockName);

	//跳转
	void slotViewOffset(const QPoint offset);

    //memu
    void slotActionTriggered();
	void slotCreateSerialTool();
	void slotSerialToolClose();

private:
    void initSetting();
    void initData();
    void initGui();
    void createUploadSetting();
    bool saveCurrentState();

    void clearDustbinData();
    //遍历模块目录
    void scanBlocks(const QString &dirPath, QTreeWidgetItem *parentItem, QMenu *parentMenu);
    void createListWidget();
    void createBeginerList(const QVector<ListWidgetBeginData> &datas, QListWidget *pListWidget);

private:
    QPoint offset_;
    QString boardIndex_;
    QPointer<UploadSettingForm> pUploadSetting_;

    EditScene *pEditScene_;
    FunctionArea *pFunctionArea_;
    SerialSettingWidget *pSerialSetting_;

    //模块路径,极其对应数据
    QHash<QString, DataStruct> hash_blockPath_blockData_;
    QMap<QString, QString> map_moduleName_moduleTag_;
    QMap<QString, QStringList> map_dirPath_blockNames_;
    QMap<QTreeWidgetItem *, int> map_treeWidgetItemPointer_pageIndex_;

    int pageIndex_;

    QPointer<IntroduceForm> pIntroduceForm_;
    QPointer<MindKitForm> pMindKitForm_;

    int affirmType_;

    //垃圾箱不做在Scene里面了,就用一个label好了
    Label *pDustbin_;
    bool bDustbinShow_;
    //存储线或者rootItem相关
    int type_;
    FlowLine *pFlowLine_;
    QString startName_;
    QString endName_;
    QString groupName_;

    //全局的menu
    QMenu *pAllBlockMenu_;

    //滚轮相关的变量
    ListWidgetAdvanceBlock *pListWidget_;//具体的模块列表

	//串口工具
	SerialPortToolForm *pSerialPortTool_;
	FunctionAreaWidget *pSerialPortToolLabel_;
	//回到开始
	QLabel *pBackStart_;
};

#endif // WIDGETMAIN_H
