#ifndef PRIM_H
#define PRIM_H

#include "macierz.h"
#include "lista.h"

//Klasa zawieraj¹ca metody dla klasy macierz
class prim_macierz {
  public:
  void sortuj_polaczenia(list<vector<int> > & polaczenia); //Sortuje liste wedlug wag
  macierz stworz_min(macierz dane, int n);  //Tworzy MDR dla zadanej listy i liczby wierzcholkow
};

//Klasa zawieraj¹ca metody dla klasy lista
class prim_lista: public lista {
  public:
  lista stworz_min(lista dane); //Tworzy MDR dla zadanej macierzy i liczby wierzcholkow
};

#endif // PRIM_H
