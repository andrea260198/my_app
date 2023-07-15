TEMPLATE = app

QT_VERSION = 6.2.4

TARGET = my_app

QT += core widgets

DESTDIR = ../bin

SOURCES = \
        Scheduler.cpp \
        SystemTrayIcon.cpp \
        Task.cpp \
        main.cpp

HEADERS = \
        Scheduler.h \
        SystemTrayIcon.h \
        Task.h

RESOURCES += my_app.qrc
