#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "lista.h"
#include "macierz.h"
#include <limits>
#include <fstream>

//Klasa zawierajaca metody dla klas macierz i lista
class dijkstra {
  public:
  double * droga; //Wskaznik na macierz kosztu drogi od wierzcholka startowego do wierzcholka o zadanym indeksie
  list<int> przejscia[400]; //Tablica list przechowujaca ciag wierzcholkow od wierzcholka startowego
  list<int> wierzcholki;  //Lista przechowujaca wierzcholki do rozpatrzenia
  void znajdz_drogi(macierz dane, int n); //Znajduje najkrotsze drogi dla macierzy
  void znajdz_drogi(lista dane, int n);   //Znajduje najkrotsze drogi dla listy
  double wez_najmniejszy(double * droga); //Zwraca wierzcholek do ktorego droga jest najkrotsza
  void wyswietl_drogi(double * droga, int n, int start);  //Wyswietla drogi
  void zapisz_do_pliku(fstream & plik, int n, int start); //Zapisuje drogi do pliku
};

#endif // DIJKSTRA_H
