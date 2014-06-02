#include "generatory.h"
#include <cstdlib>

template < class typ >
typ generator<typ>::generuj(int n, double p, int start, int algorytm) {
  default_random_engine gen;
  int min, max;
  //Zakres rozkladu jednostajnego dla algorytmu Dijkstry
  if(algorytm==0) {
    min=1;
    max=500;
  }
  //Zakres rozkladu jednostajnego dla algorytmu Bellmana-Forda
  else {
    min=-10;
    max=1000;
  }
  uniform_real_distribution<double> jednostajny(min,max);
  typ dane(n); //Konstruktor macierzy/listy
  int waga, losuj, krawedzie=0;
  srand(time(NULL));
  for(int i=0; i<n; i++) {
  	for(int j=i+1; j<n; j++) {
  	  if(rand()%100 < p*100.d) {
        do {
          waga=jednostajny(gen);
        } while(waga<min || waga>max);
        losuj=rand()%2+1; //Losuje kierunek polaczenia dwoch wierzcholkow
        if(losuj==1)
          dane.dodaj(i,j,waga);
        else
          dane.dodaj(j,i,waga);
        krawedzie++;
  	  }
  	}
  }
  dane.krawedzie=krawedzie;
  dane.wierzcholki=n;
  dane.start=start;
  return dane; //Zwraca graf o zadanym typie (macierz/lista)
}
