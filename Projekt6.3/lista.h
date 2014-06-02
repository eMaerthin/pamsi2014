#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <vector>
#include <list>
#include <math.h>
using namespace std;

class lista {
  public:
	list<vector<int> > graf; //Lista zawierajaca wierzcholki oraz wagi ich polaczen (wektory)
	int krawedzie;    //Zmienna zawierajaca liczbe krawedz
	int wierzcholki;  //Zmienna zawierajaca liczbe wierzcholkow
	int start;        //Zmienna zawierajaca wierzcholek startowy
	lista(int n);     //Konstruktor listy polaczen
  void dodaj(int pierwszy, int drugi, int waga); //Dodaje wektor zawierajacy wierzcholki oraz wagi ich polaczen do grafu
	void wyswietl_liste();      //Wyswietla liste polaczen
	void wyswietl_parametry();  //Wyswietla liczbe krawedzi, wierzcholkow i wierzcholek startowy
};

#endif //LISTA_H
