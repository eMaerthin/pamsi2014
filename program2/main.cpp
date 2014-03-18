//
//  main.cpp
//  pamaaaasi
//
//  Created by Adrian Bykowski on 11.03.2014.
//  Copyright (c) 2014 Adrian Bykowski. All rights reserved.
//

#include <iostream>
#include "stos.h"
#include "lista.h"
using namespace std;

int main(int argc, const char * argv[])
{
    stos stosik;
    lista listunia;
    int opcja=1;
    cout << "Start Programu" << endl;
    while(opcja){
    cout <<
    "opcja 1 dodaj el. stosu" << endl <<
    "opcja 2 dodaj el. listy poczatek" << endl <<
    "opcja 3 dodaj el. listy koniec" << endl <<
    "opcja 4 usun el. stosu" << endl <<
    "opcja 5 usun el. listy poczatek" << endl <<
    "opcja 6 usun el. listy koniec" << endl <<
    "opcja 7 wyswietl stos" << endl <<
    "opcja 8 wyswietl liste" << endl <<
    "opcja 0 koniec" << endl;
    
    cin >> opcja;
    int x;
    switch(opcja)
        {
        case 1: {cin >> x; stosik.dodaj(x); break;}
        case 2: {cin >> x; listunia.dodajp(x); break;}
        case 3: {cin >> x; listunia.dodajk(x); break;}
        case 4: {stosik.usun(); break;}
        case 5: {listunia.usunp(); break;}
        case 6: {listunia.usunk(); break;}
        case 7: {stosik.wyswietl(); break;}
        case 8: {listunia.wyswietl(); break;}
        case 0: {break;}
        default: break;
        }
    }
    
    
    return 0;
}

