#ifndef KRUSKAL_H
#define KRUSKAL_H

#include "macierz.h"
#include "lista.h"

//Klasa zawieraj¹ca metody dla klasy macierz
class kruskal_macierz {
  public:
  macierz stworz_min(macierz dane, int n); //Tworzy MDR dla zadanej macierzy i liczby wierzcholkow
};

//Klasa zawieraj¹ca metody dla klasy lista
class kruskal_lista: public lista {
  public:
  lista stworz_min(lista dane, int n); //Tworzy MDR dla zadanej listy i liczby wierzcholkow
};

#endif // KRUSKAL_H
