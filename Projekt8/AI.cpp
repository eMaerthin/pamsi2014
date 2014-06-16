#include "AI.h"

szachownica komputer::ruch_komputera(szachownica dane) {
  list<wezel>::iterator it[7];
  wezel w[8];
  symulacje=0;
  najlepszy.first=0; najlepszy.second=-1000;
  //Inicjacja poziomu 0
  w[0].stan=dane;
  w[0].punkty=0;
  poziom=1;
  w[0]=zasymuluj_ruchy(w[0],dane,2,dane.trudnosc); //Zasymulowano poziom 1
  if(zakoncz!=0) {
    for(it[0]=w[0].mozliwosci.begin(); it[0]!=w[0].mozliwosci.end(); it[0]++) {
      poziom=2;
      w[1]=zasymuluj_ruchy((*it[0]),dane,1,dane.trudnosc); //Zasymulowano poziom 2
      if(zakoncz==0) break;
      for(it[1]=w[1].mozliwosci.begin(); it[1]!=w[1].mozliwosci.end(); it[1]++) {
        poziom=3;
        w[2]=zasymuluj_ruchy((*it[1]),dane,2,dane.trudnosc); //Zasymulowano poziom 3
        if(zakoncz==0) break;
        for(it[2]=w[2].mozliwosci.begin(); it[2]!=w[2].mozliwosci.end(); it[2]++) {
          poziom=4;
          w[3]=zasymuluj_ruchy((*it[2]),dane,1,dane.trudnosc); //Zasymulowano poziom 4
          if(zakoncz==0) break;
          if(dane.trudnosc==1)
            break;
          for(it[3]=w[3].mozliwosci.begin(); it[3]!=w[3].mozliwosci.end(); it[3]++) {
            poziom=5;
            w[4]=zasymuluj_ruchy((*it[3]),dane,2,dane.trudnosc); //Zasymulowano poziom 5
            if(zakoncz==0) break;
            for(it[4]=w[4].mozliwosci.begin(); it[4]!=w[4].mozliwosci.end(); it[4]++) {
              poziom=6;
              w[5]=zasymuluj_ruchy((*it[4]),dane,1,dane.trudnosc); //Zasymulowano poziom 6
              if(zakoncz==0) break;
              if(dane.trudnosc==2)
                break;
              for(it[5]=w[5].mozliwosci.begin(); it[5]!=w[5].mozliwosci.end(); it[5]++) {
                poziom=7;
                w[6]=zasymuluj_ruchy((*it[5]),dane,2,dane.trudnosc); //Zasymulowano poziom 7
                if(zakoncz==0) break;
                for(it[6]=w[6].mozliwosci.begin(); it[6]!=w[6].mozliwosci.end(); it[6]++) {
                  poziom=8;
                  w[7]=zasymuluj_ruchy((*it[6]),dane,1,dane.trudnosc); //Zasymulowano poziom 8
                  if(zakoncz==0) break;
                }
              }
            }
          }
        }
      }
    }
  }
  for(it[0]=w[0].mozliwosci.begin(); it[0]!=w[0].mozliwosci.end(); it[0]++) {
    if((*it[0]).poczatek==najlepszy.first) {
      dane=(*it[0]).stan;
      break;
    }
  }
  cout << endl << "       Liczba symulacji: " << symulacje << endl;
  return dane;
}

komputer::wezel komputer::zasymuluj_ruchy(wezel w1, szachownica dane, int gracz, int trudnosc) {
  int i, licz=0, dlugosc, rodzaj, punkty_gracz=0, koniec[3]={4,6,8};
  wezel w2, koncowka;
  sprawdzenia spr;
  list<wezel> najlepsze_gracz;
  list<list<pair<int,int> > >::iterator it1;
  list<pair<int,int> >::iterator it2;
  list<wezel>::iterator it3;
  pair<int,int> ostatni;
  w1.stan=spr.sprawdz_bicia(w1.stan,gracz);
  w1.stan=spr.sprawdz_ruchy(w1.stan,gracz);
  w1.mozliwosci.clear();
  for(it1=w1.stan.zagrozone.begin(); it1!=w1.stan.zagrozone.end(); it1++) {
    w2.stan=w1.stan;
    w2.poczatek=w1.poczatek;
    if(poziom==1) {
      w2.poczatek=licz;
      licz++;
    }
    dlugosc=(*it1).size();
    for(it2=(*it1).begin(), i=1; it2!=(*it1).end(); it2++, i++) {
      if(i==1) {
        w2.stan.przejscia.clear();
        w2.stan.zbicia.clear();
        rodzaj=w1.stan.pole[(*it2).first][(*it2).second];
        w2.stan.pole[(*it2).first][(*it2).second]=0;
        w2.stan.przejscia.push_back(*it2);
      }
      if(i>1 && i<dlugosc) {
        w2.stan.pole[(*it2).first][(*it2).second]=0;
        w2.stan.zbicia.push_back(*it2);
      }
      if(i==dlugosc) {
        if((rodzaj==1 && (*it2).first==0) || (rodzaj==2 && (*it2).first==7))
          w2.stan.pole[(*it2).first][(*it2).second]=rodzaj+2;
        else
          w2.stan.pole[(*it2).first][(*it2).second]=rodzaj;
        w2.stan.ostatni=(*it2);
      }
      if(gracz==2) {
        zakoncz=spr.czy_sa_pionki(w2.stan,1);
        if(zakoncz==0) {
          w2.punkty=ocen_sytuacje(dane,w2.stan,2);
          najlepszy.first=w2.poczatek;
          najlepszy.second=w2.punkty;
          w1.mozliwosci.push_back(w2);
          return w1;
        }
      }
    }
    w2.stan=spr.ukaraj(w2.stan,gracz);
    if(gracz==1) {
      w2.punkty=ocen_sytuacje(w1.stan,w2.stan,1);
      if(w2.punkty==punkty_gracz)
        najlepsze_gracz.push_back(w2);
      if(w2.punkty>punkty_gracz) {
        najlepsze_gracz.clear();
        najlepsze_gracz.push_back(w2);
        punkty_gracz=w2.punkty;
      }
    }
    if(gracz==2)
      w1.mozliwosci.push_back(w2);
    symulacje++;
  }
  for(it1=w1.stan.zwykle_ruchy.begin(); it1!=w1.stan.zwykle_ruchy.end(); it1++) {
    w2.stan=w1.stan;
    w2.poczatek=w1.poczatek;
    if(poziom==1) {
      w2.poczatek=licz;
      licz++;
    }
    for(it2=(*it1).begin(), i=1; it2!=(*it1).end(); it2++, i++) {
      if(i==1) {
        w2.stan.przejscia.clear();
        rodzaj=w1.stan.pole[(*it2).first][(*it2).second];
        w2.stan.pole[(*it2).first][(*it2).second]=0;
        w2.stan.przejscia.push_back(*it2);
      }
      else {
        w2.stan.pole[(*it2).first][(*it2).second]=rodzaj;
        w2.stan.ostatni=(*it2);
        if((rodzaj==1 && (*it2).first==0) || (rodzaj==2 && (*it2).first==7))
          w2.stan.pole[(*it2).first][(*it2).second]=rodzaj+2;
        else
          w2.stan.pole[(*it2).first][(*it2).second]=rodzaj;
      }
    }
    w2.stan=spr.ukaraj(w2.stan,gracz);
    if(gracz==1) {
      w2.punkty=ocen_sytuacje(w1.stan,w2.stan,1);
      if(w2.punkty==punkty_gracz)
        najlepsze_gracz.push_back(w2);
      if(w2.punkty>punkty_gracz) {
        najlepsze_gracz.clear();
        najlepsze_gracz.push_back(w2);
        punkty_gracz=w2.punkty;
      }
    }
    if(gracz==2)
      w1.mozliwosci.push_back(w2);
    symulacje++;
  }
  if(gracz==1)
    w1.mozliwosci=najlepsze_gracz;
  if(w1.mozliwosci.size()!=0 && gracz==1) {
    for(it3=w1.mozliwosci.begin(); it3!=w1.mozliwosci.end(); it3++) {
      (*it3).stan=spr.sprawdz_bicia((*it3).stan,2);
      (*it3).stan=spr.sprawdz_ruchy((*it3).stan,2);
      //cout << poziom << " " << (*it3).stan.zagrozone.size() << " " << (*it3).stan.zwykle_ruchy.size() << endl;
      //Jesli osiagnieto maksymalny poziom albo wezel staje sie ruchem koncowym
      if(poziom==koniec[trudnosc-1] || ((*it3).stan.zagrozone.size()==0 && (*it3).stan.zwykle_ruchy.size()==0)) {
        (*it3).punkty=ocen_sytuacje(dane,(*it3).stan,2);
        if((*it3).punkty > najlepszy.second) {
          najlepszy.first=(*it3).poczatek;
          najlepszy.second=(*it3).punkty;
        }
        else {
          (*it3).stan.zagrozone.clear();
          (*it3).stan.zwykle_ruchy.clear();
        }
      }
    }
  }
  return w1;
}

int komputer::ocen_sytuacje(szachownica stan1, szachownica stan2, int gracz) {
  int i,j,przeciwnik,punkty=0,pionek[2]={0,0},damka[2]={0,0},zbity_pionek=0,zbita_damka=0;
  if(gracz==1)
    przeciwnik=gracz+1;
  else
    przeciwnik=gracz-1;
  if(zakoncz==0)
    return 1000;
  for(i=0; i<8; i++) {
    for(j=0; j<8; j++) {
      if(stan2.pole[i][j]!=-1 && stan2.pole[i][j]!=0 && (stan2.pole[i][j]==gracz || stan2.pole[i][j]==gracz+2)) {
        if(stan2.pole[i][j]==gracz) //Jesli jest to pionek
          punkty=punkty+5;
        if(stan2.pole[i][j]==gracz+2) //Jesli jest to damka
          punkty=punkty+50;
        if((gracz==1 && (i==4 || i==5)) || (gracz==2 && (i==2 || i==3))) //Gracz jest na 2 poziomie szachownicy
          punkty=punkty+1;
        if((gracz==1 && (i==2 || i==3)) || (gracz==2 && (i==4 || i==5))) //Gracz jest na 3 poziomie szachownicy
          punkty=punkty+3;
        if((gracz==1 && (i==0 || i==1)) || (gracz==2 && (i==6 || i==7))) //Gracz jest na 4 poziomie szachownicy
          punkty=punkty+10;
        if(i==0 || i==7 || j==0 || j==7) //Gracz jest w I strefie szachownicy
          punkty=punkty+2;
        if(((i==1 || i==6 ) && (j>=1 && j<=6)) || ((i>=1 && i<=6) && (j==1 || j==6 ))) //Gracz jest w II strefie szachownicy
          punkty=punkty+1;
      }
    }
  }
  //Policz zbicia
  for(i=0; i<8; i++) {
    for(j=0; j<8; j++) {
      if(stan1.pole[i][j]==przeciwnik)
        pionek[0]++;
      if(stan1.pole[i][j]==przeciwnik+2)
        damka[0]++;
      if(stan2.pole[i][j]==przeciwnik)
        pionek[1]++;
      if(stan2.pole[i][j]==przeciwnik+2)
        damka[1]++;
    }
  }
  if(pionek[0]+damka[0]!=pionek[1]+damka[1]) {
    if(damka[0]-damka[1]>0) //Przeciwnik stracil damke
      zbita_damka=zbita_damka+(damka[0]-damka[1]);
    if(damka[0]-damka[1]<0) { //Przeciwnik zyskal damke
      zbita_damka=zbita_damka+(damka[0]-damka[1]); //Wtedy gracz bedzie tracil punkty
      zbity_pionek=zbity_pionek+(-1)*(damka[0]-damka[1]); //Zmniejsz liczbe bic pionkow o 1 by nie policzono bicia pionka
    }
    if(pionek[0]-pionek[1]>0) //Przeciwnik stracil pionka
      zbity_pionek=zbity_pionek+pionek[0]-pionek[1];
    punkty=punkty+(5*zbity_pionek)+(20*zbita_damka); //Sumuj wszystkie punkty
  }
  return punkty;
}
