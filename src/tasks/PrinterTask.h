// PrinterTask is a class representing the task of printing a msg with a certain frequency.
// PrinterTaskWindow is used by the PrinterTask class to show a window where to input the message that has to be displaied.

#pragma once

#include <QDebug>
#include <QString>
#include <QWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QLabel>
#include <memory>
#include "ITask.h"
#include "PrinterTaskStatus.h"
#include "PrinterTaskWindow.h"


class PrinterTask : public AbstractTask
{
public:
    PrinterTask();
    ~PrinterTask();

    void run() override;

private:
    std::shared_ptr<PrinterTaskStatus> mpStatus;
    std::unique_ptr<PrinterTaskWindow> mpWindow;
};


