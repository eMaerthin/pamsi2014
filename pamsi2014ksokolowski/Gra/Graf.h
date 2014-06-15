#ifndef GRAF_HPP
#define GRAF_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <conio.h>
#include <ctime>	//srand
#include <cstdlib>	//srand
#include <math.h>
#include <iomanip>

#include "funkcje.h"

//*******************************************************************************************************
template<class TYP>
class Graf{
protected:
	//Klasa pomocnicza przechowujaca informacje o krawedziach
	struct CalePolaczenie{
		int pierwszy_wierzcholek, drugi_wierzcholek;
		TYP waga;

		CalePolaczenie(int p_wierz = 0, int d_wierz = 0, TYP wag = 0) : waga(wag), pierwszy_wierzcholek(p_wierz), drugi_wierzcholek(d_wierz) {}

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

	std::vector< std::vector<TYP> > graf_tablica;
	std::vector< std::vector<int> > drogi; //zmienna przechowujaca wierzcholki tras
	std::vector<TYP> D; //wagi tras

public:
	Graf() {}

	template<class TYP> friend class Siec;

	//Wykonanie algorytmu Bellmana-Forda
	//Argumenty: repr - Reprezentacja grafu(listowa 'L', tablicowa 'T')
	//			 start - wierzcholek startowy
	bool alg_BF(int start);
	void alg_Dijkstry(int start, int koniec = INF_);

	const std::vector<int>& podajWektorDrogi(int koniec) const { return drogi[koniec]; }

	bool spojny();

	//Wczytanie grafu z pliku o sciezce 'nazwa'
	void wczytaj_graf_z_pliku(std::string nazwa);
	//Zapisanie nakrotszych tras po wykonaniu ostatniego algorytmu do pliku o sciezce 'nazwa'
	void zapisz_trasy_do_pliku(std::string nazwa) const;

	void wyswietl_graf_tablica() const;

	void dodaj_polaczenie(int p_wierz, int d_wierz, TYP waga);
	void usun_polaczenie(int p_wierz, int d_wierz);

	void graf_ER(int N, double p, int zakres_min, int zakres_max);

	bool znajdz_wierz(int numer);

	void usun_wszystko();

	void zmien_wage(int p_wierz, int d_wierz, TYP waga) { graf_tablica[p_wierz][d_wierz] = waga; }

private:
	//Funkcja sortuje podany wektor sortowanie quicksort
	void posortuj_szybko_wektor(std::vector<CalePolaczenie>& wek) const;

	//Funkcja pomocnicza dla algorytmu BF, pobiera wszystkie krawedzie istniejace w grafie
	void wez_krawedzie(std::vector<CalePolaczenie>& kr);

	//Funkcja pomocnicza dla algorytmu BF, znajduje trase po podanej wadze od wierzcholka 'start'
	void znajdz_drogi_po_wadze(int start);
};
//*******************************************************************************************************


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
bool Graf<TYP>::alg_BF(int start)
{
	if (start >= (int)graf_tablica.size() || start < 0){
		std::cout << "\nPodano bledny wierzcholek startowy" << endl;
		return false;
	}

	std::vector<CalePolaczenie> krawedzie;

	drogi.clear(); D.clear();
	drogi.resize(graf_tablica.size()); D.resize(graf_tablica.size());

	std::size_t i, j, rozmiar = graf_tablica.size();

	for (i = 0; i < rozmiar; ++i){ //poczatkowa droga do kazdego wierzcholka z wierzcholka start jest nieznana
		D[i] = INF_;
	}
	D[start] = 0; //Droga do samego siebie jest zerowa
	drogi[start].push_back(start);

	wez_krawedzie(krawedzie);

	std::size_t kr_rozm = krawedzie.size();
	int p_wierz, k_wierz; //wierzcholki poczatkowy i koncowy drogi/sciezki
	TYP waga;

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

	return true;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
void Graf<TYP>::alg_Dijkstry(int start, int koniec)
{
	if (start >= (int)graf_tablica.size() || start < 0){
		std::cout << "\nPodano bledny wierzcholek startowy" << endl;
		return;
	}

	vector<CalePolaczenie> Q;
	size_t i, v, rozmiar = graf_tablica.size();
	vector<int> p(rozmiar);

	drogi.clear(); D.clear();
	drogi.resize(rozmiar); D.resize(rozmiar);

	for (i = 0; i < rozmiar; ++i){
		if (i == start)
			Q.push_back(CalePolaczenie(-1, i, 0));
		else
			Q.push_back(CalePolaczenie(-1, i, INF_));

		D[i] = INF_;
		p[i] = 0;
	}
	D[start] = 0;

	int u;

	while (!Q.empty()){
		posortuj_szybko_wektor(Q);
		u = Q.front().drugi_wierzcholek;

		Q.erase(Q.begin());

		for (v = 0; v < rozmiar; ++v){
			if (graf_tablica[u][v] != INF_ && graf_tablica[u][v] != 0 && (D[v] > D[u] + graf_tablica[u][v])) {
				D[v] = D[u] + graf_tablica[u][v];
				p[v] = u;
			}
		}

		for (i = 0; i < Q.size(); ++i){
			Q[i].waga = D[Q[i].drugi_wierzcholek];
		}
	}

	if (koniec == INF_)
		znajdz_drogi_po_wadze(start);
	else{
		v = koniec;
		while (v != start){
			//cout << "V = " << v << endl;
			drogi[koniec].insert(drogi[koniec].begin(), v);
			v = p[v];
		}
		drogi[koniec].insert(drogi[koniec].begin(), start);
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
void Graf<TYP>::wez_krawedzie(std::vector<CalePolaczenie>& kr)
{
	std::size_t i, j, rozmiar = graf_tablica.size();

	for (i = 0; i < rozmiar; ++i){
		for (j = 0; j < rozmiar; ++j){
			if (graf_tablica[i][j] != INF_ && graf_tablica[i][j] != 0)
				kr.push_back(CalePolaczenie(i, j, graf_tablica[i][j]));
			if (graf_tablica[j][i] != INF_ && graf_tablica[j][i] != 0)
				kr.push_back(CalePolaczenie(j, i, graf_tablica[j][i]));
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
	std::size_t rozmiar = graf_tablica.size(), i, koniec;

	for (koniec = 0; koniec < rozmiar; ++koniec){
		if (koniec == start) continue;
		v = koniec;

		while (v != start){
			poprzedniki.clear();
			for (i = 0; i < rozmiar; ++i){//znalezienie poprzednikow wierzcholka v
				if (graf_tablica[i][v] != INF_ && graf_tablica[i][v] != 0)
					poprzedniki.push_back(i);
			}

			for (i = 0; i < poprzedniki.size(); ++i){
				if (D[v] == D[poprzedniki[i]] + graf_tablica[v][poprzedniki[i]] ||
					D[v] == D[poprzedniki[i]] + graf_tablica[poprzedniki[i]][v])
				{
					u = poprzedniki[i];
				}
			}

			drogi[koniec].insert(drogi[koniec].begin(), u);
			v = u;
		}
		drogi[koniec].push_back(koniec);
	}
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
	quicksort(tab, 0, (int)wek.size() - 1);
	for (i = 0; i < wek.size(); ++i){
		wek[i] = tab[i];
	}
	delete tab;
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

	while (!plik.eof()){
		plik >> p_wierz >> d_wierz >> waga;
		dodaj_polaczenie(p_wierz, d_wierz, waga);
		dodaj_polaczenie(d_wierz, p_wierz, 0);
	}
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
void Graf<TYP>::wyswietl_graf_tablica() const
{
	if (graf_tablica.empty()){
		std::cout << "\nGraf jest pusty!" << endl;
		return;
	}

	std::cout << "   ";
	for (int i = 0; i < (int)graf_tablica.size(); ++i) std::cout << setw(5) << i << "  ";
	std::cout << endl;

	for (int i = 0; i < (int)graf_tablica.size(); ++i){
		std::cout << i << "  ";
		for (int j = 0; j < (int)graf_tablica.size(); ++j){
			std::cout << std::setw(7) << graf_tablica[i][j];
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

	graf_tablica[p_wierz][d_wierz] = waga;
	//graf_tablica[d_wierz][p_wierz] = 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
void Graf<TYP>::usun_polaczenie(int p_wierz, int d_wierz)
{
	graf_tablica[p_wierz][d_wierz] = INF_;
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
	//dodaj_wierzcholek(N); //Dodajemy N wierzcholkow do pustego grafu
	graf_tablica.resize(N);
	for (int i = 0; i < N; ++i) graf_tablica[i].resize(N);

	int rozmiar = graf_tablica.size(),
		prawdop = static_cast<int>(p * 100);

	CalePolaczenie schowek;

	for (int i = 0; i < rozmiar; ++i){
		for (int j = i + 1; j < rozmiar; ++j){
			if (rand() % 100 <= prawdop && j != i){
				graf_tablica[i][j] = rand() % (abs(zakres_min) + zakres_max) + zakres_min;
				graf_tablica[j][i] = rand() % (abs(zakres_min) + zakres_max) + zakres_min;

				if (graf_tablica[i][j] > graf_tablica[j][i]){
					graf_tablica[i][j] -= graf_tablica[j][i];
				}
				else{
					graf_tablica[j][i] -= graf_tablica[i][j];
					if (graf_tablica[j][i] == 0) graf_tablica[j][i] += 1;
				}
			}
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
void Graf<TYP>::usun_wszystko()
{
	graf_tablica.clear();
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
bool Graf<TYP>::spojny()
{
	if (graf_tablica.empty()){
		return true;
	}
	std::size_t i, rozmiar = graf_tablica.size();

	list<int> kolejka_wierzcholkow;
	vector<int> znalezione_wierzcholki;

	kolejka_wierzcholkow.push_back(0); //dodanie wierzcholka startowego

	int wierz;
	while (!kolejka_wierzcholkow.empty()){
		wierz = kolejka_wierzcholkow.front();
		kolejka_wierzcholkow.pop_front();

		for (i = 0; i < rozmiar; ++i){
			//warunek: jesli istnieje polaczenie i nie ma takiego wierzcholka w kolejce i w dodanych wierzcholkach
			if (graf_tablica[wierz][i] != INF_ && graf_tablica[wierz][i] != 0 &&
				find(kolejka_wierzcholkow.begin(), kolejka_wierzcholkow.end(), i) == kolejka_wierzcholkow.end() &&
				find(znalezione_wierzcholki.begin(), znalezione_wierzcholki.end(), i) == znalezione_wierzcholki.end())
			{
				kolejka_wierzcholkow.push_back(i);
			}
		}

		znalezione_wierzcholki.push_back(wierz);
	}

	return (rozmiar == znalezione_wierzcholki.size());
}

#endif