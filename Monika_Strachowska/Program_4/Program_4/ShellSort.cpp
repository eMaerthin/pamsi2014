#include "ShellSort.h"
#include <iostream>

using namespace std;


ShellSort::ShellSort(void)
{
}


ShellSort::ShellSort(int rozmiar1, int rozkald1, int uporzadkowanie1)
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


ShellSort::~ShellSort(void)
{
}


void ShellSort::algorytm(void)
{
	int h = 1;
	do {
		h = 3 * h + 1;
	}while(h < rozmiar);
	h = h % 9; 
	if(h > 0)
		podzial = h - 1;
	else podzial = 1; 
	do {
		for(int j = rozmiar - podzial - 1; j >= 0; j--) {
			int x = tablica[j];
			int i = j + podzial;
			do {
				tablica[i - podzial] = tablica[i];
				i += podzial;
			}while((i < rozmiar) && (x > tablica[i])) ;
			tablica[i - podzial] = x;
		}
		podzial = podzial / 3;
	}while(podzial > 0);

}
