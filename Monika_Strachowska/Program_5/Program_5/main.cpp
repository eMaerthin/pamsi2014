#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <queue>
#include <set>

using namespace std;

class Krawedz {
public:
	int wagaKrawedzi;
	int wierzcholekWej;
	int wierzcholekWyj;
	bool odwiedzony;
	Krawedz(int waga, int wej, int wyj): wagaKrawedzi(waga), wierzcholekWej(wej), wierzcholekWyj(wyj), odwiedzony(false) {};
};

class KrawedzPorownanie {
public:
	bool operator() (const Krawedz &k1, const Krawedz &k2) {
		if(k1.wagaKrawedzi > k2.wagaKrawedzi) return true;
		return false;
	}
};

void wczytywanieZPliku(string nazwa, vector <Krawedz> &wektor, int *liczbaWierzcholkow, int *liczbaKrawedzi) {
	fstream plik(nazwa, ios::in);
	int w, win, wout;
	if(plik.good()) {
		do {
			plik >> win >> wout >> w;
			Krawedz Ktmp1(w, win, wout);
			Krawedz Ktmp2(w, wout, win);
			wektor.push_back(Ktmp1);
			wektor.push_back(Ktmp2);
			(*liczbaWierzcholkow < win) ? (*liczbaWierzcholkow = win):0;
			(*liczbaWierzcholkow < wout) ? (*liczbaWierzcholkow = wout):0;
		}while(!plik.eof());
	}
	plik.close();
	*liczbaWierzcholkow += 1;
	*liczbaKrawedzi = wektor.size()/2; // bo dwukierunkowe krawedzie
}

void wyswietlanieMacierzy( vector <Krawedz> &wektor, int liczbaWierzcholkow) {
	int **macierz = new int*[liczbaWierzcholkow];
	for(int i = 0; i < liczbaWierzcholkow; i++)
		macierz[i] = new int[liczbaWierzcholkow];
	for(int i = 0; i < liczbaWierzcholkow; i++)
		for(int j = 0; j < liczbaWierzcholkow; j++) 
			macierz[i][j] = -1;
	for(int i = 0; i < (int)wektor.size(); i++)
		macierz[wektor[i].wierzcholekWej][wektor[i].wierzcholekWyj] = wektor[i].wagaKrawedzi;
	cout << "\n\nMACIERZ\n\n";
	for(int i = 0; i < liczbaWierzcholkow; i++) {
		for(int j = 0; j < liczbaWierzcholkow; j++)
			cout << setw(3) << macierz[i][j] << " ";
		cout << endl;
	}

}

void wyswietlanieLista(vector <Krawedz> &wektor, int liczbaWierzcholkow) {
	vector< vector< pair<int,int>>> lista(liczbaWierzcholkow, vector<pair<int,int>> (0));
	for(int i = 0; i < (int)wektor.size(); i++) 
		lista[wektor[i].wierzcholekWej].push_back(make_pair(wektor[i].wierzcholekWyj,wektor[i].wagaKrawedzi));
	cout << "\n\nLISTA\n\n";
	for(int i = 0; i < (int) lista.size(); i++) {
		cout << "Wierzcholek: " << i << "\t";
		for(int j = 0; j < lista[i].size(); j++) {
			pair<int,int> tmp = lista[i][j];
			cout << tmp.first << " (" << tmp.second << "); ";
		}
		cout << endl;
	}
}

void wyswietlaniePolaczenWyniku(vector <Krawedz> wektor) {
	for(int i = 0; i < wektor.size(); i++)
		cout << wektor[i].wierzcholekWej << " <-> " << wektor[i].wierzcholekWyj << "  (" << wektor[i].wagaKrawedzi << ")\n";
}

int znajdz(int x, int *parent) {
	if(x != parent[x])
		parent[x] = znajdz(parent[x], parent);
	return parent[x];
}

typedef priority_queue<Krawedz,vector<Krawedz>,KrawedzPorownanie> kolejkaKP;
vector<Krawedz> kruskal(vector <Krawedz> wektor, int liczbaWierzcholkow) {
	kolejkaKP kolejka;
	for(int  i = 0; i < (int) wektor.size(); i++)
		kolejka.push(wektor[i]);

	vector <Krawedz> wynik;
	int pIn, pOut;
	int *parent = new int[liczbaWierzcholkow];
	for(int i = 0; i < liczbaWierzcholkow; i++) parent[i] = i;
	while(!kolejka.empty()) {
		Krawedz k = kolejka.top();
		pIn = znajdz(k.wierzcholekWej, parent);
		pOut = znajdz(k.wierzcholekWyj, parent);
		if(pIn != pOut) {
			wynik.push_back(k);
			parent[pIn] = parent[pOut];
		}
		kolejka.pop();
	}
	int suma = 0;
	for(int i = 0; i < wynik.size(); i++)
		suma += wynik[i].wagaKrawedzi;
	cout << "SUMA KRUSKAL: " << suma << endl;
	return wynik;
}

void wyswietlanieKolejki(kolejkaKP kolejka) {
	int rozmiar = kolejka.size();
	for(int i = 0; i < rozmiar; i++) {
		cout << kolejka.top().wagaKrawedzi << "   " <<
			kolejka.top().wierzcholekWej << "   " <<
			kolejka.top().wierzcholekWyj << "   flaga " << 
			kolejka.top().odwiedzony << endl;
		kolejka.pop();
	}
}

kolejkaKP przepisanie(kolejkaKP tmp) {
	if(!tmp.empty()) {
		kolejkaKP kolejka;
		int rozmiar = tmp.size();
		for(int i = 0; i < rozmiar; i++) {
			Krawedz k(tmp.top().wagaKrawedzi,tmp.top().wierzcholekWej,tmp.top().wierzcholekWyj);
			kolejka.push(k);
			tmp.pop();
		}
		return kolejka;
	}
	else {
		cout << "\nPusta kolejka do przepisania\n";
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
		if(tmp.top().wierzcholekWyj == wOut)
			tmp.pop();
		else {
			(*kolejka).push(tmp.top());
			tmp.pop();
		}
	}
}

vector<Krawedz> prim(vector <Krawedz> wektor, int liczbaWierzcholkow) {
	int aktualny = 0, suma = 0, rozmiar = wektor.size();
	kolejkaKP kolejka;
	vector <Krawedz> wynik;
	int liczbaPotrzebnychKrawedzi = liczbaWierzcholkow - 1;
	do {
		for(int i = 0; i < rozmiar; i++) {
			if(wektor[i].wierzcholekWej == aktualny && wektor[i].odwiedzony == false)
				kolejka.push(wektor[i]);
			if(wektor[i].wierzcholekWyj == aktualny)
				wektor[i].odwiedzony = true;
		}
		usuwanieZKolejki(&kolejka,aktualny);
		if(!kolejka.empty()) {
			while(kolejka.top().odwiedzony == true) kolejka.pop();
			if(kolejka.top().odwiedzony == false) {
				aktualny = kolejka.top().wierzcholekWyj;
				wynik.push_back(kolejka.top());
				kolejka.pop();
			}
		}
		liczbaPotrzebnychKrawedzi--;
	}while(liczbaPotrzebnychKrawedzi > 0);

	for(int i = 0; i < wynik.size(); i++ )
		suma += wynik[i].wagaKrawedzi;
	cout << "SUMA PRIM: " << suma << endl;
	return wynik;
}

int main() {
	int liczbaKrawedzi = 0, liczbaWierzcholkow = 0;
	vector <Krawedz> wektor;
	cout << liczbaKrawedzi << " " << liczbaWierzcholkow << endl;
	wczytywanieZPliku("graf10-100.txt", wektor, &liczbaWierzcholkow, &liczbaKrawedzi);
	cout << liczbaKrawedzi << " " << liczbaWierzcholkow << endl;
	wyswietlanieMacierzy(wektor,liczbaWierzcholkow);
	wyswietlanieLista(wektor,liczbaWierzcholkow);
	wyswietlaniePolaczenWyniku(kruskal(wektor,liczbaWierzcholkow));
	prim(wektor,liczbaWierzcholkow);
	system("PAUSE");
	return 0;
}