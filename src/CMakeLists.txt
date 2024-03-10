cmake_minimum_required(VERSION 3.1.0)

project(task_scheduler_proj VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

include_directories(tasks)

qt_add_executable(task_scheduler_app
    my_app.qrc
    main.cpp
    Scheduler.cpp
    SystemTrayIcon.cpp
    SettingsFactory.cpp
    tasks/AbstractTask.h
    tasks/FinderTask.cpp
    tasks/PrinterTask.cpp
    tasks/PrinterTaskStatus.cpp
    tasks/PrinterTaskWindow.cpp
)

target_link_libraries(task_scheduler_app PRIVATE Qt6::Widgets)
