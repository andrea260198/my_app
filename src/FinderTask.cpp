#include "FinderTask.h"


FinderTask::FinderTask()
{

}


FinderTask::~FinderTask()
{

}


void FinderTask::run()
{
    QFileInfo file("");
    if ( !file.exists("C:/Users/Andrea/Desktop/my_app/README.md") )
    {
        qDebug() << "File does not exists\n";
    } else
    {
        qDebug() << "File exists\n";
    }

}
