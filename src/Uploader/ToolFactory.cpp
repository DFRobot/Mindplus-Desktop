#include "ToolsFactory.h"
#include <QDebug>

#include "ToolBase.h"
#include "ArduinoUploader.h"
#include "DFRobotUploader.h"
ToolFactory::ToolFactory(const QString &serialNumber, const QString &boardType, QObject *parent)
    : QObject(parent)
    , serial_(serialNumber)
    , board_(boardType)
{
}

ToolBase *ToolFactory::createTool(ToolFactory::ToolType toolType)
{
    ToolBase *pToolBase = NULL;
    switch (toolType)
    {
        case ToolFactory::SillustaniUploader:
        {
            qDebug() << "create ArduinoUploader ";
            pToolBase = new ArduinoUploader(serial_, board_);
            break;
        }
        case ToolFactory::SeiferUploader:
        {
            qDebug() << "create DFRobotUploader ";
            pToolBase = new DFRobotUploader(serial_, board_);
            break;
        }
        default:
        {
            //..
            break;
        }
    }
    return pToolBase;
}
