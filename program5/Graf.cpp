//
//  Graf.cpp
//  PAMSI_testy
//
//  Created by Adrian Bykowski on 29.04.2014.
//  Copyright (c) 2014 Adrian Bykowski. All rights reserved.
//

#include "Graf.h"
#include <fstream>

using namespace std;
void DodawanieKrawedzi(std::vector<Graf> & elementy, int &roz)
{
	// petla o ilosc krawedzi
    int V,gestosc,E;
    std::cout << "Wprowadz ilosc wierzcholkow: ";
    std::cin >> V;
    std::cout << "Wprowadz gestosc grafu(0-100)%: ";
    std::cin >> gestosc;
    E = (((V*(V-1))/2)*gestosc)/100;
    int tablica[1000][1000];   // tutaj !!! !!
    for(int i(0);i<1000;i++)
        for(int j(0);j<1000;j++)
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
            std::cout << "dodano krawedz" << std::endl;
		}
        
	}
	
}


void swapx( Graf& a, Graf& b )
{
    Graf temp = a;
    a = b;
    b = temp;
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



