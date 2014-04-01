#include <iostream>
#include "BubbleSort.h"
#include "ShellSort.h"
#include "QuickSort.h"
#include "Tablica.h"
#include <Windows.h>


void menu();

int main() {
	menu();
	system("PAUSE");
	return 0;
}


void menu() {
	std::cout << "Witaj! Ile elementow ma miec tablica?\n>";
	int n = 0;
	std::cin >> n;
	std::cout << "\n0 - sortowanie tablicy z rozkladu jednostajnego\n"
		<< "1 - sortowanie tablicy z rozkladu normalnego\n"
		<< "2 - sortowanie tablicy z rozkladu Poissona\n>";
	int rozklad = 0;
	std::cin >> rozklad;
	std::cout << "\n0 - sortowanie tablicy nieuporzadkowanej\n"
		<< "1 - sortowanie tablicy z 10% uporzadkowanymi elementami\n"
		<< "2 - sortowanie tablicy z 50% uporzadkowanymi elementami\n"
		<< "3 - sortowanie tablicy z 90% uporzadkowanymi elementami\n>";
	int uporzadkowanie = 0;
	std::cin >> uporzadkowanie;
	std::cout << "\n0 - sortowanie babelkowe\n"
		<< "1 - sortowanie shella\n"
		<< "2 - sortowanie quick sort\n";
	int ktore = 0;
	std::cin >> ktore;
	///*if(ktore == 0)*/ BubbleSort BS(n,rozklad,uporzadkowanie);
	/*else if(ktore == 1)*/ ShellSort SS(n,rozklad,uporzadkowanie);
	///*else if(ktore == 2)*/ QuickSort QS(n,rozklad,uporzadkowanie);
}

