#include <QDir>
#include <QDebug>
#include "SettingsFactory.h"


QSettings SettingsFactory::create()
{
    QString task_timer_settings_filename = "task_timer_settings.ini";

    QString file_path = QDir::homePath() + "/" + task_timer_settings_filename;

    QFileInfo file(file_path);

    if ( file.exists() )
    {
        qDebug() << "Settings file found";
        return QSettings(file_path, QSettings::IniFormat);
    }
    else
    {
        qDebug() << "Settings file not found";
        return QSettings();
    }
}
