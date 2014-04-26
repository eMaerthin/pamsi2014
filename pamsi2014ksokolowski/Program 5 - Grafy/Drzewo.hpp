#ifndef DRZEWO_HH
#define DRZEWO_HH

#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <list>
#include <algorithm>
#include <map>

#include "Graf.hpp"

//*******************************************************************************************************
template<class TYP>
class Drzewo : public Graf<TYP>{

	struct CalePolaczenie : public Polaczenie{
		int pierwszy_wierzcholek;
	};

public:
	bool alg_Kruskala();
	void alg_Prima();

	bool czy_spojny();

private:
	bool czy_brak_krawedzi() const;
	void wez_posortowane_wagi(std::list<CalePolaczenie>& lista_wag);
	int znajdz_id(const std::vector< std::vector<int> >& las, int wierz) const;
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

	return (id_drzew.size() == 1); //jezeli jest rozmiar rozny od zera, znaczy to ze graf jest niespojny (nie zostalo jedno drzewo na koncu)
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

	while (rozmiar_koncowy != dodane_wierzcholki.size()/*wagi.size() + rozmiar_koncowy*/){

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

		wagi.sort();
		//cout << wagi.size() + rozmiar_koncowy << endl; _getch();
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
bool Drzewo<TYP>::czy_spojny()
{
	//sprawdzenie spojnosci polega na sprawdzenie co zwraca alg_Kruskala - czy zostal on poprawnie wykonany
	//tzn. finalna liczba drzew wynosi 1 (jezeli tak to alg_Kruskala zwraca true czyli graf jest spojny)
	return alg_Kruskala();
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
void Drzewo<TYP>::wez_posortowane_wagi(std::list<CalePolaczenie>& lista_wag)
{
	CalePolaczenie schowek;
	int i, j;

	//Dodanie wag i ich posortowanie rosnaco
	for (i = 0; i < (int)graf_lista.size(); ++i){
		for (j = 0; j < (int)graf_lista[i].size(); ++j){
			schowek.pierwszy_wierzcholek = i;
			schowek.drugi_wierzcholek = graf_lista[i][j].drugi_wierzcholek;
			schowek.waga = graf_lista[i][j].waga;
			lista_wag.push_back(schowek);
		}
	}
	lista_wag.sort(); //posortowanie wag w kolejnosci rosnacej
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


#endif