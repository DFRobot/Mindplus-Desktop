#ifndef DATABASECREATECOMPONENT_H
#define DATABASECREATECOMPONENT_H

class QSqlDatabase;
class QSqlQuery;
class QSqlRecord;

#include <QObject>
//本类用于在动态创建组件的时候与数据库交互(主要针对各个模块对应的数据库)
class DataBaseCreateComponent : public QObject
{
    Q_OBJECT
public:
    explicit DataBaseCreateComponent(const QString &bbName, QObject *parent = 0);
    void closeDataBaseConnect();
    QSqlQuery selectData(const QString &tableName) const;
signals:

public slots:
    //用于处理组件创建完毕的信号,然后释放数据连接
    void slotCreateComponentFinish();

private:
    void initData();

private:
    QSqlDatabase *pDb_;
    QSqlQuery *pQuery_;
    QString bbName_;
};

#endif // DATABASECREATECOMPONENT_H
