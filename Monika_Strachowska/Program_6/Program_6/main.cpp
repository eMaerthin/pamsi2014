#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <queue>
#include <Windows.h>
#include <cmath>
#include <random>
#include <string>
#include <stack>

const int INF = 10000000;

using namespace std;
class Krawedz;
Krawedz **macierz = NULL;
vector< vector< Krawedz>> lista;
int liczbaWierzcholkow = 0;
int liczbaKrawedzi = 0;
bool czyWyswietlacWyniki = false;
int wierzcholekStartowy;

void wczytywanieZPliku(string);
void wyswietlanieWczytanych();
void DijkstraMacierz();
void DijkstraLista();
bool BFLista();
bool BFMacierz();
void losowanieGrafow(double, double, double);
void eksperyment();
void usrednianieCzasu(vector <long double>);
void wyswietlaniePolaczen(vector <int>, vector <int>, int);
void zapisanieLosowychGrafow();

class Krawedz {
public:
	int win, wout, waga;
	Krawedz():waga(-INF), win(INF), wout(INF){};
	Krawedz(int wi, int wo, int w): win(wi), wout(wo), waga(w){};
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
			DijkstraLista();
			cout << "\nPRIM MACIERZ\n";
			DijkstraMacierz();
			cout << "\nKRUSKAL LISTA\n";
			BFLista();
			cout << "\nKRUSKAL MACIERZ\n";
			BFMacierz();
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
		plik >> liczbaKrawedzi >> liczbaWierzcholkow >> wierzcholekStartowy;
		macierz = new Krawedz*[liczbaWierzcholkow];
		for(int i = 0; i < liczbaWierzcholkow; i++)
			macierz[i] = new Krawedz[liczbaWierzcholkow];
		lista = vector< vector< Krawedz>>(liczbaWierzcholkow, vector<Krawedz> (0));
		do {
			plik >> win >> wout >> w;
			Krawedz k(win,wout,w);
			macierz[win][wout] = k;
			lista[win].push_back(k);
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

void wyswietlaniePolaczen(vector <int> p, vector <int> d, int n) {
	for(int j = 0; j <n; j++) {
		cout << j << "   " << d[j] << "   ";
		stack <int> L;
		int i = j;
		while(i != 0){
			L.push(i);
			i = p[i];
		}
		L.push(0);
		while(!L.empty()) {
			cout << L.top() << " ";
			L.pop();
		}
		cout << endl;
	}
}

void DijkstraMacierz() {
	int n = liczbaWierzcholkow;
	int vo = wierzcholekStartowy;
	vector <int> d, p, S, Q;
	for(int i = 0; i < n; i++) {
		Q.push_back(i);
		p.push_back(0);
		d.push_back(INF);
	}
	d[vo] = 0;
	while(!Q.empty()) {
		int u = Q[0];
		Q.erase(Q.begin());
		S.push_back(u);
		for(int v = 0; v < n; v++) {
			if(macierz[u][v].waga > 0) {
				if(d[v] > d[u] + macierz[u][v].waga) {
					d[v] = d[u] + macierz[u][v].waga;
					p[v] = u;
				}
			}
		}
	}
	if(czyWyswietlacWyniki == true) {
		wyswietlaniePolaczen(p, d, n);
	}
}

void DijkstraLista() {
	int n = liczbaWierzcholkow;
	int vo = wierzcholekStartowy;
	vector <int> d, p, S, Q;
	for(int i = 0; i < n; i++) {
		Q.push_back(i);
		p.push_back(0);
		d.push_back(INF);
	}
	d[vo] = 0;
	while(!Q.empty()) {
		int u = Q[0];
		Q.erase(Q.begin());
		S.push_back(u);
		for(int v = 0; v < (int)lista[u].size(); v++) {
			if(d[lista[u][v].wout] > d[u] + lista[u][v].waga) {
					d[lista[u][v].wout] = d[u] + lista[u][v].waga;
					p[lista[u][v].wout] = u;
				}
		}
	}
	if(czyWyswietlacWyniki == true) {
		wyswietlaniePolaczen(p, d, n);
	}
}

bool BFMacierz() {
	bool test;
	int n = liczbaWierzcholkow;
	int vo = wierzcholekStartowy;
	vector <int> d, p, S, Q;
	for(int i = 0; i < n; i++) {
		Q.push_back(i);
		p.push_back(-1);
		d.push_back(INF);
	}
	d[vo] = 0;
	for(int i = 1; i < n; i++) {
		test = true;
		for(int x = 0; x < n - 1; x++) {
			for(int y = 0; y < n; y++) {
				if(macierz[x][y].waga > -INF) {
					if(d[y] <= d[x] + macierz[x][y].waga)
						continue;
					test = false;
					d[y] = d[x] + macierz[x][y].waga;
					p[y] = x;
				}
			}
			if(test == true) {
				if(czyWyswietlacWyniki == true) {
					wyswietlaniePolaczen(p, d, n);
				}
				return true;
			}
		}
	}
	for(int x = 0; x < n - 1; x++) {
		for(int y = 0; y < n; y++) {
			if(macierz[x][y].waga > -INF) {
				if(d[y] > d[x] + macierz[x][y].waga)
					return false;
			}
		}
	}
	if(czyWyswietlacWyniki == true) {
		wyswietlaniePolaczen(p, d, n);
	}
	return true;
}

bool BFLista() {
	bool test;
	int n = liczbaWierzcholkow;
	int vo = wierzcholekStartowy;
	vector <int> d, p, S, Q;
	for(int i = 0; i < n; i++) {
		Q.push_back(i);
		p.push_back(-1);
		d.push_back(INF);
	}
	d[vo] = 0;
	for(int i = 1; i < n; i++) {
		test = true;
		for(int x = 0; x < n - 1; x++) {
			for(int y = 0; y < (int)lista[x].size(); y++) {
				if(d[lista[x][y].wout] <= d[x] + lista[x][y].waga)
					continue;
				test = false;
				d[lista[x][y].wout] = d[x] + lista[x][y].waga;
				p[lista[x][y].wout] = x;
			}
			if(test == true) {
				if(czyWyswietlacWyniki == true) {
					wyswietlaniePolaczen(p, d, n);
				}
				return true;
			}
		}
	}
	for(int x = 0; x < n - 1; x++) {
		for(int y = 0; y < (int)lista[x].size(); y++) {
			if(d[lista[x][y].wout] > d[x] + macierz[x][y].waga)
				return false;
		}
	}
	if(czyWyswietlacWyniki == true) {
		wyswietlaniePolaczen(p, d, n);
	}
	return true;
}

void losowanieGrafow(double p, double dol, double gora) {
	macierz = new Krawedz*[liczbaWierzcholkow];
	for(int i = 0; i < liczbaWierzcholkow; i++)
		macierz[i] = new Krawedz[liczbaWierzcholkow];
	lista = vector< vector< Krawedz>>(liczbaWierzcholkow, vector<Krawedz> (0));

	default_random_engine generator;
	int* wagi = new int[liczbaWierzcholkow * liczbaWierzcholkow];
	for(int i = 0; i < liczbaWierzcholkow * liczbaWierzcholkow; i++) {
		uniform_real_distribution <double> poisson_sampler(dol,gora);
		wagi[i] = (int)poisson_sampler(generator);
	}
	for(int i = 0; i <liczbaWierzcholkow; i++)
		for(int j = i+1; j < liczbaWierzcholkow; j++) {
			if(rand() % 100000 < p * 100000) {
				Krawedz k(i,j,wagi[i*j]);
				macierz[i][j] = k;
				lista[i].push_back(k);
				liczbaKrawedzi++;
			}
		}
}

void eksperyment() {
	vector <long double> czasDL, czasDM, czasBL, czasBM;
	std::fstream plik("wyniki.txt", std::fstream::out | std::fstream::app);
	int wierzcholki[] = {50,100,200,400};
	double p[] = {0.25,0.5,0.75,1.0};
	__int64 czestotliosc;
	QueryPerformanceFrequency((LARGE_INTEGER*) &czestotliosc);
	for(int i = 0; i < 4; i++) {
		liczbaWierzcholkow = wierzcholki[i];
		for(int j = 0; j < 4; j++) {
			if(plik.good()) plik << "\n liczbaWierzcholkow: " << liczbaWierzcholkow << "  prawdopodobienstwo: " << p[j] << endl;
			cout << "\n liczbaWierzcholkow: " << liczbaWierzcholkow << "  prawdopodobienstwo: " << p[j] << endl;
			for(int k = 0; k < 100; k++) {
				if(k%10 == 9) {
					cout << ".";
				}
				losowanieGrafow(p[j],1,500);
				__int64 poczatekDL = 0, koniecDL = 0, poczatekDM = 0, koniecDM = 0;

				QueryPerformanceCounter((LARGE_INTEGER*) &poczatekDL);
				DijkstraLista();
				QueryPerformanceCounter((LARGE_INTEGER*) &koniecDL);

				QueryPerformanceCounter((LARGE_INTEGER*) &poczatekDM);
				DijkstraMacierz();
				QueryPerformanceCounter((LARGE_INTEGER*) &koniecDM);

				czasDL.push_back((long double)((koniecDL - poczatekDL)*1000/czestotliosc));
				czasDM.push_back((long double)((koniecDM - poczatekDM)*1000/czestotliosc));

				losowanieGrafow(p[j],-10,1000);
				__int64 poczatekBL = 0, koniecBL = 0, poczatekBM = 0, koniecBM = 0;

				QueryPerformanceCounter((LARGE_INTEGER*) &poczatekBL);
				bool cykl = BFLista();
				QueryPerformanceCounter((LARGE_INTEGER*) &koniecBL);
				if(cykl == false) 
					continue;
				QueryPerformanceCounter((LARGE_INTEGER*) &poczatekBM);
				BFMacierz();
				QueryPerformanceCounter((LARGE_INTEGER*) &koniecBM);
				
				czasBL.push_back((long double)((koniecBL - poczatekBL)*1000/czestotliosc));
				czasBM.push_back((long double)((koniecBM - poczatekBM)*1000/czestotliosc));
			}
			cout << endl;
			plik << "Dijkstra lista" << endl;
			cout << "Dijkstra lista" << endl;
			usrednianieCzasu(czasDL);
			plik << "Dijkstra macierz" << endl;
			cout << "Dijkstra macierz" << endl;
			usrednianieCzasu(czasDM);
			plik << "BF lista" << endl;
			cout << "BF lista" << endl;
			usrednianieCzasu(czasBL);
			plik << "BF macierz" << endl;
			cout << "BF macierz" << endl;
			usrednianieCzasu(czasBM);
			czasDL.clear();
			czasDM.clear();
			czasBL.clear();
			czasBM.clear();
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
	if(plik.good()) plik << "\nSredni_czas(ms): " << wynik << "\t" << wektor.size() << "\n\n";
	cout << "\nSredni_czas(ms): " << wynik << "\t" << wektor.size() << "\n\n";
	plik.close();
}

void zapisanieLosowychGrafow() {
	string nazwa;
	double prawdopodobienstwo;
	int dol, gora;
	cout << "podaj liczbe wierzcholkow i prawdopodobienstwo (0. - 1)\n";
	cin >> liczbaWierzcholkow >> prawdopodobienstwo;
	cout << "podaj zakres dolny i gorny\n\n";
	cin >> dol >> gora;
	nazwa = "graf" + to_string((long double)liczbaWierzcholkow) + "-" + to_string((long double)prawdopodobienstwo) 
		+ "_" + to_string((long double)dol) + to_string((long double)gora) + ".txt";
	losowanieGrafow(prawdopodobienstwo,dol,gora);
	fstream plik(nazwa, ios::out);
	if(plik.good()) {
		for(int i = 0; i < liczbaWierzcholkow; i++) {
			for(int j = i; j < liczbaWierzcholkow; j++)
				if(macierz[i][j].waga != -INF)
					plik << macierz[i][j].win << "\t" << macierz[i][j].wout << "\t" << macierz[i][j].waga << endl;
		}
	}
}
