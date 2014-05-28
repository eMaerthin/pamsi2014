//
//  main.cpp
//  PAMSI2014_3
//
//  Created by Adrian Bykowski on 25.03.2014.
//  Copyright (c) 2014 Adrian Bykowski. All rights reserved.
//
#define ILE 20 // ilosc el kopca
#include <iostream>
#include "Kopiec.h"
#include "stos.h"
#include "kolejka.h"
int main(int argc, const char * argv[])
{
    stos stosik;
    kolejka kolejeczka;
    int opcja=1;
    cout << "Start Programu" << endl;
    while(opcja){
        cout <<
        "opcja 1 dodaj el. stosu" << endl <<
        "opcja 2 wstaw el. do kopca" << endl <<
        "opcja 3 dodaj el. do kolejki" << endl <<
        "opcja 4 usun el. stosu" << endl <<
        "opcja 5 znajdz element stosu" << endl <<
        "opcja 6 wyswietl kopiec" << endl <<
        "opcja 7 wyswietl stos" << endl <<
        "opcja 8 wyswietl dlugosc kolejki" << endl <<
        "opcja 9 pokaz i usun pierwszy el. kolejki" << endl <<
        "opcja 0 koniec" << endl;
        
        cin >> opcja;
        int x;
        switch(opcja)
        {
            case 1: {cin >> x; stosik.dodaj(x); break;}
            case 2: {   for (int i=1;i<ILE;i++)
                        Wstaw(i); break;}
            case 3: {cin >> x; kolejeczka.dodaj(x); break;}
            case 4: {stosik.usun(); break;}
            case 5: {cin >> x; if(stosik.znajdz(x))cout << "znaleziono" << endl; break;}
            case 6: {wyswietl(); break;}
            case 7: {stosik.wyswietl(); break;}
            case 8: {kolejeczka.dlugosc(); break;}
            case 9: {cout << "pierwszy element : " << kolejeczka.pierwszy() << endl; break;}
            case 0: {break;}
            default: break;
        }
    }
    return 0;
}

