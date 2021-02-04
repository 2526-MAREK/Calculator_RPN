#include <stdio.h>
#include <stdlib.h>
#include "main_kalkulator.h"

void init(T_STOS *stos){
  *stos = NULL;  //inicjalizacja pustej listy(stosu)  
}

int empty(T_STOS stos){//Funkcja, która srpawdza czy stos jest pusty 
  if(stos==NULL)
    return PUSTY_STOS;
  else
    return W_OK;
}

int push(T_STOS *stos, int *dana){
  T_ELEM *element;
  
  element = (T_ELEM *)malloc(sizeof(T_ELEM)); //alokacja pamieci dla struktury danych
  element->elem_stosu=*dana; // przypisanie do zmiennej w strukturze dana wartosci 
  element->nast=NULL;
 
  if(!empty(*stos)){
    element->nast=*stos;
    *stos = element;
    
    return W_OK;
  }
  else{       // jesli lista/stos jest pusty
  *stos = element;
    return W_OK;
  }
}

int pop(T_STOS *stos, int *dana){
  T_ELEM *usun_elem;
  usun_elem=*stos;
  
  if(empty(*stos)){
    BRAK_ELEMENTOW;
    return PUSTY_STOS;
  }
  else{
    *dana=usun_elem->elem_stosu; // Przypisanie do zmiennej dana w main poprzedniej wartości
    if(usun_elem->nast==NULL){//przypadek jesli mamy tylko jeden element w stosie
      *stos = NULL; // STOS PUSTY
    }
    else{  //więcej niż jeden element
      *stos=usun_elem->nast;
    }
    free(usun_elem);
    usun_elem = NULL;
    return W_OK;
  }
}

void full_print(T_STOS stos){
  T_ELEM *pom;
  
  if(!empty(stos)){
    printf("W pamięci kalkulatora, są następujące elementy:\n");
    pom=stos;
    while(pom != NULL){
      printf("%d\n", pom->elem_stosu);
      pom = pom->nast;
    }
  }
  else
    printf("Stos jest pusty\n");
  pom = NULL;
}

void clear_stos(T_STOS *glowny){
  T_ELEM *pom;
  T_ELEM *biezacy;
  
  /*zwalniamy zajeta pamiec*/
  biezacy=*glowny;
  while(biezacy != NULL){
    pom = biezacy;
    biezacy=pom->nast;
    free(pom);
    pom=NULL;
  }
  biezacy = NULL;
  *glowny = NULL;
}

void operacje_arytmetyczne(T_STOS *stos, OP_KALK *op_kalk){
  T_ELEM *pom = *stos;
  
  pop(&*stos, &op_kalk->dana);
  op_kalk->tab[op_kalk->rozmiar] = op_kalk->dana;
  pop(&*stos, &op_kalk->dana);
  op_kalk->rozmiar++;
  op_kalk->tab[op_kalk->rozmiar] = op_kalk->dana;
  /*wybieramy operacje arytmetyczna*/
  if(op_kalk->operacja==DODAWANIE)
    op_kalk->dana = op_kalk->tab[1]+op_kalk->tab[0];
  if(op_kalk->operacja==ODEJMOWANIE)
    op_kalk->dana = op_kalk->tab[1]-op_kalk->tab[0];
  if(op_kalk->operacja==MNOZENIE)
    op_kalk->dana = op_kalk->tab[1]*op_kalk->tab[0];
  if(op_kalk->operacja==DZIELENIE)
    op_kalk->dana = op_kalk->tab[1]/op_kalk->tab[0];
  push(&*stos, &op_kalk->dana);
  op_kalk->rozmiar = 0; //na wszelki wypadek
}


void reverse(T_STOS *glowny, OP_KALK *op_kalk){

  /*Sciagamy dwa pierwsze elementy z gory listy*/
  pop(&*glowny, &op_kalk->dana);
  op_kalk->tab[op_kalk->rozmiar] = op_kalk->dana;
  pop(&*glowny, &op_kalk->dana);
  op_kalk->rozmiar++;
  op_kalk->tab[op_kalk->rozmiar] = op_kalk->dana;
  op_kalk->rozmiar = 0;
  /*Przypisujemy do listy te elelemnty ale teraz w odwrotnej kolejnsoci*/
  push(&*glowny, &op_kalk->tab[op_kalk->rozmiar]);
  op_kalk->rozmiar++;
  push(&*glowny, &op_kalk->tab[op_kalk->rozmiar]);
  op_kalk->rozmiar = 0;  
}

void duplicate(T_STOS *glowny, OP_KALK *op_kalk){
  pop(&*glowny, &op_kalk->dana);
  op_kalk->tab[op_kalk->rozmiar] = op_kalk->dana;
  push(&*glowny, &op_kalk->tab[op_kalk->rozmiar]);
  push(&*glowny, &op_kalk->tab[op_kalk->rozmiar]);
}



