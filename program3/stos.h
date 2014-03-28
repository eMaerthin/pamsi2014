
//
//  stos.h
//  pamaaaasi
//
//  Created by Adrian Bykowski on 11.03.2014.
//  Copyright (c) 2014 Adrian Bykowski. All rights reserved.
//

#ifndef __pamaaaasi__stos__
#define __pamaaaasi__stos__
#include <stack>
#include <iostream>
using namespace std;
class stos
{
    stack<int> lista;
public:
    void dodaj(int & x);
    unsigned long int rozmiar(void);
    void wyswietl(void);
    void usun(void);
    bool znajdz(int x);
};
#endif /* defined(__pamaaaasi__stos__) */
