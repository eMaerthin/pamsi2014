#ifndef DRZEWO_HH
#define DRZEWO_HH

#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <list>
#include <algorithm>
#include <map>
#include "boost/date_time/posix_time/posix_time.hpp"

#include "Graf.hpp"

//*******************************************************************************************************
template<class TYP>
class Drzewo : public Graf<TYP>{

	boost::posix_time::time_duration czas_ostatniego;//zmienna zapamietujaca czas ostatniego wykonywania algorytmu tworzenia MST

	//Klasa pomocnicza zapamietujaca obydwa wierzcholki i wage ich polaczenia
	struct CalePolaczenie : public Polaczenie{
		int pierwszy_wierzcholek;

		CalePolaczenie() {}
		CalePolaczenie(int p_wierz, int d_wierz, TYP wag) : Polaczenie(d_wierz, wag), pierwszy_wierzcholek(p_wierz)
		{}

		bool operator==(const CalePolaczenie& arg) const {
			return ((pierwszy_wierzcholek == arg.pierwszy_wierzcholek) && (drugi_wierzcholek == arg.drugi_wierzcholek) && (waga == arg.waga));
		}
	};

public:
	Drzewo() {}

	//Funkcja podaje czas ostatniego wykonywania algorytmu
	int _czas() const
	{
		return (int)czas_ostatniego.total_milliseconds();
	}

	//Tworzenie MST algorytmem Kruskala
	//Argument: reporezentacja - wykonanie algorytmu Kruskala dla grafu z reprezentacja jako lista 'L' czy tablica 'T'
	bool alg_Kruskala(char reprezentacja = 'L');
	//Tworzenie MST algorytmem Prima z reprezentacji grafu jako tablica
	void alg_Prima();
	//Tworzenie MST algorytmem Prima z reprezentacji grafu jako lista
	void alg_Prima_lista();
	//Tworzenie MST algorytmem Boruvki
	void alg_Boruvki();

	//Sprawdzenie czy drzewo jest spojne
	bool czy_spojny();

private:
	//Wstawienie do listy 'lista_wag' wszystkich polaczen juz posortowanych od najlzejszych
	void wez_posortowane_wagi(std::list<CalePolaczenie>& lista_wag);
	void wez_posortowane_wagi_tablica(std::list<CalePolaczenie>& lista_wag);
	//Znajduje pozycje wierzcholka 'wierz'
	int znajdz_id(const std::vector< std::vector<int> >& las, int wierz) const;
};
//*******************************************************************************************************

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
bool Drzewo<TYP>::alg_Kruskala(char reprezentacja)
{
	std::list<CalePolaczenie> wagi;

	if (reprezentacja == 'L') wez_posortowane_wagi(wagi);
	else wez_posortowane_wagi_tablica(wagi);

	std::vector<int> wierzcholki(1); //poczatkowy rozmiar 1 bo na poczatku wszystkie drzewa w lesie sa 1 wierzcholkowe
	std::vector< std::vector<int> > id_drzew;

	//Przydzielamy kolejne wierzcholki drzewom z lasu (id_drzew)
	for (int i = 0; i < (int)graf_lista.size(); ++i){
		wierzcholki[0] = i;
		id_drzew.push_back(wierzcholki);
	}

	int p_wierz, d_wierz,
		p_id, d_id;

	usun_wszystko(); //usuwamy dotychczasowa zawartosc drzewa by stworzyc je na nowo jako minimalne...
	//Wlasciwy algorytm kruskala

	boost::posix_time::ptime p = boost::posix_time::microsec_clock::local_time();

	while (!wagi.empty() && id_drzew.size() != 1){
		p_wierz = wagi.front().pierwszy_wierzcholek;
		d_wierz = wagi.front().drugi_wierzcholek;
		p_id = znajdz_id(id_drzew, p_wierz);
		d_id = znajdz_id(id_drzew, d_wierz);
		if (p_id != d_id){ //jezeli drzewa sa o innych identyfikatorach to mozna je polaczyc
			this->dodaj_polaczenie(p_wierz, d_wierz, wagi.front().waga);
			id_drzew[p_id].insert(id_drzew[p_id].end(), id_drzew[d_id].begin(), id_drzew[d_id].end());
			id_drzew.erase(id_drzew.begin() + d_id);
		}
		wagi.pop_front();
		//std::cout << "!" << id_drzew.size() << " ";
	}

	boost::posix_time::ptime k = boost::posix_time::microsec_clock::local_time();

	czas_ostatniego = k - p;

	//std::cout << "!1!\n";
	return (id_drzew.size() == 1);//jezeli jest rozmiar rozny od zera, znaczy to ze graf jest niespojny (nie zostalo jedno drzewo na koncu)
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
void Drzewo<TYP>::alg_Prima()
{
	std::size_t rozmiar_koncowy = graf_lista.size(), i, j;

	std::list<int>	dodane_wierzcholki;
	std::vector< CalePolaczenie > lista_mozliwych_polaczen;
	std::vector< std::vector<TYP> > kopia_graf_tab = graf_tablica;

	usun_wszystko();
	//Dodanie wierzcholka startowego
	int wierz_startowy = 0;

	this->dodaj_wierzcholek();
	dodane_wierzcholki.push_back(wierz_startowy);

	std::list<int>::iterator iter_dodanych;

	CalePolaczenie *tab; //tablica by szybko posortowac
	std::size_t rozmiar;
	int p_wierz, d_wierz, waga;

	boost::posix_time::ptime p = boost::posix_time::microsec_clock::local_time();

	while (rozmiar_koncowy > dodane_wierzcholki.size()){
		rozmiar = kopia_graf_tab.size();
		for (iter_dodanych = dodane_wierzcholki.begin(); iter_dodanych != dodane_wierzcholki.end(); ++iter_dodanych){
			for (j = 0; j < rozmiar; ++j){
				if (kopia_graf_tab[*iter_dodanych][j] != -1)
					lista_mozliwych_polaczen.push_back( CalePolaczenie(*iter_dodanych, j, kopia_graf_tab[*iter_dodanych][j]) );
			}
		}
		//posortowanie listy_mozliwych_polaczen
		rozmiar = lista_mozliwych_polaczen.size();

		tab = new CalePolaczenie[rozmiar];
		for (i = 0; i < (int)rozmiar; ++i){
			tab[i] = lista_mozliwych_polaczen[i];
		}

		quicksort(tab, 0, rozmiar - 1);
		for (i = 0; i < (int)rozmiar; ++i){
			lista_mozliwych_polaczen[i] = tab[i];
		}
		delete[] tab;

		//wyszukanie polaczenia, ktore mozna dodac do drzewa
		for (i = 0; i < (int)lista_mozliwych_polaczen.size(); ++i){
			p_wierz = lista_mozliwych_polaczen[i].pierwszy_wierzcholek;
			d_wierz = lista_mozliwych_polaczen[i].drugi_wierzcholek;
			waga = lista_mozliwych_polaczen[i].waga;

			kopia_graf_tab[p_wierz][d_wierz] = -1;

			if (find(dodane_wierzcholki.begin(), dodane_wierzcholki.end(), d_wierz) == dodane_wierzcholki.end()){
				dodaj_polaczenie(p_wierz, d_wierz, waga);
				dodane_wierzcholki.push_back(d_wierz);
				break;
			}

		}
		lista_mozliwych_polaczen.clear();
	}

	boost::posix_time::ptime k = boost::posix_time::microsec_clock::local_time();

	czas_ostatniego = k - p;
}
////////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
void Drzewo<TYP>::alg_Prima_lista()
{
	std::size_t rozmiar_koncowy = graf_lista.size(), i, j;

	std::list<int>	dodane_wierzcholki;
	std::vector< CalePolaczenie > lista_mozliwych_polaczen;
	std::vector< std::vector<Polaczenie> > kopia_graf_lista(graf_lista);

	usun_wszystko();
	//Dodanie wierzcholka startowego
	int wierz_startowy = 0;

	this->dodaj_wierzcholek();
	dodane_wierzcholki.push_back(wierz_startowy);

	std::list<int>::iterator iter_dodanych;

	CalePolaczenie *tab; //tablica by szybko posortowac
	std::size_t rozmiar;
	int p_wierz, d_wierz, waga;
	std::vector< std::vector<CalePolaczenie> >::iterator iter;
	CalePolaczenie schowek;

	boost::posix_time::ptime p = boost::posix_time::microsec_clock::local_time();

	while (rozmiar_koncowy > dodane_wierzcholki.size()){
		for (iter_dodanych = dodane_wierzcholki.begin(); iter_dodanych != dodane_wierzcholki.end(); ++iter_dodanych){
			rozmiar = kopia_graf_lista[*iter_dodanych].size();
			for (j = 0; j < rozmiar; ++j){
				lista_mozliwych_polaczen.push_back(CalePolaczenie(*iter_dodanych, kopia_graf_lista[*iter_dodanych][j].drugi_wierzcholek, kopia_graf_lista[*iter_dodanych][j].waga));
			}
		}
		//posortowanie listy_mozliwych_polaczen
		rozmiar = lista_mozliwych_polaczen.size();

		tab = new CalePolaczenie[rozmiar];
		for (i = 0; i < (int)rozmiar; ++i){
		tab[i] = lista_mozliwych_polaczen[i];
		}

		quicksort(tab, 0, rozmiar - 1);
		for (i = 0; i < (int)rozmiar; ++i){
		lista_mozliwych_polaczen[i] = tab[i];
		}
		delete[] tab;
		//wyszukanie polaczenia, ktore mozna dodac do drzewa
		for (i = 0; i < (int)lista_mozliwych_polaczen.size(); ++i){
			p_wierz = lista_mozliwych_polaczen[i].pierwszy_wierzcholek;
			d_wierz = lista_mozliwych_polaczen[i].drugi_wierzcholek;
			waga = lista_mozliwych_polaczen[i].waga;

			for (j = 0; j < kopia_graf_lista[p_wierz].size(); ++j){
				if (kopia_graf_lista[p_wierz][j].drugi_wierzcholek == d_wierz && kopia_graf_lista[p_wierz][j].waga == waga) break;
			}
			if (j != kopia_graf_lista[p_wierz].size()){
				kopia_graf_lista[p_wierz].erase(kopia_graf_lista[p_wierz].begin() + j);
			}

			for (j = 0; j < kopia_graf_lista[d_wierz].size(); ++j){
				if (kopia_graf_lista[d_wierz][j].drugi_wierzcholek == p_wierz && kopia_graf_lista[d_wierz][j].waga == waga) break;
			}
			if (j != kopia_graf_lista[d_wierz].size()){
				kopia_graf_lista[d_wierz].erase(kopia_graf_lista[d_wierz].begin() + j);
			}

			if (find(dodane_wierzcholki.begin(), dodane_wierzcholki.end(), d_wierz) == dodane_wierzcholki.end()){
				dodaj_polaczenie(p_wierz, d_wierz, waga);
				dodane_wierzcholki.push_back(d_wierz);
				break;
			}
		}
		lista_mozliwych_polaczen.clear();
	}
	boost::posix_time::ptime k = boost::posix_time::microsec_clock::local_time();

	czas_ostatniego = k - p;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
void Drzewo<TYP>::alg_Boruvki()
{
	if (!czy_spojny()){
		std::cout << "\nNie mozna wykonac algorytmu gdyz graf nie jest spojny!" << std::endl;
		return;
	}

	std::list<CalePolaczenie> wagi;

	wez_posortowane_wagi(wagi);

	std::size_t rozmiar = graf_lista.size();
	usun_wszystko();

	std::vector< std::vector<int> > drzewa;
	std::vector<int> schowek(1);

	//zbieramy wszystkie wierzcholki
	for (std::size_t i = 0; i < rozmiar; ++i){
		schowek[0] = i;
		drzewa.push_back(schowek);
	}

	int p_id = -1, d_id = -2;
	std::size_t i, j;
	std::list<CalePolaczenie>::iterator iter;

	boost::posix_time::ptime p = boost::posix_time::microsec_clock::local_time();

	while (drzewa.size() > 1){
		for (i = 0; i < drzewa.size(); ++i){
			TYP najm_waga = (--wagi.end())->waga; //pobranie najwyzszej wagi by miec z czym porownywac

			std::size_t rozmiar = drzewa[i].size();
			std::list<CalePolaczenie>::iterator j_iter, kopia;

			iter = --wagi.end();
			for (j = 0; j < rozmiar; ++j){
				for (j_iter = wagi.begin(); j_iter != wagi.end(); ++j_iter){
					if (drzewa[i][j] == j_iter->pierwszy_wierzcholek || drzewa[i][j] == j_iter->drugi_wierzcholek){
						p_id = znajdz_id(drzewa, j_iter->pierwszy_wierzcholek);
						d_id = znajdz_id(drzewa, j_iter->drugi_wierzcholek);

						if (j_iter->waga < najm_waga && p_id != d_id){
							najm_waga = j_iter->waga;
							if (iter != (--wagi.end())){
								wagi.erase(iter);
							}
							iter = j_iter;
							break;
						}
					}
				}
			}
			p_id = znajdz_id(drzewa, iter->pierwszy_wierzcholek);
			d_id = znajdz_id(drzewa, iter->drugi_wierzcholek);

			this->dodaj_polaczenie(iter->pierwszy_wierzcholek, iter->drugi_wierzcholek, iter->waga);
			
			drzewa[p_id].insert(drzewa[p_id].end(), drzewa[d_id].begin(), drzewa[d_id].end());
			drzewa.erase(drzewa.begin() + d_id);

			wagi.erase(iter);
		}
	}

	boost::posix_time::ptime k = boost::posix_time::microsec_clock::local_time();

	czas_ostatniego = k - p;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
bool Drzewo<TYP>::czy_spojny()
{
	Drzewo<TYP> do_testu_spojnosci = *this;

	//sprawdzenie spojnosci polega na sprawdzenie co zwraca alg_Kruskala - czy zostal on poprawnie wykonany
	//tzn. finalna liczba drzew wynosi 1 (jezeli tak to alg_Kruskala zwraca true czyli graf jest spojny)
	return do_testu_spojnosci.alg_Kruskala();
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
void Drzewo<TYP>::wez_posortowane_wagi(std::list<CalePolaczenie>& lista_wag)
{
	CalePolaczenie schowek;
	std::size_t i, j;

	//Dodanie wag i ich posortowanie rosnaco
	for (i = 0; i < graf_lista.size(); ++i){
		for (j = 0; j < graf_lista[i].size(); ++j){
			if (graf_lista[i][j].drugi_wierzcholek > (int)i){
				schowek.pierwszy_wierzcholek = i;
				schowek.drugi_wierzcholek = graf_lista[i][j].drugi_wierzcholek;
				schowek.waga = graf_lista[i][j].waga;

				lista_wag.push_back(schowek);
			}
		}
	}
	CalePolaczenie *tab = new CalePolaczenie[(int)lista_wag.size()]; //stworzenie tablicy ktora przyspieszy sortowanie
	std::size_t rozmiar = lista_wag.size();

	for (i = 0; i < rozmiar; ++i){
		tab[i] = lista_wag.front();
		lista_wag.pop_front();
	}

	quicksort(tab, 0, rozmiar - 1);
	for (i = 0; i < rozmiar; ++i){
		lista_wag.push_back(tab[i]);
	}

	delete[] tab;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
void Drzewo<TYP>::wez_posortowane_wagi_tablica(std::list<CalePolaczenie>& lista_wag)
{
	CalePolaczenie schowek;
	std::size_t i, j;
	std::size_t rozmiar_tab = graf_tablica.size();
	//Dodanie wag i ich posortowanie rosnaco
	for (i = 0; i < rozmiar_tab; ++i){
		for (j = 0; j < rozmiar_tab; ++j){
			if (graf_tablica[i][j] != -1){
				schowek.pierwszy_wierzcholek = i;
				schowek.drugi_wierzcholek = j;
				schowek.waga = graf_tablica[i][j];

				lista_wag.push_back(schowek);
			}
		}
	}
	CalePolaczenie *tab = new CalePolaczenie[(int)lista_wag.size()]; //stworzenie tablicy ktora przyspieszy sortowanie
	std::size_t rozmiar = lista_wag.size();

	for (i = 0; i < rozmiar; ++i){
		tab[i] = lista_wag.front();
		lista_wag.pop_front();
	}

	quicksort(tab, 0, rozmiar - 1);
	for (i = 0; i < rozmiar; ++i){
		lista_wag.push_back(tab[i]);
	}

	delete[] tab;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
int Drzewo<TYP>::znajdz_id(const std::vector< std::vector<int> >& las, int wierz) const
{
	int j = 0;

	for (int i = 0; i < (int)las.size(); ++i){
		for (j = 0; j < (int)las[i].size(); ++j){
			if (las[i][j] == wierz) return i; //nr id w wektorze w ktorym znajduje sie element
		}
	}
	return -1; //gdy nie znaleziono
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#endif