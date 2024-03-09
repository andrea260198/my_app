#include <QDir>
#include "SettingsManager.h"


SettingsManager::SettingsManager()
    : task_timer_settings_filename("task_timer_settings.ini")
    , QSettings(QDir::homePath() + "/" + task_timer_settings_filename, QSettings::IniFormat)
{

}
