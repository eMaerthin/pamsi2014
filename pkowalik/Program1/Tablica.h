#include<iostream>
#include<vector>
#include<fstream>
#include<random>
using namespace std;

template<typename Typ>
class Tablica{
	vector<Typ> tab;

public:
	Tablica(void);
	Tablica(const Tablica<Typ> & T);
	~Tablica(void);
//	friend istream & operator>>(istream & in, Tablica<Typ> & A);
//	friend ostream & operator<<(ostream & out, Tablica<Typ> & A);
	int size();
	bool empty();
	void clear();
	void push(Typ x);
	void Wpisz_z_txt();
	void Wpisz_do_txt();
	void Wpisz_z_bin();
	void Wpisz_do_bin();
	void Random();
	Typ operator[](int i);
	Tablica<Typ> & operator=(Tablica<Typ> & T);
};

/*
* Konstruktor.*****************************************************************************************
*/
template<typename Typ>
Tablica<Typ>::Tablica(void)
{
	tab.clear();
}

/*
* Destruktor.******************************************************************************************
*/
template<typename Typ>
Tablica<Typ>::~Tablica(void)
{
	tab.clear();
}

/*
* Konstruktor kopiuj¹cy.*******************************************************************************
*/
template<typename Typ>
Tablica<Typ>::Tablica(const Tablica<Typ> & T) {
	~Tablica();
	for(int i=0; i<T.size(); i++) {
		tab.push_back(T.tab[i]);
	}
}

/*
* Przeci¹¿enie operatora wy³uskania.*******************************************************************
*/
template<typename Typ>
Typ Tablica<Typ>::operator[](int i){
	return tab[i];
}

/*
* Przeci¹¿enie operatora przypisania.******************************************************************
*/
template<typename Typ>
Tablica<Typ> & Tablica<Typ>::operator=(Tablica<Typ> & T) {
	for(int i=0; i<T.size(); i++) {
		tab.push_back(T.tab[i]);
	}
	return *(this);
}

/*
* funkcja publiczna umo¿liwiaj¹ca zastosowanie push_back() prywatnego sk³adnika klasy.*****************
*/
template<typename Typ>
void Tablica<Typ>::push(Typ x)
{
	tab.push_back(x);
}
/*
string Wybierz_Typ(){
	string typ;
	int x;
	bool koniec=false;
	while(koniec) {
		cout<<"Podaj typ tablicy:"<<endl;
		cout<<"1.Int"<<endl;
		cout<<"2.Char"<<endl;
		cout<<"3.Float"<<endl;
		cout<<"4.Double"<<endl;
		cout<<"5.String"<<endl;
		cin>>x;
		switch(x) {
		case 1: {
			typ="int";
			koniec=true;
			break;
				}
		case 2: {
			typ="char";
			koniec=true;
			break;
				}
		case 3: {
			typ="float";
			koniec=true;
			break;
				}
		case 4: {
			typ="double";
			koniec=true;
			break;
				}
		case 5: {
			typ="string";
			koniec=true;
			break;
				}
		default: {
			cout<<"Nie ma takiej opcji"<<endl;
			break;
				 }
		}
	}
		return typ;
}
*/

/*
*Zwraca rozmiar wektora.*******************************************************************************
*/
template<typename Typ>
int Tablica<Typ>::size(){
	return tab.size();
}

/*
*Zwraca wioadomosc czy wektor jest pusty.**************************************************************
*/
template<typename Typ>
bool Tablica<Typ>::empty(){
	return tab.empty();
}

/*
*Czysci wektor.****************************************************************************************
*/
template<class Typ>
void Tablica<Typ>::clear(){
	tab.clear();
}

/*
*Funkcja wpisywanie zmiennych typu Tablica*************************************************************
*/
template<typename Typ>
istream & operator>>(istream & in, Tablica<Typ> & A){
	char wpis='0';
	int x;
	A.clear();
	cout<<"Wpisz tablice:"<<endl;
	wpis='a';
	in.ignore();
	in.clear();
	while(wpis!='\n'){
		wpis=in.get();
		if(wpis!='\n') {
			in.unget();
			in>>x;
			A.push(x);
		}
	}
	return in;
}

/*
*Funkcja wypisujaca zmienne typu Tablica do strupienia wyjœciowego*************************************
*/
template<typename Typ>
ostream & operator<<(ostream & out, Tablica<Typ> & A) {
	if(!A.empty()){
		out<<"Wyswietlam tablice:"<<endl;
		for(int i=0; i<A.size(); i++) {
			out<<A[i]<<' ';
		}
	} else {
		out<<"Nie wipsano jeszcze zadnej tablicy";
	}
	return out;
}

/*
*Menu zapisu pliku.
*Uzytkownik decyduje czy chce wpisac nowa tablice do pliku czy chce zapisac juz istniejaca w programie.
*Jesli tablica jest pusta odrazu wybiera wpisywanie nowej tablicy.
*/
template<typename Typ>
int menu_plik(vector<Typ> A) {
	int wybor;
	bool koniec=false;
	if(!A.empty()) {
		do{
			cout<<"Obecnie jest juz wpisana tablica:"<<endl;
			cout<<"1.Wpisz obecna tablice do pliku."<<endl;
			cout<<"2.Wpisz nowa tablice do pliku."<<endl;
			cin>>wybor;
			switch(wybor) {
			case 1: {
				koniec=true;
				break;
					}
			case 2: {
				koniec=true;
				break;
					}
			default:{
				cout<<"Nie ma takiej opcji. Sprobuj ponownie."<<endl<<endl;
				break;
					}
			}
		}while(!koniec);
	} else {
		wybor=2;
	}
	return wybor;
}

/*
*Wczytywanie tablicy z pliku typu .txt*****************************************************************
*/
template<typename Typ>
void Tablica<Typ>::Wpisz_z_txt() {
	ifstream plik;
	int x;
	plik.open("Tablicatxt.txt");
	if(!plik.good()){
		cout<<"Plik tekstowy nie istnieje. Aby utworzyc wybierz funkcje zapisu tablicy do pliku tekstowego."<<endl;
	} else {
		if(!plik.eof()) {
			tab.clear();
			while(!plik.eof()){
			plik>>x;
			tab.push_back(x);
			} 
			tab.pop_back();
			cout<<"Wczytano tablice. Aby wyswietlic wybierz opcje nr 2."<<endl;
		} else {
			cout<<"W pliku nie ma zadnego zapisu";
		}
	}
	plik.close();
}

/*
*Zapisywanie tablicy do pliku typu .txt****************************************************************
*/
template<typename Typ>
void Tablica<Typ>::Wpisz_do_txt() {
	ofstream plik;
	unsigned int i;
	if(menu_plik(tab)==1) {
		plik.open("Tablicatxt.txt");
		for(i=0; i<tab.size(); i++) {
		plik<<tab[i]<<endl;
		}
		plik.close();
	} else {
		cin>>*(this);
		plik.open("Tablicatxt.txt");
		for(i=0; i<tab.size(); i++) {
		plik<<tab[i]<<endl;
		}
		plik.close();
	}
}

/*
*Wczytywanie tablicy z pliku binarnego.****************************************************************
*/
template<typename Typ>
void Tablica<Typ>::Wpisz_z_bin() {
	ifstream binar;
	int x;
	binar.open("Tablicabin", ios::binary);
	if(!binar.good()){
		cout<<"Plik binarny nie istnieje. Aby utworzyc wybierz funkcje zapisu tablicy do pliku binarnego."<<endl;
	} else {
		if(!binar.eof()) {
			tab.clear();
			while(!binar.eof()){
			binar>>x;
			tab.push_back(x);
			}
			tab.pop_back();
			cout<<"Wczytano tablice. Aby wyswietlic wybierz opcje nr 2."<<endl;
		} else {
			cout<<"W pliku nie ma zadnego zapisu";
		}
	}
	binar.close();
}

/*
*Zapisywanie tablicy do pliku binarnego.***************************************************************
*/
template<typename Typ>
void Tablica<Typ>::Wpisz_do_bin(){
	ofstream binar;
	unsigned int i;
	if(menu_plik(tab)==1) {
		binar.open("Tablicabin", ios::binary);
		for(i=0; i<tab.size(); i++) {
		binar<<tab[i]<<endl;
		}
		binar.close();
	}else {
		cin>>*(this);
		binar.open("Tablicabin", ios::binary);
		for(i=0; i<tab.size(); i++) {
		binar<<tab[i]<<endl;
		}
		binar.close();
	}
}

/*
*Uzupelnianie tablicy o wybranym rozmiarze losowo wybranymi liczbami z zakresu 0-100.******************
*/
template<typename Typ>
void Tablica<Typ>::Random(){
	int i, ilosc;
	tab.clear();
	cout<<"Ile ma zawierac elementow? :";
	cin>>ilosc;
	for(i=0; i<ilosc; i++){
			tab.push_back(rand()%100);
		}
}