#include <iostream>
#include <cstdlib> /* rand() */
#include <iomanip> /* setw() */
#include <list> /* lista */
#include <fstream>
#include <limits>

#include "macierz.hh"
#include "lista.hh"
#include "plik.hh"
#include "typ.hh"

using namespace std;

int main ()
{
  /* rand() */
  srand (time(NULL));

  char opcja;
  string nazwa_odczytu, nazwa_zapisu;
  TYP wynik = 0;
  Macierz_graf<TYP> macierz;
  Lista_graf<TYP> lista;
  
  cout << "---------------------------------------------" << endl;
  cout << "| PROGRAM SKOMPILOWANO DLA TYPU: " << NAZWA_TYPU << endl;
  cout << "---------------------------------------------" << endl;

  cout << "Lista 5, Program 5 |zajecia PAMSI| graf." << endl;
  cout << "Algorytm Kruskala i Prima. Minimalne drzewo rozpinajace." << endl;
   
  while(true)
    {
      cout << endl;
      cout << "MENU: " <<endl;
      cout << " Operacje na macierzy:"<<endl;
      cout << "  1.Generowanie grafu."<<endl;
      cout << "  2.Wczytanie grafu z pliku."<<endl;
      cout << "  3.Zapisanie grafu do pliku."<<endl;
      cout << "  4.Wyswietlenie macierzy."<<endl;
      cout << "  5.Algorytm Kruskala dla macierzy."<<endl;
      cout << "  6.Algorytm Prima dla macierzy."<<endl<<endl;
      cout << " Operacje na liscie:"<<endl;
      cout << "  a.Generowanie grafu."<<endl;
      cout << "  b.Wczytanie grafu z pliku."<<endl;
      cout << "  c.Zapisanie grafu do pliku."<<endl;
      cout << "  d.Wyswietlenie listy."<<endl;
      cout << "  k.Algorytm Kruskala dla listy."<<endl;
      cout << "  p.Algorytm Prima dla listy."<<endl<<endl;
      cout << " Twoj wybor (0-6) lub (a,b,c,d,k,p): ";

      cin >> opcja;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
            
      switch(opcja)
	{
	case '0': 
	  {
	    cout<<"Koniec dzialania programu"<<endl;
	    cout<<"_________________________"<<endl;
	  }	  
	  return false;

	case '1': /* generowanie grafu */
	  {
	    int ilosc_wierzcholkow;
	    double gestosc;

	    cout << "Podaj ilosc wierzcholkow: ";
	    cin >> ilosc_wierzcholkow;

	    cout << "Podaj gestosc: ";
	    cin >> gestosc;

	    macierz.zmien_rozmiar(ilosc_wierzcholkow);
	    macierz.generuj_graf(gestosc);
	  }
	  break;

	case '2': /* wczytanie grafu z pliku */
	  {
	    cout << "Do nazwy pliku zostanie dopisane rozszerzenie '.dat'" << endl;
	    cout << "Podaj nazwe pliku do wczytania (bez rozszerzenia): ";
	    cin >> nazwa_odczytu;
	    nazwa_odczytu += ".dat";

	    /* zmiana rozmiaru macierzy, 
	       funkcja znajdz_rozmiar_w_pliku (...) zwraca wartosc, okreslajaca 
	       minimalny niezbedny rozmiar macierzy, ktora nalezy stworzyc aby 
	       bezproblemowo wczytac dane z pliku 

	       zwrocenie wartosci 0 oznacza blad podczas otwierania pliku */
	    int rozmiar = znajdz_rozmiar_w_pliku(nazwa_odczytu);

	    if(rozmiar > 0)
	      {	    
		macierz.zmien_rozmiar(rozmiar);

		/* graf zostaje wypelniony danymi wczytanymi z pliku */
		macierz.wczytaj_z_pliku(nazwa_odczytu);
	      }
	  }
	  break;

	case '3': /* zapisanie grafu do pliku */
	  {
	    cout << "Do nazwy pliku zostanie dopisane rozszerzenie '.dat'" << endl;
	    cout << "Podaj nazwe pliku do ktorego dane beda zapisane (bez rozszerzenia): ";
	    cin >> nazwa_zapisu;
	    nazwa_zapisu += ".dat";

	    macierz.zapisz_do_pliku(nazwa_zapisu);
	  }
	  break;

	case '4': /* wyswietlenie macierzy */
	  {
	    macierz.wyswietl_macierz();
	  }
	  break;
	  
	case '5': /* Algorytm Kruskala */
	  {
	    wynik = macierz.algorytm_Kruskala();
	    cout << "Wartosc MST wedlug Kruskala: " << wynik << endl;
	    
	    cout << "***************************************************"<<endl;
	  }
	  break;

	case '6': /* Algorytm Prima */
	  {
	    wynik = macierz.algorytm_Prima();
	    cout << "Wartosc MST wedlug Prima: " << wynik << endl;

	    cout << "***************************************************"<<endl;
	  }
	  break;

	case 'a': /* generowanie grafu w liscie */
	  {
	    int ilosc_wierzcholkow;
	    double gestosc;

	    cout << "Podaj ilosc wierzcholkow: ";
	    cin >> ilosc_wierzcholkow;

	    cout << "Podaj gestosc: ";
	    cin >> gestosc;

	    lista.zmien_rozmiar(ilosc_wierzcholkow);
	    lista.generuj_graf(gestosc);
	  }
	  break;

	case 'b': /* wczytanie grafu z pliku */
	  {
	    cout << "Do nazwy pliku zostanie dopisane rozszerzenie '.dat'" << endl;
	    cout << "Podaj nazwe pliku do wczytania (bez rozszerzenia): ";
	    cin >> nazwa_odczytu;
	    nazwa_odczytu += ".dat";

	    /* zmiana rozmiaru macierzy, 
	       funkcja znajdz_rozmiar_w_pliku (...) zwraca wartosc, okreslajaca 
	       minimalny niezbedny rozmiar listy, ktora nalezy stworzyc aby 
	       bezproblemowo wczytac dane z pliku 

	       zwrocenie wartosci 0 oznacza blad podczas otwierania pliku */
	    int rozmiar = znajdz_rozmiar_w_pliku(nazwa_odczytu);

	    if(rozmiar > 0)
	      {	    
		lista.zmien_rozmiar(rozmiar);

		/* graf zostaje wypelniony danymi wczytanymi z pliku */
		lista.wczytaj_z_pliku(nazwa_odczytu);
	      }
	  }
	  break;
	  
	case 'c': /* zapisanie grafu do pliku */
	  {
	    cout << "Do nazwy pliku zostanie dopisane rozszerzenie '.dat'" << endl;
	    cout << "Podaj nazwe pliku do ktorego dane beda zapisane (bez rozszerzenia): ";
	    cin >> nazwa_zapisu;
	    nazwa_zapisu += ".dat";
	    
	    lista.zapisz_do_pliku(nazwa_zapisu);
	  }
	  break;

	case 'd':
	  {
	    lista.wyswietl_liste();
	  }
	  break;

	case 'k': /* Algorytm Kruskala */
	  {
	    wynik = lista.algorytm_Kruskala();
	    cout << "Wartosc MST wedlug Kruskala: "<< wynik << endl;
	    
	    cout << "***************************************************"<<endl;
	  }
	  break;

	case 'p': /* Algorytm Prima */
	  {
	    wynik = lista.algorytm_Prima();
	    cout << "Wartosc MST wedlug Prima: "<< wynik << endl;

	    cout << "***************************************************"<<endl;
	  }
	  break;

	default: /* opcja nierozpoznana */
	  cout << "--------------------------------"<<endl;
	  cout << "Nie rozpoznano opcji :'"<<opcja<<"' "<<endl;
	  cout << "Podaj liczbe z zakresu (0-6) lub (a,b,c,d,k,p)"<<endl;
	  cout << "--------------------------------"<<endl;
	} /* end switch */
    } /* end while */
} /* end main */
