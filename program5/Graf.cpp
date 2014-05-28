//
//  Graf.cpp
//  PAMSI_testy
//
//  Created by Adrian Bykowski on 29.04.2014.
//  Copyright (c) 2014 Adrian Bykowski. All rights reserved.
//

#include "Graf.h"
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <vector>
double rjedn()
{
    std::random_device rd;
    std::mt19937 e2(rd());
    std::uniform_real_distribution<double> uni(0,1);
    return uni(e2);
}
int generujER(int n, float p, std::vector<Graf> & elementy, int & roz)
{
    //if p <= 0 or p >= 1:
    Graf z;
    int v = 1;  // Nodes in graph are from 0,n-1 (this is the second node index).
    int w = -1;
    float lp = log(1.0 - p);
    float lr;
    elementy.clear();
    while (v < n){
        lr = log(1.0 - rjedn());
        w = w + 1 + int(lr/lp);
        while (w >= v && v < n){
            w = w - v;
            v = v + 1;
        }
        if (v < n)
        {
            if(v != w){
            z.pierwszy=v;
            z.drugi=w;
            z.waga= rand()%100;
            roz++;
            elementy.resize(roz);
            elementy.push_back(z);
            }
            
        }
    }
    elementy[0]=elementy[roz];
    elementy.pop_back();
    return 1;
}

using namespace std;
void DodawanieKrawedzi(std::vector<Graf> & elementy, int &roz)
{
	// petla o ilosc krawedzi
    int V,gestosc,E;
    //std::cout << "Wprowadz ilosc wierzcholkow: ";
    std::cin >> V;
    //std::cout << "Wprowadz gestosc grafu(0-100)%: ";
    //std::cin >> gestosc;
    gestosc=100;
    E = (((V*(V-1))/2)*gestosc)/100;
    int tablica[2000][2000];   // tutaj !!! !!
    for(int i(0);i<2000;i++)
        for(int j(0);j<2000;j++)
            tablica[i][j]=0;
    Graf x;
	for( int k = 0; k < E; ){
		int n = rand() % V + 0;
		int m = rand() % V + 0;
		if( n != m && tablica[n][m] == 0 ){
			x.waga = rand() % 9 + 1;
			tablica[n][m] =x.waga;
            x.pierwszy=n;
            x.drugi=m;
            elementy.resize(k+1);
            elementy[k]=x;
			k++;
            roz++;
            //std::cout << "dodano krawedz" << std::endl;
		}
        
	}
	
}


void swapx( Graf& a, Graf& b )
{
    Graf temp = a;
    a = b;
    b = temp;
}
void quicksort( std::vector<Graf>& tab, long lewy, long prawy )
{
    long i = lewy;
    long j = prawy;
    double x = tab[( lewy + prawy ) / 2 ].waga;
    do
    {
        while( tab[ i ].waga < x )
            i++;
        
        while( tab[ j ].waga > x )
            j--;
        
        if( i <= j )
        {
            swap( tab[ i ], tab[ j ] );
            
            i++;
            j--;
        }
    } while( i <= j );
    
    if( lewy < j ) quicksort( tab, lewy, j );
    
    if( prawy > i ) quicksort( tab, i, prawy );
    
}

void Sortuj(std::vector<Graf> & tab, int roz)
{
    int x = 1;
    while(x){
        x = 0;
        for(int i = 0; i<roz-1;i++){
            if(tab[i].waga>tab[i+1].waga){
                swapx(tab[i],tab[i+1]);
                x = 1;
            }
        }
    }
}
void wczytywaniezpliku(const char * nazwa, std::vector<Graf> & G, int & roz, std::fstream & plik)
{
    plik.open(nazwa, std::ios::in );
    if(plik.is_open()){
        int i(0);
        while(!plik.eof()){
             G.resize(roz+1);
           // plik >> G[i];
            plik >> G[i].pierwszy >> G[i].drugi >> G[i].waga;
            i++; roz++;
           
        }
   } else { std::cout << "Plik nie otwarty \n"; }
    plik.close();
}



