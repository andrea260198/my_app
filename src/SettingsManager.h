#pragma once

#include <QSettings>


class SettingsManager: public QSettings
{
public:
    SettingsManager();

private:
    QString task_timer_settings_filename;
};

