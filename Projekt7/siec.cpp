#include "siec.h"

siec::siec(int n) {
  macierz = new int**[n];
  for(int i=0; i<n; i++) {
    macierz[i] = new int*[n];
    for(int j=0; j<n; j++)
    //Pierwszy indeks oznacza siec residualna,
    //drugi indeks oznacza siec przeplywowa:
      macierz[i][j] = new int[2];
  }
  for(int i=0; i<n; i++) {
    for(int j=i; j<n; j++) {
      //Brak wartosci w tablicy 3D o zadanych indeksach w sieci residualnej:
      macierz[i][j][0]=-1;
      macierz[j][i][0]=-1;
      //Wyzerowanie przeplywow w sieci przeplywowej:
      macierz[i][j][1]=0;
      macierz[j][i][1]=0;
    }
  }
  wierzcholki=n; //Zapisz liczbe wierzcholkow
}

int siec::licz_fkrawedzie() {
  int fkrawedzie=0;
  for(int i=0; i<wierzcholki; i++) {;
    for(int j=0; j<wierzcholki; j++) {
      if(macierz[i][j][0]!=-1 && macierz[i][j][1]!=0)
        fkrawedzie++;
    }
  }
  return fkrawedzie;
}

void siec::wyswietl_siec_macierz() {
  cout << endl << "SIEC POLACZEN:" << endl;
  for(int i=0; i<wierzcholki; i++) {
    for(int j=0; j<wierzcholki; j++) {
      if(macierz[i][j][0]==-1)
        cout << " - ";
      else
        cout << macierz[i][j][0] << "/" << macierz[i][j][1] << " ";
    }
    cout << endl;
  }
}

void siec::wyswietl_siec_lista() {
  cout << endl << "SIEC POLACZEN:" << endl;
  for(int i=0; i<wierzcholki; i++) {
    for(int j=0; j<wierzcholki; j++) {
      if(macierz[i][j][0]!=-1)
        cout << i << " -> " << j << ": " << macierz[i][j][0] << "/" << macierz[i][j][1] << " " << endl;
    }
  }
}

void siec::wyswietl_parametry() {
  cout << endl << "Wierzcholki: " << wierzcholki;
  cout << endl << "Krawedzie: " << krawedzie;
  cout << endl << "Zrodlo: " << zrodlo;
  cout << endl << "Ujscie: " << ujscie << endl;
}
