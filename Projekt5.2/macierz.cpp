#include "macierz.h"

macierz::macierz(int n) {
  drzewko = new int*[n];
  for(int i=0; i<n; i++)
    drzewko[i] = new int[n];
  for(int i=0; i<n; i++) {
    for(int j=i; j<n; j++) {
      drzewko[i][j]=-1;
      drzewko[j][i]=-1;
    }
  }
  max=n;
}

void macierz::dodaj(int pierwszy, int drugi, int waga) {
  drzewko[drugi][pierwszy]=waga;
  drzewko[pierwszy][drugi]=waga;
}

int macierz::suma_wag() {
  int suma=0;
  for(int i=0; i<max; i++) {
    for(int j=i+1; j<max; j++) {
      if(drzewko[i][j]!=-1)
        suma=suma+drzewko[i][j];
    }
  }
  return suma;
}

void macierz::wyswietl_macierz() {
  cout << endl << "MACIERZ POLACZEN:" << endl;
  for(int i=0; i<max; i++) {
    for(int j=0; j<max; j++) {
      if(drzewko[i][j]==-1)
        cout << " - ";
      else {
        if(drzewko[i][j]<10)
          cout << " ";
        cout << drzewko[i][j] << " ";
      }
    }
    cout << endl;
  }
}
