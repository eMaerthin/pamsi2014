
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdlib> 
#include <fstream> 
#include <queue> 
#include <windows.h>


using namespace std;

class Graf
{
public:

	vector< vector<int> > lista;  
	vector< vector<int> > drzewo;    // do minimalnego drzewa rozpinajacego dla danego grafu 

	vector<int> kolory;  // kolorowanie wierzcholkow 
	vector<int> odleglosci;  // odleglosci ( Prim ) 
	vector<int> grupy;  // grupy ( Kruskal )

	vector<int> droga; // do wyznaczania wagi drogi 
	int liczbawierzcholkow;

	void wyswietl();
	void zmienwielkosc(int n);
	void prim();
	void naprawodl(int numer);   // dla Prima
	void kruskal();
	void naprawgrup(int grupa1, int grupa2);  // dla Kruskala  
	void sortowanie();
};

void Graf::sortowanie()
{
	int pom;
	for (int i = 0; i < lista.size() - 1; i++)
	{
		for (int j = 0; j<lista.size() - 1; j++)
		{
			if (lista[j][2]>lista[j + 1][2])
			{
				pom = lista[j][0];
				lista[j][0] = lista[j + 1][0];
				lista[j + 1][0] = pom;

				pom = lista[j][1];
				lista[j][1] = lista[j + 1][1];
				lista[j + 1][1] = pom;

				pom = lista[j][2];
				lista[j][2] = lista[j + 1][2];
				lista[j + 1][2] = pom;
			}
		}
	}
}

void Graf::naprawodl(int numer)
{
	for (int i = 0; i<lista.size(); i++)
	{
		if (lista[i][0] == numer)
		{
			if (odleglosci[lista[i][1]] > lista[i][2])  odleglosci[lista[i][1]] = lista[i][2];
		}
	}
}


void Graf::prim()
{

	kolory.resize(liczbawierzcholkow);
	odleglosci.resize(liczbawierzcholkow);

	for (int i = 0; i < liczbawierzcholkow; i++) kolory[i] = 0;
	for (int i = 0; i < liczbawierzcholkow; i++) odleglosci[i] = 99999;

	int waga = 0;
	int flaga = 1;
	waga += lista[0][2];

	kolory[lista[0][0]] = 1;
	kolory[lista[0][1]] = 1;

	naprawodl(lista[0][0]);
	naprawodl(lista[0][1]);

	while (flaga)
	{

		int najmniejsza = 99999;
		int numernajmniejsza = liczbawierzcholkow + 1;

		for (int i = 0; i < odleglosci.size(); i++)
		{
			if ((kolory[i] == 0) && (odleglosci[i] < najmniejsza))
			{
				najmniejsza = odleglosci[i];
				numernajmniejsza = i;
			}
		}

		kolory[numernajmniejsza] = 1;
		waga += odleglosci[numernajmniejsza];

		naprawodl(numernajmniejsza);

		flaga = 0;
		for (int i = 0; i < kolory.size(); i++) if (kolory[i] == 0) { flaga = 1; }
	}


	cout << " Waga minimalnego drzewa rozpinajacego wynosi " << waga << endl;
}

void Graf::naprawgrup(int grupa1, int grupa2)  // zamienia wszystkie z grupy 1 na grupe 2  
{
	for (int i = 0; i < grupy.size(); i++)
	{
		if (grupy[i] == grupa1) grupy[i] = grupa2;
	}
}

void Graf::kruskal()
{
	int waga = 0;
	int flaga = 1;
	int pom; // pomocnicza  
	kolory.resize(liczbawierzcholkow);
	grupy.resize(liczbawierzcholkow);

	for (int i = 0; i < liczbawierzcholkow; i++) kolory[i] = 0;
	for (int i = 0; i < liczbawierzcholkow; i++) grupy[i] = i;


	for (int i = 0; i < lista.size(); i++)
	{
		if ((grupy[lista[i][0]] != grupy[lista[i][1]]))
		{

			kolory[lista[i][0]] = 1;
			kolory[lista[i][0]] = 1;
			waga += lista[i][2];
			naprawgrup(grupy[lista[i][0]], grupy[lista[i][1]]);
			// cout<<lista[i][2]<<endl;
		}

	}


	cout << " Waga minimalnego drzewa rozpinajacego wynosi " << waga << endl;


}

//-------------------------------------------------------------
void Graf::zmienwielkosc(int n)
{
	lista.resize(n);
}


void Graf::wyswietl()   
{
	for (int i = 0; i < lista.size(); i++)
	{
		cout << lista[i][0] << " ";
		cout << lista[i][1] << " ";
		cout << lista[i][2] << " ";
		cout << endl;
	}
}
//--------------------------------------------------------------MAIN-------------------------------------------

int main()
{
	double diff;
	int wybor = 1, n, numer, ilosc;
	Graf graf;
	long long int ileTaktowUplynelo;
	long double ileMiliSekundUplynelo;
	LARGE_INTEGER taktPoczatku, taktKonca, taktowNaSekunde;
	QueryPerformanceFrequency(&taktowNaSekunde);
	fstream Plik("prima.txt", ios::out);              //plik do zaspisu czasow
	fstream Plik2("kruskala.txt", ios::out);

	while (wybor != 0)
	{
		cout << endl << " Co chcesz zrobic ? : " << endl;
		cout << " 1 - wczytanie z pliku " << endl;
		cout << " 2 - wypisanie listy " << endl;
		cout << " 3 - Algorytm PRIMA  " << endl;
		cout << " 4 - Algorytm KRUSKALA  " << endl;
		cout << " 0 - koniec " << endl;
		cin >> wybor;
		cout << endl;
		switch (wybor)
		{
		case 1:
		{
				  int rozmiar;
				  int pomocnicza;
				  ifstream plik;
				  plik.open("G_log.txt");
				  plik >> graf.liczbawierzcholkow;
				  plik >> rozmiar;
				  graf.zmienwielkosc(2 * rozmiar);
				  graf.lista.resize(2 * rozmiar);  // resize 

				  for (int i = 0; i < 2 * rozmiar; i++) graf.lista[i].resize(3);

				  for (int i = 0; i <= rozmiar; i++)
				  {
					  plik >> graf.lista[i][0];
					  plik >> graf.lista[i][1];
					  plik >> graf.lista[i][2];
				  }

				  for (int i = 0; i < rozmiar; i++)
				  {
					  graf.lista[rozmiar + i][0] = graf.lista[i][1];
					  graf.lista[rozmiar + i][1] = graf.lista[i][0];
					  graf.lista[rozmiar + i][2] = graf.lista[i][2];
				  }

				  //plik.close("danelista.txt");
				  break;
		}
		case 2:
		{
				  graf.wyswietl();
				  break;
		}
		case 3:
		{
				  if (Plik.good())
				  {
					  for (int i = 0; i < 100; i++)
					  {
						  graf.sortowanie();
						  // Zaczynamy liczyæ czas
						  QueryPerformanceCounter(&taktPoczatku);
						  graf.prim();
						  // Konczymy liczyc czas
						  QueryPerformanceCounter(&taktKonca);

						  ileTaktowUplynelo = taktKonca.QuadPart - taktPoczatku.QuadPart;
						  ileMiliSekundUplynelo = ((long double)ileTaktowUplynelo * 1000) / (long double)taktowNaSekunde.QuadPart;
						  int l = ileMiliSekundUplynelo;
						  cout << "Trwalo to: " << ileMiliSekundUplynelo << " ms" << endl;

						  Plik << ileMiliSekundUplynelo << endl;
					  }
					  Plik.flush();
				  }
				  Plik.close();

				  break;
		}
		case 4:
		{
				  if (Plik2.good())
				  {
					  for (int i = 0; i < 100; i++)
					  {
						  graf.sortowanie();
						  // Zaczynamy liczyæ czas
						  QueryPerformanceCounter(&taktPoczatku);
						  graf.kruskal();
						  // Konczymy liczyc czas
						  QueryPerformanceCounter(&taktKonca);

						  ileTaktowUplynelo = taktKonca.QuadPart - taktPoczatku.QuadPart;
						  ileMiliSekundUplynelo = ((long double)ileTaktowUplynelo * 1000) / (long double)taktowNaSekunde.QuadPart;
						  int l = ileMiliSekundUplynelo;
						  cout << "Trwalo to: " << ileMiliSekundUplynelo << " ms" << endl;

						  Plik2 << ileMiliSekundUplynelo << endl;
					  }
					  Plik2.flush();
				  }
				  Plik2.close();

				  break;
		}

		default: {break; }
		}
	}


	system("pause");

	return 0;
}
