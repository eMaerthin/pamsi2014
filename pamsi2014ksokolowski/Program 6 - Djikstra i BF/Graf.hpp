#ifndef GRAF_HPP
#define GRAF_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <conio.h>
#include <ctime>	//srand
#include <cstdlib>	//srand
#include <math.h>

#include "boost/date_time/posix_time/posix_time.hpp"
#include "funkcje.hpp"

const int INF_ = (int)pow(10, 4); //dla nas wartoscia nieosiagalna bedzie liczba 11^3 (ze wzgledu na zalozenia w projekcie)

//*******************************************************************************************************
template<class TYP>
class Graf{
protected:
	//Klasa pomocnicza przechowujaca informacje o krawedziach
	struct CalePolaczenie{
		int pierwszy_wierzcholek, drugi_wierzcholek;
		TYP waga;

		CalePolaczenie(int p_wierz=0, int d_wierz=0, TYP wag=0) : waga(wag), pierwszy_wierzcholek(p_wierz), drugi_wierzcholek(d_wierz) {}

		bool operator>(const CalePolaczenie& arg){
			return (this->waga > arg.waga);
		}
		bool operator<(const CalePolaczenie& arg){
			return (this->waga < arg.waga);
		}
		bool operator==(const CalePolaczenie& arg) const {
			return ((pierwszy_wierzcholek == arg.pierwszy_wierzcholek) && (drugi_wierzcholek == arg.drugi_wierzcholek) && (waga == arg.waga));
		}
	};
	std::vector< std::vector<CalePolaczenie> > graf_lista;
	std::vector< std::vector<TYP> > graf_tablica;
	bool zn; //zmienna pomocnicza do zapamietania sciezek (uzywana w funkcji waga_tras)
	int zrodlo; //wierzcholek zrodlowy, dla ktorego bedziemy szukac polaczen
	std::vector< std::vector<int> > drogi; //zmienna przechowujaca wierzcholki tras
	std::vector<TYP> D; //wagi tras

	boost::posix_time::time_duration czas_ostatniego;//zmienna zapamietujaca czas ostatniego wykonywania algorytmu tworzenia MST

public:
	Graf() : zrodlo(0) {}

	//Podaje czas ostatniego wykonanego algorytmu
	int _czas() const
	{
		return (int)czas_ostatniego.total_milliseconds();
	}

	//Wykonanie algorytmu Dijkstry
	//Argumenty: repr - Reprezentacja grafu(listowa 'L', tablicowa 'T')
	//			 start - wierzcholek startowy
	void alg_Dijkstry(char repr = 'L', int start = INF_);
	//Wykonanie algorytmu Bellmana-Forda
	//Argumenty: repr - Reprezentacja grafu(listowa 'L', tablicowa 'T')
	//			 start - wierzcholek startowy
	bool alg_BF(char repr = 'L', int start = INF_);

	//Wczytanie grafu z pliku o sciezce 'nazwa'
	void wczytaj_graf_z_pliku(std::string nazwa);
	//Zapisanie grafu do pliku o siezce 'nazwa'
	void zapisz_graf_do_pliku(std::string nazwa) const;
	//Zapisanie nakrotszych tras po wykonaniu ostatniego algorytmu do pliku o sciezce 'nazwa'
	void zapisz_trasy_do_pliku(std::string nazwa) const;

	void wyswietl_graf_lista(std::ostream& strumien = std::cout) const;
	void wyswietl_graf_tablica() const;

	void dodaj_polaczenie(int p_wierz, int d_wierz, TYP waga);
	void usun_polaczenie(int p_wierz, int d_wierz);

	int dodaj_wierzcholek(int o_ile = 1); //zwraca numer wierzcholka
	void usun_wierzcholek(unsigned int ktory_nr); //ktory = {0,...,rozmiar-1}

	void graf_ER(int N, double p, int zakres_min, int zakres_max);
	void graf_pelny(int N);

	bool znajdz_wierz(int numer);

	bool czy_spojny() const;

	void usun_wszystko();

private:
	//Funkcja pomocnicza dla algorytmu Dijkstry, ktora szuka minimalna trase w grafie dla wierzcholka 'start'
	void znajdz_min_trase(int start, std::vector<CalePolaczenie>& trasa, char repr = 'L');
	//Wyszukanie dla danego wierzcholka najblizszego sasiada - funkcja pomocnicza dla znajdz_min_trase
	void najm_sasiad_list(int wierz, const std::vector<int>& dodane_wierz, CalePolaczenie& cp) const;
	void najm_sasiad_tab(int wierz, const std::vector<int>& dodane_wierz, CalePolaczenie& cp) const;
	//Funkcja sortuje podany wektor sortowanie quicksort
	void posortuj_szybko_wektor(std::vector<CalePolaczenie>& wek) const;
	//Funkcja pomocnicza dla funkcji najm_sasiad. Daje informacje o tym czy dany wierzcholek nie zostal juz dodany do trasy
	bool spr_sasiadow_list(int wierz, const std::vector<int>& dodane_wierz) const;
	bool spr_sasiadow_tab(int wierz, const std::vector<int>& dodane_wierz) const;
	//Podaje wartosc trasy od wierzcholka 'start' do 'koniec'. Trasa zadawana jest w argumencie 'trasa'
	TYP waga_trasy(int start, int koniec, const std::vector<CalePolaczenie>& trasa, std::vector<int> &droga);

	//Funkcja pomocnicza dla algorytmu BF, pobiera wszystkie krawedzie istniejace w grafie
	void wez_krawedzie_list(std::vector<CalePolaczenie>& kr);
	void wez_krawedzie_tab(std::vector<CalePolaczenie>& kr);

	//Funkcja pomocnicza dla algorytmu BF, znajduje trase po podanej wadze od wierzcholka 'start'
	void znajdz_drogi_po_wadze(int start);
};
//*******************************************************************************************************

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
void Graf<TYP>::alg_Dijkstry(char repr, int start)
{
	if (!czy_spojny()){
		std::cout << "\nAlgorytm Dijkstry mozna wykonac tylko dla grafu spojnego!" << endl;
		return;
	}
	if (start == INF_) start = zrodlo;
	if (start >= (int)graf_lista.size() || start < 0){
		std::cout << "\nPodano bledny wierzcholek startowy" << endl;
		return;
	}

	std::vector<CalePolaczenie> najkrotsze_trasy, cala_trasa;
	std::size_t i;

	drogi.clear(); D.clear();
	drogi.resize(graf_lista.size()); D.resize(graf_lista.size());

	boost::posix_time::ptime p = boost::posix_time::microsec_clock::local_time();

	znajdz_min_trase(start, cala_trasa, repr);

	for (i = 0; i < graf_lista.size(); ++i){//glowna petla - szukamy polaczenia start z wierzcholkiem 'i'
		if (i != start){
			najkrotsze_trasy.push_back( CalePolaczenie(start, i, waga_trasy(start, i, cala_trasa, drogi[i])) );
			drogi[i].push_back(start);
			zn = false;
		}
		else {
			najkrotsze_trasy.push_back(CalePolaczenie(start, start, 0));
		}
	}

	for (i = 0; i < najkrotsze_trasy.size(); ++i){
		D[i] = najkrotsze_trasy[i].waga;
	}
	drogi[start].push_back(start);

	boost::posix_time::ptime k = boost::posix_time::microsec_clock::local_time();

	czas_ostatniego = k - p;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
bool Graf<TYP>::alg_BF(char repr, int start)
{
	if (start == INF_) start = zrodlo;
	if (start >= (int)graf_lista.size() || start < 0){
		std::cout << "\nPodano bledny wierzcholek startowy" << endl;
		return false;
	}

	std::vector<CalePolaczenie> krawedzie;

	drogi.clear(); D.clear();
	drogi.resize(graf_lista.size()); D.resize(graf_lista.size());

	std::size_t i, j, rozmiar = graf_lista.size();

	for (i = 0; i < rozmiar; ++i){ //poczatkowa droga do kazdego wierzcholka z wierzcholka start jest nieznana
		D[i] = INF_;
	}
	D[start] = 0; //Droga do samego siebie jest zerowa
	drogi[start].push_back(start);

	if( repr == 'L' ) wez_krawedzie_list(krawedzie);
	else wez_krawedzie_tab(krawedzie);

	std::size_t kr_rozm = krawedzie.size();
	int p_wierz, k_wierz; //wierzcholki poczatkowy i koncowy drogi/sciezki
	TYP waga;

	boost::posix_time::ptime p = boost::posix_time::microsec_clock::local_time();

	for (i = 0; i < rozmiar; ++i){
		for (j = 0; j < kr_rozm; ++j){
			p_wierz = krawedzie[j].pierwszy_wierzcholek;
			k_wierz = krawedzie[j].drugi_wierzcholek;
			waga = krawedzie[j].waga;

			if (D[p_wierz] + waga < D[k_wierz] && D[p_wierz] != INF_){
				D[k_wierz] = D[p_wierz] + waga;

				if (i + 1 == rozmiar){//wykrycie cyklu o ujemnej wadze
					return false;
				}
			}
		}
	}

	znajdz_drogi_po_wadze(start);

	boost::posix_time::ptime k = boost::posix_time::microsec_clock::local_time();

	czas_ostatniego = k - p;

	return true;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
void Graf<TYP>::wez_krawedzie_list(std::vector<CalePolaczenie>& kr)
{
	std::size_t i, j, rozmiar = graf_lista.size();

	for (i = 0; i < rozmiar; ++i){
		for (j = 0; j < graf_lista[i].size(); ++j){
			kr.push_back(CalePolaczenie(i, graf_lista[i][j].drugi_wierzcholek, graf_lista[i][j].waga));
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
void Graf<TYP>::wez_krawedzie_tab(std::vector<CalePolaczenie>& kr)
{
	std::size_t i, j, rozmiar = graf_tablica.size();

	for (i = 0; i < rozmiar; ++i){
		for (j = 0; j < rozmiar; ++j){
			if (graf_tablica[i][j] != INF_)
				kr.push_back(CalePolaczenie(i, j, graf_tablica[i][j]));
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
void Graf<TYP>::znajdz_drogi_po_wadze(int start)
{
	int v, u; //wierzcholki
	vector<int> poprzedniki;
	std::size_t rozmiar = graf_lista.size(), i, koniec;

	for (koniec = 0; koniec < rozmiar; ++koniec){
		if (koniec == start) continue;
		v = koniec;

		while (v != start){
			poprzedniki.clear();
			for (i = 0; i < graf_lista[v].size(); ++i){//znalezienie poprzednikow wierzcholka v
					poprzedniki.push_back(graf_lista[v][i].drugi_wierzcholek);
			}

			for (i = 0; i < poprzedniki.size(); ++i){
				if (D[v] == D[poprzedniki[i]] + graf_tablica[v][poprzedniki[i]])
					u = poprzedniki[i];
			}

			drogi[koniec].insert(drogi[koniec].begin(), u);
			v = u;
		}
		drogi[koniec].push_back(koniec);
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
void Graf<TYP>::znajdz_min_trase(int start, std::vector<CalePolaczenie>& trasa, char repr)
{
	std::vector<int> kolejka, dodane_wierzcholki;
	std::vector<CalePolaczenie> wagi;

	dodane_wierzcholki.push_back(start);
	kolejka.push_back(start); //dodanie do kolejki wierzcholka startowego

	std::size_t i;
	CalePolaczenie schowek;

	while (dodane_wierzcholki.size() < graf_lista.size()){
		for (i = 0; i < kolejka.size(); ++i){
			if( repr == 'L' ) najm_sasiad_list(kolejka[i], dodane_wierzcholki, schowek);
			else najm_sasiad_tab(kolejka[i], dodane_wierzcholki, schowek);

			wagi.push_back(schowek);
		}
		posortuj_szybko_wektor(wagi);

		trasa.push_back(wagi.front());
		dodane_wierzcholki.push_back(wagi.front().drugi_wierzcholek);

		kolejka.push_back(wagi.front().drugi_wierzcholek);

		//sprawdzenie czy sa wolni sasiedzi
		for (i = 0; i < kolejka.size(); ++i){
			if ( repr == 'L' && !spr_sasiadow_list(kolejka[i], dodane_wierzcholki) ){//gdy nie ma juz sasiada z ktorym mozna sie polaczyc
				kolejka.erase(kolejka.begin() + i); //usuwamy ten wierzcholek z kolejki
				--i;
			}
			else if( !spr_sasiadow_tab(kolejka[i], dodane_wierzcholki) ){
				kolejka.erase(kolejka.begin() + i); //usuwamy ten wierzcholek z kolejki
				--i;
			}
		}
		wagi.clear();
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
void Graf<TYP>::najm_sasiad_list(int wierz, const std::vector<int>& dodane_wierz, CalePolaczenie& cp) const
{
	CalePolaczenie min_waga(0, 0, INF_); //wstepnie jest nieskonczona waga

	std::size_t i, rozmiar = graf_lista[wierz].size();

	for (i = 0; i < rozmiar; ++i){
		//Sprawdzenie czy wierzcholek jest lzejszy od poprzedniego
		if (graf_lista[wierz][i].waga < min_waga.waga &&
			find(dodane_wierz.begin(), dodane_wierz.end(), graf_lista[wierz][i].drugi_wierzcholek) == dodane_wierz.end())
		{
			min_waga = graf_lista[wierz][i];
			min_waga.pierwszy_wierzcholek = wierz;
		}
	}

	cp = min_waga;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
void Graf<TYP>::najm_sasiad_tab(int wierz, const std::vector<int>& dodane_wierz, CalePolaczenie& cp) const
{
	CalePolaczenie min_waga(0, 0, INF_); //wstepnie jest nieskonczona waga

	std::size_t i, rozmiar = graf_tablica.size();

	for (i = 0; i < rozmiar; ++i){
		//Sprawdzenie czy wierzcholek jest lzejszy od poprzedniego
		if (graf_tablica[wierz][i] != INF_ && graf_tablica[wierz][i] < min_waga.waga &&
			find(dodane_wierz.begin(), dodane_wierz.end(), i) == dodane_wierz.end())
		{
			min_waga = CalePolaczenie(wierz, i, graf_tablica[wierz][i]);
		}
	}

	cp = min_waga;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
void Graf<TYP>::posortuj_szybko_wektor(std::vector<CalePolaczenie>& wek) const
{
	CalePolaczenie *tab = new CalePolaczenie[wek.size()];

	std::size_t i;

	for (i = 0; i < wek.size(); ++i){
		tab[i] = wek[i];
	}
	quicksort(tab, 0, (int)wek.size()-1);
	for (i = 0; i < wek.size(); ++i){
		wek[i] = tab[i];
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
bool Graf<TYP>::spr_sasiadow_list(int wierz, const std::vector<int>& dodane_wierz) const
{
	for (std::size_t i = 0; i < graf_lista[wierz].size(); ++i){
		if (find(dodane_wierz.begin(), dodane_wierz.end(), graf_lista[wierz][i].drugi_wierzcholek) == dodane_wierz.end()){
			return true;
		}
	}
	return false;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
bool Graf<TYP>::spr_sasiadow_tab(int wierz, const std::vector<int>& dodane_wierz) const
{
	std::size_t rozmiar = graf_tablica.size();
	for (std::size_t i = 0; i < rozmiar; ++i){
		if (graf_tablica[wierz][i] != INF_ &&
			find(dodane_wierz.begin(), dodane_wierz.end(), i) == dodane_wierz.end()){
			return true;
		}
	}
	return false;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
TYP Graf<TYP>::waga_trasy(int start, int koniec, const std::vector<CalePolaczenie>& trasa, std::vector<int>& droga)
{
	std::size_t i;
	TYP waga_dalszych;

	//szukanie bezposredniego polaczenia
	for (i = 0; i < trasa.size(); ++i){
		if ((trasa[i].pierwszy_wierzcholek == start && trasa[i].drugi_wierzcholek == koniec) ||
			(trasa[i].pierwszy_wierzcholek == koniec && trasa[i].drugi_wierzcholek == start))
		{
			droga.push_back(koniec);
			zn = true;
			return trasa[i].waga;
		}
	}
	
	for (i = 0; i < trasa.size(); ++i){
		if (trasa[i].pierwszy_wierzcholek == start){
			waga_dalszych = waga_trasy(trasa[i].drugi_wierzcholek, koniec, trasa, droga);
			if (waga_dalszych == 0){
				continue;
			}
			else{
				if (zn) droga.push_back(trasa[i].drugi_wierzcholek);
				return  trasa[i].waga + waga_dalszych;
			}
		}
	}
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
void Graf<TYP>::wczytaj_graf_z_pliku(std::string nazwa)
{
	std::ifstream plik(nazwa);
	int p_wierz, d_wierz; // pierwszy i drugi wierzcholek
	TYP waga;

	if (!plik.good()){
		std::cout << "\nBlad podczas proby wczytywania z pliku o nazwie " << nazwa;
		return;
	}

	//Wczytanie pierwszej linii danych zawierajacej: liczbe krawedzi, liczbe wierzcholkow, wierzcholek startowy
	plik >> p_wierz >> d_wierz >> zrodlo;

	while (!plik.eof()){
		plik >> p_wierz >> d_wierz >> waga;
		dodaj_polaczenie(p_wierz, d_wierz, waga);
	}
	plik.close();
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
void Graf<TYP>::zapisz_graf_do_pliku(std::string nazwa) const
{
	if (graf_tablica.empty()){
		std::cout << "\nGraf jest pusty!" << endl;
		return;
	}

	ofstream plik(nazwa);

	if (!plik.good()){
		std::cout << "\nBlad podczas proby zapisu do pliku o nazwie " << nazwa;
		return;
	}

	wyswietl_graf_lista(plik);
	plik.close();
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
void Graf<TYP>::zapisz_trasy_do_pliku(std::string nazwa) const
{
	if (D.empty()){
		std::cout << "\nNie ma zadnych tras w pamieci!" << endl;
		return;
	}

	ofstream plik(nazwa);
	if (!plik.good()){
		std::cout << "\nBlad podczas proby zapisu do pliku o nazwie " << nazwa;
		return;
	}

	std::size_t i, j, rozmiar = D.size();
	for (i = 0; i < rozmiar; ++i){
		plik << i << " " << D[i];

		for (j = 0; j < drogi[i].size(); ++j){
			plik << " " << drogi[i][j];
		}

		plik << endl;
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class TYP>
void Graf<TYP>::wyswietl_graf_lista(std::ostream& strumien = std::cout) const
{
	if (graf_tablica.empty()){
		std::cout << "\nGraf jest pusty!" << endl;
		return;
	}

	for (int i = 0; i < (int)graf_lista.size(); ++i){
		for (int j = 0; j < (int)graf_lista[i].size(); ++j){
			//if (graf_lista[i][j].drugi_wierzcholek > i)//by nie wyswietlac tych samych polaczen
			strumien << i << "\t" << graf_lista[i][j].drugi_wierzcholek << "\t" << graf_lista[i][j].waga << std::endl;
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class TYP>
void Graf<TYP>::wyswietl_graf_tablica() const
{
	if (graf_tablica.empty()){
		std::cout << "\nGraf jest pusty!" << endl;
		return;
	}

	for (int i = 0; i < (int)graf_tablica.size(); ++i){
		for (int j = 0; j < (int)graf_tablica.size(); ++j){
			std::cout << graf_tablica[i][j] << "  ";
		}
		std::cout << std::endl;
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
void Graf<TYP>::dodaj_polaczenie(int p_wierz, int d_wierz, TYP waga)
{
	int stary_rozmiar = graf_tablica.size(),
		nowy_rozmiar = 0;
	CalePolaczenie schowek;
	if (stary_rozmiar <= p_wierz || stary_rozmiar <= d_wierz){
		if (p_wierz > d_wierz){
			nowy_rozmiar = p_wierz + 1;
		}
		else{
			nowy_rozmiar = d_wierz + 1;
		}
		graf_lista.resize(nowy_rozmiar);
		graf_tablica.resize(nowy_rozmiar);
		for (int i = 0; i < nowy_rozmiar; ++i){
			graf_tablica[i].resize(nowy_rozmiar);
		}
		for (int i = 0; i < nowy_rozmiar; ++i){
			for (int j = 0; j < nowy_rozmiar; ++j){
				if ((i < stary_rozmiar && j >= stary_rozmiar) || (i >= stary_rozmiar))
					graf_tablica[i][j] = INF_;
			}
		}
	}

	graf_tablica[p_wierz][d_wierz] = graf_tablica[d_wierz][p_wierz] = waga;

	schowek.drugi_wierzcholek = d_wierz;
	schowek.waga = waga;

	std::vector<CalePolaczenie>::iterator iter = graf_lista[p_wierz].begin();
	if (!graf_lista[p_wierz].empty()){
		int i = 0;

		//Przemieszczamy sie po wektorze az nie znajdziemy odpowiedniego miejsca na wstawienie
		while ((i < (int)graf_lista[p_wierz].size() - 1 && iter->drugi_wierzcholek < d_wierz)){
			++iter; ++i;
		}
		++iter;
	}
	graf_lista[p_wierz].insert(iter, schowek);

	iter = graf_lista[d_wierz].begin();
	if (!graf_lista[d_wierz].empty()){
		int i = 0;

		//Przemieszczamy sie po wektorze az nie znajdziemy odpowiedniego miejsca na wstawienie
		while ((i < (int)graf_lista[d_wierz].size() - 1 && iter->drugi_wierzcholek < p_wierz)){
			++iter; ++i;
		}
		++iter;
	}
	schowek.drugi_wierzcholek = p_wierz;
	graf_lista[d_wierz].insert(iter, schowek);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
void Graf<TYP>::usun_polaczenie(int p_wierz, int d_wierz)
{
	graf_tablica[p_wierz][d_wierz] = graf_tablica[d_wierz][p_wierz] = INF_;

	std::vector< CalePolaczenie >::iterator iter = graf_lista[p_wierz].begin();

	while (iter->drugi_wierzcholek != d_wierz){
		++iter;
	}
	graf_lista[p_wierz].erase(iter);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
int Graf<TYP>::dodaj_wierzcholek(int o_ile)
{
	int stary_rozmiar = graf_lista.size(),
		nowy_rozmiar = graf_lista.size() + o_ile;

	graf_lista.resize(nowy_rozmiar);
	graf_tablica.resize(nowy_rozmiar);
	for (int i = 0; i < nowy_rozmiar; ++i){
		graf_tablica[i].resize(nowy_rozmiar);
	}

	for (int i = 0; i < nowy_rozmiar; ++i){
		for (int j = 0; j < nowy_rozmiar; ++j){
			if ((i < stary_rozmiar && j >= stary_rozmiar) || (i >= stary_rozmiar))
				graf_tablica[i][j] = INF_;
		}
	}
	return nowy_rozmiar - 1; //Oddajemy rozmiar - 1 dlatego ze liczymy od 0
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
void Graf<TYP>::usun_wierzcholek(unsigned int ktory_nr)
{
	if (ktory_nr >= graf_lista.size()){
		std::cout << "\nNie ma takiego wierzcholka!";
	}

	graf_lista.erase(graf_lista.begin() + ktory_nr);
	graf_tablica.erase(graf_tablica.begin() + ktory_nr);
	for (int i = 0; i < graf_lista.size(); ++i){
		graf_tablica[i].erase(graf_tablica[i].begin() + ktory_nr);
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
void Graf<TYP>::graf_ER(int N, double p, int zakres_min, int zakres_max)
{
	if (p < 0) return;
	if (p > 1) p = 1;

	srand((int)time(NULL));

	usun_wszystko(); //czyscimy graf na wszelki wypadek gdyby cos w nim bylo
	dodaj_wierzcholek(N); //Dodajemy N wierzcholkow do pustego grafu

	int rozmiar = graf_tablica.size(),
		prawdop = static_cast<int>(p * 100);

	CalePolaczenie schowek;

	for (int i = 0; i < rozmiar; ++i){
		for (int j = i + 1; j < rozmiar; ++j){
			if (rand() % 100 <= prawdop && j != i){
				graf_tablica[i][j] = graf_tablica[j][i] = rand() % (abs(zakres_min)+zakres_max) + zakres_min;

				schowek.drugi_wierzcholek = j;
				schowek.waga = graf_tablica[i][j];
				graf_lista[i].push_back(schowek);

				schowek.drugi_wierzcholek = i;
				graf_lista[j].push_back(schowek);
			}
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
void Graf<TYP>::graf_pelny(int N)
{
	srand((int)time(NULL));

	usun_wszystko(); //czyscimy graf na wszelki wypadek gdyby cos w nim bylo
	dodaj_wierzcholek(N); //Dodajemy N wierzcholkow do pustego grafu

	int rozmiar = graf_tablica.size();
	CalePolaczenie schowek;

	for (int i = 0; i < rozmiar; ++i){
		for (int j = i + 1; j < rozmiar; ++j){
			graf_tablica[i][j] = graf_tablica[j][i] = rand() % (N * 2) + 1;

			schowek.drugi_wierzcholek = j;
			schowek.waga = graf_tablica[i][j];
			graf_lista[i].push_back(schowek);

			schowek.drugi_wierzcholek = i;
			graf_lista[j].push_back(schowek);
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
void Graf<TYP>::usun_wszystko()
{
	graf_lista.clear();
	graf_tablica.clear();
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
bool Graf<TYP>::czy_spojny() const
{
	if (graf_lista.size() <= 1){ //gdy graf zawiera 0 lub 1 wierzcholek to spojny
		return true;
	}
	//By sprawdzic spojnosc sprawdzamy czy z pierwszego wierzcholka da sie dojsc do innych wierzcholkow

	std::size_t rozmiar = graf_lista.size();
	std::size_t i;

	for (i = 1; i < rozmiar; ++i){ //szukanie polaczen z kolejnymi wierzcholkami

	}


	return true;
}


#endif