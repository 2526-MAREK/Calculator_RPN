all: main_funkcje.o main_kalkulator.o
	gcc -std=c99 -pedantic -Wall main_funkcje.o main_kalkulator.o -o Kalkulator_RPN.out
	-rm -f *.o 
main_funkcje.o: main_funkcje.o main_kalkulator.h
	gcc main_funkcje.c -c -o main_funkcje.o
main_kalkulator.o: main_kalkulator.o main_kalkulator.h
	gcc main_kalkulator.c -c -o main_kalkulator.o
