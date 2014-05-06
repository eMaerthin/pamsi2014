//autor: Marcin Ochocki 200330

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <math.h>
#include <time.h>
#define ROZMIAR 1000
#define ROZMIAR2 1000
using namespace std;
fstream plik;

class graf {
	list<vector<int> > drzewo;          //Lista zawierajaca wierzcholki oraz wagi drzewa (wektory)
	int macierz[ROZMIAR2][ROZMIAR2];   //Macierz polaczen
	int max;						   //Maksymalny indeks macierzy
	int suma;						   //Suma wag drzewa
	public:
	void czytaj_plik(fstream & plik);
	void zapisz_do_pliku(fstream & plik);
	void generator_grafu(int n, float p);
	int sprawdz_spojnosc();
	void graf_pelny(int n);
	void stworz_macierz();
	void sortuj_wagi();
	void stworz_min();       //Tworzy MDR (po uprzednim posortowaniu wag)
	void suma_wag();		 //Sumuje wagi drzewa
	void wyswietl_liste();   //Wyswietla drzewo
	void wyswietl_macierz();
};

void graf::czytaj_plik(fstream & plik) {
  plik.open("dane3.txt", ios::in);
  int x;
  max=0;
  cout << endl;
  if( plik.good() == true )
	cout << "[Wczytywanie] Uzyskano dostep do pliku :)" << endl << endl;
  else 
	cout << "[Wczytywanie] Brak dostepu do pliku :(" << endl << endl; 
  do {
  	vector<int>tmp;
  	for(int i=0; i<3; i++) {
  	  plik >> x;
	  tmp.push_back(x);
	  if(i==0 || i==1) {
	  	if(x>max) //Jesli wierzcholek jest wiekszy od maksymalnego indeksu macierzy
	  	  max=x;  //Zmien maksymalny indeks macierzy
	  }
    }
    drzewo.push_back(tmp); //Dodaj wektor do drzewa
  } while(!plik.eof());
  plik.close();
}

void graf::zapisz_do_pliku(fstream & plik) {
  plik.open("zapisane.txt", ios::out);
  cout << endl;
  if( plik.good() == true )
	cout << "[Zapisywanie] Uzyskano dostep do pliku :)" << endl << endl;
  else 
	cout << "[Zapisywanie] Brak dostepu do pliku :(" << endl << endl; 
  for(list<vector<int> >::iterator it1=drzewo.begin(); it1!=drzewo.end(); it1++) { //Przeszukiwanie drzewa
	for(vector<int>::iterator it2=(*it1).begin(); it2!=(*it1).end(); it2++) {     //Przeszukiwanie wektora
	  if(*it2<10)
	    plik << " ";
	  plik << *it2 << " ";
    }
    plik << "\n";
  }
  plik.close();
}

void graf::generator_grafu(int n, float p) {
  int waga;
  vector<int> tmp;
  max=n-1;
  srand(time(NULL));
  for(int i=0; i<n; i++) {
  	for(int j=0; j<n; j++) {
  	  macierz[i][j]=-1;
  	}
  }
  for(int i=0; i<n; i++) {
  	for(int j=0; j<n; j++) {
  	  if(rand()%100000 < p*100000.f) {
  	  	waga=rand()%100+10;
  	  	macierz[i][j]=waga;
		macierz[j][i]=waga;
  	  	tmp.push_back(i);
  	  	tmp.push_back(j);
  	  	tmp.push_back(waga);
  	  	drzewo.push_back(tmp);
  	  	tmp.clear();
  	  	//cout << i << " " << j << " " << waga << endl;
  	  }
  	}
  }
}

int graf::sprawdz_spojnosc() {
  int licz;
  for(int i=0; i<max; i++) {
  	licz=0;
  	for(int j=0; j<=max; j++) {
  	  if(macierz[i][j]==-1)
  	    licz++;
    }
    if(licz==max) {
      cout << endl << "[Sprawdzanie spojnosci grafu] Graf nie jest spojny :(" << endl;
      system ("PAUSE");
      return 0;
    }
  }
  cout << endl << "[Sprawdzanie spojnosci grafu] Graf jest spojny :)" << endl;
  return 1;
}

void graf::graf_pelny(int n) {
  int waga;
  vector<int> tmp;
  max=n;
  srand(time(NULL));
  for(int i=0; i<=max; i++) {
  	for(int j=0; j<=max; j++) {
  	  waga=rand()%100+10;
  	  macierz[i][j]=macierz[j][i]=waga;
  	  tmp.push_back(i);
  	  tmp.push_back(j);
  	  tmp.push_back(waga);
  	  drzewo.push_back(tmp);
  	  tmp.clear();
    }
  }
}

void graf::stworz_macierz() {
  int x,y;
  for(int i=0; i<=max; i++) {
  	for(int j=0; j<=max; j++) {
  	  macierz[i][j]=-1;
  	}
  }
  for(list<vector<int>>::iterator it1=drzewo.begin(); it1!=drzewo.end(); ++it1) { //Przeszukiwanie drzewa
	for(vector<int>::iterator it2=(*it1).begin(); it2!=(*it1).end(); ++it2) {     //Przeszukiwanie wektora
	  x=*it2++;
	  y=*it2++++;
      macierz[x][y]=*it2;
      macierz[y][x]=*it2;
    }
  }
}

void graf::sortuj_wagi() {	
  drzewo.sort([](const vector<int> & a, const vector <int> & b) { return a.back() < b.back(); });
}

void graf::stworz_min() {
  int ile=1;  //Zmienna zawierajaca rozmiar MDR
  int a, b, x, y, i, j, k;
  list<vector<int>> min[1000];
  list<vector<int>>::iterator it1, it3; //Iteratory do przeszukiwania drzewa
  vector<int>::iterator it2, it4;	    //Iteratory do przeszukiwania wektorow
  for(it1=drzewo.begin(); it1!=drzewo.end(); ++it1) { 
  	for(it2=(*it1).begin(), i=1; i<3; ++it2, ++i) {
  	  if(i==1) //Jesli jest to pierwszy wierzcholek
  	    a=-1;  //Wartosc pierwszego wierzcholka jest nieokreslona
  	  else     //Jesli jest to drugi wierzcholek
  	    b=-1;  //Wartosc drugiego wierzcholka jest nieokreslona
  	  for(j=0; j<ile; j++) { //Przeszukaj tymczasowe drzewa
  	  	for(it3=min[j].begin(); it3!=min[j].end(); ++it3) { 
  	  	  for(it4=(*it3).begin(), k=1; k<3; ++it4, ++k) {
		    if(*it2==*it4 && i==1) { //Jesli pierwszy wierzcholek juz wystapil na drzewie
		  	  a=j;    //Zapisz indeks tymczasowego drzewa
		  	  x=*it2; //Zapisz wierzcho³ek
		    }
		    if(*it2==*it4 && i==2) { //Jesli drugi wierzcholek juz wystapil na drzewie
		      b=j;    //Zapisz indeks tymczasowego drzewa
		      y=*it2; //Zapisz wierzcho³ek
		    }
		  }
	    }
  	  }
    }
    if(a>-1 && b>-1) {
      //Laczenie 2 drzew o zadanych indeksach ze soba
      if(a!=b) {
      	if(a<b) {
      	  for(it3=min[b].begin(); it3!=min[b].end(); ++it3)
      	    min[a].push_back(*it3);
          min[a].push_back(*it1);
          min[b].clear(); //Usuniecie drzewa o wyzszym indeksie
        }
        if(a>b) {
          for(it3=min[a].begin(); it3!=min[a].end(); ++it3)
      	    min[b].push_back(*it3);
          min[b].push_back(*it1);
          min[a].clear(); //Usuniecie drzewa o wyzszym indeksie
        }
      }
      //Przypadek gdy wierzcho³ek okresla sam siebie
      if(a==b && x==y)
      	min[a].push_back(*it1);
    }
    //Dodanie do drzewa o zadanym indeksie
    if(a>-1 && b==-1)
      min[a].push_back(*it1);
    //Dodanie do drzewa o zadanym indeksie
    if(a==-1 && b>-1)
      min[b].push_back(*it1);
    //Nie znaleziono na zadnym drzewie, tworzenie nowego drzewa
    if(a==-1 && b==-1) {
      min[ile-1].push_back(*it1);
      ++ile;
    }
    //Jesli nie spelnione sa powyzsze warunki to znaczy ze wystapil cykl
    //wiec wektor bedzie ignorowany
  }
  drzewo=min[0]; //Kopiuj tymczasowe drzewo o najnizszym indeksie do naszego drzewa
  for(i=0; i<ile; i++)
    min[i].clear(); //Wyczysc tymczasowe drzewa
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
  int opcja, n;
  float p;
  cout << endl << "Skad chcesz wziac parametry grafu?" << endl 
	   << "0 - z pliku" << endl
	   << "1 - wygenerowany losowo" << endl 
	   << "Twoj wybor: ";
  cin >> opcja;
  switch(opcja) {
  	default: 
	return 0;
  	
  	case 0:
  	x.czytaj_plik(plik);
  	x.stworz_macierz();
  	break;
  	
  	case 1: {
  	cout << endl << "Ile ma byc wierzcholkow w grafie?" << endl
  	   << "0 - 500" << endl
  	   << "1 - 1000" << endl
  	   << "2 - 2000" << endl
  	   << "3 - 4000" << endl
  	   << "Twoj wybor: ";
    cin >> opcja;
    
    switch(opcja) {
	  case 0: n=500; break;
	  case 1: n=1000; break;
	  case 2: n=2000; break;
	  case 3: n=4000; break;
	  default: return 0;
    }
    cout << endl << "Jakie ma byc prawdopodobienstwo p?" << endl
  	   << "0 - [3log2(n)]/n" << endl
  	   << "1 - n^(-1/3)" << endl
  	   << "2 - graf pelny" << endl
  	   << "Twoj wybor: ";
    cin >> opcja;
    
    switch(opcja) {
	  case 0: 
	  p=(3*(log((float)n))/(log(2)))/(float)n;
	  cout << endl << "p="<< p << endl;
	  x.generator_grafu(n,p);
  	  x.sprawdz_spojnosc();
	  break;
	  
	  case 1:
	  p=pow((float)n, -1/3.f);
	  cout << endl << "p="<< p << endl;
	  x.generator_grafu(n,p);
  	  x.sprawdz_spojnosc();
	  break;
	  
	  case 2: 
	  x.graf_pelny(n);
	  break;
	  
	  default: 
	  return 0;
    }
    }
  }
    
  cout << endl << "Poczatkowe drzewo:" << endl << endl;
  //x.wyswietl_liste();
  x.sortuj_wagi();
  x.suma_wag(); 
  //cout << endl << "Posortowane wagi:" << endl << endl;
  //x.wyswietl_liste();
  x.stworz_min();
  x.stworz_macierz();
  x.sortuj_wagi();
  cout << endl << "Minimalne drzewo:" << endl << endl;
  //x.wyswietl_liste();
  x.suma_wag(); 
  //cout << endl << "Macierz polaczen:" << endl << endl;
  //x.wyswietl_macierz();
  x.zapisz_do_pliku(plik);
  system ("PAUSE");
  return 0;
}
