//
//  main.cpp
//  PAMSI2014_4

//  SPRAWOZDANIA - SORTOWANIE TABLIC


//  Created by Adrian Bykowski on 25.03.2014.
//  Copyright (c) 2014 Adrian Bykowski. All rights reserved.
//
#define ROZ 10000
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include "sortowanie.h"
#include "Intro.h"
#include <random>
#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <cmath>
using namespace std;

#define ILE 1.0


double rnorm (double mu, double sigma)
{
    std::random_device rd;
    std::mt19937 e2(rd());
    std::normal_distribution<double> normal(mu,sigma);
    return normal(e2);
}
double rjedn(double x, double y)
{
    std::random_device rd;
    std::mt19937 e2(rd());
    std::uniform_real_distribution<double> uni(x,y);
    return uni(e2);
}
double rpoiss(double mean)
{
    std::random_device rd;
    std::mt19937 e2(rd());
    std::normal_distribution<double> poiss(mean);
    return poiss(e2);
}

int main(int argc, const char * argv[])
{
    double *tab = nullptr;
    long N;
    double wyniki[100];
    clock_t t = 0;
    //cout << " Wpisz liczbe elementow " << endl;
    //cin >> N;
    cout << "Wybierz rozklad \n 1. Rozklad Normalny \n 2. Rozklad jednostajny \n 3. Rozklad Poissona \n" << endl;
    int x;
    cin >> x;
    int y;
    cout << "Wybierz metode sortowania \n 1. BubbleSort \n 2. InsertSort \n 3. QuickSort \n 4. IntroSort" << endl;
    cin >> y;
    for(N=100;N<=1000000;N=N*10){
        
    for(int j(0);j<ILE;j++){
        tab = new double[N];
        switch (x)
        {
            case 1: {
                        for(long i=0;i<N;i++)
                            tab[i] = rnorm(0.0,1.0);
                        break;  }
            case 2: {
                        for(long i=0;i<N;i++)
                            tab[i] = rjedn(0.0,1.0);
                        break; }
            case 3: {
                        for(long i=0;i<N;i++)
                            tab[i] = rpoiss(5.0);
                        break; }
            default: { cout << " Wybierz jeszcze raz \n" << endl; break; }
        }
   // for(long i(0);i<N ;i++)
   //     cout << tab[i] << endl;   // cout !! ! !! !! !
   
        t=clock();
        switch (y)
        {
            case 1: {bubblesort(tab, N); break;}
            case 2: {wybieraniesort(tab, N); break; }
            case 3: {quicksort(tab, 0,(int)N-1); break; }
            case 4: {sortIntro(tab, N); break;}
            default: { cout << " Wybierz jeszcze raz \n" << endl; break; }
        }
        t=clock()-t;
        wyniki[j]=t;
        //cout <<"czas : "<< ((double)t)/CLOCKS_PER_SEC << endl << "clicks : " << t << endl;
        delete [] tab;
    }
    double wynik(0);
    for(int i(0);i<ILE;i++){
        wynik+=wyniki[i]/CLOCKS_PER_SEC;
    }
    wynik=wynik/ILE;
        cout <<"czas usredniony : "<< setprecision(5) << fixed << wynik << "     dla N : "<< N <<endl;
    }
    //cout << "0. : " << tab[0];
    // for(int i=0;i<N ;i++)
    //   cout << i <<". : "<< tab[i] << endl;
    
    getchar();
    return 0;
}

