#ifndef BABEL_HH
#define BABEL_HH
#include <boost/timer/timer.hpp>

void sort_babelkowe_rosn(TYP * dane, int rozmiar) {
	TYP temp;
	boost::timer::auto_cpu_timer czas("Czas wykonywania algorytmu: %t sekund CPU, rzeczywisty: %w sekund\n");
	for (int i = 0; i < rozmiar; i++) { //krotno�� sortowania r�wna ilosci element�w - najgorszy przypadek
		for (int j = i+1; j < rozmiar; j++) { //sortowanie poszczeg�lnych element�w
			if (dane[i] > dane[j]) {     //jesli elementy s� u�o�one malej�co
				temp = dane[j];      //przechowanie wi�kszego elementu
				dane[j] = dane[i]; //przypisanie elementu wi�kszego na dalszym miejscu
				dane[i] = temp; }	 //przypisanie mniejszego elementu na wcze�niejszym miejscu
	} }
}

void sort_babelkowe_malej(TYP * dane, int rozmiar) {
	TYP temp;
	boost::timer::auto_cpu_timer czas("Czas wykonywania algorytmu: %t sekund CPU, rzeczywisty: %w sekund\n");
	for (int i = 0; i < rozmiar; i++) { //krotno�� sortowania r�wna ilosci element�w - najgorszy przypadek
		for (int j = i+1; j < rozmiar; j++) { //sortowanie poszczeg�lnych element�w
			if (dane[i] < dane[j]) {     //jesli elementy s� u�o�one rosn�co
				temp = dane[j];      //przechowanie mniejszego elementu
				dane[j] = dane[i]; //przypisanie elementu mniejszego na dalszym miejscu
				dane[i] = temp;	}	 //przypisanie wi�kszego elementu na wcze�niejszym miejscu
	} }
}
#endif