//
//  AlgorytmEK.cpp
//  PAMSI2014_7
//
//  Created by Adrian Bykowski on 08.06.2014.
//  Copyright (c) 2014 Adrian Bykowski. All rights reserved.
//

#include "AlgorytmEK.h"
#include "Edge.h"
#include <fstream>
#include <queue>
extern std::vector<int> prev;
inline int min(int a, int b) { return a < b ? a : b; }
std::list<Edge*>  bfs (int s, int e, std::vector<Edge> & Graf, int & N){ // s - start e - end
    
    std::queue<int> kolejka;        // kolejka do przechowywania kolejnych wierzcholkow
    std::vector<int> dodane;        // pierw dodajemy ze startu
    std::vector<int> wartosc;
    wartosc.resize(N);              // przypisywane do wierzcholka wartosc
    std::vector<std::list<Edge*>> droga;
    droga.resize(N);
    for(std::vector<int>::iterator it = wartosc.begin(); it != wartosc.end(); it++)
    {
        *it = 20000000; // inf
    }
    wartosc[s]=0;
    kolejka.push(s);
    dodane.push_back(s);
    int x;
    Edge z;
    bool test = true;
    //
    
    
    while(!kolejka.empty()){
        x=kolejka.front();
        kolejka.pop();
        for(std::vector<Edge>::iterator it = Graf.begin(); it!=Graf.end(); it++ ){
            z = *it;
            if(z.u == x && z.fw > 0){
                
                /////// sprawdzanie drogi
                if(wartosc[z.v] > (wartosc[x]+1)){
                    
                    wartosc[z.v]=wartosc[x]+1;
                    prev[z.v]=x;
                }
                //////////////////////////
                
                /////// dodawanie kolejnych elementow
                for(std::vector<int>::iterator it = dodane.begin(); it!=dodane.end(); it++){
                    if(z.v == *it) {test = false;}
                }
                if(test){
                    dodane.push_back(z.v);
                    kolejka.push(z.v);
                }
                test = true;
                //////////////////////////////////////
            }
        }
    }
    return droga[e]; // zwracanie najkrotczej drogi do konca
}



int AlgorytmEK( std::vector<Edge> & Graf,int &e, int &s , int & N)
{
    int fmax(0); // zmienna zawierajaca przeplyt max
    int flow_droga;
    int tester = 1;
    std::list<Edge*> Droga;
    std::vector<Edge>::iterator it = Graf.begin();
    int d = e;
    while(tester)
    {
        flow_droga = 2000000000; // inf
        Droga = bfs(s,e,Graf,N);
        d = e;
        tester = 1;
        if(tester){
            
            
            while(it!=Graf.end()){
                if((*it).u == prev[d] && (*it).v == d){
                    d = prev[d];
                    flow_droga = min(flow_droga,(*it).fw);
                    it = Graf.begin();
                    continue;
                }
                if(d==s){ break;}
                it++;
            }
            d=e;
            while(it!=Graf.end()){
                if((*it).u == prev[d] && (*it).v == d){
                    d = prev[d];
                    (*it).fw -= flow_droga;
                    it = Graf.begin();
                    continue;
                }
                if(d==s){ break;}
                it++;
            }
            fmax+=flow_droga;
            if(flow_droga==0){break;}
        }
    }
    return fmax;
}

