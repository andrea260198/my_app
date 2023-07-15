# My_App
Please, find the app my_app.exe in the bin folder.

## Exercise specifications
Lo scopo di questa applicazione sarà quello di fornire la possibilità di eseguire in modo periodico 
(ogni 10 secondi, ogni 2 ore, il lunedì martedì e mercoledì alle 12:00, ...) una serie di "task" 
indipendenti tra di loro. La periodicità sarà configurabile per il singolo task così da permettere, 
ad esempio, che il task "T1" venga eseguito una volta ogni ora mentre il task "T2" venga eseguito una 
volta ogni 10 secondi. Tramite la QSystemTrayIcon l'utente avrà la possibilità di interagire con 
l'applicazione accedendo a tutte le configurazioni e i parametri richiesti dai vari tasks.

Il compito principale del candidato sarà quindi quello di progettare e implementare uno schedulatore 
generico di tasks, ponendo molta attenzione alla modularità. Si richiede infatti che lo schedulatore 
consenta facilmente di:

- ampliare il set di task a disposizione
- complicare a piacere le periodicità supportate

Ai fini del test è sufficiente che l'applicazione supporti 2 task indipendenti. Il primo task dovrà 
consentire la scelta di un testo, tramite GUI, che verrà stampato in debug ogni 10 secondi. Il secondo 
dovrà controllare, ogni 30 secondi, se uno specifico file ("C:/ESEMPIO.txt") esiste. Nel caso non esista, 
stampare in debug un messaggio di notifica. Per semplicità non si richiede che le periodicità dei task 
siano configurabili tramite GUI (basta siano modulari e configurabili lato programmazione).

Si richiede inoltre che i vari tasks vengano eseguiti in modo serializzato e non parallelo. Si ammette, 
ma non richiede, l'esistenza di un thread dedicato all'esecuzione dei tasks (separato dal principale per 
la GUI), ma non sarà possibile avere un thread specifico per ciascun task. Se la richiesta di esecuzione 
di un task arriva mentre si sta già eseguendo un secondo task, l'esecuzione dovrà essere posticipata 
alla fine del task in corso.

## Classes
The application is made of the following classes:
* SystemTrayIcon
* Scheduler
* ITask
* PrinterTask
* PrinterTaskWindow
* FinderTask

## Credits
The image my_icon.png has been downloaded from "flaticon.com".



