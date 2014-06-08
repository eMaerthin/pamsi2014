#ifndef OBSLUGA_PLIKOW_H
#define OBSLUGA_PLIKOW_H
#include "siec.h"
#include <fstream>

//Klasa zawierajaca metody dla klas macierz i lista
class obsluga_plikow {
  public:
  siec czytaj_plik(fstream & plik, string nazwa, int n); //Czyta zadany plik i zwraca graf
};

#endif // OBSLUGA_PLIKOW_H
