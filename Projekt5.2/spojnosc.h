#ifndef SPOJNOSC_H
#define SPOJNOSC_H
#include "lista.h"
#include "macierz.h"

//Klasa zawieraj¹ca metody dla klasy macierz
class spojnosc_macierzy {
  public:
  int sprawdz_spojnosc(macierz dane, int n); //Sprawdza spojnosc grafu dla zadanej macierzy incydencji
};

//Klasa zawieraj¹ca metody dla klasy lista
class spojnosc_listy: public lista {
  public:
  int sprawdz_spojnosc(lista dane, int n);  //Sprawdza spojnosc grafu dla zadanej listy polaczen
};

void sortuj_sasiadow(list<int> & tmp); //Sortuje wektor

#endif // SPOJNOSC_H
