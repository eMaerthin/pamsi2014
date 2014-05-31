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
//std::vector<std::list<int>> droga;
// ilosc wierzcholkow
int prawdo(4); int ilosc(500); int algorytm(0);bool koniec = false;
void generacja(int & N, double & p,int & menu)
{
    std::cout<<"Wprowadz liczbe wierzcholkow \n";
    std::cin>>N;
    std::cout<<"Wybierz prawdopodobienstwo \n 1. 0.25 \n 2. 0.5 \n 3. 0.75 \n 4. 1 \n";
    std::cin>>menu;
    
    //bool test = false;
    //N=ilosc;
    //if(ilosc>4000) {ilosc=N=500; test=true;}
    //ilosc=ilosc*2;
    //if(test)
    //{
    //    prawdo++;
    //    if(prawdo>5){koniec = true;}
    //}
    //menu=prawdo;
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
    std::vector<std::list<int>> droga;
    int N,roz,menu; //liczba wierzcholkow, rozmiar
    double p;
    std::vector<Graf> G; std::vector<int> W;
    //N = DodawanieKrawedzi(G, roz);
    generacja(N, p, menu);
    generujER(N, p, G,roz);
    W.resize(N);
    droga.resize(N);
    AlgorytmD(G,W,N,droga);
    WyswietlanieW(W,droga);
    std::cout << "Hello, World!\n";
    return 0;
}

