#include <iostream>
#include <random>
#include <time.h>
using namespace std;
const int rozmiar=100;

void sortowanie_przez_wstawianie(int* tab, int rozmiar)
{
	int tmp,i,j;
	for(i=1; i<rozmiar; i++)
	{
		tmp=tab[i];
		for(j=i-1;j>=0&&tab[j]>tmp; j--)
		{
			tab[j+1]=tab[j];
		}
		tab[j+1]=tmp;
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
	sortowanie_przez_wstawianie(tab, rozmiar);
	cout<<"\nTablica posortowana:\n";
	for(int i=0; i<rozmiar; i++)
	cout<<tab[i]<<" ";
}
