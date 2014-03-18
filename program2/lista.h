//
//  lista.h
//  pamaaaasi
//
//  Created by Adrian Bykowski on 11.03.2014.
//  Copyright (c) 2014 Adrian Bykowski. All rights reserved.
//

#ifndef __pamaaaasi__lista__
#define __pamaaaasi__lista__
#include <list>
#include <iostream>
class lista
{
public:
    class Element{
    public:
        Element * poprzedni;
        Element * nastepny;
        int wartosc;
    };
    class iter{
    public:
        Element * wsk;
        iter nastepny(iter x);
    };
    iter poczatek, koniec;
    lista(void);
    void dodajp(int); // dodawanie na poczatku listy
    void dodajk(int); // dodawanie na koncu listy
    void wyswietl();  // wyswietlanie listy
    void usunp();     // usuuwanie elementu z poczatku listy
    void usunk();     // usuwanie elementu z konca listy
    int rozmiar;
};
#endif /* defined(__pamaaaasi__lista__) */
