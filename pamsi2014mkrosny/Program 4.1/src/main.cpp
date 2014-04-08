#include "tester_eksperyment.hh"
int main() {
	int wybor;
	do {
		cout << "1. Program tester pozwala na wczytanie danych z konsoli," << endl;
		cout << "\twybor algorytmu sortujacego, nastepnie sortuje wedle" << endl;
		cout << "\twybranej metody i wyswietla czas dzialania algorytmu." << endl;

		cout << "2. Program eksperyment pozwala na testowanie efektywnosci algorytmow." << endl;
		cout << "\tW programie dostepne sa roznego rodzaju tablice danych do sortowania," << endl;
		cout << "\tprogram sortuje wybrane dane wszystkimi algorytmami n=100 razy " << endl;
		cout << "\ti wyswietla sredni czas dzialania danego algorytmu." << endl;

		cout << "0. Wyjœcie do systemu." << endl;
		cout << "Wybierz program:\t";
		cin >> wybor;
		switch (wybor) {
		case 0: break;
		case 1: tester(); break;
		case 2: eksperyment(); break;
		default: cout << "Nieprawidlowy wybor, sprobuj ponownie." << endl; break; }
	} while (wybor != 0);
	return 0;
}