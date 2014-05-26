//
//  main.cpp
//  PAMSI_testy
//
//  Created by Adrian Bykowski on 28.04.2014.
//  Copyright (c) 2014 Adrian Bykowski. All rights reserved.
//

#include <iostream>
#include <list>
#include <vector>
#include "Graf.h"
#include "kruskal.h"
#include "Prime.h"
#include <fstream>

//DodawanieKrawedzi(elementy, roz);


int main(int argc, const char * argv[])
{
    std::vector<_drzewo_lista> drzewa;
    std::vector<Graf> elementy;
    int ile=0;
    Graf te; // do wyswietlania wagi
    int menu(0); // zmienna dla wybierania menu
    int roz(0);
    std::fstream plik;
    while(1){
        std::cout << "Wybierz graf do wczytania \n 1. 10  \n 2. 100 " << std::endl;
        std::cin >> menu;
        switch(menu)
        {
            case 1 : {wczytywaniezpliku("/Users/rhyre_Mac/Desktop/graf10.txt", elementy, roz, plik); break;}
            case 2 : {wczytywaniezpliku("/Users/rhyre_Mac/Desktop/graf100.txt", elementy, roz, plik); break;}
            default: continue;
        }
        std::cout << "Wybierz algorytm \n 1. Prime \n 2. Kruskal" << std::endl;
        std::cin >> menu;
        switch(menu)
        {
            case 1 : {drzewa.resize(1); Sortuj(elementy, roz); AlgorytmP(drzewa, elementy,roz); break;}
            case 2 : {Sortuj(elementy, roz); AlgorytmK(drzewa, elementy,roz);drzewa[1].sort();drzewa[0].merge(drzewa[1]); break;}
            default: continue;
        }
        break;
    }

    for(std::list<Graf>::iterator iter = drzewa[0].begin(); iter!=drzewa[0].end(); iter++)
    {
        te = *iter;
        ile += te.waga;
    }
    std::cout  << "waga : " << ile << std::endl;
    return 0;
}

