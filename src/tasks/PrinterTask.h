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


class PrinterTaskWindow;  // Forward declaration
class PrinterTaskStatus;  // Forward declaration


class PrinterTask : public ITask
{
public:
    PrinterTask();
    ~PrinterTask();

    void run() override;

private:
    std::shared_ptr<PrinterTaskStatus> mpStatus;
    std::unique_ptr<PrinterTaskWindow> mpWindow;
};


class PrinterTaskStatus: public QObject
{
    Q_OBJECT
public:
    void setMsgDefined(const bool val) { bMsgIsDefined = val; };
    void setMsg(const QString &msg) { mMsg = msg; };
    QString getMsg();
    bool isMsgDefined();

private:
    QString mMsg;
    bool bMsgIsDefined = false;
};


class PrinterTaskWindow : public QWidget {
public:
    PrinterTaskWindow(std::shared_ptr<PrinterTaskStatus> pStatus);
    ~PrinterTaskWindow();

    void setupUi();

private:
    void inputReceived();

    std::shared_ptr<PrinterTaskStatus> mpStatus;

    std::unique_ptr<QVBoxLayout> mpLayout;
    std::unique_ptr<QLabel> mpLabel;
    std::unique_ptr<QLineEdit> mpLineEdit;
};


