#include <iostream>
#include <random>
#include <time.h>
using namespace std;
const int rozmiar=100;

void sortowanie_babelkowe(int* tab, int rozmiar)
{
	int tmp;
	int n=rozmiar;
    do
    {
         for(int i=0; i<n; i++)
         {
                 if(tab[i]>tab[i+1])
                 {
                    tmp=tab[i];
                    tab[i]=tab[i+1];
                    tab[i+1]=tmp;              
                 }
         }
         n=n-1;
    }
         while(n>1);
}


int main()
{
	int tab[rozmiar];
	srand(time(NULL));
	for(int i=0; i<rozmiar; i++)
	tab[i]=rand()%100;
	cout<<"Nieposortowana tablica:\n";
	for(int i=0; i<rozmiar; i++)
	cout<<tab[i]<<" ";
	sortowanie_babelkowe(tab, rozmiar);
	cout<<"\nTablica posortowana:\n";
	for(int i=0; i<rozmiar; i++)
	cout<<tab[i]<<" ";
}
