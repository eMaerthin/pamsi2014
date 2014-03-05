#include <iostream>
#include <string>
#include <fstream>
#include <time.h>


using namespace std;

void wczytywanieTablicy(int*  tablica, int n) {
	int tekst;
	for(int i = 0; i < n; i++) {
		cin.clear();
		cin.ignore( 1000, '\n');
		cin >> tekst;
		tablica[i] = tekst;
	}
}

void wyswietlanieTablicy(int* tablica, int n) {
	for(int i = 0; i < n; i++) {
		cout << tablica[i] << " ";
	}
	cout << endl;
}

 int *kopiowanieTablicy(int* tablica, int n) {
	 int *nowaTablica = NULL;
	 nowaTablica = new int[n];
	 for(int i = 0; i < n; i++) {
		 nowaTablica[i] = tablica[i];
	 }
	 return nowaTablica;
 }

int main() {
	int* tablica = NULL;
	int n = 0;
	int opcja = NULL;
	fstream plik, plikb;
	srand((int)time(NULL));
	//int val = 6;
	//for(int i = 31; i >= 0; i--)
	//	cout << (val >> i)%2;
	//cout << endl;
	do{
		cout << "1.Wczytanie tablicy z konsoli"<<endl;
		cout << "2.Wyswietlenie tablicy"<<endl;
		cout << "3.Wczytywanie z pliku tekstowego"<<endl;
		cout << "4.Zapisywanie do pliku tekstowego"<<endl;
		cout << "5.Wczytywanie z pliku binarnego"<<endl;
		cout << "6.Zapisywanie do pliku binarnego"<<endl;
		cout << "7.Wypelnianie tablicy"<<endl;
		cout << "8.Tworzenie dynamicznej kopii + wyswietlenie kopii"<<endl;
		cout << "0.Koniec"<<endl;
		cout << "Wybierz opcje\t";
		cin >> opcja;
		switch(opcja) {
		case 0: 
			break;
		case 1: {	//Wczytanie tablicy z konsoli
			cout << "Ile elementow bedzie miala tablica?\t";
			cin >> n;
			tablica = new int[n];
			wczytywanieTablicy(tablica, n);
			break;
				}
		case 2: {	//Wyœwietlenie tablicy
			wyswietlanieTablicy(tablica, n); 
			break;
				}
		case 3: {	//Wczytywanie z pliku tekstowego
			plik.open("tab.txt", ios::in);
			int tmp;
			n = 0;
			if(plik.good()) {
				do {
					plik >> tmp;
					cout << tmp << " ";
					n++;
				}while(!plik.eof());
			}
			tablica = new int[n];
			int i = 0;
			plik.close();
			plik.open("tab.txt", ios::in);
			if(plik.good()) {
				do {
					plik >> tmp;
					tablica[i] = tmp;
					i++;
				}while(!plik.eof());
			}
			plik.close();
			break;
				}
		case 4: {	//Zapisywanie do pliku tekstowego
			if(tablica != NULL) {
				plik.open("tab.txt", ios::out);
				if(plik.good()) {
					for(int i = 0; i < n; i++) {
						plik << tablica[i];
						if(i != n - 1)
							plik << " ";
					}
				}
				cout << "udany zapis do pliku\n";
			}
			else cout << "brak tablicy do zapisania\n";
			plik.close();
			break;
				}
		case 5: {	//Wczytywanie z pliku binarnego
			char buff[100];
			char tmp[100];
			plikb.open("bin.bin", ios::in | ios::binary);
			n = 0;
			int i = 0;
			do {
				plikb.read((char*)buff + n,sizeof(char));
				if((int)buff[n] != -52)
					++n;
			}while(!plikb.eof());
			tablica = new int[n];
			for(int i = 0; i < n; i++) {
				tablica[i] = (int)buff[i];
			}
			plikb.close();
			break;
				}
		case 6: {	//Zapisywanie do pliku binarnego
			if(tablica != NULL) {
				char buff[100];
				for(int i = 0; i < n; i++) {
					buff[i] = tablica[i];
				}
				plikb.open("bin.bin", ios::out | ios::binary);
				if(plikb.good()) {
					for(int i = 0; i < sizeof(buff); i++)
						plikb.write((char*)buff + i,sizeof(char));
				}
				cout << "udany zapis do pliku\n";
			}
			else cout << "brak tablicy do zapisania\n";
			plikb.close();
			break;
				}
		case 7: {	//Wype³nianie tablicy
			int dol(0), gora(0);
			cout << "jaki rozmiar tablicy?\t";
			cin >> n;
			cout << "\npodaj dolny zakres\t";
			cin >> dol;
			cout << "\npodaj gorny zakres\t";
			cin >> gora;
			tablica = new int[n];
			for(int i = 0; i < n; i++) {
				tablica[i] = rand() % gora + dol;
			}
			break;
				}
		case 8: {	//Tworzenie dynamicznej kopii + wyœwietlenie kopii
			if(tablica != NULL) {
				int* adres = kopiowanieTablicy(tablica,n);
				cout << "skopiowana tablica(wyswietlana poza funkcja zwracajaca wskaznik na tablice):\n";
				for(int i = 0; i < n; i++)
					cout << *(adres + i) << " ";
			}
			else cout << "tablica jest pusta, nie ma co przepisac\n";
			break;
				}
		}
		cout << endl;
	}while(opcja !=0);
	if(tablica != NULL)	delete [] tablica;
	system("PAUSE");
	return 0;
}