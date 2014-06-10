#include <iostream>

class wierzcholek			// wierzcholki grafu
{
public:
	wierzcholek *n;			// wskaŸnik na nastêpnik
	int indeks;
	int waga;
};
class krawedzie				// krawedzie grafu
{
public:
	int p;
	int n;
	int waga;

	krawedzie() : p(-1), n(-1), waga(-1) {}
};

class lista
{
public:
	wierzcholek *w;

	void dodaj(int indeks, int waga);
	void wypisz();
	void wypisz_do_pliku(std::ofstream& p);
};

class graf_lista
{
public:
	int v;							// liczba wierzcho³ków
	lista **list;

	graf_lista() :v(0){}
	graf_lista(int s) : v(s){
		list = new lista*[s];		// tablica list
	}

	void wypisz();
	void wypisz_do_pliku(std::ofstream& p);
	void konwertuj(int **M);		// konwersja macierz -> lista
};

class graf_macierz
{
public:
	int v;				// liczba wierzcho³ków
	int **macierz_wag;			// reprezentacja macierzy jako tab dwuwymiarowej liczb ca³kowitych

	graf_macierz();
	graf_macierz(int ile);	// konstruktor tworzacy macierz ile x ile
	graf_macierz(int **tab, int rozmiar); // konstruktor tworzacy macierz na podstawie do³¹czonej tablicy

	void wylosuj(int wsp);		// metoda generowania losowych macierzy
	void wyczysc();				// wyzerowanie macierzy
	void wypisz();
	void wypisz_do_pliku(std::ofstream& p);
};