#ifndef FUNKCJE_HPP
#define FUNKCJE_HPP

#include <iostream>
#include <math.h>

#include "Drzewo.hpp"

int silnia(int n);
double symbol_newtona(int g, int d);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double wylosuj_prawdop_log2(int n);
double wylosuj_prawdop_min2(int n);
double wylosuj_prawdop_min3(int n);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
int partition(TYP *tablica, int p, int r) // dzielimy tablice na dwie czesci, w pierwszej wszystkie liczby sa mniejsze badz rowne x, w drugiej wieksze lub rowne od x
{
	TYP x = tablica[p], w; // obieramy x
	int i = p, j = r; // i, j - indeksy w tabeli
	while (true) // petla nieskonczona - wychodzimy z niej tylko przez return j
	{
		while (tablica[j] > x) // dopoki elementy sa wieksze od x
			j--;
		while (tablica[i] < x) // dopoki elementy sa mniejsze od x
			i++;
		if (i < j) // zamieniamy miejscami gdy i < j
		{
			w = tablica[i];
			tablica[i] = tablica[j];
			tablica[j] = w;
			i++;
			j--;
		}
		else // gdy i >= j zwracamy j jako punkt podzialu tablicy
			return j;
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
void quicksort(TYP *tablica, int p, int r) // sortowanie szybkie
{
	int q;
	if (p < r)
	{
		q = partition(tablica, p, r); // dzielimy tablice na dwie czesci; q oznacza punkt podzialu
		quicksort(tablica, p, q); // wywolujemy rekurencyjnie quicksort dla pierwszej czesci tablicy
		quicksort(tablica, q + 1, r); // wywolujemy rekurencyjnie quicksort dla drugiej czesci tablicy
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//void eksperyment();


//double wykonaj_alg_i_wez_czas(Drzewo<int> tab, int aaa){ return 2.2; }
//Drzewo<int> moje;


#endif