#include "dijkstra.h"
#include <cstdlib>

double dijkstra::wez_najmniejszy(double * droga) {
  list<int>::iterator it, it_min;
  int min;
  it_min=wierzcholki.begin();
  for(it=wierzcholki.begin(); it!=wierzcholki.end(); ++it) {
    if(droga[*it]>*it_min)
      it_min=it;
  }
  min=*it_min;
  wierzcholki.erase(it_min);
  return min;
}

void dijkstra::znajdz_drogi(lista dane, int n) {
  //cout << endl << "[Tworzenie minimalnych drog...] ";
  int poczatek, koniec, waga;
  list<vector<int>>::iterator it1;
  vector<int>::iterator it2;
  droga = new double[n];
  for(int i=0; i<n; i++)
  	droga[i]=-1;
  wierzcholki.push_back(dane.start);
  do {
  	poczatek=wez_najmniejszy(droga); //Bierze wierzcholek do ktorego jest najkrotsze polaczenie
    for(it1=dane.graf.begin(); it1!=dane.graf.end(); ++it1) {
      it2=(*it1).begin();
      if(*it2==poczatek) { //Jesli znaleziono wierzcholek poczatkowy
        ++it2;
        if(droga[*it2]==-1) //Jesli droga do wierzcholka jest nieokreslona
          wierzcholki.push_back(*it2); //Dodaj do listy wierzcholkow do rozpatrzenia
        koniec=*it2; //Zapisz wierzcholek koncowy
        ++it2;
        waga=*it2;  //Zapisz wage polaczenia
        if(droga[koniec]==-1 || droga[koniec]>droga[poczatek]+waga) {
          if(droga[poczatek]==-1) //Jesli droga do wierzcholka jest nieokreslona
            droga[poczatek]=0;
          droga[koniec]=droga[poczatek]+waga;
          przejscia[koniec]=przejscia[poczatek];  //Kopiuj ciag wierzcholkow
          przejscia[koniec].push_back(koniec);    //Dodaj do ciagu wierzcholek koncowy
        }
      }
    }
  } while(!wierzcholki.empty());
  //Droga do wierzcholko, z ktorymi nie ma polaczenia ustaw na nieskonczona
  for(int i=0; i<n; i++) {
    if(droga[i]==-1)
      droga[i] = numeric_limits<double>::infinity();
  }
  //cout << "Utworzono :>" << endl;
}

void dijkstra::znajdz_drogi(macierz dane, int n) {
  //cout << endl << "[Tworzenie minimalnych drog...] ";
  int poczatek, koniec, waga, i;
  droga = new double[n];
  for(int i=0; i<n; i++)
  	droga[i]=-1;
  wierzcholki.push_back(dane.start);
  do {
  	poczatek=wez_najmniejszy(droga); //Bierze wierzcholek do ktorego jest najkrotsze polaczenie
    for(i=0; i<n; i++) {
      if(dane.graf[poczatek][i]!=-1) { //Jesli dana w macierzy o zadanych indeksach nie jest nieokreslona
        if(droga[i]==-1) //Jesli droga do wierzcholka jest nieokreslona
          wierzcholki.push_back(i); //Dodaj do listy wierzcholkow do rozpatrzenia
        koniec=i; //Zapisz wierzcholek koncowy
        waga=dane.graf[poczatek][koniec]; //Zapisz wage polaczenia
        if(droga[koniec]==-1 || droga[koniec]>droga[poczatek]+waga) {
          if(droga[poczatek]==-1) //Jesli droga do wierzcholka jest nieokreslona
            droga[poczatek]=0;
          droga[koniec]=droga[poczatek]+waga;
          przejscia[koniec].clear();
          przejscia[koniec]=przejscia[poczatek];  //Kopiuj ciag wierzcholkow
          przejscia[koniec].push_back(koniec);    //Dodaj do ciagu wierzcholek koncowy
        }
      }
    }
  } while(!wierzcholki.empty());
  //Droga do wierzcholko, z ktorymi nie ma polaczenia ustaw na nieskonczona
  for(int i=0; i<n; i++) {
    if(droga[i]==-1)
      droga[i] = numeric_limits<double>::infinity();
  }
  //cout << "Utworzono :>" << endl;
}

void dijkstra::wyswietl_drogi(double * droga, int n, int start) {
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

void dijkstra::zapisz_do_pliku(fstream & plik, int n, int start) {
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
