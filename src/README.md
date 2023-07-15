# Description
The application is made of the following classes:
* SystemTrayIcon
	SystemTrayIcon class manages the tray icon of the application
	
* Scheduler
	The Scheduler class implements a simple scheduler using the signal emitted by QTimer object 
	on a regular basis.
	Note that the Scheduler is part of the main thread. The entire app runs on a single thread.
	
* ITask
	ITask is an interface for a task.
	
* PrinterTask
	PrinterTask is a class representing the task of printing a msg with a certain frequency.

* PrinterTaskWindow
	PrinterTaskWindow is used by the PrinterTask class to show a window where to input the 
	message that has to be displaied.
	
* FinderTask
	FinderTask is a class representing the task of verifying a specific file is in a certain directory.