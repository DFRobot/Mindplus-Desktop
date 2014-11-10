#ifndef PARAM_H
#define PARAM_H

#include <QObject>

class Param : public QObject
{
	Q_OBJECT
public:
	explicit Param(QObject *parent = 0);

signals:

public slots:

private:
	QString value_;
};

#endif // PARAM_H
