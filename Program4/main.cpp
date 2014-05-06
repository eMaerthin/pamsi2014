#include "sort.hpp"
#include "tablica.hpp"

#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;


double PCFreq = 0.0;
__int64 CounterStart = 0;

void StartCounter()
{
    LARGE_INTEGER li;
    if(!QueryPerformanceFrequency(&li))
	cout << "QueryPerformanceFrequency failed!\n";

    PCFreq = double(li.QuadPart)/1000000.0; // mikrosekundy

    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}
double GetCounter()
{
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart-CounterStart)/PCFreq;
}




int main()
{

// ******************************************************************************************************/
//                                               #PARAM                                                  /
// ******************************************************************************************************/
// DEFINIOWANIE ROZMIARU TABLIC
#define STO
#define TYSIAC
#define DZIESIEC_TYSIECY
//#define STO_TYSIECY
//#define MILION
// DEFINIOWANIE ALGORYTMOW SORTOWANIA
#define WSTAWIANIE
#define KOPCOWANIE
#define SHELL
#define QUICKSORT
#define INTROSORT
// DEFINIOWANIE ROZKLADOW
#define POISSON
#define GAUSS
#define JEDNOSTAJNY

int ilosc_iteracji = 10;  // ilosc powtorzen calej petli

// ******************************************************************************************************/
//                                             #PARAM END                                                /
// ******************************************************************************************************/


// ******************************************************************************************************/
//                                       Wyniki wstawiania                                               /
// ******************************************************************************************************/
#if defined (STO) && defined (WSTAWIANIE) && defined (POISSON)
    double* wstawianie_wynik_1 = new double[ilosc_iteracji];
    double* wstawianie_wynik_2 = new double[ilosc_iteracji];
    double* wstawianie_wynik_3 = new double[ilosc_iteracji];
    double* wstawianie_wynik_4 = new double[ilosc_iteracji];
#endif // defined
#if defined (TYSIAC) && defined (WSTAWIANIE) && defined (POISSON)
    double* wstawianie_wynik_5 = new double[ilosc_iteracji];
    double* wstawianie_wynik_6 = new double[ilosc_iteracji];
    double* wstawianie_wynik_7 = new double[ilosc_iteracji];
    double* wstawianie_wynik_8 = new double[ilosc_iteracji];
#endif // defined
#if defined (DZIESIEC_TYSIECY) && defined (WSTAWIANIE) && defined (POISSON)
    double* wstawianie_wynik_9 = new double[ilosc_iteracji];
    double* wstawianie_wynik_10 = new double[ilosc_iteracji];
    double* wstawianie_wynik_11 = new double[ilosc_iteracji];
    double* wstawianie_wynik_12 = new double[ilosc_iteracji];
#endif // defined
#if defined (STO_TYSIECY) && defined (WSTAWIANIE) && defined (POISSON)
    double* wstawianie_wynik_13 = new double[ilosc_iteracji];
    double* wstawianie_wynik_14 = new double[ilosc_iteracji];
    double* wstawianie_wynik_15 = new double[ilosc_iteracji];
    double* wstawianie_wynik_16 = new double[ilosc_iteracji];
#endif // defined
#if defined (MILION) && defined (WSTAWIANIE) && defined (POISSON)
    double* wstawianie_wynik_17 = new double[ilosc_iteracji];
    double* wstawianie_wynik_18 = new double[ilosc_iteracji];
    double* wstawianie_wynik_19 = new double[ilosc_iteracji];
    double* wstawianie_wynik_20 = new double[ilosc_iteracji];
#endif // defined
#if defined (STO) && defined (WSTAWIANIE) && defined (GAUSS)
    double* wstawianie_wynik_21 = new double[ilosc_iteracji];
    double* wstawianie_wynik_22 = new double[ilosc_iteracji];
    double* wstawianie_wynik_23 = new double[ilosc_iteracji];
    double* wstawianie_wynik_24 = new double[ilosc_iteracji];
#endif // defined
#if defined (TYSIAC) && defined (WSTAWIANIE) && defined (GAUSS)
    double* wstawianie_wynik_25 = new double[ilosc_iteracji];
    double* wstawianie_wynik_26 = new double[ilosc_iteracji];
    double* wstawianie_wynik_27 = new double[ilosc_iteracji];
    double* wstawianie_wynik_28 = new double[ilosc_iteracji];
#endif // defined
#if defined (DZIESIEC_TYSIECY) && defined (WSTAWIANIE) && defined (GAUSS)
    double* wstawianie_wynik_29 = new double[ilosc_iteracji];
    double* wstawianie_wynik_30 = new double[ilosc_iteracji];
    double* wstawianie_wynik_31 = new double[ilosc_iteracji];
    double* wstawianie_wynik_32 = new double[ilosc_iteracji];
#endif // defined
#if defined (STO_TYSIECY) && defined (WSTAWIANIE) && defined (GAUSS)
    double* wstawianie_wynik_33 = new double[ilosc_iteracji];
    double* wstawianie_wynik_34 = new double[ilosc_iteracji];
    double* wstawianie_wynik_35 = new double[ilosc_iteracji];
    double* wstawianie_wynik_36 = new double[ilosc_iteracji];
#endif // defined
#if defined (MILION) && defined (WSTAWIANIE) && defined (GAUSS)
    double* wstawianie_wynik_37 = new double[ilosc_iteracji];
    double* wstawianie_wynik_38 = new double[ilosc_iteracji];
    double* wstawianie_wynik_39 = new double[ilosc_iteracji];
    double* wstawianie_wynik_40 = new double[ilosc_iteracji];
#endif // defined
#if defined (STO) && defined (WSTAWIANIE) && defined (JEDNOSTAJNY)
    double* wstawianie_wynik_41 = new double[ilosc_iteracji];
    double* wstawianie_wynik_42 = new double[ilosc_iteracji];
    double* wstawianie_wynik_43 = new double[ilosc_iteracji];
    double* wstawianie_wynik_44 = new double[ilosc_iteracji];
#endif // defined
#if defined (TYSIAC) && defined (WSTAWIANIE) && defined (JEDNOSTAJNY)
    double* wstawianie_wynik_45 = new double[ilosc_iteracji];
    double* wstawianie_wynik_46 = new double[ilosc_iteracji];
    double* wstawianie_wynik_47 = new double[ilosc_iteracji];
    double* wstawianie_wynik_48 = new double[ilosc_iteracji];
#endif // defined
#if defined (DZIESIEC_TYSIECY) && defined (WSTAWIANIE) && defined (JEDNOSTAJNY)
    double* wstawianie_wynik_49 = new double[ilosc_iteracji];
    double* wstawianie_wynik_50 = new double[ilosc_iteracji];
    double* wstawianie_wynik_51 = new double[ilosc_iteracji];
    double* wstawianie_wynik_52 = new double[ilosc_iteracji];
#endif // defined
#if defined (STO_TYSIECY) && defined (WSTAWIANIE) && defined (JEDNOSTAJNY)
    double* wstawianie_wynik_53 = new double[ilosc_iteracji];
    double* wstawianie_wynik_54 = new double[ilosc_iteracji];
    double* wstawianie_wynik_55 = new double[ilosc_iteracji];
    double* wstawianie_wynik_56 = new double[ilosc_iteracji];
#endif // defined
#if defined (MILION) && defined (WSTAWIANIE) && defined (JEDNOSTAJNY)
    double* wstawianie_wynik_57 = new double[ilosc_iteracji];
    double* wstawianie_wynik_58 = new double[ilosc_iteracji];
    double* wstawianie_wynik_59 = new double[ilosc_iteracji];
    double* wstawianie_wynik_60 = new double[ilosc_iteracji];
#endif // defined
// ******************************************************************************************************/
//                                       Wyniki kopcowania                                               /
// ******************************************************************************************************/
#if defined (STO) && defined (KOPCOWANIE) && defined (POISSON)
    double* kopcowanie_wynik_1 = new double[ilosc_iteracji];
    double* kopcowanie_wynik_2 = new double[ilosc_iteracji];
    double* kopcowanie_wynik_3 = new double[ilosc_iteracji];
    double* kopcowanie_wynik_4 = new double[ilosc_iteracji];
#endif // defined
#if defined (TYSIAC) && defined (KOPCOWANIE) && defined (POISSON)
    double* kopcowanie_wynik_5 = new double[ilosc_iteracji];
    double* kopcowanie_wynik_6 = new double[ilosc_iteracji];
    double* kopcowanie_wynik_7 = new double[ilosc_iteracji];
    double* kopcowanie_wynik_8 = new double[ilosc_iteracji];
#endif // defined
#if defined (DZIESIEC_TYSIECY) && defined (KOPCOWANIE) && defined (POISSON)
    double* kopcowanie_wynik_9 = new double[ilosc_iteracji];
    double* kopcowanie_wynik_10 = new double[ilosc_iteracji];
    double* kopcowanie_wynik_11 = new double[ilosc_iteracji];
    double* kopcowanie_wynik_12 = new double[ilosc_iteracji];
#endif // defined
#if defined (STO_TYSIECY) && defined (KOPCOWANIE) && defined (POISSON)
    double* kopcowanie_wynik_13 = new double[ilosc_iteracji];
    double* kopcowanie_wynik_14 = new double[ilosc_iteracji];
    double* kopcowanie_wynik_15 = new double[ilosc_iteracji];
    double* kopcowanie_wynik_16 = new double[ilosc_iteracji];
#endif // defined
#if defined (MILION) && defined (KOPCOWANIE) && defined (POISSON)
    double* kopcowanie_wynik_17 = new double[ilosc_iteracji];
    double* kopcowanie_wynik_18 = new double[ilosc_iteracji];
    double* kopcowanie_wynik_19 = new double[ilosc_iteracji];
    double* kopcowanie_wynik_20 = new double[ilosc_iteracji];
#endif // defined
#if defined (STO) && defined (KOPCOWANIE) && defined (GAUSS)
    double* kopcowanie_wynik_21 = new double[ilosc_iteracji];
    double* kopcowanie_wynik_22 = new double[ilosc_iteracji];
    double* kopcowanie_wynik_23 = new double[ilosc_iteracji];
    double* kopcowanie_wynik_24 = new double[ilosc_iteracji];
#endif // defined
#if defined (TYSIAC) && defined (KOPCOWANIE) && defined (GAUSS)
    double* kopcowanie_wynik_25 = new double[ilosc_iteracji];
    double* kopcowanie_wynik_26 = new double[ilosc_iteracji];
    double* kopcowanie_wynik_27 = new double[ilosc_iteracji];
    double* kopcowanie_wynik_28 = new double[ilosc_iteracji];
#endif // defined
#if defined (DZIESIEC_TYSIECY) && defined (KOPCOWANIE) && defined (GAUSS)
    double* kopcowanie_wynik_29 = new double[ilosc_iteracji];
    double* kopcowanie_wynik_30 = new double[ilosc_iteracji];
    double* kopcowanie_wynik_31 = new double[ilosc_iteracji];
    double* kopcowanie_wynik_32 = new double[ilosc_iteracji];
#endif // defined
#if defined (STO_TYSIECY) && defined (KOPCOWANIE) && defined (GAUSS)
    double* kopcowanie_wynik_33 = new double[ilosc_iteracji];
    double* kopcowanie_wynik_34 = new double[ilosc_iteracji];
    double* kopcowanie_wynik_35 = new double[ilosc_iteracji];
    double* kopcowanie_wynik_36 = new double[ilosc_iteracji];
#endif // defined
#if defined (MILION) && defined (KOPCOWANIE) && defined (GAUSS)
    double* kopcowanie_wynik_37 = new double[ilosc_iteracji];
    double* kopcowanie_wynik_38 = new double[ilosc_iteracji];
    double* kopcowanie_wynik_39 = new double[ilosc_iteracji];
    double* kopcowanie_wynik_40 = new double[ilosc_iteracji];
#endif // defined
#if defined (STO) && defined (KOPCOWANIE) && defined (JEDNOSTAJNY)
    double* kopcowanie_wynik_41 = new double[ilosc_iteracji];
    double* kopcowanie_wynik_42 = new double[ilosc_iteracji];
    double* kopcowanie_wynik_43 = new double[ilosc_iteracji];
    double* kopcowanie_wynik_44 = new double[ilosc_iteracji];
#endif // defined
#if defined (TYSIAC) && defined (KOPCOWANIE) && defined (JEDNOSTAJNY)
    double* kopcowanie_wynik_45 = new double[ilosc_iteracji];
    double* kopcowanie_wynik_46 = new double[ilosc_iteracji];
    double* kopcowanie_wynik_47 = new double[ilosc_iteracji];
    double* kopcowanie_wynik_48 = new double[ilosc_iteracji];
#endif // defined
#if defined (DZIESIEC_TYSIECY) && defined (KOPCOWANIE) && defined (JEDNOSTAJNY)
    double* kopcowanie_wynik_49 = new double[ilosc_iteracji];
    double* kopcowanie_wynik_50 = new double[ilosc_iteracji];
    double* kopcowanie_wynik_51 = new double[ilosc_iteracji];
    double* kopcowanie_wynik_52 = new double[ilosc_iteracji];
#endif // defined
#if defined (STO_TYSIECY) && defined (KOPCOWANIE) && defined (JEDNOSTAJNY)
    double* kopcowanie_wynik_53 = new double[ilosc_iteracji];
    double* kopcowanie_wynik_54 = new double[ilosc_iteracji];
    double* kopcowanie_wynik_55 = new double[ilosc_iteracji];
    double* kopcowanie_wynik_56 = new double[ilosc_iteracji];
#endif // defined
#if defined (MILION) && defined (KOPCOWANIE) && defined (JEDNOSTAJNY)
    double* kopcowanie_wynik_57 = new double[ilosc_iteracji];
    double* kopcowanie_wynik_58 = new double[ilosc_iteracji];
    double* kopcowanie_wynik_59 = new double[ilosc_iteracji];
    double* kopcowanie_wynik_60 = new double[ilosc_iteracji];
#endif // defined
// ******************************************************************************************************/
//                                       Wyniki shella                                                   /
// ******************************************************************************************************/
#if defined (STO) && defined (SHELL) && defined (POISSON)
    double* shell_wynik_1 = new double[ilosc_iteracji];
    double* shell_wynik_2 = new double[ilosc_iteracji];
    double* shell_wynik_3 = new double[ilosc_iteracji];
    double* shell_wynik_4 = new double[ilosc_iteracji];
#endif // defined
#if defined (TYSIAC) && defined (SHELL) && defined (POISSON)
    double* shell_wynik_5 = new double[ilosc_iteracji];
    double* shell_wynik_6 = new double[ilosc_iteracji];
    double* shell_wynik_7 = new double[ilosc_iteracji];
    double* shell_wynik_8 = new double[ilosc_iteracji];
#endif // defined
#if defined (DZIESIEC_TYSIECY) && defined (SHELL) && defined (POISSON)
    double* shell_wynik_9 = new double[ilosc_iteracji];
    double* shell_wynik_10 = new double[ilosc_iteracji];
    double* shell_wynik_11 = new double[ilosc_iteracji];
    double* shell_wynik_12 = new double[ilosc_iteracji];
#endif // defined
#if defined (STO_TYSIECY) && defined (SHELL) && defined (POISSON)
    double* shell_wynik_13 = new double[ilosc_iteracji];
    double* shell_wynik_14 = new double[ilosc_iteracji];
    double* shell_wynik_15 = new double[ilosc_iteracji];
    double* shell_wynik_16 = new double[ilosc_iteracji];
#endif // defined
#if defined (MILION) && defined (SHELL) && defined (POISSON)
    double* shell_wynik_17 = new double[ilosc_iteracji];
    double* shell_wynik_18 = new double[ilosc_iteracji];
    double* shell_wynik_19 = new double[ilosc_iteracji];
    double* shell_wynik_20 = new double[ilosc_iteracji];
#endif // defined
#if defined (STO) && defined (SHELL) && defined (GAUSS)
    double* shell_wynik_21 = new double[ilosc_iteracji];
    double* shell_wynik_22 = new double[ilosc_iteracji];
    double* shell_wynik_23 = new double[ilosc_iteracji];
    double* shell_wynik_24 = new double[ilosc_iteracji];
#endif // defined
#if defined (TYSIAC) && defined (SHELL) && defined (GAUSS)
    double* shell_wynik_25 = new double[ilosc_iteracji];
    double* shell_wynik_26 = new double[ilosc_iteracji];
    double* shell_wynik_27 = new double[ilosc_iteracji];
    double* shell_wynik_28 = new double[ilosc_iteracji];
#endif // defined
#if defined (DZIESIEC_TYSIECY) && defined (SHELL) && defined (GAUSS)
    double* shell_wynik_29 = new double[ilosc_iteracji];
    double* shell_wynik_30 = new double[ilosc_iteracji];
    double* shell_wynik_31 = new double[ilosc_iteracji];
    double* shell_wynik_32 = new double[ilosc_iteracji];
#endif // defined
#if defined (STO_TYSIECY) && defined (SHELL) && defined (GAUSS)
    double* shell_wynik_33 = new double[ilosc_iteracji];
    double* shell_wynik_34 = new double[ilosc_iteracji];
    double* shell_wynik_35 = new double[ilosc_iteracji];
    double* shell_wynik_36 = new double[ilosc_iteracji];
#endif // defined
#if defined (MILION) && defined (SHELL) && defined (GAUSS)
    double* shell_wynik_37 = new double[ilosc_iteracji];
    double* shell_wynik_38 = new double[ilosc_iteracji];
    double* shell_wynik_39 = new double[ilosc_iteracji];
    double* shell_wynik_40 = new double[ilosc_iteracji];
#endif // defined
#if defined (STO) && defined (SHELL) && defined (JEDNOSTAJNY)
    double* shell_wynik_41 = new double[ilosc_iteracji];
    double* shell_wynik_42 = new double[ilosc_iteracji];
    double* shell_wynik_43 = new double[ilosc_iteracji];
    double* shell_wynik_44 = new double[ilosc_iteracji];
#endif // defined
#if defined (TYSIAC) && defined (SHELL) && defined (JEDNOSTAJNY)
    double* shell_wynik_45 = new double[ilosc_iteracji];
    double* shell_wynik_46 = new double[ilosc_iteracji];
    double* shell_wynik_47 = new double[ilosc_iteracji];
    double* shell_wynik_48 = new double[ilosc_iteracji];
#endif // defined
#if defined (DZIESIEC_TYSIECY) && defined (SHELL) && defined (JEDNOSTAJNY)
    double* shell_wynik_49 = new double[ilosc_iteracji];
    double* shell_wynik_50 = new double[ilosc_iteracji];
    double* shell_wynik_51 = new double[ilosc_iteracji];
    double* shell_wynik_52 = new double[ilosc_iteracji];
#endif // defined
#if defined (STO_TYSIECY) && defined (SHELL) && defined (JEDNOSTAJNY)
    double* shell_wynik_53 = new double[ilosc_iteracji];
    double* shell_wynik_54 = new double[ilosc_iteracji];
    double* shell_wynik_55 = new double[ilosc_iteracji];
    double* shell_wynik_56 = new double[ilosc_iteracji];
#endif // defined
#if defined (MILION) && defined (SHELL) && defined (JEDNOSTAJNY)
    double* shell_wynik_57 = new double[ilosc_iteracji];
    double* shell_wynik_58 = new double[ilosc_iteracji];
    double* shell_wynik_59 = new double[ilosc_iteracji];
    double* shell_wynik_60 = new double[ilosc_iteracji];
#endif // defined
// ******************************************************************************************************/
//                                       Wyniki quicksort                                                /
// ******************************************************************************************************/
#if defined (STO) && defined (QUICKSORT) && defined (POISSON)
    double* quick_wynik_1 = new double[ilosc_iteracji];
    double* quick_wynik_2 = new double[ilosc_iteracji];
    double* quick_wynik_3 = new double[ilosc_iteracji];
    double* quick_wynik_4 = new double[ilosc_iteracji];
#endif // defined
#if defined (TYSIAC) && defined (QUICKSORT) && defined (POISSON)
    double* quick_wynik_5 = new double[ilosc_iteracji];
    double* quick_wynik_6 = new double[ilosc_iteracji];
    double* quick_wynik_7 = new double[ilosc_iteracji];
    double* quick_wynik_8 = new double[ilosc_iteracji];
#endif // defined
#if defined (DZIESIEC_TYSIECY) && defined (QUICKSORT) && defined (POISSON)
    double* quick_wynik_9 = new double[ilosc_iteracji];
    double* quick_wynik_10 = new double[ilosc_iteracji];
    double* quick_wynik_11 = new double[ilosc_iteracji];
    double* quick_wynik_12 = new double[ilosc_iteracji];
#endif // defined
#if defined (STO_TYSIECY) && defined (QUICKSORT) && defined (POISSON)
    double* quick_wynik_13 = new double[ilosc_iteracji];
    double* quick_wynik_14 = new double[ilosc_iteracji];
    double* quick_wynik_15 = new double[ilosc_iteracji];
    double* quick_wynik_16 = new double[ilosc_iteracji];
#endif // defined
#if defined (MILION) && defined (QUICKSORT) && defined (POISSON)
    double* quick_wynik_17 = new double[ilosc_iteracji];
    double* quick_wynik_18 = new double[ilosc_iteracji];
    double* quick_wynik_19 = new double[ilosc_iteracji];
    double* quick_wynik_20 = new double[ilosc_iteracji];
#endif // defined
#if defined (STO) && defined (QUICKSORT) && defined (GAUSS)
    double* quick_wynik_21 = new double[ilosc_iteracji];
    double* quick_wynik_22 = new double[ilosc_iteracji];
    double* quick_wynik_23 = new double[ilosc_iteracji];
    double* quick_wynik_24 = new double[ilosc_iteracji];
#endif // defined
#if defined (TYSIAC) && defined (QUICKSORT) && defined (GAUSS)
    double* quick_wynik_25 = new double[ilosc_iteracji];
    double* quick_wynik_26 = new double[ilosc_iteracji];
    double* quick_wynik_27 = new double[ilosc_iteracji];
    double* quick_wynik_28 = new double[ilosc_iteracji];
#endif // defined
#if defined (DZIESIEC_TYSIECY) && defined (QUICKSORT) && defined (GAUSS)
    double* quick_wynik_29 = new double[ilosc_iteracji];
    double* quick_wynik_30 = new double[ilosc_iteracji];
    double* quick_wynik_31 = new double[ilosc_iteracji];
    double* quick_wynik_32 = new double[ilosc_iteracji];
#endif // defined
#if defined (STO_TYSIECY) && defined (QUICKSORT) && defined (GAUSS)
    double* quick_wynik_33 = new double[ilosc_iteracji];
    double* quick_wynik_34 = new double[ilosc_iteracji];
    double* quick_wynik_35 = new double[ilosc_iteracji];
    double* quick_wynik_36 = new double[ilosc_iteracji];
#endif // defined
#if defined (MILION) && defined (QUICKSORT) && defined (GAUSS)
    double* quick_wynik_37 = new double[ilosc_iteracji];
    double* quick_wynik_38 = new double[ilosc_iteracji];
    double* quick_wynik_39 = new double[ilosc_iteracji];
    double* quick_wynik_40 = new double[ilosc_iteracji];
#endif // defined
#if defined (STO) && defined (QUICKSORT) && defined (JEDNOSTAJNY)
    double* quick_wynik_41 = new double[ilosc_iteracji];
    double* quick_wynik_42 = new double[ilosc_iteracji];
    double* quick_wynik_43 = new double[ilosc_iteracji];
    double* quick_wynik_44 = new double[ilosc_iteracji];
#endif // defined
#if defined (TYSIAC) && defined (QUICKSORT) && defined (JEDNOSTAJNY)
    double* quick_wynik_45 = new double[ilosc_iteracji];
    double* quick_wynik_46 = new double[ilosc_iteracji];
    double* quick_wynik_47 = new double[ilosc_iteracji];
    double* quick_wynik_48 = new double[ilosc_iteracji];
#endif // defined
#if defined (DZIESIEC_TYSIECY) && defined (QUICKSORT) && defined (JEDNOSTAJNY)
    double* quick_wynik_49 = new double[ilosc_iteracji];
    double* quick_wynik_50 = new double[ilosc_iteracji];
    double* quick_wynik_51 = new double[ilosc_iteracji];
    double* quick_wynik_52 = new double[ilosc_iteracji];
#endif // defined
#if defined (STO_TYSIECY) && defined (QUICKSORT) && defined (JEDNOSTAJNY)
    double* quick_wynik_53 = new double[ilosc_iteracji];
    double* quick_wynik_54 = new double[ilosc_iteracji];
    double* quick_wynik_55 = new double[ilosc_iteracji];
    double* quick_wynik_56 = new double[ilosc_iteracji];
#endif // defined
#if defined (MILION) && defined (QUICKSORT) && defined (JEDNOSTAJNY)
    double* quick_wynik_57 = new double[ilosc_iteracji];
    double* quick_wynik_58 = new double[ilosc_iteracji];
    double* quick_wynik_59 = new double[ilosc_iteracji];
    double* quick_wynik_60 = new double[ilosc_iteracji];
#endif // defined
// ******************************************************************************************************/
//                                       Wyniki introsort                                                /
// ******************************************************************************************************/
#if defined (STO) && defined (INTROSORT) && defined (POISSON)
    double* introsort_wynik_1 = new double[ilosc_iteracji];
    double* introsort_wynik_2 = new double[ilosc_iteracji];
    double* introsort_wynik_3 = new double[ilosc_iteracji];
    double* introsort_wynik_4 = new double[ilosc_iteracji];
#endif // defined
#if defined (TYSIAC) && defined (INTROSORT) && defined (POISSON)
    double* introsort_wynik_5 = new double[ilosc_iteracji];
    double* introsort_wynik_6 = new double[ilosc_iteracji];
    double* introsort_wynik_7 = new double[ilosc_iteracji];
    double* introsort_wynik_8 = new double[ilosc_iteracji];
#endif // defined
#if defined (DZIESIEC_TYSIECY) && defined (INTROSORT) && defined (POISSON)
    double* introsort_wynik_9 = new double[ilosc_iteracji];
    double* introsort_wynik_10 = new double[ilosc_iteracji];
    double* introsort_wynik_11 = new double[ilosc_iteracji];
    double* introsort_wynik_12 = new double[ilosc_iteracji];
#endif // defined
#if defined (STO_TYSIECY) && defined (INTROSORT) && defined (POISSON)
    double* introsort_wynik_13 = new double[ilosc_iteracji];
    double* introsort_wynik_14 = new double[ilosc_iteracji];
    double* introsort_wynik_15 = new double[ilosc_iteracji];
    double* introsort_wynik_16 = new double[ilosc_iteracji];
#endif // defined
#if defined (MILION) && defined (INTROSORT) && defined (POISSON)
    double* introsort_wynik_17 = new double[ilosc_iteracji];
    double* introsort_wynik_18 = new double[ilosc_iteracji];
    double* introsort_wynik_19 = new double[ilosc_iteracji];
    double* introsort_wynik_20 = new double[ilosc_iteracji];
#endif // defined
#if defined (STO) && defined (INTROSORT) && defined (GAUSS)
    double* introsort_wynik_21 = new double[ilosc_iteracji];
    double* introsort_wynik_22 = new double[ilosc_iteracji];
    double* introsort_wynik_23 = new double[ilosc_iteracji];
    double* introsort_wynik_24 = new double[ilosc_iteracji];
#endif // defined
#if defined (TYSIAC) && defined (INTROSORT) && defined (GAUSS)
    double* introsort_wynik_25 = new double[ilosc_iteracji];
    double* introsort_wynik_26 = new double[ilosc_iteracji];
    double* introsort_wynik_27 = new double[ilosc_iteracji];
    double* introsort_wynik_28 = new double[ilosc_iteracji];
#endif // defined
#if defined (DZIESIEC_TYSIECY) && defined (INTROSORT) && defined (GAUSS)
    double* introsort_wynik_29 = new double[ilosc_iteracji];
    double* introsort_wynik_30 = new double[ilosc_iteracji];
    double* introsort_wynik_31 = new double[ilosc_iteracji];
    double* introsort_wynik_32 = new double[ilosc_iteracji];
#endif // defined
#if defined (STO_TYSIECY) && defined (INTROSORT) && defined (GAUSS)
    double* introsort_wynik_33 = new double[ilosc_iteracji];
    double* introsort_wynik_34 = new double[ilosc_iteracji];
    double* introsort_wynik_35 = new double[ilosc_iteracji];
    double* introsort_wynik_36 = new double[ilosc_iteracji];
#endif // defined
#if defined (MILION) && defined (INTROSORT) && defined (GAUSS)
    double* introsort_wynik_37 = new double[ilosc_iteracji];
    double* introsort_wynik_38 = new double[ilosc_iteracji];
    double* introsort_wynik_39 = new double[ilosc_iteracji];
    double* introsort_wynik_40 = new double[ilosc_iteracji];
#endif // defined
#if defined (STO) && defined (INTROSORT) && defined (JEDNOSTAJNY)
    double* introsort_wynik_41 = new double[ilosc_iteracji];
    double* introsort_wynik_42 = new double[ilosc_iteracji];
    double* introsort_wynik_43 = new double[ilosc_iteracji];
    double* introsort_wynik_44 = new double[ilosc_iteracji];
#endif // defined
#if defined (TYSIAC) && defined (INTROSORT) && defined (JEDNOSTAJNY)
    double* introsort_wynik_45 = new double[ilosc_iteracji];
    double* introsort_wynik_46 = new double[ilosc_iteracji];
    double* introsort_wynik_47 = new double[ilosc_iteracji];
    double* introsort_wynik_48 = new double[ilosc_iteracji];
#endif // defined
#if defined (DZIESIEC_TYSIECY) && defined (INTROSORT) && defined (JEDNOSTAJNY)
    double* introsort_wynik_49 = new double[ilosc_iteracji];
    double* introsort_wynik_50 = new double[ilosc_iteracji];
    double* introsort_wynik_51 = new double[ilosc_iteracji];
    double* introsort_wynik_52 = new double[ilosc_iteracji];
#endif // defined
#if defined (STO_TYSIECY) && defined (INTROSORT) && defined (JEDNOSTAJNY)
    double* introsort_wynik_53 = new double[ilosc_iteracji];
    double* introsort_wynik_54 = new double[ilosc_iteracji];
    double* introsort_wynik_55 = new double[ilosc_iteracji];
    double* introsort_wynik_56 = new double[ilosc_iteracji];
#endif // defined
#if defined (MILION) && defined (INTROSORT) && defined (JEDNOSTAJNY)
    double* introsort_wynik_57 = new double[ilosc_iteracji];
    double* introsort_wynik_58 = new double[ilosc_iteracji];
    double* introsort_wynik_59 = new double[ilosc_iteracji];
    double* introsort_wynik_60 = new double[ilosc_iteracji];
#endif // defined
// ******************************************************************************************************/
//                                       Koniec wynikow                                                  /
// ******************************************************************************************************/


for(int iteracja = 0; iteracja < ilosc_iteracji;iteracja++){

    StartCounter();

// ******************************************************************************************************/
//                            Generowanie tablic dla wstawiania                                          /
// ******************************************************************************************************/
#if defined (STO) && defined (WSTAWIANIE) && defined (POISSON)
    int* wstawianie_poisson_1 = new int[100]; wstawianie_poisson_1 = poisson(100);
    int* wstawianie_poisson_2 = new int[100]; wstawianie_poisson_2 = poisson(100); wstawianie_poisson_2 = posortuj_czesciowo(wstawianie_poisson_2,50);
    int* wstawianie_poisson_3 = new int[100]; wstawianie_poisson_3 = poisson(100); wstawianie_poisson_3 = posortuj_czesciowo(wstawianie_poisson_3,90);
    int* wstawianie_poisson_4 = new int[100]; wstawianie_poisson_4 = poisson(100); wstawianie_poisson_4 = posortuj_czesciowo(wstawianie_poisson_4,99);
#endif
#if defined (TYSIAC) && defined (WSTAWIANIE) && defined (POISSON)
    int* wstawianie_poisson_5 = new int[1000]; wstawianie_poisson_5 = poisson(1000);
    int* wstawianie_poisson_6 = new int[1000]; wstawianie_poisson_6 = poisson(1000); wstawianie_poisson_6 = posortuj_czesciowo(wstawianie_poisson_6,500);
    int* wstawianie_poisson_7 = new int[1000]; wstawianie_poisson_7 = poisson(1000); wstawianie_poisson_7 = posortuj_czesciowo(wstawianie_poisson_7,900);
    int* wstawianie_poisson_8 = new int[1000]; wstawianie_poisson_8 = poisson(1000); wstawianie_poisson_8 = posortuj_czesciowo(wstawianie_poisson_8,990);
#endif
#if defined (DZIESIEC_TYSIECY) && defined (WSTAWIANIE) && defined (POISSON)
    int* wstawianie_poisson_9  = new int[10000]; wstawianie_poisson_9  = poisson(10000);
    int* wstawianie_poisson_10 = new int[10000]; wstawianie_poisson_10 = poisson(10000); wstawianie_poisson_10 = posortuj_czesciowo(wstawianie_poisson_10,5000);
    int* wstawianie_poisson_11 = new int[10000]; wstawianie_poisson_11 = poisson(10000); wstawianie_poisson_11 = posortuj_czesciowo(wstawianie_poisson_11,9000);
    int* wstawianie_poisson_12 = new int[10000]; wstawianie_poisson_12 = poisson(10000); wstawianie_poisson_12 = posortuj_czesciowo(wstawianie_poisson_12,9900);
#endif
#if defined (STO_TYSIECY) && defined (WSTAWIANIE) && defined (POISSON)
    int* wstawianie_poisson_13 = new int[100000]; wstawianie_poisson_13 = poisson(100000);
    int* wstawianie_poisson_14 = new int[100000]; wstawianie_poisson_14 = poisson(100000); wstawianie_poisson_14 = posortuj_czesciowo(wstawianie_poisson_14,50000);
    int* wstawianie_poisson_15 = new int[100000]; wstawianie_poisson_15 = poisson(100000); wstawianie_poisson_15 = posortuj_czesciowo(wstawianie_poisson_15,90000);
    int* wstawianie_poisson_16 = new int[100000]; wstawianie_poisson_16 = poisson(100000); wstawianie_poisson_16 = posortuj_czesciowo(wstawianie_poisson_16,99000);
#endif
#if defined (MILION) && defined (WSTAWIANIE) && defined (POISSON)
    int* wstawianie_poisson_17 = new int[1000000]; wstawianie_poisson_17 = poisson(1000000);
    int* wstawianie_poisson_18 = new int[1000000]; wstawianie_poisson_18 = poisson(1000000); wstawianie_poisson_18 = posortuj_czesciowo(wstawianie_poisson_18,500000);
    int* wstawianie_poisson_19 = new int[1000000]; wstawianie_poisson_19 = poisson(1000000); wstawianie_poisson_19 = posortuj_czesciowo(wstawianie_poisson_19,900000);
    int* wstawianie_poisson_20 = new int[1000000]; wstawianie_poisson_20 = poisson(1000000); wstawianie_poisson_20 = posortuj_czesciowo(wstawianie_poisson_20,990000);
#endif

#if defined (STO) && defined (WSTAWIANIE) && defined (GAUSS)
    int* wstawianie_gauss_1 = new int[100]; wstawianie_gauss_1 = gauss(100);
    int* wstawianie_gauss_2 = new int[100]; wstawianie_gauss_2 = gauss(100); wstawianie_gauss_2 = posortuj_czesciowo(wstawianie_gauss_2,50);
    int* wstawianie_gauss_3 = new int[100]; wstawianie_gauss_3 = gauss(100); wstawianie_gauss_3 = posortuj_czesciowo(wstawianie_gauss_3,90);
    int* wstawianie_gauss_4 = new int[100]; wstawianie_gauss_4 = gauss(100); wstawianie_gauss_4 = posortuj_czesciowo(wstawianie_gauss_4,99);
#endif
#if defined (TYSIAC) && defined (WSTAWIANIE) && defined (GAUSS)
    int* wstawianie_gauss_5 = new int[1000]; wstawianie_gauss_5 = gauss(1000);
    int* wstawianie_gauss_6 = new int[1000]; wstawianie_gauss_6 = gauss(1000); wstawianie_gauss_6 = posortuj_czesciowo(wstawianie_gauss_6,500);
    int* wstawianie_gauss_7 = new int[1000]; wstawianie_gauss_7 = gauss(1000); wstawianie_gauss_7 = posortuj_czesciowo(wstawianie_gauss_7,900);
    int* wstawianie_gauss_8 = new int[1000]; wstawianie_gauss_8 = gauss(1000); wstawianie_gauss_8 = posortuj_czesciowo(wstawianie_gauss_8,990);
#endif
#if defined (DZIESIEC_TYSIECY) && defined (WSTAWIANIE) && defined (GAUSS)
    int* wstawianie_gauss_9  = new int[10000]; wstawianie_gauss_9  = gauss(10000);
    int* wstawianie_gauss_10 = new int[10000]; wstawianie_gauss_10 = gauss(10000); wstawianie_gauss_10 = posortuj_czesciowo(wstawianie_gauss_10,5000);
    int* wstawianie_gauss_11 = new int[10000]; wstawianie_gauss_11 = gauss(10000); wstawianie_gauss_11 = posortuj_czesciowo(wstawianie_gauss_11,9000);
    int* wstawianie_gauss_12 = new int[10000]; wstawianie_gauss_12 = gauss(10000); wstawianie_gauss_12 = posortuj_czesciowo(wstawianie_gauss_12,9900);
#endif
#if defined (STO_TYSIECY) && defined (WSTAWIANIE) && defined (GAUSS)
    int* wstawianie_gauss_13 = new int[100000]; wstawianie_gauss_13 = gauss(100000);
    int* wstawianie_gauss_14 = new int[100000]; wstawianie_gauss_14 = gauss(100000); wstawianie_gauss_14 = posortuj_czesciowo(wstawianie_gauss_14,50000);
    int* wstawianie_gauss_15 = new int[100000]; wstawianie_gauss_15 = gauss(100000); wstawianie_gauss_15 = posortuj_czesciowo(wstawianie_gauss_15,90000);
    int* wstawianie_gauss_16 = new int[100000]; wstawianie_gauss_16 = gauss(100000); wstawianie_gauss_16 = posortuj_czesciowo(wstawianie_gauss_16,99000);
#endif
#if defined (MILION) && defined (WSTAWIANIE) && defined (GAUSS)
    int* wstawianie_gauss_17 = new int[1000000]; wstawianie_gauss_17 = gauss(1000000);
    int* wstawianie_gauss_18 = new int[1000000]; wstawianie_gauss_18 = gauss(1000000); wstawianie_gauss_18 = posortuj_czesciowo(wstawianie_gauss_18,500000);
    int* wstawianie_gauss_19 = new int[1000000]; wstawianie_gauss_19 = gauss(1000000); wstawianie_gauss_19 = posortuj_czesciowo(wstawianie_gauss_19,900000);
    int* wstawianie_gauss_20 = new int[1000000]; wstawianie_gauss_20 = gauss(1000000); wstawianie_gauss_20 = posortuj_czesciowo(wstawianie_gauss_20,990000);
#endif

#if defined (STO) && defined (WSTAWIANIE) && defined (JEDNOSTAJNY)
    int* wstawianie_jednostajny_1 = new int[100]; wstawianie_jednostajny_1 = jednostajny(100);
    int* wstawianie_jednostajny_2 = new int[100]; wstawianie_jednostajny_2 = jednostajny(100); wstawianie_jednostajny_2 = posortuj_czesciowo(wstawianie_jednostajny_2,50);
    int* wstawianie_jednostajny_3 = new int[100]; wstawianie_jednostajny_3 = jednostajny(100); wstawianie_jednostajny_3 = posortuj_czesciowo(wstawianie_jednostajny_3,90);
    int* wstawianie_jednostajny_4 = new int[100]; wstawianie_jednostajny_4 = jednostajny(100); wstawianie_jednostajny_4 = posortuj_czesciowo(wstawianie_jednostajny_4,99);
#endif
#if defined (TYSIAC) && defined (WSTAWIANIE) && defined (JEDNOSTAJNY)
    int* wstawianie_jednostajny_5 = new int[1000]; wstawianie_jednostajny_5 = jednostajny(1000);
    int* wstawianie_jednostajny_6 = new int[1000]; wstawianie_jednostajny_6 = jednostajny(1000); wstawianie_jednostajny_6 = posortuj_czesciowo(wstawianie_jednostajny_6,500);
    int* wstawianie_jednostajny_7 = new int[1000]; wstawianie_jednostajny_7 = jednostajny(1000); wstawianie_jednostajny_7 = posortuj_czesciowo(wstawianie_jednostajny_7,900);
    int* wstawianie_jednostajny_8 = new int[1000]; wstawianie_jednostajny_8 = jednostajny(1000); wstawianie_jednostajny_8 = posortuj_czesciowo(wstawianie_jednostajny_8,990);
#endif
#if defined (DZIESIEC_TYSIECY) && defined (WSTAWIANIE) && defined (JEDNOSTAJNY)
    int* wstawianie_jednostajny_9  = new int[10000]; wstawianie_jednostajny_9  = jednostajny(10000);
    int* wstawianie_jednostajny_10 = new int[10000]; wstawianie_jednostajny_10 = jednostajny(10000); wstawianie_jednostajny_10 = posortuj_czesciowo(wstawianie_jednostajny_10,5000);
    int* wstawianie_jednostajny_11 = new int[10000]; wstawianie_jednostajny_11 = jednostajny(10000); wstawianie_jednostajny_11 = posortuj_czesciowo(wstawianie_jednostajny_11,9000);
    int* wstawianie_jednostajny_12 = new int[10000]; wstawianie_jednostajny_12 = jednostajny(10000); wstawianie_jednostajny_12 = posortuj_czesciowo(wstawianie_jednostajny_12,9900);
#endif
#if defined (STO_TYSIECY) && defined (WSTAWIANIE) && defined (JEDNOSTAJNY)
    int* wstawianie_jednostajny_13 = new int[100000]; wstawianie_jednostajny_13 = jednostajny(100000);
    int* wstawianie_jednostajny_14 = new int[100000]; wstawianie_jednostajny_14 = jednostajny(100000); wstawianie_jednostajny_14 = posortuj_czesciowo(wstawianie_jednostajny_14,50000);
    int* wstawianie_jednostajny_15 = new int[100000]; wstawianie_jednostajny_15 = jednostajny(100000); wstawianie_jednostajny_15 = posortuj_czesciowo(wstawianie_jednostajny_15,90000);
    int* wstawianie_jednostajny_16 = new int[100000]; wstawianie_jednostajny_16 = jednostajny(100000); wstawianie_jednostajny_16 = posortuj_czesciowo(wstawianie_jednostajny_16,99000);
#endif
#if defined (MILION) && defined (WSTAWIANIE) && defined (JEDNOSTAJNY)
    int* wstawianie_jednostajny_17 = new int[1000000]; wstawianie_jednostajny_17 = jednostajny(1000000);
    int* wstawianie_jednostajny_18 = new int[1000000]; wstawianie_jednostajny_18 = jednostajny(1000000); wstawianie_jednostajny_18 = posortuj_czesciowo(wstawianie_jednostajny_18,500000);
    int* wstawianie_jednostajny_19 = new int[1000000]; wstawianie_jednostajny_19 = jednostajny(1000000); wstawianie_jednostajny_19 = posortuj_czesciowo(wstawianie_jednostajny_19,900000);
    int* wstawianie_jednostajny_20 = new int[1000000]; wstawianie_jednostajny_20 = jednostajny(1000000); wstawianie_jednostajny_20 = posortuj_czesciowo(wstawianie_jednostajny_20,990000);
#endif
// ******************************************************************************************************/
//                            Generowanie tablic dla kopcowania                                          /
// ******************************************************************************************************/
#if defined (STO) && defined (KOPCOWANIE) && defined (POISSON)
    int* kopcowanie_poisson_1 = new int[100]; kopcowanie_poisson_1 = poisson(100);
    int* kopcowanie_poisson_2 = new int[100]; kopcowanie_poisson_2 = poisson(100); kopcowanie_poisson_2 = posortuj_czesciowo(kopcowanie_poisson_2,50);
    int* kopcowanie_poisson_3 = new int[100]; kopcowanie_poisson_3 = poisson(100); kopcowanie_poisson_3 = posortuj_czesciowo(kopcowanie_poisson_3,90);
    int* kopcowanie_poisson_4 = new int[100]; kopcowanie_poisson_4 = poisson(100); kopcowanie_poisson_4 = posortuj_czesciowo(kopcowanie_poisson_4,99);
#endif
#if defined (TYSIAC) && defined (KOPCOWANIE) && defined (POISSON)
    int* kopcowanie_poisson_5 = new int[1000]; kopcowanie_poisson_5 = poisson(1000);
    int* kopcowanie_poisson_6 = new int[1000]; kopcowanie_poisson_6 = poisson(1000); kopcowanie_poisson_6 = posortuj_czesciowo(kopcowanie_poisson_6,500);
    int* kopcowanie_poisson_7 = new int[1000]; kopcowanie_poisson_7 = poisson(1000); kopcowanie_poisson_7 = posortuj_czesciowo(kopcowanie_poisson_7,900);
    int* kopcowanie_poisson_8 = new int[1000]; kopcowanie_poisson_8 = poisson(1000); kopcowanie_poisson_8 = posortuj_czesciowo(kopcowanie_poisson_8,990);
#endif
#if defined (DZIESIEC_TYSIECY) && defined (KOPCOWANIE) && defined (POISSON)
    int* kopcowanie_poisson_9  = new int[10000]; kopcowanie_poisson_9  = poisson(10000);
    int* kopcowanie_poisson_10 = new int[10000]; kopcowanie_poisson_10 = poisson(10000); kopcowanie_poisson_10 = posortuj_czesciowo(kopcowanie_poisson_10,5000);
    int* kopcowanie_poisson_11 = new int[10000]; kopcowanie_poisson_11 = poisson(10000); kopcowanie_poisson_11 = posortuj_czesciowo(kopcowanie_poisson_11,9000);
    int* kopcowanie_poisson_12 = new int[10000]; kopcowanie_poisson_12 = poisson(10000); kopcowanie_poisson_12 = posortuj_czesciowo(kopcowanie_poisson_12,9900);
#endif
#if defined (STO_TYSIECY) && defined (KOPCOWANIE) && defined (POISSON)
    int* kopcowanie_poisson_13 = new int[100000]; kopcowanie_poisson_13 = poisson(100000);
    int* kopcowanie_poisson_14 = new int[100000]; kopcowanie_poisson_14 = poisson(100000); kopcowanie_poisson_14 = posortuj_czesciowo(kopcowanie_poisson_14,50000);
    int* kopcowanie_poisson_15 = new int[100000]; kopcowanie_poisson_15 = poisson(100000); kopcowanie_poisson_15 = posortuj_czesciowo(kopcowanie_poisson_15,90000);
    int* kopcowanie_poisson_16 = new int[100000]; kopcowanie_poisson_16 = poisson(100000); kopcowanie_poisson_16 = posortuj_czesciowo(kopcowanie_poisson_16,99000);
#endif
#if defined (MILION) && defined (KOPCOWANIE) && defined (POISSON)
    int* kopcowanie_poisson_17 = new int[1000000]; kopcowanie_poisson_17 = poisson(1000000);
    int* kopcowanie_poisson_18 = new int[1000000]; kopcowanie_poisson_18 = poisson(1000000); kopcowanie_poisson_18 = posortuj_czesciowo(kopcowanie_poisson_18,500000);
    int* kopcowanie_poisson_19 = new int[1000000]; kopcowanie_poisson_19 = poisson(1000000); kopcowanie_poisson_19 = posortuj_czesciowo(kopcowanie_poisson_19,900000);
    int* kopcowanie_poisson_20 = new int[1000000]; kopcowanie_poisson_20 = poisson(1000000); kopcowanie_poisson_20 = posortuj_czesciowo(kopcowanie_poisson_20,990000);
#endif

#if defined (STO) && defined (KOPCOWANIE) && defined (GAUSS)
    int* kopcowanie_gauss_1 = new int[100]; kopcowanie_gauss_1 = gauss(100);
    int* kopcowanie_gauss_2 = new int[100]; kopcowanie_gauss_2 = gauss(100); kopcowanie_gauss_2 = posortuj_czesciowo(kopcowanie_gauss_2,50);
    int* kopcowanie_gauss_3 = new int[100]; kopcowanie_gauss_3 = gauss(100); kopcowanie_gauss_3 = posortuj_czesciowo(kopcowanie_gauss_3,90);
    int* kopcowanie_gauss_4 = new int[100]; kopcowanie_gauss_4 = gauss(100); kopcowanie_gauss_4 = posortuj_czesciowo(kopcowanie_gauss_4,99);
#endif
#if defined (TYSIAC) && defined (KOPCOWANIE) && defined (GAUSS)
    int* kopcowanie_gauss_5 = new int[1000]; kopcowanie_gauss_5 = gauss(1000);
    int* kopcowanie_gauss_6 = new int[1000]; kopcowanie_gauss_6 = gauss(1000); kopcowanie_gauss_6 = posortuj_czesciowo(kopcowanie_gauss_6,500);
    int* kopcowanie_gauss_7 = new int[1000]; kopcowanie_gauss_7 = gauss(1000); kopcowanie_gauss_7 = posortuj_czesciowo(kopcowanie_gauss_7,900);
    int* kopcowanie_gauss_8 = new int[1000]; kopcowanie_gauss_8 = gauss(1000); kopcowanie_gauss_8 = posortuj_czesciowo(kopcowanie_gauss_8,990);
#endif
#if defined (DZIESIEC_TYSIECY) && defined (KOPCOWANIE) && defined (GAUSS)
    int* kopcowanie_gauss_9  = new int[10000]; kopcowanie_gauss_9  = gauss(10000);
    int* kopcowanie_gauss_10 = new int[10000]; kopcowanie_gauss_10 = gauss(10000); kopcowanie_gauss_10 = posortuj_czesciowo(kopcowanie_gauss_10,5000);
    int* kopcowanie_gauss_11 = new int[10000]; kopcowanie_gauss_11 = gauss(10000); kopcowanie_gauss_11 = posortuj_czesciowo(kopcowanie_gauss_11,9000);
    int* kopcowanie_gauss_12 = new int[10000]; kopcowanie_gauss_12 = gauss(10000); kopcowanie_gauss_12 = posortuj_czesciowo(kopcowanie_gauss_12,9900);
#endif
#if defined (STO_TYSIECY) && defined (KOPCOWANIE) && defined (GAUSS)
    int* kopcowanie_gauss_13 = new int[100000]; kopcowanie_gauss_13 = gauss(100000);
    int* kopcowanie_gauss_14 = new int[100000]; kopcowanie_gauss_14 = gauss(100000); kopcowanie_gauss_14 = posortuj_czesciowo(kopcowanie_gauss_14,50000);
    int* kopcowanie_gauss_15 = new int[100000]; kopcowanie_gauss_15 = gauss(100000); kopcowanie_gauss_15 = posortuj_czesciowo(kopcowanie_gauss_15,90000);
    int* kopcowanie_gauss_16 = new int[100000]; kopcowanie_gauss_16 = gauss(100000); kopcowanie_gauss_16 = posortuj_czesciowo(kopcowanie_gauss_16,99000);
#endif
#if defined (MILION) && defined (KOPCOWANIE) && defined (GAUSS)
    int* kopcowanie_gauss_17 = new int[1000000]; kopcowanie_gauss_17 = gauss(1000000);
    int* kopcowanie_gauss_18 = new int[1000000]; kopcowanie_gauss_18 = gauss(1000000); kopcowanie_gauss_18 = posortuj_czesciowo(kopcowanie_gauss_18,500000);
    int* kopcowanie_gauss_19 = new int[1000000]; kopcowanie_gauss_19 = gauss(1000000); kopcowanie_gauss_19 = posortuj_czesciowo(kopcowanie_gauss_19,900000);
    int* kopcowanie_gauss_20 = new int[1000000]; kopcowanie_gauss_20 = gauss(1000000); kopcowanie_gauss_20 = posortuj_czesciowo(kopcowanie_gauss_20,990000);
#endif

#if defined (STO) && defined (KOPCOWANIE) && defined (JEDNOSTAJNY)
    int* kopcowanie_jednostajny_1 = new int[100]; kopcowanie_jednostajny_1 = jednostajny(100);
    int* kopcowanie_jednostajny_2 = new int[100]; kopcowanie_jednostajny_2 = jednostajny(100); kopcowanie_jednostajny_2 = posortuj_czesciowo(kopcowanie_jednostajny_2,50);
    int* kopcowanie_jednostajny_3 = new int[100]; kopcowanie_jednostajny_3 = jednostajny(100); kopcowanie_jednostajny_3 = posortuj_czesciowo(kopcowanie_jednostajny_3,90);
    int* kopcowanie_jednostajny_4 = new int[100]; kopcowanie_jednostajny_4 = jednostajny(100); kopcowanie_jednostajny_4 = posortuj_czesciowo(kopcowanie_jednostajny_4,99);
#endif
#if defined (TYSIAC) && defined (KOPCOWANIE) && defined (JEDNOSTAJNY)
    int* kopcowanie_jednostajny_5 = new int[1000]; kopcowanie_jednostajny_5 = jednostajny(1000);
    int* kopcowanie_jednostajny_6 = new int[1000]; kopcowanie_jednostajny_6 = jednostajny(1000); kopcowanie_jednostajny_6 = posortuj_czesciowo(kopcowanie_jednostajny_6,500);
    int* kopcowanie_jednostajny_7 = new int[1000]; kopcowanie_jednostajny_7 = jednostajny(1000); kopcowanie_jednostajny_7 = posortuj_czesciowo(kopcowanie_jednostajny_7,900);
    int* kopcowanie_jednostajny_8 = new int[1000]; kopcowanie_jednostajny_8 = jednostajny(1000); kopcowanie_jednostajny_8 = posortuj_czesciowo(kopcowanie_jednostajny_8,990);
#endif
#if defined (DZIESIEC_TYSIECY) && defined (KOPCOWANIE) && defined (JEDNOSTAJNY)
    int* kopcowanie_jednostajny_9  = new int[10000]; kopcowanie_jednostajny_9  = jednostajny(10000);
    int* kopcowanie_jednostajny_10 = new int[10000]; kopcowanie_jednostajny_10 = jednostajny(10000); kopcowanie_jednostajny_10 = posortuj_czesciowo(kopcowanie_jednostajny_10,5000);
    int* kopcowanie_jednostajny_11 = new int[10000]; kopcowanie_jednostajny_11 = jednostajny(10000); kopcowanie_jednostajny_11 = posortuj_czesciowo(kopcowanie_jednostajny_11,9000);
    int* kopcowanie_jednostajny_12 = new int[10000]; kopcowanie_jednostajny_12 = jednostajny(10000); kopcowanie_jednostajny_12 = posortuj_czesciowo(kopcowanie_jednostajny_12,9900);
#endif
#if defined (STO_TYSIECY) && defined (KOPCOWANIE) && defined (JEDNOSTAJNY)
    int* kopcowanie_jednostajny_13 = new int[100000]; kopcowanie_jednostajny_13 = jednostajny(100000);
    int* kopcowanie_jednostajny_14 = new int[100000]; kopcowanie_jednostajny_14 = jednostajny(100000); kopcowanie_jednostajny_14 = posortuj_czesciowo(kopcowanie_jednostajny_14,50000);
    int* kopcowanie_jednostajny_15 = new int[100000]; kopcowanie_jednostajny_15 = jednostajny(100000); kopcowanie_jednostajny_15 = posortuj_czesciowo(kopcowanie_jednostajny_15,90000);
    int* kopcowanie_jednostajny_16 = new int[100000]; kopcowanie_jednostajny_16 = jednostajny(100000); kopcowanie_jednostajny_16 = posortuj_czesciowo(kopcowanie_jednostajny_16,99000);
#endif
#if defined (MILION) && defined (KOPCOWANIE) && defined (JEDNOSTAJNY)
    int* kopcowanie_jednostajny_17 = new int[1000000]; kopcowanie_jednostajny_17 = jednostajny(1000000);
    int* kopcowanie_jednostajny_18 = new int[1000000]; kopcowanie_jednostajny_18 = jednostajny(1000000); kopcowanie_jednostajny_18 = posortuj_czesciowo(kopcowanie_jednostajny_18,500000);
    int* kopcowanie_jednostajny_19 = new int[1000000]; kopcowanie_jednostajny_19 = jednostajny(1000000); kopcowanie_jednostajny_19 = posortuj_czesciowo(kopcowanie_jednostajny_19,900000);
    int* kopcowanie_jednostajny_20 = new int[1000000]; kopcowanie_jednostajny_20 = jednostajny(1000000); kopcowanie_jednostajny_20 = posortuj_czesciowo(kopcowanie_jednostajny_20,990000);
#endif
// ******************************************************************************************************/
//                            Generowanie tablic dla shell                                               /
// ******************************************************************************************************/
#if defined (STO) && defined (SHELL) && defined (POISSON)
    int* shell_poisson_1 = new int[100]; shell_poisson_1 = poisson(100);
    int* shell_poisson_2 = new int[100]; shell_poisson_2 = poisson(100); shell_poisson_2 = posortuj_czesciowo(shell_poisson_2,50);
    int* shell_poisson_3 = new int[100]; shell_poisson_3 = poisson(100); shell_poisson_3 = posortuj_czesciowo(shell_poisson_3,90);
    int* shell_poisson_4 = new int[100]; shell_poisson_4 = poisson(100); shell_poisson_4 = posortuj_czesciowo(shell_poisson_4,99);
#endif
#if defined (TYSIAC) && defined (SHELL) && defined (POISSON)
    int* shell_poisson_5 = new int[1000]; shell_poisson_5 = poisson(1000);
    int* shell_poisson_6 = new int[1000]; shell_poisson_6 = poisson(1000); shell_poisson_6 = posortuj_czesciowo(shell_poisson_6,500);
    int* shell_poisson_7 = new int[1000]; shell_poisson_7 = poisson(1000); shell_poisson_7 = posortuj_czesciowo(shell_poisson_7,900);
    int* shell_poisson_8 = new int[1000]; shell_poisson_8 = poisson(1000); shell_poisson_8 = posortuj_czesciowo(shell_poisson_8,990);
#endif
#if defined (DZIESIEC_TYSIECY) && defined (SHELL) && defined (POISSON)
    int* shell_poisson_9  = new int[10000]; shell_poisson_9  = poisson(10000);
    int* shell_poisson_10 = new int[10000]; shell_poisson_10 = poisson(10000); shell_poisson_10 = posortuj_czesciowo(shell_poisson_10,5000);
    int* shell_poisson_11 = new int[10000]; shell_poisson_11 = poisson(10000); shell_poisson_11 = posortuj_czesciowo(shell_poisson_11,9000);
    int* shell_poisson_12 = new int[10000]; shell_poisson_12 = poisson(10000); shell_poisson_12 = posortuj_czesciowo(shell_poisson_12,9900);
#endif
#if defined (STO_TYSIECY) && defined (SHELL) && defined (POISSON)
    int* shell_poisson_13 = new int[100000]; shell_poisson_13 = poisson(100000);
    int* shell_poisson_14 = new int[100000]; shell_poisson_14 = poisson(100000); shell_poisson_14 = posortuj_czesciowo(shell_poisson_14,50000);
    int* shell_poisson_15 = new int[100000]; shell_poisson_15 = poisson(100000); shell_poisson_15 = posortuj_czesciowo(shell_poisson_15,90000);
    int* shell_poisson_16 = new int[100000]; shell_poisson_16 = poisson(100000); shell_poisson_16 = posortuj_czesciowo(shell_poisson_16,99000);
#endif
#if defined (MILION) && defined (SHELL) && defined (POISSON)
    int* shell_poisson_17 = new int[1000000]; shell_poisson_17 = poisson(1000000);
    int* shell_poisson_18 = new int[1000000]; shell_poisson_18 = poisson(1000000); shell_poisson_18 = posortuj_czesciowo(shell_poisson_18,500000);
    int* shell_poisson_19 = new int[1000000]; shell_poisson_19 = poisson(1000000); shell_poisson_19 = posortuj_czesciowo(shell_poisson_19,900000);
    int* shell_poisson_20 = new int[1000000]; shell_poisson_20 = poisson(1000000); shell_poisson_20 = posortuj_czesciowo(shell_poisson_20,990000);
#endif

#if defined (STO) && defined (SHELL) && defined (GAUSS)
    int* shell_gauss_1 = new int[100]; shell_gauss_1 = gauss(100);
    int* shell_gauss_2 = new int[100]; shell_gauss_2 = gauss(100); shell_gauss_2 = posortuj_czesciowo(shell_gauss_2,50);
    int* shell_gauss_3 = new int[100]; shell_gauss_3 = gauss(100); shell_gauss_3 = posortuj_czesciowo(shell_gauss_3,90);
    int* shell_gauss_4 = new int[100]; shell_gauss_4 = gauss(100); shell_gauss_4 = posortuj_czesciowo(shell_gauss_4,99);
#endif
#if defined (TYSIAC) && defined (SHELL) && defined (GAUSS)
    int* shell_gauss_5 = new int[1000]; shell_gauss_5 = gauss(1000);
    int* shell_gauss_6 = new int[1000]; shell_gauss_6 = gauss(1000); shell_gauss_6 = posortuj_czesciowo(shell_gauss_6,500);
    int* shell_gauss_7 = new int[1000]; shell_gauss_7 = gauss(1000); shell_gauss_7 = posortuj_czesciowo(shell_gauss_7,900);
    int* shell_gauss_8 = new int[1000]; shell_gauss_8 = gauss(1000); shell_gauss_8 = posortuj_czesciowo(shell_gauss_8,990);
#endif
#if defined (DZIESIEC_TYSIECY) && defined (SHELL) && defined (GAUSS)
    int* shell_gauss_9  = new int[10000]; shell_gauss_9  = gauss(10000);
    int* shell_gauss_10 = new int[10000]; shell_gauss_10 = gauss(10000); shell_gauss_10 = posortuj_czesciowo(shell_gauss_10,5000);
    int* shell_gauss_11 = new int[10000]; shell_gauss_11 = gauss(10000); shell_gauss_11 = posortuj_czesciowo(shell_gauss_11,9000);
    int* shell_gauss_12 = new int[10000]; shell_gauss_12 = gauss(10000); shell_gauss_12 = posortuj_czesciowo(shell_gauss_12,9900);
#endif
#if defined (STO_TYSIECY) && defined (SHELL) && defined (GAUSS)
    int* shell_gauss_13 = new int[100000]; shell_gauss_13 = gauss(100000);
    int* shell_gauss_14 = new int[100000]; shell_gauss_14 = gauss(100000); shell_gauss_14 = posortuj_czesciowo(shell_gauss_14,50000);
    int* shell_gauss_15 = new int[100000]; shell_gauss_15 = gauss(100000); shell_gauss_15 = posortuj_czesciowo(shell_gauss_15,90000);
    int* shell_gauss_16 = new int[100000]; shell_gauss_16 = gauss(100000); shell_gauss_16 = posortuj_czesciowo(shell_gauss_16,99000);
#endif
#if defined (MILION) && defined (SHELL) && defined (GAUSS)
    int* shell_gauss_17 = new int[1000000]; shell_gauss_17 = gauss(1000000);
    int* shell_gauss_18 = new int[1000000]; shell_gauss_18 = gauss(1000000); shell_gauss_18 = posortuj_czesciowo(shell_gauss_18,500000);
    int* shell_gauss_19 = new int[1000000]; shell_gauss_19 = gauss(1000000); shell_gauss_19 = posortuj_czesciowo(shell_gauss_19,900000);
    int* shell_gauss_20 = new int[1000000]; shell_gauss_20 = gauss(1000000); shell_gauss_20 = posortuj_czesciowo(shell_gauss_20,990000);
#endif

#if defined (STO) && defined (SHELL) && defined (JEDNOSTAJNY)
    int* shell_jednostajny_1 = new int[100]; shell_jednostajny_1 = jednostajny(100);
    int* shell_jednostajny_2 = new int[100]; shell_jednostajny_2 = jednostajny(100); shell_jednostajny_2 = posortuj_czesciowo(shell_jednostajny_2,50);
    int* shell_jednostajny_3 = new int[100]; shell_jednostajny_3 = jednostajny(100); shell_jednostajny_3 = posortuj_czesciowo(shell_jednostajny_3,90);
    int* shell_jednostajny_4 = new int[100]; shell_jednostajny_4 = jednostajny(100); shell_jednostajny_4 = posortuj_czesciowo(shell_jednostajny_4,99);
#endif
#if defined (TYSIAC) && defined (SHELL) && defined (JEDNOSTAJNY)
    int* shell_jednostajny_5 = new int[1000]; shell_jednostajny_5 = jednostajny(1000);
    int* shell_jednostajny_6 = new int[1000]; shell_jednostajny_6 = jednostajny(1000); shell_jednostajny_6 = posortuj_czesciowo(shell_jednostajny_6,500);
    int* shell_jednostajny_7 = new int[1000]; shell_jednostajny_7 = jednostajny(1000); shell_jednostajny_7 = posortuj_czesciowo(shell_jednostajny_7,900);
    int* shell_jednostajny_8 = new int[1000]; shell_jednostajny_8 = jednostajny(1000); shell_jednostajny_8 = posortuj_czesciowo(shell_jednostajny_8,990);
#endif
#if defined (DZIESIEC_TYSIECY) && defined (SHELL) && defined (JEDNOSTAJNY)
    int* shell_jednostajny_9  = new int[10000]; shell_jednostajny_9  = jednostajny(10000);
    int* shell_jednostajny_10 = new int[10000]; shell_jednostajny_10 = jednostajny(10000); shell_jednostajny_10 = posortuj_czesciowo(shell_jednostajny_10,5000);
    int* shell_jednostajny_11 = new int[10000]; shell_jednostajny_11 = jednostajny(10000); shell_jednostajny_11 = posortuj_czesciowo(shell_jednostajny_11,9000);
    int* shell_jednostajny_12 = new int[10000]; shell_jednostajny_12 = jednostajny(10000); shell_jednostajny_12 = posortuj_czesciowo(shell_jednostajny_12,9900);
#endif
#if defined (STO_TYSIECY) && defined (SHELL) && defined (JEDNOSTAJNY)
    int* shell_jednostajny_13 = new int[100000]; shell_jednostajny_13 = jednostajny(100000);
    int* shell_jednostajny_14 = new int[100000]; shell_jednostajny_14 = jednostajny(100000); shell_jednostajny_14 = posortuj_czesciowo(shell_jednostajny_14,50000);
    int* shell_jednostajny_15 = new int[100000]; shell_jednostajny_15 = jednostajny(100000); shell_jednostajny_15 = posortuj_czesciowo(shell_jednostajny_15,90000);
    int* shell_jednostajny_16 = new int[100000]; shell_jednostajny_16 = jednostajny(100000); shell_jednostajny_16 = posortuj_czesciowo(shell_jednostajny_16,99000);
#endif
#if defined (MILION) && defined (SHELL) && defined (JEDNOSTAJNY)
    int* shell_jednostajny_17 = new int[1000000]; shell_jednostajny_17 = jednostajny(1000000);
    int* shell_jednostajny_18 = new int[1000000]; shell_jednostajny_18 = jednostajny(1000000); shell_jednostajny_18 = posortuj_czesciowo(shell_jednostajny_18,500000);
    int* shell_jednostajny_19 = new int[1000000]; shell_jednostajny_19 = jednostajny(1000000); shell_jednostajny_19 = posortuj_czesciowo(shell_jednostajny_19,900000);
    int* shell_jednostajny_20 = new int[1000000]; shell_jednostajny_20 = jednostajny(1000000); shell_jednostajny_20 = posortuj_czesciowo(shell_jednostajny_20,990000);
#endif
// ******************************************************************************************************/
//                            Generowanie tablic dla quicksort                                           /
// ******************************************************************************************************/
#if defined (STO) && defined (QUICKSORT) && defined (POISSON)
    int* quick_poisson_1 = new int[100]; quick_poisson_1 = poisson(100);
    int* quick_poisson_2 = new int[100]; quick_poisson_2 = poisson(100); quick_poisson_2 = posortuj_czesciowo(quick_poisson_2,50);
    int* quick_poisson_3 = new int[100]; quick_poisson_3 = poisson(100); quick_poisson_3 = posortuj_czesciowo(quick_poisson_3,90);
    int* quick_poisson_4 = new int[100]; quick_poisson_4 = poisson(100); quick_poisson_4 = posortuj_czesciowo(quick_poisson_4,99);
#endif
#if defined (TYSIAC) && defined (QUICKSORT) && defined (POISSON)
    int* quick_poisson_5 = new int[1000]; quick_poisson_5 = poisson(1000);
    int* quick_poisson_6 = new int[1000]; quick_poisson_6 = poisson(1000); quick_poisson_6 = posortuj_czesciowo(quick_poisson_6,500);
    int* quick_poisson_7 = new int[1000]; quick_poisson_7 = poisson(1000); quick_poisson_7 = posortuj_czesciowo(quick_poisson_7,900);
    int* quick_poisson_8 = new int[1000]; quick_poisson_8 = poisson(1000); quick_poisson_8 = posortuj_czesciowo(quick_poisson_8,990);
#endif
#if defined (DZIESIEC_TYSIECY) && defined (QUICKSORT) && defined (POISSON)
    int* quick_poisson_9  = new int[10000]; quick_poisson_9  = poisson(10000);
    int* quick_poisson_10 = new int[10000]; quick_poisson_10 = poisson(10000); quick_poisson_10 = posortuj_czesciowo(quick_poisson_10,5000);
    int* quick_poisson_11 = new int[10000]; quick_poisson_11 = poisson(10000); quick_poisson_11 = posortuj_czesciowo(quick_poisson_11,9000);
    int* quick_poisson_12 = new int[10000]; quick_poisson_12 = poisson(10000); quick_poisson_12 = posortuj_czesciowo(quick_poisson_12,9900);
#endif
#if defined (STO_TYSIECY) && defined (QUICKSORT) && defined (POISSON)
    int* quick_poisson_13 = new int[100000]; quick_poisson_13 = poisson(100000);
    int* quick_poisson_14 = new int[100000]; quick_poisson_14 = poisson(100000); quick_poisson_14 = posortuj_czesciowo(quick_poisson_14,50000);
    int* quick_poisson_15 = new int[100000]; quick_poisson_15 = poisson(100000); quick_poisson_15 = posortuj_czesciowo(quick_poisson_15,90000);
    int* quick_poisson_16 = new int[100000]; quick_poisson_16 = poisson(100000); quick_poisson_16 = posortuj_czesciowo(quick_poisson_16,99000);
#endif
#if defined (MILION) && defined (QUICKSORT) && defined (POISSON)
    int* quick_poisson_17 = new int[1000000]; quick_poisson_17 = poisson(1000000);
    int* quick_poisson_18 = new int[1000000]; quick_poisson_18 = poisson(1000000); quick_poisson_18 = posortuj_czesciowo(quick_poisson_18,500000);
    int* quick_poisson_19 = new int[1000000]; quick_poisson_19 = poisson(1000000); quick_poisson_19 = posortuj_czesciowo(quick_poisson_19,900000);
    int* quick_poisson_20 = new int[1000000]; quick_poisson_20 = poisson(1000000); quick_poisson_20 = posortuj_czesciowo(quick_poisson_20,990000);
#endif

#if defined (STO) && defined (QUICKSORT) && defined (GAUSS)
    int* quick_gauss_1 = new int[100]; quick_gauss_1 = gauss(100);
    int* quick_gauss_2 = new int[100]; quick_gauss_2 = gauss(100); quick_gauss_2 = posortuj_czesciowo(quick_gauss_2,50);
    int* quick_gauss_3 = new int[100]; quick_gauss_3 = gauss(100); quick_gauss_3 = posortuj_czesciowo(quick_gauss_3,90);
    int* quick_gauss_4 = new int[100]; quick_gauss_4 = gauss(100); quick_gauss_4 = posortuj_czesciowo(quick_gauss_4,99);
#endif
#if defined (TYSIAC) && defined (QUICKSORT) && defined (GAUSS)
    int* quick_gauss_5 = new int[1000]; quick_gauss_5 = gauss(1000);
    int* quick_gauss_6 = new int[1000]; quick_gauss_6 = gauss(1000); quick_gauss_6 = posortuj_czesciowo(quick_gauss_6,500);
    int* quick_gauss_7 = new int[1000]; quick_gauss_7 = gauss(1000); quick_gauss_7 = posortuj_czesciowo(quick_gauss_7,900);
    int* quick_gauss_8 = new int[1000]; quick_gauss_8 = gauss(1000); quick_gauss_8 = posortuj_czesciowo(quick_gauss_8,990);
#endif
#if defined (DZIESIEC_TYSIECY) && defined (QUICKSORT) && defined (GAUSS)
    int* quick_gauss_9  = new int[10000]; quick_gauss_9  = gauss(10000);
    int* quick_gauss_10 = new int[10000]; quick_gauss_10 = gauss(10000); quick_gauss_10 = posortuj_czesciowo(quick_gauss_10,5000);
    int* quick_gauss_11 = new int[10000]; quick_gauss_11 = gauss(10000); quick_gauss_11 = posortuj_czesciowo(quick_gauss_11,9000);
    int* quick_gauss_12 = new int[10000]; quick_gauss_12 = gauss(10000); quick_gauss_12 = posortuj_czesciowo(quick_gauss_12,9900);
#endif
#if defined (STO_TYSIECY) && defined (QUICKSORT) && defined (GAUSS)
    int* quick_gauss_13 = new int[100000]; quick_gauss_13 = gauss(100000);
    int* quick_gauss_14 = new int[100000]; quick_gauss_14 = gauss(100000); quick_gauss_14 = posortuj_czesciowo(quick_gauss_14,50000);
    int* quick_gauss_15 = new int[100000]; quick_gauss_15 = gauss(100000); quick_gauss_15 = posortuj_czesciowo(quick_gauss_15,90000);
    int* quick_gauss_16 = new int[100000]; quick_gauss_16 = gauss(100000); quick_gauss_16 = posortuj_czesciowo(quick_gauss_16,99000);
#endif
#if defined (MILION) && defined (QUICKSORT) && defined (GAUSS)
    int* quick_gauss_17 = new int[1000000]; quick_gauss_17 = gauss(1000000);
    int* quick_gauss_18 = new int[1000000]; quick_gauss_18 = gauss(1000000); quick_gauss_18 = posortuj_czesciowo(quick_gauss_18,500000);
    int* quick_gauss_19 = new int[1000000]; quick_gauss_19 = gauss(1000000); quick_gauss_19 = posortuj_czesciowo(quick_gauss_19,900000);
    int* quick_gauss_20 = new int[1000000]; quick_gauss_20 = gauss(1000000); quick_gauss_20 = posortuj_czesciowo(quick_gauss_20,990000);
#endif

#if defined (STO) && defined (QUICKSORT) && defined (JEDNOSTAJNY)
    int* quick_jednostajny_1 = new int[100]; quick_jednostajny_1 = jednostajny(100);
    int* quick_jednostajny_2 = new int[100]; quick_jednostajny_2 = jednostajny(100); quick_jednostajny_2 = posortuj_czesciowo(quick_jednostajny_2,50);
    int* quick_jednostajny_3 = new int[100]; quick_jednostajny_3 = jednostajny(100); quick_jednostajny_3 = posortuj_czesciowo(quick_jednostajny_3,90);
    int* quick_jednostajny_4 = new int[100]; quick_jednostajny_4 = jednostajny(100); quick_jednostajny_4 = posortuj_czesciowo(quick_jednostajny_4,99);
#endif
#if defined (TYSIAC) && defined (QUICKSORT) && defined (JEDNOSTAJNY)
    int* quick_jednostajny_5 = new int[1000]; quick_jednostajny_5 = jednostajny(1000);
    int* quick_jednostajny_6 = new int[1000]; quick_jednostajny_6 = jednostajny(1000); quick_jednostajny_6 = posortuj_czesciowo(quick_jednostajny_6,500);
    int* quick_jednostajny_7 = new int[1000]; quick_jednostajny_7 = jednostajny(1000); quick_jednostajny_7 = posortuj_czesciowo(quick_jednostajny_7,900);
    int* quick_jednostajny_8 = new int[1000]; quick_jednostajny_8 = jednostajny(1000); quick_jednostajny_8 = posortuj_czesciowo(quick_jednostajny_8,990);
#endif
#if defined (DZIESIEC_TYSIECY) && defined (QUICKSORT) && defined (JEDNOSTAJNY)
    int* quick_jednostajny_9  = new int[10000]; quick_jednostajny_9  = jednostajny(10000);
    int* quick_jednostajny_10 = new int[10000]; quick_jednostajny_10 = jednostajny(10000); quick_jednostajny_10 = posortuj_czesciowo(quick_jednostajny_10,5000);
    int* quick_jednostajny_11 = new int[10000]; quick_jednostajny_11 = jednostajny(10000); quick_jednostajny_11 = posortuj_czesciowo(quick_jednostajny_11,9000);
    int* quick_jednostajny_12 = new int[10000]; quick_jednostajny_12 = jednostajny(10000); quick_jednostajny_12 = posortuj_czesciowo(quick_jednostajny_12,9900);
#endif
#if defined (STO_TYSIECY) && defined (QUICKSORT) && defined (JEDNOSTAJNY)
    int* quick_jednostajny_13 = new int[100000]; quick_jednostajny_13 = jednostajny(100000);
    int* quick_jednostajny_14 = new int[100000]; quick_jednostajny_14 = jednostajny(100000); quick_jednostajny_14 = posortuj_czesciowo(quick_jednostajny_14,50000);
    int* quick_jednostajny_15 = new int[100000]; quick_jednostajny_15 = jednostajny(100000); quick_jednostajny_15 = posortuj_czesciowo(quick_jednostajny_15,90000);
    int* quick_jednostajny_16 = new int[100000]; quick_jednostajny_16 = jednostajny(100000); quick_jednostajny_16 = posortuj_czesciowo(quick_jednostajny_16,99000);
#endif
#if defined (MILION) && defined (QUICKSORT) && defined (JEDNOSTAJNY)
    int* quick_jednostajny_17 = new int[1000000]; quick_jednostajny_17 = jednostajny(1000000);
    int* quick_jednostajny_18 = new int[1000000]; quick_jednostajny_18 = jednostajny(1000000); quick_jednostajny_18 = posortuj_czesciowo(quick_jednostajny_18,500000);
    int* quick_jednostajny_19 = new int[1000000]; quick_jednostajny_19 = jednostajny(1000000); quick_jednostajny_19 = posortuj_czesciowo(quick_jednostajny_19,900000);
    int* quick_jednostajny_20 = new int[1000000]; quick_jednostajny_20 = jednostajny(1000000); quick_jednostajny_20 = posortuj_czesciowo(quick_jednostajny_20,990000);
#endif
// ******************************************************************************************************/
//                            Generowanie tablic dla introsort                                           /
// ******************************************************************************************************/
#if defined (STO) && defined (INTROSORT) && defined (POISSON)
    int* introsort_poisson_1 = new int[100]; introsort_poisson_1 = poisson(100);
    int* introsort_poisson_2 = new int[100]; introsort_poisson_2 = poisson(100); introsort_poisson_2 = posortuj_czesciowo(introsort_poisson_2,50);
    int* introsort_poisson_3 = new int[100]; introsort_poisson_3 = poisson(100); introsort_poisson_3 = posortuj_czesciowo(introsort_poisson_3,90);
    int* introsort_poisson_4 = new int[100]; introsort_poisson_4 = poisson(100); introsort_poisson_4 = posortuj_czesciowo(introsort_poisson_4,99);
#endif
#if defined (TYSIAC) && defined (INTROSORT) && defined (POISSON)
    int* introsort_poisson_5 = new int[1000]; introsort_poisson_5 = poisson(1000);
    int* introsort_poisson_6 = new int[1000]; introsort_poisson_6 = poisson(1000); introsort_poisson_6 = posortuj_czesciowo(introsort_poisson_6,500);
    int* introsort_poisson_7 = new int[1000]; introsort_poisson_7 = poisson(1000); introsort_poisson_7 = posortuj_czesciowo(introsort_poisson_7,900);
    int* introsort_poisson_8 = new int[1000]; introsort_poisson_8 = poisson(1000); introsort_poisson_8 = posortuj_czesciowo(introsort_poisson_8,990);
#endif
#if defined (DZIESIEC_TYSIECY) && defined (INTROSORT) && defined (POISSON)
    int* introsort_poisson_9  = new int[10000]; introsort_poisson_9  = poisson(10000);
    int* introsort_poisson_10 = new int[10000]; introsort_poisson_10 = poisson(10000); introsort_poisson_10 = posortuj_czesciowo(introsort_poisson_10,5000);
    int* introsort_poisson_11 = new int[10000]; introsort_poisson_11 = poisson(10000); introsort_poisson_11 = posortuj_czesciowo(introsort_poisson_11,9000);
    int* introsort_poisson_12 = new int[10000]; introsort_poisson_12 = poisson(10000); introsort_poisson_12 = posortuj_czesciowo(introsort_poisson_12,9900);
#endif
#if defined (STO_TYSIECY) && defined (INTROSORT) && defined (POISSON)
    int* introsort_poisson_13 = new int[100000]; introsort_poisson_13 = poisson(100000);
    int* introsort_poisson_14 = new int[100000]; introsort_poisson_14 = poisson(100000); introsort_poisson_14 = posortuj_czesciowo(introsort_poisson_14,50000);
    int* introsort_poisson_15 = new int[100000]; introsort_poisson_15 = poisson(100000); introsort_poisson_15 = posortuj_czesciowo(introsort_poisson_15,90000);
    int* introsort_poisson_16 = new int[100000]; introsort_poisson_16 = poisson(100000); introsort_poisson_16 = posortuj_czesciowo(introsort_poisson_16,99000);
#endif
#if defined (MILION) && defined (INTROSORT) && defined (POISSON)
    int* introsort_poisson_17 = new int[1000000]; introsort_poisson_17 = poisson(1000000);
    int* introsort_poisson_18 = new int[1000000]; introsort_poisson_18 = poisson(1000000); introsort_poisson_18 = posortuj_czesciowo(introsort_poisson_18,500000);
    int* introsort_poisson_19 = new int[1000000]; introsort_poisson_19 = poisson(1000000); introsort_poisson_19 = posortuj_czesciowo(introsort_poisson_19,900000);
    int* introsort_poisson_20 = new int[1000000]; introsort_poisson_20 = poisson(1000000); introsort_poisson_20 = posortuj_czesciowo(introsort_poisson_20,990000);
#endif

#if defined (STO) && defined (INTROSORT) && defined (GAUSS)
    int* introsort_gauss_1 = new int[100]; introsort_gauss_1 = gauss(100);
    int* introsort_gauss_2 = new int[100]; introsort_gauss_2 = gauss(100); introsort_gauss_2 = posortuj_czesciowo(introsort_gauss_2,50);
    int* introsort_gauss_3 = new int[100]; introsort_gauss_3 = gauss(100); introsort_gauss_3 = posortuj_czesciowo(introsort_gauss_3,90);
    int* introsort_gauss_4 = new int[100]; introsort_gauss_4 = gauss(100); introsort_gauss_4 = posortuj_czesciowo(introsort_gauss_4,99);
#endif
#if defined (TYSIAC) && defined (INTROSORT) && defined (GAUSS)
    int* introsort_gauss_5 = new int[1000]; introsort_gauss_5 = gauss(1000);
    int* introsort_gauss_6 = new int[1000]; introsort_gauss_6 = gauss(1000); introsort_gauss_6 = posortuj_czesciowo(introsort_gauss_6,500);
    int* introsort_gauss_7 = new int[1000]; introsort_gauss_7 = gauss(1000); introsort_gauss_7 = posortuj_czesciowo(introsort_gauss_7,900);
    int* introsort_gauss_8 = new int[1000]; introsort_gauss_8 = gauss(1000); introsort_gauss_8 = posortuj_czesciowo(introsort_gauss_8,990);
#endif
#if defined (DZIESIEC_TYSIECY) && defined (INTROSORT) && defined (GAUSS)
    int* introsort_gauss_9  = new int[10000]; introsort_gauss_9  = gauss(10000);
    int* introsort_gauss_10 = new int[10000]; introsort_gauss_10 = gauss(10000); introsort_gauss_10 = posortuj_czesciowo(introsort_gauss_10,5000);
    int* introsort_gauss_11 = new int[10000]; introsort_gauss_11 = gauss(10000); introsort_gauss_11 = posortuj_czesciowo(introsort_gauss_11,9000);
    int* introsort_gauss_12 = new int[10000]; introsort_gauss_12 = gauss(10000); introsort_gauss_12 = posortuj_czesciowo(introsort_gauss_12,9900);
#endif
#if defined (STO_TYSIECY) && defined (INTROSORT) && defined (GAUSS)
    int* introsort_gauss_13 = new int[100000]; introsort_gauss_13 = gauss(100000);
    int* introsort_gauss_14 = new int[100000]; introsort_gauss_14 = gauss(100000); introsort_gauss_14 = posortuj_czesciowo(introsort_gauss_14,50000);
    int* introsort_gauss_15 = new int[100000]; introsort_gauss_15 = gauss(100000); introsort_gauss_15 = posortuj_czesciowo(introsort_gauss_15,90000);
    int* introsort_gauss_16 = new int[100000]; introsort_gauss_16 = gauss(100000); introsort_gauss_16 = posortuj_czesciowo(introsort_gauss_16,99000);
#endif
#if defined (MILION) && defined (INTROSORT) && defined (GAUSS)
    int* introsort_gauss_17 = new int[1000000]; introsort_gauss_17 = gauss(1000000);
    int* introsort_gauss_18 = new int[1000000]; introsort_gauss_18 = gauss(1000000); introsort_gauss_18 = posortuj_czesciowo(introsort_gauss_18,500000);
    int* introsort_gauss_19 = new int[1000000]; introsort_gauss_19 = gauss(1000000); introsort_gauss_19 = posortuj_czesciowo(introsort_gauss_19,900000);
    int* introsort_gauss_20 = new int[1000000]; introsort_gauss_20 = gauss(1000000); introsort_gauss_20 = posortuj_czesciowo(introsort_gauss_20,990000);
#endif

#if defined (STO) && defined (INTROSORT) && defined (JEDNOSTAJNY)
    int* introsort_jednostajny_1 = new int[100]; introsort_jednostajny_1 = jednostajny(100);
    int* introsort_jednostajny_2 = new int[100]; introsort_jednostajny_2 = jednostajny(100); introsort_jednostajny_2 = posortuj_czesciowo(introsort_jednostajny_2,50);
    int* introsort_jednostajny_3 = new int[100]; introsort_jednostajny_3 = jednostajny(100); introsort_jednostajny_3 = posortuj_czesciowo(introsort_jednostajny_3,90);
    int* introsort_jednostajny_4 = new int[100]; introsort_jednostajny_4 = jednostajny(100); introsort_jednostajny_4 = posortuj_czesciowo(introsort_jednostajny_4,99);
#endif
#if defined (TYSIAC) && defined (INTROSORT) && defined (JEDNOSTAJNY)
    int* introsort_jednostajny_5 = new int[1000]; introsort_jednostajny_5 = jednostajny(1000);
    int* introsort_jednostajny_6 = new int[1000]; introsort_jednostajny_6 = jednostajny(1000); introsort_jednostajny_6 = posortuj_czesciowo(introsort_jednostajny_6,500);
    int* introsort_jednostajny_7 = new int[1000]; introsort_jednostajny_7 = jednostajny(1000); introsort_jednostajny_7 = posortuj_czesciowo(introsort_jednostajny_7,900);
    int* introsort_jednostajny_8 = new int[1000]; introsort_jednostajny_8 = jednostajny(1000); introsort_jednostajny_8 = posortuj_czesciowo(introsort_jednostajny_8,990);
#endif
#if defined (DZIESIEC_TYSIECY) && defined (INTROSORT) && defined (JEDNOSTAJNY)
    int* introsort_jednostajny_9  = new int[10000]; introsort_jednostajny_9  = jednostajny(10000);
    int* introsort_jednostajny_10 = new int[10000]; introsort_jednostajny_10 = jednostajny(10000); introsort_jednostajny_10 = posortuj_czesciowo(introsort_jednostajny_10,5000);
    int* introsort_jednostajny_11 = new int[10000]; introsort_jednostajny_11 = jednostajny(10000); introsort_jednostajny_11 = posortuj_czesciowo(introsort_jednostajny_11,9000);
    int* introsort_jednostajny_12 = new int[10000]; introsort_jednostajny_12 = jednostajny(10000); introsort_jednostajny_12 = posortuj_czesciowo(introsort_jednostajny_12,9900);
#endif
#if defined (STO_TYSIECY) && defined (INTROSORT) && defined (JEDNOSTAJNY)
    int* introsort_jednostajny_13 = new int[100000]; introsort_jednostajny_13 = jednostajny(100000);
    int* introsort_jednostajny_14 = new int[100000]; introsort_jednostajny_14 = jednostajny(100000); introsort_jednostajny_14 = posortuj_czesciowo(introsort_jednostajny_14,50000);
    int* introsort_jednostajny_15 = new int[100000]; introsort_jednostajny_15 = jednostajny(100000); introsort_jednostajny_15 = posortuj_czesciowo(introsort_jednostajny_15,90000);
    int* introsort_jednostajny_16 = new int[100000]; introsort_jednostajny_16 = jednostajny(100000); introsort_jednostajny_16 = posortuj_czesciowo(introsort_jednostajny_16,99000);
#endif
#if defined (MILION) && defined (INTROSORT) && defined (JEDNOSTAJNY)
    int* introsort_jednostajny_17 = new int[1000000]; introsort_jednostajny_17 = jednostajny(1000000);
    int* introsort_jednostajny_18 = new int[1000000]; introsort_jednostajny_18 = jednostajny(1000000); introsort_jednostajny_18 = posortuj_czesciowo(introsort_jednostajny_18,500000);
    int* introsort_jednostajny_19 = new int[1000000]; introsort_jednostajny_19 = jednostajny(1000000); introsort_jednostajny_19 = posortuj_czesciowo(introsort_jednostajny_19,900000);
    int* introsort_jednostajny_20 = new int[1000000]; introsort_jednostajny_20 = jednostajny(1000000); introsort_jednostajny_20 = posortuj_czesciowo(introsort_jednostajny_20,990000);
#endif

// cout << "Zakonczono generowanie tablic w czasie " << GetCounter() << " ms" << endl;


// ******************************************************************************************************/
//                                     POCZATEK SORTOWANIA                                               /
// ******************************************************************************************************/
// ******************************************************************************************************/
//                                     Wstawianie Poisson                                                /
// ******************************************************************************************************/
#if defined (STO) && defined (WSTAWIANIE) && defined (POISSON)
    StartCounter(); wstawianie(wstawianie_poisson_1, 100); wstawianie_wynik_1[iteracja] = GetCounter();
    StartCounter(); wstawianie(wstawianie_poisson_2, 100); wstawianie_wynik_2[iteracja] = GetCounter();
    StartCounter(); wstawianie(wstawianie_poisson_3, 100); wstawianie_wynik_3[iteracja] = GetCounter();
    StartCounter(); wstawianie(wstawianie_poisson_4, 100); wstawianie_wynik_4[iteracja] = GetCounter();
#endif
#if defined (TYSIAC) && defined (WSTAWIANIE) && defined (POISSON)
    StartCounter(); wstawianie(wstawianie_poisson_5, 1000); wstawianie_wynik_5[iteracja] = GetCounter();
    StartCounter(); wstawianie(wstawianie_poisson_6, 1000); wstawianie_wynik_6[iteracja] = GetCounter();
    StartCounter(); wstawianie(wstawianie_poisson_7, 1000); wstawianie_wynik_7[iteracja] = GetCounter();
    StartCounter(); wstawianie(wstawianie_poisson_8, 1000); wstawianie_wynik_8[iteracja] = GetCounter();
#endif
#if defined (DZIESIEC_TYSIECY) && defined (WSTAWIANIE) && defined (POISSON)
    StartCounter(); wstawianie(wstawianie_poisson_9, 10000); wstawianie_wynik_9[iteracja] = GetCounter();
    StartCounter(); wstawianie(wstawianie_poisson_10, 10000); wstawianie_wynik_10[iteracja] = GetCounter();
    StartCounter(); wstawianie(wstawianie_poisson_11, 10000); wstawianie_wynik_11[iteracja] = GetCounter();
    StartCounter(); wstawianie(wstawianie_poisson_12, 10000); wstawianie_wynik_12[iteracja] = GetCounter();
#endif
#if defined (STO_TYSIECY) && defined (WSTAWIANIE) && defined (POISSON)
    StartCounter(); wstawianie(wstawianie_poisson_13, 100000); wstawianie_wynik_13[iteracja] = GetCounter();
    StartCounter(); wstawianie(wstawianie_poisson_14, 100000); wstawianie_wynik_14[iteracja] = GetCounter();
    StartCounter(); wstawianie(wstawianie_poisson_15, 100000); wstawianie_wynik_15[iteracja] = GetCounter();
    StartCounter(); wstawianie(wstawianie_poisson_16, 100000); wstawianie_wynik_16[iteracja] = GetCounter();
#endif
#if defined (MILION) && defined (WSTAWIANIE) && defined (POISSON)
    StartCounter(); wstawianie(wstawianie_poisson_17, 1000000); wstawianie_wynik_17[iteracja] = GetCounter();
    StartCounter(); wstawianie(wstawianie_poisson_18, 1000000); wstawianie_wynik_18[iteracja] = GetCounter();
    StartCounter(); wstawianie(wstawianie_poisson_19, 1000000); wstawianie_wynik_19[iteracja] = GetCounter();
    StartCounter(); wstawianie(wstawianie_poisson_20, 1000000); wstawianie_wynik_20[iteracja] = GetCounter();
#endif
//**********************************************************************************************************************************************
//                                              Wstawianie Gauss
//**********************************************************************************************************************************************
#if defined (STO) && defined (WSTAWIANIE) && defined (GAUSS)
    StartCounter(); wstawianie(wstawianie_gauss_1, 100); wstawianie_wynik_21[iteracja] = GetCounter();
    StartCounter(); wstawianie(wstawianie_gauss_2, 100); wstawianie_wynik_22[iteracja] = GetCounter();
    StartCounter(); wstawianie(wstawianie_gauss_3, 100); wstawianie_wynik_23[iteracja] = GetCounter();
    StartCounter(); wstawianie(wstawianie_gauss_4, 100); wstawianie_wynik_24[iteracja] = GetCounter();
#endif
#if defined (TYSIAC) && defined (WSTAWIANIE) && defined (GAUSS)
    StartCounter(); wstawianie(wstawianie_gauss_5, 1000); wstawianie_wynik_25[iteracja] = GetCounter();
    StartCounter(); wstawianie(wstawianie_gauss_6, 1000); wstawianie_wynik_26[iteracja] = GetCounter();
    StartCounter(); wstawianie(wstawianie_gauss_7, 1000); wstawianie_wynik_27[iteracja] = GetCounter();
    StartCounter(); wstawianie(wstawianie_gauss_8, 1000); wstawianie_wynik_28[iteracja] = GetCounter();
#endif
#if defined (DZIESIEC_TYSIECY) && defined (WSTAWIANIE) && defined (GAUSS)
    StartCounter(); wstawianie(wstawianie_gauss_9, 10000); wstawianie_wynik_29[iteracja] = GetCounter();
    StartCounter(); wstawianie(wstawianie_gauss_10, 10000); wstawianie_wynik_30[iteracja] = GetCounter();
    StartCounter(); wstawianie(wstawianie_gauss_11, 10000); wstawianie_wynik_31[iteracja] = GetCounter();
    StartCounter(); wstawianie(wstawianie_gauss_12, 10000); wstawianie_wynik_32[iteracja] = GetCounter();
#endif
#if defined (STO_TYSIECY) && defined (WSTAWIANIE) && defined (GAUSS)
    StartCounter(); wstawianie(wstawianie_gauss_13, 100000); wstawianie_wynik_33[iteracja] = GetCounter();
    StartCounter(); wstawianie(wstawianie_gauss_14, 100000); wstawianie_wynik_34[iteracja] = GetCounter();
    StartCounter(); wstawianie(wstawianie_gauss_15, 100000); wstawianie_wynik_35[iteracja] = GetCounter();
    StartCounter(); wstawianie(wstawianie_gauss_16, 100000); wstawianie_wynik_36[iteracja] = GetCounter();
#endif
#if defined (MILION) && defined (WSTAWIANIE) && defined (GAUSS)
    StartCounter(); wstawianie(wstawianie_gauss_17, 1000000); wstawianie_wynik_37[iteracja] = GetCounter();
    StartCounter(); wstawianie(wstawianie_gauss_18, 1000000); wstawianie_wynik_38[iteracja] = GetCounter();
    StartCounter(); wstawianie(wstawianie_gauss_19, 1000000); wstawianie_wynik_39[iteracja] = GetCounter();
    StartCounter(); wstawianie(wstawianie_gauss_20, 1000000); wstawianie_wynik_40[iteracja] = GetCounter();
#endif
//**********************************************************************************************************************************************
//                                              Wstawianie Jednostajny
//**********************************************************************************************************************************************
#if defined (STO) && defined (WSTAWIANIE) && defined (JEDNOSTAJNY)
    StartCounter(); wstawianie(wstawianie_jednostajny_1, 100); wstawianie_wynik_41[iteracja] = GetCounter();
    StartCounter(); wstawianie(wstawianie_jednostajny_2, 100); wstawianie_wynik_42[iteracja] = GetCounter();
    StartCounter(); wstawianie(wstawianie_jednostajny_3, 100); wstawianie_wynik_43[iteracja] = GetCounter();
    StartCounter(); wstawianie(wstawianie_jednostajny_4, 100); wstawianie_wynik_44[iteracja] = GetCounter();
#endif
#if defined (TYSIAC) && defined (WSTAWIANIE) && defined (JEDNOSTAJNY)
    StartCounter(); wstawianie(wstawianie_jednostajny_5, 1000); wstawianie_wynik_45[iteracja] = GetCounter();
    StartCounter(); wstawianie(wstawianie_jednostajny_6, 1000); wstawianie_wynik_46[iteracja] = GetCounter();
    StartCounter(); wstawianie(wstawianie_jednostajny_7, 1000); wstawianie_wynik_47[iteracja] = GetCounter();
    StartCounter(); wstawianie(wstawianie_jednostajny_8, 1000); wstawianie_wynik_48[iteracja] = GetCounter();
#endif
#if defined (DZIESIEC_TYSIECY) && defined (WSTAWIANIE) && defined (JEDNOSTAJNY)
    StartCounter(); wstawianie(wstawianie_jednostajny_9, 10000); wstawianie_wynik_49[iteracja] = GetCounter();
    StartCounter(); wstawianie(wstawianie_jednostajny_10, 10000); wstawianie_wynik_50[iteracja] = GetCounter();
    StartCounter(); wstawianie(wstawianie_jednostajny_11, 10000); wstawianie_wynik_51[iteracja] = GetCounter();
    StartCounter(); wstawianie(wstawianie_jednostajny_12, 10000); wstawianie_wynik_52[iteracja] = GetCounter();
#endif
#if defined (STO_TYSIECY) && defined (WSTAWIANIE) && defined (JEDNOSTAJNY)
    StartCounter(); wstawianie(wstawianie_jednostajny_13, 100000); wstawianie_wynik_53[iteracja] = GetCounter();
    StartCounter(); wstawianie(wstawianie_jednostajny_14, 100000); wstawianie_wynik_54[iteracja] = GetCounter();
    StartCounter(); wstawianie(wstawianie_jednostajny_15, 100000); wstawianie_wynik_55[iteracja] = GetCounter();
    StartCounter(); wstawianie(wstawianie_jednostajny_16, 100000); wstawianie_wynik_56[iteracja] = GetCounter();
#endif
#if defined (MILION) && defined (WSTAWIANIE) && defined (JEDNOSTAJNY)
    StartCounter(); wstawianie(wstawianie_jednostajny_17, 1000000); wstawianie_wynik_57[iteracja] = GetCounter();
    StartCounter(); wstawianie(wstawianie_jednostajny_18, 1000000); wstawianie_wynik_58[iteracja] = GetCounter();
    StartCounter(); wstawianie(wstawianie_jednostajny_19, 1000000); wstawianie_wynik_59[iteracja] = GetCounter();
    StartCounter(); wstawianie(wstawianie_jednostajny_20, 1000000); wstawianie_wynik_60[iteracja] = GetCounter();
#endif
// ******************************************************************************************************/
//                                     kopcowanie Poisson                                                /
// ******************************************************************************************************/
#if defined (STO) && defined (KOPCOWANIE) && defined (POISSON)
    StartCounter(); kopcowanie(kopcowanie_poisson_1, 100); kopcowanie_wynik_1[iteracja] = GetCounter();
    StartCounter(); kopcowanie(kopcowanie_poisson_2, 100); kopcowanie_wynik_2[iteracja] = GetCounter();
    StartCounter(); kopcowanie(kopcowanie_poisson_3, 100); kopcowanie_wynik_3[iteracja] = GetCounter();
    StartCounter(); kopcowanie(kopcowanie_poisson_4, 100); kopcowanie_wynik_4[iteracja] = GetCounter();
#endif
#if defined (TYSIAC) && defined (KOPCOWANIE) && defined (POISSON)
    StartCounter(); kopcowanie(kopcowanie_poisson_5, 1000); kopcowanie_wynik_5[iteracja] = GetCounter();
    StartCounter(); kopcowanie(kopcowanie_poisson_6, 1000); kopcowanie_wynik_6[iteracja] = GetCounter();
    StartCounter(); kopcowanie(kopcowanie_poisson_7, 1000); kopcowanie_wynik_7[iteracja] = GetCounter();
    StartCounter(); kopcowanie(kopcowanie_poisson_8, 1000); kopcowanie_wynik_8[iteracja] = GetCounter();
#endif
#if defined (DZIESIEC_TYSIECY) && defined (KOPCOWANIE) && defined (POISSON)
    StartCounter(); kopcowanie(kopcowanie_poisson_9, 10000); kopcowanie_wynik_9[iteracja] = GetCounter();
    StartCounter(); kopcowanie(kopcowanie_poisson_10, 10000); kopcowanie_wynik_10[iteracja] = GetCounter();
    StartCounter(); kopcowanie(kopcowanie_poisson_11, 10000); kopcowanie_wynik_11[iteracja] = GetCounter();
    StartCounter(); kopcowanie(kopcowanie_poisson_12, 10000); kopcowanie_wynik_12[iteracja] = GetCounter();
#endif
#if defined (STO_TYSIECY) && defined (KOPCOWANIE) && defined (POISSON)
    StartCounter(); kopcowanie(kopcowanie_poisson_13, 100000); kopcowanie_wynik_13[iteracja] = GetCounter();
    StartCounter(); kopcowanie(kopcowanie_poisson_14, 100000); kopcowanie_wynik_14[iteracja] = GetCounter();
    StartCounter(); kopcowanie(kopcowanie_poisson_15, 100000); kopcowanie_wynik_15[iteracja] = GetCounter();
    StartCounter(); kopcowanie(kopcowanie_poisson_16, 100000); kopcowanie_wynik_16[iteracja] = GetCounter();
#endif
#if defined (MILION) && defined (KOPCOWANIE) && defined (POISSON)
    StartCounter(); kopcowanie(kopcowanie_poisson_17, 1000000); kopcowanie_wynik_17[iteracja] = GetCounter();
    StartCounter(); kopcowanie(kopcowanie_poisson_18, 1000000); kopcowanie_wynik_18[iteracja] = GetCounter();
    StartCounter(); kopcowanie(kopcowanie_poisson_19, 1000000); kopcowanie_wynik_19[iteracja] = GetCounter();
    StartCounter(); kopcowanie(kopcowanie_poisson_20, 1000000); kopcowanie_wynik_20[iteracja] = GetCounter();
#endif
//**********************************************************************************************************************************************
//                                              kopcowanie Gauss
//**********************************************************************************************************************************************
#if defined (STO) && defined (KOPCOWANIE) && defined (GAUSS)
    StartCounter(); kopcowanie(kopcowanie_gauss_1, 100); kopcowanie_wynik_21[iteracja] = GetCounter();
    StartCounter(); kopcowanie(kopcowanie_gauss_2, 100); kopcowanie_wynik_22[iteracja] = GetCounter();
    StartCounter(); kopcowanie(kopcowanie_gauss_3, 100); kopcowanie_wynik_23[iteracja] = GetCounter();
    StartCounter(); kopcowanie(kopcowanie_gauss_4, 100); kopcowanie_wynik_24[iteracja] = GetCounter();
#endif
#if defined (TYSIAC) && defined (KOPCOWANIE) && defined (GAUSS)
    StartCounter(); kopcowanie(kopcowanie_gauss_5, 1000); kopcowanie_wynik_25[iteracja] = GetCounter();
    StartCounter(); kopcowanie(kopcowanie_gauss_6, 1000); kopcowanie_wynik_26[iteracja] = GetCounter();
    StartCounter(); kopcowanie(kopcowanie_gauss_7, 1000); kopcowanie_wynik_27[iteracja] = GetCounter();
    StartCounter(); kopcowanie(kopcowanie_gauss_8, 1000); kopcowanie_wynik_28[iteracja] = GetCounter();
#endif
#if defined (DZIESIEC_TYSIECY) && defined (KOPCOWANIE) && defined (GAUSS)
    StartCounter(); kopcowanie(kopcowanie_gauss_9, 10000); kopcowanie_wynik_29[iteracja] = GetCounter();
    StartCounter(); kopcowanie(kopcowanie_gauss_10, 10000); kopcowanie_wynik_30[iteracja] = GetCounter();
    StartCounter(); kopcowanie(kopcowanie_gauss_11, 10000); kopcowanie_wynik_31[iteracja] = GetCounter();
    StartCounter(); kopcowanie(kopcowanie_gauss_12, 10000); kopcowanie_wynik_32[iteracja] = GetCounter();
#endif
#if defined (STO_TYSIECY) && defined (KOPCOWANIE) && defined (GAUSS)
    StartCounter(); kopcowanie(kopcowanie_gauss_13, 100000); kopcowanie_wynik_33[iteracja] = GetCounter();
    StartCounter(); kopcowanie(kopcowanie_gauss_14, 100000); kopcowanie_wynik_34[iteracja] = GetCounter();
    StartCounter(); kopcowanie(kopcowanie_gauss_15, 100000); kopcowanie_wynik_35[iteracja] = GetCounter();
    StartCounter(); kopcowanie(kopcowanie_gauss_16, 100000); kopcowanie_wynik_36[iteracja] = GetCounter();
#endif
#if defined (MILION) && defined (KOPCOWANIE) && defined (GAUSS)
    StartCounter(); kopcowanie(kopcowanie_gauss_17, 1000000); kopcowanie_wynik_37[iteracja] = GetCounter();
    StartCounter(); kopcowanie(kopcowanie_gauss_18, 1000000); kopcowanie_wynik_38[iteracja] = GetCounter();
    StartCounter(); kopcowanie(kopcowanie_gauss_19, 1000000); kopcowanie_wynik_39[iteracja] = GetCounter();
    StartCounter(); kopcowanie(kopcowanie_gauss_20, 1000000); kopcowanie_wynik_40[iteracja] = GetCounter();
#endif
//**********************************************************************************************************************************************
//                                              kopcowanie Jednostajny
//**********************************************************************************************************************************************
#if defined (STO) && defined (KOPCOWANIE) && defined (JEDNOSTAJNY)
    StartCounter(); kopcowanie(kopcowanie_jednostajny_1, 100); kopcowanie_wynik_41[iteracja] = GetCounter();
    StartCounter(); kopcowanie(kopcowanie_jednostajny_2, 100); kopcowanie_wynik_42[iteracja] = GetCounter();
    StartCounter(); kopcowanie(kopcowanie_jednostajny_3, 100); kopcowanie_wynik_43[iteracja] = GetCounter();
    StartCounter(); kopcowanie(kopcowanie_jednostajny_4, 100); kopcowanie_wynik_44[iteracja] = GetCounter();
#endif
#if defined (TYSIAC) && defined (KOPCOWANIE) && defined (JEDNOSTAJNY)
    StartCounter(); kopcowanie(kopcowanie_jednostajny_5, 1000); kopcowanie_wynik_45[iteracja] = GetCounter();
    StartCounter(); kopcowanie(kopcowanie_jednostajny_6, 1000); kopcowanie_wynik_46[iteracja] = GetCounter();
    StartCounter(); kopcowanie(kopcowanie_jednostajny_7, 1000); kopcowanie_wynik_47[iteracja] = GetCounter();
    StartCounter(); kopcowanie(kopcowanie_jednostajny_8, 1000); kopcowanie_wynik_48[iteracja] = GetCounter();
#endif
#if defined (DZIESIEC_TYSIECY) && defined (KOPCOWANIE) && defined (JEDNOSTAJNY)
    StartCounter(); kopcowanie(kopcowanie_jednostajny_9, 10000); kopcowanie_wynik_49[iteracja] = GetCounter();
    StartCounter(); kopcowanie(kopcowanie_jednostajny_10, 10000); kopcowanie_wynik_50[iteracja] = GetCounter();
    StartCounter(); kopcowanie(kopcowanie_jednostajny_11, 10000); kopcowanie_wynik_51[iteracja] = GetCounter();
    StartCounter(); kopcowanie(kopcowanie_jednostajny_12, 10000); kopcowanie_wynik_52[iteracja] = GetCounter();
#endif
#if defined (STO_TYSIECY) && defined (KOPCOWANIE) && defined (JEDNOSTAJNY)
    StartCounter(); kopcowanie(kopcowanie_jednostajny_13, 100000); kopcowanie_wynik_53[iteracja] = GetCounter();
    StartCounter(); kopcowanie(kopcowanie_jednostajny_14, 100000); kopcowanie_wynik_54[iteracja] = GetCounter();
    StartCounter(); kopcowanie(kopcowanie_jednostajny_15, 100000); kopcowanie_wynik_55[iteracja] = GetCounter();
    StartCounter(); kopcowanie(kopcowanie_jednostajny_16, 100000); kopcowanie_wynik_56[iteracja] = GetCounter();
#endif
#if defined (MILION) && defined (KOPCOWANIE) && defined (JEDNOSTAJNY)
    StartCounter(); kopcowanie(kopcowanie_jednostajny_17, 1000000); kopcowanie_wynik_57[iteracja] = GetCounter();
    StartCounter(); kopcowanie(kopcowanie_jednostajny_18, 1000000); kopcowanie_wynik_58[iteracja] = GetCounter();
    StartCounter(); kopcowanie(kopcowanie_jednostajny_19, 1000000); kopcowanie_wynik_59[iteracja] = GetCounter();
    StartCounter(); kopcowanie(kopcowanie_jednostajny_20, 1000000); kopcowanie_wynik_60[iteracja] = GetCounter();
#endif
// ******************************************************************************************************/
//                                     shell Poisson                                                /
// ******************************************************************************************************/
#if defined (STO) && defined (SHELL) && defined (POISSON)
    StartCounter(); shell(shell_poisson_1, 100); shell_wynik_1[iteracja] = GetCounter();
    StartCounter(); shell(shell_poisson_2, 100); shell_wynik_2[iteracja] = GetCounter();
    StartCounter(); shell(shell_poisson_3, 100); shell_wynik_3[iteracja] = GetCounter();
    StartCounter(); shell(shell_poisson_4, 100); shell_wynik_4[iteracja] = GetCounter();
#endif
#if defined (TYSIAC) && defined (SHELL) && defined (POISSON)
    StartCounter(); shell(shell_poisson_5, 1000); shell_wynik_5[iteracja] = GetCounter();
    StartCounter(); shell(shell_poisson_6, 1000); shell_wynik_6[iteracja] = GetCounter();
    StartCounter(); shell(shell_poisson_7, 1000); shell_wynik_7[iteracja] = GetCounter();
    StartCounter(); shell(shell_poisson_8, 1000); shell_wynik_8[iteracja] = GetCounter();
#endif
#if defined (DZIESIEC_TYSIECY) && defined (SHELL) && defined (POISSON)
    StartCounter(); shell(shell_poisson_9, 10000); shell_wynik_9[iteracja] = GetCounter();
    StartCounter(); shell(shell_poisson_10, 10000); shell_wynik_10[iteracja] = GetCounter();
    StartCounter(); shell(shell_poisson_11, 10000); shell_wynik_11[iteracja] = GetCounter();
    StartCounter(); shell(shell_poisson_12, 10000); shell_wynik_12[iteracja] = GetCounter();
#endif
#if defined (STO_TYSIECY) && defined (SHELL) && defined (POISSON)
    StartCounter(); shell(shell_poisson_13, 100000); shell_wynik_13[iteracja] = GetCounter();
    StartCounter(); shell(shell_poisson_14, 100000); shell_wynik_14[iteracja] = GetCounter();
    StartCounter(); shell(shell_poisson_15, 100000); shell_wynik_15[iteracja] = GetCounter();
    StartCounter(); shell(shell_poisson_16, 100000); shell_wynik_16[iteracja] = GetCounter();
#endif
#if defined (MILION) && defined (SHELL) && defined (POISSON)
    StartCounter(); shell(shell_poisson_17, 1000000); shell_wynik_17[iteracja] = GetCounter();
    StartCounter(); shell(shell_poisson_18, 1000000); shell_wynik_18[iteracja] = GetCounter();
    StartCounter(); shell(shell_poisson_19, 1000000); shell_wynik_19[iteracja] = GetCounter();
    StartCounter(); shell(shell_poisson_20, 1000000); shell_wynik_20[iteracja] = GetCounter();
#endif
//**********************************************************************************************************************************************
//                                              shell Gauss
//**********************************************************************************************************************************************
#if defined (STO) && defined (SHELL) && defined (GAUSS)
    StartCounter(); shell(shell_gauss_1, 100); shell_wynik_21[iteracja] = GetCounter();
    StartCounter(); shell(shell_gauss_2, 100); shell_wynik_22[iteracja] = GetCounter();
    StartCounter(); shell(shell_gauss_3, 100); shell_wynik_23[iteracja] = GetCounter();
    StartCounter(); shell(shell_gauss_4, 100); shell_wynik_24[iteracja] = GetCounter();
#endif
#if defined (TYSIAC) && defined (SHELL) && defined (GAUSS)
    StartCounter(); shell(shell_gauss_5, 1000); shell_wynik_25[iteracja] = GetCounter();
    StartCounter(); shell(shell_gauss_6, 1000); shell_wynik_26[iteracja] = GetCounter();
    StartCounter(); shell(shell_gauss_7, 1000); shell_wynik_27[iteracja] = GetCounter();
    StartCounter(); shell(shell_gauss_8, 1000); shell_wynik_28[iteracja] = GetCounter();
#endif
#if defined (DZIESIEC_TYSIECY) && defined (SHELL) && defined (GAUSS)
    StartCounter(); shell(shell_gauss_9, 10000); shell_wynik_29[iteracja] = GetCounter();
    StartCounter(); shell(shell_gauss_10, 10000); shell_wynik_30[iteracja] = GetCounter();
    StartCounter(); shell(shell_gauss_11, 10000); shell_wynik_31[iteracja] = GetCounter();
    StartCounter(); shell(shell_gauss_12, 10000); shell_wynik_32[iteracja] = GetCounter();
#endif
#if defined (STO_TYSIECY) && defined (SHELL) && defined (GAUSS)
    StartCounter(); shell(shell_gauss_13, 100000); shell_wynik_33[iteracja] = GetCounter();
    StartCounter(); shell(shell_gauss_14, 100000); shell_wynik_34[iteracja] = GetCounter();
    StartCounter(); shell(shell_gauss_15, 100000); shell_wynik_35[iteracja] = GetCounter();
    StartCounter(); shell(shell_gauss_16, 100000); shell_wynik_36[iteracja] = GetCounter();
#endif
#if defined (MILION) && defined (SHELL) && defined (GAUSS)
    StartCounter(); shell(shell_gauss_17, 1000000); shell_wynik_37[iteracja] = GetCounter();
    StartCounter(); shell(shell_gauss_18, 1000000); shell_wynik_38[iteracja] = GetCounter();
    StartCounter(); shell(shell_gauss_19, 1000000); shell_wynik_39[iteracja] = GetCounter();
    StartCounter(); shell(shell_gauss_20, 1000000); shell_wynik_40[iteracja] = GetCounter();
#endif
//**********************************************************************************************************************************************
//                                              shell Jednostajny
//**********************************************************************************************************************************************
#if defined (STO) && defined (SHELL) && defined (JEDNOSTAJNY)
    StartCounter(); shell(shell_jednostajny_1, 100); shell_wynik_41[iteracja] = GetCounter();
    StartCounter(); shell(shell_jednostajny_2, 100); shell_wynik_42[iteracja] = GetCounter();
    StartCounter(); shell(shell_jednostajny_3, 100); shell_wynik_43[iteracja] = GetCounter();
    StartCounter(); shell(shell_jednostajny_4, 100); shell_wynik_44[iteracja] = GetCounter();
#endif
#if defined (TYSIAC) && defined (SHELL) && defined (JEDNOSTAJNY)
    StartCounter(); shell(shell_jednostajny_5, 1000); shell_wynik_45[iteracja] = GetCounter();
    StartCounter(); shell(shell_jednostajny_6, 1000); shell_wynik_46[iteracja] = GetCounter();
    StartCounter(); shell(shell_jednostajny_7, 1000); shell_wynik_47[iteracja] = GetCounter();
    StartCounter(); shell(shell_jednostajny_8, 1000); shell_wynik_48[iteracja] = GetCounter();
#endif
#if defined (DZIESIEC_TYSIECY) && defined (SHELL) && defined (JEDNOSTAJNY)
    StartCounter(); shell(shell_jednostajny_9, 10000); shell_wynik_49[iteracja] = GetCounter();
    StartCounter(); shell(shell_jednostajny_10, 10000); shell_wynik_50[iteracja] = GetCounter();
    StartCounter(); shell(shell_jednostajny_11, 10000); shell_wynik_51[iteracja] = GetCounter();
    StartCounter(); shell(shell_jednostajny_12, 10000); shell_wynik_52[iteracja] = GetCounter();
#endif
#if defined (STO_TYSIECY) && defined (SHELL) && defined (JEDNOSTAJNY)
    StartCounter(); shell(shell_jednostajny_13, 100000); shell_wynik_53[iteracja] = GetCounter();
    StartCounter(); shell(shell_jednostajny_14, 100000); shell_wynik_54[iteracja] = GetCounter();
    StartCounter(); shell(shell_jednostajny_15, 100000); shell_wynik_55[iteracja] = GetCounter();
    StartCounter(); shell(shell_jednostajny_16, 100000); shell_wynik_56[iteracja] = GetCounter();
#endif
#if defined (MILION) && defined (SHELL) && defined (JEDNOSTAJNY)
    StartCounter(); shell(shell_jednostajny_17, 1000000); shell_wynik_57[iteracja] = GetCounter();
    StartCounter(); shell(shell_jednostajny_18, 1000000); shell_wynik_58[iteracja] = GetCounter();
    StartCounter(); shell(shell_jednostajny_19, 1000000); shell_wynik_59[iteracja] = GetCounter();
    StartCounter(); shell(shell_jednostajny_20, 1000000); shell_wynik_60[iteracja] = GetCounter();
#endif
// ******************************************************************************************************/
//                                     quick Poisson                                                /
// ******************************************************************************************************/
#if defined (STO) && defined (QUICKSORT) && defined (POISSON)
    StartCounter(); quicksort(quick_poisson_1, 100); quick_wynik_1[iteracja] = GetCounter();
    StartCounter(); quicksort(quick_poisson_2, 100); quick_wynik_2[iteracja] = GetCounter();
    StartCounter(); quicksort(quick_poisson_3, 100); quick_wynik_3[iteracja] = GetCounter();
    StartCounter(); quicksort(quick_poisson_4, 100); quick_wynik_4[iteracja] = GetCounter();
#endif
#if defined (TYSIAC) && defined (QUICKSORT) && defined (POISSON)
    StartCounter(); quicksort(quick_poisson_5, 1000); quick_wynik_5[iteracja] = GetCounter();
    StartCounter(); quicksort(quick_poisson_6, 1000); quick_wynik_6[iteracja] = GetCounter();
    StartCounter(); quicksort(quick_poisson_7, 1000); quick_wynik_7[iteracja] = GetCounter();
    StartCounter(); quicksort(quick_poisson_8, 1000); quick_wynik_8[iteracja] = GetCounter();
#endif
#if defined (DZIESIEC_TYSIECY) && defined (QUICKSORT) && defined (POISSON)
    StartCounter(); quicksort(quick_poisson_9, 10000); quick_wynik_9[iteracja] = GetCounter();
    StartCounter(); quicksort(quick_poisson_10, 10000); quick_wynik_10[iteracja] = GetCounter();
    StartCounter(); quicksort(quick_poisson_11, 10000); quick_wynik_11[iteracja] = GetCounter();
    StartCounter(); quicksort(quick_poisson_12, 10000); quick_wynik_12[iteracja] = GetCounter();
#endif
#if defined (STO_TYSIECY) && defined (QUICKSORT) && defined (POISSON)
    StartCounter(); quicksort(quick_poisson_13, 100000); quick_wynik_13[iteracja] = GetCounter();
    StartCounter(); quicksort(quick_poisson_14, 100000); quick_wynik_14[iteracja] = GetCounter();
    StartCounter(); quicksort(quick_poisson_15, 100000); quick_wynik_15[iteracja] = GetCounter();
    StartCounter(); quicksort(quick_poisson_16, 100000); quick_wynik_16[iteracja] = GetCounter();
#endif
#if defined (MILION) && defined (QUICKSORT) && defined (POISSON)
    StartCounter(); quicksort(quick_poisson_17, 1000000); quick_wynik_17[iteracja] = GetCounter();
    StartCounter(); quicksort(quick_poisson_18, 1000000); quick_wynik_18[iteracja] = GetCounter();
    StartCounter(); quicksort(quick_poisson_19, 1000000); quick_wynik_19[iteracja] = GetCounter();
    StartCounter(); quicksort(quick_poisson_20, 1000000); quick_wynik_20[iteracja] = GetCounter();
#endif
//**********************************************************************************************************************************************
//                                              quick Gauss
//**********************************************************************************************************************************************
#if defined (STO) && defined (QUICKSORT) && defined (GAUSS)
    StartCounter(); quicksort(quick_gauss_1, 100); quick_wynik_21[iteracja] = GetCounter();
    StartCounter(); quicksort(quick_gauss_2, 100); quick_wynik_22[iteracja] = GetCounter();
    StartCounter(); quicksort(quick_gauss_3, 100); quick_wynik_23[iteracja] = GetCounter();
    StartCounter(); quicksort(quick_gauss_4, 100); quick_wynik_24[iteracja] = GetCounter();
#endif
#if defined (TYSIAC) && defined (QUICKSORT) && defined (GAUSS)
    StartCounter(); quicksort(quick_gauss_5, 1000); quick_wynik_25[iteracja] = GetCounter();
    StartCounter(); quicksort(quick_gauss_6, 1000); quick_wynik_26[iteracja] = GetCounter();
    StartCounter(); quicksort(quick_gauss_7, 1000); quick_wynik_27[iteracja] = GetCounter();
    StartCounter(); quicksort(quick_gauss_8, 1000); quick_wynik_28[iteracja] = GetCounter();
#endif
#if defined (DZIESIEC_TYSIECY) && defined (QUICKSORT) && defined (GAUSS)
    StartCounter(); quicksort(quick_gauss_9, 10000); quick_wynik_29[iteracja] = GetCounter();
    StartCounter(); quicksort(quick_gauss_10, 10000); quick_wynik_30[iteracja] = GetCounter();
    StartCounter(); quicksort(quick_gauss_11, 10000); quick_wynik_31[iteracja] = GetCounter();
    StartCounter(); quicksort(quick_gauss_12, 10000); quick_wynik_32[iteracja] = GetCounter();
#endif
#if defined (STO_TYSIECY) && defined (QUICKSORT) && defined (GAUSS)
    StartCounter(); quicksort(quick_gauss_13, 100000); quick_wynik_33[iteracja] = GetCounter();
    StartCounter(); quicksort(quick_gauss_14, 100000); quick_wynik_34[iteracja] = GetCounter();
    StartCounter(); quicksort(quick_gauss_15, 100000); quick_wynik_35[iteracja] = GetCounter();
    StartCounter(); quicksort(quick_gauss_16, 100000); quick_wynik_36[iteracja] = GetCounter();
#endif
#if defined (MILION) && defined (QUICKSORT) && defined (GAUSS)
    StartCounter(); quicksort(quick_gauss_17, 1000000); quick_wynik_37[iteracja] = GetCounter();
    StartCounter(); quicksort(quick_gauss_18, 1000000); quick_wynik_38[iteracja] = GetCounter();
    StartCounter(); quicksort(quick_gauss_19, 1000000); quick_wynik_39[iteracja] = GetCounter();
    StartCounter(); quicksort(quick_gauss_20, 1000000); quick_wynik_40[iteracja] = GetCounter();
#endif
//**********************************************************************************************************************************************
//                                              quick Jednostajny
//**********************************************************************************************************************************************
#if defined (STO) && defined (QUICKSORT) && defined (JEDNOSTAJNY)
    StartCounter(); quicksort(quick_jednostajny_1, 100); quick_wynik_41[iteracja] = GetCounter();
    StartCounter(); quicksort(quick_jednostajny_2, 100); quick_wynik_42[iteracja] = GetCounter();
    StartCounter(); quicksort(quick_jednostajny_3, 100); quick_wynik_43[iteracja] = GetCounter();
    StartCounter(); quicksort(quick_jednostajny_4, 100); quick_wynik_44[iteracja] = GetCounter();
#endif
#if defined (TYSIAC) && defined (QUICKSORT) && defined (JEDNOSTAJNY)
    StartCounter(); quicksort(quick_jednostajny_5, 1000); quick_wynik_45[iteracja] = GetCounter();
    StartCounter(); quicksort(quick_jednostajny_6, 1000); quick_wynik_46[iteracja] = GetCounter();
    StartCounter(); quicksort(quick_jednostajny_7, 1000); quick_wynik_47[iteracja] = GetCounter();
    StartCounter(); quicksort(quick_jednostajny_8, 1000); quick_wynik_48[iteracja] = GetCounter();
#endif
#if defined (DZIESIEC_TYSIECY) && defined (QUICKSORT) && defined (JEDNOSTAJNY)
    StartCounter(); quicksort(quick_jednostajny_9, 10000); quick_wynik_49[iteracja] = GetCounter();
    StartCounter(); quicksort(quick_jednostajny_10, 10000); quick_wynik_50[iteracja] = GetCounter();
    StartCounter(); quicksort(quick_jednostajny_11, 10000); quick_wynik_51[iteracja] = GetCounter();
    StartCounter(); quicksort(quick_jednostajny_12, 10000); quick_wynik_52[iteracja] = GetCounter();
#endif
#if defined (STO_TYSIECY) && defined (QUICKSORT) && defined (JEDNOSTAJNY)
    StartCounter(); quicksort(quick_jednostajny_13, 100000); quick_wynik_53[iteracja] = GetCounter();
    StartCounter(); quicksort(quick_jednostajny_14, 100000); quick_wynik_54[iteracja] = GetCounter();
    StartCounter(); quicksort(quick_jednostajny_15, 100000); quick_wynik_55[iteracja] = GetCounter();
    StartCounter(); quicksort(quick_jednostajny_16, 100000); quick_wynik_56[iteracja] = GetCounter();
#endif
#if defined (MILION) && defined (QUICKSORT) && defined (JEDNOSTAJNY)
    StartCounter(); quicksort(quick_jednostajny_17, 1000000); quick_wynik_57[iteracja] = GetCounter();
    StartCounter(); quicksort(quick_jednostajny_18, 1000000); quick_wynik_58[iteracja] = GetCounter();
    StartCounter(); quicksort(quick_jednostajny_19, 1000000); quick_wynik_59[iteracja] = GetCounter();
    StartCounter(); quicksort(quick_jednostajny_20, 1000000); quick_wynik_60[iteracja] = GetCounter();
#endif
// ******************************************************************************************************/
//                                     introsort Poisson                                                /
// ******************************************************************************************************/
#if defined (STO) && defined (INTROSORT) && defined (POISSON)
    StartCounter(); introsort(introsort_poisson_1, 100); introsort_wynik_1[iteracja] = GetCounter();
    StartCounter(); introsort(introsort_poisson_2, 100); introsort_wynik_2[iteracja] = GetCounter();
    StartCounter(); introsort(introsort_poisson_3, 100); introsort_wynik_3[iteracja] = GetCounter();
    StartCounter(); introsort(introsort_poisson_4, 100); introsort_wynik_4[iteracja] = GetCounter();
#endif
#if defined (TYSIAC) && defined (INTROSORT) && defined (POISSON)
    StartCounter(); introsort(introsort_poisson_5, 1000); introsort_wynik_5[iteracja] = GetCounter();
    StartCounter(); introsort(introsort_poisson_6, 1000); introsort_wynik_6[iteracja] = GetCounter();
    StartCounter(); introsort(introsort_poisson_7, 1000); introsort_wynik_7[iteracja] = GetCounter();
    StartCounter(); introsort(introsort_poisson_8, 1000); introsort_wynik_8[iteracja] = GetCounter();
#endif
#if defined (DZIESIEC_TYSIECY) && defined (INTROSORT) && defined (POISSON)
    StartCounter(); introsort(introsort_poisson_9, 10000); introsort_wynik_9[iteracja] = GetCounter();
    StartCounter(); introsort(introsort_poisson_10, 10000); introsort_wynik_10[iteracja] = GetCounter();
    StartCounter(); introsort(introsort_poisson_11, 10000); introsort_wynik_11[iteracja] = GetCounter();
    StartCounter(); introsort(introsort_poisson_12, 10000); introsort_wynik_12[iteracja] = GetCounter();
#endif
#if defined (STO_TYSIECY) && defined (INTROSORT) && defined (POISSON)
    StartCounter(); introsort(introsort_poisson_13, 100000); introsort_wynik_13[iteracja] = GetCounter();
    StartCounter(); introsort(introsort_poisson_14, 100000); introsort_wynik_14[iteracja] = GetCounter();
    StartCounter(); introsort(introsort_poisson_15, 100000); introsort_wynik_15[iteracja] = GetCounter();
    StartCounter(); introsort(introsort_poisson_16, 100000); introsort_wynik_16[iteracja] = GetCounter();
#endif
#if defined (MILION) && defined (INTROSORT) && defined (POISSON)
    StartCounter(); introsort(introsort_poisson_17, 1000000); introsort_wynik_17[iteracja] = GetCounter();
    StartCounter(); introsort(introsort_poisson_18, 1000000); introsort_wynik_18[iteracja] = GetCounter();
    StartCounter(); introsort(introsort_poisson_19, 1000000); introsort_wynik_19[iteracja] = GetCounter();
    StartCounter(); introsort(introsort_poisson_20, 1000000); introsort_wynik_20[iteracja] = GetCounter();
#endif
//**********************************************************************************************************************************************
//                                              introsort Gauss
//**********************************************************************************************************************************************
#if defined (STO) && defined (INTROSORT) && defined (GAUSS)
    StartCounter(); introsort(introsort_gauss_1, 100); introsort_wynik_21[iteracja] = GetCounter();
    StartCounter(); introsort(introsort_gauss_2, 100); introsort_wynik_22[iteracja] = GetCounter();
    StartCounter(); introsort(introsort_gauss_3, 100); introsort_wynik_23[iteracja] = GetCounter();
    StartCounter(); introsort(introsort_gauss_4, 100); introsort_wynik_24[iteracja] = GetCounter();
#endif
#if defined (TYSIAC) && defined (INTROSORT) && defined (GAUSS)
    StartCounter(); introsort(introsort_gauss_5, 1000); introsort_wynik_25[iteracja] = GetCounter();
    StartCounter(); introsort(introsort_gauss_6, 1000); introsort_wynik_26[iteracja] = GetCounter();
    StartCounter(); introsort(introsort_gauss_7, 1000); introsort_wynik_27[iteracja] = GetCounter();
    StartCounter(); introsort(introsort_gauss_8, 1000); introsort_wynik_28[iteracja] = GetCounter();
#endif
#if defined (DZIESIEC_TYSIECY) && defined (INTROSORT) && defined (GAUSS)
    StartCounter(); introsort(introsort_gauss_9, 10000); introsort_wynik_29[iteracja] = GetCounter();
    StartCounter(); introsort(introsort_gauss_10, 10000); introsort_wynik_30[iteracja] = GetCounter();
    StartCounter(); introsort(introsort_gauss_11, 10000); introsort_wynik_31[iteracja] = GetCounter();
    StartCounter(); introsort(introsort_gauss_12, 10000); introsort_wynik_32[iteracja] = GetCounter();
#endif
#if defined (STO_TYSIECY) && defined (INTROSORT) && defined (GAUSS)
    StartCounter(); introsort(introsort_gauss_13, 100000); introsort_wynik_33[iteracja] = GetCounter();
    StartCounter(); introsort(introsort_gauss_14, 100000); introsort_wynik_34[iteracja] = GetCounter();
    StartCounter(); introsort(introsort_gauss_15, 100000); introsort_wynik_35[iteracja] = GetCounter();
    StartCounter(); introsort(introsort_gauss_16, 100000); introsort_wynik_36[iteracja] = GetCounter();
#endif
#if defined (MILION) && defined (INTROSORT) && defined (GAUSS)
    StartCounter(); introsort(introsort_gauss_17, 1000000); introsort_wynik_37[iteracja] = GetCounter();
    StartCounter(); introsort(introsort_gauss_18, 1000000); introsort_wynik_38[iteracja] = GetCounter();
    StartCounter(); introsort(introsort_gauss_19, 1000000); introsort_wynik_39[iteracja] = GetCounter();
    StartCounter(); introsort(introsort_gauss_20, 1000000); introsort_wynik_40[iteracja] = GetCounter();
#endif
//**********************************************************************************************************************************************
//                                              introsort Jednostajny
//**********************************************************************************************************************************************
#if defined (STO) && defined (INTROSORT) && defined (JEDNOSTAJNY)
    StartCounter(); introsort(introsort_jednostajny_1, 100); introsort_wynik_41[iteracja] = GetCounter();
    StartCounter(); introsort(introsort_jednostajny_2, 100); introsort_wynik_42[iteracja] = GetCounter();
    StartCounter(); introsort(introsort_jednostajny_3, 100); introsort_wynik_43[iteracja] = GetCounter();
    StartCounter(); introsort(introsort_jednostajny_4, 100); introsort_wynik_44[iteracja] = GetCounter();
#endif
#if defined (TYSIAC) && defined (INTROSORT) && defined (JEDNOSTAJNY)
    StartCounter(); introsort(introsort_jednostajny_5, 1000); introsort_wynik_45[iteracja] = GetCounter();
    StartCounter(); introsort(introsort_jednostajny_6, 1000); introsort_wynik_46[iteracja] = GetCounter();
    StartCounter(); introsort(introsort_jednostajny_7, 1000); introsort_wynik_47[iteracja] = GetCounter();
    StartCounter(); introsort(introsort_jednostajny_8, 1000); introsort_wynik_48[iteracja] = GetCounter();
#endif
#if defined (DZIESIEC_TYSIECY) && defined (INTROSORT) && defined (JEDNOSTAJNY)
    StartCounter(); introsort(introsort_jednostajny_9, 10000); introsort_wynik_49[iteracja] = GetCounter();
    StartCounter(); introsort(introsort_jednostajny_10, 10000); introsort_wynik_50[iteracja] = GetCounter();
    StartCounter(); introsort(introsort_jednostajny_11, 10000); introsort_wynik_51[iteracja] = GetCounter();
    StartCounter(); introsort(introsort_jednostajny_12, 10000); introsort_wynik_52[iteracja] = GetCounter();
#endif
#if defined (STO_TYSIECY) && defined (INTROSORT) && defined (JEDNOSTAJNY)
    StartCounter(); introsort(introsort_jednostajny_13, 100000); introsort_wynik_53[iteracja] = GetCounter();
    StartCounter(); introsort(introsort_jednostajny_14, 100000); introsort_wynik_54[iteracja] = GetCounter();
    StartCounter(); introsort(introsort_jednostajny_15, 100000); introsort_wynik_55[iteracja] = GetCounter();
    StartCounter(); introsort(introsort_jednostajny_16, 100000); introsort_wynik_56[iteracja] = GetCounter();
#endif
#if defined (MILION) && defined (INTROSORT) && defined (JEDNOSTAJNY)
    StartCounter(); introsort(introsort_jednostajny_17, 1000000); introsort_wynik_57[iteracja] = GetCounter();
    StartCounter(); introsort(introsort_jednostajny_18, 1000000); introsort_wynik_58[iteracja] = GetCounter();
    StartCounter(); introsort(introsort_jednostajny_19, 1000000); introsort_wynik_59[iteracja] = GetCounter();
    StartCounter(); introsort(introsort_jednostajny_20, 1000000); introsort_wynik_60[iteracja] = GetCounter();
#endif
// ******************************************************************************************************/
//                                       Koniec sortowania                                               /
// ******************************************************************************************************/

// ******************************************************************************************************/
//                                       usuwanie tablic                                                 /
// ******************************************************************************************************/

// Wstawianie
#if defined (STO) && defined (WSTAWIANIE) && defined (POISSON)
delete [] wstawianie_poisson_1;
delete [] wstawianie_poisson_2;
delete [] wstawianie_poisson_3;
delete [] wstawianie_poisson_4;
#endif
#if defined (TYSIAC) && defined (WSTAWIANIE) && defined (POISSON)
delete [] wstawianie_poisson_5;
delete [] wstawianie_poisson_6;
delete [] wstawianie_poisson_7;
delete [] wstawianie_poisson_8;
#endif
#if defined (DZIESIEC_TYSIECY) && defined (WSTAWIANIE) && defined (POISSON)
delete [] wstawianie_poisson_9;
delete [] wstawianie_poisson_10;
delete [] wstawianie_poisson_11;
delete [] wstawianie_poisson_12;
#endif
#if defined (STO_TYSIECY) && defined (WSTAWIANIE) && defined (POISSON)
delete [] wstawianie_poisson_13;
delete [] wstawianie_poisson_14;
delete [] wstawianie_poisson_15;
delete [] wstawianie_poisson_16;
#endif
#if defined (MILION) && defined (WSTAWIANIE) && defined (POISSON)
delete [] wstawianie_poisson_17;
delete [] wstawianie_poisson_18;
delete [] wstawianie_poisson_19;
delete [] wstawianie_poisson_20;
#endif
#if defined (STO) && defined (WSTAWIANIE) && defined (GAUSS)
delete [] wstawianie_gauss_1;
delete [] wstawianie_gauss_2;
delete [] wstawianie_gauss_3;
delete [] wstawianie_gauss_4;
#endif
#if defined (TYSIAC) && defined (WSTAWIANIE) && defined (GAUSS)
delete [] wstawianie_gauss_5;
delete [] wstawianie_gauss_6;
delete [] wstawianie_gauss_7;
delete [] wstawianie_gauss_8;
#endif
#if defined (DZIESIEC_TYSIECY) && defined (WSTAWIANIE) && defined (GAUSS)
delete [] wstawianie_gauss_9;
delete [] wstawianie_gauss_10;
delete [] wstawianie_gauss_11;
delete [] wstawianie_gauss_12;
#endif
#if defined (STO_TYSIECY) && defined (WSTAWIANIE) && defined (GAUSS)
delete [] wstawianie_gauss_13;
delete [] wstawianie_gauss_14;
delete [] wstawianie_gauss_15;
delete [] wstawianie_gauss_16;
#endif
#if defined (MILION) && defined (WSTAWIANIE) && defined (GAUSS)
delete [] wstawianie_gauss_17;
delete [] wstawianie_gauss_18;
delete [] wstawianie_gauss_19;
delete [] wstawianie_gauss_20;
#endif
#if defined (STO) && defined (WSTAWIANIE) && defined (JEDNOSTAJNY)
delete [] wstawianie_jednostajny_1;
delete [] wstawianie_jednostajny_2;
delete [] wstawianie_jednostajny_3;
delete [] wstawianie_jednostajny_4;
#endif
#if defined (TYSIAC) && defined (WSTAWIANIE) && defined (JEDNOSTAJNY)
delete [] wstawianie_jednostajny_5;
delete [] wstawianie_jednostajny_6;
delete [] wstawianie_jednostajny_7;
delete [] wstawianie_jednostajny_8;
#endif
#if defined (DZIESIEC_TYSIECY) && defined (WSTAWIANIE) && defined (JEDNOSTAJNY)
delete [] wstawianie_jednostajny_9;
delete [] wstawianie_jednostajny_10;
delete [] wstawianie_jednostajny_11;
delete [] wstawianie_jednostajny_12;
#endif
#if defined (STO_TYSIECY) && defined (WSTAWIANIE) && defined (JEDNOSTAJNY)
delete [] wstawianie_jednostajny_13;
delete [] wstawianie_jednostajny_14;
delete [] wstawianie_jednostajny_15;
delete [] wstawianie_jednostajny_16;
#endif
#if defined (MILION) && defined (WSTAWIANIE) && defined (JEDNOSTAJNY)
delete [] wstawianie_jednostajny_17;
delete [] wstawianie_jednostajny_18;
delete [] wstawianie_jednostajny_19;
delete [] wstawianie_jednostajny_20;
#endif
// Kopcowanie
#if defined (STO) && defined (KOPCOWANIE) && defined (POISSON)
delete [] kopcowanie_poisson_1;
delete [] kopcowanie_poisson_2;
delete [] kopcowanie_poisson_3;
delete [] kopcowanie_poisson_4;
#endif
#if defined (TYSIAC) && defined (KOPCOWANIE) && defined (POISSON)
delete [] kopcowanie_poisson_5;
delete [] kopcowanie_poisson_6;
delete [] kopcowanie_poisson_7;
delete [] kopcowanie_poisson_8;
#endif
#if defined (DZIESIEC_TYSIECY) && defined (KOPCOWANIE) && defined (POISSON)
delete [] kopcowanie_poisson_9;
delete [] kopcowanie_poisson_10;
delete [] kopcowanie_poisson_11;
delete [] kopcowanie_poisson_12;
#endif
#if defined (STO_TYSIECY) && defined (KOPCOWANIE) && defined (POISSON)
delete [] kopcowanie_poisson_13;
delete [] kopcowanie_poisson_14;
delete [] kopcowanie_poisson_15;
delete [] kopcowanie_poisson_16;
#endif
#if defined (MILION) && defined (KOPCOWANIE) && defined (POISSON)
delete [] kopcowanie_poisson_17;
delete [] kopcowanie_poisson_18;
delete [] kopcowanie_poisson_19;
delete [] kopcowanie_poisson_20;
#endif
#if defined (STO) && defined (KOPCOWANIE) && defined (GAUSS)
delete [] kopcowanie_gauss_1;
delete [] kopcowanie_gauss_2;
delete [] kopcowanie_gauss_3;
delete [] kopcowanie_gauss_4;
#endif
#if defined (TYSIAC) && defined (KOPCOWANIE) && defined (GAUSS)
delete [] kopcowanie_gauss_5;
delete [] kopcowanie_gauss_6;
delete [] kopcowanie_gauss_7;
delete [] kopcowanie_gauss_8;
#endif
#if defined (DZIESIEC_TYSIECY) && defined (KOPCOWANIE) && defined (GAUSS)
delete [] kopcowanie_gauss_9;
delete [] kopcowanie_gauss_10;
delete [] kopcowanie_gauss_11;
delete [] kopcowanie_gauss_12;
#endif
#if defined (STO_TYSIECY) && defined (KOPCOWANIE) && defined (GAUSS)
delete [] kopcowanie_gauss_13;
delete [] kopcowanie_gauss_14;
delete [] kopcowanie_gauss_15;
delete [] kopcowanie_gauss_16;
#endif
#if defined (MILION) && defined (KOPCOWANIE) && defined (GAUSS)
delete [] kopcowanie_gauss_17;
delete [] kopcowanie_gauss_18;
delete [] kopcowanie_gauss_19;
delete [] kopcowanie_gauss_20;
#endif
#if defined (STO) && defined (KOPCOWANIE) && defined (JEDNOSTAJNY)
delete [] kopcowanie_jednostajny_1;
delete [] kopcowanie_jednostajny_2;
delete [] kopcowanie_jednostajny_3;
delete [] kopcowanie_jednostajny_4;
#endif
#if defined (TYSIAC) && defined (KOPCOWANIE) && defined (JEDNOSTAJNY)
delete [] kopcowanie_jednostajny_5;
delete [] kopcowanie_jednostajny_6;
delete [] kopcowanie_jednostajny_7;
delete [] kopcowanie_jednostajny_8;
#endif
#if defined (DZIESIEC_TYSIECY) && defined (KOPCOWANIE) && defined (JEDNOSTAJNY)
delete [] kopcowanie_jednostajny_9;
delete [] kopcowanie_jednostajny_10;
delete [] kopcowanie_jednostajny_11;
delete [] kopcowanie_jednostajny_12;
#endif
#if defined (STO_TYSIECY) && defined (KOPCOWANIE) && defined (JEDNOSTAJNY)
delete [] kopcowanie_jednostajny_13;
delete [] kopcowanie_jednostajny_14;
delete [] kopcowanie_jednostajny_15;
delete [] kopcowanie_jednostajny_16;
#endif
#if defined (MILION) && defined (KOPCOWANIE) && defined (JEDNOSTAJNY)
delete [] kopcowanie_jednostajny_17;
delete [] kopcowanie_jednostajny_18;
delete [] kopcowanie_jednostajny_19;
delete [] kopcowanie_jednostajny_20;
#endif
// Shell
#if defined (STO) && defined (SHELL) && defined (POISSON)
delete [] shell_poisson_1;
delete [] shell_poisson_2;
delete [] shell_poisson_3;
delete [] shell_poisson_4;
#endif
#if defined (TYSIAC) && defined (SHELL) && defined (POISSON)
delete [] shell_poisson_5;
delete [] shell_poisson_6;
delete [] shell_poisson_7;
delete [] shell_poisson_8;
#endif
#if defined (DZIESIEC_TYSIECY) && defined (SHELL) && defined (POISSON)
delete [] shell_poisson_9;
delete [] shell_poisson_10;
delete [] shell_poisson_11;
delete [] shell_poisson_12;
#endif
#if defined (STO_TYSIECY) && defined (SHELL) && defined (POISSON)
delete [] shell_poisson_13;
delete [] shell_poisson_14;
delete [] shell_poisson_15;
delete [] shell_poisson_16;
#endif
#if defined (MILION) && defined (SHELL) && defined (POISSON)
delete [] shell_poisson_17;
delete [] shell_poisson_18;
delete [] shell_poisson_19;
delete [] shell_poisson_20;
#endif
#if defined (STO) && defined (SHELL) && defined (GAUSS)
delete [] shell_gauss_1;
delete [] shell_gauss_2;
delete [] shell_gauss_3;
delete [] shell_gauss_4;
#endif
#if defined (TYSIAC) && defined (SHELL) && defined (GAUSS)
delete [] shell_gauss_5;
delete [] shell_gauss_6;
delete [] shell_gauss_7;
delete [] shell_gauss_8;
#endif
#if defined (DZIESIEC_TYSIECY) && defined (SHELL) && defined (GAUSS)
delete [] shell_gauss_9;
delete [] shell_gauss_10;
delete [] shell_gauss_11;
delete [] shell_gauss_12;
#endif
#if defined (STO_TYSIECY) && defined (SHELL) && defined (GAUSS)
delete [] shell_gauss_13;
delete [] shell_gauss_14;
delete [] shell_gauss_15;
delete [] shell_gauss_16;
#endif
#if defined (MILION) && defined (SHELL) && defined (GAUSS)
delete [] shell_gauss_17;
delete [] shell_gauss_18;
delete [] shell_gauss_19;
delete [] shell_gauss_20;
#endif
#if defined (STO) && defined (SHELL) && defined (JEDNOSTAJNY)
delete [] shell_jednostajny_1;
delete [] shell_jednostajny_2;
delete [] shell_jednostajny_3;
delete [] shell_jednostajny_4;
#endif
#if defined (TYSIAC) && defined (SHELL) && defined (JEDNOSTAJNY)
delete [] shell_jednostajny_5;
delete [] shell_jednostajny_6;
delete [] shell_jednostajny_7;
delete [] shell_jednostajny_8;
#endif
#if defined (DZIESIEC_TYSIECY) && defined (SHELL) && defined (JEDNOSTAJNY)
delete [] shell_jednostajny_9;
delete [] shell_jednostajny_10;
delete [] shell_jednostajny_11;
delete [] shell_jednostajny_12;
#endif
#if defined (STO_TYSIECY) && defined (SHELL) && defined (JEDNOSTAJNY)
delete [] shell_jednostajny_13;
delete [] shell_jednostajny_14;
delete [] shell_jednostajny_15;
delete [] shell_jednostajny_16;
#endif
#if defined (MILION) && defined (SHELL) && defined (JEDNOSTAJNY)
delete [] shell_jednostajny_17;
delete [] shell_jednostajny_18;
delete [] shell_jednostajny_19;
delete [] shell_jednostajny_20;
#endif
// Quicksort
#if defined (STO) && defined (QUICKSORT) && defined (POISSON)
delete [] quick_poisson_1;
delete [] quick_poisson_2;
delete [] quick_poisson_3;
delete [] quick_poisson_4;
#endif
#if defined (TYSIAC) && defined (QUICKSORT) && defined (POISSON)
delete [] quick_poisson_5;
delete [] quick_poisson_6;
delete [] quick_poisson_7;
delete [] quick_poisson_8;
#endif
#if defined (DZIESIEC_TYSIECY) && defined (QUICKSORT) && defined (POISSON)
delete [] quick_poisson_9;
delete [] quick_poisson_10;
delete [] quick_poisson_11;
delete [] quick_poisson_12;
#endif
#if defined (STO_TYSIECY) && defined (QUICKSORT) && defined (POISSON)
delete [] quick_poisson_13;
delete [] quick_poisson_14;
delete [] quick_poisson_15;
delete [] quick_poisson_16;
#endif
#if defined (MILION) && defined (QUICKSORT) && defined (POISSON)
delete [] quick_poisson_17;
delete [] quick_poisson_18;
delete [] quick_poisson_19;
delete [] quick_poisson_20;
#endif
#if defined (STO) && defined (QUICKSORT) && defined (GAUSS)
delete [] quick_gauss_1;
delete [] quick_gauss_2;
delete [] quick_gauss_3;
delete [] quick_gauss_4;
#endif
#if defined (TYSIAC) && defined (QUICKSORT) && defined (GAUSS)
delete [] quick_gauss_5;
delete [] quick_gauss_6;
delete [] quick_gauss_7;
delete [] quick_gauss_8;
#endif
#if defined (DZIESIEC_TYSIECY) && defined (QUICKSORT) && defined (GAUSS)
delete [] quick_gauss_9;
delete [] quick_gauss_10;
delete [] quick_gauss_11;
delete [] quick_gauss_12;
#endif
#if defined (STO_TYSIECY) && defined (QUICKSORT) && defined (GAUSS)
delete [] quick_gauss_13;
delete [] quick_gauss_14;
delete [] quick_gauss_15;
delete [] quick_gauss_16;
#endif
#if defined (MILION) && defined (QUICKSORT) && defined (GAUSS)
delete [] quick_gauss_17;
delete [] quick_gauss_18;
delete [] quick_gauss_19;
delete [] quick_gauss_20;
#endif
#if defined (STO) && defined (QUICKSORT) && defined (JEDNOSTAJNY)
delete [] quick_jednostajny_1;
delete [] quick_jednostajny_2;
delete [] quick_jednostajny_3;
delete [] quick_jednostajny_4;
#endif
#if defined (TYSIAC) && defined (QUICKSORT) && defined (JEDNOSTAJNY)
delete [] quick_jednostajny_5;
delete [] quick_jednostajny_6;
delete [] quick_jednostajny_7;
delete [] quick_jednostajny_8;
#endif
#if defined (DZIESIEC_TYSIECY) && defined (QUICKSORT) && defined (JEDNOSTAJNY)
delete [] quick_jednostajny_9;
delete [] quick_jednostajny_10;
delete [] quick_jednostajny_11;
delete [] quick_jednostajny_12;
#endif
#if defined (STO_TYSIECY) && defined (QUICKSORT) && defined (JEDNOSTAJNY)
delete [] quick_jednostajny_13;
delete [] quick_jednostajny_14;
delete [] quick_jednostajny_15;
delete [] quick_jednostajny_16;
#endif
#if defined (MILION) && defined (QUICKSORT) && defined (JEDNOSTAJNY)
delete [] quick_jednostajny_17;
delete [] quick_jednostajny_18;
delete [] quick_jednostajny_19;
delete [] quick_jednostajny_20;
#endif
// Introsort
#if defined (STO) && defined (INTROSORT) && defined (POISSON)
delete [] introsort_poisson_1;
delete [] introsort_poisson_2;
delete [] introsort_poisson_3;
delete [] introsort_poisson_4;
#endif
#if defined (TYSIAC) && defined (INTROSORT) && defined (POISSON)
delete [] introsort_poisson_5;
delete [] introsort_poisson_6;
delete [] introsort_poisson_7;
delete [] introsort_poisson_8;
#endif
#if defined (DZIESIEC_TYSIECY) && defined (INTROSORT) && defined (POISSON)
delete [] introsort_poisson_9;
delete [] introsort_poisson_10;
delete [] introsort_poisson_11;
delete [] introsort_poisson_12;
#endif
#if defined (STO_TYSIECY) && defined (INTROSORT) && defined (POISSON)
delete [] introsort_poisson_13;
delete [] introsort_poisson_14;
delete [] introsort_poisson_15;
delete [] introsort_poisson_16;
#endif
#if defined (MILION) && defined (INTROSORT) && defined (POISSON)
delete [] introsort_poisson_17;
delete [] introsort_poisson_18;
delete [] introsort_poisson_19;
delete [] introsort_poisson_20;
#endif
#if defined (STO) && defined (INTROSORT) && defined (GAUSS)
delete [] introsort_gauss_1;
delete [] introsort_gauss_2;
delete [] introsort_gauss_3;
delete [] introsort_gauss_4;
#endif
#if defined (TYSIAC) && defined (INTROSORT) && defined (GAUSS)
delete [] introsort_gauss_5;
delete [] introsort_gauss_6;
delete [] introsort_gauss_7;
delete [] introsort_gauss_8;
#endif
#if defined (DZIESIEC_TYSIECY) && defined (INTROSORT) && defined (GAUSS)
delete [] introsort_gauss_9;
delete [] introsort_gauss_10;
delete [] introsort_gauss_11;
delete [] introsort_gauss_12;
#endif
#if defined (STO_TYSIECY) && defined (INTROSORT) && defined (GAUSS)
delete [] introsort_gauss_13;
delete [] introsort_gauss_14;
delete [] introsort_gauss_15;
delete [] introsort_gauss_16;
#endif
#if defined (MILION) && defined (INTROSORT) && defined (GAUSS)
delete [] introsort_gauss_17;
delete [] introsort_gauss_18;
delete [] introsort_gauss_19;
delete [] introsort_gauss_20;
#endif
#if defined (STO) && defined (INTROSORT) && defined (JEDNOSTAJNY)
delete [] introsort_jednostajny_1;
delete [] introsort_jednostajny_2;
delete [] introsort_jednostajny_3;
delete [] introsort_jednostajny_4;
#endif
#if defined (TYSIAC) && defined (INTROSORT) && defined (JEDNOSTAJNY)
delete [] introsort_jednostajny_5;
delete [] introsort_jednostajny_6;
delete [] introsort_jednostajny_7;
delete [] introsort_jednostajny_8;
#endif
#if defined (DZIESIEC_TYSIECY) && defined (INTROSORT) && defined (JEDNOSTAJNY)
delete [] introsort_jednostajny_9;
delete [] introsort_jednostajny_10;
delete [] introsort_jednostajny_11;
delete [] introsort_jednostajny_12;
#endif
#if defined (STO_TYSIECY) && defined (INTROSORT) && defined (JEDNOSTAJNY)
delete [] introsort_jednostajny_13;
delete [] introsort_jednostajny_14;
delete [] introsort_jednostajny_15;
delete [] introsort_jednostajny_16;
#endif
#if defined (MILION) && defined (INTROSORT) && defined (JEDNOSTAJNY)
delete [] introsort_jednostajny_17;
delete [] introsort_jednostajny_18;
delete [] introsort_jednostajny_19;
delete [] introsort_jednostajny_20;
#endif
}
// ******************************************************************************************************/
//                                         KONIEC PÊTLI                                                  /
// ******************************************************************************************************/
//
fstream plik_zapis("C:/wyniki.txt", ios::out);
double linia;
if (plik_zapis.good())
//cout << "Plik otworzono / stworzono pomyslnie  " << endl;
{
// WSTAWIANIE
#if defined (STO) && defined (WSTAWIANIE) && defined (POISSON)
for(int i=0;i<ilosc_iteracji;i++) {linia =  wstawianie_wynik_1[i]; plik_zapis << linia << ",";}
plik_zapis << " Wstawianie " << "," << "Poisson" << "," << "100" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  wstawianie_wynik_2[i]; plik_zapis << linia << ",";}
plik_zapis << " Wstawianie " << "," << "Poisson" << "," << "100" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  wstawianie_wynik_3[i]; plik_zapis << linia << ",";}
plik_zapis << " Wstawianie " << "," << "Poisson" << "," << "100" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  wstawianie_wynik_4[i]; plik_zapis << linia << ",";}
plik_zapis << " Wstawianie " << "," << "Poisson" << "," << "100" << "," << "99%" << endl;
#endif
#if defined (TYSIAC) && defined (WSTAWIANIE) && defined (POISSON)
for(int i=0;i<ilosc_iteracji;i++) {linia =  wstawianie_wynik_5[i]; plik_zapis << linia << ",";}
plik_zapis << " Wstawianie " << "," << "Poisson" << "," << "1000" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  wstawianie_wynik_6[i]; plik_zapis << linia << ",";}
plik_zapis << " Wstawianie " << "," << "Poisson" << "," << "1000" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  wstawianie_wynik_7[i]; plik_zapis << linia << ",";}
plik_zapis << " Wstawianie " << "," << "Poisson" << "," << "1000" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  wstawianie_wynik_8[i]; plik_zapis << linia << ",";}
plik_zapis << " Wstawianie " << "," << "Poisson" << "," << "1000" << "," << "99%" << endl;
#endif
#if defined (DZIESIEC_TYSIECY) && defined (WSTAWIANIE) && defined (POISSON)
for(int i=0;i<ilosc_iteracji;i++) {linia =  wstawianie_wynik_9[i]; plik_zapis << linia << ",";}
plik_zapis << " Wstawianie " << "," << "Poisson" << "," << "10000" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  wstawianie_wynik_10[i]; plik_zapis << linia << ",";}
plik_zapis << " Wstawianie " << "," << "Poisson" << "," << "10000" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  wstawianie_wynik_11[i]; plik_zapis << linia << ",";}
plik_zapis << " Wstawianie " << "," << "Poisson" << "," << "10000" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  wstawianie_wynik_12[i]; plik_zapis << linia << ",";}
plik_zapis << " Wstawianie " << "," << "Poisson" << "," << "10000" << "," << "99%" << endl;
#endif
#if defined (STO_TYSIECY) && defined (WSTAWIANIE) && defined (POISSON)
for(int i=0;i<ilosc_iteracji;i++) {linia =  wstawianie_wynik_13[i]; plik_zapis << linia << ",";}
plik_zapis << " Wstawianie " << "," << "Poisson" << "," << "100000" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  wstawianie_wynik_14[i]; plik_zapis << linia << ",";}
plik_zapis << " Wstawianie " << "," << "Poisson" << "," << "100000" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  wstawianie_wynik_15[i]; plik_zapis << linia << ",";}
plik_zapis << " Wstawianie " << "," << "Poisson" << "," << "100000" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  wstawianie_wynik_16[i]; plik_zapis << linia << ",";}
plik_zapis << " Wstawianie " << "," << "Poisson" << "," << "100000" << "," << "99%" << endl;
#endif
#if defined (MILION) && defined (WSTAWIANIE) && defined (POISSON)
for(int i=0;i<ilosc_iteracji;i++) {linia =  wstawianie_wynik_17[i]; plik_zapis << linia << ",";}
plik_zapis << " Wstawianie " << "," << "Poisson" << "," << "1000000" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  wstawianie_wynik_18[i]; plik_zapis << linia << ",";}
plik_zapis << " Wstawianie " << "," << "Poisson" << "," << "1000000" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  wstawianie_wynik_19[i]; plik_zapis << linia << ",";}
plik_zapis << " Wstawianie " << "," << "Poisson" << "," << "1000000" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  wstawianie_wynik_20[i]; plik_zapis << linia << ",";}
plik_zapis << " Wstawianie " << "," << "Poisson" << "," << "1000000" << "," << "99%" << endl;
#endif
#if defined (STO) && defined (WSTAWIANIE) && defined (GAUSS)
for(int i=0;i<ilosc_iteracji;i++) {linia =  wstawianie_wynik_21[i]; plik_zapis << linia << ",";}
plik_zapis << " Wstawianie " << "," << "Gauss" << "," << "100" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  wstawianie_wynik_22[i]; plik_zapis << linia << ",";}
plik_zapis << " Wstawianie " << "," << "Gauss" << "," << "100" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  wstawianie_wynik_23[i]; plik_zapis << linia << ",";}
plik_zapis << " Wstawianie " << "," << "Gauss" << "," << "100" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  wstawianie_wynik_24[i]; plik_zapis << linia << ",";}
plik_zapis << " Wstawianie " << "," << "Gauss" << "," << "100" << "," << "99%" << endl;
#endif
#if defined (TYSIAC) && defined (WSTAWIANIE) && defined (GAUSS)
for(int i=0;i<ilosc_iteracji;i++) {linia =  wstawianie_wynik_25[i]; plik_zapis << linia << ",";}
plik_zapis << " Wstawianie " << "," << "Gauss" << "," << "1000" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  wstawianie_wynik_26[i]; plik_zapis << linia << ",";}
plik_zapis << " Wstawianie " << "," << "Gauss" << "," << "1000" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  wstawianie_wynik_27[i]; plik_zapis << linia << ",";}
plik_zapis << " Wstawianie " << "," << "Gauss" << "," << "1000" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  wstawianie_wynik_28[i]; plik_zapis << linia << ",";}
plik_zapis << " Wstawianie " << "," << "Gauss" << "," << "1000" << "," << "99%" << endl;
#endif
#if defined (DZIESIEC_TYSIECY) && defined (WSTAWIANIE) && defined (GAUSS)
for(int i=0;i<ilosc_iteracji;i++) {linia =  wstawianie_wynik_29[i]; plik_zapis << linia << ",";}
plik_zapis << " Wstawianie " << "," << "Gauss" << "," << "10000" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  wstawianie_wynik_30[i]; plik_zapis << linia << ",";}
plik_zapis << " Wstawianie " << "," << "Gauss" << "," << "10000" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  wstawianie_wynik_31[i]; plik_zapis << linia << ",";}
plik_zapis << " Wstawianie " << "," << "Gauss" << "," << "10000" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  wstawianie_wynik_32[i]; plik_zapis << linia << ",";}
plik_zapis << " Wstawianie " << "," << "Gauss" << "," << "10000" << "," << "99%" << endl;
#endif
#if defined (STO_TYSIECY) && defined (WSTAWIANIE) && defined (GAUSS)
for(int i=0;i<ilosc_iteracji;i++) {linia =  wstawianie_wynik_33[i]; plik_zapis << linia << ",";}
plik_zapis << " Wstawianie " << "," << "Gauss" << "," << "100000" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  wstawianie_wynik_34[i]; plik_zapis << linia << ",";}
plik_zapis << " Wstawianie " << "," << "Gauss" << "," << "100000" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  wstawianie_wynik_35[i]; plik_zapis << linia << ",";}
plik_zapis << " Wstawianie " << "," << "Gauss" << "," << "100000" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  wstawianie_wynik_36[i]; plik_zapis << linia << ",";}
plik_zapis << " Wstawianie " << "," << "Gauss" << "," << "100000" << "," << "99%" << endl;
#endif
#if defined (MILION) && defined (WSTAWIANIE) && defined (GAUSS)
for(int i=0;i<ilosc_iteracji;i++) {linia =  wstawianie_wynik_37[i]; plik_zapis << linia << ",";}
plik_zapis << " Wstawianie " << "," << "Gauss" << "," << "1000000" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  wstawianie_wynik_38[i]; plik_zapis << linia << ",";}
plik_zapis << " Wstawianie " << "," << "Gauss" << "," << "1000000" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  wstawianie_wynik_39[i]; plik_zapis << linia << ",";}
plik_zapis << " Wstawianie " << "," << "Gauss" << "," << "1000000" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  wstawianie_wynik_40[i]; plik_zapis << linia << ",";}
plik_zapis << " Wstawianie " << "," << "Gauss" << "," << "1000000" << "," << "99%" << endl;
#endif
#if defined (STO) && defined (WSTAWIANIE) && defined (JEDNOSTAJNY)
for(int i=0;i<ilosc_iteracji;i++) {linia =  wstawianie_wynik_41[i]; plik_zapis << linia << ",";}
plik_zapis << " Wstawianie " << "," << "Jednostajny" << "," << "100" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  wstawianie_wynik_42[i]; plik_zapis << linia << ",";}
plik_zapis << " Wstawianie " << "," << "Jednostajny" << "," << "100" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  wstawianie_wynik_43[i]; plik_zapis << linia << ",";}
plik_zapis << " Wstawianie " << "," << "Jednostajny" << "," << "100" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  wstawianie_wynik_44[i]; plik_zapis << linia << ",";}
plik_zapis << " Wstawianie " << "," << "Jednostajny" << "," << "100" << "," << "99%" << endl;
#endif
#if defined (TYSIAC) && defined (WSTAWIANIE) && defined (JEDNOSTAJNY)
for(int i=0;i<ilosc_iteracji;i++) {linia =  wstawianie_wynik_45[i]; plik_zapis << linia << ",";}
plik_zapis << " Wstawianie " << "," << "Jednostajny" << "," << "1000" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  wstawianie_wynik_46[i]; plik_zapis << linia << ",";}
plik_zapis << " Wstawianie " << "," << "Jednostajny" << "," << "1000" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  wstawianie_wynik_47[i]; plik_zapis << linia << ",";}
plik_zapis << " Wstawianie " << "," << "Jednostajny" << "," << "1000" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  wstawianie_wynik_48[i]; plik_zapis << linia << ",";}
plik_zapis << " Wstawianie " << "," << "Jednostajny" << "," << "1000" << "," << "99%" << endl;
#endif
#if defined (DZIESIEC_TYSIECY) && defined (WSTAWIANIE) && defined (JEDNOSTAJNY)
for(int i=0;i<ilosc_iteracji;i++) {linia =  wstawianie_wynik_49[i]; plik_zapis << linia << ",";}
plik_zapis << " Wstawianie " << "," << "Jednostajny" << "," << "10000" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  wstawianie_wynik_50[i]; plik_zapis << linia << ",";}
plik_zapis << " Wstawianie " << "," << "Jednostajny" << "," << "10000" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  wstawianie_wynik_51[i]; plik_zapis << linia << ",";}
plik_zapis << " Wstawianie " << "," << "Jednostajny" << "," << "10000" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  wstawianie_wynik_52[i]; plik_zapis << linia << ",";}
plik_zapis << " Wstawianie " << "," << "Jednostajny" << "," << "10000" << "," << "99%" << endl;
#endif
#if defined (STO_TYSIECY) && defined (WSTAWIANIE) && defined (JEDNOSTAJNY)
for(int i=0;i<ilosc_iteracji;i++) {linia =  wstawianie_wynik_53[i]; plik_zapis << linia << ",";}
plik_zapis << " Wstawianie " << "," << "Jednostajny" << "," << "100000" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  wstawianie_wynik_54[i]; plik_zapis << linia << ",";}
plik_zapis << " Wstawianie " << "," << "Jednostajny" << "," << "100000" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  wstawianie_wynik_55[i]; plik_zapis << linia << ",";}
plik_zapis << " Wstawianie " << "," << "Jednostajny" << "," << "100000" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  wstawianie_wynik_56[i]; plik_zapis << linia << ",";}
plik_zapis << " Wstawianie " << "," << "Jednostajny" << "," << "100000" << "," << "99%" << endl;
#endif
#if defined (MILION) && defined (WSTAWIANIE) && defined (JEDNOSTAJNY)
for(int i=0;i<ilosc_iteracji;i++) {linia =  wstawianie_wynik_57[i]; plik_zapis << linia << ",";}
plik_zapis << " Wstawianie " << "," << "Jednostajny" << "," << "1000000" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  wstawianie_wynik_58[i]; plik_zapis << linia << ",";}
plik_zapis << " Wstawianie " << "," << "Jednostajny" << "," << "1000000" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  wstawianie_wynik_59[i]; plik_zapis << linia << ",";}
plik_zapis << " Wstawianie " << "," << "Jednostajny" << "," << "1000000" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  wstawianie_wynik_60[i]; plik_zapis << linia << ",";}
plik_zapis << " Wstawianie " << "," << "Jednostajny" << "," << "1000000" << "," << "99%" << endl;
#endif
// KOPCOWANIE
#if defined (STO) && defined (KOPCOWANIE) && defined (POISSON)
for(int i=0;i<ilosc_iteracji;i++) {linia =  kopcowanie_wynik_1[i]; plik_zapis << linia << ",";}
plik_zapis << " Kopcowanie " << "," << "Poisson" << "," << "100" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  kopcowanie_wynik_2[i]; plik_zapis << linia << ",";}
plik_zapis << " Kopcowanie " << "," << "Poisson" << "," << "100" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  kopcowanie_wynik_3[i]; plik_zapis << linia << ",";}
plik_zapis << " Kopcowanie " << "," << "Poisson" << "," << "100" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  kopcowanie_wynik_4[i]; plik_zapis << linia << ",";}
plik_zapis << " Kopcowanie " << "," << "Poisson" << "," << "100" << "," << "99%" << endl;
#endif
#if defined (TYSIAC) && defined (KOPCOWANIE) && defined (POISSON)
for(int i=0;i<ilosc_iteracji;i++) {linia =  kopcowanie_wynik_5[i]; plik_zapis << linia << ",";}
plik_zapis << " Kopcowanie " << "," << "Poisson" << "," << "1000" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  kopcowanie_wynik_6[i]; plik_zapis << linia << ",";}
plik_zapis << " Kopcowanie " << "," << "Poisson" << "," << "1000" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  kopcowanie_wynik_7[i]; plik_zapis << linia << ",";}
plik_zapis << " Kopcowanie " << "," << "Poisson" << "," << "1000" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  kopcowanie_wynik_8[i]; plik_zapis << linia << ",";}
plik_zapis << " Kopcowanie " << "," << "Poisson" << "," << "1000" << "," << "99%" << endl;
#endif
#if defined (DZIESIEC_TYSIECY) && defined (KOPCOWANIE) && defined (POISSON)
for(int i=0;i<ilosc_iteracji;i++) {linia =  kopcowanie_wynik_9[i]; plik_zapis << linia << ",";}
plik_zapis << " Kopcowanie " << "," << "Poisson" << "," << "10000" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  kopcowanie_wynik_10[i]; plik_zapis << linia << ",";}
plik_zapis << " Kopcowanie " << "," << "Poisson" << "," << "10000" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  kopcowanie_wynik_11[i]; plik_zapis << linia << ",";}
plik_zapis << " Kopcowanie " << "," << "Poisson" << "," << "10000" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  kopcowanie_wynik_12[i]; plik_zapis << linia << ",";}
plik_zapis << " Kopcowanie " << "," << "Poisson" << "," << "10000" << "," << "99%" << endl;
#endif
#if defined (STO_TYSIECY) && defined (KOPCOWANIE) && defined (POISSON)
for(int i=0;i<ilosc_iteracji;i++) {linia =  kopcowanie_wynik_13[i]; plik_zapis << linia << ",";}
plik_zapis << " Kopcowanie " << "," << "Poisson" << "," << "100000" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  kopcowanie_wynik_14[i]; plik_zapis << linia << ",";}
plik_zapis << " Kopcowanie " << "," << "Poisson" << "," << "100000" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  kopcowanie_wynik_15[i]; plik_zapis << linia << ",";}
plik_zapis << " Kopcowanie " << "," << "Poisson" << "," << "100000" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  kopcowanie_wynik_16[i]; plik_zapis << linia << ",";}
plik_zapis << " Kopcowanie " << "," << "Poisson" << "," << "100000" << "," << "99%" << endl;
#endif
#if defined (MILION) && defined (KOPCOWANIE) && defined (POISSON)
for(int i=0;i<ilosc_iteracji;i++) {linia =  kopcowanie_wynik_17[i]; plik_zapis << linia << ",";}
plik_zapis << " Kopcowanie " << "," << "Poisson" << "," << "1000000" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  kopcowanie_wynik_18[i]; plik_zapis << linia << ",";}
plik_zapis << " Kopcowanie " << "," << "Poisson" << "," << "1000000" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  kopcowanie_wynik_19[i]; plik_zapis << linia << ",";}
plik_zapis << " Kopcowanie " << "," << "Poisson" << "," << "1000000" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  kopcowanie_wynik_20[i]; plik_zapis << linia << ",";}
plik_zapis << " Kopcowanie " << "," << "Poisson" << "," << "1000000" << "," << "99%" << endl;
#endif
#if defined (STO) && defined (KOPCOWANIE) && defined (GAUSS)
for(int i=0;i<ilosc_iteracji;i++) {linia =  kopcowanie_wynik_21[i]; plik_zapis << linia << ",";}
plik_zapis << " Kopcowanie " << "," << "Gauss" << "," << "100" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  kopcowanie_wynik_22[i]; plik_zapis << linia << ",";}
plik_zapis << " Kopcowanie " << "," << "Gauss" << "," << "100" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  kopcowanie_wynik_23[i]; plik_zapis << linia << ",";}
plik_zapis << " Kopcowanie " << "," << "Gauss" << "," << "100" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  kopcowanie_wynik_24[i]; plik_zapis << linia << ",";}
plik_zapis << " Kopcowanie " << "," << "Gauss" << "," << "100" << "," << "99%" << endl;
#endif
#if defined (TYSIAC) && defined (KOPCOWANIE) && defined (GAUSS)
for(int i=0;i<ilosc_iteracji;i++) {linia =  kopcowanie_wynik_25[i]; plik_zapis << linia << ",";}
plik_zapis << " Kopcowanie " << "," << "Gauss" << "," << "1000" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  kopcowanie_wynik_26[i]; plik_zapis << linia << ",";}
plik_zapis << " Kopcowanie " << "," << "Gauss" << "," << "1000" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  kopcowanie_wynik_27[i]; plik_zapis << linia << ",";}
plik_zapis << " Kopcowanie " << "," << "Gauss" << "," << "1000" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  kopcowanie_wynik_28[i]; plik_zapis << linia << ",";}
plik_zapis << " Kopcowanie " << "," << "Gauss" << "," << "1000" << "," << "99%" << endl;
#endif
#if defined (DZIESIEC_TYSIECY) && defined (KOPCOWANIE) && defined (GAUSS)
for(int i=0;i<ilosc_iteracji;i++) {linia =  kopcowanie_wynik_29[i]; plik_zapis << linia << ",";}
plik_zapis << " Kopcowanie " << "," << "Gauss" << "," << "10000" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  kopcowanie_wynik_30[i]; plik_zapis << linia << ",";}
plik_zapis << " Kopcowanie " << "," << "Gauss" << "," << "10000" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  kopcowanie_wynik_31[i]; plik_zapis << linia << ",";}
plik_zapis << " Kopcowanie " << "," << "Gauss" << "," << "10000" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  kopcowanie_wynik_32[i]; plik_zapis << linia << ",";}
plik_zapis << " Kopcowanie " << "," << "Gauss" << "," << "10000" << "," << "99%" << endl;
#endif
#if defined (STO_TYSIECY) && defined (KOPCOWANIE) && defined (GAUSS)
for(int i=0;i<ilosc_iteracji;i++) {linia =  kopcowanie_wynik_33[i]; plik_zapis << linia << ",";}
plik_zapis << " Kopcowanie " << "," << "Gauss" << "," << "100000" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  kopcowanie_wynik_34[i]; plik_zapis << linia << ",";}
plik_zapis << " Kopcowanie " << "," << "Gauss" << "," << "100000" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  kopcowanie_wynik_35[i]; plik_zapis << linia << ",";}
plik_zapis << " Kopcowanie " << "," << "Gauss" << "," << "100000" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  kopcowanie_wynik_36[i]; plik_zapis << linia << ",";}
plik_zapis << " Kopcowanie " << "," << "Gauss" << "," << "100000" << "," << "99%" << endl;
#endif
#if defined (MILION) && defined (KOPCOWANIE) && defined (GAUSS)
for(int i=0;i<ilosc_iteracji;i++) {linia =  kopcowanie_wynik_37[i]; plik_zapis << linia << ",";}
plik_zapis << " Kopcowanie " << "," << "Gauss" << "," << "1000000" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  kopcowanie_wynik_38[i]; plik_zapis << linia << ",";}
plik_zapis << " Kopcowanie " << "," << "Gauss" << "," << "1000000" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  kopcowanie_wynik_39[i]; plik_zapis << linia << ",";}
plik_zapis << " Kopcowanie " << "," << "Gauss" << "," << "1000000" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  kopcowanie_wynik_40[i]; plik_zapis << linia << ",";}
plik_zapis << " Kopcowanie " << "," << "Gauss" << "," << "1000000" << "," << "99%" << endl;
#endif
#if defined (STO) && defined (KOPCOWANIE) && defined (JEDNOSTAJNY)
for(int i=0;i<ilosc_iteracji;i++) {linia =  kopcowanie_wynik_41[i]; plik_zapis << linia << ",";}
plik_zapis << " Kopcowanie " << "," << "Jednostajny" << "," << "100" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  kopcowanie_wynik_42[i]; plik_zapis << linia << ",";}
plik_zapis << " Kopcowanie " << "," << "Jednostajny" << "," << "100" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  kopcowanie_wynik_43[i]; plik_zapis << linia << ",";}
plik_zapis << " Kopcowanie " << "," << "Jednostajny" << "," << "100" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  kopcowanie_wynik_44[i]; plik_zapis << linia << ",";}
plik_zapis << " Kopcowanie " << "," << "Jednostajny" << "," << "100" << "," << "99%" << endl;
#endif
#if defined (TYSIAC) && defined (KOPCOWANIE) && defined (JEDNOSTAJNY)
for(int i=0;i<ilosc_iteracji;i++) {linia =  kopcowanie_wynik_45[i]; plik_zapis << linia << ",";}
plik_zapis << " Kopcowanie " << "," << "Jednostajny" << "," << "1000" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  kopcowanie_wynik_46[i]; plik_zapis << linia << ",";}
plik_zapis << " Kopcowanie " << "," << "Jednostajny" << "," << "1000" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  kopcowanie_wynik_47[i]; plik_zapis << linia << ",";}
plik_zapis << " Kopcowanie " << "," << "Jednostajny" << "," << "1000" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  kopcowanie_wynik_48[i]; plik_zapis << linia << ",";}
plik_zapis << " Kopcowanie " << "," << "Jednostajny" << "," << "1000" << "," << "99%" << endl;
#endif
#if defined (DZIESIEC_TYSIECY) && defined (KOPCOWANIE) && defined (JEDNOSTAJNY)
for(int i=0;i<ilosc_iteracji;i++) {linia =  kopcowanie_wynik_49[i]; plik_zapis << linia << ",";}
plik_zapis << " Kopcowanie " << "," << "Jednostajny" << "," << "10000" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  kopcowanie_wynik_50[i]; plik_zapis << linia << ",";}
plik_zapis << " Kopcowanie " << "," << "Jednostajny" << "," << "10000" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  kopcowanie_wynik_51[i]; plik_zapis << linia << ",";}
plik_zapis << " Kopcowanie " << "," << "Jednostajny" << "," << "10000" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  kopcowanie_wynik_52[i]; plik_zapis << linia << ",";}
plik_zapis << " Kopcowanie " << "," << "Jednostajny" << "," << "10000" << "," << "99%" << endl;
#endif
#if defined (STO_TYSIECY) && defined (KOPCOWANIE) && defined (JEDNOSTAJNY)
for(int i=0;i<ilosc_iteracji;i++) {linia =  kopcowanie_wynik_53[i]; plik_zapis << linia << ",";}
plik_zapis << " Kopcowanie " << "," << "Jednostajny" << "," << "100000" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  kopcowanie_wynik_54[i]; plik_zapis << linia << ",";}
plik_zapis << " Kopcowanie " << "," << "Jednostajny" << "," << "100000" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  kopcowanie_wynik_55[i]; plik_zapis << linia << ",";}
plik_zapis << " Kopcowanie " << "," << "Jednostajny" << "," << "100000" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  kopcowanie_wynik_56[i]; plik_zapis << linia << ",";}
plik_zapis << " Kopcowanie " << "," << "Jednostajny" << "," << "100000" << "," << "99%" << endl;
#endif
#if defined (MILION) && defined (KOPCOWANIE) && defined (JEDNOSTAJNY)
for(int i=0;i<ilosc_iteracji;i++) {linia =  kopcowanie_wynik_57[i]; plik_zapis << linia << ",";}
plik_zapis << " Kopcowanie " << "," << "Jednostajny" << "," << "1000000" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  kopcowanie_wynik_58[i]; plik_zapis << linia << ",";}
plik_zapis << " Kopcowanie " << "," << "Jednostajny" << "," << "1000000" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  kopcowanie_wynik_59[i]; plik_zapis << linia << ",";}
plik_zapis << " Kopcowanie " << "," << "Jednostajny" << "," << "1000000" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  kopcowanie_wynik_60[i]; plik_zapis << linia << ",";}
plik_zapis << " Kopcowanie " << "," << "Jednostajny" << "," << "1000000" << "," << "99%" << endl;
#endif
// SHELL
#if defined (STO) && defined (SHELL) && defined (POISSON)
for(int i=0;i<ilosc_iteracji;i++) {linia =  shell_wynik_1[i]; plik_zapis << linia << ",";}
plik_zapis << " Shell " << "," << "Poisson" << "," << "100" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  shell_wynik_2[i]; plik_zapis << linia << ",";}
plik_zapis << " Shell " << "," << "Poisson" << "," << "100" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  shell_wynik_3[i]; plik_zapis << linia << ",";}
plik_zapis << " Shell " << "," << "Poisson" << "," << "100" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  shell_wynik_4[i]; plik_zapis << linia << ",";}
plik_zapis << " Shell " << "," << "Poisson" << "," << "100" << "," << "99%" << endl;
#endif
#if defined (TYSIAC) && defined (SHELL) && defined (POISSON)
for(int i=0;i<ilosc_iteracji;i++) {linia =  shell_wynik_5[i]; plik_zapis << linia << ",";}
plik_zapis << " Shell " << "," << "Poisson" << "," << "1000" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  shell_wynik_6[i]; plik_zapis << linia << ",";}
plik_zapis << " Shell " << "," << "Poisson" << "," << "1000" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  shell_wynik_7[i]; plik_zapis << linia << ",";}
plik_zapis << " Shell " << "," << "Poisson" << "," << "1000" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  shell_wynik_8[i]; plik_zapis << linia << ",";}
plik_zapis << " Shell " << "," << "Poisson" << "," << "1000" << "," << "99%" << endl;
#endif
#if defined (DZIESIEC_TYSIECY) && defined (SHELL) && defined (POISSON)
for(int i=0;i<ilosc_iteracji;i++) {linia =  shell_wynik_9[i]; plik_zapis << linia << ",";}
plik_zapis << " Shell " << "," << "Poisson" << "," << "10000" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  shell_wynik_10[i]; plik_zapis << linia << ",";}
plik_zapis << " Shell " << "," << "Poisson" << "," << "10000" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  shell_wynik_11[i]; plik_zapis << linia << ",";}
plik_zapis << " Shell " << "," << "Poisson" << "," << "10000" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  shell_wynik_12[i]; plik_zapis << linia << ",";}
plik_zapis << " Shell " << "," << "Poisson" << "," << "10000" << "," << "99%" << endl;
#endif
#if defined (STO_TYSIECY) && defined (SHELL) && defined (POISSON)
for(int i=0;i<ilosc_iteracji;i++) {linia =  shell_wynik_13[i]; plik_zapis << linia << ",";}
plik_zapis << " Shell " << "," << "Poisson" << "," << "100000" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  shell_wynik_14[i]; plik_zapis << linia << ",";}
plik_zapis << " Shell " << "," << "Poisson" << "," << "100000" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  shell_wynik_15[i]; plik_zapis << linia << ",";}
plik_zapis << " Shell " << "," << "Poisson" << "," << "100000" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  shell_wynik_16[i]; plik_zapis << linia << ",";}
plik_zapis << " Shell " << "," << "Poisson" << "," << "100000" << "," << "99%" << endl;
#endif
#if defined (MILION) && defined (SHELL) && defined (POISSON)
for(int i=0;i<ilosc_iteracji;i++) {linia =  shell_wynik_17[i]; plik_zapis << linia << ",";}
plik_zapis << " Shell " << "," << "Poisson" << "," << "1000000" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  shell_wynik_18[i]; plik_zapis << linia << ",";}
plik_zapis << " Shell " << "," << "Poisson" << "," << "1000000" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  shell_wynik_19[i]; plik_zapis << linia << ",";}
plik_zapis << " Shell " << "," << "Poisson" << "," << "1000000" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  shell_wynik_20[i]; plik_zapis << linia << ",";}
plik_zapis << " Shell " << "," << "Poisson" << "," << "1000000" << "," << "99%" << endl;
#endif
#if defined (STO) && defined (SHELL) && defined (GAUSS)
for(int i=0;i<ilosc_iteracji;i++) {linia =  shell_wynik_21[i]; plik_zapis << linia << ",";}
plik_zapis << " Shell " << "," << "Gauss" << "," << "100" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  shell_wynik_22[i]; plik_zapis << linia << ",";}
plik_zapis << " Shell " << "," << "Gauss" << "," << "100" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  shell_wynik_23[i]; plik_zapis << linia << ",";}
plik_zapis << " Shell " << "," << "Gauss" << "," << "100" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  shell_wynik_24[i]; plik_zapis << linia << ",";}
plik_zapis << " Shell " << "," << "Gauss" << "," << "100" << "," << "99%" << endl;
#endif
#if defined (TYSIAC) && defined (SHELL) && defined (GAUSS)
for(int i=0;i<ilosc_iteracji;i++) {linia =  shell_wynik_25[i]; plik_zapis << linia << ",";}
plik_zapis << " Shell " << "," << "Gauss" << "," << "1000" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  shell_wynik_26[i]; plik_zapis << linia << ",";}
plik_zapis << " Shell " << "," << "Gauss" << "," << "1000" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  shell_wynik_27[i]; plik_zapis << linia << ",";}
plik_zapis << " Shell " << "," << "Gauss" << "," << "1000" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  shell_wynik_28[i]; plik_zapis << linia << ",";}
plik_zapis << " Shell " << "," << "Gauss" << "," << "1000" << "," << "99%" << endl;
#endif
#if defined (DZIESIEC_TYSIECY) && defined (SHELL) && defined (GAUSS)
for(int i=0;i<ilosc_iteracji;i++) {linia =  shell_wynik_29[i]; plik_zapis << linia << ",";}
plik_zapis << " Shell " << "," << "Gauss" << "," << "10000" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  shell_wynik_30[i]; plik_zapis << linia << ",";}
plik_zapis << " Shell " << "," << "Gauss" << "," << "10000" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  shell_wynik_31[i]; plik_zapis << linia << ",";}
plik_zapis << " Shell " << "," << "Gauss" << "," << "10000" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  shell_wynik_32[i]; plik_zapis << linia << ",";}
plik_zapis << " Shell " << "," << "Gauss" << "," << "10000" << "," << "99%" << endl;
#endif
#if defined (STO_TYSIECY) && defined (SHELL) && defined (GAUSS)
for(int i=0;i<ilosc_iteracji;i++) {linia =  shell_wynik_33[i]; plik_zapis << linia << ",";}
plik_zapis << " Shell " << "," << "Gauss" << "," << "100000" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  shell_wynik_34[i]; plik_zapis << linia << ",";}
plik_zapis << " Shell " << "," << "Gauss" << "," << "100000" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  shell_wynik_35[i]; plik_zapis << linia << ",";}
plik_zapis << " Shell " << "," << "Gauss" << "," << "100000" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  shell_wynik_36[i]; plik_zapis << linia << ",";}
plik_zapis << " Shell " << "," << "Gauss" << "," << "100000" << "," << "99%" << endl;
#endif
#if defined (MILION) && defined (SHELL) && defined (GAUSS)
for(int i=0;i<ilosc_iteracji;i++) {linia =  shell_wynik_37[i]; plik_zapis << linia << ",";}
plik_zapis << " Shell " << "," << "Gauss" << "," << "1000000" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  shell_wynik_38[i]; plik_zapis << linia << ",";}
plik_zapis << " Shell " << "," << "Gauss" << "," << "1000000" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  shell_wynik_39[i]; plik_zapis << linia << ",";}
plik_zapis << " Shell " << "," << "Gauss" << "," << "1000000" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  shell_wynik_40[i]; plik_zapis << linia << ",";}
plik_zapis << " Shell " << "," << "Gauss" << "," << "1000000" << "," << "99%" << endl;
#endif
#if defined (STO) && defined (SHELL) && defined (JEDNOSTAJNY)
for(int i=0;i<ilosc_iteracji;i++) {linia =  shell_wynik_41[i]; plik_zapis << linia << ",";}
plik_zapis << " Shell " << "," << "Jednostajny" << "," << "100" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  shell_wynik_42[i]; plik_zapis << linia << ",";}
plik_zapis << " Shell " << "," << "Jednostajny" << "," << "100" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  shell_wynik_43[i]; plik_zapis << linia << ",";}
plik_zapis << " Shell " << "," << "Jednostajny" << "," << "100" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  shell_wynik_44[i]; plik_zapis << linia << ",";}
plik_zapis << " Shell " << "," << "Jednostajny" << "," << "100" << "," << "99%" << endl;
#endif
#if defined (TYSIAC) && defined (SHELL) && defined (JEDNOSTAJNY)
for(int i=0;i<ilosc_iteracji;i++) {linia =  shell_wynik_45[i]; plik_zapis << linia << ",";}
plik_zapis << " Shell " << "," << "Jednostajny" << "," << "1000" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  shell_wynik_46[i]; plik_zapis << linia << ",";}
plik_zapis << " Shell " << "," << "Jednostajny" << "," << "1000" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  shell_wynik_47[i]; plik_zapis << linia << ",";}
plik_zapis << " Shell " << "," << "Jednostajny" << "," << "1000" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  shell_wynik_48[i]; plik_zapis << linia << ",";}
plik_zapis << " Shell " << "," << "Jednostajny" << "," << "1000" << "," << "99%" << endl;
#endif
#if defined (DZIESIEC_TYSIECY) && defined (SHELL) && defined (JEDNOSTAJNY)
for(int i=0;i<ilosc_iteracji;i++) {linia =  shell_wynik_49[i]; plik_zapis << linia << ",";}
plik_zapis << " Shell " << "," << "Jednostajny" << "," << "10000" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  shell_wynik_50[i]; plik_zapis << linia << ",";}
plik_zapis << " Shell " << "," << "Jednostajny" << "," << "10000" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  shell_wynik_51[i]; plik_zapis << linia << ",";}
plik_zapis << " Shell " << "," << "Jednostajny" << "," << "10000" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  shell_wynik_52[i]; plik_zapis << linia << ",";}
plik_zapis << " Shell " << "," << "Jednostajny" << "," << "10000" << "," << "99%" << endl;
#endif
#if defined (STO_TYSIECY) && defined (SHELL) && defined (JEDNOSTAJNY)
for(int i=0;i<ilosc_iteracji;i++) {linia =  shell_wynik_53[i]; plik_zapis << linia << ",";}
plik_zapis << " Shell " << "," << "Jednostajny" << "," << "100000" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  shell_wynik_54[i]; plik_zapis << linia << ",";}
plik_zapis << " Shell " << "," << "Jednostajny" << "," << "100000" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  shell_wynik_55[i]; plik_zapis << linia << ",";}
plik_zapis << " Shell " << "," << "Jednostajny" << "," << "100000" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  shell_wynik_56[i]; plik_zapis << linia << ",";}
plik_zapis << " Shell " << "," << "Jednostajny" << "," << "100000" << "," << "99%" << endl;
#endif
#if defined (MILION) && defined (SHELL) && defined (JEDNOSTAJNY)
for(int i=0;i<ilosc_iteracji;i++) {linia =  shell_wynik_57[i]; plik_zapis << linia << ",";}
plik_zapis << " Shell " << "," << "Jednostajny" << "," << "1000000" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  shell_wynik_58[i]; plik_zapis << linia << ",";}
plik_zapis << " Shell " << "," << "Jednostajny" << "," << "1000000" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  shell_wynik_59[i]; plik_zapis << linia << ",";}
plik_zapis << " Shell " << "," << "Jednostajny" << "," << "1000000" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  shell_wynik_60[i]; plik_zapis << linia << ",";}
plik_zapis << " Shell " << "," << "Jednostajny" << "," << "1000000" << "," << "99%" << endl;
#endif
// QUICKSORT
#if defined (STO) && defined (QUICKSORT) && defined (POISSON)
for(int i=0;i<ilosc_iteracji;i++) {linia =  quick_wynik_1[i]; plik_zapis << linia << ",";}
plik_zapis << " Quicksort " << "," << "Poisson" << "," << "100" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  quick_wynik_2[i]; plik_zapis << linia << ",";}
plik_zapis << " Quicksort " << "," << "Poisson" << "," << "100" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  quick_wynik_3[i]; plik_zapis << linia << ",";}
plik_zapis << " Quicksort " << "," << "Poisson" << "," << "100" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  quick_wynik_4[i]; plik_zapis << linia << ",";}
plik_zapis << " Quicksort " << "," << "Poisson" << "," << "100" << "," << "99%" << endl;
#endif
#if defined (TYSIAC) && defined (QUICKSORT) && defined (POISSON)
for(int i=0;i<ilosc_iteracji;i++) {linia =  quick_wynik_5[i]; plik_zapis << linia << ",";}
plik_zapis << " Quicksort " << "," << "Poisson" << "," << "1000" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  quick_wynik_6[i]; plik_zapis << linia << ",";}
plik_zapis << " Quicksort " << "," << "Poisson" << "," << "1000" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  quick_wynik_7[i]; plik_zapis << linia << ",";}
plik_zapis << " Quicksort " << "," << "Poisson" << "," << "1000" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  quick_wynik_8[i]; plik_zapis << linia << ",";}
plik_zapis << " Quicksort " << "," << "Poisson" << "," << "1000" << "," << "99%" << endl;
#endif
#if defined (DZIESIEC_TYSIECY) && defined (QUICKSORT) && defined (POISSON)
for(int i=0;i<ilosc_iteracji;i++) {linia =  quick_wynik_9[i]; plik_zapis << linia << ",";}
plik_zapis << " Quicksort " << "," << "Poisson" << "," << "10000" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  quick_wynik_10[i]; plik_zapis << linia << ",";}
plik_zapis << " Quicksort " << "," << "Poisson" << "," << "10000" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  quick_wynik_11[i]; plik_zapis << linia << ",";}
plik_zapis << " Quicksort " << "," << "Poisson" << "," << "10000" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  quick_wynik_12[i]; plik_zapis << linia << ",";}
plik_zapis << " Quicksort " << "," << "Poisson" << "," << "10000" << "," << "99%" << endl;
#endif
#if defined (STO_TYSIECY) && defined (QUICKSORT) && defined (POISSON)
for(int i=0;i<ilosc_iteracji;i++) {linia =  quick_wynik_13[i]; plik_zapis << linia << ",";}
plik_zapis << " Quicksort " << "," << "Poisson" << "," << "100000" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  quick_wynik_14[i]; plik_zapis << linia << ",";}
plik_zapis << " Quicksort " << "," << "Poisson" << "," << "100000" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  quick_wynik_15[i]; plik_zapis << linia << ",";}
plik_zapis << " Quicksort " << "," << "Poisson" << "," << "100000" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  quick_wynik_16[i]; plik_zapis << linia << ",";}
plik_zapis << " Quicksort " << "," << "Poisson" << "," << "100000" << "," << "99%" << endl;
#endif
#if defined (MILION) && defined (QUICKSORT) && defined (POISSON)
for(int i=0;i<ilosc_iteracji;i++) {linia =  quick_wynik_17[i]; plik_zapis << linia << ",";}
plik_zapis << " Quicksort " << "," << "Poisson" << "," << "1000000" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  quick_wynik_18[i]; plik_zapis << linia << ",";}
plik_zapis << " Quicksort " << "," << "Poisson" << "," << "1000000" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  quick_wynik_19[i]; plik_zapis << linia << ",";}
plik_zapis << " Quicksort " << "," << "Poisson" << "," << "1000000" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  quick_wynik_20[i]; plik_zapis << linia << ",";}
plik_zapis << " Quicksort " << "," << "Poisson" << "," << "1000000" << "," << "99%" << endl;
#endif
#if defined (STO) && defined (QUICKSORT) && defined (GAUSS)
for(int i=0;i<ilosc_iteracji;i++) {linia =  quick_wynik_21[i]; plik_zapis << linia << ",";}
plik_zapis << " Quicksort " << "," << "Gauss" << "," << "100" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  quick_wynik_22[i]; plik_zapis << linia << ",";}
plik_zapis << " Quicksort " << "," << "Gauss" << "," << "100" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  quick_wynik_23[i]; plik_zapis << linia << ",";}
plik_zapis << " Quicksort " << "," << "Gauss" << "," << "100" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  quick_wynik_24[i]; plik_zapis << linia << ",";}
plik_zapis << " Quicksort " << "," << "Gauss" << "," << "100" << "," << "99%" << endl;
#endif
#if defined (TYSIAC) && defined (QUICKSORT) && defined (GAUSS)
for(int i=0;i<ilosc_iteracji;i++) {linia =  quick_wynik_25[i]; plik_zapis << linia << ",";}
plik_zapis << " Quicksort " << "," << "Gauss" << "," << "1000" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  quick_wynik_26[i]; plik_zapis << linia << ",";}
plik_zapis << " Quicksort " << "," << "Gauss" << "," << "1000" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  quick_wynik_27[i]; plik_zapis << linia << ",";}
plik_zapis << " Quicksort " << "," << "Gauss" << "," << "1000" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  quick_wynik_28[i]; plik_zapis << linia << ",";}
plik_zapis << " Quicksort " << "," << "Gauss" << "," << "1000" << "," << "99%" << endl;
#endif
#if defined (DZIESIEC_TYSIECY) && defined (QUICKSORT) && defined (GAUSS)
for(int i=0;i<ilosc_iteracji;i++) {linia =  quick_wynik_29[i]; plik_zapis << linia << ",";}
plik_zapis << " Quicksort " << "," << "Gauss" << "," << "10000" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  quick_wynik_30[i]; plik_zapis << linia << ",";}
plik_zapis << " Quicksort " << "," << "Gauss" << "," << "10000" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  quick_wynik_31[i]; plik_zapis << linia << ",";}
plik_zapis << " Quicksort " << "," << "Gauss" << "," << "10000" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  quick_wynik_32[i]; plik_zapis << linia << ",";}
plik_zapis << " Quicksort " << "," << "Gauss" << "," << "10000" << "," << "99%" << endl;
#endif
#if defined (STO_TYSIECY) && defined (QUICKSORT) && defined (GAUSS)
for(int i=0;i<ilosc_iteracji;i++) {linia =  quick_wynik_33[i]; plik_zapis << linia << ",";}
plik_zapis << " Quicksort " << "," << "Gauss" << "," << "100000" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  quick_wynik_34[i]; plik_zapis << linia << ",";}
plik_zapis << " Quicksort " << "," << "Gauss" << "," << "100000" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  quick_wynik_35[i]; plik_zapis << linia << ",";}
plik_zapis << " Quicksort " << "," << "Gauss" << "," << "100000" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  quick_wynik_36[i]; plik_zapis << linia << ",";}
plik_zapis << " Quicksort " << "," << "Gauss" << "," << "100000" << "," << "99%" << endl;
#endif
#if defined (MILION) && defined (QUICKSORT) && defined (GAUSS)
for(int i=0;i<ilosc_iteracji;i++) {linia =  quick_wynik_37[i]; plik_zapis << linia << ",";}
plik_zapis << " Quicksort " << "," << "Gauss" << "," << "1000000" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  quick_wynik_38[i]; plik_zapis << linia << ",";}
plik_zapis << " Quicksort " << "," << "Gauss" << "," << "1000000" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  quick_wynik_39[i]; plik_zapis << linia << ",";}
plik_zapis << " Quicksort " << "," << "Gauss" << "," << "1000000" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  quick_wynik_40[i]; plik_zapis << linia << ",";}
plik_zapis << " Quicksort " << "," << "Gauss" << "," << "1000000" << "," << "99%" << endl;
#endif
#if defined (STO) && defined (QUICKSORT) && defined (JEDNOSTAJNY)
for(int i=0;i<ilosc_iteracji;i++) {linia =  quick_wynik_41[i]; plik_zapis << linia << ",";}
plik_zapis << " Quicksort " << "," << "Jednostajny" << "," << "100" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  quick_wynik_42[i]; plik_zapis << linia << ",";}
plik_zapis << " Quicksort " << "," << "Jednostajny" << "," << "100" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  quick_wynik_43[i]; plik_zapis << linia << ",";}
plik_zapis << " Quicksort " << "," << "Jednostajny" << "," << "100" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  quick_wynik_44[i]; plik_zapis << linia << ",";}
plik_zapis << " Quicksort " << "," << "Jednostajny" << "," << "100" << "," << "99%" << endl;
#endif
#if defined (TYSIAC) && defined (QUICKSORT) && defined (JEDNOSTAJNY)
for(int i=0;i<ilosc_iteracji;i++) {linia =  quick_wynik_45[i]; plik_zapis << linia << ",";}
plik_zapis << " Quicksort " << "," << "Jednostajny" << "," << "1000" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  quick_wynik_46[i]; plik_zapis << linia << ",";}
plik_zapis << " Quicksort " << "," << "Jednostajny" << "," << "1000" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  quick_wynik_47[i]; plik_zapis << linia << ",";}
plik_zapis << " Quicksort " << "," << "Jednostajny" << "," << "1000" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  quick_wynik_48[i]; plik_zapis << linia << ",";}
plik_zapis << " Quicksort " << "," << "Jednostajny" << "," << "1000" << "," << "99%" << endl;
#endif
#if defined (DZIESIEC_TYSIECY) && defined (QUICKSORT) && defined (JEDNOSTAJNY)
for(int i=0;i<ilosc_iteracji;i++) {linia =  quick_wynik_49[i]; plik_zapis << linia << ",";}
plik_zapis << " Quicksort " << "," << "Jednostajny" << "," << "10000" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  quick_wynik_50[i]; plik_zapis << linia << ",";}
plik_zapis << " Quicksort " << "," << "Jednostajny" << "," << "10000" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  quick_wynik_51[i]; plik_zapis << linia << ",";}
plik_zapis << " Quicksort " << "," << "Jednostajny" << "," << "10000" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  quick_wynik_52[i]; plik_zapis << linia << ",";}
plik_zapis << " Quicksort " << "," << "Jednostajny" << "," << "10000" << "," << "99%" << endl;
#endif
#if defined (STO_TYSIECY) && defined (QUICKSORT) && defined (JEDNOSTAJNY)
for(int i=0;i<ilosc_iteracji;i++) {linia =  quick_wynik_53[i]; plik_zapis << linia << ",";}
plik_zapis << " Quicksort " << "," << "Jednostajny" << "," << "100000" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  quick_wynik_54[i]; plik_zapis << linia << ",";}
plik_zapis << " Quicksort " << "," << "Jednostajny" << "," << "100000" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  quick_wynik_55[i]; plik_zapis << linia << ",";}
plik_zapis << " Quicksort " << "," << "Jednostajny" << "," << "100000" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  quick_wynik_56[i]; plik_zapis << linia << ",";}
plik_zapis << " Quicksort " << "," << "Jednostajny" << "," << "100000" << "," << "99%" << endl;
#endif
#if defined (MILION) && defined (QUICKSORT) && defined (JEDNOSTAJNY)
for(int i=0;i<ilosc_iteracji;i++) {linia =  quick_wynik_57[i]; plik_zapis << linia << ",";}
plik_zapis << " Quicksort " << "," << "Jednostajny" << "," << "1000000" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  quick_wynik_58[i]; plik_zapis << linia << ",";}
plik_zapis << " Quicksort " << "," << "Jednostajny" << "," << "1000000" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  quick_wynik_59[i]; plik_zapis << linia << ",";}
plik_zapis << " Quicksort " << "," << "Jednostajny" << "," << "1000000" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  quick_wynik_60[i]; plik_zapis << linia << ",";}
plik_zapis << " Quicksort " << "," << "Jednostajny" << "," << "1000000" << "," << "99%" << endl;
#endif
// INTROSORT
#if defined (STO) && defined (INTROSORT) && defined (POISSON)
for(int i=0;i<ilosc_iteracji;i++) {linia =  introsort_wynik_1[i]; plik_zapis << linia << ",";}
plik_zapis << " Introsort " << "," << "Poisson" << "," << "100" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  introsort_wynik_2[i]; plik_zapis << linia << ",";}
plik_zapis << " Introsort " << "," << "Poisson" << "," << "100" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  introsort_wynik_3[i]; plik_zapis << linia << ",";}
plik_zapis << " Introsort " << "," << "Poisson" << "," << "100" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  introsort_wynik_4[i]; plik_zapis << linia << ",";}
plik_zapis << " Introsort " << "," << "Poisson" << "," << "100" << "," << "99%" << endl;
#endif
#if defined (TYSIAC) && defined (INTROSORT) && defined (POISSON)
for(int i=0;i<ilosc_iteracji;i++) {linia =  introsort_wynik_5[i]; plik_zapis << linia << ",";}
plik_zapis << " Introsort " << "," << "Poisson" << "," << "1000" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  introsort_wynik_6[i]; plik_zapis << linia << ",";}
plik_zapis << " Introsort " << "," << "Poisson" << "," << "1000" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  introsort_wynik_7[i]; plik_zapis << linia << ",";}
plik_zapis << " Introsort " << "," << "Poisson" << "," << "1000" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  introsort_wynik_8[i]; plik_zapis << linia << ",";}
plik_zapis << " Introsort " << "," << "Poisson" << "," << "1000" << "," << "99%" << endl;
#endif
#if defined (DZIESIEC_TYSIECY) && defined (INTROSORT) && defined (POISSON)
for(int i=0;i<ilosc_iteracji;i++) {linia =  introsort_wynik_9[i]; plik_zapis << linia << ",";}
plik_zapis << " Introsort " << "," << "Poisson" << "," << "10000" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  introsort_wynik_10[i]; plik_zapis << linia << ",";}
plik_zapis << " Introsort " << "," << "Poisson" << "," << "10000" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  introsort_wynik_11[i]; plik_zapis << linia << ",";}
plik_zapis << " Introsort " << "," << "Poisson" << "," << "10000" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  introsort_wynik_12[i]; plik_zapis << linia << ",";}
plik_zapis << " Introsort " << "," << "Poisson" << "," << "10000" << "," << "99%" << endl;
#endif
#if defined (STO_TYSIECY) && defined (INTROSORT) && defined (POISSON)
for(int i=0;i<ilosc_iteracji;i++) {linia =  introsort_wynik_13[i]; plik_zapis << linia << ",";}
plik_zapis << " Introsort " << "," << "Poisson" << "," << "100000" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  introsort_wynik_14[i]; plik_zapis << linia << ",";}
plik_zapis << " Introsort " << "," << "Poisson" << "," << "100000" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  introsort_wynik_15[i]; plik_zapis << linia << ",";}
plik_zapis << " Introsort " << "," << "Poisson" << "," << "100000" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  introsort_wynik_16[i]; plik_zapis << linia << ",";}
plik_zapis << " Introsort " << "," << "Poisson" << "," << "100000" << "," << "99%" << endl;
#endif
#if defined (MILION) && defined (INTROSORT) && defined (POISSON)
for(int i=0;i<ilosc_iteracji;i++) {linia =  introsort_wynik_17[i]; plik_zapis << linia << ",";}
plik_zapis << " Introsort " << "," << "Poisson" << "," << "1000000" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  introsort_wynik_18[i]; plik_zapis << linia << ",";}
plik_zapis << " Introsort " << "," << "Poisson" << "," << "1000000" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  introsort_wynik_19[i]; plik_zapis << linia << ",";}
plik_zapis << " Introsort " << "," << "Poisson" << "," << "1000000" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  introsort_wynik_20[i]; plik_zapis << linia << ",";}
plik_zapis << " Introsort " << "," << "Poisson" << "," << "1000000" << "," << "99%" << endl;
#endif
#if defined (STO) && defined (INTROSORT) && defined (GAUSS)
for(int i=0;i<ilosc_iteracji;i++) {linia =  introsort_wynik_21[i]; plik_zapis << linia << ",";}
plik_zapis << " Introsort " << "," << "Gauss" << "," << "100" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  introsort_wynik_22[i]; plik_zapis << linia << ",";}
plik_zapis << " Introsort " << "," << "Gauss" << "," << "100" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  introsort_wynik_23[i]; plik_zapis << linia << ",";}
plik_zapis << " Introsort " << "," << "Gauss" << "," << "100" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  introsort_wynik_24[i]; plik_zapis << linia << ",";}
plik_zapis << " Introsort " << "," << "Gauss" << "," << "100" << "," << "99%" << endl;
#endif
#if defined (TYSIAC) && defined (INTROSORT) && defined (GAUSS)
for(int i=0;i<ilosc_iteracji;i++) {linia =  introsort_wynik_25[i]; plik_zapis << linia << ",";}
plik_zapis << " Introsort " << "," << "Gauss" << "," << "1000" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  introsort_wynik_26[i]; plik_zapis << linia << ",";}
plik_zapis << " Introsort " << "," << "Gauss" << "," << "1000" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  introsort_wynik_27[i]; plik_zapis << linia << ",";}
plik_zapis << " Introsort " << "," << "Gauss" << "," << "1000" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  introsort_wynik_28[i]; plik_zapis << linia << ",";}
plik_zapis << " Introsort " << "," << "Gauss" << "," << "1000" << "," << "99%" << endl;
#endif
#if defined (DZIESIEC_TYSIECY) && defined (INTROSORT) && defined (GAUSS)
for(int i=0;i<ilosc_iteracji;i++) {linia =  introsort_wynik_29[i]; plik_zapis << linia << ",";}
plik_zapis << " Introsort " << "," << "Gauss" << "," << "10000" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  introsort_wynik_30[i]; plik_zapis << linia << ",";}
plik_zapis << " Introsort " << "," << "Gauss" << "," << "10000" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  introsort_wynik_31[i]; plik_zapis << linia << ",";}
plik_zapis << " Introsort " << "," << "Gauss" << "," << "10000" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  introsort_wynik_32[i]; plik_zapis << linia << ",";}
plik_zapis << " Introsort " << "," << "Gauss" << "," << "10000" << "," << "99%" << endl;
#endif
#if defined (STO_TYSIECY) && defined (INTROSORT) && defined (GAUSS)
for(int i=0;i<ilosc_iteracji;i++) {linia =  introsort_wynik_33[i]; plik_zapis << linia << ",";}
plik_zapis << " Introsort " << "," << "Gauss" << "," << "100000" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  introsort_wynik_34[i]; plik_zapis << linia << ",";}
plik_zapis << " Introsort " << "," << "Gauss" << "," << "100000" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  introsort_wynik_35[i]; plik_zapis << linia << ",";}
plik_zapis << " Introsort " << "," << "Gauss" << "," << "100000" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  introsort_wynik_36[i]; plik_zapis << linia << ",";}
plik_zapis << " Introsort " << "," << "Gauss" << "," << "100000" << "," << "99%" << endl;
#endif
#if defined (MILION) && defined (INTROSORT) && defined (GAUSS)
for(int i=0;i<ilosc_iteracji;i++) {linia =  introsort_wynik_37[i]; plik_zapis << linia << ",";}
plik_zapis << " Introsort " << "," << "Gauss" << "," << "1000000" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  introsort_wynik_38[i]; plik_zapis << linia << ",";}
plik_zapis << " Introsort " << "," << "Gauss" << "," << "1000000" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  introsort_wynik_39[i]; plik_zapis << linia << ",";}
plik_zapis << " Introsort " << "," << "Gauss" << "," << "1000000" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  introsort_wynik_40[i]; plik_zapis << linia << ",";}
plik_zapis << " Introsort " << "," << "Gauss" << "," << "1000000" << "," << "99%" << endl;
#endif
#if defined (STO) && defined (INTROSORT) && defined (JEDNOSTAJNY)
for(int i=0;i<ilosc_iteracji;i++) {linia =  introsort_wynik_41[i]; plik_zapis << linia << ",";}
plik_zapis << " Introsort " << "," << "Jednostajny" << "," << "100" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  introsort_wynik_42[i]; plik_zapis << linia << ",";}
plik_zapis << " Introsort " << "," << "Jednostajny" << "," << "100" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  introsort_wynik_43[i]; plik_zapis << linia << ",";}
plik_zapis << " Introsort " << "," << "Jednostajny" << "," << "100" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  introsort_wynik_44[i]; plik_zapis << linia << ",";}
plik_zapis << " Introsort " << "," << "Jednostajny" << "," << "100" << "," << "99%" << endl;
#endif
#if defined (TYSIAC) && defined (INTROSORT) && defined (JEDNOSTAJNY)
for(int i=0;i<ilosc_iteracji;i++) {linia =  introsort_wynik_45[i]; plik_zapis << linia << ",";}
plik_zapis << " Introsort " << "," << "Jednostajny" << "," << "1000" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  introsort_wynik_46[i]; plik_zapis << linia << ",";}
plik_zapis << " Introsort " << "," << "Jednostajny" << "," << "1000" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  introsort_wynik_47[i]; plik_zapis << linia << ",";}
plik_zapis << " Introsort " << "," << "Jednostajny" << "," << "1000" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  introsort_wynik_48[i]; plik_zapis << linia << ",";}
plik_zapis << " Introsort " << "," << "Jednostajny" << "," << "1000" << "," << "99%" << endl;
#endif
#if defined (DZIESIEC_TYSIECY) && defined (INTROSORT) && defined (JEDNOSTAJNY)
for(int i=0;i<ilosc_iteracji;i++) {linia =  introsort_wynik_49[i]; plik_zapis << linia << ",";}
plik_zapis << " Introsort " << "," << "Jednostajny" << "," << "10000" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  introsort_wynik_50[i]; plik_zapis << linia << ",";}
plik_zapis << " Introsort " << "," << "Jednostajny" << "," << "10000" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  introsort_wynik_51[i]; plik_zapis << linia << ",";}
plik_zapis << " Introsort " << "," << "Jednostajny" << "," << "10000" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  introsort_wynik_52[i]; plik_zapis << linia << ",";}
plik_zapis << " Introsort " << "," << "Jednostajny" << "," << "10000" << "," << "99%" << endl;
#endif
#if defined (STO_TYSIECY) && defined (INTROSORT) && defined (JEDNOSTAJNY)
for(int i=0;i<ilosc_iteracji;i++) {linia =  introsort_wynik_53[i]; plik_zapis << linia << ",";}
plik_zapis << " Introsort " << "," << "Jednostajny" << "," << "100000" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  introsort_wynik_54[i]; plik_zapis << linia << ",";}
plik_zapis << " Introsort " << "," << "Jednostajny" << "," << "100000" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  introsort_wynik_55[i]; plik_zapis << linia << ",";}
plik_zapis << " Introsort " << "," << "Jednostajny" << "," << "100000" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  introsort_wynik_56[i]; plik_zapis << linia << ",";}
plik_zapis << " Introsort " << "," << "Jednostajny" << "," << "100000" << "," << "99%" << endl;
#endif
#if defined (MILION) && defined (INTROSORT) && defined (JEDNOSTAJNY)
for(int i=0;i<ilosc_iteracji;i++) {linia =  introsort_wynik_57[i]; plik_zapis << linia << ",";}
plik_zapis << " Introsort " << "," << "Jednostajny" << "," << "1000000" << "," << "0%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  introsort_wynik_58[i]; plik_zapis << linia << ",";}
plik_zapis << " Introsort " << "," << "Jednostajny" << "," << "1000000" << "," << "50%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  introsort_wynik_59[i]; plik_zapis << linia << ",";}
plik_zapis << " Introsort " << "," << "Jednostajny" << "," << "1000000" << "," << "90%" << endl;
for(int i=0;i<ilosc_iteracji;i++) {linia =  introsort_wynik_60[i]; plik_zapis << linia << ",";}
plik_zapis << " Introsort " << "," << "Jednostajny" << "," << "1000000" << "," << "99%" << endl;
#endif


plik_zapis.flush();
plik_zapis.close();
}



    return 0;
}
