//
//  Graf.h
//  PAMSI_testy
//
//  Created by Adrian Bykowski on 29.04.2014.
//  Copyright (c) 2014 Adrian Bykowski. All rights reserved.
//

#ifndef __PAMSI_testy__Graf__
#define __PAMSI_testy__Graf__

#include <iostream>
#include <vector>
#include <fstream>
class Graf
{
public:
    int waga;
    int pierwszy;
    int drugi;
    bool operator < (const Graf& test) const
    {
        return waga < test.waga;
    }
    friend std::istream& operator>>(std::istream& in, Graf& G) // input
    {
        in >> G.pierwszy >> G.drugi >> G.waga;
        return in;
    }
    friend std::ostream& operator<<(std::ostream& in, Graf& G) // input
    {
        in << G.pierwszy << G.drugi << G.waga;
        return in;
    }
};
void quicksort( std::vector<Graf>& tab, long lewy, long prawy );
void DodawanieKrawedzi(std::vector<Graf> & elementy, int &roz);
void swapx( Graf& a, Graf& b );
void Sortuj(std::vector<Graf> & elementy, int roz);
void wczytywaniezpliku(const char * nazwa, std::vector<Graf> & G, int & roz, std::fstream & plik);
int generujER(int n, float p, std::vector<Graf> & elementy, int & roz);

#endif /* defined(__PAMSI_testy__Graf__) */
