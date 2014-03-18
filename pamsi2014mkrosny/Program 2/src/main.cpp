#include "stos.hh"
#define TYP int //double, float, string, itd

int main() {
	int opcja;
	k_stos<TYP> stos;
	TYP dana;
	do {
		cout << "1.Dodawanie elementu na poczatek listy" << endl;
		cout << "2.Wyœwietlenie zawartosci listy i jej rozmiaru" << endl;
		cout << "3.Usuniêcie elementu listy" << endl;
		cout << "0.Koniec" << endl;
		cout << "Wybierz opcjê" << endl;
		cin >> opcja;
		cout << endl;
		switch (opcja) {
		case 0: break;
		case 1: cout << "Podaj element do polozenia na poczatek stosu:" << endl; cin >> dana; stos.Poloz_poczatek(dana); break;
		case 2: stos.Wyswietl_stos(); cout << endl;  stos.Rozmiar_stosu(); break;
		case 3: stos.Usun_poczatek(); break;
		}
	} while (opcja != 0);

	return 0;
}