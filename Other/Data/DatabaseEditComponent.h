#ifndef DATABASEEDITCOMPONENT_H
#define DATABASEEDITCOMPONENT_H

class QSqlDatabase;
class QSqlQuery;

#include <QObject>
//本类用于编辑组件的时候与数据的交互(主要针对Buffer.db)
class DatabaseEditComponent : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseEditComponent(QObject *parent = 0);
    //创建之初插入数据所用
    void insertParamterData(int index, const QString &type, const QString &value, const QString &ownerName, const QString &typeUi, const QString &sketch, const QString &postfix);
    //编辑部件中的参数的时候更新数据库中的数据所需
    void updateParameter(const QString &type, const QString &value, const QString &ownerName);
    //要塞进最终翻译的数据库的时候需要的
    QSqlQuery selectParameter();
    void clearData();
    void insertBBlist(const QString &bbName, const QString &type);
    void updateBBlist(const QString &bbName, int bbIndex, int paramIndex);
    void insertLinker(const QString &start, const QString &end);
    QString getParamterId(const QString &name) const;
    void deleteComponent(const QString &bbName);
    QSqlQuery selectLinker() const;
    void deleteLinkage(const QString &bbName);
    void deleteLinkage(const QString &startName, const QString &endName);

    //为了数据分享加入的
    QString getPrameterOwnerBBName(int index);
    QString getPrameterIndexInLinageTable();

signals:

public slots:

private:
    void initData();
    void deleteParameter(const QString &bbName);
    void deleteBBlist(const QString &bbName);

private:
    QSqlDatabase *pDb_;
    QSqlQuery *pQuery_;
};

#endif // DATABASEEDITCOMPONENT_H
