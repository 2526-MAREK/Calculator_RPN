#define DZIELENIE 5
#define MNOZENIE 4
#define ODEJMOWANIE 3
#define DODAWANIE 2
#define PUSTY_STOS 1
#define W_OK 0 //Wszystko jest poprawne ( brak błędów)
#define BRAK_ELEMENTOW printf("Brakuje elementów do wykonania operacji\n")

/*Lista przechowujaca stos*/
typedef struct t_stos {
  int elem_stosu; 
  struct t_stos *nast;
}T_ELEM;

typedef T_ELEM * T_STOS;

/*Struktura danych przechowujaca dane operacji kalkulatora, op_kalk od operacje kalkulatora*/
typedef struct op_kalk {
  int dana;
  int rozmiar; //zmienna do okreslania miejsca w tablicy
  int tab[2]; //tablica tymczasowa na dwa sciagniete elementy ze stosu
  int operacja;
}OP_KALK;

/*Prototypy funkcji*/
void init(T_STOS *stos);
int empty(T_STOS stos);
int push(T_STOS *stos, int *dana);
int pop(T_STOS *stos, int *dana);
void full_print(T_STOS stos);
void czyszczenie_bufora(void);
void wczytaj_liczbe(int *dana, T_STOS *stos, int dodaj_minus);
void operacje_arytmetyczne(T_STOS *stos, OP_KALK *op_kalk);
void clear_stos(T_STOS *glowny);
void reverse(T_STOS *glowny, OP_KALK *op_kalk);
void duplicate(T_STOS *glowny, OP_KALK *op_kalk);
