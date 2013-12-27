#include "DataBaseHandle.h"
#include "ResultsetBase.h"
#include <QDebug>
#include <QStringList>
#include <QRegExp>

DataBaseHandle::DataBaseHandle(ResultsetBase &resultsetBase, QObject *parent)
    : QObject(parent)
{
    tableData_ = resultsetBase.getResultset();

    //初始化表头
    QList<QVariant> listTmp = tableData_.at(0);
    for(int i = 0; i != listTmp.size(); ++i)
    {
        list_tableTitle_.append(listTmp.at(i).toString());
        map_columnName_index_[listTmp.at(i).toString()] = i;
    }
}

DataBaseHandle::~DataBaseHandle()
{
}

/*!
 * \brief DataBaseHandle::select 查询结果集
 * \param filters 目标列
 * \param condition 筛选条件 >=, >, ==, <, <=, in
 * \param separator 分隔符
 * \return 成功返回符合的结果集, 不成功返回空集
 */
QList<QList<QVariant> > &DataBaseHandle::select(const QString &filters, const QString &condition, const QString &separator)
{
    QStringList listFilters = filters.split(separator);
    if(!listFilters.isEmpty())
    {

        //在这里选出rows
        //for(int i = 0; i != )
    }
    //然后在选出column
    //return QList<QList<QVariant> >();
}

bool DataBaseHandle::insert(const QString &filter)
{
}

bool DataBaseHandle::update(const QString &filter)
{
}

bool DataBaseHandle::deleteRow(const QString &filter)
{
}

void DataBaseHandle::clear()
{
    tableData_.clear();
}

QStringList DataBaseHandle::separatorCondition(const QString &condition) const
{//这里用正则表达式
    //\s*\w*\s*>\s*\d\s*
//    if(condition.contains(QRegExp("\s*\w*\s*in\s*\d\s*")))
//    {

//    }
//    else if(condition.contains(QRegExp("\s*\w*\s*>=\s*\d\s*")))
//    {// >=

//    }
//    else if(condition.contains(QRegExp("\s*\w*\s*<=\s*\d\s*")))
//    {// <=

//    }
//    else if(condition.contains(QRegExp("\s*\w*\s*==\s*\d\s*")))
//    {// ==

//    }
//    else if(condition.contains(QRegExp("\s*\w*\s*!=\s*\d\s*")))
//    {//!=

//    }
//    else if(condition.contains(QRegExp("\s*\w*\s*>\s*\d\s*")))
//    {// >

//    }
//    else if(condition.contains(QRegExp("\s*\w*\s*<\s*\d\s*")))
//    {// <

//    }
}
