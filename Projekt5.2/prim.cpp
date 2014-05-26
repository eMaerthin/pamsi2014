#include "prim.h"
#include <cstdlib>

lista prim_lista::stworz_min(lista dane) {
  cout << endl << "[Tworzenie MDR...] ";
  int i, j, a, b, waga, znaleziono_a, znaleziono_b, wierzcholek, polaczono=1;
  //int licz=0;
  lista kopia;
  kopia=dane;
  vector<int> polaczenie;
  list<vector<int>> min;
  list<int> wierzcholki;
  list<vector<int>>::iterator it1, indeks;
  vector<int>::iterator it2;
  list<int>::iterator it3;
  it1=kopia.drzewo.begin();   //Wez pierwszy wektor z drzewa
  it2=(*it1).begin();        //Wez pierwszy wierzcholek z wektora
  wierzcholki.push_back(*it2);  //Dodaj wierzcholek do listy wierzcholkow
  while(polaczono==1) { //Jesli ostatnio dolaczono wierzcholek
  	polaczono=0;   //Nie wykonano zadnych polaczen
  	waga=-1;
    for(it1=kopia.drzewo.begin(), i=0; it1!=kopia.drzewo.end(); it1++, i++) { //Przeszukaj drzewo
      znaleziono_a=0;
  	  znaleziono_b=0;
  	  for(it2=(*it1).begin(), j=0; it2!=(*it1).end(); it2++, j++) {
  	  	if(j==0)
  	  	  a=*it2; //Zapisz pierwszy wierzcholek
  	  	if(j==1)
  	  	  b=*it2; //Zapisz drugi wierzcholek
  	  }
  	  it2--;
  	  if(waga==-1)
  	    waga=*it2;
  	  for(it3=wierzcholki.begin(); it3!=wierzcholki.end(); it3++) {
        if(a==*it3)
          znaleziono_a=1;
        if(b==*it3)
          znaleziono_b=1;
  	  }
  	  if((znaleziono_a==0 && znaleziono_b==1) && waga>=*it2) {
        polaczenie=*it1; //Zapisz polaczenie
        wierzcholek=a;   //Zapisz wierzcholek
        waga=*it2;       //Zapisz wage polaczenia
        indeks=it1;      //Zapisz adres wektora z poczatkowego drzewa
        polaczono=1;     //Mozna dolaczyc wierzcholek do MDR
      }
      if((znaleziono_a==1 && znaleziono_b==0) && waga>=*it2) {
      	polaczenie=*it1;
        wierzcholek=b;
        waga=*it2;
        indeks=it1;
        polaczono=1;
      }
      //Jesli oba wierzcholki naleza do tego samego drzewa
      if(znaleziono_a==1 && znaleziono_b==1)
        kopia.drzewo.erase(it1--);     //Usun wektor z drzewa o zadanej pozycji
    }
    //Jesli mozna dolaczyc wierzcholek
    if(polaczono==1) {
      min.push_back(polaczenie); //Dodaj wektor do MDR
      wierzcholki.push_back(wierzcholek); //Dodaj wierzcholki
      kopia.drzewo.erase(indeks);
      //cout << licz++ << endl;
    }
  }
  dane.drzewo=min;
  min.clear();
  wierzcholki.clear();
  cout << "Utworzono MDR :>" << endl;
  return dane;
}

void prim_macierz::sortuj_polaczenia(list<vector<int> > & polaczenia) {
  polaczenia.sort([](const vector<int> & a, const vector<int> & b) { return a.back() > b.back(); });
}

macierz prim_macierz::stworz_min(macierz dane, int n) {
  cout << endl << "[Tworzenie MDR...] ";
  macierz min(n);
  int x=0, y, waga, polaczono=1, znaleziono;
  list<vector<int> > polaczenia, tmp; //Listy polaczen
  vector<int> wektor;
  list<int> dodane; //Lista dodanych wierzcholkow do drzewa
  list<vector<int> >::iterator it_l;
  vector<int>::iterator it_v;
  list<int>::iterator it;
  dodane.push_back(x); //Dodaje wierzcholek x do listy
  do {
    //Spisuje sasiadow dla zadanego wierzcholka x
    for(int i=0; i<n; i++) {
      if(dane.drzewko[x][i]!=-1) {
        //Tworzy wektor z zadanych wierzcholkow i wadze
        wektor.push_back(x);
        wektor.push_back(i);
        wektor.push_back(dane.drzewko[x][i]);
        tmp.push_back(wektor); //Dodaje wektor do tymczasowej listy wektorow
        wektor.clear();
      }
    }
    polaczenia.splice(polaczenia.end(), tmp); //Laczy dwie listy ze soba
    sortuj_polaczenia(polaczenia);  //Sortuje liste wedlug wag
    do {
      //Bierze ostatni wektor z listy polaczen
      it_l=polaczenia.end();
      it_l--;
      it_v=(*it_l).begin();
      y=(*it_v);
      it_v++;
      x=(*it_v);
      it_v++;
      waga=(*it_v);
      znaleziono=0;
      //Szuka zadanych wierzcholkow w liscie dodanych wierzcholkow do drzewa
      for(it=dodane.begin(); it!=dodane.end(); it++) {
        if(x==(*it) || y==(*it))
          znaleziono++;
        if(znaleziono==2) //Jesli znaleziono 2 razy
          break;
      }
      polaczenia.erase(it_l); //Usuwa wektor z listy o zdanym iteratorze
    } while(znaleziono==2);   //Jesli znaleziono 2 razy
    //Zapisuje minimalna wage do macierzy incydencji
    min.drzewko[x][y]=waga;
    min.drzewko[y][x]=waga;
    dodane.push_back(x);
    polaczono++;
    //cout << polaczono << endl;
  } while(polaczono!=n); //Jesli nie dodano wszystkich wierzcholkow do drzewa
  //Wyczysc listy
  polaczenia.clear();
  dodane.clear();
  dane=min; //Kopiuje macierz incydencji
  cout << "Utworzono MDR :>" << endl;
  return dane; //Zwraca macierz incydencji
}
