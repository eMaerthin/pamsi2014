#include "lista.hh"
#include "macierz.hh"

int main() {
	int wybor;
	cout << "Program umo¿liwia wczytanie grafu z pliku do macierzy lub listy\n\ti wyœwietlenie go w danej formie, a nastêpnie zapis do pliku." << endl;
	do {
		cout << "1. Forma listy." << endl;
		cout << "2. Forma macierzowa." << endl;
		cout << "0. Wyjœcie do systemu." << endl;
		cout << "Wybierz opcjê:\t";
		cin >> wybor;
		switch (wybor) {
		case 0: break;
		case 1: Program_lista(); break;
		case 2:	Program_macierz(); break;
		default: cout << "Nieprawidlowy wybor, sprobuj ponownie." << endl << endl; break;
		}
	} while (wybor != 0);
	return 0;
}