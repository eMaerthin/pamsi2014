#ifndef BELLMAN_FORD_H
#define BELLMAN_FORD_H

#include "lista.h"
#include "macierz.h"
#include <limits>
#include <fstream>

//Klasa zawierajaca metody dla klas macierz i lista
class bellman_ford {
  public:
  double * droga; //Wskaznik na macierz kosztu drogi od wierzcholka startowego do wierzcholka o zadanym indeksie
  list<int> przejscia[400]; //Tablica list przechowujaca ciag wierzcholkow od wierzcholka startowego
  int znajdz_drogi(macierz dane, int n); //Znajduje najkrotsze drogi dla macierzy
  int znajdz_drogi(lista dane, int n);   //Znajduje najkrotsze drogi dla listy
  void wyswietl_drogi(double * droga, int n, int start);  //Wyswietla drogi
  void zapisz_do_pliku(fstream & plik, int n, int start); //Zapisuje drogi do pliku
};

#endif // BELLMAN_FORD_H
