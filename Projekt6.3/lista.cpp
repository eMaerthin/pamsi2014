#include "lista.h"

lista::lista(int n) {
  list<vector<int> > graf;
  wierzcholki=n;
}

void lista::dodaj(int pierwszy, int drugi, int waga) {
  vector<int> tmp;
  tmp.push_back(pierwszy);
  tmp.push_back(drugi);
  tmp.push_back(waga);
  graf.push_back(tmp);
  tmp.clear();
}

void lista::wyswietl_liste() {
  cout << endl << "LISTA POLACZEN:" << endl;
  list<vector<int> >::iterator it1;
  vector<int>::iterator it2;
  for(it1=graf.begin(); it1!=graf.end(); it1++) {
    for(it2=(*it1).begin(); it2!=(*it1).end(); it2++) {
      if(*it2<10)
        cout << " ";
      cout << *it2 << " ";
    }
    cout << endl;
  }
}

void lista::wyswietl_parametry() {
  cout << endl << "Liczba krawedzi: " << krawedzie << " "
       << endl << "Liczba wierzcholkow: " << wierzcholki << " "
       << endl << "Wierzcholek startowy: " << start << endl;
}
