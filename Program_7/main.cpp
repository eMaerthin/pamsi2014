#include <iostream>
#include <list>
#include <time.h>
#include <fstream>
#include <cstdlib>
#include <windows.h>

using namespace std;

int main()
{
	int fmax, cp, v1, v2, esc;
	list <int> q;
	int liczbawierzcholkow, liczbakrawedzi, zrodlo, ujscie;

	long long int ileTaktowUplynelo;
	long double ileMiliSekunduplynelo;
	LARGE_INTEGER taktPoczatku, taktKonca, taktowNaSekunde;
	QueryPerformanceFrequency(&taktowNaSekunde);

	ifstream Plik;
	Plik.open("2k100-35.txt");

	Plik >> liczbawierzcholkow;
	Plik >> liczbakrawedzi;
	Plik >> zrodlo;
	Plik >> ujscie;


	// C[][] - przepustowosci krawedzi
	// F[][] - przeplywy w krawedziach
	int** C = new int*[liczbawierzcholkow + 1];
	for (int i = 0; i < liczbawierzcholkow + 1; i++)
		C[i] = new int[liczbawierzcholkow + 1];

	int** F = new int*[liczbawierzcholkow + 1];
	for (int i = 0; i < liczbawierzcholkow + 1; i++)
		F[i] = new int[liczbawierzcholkow + 1];

	// p[]   - poprzednicy na sciezkach tworzonych przez BFS
	// cfp[] - przepustowosc sciezek

	int* p = new int[liczbawierzcholkow + 1];
	int* cfp = new int[liczbawierzcholkow + 1];


	for (int i = 1; i <= liczbawierzcholkow; i++)
	for (int j = 1; j <= liczbawierzcholkow; j++) F[i][j] = C[i][j] = 0;


	for (int i = 1; i <= liczbakrawedzi; i++)
	{
		Plik >> v1 >> v2 >> cp;
		C[v1][v2] = cp;
	}


	//**************************************************
	//** algorytm Edmondsa-Karpa                      **
	//**************************************************

	/*** Zaczynam liczyc czas dzialania algorytmu ******/
	QueryPerformanceCounter(&taktPoczatku);

	fmax = 0;

	do
	{
		for (int i = 1; i <= liczbawierzcholkow; i++) p[i] = 0;

		p[zrodlo] = -1;
		cfp[zrodlo] = MAXINT;
		q.clear(); q.push_back(zrodlo);

		esc = 0;
		while (q.size())
		{
			v1 = q.front(); q.pop_front();
			for (v2 = 1; v2 <= liczbawierzcholkow; v2++)
			{
				cp = C[v1][v2] - F[v1][v2];
				if (cp && !p[v2])
				{
					p[v2] = v1;
					cfp[v2] = cfp[v1] > cp ? cp : cfp[v1];
					if (v2 == ujscie)
					{
						fmax += cfp[ujscie];
						while (v2 != zrodlo)
						{
							v1 = p[v2];
							F[v1][v2] += cfp[ujscie];
							F[v2][v1] -= cfp[ujscie];
							v2 = v1;
						} //while(y != s)
						esc = 1; break;

					} //if(y == t)

					q.push_back(v2);

				} //if(cp && !p[y])     

			} // for(y = 1; y <= n; y++)

			if (esc) break;

		} //while(q.size())

		if (!esc) break;
	} while (true);

	/************  Koncze liczyc czas   ********************/
	QueryPerformanceCounter(&taktKonca);

	ileTaktowUplynelo = taktKonca.QuadPart - taktPoczatku.QuadPart;
	ileMiliSekunduplynelo = ((long double)ileTaktowUplynelo * 1000) / (long double)taktowNaSekunde.QuadPart;
	int czas = ileMiliSekunduplynelo;


	for (v1 = 1; v1 <= liczbawierzcholkow; v1++)
	for (v2 = 1; v2 <= liczbawierzcholkow; v2++)
	if (C[v1][v2])
		cout << v1 << " -> " << v2 << " " << F[v1][v2] << "/" << C[v1][v2] << endl;

	cout << endl;
	cout << "\nfmax = " << fmax << endl << endl;
	cout << "Czas dzialania algorytmu: " << czas << endl;

	system("PAUSE");
	return 0;
}
