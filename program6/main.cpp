//
//  main.cpp
//  PAMSI2014_6
//
//  Created by Adrian Bykowski on 29.04.2014.
//  Copyright (c) 2014 Adrian Bykowski. All rights reserved.
//

#include <iostream>
#include "Graf.h"
#include <queue>
#include <vector>
#include <list>
#include "AlgorytmD.h"
#include "AlgorytmBF.h"
#include <fstream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <map>
#include <iomanip>
//std::vector<std::list<int>> droga;
// ilosc wierzcholkow
int prawdo(1); int ilosc(50); int algorytm(0);bool koniec = false;
void generacja(int & N, double & p,int & menu)
{
    std::cout<<"Wprowadz liczbe wierzcholkow \n";
    std::cin>>N;
    std::cout<<"Wybierz prawdopodobienstwo \n 1. 0.25 \n 2. 0.5 \n 3. 0.75 \n 4. 1 \n";
    std::cin>>menu;
    /*
    bool test = false;
    N=ilosc;
    if(ilosc>400) {ilosc=N=50; test=true;}
    ilosc=ilosc*2;
    if(test)
    {
        prawdo++;
        if(prawdo>=5){koniec = true;}
    }
    menu=prawdo;*/
    switch(menu){
        case 1 : {p = 0.25; break;}
        case 2 : {p = 0.5; break;}
        case 3 : {p = 0.75; break;}
        case 4 : {p = 1; break;}
        case 5 : break;
        default : break;
    }
}

int main(int argc, const char * argv[])
{
    float t;
    std::vector<std::list<int>> droga;
    int N,roz,menu; //liczba wierzcholkow, rozmiar
    double p;
    std::vector<Graf> G; std::vector<int> W;
    std::cout<< "Wybierz Algorytm \n 1. Djikstry\n 2. Belmana - Forda\n";
    int opcja;
    float wynik = 0;
    std::cin>>opcja;
    bool cykl = false;
    //for(opcja = 1; opcja == 2 ; opcja++){
    switch(opcja){
        case 1: {
            koniec = false;
            std::cout << "Djikstr\n \n";
            while(!koniec){
                generacja(N, p, menu);
                generujER(N, p, G,roz);
                W.resize(N);
                droga.resize(N);
                t=clock();
                AlgorytmD(G,W,N,droga);
                t=clock()-t;
                wynik=t/CLOCKS_PER_SEC;
                std::cout <<"czas usredniony : "<< std::setprecision(5) << std::fixed << wynik << "    dla N : "<< N << " dla p :" << menu <<std::endl;

            }
            break;
        }
        case 2:{
            
            std::cout << "Bellman \n \n";
            koniec = false;
            while(!koniec){
                generacja(N, p, menu);
                generujER_S(N, p, G,roz);
                W.resize(N);
                droga.resize(N);
                t=clock();
                cykl = AlgorytmBF(G,W,N,droga);
                t=clock()-t;
                    if(!cykl){
                        ilosc = ilosc/2;
                    }else{
                        wynik=t/CLOCKS_PER_SEC;
                        std::cout <<"czas usredniony : "<< std::setprecision(5) << std::fixed << wynik << "    dla N : "<< N << " dla p :" << menu <<std::endl;
                }
            }
            break;
        }
        default: {std::cout<<"Zla opcja\n"; break;}
   // }
}
       WyswietlanieW(W,droga);
    std::cout << "Hello, World!\n";
    return 0;
}

