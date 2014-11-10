#ifndef TOOLBASE_H
#define TOOLBASE_H

#include <QObject>
#include <QPointer>
#include <QProcess>
/*!
 * \brief  编译烧写工具基类
 */
class ToolBase : public QObject
{
    Q_OBJECT
public:
    virtual ~ToolBase();

    /*!
     * \brief 错误类型
     */
    enum ToolError
    {
        SetupError,
        CompileError,
        WriteProError,
        ClearError
    };
    void start();

signals:
    void signalSetupStart();
    void signalCompileStart();
    void signalWriteProStart();
    void signalClearStart();

    void signalSetupError();
    void signalCompileError(const QString &errorString);
    void signalWriteProError();
    void signalClearError();

    void signalSetupEnd();
    void signalCompileEnd();
    void signalWriteProEnd();

    void signalError(ToolError errorType);
    void signalCompileProgress(float current, float total, int sec);
    void signalWriteProProgress(float current, float total, int sec);

    ///////////////////////////////////
    void signalTypeConversionError(const QString &error);
    void signalPortError(const QString &error);
    void signalBoardError(const QString &error);

protected:
    explicit ToolBase(const QString &serial, const QString &board, int sketch = -1, bool debug = false, QObject *parent = 0);

    virtual void compile() = 0; //! 编译
protected:
    QPointer<QProcess> pExternalProcess_;//! 调用的外部程序指针
	QString boardType_;//! 板子类型
	QString serialPort_;//! 串口号
    int sketch_;
    bool debug_;//! 编译模式[normal|debug]
    QString toolPath_;
    QString codePath_;
    QString cmd_;
};

#endif // TOOLBASE_H
