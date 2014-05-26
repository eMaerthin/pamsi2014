#ifndef MACIERZ_H
#define MACIERZ_H

#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

class macierz {
  public:
  int ** drzewko; //Wskaünik na macierz incydencji
  int max;        //Zmienna zawierajaca maksymalny indeks macierzy
  float gestosc;  //Zmienna zawierajaca gestosc grafu
  macierz(int n); //Konstruktor macierzy incydencji
  void dodaj(int pierwszy, int drugi, int waga);  //Dodaje do macierzy wage o zadanych wierzcholkach
  int suma_wag();
  void wyswietl_macierz();
  macierz czytaj_plik(fstream & plik, int n); //Czyta graf z pliku
	void zapisz_do_pliku(fstream & plik);       //Zapisuje graf do pliku
};

int znajdz_max(fstream & plik); //Znajduje w pliku maksymalny indeks macierzy

#endif // MACIERZ_H
