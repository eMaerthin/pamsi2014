//
//  Intro.cpp
//  PAMSI2014_4
//
//  Created by Adrian Bykowski on 05.05.2014.
//  Copyright (c) 2014 Adrian Bykowski. All rights reserved.
//

#include "Intro.h"
//sortowanie introspektywne


void Heapify(double tab[],long i, long N)
{
    long pocz,kon,largest;
    double tmp;
    pocz = 2*i+1;
    kon = 2*i+2;
    if(pocz<N)
    {
        if( tab[pocz]>tab[i])
            largest=pocz;
        else
            largest=i;
    }
    else
        largest=i;
    if(kon<N)
    {
        if( tab[kon]>tab[largest])
            largest=kon;
    }
    if (largest!=i)
    {
        tmp=tab[i];
        tab[i]=tab[largest];
        tab[largest]=tmp;
        Heapify(tab,largest, N);
    }
    return;
}
void IntroQuick(double tab[],long pocz, long kon, int Rec)
{
    if(Rec<=0)
    {
        for(long i=((kon-pocz+1)/2-1); i>=0 ; i--)
            Heapify(tab,i,(kon-pocz+1));
        double tmp;
        for(long i=(kon-pocz+1); i>0 ; i--)
        {
            Heapify(tab,0, i);
            tmp=tab[0];
            tab[0]=tab[i-1];
            tab[i-1]=tmp;
        }
    }
    else
    {
        if(pocz<kon)
        {
            long m=pocz;
            double tmp;
            for (long i=pocz+1;i<=kon;i++)
            {
                if(tab[i]<tab[pocz])
                {
                    m++;
                    tmp=tab[m];
                    tab[m]=tab[i];
                    tab[i]=tmp;
                }
            }
            tmp=tab[m];
            tab[m]=tab[pocz];
            tab[pocz]=tmp;
            IntroQuick(tab,pocz, m-1,Rec-1);
            IntroQuick(tab,m+1, kon,Rec-1);
        }
    }
    return;
}
void sortIntro(double tab[],long N)
{
    long pocz = 0;
    long kon = N-1;
    if(kon-pocz>0)
        IntroQuick(tab,pocz, kon,(int)floor(2*log(N)/M_LN2));
}