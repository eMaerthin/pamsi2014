#include "spojnosc.h"

void sprawdzanie_spojnosci::sortuj_sasiadow(list<int> & tmp) {
  tmp.sort([](const int & a, const int & b) { return a > b; });
}

int sprawdzanie_spojnosci::sprawdz_spojnosc(macierz dane, int n, int start) {
  //cout << endl << "[Sprawdzanie spojnosci grafu...] ";
  list<int> odwiedzone, sasiedzi, tmp;
  list<int>::iterator it, it2;
  int x=start, pusty=0, znaleziono, czy_spojny;
  do {
    odwiedzone.push_back(x);
    for(int i=0; i<n; i++) {
      if(dane.graf[x][i]!=-1) {
        znaleziono=0;
        for(it=odwiedzone.begin(); it!=odwiedzone.end(); it++) {
          if(i==(*it)) {
            znaleziono=1;
            break;
          }
        }
        if(znaleziono==0) {
          for(it=sasiedzi.begin(); it!=sasiedzi.end(); it++) {
            if(i==(*it)) {
              znaleziono=1;
              break;
            }
          }
          if(znaleziono==0)
            tmp.push_back(i);
        }
      }
    }
    sortuj_sasiadow(tmp);
    sasiedzi.splice(sasiedzi.end(), tmp);
    do {
      znaleziono=0;
      it=sasiedzi.end();
      it--;
      x=*it;
       for(it2=odwiedzone.begin(); it2!=odwiedzone.end(); it2++) {
        if(x==(*it2)) {
          znaleziono=1;
          break;
        }
      }
      if(sasiedzi.size()!=0) {
        sasiedzi.erase(it);
        pusty=0;
      }
      else
        pusty=1;
    } while(znaleziono!=0);
  } while(pusty!=1);
  if(odwiedzone.size()==n) {
    //cout << "Graf jest spojny :)" << endl;
    odwiedzone.clear();
    czy_spojny=1;
  }
  else {
    /*cout << "Graf jest niespojny :(" << endl
         << "Liczba wierzcholkow, z ktorymi nie ma polaczenia: "
         << n-odwiedzone.size() << endl;*/
    odwiedzone.clear();
    czy_spojny=2;
  }
  return czy_spojny;
}

int sprawdzanie_spojnosci::sprawdz_spojnosc(lista dane, int n, int start) {
  //cout << endl << "[Sprawdzanie spojnosci grafu...] ";
  list<int> odwiedzone, sasiedzi, tmp;
  list<vector<int> >::iterator it_l;
  vector<int>::iterator it_v;
  list<int>::iterator it, it2;
  int x=start, pusty=0, znaleziono, znaleziono_sasiada, czy_spojny;
  do {
    odwiedzone.push_back(x);
    for(it_l=dane.graf.begin(); it_l!=dane.graf.end(); it_l++) {
      it_v=(*it_l).begin();
      znaleziono_sasiada=0;
      znaleziono=0;
      if(x==(*it_v)) {
        it_v++;
        znaleziono_sasiada=1;
      }
      if(znaleziono_sasiada==1) {
        for(it=odwiedzone.begin(); it!=odwiedzone.end(); it++) {
          if((*it_v)==(*it)) {
            znaleziono=1;
            break;
          }
        }
        if(znaleziono==0) {
          for(it=sasiedzi.begin(); it!=sasiedzi.end(); it++) {
            if((*it_v)==(*it)) {
              znaleziono=1;
              break;
            }
          }
          if(znaleziono==0)
            tmp.push_back(*it_v);
        }
      }
    }
    sortuj_sasiadow(tmp);
    sasiedzi.splice(sasiedzi.end(), tmp);
    do {
      znaleziono=0;
      it=sasiedzi.end();
      it--;
      x=*it;
       for(it2=odwiedzone.begin(); it2!=odwiedzone.end(); it2++) {
        if(x==(*it2)) {
          znaleziono=1;
          break;
        }
      }
      if(sasiedzi.size()!=0) {
        sasiedzi.erase(it);
        pusty=0;
      }
      else
        pusty=1;
    } while(znaleziono!=0);
  } while(pusty!=1);
  if(odwiedzone.size()==n) {
    //cout << "Graf jest spojny :)" << endl;
    odwiedzone.clear();
    czy_spojny=1;
  }
  else {
    /*cout << "Graf jest niespojny :(" << endl
         << "Liczba wierzcholkow, z ktorymi nie ma polaczenia: "
         << n-odwiedzone.size() << endl;*/
    odwiedzone.clear();
    czy_spojny=2;
  }
  return czy_spojny;
}
