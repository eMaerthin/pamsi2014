#ifndef SPOJNOSC_H
#define SPOJNOSC_H
#include "lista.h"
#include "macierz.h"

//Klasa zawierajaca metody dla klas macierz i lista
class sprawdzanie_spojnosci {
  public:
  void sortuj_sasiadow(list<int> & tmp);  //Sortuje liste
  int sprawdz_spojnosc(macierz dane, int n, int start); //Sprawdza spojnosc grafu dla zadanej macierzy incydencji
  int sprawdz_spojnosc(lista dane, int n, int start); //Sprawdza spojnosc grafu dla zadanej listy polaczen
};

#endif // SPOJNOSC_H
