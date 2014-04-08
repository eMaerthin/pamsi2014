#ifndef SCALANIE_HH
#define SCALANIE_HH

#include <boost/timer/timer.hpp>

void scal_rosn(TYP * tablica, int rozmiar, int poczatek, int srodek, int koniec) {
	TYP * temp=new TYP[rozmiar];
	for (int i = poczatek; i <= koniec; i++) temp[i] = tablica[i];  // Skopiowanie danych do tablicy pomocniczej

	int p = poczatek;
	int s = srodek + 1;
	int k = poczatek;                 // Ustawienie wskaŸników tablic
	while (p <= srodek && s <= koniec) {         // Przenoszenie danych z sortowaniem ze zbiorów pomocniczych do tablicy g³ównej
		if (temp[p]<temp[s]) tablica[k++] = temp[p++];
		else tablica[k++] = temp[s++];
	}
	while (p <= srodek)	tablica[k++] = temp[p++]; // Przeniesienie nie skopiowanych danych ze zbioru pierwszego w przypadku, gdy drugi zbiór siê skoñczy³
}

/* Procedura sortowania tab[pocz...kon] */
void sort_scalanie_rosn(TYP * tablica, int rozmiar, int pocz, int kon) {
	int srodek;
	int poczatek = pocz;
	int koniec = kon;
	if (poczatek<koniec) {
		srodek = (poczatek + koniec) / 2;
		sort_scalanie_rosn(tablica, rozmiar, poczatek, srodek);    // Dzielenie lewej czêœci
		sort_scalanie_rosn(tablica, rozmiar, srodek + 1, koniec);   // Dzielenie prawej czêœci
		scal_rosn(tablica, rozmiar, poczatek, srodek, koniec);   // £¹czenie czêœci lewej i prawej
	}
}

void scal_malej(TYP * tablica, int rozmiar, int poczatek, int srodek, int koniec) {
	TYP * temp = new TYP[rozmiar];
	for (int i = poczatek; i <= koniec; i++) temp[i] = tablica[i];  // Skopiowanie danych do tablicy pomocniczej

	int p = poczatek;
	int s = srodek + 1;
	int k = poczatek;                 // Ustawienie wskaŸników tablic
	while (p <= srodek && s <= koniec) {         // Przenoszenie danych z sortowaniem ze zbiorów pomocniczych do tablicy g³ównej
		if (temp[p]>temp[s]) tablica[k++] = temp[p++];
		else tablica[k++] = temp[s++];
	}
	while (p <= srodek)	tablica[k++] = temp[p++]; // Przeniesienie nie skopiowanych danych ze zbioru pierwszego w przypadku, gdy drugi zbiór siê skoñczy³
}

/* Procedura sortowania tab[pocz...kon] */
void sort_scalanie_malej(TYP * tablica, int rozmiar, int pocz, int kon) {
	int srodek;
	int poczatek = pocz;
	int koniec = kon;
	if (poczatek<koniec) {
		srodek = (poczatek + koniec) / 2;
		sort_scalanie_malej(tablica, rozmiar, poczatek, srodek);    // Dzielenie lewej czêœci
		sort_scalanie_malej(tablica, rozmiar, srodek + 1, koniec);   // Dzielenie prawej czêœci
		scal_malej(tablica, rozmiar, poczatek, srodek, koniec);   // £¹czenie czêœci lewej i prawej
	}
}

#endif