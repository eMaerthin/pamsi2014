//autor: Marcin Ochocki 200330
//Kompilacja w standardzie C++0x ISO C++
//Testowanie algorytmow Prima i Kruskala dla reprezentacji macierzowej

#include "generatory.h"
#include "spojnosc.h"
#include "kruskal.h"
#include "prim.h"
#include <boost/timer.hpp>

fstream plik;

int main() {
  generator_macierzy g_m;
  spojnosc_macierzy s_m;
  kruskal_macierz k_m;
  prim_macierz p_m;

  int opcja, opcja1, algorytm, n, czy_spojny, powtorzenia, licz=0,
  waga_poczatkowa, waga_koncowa, poprzednia_waga[2];
  poprzednia_waga[0]=0; poprzednia_waga[1]=0;
  float p, czas[3], gestosc[2];
  czas[2]=0;
  gestosc[0]=0;
  boost::timer time;
  cout << endl << "Skad chcesz wziac parametry grafu?" << endl
	   << "0 - z pliku" << endl
	   << "1 - wygenerowany losowo" << endl
	   << "Twoj wybor: ";
  cin >> opcja1;
  if(opcja1==0) {
    n=znajdz_max(plik);
  }
  if(opcja1==1) {
    cout << endl << "Ile ma byc wierzcholkow w grafie?" << endl
  	   << "0 - 500" << endl
  	   << "1 - 1000" << endl
  	   << "2 - 1500" << endl
  	   << "3 - 2000" << endl
  	   << "Twoj wybor: ";
    cin >> opcja;

    switch(opcja) {
      case 0: n=500; break;
      case 1: n=1000; break;
      case 2: n=1500; break;
      case 3: n=2000; break;
      default: return 0;
    }
    cout << endl << "Jakie ma byc prawdopodobienstwo p?" << endl
  	   << "0 - [3log2(n)]/n" << endl
  	   << "1 - n^(-1/3)" << endl
  	   << "2 - graf pelny" << endl
  	   << "Twoj wybor: ";
    cin >> opcja;

    switch(opcja) {
      case 0:
      p=(3*(log((float)n))/(log(2)))/(float)n;
      cout << endl << "p = "<< p << endl;
      break;

      case 1:
      p=pow((float)n, -1/3.f);
      cout << endl << "p = "<< p << endl;
      break;

      case 2:
      break;

      default:
      return 0;
    }
  }
  if(opcja1!=0 && opcja1!=1)
    return 0;

  macierz m(n);

  cout << endl << "Jakiego algorytm chcesz uzyc?" << endl
       << "0 - Kruskala" << endl
  	   << "1 - Prima" << endl
  	   << "Twoj wybor: ";
  cin >> algorytm;

  switch(algorytm) {
    case 0:
    algorytm=0;
    break;

    case 1:
    algorytm=1;
    break;

    default:
    return 0;
  }

  cout << endl << "Ile mam wykonac powtorzen?: ";
  cin >> powtorzenia;
  while(licz<powtorzenia) {
    if(opcja1==0) {
      m=m.czytaj_plik(plik,n);
    }
    if(opcja1==1) {
      if(opcja==0 || opcja==1) {
        m=g_m.graf_er(n,p);
      }
      else {
        m=g_m.graf_pelny(n);
      }
    }
    czy_spojny=s_m.sprawdz_spojnosc(m,n);
    if(czy_spojny==1) {
      licz++;
      gestosc[1]=m.gestosc+gestosc[0];
      gestosc[0]=gestosc[1];
      waga_poczatkowa=m.suma_wag()+poprzednia_waga[0];
      poprzednia_waga[0]=waga_poczatkowa;
      czas[0]=time.elapsed();
      if(algorytm==0)
        m=k_m.stworz_min(m,n);
      else
        m=p_m.stworz_min(m,n);
      czas[1]=time.elapsed()-czas[0]+czas[2];
      czas[2]=czas[1];
      waga_koncowa=m.suma_wag()+poprzednia_waga[1];
      poprzednia_waga[1]=waga_koncowa;
    }
  }
  czas[1]=czas[1]/licz;
  gestosc[1]=gestosc[1]/licz;
  waga_poczatkowa=waga_poczatkowa/licz;
  waga_koncowa=waga_koncowa/licz;
  cout << endl << "Srednia gestosc grafu: " << gestosc[1] << endl;
  cout << endl << "Srednia waga poczatkowa: " << waga_poczatkowa << endl;
  cout << endl << "Srednia waga koncowa: " << waga_koncowa << endl;
  cout << endl << "Czas wykonania algorytmu: " << czas[1] << "s" << endl;
  system ("PAUSE");
  return 0;
}
