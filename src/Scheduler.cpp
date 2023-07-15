#include "Scheduler.h"


Scheduler::Scheduler()
{
    pTask1 = new Task();
    pTimer1 = new QTimer();

    pTask2 = new Task();
    pTimer2 = new QTimer();

    mTimersMap.insert(pTask1, pTimer1);
    mTimersMap.insert(pTask2, pTimer2);


    for ( auto iter : mTimersMap.toStdMap() )
    {
        Task *pTask = iter.first;
        QTimer *pTimer = iter.second;

        // Every time the timer emits the timout signal, the task is executed.
        // Qt::QueuedConnection option specifies that tasks shall be executed sequentially.
        // Note that the tasks will run in the main thread.
        QObject::connect(pTimer, &QTimer::timeout, pTask, &Task::run, Qt::QueuedConnection);
    }

}

Scheduler::~Scheduler() {
    delete pTask1;
    delete pTask2;
    delete pTimer1;
    delete pTimer2;
}
