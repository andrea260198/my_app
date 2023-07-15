// ITask is an interface for a task.

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
    QString getName() { return mName; };
    long getPeriod() { return mPeriod; };

protected:
    QString mName;  // Name of the task.
    long mPeriod;  // [s] Task shall be repeated every <mPeriod> seconds.
};

