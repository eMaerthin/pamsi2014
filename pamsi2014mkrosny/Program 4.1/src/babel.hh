#ifndef BABEL_HH
#define BABEL_HH
#include <boost/timer/timer.hpp>

void sort_babelkowe_rosn(TYP * dane, int rozmiar) {
	TYP temp;
	boost::timer::auto_cpu_timer czas("Czas wykonywania algorytmu: %t sekund CPU, rzeczywisty: %w sekund\n");
	for (int i = 0; i < rozmiar; i++) { //krotnoœæ sortowania równa ilosci elementów - najgorszy przypadek
		for (int j = i+1; j < rozmiar; j++) { //sortowanie poszczególnych elementów
			if (dane[i] > dane[j]) {     //jesli elementy s¹ u³o¿one malej¹co
				temp = dane[j];      //przechowanie wiêkszego elementu
				dane[j] = dane[i]; //przypisanie elementu wiêkszego na dalszym miejscu
				dane[i] = temp; }	 //przypisanie mniejszego elementu na wczeœniejszym miejscu
	} }
}

void sort_babelkowe_malej(TYP * dane, int rozmiar) {
	TYP temp;
	boost::timer::auto_cpu_timer czas("Czas wykonywania algorytmu: %t sekund CPU, rzeczywisty: %w sekund\n");
	for (int i = 0; i < rozmiar; i++) { //krotnoœæ sortowania równa ilosci elementów - najgorszy przypadek
		for (int j = i+1; j < rozmiar; j++) { //sortowanie poszczególnych elementów
			if (dane[i] < dane[j]) {     //jesli elementy s¹ u³o¿one rosn¹co
				temp = dane[j];      //przechowanie mniejszego elementu
				dane[j] = dane[i]; //przypisanie elementu mniejszego na dalszym miejscu
				dane[i] = temp;	}	 //przypisanie wiêkszego elementu na wczeœniejszym miejscu
	} }
}
#endif