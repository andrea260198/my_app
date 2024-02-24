#include "PrinterTask.h"


// PrinterTask method definitions
PrinterTask::PrinterTask()
{
    mName = "PrinterTask";
    mPeriod = 10;
    mpStatus = std::make_shared<PrinterTaskStatus>();
    mpWindow = std::make_shared<PrinterTaskWindow>(mpStatus);
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


// PrinterTaskWindow method definitions
PrinterTaskWindow::PrinterTaskWindow(std::shared_ptr<PrinterTaskStatus> pStatus)
    : mpStatus(pStatus)
{
    setupUi();
}


PrinterTaskWindow::~PrinterTaskWindow()
{

}


void PrinterTaskWindow::setupUi()
{
    this->resize(200, 100);
    mpLayout = std::make_shared<QVBoxLayout>();
    this->setLayout(mpLayout.get());

    mpLabel = std::make_shared<QLabel>("Please, write a message below and press Enter");

    mpLineEdit = std::make_shared<QLineEdit>();
    mpLineEdit->resize(100, 100);

    mpLayout->addWidget(mpLabel.get());
    mpLayout->addWidget(mpLineEdit.get());

    connect(mpLineEdit.get(),
            &QLineEdit::editingFinished,
            this,
            &PrinterTaskWindow::inputReceived);
}


void PrinterTaskWindow::inputReceived()
{
    mpStatus->setMsgDefined(true);
    mpStatus->setMsg(mpLineEdit->text());
    this->setVisible(false);
}


// PrinterTaskStatus method definitions
QString PrinterTaskStatus::getMsg()
{
    return mMsg;
}


bool PrinterTaskStatus::isMsgDefined()
{
    return bMsgIsDefined;
}
