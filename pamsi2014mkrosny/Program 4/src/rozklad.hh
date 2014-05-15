#ifndef ROZKLAD_HH
#define ROZKLAD_HH
#include <random>
#include <iostream>

using namespace std;

void wyswietl(TYP * tablica, int rozmiar) {
	cout << endl << "Tablica danych: " << endl;
	for (int i = 0; i < rozmiar; i++) {
		cout << tablica[i] << "   ";
	}
	cout << endl;
}

void Wypelnij_rozklad_normalny(TYP * tablica, int rozmiar) {
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
void Wypelnij_rozklad_poissona(TYP * tablica, int rozmiar) {
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
void Wypelnij_rozklad_jednostajny(TYP * tablica, int rozmiar) {
	int przedzial1, przedzial2;
	double liczba;
	cout << "Podaj zakres przedzialu dyskretnego rozkladu jednostajnego (np. 0,9: wpisz 0, zatwierdŸ enter, wpisz 9, zatwierdŸ enter):" << endl;
	cin >> przedzial1;
	cin >> przedzial2;

	default_random_engine generator;
	uniform_int_distribution<int> rozklad(przedzial1, przedzial2);

	for (int i = 0; i < rozmiar; ++i) {
		liczba = rozklad(generator);
		tablica[i] = TYP(liczba);
	}
}
#endif