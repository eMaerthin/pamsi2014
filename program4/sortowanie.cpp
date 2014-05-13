//
//  sortowanie.cpp
//  PAMSI2014_4
//
//  Created by Adrian Bykowski on 25.03.2014.
//  Copyright (c) 2014 Adrian Bykowski. All rights reserved.
//
#include <algorithm>
#include "sortowanie.h"
#include <cmath>
using namespace std;
void swapx( double& a, double& b )
{
    double temp = a;
    a = b;
    b = temp;
}
void bubblesort(double tab[], long roz)
{
    int x = 1;
    while(x)
    {
        x = 0;
        for(long i = 0; i<roz-1;i++)
        {
            if(tab[i]>tab[i+1])
            {
                swapx(tab[i],tab[i+1]);
                x = 1;
            }
        }
    }
}
void wybieraniesort(double tab[], long N)
{
    long x;
    double min;
    for(int i=0; i<N; i++)
    {
        x=i;
        min = tab[i];
        for(int j=i+1;j<N;j++)
        {
           if(tab[j]<min)
           {
               min = tab[j];
               x=j;
           }
        }
        swap(tab[x],tab[i]);
    }
}
void quicksort( double tab[], long lewy, long prawy )
{
    long i = lewy;
    long j = prawy;
    double x = tab[( lewy + prawy ) / 2 ];
    do
    {
        while( tab[ i ] < x )
            i++;
        
        while( tab[ j ] > x )
            j--;
        
        if( i <= j )
        {
            swap( tab[ i ], tab[ j ] );
            
            i++;
            j--;
        }
    } while( i <= j );
    
    if( lewy < j ) quicksort( tab, lewy, j );
    
    if( prawy > i ) quicksort( tab, i, prawy );
    
}

