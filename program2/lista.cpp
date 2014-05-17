//
//  lista.cpp
//  pamaaaasi
//
//  Created by Adrian Bykowski on 11.03.2014.
//  Copyright (c) 2014 Adrian Bykowski. All rights reserved.
//
#include "lista.h"

lista::lista(void)
{
    rozmiar = 0;
    poczatek.wsk = koniec.wsk = NULL;
}
void lista::dodajk(int x)
{
    rozmiar++;
    Element * a = koniec.wsk;
    Element * b = new Element;
    b -> nastepny = b;
    b -> poprzedni = a;
    b -> wartosc = x;
    if(koniec.wsk!=NULL)
    a -> nastepny = b;
    if(poczatek.wsk==NULL)
    {
        if(koniec.wsk!=NULL)
        a -> poprzedni = b ;
        b -> poprzedni = b ;
        poczatek.wsk=b;
    }
    koniec.wsk = b;
}
void lista ::dodajp(int x)
{
    rozmiar++;
    Element * a = poczatek.wsk;
    Element * b = new Element;
    b -> nastepny = a;
    b -> poprzedni = b;
    b -> wartosc = x;
    if(poczatek.wsk!=NULL)
    a -> poprzedni = b;
    if(koniec.wsk==NULL)
    {
        if(poczatek.wsk!=NULL)
        a -> poprzedni = b ;
        b -> poprzedni = b ;
        koniec.wsk=b;
    }
    poczatek.wsk = b;
}
void lista::usunk()
{
    if(rozmiar)
    {
        Element * a = koniec.wsk;
        Element * b = a->poprzedni;
        b -> nastepny = b;
        delete a;
        koniec.wsk = b;
        rozmiar--;
    }
    else
        std::cout<<"brak elementow listy" << std::endl;
}
void lista::usunp()
{
    if(rozmiar)
    {
        Element * a = poczatek.wsk;
        Element * b = a->nastepny;
        b -> poprzedni = b;
        delete a;
        poczatek.wsk = b;
        rozmiar--;
    }
    else
        std::cout<<"brak elementow listy" << std::endl;
}
void lista::wyswietl()
{
    iter x = poczatek;
    for(int i = 0; i<rozmiar;i++ ){
        std::cout << x.wsk->wartosc << ", ";
        x.wsk = x.wsk->nastepny;
    }
    std::cout << "rozmiar :" << rozmiar << std::endl;
    
}

