// The Scheduler class implements a simple scheduler using the signal emitted by QTimer object on a regular basis.
// Note that the Scheduler is part of the main thread. The entire app runs on a single thread.

#pragma once

#include <QMap>
#include <QDebug>
#include "ITask.h"


class Scheduler : public QObject
{
    Q_OBJECT

public:
    Scheduler();
    ~Scheduler();

    void initialize();
    QMap<ITask *, QTimer *> createTaskTimerMap();

private:
    QList<ITask *> mTasks;
    QMap<ITask *, QTimer *> mTaskTimerMap;  // This map associates a QTimer object to every task.

    ITask *pTask1;
    ITask *pTask2;
    QTimer *pTimer1, *pTimer2;
};

