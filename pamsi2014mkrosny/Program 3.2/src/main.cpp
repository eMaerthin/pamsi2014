#include "kopiec.hh"
int main() {
	int opcja;
	do { cout << "Ile elementow bedzie mial kopiec?" << endl;
		cin >> opcja;	}
	while (!(opcja > 0));

	k_kopiec kopiec(opcja);
	do {
		cout << "__________________________________" << endl;
		cout << "1.Wypelnienie kopca "; kopiec.Rozmiar(); cout << "-elementowym rozwiniêciem liczby pi" << endl;
		cout << "2.Wypelnienie kopca "; kopiec.Rozmiar(); cout << " wartoœciami losowymi z rozk³adu normalnego" << endl;
		cout << "3.Przywracanie wlasnosci kopca" << endl;
		cout << "4.Wyswietlenie kopca w czytelnej formie" << endl;
		cout << "5. Przywrocenie wlasnosci + Usuniecie ze szczytu kopca elementu o najwiekszej wartosci" << endl;
		cout << "__________________________________" << endl;
		cout << "0.Koniec" << endl;
		cout << "__________________________________" << endl;
		cout << "Wybierz opcjê:" << endl;
		cin >> opcja;
		switch (opcja) {
		case 0: break;
		case 1: kopiec.Wypelnij_pi(); break;
		case 2: kopiec.Wypelnij_rozklad(); break;
		case 3: kopiec.Przywroc(); break;
		case 4: kopiec.Wyswietl(); break;
		case 5: kopiec.Przywroc(); kopiec.Usun_szczyt(); break;
		}
	} while (opcja != 0);

	return 0;
}