#include "menu.h"

using namespace std;

void menu_stos()
{
	int wybor;

	Stos<int> stosik;
	int typ; //jezeli zmieniamy typ stosu trzeba tez zmienic typ tej zmiennej - sluzy ona wykryciu typu dla funkcji wczytaj_wartosc
	
	do{
		cout << "\n\n\n******** Menu Stos ********" << endl
			<< "1. Dodaj element na poczatku stosu." << endl
			<< "2. Wyswietlanie stosu oraz aktualnego rozmiaru." << endl
			<< "3. Usuniecie elementu z przodu stosu. " << endl
			<< "0. Wyjscie" << endl
			<< "Twoj wybor:\t";
		cin >> wybor;

		switch (wybor){
			
		case 1:	stosik.dodaj_element(wczytaj_wartosc(typ));
			break;
		case 2: stosik.wyswietl_liste();
			break;
		case 3: stosik.usun_element();
			break;
		}

	} while (wybor != 0);
}
////////////////////////////////////////////////////////////////////////////////////////
void menu_lista()
{
	int wybor;

	Lista<int> moja_lista; 
	int typ; //jezeli zmieniamy typ listy trzeba tez zmienic typ tej zmiennej - sluzy ona wykryciu typu dla funkcji wczytaj_wartosc

	do{
		cout << "\n\n\n******** Menu Lista ********" << endl
			<< "1. Dodaj element na poczatku listy." << endl
			<< "2. Dodaj element na koncu listy." << endl
			<< "3. Wyswietlanie listy oraz aktualnego rozmiaru." << endl
			<< "4. Usuniecie elementu z przodu listy. " << endl
			<< "5. Usuniecie elementu z konca listy. " << endl
			<< "0. Wyjscie" << endl
			<< "Twoj wybor:\t";
		cin >> wybor;

		switch (wybor){

		case 1: moja_lista.dodaj_na_poczatek(wczytaj_wartosc(typ));
			break;
		case 2: moja_lista.dodaj_na_koniec(wczytaj_wartosc(typ));
			break;
		case 3: moja_lista.wyswietl();
			break;
		case 4: moja_lista.usun_pierwszy();
			break;
		case 5: moja_lista.usun_ostatni();
			break;
		}

	} while (wybor != 0);
}