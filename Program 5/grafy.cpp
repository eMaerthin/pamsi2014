/*Program wczytujacy graf z pliku tekstowego, a nastepnie zapisujacy go w postaci listy oraz macierzy do plikow tekstowych*/

#include <iostream>
#include <list>
#include <fstream>
using namespace std;
ifstream plik;
ofstream plik2;
const int rozmiar=100; //Rozmiar grafu - ilosc wierzcholkow

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




struct graf
{
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
            plik.open("nazwa.txt");   // nazwa pliku zawierajacego dane wejsciowe
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
       
       
       
       void zapisz_macierz()
       {
            cout<<"Zapisywanie tablicy do pliku tekstowego\n";
            plik2.open("macierz.txt");
            if(plik2.good())
            {
                            cout<<"Plik do zapisu zostal otworzony pomyslnie\n";
                             for (int i=0; i<rozmiar; i++)
                             {
                                           for(int j=0; j<rozmiar; j++)
                                           {
                                           plik2<<macierz[i][j]<<" ";
                                           cout<<macierz[i][j]<<" ";
                                           }
                                           plik2<<"\n";
                                           cout<<"\n";
                             }
                             plik2.close();
            }
            else
            {
                cout<<"Nie udalo sie zapisac do pliku\n";
            }
       }
       
       
       void zapisz_liste()
       {
            cout<<"Zapisywanie listy do pliku tekstowego\n";
            plik2.open("lista.txt");
            if(plik2.good())
            {
                            cout<<"Plik do zapisu zostal otworzony pomyslnie\n";
                            for(int i=0; i<rozmiar; i++)
                            {
                              plik2<<i;
                              cout<<i;
                              while(!lista[i].empty())
                              {
                                            plik2<<lista[i].front();
                                            cout<<lista[i].front();
                                            lista[i].pop_front();
                              }
                              plik2<<"\n";
                              cout<<"\n";
                            }
            plik2.close();
            }
       }
       
};



int main()
{
    int i;
    graf G;
    cout<<"Utworzony zostal nowy graf\n";
    G.wczytaj_z_pliku();
    cout<<"Graf w postaci macierzy wczytany z pliku:\n";
    G.zapisz_macierz();
    cout<<"Graf w postaci listy (w nawiasach zamieszczone sa wagi):\n";
    G.zapisz_liste();
    cin>>i;
}

