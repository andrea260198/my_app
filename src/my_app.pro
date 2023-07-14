TEMPLATE = app

QT_VERSION = 6.2.4

TARGET = my_app

QT += core widgets

DESTDIR = ../bin

SOURCES = \
        MyScheduler.cpp \
        main.cpp \
        MySystemTrayIcon.cpp

HEADERS = \
        MyScheduler.h \
        MySystemTrayIcon.h

RESOURCES += my_app.qrc
