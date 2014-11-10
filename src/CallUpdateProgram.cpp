#include "CallUpdateProgram.h"
#include <QProcess>

CallUpdateProgram::CallUpdateProgram(QObject *parent) :
    QObject(parent)
{

}

void CallUpdateProgram::slotCallUpdateProgram()
{
    QProcess::execute("MindUpgrader.exe");
}
