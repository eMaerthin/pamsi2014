#include "pionek.h"

szachownica pionek::ruch(szachownica dane, int gracz, int x1, int y1, int x2, int y2) {
  dane.byl_ruch=1;
  //Jesli na pierwszej pozycji jest pionek i druga pozycja jest wolna
  if(dane.pole[x1][y1]==gracz && dane.pole[x2][y2]==0) {
    //Jesli jest to zwykly ruch
    if((y2-y1==1 || y2-y1==-1) && ((gracz==1 && (x2-x1)==-1) || (gracz==2 && (x2-x1)==1)))
      dane=idz(dane,gracz,x1,y1,x2,y2); //Idz do przodu
    else {
      dane=zbijaj(dane,gracz,x1,y1,x2,y2); //Zbijaj (o ile to mozliwe)
    }
  }
  else
    dane.byl_ruch=0; //Nie wykonano ruchu
  return dane;
}

szachownica pionek::idz(szachownica dane, int gracz, int x1, int y1, int x2, int y2) {
  pair<int,int> zapisz;
  dane.pole[x1][y1]=0;  //Zwolnij poczatkowa pozycje
  if((gracz==1 && x2!=0) || (gracz==2 && x2!=7)) //Jesli pionek nie doszedl do konca szachownicy
    dane.pole[x2][y2]=gracz;  //Zajmij druga pozycje
  else  //Jesli doszedl
    dane.pole[x2][y2]=gracz+2; //Zajmij druga pozycje i zamien pionka na damke
  zapisz.first=x1; zapisz.second=y1; //Zapisz ostatni ruch (do wyswietlania "o")
  dane.przejscia.push_back(zapisz); //Dodaj ten ruch do listy ruchow
  dane.ostatni.first=x2; dane.ostatni.second=y2; //Zapisz pozycje pionka wykonujacego ruch
  return dane;
}

szachownica pionek::zbijaj(szachownica dane, int gracz, int x1, int y1, int x2, int y2) {
  list<list<pair<int,int> > > sciezki; //Lista sciezek zawierajacej kolejne zbicia
  list<pair<int,int> > lista_bic; //Sciezka zawierajacej kolejne zbicia
  pair<int,int> bicie,zbity;
  list<list<pair<int,int> > >::iterator it1;
  list<pair<int,int> >::iterator it2,it3;
  int przeciwnik,bylo_bicie,dodac,licz=0,i;
  //Kierunki poruszania sie:
  int x[4]={1,1,-1,-1};
  int y[4]={-1,1,1,-1};
  //Zapisz jak oznaczone sa pionki przeciwnika:
  if(gracz==1)
    przeciwnik=gracz+1;
  else
    przeciwnik=gracz-1;
  bicie.first=x1; bicie.second=y1; //Zapisz pozycje poczatkowa
  lista_bic.push_back(bicie); //Dodaj ja do sciezki
  sciezki.push_back(lista_bic); //Dodaj sciezke do listy sciezek zawierajacej kolejne zbicia
  do {
    for(it1=sciezki.begin(); it1!=sciezki.end(); it1++) { //Przeszukaj liste sciezek
      bylo_bicie=0;
      it2=(*it1).end(); //Wez ostatnia pozycje pionka zbijajacego
      it2--;
      for(i=0; i<4; i++) {
        //Jesli na polu obok jest przeciwnik (pionek lub damka) i czy pole za przeciwnikiem jest wolne
        if((dane.pole[(*it2).first+x[i]][(*it2).second+y[i]]==przeciwnik
            || dane.pole[(*it2).first+x[i]][(*it2).second+y[i]]==przeciwnik+2)
            && dane.pole[(*it2).first+(x[i]*2)][(*it2).second+(y[i]*2)]==0) {
          bicie.first=(*it2).first+(x[i]*2); bicie.second=(*it2).second+(y[i]*2); //Zapisz pole po zbiciu
          zbity.first=(*it2).first+x[i]; zbity.second=(*it2).second+y[i]; //Zapisz zbitego przeciwnika
          if(bicie.first==x2 && bicie.second==y2) { //Jesli pole po zbiciu jest takie jak pole koncowe
            for(it3=(*it1).begin(); it3!=(*it1).end(); it3++) {
              dane.pole[(*it3).first][(*it3).second]=0; //Usun przeciwnikow
              //Zapisz przejscia pionka zbijajacego i pozycje zbitych przeciwnikow
              //(do wyswietlania "o" i "X"):
              bicie.first=(*it3).first; bicie.second=(*it3).second;
              if(licz==0) {
                dane.przejscia.push_back(bicie);
                licz++;
              }
              else {
                dane.zbicia.push_back(bicie);
                licz--;
              }
            }
            dane.pole[zbity.first][zbity.second]=0; //Usun ostatniego przeciwnika
            bicie.first=zbity.first; bicie.second=zbity.second; //Zapisz pozycje zbitego przeciwnika
            dane.zbicia.push_back(bicie);
            if((gracz==1 && x2!=0) || (gracz==2 && x2!=7)) //Jesli pionek nie doszedl do konca szachownicy
              dane.pole[x2][y2]=gracz; //Zajmij miejsce za zbitym przeciwnikiem
            else //Jesli doszedl
              dane.pole[x2][y2]=gracz+2; //Zajmij miejsce za zbitym przeciwnikiem i zamien pionka na damke
            dane.ostatni.first=x2; dane.ostatni.second=y2; //Zapisz pozycje pionka wykonujacego ruch
            return dane;
          }
          dodac=1; //Znaleziono bicie
          for(it3=(*it1).begin(); it3!=(*it1).end(); it3++) { //Przeszukaj sciezke bic
            if((*it3).first==bicie.first && (*it3).second==bicie.second) {  //Jesli dane bicie juz jest na liscie bic
              dodac=0; //Nie dodawaj do listy bic
              break;
            }
          }
          if(dodac==1) {
            lista_bic.push_back(zbity); //Dodaj zbitego przeciwnika do listy
            lista_bic.push_back(bicie); //Dodaj wolne pole po zbiciu do listy
            sciezki.push_back(lista_bic); //Dodaj liste bic do listy sciezek
            bylo_bicie=1;
          }
        }
      }
    }
  } while(bylo_bicie!=0); //Jesli wykonane bylo bicie
  dane.byl_ruch=0; //Nie wykonano ruchu
  return dane;
}
