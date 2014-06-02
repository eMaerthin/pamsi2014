//
//  Graf.h
//  PAMSI2014_6
//
//  Created by Adrian Bykowski on 29.04.2014.
//  Copyright (c) 2014 Adrian Bykowski. All rights reserved.
//

#ifndef __PAMSI2014_6__Graf__
#define __PAMSI2014_6__Graf__

#include <cmath>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <random>
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
};
int generujER_S(int n, float p, std::vector<Graf> & elementy, int & roz);
int generujER(int n, float p, std::vector<Graf> & elementy, int & roz);
int DodawanieKrawedzi(std::vector<Graf> & elementy, int &roz);
void swapx( Graf& a, Graf& b );
void Sortuj(std::vector<Graf> & elementy, int roz);

#endif /* defined(__PAMSI2014_6__Graf__) */
