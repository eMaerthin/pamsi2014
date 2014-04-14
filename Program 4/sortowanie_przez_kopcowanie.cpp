#include <iostream>
#include <random>
#include <time.h>
using namespace std;
const int rozmiar=100;

void sortowanie_przez_kopcowanie(int* tab, int rozmiar)
{
	int i,j,k,m,x,tmp;
	for(int i=0; i<rozmiar; i++)
	{
		j=i; k=j/2;
		x=tab[i];
		while((k>0)&&(tab[k]<x))
		{
			tab[j]=tab[k];
			j=k; k=j/2;
		}
		tab[j]=x;
	}
	for(int i=rozmiar-1; i>0; i--)
	{
		tmp=tab[1];
		tab[1]=tab[i];
		tab[i]=tmp;
		j=1; k=2;
		while(k<i)
		{
			if((k+1<i)&&(tab[k+1]>tab[k]))
			m=k+1;
			else
			m=k;
			if(tab[m]<=tab[j])
			break;
			tmp=tab[j];
			tab[j]=tab[m];
			tab[m]=tmp;
			j=m; k=j+j;
		}
	}
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
	sortowanie_przez_kopcowanie(tab, rozmiar);
	cout<<"\nTablica posortowana:\n";
	for(int i=0; i<rozmiar; i++)
	cout<<tab[i]<<" ";
}
