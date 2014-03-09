#ifndef TABLICA_HH
#define TABLICA_HH

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>	//srand
#include <cstdlib>	//srand


//Klasa ktora tworzy dynamicznie tablice na okreslona liczbe elementow
//Moze ta tablica zarzodzac, np zapisywac, wypisywac na ekranie, kopiowac itd.
template <class TYP>
class Tablica {
	TYP *tablica;
	int rozmiar_tablicy;

public:
	Tablica(int rozmiar = 0) : rozmiar_tablicy(rozmiar), tablica(NULL)
	{
		if (rozmiar != 0){
			tablica = new TYP[rozmiar];
		}
	}
	~Tablica()
	{
		delete[] tablica;
	}
	//////////////////////////////////////////////////////////////
	const int& Rozmiar() const { return rozmiar_tablicy; }
	int& Rozmiar() { return rozmiar_tablicy; }

	//Opisy ponizszych metod sa analogiczne do odpowiadajacym im funkcji w pilku funkcje.h
	//z tylko tym wyjatkiem ze tutaj klasa przechowuje wkaznik na tablice i jej rozmiar wiec nie trzeba
	//przesylac tych zmiennych jako parametry
	//Niektore z tych funkcji zwracaja referencje do uzywanej/edytowanej klasy, aby moc uzywac kaskad
	//W tym programie akurat nie sa stosowane
	Tablica<TYP>& wczytaj_tab_z_konsoli();
	void wyswietl_tablice(std::ostream& strumien = std::cout) const;
	Tablica<TYP>& wczytaj_tab_z_pliku();
	void zapisz_tab_do_pliku() const;
	Tablica<TYP>& wczytaj_tab_z_pliku_binarnego();
	void zapisz_tab_do_pliku_binarnego() const;
	Tablica<TYP>& wypelnij_tablice_losowo();

	//operator przypisania - ma analogiczna funkcje jak funkcja tworzaca kopie (w pliku funkcje.h)
	//Przykladowe uzycie: klasa_DO_ktorej_chcemy_kopiowac = klasa_Z_ktorej_chcemy_kopiowac;
	Tablica<TYP>& operator=(Tablica<TYP>& kopia);
};
////////////////////////////////////////////////////////////////////////////////
template <class TYP>
Tablica<TYP>& Tablica<TYP>::wczytaj_tab_z_konsoli()
{
	if (tablica != NULL) delete[] tablica;

	cout << "\nPodaj rozmiar tablicy:\t";
	cin >> rozmiar_tablicy;
	tablica = new TYP[rozmiar_tablicy];

	cout << "\nPodaj elementy tablicy" << endl;
	for (int i = 0; i < rozmiar_tablicy; ++i){
		cin >> tablica[i];
	}

	return *this;
}
////////////////////////////////////////////////////////////////////////////////
template <class TYP>
void Tablica<TYP>::wyswietl_tablice(std::ostream& strumien) const
{
	if (tablica == NULL) {
		cout << "Tablica jest pusta!" << endl;
		return;
	}

	for (int i = 0; i < rozmiar_tablicy; ++i){
		strumien << tablica[i] << "\t";
	}
	strumien << endl;
}
////////////////////////////////////////////////////////////////////////////////
template <class TYP>
Tablica<TYP>& Tablica<TYP>::wczytaj_tab_z_pliku()
{
	ifstream plik;
	string sciezka;

	cout << "\nPodaj sciezke lub nazwe (jezeli plik znajduje sie w folderze z programem) do pliku wraz z rozszerzeniem.\n";
	cin.sync();
	getline(cin, sciezka);

	plik.open(sciezka);
	if (!plik.good() || plik.eof()){
		cout << "\nWystapil blad podczas proby otwarcia pliku lub plik jest pusty!";
		return *this;
	}

	plik >> rozmiar_tablicy;
	
	TYP *tab = new TYP[rozmiar_tablicy];

	for (int i = 0; i < rozmiar_tablicy; ++i){
		plik >> tab[i];
	}
	plik.close();

	if (tablica != NULL) delete[] tablica; //usuwamy poprzednia zawartosc tablicy by wczytac nowa
	tablica = tab;

	return *this;
}
////////////////////////////////////////////////////////////////////////////////
template <class TYP>
void Tablica<TYP>::zapisz_tab_do_pliku() const
{
	ofstream plik;
	string sciezka;

	cout << "\nPodaj sciezke lub nazwe (jezeli plik znajduje sie w folderze z programem) do pliku wraz z rozszerzeniem.\n";
	cin.sync();
	getline(cin, sciezka);

	plik.open(sciezka);
	if (!plik.good()){
		cout << "\nWystapil blad podczas proby otwarcia pliku!";
		return;
	}

	plik << rozmiar_tablicy << endl;
	wyswietl_tablice(plik);

	plik.close();
}
////////////////////////////////////////////////////////////////////////////////
template <class TYP>
Tablica<TYP>& Tablica<TYP>::wczytaj_tab_z_pliku_binarnego()
{
	ifstream plik;
	string sciezka;

	cout << "\nPodaj sciezke lub nazwe (jezeli plik znajduje sie w folderze z programem) do pliku.\n";
	cin.sync();
	getline(cin, sciezka);

	plik.open(sciezka, ios::binary);
	if (!plik.good() || plik.eof()){
		cout << "\nWystapil blad podczas proby otwarcia pliku lub plik jest pusty!";
		return *this;
	}

	plik >> rozmiar_tablicy;
	
	TYP *tab = new TYP[rozmiar_tablicy];

	for (int i = 0; i < rozmiar_tablicy; ++i){
		plik >> tab[i];
	}
	plik.close();

	if (tablica != NULL) delete[] tablica; //usuwamy poprzednia zawartosc tablicy by wczytac nowa
	tablica = tab;

	return *this;
}
////////////////////////////////////////////////////////////////////////////////
template <class TYP>
void Tablica<TYP>::zapisz_tab_do_pliku_binarnego() const
{
	ofstream plik;
	string sciezka;

	cout << "\nPodaj sciezke lub nazwe (jezeli plik znajduje sie w folderze z programem) do pliku wraz z rozszerzeniem.\n";
	cin.sync();
	getline(cin, sciezka);

	plik.open(sciezka, ios::binary);
	if (!plik.good()){
		cout << "\nWystapil blad podczas proby otwarcia pliku!";
		return;
	}

	plik << rozmiar_tablicy << endl;
	wyswietl_tablice(plik);

	plik.close();
}
////////////////////////////////////////////////////////////////////////////////
template <class TYP>
Tablica<TYP>& Tablica<TYP>::wypelnij_tablice_losowo()
{
	if (rozmiar_tablicy == 0){
		cout << "\nPodaj rozmiar tablicy:\t";
		cin >> rozmiar_tablicy;
	}

	if (tablica == NULL){
		tablica = new TYP[rozmiar_tablicy];
	}

	srand(time(NULL));

	for (int i = 0; i < rozmiar_tablicy; ++i){
		tablica[i] = rand() % 100;
	}

	return *this;
}
////////////////////////////////////////////////////////////////////////////////
template <class TYP>
Tablica<TYP>& Tablica<TYP>::operator=(Tablica<TYP>& kopia)
{
	if (kopia.tablica == NULL){
		tablica = NULL;
		return *this;
	}

	rozmiar_tablicy = kopia.rozmiar_tablicy;
	if (tablica != NULL) delete[] tablica;

	tablica = new TYP[rozmiar_tablicy];
	for (int i = 0; i < rozmiar_tablicy; ++i){
		tablica[i] = kopia.tablica[i];
	}

	return *this;
}

#endif