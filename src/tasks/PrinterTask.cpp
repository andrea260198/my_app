#include "PrinterTask.h"


// PrinterTask method definitions
PrinterTask::PrinterTask()
{
    mName = "PrinterTask";
    mPeriod = 10;
    mpWindow = new PrinterTaskWindow(this);
}


PrinterTask::~PrinterTask()
{
    delete mpWindow;
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
    delete mpLayout;
    delete mpLabel;
    delete mpLineEdit;
}


void PrinterTaskWindow::setupUi()
{
    this->resize(200, 100);
    mpLayout = new QVBoxLayout();
    this->setLayout(mpLayout);

    mpLabel = new QLabel("Please, write a message below and press Enter");

    mpLineEdit = new QLineEdit();
    mpLineEdit->resize(100, 100);

    mpLayout->addWidget(mpLabel);
    mpLayout->addWidget(mpLineEdit);

    connect(mpLineEdit,
            &QLineEdit::editingFinished,
            this,
            [this](){ mpTask->setMsgDefined(true); mpTask->setMsg(mpLineEdit->text()); this->setVisible(false); });
}
