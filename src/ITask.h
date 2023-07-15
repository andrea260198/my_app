// ITask is an interface for every task that can be created in the future.

#pragma once

#include <QTimer>
#include <QString>
#include <QObject>


class ITask : public QObject
{
    Q_OBJECT

public:
//    ITask();
//    virtual ~ITask();

    virtual void run() = 0;
    QString getName() { return name; };

private:
    QString name;
};

