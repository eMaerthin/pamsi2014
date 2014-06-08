#include "edmonds_karp.h"

void edmonds_karp::sortuj_liste(list<int> & tmp) {
  tmp.sort([](const int & a, const int & b) { return a < b; });
}

void edmonds_karp::bfs(siec dane) {
  list<int> odwiedzone, sasiedzi, tmp, przejscia[dane.wierzcholki];
  list<int>::iterator it;
  int x=dane.zrodlo, znaleziono, znaleziono_ujscie=0, i;
  polaczenia.clear();
  //Ustaw zrodlo jako poczatek w kazdej sciezce do kazdego wierzcholka
  for(i=0; i<dane.wierzcholki; i++)
    przejscia[i].push_back(dane.zrodlo);
  do {
    odwiedzone.push_back(x); //Odwiedzenie wierzcholka
    for(i=0; i<dane.wierzcholki; i++) {
      //Jesli jest dana w sieci pierwotnej oraz przepustowosc w sieci przeplywowej nie wynosi 0
      if(dane.macierz[x][i][0]!=-1 && dane.macierz[x][i][0]!=0) {
        if(i==dane.ujscie) { //Jesli znaleziono ujscie
          znaleziono_ujscie=1;
          przejscia[i]=przejscia[x];  //Kopiuj ciag wierzcholkow
          przejscia[i].push_back(i);  //Dodaj ujscie do ciagu wierzcholkow
          break;
        }
        znaleziono=0;
        for(it=odwiedzone.begin(); it!=odwiedzone.end(); it++) {
          if(i==(*it)) { //Jesli wierzcholek juz byl odwiedzony
            znaleziono=1;
            break;
          }
        }
        if(znaleziono==0) {
          for(it=sasiedzi.begin(); it!=sasiedzi.end(); it++) {
            if(i==(*it)) { //Jesli wierzcholek juz jest w liscie sasiadow
              znaleziono=1;
              break;
            }
          }
          if(znaleziono==0) { //Jesli nie znaleziono wierzcholka w zadnej liscie
            tmp.push_back(i); //Dodaj wierzcholek do tymczasowej listy
            przejscia[i]=przejscia[x];  //Kopiuj ciag wierzcholkow
            przejscia[i].push_back(i);  //Dodaj wierzcholek do ciagu wierzcholkow
          }
        }
      }
      if(znaleziono_ujscie==1) {
        break;
      }
    }
    if(znaleziono_ujscie==1 || (x==dane.zrodlo && tmp.size()==0)) {
      break;
    }
    sasiedzi.splice(sasiedzi.end(), tmp); //Polacz liste tymczasowa z lista sasiadow
    sortuj_liste(sasiedzi); //Sortuj liste sasiadow
    it=sasiedzi.begin();    //Odczytaj adres pierwszego wierzcholka z listy sasiadow
    if(sasiedzi.size()==0)  //Jesli lista sasiadow jest pusta
      break;
    x=(*it);
    sasiedzi.erase(it); //Usun pobrany wierzcholek z listy
  } while(x!=dane.ujscie);  //Jesli nie znaleziono ujscia
  polaczenia=przejscia[dane.ujscie];  //Kopiuj ciag wierzcholkow ze zrodla do ujscia
  for(i=0; i<dane.wierzcholki; i++)
    przejscia[i].clear(); //Wyczysc wszystkie listy przejsc
}

int edmonds_karp::wyznacz_przepustowosc(siec dane) {
  list<int>::iterator it;
  int przepustowosc=9999, poczatek;
  it=polaczenia.begin(); //Wez pierwszy wierzcholek z listy przejsc
  do {
    poczatek=(*it);
    it++;
    if(dane.macierz[poczatek][*it][0] < przepustowosc) //Jesli znaleziono mniejsza przepustowosc
      przepustowosc=dane.macierz[poczatek][*it][0];
  } while((*it)!=dane.ujscie); //Jesli nie doszlo do ujscia
  return przepustowosc;
}

void edmonds_karp::zmniejsz_przepustowosc(siec dane, int przepustowosc) {
  list<int>::iterator it;
  int poczatek;
  it=polaczenia.begin(); //Wez pierwszy wierzcholek z listy przejsc
  do {
    poczatek=(*it);
    it++;
    dane.macierz[poczatek][*it][1]=dane.macierz[poczatek][*it][1]+przepustowosc; //Zwieksz przeplyw w sieci przeplywowej
    dane.macierz[poczatek][*it][0]=dane.macierz[poczatek][*it][0]-przepustowosc; //Zmniejsz przeplyw w sieci pierwotnej
  } while((*it)!=dane.ujscie); //Jesli nie doszlo do ujscia
}

siec edmonds_karp::wyznacz_fmax(siec dane) {
  list<int>::iterator it;
  int przepustowosc;
  dane.fmax=0;
  do {
    bfs(dane); //Szukaj sciezki rozszerzajacej ze zrodla do ujscia
    if(polaczenia.size()==1) //Jesli nie znaleziono sciezki rozszerzajacej
      break;
    przepustowosc=wyznacz_przepustowosc(dane);  //Wyznaczenie maksymalnej przepustowosci w sciezce
    dane.fmax=dane.fmax+przepustowosc;  //Zwiekszenie przeplywu o wartosc przepustowosci
    zmniejsz_przepustowosc(dane, przepustowosc);
  } while(polaczenia.size()!=1); //Jesli znaleziono sciezke rozszerzajaca
  return dane;
}
