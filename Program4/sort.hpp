#ifndef SORT_HPP
#define SORT_HPP
#include <memory>
using namespace std;

void wstawianie(int* tablica, int liczba_elementow);
void shell(int* tablica, int liczba_elementow);
void kopcowanie(int* tablica, int liczba_elementow);
void quicksort(int* tablica, int liczba_elementow);
    int* quicksort(int* tablica, int poczatek, int koniec);
void introsort(int* tablica, int liczba_elementow);
    int* introsort(int* tablica, int poczatek, int koniec);

unique_ptr<int[]> ekstrakt_tablicy(int* tablica, int poczatek, int koniec);
void agregacja_tablicy(int* ekstrakt, int* tablica, int poczatek, int koniec);




#endif
