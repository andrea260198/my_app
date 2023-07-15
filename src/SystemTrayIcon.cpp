#include "SystemTrayIcon.h"


SystemTrayIcon::SystemTrayIcon() : QSystemTrayIcon(QIcon(":/images/my_icon.png"))
{
    setupUi();
}


void SystemTrayIcon::setupUi()
{
    this->setToolTip("This is my system tray icon!");
    this->setVisible(true);
}
