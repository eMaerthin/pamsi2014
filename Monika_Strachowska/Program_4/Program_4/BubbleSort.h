#pragma once
#include "Tablica.h"

class BubbleSort : public Tablica
{
public:
	BubbleSort(void);
	BubbleSort(int rozmiar1, int rozkald1, int uporzadkowanie1);
	~BubbleSort(void);
	void algorytmBS(void);
private:
	long double czas;
public:
	long double getCzas(void);
};

