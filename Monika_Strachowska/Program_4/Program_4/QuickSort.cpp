#include "QuickSort.h"
#include <iostream>
#include <Windows.h>
using namespace std;


QuickSort::QuickSort(void)
	: czas(0)
{
}


QuickSort::QuickSort(int rozmiar1, int rozkald1, int uporzadkowanie1)
{
	setRozklad(rozkald1);
	setRozmiar(rozmiar1);
	setUporzadkowanie(uporzadkowanie1);
	tablica = new int[rozmiar1];
	uzupelnianeTablicy();
	wstepneSortowanie();

	__int64 poczatek = 0, koniec = 0;
	QueryPerformanceCounter((LARGE_INTEGER*) & poczatek);
	algorytmQS(0,rozmiar - 1);
	QueryPerformanceCounter((LARGE_INTEGER*) & koniec);
	czas = (long double) (koniec - poczatek);
	__int64 czestotliwosc;
	QueryPerformanceFrequency((LARGE_INTEGER*) & czestotliwosc);
	czas = (long double) (czas * 1000  / czestotliwosc);
}


QuickSort::~QuickSort(void)
{
}


void QuickSort::algorytmQS(int lewy, int prawy)
{
	int i = lewy, j = prawy + 1;
	int temp, v = tablica[lewy];
	do {
		do {
			++i;
		} while (tablica[i] < v);
		do {
			--j;
		} while (tablica[j] > v);
		if (i < j)
		{
			temp = tablica[i];
			tablica[i] = tablica[j];
			tablica[j] = temp;
		}
	} while (j > i);
	tablica[lewy] = tablica[j];
	tablica[j] = v;
	if (j - 1 > lewy) {
		algorytmT(lewy, j - 1);
	}
	if (prawy > j + 1)	{
		algorytmT(j + 1, prawy);
	}
}


long double QuickSort::getCzas(void)
{
	return czas;
}
