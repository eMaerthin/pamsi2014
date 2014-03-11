// autor: Marcin Ochocki 200330

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>  
#define ROZMIAR 100
using namespace std;
fstream plik, binarny;

//Wczytywanie tablicy z konsoli:
void wczytaj(int *tab, int &ile) {
    for(int i=0; i<ile; i++) {
      cin >> tab[i];
    }
}

//Wyswietlanie tablicy:
void wyswietl(int *tab, int &ile) {
      for(int i=0; i<ile; i++) {
      cout << tab[i] << endl;
    }
}

//Wczytywanie tablicy z pliku tekstowego:
void czytajplik(fstream & plik, int *tab, int &ile) {
    plik.open("tabliczka.txt", ios::in);
    
    if( plik.good() == true ) {
		cout << "Uzyskano dostep do pliku" << endl;
	}  
	else 
		cout << "Brak dostepu do pliku" << endl;
    
    for(int i=0; i<ile; i++) {
      plik >> tab[i];
    }
}

//Zapisywanie tablicy do pliku tekstowego:
void zapiszdopliku(fstream & plik, int *tab, int &ile) {
	  plik.open("tabliczka.txt", ios::out);
	  
	  if( plik.good() == true ) {
		cout << "Uzyskano dostep do pliku" << endl;
	  }  
	  else 
		cout << "Brak dostepu do pliku" << endl;
		
      for(int i=0; i<ile; i++) {
      plik << tab[i] << " ";
    }
}

//Wczytywanie rozmiaru tablicy z konsoli:
void podajile(int &ile) {
     cin >> ile;
}

//Losowanie elementow tablicy z przedzialu 1-10:
void losuj(int *tab, int &ile) {
     
    srand(time(NULL));
     
    for(int i=0; i<ile; i++) {
      tab[i]=rand() % 10 + 1;
    }
}

//Kopiowanie tablicy + wyswietlanie:
int *kopiuj(int *tab, int *kopia, int &ile) {
     kopia=new int[ile];
     
     for(int i=0; i<ile; i++) {
       kopia[i]=tab[i];
     }
     
     for(int i=0; i<ile; i++) {
       cout << kopia[i] << endl;
     }
     
     delete [] kopia;
     
     return kopia;
}

//Zapisywanie tablicy do pliku binarnego:
void ZapiszDoBinarnego(fstream & binarny, int *tab, char *bin, int &ile) {
    
    binarny.open("binarny.bin", ios::out | ios::binary);
    
    if( plik.good() == true ) {
		cout << "Uzyskano dostep do pliku" << endl;
	}  
	else 
		cout << "Brak dostepu do pliku" << endl;
    
    for(int i=0; i<ile; i++) {
      bin[i]=tab[i];
      binarny.write((char*)bin+i,sizeof(char));
    }
}

//Wczytywanie tablicy z pliku binarnego:
void WczytajzBinarnego(fstream & binarny, int *tab, char *bin, int &ile) {
	
	binarny.open("binarny.bin", ios::out | ios::binary);
	
	if( plik.good() == true ) {
		cout << "Uzyskano dostep do pliku" << endl;
	}  
	else 
		cout << "Brak dostepu do pliku" << endl;
	
	for(int i=0; i<ile; i++) {
		binarny.read((char*)bin+i,sizeof(char));
	}
	for(int i=0; i<ile; i++) {
		tab[i]=(int)bin[i];
	}
		
}

int main() {
    int tab[ROZMIAR], ile, opcja, kopia[ROZMIAR];
    char bin[ROZMIAR];
    cout << "Podaj rozmiar tablicy: ";
    podajile(ile);
    cout << endl << "Pamietaj ze tablica przez caly czas trwania "
    	 << endl << "programu bedzie miala taki sam rozmiar!"
		 << endl;
    
    
    do {
		
	  cout << endl;
      cout << "1.Wczytanie tablicy z konsoli"<<endl;
   	  cout << "2.Wyswietlenie tablicy"<<endl;
   	  cout << "3.Wczytywanie z pliku tekstowego"<<endl;
  	  cout << "4.Zapisywanie do pliku tekstowego"<<endl;
      cout << "5.Wczytywanie z pliku binarnego"<<endl;
      cout << "6.Zapisywanie do pliku binarnego"<<endl;
      cout << "7.Wypelnianie tablicy"<<endl;
   	  cout << "8.Tworzenie dynamicznej kopii + wyswietlenie kopii"<<endl;
      cout << "0.Koniec"<<endl<<endl;
		
      cout << endl << "Wybierz opcje: ";
      cin >> opcja;
      cout << endl;
        
      switch(opcja) {
        case 1:
          wczytaj(tab, ile);
          break;
        case 2:
          wyswietl(tab, ile);
          cout << endl;
          break;
        case 3: 
          czytajplik(plik, tab, ile);
          break;
        case 4:
          zapiszdopliku(plik, tab, ile);
          break;
        case 5:
		  WczytajzBinarnego(binarny, tab, bin, ile);
          break;
        case 6:
		  ZapiszDoBinarnego(binarny, tab, bin, ile);
          break;
        case 7:
          losuj(tab, ile);
          break;
        case 8:
          kopiuj(tab, kopia, ile);
          cout << endl;
          break;
        case 0:
          cout << endl << "Koniec" << endl;
          return 0;
          break;
        default:
          break;
      }
   } while (opcja!=0);
}
      
