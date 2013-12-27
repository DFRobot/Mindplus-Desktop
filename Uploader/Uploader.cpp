#include "Uploader.h"
#include <QDebug>
#include <QSettings>
#include "Translate.h"
#include "ToolsFactory.h"
#include "ToolBase.h"
#include "DFRobotUploader.h"
#include "ArduinoUploader.h"

Uploader::Uploader(const QString &fileSavePath, const QString &serialNumber, const QString &boardType, QObject *parent)
    : QObject(parent)
    , pTranslate_(new Translate(fileSavePath, this))
    , pToolFactory_(new ToolFactory(serialNumber,  boardType, this))
    , pTool_(NULL)
{
    connect(pTranslate_, SIGNAL(signalTranslateStart()), this, SIGNAL(signalTranslateStart()));
    connect(pTranslate_, SIGNAL(signalTranslateEnd()), this, SIGNAL(signalTranslateEnd()));
    connect(pTranslate_, SIGNAL(signalTranslateError()), this, SIGNAL(signalTranslateError()));
	//编译进度
	connect(pTranslate_, SIGNAL(signalAdvanceProgress(float,float,int)), this, SLOT(slotTranslateProgress(float,float,int)));

    QSettings settingTmp("./resource/setting.ini", QSettings::IniFormat);
    QString value = settingTmp.value("Normal/uploader").toString();
    if(value == "ArduinoUploader")
    {
        //调用stanly的
        qDebug() << "调用stanly的";
        pTool_ = pToolFactory_->createTool(ToolFactory::SillustaniUploader);
    }
    else if(value == "DFRobotUploader")
    {
        //调用seifer的
        qDebug() << "调用seifer的";
        pTool_ = pToolFactory_->createTool(ToolFactory::SeiferUploader);
    }
    if(pTool_)
    {
        connect(pTool_, SIGNAL(signalCompileStart()), this, SIGNAL(signalCompileStart()));
        connect(pTool_, SIGNAL(signalCompileError(QString)), this, SIGNAL(signalCompileError(QString)));
        connect(pTool_, SIGNAL(signalCompileEnd()), this, SIGNAL(signalCompileEnd()));
        connect(pTool_, SIGNAL(signalCompileProgress(float,float,int)), this, SLOT(slotCompileProgress(float,float,int)));

        connect(pTool_, SIGNAL(signalWriteProStart()), this, SIGNAL(signalWriteProStart()));
        connect(pTool_, SIGNAL(signalWriteProError()), this, SIGNAL(signalWriteProError()));
        connect(pTool_, SIGNAL(signalWriteProEnd()), this, SIGNAL(signalWriteProEnd()));
        connect(pTool_, SIGNAL(signalWriteProProgress(float,float,int)), this, SLOT(slotWriteProProgress(float,float,int)));

        ///////////////////////////
        //报告错误
        connect(pTool_, SIGNAL(signalBoardError(QString)), this, SIGNAL(signalBoardError(QString)));
        connect(pTool_, SIGNAL(signalPortError(QString)), this, SIGNAL(signalPortError(QString)));
        connect(pTool_, SIGNAL(signalTypeConversionError(QString)),this, SIGNAL(signalTypeConversionError(QString)));
    }
}

void Uploader::slotStart()
{
    emit signalTranslateStart();
    pTranslate_->translateCode();
    emit signalTranslateEnd();

    if(pTool_)
    {
        pTool_->start();
    }
}

/*!
 * \brief 处理翻译进度的槽 (0%~60%)
 * \param current 当前进度
 * \param total 总步骤数
 * \param sec 进度显示时常(毫秒)
 */
void Uploader::slotTranslateProgress(float current, float total, int sec)
{
    qDebug() << "来翻译进度了" <<current <<" "<< total <<  "  "<< sec;
    emit signalCurrentProgress(60/100.0 * current/total, 500);
}

/*!
 * \brief 处理编译进度的槽 (60%~90%)
 * \param current 当前进度
 * \param total 总步骤数
 * \param sec 进度显示时常(毫秒)
 */
void Uploader::slotCompileProgress(float current, float total, int sec)
{
    qDebug() << "来编译进度了" <<current <<" "<< total <<  "  "<< sec << 60/100.0 + 30/100.0 * (current/total) << current/total;
    emit signalCurrentProgress(60/100.0 + 30/100.0 * (current/total), 500);
}

/*!
 * \brief 处理烧写进度的槽
 * \param current 当前进度
 * \param total 总步骤数
 * \param sec 进度显示时常(毫秒)
 */
void Uploader::slotWriteProProgress(float current, float total, int sec)
{
    qDebug() << "来烧写进度了" <<current <<" "<< total <<  "  "<< sec << 90/100.0 + 10/100.0 * current/total << current/total;
    emit signalCurrentProgress(90/100.0 + 10/100.0 * current/total, 500);
}
