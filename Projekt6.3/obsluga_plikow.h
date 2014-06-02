#ifndef OBSLUGA_PLIKOW_H
#define OBSLUGA_PLIKOW_H
#include "lista.h"
#include "macierz.h"
#include <fstream>

template < class typ >
//Klasa zawierajaca metody dla klas macierz i lista
class obsluga_plikow {
  public:
  int znajdz_max(fstream & plik); //Znajduje najwiekszy numer wierzcholka w pliku
  typ czytaj_plik(fstream & plik, int n); //Czyta zadany plik i zwraca graf o zadanym typie (macierz/lista)
};

#endif // OBSLUGA_PLIKOW_H
