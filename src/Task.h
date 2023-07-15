#pragma once

#include <QTimer>


class Task
{
public:
    Task();
    ~Task();

    void run();
    bool isToRun();

private:
    long frequency;
};

