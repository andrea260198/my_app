#include <QApplication>
#include <iostream>
#include "MySystemTrayIcon.h""


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    new MySystemTrayIcon();

    new MyScheduler();

    return app.exec();
}
