#ifndef TRANSLATE_H
#define TRANSLATE_H

#include <QObject>
#include <QMap>
/*!
 * \brief Translate是Rex的翻译引擎, 剥离了编译上传的关联, 这里只做代码的翻译生成
 */

class Translate : public QObject
{
    Q_OBJECT
public:
    explicit Translate(const QString &fileSavePath, QObject *parent = 0);

    /*!
     * \brief TranslateError翻译部分的错误
     */
    enum TranslateError
    {
        FileError //! 文件错误
    };
    void translateCode();
    static QMap<QString, QString> map_fileName_filePath_;

signals:
    void signalTranslateStart();
    void signalAdvanceProgress(float current, float total, int sec);
    void signalTranslateError();
    void signalError(TranslateError errorType);
    void signalTranslateEnd();

public slots:

private:
    QString ReplaceBPIO(QString currentBBSetup);

private:
    QString BI[10];
    QString BO[10];
    QString PI[10];
    QString PO[10];
    float translateProgress_;
    QString fileSavePath_;
};

#endif // TRANSLATE_H
