#ifndef POSTAC_H
#define POSTAC_H

#include <iostream>
#include <string>
#include <vector>
#include <GL/glut.h>
#include <ctime>	//srand
#include <cstdlib>	//srand

#include "Wspolrzedne.h"
#include "Graf.h"
#include "PoleGry.h"
#include <boost/thread/thread.hpp>

//szerokosc i wysokosc okna
const int _w = 408, _h = 408;
//zmienna reprezentuje rozmiar jednego piksela w oknie na osia <-1, 1>
const float jeden_piksel = (float)1/_w;

enum Kierunki {
	GORA = -1,
	DOL = 1,
	PRAWO = -3,
	LEWO = 3,
};

////////////////////////////////////////////////////////////
//Klasa reprezentujaca snake'a
class Postac {
	std::string nazwa_postaci;
	std::vector<Wspolrzedne> ogon; //wektor dla calego ciala snake'a - zawiera jego Wspolrzedne
	Kierunki akt_kierunek; //aktualny kierunek postaci
	GLfloat czerwony, zielony, niebieski; //Kolor postaci reprezentowany 3 odcieniami kolorow podstawowych

	bool kolizja; //Zmienna mowi czy ruch ktory zostal wykonany jest kolizyjny
	int przedluz; //do przedluzania ogona
	bool po_skrecie; //zmienna usprawniajaca skrecanie - nie jest opoznione

	bool _bot; //false - gracz ludzki, true - gracz komputerowy
	const Postac *przeciwnik; //Adres przeciwnika. Glownie uzywany przez gracza komputerowego

public:
	//Konstruktor inicjalizuje najwazniejsze zmienne oraz dodaje snake'a do zmiennej 'mapa'
	Postac( const std::string& nazwa,
			const Wspolrzedne& glowa,
			unsigned int dlugosc_ogona = 1,
			Kierunki ktory = GORA,
			GLfloat czer = 0,
			GLfloat ziel = 0,
			GLfloat nieb = 0,
			bool czyBot = false,
			const Postac* adrPrzeciwnika = NULL);

	void wykonaj_ruch(); //wykonuje ruch w aktualnym kierunku ('akt_kierunek')
	void skrec_w(Kierunki kierunek); //Wykonuje natychmiastowy skret
	void wydluz_ogon(int o_ile = 1); //Wydluza ogon o 'o_ile'

	void wyswietlPostac() const; //Rysuje Postac na ekranie

	bool czyKolizja() const { return kolizja; } //Zwraca zmienna 'kolizja'
	void dodajPrzeciwnika(const Postac *przec) { przeciwnik = przec; } //zmienia adres przeciwnika

private:
	void przesun_cialo(Kierunki kierunek); //Przesuwanie ciala (ogona) w podanym kierunku
	bool sprKolizje(const Wspolrzedne& kords) const; //Sprawdzenie czy jest kolizja na podanych wspolrzednych. false - brak kolizji, true = kolizja
	bool sprKolizje(Kierunki kierunek) const;//Sprawdzenie czy jest kolizja w konkretnym kierunku. false - brak kolizji, true = kolizja
	Kierunki wKtoraRuch() const; //Funkcja sztucznej inteligencji organizuj¹ca ruch komputera
	bool czyWolnyJakisRuch() const { return !(sprKolizje(GORA) && sprKolizje(DOL) && sprKolizje(PRAWO) && sprKolizje(LEWO)); } //Zwraca informacje o tym czy istnieje jakis wolny kierunek. True - istnieje wolny kierunek
	Kierunki podajWolnyKierunek() const { return (!sprKolizje(GORA)) ? GORA : (!sprKolizje(PRAWO)) ? PRAWO : (!sprKolizje(DOL)) ? DOL : LEWO;  }

	Kierunki wybierzKierunek(int z_kafelek, int do_kafelek) const; //Szuka najlepszego kierunku, w ktory nalezy sie poruszyc, gdy glowa przeciwnika i komputera sa w roznych kafelkach
	Kierunki wybierzKierunek(int nr_kafelka) const; //Szuka najlepszego kierunku, w ktory nalezy sie poruszyc, gdy glowa przeciwnika i komputera sa w tym samym kafelku 
	Kierunki wolnyKierunek(Kierunki glowny) const; //Funkcja pomocna dla wybierzKierunek
};
////////////////////////////////////////////////////////////
#endif