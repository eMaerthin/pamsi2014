#ifndef AI_H
#define AI_H
#include "szachownica.h"
#include "pionek.h"
#include "damka.h"
#include "sprawdzenia.h"

class komputer {
  public:
  class wezel {
    public:
    int poczatek;
    szachownica stan;
    int punkty;
    list<wezel> mozliwosci;
  };
  list<wezel> koncowy;
  pair<int,int> najlepszy; //Pierwsza zmienna przechowuje wezel poczatkowy, a druga najlepszy wynik punktowy
  int poziom;
  int symulacje;
  int zakoncz;
  szachownica ruch_komputera(szachownica dane);
  wezel zasymuluj_ruchy(wezel w, szachownica dane, int gracz, int trudnosc);
  int ocen_sytuacje(szachownica stan1, szachownica stan2, int gracz);
};

#endif // AI_H
