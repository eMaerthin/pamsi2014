#ifndef EKSPERYMENT_HH
#define EKSPERYMENT_HH
#define TYP int
#include <iostream>
#include <boost/date_time/posix_time/posix_time.hpp>
#include "babel.hh"//sortowania
#include "wybor.hh"
#include "scalanie.hh"
#include "rozklad.hh"

using namespace boost::posix_time;

//W programie eksperyment zakomentowany jest fragment kodu, ktory pozwala na zapytanie u¿ytkownika, ilukrotnie sortowaæ tablicê ka¿dym z algorytmów.
//Na potrzeby za³o¿eñ programu pozostaje on domyslnie zakomentowany.

void eksperyment_sortuj_rosnaco(TYP * tablica, TYP *s_tablica, int rozmiar, int ile) {
	double sr_czas1 = 0, sr_czas2 = 0, sr_czas3 = 0;
	for (int i = 0; i < ile; i++) {
		for (i = 0; i < rozmiar; i++) s_tablica[i] = tablica[i]; //odswiezenie tablicy do sortowania przed kolejnym sortowaniem
		ptime czas1 = microsec_clock::local_time();
		sort_babelkowe_rosn(s_tablica, rozmiar);
		ptime czas2 = microsec_clock::local_time();
		time_duration czas = czas2 - czas1; //roznica czasu, rzeczywisty czas wykonywania algorytmu
		sr_czas1 += czas.total_milliseconds();
	} cout << "\tAlgorytm sortowania babelkowego: " << (sr_czas1 / ile) << " ms" << endl;
	for (int i = 0; i < ile; i++) {
		for (i = 0; i < rozmiar; i++) s_tablica[i] = tablica[i]; //odswiezenie tablicy do sortowania przed kolejnym sortowaniem
		ptime czas1 = microsec_clock::local_time();
		sort_wybor_rosn(s_tablica, rozmiar);
		ptime czas2 = microsec_clock::local_time();
		time_duration czas = czas2 - czas1; //roznica czasu, rzeczywisty czas wykonywania algorytmu
		sr_czas2 += czas.total_milliseconds();
	} cout << "\tAlgorytm sortowania przez wybor: " << (sr_czas2 / ile) << " ms" << endl;
	for (int i = 0; i < ile; i++) {
		for (i = 0; i < rozmiar; i++) s_tablica[i] = tablica[i]; //odswiezenie tablicy do sortowania przed kolejnym sortowaniem
		ptime czas1 = microsec_clock::local_time();
		sort_scalanie_rosn(s_tablica, 0, rozmiar - 1);
		ptime czas2 = microsec_clock::local_time();
		time_duration czas = czas2 - czas1; //roznica czasu, rzeczywisty czas wykonywania algorytmu
		sr_czas3 += czas.total_milliseconds();
	} cout << "\tAlgorytm sortowania przez scalanie: " << (sr_czas3 / ile) << " ms" << endl;
}
void eksperyment_sortuj_malejaco(TYP * tablica, TYP *s_tablica, int rozmiar, int ile){
	double sr_czas1 = 0, sr_czas2 = 0, sr_czas3 = 0;
	for (int i = 0; i < ile; i++) {
		for (i = 0; i < rozmiar; i++) s_tablica[i] = tablica[i]; //odswiezenie tablicy do sortowania przed kolejnym sortowaniem
		ptime czas1 = microsec_clock::local_time();
		sort_babelkowe_malej(s_tablica, rozmiar);
		ptime czas2 = microsec_clock::local_time();
		time_duration czas = czas2 - czas1; //roznica czasu, rzeczywisty czas wykonywania algorytmu
		sr_czas1 += czas.total_milliseconds();
	} cout << "\tAlgorytm sortowania babelkowego: " << (sr_czas1 / ile) << " ms" << endl;
	for (int i = 0; i < ile; i++) {
		for (i = 0; i < rozmiar; i++) s_tablica[i] = tablica[i]; //odswiezenie tablicy do sortowania przed kolejnym sortowaniem
		ptime czas1 = microsec_clock::local_time();
		sort_wybor_malej(s_tablica, rozmiar);
		ptime czas2 = microsec_clock::local_time();
		time_duration czas = czas2 - czas1; //roznica czasu, rzeczywisty czas wykonywania algorytmu
		sr_czas2 += czas.total_milliseconds();
	} cout << "\tAlgorytm sortowania przez wybor: " << (sr_czas2 / ile) << " ms" << endl;
	for (int i = 0; i < ile; i++) {
		for (i = 0; i < rozmiar; i++) s_tablica[i] = tablica[i]; //odswiezenie tablicy do sortowania przed kolejnym sortowaniem
		ptime czas1 = microsec_clock::local_time();
		sort_scalanie_malej(s_tablica, 0, rozmiar - 1);
		ptime czas2 = microsec_clock::local_time();
		time_duration czas = czas2 - czas1; //roznica czasu, rzeczywisty czas wykonywania algorytmu
		sr_czas3 += czas.total_milliseconds();
	} cout << "\tAlgorytm sortowania przez wybor: " << (sr_czas3 / ile) << " ms" << endl;
}
void eksperyment() {
	int rozmiar, ile, i;
	do {
	cout << "Program eksperyment generuj¹cy wybrane dane i sortuj¹cy dostêpnymi algorytmami." << endl;
	cout << "Podaj iloœæ elementów do posortowania:\t";
	cin >> rozmiar; //wczytanie rozmiaru deklarowanej tablicy
} while (!(rozmiar > 0));
	TYP * tablica = new TYP[rozmiar];	//deklaracja tablicy o odpowiedniej iloœci elementów
	TYP * s_tablica = new TYP[rozmiar]; //deklaracja tablicy do sortowania
	do {
		cout << "1. Sortowanie tablicy wypelnionej rozkladem normalnym." << endl;
		cout << "2. Sortowanie tablicy wypelnionej rozkladem jednostajnym." << endl;
		cout << "3. Sortowanie tablicy wypelnionej rozkladem poissona." << endl;
		cout << "Wybierz program:\t";
		cin >> i;
		switch (i) {
		case 1: Wypelnij_rozklad_normalny(tablica, rozmiar); i = 0; break;
		case 2: Wypelnij_rozklad_jednostajny(tablica, rozmiar); i = 0; break;
		case 3: Wypelnij_rozklad_poissona(tablica, rozmiar); i = 0; break;
		default: cout << "Nieprawidlowy wybor, sprobuj ponownie." << endl; break;
		}
	} while (i != 0);
	do {
		cout << endl << endl << "1. Sortowanie nieuporz¹dkowanej tablicy rosn¹co." << endl;
		cout << "2. Sortowanie nieuporz¹dkowanej tablicy malej¹co." << endl;
		cout << "3. Sortowanie tablicy z 10 % uporzadkowanymi elementami rosn¹co." << endl; //posortowanie pierwszego X % danych w tablicy
		cout << "4. Sortowanie tablicy z 10 % uporzadkowanymi elementami malej¹co." << endl; //dokonane jest za pomoc¹ algorytmu sortowania
		cout << "5. Sortowanie tablicy z 50 % uporzadkowanymi elementami rosn¹co." << endl;	//przez scalanie ze wzgledu na jego najmniejsza
		cout << "6. Sortowanie tablicy z 50 % uporzadkowanymi elementami malej¹co." << endl; //zlozonosc obliczeniowa
		cout << "7. Sortowanie tablicy z 90 % uporzadkowanymi elementami rosn¹co." << endl;
		cout << "8. Sortowanie tablicy z 90 % uporzadkowanymi elementami malej¹co." << endl;
		cout << "0. Wyjscie z programu eksperyment." << endl;
		cout << "Wybierz rodzaj sortowania:\t";
		cin >> i;
//		cout << endl << "Podaj iloœæ powtórzeñ sortowania danych ka¿dym algorytmem:" << endl;
//		cin >> ile;
		ile = 100; //pozostawiona mo¿liwoœæ zmiany programu i pytania o ilosc/wyboru iloœci powtórzeñ sortowania dla ka¿dego algorytmu
		cout << endl << "\tCzekaj...\n\n" << "Sredni czas pomierzony dla n = " << ile << " powtorzen:\n";
		switch (i) {
		case 0: break;
		case 1:	{ eksperyment_sortuj_rosnaco(tablica, s_tablica, rozmiar, ile); break; } //losowo - rosnaco
		case 2: { eksperyment_sortuj_malejaco(tablica, s_tablica, rozmiar, ile); break; } //losowo - malejaco
		case 3: { sort_scalanie_rosn(tablica, 0, (rozmiar / 10));
					eksperyment_sortuj_rosnaco(tablica, s_tablica, rozmiar, ile); break; } //10% posortowane - rosnaco
		case 4: { sort_scalanie_malej(tablica, 0, (rozmiar / 10));
					eksperyment_sortuj_malejaco(tablica, s_tablica, rozmiar, ile); break; } //10% posortowane - malejaco
		case 5: { sort_scalanie_rosn(tablica, 0, (rozmiar / 2));
					eksperyment_sortuj_rosnaco(tablica, s_tablica, rozmiar, ile); break; } //50% posortowane - rosnaco
		case 6: { sort_scalanie_malej(tablica, 0, (rozmiar / 2));
					eksperyment_sortuj_malejaco(tablica, s_tablica, rozmiar, ile); break; } //50% posortowane - malejaco
		case 7: { sort_scalanie_rosn(tablica, 0, ((9 * rozmiar) / 10));
					eksperyment_sortuj_rosnaco(tablica, s_tablica, rozmiar, ile); break; } //90% posortowane - rosnaco
		case 8: { sort_scalanie_malej(tablica, 0, ((9 * rozmiar) / 10));
					eksperyment_sortuj_malejaco(tablica, s_tablica, rozmiar, ile); break; } //90% posortowane - malejaco
		default: cout << "Nieprawidlowy wybor, sprobuj ponownie." << endl; break;
		}
	} while (i != 0);
}
#endif