#ifndef LISTA_HH
#define LISTA_HH
#include "typ.hh"
#include <list>
//JEDZIEMY NA STL- LISTA WSKAZNIKOW (elementow poczatkowych) NA ELEMENTY KONCOWE
struct st_wierzcholek {
	int nr; //numer wierzcholka
	int waga; //waga laczaca nr wierzcholka z drugim
};
class k_lista {
	list<st_wierzcholek> *lista;
	int rozmiar;
public:
	bool Wyswietl_i_zapisz_txt();
	bool Wczytaj_txt();
	int Zbadaj_plik(string n);
	void Rozmiar() { cout << "__________________" << endl << "Ilosc wierzcholkow grafu:\t" << rozmiar << endl << endl; }
	k_lista() { lista = NULL; rozmiar = 0; }
	k_lista(int n) { lista = new list<st_wierzcholek>[n]; rozmiar = n; }
	~k_lista() { delete[] lista; }
};
int k_lista::Zbadaj_plik(string n) {
	fstream plik;
	rozmiar = 0;
	int i = -1, j = -1, zero = 1;

	plik.open(n, ios::in); //podgladamy plik zeby wiedziec, jak duza macierz zaalokowac
	if (plik.good()) {
		while (!plik.eof()) {
			plik >> i; { if (i == 0) zero = 0;			//jesli wykryto zero, zwiekszymy potem liczbe elementow
			if (i > rozmiar) rozmiar = i; } // jesli ktorys z elementow jest wiekszy od rozmiaru, zwiekszamy go do tego elementu
			plik >> j; { if (j == 0) zero = 0;
			if (j > rozmiar) rozmiar = j; }
			plik >> i; } //tu wczytujemy wage, dla poprawnosci dzialania programu
		if (zero == 0) rozmiar++; //jesli wsrod wierzcholkow macierzy znajdzie sie zero
	}
	plik.close();
	return rozmiar;
}
bool k_lista::Wczytaj_txt() {
	string nazwa;
	fstream plik;
	int i, j, w;

	cout << endl << "Podaj nazwê pliku do wczytania: " << endl;
	cin >> nazwa;
	Zbadaj_plik(nazwa);
	plik.open(nazwa, ios::in);
	if (plik.good()) {
		lista = new list<st_wierzcholek>[rozmiar];			// alokujemy nowa liste o znanym rozmiarze

		while (!plik.eof()) {
			plik >> i >> j >> w;
			st_wierzcholek temp;
			temp.waga = w;
			temp.nr = j; lista[i].push_back(temp);
			temp.nr = i; lista[j].push_back(temp); //zapisujemy takze w druga strone, graf nieskierowany
		} //wczytywanie do listy
		plik.close();
		return true;
	}
	else cout << "Nie otworzono pliku." << endl;  return false;
}
bool k_lista::Wyswietl_i_zapisz_txt() {
	string nazwa;
	fstream plik;
	st_wierzcholek temp;

	cout << endl << "Podaj nazwê pliku do zapisu:" << endl;
	cin >> nazwa;

	plik.open(nazwa, ios::out);
	if (plik.good() == true) { //zapisywanie do pliku
		cout << endl << "Lista grafu wraz z wagami w nawiasach kwadratowych:" << endl; // i jednoczesne wyswietlanie
		for (int i = 0; i < rozmiar; ++i) {
			cout << i;				// pierwszy element wierzcholka jest wyswietlony
			while (!lista[i].empty()) {																	
				temp = lista[i].front();												//podgladamy jeden element
				plik << i << "       " << temp.nr << "       " << temp.waga << endl;	//po kolei, pierwszy, drugi element wierzcholka,
				lista[i].pop_front();													 // na koncu waga i nowa linijka, sciagamy element 
			cout << " --> " << temp.nr << " [ " << temp.waga << " ]"; } //jednoczesne wyswietlenie
			cout << endl; // i konsoli
		}
		plik.close();
		cout << endl << endl;
		return true;
	}
	else cout << "Nie utworzono pliku." << endl;  return false;
}
void Program_lista(){
	k_lista graf;
	int wybor;
	cout << "Program umo¿liwia wczytanie grafu z pliku do listy\n\ti wyœwietlenie go w tej formie, a nastêpnie zapis do pliku." << endl;
	do {
		cout << "1. Wczytaj graf z pliku tekstowego." << endl;
		cout << "2. Wyœwietl wczytany graf w formie listowej i zapisz do pliku tekstowego." << endl;
		cout << "0. Wyjœcie do menu wyboru formy grafu." << endl;
		cout << "Wybierz opcjê:\t";
		cin >> wybor;
		switch (wybor) {
		case 0: break;
		case 1: graf.Wczytaj_txt(); break;
		case 2: graf.Wyswietl_i_zapisz_txt(); break;
		default: cout << "Nieprawidlowy wybor, sprobuj ponownie." << endl << endl; break;
		}
	} while (wybor != 0);
}
#endif