//autor: Marcin Ochocki 200330

#include <iostream>
#include <fstream>
#include <time.h>
#include <boost/timer.hpp>
#include <cstdlib>
#include <random>
#define ROZMIAR 100000
using namespace std;
fstream plik;

template < class typ >
class sortowanie {
	private:
	typ tab[ROZMIAR];
	public:
	void ktory_rozklad(long rozmiar);
	int bubble(long rozmiar);
	void sortfast(long lewy, long prawy);
	int scalaj(long lewy, long srodek, long prawy, long rozmiar);
	void sortuj_scalanie(long lewy, long prawy, long rozmiar);
	void zapiszdopliku(fstream & plik, long rozmiar);
	void czytajplik(fstream & plik, long rozmiar);
	void wyswietl(long rozmiar);
	void rodzaj_tablicy(long lewy, long prawy, long rozmiar);
};


//Wybiera rodzaj rozkladu:
template < class typ >
void sortowanie<typ>::ktory_rozklad(long rozmiar) {
  int opcja;
  cout << endl << "Z jakiego rozkladu maja byc liczby?" << endl
	   << "0 - rozklad normalny" << endl
	   << "1 - rozklad jednostajny" << endl
	   << "2 - rozklad Poissona" << endl
	   << "Twoj wybor: ";
  cin >> opcja;
  cout << endl;
  default_random_engine generator;
  if(opcja==0) {
  	normal_distribution<double> normalny(5.0,2.0); 
	for(int i=0; i<rozmiar; i++) {
  	  tab[i]=normalny(generator);
  	}
  }
  if(opcja==1) {
  	normal_distribution<double> jednostajny(0.0,5.0);
	for(int i=0; i<rozmiar; i++) {
  	  tab[i]=jednostajny(generator);
  	}
  }
  if(opcja==2) {
  	normal_distribution<double> poisson(4.1);
	for(int i=0; i<rozmiar; i++) {
  	  tab[i]=poisson(generator);
  	}
  }
}

//Sortowanie b¹belkowe:
template < class typ >
int sortowanie<typ>::bubble(long rozmiar) {
  int p;
  for(long j=rozmiar-2; j>=1; j--) {
    p=1;
    for(long i=0; i<=j; i++) {
      if(tab[i]>tab[i+1]) {
        swap(tab[i], tab[i+1]);
        p=0;
      }
    }
    if(p==1) {
      return 1;
    }
  }
  return 1;
}

//Sortowanie szybkie:
template < class typ >
void sortowanie<typ>::sortfast(long lewy, long prawy) {
  long i=(lewy+prawy)/2;
  typ srodek=tab[i];
  tab[i]=tab[prawy];
  long j=lewy;
  for(i=lewy; i<prawy; i++) {
    if(tab[i]<srodek) {
	  swap(tab[i], tab[j]);
      j++;
    }
  }
  tab[prawy]=tab[j];
  tab[j]=srodek;
  if(lewy<j) {
    sortfast(lewy,j-1);
  }
  if(j+1<prawy) {
    sortfast(j+1,prawy);
  }
}

//Sortowanie przez scalanie (cz. II):
template < class typ >
int sortowanie<typ>::scalaj(long lewy, long srodek, long prawy, long rozmiar) {
	typ tmp[rozmiar];
	long i1=lewy;
	long i2=srodek;
	for(long i=lewy; i<=prawy; i++) {
		if(i1==srodek) {
			tmp[i]=tab[i2];
			i2++;
		}
		else {
			if(i2>prawy) {
				tmp[i]=tab[i1];
				i1++;
			}
			else {
				if(tab[i1]>tab[i2]) {
					tmp[i]=tab[i2];
					i2++;
				}
				else {
					tmp[i]=tab[i1];
					i1++;
				}
			}
		}
	}
	for(long i=lewy; i<=prawy; i++) {
		tab[i]=tmp[i];
	}
	return 1;
}

//Sortowanie przez scalanie (cz. I):
template < class typ >
void sortowanie<typ>::sortuj_scalanie(long lewy, long prawy, long rozmiar) {
	long srodek=(lewy+prawy+1)/2;
	if(srodek-lewy>1) {
		sortuj_scalanie(lewy, srodek-1, rozmiar);
	}
	if(prawy-srodek>0) {
		sortuj_scalanie(srodek, prawy, rozmiar);
	}
	scalaj(lewy,srodek,prawy,rozmiar);
}

//Zapisuje tablice liczb do pliku:
template < class typ >
void sortowanie<typ>::zapiszdopliku(fstream & plik, long rozmiar) {
  plik.open("dane.txt", ios::out);
	  
  if( plik.good() == true ) {
	cout << "[Zapis] Uzyskano dostep do pliku" << endl;
  }  
  else 
	cout << "[Zapis] Brak dostepu do pliku" << endl;	
  for(int i=0; i<rozmiar; i++) {
    plik << tab[i] << " ";
  }
  plik.close();
}

//Wczytuje tablice liczb z pliku:
template < class typ >
void sortowanie<typ>::czytajplik(fstream & plik, long rozmiar) {
  plik.open("dane.txt", ios::in);
    
  if( plik.good() == true ) {
	cout << "[Wczytywanie] Uzyskano dostep do pliku" << endl;
  }  
  else 
	cout << "[Wczytywanie] Brak dostepu do pliku" << endl; 
  for(int i=0; i<rozmiar; i++) {
    plik >> tab[i];
  }
  plik.close();
}

//Wyswietla tablice liczb:
template < class typ >
void sortowanie<typ>::wyswietl(long rozmiar) {
  for(int i=0; i<rozmiar; i++) {
    cout << tab[i] << " ";
  }
}

//Fukcja w ktorej wybieramy jaka czesc tablicy ma byc posortowana:
template < class typ >
void sortowanie<typ>::rodzaj_tablicy(long lewy, long prawy, long rozmiar) {
  int opcja;
  cout << endl << "0 - tablica zupelnie losowa" << endl 
	   << "1 - pierwsze 50% posortowane" << endl
	   << "2 - pierwsze 90% posortowane" << endl 
	   << "3 - pierwsze 99% posortowane" << endl
	   << "Twoj wybor: ";
  cin >> opcja;
  cout << endl;
  switch(opcja) {
	case 0: break;
	case 1: 
	  prawy=prawy/2;
	  sortuj_scalanie(lewy, prawy, prawy);
  	  zapiszdopliku(plik, rozmiar);
	  break;
	case 2: 
	  prawy=0.9*prawy;
	  sortuj_scalanie(lewy, prawy, prawy);
  	  zapiszdopliku(plik, rozmiar);
	  break;
	case 3: 
	  prawy=0.99*prawy;
	  sortuj_scalanie(lewy, prawy, prawy);
  	  zapiszdopliku(plik, rozmiar);
	  break;
  }
}

int main() {
	fstream plik;
	float poczatkowy;
	float koncowy[3];
	int opcja;
	long rozmiar;
	boost::timer czas;
	cout << "Ile elementow chcesz posortowac?" << endl
		 << "0 - 10" << endl << "1 - 100" << endl
		 << "2 - 1000" << endl << "3 - 10 000" << endl
		 << "4 - 100 000" << endl << "5 - 1000 000" << endl
		 << "Twoj wybor: ";
	cin >> opcja;
	switch(opcja) {
	  case 0: rozmiar=10; break;
	  case 1: rozmiar=100; break;
	  case 2: rozmiar=1000; break;
	  case 3: rozmiar=10000; break;
	  case 4: rozmiar=100000; break;
	  case 5: rozmiar=1000000; break;
	  default: return 0;
	}
	
	long lewy=0;
	long prawy=rozmiar-1;
	cout << endl << "Jakie elementy chcesz sortowac?" << endl
		 << "0 - zmienne typu int" << endl
		 << "1 - zmienne typu double" << endl
		 << "Twoj wybor: ";
	cin >> opcja;
	
	switch(opcja) {
		case 0:
		sortowanie <int> x;
		x.ktory_rozklad(rozmiar);
		x.zapiszdopliku(plik, rozmiar);
		x.rodzaj_tablicy(lewy, prawy, rozmiar);
		
		x.czytajplik(plik, rozmiar);
		poczatkowy=czas.elapsed();
		x.bubble(rozmiar);
		koncowy[0]=czas.elapsed()-poczatkowy;
		
		x.czytajplik(plik, rozmiar);
		poczatkowy=czas.elapsed();
    	x.sortfast(lewy, prawy);
    	koncowy[1]=czas.elapsed()-poczatkowy;
    	
    	x.czytajplik(plik, rozmiar);
    	poczatkowy=czas.elapsed();
    	x.sortuj_scalanie(lewy, prawy, rozmiar);
   		koncowy[2]=czas.elapsed()-poczatkowy;
   		
   		//x.wyswietl(rozmiar);
   		break;
   		
		case 1:
		sortowanie <double> y;
		y.ktory_rozklad(rozmiar);
		y.zapiszdopliku(plik, rozmiar);
		y.rodzaj_tablicy(lewy, prawy, rozmiar);
		
		y.czytajplik(plik, rozmiar);
		poczatkowy=czas.elapsed();
		y.bubble(rozmiar);
		koncowy[0]=czas.elapsed()-poczatkowy;
		
		y.czytajplik(plik, rozmiar);
		poczatkowy=czas.elapsed();
    	y.sortfast(lewy, prawy);
    	koncowy[1]=czas.elapsed()-poczatkowy;
    	
    	y.czytajplik(plik, rozmiar);
    	poczatkowy=czas.elapsed();
    	y.sortuj_scalanie(lewy, prawy, rozmiar);
   		koncowy[2]=czas.elapsed()-poczatkowy;
   		
   		//y.wyswietl(rozmiar);
   		break;
   		
		default: return 0;
	}
    cout << endl << endl << "Czas sortowania babelkowego: " << koncowy[0] << "s" << endl
         << "Czas sortowania szybkiego: " << koncowy[1] << "s" << endl
         << "Czas sortowania przez scalanie: " << koncowy[2] << "s" << endl;
    system ("PAUSE");
    return 0;
}
        
