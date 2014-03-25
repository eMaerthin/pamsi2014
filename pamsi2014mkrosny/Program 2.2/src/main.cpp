#include "lista.hh"
#define TYP int //double, float, string, itd

int main() {
	int opcja;
	k_lista<TYP> lista;
	TYP dana;
	do {
		cout << endl << "1.Dodawanie elementu na poczatek listy" << endl;
		cout << "2.Dodanie elementu na koniec listy" << endl;
		cout << "3.Wyœwietlenie zawartosci listy i jej rozmiaru" << endl;
		cout << "4.Usuniecie elementu listy z poczatku" << endl;
		cout << "5.Usuniecie elementu listy z konca" << endl;
		cout << "0.Koniec" << endl;
		cout << "Wybierz opcjê" << endl;
		cin >> opcja;
		cout << endl;
		switch (opcja) {
		case 0: break;
		case 1: cout << "Podaj element do polozenia na poczatek listy:" << endl; cin >> dana; lista.Poloz_poczatek(dana); break;
		case 2: cout << "Podaj element do polozenia na koniec listy:" << endl; cin >> dana; lista.Poloz_koniec(dana); break;
		case 3: lista.Wyswietl_liste(); cout << endl;  lista.Rozmiar_listy(); break;
		case 4: lista.Usun_poczatek(); break;
		case 5: lista.Usun_koniec(); break;
		}
	} while (opcja != 0);

	return 0;
}