#ifndef GENERATORY_H
#define GENERATORY_H
#include "lista.h"
#include "macierz.h"
#include <time.h>
#include <cstdlib>

//Klasa zawieraj¹ca metody dla klasy macierz
class generator_macierzy {
  public:
  macierz graf_er(int n, float p); //Generuje graf dla zadanej liczby wierzcholkow i prawdopodobienstwa p
  macierz graf_pelny(int n);       //Generuje graf pelny dla zadanej liczby wierzcholkow
};

//Klasa zawieraj¹ca metody dla klasy lista
class generator_listy: public lista {
  public:
  lista graf_er(int n, float p); //Generuje graf dla zadanej liczby wierzcholkow i prawdopodobienstwa p
  lista graf_pelny(int n);       //Generuje graf pelny dla zadanej liczby wierzcholkow
};

#endif // GENERATORY_H
