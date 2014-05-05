#include <iostream>
#include <list>
#include <fstream>
#include <queue>
#include <limits.h>
using namespace std;
ifstream plik;
ofstream plik2;
const int rozmiar=10; //maksymalna ilosc wierzcholkow grafu



struct dijkstra
{
       public:
       int macierz[rozmiar][rozmiar]; //macierz reprezentujaca graf
       int odleglosci[rozmiar]; //tablica odleglosci poszczegolnych wierzcholkow od wierzcholka poczatkowego
       int poczatek; //indeks wierzcholka poczatkowego
       bool odwiedzone[rozmiar]; //tablica zawierajaca informacje, czy wierzcholek byl juz w kolejce
       queue<int> kolejka; //kolejka wierzcholkow
       dijkstra(int &p) //konstruktor parametryczny, p-wierzcholek poczatkowy, czyli ten, od ktorego wyznaczane beda ogleglosci
       {                 	     
	   			 poczatek=p;
                 for(int i=0; i<rozmiar; i++)
                 {
                         for(int j=0; j<rozmiar; j++)    //uzupelnienie macierzy wartosciami -1, co oznacza brak polaczenia
                                 macierz[i][j]=-1;       
                                 
                         if(i==p)
                                 odleglosci[i]=0;      //uzupelnienie tablicy odleglosci wartosciami. odleglosc do poczatku jest rowna 0,
                         else                          //a odleglosc do pozostalych krawedzi zostaje oznaczona jako "nieskonczonosc" (tutaj INT_MAX)
                                 odleglosci[i]=INT_MAX;
                                 
                		odwiedzone[i]=false;          //uzupelnienie tablicy odwiedzonych wierzcholkow, na poczatku dla wszystkich wartosc ustalona na false
            	}
       }


/*metoda odpowiadajaca za wczytanie wartosci z pliku do macierzy reprezentujacej graf*/
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
       
       
/*algorytm Dijkstry*/    
       void algorytm()
       {
            int tmp;   //zmienna pomocnicza, do ktorej trafial bedzie indeks pierwszego elementu z kolejki
            kolejka.push(poczatek);   //wrzucenie na poczatek kolejki indeksu wierzcholka poczatkowego
            
            do    //petla wykonywana dopoki kolejka nie jest pusta
            {
            tmp=kolejka.front();  //do zmiennej tmp trafia pierwszy element z kolejki
            kolejka.pop();    //usuniecie pierwszego elementu z kolejki, ktory jest przypisanej do zmiennej tmp;
            for(int i=0; i<rozmiar; i++)
            {
                    if(macierz[i][tmp]!=-1&&macierz[tmp][i]!=-1)  //jezeli element macierzy jest rozny od -1, czyli istnieje polaczenie miedzy elementami
                    {
                                              
                                              if(odleglosci[i]!=INT_MAX&&odleglosci[i]>(odleglosci[tmp]+macierz[i][tmp])) //jezeli odleglosc do elementu o indeksie i zostala okreslona, ale nie jest ona najkrotsza
                                              {
                                              odleglosci[i]=odleglosci[tmp]+macierz[i][tmp];
                                              kolejka.push(i);
                                              }
                                              if(odleglosci[i]==INT_MAX) //jezeli odleglosc do elementu o indeksie i nie zostala jeszcze okreslona
                                              {
                                              	odleglosci[i]=odleglosci[tmp]+macierz[i][tmp];
                                              	if(odwiedzone[i]==false)
                                            	kolejka.push(i);
                                              }
                    }
            }
            odwiedzone[tmp]=true; //oznaczenie elementu jako wyrzuconego juz ze stosu
            }
            while(!kolejka.empty());
                    
       }
       
/*metoda odpowiadajaca za wyswietlenie odleglosci do wierzcholkow*/       
       void wyswietl()
       {
       		cout<<"Odleglosci od wierzcholka "<<poczatek<<" wynosza:\n";
       		for(int i=0; i<rozmiar; i++)
       				cout<<i<<"->"<<odleglosci[i]<<"\n";
       }
       
       
       
       
};


int main()
{
    int p;
    cout<<"Wybierz wierzcholek startowy\n";
    cin>>p;
    dijkstra dijkstra(p);
    dijkstra.wczytaj_z_pliku();
    dijkstra.algorytm();
    dijkstra.wyswietl();
}
