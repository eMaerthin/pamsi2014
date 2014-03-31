#ifndef TABLICA_KLASA_HH
#define TABLICA_KLASA_HH
#define TYP int

#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <cstdlib>

using namespace std;

template <typename Tab>
class Tablica {
private:
	queue<TYP> *tablica;

public:
	void Wczytywanie_Konsola();
	void Wyswietl_Konsola() const;
	void Wczytaj_TXT();
	void Zapisz_TXT() const;
	void Wczytaj_BIN();
	void Zapisz_BIN() const;
	void Wypelnij_Losowo();
	Tablica<Tab> operator=(Tablica tab);
};

template <typename Tab>
void Tablica <Tab>::Wczytywanie_Konsola() {
	string temp;
	string koniec("#");
	TYP elem;

	while (!tablica->empty()) tablica->pop(); //czyszczenie tablicy w pamieci przed wczytaniem nowej

	cout << endl << "Podaj kolejne elementy tablicy. Wpisz # aby zakoñczyæ dodawanie elementów." << endl << endl;
	do {
		temp.clear();
		cin >> temp;
		if (temp.compare(koniec) == 0) break; //sprawdzenie, czy wczytano sygnal stop
		else elem = stoi(temp);
		tablica->push(elem);
	} while (elem > 0);
}

template <typename Tab>
void Tablica<Tab>::Wyswietl_Konsola() const {
	cout << endl << "Tablica elementów: " << endl;
	TYP elem;
	while (!tablica->empty()) { elem = tablica->front(); tablica->pop(); cout << elem << endl; }
}

template <typename Tab>
void Tablica<Tab>::Wczytaj_TXT() {
	string nazwa;
	string linia;
	fstream plik;
	TYP elem;

	while (!tablica->empty()) tablica->pop(); //czyszczenie tablicy w pamieci przed wczytaniem nowej

	cout << endl << "Podaj nazwê pliku: " << endl;
	cin >> nazwa;
	plik.open(nazwa, ios::in);
	if (plik.good()) {
		while (getline(plik, linia))  { //wczytywanie do zmiennej tymczasowej
			elem = stoi(linia); //konwersja
			tablica->push(elem); //wczytanie do tablicy
		}
		plik.close();
	}
}

template <typename Tab>
void Tablica<Tab>::Zapisz_TXT() const {
	string nazwa;
	string linia;
	fstream plik;

	cout << endl << "Podaj nazwê pliku:" << endl;
	cin >> nazwa;

	plik.open(nazwa, ios::out);

	if (plik.good() == true) {
		while (plik << tablica->front()) { //zapisywanie do pliku
			plik << endl;
			tablica->pop();
		}
	}
	plik.close();
}

template <typename Tab>
void Tablica<Tab>::Wczytaj_BIN() {
	string nazwa;
	fstream plik;
	char bufor[256];
	TYP elem;

	while (!tablica->empty()) tablica->pop(); //czyszczenie tablicy w pamieci przed wczytaniem nowej

	cout << endl << "Podaj nazwê pliku: " << endl;
	cin >> nazwa;
	plik.open(nazwa, ios::in, ios::binary);

	int l = 0;
	do {
		plik.read((char*)bufor + l, sizeof(char)); //wczytanie kolejnych blokow do tymczasowej zmiennej
		if ((int)bufor[l] != -52) ++l; //sprawdzenie warunku poprawnoœci odczytanego bloku i indeksowanie kolejnych danych w pliku binarnym
	} while (!plik.eof());

	for (int i = 0; i < l; i++) {
		elem = (TYP)bufor[i]; //konwersja
		tablica->push(elem);  //wczytanie do tablicy
	}
	plik.close();
}

template <typename Tab>
void Tablica<Tab>::Zapisz_BIN() const {
	string nazwa;
	char bufor[256];
	fstream plik;

	cout << endl << "Podaj nazwê pliku:" << endl;
	cin >> nazwa;

	plik.open(nazwa, ios::out, ios::binary);

	int i = 0;
	while (!tablica->empty()) {
		bufor[i] = (char)tablica->front();  //przygotowanie buforu do zapisu
		tablica->pop();
		i++;
	}

	if (plik.good() == true) {
		for (i = 0; i < sizeof(bufor); i++) //indeksowanie kolejnych blokow danych w buforze
			plik.write((char*)bufor + i, sizeof(char)); //zapisywanie kolejnych blokow danych z bufora do pliku binarnego
	}
	plik.close();
}

template <typename Tab>
void Tablica<Tab>::Wypelnij_Losowo() {
	int ile;
	TYP elem;
	while (!tablica->empty()) tablica->pop(); //czyszczenie tablicy w pamieci przed wczytaniem nowej

	cout << endl << "Podaj iloœæ losowych liczb w tablicy:" << endl;
	cin >> ile;
	while (ile>0) {
		ile--;
		elem = rand(); //losowanie liczby
		tablica->push(elem); //wczytanie liczby do tablicy
	}
}

template <typename Tab>
Tablica<Tab> Tablica<Tab>::operator=(Tablica tab) {
	if (tablica->size() == NULL) { cout << "Tablica jest pusta!" << endl; return *this; }

	tab.tablica = tablica;
	return tab;
}
#endif