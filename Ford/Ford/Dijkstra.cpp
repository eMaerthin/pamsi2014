//Dijkstra
#include "stdafx.h"

//Algorytm Dijkstry dla grafu zapisanego w postaci listy
int* dijkstra(lista **L, int ile_w, int *poprzednie)
{
	int m;
	wierzcholek *t;
	int* result = new int[ile_w];

	int *sciezki = new int[ile_w];                   // tablica pomocnicza pami�taj�ca znalezione ju� minimalne �cie�ki

	for (int i = 0; i < ile_w; i++)
	{
		sciezki[i] = 1;                         // wype�nienie '1' tablicy pomocniczej, czyli nie znamy jeszcze �adnej �cie�ki
		result[i] = MAX * ile_w;		        // wype�nienie tablicy wynikowej warto�ciami �cie�ek maksymalnych

	}

	t = L[0]->w;

	while (t != NULL)								// przegl�danie listy
	{
		result[t->indeks] = t->waga;		// wype�nienie tablicy wynik�w, warto�ciami odpowiadaj�cych wag
		t = t->n;
	}
	sciezki[0] = 0;

	for (int j = 0; j < ile_w - 1; j++)					// wyszukiwanie minimalnych �cie�ek 
	{
		m = min_sciezka(result, sciezki, ile_w);	// wyszukujemy �cie�k� minimaln� z juz znalezionych
		sciezki[m] = 0;								// zapami�tanie znalezionej �cie�ki
		t = L[m]->w;
		while (t != NULL)							// relaksacja kraw�dzi						
		{
			if (sciezki[t->indeks] == 1)
				// sprawdzenie czy przy przej�ciu przez dan� kraw�dz nie otrzymamy kr�tszej �cie�ki
			if ((result[m] + t->waga) < result[t->indeks])
			{
				// je�li tak, to aktualizujemy
				result[t->indeks] = result[m] + t->waga;
				poprzednie[t->indeks] = m;
			}

			t = t->n;
		}
	}
	result[0] = 0;

	delete[] sciezki;
	return result;
}

//Algorytm Dijkstry dla grafu zapisanego w postaci macierzowej
int* dijkstra(int **M, int ile_w, int *poprzednie)
{
	int min, *sciezki;
	int* result = new int[ile_w];

	sciezki = new int[ile_w];                      // tablica pomocnicza pami�taj�ca znalezione ju� minimalne �cie�ki

	for (int i = 0; i < ile_w; i++)
	{
		sciezki[i] = 1;                         // wype�nienie '1', czyli nie znamy jeszcze �adnej �cie�ki

		if (M[0][i] != 0)						// wype�nienie tablicy wynikowej warto�ciami �cie�ek maksymalnych
			result[i] = M[0][i];				// dla kom�rek niezerowych - zapisujemy warto�� tej kom�rki
		else
			result[i] = MAX * ile_w;			// je�li brak kraw�dzi zapisujem wag� maksymaln�

	}

	sciezki[0] = 0;

	for (int j = 0; j < ile_w - 1; j++)							// wyszukiwanie minimalnych �cie�ek 
	{
		min = min_sciezka(result, sciezki, ile_w);			// wyszukujemy �cie�k� minimaln� z juz znalezionych
		sciezki[min] = 0;									// zapami�tanie znalezionej �cie�ki

		for (int w = 0; w < ile_w; w++)						// relaksacja kraw�dzi
		if ((sciezki[w] == 1) && (M[min][w] != 0))
		if ((result[min] + M[min][w]) < result[w])	// sprawdzenie czy przy przej�ciu przez dan� kraw�dz nie otrzymamy kr�tszej �cie�ki
		{
			poprzednie[w] = min;
			result[w] = result[min] + M[min][w];	// je�li tak, to aktualizujemy
		}
	}
	result[0] = 0;
	delete[] sciezki;
	return result;
}


// Wyszukiwanie najkr�tszej �cie�ki ze wszystkich znalezionych dla danego wierzcho�ka
int min_sciezka(int *tab, int *tab2, int ile_w)
{
	int min, m_tab;

	min = 0;
	m_tab = tab[0];

	for (int i = 0; i < ile_w; i++)                       // p�tla przegl�daj�ca tablice
	if (tab2[i] == 1 && tab[i] < m_tab)					// je�li nie znamy jeszcze najkr�tszej �cie�ki dla danego wierzcho�ka
	{                                                   // i znaleziona droga jest kr�tsze od dotychczasowego minimum
		m_tab = tab[i];									// zapis nowych warto�ci minimalnych
		min = i;
	}

	return min;
}
