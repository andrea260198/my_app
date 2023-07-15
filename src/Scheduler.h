#pragma once

//#include <QThread>
#include <QMap>
#include <vector>
#include "Task.h"


class Scheduler : public QObject
{
    Q_OBJECT

public:
    Scheduler();
    ~Scheduler();

private:
    std::vector<Task> mTasks;
    QMap<Task *, QTimer *> mTimersMap;
    std::vector<Task> mQueue;


    Task *pTask1, *pTask2;
    QTimer *pTimer1, *pTimer2;
};

