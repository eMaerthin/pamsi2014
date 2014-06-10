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
		result[i] = NIESKON;                                      // wype�nienie tablicy wynik�w niesko�czono�ciami 

	result[0] = 0;

	while (t != NULL)										  // dla istniej�cych kraw�dzi zapisujemy ich wag�
	{
		result[t->indeks] = t->waga;
		t = t->n;
	}

	for (int i = 1; i < ile_w; i++)
	{
		t = L[i]->w;

		while (t != NULL)											// sprawdzanie kolejnych �cie�ek
		{
			if (result[t->indeks] + t->waga > NIESKON)
				t1 = NIESKON;										// je�li kraw�dz nieistnieje zapisujemy niesko�czono��
			else
			{
				t1 = result[t->indeks] + t->waga;				// je�li istnieje dodajemy jej wag�
				temp = t->indeks;
			}

			if (result[i] > t1)										// sprawdzenie czy znaleziona �cie�ka jest kr�tsza od ju� znanej
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
				autM[i][j] = NIESKON;					// nieistniej�ce kraw�dzie zast�pujemy niesko�czono�ciami
		}

		autM[i][i] = 0;
	}

	int temp, temp2;

	for (int i = 0; i < ile_w; ++i)									// wpisujemy do tablicy wynik�w warto�ci pocz�tkowe
		result[i] = autM[0][i];

	for (int i = 1; i < ile_w; i++)                               // przeszukiwanie kolejnych wierszy i kolumn 
	{
		for (int j = 0; j < ile_w; j++)
		{
			if (result[j] + autM[j][i] > INT_MAX)
				temp = NIESKON;										// je�li kraw�dz nieistnieje zapisujemy niesko�czono��
			else
			{
				temp = result[j] + autM[j][i];						// je�li istnieje dodajemy jej wag�
				temp2 = j;
			}

			if (result[i] > temp)								    // sprawdzenie czy znaleziona �cie�ka jest kr�tsza od ju� znanej
			{
				result[i] = temp;
				poprzednie[i] = temp2;
			}


		}
	}
	delete[] autM;
	return result;
}