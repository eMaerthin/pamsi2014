#ifndef TABLICA_KLASA_HH
#define TABLICA_KLASA_HH
#define TABLICA queue<int>

#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <cstdlib>

using namespace std;

template <class TABLICA>
class Tablica {
	TABLICA *tablica;

public:
	Tablica() : tablica();
	~Tablica() { delete[] tablica;  }
	
	Tablica<TABLICA>& Wczytywanie_Konsola();
	void Wyswietl_Konsola() const;
	Tablica<TABLICA>& Wczytaj_TXT();
	void Zapisz_TXT() const;
	Tablica<TABLICA>& Wczytaj_BIN();
	void Zapisz_BIN() const;
	Tablica<TABLICA>& Wypelnij_Losowo();
	Tablica<TABLICA>& operator=(Tablica<TABLICA>& Kopia);
};

template <class TABLICA>
Tablica<TABLICA>& Tablica<TABLICA>::Wczytywanie_Konsola() {
	string temp;
	string koniec("#");
	int elem;

	if (!tablica.empty()) do tablica.pop(); while (!tablica.empty()); //czyszczenie tablicy w pamieci przed wczytaniem nowej

	cout << endl << "Podaj kolejne elementy tablicy. Wpisz # aby zakoñczyæ dodawanie elementów." << endl << endl;
	do {
		temp.clear();
		cin >> temp;
		if (temp.compare(koniec) == 0) break; //sprawdzenie, czy wczytano sygnal stop
		else elem = stoi(temp);
		elem >> tablica;
	} while (elem>0);

	return *this;
}

template <class TABLICA>
void Tablica<TABLICA>::Wyswietl_Konsola() const {
	cout << endl << "Tablica elementów: " << endl << tablica << endl << "___________________________________" << endl;
}

template <class TABLICA>
Tablica<TABLICA>& Tablica<TABLICA>::Wczytaj_TXT() {
	string nazwa;
	string linia;
	fstream plik;
	int elem;

	if (!tablica.empty()) do tablica.pop(); while (!tablica.empty()); //czyszczenie tablicy w pamieci przed wczytaniem nowej

	cout << endl << "Podaj nazwê pliku: " << endl;
	cin >> nazwa;
	plik.open(nazwa, ios::in);
	if (plik.good()) {
		while (getline(plik, linia))  { //wczytywanie do zmiennej tymczasowej
			elem = stoi(linia); //konwersja
			elem >> tablica; //wczytanie do tablicy
		}
		plik.close();
	}
	return *this;
}

template <class TABLICA>
void Tablica<TABLICA>::Zapisz_TXT() const {
	string nazwa;
	string linia;
	fstream plik;

	cout << endl << "Podaj nazwê pliku:" << endl;
	cin >> nazwa;

	plik.open(nazwa, ios::out);

	if (plik.good() == true) {
		while (plik << tablica.front()) { //zapisywanie do pliku
			plik << endl;
			tablica.pop();
		}
	}
	plik.close();
}

template <class TABLICA>
Tablica<TABLICA>& Tablica<TABLICA>::Wczytaj_BIN() {
	string nazwa;
	fstream plik;
	char bufor[256];
	int elem;

	if (!tablica.empty()) do tablica.pop(); while (!tablica.empty()); //czyszczenie tablicy w pamieci przed wczytaniem nowej

	cout << endl << "Podaj nazwê pliku: " << endl;
	cin >> nazwa;
	plik.open(nazwa, ios::in, ios::binary);

	int l = 0;
	do {
		plik.read((char*)bufor + l, sizeof(char)); //wczytanie kolejnych blokow do tymczasowej zmiennej
		if ((int)bufor[l] != -52) ++l; //sprawdzenie warunku poprawnoœci odczytanego bloku i indeksowanie kolejnych danych w pliku binarnym
	} while (!plik.eof());

	for (int i = 0; i < l; i++) {
		elem = (int)bufor[i]; //konwersja
		elem >> tablica;  //wczytanie do tablicy
	}
	plik.close();
	return *this;
}

template <class TABLICA>
void Tablica<TABLICA>::Zapisz_BIN() const {
	string nazwa;
	char bufor[256];
	fstream plik;

	cout << endl << "Podaj nazwê pliku:" << endl;
	cin >> nazwa;

	plik.open(nazwa, ios::out, ios::binary);

	int i = 0;
	while (!tablica.empty()) {
		bufor[i] = (char)tablica.front();  //przygotowanie buforu do zapisu
		tablica.pop();
		i++;
	}

	if (plik.good() == true) {
		for (i = 0; i < sizeof(bufor); i++) //indeksowanie kolejnych blokow danych w buforze
			plik.write((char*)bufor + i, sizeof(char)); //zapisywanie kolejnych blokow danych z bufora do pliku binarnego
	}
	plik.close();
}

template <class TABLICA>
Tablica<TABLICA>& Tablica<TABLICA>::Wypelnij_Losowo() {
	int ile, elem;

	if (!tablica.empty()) do tablica.pop(); while (!tablica.empty()); //czyszczenie tablicy w pamieci przed wczytaniem nowej

	cout << endl << "Podaj iloœæ losowych liczb w tablicy:" << endl;
	cin >> ile;
	while (ile>0) {
		ile--;
		elem = rand(); //losowanie liczby
		elem >> tablica; //wczytanie liczby do tablicy
	}
	return *this;
}

template <class TABLICA>
Tablica<TABLICA>& Tablica<TABLICA>::operator=(Tablica<TABLICA>& Kopia) {
	if (tablica.size() == NULL) { cout << "Tablica jest pusta!" << endl; return *this; }

	tablica = new TABLICA;
	tablica = Kopia.tablica;
	Wyswietl_Konsola();
	return *this;
}
#endif