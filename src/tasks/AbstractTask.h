// ITask is an interface for a task.

#pragma once

#include <QTimer>
#include <QString>
#include <QObject>


class AbstractTask : public QObject
{
    Q_OBJECT

public:
    AbstractTask(const QString &name, long period)
        : mName(name)
        , mPeriod(period)
    {
    }

    virtual void run() = 0;
    QString getName() { return mName; };
    long getPeriod() { return mPeriod; };
    void setPeriod(long period) { mPeriod = period;};

protected:
    QString mName;  // Name of the task.
    long mPeriod;  // [s] Task shall be repeated every <mPeriod> seconds.
};

