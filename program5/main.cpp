//
//  main.cpp
//  PAMSI_testy
//
//  Created by Adrian Bykowski on 28.04.2014.
//  Copyright (c) 2014 Adrian Bykowski. All rights reserved.
//
#define ILE 1.0
#include <iostream>
#include <list>
#include <vector>
#include "Graf.h"
#include "kruskal.h"
#include "Prime.h"
#include <fstream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <map>
#include <iomanip>
int prawdo(4); int ilosc(500); int algorytm(0);bool koniec = false;
//DodawanieKrawedzi(elementy, roz);
void generacja(int & N, double & p,int & menu)
{
    //std::cout<<"Wprowadz liczbe wierzcholkow \n";
    //std::cin>>N;
    bool test = false;
    N=ilosc;
    if(ilosc>4000) {ilosc=N=500; test=true;}
    ilosc=ilosc*2;
    //std::cout<<"Wybierz prawdopodobienstwo \n 1. 3log2(n)/n \n 2. n^-1/3 \n 3. n^-1/2 \n 4. Graf Pelny \n";
    //std::cin>>menu;
    
    if(test)
    {
        prawdo++;
        if(prawdo>5){koniec = true;}
    }
    menu=prawdo;
    switch(menu){
            case 1 : {p = (3*log2(N))/N; break;}
            case 2 : {p = pow((double)N,-1.0/3.0); break;}
            case 3 : {p = pow((double)N,-1.0/2.0); break;}
            case 4 : {p = 1; break;}
            case 5 : break;
        default : break;
    }
}

int main(int argc, const char * argv[])
{
    std::vector<_drzewo_lista> drzewa;
    std::vector<Graf> elementy;
    int ile(0); int N(0); double p;
    Graf te; // do wyswietlania wagi
    //int menu(0); // zmienna dla wybierania menu
    int roz(0);
    clock_t t = 0;
    std::fstream plik;
    //int j=0;
    int pr(0);
    double wynik(0);
    double wyniki[100];
    while(!koniec){
        // std::cout << "Wybierz graf do wczytania \n 1. 10  \n 2. 100 \n 3. Generowanie" << std::endl;
        // std::cin >> menu;
        //switch(menu) // wybor grafu
        //{
        //    case 1 : {wczytywaniezpliku("/Users/rhyre_Mac/Desktop/graf10.txt", elementy, roz, plik); break;}
        //    case 2 : {wczytywaniezpliku("/Users/rhyre_Mac/Desktop/graf100.txt", elementy, roz, plik); break;}
        //    case 3 : {generacja(N,p,pr); generujER(N, p, elementy,roz); break;}
        //    default: continue;
        //}
        // std::cout << "Wybierz algorytm \n 1. Prime \n 2. Kruskal" << std::endl;
        // std::cin >> menu;
        generacja(N,p,pr);
        generujER(N, p, elementy,roz);
        //DodawanieKrawedzi(elementy, roz);
        //switch(1)
        //{
        //    case 1 : {drzewa.resize(1); Sortuj(elementy, roz);t=clock(); AlgorytmP(drzewa, elementy,roz);  t=clock()-t; break;}
        //    case 2 : {Sortuj(elementy, roz); AlgorytmK(drzewa, elementy,roz);drzewa[1].sort();drzewa[0].merge(drzewa[1]); break;}
        //    default: continue;
        //}
        drzewa.resize(1);
        quicksort(elementy, 0, elementy.size());
        t=clock();
        //AlgorytmK(drzewa, elementy,roz);
        AlgorytmP(drzewa, elementy,roz);
        t=clock()-t;
        //drzewa[1].sort();
        // drzewa[0].merge(drzewa[1]);
        wyniki[1]=t;
        wynik=wyniki[1]/CLOCKS_PER_SEC;
        std::cout <<"czas usredniony : "<< std::setprecision(5) << std::fixed << wynik << "    dla N : "<< N << " dla p :" << pr <<std::endl;
        //j++;
        for(std::list<Graf>::iterator iter = drzewa[0].begin(); iter!=drzewa[0].end(); iter++)
        {
            te = *iter;
            ile += te.waga;
        }
        std::cout  << "waga : " << ile << std::endl;
        elementy.clear(); elementy.resize(0);
        drzewa.clear(); drzewa.resize(0);
        roz = 0;
        //break;
    }
   // for(int i(0);i<ILE;i++){
   //     wynik+=wyniki[i]/CLOCKS_PER_SEC;
   // }
   // wynik=wynik/ILE;
   // std::cout <<"czas usredniony : "<< std::setprecision(5) << std::fixed << wynik << "     dla N : "<< N << " dla p :" << pr <<std::endl;
   // for(std::list<Graf>::iterator iter = drzewa[0].begin(); iter!=drzewa[0].end(); iter++)
   // {
   //     te = *iter;
   //     ile += te.waga;
   // }
   // std::cout  << "waga : " << ile << std::endl;
   //generujER(10, 1, elementy,roz);

    return 0;
}

