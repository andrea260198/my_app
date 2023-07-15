TEMPLATE = app

QT_VERSION = 6.2.4

TARGET = my_app

QT += core widgets

DESTDIR = ../bin

SOURCES = \
        FinderTask.cpp \
        PrinterTask.cpp \
        Scheduler.cpp \
        SystemTrayIcon.cpp \
        main.cpp

HEADERS = \
        FinderTask.h \
        ITask.h \
        PrinterTask.h \
        Scheduler.h \
        SystemTrayIcon.h

RESOURCES += my_app.qrc
