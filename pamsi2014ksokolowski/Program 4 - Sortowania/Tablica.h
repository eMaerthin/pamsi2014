#ifndef TABLICA_HH
#define TABLICA_HH

//Definicja szblonu klasy Tablica

#include <iostream>
#include <ctime>	//srand
#include <cstdlib>	//srand
#include <algorithm> //dla kopca
#include <stack>
#include <conio.h>
#include <fstream>
#include <string>
#include <random>
#include "boost/date_time/posix_time/posix_time.hpp"

//Klasa Tablica zawiera w sobie alokowana dynamicznie tablice, ktora mozna
//posortowac: przez kopcowanie, przez scalanie, metoda Shella
//Klasa pamieta czas w jakim zostalo wykonane sortowanie. Czas ten mozna
//odczytac za pomoca odpowiedniej metody.
//*******************************************************************************
template <class TYP>
class Tablica{
	TYP *tab; //wskaznik na tablice zmiennych, ktore bedziemy losowac
	int rozmiar; //rozmiar tablicy tab

	std::stack<int> ods_Tokuda; //stos przechowujacy kolejne odstepy Tokuda

	boost::posix_time::time_duration czas_ostatniego_sortowania;

	std::string zapisywanie;
	std::string wczytywanie;

public:
	///////////////////////////////////////////////////////////
	//Konstruktor wraz ze wstepna inicjalizacja zmiennych
	Tablica() : rozmiar(0) , tab(NULL) {
		srand((int)time(NULL));
	}
	//Konstruktor kopiujacy
	Tablica(const Tablica& oryginal) {
		*this = oryginal;
	}
	///////////////////////////////////////////////////////////
	~Tablica()
	{
		if (tab != NULL){
			delete[] tab;
		}
	}
	///////////////////////////////////////////////////////////

	//Podawanie czasu ostatniego wykonanego sortowania
	int czas_sort() const
	{
		return (int)czas_ostatniego_sortowania.total_milliseconds();
	}
	///////////////////////////////////////////////////////////
	//Wlosowanie losowych elementow do tablicy
	void wlosuj_elementy(int roz = 0)
	{
		srand((int)time(NULL));

		if (roz == 0 && rozmiar == 0){
			std::cout << "\nPodaj rozmiar tablicy: ";
			std::cin >> rozmiar;
		}
		else {
			rozmiar = roz;
		}
		tab = new TYP[rozmiar];

		for (int i = 0; i < rozmiar; ++i){
			tab[i] = rand() % rozmiar + 1;
		}
	}
	///////////////////////////////////////////////////////////
	//Wlosowywanie elementow z rozkladu jednostajnego do tablicy
	void wlosuj_rozkladem_jednostajnym(int roz = 0){
		if (roz == 0 && rozmiar == 0){
			std::cout << "\nPodaj rozmiar tablicy: ";
			std::cin >> rozmiar;
		}
		else {
			rozmiar = roz;
		}
		tab = new TYP[rozmiar];

		std::default_random_engine generator;
		std::uniform_int_distribution<int> distribution(1, rozmiar);

		for (int i = 0; i < rozmiar; ++i){
			tab[i] = distribution(generator);
		}
	}
	///////////////////////////////////////////////////////////
	//Wlosowywanie elementow z rozkladu normalnego do tablicy
	void wlosuj_rozkladem_normalnym(int roz = 0){
		if (roz == 0 && rozmiar == 0){
			std::cout << "\nPodaj rozmiar tablicy: ";
			std::cin >> rozmiar;
		}
		else {
			rozmiar = roz;
		}
		tab = new TYP[rozmiar];

		std::default_random_engine generator;
		std::normal_distribution<double> distribution(rozmiar, rozmiar/2);

		for (int i = 0; i < rozmiar; ++i){
			tab[i] = static_cast<int>(distribution(generator));
		}
	}
	///////////////////////////////////////////////////////////
	//Wlosowywanie elementow z rozkladu Poissona do tablicy
	void wlosuj_rozkladem_poissona(int roz = 0){
		if (roz == 0 && rozmiar == 0){
			std::cout << "\nPodaj rozmiar tablicy: ";
			std::cin >> rozmiar;
		}
		else {
			rozmiar = roz;
		}
		tab = new TYP[rozmiar];

		std::default_random_engine generator;
		std::poisson_distribution<int> distribution(rozmiar);

		for (int i = 0; i < rozmiar; ++i){
			tab[i] = distribution(generator);
		}
	}
	///////////////////////////////////////////////////////////
	//Menu wczytywania z pliku zbioru elementow
	void wczytaj_z_pliku_menu()
	{
		std::ofstream zap;
		std::ifstream wczy;

		do{
			std::cout << "\nPodaj plik, z ktorego bedziemy wczytywac: ";
			std::cin >> wczytywanie;

			wczy.open(wczytywanie);
			if (!wczy.good()){
				std::cout << "\nPlik o nazwie: '" << wczytywanie << "' nie istnieje!" << endl;
			}
		} while (!wczy.good());
		wczy.close();

		do{
			std::cout << "\nPodaj plik, do ktorego bedziemy zapisywac: ";
			std::cin >> zapisywanie;

			zap.open(zapisywanie);
			if (!zap.good()){
				std::cout << "\nPlik o nazwie: '" << zapisywanie << "' nie istnieje!" << endl;
			}
		} while (!zap.good());
		zap.close();

		wczytaj_z_pliku();
	}
	///////////////////////////////////////////////////////////
	//Wyswietlanie tablicy
	void wyswietl_tab() const
	{
		std::cout << endl;
		for (int i = 0; i < rozmiar; ++i){
			std::cout << tab[i] << " ";
		}
		std::cout << endl;
	}

	//Operator przypisania by zapobiec kopiowaniu adresu tablicy, a skopiowac tylko jej elementy
	Tablica& operator=(const Tablica& oryginal)
	{
		if (tab != NULL){
			delete[] tab;
		}

		rozmiar = oryginal.rozmiar;
		tab = new TYP[rozmiar];
		
		for (int i = 0; i < rozmiar; ++i){
			tab[i] = oryginal.tab[i];
		}

		return *this;
	}
	///////////////////////////////////////////////////////////
	//Wstepne posortowanie tablicy.
	//Argument: procent - procent elementow tablicy do posortowania
	void posortuj_wstepnie(int procent = 0){
		if (procent > 100 || procent < 0){
			std::cout << "Procent nie moze byc wiekszy od 100 i mniejszy od 0!\n";
			return;
		}
		
		sort_przez_sc(0, rozmiar);
		wymieszaj(rozmiar*procent / 100, rozmiar);
	}
	///////////////////////////////////////////////////////////
	//Wykonanie sortowania przez kopcowanie wraz z pomiarem czasu tego sortowania
	void posortuj_przez_kopcowanie()
	{
		boost::posix_time::ptime p = boost::posix_time::microsec_clock::local_time();
		bool czy_posort = false;
		//Wlasciwe sortowanie przez kopcowanie
		for (int i = 0; i < rozmiar; ++i){
			czy_posort = true;
			for (int j = 0; j < rozmiar - 1; ++j){
				if (tab[j] < tab[j + 1]){
					czy_posort = false;
					i = j;
					break;
				}
			}
			if (czy_posort) break;
			std::make_heap(tab + i, tab + rozmiar);
		}

		boost::posix_time::ptime k = boost::posix_time::microsec_clock::local_time();

		czas_ostatniego_sortowania = k - p;
		
		if (!zapisywanie.empty()){
			zapisz_do_pliku();
		}
	}
	///////////////////////////////////////////////////////////
	//Funkcja zarzadzajaca sortowaniem przez scalanie oraz mierzaca czas wykonania tego sortowania
	void posortuj_przez_scalanie()
	{
		boost::posix_time::ptime p = boost::posix_time::microsec_clock::local_time();

		sort_przez_sc(0, rozmiar); //Wlasciwe sorotwanie przez scalanie

		boost::posix_time::ptime k = boost::posix_time::microsec_clock::local_time();

		czas_ostatniego_sortowania = k - p;

		if (!zapisywanie.empty()){
			zapisz_do_pliku();
		}
	}
	///////////////////////////////////////////////////////////
	//Funkcja zarzadzajaca sortowaniem metoda Shella oraz mierzaca czas wykonania tego sortowania
	void posortuj_Shella()
	{
		generuj_odstepy_Tokuda();

		boost::posix_time::ptime p = boost::posix_time::microsec_clock::local_time();

		sort_Shella();  //Wlasciwe sorotwanie przez scalanie

		boost::posix_time::ptime k = boost::posix_time::microsec_clock::local_time();

		czas_ostatniego_sortowania = k - p;
		if (!zapisywanie.empty()){
			zapisz_do_pliku();
		}
	}

private:
	///////////////////////////////////////////////////////////
	//Sortowanie tablicy przez scalanie
	//Argumenty: pocz - poczatek (nr elementu tablicy tab), od ktorego mamy zaczac sortowanie
	//           kon - koniec (nr elementu tablicy tab), na ktorym mamy zakonczyc sortowanie
	void sort_przez_sc(int pocz, int kon)
	{
		if (pocz - kon > 1){ //dopoki podtablica ma rozmiar wiekszy niz 1
			//dzielenie na podtablice
			int i = (pocz + kon) / 2; 
			sort_przez_sc(pocz, i);
			sort_przez_sc(i + 1, kon);
		}

		//Scalajac elementy podtablic sortujemy je przez wstawianie
		sort_przez_wstawianie(pocz, kon);
		return;
	}
	///////////////////////////////////////////////////////////
	//Funkcja sortujaca przez wstawianie. Jest funkcja pomocnicza do sortowania przez scalanie
	void sort_przez_wstawianie(int pocz=0, int kon=rozmiar)
	{
		int i, k, schowek;
		for (i = 1+pocz; i<kon; i++)
		{
			k = i;
			schowek = tab[i];
			while ((tab[k - 1]<schowek) && (k>0))
			{
				tab[k] = tab[k - 1];
				k--;
			}
			tab[k] = schowek;
		}
	}
	///////////////////////////////////////////////////////////
	//Generowanie liczb slozacych jako odstepy Tokuda. Odstepy te sa potrzebne do
	//sortowania metoda Schella i sa zapamietane w stosie
	void generuj_odstepy_Tokuda()
	{
		const double mnoznik = 2.25; //Mnoznik pozwalajacy wyliczyc kolejne odstepy Tokuda

		//Dodanie 2 pierwszych elementow niebedacych zgodnych z algorytmem, ale nalezacych do ciagu Tokuda
		ods_Tokuda.push(1);
		ods_Tokuda.push(4);
		//Wyliczanie reszty odstepow Tokuda
		while (ods_Tokuda.top()*mnoznik < rozmiar){
			ods_Tokuda.push(static_cast<int>(ods_Tokuda.top()*mnoznik));
		}
	}
	///////////////////////////////////////////////////////////
	//Wlasciwe sortowanie metoda Shella
	void sort_Shella()
	{
		int i, j, schowek;

		while (!ods_Tokuda.empty()) //Dopoki zostaly jeszcze jakies nieuzyte odstepy
		{
			for (j = rozmiar - ods_Tokuda.top() - 1; j >= 0; j--) //Podzial na podtablice do sortowania
			{
				schowek = tab[j];
				i = j + ods_Tokuda.top();
				while ((i < rozmiar) && (schowek < tab[i])) //Sortowanie elementow w podtablicach
				{
					tab[i - ods_Tokuda.top()] = tab[i];
					i += ods_Tokuda.top();
				}
				tab[i - ods_Tokuda.top()] = schowek;
			}
			ods_Tokuda.pop(); //Wyrzucenie ostatniego uzywanego odstepu 
		}
	}
	///////////////////////////////////////////////////////////
	//Wczytywanie z zbioru elementow z pliku
	void wczytaj_z_pliku()
	{
		std::ifstream plik(wczytywanie);

		plik >> rozmiar;
		tab = new TYP[rozmiar];

		for (int i = 0; i < rozmiar; ++i){
			plik >> tab[i];
		}

		plik.close();
	}
	///////////////////////////////////////////////////////////
	//Zapisywanie zbioru elementow do pliku
	void zapisz_do_pliku()
	{
		std::ofstream plik(zapisywanie);

		plik << rozmiar << endl;

		for (int i = 0; i < rozmiar; ++i){
			plik << tab[i] << " ";
		}

		plik.close();
	}
	///////////////////////////////////////////////////////////
	//Funkcja mieszajaca uzywana przy wstepnym sortowaniu by elementy ktore nie maja byc posorotwane byly pomieszane
	void wymieszaj(int pocz, int kon){
		int schowek, miejsce;
		while (kon - pocz >= 1){
			schowek = tab[pocz];
			miejsce = rand() % (kon - pocz) + pocz;
			tab[pocz] = tab[miejsce];
			tab[miejsce] = schowek;
			++pocz;
		}
	}
};
//*******************************************************************************


#endif