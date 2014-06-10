#include "stdafx.h"

using namespace std;

void lista::dodaj(int indeks, int waga)		// metoda  do dodawania nowego wierzcholka
{
	wierzcholek *tmp;
	tmp = new wierzcholek;
	tmp->n = w;
	tmp->indeks = indeks;
	tmp->waga = waga;
	w = tmp;
}
void lista::wypisz()						// wypisanie listy na ekran
{
	wierzcholek *tmp = w;
	while (tmp != NULL)
	{
		cout << tmp->indeks << "=" << tmp->waga << " ";
		tmp = tmp->n;
	}
}
void lista::wypisz_do_pliku(ofstream& p)		// zapis listy wierzcholkow do pliku
{
	wierzcholek *tmp = w;
	while (tmp != NULL)
	{
		p << " -> " << tmp->indeks << " = " << tmp->waga << " ";
		tmp = tmp->n;
	}
}
void graf_lista::wypisz()						// wypisanie grafu w postaci listy sasiedztwa na ekran
{
	for (int i = 0; i<v; i++)
	{
		cout << endl << i << "->";
		list[i]->wypisz();
	}

	cout << endl;
}
void graf_lista::wypisz_do_pliku(ofstream& p)		// zapis grafu w reprezentacji listy sasiedztwa do pliku
{
	p << "Lista sasiedztwa: " << endl;
	for (int i = 0; i<v; i++)
	{
		p << endl << i;
		list[i]->wypisz_do_pliku(p);
	}

	p << endl << endl;
}
void graf_lista::konwertuj(int **M)					// zamiana macierzy sasiedztwa na liste sasiedztwa
{
	for (int i = 0; i<v; i++)
	{
		list[i] = new lista;
		list[i]->w = NULL;
	}

	for (int i = 0; i<v; i++)
	{
		for (int j = i; j<v; j++)
		{
			if (M[i][j] != 0)
			{
				list[i]->dodaj(j, M[i][j]);
				list[j]->dodaj(i, M[i][j]);
			}
		}
	}
}