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
	wyznaczenieOptymalnegoPodzialu();
	algorytm();
	wyswietlanieTablicy();
}


ShellSort::~ShellSort(void)
{
}


void ShellSort::algorytm(void)
{
	tablica[0] = 15;
	tablica[1] = 12;
	tablica[2] = 1;
	tablica[3] = 8;
	tablica[4] = 13;
	do {
		for(int j = rozmiar - podzial ; j >= 0; j--) {
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


void ShellSort::wyznaczenieOptymalnegoPodzialu(void)
{
	int h = 1;
	do {
		h = 3 * h + 1;
	}while(h < rozmiar);
	h = h % 9; 
	if(h > 0)
		podzial = h - 1;
	else podzial = 1; 
}
