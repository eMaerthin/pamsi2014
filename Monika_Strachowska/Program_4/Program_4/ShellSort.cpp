#include "ShellSort.h"
#include <iostream>
#include <Windows.h>

using namespace std;


ShellSort::ShellSort(void)
	: czas(0)
{
}


ShellSort::ShellSort(int rozmiar1, int rozkald1, int uporzadkowanie1)
{
	
	setRozklad(rozkald1);
	setRozmiar(rozmiar1);
	setUporzadkowanie(uporzadkowanie1);
	tablica = new int[rozmiar1];
	uzupelnianeTablicy();
	wstepneSortowanie();
	__int64 poczatek = 0, koniec = 0;
	QueryPerformanceCounter((LARGE_INTEGER*) & poczatek);
	algorytmSS();
	QueryPerformanceCounter((LARGE_INTEGER*) & koniec);
	czas = (long double) (koniec - poczatek);
	__int64 czestotliwosc;
	QueryPerformanceFrequency((LARGE_INTEGER*) & czestotliwosc);
	czas = (long double) (czas * 1000  / czestotliwosc);
}


ShellSort::~ShellSort(void)
{
}


void ShellSort::algorytmSS(void)
{
	int i, j;
	for(int podzial = rozmiar / 3; podzial > 0; podzial /= 3) {
		for( i = podzial; i < rozmiar; i++) {
			int temp = tablica[i];
			for(j = i; j >= podzial; j -= podzial) {
				if(temp < tablica[j - podzial])
					tablica[j] = tablica[j - podzial];
				else
					break;
			}
			tablica[j] = temp;
		}
	}
}


long double ShellSort::getCzas(void)
{
	return czas;
}
