#include "PrinterTask.h"


PrinterTask::PrinterTask()
{
    mpWindow = new QWidget;
    mpWindow->resize(200, 200);
    mpVBoxLayout = new QVBoxLayout();
    mpWindow->setLayout(mpVBoxLayout);
    mpLineEdit = new QLineEdit();
    mpLineEdit->resize(100, 100);
    mpVBoxLayout->addWidget(mpLineEdit);

    connect(mpLineEdit, &QLineEdit::editingFinished, this, [this](){ msgIsDefined = true; mMsg = mpLineEdit->text();});
}


PrinterTask::~PrinterTask()
{
    delete mpWindow;
}


void PrinterTask::run()
{
    if ( msgIsDefined )
    {
        mpWindow->setVisible(false);
        qDebug() << mMsg;

    } else
    {
        mpWindow->setVisible(true);
    }
}
