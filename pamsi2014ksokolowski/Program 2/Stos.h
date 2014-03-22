#ifndef STOS_H
#define STOS_H

//Szablon klasy Stos (lista jednokierunkowa) oraz definicje jej metod.

#include <iostream>

//Klasa Stos (lista jednokierunkowa)
//Pozwala na dodawanie/usuwanie jej pierwszych elementow
//wyswietla wszystkie elementy tej klasy podajac przy tym jej aktualny rozmiar.
//*********************************************************************************
template <class TYP>
class Stos{
	//Aktualny rozmiar(liczba elementow) listy
	int rozmiar;

	//Klasa przechowujaca adres poprzedzajacego ja elementu oraz swoja wartosc
	//******************************************************************
	struct Element{
		TYP wartosc; //Wartosc elementu listy
		Element *poprzednik;//Wskaznik na poprzedni element listy

		Element(Element *adres = NULL) : poprzednik(adres) {}
	};//****************************************************************

	Element *aktualny;//Wskaznik na aktualnie pokazywany element listy

public:
	Stos<TYP>() : aktualny(), rozmiar(0) {}
	~Stos<TYP>()
	{
		while (aktualny != NULL){
			usun_element();
		}
	}

	//Dodawanie elementu okreslonego przez argument 'nowy' na gore stosu
	Stos<TYP>& dodaj_element(const TYP& nowy);
	//Usuwanie elementu z gory stosu
	Stos<TYP>& usun_element();
	//Podawanie wartosci elementu znajdujacego sie na gorze stosu z mozliwoscia jego edycji
	TYP& Wartosc() { return aktualny->wartosc; }
	//Podawanie wartosci elementu znajdujacego sie na gorze stosu bez mozliwosci jego edycji
	const TYP& Wartosc() const { return aktualny->wartosc; }
	//Wyswietlanie calej zawartosci listy wraz z informacja o jej romiarze (liczbie elementow)
	Stos<TYP>& wyswietl_liste();

	//Wyjmowanie elementu z gury stosu (podanie wartosci i jego usuniecie)
	TYP Pop() {
		TYP wart = Wartosc();

		usun_element();
		return wart;
	}
	
};//*********************************************************************************


////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
Stos<TYP>& Stos<TYP>::dodaj_element(const TYP& nowy)
{
	Element *schowek = aktualny;

	aktualny = new Element(schowek);
	aktualny->wartosc = nowy;

	++rozmiar;

	return (*this);
}
////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
Stos<TYP>& Stos<TYP>::usun_element()
{
	if (aktualny == NULL){
		std::cout << "\nStos jest pusty!\n";
		return *this;
	}

	Element *schowek = aktualny->poprzednik;

	delete aktualny;
	aktualny = schowek;

	--rozmiar;

	return *this;
}
////////////////////////////////////////////////////////////////////////////////////////
template <class TYP>
Stos<TYP>& Stos<TYP>::wyswietl_liste()
{
	if (aktualny == NULL){
		std::cout << "\nStos jest pusty!\n";
		return *this;
	}

	Stos<TYP> schowek; //schowek na wyswietlany Stos<TYP>
	int ile = rozmiar;

	std::cout << "Wyswietlanie stosu o rozmiarze: " << rozmiar << endl;

	for (int i = 0; i < ile; ++i){
		std::cout << aktualny->wartosc << " ";
		schowek.dodaj_element(this->Pop());
	}

	for (int i = 0; i < ile; ++i){
		dodaj_element(schowek.Pop());
	}

	return *this;
}


#endif