#ifndef GRAF_HPP
#define GRAF_HPP


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <conio.h>
#include <ctime>	//srand
#include <cstdlib>	//srand

#include "funkcje.hpp"

//*******************************************************************************************************
template<class TYP>
class Graf{
protected:
	struct Polaczenie{
		int drugi_wierzcholek;
		TYP waga;

		bool operator>(const Polaczenie& arg){
			return (this->waga > arg.waga);
		}
		bool operator<(const Polaczenie& arg){
			return (this->waga < arg.waga);
		}
	};
	std::vector< std::vector<Polaczenie> > graf_lista;
	std::vector< std::vector<TYP> > graf_tablica;

public:
	Graf() {}


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

	void usun_wszystko();
};
//*******************************************************************************************************


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

	for (int i = 0; i < (int)graf_lista.size(); ++i){
		for (int j = 0; j < (int)graf_lista[i].size(); ++j){
			graf_tablica[i][graf_lista[i][j].drugi_wierzcholek] = graf_lista[i][j].waga;
			graf_tablica[graf_lista[i][j].drugi_wierzcholek][i] = graf_lista[i][j].waga;
		}
	}
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
		nowy_rozmiar=0;
	Polaczenie schowek;
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
					graf_tablica[i][j] = -1;
			}
		}
	}

	graf_tablica[p_wierz][d_wierz] = graf_tablica[d_wierz][p_wierz] = waga;

	schowek.drugi_wierzcholek = d_wierz;
	schowek.waga = waga;

	std::vector<Polaczenie>::iterator iter = graf_lista[p_wierz].begin();
	if (!graf_lista[p_wierz].empty()){
		int i = 0;

		//Przemieszczamy sie po wektorze az nie znajdziemy odpowiedniego miejsca na wstawienie
		while ((i < (int)graf_lista[p_wierz].size() - 1 && iter->drugi_wierzcholek < d_wierz)){
			++iter; ++i;
		}
		++iter;
	}
	graf_lista[p_wierz].insert(iter, schowek);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
void Graf<TYP>::usun_polaczenie(int p_wierz, int d_wierz)
{
	graf_tablica[p_wierz][d_wierz] = graf_tablica[d_wierz][p_wierz] = -1;

	std::vector< Polaczenie >::iterator iter = graf_lista[p_wierz].begin();

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
				graf_tablica[i][j] = -1;
		}
	}
	return nowy_rozmiar-1; //Oddajemy rozmiar - 1 dlatego ze liczymy od 0
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
	if (p < 0 || p > 1){
		std::cout << "\nPrawdopodobienstwo p musi znajdowac sie w przedziale <0,1>!" << std::endl;
	}

	srand((int)time(NULL));

	usun_wszystko(); //czyscimy graf na wszelki wypadek gdyby cos w nim bylo
	dodaj_wierzcholek(N); //Dodajemy N wierzcholkow do pustego grafu

	int rozmiar = graf_tablica.size(),
		prawdop = static_cast<int>(p * 100);

	Polaczenie schowek;

	for (int i = 0; i < rozmiar; ++i){
		for (int j = i+1; j < rozmiar; ++j){
			if (rand() % 100 <= prawdop && j != i){
				graf_tablica[i][j] = graf_tablica[j][i] = rand() % (N * N/2) + 1;
				schowek.drugi_wierzcholek = j;
				schowek.waga = graf_tablica[i][j];

				graf_lista[i].push_back(schowek);
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
	Polaczenie schowek;

	for (int i = 0; i < rozmiar; ++i){
		for (int j = i + 1; j < rozmiar; ++j){
			graf_tablica[i][j] = graf_tablica[j][i] = rand() % (N * N/2) + 1;

			schowek.drugi_wierzcholek = j;
			schowek.waga = graf_tablica[i][j];

			graf_lista[i].push_back(schowek);
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


#endif