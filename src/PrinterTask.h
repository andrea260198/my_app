#pragma once

#include <QDebug>
#include <QString>
#include <QWidget>
#include <QLineEdit>
#include <QApplication>
#include <QDialog>
#include <QThread>
#include <QVBoxLayout>
#include "ITask.h"


class PrinterTaskWindow;  // Forward declaration


class PrinterTask : public ITask
{
public:
    PrinterTask();
    ~PrinterTask();

    void run() override;
    void setMsgDefined(bool val) { msgIsDefined = val; };
    void setMsg(QString msg) { mMsg = msg; };

private:
    QString mMsg = "Hello world!!!\n";
    bool msgIsDefined = false;

    PrinterTaskWindow *mpWindow;
};


class PrinterTaskWindow : public QWidget {
public:
    PrinterTaskWindow(PrinterTask *pPrTask);
    ~PrinterTaskWindow();

    void setupUi();

private:
    PrinterTask *pt;

    QVBoxLayout *mpVBoxLayout;
    QLineEdit *mpLineEdit;
};

