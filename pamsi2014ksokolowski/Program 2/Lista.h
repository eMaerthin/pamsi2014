#ifndef LISTA_H
#define LISTA_H

//Szablon klasy Lista (lista dwukierunkowa) oraz definicje jej metod.

#include <iostream>

//Klasa Lista (lista dwukierunkowa)
//Pozwala na dodawanie/usuwanie elementow zarowno na jej poczatku jak i koncu oraz
//wyswietla wszystkie elementy tej klasy podajac przy tym jej aktualny rozmiar.
//*********************************************************************************
template <class TYP>
class Lista{
	//Aktualny rozmiar(liczba elementow) listy
	int rozmiar;

	//Klasa przechowujaca adresy jej sasiednich elementow oraz swoja wartosc
	//******************************************************************
	struct Element{
		TYP wartosc; //Wartosc elementu listy
		Element *poprzedni; //Wskaznik na poprzedni element listy
		Element *nastepny; //Wskaznik na nastepny element listy

		Element(Element *adres_p = NULL, Element *adres_n = NULL) : poprzedni(adres_p), nastepny(adres_n) {}
		Element(Element *adres_p, Element *adres_n, TYP wart) : poprzedni(adres_p), nastepny(adres_n), wartosc(wart) {}
	};//****************************************************************

	Element *aktualny; //Wskaznik na aktualnie pokazywany element listy
	Element *pierwszy, *ostatni; //Wskazniki na pierwszy i ostatni element listy

public:
	Lista<TYP>() : aktualny(NULL), pierwszy(NULL), ostatni(NULL), rozmiar(0) {}
	~Lista<TYP>()
	{
		while (aktualny != NULL){
			usun_ostatni();
		}
	}

	//Dodawanie elementu okreslonego przez argument 'nowy' na poczatek listy
	Lista<TYP>& dodaj_na_poczatek(const TYP& nowy);
	//Dodawanie elementu okreslonego przez argument 'nowy' na koniec listy
	Lista<TYP>& dodaj_na_koniec(const TYP& nowy);

	//Usuwanie elementu z poczatku listy
	Lista<TYP>& usun_pierwszy();
	//Usuwanie elementu z konca listy
	Lista<TYP>& usun_ostatni();

	//Wyswietlanie calej zawartosci listy wraz z informacja o jej romiarze (liczbie elementow)
	Lista<TYP>& wyswietl();

	//Podaje element na okreslonej pozycji przez argument 'poz'. Odliczanie zaczyna sie od 0
	TYP& daj_element(int poz);

};//*********************************************************************************

////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
Lista<TYP>& Lista<TYP>::dodaj_na_poczatek(const TYP& nowy)
{
	if (aktualny == NULL){
		aktualny = new Element(NULL, NULL, nowy);
		pierwszy = ostatni = aktualny;
	}
	else{
		pierwszy->poprzedni = new Element(NULL, pierwszy, nowy);
		pierwszy = pierwszy->poprzedni;
		aktualny = pierwszy;
	}

	++rozmiar;

	return *this;
}
////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
Lista<TYP>& Lista<TYP>::dodaj_na_koniec(const TYP& nowy)
{
	if (aktualny == NULL){
		aktualny = new Element(NULL, NULL, nowy);
		pierwszy = ostatni = aktualny;
	}
	else{
		ostatni->nastepny = new Element(ostatni, NULL, nowy);
		ostatni = ostatni->nastepny;
		aktualny = ostatni;
	}

	++rozmiar;

	return *this;
}
////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
Lista<TYP>& Lista<TYP>::usun_pierwszy()
{
	if (rozmiar == 0){
		std::cout << "\nLista jest pusta!" << endl;
		return *this;
	}
	if (rozmiar == 1){
		delete pierwszy;
		pierwszy = ostatni = aktualny = NULL;
	}
	else{
		Element *schowek = pierwszy;

		(pierwszy->nastepny)->poprzedni = NULL;
		pierwszy = aktualny = pierwszy->nastepny;
		delete schowek;
	}

	--rozmiar;
	return *this;
}
////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
Lista<TYP>& Lista<TYP>::usun_ostatni()
	{
	if (rozmiar == 0){
		std::cout << "\nLista jest pusta!" << endl;
		return *this;
	}
	if (rozmiar == 1){
		delete ostatni;
		pierwszy = ostatni = aktualny = NULL;
	}
	else{
		Element *schowek = ostatni;

		(ostatni->poprzedni)->nastepny = NULL;
		ostatni = aktualny = ostatni->nastepny;
		delete schowek;
	}

	--rozmiar;
	return *this;
}
////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
Lista<TYP>& Lista<TYP>::wyswietl()
{
	if (rozmiar == 0){
		std::cout << "\nLista jest pusta!" << endl;
		return *this;
	}

	std::cout << "Wyswietlanie Listy o rozmiarze: " << rozmiar << endl;
	aktualny = pierwszy;

	while (aktualny != NULL){
		std::cout << aktualny->wartosc << " ";
		aktualny = aktualny->nastepny;
	}

	return *this;
}
////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
TYP& Lista<TYP>::daj_element(int poz) throw(char)
{
	if (poz > rozmiar - 1 || poz < 0){
		std::cout << "\nBledna pozycja na liscie!\n";
		throw '!';
	}

	akutalny = pierwszy;
	while (poz--){
		aktualny = aktualny->nastepny;
	}

	return aktualny->wartosc;
}

#endif