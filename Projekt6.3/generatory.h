#ifndef GENERATORY_H
#define GENERATORY_H
#include "lista.h"
#include "macierz.h"
#include <time.h>
#include <cstdlib>
#include <random>

template < class typ >
//Klasa zawierajaca metody dla klas macierz i lista
class generator {
  public:
  //Generuje i zwraca graf losowy dla zadanej liczby wierzcholkow,
  //prawdopodobienstwa polaczenia, wierzcholka startowego i rodzaju algorytmu
  typ generuj(int n, double p, int start, int algorytm);
};

#endif // GENERATORY_H
