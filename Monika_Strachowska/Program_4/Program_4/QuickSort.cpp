#include "QuickSort.h"
#include <iostream>
#include <Windows.h>
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
	//wyswietlanieTablicy();
	wstepneSortowanie();
	//wyswietlanieTablicy();
	__int64 poczatek = 0, koniec = 0;
	QueryPerformanceCounter((LARGE_INTEGER*) & poczatek);
	algorytmQS(0,rozmiar - 1);
	QueryPerformanceCounter((LARGE_INTEGER*) & koniec);
	__int64 czas = koniec - poczatek;
	cout << "\n\n Czas " << czas << endl;
	wyswietlanieTablicy();
}


QuickSort::~QuickSort(void)
{
}


void QuickSort::algorytmQS(int lewy, int prawy)
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
		algorytmQS(lewy, j - 1);
	if(j + 1 < prawy)
		algorytmQS(j + 1, prawy);
}
