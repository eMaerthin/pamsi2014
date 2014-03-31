#ifndef OPERACJE_HH
#define OPERACJE_HH

#include <fstream>
#include <iostream>
#include <string>
#include <queue>
#include <cstdlib>

using namespace std;

void Wczytywanie_Konsola(queue<int> &tablica);
void Wyswietl_Konsola(queue<int> tablica);
void Wczytaj_TXT(queue<int> &tablica);
void Zapisz_TXT(queue<int> tablica);
void Wczytaj_BIN(queue<int> &tablica);
void Zapisz_BIN(queue<int> tablica);
void Wypelnij_Losowo(queue<int> &tablica);
queue<int> * Kopia(queue<int> tablica);

istream & operator >> (istream &wej, queue<int> &L);
void operator >> (int &elem, queue<int> &L);
ostream & operator << (ostream &wyj, queue<int> L);


#endif
