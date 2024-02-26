#include "PrinterTaskWindow.h"


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
    mpLayout = std::make_unique<QVBoxLayout>();
    this->setLayout(mpLayout.get());

    mpLabel = std::make_unique<QLabel>("Please, write a message below and press Enter");

    mpLineEdit = std::make_unique<QLineEdit>();
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
