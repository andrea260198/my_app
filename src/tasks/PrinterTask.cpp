#include "PrinterTask.h"


PrinterTask::PrinterTask()
{
    mName = "PrinterTask";
    mPeriod = 10;
    mpStatus = std::make_shared<PrinterTaskStatus>();
    mpWindow = std::make_unique<PrinterTaskWindow>(mpStatus);
}


PrinterTask::~PrinterTask()
{

}


void PrinterTask::run()
{
    if ( mpStatus->isMsgDefined() )
    {
        qDebug().noquote() << mpStatus->getMsg();

    } else
    {
        mpWindow->setVisible(true);
    }
}
