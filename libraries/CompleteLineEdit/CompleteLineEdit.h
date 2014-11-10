#ifndef COMPLETELINEEDIT_H
#define COMPLETELINEEDIT_H

#include <QLineEdit>
#include <QStringList>
#include <QHash>
#include <QStandardItem>
#include <QStandardItemModel>

QT_BEGIN_NAMESPACE
class QListView;
class QStringListModel;
class QModelIndex;
struct DataStruct;
QT_END_NAMESPACE

class CompleteLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    CompleteLineEdit(QWidget *parent = 0);
    void setCompleteList(const QStringList &listComplete);
    void hide();
    void addModulesData(const QMap<QString, QString> &data);
	void show();

signals:
    void signalSelectItem(const QString &name);
    void signalEsc();

public slots:
    void slotCompleterInputText(const QString &inputText); // 动态的显示完成列表
    void slotCompleteText(const QModelIndex &index); // 点击完成列表中的项，使用此项自动完成输入的单词

protected:
    virtual void keyPressEvent(QKeyEvent *e);

private:
    void initData();

private:
    QStringList listComplete_; // 整个完成列表的单词
    QListView *pListView_; // 完成列表
    QStandardItemModel *pStandardItemModel_;
    QMap<QString, QString> map_moduleName_moduleTag_;
};
#endif
