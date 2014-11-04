#ifndef DFROBOTUPLOADER_H
#define DFROBOTUPLOADER_H

#include "ToolBase.h"
/* 被废弃 */
class DFRobotUploader : public ToolBase
{
    Q_OBJECT
public:
    explicit DFRobotUploader(const QString &serial, const QString &board, int sketch = -1, bool debug = false, QObject *parent = 0);
	~DFRobotUploader();
	void setup();
signals:

public slots:

private:
    virtual void compile(); //! 编译
};

#endif // DFROBOTUPLOADER_H
