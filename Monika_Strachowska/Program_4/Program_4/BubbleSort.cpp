#include "BubbleSort.h"
#include <iostream>
#include <random>
#include <Windows.h>

using namespace std;

BubbleSort::BubbleSort(void)
{
}

BubbleSort::BubbleSort(int rozmiar1, int rozkald1, int uporzadkowanie1)
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
	algorytmBS();
	QueryPerformanceCounter((LARGE_INTEGER*) & koniec);
	__int64 czas = koniec - poczatek;
	cout << "\n\n Czas " << czas << endl;
	wyswietlanieTablicy();

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



