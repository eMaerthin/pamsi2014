#include "sprawdzenia.h"

int sprawdzenia::czy_sa_pionki(szachownica dane, int gracz) {
  int i,j,znaleziono=0;
  for(i=0; i<8; i++) {
    for(j=0; j<8; j++) {
      if(dane.pole[i][j]==gracz || dane.pole[i][j]==gracz+2)
        znaleziono=1;
    }
    if(znaleziono==1)
      break;
  }
  return znaleziono;
}

szachownica sprawdzenia::sprawdz_ruchy(szachownica dane, int gracz) {
  list<pair<int,int> > ruchy;
  pair<int,int> pozycja;
  int i,j,k,l;
  int x[4]={1,1,-1,-1};
  int y[4]={-1,1,1,-1};
  dane.zwykle_ruchy.clear();
  for(i=0; i<8; i++) {
    for(j=0; j<8; j++) {
      if(dane.pole[i][j]==gracz) { //Jesli jest to pionek
        if(gracz==1)
          l=2;
        else
          l=0;
        for(k=l; k<l+2; k++) {
          if(dane.pole[i+x[k]][j+y[k]]==0 &&
            i+x[k]>=0 && i+x[k]<=7 && j+y[k]>=0 && j+y[k]<=7) {
            pozycja.first=i; pozycja.second=j;
            ruchy.clear();
            ruchy.push_back(pozycja);
            pozycja.first=i+x[k]; pozycja.second=j+y[k];
            ruchy.push_back(pozycja);
            dane.zwykle_ruchy.push_back(ruchy);
          }
        }
      }
      if(dane.pole[i][j]==gracz+2) { //Jesli jest to damka
        for(k=0; k<4; k++) {
          for(l=1; l<8; l++) {
            if(dane.pole[i+(x[k]*l)][j+(y[k]*l)]==0 &&
              i+(l*x[k])>=0 && i+(l*x[k])<=7 && j+(l*y[k])>=0 && j+(l*y[k])<=7) {
              pozycja.first=i; pozycja.second=j;
              ruchy.clear();
              ruchy.push_back(pozycja);
              pozycja.first=i+(x[k]*l); pozycja.second=j+(y[k]*l);
              ruchy.push_back(pozycja);
              dane.zwykle_ruchy.push_back(ruchy);
            }
            else
              break;
          }
        }
      }
    }
  }
  /*list<list<pair<int,int> > >::iterator it2;
  list<pair<int,int> >::iterator it;
  for(it2=dane.zwykle_ruchy.begin(); it2!=dane.zwykle_ruchy.end(); it2++) {
    for(it=(*it2).begin(); it!=(*it2).end(); it++) {
      cout << (*it).first << " " << (*it).second << " -> ";
    }
    cout << endl;
  }*/
  return dane;
}

szachownica sprawdzenia::sprawdz_bicia(szachownica dane, int gracz) {
  int i,j,k,l,m,n=0,x1,y1,nr,przeciwnik,dodaj;
  int znaleziono[4]; //Jesli damka napotkala pierwszego przeciwnika dla danego kierunku
  list<pair<int,int> > sciezka[10][10];
  list<pair<int,int> >::iterator it;
  pair<int,int> pozycja;
  int x[4]={1,1,-1,-1};
  int y[4]={-1,1,1,-1};
  if(gracz==1)
    przeciwnik=gracz+1;
  else
    przeciwnik=gracz-1;
  dane.zagrozone.clear();
  for(i=0; i<8; i++) {
    for(j=0; j<8; j++) {
      if(dane.pole[i][j]==gracz || dane.pole[i][j]==gracz+2) {
        pozycja.first=i; pozycja.second=j; //Zapisz pozycje poczatkowa pionka zbijajacego
        for(m=0; m<10; m++)
          sciezka[n][m].clear(); //Wyczysc sciezki dla danego pionka
        sciezka[n][0].push_back(pozycja); //Dodaj do pierwszej sciezki pozycje poczatkowa pionka zbijajacego
        for(m=0; m<10; m++) {
          if(sciezka[n][m].size()>0) { //Jesli istnieje taka sciezka
            nr=m;
            it=sciezka[n][m].end(); it--; //Odczytaj pole po ostatnim zbiciu (lub pozycje poczatkowa)
            x1=(*it).first; y1=(*it).second;
            for(k=0; k<4; k++) { //Dla kazdego kierunku
              znaleziono[k]=0;
              for(l=1; l<8; l++) {
                dodaj=1;
                if(dane.pole[x1+(x[k]*l)+x[k]][y1+(y[k]*l)+y[k]]==0 &&
                  (dane.pole[x1+(x[k]*l)][y1+(y[k]*l)]==przeciwnik || dane.pole[x1+(x[k]*l)][y1+(y[k]*l)]==przeciwnik+2)
                  && x1+(l*x[k])>=0 && x1+(l*x[k])<=7 && y1+(l*y[k])>=0 && y1+(l*y[k])<=7) {
                  if(sciezka[n][m].size()>2) {
                    it=sciezka[n][m].end(); it--; it--;
                    if((*it).first==x1+(x[k]*l) && (*it).second==y1+(y[k]*l)) //Jesli pozycja jest juz na sciezce
                      dodaj=0;
                  }
                  if(dodaj==1) {
                    pozycja.first=x1+(x[k]*l); pozycja.second=y1+(y[k]*l); //Zapisz pozycje przeciwnika
                    nr++; //Zwieksz liczbe sciezek o 1
                    sciezka[n][nr]=sciezka[n][m];  //Kopiuj na nowa powstala sciezke zawartosc poprzedniej sciezki
                    if(sciezka[n][nr].size()>1) {
                      it=sciezka[n][nr].end(); it--;
                      it=sciezka[n][nr].erase(it);
                    }
                    sciezka[n][nr].push_back(pozycja); //Dodaj do sciezki pozycje zbitego przeciwnika
                    pozycja.first=x1+(x[k]*l)+x[k]; pozycja.second=y1+(y[k]*l)+y[k];
                    sciezka[n][nr].push_back(pozycja); //Dodaj do sciezki pole po zbiciu przeciwnika
                    dane.zagrozone.push_back(sciezka[n][nr]);
                  }
                }
                if(dane.pole[i][j]<gracz+2 || znaleziono[k]==0) {
                  break;
                }
              }
            }
          }
        }
        if(nr!=0) {
          n++;
        }
      }
    }
  }
  /*list<list<pair<int,int> > >::iterator it2;
  for(it2=dane.zagrozone.begin(); it2!=dane.zagrozone.end(); it2++) {
    for(it=(*it2).begin(); it!=(*it2).end(); it++) {
      cout << (*it).first << " " << (*it).second << " -> ";
    }
    cout << endl;
  }*/
  return dane;
}

szachownica sprawdzenia::ukaraj(szachownica dane, int gracz) {
  list<list<pair<int,int> > >::iterator it1,it3;
  list<pair<int,int> >::iterator it2,it4;
  list<pair<int,int> > do_ukarania;
  pair<int,int> poczatek[2],pierwszy[2];
  int i,przeciwnik,znaleziono,dlugosc;
  if(gracz==1)
    przeciwnik=gracz+1;
  else
    przeciwnik=gracz-1;
  for(it1=dane.zagrozone.begin(); it1!=dane.zagrozone.end(); it1++) { //Przeszukaj sciezki zbijajace
    it2=(*it1).begin();
    poczatek[0]=(*it2); //Zapisz pozycje pionka zbijajacego
    it2++;
    pierwszy[0]=(*it2); //Zapisz pozycje pierwszego spotkanego przeciwnika
    do { //Przeszukaj sciezki zbijajace
      it1++;
      if((*it1).size()==0)
        break;
      it2=(*it1).begin();
      poczatek[1]=(*it2);
      it2++;
      pierwszy[1]=(*it2);
      //Przeszukaj sciezki dopoki pozycja pionka zbijajacego i
    } while(poczatek[1]==poczatek[0] && pierwszy[1]==pierwszy[0]);
    if((*it1).size()!=0)
      it1--;
    dlugosc=(*it1).size();
    for(it2=(*it1).begin(), i=1; it2!=(*it1).end(); it2++, i++) {
      if(dane.pole[(*it2).first][(*it2).second]==przeciwnik
        || dane.pole[(*it2).first][(*it2).second]==przeciwnik+2) {
        znaleziono=0;
        for(it4=do_ukarania.begin(); it4!=do_ukarania.end(); it4++) {
          if((*it4)==poczatek[0]) {
            znaleziono=1;
            break;
          }
        }
        if(znaleziono==0)
          do_ukarania.push_back(poczatek[0]);
      }
      if((dane.pole[(*it2).first][(*it2).second]!=przeciwnik
        || dane.pole[(*it2).first][(*it2).second]!=przeciwnik+2) && i==dlugosc) {
        do {
          it1++;
          it2=(*it1).begin();
        } while((*it2)==pierwszy[0]);
        it1--;
        break;
      }
    }
  }
  for(it2=do_ukarania.begin(); it2!=do_ukarania.end(); it2++) {
    if(dane.pole[(*it2).first][(*it2).second]!=0) { //Jesli pionek jest na wskazanej pozycji
      dane.pole[(*it2).first][(*it2).second]=0;
      dane.zbicia.push_back(*it2);
    }
    else {
      dane.pole[dane.ostatni.first][dane.ostatni.second]=0;
      dane.zbicia.push_back(dane.ostatni);
    }
  }
  return dane;
}
