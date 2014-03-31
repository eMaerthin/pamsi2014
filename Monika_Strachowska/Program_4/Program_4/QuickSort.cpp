#include "QuickSort.h"
#include <iostream>
using namespace std;


QuickSort::QuickSort(void)
{
}


QuickSort::QuickSort(int rozmiar1, int rozkald1, int uporzadkowanie1)
{
	setRozklad(rozkald1);
	setRozmiar(rozmiar1);
	setUporzadkowanie(uporzadkowanie1);
	tablica = new int[rozmiar1];
	uzupelnianeTablicy();
	wyswietlanieTablicy();
	wstepneSortowanie();
	wyswietlanieTablicy();
	algorytm(0,rozmiar - 1);
	wyswietlanieTablicy();
}


QuickSort::~QuickSort(void)
{
}


void QuickSort::algorytm(int lewy, int prawy)
{
	int i = (lewy + prawy)/2;
	int piwot = tablica[i];
	tablica[i] = tablica[prawy];
	int j = lewy;
	for(int i = lewy; i < prawy; i++) {
		if(tablica[i] < piwot){
			int tmp = tablica[i];
			tablica[i] = tablica[j];
			tablica[j] = tmp;
			j += 1;
		}
	}
	tablica[prawy] = tablica[j];
	tablica[j] = piwot;
	if(lewy < j - 1)
		algorytm(lewy, j - 1);
	if(j + 1 < prawy)
		algorytm(j + 1, prawy);
}
