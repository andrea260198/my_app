#include "Scheduler.h"
#include "PrinterTask.h"
#include "FinderTask.h"


Scheduler::Scheduler()
{
    mTaskTimerMap = createTaskTimerMap();

    for ( auto [task, timer] : mTaskTimerMap.asKeyValueRange() )
    {
        // Every time the timer emits the timout signal, the task is executed.
        // "Qt::QueuedConnection" option specifies that tasks shall be executed sequentially.
        // Note that the tasks will run in the main thread.
        QObject::connect(timer.get(), &QTimer::timeout, task.get(), &ITask::run, Qt::QueuedConnection);
    }
}


task_timer_map_t Scheduler::createTaskTimerMap()
{
    task_timer_map_t taskTimerMap;

    pTask1 = std::make_shared<PrinterTask>();
    pTimer1 = std::make_shared<QTimer>();
    pTimer1->start( 1'000 * pTask1->getPeriod() );  // Emit QTimer::timeout signal every 10 sec.  TODO: change time to 10 sec

    pTask2 = std::make_shared<FinderTask>();
    pTimer2 = std::make_shared<QTimer>();
    pTimer2->start( 1'000 * pTask2->getPeriod() );  // Emit QTimer::timeout signal every 30 sec.  TODO: change time to 30 sec

    taskTimerMap.insert(pTask1, pTimer1);
    taskTimerMap.insert(pTask2, pTimer2);

    return taskTimerMap;
}
