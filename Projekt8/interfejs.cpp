#include "interfejs.h"

int interfejs::rozgrywka(int typ) {
  int pozycja[2][2], zla_wspolrzedna, gracz=2, koniec;
  string wspolrzedne[2];
  szachownica gra;
  gra.byl_ruch=1;
  pionek p;
  damka d;
  komputer comp;
  sprawdzenia spr;
  if(typ==1) {
    do {
    cout << endl << " Wybierz poziom trudnosci: "
         << endl << " 1 - latwy"
         << endl << " 2 - sredni"
         << endl << " 3 - trudny"
         << endl << " Twoj wybor: ";
    cin >> gra.trudnosc;
    } while(gra.trudnosc<1 || gra.trudnosc>3);
  }
  cout << endl << " Aby przesunac pionka podaj pozycje poczatkowa i koncowa (np. a6 b5)." << endl
       << " Mozesz rowniez odswiezyc szachownice poslugujac sie formula re." << endl
       << " Zycze milej gry :)" << endl << endl;
  system("PAUSE");
  do {
    if(gra.byl_ruch==1) { //Jesli ostatnio odbyl sie ruch
      //Zmien graczy:
      if(gracz==2)
        gracz=1;
      else
        gracz=2;
      gra.wyswietl_szachownice();
    }
    gra=spr.sprawdz_ruchy(gra,gracz);
    gra=spr.sprawdz_bicia(gra, gracz);  //Sprawdz wszystkie bicia jakie moze wykonac gracz
    if(typ==2 || gracz==1) {
      do {
        zla_wspolrzedna=0;
        do {
          cout << endl << "       Gracz ";
          if(gracz==1)
            cout << "A: ";
          else
            cout << "B: ";
          cin >> wspolrzedne[0]; //Wczytaj pierwsza wspolrzedna
          //Jesli jest to napis o dlugosci 2 zbudowany z 'r' i 'e'
          if(wspolrzedne[0].length()==2 && (int)wspolrzedne[0][0]==114 && (int)wspolrzedne[0][1]==101)
            gra.wyswietl_szachownice(); //"Odswiez" szachownice
          //Jesli odswierzano szachownice
        } while(wspolrzedne[0].length()==2 && (int)wspolrzedne[0][0]==114 && (int)wspolrzedne[0][1]==101);
        cin >> wspolrzedne[1]; //Wczytaj pierwsza wspolrzedna
        for(int i=0; i<2; i++) {
          //Jesli w napisie pierwsza dana to char, a druga to cyfra oraz rozmiar napisu wynosi 2
          if(isalpha(wspolrzedne[i][0]) && isdigit(wspolrzedne[i][1]) && wspolrzedne[i].length()==2) {
            pozycja[i][0]=(int)wspolrzedne[i][1]-49; //Konwertuj char (cyfra) na int
            pozycja[i][1]=(int)wspolrzedne[i][0]-97; //Konwertuj char (literka) na int
            //Jesli wspolrzedne nie mieszcza sie na szachownicy
            if(pozycja[i][0]<0 || pozycja[i][0]>7 || pozycja[i][1]<0 || pozycja[i][1]>7)
              zla_wspolrzedna=1;
          }
          else
            zla_wspolrzedna=1;
        }
        if(zla_wspolrzedna==1)
          cout << "       Bledna wspolrzedna!";
        //Powtarzaj petle do czasu az gracz poda dobre wspolrzedne
      } while(zla_wspolrzedna==1);
      if(gra.pole[pozycja[0][0]][pozycja[0][1]]<=2) //Jesli na pierwszej wspolrzednej jest pionek
        gra=p.ruch(gra, gracz, pozycja[0][0], pozycja[0][1], pozycja[1][0], pozycja[1][1]);
      else //Jesli na pierwszej wspolrzednej jest damka
        gra=d.ruch(gra, gracz, pozycja[0][0], pozycja[0][1], pozycja[1][0], pozycja[1][1]);
      if(gra.byl_ruch==1) //Jesli zostal wykonany ruch
        gra=spr.ukaraj(gra,gracz);  //Ukaraj pionki/damki ktore nie zbily przeciwnika (o ile to mozliwe)
      else
        cout << "       Bledny ruch!";
    }
    else {
      gra=comp.ruch_komputera(gra);
      gra.byl_ruch=1;
    }
    if(gracz==1)
      koniec=spr.czy_sa_pionki(gra,2);
    else
      koniec=spr.czy_sa_pionki(gra,1);
  } while(koniec!=0);
  gra.wyswietl_szachownice();
  return gracz;
}
