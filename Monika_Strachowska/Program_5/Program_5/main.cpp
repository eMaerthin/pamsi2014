#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

using namespace std;

void odczyt(string,int);

int main() {
	odczyt("graf10-100.txt",10);
	system("PAUSE");
	return 0;
}

void odczyt(string nazwa, int rozmiar) {
	fstream plik(nazwa, ios::in);
	vector<vector<pair<int,int>>> lista(rozmiar, vector<pair<int,int>>(0));
	int **macierz = new int*[rozmiar];
	for(int i = 0; i < rozmiar; i++)
		macierz[i] = new int[rozmiar];
	for(int i = 0; i < rozmiar; i++)
		for(int j = 0; j < rozmiar; j++)
			macierz[i][j] = -1;
	int tPoczatek, tKoniec, tWaga;
	if(plik.good()) {
		do{
			plik >> tPoczatek >> tKoniec >> tWaga;
			macierz[tPoczatek][tKoniec] = tWaga;
			macierz[tKoniec][tPoczatek] = tWaga;
			lista[tPoczatek].push_back(make_pair(tKoniec,tWaga));
			lista[tKoniec].push_back(make_pair(tPoczatek,tWaga));
		}while(!plik.eof());
	}
	cout << endl;

	for(int i = 0; i < rozmiar; i++) {
		for(int j = 0; j < rozmiar; j++) 
			cout << macierz[i][j] << " ";
		cout << endl;
	}
	for(int i = 0; i < lista.size(); i++) {
		cout << "Wierzcholek " << i << "   ";
		for(int j = 0; j < lista[i].size(); j++) {
			pair<int,int> tmp;
			tmp = lista[i][j];
			cout << tmp.first << " (" << tmp.second << "); ";
		}
		cout << endl;
	}
}

