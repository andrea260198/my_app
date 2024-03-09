// The Scheduler class implements a simple scheduler using the signal emitted by QTimer object on a regular basis.
// Note that the Scheduler is part of the main thread. The entire app runs on a single thread.

#pragma once

#include <QMap>
#include <QDebug>
#include <memory>
#include "tasks/AbstractTask.h"


using task_timer_map_t = QMap<std::shared_ptr<AbstractTask>, std::shared_ptr<QTimer>>;
using task_list_t = QList<std::shared_ptr<AbstractTask>>;


class Scheduler : public QObject
{
    Q_OBJECT

public:
    Scheduler();

private:
    void setTaskTimerMap();
    void setTaskFrequency();
    void setTaskList();
    void connectTaskAndTimer();

    task_list_t mTaskList;
    task_timer_map_t mTaskTimerMap;  // This map associates a QTimer object to every task.

    std::shared_ptr<AbstractTask> pTask1, pTask2;
    std::shared_ptr<QTimer> pTimer1, pTimer2;
};

