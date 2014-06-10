#include "stdafx.h"

using namespace std;

// Funkcja do zapisu wynikow do pliku
void zapisz_wyniki(ofstream& p, krawedzie* wyniki, int ile)
{

	p << "Wyniki: " << endl << endl;
	p << "Wp Wk Waga" << endl;
	for (int i = 0; i < ile - 1; i++)
	{
		p << wyniki[i].p << "  " << wyniki[i].n << "  " << wyniki[i].waga << endl;
	}

	p << endl;

}

// Funkcja do zapisu wynikow do pliku
void zapisz_wyniki(ofstream& p, int* wyniki, int ile, int *poprzednie)
{
	int j = 1;
	p << "Wyniki: " << endl << endl;
	p << "Wp Wk Waga  Przez" << endl;
	for (int i = 0; i < ile; i++)
	{
		j = i;
		p << "0  " << i << "  " << wyniki[i] << "    ";
		while (poprzednie[j] != -1 && j < ile)
		{
			p << poprzednie[j] << " ";
			j = poprzednie[j];
		}
		p << endl;
	}

	p << endl;
}

// Generowanie grafow z roznymi gestosciami i zapis do pliku w postaci macierzy sasiedztwa
void wygeneruj(int wierzcholki, int ilosc)
{
	graf_macierz G(wierzcholki);
	fstream dane;
	dane.open("dane.txt", fstream::out, fstream::trunc);
	if (!dane.good())
	{
		cout << "Nie mogê otworzyæ pliku";
		exit(1);
	}
	else
	{
		cout << "Generator: 1 z 4 " << endl;
		dane << "Liczba wierzcholkow : " << wierzcholki << endl;
		dane << "ilosc : " << ilosc << endl;
		dane << "gestosc : 25" << endl << endl;
		for (int i = 0; i < ilosc; ++i)
		{
			G.wyczysc();
			G.wylosuj(25);
			for (int i = 0; i<G.v; i++)
			{
				for (int j = 0; j<G.v; j++)
					dane << G.macierz_wag[i][j] << " ";
				dane << endl;
			}
			dane << endl;
		}

		cout << "Generator: 2 z 4" << endl;
		dane << "Liczba wierzcholkow : " << wierzcholki << endl;
		dane << "ilosc : " << ilosc << endl;
		dane << "gestosc : 50" << endl << endl;
		for (int i = 0; i < ilosc; ++i)
		{
			G.wyczysc();
			G.wylosuj(50);
			for (int i = 0; i<G.v; i++)
			{
				for (int j = 0; j<G.v; j++)
					dane << G.macierz_wag[i][j] << " ";
				dane << endl;
			}
			dane << endl;
		}

		cout << "Generator: 3 z 4" << endl;
		dane << "Liczba wierzcholkow : " << wierzcholki << endl;
		dane << "ilosc : " << ilosc << endl;
		dane << "gestosc : 75" << endl << endl;
		for (int i = 0; i < ilosc; ++i)
		{
			G.wyczysc();
			G.wylosuj(75);
			for (int i = 0; i<G.v; i++)
			{
				for (int j = 0; j<G.v; j++)
					dane << G.macierz_wag[i][j] << " ";
				dane << endl;
			}
			dane << endl;
		}

		cout << "Generator: 4 z 4" << endl;
		dane << "Liczba wierzcholkow : " << wierzcholki << endl;
		dane << "ilosc : " << ilosc << endl;
		dane << "gestosc : 100" << endl << endl;
		for (int i = 0; i < ilosc; ++i)
		{
			G.wyczysc();
			G.wylosuj(100);
			for (int i = 0; i<G.v; i++)
			{
				for (int j = 0; j<G.v; j++)
					dane << G.macierz_wag[i][j] << " ";
				dane << endl;
			}
			dane << endl;
		}
	}
	dane.flush();
	dane.close();
}

// Przetwarzanie danych wygenerowanych do pliku dane.txt, wyliczenie czasow dzialania algorytmow i zapis do plikow
void przetworzdane()
{
	krawedzie *wyniki;
	int wierzcholki, ilosc;
	int gestosc = 0;
	int *wyniki2;
	ofstream plik[4];
	fstream dane;
	float czas[4] = { 0, 0, 0, 0 };
	unsigned __int64 freq, counterStart, counterStop;

	dane.open("dane.txt");
	plik[0].open("dijkstra_macierz.txt", ios::out);
	plik[1].open("dijkstra_lista.txt", ios::out);
	plik[2].open("bellford_macierz.txt", ios::out);
	plik[3].open("bellford_lista.txt", ios::out);


	for (int i = 0; i < 4; ++i)
	{
		cout << "Przetwarzanie: " << i + 1 << " z 4" << endl;
		gestosc = 0;
		dane.ignore(256, ':');
		dane >> wierzcholki;
		dane.ignore(256, ':');
		dane >> ilosc;
		dane.ignore(256, ':');
		dane >> gestosc;

		for (int i = 0; i < ilosc; i++)
		{
			int *poprzednie = new int[wierzcholki];
			for (int i = 0; i < wierzcholki; ++i)
				poprzednie[i] = -1;

			int** tmp = new int*[wierzcholki];
			for (int i = 0; i < wierzcholki; i++)
				tmp[i] = new int[wierzcholki];

			for (int i = 0; i<wierzcholki; i++)
			{
				for (int j = 0; j<wierzcholki; j++)
					dane >> tmp[i][j];
			}

			graf_macierz M(tmp, wierzcholki);
			graf_lista L(wierzcholki);
			graf_macierz M2(wierzcholki);
			M2.wyczysc();

			L.konwertuj(M.macierz_wag);

			if (CZYWYNIKI == 1)
			{
				M.wypisz_do_pliku(plik[0]);
				L.wypisz_do_pliku(plik[1]);
				M.wypisz_do_pliku(plik[2]);
				L.wypisz_do_pliku(plik[3]);
			}

			QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER*> (&freq));
			QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*> (&counterStart));

			wyniki2 = dijkstra(M.macierz_wag, M.v, poprzednie);

			QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*> (&counterStop));
			czas[0] += (static_cast<float> (counterStop)-counterStart) / freq * 1000;

			if (CZYWYNIKI == 1)
				zapisz_wyniki(plik[0], wyniki2, M.v, poprzednie);

			for (int i = 0; i < wierzcholki; ++i)
				poprzednie[i] = -1;

			QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER*> (&freq));
			QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*> (&counterStart));

			wyniki2 = dijkstra(L.list, L.v, poprzednie);

			QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*> (&counterStop));
			czas[1] += (static_cast<float> (counterStop)-counterStart) / freq * 1000;

			if (CZYWYNIKI == 1)
				zapisz_wyniki(plik[1], wyniki2, L.v, poprzednie);

			for (int i = 0; i < wierzcholki; ++i)
				poprzednie[i] = -1;

			QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER*> (&freq));
			QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*> (&counterStart));

			wyniki2 = bell_Ford(M.macierz_wag, M.v, poprzednie);

			QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*> (&counterStop));
			czas[2] += (static_cast<float> (counterStop)-counterStart) / freq * 1000;

			if (CZYWYNIKI == 1)
				zapisz_wyniki(plik[2], wyniki2, M.v, poprzednie);

			for (int i = 0; i < wierzcholki; ++i)
				poprzednie[i] = -1;

			QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER*> (&freq));
			QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*> (&counterStart));

			wyniki2 = bell_Ford(L.list, L.v, poprzednie);

			QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*> (&counterStop));
			czas[3] += (static_cast<float> (counterStop)-counterStart) / freq * 1000;

			if (CZYWYNIKI == 1)
				zapisz_wyniki(plik[3], wyniki2, L.v, poprzednie);

			delete tmp;
			delete poprzednie;
		}

		//Wypisanie czasow do pliku
		for (int i = 0; i < 4; ++i)
		{
			plik[i] << "Czas dla gestosci " << gestosc << " % wynosi : " << czas[i] / ilosc << endl
				<< endl << "*-*-*-*-*-*-*-*-*-*-**-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl << endl;
			czas[i] = 0;
		}

	}

	// Zamykanie plikow
	for (int i = 0; i < 4; ++i)
		plik[i].close();
}