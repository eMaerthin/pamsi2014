#include "macierz.h"
#include "lista.h"

lista lista::czytaj_plik(fstream & plik) {
  lista drzewko;
  plik.open("dane.txt", ios::in);
  int x;
  vector<int>tmp;
  cout << endl;
  cout << "[Wczytywanie] ";
  if( plik.good() == true )
    cout << "Uzyskano dostep do pliku :)" << endl;
  else
    cout << "Brak dostepu do pliku :(" << endl;
  do {
  	for(int i=0; i<3; i++) {
  	  plik >> x;
      tmp.push_back(x);
    }
    drzewko.drzewo.push_back(tmp); //Dodaj wektor do drzewa
    tmp.clear();
  } while(!plik.eof());
  plik.close();
  return drzewko;
}

void lista::zapisz_do_pliku(fstream & plik) {
  plik.open("zapisane.txt", ios::out);
  list<vector<int> >::iterator it1;
  vector<int>::iterator it2;
  cout << endl << "[Zapisywanie] ";
  if( plik.good() == true )
    cout << "Uzyskano dostep do pliku :)" << endl << endl;
  else
    cout << "Brak dostepu do pliku :(" << endl << endl;
  for(it1=drzewo.begin(); it1!=drzewo.end(); it1++) {    //Przeszukiwanie drzewa
    for(it2=(*it1).begin(); it2!=(*it1).end(); it2++) {  //Przeszukiwanie wektora
      plik << *it2 << " ";
    }
    plik << "\n";
  }
  plik.close();
}

int znajdz_max(fstream & plik) {
  plik.open("dane.txt", ios::in);
  int x,max;
  cout << endl;
  cout << "[Szukanie maksymalnego indeksu macierzy] ";
  if( plik.good() == true )
    cout << "Uzyskano dostep do pliku :)" << endl;
  else
    cout << "Brak dostepu do pliku :(" << endl;
  max=0;
  do {
    for(int i=0;i<2;i++) {
      plik >> x;
      if(max<x)
        max=x;
    }
    plik >> x;
  } while(!plik.eof());
  plik.close();
  return max+1;
}

macierz macierz::czytaj_plik(fstream & plik, int n) {
  macierz drzewo(n);
  plik.open("dane.txt", ios::in);
  int x[3];
  cout << endl;
  cout << "[Wczytywanie] ";
  if( plik.good() == true )
    cout << "Uzyskano dostep do pliku :)" << endl;
  else
    cout << "Brak dostepu do pliku :(" << endl;
  do {
    for(int i=0; i<3; i++) {
      plik >> x[i];
    }
    drzewo.dodaj(x[0],x[1],x[2]);
  } while(!plik.eof());
  plik.close();
  return drzewo;
}

void macierz::zapisz_do_pliku(fstream & plik) {
  plik.open("zapisane.txt", ios::out);
  cout << endl << "[Zapisywanie] ";
  if( plik.good() == true )
    cout << "Uzyskano dostep do pliku :)" << endl << endl;
  else
    cout << "Brak dostepu do pliku :(" << endl << endl;
  for(int i=0; i<max; i++) {
    for(int j=0; j<max; j++) {
      if(drzewko[i][j]==-1)
        plik << " - ";
      else {
        if(drzewko[i][j]<10)
          plik << " ";
        plik << drzewko[i][j] << " ";
      }
    }
    plik << "\n";
  }
  plik.close();
}
