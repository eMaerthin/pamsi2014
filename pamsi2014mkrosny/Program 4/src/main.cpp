#include "tester.hh"
#include "eksperyment.hh"
int main() {
	char wybor;
	do {
		cout << "'t': Program tester pozwala na wczytanie danych z konsoli," << endl;
		cout << "\twybor algorytmu sortujacego, nastepnie sortuje wedle" << endl;
		cout << "\twybranej metody i wyswietla czas dzialania algorytmu." << endl;
		cout << "\tMo¿na wybraæ sortowanie rosn¹co lub malej¹co." << endl;

		cout << "'e': Program eksperyment pozwala na testowanie efektywnosci algorytmow." << endl;
		cout << "\tW programie dostepne sa roznego rodzaju tablice danych do sortowania," << endl;
		cout << "\tprogram sortuje wybrane dane wszystkimi algorytmami n=100 razy " << endl;
		cout << "\ti wyswietla sredni czas dzialania danego algorytmu." << endl;
		cout << "\tMo¿na wybraæ sortowanie rosn¹co lub malej¹co." << endl;

		cout << "'w': Wyjœcie do systemu." << endl;
		cout << "Wybierz program:\t";
		cin >> wybor;
		switch (wybor) {
		case 'w': break;
		case 't': tester(); break;
		case 'e': eksperyment(); break;
		default: cout << "Nieprawidlowy wybor, sprobuj ponownie." << endl << endl; break; }
	} while (wybor != 'w');
	return 0;
}