#include "PrinterTask.h"


// PrinterTask
PrinterTask::PrinterTask()
{
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
        qDebug() << mMsg;

    } else
    {
        mpWindow->setVisible(true);
    }
}


// PrinterTaskWindow
PrinterTaskWindow::PrinterTaskWindow(PrinterTask *pPrTask)
    : pt(pPrTask)
{
    setupUi();
}


PrinterTaskWindow::~PrinterTaskWindow()
{
    delete mpVBoxLayout;
    delete mpLineEdit;
}


void PrinterTaskWindow::setupUi() {
    this->resize(200, 400);
    mpVBoxLayout = new QVBoxLayout();
    this->setLayout(mpVBoxLayout);
    mpLineEdit = new QLineEdit();
    mpLineEdit->resize(100, 100);
    mpLineEdit->move(10, 10);
    mpVBoxLayout->addWidget(mpLineEdit);

    connect(mpLineEdit,
            &QLineEdit::editingFinished,
            this,
            [this](){ pt->setMsgDefined(true); pt->setMsg(mpLineEdit->text()); this->setVisible(false); });
}
