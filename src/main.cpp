#include <QApplication>
#include "SystemTrayIcon.h"
#include "Scheduler.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    SystemTrayIcon SystemTrayIcon;

    Scheduler scheduler;

    return app.exec();
}
