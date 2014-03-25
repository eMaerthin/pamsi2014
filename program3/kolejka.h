//
//  kolejka.h
//  PAMSI2014_3
//
//  Created by Adrian Bykowski on 25.03.2014.
//  Copyright (c) 2014 Adrian Bykowski. All rights reserved.
//

#ifndef __PAMSI2014_3__kolejka__
#define __PAMSI2014_3__kolejka__

#include <iostream>
#include <queue>
class kolejka
{
    queue<int> kol;
public:
    int pierwszy(void){int x = kol.front(); kol.pop(); return x;}
    void dodaj(int x){kol.push(x);}
    void dlugosc(){cout <<"Dlugosc: " << kol.size() << endl;}
};
#endif /* defined(__PAMSI2014_3__kolejka__) */
