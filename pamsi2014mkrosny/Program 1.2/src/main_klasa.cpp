#include "tablica_klasa.hh"

int main()
{
	int opcja;
	Tablica<TYP> tablica;

	do{
		cout << "1.Wczytanie tablicy z konsoli" << endl;
		cout << "2.Wyœwietlenie tablicy na konsoli" << endl;
		cout << "3.Wczytywanie z pliku tekstowego" << endl;
		cout << "4.Zapisywanie do pliku tekstowego" << endl;
		cout << "5.Wczytywanie z pliku binarnego" << endl;
		cout << "6.Zapisywanie do pliku binarnego" << endl;
		cout << "7.Wype³nianie tablicy liczbami losowymi" << endl;
		cout << "8.Tworzenie dynamicznej kopii + wyœwietlenie kopii" << endl;
		cout << "0.Koniec" << endl;
		cout << "Wybierz opcjê" << endl;
		cin >> opcja;

		switch (opcja){
		case 0: break;
		case 1: tablica.Wczytywanie_Konsola(); break;
		case 2: tablica.Wyswietl_Konsola(); break;
		case 3: tablica.Wczytaj_TXT(); tablica.Wyswietl_Konsola(); break;
		case 4: tablica.Zapisz_TXT(); break;
		case 5: tablica.Wczytaj_BIN(); tablica.Wyswietl_Konsola(); break;
		case 6: tablica.Zapisz_BIN(); break;
		case 7: tablica.Wypelnij_Losowo(); break;
		case 8: Tablica<TYP> tablica_kopia; tablica_kopia = tablica; tablica_kopia.Wyswietl_Konsola(); break;
		}

	} while (opcja != 0);
	return 0;
}