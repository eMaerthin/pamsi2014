#include "generatory.h"

macierz generator_macierzy::graf_er(int n, float p) {
  macierz dane(n);
  int waga, licz=0;
  srand(time(NULL));
  for(int i=0; i<n; i++) {
  	for(int j=i+1; j<n; j++) {
  	  if(rand()%100000 < p*100000.f) {
  	  	waga=rand()%100+10;
        dane.dodaj(i,j,waga);
        licz++;
  	  	//cout << i << " " << j << " " << waga << endl;
  	  }
  	}
  }
  dane.gestosc=(float)licz/(((float)n*(float)n)-(float)n);
  return dane;
}

macierz generator_macierzy::graf_pelny(int n) {
  macierz dane(n);
  int waga;
  srand(time(NULL));
  for(int i=0; i<n; i++) {
  	for(int j=i+1; j<n; j++) {
      waga=rand()%100+10;
      dane.dodaj(i,j,waga);
      //cout << i << " " << j << " " << waga << endl;
    }
  }
  dane.gestosc=1;
  return dane;
}

lista generator_listy::graf_er(int n, float p) {
  lista dane;
  int waga, licz=0;
  srand(time(NULL));
  for(int i=0; i<n; i++) {
  	for(int j=i+1; j<n; j++) {
  	  if(rand()%100000 < p*100000.f) {
  	  	waga=rand()%100+10;
        dane.dodaj(i,j,waga);
        licz++;
  	  	//cout << i << " " << j << " " << waga << endl;
  	  }
  	}
  }
  dane.gestosc=(float)licz/(((float)n*(float)n)-(float)n);
  return dane;
}

lista generator_listy::graf_pelny(int n) {
  lista dane;
  int waga;
  srand(time(NULL));
  for(int i=0; i<n; i++) {
  	for(int j=i+1; j<n; j++) {
      waga=rand()%100+10;
      dane.dodaj(i,j,waga);
      //cout << i << " " << j << " " << waga << endl;
    }
  }
  dane.gestosc=1;
  return dane;
}
