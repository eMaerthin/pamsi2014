//
//  Edge.cpp
//  PAMSI2014_7
//
//  Created by Adrian Bykowski on 03.06.2014.
//  Copyright (c) 2014 Adrian Bykowski. All rights reserved.
//

#include "Edge.h"
#include <ctime>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>
#include <random>
#include <ctime>
#include <fstream>
void wczytywaniezpliku(const char * nazwa, std::vector<Edge> & G, std::fstream & plik, int & e, int & s,int & N)
{
    int roz = 0;
    plik.open(nazwa, std::ios::in );
    if(plik.is_open()){
        int i(0);
        plik >> N >> roz >> s >> e;
        G.resize(roz+1);
        while(!plik.eof()){
            plik >> G[i].u >> G[i].v >> G[i].f;
            G[i].fw = G[i].f;
            i++;
        }
    } else { std::cout << "Plik nie otwarty \n"; }
    plik.close();
}

