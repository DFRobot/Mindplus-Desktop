#include "ArduinoUploader.h"
#include <QDebug>
#include <QMessageBox>

ArduinoUploader::ArduinoUploader(const QString &serial, const QString &board, int sketch, bool debug, QObject *parent)
    : ToolBase(serial, board, sketch, debug, parent)
    , currentPath_("")
    , pUpload_(NULL)
{

}

ArduinoUploader::~ArduinoUploader()
{
}

void ArduinoUploader::slotReadStandarOutput()
{
    qDebug() << endl;
    QString errorString = pUpload_->readAllStandardOutput();
    qDebug() << "111111111 standard out put start";
    qDebug() << errorString;
    //成功创建Hex文件-->>编译完成
	if(errorString.contains("Compiliation successful completed"))
    {
        emit signalCompileProgress(2, 2, 500);
        emit signalCompileEnd();
    }

    //上传错误--端口号错误
	if(errorString.contains("error opening port"))
    {
        //对外通知端口号错误
        emit signalPortError(tr("error opening port"));
    }

    qDebug() << "111111111 standard out put end";
    qDebug() << endl;
}

void ArduinoUploader::slotReadStandarError()
{
    QString errorString = pUpload_->readAllStandardError();
    qDebug() << endl;
    qDebug() << "000000000 standard error start";
    qDebug() << errorString;
    QRegExp regExp("error: invalid conversion from '.+' to '.+'");

    //编译错误--类型转换错误
    int pos = errorString.indexOf(regExp);
    if(pos >= 0)
    {
        QString tmp = regExp.cap(0).left(regExp.cap(0).indexOf("\n"));
        qDebug() << "regExp.cap(0) :" << tmp;
        qDebug() << "regExp.cap(1) :" << regExp.cap(1);
        qDebug() << "regExp.cap(2) :" << regExp.cap(2);
        emit signalTypeConversionError(tmp);
    }

    //选错版--这里也有选错版.唉这返回的信息真实凌乱不堪啊
    if(errorString.contains("no new port found"))
    {
        emit signalBoardError("board error");
    }

    //上传错误--端口号错误
	if(errorString.contains("avrdude: ser_open(): can't open device"))
    {
        //对外通知端口号错误
        emit signalPortError(tr("Serialport error ,and can't open device"));
    }
    if(errorString.contains("not in sync"))
    {//如果猜得没错就是它了
         //对外通知板子类型错误
        emit signalBoardError(tr("Serialport number error"));
    }

    //编译上传成功
	if(errorString.contains("bytes of flash verified")
			&& errorString.contains("100%"))
	{
		emit signalWriteProProgress(1, 1, 500);
	}

    qDebug() << "000000000 standard error end";
    qDebug() << endl;
}

void ArduinoUploader::slotFinish(int exitCode, QProcess::ExitStatus exitStatus)
{
    if(QProcess::NormalExit == exitStatus)
    {
		//这里不符合逻辑呢
		//emit signalCompileProgress(2, 2, 500);
    }
    else if(QProcess::CrashExit)
    {
        qDebug() << "process crash!";
    }
    else
    {
        qDebug() << "process exit in other reason exitCode: " << exitCode << "exitStatus: " << exitStatus;
    }
}

void ArduinoUploader::compile()
{
    emit signalCompileStart();

    currentPath_ = QDir::current().currentPath();
    qDebug() << "current : " << currentPath_;
#ifdef Q_OS_MAC
	QDir::setCurrent("./resource/tools/ArduinoUploader/ArduinoUploader.app/Contents/MacOS");
	//QDir::setCurrent("./resource/tools/ArduinoUploader");
#else
    QDir::setCurrent("./resource/tools/ArduinoUploader");
#endif
    pUpload_ = new QProcess();
	connect(pUpload_, SIGNAL(readyReadStandardOutput()), this, SLOT(slotReadStandarOutput()));
	connect(pUpload_, SIGNAL(readyReadStandardError()), this, SLOT(slotReadStandarError()));
#ifdef Q_OS_WIN32
	QString cmd = tr("ArduinoUploader.exe ./Temp/code.cpp %1 %2").arg(boardType_).arg(serialPort_);
#else
	QString cmd = tr("./ArduinoUploader ./Temp/code.cpp %1 %2").arg(boardType_).arg(serialPort_.remove("/dev/"));
#endif
    qDebug() << "调用命令是: " << cmd;
	pUpload_->start(cmd);
	if(pUpload_->waitForStarted())
    {
        qDebug() << "uploader start success!";
        connect(pUpload_, SIGNAL(finished(int,QProcess::ExitStatus)), this, SLOT(slotFinish(int,QProcess::ExitStatus)));
    }
    else
    {
        qDebug() << "uploader start fail!";
    }
    QDir::setCurrent(currentPath_);
    emit signalCompileProgress(1, 2, 500);
}
