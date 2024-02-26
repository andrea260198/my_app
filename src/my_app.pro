TEMPLATE = app

QT_VERSION = 6.2.4

TARGET = my_app

QT += core widgets

DESTDIR = ../bin

INCLUDEPATH = tasks

SOURCES = \
        tasks/FinderTask.cpp \
        tasks/PrinterTask.cpp \
        tasks/PrinterTaskStatus.cpp \
        tasks/PrinterTaskWindow.cpp \
        Scheduler.cpp \
        SystemTrayIcon.cpp \
        main.cpp

HEADERS = \
        tasks/FinderTask.h \
        tasks/PrinterTask.h \
        tasks/PrinterTaskStatus.h \
        tasks/PrinterTaskWindow.h \
        ITask.h \
        Scheduler.h \
        SystemTrayIcon.h

RESOURCES += my_app.qrc
