#include <QApplication>
#include "WidgetMain.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#if QT_VERSION < 0x050000
#include <QTextCodec>
#endif
#include <QDebug>
#include <QMessageBox>
#include <QFontDatabase>
#include <QSplashScreen>
#include <QPainter>
#include <QDesktopWidget>
#include "Sleep.h"

int main(int argc, char *argv[])
{
    //动态库加载
#ifdef Q_OS_MAC
//	QApplication::addLibraryPath("Mind+.app/Contents/Plugins/accessible");
//	QApplication::addLibraryPath("Mind+.app/Contents/Plugins/bearer/");
//	QApplication::addLibraryPath("Mind+.app/Contents/Plugins/codecs/");
//	QApplication::addLibraryPath("Mind+.app/Contents/Plugins/imageformats/");
//	QApplication::addLibraryPath("Mind+.app/Contents/Plugins/sqldrivers/");
#else
    QApplication::addLibraryPath("./resource/plugins");
    QApplication::addLibraryPath("./resource/plugins/codecs/");
    QApplication::addLibraryPath("./resource/plugins/imageformats/");
    QApplication::addLibraryPath("./resource/plugins/sqldrivers/");
	QApplication::addLibraryPath("./resource/plugins/platforms/");
#endif
    QApplication app(argc, argv);

    QFont font;
#ifdef Q_OS_WIN32
    font = QFont("arial", 11, QFont::Normal,false);
#elif defined(Q_OS_LINUX)
    font = QFont("Sans", 11, QFont::Normal,false);
#elif defined Q_OS_MAC
    font = QFont("Helvetica", 11, QFont::Normal,false);
#endif
    //设置默认字体
    font.setStyleStrategy(QFont::PreferAntialias);
    QApplication::setFont(font);

#if QT_VERSION < 0x050000
    qDebug() << "qt5以下的版本, 从QTextCodec设置全局字符集";
    QTextCodec*codec=QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForTr(codec);
    QTextCodec::setCodecForCStrings(codec);
#endif

    //启动画面
    QSplashScreen splash(QPixmap(QString("./resource/images/startup/startupIMG_1.png")));
    splash.setDisabled(true);   //禁用用户的输入响应事件
    splash.show();

    for(int i = 0 ; i < 68 ; i ++ )
    {
		//://resource/images/startup/startupIMG_
		//QPixmap pix = QString("./resource/images/startup/startupIMG_%1.png").arg(QString::number(i));
		QPixmap pix = QString("://resource/images/startup/startupIMG_%1.png").arg(QString::number(i));
        QPainter paint(&pix);
        paint.setPen(QPen(QColor(255, 255, 255)));
        //如果要设置字体就setFont()
        QFont font = paint.font();
        font.setPointSize(9);
        paint.setFont(font);
		paint.drawText(QRect(10, 10, 200, 40), Qt::AlignLeft, QString("Version:v0.9.6b"));

        splash.setPixmap(pix);
#ifdef Q_OS_Win32
		Sleep::sleep(8);
#else
		app.processEvents();
#endif
		Sleep::sleep(20);
    }
    Sleep::sleep(1000);

    WidgetMain w;
#ifdef Q_OS_MAC
    w.setWindowIcon(QIcon("v095_logo_macx.icns"));//竟然没有用啊
#elif defined(Q_OS_WIN32)
	w.setWindowIcon(QIcon("./resource/images/icon/v095_logop_4_48x48x8.png"));//竟然没有用啊
#endif
	w.move((app.desktop()->width() - w.width())/2, (app.desktop()->height() - w.height())/2);
    w.setWindowTitle("Mind+");

    w.show();
    splash.finish(&w);
    return app.exec();
}
