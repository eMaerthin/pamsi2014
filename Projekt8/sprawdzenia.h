#ifndef SPRAWDZENIA_H
#define SPRAWDZENIA_H
#include "szachownica.h"

class sprawdzenia {
  public:
  int czy_sa_pionki(szachownica dane, int gracz);
  szachownica sprawdz_ruchy(szachownica dane, int gracz);
  szachownica sprawdz_bicia(szachownica dane, int gracz);
  szachownica ukaraj(szachownica dane, int gracz);
};

#endif // SPRAWDZENIA_H
