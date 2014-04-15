#ifndef MACIERZ_HH
#define MACIERZ_HH
#include "typ.hh"

class k_macierz {
	TYP **macierz;
	int rozmiar;
public:
	void Wyzeruj_macierz();
	void Wyswietl_macierz();
	bool Zapisz_txt();
	bool Wczytaj_txt();
	int Zbadaj_plik(string n);
	void Rozmiar() { cout << "__________________" << endl << "Ilosc wierzcholkow grafu:\t" << rozmiar << endl << endl; }
	k_macierz() { macierz = NULL; rozmiar = 0; }
	k_macierz(int n) { macierz = new TYP *[n];	for (int i = 0; i < n; ++i) macierz[i] = new TYP[n]; rozmiar = n; Wyzeruj_macierz(); }
	~k_macierz() { for (int i=0; i < rozmiar; ++i) delete[] macierz[i];
					delete[] macierz; }
};
void k_macierz::Wyswietl_macierz() {
	cout << "Macierz grafu wraz z wagami:" << endl << "   ";
	for (int j = 0; j < rozmiar; ++j) cout << "  " << j; //kolumny
	cout << endl<< "   ";
	for (int j = 0; j < rozmiar; ++j) cout << "___";
	for (int i = 0; i < rozmiar; ++i) { cout << endl << i << " | "; //kolejne rzêdy
		for (int j = 0; j < rozmiar; ++j) {					//wagi wierzcho³ków w rzêdzie,
			if (macierz[i][j] >= 0) cout << macierz[i][j] << "  "; else cout << "  "; } // lub puste elementy, (-1) z wyzerowanej macierzy
	}	cout << endl << endl;
}

void k_macierz::Wyzeruj_macierz() {
	for (int i = 0; i < rozmiar; ++i) {
		for (int j = 0; j < rozmiar; ++j)
			macierz[i][j] = (-1); } // wagi rowne -1 jako wyzerowanie, poniewa¿ mo¿e siê trafiæ waga = 0
}

bool k_macierz::Wczytaj_txt() {
	string nazwa;
	fstream plik;
	int i, j, w;

	cout << endl << "Podaj nazwê pliku do wczytania: " << endl;
	cin >> nazwa;
	Zbadaj_plik(nazwa);
	plik.open(nazwa, ios::in);
	if (plik.good()) {
		macierz = new TYP *[rozmiar];			// alokujemy nowa macierz o znanym rozmiarze
		for (i = 0; i < rozmiar; ++i) macierz[i] = new TYP[rozmiar]; //dwuwymiarowa
		Wyzeruj_macierz();	//i ja zerujemy
		
		while (!plik.eof()) { plik >> i >> j >> w;
							macierz[i][j] = w;
							macierz[j][i] = w; } //wczytywanie do macierzy
		plik.close();
		return true;
	}
	else cout << "Nie otworzono pliku." << endl;  return false;
}
bool k_macierz::Zapisz_txt() {
	string nazwa;
	fstream plik;

	cout << endl << "Podaj nazwê pliku do zapisu:" << endl;
	cin >> nazwa;

	plik.open(nazwa, ios::out);

	if (plik.good() == true) { //zapisywanie do pliku
		for (int i = 0; i < rozmiar; ++i) {
			for (int j = i; j < rozmiar; ++j) //zapisujemy tylko polowe macierzy, od przek¹tnej - macierz jest symetryczna
			if (macierz[i][j] >= 0) plik << i << "       " << j << "       " << macierz[i][j] << endl;
		}
		plik << endl;
		plik.close();
		return true;
	}
	else cout << "Nie utworzono pliku." << endl;  return false;
}

int k_macierz::Zbadaj_plik(string n) {
	fstream plik;
	rozmiar = 0;
	int i=-1,j=-1,zero=1;
	
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
void Program_macierz(){
	k_macierz graf;
	int wybor;
	cout << "Program umo¿liwia wczytanie grafu z pliku do macierzy\n\ti wyœwietlenie go w tej formie, a nastêpnie zapis do pliku." << endl;
	do {
		cout << "1. Wczytaj graf z pliku tekstowego." << endl;
		cout << "2. Wyœwietl wczytany graf w formie macierzowej." << endl;
		cout << "3. Zapisz graf do pliku tekstowego." << endl;
		cout << "0. Wyjœcie do menu wyboru formy grafu." << endl;
		cout << "Wybierz opcjê:\t";
		cin >> wybor;
		switch (wybor) {
		case 0: break;
		case 1: graf.Wczytaj_txt(); break;
		case 2: graf.Wyswietl_macierz(); break;
		case 3: graf.Zapisz_txt(); break;
		default: cout << "Nieprawidlowy wybor, sprobuj ponownie." << endl << endl; break;
		}
	} while (wybor != 0);
}
#endif