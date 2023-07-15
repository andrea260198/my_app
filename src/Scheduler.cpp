#include "Scheduler.h"


Scheduler::Scheduler()
{
    pTask1 = new PrinterTask();
    pTimer1 = new QTimer();
    pTimer1->start(1'000);  // Emit QTimer::timeout signal every 10 sec.

    pTask2 = new FinderTask();
    pTimer2 = new QTimer();
    pTimer2->start(5'000);  // Emit QTimer::timeout signal every 30 sec.

    mTaskTimerMap.insert(pTask1, pTimer1);
    mTaskTimerMap.insert(pTask2, pTimer2);


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

Scheduler::~Scheduler() {
    delete pTask1;
    delete pTask2;
    delete pTimer1;
    delete pTimer2;
}
