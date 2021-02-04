# Project Name

Calculator_RPN

## Table of contents
* [General info](#general-info)
* [Technologies](#technologies)
* [How to use](#How to use)
* [Features](#features)
* [Status](#status)
* [Test](#test)
* [Contact](#contact)

## General info
"Calculator_RPN" is calculator, which operating on reverse polish notation(RPN). I created this calclator on linked lists. This is similar to how the stack works. Similar calculator is unix calculator"dc" , which you can find in BASH/SHELL(for example. terminal linux). To launch this calculator you must writing "dc" in terminal.

## Technologies
Language C Standard ANSI C99

## How to use
In terminal[(BASH/SHELL)launched in folder where find your Calculator_RPN] first you must compile program, writing: make

Next you must launch program, writing: ./Kalkulator_RPN.out 

## Features
Calculator have features:
"/" - division
"*" - multiplication
"+" - addition
"-" - subtraction
P - delete last introduced element
c - clear calculator memory
r - replace two element's "on the top"
d - copy element "on the top" 
p - print element "on the top"
f - full print
q - close program

## Status
Only Polish version(I will upgrade this, in the closest future).
!!! Program does only on integer (I will upgrade this, in the closest future). !!!

## Test

Program tests only in polish version(I will upgrade this, in the closest future)

/*TESTY PROGRAMU*/
/*Wywołanie programu: ./Kalkulator_RPN.out*/
/*TESTY DZIALANIA FUNKCJI PROGRAMU*/
/*Funkcji f(full print) nie testuje oddziellnie poniewaz powtarza się ona w każdym teście*/

/*1 TEST
Testujemy operacje dodawania
Dane wejściowe:
1 2 3 +
Dane wyjściowe:
wyświetlam za pomoca f, wszystkie elementy:
5
1

Program działa prawidłowo*/

/*2 TEST
Testujemy operacje odejmowania
Dane wejściowe:
1 -2 3 -
Dane wyjściowe:
wyświetlam za pomoca f, wszystkie elementy:
-5
1

Program działa prawidłowo i rozroznia liczbe ujemna od operacji odejmowania*/

/*3 TEST
Testujemy operacje mnożenia
Dane wejściowe:
1 -2 -3 *
Dane wyjściowe:
wyświetlam za pomoca f, wszystkie elementy:
6 
1

Program działa prawidłowo*/

/*4 TEST
Testujemy operacje dzielenia
Dane wejściowe:
1 6 2 /
Dane wyjściowe:
wyświetlam za pomoca f, wszystkie elementy:
3
1

Program działa prawidłowo

/*5 TEST
Testuje działanie funkcji f(full print), gdy stos jest pusty
Dane wejściowe:
f
Dane wyjściowe:
Stos jest pusty

Program działa prawidłowo*/

/*6 TEST 
Testuje działanie funkcji P(usuniecie ostatniej wprowadzonej liczby)
Dane wejściowe:
1 2 3 
P
Dane wyjściowe:
wyświetlam za pomoca f, wszystkie elementy:
2
1

Program działa prawidłowo*/

/*7 TEST
Testuje działanie funkcji c("czyszczenie" całego stosu)
Dane wejściowe:
1 2 3 4 5 6 
c
Dane wyjściowe:
wyświetlam za pomoca f, wszystkie elementy:
Stos jest pusty

Program działa prawidłowo*/

/*8 TEST
Testuje działanie funkcji c, gdy nie ma elementow na stosie
Dane wejściowe:
c
Dane wyjściowe:
Brakuje elementów do wykonania operacji

Program działa prawidłowo*/

/*9 TEST
Testuje działanie funkcji r(zamiana dwóch argumentow na szczycie stosu
Dane wejsciowe:
1 2 3 
r
Dane wyjściowe:
2
3
1

Program działa prawidłowo*/

/*10 TEST
Testuje działanie funkcji d(duplikacja elementow znajdujacego sie na szczycie
Dane wejściowe:
1 2 3
d
Dane wyjściowe:
3
3
2
1

Program działa prawidłowo*/

/*11 TEST
Testuje działanie funkcji p( wyswietlenie elementu znjadujacego sie na szczycie)
Dane wejściowe:
3 3 2 1 
p
Dane wyjsciowe:
3

Program działa prawidłowo*/

/*12 TEST 
Testuje działanie funkcji q(zakonczecnie pracy kalkulatora)
Dane wejściowe:
q
Dane wyjściowe:
Program zakończył prace 

Program działa prawidłowo*/

/*13 TEST 
Testuje wprowadzenie danej typu float
Dane wejściowe:
4.8
Dane wyjściowe:
Kalkulator nie przyjumuje takiego znaku

Program działa prawidłowo, ma on operować tylko na liczbach całkowitych*/

/*14 TEST
Testuje wprowadzenie nieprawidłowoego znaku 
Dane wejściowe:
[ a b ]
Dane wyjściowe:
Kalkulator nie przyjmuje takiego znaku
Kalkulator nie przyjmuje takiego znaku
Kalkulator nie przyjmuje takiego znaku
Kalkulator nie przyjmuje takiego znaku

Program działa prawidłowo*/

/*15 TEST
Testuje wporwadzenie duzej liczby
Dane wejsciowe:
2000000000000
Dane wyjściowe:
wyświetlam za pomoca f, wszystkie elementy:
W pamięci kalkulatora, są następujące elementy:
-1454759936

Program działa prawidłowo, operuje on tylko liczbach całkowitych, aby wprowadzic mozliwosc wporwadzania tak duzych liczb nalezaloby zastosowac inny typ zmiennej np long long int*/

/*Wnioski końcowe
  Program działa prawidłowo, jednak pokusiłbym się o wprowadznie możliwości operacji na liczbach typu float(zmiennoprzecinkowych)*/

## Contact
Created by Marek Szulak