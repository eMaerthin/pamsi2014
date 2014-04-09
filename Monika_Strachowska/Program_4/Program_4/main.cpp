#include <iostream>
#include "BubbleSort.h"
#include "ShellSort.h"
#include "QuickSort.h"
#include "Tablica.h"
#include <vector>
#include <Windows.h>
#include <fstream>

void usrednianieCzasu(std::vector<long double> &);
//void menu();
void eksperyment(int, int, int, int);


int main() {
	//menu();
	//rozmiar//rozklad 0-2//uporzadkowanie 0-3//sortowanie 0-2
	int rozmiar = 1000000;
	std::cout << "START\n";
	std::cout << "....................................\n";
	/*for(int sortowanie = 2; sortowanie < 3; sortowanie++)
		for(int rozklad = 1; rozklad < 3; rozklad++)
			for(int uporzadkowanie = 0; uporzadkowanie < 4; uporzadkowanie++) {
				eksperyment(rozmiar,rozklad,uporzadkowanie,sortowanie);
				std::cout << ".";
			}*/

	
	eksperyment(rozmiar,2,2,2);
	eksperyment(rozmiar,2,3,2);
	std::cout<<"\n";
	system("PAUSE");
	return 0;
}


//void menu() {
//	std::cout << "Witaj! Ile elementow ma miec tablica?\n>";
//	int n = 0;
//	std::cin >> n;
//	std::cout << "\n0 - sortowanie tablicy z rozkladu jednostajnego\n"
//		<< "1 - sortowanie tablicy z rozkladu normalnego\n"
//		<< "2 - sortowanie tablicy z rozkladu Poissona\n>";
//	int rozklad = 0;
//	std::cin >> rozklad;
//	std::cout << "\n0 - sortowanie tablicy nieuporzadkowanej\n"
//		<< "1 - sortowanie tablicy z 10% uporzadkowanymi elementami\n"
//		<< "2 - sortowanie tablicy z 50% uporzadkowanymi elementami\n"
//		<< "3 - sortowanie tablicy z 90% uporzadkowanymi elementami\n>";
//	int uporzadkowanie = 0;
//	std::cin >> uporzadkowanie;
//	std::cout << "\n0 - sortowanie babelkowe\n"
//		<< "1 - sortowanie shella\n"
//		<< "2 - sortowanie quick sort\n";
//	int ktore = 0;
//	std::cin >> ktore;
//	///*if(ktore == 0)*/ BubbleSort BS(n,rozklad,uporzadkowanie);
//	///*else if(ktore == 1)*/ ShellSort SS(n,rozklad,uporzadkowanie);
//	///*else if(ktore == 2)*/ QuickSort QS(n,rozklad,uporzadkowanie);
//	eksperyment(n,rozklad,uporzadkowanie,ktore);
//}


void eksperyment(int rozmiar, int rozklad, int uporzadkowanie, int sortowanie) {
	int iloscPetli = 100;
	std::vector <long double> czas;
	if(sortowanie == 0) {
		for(int i = 0; i < iloscPetli; i++) {
			BubbleSort BS(rozmiar,rozklad,uporzadkowanie);
			czas.push_back(BS.getCzas());
		}
		std::fstream plik("wyniki.txt", std::fstream::out | std::fstream::app);
		plik << "sortowanie_babelkowe\n"
			"Rozmiar_tablicy: " << rozmiar <<
			"\nRozklad_tablicy: " << rozklad <<
			"\nStopien_uporzadkowania: " << uporzadkowanie;
	}
	else if(sortowanie == 1) {
		for(int i = 0; i < iloscPetli; i++) {
			ShellSort SS(rozmiar,rozklad,uporzadkowanie);
			czas.push_back(SS.getCzas());
		}
		std::fstream plik("wyniki.txt", std::fstream::out | std::fstream::app);
		plik << "sortowanie_shellsort\n"
			"Rozmiar_tablicy: " << rozmiar <<
			"\nRozklad_tablicy: " << rozklad <<
			"\nStopien_uporzadkowania: " << uporzadkowanie;
	}
	else if(sortowanie == 2) {
		for(int i = 0; i < iloscPetli; i++) {
			QuickSort QS(rozmiar,rozklad,uporzadkowanie);
			czas.push_back(QS.getCzas());
		}
		std::fstream plik("wyniki.txt", std::fstream::out | std::fstream::app);
		plik << "sortowanie_quicksort\n"
			"Rozmiar_tablicy: " << rozmiar <<
			"\nRozklad_tablicy: " << rozklad <<
			"\nStopien_uporzadkowania: " << uporzadkowanie;
	}
	usrednianieCzasu(czas);
}

void usrednianieCzasu(std::vector <long double> & wektor) {
	
	long double temp = 0;
	for(int i = 0; i < wektor.size(); i++) {
		temp += wektor[i];
	}
	long double wynik = temp/wektor.size();
	std::cout.setf(std::ios::fixed, std::ios::floatfield);
	std::fstream plik("wyniki.txt", std::fstream::out | std::fstream::app);
	plik << "\nSredni_czas(ms): " << wynik << "\n\n";
}
