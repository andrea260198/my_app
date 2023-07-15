#include "Scheduler.h"
#include "PrinterTask.h"
#include "FinderTask.h"


Scheduler::Scheduler()
{
    initialize();
}


Scheduler::~Scheduler() {
    delete pTask1;
    delete pTask2;
    delete pTimer1;
    delete pTimer2;
}


void Scheduler::initialize()
{
    mTaskTimerMap = createTaskTimerMap();

    for ( auto iter : mTaskTimerMap.toStdMap() )
    {
        ITask *pTask = iter.first;
        QTimer *pTimer = iter.second;

        // Every time the timer emits the timout signal, the task is executed.
        // "Qt::QueuedConnection" option specifies that tasks shall be executed sequentially.
        // Note that the tasks will run in the main thread.
        QObject::connect(pTimer, &QTimer::timeout, pTask, &ITask::run, Qt::QueuedConnection);
    }
}


QMap<ITask *, QTimer *> Scheduler::createTaskTimerMap() {
    QMap<ITask *, QTimer *> taskTimerMap;

    pTask1 = new PrinterTask();
    pTimer1 = new QTimer();
    pTimer1->start( 1'000 * pTask1->getPeriod() );  // Emit QTimer::timeout signal every 10 sec.  TODO: change time to 10 sec

    pTask2 = new FinderTask();
    pTimer2 = new QTimer();
    pTimer2->start( 1'000 * pTask2->getPeriod() );  // Emit QTimer::timeout signal every 30 sec.  TODO: change time to 30 sec

    taskTimerMap.insert(pTask1, pTimer1);
    taskTimerMap.insert(pTask2, pTimer2);

    return taskTimerMap;
}
