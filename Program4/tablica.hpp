#ifndef TABLICA_HPP
#define TABLICA_HPP
using namespace std;

#include <iostream>
#include <random>

int* poisson(int wielkosc);
int* gauss(int wielkosc);
int* jednostajny(int wielkosc);
void wyswietl(int* tablica, int rozmiar);
int* posortuj_czesciowo(int*tablica, int liczba_elementow);


#endif
