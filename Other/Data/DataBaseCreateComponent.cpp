#include "DataBaseCreateComponent.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QSqlRecord>

DataBaseCreateComponent::DataBaseCreateComponent(const QString &bbName, QObject *parent)
    : QObject(parent)
    , bbName_(bbName)
{
    initData();
}

void DataBaseCreateComponent::closeDataBaseConnect()
{
    if(pDb_)
    {
        pDb_->close();
    }
}

QSqlQuery DataBaseCreateComponent::selectData(const QString &tableName) const
{
    pQuery_->exec(tr("select * from ") + tableName);
    return *pQuery_;
}

void DataBaseCreateComponent::slotCreateComponentFinish()
{
    pDb_->close();
}

//对应的应该在创建对象完毕的时候有一个信号让数据库关闭连接
void DataBaseCreateComponent::initData()
{
    pDb_ = new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"));
    pDb_->setDatabaseName(tr("./resource/Blocks/") + bbName_ + ".mpb");
//    //pDb_->setPassword();
    if(!pDb_->open())
    {
        qDebug() << bbName_ << "模块数据库打开失败" <<pDb_->lastError().text();
    }

    pQuery_ = new QSqlQuery(*pDb_);
}
