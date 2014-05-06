//autor: Marcin Ochocki 200330

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#define ROZMIAR 1000
#define ROZMIAR2 700
using namespace std;
fstream plik;

class graf {
	list<vector<int>> drzewo;
	int macierz[ROZMIAR2][ROZMIAR2];
	int max;
	int suma;
	public:
	void czytaj_plik(fstream & plik);
	void zapisz_do_pliku(fstream & plik);
	void stworz_macierz();
	void sortuj_wagi();
	void stworz_min();
	void suma_wag();
	void wyswietl_liste();
	void wyswietl_macierz();
};

void graf::czytaj_plik(fstream & plik) {
  plik.open("dane3.txt", ios::in);
  int x;
  max=0;
  if( plik.good() == true )
	cout << "[Wczytywanie] Uzyskano dostep do pliku" << endl << endl;
  else 
	cout << "[Wczytywanie] Brak dostepu do pliku" << endl << endl; 
  do {
  	vector<int>tmp;
  	for(int i=0; i<3; i++) {
  	  plik >> x;
	  tmp.push_back(x);
	  if(i==0 || i==1) {
	  	if(x>max)
	  	  max=x;
	  }
    }
    drzewo.push_back(tmp);
  } while(!plik.eof());
  plik.close();
  stworz_macierz();
}

void graf::zapisz_do_pliku(fstream & plik) {
  plik.open("zapisane.txt", ios::out);
  if( plik.good() == true )
	cout << "[Zapisywanie] Uzyskano dostep do pliku" << endl << endl;
  else 
	cout << "[Zapisywanie] Brak dostepu do pliku" << endl << endl; 
  for(list<vector<int>>::iterator it1=drzewo.begin(); it1!=drzewo.end(); ++it1) {
	for(vector<int>::iterator it2=(*it1).begin(); it2!=(*it1).end(); ++it2) {
	  if(*it2<10)
	    plik << " ";
	  plik << *it2 << " ";
    }
    plik << "\n";
  }
  plik.close();
}

void graf::stworz_macierz() {
  int x,y;
  for(int i=0; i<=max; i++) {
  	for(int j=0; j<=max; j++) {
  	  macierz[i][j]=-1;
  	}
  }
  for(list<vector<int>>::iterator it1=drzewo.begin(); it1!=drzewo.end(); ++it1) {
	for(vector<int>::iterator it2=(*it1).begin(); it2!=(*it1).end(); ++it2) {
	  x=*it2++;
	  y=*it2++++;
      macierz[x][y]=*it2;
      macierz[y][x]=*it2;
    }
  }
}

void graf::stworz_min() {
  int i, j, k, a, b;
  int waga, znaleziono_a, znaleziono_b, wierzcholek;
  int polaczono=1;
  int licz;
  vector<int> polaczenie;
  list<vector<int>> min;
  list<int> wierzcholki;
  list<vector<int>>::iterator it1, indeks;
  vector<int>::iterator it2;
  list<int>::iterator it3;
  it1=drzewo.begin();   //Wez pierwszy wektor z drzewa
  it2=(*it1).begin();   //Wez pierwszy wierzcholek z wektora
  wierzcholki.push_back(*it2);  //Dodaj wierzcholek do listy wierzcholkow
  while(polaczono==1) { //Jesli ostatnio dolaczono wierzcholek
  	polaczono=0;   //Nie wykonano zadnych polaczen
  	waga=-1;
    for(it1=drzewo.begin(), i=0; it1!=drzewo.end(); it1++, i++) { //Przeszukaj drzewo
      znaleziono_a=0;
  	  znaleziono_b=0;
  	  for(it2=(*it1).begin(), j=0; it2!=(*it1).end(); it2++, j++) {
  	  	if(j==0)
  	  	  a=*it2; //Zapisz pierwszy wierzcholek
  	  	if(j==1)
  	  	  b=*it2; //Zapisz drugi wierzcholek
  	  }
  	  it2--;
  	  if(waga==-1)
  	    waga=*it2;
  	  for(it3=wierzcholki.begin(); it3!=wierzcholki.end(); it3++) {
    	if(a==*it3)
    	  znaleziono_a=1;
    	if(b==*it3)
    	  znaleziono_b=1;
  	  }
  	  if((znaleziono_a==0 && znaleziono_b==1) && waga>=*it2) {
    	polaczenie=*it1; //Zapisz polaczenie
    	wierzcholek=a;   //Zapisz wierzcholek
    	waga=*it2;       //Zapisz wage polaczenia
    	indeks=it1;      //Zapisz adres wektora z poczatkowego drzewa
    	polaczono=1;     //Mozna dolaczyc wierzcholek do MDR
      }
      if((znaleziono_a==1 && znaleziono_b==0) && waga>=*it2) {
      	polaczenie=*it1;
    	wierzcholek=b;
    	waga=*it2;
    	indeks=it1;
    	polaczono=1;
      }
      //Jesli oba wierzcholki naleza do tego samego drzewa
      if(znaleziono_a==1 && znaleziono_b==1)
    	drzewo.erase(it1--);     //Usun wektor z drzewa o zadanej pozycji
    }
    //Jesli mozna dolaczyc wierzcholek
    if(polaczono==1) {
      min.push_back(polaczenie); //Dodaj wektor do MDR
      wierzcholki.push_back(wierzcholek); //Dodaj wierzcholki
      drzewo.erase(indeks);
    }
  }
  drzewo=min;
  min.clear();
  wierzcholki.clear();
}

void graf::suma_wag() {
  suma=0;
  vector<int>::iterator it2;
  for(list<vector<int>>::iterator it1=drzewo.begin(); it1!=drzewo.end(); it1++) {
  	it2=(*it1).end();
  	--it2;
  	suma=suma+(*it2);
  }
  cout << "Suma wag: " << suma << endl;
}

void graf::wyswietl_liste() {
  for(list<vector<int>>::iterator it1=drzewo.begin(); it1!=drzewo.end(); it1++) {
	for(vector<int>::iterator it2=(*it1).begin(); it2!=(*it1).end(); it2++) {
	  if(*it2<10)
	    cout << " ";
	  cout << *it2 << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void graf::wyswietl_macierz() {
  for(int i=0; i<=max; i++) {
  	for(int j=0; j<=max; j++) {
  	  if(macierz[i][j]<10)
  	    cout << " ";
  	  if(macierz[i][j]==-1)
  	  	cout << "- ";
  	  else
  	    cout << macierz[i][j] << " ";
  	}
  	cout << endl;
  }
  cout << endl;
}
    
int main() {
  graf x;
  x.czytaj_plik(plik);
  x.stworz_macierz();
  cout << endl << "Poczatkowe drzewo:" << endl << endl;
  //x.wyswietl_liste();
  x.suma_wag(); 
  x.stworz_min();
  x.stworz_macierz();
  cout << endl << "Minimalne drzewo:" << endl << endl;
  //x.wyswietl_liste();
  x.suma_wag(); 
  //cout << endl << "Macierz polaczen:" << endl << endl;
  //x.wyswietl_macierz();
  x.zapisz_do_pliku(plik);
  system ("PAUSE");
  return 0;
}
