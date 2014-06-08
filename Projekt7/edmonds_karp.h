#ifndef EDMONDS_KARP_H
#define EDMONDS_KARP_H
#include "siec.h"
#include <list>

class edmonds_karp {
  public:
  list<int> polaczenia;
  void sortuj_liste(list<int> & tmp);   //Sortuje liste sasiadow
  void bfs(siec dane);                  //Algorytm szukania w szerz
  int wyznacz_przepustowosc(siec dane); //Zwraca maksymalna przepustowosc w sciezce
  void zmniejsz_przepustowosc(siec dane, int przepustowosc);  //Zmniejsza przepustowosc w sieci poczatkowej
  siec wyznacz_fmax(siec dane); //Wyznacza maksymalny przeplyw i zwraca siec pierwotna/przeplywowa
};

#endif // EDMONDS_KARP_H
