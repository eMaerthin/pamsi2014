#include "funkcje.hpp"

using namespace std;

int silnia(int n)
{
	if (n == 0) return 1;
	else return n*silnia(n - 1);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double symbol_newtona(int g, int d)
{
	if (g < d) return 0;

	return (silnia(g) / (silnia(d)*silnia(g - d)));
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double wylosuj_prawdop_log2(int n)
{
	return (3 * log2(n) / n);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double wylosuj_prawdop_min2(int n)
{
	return (1/sqrt(n));
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double wylosuj_prawdop_min3(int n)
{
	return (1/cbrt(n));
}
void funkcja(Drzewo<int> moje){
	cout << endl;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void menu()
{
	char wybor;
	Drzewo<int> minST;
	while (true){
		cout << "\n\n******Wybierz opcje" << endl
			<< "1. Wczytaj graf z pliku." << endl
			<< "2. Zapisz graf do pliku. " << endl
			<< "3. Stworz MST algorytmem Kruskala." << endl
			<< "4. Stworz MST algorytmem Prima." << endl
			<< "5. Stworz MST algorytmem Boruvki." << endl
			<< "6. Wyswietl graf jako liste." << endl
			<< "7. Wyswietl graf jako tablice." << endl
			<< "0. Wyjscie z programu." << endl;

		do{
			cout << "\rTwoj wybor: ";
			wybor = _getch();
		} while (wybor < '0' || wybor > '7');

		cout << endl;
		switch (wybor){

		case '1': {		cout << "\nPodaj sciezke do pliku:\t";
						string sciezka;
						getline(cin, sciezka);
						minST.wczytaj_graf_z_pliku(sciezka);
						break; }
		case '2': {		cout << "\nPodaj sciezke do pliku:\t";
						string sciezka;
						getline(cin, sciezka);
						minST.zapisz_graf_do_pliku(sciezka);
						break; }
		case '3': {		if (minST.pusty()){
						  cout << "\nGraf jest pusty!" << endl;
						  break;
						}
						  minST.alg_Kruskala();
						  break; }
		case '4': {		if (minST.pusty()){
						  cout << "\nGraf jest pusty!" << endl;
						  break;
						}
						  minST.alg_Prima();
						  break; }
		case '5': {		if (minST.pusty()){
						  cout << "\nGraf jest pusty!" << endl;
						  break;
						}
						  minST.alg_Boruvki();
						  break; }
		case '6': {		minST.wyswietl_graf_lista();
						break; }
		case '7': {		minST.wyswietl_graf_tablica();
						break; }
		case '0': {		return; }
		}
	}
}