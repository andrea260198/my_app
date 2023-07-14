#pragma once

#include <QSystemTrayIcon>
#include <QObject>
#include <QIcon>


class MySystemTrayIcon : public QSystemTrayIcon
{
public:
    MySystemTrayIcon();
    ~MySystemTrayIcon() {};

    void setupUi();


private:

};
