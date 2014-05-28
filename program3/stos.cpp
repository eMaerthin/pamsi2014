//
//  stos.cpp
//  pamaaaasi
//
//  Created by Adrian Bykowski on 11.03.2014.
//  Copyright (c) 2014 Adrian Bykowski. All rights reserved.
//
#include <stack>
#include "stos.h"
using namespace std;
void stos::dodaj(int &x)
{
    lista.push(x);
}
unsigned long int stos::rozmiar(void)
{
    return lista.size();
}
void stos::usun()
{
    if(!lista.empty())
    lista.pop();
    else
        std::cout<<"brak elementow stosu" << std::endl;
}
void stos::wyswietl(void)
{
    stack<int> temp1 = lista;
    while(!temp1.empty())
    {
        cout << temp1.top() << endl;
        temp1.pop();
    }
    cout << "rozmiar :" << lista.size() << endl;
}
bool stos::znajdz(int x)
{
    stack<int> temp1 = lista;
    while(!temp1.empty())
    {
        if(temp1.top()==x)
            return true;
        else temp1.pop();
    }
    return false;
}
