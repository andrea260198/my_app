#pragma once

#include <QDebug>
#include <QString>
#include <QWidget>
#include <QLineEdit>
#include <QApplication>
#include <QDialog>
#include <QThread>
#include <QVBoxLayout>>
#include "ITask.h"


class PrinterTask : public ITask
{
public:
    PrinterTask();
    ~PrinterTask();

    void run() override;

private:
    QString mMsg = "Hello world!!!\n";
    bool msgIsDefined = false;

    QWidget *mpWindow;
    QVBoxLayout *mpVBoxLayout;
    QLineEdit *mpLineEdit;
};

