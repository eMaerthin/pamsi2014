#include <iostream>
#include <list>
#include <fstream>
#include <boost/progress.hpp>
using namespace std;
ifstream plik;
ofstream plik2;
const int rozmiar=200;
const int inf=10000000;

struct FF
{
       int C[rozmiar][rozmiar]; //macierz przepustowosci krawedzi
       int F[rozmiar][rozmiar]; //macierz przeplywow w krawedziach
       int poprzedni[rozmiar]; //tablica poprzednikow na sciezkach tworzonych przez BFS
       int przepust[rozmiar]; //tablica przepustowosci sciezek;
       int zrodlo, ujscie;
       int fmax,wyjdz,v1,v2,w;
       list<int> kolejka;
       FF(int &z, int &u)
       {
             zrodlo=z;
             ujscie=u;
             
             for(int i=0; i<rozmiar; i++)
                     for(int j=0; j<rozmiar; j++)
                             F[i][j]=C[i][j]=0;
       }
       
       void wczytaj_z_pliku()
       {
            //cout<<"Wczytywanie danych z pliku tekstowego\n";

            //int k=0;
            if(plik.good())
            {
                         //  cout<<"Plik zostal otwarty pomyslnie\n";
                           while(!plik.eof())
                           {
                           int i,j,w;
                           plik>>i;
                           plik>>j;
                           plik>>w;
                                                
                           C[i][j]=w;
                           }
            }
            else
            cout<<"Nie udalo sie otworzyc pliku\n";
       }
       
       
       void algorytm()
       {
            fmax=0;
            do
            {
                   for(int i=0; i<rozmiar; i++)
                           poprzedni[i]=0;
                   poprzedni[zrodlo]=-1;
                   przepust[zrodlo]=inf;
                   kolejka.clear();
                   kolejka.push_back(zrodlo);
                   wyjdz=0;
                   while(kolejka.size()&&!wyjdz)
                   {
                                  v1=kolejka.front();
                                  kolejka.pop_front();
                                  for(v2=0;v2<rozmiar;v2++)
                                  {
                                                        w=C[v1][v2]-F[v1][v2];
                                                        if(w && !poprzedni[v2])
                                                        {
                                                              poprzedni[v2]=v1;
                                                              if(przepust[v1]>w)
                                                              	przepust[v2]=w;
                                                              else
                                                              	przepust[v2]=przepust[v1];
                                                              if(v2==ujscie)
                                                              {
                                                                           fmax+=przepust[ujscie];
                                                                           while(v2!=zrodlo)
                                                                           {
                                                                                           v1=poprzedni[v2];
                                                                                           F[v1][v2]+=przepust[ujscie];
                                                                                           F[v2][v1]-=przepust[ujscie];
                                                                                           v2=v1;
                                                                           }
                                                              wyjdz=1; break;
                                                              }
                                                        kolejka.push_back(v2);      
                                                        }
                                  }
                   }
            }
            while(wyjdz);
       }
       
       
       void wyswietl()
       {

           /* for(x=0; x<rozmiar; x++)
                     for(y=0; y<rozmiar; y++)
                             if(C[x][y])
                                        cout<<x<<"->"<<y<<" "<<F[x][y]<<"/"<<C[x][y]<<"\n";*/
                        cout<<"fmax="<<fmax<<"\n";
       }           
       void zapisz()
       {
            plik2.open("FF.txt");
            plik2<<"fmax="<<fmax<<"\n";
            for(v1=0; v1<rozmiar; v1++)
                     for(v2=0; v2<rozmiar; v2++)
                             if(C[v1][v2])
                                        plik2<<v1<<"->"<<v2<<" "<<F[v1][v2]<<"/"<<C[v1][v2]<<"\n";
       }    
       
};

int main()
{
    int v,e,s,u;
    float czas=0;
    for(int i=0;i<10;i++)
    {
    plik.open("2k100-35.txt");
    plik>>v>>e>>s>>u;
    FF FF(s,u);
    FF.wczytaj_z_pliku();
    boost::timer t1;
	FF.algorytm();
	czas+=t1.elapsed();
	plik.close();
	FF.wyswietl();
	}
	cout<<czas/10;

    //FF.zapisz(); 
}

