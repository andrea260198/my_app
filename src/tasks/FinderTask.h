// FinderTask is a class representing the task of verifying a specific file is in a certain directory.

#pragma once

#include <QFileInfo>
#include <QDebug>
#include "AbstractTask.h"


class FinderTask : public AbstractTask
{
public:
    FinderTask();
    ~FinderTask();

    void run() override;

private:
    QString file_path = "C:/Users/Andrea/Desktop/my_app/example.txt";
};

