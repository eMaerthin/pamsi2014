#ifndef LISTA_HH
#define LISTA_HH
#include <iostream>
using namespace std;

template <typename TYP>
class k_element {
public:
	TYP wartosc;
	k_element *nastepny;
	k_element *poprzedni;
	k_element(TYP d) { wartosc = d; poprzedni = nastepny = NULL; }
	~k_element() { wartosc = NULL; poprzedni = nastepny = NULL; }
};

template <typename TYP>
class k_lista { //lista dwukierunkowa
	int rozmiar;
	k_element<TYP> *pierwszy; //pierwszy element
	k_element<TYP> *ostatni; //ostatni element
public:
	k_lista(){ pierwszy = NULL; ostatni = NULL; rozmiar = 0; } //konstruktor klasy lista
	~k_lista() { while (Usun_poczatek()); } //destruktor klasy lista

	void Rozmiar_listy() { cout << endl << "__________________" << endl << "Rozmiar listy, ilosc elementow:\t" << rozmiar << endl; }

	void Poloz_poczatek(TYP d);
	void Poloz_koniec(TYP d);
	bool Usun_poczatek();
	bool Usun_koniec();
	void Wyswietl_liste();
};


template <typename TYP>
void k_lista<TYP>::Poloz_poczatek(TYP d) {
	k_element<TYP>* nowy = new k_element<TYP>(d);
	if (pierwszy == NULL) pierwszy = ostatni = nowy; //jesli lista jest pusta
	else { nowy->nastepny = pierwszy; //przypisujemy wczesniej pierwszy element listy jako drugi
			pierwszy = nowy; } // przypisujemy nowy element do poczatku listy
	rozmiar++;
}
template <typename TYP>
void k_lista<TYP>::Poloz_koniec(TYP d) {
	k_element<TYP>* nowy = new k_element<TYP>(d);
	if (pierwszy == NULL) pierwszy = ostatni = nowy; //jesli lista jest pusta
	else { if (ostatni->nastepny == NULL) nowy->poprzedni = ostatni; ostatni->nastepny = nowy; } //jesli nie, przeskakujemy po wskaünikach na koniec
	rozmiar++;											//i przypisujemy nowy element do konca listy
}
template <typename TYP>
void k_lista<TYP>::Wyswietl_liste() {
	k_element<TYP> *i = pierwszy; //iterator
	cout << endl << "Lista elementÛw, w kolejnoúci od pierwszego do ostatniego:" << endl;
	while (i) { cout << i->wartosc << endl;
		i = i->nastepny; }
	delete i; //zwalnianie pamieci
}
template <typename TYP>
bool k_lista<TYP>::Usun_poczatek() {
	if (rozmiar == 0) { cout << "Lista jest pusta"; return false; } //jesli lista jest pusta
	if (rozmiar == 1) { rozmiar--; pierwszy = NULL; return true; } //jesli lista zawiera jeden element
	else { rozmiar--;
		k_element<TYP> *temp = pierwszy;
		pierwszy = temp->nastepny; //jesli lista zawiera wiecej elementow
		delete temp; //zwalnianie pamieci
		return true; }
}
template <typename TYP>
bool k_lista<TYP>::Usun_koniec() {
	if (rozmiar == 0) { cout << "Lista jest pusta"; return false; } //jesli lista jest pusta
	if (rozmiar == 1) { rozmiar--; free(pierwszy); pierwszy = ostatni = NULL; return true; } //jesli lista zawiera jeden element
	else {	rozmiar--; //jesli lista zawiera wiecej elementow 
			k_element<TYP> *temp = ostatni;
			if (ostatni->nastepny == NULL) ostatni = ostatni->poprzedni; ostatni->nastepny = NULL; //nie dziala, lista prawdopodobnie przeskakuje za daleko
	delete temp;
	return true; }
}

#endif
