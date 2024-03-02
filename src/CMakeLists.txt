include_directories(tasks)

qt_add_executable(task_scheduler_app
    my_app.qrc
    main.cpp
    Scheduler.h
    Scheduler.cpp
    SystemTrayIcon.h
    SystemTrayIcon.cpp
    tasks/ITask.h
    tasks/FinderTask.h
    tasks/FinderTask.cpp
    tasks/PrinterTask.h
    tasks/PrinterTask.cpp
    tasks/PrinterTaskStatus.h
    tasks/PrinterTaskStatus.cpp
    tasks/PrinterTaskWindow.h
    tasks/PrinterTaskWindow.cpp
)

target_link_libraries(task_scheduler_app PRIVATE Qt6::Widgets)
