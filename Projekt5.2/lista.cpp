#include "lista.h"

void lista::dodaj(int pierwszy, int drugi, int waga) {
  vector<int> tmp;
  tmp.push_back(pierwszy);
  tmp.push_back(drugi);
  tmp.push_back(waga);
  drzewo.push_back(tmp);
  tmp.clear();
}

int lista::suma_wag() {
  int suma=0;
  list<vector<int> >::iterator it1;
  vector<int>::iterator it2;
  for(it1=drzewo.begin(); it1!=drzewo.end(); it1++) {
    it2=(*it1).end();
    it2--;
    suma=suma+(*it2);
  }
  return suma;
}

void lista::wyswietl_liste() {
  cout << endl << "LISTA POLACZEN:" << endl;
  list<vector<int> >::iterator it1;
  vector<int>::iterator it2;
  for(it1=drzewo.begin(); it1!=drzewo.end(); it1++) {
    for(it2=(*it1).begin(); it2!=(*it1).end(); it2++) {
      if(*it2<10)
        cout << " ";
      cout << *it2 << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void lista::sortuj_wagi() {
  drzewo.sort([](const vector<int> & a, const vector <int> & b) { return a.back() < b.back(); });
}
