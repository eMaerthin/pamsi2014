#include "obsluga_plikow.h"

template < class typ >
typ obsluga_plikow<typ>::czytaj_plik(fstream & plik, int n) {
  typ dane(n);
  plik.open("dane.txt", ios::in);
  int x[3];
  cout << endl << "[Wczytywanie] ";
  if( plik.good() == true )
    cout << "Uzyskano dostep do pliku :)" << endl;
  else
    cout << "Brak dostepu do pliku :(" << endl;
  //Odczytanie pierwszej linijki tekstu i zapisanie:
  //liczby krawedzi, wierzcholkow oraz wierzcholka startowego
  plik >> x[0];
  dane.krawedzie=x[0];
  plik >> x[0];
  dane.wierzcholki=x[0];
  plik >> x[0];
  dane.start=x[0];
  do {
  	for(int i=0; i<3; i++) {
  	  plik >> x[i];
    }
    dane.dodaj(x[0],x[1],x[2]); //Dodaj wektor do drzewa
  } while(!plik.eof());
  plik.close();
  return dane;
}

template < class typ >
int obsluga_plikow<typ>::znajdz_max(fstream & plik) {
  plik.open("dane.txt", ios::in);
  int x,max;
  cout << endl << "[Szukanie maksymalnego indeksu macierzy] ";
  if( plik.good() == true )
    cout << "Uzyskano dostep do pliku :)" << endl;
  else
    cout << "Brak dostepu do pliku :(" << endl;
  max=0;
  plik >> x >> x >> x; //Pominiecie pierwszej linijki tekstu
  do {
    for(int i=0; i<2; i++) {
      plik >> x;
      if(max<x)
        max=x;
    }
    plik >> x;
  } while(!plik.eof());
  plik.close();
  return max+1;
}
