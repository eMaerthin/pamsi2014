#include "macierz.h"

macierz::macierz(int n) {
  graf = new int*[n];
  for(int i=0; i<n; i++)
    graf[i] = new int[n];
  for(int i=0; i<n; i++) {
    for(int j=i; j<n; j++) {
      graf[i][j]=-1;
      graf[j][i]=-1;
    }
  }
  wierzcholki=n;
}

void macierz::dodaj(int pierwszy, int drugi, int waga) {
  graf[pierwszy][drugi]=waga;
}

void macierz::wyswietl_macierz() {
  cout << endl << "MACIERZ POLACZEN:" << endl;
  for(int i=0; i<wierzcholki; i++) {
    for(int j=0; j<wierzcholki; j++) {
      if(graf[i][j]==-1)
        cout << " - ";
      else {
        if(graf[i][j]<10)
          cout << " ";
        cout << graf[i][j] << " ";
      }
    }
    cout << endl;
  }
}

void macierz::wyswietl_parametry() {
  cout << endl << "Liczba krawedzi: " << krawedzie << " "
       << endl << "Liczba wierzcholkow: " << wierzcholki << " "
       << endl << "Wierzcholek startowy: " << start << endl;
}
