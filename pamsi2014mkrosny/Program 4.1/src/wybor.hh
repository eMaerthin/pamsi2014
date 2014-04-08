#ifndef WYBOR_HH
#define WYBOR_HH
#include <boost/timer/timer.hpp>


void zamien(TYP * dane, int t, int j) {
	TYP temp = dane[j];//tymczasowe przechowanie
	dane[j] = dane[t];
	dane[t] = temp;
}

void sort_wybor_rosn(TYP * dane, int rozmiar) {
	boost::timer::auto_cpu_timer czas("Czas wykonywania algorytmu: %t sekund CPU, rzeczywisty: %w sekund\n");
	int min = 0;
	for (int i = 0; i < rozmiar; i++)
	if (dane[i] < dane[min]) min = i; //szukamy min
	zamien(dane, 0, min); //i ustawiamy na poczatku
	int j, k; //indeksowanie tablicy, indeks biezacy i porownywany
	int t; //tymczasowy indeks dla elementu, ktory bedzie zamieniany z biezacym
	for (j = 0; j < rozmiar; j++) {
		t = j; //element biezacy
		for (k = j + 1; k < rozmiar; k++) if (dane[k] < dane[t]) t = k; // element nastepny, jesli mniejszy od biezacego
		zamien(dane, t, j);									//przypisac jego indeks i zamienic miejscami z biezacym
	}
}

void sort_wybor_malej(TYP * dane, int rozmiar) {
	boost::timer::auto_cpu_timer czas("Czas wykonywania algorytmu: %t sekund CPU, rzeczywisty: %w sekund\n");
	int max = 0;
	for (int i = 0; i < rozmiar; i++)
	if (dane[i] > dane[max]) max = i; //szukamy max
	zamien(dane, 0, max); //i ustawiamy na poczatku

	int j, k; //indeksowanie tablicy, indeks biezacy i porownywany
	int t; //tymczasowy indeks dla elementu, ktory bedzie zamieniany z biezacym
	for (j = 0; j < rozmiar; j++) {
		t = j; //element biezacy
		for (k = j + 1; k < rozmiar; k++) if (dane[k]>dane[t]) t = k; // element nastepny, jesli wiêkszy od biezacego
		zamien(dane, t, j);									//przypisac jego indeks i zamienic miejscami z biezacym
	}
}
#endif