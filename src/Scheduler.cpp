#include "Scheduler.h"
#include "PrinterTask.h"
#include "FinderTask.h"


Scheduler::Scheduler()
{
    initialize();
}


Scheduler::~Scheduler()
{

}


void Scheduler::initialize()
{
    mTaskTimerMap = createTaskTimerMap();

    for ( const auto &iter : mTaskTimerMap.toStdMap() )
    {
        auto pTask = iter.first.get();
        auto pTimer = iter.second.get();

        // Every time the timer emits the timout signal, the task is executed.
        // "Qt::QueuedConnection" option specifies that tasks shall be executed sequentially.
        // Note that the tasks will run in the main thread.
        QObject::connect(pTimer, &QTimer::timeout, pTask, &ITask::run, Qt::QueuedConnection);
    }
}


task_timer_map_t Scheduler::createTaskTimerMap() {
    decltype(mTaskTimerMap) taskTimerMap;

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
