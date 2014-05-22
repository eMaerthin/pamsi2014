#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <random>
#include <windows.h>


using namespace std;

/*******************************************************************************************/
/* Kilka uwag*/
/* Rozklady dzialaja, to znaczy generuja liczby, jednak nie dalam rady zrobic przyjaznego interfejsu dla*/
/* uzytkownika, dlatego aby zmienic rodzaj sortowania dla tablicy trzeba komentowac odpowiednie fragmenty*/
/* programu i usuwac komentarze rozkladow*/
/*********************************************************************************************/


int sortowanie_babelkowe(int rozmiar)
{
	int f = rozmiar *0.5;									// 0.9, 0.99
	int e = rozmiar-f;
	int* liczba_sortuj = new int[e];
	int* kopiec = new int[f];
	int* liczba = new int[rozmiar];

	long long int ileTaktowUplynelo;
	long double ileMiliSekundUplynelo;
	LARGE_INTEGER taktPoczatku, taktKonca, taktowNaSekunde;
	QueryPerformanceFrequency(&taktowNaSekunde);
	
    /************************** rozklad poissona*/
//	default_random_engine generator;
//	poisson_distribution<int> distribution1(rozmiar);
//	for (int i = 0; i < rozmiar; i++)
//		liczba[i] = distribution1(generator);

	/************************* rozklad normalny*/
//	default_random_engine generator;
//	normal_distribution<double> distribution1(50.0, 15.0);
//	for (int i = 0; i < rozmiar; i++)
//		liczba[i] = distribution1(generator);
	/************************* rozklad jednostajny*/
//	default_random_engine generator;
//	uniform_int_distribution<int> distribution1(0, 100);
//	for (int i = 0; i < rozmiar; i++)
//		liczba[i] = distribution1(generator);

	srand(time(NULL));
	for (int i = 0; i < e; i++)
		liczba_sortuj[i] = rand() % e;

	for (int i = 0; i < f; i++)
		kopiec[i] = rand() % f;

	for (int j = f; j >= 0; j--)
	{
		int x = kopiec[j];
		int i = j + 1;
		while ((i < f) && (x > kopiec[i]))
		{
			kopiec[i - 1] = kopiec[i];
			i++;
		}
		kopiec[i - 1] = x;
	}

	for (int j = 0; j < rozmiar; j++)
	{
		if (j < e)
			liczba[j] = liczba_sortuj[j];
		else
			liczba[j] = kopiec[j - e];
	}

	/************  Zaczynam liczyc czas sortowanie  ********************/

	QueryPerformanceCounter(&taktPoczatku);

	int trzymaj;
	int n = rozmiar;
	do{
		for (int j = 0; j < n - 1; j++)
		{
			if (liczba[j] > liczba[j + 1])
			{
				trzymaj = liczba[j + 1];
				liczba[j + 1] = liczba[j];
				liczba[j] = trzymaj;
			}
		}n--;
	} while (n > 1);

	
	/************  Koncze liczyc czas sortowanie  ********************/

	QueryPerformanceCounter(&taktKonca);

	ileTaktowUplynelo = taktKonca.QuadPart - taktPoczatku.QuadPart;
	ileMiliSekundUplynelo = ((long double)ileTaktowUplynelo * 1000) / (long double)taktowNaSekunde.QuadPart;
	int l = ileMiliSekundUplynelo;
	cout << "Trwalo to: " << ileMiliSekundUplynelo << " ms" << endl;


	//	delete[]liczba_sortuj;

	return 0;
}

int sortowanie_przez_wybieranie(int rozmiar)
{
	int f = rozmiar *0.5;							// 0.9, 0.99
	int e = rozmiar-f;
	int* wybieranie = new int[e];
	int* kopiec = new int[f];
	int* liczba = new int[rozmiar];

	int x, i;
	long long int ileTaktowUplynelo;
	long double ileMiliSekundUplynelo;
	LARGE_INTEGER taktPoczatku, taktKonca, taktowNaSekunde;
	QueryPerformanceFrequency(&taktowNaSekunde);

	srand(time(NULL));
	for (int i = 0; i < e; i++)
		wybieranie[i] = rand() % e;

	for (int i = 0; i < f; i++)
		kopiec[i] = rand() % f;

	for (int j = f; j >= 0; j--)
	{
		int x = kopiec[j];
		int i = j + 1;
		while ((i < f) && (x > kopiec[i]))
		{
			kopiec[i - 1] = kopiec[i];
			i++;
		}
		kopiec[i - 1] = x;
	}
	

	for (int j = 0; j < rozmiar; j++)
	{
		if (j < e)
			liczba[j] = wybieranie[j];
		else
			liczba[j] = kopiec[j-e];
	}



/////////////////////////////////////////////////////////
	QueryPerformanceCounter(&taktPoczatku);

	for (int j = rozmiar; j >= 0; j--)
	{
		x = liczba[j];
		i = j + 1;
		while ((i < rozmiar) && (x > liczba[i]))
		{
			liczba[i - 1] = liczba[i];
			i++;
		}
		liczba[i - 1] = x;
	}

	QueryPerformanceCounter(&taktKonca);
//////////////////////////////////////////////////////////

	ileTaktowUplynelo = taktKonca.QuadPart - taktPoczatku.QuadPart;
	ileMiliSekundUplynelo = ((long double)ileTaktowUplynelo * 1000) / (long double)taktowNaSekunde.QuadPart;

	cout << "Trwalo to: " << ileMiliSekundUplynelo << " ms" << endl;


	//	delete[]liczba;

	return 0;

}

int sortowanie_przez_kopcowanie(int rozmiar)
{
	int f = rozmiar *0.5;					// 0.9, 0.99
	int e = rozmiar - f;
	int* kopiec = new int[f];
	int* tablica1 = new int[e];
	int* liczba = new int[rozmiar];

	int j, k, x;
	long long int ileTaktowUplynelo;
	long double ileMiliSekundUplynelo;
	LARGE_INTEGER taktPoczatku, taktKonca, taktowNaSekunde;
	QueryPerformanceFrequency(&taktowNaSekunde);

	for (int i = 0; i < e; i++)
		tablica1[i] = rand() % e;

	for (int i = 0; i < f; i++)
		kopiec[i] = rand() % f;

	for (int j = f; j >= 0; j--)
	{
		int x = kopiec[j];
		int i = j + 1;
		while ((i < f) && (x > kopiec[i]))
		{
			kopiec[i - 1] = kopiec[i];
			i++;
		}
		kopiec[i - 1] = x;
	}


	for (int j = 0; j < rozmiar; j++)
	{
		if (j < e)
			liczba[j] = tablica1[j];
		else
			liczba[j] = kopiec[j - e];
	}

/////////////////////////////////////////////////////
	QueryPerformanceCounter(&taktPoczatku);

	for (int i = 2; i < rozmiar; i++)
	{
		j = i;
		k = j / 2;
		x = liczba[i];
		while ((k > 0) && (liczba[k] < x))
		{
			liczba[j] = liczba[k];
			j = k;
			k = j / 2;
		}
		liczba[j];
	}
///////////////////////////////////////////////////////
	QueryPerformanceCounter(&taktKonca);

	ileTaktowUplynelo = taktKonca.QuadPart - taktPoczatku.QuadPart;
	ileMiliSekundUplynelo = ((long double)ileTaktowUplynelo * 1000) / (long double)taktowNaSekunde.QuadPart;

	cout << "Trwalo to: " << ileMiliSekundUplynelo << " ms" << endl;


	//	delete[]kopiec;

	return 0;
}


int main()
{
	int opcja;
	int rozmiar;
	int wielkosc = 10;
	cout << " Witaj ile elementow ma miec tablica? " << endl << " >100" << endl;
	cin >> rozmiar;
	int* liczba = new int[rozmiar];
	cout << " Jaki rodzaj sortowania chcesz zastosowac? " << endl;
	cout << " 0 - sortowanie babelkowe " << endl;
	cout << " 1 - sortowanie przez wybieranie " << endl;
	cout << " 2 - sortowanie przez kopcowanie " << endl;
	cin >> opcja;
	switch (opcja)
	{
	case 0:
		for (int i = 0; i < wielkosc; i++)
			sortowanie_babelkowe(rozmiar);

		break;
	case 1:
		for (int i = 0; i < wielkosc; i++)
			sortowanie_przez_wybieranie(rozmiar);

		break;
	case 2:
		for (int i = 0; i < wielkosc; i++)
			sortowanie_przez_kopcowanie(rozmiar);

		break;
	default: cout << "\n------- Zla opcja -------\n";
		break;
	}

	system("PAUSE");

	return 0;

}