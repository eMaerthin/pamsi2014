#ifndef MENU_HH
#define MENU_HH

// Plik z funkcjami menu 

#include <iostream>
#include "Stos.h"
#include "Lista.h"

// Menu dla operacji na klasie STOS 
// Wyswietla opcje mozliwe do wykonania przez stos i umozliwia na nim operacje
void menu_stos();

// Menu dla operacji na klasie LISTA 
// Wyswietla opcje mozliwe do wykonania przez liste i umozliwia na niej operacje
void menu_lista();

// Funkcja wczytujaca wartosc
// Przed wczytaniem wartosci wyswietla tekst o tym ze nalezy wpisac wartosc.
// Argument: Dowolna zmienna typu ktory ma byc wczytany
// Zwraca: wczytana wartosc z konsoli
template <class TYP>
TYP wczytaj_wartosc(TYP&) // TYP& by wykryc typ (& po to by nie trzeba bylo inicjalizowac go)
{
	TYP wartosc;

	std::cout << "\nPodaj element ktory chcesz dodac:\t";
	std::cin >> wartosc;

	return wartosc;
}


#endif