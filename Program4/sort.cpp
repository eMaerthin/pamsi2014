#include "sort.hpp"
#include <iostream>
#include <cmath>

using namespace std;

// ******************************************************************************************************/
//                                 Sortowanie przez wstawianie                                           /
// ******************************************************************************************************/
void wstawianie(int* tablica, int liczba_elementow){

int licznik;
int biezaca_wartosc;
int odstep = 1;
    while (odstep>0){
        for (int i = odstep; i < liczba_elementow;i++){
            biezaca_wartosc=tablica[i];                              // wpisuje wartosc komorki do osobnej zmiennej
            licznik = i-odstep;                                      // ustawia licznik na startowy element
            while ((tablica[licznik]>biezaca_wartosc)&&(licznik>0))
                {
                tablica[licznik+odstep]=tablica[licznik];
                licznik = licznik -  odstep;
                }
        tablica[licznik+odstep]=biezaca_wartosc;
        }
    odstep /= 2;
    }
}
// ******************************************************************************************************/
//                                        Sortowanie shella                                              /
// ******************************************************************************************************/
void shell (int *tablica, int liczba_elementow) {
    int h, i, j, k;
    for (h = liczba_elementow; h /= 2;) {
        for (i = h; i < liczba_elementow; i++) {
            k = tablica[i];
            for (j = i; j >= h && k < tablica[j - h]; j -= h) {
                tablica[j] = tablica[j - h];
            }
            tablica[j] = k;
        }
    }
}
/*
// Segmentation fault przy 100k ?!
void shell(int* tablica, int liczba_elementow){

int licznik;
int biezaca_wartosc;
int odstep = 1;

for(odstep = 1; odstep < liczba_elementow/2; odstep = 2*odstep);

odstep /= 2;

//if(!odstep) odstep++;
while (odstep>0){
    for (int i = odstep; i < liczba_elementow;i++){
    biezaca_wartosc=tablica[i];                                             // wpisuje wartosc komorki do osobnej zmiennej
    licznik = i-odstep;                                                    // ustawia licznik na startowy element
        while ((tablica[licznik]>biezaca_wartosc)&&(licznik>0)){
            tablica[licznik+odstep]=tablica[licznik];
            licznik = licznik - odstep;
            }
        tablica[licznik+odstep]=biezaca_wartosc;
        }
    odstep /= 2;
    }
}*/
// ******************************************************************************************************/
//                                    Sortowanie quicksort                                               /
// ******************************************************************************************************/


// ******************************************************************************************************/
// Przeciazona metoda quicksort stworzona w celu zachowania standardu                                    /
// ******************************************************************************************************/
void quicksort(int* tablica, int liczba_elementow){
    int poczatek = 0;
    int koniec = liczba_elementow-1;
   tablica = quicksort(tablica, poczatek, koniec);
}
int* quicksort(int* tablica, int poczatek, int koniec){

     int i=poczatek;
     int j=koniec;
     int x=tablica[(poczatek+koniec)>>1];
     do{
        while(tablica[i]<x) i++;
            while(tablica[j]>x) j--;
                if(i<=j){
                    swap(tablica[i],tablica[j]);
                    i++;
                    j--;
                 }
     }while(i<=j);
     if(poczatek<j) quicksort(tablica,poczatek,j);
     if(koniec>i) quicksort(tablica,i,koniec);

return tablica;
}
// ******************************************************************************************************/
//                                 Sortowanie przez kopcowanie                                           /
// ******************************************************************************************************/
void kopcowanie(int* tablica, int liczba_elementow){

// Budujemy kopiec
    int a,b,x,licznik;

   for(licznik = 2; licznik < liczba_elementow/*TU ZMIENAM*/; licznik++)
  {
    b = licznik; a = b / 2;
    x = tablica[licznik];
    while((a > 0) && (tablica[a] < x))
    {
      tablica[b] = tablica[a];
      b = a; a = b / 2;
    }
    tablica[b] = x;
  }
// Rozbieramy kopiec

int i,j,k,t;
    for(i = liczba_elementow - 1; i >= 0; i--)
    {
        t = tablica[0]; tablica[0] = tablica[i]; tablica[i] = t;
        j = 0;
        while(j != i)
        {
            k = j + j + 1;
            if(k < i)
            {
                if((k+1 < i) && (tablica[k]<=tablica[k+1])) k++;
                if(tablica[k]<=tablica[j])
                    j = i;
                else
                {
                    t = tablica[k]; tablica[k] = tablica[j]; tablica[j] = t;
                    j = k;
                };
            }
            else j = i;
        };
    };

}

// ******************************************************************************************************/
//                                 Sortowanie introspektywne                                             /
// ******************************************************************************************************/

// ******************************************************************************************************/
// Funkcje pomocnicze
// ******************************************************************************************************/
unique_ptr<int[]> ekstrakt_tablicy(int* tablica, int poczatek, int koniec){

    //int* ekstrakt = new int[koniec-poczatek+1];
    unique_ptr<int[]> ekstrakt(new int[koniec-poczatek+1]);

    for (int licznik = poczatek,i = 0; licznik <=koniec; licznik++, i++){
        ekstrakt[i] = tablica[licznik];
    }

return ekstrakt;
}
// ******************************************************************************************************/
void agregacja_tablicy(int* ekstrakt, int* tablica, int poczatek, int koniec){
    for(int i = 0,licznik = poczatek; licznik <= koniec;licznik++,i++){
         tablica[licznik]=ekstrakt[i];
    }
}
// ******************************************************************************************************/
// Przeciazona metoda introsort stworzona w celu zachowania standardu                                    /
// ******************************************************************************************************/
void introsort(int* tablica, int liczba_elementow){
    int poczatek = 0;
    int koniec = liczba_elementow-1;
    tablica = introsort(tablica, poczatek, koniec);
}

// ******************************************************************************************************/
// Glowna funkcja sortowania                                                                             /
// ******************************************************************************************************/
int* introsort(int* tablica, int poczatek, int koniec){
    int liczba_elementow = (koniec-poczatek+1);
    static int licznik = 0;
    static int ograniczenie = 2*log(liczba_elementow);

     int i=poczatek;
     int j=koniec;
     int x=tablica[(poczatek+koniec)>>1];
     do{
        while(tablica[i]<x) i++;
            while(tablica[j]>x) j--;
                if(i<=j){
                    swap(tablica[i],tablica[j]);
                    i++;
                    j--;
                 }
     }while(i<=j);
     if(poczatek<j&&licznik<ograniczenie){
             licznik++;
             introsort(tablica,poczatek,j);
             licznik--;
     }
    else {
        int tymczasowy_rozmiar=(j-poczatek+1);
        unique_ptr<int[]> wskaznik(new int[tymczasowy_rozmiar]);
        wskaznik = ekstrakt_tablicy(tablica,poczatek,j);
        kopcowanie(wskaznik.get(),tymczasowy_rozmiar);
        agregacja_tablicy(wskaznik.get(),tablica,poczatek,j);
        }
     if(koniec>i&&licznik<ograniczenie){
            licznik++;
            introsort(tablica,i,koniec);
            licznik--;
        }
    else {
        int tymczasowy_rozmiar=(koniec-i+1);
        unique_ptr<int[]> wskaznik(new int[tymczasowy_rozmiar]);
        wskaznik = ekstrakt_tablicy(tablica,i,koniec);
        kopcowanie(wskaznik.get(),tymczasowy_rozmiar);
        agregacja_tablicy(wskaznik.get(),tablica,i,koniec);
        }
return tablica;
}
