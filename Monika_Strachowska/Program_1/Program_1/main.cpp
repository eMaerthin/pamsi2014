/**
*
*	autor:	Monika Strachowska
*	data:	4.03.2014
*/
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
using namespace std;
template <class T>
class Tablica{
private:
	T *tablica;
	int n;
	void wczytywanieTablicy(/*int *, int*/);
	void wyswietlanieTablicy(/*int *, int*/);
	T *kopiowanieTablicy(/*int *, int*/);
	void czytanieZPlikuTxt(/*int *, int, */string);
	void zapisDoPlikuTxt(/*int *, int, */string);
	void czytanieZPlikuBin(/*int *, int,*/ string);
	void zapisaDoPlikuBin(/*int *, int, */string);
	void wypelnianie();
public:
	Tablica():tablica(NULL),n(0){cout << "konstruktor\n";};
	~Tablica() {cout << "destruktor\n";delete [] tablica;};
	
	void menu();
	Tablica & operator= (const Tablica<T> &t) { 
		cout << "\t\t\tprzypisanie\n";
		return *this;
	};
};
template <class T>
void Tablica <T>::menu() {
	int opcja = NULL;
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
			tablica = new T[n];
			wczytywanieTablicy(/*tablica, n*/);
			break;
				}
		case 2: {	//Wyswietlenie tablicy
			wyswietlanieTablicy(/*tablica, n*/); 
			break;
				}
		case 3: {	//Wczytywanie z pliku tekstowego
			czytanieZPlikuTxt(/*tablica,n,*/ "tab.txt");
			break;
				}
		case 4: {	//Zapisywanie do pliku tekstowego
			zapisDoPlikuTxt(/*tablica, n, */"tab.txt");
			break;
				}
		case 5: {	//Wczytywanie z pliku binarnego
			czytanieZPlikuBin(/*tablica, n,*/ "bin.bin");
			break;
				}
		case 6: {	//Zapisywanie do pliku binarnego
			zapisaDoPlikuBin(/*tablica, n,*/ "bin.bin");
			break;
				}
		case 7: {	//Wypelnianie tablicy
			wypelnianie();
			break;
				}
		case 8: {	//Tworzenie dynamicznej kopii + wyswietlenie kopii
			if(tablica != NULL) {
				T* adres = kopiowanieTablicy(/*tablica,n*/);
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
}
template <class T>
void Tablica <T>::wczytywanieTablicy(/*int *tablica, int n*/) {
	T tekst;
	for(int i = 0; i < n; i++) {
		cin.clear();
		cin.ignore();
		cin >> tekst;
		tablica[i] = tekst;
	}
}
template <class T>
void Tablica <T>::wyswietlanieTablicy(/*int *tablica, int n*/) {
	for(int i = 0; i < n; i++) {
		cout << tablica[i] << " ";
	}
	cout << endl;
}
template <class T>
T *Tablica <T>::kopiowanieTablicy(/*int *tablica, int n*/) {
	 T *nowaTablica = NULL;
	 nowaTablica = new T[n];
	 for(int i = 0; i < n; i++) {
		 nowaTablica[i] = tablica[i];
	 }
	 return nowaTablica;
 }
template <class T>
void Tablica <T>::czytanieZPlikuTxt(/*int *tablica, int n, */string nazwaPliku) {
	fstream plik;
	plik.open(nazwaPliku, ios::in);
	T tmp;
	n = 0;
	if(plik.good()) {
		do {
			plik >> tmp;
			cout << tmp << " ";
			n++;
		}while(!plik.eof());
	}
	tablica = new T[n];
	int i = 0;
	plik.close();
	plik.open(nazwaPliku, ios::in);
	if(plik.good()) {
		do {
			plik >> tmp;
			tablica[i] = tmp;
			i++;
		}while(!plik.eof());
	}
	plik.close();
 }
template <class T>
void Tablica <T>::zapisDoPlikuTxt(/*int *tablica, int n, */string nazwaPliku) {
	 fstream plik;
	 if(tablica != NULL) {
		plik.open(nazwaPliku, ios::out);
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
 }
template <class T>
void Tablica <T>::czytanieZPlikuBin(/*int *tablica, int n, */string nazwaPliku) {
	fstream plikb;
	char buff[100];
	plikb.open(nazwaPliku, ios::in | ios::binary);
	n = 0;
	int i = 0;
	do {
		plikb.read((char*)buff + n,sizeof(char));
		if((int)buff[n] != -52)
			n++;
	}while(!plikb.eof());
	tablica = new T[n];
	for(int i = 0; i < n; i++) {
		tablica[i] = (T)buff[i];
		cout << tablica[i] << " ";
	}
	plikb.close();
 }
template <class T> 
void Tablica <T>::zapisaDoPlikuBin(/*int *tablica, int n, */string nazwaPliku) {
	fstream plikb;
	if(tablica != NULL) {
		T buff[100];
		for(int i = 0; i < n; i++) {
			buff[i] = tablica[i];
		}
		plikb.open(nazwaPliku, ios::out | ios::binary);
		if(plikb.good()) {
			for(int i = 0; i < sizeof(buff); i++)
				plikb.write((char*)buff + i,sizeof(char));
		}
		cout << "udany zapis do pliku\n";
	}
	else cout << "brak tablicy do zapisania\n";
	plikb.close();
 }
template <class T>
void Tablica <T>::wypelnianie() {
	srand((int)time(NULL));
	int dol(0), gora(0);
	cout << "jaki rozmiar tablicy?\t";
	cin >> n;
	cout << "\npodaj dolny zakres\t";
	cin >> dol;
	cout << "\npodaj gorny zakres\t";
	cin >> gora;
	tablica = new T[n];
	for(int i = 0; i < n; i++)
		tablica[i] = (T)(rand() % gora + dol);
}

int main() {
	Tablica <float>*t = new Tablica <float>;
	t->menu();
	Tablica <float>*k = new Tablica <float>;

	//k->menu();
	t = k;
	//float* a = k;
	t->menu();
	Tablica <double> y;
	double* q = new double[5];
 	/*k = q;
	y = q;
	q = y;*/
	system("PAUSE");
	return 0;
}