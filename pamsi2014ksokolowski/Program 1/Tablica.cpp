#include "Tablica.h"

using namespace std;

int* wczytaj_tab_z_konsoli(int& rozmiar_tab, istream& strumien)
{
	cout << "\nIle elementow chcesz wpisac?\t";

	int *tablica;
	cin >> rozmiar_tab;

	tablica = new int[rozmiar_tab];

	for (int i = 0; i < rozmiar_tab; ++i){
		cin >> tablica[i];
	}

	return tablica;
}
////////////////////////////////////////////////////////////////////////////////