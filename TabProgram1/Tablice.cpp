#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int* WczTab(int* t, int iR)
{
	int a;
	cout << endl;
	for (int i = 0; i < iR; i++)
	{	
		cout << "Podaj wartoœci do tablicy" << endl;
		cin >> a;
		t[i] = a;
	}
	
	return t;
		}

void WysTab(int *t, int iR)
{
	cout << "Wczytana tablica :" << endl;
	for (int i = 0; i < iR; i++)
	{
		cout << t[i]<< " ";
	}

	cout << endl;

}

void ZapPlTekst(int *t, int iR)
{
	
	fstream plik;
	plik.open("tab.txt", ios::out);
	for (int i = 0; i < iR; i++)
	{
		plik << *t++ << " ";
	}
	plik.close();

}

void WczPlTekst(int t[], int iR)

{

	ifstream liczby("tab.txt");

	if (!liczby)
	{
		cout << "Plik nie istnieje";
		getchar();
	}
	int a = 0;
	while (!liczby.eof())
		liczby >> t[a++];

	liczby.close();
	
}

void ZapPlBin(int *t, int iR)
{
	fstream plik("tab.dat", ios::out | ios::binary);
	for (int i = 0; i < iR; i++)
	{
		plik << *t++<< " ";
	}
	plik.close();

}

void WczPlBin(int *t, int iR)
{
	ifstream liczby("tab.dat");

	if (!liczby)
	{
		cout << "Plik nie istnieje";
		getchar();
	}
	int a = 0;
	while (!liczby.eof())
		liczby >> t[a++];

	liczby.close();
}

int* WypLos(int *t, int iR)
{
	srand((unsigned)time(NULL));
	cout << "Iloma liczbami losowymi wypelnic tablice ??" << endl;
	cin >> iR;
	for (int i = 0; i < iR; i++)
	{
		t[i] = rand()%100;
	}
	return t;
}

int* DynKoTab(int *t, int iR)
{
	int *tab2;
	tab2 = new int[iR];
	for (int i = 0; i < iR; i++)
	{
		tab2[i]=t[i];
	}
	WysTab(tab2, iR);
	return tab2;
}


int main(){

	const int iR=5;
	int* tab2;
	int tab[iR];
	int opcja;
	

	do{
		cout << endl;
		cout << "1.Wczytanie tablicy z konsoli" << endl;
		cout << "2.Wyswietlenie tablicy" << endl;
		cout << "3.Zapisywanie do pliku tekstowego" << endl;
		cout << "4.Wczytywanie z pliku tekstowego" << endl;
		cout << "5.Zapisywanie do pliku binarnego" << endl;
		cout << "6.Wczytywanie z pliku binarnego" << endl;
		cout << "7.Wypelnianie tablicy" << endl;
		cout << "8.Tworzenie dynamicznej kopii + wyswietlenie kopii" << endl;
		cout << "0.Koniec" << endl;
		cout << "Wybierz opcjê" << endl;
			cin >> opcja;
		switch (opcja)
		{
		case 0: 
		
			break;

		case 1: 
			WczTab(tab, iR);
		break;

		case 2:
			WysTab(tab, iR);
		break;

		case 3:
			ZapPlTekst(tab, iR);
			break;

		case 4:
			WczPlTekst(tab, iR);
		break;

		case 5:
			ZapPlBin(tab, iR);
			break;

		case 6:
			WczPlBin(tab, iR);
			break;

		case 7:
			WypLos(tab, iR);
			break;

		case 8:
			tab2 = DynKoTab(tab, iR);
			break;
		}
	} while (opcja != 0);
}