#ifndef SIEC_HPP
#define SIEC_HPP

#include <iostream>
#include "boost/date_time/posix_time/posix_time.hpp"

#include "Graf.hpp"

//Klasa reprezentujaca siec
//*******************************************************************************************************
template <class TYP>
class Siec{
	int zrodlo, ujscie; //zmienne zapamietujace zrodlo oraz ujscie w sieci
	Graf<TYP> przeplyw; //Graf ktory reprezentuje siec

	boost::posix_time::time_duration czas_ostatniego; //Czas ostatniego wyliczonego czasu wykonywania alg. E-K
public:
	Siec() : zrodlo(0), ujscie(0) {}

	//Algorytm Edmondsa-Karpa dla sieci
	void alg_Edmondsa_Karpa();
	//Funkcja wczytujaca siec o sciezce 'nazwa'. Wyglad takiego pliku okreslony jest w opisie do projektu.
	void wczytaj_siec(const std::string& nazwa);

	//Podanie ostatniego zmierzonego czasu
	int _czas() const
	{
		return (int)czas_ostatniego.total_milliseconds();
	}

private:
	//Odswiezenie przeplywu oraz wygladu sieci rezydualnej
	void zaktualizuj_przeplyw(const Graf<TYP>& c, Graf<TYP>& f, Graf<TYP>& resid);
	//Funkcja szuka najkrotsza sciezke od 'zrodla' do 'ujscia' w sieci rezydualnej
	std::vector<int> znajdz_sciezke(Graf<TYP>& resid, int s, int t);
	//Podanie minimalnej pojemnosci w znalezionej sciezce
	TYP min_pojemnosc(Graf<TYP>& resid, const std::vector<int>& sciezka);
	//Zwiekszenie przeplywu w grafie/sieci o 'o_ile' w sciezne podanej przez 'sciezka'
	void zwieksz_przeplyw(Graf<TYP>& graf, TYP o_ile, const std::vector<int>& sciezka);
};
//*******************************************************************************************************

template <class TYP>
void Siec<TYP>::alg_Edmondsa_Karpa()
{
	std::vector<int> sciezka; //sciezka - do zapamietania sciezki w sieci res
	Graf<TYP> przeplyw_akt; //Przeplyw aktualny w sieci
	Graf<TYP> przeplyw_max = przeplyw //Przeplyw maksymalny w sieci
	std::size_t i, j; //zmienne uzywane w petlach
	
	//Sprawdzenie czy poprawnie zostaly podane wierzcholki: 'zrodlo' i 'ujscie'
	if (zrodlo >= (int)przeplyw_max.graf_tablica.size() || ujscie >= (int)przeplyw_max.graf_tablica.size() || zrodlo == ujscie){
		std::cout << "\nBledne podane zrodlo lub ujscie!!!" << endl;
		return;
	}

	przeplyw_akt = przeplyw_max; //przeplyw aktualny ma takie same wierzcholki i polaczenia jak maksymalny tylko poczatkowo 0 wagi

	//uaktualniamy zerowe przeplywy w 'przeplyw_akt'
	for (i = 0; i < przeplyw_akt.graf_tablica.size(); ++i){
		for (j = 0; j < przeplyw_akt.graf_tablica[i].size(); ++j){
			if(przeplyw_akt.graf_tablica[i][j] != INF_) przeplyw_akt.graf_tablica[i][j] = 0;
		}
	}

	Graf<TYP> siec_res; //Siec rezydualna

	zaktualizuj_przeplyw(przeplyw_max, przeplyw_akt, siec_res); //uzupelnienie sieci rezydualnej

	boost::posix_time::ptime pocz = boost::posix_time::microsec_clock::local_time();

	while (true) {//wyjdziemy z petli gdy nie zostanie znaleziona zadna sciezka z zrodla do ujscia
		sciezka.clear();
		sciezka = znajdz_sciezke(siec_res, zrodlo, ujscie); //szukanie najkrotszej sciezki w sieci od zrodla do ujscia

		if (sciezka.empty()){ //gdy sciezka nie istnieje to znaczy konczymy algorytm
			break;
		}

		zwieksz_przeplyw(przeplyw_akt, min_pojemnosc(siec_res, sciezka), sciezka); 
	
		zaktualizuj_przeplyw(przeplyw_max, przeplyw_akt, siec_res); 
	}

	boost::posix_time::ptime kon = boost::posix_time::microsec_clock::local_time();
	
	//Znalezienie maksymalnego preplywu po wykonaniu algorytmu
	TYP max_przeplyw = 0;
	for (std::size_t i = 0; i < przeplyw_akt.graf_tablica.size(); ++i){
		if (przeplyw_akt.graf_tablica[zrodlo][i] != INF_)
			max_przeplyw += przeplyw_akt.graf_tablica[zrodlo][i];
	}

	czas_ostatniego = kon - pocz;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
void Siec<TYP>::zaktualizuj_przeplyw(const Graf<TYP>& c, Graf<TYP>& f, Graf<TYP>& resid)
{
	std::size_t i, j, rozmiar = f.graf_tablica.size(), k=0;
	TYP roznica;

	resid.graf_tablica.clear();
	for (i = 0; i < rozmiar; ++i){
		for (j = 0; j < rozmiar; ++j){
			roznica = c.graf_tablica[i][j] - f.graf_tablica[i][j];

			if (roznica > 0){
				resid.dodaj_polaczenie(i, j, roznica);
			}
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
std::vector<int> Siec<TYP>::znajdz_sciezke(Graf<TYP>& resid, int s, int t)
{
	resid.alg_Dijkstry(s);

	if (resid.D[t] == INF_) resid.drogi[t].clear();

	return resid.drogi[t];
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
TYP Siec<TYP>::min_pojemnosc(Graf<TYP>& resid, const std::vector<int>& sciezka)
{
	std::vector<TYP> przeplywy;
	std::size_t i, rozmiar = sciezka.size();

	for (i = 0; i < rozmiar-1; ++i){
		if (resid.graf_tablica[sciezka[i]][sciezka[i + 1]] != 0)
			przeplywy.push_back(resid.graf_tablica[sciezka[i]][sciezka[i + 1]]);
	}

	posortuj_szybko_wektor(przeplywy);

	return przeplywy.front();
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
void Siec<TYP>::zwieksz_przeplyw(Graf<TYP>& graf, TYP o_ile, const std::vector<int>& sciezka)
{
	std::size_t i, rozmiar = sciezka.size();

	for (i = 0; i < rozmiar - 1; ++i){
		graf.graf_tablica[sciezka[i]][sciezka[i + 1]] += o_ile;
		graf.graf_tablica[sciezka[i + 1]][sciezka[i]] -= o_ile;
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
void Siec<TYP>::wczytaj_siec(const std::string& nazwa)
{
	ifstream plik(nazwa);

	if (!plik.good()){
		std::cout << "Blad podczas proby otwarcia pliku o sciezce " << nazwa;
		return;
	}
	przeplyw.usun_wszystko();

	int p_wierz, d_wierz;
	TYP waga;

	plik >> p_wierz >> p_wierz; //Wczytanie i zignorowanie liczby wierzcholkow i liczby krawedzi (klasa sama sie rozszerza)
	plik >> zrodlo >> ujscie;
	while (!plik.eof()){
		plik >> p_wierz >> d_wierz >> waga;
		przeplyw.dodaj_polaczenie(p_wierz, d_wierz, waga);
		przeplyw.dodaj_polaczenie(d_wierz, p_wierz, 0);
	}

	plik.close();
}

#endif