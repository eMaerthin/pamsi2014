//
//  Graf.cpp
//  PAMSI2014_6
//
//  Created by Adrian Bykowski on 29.04.2014.
//  Copyright (c) 2014 Adrian Bykowski. All rights reserved.
//

#include "Graf.h"
double rjedn()
{
    std::random_device rd;
    std::mt19937 e2(rd());
    std::uniform_real_distribution<double> uni(0,1);
    return uni(e2);
}
int generujER_S(int n, float p, std::vector<Graf> & elementy, int & roz)
{
    Graf z,y;
    int v = 1; 
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
                y.drugi=v;
                y.pierwszy=w;
                z.drugi=w;
                z.waga = rand()%1010-10;
                roz++;
                y.waga=rand()%1010-10;
                elementy.resize(roz);
                elementy.push_back(z);
                roz++;
                elementy.resize(roz);
                elementy.push_back(y);
            }
            
        }
    }
    elementy[0]=elementy[roz];
    elementy.pop_back();
    return 1;
}
int generujER(int n, float p, std::vector<Graf> & elementy, int & roz)
{
    Graf z;
    int v = 1;
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
                z.waga = rand()%500;
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

int DodawanieKrawedzi(std::vector<Graf> & elementy, int &roz)
{
	// petla o ilosc krawedzi
    int V,gestosc,E;
    std::cout << "Wprowadz ilosc wierzcholkow: ";
    std::cin >> V;
    std::cout << "Wprowadz gestosc grafu(0-100)%: ";
    std::cin >> gestosc;
    E = (((V*(V-1))/2)*gestosc)/100;
    int tablica[1000][1000];
    for(int i(0);i<1000;i++)
        for(int j(0);j<1000;j++)
            tablica[i][j]=0;
    Graf x;
	for( int k = 0; k < E; ){
		int n = rand() % V + 0;
		int m = rand() % V + 0;
		if( n != m && tablica[n][m] == 0 && tablica[m][n] == 0){
			x.waga = rand() % 9 + 1;
			tablica[n][m] =x.waga;
            tablica[m][n] =x.waga;
            x.pierwszy=n;
            x.drugi=m;
            elementy.resize(k+1);
            elementy[k]=x;
			k++;
            roz++;
        }
        
	}
	return V;
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
