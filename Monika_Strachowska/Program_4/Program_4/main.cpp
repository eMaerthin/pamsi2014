#include <iostream>
#include "BubbleSort.h"
#include "ShellSort.h"
#include "QuickSort.h"
#include "Tablica.h"
#include <vector>
#include <Windows.h>
#include <fstream>

/********
rozmiar - dowolny
rozklad		
		0 - sortowanie tablicy z rozkladu jednostajnego
		1 - sortowanie tablicy z rozkladu normalnego
		2 - sortowanie tablicy z rozkladu Poissona
uporzadkowanie
		0 - sortowanie tablicy nieuporzadkowanej
		1 - sortowanie tablicy z 10% uporzadkowanymi elementami
		2 - sortowanie tablicy z 50% uporzadkowanymi elementami
		3 - sortowanie tablicy z 90% uporzadkowanymi elementami
sortowanie 
		0 - sortowanie babelkowe
		1 - sortowanie shella
		2 - sortowanie quick sort
*/

void usrednianieCzasu(std::vector<long double> &);
void menu();
void eksperyment(int, int, int, int);


int main() {
	int rozmiar = 0;
	int wybor = 0;
	std::cout << "W jaki sposob chcesz sortowac tablice? \n\n"
		"1 - Automatyczne liczenie wszystkich kombinacji dla zadanego rozmiaru?\n\t (zapis wynikow do pliku, 100 probek)\n\n"
		"2 - Jedno sortowanie, jeden rozmiar, jeden rozklad, jedno uporzadkowanie?\n";
	std::cin >> wybor;
	if(wybor == 1) {
		std::cout << "Ile elementow ma miec tablica?\n";
		std::cin >> rozmiar;
		std::cout << "START\n";
		std::cout << "....................................\n";
		for(int sortowanie = 0; sortowanie < 3; sortowanie++)
			for(int rozklad = 0; rozklad < 3; rozklad++)
				for(int uporzadkowanie = 0; uporzadkowanie < 4; uporzadkowanie++) {
					eksperyment(rozmiar,rozklad,uporzadkowanie,sortowanie);
					std::cout << ".";
				}
	}
	else if(wybor == 2)
		menu();

	std::cout<<"\n";
	system("PAUSE");
	return 0;
}


void menu() {
	std::cout << "Ile elementow ma miec tablica?\n>";
	int n = 0;
	std::cin >> n;
	std::cout << "\n0 - sortowanie tablicy z rozkladu jednostajnego\n"
		<< "1 - sortowanie tablicy z rozkladu normalnego\n"
		<< "2 - sortowanie tablicy z rozkladu Poissona\n>";
	int rozklad = 0;
	std::cin >> rozklad;
	std::cout << "\n0 - sortowanie tablicy nieuporzadkowanej\n"
		<< "1 - sortowanie tablicy z 10% uporzadkowanymi elementami\n"
		<< "2 - sortowanie tablicy z 50% uporzadkowanymi elementami\n"
		<< "3 - sortowanie tablicy z 90% uporzadkowanymi elementami\n>";
	int uporzadkowanie = 0;
	std::cin >> uporzadkowanie;
	std::cout << "\n0 - sortowanie babelkowe\n"
		<< "1 - sortowanie shella\n"
		<< "2 - sortowanie quick sort\n";
	int ktore = 0, tak = 0;
	std::cin >> ktore;
	if(ktore == 0) {
		BubbleSort BS(n,rozklad,uporzadkowanie);
		std::cout << "Czy wyswietlic tablice (1)?\n";
		std::cin >> tak;
		if(tak == 1)
			BS.wyswietlanieTablicy();
		std::cout << std::endl << "Czas sortowania wynosi: " <<
			BS.getCzas() << "\n";
	}
	else if(ktore == 1) {
		ShellSort SS(n,rozklad,uporzadkowanie);
		std::cout << "Czy wyswietlic tablice (1)?\n";
		std::cin >> tak;
		if(tak == 1)
			SS.wyswietlanieTablicy();
		std::cout << std::endl << "Czas sortowania wynosi: " <<
			SS.getCzas() << "\n";
	}
	else if(ktore == 2) {
		QuickSort QS(n,rozklad,uporzadkowanie);
		std::cout << "Czy wyswietlic tablice (1)?\n";
		std::cin >> tak;
		if(tak == 1)
			QS.wyswietlanieTablicy();
		std::cout << std::endl << "Czas sortowania wynosi: " <<
			QS.getCzas() << "\n";
	}
}


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
