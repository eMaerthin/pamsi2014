#include "szachownica.h"

szachownica::szachownica() {
  pole[0][0]=pole[0][2]=pole[0][4]=pole[0][6]=
  pole[1][1]=pole[1][3]=pole[1][5]=pole[1][7]=
  pole[2][0]=pole[2][2]=pole[2][4]=pole[2][6]=
  pole[3][1]=pole[3][3]=pole[3][5]=pole[3][7]=
  pole[4][0]=pole[4][2]=pole[4][4]=pole[4][6]=
  pole[5][1]=pole[5][3]=pole[5][5]=pole[5][7]=
  pole[6][0]=pole[6][2]=pole[6][4]=pole[6][6]=
  pole[7][1]=pole[7][3]=pole[7][5]=pole[7][7]=-1;

  //---------------------------------------------

  pole[0][1]=pole[0][3]=pole[0][5]=pole[0][7]=
  pole[1][0]=pole[1][2]=pole[1][4]=pole[1][6]=
  pole[2][1]=pole[2][3]=pole[2][5]=pole[2][7]=2;

  pole[3][0]=pole[3][2]=pole[3][4]=pole[3][6]=
  pole[4][1]=pole[4][3]=pole[4][5]=pole[4][7]=0;

  pole[5][0]=pole[5][2]=pole[5][4]=pole[5][6]=
  pole[6][1]=pole[6][3]=pole[6][5]=pole[6][7]=
  pole[7][0]=pole[7][2]=pole[7][4]=pole[7][6]=1;

  //---------------------------------------------

  //Odkomentuj by zagrac 4v4 damki:

  /*pole[0][1]=pole[0][3]=pole[0][5]=pole[0][7]=4;
  pole[1][0]=pole[1][2]=pole[1][4]=pole[1][6]=
  pole[2][1]=pole[2][3]=pole[2][5]=pole[2][7]=0;

  pole[3][0]=pole[3][2]=pole[3][4]=pole[3][6]=
  pole[4][1]=pole[4][3]=pole[4][5]=pole[4][7]=0;

  pole[5][0]=pole[5][2]=pole[5][4]=pole[5][6]=
  pole[6][1]=pole[6][3]=pole[6][5]=pole[6][7]=0;
  pole[7][0]=pole[7][2]=pole[7][4]=pole[7][6]=3;*/

  //---------------------------------------------

  //Tak wyglada poczatkowa tablica:

  /*pole[8][8]={-1,1,-1,1,-1,1,-1,1,
              1,-1,1,-1,1,-1,1,-1,
              -1,1,-1,1,-1,1,-1,1,
              0,-1,0,-1,0,-1,0,-1,
              -1,0,-1,0,-1,0,-1,0,
              2,-1,2,-1,2,-1,2,-1,
              -1,2,-1,2,-1,2,-1,2,
              2,-1,2,-1,2,-1,2,-1};*/
}

void szachownica::wyswietl_szachownice() {
  list<pair<int,int> >::iterator it,it2;
  int i,j,k,zamaluj,znaleziono,wyswietl_o;
  char literka[8]={'A','B','C','D','E','F','G','H'};
  cout << endl << "            ";
  for(i=0; i<8; i++) {
    cout << literka[i] << "         ";
  }
  for(j=0; j<9; j++) {
    if(j%2==0)
      zamaluj=1;
    else
      zamaluj=0;
    cout << endl << "       ";
    for(i=0; i<8; i++) {
      cout << "==========";
    }
    for(k=0; k<3; k++) {
      if(j<8) {
        if(k==1)
          cout << endl << "   " << j+1 << "   ";
        else
          cout << endl << "       ";
      }
      if(j<8) {
        for(i=0; i<8; i++) {
          if(zamaluj==1)
            cout << "| . . . . ";
          else {
            if(k==0) {
              if(pole[j][i]==0 || pole[j][i]==1 || pole[j][i]==2)
                cout << "|         ";
              else
                cout << "|    _    ";
            }
            if(k==1) {
              znaleziono=0;
              if(pole[j][i]==0) {
                for(it=przejscia.begin(); it!=przejscia.end(); it++) {
                  wyswietl_o=1;
                  for(it2=zbicia.begin(); it2!=zbicia.end(); it2++) {
                    if((*it2).first==j && (*it2).second==i) {
                      wyswietl_o=0;
                      break;
                    }
                  }
                  if(wyswietl_o==1) {
                    if((*it).first==j && (*it).second==i) {
                      cout << "|    o    ";
                      znaleziono=1;
                      break;
                    }
                  }
                }
                for(it=zbicia.begin(); it!=zbicia.end(); it++) {
                  if((*it).first==j && (*it).second==i) {
                    cout << "|    X    ";
                    znaleziono=1;
                    break;
                  }
                }
                if(znaleziono==0)
                  cout << "|         ";
              }
              if(pole[j][i]==1 || pole[j][i]==3) {
                if(ostatni.first==j && ostatni.second==i)
                  cout << "|  < A >  ";
                else
                  cout << "|  ( A )  ";
              }
              if(pole[j][i]==2 || pole[j][i]==4) {
                if(ostatni.first==j && ostatni.second==i)
                  cout << "|  < B >  ";
                else
                  cout << "|  [ B ]  ";
              }
            }
            if(k==2)
              cout << "|         ";
          }
          if(zamaluj==1)
            zamaluj=0;
          else
            zamaluj=1;
        }
        cout << "|";
      }
    }
  }
  przejscia.clear();
  zbicia.clear();
  cout << endl;
}
