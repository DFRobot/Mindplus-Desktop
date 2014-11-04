#include "DFRobotUploader.h"
#include <QDir>
#include <QDebug>

DFRobotUploader::DFRobotUploader(const QString &serial, const QString &board, int sketch, bool debug, QObject *parent)
    :  ToolBase(serial, board, sketch, debug, parent)
{
}

DFRobotUploader::~DFRobotUploader()
{

}

void DFRobotUploader::setup()
{
    QDir dir("./");
#ifdef Q_WS_WIN32
    if(dir.exists("upload.bat"))
    {
        dir.remove("upload.bat");
    }
    QFile file("./upload.bat");
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        qDebug() << "can't open file";
        file.close();
        return ;
    }
    QTextStream out(&file);
    out.setCodec("gbk");
    //QString path = dir.currentPath().replace("/", "\\") + "\\" + "resource\\tools\\DFRobotUploader";
    QString path = dir.path() + "/resource/tools/DFRobotUploader";
    path = QDir::toNativeSeparators(path);

    out <<"cd " << path <<endl;
    out << QString("DFRobotUploader.exe %1\\Code\\Code.ino %2 %3").arg(path).arg(serialPort_).arg(boardType_) <<endl;

    file.close();
#elif defined(Q_WS_LINUX)
//
#elif defined(Q_WS_MAC)
//
#endif
}

void DFRobotUploader::compile()
{
    emit signalCompileStart();

    QProcess::execute("upload.bat");

    emit signalCompileProgress(1, 1, 500);
    emit signalCompileEnd();
}
