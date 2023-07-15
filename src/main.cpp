#include <QApplication>
#include <iostream>
#include "SystemTrayIcon.h"
#include "Scheduler.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    new SystemTrayIcon();

    new Scheduler();

    return app.exec();
}
