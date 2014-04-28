#include <iostream>
#include <stdio.h>
#include "Drzewo.hpp"
#include "Graf.hpp"
#include "funkcje.hpp"
#include <fstream>

using namespace std;


template <class TYP>
double pobierz_sredni_czas(Drzewo<TYP> tab[], const char funkcja, const int l_elementow = 100)
{
	int suma_czasow = 0;
	int ile = l_elementow;

	while (ile--){
		std::cout << ile << " ";
		switch (funkcja){
		case 'K' : { tab[ile].alg_Kruskala();
				break; }
		case 'P' : { tab[ile].alg_Prima();
				break; }
		case 'B' : { tab[ile].alg_Boruvki();
				break; }
		}
		suma_czasow += tab[ile].czas_sort();
	}

	return (suma_czasow / l_elementow);
}

void eksperyment()
{
	ofstream plik("eksperyment.txt");

	const int l_elementow = 20;
	int liczba_wierz[] = { 500, 1000, 5000, 10000 };
	Drzewo<int> tablica[l_elementow];

	plik << "Typ wygen Grafu\t Liczba ele\t Kruskala\t Prima\t Boruvki\n";

	int i, j;
	
	for (i = 0; i < 1; ++i){
		for (j = 0; j < l_elementow; ++j){
			tablica[j].usun_wszystko();
			tablica[j].graf_pelny(liczba_wierz[i]);
			std::cout << " G"<< j;
		}
		plik << "Graf Pelny\t";
		plik << liczba_wierz[i] << "\t" << pobierz_sredni_czas(tablica, 'K', l_elementow)
								<< "\t" << pobierz_sredni_czas(tablica, 'P', l_elementow)
								<< "\t" << pobierz_sredni_czas(tablica, 'B', l_elementow) << endl;
	}
	for (i = 0; i < 1; ++i){
		for (j = 0; j < l_elementow; ++j){
			std::cout << " G" << j;
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
	for (i = 0; i < 1; ++i){
		for (j = 0; j < l_elementow; ++j){
			std::cout << " G" << j;
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
	for (i = 0; i < 1; ++i){
		for (j = 0; j < l_elementow; ++j){
			std::cout << " G" << j;
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
	plik.close();
}


int main()
{
	cout << wylosuj_prawdop_log2(5000) << endl;
	//eksperyment();
	//Drzewo<int> moje, nowy;

	//moje.wczytaj_graf_z_pliku("graf10.txt");
	/*
	moje.graf_ER(10, 0.7);
	cout << "Wczytalem" << moje.czy_spojny() << endl;
	nowy = moje;

	nowy.alg_Prima();

	nowy.wyswietl_graf_lista();

	cout << endl << endl;
	nowy = moje;
	nowy.alg_Kruskala();

	nowy.wyswietl_graf_lista();*/

	//moje.wyswietl_graf_tablica();

	//cout << endl << endl << moje.czas_sort() << endl << endl;

	/*moje.alg_Kruskala();


	moje.wyswietl_graf_lista();

	cout << endl << endl;

	moje.wyswietl_graf_tablica();

	cout << endl << endl << endl << endl;


	moje.alg_Prima();


	moje.wyswietl_graf_lista();

	cout << endl << endl;

	moje.wyswietl_graf_tablica();

	cout << endl << endl;*/
	//moje.zapisz_graf_do_pliku("nowy_graf.txt");


	system("PAUSE");
	return 0;
}