#include "DatabaseEditComponent.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QStringList>

DatabaseEditComponent::DatabaseEditComponent(QObject *parent) :
    QObject(parent)
{
    initData();
}

void DatabaseEditComponent::insertParamterData(int index, const QString &type, const QString &value, const QString &ownerName, const QString &typeUi, const QString &sketch, const QString &postfix)
{
    pQuery_->prepare("INSERT INTO Parameter (ID, Type, Postfix, Value, Owner, uiType, Sketch) "
                     "VALUES (?, ?, ?, ?, ?, ?, ?)");
    pQuery_->bindValue(0, index);
    pQuery_->bindValue(1, type);
    pQuery_->bindValue(2, postfix);
    pQuery_->bindValue(3, value);
    pQuery_->bindValue(4, ownerName);
    pQuery_->bindValue(5, typeUi);
    pQuery_->bindValue(6, sketch);
    pQuery_->exec();
}

void DatabaseEditComponent::updateParameter(const QString &type, const QString &value, const QString &ownerName)
{
    QString cmd;
    //判断类型
    if(tr("INT") == type.toUpper())
    {
		qDebug() << "纳尼不是你么？" << value;

		if("FALSE" == value.toUpper())
        {
            cmd = tr("UPDATE Parameter SET Value = '%1' WHERE Owner = '%2'").arg("0").arg(ownerName);
        }
		else if("TRUE" == value.toUpper())
        {
            cmd = tr("UPDATE Parameter SET Value = '%1' WHERE Owner = '%2'").arg("1").arg(ownerName);
        }
		//else if(value.contains(R"(\[[\s \w]*\])"))
        else
        {
            cmd = tr("UPDATE Parameter SET Value = '%1' WHERE Owner = '%2'").arg(value.toInt()).arg(ownerName);
        }

        qDebug() << cmd ;
    }
	else if("FLOAT"  == type.toUpper())
	{
		if(value.contains("{")
				&&value.contains("}"))
		{
			qDebug() << "来吧！";
			cmd = tr("UPDATE Parameter SET Value = '%1' WHERE Owner = '%2'").arg(value).arg(ownerName);
		}
		else if(value.contains("[")
				&&value.contains("]"))
		{
			qDebug() << "来吧！";
			cmd = tr("UPDATE Parameter SET Postfix = '%1' WHERE Owner = '%2'").arg(value).arg(ownerName);
		}
		else
		{
			cmd = tr("UPDATE Parameter SET Value = '%1' WHERE Owner = '%2'").arg(value.toFloat()).arg(ownerName);
			qDebug() << cmd ;
		}
	}
    else if(tr("STRING") == type.toUpper())
    {
        cmd = tr("UPDATE Parameter SET Value = '%1' WHERE Owner = '%2'").arg(value).arg(ownerName);
		qDebug() << cmd;
    }
    else
    {
        cmd = tr("UPDATE Parameter SET Value = '%1' WHERE Owner = '%2'").arg(value).arg(ownerName);
        qDebug() << "sssssssssssssss " << cmd;
    }

    qDebug() << cmd;
    pQuery_->exec(cmd);
}

QSqlQuery DatabaseEditComponent::selectParameter()
{
    pQuery_->exec("SELECT Value, Owner FROM Parameter");
    return *pQuery_;
}

void DatabaseEditComponent::clearData()
{
    //清空那几张表
    //先是参数的表
    pQuery_->exec("delete from Parameter");
    //然后是模块表
    pQuery_->exec("delete from BBList");
    //在清空链接的表
    pQuery_->exec("delete from Linkage");
}

void DatabaseEditComponent::insertBBlist(const QString &bbName, const QString &type)
{
    pQuery_->prepare("INSERT INTO BBList (BB, Type) "
                     "VALUES (?,?)");
    pQuery_->bindValue(0, bbName);
    pQuery_->bindValue(1, type);
    pQuery_->exec();
}

void DatabaseEditComponent::deleteBBlist(const QString &bbName)
{
    QString cmd = tr("delete from BBList where BB == '%1'").arg(bbName);
    qDebug() << cmd;

    pQuery_->exec(cmd);
}

void DatabaseEditComponent::updateBBlist(const QString &bbName, int bbIndex, int paramIndex)
{
    QString cmd = tr("UPDATE BBList SET pi%1 = %2 WHERE BB == '%3'")
            .arg(QString::number(bbIndex))
            .arg(QString::number(paramIndex))
            .arg(bbName);
    qDebug() << cmd;

    pQuery_->exec(cmd);
}

void DatabaseEditComponent::insertLinker(const QString &start, const QString &end)
{
    qDebug() << "come:" << start << "end:" << end;
    pQuery_->prepare("INSERT INTO Linkage (Come, Go) "
                     "VALUES (?,?)");
    pQuery_->bindValue(0, start);
    pQuery_->bindValue(1, end);
    pQuery_->exec();
}

QString DatabaseEditComponent::getParamterId(const QString &name) const
{
    QString cmd = tr("select ID from Parameter where Owner == '%1' ").arg(name);
    qDebug() << cmd;
    pQuery_->exec(cmd);
    pQuery_->next();
    QString tmp = pQuery_->value(0).toString();
    qDebug() << "搜索到的位置是" <<tmp;

    return tmp;
}

void DatabaseEditComponent::deleteComponent(const QString &bbName)
{
    //linkage表需要like
    deleteLinkage(bbName);
    //BBList 只需要bbName
    deleteBBlist(bbName);
    //paramter 需要like
    deleteParameter(bbName);
}

QSqlQuery DatabaseEditComponent::selectLinker() const
{
    pQuery_->exec(tr("SELECT * FROM Linkage"));
    return *pQuery_;
}

void DatabaseEditComponent::deleteLinkage(const QString &bbName)
{
    qDebug() <<"全名还是?" << bbName << bbName;
    QString cmd = tr("delete from Linkage where Come like '%1%'").arg(bbName);
    QString cmd1 = tr("delete from Linkage where Go like '%1%'").arg(bbName);
    qDebug() << cmd;
    qDebug() << cmd1;

    pQuery_->exec(cmd);
    pQuery_->exec(cmd1);
}

void DatabaseEditComponent::initData()
{
    pDb_ = new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"));
	pDb_->setDatabaseName("./resource/Blocks/Buffer.mpb");
	//pDb_->setDatabaseName("./resource/Blocks/buffer.dll");

    if(!pDb_->open())
    {
        qDebug() << "编辑信息数据库打开失败" <<pDb_->lastError().text();
    }

    pQuery_ = new QSqlQuery(*pDb_);
    //开始清空之前的数据,除了code表,这个是应该在翻译的时候清空的
    clearData();
}

void DatabaseEditComponent::deleteParameter(const QString &bbName)
{
    QString cmd = tr("delete from Parameter where Owner like '%1%'").arg(bbName);
    qDebug() << cmd;

    pQuery_->exec(cmd);
}

//这里在判断的时候必须精确的匹配
void DatabaseEditComponent::deleteLinkage(const QString &startName, const QString &endName)
{
    qDebug() <<"删除线的两端, 端点名是:" << startName << endName;
    QString cmd = tr("delete from Linkage where Come == '%1' and Go == '%2'").arg(startName).arg(endName);
    qDebug() << cmd;

    pQuery_->exec(cmd);
}

QString DatabaseEditComponent::getPrameterOwnerBBName(int index)
{
    qDebug() << "要查找param的owner了"  << index;

    QString cmd = tr("select Owner from Parameter where ID == %1")
            .arg(QString::number(index));
    qDebug() << cmd;
    pQuery_->exec(cmd);
    if(pQuery_->next())
    {
        QStringList tmpList = pQuery_->value(0).toString().split("_");
        QString tmp = tmpList.at(0);
        for(int i = 1; i < tmpList.size() - 1; ++i)
        {
            tmp += tr("_") + tmpList.at(i);
        }

        return tmp;
    }
    else
    {
        return QString();
    }
}

QString DatabaseEditComponent::getPrameterIndexInLinageTable()
{
    qDebug() << "从linkage表拿parameter的编号";
}
