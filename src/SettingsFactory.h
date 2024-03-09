#pragma once

#include <QSettings>


class SettingsFactory
{
public:
    SettingsFactory() = delete;
    QSettings create();

private:

};

