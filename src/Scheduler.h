// The Scheduler class implements a simple scheduler using the signal emitted by QTimer object on a regular basis.
// Note that the Scheduler is part of the main thread. The entire app runs on a single thread.

#pragma once

#include <QMap>
#include <QDebug>
#include <memory>
#include "tasks/ITask.h"


typedef QMap<std::shared_ptr<ITask>, std::shared_ptr<QTimer>> task_timer_map_t;


class Scheduler : public QObject
{
    Q_OBJECT

public:
    Scheduler();
    ~Scheduler();

    void initialize();
    task_timer_map_t createTaskTimerMap();

private:
    task_timer_map_t mTaskTimerMap;  // This map associates a QTimer object to every task.

    std::shared_ptr<ITask> pTask1, pTask2;
    std::shared_ptr<QTimer> pTimer1, pTimer2;
};

