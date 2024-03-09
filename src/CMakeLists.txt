include_directories(tasks)

qt_add_executable(task_scheduler_app
    my_app.qrc
    main.cpp
    Scheduler.cpp
    SystemTrayIcon.cpp
    SettingsManager.cpp
    tasks/AbstractTask.h
    tasks/FinderTask.cpp
    tasks/PrinterTask.cpp
    tasks/PrinterTaskStatus.cpp
    tasks/PrinterTaskWindow.cpp
)

target_link_libraries(task_scheduler_app PRIVATE Qt6::Widgets)
