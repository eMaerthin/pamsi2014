#pragma once
#include "Tablica.h"
class ShellSort : public Tablica
{
public:
	int podzial;
	ShellSort(void);
	ShellSort(int rozmiar1, int rozkald1, int uporzadkowanie1);
	~ShellSort(void);
	void algorytm(void);
	void wyznaczenieOptymalnegoPodzialu(void);
};

