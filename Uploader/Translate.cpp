#include "Translate.h"
#include <QFile>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QVariant>
#include <QDir>
#include <QFileInfo>

QMap<QString, QString> Translate::map_fileName_filePath_ = QMap<QString, QString>();

Translate::Translate(const QString &fileSavePath, QObject *parent)
    : QObject(parent)
    , fileSavePath_(fileSavePath)
{
}

QString Translate::ReplaceBPIO(QString currentBBSetup)
{
    currentBBSetup.replace("&BI1&",BI[0]);
    currentBBSetup.replace("&BI2&",BI[1]);
    currentBBSetup.replace("&BI3&",BI[2]);
    currentBBSetup.replace("&BI4&",BI[3]);
    currentBBSetup.replace("&BI5&",BI[4]);

    currentBBSetup.replace("&BI6&",BI[5]);
    currentBBSetup.replace("&BI7&",BI[6]);
    currentBBSetup.replace("&BI8&",BI[7]);
    currentBBSetup.replace("&BI9&",BI[8]);
    currentBBSetup.replace("&BI10&",BI[9]);

    ///////////////////////多个变量赋值代码转多行赋值代码///////////////////////////
    QString BOName[11] = {"&BO1&","&BO2&","&BO3&","&BO4&","&BO5&","&BO6&","&BO7&","&BO8&","&BO9&","&BO10&"};
    for (int f = 0; f < 10 ; f++)
    {
        QString BOEqual;
        int BOEqualEnd;
        QString BOBuffer;

        while (currentBBSetup.contains(BOName[f],Qt::CaseInsensitive))
        {
            BOEqual = currentBBSetup.section(BOName[f],1);    //获取当前BO所在位置后的内容
            BOEqualEnd = BOEqual.indexOf(';');     //获取当前BO结尾所在位置的结果
            BOBuffer = "";

            for (int i = 0; i < (BO[f].count(',')+1);i++)
            {
                QString BOStartAt = BO[f].section(',',i,i);
                if (BOStartAt != "Null")
                {
                    BOStartAt += BOEqual.left(BOEqualEnd);
                    BOStartAt += "; //Multi Variable To MultiLine \r\n";
                    BOBuffer += BOStartAt;
                    //qDebug(BOStartAt);
                }
            }
            //qDebug()<< "------------" ;
            //qDebug()<< BOEqual ;
            //qDebug()<< "<<<<<<<<<<<" ;
            //qDebug()<<  BOName[f] << "____" << BOName[f]+BOEqual.left(BOEqualEnd)+";" << "__=__" << BOBuffer;
            //qDebug()<<  BOName[f] << "----" << BOBuffer;
            //qDebug()<< "=============" ;

            currentBBSetup.replace(BOName[f]+BOEqual.left(BOEqualEnd)+";",BOBuffer);
        }

    }
    ///////////////////////多个变量赋值代码转多行赋值代码///////////////////////////

    currentBBSetup.replace("&PI1&",PI[0]);
    currentBBSetup.replace("&PI2&",PI[1]);
    currentBBSetup.replace("&PI3&",PI[2]);
    currentBBSetup.replace("&PI4&",PI[3]);
    currentBBSetup.replace("&PI5&",PI[4]);

    currentBBSetup.replace("&PI6&",PI[5]);
    currentBBSetup.replace("&PI7&",PI[6]);
    currentBBSetup.replace("&PI8&",PI[7]);
    currentBBSetup.replace("&PI9&",PI[8]);
    currentBBSetup.replace("&PI10&",PI[9]);

    ///////////////////////多个变量赋值代码转多行赋值代码///////////////////////////
    QString POName[11] = {"&PO1&","&PO2&","&PO3&","&PO4&","&PO5&","&PO6&","&PO7&","&PO8&","&PO9&","&PO10&"};
    for (int f = 0; f < 10 ; f++)
    {
        QString POEqual = currentBBSetup.section(POName[f],1);    //获取当前PO所在位置后的内容
        int POEqualEnd = POEqual.indexOf(';');     //获取当前PO结尾所在位置的结果
        QString POBuffer = "";
        if (POEqual != "")
        {
            for (int i = 0; i < (PO[f].count(',')+1);i++)
            {
                QString POStartAt = PO[f].section(',',i,i);
                if (POStartAt != "Null")
                {
                    POStartAt += POEqual.left(POEqualEnd);POStartAt += "; //Multi Variable To MultiLine \r\n";
                    POBuffer += POStartAt;
                    //qDebug(POStartAt);
                }
            }
        }
        currentBBSetup.replace(POName[f]+POEqual.left(POEqualEnd)+";",POBuffer);
    }
    ///////////////////////多个变量赋值代码转多行赋值代码///////////////////////////

    return currentBBSetup;
}

/*!
 * \brief 将连线图翻译成为代码
 */
void Translate::translateCode()
{
    qDebug() << "开始翻译";

    translateProgress_ = 0;
    //////////////读取翻译缓冲用数据库////////////
    QSqlDatabase dbBuffer=QSqlDatabase::addDatabase("QSQLITE","Buffer");
    dbBuffer.setDatabaseName("./resource/Blocks/Buffer.mpb");
    dbBuffer.open();

    QSqlDatabase dbDict=QSqlDatabase::addDatabase("QSQLITE","Dict");
    //读取翻译缓冲用数据库////////////

    ///////翻译之前来一腿！！！！///////////////////
    QSqlQuery pQuery_(dbBuffer);

    int counter = 0;

qDebug() << "------1-------";
    QFile fileLinkage("Linkage.csv");

    if(!fileLinkage.open(QFile::ReadOnly))
    {
        qDebug() << "文件打开失败";
        qDebug() << fileLinkage.errorString();
    }

    QTextStream in(&fileLinkage);
    pQuery_.exec("delete From Linkage");
    dbBuffer.transaction();
    counter = 0;
    while (!in.atEnd())
    {
        QString str;
        in >> str;
        qDebug() << str;
        QStringList strs = str.split(",");
qDebug() << strs.size();
        if(counter < strs.size())
        {
            QString cmd = QString("INSERT INTO Linkage VALUES('%1','%2','%3','%4')").arg(strs.at(0)).arg(strs.at(1)).arg(strs.at(2)).arg(strs.at(3));
            qDebug() << cmd;

            pQuery_.exec(cmd);

        }
        counter++;
    }
    dbBuffer.commit();
    fileLinkage.close();
    ///////////////////////////////////
    qDebug() << "------2-------";
    QFile fileParameter("Parameter.csv");

            if(!fileParameter.open(QFile::ReadOnly))
            {
                qDebug() << "文件打开失败";
                qDebug() << fileParameter.errorString();
            }

    QTextStream in1(&fileParameter);
    pQuery_.exec("delete From Parameter");
    dbBuffer.transaction();
    counter = 0;

    while (!in1.atEnd())
    {
        QString str;
        in1 >> str;
        qDebug() << str;
        QStringList strs = str.split(",");
qDebug() << strs.size();
        if(counter < strs.size())
        {
            QString cmd = QString("INSERT INTO Parameter VALUES('%1','%2','%3','%4','%5','%6','%7')").arg(strs.at(0)).arg(strs.at(1)).arg(strs.at(2)).arg(strs.at(3)).arg(strs.at(4)).arg(strs.at(5)).arg(strs.at(6));
            qDebug() << cmd;

            pQuery_.exec(cmd);
        }
        counter++;
    }
    dbBuffer.commit();
    fileParameter.close();
    ///////////////////////////////////
    qDebug() << "-------3------";
    QFile fileBB("BBList.csv");

    if(!fileBB.open(QFile::ReadOnly))
    {
        qDebug() << "文件打开失败";
        qDebug() << fileBB.errorString();
    }

    QTextStream in2(&fileBB);

    counter = 0;
pQuery_.exec("delete From BBList");
    dbBuffer.transaction();
    while (!in2.atEnd())
    {
        QString str;
        in2 >> str;
        qDebug() << str;
        QStringList strs = str.split(",");
qDebug() << strs.size();
        if(counter < strs.size())
        {
            QString cmd = QString("INSERT INTO BBList VALUES('%1','%2','%3','%4','%5','%6','%7','%8','%9','%10','%11','%12','%13','%14','%15')").arg(strs.at(0)).arg(strs.at(1)).arg(strs.at(2)).arg(strs.at(3)).arg(strs.at(4)).arg(strs.at(5)).arg(strs.at(6)).arg(strs.at(7)).arg(strs.at(8)).arg(strs.at(9)).arg(strs.at(10)).arg(strs.at(11)).arg(strs.at(12)).arg(strs.at(13)).arg(strs.at(14));
            qDebug() << cmd;

            pQuery_.exec(cmd);
        }
        counter++;
    }
    dbBuffer.commit();
    fileBB.close();
    ///////翻译之后结束的一腿！！！！///////////////////

    //////////////清空上次翻译结果////////////
    QSqlQuery queryDel(dbBuffer);
    queryDel.exec("delete from Code where ROM = '0'");
    //////////////清空上次翻译结果////////////

    QSqlQuery queryInsert(dbBuffer);
    QString queryInsertStr;
    //////////////插入参数代码////////////
    QSqlQuery queryParameter(dbBuffer);
    queryParameter.exec("select ID,Type,Value,Postfix from Parameter");
    while(queryParameter.next())
    {
        queryInsert.exec("select ID from Code where Mark = 'Variable Parameter' order by ID desc limit 1");
        queryInsert.next();

        queryInsertStr = "insert into Code values(";
        queryInsertStr += QString::number(queryInsert.value(0).toInt()+1);
        queryInsertStr += ",'"+queryParameter.value(1).toString() + " LocalParameter_" + queryParameter.value(0).toString() + queryParameter.value(3).toString() + " = " + queryParameter.value(2).toString() + ";" ;
        queryInsertStr += "','Variable Parameter',0)";
        queryInsert.exec(queryInsertStr);
    }
    //////////////插入参数代码////////////

    ////////////翻译主体（检索所有BB）////////////
    QSqlQuery queryBBList(dbBuffer);
    queryBBList.exec("select BB,Type from BBList");

    float resultCount = 0;
    queryBBList.last();
    resultCount = queryBBList.at()+1;//+1因为index从0开始
    queryBBList.first();

    //**************Report Process**************
    //qDebug()<< compileProgress;
    emit signalAdvanceProgress(++translateProgress_, resultCount+1, 500);//+1是因为前面插入参数也是一个步骤
    //**************Report Process**************

    queryBBList.seek(0);
    for (int i =0; i < resultCount ; i++)
    {  //检索BB List列表
        if (i != 0) queryBBList.next();

        QString currentBB = queryBBList.value(0).toString();
        QString currentBBType = queryBBList.value(1).toString();
        qDebug() << currentBB;

        ///////////////////清理BPIO//////////////
        for (int i = 0 ; i < 10 ; i++)
        {
            BI[i] = "Null";
            BO[i] = "Null";
            PI[i] = "Null";
            PO[i] = "Null";
        }
        ///////////////////清理BPIO//////////////
        ///////////////BI////////////////
        QString BIBaseString = currentBB + "_";

        //dbDict.setDatabaseName(("./resource/Blocks/") + currentBBType + ".mpb");
        if(!map_fileName_filePath_.contains(currentBBType))
        {
            qDebug() << "翻译的时候检查模块出错 map_fileName_filePath_没有对应的" << currentBBType;
        }
        dbDict.setDatabaseName(map_fileName_filePath_.value(currentBBType));
        dbDict.open();

        QSqlQuery queryBI(dbDict);
        QString queryBIStr = "select name from behaviorIn order by id";
        queryBI.exec(queryBIStr);

        for (int i = 0;i < 10;i++)
        {
            if (queryBI.next()){
                if (queryBI.value(0).toString() != "")
                {
                    BI[i] = BIBaseString + queryBI.value(0).toString();
                    //qDebug(BI[i]);
                }
            }
        }
        ///////////////BI////////////////
        //qDebug("==========BO===================");
        ///////////////BO///////////////
        QSqlQuery queryBO(dbDict);
        QString queryBOStr = "select name from behaviorOut order by id";
        queryBO.exec(queryBOStr);


        for (int i = 0;i < 10;i++)
        {
            if (queryBO.next()){
                if (queryBO.value(0).toString() != "")    //只运算有输出引脚的部分
                {
                    QString fromPin = currentBB + "_"+queryBO.value(0).toString();  //qDebug(fromPin);
                    //获取当前模块的输出引脚名字
                    QSqlQuery queryLinkage(dbBuffer);
                    QString queryLinkageStr = "select * from Linkage where Come = '"+fromPin+"'";
                    queryLinkage.exec(queryLinkageStr);

                    while(queryLinkage.next())
                    {
                        BO[i] = BO[i] + "," + queryLinkage.value(1).toString();
                    }
                }
            }
        }
        ///////////////BO///////////////
        //qDebug("============PI=================");
        ///////////////PI///////////////
        QString PIBaseString = "LocalParameter_";

        QSqlQuery queryPI(dbBuffer);
        QString queryPIStr = "select pi0,pi1,pi2,pi3,pi4 from BBList where BB = '"+currentBB+"'";
        queryPI.exec(queryPIStr);

        queryPI.next();
        for (int i = 0;i < 10;i++)
        {
            if (queryPI.value(i).toString() != "")
            {
                PI[i] = PIBaseString + queryPI.value(i).toString();
                //qDebug(PI[i]);
            }
        }
        ///////////////PI///////////////
        //qDebug("==========PO===================");
        ///////////////PO///////////////
        QSqlQuery queryPO(dbDict);
        QString queryPOStr = "select name from paramOut order by id";
        queryPO.exec(queryPOStr);


        for (int i = 0;i < 10;i++)
        {
            if (queryPO.next()){
                if (queryPO.value(0).toString() != "")
                {
                    QString fromPin = currentBB + "_"+queryPO.value(0).toString();  //qDebug(fromPin);
                    //获取当前模块的输出引脚名字
                    QSqlQuery queryLinkage(dbBuffer);
                    QString queryLinkageStr = "select * from Linkage where Come = '"+fromPin+"'";
                    queryLinkage.exec(queryLinkageStr);

                    while(queryLinkage.next())
                    {
                        PO[i] = PO[i] + "," + queryLinkage.value(1).toString();
                    }
                }
            }
        }
        ///////////////PO///////////////
        ////////////翻译主体（检索所有BB）////////////

        ////////////////生成BB变量///////////////
        for (int i =0; i < 10;i++)
        {
            if (BI[i] != "Null")
            {
                queryInsert.exec("select ID from Code where Mark = 'Variable Beh IO' order by ID desc limit 1");
                queryInsert.next();


                QSqlQuery queryLinkage(dbBuffer);
                QString queryLinkageStr = "select * from Linkage where Go = '"+BI[i]+"'";
                queryLinkage.exec(queryLinkageStr);

                int startAtBegin = 0;
                while(queryLinkage.next()){
                    if (queryLinkage.value(0).toString() == "Start"){
                        startAtBegin = 1;
                    }
                }
                //用于检测所有相关结果 但只保留一个结果

                //检测是否与Start连接
                queryInsertStr = "insert into Code values(";
                queryInsertStr += QString::number(queryInsert.value(0).toInt()+1);

                if (startAtBegin)
                {
                    queryInsertStr += ",'boolean " + BI[i] + " = true;";
                }else{
                    queryInsertStr += ",'boolean " + BI[i] + " = false;";
                }

                /////检测是否与Start连接 设置是否自动启动
                queryInsertStr += "','Variable Parameter',0)";
                if (BI[i] != "" && BI[i] != "Null") queryInsert.exec(queryInsertStr);
            }
        }
        //////////////////生成每个环节的代码/////////////////////
        QSqlQuery queryLib(dbDict);
        QString queryLibStr = "select codeInclude,codeClass,codeParameter,codeSetup,codePreWork,codeMainWork,codeLastWork,codeVoid from code";
        queryLib.exec(queryLibStr);
        queryLib.next();

        QString currentBBSetup;
        //////////////获取当前BB的资料//////////////

        //////////////0插入Include////////////////
        currentBBSetup = queryLib.value(0).toString();  //qDebug(currentBBSetup);

        queryInsert.exec("select ID from Code where Mark = 'Include' order by ID desc limit 1");
        queryInsert.next();

        currentBBSetup = ReplaceBPIO(currentBBSetup);

        QSqlQuery queryCheckRepeat(dbBuffer);
        QString queryCheckRepeatStr = "select Code from Code where Code = '";
        queryCheckRepeatStr += currentBBSetup;
        queryCheckRepeatStr += "'";
        queryCheckRepeat.exec(queryCheckRepeatStr);
        queryCheckRepeat.next();
        QString result = queryCheckRepeat.value(0).toString();

        if (result == "")
        {
            queryInsertStr = "insert into Code values(";
            queryInsertStr += QString::number(queryInsert.value(0).toInt()+1);
            queryInsertStr += ",'"+currentBBSetup;
            queryInsertStr += "','Include',0)";
            queryInsert.exec(queryInsertStr);
        }
        //qDebug(currentBBSetup);
        //////////////1插入Class////////////////
        currentBBSetup = queryLib.value(1).toString();  //qDebug(currentBBSetup);

        queryInsert.exec("select ID from Code where Mark = 'Variable Class' order by ID desc limit 1");
        queryInsert.next();

        currentBBSetup = ReplaceBPIO(currentBBSetup);

        queryCheckRepeatStr = "select Code from Code where Code = '";
        queryCheckRepeatStr += currentBBSetup;
        queryCheckRepeatStr += "'";
        queryCheckRepeat.exec(queryCheckRepeatStr);
        queryCheckRepeat.next();
        result = queryCheckRepeat.value(0).toString();

        if (result == "")
        {
            queryInsertStr = "insert into Code values(";
            queryInsertStr += QString::number(queryInsert.value(0).toInt()+1);
            queryInsertStr += ",'"+currentBBSetup;
            queryInsertStr += "','Variable Class',0)";
            queryInsert.exec(queryInsertStr);
        }
        //qDebug(currentBBSetup);
        //////////////2插入Parameter////////////////
        currentBBSetup = queryLib.value(2).toString();  //qDebug(currentBBSetup);

        queryInsert.exec("select ID from Code where Mark = 'Variable Parameter' order by ID desc limit 1");
        queryInsert.next();

        currentBBSetup = ReplaceBPIO(currentBBSetup);

        queryCheckRepeatStr = "select Code from Code where Code = '";
        queryCheckRepeatStr += currentBBSetup;
        queryCheckRepeatStr += "'";
        queryCheckRepeat.exec(queryCheckRepeatStr);
        queryCheckRepeat.next();
        result = queryCheckRepeat.value(0).toString();

        if (result == "")
        {
            queryInsertStr = "insert into Code values(";
            queryInsertStr += QString::number(queryInsert.value(0).toInt()+1);
            queryInsertStr += ",'"+currentBBSetup;
            queryInsertStr += "','Variable Parameter',0)";
            queryInsert.exec(queryInsertStr);
        }

        ////////////////3插入Setup资料//////////////
        currentBBSetup = queryLib.value(3).toString();  //qDebug(currentBBSetup);

        queryInsert.exec("select ID from Code where Mark = 'Pin Setup' order by ID desc limit 1");
        queryInsert.next();
        //QString queryInsertPos = queryInsert.value(0).toString(); //qDebug(queryInsertPos);
        //获取插入位置

        //
        currentBBSetup = ReplaceBPIO(currentBBSetup);

        queryCheckRepeatStr = "select Code from Code where Code = '";
        queryCheckRepeatStr += currentBBSetup;
        queryCheckRepeatStr += "'";
        queryCheckRepeat.exec(queryCheckRepeatStr);
        queryCheckRepeat.next();
        result = queryCheckRepeat.value(0).toString();

        if (result == "")
        {
            queryInsertStr = "insert into Code values(";
            queryInsertStr += QString::number(queryInsert.value(0).toInt()+1);
            queryInsertStr += ",'"+currentBBSetup;
            queryInsertStr += "','Pin Setup',0)";
            queryInsert.exec(queryInsertStr);
            //qDebug(currentBBSetup);
        }
        //////////////4插入PreWork////////////////
        currentBBSetup = queryLib.value(4).toString();  //qDebug(currentBBSetup);

        queryInsert.exec("select ID from Code where Mark = 'Pre Work' order by ID desc limit 1");
        queryInsert.next();

        //
        currentBBSetup = ReplaceBPIO(currentBBSetup);

        queryCheckRepeatStr = "select Code from Code where Code = '";
        queryCheckRepeatStr += currentBBSetup;
        queryCheckRepeatStr += "'";
        queryCheckRepeat.exec(queryCheckRepeatStr);
        queryCheckRepeat.next();
        result = queryCheckRepeat.value(0).toString();

        if (result == "")
        {
            queryInsertStr = "insert into Code values(";
            queryInsertStr += QString::number(queryInsert.value(0).toInt()+1);
            queryInsertStr += ",'"+currentBBSetup;
            queryInsertStr += "','Pre Work',0)";
            queryInsert.exec(queryInsertStr);
        }
        //qDebug(currentBBSetup);
        //////////////5插入MainWork////////////////
        currentBBSetup = queryLib.value(5).toString();  //qDebug(currentBBSetup);

        queryInsert.exec("select ID from Code where Mark = 'Main Work' order by ID desc limit 1");
        queryInsert.next();

        currentBBSetup = ReplaceBPIO(currentBBSetup);

        queryCheckRepeatStr = "select Code from Code where Code = '";
        queryCheckRepeatStr += currentBBSetup;
        queryCheckRepeatStr += "'";
        queryCheckRepeat.exec(queryCheckRepeatStr);
        queryCheckRepeat.next();
        result = queryCheckRepeat.value(0).toString();

        if (result == "")
        {
            queryInsertStr = "insert into Code values(";
            queryInsertStr += QString::number(queryInsert.value(0).toInt()+1);
            queryInsertStr += ",'"+currentBBSetup;
            queryInsertStr += "','Main Work',0)";
            queryInsert.exec(queryInsertStr);
        }

        //////////////6插入LastWork////////////////
        currentBBSetup = queryLib.value(6).toString();  //qDebug(currentBBSetup);

        queryInsert.exec("select ID from Code where Mark = 'Last Work' order by ID desc limit 1");
        queryInsert.next();

        currentBBSetup = ReplaceBPIO(currentBBSetup);

        queryCheckRepeatStr = "select Code from Code where Code = '";
        queryCheckRepeatStr += currentBBSetup;
        queryCheckRepeatStr += "'";
        queryCheckRepeat.exec(queryCheckRepeatStr);
        queryCheckRepeat.next();
        result = queryCheckRepeat.value(0).toString();

        if (result == "")
        {
            if (currentBBSetup != "")
            {
                queryInsertStr = "insert into Code values(";
                queryInsertStr += QString::number(queryInsert.value(0).toInt()+1);
                queryInsertStr += ",'"+currentBBSetup;
                queryInsertStr += "','Last Work',0)";
                queryInsert.exec(queryInsertStr);
            }
        }
        //////////////7插入VoidWork////////////////
        currentBBSetup = queryLib.value(7).toString();  //qDebug(currentBBSetup);

        queryInsert.exec("select ID from Code where Mark = 'Void Work' order by ID desc limit 1");
        queryInsert.next();

        //
        currentBBSetup = ReplaceBPIO(currentBBSetup);

        queryInsertStr = "insert into Code values(";
        queryInsertStr += QString::number(queryInsert.value(0).toInt()+1);
        queryInsertStr += ",'"+currentBBSetup;
        queryInsertStr += "','Void Work',0)";
        queryInsert.exec(queryInsertStr);

        //**************Report Process**************
        //qDebug()<< compileProgress;
        emit signalAdvanceProgress(++translateProgress_, resultCount+1, 500);//+1是因为前面插入参数也是一个步骤
        //**************Report Process**************
    }

    dbDict.close();

    qDebug("Success GenCode !!!");
    /////////////////////Save File//////////////////


    //    {
    //        //确保目录存在
    //        QFileInfo infro(fileSavePath_);
    //        QDir dir(infro.path());
    //        if(dir.exists())
    //        {
    //            qDebug() << "The Temp dir not exists, and will be create it";
    //            if(!dir.mkpath(infro.path()))
    //            {
    //                qDebug() << "create Temp fail";
    //            }
    //        }
    //    }
    QFile file(fileSavePath_);
    if (!file.open(QIODevice::WriteOnly))
    {
        emit signalTranslateError();
        emit signalError(FileError);
        return;
    }
    QTextStream stream(&file);
    //创建文件和文件流

    QSqlQuery query(dbBuffer);
    query.exec("select Code from Code order by ID");
    //以下执行相关QSL语句
    while(query.next())
    {
        QString string = query.value(0).toString();
        //qDebug(qPrintable( string ));
        //qDebug(string);
        if (string != "")
        {
            stream<<string<<endl;
        }
        //将Code的每一行都写入文件中
    }
    /////////////////////Save File//////////////////
    qDebug("Success Save File  !!!");
    dbBuffer.close();
    file.close();
}
