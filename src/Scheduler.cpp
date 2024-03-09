#include <QSettings>
#include <QDir>
#include "Scheduler.h"
#include "PrinterTask.h"
#include "FinderTask.h"
#include "SettingsFactory.h"


Scheduler::Scheduler()
{
    setTaskList();
    setTaskFrequency();
    setTaskTimerMap();
    connectTaskAndTimer();
}


void Scheduler::setTaskList()
{
    pTask1 = std::make_shared<PrinterTask>();
    pTask2 = std::make_shared<FinderTask>();

    task_list_t tasks = {pTask1, pTask2};
    mTaskList.append(tasks);
}


void Scheduler::setTaskFrequency()
{
    SettingsFactory settingsFactory;
    QSettings settings = settingsFactory.create();

    for (auto task : mTaskList)
    {
        long period = settings.value(task->getName() + "/period", "r").toInt();
        task->setPeriod(period);
    }
}


void Scheduler::setTaskTimerMap()
{
    for (auto pTask : mTaskList)
    {
        auto pTimer = std::make_shared<QTimer>();
        pTimer->start( 1'000 * pTask->getPeriod() );  // Emit QTimer::timeout signal every 30 sec.  TODO: change time to 30 sec

        mTaskTimerMap.insert(pTask, pTimer);
    }
}


void Scheduler::connectTaskAndTimer()
{
    for ( auto [task, timer] : mTaskTimerMap.asKeyValueRange() )
    {
        // Every time the timer emits the timout signal, the task is executed.
        // "Qt::QueuedConnection" option specifies that tasks shall be executed sequentially.
        // Note that the tasks will run in the main thread.
        QObject::connect(timer.get(), &QTimer::timeout, task.get(), &AbstractTask::run, Qt::QueuedConnection);
    }
}
