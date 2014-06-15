#ifndef POLEGRY_H
#define POLEGRY_H

#include <iostream>

#include "Wspolrzedne.h"
#include "Kafelek.h"

//rozmiar tablicy kafelkow - ilosc kafelkow w poziomie i w pionie
#define _rozm  20
//stala we wzorze na wage polaczenia miedzy kafelkami
#define stala  110 //32

//Klasa reprezentuje pole gry. Zawiera informacje o tym ktore elementy (pola) mapy sa zajete
class PoleGry {
	//Pole gry jest podzielone na wiele kafelkow
	Kafelek pole[_rozm][_rozm];

public:
	PoleGry() {};

	//Zmienia wspolrzedna na okreslona wartosc. wartosc - przyjmuje wartosci: 0 - wolne pole, 1 - zajete
	void zmienWsp(const Wspolrzedne& wsp, short wartosc);
	//Zmienia wspolrzedna na okreslona wartosc. Argumenty 'x' i 'y' reprezentuja warosci na odpowiadajacym im osiach <-39, 39>. wartosc - przyjmuje wartosci: 0 - wolne pole, 1 - zajete
	void zmienWsp(int x, int y, short wartosc);

	//Podaje wartosc na podanej wspolrzednej. Argumenty 'x' i 'y' reprezentuja warosci na odpowiadajacym im osiach <-39, 39>.
	short podajWart(int x, int y) const;
	short podajWart(const Wspolrzedne& wsp) const;


	//Szukanie wagi polaczenia z 'p_kafelek' do 'd_kafelek'. Waga jest okreslana wg specialnego wzoru.
	int wagaPolaczenia(short p_kafelek, short d_kafelek) const;
	//Waga polaczenia miedzy dwoma kafelkami w - oznacza wiersz, k - oznacza kolumna, p, d - odpowiednio pierwszy kafelek, drugi kafelek
	int wagaPolaczenia(short w_p, short k_p, short w_d, short k_d) const;

	//Podaje ilosc wolnych pol w podanym kafelku
	int ileWolnychPol(short x, short y) const { return pole[y][x].wolnePola(); }

	//Zwraca kafelek o podanym numerze 0-399
	Kafelek podajKafelek(short nr_kaf) const { return pole[nr_kaf / _rozm][nr_kaf%_rozm]; }
};


#endif