



#include <iostream>
#include <list>
#include <fstream>
#include <algorithm>
#include <functional>
#include <stack>
using namespace std;
ifstream plik;
ofstream plik2;
const int rozmiar=800; //Rozmiar grafu - ilosc wierzcholkow
const int inf=10000000;
//Struktura polaczenie konieczna do zdefiniowania postaci listowej grafu.
struct polaczenie
{
       int wierzcholek; // wierzcholek z ktorym jest polaczenie o nastepujacej wadze:
       int waga;
       friend ostream & operator <<(ostream &wyjscie, polaczenie p);
};

ostream & operator <<(ostream &wyjscie,const polaczenie p)
{
        return wyjscie<<"->"<<p.wierzcholek<<"("<<p.waga<<")";
}

struct luk
{
int poczatek, koniec, waga;

};


bool mniejsze(const luk &L1,const  luk &L2)
{
        if(L1.waga<L2.waga) return true;
         else return false;
}




struct graf
{
   list<luk> MDR; //minimalne drzewo rozpinajace w postaci listy
       int macierz[rozmiar][rozmiar];
       list<polaczenie> lista[rozmiar];
       graf()
       {
                   for(int i=0; i<rozmiar; i++)
                           for(int j=0; j<rozmiar; j++)
                                   macierz[i][j]=-1;      
       }

        void wczytaj_z_pliku()
       {
            cout<<"Wczytywanie danych z pliku tekstowego\n";
            plik.open("test.txt");   // nazwa pliku zawierajacego dane wejsciowe
            if(plik.good())
            {
                           cout<<"Plik zostal otwarty pomyslnie\n";
                           while(!plik.eof())
                           {
                           int i,j,w;
                           plik>>i;
                           plik>>j;
                           plik>>w;
                           polaczenie tmp;
                           tmp.wierzcholek=j;
                           tmp.waga=w;
                           lista[i].push_back(tmp);
                           tmp.wierzcholek=i;
                           lista[j].push_back(tmp);
                           macierz[i][j]=w;
                           macierz[j][i]=w;
                           }
            }
            else
            cout<<"Nie udalo sie otworzyc pliku\n";
       }


/*Metoda odpowiadajaca za sortowanie tablicy lukow w kolejnosci rosnacej w zaleznosci od wag*/





void sortuj_tablice_lukow(list <luk> &L)
{
 L.sort(mniejsze);
}

/*Metoda sprawdzajaca czy wszystkie wierzcholki grafu znajduja sie w minimalnym drzewie rozpinajacym*/
bool czy_drzewo_zawiera_wszystkie_wierzcholki(bool* tab)
{
int ilosc=0;
for(int i=0; i<rozmiar; i++)
if(tab[i]==true)
ilosc++;

if(ilosc==rozmiar)
return true;
else
return false;
}


       bool czy_istnieje_droga_w_MDR(int poczatek, int koniec)
       {
list<luk> MDRtmp;
MDRtmp=MDR;
list<int> *A;
A=new list<int> [rozmiar];
int tmp;


while(!MDRtmp.empty())
{
A[MDRtmp.front().poczatek].push_front(MDRtmp.front().koniec);
A[MDRtmp.front().koniec].push_front(MDRtmp.front().poczatek);
MDRtmp.pop_front();
}


bool* odwiedzone=new bool[rozmiar];

for(int i=0; i<rozmiar; i++)
odwiedzone[i]=false;

stack<int> STOS;
bool znalezione=false;
STOS.push(poczatek);

while(!STOS.empty())
{
tmp=STOS.top();
STOS.pop();
if(!odwiedzone[tmp])
{
odwiedzone[tmp]=true;
if(tmp==koniec)
{
znalezione=true;
break;
}

for(list<int>::iterator it=A[tmp].begin(); it!=A[tmp].end();it++)
if(!odwiedzone[*it])
STOS.push(*it);

}
}
delete []odwiedzone;
delete []A;
return znalezione;
  }




      void algorytm_kruskala()
       {
    luk tmp;
    list <luk> listaL,listaTMP;
    bool czy_nalezy_do_drzewa[rozmiar];
    bool sprawdzacz=false;

   
   for(int i=0; i<rozmiar; i++)
    czy_nalezy_do_drzewa[i]=false;
    for(int i=0;i<rozmiar; i++)
    for(int j=0; j<rozmiar; j++)
    if(macierz[i][j]!=-1)
    {
    tmp.poczatek=i;
           tmp.koniec=j;
           tmp.waga=macierz[i][j];
        listaL.push_front(tmp);
    }

    sortuj_tablice_lukow(listaL);


    

    do
    {
     while(!listaL.empty())
     {
      if(!czy_istnieje_droga_w_MDR(listaL.front().poczatek,listaL.front().koniec))
      {
       MDR.push_front(listaL.front());
       czy_nalezy_do_drzewa[listaL.front().koniec]=true;
       czy_nalezy_do_drzewa[listaL.front().poczatek]=true;
      }
     listaL.pop_front();
    } 
    }while(!czy_drzewo_zawiera_wszystkie_wierzcholki(czy_nalezy_do_drzewa));
    int waga=0;
       do
       {
           cout<<MDR.front().poczatek<<" "<<MDR.front().koniec<<" "<<MDR.front().waga<<"\n";
           waga+=MDR.front().waga;
           MDR.pop_front();
    }
    while(!MDR.empty());
    cout<<"Waga: "<<waga<<"\n";
       }

};




int main()
{
    int i;
    graf G;
    cout<<"Utworzony zostal nowy graf\n";
    G.wczytaj_z_pliku();
    cout<<"MDR znalezione za pomoca algorytmu Kruskala:\n";
    G.algorytm_kruskala();
    cin>>i;
}


