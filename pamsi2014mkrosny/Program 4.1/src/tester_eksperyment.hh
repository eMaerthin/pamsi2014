#ifndef TESTER_EKSPERYMENT_CPP
#define TESTER_EKSPERYMENT_CPP
#define TYP int
#include <iostream>

#include "babel.hh"//sortowania
#include "wybor.hh"
#include "scalanie.hh"

using namespace std;
void wyswietl(TYP * tablica, int rozmiar) {
	cout << endl << "Tablica danych: " << endl;
	for (int i = 0; i < rozmiar; i++) { 
		cout << tablica[i] << "   "; }
	cout << endl;
}
void tester() {
	int rozmiar, i;
	do {
		cout << "Program tester wczytuj¹cy dane i sortuj¹cy wedle wybranej metody." << endl;

		cout << "Podaj iloœæ elementów do posortowania:\t";
		cin >> rozmiar; //wczytanie rozmiaru deklarowanej tablicy
	} while (!(rozmiar > 0));

	TYP * tablica = new TYP[rozmiar];	//deklaracja tablicy o odpowiedniej iloœci elementów
	TYP * s_tablica = new TYP[rozmiar]; //deklaracja tablicy do sortowania
	cout << "Wpisz elementy do posortowania, zatwierdzajac kazdy enterem:" << endl;
	for (i = 0; i < rozmiar; i++) cin >> tablica[i]; //wczytywanie danych

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
		case 1: { cout << "Przed sortowaniem:" << endl; wyswietl(tablica, rozmiar);
			sort_babelkowe_rosn(s_tablica, rozmiar); cout << "Po sortowaniu:" << endl; wyswietl(s_tablica, rozmiar); } break;
		case 2: { cout << "Przed sortowaniem:" << endl; wyswietl(tablica, rozmiar);
			sort_babelkowe_malej(s_tablica, rozmiar); cout << "Po sortowaniu:" << endl; wyswietl(s_tablica, rozmiar); } break;
		case 3: { cout << "Przed sortowaniem:" << endl; wyswietl(tablica, rozmiar);
			sort_wybor_rosn(s_tablica, rozmiar); cout << "Po sortowaniu:" << endl; wyswietl(s_tablica, rozmiar); } break;
		case 4: { cout << "Przed sortowaniem:" << endl; wyswietl(tablica, rozmiar);
			sort_wybor_malej(s_tablica, rozmiar); cout << "Po sortowaniu:" << endl; wyswietl(s_tablica, rozmiar); } break;
		case 5: { cout << "Przed sortowaniem:" << endl; wyswietl(tablica, rozmiar);
			boost::timer::auto_cpu_timer czas("Czas wykonywania algorytmu: %t sekund CPU, rzeczywisty: %w sekund\n");
			sort_scalanie_rosn(s_tablica, rozmiar, 0, rozmiar-1);
			cout << "Po sortowaniu:" << endl; wyswietl(s_tablica, rozmiar); } break;
		case 6: { cout << "Przed sortowaniem:" << endl; wyswietl(tablica, rozmiar);
			boost::timer::auto_cpu_timer czas("Czas wykonywania algorytmu: %t sekund CPU, rzeczywisty: %w sekund\n");
			sort_scalanie_malej(s_tablica, rozmiar, 0, rozmiar - 1); cout << "Po sortowaniu:" << endl; wyswietl(s_tablica, rozmiar); } break;
		default: cout << "Nieprawidlowy wybor, sprobuj ponownie." << endl; break;
		}
	} while (i != 0);
}
void eksperyment() {
	cout << "Program eksperyment generuj¹cy wybrane dane i sortuj¹cy dostêpnymi algorytmami." << endl;
}

void Wypelnij_rozklad_normalny() {
	double liczba, srednia, odchylenie;
	cout << "Podaj wartosc srednia(oczekiwana) jako liczbe typu double (np. 2.0 14.7):" << endl;
	cin >> srednia;
	cout << "Podaj odchylenie od wartosci sredniej jako liczbe typu double (np. 2.0 14.7), przykladowo polowe wartosci sredniej:" << endl;
	cin >> odchylenie;

	default_random_engine generator;
	normal_distribution<double> rozklad(srednia, odchylenie);

	for (int i = 0; i < rozmiar; ++i) {
		liczba = rozklad(generator);
		tablica[i] = TYP(liczba);
	}
}
void Wypelnij_rozklad_poissona() {
	double liczba, srednia;
	cout << "Podaj wartosc srednia(oczekiwana) jako liczbe typu double (np. 2.0 14.7):" << endl;
	cin >> srednia;

	default_random_engine generator;
	poisson_distribution<int> rozklad(srednia);

	for (int i = 0; i < rozmiar; ++i) {
		liczba = rozklad(generator);
		tablica[i] = TYP(liczba);
	}
}
void Wypelnij_rozklad_jednostajny() {
	int przedzial1,przedzial2;
	cout << "Podaj zakres przedzialu dyskretnego rozkladu jednostajnego (np. 0,9: wpisz 0, zatwierdŸ enter, wpisz 9, zatwierdŸ enter):" << endl;
	cin >> przedzial1;
	cin >> przedzial2;

	default_random_engine generator;
	uniform_int_distribution<int> rozklad(przedzial1,przedzial2);

	for (int i = 0; i < rozmiar; ++i) {
		liczba = rozklad(generator);
		tablica[i] = TYP(liczba);
	}
}
#endif