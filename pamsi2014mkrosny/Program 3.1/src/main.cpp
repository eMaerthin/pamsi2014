#include "stos.hh"

int main() {
	int opcja;
	stack <int> stos;
	do {
		cout << "__________________________________" << endl;
		cout << "1.Umieszczanie elementu na stosie" << endl;
		cout << "2.Wyœwietlenie elementów stosu w konsoli" << endl;
		cout << "3.Wyszukanie elementu na stosie" << endl;
		cout << "4.Usuwanie elementu ze stosu" << endl;
		cout << "__________________________________" << endl;
		cout << "0.Koniec" << endl;
		cout << "__________________________________" << endl;
		cout << "Wybierz opcjê:" << endl;
		cin >> opcja;
		switch (opcja) {
		case 0: break;
		case 1: Dodaj_konsola(stos); break;
		case 2: Wyswietl_konsola(stos); break;
		case 3: Wyszukaj(stos); break;
		case 4: Usun(stos); break;
		}
	} while (opcja != 0);

	return 0;
}