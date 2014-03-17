#ifndef FUNKCJE_HH
#define FUNKCJE_HH

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>	//srand
#include <cstdlib>	//srand
#include "Tablica.h"

//********** Wczytywanie tablicy z konsoli
// rozmiar_tab - referencja do zmiennej, ktora bedzie przechowywac rozmiar tablicy
// Return: wskaznik na pierwszy element tablicy
int* wczytaj_tab_z_konsoli(int& rozmiar_tab);

//********** Wyswietlanie tablicy 
// tablica - wskaznik na tablice ktora chcemy wyswietlic
// ile - ile elementow jest w tablicy, czy tez ile chcemy wyswielic
// strumien - do jakiego strumienia chcemy wpisac tablice
void wyswietl_tablice(int* tablica, int ile, std::ostream& strumien = std::cout);

//********** Wczytywanie tablicy z pliku tekstowego
// rozmiar_tab - referencja do zmiennej, ktora bedzie przechowywac rozmiar tablicy
// Return: wskaznik na pierwszy element tablicy
int* wczytaj_tab_z_pliku(int& rozmiar_tab);

//********** Zapisywanie tablicy do pliku tekstowego
// tablica - wskaznik na tablice ktora chcemy zapisac
// ile - ile elementow jest w tablicy, czy tez ile chcemy elementow zapisac
void zapisz_tab_do_pliku(int* tablica, int ile);

//********** Wczytywanie tablicy z pliku binarnego
// rozmiar_tab - referencja do zmiennej, ktora bedzie przechowywac rozmiar tablicy
// Return: wskaznik na pierwszy element tablicy
int* wczytaj_tab_z_pliku_binarnego(int& rozmiar_tab);

//********** Zapisywanie tablicy do pliku binarnego
// tablica - wskaznik na tablice ktora chcemy zapisac
// ile - ile elementow jest w tablicy, czy tez ile chcemy elementow zapisac
void zapisz_tab_do_pliku_binarnego(int* tablica, int ile);

//********** Wypelnianie tablicy liczbami losowymi
// tablica - wskaznik na tablice, w ktorej chcemy miec liczby losowe(jezeli pusta, to zostanie stworzona z rozmiarem kolejnej zmiennej)
// rozmiar_tab - referencja do zmiennej, ktora bedzie przechowywac rozmiar tablicy
// Return: wskaznik na tablice
int* wypelnij_tablice_losowo(int& rozmiar_tab, int* tablica = NULL);

//********** Tworzenie kopi tablicy
// tablica - wskaznik na tablice, ktorej kopie chcemy utworzyc
// rozmiar_tab - rozmiar tej tablicy
// Return: wskaznik na utworzona kopie
int* zrob_kopie(int* tablica, int rozmiar_tab);

//********** Menu dla pierwszej czesci zadania - pracujacej na funkcjach
void program_funkcje();

//********** Menu dla drugiej czesci zadania - pracujacej na szablonie klasy Tablica
void program_klasa();

#endif