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

	boost::posix_time::time_duration czas_ostatniego_sortowania;

	struct CalePolaczenie : public Polaczenie{
		int pierwszy_wierzcholek;
	};

public:
	Drzewo() {}

	//bool spojnosc;
	int czas_sort() const
	{
		return (int)czas_ostatniego_sortowania.total_milliseconds();
	}

	bool alg_Kruskala();
	void alg_Prima();
	void alg_Boruvki();

	bool czy_spojny();

private:
	bool czy_brak_krawedzi() const;
	void wez_posortowane_wagi(std::list<CalePolaczenie>& lista_wag);
	int znajdz_id(const std::vector< std::vector<int> >& las, int wierz) const;
	std::size_t znajdz_najlzejsze_mozliwe(std::list<CalePolaczenie>& polaczenia, const std::vector< std::vector<int> >& elementy, int indeks_wek);
};
//*******************************************************************************************************

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
bool Drzewo<TYP>::alg_Kruskala()
{
	std::list<CalePolaczenie> wagi;

	wez_posortowane_wagi(wagi);

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

	while (!wagi.empty()){
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
	}

	boost::posix_time::ptime k = boost::posix_time::microsec_clock::local_time();

	czas_ostatniego_sortowania = k - p;

	return (id_drzew.size() == 1);//jezeli jest rozmiar rozny od zera, znaczy to ze graf jest niespojny (nie zostalo jedno drzewo na koncu)
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
void Drzewo<TYP>::alg_Prima()
{
	std::size_t rozmiar_koncowy = graf_lista.size();
	std::list<CalePolaczenie> wagi;

	wez_posortowane_wagi(wagi);

	std::list<int>	dodane_wierzcholki;
	std::vector< std::list<CalePolaczenie>::iterator > lista_mozliwych_polaczen; //do przechowywania info gdzie leza polaczenia w "wagi"

	usun_wszystko();
	//Dodanie wierzcholka startowego
	int wierz_startowy = 0;

	this->dodaj_wierzcholek();
	dodane_wierzcholki.push_back(wierz_startowy);

	std::list<CalePolaczenie>::iterator iter = wagi.begin();
	std::list<int>::iterator iter_dodanych;

	int schowek;

	boost::posix_time::ptime p = boost::posix_time::microsec_clock::local_time();

	while (rozmiar_koncowy != dodane_wierzcholki.size()/*wagi.size() + rozmiar_koncowy*/){

		//zapisujemy mozliwe polaczenia z wierzcholkami juz znajdujacymi sie w drzewie
		for (iter = wagi.begin(); iter != wagi.end(); ++iter){
			for (iter_dodanych = dodane_wierzcholki.begin(); iter_dodanych != dodane_wierzcholki.end(); ++iter_dodanych){
				if (iter->pierwszy_wierzcholek == *iter_dodanych || iter->drugi_wierzcholek == *iter_dodanych){
					if (iter->drugi_wierzcholek == *iter_dodanych){ //zamieniamy by ten wierzcholek juz znajdujacy sie w drzewie byl zawsze jako pierwszy w klasie CalePolaczenie w celu ulatwienia dalszych operacji
						schowek = iter->drugi_wierzcholek;
						iter->drugi_wierzcholek = iter->pierwszy_wierzcholek;
						iter->pierwszy_wierzcholek = schowek;
					}

					lista_mozliwych_polaczen.push_back(iter);
					break;
				}
			}
		}

		for (int i = 0; i < (int)lista_mozliwych_polaczen.size(); ++i){
			if (find(dodane_wierzcholki.begin(), dodane_wierzcholki.end(), lista_mozliwych_polaczen[i]->drugi_wierzcholek) == dodane_wierzcholki.end()){
				dodaj_polaczenie(lista_mozliwych_polaczen[i]->pierwszy_wierzcholek, lista_mozliwych_polaczen[i]->drugi_wierzcholek, lista_mozliwych_polaczen[i]->waga);
				dodane_wierzcholki.push_back(lista_mozliwych_polaczen[i]->drugi_wierzcholek);
				
				wagi.erase(lista_mozliwych_polaczen[i]);

				lista_mozliwych_polaczen.clear();
				break;
			}
		}
		//wagi.sort();
		//std::cout << dodane_wierzcholki.size() << endl;
	}

	boost::posix_time::ptime k = boost::posix_time::microsec_clock::local_time();

	czas_ostatniego_sortowania = k - p;
}
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

	std::size_t indeks_wagi;
	int p_id, d_id;
	std::list<CalePolaczenie>::iterator iter;

	boost::posix_time::ptime p = boost::posix_time::microsec_clock::local_time();

	while (drzewa.size() > 1){
		for (int i = 0; i < (int)drzewa.size(); ++i){
			indeks_wagi = znajdz_najlzejsze_mozliwe(wagi, drzewa, i);
			iter = wagi.begin();
			for (; indeks_wagi; --indeks_wagi){ ++iter; }

			p_id = znajdz_id(drzewa, iter->pierwszy_wierzcholek);
			d_id = znajdz_id(drzewa, iter->drugi_wierzcholek);

			this->dodaj_polaczenie(iter->pierwszy_wierzcholek, iter->drugi_wierzcholek, iter->waga);
			
			drzewa[p_id].insert(drzewa[p_id].end(), drzewa[d_id].begin(), drzewa[d_id].end());
			drzewa.erase(drzewa.begin() + d_id);

			wagi.erase(iter);
		}
	}

	boost::posix_time::ptime k = boost::posix_time::microsec_clock::local_time();

	czas_ostatniego_sortowania = k - p;
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
	int i, j;
	CalePolaczenie *tab = new CalePolaczenie[(int)graf_lista.size()];

	//Dodanie wag i ich posortowanie rosnaco
	for (i = 0; i < (int)graf_lista.size(); ++i){
		for (j = 0; j < (int)graf_lista[i].size(); ++j){
			schowek.pierwszy_wierzcholek = i;
			schowek.drugi_wierzcholek = graf_lista[i][j].drugi_wierzcholek;
			schowek.waga = graf_lista[i][j].waga;

			tab[i] = schowek;
		}
	}
	//sort_przez_sc(tab, tab + (int)graf_lista.size());
	quicksort(tab, 0, (int)graf_lista.size() - 1);
	for (i = 0; i < (int)graf_lista.size(); ++i){
		lista_wag.push_back(tab[i]);
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
bool Drzewo<TYP>::czy_brak_krawedzi() const
{
	int rozmiar = graf_tablica.size();
	int i, j;

	for (i = 0; i < rozmiar; ++i){
		for (j = 0; j < rozmiar; ++j){
			if (graf_tablica[i][j] != -1){
				return false;
			}
		}
	}
	return true;
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
template <class TYP>
std::size_t Drzewo<TYP>::znajdz_najlzejsze_mozliwe(std::list<CalePolaczenie>& polaczenia, const std::vector< std::vector<int> >& elementy, int indeks_wek)
{
	TYP najm_waga = (--polaczenia.end())->waga; //pobranie najwyzszej wagi by miec z czym porownywac
	std::size_t indeks = polaczenia.size() - 1;

	std::size_t rozmiar = elementy[indeks_wek].size();
	std::size_t i, j;
	std::list<CalePolaczenie>::iterator j_iter;

	for (i = 0; i < rozmiar; ++i){
		for (j_iter = polaczenia.begin(), j = 0; j_iter != polaczenia.end(); ++j_iter, ++j){
			if (elementy[indeks_wek][i] == j_iter->pierwszy_wierzcholek || elementy[indeks_wek][i] == j_iter->drugi_wierzcholek){
				if (j_iter->waga < najm_waga && znajdz_id(elementy, j_iter->pierwszy_wierzcholek) != znajdz_id(elementy, j_iter->drugi_wierzcholek)){
					najm_waga = j_iter->waga;
					indeks = j;
				}
			}
		}
	}

	return indeks;
}



#endif