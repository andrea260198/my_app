#pragma once

#include <QMap>
#include <vector>
#include "ITask.h"
#include "PrinterTask.h"
#include "FinderTask.h"


class Scheduler : public QObject
{
    Q_OBJECT

public:
    Scheduler();
    ~Scheduler();

private:
    QList<ITask *> mTasks;
    QMap<ITask *, QTimer *> mTaskTimerMap;

    ITask *pTask1;
    ITask *pTask2;
    QTimer *pTimer1, *pTimer2;
};

