//
//  AlgorytmBF.cpp
//  PAMSI2014_6
//
//  Created by Adrian Bykowski on 02.06.2014.
//  Copyright (c) 2014 Adrian Bykowski. All rights reserved.
//

#include "AlgorytmBF.h"

void AlgorytmBF(std::vector<Graf>& G, std::vector<int>&W, int & N, std::vector<std::list<int>> & droga){
    int i;
    bool z = false;
    for(std::vector<int>::iterator it = W.begin()+1; it!=W.end(); it++) // przypisanie wierzcholka wartosci INF
    {
        *it=2000000;                // inf
    }
    W[0]=0; // start

    for(int i=1; i<N; i++){ //wykonujemy N-1 przebiegow
        for(int j=0; j<G.size(); j++){ // G.size -> ilosc krawedzi
            if(W[G[j].pierwszy] > W[G[j].drugi] + G[j].waga){ //sprawdzanie czy ma nastapic relaksacja
                W[G[j].pierwszy] = W[G[j].drugi] + G[j].waga; // relaksacja
                droga[G[j].pierwszy].clear(); // czyszczenie drogi
                for(std::list<int>::iterator iter = droga[G[j].drugi].begin(); iter != droga[G[j].drugi].end(); iter ++){ // dodawanie drogi
                    droga[G[j].pierwszy].push_back(*iter);
                }
                droga[G[j].pierwszy].push_back(G[j].drugi);
            }
        }
    }
    
    for(int i=0; i<G.size(); i++){ // sprawdzenie wystepowania cyklu
        if(W[G[i].pierwszy] > W[G[i].drugi] + G[i].waga) std::cout << "wystapil cykl \n";
    }}
