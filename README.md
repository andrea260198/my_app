# Application

Please, find the app my_app.exe in the bin folder.

## Exercise specifications

The goal of this app is to make possible to periodically execute (every 10 seconds, every 2 hours, Monday Tuesday and Wednesday at 12pm, ...)
a series of tasks independent from each other. Periodicity shall be configurable for every single task so that,
for example, task "T1" can be executed once every hour, while task "T2" is executed once every 10 seconds.
By using a QSystemTrayIcon the user shall be able to interact with the app accessing all the configurations and 
the paramenters required by the various tasks.

The main task of the candidate is to design and implement a generic scheduler of tasks, focusing on modularity.
It is required for the scheduler to be able to:

- increase the set of possible tasks
- complicate the periodicity of tasks

In order to succede in the test, it is sufficient for the app to support 2 independent tasks. The first task shall receive a text as input,
with a GUI, which will be printed in debug every 10 seconds. The second task shall check, every 30 seconds, if a specific file ("C:/EXAMPLE.txt") exists.
In case the file does not exist, print in debug a message to notify. For simplicity, it is not required for the tasks periodicity to be configurable with a GUI
(it's enough that it is modular and configurable through coding).

It is expected, in addition, that the various tasks are executed serially and not in parallel. It is allowed, but not required,
to have a specific thread  for tasks execution (separated from the main one for the GUI), but it is not possible to have a specific thread for every task.
If the request for a task execution arrives when another task is executing, the execution shall be postponed to the end of the current running task.

## How to build

On Windows, open the .pro file with QtCreator to open the project.
Then build using QtCreator.

## Credits

The image my_icon.png has been downloaded from "flaticon.com".



