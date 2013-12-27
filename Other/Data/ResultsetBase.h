#ifndef RESULTSETBASE_H
#define RESULTSETBASE_H

#include <QObject>
#include <QVariant>
//结果集基类, 为数据操作类提供统一的结果集
//针对不同的数据存储方案,需要派生不同的派生类
class ResultsetBase : public QObject
{
    Q_OBJECT
public:
    explicit ResultsetBase(QObject *parent = 0);
    virtual ~ResultsetBase();

    QList<QList<QVariant> >& getResultset();
    /*! 错误*/
    enum ResultsetError
    {
        ErrorOpen,/*!< 打开数据存储文件错误*/
        ErrorTraverse/*!< 遍历数据存储文件错误*/
    };

signals:
    void signalError(ResultsetError errorType);
    void signalOpenDataFileError();
    void signalTraverseDataFileError();

protected:
    //让派生类去覆盖
    virtual void traverse(const QString &dataPath) = 0;

protected:
        QList<QList<QVariant> > tableData_;
};

#endif // RESULTSETBASE_H
