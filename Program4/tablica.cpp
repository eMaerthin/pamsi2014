#include "tablica.hpp"

#include "sort.hpp" // quicksort wykorzystany

//#include <iostream>
//#include <random>

using namespace std;


// Funkcja tworzaca rozklad Poissona
int* poisson(int wielkosc)
{
default_random_engine poisson;
poisson_distribution<int> distribution(4.0);

int* tablica = new int[wielkosc];
int wartosc;

for (int i=0; i<wielkosc; i++) {
    wartosc = distribution(poisson);
    tablica[i]=wartosc;
}

return tablica;
}

// Funkcja tworzaca rozklad nromalny
int* gauss(int wielkosc)
{
default_random_engine gauss;
normal_distribution<double> distribution(5.0,2.0);

int* tablica = new int[wielkosc];
int wartosc;

for (int i=0; i<wielkosc; i++) {
    wartosc = distribution(gauss);
    tablica[i]=wartosc;
    }
return tablica;
}


// Funkcja tworzaca rozklad jednostajny
int* jednostajny(int wielkosc)
{
default_random_engine jednostajny;
uniform_int_distribution<int> distribution(5.0,2.0);

int* tablica = new int[wielkosc];
int wartosc;

for (int i=0; i<wielkosc; i++) {
    wartosc = distribution(jednostajny);
    tablica[i]=wartosc;
    }
return tablica;
}

// Funkcja wyswietlajaca tablice
void wyswietl(int* tablica, int rozmiar){
for(int i = 0; i<rozmiar; i++) cout << "Element tablicy numer " << (i+1) << " to " << tablica[i] << endl;
}


int* posortuj_czesciowo(int*tablica, int liczba_elementow){
// Stworzenie pomoczniczej tablicy do sortowania
int* czesc_sortowana = new int[liczba_elementow];
// Przepisanie do osobnej tablicy
for (int i=0 ; i<liczba_elementow; i++) czesc_sortowana[i]=tablica[i];
// Quicksort
quicksort(czesc_sortowana,liczba_elementow);
// Przepisanie do wyjsciowej tablicy
for (int i=0 ; i<liczba_elementow; i++) tablica[i]=czesc_sortowana[i];
return tablica;




}
