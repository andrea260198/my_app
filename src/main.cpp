#include <QApplication>
#include <QWidget>
#include <iostream>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    auto pWindow = new QWidget();
    pWindow->setVisible(true);

    return app.exec();
}
