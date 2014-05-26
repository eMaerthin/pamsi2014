#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <math.h>
using namespace std;

class lista {
  public:
	list<vector<int> > drzewo;    //Lista zawierajaca wierzcholki oraz wagi drzewa (wektory)
	float gestosc;                //Zmienna zawierajaca gestosc grafu
  void dodaj(int pierwszy, int drugi, int waga); //Dodaje do listy wektor
  int suma_wag();                       //Sumuje wagi grafu
  lista czytaj_plik(fstream & plik);    //Czyta graf z pliku
	void zapisz_do_pliku(fstream & plik); //Zapisuje graf do pliku
	void wyswietl_liste();
	void sortuj_wagi();
};

#endif //LISTA_H
