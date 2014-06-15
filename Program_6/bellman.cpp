#include <iostream>
#include <utility>
#include <vector>
#include <windows.h>

using namespace std;

int iloscwierzcholkow, ilosckrawedzi, u, v, w;
const int INF = 1000000001; //nieskonczonosc

struct Krawedz{ //struktura reprezentujaca krawedz.
	int u;
	int v;
	int w;
	Krawedz(int i, int j, int k){
		u = i;
		v = j;
		w = k;
	}
};

vector<Krawedz> Krawedzie;                //struktura przechowujaca krawedzie
int d[10000];                      //struktura przechowujaca dlugosci (d[v]) najkrotszych drog laczacych wierzcholek s z v
int poprzednik[10000];             //przechowuje poprzednik wierzcholka v na sciezce (najkrotszej) do s
int s;                             //wierzcholek dla ktorego liczymy odleglosci (zrodlo) i do ktorego konstruujemy drogi

void init(){ //inicjujemy wszystkie tablice
	for (int i = 0; i<iloscwierzcholkow; i++){
		d[i] = INF; //poczatkowo odleglosc kazdego wierzcholka v od zrodla s wynosi nieskoczonosc
		poprzednik[i] = -1; //nikt nie ma zadnych poprzednikow bo nie ma zadnych sciezek
	}
	d[s] = 0; //odleglosc zrodla od niego samego wynosi 0
}

bool bellman(){ //oblicza dlugosci oraz przebieg najkrotszych sciezek miedzy wierzcholkiem zrodlowym s a wszystkimi innymi wierzcholkami
	for (int i = 1; i<iloscwierzcholkow; i++){ //wykonujemy N-1 przebiegow 
		for (int j = 0; j<2 * ilosckrawedzi; j++){
			if (d[Krawedzie[j].v] > d[Krawedzie[j].u] + Krawedzie[j].w){ //jezeli dlugosc sciezki s~>v jest wieksza niz s~>u + waga krawedzi u->v to...
				d[Krawedzie[j].v] = d[Krawedzie[j].u] + Krawedzie[j].w; //... zaktualizuj optymalny winik dla v i...
				poprzednik[Krawedzie[j].v] = Krawedzie[j].u; //... ustaw u jako poprzednika v na aktualnej najkrotszej sciezce s~>v
			}
		}
	}
	for (int i = 0; i<ilosckrawedzi; i++){ 
		if (d[Krawedzie[i].v] > d[Krawedzie[i].u] + Krawedzie[i].w)return false;
	}
	return true; //w grafie nie ma cyklu o ujemnej wadze wiec wyniki sa prawidlowe
}

void droga(int v){ //odtwarza droge v~>s idac po poprzednikach na najkrotszej sciezce
	do{
		cout << v + 1 << " ";
		v = poprzednik[v];
	} while (poprzednik[v] != -1);
}

int main(){
	ios_base::sync_with_stdio(0);

	long long int ileTaktowUplynelo;
	long double ileMiliSekunduplynelo;
	LARGE_INTEGER taktPoczatku, taktKonca, taktowNaSekunde;
	QueryPerformanceFrequency(&taktowNaSekunde);

	cout << "Podaj liczbe wierzcholkow: " << endl;
	cin >> iloscwierzcholkow;
	cout << "Podaj liczbe krawedzi: " << endl;
	cin >> ilosckrawedzi;

	cout << "Podaj wierzcholek od ktorego zaczynamy: " << endl;
	cin >> s;
	s--;
	for (int i = 0; i<ilosckrawedzi; i++){

		u = rand() % iloscwierzcholkow + 1;
		v = rand() % iloscwierzcholkow + 1;
		w = rand() % 500 + -10;

		Krawedzie.push_back(Krawedz(u - 1, v - 1, w));
		Krawedzie.push_back(Krawedz(v - 1, u - 1, w)); //graf jest nieskierowany
	}

	/*** Zaczynam liczyc czas dzialania algorytmu ******/
	QueryPerformanceCounter(&taktPoczatku);
	init();

	if (!bellman()){ //w grafie wystepuje cykl o ujemnej wadze
		cout << "W grafie wystepuje cykl o ujemnej wadze i nie da sie obliczyc najkrotszych sciezek.\n";
	}
	else{
		cout << "W grafie nie wystepuja cykle o ujemnej wadze. Oto najkrotsze sciezki miedzy wierzcholkiem " << s + 1 << ", a wszystkimi pozostalymi:\n";
		for (int i = 0; i < iloscwierzcholkow; i++){
			if (i != s){
				cout << s + 1 << "->" << i + 1 << " dl. " << d[i] << ", przebieg: ";
				droga(i);
				cout << s + 1 << endl;
			}
		}
	}

	/************  Koncze liczyc czas   ********************/
	QueryPerformanceCounter(&taktKonca);
	ileTaktowUplynelo = taktKonca.QuadPart - taktPoczatku.QuadPart;
	ileMiliSekunduplynelo = ((long double)ileTaktowUplynelo * 1000) / (long double)taktowNaSekunde.QuadPart;
	int czas = ileMiliSekunduplynelo;

	cout << "Czas " << ": " << czas << endl;

	system("pause");
	return 0;
}