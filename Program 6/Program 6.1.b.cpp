#include <iostream>
#include <list>
#include <fstream>
#include <queue>
const int rozmiar=10;
using namespace std;
ifstream plik;
const int inf=10000000;
struct BF
{
       int macierz[rozmiar][rozmiar];  //macierz reprezentujaca graf'
       int odleglosci[rozmiar];  //tablica odleglosci od wierzcholka startowego
       int poczatek;    //indeks wierzcholka startowego
       queue<int> sciezka[rozmiar];  //tablica kolejek sluzaca do zapamietania drogi prowadzacej do wierzcholka
       BF(int &p)       // konstruktor parametryczny, p-wierzcholek startowy
       {
             poczatek=p;
             for (int i=0; i<rozmiar; i++)    //przy tworzeniu obiektu cala macierz wypelniana jest wartosciami -1, co oznacza brak polaczen
                 for(int j=0; j<rozmiar; j++) 
                         macierz[i][j]=-1;
             for(int i=0; i<rozmiar; i++)  //odleglosci deklarowane sa jako nieskonczonosc...
                     odleglosci[i]=inf;
             odleglosci[p]=0;  // ... za wyjatkiem odleglosci "od poczatku do poczatku", ktora rowna jest 0;
             
             for(int i=0; i<rozmiar; i++)
             sciezka[i].push(i);  //umieszczenie w kolejce elementow prowadzacych do elementu i, elementu i (oznacza to, ze jedyna droga do tego elementu jest tylko on sam)
       }       
       
       
       
       
       //metoda odpowiadajaca za wczytanie grafu z pliku tekstowego
       void wczytaj_z_pliku()
       {
            cout<<"Wczytywanie danych z pliku tekstowego\n";
            plik.open("nazwa2.txt");
            int k=0;
            if(plik.good())
            {
                           cout<<"Plik zostal otwarty pomyslnie\n";
                           while(!plik.eof())
                           {
                           int i,j,w;
                           plik>>i;
                           plik>>j;
                           plik>>w;
                                                 
                           macierz[i][j]=w;
                           macierz[j][i]=w;
                           }
            }
            else
            cout<<"Nie udalo sie otworzyc pliku\n";
       }
       
       void algorytm()
       {
       for(int n=0; n<rozmiar; n++)   //glowna petla programu, zgodnie z algorytmem wykonywana n-1 razy
            for(int i=0; i<rozmiar; i++) //petle z licznikami i oraz j odpowiadaja za przegladanie calej macierzy
                    for(int j=0; j<rozmiar; j++)
                            if(macierz[i][j]!=-1) //jezeli wierzcholki o indeksach i oraz j sa sasiadami (czyli element macierzy o indeksach i, j jest rozny od -1)
                                       if(odleglosci[i]>(odleglosci[j]+macierz[i][j]))  //jezeli odleglosc mozna zmniejszyc;
                                       {
                                                     odleglosci[i]=odleglosci[j]+macierz[i][j];   // zmiana odleglosci
                                                     sciezka[i]=sciezka[j];  //zmiana sciezki prowadzacej do wierzcholka
                                                     sciezka[i].push(i);
                                       }   
       }
       // metoda odpowiadajaca za wyswietlenie najkrotszej drogi od wierzcholka startowego do kazdego z wierzcholkow, a takze drogi doprowadzajacej
       void wyswietl()
       {
            cout<<"Odleglosci od wierzcholka "<<poczatek<<" wynosza:\n";
            for(int i=0; i<rozmiar; i++)
            {
            cout<<i<<"->"<<odleglosci[i]<<" droga: ";
            while(!sciezka[i].empty())
            {
                                      cout<<sciezka[i].front()<<" ";
                                      sciezka[i].pop();
            }
            cout<<"\n";
            }
       }
       
       
};




int main()
{
    int p;
    cout<<"Wybierz wierzcholek startowy\n";
    cin>>p;
    BF BF(p);
    BF.wczytaj_z_pliku();
    BF.algorytm();
    BF.wyswietl();
    cin>>p;
}

