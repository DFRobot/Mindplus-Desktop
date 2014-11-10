#ifndef DATABASEHANDLE_H
#define DATABASEHANDLE_H

#include <QObject>
#include <QVariant>
#include <QMap>
//数据操作类, 处理数据集中的数据
class ResultsetBase;
class DataBaseHandle : public QObject
{
    Q_OBJECT
public:
    explicit DataBaseHandle(ResultsetBase &resultsetBase, QObject *parent = 0);
    virtual ~DataBaseHandle();

    QList<QList<QVariant> > & select(const QString &filters = QString("*"), const QString &condition = QString(""), const QString &separator = QString(","));
    bool insert(const QString &filter);
    bool update(const QString &filter);
    bool deleteRow(const QString &filter);
    void clear();

signals:
    //void signal
public slots:

protected:
    QStringList separatorCondition(const QString &condition) const;

protected:
    QMap<QString, int> map_columnName_index_;
    QList<QList<QVariant> > tableData_;
    QList<QString> list_tableTitle_;
};

#endif // DATABASEHANDLE_H
