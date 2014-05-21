#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <queue>
#include <Windows.h>
#include <cmath>
#include <random>
#include <string>

using namespace std;
class Krawedz;
class KrawedzPorownanie;
typedef priority_queue<Krawedz,vector<Krawedz>,KrawedzPorownanie> kolejkaKP;
Krawedz **macierz = NULL;
vector< vector< Krawedz>> lista;
int liczbaWierzcholkow = 0;
int liczbaKrawedzi = 0;
bool czyWyswietlacWyniki = false;

void wczytywanieZPliku(string);
void wyswietlanieWczytanych();
int primLista();
int primMacierz();
int kruskalLista();
int kruskalMacierz();
kolejkaKP przepisanie(kolejkaKP);
void usuwanieZKolejki(kolejkaKP *, int);
int znajdz(int, int *);
void losowanieGrafow(double);
void wyswietlaniePolaczen(vector <Krawedz>);
void eksperyment();
void usrednianieCzasu(vector <long double>);
void ustawianieFlagPrim();
void zapisanieLosowychGrafow();

class Krawedz {
public:
	int win, wout, waga;
	bool odwiedzony;
	Krawedz():waga(-1), win(-1), wout(-1), odwiedzony(true){};
	Krawedz(int wi, int wo, int w): win(wi), wout(wo), waga(w), odwiedzony(false) {};
};
class KrawedzPorownanie {
public:
	bool operator() (const Krawedz &k1, const Krawedz &k2) {
		if(k1.waga > k2.waga) return true;
		return false;
	}
};



int main() {
	int wybor = 0;
	string nazwa;
	do {
		cout << "Co chcesz zrobic?\n"
			"1 - eksperyment\n"
			"2 - odczyt z pliku\n"
			"3 - zapis do pliku\n"
			"0 - wyjscie\n";
		cin >> wybor;
		if(wybor == 1)
			eksperyment();
		if(wybor == 2) {
			cout << "Z jakiego pliku czytac (*.txt)\n";
			cin >> nazwa;
			wczytywanieZPliku(nazwa);
			int z = 0;
			cout << "Czy wyswietlic polaczenia? (1)\n";
			cin >> z;
			if(z == 1) czyWyswietlacWyniki = true;
			cout << "\nPRIM LISTA\n";
			primLista();
			cout << "\nPRIM MACIERZ\n";
			primMacierz();
			cout << "\nKRUSKAL LISTA\n";
			kruskalLista();
			cout << "\nKRUSKAL MACIERZ\n";
			kruskalMacierz();
			czyWyswietlacWyniki = false;
		}
		if(wybor == 3) 
			zapisanieLosowychGrafow();
	}while( wybor != 0);
	system("PAUSE");
	return 0;
}

void wczytywanieZPliku(string nazwa) {
	fstream plik(nazwa, ios::in);
	int w, win, wout;
	if(plik.good()) {
		do {
			plik >> win >> wout >> w;
			(liczbaWierzcholkow < win) ? (liczbaWierzcholkow = win):0;
			(liczbaWierzcholkow < wout) ? (liczbaWierzcholkow = wout):0;
			(liczbaKrawedzi)++;
		}while(!plik.eof());
	}
	plik.close();
	liczbaWierzcholkow += 1;

	macierz = new Krawedz*[liczbaWierzcholkow];
	for(int i = 0; i < liczbaWierzcholkow; i++)
		macierz[i] = new Krawedz[liczbaWierzcholkow];
	lista = vector< vector< Krawedz>>(liczbaWierzcholkow, vector<Krawedz> (0));

	plik.open(nazwa);
	if(plik.good()) {
		do {
			plik >> win >> wout >> w;
			Krawedz k(win,wout,w);
			Krawedz k1(wout,win,w);
			macierz[win][wout] = k;
			macierz[wout][win] = k1;
			lista[win].push_back(k);
			lista[wout].push_back(k1);
		}while(!plik.eof());
	}
	plik.close();
}

void wyswietlanieWczytanych() {
	cout << endl;
	for(int i = 0; i < liczbaWierzcholkow; i++) {
		for(int j = 0; j < liczbaWierzcholkow; j++)
			cout << setw(3) << macierz[i][j].waga << " ";
		cout << endl;
	}
	cout << endl;
	for(int i = 0; i < (int) lista.size(); i++) {
		cout << "Wierzcholek: " << i << "\t";
		for(int j = 0; j < (int)lista[i].size(); j++) {
			cout << lista[i][j].wout << " (" << lista[i][j].waga << "); ";
		}
		cout << endl;
	}
	cout << endl;
}

void wyswietlaniePolaczen(vector <Krawedz> wyniki) {
	for(int i = 0; i < (int) wyniki.size(); i++)
		cout << wyniki[i].win << "  -  " << wyniki[i].wout << "    => " << wyniki[i].waga << endl;
}

int primLista() {
	int aktualny = 0, suma = 0;
	vector< vector< Krawedz>> listaTMP = lista;

	kolejkaKP kolejka;
	vector <Krawedz> wynik;
	int liczbaPotrzebnychKrawedzi = liczbaWierzcholkow - 1;
	do {
		for(int i = 0; i < liczbaWierzcholkow; i++) {
			for(int j = 0; j < (int)lista[i].size(); j++) {
				if(listaTMP[i][j].win == aktualny && listaTMP[i][j].odwiedzony == false)
					kolejka.push(listaTMP[i][j]);
				if(listaTMP[i][j].wout == aktualny)
					listaTMP[i][j].odwiedzony = true;
			}
		}
		usuwanieZKolejki(&kolejka,aktualny);
		if(!kolejka.empty()) {
			while(kolejka.top().odwiedzony == true) kolejka.pop();
			if(kolejka.top().odwiedzony == false) {
				aktualny = kolejka.top().wout;
				wynik.push_back(kolejka.top());
				suma +=kolejka.top().waga;
				kolejka.pop();
			}
		}
		liczbaPotrzebnychKrawedzi--;
	}while(liczbaPotrzebnychKrawedzi > 0);

	if(czyWyswietlacWyniki == true) {
		wyswietlaniePolaczen(wynik);
		cout << "SUMA: " << suma << endl;
	}
	return suma;
}

void ustawianieFlagPrim() {
	for(int i = 0; i < liczbaWierzcholkow; i++) {
		for(int j = 0; j < liczbaWierzcholkow; j++)
			macierz[i][j].odwiedzony = false;
	}
}

kolejkaKP przepisanie(kolejkaKP tmp) {
	if(!tmp.empty()) {
		kolejkaKP kolejka;
		int rozmiar = tmp.size();
		for(int i = 0; i < rozmiar; i++) {
			Krawedz k(tmp.top().win,tmp.top().wout,tmp.top().waga);
			kolejka.push(k);
			tmp.pop();
		}
		return kolejka;
	}
	else {
		cout << "\nGraf nie pelny\n";
		system("PAUSE");
		exit(-1);
	}
}

void usuwanieZKolejki(kolejkaKP *kolejka, int wOut) {
	kolejkaKP tmp;
	tmp = przepisanie(*kolejka);
	int rozmiar = (*kolejka).size();
	while(!(*kolejka).empty()) (*kolejka).pop();
	for(int i = 0; i < rozmiar; i++) {
		if(tmp.top().wout == wOut)
			tmp.pop();
		else {
			(*kolejka).push(tmp.top());
			tmp.pop();
		}
	}
}

int primMacierz() {
	int aktualny = 0, suma = 0;
	Krawedz **macierzTMP = macierz;

	kolejkaKP kolejka;
	vector <Krawedz> wynik;
	int liczbaPotrzebnychKrawedzi = liczbaWierzcholkow - 1;
	do {
		for(int i = 0; i < liczbaWierzcholkow; i++) {
			for(int j = 0; j < liczbaWierzcholkow; j++) {
				if(macierzTMP[i][j].win == aktualny && macierzTMP[i][j].odwiedzony == false)
					kolejka.push(macierzTMP[i][j]);
				if(macierzTMP[i][j].wout == aktualny)
					macierzTMP[i][j].odwiedzony = true;
			}
		}
		usuwanieZKolejki(&kolejka,aktualny);
		if(!kolejka.empty()) {
			while(kolejka.top().odwiedzony == true) kolejka.pop();
			if(kolejka.top().odwiedzony == false) {
				aktualny = kolejka.top().wout;
				suma += kolejka.top().waga;
				wynik.push_back(kolejka.top());
				kolejka.pop();
			}
		}
		liczbaPotrzebnychKrawedzi--;
	}while(liczbaPotrzebnychKrawedzi > 0);

	if(czyWyswietlacWyniki == true) {
		wyswietlaniePolaczen(wynik);
		cout << "SUMA: " << suma << endl;
	}

	return suma;
}

int kruskalLista() {
	vector< vector< Krawedz>> listaTMP = lista;
	kolejkaKP kolejka;
	for(int  i = 0; i < liczbaWierzcholkow; i++) {
		for(int j = 0; j < (int)listaTMP[i].size(); j++)
			if(listaTMP[i][j].waga != -1)
				kolejka.push(listaTMP[i][j]);
	}

	vector <Krawedz> wynik;
	int pIn, pOut, suma = 0;
	int *parent = new int[liczbaWierzcholkow];
	for(int i = 0; i < liczbaWierzcholkow; i++) parent[i] = i;
	while(!kolejka.empty()) {
		Krawedz k = kolejka.top();
		pIn = znajdz(k.win, parent); 
		pOut = znajdz(k.wout, parent);
		if(pIn != pOut) {
			wynik.push_back(k);
			suma += k.waga;
			parent[pIn] = parent[pOut];
		}
		kolejka.pop();
	}

	if(czyWyswietlacWyniki == true) {
		wyswietlaniePolaczen(wynik);
		cout << "SUMA: " << suma << endl;
	}

	return suma;
}

int znajdz(int x, int *parent) {
	if(x != parent[x])
		parent[x] = znajdz(parent[x], parent);
	return parent[x];
}

int kruskalMacierz() {
	Krawedz **macierzTMP = macierz;
	kolejkaKP kolejka;
	for(int  i = 0; i < liczbaWierzcholkow; i++)
		for(int j = i; j < liczbaWierzcholkow; j++) 
			if(macierzTMP[i][j].waga != -1)
				kolejka.push(macierzTMP[i][j]);

	vector <Krawedz> wynik;
	int pIn, pOut, suma = 0;
	int *parent = new int[liczbaWierzcholkow];
	for(int i = 0; i < liczbaWierzcholkow; i++) parent[i] = i;
	while(!kolejka.empty()) {
		Krawedz k = kolejka.top();
		pIn = znajdz(k.win, parent);
		pOut = znajdz(k.wout, parent);
		if(pIn != pOut) {
			wynik.push_back(k);
			suma += k.waga;
			parent[pIn] = parent[pOut];
		}
		kolejka.pop();
	}

	if(czyWyswietlacWyniki == true) {
		wyswietlaniePolaczen(wynik);
		cout << "SUMA: " << suma << endl;
	}

	return suma;
}

void losowanieGrafow(double p) {
	macierz = new Krawedz*[liczbaWierzcholkow];
	for(int i = 0; i < liczbaWierzcholkow; i++)
		macierz[i] = new Krawedz[liczbaWierzcholkow];
	lista = vector< vector< Krawedz>>(liczbaWierzcholkow, vector<Krawedz> (0));

	default_random_engine generator;
	mt19937 gen;
	int* wagi = new int[liczbaWierzcholkow * liczbaWierzcholkow];
	for(int i = 0; i < liczbaWierzcholkow * liczbaWierzcholkow; i++) {
		poisson_distribution <> pois_dist(10.0);
		variate_generator<mt19937&, poisson_distribution<>> poisson_sampler(gen, pois_dist);
		wagi[i] = poisson_sampler();
	}
	for(int i = 0; i <liczbaWierzcholkow; i++)
		for(int j = i+1; j < liczbaWierzcholkow; j++) {
			if(rand() % 100000 < p * 100000) {
				Krawedz k(i,j,wagi[i*j]);
				Krawedz k1(j,i,wagi[i*j]);
				macierz[i][j] = k;
				macierz[j][i] = k1;
				lista[i].push_back(k);
				lista[j].push_back(k1);
				liczbaKrawedzi++;
			}
		}
}

void eksperyment() {
	vector <long double> czasPl, czasPm, czasKl, czasKm;
	std::fstream plik("wyniki.txt", std::fstream::out | std::fstream::app);
	int wierzcholki[] = {500,1000,2000,4000};
	__int64 czestotliosc;
	QueryPerformanceFrequency((LARGE_INTEGER*) &czestotliosc);
	for(int i = 0; i < 4; i++) {
		liczbaWierzcholkow = wierzcholki[i];
		double p[] = {3 * log((double)liczbaWierzcholkow)/liczbaWierzcholkow, pow((double)(liczbaWierzcholkow),(-1/3.0)), pow((double)(liczbaWierzcholkow),(-1/2.0)), 1};
		for(int j = 0; j < 4; j++) {
			if(plik.good()) 
				plik << "\n liczbaWierzcholkow: " << liczbaWierzcholkow 
				<< "  prawdopodobienstwo: " << p[j] << endl;
			cout << "\n liczbaWierzcholkow: " << liczbaWierzcholkow 
				<< "  prawdopodobienstwo: " << p[j] << endl;
			for(int k = 0; k < 100; k++) {
				if(k%10 == 9) {
					cout << ".";
				}
				losowanieGrafow(p[j]);
				__int64 poczatekPl = 0, koniecPl = 0, poczatekPm = 0, koniecPm = 0;
				ustawianieFlagPrim();

				QueryPerformanceCounter((LARGE_INTEGER*) &poczatekPl);
				primLista();
				QueryPerformanceCounter((LARGE_INTEGER*) &koniecPl);

				ustawianieFlagPrim();

				QueryPerformanceCounter((LARGE_INTEGER*) &poczatekPm);
				primMacierz();
				QueryPerformanceCounter((LARGE_INTEGER*) &koniecPm);

				ustawianieFlagPrim();

				czasPl.push_back((long double)((koniecPl - poczatekPl)*1000/czestotliosc));
				czasPm.push_back((long double)((koniecPm - poczatekPm)*1000/czestotliosc));

				__int64 poczatekKl = 0, koniecKl = 0, poczatekKm = 0, koniecKm = 0;

				QueryPerformanceCounter((LARGE_INTEGER*) &poczatekKl);
				kruskalLista();
				QueryPerformanceCounter((LARGE_INTEGER*) &koniecKl);

				QueryPerformanceCounter((LARGE_INTEGER*) &poczatekKm);
				kruskalMacierz();
				QueryPerformanceCounter((LARGE_INTEGER*) &koniecKm);

				czasKl.push_back((long double)((koniecKl - poczatekKl)*1000/czestotliosc));
				czasKm.push_back((long double)((koniecKm - poczatekKm)*1000/czestotliosc));
			}
			cout << endl;
			plik << "Kruskal lista" << endl;
			cout << "Kruskal lista" << endl;
			usrednianieCzasu(czasKl);
			plik << "Kruskal macierz" << endl;
			cout << "Kruskal macierz" << endl;
			usrednianieCzasu(czasKm);
			plik << "Prim lista" << endl;
			cout << "Prim lista" << endl;
			usrednianieCzasu(czasPl);
			plik << "Prim macierz" << endl;
			cout << "Prim macierz" << endl;
			usrednianieCzasu(czasPm);
			czasKl.clear();
			czasKm.clear();
			czasPl.clear();
			czasPm.clear();
		}
	}
	plik.close();
}

void usrednianieCzasu(vector <long double> wektor) {
	long double temp = 0;
	for(int i = 0; i < (int)wektor.size(); i++) {
		temp += wektor[i];
	}
	long double wynik = temp/wektor.size();
	std::cout.setf(std::ios::fixed, std::ios::floatfield);
	std::fstream plik("wyniki.txt", std::fstream::out | std::fstream::app);
	if(plik.good()) plik << "\nSredni_czas(ms): " << wynik << "\n\n";
	cout << "\nSredni_czas(ms): " << wynik << "\n\n";
	plik.close();
}

void zapisanieLosowychGrafow() {
	string nazwa;
	float prawdopodobienstwo;
	cout << "podaj liczbe wierzcholkow i prawdopodobienstwo (0. - 1)\n";
	cin >> liczbaWierzcholkow >> prawdopodobienstwo;
	nazwa = "graf" + to_string((long double)liczbaWierzcholkow) + "-" + to_string((long double)prawdopodobienstwo) + ".txt";
	losowanieGrafow(prawdopodobienstwo);
	fstream plik(nazwa, ios::out);
	if(plik.good()) {
		for(int i = 0; i < liczbaWierzcholkow; i++) {
			for(int j = i; j < liczbaWierzcholkow; j++)
				if(macierz[i][j].waga != -1)
					plik << macierz[i][j].win << "\t" << macierz[i][j].wout << "\t" << macierz[i][j].waga << endl;
		}
	}
}