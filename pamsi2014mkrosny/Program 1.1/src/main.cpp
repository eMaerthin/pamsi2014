#include "operacje.hh"

int main() {
    int opcja;
	queue <int> tablica;
	do { 
cout << "1.Wczytanie tablicy z konsoli"<< endl;
cout << "2.Wyœwietlenie tablicy na konsoli"<< endl;
cout << "3.Wczytywanie z pliku tekstowego"<< endl;
cout << "4.Zapisywanie do pliku tekstowego"<< endl;
cout << "5.Wczytywanie z pliku binarnego"<< endl;
cout << "6.Zapisywanie do pliku binarnego"<< endl;
cout << "7.Wype³nianie tablicy liczbami losowymi"<< endl;
cout << "8.Tworzenie dynamicznej kopii + wyœwietlenie kopii"<< endl;
cout << "0.Koniec"<< endl;
cout << "Wybierz opcjê" << endl;
cin >> opcja;
switch(opcja) {
	case 0: break;
	case 1: Wczytywanie_Konsola(tablica); break;
	case 2: Wyswietl_Konsola(tablica); break;
	case 3: Wczytaj_TXT(tablica); Wyswietl_Konsola(tablica); break;
	case 4: Zapisz_TXT(tablica); break;
	case 5: Wczytaj_BIN(tablica); Wyswietl_Konsola(tablica); break;
	case 6: Zapisz_BIN(tablica); break;
	case 7: Wypelnij_Losowo(tablica); break;
	case 8: Kopia(tablica); break;
	}
} while(opcja !=0);

	return 0;
}

