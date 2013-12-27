#ifndef UPLOADER_H
#define UPLOADER_H

#include <QObject>
#include <QPointer>
class Translate;
class ToolFactory;
class ToolBase;

/*!
 * \brief Uploader是负责整个翻译,编译,烧写的类
 */
class Uploader : public QObject
{
    Q_OBJECT
public:
    explicit Uploader(const QString &fileSavePath, const QString &serialNumber, const QString &boardType, QObject *parent = 0);

signals:
    //开始
    void signalTranslateStart();
    void signalCompileStart();
    void signalWriteProStart();

    //错误
    void signalTranslateError();
    void signalCompileError(const QString &errorString);
    void signalWriteProError();

    //完成
    void signalTranslateEnd();
    void signalCompileEnd();
    void signalWriteProEnd();

    //在内部计算好, 对外有一个统一的进度
    void signalCurrentProgress(float progress, int sec);

    /////////////////////////////////////////
    //转发ToolBase的信号（主要是错误信息）
    void signalTypeConversionError(const QString &error);
    void signalPortError(const QString &error);
    void signalBoardError(const QString &error);

public slots:
    void slotStart();
    void slotTranslateProgress(float current, float total, int sec);
    void slotCompileProgress(float current, float total, int sec);
    void slotWriteProProgress(float current, float total, int sec);

private:

private:
    Translate *pTranslate_;
    ToolFactory *pToolFactory_;
    ToolBase *pTool_;
};

#endif // UPLOADER_H
