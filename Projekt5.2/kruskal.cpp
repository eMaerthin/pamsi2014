#include "kruskal.h"

lista kruskal_lista::stworz_min(lista dane, int n) {
  cout << endl << "[Tworzenie MDR...] ";
  int ile=1;  //Zmienna zawierajaca rozmiar MDR
  int a, b, x, y, i, j, k;
  list<vector<int> > las[n/2];
  list<vector<int> >::iterator it1, it3; //Iteratory do przeszukiwania drzewa
  vector<int>::iterator it2, it4;	    //Iteratory do przeszukiwania wektorow
  dane.sortuj_wagi();
  for(it1=dane.drzewo.begin(); it1!=dane.drzewo.end(); ++it1) {
  	for(it2=(*it1).begin(), i=1; i<3; ++it2, ++i) {
  	  if(i==1) //Jesli jest to pierwszy wierzcholek
  	    a=-1;  //Wartosc pierwszego wierzcholka jest nieokreslona
  	  else     //Jesli jest to drugi wierzcholek
  	    b=-1;  //Wartosc drugiego wierzcholka jest nieokreslona
  	  for(j=0; j<ile; j++) { //Przeszukaj tymczasowe drzewa
  	  	for(it3=las[j].begin(); it3!=las[j].end(); ++it3) {
  	  	  for(it4=(*it3).begin(), k=1; k<3; ++it4, ++k) {
            if(*it2==*it4 && i==1) { //Jesli pierwszy wierzcholek juz wystapil na drzewie
              a=j;    //Zapisz indeks tymczasowego drzewa
              x=*it2; //Zapisz wierzcholek
            }
            if(*it2==*it4 && i==2) { //Jesli drugi wierzcholek juz wystapil na drzewie
              b=j;    //Zapisz indeks tymczasowego drzewa
              y=*it2; //Zapisz wierzcholek
            }
          }
        }
  	  }
    }
    if(a>-1 && b>-1) {
      //Laczenie 2 drzew o zadanych indeksach ze soba
      if(a!=b) {
      	if(a<b) {
      	  for(it3=las[b].begin(); it3!=las[b].end(); ++it3)
      	    las[a].push_back(*it3);
            las[a].push_back(*it1);
            las[b].clear(); //Usuniecie drzewa o wyzszym indeksie
        }
        if(a>b) {
          for(it3=las[a].begin(); it3!=las[a].end(); ++it3)
      	    las[b].push_back(*it3);
            las[b].push_back(*it1);
            las[a].clear(); //Usuniecie drzewa o wyzszym indeksie
        }
      }
      //Przypadek gdy wierzcholek okresla sam siebie
      if(a==b && x==y)
      	las[a].push_back(*it1);
    }
    //Dodanie do drzewa o zadanym indeksie
    if(a>-1 && b==-1)
      las[a].push_back(*it1);
    //Dodanie do drzewa o zadanym indeksie
    if(a==-1 && b>-1)
      las[b].push_back(*it1);
    //Nie znaleziono na zadnym drzewie, tworzenie nowego drzewa
    if(a==-1 && b==-1) {
      las[ile-1].push_back(*it1);
      ++ile;
    }
    //Jesli nie spelnione sa powyzsze warunki to znaczy ze wystapil cykl
    //wiec wektor bedzie ignorowany
  }
  dane.drzewo=las[0]; //Kopiuj tymczasowe drzewo o najnizszym indeksie do naszego drzewa
  for(i=0; i<ile; i++)
    las[i].clear(); //Wyczysc tymczasowe drzewa
  cout << "Utworzono MDR :>" << endl;
  return dane;
}

macierz kruskal_macierz::stworz_min(macierz dane, int n) {
  cout << endl << "[Tworzenie MDR...] ";
  macierz ** las; //WskaŸnik na macierz incydencji
  //Tworzenie lasu macierzy incydencji
  las=new macierz*[n/2];
  for(int i=0; i<(n/2); i++)
    las[i]=new macierz(n);
  int i,j,k,min,ile=0,a,b,pierwszy,drugi;
  do {
    min=-1; //Ustawia minimalna wage na nieokreslona
    for(i=0; i<n; i++) {
      for(j=i+1; j<n; j++) {
        //Jesli nie ma zapisanej wagi na zadanych indeksach macierzy
        //oraz gdy minimalna waga jest wieksza od nowej wartosci lub jest nieokreslona
        if(dane.drzewko[i][j]!=-1 && (min>dane.drzewko[i][j] || min==-1)) {
          min=dane.drzewko[i][j]; //Zapisuje minimalna wage
          pierwszy=i; //Zapisuje pierwszy wierzcholek
          drugi=j;    //Zapisuje drugi wierzcholek
        }
      }
    }
    //Usuniecie wagi o zadanych indeksach w poczatkowej macierzy
    dane.drzewko[pierwszy][drugi]=-1;
    dane.drzewko[drugi][pierwszy]=-1;
    if(min==-1)
      break;
    //Ustawienie wierzcholkow na nieokreslone
    a=-1;
    b=-1;
    for(i=0; i<=ile; i++) {
      for(j=0; j<n; j++) {
        while(las[i]->drzewko[0][0]==-100) //Jesli las o zadanym indeksie zostal "usuniety"
          i++;
        if(i>=ile)
          break;
        //Sprawdzenie polaczen na zadanych lasach
        for(k=j+1; k<n; k++) {
          if((pierwszy==j || pierwszy==k) && las[i]->drzewko[j][k]!=-1)
            a=i;
          if((drugi==j || drugi==k) && las[i]->drzewko[j][k]!=-1)
            b=i;
        }
      }
    }
    //Laczenie 2 drzew o zadanych indeksach ze soba
    if(a>-1 && b>-1) {
      if(a<b) {
        for(i=0; i<n; i++) {
          for(j=i+1; j<n; j++) {
            if(las[b]->drzewko[i][j]!=-1) {
              las[a]->drzewko[i][j]=las[b]->drzewko[i][j];
              las[a]->drzewko[j][i]=las[b]->drzewko[j][i];
            }
          }
        }
        las[a]->drzewko[pierwszy][drugi]=min;
        las[a]->drzewko[drugi][pierwszy]=min;
        las[b]->drzewko[0][0]=-100; //"Usuwa" las o zadanym indeksie
      }
      if(a>b) {
        for(i=0; i<n; i++) {
          for(j=i+1; j<n; j++) {
            if(las[a]->drzewko[i][j]!=-1) {
              las[b]->drzewko[i][j]=las[a]->drzewko[i][j];
              las[b]->drzewko[j][i]=las[a]->drzewko[j][i];
            }
          }
        }
        las[b]->drzewko[pierwszy][drugi]=min;
        las[b]->drzewko[drugi][pierwszy]=min;
        las[a]->drzewko[0][0]=-100; //"Usuwa" las o zadanym indeksie
      }
    }
    //Dodanie do drzewa o zadanym indeksie
    if(a>-1 && b==-1) {
      las[a]->drzewko[pierwszy][drugi]=min;
      las[a]->drzewko[drugi][pierwszy]=min;
    }
    //Dodanie do drzewa o zadanym indeksie
    if(a==-1 && b>-1) {
      las[b]->drzewko[pierwszy][drugi]=min;
      las[b]->drzewko[drugi][pierwszy]=min;
    }
    //Nie znaleziono na zadnym drzewie, tworzenie nowego drzewa
    if(a==-1 && b==-1) {
      las[ile]->drzewko[pierwszy][drugi]=min;
      las[ile]->drzewko[drugi][pierwszy]=min;
      ++ile;
      //cout << ile << endl;
    }
  } while(min!=-1);
  //Kopiuje MDR z lasu o zerowym indeksie
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      dane.drzewko[i][j]=las[0]->drzewko[i][j];
      dane.drzewko[j][i]=las[0]->drzewko[j][i];
    }
  }
  for(int i=0; i<(n/2); i++)
		delete las[i]; //Usuwa las
	delete []las;
	cout << "Utworzono MDR :>" << endl;
  return dane;
}
