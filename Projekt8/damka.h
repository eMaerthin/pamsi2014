#ifndef DAMKA_H
#define DAMKA_H

#include "szachownica.h"
#include <cmath>
using namespace std;

class damka {
  public:
  //szachownica, gracz, indeksy pozycji poczatkowej, indeksy pozycji koncowej:
  szachownica ruch(szachownica,int, int, int, int, int);
  szachownica zbijaj(szachownica,int, int, int, int, int);
  szachownica idz(szachownica,int, int, int, int, int);
};

#endif // DAMKA_H
