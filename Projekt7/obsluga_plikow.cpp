#include "obsluga_plikow.h"

siec obsluga_plikow::czytaj_plik(fstream & plik, string nazwa, int n) {
  siec dane(n);
  plik.open(nazwa, ios::in);
  int x[3];
  //cout << endl << "[Wczytywanie] ";
  //Odczytanie pierwszej linijki tekstu i zapisanie:
  plik >> x[0];
  dane.wierzcholki=x[0];  //v - liczba wierzcholkow w calej sieci
  plik >> x[0];
  dane.krawedzie=x[0];    //e - liczba krawedzi w calej sieci
  plik >> x[0];
  dane.zrodlo=x[0]; //s - zrodlo
  plik >> x[0];
  dane.ujscie=x[0]; //u - ujscie
  do {
    //Odczytywanie i zapisywanie kolejnych linijek tekstu:
  	for(int i=0; i<3; i++)
  	  plik >> x[i];
    dane.macierz[x[0]][x[1]][0]=x[2];
  } while(!plik.eof());
  plik.close();
  return dane;
}
