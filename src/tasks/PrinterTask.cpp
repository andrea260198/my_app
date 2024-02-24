#include "PrinterTask.h"


// PrinterTask method definitions
PrinterTask::PrinterTask()
{
    mName = "PrinterTask";
    mPeriod = 10;
    mpWindow = std::make_shared<PrinterTaskWindow>(this);
}


PrinterTask::~PrinterTask()
{

}


void PrinterTask::run()
{
    if ( msgIsDefined )
    {
        qDebug().noquote() << mMsg;

    } else
    {
        mpWindow->setVisible(true);
    }
}


// PrinterTaskWindow method definitions
PrinterTaskWindow::PrinterTaskWindow(PrinterTask *pTask)
    : mpTask(pTask)
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
    mpTask->setMsgDefined(true);
    mpTask->setMsg(mpLineEdit->text());
    this->setVisible(false);
}

