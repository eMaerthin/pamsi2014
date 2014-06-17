#include "damka.h"

szachownica damka::ruch(szachownica dane, int gracz, int x1, int y1, int x2, int y2) {
  dane.byl_ruch=1;
  //Jesli na pierwszej pozycji jest damka i druga pozycja jest wolna
  if(dane.pole[x1][y1]==gracz+2 && dane.pole[x2][y2]==0) {
    if(abs(y2-y1)==abs(x2-x1)) //Jesli ruch odbywa sie po kwadracie
      dane=idz(dane,gracz,x1,y1,x2,y2); //Idz do przodu (moze sie zmienic na bicie)
    else
      dane=zbijaj(dane,gracz,x1,y1,x2,y2); //Zbijaj (o ile to mozliwe)
  }
  else
    dane.byl_ruch=0; //Nie wykonano ruchu
  return dane;
}

szachownica damka::idz(szachownica dane, int gracz, int x1, int y1, int x2, int y2) {
  pair<int,int> zapisz;
  int przeciwnik, spotkano_przeciwnika=0,kierunek;
  //Zapisz jak oznaczone sa pionki przeciwnika:
  if(gracz==1)
    przeciwnik=gracz+1;
  else
    przeciwnik=gracz-1;
  //Kierunki poruszania sie:
  int x[4]={1,1,-1,-1};
  int y[4]={-1,1,1,-1};
  if(x2-x1>0 && y2-y1<0) {
    kierunek=0;
  }
  if(x2-x1>0 && y2-y1>0) {
    kierunek=1;
  }
  if(x2-x1<0 && y2-y1>0) {
    kierunek=2;
  }
  if(x2-x1<0 && y2-y1<0) {
    kierunek=3;
  }
  for(int i=1; i<abs(x2-x1); i++) { //Wykonuj kroki az do osiagniecia pozycji koncowej
    //Jesli spotkano przeciwnika
    if(dane.pole[x1+(i*x[kierunek])][y1+(i*y[kierunek])]==przeciwnik ||
       dane.pole[x1+(i*x[kierunek])][y1+(i*y[kierunek])]==przeciwnik+2) {
      spotkano_przeciwnika=1;
      //Jesli pole za przeciwnikiem jest puste
      if(dane.pole[x1+(i*x[kierunek])+x[kierunek]][y1+(i*y[kierunek])+y[kierunek]]==0)
        dane=zbijaj(dane,gracz,x1,y1,x2,y2); //Zbijaj
      else
        dane.byl_ruch=0; //Nie wykonano ruchu
      break;
    }
  }
  if(spotkano_przeciwnika==0) { //Jesli nie spotkano przeciwnika
    dane.pole[x1][y1]=0; //Zwolnij poczatkowa pozycje
    dane.pole[x2][y2]=gracz+2; //Zajmij druga pozycje
    zapisz.first=x1; zapisz.second=y1; //Zapisz pozycje poczatkowa (do wyswietlania "o")
    dane.przejscia.push_back(zapisz);
    dane.ostatni.first=x2; dane.ostatni.second=y2; //Zapisz pozycje damki wykonujacej ruch
  }
  return dane;
}

szachownica damka::zbijaj(szachownica dane, int gracz, int x1, int y1, int x2, int y2) {
  list<list<pair<int,int> > > sciezki; //Lista sciezek zawierajacej kolejne zbicia
  list<pair<int,int> > lista_bic; //Sciezka zawierajacej kolejne zbicia
  pair<int,int> bicie,zbity;
  list<list<pair<int,int> > >::iterator it1;
  list<pair<int,int> >::iterator it2,it3;
  int przeciwnik,bylo_bicie,dodac,licz=0,i,j;
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
  for(j=0; j<4; j++) {
    for(i=0; i<8; i++) {
       //Wykonuj kroki w okreslonym kierunku az do znalezienia przeciwnika
      if(dane.pole[x1+(i*x[j])][y1+(i*y[j])]==przeciwnik ||
         dane.pole[x1+(i*x[j])][y1+(i*y[j])]==przeciwnik+2) {
        if(dane.pole[x1+(i*x[j])+x[j]][y1+(i*y[j])+y[j]]==0 && //Jesli pole za przeciwnikiem jest puste
           x1+(i*x[j])+x[j]>=0 && x1+(i*x[j])+x[j]<=7 && y1+(i*y[j])+y[j]>=0 && y1+(i*y[j])+y[j]<=7) {
          bicie.first=x1+(i*x[j])+x[j]; bicie.second=y1+(i*y[j])+y[j]; //Zapisz pole po zbiciu
          zbity.first=x1+(i*x[j]); zbity.second=y1+(i*y[j]); //Zapisz zbitego przeciwnika
          lista_bic.push_back(zbity); //Dodaj zbitego przeciwnika do listy
          lista_bic.push_back(bicie); //Dodaj wolne pole po zbiciu do listy
          sciezki.push_back(lista_bic); //Dodaj liste bic do listy sciezek
        }
        break;
      }
    }
  }
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
          if(bicie.first!=x2 && bicie.second!=y2) {
            bicie.first=(*it2).first+(x[i]*2); bicie.second=(*it2).second+(y[i]*2); //Zapisz pole po zbiciu
            zbity.first=(*it2).first+x[i]; zbity.second=(*it2).second+y[i]; //Zapisz zbitego przeciwnika
          }
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
            dane.pole[x2][y2]=gracz+2; //Zajmij miejsce za zbitym przeciwnikiem
            dane.ostatni.first=x2; dane.ostatni.second=y2; //Zapisz pozycje damki wykonujacej ruch
            return dane;
          }
          dodac=1;
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
