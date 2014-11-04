#include "ResultsetBase.h"

ResultsetBase::ResultsetBase(QObject *parent) :
    QObject(parent)
{
}

ResultsetBase::~ResultsetBase()
{
}

QList<QList<QVariant> > &ResultsetBase::getResultset()
{
    return tableData_;
}
