#include <queue>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

const int INF = 2147483646;

using namespace std; 

int bfs();
void edmondsKarp();
void odczytywanieZPliku(string);
void eksperyment();
void usrednianieCzasu(vector <long double>); 

int **C, **F;
vector <int> *graf;
int *p, *cpc;
int liczbaWierzcholkow, liczbaKrawedzi, wierzcholekStartowy, wierzcholekKoncowy, fmax;
string nazwaPliku;

int main()
{
	nazwaPliku = "2k100-35.txt";
	eksperyment();
	nazwaPliku = "2k200-89.txt";
	eksperyment();
	nazwaPliku = "2k300-53.txt";
	eksperyment();
	nazwaPliku = "2k400-37.txt";
	eksperyment();
	nazwaPliku = "2k500-92.txt";
	eksperyment();

	nazwaPliku = "4k100-23.txt";
	eksperyment();
	nazwaPliku = "4k200-93.txt";
	eksperyment();
	nazwaPliku = "4k300-72.txt";
	eksperyment();
	nazwaPliku = "4k400-64.txt";
	eksperyment();
	nazwaPliku = "4k500-16.txt";
	eksperyment();

	nazwaPliku = "16k100-67.txt";
	eksperyment();
	nazwaPliku = "16k200-48.txt";
	eksperyment();
	nazwaPliku = "16k300-19.txt";
	eksperyment();

	system("PAUSE");
	return 0;
}

void odczytywanieZPliku(string nazwa) {
	int win, wout, w;

	fstream plik(nazwa, ios::in);
	
	if(plik.good()) {
		plik >> liczbaWierzcholkow >> liczbaKrawedzi >> wierzcholekStartowy >> wierzcholekKoncowy;
		graf = new vector <int> [liczbaWierzcholkow];
		p = new int[liczbaWierzcholkow];
		cpc = new int[liczbaWierzcholkow];
		C = new int*[liczbaWierzcholkow];
		F = new int*[liczbaWierzcholkow];
		for(int i = 0; i < liczbaWierzcholkow; i++) {
			C[i] = new int[liczbaWierzcholkow];
			F[i] = new int[liczbaWierzcholkow];
		}
		for(int i = 0; i < liczbaWierzcholkow; i++) {
			p[i] = -1;
			cpc[i] = 0;
			for(int j = 0; j < liczbaWierzcholkow; j++) {
				C[i][j] = 0;
				F[i][j] = 0;
			}
		}

		for(int edge = 0; edge < liczbaKrawedzi; edge++) {
			plik >> win >> wout >> w;
			C[win][wout]=w;
			graf[win].push_back(wout);
			graf[wout].push_back(win);
		}
	}
	plik.close();
}

int bfs() {
	for(int i = 0; i < liczbaWierzcholkow; i++) {
		p[i] = -1;
		cpc[i] = 0;
	}
	queue<int> q;
	q.push(wierzcholekStartowy);
	p[wierzcholekStartowy] = -2;
	cpc[wierzcholekStartowy] = INF;

	while(!q.empty()) {
		int aktualnyWierzcholek = q.front(); q.pop();
		for(int i = 0; i < graf[aktualnyWierzcholek].size(); i++) {
			int to = graf[aktualnyWierzcholek][i];
			if(p[to] == -1) {
				if(C[aktualnyWierzcholek][to] - F[aktualnyWierzcholek][to] > 0) {
					p[to] = aktualnyWierzcholek;
					cpc[to] = min(cpc[aktualnyWierzcholek], C[aktualnyWierzcholek][to] - F[aktualnyWierzcholek][to]);
					if(to == wierzcholekKoncowy) return cpc[wierzcholekKoncowy];
					q.push(to);
				}
			}
		}
	}

	return 0;
}

void edmondsKarp() {
	while(true) {
		int przeplyw = bfs();
		if(przeplyw == 0) break;
		fmax += przeplyw;
		int aktualnyWierzcholek = wierzcholekKoncowy;
		while(aktualnyWierzcholek != wierzcholekStartowy) {
			int poprzedniWierzcholek = p[aktualnyWierzcholek];
			F[poprzedniWierzcholek][aktualnyWierzcholek] += przeplyw;
			F[aktualnyWierzcholek][poprzedniWierzcholek] -= przeplyw;
			aktualnyWierzcholek = poprzedniWierzcholek;
		}
	}
}

void eksperyment() {
	vector <long double> czas;
	std::fstream plik("wyniki.txt", std::fstream::out | std::fstream::app);
	__int64 czestotliosc;
	QueryPerformanceFrequency((LARGE_INTEGER*) &czestotliosc);
	odczytywanieZPliku(nazwaPliku);
	if(plik.good()) {
		plik << "Dlapliku ";
		plik << nazwaPliku << endl;
		cout << "Dlapliku " << nazwaPliku << endl;
		plik << "liczbaWierzcholkow: " << liczbaWierzcholkow << "  liczbaKrawedzi: " << liczbaKrawedzi << 
			"\nwierzcholekStartowy: " << wierzcholekStartowy << " wierzcholekKoncowy: " << wierzcholekKoncowy;
		cout << "liczbaWierzcholkow: " << liczbaWierzcholkow << "  liczbaKrawedzi: " << liczbaKrawedzi << 
			"\nwierzcholekStartowy: " << wierzcholekStartowy << " wierzcholekKoncowy: " << wierzcholekKoncowy << endl;
		for(int i = 0; i < 10; i++) {
			cout << ".";
			__int64 poczatek = 0, koniec = 0;

			QueryPerformanceCounter((LARGE_INTEGER*) &poczatek);
			edmondsKarp();
			QueryPerformanceCounter((LARGE_INTEGER*) &koniec);

			czas.push_back((long double)((koniec - poczatek)*1000/czestotliosc));
		}
		cout << endl;
		plik << endl;
		usrednianieCzasu(czas);
		czas.clear();

		cout << "maksymalnyPrzeplyw: ";
		plik << "maksymalnyPrzeplyw: ";
		cout << fmax;
		plik << fmax;
		plik << "\n\n";
		cout << "\n\n";
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
	if(plik.good()) plik << "Sredni_czas(ms): " << wynik << "\t" << wektor.size() << "\n";
	cout << "Sredni_czas(ms): " << wynik << "\t" << wektor.size() << "\n";
	plik.close();
}