#include "kolejka.hh"

int main() {
	int opcja;
	queue <int> kolejka;
	do {
		cout << "__________________________________" << endl;
		cout << "1.Umieszczenie elementu na koniec kolejki" << endl;
		cout << "2.Pobranie elementu z pocz�tku kolejki (usuwanie)" << endl;
		cout << "3.Wy�wietlanie d�ugo�ci kolejki" << endl;
		cout << "__________________________________" << endl;
		cout << "0.Koniec" << endl;
		cout << "__________________________________" << endl;
		cout << "Wybierz opcj�:" << endl;
		cin >> opcja;
		switch (opcja) {
		case 0: break;
		case 1: Dodaj_koniec(kolejka); break;
		case 2: Usun_poczatek(kolejka); break;
		case 3: Dlugosc(kolejka); break;
		}
	} while (opcja != 0);

	return 0;
}