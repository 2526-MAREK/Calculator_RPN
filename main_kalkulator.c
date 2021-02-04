/*KALKULATOR_RPN*/
/*Marek Szulak*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "main_kalkulator.h"

int main(void){
  T_STOS glowny; // główny wskaźnik, wskazujący na początek listy(stosu)

  OP_KALK op_kalk;

  char ch;
  char ch_pom;
  int dana;
  char pom2;
  int wczytano;
  int dodaj_minus;

  init(&glowny); //Inicjacja pustej listy

  while( (ch = getchar()) != 'q' ){ //Dopoki znak jest rozny od "q"
    
    wczytano=1;
    dodaj_minus = 0;
    op_kalk.rozmiar = 0;
    
    switch(ch)
      {
      case('+'):{//mamy wykonać dodawanie
	if(!empty(glowny)){//Najpierw sprawdzimy czy lista jest pusta 
	  if(!empty(glowny->nast)){//Teraz sprawdzamy czy sa co najmniej dwa elementy na liscie
	    op_kalk.operacja = DODAWANIE;
	    operacje_arytmetyczne(&glowny, &op_kalk);
	  }
	  else
	    BRAK_ELEMENTOW;
	}
	else
	  BRAK_ELEMENTOW;
     	break;
      }
      case('-'):{//mamy wykonać odejmowanie
	if((ch_pom=getchar())==(' ')){//jeśli znak jest znakiem pustym(spacja,tablacja)
	  dodaj_minus = 1;//Dodaje minus ponieważ potrafimy zwrocic tylko jeden znak z bufora( ta operacja jest powtwarzana jeszcze 1 razy w programie
	  wczytaj_liczbe(&op_kalk.dana, &glowny, dodaj_minus);
	  wczytano=0;//zmienna pomocnicza aby dana nie była wczytywana dwa razy 
	}
	ungetc(ch_pom, stdin);
	if(wczytano){
	pom2=getchar();	 
	if(isdigit(pom2)){//jesli znak jest liczba 
	  ungetc(pom2, stdin);
	  dodaj_minus = 1;
	  wczytaj_liczbe(&op_kalk.dana, &glowny, dodaj_minus);
	}
	else{// jesli znak ( w tym przypadku odejmowanie)
	  ungetc(pom2, stdin);
	  if(!empty(glowny)){//Najpierw sprawdzimy czy lista jest pusta 
	    if(!empty(glowny->nast)){//Teraz sprawdzamy czy sa co najmniej dwa elementy na liscie
	      op_kalk.operacja = ODEJMOWANIE;
	      operacje_arytmetyczne(&glowny, &op_kalk);
	    }
	    else
	      BRAK_ELEMENTOW;
	  }
	  else
	    BRAK_ELEMENTOW;
	}
	}
	break;
      }
      case('*'):{//mamy wykonać mnożenie
	if(!empty(glowny)){//Najpierw sprawdzimy czy lista jest pusta 
	  if(!empty(glowny->nast)){//Teraz sprawdzamy czy sa co najmniej dwa elementy na liscie
	    op_kalk.operacja = MNOZENIE;
	    operacje_arytmetyczne(&glowny, &op_kalk);
	  }
	  else
	    BRAK_ELEMENTOW;
	}
	else
	  BRAK_ELEMENTOW;
	break;
      }
      case('/'):{//mamy wykonać dzielenie
	if(!empty(glowny)){//Najpierw sprawdzimy czy lista jest pusta 
	  if(!empty(glowny->nast)){//Teraz sprawdzamy czy sa co najmniej dwa elementy na liscie
	    op_kalk.operacja = DZIELENIE;
	    operacje_arytmetyczne(&glowny, &op_kalk);
	  }
	  else
	    BRAK_ELEMENTOW;
	}
	else
	  BRAK_ELEMENTOW;
	break;
      }
      case('P'):{//mamy usunać ostatnio wprowadzoną liczbę
	if(!empty(glowny))
	pop(&glowny, &op_kalk.dana);
	else
	  BRAK_ELEMENTOW;
	break;
      }
      case('c'):{//całkowite "czyszczenie" stosu
	if(!empty(glowny))
	clear_stos(&glowny);
	else
	  BRAK_ELEMENTOW;
	break;
      }
      case('r'):{//zamiana dwóch elementow na szczycie stosu
	if(!empty(glowny)){//Najpierw sprawdzimy czy lista jest pusta 
	  if(!empty(glowny->nast)){//Teraz sprawdzamy czy sa co najmniej dwa elementy na liscie
	    reverse(&glowny, &op_kalk);
	  }
	  else
	    BRAK_ELEMENTOW;
	}
	else
	  BRAK_ELEMENTOW;
	break;
      }
      case('d'):{//duplikacja elementu znajdującego się na szczycie stosu
	if(!empty(glowny)){//Najpierw sprawdzimy czy lista jest pusta
	  duplicate(&glowny, &op_kalk);
	}
	else
	  BRAK_ELEMENTOW;
	break;
      }
      case('p'):{//wydrukowanie na wyjściu elementu, który jest na szczycie stosu
	if(!empty(glowny)){
	printf("%d\n", glowny->elem_stosu);
	}
	else
	  BRAK_ELEMENTOW;
	break;
      }
      case('f'):{//wyswietlenie wszystkich elementow znajdujacych sie na stosie
	full_print(glowny);
	break;
      }
      case('\n'):{//pomijamy znak nowej lini
	break;
      }
      case(' '):{//pomijamy spacje/znak pusty
	break;
      }
      default:{//jeśli liczba
	ungetc(ch, stdin);
	dodaj_minus = 0;
        wczytaj_liczbe(&op_kalk.dana, &glowny, dodaj_minus);
	break;
      }
      }
  }

  if(!empty)
  clear_stos(&glowny);

  return 0;	
}

void wczytaj_liczbe(int *dana, T_STOS *stos, int dodaj_minus){
  if((scanf("%d", &*dana))==1){//jesli odczytano
    if(dodaj_minus)
      *dana=-*dana;
    push(stos, dana);
  }
  else
    {
      printf("Kalkulator nie przyjmuje takiego znaku\n");
      czyszczenie_bufora();
    }
}

void czyszczenie_bufora(void){
  int pom; //zmienna pomocniczna
  
  while((pom = getchar()) != '\n' && pom != EOF) // pętla wyciągająca znaki z bufora
  break;
}


