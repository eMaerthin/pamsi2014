//autor: Marcin Ochocki 200330
//Kompilacja w standardzie C++0x ISO C++
//Testowanie algorytmow wyznaczania najkrotszych sciezek w grafie:
//Dijkstry i Bellmana-Forda dla reprezentacji macierzowej i listowej

//#include "obsluga_plikow.h"
#include "obsluga_plikow.cpp"
//#include "generatory.h"
#include "generatory.cpp"
#include "spojnosc.h"
#include "dijkstra.h"
#include "bellman_ford.h"
#include <boost/timer.hpp>

fstream plik;

int main() {

  //Zmienne dla reprezentacji macierzowej:
  obsluga_plikow <macierz> op_m;
  generator <macierz> g_m;

  //Zmienne dla reprezentacji listowej:
  obsluga_plikow <lista> op_l;
  generator <lista> g_l;

  sprawdzanie_spojnosci s_s;
  dijkstra d;
  bellman_ford bf;

  int opcja, opcja1, n, algorytm, reprezentacja, wyswietl, powtorzenia, licz=0, licz2=0, czy_ujemny=1;
  double p;
  float czas[3];
  boost::timer time;
  do {
    cout << endl << "Jaki algorytm chcesz przetestowac?" << endl
         << "0 - Dijkstry" << endl
         << "1 - Bellmana-Forda" << endl
         << "Twoj wybor: ";
    cin >> algorytm;
  } while(algorytm!=0 && algorytm!=1);
  cout << endl << "Skad chcesz wziac parametry grafu?" << endl
	   << "0 - z pliku" << endl
	   << "1 - wygenerowany losowo" << endl
	   << "Twoj wybor: ";
  cin >> opcja1;
  if(opcja1==0) {
    n=op_l.znajdz_max(plik);
  }
  if(opcja1==1) {
    cout << endl << "Ile ma byc wierzcholkow w grafie?" << endl
  	   << "0 - 50" << endl
  	   << "1 - 100" << endl
  	   << "2 - 200" << endl
  	   << "3 - 400" << endl
  	   << "Twoj wybor: ";
    cin >> opcja;

    switch(opcja) {
      case 0: n=50; break;
      case 1: n=100; break;
      case 2: n=200; break;
      case 3: n=400; break;
      default: return 0;
    }
    cout << endl << "Jakie ma byc prawdopodobienstwo polaczenia?" << endl
  	   << "0 - 0.25" << endl
  	   << "1 - 0.5" << endl
  	   << "2 - 0.75" << endl
  	   << "3 - 1.0" << endl
  	   << "Twoj wybor: ";
    cin >> opcja;

    switch(opcja) {
      case 0:
      p=0.25;
      break;

      case 1:
      p=0.5;
      break;

      case 2:
      p=0.75;
      break;

      case 3:
      p=1;
      break;

      default:
      return 0;
    }
  }
  if(opcja1!=0 && opcja1!=1)
    return 0;
  macierz m(n); //Konstruktor macierzy
  lista l(n);   //Konstruktor listy
  cout << endl << "Jakiej reprezentacji grafu chcesz uzyc?: " << endl
       << "0 - macierzowa" << endl
       << "1 - listowa" << endl
       << "Twoj wybor: ";
  cin >> reprezentacja;
  if(reprezentacja!=0 && reprezentacja!=1)
    return 0;

  if(opcja1==1) {
    cout << endl << "Wybierz wierzcholek startowy z zakresu "
        << "0 - " << n-1 << ": ";
    if(reprezentacja==0) {
      cin >> m.start;
      while (m.start<0 || m.start>n-1) {
        cout << "Podaj wierzcholek z podanego zakresu!: ";
        cin >> m.start;
      }
    }
    else {
      cin >> l.start;
      while (l.start<0 || l.start>n-1) {
        cout << "Podaj wierzcholek z podanego zakresu!: ";
        cin >> l.start;
      }
    }
  }
  cout << endl << "Ile mam wykonac powtorzen?: ";
  cin >> powtorzenia;

  while (powtorzenia<1) {
    cout << "Podaj wartosc wieksza od zera!: ";
    cin >> powtorzenia;
  }

  do {
    cout << endl << "Mam wyswietlac wyniki (macierz/lista, drogi)?: "
         << endl << "0 - NIE"
         << endl << "1 - TAK"
         << endl << "Twoj wybor: ";
    cin >> wyswietl;
  } while(wyswietl!=0 && wyswietl!=1);

  while(licz<powtorzenia) {
    if(opcja1==0 && czy_ujemny==1) {
      if(reprezentacja==0) {
        m=op_m.czytaj_plik(plik,n);
        if(wyswietl==1) {
          m.wyswietl_parametry();
          m.wyswietl_macierz();
        }
      }
      else {
        l=op_l.czytaj_plik(plik,n);
        if(wyswietl==1) {
          l.wyswietl_parametry();
          l.wyswietl_liste();
        }
      }
    }
    if(opcja1==0 && czy_ujemny==2) {
      cout << endl << "W podanym pliku znajduje sie cykl ujemny"
           << endl << "Nic nie moge z tym zrobic :<" << endl;
      system ("PAUSE");
      return 0;
    }
    if(opcja1==1) {
      if(reprezentacja==0) {
        m=g_m.generuj(n,p,m.start,algorytm);
        if(wyswietl==1)
          m.wyswietl_parametry();
      }
      else {
        l=g_l.generuj(n,p,l.start,algorytm);
        if(wyswietl==1)
          l.wyswietl_parametry();
      }
    }
    if(reprezentacja==0)
      s_s.sprawdz_spojnosc(m,n,m.start);
    else
      s_s.sprawdz_spojnosc(l,n,l.start);

    licz++;
    czas[0]=time.elapsed();

    if(reprezentacja==0) {
      if(algorytm==0)
        d.znajdz_drogi(m,n);
      else {
        czy_ujemny=bf.znajdz_drogi(m,n);
        licz2++;
      }
    }

    else {
      if(algorytm==0)
        d.znajdz_drogi(l,n);
      else {
        czy_ujemny=bf.znajdz_drogi(l,n);
        licz2++;
      }
    }

    if(czy_ujemny==1) {
      czas[1]=time.elapsed()-czas[0]+czas[1];
      czas[2]=czas[1];
    }

    if(reprezentacja==0 && wyswietl==1 && czy_ujemny==1) {
      if(algorytm==0)
        d.wyswietl_drogi(d.droga, n, m.start);
      else
        bf.wyswietl_drogi(bf.droga, n, m.start);
    }
    if(reprezentacja==1 && wyswietl==1 && czy_ujemny==1) {
      if(algorytm==0)
        d.wyswietl_drogi(d.droga, n, l.start);
      else
        bf.wyswietl_drogi(bf.droga, n, l.start);
    }
    if(czy_ujemny==2)
      licz--;
  }
  if(reprezentacja==0) {
    if(algorytm==0)
      d.zapisz_do_pliku(plik, n, m.start);
    else {
      bf.zapisz_do_pliku(plik, n, m.start);
      cout << endl << "W " << licz2 << " losowaniach wystapilo "
           << (((double)licz2-(double)licz)/(double)licz2)*100 << "% cykli ujemnych" << endl;
    }
  }
  else {
    if(algorytm==0)
      d.zapisz_do_pliku(plik, n, l.start);
    else {
      bf.zapisz_do_pliku(plik, n, l.start);
      cout << endl << "W " << licz2 << " losowaniach wystapilo "
           << (((double)licz2-(double)licz)/(double)licz2)*100 << "% cykli ujemnych" << endl;
    }
  }
  cout << endl << "Sredni czas trwania algorytmu: " << czas[1]/licz << "s" << endl << endl;
  system ("PAUSE");
  return 0;
}
