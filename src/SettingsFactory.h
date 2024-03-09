#pragma once

#include <QSettings>


class SettingsFactory
{
public:
    SettingsFactory() {};
    QSettings create();

private:

};

