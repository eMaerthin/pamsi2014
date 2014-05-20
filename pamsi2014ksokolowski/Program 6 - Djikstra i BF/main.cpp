#include <iostream>
#include <fstream>

#include "Graf.hpp"

using namespace std;

//Funkcja wylicza sredni czas wykonywania wybranego algorytmu dla przeslanego zbioru grafow
//Argumenty: tab - tablica zawierajaca wzorce grafow
//			 algorytm - 'D' - jezeli chcemy wybrac algorytm Dijkstry, 'B' - dla alg. Bellmana-Forda
//			 reprez - 'L' - reprezentacja grafu listowa, 'T' - reprezentacja grafu tablicowa
//			 l_elementow - rozmiar tablicy tab
template <class TYP>
double pobierz_sredni_czas(Graf<TYP> tab[], const char algorytm, const char reprez, const int l_elementow)
{
	int suma_czasow = 0;
	int ile = l_elementow;

	while (ile--){
		std::cout << ile << algorytm << reprez << " ";
		switch (algorytm){
		case 'D': {  tab[ile].alg_Dijkstry(reprez, 0);
			break;	 }
		case 'B': { tab[ile].alg_BF(reprez, 0);
			break; }
		}
		suma_czasow += tab[ile]._czas();
	}
	return (suma_czasow / l_elementow);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Przeprowadzenie eksperymentu, w ktorym to wyliczane sa srednie czasy wykonywania algorytmow
//Dijkstry oraz Bellmana-Forda dla reprezentacji listowej oraz tablicowej
void eksperyment()
{
	const int l_grafow = 100;
	Graf<int> tab[l_grafow];
	int l_elementow[] = { 50, 100, 200, 400 };
	double prawdop[] = { 0.25, 0.5, 0.75, 1 };

	ofstream plik("eksperyment4.txt");

	plik << "Typ algorytmu\tLiczba ele\tPrawdop\tCzas\n";

	for (int i = 0; i < 4; i++){
		for (int p = 0; p < 4; p++){
			for (int j = 0; j < l_grafow; j++){
				tab[j].graf_ER(l_elementow[i], prawdop[p], 1, 500);
			}
			plik << "DijkstryTablica\t" << l_elementow[i] << "\t" << prawdop[p] << "\t" << pobierz_sredni_czas(tab, 'D', 'T', l_grafow) << endl;
		}
	}
	for (int i = 0; i < 4; i++){
		for (int p = 0; p < 4; p++){
			for (int j = 0; j < l_grafow; j++){
				tab[j].graf_ER(l_elementow[i], prawdop[p], 1, 500);
			}
			plik << "DijkstryLista\t" << l_elementow[i] << "\t" << prawdop[p] << "\t" << pobierz_sredni_czas(tab, 'D', 'L', l_grafow) << endl;
		}
	}
	for (int i = 0; i < 4; i++){
		for (int p = 0; p < 4; p++){
			for (int j = 0; j < l_grafow; j++){
				tab[j].graf_ER(l_elementow[i], prawdop[p], -10, 1000);
				if (!tab[j].alg_BF(0, 'L')){
					--j;
				}
			}
			plik << "BFTablica\t" << l_elementow[i] << "\t" << prawdop[p] << "\t" << pobierz_sredni_czas(tab, 'B', 'T', l_grafow) << endl;
		}
	}
	for (int i = 0; i < 4; i++){
		for (int p = 0; p < 4; p++){
			for (int j = 0; j < l_grafow; j++){
				tab[j].graf_ER(l_elementow[i], prawdop[p], -10, 1000);
				if (!tab[j].alg_BF(0, 'L')){
					--j;
				}
			}
			plik << "BFLista\t" << l_elementow[i] << "\t" << prawdop[p] << "\t" << pobierz_sredni_czas(tab, 'B', 'L', l_grafow) << endl;
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Proste menu udostepniajace funkcje w programie
void menu()
{
	int wybor;
	Graf<int> graf;

	while (true){
		std::cout << "\n********** MENU **********" << endl
			<< "1. Wczytaj graf z pliku" << endl
			<< "2. Zapisz trasy do pliku" << endl
			<< "3. Wykonaj algorytm Dijkstry dla grafu z reprezentacja listowa" << endl
			<< "4. Wykonaj algorytm Bellmana-Forda dla grafu z reprezentacja listowa" << endl
			<< "5. Wykonaj algorytm Dijkstry dla grafu z reprezentacja tablicowa" << endl
			<< "6. Wykonaj algorytm Bellmana-Forda dla grafu z reprezentacja tablicowa" << endl
			<< "0. Wyjscie z programu" << endl
			<< "Twoj wybor:\t";

		cin >> wybor;

		switch (wybor){
		case 1: {
					std::string nazwa;
					std::cout << "\nPodaj sciezke do pliku: ";
					std::cin >> nazwa;
					graf.wczytaj_graf_z_pliku(nazwa);
					break;
		}
		case 2:{
				   std::string nazwa;
				   std::cout << "\nPodaj sciezke do pliku: ";
				   std::cin >> nazwa;
				   graf.zapisz_trasy_do_pliku(nazwa);
				   break;
		}
		case 3:{
				   graf.alg_Dijkstry('L');
				   break;
		}
		case 4:{
				   graf.alg_BF('L');
				   break;
		}
		case 5:{
				   graf.alg_Dijkstry('T');
				   break;
		}
		case 6:{
				   graf.alg_BF('T');
				   break;
		}
		case 0:{
				   return;
		}
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	menu();

	return 0;
}
