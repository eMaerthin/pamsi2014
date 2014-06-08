#include "bellman_ford.h"

int bellman_ford::znajdz_drogi(macierz dane, int n) {
  //cout << endl << "[Tworzenie minimalnych drog...] ";
  list<int>::iterator it;
  int i, j, k, licz;
  double inf=numeric_limits<double>::infinity();
  droga = new double[n]; //Tworzenie tablicy drog
  for(i=0; i<n; i++)
  	droga[i]=inf; //Droga do kazdego wierzcholka jest nieskonczona
  droga[dane.start]=0;  //Droga do pierwszego wierzcholka wynosi 0
  for(k=0; k<n; k++) {
    for(i=0; i<n; i++) {
      for(j=0; j<n; j++) {
        if(dane.graf[i][j]!=-1) { //Jesli dana w macierzy o zadanych indeksach nie jest nieokreslona
          if(droga[i]!=inf && droga[i]+dane.graf[i][j]<droga[j]) {
            droga[j]=droga[i]+dane.graf[i][j];
            przejscia[j]=przejscia[i];  //Kopiuj ciag wierzcholkow
            przejscia[j].push_back(j);  //Dodaj do ciagu wierzcholek koncowy
            if(droga[j]<0) { //Jesli koszt drogi jest mniejszy od 0
              licz=0;
              for(it=przejscia[j].begin(); it!=przejscia[j].end(); it++) {
                if((*it)==j) { //Jesli znaleziono zadany wierzcholek
                  licz++;
                  if(licz>1) { //Jesli znaleziono go wiecej niz raz
                    //cout << "Znaleziono cykl ujemny :<" << endl;
                    return 2;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  //cout << "Utworzono :>" << endl;
  return 1;
}

int bellman_ford::znajdz_drogi(lista dane, int n) {
  //cout << endl << "[Tworzenie minimalnych drog...] ";
  int i, x, y, licz;
  list<int>::iterator it;
  list<vector<int> >::iterator it1;
  vector<int>::iterator it2;
  double inf=numeric_limits<double>::infinity();
  droga = new double[n]; //Tworzenie tablicy drog
  for(i=0; i<n; i++)
  	droga[i]=inf; //Droga do kazdego wierzcholka jest nieskonczona
  droga[dane.start]=0;  //Droga do pierwszego wierzcholka wynosi 0
  for(i=0; i<n; i++) {
    for(it1=dane.graf.begin(); it1!=dane.graf.end(); it1++) { //Przeszukaj liste wektorow
      it2=(*it1).begin();
      x=(*it2); //Zapisz pierwszy wierzcholek
      it2++;
      y=(*it2); //Zapisz drugi wierzcholek
      it2++;
      if(droga[x]!=inf && droga[x]+(*it2)<droga[y]) {
        droga[y]=droga[x]+(*it2);
        //cout << y << " " << droga[y] << "     ";
        //system("PAUSE");
        przejscia[y]=przejscia[x];  //Kopiuj ciag wierzcholkow
        przejscia[y].push_back(y);  //Dodaj do ciagu wierzcholek koncowy
        if(droga[y]<0) {  //Jesli koszt drogi jest mniejszy od 0
          licz=0;
          for(it=przejscia[y].begin(); it!=przejscia[y].end(); it++) {
            if((*it)==y) {  //Jesli znaleziono zadany wierzcholek
              licz++;
              if(licz>1) {  //Jesli znaleziono go wiecej niz raz
                //cout << "Znaleziono cykl ujemny :<" << endl;
                return 2;
              }
            }
          }
        }
      }
    }
  }
  //cout << "Utworzono :>" << endl;
  return 1;
}

void bellman_ford::wyswietl_drogi(double * droga, int n, int start) {
  list<int>::iterator it;
  cout << endl << "Najkrotsze polaczenia:" << endl;
  for(int i=0; i<n; i++) {
    cout << start;
    for(it=przejscia[i].begin(); it!=przejscia[i].end(); it++) {
      cout << " -> " << *it;
    }
    if(przejscia[i].size()==0)
      cout << " -> " << i;
    cout << ": " << droga[i] << endl;
  }
}

void bellman_ford::zapisz_do_pliku(fstream & plik, int n, int start) {
  plik.open("zapisane.txt", ios::out);
  list<int>::iterator it;
  cout << endl << "[Zapisywanie] ";
  if( plik.good() == true )
    cout << "Uzyskano dostep do pliku :)" << endl;
  else
    cout << "Brak dostepu do pliku :(" << endl;
  for(int i=0; i<n; i++) {
    plik << i << " " << droga[i] << " " << start;
    for(it=przejscia[i].begin(); it!=przejscia[i].end(); it++) {
      plik << " " << *it;
    }
    if(przejscia[i].size()==0 && i!=start)
      plik << " " << i;
    plik << "\n";
  }
  plik.close();
}
