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

	int Rozmiar_stosu() { cout << endl << "__________________" << endl << "Rozmiar stosu:\t"; return rozmiar; }

	void Poloz_poczatek(TYP d);
	bool Usun_poczatek();
	void Wyswietl_stos();
};


template <typename TYP>
void k_stos<TYP>::Poloz_poczatek(TYP d) {
	k_element<TYP>* nowy = new k_element<TYP>(d);

	if (pierwszy == NULL) pierwszy = nowy; //jesli lista jest pusta
	else {
		k_element<TYP> *temp = pierwszy; // jesli nie, przypisujemy tymczasowo dodany element
		while (temp->wsk) { temp = temp->wsk; } //przeskakujemy po wskaünikach na poczatek
		temp->wsk = nowy;  // przypisujemy nowy element do poczatku listy
	}
	rozmiar++;
}
template <typename TYP>
void k_stos<TYP>::Wyswietl_stos() {
	k_element<TYP> *i = pierwszy; //iterator
	cout << endl << "Lista elementÛw, w kolejnoúci od pierwszego do ostatniego:" << endl;
	while (i) {
		cout << i->wartosc << endl;
		i = i->wsk;
	}
}

template <typename TYP>
bool k_stos<TYP>::Usun_poczatek() {
	int i,s;
	if (pierwszy == NULL) { cout << "Stos jest pusty"; return false; } //jesli lista jest pusta
	else {
		k_element<TYP> *temp = pierwszy; // jesli nie, przypisujemy tymczasowo dodany element
		i = 0;
		while (temp->wsk != NULL) { temp = temp->wsk; i++; } //przeskakujemy po wskaünikach na poczatek
		temp = NULL;
		for (s = 0; s < i; s++) {
			pierwszy = pierwszy->wsk;
		}
		pierwszy->wsk = NULL;
		rozmiar--;
		return true;
	}
}

#endif
