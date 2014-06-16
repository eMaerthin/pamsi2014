#include <iostream> 
#include <conio.h> 
#include <windows.h>
#include <random>
#include <queue>

using namespace std;

int* tablica;        //tablica przechowuj�ca odleg�o�ci od wierzcho�ka z do pozosta�ych 

class Wierzcholek    //klasa przechowuj�ca dane wierzcho�ka 
{
public:
	int cel, waga;
	Wierzcholek* next;
	Wierzcholek()
	{
		next = NULL;
	}
};
class Lista        //klasa przechowuj�ca wska�niki do obiekt�w klasy Wierzcho�ek 
{
public:
	Wierzcholek *V1, *V2;
	Lista()
	{
		V1 = V2 = NULL;
	}
};
Lista* graf;
class Porzadkuj        // sortowanie wierzcholkow
{
public:
	bool operator()(const int& v1, const int &v2)
	{
		if (tablica[v1]>tablica[v2])
			return true;
		return false;
	}
};
int main()
{
	int liczbawierzcholkow, liczbakrawedzi, v1, v2, koszt, z;

	long long int ileTaktowUplynelo;
	long double ileMiliSekunduplynelo;
	LARGE_INTEGER taktPoczatku, taktKonca, taktowNaSekunde;
	QueryPerformanceFrequency(&taktowNaSekunde);

	cout << "Podaj liczbe wierzcholkow: "; cin >> liczbawierzcholkow;
	graf = new Lista[liczbawierzcholkow + 1];
	cout << "Podaj liczbe krawedzi: "; cin >> liczbakrawedzi;
	cout << "wierzcholek dla ktorego chcesz obliczyc odleglosci: ";	cin >> z;
	Wierzcholek* wskaznik;
	int procent;
	cout << "Podaj % g�stosci grafu: " << endl;
	cin >> procent;
	int k = (liczbawierzcholkow * procent)/100;

	for (int i = 0; i<k; i++)    //wczytanie danych 
	{
		wskaznik = new Wierzcholek;
		v1 = rand() % liczbawierzcholkow + 1;
		v2 = rand() % liczbawierzcholkow + 1;

		koszt = rand() % 500 + 1;

		if (graf[v1].V1 == NULL)
			graf[v1].V1 = graf[v1].V2 = wskaznik;
		else
		{
			graf[v1].V2->next = wskaznik;
			graf[v1].V2 = wskaznik;
		}
		wskaznik->cel = v2;
		wskaznik->waga = koszt;
		if (v1 != v2)
		{
			wskaznik = new Wierzcholek;
			if (graf[v2].V1 == NULL)
				graf[v2].V1 = graf[v2].V2 = wskaznik;
			else
			{
				graf[v2].V2->next = wskaznik;
				graf[v2].V2 = wskaznik;
			}
			wskaznik->cel = v1;
			wskaznik->waga = koszt;
		}
	}


	/*** Zaczynam liczyc czas dzialania algorytmu ******/
	QueryPerformanceCounter(&taktPoczatku);

	tablica = new int[liczbawierzcholkow + 1];
	const int MAX = 32000;
	for (int i = 1; i < liczbawierzcholkow + 1; i++)    //wype�nienie tablicy sta�� MAX 
		tablica[i] = MAXINT;
	tablica[z] = 0;        //odleg�o�� od z do z wynosi 0 
	priority_queue<int, vector<int>, Porzadkuj> kolejka; //utworzenie kolejki 
	kolejka.push(z);    //wstawienie do kolejki wierzcho�ka z 
	for (; !kolejka.empty();) //wykonuj dop�ki kolejka nie jest pusta 
	{
		int v = kolejka.top();    //pobranie wierzcho�ka... 
		kolejka.pop();        //...i usuni�cie go z kolejki 
		wskaznik = graf[v].V1;
		while (wskaznik != NULL)    //przej�cie po wszystkich wierzcho�kach s�siednich do v 
		{
			if (tablica[wskaznik->cel] > tablica[v] + wskaznik->waga) //sprawdzenie odleg�o�ci 
			{
				tablica[wskaznik->cel] = tablica[v] + wskaznik->waga;
				kolejka.push(wskaznik->cel);
			}
			wskaznik = wskaznik->next;
		}
	}


	/************  Koncze liczyc czas   ********************/
	QueryPerformanceCounter(&taktKonca);
	ileTaktowUplynelo = taktKonca.QuadPart - taktPoczatku.QuadPart;
	ileMiliSekunduplynelo = ((long double)ileTaktowUplynelo * 1000) / (long double)taktowNaSekunde.QuadPart;
	int czas = ileMiliSekunduplynelo;

	cout << "Czas " << ": " << czas << endl;

	for (int i = 1; i<liczbawierzcholkow + 1; i++) //wy�wietlenie wynik�w 
	if (tablica[i] == MAXINT)
		cout << "-\t";
	else
		cout << tablica[i] << "\t";

	system("PAUSE");

	return 0;
}

