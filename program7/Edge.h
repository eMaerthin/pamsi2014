//
//  Edge.h
//  PAMSI2014_7
//
//  Created by Adrian Bykowski on 03.06.2014.
//  Copyright (c) 2014 Adrian Bykowski. All rights reserved.
//

#ifndef __PAMSI2014_7__Edge__
#define __PAMSI2014_7__Edge__

#include <iostream>
#include <vector>

class Edge {
public:
    int u;
    int v;
    int f; // flow
    int fw; // flow pozostaly
    Edge * poprzednik;
};
int generujER_S(int n, float p, std::vector<Edge> & elementy, int & roz);
int generujER(int n, float p, std::vector<Edge> & elementy, int & roz);
int DodawanieKrawedzi(std::vector<Edge> & elementy, int &roz);
void Sortuj(std::vector<Edge> & tab, int roz);
void wczytywaniezpliku(const char * nazwa, std::vector<Edge> & G, std::fstream & plik, int & e, int & s,int & N);

#endif /* defined(__PAMSI2014_7__Edge__) */
