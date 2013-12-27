#include "ToolBase.h"
#include <QDebug>
ToolBase::ToolBase(const QString &serial, const QString &board, int sketch, bool debug, QObject *parent)
    : QObject(parent)
    , pExternalProcess_(new QProcess())
    , boardType_(serial)
    , serialPort_(board)
    , sketch_(sketch)
    , debug_(debug)
    , toolPath_("./resource/tools/")
    , codePath_("")
    , cmd_("")
{
}

ToolBase::~ToolBase()
{
    if(pExternalProcess_)
    {
        pExternalProcess_.data()->deleteLater();
        pExternalProcess_ = NULL;
    }
}

void ToolBase::start()
{
	compile();
}
