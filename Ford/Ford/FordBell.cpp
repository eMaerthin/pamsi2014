//Bellman-Ford
#include "stdafx.h"

//Algorytm Bellmana-Forda dla grafu zapisanego w postaci listy
int* bell_Ford(lista **L, int ile_w, int *poprzednie)
{
	int t1, temp;
	wierzcholek *t;
	int* result = new int[ile_w];

	t = L[0]->w;

	for (int i = 1; i < ile_w; i++)
		result[i] = NIESKON;                                      // wype³nienie tablicy wyników nieskoñczonoœciami 

	result[0] = 0;

	while (t != NULL)										  // dla istniej¹cych krawêdzi zapisujemy ich wagê
	{
		result[t->indeks] = t->waga;
		t = t->n;
	}

	for (int i = 1; i < ile_w; i++)
	{
		t = L[i]->w;

		while (t != NULL)											// sprawdzanie kolejnych œcie¿ek
		{
			if (result[t->indeks] + t->waga > NIESKON)
				t1 = NIESKON;										// jeœli krawêdz nieistnieje zapisujemy nieskoñczonoœæ
			else
			{
				t1 = result[t->indeks] + t->waga;				// jeœli istnieje dodajemy jej wagê
				temp = t->indeks;
			}

			if (result[i] > t1)										// sprawdzenie czy znaleziona œcie¿ka jest krótsza od ju¿ znanej
			{
				result[i] = t1;
				poprzednie[i] = temp;
			}

			t = t->n;
		}
	}

	return result;
}

//Algorytm Bellmana-Forda dla grafu zapisanego w postaci macierzy
int* bell_Ford(int** M, int ile_w, int *poprzednie)
{
	int* result = new int[ile_w];
	int** autM = new int*[ile_w];						// tworzymy lokalna kopie macierzy						

	for (int i = 0; i < ile_w; ++i)
	{
		autM[i] = new int[ile_w];
		for (int j = 0; j < ile_w; ++j)
		{
			autM[i][j] = M[i][j];
			if (autM[i][j] == 0)
				autM[i][j] = NIESKON;					// nieistniej¹ce krawêdzie zastêpujemy nieskoñczonoœciami
		}

		autM[i][i] = 0;
	}

	int temp, temp2;

	for (int i = 0; i < ile_w; ++i)									// wpisujemy do tablicy wyników wartoœci pocz¹tkowe
		result[i] = autM[0][i];

	for (int i = 1; i < ile_w; i++)                               // przeszukiwanie kolejnych wierszy i kolumn 
	{
		for (int j = 0; j < ile_w; j++)
		{
			if (result[j] + autM[j][i] > INT_MAX)
				temp = NIESKON;										// jeœli krawêdz nieistnieje zapisujemy nieskoñczonoœæ
			else
			{
				temp = result[j] + autM[j][i];						// jeœli istnieje dodajemy jej wagê
				temp2 = j;
			}

			if (result[i] > temp)								    // sprawdzenie czy znaleziona œcie¿ka jest krótsza od ju¿ znanej
			{
				result[i] = temp;
				poprzednie[i] = temp2;
			}


		}
	}
	delete[] autM;
	return result;
}