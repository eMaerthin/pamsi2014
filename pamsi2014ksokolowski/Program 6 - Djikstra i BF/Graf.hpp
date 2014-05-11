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

#include "funkcje.hpp"

const int INF_ = (int)pow(10, 4); //dla nas wartoscia nieosiagalna bedzie liczba 11^3 (ze wzgledu na zalozenia w projekcie)

//*******************************************************************************************************
template<class TYP>
class Graf{
protected:
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
public:
	Graf() {}

	void alg_Dijkstry(int start);
	void alg_BF(int start);

	void wczytaj_graf_z_pliku(std::string nazwa);
	void zapisz_graf_do_pliku(std::string nazwa) const;

	void wyswietl_graf_lista(std::ostream& strumien = std::cout) const;
	void wyswietl_graf_tablica() const;

	void dodaj_polaczenie(int p_wierz, int d_wierz, TYP waga);
	void usun_polaczenie(int p_wierz, int d_wierz);

	int dodaj_wierzcholek(int o_ile = 1); //zwraca numer wierzcholka
	void usun_wierzcholek(unsigned int ktory_nr); //ktory = {0,...,rozmiar-1}

	void graf_ER(int N, double p);
	void graf_pelny(int N);

	bool znajdz_wierz(int numer);

	bool czy_spojny() const;

	void usun_wszystko();

private:
	void znajdz_min_trase(int start, std::vector<CalePolaczenie>& trasa);
	void najm_sasiad(int wierz, const std::vector<int>& dodane_wierz, CalePolaczenie& cp) const;
	void posortuj_szybko_wektor(std::vector<CalePolaczenie>& wek) const;
	bool spr_sasiadow(int wierz, const std::vector<int>& dodane_wierz) const;
	TYP waga_trasy(int start, int koniec, const std::vector<CalePolaczenie>& trasa, std::vector<int> &droga);

	void wez_krawedzie(std::vector<CalePolaczenie>& kr);
};
//*******************************************************************************************************

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
void Graf<TYP>::alg_Dijkstry(int start)
{
	if (!czy_spojny()){
		std::cout << "\nAlgorytm Dijkstry mozna wykonac tylko dla grafu spojnego!" << endl;
		return;
	}
	if (start >= (int)graf_lista.size() || start < 0){
		std::cout << "\nPodano bledny wierzcholek startowy" << endl;
		return;
	}

	std::vector<CalePolaczenie> najkrotsze_trasy, cala_trasa;
	std::vector< std::vector<int> > drogi(graf_lista.size());
	std::size_t i;

	znajdz_min_trase(start, cala_trasa);
	/*for (i = 0; i < cala_trasa.size(); ++i){
		std::cout << cala_trasa[i].pierwszy_wierzcholek << " " << cala_trasa[i].drugi_wierzcholek << " " << cala_trasa[i].waga << endl;
	}std::cout << endl << endl;*/
	for (i = 0; i < graf_lista.size(); ++i){//glowna petla - szukamy polaczenia start z wierzcholkiem 'i'
		if (i != start){
			najkrotsze_trasy.push_back( CalePolaczenie(start, i, waga_trasy(start, i, cala_trasa, drogi[i])) );
			drogi[i].push_back(start);
			zn = false;
		}
	}
	
	//
	//wyswietl trasy
	//
	for (i = 0; i < najkrotsze_trasy.size(); ++i){
		std::cout << endl << najkrotsze_trasy[i].pierwszy_wierzcholek << " " << najkrotsze_trasy[i].drugi_wierzcholek << " " << najkrotsze_trasy[i].waga;
		std::cout << "\t>>>>\t";
		for (int j = drogi[najkrotsze_trasy[i].drugi_wierzcholek].size() - 1; j >= 0; --j){
			std::cout << drogi[najkrotsze_trasy[i].drugi_wierzcholek][j] << "-";
		}
	}
	std::cout << endl;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
void Graf<TYP>::alg_BF(int start)
{
	std::vector< std::vector<int> > drogi(graf_lista.size());
	std::vector<TYP> D(graf_lista.size());
	std::vector<CalePolaczenie> krawedzie;

	std::size_t i, j, rozmiar = graf_lista.size();

	for (i = 0; i < graf_lista.size(); ++i){ //poczatkowa droga do kazdego wierzcholka z wierzcholka start jest nieznana
		D[i] = INF_;
	}
	D[start] = 0; //Droga do samego siebie jest zerowa

	wez_krawedzie(krawedzie);
	std::size_t kr_rozm = krawedzie.size();
	int p_wierz, k_wierz; //wierzcholki poczatkowy i koncowy drogi/sciezki
	TYP waga;

	for (i = 0; i < rozmiar; ++i){
		//std::cout << endl << endl;
		for (j = 0; j < kr_rozm; ++j){
			p_wierz = krawedzie[j].pierwszy_wierzcholek;
			k_wierz = krawedzie[j].drugi_wierzcholek;
			waga = krawedzie[j].waga;
			//std::cout << p_wierz << "!" << k_wierz << endl;
			if (D[p_wierz] + waga < D[k_wierz] && D[p_wierz] != INF_){
				D[k_wierz] = D[p_wierz] + waga;

				drogi[k_wierz].push_back(p_wierz);

				if (i + 1 == rozmiar){//wykrycie cyklu o ujemnej wadze
					std::cout << "Wykryto cykl o ujemnej wadze w grafie!" << endl;
					return;
				}
			}
		}
	}

	//wyswietlenie wag tras
	for (i = 0; i < rozmiar; ++i)
	{
		if (i != start && D[i] < INF_){
			std::cout << start << "->" << i << "\t" << D[i] << "\t>>>>>>\t";
			for (int k = 0; k < (int)drogi[i].size(); ++k){
				std::cout << drogi[i][k] << "-";
			}
		}
		std::cout << i << endl;
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
void Graf<TYP>::wez_krawedzie(std::vector<CalePolaczenie>& kr)
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
void Graf<TYP>::znajdz_min_trase(int start, std::vector<CalePolaczenie>& trasa)
{
	std::vector<int> kolejka, dodane_wierzcholki;
	std::vector<CalePolaczenie> wagi;

	dodane_wierzcholki.push_back(start);
	kolejka.push_back(start); //dodanie do kolejki wierzcholka startowego

	std::size_t i;
	CalePolaczenie schowek;

	while (dodane_wierzcholki.size() < graf_lista.size()){
		for (i = 0; i < kolejka.size(); ++i){
			najm_sasiad(kolejka[i], dodane_wierzcholki, schowek);
			wagi.push_back(schowek);
		}
		posortuj_szybko_wektor(wagi);

		trasa.push_back(wagi.front());
		dodane_wierzcholki.push_back(wagi.front().drugi_wierzcholek);

		kolejka.push_back(wagi.front().drugi_wierzcholek);

		//sprawdzenie czy sa wolni sasiedzi
		for (i = 0; i < kolejka.size(); ++i){
			if (!spr_sasiadow(kolejka[i], dodane_wierzcholki)){//gdy nie ma juz sasiada z ktorym mozna sie polaczyc
				kolejka.erase(kolejka.begin() + i); //usuwamy ten wierzcholek z kolejki
				--i;
			}
		}
		wagi.clear();
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
void Graf<TYP>::najm_sasiad(int wierz, const std::vector<int>& dodane_wierz, CalePolaczenie& cp) const
{
	CalePolaczenie min_waga(0, 0, INF_); //wstepnie jest nieskonczona waga

	std::size_t i;

	for (i = 0; i < graf_lista[wierz].size(); ++i){
		//Sprawdzenie czy wierzcholek jest lzejszy od poprzedniego
		if (graf_lista[wierz][i].waga < min_waga.waga &&
			find(dodane_wierz.begin(), dodane_wierz.end(), graf_lista[wierz][i].drugi_wierzcholek) == dodane_wierz.end())
		{
			min_waga = graf_lista[wierz][i];
			min_waga.pierwszy_wierzcholek = wierz;
		}
	}

	//return min_waga;
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
bool Graf<TYP>::spr_sasiadow(int wierz, const std::vector<int>& dodane_wierz) const
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
	}

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
	}

	wyswietl_graf_lista(plik);
	plik.close();
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
void Graf<TYP>::graf_ER(int N, double p)
{
	if (p < 0) return;
	if (p > 1) p = 1;

	srand((int)time(NULL));

	usun_wszystko(); //czyscimy graf na wszelki wypadek gdyby cos w nim bylo
	dodaj_wierzcholek(N); //Dodajemy N wierzcholkow do pustego grafu

	int rozmiar = graf_tablica.size(),
		prawdop = static_cast<int>(p * 100000);

	CalePolaczenie schowek;

	for (int i = 0; i < rozmiar; ++i){
		for (int j = i + 1; j < rozmiar; ++j){
			if (rand() % 100000 <= prawdop && j != i){
				graf_tablica[i][j] = graf_tablica[j][i] = rand() % (N * 2) + 1;

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