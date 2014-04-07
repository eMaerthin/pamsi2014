#ifndef FUNKCJE_HH
#define FUNKCJE_HH

#include <iostream>
#include <vector>
#include "Tablica.h"

char wpisz_ele_menu();
/////////////////////////////////////////////////////////////////////////////////////////////
//Funkcja zarzadzajaca sortowaniem przez kopcowanie
template <class TYP>
void menu_sortowanie_przez_kopcowanie(Tablica<TYP>& tablica)
{
	std::cout << "******************* Sortowanie przez kopcowanie *******************" << endl;

	switch (wpisz_ele_menu()){
		case '1': tablica.wlosuj_elementy(); 
				break;

		case '2': tablica.wczytaj_z_pliku_menu();
				break;
		case '3': return;
	}

	tablica.posortuj_przez_kopcowanie();
	tablica.wyswietl_tab();
	std::cout << "Czas wykonywania: " << tablica.czas_sort() << endl;
}
/////////////////////////////////////////////////////////////////////////////////////////////
//Funkcja zarzadzajaca sortowaniem przez scalanie
template <class TYP>
void menu_sortowanie_scalanie(Tablica<TYP>& tablica)
{
	std::cout << "******************* Sortowanie przez scalanie *******************" << endl;

	switch (wpisz_ele_menu()){
		case '1': tablica.wlosuj_elementy();
			break;

		case '2': tablica.wczytaj_z_pliku_menu();
			break;
		case '3': return;
	}

	tablica.posortuj_przez_scalanie();
	tablica.wyswietl_tab();
	std::cout << "Czas wykonywania: " << tablica.czas_sort() << endl;
}
/////////////////////////////////////////////////////////////////////////////////////////////
//Funkcja zarzadzajaca sortowaniem Shella
template <class TYP>
void menu_sortowanie_Shella(Tablica<TYP>& tablica)
{
	std::cout << "******************* Sortowanie Shella *******************" << endl;

	switch (wpisz_ele_menu()){
		case '1': tablica.wlosuj_elementy();
			break;

		case '2': tablica.wczytaj_z_pliku_menu();
			break;
		case '3': return;
	}

	tablica.posortuj_Shella();
	tablica.wyswietl_tab();
	std::cout << "Czas wykonywania: " << tablica.czas_sort() << endl;
}
/////////////////////////////////////////////////////////////////////////////////////////////
//Funkcja pozwalajaca wybrac tryb sortowania i ilosc elementow losowych do posortowania
//Wyswietla ona takze zbior przed i po losowaniu
void menu_sortowania();
/////////////////////////////////////////////////////////////////////////////////////////////
//Wykonywanie eksperymentu na zbiorach z rozkladow: jednostajnego, normlanego, Poissona, dla roznych ich dlugosci
//i sortowanie 100 roznych takich zbiorow tymi samymi metodami sortowania w celu usrednienia wyniku czasu sortowania.
void eksperyment();
/////////////////////////////////////////////////////////////////////////////////////////////
//Funkcja pomocnicza do wykonywania sortowan w eksperymecie. Sortuje 100 tablic i zwrac sredni czas sortowania przez kopcowanie
double test_efektywnosci_kopcowania(Tablica<int> wek[], int ile_ele);
//Funkcja pomocnicza do wykonywania sortowan w eksperymecie. Sortuje 100 tablic i zwrac sredni czas sortowania przez scalanie
double test_efektywnosci_scalania(Tablica<int> wek[], int ile_ele);
//Funkcja pomocnicza do wykonywania sortowan w eksperymecie. Sortuje 100 tablic i zwrac sredni czas sortowania metoda Shella
double test_efektywnosci_Shella(Tablica<int> wek[], int ile_ele);
/////////////////////////////////////////////////////////////////////////////////////////////

#endif