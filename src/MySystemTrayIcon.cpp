#include "MySystemTrayIcon.h"


MySystemTrayIcon::MySystemTrayIcon() : QSystemTrayIcon(QIcon(":/images/my_icon.png"))
{
    setupUi();
}


void MySystemTrayIcon::setupUi()
{
    this->setToolTip("Hello world!!!");
    this->setVisible(true);
}
