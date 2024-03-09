#include <QDir>
#include "SettingsManager.h"


QSettings SettingsFactory::create()
{
    QString task_timer_settings_filename = "task_timer_settings.ini";
    return QSettings(QDir::homePath() + "/" + task_timer_settings_filename, QSettings::IniFormat);
}
