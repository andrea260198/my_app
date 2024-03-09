#include "FinderTask.h"


FinderTask::FinderTask()
    : AbstractTask("FinderTask", 10)
{

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
