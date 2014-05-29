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
    Graf x;
    int i;
    bool z = false;
    for(std::vector<int>::iterator it = W.begin()+1; it!=W.end(); it++) // przypisanie wierzcholka wartosci -1
    {
        *it=2000000;                // inf
    }
    W[0]=0;                         // USTAWIENIE STARTU
    std::vector<int> dodane(N);     // tutaj dodane już wierzcholki ktore nie beda uwzgledniane
    dodane.push_back(0);            // dodanie pierwszego elementu
    std::queue<int> kolejka;        // deklaracja kolejki
    kolejka.push(0);                // dodawanie pierwszego elementu
    for (i = kolejka.front(); !kolejka.empty();i = kolejka.front()) {   // petla zdejmowania elementow z kolejki i przypisujaca                                      zmiennej i wartosc z kolejki
        kolejka.pop();                                                      // usuwanie elementu ktory zostal zdjety
        for(std::vector<Graf>::iterator it = G.begin(); it!=G.end(); it++){ //szukanie elementow w drzewie ktore sa sasiadujace i moga posiadac krotsza droge
            x=*it;  // przypisanie wartosci do zmiennej pomocniczej
            if(x.pierwszy==i){
                if(W[x.drugi]>x.waga+W[i]){
                    W[x.drugi]=x.waga+W[i];
                    
                    
                    droga[x.drugi].clear();
                    for(std::list<int>::iterator iter = droga[i].begin(); iter != droga[i].end(); iter ++){
                        droga[x.drugi].push_back(*iter);
                    }
                    droga[x.drugi].push_back(i);
                    
                    
                }
                z = true;
                for(std::vector<int>::iterator it2 = dodane.begin(); it2!=dodane.end();it2++){
                    if(*it2 == x.drugi) { z=false; }
                }
                if(z){
                    kolejka.push(x.drugi);
                    dodane.push_back(x.drugi);
                }
            }
            else {
                if(x.drugi==i){
                    if(W[x.pierwszy]>x.waga+W[i]){
                        W[x.pierwszy]=x.waga+W[i];
                        droga[x.pierwszy].clear();
                        for(std::list<int>::iterator iter = droga[i].begin(); iter != droga[i].end(); iter ++){
                            droga[x.pierwszy].push_back(*iter);
                        }
                        droga[x.pierwszy].push_back(i);
                    }
                z = true;
                for(std::vector<int>::iterator it3 = dodane.begin(); it3!=dodane.end();it3++){
                    if(*it3 == x.pierwszy) { z=false; }
                }
                if(z){
                    kolejka.push(x.pierwszy);
                    dodane.push_back(x.pierwszy);
                }
            }
            }
        }
    }
}
//droga[x.drugi].clear();
//for(std::list<int>::iterator iter = droga[i].begin(); iter != droga[i].end(); iter ++){
//    droga[x.drugi].push_back(*iter);
//}
//droga[x.drugi].push_back(i);