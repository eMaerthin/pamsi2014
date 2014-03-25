#ifndef STOS_HH
#define STOS_HH
#include <iostream>
using namespace std;

template <typename TYP>
class k_element {
public:
	TYP wartosc;
	k_element *wsk;
	k_element(TYP d) { wartosc = d; wsk = NULL; }
};

template <typename TYP>
class k_stos { //lista jednokierunkowa
	int rozmiar;
	k_element<TYP> *pierwszy; //pierwszy element

public:
	k_stos(){ pierwszy = NULL; rozmiar = 0; } //konstruktor klasy stos
	~k_stos() { while (Usun_poczatek()); } //destruktor klasy stos

	void Rozmiar_stosu() { cout << endl << "__________________" << endl << "Rozmiar stosu, ilosc elementow:\t" << rozmiar << endl; }

	void Poloz_poczatek(TYP d);
	bool Usun_poczatek();
	void Wyswietl_stos();
};


template <typename TYP>
void k_stos<TYP>::Poloz_poczatek(TYP d) {
	k_element<TYP>* nowy = new k_element<TYP>(d);

	if (pierwszy == NULL) pierwszy = nowy; //jesli lista jest pusta
	else { nowy->wsk = pierwszy; //przypisujemy wczesniej pierwszy element listy jako drugi
			pierwszy = nowy;  // przypisujemy nowy element do poczatku listy
	}
	rozmiar++;
}
template <typename TYP>
void k_stos<TYP>::Wyswietl_stos() {
	k_element<TYP> *i = pierwszy; //iterator
	cout << endl << "Lista elementów, w kolejnoœci od pierwszego do ostatniego:" << endl;
	while (i) {
		cout << i->wartosc << endl;
		i = i->wsk; }
	delete i; //zwalnianie pamieci tymczasowej
}

template <typename TYP>
bool k_stos<TYP>::Usun_poczatek() {
	if (pierwszy == NULL) { cout << "Stos jest pusty"; return false; } //jesli lista jest pusta
	else { rozmiar--;
		k_element<TYP> *temp = pierwszy;
		if (temp->wsk == NULL) pierwszy = NULL; //jesli pierwszy element jest pierwszy na liscie; lista zawiera jeden element
		else pierwszy = temp->wsk; //jesli lista zawiera wiecej elementow
		delete temp; //zwalnianie pamieci tymczasowej
		return true; }
}

#endif
