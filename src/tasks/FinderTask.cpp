#include "FinderTask.h"


FinderTask::FinderTask()
{
    mName = "FinderTask";
    mPeriod = 30;  // [s]
}


FinderTask::~FinderTask()
{

}


void FinderTask::run()
{
    QFileInfo file(file_path);

    if ( !file.exists() )
    {
        qDebug() << "File does not exists";
    }
    else
    {
        qDebug() << "File exists";
    }

}
