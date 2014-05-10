#include <iostream>
#include <stdio.h>
#include "Drzewo.hpp"
#include "Graf.hpp"
#include "funkcje.hpp"
#include <fstream>

using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////
//Wykonywanie algorytmu Kruskala, Prima, Boruvki 'l_elementow' razy pobranie czasu
//kazdorazowego wykonania algorytmu.
//Argumenty: tab[] - tablica na drzewa na ktorych ma byc wykonany algorytm
//			 funkcja - znak odpowiadajacy interesujacego nas algorytmu: K, P, B
//			 l_elementow - rozmiar tablicy tab
//Zwraca: sredni czas wykonania algorytmu na 'l_elementow' elementach
template <class TYP>
double pobierz_sredni_czas(Drzewo<TYP> tab[], const char funkcja, const int l_elementow = 100)
{
	int suma_czasow = 0;
	int ile = l_elementow;

	while (ile--){
		std::cout << ile << funkcja <<" ";
		switch (funkcja){
			case 'K': {  tab[ile].alg_Kruskala('T');
					break;	 }
			case 'P' : { tab[ile].alg_Prima_lista();
					break; }
			case 'B' : { tab[ile].alg_Boruvki();
					break; }
		}
		suma_czasow += tab[ile]._czas();
	}
	return (suma_czasow / l_elementow);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Eksperyment majacy na celu zebraniu srednich czasow wykonan dla algorytmow tworzacych MST
//z grafow o roznej gestosci. Eksperyment wykonywany jest dla roznej liczby wierzcholkow, a
//jego wyniki sa zapisywane do pliku
void eksperyment()
{
	ofstream plik("eksperyment.txt");

	const int l_elementow = 100;
	int liczba_wierz[] = { 500, 1000, 2000, 4000 };
	Drzewo<int> tablica[l_elementow];

	plik << "Typ wygen Grafu\t Liczba ele\t Kruskala\t Prima\t Boruvki\n";

	int i, j;
	
	//eksperyment dla grafu ER z prawdopodobienstwem z log...
	for (i = 0; i < 4; ++i){
		for (j = 0; j < l_elementow; ++j){
			std::cout << " Glog" << j;
			tablica[j].usun_wszystko();
			tablica[j].graf_ER(liczba_wierz[i], wylosuj_prawdop_log2(liczba_wierz[i]));
			if (!tablica[j].czy_spojny()){
				j--;
				continue;
			}
		}
		plik << "Graf ER log2\t";
		plik << liczba_wierz[i] << "\t" << pobierz_sredni_czas(tablica, 'K', l_elementow)
								<< "\t" << pobierz_sredni_czas(tablica, 'P', l_elementow)
								<< "\t" << pobierz_sredni_czas(tablica, 'B', l_elementow) << endl;
	}
	//eksperyment dla grafu ER z prawdopodobienstwem z n^(-1/2)
	for (i = 0; i < 4; ++i){
		for (j = 0; j < l_elementow; ++j){
			std::cout << " G2m" << j;
			tablica[j].usun_wszystko();
			tablica[j].graf_ER(liczba_wierz[i], wylosuj_prawdop_min2(liczba_wierz[i]));
			if (!tablica[j].czy_spojny()){
				j--;
				continue;
			}
		}
		plik << "Graf ER min2\t";
		plik << liczba_wierz[i] << "\t" << pobierz_sredni_czas(tablica, 'K', l_elementow)
								<< "\t" << pobierz_sredni_czas(tablica, 'P', l_elementow)
								<< "\t" << pobierz_sredni_czas(tablica, 'B', l_elementow) << endl;
	}
	//eksperyment dla grafu ER z prawdopodobienstwem z n^(-1/3)
	for (i = 0; i < 4; ++i){
		for (j = 0; j < l_elementow; ++j){
			std::cout << " G3m" << j;
			tablica[j].usun_wszystko();
			tablica[j].graf_ER(liczba_wierz[i], wylosuj_prawdop_min3(liczba_wierz[i]));
			if (!tablica[j].czy_spojny()){
				j--;
				continue;
			}
		}
		plik << "Graf ER min3\t";
		plik << liczba_wierz[i] << "\t" << pobierz_sredni_czas(tablica, 'K', l_elementow)
										<< "\t" << pobierz_sredni_czas(tablica, 'P', l_elementow)
										<< "\t" << pobierz_sredni_czas(tablica, 'B', l_elementow) << endl;
	}
	//eksperyment dla grafu pelnego
	for (i = 0; i < 4; ++i){
		for (j = 0; j < l_elementow; ++j){
			tablica[j].usun_wszystko();
			tablica[j].graf_pelny(liczba_wierz[i]);
			std::cout << " Gp" << j;
		}
		plik << "Graf Pelny\t";
		plik << liczba_wierz[i] << "\t" << pobierz_sredni_czas(tablica, 'K', l_elementow)
								<< "\t" << pobierz_sredni_czas(tablica, 'P', l_elementow)
								<< "\t" << pobierz_sredni_czas(tablica, 'B', l_elementow) << endl;
	}
	plik.close();
}
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	menu();

	return 0;
}