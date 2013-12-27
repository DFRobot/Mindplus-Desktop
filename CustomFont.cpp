#include "CustomFont.h"
#include <QDir>
#include <QString>
#include <QFont>
#include <QStringList>
#include <QFileInfoList>
#include <QDebug>
#include <QFontDatabase>

QMap<QString, QString> CustomFont::map_localFontName_path_ = QMap<QString, QString>();//还真恶心

/*!
 * \brief CustomFont::getCustomFont 若成功则返回自定义字体, 若失败返回自定义字体
 * \param fontName 自定义字体的名字(包含后缀, 在./resource/fonts/os/)
 * \param pointSize 字体大小(磅)
 * \param weight 字体大小(??)
 * \param italic 斜体
 * \return QFont对象
 */
QFont CustomFont::getCustomFont(const QString &fontName, int pointSize, int weight, bool italic)
{//这里有效率问题
    initData();
    int fontId;
    QFont font;
    if(!map_localFontName_path_.isEmpty()
            && map_localFontName_path_.contains(fontName))
    {
        fontId = QFontDatabase::addApplicationFont(map_localFontName_path_.value(fontName));
        QString fontFamily = QFontDatabase::applicationFontFamilies ( fontId ).at(0);
        font = QFont(fontFamily, pointSize, weight, italic);
        font.setStyleStrategy(QFont::PreferAntialias);
    }
    else
    {
        qDebug() << "不能加载对应的字体" << fontName << "现在加载该系统下的默认字体";
    }
    return font;
}

/*!
 * \brief CustomFont::initData 针对不同的操作系统环境初始化fonts的数据
 */
void CustomFont::initData()
{
    QString path = "./resource/fonts/";
    QString os;
#ifdef Q_OS_WIN
    os = "Windows";
#elif defined Q_OS_LINUX
    os = "Linux";
#elif defined  Q_OS_MAC
    os = "Mac";
#endif

    QString fontPath = path+os + "/" ;
    qDebug() << fontPath;

    QDir fontDir(fontPath);
    fontDir.setFilter(QDir::Files);
    QStringList fontNameList = fontDir.entryList();
    foreach (QString fontName, fontNameList)
    {
        map_localFontName_path_.insert(fontName, fontPath+fontName);
    }
}

