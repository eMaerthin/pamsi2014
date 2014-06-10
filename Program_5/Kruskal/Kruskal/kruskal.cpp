#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<time.h>
#include<list>
#include<windows.h>
#include<fstream>

using namespace std;

class Krawedz //klasa przechowuje krawedzie
{
public:
	int waga; //waga krsawedzi
	int w1; //1 koniec krawedzi
	int w2;	//2 koniec krawedzi
	void DodajKrawedzie(int pom, int pom2, int pom3);
};

void Krawedz::DodajKrawedzie(int pom, int pom2, int pom3) //dodaje krawedz
{
	waga = pom;
	w1 = pom2;
	w2 = pom3;
}



class Graf
{
public:
	int *graf; //tablica przechowujaca informacje o grafie w postaci macierzy wag
	Krawedz *krawedzie; //tablica krawedzi
	Graf(int V, int E);
	~Graf(){};
	void Wypelnij(int V, int E);
	void Wypisz(int V);
	void Posortuj(int pocz, int kon, int E);
	void Pelny(int V); //tworzy graf pelny (oszczedzajac czas)

};

Graf::Graf(int V, int E) //inicjalizuje graf
{
	graf = new int[V*V];
	krawedzie = new Krawedz[E];
	for (int i = 0; i < V*V; i++)
		graf[i] = -1; // wype³animy -1
}

void Graf::Pelny(int V)
{
	int pom2, pom3, pom, i, j;
	i = 0;
	j = 0;
	while (j<(V*V) / 2) //wypelnia macierz wag losowymi
	{
		pom = 1 + rand() % 9;
		pom2 = i%V; //przeliczamy numer elementu z tablicy na 
		pom3 = abs((i - pom2) / V); // 2 osobne krawedzie
		if (pom3>pom2)
		{
			graf[i] = pom;
			if (pom2 != pom3) //jesli nie jest to krawedz na glownej przekatnej macierzy grafu 
			{
				graf[V*pom2 + pom3] = pom;
			}
			Krawedz k;
			k.DodajKrawedzie(pom, pom2, pom3);
			krawedzie[j] = k;
			j = j + 1;
		}
		i = i + 1;
	}
}

void Graf::Wypelnij(int V, int E) //wypelnia graf
{
	int* tab = new int[E];
	int i, j, l, pom2, pom3;
	bool tmp;

	srand((int)time(NULL));
	l = 0;
	do //do momentu az bedziemy mieli okraslona ilosc krawedzi
	{
		j = rand() % (V*V); //losuje liczbe od 0 do V^2 -1
		tmp = true;
		for (i = 0; i < l; i++)
		{
			pom2 = j%V;
			pom3 = abs((j - pom2) / V);
			if (tab[i] == j) //jesli dana krawedz juz byla zwraca falsz
			{
				tmp = false;
				break;
			}
			else if (pom2 == pom3) //gdy krawedz na glownej przekatnej macierzy
			{
				tmp = false;
				break;
			}
			else if ((pom3 == tab[i] % V) && (pom2 == abs((tab[i] - tab[i] % V) / V))) //jesli dana krawedz juz byla zwraca falsz
			{
				tmp = false;
				break;
			}
			else if (pom2*V + pom3 == tab[i]) //jesli dana krawedz juz byla zwraca falsz
			{
				tmp = false;
				break;
			}

		}
		if (tmp) //gdy tmp zwraca true
			tab[l++] = j;

	} while (l < E);

	for (i = 0; i < E; i++) //wypelnianie wylosowanych krawezi
	{
		int pom;
		pom = 0 + rand() % E;//losujemy wage od 1 do 9
		graf[tab[i]] = pom; //w wylosowana wczesniej krawedz dodajemy wage
		pom2 = tab[i] % V; //przeliczamy numer elementu z tablicy na 
		pom3 = abs((tab[i] - pom2) / V); //dwie osobne krawedzie
		graf[pom2*V + pom3] = pom; //dodajemy wage w krawedz rowniez po 2 stronie przekatnej macierzy
		Krawedz k;
		k.DodajKrawedzie(pom, pom2, pom3);
		krawedzie[i] = k;
	}
	delete[] tab;
}

void Graf::Wypisz(int V) //wypisujemy graf w formie macierzy
{
	for (int i = 0; i < V*V; i++)
	{
		if (i%V == 0)
			cout << endl;
		cout << graf[i] << " ";
	}
}

void Graf::Posortuj(int pocz, int kon, int E)
{
	int srodek, pom1, pom2, i;
	Krawedz* k = new Krawedz[E];
	srodek = (pocz + kon + 1) / 2; //Wyszukuje srodek tablicy
	if (srodek - pocz > 1) Posortuj(pocz, srodek - 1, E); //jesli zbior ma wiecej niz 1 element (1 polowa)
	if (kon - srodek > 0)  Posortuj(srodek, kon, E);  //jesli zbior ma wiecej niz 1 element (2 polowa)
	pom1 = pocz;
	pom2 = srodek;
	for (i = pocz; i <= kon; i++)
	if ((pom1 == srodek) || ((pom2 <= kon) && (krawedzie[pom1].waga > krawedzie[pom2].waga))) //jesli mamy 1 element lub element pierwszy pierwszej polowy tablicy jest wiekszy od pierwszego 2 polowy tablicy
		k[i] = krawedzie[pom2++];
	else
		k[i] = krawedzie[pom1++];
	for (i = pocz; i <= kon; i++)//pzepisanie tablicy pomocniczej na glowna
		krawedzie[i] = k[i];

	delete k;
}

int  Kruskala(int V, int E, Graf g)
{
	int* tmp = new int[V];
	int j, w1, w2, pom1;
	int suma = 0; //zapamietuje ilosc krawedzi ktore trzeba dodac aby wszystkie wierzcholki wchodzily w sklad grafu
	Krawedz *pom; //tablica pomocnicza krawedzi
	pom = new Krawedz[E];
	for (int i = 0; i < V; i++) //uzupelniamy pomocnicza tablice -1 bedzie ona sluzyla do sprawdzania czy dane wierzcholki nie zostaly juz jakos polaczone
		tmp[i] = -1;
	j = 0;

	while (j < E) //dopuki nie skoncza sie krawedzie
	{
		w1 = g.krawedzie[j].w1; //1 wierzcholek danej krawedzi
		w2 = g.krawedzie[j].w2; //2 wierzcholek danej krawedzi
		j = j + 1;
		if (tmp[w1] == -1 || tmp[w2] == -1 || tmp[w1] != tmp[w2]) //jesli -1 oznacza to ze dany wierzcholek jeszcze nie zostal dolaczony jesli 2 wierzcholki rozne od siebie oznacza ze nie sa one jeszcze ze soba polaczone
		{
			suma = suma + 1;
			pom[suma] = g.krawedzie[j - 1]; //przepisujemy krawedz do zmiennej pomocniczej
			if (tmp[w1] == -1 && tmp[w2] != -1) //jesli jeden wierzcholek jest dodany a 2 nie jest
			{
				pom1 = w1;
				w1 = w2;
				w2 = pom1;
			}
			if (tmp[w1] == -1) //jesli wierzcholek nie byl wczesniej dodany
				tmp[w1] = w1; //przypisujemy miejscu w tablicy pomocniczej wartosc tego wierzcholka aby bylo widac ze juz jest jakos polaczony
			if (tmp[w2] == -1) //jesli wierzcholek 2 danej krawedzi nie byl wczesniej dodany
				tmp[w2] = tmp[w1]; //przypisujemy mu ta samom wartosc co 1 aby mozna bylo sprawdzic czy podobna krawedz (ale o innej wadze) nie byla juz dodana
			else  //jesli wierzcholek 2 byl dodany
			{
				pom1 = tmp[w2];
				for (int i = 0; i < V; i++)
				if (tmp[i] == pom1)
					tmp[i] = tmp[w1];
			}
		}
	}
	delete tmp;
	return suma;
}


int main()
{
	int V, E, tmp;
	int i = 0;
	long long int ileTaktowUplynelo;
	long double ileMiliSekundUplynelo;
	LARGE_INTEGER taktPoczatku, taktKonca, taktowNaSekunde;
	QueryPerformanceFrequency(&taktowNaSekunde);

	V = 10;
	fstream Plik("kruskala.txt", ios::out);              //plik do zaspisu czasow
	int suma = 0;
	int gestosc = 10;
	cout << endl;
	E = V*(V - 1)*gestosc / 100 / 2;
	cout << E << endl;
	Graf g(V, E);
	if (gestosc != 100)
		g.Wypelnij(V, E);
	else
		g.Pelny(V);
	//	g.Wypisz(V);
	if (Plik.good())
	{
		for (i = 0; i < 100; i++) //wywoluje algorytm kruskala 100 razy i zapisuje te czasy do pliku
		{
			srand(time(NULL));
			int k = 0;
			// Zaczynamy liczyæ czas
			QueryPerformanceCounter(&taktPoczatku);
			g.Posortuj(0, E - 1, E);
			for (i = 0; i < E; i++)
			{
				cout << endl << g.krawedzie[i].w1 << "-" << g.krawedzie[i].w2 << " waga: " << g.krawedzie[i].waga;
			}
			tmp = Kruskala(V, E, g);
			// Konczymy liczyc czas
			QueryPerformanceCounter(&taktKonca);

			ileTaktowUplynelo = taktKonca.QuadPart - taktPoczatku.QuadPart;
			ileMiliSekundUplynelo = ((long double)ileTaktowUplynelo * 1000) / (long double)taktowNaSekunde.QuadPart;
			int l = ileMiliSekundUplynelo;
			cout << endl << "Trwalo to: " << ileMiliSekundUplynelo << " ms" << endl;

			Plik << ileMiliSekundUplynelo << endl;
			Plik.flush();
		}
		Plik.close();
	}
	for (i = 0; i < tmp; i++)
	{
		suma = suma + g.krawedzie[i].waga;
	}
	cout << endl << endl << "Najkrotsza droga wynosi: " << suma << endl;


	system("PAUSE");
	//	return 0;
}
