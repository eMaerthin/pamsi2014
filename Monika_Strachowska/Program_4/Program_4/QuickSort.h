#pragma once
#include "Tablica.h"
class QuickSort : public Tablica
{
public:
	QuickSort(void);
	QuickSort(int rozmiar1, int rozkald1, int uporzadkowanie1);
	~QuickSort(void);
	void algorytmQS(int lewy, int prawy);
private:
	long double czas;
public:
	long double getCzas(void);
};

