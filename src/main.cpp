#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QSystemTrayIcon>
#include <iostream>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QSystemTrayIcon *pTrayIcon = new QSystemTrayIcon(QIcon(":/images/my_icon.png"));
    pTrayIcon->setToolTip("Hello world!!!");
    pTrayIcon->setVisible(true);

    return app.exec();
}
