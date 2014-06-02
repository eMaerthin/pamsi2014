//
//  AlgorytmD.cpp
//  PAMSI2014_6
//
//  Created by Adrian Bykowski on 29.05.2014.
//  Copyright (c) 2014 Adrian Bykowski. All rights reserved.
//

#include "AlgorytmD.h"
#include <iomanip>
void WyswietlanieW(std::vector<int> &W, std::vector<std::list<int>> droga)
{
    int i(1);
    for(std::vector<int>::iterator it = W.begin()+1; it!=W.end(); it++, i++){
        std::cout << "Start -> " << std::setw(3) <<i << " : " << std::setw(3) <<*it << " droga : ";
        for(std::list<int>::iterator d = droga[i].begin(); d!=droga[i].end() ;d++)
        {
            std::cout << *d;
            if ( ++d!=droga[i].end())
            { std::cout << " - "; }
            d--;
        }
        std::cout << std::endl;
    }
}

void AlgorytmD(std::vector<Graf>& G, std::vector<int>&W, int & N, std::vector<std::list<int>> & droga){
    for(std::vector<int>::iterator it = W.begin()+1; it!=W.end(); it++) // przypisanie wierzcholka wartosci -1
    {
        *it=2000000;                // inf
    }
    W[0]=0;                         // USTAWIENIE STARTU
    
    for(int i=1; i<N; i++){ //wykonujemy N-1 przebiegow
        for(int j=0; j<G.size(); j++){ // G.size -> ilosc krawedzi
            if(W[G[j].pierwszy] > W[G[j].drugi] + G[j].waga){ //sprawdzanie czy ma nastapic relaksacja
                W[G[j].pierwszy] = W[G[j].drugi] + G[j].waga; // relaksacja
                droga[G[j].pierwszy].clear(); // czyszczenie drogi
                for(std::list<int>::iterator iter = droga[G[j].drugi].begin(); iter != droga[G[j].drugi].end(); iter ++){ // dodawanie drogi
                    droga[G[j].pierwszy].push_back(*iter);
                }
                droga[G[j].pierwszy].push_back(G[j].drugi);
            } // drugi if dla odwrotnej sytuacji gdyz graf jest nieskierowany
            if(W[G[j].drugi] > W[G[j].pierwszy] + G[j].waga){ //sprawdzanie czy ma nastapic relaksacja
                W[G[j].drugi] = W[G[j].pierwszy] + G[j].waga; // relaksacja
                droga[G[j].drugi].clear(); // czyszczenie drogi
                for(std::list<int>::iterator iter = droga[G[j].pierwszy].begin(); iter != droga[G[j].pierwszy].end(); iter ++){ // dodawanie drogi
                    droga[G[j].drugi].push_back(*iter);
                }
                droga[G[j].drugi].push_back(G[j].pierwszy);
            }
        }
    }
   }