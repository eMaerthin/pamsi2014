//Dijkstra
#include "stdafx.h"

//Algorytm Dijkstry dla grafu zapisanego w postaci listy
int* dijkstra(lista **L, int ile_w, int *poprzednie)
{
	int m;
	wierzcholek *t;
	int* result = new int[ile_w];

	int *sciezki = new int[ile_w];                   // tablica pomocnicza pamiêtaj¹ca znalezione ju¿ minimalne œcie¿ki

	for (int i = 0; i < ile_w; i++)
	{
		sciezki[i] = 1;                         // wype³nienie '1' tablicy pomocniczej, czyli nie znamy jeszcze ¿adnej œcie¿ki
		result[i] = MAX * ile_w;		        // wype³nienie tablicy wynikowej wartoœciami œcie¿ek maksymalnych

	}

	t = L[0]->w;

	while (t != NULL)								// przegl¹danie listy
	{
		result[t->indeks] = t->waga;		// wype³nienie tablicy wyników, wartoœciami odpowiadaj¹cych wag
		t = t->n;
	}
	sciezki[0] = 0;

	for (int j = 0; j < ile_w - 1; j++)					// wyszukiwanie minimalnych œcie¿ek 
	{
		m = min_sciezka(result, sciezki, ile_w);	// wyszukujemy œcie¿kê minimaln¹ z juz znalezionych
		sciezki[m] = 0;								// zapamiêtanie znalezionej œcie¿ki
		t = L[m]->w;
		while (t != NULL)							// relaksacja krawêdzi						
		{
			if (sciezki[t->indeks] == 1)
				// sprawdzenie czy przy przejœciu przez dan¹ krawêdz nie otrzymamy krótszej œcie¿ki
			if ((result[m] + t->waga) < result[t->indeks])
			{
				// jeœli tak, to aktualizujemy
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

	sciezki = new int[ile_w];                      // tablica pomocnicza pamiêtaj¹ca znalezione ju¿ minimalne œcie¿ki

	for (int i = 0; i < ile_w; i++)
	{
		sciezki[i] = 1;                         // wype³nienie '1', czyli nie znamy jeszcze ¿adnej œcie¿ki

		if (M[0][i] != 0)						// wype³nienie tablicy wynikowej wartoœciami œcie¿ek maksymalnych
			result[i] = M[0][i];				// dla komórek niezerowych - zapisujemy wartoœæ tej komórki
		else
			result[i] = MAX * ile_w;			// jeœli brak krawêdzi zapisujem wagê maksymaln¹

	}

	sciezki[0] = 0;

	for (int j = 0; j < ile_w - 1; j++)							// wyszukiwanie minimalnych œcie¿ek 
	{
		min = min_sciezka(result, sciezki, ile_w);			// wyszukujemy œcie¿kê minimaln¹ z juz znalezionych
		sciezki[min] = 0;									// zapamiêtanie znalezionej œcie¿ki

		for (int w = 0; w < ile_w; w++)						// relaksacja krawêdzi
		if ((sciezki[w] == 1) && (M[min][w] != 0))
		if ((result[min] + M[min][w]) < result[w])	// sprawdzenie czy przy przejœciu przez dan¹ krawêdz nie otrzymamy krótszej œcie¿ki
		{
			poprzednie[w] = min;
			result[w] = result[min] + M[min][w];	// jeœli tak, to aktualizujemy
		}
	}
	result[0] = 0;
	delete[] sciezki;
	return result;
}


// Wyszukiwanie najkrótszej œcie¿ki ze wszystkich znalezionych dla danego wierzcho³ka
int min_sciezka(int *tab, int *tab2, int ile_w)
{
	int min, m_tab;

	min = 0;
	m_tab = tab[0];

	for (int i = 0; i < ile_w; i++)                       // pêtla przegl¹daj¹ca tablice
	if (tab2[i] == 1 && tab[i] < m_tab)					// jeœli nie znamy jeszcze najkrótszej œcie¿ki dla danego wierzcho³ka
	{                                                   // i znaleziona droga jest krótsze od dotychczasowego minimum
		m_tab = tab[i];									// zapis nowych wartoœci minimalnych
		min = i;
	}

	return min;
}
