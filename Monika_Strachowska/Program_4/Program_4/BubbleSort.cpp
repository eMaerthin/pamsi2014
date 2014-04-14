#include "BubbleSort.h"
#include <iostream>
#include <random>
#include <Windows.h>

using namespace std;

BubbleSort::BubbleSort(void)
	: czas(0)
{
}

BubbleSort::BubbleSort(int rozmiar1, int rozkald1, int uporzadkowanie1)
{
	setRozklad(rozkald1);
	setRozmiar(rozmiar1);
	setUporzadkowanie(uporzadkowanie1);
	tablica = new int[rozmiar1];
	uzupelnianeTablicy();
	wstepneSortowanie();

	__int64 poczatek = 0, koniec = 0;
	QueryPerformanceCounter((LARGE_INTEGER*) & poczatek);
	algorytmBS();
	QueryPerformanceCounter((LARGE_INTEGER*) & koniec);
	czas = (long double) (koniec - poczatek);
	__int64 czestotliwosc;
	QueryPerformanceFrequency((LARGE_INTEGER*) & czestotliwosc);
	czas = (long double) (czas * 1000  / czestotliwosc);
}


BubbleSort::~BubbleSort(void)
{
}


void BubbleSort::algorytmBS(void)
{
	int n = rozmiar;
	do {
		for(int i = 0; i < n - 1; i++)
			if(tablica[i] > tablica[i + 1]) {
				int tmp = tablica[i];
				tablica[i] = tablica[i+1];
				tablica[i+1] = tmp;
			}
			n--;
	}while(n>1);
}


long double BubbleSort::getCzas(void)
{
	return czas;
}
