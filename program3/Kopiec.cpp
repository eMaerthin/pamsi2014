//
//  Kopiec.cpp
//  PAMSI2014_3
//
//  Created by Adrian Bykowski on 25.03.2014.
//  Copyright (c) 2014 Adrian Bykowski. All rights reserved.
//
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

int kopiec[100], pos = 0;

int rodzic(int x)
{
    return x / 2; //zwraca index rodzica dla danej gałęzi
}

int l_galaz(int x)
{
    return 2 * x; // zwraca index lewej gałęzi
}

int p_galaz(int x)
{
    return 2 * x + 1;
}
void Gora(void)
{
    if (pos != 0)
        cout << kopiec[1] << "\n";
}
void Wstaw(int x)
{
    kopiec[pos+1] = x; //wstaw na koniec
    pos++;           //zwieksz liczbe elementow kopca
    int v = pos;
    while (v != 1 and kopiec[rodzic(v)] < kopiec[v]) //przywroc wlasciwosc kopca
    {
        swap (kopiec[rodzic(v)], kopiec[v]);
        v=rodzic(v);
    }
}
//Usuwa wierzcholek kopca
void Usun_wierzcholek()
{
    if (pos==0)      //jezeli kopiec jest pusty zakoncz bez zadnej akcji
        return;
    
    kopiec[1]=kopiec[pos]; //wstaw ostatni element do wierzcholka
    pos--;             //zmniejsz liczbe elementow kopca
    int v = 1;
    while(v*2 <= pos){
        if(kopiec[v] < kopiec[v*2] || kopiec[v] < kopiec[v*2+1]) {
            if(kopiec[v*2] > kopiec[v*2+1] || v*2+1 > pos) {
                swap(kopiec[v],kopiec[v*2]);v=v*2;}
            else {
                swap(kopiec[v],kopiec[v*2+1]);v=v*2+1;
            }
        }
        else
            break;
    }
}
void wyswietl(int poczatek=1){
    int x = 1, y=1, z = 2;
    cout << '\t' << '\t' << '\t' << kopiec[1] << endl;
    for(int i = 1; i <= pos; )
    {
        y=y*2;
        x=y;
        if(z==2)cout << "\t \t  ";
        if(z==1)cout << "\t \t";
        if(z==0)cout << "\t";
        if(z==-1)cout << " ";
        z--;
        while(x)
        {
            i++;
            if(i>pos)break;
            cout << kopiec[i] << " ";
            x--;
        }
        cout << endl;
        
    }
}
