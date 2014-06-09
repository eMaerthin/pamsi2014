//autor: Marcin Ochocki 200330
//Kompilacja w standardzie C++0x ISO C++
//Testowanie algorytmu wyznaczania maksymalnego przeplywu w sieci przeplywowej:
//Edmondsa-Karpa na podstawie metody Forda-Fulkersona.
//Interfejs umozliwia wczytywanie danych z zadanych plikow o rozszerzeniu .txt

#include <iostream>
#include <boost/timer.hpp>
#include "obsluga_plikow.h"
#include "edmonds_karp.h"

int main() {
  fstream plik;
  int n, licz=0, powtorzenia=0, otwarto=0, fkrawedzie;
  float czas[3];
  czas[0]=0; czas[1]=0; czas[2]=0;
  boost::timer time;
  string nazwa;
  cout << "Podaj nazwe pliku: ";
  while(otwarto==0) {
    cin >> nazwa;
    plik.open(nazwa, ios::in);
    if( plik.good() == true ) {
      cout << "Uzyskano dostep do pliku :)" << endl;
      otwarto=1;
    }
    else
      cout << "Nie ma takiego pliku, podaj jeszcze raz: ";
  }
  plik >> n;
  plik.close();
  do {
    cout << "Ile mam wykonac powtorzen?: ";
    cin >> powtorzenia;
  } while(powtorzenia<1);
  obsluga_plikow op;
  edmonds_karp ek;
  siec s(n);
  while(licz<powtorzenia) {
    cout << licz;
    licz++;
    s=op.czytaj_plik(plik,nazwa,n);
    //s.wyswietl_parametry();
    //s.wyswietl_siec_lista();
    czas[0]=time.elapsed();
    s=ek.wyznacz_fmax(s);
    czas[1]=time.elapsed()-czas[0]+czas[2];
    czas[2]=czas[1];
    //s.wyswietl_siec_lista();
  }
  fkrawedzie=s.licz_fkrawedzie();
  cout << endl << "Maksymalny przeplyw: " << s.fmax << endl;
  cout << endl << "Liczba krawedzi: " << fkrawedzie << endl;
  cout << endl << "Sredni czas trwania algorytmu: " << czas[2]/(float)licz << "s" << endl;
  return 0;
}
