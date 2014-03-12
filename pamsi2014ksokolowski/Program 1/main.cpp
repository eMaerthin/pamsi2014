#include <iostream>
#include "funkcje.h"
#include "Tablica.h"

using namespace std;

int main()
{
	short opcja;

	do {
		cout << "\n\n Menu" << endl
			<< "Ktora czesc chcesz uruchomic?" << endl
			<< "1. Pracujaca na funkcjach." << endl
			<< "2. Pracujaca na klasie." << endl
			<< "0. Wyjscie z programu." << endl
			<< "Twoj wybor:\t";
		cin >> opcja;

		switch (opcja){

		case 1: program_funkcje();
			break;

		case 2: program_klasa();
			break;
		}
	} while (opcja != 0);

	system("PAUSE");
	return 0;
}