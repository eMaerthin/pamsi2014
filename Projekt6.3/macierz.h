#ifndef MACIERZ_H
#define MACIERZ_H

#include <iostream>
#include <math.h>
using namespace std;

class macierz {
  public:
  int ** graf;     //Wskaznik na macierz incydencji
  int krawedzie;   //Zmienna zawierajaca liczbe krawedzi
	int wierzcholki; //Zmienna zawierajaca liczbe wierzcholkow
	int start;       //Zmienna zawierajaca wierzcholek startowy
  macierz(int n);  //Konstruktor macierzy incydencji
  void dodaj(int pierwszy, int drugi, int waga);  //Dodaje do macierzy wage o zadanych wierzcholkach
  void wyswietl_macierz();    //Wyswietla macierz incydencji
  void wyswietl_parametry();  //Wyswietla liczbe krawedzi, wierzcholkow i wierzcholek startowy
};

#endif // MACIERZ_H
