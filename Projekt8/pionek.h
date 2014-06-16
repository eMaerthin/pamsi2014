#ifndef PIONEK_H
#define PIONEK_H

#include "szachownica.h"
using namespace std;

class pionek {
  public:
  //szachownica, gracz, indeksy pozycji poczatkowej, indeksy pozycji koncowej:
  szachownica ruch(szachownica,int, int, int, int, int);
  szachownica zbijaj(szachownica,int, int, int, int, int);
  szachownica idz(szachownica,int, int, int, int, int);
};

#endif // PIONEK_H


