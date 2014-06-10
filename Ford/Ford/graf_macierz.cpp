#include "stdafx.h"
using namespace std;

graf_macierz::graf_macierz()			// konstruktor domyslny
{
	v = 1;
	macierz_wag = new int*[1];
	macierz_wag[0] = new int[1];
}

graf_macierz::graf_macierz(int ile)		// konstruktor tworzacy tworzacy macierz ile x ile
{
	v = ile;
	macierz_wag = new int*[ile];
	for (int i = 0; i < ile; i++)
		macierz_wag[i] = new int[ile];

	for (int i = 0; i<v; i++)
	for (int j = i; j<v; j++)
		macierz_wag[i][j] = macierz_wag[j][i] = 0;
}
graf_macierz::graf_macierz(int **tab, int rozmiar)		// konstruktor tworzacy macierz na podstawie dolaczonej tablicy
{
	v = rozmiar;
	macierz_wag = new int*[rozmiar];
	for (int i = 0; i < rozmiar; i++)
		macierz_wag[i] = new int[rozmiar];

	for (int i = 0; i<rozmiar; i++)
	for (int j = 0; j<rozmiar; j++)
		macierz_wag[i][j] = tab[i][j];
}


void graf_macierz::wypisz()								// wypisanie macierzy sasiedztwa na ekran
{
	for (int i = 0; i<v; i++)
	{
		for (int j = 0; j<v; j++)
			cout << macierz_wag[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

void graf_macierz::wypisz_do_pliku(ofstream& p)			// zapisanie macierzy sasiedztwa do pliku
{
	p << "Macierz sasiedztwa: " << endl << endl;
	for (int i = 0; i<v; i++)
	{
		for (int j = 0; j<v; j++)
			p << macierz_wag[i][j] << " ";
		p << endl;
	}
	p << endl;
}

void graf_macierz::wylosuj(int wsp)			// losowanie liczb do macierzy
{
	long long int suma = 0;
	int k, l;
	srand((int)time(NULL));		// zainicjowanie generatora liczb pseudolosowych

	for (int i = 0; i< v - 1; i++)		// sumujemy wszystkie wierzcholki
		suma += i;

	suma = (long long int) (suma * wsp / 100);				// zmienna potrzebna do okreslania gestosci grafu

	for (k = 0; k < v; k++)
	{
		for (l = k; l < v; l++)
		{
			if (l == (k + 1))
				macierz_wag[k][l] = macierz_wag[l][k] = (rand() % MAX) + 1;		// generujemy najprostszy graf bez pêtli
		}
	}

	int m = 0;
	while (m < suma)							// w zale¿noœci od wspó³czynnika
	{

		k = rand() % v;							// losowanie wierzcho³ka
		l = rand() % v;

		if (macierz_wag[k][l] == 0 && k != l)
		{

			macierz_wag[k][l] = macierz_wag[l][k] = (rand() % MAX) + 1;			// dodawanie "liœci" do grafu
			m++;
		}
	}
}

void graf_macierz::wyczysc()			// czyszczenie macierzy
{
	for (int i = 0; i<v; i++)
	for (int j = i; j<v; j++)
		macierz_wag[i][j] = macierz_wag[j][i] = 0;
}