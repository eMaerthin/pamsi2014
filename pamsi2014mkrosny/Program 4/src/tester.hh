#ifndef TESTER_HH
#define TESTER_HH
#define TYP int
#include <boost/date_time/posix_time/posix_time.hpp>
#include "babel.hh"//sortowania
#include "wybor.hh"
#include "scalanie.hh"
#include "rozklad.hh"

//W programie tester zakomentowane sa fragmenty kodu, ktore pozwalaja wyswietlic tablice przed i po sortowaniu, sprawdzic, czy algorytm dziala poprawnie.
//Z koniecznosci zachowania estetyki wyswietlania wazniejszych informacji w konsoli niz kolejnosc wielu elementow tablicy,
//	pozostaja one domyslnie zakomentowane.

using namespace boost::posix_time;

void tester() {
	int rozmiar, i;
	do {
		cout << "Program tester wczytuj¹cy dane i sortuj¹cy wedle wybranej metody." << endl;
		cout << "Podaj iloœæ elementów do posortowania:\t";
		cin >> rozmiar; //wczytanie rozmiaru deklarowanej tablicy
	} while (!(rozmiar > 0));

	TYP * tablica = new TYP[rozmiar];	//deklaracja tablicy o odpowiedniej iloœci elementów
	TYP * s_tablica = new TYP[rozmiar]; //deklaracja tablicy do sortowania
	do {
		cout << "1. Wczytywanie danych z konsoli do tablicy." << endl;
		cout << "2. Wypelnienie tablicy rozkladem normalnym." << endl;
		cout << "3. Wypelnienie tablicy rozkladem jednostajnym." << endl;
		cout << "4. Wypelnienie tablicy rozkladem poissona." << endl;
		cout << "0. Wyjscie z programu tester." << endl;
		cout << "Wybierz dane do wype³nienia tablicy:\t";
		cin >> i;
		switch (i) {
		case 0: break; return;
		case 1: {	cout << "Wpisz elementy do posortowania, zatwierdzajac kazdy enterem:" << endl;
			for (i = 0; i < rozmiar; i++) cin >> tablica[i]; //wczytywanie danych
			i = 0; } break;
		case 2: Wypelnij_rozklad_normalny(tablica, rozmiar); i = 0; break;
		case 3: Wypelnij_rozklad_jednostajny(tablica, rozmiar); i = 0; break;
		case 4: Wypelnij_rozklad_poissona(tablica, rozmiar); i = 0; break;
		default: cout << "Nieprawidlowy wybor, sprobuj ponownie." << endl; break;
		}
	} while (i != 0);
	
	do {
		for (i = 0; i < rozmiar; i++) s_tablica[i] = tablica[i]; //odswiezenie tablicy do sortowania przed kolejnym sortowaniem
		cout << endl << "Wybierz metodê sortowania:" << endl;
		cout << "1. Sortowanie b¹belkowe - rosn¹co" << endl;
		cout << "2. Sortowanie b¹belkowe - malej¹co" << endl;
		cout << "3. Sortowanie przez wybór - rosn¹co" << endl;
		cout << "4. Sortowanie przez wybór - malej¹co" << endl;
		cout << "5. Sortowanie przez scalanie - rosn¹co" << endl;
		cout << "6. Sortowanie przez scalanie - malej¹co" << endl;
		cout << "0. Wyjœcie z programu tester" << endl;
		cin >> i;
		switch (i) {
		case 0: break;
		case 1: { //cout << "Przed sortowaniem:" << endl; wyswietl(tablica, rozmiar);
					ptime czas1 = microsec_clock::local_time();
					sort_babelkowe_rosn(s_tablica, rozmiar);
					ptime czas2 = microsec_clock::local_time();
					//cout << "Po sortowaniu:" << endl; wyswietl(s_tablica, rozmiar);
					time_duration czas = czas2 - czas1;
					cout << "Rzeczywisty czas wykonywania algorytmu: " << czas.total_milliseconds() << " ms\n"; } break;
		case 2: { //cout << "Przed sortowaniem:" << endl; wyswietl(tablica, rozmiar);
					ptime czas1 = microsec_clock::local_time();
					sort_babelkowe_malej(s_tablica, rozmiar);
					ptime czas2 = microsec_clock::local_time();
					//cout << "Po sortowaniu:" << endl; wyswietl(s_tablica, rozmiar);
					time_duration czas = czas2 - czas1;
					cout << "Rzeczywisty czas wykonywania algorytmu: " << czas.total_milliseconds() << " ms\n"; } break;
		case 3: { //cout << "Przed sortowaniem:" << endl; wyswietl(tablica, rozmiar);
					ptime czas1 = microsec_clock::local_time();
					sort_wybor_rosn(s_tablica, rozmiar);
					ptime czas2 = microsec_clock::local_time();
					//cout << "Po sortowaniu:" << endl; wyswietl(s_tablica, rozmiar);
					time_duration czas = czas2 - czas1;
					cout << "Rzeczywisty czas wykonywania algorytmu: " << czas.total_milliseconds() << " ms\n"; } break;
		case 4: { //cout << "Przed sortowaniem:" << endl; wyswietl(tablica, rozmiar);
					ptime czas1 = microsec_clock::local_time();
					sort_wybor_malej(s_tablica, rozmiar);
					ptime czas2 = microsec_clock::local_time();
					//cout << "Po sortowaniu:" << endl; wyswietl(s_tablica, rozmiar);
					time_duration czas = czas2 - czas1;
					cout << "Rzeczywisty czas wykonywania algorytmu: " << czas.total_milliseconds() << " ms\n"; } break;
		case 5: { //cout << "Przed sortowaniem:" << endl; wyswietl(tablica, rozmiar);
					ptime czas1 = microsec_clock::local_time();
					sort_scalanie_rosn(s_tablica, 0, rozmiar - 1);
					ptime czas2 = microsec_clock::local_time();
					//cout << "Po sortowaniu:" << endl; wyswietl(s_tablica, rozmiar);
					time_duration czas = czas2 - czas1;
					cout << "Rzeczywisty czas wykonywania algorytmu: " << czas.total_milliseconds() << " ms\n"; } break;
		case 6: { //cout << "Przed sortowaniem:" << endl; wyswietl(tablica, rozmiar);
					ptime czas1 = microsec_clock::local_time();
					sort_scalanie_malej(s_tablica, 0, rozmiar - 1);
					ptime czas2 = microsec_clock::local_time();
					//cout << "Po sortowaniu:" << endl; wyswietl(s_tablica, rozmiar);
					time_duration czas = czas2 - czas1;
					cout << "Rzeczywisty czas wykonywania algorytmu: " << czas.total_milliseconds() << " ms\n"; } break;
		default: cout << "Nieprawidlowy wybor, sprobuj ponownie." << endl; break;
		}
	} while (i != 0);
}
#endif