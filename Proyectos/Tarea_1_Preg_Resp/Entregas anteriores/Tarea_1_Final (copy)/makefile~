Tarea_1: Main.o Menu.o Lista.o
	gcc Main.o Menu.o Lista.c -o Tarea_1
Main.o: Main.c Pregunta.h Menu.h Lista.h
	gcc -c  Main.c
Lista.o: Lista.c Pregunta.h Lista.h 
	gcc -c Lista.c
Menu.o: Menu.c Menu.h
	gcc -c Menu.c
