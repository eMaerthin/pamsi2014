#ifndef KOPIEC_HH
#define KOPIEC_HH

//Klasa pojemnikowa typu kopiec

#include <iostream>
#include <ctime>	//srand
#include <cstdlib>	//srand
#include <math.h> 
#include <algorithm>

//Klasa pojemnikowa typu kopiec
//Uzywajac konstruktora nalezy stworzyc kopiec, ktory zostanie wypelniony losowymi danymi
//Mozna w srodku klasy wybrac typ sortowania. Stworzony przeze mnie lub tez przy uzyciu biblioteki STL
//*****************************************************************************************************
template <class TYP>
class Kopiec{
	TYP* tablica; //tablica przechowujaca elementy kopca
	int rozmiar; //rozmiar tablicy

public:
	
	//Konstruktor przyjmuje liczbe okreslajaca wielkosc kopca
	//Elementy kopca zostana wygenerowane losowo
	Kopiec(int roz) : rozmiar(roz) 
	{
		tablica = new TYP[roz];
		stworz_kopiec();
	}
	/////////////////////////////////////////////////////////////////////////
	~Kopiec(){
		delete[] tablica;
	}
	

	//Wyswietlanie kopca w wygodnym formacie
	void wyswietl() const
	{
		if (rozmiar <= 0) {
			std::cout << "\nKopiec jest pusty!" << endl;
		}
		int i, potega=1, suma=2;

		std::cout << tablica[0] << endl;
		for (i = 0; i < rozmiar; ++i){
			if ((2 * i + 1) >= rozmiar) break;
			std::cout << tablica[2 * i + 1] << " ";
			if ((2 * i + 2) >= rozmiar) break;
			std::cout << tablica[2 * i + 2] << "\t";

			if (suma % (2 * i + 2) == 0){
				suma += pow(2, ++potega);
				std::cout << endl;
			}
		}
		std::cout << endl;
	}
	/////////////////////////////////////////////////////////////////////////
	//Usuwanie pierwszego elementu tj o najwiekszej wartosci
	void usun_pierwszy()
	{
		przesun_w_lewo();
		--rozmiar;
		posortuj();
	}

private:
	//Funkcja tworzaca kopiec - losuje elementy i sortuje je
	//Mozna wybrac sortowanie przy pomocy algorytmu, wymyslonego przeze mnie, lub tez
	//uzywajac funkcji z biblioteki STL. Nalezy pamietac ze sortowanie to wtedy bedzie odwrotne!
	void stworz_kopiec()
	{
		wpisz_liczby_losowe();
		posortuj();
		//sortuj_z_stl();
	}
	/////////////////////////////////////////////////////////////////////////
	//Wpisanie liczb losowych do tablicy kopca
	void wpisz_liczby_losowe()
	{
		srand(time(NULL));

		for (int i = 0; i < rozmiar; ++i){
			tablica[i] = rand() % 100;
		}
	}
	/////////////////////////////////////////////////////////////////////////
	//Wlasny algorytm sortujacy kopiec
	void posortuj()
	{
		bool zmiana = false; //zmianna na zapamietanie czy zostala wykonana zamiana wkopcu
		int schowek;

		do{
			zmiana = false;
			for (int i = 0; i < rozmiar; ++i){
				if (2 * i >= rozmiar) break; //przerwanie gdy nie ma juz dalej "dzieci"
				if (tablica[i] < tablica[2 * i + 1]){
					schowek = tablica[i];
					tablica[i] = tablica[2 * i + 1];
					tablica[2 * i + 1] = schowek;

					zmiana = true;
				}
				if (tablica[i] < tablica[2 * i + 2]){
					schowek = tablica[i];
					tablica[i] = tablica[2 * i + 2];
					tablica[2 * i + 2] = schowek;

					zmiana = true;
				}
			}
		} while (zmiana); //dopuki nie zostanie niewykonana zadna zmiana
	}
	/////////////////////////////////////////////////////////////////////////
	//Funkcja pozwalajaca na sortowanie kopca przy uzyciu funkcji z biblioteki STL
	void sortuj_z_stl()
	{
		std::make_heap(tablica, tablica + rozmiar);
		//std::reverse(tablica, tablica + rozmiar);
		std::sort_heap(tablica, tablica + rozmiar);
	}
	/////////////////////////////////////////////////////////////////////////
	//Funkcja pomocnicza przy usuwaniu pierwszego elementu z kopca i tym samym z tablicy
	void przesun_w_lewo()
	{
		for (int i = 0; i < rozmiar-1; ++i){
			tablica[i] = tablica[i + 1];
		}
	}
};
//*****************************************************************************************************

#endif