#include "BubbleSort.h"
#include <iostream>
#include <random>

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
	wyswietlanieTablicy();
	wstepneSortowanie();
	wyswietlanieTablicy();
	algorytm();
	wyswietlanieTablicy();
}


BubbleSort::~BubbleSort(void)
{
}


void BubbleSort::algorytm(void)
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



