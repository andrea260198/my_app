#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <memory>
#include "PrinterTaskStatus.h"


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
