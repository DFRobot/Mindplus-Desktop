#ifndef ARDUINOUPLOADER_H
#define ARDUINOUPLOADER_H

#include "ToolBase.h"
#include <QDir>

class ArduinoUploader : public ToolBase
{
    Q_OBJECT
public:
    explicit ArduinoUploader(const QString &serial, const QString &board, int sketch = -1, bool debug = false, QObject *parent = 0);
    ~ArduinoUploader();

signals:

public slots:
	void slotReadStandarOutput();
	void slotReadStandarError();
    void slotFinish(int exitCode, QProcess::ExitStatus exitStatus);

private:
    virtual void compile(); //! 编译

private:
    QString currentPath_;
    QProcess *pUpload_;
};

#endif // ARDUINOUPLOADER_H
