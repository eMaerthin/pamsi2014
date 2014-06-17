#ifndef SZACHOWNICA_H
#define SZACHOWNICA_H
#include <iostream>
#include <list>
using namespace std;

class szachownica {
  public:
  int pole[8][8];
  //int poziom;
  int byl_ruch;
  int trudnosc;
  pair<int,int> ostatni;
  list<pair<int,int> > zbicia, przejscia;
  list<list<pair<int,int> > > zagrozone;
  list<list<pair<int,int> > > zwykle_ruchy;
  szachownica();
  void wyswietl_szachownice();
};

#endif // SZACHOWNICA_H
