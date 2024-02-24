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


// TODO: resolve circular reference between PrinterTask and PrinterTaskWindow


class PrinterTaskWindow;  // Forward declaration


class PrinterTask : public ITask
{
public:
    PrinterTask();
    ~PrinterTask();

    void run() override;
    void setMsgDefined(const bool val) { msgIsDefined = val; };
    void setMsg(const QString &msg) { mMsg = msg; };

private:
    QString mMsg;
    bool msgIsDefined = false;

    std::shared_ptr<PrinterTaskWindow> mpWindow;
};


class PrinterTaskWindow : public QWidget {
public:
    PrinterTaskWindow(PrinterTask *pPrTask);
    ~PrinterTaskWindow();

    void setupUi();

private:
    void inputReceived();

    std::shared_ptr<PrinterTask> mpTask;

    std::shared_ptr<QVBoxLayout> mpLayout;
    std::shared_ptr<QLabel> mpLabel;
    std::shared_ptr<QLineEdit> mpLineEdit;
};

