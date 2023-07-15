#pragma once

#include <QFileInfo>
#include <QDebug>
#include "ITask.h"


class FinderTask : public ITask
{
public:
    FinderTask();
    ~FinderTask();

    void run() override;
};

