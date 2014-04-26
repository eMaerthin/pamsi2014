#include <iostream>
#include <stdio.h>
#include "Drzewo.hpp"
#include "Graf.hpp"
#include "funkcje.hpp"

using namespace std;

int main()
{
	Drzewo<int> moje;

	//moje.wczytaj_graf_z_pliku("graf10.txt");
	moje.graf_pelny(10);

	moje.wyswietl_graf_lista();

	cout << endl << endl;

	moje.wyswietl_graf_tablica();

	cout << endl << endl << moje.czy_spojny() << endl << endl;

	/*moje.alg_Kruskala();


	moje.wyswietl_graf_lista();

	cout << endl << endl;

	moje.wyswietl_graf_tablica();

	cout << endl << endl << endl << endl;


	moje.alg_Prima();


	moje.wyswietl_graf_lista();

	cout << endl << endl;

	moje.wyswietl_graf_tablica();

	cout << endl << endl;*/
	//moje.zapisz_graf_do_pliku("nowy_graf.txt");


	system("PAUSE");
	return 0;
}