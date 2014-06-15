#ifndef KAFELEK_H
#define KAFELEK_H

//Rozmiar kafelka
#define rozm_kaf 4

//Kafelek zawiera w sobie 4x4 elementy mapy na ktorych moze znajdowac sie fragment postaci
class Kafelek {
	//0 - wolne pole, 1 - zajete pole
	short tab[rozm_kaf][rozm_kaf];

public:
	Kafelek();

	short _G1() const;//funkcja podaje ile jest wolnych pol w lini pierwszej od gory
	short _G2() const;//funkcja podaje ile jest wolnych pol w lini drugiej od gory

	short _D1() const;//funkcja podaje ile jest wolnych pol w lini pierwszej od dolu
	short _D2() const;//funkcja podaje ile jest wolnych pol w lini drugiej od dolu

	short _P1() const;//funkcja podaje ile jest wolnych pol w lini pierwszej od prawej
	short _P2() const;//funkcja podaje ile jest wolnych pol w lini drugiej od prawej

	short _L1() const;//funkcja podaje ile jest wolnych pol w lini pierwszej od lewej
	short _L2() const;//funkcja podaje ile jest wolnych pol w lini drugiej od lewej

	//Operator pozwala na szybkie odwolanie sie do elementu o 'x' i 'y': <0, 3>
	short& operator()(short x, short y) { return tab[y][x]; }
	//Zmienia wartosc pola 'x' i 'y': <0, 3>, na 'wartosc'.
	void zmienPole(short x, short y, short wartosc) { tab[y][x] = wartosc; }

	//Podaje wartosc pola o 'x' i 'y': <0, 3>
	short podajWartPola(short x, short y) const { return tab[y][x]; }

	//Podaje ilosc wolnych pol w kafelku: <0, 16>
	short wolnePola() const;
};

#endif