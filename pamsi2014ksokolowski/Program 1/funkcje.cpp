#include "funkcje.h"

using namespace std;

int* wczytaj_tab_z_konsoli(int& rozmiar_tab)
{
	cout << "\nIle elementow chcesz wpisac?\t";

	int *tablica;
	cin >> rozmiar_tab;

	tablica = new int[rozmiar_tab];

	for (int i = 0; i < rozmiar_tab; ++i){
		cin >> tablica[i];
	}

	return tablica;
}
////////////////////////////////////////////////////////////////////////////////
void wyswietl_tablice(int* tablica, int ile, ostream& strumien)
{
	if (tablica == NULL) {
		cout << "Tablica jest pusta!" << endl;
		return;
	}

	for (int i = 0; i < ile; ++i){
		strumien << tablica[i] << "\t";
	}
	strumien << endl;
}
////////////////////////////////////////////////////////////////////////////////
int* wczytaj_tab_z_pliku(int& rozmiar_tab)
{
	fstream plik;
	string sciezka;

	cout << "\nPodaj sciezke lub nazwe (jezeli plik znajduje sie w folderze z programem) do pliku wraz z rozszerzeniem.\n";
	cin.sync(); //czyszczenie ewentualnych "smici" w strumieniu
	getline(cin, sciezka);

	plik.open(sciezka);
	if (!plik.good() || plik.eof()){
		cout << "\nWystapil blad podczas proby otwarcia pliku lub plik jest pusty!";
		return NULL;
	}

	plik >> rozmiar_tab;
	int *tablica = new int[rozmiar_tab];

	for (int i = 0; i < rozmiar_tab; ++i){
		plik >> tablica[i];
	}
	plik.close();

	return tablica;
}
////////////////////////////////////////////////////////////////////////////////
void zapisz_tab_do_pliku(int* tablica, int ile)
{
	ofstream plik;
	string sciezka;

	cout << "\nPodaj sciezke lub nazwe (jezeli plik znajduje sie w folderze z programem) do pliku wraz z rozszerzeniem.\n";
	cin.sync(); //czyszczenie ewentualnych "smici" w strumieniu
	getline(cin, sciezka);

	plik.open(sciezka);
	if (!plik.good()){
		cout << "\nWystapil blad podczas proby otwarcia pliku!";
		return;
	}

	plik << ile << endl;
	wyswietl_tablice(tablica, ile, plik);

	plik.close();
}
////////////////////////////////////////////////////////////////////////////////
int* wczytaj_tab_z_pliku_binarnego(int& rozmiar_tab)
{
	ifstream plik;
	string sciezka;

	cout << "\nPodaj sciezke lub nazwe (jezeli plik znajduje sie w folderze z programem) do pliku wraz z rozszerzeniem.\n";
	cin.sync(); //czyszczenie ewentualnych "smici" w strumieniu
	getline(cin, sciezka);

	plik.open(sciezka, ios::binary);
	if (!plik.good() || plik.eof()){
		cout << "\nWystapil blad podczas proby otwarcia pliku lub plik jest pusty!";
		return NULL;
	}

	plik >> rozmiar_tab;
	int *tablica = new int[rozmiar_tab];

	for (int i = 0; i < rozmiar_tab; ++i){
		plik >> tablica[i];
	}
	plik.close();

	return tablica;
}
////////////////////////////////////////////////////////////////////////////////
void zapisz_tab_do_pliku_binarnego(int* tablica, int ile)
{
	ofstream plik;
	string sciezka;

	cout << "\nPodaj sciezke lub nazwe (jezeli plik znajduje sie w folderze z programem) do pliku wraz z rozszerzeniem.\n";
	cin.sync(); //czyszczenie ewentualnych "smici" w strumieniu
	getline(cin, sciezka); 

	plik.open(sciezka, ios::binary);
	if (!plik.good()){
		cout << "\nWystapil blad podczas proby otwarcia pliku!";
		return;
	}

	plik << ile << endl;
	wyswietl_tablice(tablica, ile, plik);

	plik.close();
}
////////////////////////////////////////////////////////////////////////////////
int* wypelnij_tablice_losowo(int& rozmiar_tab, int* tablica)
{
	cout << "\nPodaj rozmiar tablicy:\t";
	cin >> rozmiar_tab;

	if (tablica == NULL){
		tablica = new int[rozmiar_tab];
	}

	srand(time(NULL)); //do losowania liczb

	for (int i = 0; i < rozmiar_tab; ++i){
		tablica[i] = rand() % 100;
	}

	return tablica;
}
////////////////////////////////////////////////////////////////////////////////
int* zrob_kopie(int* tablica, int rozmiar_tab)
{
	if (tablica == NULL) {
		cout << "Tablica jest pusta!" << endl;
		return NULL;
	}

	int *kopia = new int[rozmiar_tab];

	for (int i = 0; i < rozmiar_tab; ++i){
		kopia[i] = tablica[i];
	}

	return kopia;
}
////////////////////////////////////////////////////////////////////////////////
void program_funkcje()
{
	short opcja;
	int rozmiar_tab;
	int *tab = NULL, *kopia = NULL;

	do{
		cout << "\n\nMenu Funkcje\n\n";
		cout << "1.Wczytanie tablicy z konsoli" << endl;
		cout << "2.Wyœwietlenie tablicy" << endl;
		cout << "3.Wczytywanie z pliku tekstowego" << endl;
		cout << "4.Zapisywanie do pliku tekstowego" << endl;
		cout << "5.Wczytywanie z pliku binarnego" << endl;
		cout << "6.Zapisywanie do pliku binarnego" << endl;
		cout << "7.Wype³nianie tablicy" << endl;
		cout << "8.Tworzenie dynamicznej kopii + wyœwietlenie kopii" << endl;
		cout << "0.Koniec" << endl;
		cout << "Wybierz opcje:\t";
		cin >> opcja;

		switch (opcja){

		case 1:	tab = wczytaj_tab_z_konsoli(rozmiar_tab);
			break;

		case 2:	wyswietl_tablice(tab, rozmiar_tab);
			break;

		case 3: tab = wczytaj_tab_z_pliku(rozmiar_tab);
			break;

		case 4: zapisz_tab_do_pliku(tab, rozmiar_tab);
			break;

		case 5: tab = wczytaj_tab_z_pliku_binarnego(rozmiar_tab);
			break;

		case 6: zapisz_tab_do_pliku_binarnego(tab, rozmiar_tab);
			break;

		case 7: tab = wypelnij_tablice_losowo(rozmiar_tab, tab);
			break;

		case 8: kopia = zrob_kopie(tab, rozmiar_tab);
			cout << endl;
			wyswietl_tablice(kopia, rozmiar_tab);
			break;
		}

	} while (opcja != 0);

	delete[] tab;
	delete[] kopia;
}
////////////////////////////////////////////////////////////////////////////////
void program_klasa()
{
	short opcja;
	Tablica<int> tab, kopia;

	do{
		cout << "\n\nMenu Klasa\n\n";
		cout << "1.Wczytanie tablicy z konsoli" << endl;
		cout << "2.Wyœwietlenie tablicy" << endl;
		cout << "3.Wczytywanie z pliku tekstowego" << endl;
		cout << "4.Zapisywanie do pliku tekstowego" << endl;
		cout << "5.Wczytywanie z pliku binarnego" << endl;
		cout << "6.Zapisywanie do pliku binarnego" << endl;
		cout << "7.Wype³nianie tablicy" << endl;
		cout << "8.Tworzenie dynamicznej kopii + wyœwietlenie kopii" << endl;
		cout << "0.Koniec" << endl;
		cout << "Wybierz opcje:\t";
		cin >> opcja;

		switch (opcja){

		case 1:	tab.wczytaj_tab_z_konsoli();
				break;

		case 2:	tab.wyswietl_tablice();
				break;

		case 3: tab.wczytaj_tab_z_pliku();
				break;

		case 4: tab.zapisz_tab_do_pliku();
				break;

		case 5: tab.wczytaj_tab_z_pliku_binarnego();
				break;

		case 6: tab.zapisz_tab_do_pliku_binarnego();
				break;

		case 7: tab.wypelnij_tablice_losowo();
				break;

		case 8: kopia = tab;
				cout << endl;
				kopia.wyswietl_tablice();
				break;
		}

	} while (opcja != 0);
}