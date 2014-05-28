//
//  kruskal.cpp
//  PAMSI_testy
//
//  Created by Adrian Bykowski on 29.04.2014.
//  Copyright (c) 2014 Adrian Bykowski. All rights reserved.
//

#include "kruskal.h"

int Kruskal(Graf & test, int & _ilosc_drzew, std::vector<_drzewo_lista> & drzewo)
{
    int nalezy1(-1),nalezy2(-1);
    Graf x;
    
    // sprawdza w ktorym drzewie znajduje sie dana krawedz
    for(int i(1); i<=_ilosc_drzew ; i++){
        for(_drzewo_lista::iterator iter = drzewo[i].begin(); iter!=drzewo[i].end(); iter++){
            x = *iter;
            if(nalezy1 == -1) {
                if (test.pierwszy == x.pierwszy || test.pierwszy == x.drugi)
                    nalezy1 = i;
            }                                                               // bug !! !!! dodaje kilka razy to samo
            
            if(nalezy2 == -1) {
                if (test.drugi == x.pierwszy || test.drugi == x.drugi)
                    nalezy2 = i;

            }
        }
    }
    // nie nalezy do drzew, tworzy nowe drzewo return -1
    if(nalezy1==-1 && nalezy2==-1){
        _ilosc_drzew++;
        drzewo.resize(_ilosc_drzew+1);
        drzewo[_ilosc_drzew].push_back(test);
        return -1;
    }
    
    // krawedz zbedna return 0
    else if(nalezy1==nalezy2){
        return 0;
    }
    
    // laczy dwa drzewa return 2
    else if(nalezy1 != -1 && nalezy2 != -1){
        drzewo[nalezy1].push_back(test);
        drzewo[nalezy1].sort(); drzewo[nalezy2].sort();
        drzewo[nalezy1].merge(drzewo[nalezy2]);
        drzewo[nalezy2]=drzewo[_ilosc_drzew];
        drzewo[_ilosc_drzew].clear();
        drzewo.resize(_ilosc_drzew);
        _ilosc_drzew--;
        return 2;
    }
    
    //dodaje element do drzewa return 1
    else if (nalezy1 != -1){
        drzewo[nalezy1].push_back(test);
        return 1;
    }
    else if (nalezy2 != -1){
        drzewo[nalezy2].push_back(test);
        return 1;
    }
    
    return 0;
}
void AlgorytmK(std::vector<std::list<Graf>> & drzewo,std::vector<Graf> & tab,int & roz)
{
    int _ilosc_drzew(0);
    for(int i(0) ; i<roz ; i++){ // sprawdzanie posczegolnych krawedzi z tab[]
        Kruskal(tab[i], _ilosc_drzew, drzewo);
    }
}