#include "Task.h"


Task::Task()
{
    QTimer *mTimer = new QTimer();

    //connect(mTimer, &QTimer::timeout, scheduler, []()addTask());
}


Task::~Task() {

}

void Task::run() {


}
