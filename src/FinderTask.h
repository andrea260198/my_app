#pragma once

#include "ITask.h"


class FinderTask : public ITask
{
public:
    FinderTask();
    ~FinderTask();

    void run() override;
};

