//
//  Prime.cpp
//  PAMSI_testy
//
//  Created by Adrian Bykowski on 29.04.2014.
//  Copyright (c) 2014 Adrian Bykowski. All rights reserved.
//
//
#include "Prime.h"
#include "Graf.h"
// NIE DZIALA KASOWANIE ELEMENTOW Z PRZODU // Usuniete usuwanie elementow.
void CzyNalezyPrime(std::list<Graf>& _elementy, std::vector<Graf>& tab, int _wezlel, int & roz, std::vector<_drzewo_lista> & _drzewo)
{
    Graf x; // zmienna do przypisywania wartosci do sprawdzania
    bool z(true);
    for(int i(0);i<roz;i++)
    {
        z = true;
        if(tab[i].pierwszy==_wezlel){ // sprawdza czy wezel zawiera sie w jednym z elementow w tablicy
            for(std::list<Graf>::iterator iter = _drzewo[0].begin(); iter!=_drzewo[0].end(); iter++){ // sprawdza czy dana krawedz z wierzcholkiem moze zawierac sie w drzewie juz utworzonym czy nie tworzy cyklu
                x = *iter; // wartosc z drzewa
                if(tab[i].drugi==x.drugi || tab[i].drugi==x.pierwszy){
                    z = false; // gdy znajduje sie w drzewie juz utworzonym
                }
            }
            if(z){
                _elementy.push_back(tab[i]);
                tab[i]=tab[roz-1];
                roz--;
                i--;
                tab.resize(roz);// jezeli nie ma w drzewie dodajemy do elementow
            } else {
                tab[i]=tab[roz-1];
                roz--;
                i--;
                tab.resize(roz);
                z=true;
                continue;            }
        } else {
            if(tab[i].drugi==_wezlel){
                for(std::list<Graf>::iterator iter = _drzewo[0].begin(); iter!=_drzewo[0].end(); iter++){
                    x = *iter;
                    if(tab[i].pierwszy==x.drugi || tab[i].pierwszy==x.pierwszy){
                        z = false;
                    }
                }
                if(z){
                    _elementy.push_back(tab[i]);
                    tab[i]=tab[roz-1];
                    roz--;
                    i--;
                } else {
                    tab[i]=tab[roz-1];
                    //tab.erase(tab.begin()+i);
                    roz--;
                    i--;
                    tab.resize(roz);
                    z=true;
                    continue;
                }
            }
        }
    }
}

// czysci liste z niepotrzebnych elementow i sortuje wedlug wag.
void CzyszczenieListy(std::list<Graf>& _elementy,std::vector<_drzewo_lista> & _drzewo)
{
    Graf x,y; // <-- Grafy pomocnicze do przechowywanie danych tymczasowych.
    bool a(false),b(false);
    for(std::list<Graf>::iterator iter2 = _elementy.begin(); iter2!=_elementy.end(); iter2++){ //  pętla po elementach
        y = *iter2;  // <-- przypisanie wartosci badanego ELEMENTU
        a = false; b = false; // ustawienie "flag"
        for(std::list<Graf>::iterator iter = _drzewo[0].begin(); iter!=_drzewo[0].end(); iter++){ // pętla po drzewie
            x = *iter; // przypisanie wartosci badanego DRZEWA
            if(y.drugi==x.drugi || y.drugi==x.pierwszy){
                a=true;
            }
            if(y.pierwszy==x.drugi || y.pierwszy==x.pierwszy){
                b=true;
            }
            if(a && b){
                iter2 = _elementy.erase(iter2);
                iter2--;
            }
        }
    }
    _elementy.sort();
}

// dodaje wezly do wezlow
void DodawanieWezlow(std::list<Graf> & _elementy, std::list<int> & _wezly, int & wezel)
{
    bool testwezla = false;
    for(std::list<int>::iterator iter = _wezly.begin(); iter!=_wezly.end(); iter++){
        if(_elementy.front().pierwszy==*iter){
            testwezla = true;
        }
    }
    if(testwezla){
        _wezly.push_back(_elementy.front().drugi);
        wezel=_elementy.front().drugi;
    } else {
        _wezly.push_back(_elementy.front().pierwszy);
        wezel=_elementy.front().pierwszy;
    }
    //_elementy.reverse();   // TUTAJ BLAD?!
    //_elementy.pop_front();
    
}

// glowny algorytm Prima
void AlgorytmP(std::vector<_drzewo_lista> & _drzewo, std::vector<Graf>& tab, int & roz)
{
    std::list<Graf> _elementy; std::list<int> _wezly; int wezel; //Graf r; // tworzenie zmiennych lokalnych
    _drzewo[0].clear();
    ///////////////////////////////////OPERACJE DODAWANIA PIERWSZEGO ELEMENTU/////////////////////
    
    wezel = tab[0].pierwszy; // losowanie pierwszego węzła
    _wezly.push_back(wezel); // dodawanie tego węzła do listy dodanych węzłów
    for(int i(0);i<tab.size();i++){
        if (tab[i].pierwszy==wezel || tab[i].drugi==wezel ){
            _elementy.push_back(tab[i]); // dodawnie elementow do listy elementow naleznych do wezlow
            tab[i]=tab[roz-1];
            tab.pop_back();
            roz--;
            i--;
        }
    }
    _elementy.sort(); // sortowanie wedlug wag
    _drzewo[0].push_back(_elementy.front()); // dodawanie elementu o najmniejszej wadze
    if(wezel==_drzewo[0].front().pierwszy){  /////////////  <--
        wezel=_drzewo[0].front().drugi;
    } else {
        wezel=_drzewo[0].front().pierwszy;
    }
    // zakomentowany blad, nie wiem czemu nie dziala. Program dziala sprawnie ale dluzej ze wzgledu na przegladanie calej listy.
    //_elementy.reverse();
    //_elementy.pop_front();
    //for(std::list<Graf>::iterator it=_elementy.begin(); it!= _elementy.end(); it++)
    //{
    //   std::cout << "\ngraf before it=" << *it;
    //}
    _elementy.pop_front();
    //for(std::list<Graf>::iterator it=_elementy.begin(); it!= _elementy.end(); it++)
    //{
    //    std::cout << "\ngraf after it=" << *it;
    //}

    //std::list<Graf>::iterator it = _elementy.begin();
    //Graf dupa = *it;
    //it = _elementy.erase(it); /// NIE MOZE USUNAC PIERWSZEGO ELEMENTU ?? ///////////////////////////////
    //tab.erase(tab.begin()+0); // usuwa pierwszy element aby już nie dodwac go.
    //roz--;
    
    ///////////////////////////////////////////////////////////////////////////////////////////////
    
    bool test = true; // pętla do dodawanie kolejnych węzłów. 
    do {
        CzyNalezyPrime(_elementy, tab, wezel, roz, _drzewo);
        CzyszczenieListy(_elementy, _drzewo);
        _drzewo[0].push_back(_elementy.front());
        DodawanieWezlow(_elementy,_wezly, wezel);
        if(_elementy.empty()){
            test = false;
        }
    } while(test);
}

