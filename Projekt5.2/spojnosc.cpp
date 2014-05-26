#include "spojnosc.h"

void sortuj_sasiadow(list<int> & tmp) {
  tmp.sort([](const int & a, const int & b) { return a > b; });
}

int spojnosc_macierzy::sprawdz_spojnosc(macierz dane, int n) {
  cout << endl << "[Sprawdzanie spojnosci grafu...] ";
  list<int> odwiedzone, sasiedzi, tmp;
  list<int>::iterator it, it2;
  int x=0, pusty=0, znaleziono, czy_spojny;
  do {
    odwiedzone.push_back(x);
    for(int i=0; i<n; i++) {
      if(dane.drzewko[x][i]!=-1) {
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
      //cout << odwiedzone.size() << " " << sasiedzi.size() << endl;
    } while(znaleziono!=0);
  } while(pusty!=1);
  if(odwiedzone.size()==n) {
    cout << "Graf jest spojny :)" << endl;
    odwiedzone.clear();
    czy_spojny=1;
  }
  else {
    cout << "Graf jest niespojny :(" << endl;
    odwiedzone.clear();
    czy_spojny=2;
  }
  return czy_spojny;
}

int spojnosc_listy::sprawdz_spojnosc(lista dane, int n) {
  cout << endl << "[Sprawdzanie spojnosci grafu...] ";
  list<int> odwiedzone, sasiedzi, tmp;
  list<vector<int> >::iterator it_l;
  vector<int>::iterator it_v;
  list<int>::iterator it, it2;
  int x=0, pusty=0, znaleziono, znaleziono_sasiada, i, czy_spojny;
  do {
    odwiedzone.push_back(x);
    for(it_l=dane.drzewo.begin(); it_l!=dane.drzewo.end(); it_l++) {
      for(it_v=(*it_l).begin(), i=0; i<2; it_v++, i++) {
        znaleziono_sasiada=0;
        znaleziono=0;
        if(x==(*it_v)) {
          if(i==0);
            it_v++;
          if(i==1) {
            it_v--;
            it_v--;
          }
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
      //cout << odwiedzone.size() << " " << sasiedzi.size() << endl;
    } while(znaleziono!=0);
  } while(pusty!=1);
  if(odwiedzone.size()==n) {
    cout << "Graf jest spojny :)" << endl;
    odwiedzone.clear();
    czy_spojny=1;
  }
  else {
    cout << "Graf jest niespojny :(" << endl;
    odwiedzone.clear();
    czy_spojny=2;
  }
  return czy_spojny;
}
