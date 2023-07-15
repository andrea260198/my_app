// SystemTrayIcon class manages the tray icon of the application

#pragma once

#include <QSystemTrayIcon>
#include <QObject>
#include <QIcon>


class SystemTrayIcon : public QSystemTrayIcon
{
public:
    SystemTrayIcon();
    ~SystemTrayIcon() {};

    void setupUi();


private:

};
