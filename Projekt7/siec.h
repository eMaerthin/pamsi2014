#ifndef SIEC_H
#define SIEC_H

#include <iostream>
#include <math.h>
using namespace std;

class siec {
  public:
  int *** macierz;     //Wskaznik na siec pierwotna/residualna
  int wierzcholki;
  int krawedzie;
  int zrodlo;
  int ujscie;
  int fmax;            //Zmienna przechowujaca maksymalny przeplyw w sieci
  siec(int n);         //Konstruktor sieci
  int licz_fkrawedzie(); //Liczy krawedzie w sieci przeplywowej
  void wyswietl_siec_macierz();   //Wyswietla siec w formie macierzy
  void wyswietl_siec_lista();     //Wyswietla siec w formie listy
  void wyswietl_parametry();      //Wyswietla parametry sieci
};

#endif // SIEC_H
