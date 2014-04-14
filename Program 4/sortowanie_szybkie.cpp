#include <iostream>
#include <random>
#include <time.h>
using namespace std;
const int rozmiar=100;

void sortowanie_szybkie(int* tab, int l, int p)
{
	int i, j, rozdzielajacy;
	rozdzielajacy=tab[(l+p)>>1];
	i=l;
	j=p;
	do
	{
		while(tab[i]<rozdzielajacy)
		i++;
		while(tab[j]>rozdzielajacy)
		j--;
		if(i<=j)
		{
			int tmp=tab[i];
			tab[i]=tab[j];
			tab[j]=tmp;
			i++;
			j--;
		}
	}
	while(i<j);
	if(l<j)
	sortowanie_szybkie(tab, l, j);
	if(p>i)
	sortowanie_szybkie(tab, i, p);
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
	sortowanie_szybkie(tab, 0, 99);
	cout<<"\nTablica posortowana:\n";
	for(int i=0; i<rozmiar; i++)
	cout<<tab[i]<<" ";
}
