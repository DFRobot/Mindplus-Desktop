#ifndef CALLUPDATEPROGRAM_H
#define CALLUPDATEPROGRAM_H

#include <QObject>

class CallUpdateProgram : public QObject
{
    Q_OBJECT
public:
    explicit CallUpdateProgram(QObject *parent = 0);

signals:

public slots:
    void slotCallUpdateProgram();
};

#endif // CALLUPDATEPROGRAM_H
